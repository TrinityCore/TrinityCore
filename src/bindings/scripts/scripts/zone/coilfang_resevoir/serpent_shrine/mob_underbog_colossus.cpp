/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: mob_underbog_colossus
SD%Complete: 99%
SDComment: Underbog Colossus in SSC
SDCategory: SSC trash
EndScriptData */

#include "precompiled.h"


#define SPELL_INFECTION                39032
#define SPELL_SPORE_QUAKE            38976

#define SPELL_FRENZY                39031
#define SPELL_ATROPHIC_BLOW            39015

#define SPELL_ACID_GEYSER            38971
#define SPELL_PARASITE                39044

#define SPELL_REFRESHING_MIST        38730
#define SPELL_TOXIC_POOL            38718
#define MOB_LURKER                    22347
#define MOB_RAGER                    22352
#define MOB_REFRESHING_MIST            41004

struct TRINITY_DLL_DECL mob_underbog_colossusAI : public ScriptedAI
{
    mob_underbog_colossusAI(Creature *c) : ScriptedAI(c) 
    {
        Reset();
        DoSetupSpells();
    }

    uint32 Spell_Timer1;
    uint32 Spell_Timer2;
    uint32 Spell_Id1;
    uint32 Spell_Id2;

    void Reset()
    {
        Spell_Timer1 = 15000+rand()%7000;
        Spell_Timer2 = 15000+rand()%7000;    
    }

    void Aggro(Unit *who)
    {

    }
    void DoSetupSpells()
    {
        switch (rand()%3)
        {
            case 0: 
                {
                    Spell_Id1 = SPELL_SPORE_QUAKE;
                    Spell_Id2 = SPELL_INFECTION;
                }
            case 1: 
                {
                    Spell_Id1 = SPELL_FRENZY;
                    Spell_Id2 = SPELL_ATROPHIC_BLOW;
                }
            case 2: 
                {
                    Spell_Id1 = SPELL_ACID_GEYSER;
                    Spell_Id2 = SPELL_PARASITE;
                }
        }
    }
    void JustDied(Unit *victim)
    {    
        switch (rand()%4)
        {
            case 0: 
                {
                    return;
                }
            case 1: 
                {
                    for (uint8 i=0;i<2;i++)
                    {
                        Creature* mob = DoSpawnCreature(MOB_LURKER, rand()%5,rand()%5,0,0,TEMPSUMMON_CORPSE_DESPAWN, 30000);
                        Unit* target = NULL;
                        target = SelectUnit(SELECT_TARGET_RANDOM,0);
                        if (target && mob)
                            mob->AI()->AttackStart(target);
                    }
                }
                break;
            case 2: 
                {
                    for (uint8 i=0;i<8+rand()%5;i++)
                    {
                        Creature* mob = DoSpawnCreature(MOB_RAGER, rand()%5,rand()%5,0,0,TEMPSUMMON_CORPSE_DESPAWN, 30000);
                        Unit* target = NULL;
                        target = SelectUnit(SELECT_TARGET_RANDOM,0);
                        if (target && mob)
                            mob->AI()->AttackStart(target);
                    }
                } 
                break;
            case 3: 
                {
                    m_creature->CastSpell(m_creature,SPELL_TOXIC_POOL,true);
                } 
                break;            
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;        

        //Spell Timer 1
        if (Spell_Timer1 < diff)
        {
            DoCast(m_creature, Spell_Id1, true);//Spell 1 is always self cast (aoe)
            Spell_Timer1 = 20000+rand()%10000;;
        }else Spell_Timer1 -= diff;

        //Spell Timer 2
        if (Spell_Timer2 < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target)
                DoCast(target, Spell_Id2, true);//Spell 2 is random targeted
            Spell_Timer2 = 20000+rand()%10000;;
        }else Spell_Timer2 -= diff;       

        DoMeleeAttackIfReady();
    } 
};

CreatureAI* GetAI_mob_underbog_colossus(Creature *_Creature)
{
    return new mob_underbog_colossusAI (_Creature);
}

void AddSC_mob_underbog_colossus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="mob_underbog_colossus";
    newscript->GetAI = GetAI_mob_underbog_colossus;
    newscript->RegisterSelf();
}
