#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SaveManaAction.h"
#include "../../AiFactory.h"
#include "../ItemVisitors.h"

using namespace ai;

bool SaveManaAction::Execute(Event event)
{
    string text = event.getParam();
    double value = AI_VALUE(double, "mana save level");

    if (text == "?")
    {
        ostringstream out; out << "Mana save level: " << format(value);
        ai->TellMaster(out);
        return true;
    }

    if (text == "*")
    {
        switch (bot->getClass())
        {
        case CLASS_HUNTER:
        case CLASS_SHAMAN:
        case CLASS_DRUID:
            value = 5.0;
            break;
        case CLASS_MAGE:
        case CLASS_PRIEST:
        case CLASS_WARLOCK:
            value = 2.0;
            break;
        default:
            value = 3.0;
        }
    }
    else if (text.empty())
    {
        value = 1.0;
    }
    else
    {
        value = atof(text.c_str());
    }

    value = min(10.0, value);
    value = max(1.0, value);
    value = floor(value * 100 + 0.5) / 100.0;

    ai->GetAiObjectContext()->GetValue<double>("mana save level")->Set(value);

    ostringstream out; out << "Mana save level set: " << format(value);
    ai->TellMaster(out);

    return true;
}

string SaveManaAction::format(double value)
{
    ostringstream out;
    if (value <= 1.0)
        out << "|cFF808080";
    else if (value <= 5.0)
        out << "|cFF00FF00";
    else if (value <= 7.0)
        out << "|cFFFFFF00";
    else
        out << "|cFFFF0000";
    out << value << "|cffffffff";
    return out.str();
}
