#include "../pchdef.h"
#include "playerbot.h"
#include "FleeManager.h"
#include "PlayerbotAIConfig.h"
#include "../Groups/Group.h"
#include "strategy/values/LastMovementValue.h"

using namespace ai;
using namespace std;

void FleeManager::calculateDistanceToPlayers(FleePoint *point)
{
	Group* group = bot->GetGroup();
	if (!group)
		return;

	for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
    {
		Player* player = gref->GetSource();
		if(player == bot)
			continue;

		float d = player->GetDistance(point->x, point->y, point->z);
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

	list<ObjectGuid> units = *bot->GetPlayerbotAI()->GetAiObjectContext()->GetValue<list<ObjectGuid> >("possible targets");
	for (list<ObjectGuid>::iterator i = units.begin(); i != units.end(); ++i)
    {
		Unit* unit = bot->GetPlayerbotAI()->GetUnit(*i);
		if (!unit)
		    continue;

		float d = unit->GetDistance(point->x, point->y, point->z);
		if (d <= sPlayerbotAIConfig.tooCloseDistance)
		    continue;

		distance.probe(d);
	}
}

void FleeManager::calculatePossibleDestinations(list<FleePoint*> &points)
{
	float botPosX = bot->GetPositionX();
	float botPosY = bot->GetPositionY();
	float botPosZ = bot->GetPositionZ();

	for (float distance = maxAllowedDistance; distance > sPlayerbotAIConfig.tooCloseDistance + 5.0f; distance -= 5.0f)
	{
        for (float angle = followAngle; angle < followAngle + 2 * M_PI; angle += M_PI / 4)
        {
            float x = botPosX + cos(angle) * distance;
            float y = botPosY + sin(angle) * distance;

            if (!bot->IsWithinLOS(x, y, botPosZ))
                continue;

            FleePoint *point = new FleePoint(x, y, botPosZ);
            calculateDistanceToPlayers(point);
            calculateDistanceToCreatures(point);
            points.push_back(point);
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
	return toAllPlayers.max <= sPlayerbotAIConfig.sightDistance && toCreatures.min >= sPlayerbotAIConfig.tooCloseDistance;
}

bool FleePoint::isBetterByCreatures(FleePoint* other)
{
    return toCreatures.min > 0 && other->toCreatures.min > 0 &&
            (toCreatures.min - other->toCreatures.min) >= 0;
}

bool FleePoint::isBetterByAll(FleePoint* other)
{
    bool isFartherFromCreatures = isBetterByCreatures(other);
    bool isNearerToRangedPlayers = toRangedPlayers.max > 0 && other->toRangedPlayers.max > 0 &&
            (toRangedPlayers.max - other->toRangedPlayers.max) <= 0;
    bool isFartherFromMeleePlayers = toMeleePlayers.min > 0 && other->toMeleePlayers.min > 0 &&
            (toMeleePlayers.min - other->toMeleePlayers.min) >= 0;

    return isFartherFromCreatures && (isNearerToRangedPlayers || isFartherFromMeleePlayers);
}

FleePoint* FleeManager::selectOptimalDestination(list<FleePoint*> &points)
{
	FleePoint* byCreatures = NULL;
	for (list<FleePoint*>::iterator i = points.begin(); i != points.end(); i++)
    {
		FleePoint* point = *i;
		if (point->isReasonable() && (!byCreatures || point->isBetterByCreatures(byCreatures)))
			byCreatures = point;
	}

	FleePoint* byAll = NULL;
	for (list<FleePoint*>::iterator i = points.begin(); i != points.end(); i++)
    {
		FleePoint* point = *i;
		if (point->isReasonable() && (!byAll || point->isBetterByAll(byAll)))
		    byAll = point;
	}

	if (byAll && byCreatures)
	{
	    if (byAll->isBetterByCreatures(byCreatures))
	        return byAll;
	}

	return byCreatures;
}

bool FleeManager::CalculateDestination(float* rx, float* ry, float* rz)
{
    LastMovement& lastMovement = *bot->GetPlayerbotAI()->GetAiObjectContext()->GetValue<LastMovement&>("last movement");
    if ((lastMovement.lastMoveToX || lastMovement.lastMoveToY) && !lastMovement.lastFollow)
    {
        FleePoint last(lastMovement.lastMoveToX, lastMovement.lastMoveToY, lastMovement.lastMoveToZ);
        if (last.isReasonable())
        {
            *rx = lastMovement.lastMoveToX;
            *ry = lastMovement.lastMoveToY;
            *rz = lastMovement.lastMoveToZ;
            return true;
        }
    }

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
	*rz = bot->GetPositionZ();

    cleanup(points);
	return true;
}
