#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "UseMeetingStoneAction.h"
#include "../../PlayerbotAIConfig.h"

bool UseMeetingStoneAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    WorldPacket p(event.getPacket());
    p.rpos(0);
    ObjectGuid guid;
    p >> guid;

    if (master->GetSelectedPlayer() && master->GetSelectedPlayer() != bot)
        return false;

    if (!master->GetSelectedPlayer() && master->GetGroup() != bot->GetGroup())
        return false;

    if (master->IsBeingTeleported())
        return false;

    if (bot->IsInCombat())
    {
        ai->TellMasterNoFacing("I am in combat");
        return false;
    }

    Map* map = master->GetMap();
    if (!map)
        return NULL;

    GameObject *gameObject = map->GetGameObject(guid);
    if (!gameObject)
        return false;

    const GameObjectTemplate* goInfo = gameObject->GetGOInfo();
    if (!goInfo || goInfo->type != GAMEOBJECT_TYPE_SUMMONING_RITUAL)
        return false;

    return Teleport();
}


bool SummonAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    if (master->GetSession()->GetSecurity() < SEC_GAMEMASTER)
    {
        ai->TellMasterNoFacing("You cannot summon me");
        return false;
    }

    return Teleport();
}

bool SummonAction::Teleport()
{
    Player* master = GetMaster();
    if (!master->IsBeingTeleported())
    {
        float followAngle = GetFollowAngle();
        for (float angle = followAngle - M_PI; angle <= followAngle + M_PI; angle += M_PI / 4)
        {
            uint32 mapId = master->GetMapId();
            float x = master->GetPositionX() + cos(angle) * sPlayerbotAIConfig.followDistance;
            float y = master->GetPositionY()+ sin(angle) * sPlayerbotAIConfig.followDistance;
            float z = master->GetPositionZ();
            if (master->IsWithinLOS(x, y, z))
            {
                bot->GetMotionMaster()->Clear();
                bot->TeleportTo(mapId, x, y, z, 0);
                return true;
            }
        }
    }

    ai->TellMasterNoFacing("There is not enough place to summon me");
    return false;
}
