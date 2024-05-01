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

#include "scarlet_monastery.h"
#include "Containers.h"
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "WaypointDefines.h"

enum HeadlessHorsemanSays
{
    // Head
    SAY_LOST_HEAD          = 0,
    SAY_REQUEST_BODY       = 1,
    SAY_PLAYER_RISE        = 2,
    SAY_PLAYER_TIME        = 3,
    SAY_PLAYER_DEATH       = 4,
    SAY_PLAYER_DEMISE      = 5,

    // Boss
    SAY_HORSEMAN_ENTRANCE  = 0,
    SAY_REJOINED           = 1,
    SAY_CONFLAGRATION      = 2,
    SAY_SPROUTING_PUMPKINS = 3,
    SAY_DEATH              = 4,
    SAY_KILL_PLAYER        = 5
};

enum HeadlessHorsemanSpells
{
    // Horseman & Head
    SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL                  = 42413,
    SPELL_HEADLESS_HORSEMAN_ONKILL_PROC                    = 43877,
    SPELL_HEADLESS_HORSEMAN_YELL_TIMER                     = 42432,
    SPELL_HEADLESS_HORSEMAN_MANIACAL_LAUGH                 = 43893,
    SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_1                 = 42547,
    SPELL_HEADLESS_HORSEMAN_CLEAVE                         = 42587,
    SPELL_HEADLESS_HORSEMAN_C_COMMAND_HEAD_REPOSITIONS     = 42410,
    SPELL_HEADLESS_HORSEMAN_C_SEND_HEAD                    = 42399,
    SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_CONFUSE           = 43105,
    SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_IMMUNE            = 42556,
    SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_TRANSFORM         = 42403,
    SPELL_HEADLESS_HORSEMAN_C_HEAD_STUN                    = 42408,
    SPELL_HEADLESS_HORSEMAN_C_HEAD_PERIODIC                = 42603,
    SPELL_HEADLESS_HORSEMAN_C_HEAL_BODY                    = 43306,
    SPELL_HEADLESS_HORSEMAN_C_RETURN_HEAD                  = 42401,
    SPELL_HEADLESS_HORSEMAN_SPEAKS                         = 43129,
    SPELL_HEADLESS_HORSEMAN_C_COMMAND_REQUEST_BODY         = 43101,
    SPELL_HEADLESS_HORSEMAN_C_HEAD_PAUSE                   = 42504,
    SPELL_HEADLESS_HORSEMAN_C_HEAD_IS_DEAD                 = 42428,
    SPELL_RAIN_OF_TREATS                                   = 43344,
    SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_2                 = 42548,
    SPELL_HORSEMANS_CONFLAGRATION_SOUND                    = 48149,
    SPELL_HORSEMANS_CONFLAGRATION_SOUND_THROTTLE           = 48148, // missing soundid
    SPELL_CONFLAGRATION                                    = 42380,
    SPELL_HEADLESS_HORSEMAN_C_HORSEMANS_WHIRLWIND          = 43116,
    SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_3                 = 42549,
    SPELL_SUMMON_PUMPKIN_BURST_DELAY                       = 52236,
    SPELL_HEADLESS_HORSEMAN_C_BODY_DEATH                   = 42429,
    SPELL_HEADLESS_HORSEMAN_BURNING_COSMETIC               = 42971,
    SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_AURA         = 42879,
    SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_SHAKE_MEDIUM = 42909,
    SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_SHAKE_SMALL  = 42910,

    // Pumpkin
    SPELL_PUMPKIN_LIFE_CYCLE                               = 42280,
    SPELL_HEADLESS_HORSEMAN_PUMPKIN_AURA                   = 42294,
    SPELL_SPROUTING                                        = 42281,
    SPELL_SPROUT_BODY                                      = 42285,
    SPELL_SQUASH_SOUL                                      = 42514,

    // Fire Bunny
    SPELL_HEADLESS_HORSEMAN_BURNING_COSMETIC_BASE          = 43184,
    SPELL_HEADLESS_HORSEMAN_FIRE_SIZE_BIG                  = 43148,

    // Sir Thomas
    SPELL_HEADLESS_HORSEMAN_WISP_INVIS                     = 42823,
    SPELL_HEADLESS_HORSEMAN_WISP_FLIGHT_MISSILE            = 42821,
    SPELL_HEADLESS_HORSEMAN_WISP_FLIGHT_PORT               = 42818,
    SPELL_HEADLESS_HORSEMAN_C_GHOST_VISUAL                 = 42575,

    SPELL_HEADLESS_HORSEMAN_C_ENRAGED_VISUAL               = 42438 // Not used, maybe a bersek mechanic?
};

enum HeadlessEvents
{
    EVENT_HORSEMAN_CLEAVE = 1,
    EVENT_START_NEXT_HEADLESS_PHASE,
    EVENT_START_HEAD_DELAYED,
    EVENT_STOP_HEAD_PHASE,
    EVENT_RAIN_OF_TREATS,
    EVENT_START_NEXT_PHASE_DELAYED,
    EVENT_CONFLAGRATE,
    EVENT_SUMMON_PUMPKIN,
    EVENT_RANDOM_LAUGH
};

enum HeadlessActions
{
    ACTION_HEAD_START_HEAD_PHASE = 1,
    ACTION_HEAD_HP_67,
    ACTION_HEAD_HP_34,
    ACTION_HEAD_IS_DEAD,
    ACTION_HORSEMAN_REQUEST_BODY,
    ACTION_HEAD_RETURN_TO_BODY,
    ACTION_HEAD_PLAYER_TEXT,
    ACTION_PUMPKIN_SPROUTING_FINISHED,
    ACTION_OTHER_OBJECT_ACTIVE
};

enum HeadlessHorsemanMisc
{
    PHASE_1                             = 1,
    PHASE_2                             = 2,
    PHASE_3                             = 3,
    PHASE_LAST                          = 4,
    PHASE_DEAD                          = 5,
    POINT_HORSEMAN_FINISH_PATH          = 1,
    POINT_HEAD                          = 2,
    LFG_DUNGEONID_THE_HEADLESS_HORSEMAN = 285,
    SOUNDID_MANIACAL_LAUGH              = 11975,
    SOUNDID_MANIACAL_LAUGH_2            = 11965,
    SOUNDID_MANIACAL_LAUGH_3            = 11976,
    QUEST_CALL_THE_HEADLESS_HORSEMAN    = 11405
};

WaypointPath const HeadlessHorsemanFlightPoints =
{
    POINT_HORSEMAN_FINISH_PATH,
    {
        { 0, 1765.00f, 1347.00f, 19.00f },
        { 1, 1784.00f, 1346.80f, 25.40f },
        { 2, 1803.30f, 1347.60f, 33.00f },
        { 3, 1824.00f, 1350.00f, 42.60f },
        { 4, 1838.80f, 1353.20f, 49.80f },
        { 5, 1852.00f, 1357.60f, 55.70f },
        { 6, 1861.30f, 1364.00f, 59.40f },
        { 7, 1866.30f, 1374.80f, 61.70f },
        { 8, 1864.00f, 1387.30f, 63.20f },
        { 9, 1854.80f, 1399.40f, 64.10f },
        { 10, 1844.00f, 1406.90f, 64.10f },
        { 11, 1824.30f, 1411.40f, 63.30f },
        { 12, 1801.00f, 1412.30f, 60.40f },
        { 13, 1782.00f, 1410.10f, 55.50f },
        { 14, 1770.50f, 1405.20f, 50.30f },
        { 15, 1765.20f, 1400.70f, 46.60f },
        { 16, 1761.40f, 1393.40f, 41.70f },
        { 17, 1759.10f, 1386.70f, 36.60f },
        { 18, 1757.80f, 1378.20f, 29.00f },
        { 19, 1758.00f, 1367.00f, 19.51f }
    },
    WaypointMoveType::Run,
    WaypointPathFlags::FlyingPath
};

std::vector<uint32> HeadlessHorsemanRandomLaughSound = { SOUNDID_MANIACAL_LAUGH, SOUNDID_MANIACAL_LAUGH_2, SOUNDID_MANIACAL_LAUGH_3 };
Position const GOPumpkinSpawnPosition = { 1776.27f, 1348.74f, 20.4116f, 6.27281f };
QuaternionData const GOPumpkinSpawnQuat = QuaternionData(0.0f, 0.0f, 0.00518764f, -0.999987f);
Position const GOSoilSpawnPosition = { 1765.28f, 1347.46f, 17.5514f, 0.100363f };
QuaternionData const GOSoilSpawnQuat = QuaternionData(0.0f, 0.0f, 0.0501604f, -0.998741f);

struct npc_headless_horseman_head : public PassiveAI
{
    npc_headless_horseman_head(Creature* creature) : PassiveAI(creature), _instance(creature->GetInstanceScript()), _phase(PHASE_1)
    {
        creature->SetDisplayFromModel(0);
    }

    void JustAppeared() override
    {
        HandleInitialSetup();
    }

    void HandleInitialSetup()
    {
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_STUN);
        me->SetUninteractible(true);
        _phase = PHASE_1;
        _events.SetPhase(PHASE_1);
    }

    void JustReachedHome() override
    {
        _events.Reset();
        me->GetMotionMaster()->Clear();
        HandleInitialSetup();
        PassiveAI::JustReachedHome();
    }

    void DoAction(int32 id) override
    {
        switch (id)
        {
            case ACTION_HEAD_START_HEAD_PHASE:
                _events.ScheduleEvent(EVENT_START_HEAD_DELAYED, 1s);
                break;
            case ACTION_HEAD_HP_67:
                if (_phase == PHASE_1)
                {
                    ++_phase;
                    me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HEAD_PERIODIC);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAL_BODY);
                    _events.ScheduleEvent(EVENT_STOP_HEAD_PHASE, 1s);
                }
                break;
            case ACTION_HEAD_HP_34:
                if (_phase == PHASE_2)
                {
                    ++_phase;
                    me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HEAD_PERIODIC);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_PAUSE);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAL_BODY, true);
                    _events.ScheduleEvent(EVENT_STOP_HEAD_PHASE, 1s);
                }
                break;
            default:
                break;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id != ACTION_HEAD_PLAYER_TEXT)
            return;

        if (Unit* target = ObjectAccessor::GetUnit(*me, guid))
            DoCast(target, SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_AURA, true);
    }

    void HandleStartPhase()
    {
        me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HEAD_STUN);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL, true);
        me->SetUninteractible(false);
        me->GetMotionMaster()->MoveRandom(30.0f);

        switch (_phase)
        {
            case PHASE_1:
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_PERIODIC, true);
                break;
            case PHASE_2:
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_PERIODIC, true);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_SPEAKS, true);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_COMMAND_REQUEST_BODY, true);
                Talk(SAY_REQUEST_BODY);
                break;
            case PHASE_3:
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_SPEAKS, true);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_COMMAND_REQUEST_BODY, true);
                Talk(SAY_REQUEST_BODY);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.SetPhase(PHASE_DEAD);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_IS_DEAD);
        _events.ScheduleEvent(EVENT_RAIN_OF_TREATS, 11s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_events.IsInPhase(PHASE_DEAD) && !UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_HEAD_DELAYED:
                    HandleStartPhase();
                    break;
                case EVENT_STOP_HEAD_PHASE:
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_STUN);
                    me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL);
                    if (Creature* horseman = _instance->GetCreature(DATA_HEADLESS_HORSEMAN))
                        DoCast(horseman, SPELL_HEADLESS_HORSEMAN_C_RETURN_HEAD, true);
                    me->RemoveAllAttackers();
                    me->GetMotionMaster()->Clear();
                    me->SetUninteractible(true);
                    break;
                case EVENT_RAIN_OF_TREATS:
                    DoCastSelf(SPELL_RAIN_OF_TREATS);
                    me->SetUninteractible(true);
                    _instance->SetData(DATA_PREPARE_RESET, 0);
                    if (GameObject* pumpkin = me->SummonGameObject(GO_PUMPKIN_SHRINE, GOPumpkinSpawnPosition, GOPumpkinSpawnQuat, 7_days))
                        me->RemoveGameObject(pumpkin, false);
                    if (GameObject* soil = me->SummonGameObject(GO_LOOSELY_TURNED_SOIL, GOSoilSpawnPosition, GOSoilSpawnQuat, 7_days))
                        me->RemoveGameObject(soil, false);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    uint8 _phase;
};

struct boss_headless_horseman : public ScriptedAI
{
    boss_headless_horseman(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me), _introDone(false) { }

    void InitializeAI() override
    {
        me->SetDisableGravity(true);
        me->SetHover(true);
        ScriptedAI::InitializeAI();
    }

    void HandleInitialSetup()
    {
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL, true);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_ONKILL_PROC, true);
    }

    void JustAppeared() override
    {
        HandleInitialSetup();
    }

    void Reset() override
    {
        _events.Reset();
        _events.SetPhase(PHASE_1);
        _summons.DespawnAll();
        me->setActive(false);
        if (_introDone)
            me->SetImmuneToPC(false);
        me->SetWalk(false);
    }

    void JustReachedHome() override
    {
        HandleInitialSetup();
        me->SetReactState(REACT_AGGRESSIVE);
        ScriptedAI::JustReachedHome();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        _events.ScheduleEvent(EVENT_HORSEMAN_CLEAVE, 13s, 0, PHASE_1);
        _events.ScheduleEvent(EVENT_RANDOM_LAUGH, 30s, 60s);

        if (Creature* head = _instance->GetCreature(DATA_HORSEMAN_HEAD))
            head->AI()->DoZoneInCombat();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
        DoZoneInCombat(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        _summons.Despawn(summon);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL_PLAYER);
    }

    void DoAction(int32 id) override
    {
        switch (id)
        {
            case ACTION_HORSEMAN_EVENT_START:
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_YELL_TIMER, true);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_MANIACAL_LAUGH, true);
                me->GetMotionMaster()->MovePath(HeadlessHorsemanFlightPoints, false);
                break;
            case ACTION_HORSEMAN_REQUEST_BODY:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_CONFUSE);
                me->GetMotionMaster()->Clear();
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HORSEMANS_WHIRLWIND, true);
                if (Creature* head = _instance->GetCreature(DATA_HORSEMAN_HEAD))
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_HEAD, head->GetPosition());
                }
                break;
            case ACTION_HEAD_RETURN_TO_BODY:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_CONFUSE);
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_IMMUNE);
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_TRANSFORM);
                Talk(SAY_REJOINED);
                _events.ScheduleEvent(EVENT_START_NEXT_PHASE_DELAYED, 3s);
                break;
            case ACTION_HEAD_IS_DEAD:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_IMMUNE);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_DEATH, true);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_BURNING_COSMETIC);
        _instance->SetData(DATA_HORSEMAN_EVENT_STATE, DONE);
        Talk(SAY_DEATH);
        me->SummonCreature(NPC_SIR_THOMAS, me->GetPosition());
        // Credit LFG
        if (me->GetMap()->HavePlayers())
        {
            Map* map = me->GetMap();
            if (Group* group = map->GetPlayers().begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), LFG_DUNGEONID_THE_HEADLESS_HORSEMAN, map);
        }
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && who != me)
        {
            damage = 0;

            if (_events.IsInPhase(PHASE_1))
                StartPhase(PHASE_2);
            else if (_events.IsInPhase(PHASE_2))
                StartPhase(PHASE_3);
            else if (_events.IsInPhase(PHASE_3))
                StartPhase(PHASE_LAST);
        }
    }

    void StartPhase(uint8 nextPhase)
    {
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_IMMUNE, true);
        _events.SetPhase(nextPhase);
        me->SetReactState(REACT_PASSIVE);
        me->AttackStop();
        me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HORSEMANS_WHIRLWIND);
        me->SetWalk(false);

        switch (nextPhase)
        {
            case PHASE_2:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_1);
                break;
            case PHASE_3:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_2);
                break;
            case PHASE_LAST:
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_3);
                me->RemoveAurasDueToSpell(SPELL_SUMMON_PUMPKIN_BURST_DELAY);
                break;
            default:
                break;
        }

        _events.ScheduleEvent(EVENT_START_NEXT_HEADLESS_PHASE, 1ms, 0, nextPhase);
    }

    void SchedulePhase2Events()
    {
        _events.ScheduleEvent(EVENT_CONFLAGRATE, 5s, 0, PHASE_2);
        _events.ScheduleEvent(EVENT_HORSEMAN_CLEAVE, 16s, 0, PHASE_2);
    }

    void SchedulePhase3Events()
    {
        _events.ScheduleEvent(EVENT_SUMMON_PUMPKIN, 1s, 0, PHASE_3);
        _events.ScheduleEvent(EVENT_HORSEMAN_CLEAVE, 9s, 0, PHASE_3);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_HEAD:
                me->SetWalk(false);
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HORSEMANS_WHIRLWIND);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_CONFUSE, true);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*waypointId*/, uint32 pathId) override
    {
        if (pathId != POINT_HORSEMAN_FINISH_PATH)
            return;

        _introDone = true;
        me->SetImmuneToPC(false);
        me->SetDisableGravity(false);
        me->SetHover(false);
        me->SetHomePosition(me->GetPosition());
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_1);
        me->SetReactState(REACT_AGGRESSIVE);
        DoZoneInCombat();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HORSEMAN_CLEAVE:
                    DoCastVictim(SPELL_HEADLESS_HORSEMAN_CLEAVE);
                    _events.Repeat(6s, 12s);
                    break;
                case EVENT_START_NEXT_HEADLESS_PHASE:
                    DoCastAOE(SPELL_HEADLESS_HORSEMAN_C_COMMAND_HEAD_REPOSITIONS);
                    if (Creature* head = _instance->GetCreature(DATA_HORSEMAN_HEAD))
                        DoCast(head, SPELL_HEADLESS_HORSEMAN_C_SEND_HEAD, true);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_CONFUSE, true);
                    me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_REGEN_TRANSFORM, true);
                    break;
                case EVENT_START_NEXT_PHASE_DELAYED:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_HEAD_VISUAL);
                    if (_events.IsInPhase(PHASE_2))
                    {
                        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_2);
                        SchedulePhase2Events();
                    }
                    else if (_events.IsInPhase(PHASE_3))
                    {
                        DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_BODY_STAGE_3);
                        SchedulePhase3Events();
                    }

                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat))
                        AttackStart(target);
                    break;
                case EVENT_CONFLAGRATE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true, false))
                    {
                        DoCastSelf(SPELL_HORSEMANS_CONFLAGRATION_SOUND, true);
                        DoCastSelf(SPELL_HORSEMANS_CONFLAGRATION_SOUND_THROTTLE, true);
                        DoCast(target, SPELL_CONFLAGRATION);
                        Talk(SAY_CONFLAGRATION);
                    }
                    _events.Repeat(18s, 21s);
                    break;
                case EVENT_SUMMON_PUMPKIN:
                    DoCastSelf(SPELL_SUMMON_PUMPKIN_BURST_DELAY);
                    _events.Repeat(30s);
                    break;
                case EVENT_RANDOM_LAUGH:
                    DoPlaySoundToSet(me, Trinity::Containers::SelectRandomContainerElement(HeadlessHorsemanRandomLaughSound));
                    _events.Repeat(30s, 60s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    SummonList _summons;
    bool _introDone;
};

struct npc_pulsing_pumpkin : public ScriptedAI
{
    npc_pulsing_pumpkin(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetDisableGravity(true);
        me->SetHover(true);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_PUMPKIN_LIFE_CYCLE);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_PUMPKIN_AURA);
        DoCastSelf(SPELL_SPROUTING);
    }

    void DoAction(int32 id) override
    {
        if (id != ACTION_PUMPKIN_SPROUTING_FINISHED)
            return;

        _scheduler.Schedule(1s, [this](TaskContext /*context*/)
        {
            me->RemoveAurasDueToSpell(SPELL_PUMPKIN_LIFE_CYCLE);
            me->SetDisableGravity(false);
            me->SetHover(false);
            DoCastSelf(SPELL_SPROUT_BODY, true);
            me->UpdateEntry(NPC_PUMPKIN_FIEND, nullptr, false);
            me->SetImmuneToNPC(true);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();
        }).Schedule(11s, [this](TaskContext squashSoul)
        {
            DoCastVictim(SPELL_SQUASH_SOUL);
            squashSoul.Repeat(10s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_flame_bunny : public PassiveAI
{
    npc_flame_bunny(Creature* creature) : PassiveAI(creature)
    {
        creature->SetDisplayFromModel(1);
    }

    void Reset() override
    {
        _scheduler.Schedule(1s, [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_HEADLESS_HORSEMAN_BURNING_COSMETIC_BASE);
        }).Schedule(3s, [this](TaskContext grow)
        {
            DoCastSelf(SPELL_HEADLESS_HORSEMAN_FIRE_SIZE_BIG);
            if (grow.GetRepeatCounter() < 2)
                grow.Repeat(2s + 200ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_sir_thomas : public PassiveAI
{
    npc_sir_thomas(Creature* creature) : PassiveAI(creature) { }

    void Reset() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->SetUninteractible(true);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_WISP_INVIS);

        _scheduler.Schedule(9s, [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_HEADLESS_HORSEMAN_WISP_FLIGHT_MISSILE);
        });
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_HEADLESS_HORSEMAN_WISP_FLIGHT_PORT)
        {
            me->SetUninteractible(false);
            me->SetNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_WISP_INVIS);
            DoCastSelf(SPELL_HEADLESS_HORSEMAN_C_GHOST_VISUAL, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct go_loosely_turned_soil : public GameObjectAI
{
    go_loosely_turned_soil(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_CALL_THE_HEADLESS_HORSEMAN) != QUEST_STATUS_COMPLETE)
            return true;

        if (_instance->GetData(DATA_HORSEMAN_EVENT_STATE) != NOT_STARTED)
            return true;

        return false;
    }

    void OnQuestReward(Player* player, Quest const* /*quest*/, LootItemType /*type*/, uint32 /*opt*/) override
    {
        player->AreaExploredOrEventHappens(QUEST_CALL_THE_HEADLESS_HORSEMAN);
        _instance->SetData(DATA_START_HORSEMAN_EVENT, 0);
        if (Creature* head = _instance->GetCreature(DATA_HORSEMAN_HEAD))
            head->AI()->SetGUID(player->GetGUID(), ACTION_HEAD_PLAYER_TEXT);
    }

private:
    InstanceScript* _instance;
};

struct go_headless_horseman_pumpkin : public GameObjectAI
{
    go_headless_horseman_pumpkin(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        ClearGossipMenuFor(player);

        if (_instance->GetData(DATA_HORSEMAN_EVENT_STATE) != NOT_STARTED)
        {
            CloseGossipMenuFor(player);
            return true;
        }

        player->AreaExploredOrEventHappens(QUEST_CALL_THE_HEADLESS_HORSEMAN);
        _instance->SetData(DATA_START_HORSEMAN_EVENT, 0);
        if (Creature* head = _instance->GetCreature(DATA_HORSEMAN_HEAD))
            head->AI()->SetGUID(player->GetGUID(), ACTION_HEAD_PLAYER_TEXT);

        CloseGossipMenuFor(player);
        return true;
    }

private:
    InstanceScript* _instance;
};

// 42432 - Headless Horseman Yell Timer
class spell_headless_horseman_yell_timer : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* horseman = GetTarget()->ToCreature();
        if (!horseman || !horseman->IsAIEnabled())
            return;

        horseman->AI()->Talk(SAY_HORSEMAN_ENTRANCE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_headless_horseman_yell_timer::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 43893 - Headless Horseman - Maniacal Laugh, Maniacal, Delayed 8
class spell_headless_horseman_maniacal_laugh : public AuraScript
{
    void HandleSound(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->PlayDirectSound(SOUNDID_MANIACAL_LAUGH);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_headless_horseman_maniacal_laugh::HandleSound, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 42410 - Headless Horseman Climax - Command, Head Repositions
class spell_headless_horseman_head_reposition : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Position random = GetCaster()->GetRandomNearPosition(30.0f);
        GetHitUnit()->NearTeleportTo(random, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_head_reposition::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 42399 - Headless Horseman Climax - Send Head
class spell_headless_horseman_send_head : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* head = GetHitUnit();
        if (head->IsAIEnabled())
            head->GetAI()->DoAction(ACTION_HEAD_START_HEAD_PHASE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_send_head::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 42603 - Headless Horseman Climax, Head: Periodic
class spell_headless_horseman_head_periodic : public AuraScript
{
    void HandleHPCheck(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        if (target->HealthBelowPct(34))
            target->GetAI()->DoAction(ACTION_HEAD_HP_34);
        else if (target->HealthBelowPct(67))
            target->GetAI()->DoAction(ACTION_HEAD_HP_67);

    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_headless_horseman_head_periodic::HandleHPCheck, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 43101 - Headless Horseman Climax - Command, Head Requests Body
class spell_headless_horseman_command_head_request_body : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* horseman = GetHitUnit();
        if (horseman->IsAIEnabled())
            horseman->GetAI()->DoAction(ACTION_HORSEMAN_REQUEST_BODY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_command_head_request_body::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 42401 - Headless Horseman Climax - Return Head
class spell_headless_horseman_return_head : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* horseman = GetHitUnit();
        if (horseman->IsAIEnabled())
            horseman->GetAI()->DoAction(ACTION_HEAD_RETURN_TO_BODY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_return_head::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 52236 - Summon Pumpkin Burst Delay
class spell_summon_pumpkin_burst_delay : public AuraScript
{
    void HandleText(AuraEffect const* /*aurEff*/)
    {
        if (Creature* horseman = GetTarget()->ToCreature())
            horseman->AI()->Talk(SAY_SPROUTING_PUMPKINS);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_summon_pumpkin_burst_delay::HandleText, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 42428 - Headless Horseman Climax - Head Is Dead
class spell_headless_horseman_head_is_dead : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target || !target->IsAIEnabled())
            return;

        switch (target->GetEntry())
        {
            case NPC_HEADLESS_HORSEMAN:
                target->AI()->DoAction(ACTION_HEAD_IS_DEAD);
                break;
            case NPC_PULSING_PUMPKIN:
            case NPC_PUMPKIN_FIEND:
                target->KillSelf();
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_head_is_dead::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 42879 - Headless Horseman Climax - Summoning Rhyme Aura
class spell_headless_horseman_summoning_rhyme_aura : public AuraScript
{
    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        Creature* caster = GetCaster()->ToCreature();
        Player* player = GetTarget()->ToPlayer();
        if (!caster || !player)
            return;

        switch (aurEff->GetTickNumber())
        {
            case 1:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_RISE, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, SoundKitPlayType::Normal, TEAM_OTHER, false, player);
                break;
            case 3:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TIME, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, SoundKitPlayType::Normal, TEAM_OTHER, false, player);
                break;
            case 5:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_DEATH, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, SoundKitPlayType::Normal, TEAM_OTHER, false, player);
                player->CastSpell(player, SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_SHAKE_SMALL, true);
                break;
            case 8:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_DEMISE, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, SoundKitPlayType::Normal, TEAM_OTHER, false, player);
                player->CastSpell(player, SPELL_HEADLESS_HORSEMAN_C_SUMMONING_RHYME_SHAKE_MEDIUM, true);
                Remove();
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_headless_horseman_summoning_rhyme_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 42281 - Sprouting
class spell_headless_horseman_sprouting : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* pumpkin = GetHitUnit();
        if (pumpkin->IsAIEnabled())
            pumpkin->GetAI()->DoAction(ACTION_PUMPKIN_SPROUTING_FINISHED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_headless_horseman_sprouting::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 42821 - Headless Horseman - Wisp Flight Missile
// 42818 - Headless Horseman - Wisp Flight Port
class spell_headless_horseman_wisp_teleport : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EarthBunnySpawnPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_headless_horseman_wisp_teleport::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

void AddSC_boss_headless_horseman()
{
    RegisterScarletMonasteryCreatureAI(boss_headless_horseman);
    RegisterScarletMonasteryCreatureAI(npc_headless_horseman_head);
    RegisterScarletMonasteryCreatureAI(npc_pulsing_pumpkin);
    RegisterScarletMonasteryCreatureAI(npc_flame_bunny);
    RegisterScarletMonasteryCreatureAI(npc_sir_thomas);
    RegisterScarletMonasteryGameObjectAI(go_loosely_turned_soil);
    RegisterScarletMonasteryGameObjectAI(go_headless_horseman_pumpkin);
    RegisterSpellScript(spell_headless_horseman_yell_timer);
    RegisterSpellScript(spell_headless_horseman_maniacal_laugh);
    RegisterSpellScript(spell_headless_horseman_head_reposition);
    RegisterSpellScript(spell_headless_horseman_send_head);
    RegisterSpellScript(spell_headless_horseman_head_periodic);
    RegisterSpellScript(spell_headless_horseman_command_head_request_body);
    RegisterSpellScript(spell_headless_horseman_return_head);
    RegisterSpellScript(spell_summon_pumpkin_burst_delay);
    RegisterSpellScript(spell_headless_horseman_head_is_dead);
    RegisterSpellScript(spell_headless_horseman_summoning_rhyme_aura);
    RegisterSpellScript(spell_headless_horseman_sprouting);
    RegisterSpellScript(spell_headless_horseman_wisp_teleport);
}
