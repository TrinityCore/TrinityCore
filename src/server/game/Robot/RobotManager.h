#ifndef ROBOT_MANAGER_H
#define ROBOT_MANAGER_H

#ifndef ROBOT_GROUP_COUNT
#define ROBOT_GROUP_COUNT 5
#endif

#include <string>
#include <iostream>
#include <sstream>

class RobotAI;
//class Strategy_Solo_Normal;

class RobotChatCommand
{
public:
    Player* sender;
    std::string chatCommandContent;
};

class RobotManager
{
    RobotManager();
    RobotManager(RobotManager const&) = delete;
    RobotManager& operator=(RobotManager const&) = delete;
    ~RobotManager() = default;

public:
    void InitializeManager();
    void UpdateManager();
    bool DeleteRobots();
    bool RobotsDeleted();
    bool IsRobot(uint32 pmSessionID);
    RobotAI* GetRobotAI(uint32 pmSessionID);
    Player* GetMaster(uint32 pmSessionID);
    uint32 CheckRobotAccount(std::string pmAccountName);
    bool CreateRobotAccount(std::string pmAccountName);
    ObjectGuid CheckAccountCharacter(uint32 pmAccountID);
    bool CreateRobotCharacter(uint32 pmAccountID, uint32 pmCharacterClass, uint32 pmCharacterRace);
    Player* CheckLogin(uint32 pmAccountID, ObjectGuid pmGUID);
    bool LoginRobot(uint32 pmAccountID, ObjectGuid pmGUID);
    void LogoutRobots();
    void HandlePlayerSay(Player* pmPlayer, std::string pmContent);
    bool StringEndWith(const std::string &str, const std::string &tail);
    bool StringStartWith(const std::string &str, const std::string &head);
    std::vector<std::string> SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored);
    std::string TrimString(std::string srcStr);
    static RobotManager* instance();

public:
    std::map<uint32, std::vector<uint32>> availableRaces;
    std::unordered_map<uint32, std::string> robotNameMap;

    std::unordered_map<uint8, std::unordered_map<uint8, std::string>> characterTalentTabNameMap;
    std::set<uint32> deleteRobotAccountSet;
    std::unordered_map<uint32, std::unordered_set<RobotAI*>> robotMap;
    uint32 updateRobotGroupIndex;
    std::unordered_map<uint32, RobotAI*> robotAICache;

    uint32 nameIndex;
    std::set<uint8> armorInventorySet;
    std::unordered_map<uint8, uint8> miscInventoryMap;
    // 0, staff 1, one hand sword 2, two hand sword 3, dagger 4, shield
    // 5, two hand axe 6, polearm
    // type | level range | index entry
    std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint32, uint32>>> meleeWeaponMap;
    // 0, bow / cross bow / gun 1, wand 2, throw
    // type | level range | index entry
    std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint32, uint32>>> rangeWeaponMap;
    // 0, cloth 1, leather 2, mail 3, plate
    // type | slot | level range | index entry
    std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint32, uint32>>>> armorMap;
    // slot | level range | index entry
    std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint32, uint32>>> miscMap;
    std::set<uint32> spellRewardClassQuestIDSet;
    // level range | index
    std::unordered_map<uint8, std::unordered_map<uint32, WorldLocation>> teleportCacheMap;

    std::unordered_map<uint32, uint32> tamableBeastEntryMap;
    std::unordered_map<std::string, std::set<uint32>> spellNameEntryMap;
};

#define sRobotManager RobotManager::instance()

#endif
