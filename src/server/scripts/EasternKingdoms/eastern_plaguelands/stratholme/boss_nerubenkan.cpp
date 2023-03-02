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
SDName: Boss_Nerubenkan
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"
#include "stratholme.h"

#define SPELL_ENCASINGWEBS          4962
#define SPELL_PIERCEARMOR           6016
#define SPELL_RAISEUNDEADSCARAB     17235

struct boss_nerubenkanAI : public ScriptedAI
{
    boss_nerubenkanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 EncasingWebs_Timer;
    uint32 PierceArmor_Timer;
    uint32 RaiseUndeadScarab_Timer;
    uint32 CryptScarab_Timer;

    uint64 WebbedPlayerGuid;
    float WebbedPlayerAggro;


    void Reset() override
    {
        EncasingWebs_Timer = 7000;
        PierceArmor_Timer = 15000;
        RaiseUndeadScarab_Timer = 3000;

        WebbedPlayerGuid = 0;
        WebbedPlayerAggro = 0;
    }

    void RaiseUndeadScarab(Unit* victim, bool crypt)
    {
        if (crypt)
        {
            int amount = 0;
            switch (urand(0, 2))
            {
                case 0:
                    amount = 4;
                    break;
                case 1:
                    amount = 6;
                    break;
                case 2:
                    amount = 8;
                    break;
            }
            for (int i = 0; i < amount; i++)
            {
                if (Creature* summoned = DoSpawnCreature(10577, 10.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
                    if (summoned->AI())
                        summoned->AI()->AttackStart(victim);
            }
        }
        else
        {
            if (Creature* summoned = DoSpawnCreature(10876, 10.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
                if (summoned->AI())
                    summoned->AI()->AttackStart(victim);
        }
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_NERUB, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (WebbedPlayerGuid)
        {
            if (Unit* pTarget = m_creature->GetMap()->GetPlayer(WebbedPlayerGuid))
            {
                if (!pTarget->HasAura(SPELL_ENCASINGWEBS))
                {
                    m_creature->GetThreatManager().addThreatDirectly(pTarget, WebbedPlayerAggro);
                    WebbedPlayerGuid = 0;
                    WebbedPlayerAggro = 0;
                }
            }
            else
            {
                WebbedPlayerGuid = 0;
                WebbedPlayerAggro = 0;
            }
        }

        //EncasingWebs
        if (EncasingWebs_Timer < diff)
        {
            if (Unit* pTarget = m_creature->GetVictim())
            {
                if (DoCastSpellIfCan(pTarget, SPELL_ENCASINGWEBS) == CAST_OK)
                {
                    WebbedPlayerGuid = pTarget->GetGUID();
                    WebbedPlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);
                    m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                    EncasingWebs_Timer = urand(10000, 15000);
                }
            }
        }
        else EncasingWebs_Timer -= diff;

        //PierceArmor
        if (PierceArmor_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PIERCEARMOR) == CAST_OK)
                PierceArmor_Timer = urand(15000, 20000);
        }
        else
            PierceArmor_Timer -= diff;

        //RaiseUndeadScarab
        if (RaiseUndeadScarab_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                RaiseUndeadScarab(target, (urand(0, 1) != 0));
                RaiseUndeadScarab_Timer = urand(6000, 10000);
            }
        }
        else
            RaiseUndeadScarab_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_nerubenkan(Creature* pCreature)
{
    return new boss_nerubenkanAI(pCreature);
}

void AddSC_boss_nerubenkan()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_nerubenkan";
    newscript->GetAI = &GetAI_boss_nerubenkan;
    newscript->RegisterSelf();
}
