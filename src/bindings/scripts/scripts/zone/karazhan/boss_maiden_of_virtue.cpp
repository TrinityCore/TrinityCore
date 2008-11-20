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
SDName: Boss_Maiden_of_Virtue
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"

#define SPELL_REPENTANCE        29511
#define SPELL_HOLYFIRE          29522
#define SPELL_HOLYWRATH         32445
#define SPELL_HOLYGROUND        29512
#define SPELL_BERSERK           26662

#define SAY_AGGRO               "Your behavior will not be tolerated!"
#define SAY_SLAY1               "Ah ah ah..."
#define SAY_SLAY2               "This is for the best."
#define SAY_SLAY3               "Impure thoughts lead to profane actions."
#define SAY_REPENTANCE1         "Cast out your corrupt thoughts."
#define SAY_REPENTANCE2         "Your impurity must be cleansed."
#define SAY_DEATH               "Death comes. Will your conscience be clear?"

#define SOUND_AGGRO             9204
#define SOUND_SLAY1             9207
#define SOUND_SLAY2             9312
#define SOUND_SLAY3             9311
#define SOUND_REPENTANCE1       9313
#define SOUND_REPENTANCE2       9208
#define SOUND_DEATH             9206

struct TRINITY_DLL_DECL boss_maiden_of_virtueAI : public ScriptedAI
{
    boss_maiden_of_virtueAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Repentance_Timer;
    uint32 Holyfire_Timer;
    uint32 Holywrath_Timer;
    uint32 Holyground_Timer;
    uint32 Enrage_Timer;

    bool Enraged;

    void Reset()
    {
        Repentance_Timer    = 30000+(rand()%15000);
        Holyfire_Timer      = 8000+(rand()%17000);
        Holywrath_Timer     = 20000+(rand()%10000);
        Holyground_Timer    = 3000;
        Enrage_Timer        = 600000;

        Enraged = false;

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    void KilledUnit(Unit* Victim)
    {
        if(rand()%2) return;

        switch(rand()%3)
        {
        case 0:
            DoYell(SAY_SLAY1,LANG_UNIVERSAL,Victim);
            DoPlaySoundToSet(m_creature, SOUND_SLAY1);
            break;
        case 1:
            DoYell(SAY_SLAY2,LANG_UNIVERSAL,Victim);
            DoPlaySoundToSet(m_creature, SOUND_SLAY2);
            break;
        case 2:
            DoYell(SAY_SLAY3,LANG_UNIVERSAL,Victim);
            DoPlaySoundToSet(m_creature, SOUND_SLAY3);
            break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if (Enrage_Timer < diff && !Enraged)
        {
            DoCast(m_creature, SPELL_BERSERK,true);
            Enraged = true;
        }else Enrage_Timer -=diff;

        if (Holyground_Timer < diff)
        {
            DoCast(m_creature, SPELL_HOLYGROUND, true);     //Triggered so it doesn't interrupt her at all
            Holyground_Timer = 3000;
        }else Holyground_Timer -= diff;

        if (Repentance_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_REPENTANCE);

            switch(rand()%2)
            {
            case 0:
                DoYell(SAY_REPENTANCE1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_REPENTANCE1);
                break;
            case 1:
                DoYell(SAY_REPENTANCE2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_REPENTANCE2);
                break;
            }
            Repentance_Timer = 30000 + rand()%15000;        //A little randomness on that spell
        }else Repentance_Timer -= diff;

        if (Holyfire_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);            

            if(target)
            {
                DoCast(target,SPELL_HOLYFIRE);
                Holyfire_Timer = 8000 + rand()%17000; //Anywhere from 8 to 25 seconds, good luck having several of those in a row!
            }
        }else Holyfire_Timer -= diff;

        if (Holywrath_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);

            if (target)
            {
                DoCast(target,SPELL_HOLYWRATH);
                Holywrath_Timer = 20000+(rand()%10000);     //20-30 secs sounds nice
            }
        }else Holywrath_Timer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_maiden_of_virtue(Creature *_Creature)
{
    return new boss_maiden_of_virtueAI (_Creature);
}

void AddSC_boss_maiden_of_virtue()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_maiden_of_virtue";
    newscript->GetAI = GetAI_boss_maiden_of_virtue;
    newscript->RegisterSelf();
}
