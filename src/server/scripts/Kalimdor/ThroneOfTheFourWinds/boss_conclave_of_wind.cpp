/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "throne_of_the_four_winds.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Player.h"

enum Spells
{
    // Conclave of Wind
    SPELL_WINDS_PRE_EFFECT_WARNING  = 96508,
    SPELL_POWER_DRAIN               = 89840,

    // Anshal
    SPELL_PRE_FIGHT_VISUAL_WEST     = 85537,
    SPELL_WITHERING_WINDS           = 85576,
    SPELL_WITHERING_WINDS_DAMAGE    = 93168,
    SPELL_NURTURE                   = 85422,
    SPELL_SOOTHING_BREEZE           = 86205,
    SPELL_ZEPHYR                    = 84638,

    // Nezir
    SPELL_PRE_FIGHT_VISUAL_NORTH    = 85532,
    SPELL_CHILLING_WINDS            = 85578,
    SPELL_CHILLING_WINDS_DAMAGE     = 93163,

    // Rohash
    SPELL_PRE_FIGHT_VISUAL_EAST     = 85538,
    SPELL_DEAFENING_WINDS           = 85573,
    SPELL_DEAFENING_WINDS_DAMAGE    = 93166,

    SPELL_SLICING_GALE              = 86182,

    // World Trigger
    SPELL_POWER_GAIN                = 89898
};

enum Events
{
    EVENT_PRE_WIND_EFFECT_WARNING = 1,
    EVENT_CHECK_VICTIM_DISTANCE,

};

enum Actions
{
    ACTION_NO_NEARBY_PLAYER     = 1,
    ACTION_PLAYER_LEFT_PLATFORM = 2,
};

enum Texts
{
    // Conclave of Wind
    SAY_AGGRO                           = 0,
    SAY_OUT_OF_RANGE                    = 1,
    SAY_GATHER_STRENGTH                 = 2,
    SAY_ANNOUNCE_GATHER_POWER           = 3,
    SAY_SPECIAL_ABILITY                 = 4,
    SAY_SLAY                            = 5,

    // Rohash
    SAY_ANNOUNCE_WIND_BLAST             = 6,

    // World Trigger
    SAY_ANNOUNCE_NEAR_FULL_STRENGHTH    = 0
};

#define MAX_HOME_POSITION_DISTANCE 50.0f

class boss_anshal : public CreatureScript
{
    public:
        boss_anshal() : CreatureScript("boss_anshal") { }

        struct boss_anshalAI : public BossAI
        {
            boss_anshalAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
            {
                Initialize();
            }

            void Initialize()
            {
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith();
                printf("anshal triggered entercombat \n");
                me->SetReactState(REACT_AGGRESSIVE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_WEST);
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(1));

                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                {
                    Talk(SAY_AGGRO);
                    events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
                    events.ScheduleEvent(EVENT_CHECK_VICTIM_DISTANCE, Seconds(1));
                }
            }

            void AttackStart(Unit* who) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                {

                    me->Attack(who, true);
                    me->GetMotionMaster()->MoveChase(who);
                }
            }

            void Reset()
            {
                _Reset();
                Initialize();
                me->SetReactState(REACT_PASSIVE);
                me->SetPower(POWER_MANA, 0);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_NO_NEARBY_PLAYER:
                        if (!me->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_WITHERING_WINDS, me)))
                        {
                            Talk(SAY_OUT_OF_RANGE);
                            DoCastSelf(SPELL_WITHERING_WINDS);
                        }
                        break;
                    case ACTION_PLAYER_LEFT_PLATFORM:
                        events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(2));
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PRE_WIND_EFFECT_WARNING:
                            DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                            events.Repeat(Seconds(3));
                            break;
                        case EVENT_CHECK_VICTIM_DISTANCE:
                            if (Unit* victim = me->GetVictim())
                            {
                                if (victim->GetDistance(me->GetHomePosition()) > MAX_HOME_POSITION_DISTANCE)
                                {
                                    // We think that the victim has gone too far away so we are gonna set his threat to 0 and select a new victim
                                    me->getThreatManager().getCurrentVictim()->setThreat(0.0f);
                                    if (Unit* target = me->SelectNearestTarget(40.0f))
                                        me->AI()->AttackStart(target);
                                    else
                                    {
                                        me->AttackStop();
                                        me->SetReactState(REACT_PASSIVE);
                                    }
                                }
                            }
                            events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetThroneOfTheFourWindsAI<boss_anshalAI>(creature);
        }
};

class boss_nezir : public CreatureScript
{
    public:
        boss_nezir() : CreatureScript("boss_nezir") { }

        struct boss_nezirAI : public BossAI
        {
            boss_nezirAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
            {
                Initialize();
            }

            void Initialize()
            {
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith();
                printf("nezir triggered entercombat \n");
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_NORTH);
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(1));

                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                {
                    Talk(SAY_AGGRO);
                    events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
                    events.ScheduleEvent(EVENT_CHECK_VICTIM_DISTANCE, Seconds(1));
                }
            }

            void AttackStart(Unit* who) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                {
                    me->Attack(who, true);
                    me->GetMotionMaster()->MoveChase(who);
                }
            }

            void Reset()
            {
                _Reset();
                Initialize();
                me->SetReactState(REACT_PASSIVE);
                me->SetPower(POWER_MANA, 0);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_NO_NEARBY_PLAYER:
                        if (!me->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_CHILLING_WINDS, me)))
                        {
                            Talk(SAY_OUT_OF_RANGE);
                            DoCastSelf(SPELL_CHILLING_WINDS);
                        }
                        break;
                    case ACTION_PLAYER_LEFT_PLATFORM:
                        events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(2));
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PRE_WIND_EFFECT_WARNING:
                            DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                            events.Repeat(Seconds(3));
                            break;
                        case EVENT_CHECK_VICTIM_DISTANCE:
                            if (Unit* victim = me->GetVictim())
                            {
                                if (victim->GetDistance(me->GetHomePosition()) > MAX_HOME_POSITION_DISTANCE)
                                {
                                    // We think that the victim has gone too far away so we are gonna set his threat to 0 and select a new victim
                                    me->getThreatManager().getCurrentVictim()->setThreat(0.0f);
                                    if (Unit* target = me->SelectNearestTarget(40.0f))
                                        me->AI()->AttackStart(target);
                                    else
                                    {
                                        me->AttackStop();
                                        me->SetReactState(REACT_PASSIVE);
                                    }
                                }
                            }
                            events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetThroneOfTheFourWindsAI<boss_nezirAI>(creature);
        }
};

class boss_rohash : public CreatureScript
{
    public:
        boss_rohash() : CreatureScript("boss_rohash") { }

        struct boss_rohashAI : public BossAI
        {
            boss_rohashAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
            {
                Initialize();
            }

            void Initialize()
            {
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith();
                printf("rohash triggered entercombat \n");
                me->SetReactState(REACT_AGGRESSIVE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_EAST);
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(1));

                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                {
                    Talk(SAY_AGGRO);
                    events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
                    events.ScheduleEvent(EVENT_CHECK_VICTIM_DISTANCE, Seconds(1));
                }
            }

            void AttackStart(Unit* who) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                if (who->GetDistance(me->GetHomePosition()) < MAX_HOME_POSITION_DISTANCE)
                    me->Attack(who, false);
            }

            void Reset()
            {
                _Reset();
                Initialize();
                me->SetReactState(REACT_PASSIVE);
                me->SetPower(POWER_MANA, 0);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_NO_NEARBY_PLAYER:
                        if (!me->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_DEAFENING_WINDS, me)))
                        {
                            Talk(SAY_OUT_OF_RANGE);
                            DoCastSelf(SPELL_DEAFENING_WINDS);
                        }
                        break;
                    case ACTION_PLAYER_LEFT_PLATFORM:
                        events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, Seconds(2));
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PRE_WIND_EFFECT_WARNING:
                            DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                            events.Repeat(Seconds(3));
                            break;
                        case EVENT_CHECK_VICTIM_DISTANCE:
                            if (Unit* victim = me->GetVictim())
                            {
                                if (victim->GetDistance(me->GetHomePosition()) > MAX_HOME_POSITION_DISTANCE)
                                {
                                    // We think that the victim has gone too far away so we are gonna set his threat to 0 and select a new victim
                                    me->getThreatManager().getCurrentVictim()->setThreat(0.0f);
                                    if (Unit* target = me->SelectNearestTarget(40.0f))
                                        me->AI()->AttackStart(target);
                                    else
                                    {
                                        me->AttackStop();
                                        me->SetReactState(REACT_PASSIVE);
                                    }
                                }
                            }
                            events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
                DoSpellAttackIfReady(SPELL_SLICING_GALE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetThroneOfTheFourWindsAI<boss_rohashAI>(creature);
        }
};

class spell_conclave_of_wind_winds_pre_effect_warning: public SpellScriptLoader
{
    public:
        spell_conclave_of_wind_winds_pre_effect_warning() : SpellScriptLoader("spell_conclave_of_wind_winds_pre_effect_warning") { }

        class spell_conclave_of_wind_winds_pre_effect_warning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_conclave_of_wind_winds_pre_effect_warning_AuraScript);

            void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Unit* caster = GetCaster())
                        if (Creature* conclave = caster->ToCreature())
                            if (conclave->IsAIEnabled)
                                conclave->AI()->DoAction(ACTION_NO_NEARBY_PLAYER);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_conclave_of_wind_winds_pre_effect_warning_AuraScript::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_conclave_of_wind_winds_pre_effect_warning_AuraScript();
        }
};

void AddSC_boss_conclave_of_wind()
{
    new boss_anshal();
    new boss_nezir();
    new boss_rohash();

    new spell_conclave_of_wind_winds_pre_effect_warning();
}
