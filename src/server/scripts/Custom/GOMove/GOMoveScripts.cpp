/*
GOMove By Rochet2
Original idea by Mordred

http://rochet2.github.io/
*/

#include "GOMove.h"
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
