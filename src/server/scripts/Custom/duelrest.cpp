#include "ScriptMgr.h"
#include "Player.h"
#include "chat.h"
#include "SpellHistory.h"
#include "Config.h"

class Duel_Reset : public PlayerScript
{
    
public:
	Duel_Reset() : PlayerScript("Duel_Reset"){}             //给决斗后的玩家,自动恢复血量
    
    bool UsingPreDuelInfo=true; // CHange this to false if you want a full reset.
    //原先值默认为真
         

	struct MyData
	{
		uint64 resethealth;
		uint64 resetPower;
		uint64 resetEnergy;
		uint64 resetRage;
	};

	std::unordered_map<ObjectGuid, MyData> playerData;
	void GetInfoPreDuel(Player* playerwin, Player* playerlose)//获取对斗信息
	{
		playerData[playerwin->GetGUID()].resethealth = playerwin->GetHealth();
		playerData[playerwin->GetGUID()].resetPower = playerwin->GetPower(playerwin->GetPowerType());
		playerData[playerlose->GetGUID()].resethealth = playerlose->GetHealth();
		playerData[playerlose->GetGUID()].resetPower = playerlose->GetPower(playerlose->GetPowerType());
	
	}
	void DoFullReset(Player* playerwin, Player* playerlose)
	{
		playerData[playerwin->GetGUID()].resethealth = playerwin->GetMaxHealth();
		playerData[playerwin->GetGUID()].resetPower = playerwin->GetMaxPower(playerlose->GetPowerType());
		playerData[playerlose->GetGUID()].resethealth = playerlose->GetMaxHealth();
		playerData[playerlose->GetGUID()].resetPower = playerlose->GetMaxPower(playerwin->GetPowerType());
	}
    
	void OnDuelStart(Player* playerwin, Player* playerlose)
	{
        if (sConfigMgr->GetBoolDefault("Duel_Reset.enable", false))//获取配置文件,默认未启用
        {
            UsingPreDuelInfo = false;//开启决斗后满血
        }
		if (!UsingPreDuelInfo)
		{
			DoFullReset(playerwin, playerlose);
		}
		if (UsingPreDuelInfo)
		{
			GetInfoPreDuel(playerwin, playerlose);
		}
	}

	void OnDuelEnd(Player* playerwin, Player* playerlose, DuelCompleteType /*type*/)
	{
		playerwin->SetHealth(playerData[playerwin->GetGUID()].resethealth);
		playerwin->SetPower(playerwin->GetPowerType(),playerData[playerwin->GetGUID()].resetPower);
		playerlose->SetHealth(playerData[playerlose->GetGUID()].resethealth);
		playerlose->SetPower(playerlose->GetPowerType(), playerData[playerlose->GetGUID()].resetPower);
				
		if (!UsingPreDuelInfo)
		{
			playerwin->GetSession()->SendNotification("Your Health & Mana has been reset.");
			playerlose->GetSession()->SendNotification("Your Health & Mana has been reset.");
			playerwin->GetSpellHistory()->ResetAllCooldowns();
		}
		else
		{
            playerwin->GetSession()->SendNotification("Congratulations,you win!");//恭喜玩家胜利了
			playerwin->GetSession()->SendNotification("Your Health & Mana has been reset to what they were before the duel!");
            //提示s胜利玩家已经重置了血量和蓝

            playerlose->GetSession()->SendNotification("Come on,you can do it!");//不要放弃,你行的!
			playerlose->GetSession()->SendNotification("Your Health & Mana has been reset to what they were before the duel!");
            //提示失败玩家已经重置了血量和蓝
		}
		playerData.erase(playerwin->GetGUID());
		playerData.erase(playerlose->GetGUID());
	}
};

void AddSC_Duel_Reset()
{
	new Duel_Reset;
}
