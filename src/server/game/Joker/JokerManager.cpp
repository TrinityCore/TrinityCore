#include "JokerManager.h"

JokerManager::JokerManager()
{

}

JokerManager* JokerManager::instance()
{
    static JokerManager instance;
    return &instance;
}
