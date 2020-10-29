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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"

enum Says
{
    // Scarlet Commander Mograine
    SAY_MO_AGGRO                 = 0,
    SAY_MO_KILL                  = 1,
    SAY_MO_RESURRECTED           = 2,

    // High Inquisitor Whitemane
    SAY_WH_INTRO                 = 0,
    SAY_WH_KILL                  = 1,
    SAY_WH_RESURRECT             = 2
};

enum Spells
{
    // Scarlet Commander Mograine
    SPELL_CRUSADER_STRIKE       = 14518,
    SPELL_HAMMER_OF_JUSTICE     = 77787,
    SPELL_DIVINE_SHIELD         = 63148,
    SPELL_LAY_ON_HANDS          = 9257,
    SPELL_RETRIBUTION_AURA      = 8990,

    // High Inquisitor Whitemane
    SPELL_HOLY_SMITE            = 25054,
    SPELL_DEEP_SLEEP            = 9256,
    SPELL_SCARLET_RESURRECTION  = 9232,
    SPELL_HEAL                  = 12039,
    SPELL_POWER_WORD_SHIELD     = 22187
};

enum Events
{
    // Scarlet Commander Mograine
    EVENT_RESURRECTED = 1,
    EVENT_HAMMER_OF_JUSTICE,
    EVENT_CRUSADER_STRIKE,
    EVENT_DIVINE_SHIELD,
    EVENT_RETRIBUTION_AURA,

    // High Inquisitor Whitemane
    EVENT_HOLY_SMITE,
    EVENT_DEEP_SLEEP,
    EVENT_SCARLET_RESURRECTION,
    EVENT_SALUTE_EMOTE,
    EVENT_REENGAGE_PLAYERS,
    EVENT_HEAL,
    EVENT_POWER_WORD_SHIELD
};

enum Actions
{
    ACTION_MOGRAINE_DIED = 1,
    ACTION_RESURRECTED
};

enum Points
{
    POINT_NONE = 0,
    POINT_RESURRECT_MOGRAINE
};

enum Misc
{
    SOUND_ID_MOGRAINE_DEATH = 1326
};

Position const WhitemaneIntroPosition = { 1150.1221f, 1397.4794f, 32.337616f };

struct npc_scarlet_commander_mograine : public ScriptedAI
{
    npc_scarlet_commander_mograine(Creature* creature) : ScriptedAI(creature), _resurrected(false), _killed(false) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_RETRIBUTION_AURA);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_MO_AGGRO);
        _instance->SetBossState(DATA_MOGRAINE_AND_WHITEMANE, IN_PROGRESS);
        me->CallForHelp(VISIBLE_RANGE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        // The Instance Script will take care of the reset
        _instance->SetBossState(DATA_MOGRAINE_AND_WHITEMANE, FAIL);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_MO_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        if (Creature* whitemane = _instance->GetCreature(DATA_HIGH_INQUISITOR_WHITEMANE))
            if (whitemane->isDead())
                _instance->SetBossState(DATA_MOGRAINE_AND_WHITEMANE, DONE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Mograine cannot die when he has not been resurrected yet.
        if (!_resurrected && damage >= me->GetHealth())
            damage = me->GetHealth() - 1;

        if (!_killed && !_resurrected && me->HealthBelowPctDamaged(1, damage))
        {
            _killed = true;
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->PlayDistanceSound(SOUND_ID_MOGRAINE_DEATH);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetImmuneToPC(true, true);
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            me->RemoveAllAuras();

            if (Creature* whitemane = _instance->GetCreature(DATA_HIGH_INQUISITOR_WHITEMANE))
                if (whitemane->IsAIEnabled)
                    whitemane->AI()->DoAction(ACTION_MOGRAINE_DIED);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RESURRECTED:
                _events.ScheduleEvent(EVENT_RESURRECTED, 3s + 500ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_killed && !UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RESURRECTED:
                    Talk(SAY_MO_RESURRECTED);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetImmuneToPC(false, true);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_LAY_ON_HANDS);
                    _resurrected = true;
                    _killed = false;

                    _events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 6s);
                    _events.ScheduleEvent(EVENT_RETRIBUTION_AURA, 7s);
                    _events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 20s);
                    _events.ScheduleEvent(EVENT_DIVINE_SHIELD, 29s);
                    break;
                case EVENT_HAMMER_OF_JUSTICE:
                    DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                    _events.Repeat(8s, 10s);
                    break;
                case EVENT_CRUSADER_STRIKE:
                    DoCastVictim(SPELL_CRUSADER_STRIKE);
                    _events.Repeat(6s);
                    break;
                case EVENT_DIVINE_SHIELD:
                    DoCastSelf(SPELL_DIVINE_SHIELD);
                    // @todo: repeat timer
                    break;
                case EVENT_RETRIBUTION_AURA:
                    DoCastSelf(SPELL_RETRIBUTION_AURA);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* _instance;
    EventMap _events;
    bool _resurrected;
    bool _killed;
};

struct npc_high_inquisitor_whitemane : public ScriptedAI
{
    npc_high_inquisitor_whitemane(Creature* creature) : ScriptedAI(creature), _below50PctHealth(false), _resurrectedMograine(false){ }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        _instance = me->GetInstanceScript();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_HOLY_SMITE, 1ms);
        _events.ScheduleEvent(EVENT_HEAL, 12s);
        _events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 22s); // @todo: validate timer
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_WH_KILL);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        // The Instance Script will take care of the reset
        _instance->SetBossState(DATA_MOGRAINE_AND_WHITEMANE, FAIL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* mograine = _instance->GetCreature(DATA_SCARLET_COMMANDER_MOGRAINE))
            if (mograine->isDead())
                _instance->SetBossState(DATA_MOGRAINE_AND_WHITEMANE, DONE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Do not allow Whitemane to die before she has resurrected Mograine.
        // This bug can actually happen on retail but for the sake of it, we wont allow it to happen.
        if (!_resurrectedMograine && damage >= me->GetHealth())
            damage = me->GetHealth() - 1;

        if (!_below50PctHealth && me->HealthBelowPctDamaged(50, damage))
        {
            _below50PctHealth = true;
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            _events.Reset();
            _events.ScheduleEvent(EVENT_DEEP_SLEEP, 1ms);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_MOGRAINE_DIED:
                Talk(SAY_WH_INTRO);
                if (GameObject* door = _instance->GetGameObject(DATA_HIGH_INQUISITORS_DOOR))
                    door->UseDoorOrButton();
                me->GetMotionMaster()->MovePoint(POINT_NONE, WhitemaneIntroPosition);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_RESURRECT_MOGRAINE:
                _events.ScheduleEvent(EVENT_SCARLET_RESURRECTION, 3s);
                break;
            default:
                break;
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (spell->Id == SPELL_SCARLET_RESURRECTION && reason == SPELL_FINISHED_SUCCESSFUL_CAST)
        {
            Talk(SAY_WH_RESURRECT);
            _resurrectedMograine = true;
            _events.ScheduleEvent(EVENT_SALUTE_EMOTE, 1s);
            _events.ScheduleEvent(EVENT_REENGAGE_PLAYERS, 5s);

            if (Creature* mograine = _instance->GetCreature(DATA_SCARLET_COMMANDER_MOGRAINE))
                if (mograine->IsAIEnabled)
                    mograine->AI()->DoAction(ACTION_RESURRECTED);
        }
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
                case EVENT_HOLY_SMITE:
                    DoCastVictim(SPELL_HOLY_SMITE);
                    _events.Repeat(5s, 7s);
                    break;
                case EVENT_DEEP_SLEEP:
                    DoCastAOE(SPELL_DEEP_SLEEP);
                    if (Creature* mograine = _instance->GetCreature(DATA_SCARLET_COMMANDER_MOGRAINE))
                    {
                        Position pos = mograine->GetPosition();
                        mograine->MovePositionToFirstCollision(pos, 2.f, mograine->GetRelativeAngle(me));
                        me->GetMotionMaster()->MovePoint(POINT_RESURRECT_MOGRAINE, pos);
                    }
                    break;
                case EVENT_SCARLET_RESURRECTION:
                    DoCastAOE(SPELL_SCARLET_RESURRECTION);
                    break;
                case EVENT_SALUTE_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    break;
                case EVENT_REENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    _events.ScheduleEvent(EVENT_HOLY_SMITE, 1ms);
                    _events.ScheduleEvent(EVENT_HEAL, 12s);
                    _events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 22s);
                    break;
                case EVENT_HEAL:
                {
                    // @todo: This logic has been ported from CMangos since there is very little sniff information about conditions and repeat timers
                    Unit* target = nullptr;
                    if (me->GetHealthPct() < 75.f)
                        target = me;
                    else if (Creature* mograine = _instance->GetCreature(DATA_SCARLET_COMMANDER_MOGRAINE))
                        if (mograine->GetHealthPct() < 75.f)
                            target = mograine;

                    if (target)
                    {
                        DoCast(target, SPELL_HEAL);
                        _events.Repeat(13s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                }
                case EVENT_POWER_WORD_SHIELD:
                    DoCastSelf(SPELL_POWER_WORD_SHIELD);
                    _events.Repeat(22s, 45s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* _instance;
    EventMap _events;
    bool _below50PctHealth;
    bool _resurrectedMograine;
};


void AddSC_boss_mograine_and_whitemane()
{
    RegisterScarletMonasteryCreatureAI(npc_scarlet_commander_mograine);
    RegisterScarletMonasteryCreatureAI(npc_high_inquisitor_whitemane);
}
