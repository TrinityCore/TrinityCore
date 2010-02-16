/* Copyright (C) 2006 - 2010 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptedPch.h"
#include "forge_of_souls.h"

enum Spells
{
    SPELL_MAGIC_S_BANE                            = 68793,
    SPELL_MAGIC_S_BANE_H                          = 69050,
    SPELL_CORRUPT_SOUL                            = 68839,
    SPELL_CONSUME_SOUL                            = 68858,
    SPELL_CONSUME_SOUL_H                          = 69047,
    SPELL_TELEPORT                                = 68988,
    SPELL_FEAR                                    = 68950,
    SPELL_SOULSTORM                               = 68872,
    SPELL_SOULSTORM_H                             = 69049,
    SPELL_SHADOW_BOLT                             = 70043
};
enum CombatPhases
{
    PHASE_1,
    PHASE_2
};
/*enum Adds
{
    CREATURE_CORRUPTED_SOUL_FRAGMENT              = 36535
};*/
struct boss_bronjahmAI : public ScriptedAI
{
    boss_bronjahmAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = m_creature->GetInstanceData();
    }
    
    uint32 uiFearTimer;
    uint32 uiShadowBoltTimer;
    uint32 uiMagicsBaneTimer;
    uint32 uiCorruptSoulTimer;
    
    CombatPhases Phase;

    ScriptedInstance* pInstance;
    
    void Reset()
    {
        Phase = PHASE_1;
        
        uiFearTimer = urand(8000,12000);
        uiShadowBoltTimer = 2000;
        uiMagicsBaneTimer = urand(8000,15000);
        uiCorruptSoulTimer = urand(15000,25000);
        
        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        //DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, IN_PROGRESS);
    }
    
    void JustDied(Unit* killer)
    {
        //DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, DONE);
    }
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;
        
        switch (Phase)
        {
            case PHASE_1:
                if (uiCorruptSoulTimer <= diff)
                {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                        DoCast(pTarget,SPELL_CORRUPT_SOUL);
                    uiCorruptSoulTimer = urand(15000,25000);
                } else uiCorruptSoulTimer -= diff;
                break;
            case PHASE_2:
                if (!me->HasAura(SPELL_SOULSTORM) || !me->HasAura(SPELL_SOULSTORM_H))
                    DoCast(m_creature, DUNGEON_MODE(SPELL_SOULSTORM,SPELL_SOULSTORM_H));
                if (uiFearTimer <= diff)
                {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                        DoCast(m_creature->getVictim(),SPELL_FEAR);
                    uiFearTimer = urand(8000,12000);
                } else uiFearTimer -= diff;
                break;
        }
        
        if (HealthBelowPct(30))
            DoCast(m_creature,SPELL_TELEPORT);
        
        if (uiShadowBoltTimer <= diff)
        {
            if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
                DoCastVictim(SPELL_SHADOW_BOLT);
            uiShadowBoltTimer = 2000;
        } else uiShadowBoltTimer -= diff;
        
        if (uiMagicsBaneTimer <= diff)
        {
            DoCastVictim(DUNGEON_MODE(SPELL_MAGIC_S_BANE,SPELL_MAGIC_S_BANE_H));
            uiMagicsBaneTimer = urand(8000,15000);
        } else uiMagicsBaneTimer -= diff;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_bronjahm(Creature* pCreature)
{
    return new boss_bronjahmAI(pCreature);
}

struct mob_corrupted_soul_fragmentAI : public ScriptedAI
{
    mob_corrupted_soul_fragmentAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = m_creature->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;
    
    void Reset()
    {
        SetCombatMovement(false);
        if (pInstance)
            if (Creature* pBronjham = Unit::GetCreature(*m_creature,pInstance->GetData64(DATA_BRONJAHM)))
                m_creature->GetMotionMaster()->MoveChase(pBronjham);

    }
    
    void MovementInform(uint32 type, uint32 id)
    {
        if (pInstance)
            if (Creature* pBronjham = Unit::GetCreature(*m_creature,pInstance->GetData64(DATA_BRONJAHM)))
                DoCast(pBronjham,DUNGEON_MODE(SPELL_CONSUME_SOUL,SPELL_CONSUME_SOUL_H));
    }

    void UpdateAI(const uint32 diff) {}
};

CreatureAI* GetAI_mob_corrupted_soul_fragment(Creature* pCreature)
{
    return new mob_corrupted_soul_fragmentAI(pCreature);
}

void AddSC_boss_bronjahm()
{
    Script *newscript;
    
    newscript = new Script;
    newscript->Name = "mob_corruptel_soul_fragment";
    newscript->GetAI = &GetAI_mob_corrupted_soul_fragment;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_bronjahm";
    newscript->GetAI = &GetAI_boss_bronjahm;
    newscript->RegisterSelf();
}