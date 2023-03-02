/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon, Chakor
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"

//#define DEBUG_ON

void EnableCreature(Creature* pCreature)
{
    pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
}

instance_dire_maul::instance_dire_maul(Map* pMap) : ScriptedInstance(pMap),
    // East
    m_uiDoorAlzzinInGUID(0),
    m_uiCrumbleWallGUID(0),
    m_uiCorruptVineGUID(0),
    
    // West
    m_uiMagicVortexGUID(0),
    m_uiForceFieldGUID(0),
    m_uiImmolTharGUID(0),
    m_uiTortheldrinGUID(0),
    m_uiRitualCandleAuraGUID(0),
    m_uiRitualPlayerGUID(0),
    
    // North
    m_uiGuardAliveCount(6),
    m_uiTendrisGUID(0),
    m_uiOldIronbarkGUID(0),
    m_uiSlipKikGUID(0),
    m_uiCaptainKromcrushGUID(0),
    m_uiKingGordokGUID(0),
    m_uiChoRushTheObserverGUID(0),
    m_uiChoRushEquipment(0),

    m_uiGordokTribute0GUID(0),
    m_uiGordokTribute1GUID(0),
    m_uiGordokTribute2GUID(0),
    m_uiGordokTribute3GUID(0),
    m_uiGordokTribute4GUID(0),
    m_uiGordokTribute5GUID(0),
    m_uiGordokTribute6GUID(0),

    m_uiBrokenTrapGUID(0),
    m_bIsGordokTributeRespawned(false),
    m_bIsTanninLooted(false)
{
    Initialize();
}

void instance_dire_maul::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    memset(&m_auiCristalsGUID, 0, sizeof(m_auiCristalsGUID));
    m_lFelvineShardGUIDs.clear();
}

void instance_dire_maul::OnPlayerEnter(Player* pPlayer)
{
    if (!pPlayer)
        return;

    // prevent instance reset exploit
    if (pPlayer->HasItemCount(ITEM_GORDOK_INNER_DOOR_KEY, 1))
    {
        if (GetData(TYPE_MOLDAR) != DONE)
            pPlayer->DestroyItemCount(ITEM_GORDOK_INNER_DOOR_KEY, 1, true);
    }

    // set the trap again if server went down
    if (GetData(TYPE_BROKEN_TRAP) == DONE)
    {
        if (GameObject* pGo = instance->GetGameObject(m_uiBrokenTrapGUID))
        {
            pPlayer->SummonGameObject(GO_FIXED_TRAP, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), 0.0f, 0, 0, 0, 0, 43200);
            pGo->Delete();
        }
    }
}

void instance_dire_maul::OnPlayerLeave(Player* pPlayer)
{
    if (!pPlayer)
        return;

    pPlayer->RemoveAurasDueToSpell(SPELL_KING_OF_GORDOK);
        /*
        if (pPlayer->HasItemCount(ITEM_GORDOK_COURTYARD_KEY, 1))
            pPlayer->DestroyItemCount(ITEM_GORDOK_COURTYARD_KEY, 1, true);
        */
}

void instance_dire_maul::OnObjectCreate(GameObject* pGo)
{
    switch (pGo->GetEntry())
    {
        // DM East
        case GO_CRUMBLE_WALL:
            m_uiCrumbleWallGUID = pGo->GetObjectGuid();
            if (m_auiEncounter[TYPE_ALZZIN] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break; 
        case GO_CORRUPT_VINE:
            m_uiCorruptVineGUID = pGo->GetObjectGuid();
            if (m_auiEncounter[TYPE_ALZZIN] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_FELVINE_SHARD:
            m_lFelvineShardGUIDs.push_back(pGo->GetObjectGuid());
            break;
        case GO_DOOR_ALZZIN_IN  :
            m_uiDoorAlzzinInGUID   = pGo->GetGUID();
            break;
        // DM West
        case GO_CRISTAL_1_EVENT :
            m_auiCristalsGUID[0]   = pGo->GetGUID();
            break;
        case GO_CRISTAL_2_EVENT :
            m_auiCristalsGUID[1]   = pGo->GetGUID();
            break;
        case GO_CRISTAL_3_EVENT :
            m_auiCristalsGUID[2]   = pGo->GetGUID();
            break;
        case GO_CRISTAL_4_EVENT :
            m_auiCristalsGUID[3]   = pGo->GetGUID();
            break;
        case GO_CRISTAL_5_EVENT :
            m_auiCristalsGUID[4]   = pGo->GetGUID();
            break;
        case GO_FORCE_FIELD     :
            m_uiForceFieldGUID     = pGo->GetGUID();
            break;
        case GO_MAGIC_VORTEX    :
            m_uiMagicVortexGUID    = pGo->GetGUID();
            break;
        // DM North
        case GO_GORDOK_TRIBUTE_0:
            m_uiGordokTribute0GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_1:
            m_uiGordokTribute1GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_2:
            m_uiGordokTribute2GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_3:
            m_uiGordokTribute3GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_4:
            m_uiGordokTribute4GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_5:
            m_uiGordokTribute5GUID = pGo->GetGUID();
            break;
        case GO_GORDOK_TRIBUTE_6:
            m_uiGordokTribute6GUID = pGo->GetGUID();
            break;
        case GO_BROKEN_TRAP:
            m_uiBrokenTrapGUID = pGo->GetGUID();
            break;
        case GO_RITUAL_CANDLE_AURA:
            m_uiRitualCandleAuraGUID = pGo->GetGUID();
            break;
        default:
            break;
    }
}

void instance_dire_maul::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_ALZZIN:
            SetData(TYPE_ALZZIN, DONE);
            break;
        case NPC_IMMOL_THAR:
            if (Creature* pTortheldrin = instance->GetCreature(m_uiTortheldrinGUID))
                pTortheldrin->MonsterYell(SAY_IMMOL_THAR_DEAD);
            break;
        case NPC_GUARD_MOLDAR:
            SetData(TYPE_MOLDAR, DONE); 
            if (GetData(TYPE_GORDOK_TRIBUTE) != DONE)
                SetData(TYPE_GORDOK_TRIBUTE, SPECIAL);
            break;
        case NPC_GUARD_FENGUS:
        case NPC_GUARD_SLIPKIK:
        case NPC_CAPTAIN_KROMCRUSH:
        case NPC_CHORUSH:
            if (GetData(TYPE_GORDOK_TRIBUTE) != DONE)
                SetData(TYPE_GORDOK_TRIBUTE, SPECIAL);
            break;
        case NPC_KING_GORDOK:
            GetMap()->SummonCreature(NPC_MIZZLE_THE_CRAFTY, 693.44f, 480.806f, 28.175f, 0.02757f, TEMPSUMMON_DEAD_DESPAWN, 3000000);

            if (Creature* pChorush = instance->GetCreature(m_uiChoRushTheObserverGUID))
            {
                if (pChorush->IsAlive())
                {
                    pChorush->SetFactionTemporary(FACTION_FRIENDLY, 0);
                    pChorush->m_Events.AddLambdaEventAtOffset([pChorush]() { DoScriptText(SAY_KING_DEAD, pChorush); }, 5000);
                }
            }
                    
            break;
    }
}

void instance_dire_maul::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_IMMOL_THAR:
            m_uiImmolTharGUID   = pCreature->GetGUID();
            if (GetData(TYPE_CRISTAL_EVENT) != DONE)
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            break;
        case NPC_TORTHELDRIN:
            m_uiTortheldrinGUID = pCreature->GetGUID();
            break;
        case NPC_RESTE_MANA:
        case NPC_ARCANE_ABERRATION:
            m_lCristalsEventtMobGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_IMMOL_THAR_GARDIEN:
            m_lImmolTharGardiensMobGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_TENDRIS:
            m_uiTendrisGUID     = pCreature->GetGUID();
            break;
        case NPC_TENDRIS_PROTECTOR:
            m_lTendrisProtectorsMobGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_OLD_IRONBARK:
            m_uiOldIronbarkGUID = pCreature->GetGUID();
            break;
        case NPC_GUARD_SLIPKIK:
            m_uiSlipKikGUID = pCreature->GetGUID();
            break;
        case NPC_CAPTAIN_KROMCRUSH:
            m_uiCaptainKromcrushGUID = pCreature->GetGUID();
            break;
        case NPC_KING_GORDOK:
            m_uiKingGordokGUID = pCreature->GetGUID();
            break;
        case NPC_CHORUSH:
            m_uiChoRushTheObserverGUID = pCreature->GetGUID();

            if (GetData(TYPE_GORDOK_TRIBUTE) == DONE)
            {
                pCreature->SetFactionTemplateId(35);
                pCreature->SetStandState(UNIT_STAND_STATE_SIT);
            }
            break; 
    }
}

void instance_dire_maul::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
        case TYPE_CRISTAL_EVENT:
        {
            if (uiData == DONE)
            {
                // Desactivation du champs de force
                DoUseDoorOrButton(m_uiForceFieldGUID);
                DoUseDoorOrButton(m_uiMagicVortexGUID);
                // Le boss devient attaquable ...
                if (Creature* pImmolThar = instance->GetCreature(m_uiImmolTharGUID))
                {
                    EnableCreature(pImmolThar);
                    // ... et ses gardiens doivent l'attaquer.
#ifdef DEBUG_ON
                    sLog.outString("Immol'Thar (%u) rendu attaquable, %u gardiens trouves.", pImmolThar->GetGUIDLow(), m_lImmolTharGardiensMobGUIDList.size());
#endif
                    bool bHasYelled = false;
                    for (const auto& guid : m_lImmolTharGardiensMobGUIDList)
                    {
                        if (Creature* pCreature = instance->GetCreature(guid))
                        {
                            // Ne pas non plus aggro toute l'instance.
                            if (pCreature->IsAlive())
                            {
                                EnableCreature(pCreature);

                                if (pCreature->GetDistance(pImmolThar) > 100.0f)
                                    continue;

                                pCreature->SetFactionTemplateId(100);

                                if (!bHasYelled)
                                {
                                    DoScriptText(SAY_FREE_IMMOLTHAR, pCreature);
                                    bHasYelled = true;
                                }

                                if (pCreature->AI())
                                    pCreature->AI()->AttackStart(pImmolThar);
                            }
                        }
                    }
                }
                else
                    sLog.outError("Immol'Thar introuvable !! GUID %u", m_uiImmolTharGUID);
            }
            m_auiEncounter[TYPE_CRISTAL_EVENT] = uiData;
            break;
        }
        case TYPE_IMMOL_THAR:
        {
            if (uiData == DONE)
            {
                if (Creature* tortheldrin = instance->GetCreature(m_uiTortheldrinGUID))
                {
                    tortheldrin->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                    tortheldrin->SetFactionTemporary(14, TEMPFACTION_RESTORE_RESPAWN);
                    sLog.outString("Tortheldrin (%u) made attackable.", tortheldrin->GetGUIDLow());
                }
                else
                    sLog.outError("Tortheldrin not found!");
            }
            m_auiEncounter[TYPE_IMMOL_THAR] = uiData;
            break;
        }
        case TYPE_BOSS_ZEVRIM:
        {
            if (uiData == DONE)
            {
#ifdef DEBUG_ON
                sLog.outString("Zevrim DOWN");
#endif
            }
            m_auiEncounter[TYPE_BOSS_ZEVRIM] = uiData;
            break;
        }
        case DATA_TENDRIS_AGGRO:
        {
            break;
        }
        case TYPE_SPEAK_ECORCEFER:
        {
            if (uiData == DONE)
            {
#ifdef DEBUG_ON
                sLog.outString("EcorceFer Speak OK");
#endif
                DoUseDoorOrButton(m_uiDoorAlzzinInGUID);
            }
            m_auiEncounter[TYPE_SPEAK_ECORCEFER] = uiData;
            break;
        }
        case TYPE_GORDOK_TRIBUTE:
        {
            if (uiData == SPECIAL)
            {
                // Les gardes renvoient SPECIAL à leur mort via eventAI
                --m_uiGuardAliveCount;
                SetData(TYPE_GORDOK_TRIBUTE, IN_PROGRESS);
            }
            if (uiData == DONE)
            {
                if (m_bIsGordokTributeRespawned)
                    return;

                uint32 finalGuardStatus = m_uiGuardAliveCount;

                switch (finalGuardStatus)
                {
                    case 0:
                        DoRespawnGameObject(m_uiGordokTribute6GUID);
                        break;
                    case 1:
                        DoRespawnGameObject(m_uiGordokTribute5GUID);
                        break;
                    case 2:
                        DoRespawnGameObject(m_uiGordokTribute4GUID);
                        break;
                    case 3:
                        DoRespawnGameObject(m_uiGordokTribute3GUID);
                        break;
                    case 4:
                        DoRespawnGameObject(m_uiGordokTribute2GUID);
                        break;
                    case 5:
                        DoRespawnGameObject(m_uiGordokTribute1GUID);
                        break;
                    case 6:
                        DoRespawnGameObject(m_uiGordokTribute0GUID);
                        break;
                }
                m_bIsGordokTributeRespawned = true;
            }
            m_auiEncounter[TYPE_GORDOK_TRIBUTE] = uiData;
            break;
        }
        case TYPE_BROKEN_TRAP:
            m_auiEncounter[TYPE_BROKEN_TRAP] = uiData;
            break;
        case TYPE_GORDOK_OGRE_SUIT:
            m_auiEncounter[TYPE_GORDOK_OGRE_SUIT] = uiData;
            break;
        case TYPE_CHORUSH_EQUIPMENT:
            m_auiEncounter[TYPE_CHORUSH_EQUIPMENT] = uiData;
            break;
        case TYPE_MOLDAR:
            m_auiEncounter[TYPE_MOLDAR] = uiData;
            break;
        case TYPE_ALZZIN:
            if (uiData == SPECIAL)
            {
                DoUseDoorOrButton(m_uiCrumbleWallGUID);
            }
            else if (uiData == DONE)
            {
                DoUseDoorOrButton(m_uiCorruptVineGUID);

                if (!m_lFelvineShardGUIDs.empty())
                {
                    for (const auto& guid : m_lFelvineShardGUIDs)
                        DoRespawnGameObject(guid);
                }
            }
            m_auiEncounter[uiType] = uiData;
            break;
        case DATA_TANNIN_LOOTED:
        {
            m_bIsTanninLooted = uiData;
            break;
        }
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " 
                   << m_auiEncounter[4] << " " << m_auiEncounter[6] << " " << m_auiEncounter[7] << " "
                   << m_auiEncounter[8] << " " << m_auiEncounter[9] << " " << m_auiEncounter[10] << " "
                   << m_auiEncounter[11];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_dire_maul::SetData64(uint32 uiType, uint64 uiData)
{
#ifdef DEBUG_ON
    sLog.outString("SetData64(%u, %u) data is %u", uiType, uiData, GetData(TYPE_CRISTAL_EVENT));
#endif

    if (uiType == TYPE_CRISTAL_EVENT && GetData(TYPE_CRISTAL_EVENT) == NOT_STARTED)
        DoSortCristalsEventMobs();

    if (uiType == TYPE_CRISTAL_EVENT && GetData(TYPE_CRISTAL_EVENT) == IN_PROGRESS)
    {
        uint8 uiNotEmptyRoomsCount = 0;
        for (uint8 i = 0; i < MAX_CRISTALS; i++)
        {
            if (m_auiCristalsGUID[i])                       // This check is used, to ensure which runes still need processing
            {
                m_alCristalsEventtMobGUIDSorted[i].remove(uiData);
                if (m_alCristalsEventtMobGUIDSorted[i].empty())
                {
                    DoUseDoorOrButton(m_auiCristalsGUID[i]);
#ifdef DEBUG_ON
                    sLog.outString("ACTIVATION d'un cristal. Numero %u", i + 1);
#endif
                    m_auiCristalsGUID[i] = 0;
                }
                else
                    uiNotEmptyRoomsCount++;                 // found an not empty room
            }
        }
        if (!uiNotEmptyRoomsCount)
            SetData(TYPE_CRISTAL_EVENT, DONE);
    }

    if (uiType == DATA_DREADSTEED_RITUAL_PLAYER)
        m_uiRitualPlayerGUID = uiData;
}

void instance_dire_maul::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4]
               >> m_auiEncounter[6] >> m_auiEncounter[7] >> m_auiEncounter[8] >> m_auiEncounter[9]
               >> m_auiEncounter[10] >> m_auiEncounter[11];

    for (uint32 & i : m_auiEncounter)
        if (i == IN_PROGRESS)
            i = NOT_STARTED;

    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_dire_maul::GetData(uint32 uiType)
{
    if (uiType == DATA_TANNIN_LOOTED)
        return m_bIsTanninLooted;

    ASSERT(uiType < INSTANCE_DIRE_MAUL_MAX_ENCOUNTER);
    return m_auiEncounter[uiType];
}

uint64 instance_dire_maul::GetData64(uint32 uiType)
{
    switch (uiType)
    {
        case NPC_GUARD_SLIPKIK:
            return m_uiSlipKikGUID;
        case NPC_CHORUSH:
            return m_uiChoRushTheObserverGUID;
        case NPC_KING_GORDOK:
            return m_uiKingGordokGUID;
        case NPC_IMMOL_THAR:
            return m_uiImmolTharGUID;
        case NPC_TORTHELDRIN:
            return m_uiTortheldrinGUID;
        case GO_FORCE_FIELD:
            return m_uiForceFieldGUID;
        case GO_MAGIC_VORTEX:
            return m_uiMagicVortexGUID;
        case GO_RITUAL_CANDLE_AURA:
            return m_uiRitualCandleAuraGUID;
        case DATA_DREADSTEED_RITUAL_PLAYER:
            return m_uiRitualPlayerGUID;
    }
    return 0;
}

uint8 instance_dire_maul::GetChoRushEquipment()
{
    m_uiChoRushEquipment = GetData(TYPE_CHORUSH_EQUIPMENT);
    if (!m_uiChoRushEquipment)
    {
        m_uiChoRushEquipment = urand(1, 3);
        SetData(TYPE_CHORUSH_EQUIPMENT, m_uiChoRushEquipment);
    }
    return m_uiChoRushEquipment;
}

void instance_dire_maul::DoSortCristalsEventMobs()
{
    if (GetData(TYPE_CRISTAL_EVENT) != NOT_STARTED)
        return;
#ifdef DEBUG_ON
    sLog.outString("instance_dire_maul::DoSortCristalsEventMobs");
#endif
    for (uint8 i = 0; i < MAX_CRISTALS; i++)
    {
        if (GameObject* pRune = instance->GetGameObject(m_auiCristalsGUID[i]))
        {
            for (const auto& guid : m_lCristalsEventtMobGUIDList)
            {
                if (Creature* pCreature = instance->GetCreature(guid))
                {
                    if (pCreature->IsAlive() && pCreature->GetDistance(pRune) < 20.0f)
                        m_alCristalsEventtMobGUIDSorted[i].push_back(guid);
                }
            }
#ifdef DEBUG_ON
            sLog.outString("Cristal %u : %u mobs", i + 1,  m_alCristalsEventtMobGUIDSorted[i].size());
#endif
        }
    }

    SetData(TYPE_CRISTAL_EVENT, IN_PROGRESS);
}

InstanceData* GetInstanceData_instance_dire_maul(Map* pMap)
{
    return new instance_dire_maul(pMap);
}

// TRASH
// npc_reste_mana
enum
{
    SPELL_CHAINLIGHTNING     = 15659,
    SPELL_BLINK              = 14514
};
struct npc_reste_manaAI : public ScriptedAI
{
    npc_reste_manaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiChainLighting_Timer;
    uint32 m_uiBlink_Timer;

    void Reset() override
    {
        m_uiBlink_Timer = urand(12000, 23000);
        m_uiChainLighting_Timer = urand(2000, 6000);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData64(TYPE_CRISTAL_EVENT, m_creature->GetGUID());
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (m_uiBlink_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BLINK);
            m_uiBlink_Timer = 6000;
            return;
        }   
        else
            m_uiBlink_Timer -= uiDiff;

        if (m_uiChainLighting_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHAINLIGHTNING);
            m_uiChainLighting_Timer = 6000;
            return;
        }
        else
            m_uiChainLighting_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_reste_mana(Creature* pCreature)
{
    return new npc_reste_manaAI(pCreature);
}

// npc_arcane_aberration (11480)
enum
{
    SPELL_MANABURN           = 22936,
    SPELL_ARCANEBOLT         = 15979
};
struct npc_arcane_aberrationAI : public ScriptedAI
{
    npc_arcane_aberrationAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiArcaneBoltTimer;
    bool m_bManaBurnDone;

    void Reset() override
    {
        m_uiArcaneBoltTimer = urand(0, 400);
        m_bManaBurnDone = false;
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData64(TYPE_CRISTAL_EVENT, m_creature->GetGUID());
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (m_creature->GetHealthPercent() > 5.0f)
            return;

        if (!m_bManaBurnDone)
        {
            DoCastSpellIfCan(m_creature, SPELL_MANABURN);
            m_bManaBurnDone = true;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (m_uiArcaneBoltTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEBOLT);
            m_uiArcaneBoltTimer = urand(2400, 3800);
            return;
        }
        else
            m_uiArcaneBoltTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_arcane_aberration(Creature* pCreature)
{
    return new npc_arcane_aberrationAI(pCreature);
}

// npc_residual_montruosity (11484)
enum
{
    SPELL_ARCANEBLAST        = 22940,
    SPELL_SUMMON_MANABURSTS  = 22939,
    SPELL_ARCANEBOLT2        = 13748
};
struct npc_residual_montruosityAI : public ScriptedAI
{
    npc_residual_montruosityAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiArcaneBoltTimer;
    uint32 m_uiArcaneBlastTimer;

    void Reset() override
    {
        m_uiArcaneBlastTimer = urand(1000, 2500);
        m_uiArcaneBoltTimer = urand(0, 400);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
    }

    void JustDied(Unit* pKiller) override
    {
        DoCastSpellIfCan(m_creature, SPELL_SUMMON_MANABURSTS);
    }

    void UpdateFormationSpeed()
    {
        float newspeed = 1.79f;
        if (!m_creature->GetVictim())
        {

            float closestbefore = 45.0f;
            float closestbehind = 45.0f;

            std::list<Creature*> montruosityList;
            GetCreatureListWithEntryInGrid(montruosityList, m_creature, 11484, 45.0f);
            if (!montruosityList.empty())
            {
                for (const auto& itr : montruosityList)
                {
                    if (itr != m_creature)
                    {
                        if (!itr->isInFrontInMap(m_creature, 45.0f, M_PI_F))
                        {
                            float distance = m_creature->GetDistance(itr);
                            if (distance < closestbefore)
                                closestbefore = distance;
                        }
                        else
                        {
                            float distance = m_creature->GetDistance(itr);
                            if (distance < closestbehind)
                                closestbehind = distance;
                        }
                    }
                }
            }
            if ((closestbefore > 36.0f) && (closestbehind < 32.0f))
                newspeed = 2.20f;
            else if ((closestbefore < 32.0f) && (closestbehind > 36.0f))
                newspeed = 1.00f;
        }
        m_creature->SetSpeedRate(MOVE_WALK, newspeed);
    }

    void UpdateAI(uint32 const uiDiff) override
    {

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            UpdateFormationSpeed();
            return;
        }

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (m_uiArcaneBoltTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEBOLT2);
            m_uiArcaneBoltTimer = urand(2400, 3800);
            return;
        }
        else
            m_uiArcaneBoltTimer -= uiDiff;

        if (m_uiArcaneBlastTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_ARCANEBLAST);
            m_uiArcaneBlastTimer = urand(3800, 5200);
            return;
        }
        else
            m_uiArcaneBlastTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_residual_montruosity(Creature* pCreature)
{
    return new npc_residual_montruosityAI(pCreature);
}

/*######
## go_broken_trap
######*/

enum
{
    QUEST_A_BROKEN_TRAP     = 1193
};

bool QuestRewarded_go_broken_trap(Player* pPlayer, GameObject* pGo, Quest const* pQuest)
{
    if (instance_dire_maul* pInstance = (instance_dire_maul*)pPlayer->GetInstanceData())
    {
        if (pQuest->GetQuestId() == QUEST_A_BROKEN_TRAP)
        {
            pInstance->SetData(TYPE_BROKEN_TRAP, DONE);
            pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            pPlayer->SummonGameObject(GO_FIXED_TRAP, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), pGo->GetOrientation(), 0, 0, 0, 0, 43200);
            pGo->Delete();
            return true;
        }
    }

    return false;
}

/*######
## npc_mizzle_the_crafty
######*/

enum
{
    SAY_KILL_KING_1      = -1900012,
    SAY_KILL_KING_2      = -1900013,
};

struct npc_mizzle_the_craftyAI : public ScriptedAI
{
    npc_mizzle_the_craftyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        m_creature->SetHomePosition(816.30f, 481.80f, 37.30f, 3.170f);
        m_creature->GetMotionMaster()->MoveTargetedHome();
        m_bJustReachedHome = false;
        DoScriptText(SAY_KILL_KING_1, m_creature);
    }

    bool m_bJustReachedHome;
    instance_dire_maul* m_pInstance;

    void Reset() override {}

    void JustReachedHome() override
    {
        if (!m_bJustReachedHome)
        {
            DoScriptText(SAY_KILL_KING_2, m_creature);
            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            m_bJustReachedHome = true;
        }
    }

    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        m_creature->SetOrientation(3.170f);
    }
};

CreatureAI* GetAI_npc_mizzle_the_crafty(Creature* pCreature)
{
    return new npc_mizzle_the_craftyAI(pCreature);
}

/*######
## npc_knot_thimblejack
######*/

enum
{
    SPELL_GORDOK_OGRE_SUIT_T    = 22813,
    SPELL_GORDOK_OGRE_SUIT_L    = 22815,
    SPELL_LEARN_GOS_T           = 22814,
    SPELL_LEARN_GOS_L           = 22816,

    QUEST_GORDOK_OGRE_SUIT      = 5518,
    QUEST_FREE_KNOT             = 5525,
    QUEST_FREE_KNOT_REPEATABLE  = 7429,

    GOSSIP_MENU_1               = 6795,
    GOSSIP_MENU_2               = 6883,

    GO_KNOTS_BALL_AND_CHAIN     = 179511,
};

struct npc_knot_thimblejackAI : public ScriptedAI
{
    npc_knot_thimblejackAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;

    void Reset() override {}

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case 1:
                me->GetMotionMaster()->MovePoint(2, 470.225372f, 542.596065f, -25.363186f);
                break;
            case 2:
                me->GetMotionMaster()->MovePoint(3, 465.367096f, 542.843689f, -23.911942f);
                break;
            case 3:
                me->GetMotionMaster()->MovePoint(4, 453.346649f, 544.004456f, -23.900503f);
                break;
            case 4:
                me->GetMotionMaster()->MovePoint(5, 435.055573f, 542.503967f, -18.395958f);
                break;
            case 5:
                me->GetMotionMaster()->MovePoint(6, 412.700775f, 537.009277f, -18.343367f);
                break;
            case 6:
                me->GetMotionMaster()->MovePoint(7, 401.076355f, 524.250061f, -12.787789f);
                break;
            case 7:
                me->GetMotionMaster()->MovePoint(8, 390.540833f, 502.830505f, -12.675946f);
                break;
            case 8:
                me->GetMotionMaster()->MovePoint(9, 386.112335f, 483.010040f, -7.232251f);
                break;
            case 9:
                me->GetMotionMaster()->MovePoint(10, 385.963501f, 442.606476f, -7.193601f);
                break;
            case 10:
                me->GetMotionMaster()->MovePoint(11, 385.531738f, 416.619385f, -1.703543f);
                break;
            case 11:
                me->GetMotionMaster()->MovePoint(12, 385.355988f, 375.940430f, -1.623023f);
                break;
            case 12:
                me->GetMotionMaster()->MovePoint(13, 385.620300f, 350.467163f, 3.825020f);
                break;
            case 13:
                me->ForcedDespawn(5000); //Despawn après 5 sec
                break;
        }
    }
};

CreatureAI* GetAI_npc_knot_thimblejack(Creature* pCreature)
{
    return new npc_knot_thimblejackAI(pCreature);
}

bool GossipHello_npc_knot_thimblejack(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->IsQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Why should I bother fixing the trap? Why not just eliminate the guard the old fashioned way?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (pPlayer->GetQuestRewardStatus(QUEST_GORDOK_OGRE_SUIT) && pPlayer->GetQuestStatus(QUEST_GORDOK_OGRE_SUIT) == QUEST_STATUS_COMPLETE)
        {
            if (pPlayer->GetSkillValueBase(SKILL_LEATHERWORKING) >= 275 && !pPlayer->HasSpell(SPELL_GORDOK_OGRE_SUIT_L))
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Please teach me how to make a Gordok Ogre Suit!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

            if (pPlayer->GetSkillValueBase(SKILL_TAILORING) >= 275 && !pPlayer->HasSpell(SPELL_GORDOK_OGRE_SUIT_T))
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Please teach me how to make a Gordok Ogre Suit!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        }

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_1, pCreature->GetObjectGuid());
        return true;

    return false;
}

bool GossipSelect_npc_knot_thimblejack(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    pPlayer->PlayerTalkClass->ClearMenus();

    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1: pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_2, pCreature->GetObjectGuid()); break;
        case GOSSIP_ACTION_INFO_DEF + 2: pPlayer->CastSpell(pPlayer, SPELL_LEARN_GOS_L, true); break;
        case GOSSIP_ACTION_INFO_DEF + 3: pPlayer->CastSpell(pPlayer, SPELL_LEARN_GOS_T, true); break;
    }
    
    return true;
}

bool QuestRewarded_npc_knot_thimblejack(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (instance_dire_maul* pInstance = (instance_dire_maul*)pPlayer->GetInstanceData())
    {
        if (pQuest && (pQuest->GetQuestId() == QUEST_FREE_KNOT || pQuest->GetQuestId() == QUEST_FREE_KNOT_REPEATABLE))
        {
            if (pCreature)
            {
                if (GameObject* pGo = pCreature->FindNearestGameObject(GO_KNOTS_BALL_AND_CHAIN, 20.0f))
                    pGo->Delete();
                pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                //pCreature->SetActiveObjectState(true);
                pCreature->GetMotionMaster()->MovePoint(1, 518.325f, 542.00f, -23.901f);
                return true;
            }
        }
    }

    return false;
}

enum
{
    SPELL_BACK_HAND     =   6253,
    SPELL_ENRAGE        =   15716,
    SPELL_BRUISING_BLOW =   22572,
    SPELL_PUMMEL        =   15615,
    SPELL_UPPERCUT      =   18072,
};

/******************/
struct GordokBruteAI : public ScriptedAI
{
    GordokBruteAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        /** Save current equipment of the creature */
        m_uiEquipment_id = m_creature->GetEquipmentId();
        Reset();
    }

    uint32 m_uiEquipment_id;
    uint32 m_uiBackhand_Timer;
    uint32 m_uiBruisingBlow_Timer;
    uint32 m_uiPummel_Timer;
    uint32 m_uiUppercut_Timer;
    bool m_bEnrage;

    void Reset() override
    {
        m_creature->LoadEquipment(m_uiEquipment_id, true);
        m_uiBackhand_Timer     = 2000;
        m_uiUppercut_Timer     = 0;
        m_uiBruisingBlow_Timer = 6000;
        m_uiPummel_Timer       = 5000;
        m_bEnrage = false;
    }

    void Aggro(Unit* pWho) override
    {
        uint32 yellChance = urand(0, 4);
        switch (yellChance)
        {
            case 0:
                m_creature->MonsterSay("Me smash! You die!");
                break;
            case 1:
                m_creature->MonsterSay("The Great One will smash you!");
                break;
            case 2:
                char eMessage[100];
                sprintf(eMessage, "Raaar!!! Me smash %s!",pWho->GetName());
                m_creature->MonsterSay(eMessage);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        /** Spell above 30% of life */
        if (m_uiBruisingBlow_Timer < uiDiff)
        {
            if(m_creature->GetHealthPercent() > 30.0f)
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BRUISING_BLOW) == CAST_OK)
                    m_uiBruisingBlow_Timer = urand(3000, 8000);
        }
        else
            m_uiBruisingBlow_Timer -= uiDiff;

        if (m_uiPummel_Timer < uiDiff)
        {
            if(m_creature->GetHealthPercent() > 30.0f && m_creature->GetVictim()->IsNonMeleeSpellCasted(true))
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PUMMEL) == CAST_OK)
                    m_uiPummel_Timer = urand(8000, 10000);
        }
        else
            m_uiPummel_Timer -= uiDiff;

        
        if (m_creature->GetHealthPercent() < 30.0f && !m_bEnrage)
        {
            char eMessage[100];
            sprintf(eMessage, "Gordok Brute puts his club away and begins swinging wildly!");
            m_creature->LoadEquipment(0, true);
            m_creature->MonsterTextEmote(eMessage, nullptr, false);

            m_creature->CastSpell(m_creature, SPELL_ENRAGE, false);
            m_bEnrage = true;
        }

        if (m_creature->GetHealthPercent() < 30.0f && m_bEnrage)
        {
            if (m_uiBackhand_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BACK_HAND) == CAST_OK)
                    m_uiBackhand_Timer = urand(5000, 9000);
            }
            else
                m_uiBackhand_Timer -= uiDiff;
        }

        if (m_uiUppercut_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UPPERCUT) == CAST_OK)
                m_uiUppercut_Timer = urand(6000, 10000);
        }
        else
            m_uiUppercut_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_gordok_brute(Creature* pCreature)
{
    return new GordokBruteAI(pCreature);
}

/*######
## boss_guards
######*/

enum
{
    // For ALL
    SPELL_KNOCK_AWAY            = 10101,
    SPELL_SHIELD_CHARGE         = 15749,
    SPELL_STRIKE                = 14516,    
    SPELL_SHIELD_BASH           = 11972,
    SPELL_GUARD_ENRAGE          = 8269,

    // Guard Fengus
    SPELL_FENGUS_FEROCITY       = 22817,
    SPELL_ICE_LOCK              = 22856,

    // Guard Slip'kik
    SPELL_SLIPKIKS_SAVVY        = 22820,

    // Guard Mol'dar
    SPELL_MOLDAR_MOXIE          = 22818,

    EMOTE_ENRAGE                = -1900040,
};

struct boss_guardsAI : public ScriptedAI
{
    boss_guardsAI(Creature* pCreature) : ScriptedAI(pCreature) 
    {
        pInstance = (instance_dire_maul*)pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* pInstance;


    uint32 m_uiStrike_Timer;
    uint32 m_uiShieldCharge_Timer;
    uint32 m_uiKnockAway_Timer;
    uint32 m_uiShieldBash_Timer;
    bool m_bEnrageUsed;

    uint32 m_uiCombatBugTimer;
    
    void Reset() override
    {
        m_uiShieldCharge_Timer = 500;
        m_uiStrike_Timer       = urand(10000, 20000);
        m_uiKnockAway_Timer    = urand(20000, 30000);
        m_uiShieldBash_Timer   = urand(8000, 15000);
        m_bEnrageUsed          = false;

        m_uiCombatBugTimer = 0;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        // Guards no longer drop loot after contributing to the Tribute
        if (pInstance->GetData(TYPE_GORDOK_TRIBUTE) == DONE)
        {
            m_creature->MonsterSay("Why... Boss.. betray.. us...?", 0, 0);
            m_creature->SetLootRecipient(nullptr);
        }
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_KNOCK_AWAY)
            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -50);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Workaround fix for bug where Slip'kik doesnt leave combat properly if he charges through the trap
        if (m_uiCombatBugTimer)
        {
            if (m_uiCombatBugTimer <= uiDiff)
            {
                if (m_creature->IsInCombat() && m_creature->HasAura(SPELL_ICE_LOCK))
                {
                    m_creature->CombatStop(true);
                    m_creature->DeleteThreatList();
                }
                m_uiCombatBugTimer = 0;
            }
            else
                m_uiCombatBugTimer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;       

        // Shield Charge
        if (m_uiShieldCharge_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_FARTHEST, 0, SPELL_SHIELD_CHARGE, SELECT_FLAG_PLAYER | SELECT_FLAG_IN_LOS), SPELL_SHIELD_CHARGE) == CAST_OK)
            {
                m_uiShieldCharge_Timer = urand(12000, 16000);
                if (m_creature->GetEntry() == NPC_GUARD_SLIPKIK)
                    m_uiCombatBugTimer = 3000;
            }
        }
        else 
            m_uiShieldCharge_Timer -= uiDiff;

        // Shield Bash 
        if (m_uiShieldBash_Timer < uiDiff) 
        {
            if (m_creature->GetVictim()->IsNonMeleeSpellCasted(true))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHIELD_BASH) == CAST_OK)
                    m_uiShieldBash_Timer = urand(10000, 15000);
            }
        } 
        else 
            m_uiShieldBash_Timer -= uiDiff;

        // Strike
        if (m_uiStrike_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_STRIKE) == CAST_OK)
                m_uiStrike_Timer = urand(10000, 15000);
        } 
        else 
            m_uiStrike_Timer -= uiDiff;

        // Knock Away
        if (m_uiKnockAway_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                m_uiKnockAway_Timer = urand(20000, 30000);
        } 
        else 
            m_uiKnockAway_Timer -= uiDiff;

        // Enrage
        if (!m_bEnrageUsed && m_creature->GetHealthPercent() < 50.0f) 
        {
            DoCastSpellIfCan(m_creature, SPELL_GUARD_ENRAGE);
            DoScriptText(EMOTE_ENRAGE, m_creature);
            m_creature->CallForHelp(50.0f);
            m_bEnrageUsed = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_guards(Creature* pCreature)
{
    return new boss_guardsAI(pCreature);
}

/*######
## go_fixed_trap
######*/

struct go_fixed_trap : public GameObjectAI
{
    go_fixed_trap(GameObject* gobj) : GameObjectAI(gobj)
    {
        pInstance = (instance_dire_maul*)gobj->GetInstanceData();
    }

    instance_dire_maul* pInstance;

    void UpdateAI(uint32 const diff) override
    {
       if (Creature* pSlipkik = me->GetMap()->GetCreature(pInstance->GetData64(NPC_GUARD_SLIPKIK)))
        {
            if (me->IsWithinDist(pSlipkik, 2.0f)) 
            {
                pSlipkik->CombatStop(true);
                pSlipkik->DeleteThreatList();
                pSlipkik->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                pSlipkik->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pSlipkik->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                pSlipkik->CastSpell(pSlipkik, SPELL_ICE_LOCK, true, nullptr);
                me->SendGameObjectCustomAnim();
                me->Delete();
            }
        }
    }
};

GameObjectAI* GetAI_go_fixed_trap(GameObject* gobj)
{
    return new go_fixed_trap(gobj);
}

/*######
## boss_kromcrush 
######*/

enum
{
    SPELL_RETALIATION           = 22857,
    SPELL_MORTAL_CLEAVE         = 22859,
    SPELL_INTIMIDATING_SHOUT    = 19134,
    SPELL_CALL_REAVERS          = 22860,

    NPC_GORDOK_REAVER           = 11450,

    EMOTE_RETALIATION           = -1900039,
    SAY_AGGRO                   = -1900038,
    SAY_CALL_HELP               = -1900037,
    SAY_GO_FURGUS               = -1900046,
    SAY_FIND_FURGUS             = -1900047
};

struct boss_kromcrushAI : public ScriptedAI
{
    boss_kromcrushAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (instance_dire_maul*)pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* pInstance;

    uint32 m_uiMortalCleave_Timer;
    uint32 m_uiIntimidatingShout_Timer;
    uint32 m_uiRetaliation_Timer;
    bool m_bRetaliationUsed;
    bool m_bCallReavers;

    void Reset() override
    {
        m_uiMortalCleave_Timer      = urand(7000, 13000);
        m_uiIntimidatingShout_Timer = 10000;
        m_bRetaliationUsed          = false;
        m_bCallReavers              = false;
    }

    void goToFengus()
    {
        pInstance->SetData(TYPE_GORDOK_OGRE_SUIT, DONE);
        DoScriptText(SAY_GO_FURGUS, m_creature);
        DoCastSpellIfCan(m_creature, SPELL_ENRAGE);
        m_creature->SetWalk(false);
        m_creature->GetMotionMaster()->MovePoint(0, 501.971f, 482.321f, 29.463f);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature, pWho);
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override 
    {
        if (uiMovementType == POINT_MOTION_TYPE)
        {
            switch (uiData)
            {
                case 0: m_creature->GetMotionMaster()->MovePoint(1, 536.947f, 535.784f, 27.917f, MOVE_PATHFINDING); break;
                case 1: m_creature->GetMotionMaster()->MovePoint(2, 533.410f, 591.445f, -4.755f, MOVE_PATHFINDING); break;
                case 2: m_creature->GetMotionMaster()->MovePoint(3, 538.760f, 540.026f, -25.403f, MOVE_PATHFINDING); break;
                case 3: m_creature->GetMotionMaster()->MovePoint(4, 386.963f, 515.853f, -12.788f, MOVE_PATHFINDING); break;
                case 4: m_creature->GetMotionMaster()->MovePoint(5, 383.887f, 258.610f, 11.440f, MOVE_PATHFINDING); break;
                case 5:
                {
                    DoScriptText(SAY_FIND_FURGUS, m_creature);
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->Relocate(383.887f, 258.610f, 11.440f);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    break;
                }
            }
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        // Kromcrush no longer drops loot after contributing to the Tribute
        if (pInstance->GetData(TYPE_GORDOK_TRIBUTE) == DONE)
        {
            m_creature->MonsterSay("Why... Boss.. betray.. us...?", 0, 0);
            m_creature->SetLootRecipient(nullptr);
        }
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();

        if (pInstance->GetData(TYPE_GORDOK_OGRE_SUIT) == DONE)
        {
            m_creature->GetMotionMaster()->Clear();
            m_creature->AI()->MovementInform(POINT_MOTION_TYPE, 4);
        }
    }

    void JustSummoned(Creature *pSummoned) override
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            pSummoned->AI()->AttackStart(pTarget);
    }

    void CallReavers()
    {
        // Kromcrush summons Reavers in different places depending on where he is ...
        m_creature->HandleEmote(EMOTE_ONESHOT_ROAR);
        if (m_creature->GetDistance(495.395f, 482.309f, 29.4627f) < 75.0f)
        {
            for (uint8 i = 0; i < 2; ++i)
                m_creature->SummonCreature(NPC_GORDOK_REAVER, 495.395f, 482.309f, 29.4627f, 6.267f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 5*MINUTE*IN_MILLISECONDS);
        }
        else
            for (uint8 i = 0; i < 2; ++i)
                m_creature->SummonCreature(NPC_GORDOK_REAVER, 633.437f, 482.309f, 29.4653f, 3.198f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 5*MINUTE*IN_MILLISECONDS);
        
        //don't use spell because the guards despawn atm ...
        //m_creature->CastSpell(m_creature, SPELL_CALL_REAVERS, false);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Mortal Cleave
        if (m_uiMortalCleave_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTAL_CLEAVE) == CAST_OK)
                m_uiMortalCleave_Timer = urand(15000, 20000);
        } 
        else 
            m_uiMortalCleave_Timer -= uiDiff;

        // Intimidating Shout
        if (m_uiIntimidatingShout_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_INTIMIDATING_SHOUT) == CAST_OK)
                m_uiIntimidatingShout_Timer = urand(30000, 35000);
        }
        else 
            m_uiIntimidatingShout_Timer -= uiDiff;

        // Retaliation
        if (!m_bRetaliationUsed && m_creature->GetHealthPercent() < 25.0f) 
        {
            DoCastSpellIfCan(m_creature, SPELL_RETALIATION);
            DoScriptText(EMOTE_RETALIATION, m_creature);
            m_bRetaliationUsed = true;
        }

        // Call Reavers
        if (!m_bCallReavers && m_creature->GetHealthPercent() < 50.0f)
        {
            DoScriptText(SAY_CALL_HELP, m_creature);
            CallReavers();
            m_bCallReavers = true;
        }

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_boss_kromcrush(Player* pPlayer, Creature * pCreature)
{
    if (pCreature->IsQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (instance_dire_maul* pInstance = (instance_dire_maul*)pCreature->GetInstanceData())
    {
        uint32 menuItem = 0;
        if (pInstance->GetData(TYPE_GORDOK_TRIBUTE) == DONE)
            menuItem = 2;

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sKromcrushGossips[menuItem].m_chItem, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(sKromcrushGossips[menuItem].m_uiMenu, pCreature->GetObjectGuid());

        return true;
    }
    return false;
}

bool GossipSelect_boss_kromcrush(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (instance_dire_maul* pInstance = (instance_dire_maul*)pCreature->GetInstanceData())
    {
        uint32 menuItem = 1;
        if (pInstance->GetData(TYPE_GORDOK_TRIBUTE) == DONE)
            menuItem = 3;

        pPlayer->PlayerTalkClass->ClearMenus();
        
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sKromcrushGossips[menuItem].m_chItem, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(sKromcrushGossips[menuItem].m_uiMenu, pCreature->GetObjectGuid());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                pPlayer->CLOSE_GOSSIP_MENU();
                if (menuItem == 3)
                    pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                else
                {
                    if (boss_kromcrushAI* pKromcrushAI = dynamic_cast<boss_kromcrushAI*>(pCreature->AI()))
                        pKromcrushAI->goToFengus();
                }
        }
    }
    return true;
}

CreatureAI* GetAI_boss_kromcrush(Creature* pCreature)
{
    return new boss_kromcrushAI(pCreature);
}

/*######
## boss_prince_tortheldrin
######*/

enum
{
   SPELL_ARCANE_BLAST     = 22920,
   SPELL_COUNTERSPELL     = 20537,
   SPELL_SUMMON           = 22995,
   SPELL_THRASH           = 8876,
   SPELL_WHIRLWIND        = 15589   
};

struct boss_prince_tortheldrinAI:public ScriptedAI
{
    boss_prince_tortheldrinAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 arcaneBlastTimer;
    uint32 counterspellTimer;
    uint32 summonTimer;    
    uint32 whirlwindTimer;    

    void Reset() override
    {
        arcaneBlastTimer     = urand(15000, 20000);
        counterspellTimer    = urand(10000, 20000);
        summonTimer          = urand(0, 3000);       
        whirlwindTimer       = urand(14000, 22000);

        // Thrash
        DoCastSpellIfCan(m_creature, SPELL_THRASH, CF_TRIGGERED | CF_AURA_NOT_PRESENT);
    }

    void UpdateAI(uint32 const uiDiff) override
    {       
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Summon
        if (summonTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SUMMON) == CAST_OK)            
                summonTimer = urand(13000, 20000);
        }
        else 
            summonTimer -= uiDiff;

        // Whirlwind
        if (whirlwindTimer < uiDiff)
        {
            bool m_bMeleeAttackers = false;
            Unit::AttackerSet attackers = m_creature->GetAttackers();
            for (const auto itr : attackers)
            {
                if (Unit* attacker = m_creature->GetMap()->GetUnit(itr->GetGUID()))
                {
                    if (m_creature->IsInRange(attacker, 0.0f, 7.0f, false)) 
                    {
                        m_bMeleeAttackers = true;
                        break;
                    }
                }
            }
            if (m_bMeleeAttackers)
                if (DoCastSpellIfCan(m_creature, SPELL_WHIRLWIND) == CAST_OK)
                    whirlwindTimer = urand(10000, 20000);
        }
        else
            whirlwindTimer -= uiDiff;

        // Arcane Blast
        if (arcaneBlastTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANE_BLAST) == CAST_OK)
            {
                DoResetThreat();
                arcaneBlastTimer = urand(10000, 15000);
            }
        }
        else
            arcaneBlastTimer -= uiDiff;

        // Counterspell
        if (counterspellTimer < uiDiff)
        {           
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER | SELECT_FLAG_POWER_MANA))
            {
                if (pTarget->IsNonMeleeSpellCasted(true))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_COUNTERSPELL) == CAST_OK)
                        counterspellTimer = urand(25000, 30000);
                }
            }
        }
        else
            counterspellTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_prince_tortheldrin(Creature* pCreature)
{
    return new boss_prince_tortheldrinAI(pCreature);
}


/*######
## boss_alzzin_the_wildshaper
######*/

enum
{
    NPC_ALZZINS_MINION          = 11460,

    SPELL_DARK_CHANNELING       = 21157,

    // Satir
    SPELL_ENERVATE              = 22661,
    SPELL_THORNS                = 22128,
    SPELL_WITHER                = 22662,
       
    // Wolf
    SPELL_DIRE_WOLF_FORM        = 22660,
    SPELL_VICIOUS_BITE          = 19319,
    SPELL_MANGLE                = 22689,
       
    // Tree
    SPELL_TREE_FORM             = 22688,
    SPELL_WILD_REGENERATION     = 7948,
  //SPELL_KNOCK_AWAY            = 10101,  // already defined
    SPELL_DISARM                = 22691
};

static float const ALZZIN_COORDS[2][3] =
{
    {274.844f, -427.251f, -119.962f},
    {262.298f, -445.57f,  -119.962f}
};

float m_fCoordMinions[15][4] =
{
    {258.87f,  -356.773f, -106.255f, 4.93928f },
    {261.65f,  -358.587f, -105.996f, 5.88176f },
    {260.443f, -357.273f, -106.288f, 3.56047f },
    {261.335f, -354.319f, -105.331f, 1.44862f },
    {263.817f, -354.068f, -105.126f, 6.02139f },
    {252.266f, -365.229f, -109.915f, 4.20624f },
    {254.409f, -365.498f, -109.99f,  1.8675f  },
    {253.869f, -362.235f, -108.675f, 0.331613f},
    {255.764f, -362.91f,  -108.83f,  5.09636f },
    {258.411f, -360.927f, -107.782f, 4.88692f },
    {250.652f, -370.499f, -112.237f, 4.20624f },
    {253.022f, -371.107f, -112.171f, 1.8675f  },
    {250.207f, -372.675f, -112.839f, 0.331613f},
    {252.79f,  -372.777f, -112.676f, 5.09636f },
    {251.389f, -374.372f, -113.371f, 4.88692f }
};

uint32 m_uiPhaseMask[3][2] = { {1, 2}, {0, 2}, {0, 1} };

struct boss_alzzin_the_wildshaperAI : ScriptedAI
{
    explicit boss_alzzin_the_wildshaperAI(Creature* pCreature) : ScriptedAI(pCreature)    
    {
        pInstance = static_cast<ScriptedInstance*>(pCreature->GetInstanceData());
        m_uiImpCount = 0;
        boss_alzzin_the_wildshaperAI::Reset();
    }

    ScriptedInstance* pInstance;

    bool m_bSummoned;
    bool m_bCastThorns;

    uint8 m_uiOOCPhase;
    uint32 m_uiOOCTimer;

    uint8 m_uiChPhase;
    uint32 m_uiPhaseTimer;
    uint32 m_uiEvadeTimer;

    uint32 m_uiThornsTimer;
    uint32 m_uiDisarmTimer;
    uint32 m_uiEnervateTimer;
    uint32 m_uiKnockAwayTimer;
    uint32 m_uiMangleTimer;
    uint32 m_uiViciousBiteTimer;
    uint32 m_uiWildRegenerationTimer;
    uint32 m_uiWitherTimer;
    uint8 m_uiImpCount;
    
    void Reset() override
    {
        m_uiOOCPhase = 0;
        m_uiOOCTimer = urand(30000, 45000);

        m_uiThornsTimer            = urand(1000, 3000);
        m_uiDisarmTimer            = urand(5000, 10000);
        m_uiEnervateTimer          = urand(5000, 10000);
        m_uiKnockAwayTimer         = urand(6000, 11000);
        m_uiMangleTimer            = urand(3000, 7000);
        m_uiViciousBiteTimer       = urand(5000, 10000);
        m_uiWildRegenerationTimer  = urand(5000, 8000);
        m_uiWitherTimer            = urand(2000, 5000);

        m_uiPhaseTimer             = urand(12000, 15000);
        m_uiChPhase = 0;
        m_uiEvadeTimer             = 3000;
        m_bSummoned                = false;

        m_bCastThorns = DoCastSpellIfCan(m_creature, SPELL_THORNS) != CAST_OK;
    }

    void SummonAdds()
    {
        uint8 uiCount = 15 - m_uiImpCount;
        for (uint8 i = 0; i < uiCount; ++i)
        {
            if (Creature* pAdds = m_creature->SummonCreature(NPC_ALZZINS_MINION, 
                m_fCoordMinions[i][0], 
                m_fCoordMinions[i][1], 
                m_fCoordMinions[i][2], 
                m_fCoordMinions[i][3], TEMPSUMMON_MANUAL_DESPAWN, 20 * IN_MILLISECONDS))
            {
                pAdds->AI()->AttackStart(m_creature->GetVictim());                
            }

            ++m_uiImpCount;
        }
    }

    void RemoveAdds() const
    {
        std::list<Creature*> m_lHelpers;
        GetCreatureListWithEntryInGrid(m_lHelpers, m_creature, NPC_ALZZINS_MINION, 80.0f);
        if (!m_lHelpers.empty())
        {
            for (const auto& pCreature : m_lHelpers)
            {
                if (pCreature && !pCreature->IsAlive())
                    static_cast<TemporarySummon*>(pCreature)->UnSummon();
            }
            m_lHelpers.clear();
        }
    }

    void ChangeForm()
    {
        uint8 uiNewPhase = 0;
        if (roll_chance_i(50))
            uiNewPhase = m_uiPhaseMask[m_uiChPhase][0];
        else
            uiNewPhase = m_uiPhaseMask[m_uiChPhase][1];
        
        switch (uiNewPhase)
        {
            case 0: // NORMAL
                m_creature->RemoveAurasDueToSpell(SPELL_DIRE_WOLF_FORM);
                m_creature->RemoveAurasDueToSpell(SPELL_TREE_FORM);
                break;

            case 1: // WOLF
                DoCastSpellIfCan(m_creature, SPELL_DIRE_WOLF_FORM);
                m_creature->RemoveAurasDueToSpell(SPELL_TREE_FORM);
                break;

            case 2: // TREE                    
                DoCastSpellIfCan(m_creature, SPELL_TREE_FORM);
                m_creature->RemoveAurasDueToSpell(SPELL_DIRE_WOLF_FORM);
                break;
        }

        m_uiChPhase = uiNewPhase;
    }

    void AuraRemoved(uint32 uiSpellId, uint32 /*uiMode*/)
    {
        if (uiSpellId == SPELL_THORNS)
            m_bCastThorns = true;
    }

    void JustDied(Unit* /* pKiller */) override
    {
        RemoveAdds();
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();

        RemoveAdds();
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (!m_bSummoned)
            static_cast<TemporarySummon*>(pSummoned)->UnSummon();
    }

    void SummonedCreatureDespawn(Creature* /* pSummoned */) override
    {
        if (!m_uiImpCount)
            return;

        --m_uiImpCount;
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case 0:
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->SetFacingTo(6.13f);
                DoCastSpellIfCan(m_creature, SPELL_DARK_CHANNELING);
                //m_creature->HandleEmoteState(EMOTE_STATE_SPELLPRECAST);
                m_uiOOCTimer = urand(10000, 30000);
                break;
            case 1:
                m_creature->GetMotionMaster()->Initialize();
                m_uiOOCTimer = urand(30000, 45000);
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Thorns
        if (m_bCastThorns)
        {
            if (m_uiThornsTimer < uiDiff)
            {
                if (!m_creature->HasAura(SPELL_DIRE_WOLF_FORM) && !m_creature->HasAura(SPELL_TREE_FORM))
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_THORNS) == CAST_OK)
                    {
                        m_uiThornsTimer = urand(10000, 15000);
                        m_bCastThorns = false;
                    }
                }
            }
            else
                m_uiThornsTimer -= uiDiff;
        }
        
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (!m_uiOOCTimer)
                return;

            if (m_uiOOCTimer <= uiDiff)
            {
                //m_creature->HandleEmote(0);
                m_creature->InterruptNonMeleeSpells(false);
                float const *point = ALZZIN_COORDS[m_uiOOCPhase];
                m_creature->GetMotionMaster()->MovePoint(m_uiOOCPhase, point[0], point[1], point[2]);

                m_uiOOCPhase ^= 1;
                m_uiOOCTimer = 0;
            }
            else
                m_uiOOCTimer -= uiDiff;

            return;
        }

        if (!m_bSummoned && m_creature->GetHealthPercent() < 45.0f)
        {
            if (pInstance && pInstance->GetData(TYPE_ALZZIN) != SPECIAL)
                pInstance->SetData(TYPE_ALZZIN, SPECIAL);

            m_creature->CallForHelp(VISIBLE_RANGE);
            SummonAdds();

            m_bSummoned = true;
        }

        // Check Evade Zone
        if (m_uiEvadeTimer < uiDiff)
        {
            if (!m_creature->IsInRange3d(ALZZIN_COORDS[0][0], ALZZIN_COORDS[0][1], ALZZIN_COORDS[0][2], 0.0f, 40.0f))
            {
                // Say something
                m_creature->AI()->EnterEvadeMode();
            }
            m_uiEvadeTimer = 3000;
        }
        else
            m_uiEvadeTimer -= uiDiff;

        // Phase
        if (m_uiPhaseTimer < uiDiff)
        {
            ChangeForm();
            m_uiPhaseTimer = urand (12000, 15000);
        }
        else
            m_uiPhaseTimer -= uiDiff;
        
        switch (m_uiChPhase)
        {
        case 0: // NORMAL
            
            // Wither
            if (m_uiWitherTimer < uiDiff)
            {                    
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WITHER, CF_AURA_NOT_PRESENT) == CAST_OK)
                    m_uiWitherTimer = urand(8000, 10000);
            }
            else
                m_uiWitherTimer -= uiDiff;

            // Enervate
            if (m_uiEnervateTimer < uiDiff)
            {                    
                if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER | SELECT_FLAG_POWER_MANA), SPELL_ENERVATE) == CAST_OK)
                    m_uiEnervateTimer = urand(12000, 15000);
            }
            else
                m_uiEnervateTimer -= uiDiff;
            break;
            
        case 1: // WOLF
            
            // Mangle
            if (m_uiMangleTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MANGLE, CF_AURA_NOT_PRESENT) == CAST_OK)
                    m_uiMangleTimer = urand(8000, 10000);
            }
            else
                m_uiMangleTimer -= uiDiff;

            // Vicious Bite
            if (m_uiViciousBiteTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VICIOUS_BITE) == CAST_OK)
                    m_uiViciousBiteTimer = urand(8000, 15000);
            }
            else
                m_uiViciousBiteTimer -= uiDiff;
            break;

        case 2: // WOOD
            
            // Knock Away
            if (m_uiKnockAwayTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                    m_uiKnockAwayTimer = urand(16000, 20000);
            }
            else
                m_uiKnockAwayTimer -= uiDiff;

            // Disarm
            if (m_uiDisarmTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DISARM) == CAST_OK)
                    m_uiDisarmTimer = urand(16000, 20000);
            }
            else
                m_uiDisarmTimer -= uiDiff;

            // Wild Regeneration
            if (m_uiWildRegenerationTimer < uiDiff)
            {
                if (m_creature->GetHealthPercent() < 50.0f)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_WILD_REGENERATION, CF_AURA_NOT_PRESENT) == CAST_OK)
                        m_uiWildRegenerationTimer = urand(10000, 15000);
                }
            }
            else
                m_uiWildRegenerationTimer -= uiDiff;
            break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_alzzins_minionAI : ScriptedAI
{
    explicit npc_alzzins_minionAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_alzzins_minionAI::Reset();
    }

    void Reset() override
    {
        if (Unit* pSummoner = m_creature->GetMap()->GetUnit(((TemporarySummon*)m_creature)->GetSummonerGuid()))
        {
            if (pSummoner->IsAlive())
                m_creature->GetMotionMaster()->MoveFollow(pSummoner, PET_FOLLOW_DIST, frand(0.0f, 6.2832f));
        }
    }

    void MoveInLineOfSight(Unit *pWho) override
    {
        if (!m_creature->IsInCombat())
        {
            if (pWho->IsPlayer() && pWho->IsTargetable(true, false) && m_creature->IsWithinDistInMap(pWho, 30.0f) && m_creature->IsWithinLOSInMap(pWho))
                m_creature->AttackedBy(pWho);
        }
    }

    void JustDied(Unit* /* pKiller */) override
    {
        if (Unit* pSummoner = m_creature->GetMap()->GetUnit(((TemporarySummon*)m_creature)->GetSummonerGuid()))
        {
            if (!pSummoner->IsAlive() || !pSummoner->IsInCombat())
                ((TemporarySummon*)m_creature)->UnSummon();
        }
    }
};

CreatureAI* GetAI_boss_alzzin_the_wildshaper(Creature* pCreature)
{
    return new boss_alzzin_the_wildshaperAI(pCreature);
}

CreatureAI* GetAI_npc_alzzins_minion(Creature* pCreature)
{
    return new npc_alzzins_minionAI(pCreature);
}

enum
{
    SPELL_CHARGE = 22911,
    SPELL_MAUL = 17156
};

struct boss_ferraAI : public ScriptedAI
{
    boss_ferraAI(Creature* pCreature) : ScriptedAI(pCreature) 
    {         
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();         
    }    
    
    ScriptedInstance* pInstance;  

    uint32 m_uiCharge_Timer;
    uint32 m_uiMaul_Timer;

    void Reset() override 
    {    
        m_uiCharge_Timer        = 0;
        m_uiMaul_Timer          = urand(5000, 10000);

        m_creature->SetNoCallAssistance(true);
    }   

    void MoveInLineOfSight(Unit *pWho) override
    {        
        if (!m_creature->IsInCombat()) 
        {
            if (pWho->IsPlayer() && m_creature->IsWithinDistInMap(pWho, 80.0f) && m_creature->IsWithinLOSInMap(pWho)
            &&  pWho->IsTargetable(true, false))
            {
                // don't aggro people through the floor, ever!
                if ((m_creature->GetPositionZ() - pWho->GetPositionZ()) < 10.0f)
                    m_creature->AI()->AttackStart(pWho);
            }
        }              
    }   

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())            
            return;

        // Maul
        if (m_uiMaul_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MAUL) == CAST_OK)
                m_uiMaul_Timer = urand(15000, 20000);
        }
        else 
            m_uiMaul_Timer -= uiDiff;

        // Charge
        if (m_uiCharge_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHARGE) == CAST_OK)
                m_uiCharge_Timer = urand(6000, 10000);
        }
        else 
            m_uiCharge_Timer -= uiDiff;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ferra(Creature* pCreature)
{
    return new boss_ferraAI(pCreature);
}


/*######
## boss_magister_kalendris
######*/

enum
{
    SPELL_SHADOWFORM             = 22917,
    SPELL_SHADOW_WORD_PAIN       = 17146,
    SPELL_MIND_FLAY              = 22919,
    SPELL_MIND_BLAST             = 17287,
    SPELL_DOMINATE_MIND          = 7645
};

struct boss_magister_kalendrisAI:public ScriptedAI
{
    boss_magister_kalendrisAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiShadowformTimer;
    uint32 m_uiShadowWordPainTimer;
    uint32 m_uiMindFlayTimer;
    uint32 m_uiMindBlastTimer;
    uint32 m_uiDominateMindTimer;

    bool m_bShadowformUsed;
    bool m_bInMeele;

    void Reset() override
    {
        m_bShadowformUsed = false;
        m_uiShadowWordPainTimer     = urand(5000, 10000);
        m_uiMindFlayTimer           = urand(10000, 20000);
        m_uiMindBlastTimer          = 0;
        m_uiDominateMindTimer       = urand(20000, 30000);
    }

    void UpdateAI(uint32 const uiDiff) override
    {       

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Shadow Word Pain
        if (m_uiShadowWordPainTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOW_WORD_PAIN, CF_AURA_NOT_PRESENT) == CAST_OK)
                m_uiShadowWordPainTimer = urand(9000, 11000);
        }
        else
            m_uiShadowWordPainTimer -= uiDiff;

        // MindFlay
        if (m_uiMindFlayTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIND_FLAY) == CAST_OK)
                m_uiMindFlayTimer = urand(18000, 23000);
        }
        else
            m_uiMindFlayTimer -= uiDiff;

        // Mind Blast
        if (m_uiMindBlastTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIND_BLAST) == CAST_OK)
                m_uiMindBlastTimer = (m_bInMeele ? urand(7000, 10000) : urand(2000, 3000));
        }
        else
            m_uiMindBlastTimer -= uiDiff;

        // Dominate Mind
        if (m_uiDominateMindTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, nullptr, SELECT_FLAG_PLAYER), SPELL_DOMINATE_MIND) == CAST_OK)
                m_uiDominateMindTimer = urand(25000, 35000);
        }
        else
            m_uiDominateMindTimer -= uiDiff;

        // Shadowform
        if (!m_bShadowformUsed && m_creature->GetHealthPercent() < 50.0f) 
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SHADOWFORM) == CAST_OK)
                m_bShadowformUsed = true;
        }

        if (!IsCombatMovementEnabled())
        { //Melee
            if (!m_bInMeele && (m_creature->GetDistance2d(m_creature->GetVictim()) < 5.0f || m_creature->GetDistance2d(m_creature->GetVictim()) > 30.0f || !m_creature->IsWithinLOSInMap(m_creature->GetVictim()) || m_creature->GetPowerPercent(POWER_MANA) < 5.0f))
            {
                SetCombatMovement(true);
                DoStartMovement(m_creature->GetVictim());
                m_bInMeele = true;
                return;
            }
        }
        else                
        { //Range
            if (m_bInMeele && m_creature->GetDistance2d(m_creature->GetVictim()) >= 5.0f && m_creature->GetDistance2d(m_creature->GetVictim()) <= 30.0f && m_creature->IsWithinLOSInMap(m_creature->GetVictim()) && m_creature->GetPowerPercent(POWER_MANA) >= 5.0f)
            {
                SetCombatMovement(false);
                m_bInMeele = false;
                DoStartNoMovement(m_creature->GetVictim());
                return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_magister_kalendris(Creature* pCreature)
{
    return new boss_magister_kalendrisAI(pCreature);
}


void AddSC_instance_dire_maul()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "instance_dire_maul";
    pNewScript->GetInstanceData = &GetInstanceData_instance_dire_maul;
    pNewScript->RegisterSelf();

    // DM West
    pNewScript = new Script;
    pNewScript->Name = "npc_reste_mana";
    pNewScript->GetAI = &GetAI_npc_reste_mana;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_arcane_aberration";
    pNewScript->GetAI = &GetAI_npc_arcane_aberration;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_residual_montruosity";
    pNewScript->GetAI = &GetAI_npc_residual_montruosity;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_ferra";    
    pNewScript->GetAI = &GetAI_boss_ferra;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_prince_tortheldrin";
    pNewScript->GetAI = &GetAI_boss_prince_tortheldrin;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_magister_kalendris";
    pNewScript->GetAI = &GetAI_boss_magister_kalendris;
    pNewScript->RegisterSelf();

    // DM North
    pNewScript = new Script;
    pNewScript->Name = "npc_gordok_brute";
    pNewScript->GetAI = &GetAI_mob_gordok_brute;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_mizzle_the_crafty";
    pNewScript->GetAI = &GetAI_npc_mizzle_the_crafty;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_knot_thimblejack";
    pNewScript->GetAI = &GetAI_npc_knot_thimblejack;
    pNewScript->pGossipHello = &GossipHello_npc_knot_thimblejack;
    pNewScript->pGossipSelect = &GossipSelect_npc_knot_thimblejack;
    pNewScript->pQuestRewardedNPC = &QuestRewarded_npc_knot_thimblejack;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_guards";
    pNewScript->GetAI = &GetAI_boss_guards;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_broken_trap";
    pNewScript->pQuestRewardedGO = &QuestRewarded_go_broken_trap;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_fixed_trap";
    pNewScript->GOGetAI = &GetAI_go_fixed_trap;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_kromcrush";
    pNewScript->GetAI = &GetAI_boss_kromcrush;
    pNewScript->pGossipHello =  &GossipHello_boss_kromcrush;
    pNewScript->pGossipSelect = &GossipSelect_boss_kromcrush;
    pNewScript->RegisterSelf();

    // DM East
    pNewScript = new Script;
    pNewScript->Name = "boss_alzzin_the_wildshaper";
    pNewScript->GetAI = &GetAI_boss_alzzin_the_wildshaper;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_alzzins_minion";
    pNewScript->GetAI = &GetAI_npc_alzzins_minion;
    pNewScript->RegisterSelf(); 
}
