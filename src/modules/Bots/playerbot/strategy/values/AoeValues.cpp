#include "botpch.h"
#include "../../playerbot.h"
#include "AoeValues.h"

#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
using namespace ai;

list<ObjectGuid> FindMaxDensity(Player* bot)
{
    list<ObjectGuid> units = *bot->GetPlayerbotAI()->GetAiObjectContext()->GetValue<list<ObjectGuid> >("all targets");
    map<ObjectGuid, list<ObjectGuid> > groups;
    int maxCount = 0;
    ObjectGuid maxGroup;
    for (list<ObjectGuid>::iterator i = units.begin(); i != units.end(); ++i)
    {
        Unit* unit = bot->GetPlayerbotAI()->GetUnit(*i);
        if (!unit)
            continue;

        for (list<ObjectGuid>::iterator j = units.begin(); j != units.end(); ++j)
        {
            Unit* other = bot->GetPlayerbotAI()->GetUnit(*j);
            if (!other)
                continue;

            float d = sServerFacade.GetDistance2d(unit, other);
            if (sServerFacade.IsDistanceLessOrEqualThan(d, sPlayerbotAIConfig.aoeRadius * 2))
                groups[*i].push_back(*j);
        }

        if (maxCount < groups[*i].size())
        {
            maxCount = groups[*i].size();
            maxGroup = *i;
        }
    }

    if (!maxCount)
        return list<ObjectGuid>();

    return groups[maxGroup];
}

WorldLocation AoePositionValue::Calculate()
{
    list<ObjectGuid> group = FindMaxDensity(bot);
    if (group.empty())
        return WorldLocation();

    float x1, y1, x2, y2;
    for (list<ObjectGuid>::iterator i = group.begin(); i != group.end(); ++i)
    {
        Unit* unit = bot->GetPlayerbotAI()->GetUnit(*i);
        if (!unit)
            continue;

        if (i == group.begin() || x1 > unit->GetPositionX())
            x1 = unit->GetPositionX();
        if (i == group.begin() || x2 < unit->GetPositionX())
            x2 = unit->GetPositionX();
        if (i == group.begin() || y1 > unit->GetPositionY())
            y1 = unit->GetPositionY();
        if (i == group.begin() || y2 < unit->GetPositionY())
            y2 = unit->GetPositionY();
    }
    float x = (x1 + x2) / 2;
    float y = (y1 + y2) / 2;
    float z = bot->GetPositionZ() + CONTACT_DISTANCE;;
    bot->UpdateAllowedPositionZ(x, y, z);
    return WorldLocation(bot->GetMapId(), x, y, z, 0);
}

uint8 AoeCountValue::Calculate()
{
    return FindMaxDensity(bot).size();
}
