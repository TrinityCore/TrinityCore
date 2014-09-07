/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "blood_furnace.h"

enum Yells
{
    SAY_AGGRO                   = 0
};

enum Spells
{
    SPELL_SLIME_SPRAY           = 30913,
    SPELL_POISON_CLOUD          = 30916,
    SPELL_POISON_BOLT           = 30917,

    SPELL_POISON_CLOUD_PASSIVE  = 30914
};

enum Events
{
    EVENT_SLIME_SPRAY = 1,
    EVENT_POISON_BOLT,
    EVENT_POISON_CLOUD,
};

class boss_broggok : public CreatureScript
{
    public:
        boss_broggok() : CreatureScript("boss_broggok") { }

        struct boss_broggokAI : public BossAI
        {
            boss_broggokAI(Creature* creature) : BossAI(creature, DATA_BROGGOK) { }

            void Reset() override
            {
                _Reset();
                DoAction(ACTION_RESET_BROGGOK);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned) override
            {
                if (summoned->GetEntry() == NPC_BROGGOK_POISON_CLOUD)
                {
                    summoned->SetReactState(REACT_PASSIVE);
                    summoned->CastSpell(summoned, SPELL_POISON_CLOUD_PASSIVE, true);
                    summons.Summon(summoned);
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SLIME_SPRAY:
                        DoCastVictim(SPELL_SLIME_SPRAY);
                        events.ScheduleEvent(EVENT_SLIME_SPRAY, urand(4000, 12000));
                        break;
                    case EVENT_POISON_BOLT:
                        DoCastVictim(SPELL_POISON_BOLT);
                        events.ScheduleEvent(EVENT_POISON_BOLT, urand(4000, 12000));
                        break;
                    case EVENT_POISON_CLOUD:
                        DoCast(me, SPELL_POISON_CLOUD);
                        events.ScheduleEvent(EVENT_POISON_CLOUD, 20000);
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_PREPARE_BROGGOK:
                        me->SetInCombatWithZone();
                        break;
                    case ACTION_ACTIVATE_BROGGOK:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE);
                        events.ScheduleEvent(EVENT_SLIME_SPRAY, 10000);
                        events.ScheduleEvent(EVENT_POISON_BOLT, 7000);
                        events.ScheduleEvent(EVENT_POISON_CLOUD, 5000);
                        break;
                    case ACTION_RESET_BROGGOK:
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE);
                        break;
                }
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBloodFurnaceAI<boss_broggokAI>(creature);
        }
};

class go_broggok_lever : public GameObjectScript
{
    public:
        go_broggok_lever() : GameObjectScript("go_broggok_lever") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) override
        {
            if (InstanceScript* instance = go->GetInstanceScript())
                if (instance->GetBossState(DATA_BROGGOK) != DONE && instance->GetBossState(DATA_BROGGOK) != IN_PROGRESS)
                {
                    instance->SetBossState(DATA_BROGGOK, IN_PROGRESS);
                    if (Creature* broggok = ObjectAccessor::GetCreature(*go, instance->GetData64(DATA_BROGGOK)))
                        broggok->AI()->DoAction(ACTION_PREPARE_BROGGOK);
                }

            go->UseDoorOrButton();
            return false;
        }
};

// 30914, 38462 - Poison (Broggok)
class spell_broggok_poison_cloud : public SpellScriptLoader
{
    public:
        spell_broggok_poison_cloud() : SpellScriptLoader("spell_broggok_poison_cloud") { }

        class spell_broggok_poison_cloud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_broggok_poison_cloud_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].TriggerSpell))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                int32 mod = int32(((float(aurEff->GetTickNumber()) / aurEff->GetTotalTicks()) * 0.9f + 0.1f) * 10000 * 2 / 3);
                GetTarget()->CastCustomSpell(triggerSpell, SPELLVALUE_RADIUS_MOD, mod, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_broggok_poison_cloud_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_broggok_poison_cloud_AuraScript();
        }
};

void AddSC_boss_broggok()
{
    new boss_broggok();
    new go_broggok_lever();
    new spell_broggok_poison_cloud();
}
