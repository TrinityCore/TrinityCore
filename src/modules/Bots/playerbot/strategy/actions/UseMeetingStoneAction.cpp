#include "botpch.h"
#include "../../playerbot.h"
#include "UseMeetingStoneAction.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

using namespace MaNGOS;

bool UseMeetingStoneAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    WorldPacket p(event.getPacket());
    p.rpos(0);
    ObjectGuid guid;
    p >> guid;

	if (master->GetSelectionGuid() && master->GetSelectionGuid() != bot->GetObjectGuid())
		return false;

	if (!master->GetSelectionGuid() && master->GetGroup() != bot->GetGroup())
		return false;

    if (master->IsBeingTeleported())
        return false;

    if (sServerFacade.IsInCombat(bot))
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

	const GameObjectInfo* goInfo = gameObject->GetGOInfo();
	if (!goInfo || goInfo->type != GAMEOBJECT_TYPE_SUMMONING_RITUAL)
        return false;

    return Teleport(master, bot);
}

class AnyGameObjectInObjectRangeCheck
{
public:
    AnyGameObjectInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) {}
    WorldObject const& GetFocusObject() const { return *i_obj; }
    bool operator()(GameObject* u)
    {
        if (u && i_obj->IsWithinDistInMap(u, i_range) && sServerFacade.isSpawned(u) && u->GetGOInfo())
            return true;

        return false;
    }

private:
    WorldObject const* i_obj;
    float i_range;
};


bool SummonAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    if (master->GetSession()->GetSecurity() >= SEC_PLAYER)
        return Teleport(master, bot);

    if (SummonUsingGos(master, bot) || SummonUsingNpcs(master, bot))
    {
        ai->TellMasterNoFacing("Hello!");
        return true;
    }

    if (SummonUsingGos(bot, master) || SummonUsingNpcs(bot, master))
    {
        ai->TellMasterNoFacing("Welcome!");
        return true;
    }

    return false;
}


bool SummonAction::SummonUsingGos(Player *summoner, Player *player)
{
    list<GameObject*> targets;
    AnyGameObjectInObjectRangeCheck u_check(summoner, sPlayerbotAIConfig.sightDistance);
    GameObjectListSearcher<AnyGameObjectInObjectRangeCheck> searcher(targets, u_check);
    Cell::VisitAllObjects((const WorldObject*)summoner, searcher, sPlayerbotAIConfig.sightDistance);

    for(list<GameObject*>::iterator tIter = targets.begin(); tIter != targets.end(); ++tIter)
    {
        GameObject* go = *tIter;
        if (go && sServerFacade.isSpawned(go) && go->GetGoType() == GAMEOBJECT_TYPE_MEETINGSTONE)
            return Teleport(summoner, player);
    }

    ai->TellMasterNoFacing(summoner == bot ? "There is no meeting stone nearby" : "There is no meeting stone near you");
    return false;
}

bool SummonAction::SummonUsingNpcs(Player *summoner, Player *player)
{
    if (!sPlayerbotAIConfig.summonAtInnkeepersEnabled)
        return false;

    list<Unit*> targets;
    AnyUnitInObjectRangeCheck u_check(summoner, sPlayerbotAIConfig.sightDistance);
    UnitListSearcher<AnyUnitInObjectRangeCheck> searcher(targets, u_check);
    Cell::VisitAllObjects(summoner, searcher, sPlayerbotAIConfig.sightDistance);
    for(list<Unit*>::iterator tIter = targets.begin(); tIter != targets.end(); ++tIter)
    {
        Unit* unit = *tIter;
        if (unit && unit->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_INNKEEPER))
        {
            if (!player->HasItemCount(6948, 1, false))
            {
                ai->TellMasterNoFacing(player == bot ? "I have no hearthstone" : "You have no hearthstone");
                return false;
            }

            if (!sServerFacade.IsSpellReady(player, 8690))
            {
                ai->TellMasterNoFacing(player == bot ? "My hearthstone is not ready" : "Your hearthstone is not ready");
                return false;
            }

            // Trigger cooldown
            SpellEntry const* spellInfo = sServerFacade.LookupSpellInfo(8690);
            if (!spellInfo)
                return false;
            Spell spell(player, spellInfo,
#ifdef MANGOS
                    0
#endif
#ifdef CMANGOS
                    TRIGGERED_OLD_TRIGGERED
#endif
                    );
            spell.SendSpellCooldown();

            return Teleport(summoner, player);
        }
    }

    ai->TellMasterNoFacing(summoner == bot ? "There are no innkeepers nearby" : "There are no innkeepers near you");
    return false;
}

bool SummonAction::Teleport(Player *summoner, Player *player)
{
    Player* master = GetMaster();
    if (!summoner->IsBeingTeleported() && !player->IsBeingTeleported())
    {
        float followAngle = GetFollowAngle();
        for (float angle = followAngle - M_PI; angle <= followAngle + M_PI; angle += M_PI / 4)
        {
            uint32 mapId = summoner->GetMapId();
            float x = summoner->GetPositionX() + cos(angle) * sPlayerbotAIConfig.followDistance;
            float y = summoner->GetPositionY()+ sin(angle) * sPlayerbotAIConfig.followDistance;
            float z = summoner->GetPositionZ();
            if (summoner->IsWithinLOS(x, y, z))
            {
                player->GetMotionMaster()->Clear();
                player->TeleportTo(mapId, x, y, z, 0);
                return true;
            }
        }
    }

    ai->TellMasterNoFacing("Not enough place to summon");
    return false;
}
