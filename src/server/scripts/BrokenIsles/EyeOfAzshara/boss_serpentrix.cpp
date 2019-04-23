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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "eye_of_azshara.h"

enum Spells
{
    SPELL_RAMPAGE           = 191848,

    SPELL_HYDRA_HEAD        = 202680,

    SPELL_TOXIC_WOUND       = 191855,
    SPELL_TOXIC_PUDDLE      = 191858,

    SPELL_POISON_SPIT       = 192050,
    SPELL_POISON_SPIT_AURA  = 191839,
    // Speed depends on winds
    SPELL_POISON_SPIT_SLOW  = 191841,
    SPELL_POISON_SPIT_NORM  = 191843,
    SPELL_POISON_SPIT_FAST  = 191845,

    // 66% and 33%
    SPELL_SUBMERGE          = 191873,

    SPELL_BLAZING_NOVA      = 192003,

    SPELL_ARCANE_BLAST      = 192005
};

enum CreatureIds
{
    NPC_BLAZING_HYDRA_SPAWN = 97259,
    NPC_ARCANE_HYDRA_SPAWN  = 97260
};

// 91808
struct boss_serpentrix : public BossAI
{
    boss_serpentrix(Creature* creature) : BossAI(creature, DATA_SERPENTRIX) { }

    void Reset() override
    {
        BossAI::Reset();
        SetCombatMovement(false);

        _removeAllPuddles();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode(why);
        summons.DespawnAll();
        me->NearTeleportTo(me->GetHomePosition());
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        _removeAllPuddles();
        me->GetInstanceScript()->SetData(DATA_BOSS_DIED, 0);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_POISON_SPIT, 12s);
        events.ScheduleEvent(SPELL_TOXIC_WOUND, 7s);
        events.ScheduleEvent(SPELL_RAMPAGE, 8s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(66, damage))
        {
            Talk(0);
            DoCastSelf(SPELL_SUBMERGE, true);
            events.RescheduleEvent(SPELL_RAMPAGE, 5s);
        }
        else if (me->HealthWillBeBelowPctDamaged(33, damage))
        {
            Talk(0);
            DoCastSelf(SPELL_SUBMERGE, true);
            events.RescheduleEvent(SPELL_RAMPAGE, 5s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_POISON_SPIT:
            {
                DoCastSelf(SPELL_POISON_SPIT, false);
                events.Repeat(10s);
                break;
            }
            case SPELL_TOXIC_WOUND:
            {
                DoCastSelf(SPELL_TOXIC_WOUND, false);
                events.Repeat(25s);
                break;
            }
            case SPELL_RAMPAGE:
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
                    {
                        DoCastSelf(SPELL_RAMPAGE, true);

                        me->GetScheduler().Schedule(2s, [this](TaskContext context)
                        {
                            if (me->GetChannelSpellId() == SPELL_RAMPAGE)
                            {
                                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                                    if (me->IsWithinMeleeRange(itr->GetSource()))
                                        me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                                context.Repeat();
                            }
                        });
                    }
                }

                events.Repeat(2s);
                break;
            }
        }
    }

private:
    void _removeAllPuddles()
    {
        std::list<AreaTrigger*> atList;
        me->GetAreaTriggerListWithSpellIDInRange(atList, 191856, 100.f);
        for (auto itr : atList)
            itr->SetDuration(0);
    }
};

// 192050
class spell_serpentrix_poison_spit : public SpellScript
{
    PrepareSpellScript(spell_serpentrix_poison_spit);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        // TODO: Spell should be selected based on Violent Winds
        if (target->ToPlayer())
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_POISON_SPIT_NORM, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_serpentrix_poison_spit::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell: 191856
// AT: 9574
struct at_serpentrix_toxic_puddle : AreaTriggerAI
{
    at_serpentrix_toxic_puddle(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(1000);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            GuidUnorderedSet const& insideUnits = at->GetInsideUnits();

            for (ObjectGuid guid : insideUnits)
                if (Player* player = ObjectAccessor::GetPlayer(*caster, guid))
                    player->CastSpell(player, SPELL_TOXIC_PUDDLE, true);
        }
    }
};

// 191873
class spell_serpentrix_submerge : public SpellScript
{
    PrepareSpellScript(spell_serpentrix_submerge);

    // Teleport somewhere
    void RelocateDest(SpellEffIndex /*effIndex*/)
    {
        Trinity::Containers::RandomShuffle(_coords);
        GetHitDest()->WorldRelocate(WorldLocation(1456, _coords[0][0], _coords[0][1], _coords[0][2], _coords[0][3]));

        if (Unit* caster = GetCaster())
        {
            if (Creature* hydra = caster->SummonCreature(NPC_BLAZING_HYDRA_SPAWN, _coords[1][0], _coords[1][1], _coords[1][2], _coords[1][3], TEMPSUMMON_CORPSE_DESPAWN, 0))
                hydra->AI()->DoZoneInCombat();

            if (caster->GetMap()->IsHeroic())
            {
                if (Creature* hydra = caster->SummonCreature(NPC_ARCANE_HYDRA_SPAWN, _coords[2][0], _coords[2][1], _coords[2][2], _coords[2][3], TEMPSUMMON_CORPSE_DESPAWN, 0))
                    hydra->AI()->DoZoneInCombat();
            }
            else if (Creature* hydra = caster->SummonCreature(NPC_BLAZING_HYDRA_SPAWN, _coords[2][0], _coords[2][1], _coords[2][2], _coords[2][3], TEMPSUMMON_CORPSE_DESPAWN, 0))
                hydra->AI()->DoZoneInCombat();

            caster->CastSpell(caster, SPELL_HYDRA_HEAD, true);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_serpentrix_submerge::RelocateDest, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }

private:
    float _coords[6][4] =
    {
        { -3294.20f,    4460.52f,  -0.633784f, 3.92802f },
        { -3304.17f,    4405.53f,   0.087278f, 3.24648f },
        { -3246.71f,    4479.65f,   0.266675f, 3.28796f },
        { -3256.36f,    4370.39f,   0.374848f, 2.72140f },
        { -3199.40f,    4384.95f,   0.161310f, 3.02506f },
        { -3192.24f,    4440.18f,  -0.648342f, 3.34983f }
    };
};

// 191850
class spell_serpentix_rampage_aura : public SpellScript
{
    PrepareSpellScript(spell_serpentix_rampage_aura);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_POISON_SPIT_FAST, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_serpentix_rampage_aura::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 97259
struct npc_blazing_hydra_spawn : public ScriptedAI
{
    npc_blazing_hydra_spawn(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        SetCombatMovement(false);

        me->GetScheduler().Schedule(1s, [](TaskContext context)
        {
            GetContextUnit()->CastSpell(GetContextUnit(), SPELL_BLAZING_NOVA, false);
            context.Repeat(1s);
        });
    }
};

// 97260
struct npc_arcane_hydra_spawn : public ScriptedAI
{
    npc_arcane_hydra_spawn(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        SetCombatMovement(false);

        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                GetContextUnit()->CastSpell(target, SPELL_ARCANE_BLAST, false);
            context.Repeat(1s);
        });
    }
};

void AddSC_boss_serpentrix()
{
    RegisterCreatureAI(boss_serpentrix);
    RegisterCreatureAI(npc_blazing_hydra_spawn);
    RegisterCreatureAI(npc_arcane_hydra_spawn);

    RegisterSpellScript(spell_serpentrix_poison_spit);
    RegisterSpellScript(spell_serpentrix_submerge);
    RegisterSpellScript(spell_serpentix_rampage_aura);

    RegisterAreaTriggerAI(at_serpentrix_toxic_puddle);
}
