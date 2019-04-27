#ifndef PROJECT_UTIL_PLACEHOLDER_H
#define PROJECT_UTIL_PLACEHOLDER_H

#include "project.h"
#include "project_language.h"
#include "project_messages.h"
#include "LFG.h"
#include "Player.h"
#include "World.h"
#include "Map.h"

#pragma once

#ifdef PROJECT_CUSTOM
#include "project_util.h"
#else

enum EquipmentSlots : uint8;

namespace PROJECT
{
    namespace Utils
    {
        namespace Azerite
        {
            TC_GAME_API inline void SendAzeriteReforgeRespec(Player* player, ObjectGuid guid) {};
        }
        namespace Players
        {
            TC_GAME_API inline void UpdateAverageItemLevel(Player* player) {};
            TC_GAME_API inline float GetRateForPlayer(Player * player, Rates RateType) { return sWorld->getRate(RateType); };
            TC_GAME_API inline bool IsPlayerBoundToCurrentMap(Player * player) { return true; };
            TC_GAME_API inline float GET_FLOAT_VALUE(Unit * caster, uint16 index) { return caster->GetFloatValue(index); };
            TC_GAME_API inline bool PlayerHasFlag(Player * player, uint32 flag) { return !!(player->Variables.GetValue<uint32>("PlayerFlags") & flag); };
            TC_GAME_API inline uint32 GetPendingGroupUpdateMask(Player * player) { return player->m_groupUpdateMask; };
            TC_GAME_API inline void UpdateResilience(Player * player) {};
            TC_GAME_API inline void UpdateItemBonuses(Player * player) {};
            TC_GAME_API inline float GetPvPPowerBonus(Player * player, bool isHealing) { return 0.0f; };
            TC_GAME_API inline bool IsPvPPowerActive(Unit * caster, Unit * victim, SpellInfo const * spellInfo = NULL) { return false; };
            TC_GAME_API inline void MovementForceApply(Player * player, AreaTrigger* areaTrigger, float magnitude) {};
            TC_GAME_API inline void MovementForceRemove(Player * player, AreaTrigger* areaTrigger) {};
            TC_GAME_API inline bool IsPvP(Unit * caster, Unit * target) { return true; };
            TC_GAME_API inline PROJECT::Constants::PlayerRoles GetRoleForPlayer(Player * player) { return PROJECT::Constants::PlayerRoles::ROLE_NONE; };
            TC_GAME_API inline lfg::LfgRoles GetLfgRole(Player* player) { return lfg::LfgRoles::PLAYER_ROLE_NONE; };
            TC_GAME_API inline void Ban(Player * player, const char * duration, const char * reason) {};
            TC_GAME_API inline void ModifyCurrencyRaw(Player * player, uint32 id, int32 count) {};
            TC_GAME_API inline bool IsReagentPos(uint8 bag, uint8 slot)
            {
                if (bag == INVENTORY_SLOT_BAG_0 && (slot >= REAGENT_SLOT_START && slot < REAGENT_SLOT_END))
                    return true;
                return false;
            };
            TC_GAME_API inline bool IsReagentPos(uint16 pos) { return IsReagentPos(pos >> 8, pos & 255); };
            TC_GAME_API inline void SendGarrisonRemoteInfo(Player* player) {};
        }

        namespace PvE
        {
            TC_GAME_API inline uint32 GetEncounterInProgress(Player * player) { return 0; };

            namespace BossTimers
            {
                TC_GAME_API inline void Initialize(Creature* creature, bool defaultCase = false) {};
                TC_GAME_API inline void Wipe(Creature* creature, bool defaultCase = false) {};
                TC_GAME_API inline void Start(Creature* creature, bool defaultCase = false) {};
                TC_GAME_API inline void Done(Creature* creature, bool defaultCase = false) {};
            }
        }

        namespace Items
        {
            TC_GAME_API inline bool HasBonus(Item* item, uint32 bonusID) { return false; };
            TC_GAME_API inline void LoadItemModifiers(Player* player, Item* item, PreparedQueryResult modifiersResult) {};
            TC_GAME_API inline void SaveItemModifiers(Item* item, SQLTransaction& trans) {};
            TC_GAME_API inline void HandleRelicScaling(Item* item, ItemDynamicFieldGems const* gem, BonusData& gemBonus, uint32& gemBaseItemLevel) {};
        }

        namespace Maps
        {
            TC_GAME_API inline float GetVisibilityDistanceForGrid(Map * map, int32 gridX = -1, int32 gridY = -1) { return map->GetVisibilityRange(); };
            TC_GAME_API inline void SendChallengeModeStart(InstanceScript* script, Player* player = nullptr) {};
            TC_GAME_API inline void SendChallengeStartElapsedTimer(InstanceScript* script, uint32 timerID, Player* player = nullptr) {};
            TC_GAME_API inline void SendChallengeStartTimer(InstanceScript* script, uint32 time) {};
            TC_GAME_API inline void ScheduleChallengeStartup(InstanceScript* script, uint32 diff) {};
            TC_GAME_API inline void ScheduleChallengeTimeUpdate(InstanceScript* script, uint32 diff) {};
            TC_GAME_API inline void SetChallengeModeStarted(InstanceScript* script) {};
            TC_GAME_API inline bool IsAllEncountersFinished(InstanceScript* script) { return false; };
            TC_GAME_API inline bool IsChallengeMode(Map* map) { return false; };
        }

        namespace Quests
        {
            TC_GAME_API inline void ObjectiveSatisfy(Player * player, int32 type, uint32 amount = 1, uint32 objectID = 0, uint32 objectiveid = 0) {};
            TC_GAME_API inline void Complete(Player * player, uint32 entry) {};
        }

        namespace Packets
        {
            TC_GAME_API inline void ShowOpcodeDebug(WorldPacket * packet, WorldSession * session, bool serverToClient) {};
        }

        namespace Artifacts
        {
            TC_GAME_API inline bool HandleEquipOnSpecChange(Player* player, uint32 newSpecId, uint32 isPet) { return true; };
        }

        namespace Misc
        {
            TC_GAME_API inline uint32 GetTime() { return (uint32)time(NULL); };
            TC_GAME_API inline uint32 GenerateGenerateLowGuidForRecycling(HighGuid highGuid)
            {
                uint32 maxGuid = 0;
                QueryResult result = NULL;
                switch (highGuid)
                {
                case HighGuid::Creature:
                    /*
                    // find GUID gaps // need to think of a better way, this is too CPU consuming
                    for (int i = PROJECT::Config->GetInt("GUIDRecycleStart"); i <= PROJECT::Config->GetInt("GUIDRecycleEnd"); i++)
                    if (!WorldDatabase.PQuery("SELECT guid FROM `creature` WHERE guid = %u", i))
                    return i;
                    */
                    result = WorldDatabase.PQuery("SELECT MAX(guid) FROM `creature` WHERE guid >= %u AND guid <= %u", PROJECT::Config->GetInt("GUIDRecycleStart"), PROJECT::Config->GetInt("GUIDRecycleEnd"));
                    break;
                case HighGuid::GameObject:
                    result = WorldDatabase.PQuery("SELECT MAX(guid) FROM `gameobject` WHERE guid >= %u AND guid <= %u", PROJECT::Config->GetInt("GUIDRecycleStart"), PROJECT::Config->GetInt("GUIDRecycleEnd"));
                    break;
                default:
                    ASSERT(false && "unhandled HIGHGUID type");
                    break;
                }

                maxGuid = (result->Fetch())[0].GetUInt32();
                if (!maxGuid)
                    maxGuid = PROJECT::Config->GetInt("GUIDRecycleStart");
                return maxGuid + 1;
            };
            TC_GAME_API inline bool CanEntityIgnoreGroundPosition(WorldObject const* entity)
            {
                if (!entity)
                    return false;

                if (Creature * creature = const_cast<Creature*>(entity->ToCreature()))
                {
                    // if ignoring MMAPS then also ignore ground position
                    if (creature->GetCreatureTemplate()->flagsEx2 & PROJECT::Constants::Creatures::FlagsEx2::IGNORE_MMAPS)
                        return true;
                    // if smooth movement disabled ignore ground position but only if creature shouldn't be flying
                    if (creature->Variables.IsSet("Movement.SmoothMovementDisabled") && !(creature->GetCreatureTemplate()->InhabitType & INHABIT_AIR))
                        return true;
                }

                return false;
            };
            TC_GAME_API inline bool CanEntityIgnoreLoS(WorldObject const* entity) { return false; };
            TC_GAME_API inline bool IsTargetAlwaysValidForAttack(Unit const* caster, Unit const* target) { return false; };
            TC_GAME_API inline bool IsTargetAlwaysInvalidForAttack(Unit const* caster, Unit const* target) { return false; };
            TC_GAME_API inline void MythicCompleted(InstanceScript* instance) {};
            TC_GAME_API inline void GetTargets_After(SmartScriptHolder const& e, ObjectList* l, WorldObject* baseObject) {};
        }

        namespace Creatures
        {
            TC_GAME_API inline uint64 GetMaxScaledHealth(Creature const* creature, uint8 playerLevel) { return 1; };
            TC_GAME_API inline uint8 GetScaledLevel(Creature const* creature, Unit const* target) { return creature->getLevel(); };
            TC_GAME_API inline bool CanScale(Creature const* creature, Unit const* unit) { return false; };
        }

        namespace Generators
        {
            namespace Hotfixes
            {
                TC_GAME_API inline void GenerateData(boost::any entry) {};
            }
        }

        namespace Battlegrounds
        {
            TC_GAME_API inline void ResetDailyFirsts() {};
        }
    }

    namespace Scenes
    {
        TC_GAME_API inline void Play(Player * player, uint32 scenePackageId, ObjectGuid npcGuid = ObjectGuid::Empty) {};
        TC_GAME_API inline void PlaybackDone(Player * player, SceneTemplate const* sceneTemplate = NULL) {};
    }

    namespace Conversations
    {
        TC_GAME_API inline void ConversationCompleted(Conversation* conversation) {};
    }
}
#endif
#endif
