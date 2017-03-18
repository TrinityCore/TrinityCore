/*
This small script allows for a reward to automatically go into the inventory of any player that makes it to a specific level.
Make sure to modify this script before using. You must hard code in the money amounts, and item entry numbers, plus spell numbers.
An example:
This is the part of the cpp file you must edit. I will explain each part.
case 10:
money = 100;
item = ITEMID;
item2 = ITEMID2;
spell = SPELLID;
break;
Here is the breakdown:
case 10: (10 = Level 10)
money = 100; (100 = 100 gold)
item = ITEMID; (Change ITEMID to the entry number of the item you want offered at this level)
item2 = ITEMID2; (Change ITEMID2 to the entry number of second item)
spell = SPELLID; (Change SPELLID to the spell id number)
break;
So if you wanted to offer 100 gold, a pet cat (pet carrier, black tabby) and a pet cockroach, plus buff the player with Power Word: Fortitude, it would look like this:
case 10:
money = 100;
item = 8491;
item2 = 10393;
spell = 48161;
break;
You must do this for each level you want to have give rewards. At this time, since items are automatically added, the player loses the reward(s) if
their bags are full.
*/
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include "ObjectGuid.h"
#include "ObjectMgr.h"


class custom_CongratsOnLevel : public PlayerScript
{
public:
	custom_CongratsOnLevel() : PlayerScript("custom_CongratsOnLevel") { }

	void OnLevelChanged(Player* player, uint8 newLevel)
	{
		uint32 money /*item, item2, spell*/;


		if (sConfigMgr->GetBoolDefault("Congrats.Level", true)) {
			switch (++newLevel)
			{
			case 10:
				//1G
				money = 1;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;

				break;
			case 20:
				//10G
				money = 10;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 30:
				//25G
				money = 25;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 40:
				//50G
				money = 50;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 50:
				//100G
				money = 100;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 60:
				//200G
				money = 200;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 70:
				//500G
				money = 500;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			case 80:
				//1000G
				money = 1000;
				//item = ITEMID;
				//item2 = ITEMID2;
				//spell = SPELLID;
				break;
			default:
				return;
			}

			std::ostringstream ss;
			ss << "|cffFF0000[The Server]|r  congratulates" << player->GetName() << " for reaching Level " << (uint32)newLevel;
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());

			std::ostringstream ss2;
			//ss2 << "Du wurdest mit " << money << " gold und Items belohnt!";
			//ss2 << "Du wurdest mit " << money << " Gold belohnt!";
			//player->GetSession()->SendNotification(ss2.str().c_str());
			player->ModifyMoney(money*GOLD);
			//player->AddItem(item, 1);
			//player->AddItem(item2, 1);
			//player->learnSpell(spell, false);
		}
	}


};

void AddSC_custom_CongratsOnLevel()
{
	new custom_CongratsOnLevel();
}