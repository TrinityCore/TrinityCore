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
SDName: Boss_Aeonus
SD%Complete: 100
SDComment:
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "precompiled.h"

#define SAND_BREATH       31478
#define TIME_STOP         31422
#define FRENZY            19812

#define SAY_ENTER         "The time has come to shatter this clockwork universe forever! Let us no longer be slaves of the hourglass! I warn you: those who do not embrace the greater path shall become victims of its passing!"
#define SAY_AGGRO         "Let us see what fate lays in store..."
#define SAY_BANISH        "Your time is up, slave of the past!"
#define SAY_SLAY1         "One less obstacle in our way!"
#define SAY_SLAY2         "No one can stop us! No one!"
#define SAY_DEATH         "It is only a matter...of time."

#define SOUND_ENTER       10400
#define SOUND_AGGRO       10402
#define SOUND_BANISH      10401
#define SOUND_SLAY1       10403
#define SOUND_SLAY2       10404
#define SOUND_DEATH       10405

struct MANGOS_DLL_DECL boss_aeonusAI : public ScriptedAI
{
    boss_aeonusAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 SandBreath_Timer;
    uint32 TimeStop_Timer;
    uint32 Frenzy_Timer;

    void Reset()
    {
        SandBreath_Timer = 30000;
        TimeStop_Timer = 40000;
        Frenzy_Timer = 120000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void JustDied(Unit *victim)
    {
        //Just Died
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void KilledUnit(Unit *victim)
    {
        //Killed Unit
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

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Sand Breath
        if (SandBreath_Timer < diff)
        {
            Unit* target = NULL;
            target = m_creature->getVictim();
            if (target)
                DoCast(target, SAND_BREATH);
            SandBreath_Timer = 30000;
        }else SandBreath_Timer -= diff;

        //Time Stop
        if (TimeStop_Timer < diff)
        {
            DoYell(SAY_BANISH, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_BANISH);

            DoCast(m_creature->getVictim(), TIME_STOP);
            TimeStop_Timer = 40000;
        }else TimeStop_Timer -= diff;

        //Frenzy
        if (Frenzy_Timer < diff)
        {
            DoCast(m_creature, FRENZY);
            Frenzy_Timer = 120000;
        }else Frenzy_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_aeonus(Creature *_Creature)
{
    return new boss_aeonusAI (_Creature);
}

void AddSC_boss_aeonus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_aeonus";
    newscript->GetAI = GetAI_boss_aeonus;
    m_scripts[nrscripts++] = newscript;
}
