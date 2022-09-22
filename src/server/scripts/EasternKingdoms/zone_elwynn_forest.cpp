/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "CreatureGroups.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum Northshire
{
    NPC_STORWIND_INFANTRY                   = 49869,
    NPC_BROTHER_PAXTON                      = 951,
    NPC_INJURED_NORTHSHIRE_INFANTRY_DUMMY   = 50378,

    EVENT_ASK_FOR_HELP                      = 1,
    EVENT_SELECT_INFANTRY,
    EVENT_HEAL_INFANTRY,
    EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS,

    SAY_ASK_FOR_HELP                        = 0,
    SAY_HEAL_INFANTRY                       = 0,
    SAY_RIGHT_CLICK                         = 0,

    SPELL_PRAYER_OF_HEALING                 = 93091,
    SPELL_RENEW                             = 93094,
    SPELL_FLASH_HEAL                        = 17843,

    SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION     = 93450,
};

uint32 const FearNoEvilQuests[] =
{
    28806,
    28807,
    28808,
    28809,
    28810,
    28811,
    28812,
    28813,
    29082,
};

struct npc_stormwind_infantry : public ScriptedAI
{
    npc_stormwind_infantry(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_ASK_FOR_HELP, Seconds(urand(1, 10) * 10));
    }

    void UpdateAI(uint32 diff) override
    {
        // No UpdateVictim() here on purpose

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ASK_FOR_HELP:
                    Talk(SAY_ASK_FOR_HELP);
                    _events.ScheduleEvent(EVENT_ASK_FOR_HELP, Seconds(urand(3, 10) * 10));
                    _events.ScheduleEvent(EVENT_HEAL_INFANTRY, 2s);
                    break;
                case EVENT_HEAL_INFANTRY:
                    if (Creature* paxton = me->FindNearestCreature(NPC_BROTHER_PAXTON, 30.0f, true))
                    {
                        if (!paxton->HasUnitState(UNIT_STATE_CASTING))
                        {
                            paxton->AI()->Talk(SAY_HEAL_INFANTRY, me);
                            if (me->GetHealthPct() <= 85)
                            {
                                paxton->StopMoving();
                                switch (urand(0, 2))
                                {
                                    case 0: // Prayer of Healing
                                        paxton->CastSpell(paxton, SPELL_PRAYER_OF_HEALING);
                                        break;
                                    case 1: // Renew
                                        paxton->SetFacingToObject(me);
                                        paxton->CastSpell(me, SPELL_RENEW);
                                        break;
                                    case 2: // Flash Heal
                                        paxton->SetFacingToObject(me);
                                        paxton->CastSpell(me, SPELL_FLASH_HEAL);
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_blackrock_battle_worg : public ScriptedAI
{
    npc_blackrock_battle_worg(Creature* creature) : ScriptedAI(creature), _isAttackingInfantry(false) { }

    void Reset() override
    {
        me->m_Events.AddEventAtOffset([this]
        {
            if (Creature* infantry = me->FindNearestCreature(NPC_STORWIND_INFANTRY, 5.0f, true))
            {
                _isAttackingInfantry = true;
                _infantryGUID = infantry->GetGUID();
                AttackStart(infantry);

                if (infantry->IsAIEnabled())
                    infantry->AI()->AttackStart(me);
            }
        }, 1s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* infantry = ObjectAccessor::GetCreature(*me, _infantryGUID))
            infantry->AI()->EnterEvadeMode();
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/) override
    {
        if (attacker && attacker->GetEntry() != NPC_STORWIND_INFANTRY)
            _isAttackingInfantry = false;
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!_isAttackingInfantry && !UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    ObjectGuid _infantryGUID;
    bool _isAttackingInfantry;
};

struct npc_injured_stormwind_infantry_dummy : public ScriptedAI
{
    npc_injured_stormwind_infantry_dummy(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS, 1ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS:
                {
                    std::vector<Player*> players;
                    Trinity::AnyPlayerInObjectRangeCheck checker(me, 50.0f);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                    Cell::VisitWorldObjects(me, searcher, 50.0f);
                    for (Player* player : players)
                    {
                        for (uint32 questId : FearNoEvilQuests)
                        {
                            if (player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (!player->HasAura(SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION))
                                {
                                    me->CastSpell(player, SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION, true);
                                    Talk(SAY_RIGHT_CLICK, player);
                                }
                            }
                        }
                    }
                    _events.Repeat(10s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum WantedHogger
{
    // Hogger
    SPELL_VICIOUS_SLICE     = 87337,
    SPELL_SUMMON_MINIONS    = 87366,
    SPELL_EATING            = 87351,
    SPELL_UPSET_STOMACH     = 87352,
    SPELL_TELEPORT_VISUAL   = 64446,

    SAY_HELP_HOGGER         = 0,
    SAY_ANNOUNCE_HEAL       = 1,
    SAY_ANNOUNCE_STUN       = 2,
    SAY_SURRENDER           = 3,
    SAY_OUTRO_1             = 4,
    SAY_OUTRO_2             = 5,

    EVENT_VICIOUS_SLICE     = 1,
    EVENT_MOVE_TO_MEAT      = 2,
    EVENT_EAT_MEAT          = 3,
    EVENT_MAKE_AGGRESSIVE   = 4,
    EVENT_SUMMON_GENERAL    = 5,
    EVENT_FACE_TO_GENERAL   = 6,
    EVENT_SAY_OUTRO_2       = 7,
    EVENT_CAST_TELEPORT     = 8,
    EVENT_DESPAWN           = 9,

    POINT_EAT_MEAT          = 1,
    POINT_SURRENDER         = 2,
};

Position const HoggerMeatPos = { -10145.12f, 667.582f, 37.53608f };
Position const HoggerEndPos = { -10136.9f, 670.009f, 36.03682f };

struct npc_hogger : public ScriptedAI
{
    npc_hogger(Creature* creature) : ScriptedAI(creature), _calledForHelp(false), _defeated(false) { }

    void Reset() override
    {
        me->GetMotionMaster()->MoveRandom(7.0f);
        me->SetReactState(REACT_AGGRESSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        _events.Reset();
        _calledForHelp = false;
        _defeated = false;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_VICIOUS_SLICE, 5s);
        me->GetMotionMaster()->Clear(MOTION_SLOT_IDLE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth() && !_defeated)
        {
            _events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->RemoveAllAuras();
            me->KillSelf();
            me->setDeathState(ALIVE);
            me->setRegeneratingHealth(false);
            me->SetHealth(1);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            Talk(SAY_SURRENDER);
            me->GetMotionMaster()->MovePoint(POINT_SURRENDER, HoggerEndPos, true);
            _defeated = true;
        }
        else if (!_calledForHelp && me->HealthBelowPctDamaged(50, damage))
        {
            Talk(SAY_HELP_HOGGER);
            DoCast(SPELL_SUMMON_MINIONS);
            _events.ScheduleEvent(EVENT_MOVE_TO_MEAT, 4s);
            _calledForHelp = true;
        }

        // Hogger may not be killed at all
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_EAT_MEAT:
                _events.ScheduleEvent(EVENT_EAT_MEAT, 1ms);
                break;
            case POINT_SURRENDER:
                _events.ScheduleEvent(EVENT_SUMMON_GENERAL, 1ms);
                break;
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_UPSET_STOMACH)
        {
            _events.CancelEvent(EVENT_MAKE_AGGRESSIVE);
            me->SetReactState(REACT_AGGRESSIVE);
            Talk(SAY_ANNOUNCE_STUN);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_defeated && !UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VICIOUS_SLICE:
                    DoCastVictim(SPELL_VICIOUS_SLICE);
                    _events.Repeat(11s, 12s);
                    break;
                case EVENT_MOVE_TO_MEAT:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_ANNOUNCE_HEAL);
                    me->GetMotionMaster()->MovePoint(POINT_EAT_MEAT, HoggerMeatPos, true);
                    break;
                case EVENT_EAT_MEAT:
                    DoCast(me, SPELL_EATING);
                    _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, 12s);
                    break;
                case EVENT_MAKE_AGGRESSIVE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_SUMMON_GENERAL:
                    me->SummonCreatureGroup(0);
                    _events.ScheduleEvent(EVENT_FACE_TO_GENERAL, 12s);
                    break;
                case EVENT_FACE_TO_GENERAL:
                    Talk(SAY_OUTRO_1);
                    me->SetFacingTo(5.339049f);
                    _events.ScheduleEvent(EVENT_SAY_OUTRO_2, 15s);
                    break;
                case EVENT_SAY_OUTRO_2:
                    Talk(SAY_OUTRO_2);
                    _events.ScheduleEvent(EVENT_CAST_TELEPORT, 7s);
                    break;
                case EVENT_CAST_TELEPORT:
                    DoCast(me, SPELL_TELEPORT_VISUAL, true);
                    _events.ScheduleEvent(EVENT_DESPAWN, 2s);
                    break;
                case EVENT_DESPAWN:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    bool _calledForHelp;
    bool _defeated;
};

enum FurtherConcerns
{
    // Events
    EVENT_PLAY_MOUNT_ANIMATION  = 1,
    EVENT_START_RIDING          = 2,
    EVENT_EJECT_PASSENGER       = 3,

    // Move Points
    POINT_BRIGDE                = 1,

    // Sound Ids
    SOUND_ID_MOUNTSPECIAL       = 4066,

    // Spells
    SPELL_EJECT_PASSENGER_1     = 77946
};

static constexpr uint8 StormwindChargerPathSize = 39;
Position const StormwindChargerPath[StormwindChargerPathSize] =
{
    { -9465.488f, 64.75174f, 55.9232f },
    { -9489.841f, 64.25694f, 55.95109f },
    { -9503.804f, 35.873264f, 56.39156f },
    { -9523.1455f, -2.920139f, 55.85599f },
    { -9541.677f, -38.56597f, 56.474117f },
    { -9547.922f, -69.87327f, 57.372242f },
    { -9549.37f, -110.31077f, 57.489456f },
    { -9555.764f, -137.2448f, 57.400364f },
    { -9575.194f, -159.01389f, 57.548084f },
    { -9586.826f, -197.10591f, 57.53395f },
    { -9603.833f, -239.58333f, 57.28743f },
    { -9615.153f, -277.39062f, 57.83489f },
    { -9619.554f, -310.06946f, 57.385513f },
    { -9620.591f, -344.71353f, 57.166138f },
    { -9620.62f, -373.00348f, 57.503777f },
    { -9618.868f, -401.0625f, 57.791756f },
    { -9611.052f, -427.99478f, 57.386707f },
    { -9597.004f, -456.90973f, 57.62922f },
    { -9589.788f, -484.03995f, 57.71283f },
    { -9596.089f, -506.9896f, 57.407463f },
    { -9610.698f, -531.625f, 54.788067f },
    { -9617.52f, -558.88196f, 54.451187f },
    { -9622.382f, -607.8733f, 52.419804f },
    { -9626.333f, -636.25696f, 51.19875f },
    { -9638.899f, -656.44617f, 49.511f },
    { -9644.645f, -673.96875f, 48.639606f },
    { -9655.107f, -718.59375f, 44.738724f },
    { -9655.63f, -745.4809f, 44.562298f },
    { -9652.263f, -776.8698f, 44.270496f },
    { -9647.052f, -797.9809f, 43.50934f },
    { -9631.623f, -816.98267f, 43.828598f },
    { -9609.665f, -840.8333f, 43.67657f },
    { -9589.141f, -863.5243f, 43.705048f },
    { -9582.302f, -898.25f, 43.62359f },
    { -9587.446f, -930.15454f, 43.31383f },
    { -9609.941f, -959.48956f, 43.61531f },
    { -9619.147f, -980.625f, 43.67072f },
    { -9621.516f, -1009.3889f, 41.507584f },
    { -9618.427f, -1032.1129f, 39.71602f }
};

struct npc_elwynn_stormwind_charger : public ScriptedAI
{
    npc_elwynn_stormwind_charger(Creature* creature) : ScriptedAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!passenger->IsPlayer())
            return;

        me->PlayDirectSound(SOUND_ID_MOUNTSPECIAL, passenger->ToPlayer());

        if (apply)
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
            _events.ScheduleEvent(EVENT_PLAY_MOUNT_ANIMATION, 200ms);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PLAY_MOUNT_ANIMATION:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);
                    _events.ScheduleEvent(EVENT_START_RIDING, 1s + 200ms);
                    break;
                case EVENT_START_RIDING:
                    me->GetMotionMaster()->MoveSmoothPath(POINT_BRIGDE, StormwindChargerPath, StormwindChargerPathSize);
                    break;
                case EVENT_EJECT_PASSENGER:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);
                    DoCastSelf(SPELL_EJECT_PASSENGER_1);
                    break;
                default:
                    break;
            }
        }
    }


    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType == EFFECT_MOTION_TYPE && pointId == POINT_BRIGDE)
            _events.ScheduleEvent(EVENT_EJECT_PASSENGER, 2s);
    }

private:
    EventMap _events;
};

enum COG_Paths
{
    STORMWIND_PATH  = 80500,
    GOLDSHIRE_PATH  = 80501,
    WOODS_PATH      = 80502,
    HOUSE_PATH      = 80503,
    LISA_PATH       = 80700
};

enum COG_Waypoints
{
    STORMWIND_WAYPOINT  = 57,
    GOLDSHIRE_WAYPOINT  = 32,
    WOODS_WAYPOINT      = 22,
    HOUSE_WAYPOINT      = 35,
    LISA_WAYPOINT       = 4
};

enum COG_Sounds
{
    BANSHEE_DEATH           = 1171,
    BANSHEEPREAGGRO         = 1172,
    CTHUN_YOU_WILL_DIE      = 8585,
    CTHUN_DEATH_IS_CLOSE    = 8580,
    HUMAN_FEMALE_EMOTE_CRY  = 6916,
    GHOSTDEATH              = 3416
};

enum COG_Creatures
{
    NPC_DANA    = 804,
    NPC_CAMERON = 805,
    NPC_JOHN    = 806,
    NPC_LISA    = 807,
    NPC_AARON   = 810,
    NPC_JOSE    = 811
};

enum COG_Events
{
    EVENT_WP_START_GOLDSHIRE    = 1,
    EVENT_WP_START_WOODS        = 2,
    EVENT_WP_START_HOUSE        = 3,
    EVENT_WP_START_LISA         = 4,
    EVENT_PLAY_SOUNDS           = 5,
    EVENT_BEGIN_EVENT           = 6
};

enum COG_GameEvent
{
    GAME_EVENT_CHILDREN_OF_GOLDSHIRE = 76
};

struct npc_cameron : public ScriptedAI
{
    npc_cameron(Creature* creature) : ScriptedAI(creature)
    {
        _started = false;
    }

    static uint32 SoundPicker()
    {
        return RAND(
            BANSHEE_DEATH,
            BANSHEEPREAGGRO,
            CTHUN_YOU_WILL_DIE,
            CTHUN_DEATH_IS_CLOSE,
            HUMAN_FEMALE_EMOTE_CRY,
            GHOSTDEATH
        );
    }

    void MoveTheChildren()
    {
        std::vector<Position> MovePosPositions =
        {
            { -9373.521f, -67.71767f, 69.201965f, 1.117011f },
            { -9374.94f, -62.51654f, 69.201965f, 5.201081f },
            { -9371.013f, -71.20811f, 69.201965f, 1.937315f },
            { -9368.419f, -66.47543f, 69.201965f, 3.141593f },
            { -9372.376f, -65.49946f, 69.201965f, 4.206244f },
            { -9377.477f, -67.8297f, 69.201965f, 0.296706f }
        };

        Trinity::Containers::RandomShuffle(MovePosPositions);

        // first we break formation because children will need to move on their own now
        for (auto guid : _childrenGUIDs)
            if (Creature* child = ObjectAccessor::GetCreature(*me, guid))
                if (child->GetFormation())
                    child->GetFormation()->RemoveMember(child);

        // Move each child to an random position
        for (uint32 i = 0; i < _childrenGUIDs.size(); ++i)
        {
            if (Creature* children = ObjectAccessor::GetCreature(*me, _childrenGUIDs[i]))
            {
                children->SetWalk(true);
                children->GetMotionMaster()->MovePoint(0, MovePosPositions.at(i));
                me->SetHomePosition(MovePosPositions.at(i));
            }
        }
        me->SetWalk(true);
        me->GetMotionMaster()->MovePoint(0, MovePosPositions.back());
        me->SetHomePosition(MovePosPositions.back());
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        switch (pathId)
        {
            case STORMWIND_PATH:
            {
                if (waypointId == STORMWIND_WAYPOINT)
                {
                    me->GetMotionMaster()->MoveRandom(10.f);
                    _events.ScheduleEvent(EVENT_WP_START_GOLDSHIRE, Minutes(11));
                }

                break;
            }
            case GOLDSHIRE_PATH:
            {
                if (waypointId == GOLDSHIRE_WAYPOINT)
                {
                    me->GetMotionMaster()->MoveRandom(10.f);
                    _events.ScheduleEvent(EVENT_WP_START_WOODS, Minutes(15));
                }
                break;
            }
            case WOODS_PATH:
            {
                if (waypointId == WOODS_WAYPOINT)
                {
                    me->GetMotionMaster()->MoveRandom(10.f);
                    _events.ScheduleEvent(EVENT_WP_START_HOUSE, Minutes(6));
                    _events.ScheduleEvent(EVENT_WP_START_LISA, Seconds(2));
                }

                break;
            }
            case HOUSE_PATH:
            {
                if (waypointId == HOUSE_WAYPOINT)
                {
                    // Move childeren at last point
                    MoveTheChildren();

                    // After 30 seconds a random sound should play
                    _events.ScheduleEvent(EVENT_PLAY_SOUNDS, Seconds(30));
                }
                break;
            }
        }
    }

    void OnGameEvent(bool start, uint16 eventId) override
    {
        if (start && eventId == GAME_EVENT_CHILDREN_OF_GOLDSHIRE)
        {
            // Start event at 7 am
            // Begin pathing
            _events.ScheduleEvent(EVENT_BEGIN_EVENT, Seconds(2));
            _started = true;
        }
        else if (!start && eventId == GAME_EVENT_CHILDREN_OF_GOLDSHIRE)
        {
            // Reset event at 8 am
            _started = false;
            _events.Reset();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_started)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WP_START_GOLDSHIRE:
                    me->GetMotionMaster()->MovePath(GOLDSHIRE_PATH, false);
                    break;
                case EVENT_WP_START_WOODS:
                    me->GetMotionMaster()->MovePath(WOODS_PATH, false);
                    break;
                case EVENT_WP_START_HOUSE:
                    me->GetMotionMaster()->MovePath(HOUSE_PATH, false);
                    break;
                case EVENT_WP_START_LISA:
                    for (uint32 i = 0; i < _childrenGUIDs.size(); ++i)
                    {
                        if (Creature* lisa = ObjectAccessor::GetCreature(*me, _childrenGUIDs[i]))
                        {
                            if (lisa->GetEntry() == NPC_LISA)
                            {
                                lisa->GetMotionMaster()->MovePath(LISA_PATH, false);
                                break;
                            }
                        }
                    }
                    break;
                case EVENT_PLAY_SOUNDS:
                    me->PlayDistanceSound(SoundPicker());
                    break;
                case EVENT_BEGIN_EVENT:
                {
                    _childrenGUIDs.clear();

                    // Get all childeren's guid's.
                    if (Creature* dana = me->FindNearestCreature(NPC_DANA, 25.0f))
                        _childrenGUIDs.push_back(dana->GetGUID());

                    if (Creature* john = me->FindNearestCreature(NPC_JOHN, 25.0f))
                        _childrenGUIDs.push_back(john->GetGUID());

                    if (Creature* lisa = me->FindNearestCreature(NPC_LISA, 25.0f))
                        _childrenGUIDs.push_back(lisa->GetGUID());

                    if (Creature* aaron = me->FindNearestCreature(NPC_AARON, 25.0f))
                        _childrenGUIDs.push_back(aaron->GetGUID());

                    if (Creature* jose = me->FindNearestCreature(NPC_JOSE, 25.0f))
                        _childrenGUIDs.push_back(jose->GetGUID());

                    // If Formation was disbanded, remake.
                    if (!me->GetFormation()->isFormed())
                        for (auto guid : _childrenGUIDs)
                            if (Creature* child = ObjectAccessor::GetCreature(*me, guid))
                                child->SearchFormation();

                    // Start movement
                    me->GetMotionMaster()->MovePath(STORMWIND_PATH, false);

                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _started;
    GuidVector _childrenGUIDs;
};

void AddSC_elwynn_forest()
{
    RegisterCreatureAI(npc_stormwind_infantry);
    RegisterCreatureAI(npc_blackrock_battle_worg);
    RegisterCreatureAI(npc_injured_stormwind_infantry_dummy);
    RegisterCreatureAI(npc_hogger);
    RegisterCreatureAI(npc_elwynn_stormwind_charger);
    RegisterCreatureAI(npc_cameron);
}
