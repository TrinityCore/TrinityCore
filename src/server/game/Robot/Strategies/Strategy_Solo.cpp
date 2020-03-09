#include "Strategy_Solo.h"
#include "RobotManager.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "MotionMaster.h"
#include "Pet.h"
#include "GridNotifiers.h"
#include "Group.h"

Strategy_Solo::Strategy_Solo(uint32 pmAccount, uint32 pmCharacter)
{
    realPrevTime = 0;

    account = pmAccount;
    character = pmCharacter;

    soloState = RobotSoloState::RobotSoloState_Wander;

    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        soloState = RobotSoloState::RobotSoloState_None;
        return;
    }
    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        sb = new Script_Warrior(character);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        sb = new Script_Hunter(character);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        sb = new Script_Shaman(character);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        sb = new Script_Paladin(character);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        sb = new Script_Warlock(character);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        sb = new Script_Priest(character);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        sb = new Script_Rogue(character);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        sb = new Script_Mage(character);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        sb = new Script_Druid(character);
        break;
    }
    }

    deathDelay = 0;
    soloDelay = urand(30 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 60 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
    restDelay = 0;
    waitDelay = 0;
    strollDelay = 0;
    confuseDelay = 0;
    interestsDelay = 0;
}

void Strategy_Solo::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return;
    }
    if (Group* checkGroup = me->GetGroup())
    {
        if (checkGroup->isRaidGroup())
        {
            if (sRobotManager->raidStrategyMap.find(checkGroup->GetLowGUID()) == sRobotManager->raidStrategyMap.end())
            {
                Strategy_Raid* sr = new  Strategy_Raid(checkGroup->GetLowGUID());
                sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()] = sr;
            }
        }
        else
        {
            if (sRobotManager->partyStrategyMap.find(checkGroup->GetLowGUID()) == sRobotManager->partyStrategyMap.end())
            {
                Strategy_Party* sp = new  Strategy_Party(checkGroup->GetLowGUID());
                sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()] = sp;
            }
        }
        return;
    }
    if (interestsDelay > 0)
    {
        interestsDelay -= diff;
    }
    if (!me->IsAlive())
    {
        if (deathDelay > 0)
        {
            deathDelay -= diff;
            if (deathDelay <= 0)
            {
                me->ResurrectPlayer(100.0f);
                sb->Prepare();
                sb->RandomTeleport();
                return;
            }
        }
        else
        {
            deathDelay = urand(1 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 2 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
        }
        return;
    }
    soloDelay -= diff;
    if (soloDelay < 0)
    {
        soloDelay = urand(30 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 60 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
        sb->Prepare();
        sb->RandomTeleport();
        return;
    }
    if (me->IsInCombat())
    {
        soloState = RobotSoloState::RobotSoloState_Battle;
    }
    switch (soloState)
    {
    case RobotSoloState::RobotSoloState_None:
    {
        return;
    }
    case RobotSoloState::RobotSoloState_Wander:
    {
        if (Rest())
        {
            return;
        }
        if (Buff())
        {
            return;
        }
        if (Battle())
        {
            return;
        }
        if (urand(0, 2) < 2)
        {
            if (Stroll())
            {
                return;
            }
        }
        if (urand(0, 2) < 2)
        {
            if (Confuse())
            {
                return;
            }
        }
        if (Wait())
        {
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Battle:
    {
        if (Rest())
        {
            return;
        }
        if (Heal())
        {
            return;
        }
        if (Battle())
        {
            return;
        }
        if (me->GetClass() == Classes::CLASS_HUNTER)
        {
            me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
        }
        soloState = RobotSoloState::RobotSoloState_Wander;
        break;
    }
    case RobotSoloState::RobotSoloState_Rest:
    {
        restDelay -= diff;
        if (restDelay < 0)
        {
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Wait:
    {
        waitDelay -= diff;
        if (waitDelay < 0)
        {
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Stroll:
    {
        strollDelay -= diff;
        if (strollDelay < 0)
        {
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Confuse:
    {
        confuseDelay -= diff;
        if (confuseDelay < 0)
        {
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void Strategy_Solo::Reset()
{
    sb->Prepare();
}

bool Strategy_Solo::Buff()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (me)
    {
        return sb->Buff(me, true);
    }
    return false;
}

bool Strategy_Solo::Rest()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    if (me->IsInCombat())
    {
        return false;
    }
    else
    {
        float hpRate = me->GetHealthPct();
        float mpRate = 100;
        if (me->GetPowerType() == Powers::POWER_MANA)
        {
            mpRate = me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA);
        }
        if (hpRate > 50 && mpRate > 50)
        {
            return false;
        }
        else
        {
            if (sb->Rest())
            {
                soloState = RobotSoloState::RobotSoloState_Rest;
                restDelay = 20 * TimeConstants::IN_MILLISECONDS;
                return true;
            }
        }
    }

    return false;
}

bool Strategy_Solo::Battle()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (sb->Attack(myTarget))
        {
            return true;
        }
    }
    Unit* closestAttacker = NULL;
    float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); attackerIT++)
    {
        if (Unit* pTarget = *attackerIT)
        {
            float distance = me->GetDistance(pTarget);
            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestAttacker = pTarget;
            }
        }
    }
    if (sb->Attack(closestAttacker))
    {
        return true;
    }
    Pet* myPet = me->GetPet();
    if (myPet)
    {
        Unit* petClosestAttacker = NULL;
        float closestDistance = 100;

        for (Unit::AttackerSet::const_iterator attackerIT = myPet->getAttackers().begin(); attackerIT != myPet->getAttackers().end(); attackerIT++)
        {
            if (Unit* pTarget = *attackerIT)
            {
                float distance = me->GetDistance(pTarget);
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    petClosestAttacker = pTarget;
                }
            }
        }

        if (sb->Attack(petClosestAttacker))
        {
            return true;
        }
    }
    std::list<Unit*> attackTargets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, DEFAULT_VISIBILITY_DISTANCE);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, attackTargets, u_check);
    Cell::VisitAllObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);
    Unit* nearestAttackableTarget = NULL;
    float nearestDistance = MAX_VISIBILITY_DISTANCE;
    for (std::list<Unit*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
    {
        if ((*it)->IsPet())
        {
            if (Pet* pet = (*it)->ToPet())
            {
                if (pet->GetCharmerOrOwner())
                {
                    continue;
                }
            }
        }
        if (!me->IsValidAttackTarget((*it)))
        {
            continue;
        }
        if (!me->IsWithinLOSInMap((*it)))
        {
            continue;
        }
        if ((*it)->GetTypeId() == TypeID::TYPEID_PLAYER)
        {
            if (sb->Attack((*it)))
            {
                return true;
            }
        }
        if (Creature* targetCreature = (Creature*)(*it))
        {
            float checkDistance = me->GetDistance((*it));
            if (checkDistance < nearestDistance)
            {
                nearestDistance = checkDistance;
                nearestAttackableTarget = (*it);
            }
        }
    }
    if (sb->Attack(nearestAttackableTarget))
    {
        return true;
    }

    return false;
}

bool Strategy_Solo::Heal()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (me)
    {
        return sb->Heal(me, true);
    }
    return false;
}

bool Strategy_Solo::Wait()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (me)
    {
        me->GetMotionMaster()->Clear();
        me->StopMoving();
        waitDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Wait;
        return true;
    }
    return false;
}

bool Strategy_Solo::Stroll()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (me)
    {
        float destX = 0;
        float destY = 0;
        float destZ = 0;
        Position rdp = me->GetRandomPoint(me->GetPosition(), DEFAULT_VISIBILITY_DISTANCE);
        me->GetMotionMaster()->MovePoint(0, rdp);
        strollDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Stroll;
        return true;
    }
    return false;
}

bool Strategy_Solo::Confuse()
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (me)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->GetMotionMaster()->MoveConfused();
        confuseDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Confuse;
        return true;
    }
    return false;
}

void Strategy_Solo::HandleChatCommand(Player* pmSender, std::string pmCMD)
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return;
    }
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "who")
    {
        sb->WhisperTo(sRobotManager->characterTalentTabNameMap[me->GetClass()][sb->characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
    }
    else if (commandName == "prepare")
    {
        sb->Prepare();
        sb->WhisperTo("I am prepared", Language::LANG_UNIVERSAL, pmSender);
    }
}
