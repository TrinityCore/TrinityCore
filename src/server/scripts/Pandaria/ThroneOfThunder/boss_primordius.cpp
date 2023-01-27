#include "ScriptPCH.h"
#include "throne_of_thunder.h"
#include "SpellAuras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_PRIMORDIAL_STRIKE = 136037,
    SPELL_MALFORMED_BLOOD = 136050,
    SPELL_MUTATED_ABOMINATION = 140544,
    SPELL_EVOLUTION = 136209,

    // Evolutions for Primosdius
    //Mutation: Erupting Pustules
    SPELL_ERUPTING_PUSTULES = 136246,
    SPELL_PUSTULE_ERUPTION_MISSILE = 136248,
    //Mutation: Metabolic Boost
    SPELL_METABOLIC_BOOST = 136245,
    //Mutation: Pathogen Glands
    SPELL_PATHOGEN_GLANDS = 136225,
    SPELL_VOLATILE_PATHOGEN_DAMAGE = 136228,
    //Mutation: Acidic Spines
    SPELL_ACIDIC_SPINES = 136218,
    SPELL_ACIDIC_EXPLOSION_MISSILE = 136219,
    //Mutation: Gas Bladder
    SPELL_GAS_BLADDER = 136215,
    SPELL_CAUSTIC_GAS = 136216,
    //Mutation: Ventral SacS
    SPELL_VECTRAL_SACS = 136210,

    // living fluid
    SPELL_MUTATE_PRIMORDIUS = 136203,
    SPELL_MUTAGENIC_POOL = 136049,
    SPELL_MUTATE_PLAYER = 136178,

    // Mutation effects for players ( helpful and harmful mutation system )
    SPELL_THICK_BONES = 136184,
    SPELL_FRAGILE_BONES = 136185,

    SPELL_CLEAR_MIND = 136186,
    SPELL_CLOUDED_MIND = 136187,

    SPELL_IMPROVED_SYNAPSES = 136182,
    SPELL_DULLED_SYNAPSES = 136183,

    SPELL_KEEN_EYESIGHT = 136180,
    SPELL_IMPAIRED_EYESIGHT = 136181,

    SPELL_FULLY_MUTATED = 140546,

    SPELL_VOLATILE_POOL = 140506,
    SPELL_VOLATILE_MUTATE_PRIMORDIUS = 140509,
    SPELL_VOLATILE_MUTATE_PLAYER_PERIODIC = 140508,

    SPELL_BLACK_BLOOD = 137000,
    SPELL_DEADLY_MUTAGEN = 136995,
};

enum Creatures
{
    NPC_VISCOUS_HORROR = 69070,
    NPC_VOLATILE_POOL = 999455,
    NPC_MUTAGENIC_POOL = 999454,
    NPC_LIVING_FLUID = 70579,
    NPC_PRIMORDIUS = 69017,
};

enum Events
{
    EVENT_MALFORMED_BLOOD = 1,
    EVENT_PRIMORDIAL_STRIKE,
    EVENT_BLACK_BLOOD,
    EVENT_ENERGY_GAIN,
    EVENT_CHECK_ENERGY,
    EVENT_SUMMON_FLUIDS_SPAWNER,
    EVENT_SUMMON_HORRORS,
    EVENT_CAUSTIC_GAS,
    EVENT_VOLATILE_PATHOGEN,
    EVENT_VOLATILE_TO_BOSS,
    EVENT_HARD_ENRAGE,
    EVENT_VOLATILE_CAST_PLAYERS,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_DEATH = 2,
    TALK_EVOLUTION = 3,
    TALK_KILL_PLAYER = 4,
};

uint32 allEvolutions[6] =
{
    SPELL_VECTRAL_SACS,
    SPELL_ACIDIC_SPINES,
    SPELL_ERUPTING_PUSTULES,
    SPELL_METABOLIC_BOOST,
    SPELL_PATHOGEN_GLANDS,
    SPELL_GAS_BLADDER
};

static const std::pair<uint32, uint32> m_pMutations[4] =
{
    { SPELL_KEEN_EYESIGHT, SPELL_IMPAIRED_EYESIGHT },
    { SPELL_IMPROVED_SYNAPSES, SPELL_DULLED_SYNAPSES },
    { SPELL_THICK_BONES, SPELL_FRAGILE_BONES },
    { SPELL_CLEAR_MIND, SPELL_CLOUDED_MIND }
};

static inline const uint32 GetTotalMutations(Unit* pUnit)
{
    uint32 m_uiMutations = 0;

    Aura* pAura;

    for (uint8 i = 0; i < 4; ++i)
    {
        if (pAura = pUnit->GetAura(m_pMutations[i].first))
            m_uiMutations += pAura->GetStackAmount();
    }

    return m_uiMutations;
};

class bfa_boss_primordius : public CreatureScript
{
public:
    bfa_boss_primordius() : CreatureScript("bfa_boss_primordius") { }

    struct bfa_boss_primordiusAI : public ScriptedAI
    {
        bfa_boss_primordiusAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            instance = creature->GetInstanceScript();
        }

        SummonList summons;
        EventMap events;
        uint32 evolutions[4];
        InstanceScript* instance;

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
            me->SetPower(POWER_ENERGY, 0);
            evolutions[0] = 0;
            evolutions[1] = 0;
            evolutions[2] = 0;
            evolutions[3] = 0;
            DespawnCreature(NPC_VOLATILE_POOL);
            DespawnCreature(NPC_MUTAGENIC_POOL);
            DespawnCreature(NPC_VISCOUS_HORROR);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_LIVING_FLUID);
            me->SetHealth(me->GetMaxHealth());

            if (instance)
                instance->SetBossState(DATA_PRIMORDIUS, NOT_STARTED);
        }

        void RemoveMutationsAtKill()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_KEEN_EYESIGHT);
                    player->RemoveAura(SPELL_THICK_BONES);
                    player->RemoveAura(SPELL_CLEAR_MIND);
                    player->RemoveAura(SPELL_IMPROVED_SYNAPSES);
                    player->RemoveAura(SPELL_FRAGILE_BONES);
                    player->RemoveAura(SPELL_DULLED_SYNAPSES);
                    player->RemoveAura(SPELL_CLOUDED_MIND);
                    player->RemoveAura(SPELL_IMPAIRED_EYESIGHT);
                }
        }

        void EnterEvadeMode(EvadeReason w)
        {
            ScriptedAI::EnterEvadeMode();

            summons.DespawnAll();

            if (instance)
                instance->SetBossState(DATA_PRIMORDIUS, FAIL);
        }

        void JustDied(Unit*)
        {
            summons.DespawnAll();
            DespawnCreature(NPC_VOLATILE_POOL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_MUTAGENIC_POOL);
            DespawnCreature(NPC_VISCOUS_HORROR);
            DespawnCreature(NPC_LIVING_FLUID);
            Talk(TALK_DEATH);
            RemoveMutationsAtKill();

            if (instance)
                instance->SetBossState(DATA_PRIMORDIUS, DONE);
        }

        void EnterCombat(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->ModifyAuraState(AURA_STATE_CONFLAGRATE, true);
            Talk(TALK_AGGRO);
            events.ScheduleEvent(EVENT_PRIMORDIAL_STRIKE, 20000, 0, 0);
            events.ScheduleEvent(EVENT_MALFORMED_BLOOD, 15000, 0, 0);
            events.ScheduleEvent(EVENT_HARD_ENRAGE, 8 * MINUTE * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ENERGY_GAIN, 5000, 0, 0);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, 500, 0, 0);
            events.ScheduleEvent(EVENT_VOLATILE_PATHOGEN, 5000);
            events.ScheduleEvent(EVENT_SUMMON_FLUIDS_SPAWNER, 5000, 0, 0);
            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_SUMMON_HORRORS, 30000, 0, 0);
            me->AddAura(SPELL_MUTATED_ABOMINATION, me);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 60);
            me->SetPower(POWER_ENERGY, 0);

            if (instance)
                instance->SetBossState(DATA_PRIMORDIUS, IN_PROGRESS);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        void KilledUnit(Unit* victim)
        {
            Talk(TALK_KILL_PLAYER);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_HARD_ENRAGE:
                    me->AddAura(26662, me);
                    break;
                case EVENT_CHECK_ENERGY:
                    if (me->GetPower(POWER_ENERGY) == 60)
                    {
                        Talk(TALK_EVOLUTION);
                        me->SetPower(POWER_ENERGY, 0);
                        me->CastSpell(me, SPELL_EVOLUTION);
                    }
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 100, 0, 0);
                    break;
                case EVENT_ENERGY_GAIN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
                    events.ScheduleEvent(EVENT_ENERGY_GAIN, 1000, 0, 0);
                    break;
                case EVENT_PRIMORDIAL_STRIKE:
                    me->CastSpell(me->GetVictim(), SPELL_PRIMORDIAL_STRIKE);
                    if (me->HasAura(SPELL_METABOLIC_BOOST))
                    {
                        events.ScheduleEvent(EVENT_PRIMORDIAL_STRIKE, 10000);
                    }
                    else
                        events.ScheduleEvent(EVENT_PRIMORDIAL_STRIKE, 20000, 0, 0);
                    break;
                case EVENT_MALFORMED_BLOOD:
                    me->CastSpell(me->GetVictim(), SPELL_MALFORMED_BLOOD);
                    if (me->HasAura(SPELL_METABOLIC_BOOST))
                    {
                        events.ScheduleEvent(EVENT_MALFORMED_BLOOD, 7500);
                    }
                    else
                        events.ScheduleEvent(EVENT_MALFORMED_BLOOD, 15000, 0, 0);
                    break;
                case EVENT_SUMMON_FLUIDS_SPAWNER:
                {
                    me->SummonCreature(NPC_LIVING_FLUID, 5644.46f, 4603.83f, 55.77f, 5.56f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5663.65f, 4636.29f, 55.77f, 6.18f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5666.07f, 4675.39f, 55.77f, 0.27f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5644.36f, 4708.64f, 55.77f, 4.48f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5538.96f, 4707.24f, 55.77f, 1.59f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5521.82f, 4674.86f, 55.77f, 4.06f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5518.97f, 4637.03f, 55.77f, 2.67f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_LIVING_FLUID, 5539.16f, 4603.12f, 55.77f, 2.92f, TEMPSUMMON_CORPSE_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON_FLUIDS_SPAWNER, 15000, 0, 0);
                    break;
                }
                case EVENT_SUMMON_HORRORS:
                    me->SummonCreature(NPC_VISCOUS_HORROR, 5518.97f, 4637.03f, 55.77f, 2.67f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    events.ScheduleEvent(EVENT_SUMMON_HORRORS, 30000, 0, 0);
                    break;
                case EVENT_VOLATILE_PATHOGEN:
                    if (me->HasAura(SPELL_PATHOGEN_GLANDS))
                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                        if (!targets.empty())
                            if (targets.size() >= 1)
                                targets.resize(1);

                        for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                            me->CastSpell((*itr), SPELL_VOLATILE_PATHOGEN_DAMAGE);
                    }
                    events.ScheduleEvent(EVENT_VOLATILE_PATHOGEN, 30000);
                    break;
                case EVENT_CAUSTIC_GAS:
                    if (me->HasAura(SPELL_GAS_BLADDER))
                        me->CastSpell(me, SPELL_CAUSTIC_GAS);
                    events.ScheduleEvent(EVENT_CAUSTIC_GAS, 15000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void CalculateHeroicEvolutions(uint32 genericMutations)
        {
            bool shifted = true;

            for (uint8 i = 0; i < 4; ++i)
            {
                if (evolutions[i] == 0)
                {
                    evolutions[i] = genericMutations;
                    shifted = false;
                    break;
                }
            }

            if (shifted)
            {
                me->RemoveAurasDueToSpell(evolutions[0]);

                evolutions[0] = evolutions[1];
                evolutions[1] = evolutions[2];
                evolutions[2] = evolutions[3];
                evolutions[3] = genericMutations;
            }

            me->AddAura(genericMutations, me);

            switch (genericMutations)
            {
            case SPELL_GAS_BLADDER:
            {
                events.ScheduleEvent(EVENT_CAUSTIC_GAS, 5000);
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136215|h[Gas Bladder]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_PATHOGEN_GLANDS:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136225|h[Pathogen Glands]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_VECTRAL_SACS:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136210|h[Ventral Sacs]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_ACIDIC_SPINES:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136218|h[Acidic Spines]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_METABOLIC_BOOST:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136245|h[Metabolic Boost]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_ERUPTING_PUSTULES:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136246|h[Erupting Pustules]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            default:
                break;
            }
        }

        void CalculateEvolutions(uint32 genericMutations)
        {
            bool shifted = true;

            for (uint8 i = 0; i < 3; ++i)
            {
                if (evolutions[i] == 0)
                {
                    evolutions[i] = genericMutations;
                    shifted = false;
                    break;
                }
            }

            if (shifted)
            {
                me->RemoveAurasDueToSpell(evolutions[0]);

                evolutions[0] = evolutions[1];
                evolutions[1] = evolutions[2];
                evolutions[2] = genericMutations;
            }

            me->AddAura(genericMutations, me);

            switch (genericMutations)
            {
            case SPELL_GAS_BLADDER:
            {
                events.ScheduleEvent(EVENT_CAUSTIC_GAS, 5000);
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136215|h[Gas Bladder]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_PATHOGEN_GLANDS:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136225|h[Pathogen Glands]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_VECTRAL_SACS:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136210|h[Ventral Sacs]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_ACIDIC_SPINES:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136218|h[Acidic Spines]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_METABOLIC_BOOST:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136245|h[Metabolic Boost]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case SPELL_ERUPTING_PUSTULES:
            {
                std::ostringstream str;
                str << "Primordius |cFFF00000|Hspell:136209|h[Evolves]|h|r and gains |cFFF00000|Hspell:136246|h[Erupting Pustules]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_primordiusAI(creature);
    }
};

class hasAuraPredicate
{
private:
    Unit* pUnit;
public:
    hasAuraPredicate(Unit* _pUnit) : pUnit(_pUnit) {}

    bool operator()(const uint32 mValue) const
    {
        return pUnit->HasAura(mValue);
    }
};

// 136209
class bfa_spell_mutation_primordius : public SpellScriptLoader
{
public:
    bfa_spell_mutation_primordius() : SpellScriptLoader("bfa_spell_mutation_primordius") {}

    class bfa_spell_mutation_primordius_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_mutation_primordius_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Creature* pCreature = GetHitCreature())
            {
                if (!pCreature)
                    return;

                std::list<uint32> m_lEvolveList;

                for (uint8 i = 0; i < 6; ++i)
                    m_lEvolveList.push_back(allEvolutions[i]);

                m_lEvolveList.remove_if(hasAuraPredicate(pCreature));

                uint32 m_uiAura = Trinity::Containers::SelectRandomContainerElement(m_lEvolveList);
                if (pCreature->GetMap()->IsHeroic())
                    CAST_AI(bfa_boss_primordius::bfa_boss_primordiusAI, pCreature->AI())->CalculateHeroicEvolutions(m_uiAura);
                else
                    CAST_AI(bfa_boss_primordius::bfa_boss_primordiusAI, pCreature->AI())->CalculateEvolutions(m_uiAura);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_mutation_primordius_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_mutation_primordius_SpellScript();
    }
};

// 136216
class bfa_spell_caustic_gas : public SpellScriptLoader
{
public:
    bfa_spell_caustic_gas() : SpellScriptLoader("bfa_spell_caustic_gas") { }

    class bfa_spell_caustic_gas_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_caustic_gas_SpellScript);

        uint8 targetsPlayers;

        bool Load()
        {
            targetsPlayers = 1;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetsPlayers = targets.size();
        }

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(GetHitDamage() / targetsPlayers);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_caustic_gas_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_caustic_gas_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_caustic_gas_SpellScript();
    }
};

// 136218
class bfa_spell_acidic_spines : public SpellScriptLoader
{
public:
    bfa_spell_acidic_spines() : SpellScriptLoader("bfa_spell_acidic_spines") { }

    class bfa_spell_acidic_spines_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_acidic_spines_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;
            GetCaster()->CastSpell(GetCaster(), SPELL_ACIDIC_EXPLOSION_MISSILE);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_acidic_spines_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_acidic_spines_AuraScript;
    }
};

// 136178 / 140508
class bfa_spell_add_mutations_players : public SpellScriptLoader
{
public:
    bfa_spell_add_mutations_players() : SpellScriptLoader("bfa_spell_add_mutations_players") {}

    class bfa_spell_add_mutations_players_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_add_mutations_players_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            if (Unit* pUnit = GetHitUnit())
            {
                if (!pUnit)
                    return;

                if (pUnit->HasAura(SPELL_FULLY_MUTATED))
                {
                    uint32 m_uiInfection = m_pMutations[urand(0, 3)].second;

                    if (Aura* pAura = pUnit->GetAura(m_uiInfection))
                        pAura->ModStackAmount(1);
                    else
                        pUnit->AddAura(m_uiInfection, pUnit);
                }
                else
                {
                    const std::pair<uint32, uint32> m_pMutationPair = m_pMutations[urand(0, 3)];
                    const uint32 m_uiTotalStacks = GetTotalMutations(pUnit);

                    if (Aura* pAura = pUnit->GetAura(m_pMutationPair.first))
                    {
                        if (pAura->GetStackAmount() >= 4)
                        {
                            pAura->Remove(AURA_REMOVE_BY_ENEMY_SPELL);

                            if (Aura* pNegAura = pUnit->GetAura(m_pMutationPair.second))
                                pNegAura->ModStackAmount(1);
                            else
                                pUnit->AddAura(m_pMutationPair.second, pUnit);
                        }
                        else
                            pAura->ModStackAmount(1);
                    }
                    else
                        pUnit->AddAura(m_pMutationPair.first, pUnit);

                    if (m_uiTotalStacks + 1 >= 5)
                    {
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            if (Aura* pAura = pUnit->GetAura(m_pMutations[i].first))
                                pAura->RefreshDuration();
                        }

                        pUnit->CastSpell(pUnit, SPELL_FULLY_MUTATED, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_add_mutations_players_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_add_mutations_players_SpellScript();
    }
};
// harmful \ helpful mutations ( all of them )
class bfa_spell_mutations_player : public SpellScriptLoader
{
public:
    bfa_spell_mutations_player() : SpellScriptLoader("bfa_spell_mutations_player") {}

    class bfa_spell_mutations_player_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_mutations_player_AuraScript);

        void HandleOnDispel(DispelInfo* /*info*/)
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                uint32 m_uiMutation = m_pMutations[i].first;
                uint32 m_uiInfection = m_pMutations[i].second;

                if (GetId() != m_uiMutation)
                    GetOwner()->ToUnit()->RemoveAura(m_uiMutation);

                if (GetId() != m_uiInfection)
                    GetOwner()->ToUnit()->RemoveAura(m_uiInfection);
            }
        }

        void Register() override
        {
            OnDispel += AuraDispelFn(bfa_spell_mutations_player_AuraScript::HandleOnDispel);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_mutations_player_AuraScript();
    }
};

class bfa_npc_living_fluid : public CreatureScript
{
public:
    bfa_npc_living_fluid() : CreatureScript("bfa_npc_living_fluid") { }

    struct bfa_npc_living_fluidAI : public ScriptedAI
    {
        bfa_npc_living_fluidAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->SetSpeed(MOVE_RUN, 0.4f);
            me->SetSpeed(MOVE_WALK, 0.4f);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->GetMotionMaster()->MoveChase(summoner);
            //me->AI()->AttackStart(summoner);
            //me->AddThreat(summoner, 99999999.9f);
        }

        void JustDied(Unit*)
        {
            if (roll_chance_f(70))
            {
                me->SummonCreature(NPC_MUTAGENIC_POOL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
            }
            else
            {
                me->SummonCreature(NPC_VOLATILE_POOL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* primordius = me->FindNearestCreature(NPC_PRIMORDIUS, 500.0f, true))
            {
                me->GetMotionMaster()->MoveChase(primordius);

                if (me->GetDistance(primordius) < 3)
                {
                    primordius->SetPower(POWER_ENERGY, primordius->GetPower(POWER_ENERGY) + 1);
                    me->DespawnOrUnsummon();
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_living_fluidAI(creature);
    }
};

class bfa_npc_viscous_horror : public CreatureScript
{
public:
    bfa_npc_viscous_horror() : CreatureScript("bfa_npc_viscous_horror") { }

    struct bfa_npc_viscous_horrorAI : public ScriptedAI
    {
        bfa_npc_viscous_horrorAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->SetSpeed(MOVE_RUN, 0.5f);
            me->SetSpeed(MOVE_WALK, 0.5f);
        }

        EventMap events;

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_BLACK_BLOOD, 30000, 0, 0);
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->GetMotionMaster()->MoveChase(summoner);
            //me->AI()->AttackStart(summoner);
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* primordius = me->FindNearestCreature(NPC_PRIMORDIUS, 500.0f, true))
            {
                if (me->GetDistance(primordius) < 5.0f)
                {
                    me->CastSpell(me, SPELL_DEADLY_MUTAGEN, true);
                    me->DespawnOrUnsummon();
                }
            }

            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLACK_BLOOD:
                    me->CastSpell(me->GetVictim(), SPELL_BLACK_BLOOD);
                    events.ScheduleEvent(EVENT_BLACK_BLOOD, 30000, 0, 0);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_viscous_horrorAI(creature);
    }
};

class bfa_npc_mutagenic_pool : public CreatureScript
{
public:
    bfa_npc_mutagenic_pool() : CreatureScript("bfa_npc_mutagenic_pool") { }

    struct bfa_npc_mutagenic_poolAI : public ScriptedAI
    {
        bfa_npc_mutagenic_poolAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->CastSpell(me, 136049, true);
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* primordius = me->FindNearestCreature(NPC_PRIMORDIUS, 500.0f, true))
            {
                if (me->GetDistance(primordius) < 3.0f)
                {
                    primordius->SetPower(POWER_ENERGY, primordius->GetPower(POWER_ENERGY) + 1);
                    me->DespawnOrUnsummon();
                }
            }

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetExactDist2d(me) < 3.0f && player->IsAlive() && !player->IsGameMaster())
                    {
                        player->CastSpell(player, SPELL_MUTATE_PLAYER, true);
                        me->DespawnOrUnsummon();
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_mutagenic_poolAI(creature);
    }
};

class bfa_npc_volatile_pool : public CreatureScript
{
public:
    bfa_npc_volatile_pool() : CreatureScript("bfa_npc_volatile_pool") { }

    struct bfa_npc_volatile_poolAI : public ScriptedAI
    {
        bfa_npc_volatile_poolAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->CastSpell(me, SPELL_VOLATILE_POOL);
            me->SetSpeed(MOVE_RUN, 0.5f);
            me->SetSpeed(MOVE_WALK, 0.5f);
            me->SetObjectScale(0.7f);
            me->SetFaction(7);
            events.ScheduleEvent(EVENT_VOLATILE_TO_BOSS, 2000);
            events.ScheduleEvent(EVENT_VOLATILE_CAST_PLAYERS, 1000);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* primordius = me->FindNearestCreature(NPC_PRIMORDIUS, 500.0f, true))
            {
                if (me->GetDistance(primordius) < 3.0f)
                {
                    me->CastSpell(primordius, SPELL_VOLATILE_MUTATE_PRIMORDIUS, true);
                    primordius->SetPower(POWER_ENERGY, primordius->GetPower(POWER_ENERGY) + 60); // in case of give power doesn't work because there is MANA type and this boss will use ENERGY
                    me->DespawnOrUnsummon();
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOLATILE_TO_BOSS:
                {
                    if (Creature* primordius = me->FindNearestCreature(NPC_PRIMORDIUS, 500.0f, true))
                    {
                        me->GetMotionMaster()->MoveChase(primordius);
                        //me->AI()->AttackStart(primordius);
                        //me->AddThreat(primordius, 99999999.9f);
                    }
                    break;
                }
                case EVENT_VOLATILE_CAST_PLAYERS:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetExactDist2d(me) < 3.0f && player->IsAlive() && !player->IsGameMaster())
                            {
                                player->CastSpell(player, SPELL_VOLATILE_MUTATE_PLAYER_PERIODIC, true);
                            }
                        }
                    events.ScheduleEvent(EVENT_VOLATILE_CAST_PLAYERS, 1000);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_volatile_poolAI(creature);
    }
};

// 136051
class bfa_spell_congeal_blood : public SpellScriptLoader
{
public:
    bfa_spell_congeal_blood() : SpellScriptLoader("bfa_spell_congeal_blood") { }

    class bfa_spell_congeal_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_congeal_blood_SpellScript);

        void OnHit(SpellEffIndex index)
        {
            if (Unit* target = GetHitUnit())
            {
                if (!target)
                    return;

                if (target->GetEntry() == NPC_LIVING_FLUID || target->GetEntry() == NPC_VISCOUS_HORROR)
                {
                    if (!GetCaster()->GetAura(SPELL_MALFORMED_BLOOD))
                        return;
                    uint32 damage = urand(1, 4);
                    uint32 base = 20000;

                    SetHitDamage(damage * base);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_congeal_blood_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_congeal_blood_SpellScript();
    }

};

// 136999
class bfa_spell_black_blood : public SpellScriptLoader
{
public:
    bfa_spell_black_blood() : SpellScriptLoader("bfa_spell_black_blood") { }

    class bfa_spell_black_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_black_blood_SpellScript);

        void OnHit(SpellEffIndex index)
        {
            if (Unit* target = GetHitUnit())
            {
                if (!target)
                    return;

                if (target->GetEntry() == NPC_PRIMORDIUS)
                {
                    if (!GetCaster()->GetAura(SPELL_BLACK_BLOOD))
                        return;
                    uint32 damage = urand(1, 4);
                    uint32 base = 20000;

                    SetHitDamage(damage * base);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_black_blood_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_black_blood_SpellScript();
    }

};

class bfa_spell_add_bad_mutations_player : public SpellScriptLoader
{
public:
    bfa_spell_add_bad_mutations_player() : SpellScriptLoader("bfa_spell_add_bad_mutations_player") {}

    class bfa_spell_add_bad_mutations_player_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_add_bad_mutations_player_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Unit* pUnit = GetHitUnit())
            {
                if (!pUnit)
                    return;

                const std::pair<uint32, uint32> m_pMutationPair = m_pMutations[urand(0, 3)];

                pUnit->AddAura(m_pMutationPair.second, pUnit);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_add_bad_mutations_player_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_add_bad_mutations_player_SpellScript();
    }
};

void AddSC_bfa_boss_primordius()
{
    new bfa_npc_living_fluid;
    new bfa_boss_primordius;
    new bfa_npc_viscous_horror;
    new bfa_npc_volatile_pool;
    new bfa_npc_mutagenic_pool;
    new bfa_spell_mutation_primordius;
    new bfa_spell_acidic_spines;
    new bfa_spell_caustic_gas;
    new bfa_spell_mutations_player;
    new bfa_spell_add_mutations_players;
    new bfa_spell_congeal_blood;
    new bfa_spell_black_blood;
    new bfa_spell_add_bad_mutations_player;
}
