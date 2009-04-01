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
SDName: Boss_Interrogator_Vishas
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_POWERWORDSHIELD           6065

#define SAY_AGGRO                       "Tell me... tell me everything!"
#define SAY_HEALTH1                     "Naughty secrets"
#define SAY_HEALTH2                     "I'll rip the secrets from your flesh!"
#define SAY_DEATH                       "Purged by pain!"

#define SOUND_AGGRO                     5847
#define SOUND_HEALTH1                   5849
#define SOUND_HEALTH2                   5850
#define SOUND_DEATH                     5848

struct TRINITY_DLL_DECL boss_interrogator_vishasAI : public ScriptedAI
{
    boss_interrogator_vishasAI(Creature *c) : ScriptedAI(c) {}

    uint32 Yell_Timer;
    uint32 PowerWordShield_Timer;

    void Reset()
    {
        Yell_Timer = 6000000;
        PowerWordShield_Timer = 60000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are low on hp Do sayings
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 60 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            //Yell_Timer
            if (Yell_Timer < diff)
            {
                DoYell(SAY_HEALTH1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_HEALTH1);
                return;

                //60 seconds until we should cast this agian
                Yell_Timer = 60000;
            }else Yell_Timer -= diff;
        }

        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 30 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            //Yell_Timer
            if (Yell_Timer < diff)
            {
                DoYell(SAY_HEALTH2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_HEALTH2);
                return;

                //60 seconds until we should cast this agian
                Yell_Timer = 6000000;
            }else Yell_Timer -= diff;
        }

        //PowerWordShield_Timer
        if (PowerWordShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_POWERWORDSHIELD);
            PowerWordShield_Timer = 60000;
        }else PowerWordShield_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_interrogator_vishas(Creature *_Creature)
{
    return new boss_interrogator_vishasAI (_Creature);
}

void AddSC_boss_interrogator_vishas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_interrogator_vishas";
    newscript->GetAI = &GetAI_boss_interrogator_vishas;
    newscript->RegisterSelf();
}

