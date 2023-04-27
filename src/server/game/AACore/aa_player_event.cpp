#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "Player.h"

#include "World.h"

#include "Battleground.h"

using namespace std;
class aa_player_event : public PlayerScript
{
public:
    aa_player_event() : PlayerScript("aa_player_event") { }
    //发送客户端消息
    void OnChat(Player* player, uint32 type, uint32 lang, std::string& receivemsg) override
    {
        {
            std::set<uint32> aiids = aaCenter.AA_GetAis(player, "说话");
            for (auto id : aiids) {
                if (id > 0) {
                    AA_Ai conf = aaCenter.aa_ais[id];
                    if (conf.event_param5 == receivemsg) {
                        aaCenter.AA_AiStart(player, nullptr, id);
                    }
                }
            }
        }
    }
};

void AddAA_player_Event()
{ 
    new aa_player_event();
}
