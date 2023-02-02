#include "../botpch.h"
#include "playerbot.h"
#include "FleeManager.h"
#include "PlayerbotAIConfig.h"
#include "Group.h"
#include "strategy/values/LastMovementValue.h"
#include "ServerFacade.h"

using namespace ai;
using namespace std;

void FleeManager::calculateDistanceToPlayers(FleePoint *point)
{
	Group* group = bot->GetGroup();
	if (!group)
		return;

	for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
    {
		Player* player = gref->getSource();
		if(player == bot)
			continue;

		float d = sServerFacade.GetDistance2d(player, point->x, point->y);
		point->toAllPlayers.probe(d);
		switch (player->getClass()) {
			case CLASS_HUNTER:
			case CLASS_MAGE:
			case CLASS_PRIEST:
			case CLASS_WARLOCK:
				point->toRangedPlayers.probe(d);
				break;
			case CLASS_PALADIN:
			case CLASS_ROGUE:
			case CLASS_WARRIOR:
				point->toMeleePlayers.probe(d);
				break;
		}
	}
}

void FleeManager::calculateDistanceToCreatures(FleePoint *point)
{
	RangePair &distance = point->toCreatures;

	list<ObjectGuid> units = *bot->GetPlayerbotAI()->GetAiObjectContext()->GetValue<list<ObjectGuid> >("all targets");
	for (list<ObjectGuid>::iterator i = units.begin(); i != units.end(); ++i)
    {
		Unit* unit = bot->GetPlayerbotAI()->GetUnit(*i);
		if (!unit)
		    continue;

		float d = sServerFacade.GetDistance2d(unit, point->x, point->y);
		distance.probe(d);
	}
}

void FleeManager::calculatePossibleDestinations(list<FleePoint*> &points)
{
	float botPosX = bot->GetPositionX();
	float botPosY = bot->GetPositionY();
	float botPosZ = bot->GetPositionZ();

	for (float distance = sPlayerbotAIConfig.tooCloseDistance; distance <= maxAllowedDistance; distance += 1.0f)
	{
        for (float angle = followAngle; angle < followAngle + 2 * M_PI; angle += M_PI / 8)
        {
            float x = botPosX + cos(angle) * distance;
            float y = botPosY + sin(angle) * distance;
            float z = botPosZ;
            bot->UpdateAllowedPositionZ(x, y, z);

            if (!bot->IsWithinLOS(x, y, z))
                continue;

            Map* map = bot->GetMap();
            const TerrainInfo* terrain = map->GetTerrain();
            if (terrain && terrain->IsInWater(x, y, z))
                continue;

            FleePoint *point = new FleePoint(x, y, z);
            calculateDistanceToPlayers(point);
            calculateDistanceToCreatures(point);

            if (point->isReasonable())
                points.push_back(point);
            else
                delete point;
        }
	}
}

void FleeManager::cleanup(list<FleePoint*> &points)
{
	for (list<FleePoint*>::iterator i = points.begin(); i != points.end(); i++)
    {
		FleePoint* point = *i;
		delete point;
	}
	points.clear();
}

bool FleePoint::isReasonable()
{
	return toCreatures.min >= 0 && toCreatures.max >= 0 &&
	        toAllPlayers.min >= 0 && toAllPlayers.max >= 0 &&
	        toAllPlayers.min <= sPlayerbotAIConfig.spellDistance &&
	        toAllPlayers.max <= sPlayerbotAIConfig.sightDistance &&
	        toCreatures.min >= sPlayerbotAIConfig.tooCloseDistance &&
	        toCreatures.max >= sPlayerbotAIConfig.shootDistance;
}

FleePoint* FleeManager::selectOptimalDestination(list<FleePoint*> &points)
{
	FleePoint* best = NULL;
	for (list<FleePoint*>::iterator i = points.begin(); i != points.end(); i++)
    {
		FleePoint* point = *i;
		if (!best || (point->toCreatures.min - best->toCreatures.min) >= 0.5f)
		{
            best = point;
		}
        else if ((point->toCreatures.min - best->toCreatures.min) >= 0)
        {
            if (point->toRangedPlayers.max >= 0 && best->toRangedPlayers.max >= 0 &&
                    (point->toRangedPlayers.max - best->toRangedPlayers.max) <= 0.5f)
            {
                best = point;
            }
            else if (point->toMeleePlayers.max >= 0 && best->toMeleePlayers.max >= 0 &&
                    (point->toMeleePlayers.min - best->toMeleePlayers.min) >= 0.5f)
            {
                best = point;
            }
        }
	}

	return best;
}

bool FleeManager::CalculateDestination(float* rx, float* ry, float* rz)
{
	list<FleePoint*> points;
	calculatePossibleDestinations(points);

    FleePoint* point = selectOptimalDestination(points);
    if (!point)
    {
        cleanup(points);
        return false;
    }

	*rx = point->x;
	*ry = point->y;
	*rz = point->z;

    cleanup(points);
	return true;
}
