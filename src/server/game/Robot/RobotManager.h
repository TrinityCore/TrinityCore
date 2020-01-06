#ifndef ROBOT_MANAGER_H
#define ROBOT_MANAGER_H

#include <string>
#include "Log.h"
#include "RobotConfig.h"
#include "Accounts/AccountMgr.h"
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Pet.h"
#include "Server/WorldSession.h"
#include "Globals/ObjectMgr.h"
#include "MotionMaster.h"
#include "Maps/MapManager.h"
#include "Groups/Group.h"
#include "Robot/RobotAI.h"
#include "Item.h"
#include "Strategies/Strategy_Solo_Normal.h"
#include "World/World.h"
#include "SpellInfo.h"

class RobotAI;
class Strategy_Solo_Normal;

class RobotManager
{
    RobotManager();
    RobotManager(RobotManager const&) = delete;
    RobotManager& operator=(RobotManager const&) = delete;
    ~RobotManager() = default;

public:
    void Preparation();
    void UpdateManager(uint32 pmDiff);
    void UpdateRobots();
    bool DeleteRobots();
    bool RobotsDeleted();
    bool CreateRobotAccount(std::string pmAccountName);
	bool CreateRobotCharacter(uint32 pmAccountID, uint8 pmCharacterClass, uint8 pmCharacterRace, uint8 pmCharacterLevel);
    bool LoginRobot(uint32 pmAccountID, ObjectGuid pmGUID);
    void LogoutRobots();
    bool LogoutRobot(Player* pmPlayer);    
    bool ProcessRobots();
    bool ProcessRobot(Player* pmPlayer);
    bool AdjustActiveRobots(std::unordered_map<uint32, WorldSession*> pmActiveSessionMap);
    void HandlePlayerSay(Player* pmPlayer, std::string pmContent);
    bool StringEndWith(const std::string &str, const std::string &tail);
    bool StringStartWith(const std::string &str, const std::string &head);
    std::vector<std::string> SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored);
    std::string TrimString(std::string srcStr);
    static RobotManager* instance();

public:
    // 0, nothing 1, delete robots 2, check delete 3, process robots 20, error
    uint8 managerState;
	std::map<uint8, std::vector<uint32>> availableRaces;
    std::unordered_map<uint32, std::string> robotNameMap;    
    int32 checkDelay;

    std::unordered_map<uint8, std::unordered_map<uint8, std::string>> characterTalentTabNameMap;
    std::set<uint32> deleteRobotAccountSet;
    std::unordered_map<uint32, std::unordered_map<uint32, uint8>> robotAccountMap;

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

    std::unordered_map<uint32, WorldSession*> activeRobotSessionMap;
    bool updateActiveRobotSessionMap;
    uint32 updateIndex;

    int activeRobotsCheckDelay;
};

#define sRobotManager RobotManager::instance()

#endif
