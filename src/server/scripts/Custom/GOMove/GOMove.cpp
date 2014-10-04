#include "ScriptPCH.h"
#include "MapManager.h"
#include "Language.h"

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

    static std::set<uint32> GObjects; // GObjects[] = GObjectID // GObjectID comes from highguid. lowguid is 0 for temps.
    static std::unordered_map<ObjectGuid, uint32> SpawnQue;

    ChatCommand* GetCommands() const override
    {
        static ChatCommand GOMoveCommandTable[] =
        {
            { "gomove", rbac::RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP, false, &GOMove_Command, "", NULL },
            { NULL, 0, false, NULL, "", NULL }
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
        uint32 ID = (uint32)atol(ID_t);

        char* GObjectID_C = strtok(NULL, " ");
        uint32 GObjectID = 0;
        bool isHex = false;
        if (GObjectID_C)
        {
            GObjectID = strtoul(GObjectID_C, NULL, 0); // can take in hex as well as dec
            isHex = (std::string(GObjectID_C).find("0x") != std::string::npos);
        }

        char* ARG_t = strtok(NULL, " ");
        uint32 ARG = 0;
        if (ARG_t)
            ARG = (uint32)atol(ARG_t);

        WorldSession* session = handler->GetSession();
        Player* player = session->GetPlayer();
        uint64 playerGUID = player->GetGUID();

        if (ID < SPAWN) // no args
        {
            if (ID >= DELET && ID <= GOTO) // has target (needs retrieve gameobject)
            {
                GameObject* target = GetObjectByGObjectID(player, GObjectID, isHex);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found. Temp(%u)", GObjectID, isHex ? 1 : 0);
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();
                    switch (ID)
                    {
                        case DELET: DeleteObject(target/*, isHex ? GObjectID : 0*/); SendSelectionInfo(player, GObjectID, isHex, false); break;
                        case X: SpawnObject(player, player->GetPositionX(), y, z, o, p, true, GObjectID, isHex);      break;
                        case Y: SpawnObject(player, x, player->GetPositionY(), z, o, p, true, GObjectID, isHex);      break;
                        case Z: SpawnObject(player, x, y, player->GetPositionZ(), o, p, true, GObjectID, isHex);      break;
                        case O: SpawnObject(player, x, y, z, player->GetOrientation(), p, true, GObjectID, isHex);    break;
                        case GOTO: player->TeleportTo(target->GetMapId(), x, y, z, o);                     break;
                        case RESPAWN: SpawnObject(player, x, y, z, o, p, false, target->GetEntry(), isHex);           break;
                        case GROUND:
                        {
                            float ground = target->GetMap()->GetHeight(target->GetPhaseMask(), x, y, MAX_HEIGHT);
                            if (ground != INVALID_HEIGHT)
                                SpawnObject(player, x, y, ground, o, p, true, GObjectID, isHex);
                        } break;
                    }
                }
            }
            else
            {
                switch (ID)
                {
                    case TEST:
                        session->SendAreaTriggerMessage(player->GetName().c_str());
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
                        SaveObject(player, GObjectID, isHex);
                        break;
                    case SELECTNEAR:
                    {
                        GameObject* object = handler->GetNearbyGameObject();
                        object = GetClosestGObjectID(player, object);
                        if (!object)
                            ChatHandler(player->GetSession()).PSendSysMessage("No objects found");
                        else
                        {
                            bool isHex = (object->GetGUIDHigh() != HIGHGUID_GAMEOBJECT);
                            SendSelectionInfo(player, isHex ? object->GetGUIDHigh() : object->GetDBTableGUIDLow() ? object->GetDBTableGUIDLow() : object->GetGUIDLow(), isHex, true);
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
                GameObject* target = GetObjectByGObjectID(player, GObjectID, isHex);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found. Temporary: %s", GObjectID, isHex ? "true" : "false");
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();
                    switch (ID)
                    {
                        case NORTH: SpawnObject(player, x + ((float)ARG / 100), y, z, o, p, true, GObjectID, isHex);                            break;
                        case EAST: SpawnObject(player, x, y - ((float)ARG / 100), z, o, p, true, GObjectID, isHex);                             break;
                        case SOUTH: SpawnObject(player, x - ((float)ARG / 100), y, z, o, p, true, GObjectID, isHex);                            break;
                        case WEST: SpawnObject(player, x, y + ((float)ARG / 100), z, o, p, true, GObjectID, isHex);                             break;
                        case NORTHEAST: SpawnObject(player, x + ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, true, GObjectID, isHex);   break;
                        case SOUTHEAST: SpawnObject(player, x - ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, true, GObjectID, isHex);   break;
                        case SOUTHWEST: SpawnObject(player, x - ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, true, GObjectID, isHex);   break;
                        case NORTHWEST: SpawnObject(player, x + ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, true, GObjectID, isHex);   break;
                        case UP: SpawnObject(player, x, y, z + ((float)ARG / 100), o, p, true, GObjectID, isHex);                               break;
                        case DOWN: SpawnObject(player, x, y, z - ((float)ARG / 100), o, p, true, GObjectID, isHex);                             break;
                        case RIGHT: SpawnObject(player, x, y, z, o - ((float)ARG / 100), p, true, GObjectID, isHex);                            break;
                        case LEFT: SpawnObject(player, x, y, z, o + ((float)ARG / 100), p, true, GObjectID, isHex);                             break;
                        case PHASE: SpawnObject(player, x, y, z, o, ARG, true, GObjectID, isHex);                                               break;
                    }
                }
            }
            else
            {
                switch (ID)
                {
                    case SPAWN:
                    {
                        if (SpawnObject(player, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), player->GetPhaseMaskForSpawn(), false, ARG, false, true))
                            SpawnQue[player->GetGUID()] = ARG;
                    } break;
                    case SPAWNSPELL:
                    {
                        SpawnQue[player->GetGUID()] = ARG;
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

                                if (GameObject* object = GetObjectByGObjectID(player, guidLow, false))
                                    SendSelectionInfo(player, guidLow, false, true);
                            } while (result->NextRow());
                        }
                        for (std::set<uint32>::const_iterator it = GObjects.begin(); it != GObjects.end();)
                        {
                            GameObject* temp = player->GetGameObject(*it);
                            if (!temp)
                            {
                                GObjects.erase(*it++);
                                continue;
                            }
                            if (temp->IsWithinDistInMap(player, ARG))
                                SendSelectionInfo(player, (*it), true, true);
                            ++it;
                        }
                    } break;
                }
            }
        }
        else
            return false;
        return true;
    }

    static GameObject* GetClosestGObjectID(Player* player, GameObject* obj)
    {
        if (!player)
            return NULL;
        uint32 closestID = 0;
        for (std::set<uint32>::const_iterator it = GObjects.begin(); it != GObjects.end();)
        {
            if (obj && obj->GetGUIDHigh() == (*it))
            {
                ++it;
                continue;
            }
            GameObject* temp = player->GetGameObject(*it);
            if (!temp)
            {
                GObjects.erase(*it++);
                continue;
            }
            if (obj && temp->GetDistance(player) > obj->GetDistance(player))
            {
                ++it;
                continue;
            }
            closestID = (*it);
            obj = temp;
            ++it;
        }
        if (obj && !closestID && obj->GetGUIDLow() && !obj->GetDBTableGUIDLow()) // obj is .gob add temp, respawn and return
        {
            float x, y, z, o;
            obj->GetPosition(x, y, z, o);
            GameObject* obj2 = SpawnObject(player, x, y, z, o, obj->GetPhaseMask(), false, obj->GetEntry(), false);
            DeleteObject(obj);
            obj = obj2;
        }
        return obj;
    }

    static GameObject* GetObjectByGObjectID(Player* player, uint32 GObjectID, bool isHex)
    {
        GameObject* object = NULL;
        if (isHex)
        {
            object = player->GetGameObject(GObjectID);
            if (!object)
                GObjects.erase(GObjectID);
        }
        else
        {
            if (GameObjectData const* gameObjectData = sObjectMgr->GetGOData(GObjectID))
                object = ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(GObjectID, gameObjectData->id);
        }

        if (!object || !object->IsInMap(player)) // cant move objects on different maps
            return NULL;
        return object;
    }

    static void SendAddonMessage(Player* player, const char* msg)
    {
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

    static void SendSelectionInfo(Player* player, uint32 GObjectID, bool isHex, bool add) // Sends an addon message for selected objects list
    {
        if (!player || !GObjectID)
            return;

        std::ostringstream ss;
        if (!add)
            if (!isHex)
                ss << "GOMOVE|REMOVE|" << std::dec << (uint32)GObjectID << "||0";
            else
                ss << "GOMOVE|REMOVE|" << "0x" << std::hex << GObjectID << "||0";
        else
        {
            GameObject* object = GetObjectByGObjectID(player, GObjectID, isHex);
            if (!object)
                return;
            if (!isHex)
                ss << "GOMOVE|ADD|" << std::dec << (uint32)GObjectID << std::dec << "|" << object->GetName() << "|" << object->GetEntry();
            else
                ss << "GOMOVE|ADD|" << "0x" << std::hex << GObjectID << std::dec << "|" << object->GetName() << "|" << object->GetEntry();
        }

        SendAddonMessage(player, ss.str().c_str());
    }

    static GameObject* SummonGameObject(Player* obj, uint32 entry, float x, float y, float z, float o, uint32 p, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime)
    {
        if (!obj->IsInWorld())
            return NULL;

        GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
        if (!goinfo)
            return NULL;

        Map* map = obj->GetMap();
        GameObject* go = new GameObject();
        if (!go->Create(0, entry, map, p, x, y, z, o, rotation0, rotation1, rotation2, rotation3, 100, GO_STATE_READY))
        {
            delete go;
            return NULL;
        }

        go->SetRespawnTime(respawnTime);
        obj->AddGameObject(go);
        map->AddToMap(go);

        go->SetSpellId(go->GetGUIDHigh()); // small hack :3
        GObjects.insert(go->GetGUIDHigh());
        return go;
    }

    static void DeleteObject(GameObject* object/*, uint32 GObjectID = 0*/)
    {
        //if(GObjectID)
        //    GObjects.erase(GObjectID);
        if (object)
        {
            GObjects.erase(object->GetGUIDHigh()); // remove from temp store

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
    }

    static GameObject* SpawnObject(Player* player, float x, float y, float z, float o, uint32 p, bool move, uint32 eorg, bool isHex, bool message = false)
    {
        // eorg = !move && entry or move && GObjectID (entry or ID)
        if (!player || !eorg)
            return NULL;

        float rot2 = std::sin(o / 2);
        float rot3 = std::cos(o / 2);

        GameObject* object = NULL;
        if (move)
        {
            object = GetObjectByGObjectID(player, eorg, isHex);
            if (!object)
                return NULL;
            GameObject* spawned = SummonGameObject(player, object->GetEntry(), x, y, z, o, p, 0, 0, rot2, rot3, 0);
            DeleteObject(object/*, isHex ? eorg : 0*/);
            if (!spawned)
                return NULL;
            // object->SetPhaseMask(p, true);
            std::ostringstream ss;
            if (!isHex)
                ss << "GOMOVE|SWAP|" << eorg << "||" << "0x" << std::hex << spawned->GetGUIDHigh();
            else
                ss << "GOMOVE|SWAP|" << "0x" << std::hex << eorg << "||" << "0x" << std::hex << spawned->GetGUIDHigh();
            SendAddonMessage(player, ss.str().c_str());
        }
        else
        {
            object = SummonGameObject(player, eorg, x, y, z, o, p, 0, 0, rot2, rot3, 0);
            if (!object)
                return NULL;
            SendSelectionInfo(player, object->GetGUIDHigh(), true, true); // MUST be handled here. There are no good ways to get the GObjectID later.
        }

        return object;
    }

    static void SaveObject(Player* player, uint32 GObjectID, bool isHex, bool message = false)
    {
        GameObject* object = GetObjectByGObjectID(player, GObjectID, isHex);
        if (!object)
            return;

        Map* map = player->GetMap();
        GameObject* saved = new GameObject();
        uint32 guidLow = sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT);
        float x, y, z, o;
        object->GetPosition(x, y, z, o);
        if (!saved->Create(guidLow, object->GetEntry(), map, object->GetPhaseMask(), x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
        {
            delete saved;
            return;
        }
        saved->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), object->GetPhaseMask());
        if (!saved->LoadGameObjectFromDB(guidLow, map))
        {
            delete saved;
            return;
        }
        sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGOData(guidLow));

        DeleteObject(object/*, isHex ? GObjectID : 0*/); // delete old
        std::ostringstream ss;
        if (!isHex)
            ss << "GOMOVE|SWAP|" << std::dec << GObjectID << std::dec << "||" << guidLow;
        else
            ss << "GOMOVE|SWAP|" << "0x" << std::hex << GObjectID << std::dec << "||" << guidLow;
        SendAddonMessage(player, ss.str().c_str());
    }
};
std::set<uint32> GOMove_commandscript::GObjects;
std::unordered_map<ObjectGuid, uint32> GOMove_commandscript::SpawnQue;

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
            if (summonPos && GOMove_commandscript::SpawnQue.find(player->GetGUID()) != GOMove_commandscript::SpawnQue.end())
                GOMove_commandscript::SpawnObject(player, summonPos->GetPositionX(), summonPos->GetPositionY(), summonPos->GetPositionZ(), player->GetOrientation(), player->GetPhaseMaskForSpawn(), false, GOMove_commandscript::SpawnQue[player->GetGUID()], false, true);
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

void AddSC_GOMove_commandscript()
{
    new GOMove_commandscript();
    new GOMove_spell_place();
}
