/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

enum CreaturesIds {
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

class boss_helya_maw : public CreatureScript
{
public:
    boss_helya_maw() : CreatureScript("boss_helya_maw") {}

    struct boss_helya_mawAI : public BossAI
    {
        boss_helya_mawAI(Creature* creature) : BossAI(creature, DATA_HELYA_MAW)
        {
            Initialize();
            SetCombatMovement(false);
        }

        void Initialize()
        {
            DifficultyModifier();
            Phase = PHASE_SIEGE;

            if(isHeroic || isMythic)
            {
                events.ScheduleEvent(EVENT_TAINT, 1 * IN_MILLISECONDS, PHASE_SIEGE);
                events.ScheduleEvent(EVENT_BARRAGE, 42 * IN_MILLISECONDS, PHASE_SIEGE);
            }
        }

        void Reset() override
        {
            _Reset();
            Initialize();
            //summons.DespawnAll();
        }

        void DifficultyModifier()
        {
            Difficulty instanceDifficulty = instance->instance->GetDifficultyID();
            uint64 myHealth = me->GetHealth();
            double healthModifier;
            double damageModifier;

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
            else
            {
                healthModifier = 20;
                damageModifier = 20;
            }

            uint64 difficultyAdjustedHealth = static_cast<unsigned long long>(myHealth * healthModifier);
            me->SetMaxHealth(difficultyAdjustedHealth);
            me->SetHealth(difficultyAdjustedHealth);
            me->SetModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_VALUE, static_cast<float>(damageModifier));
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            instance->SetBossState(DATA_HELYA_MAW, IN_PROGRESS);
            Talk(YELL_ENTER_COMBAT);
            DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(YELL_KILLED);
            //summons.DespawnAll();
            instance->SetBossState(DATA_HELYA_MAW, DONE);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SetBossState(DATA_HELYA_MAW, FAIL);
            //summons.DespawnAll();
            me->CombatStop();
            me->DespawnOrUnsummon();
            me->SetCorpseDelay(5);
            me->SetRespawnDelay(10);
            me->RemoveAllAuras();
            events.Reset();
            Initialize();
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

            if(Phase < PHASE_BREACH)
            {

            }
            else
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<boss_helya_mawAI>(creature);
    }
};

// NPC 99801
class npc_helya_maw_destructor_tentacle : public CreatureScript
{
    public:
        npc_helya_maw_destructor_tentacle() : CreatureScript("npc_helya_maw_destructor_tentacle") { }

        struct npc_helya_maw_destructor_tentacleAI : public ScriptedAI
        {
            npc_helya_maw_destructor_tentacleAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                SetCombatMovement(false);
                Initialize();
            }

            void Initialize()
            {
                DoCastVictim(SPELL_DESTRUCTOR_RUPTURE);
            }

            void EnterCombat(Unit* /*who*/) override
            {

            }

            void JustDied(Unit* /*killer*/) override
            {
                if(Creature* helya = ObjectAccessor::GetCreature((*me), instance->GetGuidData(DATA_HELYA_MAW)))
                {
                    helya->AI()->Talk(YELL_TENTACLE);
                    uint64 damagePerTentacle = helya->GetMaxHealth() * 0.0333;
                    uint64 newHealth = helya->GetHealth() - damagePerTentacle;
                    helya->SetHealth(newHealth);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if(!UpdateVictim())
                    return;

                if(presenseCheck <= diff)
                {
                    if (!playerInRange)
                        DoCastAOE(SPELL_DESTRUCTOR_SMASH);

                    presenseCheck = 5 * IN_MILLISECONDS;
                }
                else
                    presenseCheck -= diff;

                if(ruptureEvery <= diff)
                {
                    if(playerInRange)
                    {
                        DoCastVictim(SPELL_DESTRUCTOR_RUPTURE);
                        ruptureEvery = 14 * IN_MILLISECONDS;
                    }
                    else
                    {
                        ruptureEvery = 1 * IN_MILLISECONDS;
                    }

                }
                else
                    ruptureEvery -= diff;

                DoMeleeAttackIfReady();
            }

            void MoveInLineOfSight(Unit* who) override
            {
                playerInRange = (who->GetTypeId() == TYPEID_PLAYER && me->GetDistance2d(who) < 3.0f) ? true : false;
            }

            private:
                InstanceScript* instance;
                uint32 ruptureEvery = 14 * IN_MILLISECONDS;
                uint32 presenseCheck = 5 * IN_MILLISECONDS;
                bool playerInRange = false;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMawOfSoulsAI<npc_helya_maw_destructor_tentacleAI>(creature);
        }
};

void AddSC_boss_helya_maw()
{
    new boss_helya_maw();
    new npc_helya_maw_destructor_tentacle();
}
