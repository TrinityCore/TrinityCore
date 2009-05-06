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
SDName: Boss_KelThuzud
SD%Complete: 0
SDComment: VERIFY SCRIPT
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//when shappiron dies. dialog between kel and lich king (in this order)
#define SAY_SAPP_DIALOG1            -1533084
#define SAY_SAPP_DIALOG2_LICH       -1533085
#define SAY_SAPP_DIALOG3            -1533086
#define SAY_SAPP_DIALOG4_LICH       -1533087
#define SAY_SAPP_DIALOG5            -1533088

//when cat dies
#define SAY_CAT_DIED                -1533089

//when each of the 4 wing bosses dies
#define SAY_TAUNT1                  -1533090
#define SAY_TAUNT2                  -1533091
#define SAY_TAUNT3                  -1533092
#define SAY_TAUNT4                  -1533093

#define SAY_SUMMON_MINIONS          -1533105                //start of phase 1

#define SAY_AGGRO1                  -1533094                //start of phase 2
#define SAY_AGGRO2                  -1533095
#define SAY_AGGRO3                  -1533096

#define SAY_SLAY1                   -1533097
#define SAY_SLAY2                   -1533098

#define SAY_DEATH                   -1533099

#define SAY_CHAIN1                  -1533100
#define SAY_CHAIN2                  -1533101
#define SAY_FROST_BLAST             -1533102

#define SAY_REQUEST_AID             -1533103                //start of phase 3
#define SAY_ANSWER_REQUEST          -1533104                //lich king answer

#define SAY_SPECIAL1_MANA_DET       -1533106
#define SAY_SPECIAL3_MANA_DET       -1533107
#define SAY_SPECIAL2_DISPELL        -1533108

//***THIS SCRIPTS IS UNDER DEVELOPMENT***
/*
DATA.
This script has been made with info taken from wowwikki... so there are things wrong...
like spell timers and Says. Also there's another major problem as there is no aggroed list
I cannot make Kel'thuzad to target specific party members, that is needed for spells like
Mana Detonation... so what I'm doing untill now is just to cast everything on my main aggroed
target. Sorry for him.
Another bug is that there are spells that are actually NOT working... I have to implement
them first.
Need DISPELL efect
I also don't know the emotes
*/

//common needed defines
#define NAXXRAMAS_MAP                533
//Positional defines

#define SPELL_FROST_BOLT            HEROIC(28478,55802)
#define SPELL_FROST_BOLT_AOE        HEROIC(28479,55807)
#define SPELL_SHADOW_FISURE         27810
#define SPELL_VOID_BLAST            27812
#define SPELL_MANA_DETONATION       27819
#define SPELL_FROST_BLAST           27808
#define SPELL_CHAINS_OF_KELTHUZAD   28410 //28408 script effect
#define SPELL_BERSERK               28498

#define MOB_WASTE                   16427 // Soldiers of the Frozen Wastes
#define MOB_ABOMINATION             16428 // Unstoppable Abominations
#define MOB_WEAVER                  16429 // Soul Weavers
#define MOB_FISSURE                 16129 // Shadow Fissure
#define MOB_ICECROWN                16441 // Guardians of Icecrown

float Pos[12][4] =
{
    {3783.272705, -5062.697266, 143.711203,3.617599},//LEFT_FAR
    {3730.291260, -5027.239258,143.956909,4.461900},//LEFT_MIDDLE
    {3683.868652,-5057.281250,143.183884,5.237086},//LEFT_NEAR
    {3759.355225,-5174.128418,143.802383,2.170104},//RIGHT_FAR
    {370.724365,-5185.123047,143.928024,1.309310},//RIGHT_MIDDLE
    {3665.121094,-5138.679199,143.183212,0.604023},//RIGHT_NEAR
    {3754.431396,-5080.727734,142.036316,3.736189},//LEFT_FAR
    {3724.396484, -5061.330566,142.032700, 4.564785},//LEFT_MIDDLE
    {3687.158424,-5076.834473,142.017319,5.237086},//LEFT_NEAR
    {3687.571777,-5126.831055,142.017807,0.604023},//RIGHT_FAR
    {3707.990733,-5151.450195,142.032562,1.376855},//RIGHT_MIDDLE
    {3739.500000,-5141.883989,142.0141130, 2.121412}//RIGHT_NEAR
};

struct TRINITY_DLL_DECL boss_kelthuzadAI : public ScriptedAI
{
    boss_kelthuzadAI(Creature* c) : ScriptedAI(c)
    {
        GuardiansOfIcecrown[0] = 0;
        GuardiansOfIcecrown[1] = 0;
        GuardiansOfIcecrown[2] = 0;
        GuardiansOfIcecrown[3] = 0;
        GuardiansOfIcecrown[4] = 0;
        GuardiansOfIcecrown_Count = 0;
    }

    uint64 GuardiansOfIcecrown[5];
    uint32 GuardiansOfIcecrown_Count;
    uint32 GuardiansOfIcecrown_Timer;

    //phase==1 summon_timer
    uint32 SummonWasters_Timer;
    uint32 SummonAbominations_Timer;
    uint32 SummonAWeavers_Timer;

    //phase==2,spell_timer
    uint32 FrostBolt_Timer;
    uint32 FrostBoltNova_Timer;
    uint32 ChainsOfKelthuzad_Timer;
    uint32 ManaDetonation_Timer;
    uint32 ShadowFisure_Timer;
    uint32 FrostBlast_Timer;

    uint32 Phase1_Timer;
    uint32 Phase;

    void Reset()
    {
        SummonWasters_Timer=3000;                           // 3s summon waster
        SummonAbominations_Timer=25000;                   //25s summon abomination
        SummonAWeavers_Timer=20000;                         //20s summon Weavers

        FrostBolt_Timer = 2000;                         //2s CD
        FrostBoltNova_Timer = 15000;                        //Cast every 15 seconds
        ChainsOfKelthuzad_Timer = (rand()%30+30)*1000;      //Cast no sooner than once every 30 seconds
        ManaDetonation_Timer = 20000;                       //Seems to cast about every 20 seconds
        ShadowFisure_Timer = 25000;                         //25 seconds
        FrostBlast_Timer = (rand()%30+30)*1000;             //Random time between 30-60 seconds
        GuardiansOfIcecrown_Timer = 5000;                   //5 seconds for summoning each Guardian of Icecrown in phase 3

        for(int i=0; i<5; i++)
        {
            if(GuardiansOfIcecrown[i])
            {
                //delete creature
                Unit* pUnit = Unit::GetUnit((*m_creature), GuardiansOfIcecrown[i]);
                if (pUnit && pUnit->isAlive())
                    pUnit->DealDamage(pUnit, pUnit->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                GuardiansOfIcecrown[i] = 0;
            }
        }

        Phase1_Timer = 228000;                              //Phase 1 lasts 3 minutes and 48 seconds
        Phase=0;
    }

    void KilledUnit()
    {
        if (rand()%2)
            DoScriptText(SAY_SLAY1, m_creature);
        else
            DoScriptText(SAY_SLAY2, m_creature);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
    }

    void SummonedCreatureDespawn(Creature *summon)
    {
        if(summon->GetEntry() == MOB_FISSURE)
            summon->CastSpell(summon, SPELL_VOID_BLAST, true);
    }

    void EnterCombat(Unit* who)
    {
        switch(rand()%3)
        {
        case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
        case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
        case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
        }
        Phase=1;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (Phase1_Timer<diff && Phase==1)
        {
            Phase=2;
        }else Phase1_Timer-=diff;

        if(Phase == 1)
        {
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            //EnterEvadeMode();
            //SummonWasters_Timer at far positon
            if ( SummonWasters_Timer< diff)
            {

                Creature *Waster = NULL;
                switch(rand()%4)
                {
                case 0: Waster = m_creature->SummonCreature(MOB_WASTE,Pos[0][0], Pos[0][1], Pos[0][2], Pos[0][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 1: Waster = m_creature->SummonCreature(MOB_WASTE,Pos[3][0], Pos[3][1], Pos[3][2], Pos[3][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 2: Waster = m_creature->SummonCreature(MOB_WASTE,Pos[6][0], Pos[6][1], Pos[6][2], Pos[6][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 3: Waster = m_creature->SummonCreature(MOB_WASTE,Pos[9][0], Pos[9][1], Pos[9][2], Pos[9][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                }

                if(Waster)
                {
                    Unit *target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    if(target)
                        Waster->AI()->AttackStart(target);
                }
                SummonWasters_Timer=3000;
            }else  SummonWasters_Timer-=diff;

            //MOB_ABOMINATION at middle positon
            if ( SummonAbominations_Timer< diff)
            {

                Creature *Abominations = NULL;
                switch(rand()%4)
                {
                case 0: Abominations = m_creature->SummonCreature(MOB_ABOMINATION,Pos[1][0], Pos[1][1], Pos[1][2], Pos[1][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 1: Abominations = m_creature->SummonCreature(MOB_ABOMINATION,Pos[4][0], Pos[4][1], Pos[4][2], Pos[4][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 2: Abominations = m_creature->SummonCreature(MOB_ABOMINATION,Pos[7][0], Pos[7][1], Pos[7][2], Pos[7][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 3: Abominations = m_creature->SummonCreature(MOB_ABOMINATION,Pos[10][0], Pos[10][1], Pos[10][2], Pos[10][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                }

                if(Abominations)
                {
                    Unit *target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    if(target)
                        Abominations->AI()->AttackStart(target);
                }
                SummonAbominations_Timer=25000;
            }else  SummonAbominations_Timer-=diff;

            //SummonAWeavers_Timer at far positon
            if ( SummonAWeavers_Timer< diff)
            {

                Creature *Weavers = NULL;
                switch(rand()%4)
                {
                case 0: Weavers = m_creature->SummonCreature(MOB_WEAVER,Pos[0][0], Pos[0][1], Pos[0][2], Pos[0][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 1: Weavers = m_creature->SummonCreature(MOB_WEAVER,Pos[3][0], Pos[3][1], Pos[3][2], Pos[3][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 2: Weavers = m_creature->SummonCreature(MOB_WEAVER,Pos[6][0], Pos[6][1], Pos[6][2], Pos[6][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                case 3: Weavers = m_creature->SummonCreature(MOB_WEAVER,Pos[9][0], Pos[9][1], Pos[9][2], Pos[9][3], TEMPSUMMON_CORPSE_DESPAWN, 0); break;
                }

                if(Weavers)
                {
                    Unit *target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    if(target)
                        Weavers->AI()->AttackStart(target);
                }
                SummonAWeavers_Timer=30000;
            }else  SummonAWeavers_Timer-=diff;

        }

        if( Phase!=1 && m_creature->getVictim() && m_creature->isAlive())
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            //Check for Frost Bolt
            if(FrostBolt_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_FROST_BOLT);
                //Cast again on time
                FrostBolt_Timer = 2000;
            }else FrostBolt_Timer -= diff;

            //Check for Frost Bolt Nova
            if(FrostBoltNova_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_FROST_BOLT_AOE);
                FrostBoltNova_Timer = 15000;
            }else FrostBoltNova_Timer -= diff;

            //Cast  Chains Of Kelthuzad only on the Heroic instance
            /*
            if(ChainsOfKelthuzad_Timer < diff)
            {
            //DoCast(m_creature->getVictim(),SPELL_CHAINS_OF_KELTHUZAD);

            //if(rand()%2 == 0)
            //DoScriptText(SAY_CHAIN1, m_creature);
            //else
            //DoScriptText(SAY_CHAIN2, m_creature);
            ChainsOfKelthuzad_Timer = (rand()%30+30)*1000;
            }else ChainsOfKelthuzad_Timer -= diff;
            */

            //Check for Mana Detonation
            if(ManaDetonation_Timer < diff)
            {
                std::list<HostilReference*> *threatList = &me->getThreatManager().getThreatList();
                std::list<HostilReference*>::iterator itr = threatList->begin();
                std::vector<Unit*> unitList;
                for(;itr != threatList->end(); ++itr)
                {
                    if((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER
                        && (*itr)->getTarget()->getPowerType() == POWER_MANA
                        && (*itr)->getTarget()->GetPower(POWER_MANA))
                        unitList.push_back((*itr)->getTarget());
                }

                if(!unitList.empty())
                {
                    std::vector<Unit*>::iterator itr = unitList.begin();
                    advance(itr, rand()%unitList.size());
                    DoCast(*itr, SPELL_MANA_DETONATION);
                }

                if (rand()%2)
                    DoScriptText(SAY_SPECIAL1_MANA_DET, m_creature);
                ManaDetonation_Timer = 20000;
            }else ManaDetonation_Timer -= diff;

            //Summons a Shadow Fissure underneath a random player.
            //The fissure will stay inactive for about 3 seconds, after which it will become a beam of purple energy,
            //instantly killing the player if they remain in it.

            if(ShadowFisure_Timer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(target, SPELL_SHADOW_FISURE);

                if (rand()%2)
                    DoScriptText(SAY_SPECIAL3_MANA_DET, m_creature);
                ShadowFisure_Timer = 25000;
            }else ShadowFisure_Timer -= diff;

            //cast Frost Blast to a random player
            if(FrostBlast_Timer < diff)
            {
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                {
                    DoCast(target,SPELL_FROST_BLAST);
                    //obviously the spell doesn't work like the description
                    //So, we need script this spell?
                }
                if(rand()%2 == 0)
                    DoScriptText(SAY_FROST_BLAST, m_creature);
                FrostBlast_Timer = (rand()%30+30)*1000;
            }else FrostBlast_Timer -= diff;

            //start phase 3 when we are 40% health
            if( Phase!=3 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 40)
            {
                Phase = 3 ;
                DoScriptText(SAY_REQUEST_AID, m_creature);
                //here Lich King should respond to KelThuzad but I don't know which creature to make talk
                //so for now just make Kelthuzad says it.
                DoScriptText(SAY_ANSWER_REQUEST, m_creature);
            }

            if(Phase==3 && (GuardiansOfIcecrown_Count < 2)) //in normal raid ,only two Icecrown
                if(GuardiansOfIcecrown_Timer < diff)
                {
                    //Summon a Guardian of Icecrown in a random alcove
                    TempSummon* pUnit = NULL;
                    switch(rand()%3)
                    {
                    case 0:
                        pUnit = m_creature->SummonCreature(MOB_ICECROWN,Pos[2][0],Pos[2][1],Pos[2][2],Pos[2][3],TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,1000);
                        break;
                    case 1:
                        pUnit = m_creature->SummonCreature(MOB_ICECROWN,Pos[5][0],Pos[5][1],Pos[5][2],Pos[5][3],TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,1000);
                        break;
                    case 2:
                        pUnit = m_creature->SummonCreature(MOB_ICECROWN,Pos[8][0],Pos[8][1],Pos[8][2],Pos[8][3],TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,1000);
                        break;
                    }

                    if (pUnit)
                    {

                        if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                        {
                            pUnit->AI()->AttackStart(target);
                        }
                        //Safe storing of creatures
                        GuardiansOfIcecrown[GuardiansOfIcecrown_Count] = pUnit->GetGUID();

                        //Update guardian count
                        GuardiansOfIcecrown_Count++;

                    }
                    //5 seconds until summoning next guardian
                    GuardiansOfIcecrown_Timer = 5000;
                }
                else GuardiansOfIcecrown_Timer -= diff;

                DoMeleeAttackIfReady();
        }
    }
};

CreatureAI* GetAI_boss_kelthuzadAI(Creature *_Creature)
{
    return new boss_kelthuzadAI (_Creature);
}

void AddSC_boss_kelthuzad()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kelthuzad";
    newscript->GetAI = &GetAI_boss_kelthuzadAI;
    newscript->RegisterSelf();
}
