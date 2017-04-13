#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GreetAction.h"

using namespace ai;

GreetAction::GreetAction(PlayerbotAI* ai) : Action(ai, "greet")
{
}

bool GreetAction::Execute(Event event)
{
	ObjectGuid guid = AI_VALUE(ObjectGuid, "new player nearby");
	if (!guid || !guid.IsPlayer()) return false;

	Player* player = dynamic_cast<Player*>(ai->GetUnit(guid));
	if (!player) return false;

	Unit* oldSel = bot->GetSelectedUnit();
	bot->SetSelection(player->GetGUID());
	bot->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
	ai->PlaySound(TEXT_EMOTE_HELLO);
	bot->SetSelection(oldSel->GetGUID());

	set<ObjectGuid>& alreadySeenPlayers = ai->GetAiObjectContext()->GetValue<set<ObjectGuid>& >("already seen players")->Get();
	alreadySeenPlayers.insert(guid);
}