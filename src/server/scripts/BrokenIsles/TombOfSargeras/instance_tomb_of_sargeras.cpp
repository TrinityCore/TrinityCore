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
#include "tomb_of_sargeras.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"


DoorData const doorData[] =
{
    //{269164,                    DATA_GOROTH,                DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {268514,                    DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {268580,                    DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {GO_GOROTH_GATES,           DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {269975,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    {269974,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    {269973,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    { GO_INTRODESTROY_2,        DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {269120,                    DATA_HARJATAN,              DOOR_TYPE_PASSAGE},
    {269192,                    DATA_HARJATAN,              DOOR_TYPE_ROOM},
    {GO_SASSZINE_DOOR,          DATA_MISTRESS_SASSZINE,     DOOR_TYPE_ROOM},
    {GO_INQUISITION_DOOR,       DATA_DEMONIC_INQUISITION,   DOOR_TYPE_ROOM},
    {GO_HAMMER_THRONE,          DATA_DEMONIC_INQUISITION,   DOOR_TYPE_PASSAGE},
    {GO_ELUNES_THRONE,          DATA_THE_DESOLATE_HOST,     DOOR_TYPE_PASSAGE},
    {GO_GOLGANETH_THRONE,       DATA_MISTRESS_SASSZINE,     DOOR_TYPE_PASSAGE},
    {GO_MAIDEN_DOOR,            DATA_MAIDEN_OF_VIGILANCE,   DOOR_TYPE_ROOM},
    {GO_SISTERS_MOON_DOOR,      DATA_SISTERS_OF_THEMOON,    DOOR_TYPE_ROOM},
    {GO_AVATARA_DOOR,           DATA_FALLEN_AVATAR,         DOOR_TYPE_ROOM},
    {GO_DESOLATE_HOST_DOOR_1,   DATA_THE_DESOLATE_HOST,     DOOR_TYPE_ROOM},
    {GO_DESOLATE_HOST_DOOR_2,   DATA_THE_DESOLATE_HOST,     DOOR_TYPE_ROOM},
    {0,                         0,                          DOOR_TYPE_ROOM} // END
};

ObjectData const creatureData[] =
{
    {NPC_BREACH_IN_WINDOW,      NPC_BREACH_IN_WINDOW},

    {NPC_KHADGAR,               NPC_KHADGAR},
    {NPC_VELEN,                 NPC_VELEN},
    {NPC_ILLIDAN,               NPC_ILLIDAN},
    {NPC_MAEIV,                 NPC_MAEIV},
    {NPC_DURGAN,                NPC_DURGAN},
    {NPC_ATRIGAN_MISC,          NPC_ATRIGAN_MISC},

    {NPC_EVENT_1,               NPC_EVENT_1},
    {NPC_EVENT_2,               NPC_EVENT_2},
    {NPC_SASSZINE_MISC,         NPC_SASSZINE_MISC},

    {NPC_GOROTH,                DATA_GOROTH},
    {NPC_SASSZINE,              DATA_MISTRESS_SASSZINE},
    {NPC_MOON_STALKER,          DATA_SISTERS_OF_THEMOON},
    {NPC_HUNTRESS_KASPARIAN,    NPC_HUNTRESS_KASPARIAN},
    {NPC_PRIESTESS_LUNASPYRE,   NPC_PRIESTESS_LUNASPYRE},
    {NPC_CAPTAIN_YATHAE,        NPC_CAPTAIN_YATHAE},
    {NPC_KILJAEDEN,             DATA_KILJAEDEN},

    {NPC_HAMMER_1,              NPC_HAMMER_1},
    {NPC_HAMMER_2,              NPC_HAMMER_2},
    {NPC_ELUNES_1,              NPC_ELUNES_1},
    {NPC_ELUNES_2,              NPC_ELUNES_2},
    {NPC_GOLGANETH_1,           NPC_GOLGANETH_1},
    {NPC_GOLGANETH_2,           NPC_GOLGANETH_2},
    {NPC_SASSZINE_NPC_OUTRO,    NPC_SASSZINE_NPC_OUTRO},
    {NPC_KILDJEDAN_AVATARA,     NPC_KILDJEDAN_AVATARA},
    {NPC_ATRIGAN,               NPC_ATRIGAN},
    {NPC_BELAK,                 NPC_BELAK},
    {NPC_HARJATAN,              NPC_HARJATAN},
    {NPC_ELDER,                 NPC_ELDER},
    {NPC_AVATARA_MAIDEN ,       NPC_AVATARA_MAIDEN},
    {NPC_SISTERS_ACH_ADD,       NPC_SISTERS_ACH_ADD},
    {0,                         0} // END
};

ObjectData const gobjectData[] =
{
    {GO_GOROTH_GATES,       GO_GOROTH_GATES},
    {GO_INTRODESTROY_1,     GO_INTRODESTROY_1},
    {GO_INTRODESTROY_2,     GO_INTRODESTROY_2},
    {GO_INTRODESTROY_3,     GO_INTRODESTROY_3},
    {GO_ELEVATOR,           GO_ELEVATOR},
    {GO_KILJAEDEN_BRIDGE_1, GO_KILJAEDEN_BRIDGE_1},
    {GO_KILJAEDEN_BRIDGE_2, GO_KILJAEDEN_BRIDGE_2},
    {GO_KILJAEDEN_CHEST,    GO_KILJAEDEN_CHEST},

    {269164,                269164},
    {268580,                268580},
    {GO_AVATARA_FLOOR ,     GO_AVATARA_FLOOR},

    // Avataras floor blocks
    {267700,                267700},
    {267701,                267701},
    {267702,                267702},
    {267703,                267703},
    {267704,                267704},
    {267705,                267705},
    {267706,                267706},
    {267707,                267707},
    {267708,                267708},
    {267709,                267709},
    {267710,                267710},
    {267711,                267711},
    {267712,                267712},
    {267713,                267713},
    {267714,                267714},
    {267715,                267715},
    {267716,                267716},
    {267717,                267717},
    {267718,                267718},
    {267719,                267719},
    {267720,                267720},
    {267721,                267721},
    {267722,                267722},
    {267723,                267723},
    {267724,                267724},

    // end Avatara bloks
    {0,                     0 } // END
};

class instance_tomb_of_sargeras : public InstanceMapScript
{
public:
    instance_tomb_of_sargeras() : InstanceMapScript(ToSScriptName, 1676) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_tomb_of_sargeras_InstanceMapScript(map);
    }

    struct instance_tomb_of_sargeras_InstanceMapScript : InstanceScript
    {
        instance_tomb_of_sargeras_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }


        std::vector<ObjectGuid> addsIntro{};
        std::set<ObjectGuid> lunarArchersEvent{};
        WorldLocation loc_res_pla{};

        std::vector<ObjectGuid> avatarasFloors{};

        uint32 checkTimer = 1000;
        uint32 checkPlayersFallTimer = 1000;

        void Initialize() override
        {
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gobjectData);
        }

        void OnPlayerEnter(Player* player) override {}

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case 121024:
            case 121023:
                if (creature->GetPositionX() >= 6019.0f && creature->GetPositionZ() <= 2972.0f)
                {
                    if (!creature->HasAura(35356)) //&& !creature->HasFlag(UNIT_FIELD_FLAGS_3, UNIT_FLAG3_FEIGN_DEATH))
                    {
                       // creature->AddDelayedEvent(1000, [creature]() -> void {creature->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_ONESHOT_ATTACK1H); });
                        addsIntro.push_back(creature->GetGUID());
                    }
                }
                break;
            case NPC_GOROTH:
                creature->SetVisible(false);
                creature->SetReactState(REACT_PASSIVE);
                break;
            case NPC_MAEIV:
            case NPC_ILLIDAN:
                //creature->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_ONESHOT_ATTACK1H);
                break;
            case NPC_VELEN:
                creature->CastSpell(creature, 241186); // he don't want use it like aura =C
                break;
            case NPC_ATRIGAN_MISC:
                creature->SetReactState(REACT_PASSIVE);
                if (GetBossState(DATA_GOROTH) != NOT_STARTED)
                    creature->SetVisible(false);
                break;
            case NPC_HAMMER_1:
            case NPC_HAMMER_2:
                if (GetBossState(DATA_DEMONIC_INQUISITION) != DONE)
                    creature->SetVisible(false);
                break;
            case NPC_ELUNES_1:
            case NPC_ELUNES_2:
                if (GetBossState(DATA_THE_DESOLATE_HOST) != DONE)
                    creature->SetVisible(false);
                break;
            case NPC_GOLGANETH_1:
            case NPC_GOLGANETH_2:
                if (GetBossState(DATA_MISTRESS_SASSZINE) != DONE)
                    creature->SetVisible(false);
                break;
            case NPC_LUNAR_ARCHER:
                if (creature->GetDistance(6088.19f, -1030.07f, 2896.31f) <= 10.0f)
                    lunarArchersEvent.insert(creature->GetGUID());
                break;
            case NPC_KILDJEDAN_AVATARA:
                if (GetBossState(DATA_FALLEN_AVATAR) == DONE)
                    creature->SetVisible(false);
                break;
            case NPC_TADPOLE_1:
            case NPC_TADPOLE_2:
            case NPC_TADPOLE_3:
                if (Creature* harjatan = instance->GetCreature(GetGuidData(NPC_HARJATAN)))
                    harjatan->AI()->JustSummoned(creature);
                break;
            case NPC_FRAGMENT_SOUL:
                if (!instance->IsMythic())
                    creature->DespawnOrUnsummon(100);
                else if (Creature* atrigan = instance->GetCreature(GetGuidData(NPC_ATRIGAN)))
                {
                    atrigan->AI()->JustSummoned(creature);
                    creature->CastSpell(creature, 241521);
                }
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_ELEVATOR:
                if (GetBossState(DATA_MAIDEN_OF_VIGILANCE) != DONE)
                  //  go->SetPhaseMask(2, true);
                break;
            case 267700:
            case 267701:
            case 267702:
            case 267703:
            case 267704:
            case 267705:
            case 267706:
            case 267707:
            case 267708:
            case 267709:
            case 267710:
            case 267711:
            case 267712:
            case 267713:
            case 267714:
            case 267715:
            case 267716:
            case 267717:
            case 267718:
            case 267719:
            case 267720:
            case 267721:
            case 267722:
            case 267723:
            case 267724:
                avatarasFloors.push_back(go->GetGUID());
                break;
            default:
                break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            InstanceScript::OnGameObjectRemove(go);
        }

        void OnUnitDeath(Unit* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_LUNAR_ARCHER:
                if (lunarArchersEvent.find(creature->GetGUID()) != lunarArchersEvent.end())
                {
                    lunarArchersEvent.erase(creature->GetGUID());
                    if (lunarArchersEvent.empty())
                        instance->SummonCreature(NPC_GUARDIAN_SENTRY, { 6088.50f, -1027.06f, 2896.43f, 4.23f });
                }
                break;
            case NPC_EVENT_1:
            case NPC_EVENT_2:
                if (Creature* event = instance->GetCreature(GetGuidData(NPC_SASSZINE_MISC)))
                    if (event->IsAlive() && event->IsInWorld())
                        event->AI()->DoAction(1);
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type != DATA_MAIDEN_OF_VIGILANCE && type != DATA_FALLEN_AVATAR && type != DATA_KILJAEDEN)
                if (GameObject* go = instance->GetGameObject(GetGuidData(269164)))
                    HandleGameObject(go->GetGUID(), CheckRequiredBosses(DATA_MAIDEN_OF_VIGILANCE, 0), go);

            switch (state)
            {
            case DONE:
            {
                switch (type)
                {
                case DATA_GOROTH:
                    if (auto khadgar = instance->GetCreature(GetGuidData(NPC_KHADGAR)))
                        khadgar->AI()->DoAction(true);
                    break;
                case DATA_DEMONIC_INQUISITION:
                    for (auto id : { NPC_HAMMER_1, NPC_HAMMER_2 })
                        if (auto hammer = instance->GetCreature(GetGuidData(id)))
                            hammer->SetVisible(true);
                    break;
                case DATA_HARJATAN:
                    if (auto sivash = instance->GetCreature(GetGuidData(NPC_SASSZINE_NPC_OUTRO)))
                       // sivash->AddDelayedEvent(2000, [sivash] {sivash->AI()->ZoneTalk(0); });
                    break;
                case DATA_THE_DESOLATE_HOST:
                    for (auto id : { NPC_ELUNES_1, NPC_ELUNES_2 })
                        if (auto elunes = instance->GetCreature(GetGuidData(id)))
                            elunes->SetVisible(true);
                    break;
                case DATA_MISTRESS_SASSZINE:
                    for (auto id : { NPC_GOLGANETH_1, NPC_GOLGANETH_2 })
                        if (auto golganeth = instance->GetCreature(GetGuidData(id)))
                            golganeth->SetVisible(true);
                    break;
                case DATA_MAIDEN_OF_VIGILANCE:
                    if (auto go = instance->GetGameObject(GetGuidData(GO_ELEVATOR)))
                      //  go->SetPhaseMask(1, true);  // invis
                    break;
                default:
                    break;
                }
                break;
            }
            case NOT_STARTED:
            {
                switch (type)
                {
                case DATA_FALLEN_AVATAR:
                    if (GameObject* go = instance->GetGameObject(GetGuidData(GO_AVATARA_FLOOR)))
                        go->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);

                    for (auto i : avatarasFloors)
                        if (GameObject* go = instance->GetGameObject(i))
                            go->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);
                    break;
                }
                break;
            }
            default:
                break;
            }

            if (type == DATA_KILJAEDEN)
            {
                if (state == IN_PROGRESS)
                {
                    HandleGameObject(GetGuidData(GO_KILJAEDEN_BRIDGE_1), true);
                    HandleGameObject(GetGuidData(GO_KILJAEDEN_BRIDGE_2), true);
                }
                else
                {
                    HandleGameObject(GetGuidData(GO_KILJAEDEN_BRIDGE_1), false);
                    HandleGameObject(GetGuidData(GO_KILJAEDEN_BRIDGE_2), false);
                }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case 1: // intro
                for (auto guid : addsIntro)
                    if (auto creature = instance->GetCreature(guid))
                    {
                        //creature->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, 0);
                        creature->CombatStop();
                        creature->CastSpell(creature, 35356);
                    }
                break;
            default:
                break;
            }
        }
/*
        uint32 GetData(uint32 type) const override
        {
            //switch (type)
            //{
            //default:
            return 0;
            //}
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            //switch (type)
            {
            //default:
            return InstanceScript::GetGuidData(type);
            }
        }
*/
      //  bool CheckRequiredBosses(uint32 bossId, uint32 /*entry*/, Player const* /*player*/ = nullptr) const override
    /*    {
            if (sWorld->getBoolConfig(CONFIG_IS_TEST_SERVER))
                return true;

            switch (bossId)
            {
            case DATA_MAIDEN_OF_VIGILANCE:
                for (uint32 i = DATA_GOROTH; i < DATA_MAIDEN_OF_VIGILANCE; ++i)
                    if (GetBossState(i) != DONE)
                        return false;
                return true;
            default:
                return true;
            }
        }
        */
     /*   WorldLocation* GetClosestGraveYard(float x, float y, float z)// override
        {
            Position playerPosition(x, y, z);
            uint32 graveyardId = 5889;

            std::vector<uint32> availableGravs{ 6014, 6017, 6019, 5889 };

            if (GetBossState(DATA_GOROTH) == DONE)
                availableGravs.push_back(6015);

            if (CheckRequiredBosses(DATA_MAIDEN_OF_VIGILANCE, 0))
                availableGravs.push_back(6016);
            if (GetBossState(DATA_HARJATAN) == DONE)
                availableGravs.push_back(6018);
            if (GetBossState(DATA_MAIDEN_OF_VIGILANCE) == DONE)
                availableGravs.push_back(6020);
            if (GetBossState(DATA_FALLEN_AVATAR) == DONE)
                availableGravs.push_back(6210);

            if (GetBossState(DATA_KILJAEDEN) == DONE)
                availableGravs.push_back(6117);

            for (auto gravYard : availableGravs)
            {
               // WorldSafeLocsEntry const* temp = sWorldSafeLocsStore.LookupEntry(gravYard);
               // WorldSafeLocsEntry const* saved = sWorldSafeLocsStore.LookupEntry(graveyardId);
              //  if (!temp)
                    continue;
               // if (!saved)
                    graveyardId = gravYard;

              //  Position pos1(temp->Loc);
               // Position pos2(saved->Loc);
                //if (playerPosition.GetExactDist(&pos1) < playerPosition.GetExactDist(&pos2))
                    graveyardId = gravYard;
            }

            if (GetBossState(DATA_GOROTH) != DONE)
            {
              //  WorldSafeLocsEntry const* temp = sWorldSafeLocsStore.LookupEntry(6015);
               // WorldSafeLocsEntry const* saved = sWorldSafeLocsStore.LookupEntry(graveyardId);
              //  if (temp)
                {
                //    Position pos1(temp->Loc);
                //    Position pos2(saved->Loc);
                  //  if (playerPosition.GetExactDist(&pos1) < playerPosition.GetExactDist(&pos2))
                        graveyardId = 6015;
                }
            }

        //    if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
            //    loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            //    loc_res_pla.SetMapId(gy->MapID);
            }

            return &loc_res_pla;
        }

        std::string GetSaveData() override
        {
            std::ostringstream saveStream;
            //saveStream << "T O S " << GetBossSaveData();
            return saveStream.str();
        }

        void Load(const char* data) override
        {
            if (!data)
            {
              //  OUT_LOAD_INST_DATA_FAIL;
                return;
            }

          //  OUT_LOAD_INST_DATA(data);

            char dataHead1, dataHead2, dataHead3;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2 >> dataHead3;

            if (dataHead1 == 'T' && dataHead2 == 'O' && dataHead3 == 'S')
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
          //  else
         //       OUT_LOAD_INST_DATA_FAIL;

        //    OUT_LOAD_INST_DATA_COMPLETE;

        }

        void Update(uint32 diff) override
        {
            if (checkTimer <= diff)
            {
                checkTimer = 1000;

             //   instance->ApplyOnEveryPlayer([&](Player* player)
                {
                 //   if (GetBossState(DATA_FALLEN_AVATAR) == IN_PROGRESS &&
                    //    (player->GetPositionZ() <= 1509.50f || (player->GetPositionX() >= 6667.59f && player->GetPositionZ() <= 1540.68f)))
                    {
                       // if (!player->HasAura(240249))
                        //    player->CastSpell(player, 240249, true);
                    }
                   // else if (player->HasAura(240249))
                     //   player->RemoveAurasDueToSpell(240249);

                  //  if (player->isAlive())
                       // if (GetBossState(DATA_MAIDEN_OF_VIGILANCE) == IN_PROGRESS || GetBossState(DATA_MAIDEN_OF_VIGILANCE) == NOT_STARTED)
                          //  if (player->GetDistance2d(6348.49f, -796.72f) <= 21.0f)
                              //  if (player->GetPositionZ() <= 2855.0f)
                                //    player->Kill(player);
              //  });
            }
         //   else
                checkTimer -= diff;

            if (checkPlayersFallTimer <= diff)
            {
                checkPlayersFallTimer = 500;

              //  instance->ApplyOnEveryPlayer([&](Player* player)
                {
                  //  if (player->IsFalling())
                    {
                       // if (player->IsWithinBox({ 4500.0f, -1510.0f, 5330.0f }, 200.0f, 200.0f, 20.0f))
                        {
                        //    if (player->isAlive())
                           //     player->Kill(player);

                        //    player->NearTeleportTo(4500.18f, -1484.60f, 5385.64f, player->GetOrientation());
                        }

                      //  if (player->GetDistance(6437.81f, -1089.29f, 2881.52f) < 100.0f && player->GetPositionZ() < 2870.0f)
                        {
                         //   if (player->isAlive())
                        //        player->Kill(player);

                        //    player->NearTeleportTo(6402.37f, -1064.89f, 2881.05f, player->GetOrientation());
                        }
                    }
              //  });
            }
           // else
                checkPlayersFallTimer -= diff;
        }*/
    };
};

void AddSC_instance_tomb_of_sargeras()
{
    new instance_tomb_of_sargeras();
}
