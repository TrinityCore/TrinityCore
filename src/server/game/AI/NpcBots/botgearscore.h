#ifndef BOT_GEARSCORE_H_
#define BOT_GEARSCORE_H_

#include "botcommon.h"

#include <utility>

class Creature;
class Item;

struct ItemTemplate;

float CalculateItemGearScore(uint32 botentry, uint8 botlevel, uint8 botclass, uint8 botspec, uint8 slot, ItemTemplate const* proto);
std::pair<float, float> CalculateBotGearScore(uint32 botentry, uint8 botlevel, uint8 botclass, uint8 botspec, Item const* const items[BOT_INVENTORY_SIZE]);

#endif
