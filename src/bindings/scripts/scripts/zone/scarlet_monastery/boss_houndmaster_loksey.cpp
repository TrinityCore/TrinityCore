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
SDName: Boss_Houndmaster_Loksey
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_SUMMONSCARLETHOUND        17164
#define SPELL_ENRAGE                    28747

#define SAY_AGGRO                       "Release the hounds!"
#define SOUND_AGGRO                     5841

struct TRINITY_DLL_DECL boss_houndmaster_lokseyAI : public ScriptedAI
{
    boss_houndmaster_lokseyAI(Creature *c) : ScriptedAI(c) {}

    uint32 Enrage_Timer;

    void Reset()
    {
        Enrage_Timer = 6000000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);

        DoCast(m_creature,SPELL_SUMMONSCARLETHOUND);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <10% hp cast healing spells at self and Mograine
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 10 && !m_creature->IsNonMeleeSpellCasted(false) && Enrage_Timer < diff)
        {
            DoCast(m_creature,SPELL_ENRAGE);
            Enrage_Timer = 900000;
        }else Enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_houndmaster_loksey(Creature *_Creature)
{
    return new boss_houndmaster_lokseyAI (_Creature);
}

void AddSC_boss_houndmaster_loksey()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_houndmaster_loksey";
    newscript->GetAI = &GetAI_boss_houndmaster_loksey;
    newscript->RegisterSelf();
}

