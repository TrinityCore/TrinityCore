/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
 * */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "bastion_of_twilight.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum spell_c
{
    // Chogall
    SPELL_CORRUPTED_BLOOD                 = 93103,
    SPELL_CORRUPTION_ACCELERATED          = 81836,
    SPELL_CORRUPTION_SICKNESS             = 93202,
    SPELL_CORRUPTION_MALFORMATION         = 82125,
    SPELL_CORRUPTION_ABSOLUTE             = 82170,

    SPELL_FURY_CHOGALL                    = 82524,

    // P1
    SPELL_SUMMON_CORRUPTING_ADHERENT      = 81628,
    SPELL_CONVERSION                      = 91303,
    SPELL_WORSHIPPING                     = 91317,
    SPELL_TWISTED_DEVOTION                = 91331,
    SPELL_FLAME_ORDER                     = 81171,
    SPELL_FLAMING_DESTRUCTION             = 81194,
    SPELL_SHADOW_ORDER                    = 81556,
    SPELL_EMPOWERED_SHADOW                = 81572,
    SPELL_BLAZE_AURA                      = 81536,

    // P2 - 25% PV
    SPELL_DARKENED_CREATIONS              = 82433,
    SPELL_CORRUPTION_OF_THE_OLD_GOD       = 82361,

    // Trashs
    SPELL_CORRUPTING_CRASH                = 81685,
    SPELL_DEPRAVITY                       = 81713,
    SPELL_FESTERING_BLOOD                 = 82914,
    SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD    = 81757,
    SPELL_BRASIER_DAMAGE                  = 93212,
    SPELL_BRASIER_AURA                    = 93484,
    SPELL_PORTAL_SHADOW_VISUAL            = 49666,
    SPELL_PORTAL_SHADOW_VISUAL_RAYON      = 70685,
    SPELL_DEBILITING_BEAM                 = 82411,

    // Trash HM
    SPELL_SHADOW_SHELL                    = 93311,
    SPELL_SHADOW_POWER                    = 93301,
    SPELL_FIRE_SHELL                      = 93276,
    SPELL_FIRE_POWER                      = 93245,
};

enum Nums
{
    NPC_BLOOD_OF_THE_OLD_GOD              = 43707,
    NPC_SPILLED_BLOOD                     = 341781,
    NPC_BLAZE                             = 43585,
    NPC_CORRUPTING_ADHERENT               = 43622,
    NPC_DARKENED_CREATION                 = 44045,
    NPC_SHADOW_LORD                       = 43592,
    NPC_FIRE_LORD                         = 43406,
    NPC_SPIKED_TENTACLE                   = 50264,
    GO_CHOGALL_FLOOR                      = 205898,
};

enum events
{
    EVENT_CONVERSION = 1,
    EVENT_FURY_OF_CHOGALL,
    EVENT_FLAME_ORDERS,
    EVENT_SHADOW_ORDERS,
    EVENT_CORRUPTING_ADHERENT,
    EVENT_SUMMON_CORRUPTING_ADHERENT,
    EVENT_FESTER_BLOOD,
    EVENT_DARKENED_CREATIONS,
};

/**************
** BOSS Chogall
***************/

class boss_chogall : public CreatureScript
{
public:
    boss_chogall() : CreatureScript("boss_chogall") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_chogallAI(creature);
    }

    struct boss_chogallAI : public BossAI
    {
        boss_chogallAI(Creature* creature) : BossAI(creature, DATA_CHOGALL)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint8 phase;

        void ResetCharmedPlayers()
        {
            if (me->GetMap() && !me->GetMap()->GetPlayers().isEmpty())
            {
                for (Map::PlayerList::const_iterator i = me->GetMap()->GetPlayers().begin(); i != me->GetMap()->GetPlayers().end(); ++i)
                {
                    if (i->GetSource() && i->GetSource()->IsCharmed())
                        i->GetSource()->RemoveCharmedBy(me->ToUnit());
                }
            }
        }

        void DamageTaken(Unit* /*who*/, uint32& /*damage*/) override
        {
            if (me->GetHealthPct() <= 25.0f && phase == 0)
            {
                phase = 1;
                me->CastSpell(me, SPELL_CORRUPTION_OF_THE_OLD_GOD, false);
                me->AddAura(82356, me);
                events.CancelEvent(EVENT_CORRUPTING_ADHERENT);
                events.CancelEvent(EVENT_SUMMON_CORRUPTING_ADHERENT);
                events.ScheduleEvent(EVENT_DARKENED_CREATIONS, urand(8000, 12000));
            }
        }

        void Reset() override
        {
            events.Reset();

            phase = 0;

            summons.DespawnAll();

            instance->SetData(DATA_CHOGALL_EVENT, NOT_STARTED);

            std::list<Creature*> unitList;
            me->GetCreatureListWithEntryInGrid(unitList, 50264, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                (*itr)->DisappearAndDie();

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_BLOOD);
            instance->DoRemoveAurasDueToSpellOnPlayers(93318);
            instance->DoRemoveAurasDueToSpellOnPlayers(82170);
            instance->DoRemoveAurasDueToSpellOnPlayers(82193);

            ResetCharmedPlayers();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            DoZoneInCombat(me);

            phase = 0;

            // Corrupted Blood on all
            me->CastSpell(me, SPELL_CORRUPTED_BLOOD, true);

            // Events
            events.ScheduleEvent(EVENT_CONVERSION, 10000);
            events.ScheduleEvent(EVENT_FURY_OF_CHOGALL, urand(45000, 50000));
            events.ScheduleEvent(EVENT_FLAME_ORDERS, urand(7000, 10000));
            events.ScheduleEvent(EVENT_CORRUPTING_ADHERENT, 60000);
            instance->SetData(DATA_CHOGALL_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            DoZoneInCombat(summon);
            switch (summon->GetEntry())
            {
                case NPC_CORRUPTING_ADHERENT:
                case NPC_DARKENED_CREATION:
                    summon->AI()->AttackStart(me->GetVictim());
                    break;
                case NPC_BLAZE:
                    summon->AddAura(SPELL_BLAZE_AURA, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summon->Attack(me->GetVictim(), true);
                    summon->AttackStop();
                    summon->StopMoving();
                    break;
                case NPC_SPILLED_BLOOD:
                    summon->AddAura(SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD, summon);
                    summon->AI()->DoAction(100);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summon->Attack(me->GetVictim(), true);
                    summon->AttackStop();
                    summon->StopMoving();
                    break;

            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CONVERSION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            if (target->GetGUID() != me->GetVictim()->GetGUID())
                            {
                                target->SetCharmedBy(me, CHARM_TYPE_CONVERT);
                                target->CastSpell(me, SPELL_WORSHIPPING, true);
                            }
                            else
                            {
                                events.ScheduleEvent(EVENT_CONVERSION, 1000);
                                break;
                            }
                        }
                        events.ScheduleEvent(EVENT_CONVERSION, 21000);
                        break;
                    case EVENT_FURY_OF_CHOGALL:
                        me->CastSpell(me->GetVictim(), SPELL_FURY_CHOGALL, false);
                        events.ScheduleEvent(EVENT_FURY_OF_CHOGALL, urand(45000, 50000));
                        break;
                    case EVENT_FLAME_ORDERS:
                        me->AddAura(SPELL_FLAMING_DESTRUCTION, me);
                        events.ScheduleEvent(EVENT_SHADOW_ORDERS, urand(20000, 25000));
                        break;
                    case EVENT_SHADOW_ORDERS:
                        me->AddAura(SPELL_EMPOWERED_SHADOW, me);
                        events.ScheduleEvent(EVENT_FLAME_ORDERS, urand(20000, 25000));
                        break;
                    case EVENT_CORRUPTING_ADHERENT:
                        me->CastSpell(me, SPELL_SUMMON_CORRUPTING_ADHERENT, false);
                        events.ScheduleEvent(EVENT_SUMMON_CORRUPTING_ADHERENT, 1600);
                        events.ScheduleEvent(EVENT_FESTER_BLOOD, 40000);
                        break;
                    case EVENT_SUMMON_CORRUPTING_ADHERENT:
                    {
                        if (RAID_MODE(false, true, false, true))
                        {
                            if (GameObject* portal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL_1, 500.0f))
                            {
                                portal->SetGoState(GO_STATE_ACTIVE);
                                me->CastSpell(portal->GetPosition(), 81611, false);
                            }

                            if (GameObject* portal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL_2, 500.0f))
                            {
                                portal->SetGoState(GO_STATE_ACTIVE);
                                me->CastSpell(portal->GetPosition(), 81618, false);
                            }
                        }
                        else
                        {
                            uint8 portalNumber = urand(0, 1);
                            if (GameObject* portal = me->FindNearestGameObject(portalNumber == 1 ? GO_TWILIGHT_PORTAL_1 : GO_TWILIGHT_PORTAL_2, 500.0f))
                            {
                                portal->SetGoState(GO_STATE_ACTIVE);
                                me->CastSpell(portal->GetPosition(), portalNumber == 1 ? 81611: 81618, false);
                            }
                        }
                        events.ScheduleEvent(EVENT_CORRUPTING_ADHERENT, 90000);
                        break;
                    }
                    case EVENT_FESTER_BLOOD:
                    {
                        std::list<Creature*> unitList;
                        me->GetCreatureListWithEntryInGrid(unitList, NPC_CORRUPTING_ADHERENT, 100.0f);
                        for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                        {
                            if ((*itr)->isDead())
                                me->SummonCreature(NPC_SPILLED_BLOOD, (*itr)->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0);
                            else
                                (*itr)->AddAura(SPELL_FESTERING_BLOOD, (*itr));
                        }
                        break;
                    }
                    case EVENT_DARKENED_CREATIONS:
                        for (uint8 i = 0; i < 4; i++)
                            me->CastSpell(me, 82433, false);

                        events.ScheduleEvent(EVENT_DARKENED_CREATIONS, urand(60000, 70000));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            ResetCharmedPlayers();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_BLOOD);
            instance->DoRemoveAurasDueToSpellOnPlayers(93318);
            instance->DoRemoveAurasDueToSpellOnPlayers(82170);
            instance->DoRemoveAurasDueToSpellOnPlayers(82193);
            instance->SetData(DATA_CHOGALL_EVENT, DONE);

            if (me->GetMap()->IsHeroic())
            {
                if (GameObject* floor = me->FindNearestGameObject(205898, 150.0f))
                    instance->HandleGameObject(floor->GetGUID(), true, floor);
            }
        }
    };
};

enum spilledEvents
{
    EVENT_SUMMON = 1,
    EVENT_DESPAWN,
};

class npc_spilled_blood : public CreatureScript
{
public:
    npc_spilled_blood() : CreatureScript("npc_spilled_blood") { }

    struct npc_spilled_bloodAI : public ScriptedAI
    {
        npc_spilled_bloodAI(Creature* c) : ScriptedAI(c), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case 100:
                    events.ScheduleEvent(EVENT_SUMMON, urand(5000, 8000));
                    events.ScheduleEvent(EVENT_DESPAWN, 45000);
                    break;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void Reset() override
        {
            summons.DespawnAll();
            if (instance)
            {
                if (Creature* chogall = instance->GetCreature(DATA_CHOGALL))
                    DoZoneInCombat(chogall);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUMMON:

                        for (uint8 i = 0; i < 4; i++)
                        {
                            Position pos = me->GetPosition();
                            pos.m_positionX += float(urand(1, 3));
                            pos.m_positionY += float(urand(1, 3));
                            me->SummonCreature(NPC_BLOOD_OF_THE_OLD_GOD, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                        }
                        break;
                    case EVENT_DESPAWN:
                        me->DisappearAndDie();
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spilled_bloodAI(creature);
    }
};

class spell_whorshipping : public SpellScriptLoader
{
    public:
        spell_whorshipping() : SpellScriptLoader("spell_whorshipping") { }

        class spell_whorshipping_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_whorshipping_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    if (owner->IsCharmed() && owner->GetCharmer())
                        owner->RemoveCharmedBy(owner->GetCharmer());
                }
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    if (owner->IsCharmed() && owner->GetCharmer())
                        owner->AddAura(SPELL_TWISTED_DEVOTION, owner->GetCharmer());
                }

                PreventDefaultAction();
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_whorshipping_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_whorshipping_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_whorshipping_AuraScript();
        }
};

void CheckCorruption(Unit* unit)
{
    int32 val = unit->GetPower(POWER_ALTERNATE_POWER);
    uint32 corruptionDone = unit->Variables.GetValue<uint32>("corruptionDone", 0);

    // Check for CA
    if (val >= 25 && val < 50 && corruptionDone == 0)
    {
        corruptionDone++;
        unit->AddAura(81836, unit);
    }

    // Check for CS
    if (val >= 50 && val < 75 && !unit->HasAura(81829))
    {
        unit->AddAura(81829, unit);
    }

    // Check for CS
    if (val >= 75 && val < 100 && corruptionDone == 1)
    {
        corruptionDone++;
        unit->CastSpell(unit, 93318, true);
    }

    // Check for CA
    if (val >= 100 && !unit->HasAura(82170))
    {
        unit->AddAura(82170, unit);
        unit->AddAura(82193, unit);
    }

    unit->Variables.Set("corruptionDone", corruptionDone);
}

class spell_depravity : public SpellScriptLoader
{
    public:
        spell_depravity() : SpellScriptLoader("spell_depravity") { }
        class spell_depravity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_depravity_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 10);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_depravity_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_depravity_SpellScript();
        }
};

class spell_sprayed_corruption : public SpellScriptLoader
{
    public:
        spell_sprayed_corruption() : SpellScriptLoader("spell_sprayed_corruption") { }
        class spell_sprayed_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sprayed_corruption_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 5);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_sprayed_corruption_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sprayed_corruption_SpellScript();
        }
};

class spell_spilled_blood_of_the_old_god : public SpellScriptLoader
{
    public:
        spell_spilled_blood_of_the_old_god() : SpellScriptLoader("spell_spilled_blood_of_the_old_god") { }
        class spell_spilled_blood_of_the_old_god_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spilled_blood_of_the_old_god_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 5);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_spilled_blood_of_the_old_god_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spilled_blood_of_the_old_god_SpellScript();
        }
};

class spell_corrupting_crash : public SpellScriptLoader
{
    public:
        spell_corrupting_crash() : SpellScriptLoader("spell_corrupting_crash") { }
        class spell_corrupting_crash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_corrupting_crash_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 10);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_corrupting_crash_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_corrupting_crash_SpellScript();
        }
};

class spell_corruption_of_the_old_god : public SpellScriptLoader
{
    public:
        spell_corruption_of_the_old_god() : SpellScriptLoader("spell_corruption_of_the_old_god") { }

        class spell_corruption_of_the_old_god_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_corruption_of_the_old_god_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 1);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_corruption_of_the_old_god_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_corruption_of_the_old_god_SpellScript();
        }
};

class spell_corruption_sickness : public SpellScriptLoader
{
    public:
        spell_corruption_sickness() : SpellScriptLoader("spell_corruption_sickness") { }

        class spell_corruption_sickness_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_corruption_sickness_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 5);
                CheckCorruption(GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_corruption_sickness_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_corruption_sickness_SpellScript();
        }
};

class spell_corruption_accelerated : public SpellScriptLoader
{
    public:
        spell_corruption_accelerated() : SpellScriptLoader("spell_corruption_accelerated") { }

        class spell_corruption_accelerated_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_corruption_accelerated_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    owner->SetPower(POWER_ALTERNATE_POWER, owner->GetPower(POWER_ALTERNATE_POWER) + 2);
                    CheckCorruption(owner);
                }

                PreventDefaultAction();
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_corruption_accelerated_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_corruption_accelerated_AuraScript();
        }
};

enum darkenedEvents
{
    EVENT_DEBILITATING_BEAM = 1,
};

class npc_darkened_creation : public CreatureScript
{
    public:
        npc_darkened_creation() : CreatureScript("npc_darkened_creation") { }

        struct npc_darkened_creationAI : public ScriptedAI
        {
            npc_darkened_creationAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                events.ScheduleEvent(EVENT_DEBILITATING_BEAM, urand(3000, 5000));
                DoZoneInCombat(me);
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                AttackStartNoMove(who);
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_DEBILITATING_BEAM:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            me->CastSpell(target, SPELL_DEBILITING_BEAM, false);

                        events.ScheduleEvent(EVENT_DEBILITATING_BEAM, urand(6000, 8000));
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_darkened_creationAI(pCreature);
        }
};


class npc_spiked_tentacle : public CreatureScript
{
    public:
        npc_spiked_tentacle() : CreatureScript("npc_spiked_tentacle") { }

        struct npc_spiked_tentacleAI : public ScriptedAI
        {
            npc_spiked_tentacleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                DoZoneInCombat(me);
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                AttackStartNoMove(who);
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spiked_tentacleAI(pCreature);
        }
};

class spell_debilitating_beam : public SpellScriptLoader {
public:
    spell_debilitating_beam() : SpellScriptLoader("spell_debilitating_beam")
    { }

    class spell_debilitating_beam_AuraScript: public AuraScript
    {
        PrepareAuraScript(spell_debilitating_beam_AuraScript);

        void PeriodicTick(AuraEffect const* /*aurEff*/)
        {
            if (!GetTarget())
                return;

            if (GetTarget()->GetMap() && GetTarget()->GetMap()->IsHeroic())
            {
                GetTarget()->SetPower(POWER_ALTERNATE_POWER, GetTarget()->GetPower(POWER_ALTERNATE_POWER) + 2);
                CheckCorruption(GetTarget());
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_debilitating_beam_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_debilitating_beam_AuraScript();
    }
};

void AddSC_boss_chogall()
{
    new boss_chogall();
    new npc_spilled_blood();
    new spell_whorshipping();
    new spell_depravity();
    new spell_sprayed_corruption();
    new spell_spilled_blood_of_the_old_god();
    new spell_corrupting_crash();
    new spell_corruption_of_the_old_god();
    new npc_darkened_creation();
    new spell_debilitating_beam();
    new spell_corruption_accelerated();
    new spell_corruption_sickness();
    new npc_spiked_tentacle();
}
