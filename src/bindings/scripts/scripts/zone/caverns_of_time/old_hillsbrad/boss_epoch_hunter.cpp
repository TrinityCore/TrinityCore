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
SDName: Boss_Epoch_Hunter
SD%Complete: 60
SDComment: Missing spawns pre-event, missing speech to be coordinated with rest of escort event.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "precompiled.h"
#include "def_old_hillsbrad.h"

#define SAY_ENTER1              "Thrall! Come outside and face your fate!"
#define SOUND_ENTER1            10418
#define SAY_ENTER2              "Taretha's life hangs in the balance. Surely you care for her. Surely you wish to save her..."
#define SOUND_ENTER2            10419
#define SAY_ENTER3              "Ah, there you are. I had hoped to accomplish this with a bit of subtlety, but I suppose direct confrontation was inevitable. Your future, Thrall, must not come to pass and so...you and your troublesome friends must die!"
#define SOUND_ENTER3            10420

#define SAY_AGGRO1              "Enough! I will erase your very existence!"
#define SOUND_AGGRO1            10421
#define SAY_AGGRO2              "You cannot fight fate!"
#define SOUND_AGGRO2            10422

#define SAY_SLAY1               "You are...irrelevant."
#define SOUND_SLAY1             10425
#define SAY_SLAY2               "Thrall will remain a slave. Taretha will die. You have failed."
#define SOUND_SLAY2             10426

#define SAY_BREATH1             "Not so fast!"
#define SOUND_BREATH1           10423
#define SAY_BREATH2             "Struggle as much as you like!"
#define SOUND_BREATH2           10424

#define SAY_DEATH               "No!...The master... will not... be pleased."
#define SOUND_DEATH             10427

#define SPELL_SAND_BREATH           31914
#define SPELL_IMPENDING_DEATH       31916
#define SPELL_MAGIC_DISRUPTION_AURA 33834
#define SPELL_WING_BUFFET           31475

struct TRINITY_DLL_DECL boss_epoch_hunterAI : public ScriptedAI
{
    boss_epoch_hunterAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 SandBreath_Timer;
    uint32 ImpendingDeath_Timer;
    uint32 WingBuffet_Timer;
    uint32 Mda_Timer;

    void Reset()
    {
        SandBreath_Timer = 25000;
        ImpendingDeath_Timer = 30000;
        WingBuffet_Timer = 35000;
        Mda_Timer = 40000;
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
            pInstance->SetData(TYPE_THRALL_PART4, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Sand Breath
        if( SandBreath_Timer < diff )
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(false);

            DoCast(m_creature->getVictim(),SPELL_SAND_BREATH);

            switch(rand()%2)
            {
                case 0:
                    DoYell(SAY_BREATH1,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature, SOUND_BREATH1);
                    break;
                case 1:
                    DoYell(SAY_BREATH2,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature, SOUND_BREATH2);
                    break;
            }

            SandBreath_Timer = 25000+rand()%5000;
        }else SandBreath_Timer -= diff;

        if( ImpendingDeath_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_IMPENDING_DEATH);
            ImpendingDeath_Timer = 30000+rand()%5000;
        }else ImpendingDeath_Timer -= diff;

        if( WingBuffet_Timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_WING_BUFFET);
            WingBuffet_Timer = 25000+rand()%10000;
        }else WingBuffet_Timer -= diff;

        if( Mda_Timer < diff )
        {
            DoCast(m_creature,SPELL_MAGIC_DISRUPTION_AURA);
            Mda_Timer = 15000;
        }else Mda_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_epoch_hunter(Creature *_Creature)
{
    return new boss_epoch_hunterAI (_Creature);
}

void AddSC_boss_epoch_hunter()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_epoch_hunter";
    newscript->GetAI = GetAI_boss_epoch_hunter;
    m_scripts[nrscripts++] = newscript;
}
