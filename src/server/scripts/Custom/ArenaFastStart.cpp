#include "ScriptPCH.h"

class FastArenaCrystal : public GameObjectScript
{
    public:

        FastArenaCrystal()
            : GameObjectScript("FastArenaCrystal")
        {
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
                    ChatHandler(player).PSendSysMessage("Players clicked: %u", bg->ClickFastStart(player, go));

            return false;
        }
};

void AddSC_fast_arena_start()
{
    new FastArenaCrystal();
}