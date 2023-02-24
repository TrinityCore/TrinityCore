/*
 * Copyright 2023 AzgathCore
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

#include "Group.h"
#include "halls_of_valor.h"
#include "WorldPacket.h"
#include "InstancePackets.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "player.h"
#include "Map.h"


DoorData const doorData[] =
{
    {GO_HYMDALL_ENTER_DOOR,         DATA_HYMDALL,         DOOR_TYPE_ROOM},
    {GO_HYMDALL_EXIT_DOOR,          DATA_HYMDALL,         DOOR_TYPE_PASSAGE},
    {GO_HYRJA_DOOR,                 DATA_HYRJA,           DOOR_TYPE_ROOM},
    {GO_GATES_OF_GLORY_DOOR,        DATA_HYRJA,           DOOR_TYPE_PASSAGE},
    {GO_GATES_OF_GLORY_DOOR,        DATA_FENRYR,          DOOR_TYPE_PASSAGE},
    {GO_ODYN_AND_SKOVALD_DOOR,      DATA_SKOVALD,         DOOR_TYPE_ROOM},
    {GO_ODYN_AND_SKOVALD_DOOR,      DATA_ODYN,            DOOR_TYPE_ROOM},
};

class instance_halls_of_valor : public InstanceMapScript
{
public:
    instance_halls_of_valor() : InstanceMapScript("instance_halls_of_valor", 1477) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_halls_of_valor_InstanceMapScript(map);
    }

    struct instance_halls_of_valor_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_valor_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        WorldLocation loc_res_pla;

        ObjectGuid HymdallChestGUID;
        ObjectGuid hyrjaGUID;
        ObjectGuid feryrGUID;
        ObjectGuid skovaldGUID;
        ObjectGuid aegisGUID;
        ObjectGuid OdynGUID;
        ObjectGuid OdynChestGUID;
        ObjectGuid HymdallGUID;

        std::map<uint32, ObjectGuid> runicBrandGUIDconteiner;

        bool StartEvent;
        uint32 fenryrEventDone;
        uint32 skovaldEventDone;
        uint32 PlayerCount;
        uint32 GoRunicColour[5];
        uint32 checkTimer = 1000;
        uint32 checkTimerAura = 1000;

        void Initialize() override
        {
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doorData);

            StartEvent = false;
            PlayerCount = 0;
            fenryrEventDone = 0;
            skovaldEventDone = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_HYRJA:
                hyrjaGUID = creature->GetGUID();
                break;
            case NPC_BOSS_FENRYR:
                feryrGUID = creature->GetGUID();
                break;
            case NPC_GOD_KING_SKOVALD:
                skovaldGUID = creature->GetGUID();
                break;
            case NPC_AEGIS_OF_AGGRAMAR:
                aegisGUID = creature->GetGUID();
                break;
            case NPC_ODYN:
                OdynGUID = creature->GetGUID();
                break;
            case NPC_HYMDALL:
                HymdallGUID = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_HYMDALL_ENTER_DOOR:
            case GO_HYMDALL_EXIT_DOOR:
            case GO_HYRJA_DOOR:
            case GO_GATES_OF_GLORY_DOOR:
            case GO_ODYN_AND_SKOVALD_DOOR:
                AddDoor(go, true);
                break;
            case GO_HYMDALL_CHEST:
                HymdallChestGUID = go->GetGUID();
                break;
            case GO_ODYN_CHEST:
                OdynChestGUID = go->GetGUID();
                break;
            case GO_RUNIC_BRAND_PURE:
                GoRunicColour[0] = go->GetEntry();
                runicBrandGUIDconteiner[go->GetEntry()] = go->GetGUID();
                break;
            case GO_RUNIC_BRAND_RED:
                GoRunicColour[1] = go->GetEntry();
                runicBrandGUIDconteiner[go->GetEntry()] = go->GetGUID();
                break;
            case GO_RUNIC_BRAND_YELLOW:
                GoRunicColour[2] = go->GetEntry();
                runicBrandGUIDconteiner[go->GetEntry()] = go->GetGUID();
                break;
            case GO_RUNIC_BRAND_BLUE:
                GoRunicColour[3] = go->GetEntry();
                runicBrandGUIDconteiner[go->GetEntry()] = go->GetGUID();
                break;
            case GO_RUNIC_BRAND_GREEN:
                GoRunicColour[4] = go->GetEntry();
                runicBrandGUIDconteiner[go->GetEntry()] = go->GetGUID();
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_HYMDALL:
                if (state == DONE)
                {
                    if (instance->GetDifficultyID() != DIFFICULTY_MYTHIC_KEYSTONE)
                        if (GameObject* chest = instance->GetGameObject(HymdallChestGUID))
                            chest->SetRespawnTime(86400);

                    DoOnPlayers([this](Player* player)
                    {
                        instance->ToInstanceMap()->PermBindAllPlayers();
                     //   player->getHostileRefManager().deleteReferences();
                    });
                }
                break;
            case DATA_SKOVALD:
            {
                if (state != IN_PROGRESS)
                    if (Creature* aegis = instance->GetCreature(aegisGUID))
                        aegis->DespawnOrUnsummon();
                if (state == DONE)
                    if (Creature* odyn = instance->GetCreature(OdynGUID))
                        odyn->AI()->DoAction(true);
                break;
            }
            case DATA_ODYN:
            {
                if (state != IN_PROGRESS)
                    for (uint8 i = 0; i < 5; i++)
                        if (GameObject* rune = instance->GetGameObject(runicBrandGUIDconteiner[GoRunicColour[i]]))
                            rune->SetGoState(GO_STATE_READY);
                if (state == DONE)
                {
                    if (instance->GetDifficultyID() != DIFFICULTY_MYTHIC_KEYSTONE)
                        if (GameObject* chest = instance->GetGameObject(OdynChestGUID))
                            chest->SetRespawnTime(86400);

                    instance->SummonCreature(NPC_SPOILS_CHEST_VISUAL, spoilsPos);
                    DoOnPlayers([this](Player* player)
                    {
                        instance->ToInstanceMap()->PermBindAllPlayers();
                       // player->getHostileRefManager().deleteReferences();
                    });
                }
                break;
            }
            default:
                break;
            }

            if (type == DATA_HYRJA || type == DATA_FENRYR)
                if (GetBossState(DATA_HYRJA) == DONE && GetBossState(DATA_FENRYR) == DONE)
                    DoCastSpellOnPlayers(202160); //Odyn's Blessing - Speed buff

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_FENRYR_EVENT:
            {
                fenryrEventDone = data;
                if (data == DONE)
                {
                    if (Creature* fen = instance->GetCreature(feryrGUID))
                    {
                        fen->SetVisible(true);
                        fen->SetReactState(REACT_AGGRESSIVE);
                    }
                    SaveToDB();
                }
                break;
            }
            case DATA_SKOVALD_EVENT:
                skovaldEventDone = data;
                if (data == DONE)
                    SaveToDB();
                break;
            case DATA_RUNES_ACTIVATED:
                if (GameObject* rune = instance->GetGameObject(runicBrandGUIDconteiner[GoRunicColour[data]]))
                    rune->SetGoState(GO_STATE_ACTIVE);
                break;
            case DATA_RUNES_DEACTIVATED:
                if (GameObject* rune = instance->GetGameObject(runicBrandGUIDconteiner[GoRunicColour[data]]))
                    rune->SetGoState(GO_STATE_READY);
                if (Creature* odyn = instance->GetCreature(OdynGUID))
                    odyn->AI()->SetData(1, data);
                break;
            default:
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_HYRJA:
                return hyrjaGUID;
            case DATA_SKOVALD:
                return skovaldGUID;
            case DATA_ODYN:
                return OdynGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_FENRYR_EVENT:
                return fenryrEventDone;
            case DATA_SKOVALD_EVENT:
                return skovaldEventDone;
            }
            return 0;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!StartEvent)
            {
                if (PlayerCount < 5)
                {
                    PlayerCount++;
                }
                else
                {
                    StartEvent = true;
                    if (Group* g = player->GetGroup())
                        if (Player* leader = ObjectAccessor::GetPlayer(*player, g->GetLeaderGUID()))
                            leader->CastSpell(leader, 202036);
                }
            }
        }

        void Update(uint32 diff) override
        {
            if (checkTimer <= diff)
            {
                checkTimer = 1000;

                DoOnPlayers([](Player* player)
                {
                    if (player->GetAreaId() == 7672)
                    {
                        if (player->GetPositionZ() <= 600.00f)
                        {
                            Unit::Kill(player, player);
                            player->RepopAtGraveyard();
                        }
                    }
                });
            }
            else
                checkTimer -= diff;

            if (checkTimerAura <= diff)
            {
                checkTimerAura = 1000;

                DoOnPlayers([](Player* player)
                {
                    if (player->GetAreaId() == 7672 && player->HasAura(192635))
                        if (player->GetPositionX() <= 2590.00f || player->GetPositionX() >= 3175.61f)
                            player->RemoveAura(192635);
                });
            }
            else
                checkTimerAura -= diff;
        }


        void Load(const char* in) override
        {

            char dataHead1, dataHead2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'H' && dataHead2 == 'V')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }

                loadStream >> fenryrEventDone;
                loadStream >> skovaldEventDone;

            }
        }

    };
};

void AddSC_instance_halls_of_valor()
{
    new instance_halls_of_valor();
}
