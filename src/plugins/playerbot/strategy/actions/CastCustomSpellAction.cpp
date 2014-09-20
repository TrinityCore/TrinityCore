#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "CastCustomSpellAction.h"

using namespace ai;

bool CastCustomSpellAction::Execute(Event event)
{
    Unit* target = NULL;

    Player* master = GetMaster();
    if (master)
        target = master->GetSelectedUnit();

    if (!target)
        target = bot;

    string text = event.getParam();

    uint32 spell = chat->parseSpell(text);

    bool result = false;
    if (spell)
        result = ai->CastSpell(spell, target);
    else
        ai->CastSpell(text, target);

    ostringstream msg;
    if (result)
    {
        msg << "Casting " << text << " on " << target->GetName();
        ai->TellMasterNoFacing(msg.str());
    }
    else
    {
        msg << "Cast " << text << " on " << target->GetName() << " is failed";
        ai->TellMaster(msg.str());
    }

    return result;
}
