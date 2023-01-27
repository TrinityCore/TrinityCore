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
SDName: Boss_instructormalicia
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

#define SPELL_CALLOFGRAVES         17831
#define SPELL_CORRUPTION           11672
#define SPELL_FLASHHEAL            10917
#define SPELL_RENEW                10929
#define SPELL_HEALINGTOUCH         9889

struct boss_instructormaliciaAI : public ScriptedAI
{
    boss_instructormaliciaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 CallOfGraves_Timer;
    uint32 Corruption_Timer;
    uint32 FlashHeal_Timer;
    uint32 Renew_Timer;
    uint32 HealingTouch_Timer;
    uint32 FlashCounter;
    uint32 TouchCounter;

    void Reset() override
    {
        CallOfGraves_Timer = 4000;
        Corruption_Timer = 8000;
        FlashHeal_Timer = 22000;
        Renew_Timer = 15000;
        HealingTouch_Timer = 25000;
        FlashCounter = 0;
        TouchCounter = 0;
    }

    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_MALICIA, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //CallOfGraves_Timer
        if (CallOfGraves_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CALLOFGRAVES);
            CallOfGraves_Timer = 65000;
        }
        else CallOfGraves_Timer -= diff;

        //Corruption_Timer
        if (Corruption_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_CORRUPTION);

            Corruption_Timer = 24000;
        }
        else Corruption_Timer -= diff;

        //Renew_Timer
        if (Renew_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_RENEW);
            Renew_Timer = 10000;
        }
        else Renew_Timer -= diff;

        //FlashHeal_Timer
        if (FlashHeal_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_FLASHHEAL);

            //5 Flashheals will be casted
            if (FlashCounter < 2)
            {
                FlashHeal_Timer = 5000;
                ++FlashCounter;
            }
            else
            {
                FlashCounter = 0;
                FlashHeal_Timer = 30000;
            }
        }
        else FlashHeal_Timer -= diff;

        //HealingTouch_Timer
        if (HealingTouch_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_HEALINGTOUCH);

            //3 Healingtouchs will be casted
            if (HealingTouch_Timer < 2)
            {
                HealingTouch_Timer = 5500;
                ++TouchCounter;
            }
            else
            {
                TouchCounter = 0;
                HealingTouch_Timer = 30000;
            }
        }
        else HealingTouch_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_instructormalicia(Creature* pCreature)
{
    return new boss_instructormaliciaAI(pCreature);
}

void AddSC_boss_instructormalicia()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_instructor_malicia";
    newscript->GetAI = &GetAI_boss_instructormalicia;
    newscript->RegisterSelf();
}
