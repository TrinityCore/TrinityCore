#include "ScriptedPch.h"
#include "violet_hold.h"

#define GOSSIP_START_EVENT  "Get your people to safety, we'll keep the Blue Dragonflight's forces at bay."
#define GOSSIP_ITEM_1       "Activate the crystals when we get in trouble, right"
#define SPAWN_TIME          20000

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

enum Spells
{
    SPELL_PORTAL_CHANNEL              = 58012
};

enum eSinclari
{
    NPC_VIOLET_HOLD_GUARD             = 30659,

    SAY_SINCLARI_1                    = -1608045,
};

const Position DoorPosition = { 1828.300049, 797.309021, 46.135502, 1.48353};
const Position MovePosition = { 1806.955566, 803.851807, 44.363323};

struct npc_sinclariAI : public ScriptedAI
{
    npc_sinclariAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
       pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint8  uiPhase;
    uint32 uiTimer;

    std::list<Creature*> GuardList;

    void Reset()
    {
        uiPhase = 0;
        uiTimer = 0;

        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->SetReactState(REACT_AGGRESSIVE);

        m_creature->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
        if (!GuardList.empty())
            for (std::list<Creature*>::iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
            {
                if (Creature* pGuard = *itr)
                {
                    pGuard->DisappearAndDie();
                    pGuard->Respawn();
                    pGuard->SetVisibility(VISIBILITY_ON);
                    pGuard->SetReactState(REACT_AGGRESSIVE);
                }
            }
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (pInstance)
        {
            pInstance->SetData(DATA_WAVE_COUNT,1);
            pInstance->SetData(DATA_REMOVE_NPC,0); // might not have been reset after a wipe on a boss.
        }

        //She should not be despawned, she will be used by the instance to summon some npcs
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->SetReactState(REACT_PASSIVE);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        ScriptedAI::UpdateAI(uiDiff);

        if (uiPhase)
        {
            if (uiTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 1:
                       DoScriptText(SAY_SINCLARI_1, m_creature);
                       uiTimer = 4000;
                       uiPhase = 2;
                       break;
                    case 2:
                        m_creature->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                        if (!GuardList.empty())
                            for (std::list<Creature*>::iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                            {
                                if (Creature* pGuard = *itr)
                                {
                                    pGuard->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                    pGuard->GetMotionMaster()->MovePoint(0, MovePosition);
                                }
                            }
                        uiTimer = 6000;
                        uiPhase = 3;
                        break;
                    case 3:
                        m_creature->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                        if (!GuardList.empty())
                            for (std::list<Creature*>::iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                            {
                                if (Creature* pGuard = *itr)
                                {
                                    pGuard->SetVisibility(VISIBILITY_OFF);
                                    pGuard->SetReactState(REACT_PASSIVE);
                                }
                            }
                        uiTimer = 2000;
                        uiPhase = 4;
                        break;
                    case 4:
                        m_creature->GetMotionMaster()->MovePoint(0, MovePosition);
                        uiTimer = 0;
                        uiPhase = 0;
                        break;
                }
            }
            else uiTimer -= uiDiff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_sinclari(Creature* pCreature)
{
    return new npc_sinclariAI(pCreature);
}

bool GossipHello_npc_sinclari(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance && pInstance->GetData(DATA_CYANIGOSA_EVENT) != DONE && pInstance->GetData(DATA_WAVE_COUNT) == 0 && pPlayer)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_START_EVENT,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(13853, pCreature->GetGUID());
    }else
        pPlayer->SEND_GOSSIP_MENU(13910, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_sinclari(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            if (pPlayer)
                pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_sinclariAI, (pCreature->AI()))->uiPhase = 1;
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->SEND_GOSSIP_MENU(13854, pCreature->GetGUID());
            break;
    }
    return true;
}

struct npc_teleportation_portalAI : public ScriptedAI
{
    npc_teleportation_portalAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiSpawnTimer;
    bool bPortalGuardianOrKeeperSpawn;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiSpawnTimer = 10000;
        bPortalGuardianOrKeeperSpawn = false;
    }

    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (pInstance && pInstance->GetData(DATA_REMOVE_NPC) == 1)
        {
            m_creature->ForcedDespawn();
            pInstance->SetData(DATA_REMOVE_NPC, 0);
        }

        if (uiSpawnTimer <= diff)
        {
            if (bPortalGuardianOrKeeperSpawn)
            {
                uint8 k = pInstance->GetData(DATA_WAVE_COUNT) < 12 ? 2 : 3;
                for (uint8 i = 0; i < k; ++i)
                {
                    uint32 entry = RAND(CREATURE_AZURE_CAPTAIN,CREATURE_AZURE_RAIDER,CREATURE_AZURE_STALKER,CREATURE_AZURE_SORCEROR);
                    if (Creature* pSummon = DoSummon(entry, m_creature, 2.0f, 30000, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT))
                        pSummon->GetMotionMaster()->MovePoint(0, DoorPosition);
                }
            }
            else 
            {
                bPortalGuardianOrKeeperSpawn = true;
                uint32 entry = RAND(CREATURE_PORTAL_GUARDIAN, CREATURE_PORTAL_KEEPER);
                if (Creature *pPortalKeeper = DoSummon(entry, m_creature, 2.0f, 0, TEMPSUMMON_DEAD_DESPAWN))
                    m_creature->CastSpell(pPortalKeeper, SPELL_PORTAL_CHANNEL, false);
            }
            uiSpawnTimer = SPAWN_TIME;
        } else uiSpawnTimer -= diff;

        if (bPortalGuardianOrKeeperSpawn && !m_creature->IsNonMeleeSpellCasted(false))
        {
            m_creature->Kill(m_creature, false);
            m_creature->RemoveCorpse();
            return;
        }
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
    newscript->GetAI = &GetAI_npc_sinclari;
    newscript->pGossipHello = &GossipHello_npc_sinclari;
    newscript->pGossipSelect = &GossipSelect_npc_sinclari;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_teleportation_portal_vh";
    newscript->GetAI = &GetAI_npc_teleportation_portal;
    newscript->RegisterSelf();
}
