#include "precompiled.h"
#include "violet_hold.h"

#define GOSSIP_START_EVENT "[PH]: Start Event"
#define NEXT_WAVE_TIME        90000
#define SPAWN_TIME            15000

enum PortalCreatures
{
    CREATURE_AZURE_INVADER            = 30661,
    CREATURE_AZURE_SPELLBREAKER       = 30662,
    CREATURE_AZURE_BINDER             = 30663,
    CREATURE_AZURE_MAGE_SLAYER        = 30664,
    CREATURE_AZURE_CAPTAIN            = 30666,
    CREATURE_AZURE_SORCEROR           = 30667,
    CREATURE_AZURE_RAIDER             = 30668,
    CREATURE_AZURE_STALKER            = 32191
};

bool GossipHello_npc_sinclari(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance && pInstance->GetData(DATA_WAVE_COUNT) == 0 && pPlayer)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_START_EVENT,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_sinclari(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (pPlayer)
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

    void Reset()
    {
        uiDespawnTimer = NEXT_WAVE_TIME;
        uiSpawnTimer = 3000;
    }

    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (uiSpawnTimer <= diff)
        {
            uint8 k = pInstance->GetData(DATA_WAVE_COUNT) < 12 ? 3 : 4;
            for (uint8 i = 0; i < k; ++i)
            {
                if (Creature* pSummon = m_creature->SummonCreature(RAND(CREATURE_AZURE_CAPTAIN,CREATURE_AZURE_RAIDER,CREATURE_AZURE_STALKER,CREATURE_AZURE_SORCEROR),
                                                       m_creature->GetPositionX()+urand(0,2), m_creature->GetPositionY()+urand(0,2),
                                                       m_creature->GetPositionZ(),m_creature->GetOrientation(),
                                                       TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
                    if (Creature* pTarget = GetClosestCreatureWithEntry(m_creature, CREATURE_SINCLARI, 150.0f))
                    {
                        pSummon->Attack(pTarget, true);
                    }
            }
            uiSpawnTimer = SPAWN_TIME;
        } else uiSpawnTimer -= diff;

        if (!m_creature->IsNonMeleeSpellCasted(false))
        {
            m_creature->Kill(m_creature, false);
            m_creature->RemoveCorpse();
            return;
        }

        if (uiDespawnTimer <= diff)
        {
            m_creature->Kill(m_creature, false);
            m_creature->RemoveCorpse();
        }
        else
            uiDespawnTimer -= diff;
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
