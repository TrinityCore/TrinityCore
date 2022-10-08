/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "InstanceScript.h"
#include "vault_of_the_wardens.h"

DoorData const doorData[] =
{
    {GO_SALTHERIL_DOOR_1,       DATA_SALTHERIL,        DOOR_TYPE_ROOM},
    {GO_SALTHERIL_DOOR_2,       DATA_SALTHERIL,        DOOR_TYPE_PASSAGE},
    {GO_SALTHERIL_DOOR_3,       DATA_SALTHERIL,        DOOR_TYPE_PASSAGE},
    {GO_SALTHERIL_DOOR_4,       DATA_SALTHERIL,        DOOR_TYPE_PASSAGE},
    {GO_SALTHERIL_DOOR_5,       DATA_SALTHERIL,        DOOR_TYPE_PASSAGE},
    {GO_TORMENTORUM_DOOR_1,     DATA_TORMENTORUM,      DOOR_TYPE_PASSAGE},
    {GO_ASHGOLM_PLATFORM,       DATA_ASHGOLM,          DOOR_TYPE_ROOM},
    {GO_ASHGOLM_BRIDGE,         DATA_ASHGOLM,          DOOR_TYPE_SPAWN_HOLE},
    {GO_GLAZER_BRIDGE,          DATA_GLAZER,           DOOR_TYPE_SPAWN_HOLE},
    {GO_CORDANA_DOOR,           DATA_CORDANA_SPIRIT,   DOOR_TYPE_PASSAGE},
};

class instance_vault_of_the_wardens : public InstanceMapScript
{
public:
    instance_vault_of_the_wardens() : InstanceMapScript("instance_vault_of_the_wardens", 1493) { }

    struct instance_vault_of_the_wardens_InstanceMapScript : public InstanceScript
    {
        instance_vault_of_the_wardens_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }


        WorldLocation loc_res_pla;
        std::map<uint32, ObjectGuid> tormCageContainer;
        std::list<ObjectGuid> ashSysContainer;
        std::list<ObjectGuid> elunesContainer;
        std::list<ObjectGuid> centryContainer;

        void Initialize() override
        {
            LoadDoorData(doorData);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_COUNTERMEASURES:
                ashSysContainer.push_back(creature->GetGUID());
                break;
            case NPC_ELUNES:
                elunesContainer.push_back(creature->GetGUID());
                break;
            case NPC_GLOWING_SENTRY:
                centryContainer.push_back(creature->GetGUID());
                break;
            }
        }

      /*  void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_SALTHERIL_DOOR_1:
            case GO_SALTHERIL_DOOR_2:
            case GO_SALTHERIL_DOOR_3:
            case GO_SALTHERIL_DOOR_4:
            case GO_SALTHERIL_DOOR_5:
            case GO_TORMENTORUM_DOOR_1:
            case GO_ASHGOLM_PLATFORM:
            case GO_ASHGOLM_BRIDGE:
            case GO_GLAZER_BRIDGE:
            case GO_CORDANA_DOOR:
                AddDoor(go, true);
                break;
            default:
                break;
            }

            if (go->GetEntry() >= GO_CAGE_1 && go->GetEntry() <= GO_CAGE_12)
                tormCageContainer[go->GetEntry()] = go->GetGUID();
        }
*/
        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_TORMENTORUM:
            {
                if (state == NOT_STARTED)
                {
                   // for (std::map<uint32, ObjectGuid>::iterator itr = tormCageContainer.begin(); itr != tormCageContainer.end(); ++itr)
                      //  if (GameObject* cage = instance->GetGameObject(itr->second))
                          //  cage->SetGoState(GO_STATE_READY);
                }
                break;
            }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_ASHGOLM_SYSTEM:
            {
                if (data == DONE)
                {
                    for (std::list<ObjectGuid>::iterator itr = ashSysContainer.begin(); itr != ashSysContainer.end(); ++itr)
                        if (Creature* system = instance->GetCreature(*itr))
                            system->SetVisible(false);
                }
                if (data == SPECIAL)
                {
                    for (std::list<ObjectGuid>::iterator itr = ashSysContainer.begin(); itr != ashSysContainer.end(); ++itr)
                        if (Creature* system = instance->GetCreature(*itr))
                            system->SetVisible(true);
                }
                if (data == IN_PROGRESS)
                {
                    for (std::list<ObjectGuid>::iterator itr = ashSysContainer.begin(); itr != ashSysContainer.end(); ++itr)
                        if (Creature* system = instance->GetCreature(*itr))
                            system->AI()->DoAction(true);
                }
                break;
            }
            case DATA_CORDANA_ACTIONS:
            {
                switch (data)
                {
                case 1:
                {
                    while (!elunesContainer.empty())
                    {
                        auto itr = elunesContainer.front();
                        if (Creature* npc = instance->GetCreature(itr))
                            npc->DespawnOrUnsummon();
                        elunesContainer.pop_front();
                    }
                    break;
                }
                case 2:
                {
                    if (centryContainer.empty())
                        break;

                    for (auto guid : centryContainer)
                        if (Creature* npc = instance->GetCreature(guid))
                        {
                            npc->RemoveAurasDueToSpell(197897);
                            npc->RemoveAurasDueToSpell(204294);
                        }
                    break;
                }

                default:
                    break;
                }
                break;
            }
            default:
                break;
            }
      //  }

        /* ObjectGuid GetGuidData(uint32 type) const
        {
            switch (type)
            {
                case NPC_:
                    return GUID;
            }
            return ObjectGuid::Empty;
        } */

      //  uint32 GetData(uint32 type) const override
      //  {
       //     /* switch (type)
        //    {
         //       case 0:
         //           return 0;
         //   } */
        //    return 0;
     //   }

      //  WorldLocation* GetClosestGraveYard(float x, float y, float z) override
       // {
          //  loc_res_pla.Relocate(x, y, z);
         //   loc_res_pla.SetMapId(1493);

          //  uint32 graveyardId = 5105;

          //  if (GetBossState(DATA_ASHGOLM) == DONE && GetBossState(DATA_TORMENTORUM) == DONE && GetBossState(DATA_GLAZER) == DONE && GetBossState(DATA_CORDANA_SPIRIT) == DONE)
           //     graveyardId = 5112;
          //  else if (GetBossState(DATA_ASHGOLM) == DONE)
            //    graveyardId = 5108;
           // else if (GetBossState(DATA_TORMENTORUM) == DONE)
            //    graveyardId = 5107;
          //  else if (GetBossState(DATA_SALTHERIL) == DONE)
         //   //    graveyardId = 5106;

          //  if (graveyardId)
           // {
              //  if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
               // {
                 //   loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                 //   loc_res_pla.SetMapId(gy->MapID);
           //     }
            }
           // return &loc_res_pla;
      //  }

        /* void Update(uint32 diff)
        {
            // Challenge
         */   //InstanceScript::Update(diff);
     //   } 
    };
};

void AddSC_instance_vault_of_the_wardens()
{
    new instance_vault_of_the_wardens();
}
