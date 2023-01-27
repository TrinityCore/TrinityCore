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
SDName: Instance_Naxxramas
SD%Complete:
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"
#include "InstanceStatistics.h"

enum NaxxEvents
{
    EVENT_BIGGLESWORTH_DIED_YELL = 1,
    EVENT_THADDIUS_SCREAM,
    EVENT_WINGBOSS_DEAD,

    EVENT_KT_LK_DIALOGUE_1,
    EVENT_KT_LK_DIALOGUE_2,
    EVENT_KT_LK_DIALOGUE_3,
    EVENT_KT_LK_DIALOGUE_4,
    EVENT_KT_LK_DIALOGUE_5,
    EVENT_KT_LK_DIALOGUE_GATE_OPEN,

    EVENT_SUMMON_FROGGER_WAVE,

    EVENT_4HM_DIALOGUE_1, // Sir Zeliek yells: Invaders! Cease this foolish venture at once! Turn away while you still can!
    EVENT_4HM_DIALOGUE_2, // Lady Blaumeux yells: Come, Zeliek, do not drive them out. Not until we've had our fun!
    EVENT_4HM_DIALOGUE_3, // Highlord Mograine yells: Enough prattling. Let them come. We shall grind their bones to dust.
    EVENT_4HM_DIALOGUE_4, // Lady Blaumeux yells: I do hope they stay long enough for me to... introduce myself.
    EVENT_4HM_DIALOGUE_5, // Sir Zeliek yells: Perhaps they will come to their senses... and run away as fast as they can.
    EVENT_4HM_DIALOGUE_6, // Thane Korth'azz yells: I've heard about enough a' yer snivelin'!Shut your flytrap before I shut it for ye'!
    EVENT_4HM_DIALOGUE_7, // Highlord Mograine yells: Conserve your anger. Harness your rage. You will all have outlets for your frustrations soon enough.

    EVENT_DKWING_INTRO_2,
    EVENT_DKWING_INTRO_3,
    EVENT_DKWING_INTRO_4
};

instance_naxxramas::instance_naxxramas(Map* pMap) : ScriptedInstance(pMap),
    m_faerlinaHaveGreeted(false),
    m_thaddiusHaveGreeted(false),
    m_haveDoneDKWingIntro(false),
    m_horsemenDeathCounter(0),
    m_uiHorsemenChestGUID(0),
    m_fChamberCenterX(0.0f),
    m_fChamberCenterY(0.0f),
    m_fChamberCenterZ(0.0f)
{
    Initialize();
}

void instance_naxxramas::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    m_events.Reset();
    // 2-5min, no idea if it's correct
    m_events.ScheduleEvent(EVENT_THADDIUS_SCREAM, urand(1000 * 60 * 2, 1000 * 60 * 5));

    m_events.ScheduleEvent(EVENT_SUMMON_FROGGER_WAVE, Seconds(6));
}

void instance_naxxramas::SetTeleporterVisualState(GameObject* pGO, uint32 uiData)
{
    if (uiData == DONE)
        pGO->SetGoState(GO_STATE_ACTIVE);
    else
        pGO->SetGoState(GO_STATE_READY);
}

void instance_naxxramas::SetTeleporterState(GameObject* pGO, uint32 uiData)
{
    SetTeleporterVisualState(pGO, uiData);
    if (uiData == DONE)
        pGO->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
    else
        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
}

uint8 instance_naxxramas::GetNumEndbossDead()
{
    uint8 ret = 0;
    if (GetData(TYPE_MAEXXNA) == DONE)
        ++ret;
    if (GetData(TYPE_THADDIUS) == DONE)
        ++ret;
    if (GetData(TYPE_FOUR_HORSEMEN) == DONE)
        ++ret;
    if (GetData(TYPE_LOATHEB) == DONE)
        ++ret;
    return ret;
}

bool instance_naxxramas::HandleEvadeOutOfHome(Creature* pWho)
{
    if (pWho->IsInEvadeMode())
        return false;

    uint32 entry = pWho->GetEntry();
    float dist;
    switch (entry)
    {
        case NPC_GROBBULUS:
            dist = 180.0f;
            break;
        case NPC_FAERLINA:
            if (pWho->GetPositionZ() > 266.0f)
            {
                pWho->AI()->EnterEvadeMode();
                return false;
            }
            return true;
        case NPC_ANUB_REKHAN:
            dist = 130.0f;
            break;
        case NPC_NOTH:
            dist = 120.0f;
            break;
        case NPC_HEIGAN:
        {
            // evade if brought out of room towards bat/grub/beast gauntlet
            if (pWho->GetPositionX() > 2825.0f)
            {
                pWho->AI()->EnterEvadeMode();
                return false;
            }
            dist = 90.0f;
            break;
        }
        case NPC_LOATHEB:
            dist = 100.0f;
            break;
        case NPC_GOTHIK:
        {
            dist = 150.0f;
            break;
        }
        case NPC_RAZUVIOUS:
            if (pWho->GetPositionZ() > 285.0f)
            {
                pWho->AI()->EnterEvadeMode();
                return false;
            }
            return true;
        case NPC_KELTHUZAD:
            dist = 130.0f;
            break;
        case NPC_BLAUMEUX:
        case NPC_MOGRAINE:
        case NPC_ZELIEK:
        case NPC_THANE:
            dist = 115.0f;
            break;
        default:
            sLog.outError("instance_naxxramas::HandleEvadeOutOfHome called for unsupported creture %d", pWho->GetEntry());
            dist = 9999.0f;
            break;
    }

    if (pWho->GetDistance2d(pWho->GetHomePosition()) > dist)
    {
        if (entry == NPC_BLAUMEUX || entry == NPC_MOGRAINE || entry == NPC_ZELIEK || entry == NPC_THANE)
        {
            if (Creature* pC = GetSingleCreatureFromStorage(NPC_BLAUMEUX))
                if (pC->IsAlive()) pC->AI()->EnterEvadeMode();
            if (Creature* pC = GetSingleCreatureFromStorage(NPC_MOGRAINE))
                if (pC->IsAlive()) pC->AI()->EnterEvadeMode();
            if (Creature* pC = GetSingleCreatureFromStorage(NPC_ZELIEK))
                if (pC->IsAlive()) pC->AI()->EnterEvadeMode();
            if (Creature* pC = GetSingleCreatureFromStorage(NPC_THANE))
                if (pC->IsAlive()) pC->AI()->EnterEvadeMode();
        }
        else
        {
            pWho->AI()->EnterEvadeMode();
        }
        return false;
    }
    return true;
}

void instance_naxxramas::OnCreatureEnterCombat(Creature * creature)
{
    if (creature->GetEntry() == NPC_SewageSlime)
    {
        std::list<Creature*> sewageSlimes;
        GetCreatureListWithEntryInGrid(sewageSlimes, creature, NPC_SewageSlime, 100.0f);
        for (Creature* pC : sewageSlimes)
        {
            if (!pC->IsInCombat())
            {
                pC->CastSpell(pC, 28033, true); // aggro all in los
            }
        }
    }
}

bool instance_naxxramas::WingsAreCleared()
{
    // All bosses must be dead, not just the end bosses. Some bosses aren't gated
    // so we just check them all
    for (int i = 0; i < TYPE_SAPPHIRON; ++i)
    {
        if (GetData(i) != DONE)
            return false;
    }

    return true;
}

void instance_naxxramas::UpdateAutomaticBossEntranceDoor(NaxxGOs which, uint32 uiData, int requiredPreBossData)
{
    if (requiredPreBossData > -1 && requiredPreBossData != DONE)
        return;

    if (GameObject* pGo = GetSingleGameObjectFromStorage(which))
    {
        UpdateAutomaticBossEntranceDoor(pGo, uiData, requiredPreBossData);
    }
}

void instance_naxxramas::UpdateAutomaticBossEntranceDoor(GameObject* pGO, uint32 uiData, int requiredPreBossData)
{
    if (requiredPreBossData > -1 && requiredPreBossData != DONE)
        return;

    if (!pGO)
    {
        sLog.outError("instance_naxxramas::UpdateAutomaticBossEntranceDoor called with nullptr GO");
        return;
    }
    if (uiData == IN_PROGRESS || uiData == SPECIAL)
    {
        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        pGO->SetGoState(GO_STATE_READY);
    }
    else
    {
        //pGO->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        pGO->SetGoState(GO_STATE_ACTIVE);
    }
}

void instance_naxxramas::UpdateManualDoor(NaxxGOs which, uint32 uiData)
{
    if (GameObject* pGo = GetSingleGameObjectFromStorage(which))
    {
        UpdateManualDoor(pGo, uiData);
    }
}

void instance_naxxramas::UpdateManualDoor(GameObject * pGO, uint32 uiData)
{
    if (uiData == DONE)
        pGO->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
    else
        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
}

void instance_naxxramas::UpdateBossGate(NaxxGOs which, uint32 uiData)
{
    if (GameObject* pGo = GetSingleGameObjectFromStorage(which))
    {
        UpdateBossGate(pGo, uiData);
    }
}

void instance_naxxramas::UpdateBossGate(GameObject* pGO, uint32 uiData)
{
    if (!pGO)
    {
        sLog.outError("instance_naxxramas::UpdateBossGate called with nullptr GO");
        return;
    }
    if (uiData == DONE)
        pGO->SetGoState(GO_STATE_ACTIVE);
    else
        pGO->SetGoState(GO_STATE_READY);
}

void instance_naxxramas::UpdateTeleporters(uint32 uiType, uint32 uiData)
{
    // todo: what was the reason behind these? Should they despawn after 30 minutes?
    // DoRespawnGameObject(GO_<WING>_PORTAL, 30 * MINUTE);
    switch (uiType)
    {
        case TYPE_MAEXXNA:
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_ARAC_EYE_BOSS))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_ARAC_EYE_RAMP))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_ARAC_PORTAL))
                SetTeleporterState(pGO, uiData);
            break;
        case TYPE_THADDIUS:
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_CONS_EYE_BOSS))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_CONS_EYE_RAMP))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_CONS_PORTAL))
                SetTeleporterState(pGO, uiData);
            break;
        case TYPE_LOATHEB:
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_PLAG_EYE_BOSS))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_PLAG_EYE_RAMP))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_PLAG_PORTAL))
                SetTeleporterState(pGO, uiData);
            break;
        case TYPE_FOUR_HORSEMEN:
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_MILI_EYE_BOSS))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_MILI_EYE_RAMP))
                SetTeleporterVisualState(pGO, uiData);
        
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_MILI_PORTAL))
                SetTeleporterState(pGO, uiData);
            break;
        default:
            sLog.outError("instance_naxxramas::UpdateTeleporters called with unsupported type %d", uiType);
    }

    if (WingsAreCleared())
    {
        if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_HUB_PORTAL))
        {
            pGO->SetGoState(GO_STATE_ACTIVE);
        }
    }
    else
    {
        if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_HUB_PORTAL))
        {
            pGO->SetGoState(GO_STATE_READY);
        }
    }
}

void instance_naxxramas::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_ANUB_REKHAN:
        case NPC_FAERLINA:
        case NPC_MAEXXNA:
        case NPC_PATCHWERK:
        case NPC_GROBBULUS:
        case NPC_GLUTH:
        case NPC_THADDIUS:
        //case NPC_STALAGG:
        //case NPC_FEUGEN:
        case NPC_NOTH:
        case NPC_HEIGAN:
        case NPC_LOATHEB:
        case NPC_RAZUVIOUS:
        case NPC_GOTHIK:
        case NPC_ZELIEK:
        case NPC_THANE:
        case NPC_BLAUMEUX:
        case NPC_MOGRAINE:
        case NPC_SAPPHIRON:
        case NPC_KELTHUZAD:
        case NPC_MR_BIGGLESWORTH:
            m_mNpcEntryGuidStore[pCreature->GetEntry()] = pCreature->GetObjectGuid();
            break;

        case NPC_SUB_BOSS_TRIGGER:
            if (m_auiEncounter[TYPE_GOTHIK] != IN_PROGRESS)
                m_lGothTriggerList.push_back(pCreature->GetGUID());
            break;
        case NPC_ArchmageTarsis:
            pCreature->SetStandState(UNIT_STAND_STATE_DEAD);
            break;
        case NPC_SewageSlime:
            pCreature->SetWanderDistance(30.0f);
            break;
        case NPC_BileSludge:
        {
            // hack to prevent the endless amounts of adds to spawn in case something bugs out
            std::list<Creature*> clist;
            GetCreatureListWithEntryInGrid(clist, pCreature, NPC_BileSludge, 50.0f);
            if (clist.size() > 20)
            {
                pCreature->ForcedDespawn();
            }
        }
    }
    // 4hm
    if (pCreature->GetEntry() >= 16062 && pCreature->GetEntry() <= 16065)
    {
        if (m_auiEncounter[TYPE_FOUR_HORSEMEN] != DONE && pCreature->IsDead())
        {
            pCreature->Respawn();
        }
    }

    OnCreatureRespawn(pCreature);
}

void instance_naxxramas::OnObjectCreate(GameObject* pGo)
{
    switch (pGo->GetEntry())
    {
        case GO_ARAC_ANUB_DOOR:
        case GO_ARAC_ANUB_GATE:
        case GO_ARAC_FAER_WEB:
        case GO_ARAC_FAER_DOOR:
        case GO_ARAC_MAEX_INNER_DOOR:
        case GO_ARAC_MAEX_OUTER_DOOR:
        case GO_PLAG_SLIME01_DOOR:
        case GO_PLAG_SLIME02_DOOR:
        case GO_PLAG_NOTH_ENTRY_DOOR:
        case GO_PLAG_NOTH_EXIT_DOOR:
        case GO_PLAG_HEIG_ENTRY_DOOR:
        case GO_PLAG_HEIG_EXIT_DOOR:
        case GO_PLAG_HEIG_OLD_EXIT_DOOR:
        case GO_PLAG_LOAT_DOOR:
        case GO_MILI_GOTH_ENTRY_GATE:
        case GO_MILI_GOTH_EXIT_GATE:
        case GO_MILI_GOTH_COMBAT_GATE:
        case GO_MILI_HORSEMEN_DOOR:
        case GO_CHEST_HORSEMEN_NORM:
        case GO_CONS_PATH_EXIT_DOOR:
        case GO_CONS_GLUT_EXIT_DOOR:
        case GO_CONS_THAD_DOOR:
        case GO_KELTHUZAD_WATERFALL_DOOR:
        case GO_KELTHUZAD_DOOR:
        case GO_ARAC_EYE_RAMP:
        case GO_PLAG_EYE_RAMP:
        case GO_MILI_EYE_RAMP:
        case GO_CONS_EYE_RAMP:
        case GO_ARAC_PORTAL:
        case GO_PLAG_PORTAL:
        case GO_MILI_PORTAL:
        case GO_CONS_PORTAL:
        case GO_ARAC_EYE_BOSS:
        case GO_PLAG_EYE_BOSS:
        case GO_MILI_EYE_BOSS:
        case GO_CONS_EYE_BOSS:
        case GO_KT_WINDOW_1:
        case GO_KT_WINDOW_2:
        case GO_KT_WINDOW_3:
        case GO_KT_WINDOW_4:
        case GO_CONS_NOX_TESLA_FEUGEN:
        case GO_CONS_NOX_TESLA_STALAGG:
        case GO_HUB_PORTAL:
        case GO_SAPPHIRON_SPAWN:
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
    }

    if (pGo->GetEntry() == GO_CHEST_HORSEMEN_NORM)
        m_uiHorsemenChestGUID = pGo->GetGUID();

    if (pGo->GetGoType() == GAMEOBJECT_TYPE_TRAP)
    {
        uint32 uiGoEntry = pGo->GetEntry();

        if ((uiGoEntry >= 181517 && uiGoEntry <= 181524) || uiGoEntry == 181678)
            m_alHeiganTrapGuids[0].push_back(pGo->GetObjectGuid());
        else if ((uiGoEntry >= 181510 && uiGoEntry <= 181516) || (uiGoEntry >= 181525 && uiGoEntry <= 181531) || uiGoEntry == 181533 || uiGoEntry == 181676)
            m_alHeiganTrapGuids[1].push_back(pGo->GetObjectGuid());
        else if ((uiGoEntry >= 181534 && uiGoEntry <= 181544) || uiGoEntry == 181532 || uiGoEntry == 181677)
        {
            m_alHeiganTrapGuids[2].push_back(pGo->GetObjectGuid());
        }
        else if (uiGoEntry >= 181545 && uiGoEntry <= 181552)
        {
            if(pGo->GetDBTableGUIDLow() != 533119 && pGo->GetDBTableGUIDLow() != 533123) // duplicates
                m_alHeiganTrapGuids[3].push_back(pGo->GetObjectGuid());
        }
        switch (pGo->GetDBTableGUIDLow())
        {
            case 533181:
            case 533182:
            case 533183:
            case 533184:
            case 533187:
            case 533188:
            case 533189:
            case 533190:
            case 533191:
            case 533192:
            case 533193:
            case 533194:
            case 533195:
            case 533197:
            case 533199:
            case 533200:
                m_alHeiganTrapGuids[3].push_back(pGo->GetObjectGuid());
                break;
            case 533185:
            case 533196:
            case 533198:
                m_alHeiganTrapGuids[2].push_back(pGo->GetObjectGuid());
            ///case 533186:
        }
    }

    switch (pGo->GetEntry())
    {
        // Arac wing
        case GO_ARAC_ANUB_DOOR:
            // starts closed by default, but must make sure it can be interracted with
            pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT | GO_FLAG_IN_USE);
            break;
        case GO_ARAC_ANUB_GATE:
            UpdateManualDoor(pGo, m_auiEncounter[TYPE_ANUB_REKHAN]);
            if (m_auiEncounter[TYPE_ANUB_REKHAN] == DONE)
                pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            break;
        case GO_ARAC_FAER_WEB:
            pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_ARAC_FAER_DOOR:
            UpdateManualDoor(pGo, m_auiEncounter[TYPE_FAERLINA]);
            // todo: unable to get the door to be properly locked.
            // It has the locked flags, and it displays as locked ingame,
            // but with green text, aka it can be clicked and opened.
            // hackfix by setting no interract flag unless it should be openable.
            if (m_auiEncounter[TYPE_FAERLINA] == DONE)
                pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            else
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            break;
        case GO_ARAC_MAEX_OUTER_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_FAERLINA]);
            break;
        case GO_ARAC_MAEX_INNER_DOOR:
            pGo->SetGoState(GO_STATE_ACTIVE);
            break;

        // Plague wing
        case GO_PLAG_NOTH_ENTRY_DOOR:
            UpdateAutomaticBossEntranceDoor(pGo, m_auiEncounter[TYPE_NOTH]);
            break;
        case GO_PLAG_NOTH_EXIT_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_NOTH]);
            break;
        case GO_PLAG_HEIG_ENTRY_DOOR:
            UpdateAutomaticBossEntranceDoor(pGo, m_auiEncounter[TYPE_HEIGAN]);
            break;
        case GO_PLAG_HEIG_EXIT_DOOR:
        case GO_PLAG_HEIG_OLD_EXIT_DOOR:
        case GO_PLAG_LOAT_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_HEIGAN]);
            break;

        // Millitary wing
        case GO_MILI_GOTH_ENTRY_GATE:
            UpdateAutomaticBossEntranceDoor(pGo, m_auiEncounter[TYPE_RAZUVIOUS]);
            break;
        case GO_MILI_GOTH_EXIT_GATE:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_GOTHIK]);
            break;
        case GO_MILI_HORSEMEN_DOOR:
            UpdateManualDoor(pGo, m_auiEncounter[TYPE_GOTHIK]);
            break;
        case GO_MILI_GOTH_COMBAT_GATE:
            pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_CHEST_HORSEMEN_NORM:
            //todo: anything to be done?
            break;

        // Cons wing doors
        case GO_CONS_PATH_EXIT_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_PATCHWERK]);
            break;
        case GO_CONS_GLUT_EXIT_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_GLUTH]);
        case GO_CONS_THAD_DOOR:
            UpdateManualDoor(pGo, m_auiEncounter[TYPE_GLUTH]);
            break;

        // Frostwyrm lair
        case GO_KELTHUZAD_WATERFALL_DOOR:
        case GO_KELTHUZAD_DOOR:
            UpdateBossGate(pGo, m_auiEncounter[TYPE_SAPPHIRON]);
            break;

        // Teleporters visual thing
        case GO_ARAC_EYE_RAMP:
        case GO_ARAC_EYE_BOSS:
            SetTeleporterVisualState(pGo, m_auiEncounter[TYPE_MAEXXNA]);
            break;
        case GO_PLAG_EYE_RAMP:
        case GO_PLAG_EYE_BOSS:
            SetTeleporterVisualState(pGo, m_auiEncounter[TYPE_LOATHEB]);
            break;
        case GO_MILI_EYE_RAMP:
        case GO_MILI_EYE_BOSS:
            SetTeleporterVisualState(pGo, m_auiEncounter[TYPE_FOUR_HORSEMEN]);
            break;
        case GO_CONS_EYE_RAMP:
        case GO_CONS_EYE_BOSS:
            SetTeleporterVisualState(pGo, m_auiEncounter[TYPE_THADDIUS]);
            break;

        // Actual teleporters
        case GO_ARAC_PORTAL:
            SetTeleporterState(pGo, m_auiEncounter[TYPE_MAEXXNA]);
            break;
        case GO_PLAG_PORTAL:
            SetTeleporterState(pGo, m_auiEncounter[TYPE_LOATHEB]);
            break;
        case GO_MILI_PORTAL:
            SetTeleporterState(pGo, m_auiEncounter[TYPE_FOUR_HORSEMEN]);
            break;
        case GO_CONS_PORTAL:
            SetTeleporterState(pGo, m_auiEncounter[TYPE_THADDIUS]);
            break;

        case GO_KT_WINDOW_1:
        case GO_KT_WINDOW_2:
        case GO_KT_WINDOW_3:
        case GO_KT_WINDOW_4:
            if (m_auiEncounter[TYPE_KELTHUZAD] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            else
                pGo->SetGoState(GO_STATE_READY);
            break;

        case GO_CONS_NOX_TESLA_FEUGEN:
        case GO_CONS_NOX_TESLA_STALAGG:
            if (m_auiEncounter[TYPE_THADDIUS] == DONE)
                pGo->SetGoState(GO_STATE_READY);
            else
                pGo->SetGoState(GO_STATE_ACTIVE);
        case GO_SAPPHIRON_SPAWN:
            if(m_auiEncounter[TYPE_SAPPHIRON] == DONE)
                pGo->DeleteLater();
            break;
    }
}

void instance_naxxramas::OnCreatureRespawn(Creature * pCreature)
{
    bool forcedDespawn = false;
    switch (pCreature->GetEntry())
    {
        case NPC_ANUB_REKHAN:
            forcedDespawn = (GetData(TYPE_ANUB_REKHAN) == DONE);
            break;
        case NPC_FAERLINA:
            forcedDespawn = (GetData(TYPE_FAERLINA) == DONE);
            break;
        case NPC_MAEXXNA:
            forcedDespawn = (GetData(TYPE_MAEXXNA) == DONE);
            break;
        case NPC_PATCHWERK:
            forcedDespawn = (GetData(TYPE_PATCHWERK) == DONE);
            break;
        case NPC_GROBBULUS:
            forcedDespawn = (GetData(TYPE_GROBBULUS) == DONE);
            break;
        case NPC_GLUTH:
            forcedDespawn = (GetData(TYPE_GLUTH) == DONE);
            break;
        case NPC_THADDIUS:
            forcedDespawn = (GetData(TYPE_THADDIUS) == DONE);
            break;
        case NPC_NOTH:
            forcedDespawn = (GetData(TYPE_NOTH) == DONE);
            break;
        case NPC_HEIGAN:
            forcedDespawn = (GetData(TYPE_HEIGAN) == DONE);
            break;
        case NPC_LOATHEB:
            forcedDespawn = (GetData(TYPE_LOATHEB) == DONE);
            break;
        case NPC_RAZUVIOUS:
            forcedDespawn = (GetData(TYPE_RAZUVIOUS) == DONE);
            break;
        case NPC_GOTHIK:
            forcedDespawn = (GetData(TYPE_GOTHIK) == DONE);
            break;
        case NPC_ZELIEK:
        case NPC_THANE:
        case NPC_BLAUMEUX:
        case NPC_MOGRAINE:
            forcedDespawn = (GetData(TYPE_FOUR_HORSEMEN) == DONE);
            break;
        case NPC_SAPPHIRON:
            forcedDespawn = (GetData(TYPE_SAPPHIRON) == DONE);
            break;
        case NPC_KELTHUZAD:
            forcedDespawn = (GetData(TYPE_KELTHUZAD) == DONE);
            break;
    }

    // Something, probably silly, makes gothik respawn, thus the trash
    // linked to him gets a chance to respawn as well. Force-despawning his
    // trash like this as well to prevent that. There should be no deathknight captains,
    // deathknight cavaliers or necro knights after gothik, so this works.
    // The hardcoded dbGUID is a lonely shade of naxxramas
    if (GetData(TYPE_GOTHIK) == DONE)
    {
        uint32 e = pCreature->GetEntry();
        if (e == NPC_UnholyAxe ||
            e == NPC_UnholyStaff ||
            e == NPC_UnholySwords ||
            e == NPC_NecroKnight ||
            e == NPC_DeathKnightCaptain ||
            e == NPC_DeathKnightCavalier ||
            pCreature->GetDBTableGUIDLow() == 88470)
        {
            forcedDespawn = true;
        }
    }

    if (forcedDespawn)
    {
        pCreature->AddObjectToRemoveList();
    }
}

bool instance_naxxramas::IsEncounterInProgress() const
{
    for (uint32 i : m_auiEncounter)
        if (i == IN_PROGRESS || i == SPECIAL)
            return true;

    return false;
}

void instance_naxxramas::SetData(uint32 uiType, uint32 uiData)
{
    ASSERT(this)

    bool sameStateAsLast = false;
    if (uiType < MAX_ENCOUNTER)
        sameStateAsLast = (m_auiEncounter[uiType] == uiData);

    switch (uiType)
    {
        case TYPE_ANUB_REKHAN:
            m_auiEncounter[uiType] = uiData;
            if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_ARAC_ANUB_DOOR))
            {
                if (uiData == IN_PROGRESS)
                    pGo->SetGoState(GO_STATE_READY);
                else
                    pGo->SetGoState(GO_STATE_ACTIVE);
            }
            UpdateManualDoor(GO_ARAC_ANUB_GATE, uiData);
            break;
        case TYPE_FAERLINA:
            m_auiEncounter[uiType] = uiData;
            UpdateAutomaticBossEntranceDoor(GO_ARAC_FAER_WEB, uiData);

            UpdateManualDoor(GO_ARAC_FAER_DOOR, uiData);
            UpdateBossGate(GO_ARAC_MAEX_OUTER_DOOR, uiData);
            // todo: unable to get the door to be properly locked.
            // It has the locked flags, and it displays as locked ingame,
            // but with green text, aka it can be clicked and opened.
            // hackfix by setting no interract flag unless it should be openable.

            if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_ARAC_FAER_DOOR))
            {
                if(uiData == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                else
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            }
            break;
        case TYPE_MAEXXNA:
            if (uiData == DONE)
                m_events.ScheduleEvent(EVENT_WINGBOSS_DEAD, 10000);
            m_auiEncounter[uiType] = uiData;
            UpdateAutomaticBossEntranceDoor(GO_ARAC_MAEX_INNER_DOOR, uiData, m_auiEncounter[TYPE_FAERLINA]);
            UpdateTeleporters(uiType, uiData);
            break;
        case TYPE_NOTH:
            m_auiEncounter[uiType] = uiData;
            UpdateAutomaticBossEntranceDoor(GO_PLAG_NOTH_ENTRY_DOOR, uiData);
            UpdateBossGate(GO_PLAG_NOTH_EXIT_DOOR, uiData);
            UpdateBossGate(GO_PLAG_HEIG_ENTRY_DOOR, uiData);
            break;
        case TYPE_HEIGAN:
            m_auiEncounter[uiType] = uiData;
            // entry door is controlled by boss script
            UpdateBossGate(GO_PLAG_LOAT_DOOR, uiData);
            UpdateBossGate(GO_PLAG_HEIG_OLD_EXIT_DOOR, uiData);
            break;
        case TYPE_LOATHEB:
            if (uiData == DONE)
                m_events.ScheduleEvent(EVENT_WINGBOSS_DEAD, 10000);
            m_auiEncounter[uiType] = uiData;
            UpdateAutomaticBossEntranceDoor(GO_PLAG_LOAT_DOOR, uiData, m_auiEncounter[TYPE_HEIGAN]);
            UpdateTeleporters(uiType, uiData);
            break;
        case TYPE_RAZUVIOUS:
            m_auiEncounter[uiType] = uiData;
            UpdateBossGate(GO_MILI_GOTH_ENTRY_GATE, uiData);
            break;
        case TYPE_GOTHIK:
            m_auiEncounter[uiType] = uiData;
            UpdateAutomaticBossEntranceDoor(GO_MILI_GOTH_ENTRY_GATE, uiData);
            UpdateBossGate(GO_MILI_GOTH_EXIT_GATE, uiData);
            if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_MILI_GOTH_COMBAT_GATE))
            {
                switch (uiData)
                {
                case IN_PROGRESS:
                    pGO->SetGoState(GO_STATE_READY);
                    break;
                case SPECIAL:
                    pGO->SetGoState(GO_STATE_ACTIVE);
                    break;
                case FAIL:
                    //if (m_auiEncounter[TYPE_GOTHIK] == IN_PROGRESS)
                    pGO->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DONE:
                    pGO->SetGoState(GO_STATE_ACTIVE);
                    m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_1, Seconds(10)); // todo: don't know if it should trigger here or when opening 4hm door
                    break;
                }
            }
            UpdateManualDoor(GO_MILI_HORSEMEN_DOOR, uiData);
            break;
        case TYPE_FOUR_HORSEMEN:
            if(uiData == DONE)
                m_events.ScheduleEvent(EVENT_WINGBOSS_DEAD, 10000);
            m_auiEncounter[uiType] = uiData;

            UpdateAutomaticBossEntranceDoor(GO_MILI_HORSEMEN_DOOR, uiData, m_auiEncounter[TYPE_GOTHIK]);
            UpdateTeleporters(uiType, uiData);
            if (uiData == SPECIAL)
            {
                ++m_horsemenDeathCounter;
                if (m_horsemenDeathCounter >= 4)
                {
                    SetData(TYPE_FOUR_HORSEMEN, DONE);
                }
            }
            else if(uiData == FAIL)
            {
                m_horsemenDeathCounter = 0;
                for (uint32 i = NPC_MOGRAINE; i <= NPC_BLAUMEUX; i++)
                {
                    if (Creature* p = GetSingleCreatureFromStorage(i))
                        if (p->IsDead())
                            p->Respawn();
                }
            }
            else if (uiData == DONE)
            {
                // spawns it for 30 minutes?
                DoRespawnGameObject(m_uiHorsemenChestGUID);
                std::list<Creature*> spirits;
                GetCreatureListWithEntryInGrid(spirits, GetSingleCreatureFromStorage(NPC_ZELIEK), { 16775, 16776, 16777, 16778}, 300.0f);
                for (Creature* pC : spirits)
                    pC->DeleteLater();

                // reputation
                FactionEntry const *factionEntry = sObjectMgr.GetFactionEntry(529); // Argent Dawn
                if (factionEntry)
                {
                    Map::PlayerList const &liste = GetMap()->GetPlayers();
                    for (const auto& i : liste)
                    {
                        if (Player* pPlayer = i.getSource())
                        {
                            pPlayer->GetReputationMgr().ModifyReputation(factionEntry, 100);
                        }
                    }
                }
                else
                {
                    sLog.outError("4hm just died. Unable to find Argent Dawn faction for reputation ");
                }
            }
            break;
        case TYPE_PATCHWERK:
            m_auiEncounter[uiType] = uiData;
            UpdateBossGate(GO_CONS_PATH_EXIT_DOOR, uiData);
            break;
        case TYPE_GROBBULUS:
            UpdateAutomaticBossEntranceDoor(GO_CONS_PATH_EXIT_DOOR, uiData, m_auiEncounter[TYPE_PATCHWERK]);
            m_auiEncounter[uiType] = uiData;
            break;
        case TYPE_GLUTH:
            m_auiEncounter[uiType] = uiData;
            UpdateBossGate(GO_CONS_GLUT_EXIT_DOOR, uiData);
            UpdateManualDoor(GO_CONS_THAD_DOOR, uiData);
            break;
        case TYPE_THADDIUS:
            // Only set the same state once
            if (uiData == m_auiEncounter[uiType])
                break;

            if (uiData == DONE)
                m_events.ScheduleEvent(EVENT_WINGBOSS_DEAD, 10000);
            m_auiEncounter[uiType] = uiData;

            UpdateAutomaticBossEntranceDoor(GO_CONS_THAD_DOOR, uiData, m_auiEncounter[TYPE_GLUTH]);

            UpdateTeleporters(uiType, uiData);
            break;
        case TYPE_SAPPHIRON:
            if(uiData == DONE)
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_1, 12000);

            m_auiEncounter[uiType] = uiData;
            UpdateBossGate(GO_KELTHUZAD_WATERFALL_DOOR, uiData);
            // GO_KELTHUZAD_DOOR is opened at the end of EVENT_KT_LK_DIALOGUE
            break;
        case TYPE_KELTHUZAD:
            UpdateAutomaticBossEntranceDoor(GO_KELTHUZAD_DOOR, uiData, m_auiEncounter[TYPE_SAPPHIRON]);
            switch (uiData)
            {
                case SPECIAL:
                {
                    Map::PlayerList const& lPlayers = instance->GetPlayers();

                    if (lPlayers.isEmpty())
                        return;

                    bool bCanBegin = true;

                    for (const auto& itr : lPlayers)
                    {
                        if (Player* pPlayer = itr.getSource())
                        {
                            if (!pPlayer->IsWithinDist2d(m_fChamberCenterX, m_fChamberCenterY, 15.0f))
                                bCanBegin = false;
                        }
                    }

                    if (bCanBegin)
                        m_auiEncounter[uiType] = IN_PROGRESS;

                    break;
                }
                case FAIL:
                    m_auiEncounter[uiType] = NOT_STARTED;
                    break;
                default:
                    m_auiEncounter[uiType] = uiData;
                    break;
            }
            break;
    }

    if (uiData == FAIL && !sameStateAsLast)
    {
        uint32 entry = 0;
        switch (uiType)
        {
            case TYPE_ANUB_REKHAN:
                entry = NPC_ANUB_REKHAN;
            break;
            case TYPE_FAERLINA:
                entry = NPC_FAERLINA;
            break;
            case TYPE_MAEXXNA:
                entry = NPC_MAEXXNA;
            break;
            case TYPE_NOTH:
                entry = NPC_NOTH;
            break;
            case TYPE_HEIGAN:
                entry = NPC_HEIGAN;
            break;
            case TYPE_LOATHEB:
                entry = NPC_LOATHEB;
            break;
            case TYPE_RAZUVIOUS:
                entry = NPC_RAZUVIOUS;
            break;
            case TYPE_GOTHIK:
                entry = NPC_GOTHIK;
            break;
            case TYPE_FOUR_HORSEMEN:
            {
                entry = NPC_ZELIEK;
            }
            break;
            case TYPE_PATCHWERK:
                entry = NPC_PATCHWERK;
            break;
            case TYPE_GROBBULUS:
                entry = NPC_GROBBULUS;
            break;
            case TYPE_GLUTH:
                entry = NPC_GLUTH;
            break;
            case TYPE_THADDIUS:
                entry = NPC_THADDIUS;
            break;
            case TYPE_SAPPHIRON:
                entry = NPC_SAPPHIRON;
            break;
            case TYPE_KELTHUZAD:
                entry = NPC_KELTHUZAD;
            break;
        }

        if (entry)
        {
            if (Creature* pCreature = GetSingleCreatureFromStorage(entry))
            {
                // Crude check to to avoid silly data clogging up our statistics
                // We only update the wipe counter if the boss has been in combat for at least 10 seconds
                if (pCreature->GetCombatTime(false) > 10)
                {
                    sInstanceStatistics.IncrementWipeCounter(533, entry);
                    if (entry == NPC_ZELIEK)
                    {
                        // special case handling for these 4hm buggers
                        sInstanceStatistics.IncrementWipeCounter(533, NPC_MOGRAINE);
                        sInstanceStatistics.IncrementWipeCounter(533, NPC_BLAUMEUX);
                        sInstanceStatistics.IncrementWipeCounter(533, NPC_THANE);
                    }
                }
            }
        }
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        for (uint32 i : m_auiEncounter)
            saveStream << i << " ";

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_naxxramas::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    for (uint32 & i : m_auiEncounter)
    {
        loadStream >> i;
        if (i == IN_PROGRESS)
            i = NOT_STARTED;
    }
    if (m_auiEncounter[TYPE_THADDIUS] == SPECIAL)
        m_auiEncounter[TYPE_THADDIUS] = FAIL;

    //todo: at least 4hm might need to be changed from SPECIAL to FAIL/NOT_STARTED as well
    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_naxxramas::GetData(uint32 uiType)
{
    if (uiType < MAX_ENCOUNTER)
        return m_auiEncounter[uiType];

    sLog.outError("instance_naxxramas::GetData() called with %d as param. %d is MAX_ENCOUNTERS", uiType, MAX_ENCOUNTER);
    return 0;
}

uint64 instance_naxxramas::GetData64(uint32 uiData)
{
    sLog.outBasic("instance_naxxramas::GetData64 called. Not implemented");
    return 0;
}

uint64 instance_naxxramas::GetGOUuid(NaxxGOs which)
{
    auto it = m_mNpcEntryGuidStore.find(which);
    if (it == m_mNpcEntryGuidStore.end())
    {
        sLog.outError("instance_naxxramas::GetGOUuid called with param %d, not found", which);
        return 0;
    }
    return it->second;
}

void instance_naxxramas::SetGothTriggers()
{
    Creature* pGoth = GetSingleCreatureFromStorage(NPC_GOTHIK);

    if (!pGoth)
        return;

    for (const auto& guid : m_lGothTriggerList)
    {
        if (Creature* pTrigger = instance->GetCreature(guid))
        {
            GothTrigger pGt;
            pGt.bIsAnchorHigh = (pTrigger->GetPositionZ() >= (pGoth->GetPositionZ() - 5.0f));
            pGt.bIsRightSide = IsInRightSideGothArea(pTrigger);

            m_mGothTriggerMap[pTrigger->GetGUID()] = pGt;
        }
    }
}

Creature* instance_naxxramas::GetClosestAnchorForGoth(Creature* pSource, bool bRightSide)
{
    std::list<Creature* > lList;

    for (const auto& itr : m_mGothTriggerMap)
    {
        if (!itr.second.bIsAnchorHigh)
            continue;

        if (itr.second.bIsRightSide != bRightSide)
            continue;

        if (Creature* pCreature = instance->GetCreature(itr.first))
            lList.push_back(pCreature);
    }

    if (!lList.empty())
    {
        lList.sort(ObjectDistanceOrder(pSource));
        return lList.front();
    }

    return nullptr;
}

void instance_naxxramas::GetGothSummonPointCreatures(std::list<Creature*> &lList, bool bRightSide)
{
    for (const auto& itr : m_mGothTriggerMap)
    {
        if (itr.second.bIsAnchorHigh)
            continue;

        if (itr.second.bIsRightSide != bRightSide)
            continue;

        if (Creature* pCreature = instance->GetCreature(itr.first))
            lList.push_back(pCreature);
    }
}

bool instance_naxxramas::IsInRightSideGothArea(Unit const* pUnit)
{
    if (GameObject* pCombatGate = GetSingleGameObjectFromStorage(GO_MILI_GOTH_COMBAT_GATE))
        return (pCombatGate->GetPositionY() >= pUnit->GetPositionY());

    sLog.outError("left/right side check, Gothik combat area failed.");
    return true;
}

void instance_naxxramas::SetChamberCenterCoords(float fX, float fY, float fZ)
{
    m_fChamberCenterX = fX;
    m_fChamberCenterY = fY;
    m_fChamberCenterZ = fZ;
}

void instance_naxxramas::ToggleKelThuzadWindows(bool setOpen)
{
    for (int i = GO_KT_WINDOW_1; i <= GO_KT_WINDOW_4; i++)
    {
        if (GameObject* pGo = GetSingleGameObjectFromStorage(i))
            pGo->SetGoState(setOpen ? GO_STATE_ACTIVE : GO_STATE_READY);
    }
}

void instance_naxxramas::OnPlayerDeath(Player* p)
{
    if (m_auiEncounter[TYPE_ANUB_REKHAN] == IN_PROGRESS)
    {
        // On player death we spawn 5 scarabs under the player. Since the player
        // can die from falldmg or other sources, anubs script impl of KilledUnit may not
        // be called, thus we need to do it here.
        if (Creature* pAnub = GetSingleCreatureFromStorage(NPC_ANUB_REKHAN))
        {
            //pAnub->AI()->DoCast(p, 29105, true);
            pAnub->SendSpellGo(p, 28864);
            for (int i = 0; i < 5; i++)
            {
                if (Creature* cs = pAnub->SummonCreature(16698, p->GetPositionX(), p->GetPositionY(), p->GetPositionZ(), 0,
                    TEMPSUMMON_CORPSE_DESPAWN))
                {
                    cs->SetInCombatWithZone();
                    if (Unit* csTarget = pAnub->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        cs->AI()->AttackStart(csTarget);
                        cs->AddThreat(csTarget, 5000);
                    }
                }
            }
        }
    }
}

void instance_naxxramas::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_MR_BIGGLESWORTH:
        {
            if(GetData(TYPE_KELTHUZAD) != DONE)
            {
                m_events.ScheduleEvent(EVENT_BIGGLESWORTH_DIED_YELL, 1000);
                sInstanceStatistics.IncrementCustomCounter(MR_BIGGLESWORTH_KILLS, true);
            }
            break;
        }
        case NPC_FrenziedBat:
        case NPC_PlaguedBat:
        case NPC_MutatedGrub:
        case NPC_PlagueBeast:
            pCreature->ForcedDespawn(10000);
            break;
        case NPC_EmbalmingSlime:
            pCreature->ForcedDespawn(30000);
            break;
        case NPC_LightningTotem:
            pCreature->DeleteLater();
            break;
    }
}

void instance_naxxramas::Update(uint32 diff)
{
    m_events.Update(diff);
    while (auto l_EventId = m_events.ExecuteEvent())
    {
        switch (l_EventId)
        {
            case EVENT_BIGGLESWORTH_DIED_YELL:
                DoOrSimulateScriptTextForThisInstance(KELTHUZAD_SAY_CAT_DIED, NPC_KELTHUZAD);
                break;
            case EVENT_THADDIUS_SCREAM:
                if (m_auiEncounter[TYPE_THADDIUS] != DONE)
                {
                    if (m_auiEncounter[TYPE_THADDIUS] != IN_PROGRESS && m_auiEncounter[TYPE_THADDIUS] != SPECIAL)
                        DoOrSimulateScriptTextForThisInstance(THADDIUS_SAY_SCREAM1 + urand(0, 3), NPC_THADDIUS);
                    m_events.ScheduleEvent(EVENT_THADDIUS_SCREAM, Minutes(urand(5,10)));
                }
                break;
            case EVENT_WINGBOSS_DEAD:
                DoOrSimulateScriptTextForThisInstance(KELTHUZAD_SAY_TAUNT1 + GetNumEndbossDead()-1, NPC_KELTHUZAD);
                break;
            case EVENT_KT_LK_DIALOGUE_1:
                DoOrSimulateScriptTextForThisInstance(SAY_SAPP_DIALOG1, NPC_KELTHUZAD);
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_2, Seconds(5));
                break;
            case EVENT_KT_LK_DIALOGUE_2:
                DoOrSimulateScriptTextForThisInstance(SAY_SAPP_DIALOG2_LICH, NPC_LICH_KING);
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_3, 16500);
                break;
            case EVENT_KT_LK_DIALOGUE_3:
                DoOrSimulateScriptTextForThisInstance(SAY_SAPP_DIALOG3, NPC_KELTHUZAD);
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_4, Seconds(6));
                break;
            case EVENT_KT_LK_DIALOGUE_4:
                DoOrSimulateScriptTextForThisInstance(SAY_SAPP_DIALOG4_LICH, NPC_LICH_KING);
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_5, Seconds(8));
                break;
            case EVENT_KT_LK_DIALOGUE_5:
                DoOrSimulateScriptTextForThisInstance(SAY_SAPP_DIALOG5, NPC_KELTHUZAD);
                m_events.ScheduleEvent(EVENT_KT_LK_DIALOGUE_GATE_OPEN, 5500);
                break;
            case EVENT_KT_LK_DIALOGUE_GATE_OPEN:
                UpdateBossGate(GO_KELTHUZAD_DOOR, DONE);
                break;
            case EVENT_SUMMON_FROGGER_WAVE:
            {
                static constexpr float pos[6][4] = {
                {3128.66f, -3121.27f, 293.341f, 4.73893f},
                {3154.58f, -3126.18f, 293.591f, 4.43020f},
                {3175.28f, -3134.76f, 293.437f, 4.24492f},
                {3129.630f, -3157.652f, 293.32f, 4.73893f},
                {3144.894f, -3159.587f, 293.32f, 4.43020f},
                {3159.510f, -3166.001f, 293.27f, 4.24492f} };

                for (int i = 0; i < 3; i++)
                {
                    if (Creature* frogger = instance->SummonCreature(NPC_LivingPoison, pos[i][0], pos[i][1], pos[i][2], pos[i][3], TEMPSUMMON_TIMED_DESPAWN, 13000))
                    {
                        frogger->GetMotionMaster()->MovePoint(0, pos[i+3][0], pos[i + 3][1], pos[i + 3][2], pos[i + 3][3]);
                    }
                }
                m_events.Repeat(Seconds(6));
                break;
            }
            case EVENT_4HM_DIALOGUE_1:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_1, NPC_ZELIEK, GetMap(), GetSingleCreatureFromStorage(NPC_ZELIEK));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_2, Seconds(7));
                break;
            case EVENT_4HM_DIALOGUE_2:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_2, NPC_BLAUMEUX, GetMap(), GetSingleCreatureFromStorage(NPC_BLAUMEUX));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_3, Seconds(7));
                break;
            case EVENT_4HM_DIALOGUE_3:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_3, NPC_MOGRAINE, GetMap(), GetSingleCreatureFromStorage(NPC_MOGRAINE));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_4, Seconds(7));
                break;
            case EVENT_4HM_DIALOGUE_4:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_4, NPC_BLAUMEUX, GetMap(), GetSingleCreatureFromStorage(NPC_BLAUMEUX));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_5, Seconds(7));
                break;
            case EVENT_4HM_DIALOGUE_5:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_5, NPC_ZELIEK, GetMap(), GetSingleCreatureFromStorage(NPC_ZELIEK));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_6, Seconds(6));
                break;
            case EVENT_4HM_DIALOGUE_6:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_6, NPC_THANE, GetMap(), GetSingleCreatureFromStorage(NPC_THANE));
                m_events.ScheduleEvent(EVENT_4HM_DIALOGUE_7, Seconds(7));
                break;
            case EVENT_4HM_DIALOGUE_7:
                DoOrSimulateScriptTextForMap(SAY_4HM_DIALOGUE_7, NPC_MOGRAINE, GetMap(), GetSingleCreatureFromStorage(NPC_MOGRAINE));
                break;
            case EVENT_DKWING_INTRO_2:
                DoOrSimulateScriptTextForMap(SAY_ZELI_TAUNT3, NPC_ZELIEK, GetMap(), GetSingleCreatureFromStorage(NPC_ZELIEK));
                m_events.ScheduleEvent(EVENT_DKWING_INTRO_3, 5000);
                break;
            case EVENT_DKWING_INTRO_3:
                DoOrSimulateScriptTextForMap(SAY_MOG_TAUNT3, NPC_MOGRAINE, GetMap(), GetSingleCreatureFromStorage(NPC_MOGRAINE));
                m_events.ScheduleEvent(EVENT_DKWING_INTRO_4, 6200);
                break;
            case EVENT_DKWING_INTRO_4:
                DoOrSimulateScriptTextForMap(SAY_BLAU_TAUNT3, NPC_BLAUMEUX, GetMap(), GetSingleCreatureFromStorage(NPC_BLAUMEUX));
                break;
        }
    }
}

InstanceData* GetInstanceData_instance_naxxramas(Map* pMap)
{
    return new instance_naxxramas(pMap);
}

void instance_naxxramas::onNaxxramasAreaTrigger(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    switch (pAt->id)
    {
        case AREATRIGGER_HUB_TO_FROSTWYRM:
            if (WingsAreCleared())
            {
                pPlayer->TeleportTo(toFrostwyrmTPPos);
            }
            break;
        case AREATRIGGER_KELTHUZAD:
            OnKTAreaTrigger(pAt);
            break;
        case AREATRIGGER_FAERLINA:
            if (!m_faerlinaHaveGreeted)
            {
                m_faerlinaHaveGreeted = true;
                if (Creature* pFaerlina = GetSingleCreatureFromStorage(NPC_FAERLINA))
                {
                    if(pFaerlina->IsAlive())
                        DoScriptText(SAY_FAERLINA_GREET, pFaerlina);
                }
            }
            break;
        case AREATRIGGER_THADDIUS_ENTRANCE:
            if (!m_thaddiusHaveGreeted)
            {
                m_thaddiusHaveGreeted = true;
                if (Creature* pThaddius = GetSingleCreatureFromStorage(NPC_THADDIUS))
                {
                    if (pThaddius->IsAlive())
                        DoScriptText(SAY_THADDIUS_GREET, pThaddius);
                }
            }
            break;
        case AREATRIGGER_START_DK_WING:
            if (!m_haveDoneDKWingIntro)
            {
                m_haveDoneDKWingIntro = true;
                if (GetData(TYPE_FOUR_HORSEMEN) != DONE)
                {
                    DoOrSimulateScriptTextForMap(SAY_KORT_TAUNT1, NPC_THANE, GetMap(), GetSingleCreatureFromStorage(NPC_THANE));
                    m_events.ScheduleEvent(EVENT_DKWING_INTRO_2, 5500);
                }
            }
            break;
    }
}

bool AreaTrigger_at_naxxramas(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->IsGameMaster() || !pPlayer->IsAlive())
        return false;

    if (instance_naxxramas* pInstance = (instance_naxxramas*)pPlayer->GetInstanceData())
    {
        pInstance->onNaxxramasAreaTrigger(pPlayer, pAt);
    }
    return false;
}

struct mob_spiritOfNaxxramasAI : public ScriptedAI
{
    mob_spiritOfNaxxramasAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_creature->CastSpell(m_creature, 18950, true); // stealth detection
    }

    ObjectGuid portal;
    uint32 portalTimer;
    uint32 shadowboltVolleyTimer;

    void DespawnPortal()
    {
        if (!portal)
            return;

        if (Creature* pPortal = m_creature->GetMap()->GetCreature(portal))
        {
            static_cast<TemporarySummon*>(pPortal)->UnSummon();
        }
        portal = 0;
    }

    void Reset() override
    {
        portalTimer = 5000;
        shadowboltVolleyTimer = 6000;
        DespawnPortal();
    }

    void JustDied(Unit* pKiller) override
    {
        DespawnPortal();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (portalTimer)
        {
            if (portalTimer < diff)
            {
                // summon portal of shadows
                if (Creature* pCreature = m_creature->SummonCreature(16420, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0,
                    TEMPSUMMON_TIMED_DESPAWN, 60000))
                {
                    m_creature->SendSpellGo(m_creature, 28383); // since we're manually summoning, we also send the visual that we're not using
                    portal = pCreature->GetObjectGuid();
                    pCreature->CastSpell(pCreature, 28384, true); // pCreature casts portal of shadow spell on self
                    portalTimer = 0;
                }
            }
            else
                portalTimer -= diff;
        }

        // casting shadowbolt volley every 10 sec
        if (shadowboltVolleyTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, 28599) == CAST_OK)
            {
                shadowboltVolleyTimer = 10000;
            }
        }
        else
            shadowboltVolleyTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_naxxramasGarboyleAI : public ScriptedAI
{
    mob_naxxramasGarboyleAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        goStoneform();

        if (m_creature->GetDefaultMovementType() == IDLE_MOTION_TYPE && m_creature->GetEntry() == 16168)
            m_creature->CastSpell(m_creature, 18950, true); // stealth detection
    }

    void goStoneform()
    {
        if (m_creature->GetDefaultMovementType() == IDLE_MOTION_TYPE && m_creature->GetEntry() == 16168)
        {
            m_creature->CastSpell(m_creature, 29154, true);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    uint32 acidVolleyTimer;

    void Reset() override
    {
        acidVolleyTimer = 4000;
    }

    void JustReachedHome() override
    {
        goStoneform();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE))
        {
            if (pWho->GetTypeId() == TYPEID_PLAYER
                && !m_creature->IsInCombat()
                && m_creature->IsWithinDistInMap(pWho, 17.0f)
                && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH)
                && m_creature->IsWithinLOSInMap(pWho))
            {
                AttackStart(pWho);
            }
        }
        else
        {
            ScriptedAI::MoveInLineOfSight(pWho);
        }
    }

    void Aggro(Unit*) override
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE))
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetHealthPercent() < 30.0f && !m_creature->IsNonMeleeSpellCasted() && !m_creature->HasAura(28995))
        {
            if (DoCastSpellIfCan(m_creature, 28995) == CAST_OK)
            {
                m_creature->CastSpell(m_creature, 28995, true); // Stoneskin
                DoScriptText(10755, m_creature); // %s emits a strange noise.
            }
        }

        if (acidVolleyTimer < diff && !m_creature->IsNonMeleeSpellCasted())
        {
            // supposedly the first gargoyle in plague wing did not do the acid volley, so
            // hackfix here to skip him
            if (m_creature->GetDBTableGUIDLow() != 88095)
            {
                if (DoCastSpellIfCan(m_creature, 29325) == CAST_OK) // acid volley
                    acidVolleyTimer = 8000;
            }
        }
        else
            acidVolleyTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_naxxramasPlagueSlimeAI : public ScriptedAI
{
    mob_naxxramasPlagueSlimeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        prev_spell = 0;
    }

    uint32 colorChangeTimer;
    uint32 prev_spell;

    void ChangeColor()
    {
        uint32 spell = urand(28987, 28990);

        if(SpellEntry const* entry = sSpellMgr.GetSpellEntry(spell))
            m_creature->UpdateEntry(entry->EffectMiscValue[0]);

        if (prev_spell)
            m_creature->RemoveAurasDueToSpell(prev_spell);

        DoCastSpellIfCan(m_creature, spell, CF_TRIGGERED);
        m_creature->SetObjectScale(2.0f); // updateentry and the actual spells screws up the scale...
        prev_spell = spell;
    }

    void Reset() override
    {
        colorChangeTimer = 0;
        ChangeColor();
    }

    void Aggro(Unit*) override
    {
        m_creature->CallForHelp(10.0f);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (colorChangeTimer < diff)
        {
            colorChangeTimer = urand(9000, 12000); // todo: no idea if timer is correct
            ChangeColor();
        }
        else
            colorChangeTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_toxic_tunnelAI : public ScriptedAI
{
    mob_toxic_tunnelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 checktime;
    uint32 _evadeTimer;

    void Reset() override
    {
        checktime = 0;
        _evadeTimer = 0;
    }

    void AttackStart(Unit*) override { }
    void MoveInLineOfSight(Unit*) override { }

    void EnterCombat(Unit*) override
    {
        // Poison aura is hitting someone. Start a short timer to evade & drop combat
        if (!_evadeTimer)
            _evadeTimer = 5000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!!_evadeTimer)
        {
            if (_evadeTimer <= diff)
            {
                EnterEvadeMode();
                _evadeTimer = 0;
            }
            else
                _evadeTimer -= diff;
        }

        // creature_template_addons should make this aura permanent, but check anyway due
        // to some reports of it not recasting
        if (checktime <= diff)
        {
            checktime = 5000;
            if (!m_creature->HasAura(28370))
                m_creature->CastSpell(m_creature, 28370, true);
        }
        else
            checktime -= diff;
    }
};

struct mob_dark_touched_warriorAI : public ScriptedAI
{
    mob_dark_touched_warriorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    bool hasFled;

    void Reset() override
    {
        hasFled = false;
    }

    void FleeToHorse()
    {
        if (!m_creature->GetVictim() || m_creature->HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
            return;

        Creature* pNearest = nullptr;
        MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck u_check(*m_creature, 16067, true, 100.0f);
        MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(pNearest, u_check);

        Cell::VisitGridObjects(m_creature, searcher, 100.0f);
        if (pNearest)
        {
            m_creature->GetMotionMaster()->MoveSeekAssistance(pNearest->GetPositionX(), pNearest->GetPositionY(), pNearest->GetPositionZ());
            m_creature->SetTargetGuid(ObjectGuid());

            m_creature->UpdateSpeed(MOVE_RUN, false);
            m_creature->InterruptSpellsWithInterruptFlags(SPELL_INTERRUPT_FLAG_MOVEMENT);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!hasFled && m_creature->GetHealthPercent() < 50.0f)
        {
            hasFled = true;
            FleeToHorse();
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_spiritOfNaxxramas(Creature* pCreature)
{
    return new mob_spiritOfNaxxramasAI(pCreature);
}

CreatureAI* GetAI_mob_naxxramasGargoyle(Creature* pCreature)
{
    return new mob_naxxramasGarboyleAI(pCreature);
}

CreatureAI* GetAI_mob_plagueSlimeAI(Creature* pCreature)
{
    return new mob_naxxramasPlagueSlimeAI(pCreature);
}

CreatureAI* GetAI_toxic_tunnel(Creature* pCreature)
{
    return new mob_toxic_tunnelAI(pCreature);
}

CreatureAI* GetAI_dark_touched_warrior(Creature* pCreature)
{
    return new mob_dark_touched_warriorAI(pCreature);
}

bool GossipHello_npc_ArchmageTarsis(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->GetStandState() != UNIT_STAND_STATE_SIT)
        pCreature->SetStandState(UNIT_STAND_STATE_SIT);
    return false;
}

enum OmarionMisc
{
    QUEST_OMARIONS_HANDBOOK = 9233,

    BC_TAILOR_TEXT        = 12251, // I am a master tailor, Omarion.
    BC_BLACKSMITH_TEXT    = 12269, // I am a master blacksmith, Omarion.
    BC_LEATHERWORKER_TEXT = 12257, // I am a master leatherworker, Omarion.
    BC_NO_CRAFT_TEXT      = 12279, // Omarion, I am not a craftsman. Can you still help me?
    BC_CLOSE_NO_CRAFTER   = 12281, // Thank you, Omarion. You have taken a fatal blow for the team on this day.
    BC_CLOSE_CRAFTER      = 12270, // I need to go. Evil stirs. Die well, Omarion.

    GOSSIP_MENU_INTRO   = 8507,
    GOSSIP_MENU_CRAFTER = 8508,
    GOSSIP_MENU_NOCRAFT = 8516,

    GOSSIP_OPT_NOT_CRAFTSMAN   = 1,

    GOSSIP_SELECT_TAILOR  = GOSSIP_ACTION_INFO_DEF + 1,
    GOSSIP_SELECT_BS      = GOSSIP_ACTION_INFO_DEF + 2,
    GOSSIP_SELECT_LW      = GOSSIP_ACTION_INFO_DEF + 3,
    GOSSIP_SELECT_NOCRAFT = GOSSIP_ACTION_INFO_DEF + 4,

    GOSSIP_SELECT_CRAFT_BEGIN     = GOSSIP_ACTION_INFO_DEF + 10,

    GOSSIP_SELECT_GLACIAL_GLOVES  = GOSSIP_SELECT_CRAFT_BEGIN + 1,  // tailor honored
    GOSSIP_SELECT_GLACIAL_WRISTS  = GOSSIP_SELECT_CRAFT_BEGIN + 2,  // tailor honored
    GOSSIP_SELECT_GLACIAL_CHEST   = GOSSIP_SELECT_CRAFT_BEGIN + 3,  // tailor exalted
    GOSSIP_SELECT_GLACIAL_CLOAK   = GOSSIP_SELECT_CRAFT_BEGIN + 4,  // tailor exalted

    GOSSIP_SELECT_POLAR_GLOVES    = GOSSIP_SELECT_CRAFT_BEGIN + 5,  // LW honored
    GOSSIP_SELECT_POLAR_WRISTS    = GOSSIP_SELECT_CRAFT_BEGIN + 6, // LW honored
    GOSSIP_SELECT_POLAR_CHEST     = GOSSIP_SELECT_CRAFT_BEGIN + 7, // LW exalted

    GOSSIP_SELECT_ICYSCALE_GLOVES = GOSSIP_SELECT_CRAFT_BEGIN + 8, // LW honored
    GOSSIP_SELECT_ICYSCALE_WRISTS = GOSSIP_SELECT_CRAFT_BEGIN + 9, // LW honored
    GOSSIP_SELECT_ICYSCALE_CHEST  = GOSSIP_SELECT_CRAFT_BEGIN + 10, // LW exalted

    GOSSIP_SELECT_ICEBANE_GLOVES  = GOSSIP_SELECT_CRAFT_BEGIN + 11, // BS exalted
    GOSSIP_SELECT_ICEBANE_WRISTS  = GOSSIP_SELECT_CRAFT_BEGIN + 12, // BS exalted
    GOSSIP_SELECT_ICEBANE_CHEST   = GOSSIP_SELECT_CRAFT_BEGIN + 13, // BS exalted

    GOSSIP_CLOSE = 100
};

void LearnCraftIfCan(uint32 learnId, uint32 knowId, Player* pPlayer, ReputationRank minRank, uint32 currSkill)
{
    uint32 argentDawnRep = pPlayer->GetReputationRank(529);
    if (argentDawnRep < minRank)
        return;

    if (currSkill < 300)
        return;

    if (!pPlayer->HasSpell(knowId))
        pPlayer->CastSpell(pPlayer, learnId, false);
}

bool GossipSelect_npc_MasterCraftsmanOmarion(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    uint32 tailorSkill      = pPlayer->GetSkillValue(SKILL_TAILORING);
    uint32 blacksmithSkill  = pPlayer->GetSkillValue(SKILL_BLACKSMITHING);
    uint32 leatherworkSkill = pPlayer->GetSkillValue(SKILL_LEATHERWORKING);
    uint32 argentDawnRep    = pPlayer->GetReputationRank(529);

    ReputationRank BOOK_REQ_RANK   = REP_REVERED;
    ReputationRank CRACT1_REQ_RANK = REP_REVERED;
    ReputationRank CRAFT2_REQ_RANK = REP_EXALTED;

    if (uiAction == GOSSIP_CLOSE)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    // if rep < honored, spit on player and be done with it.
    if (argentDawnRep < BOOK_REQ_RANK)
    {
        DoScriptText(-1999913, pCreature, pPlayer); // spit on player
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    switch (uiAction)
    {
        case GOSSIP_SELECT_TAILOR:
            if (argentDawnRep >= CRACT1_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Glacial Gloves", GOSSIP_SELECT_TAILOR, GOSSIP_SELECT_GLACIAL_GLOVES);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Glacial Wrists", GOSSIP_SELECT_TAILOR, GOSSIP_SELECT_GLACIAL_WRISTS);
            }
            if (argentDawnRep >= CRAFT2_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Glacial Vest" , GOSSIP_SELECT_TAILOR, GOSSIP_SELECT_GLACIAL_CHEST);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Glacial Cloak", GOSSIP_SELECT_TAILOR, GOSSIP_SELECT_GLACIAL_CLOAK);
            }
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_CLOSE_CRAFTER, GOSSIP_SELECT_TAILOR, GOSSIP_CLOSE);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_CRAFTER, pCreature->GetGUID());
            return true;
        case GOSSIP_SELECT_BS:
            if (argentDawnRep >= CRACT1_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icebane Gauntlets", GOSSIP_SELECT_BS, GOSSIP_SELECT_ICEBANE_GLOVES);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icebane Bracers", GOSSIP_SELECT_BS, GOSSIP_SELECT_ICEBANE_WRISTS);
            }
            if (argentDawnRep >= CRAFT2_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icebane Breastplate", GOSSIP_SELECT_BS, GOSSIP_SELECT_ICEBANE_CHEST);
            }
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_CLOSE_CRAFTER, GOSSIP_SELECT_BS, GOSSIP_CLOSE);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_CRAFTER, pCreature->GetGUID());
            return true;
        case GOSSIP_SELECT_LW:
            if (argentDawnRep >= CRACT1_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Polar Gloves", GOSSIP_SELECT_LW, GOSSIP_SELECT_POLAR_GLOVES);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icy Scale Gauntlets", GOSSIP_SELECT_LW, GOSSIP_SELECT_ICYSCALE_GLOVES);
        
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Polar Bracers", GOSSIP_SELECT_LW, GOSSIP_SELECT_POLAR_WRISTS);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icy Scale Bracers", GOSSIP_SELECT_LW, GOSSIP_SELECT_ICYSCALE_WRISTS);
            }
            if (argentDawnRep >= CRAFT2_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Polar Tunic", GOSSIP_SELECT_LW, GOSSIP_SELECT_POLAR_CHEST);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Icy Scale Breastplate", GOSSIP_SELECT_LW, GOSSIP_SELECT_ICYSCALE_CHEST);
            }
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_CLOSE_CRAFTER, GOSSIP_SELECT_LW, GOSSIP_CLOSE);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_CRAFTER, pCreature->GetGUID());
            return true;
        case GOSSIP_SELECT_NOCRAFT:
        {
            if (argentDawnRep >= BOOK_REQ_RANK)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_CLOSE_NO_CRAFTER, GOSSIP_SENDER_MAIN, GOSSIP_CLOSE);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_NOCRAFT, pCreature->GetGUID());
                if (!pPlayer->HasItemCount(22719, 1, true))
                {
                    pPlayer->AddItem(22719);
                }
            }
            return true;
        }

        /***************************
        *       Craft spells
        ****************************/

        case GOSSIP_SELECT_GLACIAL_GLOVES:
        {
            LearnCraftIfCan(28212, 28205, pPlayer, CRACT1_REQ_RANK, tailorSkill);
            break;
        }
        case GOSSIP_SELECT_GLACIAL_WRISTS:
        {
            LearnCraftIfCan(28215, 28209, pPlayer, CRACT1_REQ_RANK, tailorSkill);
            break;
        }
        case GOSSIP_SELECT_GLACIAL_CHEST:
        {
            // spell castbar bug, displays as "glacial gloves"
            LearnCraftIfCan(28213, 28207, pPlayer, CRAFT2_REQ_RANK, tailorSkill);
            break;
        }
        case GOSSIP_SELECT_GLACIAL_CLOAK:
        {
            LearnCraftIfCan(28214, 28208, pPlayer, CRAFT2_REQ_RANK, tailorSkill);
            break;
        }
        case GOSSIP_SELECT_POLAR_GLOVES:
        {
            LearnCraftIfCan(28229, 28220, pPlayer, CRACT1_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_POLAR_WRISTS:
        {
            LearnCraftIfCan(28230, 28221, pPlayer, CRACT1_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_POLAR_CHEST:
        {
            LearnCraftIfCan(28228, 28219, pPlayer, CRAFT2_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_ICYSCALE_GLOVES:
        {
            LearnCraftIfCan(28232, 28223, pPlayer, CRACT1_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_ICYSCALE_WRISTS:
        {
            LearnCraftIfCan(28233, 28224, pPlayer, CRACT1_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_ICYSCALE_CHEST:
        {
            LearnCraftIfCan(28231, 28222, pPlayer, CRAFT2_REQ_RANK, leatherworkSkill);
            break;
        }
        case GOSSIP_SELECT_ICEBANE_GLOVES:
        {
            LearnCraftIfCan(28248, 28243, pPlayer, CRACT1_REQ_RANK, blacksmithSkill);
            break;
        }
        case GOSSIP_SELECT_ICEBANE_WRISTS:
        {
            LearnCraftIfCan(28249, 28244, pPlayer, CRACT1_REQ_RANK, blacksmithSkill);
            break;
        }
        case GOSSIP_SELECT_ICEBANE_CHEST:
        {
            LearnCraftIfCan(28245, 28242,  pPlayer, CRAFT2_REQ_RANK, blacksmithSkill);
            break;
        }
    }

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_CLOSE_CRAFTER, uiSender, GOSSIP_CLOSE);
    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_CRAFTER, pCreature->GetGUID());
    return true;
}

bool GossipHello_npc_MasterCraftsmanOmarion(Player* pPlayer, Creature* pCreature)
{
    uint32 tailorSkill      = pPlayer->GetSkillValue(SKILL_TAILORING);
    uint32 blacksmithSkill  = pPlayer->GetSkillValue(SKILL_BLACKSMITHING);
    uint32 leatherworkSkill = pPlayer->GetSkillValue(SKILL_LEATHERWORKING);

    if(tailorSkill >= 225)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_TAILOR_TEXT, GOSSIP_SELECT_TAILOR, GOSSIP_SELECT_TAILOR);

    if(blacksmithSkill >= 225)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_BLACKSMITH_TEXT, GOSSIP_SELECT_BS, GOSSIP_SELECT_BS);

    if(leatherworkSkill >= 225)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_LEATHERWORKER_TEXT, GOSSIP_SELECT_LW, GOSSIP_SELECT_LW);

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, BC_NO_CRAFT_TEXT, GOSSIP_SENDER_MAIN, GOSSIP_SELECT_NOCRAFT);

    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_INTRO, pCreature->GetGUID());
    pCreature->HandleEmote(EMOTE_ONESHOT_LAUGH);
    return true;

    /*
    send GOSSIP_INTRO

    if player has 300/300 blacksmithing/leatherworking/taloring
        add option "I am master <profession>, Omarion."
        when clicked
            if <300 in your crafting skill OR less than Honored with AD
                /spits on you
            else
                say "Perhaps I can teach you something..."
                if revered with AD, give option for bracers and gloves
                if exalted with AD, give option for chest
                exit dialogue "I need to go. Evil stirs. Die well, Omarion."


    regardless of any profession, present option:
        "Omarion, I am not a craftsman. Can you still help me?"
        if player reputation < honored
            /spit on you
        else
            send gossip GOSSIP_REPLY_NOT_CRAFTSMAN
            add item 22719 (book) to player
            add exit text "Thank you, Omarion. You have taken a fatal blow for the team on this day."
    */
}

void AddSC_instance_naxxramas()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_naxxramas";
    pNewScript->GetInstanceData = &GetInstanceData_instance_naxxramas;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_naxxramas";
    pNewScript->pAreaTrigger = &AreaTrigger_at_naxxramas;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "spirit_of_naxxramas_ai";
    pNewScript->GetAI = &GetAI_mob_spiritOfNaxxramas;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "naxxramas_gargoyle_ai";
    pNewScript->GetAI = &GetAI_mob_naxxramasGargoyle;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "naxxramas_plague_slime_ai";
    pNewScript->GetAI = &GetAI_mob_plagueSlimeAI;
    pNewScript->RegisterSelf();


    pNewScript = new Script;
    pNewScript->Name = "toxic_tunnel_ai";
    pNewScript->GetAI = &GetAI_toxic_tunnel;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "dark_touched_warriorAI";
    pNewScript->GetAI = &GetAI_dark_touched_warrior;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_archmage_tarsis";
    pNewScript->pGossipHello = &GossipHello_npc_ArchmageTarsis;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_craftsman_omarion";
    pNewScript->pGossipHello = &GossipHello_npc_MasterCraftsmanOmarion;
    pNewScript->pGossipSelect = &GossipSelect_npc_MasterCraftsmanOmarion;
    pNewScript->RegisterSelf();
}
