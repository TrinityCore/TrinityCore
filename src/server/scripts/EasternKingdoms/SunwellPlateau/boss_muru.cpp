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
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"

enum Spells
{
    // Muru's spells
    SPELL_OPEN_PORTAL_PERIODIC                  = 45994,
    SPELL_DARKNESS_PERIODIC                     = 45998,
    SPELL_NEGATIVE_ENERGY_PERIODIC              = 46009,
    SPELL_SUMMON_VOID_SPAWN                     = 46071,
    SPELL_SUMMON_BLOOD_ELVES_SCRIPT             = 46050,
    SPELL_SUMMON_BLOOD_ELVES_PERIODIC           = 46041,
    SPELL_OPEN_ALL_PORTALS                      = 46177,
    SPELL_SUMMON_ENTROPIUS                      = 46217,
    SPELL_ENRAGE                                = 26662,
    SPELL_SUMMON_DARK_FIEND_0                   = 46000,
    SPELL_SUMMON_DARK_FIEND_1                   = 46001,
    SPELL_SUMMON_DARK_FIEND_2                   = 46002,
    SPELL_SUMMON_DARK_FIEND_3                   = 46003,
    SPELL_SUMMON_DARK_FIEND_4                   = 46004,
    SPELL_SUMMON_DARK_FIEND_5                   = 46005,
    SPELL_SUMMON_DARK_FIEND_6                   = 46006,
    SPELL_SUMMON_DARK_FIEND_7                   = 46007,
    SPELL_SUMMON_BERSERKER                      = 46037,
    SPELL_SUMMON_BERSERKER_2                    = 46040,
    SPELL_SUMMON_FURY_MAGE                      = 46038,
    SPELL_SUMMON_FURY_MAGE_2                    = 46039,

    // Entropius's spells
    SPELL_ENTROPIUS_COSMETIC_SPAWN              = 46223,
    SPELL_DARKNESS_E                            = 46269,
    SPELL_NEGATIVE_ENERGY_PERIODIC_E            = 46284,
    SPELL_BLACKHOLE                             = 46282,
    SPELL_SUMMON_DARKFIEND_E                    = 46263,

    // Myruu's Portal Target
    SPELL_SUMMON_VOID_SENTINEL_SUMMONER         = 45978,
    SPELL_SUMMON_VOID_SENTINEL_SUMMONER_VISUAL  = 45989,
    SPELL_SUMMON_VOID_SENTINEL                  = 45988,
    SPELL_TRANSFORM_VISUAL_MISSILE              = 46205,
    TRANSFORM_VISUAL_MISSILE_1                  = 46208,
    TRANSFORM_VISUAL_MISSILE_2                  = 46178,
    SPELL_OPEN_PORTAL                           = 45977,
    SPELL_OPEN_PORTAL_2                         = 45976,

    //Dark Fiend Spells
    SPELL_DARKFIEND_DAMAGE                      = 45944,
    SPELL_DARKFIEND_VISUAL                      = 45936,
    SPELL_DARKFIEND_SKIN                        = 45934,

    // Void Sentinel's spells
    SPELL_SHADOW_PULSE_PERIODIC                 = 46086,
    SPELL_VOID_BLAST                            = 46161,

    //Black Hole Spells
    SPELL_BLACKHOLE_SUMMON_VISUAL               = 46242,
    SPELL_BLACKHOLE_SUMMON_VISUAL_2             = 46247,
    SPELL_BLACKHOLE_PASSIVE                     = 46228,
    SPELL_BLACK_HOLE_VISUAL_2                   = 46235
};

enum Phases
{
    PHASE_ONE                                   = 1,
    PHASE_TWO                                   = 2
};

enum Misc
{
    MAX_VOID_SPAWNS                             = 6,
    MAX_SUMMON_BLOOD_ELVES                      = 4,
    MAX_SUMMON_DARK_FIEND                       = 8
};

uint32 const SummonDarkFiendSpells[MAX_SUMMON_DARK_FIEND] =
{
    SPELL_SUMMON_DARK_FIEND_0,
    SPELL_SUMMON_DARK_FIEND_1,
    SPELL_SUMMON_DARK_FIEND_2,
    SPELL_SUMMON_DARK_FIEND_3,
    SPELL_SUMMON_DARK_FIEND_4,
    SPELL_SUMMON_DARK_FIEND_5,
    SPELL_SUMMON_DARK_FIEND_6,
    SPELL_SUMMON_DARK_FIEND_7
};

uint32 const SummonBloodElvesSpells[MAX_SUMMON_BLOOD_ELVES] =
{
    SPELL_SUMMON_BERSERKER,
    SPELL_SUMMON_BERSERKER_2,
    SPELL_SUMMON_FURY_MAGE,
    SPELL_SUMMON_FURY_MAGE_2
};

class VoidSpawnSummon : public BasicEvent
{
    public:
        explicit VoidSpawnSummon(Creature* owner)
            : _owner(owner)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _owner->CastSpell(nullptr, SPELL_SUMMON_VOID_SENTINEL, true);
            return true;
        }

    private:
        Creature* _owner;
};

struct boss_entropius : public BossAI
{
    boss_entropius(Creature* creature) : BossAI(creature, DATA_MURU) { }

    void Reset() override
    {
        _Reset();
        DoCast(me, SPELL_ENTROPIUS_COSMETIC_SPAWN, true);
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Milliseconds(2000), [this](TaskContext /*context*/)
        {
            DoResetPortals();
            DoCastAOE(SPELL_NEGATIVE_ENERGY_PERIODIC_E, true);
        });

        scheduler.Schedule(Seconds(15), [this](TaskContext context)
        {
            DoCastAOE(SPELL_DARKNESS_E, true);
            DoCastAOE(SPELL_BLACKHOLE, true);

            context.Repeat();
        });
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_DARK_FIENDS:
                summon->CastSpell(summon, SPELL_DARKFIEND_VISUAL);
                break;
            case NPC_DARKNESS:
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_BLACKHOLE);
                summon->CastSpell(summon, SPELL_SUMMON_DARKFIEND_E, true);
                break;
        }
        summons.Summon(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (Creature* muru = instance->GetCreature(DATA_MURU))
            muru->AI()->EnterEvadeMode();

        DoResetPortals();
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (Creature* muru = instance->GetCreature(DATA_MURU))
            muru->DisappearAndDie();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void DoResetPortals()
    {
        std::list<Creature*> portals;
        me->GetCreatureListWithEntryInGrid(portals, NPC_MURU_PORTAL_TARGET, 100.0f);
        for (Creature* portal : portals)
            portal->RemoveAllAuras();
    }
};

struct boss_muru : public BossAI
{
    boss_muru(Creature* creature) : BossAI(creature, DATA_MURU)
    {
        Initialize();
        SetCombatMovement(false);
    }

    void Initialize()
    {
        _hasEnraged = false;
        _phase = PHASE_ONE;
        _entropiusGUID.Clear();
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
        me->SetVisible(true);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        BossAI::EnterEvadeMode();
        if (Creature* entropius = ObjectAccessor::GetCreature(*me, _entropiusGUID))
            entropius->AI()->EnterEvadeMode();
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Minutes(10), [this](TaskContext /*context*/)
        {
            if (Creature* entropius = ObjectAccessor::GetCreature(*me, _entropiusGUID))
                entropius->CastSpell(entropius, SPELL_ENRAGE);
            DoCast(me, SPELL_ENRAGE);
            _hasEnraged = true;
        });

        scheduler.Schedule(Seconds(10), [this](TaskContext /*context*/)
        {
            DoCast(me, SPELL_SUMMON_BLOOD_ELVES_SCRIPT, true);
            DoCast(me, SPELL_SUMMON_BLOOD_ELVES_PERIODIC, true);
        });
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        DoCast(me, SPELL_OPEN_PORTAL_PERIODIC, true);
        DoCast(me, SPELL_DARKNESS_PERIODIC, true);
        DoCast(me, SPELL_NEGATIVE_ENERGY_PERIODIC, true);
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;
            if (_phase != PHASE_ONE)
                return;

            _phase = PHASE_TWO;
            me->RemoveAllAuras();
            DoCast(me, SPELL_OPEN_ALL_PORTALS, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);

            scheduler.Schedule(Seconds(6), [this](TaskContext /*context*/)
            {
                DoCast(me, SPELL_SUMMON_ENTROPIUS, true);
            });
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_ENTROPIUS)
        {
            me->SetVisible(false);
            _entropiusGUID = summon->GetGUID();
            if (_hasEnraged)
                summon->CastSpell(summon, SPELL_ENRAGE, true);
            return;
        }
        BossAI::JustSummoned(summon);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);
    }

private:
    ObjectGuid _entropiusGUID;
    bool _hasEnraged;
    uint8 _phase;
};

struct npc_muru_portal : public ScriptedAI
{
    npc_muru_portal(Creature* creature) : ScriptedAI(creature) { }

    void JustSummoned(Creature* summon) override
    {
        DoCast(summon, SPELL_SUMMON_VOID_SENTINEL_SUMMONER_VISUAL, true);

        summon->m_Events.AddEvent(new VoidSpawnSummon(summon), summon->m_Events.CalculateTime(1500ms));
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_OPEN_ALL_PORTALS:
                DoCastAOE(SPELL_OPEN_PORTAL, true);
                DoCastAOE(SPELL_TRANSFORM_VISUAL_MISSILE, true);
                break;
            case SPELL_OPEN_PORTAL_2:
                DoCastAOE(SPELL_OPEN_PORTAL, true);
                _scheduler.Schedule(Seconds(6), [this](TaskContext /*context*/)
                {
                    DoCastAOE(SPELL_SUMMON_VOID_SENTINEL_SUMMONER, true);
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_dark_fiend : public ScriptedAI
{
    npc_dark_fiend(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        me->SetReactState(REACT_PASSIVE);
        DoCast(me, SPELL_DARKFIEND_SKIN, true);

        _scheduler.Schedule(Seconds(2), [this](TaskContext /*context*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);

            if (Creature* _summoner = ObjectAccessor::GetCreature(*me, _summonerGUID))
                if (Unit* target = _summoner->AI()->SelectTarget(SelectTargetMethod::Random, 0))
                    AttackStart(target);
        });

        _scheduler.Schedule(Seconds(3), [this](TaskContext context)
        {
            if (me->IsWithinDist(me->GetVictim(), 5.0f) && me->HasAura(SPELL_DARKFIEND_SKIN))
            {
                DoCastAOE(SPELL_DARKFIEND_DAMAGE, false);
                me->DisappearAndDie();
            }

            context.Repeat(Milliseconds(500));
        });
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        _summonerGUID = summoner->GetGUID();
    }

    bool CanAIAttack(Unit const* /*target*/) const override
    {
        return me->HasAura(SPELL_DARKFIEND_SKIN);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _summonerGUID;
};

struct npc_void_sentinel : public ScriptedAI
{
    npc_void_sentinel(Creature* creature) : ScriptedAI(creature)
    {
        _instance = me->GetInstanceScript();
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* muru = _instance->GetCreature(DATA_MURU))
            muru->AI()->JustSummoned(me);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCast(me, SPELL_SHADOW_PULSE_PERIODIC, true);

        _scheduler.Schedule(Seconds(45), [this](TaskContext context)
        {
            DoCastVictim(SPELL_VOID_BLAST, false);

            context.Repeat();
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        for (uint8 i = 0; i < MAX_VOID_SPAWNS; ++i)
            DoCastAOE(SPELL_SUMMON_VOID_SPAWN, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

struct npc_blackhole : public ScriptedAI
{
    npc_blackhole(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_BLACKHOLE_SUMMON_VISUAL);

        _scheduler.Schedule(Seconds(15), [this](TaskContext /*context*/)
        {
            me->DisappearAndDie();
        });

        _scheduler.Schedule(Seconds(1), [this](TaskContext context)
        {
            switch (context.GetRepeatCounter())
            {
                case 0:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(SPELL_BLACKHOLE_SUMMON_VISUAL_2);
                    if (Unit* victim = ObjectAccessor::GetUnit(*me, _instance->GetGuidData(DATA_PLAYER_GUID)))
                        AttackStart(victim);
                    context.Repeat(Milliseconds(1200));
                    break;
                case 1:
                    DoCast(SPELL_BLACKHOLE_SUMMON_VISUAL);
                    context.Repeat(Seconds(2));
                    break;
                case 2:
                    DoCast(SPELL_BLACKHOLE_PASSIVE);
                    DoCast(SPELL_BLACK_HOLE_VISUAL_2);
                    break;
                default:
                    break;
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 46050 - Summon Blood Elves Script
class spell_summon_blood_elves_script : public SpellScript
{
    PrepareSpellScript(spell_summon_blood_elves_script);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(SummonBloodElvesSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        for (uint8 i = 0; i < MAX_SUMMON_BLOOD_ELVES; ++i)
            GetCaster()->CastSpell(nullptr, SummonBloodElvesSpells[urand(0,3)], true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_summon_blood_elves_script::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45996 - Darkness
class spell_muru_darkness : public SpellScript
{
    PrepareSpellScript(spell_muru_darkness);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(SummonDarkFiendSpells);
    }

    void HandleAfterCast()
    {
        for (uint8 i = 0; i < MAX_SUMMON_DARK_FIEND; ++i)
            GetCaster()->CastSpell(nullptr, SummonDarkFiendSpells[i], true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_muru_darkness::HandleAfterCast);
    }
};

// 45934 - Dark Fiend
class spell_dark_fiend_skin : public AuraScript
{
    PrepareAuraScript(spell_dark_fiend_skin);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (Creature* target = GetTarget()->ToCreature())
        {
            target->SetReactState(REACT_PASSIVE);
            target->AttackStop();
            target->StopMoving();
            target->CastSpell(target, SPELL_DARKFIEND_VISUAL, true);
            target->DespawnOrUnsummon(3s);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dark_fiend_skin::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46205 - Transform Visual Missile Periodic
class spell_transform_visual_missile_periodic : public AuraScript
{
    PrepareAuraScript(spell_transform_visual_missile_periodic);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, RAND(TRANSFORM_VISUAL_MISSILE_1, TRANSFORM_VISUAL_MISSILE_2), true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_transform_visual_missile_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46041 - Summon Blood Elves Periodic
class spell_summon_blood_elves_periodic : public AuraScript
{
    PrepareAuraScript(spell_summon_blood_elves_periodic);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_SUMMON_BLOOD_ELVES_SCRIPT, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_summon_blood_elves_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46284 - Negative Energy Periodic
class spell_muru_negative_energy_periodic : public AuraScript
{
    PrepareAuraScript(spell_muru_negative_energy_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, aurEff->GetTickNumber() / 10 + 1);
        GetTarget()->CastSpell(nullptr, aurEff->GetSpellEffectInfo().TriggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_muru_negative_energy_periodic::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_muru()
{
    RegisterSunwellPlateauCreatureAI(boss_muru);
    RegisterSunwellPlateauCreatureAI(boss_entropius);
    RegisterSunwellPlateauCreatureAI(npc_muru_portal);
    RegisterSunwellPlateauCreatureAI(npc_dark_fiend);
    RegisterSunwellPlateauCreatureAI(npc_void_sentinel);
    RegisterSunwellPlateauCreatureAI(npc_blackhole);
    RegisterSpellScript(spell_summon_blood_elves_script);
    RegisterSpellScript(spell_muru_darkness);
    RegisterSpellScript(spell_dark_fiend_skin);
    RegisterSpellScript(spell_transform_visual_missile_periodic);
    RegisterSpellScript(spell_summon_blood_elves_periodic);
    RegisterSpellScript(spell_muru_negative_energy_periodic);
}
