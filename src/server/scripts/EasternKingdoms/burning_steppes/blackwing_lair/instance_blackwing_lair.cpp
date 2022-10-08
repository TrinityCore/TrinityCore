/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
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
SDName: Instance_Blackwing_Lair
SD%Complete: 90
SDComment:
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

struct RazCoords
{
    float X;
    float Y;
    float Z;
    float O;
};

static RazCoords RazOeufs[] =
{
    {-7579.49f, -1051.48f, 408.157f, 0.523599f},
    {-7563.15f, -1088.71f, 413.381f, -0.453786f},
    {-7568.27f, -1097.68f, 413.381f, 2.79253f},
    {-7578.64f, -1089.95f, 413.381f, 2.21657f},
    {-7568.62f, -1086.58f, 413.381f, 0.855211f},
    {-7572.49f, -1095.03f, 413.381f, -2.86234f},
    {-7569.38f, -1079.73f, 413.381f, -2.68781f},
    {-7576.92f, -1083.69f, 413.381f, -2.89725f},
    {-7580.80f, -1067.29f, 408.490f, -2.98451f},
    {-7592.38f, -1035.68f, 408.157f, 1.62316f},
    {-7588.84f, -1053.79f, 408.157f, -1.72788f},
    {-7597.53f, -1094.54f, 408.490f, 2.37365f},
    {-7594.37f, -1102.90f, 408.490f, -0.907571f},
    {-7584.68f, -1075.84f, 408.490f, 3.01942f},
    {-7601.14f, -1077.11f, 408.218f, -1.27409f},
    {-7599.00f, -1044.77f, 408.157f, -1.02974f},
    {-7604.36f, -1060.25f, 408.157f, -2.77507f},
    { -7618.1f, -1069.33f, 408.490f, -1.32645f},
    {-7619.76f, -1058.94f, 408.490f, 1.81514f},
    {-7586.36f, -1024.43f, 408.490f, -2.93215f},
    {-7609.94f, -1035.11f, 408.490f, -1.93731f},
    {-7628.32f, -1044.57f, 408.490f, -0.174533f},
    {-7592.35f, -1010.84f, 408.490f, -2.54818f},
    {-7611.60f, -1020.32f, 413.381f, 3.08923f},
    {-7626.69f, -1011.71f, 413.381f, 0.226893f},
    {-7577.84f, -1035.97f, 408.490f, -1.11701f},
    {-7564.89f, -1058.87f, 408.490f, 2.28638f},
    {-7566.00f, -1045.93f, 408.490f, 3.05433f},
    {-7554.42f, -1061.50f, 408.490f, -2.28638f},
    {-7549.48f, -1069.96f, 408.490f, -0.523599f},
};

enum
{
    AT_ORB_OF_COMMAND           = 3847,
    AT_ENTER_VAEL_ROOM          = 3626,

    EGGS_COUNT                  = 30,

    SPELL_NATURE_IMMUNITY       = 7941,
    SPELL_FROST_IMMUNITY        = 7940,
    SPELL_FIRE_IMMUNITY         = 7942,
    SPELL_ARCANE_IMMUNITY       = 33020, // Spell_mod
    SPELL_MIND_EXHAUSTION       = 23958,
    SPELL_POSSESS               = 19832,
    SPELL_POSSESS_VISUAL        = 23014,
    SPELL_WARMING_FLAMES        = 23040,
    SPELL_SUPPRESSION_AURA      = 22247,

    NPC_RAZORGORE               = 12435,
    NPC_VAELASTRASZ             = 13020,
    NPC_LASHLAYER               = 12017,
    NPC_FIREMAW                 = 11983,
    NPC_EBONROC                 = 14601,
    NPC_FLAMEGOR                = 11981,
    NPC_CHROMAGGUS              = 14020,
    NPC_NEFARIAN                = 11583,
    NPC_LORD_NEFARIAN           = 10162,

    GO_DOOR_RAZORGORE_ENTER     = 176964,
    GO_DOOR_RAZORGORE_EXIT      = 176965,
    GO_DOOR_NEFARIAN            = 176966,
    GO_DOOR_CHROMAGGUS_ENTER    = 179115,
    GO_DOOR_CHROMAGGUS_SIDE     = 179116,
    GO_LEVER_CHROMAGGUS_SIDE    = 179148,
    GO_DOOR_CHROMAGGUS_EXIT     = 179117,
    GO_DOOR_VAELASTRASZ         = 179364,
    GO_DOOR_LASHLAYER           = 179365,

    GO_OEUF_RAZ                 = 177807,
    GO_ORBE_DOMINATION          = 177808,

    // Raz
    MOB_RAZ_TRIGGER             = 14453,
    MOB_GRETHOK                 = 12557,
    MOB_GARDE_AILE_NOIRE        = 14456,
    // Vael
    MOB_TECHNICIEN_AILE_NOIRE   = 13996,
    // Lashlayer
    MOB_CAPITAINE_GRIFFEMORT    = 12467,
    MOB_RONGE_GRIFFEMORT        = 12464,
    MOB_WYRMIDE_GRIFFEMORT      = 12465,
    MOB_FLAMMECAILLE_GRIFFEMORT = 12463,
    MOB_EVEILLEUR_GRIFFEMORT    = 12468,
    MOB_SOUS_CHEF_AILE_NOIRE    = 12458,
    MOB_DRACO_VERT              = 14023,
    MOB_DRACO_ROUGE             = 14022,
    MOB_DRACO_BLEU              = 14024,
    MOB_DRACO_BRONZE            = 14025,
    GO_SUPPRESSION_ENGINE       = 179784,
    // Drags
    MOB_DEMONISTE_AILE_NOIRE    = 12459,
    MOB_SURVEILLANT_GRIFFEMORT  = 12461,
    MOB_LIEUR_SORT_AILE_NOIRE   = 12457,
    MOB_GARDE_WYRM_GRIFFEMORT   = 12460,

    EMOTE_DESTROY_EGG           = -1469034,
    GOSSIP_OPTION_NEFARIUS      = 6045,

    CONDITION_SCEPTER_FAIL      = 1,
    CONDITION_SCEPTER_WIN       = 2
};

void NefariusGossipOptionClicked(Creature* pCreature);

struct blackwing_technicians_helper
{
public:
    blackwing_technicians_helper(ScriptedInstance *pInstance) :
        m_bUpdated(false),
        m_uiTechniciansUpdate(0),
        m_pInstance(pInstance)
    {
    }
    void AddTechnician(Creature *pTechnician)
    {
        ASSERT(pTechnician);
        m_vTechniciansGuid.push_back(pTechnician->GetObjectGuid());
        ThreatList threatList = pTechnician->GetThreatManager().getThreatList();
        for (const auto i : threatList)
        {
            if (Unit *pUnit = m_pInstance->instance->GetCreature(i->getUnitGuid()))
            {
                m_mThreatGuid[pUnit->GetObjectGuid()] += i->getThreat();
                pTechnician->GetThreatManager().modifyThreatPercent(pUnit, -100);
            }
        }
    }
    void RemoveTechnician(Creature *pTechnician)
    {
        for (std::vector<ObjectGuid>::iterator itr = m_vTechniciansGuid.begin(); itr != m_vTechniciansGuid.end(); ++itr)
        {
            if (pTechnician->GetObjectGuid() == (*itr))
            {
                m_vTechniciansGuid.erase(itr);
                if (m_vTechniciansGuid.empty())
                    m_mThreatGuid.clear();
                return;
            }
        }
    }
    ObjectGuid GetVictimGuid() const
    {
        float fMaxThreat = 0.0f;
        ObjectGuid victimGuid;

        for (const auto& itr : m_mThreatGuid)
        {
            if (fMaxThreat <= itr.second)
            {
                fMaxThreat = itr.second;
                victimGuid = itr.first;
            }
        }
        return victimGuid;
    }
    void RemovePotentialVictim(ObjectGuid victimGuid)
    {
        // Victim died, must be removed from threat list or we can get stuck on it.
        // Better to remove it here than in RecalculateThreat since we'd have to keep
        // track and update during iteration otherwise
        std::map<ObjectGuid, float>::iterator itr = m_mThreatGuid.find(victimGuid);
        if (itr != m_mThreatGuid.end())
            m_mThreatGuid.erase(itr);
    }

    ScriptedInstance *GetInstance() const
    {
        return (m_pInstance);
    }
    void RecalculateThreat()
    {
        // Update when m_uiTechniciansUpdate == 0 (buffered update)
        if (m_uiTechniciansUpdate)
            --m_uiTechniciansUpdate;
        else
            m_bUpdated = false;

        if (!m_bUpdated)
        {
            // Don't -1 for 0 index, otherwise we get stuck and never update again. Also the potential
            // for an integer overflow
            m_uiTechniciansUpdate = m_vTechniciansGuid.size();
            m_bUpdated = true;
            for (const auto& guid : m_vTechniciansGuid)
            {
                if (Creature *pCreature = m_pInstance->instance->GetCreature(guid))
                {
                    if (!pCreature->IsAlive())
                        continue;
                    // Copy the list, since it may get invalidated at 'modifyThreatPercent' call
                    ThreatList threatList = pCreature->GetThreatManager().getThreatList();
                    for (const auto i : threatList)
                    {
                        if (Unit *pUnit = m_pInstance->instance->GetUnit(i->getUnitGuid()))
                        {
                            m_mThreatGuid[pUnit->GetObjectGuid()] += i->getThreat();
                            pCreature->GetThreatManager().modifyThreatPercent(pUnit, -100);
                        }
                    }
                }
            }
        }
    }
private:
    bool m_bUpdated;
    uint32 m_uiTechniciansUpdate;
    std::vector<ObjectGuid> m_vTechniciansGuid;
    std::map<ObjectGuid, float> m_mThreatGuid;
    ScriptedInstance* const m_pInstance;
};

struct instance_blackwing_lair : public ScriptedInstance
{
    instance_blackwing_lair(Map* pMap) : ScriptedInstance(pMap), m_hBlackwingTechnicians(this)
    {
        Initialize();
    };

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    uint64 m_auiData[MAX_DATAS];
    uint64 m_uiWyrmPackComposition;
    std::string strInstData;
    std::list<ObjectGuid> m_lVaelGobs;
    blackwing_technicians_helper m_hBlackwingTechnicians;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        memset(&m_auiData, 0, sizeof(m_auiData));
        m_uiWyrmPackComposition = 0;

        // 5 * 4 possible colours
        m_auiData[DATA_CHROM_BREATH] = urand(0, 19);
        m_auiData[DATA_NEF_COLOR] = urand(0, 19);
    }

    bool IsEncounterInProgress() const override
    {
        // Don't include TYPE_SCEPTER_RUN status in encounter progress check
        // TODO: Move scepter run out of encounter ordering
        for (int i = 0; i < TYPE_VAEL_EVENT; i++)
        {
            if (m_auiEncounter[i] == IN_PROGRESS)
                return true;
        }
        return false;
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_DOOR_RAZORGORE_ENTER:
                m_auiData[DATA_DOOR_RAZORGORE_ENTER] = pGo->GetObjectGuid();
                break;
            case GO_DOOR_RAZORGORE_EXIT:
                m_auiData[DATA_DOOR_RAZORGORE_EXIT] = pGo->GetObjectGuid();
                if (m_auiEncounter[TYPE_RAZORGORE] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_DOOR_NEFARIAN:
                m_auiData[DATA_DOOR_NEFARIAN] = pGo->GetObjectGuid();
                break;
            case GO_DOOR_CHROMAGGUS_ENTER:
                m_auiData[DATA_DOOR_CHROMAGGUS_ENTER] = pGo->GetObjectGuid();
                break;
            case GO_DOOR_CHROMAGGUS_SIDE:
                m_auiData[DATA_DOOR_CHROMAGGUS_SIDE] = pGo->GetObjectGuid();
                if (m_auiEncounter[TYPE_CHROMAGGUS] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_DOOR_CHROMAGGUS_EXIT:
                m_auiData[DATA_DOOR_CHROMAGGUS_EXIT] = pGo->GetObjectGuid();
                if (m_auiEncounter[TYPE_CHROMAGGUS] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_DOOR_VAELASTRASZ:
                m_auiData[DATA_DOOR_VAELASTRASZ] = pGo->GetObjectGuid();
                if (m_auiEncounter[TYPE_VAELASTRASZ] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_DOOR_LASHLAYER:
                m_auiData[DATA_DOOR_LASHLAYER] = pGo->GetObjectGuid();
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pGo->DeleteLater();
                break;
            case GO_ORBE_DOMINATION:
                m_auiData[DATA_ORB_DOMINATION_GUID] = pGo->GetObjectGuid();
            case GO_OEUF_RAZ:
                if (m_auiEncounter[TYPE_RAZORGORE] == DONE)
                    pGo->DeleteLater();
                break;
            case GO_SUPPRESSION_ENGINE:
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pGo->DeleteLater();
                break;
        }
    }

    void OnCreatureEnterCombat(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case MOB_GRETHOK:
            case MOB_GARDE_AILE_NOIRE:
                if (m_auiEncounter[TYPE_RAZORGORE] == NOT_STARTED)
                    m_auiEncounter[TYPE_RAZORGORE] = IN_PROGRESS;
                if (Creature* pCreature = instance->GetCreature(m_auiData[DATA_RAZORGORE_GUID]))
                {
                    if (pCreature->IsAlive() && !pCreature->IsInCombat())
                        pCreature->SetInCombatWithZone();
                }
                break;
            case NPC_RAZORGORE:
                if (Creature* pCreature = instance->GetCreature(m_auiData[DATA_GRETOK_GUID]))
                {
                    if (pCreature->IsAlive() && !pCreature->IsInCombat())
                        pCreature->SetInCombatWithZone();
                }
                break;
        }
    }

    void OnCreatureEvade(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case MOB_DRACO_VERT:
                pCreature->AddAura(SPELL_NATURE_IMMUNITY, ADD_AURA_PERMANENT);
                break;
            case MOB_DRACO_BLEU:
                pCreature->AddAura(SPELL_FROST_IMMUNITY, ADD_AURA_PERMANENT);
                break;
            case MOB_DRACO_ROUGE:
                pCreature->AddAura(SPELL_FIRE_IMMUNITY, ADD_AURA_PERMANENT);
                break;
            case MOB_DRACO_BRONZE:
                pCreature->AddAura(SPELL_ARCANE_IMMUNITY, ADD_AURA_PERMANENT);
                break;
        }
    }

    void OnCreatureRespawn(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case MOB_RAZ_TRIGGER:
                pCreature->DeleteLater();
                break;
            case MOB_GRETHOK:
            case MOB_GARDE_AILE_NOIRE:
                if (m_auiEncounter[TYPE_RAZORGORE] == DONE)
                    pCreature->DeleteLater();
                break;
            case MOB_DRACO_VERT:
            case MOB_DRACO_BLEU:
            case MOB_DRACO_ROUGE:
            case MOB_DRACO_BRONZE:
                switch (rand() % 4)
                {
                    case 0:
                        pCreature->SetEntry(MOB_DRACO_BLEU);
                        pCreature->UpdateEntry(MOB_DRACO_BLEU);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_FROST_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 1:
                        pCreature->SetEntry(MOB_DRACO_VERT);
                        pCreature->UpdateEntry(MOB_DRACO_VERT);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_NATURE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 2:
                        pCreature->SetEntry(MOB_DRACO_ROUGE);
                        pCreature->UpdateEntry(MOB_DRACO_ROUGE);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_FIRE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 3:
                        pCreature->SetEntry(MOB_DRACO_BRONZE);
                        pCreature->UpdateEntry(MOB_DRACO_BRONZE);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_ARCANE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                }
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pCreature->DeleteLater();
                else if (m_auiEncounter[TYPE_LASHLAYER] == IN_PROGRESS)
                {
                    pCreature->SetVisibility(VISIBILITY_OFF);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                    pCreature->ForcedDespawn(1000);
                }
                else if (m_auiEncounter[TYPE_LASHLAYER] == FAIL)
                {
                    pCreature->SetVisibility(VISIBILITY_ON);
                    pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                }
                break;
            case MOB_EVEILLEUR_GRIFFEMORT:
            case MOB_SOUS_CHEF_AILE_NOIRE:
            case MOB_RONGE_GRIFFEMORT:
            case MOB_WYRMIDE_GRIFFEMORT:
            case MOB_FLAMMECAILLE_GRIFFEMORT:
            case MOB_CAPITAINE_GRIFFEMORT:
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pCreature->DeleteLater();
                break;
            case MOB_DEMONISTE_AILE_NOIRE:
            case MOB_LIEUR_SORT_AILE_NOIRE:
            case MOB_GARDE_WYRM_GRIFFEMORT:
            case MOB_TECHNICIEN_AILE_NOIRE:
            case MOB_SURVEILLANT_GRIFFEMORT:
                if (m_auiEncounter[TYPE_FIREMAW] == DONE &&
                        m_auiEncounter[TYPE_EBONROC] == DONE &&
                        m_auiEncounter[TYPE_FLAMEGOR] == DONE)
                    pCreature->DeleteLater();
                break;
            case NPC_VAELASTRASZ:
                if (m_auiEncounter[TYPE_VAELASTRASZ] == DONE)
                    pCreature->DeleteLater();
                break;
            case NPC_LORD_NEFARIAN:
                if (pCreature->IsTemporarySummon()) // second nefarion summoned temporarily for vael event
                    break;
                if (m_auiEncounter[TYPE_NEFARIAN] == DONE)
                    pCreature->DeleteLater();
                break;
        }
    }

    void OnCreatureDeath(Creature *who) override
    {
        switch (who->GetEntry())
        {
            case NPC_RAZORGORE:
                if (m_auiEncounter[TYPE_RAZORGORE] == FAIL)
                {
                    if (Creature* pRazorgore = instance->GetCreature(m_auiData[DATA_RAZORGORE_GUID]))
                        pRazorgore->MonsterYell("If I fall into the abyss, I'll take all of you mortals with me!",0,0);
                }
                break;
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_RAZORGORE:
                m_auiData[DATA_RAZORGORE_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_VAELASTRASZ:
                m_auiData[DATA_VAELASTRASZ_GUID] = pCreature->GetObjectGuid();
                if (m_auiEncounter[TYPE_VAELASTRASZ] == DONE)
                    pCreature->DeleteLater();
                break;
            case NPC_LASHLAYER:
                m_auiData[DATA_LASHLAYER_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_FIREMAW:
                m_auiData[DATA_FIREMAW_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_EBONROC:
                m_auiData[DATA_EBONROC_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_FLAMEGOR:
                m_auiData[DATA_FLAMEGOR_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_CHROMAGGUS:
                m_auiData[DATA_CHROMAGGUS_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_NEFARIAN:
                m_auiData[DATA_NEFARIAN_GUID] = pCreature->GetObjectGuid();
                break;
            case NPC_LORD_NEFARIAN:
                if (pCreature->IsTemporarySummon()) // second nefarion summoned temporarily for vael event
                    break;
                m_auiData[DATA_NEFARIUS_GUID] = pCreature->GetObjectGuid();
                if (m_auiEncounter[TYPE_NEFARIAN] == DONE)
                    pCreature->DeleteLater();
                break;
            case MOB_GRETHOK:
                m_auiData[DATA_GRETOK_GUID] = pCreature->GetObjectGuid();
            case MOB_GARDE_AILE_NOIRE:
                if (m_auiEncounter[TYPE_RAZORGORE] == DONE)
                    pCreature->DeleteLater();
                break;
            case MOB_RAZ_TRIGGER:
                m_auiData[DATA_TRIGGER_GUID] =  pCreature->GetObjectGuid();
                break;
            case MOB_DRACO_VERT:
            case MOB_DRACO_BLEU:
            case MOB_DRACO_ROUGE:
            case MOB_DRACO_BRONZE:
                switch (rand() % 4)
                {
                    case 0:
                        pCreature->SetEntry(MOB_DRACO_BLEU);
                        pCreature->UpdateEntry(MOB_DRACO_BLEU);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_FROST_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 1:
                        pCreature->SetEntry(MOB_DRACO_VERT);
                        pCreature->UpdateEntry(MOB_DRACO_VERT);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_NATURE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 2:
                        pCreature->SetEntry(MOB_DRACO_ROUGE);
                        pCreature->UpdateEntry(MOB_DRACO_ROUGE);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_FIRE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                    case 3:
                        pCreature->SetEntry(MOB_DRACO_BRONZE);
                        pCreature->UpdateEntry(MOB_DRACO_BRONZE);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_ARCANE_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                }
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE || m_auiEncounter[TYPE_LASHLAYER] == IN_PROGRESS)
                    pCreature->DeleteLater();
                break;
            case MOB_RONGE_GRIFFEMORT:
            case MOB_WYRMIDE_GRIFFEMORT:
            case MOB_FLAMMECAILLE_GRIFFEMORT:
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pCreature->DeleteLater();/*
                else switch (rand() % 4)
                {
                    case 0:
                        pCreature->SetEntry(MOB_DRACO_BLEU);
                        pCreature->UpdateEntry(MOB_DRACO_BLEU);
                        pCreature->RemoveAllAuras();
                        pCreature->AddAura(SPELL_FROST_IMMUNITY, ADD_AURA_PERMANENT);
                        break;
                        }*/
                break;
            case MOB_CAPITAINE_GRIFFEMORT:
            case MOB_EVEILLEUR_GRIFFEMORT:
            case MOB_SOUS_CHEF_AILE_NOIRE:
                if (m_auiEncounter[TYPE_LASHLAYER] == DONE)
                    pCreature->DeleteLater();
                break;
            case MOB_TECHNICIEN_AILE_NOIRE:
                if (pCreature->GetPositionZ() < 420.0f)
                {
                    if (m_auiEncounter[TYPE_VAEL_EVENT] == DONE)
                    {
                        pCreature->DeleteLater();
                        break;
                    }
                    if (m_auiEncounter[TYPE_RAZORGORE] != DONE)
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    m_lVaelGobs.push_back(pCreature->GetObjectGuid());
                 }
            case MOB_DEMONISTE_AILE_NOIRE:
            case MOB_LIEUR_SORT_AILE_NOIRE:
            case MOB_GARDE_WYRM_GRIFFEMORT:
            case MOB_SURVEILLANT_GRIFFEMORT:
                if (m_auiEncounter[TYPE_FIREMAW] == DONE &&
                    m_auiEncounter[TYPE_EBONROC] == DONE &&
                    m_auiEncounter[TYPE_FLAMEGOR] == DONE)
                    pCreature->DeleteLater();
                break;
        }
    }

    void OnPlayerDeath(Player *player) override
    {
        m_hBlackwingTechnicians.RemovePotentialVictim(player->GetObjectGuid());
    }

    uint64 GetData64(uint32 data) override
    {
        if (data < MAX_DATAS)
            return m_auiData[data];
        return 0;
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
        case DATA_SCEPTER_RUN_TIME:
            m_auiData[DATA_SCEPTER_RUN_TIME] = uiData;
            break;

        case TYPE_RAZORGORE:
            m_auiEncounter[TYPE_RAZORGORE] = uiData;
            if (uiData == IN_PROGRESS)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_ENTER]))
                {
                    if (pGo->GetGoState() == GO_STATE_ACTIVE) // Open
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_ENTER]);
                }
            }
            else if (uiData == FAIL)
            {
                m_auiData[DATA_HOW_EGG] = 0;
                RepopOeufs();
                SetData(DATA_EGG, FAIL);
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_ENTER]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_ENTER]);
                }
            }
            else if (uiData == DONE)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_EXIT]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_EXIT]);
                }
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_ENTER]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_ENTER]);
                }
                for (const auto& guid : m_lVaelGobs)
                {
                    if (Creature *pCreature = instance->GetCreature(guid))
                    {
                        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
            }
            break;
        case TYPE_VAELASTRASZ:
            m_auiEncounter[TYPE_VAELASTRASZ] = uiData;
            if (uiData == IN_PROGRESS)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_EXIT]))
                {
                    if (pGo->GetGoState() == GO_STATE_ACTIVE) // Open
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_EXIT]);
                }
            }
            else if (uiData == DONE)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_EXIT]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_EXIT]);
                }
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_VAELASTRASZ]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_VAELASTRASZ]);
                }
            }
            else if (uiData == FAIL)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_RAZORGORE_EXIT]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_RAZORGORE_EXIT]);
                }
            }
            break;
        case TYPE_LASHLAYER:
            m_auiEncounter[TYPE_LASHLAYER] = uiData;
            if (uiData == DONE)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_LASHLAYER]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_LASHLAYER]);
                }
            }
            break;
        case TYPE_FIREMAW:
            m_auiEncounter[TYPE_FIREMAW] = uiData;
            break;
        case TYPE_EBONROC:
            m_auiEncounter[TYPE_EBONROC] = uiData;
            break;
        case TYPE_FLAMEGOR:
            m_auiEncounter[TYPE_FLAMEGOR] = uiData;
            break;
        case TYPE_CHROMAGGUS:
            m_auiEncounter[TYPE_CHROMAGGUS] = uiData;
            if (uiData == DONE)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_CHROMAGGUS_EXIT]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_CHROMAGGUS_EXIT]);
                }
            }
            break;
        case TYPE_NEFARIAN:
            m_auiEncounter[TYPE_NEFARIAN] = uiData;
            if (uiData == DONE || uiData == FAIL)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_NEFARIAN]))
                {
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // Close
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_NEFARIAN]);
                }
            }
            if (uiData == IN_PROGRESS)
            {
                if (GameObject* pGo = instance->GetGameObject(m_auiData[DATA_DOOR_NEFARIAN]))
                {
                    if (pGo->GetGoState() == GO_STATE_ACTIVE) // Open
                        DoUseDoorOrButton(m_auiData[DATA_DOOR_NEFARIAN]);
                }
            }
            break;
        case TYPE_VAEL_EVENT:
            m_auiEncounter[TYPE_VAEL_EVENT] = uiData;
            if (uiData == DONE)
            {
                bool bYelled = false;
                for (const auto& guid : m_lVaelGobs)
                {
                    if (Creature *pCreature = instance->GetCreature(guid))
                    {
                        if (!bYelled)
                        {
                            bYelled = true;
                        }
                        pCreature->MonsterMoveWithSpeed(-7608.0f, -888.0f, 432.0f, 10.0f, pCreature->GetSpeed(MOVE_RUN), uint32(MOVE_PATHFINDING));
                    }
                }
            }
            break;
        case DATA_EGG:
            if (uiData == IN_PROGRESS)
            {
                if (++m_auiData[DATA_HOW_EGG] >= EGGS_COUNT)
                    m_auiData[DATA_EGG] = DONE;
            }
            else if (uiData == FAIL)
            {
                if (Creature *pCreature = instance->GetCreature(m_auiData[DATA_TRIGGER_GUID]))
                    pCreature->DeleteLater();
                m_auiData[DATA_TRIGGER_GUID] = 0;
                m_auiData[DATA_EGG] = FAIL;
            }
            break;

        case TYPE_SCEPTER_RUN:
            m_auiEncounter[TYPE_SCEPTER_RUN] = uiData;
            break;

        case DATA_SCEPTER_CHAMPION:
            m_auiData[DATA_SCEPTER_CHAMPION] = uiData;
            break;
        case GOSSIP_OPTION_NEFARIUS:
            if (Creature* pCreature = GetCreature(m_auiData[DATA_NEFARIUS_GUID]))
                NefariusGossipOptionClicked(pCreature);
            break;
        }

        if (uiData == DONE || TYPE_SCEPTER_RUN == uiType || DATA_SCEPTER_CHAMPION == uiData)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << 
            " " << m_auiEncounter[5] << " " << m_auiEncounter[6] << " " << m_auiEncounter[7] << " " << m_auiEncounter[8] << " " << m_auiData[DATA_CHROM_BREATH] << 
            " " << m_auiData[DATA_NEF_COLOR] << " " << m_auiEncounter[9] << " " << m_auiData[DATA_SCEPTER_RUN_TIME] << " " << m_auiData[DATA_SCEPTER_CHAMPION];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    bool CheckConditionCriteriaMeet(Player const* player, uint32 map_id, WorldObject const* source, uint32 instance_condition_id) const override
    {
        ObjectGuid scepterChampion = m_auiData[DATA_SCEPTER_CHAMPION];

        // No scepter run attempted
        if (0 == scepterChampion)
            return false;

        // On scepter "alternate success", give everyone a copy of "From the Desk of Lord Victor Nefarius"
        if (CONDITION_SCEPTER_FAIL == instance_condition_id)
        {
            if (FAIL == m_auiEncounter[TYPE_SCEPTER_RUN])
                return true;
        }

        // A true champion. Reward only this one with the Red Scepter Shard
        if (CONDITION_SCEPTER_WIN == instance_condition_id)
        { 
            if (DONE == m_auiEncounter[TYPE_SCEPTER_RUN] && player->GetGUID() == scepterChampion)
                return true;
        }

        return false;

    }

    char const* Save() override
    {
        return strInstData.c_str();
    }

    uint32 GetData(uint32 uiType) override
    {
        if (uiType < MAX_ENCOUNTER)
            return (m_auiEncounter[uiType]);
        return 0;
    }

    void Load(char const* chrIn) override
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);

        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> 
        m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6] >> m_auiEncounter[7] >> m_auiEncounter[8] >> 
        m_auiData[DATA_CHROM_BREATH] >> m_auiData[DATA_NEF_COLOR] >> m_auiEncounter[9] >> m_auiData[DATA_SCEPTER_RUN_TIME]
        >> m_auiData[DATA_SCEPTER_CHAMPION];

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (TYPE_SCEPTER_RUN != i)
                if (m_auiEncounter[i] == IN_PROGRESS)           // Do not load an encounter as "In Progress" - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }

    void RepopOeufs()
    {
        Creature* pCreature = instance->GetCreature(m_auiData[DATA_RAZORGORE_GUID]);

        if (pCreature)
        {
            std::list<GameObject *> lGameObjects;
            pCreature->GetGameObjectListWithEntryInGrid(lGameObjects, GO_OEUF_RAZ, 250.0f);
            for (const auto pGo : lGameObjects)
                pGo->DeleteLater();

            for (const auto& position : RazOeufs)
                pCreature->SummonGameObject(GO_OEUF_RAZ, position.X, position.Y, position.Z, position.O);
        }
    }

    blackwing_technicians_helper *GetTechnicianHelper() { return &m_hBlackwingTechnicians; }
};

InstanceData* GetInstanceData_instance_blackwing_lair(Map* pMap)
{
    return new instance_blackwing_lair(pMap);
}

bool GOHello_go_orbe_domination(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        if (!pPlayer->HasAura(SPELL_MIND_EXHAUSTION))
        {
            if (Creature* pCreature = pGo->GetMap()->GetCreature(pInstance->GetData64(DATA_RAZORGORE_GUID)))
            {
                // Deja CM ?
                if (pCreature->HasUnitState(UNIT_STAT_POSSESSED))
                    return true;
                if (pCreature->IsInCombat() && pInstance->GetData64(DATA_EGG) != DONE)
                {
                    pPlayer->CastSpell(pPlayer, SPELL_MIND_EXHAUSTION, true);
                    pPlayer->CastSpell(pCreature, SPELL_POSSESS, true);
                    if (Creature* pTrigger = pGo->GetMap()->GetCreature(pInstance->GetData64(DATA_TRIGGER_GUID)))
                    {
                        pCreature->AddThreat(pTrigger, 100.0f);
                        pTrigger->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, pCreature->GetObjectGuid());
                        pTrigger->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_POSSESS_VISUAL);
                    }
                }
            }
        }
    }

    return true;
}

struct go_oeuf_razAI: public GameObjectAI
{
    go_oeuf_razAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser) override
    {
        if (!pUser)
            return true;
        if (ScriptedInstance* pInstance = (ScriptedInstance*)me->GetInstanceData())
        {
            pInstance->SetData(DATA_EGG, IN_PROGRESS);
            //char sMessage[200];
            //sprintf(sMessage, "Nombre d'oeufs detruits : %d sur 30", pInstance->GetData64(DATA_HOW_EGG));
            if (pUser->IsCreature() && pUser->GetEntry() == NPC_RAZORGORE)
            {
                //pUser->MonsterYell(sMessage, 0);
                DoScriptText(EMOTE_DESTROY_EGG, pUser);
                switch (urand(0, 5))
                {
                    case 0:
                        pUser->MonsterYell("No! Not another one! I'll have your heads for this atrocity!", LANG_UNIVERSAL);
                        pUser->PlayDirectSound(8277);
                        break;
                    case 1:
                        pUser->MonsterYell("Fools! These eggs are more precious than you know!", LANG_UNIVERSAL);
                        pUser->PlayDirectSound(8276);
                        break;
                    case 2:
                        pUser->MonsterYell("You'll pay for forcing me to do this!", LANG_UNIVERSAL);
                        pUser->PlayDirectSound(8275);
                        break;
                }

                if (pInstance->GetData64(DATA_EGG) == DONE)
                {
                    pUser->RemoveAllAuras();
                    if (pUser->GetMaxHealth() != 450000)
                        pUser->SetMaxHealth(450000);
                    pUser->CastSpell(pUser, SPELL_WARMING_FLAMES, true);
                }
            }
            me->Delete();
        }

        return true;
    }
};

GameObjectAI* GetAIgo_oeuf_raz(GameObject *pGo)
{
    return new go_oeuf_razAI(pGo);
}

struct go_engin_suppressionAI: public GameObjectAI
{
    go_engin_suppressionAI(GameObject* pGo) : GameObjectAI(pGo), m_uiCheckTimer(urand(6000, 12000)), m_bActive(true) {}

    uint32 m_uiCheckTimer;
    bool m_bActive;

    bool OnUse(Unit* pUser) override
    {
        if (pUser->IsWithinDistInMap(me, 5.0f))
        {
            me->SetGoState(GO_STATE_ACTIVE);
            m_bActive = false;
            m_uiCheckTimer = urand(4000, 6000);
            return true;
        }
        else
            return false;
    }

    void ApplyAura()
    {
        me->SendGameObjectCustomAnim();
        Map::PlayerList const &liste = me->GetMap()->GetPlayers();
        for (const auto& i : liste)
        {
            if (me->GetDistance(i.getSource()) <= 15.0f)
                if (!i.getSource()->HasStealthAura() && i.getSource()->IsAlive() && !i.getSource()->IsGameMaster())
                    i.getSource()->AddAura(SPELL_SUPPRESSION_AURA);
        }
    }

    void RestoreGo()
    {
        if (me->GetInstanceData()->GetData(TYPE_LASHLAYER) == DONE)
            return;

        me->SetGoState(GO_STATE_READY);
        m_bActive = true;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiCheckTimer <= uiDiff)
        {
            if (m_bActive)
                ApplyAura();
            else
            {
                if (!urand(0, 4))
                {
                    RestoreGo();
                    m_uiCheckTimer = urand(3000, 4000);
                    return;
                }
            }
            m_uiCheckTimer = 6000;
            return;
        }
        m_uiCheckTimer -= uiDiff;
    }
};

GameObjectAI* GetAIgo_engin_suppression(GameObject *pGo)
{
    return new go_engin_suppressionAI(pGo);
}

bool AreaTrigger_at_orb_of_command(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pAt->id == AT_ORB_OF_COMMAND)
    {
        Corpse *pCorpse = pPlayer->GetCorpse();
        if (pPlayer->IsDead() && pPlayer->GetQuestRewardStatus(7761) && pCorpse && (pCorpse->GetMapId() == 469))
        {
            pPlayer->ResurrectPlayer(0.5f);
            pPlayer->SpawnCorpseBones();
            pPlayer->TeleportTo(469, -7672.32f, -1107.05f, 396.651f, 0.785398f);
        }
    }

    return false;
}

bool AreaTrigger_at_enter_vael_room(Player *pPlayer, AreaTriggerEntry const* pAt)
{
    if (pAt->id == AT_ENTER_VAEL_ROOM)
    {
        if (pPlayer->IsGameMaster())
            return false;

        if (ScriptedInstance* pInstance = (ScriptedInstance*)pPlayer->GetMap()->GetInstanceData())
        {
            if (pInstance->GetData(TYPE_VAEL_EVENT) != DONE)
                pInstance->SetData(TYPE_VAEL_EVENT, DONE);
        }
    }

    return false;
}

/*######
## npc_death_talon
######*/

enum
{
    NPC_OVERSEER                = 12461,
    NPC_WYRMGUARD               = 12460,

    SPELL_CLEAVE                = 15284,
    SPELL_WARSTOMP              = 24375,
    SPELL_FIREBLAST             = 20623,
    SPELL_BROODPOWER_BLUE       = 22285,
    SPELL_BROODPOWER_BLACK      = 22287,
    SPELL_BROODPOWER_BRONZE     = 22286,
    SPELL_BROODPOWER_RED        = 22283,
    SPELL_BROODPOWER_GREEN      = 22288,

    SPELL_FIRE_VULNERABILITY    = 22277,
    SPELL_FROST_VULNERABILITY   = 22278,
    SPELL_SHADOW_VULNERABILITY  = 22279,
    SPELL_NATURE_VULNERABILITY  = 22280,
    SPELL_ARCANE_VULNERABILITY  = 22281
};

struct npc_death_talonAI : public ScriptedAI
{
    npc_death_talonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_uiBroodPower = RandomPower();
        m_uiSchoolSensibility = RandomSensibility();
        m_bIsOverSeer = (pCreature->GetEntry() == NPC_OVERSEER);
        Reset();
    }

    uint32 m_uiCleaveTimer;
    uint32 m_uiWarStompTimer;
    uint32 m_uiFireBlastTimer;
    uint32 m_uiBroodPower;
    uint32 m_uiSchoolSensibility;
    bool m_bIsOverSeer;

    void Reset() override
    {
        m_uiCleaveTimer     = urand(5000, 9000);
        m_uiWarStompTimer   = 8000;
        m_uiFireBlastTimer  = 8000;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_uiBroodPower = RandomPower();
        m_uiSchoolSensibility = RandomSensibility();
    }

    void Aggro(Unit* /*pWho*/) override
    {
        // aggro Master Elementalist with the pull
        if (!m_bIsOverSeer)
            m_creature->CallForHelp(15.0f);
    }

    uint32 RandomPower()
    {
        switch (urand(0, 4))
        {
            case 0:
                return SPELL_BROODPOWER_BLUE;
            case 1:
                return SPELL_BROODPOWER_BLACK;
            case 2:
                return SPELL_BROODPOWER_BRONZE;
            case 3:
                return SPELL_BROODPOWER_RED;
            case 4:
                return SPELL_BROODPOWER_GREEN;
        }
        return (0);
    }

    uint32 RandomSensibility()
    {
        switch (urand(0, 4))
        {
            case 0:
                return SPELL_FIRE_VULNERABILITY;
            case 1:
                return SPELL_FROST_VULNERABILITY;
            case 2:
                return SPELL_SHADOW_VULNERABILITY;
            case 3:
                return SPELL_NATURE_VULNERABILITY;
            case 4:
                return SPELL_ARCANE_VULNERABILITY;
        }
        return (0);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_bIsOverSeer && !m_creature->HasAura(m_uiBroodPower))
            m_creature->AddAura(m_uiBroodPower);

        if (!m_creature->HasAura(m_uiSchoolSensibility))
            m_creature->AddAura(m_uiSchoolSensibility);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(5000, 9000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        if (!m_bIsOverSeer)
        {
            if (m_uiWarStompTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_WARSTOMP) == CAST_OK)
                    m_uiWarStompTimer = urand(8000, 14000);
            }
            else
                m_uiWarStompTimer -= uiDiff;
        }
        else
        {
            if (m_uiFireBlastTimer < uiDiff)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_FIREBLAST) == CAST_OK)
                        m_uiFireBlastTimer = 10000;
                }
            }
            else
                m_uiFireBlastTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_death_talon(Creature* pCreature)
{
    return new npc_death_talonAI(pCreature);
}

enum
{
    SPELL_BOMB          = 22334,
    SPELL_POISON_BOTTLE = 22335
};

struct npc_blackwing_technicianAI : public ScriptedAI
{
    npc_blackwing_technicianAI(Creature* pCreature) : ScriptedAI(pCreature), m_pTechnicianHelper(nullptr)
    {
        m_bAdded = false;
        m_bVaelGob = (pCreature->GetPositionZ() < 420.0f);
        if (ScriptedInstance *pInstance = (ScriptedInstance*)pCreature->GetInstanceData())
        {
            if (instance_blackwing_lair *pBlackwingLair = dynamic_cast<instance_blackwing_lair*>(pInstance))
                m_pTechnicianHelper = pBlackwingLair->GetTechnicianHelper();
        }
        Reset();
    }

    uint32 m_uiPoisonBottleTimer;
    uint32 m_uiAggroSyncTimer;
    uint32 m_uiEmoteTimer;
    bool m_bVaelGob;
    bool m_bAdded;
    blackwing_technicians_helper *m_pTechnicianHelper;

    void Reset() override
    {
        if (m_pTechnicianHelper && m_bAdded)
        {
            m_pTechnicianHelper->RemoveTechnician(m_creature);
            m_bAdded = false;
        }
        m_uiPoisonBottleTimer = 2000;
        m_uiAggroSyncTimer = 5000;
        if (!m_bVaelGob)
            m_uiEmoteTimer = urand(0, 1) ? 1000 : 3000;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (!m_bVaelGob)
            ScriptedAI::MoveInLineOfSight(pWho);
    }

    void Aggro(Unit* who) override
    {
        if (m_pTechnicianHelper && !m_bAdded)
        {
            m_pTechnicianHelper->AddTechnician(m_creature);
            m_bAdded = true;
        }
        ScriptedAI::Aggro(who);
    }

    void JustDied(Unit* killer) override
    {
        if (m_pTechnicianHelper && m_bAdded)
        {
            m_pTechnicianHelper->RemoveTechnician(m_creature);
            m_bAdded = false;
        }
        ScriptedAI::JustDied(killer);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_bVaelGob && m_creature->GetPositionZ() >= 430.0f)
            m_creature->DeleteLater();

        if (m_uiEmoteTimer)
        {
            if (m_uiEmoteTimer <= uiDiff)
            {
                m_creature->HandleEmote(133);
                m_uiEmoteTimer = 0;
            }
            else m_uiEmoteTimer -= uiDiff;
        }

        // If we don't have a current victim and we're not added to the helper, stop AI.
        // Have to check the helper if possible in case the victim has died, otherwise
        // the technician will stand still doing nothing rather than re-targeting
        if (!m_creature->GetVictim() && !m_bAdded)
            return;

        if (m_pTechnicianHelper)
        {
            if (m_uiAggroSyncTimer <= uiDiff)
            {
                m_pTechnicianHelper->RecalculateThreat();
                m_uiAggroSyncTimer = 2500;
            }
            else
                m_uiAggroSyncTimer -= uiDiff;
        }

        Unit* victim = m_creature->GetVictim();
        if (m_pTechnicianHelper)
            if (ObjectGuid victimGuid = m_pTechnicianHelper->GetVictimGuid())
                victim = m_pTechnicianHelper->GetInstance()->instance->GetUnit(victimGuid);
        
        if (!victim)
            return;

        if (victim)
        {
            AttackStart(victim);

            if (m_uiPoisonBottleTimer <= uiDiff)
                m_uiPoisonBottleTimer = 0;
            else
                m_uiPoisonBottleTimer -= uiDiff;

            if (m_creature->IsWithinLOSInMap(victim))
            {
                if (!m_uiPoisonBottleTimer && DoCastSpellIfCan(victim, SPELL_POISON_BOTTLE) == CAST_OK)
                    m_uiPoisonBottleTimer = urand(3500, 6000);
                else
                    m_creature->CastSpell(victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ(), SPELL_BOMB, false);
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_blackwing_technician(Creature* pCreature)
{
    return new npc_blackwing_technicianAI(pCreature);
}

struct CorruptedWhelpAI : public ScriptedAI
{
    CorruptedWhelpAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }


    void Reset() override
    {
    }

    /*
    void Aggro(Unit* pWho)
    {
        m_creature->SetInCombatWithZone();
    }
    */

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_corrupted_whelp(Creature* pCreature)
{
    return new CorruptedWhelpAI(pCreature);
}


void AddSC_instance_blackwing_lair()
{
    Script* pNewscript;
    pNewscript = new Script;
    pNewscript->Name = "instance_blackwing_lair";
    pNewscript->GetInstanceData = &GetInstanceData_instance_blackwing_lair;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "go_orbe_domination";
    pNewscript->pGOHello = &GOHello_go_orbe_domination;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "go_oeuf_raz";
    pNewscript->GOGetAI = &GetAIgo_oeuf_raz;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "go_engin_suppression";
    pNewscript->GOGetAI = &GetAIgo_engin_suppression;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "at_orb_of_command";
    pNewscript->pAreaTrigger = &AreaTrigger_at_orb_of_command;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "at_enter_vael_room";
    pNewscript->pAreaTrigger = &AreaTrigger_at_enter_vael_room;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "npc_death_talon";
    pNewscript->GetAI = &GetAI_npc_death_talon;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "npc_corrupted_whelp";
    pNewscript->GetAI = &GetAI_npc_corrupted_whelp;
    pNewscript->RegisterSelf();

    pNewscript = new Script;
    pNewscript->Name = "npc_blackwing_technician";
    pNewscript->GetAI = &GetAI_npc_blackwing_technician;
    pNewscript->RegisterSelf();
}
