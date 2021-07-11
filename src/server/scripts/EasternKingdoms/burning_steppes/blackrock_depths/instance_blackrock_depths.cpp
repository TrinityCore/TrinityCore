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
SDName: Instance_Blackrock_Depths
SD%Complete:
SDComment: events: ring of law
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_depths.h"

struct instance_blackrock_depths : ScriptedInstance
{
    explicit instance_blackrock_depths(Map* pMap) : ScriptedInstance(pMap)
    {
        instance_blackrock_depths::Initialize();
    }

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string strInstData;

    uint64 m_uiEmperorGUID;
    uint64 m_uiPrincessGUID;
    uint64 m_uiPhalanxGUID;
    uint64 m_uiHaterelGUID;
    uint64 m_uiAngerrelGUID;
    uint64 m_uiVilerelGUID;
    uint64 m_uiGloomrelGUID;
    uint64 m_uiSeethrelGUID;
    uint64 m_uiDoomrelGUID;
    uint64 m_uiDoperelGUID;

    uint64 m_uiTheldrenGUID;
    uint64 m_uiGrimstoneGUID;
    uint64 m_uiChallengerPlayerGUID;
    uint64 m_uiArenaSpoilsGUID;

    uint64 m_uiGoArena1GUID;
    uint64 m_uiGoArena2GUID;
    uint64 m_uiGoArena3GUID;
    uint64 m_uiGoArena4GUID;
    uint64 m_uiGoShadowLockGUID;
    uint64 m_uiGoShadowMechGUID;
    uint64 m_uiGoShadowGiantGUID;
    uint64 m_uiGoShadowDummyGUID;
    uint64 m_uiGoBarKegGUID;
    uint64 m_uiGoBarKegTrapGUID;
    uint64 m_uiGoBarDoorGUID;
    uint64 m_uiGoTombEnterGUID;
    uint64 m_uiGoTombExitGUID;
    uint64 m_uiGoLyceumGUID;
    uint64 m_uiGoGolemNGUID;
    uint64 m_uiGoGolemSGUID;
    uint64 m_uiGoThroneGUID;

    uint64 m_uiDwarfRuneA01GUID;
    uint64 m_uiDwarfRuneB01GUID;
    uint64 m_uiDwarfRuneC01GUID;
    uint64 m_uiDwarfRuneD01GUID;
    uint64 m_uiDwarfRuneE01GUID;
    uint64 m_uiDwarfRuneF01GUID;
    uint64 m_uiDwarfRuneG01GUID;

    uint64 m_uiGoMagnusGUID;

    uint64 m_uiRocknotGUID;
    uint64 m_uiNagmaraGUID;

    //uint64 m_uiPanzorGUID;
    uint64 m_uiGolemLordArgelmachGUID;
    uint64 m_uiPluggerSpazzringGUID;

    uint64 m_uiSpectralChaliceGUID;
    uint64 m_uiSevensChestGUID;
    uint64 m_uiGoSecretDoorGUID;

    uint32 m_uiBarAleCount;
    uint32 m_uiThunderbrewCount;
    uint32 m_uiRelicCofferDoorCount;

    std::list<uint64> m_lRibblySCronyMobGUIDList;
    std::list<uint64> m_lArenaSpectatorMobGUIDList;
    std::list<uint64> m_lArgelmachProtectorsMobGUIDList;
    std::list<uint64> m_sBarPatronNpcGuids;
    std::list<uint64> m_sBarPatrolGuids;

    bool m_bDoorDughalOpened;
    bool m_bDoorTobiasOpened;
    bool m_bDoorCrestOpened;
    bool m_bDoorJazOpened;
    bool m_bDoorShillOpened;
    bool m_bDoorSupplyOpened;

    bool m_bIsTheldrenInvocated;
    bool m_bBarHostile;

    uint8 m_uiStolenAles;
    uint32 m_uiDagranTimer;
    uint32 m_uiPatronEmoteTimer;
    uint32 m_uiPatrolTimer;

    ObjectGuid m_uiOgrabisiGUID;
    ObjectGuid m_uiShillGUID;
    ObjectGuid m_uiCrestGUID;
    ObjectGuid m_uiJazGUID;
    ObjectGuid m_uiGoJailSupplyRoomGUID;
    ObjectGuid m_uiGoJailSupplyCrateGUID;

    void EnableCreature(Creature* pCreature)
    {
        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiEmperorGUID = 0;
        m_uiPrincessGUID = 0;
        m_uiPhalanxGUID = 0;
        m_uiHaterelGUID = 0;
        m_uiAngerrelGUID = 0;
        m_uiVilerelGUID = 0;
        m_uiGloomrelGUID = 0;
        m_uiSeethrelGUID = 0;
        m_uiDoomrelGUID = 0;
        m_uiDoperelGUID = 0;

        m_uiGoMagnusGUID = 0;

        // Ring of Law Challenge
        m_uiTheldrenGUID = 0;
        m_uiGrimstoneGUID = 0;
        m_uiChallengerPlayerGUID = 0;
        m_uiArenaSpoilsGUID = 0;

        m_uiGoArena1GUID = 0;
        m_uiGoArena2GUID = 0;
        m_uiGoArena3GUID = 0;
        m_uiGoArena4GUID = 0;
        m_uiGoShadowLockGUID = 0;
        m_uiGoShadowMechGUID = 0;
        m_uiGoShadowGiantGUID = 0;
        m_uiGoShadowDummyGUID = 0;
        m_uiGoBarKegGUID = 0;
        m_uiGoBarKegTrapGUID = 0;
        m_uiGoBarDoorGUID = 0;
        m_uiGoTombEnterGUID = 0;
        m_uiGoTombExitGUID = 0;
        m_uiGoLyceumGUID = 0;
        m_uiGoGolemNGUID = 0;
        m_uiGoGolemSGUID = 0;
        m_uiGoThroneGUID = 0;

        m_uiOgrabisiGUID = 0;
        m_uiShillGUID = 0;
        m_uiCrestGUID = 0;
        m_uiJazGUID = 0;
        m_uiGoJailSupplyRoomGUID = 0;
        m_uiGoJailSupplyCrateGUID = 0;

        //m_uiPanzorGUID = 0;
        m_uiGolemLordArgelmachGUID = 0;

        m_uiSpectralChaliceGUID = 0;
        m_uiSevensChestGUID = 0;
        m_uiGoSecretDoorGUID = 0;

        m_uiThunderbrewCount = 0;
        m_uiRelicCofferDoorCount = 0;
        m_bIsTheldrenInvocated = false;

        m_uiBarAleCount = 0;
        m_uiStolenAles  = 0;

        m_uiDagranTimer = 0;
        m_uiPatronEmoteTimer = 2000;
        m_uiPatrolTimer = 0;

        m_bBarHostile = false;

        SetOpenedDoor(GO_JAIL_DOOR_DUGHAL, false);
        SetOpenedDoor(GO_JAIL_DOOR_TOBIAS, false);
        SetOpenedDoor(GO_JAIL_DOOR_JAZ, false);
        SetOpenedDoor(GO_JAIL_DOOR_CREST, false);
        SetOpenedDoor(GO_JAIL_DOOR_SHILL, false);
        SetOpenedDoor(GO_JAIL_DOOR_SUPPLY, false);
    }

    void SetOpenedDoor(uint64 m_uiGoEntry, bool opened)
    {
        switch (m_uiGoEntry)
        {
        case GO_JAIL_DOOR_DUGHAL: m_bDoorDughalOpened = opened; break;
        case GO_JAIL_DOOR_TOBIAS: m_bDoorTobiasOpened = opened; break;
        case GO_JAIL_DOOR_CREST:  m_bDoorCrestOpened = opened; break;
        case GO_JAIL_DOOR_JAZ:    m_bDoorJazOpened = opened; break;
        case GO_JAIL_DOOR_SHILL:  m_bDoorShillOpened = opened; break;
        case GO_JAIL_DOOR_SUPPLY: m_bDoorSupplyOpened = opened; break;
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_EMPEROR:
                m_uiEmperorGUID = pCreature->GetGUID();
                break;
            case NPC_PRINCESS:
                m_uiPrincessGUID = pCreature->GetGUID();
                break;
            case NPC_PHALANX:
                m_uiPhalanxGUID = pCreature->GetGUID();
                break;
            case NPC_HATEREL:
                m_uiHaterelGUID = pCreature->GetGUID();
                break;
            case NPC_ANGERREL:
                m_uiAngerrelGUID = pCreature->GetGUID();
                break;
            case NPC_VILEREL:
                m_uiVilerelGUID = pCreature->GetGUID();
                break;
            case NPC_GLOOMREL:
                m_uiGloomrelGUID = pCreature->GetGUID();
                break;
            case NPC_SEETHREL:
                m_uiSeethrelGUID = pCreature->GetGUID();
                break;
            case NPC_DOOMREL:
                m_uiDoomrelGUID = pCreature->GetGUID();
                break;
            case NPC_DOPEREL:
                m_uiDoperelGUID = pCreature->GetGUID();
                break;
            case NPC_THELDREN:
                m_uiTheldrenGUID = pCreature->GetGUID();
                break;
            case NPC_RIBBLY_S_CRONY:
                m_lRibblySCronyMobGUIDList.push_back(pCreature->GetGUID());
                break;
            case 9938:
                m_uiGoMagnusGUID = pCreature->GetGUID();
                break;
            case NPC_ARENA_SPECTATOR:
                m_lArenaSpectatorMobGUIDList.push_back(pCreature->GetGUID());
                break;
            /*case NPC_PANZOR: m_uiPanzorGUID = pCreature->GetGUID();
                switch (urand (0,1))
                {
                    case 0:
                        pCreature->SetVisibility(VISIBILITY_OFF);
                        break;
                    case 1:
                        pCreature->SetVisibility(VISIBILITY_ON);
                        EnableCreature(pCreature);
                        break;
                }
                break;*/
            case NPC_WRATH_HAMMER_CONSTRUCT:
            case NPC_GOLEM_RAVAGE:
                m_lArgelmachProtectorsMobGUIDList.push_back(pCreature->GetGUID());
                break;
            case NPC_GOLEM_LORD_ARGELMACH:
                m_uiGolemLordArgelmachGUID = pCreature->GetGUID();
                break;
            case NPC_PLUGGER_SPAZZRING:
                m_uiPluggerSpazzringGUID = pCreature->GetGUID();
                break;
            case NPC_GUZZLING_PATRON:
            case NPC_GRIM_PATRON:
            case NPC_HAMMERED_PATRON:
                m_sBarPatronNpcGuids.push_back(pCreature->GetGUID());
                if (GetData(TYPE_PLUGGER) == DONE)
                {
                    pCreature->SetFactionTemporary(FACTION_DARK_IRON, TEMPFACTION_RESTORE_RESPAWN);
                    pCreature->SetStandState(UNIT_STAND_STATE_STAND);
                    m_bBarHostile = true;
                }
                break;
            case NPC_PRIVATE_ROCKNOT:
                m_uiRocknotGUID = pCreature->GetGUID();
                break;
            case NPC_MISTRESS_NAGMARA:
                m_uiNagmaraGUID = pCreature->GetGUID();
                break;
            case NPC_OGRABISI:
                m_uiOgrabisiGUID = pCreature->GetObjectGuid();
                break;
            case NPC_SHILL:
                m_uiShillGUID = pCreature->GetObjectGuid();
                break;
            case NPC_CREST:
                m_uiCrestGUID = pCreature->GetObjectGuid();
                break;
            case NPC_JAZ:
                m_uiJazGUID = pCreature->GetObjectGuid();
                break;
            case NPC_GRIMSTONE:
                m_uiGrimstoneGUID = pCreature->GetGUID();
        }
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_ARENA1:
                m_uiGoArena1GUID = pGo->GetGUID();
                break;
            case GO_ARENA2:
                m_uiGoArena2GUID = pGo->GetGUID();
                break;
            case GO_ARENA3:
                m_uiGoArena3GUID = pGo->GetGUID();
                // Re-open the door for saved instance after restart
                if (GetData(TYPE_RING_OF_LAW) == DONE)
                    pGo->SetGoState(GOState(GO_STATE_ACTIVE));

                break;
            case GO_ARENA4:
                m_uiGoArena4GUID = pGo->GetGUID();
                break;
            case GO_SHADOW_LOCK:
                m_uiGoShadowLockGUID = pGo->GetGUID();
                break;
            case GO_SHADOW_MECHANISM:
                m_uiGoShadowMechGUID = pGo->GetGUID();
                break;
            case GO_SHADOW_GIANT_DOOR:
                m_uiGoShadowGiantGUID = pGo->GetGUID();
                break;
            case GO_SHADOW_DUMMY:
                m_uiGoShadowDummyGUID = pGo->GetGUID();
                break;
            case GO_BAR_KEG_SHOT:
                m_uiGoBarKegGUID = pGo->GetGUID();
                break;
            case GO_BAR_KEG_TRAP:
                m_uiGoBarKegTrapGUID = pGo->GetGUID();
                break;
            case GO_BAR_DOOR:
                m_uiGoBarDoorGUID = pGo->GetGUID();
                if (GetData(TYPE_ROCKNOT) == DONE)
                    pGo->SetGoState(GOState(2));
                if(GetData(TYPE_NAGMARA) == DONE || GetData(TYPE_PLUGGER) == DONE)
                    pGo->SetGoState(GOState(0));
                break;
            case GO_TOMB_ENTER:
                m_uiGoTombEnterGUID = pGo->GetGUID();
                break;
            case GO_TOMB_EXIT:
                m_uiGoTombExitGUID = pGo->GetGUID();
                if (GetData(TYPE_TOMB_OF_SEVEN) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_LYCEUM:
                m_uiGoLyceumGUID = pGo->GetGUID();
                break;
            case GO_GOLEM_ROOM_N:
                m_uiGoGolemNGUID = pGo->GetGUID();
                if (GetData(TYPE_LYCEUM) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_GOLEM_ROOM_S:
                m_uiGoGolemSGUID = pGo->GetGUID();
                if (GetData(TYPE_LYCEUM) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_THRONE_ROOM:
                m_uiGoThroneGUID = pGo->GetGUID();
                if (GetData(TYPE_IRON_HALL) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_SPECTRAL_CHALICE:
                m_uiSpectralChaliceGUID = pGo->GetGUID();
                break;
            case GO_CHEST_SEVEN:
                m_uiSevensChestGUID = pGo->GetGUID();
                break;
            case GO_SECRET_DOOR:
                m_uiGoSecretDoorGUID = pGo->GetGUID();
                break;
            case GO_JAIL_DOOR_SUPPLY:
                m_uiGoJailSupplyRoomGUID = pGo->GetObjectGuid();
                break;
            case GO_JAIL_SUPPLY_CRATE:
                m_uiGoJailSupplyCrateGUID = pGo->GetObjectGuid();
                break;
            case GO_ARENA_SPOILS:
                m_uiArenaSpoilsGUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_A01:
                m_uiDwarfRuneA01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_B01:
                m_uiDwarfRuneB01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_C01:
                m_uiDwarfRuneC01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_D01:
                m_uiDwarfRuneD01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_E01:
                m_uiDwarfRuneE01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_F01:
                m_uiDwarfRuneF01GUID = pGo->GetGUID();
                break;
            case GO_DWARF_RUNE_G01:
                m_uiDwarfRuneG01GUID = pGo->GetGUID();
                break;
        }
    }

    void OnCreatureDeath(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_SHADOWFORGE_SENATOR:
                // Emperor Dagran Thaurissan performs a random yell upon the death
                // of Shadowforge Senators in the Throne Room
                if (Creature* pDagran = instance->GetCreature(GetData64(DATA_EMPEROR)))
                {
                    uint32 uiTextId;

                    if (!pDagran->IsAlive())
                        return;

                    if (m_uiDagranTimer > 0)
                        return;

                    switch (urand(0, 3))
                    {
                        case 0: uiTextId = YELL_SENATOR_1; break;
                        case 1: uiTextId = YELL_SENATOR_2; break;
                        case 2: uiTextId = YELL_SENATOR_3; break;
                        case 3: uiTextId = YELL_SENATOR_4; break;
                    }
                    DoScriptText(uiTextId, pDagran);
                    m_uiDagranTimer = 45000;    // set a timer of 45 sec to avoid Emperor Thaurissan to spam yells in case many senators are killed in a short amount of time
                }
                break;
            case NPC_GRIM_PATRON:
            case NPC_HAMMERED_PATRON:
            case NPC_GUZZLING_PATRON:
               HandleBarPatrons(PATRON_HOSTILE);
               break;
            /*case NPC_THELDREN:
                SetData(DATA_THELDREN, DONE);
                break;*/
        }
    }

    void HandleBarPatrons(uint8 uiEventType)
    {
        switch  (uiEventType)
        {
        // case for periodical handle of random emotes
        case PATRON_EMOTE:
            if (GetData(TYPE_PLUGGER) == DONE)
                return;

            for (const auto& guid : m_sBarPatronNpcGuids)
            {
                 // About 5% of patrons do emote at a given time
                // So avoid executing follow up code for the 95% others
                if (urand(0, 100) < 4)
                {
                    // Only three emotes are seen in data: laugh, cheer and exclamation
                    // the last one appearing the least and the first one appearing the most
                    // emotes are stored in a table and frequency is handled there
                    if (Creature* pPatron = instance->GetCreature(guid))
                       pPatron->HandleEmote(aPatronsEmotes[urand(0, 5)]);
                }
            }
            return;
        // case for Rocknot event when breaking the barrel
        case PATRON_PISSED:
            // Three texts are said, one less often than the two others
            // Only by patrons near the broken barrel react to Rocknot's rampage
            if (GameObject* pGo = instance->GetGameObject(m_uiGoBarKegTrapGUID))
            {
                for (const auto& guid : m_sBarPatronNpcGuids)
                {
                    if (Creature* pPatron = instance->GetCreature(guid))
                    {
                        if (pPatron->GetPositionZ() > pGo->GetPositionZ() - 1 && pPatron->IsWithinDist2d(pGo->GetPositionX(), pGo->GetPositionY(), 18.0f))
                        {
                            uint32 uiTextId = 0;
                            switch (urand(0, 4))
                            {
                                case 0: uiTextId = SAY_PISSED_PATRON_3; break;
                                case 1:  // case is double to give this text twice the chance of the previous one do be displayed
                                case 2: uiTextId = SAY_PISSED_PATRON_2; break;
                                // covers the two remaining cases
                                default: uiTextId = SAY_PISSED_PATRON_1; break;
                            }
                            DoScriptText(uiTextId, pPatron);
                        }
                    }
                }
            }
            return;
        // case when Plugger is killed
        case PATRON_HOSTILE:
            if (m_bBarHostile)
                return;

            m_bBarHostile = true;

            for (const auto& guid : m_sBarPatronNpcGuids)
            {
                if (Creature* pPatron = instance->GetCreature(guid))
                {
                    pPatron->SetFactionTemporary(FACTION_DARK_IRON, TEMPFACTION_RESTORE_RESPAWN);
                    pPatron->SetStandState(UNIT_STAND_STATE_STAND);
                    pPatron->HandleEmote(0);
                    pPatron->SetDefaultMovementType(RANDOM_MOTION_TYPE);
                    pPatron->SetWanderDistance(3.0f);
                    pPatron->GetMotionMaster()->Initialize();
                }
            }
            // Mistress Nagmara and Private Rocknot despawn if the bar turns hostile
            if (Creature* pRocknot = instance->GetCreature(GetData64(DATA_ROCKNOT)))
            {
                if (pRocknot->HasAura(15064)) // don't despawn if Rocknot and Nagmara are kissing under the stairs
                    return;
                DoScriptText(SAY_ROCKNOT_DESPAWN, pRocknot);
                pRocknot->ForcedDespawn();
            }
            if (Creature* pNagmara = instance->GetCreature(GetData64(DATA_NAGMARA)))
            {
                pNagmara->CastSpell(pNagmara, SPELL_NAGMARA_VANISH, true);
                pNagmara->ForcedDespawn();
            }
            return;
        }
    }

    void HandleBarPatrol(uint8 uiStep)
    {
        if (GetData(TYPE_PATROL) == DONE)
            return;

        switch (uiStep)
        {
            case 0:
                if (Creature* pPlugger = instance->GetCreature(GetData64(DATA_PLUGGER)))
                {
                    // if relevant, open the bar door
                    if (GameObject* pGo = instance->GetGameObject(m_uiGoBarDoorGUID))
                    {
                        if (pGo->GetGoState() == GO_STATE_READY) // Closed
                            DoUseDoorOrButton(m_uiGoBarDoorGUID);
                    }

                    // One Fireguard Destroyer and two Anvilrage Officers are spawned
                    for (uint32 i : aBarPatrolId)
                    {
                        float fX, fY, fZ;
                        // spawn them behind the bar door
                        pPlugger->GetRandomPoint(aBarPatrolPositions[0][0], aBarPatrolPositions[0][1], aBarPatrolPositions[0][2], 2.0f, fX, fY, fZ);
                        if (Creature* pSummoned = pPlugger->SummonCreature(i, fX, fY, fZ, aBarPatrolPositions[0][3], TEMPSUMMON_DEAD_DESPAWN, 0))
                        {
                            m_sBarPatrolGuids.push_back(pSummoned->GetGUID());
                            // move them to the Grim Guzzler
                            pPlugger->GetRandomPoint(aBarPatrolPositions[1][0], aBarPatrolPositions[1][1], aBarPatrolPositions[1][2], 2.0f, fX, fY, fZ);
                            pSummoned->GetMotionMaster()->MoveIdle();
                            pSummoned->GetMotionMaster()->MovePoint(0,fX, fY, fZ);
                        }
                    }
                    // start timer to handle the yells
                    m_uiPatrolTimer = 5000;
                    break;
                }
            case 1:
                for (const auto& guid : m_sBarPatrolGuids)
                {
                    if (Creature* pCreature = instance->GetCreature(guid))
                    {
                        if (pCreature->GetEntry() == NPC_ANVILRAGE_OFFICER)
                        {
                            DoScriptText(YELL_PATROL_1, pCreature);
                            SetData(TYPE_PATROL, SPECIAL); // temporary set the status to special before the next yell: event will then be complete
                            m_uiPatrolTimer = 3000;
                            break;
                        }
                    }
                }
                break;
            case 2:
                for (const auto& guid : m_sBarPatrolGuids)
                {
                    if (Creature* pCreature = instance->GetCreature(guid))
                    {
                        if (pCreature->GetEntry() == NPC_ANVILRAGE_OFFICER)
                        {
                            DoScriptText(YELL_PATROL_2, pCreature);
                            SetData(TYPE_PATROL, DONE);
                            m_uiPatrolTimer = 0;
                            break;
                        }
                    }
                }
                break;
        }
    }

    void CustomSpellCasted(uint32 spellId, Unit* caster, Unit* target) override
    {
        sLog.outString("Spell %u caste par '%s' sur '%s'", spellId, caster->GetName(), (target) ? target->GetName() : "<Personne>");
        switch (spellId)
        {
            // BRD : Invocation de Theldren
            case 27517:
            {
                // On invoque pas 2 fois ...
                if (m_bIsTheldrenInvocated)
                    return;

                if (Player *pPlayer = caster->ToPlayer())
                {
                    m_bIsTheldrenInvocated = true;
                    BeginTheldrenEvent(pPlayer);
                }
                break;
            }
            default:
                break;
        }
    }

    void DoSummonCreatureAndAttack(uint32 entry, Unit* who, uint32 num)
    {
        float posx = 586.0f;
        float posy = -152.0f;
        float posz = -52.0f;
        switch (num)
        {
            case 0:
                posx = 598.0f;
                posy = -153.0f;
                break;
            case 1:
                posx = 577.0f;
                posy = -162.0f;
                break;
            case 2:
                posx = 583.0f;
                posy = -158.0f;
                break;
            case 3:
                posx = 593.0f;
                posy = -154.0f;
                break;
        }
        if (Creature* crea = instance->SummonCreature(entry, posx, posy, posz, 4.8f))
        {
            crea->SetInCombatWithZone();
            crea->AI()->AttackStart(who);
            crea->SetFactionTemplateId(16);
        }
    }

    void BeginTheldrenEvent(Player* pPlayer)
    {
        SetData(DATA_THELDREN, IN_PROGRESS);

        m_uiChallengerPlayerGUID = pPlayer->GetGUID();
    }

    void ReplacePrincessIfPossible()
    {
        Map::PlayerList const& players = instance->GetPlayers();
        if (players.isEmpty())
            return;

        bool needsReplacing = true;
        for (const auto& itr : players)
        {
            if (Player* pPlayer = itr.getSource())
            {
                // if at least one player didn't complete the quest, return false
                if ((pPlayer->GetTeam() == ALLIANCE && !pPlayer->GetQuestRewardStatus(QUEST_FATE_KINGDOM))
                        || (pPlayer->GetTeam() == HORDE && !pPlayer->GetQuestRewardStatus(QUEST_ROYAL_RESCUE)))
                    needsReplacing = false;
            }
        }

        if (needsReplacing)
        {
            if (Creature* pMoira = instance->GetCreature(GetData64(DATA_PRINCESS)))
                pMoira->UpdateEntry(NPC_HIGH_PRIESTESS);
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        sLog.outDebug("Instance Blackrock Depths: SetData update (Type: %u Data %u)", uiType, uiData);

        switch (uiType)
        {
            case TYPE_RING_OF_LAW:
                if (uiData == DONE)
                {
                    for (const auto& guid : m_lArenaSpectatorMobGUIDList)
                    {
                        if (Creature* pCreature = instance->GetCreature(guid))
                        {
                            if (pCreature->IsAlive())
                                pCreature->SetFactionTemplateId(674);
                        }
                    }
                }
                m_auiEncounter[TYPE_RING_OF_LAW] = uiData;
                break;
            case TYPE_VAULT:
                m_auiEncounter[TYPE_VAULT] = uiData;
                break;
            case TYPE_ROCKNOT:
                if (uiData == SPECIAL)
                    ++m_uiBarAleCount;
                else 
                {
                    if (uiData == DONE)
                        HandleBarPatrons(PATRON_PISSED);
                    m_auiEncounter[2] = uiData;
                }
                break;
            case TYPE_TOMB_OF_SEVEN:
                switch (uiData)
                {
                    case IN_PROGRESS:
                        DoUseDoorOrButton(m_uiGoTombEnterGUID);
                        break;
                    case FAIL:
                        if (m_auiEncounter[3] == IN_PROGRESS)//prevent use more than one time
                            DoUseDoorOrButton(m_uiGoTombEnterGUID);
                        break;
                    case DONE:
                        DoRespawnGameObject(m_uiSevensChestGUID, HOUR * IN_MILLISECONDS);
                        DoUseDoorOrButton(m_uiGoTombExitGUID);
                        DoUseDoorOrButton(m_uiGoTombEnterGUID);
                        break;
                }
                m_auiEncounter[TYPE_TOMB_OF_SEVEN] = uiData;
                break;
            case TYPE_LYCEUM:
                if (uiData == IN_PROGRESS && GetData(TYPE_LYCEUM) == DONE)
                    uiData = DONE;
                if (uiData == DONE)
                {
                    DoOpenDoor(m_uiGoGolemNGUID);
                    DoOpenDoor(m_uiGoGolemSGUID);
                    if (Creature* magnus = instance->GetCreature(m_uiGoMagnusGUID))
                    {
                        DoScriptText(YELL_MAGMUS, magnus);
                        std::list<Creature*> AnvilrageList;
                        GetCreatureListWithEntryInGrid(AnvilrageList, magnus, 8901, 400.0f);

                        for (const auto& it : AnvilrageList)
                            it->SetRespawnDelay(345600);
                    }
                }
                m_auiEncounter[TYPE_LYCEUM] = uiData;
                break;
            case TYPE_IRON_HALL:
                switch (uiData)
                {
                    case IN_PROGRESS:
                        DoResetDoor(m_uiGoGolemNGUID);
                        DoResetDoor(m_uiGoGolemSGUID);
                        break;
                    case FAIL:
                        DoOpenDoor(m_uiGoGolemNGUID);
                        DoOpenDoor(m_uiGoGolemSGUID);
                        break;
                    case DONE:
                        DoOpenDoor(m_uiGoGolemNGUID);
                        DoOpenDoor(m_uiGoGolemSGUID);
                        DoOpenDoor(m_uiGoThroneGUID);
                        ReplacePrincessIfPossible();
                        break;
                }
                m_auiEncounter[TYPE_IRON_HALL] = uiData;
                break;
            case TYPE_THUNDERBREW:
                if (uiData == IN_PROGRESS)
                {
                    m_uiThunderbrewCount++;
                    if (m_uiThunderbrewCount == 3)
                        m_auiEncounter[TYPE_THUNDERBREW] = DONE;
                }
                break;
            case TYPE_RELIC_COFFER:
                if (uiData == IN_PROGRESS)
                {
                    m_uiRelicCofferDoorCount++;
                    if (m_uiRelicCofferDoorCount == 12)
                        m_auiEncounter[TYPE_RELIC_COFFER] = DONE;
                }
                break;
            case TYPE_DOOMGRIP:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiGoSecretDoorGUID);
                m_auiEncounter[TYPE_DOOMGRIP] = uiData;
                break;
            case TYPE_RIBBLY:
                if (uiData == DONE)
                {
                    for (const auto& guid : m_lRibblySCronyMobGUIDList)
                    {
                        if (Creature* pCreature = instance->GetCreature(guid))
                        {
                            if (pCreature->IsAlive())
                            {
                                pCreature->SetFactionTemplateId(14);
                                Unit* pVictim = pCreature->GetVictim();
                                if (pCreature->AI())
                                    pCreature->AI()->AttackStart(pVictim);
                            }
                        }
                    }
                }
                m_auiEncounter[TYPE_RIBBLY] = uiData;
                break;
            case DATA_ARGELMACH_AGGRO:
                if (uiData == IN_PROGRESS)
                {
                    if (Creature* argelmach = instance->GetCreature(m_uiGolemLordArgelmachGUID))
                        if (Unit* pVictim = argelmach->GetVictim())
                            for (const auto& guid : m_lArgelmachProtectorsMobGUIDList)
                                if (Creature* protector = instance->GetCreature(guid))
                                    if (protector->IsAlive() && protector->AI() && protector->IsWithinDist(argelmach, 80.0f))
                                        protector->AI()->AttackStart(pVictim);
                }
                m_auiEncounter[DATA_ARGELMACH_AGGRO] = uiData;
                break;
            case TYPE_PATROL:
                if (uiData == IN_PROGRESS)
                    HandleBarPatrol(0);
                m_auiEncounter[11] = uiData;
                break;
            case DATA_THELDREN:
                if (uiData == DONE)
                {
                    // Spawn "Arena Spoils" chest with sick loot
                    DoRespawnGameObject(m_uiArenaSpoilsGUID);
                }
                m_auiEncounter[12] = uiData;
                break;
            case TYPE_NAGMARA:
                m_auiEncounter[13] = uiData;
                break;
            case TYPE_BRIDGE:
                m_auiEncounter[14] = uiData;
                break;
            case TYPE_PLUGGER:
                if (uiData == SPECIAL)
                {
                    if (Creature* pPlugger = instance->GetCreature(m_uiPluggerSpazzringGUID))
                    {
                        ++m_uiStolenAles;
                        if (m_uiStolenAles == 3)
                            uiData = IN_PROGRESS;
                    }
                }
                m_auiEncounter[15] = uiData;
                break;
            case TYPE_QUEST_JAIL_BREAK:
                m_auiEncounter[16] = uiData;
                break;
            case TYPE_JAIL_DUGHAL:
                m_auiEncounter[17] = uiData;
                break;
            case TYPE_JAIL_SUPPLY_ROOM:
                m_auiEncounter[18] = uiData;
                break;
            case TYPE_JAIL_TOBIAS:
                m_auiEncounter[19] = uiData;
                break;
            case GO_JAIL_DOOR_DUGHAL: m_bDoorDughalOpened = uiData; break;
            case GO_JAIL_DOOR_TOBIAS: m_bDoorTobiasOpened = uiData; break;
            case GO_JAIL_DOOR_CREST:  m_bDoorCrestOpened  = uiData; break;
            case GO_JAIL_DOOR_JAZ:    m_bDoorJazOpened    = uiData; break;
            case GO_JAIL_DOOR_SHILL:  m_bDoorShillOpened  = uiData; break;
            case GO_JAIL_DOOR_SUPPLY: m_bDoorSupplyOpened = uiData; break;
            case EVENT_BAR_PATRONS:
                HandleBarPatrons(uiData);
                break;
       }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                       << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5] << " "
                       << m_auiEncounter[6] << " " << m_auiEncounter[7] << " " << m_auiEncounter[8] << " "
                       << m_auiEncounter[9] << " " << m_auiEncounter[10] << " " << m_auiEncounter[11] << " "
                       << m_auiEncounter[12] << " " << m_auiEncounter[13] << " " << m_auiEncounter[14] << " "
                       << m_auiEncounter[15] << " " << m_auiEncounter[16] << " " << m_auiEncounter[17] << " "
                       << m_auiEncounter[18] << " " << m_auiEncounter[19];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    bool GetOpenedDoor(uint64 m_uiGoEntry)
    {
        switch(m_uiGoEntry)
        {
            case GO_JAIL_DOOR_DUGHAL: return m_bDoorDughalOpened;
            case GO_JAIL_DOOR_TOBIAS: return m_bDoorTobiasOpened;
            case GO_JAIL_DOOR_CREST:  return m_bDoorCrestOpened;
            case GO_JAIL_DOOR_JAZ:    return m_bDoorJazOpened;
            case GO_JAIL_DOOR_SHILL:  return m_bDoorShillOpened;
            case GO_JAIL_DOOR_SUPPLY: return m_bDoorSupplyOpened;
        }
        return false;
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_RING_OF_LAW:
                return m_auiEncounter[0];
            case TYPE_VAULT:
                return m_auiEncounter[1];
            case TYPE_ROCKNOT:
                if (m_auiEncounter[2] == IN_PROGRESS && m_uiBarAleCount == 3)
                    return SPECIAL;
                else
                    return m_auiEncounter[2];
            case TYPE_TOMB_OF_SEVEN:
                return m_auiEncounter[3];
            case TYPE_LYCEUM:
                return m_auiEncounter[4];
            case TYPE_IRON_HALL:
                return m_auiEncounter[5];
            case TYPE_THUNDERBREW:
                return m_auiEncounter[6];
            case TYPE_RELIC_COFFER:
                return m_auiEncounter[7];
            case TYPE_DOOMGRIP:
                return m_auiEncounter[8];
            case TYPE_RIBBLY:
                return m_auiEncounter[9];
            case DATA_ARGELMACH_AGGRO:
                return m_auiEncounter[10];
            case TYPE_PATROL:
                return m_auiEncounter[11];
            case DATA_THELDREN:
                return m_auiEncounter[12];
            case TYPE_NAGMARA:
                return m_auiEncounter[13];
            case TYPE_BRIDGE:
                return m_auiEncounter[14];
            case TYPE_PLUGGER:
                return m_auiEncounter[15];
            case TYPE_QUEST_JAIL_BREAK:
                return m_auiEncounter[16];
            case TYPE_JAIL_DUGHAL:
                return m_auiEncounter[17];
            case TYPE_JAIL_SUPPLY_ROOM:
                return m_auiEncounter[18];
            case TYPE_JAIL_TOBIAS:
                return m_auiEncounter[19];
            case GO_JAIL_DOOR_DUGHAL: return m_bDoorDughalOpened;
            case GO_JAIL_DOOR_TOBIAS: return m_bDoorTobiasOpened;
            case GO_JAIL_DOOR_CREST:  return m_bDoorCrestOpened;
            case GO_JAIL_DOOR_JAZ:    return m_bDoorJazOpened;
            case GO_JAIL_DOOR_SHILL:  return m_bDoorShillOpened;
            case GO_JAIL_DOOR_SUPPLY: return m_bDoorSupplyOpened; 
        }
        return 0;
    }

    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case DATA_EMPEROR:
                return m_uiEmperorGUID;
            case DATA_PRINCESS:
                return m_uiPrincessGUID;
            case DATA_PHALANX:
                return m_uiPhalanxGUID;
            case DATA_HATEREL:
                return m_uiHaterelGUID;
            case DATA_ANGERREL:
                return m_uiAngerrelGUID;
            case DATA_VILEREL:
                return m_uiVilerelGUID;
            case DATA_GLOOMREL:
                return m_uiGloomrelGUID;
            case DATA_SEETHREL:
                return m_uiSeethrelGUID;
            case DATA_DOOMREL:
                return m_uiDoomrelGUID;
            case DATA_DOPEREL:
                return m_uiDoperelGUID;

            case DATA_ARENA1:
                return m_uiGoArena1GUID;
            case DATA_ARENA2:
                return m_uiGoArena2GUID;
            case DATA_ARENA3:
                return m_uiGoArena3GUID;
            case DATA_ARENA4:
                return m_uiGoArena4GUID;

            case DATA_GO_BAR_KEG:
                return m_uiGoBarKegGUID;
            case DATA_GO_BAR_KEG_TRAP:
                return m_uiGoBarKegTrapGUID;
            case DATA_GO_BAR_DOOR:
                return m_uiGoBarDoorGUID;
            case DATA_GO_CHALICE:
                return m_uiSpectralChaliceGUID;
            case DATA_GO_TOMB_EXIT:
                return m_uiGoTombExitGUID;

            case DATA_ROCKNOT:
                return m_uiRocknotGUID;
            case DATA_NAGMARA:
                return m_uiNagmaraGUID;
            case DATA_PLUGGER:
                return m_uiPluggerSpazzringGUID;

            case NPC_OGRABISI:
                return m_uiOgrabisiGUID;
            case NPC_SHILL:
                return m_uiShillGUID;
            case NPC_CREST:
                return m_uiCrestGUID;
            case NPC_JAZ:
                return m_uiJazGUID;
            case GO_JAIL_DOOR_SUPPLY:
                return m_uiGoJailSupplyRoomGUID;
            case GO_JAIL_SUPPLY_CRATE:
                return m_uiGoJailSupplyCrateGUID; 
            case GO_DWARF_RUNE_A01:
                return m_uiDwarfRuneA01GUID;
            case GO_DWARF_RUNE_B01:
                return m_uiDwarfRuneB01GUID;
            case GO_DWARF_RUNE_C01:
                return m_uiDwarfRuneC01GUID;
            case GO_DWARF_RUNE_D01:
                return m_uiDwarfRuneD01GUID;
            case GO_DWARF_RUNE_E01:
                return m_uiDwarfRuneE01GUID;
            case GO_DWARF_RUNE_F01:
                return m_uiDwarfRuneF01GUID;
            case GO_DWARF_RUNE_G01:
                return m_uiDwarfRuneG01GUID;

            case DATA_ARENA_CHALLENGER:
                return m_uiChallengerPlayerGUID;
            case NPC_GRIMSTONE:
                return m_uiGrimstoneGUID;

        }
        return 0;
    }

    void Update(uint32 uiDiff) override
    {
        if (m_uiDagranTimer)
        {
            if (m_uiDagranTimer <= uiDiff)
                m_uiDagranTimer = 0;
            else
                m_uiDagranTimer -= uiDiff;
        }  

        // Every second some of the patrons will do one random emote if they are not hostile (i.e. Plugger event is not done/in progress)
        if (m_uiPatronEmoteTimer)
        {
            if (m_uiPatronEmoteTimer <= uiDiff)
            {
                HandleBarPatrons(PATRON_EMOTE);
                m_uiPatronEmoteTimer = 1250;
            }
            else
                m_uiPatronEmoteTimer -= uiDiff;
        }

        if (m_uiPatrolTimer)
        {
            if (m_uiPatrolTimer <= uiDiff)
            {
                switch(GetData(TYPE_PATROL))
                {
                    case IN_PROGRESS:
                        HandleBarPatrol(1);
                        break;
                    case SPECIAL:
                        HandleBarPatrol(2);
                        break;
                    default:
                        break;
                }
            }
            else
                m_uiPatrolTimer -= uiDiff;
        }
    }

    char const* Save() override
    {
        return strInstData.c_str();
    }

    void Load(char const* in) override
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);

        std::istringstream loadStream(in);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
                   >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6] >> m_auiEncounter[7]
                   >> m_auiEncounter[8] >> m_auiEncounter[9] >> m_auiEncounter[10] >> m_auiEncounter[11]
                   >> m_auiEncounter[12] >> m_auiEncounter[13] >> m_auiEncounter[14] >> m_auiEncounter[15]
                   >> m_auiEncounter[16] >> m_auiEncounter[17] >> m_auiEncounter[18] >> m_auiEncounter[19];

        for (uint32 & i : m_auiEncounter)
            if (i == IN_PROGRESS)
                i = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_blackrock_depths(Map* pMap)
{
    return new instance_blackrock_depths(pMap);
}

void AddSC_instance_blackrock_depths()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_blackrock_depths";
    newscript->GetInstanceData = &GetInstanceData_instance_blackrock_depths;
    newscript->RegisterSelf();
}
