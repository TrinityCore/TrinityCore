/* Copyright (C) 2009 - 2011 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"

enum
{
    GO_DOOR = 179549,
    NPC_IRONBARK_THE_REDEEMED = 14241,
};
struct npc_ecorceferAI : public ScriptedAI
{
    npc_ecorceferAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCheckDoorTimer;
    bool m_bHasBrokenDoor;
    bool m_bIsZevrimDead;

    void Reset() override
    {
        m_uiCheckDoorTimer = 0;
        m_bHasBrokenDoor   = false;
        m_bIsZevrimDead    = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_bIsZevrimDead)
        {
            instance_dire_maul* pInstance = (instance_dire_maul*) m_creature->GetInstanceData();
            if (pInstance && pInstance->GetData(TYPE_BOSS_ZEVRIM) == DONE)
            {
                if (m_creature->GetEntry() == NPC_OLD_IRONBARK)
                {
                    m_creature->UpdateEntry(NPC_IRONBARK_THE_REDEEMED);
                    m_creature->MonsterYell("At last... Freed from his curse grasp!",0,0);
                }
                m_bIsZevrimDead = true;
            }
        }

        if (!m_uiCheckDoorTimer)
            return;

        if (m_uiCheckDoorTimer <= uiDiff)
        {
            if (!m_bHasBrokenDoor)
            {
                if (GameObject* pGo = m_creature->FindNearestGameObject(GO_DOOR, 10.0f))
                {
                    pGo->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    m_creature->MonsterSay("My strength wanes, mortal. I have done as promised, the way is clear. I now return to whence I came", 0, 0);
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_ATTACKUNARMED);
                    m_bHasBrokenDoor = true;
                    m_creature->DoKillUnit();
                }
            }
            m_uiCheckDoorTimer = 250;
        }
        else
            m_uiCheckDoorTimer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_ecorcefer(Creature* pCreature)
{
    return new npc_ecorceferAI(pCreature);
}

bool GossipSelect_npc_ecorcefer(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    instance_dire_maul* pInstance = (instance_dire_maul*) _Creature->GetInstanceData();
    if (!pInstance || pInstance->GetData(TYPE_BOSS_ZEVRIM) != DONE || pInstance->GetData(TYPE_SPEAK_ECORCEFER) == DONE)
    {
//        _Creature->MonsterSay("Cheater Spotted", 0, 0);
        return true;
    }
    _Creature->MonsterSay("As you wish...", 0, 0);
    _Creature->MonsterMoveWithSpeed(123.706f, -278.828f, -55.868f, -10.0f, 10, uint32(MOVE_PATHFINDING | MOVE_FORCE_DESTINATION));
    ((npc_ecorceferAI*)_Creature->AI())->m_uiCheckDoorTimer = 10000;
    pInstance->SetData(TYPE_SPEAK_ECORCEFER, DONE);
    return true;
}

bool GossipHello_npc_ecorcefer(Player *player, Creature *_Creature)
{
    instance_dire_maul* pInstance = (instance_dire_maul*) _Creature->GetInstanceData();
    if (!pInstance || pInstance->GetData(TYPE_BOSS_ZEVRIM) != DONE)
    {
        //player->ADD_GOSSIP_ITEM(0, "Vous devez tuer Zevrim !",GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        //player->SEND_GOSSIP_MENU(_Creature->GetEntry(),_Creature->GetGUID());
        return false;
    }
    if (pInstance->GetData(TYPE_SPEAK_ECORCEFER) == DONE)
    {
        //player->ADD_GOSSIP_ITEM(0, "Porte deja cassee !",GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        //player->SEND_GOSSIP_MENU(_Creature->GetEntry(),_Creature->GetGUID());
        return false;
    }
    player->ADD_GOSSIP_ITEM(0, "Thank you, Ironbark. We are ready for you to open the door.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->SEND_GOSSIP_MENU(6695, _Creature->GetGUID());
    return true;
}

void AddSC_npc_ecorcefer()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "npc_ecorcefer";
    pNewScript->pGossipHello   = &GossipHello_npc_ecorcefer;
    pNewScript->pGossipSelect  = &GossipSelect_npc_ecorcefer;
    pNewScript->GetAI          = &GetAI_npc_ecorcefer;
    pNewScript->RegisterSelf();
}
