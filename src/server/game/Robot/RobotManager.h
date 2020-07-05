#ifndef ROBOT_MANAGER_H
#define ROBOT_MANAGER_H

#define enum_to_string(x) #x

#ifndef ROBOT_PASSWORD
# define ROBOT_PASSWORD "robot"
#endif

#ifndef AOE_TARGETS_RANGE
# define AOE_TARGETS_RANGE 5.0f
#endif

#ifndef MID_RANGE
# define MID_RANGE 8.0f
#endif

#ifndef MIN_DISTANCE_GAP
# define MIN_DISTANCE_GAP 0.5f
#endif

#ifndef FOLLOW_MIN_DISTANCE
# define FOLLOW_MIN_DISTANCE 1.0f
#endif

#ifndef FOLLOW_NORMAL_DISTANCE
# define FOLLOW_NORMAL_DISTANCE 15.0f
#endif

#ifndef FOLLOW_FAR_DISTANCE
# define FOLLOW_FAR_DISTANCE 30.0f
#endif

#ifndef FOLLOW_MAX_DISTANCE
# define FOLLOW_MAX_DISTANCE 60.0f
#endif

#ifndef MELEE_MIN_DISTANCE
# define MELEE_MIN_DISTANCE 1.0f
#endif

#ifndef MELEE_MAX_DISTANCE
# define MELEE_MAX_DISTANCE 3.0f
#endif

#ifndef RANGED_NORMAL_DISTANCE
# define RANGED_NORMAL_DISTANCE 20.0f
#endif

#ifndef RANGED_MAX_DISTANCE
# define RANGED_MAX_DISTANCE 45.0f
#endif

#ifndef HEAL_MAX_DISTANCE
# define HEAL_MAX_DISTANCE 40.0f
#endif

#ifndef ATTACK_RANGE_LIMIT
# define ATTACK_RANGE_LIMIT 200.0f
#endif

#ifndef DEFAULT_REST_DELAY
# define DEFAULT_REST_DELAY 20000
#endif

#include "RobotEntity.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <sstream>

enum RobotType :uint32
{
    RobotType_World = 0,
    RobotType_Raid = 1,
};

class RobotManager
{
    RobotManager();
    RobotManager(RobotManager const&) = delete;
    RobotManager& operator=(RobotManager const&) = delete;
    ~RobotManager() = default;

public:
    void InitializeManager();
    void UpdateRobotManager(uint32 pmDiff);
    bool DeleteRobots();
    bool RobotsDeleted();
    bool CheckRobotAccount(uint32 pmAccountID);
    uint32 CheckRobotAccount(std::string pmAccountName);
    uint32 CreateRobotAccount();
    uint32 CheckAccountCharacter(uint32 pmAccountID);
    uint32 GetCharacterRace(uint32 pmCharacterID);
    uint32 CreateRobotCharacter(uint32 pmAccountID);
    uint32 CreateRobotCharacter(uint32 pmAccountID, uint32 pmCharacterClass, uint32 pmCharacterRace);
    bool PrepareRobot(Player* pmRobot);
    std::unordered_set<uint32> GetUsableEquipSlot(const ItemTemplate* pmIT);
    Player* CheckLogin(uint32 pmAccountID, uint32 pmCharacterID);
    bool LoginRobot(uint32 pmAccountID, uint32 pmCharacterID);
    void LogoutRobot(uint32 pmCharacterID);
    void LogoutRobots();
    void HandlePlayerSay(Player* pmPlayer, std::string pmContent);
    void HandleChatCommand(Player* pmSender, std::string pmCMD, Player* pmReceiver = NULL);
    bool StringEndWith(const std::string &str, const std::string &tail);
    bool StringStartWith(const std::string &str, const std::string &head);
    std::vector<std::string> SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored);
    std::string TrimString(std::string srcStr);
    static RobotManager* instance();
    void HandlePacket(WorldSession* pmSession, WorldPacket pmPacket);
    void WhisperTo(Player* pmSender, std::string pmContent, Language pmLanguage, Player* pmTarget);
    bool UnitTargetReachable(Player* pmCheckPlayer, Unit* pmTarget);
    void CheckLevelRobotEntities(uint32 pmLevel, uint32 pmRobotType, uint32 pmTotalCount);

    bool InitializeCharacter(Player* pmTargetPlayer, uint32 pmTargetLevel);
    void InitializeEquipments(Player* pmTargetPlayer, bool pmReset);
    uint32 GetUsableArmorSubClass(Player* pmTargetPlayer);
    bool ApplyGlyph(Player* pmTargetPlayer, uint32 pmGlyphItemEntry, uint32 pmSlot);
    void TryEquip(Player* pmTargetPlayer, std::unordered_set<uint32> pmClassSet, std::unordered_set<uint32> pmSubClassSet, uint32 pmTargetSlot);
    bool EquipNewItem(Player* pmTargetPlayer, uint32 pmItemEntry, uint8 pmEquipSlot);
    void RandomTeleport(Player* pmTargetPlayer);

public:
    std::unordered_map<uint32, std::unordered_map<uint32, uint32>> availableRaces;
    std::unordered_map<uint32, std::string> robotNameMap;

    std::unordered_map<uint8, std::unordered_map<uint8, std::string>> characterTalentTabNameMap;
    std::set<uint32> deleteRobotAccountSet;
    int checkDelay;
    std::unordered_map<uint32, std::unordered_set<RobotEntity*>> robotEntityMap;

    uint32 nameIndex;

    std::unordered_set<uint32> spellRewardClassQuestIDSet;
    std::unordered_map<uint32, uint32> onlinePlayerIDMap;

    std::unordered_map<uint32, uint32> tamableBeastEntryMap;
    std::unordered_map<std::string, std::set<uint32>> spellNameEntryMap;
    std::unordered_set<uint32> lightwellRenewSpellIDSet;
    std::unordered_set<uint32> lightwellUnitEntrySet;

    std::unordered_map<uint32, uint32> orgrimmar_gruntSpawnIDMap;
    std::unordered_map<uint32, uint32> ironforge_guardSpawnIDMap;
};

#define sRobotManager RobotManager::instance()

#endif
