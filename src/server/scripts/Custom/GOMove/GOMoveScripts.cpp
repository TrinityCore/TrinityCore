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
#include "ChatCommand.h"
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
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

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
        FLOOR,
        RESPAWN,
        GOTO,
        FACE,
        INFO,
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
        PITCHUP,
        PITCHDOWN,
        ROLLRIGHT,
        ROLLLEFT,
        SETPITCH,
        SETROLL,
        SETTURN,
    };

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable GOMoveCommandTable =
        {
            { "gomove", GOMove_Command, rbac::RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP, Console::No },
        };
        return GOMoveCommandTable;
    }

    static bool GOMove_Command(ChatHandler* handler, uint32 ID, Optional<uint32> cLowguid, Optional<uint32> ARG_t)
    {
        uint32 lowguid = 0;
        if (cLowguid)
            lowguid = *cLowguid;

        uint32 ARG = 0;
        if (ARG_t)
            ARG = *ARG_t;

        WorldSession* session = handler->GetSession();
        if (!session)
            return false;
        Player* player = session->GetPlayer();

        if (ID < SPAWN) // no args
        {
            if (ID >= DELET && ID <= INFO && ID != FACE) // has target (needs retrieve gameobject) - Extended to include INFO
            {
                GameObject* target = GOMove::GetGameObject(player, lowguid);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found.", lowguid);
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();
                    switch (ID)
                    {
                    case DELET: GOMove::DeleteGameObject(target); GOMove::SendRemove(player, lowguid); break;
                    case X: GOMove::MoveGameObject(player, player->GetPositionX(), y, z, o, p, lowguid);       break;
                    case Y: GOMove::MoveGameObject(player, x, player->GetPositionY(), z, o, p, lowguid);       break;
                    case Z: GOMove::MoveGameObject(player, x, y, player->GetPositionZ(), o, p, lowguid);       break;
                    case O: GOMove::MoveGameObject(player, x, y, z, player->GetOrientation(), p, lowguid);     break;
                    case RESPAWN: GOMove::SpawnGameObject(player, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), p, target->GetEntry()); break;
                    case GOTO:
                    {
                        // stop flight if need
                        if (player->IsInFlight())
                            player->FinishTaxiFlight();
                        else
                            player->SaveRecallPosition(); // save only in non-flight case
                        player->TeleportTo(target->GetMapId(), x, y, z, o);
                    } break;
                    case GROUND:
                    {
                        float ground = target->GetMap()->GetHeight(target->GetPhaseMask(), x, y, MAX_HEIGHT);
                        if (ground != INVALID_HEIGHT)
                            GOMove::MoveGameObject(player, x, y, ground, o, p, lowguid);
                    } break;
                    case FLOOR:
                    {
                        float floor = target->GetMap()->GetHeight(target->GetPhaseMask(), x, y, z);
                        if (floor != INVALID_HEIGHT)
                            GOMove::MoveGameObject(player, x, y, floor, o, p, lowguid);
                    } break;
                    case INFO:
                    {
                        // Get rotation info
                        QuaternionData rot = target->GetLocalRotation();
                        float ori, pitch, roll;
                        rot.toEulerAnglesZYX(ori, pitch, roll);

                        // Send object info to the addon
                        GOMove::SendInfo(player, lowguid);
                        // Also display in chat for convenience
                        ChatHandler(player->GetSession()).PSendSysMessage("Object: %s (Entry: %u, GUID: %u)", 
                            target->GetName().c_str(), target->GetEntry(), lowguid);
                        ChatHandler(player->GetSession()).PSendSysMessage("Position: %.2f, %.2f, %.2f", x, y, z);
                        ChatHandler(player->GetSession()).PSendSysMessage("Rotation: O=%.2f, Pitch=%.2f, Roll=%.2f", ori, pitch, roll);
                        ChatHandler(player->GetSession()).PSendSysMessage("Phase: %u, Map: %u", p, target->GetMapId());
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
                case SELECTNEAR:
                {
                    GameObject* object = handler->GetNearbyGameObject();
                    if (!object)
                        ChatHandler(player->GetSession()).PSendSysMessage("No objects found");
                    else
                    {
                        GOMove::SendAdd(player, object->GetSpawnId());
                        session->SendAreaTriggerMessage("Selected %s", object->GetName().c_str());
                    }
                } break;
                }
            }
        }
        else if (ARG && ID >= SPAWN)
        {
            if (ID >= NORTH && ID <= PHASE) // Movement and phase commands only
            {
                GameObject* target = GOMove::GetGameObject(player, lowguid);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found", lowguid);
                else
                {
                    float x, y, z, o;
                    target->GetPosition(x, y, z, o);
                    uint32 p = target->GetPhaseMask();

                    // Get current rotation for pitch/roll commands
                    QuaternionData rot = target->GetLocalRotation();
                    float currentO, currentPitch, currentRoll;
                    rot.toEulerAnglesZYX(currentO, currentPitch, currentRoll);

                    switch (ID)
                    {
                    case NORTH: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y, z, o, p, lowguid);                            break;
                    case EAST: GOMove::MoveGameObject(player, x, y - ((float)ARG / 100), z, o, p, lowguid);                             break;
                    case SOUTH: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y, z, o, p, lowguid);                            break;
                    case WEST: GOMove::MoveGameObject(player, x, y + ((float)ARG / 100), z, o, p, lowguid);                             break;
                    case NORTHEAST: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, lowguid);   break;
                    case SOUTHEAST: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y - ((float)ARG / 100), z, o, p, lowguid);   break;
                    case SOUTHWEST: GOMove::MoveGameObject(player, x - ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, lowguid);   break;
                    case NORTHWEST: GOMove::MoveGameObject(player, x + ((float)ARG / 100), y + ((float)ARG / 100), z, o, p, lowguid);   break;
                    case UP: GOMove::MoveGameObject(player, x, y, z + ((float)ARG / 100), o, p, lowguid);                               break;
                    case DOWN: GOMove::MoveGameObject(player, x, y, z - ((float)ARG / 100), o, p, lowguid);                             break;
                    case RIGHT: GOMove::MoveGameObject(player, x, y, z, o - ((float)ARG / 100), p, lowguid);                            break;
                    case LEFT: GOMove::MoveGameObject(player, x, y, z, o + ((float)ARG / 100), p, lowguid);                             break;
                    case PHASE: GOMove::MoveGameObject(player, x, y, z, o, ARG, lowguid);                                               break;
                    }
                }
            }
            else if (ID >= PITCHUP && ID <= SETTURN) // Pitch/roll/turn commands
            {
                GameObject* target = GOMove::GetGameObject(player, lowguid);
                if (!target)
                    ChatHandler(player->GetSession()).PSendSysMessage("Object GUID: %u not found", lowguid);
                else
                {
                    QuaternionData rot = target->GetLocalRotation();
                    float currentO, currentPitch, currentRoll;
                    rot.toEulerAnglesZYX(currentO, currentPitch, currentRoll);

                    switch (ID)
                    {
                    case PITCHUP: GOMove::RotateGameObject(player, currentO, currentPitch + ((float)ARG / 100), currentRoll, lowguid);  break;
                    case PITCHDOWN: GOMove::RotateGameObject(player, currentO, currentPitch - ((float)ARG / 100), currentRoll, lowguid); break;
                    case ROLLRIGHT: GOMove::RotateGameObject(player, currentO, currentPitch, currentRoll + ((float)ARG / 100), lowguid); break;
                    case ROLLLEFT: GOMove::RotateGameObject(player, currentO, currentPitch, currentRoll - ((float)ARG / 100), lowguid);  break;
                    case SETPITCH: GOMove::RotateGameObject(player, currentO, ((float)ARG - 18000.0f) / 100.0f, currentRoll, lowguid); break;
                    case SETROLL: GOMove::RotateGameObject(player, currentO, currentPitch, ((float)ARG - 18000.0f) / 100.0f, lowguid); break;
                    case SETTURN: GOMove::RotateGameObject(player, ((float)ARG - 18000.0f) / 100.0f, currentPitch, currentRoll, lowguid); break;
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
                    for (GameObject const * go : GOMove::GetNearbyGameObjects(player, static_cast<float>(ARG)))
                        GOMove::SendAdd(player, go->GetSpawnId());
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
    new GOMove_player_track();
}
