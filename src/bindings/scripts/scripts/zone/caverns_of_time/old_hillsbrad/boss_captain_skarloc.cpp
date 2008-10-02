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
SDName: Boss_Captain_Skarloc
SD%Complete: 75
SDComment: Missing adds, missing waypoints to move up to Thrall once spawned + speech before enter combat.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "precompiled.h"
#include "def_old_hillsbrad.h"

#define HOLY_LIGHT          29562
#define CLEANSE             39078
#define HAMMER_OF_JUSTICE   13005
#define HOLY_SHIELD         31904
#define DEVOTION_AURA       41452
#define CONSECRATION        41541

#define SAY_ENTER           "Thrall! You didn't really think you would escape did you? You and your allies shall answer to Blackmoore - after I've had my fun!"
#define SAY_AGGRO1          "You're a slave. That's all you'll ever be.'"
#define SAY_AGGRO2          "I don't know what Blackmoore sees in you. For my money, you're just another ignorant savage!"
#define SAY_SLAY1           "Thrall will never be free!"
#define SAY_SLAY2           "Did you really think you would leave here alive?"
#define SAY_DEATH           "Guards! Urgh..Guards..!'"

#define SOUND_ENTER         10406
#define SOUND_AGGRO1        10407
#define SOUND_AGGRO2        10408
#define SOUND_SLAY1         10409
#define SOUND_SLAY2         10410
#define SOUND_DEATH         10411

struct MANGOS_DLL_DECL boss_captain_skarlocAI : public ScriptedAI
{
    boss_captain_skarlocAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 Holy_Light_Timer;
    uint32 Cleanse_Timer;
    uint32 HammerOfJustice_Timer;
    uint32 HolyShield_Timer;
    uint32 DevotionAura_Timer;
    uint32 Consecration_Timer;

    void Reset()
    {
        Holy_Light_Timer = 30000;
        Cleanse_Timer = 10000;
        HammerOfJustice_Timer = 60000;
        HolyShield_Timer = 240000;
        DevotionAura_Timer = 60000;
        Consecration_Timer = 8000;
    }

    void Aggro(Unit *who)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_AGGRO1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
                break;
        }
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
        if( pInstance && pInstance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS )
            pInstance->SetData(TYPE_THRALL_PART1, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Holy_Light
        if (Holy_Light_Timer < diff)
        {
            DoCast(m_creature, HOLY_LIGHT);
            Holy_Light_Timer = 30000;
        }else Holy_Light_Timer -= diff;

        //Cleanse
        if(Cleanse_Timer  < diff)
        {
            DoCast(m_creature, CLEANSE);
            Cleanse_Timer = 10000 ;
        } else Cleanse_Timer -= diff;

        //Hammer of Justice
        if (HammerOfJustice_Timer < diff)
        {
            DoCast(m_creature->getVictim(), HAMMER_OF_JUSTICE);
            HammerOfJustice_Timer = 60000;
        }else HammerOfJustice_Timer -= diff;

        //Holy Shield
        if (HolyShield_Timer < diff)
        {
            DoCast(m_creature,HOLY_SHIELD);
            HolyShield_Timer = 240000;
        }else HolyShield_Timer -= diff;

        //Devotion_Aura
        if (DevotionAura_Timer < diff)
        {
            DoCast(m_creature,DEVOTION_AURA);
            DevotionAura_Timer = 60000;
        }else DevotionAura_Timer -= diff;

        //Consecration
        if (Consecration_Timer < diff)
        {
            //DoCast(m_creature->getVictim(),CONSECRATION);
            Consecration_Timer = 8000;
        }else Consecration_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_captain_skarloc(Creature *_Creature)
{
    return new boss_captain_skarlocAI (_Creature);
}

void AddSC_boss_captain_skarloc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_captain_skarloc";
    newscript->GetAI = GetAI_boss_captain_skarloc;
    m_scripts[nrscripts++] = newscript;
}
