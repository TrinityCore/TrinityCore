#ifndef REFORGING_H
#define REFORGING_H

#include "Define.h"
#include <vector>

class Player;
class Item;
struct ReforgeData;

// Supply lowguid or reforge! (or both)
// Warning, this function may modify player->reforgeMap when lowguid is supplied
void TC_GAME_API SendReforgePacket(Player* player, uint32 entry, uint32 lowguid = 0, const ReforgeData* reforge = NULL);
void TC_GAME_API SendReforgePackets(Player* player);
void TC_GAME_API RemoveReforge(Player* player, uint32 itemguid, bool update);
std::vector<Item*> TC_GAME_API GetItemList(const Player* player);

#endif
