#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackAction.h"
#include "../../../Movement/MovementGenerator.h"
#include "../../../game/AI/CreatureAI.h"
#include "../../../Entities/Pet/Pet.h"
#include "../../LootObjectStack.h"

using namespace ai;

bool AttackAction::Execute(Event event)
{
    Unit* target = GetTarget();

    if (!target)
        return false;

    return Attack(target);
}

bool AttackMyTargetAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    Unit* target = master->GetSelectedUnit();
    if (!target)
    {
        if (verbose) bot->Say("You have no target", LANG_UNIVERSAL);
        return false;
    }

    return Attack(target);
}

bool AttackAction::Attack(Unit* target)
{
    MotionMaster &mm = *bot->GetMotionMaster();
    if (bot->IsFlying())
    {
        if (verbose) bot->Say("I cannot attack in flight", LANG_UNIVERSAL);
        return false;
    }

    if (!target)
    {
        if (verbose) bot->Say("I have no target", LANG_UNIVERSAL);
        return false;
    }

    ostringstream msg;
    msg << target->GetName();
    if (bot->IsFriendlyTo(target))
    {
        msg << " is friendly to me";
        if (verbose) bot->Say(msg.str(), LANG_UNIVERSAL);
        return false;
    }
	if (target->isDead())
	{
		msg << " is dead";
		if (verbose) bot->Say(msg.str(), LANG_UNIVERSAL);
		return false;
	}
    if (!bot->InBattleground() && !bot->IsWithinLOSInMap(target))
    {
        msg << " is not on my sight";
        if (verbose) bot->Say(msg.str(), LANG_UNIVERSAL);
        return false;
    }

	if (bot->IsMounted() && bot->IsWithinLOSInMap(target))
    {
        WorldPacket emptyPacket;
        bot->GetSession()->HandleCancelMountAuraOpcode(emptyPacket);
    }

    ObjectGuid guid = target->GetGUID();
    bot->SetSelection(target->GetGUID());

    Unit* oldTarget = context->GetValue<Unit*>("current target")->Get();
    context->GetValue<Unit*>("old target")->Set(oldTarget);

    context->GetValue<Unit*>("current target")->Set(target);
    context->GetValue<LootObjectStack*>("available loot")->Get()->Add(guid);

    Pet* pet = bot->GetPet();
    if (pet)
    {
        pet->SetTarget(target->GetGUID());
        pet->AI()->EnterCombat(target);
		pet->GetCharmInfo()->SetIsCommandAttack(true);
		pet->AI()->AttackStart(target);
    }

    bot->Attack(target, true);
    ai->ChangeEngine(BOT_STATE_COMBAT);
    return true;
}

bool AttackDuelOpponentAction::isUseful()
{
    return AI_VALUE(Unit*, "duel target");
}

bool AttackDuelOpponentAction::Execute(Event event)
{
    return Attack(AI_VALUE(Unit*, "duel target"));
}
