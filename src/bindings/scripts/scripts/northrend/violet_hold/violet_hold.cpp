#include "precompiled.h"
#include "def_violet_hold.h"

#define GOSSIP_START_EVENT "[PH]: Start Event"
#define NEXT_WAVE_TIME        90000
#define SPAWN_TIME             9000

enum Creatures
{
    CREATURE_AZURE_INVADER            = 30661,
    CREATURE_AZURE_SPELLBREAKER       = 30662,
    CREATURE_AZURE_BINDER             = 30663,
    CREATURE_AZURE_MAGE_SLAYER        = 30664,
    CREATURE_AZURE_CAPTAIN            = 30666
};

bool GossipHello_npc_sinclari(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance && pInstance->GetData(DATA_WAVE_COUNT) == 0)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_START_EVENT,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_sinclari(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    pPlayer->CLOSE_GOSSIP_MENU();
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance)
        pInstance->SetData(DATA_WAVE_COUNT,1);
    return true;
}

struct TRINITY_DLL_DECL npc_teleportation_portalAI : public ScriptedAI
{
    npc_teleportation_portalAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiDespawnTimer;
    uint32 uiSpawnTimer;

    ScriptedInstance *pInstance;

    void reset()
    {
        uiDespawnTimer = NEXT_WAVE_TIME;
        uiSpawnTimer = 500;
    }

    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (uiSpawnTimer < diff)
        {
            if (Creature* pSummon = m_creature->SummonCreature(RAND(CREATURE_AZURE_CAPTAIN,CREATURE_AZURE_SPELLBREAKER,
                                                               CREATURE_AZURE_BINDER,CREATURE_AZURE_MAGE_SLAYER,CREATURE_AZURE_CAPTAIN),
                                                       m_creature->GetPositionX()+rand()%3, m_creature->GetPositionY()+rand()%3,
                                                       m_creature->GetPositionZ(),m_creature->GetOrientation(),
                                                       TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
                pSummon->Attack(pSummon->SelectNearestTarget(100),true);
            uiSpawnTimer = SPAWN_TIME;
        } else uiSpawnTimer -= diff;
        if (uiDespawnTimer < diff)
        {
            m_creature->Kill(m_creature);
            m_creature->RemoveCorpse();
        } else uiDespawnTimer -= diff;
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_WAVE_COUNT,pInstance->GetData(DATA_WAVE_COUNT)+1);
    }
};

CreatureAI* GetAI_npc_teleportation_portal(Creature *pCreature)
{
    return new npc_teleportation_portalAI(pCreature);
}

void AddSC_violet_hold()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_sinclari_vh";
    newscript->pGossipHello = &GossipHello_npc_sinclari;
    newscript->pGossipSelect = &GossipSelect_npc_sinclari;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_teleportation_portal_vh";
    newscript->GetAI = &GetAI_npc_teleportation_portal;
    newscript->RegisterSelf();
}
