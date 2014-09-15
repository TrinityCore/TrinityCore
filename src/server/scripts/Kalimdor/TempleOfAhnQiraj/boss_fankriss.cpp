/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Fankriss
SD%Complete: 100
SDComment: sound not implemented
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define SOUND_SENTENCE_YOU 8588
#define SOUND_SERVE_TO     8589
#define SOUND_LAWS         8590
#define SOUND_TRESPASS     8591
#define SOUND_WILL_BE      8592

enum Spells
{
    SPELL_MORTAL_WOUND      = 28467,
    SPELL_ROOT              = 28858,

    // Enrage for his spawns
    SPELL_ENRAGE            = 28798
};

class boss_fankriss : public CreatureScript
{
public:
    boss_fankriss() : CreatureScript("boss_fankriss") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_fankrissAI(creature);
    }

    struct boss_fankrissAI : public ScriptedAI
    {
        boss_fankrissAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            MortalWound_Timer = urand(10000, 15000);
            SpawnHatchlings_Timer = urand(6000, 12000);
            SpawnSpawns_Timer = urand(15000, 45000);
        }

        uint32 MortalWound_Timer;
        uint32 SpawnHatchlings_Timer;
        uint32 SpawnSpawns_Timer;

        void Reset() override
        {
            Initialize();
        }

        void SummonSpawn(Unit* victim)
        {
            if (!victim)
                return;

            int Rand = 10 + (rand32() % 10);
            float RandX = 0.f;
            float RandY = 0.f;

            switch (rand32() % 2)
            {
                case 0: RandX = 0.0f - Rand; break;
                case 1: RandX = 0.0f + Rand; break;
            }

            Rand = 10 + (rand32() % 10);
            switch (rand32() % 2)
            {
                case 0: RandY = 0.0f - Rand; break;
                case 1: RandY = 0.0f + Rand; break;
            }
            Rand = 0;
            Creature* Spawn = DoSpawnCreature(15630, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            if (Spawn)
                Spawn->AI()->AttackStart(victim);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //MortalWound_Timer
            if (MortalWound_Timer <= diff)
            {
                DoCastVictim(SPELL_MORTAL_WOUND);
                MortalWound_Timer = urand(10000, 20000);
            } else MortalWound_Timer -= diff;

            //Summon 1-3 Spawns of Fankriss at random time.
            if (SpawnSpawns_Timer <= diff)
            {
                switch (urand(0, 2))
                {
                    case 0:
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        break;
                    case 1:
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        break;
                    case 2:
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        SummonSpawn(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        break;
                }
                SpawnSpawns_Timer = urand(30000, 60000);
            } else SpawnSpawns_Timer -= diff;

            // Teleporting Random Target to one of the three tunnels and spawn 4 hatchlings near the gamer.
            //We will only telport if fankriss has more than 3% of hp so teleported gamers can always loot.
            if (HealthAbovePct(3))
            {
                if (SpawnHatchlings_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    {
                        DoCast(target, SPELL_ROOT);

                        if (DoGetThreat(target))
                            DoModifyThreatPercent(target, -100);

                        Creature* Hatchling = nullptr;
                        switch (urand(0, 2))
                        {
                            case 0:
                                DoTeleportPlayer(target, -8106.0142f, 1289.2900f, -74.419533f, 5.112f);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-3, target->GetPositionY()-3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-3, target->GetPositionY()+3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()-5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()+5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                break;
                            case 1:
                                DoTeleportPlayer(target, -7990.135354f, 1155.1907f, -78.849319f, 2.608f);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX() - 3, target->GetPositionY() - 3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-3, target->GetPositionY()+3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()-5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()+5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                break;
                            case 2:
                                DoTeleportPlayer(target, -8159.7753f, 1127.9064f, -76.868660f, 0.675f);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX() - 3, target->GetPositionY() - 3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-3, target->GetPositionY()+3, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()-5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                Hatchling = me->SummonCreature(15962, target->GetPositionX()-5, target->GetPositionY()+5, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (Hatchling)
                                    Hatchling->AI()->AttackStart(target);
                                break;
                        }
                    }
                    SpawnHatchlings_Timer = urand(45000, 60000);
                } else SpawnHatchlings_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_fankriss()
{
    new boss_fankriss();
}
