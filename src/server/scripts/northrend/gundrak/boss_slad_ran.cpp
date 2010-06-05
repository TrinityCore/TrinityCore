/*
* Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "ScriptedPch.h"
#include "gundrak.h"

//Spells
enum Spells
{
    SPELL_POISON_NOVA                             = 55081,
    H_SPELL_POISON_NOVA                           = 59842,
    SPELL_POWERFULL_BITE                          = 48287,
    H_SPELL_POWERFULL_BITE                        = 59840,
    SPELL_VENOM_BOLT                              = 54970,
    H_SPELL_VENOM_BOLT                            = 59839
};

//Yell
enum Yells
{
    SAY_AGGRO                                     = -1604017,
    SAY_SLAY_1                                    = -1604018,
    SAY_SLAY_2                                    = -1604019,
    SAY_SLAY_3                                    = -1604020,
    SAY_DEATH                                     = -1604021,
    SAY_SUMMON_SNAKES                             = -1604022,
    SAY_SUMMON_CONSTRICTORS                       = -1604023
};

//Creatures
enum Creatures
{
    CREATURE_SNAKE                                = 29680,
    CREATURE_CONSTRICTORS                         = 29713
};

//Creatures' spells
enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                        = 55093,
    SPELL_VENOMOUS_BITE                           = 54987,
    H_SPELL_VENOMOUS_BITE                         = 58996
};

static Position SpawnLoc[]=
{
  {1783.81, 646.637, 133.948, 3.71755},
  {1775.03, 606.586, 134.165, 1.43117},
  {1717.39, 630.041, 129.282, 5.96903},
  {1765.66, 646.542, 134.02,  5.11381},
  {1716.76, 635.159, 129.282, 0.191986}
};

struct boss_slad_ranAI : public ScriptedAI
{
    boss_slad_ranAI(Creature *c) : ScriptedAI(c), lSummons(me)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiPoisonNovaTimer;
    uint32 uiPowerfullBiteTimer;
    uint32 uiVenomBoltTimer;
    uint32 uiSpawnTimer;

    uint8 uiPhase;

    SummonList lSummons;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiPoisonNovaTimer = 10*IN_MILISECONDS;
        uiPowerfullBiteTimer = 3*IN_MILISECONDS;
        uiVenomBoltTimer = 15*IN_MILISECONDS;
        uiSpawnTimer = 5*IN_MILISECONDS;
        uiPhase = 0;

        lSummons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiPoisonNovaTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_POISON_NOVA);
            uiPoisonNovaTimer = 15*IN_MILISECONDS;
        } else uiPoisonNovaTimer -= diff;

        if (uiPowerfullBiteTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_POWERFULL_BITE);
            uiPowerfullBiteTimer = 10*IN_MILISECONDS;
        } else uiPowerfullBiteTimer -= diff;

        if (uiVenomBoltTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_VENOM_BOLT);
            uiVenomBoltTimer = 10*IN_MILISECONDS;
        } else uiVenomBoltTimer -= diff;

        if (uiPhase)
        {
            if (uiSpawnTimer <= diff)
            {
                if (uiPhase == 1)
                    for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                        me->SummonCreature(CREATURE_SNAKE, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILISECONDS);
                if (uiPhase == 2)
                    for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                        me->SummonCreature(CREATURE_CONSTRICTORS, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILISECONDS);
                uiSpawnTimer = 5*IN_MILISECONDS;
            } else uiSpawnTimer -= diff;
        }

        if (uiPhase == 0 && HealthBelowPct(30))
        {
            DoScriptText(SAY_SUMMON_SNAKES,me);
            uiPhase = 1;
        }

        if (uiPhase == 1 && HealthBelowPct(25))
        {
            DoScriptText(SAY_SUMMON_CONSTRICTORS,me);
            uiPhase = 2;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, DONE);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->GetMotionMaster()->MovePoint(0,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ());
        lSummons.Summon(summoned);
    }
};

struct mob_slad_ran_constrictorAI : public ScriptedAI
{
    mob_slad_ran_constrictorAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiGripOfSladRanTimer;

    void Reset()
    {
        uiGripOfSladRanTimer = 1*IN_MILISECONDS;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (uiGripOfSladRanTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_GRIP_OF_SLAD_RAN);
            uiGripOfSladRanTimer = 5*IN_MILISECONDS;
        } else uiGripOfSladRanTimer -= diff;
    }

    ScriptedInstance* pInstance;
};

struct mob_slad_ran_viperAI : public ScriptedAI
{
    mob_slad_ran_viperAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiVenomousBiteTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiVenomousBiteTimer = 2*IN_MILISECONDS;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiVenomousBiteTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_VENOMOUS_BITE);
            uiVenomousBiteTimer = 10*IN_MILISECONDS;
        } else uiVenomousBiteTimer -= diff;
    }
};

CreatureAI* GetAI_boss_slad_ran(Creature* pCreature)
{
    return new boss_slad_ranAI (pCreature);
}

CreatureAI* GetAI_mob_slad_ran_constrictor(Creature* pCreature)
{
    return new mob_slad_ran_constrictorAI (pCreature);
}

CreatureAI* GetAI_mob_slad_ran_viper(Creature* pCreature)
{
    return new mob_slad_ran_viperAI (pCreature);
}

void AddSC_boss_slad_ran()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_slad_ran";
    newscript->GetAI = &GetAI_boss_slad_ran;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_slad_ran_constrictor";
    newscript->GetAI = &GetAI_mob_slad_ran_constrictor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_slad_ran_viper";
    newscript->GetAI = &GetAI_mob_slad_ran_viper;
    newscript->RegisterSelf();
}
