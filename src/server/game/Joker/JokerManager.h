#ifndef JOKER_MANAGER_H
#define JOKER_MANAGER_H

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
};

#define sJokerManager JokerManager::instance()

#endif
