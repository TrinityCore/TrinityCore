/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Shazzrah
SD%Complete: 75
SDComment: Teleport NYI
SDCategory: Molten Core
EndScriptData */

#include "scriptPCH.h"
#include "molten_core.h"

enum
{
    SPELL_ARCANEEXPLOSION           = 19712,
    SPELL_SHAZZRAHCURSE             = 19713,
    SPELL_DEADENMAGIC               = 19714,
    SPELL_COUNTERSPELL              = 19715,
    SPELL_GATE_DUMMY                = 23138                 // effect spell: 23139
};

struct boss_shazzrahAI : public ScriptedAI
{
    boss_shazzrahAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 ArcaneExplosion_Timer;
    uint32 ShazzrahCurse_Timer;
    uint32 DeadenMagic_Timer;
    uint32 Countspell_Timer;
    uint32 Blink_Timer;

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        ArcaneExplosion_Timer = 2000;
        ShazzrahCurse_Timer = 10000;
        DeadenMagic_Timer = 5000;
        Countspell_Timer = 15000;
        Blink_Timer = urand(25000, 30000);

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_SHAZZRAH, NOT_STARTED);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SHAZZRAH, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SHAZZRAH, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ArcaneExplosion_Timer
        if (ArcaneExplosion_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEEXPLOSION) == CAST_OK)
                ArcaneExplosion_Timer = urand(3000, 5000);
        }
        else ArcaneExplosion_Timer -= diff;

        //ShazzrahCurse_Timer
        if (ShazzrahCurse_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHAZZRAHCURSE, CF_AURA_NOT_PRESENT) == CAST_OK)
                ShazzrahCurse_Timer = 20000;
        }
        else ShazzrahCurse_Timer -= diff;

        //DeadenMagic_Timer
        if (DeadenMagic_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_DEADENMAGIC) == CAST_OK)
                DeadenMagic_Timer = urand(7000, 14000);
        }
        else DeadenMagic_Timer -= diff;

        //Countspell_Timer
        if (Countspell_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_COUNTERSPELL) == CAST_OK)
                Countspell_Timer = urand(16000, 18000);
        }
        else Countspell_Timer -= diff;

        //Blink_Timer
        if (Blink_Timer < diff)
        {
            // Teleporting him to a random gamer and casting Arcane Explosion after that.
            if (DoCastSpellIfCan(m_creature, SPELL_GATE_DUMMY, CF_TRIGGERED) == CAST_OK)
            {
                // manual, until added effect of dummy properly
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER))
                {
                    DoResetThreat();
                    m_creature->NearTeleportTo(pTarget->GetPosition());
                    m_creature->Attack(pTarget, true);
                }

                Blink_Timer = urand(25000, 35000);
            }
        }
        else Blink_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_shazzrah(Creature* pCreature)
{
    return new boss_shazzrahAI(pCreature);
}

void AddSC_boss_shazzrah()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_shazzrah";
    newscript->GetAI = &GetAI_boss_shazzrah;
    newscript->RegisterSelf();
}
