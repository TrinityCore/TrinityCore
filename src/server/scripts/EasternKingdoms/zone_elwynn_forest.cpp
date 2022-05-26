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

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "CreatureGroups.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

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
        for (ObjectGuid guid : _childrenGUIDs)
            if (Creature* child = ObjectAccessor::GetCreature(*me, guid))
                if (child->GetFormation())
                    child->GetFormation()->RemoveMember(child);

        // Move each child to an random position
        for (uint32 i = 0; i < _childrenGUIDs.size(); ++i)
        {
            if (Creature* children = ObjectAccessor::GetCreature(*me, _childrenGUIDs[i]))
            {
                children->SetWalk(true);
                children->GetMotionMaster()->MovePoint(0, MovePosPositions[i], true, MovePosPositions[i].GetOrientation());
            }
        }
        me->SetWalk(true);
        me->GetMotionMaster()->MovePoint(0, MovePosPositions.back(), true, MovePosPositions.back().GetOrientation());
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
                    _events.ScheduleEvent(EVENT_WP_START_GOLDSHIRE, 11min);
                }

                break;
            }
            case GOLDSHIRE_PATH:
            {
                if (waypointId == GOLDSHIRE_WAYPOINT)
                {
                    me->GetMotionMaster()->MoveRandom(10.f);
                    _events.ScheduleEvent(EVENT_WP_START_WOODS, 15min);
                }
                break;
            }
            case WOODS_PATH:
            {
                if (waypointId == WOODS_WAYPOINT)
                {
                    me->GetMotionMaster()->MoveRandom(10.f);
                    _events.ScheduleEvent(EVENT_WP_START_HOUSE, 6min);
                    _events.ScheduleEvent(EVENT_WP_START_LISA, 2s);
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
                    _events.ScheduleEvent(EVENT_PLAY_SOUNDS, 30s);
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
            _events.ScheduleEvent(EVENT_BEGIN_EVENT, 2s);
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
                    for (ObjectGuid guid : _childrenGUIDs)
                    {
                        if (Creature* child = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (child->GetEntry() == NPC_LISA)
                            {
                                child->GetMotionMaster()->MovePath(LISA_PATH, false);
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
                    if (!me->GetFormation()->IsFormed())
                        for (ObjectGuid guid : _childrenGUIDs)
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

enum NA_Creatures {
    NPC_BROTHER_PAXTON = 951,
    NPC_STORWIND_INFANTRY = 49869,
    NPC_BLACKROCK_WORG = 49871,
};
enum NA_Events {
    EVENT_ASK_FOR_HELP = 1,
    EVENT_HEAL_INFANTRY,
};

enum NA_Says {
    SAY_ASK_FOR_HELP = 0,
    SAY_HEAL_INFANTRY = 0,
};

enum NA_Spells {
    SPELL_FLASH_HEAL                        = 17843,
    SPELL_PRAYER_OF_HEALING                 = 93091,
    SPELL_RENEW                             = 93094,
};

struct npc_stormwind_infantry : public ScriptedAI
{
    npc_stormwind_infantry(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_ASK_FOR_HELP, Seconds(urand(1, 10) * 10));
    }

    void DamageDealt(Unit* target, uint32& damage, DamageEffectType /*damageType*/) override
    {
        if (target->ToCreature() && target->ToCreature()->GetEntry()==NPC_BLACKROCK_WORG)
            if (target->GetHealth() <= damage || target->GetHealthPct() <= 70.0f)
                damage = 0;
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

struct npc_blackrock_worg : public ScriptedAI
{
    npc_blackrock_worg(Creature* creature) : ScriptedAI(creature), _isAttackingInfantry(false) { }

    void Reset() override
    {
        me->m_Events.AddEventAtOffset([this]
        {
            if (Creature* infantry = me->FindNearestCreature(NPC_STORWIND_INFANTRY, 15.0f, true))
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
    void DamageDealt(Unit* target, uint32& damage, DamageEffectType /*damageType*/) override
    {
        if (target->ToCreature() && target->ToCreature()->GetEntry()==NPC_STORWIND_INFANTRY)
            if (target->GetHealth() <= damage || target->GetHealthPct() <= 70.0f)
                damage = 0;
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/, DamageEffectType /* effectType */, const SpellInfo* /* info */) override
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

void AddSC_elwynn_forest()
{
    RegisterCreatureAI(npc_cameron);
    RegisterCreatureAI(npc_stormwind_infantry);
    RegisterCreatureAI(npc_blackrock_worg);
}
