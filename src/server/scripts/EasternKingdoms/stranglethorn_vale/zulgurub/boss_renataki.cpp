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
SDName: Boss_Renataki
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

#define SPELL_TRASH             3391
#define SPELL_ENRAGE            8269
#define SPELL_RED_LIGHTNING     24240
#define SPELL_AMBUSH            24337
#define SPELL_THOUSANDBLADES    24649
#define SPELL_SURINER_ZONE      24698
#define EQUIP_ID_MAIN_HAND      0                           //was item display id 31818, but this id does not exist

struct boss_renatakiAI : public ScriptedAI
{
    boss_renatakiAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        Light = false;
    }

    uint32 TickTimer;
    uint32 Invisible_Timer;
    uint32 Suriner_Timer;
    uint32 Visible_Timer;
    uint32 Aggro_Timer;
    uint32 ThousandBlades_Timer;

    bool Invisible;
    bool Light;

    void Reset() override
    {
        TickTimer = 1000;
        Invisible_Timer = urand(28000, 32000);
        Suriner_Timer = urand(9000, 11000);
        Visible_Timer = 20000;
        Aggro_Timer = urand(15000, 25000);
        ThousandBlades_Timer = urand(4000, 8000);

        Invisible = false;
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 31818);
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO , 218171138);
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO  + 1, 3);
    }

    void JustDied(Unit* pKiller) override
    {
        LeaveVanish();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!Light)
        {
            Light = true;
            m_creature->CastSpell(m_creature, SPELL_RED_LIGHTNING, true);
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetHealthPercent() < 30)
            DoCastSpellIfCan(m_creature, SPELL_ENRAGE, CF_AURA_NOT_PRESENT);

        if (Invisible)
        {
            if (Visible_Timer < diff)
            {
                Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                LeaveVanish();
                ASSERT(pTarget);
                Ambush(pTarget, SPELL_AMBUSH);

                Invisible = false;
                Visible_Timer = 20000;
            }
            else
                Visible_Timer -= diff;
            return;
        }

        if (Suriner_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SURINER_ZONE) == CAST_OK)
                Suriner_Timer = urand(9000, 11000);
        }
        else Suriner_Timer -= diff;

        //Invisible_Timer
        if (Invisible_Timer < diff)
        {
            EnterVanish();
            Invisible = true;

            Invisible_Timer = urand(30000, 42000);
        }
        else Invisible_Timer -= diff;

        //Resetting some aggro so he attacks other gamers
        if (Aggro_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1);

            if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -50);

            if (target)
                AttackStart(target);

            Aggro_Timer = urand(7000, 20000);
        }
        else Aggro_Timer -= diff;

        if (ThousandBlades_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THOUSANDBLADES);
            ThousandBlades_Timer = urand(7000, 12000);
        }
        else ThousandBlades_Timer -= diff;

        if (m_creature->IsAttackReady() && !urand(0, 2))
            m_creature->CastSpell(m_creature, SPELL_TRASH, true);

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_renataki(Creature* pCreature)
{
    return new boss_renatakiAI(pCreature);
}

void AddSC_boss_renataki()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_renataki";
    newscript->GetAI = &GetAI_boss_renataki;
    newscript->RegisterSelf();
}
