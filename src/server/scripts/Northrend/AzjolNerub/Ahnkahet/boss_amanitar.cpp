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
#include "ahnkahet.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum AmanitarSpells
{
    //Amanitar
    SPELL_BASH                            = 57094,
    SPELL_ENTANGLING_ROOTS                = 57095,
    SPELL_MINI                            = 57055,
    SPELL_VENOM_BOLT_VOLLEY               = 57088,
    SPELL_REMOVE_MUSHROOM_POWER           = 57283,
    //Mushrooms
    SPELL_POTENT_FUNGUS                   = 56648,
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD = 57061,
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA  = 56741,
    SPELL_POWER_MUSHROOM_VISUAL_AURA      = 56740,
    SPELL_PUTRID_MUSHROOM                 = 31690,
    SPELL_GROW                            = 57059,
    SPELL_SHRINK                          = 31691
};

enum AmanitarEvents
{
    EVENT_SPAWN = 1,
    EVENT_MINI,
    EVENT_ROOT,
    EVENT_BASH,
    EVENT_BOLT,
    EVENT_RESPAWN
};

Position const MushroomPositions[32] =
{
    { 373.4807f, -856.5301f, -74.30518f, 0.2094395f },
    { 358.4792f, -879.3193f, -75.9463f,  5.166174f  },
    { 356.5531f, -846.3022f, -72.1796f,  3.193953f  },
    { 332.369f,  -846.081f,  -74.30516f, 4.834562f  },
    { 360.2234f, -862.055f,  -75.22755f, 1.658063f  },
    { 351.7189f, -890.9619f, -76.54617f, 1.064651f  },
    { 345.8126f, -869.1772f, -77.17728f, 1.361357f  },
    { 367.5179f, -884.0129f, -77.32881f, 4.276057f  },
    { 370.6044f, -868.4305f, -74.19881f, 0.8901179f },
    { 381.3156f, -873.2377f, -74.82656f, 1.099557f  },
    { 371.5869f, -873.8141f, -74.72424f, 1.082104f  },
    { 340.4079f, -891.6375f, -74.99128f, 1.134464f  },
    { 368.21f,   -851.5953f, -73.99741f, 4.694936f  },
    { 328.7047f, -853.9812f, -75.51253f, 0.5759587f },
    { 366.4145f, -876.39f,   -75.52739f, 5.253441f  },
    { 380.1362f, -861.4344f, -73.45917f, 3.787364f  },
    { 373.3007f, -888.8057f, -79.03593f, 5.602507f  },
    { 348.3599f, -848.0839f, -73.54117f, 1.745329f  },
    { 352.5586f, -882.6624f, -75.68202f, 3.822271f  },
    { 357.8967f, -871.179f,  -75.77553f, 2.443461f  },
    { 360.1034f, -842.3351f, -71.08852f, 4.34587f   },
    { 348.1334f, -861.5244f, -74.61307f, 2.565634f  },
    { 401.4896f, -866.7059f, -73.22395f, 0.8901179f },
    { 360.1683f, -889.1515f, -76.74798f, 3.612832f  },
    { 350.1828f, -907.7313f, -74.94678f, 5.044002f  },
    { 340.6278f, -856.5973f, -74.23862f, 4.415683f  },
    { 366.4849f, -859.7621f, -74.82679f, 1.500983f  },
    { 359.1482f, -853.3346f, -74.47543f, 5.654867f  },
    { 374.9992f, -879.0921f, -75.56115f, 1.867502f  },
    { 339.5252f, -850.4612f, -74.45442f, 4.764749f  },
    { 337.0534f, -864.002f,  -75.72749f, 4.642576f  },
    { 398.2797f, -851.8694f, -68.84419f, 0.5759587f }
};

struct boss_amanitar : public BossAI
{
    boss_amanitar(Creature* creature) : BossAI(creature, DATA_AMANITAR) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        events.ScheduleEvent(EVENT_ROOT, 5s, 9s);
        events.ScheduleEvent(EVENT_BASH, 10s, 14s);
        events.ScheduleEvent(EVENT_BOLT, 15s, 20s);
        events.ScheduleEvent(EVENT_MINI, 12s, 18s);
        events.ScheduleEvent(EVENT_SPAWN, 1s);
        events.ScheduleEvent(EVENT_RESPAWN, 40s, 1min);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI, true, true);
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastAOE(SPELL_REMOVE_MUSHROOM_POWER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI, true, true);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        _mushroomsDeque.push_back(summon->GetPosition());

        BossAI::SummonedCreatureDies(summon, killer);
    }

    void SpawnMushroom(Position const pos)
    {
        me->SummonCreature(roll_chance_i(40) ? NPC_HEALTHY_MUSHROOM : NPC_POISONOUS_MUSHROOM, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 4000);
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
                case EVENT_SPAWN:
                    for (Position const pos : MushroomPositions)
                        SpawnMushroom(pos);
                    break;
                case EVENT_MINI:
                    if (SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, true, -SPELL_MINI))
                    {
                        DoCastAOE(SPELL_MINI);
                        events.Repeat(Seconds(30));
                    }
                    else
                        events.Repeat(Seconds(1));
                    break;
                case EVENT_ROOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                        DoCast(target, SPELL_ENTANGLING_ROOTS, true);
                    events.Repeat(Seconds(10), Seconds(15));
                    break;
                case EVENT_BASH:
                    DoCastVictim(SPELL_BASH);
                    events.Repeat(Seconds(7), Seconds(12));
                    break;
                case EVENT_BOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_VENOM_BOLT_VOLLEY, true);
                    events.Repeat(Seconds(18), Seconds(22));
                    break;
                case EVENT_RESPAWN:
                    while (!_mushroomsDeque.empty())
                    {
                        SpawnMushroom(_mushroomsDeque.front());
                        _mushroomsDeque.pop_front();
                    }
                    events.Repeat(Seconds(40), Seconds(60));
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
        std::deque<Position> _mushroomsDeque;
};

struct npc_amanitar_mushrooms : public ScriptedAI
{
    npc_amanitar_mushrooms(Creature* creature) : ScriptedAI(creature), _active(false) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        DoCastSelf(SPELL_PUTRID_MUSHROOM);
        DoCastSelf(SPELL_SHRINK, true);
        DoCastSelf(SPELL_GROW, true);

        if (me->GetEntry() == NPC_HEALTHY_MUSHROOM)
        {
            DoCastSelf(SPELL_POWER_MUSHROOM_VISUAL_AURA);
            _active = true;
        }
        else
            DoCastSelf(SPELL_POISONOUS_MUSHROOM_VISUAL_AURA);

        _scheduler.Schedule(Milliseconds(800), [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_GROW, true);
        });
    }

    void MoveInLineOfSight(Unit* target) override
    {
        if (_active || target->GetTypeId() != TYPEID_PLAYER || me->GetDistance2d(target) > 2.0f)
            return;

        _active = true;

        target->RemoveAurasDueToSpell(SPELL_POTENT_FUNGUS);
        DoCastAOE(SPELL_POISONOUS_MUSHROOM_POISON_CLOUD);

        _scheduler.Schedule(Seconds(1), [this](TaskContext /*context*/)
        {
            me->SetObjectScale(0.1f);
            me->DespawnOrUnsummon(Seconds(4));
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetEntry() == NPC_HEALTHY_MUSHROOM)
            DoCastAOE(SPELL_POTENT_FUNGUS, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    bool _active;
};

// 56648 - Potent Fungus
class spell_amanitar_potent_fungus : public AuraScript
{
    PrepareAuraScript(spell_amanitar_potent_fungus);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_MINI))
            return;

        target->RemoveAurasDueToSpell(SPELL_MINI);
        Remove();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_amanitar_potent_fungus::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_amanitar()
{
    RegisterAhnKahetCreatureAI(boss_amanitar);
    RegisterAhnKahetCreatureAI(npc_amanitar_mushrooms);
    RegisterAuraScript(spell_amanitar_potent_fungus);
}
