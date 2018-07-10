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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>
#include "ScriptMgr.h"
#include "eye_of_azshara.h"

enum SpellIds
{
    SPELL_MASSIVE_DELUGE            = 192617, // On the tank

    SPELL_MYSTIC_TORNADO            = 192680, // The one with implicit targets
    SPELL_MYSTIC_TORNADO_AT         = 192673, // + Visual aura, the AT has random movement
    SPELL_MYSTIC_TORNADO_DAMAGE     = 192675, // + Knock Back (cast by the AT)
    SPELL_MYSTIC_TORNADO_MISSILE    = 192681,

    SPELL_ARCANE_BOMB               = 192705, // The one with implicit targets, NOT the tank
    SPELL_ARCANE_BOMB_VEHICLE       = 192706, // The one giving the debuff to dispel (+ ride vehicle)
    SPELL_ARCANE_BOMB_DAMAGE        = 192708, // Cast by the arcane bomb NPC on itself
    SPELL_ARCANE_BOMB_FOLLOW        = 192711, // Cast by the arcane bomb NPC on the player
    SPELL_RIDE_VEHICLE_HARDCODED    = 46598,

    SPELL_RAGING_STORMS             = 192696, // Cast when no one is in melee range

    // Mythic
    SPELL_CRUSHING_DEPTHS           = 197365, // Mythic only, random target
    SPELL_FROST_RESONANCE           = 196666,
    SPELL_MAGIC_RESONANCE           = 196665,
    // End Mythic

    SPELL_TIDAL_WAVE_AT             = 192753,
    SPELL_TIDAL_WAVE_DAMAGE         = 192801,

    SPELL_SURGING_WATERS_AT         = 192632, // Cast once, spawns AT
    SPELL_SURGING_WATERS_DAMAGE     = 192633, // Cast by the AT upon entering

    SPELL_CRY_OF_WRATH              = 192985, // When reaching 10%

    SPELL_TIDESTONE_OF_GOLGANNETH   = 241423,

    // Spells for the 4 naga guardians
    SPELL_STORM_CONDUIT             = 193196, // Visual from the naga to the boss

    SPELL_LIGHTNING_BLAST           = 196516,
    SPELL_AQUA_SPOUT                = 196027,
    SPELL_POLYMORPH_FISH            = 197105,
    SPELL_MAGIC_BINDING             = 196515,
    SPELL_STORM                     = 196870
};

enum CreatureIds
{
    NPC_MYSTIC_TORNADO              = 97673,
    NPC_TIDAL_WAVE                  = 97739,
    NPC_ARCANE_BOMB                 = 97691
};

struct boss_wrath_of_azshara : public BossAI
{
    boss_wrath_of_azshara(Creature* creature) : BossAI(creature, DATA_WRATH_OF_AZSHARA), _cryOfWrath(false) { }

    void Reset() override
    {
        BossAI::Reset();

        SetCombatMovement(false);

        _cryOfWrath = false;

        me->GetScheduler().Schedule(1s, [](TaskContext context)
        {
            GetContextUnit()->SetHealth(GetContextUnit()->CountPctFromMaxHealth(20));
            GetContextCreature()->LowerPlayerDamageReq(GetContextUnit()->CountPctFromMaxHealth(80));
            GetContextUnit()->ToCreature()->DisableHealthRegen();
        });

        me->RemoveAllAreaTriggers();

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FROST_RESONANCE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGIC_RESONANCE);

        me->GetInstanceScript()->SetData(DATA_CRY_OF_WRATH, 1); // Trigger Violent Winds every 90s
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        DoCastSelf(SPELL_SURGING_WATERS_AT, true);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(10, damage))
        {
            Talk(1);
            me->InterruptNonMeleeSpells(true);
            DoCastSelf(SPELL_CRY_OF_WRATH, false);
            _cryOfWrath = true;
            me->GetInstanceScript()->SetData(DATA_CRY_OF_WRATH, 0); // Trigger Violent Winds every 10s
        }
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        DoCastSelf(SPELL_TIDESTONE_OF_GOLGANNETH, true);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FROST_RESONANCE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGIC_RESONANCE);

        me->GetInstanceScript()->SetData(DATA_CRY_OF_WRATH, 2); // Remove Violent Winds

        me->RemoveAllAreaTriggers();
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_MASSIVE_DELUGE, 22s);
        events.ScheduleEvent(SPELL_RAGING_STORMS, 5s);
        events.ScheduleEvent(SPELL_TIDAL_WAVE_AT, 10s);
        events.ScheduleEvent(SPELL_MYSTIC_TORNADO, 20s);
        events.ScheduleEvent(SPELL_ARCANE_BOMB, 30s, 40s);

        if (IsHeroic())
            events.ScheduleEvent(SPELL_CRUSHING_DEPTHS, 25s, 45s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_MASSIVE_DELUGE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoCast(target, SPELL_MASSIVE_DELUGE, false);
                events.Repeat(25s);
                break;
            }
            case SPELL_RAGING_STORMS:
            {
                bool hasPlayerInRange = false;
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                if (!playerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    {
                        if (me->IsWithinMeleeRange(itr->GetSource()))
                        {
                            hasPlayerInRange = true;
                            break;
                        }
                    }

                    if (!hasPlayerInRange)
                        DoCastSelf(SPELL_RAGING_STORMS, true);
                }

                events.Repeat(2s);
                break;
            }
            case SPELL_MYSTIC_TORNADO:
            {
                Talk(2);
                DoCastSelf(SPELL_MYSTIC_TORNADO, false);
                events.Repeat(20s, 30s);
                break;
            }
            case SPELL_TIDAL_WAVE_AT:
            {
                DoCastSelf(SPELL_TIDAL_WAVE_AT, true);
                if (_cryOfWrath)
                    events.Repeat(5s);
                else
                    events.Repeat(10s, 15s);
                break;
            }
            case SPELL_ARCANE_BOMB:
                DoCastSelf(SPELL_ARCANE_BOMB, true);
                events.Repeat(55s, 60s);
                break;
            case SPELL_CRUSHING_DEPTHS:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                    DoCast(target, SPELL_CRUSHING_DEPTHS, false);
                events.Repeat(35s, 45s);
                break;
        }
    }

private:
    bool _cryOfWrath;
};

// Spell: 192632
// AT: 9640
struct at_wrath_of_azshara_surging_waters : AreaTriggerAI
{
    at_wrath_of_azshara_surging_waters(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (caster && unit)
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_SURGING_WATERS_DAMAGE, true);
    }
};

// 192680
class spell_wrath_of_azshara_mystic_tornado : public SpellScript
{
    PrepareSpellScript(spell_wrath_of_azshara_mystic_tornado);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (caster && target)
        {
            float x, y, z;
            target->GetNearPoint(target, x, y, z, 1, 10.0f, frand(0.f, 2.f * float(M_PI)));
            if (Creature* tornado = caster->SummonCreature(NPC_MYSTIC_TORNADO, x, y, z, 1.0f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                tornado->setFaction(caster->getFaction());
                tornado->SetLevel(caster->getLevel());
                tornado->SetReactState(REACT_PASSIVE);
                tornado->CastSpell(tornado, SPELL_MYSTIC_TORNADO_AT, false);
                tornado->GetMotionMaster()->MoveRandom(25.0f);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wrath_of_azshara_mystic_tornado::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell: 192673
// AT: 9647
struct at_wrath_of_azshara_mystic_tornado : AreaTriggerAI
{
    at_wrath_of_azshara_mystic_tornado(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (caster && unit && caster->IsValidAttackTarget(unit))
        {
            caster->CastSpell(unit, SPELL_MYSTIC_TORNADO_DAMAGE, true);

            Difficulty instanceDifficulty = caster->GetInstanceScript()->instance->GetDifficultyID();
            if (instanceDifficulty == DIFFICULTY_HEROIC || instanceDifficulty == DIFFICULTY_MYTHIC)
                caster->CastSpell(unit, SPELL_MAGIC_RESONANCE, true);
        }
    }
};

// Spell: 192753
// AT: 9671
struct at_wrath_of_azshara_tidal_wave : AreaTriggerAI
{
    at_wrath_of_azshara_tidal_wave(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->InitSplines(_tidalWavesPoints, 80000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (caster && unit && caster->IsValidAttackTarget(unit))
        {
            caster->CastSpell(unit, SPELL_TIDAL_WAVE_DAMAGE, true);

            Difficulty instanceDifficulty = caster->GetInstanceScript()->instance->GetDifficultyID();
            if (instanceDifficulty == DIFFICULTY_HEROIC || instanceDifficulty == DIFFICULTY_MYTHIC)
                caster->CastSpell(unit, SPELL_FROST_RESONANCE, true);
        }
    }

    void OnDestinationReached() override
    {
        at->Remove();
    }

private:
    std::vector<G3D::Vector3> _tidalWavesPoints = {
        G3D::Vector3(-3484.453, 4386.284, 0.7607061),
        G3D::Vector3(-3484.453, 4386.284, 0.7607061),
        G3D::Vector3(-3482.29, 4379.627, 0.7607061),
        G3D::Vector3(-3471.979, 4379.928, 0.7607061),
        G3D::Vector3(-3464.481, 4392.773, 0.7607061),
        G3D::Vector3(-3471.742, 4411.232, 0.7607061),
        G3D::Vector3(-3495.269, 4419.571, 0.7607061),
        G3D::Vector3(-3521.876, 4405.352, 0.7607061),
        G3D::Vector3(-3531.055, 4371.143, 0.7607061),
        G3D::Vector3(-3509.877, 4336.388, 0.7607061),
        G3D::Vector3(-3464.985, 4326.368, 0.7607061),
        G3D::Vector3(-3422.083, 4354.505, 0.7607061),
        G3D::Vector3(-3411.222, 4410.079, 0.7607061),
        G3D::Vector3(-3446.318, 4461.129, 0.7607061),
        G3D::Vector3(-3512.574, 4472.83, 0.7607061),
        G3D::Vector3(-3571.772, 4430.775, 0.7607061),
        G3D::Vector3(-3584.314, 4353.837, 0.7607061),
        G3D::Vector3(-3535.3, 4286.491, 0.7607061),
        G3D::Vector3(-3447.68, 4273.108, 0.7607061),
        G3D::Vector3(-3372.187, 4329.082, 0.7607061),
        G3D::Vector3(-3357.963, 4427.383, 0.7607061),
        G3D::Vector3(-3420.895, 4511.025, 0.7607061),
        G3D::Vector3(-3420.895, 4511.025, 0.7607061)
    };
};

// 192705
class spell_wrath_of_azshara_arcane_bomb_target : public SpellScript
{
    PrepareSpellScript(spell_wrath_of_azshara_arcane_bomb_target);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (caster && target)
        {
            caster->ToCreature()->AI()->Talk(3, target);
            caster->CastSpell(target, SPELL_ARCANE_BOMB_VEHICLE, true);
            Position pos = target->GetPosition();
            if (Creature* bomb = caster->SummonCreature(NPC_ARCANE_BOMB, pos))
            {
                bomb->EnterVehicle(target);
                bomb->CastSpell(target, SPELL_ARCANE_BOMB_FOLLOW, true);
                bomb->GetScheduler().Schedule(1s, [](TaskContext context)
                {
                    GetContextUnit()->CastSpell(GetContextUnit(), SPELL_ARCANE_BOMB_DAMAGE, false);
                });
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wrath_of_azshara_arcane_bomb_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 98173, 100248, 100249, 100250
struct npc_wrath_of_azshara_naga : public ScriptedAI
{
    npc_wrath_of_azshara_naga(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_STORM_CONDUIT);
    }

    void JustDied(Unit* killer) override
    {
        ScriptedAI::JustDied(killer);

        me->GetInstanceScript()->SetData(DATA_NAGA_DIED, 0);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(0);
        me->GetScheduler().Schedule(Seconds(5), Seconds(8), [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                GetContextUnit()->CastSpell(target, SPELL_LIGHTNING_BLAST, false);
            context.Repeat();
        });

        me->GetScheduler().Schedule(Seconds(20), Seconds(35), [](TaskContext context)
        {
            GetContextUnit()->CastSpell(GetContextUnit(), SPELL_ARCANE_BOMB, true);
            context.Repeat();
        });

        switch (me->GetEntry())
        {
            case NPC_RITUALIST_LESHA:
                me->GetScheduler().Schedule(Seconds(5), Seconds(12), [](TaskContext context)
                {
                    GetContextUnit()->CastSpell(GetContextUnit(), SPELL_AQUA_SPOUT, false);
                    context.Repeat();
                });
                break;
            case NPC_CHANNELER_VARISZ:
                me->GetScheduler().Schedule(Seconds(4), Seconds(12), [this](TaskContext context)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        GetContextUnit()->CastSpell(target, SPELL_POLYMORPH_FISH, false);
                    context.Repeat();
                });
                break;
            case NPC_BINDER_ASHIOI:
                me->GetScheduler().Schedule(Seconds(15), Seconds(20), [](TaskContext context)
                {
                    GetContextUnit()->CastSpell(GetContextUnit(), SPELL_MAGIC_BINDING, false);
                    context.Repeat();
                });
                break;
            case NPC_MYSTIC_SSAVEH:
                me->GetScheduler().Schedule(Seconds(15), Seconds(20), [](TaskContext context)
                {
                    GetContextUnit()->CastSpell(GetContextUnit(), SPELL_STORM, false);
                    context.Repeat();
                });
                break;
        }
    }
};

void AddSC_boss_wrath_of_azshara()
{
    RegisterCreatureAI(boss_wrath_of_azshara);
    RegisterCreatureAI(npc_wrath_of_azshara_naga);

    RegisterAreaTriggerAI(at_wrath_of_azshara_surging_waters);
    RegisterAreaTriggerAI(at_wrath_of_azshara_mystic_tornado);
    RegisterAreaTriggerAI(at_wrath_of_azshara_tidal_wave);

    RegisterSpellScript(spell_wrath_of_azshara_mystic_tornado);
    RegisterSpellScript(spell_wrath_of_azshara_arcane_bomb_target);
}
