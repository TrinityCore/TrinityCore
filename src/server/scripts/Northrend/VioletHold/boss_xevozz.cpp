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
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "violet_hold.h"

/*
 * TODO:
 * - Implement Ethereal Summon Target
 */

enum Spells
{
    SPELL_ARCANE_BARRAGE_VOLLEY                 = 54202,
    SPELL_ARCANE_BUFFET                         = 54226,
    SPELL_SUMMON_TARGET_VISUAL                  = 54111
};

static uint32 const EtherealSphereCount = 3;
static uint32 const EtherealSphereSummonSpells[EtherealSphereCount] = { 54102, 54137, 54138 };
static uint32 const EtherealSphereHeroicSummonSpells[EtherealSphereCount] = { 54102, 54137, 54138 };

enum NPCs
{
    NPC_ETHEREAL_SPHERE                         = 29271,
    NPC_ETHEREAL_SPHERE2                        = 32582,
    NPC_ETHEREAL_SUMMON_TARGET                  = 29276
};

enum CreatureSpells
{
    H_SPELL_ARCANE_POWER                        = 59474,
    SPELL_MAGIC_PULL                            = 50770,
    SPELL_SUMMON_PLAYERS                        = 54164,
    SPELL_POWER_BALL_VISUAL                     = 54141,
};

#define SPELL_ARCANE_POWER DUNGEON_MODE<uint32>(54160,H_SPELL_ARCANE_POWER)
#define SPELL_POWER_BALL_DAMAGE_TRIGGER DUNGEON_MODE<uint32>(54207,59476)

enum Yells
{
    // Xevozz
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_CHARGED                                 = 4,
    SAY_REPEAT_SUMMON                           = 5,
    SAY_SUMMON_ENERGY                           = 6,

    // Ethereal Sphere
    SAY_ETHEREAL_SPHERE_SUMMON                  = 0
};

enum SphereActions
{
    ACTION_SUMMON                               = 1,
};

struct boss_xevozz : public BossAI
{
    boss_xevozz(Creature* creature) : BossAI(creature, DATA_XEVOZZ) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetData(DATA_HANDLE_CELLS, DATA_XEVOZZ);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        summon->GetMotionMaster()->MoveFollow(me, 0.0f, 0.0f);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ARCANE_POWER || spellInfo->Id == H_SPELL_ARCANE_POWER)
            Talk(SAY_SUMMON_ENERGY);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Seconds(8), Seconds(10), [this](TaskContext task)
        {
            DoCastAOE(SPELL_ARCANE_BARRAGE_VOLLEY);
            task.Repeat(Seconds(8), Seconds(10));
        });

        scheduler.Schedule(Seconds(10), Seconds(11), [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
                DoCast(target, SPELL_ARCANE_BUFFET);
            task.Repeat(Seconds(15), Seconds(20));
        });

        scheduler.Schedule(Seconds(5), [this](TaskContext task)
        {
            Talk(SAY_REPEAT_SUMMON);

            std::list<uint8> summonSpells = { 0, 1, 2 };

            uint8 spell = Trinity::Containers::SelectRandomContainerElement(summonSpells);
            DoCast(me, EtherealSphereSummonSpells[spell]);
            summonSpells.remove(spell);

            if (IsHeroic())
            {
                spell = Trinity::Containers::SelectRandomContainerElement(summonSpells);
                task.Schedule(Milliseconds(2500), [this, spell](TaskContext /*task*/)
                {
                    DoCast(me, EtherealSphereHeroicSummonSpells[spell]);
                });
            }

            task.Schedule(Seconds(33), Seconds(35), [this](TaskContext /*task*/)
            {
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_SUMMON, pred);
            });

            task.Repeat(Seconds(45), Seconds(47));
        });
    }
};

struct npc_ethereal_sphere : public ScriptedAI
{
    npc_ethereal_sphere(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        scheduler.CancelAll();
        ScheduledTasks();

        DoCast(me, SPELL_POWER_BALL_VISUAL);
        DoCast(me, SPELL_POWER_BALL_DAMAGE_TRIGGER);

        me->DespawnOrUnsummon(40s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SUMMON)
        {
            Talk(SAY_ETHEREAL_SPHERE_SUMMON);
            DoCastAOE(SPELL_SUMMON_PLAYERS);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

    void ScheduledTasks()
    {
        scheduler.Schedule(Seconds(1), [this](TaskContext task)
        {
            if (Creature* xevozz = instance->GetCreature(DATA_XEVOZZ))
            {
                if (me->IsWithinDist(xevozz, 3.0f))
                {
                    DoCastAOE(SPELL_ARCANE_POWER);
                    me->DespawnOrUnsummon(8s);
                    return;
                }
            }
            task.Repeat();
        });
    }

private:
    InstanceScript* instance;
    TaskScheduler scheduler;
};

// 54164 - Summon Players
class spell_xevozz_summon_players : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGIC_PULL });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGIC_PULL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_xevozz_summon_players::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_xevozz()
{
    RegisterVioletHoldCreatureAI(boss_xevozz);
    RegisterVioletHoldCreatureAI(npc_ethereal_sphere);
    RegisterSpellScript(spell_xevozz_summon_players);
}
