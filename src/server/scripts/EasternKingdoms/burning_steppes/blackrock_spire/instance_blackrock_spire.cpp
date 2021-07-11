/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: instance_blackrock_spire
SD%Complete: 50
SDComment: To really get this instance working, many encounters will need more love - and also the DB content is surely not yet perfect.
SDCategory: Blackrock Spire
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_spire.h"
#include "WaypointManager.h"
#include "CreatureGroups.h"

//#define DEBUG_ON

enum
{
    AREATRIGGER_ENTER_UBRS      = 2046,
    AREATRIGGER_STADIUM         = 2026,

    // Arena event dialogue intro and outro - handled by instance
    SAY_NEFARIUS_INTRO_1        = 5635,
    SAY_NEFARIUS_INTRO_2        = 5640,
    SAY_NEFARIUS_LOSE1          = 5709,
    SAY_REND_ATTACK             = 5722,
    SAY_NEFARIUS_WARCHIEF       = 5720,
    SAY_NEFARIUS_PACING         = 5721,
    SAY_NEFARIUS_VICTORY        = 5824,

    // Arena event random taunt - handled on creature death
    SAY_NEFARIUS_TAUNT1         = 5665,
    SAY_NEFARIUS_TAUNT2         = 5671,
    SAY_NEFARIUS_TAUNT3         = 5666,
    SAY_NEFARIUS_TAUNT4         = 5667,
    SAY_NEFARIUS_TAUNT5         = 5668,
    SAY_NEFARIUS_TAUNT6         = 5669,
    SAY_NEFARIUS_TAUNT7         = 5664,
    SAY_NEFARIUS_TAUNT8         = 5719,
    SAY_REND_TAUNT1             = 5672,
    SAY_REND_TAUNT2             = 5678,
    SAY_REND_TAUNT3             = 5673,
    SAY_REND_TAUNT4             = 5674,

    WAYPOINT_ID_STADIUM         = 10442,
};

/* Areatrigger
1470 Instance Entry
1628 LBRS, between Spiders and Ogres
1946 LBRS, ubrs pre-quest giver (1)
1986 LBRS, ubrs pre-quest giver (2)
1987 LBRS, ubrs pre-quest giver (3)
2026 UBRS, stadium event trigger
2046 UBRS, way to upper
2066 UBRS, The Beast - Exit (to the dark chamber)
2067 UBRS, The Beast - Entry
2068 LBRS, fall out of map
3726 UBRS, entrance to BWL
*/

static const uint32 aStadiumSpectators[12] =
{
    NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_ELITE, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN,
    NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_ELITE, NPC_BLACKHAND_VETERAN, NPC_BLACKHAND_VETERAN
};

static const Position aSpectatorsSpawnLocs[12] =
{
    { 163.3209f, -340.9818f, 111.0216f, 4.818223f },
    { 164.2471f, -339.0313f, 111.0368f, 1.413717f },
    { 161.124f, -339.5178f, 111.0381f, 3.001966f },
    { 162.5045f, -337.8101f, 111.0367f, 4.13643f },
    { 160.9896f, -337.7715f, 111.0368f, 1.117011f },
    { 161.8347f, -335.7923f, 111.0352f, 2.286381f },
    { 113.9726f, -366.0805f, 116.9195f, 6.252025f },
    { 112.7245f, -368.9635f, 116.9307f, 4.677482f },
    { 110.5757f, -368.2123f, 116.9278f, 4.310963f },
    { 109.3343f, -366.4785f, 116.9261f, 2.740167f },
    { 110.1331f, -363.9824f, 116.9272f, 0.5235988f },
    { 111.9971f, -363.0948f, 116.929f, 5.951573f },
};

static const Position aSpectatorsTargetLocs[12] =
{
    { 160.619f, -395.826f, 121.9752f, -1.502597f },
    { 162.1428f, -395.1175f, 121.9751f, -1.67753f },
    { 158.6822f, -395.7097f, 121.9753f, -1.787977f },
    { 164.384f, -395.3787f, 121.9751f, -1.502597f },
    { 156.9669f, -395.2188f, 121.9752f, -1.678662f },
    { 166.2515f, -395.0366f, 121.975f, -1.791467f },
    { 143.814f, -396.7092f, 121.9753f, -1.40136f },
    { 145.3893f, -396.1959f, 121.9752f, -1.419479f },
    { 142.1598f, -396.0284f, 121.9752f, -1.661444f },
    { 147.7274f, -396.3042f, 121.9753f, -1.40136f },
    { 139.9446f, -396.7277f, 121.9753f, -1.428414f },
    { 149.3754f, -395.7497f, 121.9753f, -1.714769f },
};

static const Position aStadiumLocs[7] =
{
    {210.00f, -420.30f, 110.94f, 3.14f},                    // dragons summon location
    {211.762f,-397.58f, 111.18f, 4.74f},                    // Gyth summon location
    {163.62f, -420.33f, 110.47f, 0.0f},                     // center of the stadium location (for movement)
    {164.63f, -444.04f, 121.97f, 3.22f},                    // Lord Nefarius summon position
    {161.01f, -443.73f, 121.97f, 6.26f},                    // Rend summon position
    {164.64f, -443.30f, 121.97f, 1.61f},                    // Nefarius move position
    {165.74f, -466.46f, 116.80f, 0.0f},                     // Rend move position
};

// Stadium event description
static const uint32 aStadiumEventNpcs[MAX_STADIUM_WAVES][MAX_STADIUM_MOBS_PER_WAVE] =
{
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, 0},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, 0},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, NPC_BLACKHAND_HANDLER, 0},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, NPC_BLACKHAND_HANDLER, 0},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, NPC_BLACKHAND_HANDLER},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, NPC_CHROMATIC_DRAGON, NPC_BLACKHAND_HANDLER},
    {NPC_CHROMATIC_WHELP, NPC_CHROMATIC_WHELP, NPC_CHROMATIC_DRAGON, NPC_CHROMATIC_DRAGON, NPC_BLACKHAND_HANDLER},
};

static const SIDialogueEntry aStadiumDialogue[] =
{
    {NPC_LORD_VICTOR_NEFARIUS,  0,                          1000},
    {SAY_NEFARIUS_INTRO_1,      NPC_LORD_VICTOR_NEFARIUS,   7000},
    {SAY_NEFARIUS_INTRO_2,      NPC_LORD_VICTOR_NEFARIUS,   5000},
    {NPC_BLACKHAND_HANDLER,     0,                          0},
    {SAY_NEFARIUS_LOSE1,        NPC_LORD_VICTOR_NEFARIUS,   3000},
    {SAY_REND_ATTACK,           NPC_REND_BLACKHAND,         2000},
    {SAY_NEFARIUS_WARCHIEF,     NPC_LORD_VICTOR_NEFARIUS,   3000},
    {SAY_NEFARIUS_PACING,       NPC_LORD_VICTOR_NEFARIUS,   0},
    {SAY_NEFARIUS_VICTORY,      NPC_LORD_VICTOR_NEFARIUS,   5000},
    {NPC_REND_BLACKHAND,        0,                          0},
    {0, 0, 0},
};

instance_blackrock_spire::instance_blackrock_spire(Map* pMap) : ScriptedInstance(pMap), DialogueHelper(aStadiumDialogue), 
    m_uiEmberseerGUID(0),
    m_uiNefariusGUID(0),
    m_uiRendGUID(0),
    m_uiGythGUID(0),
    m_uiInfiltratorGUID(0),
    m_uiDrakkisathGUID(0),

    m_uiEmberseerInDoorGUID(0),
    m_uiEmberseerCombatDoorGUID(0),
    m_uiEmberseerOutDoorGUID(0),

    m_uiGythEntryDoorGUID(0),
    m_uiGythCombatDoorGUID(0),
    m_uiGythExitDoorGUID(0),

    m_uiFatherFlameGUID(0),
    m_uiFatherFlame_timer(0),
    m_uiFatherFlame_WaveCount(0),
    m_uiSolakarTriggerGUID(0),

    m_uiUBRSDoorGUID(0),
    m_uiBrazier01GUID(0),
    m_uiBrazier02GUID(0),
    m_uiBrazier03GUID(0),
    m_uiBrazier04GUID(0),
    m_uiBrazier05GUID(0),
    m_uiBrazier06GUID(0),

    m_uiEmberseerRune01GUID(0),
    m_uiEmberseerRune02GUID(0),
    m_uiEmberseerRune03GUID(0),
    m_uiEmberseerRune04GUID(0),
    m_uiEmberseerRune05GUID(0),
    m_uiEmberseerRune06GUID(0),
    m_uiEmberseerRune07GUID(0),

    m_uiBlackRockAltarGUID(0),

    m_uiUBRSDoor_Timer(0),
    m_uiUBRSDoor_Step(0),

    m_uiStadiumEventTimer(0),
    m_uiStadiumWaves(0),
    m_uiStadiumMobsAlive(0),

    m_bBannokSpawned(false)

{
    Initialize();
}

void instance_blackrock_spire::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    memset(&m_auiRoomRuneGUID, 0, sizeof(m_auiRoomRuneGUID));
#ifdef DEBUG_ON
    sLog.outString("Instance BlackRockSpire : Initialize");
#endif
}

void instance_blackrock_spire::OnObjectCreate(GameObject* pGo)
{
    switch (pGo->GetEntry())
    {
        case GO_BLACKROCK_ALTAR:
            m_uiBlackRockAltarGUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_IN:
            m_uiEmberseerInDoorGUID = pGo->GetGUID();
            if (GetData(TYPE_ROOM_EVENT) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_DOORS:
            m_uiEmberseerCombatDoorGUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_OUT:
            m_uiEmberseerOutDoorGUID = pGo->GetGUID();
            if (GetData(TYPE_EMBERSEER) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_GYTH_ENTRY_DOOR:
            m_uiGythEntryDoorGUID = pGo->GetGUID();
            break;
        case GO_GYTH_COMBAT_DOOR:
            m_uiGythCombatDoorGUID = pGo->GetGUID();
            break;
        case GO_GYTH_EXIT_DOOR:
            m_uiGythExitDoorGUID = pGo->GetGUID();
            if (GetData(TYPE_STADIUM) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;

        case GO_ROOM_1_RUNE:
            m_auiRoomRuneGUID[0] = pGo->GetGUID();
            break;
        case GO_ROOM_2_RUNE:
            m_auiRoomRuneGUID[1] = pGo->GetGUID();
            break;
        case GO_ROOM_3_RUNE:
            m_auiRoomRuneGUID[2] = pGo->GetGUID();
            break;
        case GO_ROOM_4_RUNE:
            m_auiRoomRuneGUID[3] = pGo->GetGUID();
            break;
        case GO_ROOM_5_RUNE:
            m_auiRoomRuneGUID[4] = pGo->GetGUID();
            break;
        case GO_ROOM_6_RUNE:
            m_auiRoomRuneGUID[5] = pGo->GetGUID();
            break;
        case GO_ROOM_7_RUNE:
            m_auiRoomRuneGUID[6] = pGo->GetGUID();
            break;

        case GO_ROOKERY_EGG:
            m_lRookeryEggGUIDList.push_back(pGo->GetGUID());
            break;
        case GO_FATHER_FLAME:
            m_uiFatherFlameGUID = pGo->GetGUID();
            /*if (GetData(TYPE_SOLAKAR) == FAIL)
                DoRespawnGameObject(m_uiFatherFlameGUID, HOUR*IN_MILLISECONDS);*/
            break;

        case GO_DOOR_URBS:
            m_uiUBRSDoorGUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_BRAZIER01:
            m_uiBrazier01GUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_BRAZIER02:
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_uiBrazier02GUID = pGo->GetGUID();
            break;
        case GO_BRAZIER03:
            m_uiBrazier03GUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_BRAZIER04:
            m_uiBrazier04GUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_BRAZIER05:
            m_uiBrazier05GUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_BRAZIER06:
            m_uiBrazier06GUID = pGo->GetGUID();
            if (GetData(TYPE_EVENT_DOOR_UBRS) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;

        case GO_EMBERSEER_RUNE01:
            m_uiEmberseerRune01GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE02:
            m_uiEmberseerRune02GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE03:
            m_uiEmberseerRune03GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE04:
            m_uiEmberseerRune04GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE05:
            m_uiEmberseerRune05GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE06:
            m_uiEmberseerRune06GUID = pGo->GetGUID();
            break;
        case GO_EMBERSEER_RUNE07:
            m_uiEmberseerRune07GUID = pGo->GetGUID();
            break;
    }
}

void instance_blackrock_spire::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_PYROGUARD_EMBERSEER:
            m_uiEmberseerGUID = pCreature->GetGUID();
            break;
        case NPC_LORD_VICTOR_NEFARIUS:
            m_uiNefariusGUID = pCreature->GetGUID();
            break;
        case NPC_REND_BLACKHAND:
            if (!m_uiRendGUID) // only save the original Rend
                m_uiRendGUID = pCreature->GetGUID();
            break;
        case NPC_GYTH:
            m_uiGythGUID = pCreature->GetGUID();
            break;
        case NPC_SCARSHIELD_INFILTRATOR:
            m_uiInfiltratorGUID = pCreature->GetGUID();
            break;
        case NPC_DRAKKISATH:
            m_uiDrakkisathGUID = pCreature->GetGUID();
            break;
        case NPC_THE_BEAST:
            m_uiBeastGUID = pCreature->GetGUID();
            break;

        case NPC_BLACKHAND_SUMMONER:
        case NPC_BLACKHAND_VETERAN:
            m_lRoomEventMobGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_BLACKHAND_INCANCERATOR:
            m_lIncanceratorGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_SOLAKAR_TRIGGER:
            m_uiSolakarTriggerGUID = pCreature->GetGUID();
            break;
        case NPC_FIREBRAND_GRUNT:
            // 14.26% chance to spawn Bannok Grimaxe instead of one of his 3 placeholders
            switch (pCreature->GetGUIDLow())
            {
                case 44020:
                case 43764:
                case 44327:
                    if (!m_bBannokSpawned && urand(0,99) < 5)
                    {
                        pCreature->UpdateEntry(NPC_BANNOK_GRIMAXE);
                        m_bBannokSpawned = true;
                    }
            }
            break;
    }
}

void instance_blackrock_spire::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
        case TYPE_ROOM_EVENT:
            if (uiData == DONE)
                DoUseDoorOrButton(m_uiEmberseerInDoorGUID);
            m_auiEncounter[TYPE_ROOM_EVENT] = uiData;
            break;
        case TYPE_EMBERSEER:
            if (uiData == IN_PROGRESS || uiData == FAIL)
                DoUseDoorOrButton(m_uiEmberseerCombatDoorGUID);
            else if (uiData == DONE)
            {
                DoUseDoorOrButton(m_uiEmberseerCombatDoorGUID);
                DoUseDoorOrButton(m_uiEmberseerOutDoorGUID);
                DoUseDoorOrButton(m_uiEmberseerRune01GUID);
                DoUseDoorOrButton(m_uiEmberseerRune02GUID);
                DoUseDoorOrButton(m_uiEmberseerRune03GUID);
                DoUseDoorOrButton(m_uiEmberseerRune04GUID);
                DoUseDoorOrButton(m_uiEmberseerRune05GUID);
                DoUseDoorOrButton(m_uiEmberseerRune06GUID);
                DoUseDoorOrButton(m_uiEmberseerRune07GUID);
            }
            m_auiEncounter[TYPE_EMBERSEER] = uiData;
            break;
        case TYPE_FLAMEWREATH:
            m_auiEncounter[TYPE_FLAMEWREATH] = uiData;
            break;
        case TYPE_STADIUM:
            // Don't set the same data twice
            if (m_auiEncounter[uiType] == uiData)
                break;
            // Combat door
            DoUseDoorOrButton(m_uiGythEntryDoorGUID);
            // Start event
            if (uiData == IN_PROGRESS)
                StartNextDialogueText(SAY_NEFARIUS_INTRO_1);
            else if (uiData == DONE)
            {
                // Event complete: remove the summoned spectators
                DespawnStadiumSpectators();
                DoUseDoorOrButton(m_uiGythExitDoorGUID);
            }
            else if (uiData == FAIL)
            {
                // Despawn Nefarius, Rend and the spectators on fail (the others are despawned OnCreatureEvade())
                if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
                    pNefarius->DespawnOrUnsummon();
                if (Creature* pRend = GetCreature(m_uiRendGUID))
                    pRend->DespawnOrUnsummon();
                if (Creature* pGyth = GetCreature(m_uiGythGUID))
                    pGyth->DespawnOrUnsummon();
                DespawnStadiumSpectators();

                m_uiStadiumEventTimer = 0;
                m_uiStadiumMobsAlive = 0;
                m_uiStadiumWaves = 0;
            }
            m_auiEncounter[uiType] = uiData;
            break;
        case TYPE_VALTHALAK:
            m_auiEncounter[TYPE_VALTHALAK] = uiData;
            break;
        case TYPE_EVENT_DOOR_UBRS:
            if (uiData == DONE)
                m_uiUBRSDoor_Timer = 2000;
            m_auiEncounter[TYPE_EVENT_DOOR_UBRS] = uiData;
            break;
        case TYPE_SOLAKAR:
            if ((uiData == FAIL && m_uiFatherFlame_timer != 0) || uiData == SPECIAL)
            {
                //DoRespawnGameObject(m_uiFatherFlameGUID, HOUR*IN_MILLISECONDS);
                m_uiFatherFlame_timer = 0;
                m_uiFatherFlame_WaveCount = 0;
            }
            if (uiData == IN_PROGRESS)
                m_uiFatherFlame_timer = 5000;

            m_auiEncounter[TYPE_SOLAKAR] = uiData;
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5] << " " << m_auiEncounter[6];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_blackrock_spire::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_CHROMATIC_WHELP:
        case NPC_CHROMATIC_DRAGON:
        case NPC_BLACKHAND_HANDLER:
            // check if it's summoned - some npcs with the same entry are already spawned in the instance
            if (!pCreature->IsTemporarySummon())
                break;

            // 5% chance for Rend or Lord Victor Nefarius to taunt players when one of the creature is killed (% is guesswork)
            // Lord Victor Nefarius
            if (urand(0, 100) < 5)
            {
                if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
                {
                    uint32 const textId = PickRandomValue(SAY_NEFARIUS_TAUNT1, SAY_NEFARIUS_TAUNT2, SAY_NEFARIUS_TAUNT3,
                                                          SAY_NEFARIUS_TAUNT4, SAY_NEFARIUS_TAUNT5, SAY_NEFARIUS_TAUNT6,
                                                          SAY_NEFARIUS_TAUNT7, SAY_NEFARIUS_TAUNT8);
                    DoScriptText(textId, pNefarius);
                }
            }
            // Warchief Rend Blackhand
            if (urand(0, 100) < 5)
            {
                if (Creature* pRend = GetCreature(m_uiRendGUID))
                {
                    uint32 const textId = PickRandomValue(SAY_REND_TAUNT1, SAY_REND_TAUNT2, SAY_REND_TAUNT3, SAY_REND_TAUNT4);
                    DoScriptText(textId, pRend);
                }
            }
            --m_uiStadiumMobsAlive;
            if (!m_uiStadiumMobsAlive && (m_uiStadiumWaves == MAX_STADIUM_WAVES))
                DoSendNextStadiumWave();
            break;
        case NPC_GYTH:
        case NPC_REND_BLACKHAND:
            --m_uiStadiumMobsAlive;
            if (m_uiStadiumMobsAlive == 0)
                StartNextDialogueText(SAY_NEFARIUS_VICTORY);
            break;
    }
}

void instance_blackrock_spire::OnCreatureEvade(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_CHROMATIC_WHELP:
        case NPC_CHROMATIC_DRAGON:
        case NPC_BLACKHAND_HANDLER:
        case NPC_GYTH:
        case NPC_REND_BLACKHAND:
            // check if it's summoned - some npcs with the same entry are already spawned in the instance
            if (!pCreature->IsTemporarySummon())
                break;
            SetData(TYPE_STADIUM, FAIL);
            pCreature->DespawnOrUnsummon();
            break;
    }
}

Creature* instance_blackrock_spire::GetSpeakerByEntry(uint32 uiEntry)
{
    switch (uiEntry)
    {
        case NPC_LORD_VICTOR_NEFARIUS:
            return GetCreature(m_uiNefariusGUID);
        case NPC_REND_BLACKHAND:
            return GetCreature(m_uiRendGUID);
    }

    return nullptr;
}

void instance_blackrock_spire::JustDidDialogueStep(int32 iEntry)
{
    switch (iEntry)
    {
        case NPC_BLACKHAND_HANDLER:
            m_uiStadiumEventTimer = 1000;
            // Move the two near the balcony
            if (Creature* pRend = GetCreature(m_uiRendGUID))
                pRend->SetFacingTo(aStadiumLocs[5].o);
            if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
            {
                pNefarius->GetMotionMaster()->MovePoint(0, aStadiumLocs[5].x, aStadiumLocs[5].y, aStadiumLocs[5].z, 0, 0.0f, aStadiumLocs[5].o);
                // Summon the spectators and move them to the western balcony
                for (uint8 i = 0; i < 12; i++)
                {
                    if (Creature* pSpectator = pNefarius->SummonCreature(aStadiumSpectators[i], aSpectatorsSpawnLocs[i].x, aSpectatorsSpawnLocs[i].y, aSpectatorsSpawnLocs[i].z, aSpectatorsSpawnLocs[i].o, TEMPSUMMON_DEAD_DESPAWN, 0))
                    {
                        pSpectator->SetDetectionDistance(1.0f);
                        pSpectator->SetNoCallAssistance(true);
                        pSpectator->SetWalk(false);
                        pSpectator->SetHomePosition(aSpectatorsTargetLocs[i].x, aSpectatorsTargetLocs[i].y, aSpectatorsTargetLocs[i].z, aSpectatorsTargetLocs[i].o);
                        pSpectator->GetMotionMaster()->MovePoint(0, aSpectatorsTargetLocs[i].x, aSpectatorsTargetLocs[i].y, aSpectatorsTargetLocs[i].z, 0, 0.0f, aSpectatorsTargetLocs[i].o);
                        m_lStadiumSpectatorsGUIDList.push_back(pSpectator->GetObjectGuid());
                    }
                }
            }
            break;
        case SAY_NEFARIUS_WARCHIEF:
            // Prepare for Gyth
            if (Creature* pRend = GetCreature(m_uiRendGUID))
            {
                pRend->ForcedDespawn(5000);
                pRend->SetWalk(false);
                pRend->GetMotionMaster()->MovePoint(0, aStadiumLocs[6].x, aStadiumLocs[6].y, aStadiumLocs[6].z);
            }
            m_uiStadiumEventTimer = 30000;
            break;
        case SAY_NEFARIUS_PACING:
            // Make Lord Nefarius walk back and forth while Rend is preparing Glyth
            if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
                pNefarius->GetMotionMaster()->MoveWaypoint();
            break;
        case SAY_NEFARIUS_VICTORY:
            SetData(TYPE_STADIUM, DONE);
            break;
        case NPC_REND_BLACKHAND:
            // Despawn Nefarius
            if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
            {
                pNefarius->ForcedDespawn(5000);
                pNefarius->GetMotionMaster()->MovePoint(0, aStadiumLocs[6].x, aStadiumLocs[6].y, aStadiumLocs[6].z);
            }
            break;
    }
}

void instance_blackrock_spire::DespawnStadiumSpectators()
{
    for (const auto& itr : m_lStadiumSpectatorsGUIDList)
    {
        if (Creature* pSpectator = instance->GetCreature(itr))
            pSpectator->DespawnOrUnsummon();
    }
    m_lStadiumSpectatorsGUIDList.clear();
}

void instance_blackrock_spire::DoSendNextStadiumWave()
{
    if (m_uiStadiumWaves < MAX_STADIUM_WAVES)
    {
        // Send current wave mobs
        if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
        {
            float fX, fY, fZ;
            Creature* pFirstMob = nullptr;
            for (uint8 i = 0; i < MAX_STADIUM_MOBS_PER_WAVE; ++i)
            {
                if (aStadiumEventNpcs[m_uiStadiumWaves][i] == 0)
                    continue;

                pNefarius->GetRandomPoint(aStadiumLocs[0].x, aStadiumLocs[0].y, aStadiumLocs[0].z, 7.0f, fX, fY, fZ);
                fX = std::min(aStadiumLocs[0].x, fX);    // Halfcircle - suits better the rectangular form
                if (Creature* pTemp = pNefarius->SummonCreature(aStadiumEventNpcs[m_uiStadiumWaves][i], fX, fY, fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
                {
                    if (!pFirstMob)
                        pFirstMob = pTemp;
                    else
                        pTemp->JoinCreatureGroup(pFirstMob, frand(3.0f, 5.0f), i, OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER);
                    ++m_uiStadiumMobsAlive;
                }
            }

            if (pFirstMob)
                pFirstMob->GetMotionMaster()->MoveWaypoint(0, PATH_FROM_SPECIAL, 0, 0, WAYPOINT_ID_STADIUM, true);
        }

        DoUseDoorOrButton(m_uiGythCombatDoorGUID);
    }
    // All waves are cleared - start Gyth intro
    else if (m_uiStadiumWaves == MAX_STADIUM_WAVES)
        StartNextDialogueText(SAY_NEFARIUS_LOSE1);
    else
    {
        // Send Gyth
        if (Creature* pNefarius = GetCreature(m_uiNefariusGUID))
        {
            // Stop Lord Nefarius from moving and put him back in place
            pNefarius->GetMotionMaster()->MoveIdle();
            pNefarius->GetMotionMaster()->MovePoint(0, aStadiumLocs[5].x, aStadiumLocs[5].y, aStadiumLocs[5].z, 0, 0.0f, aStadiumLocs[5].o);

            if (Creature* pGyth = pNefarius->SummonCreature(NPC_GYTH, aStadiumLocs[1].x, aStadiumLocs[1].y, aStadiumLocs[1].z, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                pGyth->SetWalk(false);
                pGyth->GetMotionMaster()->MoveWaypoint();
            }
        }

        // Set this to 2, because Rend will be summoned later during the fight
        m_uiStadiumMobsAlive = 2;

        DoUseDoorOrButton(m_uiGythCombatDoorGUID);
    }

    ++m_uiStadiumWaves;

    // Stop the timer when all the waves have been sent
    if (m_uiStadiumWaves >= MAX_STADIUM_WAVES)
        m_uiStadiumEventTimer = 0;
    else
        m_uiStadiumEventTimer = 60000;
}

enum
{
    SAY_ROOKERY_EVENT_START = -1229020
};

void instance_blackrock_spire::Update(uint32 uiDiff)
{
    DialogueUpdate(uiDiff);

    if (m_uiStadiumEventTimer)
    {
        if (m_uiStadiumEventTimer <= uiDiff)
            DoSendNextStadiumWave();
        else
            m_uiStadiumEventTimer -= uiDiff;
    }

    if (m_uiUBRSDoor_Timer)
    {
        if (m_uiUBRSDoor_Timer <= uiDiff)
        {
            switch (m_uiUBRSDoor_Step)
            {
                case 0:
                    DoUseDoorOrButton(m_uiBrazier01GUID);
                    DoUseDoorOrButton(m_uiBrazier02GUID);
                    m_uiUBRSDoor_Timer = 3000;
                    ++m_uiUBRSDoor_Step;
                    break;
                case 1:
                    DoUseDoorOrButton(m_uiBrazier03GUID);
                    DoUseDoorOrButton(m_uiBrazier04GUID);
                    m_uiUBRSDoor_Timer = 3000;
                    ++m_uiUBRSDoor_Step;
                    break;
                case 2:
                    DoUseDoorOrButton(m_uiBrazier05GUID);
                    DoUseDoorOrButton(m_uiBrazier06GUID);
                    m_uiUBRSDoor_Timer = 3000;
                    ++m_uiUBRSDoor_Step;
                    break;
                case 3:
                    DoUseDoorOrButton(m_uiUBRSDoorGUID);
                    m_uiUBRSDoor_Step = 0;
                    m_uiUBRSDoor_Timer = 0;
                    break;
            }
        }
        else
            m_uiUBRSDoor_Timer -= uiDiff;
    }

    if (GetData(TYPE_SOLAKAR) == IN_PROGRESS)
    {
        if (Creature* Crea = GetCreature(m_uiSolakarTriggerGUID))
        {
            if (m_uiFatherFlame_timer <= uiDiff)
            {
                if (m_uiFatherFlame_WaveCount == 0) // First wave should be a Rookery Hatcher and there is a text that it has to say.
                {
                    Creature* pFirstHatcher = Crea->SummonCreature(NPC_ROOKERY_HATCHER, 55.232342f, -265.751282f, 93.883f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                    if (pFirstHatcher)
                        DoScriptText(SAY_ROOKERY_EVENT_START, pFirstHatcher);
                    Crea->SummonCreature(NPC_ROOKERY_HATCHER, 60.011333f, -263.914703f, 94.022f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                    m_uiFatherFlame_timer = urand(30000, 40000);
                    ++m_uiFatherFlame_WaveCount;
                }
                else if (m_uiFatherFlame_WaveCount < 5)
                {
                    switch (urand(0, 2))
                    {
                        case 0:
                        {
                            Crea->SummonCreature(NPC_ROOKERY_GUARDIAN, 55.232342f, -265.751282f, 93.883f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            Crea->SummonCreature(NPC_ROOKERY_GUARDIAN, 60.011333f, -263.914703f, 94.022f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            break;
                        }
                        case 1:
                        {
                            Crea->SummonCreature(NPC_ROOKERY_HATCHER, 55.232342f, -265.751282f, 93.883f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            Crea->SummonCreature(NPC_ROOKERY_HATCHER, 60.011333f, -263.914703f, 94.022f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            break;
                        }
                        case 2:
                        {
                            Crea->SummonCreature(NPC_ROOKERY_GUARDIAN, 55.232342f, -265.751282f, 93.883f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            Crea->SummonCreature(NPC_ROOKERY_HATCHER, 60.011333f, -263.914703f, 94.022f, 5, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                            break;
                        }
                    }
                    m_uiFatherFlame_timer = urand(30000, 40000);
                    ++m_uiFatherFlame_WaveCount;
                }
                else
                {
                    Crea->SummonCreature(NPC_SOLAKAR, 43.7685f, -259.82f, 91.6483f, 0, TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                    SetData(TYPE_SOLAKAR, DONE);
                    m_uiFatherFlame_timer = 0;
                }
            }
            else
                m_uiFatherFlame_timer -= uiDiff;
        }
    }
}

void instance_blackrock_spire::SetData64(uint32 uiType, uint64 uiData)
{
    if (uiType == TYPE_ROOM_EVENT && GetData(TYPE_ROOM_EVENT) == IN_PROGRESS)
    {
        uint8 uiNotEmptyRoomsCount = 0;
        for (uint8 i = 0; i < MAX_ROOMS; i++)
        {
            if (m_auiRoomRuneGUID[i])                       // This check is used, to ensure which runes still need processing
            {
                m_alRoomEventMobGUIDSorted[i].remove(uiData);
                if (m_alRoomEventMobGUIDSorted[i].empty())
                {
                    DoUseDoorOrButton(m_auiRoomRuneGUID[i]);
                    m_auiRoomRuneGUID[i] = 0;
                }
                else
                    uiNotEmptyRoomsCount++;                 // found an not empty room
            }
        }
        if (!uiNotEmptyRoomsCount)
            SetData(TYPE_ROOM_EVENT, DONE);
    }
}

void instance_blackrock_spire::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6];

    for (uint32 & i : m_auiEncounter)
    {
        if (i == IN_PROGRESS)
            i = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_blackrock_spire::GetData(uint32 uiType)
{
    switch (uiType)
    {
        case TYPE_ROOM_EVENT:
        case TYPE_EMBERSEER:
        case TYPE_FLAMEWREATH:
        case TYPE_STADIUM:
        case TYPE_VALTHALAK:
        case TYPE_EVENT_DOOR_UBRS:
        case TYPE_SOLAKAR:
            return m_auiEncounter[uiType];
    }
    return 0;
}

uint64 instance_blackrock_spire::GetData64(uint32 uiType)
{
    switch (uiType)
    {
        case GO_BLACKROCK_ALTAR:
            return m_uiBlackRockAltarGUID;
        case NPC_PYROGUARD_EMBERSEER:
            return m_uiEmberseerGUID;
        case NPC_LORD_VICTOR_NEFARIUS:
            return m_uiNefariusGUID;
        case NPC_REND_BLACKHAND:
            return m_uiRendGUID;
        case NPC_GYTH:
            return m_uiGythGUID;
        case NPC_SCARSHIELD_INFILTRATOR:
            return m_uiInfiltratorGUID;
        case GO_GYTH_COMBAT_DOOR:
            return m_uiGythCombatDoorGUID;
        case NPC_DRAKKISATH:
            return m_uiDrakkisathGUID;
        case NPC_THE_BEAST:
            return m_uiBeastGUID;
    }
    return 0;
}

void instance_blackrock_spire::DoSortRoomEventMobs()
{
    if (GetData(TYPE_ROOM_EVENT) != NOT_STARTED)
        return;
#ifdef DEBUG_ON
    sLog.outString("instance_blackrock_spire::DoSortRoomEventMobs");
#endif
    for (uint8 i = 0; i < MAX_ROOMS; i++)
    {
        if (GameObject* pRune = instance->GetGameObject(m_auiRoomRuneGUID[i]))
        {
            for (const auto& guid : m_lRoomEventMobGUIDList)
            {
                if (Creature* pCreature = instance->GetCreature(guid))
                {
                    if (pCreature->IsAlive() && pCreature->GetDistance(pRune) < 10.0f)
                        m_alRoomEventMobGUIDSorted[i].push_back(guid);
                }
#ifdef DEBUG_ON
                sLog.outString("Alcove %u : %u mobs", i,  m_alRoomEventMobGUIDSorted[i].size());
#endif
            }
        }
    }

    SetData(TYPE_ROOM_EVENT, IN_PROGRESS);
}

InstanceData* GetInstanceData_instance_blackrock_spire(Map* pMap)
{
    return new instance_blackrock_spire(pMap);
}

bool AreaTrigger_at_blackrock_spire(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->IsDead() || pPlayer->IsGameMaster())
        return false;

    switch (pAt->id)
    {
        case AREATRIGGER_ENTER_UBRS:
            if (instance_blackrock_spire* pInstance = (instance_blackrock_spire*) pPlayer->GetInstanceData())
            {
                pInstance->DoSortRoomEventMobs();
                if (pPlayer->HasItemCount(12344, 1)) // le joueur a le sceau de l'ascension
                    if (pInstance->GetData(TYPE_EVENT_DOOR_UBRS) != DONE)
                        pInstance->SetData(TYPE_EVENT_DOOR_UBRS, DONE);
            }
            break;
        case AREATRIGGER_STADIUM:
            if (instance_blackrock_spire* pInstance = (instance_blackrock_spire*)pPlayer->GetInstanceData())
            {
                if (pInstance->GetData(TYPE_STADIUM) == IN_PROGRESS || pInstance->GetData(TYPE_STADIUM) == DONE)
                    return false;

                // Respawn Nefarius and Rend for the dialogue event if they are not spawned already.
                if (Creature* pNefarius = pInstance->GetCreature(pInstance->GetData64(NPC_LORD_VICTOR_NEFARIUS)))
                    if (!pNefarius->IsAlive())
                        pNefarius->Respawn();
                if (Creature* pRend = pInstance->GetCreature(pInstance->GetData64(NPC_REND_BLACKHAND)))
                    if (!pRend->IsAlive())
                        pRend->Respawn();

                pInstance->SetData(TYPE_STADIUM, IN_PROGRESS);
            }
            break;
    }
    return false;
}

struct go_father_flameAI: public GameObjectAI
{
    go_father_flameAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser) override
    {
        if (ScriptedInstance* pInstance = (instance_blackrock_spire*)me->GetInstanceData())
            if (pInstance->GetData(TYPE_SOLAKAR) != IN_PROGRESS && pInstance->GetData(TYPE_SOLAKAR) != DONE)
                if (Creature* pDrakki = pInstance->instance->GetCreature(pInstance->GetData64(NPC_DRAKKISATH)))
                    if (pDrakki->IsAlive())
                        pInstance->SetData(TYPE_SOLAKAR, IN_PROGRESS);
        return true;
    }
};

GameObjectAI* GetAIgo_father_flame(GameObject *pGo)
{
    return new go_father_flameAI(pGo);
}

struct npc_solakar_triggerAI : public ScriptedAI
{
    npc_solakar_triggerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        instance = (instance_blackrock_spire*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* instance;

    void Reset() override
    {
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!instance)
            return;

        if (who->GetTypeId() == TYPEID_UNIT && m_creature->IsWithinDistInMap(who, 5.0f) && instance->GetData(TYPE_SOLAKAR) == IN_PROGRESS)
        {
            Creature* CreaGuardian = m_creature->FindNearestCreature(10258, 5.0f); // NPC_ROOKERY_GUARDIAN = 10258
            Creature* CreaHatcher = m_creature->FindNearestCreature(10683, 5.0f); // NPC_ROOKERY_HATCHER = 10683
            if (CreaGuardian || CreaHatcher)
            {
                instance->SetData(TYPE_SOLAKAR, SPECIAL);

                std::list<Creature*> listHatcher;
                GetCreatureListWithEntryInGrid(listHatcher, m_creature, 10683, 10.0f);
                for (std::list<Creature*>::const_iterator itr = listHatcher.begin(); itr != listHatcher.end(); ++itr)
                {
                    if (listHatcher.empty())
                        break;
                    if (!(*itr)->IsAlive())
                        continue;

                    (*itr)->AI()->EnterEvadeMode();
                }
                listHatcher.clear();
            }
        }
    }
};

CreatureAI* GetAI_npc_solakar_trigger(Creature* pCreature)
{
    return new npc_solakar_triggerAI(pCreature);
}

/****************************************
** Rookery Hatcher npc_rookery_hatcher **
****************************************/

enum
{
    SPELL_SUNDER_ARMOR       = 15572,
    SPELL_STRIKE             = 15580,
    SPELL_HATCH_ROOKERY_EGG  = 15746
};

struct npc_rookery_hatcherAI : public ScriptedAI
{
    npc_rookery_hatcherAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_blackrock_spire*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 SunderArmor_Timer;
    uint32 Strike_Timer;
    uint32 HatchRookeryEgg_Timer;

    void Reset() override
    {
        SunderArmor_Timer = urand(8000, 12000);
        Strike_Timer = urand(5000, 7000);
        HatchRookeryEgg_Timer = urand(5000, 10000);
    }

    void JustReachedHome() override
    {
        if (m_pInstance->GetData(TYPE_SOLAKAR) == SPECIAL)
            HatchRookeryEgg();
        else
            m_pInstance->SetData(TYPE_SOLAKAR, FAIL);
        m_creature->ForcedDespawn();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // Do not aggro players in the Hall of Binding.
        if (pWho->GetPositionX() > 110.0f)
            return;

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void HatchRookeryEgg()
    {
        uint8 uiHatchedEgg = 0;
        uint8 uiMaxHatchedEgg = 4;
        std::list<GameObject*> listRookeryEgg;
        GetGameObjectListWithEntryInGrid(listRookeryEgg, m_creature, 175124, 50.0f);
        for (std::list<GameObject*>::const_iterator itr = listRookeryEgg.begin(); itr != listRookeryEgg.end(); ++itr)
        {
            if (listRookeryEgg.empty())
                break;
            if (!(*itr)->isSpawned())
                continue;

            if (uiHatchedEgg < uiMaxHatchedEgg)
            {
                (*itr)->SetLootState(GO_JUST_DEACTIVATED);
                if (m_pInstance->GetData(TYPE_SOLAKAR) == SPECIAL)
                {
                    m_creature->SummonCreature(160015, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    uiMaxHatchedEgg = 24;
                }
                else
                    m_creature->SummonCreature(10161, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);

                uiHatchedEgg++;
            }
            else
                break;
        }
        listRookeryEgg.clear();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == 10161)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_pInstance || !m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //  Sunder Armor
        if (SunderArmor_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SUNDER_ARMOR) == CAST_OK)
                SunderArmor_Timer = urand(10000, 15000);
        }
        else
            SunderArmor_Timer -= uiDiff;

        //  Strike
        if (Strike_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_STRIKE) == CAST_OK)
                Strike_Timer = urand(4000, 6000);
        }
        else
            Strike_Timer -= uiDiff;

        //  Hatch Rookery Egg
        if (HatchRookeryEgg_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_HATCH_ROOKERY_EGG) == CAST_OK)
            {
                HatchRookeryEgg();
                HatchRookeryEgg_Timer = urand(15000, 20000);
            }
        }
        else
            HatchRookeryEgg_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_rookery_hatcher(Creature* pCreature)
{
    return new npc_rookery_hatcherAI(pCreature);
}

/*struct go_rookey_eggAI : public GameObjectAI
{
    go_rookey_eggAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser)
    {
        if (me->isSpawned())
        {
            me->SetLootState(GO_JUST_DEACTIVATED);
            float x,y,z;
            me->GetPosition(x,y,z);
            ((Creature *)pUser)->SummonCreature(160015, x, y, z, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
        }
    }

    void SummonWelp()
    {
        Map::PlayerList const &liste = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = liste.begin(); i != liste.end(); ++i)
        {
            if (me->GetDistance(i->getSource()) <= 4.0f)
            {
                me->SetLootState(GO_JUST_DEACTIVATED);
                float x,y,z;
                me->GetPosition(x,y,z);
                i->getSource()->SummonCreature(10161, x, y, z, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                Actif = true;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff)
    {
        if (!Actif && me->isSpawned())
        {
            if (CheckTimer <= uiDiff)
            {
                SummonWelp();
                CheckTimer = 500;
            }
            else
                CheckTimer -= uiDiff;
        }
    }
};

GameObjectAI* GetAIgo_rookey_egg(GameObject *pGo)
{
    return new go_rookey_eggAI(pGo);
}*/

bool AreaTrigger_at_ubrs_the_beast(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->IsDead())
        return false;

    if (instance_blackrock_spire* pInstance = (instance_blackrock_spire*)pPlayer->GetInstanceData())
        if (Creature* pBeast = pInstance->instance->GetCreature(pInstance->GetData64(NPC_THE_BEAST)))
            if (pBeast->IsAlive() && !pBeast->IsInCombat())
                pBeast->AI()->AttackStart(pPlayer);

    return false;
}

void AddSC_instance_blackrock_spire()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "instance_blackrock_spire";
    pNewScript->GetInstanceData = &GetInstanceData_instance_blackrock_spire;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_blackrock_spire";
    pNewScript->pAreaTrigger = &AreaTrigger_at_blackrock_spire;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_father_flame";
    pNewScript->GOGetAI = &GetAIgo_father_flame;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_solakar_trigger";
    pNewScript->GetAI = &GetAI_npc_solakar_trigger;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_rookery_hatcher";
    pNewScript->GetAI = &GetAI_npc_rookery_hatcher;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_ubrs_the_beast";
    pNewScript->pAreaTrigger = &AreaTrigger_at_ubrs_the_beast;
    pNewScript->RegisterSelf();

    /*    pNewScript = new Script;
        pNewScript->Name = "go_rookey_egg";
        pNewScript->GOGetAI = &GetAIgo_rookey_egg;
        pNewScript->RegisterSelf();*/
}
