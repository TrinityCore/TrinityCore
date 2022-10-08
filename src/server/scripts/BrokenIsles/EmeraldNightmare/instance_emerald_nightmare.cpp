/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "Creature.h"
#include "emerald_nightmare.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

DoorData const doorData[] =
{
    {GO_NYTHENDRA_DOOR_1,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_2,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_3,       DATA_NYTHENDRA,         DOOR_TYPE_ROOM},
    {GO_NYTHENDRA_DOOR_4,       DATA_NYTHENDRA,         DOOR_TYPE_ROOM},
    {GO_NYTHENDRA_DOOR_5,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_6,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_RENFERAL_DOOR,          DATA_RENFERAL,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_1,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_2,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_3,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_URSOC_DOOR_1,           DATA_URSOC,             DOOR_TYPE_ROOM},
    {GO_URSOC_DOOR_2,           DATA_URSOC,             DOOR_TYPE_ROOM},
};

ObjectData const creatureData[] =
{
    {NPC_NYTHENDRA,         NPC_NYTHENDRA},
    {NPC_YSONDRE,           NPC_YSONDRE},
    {NPC_LETHON,            NPC_LETHON},
    {NPC_XAVIUS,            NPC_XAVIUS},
    {0,                     0} // END
};

ObjectData const gobjectData[] =
{
    {GO_CENARIUS_CHEST,     GO_CENARIUS_CHEST},
    {0,                     0 } // END
};

class instance_the_emerald_nightmare : public InstanceMapScript
{
public:
    instance_the_emerald_nightmare() : InstanceMapScript("instance_the_emerald_nightmare", 1520) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_emerald_nightmare_InstanceMapScript(map);
    }

    struct instance_the_emerald_nightmare_InstanceMapScript : public InstanceScript
    {
        instance_the_emerald_nightmare_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }
//        {
//            SetBossNumber(MAX_ENCOUNTER);
 //       }

        std::map<uint32, ObjectGuid> eggGUIDconteiner;
        ObjectGuid IlgynothDoorGUID;
        ObjectGuid cenariusPortalGUID;

        uint32 cenariusActivatePortalTimer;

        WorldLocation loc_res_pla;  // for respawn

        void Initialize() override
        {
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gobjectData);

            IlgynothDoorGUID.Clear();
            cenariusPortalGUID.Clear();

            cenariusActivatePortalTimer = 5000;

            if (GetBossState(DATA_XAVIUS) != DONE)
                SetBossState(DATA_PRE_EVENT_XAVIUS, NOT_STARTED); // Reset event
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetBossState(DATA_XAVIUS) == IN_PROGRESS)
                player->CastSpell(player, 189960, true); //Alter power
        }

    /*    WorldSafeLocsEntry const* GetClosestGraveYard(float x, float y, float z) override
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1520);

            uint32 graveyardId = 0;

            if (GetBossState(DATA_NYTHENDRA) != DONE ||
                (x >= 1066.98f && y <= 2133.02f && x <= 2666.36f && y >= 533.64f)) // zone around first boss
                graveyardId = 5533;
            else if (GetBossState(DATA_CENARIUS) != DONE)
                graveyardId = 5681;
            else
                graveyardId = 5692;

            if (graveyardId)
            {
                if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
                {
                    loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                    loc_res_pla.SetMapId(gy->MapID);
                }
            }
            return &loc_res_pla;
        }
        */
        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_YSONDRE:
            case NPC_TAERAR:
            case NPC_LETHON:
            case NPC_EMERISS:
               // AddToDamageManager(creature);
                break;
            case NPC_SURGING_EGG_SAC:
                eggGUIDconteiner[creature->GetEntry()] = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_NYTHENDRA_DOOR_1:
            case GO_NYTHENDRA_DOOR_2:
            case GO_NYTHENDRA_DOOR_3:
            case GO_NYTHENDRA_DOOR_4:
            case GO_NYTHENDRA_DOOR_5:
            case GO_NYTHENDRA_DOOR_6:
            case GO_RENFERAL_DOOR:
            case GO_ILGYNOTH_DOOR_1:
            case GO_ILGYNOTH_DOOR_2:
            case GO_ILGYNOTH_DOOR_3:
            case GO_URSOC_DOOR_1:
            case GO_URSOC_DOOR_2:
                AddDoor(go, true);
                break;
            case GO_EYE_OF_ILGYNOTH_DOOR:
                IlgynothDoorGUID = go->GetGUID();
                break;
            case GO_CENARIUS_PORTAL:
                cenariusPortalGUID = go->GetGUID();
                go->AddFlag(GO_FLAG_NOT_SELECTABLE);
                break;
            default:
                break;
            }
        }

        void CreatureDies(Creature* creature, Unit* /*killer*/)// override
        {
            // Dragons of Nightmare: Corruption of the Dream
            if (instance->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || instance->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            {
                auto ysondre = instance->GetCreature(GetGuidData(NPC_YSONDRE));
                if (!ysondre)
                    return;

                switch (creature->GetEntry())
                {
                case NPC_DREAD_HORROR:
                    creature->CastSpell(creature, 204008, true, 0, 0, ysondre->GetGUID());
                    break;
                case NPC_ESSENCE_OF_CORRUPTION:
                case NPC_SPIRIT_SHADE:
                    creature->CastSpell(creature, 204009, true, 0, 0, ysondre->GetGUID());
                    break;
                case NPC_SHADE_OF_TAERAR:
                    creature->CastSpell(creature, 204010, true, 0, 0, ysondre->GetGUID());
                    break;
                }
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_RENFERAL:
            {
                switch (state)
                {
                case IN_PROGRESS:
                    for (auto itr : eggGUIDconteiner)
                        if (auto egg = instance->GetCreature(itr.second))
                            if (!egg->IsAlive())
                                egg->Respawn();
                    break;
                }
                break;
            }
            case DATA_CENARIUS:
            {
                if (state == DONE)
                    if (auto chest = instance->GetGameObject(GetGuidData(GO_CENARIUS_CHEST)))
                        chest->SetRespawnTime(604800);
                break;
            }
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_EYE_ILGYNOTH:
                if (data == IN_PROGRESS)
                    HandleGameObject(IlgynothDoorGUID, false);
                if (data == DONE)
                    HandleGameObject(IlgynothDoorGUID, true);
                break;
            default:
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            return InstanceScript::GetGuidData(type);
        }

        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

        void Update(uint32 diff) override
        {
            if (cenariusActivatePortalTimer)
            {
                if (cenariusActivatePortalTimer <= diff)
                {
                    cenariusActivatePortalTimer = 5000;
                    if (CheckFirstBosses())
                    {
                        if (GameObject* go = instance->GetGameObject(cenariusPortalGUID))
                        {
                            cenariusActivatePortalTimer = 0;
                            go->SetAnimKitId(3761, false);
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                }
                else cenariusActivatePortalTimer -= diff;
            }
        }

        std::string GetSaveData() override
        {
            std::ostringstream saveStream;
           // saveStream << "E N " << GetBossSaveData();
            return saveStream.str();
        }

        void Load(const char* data) override
        {
            if (!data)
            {
             //   OUT_LOAD_INST_DATA_FAIL;
                return;
            }

           // OUT_LOAD_INST_DATA(data);

            char dataHead1, dataHead2;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'E' && dataHead2 == 'N')
            {
                for (uint32 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            }
           // else
           //     OUT_LOAD_INST_DATA_FAIL;

          //  OUT_LOAD_INST_DATA_COMPLETE;

        }

        bool CheckFirstBosses()
        {
            if (GetBossState(DATA_NYTHENDRA) == DONE &&
                GetBossState(DATA_RENFERAL) == DONE && GetBossState(DATA_ILGYNOTH) == DONE &&
                GetBossState(DATA_URSOC) == DONE && GetBossState(DATA_DRAGON_NIGHTMARE) == DONE)
                return true;
            else
                return false;
        }
    };
};


void AddSC_instance_emerald_nightmare()
{
    new instance_the_emerald_nightmare();
}
