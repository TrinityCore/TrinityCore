/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Morogrim_Tidewalker
SD%Complete: 90
SDComment: Water globules don't explode properly, remove hacks
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "serpent_shrine.h"

#define SAY_AGGRO                   -1548030
#define SAY_SUMMON1                 -1548031
#define SAY_SUMMON2                 -1548032
#define SAY_SUMMON_BUBL1            -1548033
#define SAY_SUMMON_BUBL2            -1548034
#define SAY_SLAY1                   -1548035
#define SAY_SLAY2                   -1548036
#define SAY_SLAY3                   -1548037
#define SAY_DEATH                   -1548038
#define EMOTE_WATERY_GRAVE          -1548039
#define EMOTE_EARTHQUAKE            -1548040
#define EMOTE_WATERY_GLOBULES       -1548041

#define SPELL_TIDAL_WAVE            37730
#define SPELL_WATERY_GRAVE          38049
#define SPELL_EARTHQUAKE            37764
#define SPELL_WATERY_GRAVE_EXPLOSION 37852

#define WATERY_GRAVE_X1             334.64
#define WATERY_GRAVE_Y1             -728.89
#define WATERY_GRAVE_Z1             -14.42
#define WATERY_GRAVE_X2             365.51
#define WATERY_GRAVE_Y2             -737.14
#define WATERY_GRAVE_Z2             -14.44
#define WATERY_GRAVE_X3             366.19
#define WATERY_GRAVE_Y3             -709.59
#define WATERY_GRAVE_Z3             -14.36
#define WATERY_GRAVE_X4             372.93
#define WATERY_GRAVE_Y4             -690.96
#define WATERY_GRAVE_Z4             -14.44

#define SPELL_WATERY_GRAVE_1    38023
#define SPELL_WATERY_GRAVE_2    38024
#define SPELL_WATERY_GRAVE_3    38025
#define SPELL_WATERY_GRAVE_4    37850

#define SPELL_SUMMON_WATER_GLOBULE_1    37854
#define SPELL_SUMMON_WATER_GLOBULE_2    37858
#define SPELL_SUMMON_WATER_GLOBULE_3    37860
#define SPELL_SUMMON_WATER_GLOBULE_4    37861

/*#define SPELL_SUMMON_MURLOC_A6    39813
#define SPELL_SUMMON_MURLOC_A7  39814
#define SPELL_SUMMON_MURLOC_A8  39815
#define SPELL_SUMMON_MURLOC_A9  39816
#define SPELL_SUMMON_MURLOC_A10 39817

#define SPELL_SUMMON_MURLOC_B6  39818
#define SPELL_SUMMON_MURLOC_B7  39819
#define SPELL_SUMMON_MURLOC_B8  39820
#define SPELL_SUMMON_MURLOC_B9  39821
#define SPELL_SUMMON_MURLOC_B10 39822*/

float MurlocCords[10][5] =
{
      {21920, 424.36, -715.4, -7.14, 0.124},
       {21920, 425.13, -719.3, -7.14, 0.124},
       {21920, 425.05, -724.23, -7.14, 0.124},
       {21920, 424.91, -728.68, -7.14, 0.124},
      {21920, 424.84, -732.18, -7.14, 0.124},
       {21920, 321.05, -734.2, -13.15, 0.124},
       {21920, 321.05, -729.4, -13.15, 0.124},
       {21920, 321.05, -724.03, -13.15, 0.124},
      {21920, 321.05, -718.73, -13.15, 0.124},
       {21920, 321.05, -714.24, -13.15, 0.124}
};

//Creatures
#define WATER_GLOBULE               21913
#define TIDEWALKER_LURKER           21920

//Morogrim Tidewalker AI
struct TRINITY_DLL_DECL boss_morogrim_tidewalkerAI : public ScriptedAI
{
    boss_morogrim_tidewalkerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    Map::PlayerList const *PlayerList;

    uint32 TidalWave_Timer;
    uint32 WateryGrave_Timer;
    uint32 Earthquake_Timer;
    uint32 WateryGlobules_Timer;
    uint32 globulespell[4];
    int8 Playercount;
    int8 counter;

    bool Earthquake;
    bool Phase2;

    void Reset()
    {
        TidalWave_Timer = 10000;
        WateryGrave_Timer = 30000;
        Earthquake_Timer = 40000;
        WateryGlobules_Timer = 0;
        globulespell[0] = SPELL_SUMMON_WATER_GLOBULE_1;
        globulespell[1] = SPELL_SUMMON_WATER_GLOBULE_2;
        globulespell[2] = SPELL_SUMMON_WATER_GLOBULE_3;
        globulespell[3] = SPELL_SUMMON_WATER_GLOBULE_4;

        Earthquake = false;
        Phase2 = false;

        if (pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
    }

    void StartEvent()
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2,SAY_SLAY3), m_creature);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, DONE);
    }

    void EnterCombat(Unit *who)
    {
        PlayerList = &m_creature->GetMap()->GetPlayers();
        Playercount = PlayerList->getSize();
        StartEvent();
    }

    void ApplyWateryGrave(Unit* pPlayer, uint8 i)
    {
        switch(i)
        {
        case 0: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_1, true); break;
        case 1: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_2, true); break;
        case 2: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_3, true); break;
        case 3: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_4, true); break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Earthquake_Timer
        if (Earthquake_Timer <= diff)
        {
            if (!Earthquake)
            {
                DoCast(m_creature->getVictim(), SPELL_EARTHQUAKE);
                Earthquake = true;
                Earthquake_Timer = 10000;
            }
            else
            {
                DoScriptText(RAND(SAY_SUMMON1,SAY_SUMMON2), m_creature);

                for (uint8 i = 0; i < 10; ++i)
                {
                    Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    Creature* Murloc = m_creature->SummonCreature(MurlocCords[i][0],MurlocCords[i][1],MurlocCords[i][2],MurlocCords[i][3],MurlocCords[i][4], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                    if (pTarget && Murloc)
                        Murloc->AI()->AttackStart(pTarget);
                }
                DoScriptText(EMOTE_EARTHQUAKE, m_creature);
                Earthquake = false;
                Earthquake_Timer = 40000+rand()%5000;
            }
        } else Earthquake_Timer -= diff;

        //TidalWave_Timer
        if (TidalWave_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_TIDAL_WAVE);
            TidalWave_Timer = 20000;
        } else TidalWave_Timer -= diff;

        if (!Phase2)
        {
            //WateryGrave_Timer
            if (WateryGrave_Timer <= diff)
            {
                //Teleport 4 players under the waterfalls
                Unit *pTarget;
                using std::set;
                set<int>list;
                set<int>::iterator itr;
                for (uint8 i = 0; i < 4; ++i)
                {
                    counter = 0;
                    do{pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);    //target players only
                    if (counter < Playercount)
                        break;
                    if (pTarget) itr = list.find(pTarget->GetGUID());
                    counter++;
                    }while(itr != list.end());
                    if (pTarget){list.insert(pTarget->GetGUID());
                    ApplyWateryGrave(pTarget, i);
                    }
                }

                DoScriptText(RAND(SAY_SUMMON_BUBL1,SAY_SUMMON_BUBL2), m_creature);

                DoScriptText(EMOTE_WATERY_GRAVE, m_creature);
                WateryGrave_Timer = 30000;
            } else WateryGrave_Timer -= diff;

            //Start Phase2
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
                Phase2 = true;
        }
        else
        {
            //WateryGlobules_Timer
            if (WateryGlobules_Timer <= diff)
            {
                Unit* pGlobuleTarget;
                using std::set;
                set<int>globulelist;
                set<int>::iterator itr;
                for (uint8 g = 0; g < 4; g++)  //one unit can't cast more than one spell per update, so some players have to cast for us XD
                {
                    counter = 0;
                    do {
                        pGlobuleTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                        if (pGlobuleTarget)
                            itr = globulelist.find(pGlobuleTarget->GetGUID());
                        if (counter > Playercount)
                            break;
                        ++counter;
                    } while (itr != globulelist.end());
                    if (pGlobuleTarget)
                        globulelist.insert(pGlobuleTarget->GetGUID());
                    pGlobuleTarget->CastSpell(pGlobuleTarget, globulespell[g], true);
                }
                DoScriptText(EMOTE_WATERY_GLOBULES, m_creature);
                WateryGlobules_Timer = 25000;
            } else WateryGlobules_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

//Water Globule AI
#define SPELL_GLOBULE_EXPLOSION 37871

struct TRINITY_DLL_DECL mob_water_globuleAI : public ScriptedAI
{
    mob_water_globuleAI(Creature *c) : ScriptedAI(c) {}

    uint32 Check_Timer;

    void Reset()
    {
        Check_Timer = 1000;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setFaction(14);
    }

    void EnterCombat(Unit *who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            //no attack radius check - it attacks the first target that moves in his los
            //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
            AttackStart(who);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (Check_Timer <= diff)
        {
            if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 5))
            {
                DoCast(m_creature->getVictim(), SPELL_GLOBULE_EXPLOSION);

                //despawn
                m_creature->ForcedDespawn();
                return;
            }
            Check_Timer = 500;
        } else Check_Timer -= diff;

        //do NOT deal any melee damage to the target.
    }
};

CreatureAI* GetAI_boss_morogrim_tidewalker(Creature* pCreature)
{
    return new boss_morogrim_tidewalkerAI (pCreature);
}
CreatureAI* GetAI_mob_water_globule(Creature* pCreature)
{
    return new mob_water_globuleAI (pCreature);
}

void AddSC_boss_morogrim_tidewalker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_morogrim_tidewalker";
    newscript->GetAI = &GetAI_boss_morogrim_tidewalker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_water_globule";
    newscript->GetAI = &GetAI_mob_water_globule;
    newscript->RegisterSelf();
}

