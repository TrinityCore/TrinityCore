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
SDName: Boss_Maleki_the_Pallid
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"
#include "stratholme.h"

#define SPELL_FROSTBOLT     17503
#define SPELL_DRAIN_LIFE    17238
#define SPELL_DRAIN_MANA    17243
#define SPELL_ICETOMB       16869

struct boss_maleki_the_pallidAI : public ScriptedAI
{
    boss_maleki_the_pallidAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 Frostbolt_Timer;
    uint32 IceTomb_Timer;
    uint32 Drain_Timer;

    uint64 IcedPlayerGuid;
    float IcedPlayerAggro;

    bool NeedMoveCloser;

    void Reset() override
    {
        Frostbolt_Timer = 1000;
        IceTomb_Timer = 12000;
        Drain_Timer = 4000;

        IcedPlayerGuid = 0;
        IcedPlayerAggro = 0;

        NeedMoveCloser = false;
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_PALLID, DONE);
    }

    inline float GetManaPercent()
    {
        return (((float)m_creature->GetPower(POWER_MANA) / (float)m_creature->GetMaxPower(POWER_MANA)) * 100);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (IcedPlayerGuid)
        {
            if (Unit* pTarget = m_creature->GetMap()->GetPlayer(IcedPlayerGuid))
            {
                if (!pTarget->HasAura(SPELL_ICETOMB))
                {
                    m_creature->GetThreatManager().addThreatDirectly(pTarget, IcedPlayerAggro);
                    IcedPlayerGuid = 0;
                    IcedPlayerAggro = 0;
                }
            }
            else
            {
                IcedPlayerGuid = 0;
                IcedPlayerAggro = 0;
            }
        }

        //Frostbolt
        if (Frostbolt_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROSTBOLT) == CAST_OK)
                Frostbolt_Timer = urand(3500, 4500);
        }
        else
            Frostbolt_Timer -= diff;

        //IceTomb
        if (IceTomb_Timer < diff)
        {
            if (Unit* pTarget = m_creature->GetVictim())
            {
                if (DoCastSpellIfCan(pTarget, SPELL_ICETOMB) == CAST_OK)
                {
                    IcedPlayerGuid = pTarget->GetGUID();
                    IcedPlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);
                    m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                    IceTomb_Timer = urand(20000, 25000);
                }
            }
        }
        else IceTomb_Timer -= diff;

        //DrainLife/Mana
        if ((m_creature->GetHealthPercent() < 60.0f) || (GetManaPercent() < 50.0f))
        {
            NeedMoveCloser = true;
            if (Drain_Timer < diff)
            {
                bool ManaTarget = false;
                if (Unit* pTarget = m_creature->GetVictim())
                    if (pTarget->GetPower(POWER_MANA))
                        ManaTarget = true;
                if (DoCastSpellIfCan(m_creature->GetVictim(), (ManaTarget ? SPELL_DRAIN_MANA : SPELL_DRAIN_LIFE)) == CAST_OK)
                    Drain_Timer = urand(12000, 18000);
            }
            else
                Drain_Timer -= diff;
        }
        else
            NeedMoveCloser = false;

        if (Unit* pTarget = m_creature->GetVictim())
        {
            if ((pTarget->GetDistance2d(m_creature) > (NeedMoveCloser ? 20.0f : 40.0f)) || (GetManaPercent() < 10.0f))
            {
                SetCombatMovement(true);
                m_creature->GetMotionMaster()->MoveChase(pTarget);
            }
            else
            {
                SetCombatMovement(false);
                m_creature->GetMotionMaster()->MoveIdle();
            }
        }
        else
            SetCombatMovement(false);

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_maleki_the_pallid(Creature* pCreature)
{
    return new boss_maleki_the_pallidAI(pCreature);
}

void AddSC_boss_maleki_the_pallid()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_maleki_the_pallid";
    newscript->GetAI = &GetAI_boss_maleki_the_pallid;
    newscript->RegisterSelf();
}
