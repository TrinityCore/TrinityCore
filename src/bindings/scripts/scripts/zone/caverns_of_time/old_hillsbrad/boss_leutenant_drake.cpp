/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Luetenant_Drake
SD%Complete: 70
SDComment: Missing proper code for patrolling area after being spawned. Also script for GO (barrels)(missing Trinity support)
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "precompiled.h"
#include "def_old_hillsbrad.h"
#include "../../../npc/npc_escortAI.h"

/*######
## go_barrel_old_hillsbrad
######*/

#define QUEST_ENTRY_DIVERSION   10283
#define LODGE_QUEST_TRIGGER     20155

bool GOHello_go_barrel_old_hillsbrad(Player *player, GameObject* _GO)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_GO->GetInstanceData());

    if( pInstance )
    {
        if( pInstance->GetData(TYPE_BARREL_DIVERSION) != DONE )
        {
            pInstance->SetData(TYPE_BARREL_DIVERSION, IN_PROGRESS);
        }
        else if( pInstance->GetData(TYPE_BARREL_DIVERSION) == DONE )
        {
            player->SummonCreature(17848,2128.43,71.01,64.42,1.74,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,1200000);
            if( player->GetQuestStatus(QUEST_ENTRY_DIVERSION) == QUEST_STATUS_INCOMPLETE )
                player->KilledMonster(LODGE_QUEST_TRIGGER,0);
        }
    }
    return false;
}

/*######
## boss_lieutenant_drake
######*/

#define WHIRLWIND         40236
#define FEAR              33789
#define MORTAL_STRIKE     40220
#define EXPLODIG_SHOUT    33792

#define SAY_ENTER1        "You there, fetch water quickly!"
#define SAY_ENTER2        "Get these flames out before they spread to the rest of the keep!"
#define SAY_ENTER3        "Hurry, damn you!"
#define  SAY_AGGRO        "I know what you're up to, and I mean to put an end to it, permanently!"
#define  SAY_SLAY1        "No more middling for you."
#define  SAY_SLAY2        "You will not interfere!"
#define  SAY_MORTAL       "Time to bleed!"
#define  SAY_SHOUT        "Run, you blasted cowards!"
#define  SAY_DEATH        "Thrall... must not... go free."

#define  SOUND_ENTER      10428
#define  SOUND_AGGRO      10429
#define  SOUND_SLAY1      10432
#define  SOUND_SLAY2      10433
#define  SOUND_MORTAL     10430
#define  SOUND_SHOUT      10431
#define  SOUND_DEATH      10434

struct Location
{
    uint32 wpId;
    float x;
    float y;
    float z;
};

static Location DrakeWP[]=
{
    {0, 2125.84, 88.2535, 54.8830},
    {1, 2111.01, 93.8022, 52.6356},
    {2, 2106.70, 114.753, 53.1965},
    {3, 2107.76, 138.746, 52.5109},
    {4, 2114.83, 160.142, 52.4738},
    {5, 2125.24, 178.909, 52.7283},
    {6, 2151.02, 208.901, 53.1551},
    {7, 2177.00, 233.069, 52.4409},
    {8, 2190.71, 227.831, 53.2742},
    {9, 2178.14, 214.219, 53.0779},
    {10, 2154.99, 202.795, 52.6446},
    {11, 2132.00, 191.834, 52.5709},
    {12, 2117.59, 166.708, 52.7686},
    {13, 2093.61, 139.441, 52.7616},
    {14, 2086.29, 104.950, 52.9246},
    {15, 2094.23, 81.2788, 52.6946},
    {16, 2108.70, 85.3075, 53.3294},
    {17, 2125.50, 88.9481, 54.7953},
    {18, 2128.20, 70.9763, 64.4221}
};

struct TRINITY_DLL_DECL boss_lieutenant_drakeAI : public ScriptedAI
{
    boss_lieutenant_drakeAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool CanPatrol;
    uint32 wpId;

    uint32 Whirlwind_Timer;
    uint32 Fear_Timer;
    uint32 MortalStrike_Timer;
    uint32 ExplodingShout_Timer;

    void Reset()
    {
        CanPatrol = true;
        wpId = 0;

        Whirlwind_Timer = 20000;
        Fear_Timer = 30000;
        MortalStrike_Timer = 45000;
        ExplodingShout_Timer = 25000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void UpdateAI(const uint32 diff)
    {
        //TODO: make this work
        if( CanPatrol && wpId == 0 )
        {
            m_creature->GetMotionMaster()->MovePoint(DrakeWP[0].wpId, DrakeWP[0].x, DrakeWP[0].y, DrakeWP[0].z);
            wpId++;
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Whirlwind
        if (Whirlwind_Timer < diff)
        {
            DoCast(m_creature->getVictim(), WHIRLWIND);

            Whirlwind_Timer = 20000+rand()%5000;
        }else Whirlwind_Timer -= diff;

        //Fear
        if (Fear_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (target)
                DoCast(target, FEAR);

            Fear_Timer = 30000+rand()%10000;
        }else Fear_Timer -= diff;

        //Mortal Strike
        if (MortalStrike_Timer < diff)
        {
            DoYell(SAY_MORTAL, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_MORTAL);

            DoCast(m_creature->getVictim(), MORTAL_STRIKE);

            MortalStrike_Timer = 45000+rand()%5000;
        }else MortalStrike_Timer -= diff;

        /*
        //This only enabled on heroic?
        //Exploding Shout
        if (m_creature->IsHeroicCreature())
        {
        if (ExplodingShout_Timer < diff)
        {
        Unit* target = NULL;
        target = SelectUnit(SELECT_TARGET_RANDOM,0);
        if (target)
        DoYell(SAY_SHOUT, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_SHOUT);
        DoCast(target,EXPLODING_SHOUT);
        ExplodingShout_Timer = 25000+rand()%5000;
        }else ExplodingShout_Timer -= diff;
        }
        */

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_lieutenant_drake(Creature *_Creature)
{
    return new boss_lieutenant_drakeAI (_Creature);
}

void AddSC_boss_lieutenant_drake()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="go_barrel_old_hillsbrad";
    newscript->pGOHello = GOHello_go_barrel_old_hillsbrad;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_lieutenant_drake";
    newscript->GetAI = GetAI_boss_lieutenant_drake;
    m_scripts[nrscripts++] = newscript;
}
