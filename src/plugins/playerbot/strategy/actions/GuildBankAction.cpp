#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GuildBankAction.h"

#include "../values/ItemCountValue.h"
#include "../../../Guilds/Guild.h"
#include "../../../Guilds/GuildMgr.h"

using namespace std;
using namespace ai;

bool GuildBankAction::Execute(Event event)
{
    string text = event.getParam();
    if (text.empty())
        return false;

    list<ObjectGuid> gos = AI_VALUE(list<ObjectGuid>, "nearest game objects");
    for (list<ObjectGuid>::iterator i = gos.begin(); i != gos.end(); i++)
    {
        GameObject* go = ai->GetGameObject(*i);
        if (!go || !bot->GetGameObjectIfCanInteractWith(go->GetGUID(), GAMEOBJECT_TYPE_GUILD_BANK))
            continue;

        return Execute(text, go);
    }

    ai->TellMaster("Cannot find the guild bank nearby");
    return false;
}

bool GuildBankAction::Execute(string text, GameObject* bank)
{
    bool result = true;

    list<Item*> found = parseItems(text);
    if (found.empty())
        return false;

    for (list<Item*>::iterator i = found.begin(); i != found.end(); i++)
    {
        Item* item = *i;
        if (item)
            result &= MoveFromCharToBank(item, bank);
    }

    return result;
}

bool GuildBankAction::MoveFromCharToBank(Item* item, GameObject* bank)
{
    uint32 playerSlot = item->GetSlot();
    uint32 playerBag = item->GetBagSlot();

    Guild* guild = sGuildMgr->GetGuildById(bot->GetGuildId());
    guild->SwapItems(bot, 0, playerSlot, 0, INVENTORY_SLOT_BAG_0, 0);

    ostringstream out; out << chat->formatItem(item->GetTemplate()) << " put to guild bank";
    ai->TellMaster(out);
    return true;
}
