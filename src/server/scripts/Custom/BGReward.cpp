#include "ScriptMgr.h"
#include "Configuration/Config.h"
#include "Battleground.h"

class Kargatum_Reward_Battleground : public PlayerScript
{
public:
    Kargatum_Reward_Battleground() : PlayerScript("Kargatum_Reward_Battleground") {}

    void OnBattlegroundEndReward(Battleground* bg, Player* player, TeamId winnerTeamId)
    {
        if (!sConfigMgr->GetBoolDefault("BG.Reward.Enable", true))
            return;

        // Not reward on end arena
        if (bg->isArena())
            return;

        // Reward ItemID
        uint32 ItemID_WSG = sConfigMgr->GetIntDefault("BG.Reward.ItemID.WSG", 20558);
        uint32 ItemID_ARATHI = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Arathi", 20559);
        uint32 ItemID_ALTERAC = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Alterac", 20560);
        uint32 ItemID_ISLE = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Isle", 47395);
        uint32 ItemID_ANCIENT = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Ancients", 42425);
        uint32 ItemID_EYE = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Eye", 29024);

        // Reward Count
        uint32 WinnerCount = sConfigMgr->GetIntDefault("BG.Reward.WinnerTeam.Count", 3);
        uint32 LoserCount = sConfigMgr->GetIntDefault("BG.Reward.LoserTeam.Count", 1);

        TeamId bgTeamId = player->GetTeamId();
        uint32 RewardCount = 0;

        bgTeamId == winnerTeamId ? (RewardCount = WinnerCount) : (RewardCount = LoserCount);

        switch (player->GetZoneId())
        {
        case 3277: // Warsong Gulch
            player->AddItem(ItemID_WSG, RewardCount);
            break;
        case 3358: // Arathi Basin
            player->AddItem(ItemID_ARATHI, RewardCount);
            break;
        case 3820: // Eye of the Storm
            player->AddItem(ItemID_EYE, RewardCount);
            break;
        case 4710: // Isle of Conquest
            player->AddItem(ItemID_ISLE, RewardCount);
            break;
        case 4384: // Strand of the Ancients
            player->AddItem(ItemID_ANCIENT, RewardCount);
            break;
        case 2597: // Alterac Valley
            player->AddItem(ItemID_ALTERAC, RewardCount);
            break;
        default:
            break;
        }
    }
};

void AddSC_BGRewardScripts()
{
    new Kargatum_Reward_Battleground();
}
