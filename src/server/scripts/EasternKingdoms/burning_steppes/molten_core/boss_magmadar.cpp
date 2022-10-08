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

#include "scriptPCH.h"
#include "molten_core.h"

enum
{
    EMOTE_GENERIC_FRENZY_KILL   = 7797,

    SPELL_LAVA_BREATH           = 19272,                    // Triggered by SPELL_FRENZY (19451)
    SPELL_FRENZY                = 19451,
    SPELL_MAGMASPIT             = 19449,                    // This is actually a buff he gives himself
    SPELL_PANIC                 = 19408,
    SPELL_LAVABOMB              = 19411,                    // This calls a dummy server side effect that cast spell 20494 to spawn GO 177704 for 30s
    SPELL_LAVABOMB_MANA         = 20474,                    // This calls a dummy server side effect that cast spell 20495 to spawn GO 177704 for 60s
};

struct boss_magmadarAI : public ScriptedAI
{
    boss_magmadarAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 m_uiFrenzyTimer;
    uint32 m_uiPanicTimer;
    uint32 m_uiLavaBombTimer;
    uint32 m_uiLavaBombManaTimer;
    uint32 m_uiRestoreTargetTimer;

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        m_uiFrenzyTimer          = 15000;
        m_uiPanicTimer           = 10000;
        m_uiLavaBombTimer        = 12000;
        m_uiLavaBombManaTimer    = 18000;
        m_uiRestoreTargetTimer   = 0;

        if (!m_creature->HasAura(SPELL_MAGMASPIT))
            m_creature->CastSpell(m_creature, SPELL_MAGMASPIT, true);

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_MAGMADAR, NOT_STARTED);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_MAGMADAR, IN_PROGRESS);
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_MAGMADAR, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Frenzy
        if (m_uiFrenzyTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                m_uiFrenzyTimer = urand(15000, 20000);
            }
        }
        else
            m_uiFrenzyTimer -= diff;

        // Panic
        if (m_uiPanicTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PANIC) == CAST_OK)
                m_uiPanicTimer = urand(30000, 35000);
        }
        else
            m_uiPanicTimer -= diff;

        // Lavabomb_Timer - non mana users
        if (m_uiLavaBombTimer < diff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_LAVABOMB, SELECT_FLAG_POWER_NOT_MANA))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_LAVABOMB) == CAST_OK)
                {
                    m_creature->SetInFront(pTarget);
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_uiLavaBombTimer = urand(12000, 15000);
                    m_uiRestoreTargetTimer = 800;
                }  
            }
        }
        else
            m_uiLavaBombTimer -= diff;

        // Lavabomb_Timer - mana users
        if (m_uiLavaBombManaTimer < diff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_LAVABOMB_MANA, SELECT_FLAG_POWER_MANA))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_LAVABOMB_MANA) == CAST_OK)
                {
                    m_creature->SetInFront(pTarget);
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_uiLavaBombManaTimer = urand(12000, 15000);
                    m_uiRestoreTargetTimer = 800;
                } 
            }
        }
        else
            m_uiLavaBombManaTimer -= diff;

        // restore target after casting a Lava Bomb
        if (m_uiRestoreTargetTimer)
        {
            if (m_uiRestoreTargetTimer <= diff)
            {
                m_creature->SetInFront(m_creature->GetVictim());
                m_creature->SetTargetGuid(m_creature->GetVictim()->GetObjectGuid());
                m_uiRestoreTargetTimer = 0;
            }
            else
                m_uiRestoreTargetTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_magmadar(Creature* pCreature)
{
    return new boss_magmadarAI(pCreature);
}

void AddSC_boss_magmadar()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_magmadar";
    newscript->GetAI = &GetAI_boss_magmadar;
    newscript->RegisterSelf();
}
