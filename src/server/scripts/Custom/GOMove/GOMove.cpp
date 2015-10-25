/*
GOMove By Rochet2
Original idea by Mordred

http://rochet2.github.io/
*/

#include <math.h>
#include <set>
#include <sstream>
#include <string>
#include "Chat.h"
#include "GameObject.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Position.h"
#include "RBAC.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "WorldPacket.h"
#include "GOMove.h"

// global
void GOMoveRemoveGO(ObjectGuid const & guid)
{
    bool isHex = GOMove::IsTemporary(guid);
    if (isHex)
        GOMove::Store.RemoveTemp(guid.GetEntry());

    for (auto session : sWorld->GetAllSessions())
        if (Player* player = session.second->GetPlayer())
            GOMove::SendRemove(player, isHex ? guid.GetEntry() : guid.GetCounter(), isHex);
}

bool GOMove::IsTemporary(ObjectGuid const & guid)
{
    return (guid.GetHigh() == HighGuid::GOMoveObject);
}

void GOMove::SendAddonMessage(Player * player, const char * msg)
{
    if (!player || !msg)
        return;

    WorldPacket data; // Needs a custom built packet since TC doesnt send guid
    uint32 messageLength = (uint32)strlen(msg) + 1;
    data.Initialize(SMSG_MESSAGECHAT, 100);
    data << uint8(CHAT_MSG_SYSTEM);
    data << int32(LANG_ADDON);
    data << uint64(player->GetGUID());
    data << uint32(0);
    data << uint64(player->GetGUID());
    data << uint32(messageLength);
    data << msg;
    data << uint8(0);
    player->GetSession()->SendPacket(&data);
}

GameObject * GOMove::GetGameObject(Player * player, uint32 GObjectID, bool isHex)
{
    if (isHex)
        return Store.GetTemp(player, GObjectID);
    else if (GameObjectData const* gameObjectData = sObjectMgr->GetGOData(GObjectID))
        return ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(GObjectID, gameObjectData->id);
    return nullptr;
}

void GOMove::SendAdd(Player * player, uint32 GObjectID, bool isHex)
{
    GameObject* object = GOMove::GetGameObject(player, GObjectID, isHex);
    if (!object)
        return;

    char msg[256];
    if (!isHex)
        snprintf(msg, 256, "GOMOVE|ADD|%u|%s|%u", GObjectID, object->GetName().c_str(), object->GetEntry());
    else
        snprintf(msg, 256, "GOMOVE|ADD|%#x|%s|%u", GObjectID, object->GetName().c_str(), object->GetEntry());

    SendAddonMessage(player, msg);
}

void GOMove::SendRemove(Player * player, uint32 GObjectID, bool isHex)
{
    char msg[256];
    if (!isHex)
        snprintf(msg, 256, "GOMOVE|REMOVE|%u||0", GObjectID);
    else
        snprintf(msg, 256, "GOMOVE|REMOVE|%#x||0", GObjectID);

    SendAddonMessage(player, msg);
}

void GOMove::SendSwap(Player * player, uint32 GObjectID1, bool isHex1, uint32 GObjectID2, bool isHex2)
{
    char msg[256];
    if (!isHex1 && !isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%u||%u", GObjectID1, GObjectID2);
    else if (isHex1 && isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%#x||%#x", GObjectID1, GObjectID2);
    else if (!isHex1 && isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%u||%#x", GObjectID1, GObjectID2);
    else if (isHex1 && !isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%#x||%u", GObjectID1, GObjectID2);
    SendAddonMessage(player, msg);
}

GameObject * GOMove::CreateTemp(Player * obj, uint32 entry, float x, float y, float z, float o, uint32 p, uint32 respawnTime)
{
    if (!obj->IsInWorld())
        return nullptr;

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
        return nullptr;

    float rotation2 = std::sin(o / 2);
    float rotation3 = std::cos(o / 2);

    Map* map = obj->GetMap();
    GameObject* go = new GameObject();
    if (!go->Create(0, entry, map, p, x, y, z, o, 0, 0, rotation2, rotation3, 100, GO_STATE_READY))
    {
        delete go;
        return nullptr;
    }

    go->SetRespawnTime(respawnTime);
    obj->AddGameObject(go);
    map->AddToMap(go);

    Store.AddTemp(go->GetGUID().GetEntry(), go);
    return go;
}

void GOMove::DeleteGameObject(GameObject * object)
{
    if (!object)
        return;

    ObjectGuid ownerGuid = object->GetOwnerGUID();
    if (ownerGuid != ObjectGuid::Empty)
    {
        Unit* owner = ObjectAccessor::GetUnit(*object, ownerGuid);
        if (owner && ownerGuid.IsPlayer())
            owner->RemoveGameObject(object, false);
    }
    object->SetRespawnTime(0);
    object->Delete();
    object->DeleteFromDB();
}

GameObject * GOMove::SpawnGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 entry)
{
    if (!player || !entry)
        return nullptr;

    GameObject* spawned = CreateTemp(player, entry, x, y, z, o, p, 0);
    if (spawned)
        SendAdd(player, spawned->GetGUID().GetEntry(), true);
    return spawned;
}

GameObject * GOMove::MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 GObjectID, bool isHex)
{
    if (!player)
        return nullptr;

    GameObject* object = GetGameObject(player, GObjectID, isHex);
    if (!object)
    {
        SendRemove(player, GObjectID, isHex);
        return nullptr;
    }

    GameObject* spawned = CreateTemp(player, object->GetEntry(), x, y, z, o, p, 0);

    if (!spawned)
        return nullptr;

    SendSwap(player, GObjectID, isHex, spawned->GetGUID().GetEntry(), true);
    DeleteGameObject(object);
    return spawned;
}

void GOMove::SaveGameObject(Player * player, uint32 GObjectID, bool isHex)
{
    GameObject* object = GetGameObject(player, GObjectID, isHex);
    if (!object)
        return;

    if (!isHex)
    {
        object->SaveToDB();
        return;
    }

    Map* map = player->GetMap();
    GameObject* saved = new GameObject();
    uint32 guidLow = map->GenerateLowGuid<HighGuid::GameObject>();
    float x, y, z, o;
    object->GetPosition(x, y, z, o);
    if (!saved->Create(guidLow, object->GetEntry(), map, object->GetPhaseMask(), x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
    {
        delete saved;
        return;
    }
    saved->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), saved->GetPhaseMask());
    guidLow = saved->GetSpawnId();
    delete saved;
    saved = new GameObject();
    if (!saved->LoadGameObjectFromDB(guidLow, map))
    {
        delete saved;
        return;
    }
    sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGOData(guidLow));

    SendSwap(player, GObjectID, isHex, guidLow, false);
    DeleteGameObject(object);
}

void GameObjectStore::SpawnQueAdd(ObjectGuid const & guid, uint32 entry)
{
    WriteGuard lock(_objectsToSpawnLock);
    objectsToSpawn[guid] = entry;
}

void GameObjectStore::SpawnQueRem(ObjectGuid const & guid)
{
    WriteGuard lock(_objectsToSpawnLock);
    objectsToSpawn.erase(guid);
}

uint32 GameObjectStore::SpawnQueGet(ObjectGuid const & guid)
{
    WriteGuard lock(_objectsToSpawnLock);
    auto it = objectsToSpawn.find(guid);
    if (it != objectsToSpawn.end())
        return it->second;
    return 0;
}

void GameObjectStore::AddTemp(uint32 GObjectID, GameObject * go)
{
    if (!go)
        return;
    WriteGuard lock(_tempObjectsLock);
    tempObjects[GObjectID] = go;
}

void GameObjectStore::RemoveTemp(uint32 GObjectID)
{
    {
        WriteGuard lock(_tempObjectsLock);
        tempObjects.erase(GObjectID);
    }
}

GameObject * GameObjectStore::GetTemp(Player* player, uint32 GObjectID)
{
    WriteGuard lock(_tempObjectsLock);
    auto it = tempObjects.find(GObjectID);
    if (it != tempObjects.end())
        return player->IsInMap(it->second) ? it->second : nullptr;
    return nullptr;
}

void GameObjectStore::SendSelectTempInRange(Player * player, float range)
{
    std::vector<uint32> toSend;
    {
        WriteGuard lock(_tempObjectsLock);
        for (auto& go : tempObjects)
        {
            if (go.second->IsWithinDistInMap(player, range))
                toSend.push_back(go.first);
        }
    }

    for (uint32 low : toSend)
        GOMove::SendAdd(player, low, true);
}

GameObject * GameObjectStore::GetClosestTemp(Player * player, GameObject * closestReal)
{
    GameObject* obj = closestReal;
    WriteGuard lock(_tempObjectsLock);
    for (auto& go : tempObjects)
    {
        if (obj && go.second->GetDistance(player) > obj->GetDistance(player))
            continue;
        obj = go.second;
    }
    return obj;
}

class GOMove_commandscript : public CommandScript
{
public:
    GOMove_commandscript() : CommandScript("GOMove_commandscript")
    {
    }

    enum commandIDs
    {
        TEST,
        SELECTNEAR,
        DELET,
        X,
        Y,
        Z,
        O,
        GROUND,
        RESPAWN,
        GOTO,
        FACE,
        SAVE,

        SPAWN,
        NORTH,
        EAST,
        SOUTH,
        WEST,
        NORTHEAST,
        NORTHWEST,
        SOUTHEAST,
        SOUTHWEST,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PHASE,
        SELECTALLNEAR,
        SPAWNSPELL,
    };

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> GOMoveCommandTable =
        {
            { "gomove", rbac::RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP, false, &GOMove_Command, "" },
        };
        return GOMoveCommandTable;
    }

    static bool GOMove_Command(ChatHandler* handler, const char* args)
    {
        if (!args)
            return false;

        char* ID_t = strtok((char*)args, " ");
        if (!ID_t)
            return false;
        uint32 ID = static_cast<uint32>(atoul(ID_t));

        char* GObjectID_C = strtok(nullptr, " ");
        uint32 GObjectID = 0;
        bool isHex = false;
        if (GObjectID_C)
        {
            GObjectID = strtoul(GObjectID_C, nullptr, 0); // can take in hex as well as dec
            isHex = (std::string(GObjectID_C).find("0x") != std::string::npos);
        }

        char* ARG_t = strtok(nullptr, " ");
        uint32 ARG = 0;
        if (ARG_t)
            ARG = static_cast<uint32>(atoul(ARG_t));

        WorldSession* session = handler->GetSession();
        if (!session)
            return false;
        Player* player = session->GetPlayer();

        if (ID < SPAWN) // no args
        {
            if (ID >= DELET && ID <= GOTO) // has target (needs retrieve gameobject)
            {
                GameObject* target = GOMove::GetGameObject(player, GObjectID, isHex);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found. Temp(%u)", GObjectID, isHex ? 1 : 0);
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();
                    switch (ID)
                    {
                    case DELET: GOMove::DeleteGameObject(target); GOMove::SendRemove(player, GObjectID, isHex); break;
                    case X: GOMove::MoveGameObject(player, player->GetPositionX(), y, z, o, p, GObjectID, isHex);       break;
                    case Y: GOMove::MoveGameObject(player, x, player->GetPositionY(), z, o, p, GObjectID, isHex);       break;
                    case Z: GOMove::MoveGameObject(player, x, y, player->GetPositionZ(), o, p, GObjectID, isHex);       break;
                    case O: GOMove::MoveGameObject(player, x, y, z, player->GetOrientation(), p, GObjectID, isHex);     break;
                    case RESPAWN: GOMove::SpawnGameObject(player, x, y, z, o, p, target->GetEntry());                   break;
                    case GOTO:
                    {
                        // stop flight if need
                        if (player->IsInFlight())
                        {
                            player->GetMotionMaster()->MovementExpired();
                            player->CleanupAfterTaxiFlight();
                        }
                        // save only in non-flight case
                        else
                            player->SaveRecallPosition();
                        player->TeleportTo(target->GetMapId(), x, y, z, o);
                    } break;
                    case GROUND:
                    {
                        float ground = target->GetMap()->GetHeight(target->GetPhaseMask(), x, y, MAX_HEIGHT);
                        if (ground != INVALID_HEIGHT)
                            GOMove::MoveGameObject(player, x, y, ground, o, p, GObjectID, isHex);
                    } break;
                    }
                }
            }
            else
            {
                switch (ID)
                {
                case TEST:
                    session->SendAreaTriggerMessage("%s", player->GetName().c_str());
                    break;
                case FACE:
                {
                    float const piper2 = float(M_PI) / 2.0f;
                    float const multi = player->GetOrientation() / piper2;
                    float const multi_int = floor(multi);
                    float const new_ori = (multi - multi_int > 0.5f) ? (multi_int + 1)*piper2 : multi_int*piper2;
                    player->SetFacingTo(new_ori);
                } break;
                case SAVE:
                    GOMove::SaveGameObject(player, GObjectID, isHex);
                    break;
                case SELECTNEAR:
                {
                    GameObject* object = GOMove::Store.GetClosestTemp(player, handler->GetNearbyGameObject());
                    if (!object)
                        ChatHandler(player->GetSession()).PSendSysMessage("No objects found");
                    else
                    {
                        if (GOMove::IsTemporary(object->GetGUID()))
                            GOMove::SendAdd(player, object->GetGUID().GetEntry(), true);
                        else
                            GOMove::SendAdd(player, object->GetSpawnId() ? object->GetSpawnId() : object->GetGUID().GetCounter(), false);
                        session->SendAreaTriggerMessage("Selected %s", object->GetName().c_str());
                    }
                } break;
                }
            }
        }
        else if (ARG && ID >= SPAWN)
        {
            if (ID >= NORTH && ID <= PHASE)
            {
                GameObject* target = GOMove::GetGameObject(player, GObjectID, isHex);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found. Temporary: %s", GObjectID, isHex ? "true" : "false");
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();
                    switch (ID)
                    {
                    case NORTH: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y, z, o, p, GObjectID, isHex);                            break;
                    case EAST: GOMove::MoveGameObject(player, x, y - ((float)ARG / 100), z, o, p, GObjectID, isHex);                             break;
                    case SOUTH: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y, z, o, p, GObjectID, isHex);                            break;
                    case WEST: GOMove::MoveGameObject(player, x, y + ((float)ARG / 100), z, o, p, GObjectID, isHex);                             break;
                    case NORTHEAST: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, GObjectID, isHex);   break;
                    case SOUTHEAST: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, GObjectID, isHex);   break;
                    case SOUTHWEST: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, GObjectID, isHex);   break;
                    case NORTHWEST: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, GObjectID, isHex);   break;
                    case UP: GOMove::MoveGameObject(player, x, y, z + ((float)ARG / 100), o, p, GObjectID, isHex);                               break;
                    case DOWN: GOMove::MoveGameObject(player, x, y, z - ((float)ARG / 100), o, p, GObjectID, isHex);                             break;
                    case RIGHT: GOMove::MoveGameObject(player, x, y, z, o - ((float)ARG / 100), p, GObjectID, isHex);                            break;
                    case LEFT: GOMove::MoveGameObject(player, x, y, z, o + ((float)ARG / 100), p, GObjectID, isHex);                             break;
                    case PHASE: GOMove::MoveGameObject(player, x, y, z, o, ARG, GObjectID, isHex);                                               break;
                    }
                }
            }
            else
            {
                switch (ID)
                {
                case SPAWN:
                {
                    if (GOMove::SpawnGameObject(player, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), player->GetPhaseMaskForSpawn(), ARG))
                        GOMove::Store.SpawnQueAdd(player->GetGUID(), ARG);
                } break;
                case SPAWNSPELL:
                {
                    GOMove::Store.SpawnQueAdd(player->GetGUID(), ARG);
                } break;
                case SELECTALLNEAR:
                {
                    if (ARG > 5000)
                        ARG = 5000;

                    QueryResult result = WorldDatabase.PQuery("SELECT guid, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE map = '%u' AND position_x BETWEEN '%f'-'%u' AND '%f'+'%u' AND position_y BETWEEN '%f'-'%u' AND '%f'+'%u' AND position_z BETWEEN '%f'-'%u' AND '%f'+'%u' ORDER BY order_ ASC LIMIT 100",
                        player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), player->GetPositionX(), ARG, player->GetPositionX(), ARG, player->GetPositionY(), ARG, player->GetPositionY(), ARG, player->GetPositionZ(), ARG, player->GetPositionZ(), ARG);

                    if (result)
                    {
                        do
                        {
                            Field* fields = result->Fetch();
                            uint32 guidLow = fields[0].GetUInt32();

                            if (GOMove::GetGameObject(player, guidLow, false))
                                GOMove::SendAdd(player, guidLow, false);
                        } while (result->NextRow());
                    }
                    GOMove::Store.SendSelectTempInRange(player, ARG);
                } break;
                }
            }
        }
        else
            return false;
        return true;
    }
};

// possible spells:
// 27651, 897

class GOMove_spell_place : public SpellScriptLoader
{
public:
    GOMove_spell_place() : SpellScriptLoader("GOMove_spell_place") { }

    class GOMove_spellscript : public SpellScript
    {
        PrepareSpellScript(GOMove_spellscript);

        void HandleAfterCast()
        {
            if (!GetCaster())
                return;
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;
            const WorldLocation* summonPos = GetExplTargetDest();
            if (!summonPos)
                return;
            if (uint32 entry = GOMove::Store.SpawnQueGet(player->GetGUID()))
                GOMove::SpawnGameObject(player, summonPos->GetPositionX(), summonPos->GetPositionY(), summonPos->GetPositionZ(), player->GetOrientation(), player->GetPhaseMaskForSpawn(), entry);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(GOMove_spellscript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new GOMove_spellscript();
    }
};

class GOMove_player_track : public PlayerScript
{
public:
    GOMove_player_track() : PlayerScript("GOMove_player_track") { }

    void OnLogout(Player* player) override
    {
        GOMove::Store.SpawnQueRem(player->GetGUID());
    }
};

void AddSC_GOMove_commandscript()
{
    new GOMove_commandscript();
    new GOMove_spell_place();
}
