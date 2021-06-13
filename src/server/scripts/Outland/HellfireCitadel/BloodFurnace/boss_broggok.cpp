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
#include "blood_furnace.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Yells
{
    SAY_AGGRO                   = 0
};

enum Spells
{
    SPELL_SLIME_SPRAY             = 30913,
    SPELL_POISON_CLOUD            = 30916,
    SPELL_POISON_BOLT             = 30917,
    SPELL_POISON_CLOUD_PASSIVE    = 30914,
    SPELL_SUMMON_INCOMBAT_TRIGGER = 26837,

    // Prisioners
    SPELL_STOMP                   = 31900,
    SPELL_CONCUSSION_BLOW         = 22427,
    SPELL_FRENZY                  = 8269,
    SPELL_CHARGE                  = 22120
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

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
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
                else if (summoned->GetEntry() == NPC_INCOMBAT_TRIGGER)
                {
                    summoned->SetReactState(REACT_PASSIVE);
                    DoZoneInCombat(summoned);
                    summons.Summon(summoned);
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SLIME_SPRAY:
                        DoCastVictim(SPELL_SLIME_SPRAY);
                        events.ScheduleEvent(EVENT_SLIME_SPRAY, 4s, 12s);
                        break;
                    case EVENT_POISON_BOLT:
                        DoCastVictim(SPELL_POISON_BOLT);
                        events.ScheduleEvent(EVENT_POISON_BOLT, 4s, 12s);
                        break;
                    case EVENT_POISON_CLOUD:
                        DoCast(me, SPELL_POISON_CLOUD);
                        events.ScheduleEvent(EVENT_POISON_CLOUD, 20s);
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
                        DoCastSelf(SPELL_SUMMON_INCOMBAT_TRIGGER);
                        break;
                    case ACTION_ACTIVATE_BROGGOK:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoZoneInCombat();
                        events.ScheduleEvent(EVENT_SLIME_SPRAY, 10s);
                        events.ScheduleEvent(EVENT_POISON_BOLT, 7s);
                        events.ScheduleEvent(EVENT_POISON_CLOUD, 5s);
                        break;
                    case ACTION_RESET_BROGGOK:
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        summons.DespawnAll();
                        instance->SetBossState(DATA_BROGGOK, NOT_STARTED);
                        if (GameObject * lever = instance->GetGameObject(DATA_BROGGOK_LEVER))
                        {
                            lever->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE | GO_FLAG_IN_USE);
                            lever->SetGoState(GO_STATE_READY);
                        }
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBloodFurnaceAI<boss_broggokAI>(creature);
        }
};

static Emote const PrisionersEmotes[] =
{
    EMOTE_ONESHOT_ROAR,
    EMOTE_ONESHOT_SHOUT,
    EMOTE_ONESHOT_BATTLE_ROAR
};

struct BroggokPrisionersAI : public ScriptedAI
{
    BroggokPrisionersAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        scheduler.CancelAll();
        scheduler.Schedule(1s, 5s, [this](TaskContext emote)
        {
            me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(PrisionersEmotes));
            emote.Repeat(6s, 9s);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        scheduler.CancelAll();
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustReachedHome() override
    {
        if (instance->GetBossState(DATA_BROGGOK) == IN_PROGRESS)
        {
            if (Creature* broggok = instance->GetCreature(DATA_BROGGOK))
                broggok->AI()->DoAction(ACTION_RESET_BROGGOK);
        }

        ScriptedAI::JustReachedHome();
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

protected:
    InstanceScript* instance;
    TaskScheduler scheduler;
};

struct npc_nascent_fel_orc : public BroggokPrisionersAI
{
    npc_nascent_fel_orc(Creature* creature) : BroggokPrisionersAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler.Schedule(15s, [this](TaskContext concussionBlow)
        {
            DoCastVictim(SPELL_CONCUSSION_BLOW);
            concussionBlow.Repeat(8s, 11s);
        }).Schedule(7s, [this](TaskContext stomp)
        {
            DoCastVictim(SPELL_STOMP);
            stomp.Repeat(16s, 21s);
        });
    }

};

struct npc_fel_orc_neophyte : public BroggokPrisionersAI
{
    npc_fel_orc_neophyte(Creature* creature) : BroggokPrisionersAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler.Schedule(5s, [this](TaskContext charge)
        {
            DoCastVictim(SPELL_CHARGE);
            charge.Repeat(20s);
        }).Schedule(1s, [this](TaskContext frenzy)
        {
            DoCastSelf(SPELL_FRENZY);
            frenzy.Repeat(12s, 13s);
        });
    }

};

class go_broggok_lever : public GameObjectScript
{
    public:
        go_broggok_lever() : GameObjectScript("go_broggok_lever") { }

        struct go_broggok_leverAI : public GameObjectAI
        {
            go_broggok_leverAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* /*player*/) override
            {
                if (instance->GetBossState(DATA_BROGGOK) != DONE && instance->GetBossState(DATA_BROGGOK) != IN_PROGRESS)
                {
                    instance->SetBossState(DATA_BROGGOK, IN_PROGRESS);
                    if (Creature* broggok = instance->GetCreature(DATA_BROGGOK))
                        broggok->AI()->DoAction(ACTION_PREPARE_BROGGOK);
                }

                me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE | GO_FLAG_IN_USE);
                me->SetGoState(GO_STATE_ACTIVE);

                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetBloodFurnaceAI<go_broggok_leverAI>(go);
        }
};

// 30914, 38462 - Poison
class spell_broggok_poison_cloud : public SpellScriptLoader
{
    public:
        spell_broggok_poison_cloud() : SpellScriptLoader("spell_broggok_poison_cloud") { }

        class spell_broggok_poison_cloud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_broggok_poison_cloud_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (!aurEff->GetTotalTicks())
                    return;

                uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                int32 mod = int32(((float(aurEff->GetTickNumber()) / aurEff->GetTotalTicks()) * 0.9f + 0.1f) * 10000 * 2 / 3);
                GetTarget()->CastSpell(nullptr, triggerSpell, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_RADIUS_MOD, mod));
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
    RegisterBloodFurnaceCreatureAI(npc_nascent_fel_orc);
    RegisterBloodFurnaceCreatureAI(npc_fel_orc_neophyte);
    new go_broggok_lever();
    new spell_broggok_poison_cloud();
}
