#include "Strategy_Solo.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "Pet.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include "RobotManager.h"
#include "RobotConfig.h"

Strategy_Solo::Strategy_Solo(Player* pmMe)
{
    me = pmMe;
    soloState = RobotSoloState::RobotSoloState_Wander;
    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        sb = new Script_Warrior(me);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        sb = new Script_Hunter(me);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        sb = new Script_Shaman(me);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        sb = new Script_Paladin(me);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        sb = new Script_Warlock(me);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        sb = new Script_Priest(me);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        sb = new Script_Rogue(me);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        sb = new Script_Mage(me);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        sb = new Script_Druid(me);
        break;
    }
    }

    deathDelay = 0;
    soloDelay = urand(sRobotConfig->SoloMinDelay, sRobotConfig->SoloMaxDelay);
    restDelay = 0;
    waitDelay = 0;
    strollDelay = 0;
    confuseDelay = 0;
    interestsDelay = 0;
    engageDelay = 0;
}

void Strategy_Solo::Update(uint32 pmDiff)
{
    if (interestsDelay > 0)
    {
        interestsDelay -= pmDiff;
    }
    if (!me->IsAlive())
    {
        if (deathDelay > 0)
        {
            deathDelay -= pmDiff;
            if (deathDelay <= 0)
            {                                
                sb->RandomTeleport();
                return;
            }
        }
        else
        {
            deathDelay = urand(sRobotConfig->DeathMinDelay, sRobotConfig->DeathMaxDelay);
        }
        return;
    }
    soloDelay -= pmDiff;
    if (soloDelay < 0)
    {        
        sb->RandomTeleport();
        return;
    }
    switch (soloState)
    {
    case RobotSoloState::RobotSoloState_None:
    {
        return;
    }
    case RobotSoloState::RobotSoloState_Wander:
    {
        if (me->IsInCombat())
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        if (Rest())
        {
            return;
        }
        if (Buff())
        {
            return;
        }
        if (PVP())
        {
            engageDelay = 20 * TimeConstants::IN_MILLISECONDS;
            return;
        }
        if (urand(0, 1) == 0)
        {
            if (Confuse())
            {
                return;
            }
        }
        if (urand(0, 1) == 0)
        {
            if (Stroll())
            {
                return;
            }
        }
        if (Battle())
        {
            engageDelay = 10 * TimeConstants::IN_MILLISECONDS;
            return;
        }
        if (Wait())
        {
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Battle:
    {
        if (me->IsInCombat())
        {
            engageDelay = 0;
            if (me->GetHealthPct() < 40.0f)
            {
                if (Heal())
                {
                    return;
                }
            }
            if (Battle())
            {
                return;
            }
            if (me->GetClass() == Classes::CLASS_HUNTER)
            {
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
            }
        }
        else
        {
            if (engageDelay > 0)
            {
                engageDelay -= pmDiff;
            }
            if (engageDelay <= 0)
            {
                engageDelay = 0;
                soloState = RobotSoloState::RobotSoloState_Wander;
            }
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Rest:
    {
        if (me->IsInCombat())
        {
            restDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        restDelay -= pmDiff;
        if (restDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Wait:
    {
        if (me->IsInCombat())
        {
            waitDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        waitDelay -= pmDiff;
        if (waitDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Stroll:
    {
        if (me->IsInCombat())
        {
            strollDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        strollDelay -= pmDiff;
        if (strollDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Confuse:
    {
        if (me->IsInCombat())
        {
            confuseDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        confuseDelay -= pmDiff;
        if (confuseDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
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

bool Strategy_Solo::Buff()
{
    if (me)
    {
        return sb->Buff(me, true);
    }
    return false;
}

bool Strategy_Solo::Rest()
{
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
                restDelay = DEFAULT_REST_DELAY;
                return true;
            }
        }
    }

    return false;
}

bool Strategy_Solo::Battle()
{
    if (!me)
    {
        return false;
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (Player* targetPlayer = myTarget->ToPlayer())
        {
            if (sb->Attack(targetPlayer))
            {
                return true;
            }
        }
    }
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); attackerIT++)
    {
        if (Unit* pTarget = *attackerIT)
        {
            if (Player* targetPlayer = pTarget->ToPlayer())
            {
                if (sb->Attack(targetPlayer))
                {
                    return true;
                }
            }
        }
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
        if (Unit* eachU = *it)
        {
            if (eachU->IsPet())
            {
                if (Pet* pet = eachU->ToPet())
                {
                    if (pet->GetCharmerOrOwner())
                    {
                        continue;
                    }
                }
            }
            if (!me->IsValidAttackTarget(eachU))
            {
                continue;
            }
            if (!me->IsWithinLOSInMap(eachU))
            {
                continue;
            }
            if (eachU->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (sb->Attack(eachU))
                {
                    return true;
                }
            }
            float checkDistance = me->GetDistance(eachU);
            if (checkDistance < nearestDistance)
            {
                nearestDistance = checkDistance;
                nearestAttackableTarget = eachU;
            }
        }
    }
    if (sb->Attack(nearestAttackableTarget))
    {
        return true;
    }

    return false;
}

bool Strategy_Solo::PVP()
{
    if (!me)
    {
        return false;
    }
    std::list<Player*> attackTargets;
    Trinity::AnyPlayerInObjectRangeCheck u_check(me, DEFAULT_VISIBILITY_DISTANCE);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, attackTargets, u_check);
    Cell::VisitWorldObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);
    for (std::list<Player*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
    {
        if (Player* eachPlayer = *it)
        {
            if (sb->Attack(eachPlayer))
            {
                return true;
            }
        }
    }

    return false;
}

bool Strategy_Solo::Heal()
{
    if (me)
    {
        return sb->Heal(me, true);
    }
    return false;
}

bool Strategy_Solo::Wait()
{
    if (me)
    {
        sb->ClearTarget();
        me->AttackStop();
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
    // EJ confuse issue use wait instead
    return Wait();

    if (me)
    {
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveConfused();
        confuseDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Confuse;
        return true;
    }
    return false;
}

void Strategy_Solo::HandleChatCommand(Player* pmSender, std::string pmCMD)
{
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

void Strategy_Solo::Reset()
{
    deathDelay = 0;
    confuseDelay = 0;
    engageDelay = 0;
    restDelay = 0;
    soloDelay = urand(sRobotConfig->SoloMinDelay, sRobotConfig->SoloMaxDelay);
    waitDelay = 0;
    strollDelay = 0;
    soloState = RobotSoloState::RobotSoloState_Wander;
}
