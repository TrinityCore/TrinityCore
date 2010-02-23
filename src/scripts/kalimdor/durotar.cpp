/* Copyright (C) 2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptedPch.h"

/*######
##Quest 5441: Lazy Peons
##npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = -1999900   //Ow! OK, I''ll get back to work, $N!'
};

enum LazyPeon
{
    QUEST_LAZY_PEONS                              = 5441,
    GO_LUMBERPILE                                 = 175784,
    SPELL_BUFF_SLEEP                              = 17743,
    SPELL_AWAKEN_PEON                             = 19938
};

struct npc_lazy_peonAI : public ScriptedAI
{
    npc_lazy_peonAI(Creature *c) : ScriptedAI(c) {}
    
    uint64 uiPlayerGUID;
    
    uint32 m_uiRebuffTimer;
    uint32 work;
    
    void Reset ()
    {
        uiPlayerGUID = 0;
        work = false;
    }
    
    void MovementInform(uint32 type, uint32 id)
    {
        if (id == 1)
            work = true;
    }
    
    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_AWAKEN_PEON && caster->GetTypeId() == TYPEID_PLAYER
            && CAST_PLR(caster)->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
        {
            ((Player *)caster)->KilledMonsterCredit(m_creature->GetEntry(),m_creature->GetGUID());
            DoScriptText(SAY_SPELL_HIT, m_creature, caster);
            m_creature->RemoveAllAuras();
            if(GameObject* Lumberpile = m_creature->FindNearestGameObject(GO_LUMBERPILE, 20))
                m_creature->GetMotionMaster()->MovePoint(1,Lumberpile->GetPositionX()-1,Lumberpile->GetPositionY(),Lumberpile->GetPositionZ());
        }
    }
    
    void UpdateAI(const uint32 uiDiff)
    {
        if (work = true)
            m_creature->HandleEmoteCommand(466);
        if (m_uiRebuffTimer <= uiDiff)
        {
            DoCast(m_creature, SPELL_BUFF_SLEEP);
            m_uiRebuffTimer = 300000;                 //Rebuff agian in 5 minutes
        }
        else
            m_uiRebuffTimer -= uiDiff;
        if (!UpdateVictim())
            return;
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_lazy_peon(Creature* pCreature)
{
    return new npc_lazy_peonAI(pCreature);
}

void AddSC_durotar()
{
    Script* newscript;
    
    newscript = new Script;
    newscript->Name = "npc_lazy_peon";
    newscript->GetAI = &GetAI_npc_lazy_peon;
    newscript->RegisterSelf();
}