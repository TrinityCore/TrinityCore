#ifndef JOKER_MANAGER_H
#define JOKER_MANAGER_H

#ifndef JOKER_MANAGER_SAVE_GAP
#define JOKER_MANAGER_SAVE_GAP 600000
#endif

#ifndef MAX_PET_LOYALTY_LEVEL
#define MAX_PET_LOYALTY_LEVEL 5
#endif

#include <string>
#include "Log.h"
#include "JokerConfig.h"

class JokerManager
{
    JokerManager();
    JokerManager(JokerManager const&) = delete;
    JokerManager& operator=(JokerManager const&) = delete;
    ~JokerManager() = default;

public:
    static JokerManager* instance();
    void UpdateJoker(uint32 pmDiff);

    // EJ instance_encounter 
    std::unordered_set<uint32> ieSet;
    // EJ unique elite set            
    std::unordered_set<uint32> ueSet;
    // EJ raid elite set            
    std::unordered_set<uint32> reSet;

    std::unordered_map<uint32, uint32> petLoyaltyLevelMap;
    std::unordered_map<uint32, uint32> accompanyTimeMap;
    std::unordered_map<uint32, std::unordered_map<uint32, uint32>> expansionCreatureMap;
    std::unordered_map<uint32, std::unordered_set<uint32>> expansionQuestMap;
    std::unordered_map<uint32, std::unordered_set<uint32>> expansionItemMap;
    std::unordered_set<uint32> classicBookSpellSet;

    int updateDelay;
};

#define sJokerManager JokerManager::instance()

#endif
