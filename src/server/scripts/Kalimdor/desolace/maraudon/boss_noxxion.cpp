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
SDName: Boss_Noxxion
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "scriptPCH.h"

#define SPELL_TOXICVOLLEY           21687
#define SPELL_UPPERCUT              22916

struct boss_noxxionAI : public ScriptedAI
{
    boss_noxxionAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 ToxicVolley_Timer;
    uint32 Uppercut_Timer;
    uint32 Adds_Timer;
    uint32 Invisible_Timer;
    bool Invisible;

    void Reset() override
    {
        ToxicVolley_Timer = 7000;
        Uppercut_Timer = 16000;
        Adds_Timer = 19000;
        Invisible_Timer = 15000;                            //Too much too low?
        Invisible = false;
    }

    void SummonAdds(Unit* victim)
    {
        if (Creature* summoned = DoSpawnCreature(13456, 8.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90000))
            if (summoned->AI())
                summoned->AI()->AttackStart(victim);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (Invisible && Invisible_Timer < diff)
        {
            //Become visible again
            m_creature->SetFactionTemplateId(14);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //Noxxion model
            m_creature->SetDisplayId(11172);
            Invisible = false;
            //m_creature->m_canMove = true;
        }
        else if (Invisible)
        {
            Invisible_Timer -= diff;
            //Do nothing while invisible
            return;
        }

        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ToxicVolley_Timer
        if (ToxicVolley_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TOXICVOLLEY) == CAST_OK)
                ToxicVolley_Timer = 9000;
        }
        else
            ToxicVolley_Timer -= diff;

        //Uppercut_Timer
        if (Uppercut_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UPPERCUT) == CAST_OK)
                Uppercut_Timer = 12000;
        }
        else
            Uppercut_Timer -= diff;

        //Adds_Timer
        if (!Invisible && Adds_Timer < diff)
        {
            //Inturrupt any spell casting
            m_creature->InterruptNonMeleeSpells(false);
            m_creature->SetFactionTemplateId(35);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Invisible Model
            m_creature->SetDisplayId(11686);
            for (int i = 0; i < 5; ++i)
                SummonAdds(m_creature->GetVictim());
            Invisible = true;
            Invisible_Timer = 15000;

            Adds_Timer = 40000;
        }
        else
            Adds_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_noxxion(Creature* pCreature)
{
    return new boss_noxxionAI(pCreature);
}

void AddSC_boss_noxxion()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_noxxion";
    newscript->GetAI = &GetAI_boss_noxxion;
    newscript->RegisterSelf();
}
