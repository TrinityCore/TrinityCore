#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ChangeTalentsAction.h"

using namespace ai;

bool ChangeTalentsAction::Execute(Event event)
{
    

    string text = event.getParam();
    if (text == "1" || text == "primary")
    {
        bot->ActivateSpec(0);
		bot->Say("Primary talents activated", LANG_UNIVERSAL);
    }
    else if (text == "2" || text == "secondary")
    {
        bot->ActivateSpec(1);
		bot->Say("Secondary talents activated", LANG_UNIVERSAL);
    }
    else
    {
        ostringstream out; 
        switch (bot->GetActiveSpec())
        {
        case 0: out << "Primary";
            break;
        default: out << "Secondary";
            break;
        }
        out << " talents are active";
		ai->TellMaster(out);
    }

    return true;
}
