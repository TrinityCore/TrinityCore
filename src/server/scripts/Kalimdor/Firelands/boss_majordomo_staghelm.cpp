/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "firelands.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum Spells
{
    // Majordormo Staghelm
    SPELL_BERSERK                   = 26662, // Increases the caster's attack and movement speeds by 150% and all damage it deals by 500%. Also grants immunity to Taunt effects
    SPELL_CAT_FORM                  = 98374, // Fandral transforms into a cat when his enemies are spread out.
    SPELL_SCORPION_FORM             = 98379, // Fandral transforms into a scorpion when 7 or more of his enemies are clustered together in 10 player raids, and 18 or more in 25 player raids.
    SPELL_FURY                      = 97235, // Fandral's fury fuels his flames, increasing the damage he inflicts with Leaping Flames and Flame Scythe by 8% per application. Stacks.
    SPELL_ADRENALINE                = 97238, // Increases the caster's energy regeneration rate by 20% per application. Stacks.
    SPELL_FIERY_CYCLONE             = 98443, // Tosses all enemy targets into the air, preventing all action but making them invulnerable for 3 sec.
    SPELL_SEARING_SEEDS             = 98450, // Implants fiery seeds in the caster's enemies. Each seed grows at a different rate. When fully grown the seeds explode, inflicting 63750 Fire damage to targets within 12 yards.
    SPELL_SEARING_SEEDS_EXPLOSION   = 98620, // should be triggered when Searing Seeds removes
    SPELL_BURNING_ORBS              = 98451, // Summons Burning Orbs to attack the caster's enemies.
    SPELL_BURNING_ORBS_SUMMON       = 98565, // 10man - 2, 25man - 5
    SPELL_FLAME_SCYTHE              = 98474, // Inflicts Fire damage in front of the caster. Damage is split equally among targets hit.
    SPELL_LEAPING_FLAMES            = 98476, // Leaps at an enemy, inflicting 26036 to 29213 Fire damage in a small area and creating a Spirit of the Flame.
    SPELL_LEAPING_FLAMES_SUMMON     = 101222, // Summon Spirit of the Flame
    SPELL_LEAPING_FLAMES_PERSISTENT = 98535, // Fandral lands in a blaze of glory, igniting the ground at his destination and causing it to burn enemy enemy units for 26036 to 29213 Fire damage every 0.5 sec

    // Burning Orb
    SPELL_BURNING_ORB_PERIODIC      = 98583, // Visual. Inflicts 7650 Fire damage every 2 sec. Stacks.

    SPELL_CONCENTRATION             = 98256,
    SPELL_CONCENTRATION_AURA        = 98229,
    SPELL_LEGENDARY_CONCENTRATION   = 98245,
    SPELL_EPIC_CONCENTRATION        = 98252,
    SPELL_RARE_CONCENTRATION        = 98253,
    SPELL_UNCOMMON_CONCENTRATION    = 98254,
};

enum Events
{
    EVENT_BERSERK           = 1,
    EVENT_CHECK_PHASE       = 2,
    EVENT_LEAPING_FLAMES    = 3,
    EVENT_FLAME_SCYTHE      = 4,
    EVENT_HUMANOID_PHASE    = 5,
    EVENT_CAT_FORM          = 6,
    EVENT_SCORPION_FORM     = 7,
};

enum Yells
{
    SAY_TRANSFORM_1         = 0, // The master's power takes on many forms ...
    SAY_TRANSFORM_2         = 1, // Behold the rage of the Firelands!
    SAY_HUMANOID_1          = 2, // Blaze of Glory!
    SAY_HUMANOID_2          = 3, // Nothing but ash!
    SAY_DEATH               = 4, // My studies... had only just begun...
    SAY_BERSERK             = 5, // So much power!
    SAY_KILL                = 6, // Burn.
                                 // Soon ALL of Azeroth will burn!
                                 // You stood in the fire!
};

enum Phases
{
    PHASE_HUMANOID      = 1,
    PHASE_CAT           = 2,
    PHASE_SCORPION      = 3
};

enum CreatureEncounterIds
{
    NPC_BURNING_ORB     = 53216,
};

const Position orbsPos[5] =
{
    {468.600f, -20.167f, 78.950f, 0.0f},
    {434.693f, -14.543f, 79.000f, 0.0f},
    {384.831f, -64.045f, 79.000f, 0.0f},
    {411.289f, -101.455f, 79.00f, 0.0f},
    {451.879f, -104.702f, 79.00f, 0.0f}
};

class boss_majordomo_staghelm : public CreatureScript
{
    public:
        boss_majordomo_staghelm() : CreatureScript("boss_majordomo_staghelm") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_majordomo_staghelmAI(creature);
        }

        struct boss_majordomo_staghelmAI : public BossAI
        {
            boss_majordomo_staghelmAI(Creature* creature) : BossAI(creature, DATA_STAGHELM)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(FLScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();
                me->SetMaxPower(POWER_ENERGY, 100);
                me->SetPower(POWER_ENERGY, 0);
                me->SetHealth(me->GetMaxHealth());

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONCENTRATION_AURA);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LEGENDARY_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EPIC_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RARE_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNCOMMON_CONCENTRATION);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                _currentPhase = PHASE_HUMANOID;
                _changePhaseNum = 0;
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (IsHeroic())
                    DoCast(me, SPELL_CONCENTRATION, true);

                events.ScheduleEvent(EVENT_BERSERK, 600000);    // 10 min
                events.ScheduleEvent(EVENT_CHECK_PHASE, 2000);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONCENTRATION_AURA);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LEGENDARY_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EPIC_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RARE_CONCENTRATION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNCOMMON_CONCENTRATION);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Talk(SAY_DEATH);
                _JustDied();
            }

            void JustReachedHome() override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                switch (summon->GetEntry())
                {
                    case NPC_BURNING_ORB:
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        summon->CastSpell(summon, SPELL_BURNING_ORB_PERIODIC, false);
                        break;
                    default:
                        break;
                }

                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->GetPower(POWER_ENERGY) == 100)
                {
                    if (_currentPhase == PHASE_CAT)
                    {
                        DoCast(me, SPELL_LEAPING_FLAMES_SUMMON);
                        Unit* target = NULL;
                        target = SelectTarget(SELECT_TARGET_RANDOM, 1, -20.0f, true);
                        if (!target)
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                        if (target)
                        {
                            DoCast(target, SPELL_LEAPING_FLAMES);
                            me->CastSpell(target, SPELL_LEAPING_FLAMES_PERSISTENT, true); // doesn't work as trigger spell of 98476
                        }
                        else
                            me->SetPower(POWER_ENERGY, 0);
                    }
                    else if (_currentPhase == PHASE_SCORPION)
                    {
                        DoCastVictim(SPELL_FLAME_SCYTHE);
                    }
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_PHASE:
                        {
                            uint8 _phase = PHASE_CAT;
                            if (me->GetVictim())
                            {
                                std::list<Player*> PlayerList;
                                me->GetPlayerListInGrid(PlayerList, 10.0f);
                                uint8 const minTargets = Is25ManRaid() ? 18 : 7;
                                if (PlayerList.size() >= minTargets)
                                    _phase = PHASE_SCORPION;
                            }

                            if (_currentPhase != _phase)
                            {
                                me->SetPower(POWER_ENERGY, 0);
                                me->RemoveAurasDueToSpell(SPELL_ADRENALINE);
                                _changePhaseNum++;
                                if (_changePhaseNum % 3 == 0)
                                {
                                    me->RemoveAurasDueToSpell(SPELL_CAT_FORM);
                                    me->RemoveAurasDueToSpell(SPELL_SCORPION_FORM);
                                    Talk(_currentPhase == PHASE_CAT ? SAY_HUMANOID_1 : SAY_HUMANOID_2);
                                    DoCastAOE(SPELL_FIERY_CYCLONE, true);
                                    DoCastAOE(_currentPhase == PHASE_CAT ? SPELL_SEARING_SEEDS : SPELL_BURNING_ORBS);
                                    // Delayed Transmormation
                                    events.ScheduleEvent(_currentPhase == PHASE_CAT ? EVENT_SCORPION_FORM : EVENT_CAT_FORM, 4500);
                                    events.ScheduleEvent(EVENT_CHECK_PHASE, 6000);
                                    return;
                                }
                                else
                                {
                                    // Normal Transformation
                                    if (_phase == PHASE_CAT)
                                    {
                                        _currentPhase = PHASE_CAT;
                                        Talk(SAY_TRANSFORM_2);
                                        me->SetPower(POWER_ENERGY, 0);
                                        DoCast(me, SPELL_CAT_FORM, true);
                                        DoCast(me, SPELL_FURY, true);

                                    }
                                    else if (_phase == PHASE_SCORPION)
                                    {
                                        _currentPhase = PHASE_SCORPION;
                                        Talk(SAY_TRANSFORM_1);
                                        me->SetPower(POWER_ENERGY, 0);
                                        DoCast(me, SPELL_SCORPION_FORM, true);
                                        DoCast(me, SPELL_FURY, true);
                                    }
                                }
                            }

                            events.ScheduleEvent(EVENT_CHECK_PHASE, 1000);
                            break;
                        }
                        case EVENT_CAT_FORM:
                            _currentPhase = PHASE_CAT;
                            Talk(SAY_TRANSFORM_2);
                            me->SetPower(POWER_ENERGY, 0);
                            DoCast(me, SPELL_CAT_FORM, true);
                            DoCast(me, SPELL_FURY, true);
                            break;
                        case EVENT_SCORPION_FORM:
                            _currentPhase = PHASE_SCORPION;
                            Talk(SAY_TRANSFORM_1);
                            me->SetPower(POWER_ENERGY, 0);
                            DoCast(me, SPELL_SCORPION_FORM, true);
                            DoCast(me, SPELL_FURY, true);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                uint8 _currentPhase;
                uint32 _changePhaseNum;
        };
};

class spell_staghelm_searing_seeds_aura : public SpellScriptLoader
{
    public:
        spell_staghelm_searing_seeds_aura() : SpellScriptLoader("spell_staghelm_searing_seeds_aura") { }

        class spell_staghelm_searing_seeds_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_staghelm_searing_seeds_aura_AuraScript);

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Aura* aura = aurEff->GetBase();
                uint32 duration = urand(3000, 45000);
                aura->SetDuration(duration);
                aura->SetMaxDuration(duration);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_SEARING_SEEDS_EXPLOSION, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_staghelm_searing_seeds_aura_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_staghelm_searing_seeds_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_staghelm_searing_seeds_aura_AuraScript();
        }
};

class spell_staghelm_burning_orbs : public SpellScriptLoader
{
    public:
        spell_staghelm_burning_orbs() : SpellScriptLoader("spell_staghelm_burning_orbs") { }

        class spell_staghelm_burning_orbs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_staghelm_burning_orbs_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Difficulty difficulty = caster->GetMap()->GetDifficultyID();
                uint8 const orbsCount = (difficulty == DIFFICULTY_25_N || difficulty == DIFFICULTY_25_HC) ? 5 : 2;
                for (uint8 i = 0; i < orbsCount; ++i)
                    caster->CastSpell(orbsPos[i].GetPositionX(), orbsPos[i].GetPositionY(), orbsPos[i].GetPositionZ(), SPELL_BURNING_ORBS_SUMMON, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_staghelm_burning_orbs_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_staghelm_burning_orbs_SpellScript();
        }
};

class spell_staghelm_concentration_aura : public SpellScriptLoader
{
    public:
        spell_staghelm_concentration_aura() : SpellScriptLoader("spell_staghelm_concentration_aura") { }

        class spell_staghelm_concentration_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_staghelm_concentration_aura_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                int32 oldamount = GetUnitOwner()->GetPower(POWER_ALTERNATE_POWER);
                int32 newamount = oldamount + 5;
                if (newamount > 100)
                    newamount = 100;
                if (newamount == oldamount)
                    return;

                if (oldamount < 100 && newamount == 100)
                {
                    GetUnitOwner()->RemoveAura(SPELL_EPIC_CONCENTRATION);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_LEGENDARY_CONCENTRATION, true);
                }
                else if (oldamount < 75 && newamount >= 75)
                {
                    GetUnitOwner()->RemoveAura(SPELL_RARE_CONCENTRATION);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_EPIC_CONCENTRATION, true);
                }
                else if (oldamount < 50 && newamount >= 50)
                {
                    GetUnitOwner()->RemoveAura(SPELL_UNCOMMON_CONCENTRATION);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_RARE_CONCENTRATION, true);
                }
                else if (oldamount < 25 && newamount >= 25)
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_UNCOMMON_CONCENTRATION, true);
                }
                else if (newamount < 25)
                {
                    GetUnitOwner()->RemoveAura(SPELL_LEGENDARY_CONCENTRATION);
                    GetUnitOwner()->RemoveAura(SPELL_EPIC_CONCENTRATION);
                    GetUnitOwner()->RemoveAura(SPELL_RARE_CONCENTRATION);
                    GetUnitOwner()->RemoveAura(SPELL_UNCOMMON_CONCENTRATION);
                }
                GetUnitOwner()->SetPower(POWER_ALTERNATE_POWER, newamount);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_staghelm_concentration_aura_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_staghelm_concentration_aura_AuraScript();
        }
};

void AddSC_boss_majordomo_staghelm()
{
    new boss_majordomo_staghelm();
    new spell_staghelm_searing_seeds_aura();
    new spell_staghelm_burning_orbs();
    new spell_staghelm_concentration_aura();
}
