/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Arcanist_Doan
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "scriptPCH.h"

enum
{
    SAY_AGGRO                   = -1189019,
    SAY_SPECIALAE               = -1189020,

    SPELL_POLYMORPH             = 13323,
    SPELL_AOESILENCE            = 8988,
    SPELL_ARCANEEXPLOSION       = 9433,
    SPELL_FIREAOE               = 9435,
    SPELL_ARCANEBUBBLE          = 9438,
};

struct boss_arcanist_doanAI : public ScriptedAI
{
    boss_arcanist_doanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Polymorph_Timer;
    uint32 AoESilence_Timer;
    uint32 ArcaneExplosion_Timer;
    bool bCanDetonate;
    bool bShielded;

    void Reset() override
    {
        Polymorph_Timer = 20000;
        AoESilence_Timer = 15000;
        ArcaneExplosion_Timer = 3000;
        bCanDetonate = false;
        bShielded = false;
    }

    void Aggro(Unit *who) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (bShielded && bCanDetonate)
        {
            DoCastSpellIfCan(m_creature, SPELL_FIREAOE);
            bCanDetonate = false;
        }

        if (m_creature->HasAura(SPELL_ARCANEBUBBLE))
            return;

        //If we are <50% hp cast Arcane Bubble
        if (!bShielded && m_creature->GetHealthPercent() <= 50.0f)
        {
            //wait if we already casting
            if (m_creature->IsNonMeleeSpellCasted(false))
                return;

            DoScriptText(SAY_SPECIALAE, m_creature);
            DoCastSpellIfCan(m_creature, SPELL_ARCANEBUBBLE);

            bCanDetonate = true;
            bShielded = true;
        }

        if (Polymorph_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                DoCastSpellIfCan(target, SPELL_POLYMORPH);

            Polymorph_Timer = 20000;
        }
        else Polymorph_Timer -= diff;

        //AoESilence_Timer
        if (AoESilence_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AOESILENCE);
            AoESilence_Timer = urand(15000, 20000);
        }
        else AoESilence_Timer -= diff;

        //ArcaneExplosion_Timer
        if (ArcaneExplosion_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEEXPLOSION);
            ArcaneExplosion_Timer = 8000;
        }
        else ArcaneExplosion_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_arcanist_doan(Creature* pCreature)
{
    return new boss_arcanist_doanAI(pCreature);
}

void AddSC_boss_arcanist_doan()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_arcanist_doan";
    newscript->GetAI = &GetAI_boss_arcanist_doan;
    newscript->RegisterSelf();
}
