/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Comment: TODO: spawn troll waves
 */

#include "ScriptPCH.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_INFECTED_WOUND                          = 49637,
    SPELL_CRUSH                                   = 49639,
    SPELL_CORPSE_EXPLODE                          = 49555,
    SPELL_CONSUME                                 = 49380,
    SPELL_CONSUME_AURA                            = 49381,
    //Heroic spells
    H_SPELL_CORPSE_EXPLODE                        = 59807,
    H_SPELL_CONSUME                               = 59803,
    H_SPELL_CONSUME_AURA                          = 59805,
};
enum Yells
{
    SAY_AGGRO                                     = -1600006,
    SAY_KILL                                      = -1600007,
    SAY_CONSUME                                   = -1600008,
    SAY_EXPLODE                                   = -1600009,
    SAY_DEATH                                     = -1600010
};
enum Achievements
{
    ACHIEV_CONSUMPTION_JUNCTION                   = 2151
};
enum Creatures
{
    NPC_DRAKKARI_INVADER_1                        = 27753,
    NPC_DRAKKARI_INVADER_2                        = 27709
};

Position AddSpawnPoint = { -260.493011, -622.968018, 26.605301, 3.036870 };

class boss_trollgore : public CreatureScript
{
public:
    boss_trollgore() : CreatureScript("boss_trollgore") { }

    struct boss_trollgoreAI : public ScriptedAI
    {
        boss_trollgoreAI(Creature *c) : ScriptedAI(c), lSummons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiConsumeTimer;
        uint32 uiAuraCountTimer;
        uint32 uiCrushTimer;
        uint32 uiInfectedWoundTimer;
        uint32 uiExplodeCorpseTimer;
        uint32 uiSpawnTimer;

        bool bAchiev;

        SummonList lSummons;

        InstanceScript* pInstance;

        void Reset()
        {
            uiConsumeTimer = 15*IN_MILLISECONDS;
            uiAuraCountTimer = 15.5*IN_MILLISECONDS;
            uiCrushTimer = urand(1*IN_MILLISECONDS,5*IN_MILLISECONDS);
            uiInfectedWoundTimer = urand(60*IN_MILLISECONDS,10*IN_MILLISECONDS);
            uiExplodeCorpseTimer = 3*IN_MILLISECONDS;
            uiSpawnTimer = urand(30*IN_MILLISECONDS,40*IN_MILLISECONDS);

            bAchiev = IsHeroic();

            lSummons.DespawnAll();

            me->RemoveAura(DUNGEON_MODE(SPELL_CONSUME_AURA,H_SPELL_CONSUME_AURA));

            if (pInstance)
                pInstance->SetData(DATA_TROLLGORE_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_TROLLGORE_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiSpawnTimer <= diff)
            {
                uint32 spawnNumber = urand(2,DUNGEON_MODE(3,5));
                for (uint8 i = 0; i < spawnNumber; ++i)
                    DoSummon(RAND(NPC_DRAKKARI_INVADER_1,NPC_DRAKKARI_INVADER_2), AddSpawnPoint, 0, TEMPSUMMON_DEAD_DESPAWN);
                uiSpawnTimer = urand(30*IN_MILLISECONDS,40*IN_MILLISECONDS);
            } else uiSpawnTimer -= diff;

            if (uiConsumeTimer <= diff)
            {
                DoScriptText(SAY_CONSUME, me);
                DoCast(SPELL_CONSUME);
                uiConsumeTimer = 15*IN_MILLISECONDS;
            } else uiConsumeTimer -= diff;

            if (bAchiev)
            {
                Aura *pConsumeAura = me->GetAura(DUNGEON_MODE(SPELL_CONSUME_AURA,H_SPELL_CONSUME_AURA));
                if (pConsumeAura && pConsumeAura->GetStackAmount() > 9)
                    bAchiev = false;
            }

            if (uiCrushTimer <= diff)
            {
                DoCastVictim(SPELL_CRUSH);
                uiCrushTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
            } else uiCrushTimer -= diff;

            if (uiInfectedWoundTimer <= diff)
            {
                DoCastVictim(SPELL_INFECTED_WOUND);
                uiInfectedWoundTimer = urand(25*IN_MILLISECONDS,35*IN_MILLISECONDS);
            } else uiInfectedWoundTimer -= diff;

            if (uiExplodeCorpseTimer <= diff)
            {
                DoCast(SPELL_CORPSE_EXPLODE);
                DoScriptText(SAY_EXPLODE, me);
                uiExplodeCorpseTimer = urand(15*IN_MILLISECONDS,19*IN_MILLISECONDS);
            } else uiExplodeCorpseTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            lSummons.DespawnAll();

            if (pInstance)
            {
                if (bAchiev)
                    pInstance->DoCompleteAchievement(ACHIEV_CONSUMPTION_JUNCTION);
                pInstance->SetData(DATA_TROLLGORE_EVENT, DONE);
            }
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;
            DoScriptText(SAY_KILL, me);
        }

        void JustSummoned(Creature* summon)
        {
            lSummons.push_back(summon->GetGUID());
            if (summon->AI())
                summon->AI()->AttackStart(me);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new boss_trollgoreAI(creature);
    }
};

void AddSC_boss_trollgore()
{
    new boss_trollgore;
}
