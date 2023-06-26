#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "Player.h"

#include "World.h"

#include "Battleground.h"

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

        //答题活动
        if (aaCenter.aa_dati_Time > 0 && aaCenter.aa_dati_id > 0) {
            AA_Dati_Conf conf = aaCenter.aa_dati_confs[aaCenter.aa_dati_id];
            if (conf.a != "" || conf.b != "" || conf.c != "" || conf.d != "") {
                if (receivemsg == "a" || receivemsg == "A" || receivemsg == "b" || receivemsg == "B" ||
                    receivemsg == "c" || receivemsg == "C" || receivemsg == "d" || receivemsg == "D") {
                    if (aaCenter.aa_dati_ok[player->GetGUID()]) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[有奖问答]|cffFF0000该题你已经回答过，无法继续作答!");
                    }
                    else {
                        //如果是抢答模式，记录第一个回答正确的人，并给奖励
                        //如果是普通模式，给回答正确的人奖励
                        if (aaCenter.aa_world_confs[97].value1 == 0) { //抢答模式
                            if (aaCenter.aa_dati_first_name != "") {
                                std::string msg = "|cff00FFFF[有奖问答]|cffFF0000该题已经被玩家[" + aaCenter.aa_dati_first_name + "]抢答！";
                                aaCenter.AA_SendMessage(player, 1, msg.c_str());
                            }
                            else {
                                if (receivemsg == conf.result) {
                                    if (conf.gm_win != "" && conf.gm_win != "0") {
                                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[有奖问答]|cffFF0000恭喜你，抢答正确!");
                                        aaCenter.AA_DoCommand(player, conf.gm_win.c_str());
                                    }
                                }
                                else {
                                    if (conf.gm_lose != "" && conf.gm_lose != "0") {
                                        aaCenter.AA_DoCommand(player, conf.gm_lose.c_str());
                                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[有奖问答]|cffFF0000回答错误，不能继续回答此题!");
                                    }
                                }
                            }
                        }
                        else {
                            if (receivemsg == conf.result) {
                                if (conf.gm_win != "" && conf.gm_win != "0") {
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[有奖问答]|cffFF0000恭喜你，回答正确!");
                                    aaCenter.AA_DoCommand(player, conf.gm_win.c_str());
                                }
                            }
                            else {
                                if (conf.gm_lose != "" && conf.gm_lose != "0") {
                                    aaCenter.AA_DoCommand(player, conf.gm_lose.c_str());
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[有奖问答]|cffFF0000回答错误，不能继续回答此题!");
                                }
                            }
                        }
                    }
                    aaCenter.aa_dati_ok[player->GetGUID()] = true; //答过之后，不能再答
                }
            }
        }
    }
};

void AddAA_player_Event()
{
    new aa_player_event();
}
