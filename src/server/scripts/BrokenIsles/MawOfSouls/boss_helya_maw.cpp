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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "maw_of_souls.h"

enum Spells
{
    // Helya Spells
    SPELL_HELYA_TORRENT_SIEGE   = 197805,
    SPELL_HELYA_TORRENT_BREACH  = 198495,
    SPELL_HELYA_WING_BUFFET     = 198520,
    SPELL_HELYA_CORRUPTED       = 227223,
    SPELL_HELYA_SUBMERGED       = 196947,
    SPELL_HELYA_BARRAGE         = 202088,

    // Destructor Tentacle Spells
    SPELL_DESTRUCTOR_SMASH      = 196534,
    SPELL_DESTRUCTOR_RUPTURE    = 185539,

    // Grasping Tentacle Spells


    // Piercing Tentacle Spells
    SPELL_PIERCING_TENTACLE     = 197117,
};

enum CreaturesIds
{
    NPC_DESTRUCTOR_TENTACLE     = 99801, // Level 112
    NPC_GRASPING_TENTACLE       = 100360, // Level 111
    NPC_PIERCING_TENTACLE       = 100188, // No idea about level, probably 112 to match instance avg level
};

enum Auras
{
    AURA_HELYA_TAINT = 197262
};

enum Yells
{
    YELL_PRE_ENCOUNTER  = 0,
    YELL_ENTER_COMBAT   = 1,
    YELL_TAINT          = 2,
    YELL_TENTACLE       = 3,
    YELL_CORRUPTED      = 4,
    YELL_KILL           = 5,
    YELL_WIPE           = 6,
    YELL_KILLED         = 7
};

enum Events
{
    EVENT_TAINT     = 1,
    EVENT_BARRAGE   = 2
};

enum Phases
{
    PHASE_SIEGE     = 0,
    PHASE_SUBMERGE  = 1,
    PHASE_BREACH    = 2
};

struct boss_helya_maw : public BossAI
{
    boss_helya_maw(Creature* creature) : BossAI(creature, DATA_HELYA_MAW) { }

    void Reset() override
    {
        _Reset();

        SetCombatMovement(false);
        DifficultyModifier();
        Phase = PHASE_SIEGE;

        if (isHeroic || isMythic)
        {
            events.ScheduleEvent(EVENT_TAINT, 1 * IN_MILLISECONDS, PHASE_SIEGE);
            events.ScheduleEvent(EVENT_BARRAGE, 42 * IN_MILLISECONDS, PHASE_SIEGE);
        }
    }

    void DifficultyModifier()
    {
        Difficulty instanceDifficulty = instance->instance->GetDifficultyID();
        double healthModifier = 20;
        double damageModifier = 20;

        if(instanceDifficulty == DIFFICULTY_NORMAL)
        {
            healthModifier = 1.0;
            damageModifier = 1.0;
        }
        else if(instanceDifficulty == DIFFICULTY_HEROIC)
        {
            healthModifier = 1.29687495317; // HealthModifier 36.99
            damageModifier = 1.30167051743;
            isHeroic = true;
        }
        else if(instanceDifficulty == DIFFICULTY_MYTHIC)
        {
            healthModifier = 1.62109363383; // HealthModifier 46.25
            damageModifier = 1.82000519133;
            isMythic = true;
        }

        uint64 difficultyAdjustedHealth = static_cast<unsigned long long>(me->GetHealth() * healthModifier);
        me->SetMaxHealth(difficultyAdjustedHealth);
        me->SetHealth(difficultyAdjustedHealth);
        me->SetModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_VALUE, static_cast<float>(damageModifier));
    }

    void EnterCombat(Unit* victim) override
    {
        BossAI::EnterCombat(victim);
        Talk(YELL_ENTER_COMBAT);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(YELL_KILLED);
    }

    void KilledUnit(Unit* victim) override
    {
        if(victim->GetTypeId() == TYPEID_PLAYER)
            Talk(YELL_KILL);
    }

    void JustSummoned(Creature* /*summoned*/) override
    {

    }

    void EnterNextPhase()
    {

    }

    void UpdateAI(uint32 diff) override
    {
        if (Phase >= PHASE_BREACH)
        {
            if(!UpdateVictim())
                return;
        }

        events.Update(diff);

        while(uint32 eventID = events.ExecuteEvent())
        {
            switch(eventID)
            {
                case EVENT_TAINT:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        if(!target->HasAura(AURA_HELYA_TAINT))
                            DoCast(target, AURA_HELYA_TAINT, false);
                    break;

                case EVENT_BARRAGE:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_HELYA_BARRAGE);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    private:
        uint8 Phase;
        //SummonList summons;
        bool isHeroic = false;
        bool isMythic = false;
};

// NPC 99801
struct npc_helya_maw_destructor_tentacle : public ScriptedAI
{
    npc_helya_maw_destructor_tentacle(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        DoCastVictim(SPELL_DESTRUCTOR_RUPTURE);
        me->GetScheduler().CancelAll();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->GetScheduler().Schedule(5s, [this](TaskContext context)
        {
            if (!playerInRange)
                DoCastAOE(SPELL_DESTRUCTOR_SMASH);

            context.Repeat();
        });

        me->GetScheduler().Schedule(5s, [this](TaskContext context)
        {
            if (playerInRange)
            {
                DoCastAOE(SPELL_DESTRUCTOR_SMASH);
                context.Repeat(14s);
            }
            else
                context.Repeat(1s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if(Creature* helya = instance->GetCreature(NPC_HELYA_MAW))
        {
            helya->AI()->Talk(YELL_TENTACLE);
            uint64 damagePerTentacle = helya->GetMaxHealth() * 0.0333;
            uint64 newHealth = helya->GetHealth() - damagePerTentacle;
            helya->SetHealth(newHealth);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        playerInRange = who->IsPlayer() && me->GetDistance2d(who) < 3.0f;
    }

    private:
        bool playerInRange = false;
};

void AddSC_boss_helya_maw()
{
    RegisterCreatureAI(boss_helya_maw);
    RegisterCreatureAI(npc_helya_maw_destructor_tentacle);
}
