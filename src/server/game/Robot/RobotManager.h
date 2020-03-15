#ifndef ROBOT_MANAGER_H
#define ROBOT_MANAGER_H

#define enum_to_string(x) #x

#ifndef ROBOT_PASSWORD
# define ROBOT_PASSWORD "robot"
#endif

#include "RobotEntity.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <sstream>

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
    uint32 CreateRobotCharacter(uint32 pmAccountID);
    uint32 CreateRobotCharacter(uint32 pmAccountID, uint32 pmCharacterClass, uint32 pmCharacterRace);
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
    void HandlePacket(WorldSession* pmSession, WorldPacket const* pmPacket);
    void WhisperTo(Player* pmSender, std::string pmContent, Language pmLanguage, Player* pmTarget);

public:
    std::unordered_map<uint32, std::unordered_map<uint32, uint32>> availableRaces;
    std::unordered_map<uint32, std::string> robotNameMap;

    std::unordered_map<uint8, std::unordered_map<uint8, std::string>> characterTalentTabNameMap;
    std::set<uint32> deleteRobotAccountSet;
    int checkDelay;
    std::unordered_set<RobotEntity*> reSet;

    uint32 nameIndex;
    std::set<uint8> armorInventorySet;
    std::unordered_map<uint8, uint8> miscInventoryMap;
    // 0, staff 1, one hand sword 2, two hand sword 3, one hand mace 4, two hand mace 5, two hand axe 6, dagger 7, shield
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
    std::unordered_set<uint32> spellRewardClassQuestIDSet;
    std::unordered_map<uint32, uint32> onlinePlayerIDMap;

    std::unordered_map<uint32, uint32> tamableBeastEntryMap;
    std::unordered_map<std::string, std::set<uint32>> spellNameEntryMap;
};

#define sRobotManager RobotManager::instance()

#endif
