#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ReviveFromCorpseAction.h"
#include "../../PlayerbotFactory.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

bool ReviveFromCorpseAction::Execute(Event event)
{
    Corpse* corpse = bot->GetCorpse();
    if (!corpse)
        return false;

    time_t reclaimTime = corpse->GetGhostTime() + bot->GetCorpseReclaimDelay( corpse->GetType()==CORPSE_RESURRECTABLE_PVP );
    if (reclaimTime > time(0) || corpse->GetDistance(bot) > sPlayerbotAIConfig.spellDistance)
        return false;

    bot->ResurrectPlayer(0.5f);
    bot->SpawnCorpseBones();
    bot->SaveToDB();
    context->GetValue<Unit*>("current target")->Set(NULL);
    bot->SetSelection(ObjectGuid::Empty);
    return true;
}

bool SpiritHealerAction::Execute(Event event)
{
    Corpse* corpse = bot->GetCorpse();
    if (!corpse)
        return false;

    list<ObjectGuid> npcs = AI_VALUE(list<ObjectGuid>, "nearest npcs");
    for (list<ObjectGuid>::iterator i = npcs.begin(); i != npcs.end(); i++)
    {
        Unit* unit = ai->GetUnit(*i);
        if (unit && unit->IsSpiritHealer())
        {
            PlayerbotChatHandler ch(bot);
            bot->ResurrectPlayer(0.5f);
            bot->SpawnCorpseBones();
            bot->SaveToDB();
            context->GetValue<Unit*>("current target")->Set(NULL);
            bot->SetSelection(ObjectGuid::Empty);
            return true;
        }
    }

    ai->TellMaster("Cannot find any spirit healer nearby");
    return false;
}
