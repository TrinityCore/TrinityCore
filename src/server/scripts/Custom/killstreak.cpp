#include "ScriptMgr.h"
#include "Config.h"
#include <Player.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// KILLSTREAK CONFIG ////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int32 AmountOfItemsYouWantTheVictimToLoose = 1;
int32 ItemReward = 23247;
int32 AmountOfRewardsOnKillStreak[9] = { 4, 6, 8, 10, 12, 14, 16, 18, 20 };
int32 HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim = 2;
const int32 KillerStreak1 = 05;
const int32 KillerStreak2 = 10;
const int32 KillerStreak3 = 15;
const int32 KillerStreak4 = 20;
const int32 KillerStreak5 = 30;
const int32 KillerStreak6 = 40;
const int32 KillerStreak7 = 50;
const int32 KillerStreak8 = 60;
const int32 KillerStreak9 = 70;
int32 KillStreaks[9] = { KillerStreak1, KillerStreak2, KillerStreak3, KillerStreak4, KillerStreak5, KillerStreak6, KillerStreak7, KillerStreak8, KillerStreak9 };
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct SystemInfo
{
	uint32 KillStreak;
	uint32 LastGUIDKill;
	uint8 KillCount;
};

static std::map<uint32, SystemInfo> KillingStreak;

class killstreak_system : public PlayerScript
{
public:
	killstreak_system() : PlayerScript("killstreak_system") { }

	void OnPVPKill(Player* killer, Player* killed)
	{
		if (sConfigMgr->GetBoolDefault("Killstreak.Enable", true))
		{
			uint32 kGUID; 
			uint32 vGUID;
			char msg[500];
			kGUID = killer->GetGUID();
			vGUID = killed->GetGUID();

			if (kGUID == vGUID)
			{
				return;
			}

			if (KillingStreak[kGUID].LastGUIDKill == vGUID)
			{
				KillingStreak[kGUID].KillCount++;
				if (KillingStreak[vGUID].KillStreak >= 5)
				{
					std::ostringstream ss;
					ss << "|cffFF0000[Psychosis PvP]:|r |cff00FF00"
						<< killer->GetName() 
						<< "|r has ended |cff00FF00" 
						<< killed->GetName() 
						<< "'s|r kill streak of |cff00FFFF" 
						<< KillingStreak[vGUID].KillCount 
						<< "|r!";
					sWorld->SendGlobalText(ss.str().c_str(), NULL);
				}
				KillingStreak[vGUID].KillCount = 1;
				killer->AddItem(ItemReward, 1);
				if (sConfigMgr->GetBoolDefault("Killstreak.Enable", true))
					killed->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true, false);
			}
			if (KillingStreak[kGUID].LastGUIDKill != vGUID)
			{
				KillingStreak[kGUID].KillCount = 1;
				KillingStreak[vGUID].KillCount = 1;
			}

			if (KillingStreak[kGUID].KillCount == HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim)
			{
				return;
			}

			if (sConfigMgr->GetBoolDefault("Loose.Token.On.PvP.Death", true))
			{
				if (!killer->GetMap()->IsBattleground() || killer->GetMapId() == 30)
				{
					return;
				}
			}

			KillingStreak[kGUID].KillStreak++;
			KillingStreak[vGUID].KillStreak = 0;
			KillingStreak[kGUID].LastGUIDKill = vGUID;
			KillingStreak[vGUID].LastGUIDKill = 0;

			if (sConfigMgr->GetBoolDefault("Add.Token.On.PvP.Kill", true))
			{
				killer->AddItem(29435, 1);
			}

			if (sConfigMgr->GetBoolDefault("Loose.Token.On.PvP.Death", true))
			{
				killed->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true);
			}

			switch(KillingStreak[kGUID].KillStreak)
			{
				case KillerStreak1:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF5|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[1]);
					killer->ModifyHonorPoints(500);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak2:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF10|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[2]);
					killer->ModifyHonorPoints(1000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak3:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF15|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[3]);
					killer->ModifyHonorPoints(1500);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak4:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF20|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[4]);
					killer->ModifyHonorPoints(2000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak5:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF30|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[5]);
					killer->ModifyHonorPoints(3000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak6:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF40|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[6]);
					killer->ModifyHonorPoints(4000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak7:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF50|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[7]);
					killer->ModifyHonorPoints(5000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak8:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF60|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[8]);
					killer->ModifyHonorPoints(6000);
					killer->CastSpell(killer, 24378, true);
					break;

				case KillerStreak9:
					sprintf(msg, "|cffFF0000[KillStreak]: |cff00FF00%s|r killed |cff00FF00%s|r and is on |cff00FFFF70|r kill streak.", killer->GetName().c_str(), killed->GetName().c_str());
					sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
					killer->AddItem(ItemReward, AmountOfRewardsOnKillStreak[9]);
					KillingStreak[kGUID].KillStreak = 0;
					killer->ModifyHonorPoints(7000);
					killer->CastSpell(killer, 24378, true);
					break;
			}
		}
	}
};

void AddSC_killstreak_system()
{
	new killstreak_system;
}