/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "CreatureTextMgr.h"
#include "naxxramas.h"

const DoorData doorData[] =
{
    {GO_ANUBREKHAN_DOOR,    DATA_ANUBREKHAN,    DOOR_TYPE_ROOM,     BOUNDARY_S  },
    {GO_ANUBREKHAN_ESCAPE,  DATA_ANUBREKHAN,    DOOR_TYPE_PASSAGE,  0           },
    {GO_FEARLINA_DOOR_1,    DATA_FAERLINA,      DOOR_TYPE_PASSAGE,  0           },
    {GO_MAEXXNA_DOOR,       DATA_FAERLINA,      DOOR_TYPE_PASSAGE,  0           },
    {GO_MAEXXNA_DOOR,       DATA_MAEXXNA,       DOOR_TYPE_ROOM,     BOUNDARY_SW },
    {GO_SPIDER_PORTAL,      DATA_MAEXXNA,       DOOR_TYPE_PASSAGE,  0           },
    {GO_NOTH_ENTRANCE,      DATA_NOTH,          DOOR_TYPE_ROOM,     BOUNDARY_N  },
    {GO_NOTH_ESCAPE,        DATA_NOTH,          DOOR_TYPE_PASSAGE,  BOUNDARY_E  },
    {GO_HEIGAN_ENTRANCE,    DATA_NOTH,          DOOR_TYPE_PASSAGE,  0           },
    {GO_HEIGAN_ENTRANCE,    DATA_HEIGAN,        DOOR_TYPE_ROOM,     BOUNDARY_N  },
    {GO_HEIGAN_ESCAPE,      DATA_HEIGAN,        DOOR_TYPE_PASSAGE,  BOUNDARY_E  },
    {GO_LOATHEB_DOOR,       DATA_HEIGAN,        DOOR_TYPE_PASSAGE,  0           },
    {GO_LOATHEB_DOOR,       DATA_LOATHEB,       DOOR_TYPE_ROOM,     BOUNDARY_W  },
    {GO_PLAGUE_WING_PORTAL, DATA_LOATHEB,       DOOR_TYPE_PASSAGE,  0           },
    {GO_GROBBULUS_DOOR,     DATA_PATCHWERK,     DOOR_TYPE_PASSAGE,  0           },
    {GO_GROBBULUS_DOOR,     DATA_GROBBULUS,     DOOR_TYPE_ROOM,     0           },
    {GO_GLUTH_ESCAPE,       DATA_GLUTH,         DOOR_TYPE_PASSAGE,  BOUNDARY_NW },
    {GO_THADDIUS_DOOR,      DATA_GLUTH,         DOOR_TYPE_PASSAGE,  0           },
    {GO_THADDIUS_DOOR,      DATA_THADDIUS,      DOOR_TYPE_ROOM,     0           },
    {GO_CONSTRUCTION_PORTAL, DATA_THADDIUS,     DOOR_TYPE_PASSAGE,  0           },
    {GO_GOTHIK_ENTRANCE,    DATA_RAZUVIOUS,     DOOR_TYPE_PASSAGE,  0           },
    {GO_GOTHIK_ENTRANCE,    DATA_GOTHIK,        DOOR_TYPE_ROOM,     BOUNDARY_N  },
    {GO_GOTHIK_ESCAPE,      DATA_GOTHIK,        DOOR_TYPE_PASSAGE,  BOUNDARY_S  },
    {GO_HORSEMEN_DOOR,      DATA_GOTHIK,        DOOR_TYPE_PASSAGE,  0           },
    {GO_HORSEMEN_DOOR,      DATA_HORSEMEN,      DOOR_TYPE_ROOM,     BOUNDARY_NE },
    {GO_DEATHKNIGHT_PORTAL, DATA_HORSEMEN,      DOOR_TYPE_PASSAGE,  0           },
    {GO_SAPPHIRON_ESCAPE,   DATA_SAPPHIRON,     DOOR_TYPE_PASSAGE,  BOUNDARY_W  },
    {GO_KELTHUZAD_DOOR,     DATA_KELTHUZAD,     DOOR_TYPE_ROOM,     BOUNDARY_S  },
    {0,                     0,                  DOOR_TYPE_ROOM,     0           },
};

const float HeiganPos[2] = {2796, -3707};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if (y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if (x > -1.0f)
        return 3;

    float slope = y/x;
    for (uint32 i = 0; i < 3; ++i)
        if (slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

Position const KelthuzadPos  = {3749.6799f, -5114.0600f, 142.1150f, 2.932150f};
Position const HorsemenPos   = {2521.4895f, -2953.4926f, 245.5520f, 2.357414f};
Position const ThaddiusPos   = {3514.9255f, -2927.2067f, 302.8355f, 3.052975f};

enum Events
{
    EVENT_TALK        = 1,
    EVENT_DEATH       = 2,
    EVENT_SAPPH1      = 3,
    EVENT_SAPPH2      = 4,
    EVENT_SAPPH3      = 5,
    EVENT_SAPPH4      = 6,
    EVENT_SAPPH5      = 7,
    EVENT_THANE1      = 8,
    EVENT_HORSEMEN1   = 9,
    EVENT_HORSEMEN2   = 10,
    EVENT_HORSEMEN3   = 11,
    EVENT_HORSEMEN4   = 12,
    EVENT_HORSEMEN5   = 13,
    EVENT_HORSEMEN6   = 14,
    EVENT_HORSEMEN7   = 15,
    EVENT_SCREAM      = 16,
    EVENT_CAT         = 17,
};

class instance_naxxramas : public InstanceMapScript
{
    public:
        instance_naxxramas() : InstanceMapScript("instance_naxxramas", 533) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_naxxramas_InstanceMapScript(map);
        }

        struct instance_naxxramas_InstanceMapScript : public InstanceScript
        {
            instance_naxxramas_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTERS);
                LoadDoorData(doorData);
            }
            std::set<uint64> heiganEruptionGUID[4];

            protected:
                uint64 anubrekhanGUID;
                uint64 faerlinaGUID;
                uint64 maexxnaGUID;
                uint64 nothGUID;
                uint64 heiganGUID;
                uint64 loathebGUID;
                uint64 patchwerkGUID;
                uint64 grobbulusGUID;
                uint64 gluthGUID;
                uint64 thaddiusGUID;
                uint64 razuviousGUID;
                uint64 gothikGUID;
                uint64 sapphironGUID;
                uint64 kelthuzadGUID;
                uint64 thaneGUID;
                uint64 ladyGUID;
                uint64 baronGUID;
                uint64 sirGUID;
                uint64 stalaggGUID;
                uint64 feugenGUID;
                uint64 teslaGUID;
                uint64 LichGUID;
                uint64 gothikGateGUID;
                uint64 horsemenChestGUID;
                uint64 kelthuzadTriggerGUID;
                uint64 portalsGUID[4];
                uint64 AracPortalGUID;
                uint64 PlagPortalGUID;
                uint64 MiliPortalGUID;
                uint64 ConsPortalGUID;
                uint64 TeslaFeugenGUID;
                uint64 TeslaStalagGUID;
                uint32 AbominationCount;
                uint8 WingsCleared;
                GOState gothikDoorState;
                time_t minHorsemenDiedTime;
                time_t maxHorsemenDiedTime;
                uint32 playerDied;
                EventMap events;

            void Initialize()
            {
                anubrekhanGUID            = 0;
                faerlinaGUID              = 0;
                maexxnaGUID               = 0;
                nothGUID                  = 0;
                heiganGUID                = 0;
                loathebGUID               = 0;
                patchwerkGUID             = 0;
                grobbulusGUID             = 0;
                gluthGUID                 = 0;
                thaddiusGUID              = 0;
                razuviousGUID             = 0;
                gothikGUID                = 0;
                sapphironGUID             = 0;
                kelthuzadGUID             = 0;
                thaneGUID                 = 0;
                ladyGUID                  = 0;
                baronGUID                 = 0;
                sirGUID                   = 0;
                stalaggGUID               = 0;
                feugenGUID                = 0;
                teslaGUID                 = 0;
                LichGUID                  = 0;
                gothikGateGUID            = 0;
                horsemenChestGUID         = 0;
                kelthuzadTriggerGUID      = 0;
                AracPortalGUID            = 0;
                PlagPortalGUID            = 0;
                MiliPortalGUID            = 0;
                ConsPortalGUID            = 0;
                TeslaFeugenGUID           = 0;
                TeslaStalagGUID           = 0;
                playerDied                = 0;
                WingsCleared              = 0;
                gothikDoorState           = GO_STATE_ACTIVE;
                memset(portalsGUID, 0, sizeof(portalsGUID));
            }

            void OnPlayerEnter(Player* player)
            {
                if (GetBossState(DATA_THADDIUS) != DONE)
                    events.ScheduleEvent(EVENT_SCREAM, 540000);
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case BOSS_ANUBREKHAN:
                        anubrekhanGUID = creature->GetGUID();
                        break;
                    case BOSS_FAERLINA:
                        faerlinaGUID = creature->GetGUID();
                        break;
                    case BOSS_MAEXXNA:
                        maexxnaGUID = creature->GetGUID();
                        break;
                    case BOSS_NOTH:
                        nothGUID = creature->GetGUID();
                        break;
                    case BOSS_HEIGAN:
                        heiganGUID = creature->GetGUID();
                        break;
                    case BOSS_LOATHEB:
                        loathebGUID = creature->GetGUID();
                        break;
                    case BOSS_PATCHWERK:
                        patchwerkGUID = creature->GetGUID();
                        break;
                    case BOSS_GROBBULUS:
                        grobbulusGUID = creature->GetGUID();
                        break;
                    case BOSS_GLUTH:
                        gluthGUID = creature->GetGUID();
                        break;
                    case BOSS_THADDIUS:
                        thaddiusGUID = creature->GetGUID();
                        break;
                    case BOSS_RAZUVIOUS:
                        razuviousGUID = creature->GetGUID();
                        break;
                    case BOSS_GOTHIK:
                        gothikGUID = creature->GetGUID();
                        break;
                    case BOSS_SAPPHIRON:
                        sapphironGUID = creature->GetGUID();
                        break;
                    case BOSS_KELTHUZAD:
                        kelthuzadGUID = creature->GetGUID();
                        break;
                    case BOSS_THANE:
                        thaneGUID = creature->GetGUID();
                        break;
                    case BOSS_LADY:
                        ladyGUID = creature->GetGUID();
                        break;
                    case BOSS_BARON:
                        baronGUID = creature->GetGUID();
                        break;
                    case BOSS_SIR:
                        sirGUID = creature->GetGUID();
                        break;
                    case BOSS_STALAGG:
                        stalaggGUID = creature->GetGUID();
                        break;
                    case BOSS_FEUGEN:
                        feugenGUID = creature->GetGUID();
                        break;
                    case NPC_TESLA:
                        teslaGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
                {
                    uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
                    heiganEruptionGUID[section].insert(go->GetGUID());
                    return;
                }

                switch (go->GetEntry())
                {
                    case GO_GOTHIK_GATE:
                       gothikGateGUID = go->GetGUID();
                       go->SetGoState(gothikDoorState);
                       break;
                    case GO_HORSEMEN_CHEST:
                       horsemenChestGUID = go->GetGUID();
                       break;
                    case GO_HORSEMEN_CHEST_HERO:
                       horsemenChestGUID = go->GetGUID();
                       break;
                    case GO_KELTHUZAD_PORTAL01:
                       portalsGUID[0] = go->GetGUID();
                       break;
                    case GO_KELTHUZAD_PORTAL02:
                       portalsGUID[1] = go->GetGUID();
                       break;
                    case GO_KELTHUZAD_PORTAL03:
                       portalsGUID[2] = go->GetGUID();
                       break;
                    case GO_KELTHUZAD_PORTAL04:
                       portalsGUID[3] = go->GetGUID();
                       break;
                    case GO_KELTHUZAD_TRIGGER:
                       kelthuzadTriggerGUID = go->GetGUID();
                       break;
                    case GO_ARAC_PORTAL:
                       AracPortalGUID = go->GetGUID();
                       if (GetBossState(DATA_MAEXXNA) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                       break;
                    case GO_PLAG_PORTAL:
                       PlagPortalGUID = go->GetGUID();
                       if (GetBossState(DATA_LOATHEB) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                       break;
                    case GO_MILI_PORTAL:
                       MiliPortalGUID = go->GetGUID();
                       if (GetBossState(DATA_HORSEMEN) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                       break;
                    case GO_CONS_PORTAL:
                       ConsPortalGUID = go->GetGUID();
                       if (GetBossState(DATA_THADDIUS) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                       break;
                    case GO_TESLA_FEUGEN:
                       TeslaFeugenGUID = go->GetGUID();
                       if (GetBossState(DATA_THADDIUS) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_STATE_ACTIVE);
                       break;
                    case GO_TESLA_STALAG:
                       TeslaStalagGUID = go->GetGUID();
                       if (GetBossState(DATA_THADDIUS) != DONE)
                           go->SetFlag(GAMEOBJECT_FLAGS, GO_STATE_ACTIVE);
                       break;
                    case GO_ANUBREKHAN_DOOR:
                    case GO_ANUBREKHAN_ESCAPE:
                    case GO_FEARLINA_DOOR_1:
                    case GO_MAEXXNA_DOOR:
                    case GO_NOTH_ENTRANCE:
                    case GO_NOTH_ESCAPE:
                    case GO_HEIGAN_ENTRANCE:
                    case GO_HEIGAN_ESCAPE:
                    case GO_LOATHEB_DOOR:
                    case GO_GROBBULUS_DOOR:
                    case GO_GLUTH_ESCAPE:
                    case GO_THADDIUS_DOOR:
                    case GO_GOTHIK_ENTRANCE:
                    case GO_GOTHIK_ESCAPE:
                    case GO_HORSEMEN_DOOR:
                    case GO_SAPPHIRON_ESCAPE:
                    case GO_KELTHUZAD_DOOR:
                    case GO_PLAGUE_WING_PORTAL:
                    case GO_DEATHKNIGHT_PORTAL:
                    case GO_SPIDER_PORTAL:
                    case GO_CONSTRUCTION_PORTAL:
                       AddDoor(go, true);
                       break;
                    default:
                       break;
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
                {
                    uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
                    heiganEruptionGUID[section].erase(go->GetGUID());
                    return;
                }
                switch (go->GetEntry())
                {
                    case GO_BIRTH:
                        if (sapphironGUID)
                        {
                            if (Creature* pSapphiron = instance->GetCreature(sapphironGUID))
                                pSapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH);
                            return;
                        }
                        break;
                    case GO_ANUBREKHAN_DOOR:
                    case GO_ANUBREKHAN_ESCAPE:
                    case GO_FEARLINA_DOOR_1:
                    case GO_MAEXXNA_DOOR:
                    case GO_NOTH_ENTRANCE:
                    case GO_NOTH_ESCAPE:
                    case GO_HEIGAN_ENTRANCE:
                    case GO_HEIGAN_ESCAPE:
                    case GO_LOATHEB_DOOR:
                    case GO_GROBBULUS_DOOR:
                    case GO_GLUTH_ESCAPE:
                    case GO_THADDIUS_DOOR:
                    case GO_GOTHIK_ENTRANCE:
                    case GO_GOTHIK_ESCAPE:
                    case GO_HORSEMEN_DOOR:
                    case GO_SAPPHIRON_ESCAPE:
                    case GO_KELTHUZAD_DOOR:
                    case GO_PLAGUE_WING_PORTAL:
                    case GO_DEATHKNIGHT_PORTAL:
                    case GO_SPIDER_PORTAL:
                    case GO_CONSTRUCTION_PORTAL:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit)
            {
                if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
                {
                    playerDied = 1;
                    SaveToDB();
                }
                if (unit->GetTypeId() == TYPEID_UNIT && unit->GetEntry() ==NPC_BIGGLESWORTH)
                {
                    if (GetBossState(DATA_KELTHUZAD) != DONE)
                        events.ScheduleEvent(EVENT_CAT, 2000);
                }
            }

            void SetData(uint32 id, uint32 value)
            {
                switch (id)
                {
                    case DATA_HEIGAN_ERUPT:
                        HeiganErupt(value);
                        break;
                    case DATA_GOTHIK_GATE:
                        if (GameObject* gothikGate = instance->GetGameObject(gothikGateGUID))
                            gothikGate->SetGoState(GOState(value));
                        gothikDoorState = GOState(value);
                        break;
                    case DATA_HORSEMEN0:
                    case DATA_HORSEMEN1:
                    case DATA_HORSEMEN2:
                    case DATA_HORSEMEN3:
                        if (value == NOT_STARTED)
                        {
                            minHorsemenDiedTime = 0;
                            maxHorsemenDiedTime = 0;
                        }
                        else if (value == DONE)
                        {
                            time_t now = time(NULL);
                            if (minHorsemenDiedTime == 0)
                                minHorsemenDiedTime = now;
                            maxHorsemenDiedTime = now;
                        }
                        break;
                    case DATA_ABOMINATION_KILLED:
                        AbominationCount = value;
                        break;
                }
            }

            uint32 GetData(uint32 id) const
            {
                switch (id)
                {
                    case DATA_ABOMINATION_KILLED:
                        return AbominationCount;
                    default:
                        break;
                }
                return 0;
            }

            uint64 GetData64(uint32 id) const
            {
                switch (id)
                {
                    case DATA_ANUBREKHAN:
                        return anubrekhanGUID;
                    case DATA_FAERLINA:
                        return faerlinaGUID;
                    case DATA_MAEXXNA:
                        return maexxnaGUID;
                    case DATA_NOTH:
                        return nothGUID;
                    case DATA_HEIGAN:
                        return heiganGUID;
                    case DATA_LOATHEB:
                        return loathebGUID;
                    case DATA_PATCHWERK:
                        return patchwerkGUID;
                    case DATA_GROBBULUS:
                        return grobbulusGUID;
                    case DATA_GLUTH:
                        return gluthGUID;
                    case DATA_THADDIUS:
                        return thaddiusGUID;
                    case DATA_RAZUVIOUS:
                        return razuviousGUID;
                    case DATA_GOTHIK:
                        return gothikGUID;
                    case DATA_SAPPHIRON:
                        return sapphironGUID;
                    case DATA_KELTHUZAD:
                        return kelthuzadGUID;
                    case DATA_THANE:
                        return thaneGUID;
                    case DATA_LADY:
                        return ladyGUID;
                    case DATA_BARON:
                        return baronGUID;
                    case DATA_SIR:
                        return sirGUID;
                    case DATA_STALAGG:
                        return stalaggGUID;
                    case DATA_FEUGEN:
                        return feugenGUID;
                    case DATA_TESLA_TRIGGER:
                        return teslaGUID;
                    case DATA_TESLA_FEUGEN:
                        return TeslaFeugenGUID;
                    case DATA_TESLA_STALAG:
                        return TeslaStalagGUID;
                    case DATA_KELTHUZAD_PORTAL01:
                        return portalsGUID[0];
                    case DATA_KELTHUZAD_PORTAL02:
                        return portalsGUID[1];
                    case DATA_KELTHUZAD_PORTAL03:
                        return portalsGUID[2];
                    case DATA_KELTHUZAD_PORTAL04:
                        return portalsGUID[3];
                    case DATA_KELTHUZAD_TRIGGER:
                        return kelthuzadTriggerGUID;
                }
                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HORSEMEN:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_KELTHUZAD) != DONE)
                            {
                                WingsCleared ++;
                                events.ScheduleEvent(EVENT_TALK, 6000);
                            }
                            if (GameObject* MiliPortal = instance->GetGameObject(MiliPortalGUID))
                            {
                                MiliPortal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                HandleGameObject(MiliPortalGUID, true, MiliPortal);
                            }
                            if (GameObject* pHorsemenChest = instance->GetGameObject(horsemenChestGUID))
                                pHorsemenChest->SetRespawnTime(pHorsemenChest->GetRespawnDelay());
                        }
                        break;
                    case DATA_THADDIUS:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_KELTHUZAD) != DONE)
                            {
                                WingsCleared ++;
                                events.ScheduleEvent(EVENT_TALK, 6000);
                            }
                            if (GameObject* ConsPortal = instance->GetGameObject(ConsPortalGUID))
                            {
                                ConsPortal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                HandleGameObject(ConsPortalGUID, true, ConsPortal);
                            }
                            events.CancelEvent(EVENT_SCREAM);
                        }
                        break;
                    case DATA_LOATHEB:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_KELTHUZAD) != DONE)
                            {
                                WingsCleared ++;
                                events.ScheduleEvent(EVENT_TALK, 6000);
                            }
                            if (GameObject* PlagPortal = instance->GetGameObject(PlagPortalGUID))
                            {
                                PlagPortal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                HandleGameObject(PlagPortalGUID, true, PlagPortal);
                            }
                        }
                        break;
                    case DATA_MAEXXNA:
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_KELTHUZAD) != DONE)
                            {
                                WingsCleared ++;
                                events.ScheduleEvent(EVENT_TALK, 6000);
                            }
                            if (GameObject* AracPortal = instance->GetGameObject(AracPortalGUID))
                            {
                                AracPortal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                HandleGameObject(AracPortalGUID, true, AracPortal);
                            }
                        }
                        break;
                    case DATA_SAPPHIRON:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_SAPPH1, 8000);
                        break;
                    case DATA_GOTHIK:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_THANE1, 10000);
                        break;
                }

                return true;
            }

            void Update (uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAT:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                KelThuzad->AI()->TalkToMap(SAY_CAT_DIED);
                            break;
                        case EVENT_TALK:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            switch(WingsCleared)
                            {
                                case 1:
                                    if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                        KelThuzad->AI()->TalkToMap(SAY_TAUNT1);
                                    break;
                                case 2:
                                    if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                        KelThuzad->AI()->TalkToMap(SAY_TAUNT2);
                                    break;
                                case 3:
                                    if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                        KelThuzad->AI()->TalkToMap(SAY_TAUNT3);
                                    break;
                                case 4:
                                    if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                        KelThuzad->AI()->TalkToMap(SAY_TAUNT4);
                                    break;
                            }
                            break;
                        case EVENT_SAPPH1:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                            {
                                KelThuzad->AI()->TalkToMap(SAY_SAPP_DIALOG1);
                                if (Creature* Lich = KelThuzad->SummonCreature(28765,  KelthuzadPos, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    LichGUID = Lich->GetGUID();
                                    Lich->SetDisplayId(11686);
                                }
                            }
                            events.ScheduleEvent(EVENT_SAPPH2, 6000);
                            break;
                        case EVENT_SAPPH2:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* Lich = instance->GetCreature(LichGUID))
                                Lich->AI()->TalkToMap(SAY_SAPP_DIALOG2_LICH);
                            events.ScheduleEvent(EVENT_SAPPH3, 16000);
                            break;
                        case EVENT_SAPPH3:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                KelThuzad->AI()->TalkToMap(SAY_SAPP_DIALOG3);
                            events.ScheduleEvent(EVENT_SAPPH4, 9000);
                            break;
                        case EVENT_SAPPH4:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* Lich = instance->GetCreature(LichGUID))
                                Lich->AI()->TalkToMap(SAY_SAPP_DIALOG4_LICH);
                            events.ScheduleEvent(EVENT_SAPPH5, 10000);
                            break;
                        case EVENT_SAPPH5:
                            instance->LoadGrid(KelthuzadPos.GetPositionX(), KelthuzadPos.GetPositionY());
                            if (Creature* KelThuzad = instance->GetCreature(kelthuzadGUID))
                                KelThuzad->AI()->TalkToMap(SAY_SAPP_DIALOG5);
                            if (Creature* Lich = instance->GetCreature(LichGUID))
                            {
                                Lich->DisappearAndDie();
                                LichGUID = 0;
                            }
                            break;
                        case EVENT_THANE1:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Thane = instance->GetCreature(thaneGUID))
                                Thane->AI()->TalkToMap(SAY_KORT_TAUNT1);
                            events.ScheduleEvent(EVENT_HORSEMEN1, 6000);
                            break;
                        case EVENT_HORSEMEN1:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Sir = instance->GetCreature(sirGUID))
                                Sir->AI()->TalkToMap(SAY_HORSEMEN_1);
                            events.ScheduleEvent(EVENT_HORSEMEN2, 7000);
                            break;
                        case EVENT_HORSEMEN2:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Lady = instance->GetCreature(ladyGUID))
                                Lady->AI()->TalkToMap(SAY_HORSEMEN_2);
                            events.ScheduleEvent(EVENT_HORSEMEN3, 7000);
                            break;
                        case EVENT_HORSEMEN3:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Baron = instance->GetCreature(baronGUID))
                                Baron->AI()->TalkToMap(SAY_HORSEMEN_3);
                            events.ScheduleEvent(EVENT_HORSEMEN4, 7000);
                            break;
                        case EVENT_HORSEMEN4:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Lady = instance->GetCreature(ladyGUID))
                                Lady->AI()->TalkToMap(SAY_HORSEMEN_4);
                            events.ScheduleEvent(EVENT_HORSEMEN5, 6000);
                            break;
                        case EVENT_HORSEMEN5:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Sir = instance->GetCreature(sirGUID))
                                Sir->AI()->TalkToMap(SAY_HORSEMEN_5);
                            events.ScheduleEvent(EVENT_HORSEMEN6, 6000);
                            break;
                        case EVENT_HORSEMEN6:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Thane = instance->GetCreature(thaneGUID))
                                Thane->AI()->TalkToMap(SAY_HORSEMEN_6);
                            events.ScheduleEvent(EVENT_HORSEMEN7, 6000);
                            break;
                        case EVENT_HORSEMEN7:
                            instance->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
                            if (Creature* Baron = instance->GetCreature(baronGUID))
                                Baron->AI()->TalkToMap(SAY_HORSEMEN_7);
                            break;
                        case EVENT_SCREAM:
                            instance->LoadGrid(ThaddiusPos.GetPositionX(), ThaddiusPos.GetPositionY());
                            switch (urand(0,3))
                            {
                                case 0:
                                    if (Creature* Thaddius = instance->GetCreature(thaddiusGUID))
                                        sCreatureTextMgr->SendSound(Thaddius, 8873, CHAT_MSG_MONSTER_YELL, 0, TEXT_RANGE_MAP, TEAM_OTHER, false);
                                    break;
                                case 1:
                                    if (Creature* Thaddius = instance->GetCreature(thaddiusGUID))
                                        sCreatureTextMgr->SendSound(Thaddius, 8874, CHAT_MSG_MONSTER_YELL, 0, TEXT_RANGE_MAP, TEAM_OTHER, false);
                                    break;
                                case 2:
                                    if (Creature* Thaddius = instance->GetCreature(thaddiusGUID))
                                        sCreatureTextMgr->SendSound(Thaddius, 8875, CHAT_MSG_MONSTER_YELL, 0, TEXT_RANGE_MAP, TEAM_OTHER, false);
                                    break;
                                case 3:
                                    if (Creature* Thaddius = instance->GetCreature(thaddiusGUID))
                                        sCreatureTextMgr->SendSound(Thaddius, 8876, CHAT_MSG_MONSTER_YELL, 0, TEXT_RANGE_MAP, TEAM_OTHER, false);
                                    break;
                            }
                            events.ScheduleEvent(EVENT_SCREAM, 600000);
                            break;
                        default:
                            break;
                    }
                }
            }

            void HeiganErupt(uint32 section)
            {
                for (uint32 i = 0; i < 4; ++i)
                {
                    if (i == section)
                        continue;
                    for (std::set<uint64>::const_iterator itr = heiganEruptionGUID[i].begin(); itr != heiganEruptionGUID[i].end(); ++itr)
                    {
                        if (GameObject* pHeiganEruption = instance->GetGameObject(*itr))
                        {
                            pHeiganEruption->SendCustomAnim(pHeiganEruption->GetGoAnimProgress());
                            pHeiganEruption->CastSpell(NULL, SPELL_ERUPTION);
                        }
                    }
                }
            }

            bool AreAllEncoutersDone()
            {
                uint32 numBossAlive = 0;
                for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    if (GetBossState(i) != DONE)
                        numBossAlive++;
                if (numBossAlive > 1)
                    return false;
                return true;
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/)
            {
                switch (criteria_id)
                {
                    case 7600:
                        if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                            return true;
                        return false;
                    case 7601:
                        if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_25MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                            return true;
                        return false;
                    case 13233:
                    case 13234:
                    case 13235:
                    case 13236:
                    case 7616:
                    case 13237:
                    case 13238:
                    case 13239:
                    case 13240:
                    case 7617:
                        if (AreAllEncoutersDone() && !playerDied)
                            return true;
                        return false;
                }
                return false;
            }

            std::string GetSaveData()
            {
                std::ostringstream saveStream;
                saveStream << GetBossSaveData() << gothikDoorState << ' ' << playerDied;
                return saveStream.str();
            }

            void Load(const char * data)
            {
                std::istringstream loadStream(LoadBossState(data));
                uint32 temp, buff, buff2;
            for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    loadStream >> temp;
                loadStream >> buff;
                gothikDoorState = GOState(buff);
                loadStream >> buff2;
                playerDied = buff2;
            }
        };
};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
}
