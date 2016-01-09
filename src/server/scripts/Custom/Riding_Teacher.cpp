#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

class Riding_Teacher : public CreatureScript
{
public:
	Riding_Teacher() : CreatureScript("Riding_Teacher") {}

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teach me Riding", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Goodbye", GOSSIP_SENDER_MAIN, 2);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
	{
		if (action == 2)
		{
			player->PlayerTalkClass->SendCloseGossip();
			return false;
		}

		player->LearnSpell(90265, false);     // Master Riding
		player->LearnSpell(54197, false);     // Cold Weather Flying
		player->LearnSpell(115913, false);    // Wisdom of the Four Winds
		player->LearnSpell(191645, false);    // Draenor Pathfinder
		player->LearnSpell(90267, false);     // Flight Master's License

		return true;
	}
};

void AddSC_Riding_Teacher()
{
	new Riding_Teacher;
}