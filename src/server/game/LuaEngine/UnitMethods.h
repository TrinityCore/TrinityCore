/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef UNITMETHODS_H
#define UNITMETHODS_H

/***
 * Inherits all methods from: [Object], [WorldObject]
 */
namespace LuaUnit
{
    /**
     * The [Unit] tries to attack a given target
     *
     * @param [Unit] who : [Unit] to attack
     * @param bool meleeAttack = false: attack with melee or not
     * @return didAttack : if the [Unit] did not attack
     */
    int Attack(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* who = Eluna::CHECKOBJ<Unit>(L, 2);
        bool meleeAttack = Eluna::CHECKVAL<bool>(L, 3, false);

        Eluna::Push(L, unit->Attack(who, meleeAttack));
        return 1;
    }

    /**
     * The [Unit] stops attacking its target
     *
     * @return bool isAttacking : if the [Unit] wasn't attacking already
     */
    int AttackStop(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->AttackStop());
        return 1;
    }

    /**
     * Returns true if the [Unit] is standing.
     *
     * @return bool isStanding
     */
    int IsStandState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsStandState());
        return 1;
    }

    /**
     * Returns true if the [Unit] is mounted.
     *
     * @return bool isMounted
     */
    int IsMounted(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsMounted());
        return 1;
    }

    /**
     * Returns true if the [Unit] is rooted.
     *
     * @return bool isRooted
     */
    int IsRooted(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef TRINITY
        Eluna::Push(L, unit->isInRoots() || unit->HasUnitMovementFlag(MOVEMENTFLAG_ROOT));
#endif
#ifdef CMANGOS
        Eluna::Push(L, unit->isInRoots() || unit->IsRooted());
#endif
#ifdef MANGOS
        Eluna::Push(L, unit->IsInRoots() || unit->IsRooted());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] has full health.
     *
     * @return bool hasFullHealth
     */
    int IsFullHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsFullHealth());
        return 1;
    }

    /**
     * Returns true if the [WorldObject] is within given radius of the [Unit].
     *
     * @param [WorldObject] obj
     * @param float radius
     * @return bool withinDist
     */
    int IsWithinDistInMap(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);
        float radius = Eluna::CHECKVAL<float>(L, 3);

        Eluna::Push(L, unit->IsWithinDistInMap(obj, radius));
        return 1;
    }

    /**
     * Returns true if the [Unit] is in an accessible place for the given [Creature].
     *
     * @param [WorldObject] obj
     * @param float radius
     * @return bool isAccessible
     */
    int IsInAccessiblePlaceFor(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Creature* creature = Eluna::CHECKOBJ<Creature>(L, 2);

#ifndef TRINITY
        Eluna::Push(L, unit->isInAccessablePlaceFor(creature));
#else
        Eluna::Push(L, unit->isInAccessiblePlaceFor(creature));
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] an auctioneer.
     *
     * @return bool isAuctioneer
     */
    int IsAuctioneer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->isAuctioner());
#else
        Eluna::Push(L, unit->IsAuctioner());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] a guild master.
     *
     * @return bool isGuildMaster
     */
    int IsGuildMaster(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isGuildMaster());
#else
        Eluna::Push(L, unit->IsGuildMaster());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] an innkeeper.
     *
     * @return bool isInnkeeper
     */
    int IsInnkeeper(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isInnkeeper());
#else
        Eluna::Push(L, unit->IsInnkeeper());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] a trainer.
     *
     * @return bool isTrainer
     */
    int IsTrainer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isTrainer());
#else
        Eluna::Push(L, unit->IsTrainer());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is able to show a gossip window.
     *
     * @return bool hasGossip
     */
    int IsGossip(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isGossip());
#else
        Eluna::Push(L, unit->IsGossip());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a taxi master.
     *
     * @return bool isTaxi
     */
    int IsTaxi(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isTaxi());
#else
        Eluna::Push(L, unit->IsTaxi());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a spirit healer.
     *
     * @return bool isSpiritHealer
     */
    int IsSpiritHealer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isSpiritHealer());
#else
        Eluna::Push(L, unit->IsSpiritHealer());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a spirit guide.
     *
     * @return bool isSpiritGuide
     */
    int IsSpiritGuide(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isSpiritGuide());
#else
        Eluna::Push(L, unit->IsSpiritGuide());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a tabard designer.
     *
     * @return bool isTabardDesigner
     */
    int IsTabardDesigner(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isTabardDesigner());
#else
        Eluna::Push(L, unit->IsTabardDesigner());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] provides services like vendor, training and auction.
     *
     * @return bool isTabardDesigner
     */
    int IsServiceProvider(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isServiceProvider());
#else
        Eluna::Push(L, unit->IsServiceProvider());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a spirit guide or spirit healer.
     *
     * @return bool isSpiritService
     */
    int IsSpiritService(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isSpiritService());
#else
        Eluna::Push(L, unit->IsSpiritService());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is alive.
     *
     * @return bool isAlive
     */
    int IsAlive(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isAlive());
#else
        Eluna::Push(L, unit->IsAlive());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is dead.
     *
     * @return bool isDead
     */
    int IsDead(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef MANGOS
        Eluna::Push(L, unit->IsDead());
#else
        Eluna::Push(L, unit->isDead());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is dying.
     *
     * @return bool isDying
     */
    int IsDying(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef MANGOS
        Eluna::Push(L, unit->IsDying());
#else
        Eluna::Push(L, unit->isDying());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a banker.
     *
     * @return bool isBanker
     */
    int IsBanker(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isBanker());
#else
        Eluna::Push(L, unit->IsBanker());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a vendor.
     *
     * @return bool isVendor
     */
    int IsVendor(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isVendor());
#else
        Eluna::Push(L, unit->IsVendor());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a battle master.
     *
     * @return bool isBattleMaster
     */
    int IsBattleMaster(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isBattleMaster());
#else
        Eluna::Push(L, unit->IsBattleMaster());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is a charmed.
     *
     * @return bool isCharmed
     */
    int IsCharmed(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isCharmed());
#else
        Eluna::Push(L, unit->IsCharmed());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is an armorer and can repair equipment.
     *
     * @return bool isArmorer
     */
    int IsArmorer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isArmorer());
#else
        Eluna::Push(L, unit->IsArmorer());
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] is attacking a player.
     *
     * @return bool isAttackingPlayer
     */
    int IsAttackingPlayer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->isAttackingPlayer());
        return 1;
    }

    /**
     * Returns true if the [Unit] flagged for PvP.
     *
     * @return bool isPvP
     */
    int IsPvPFlagged(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsPvP());
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns true if the [Unit] is on a [Vehicle].
     *
     * @return bool isOnVehicle
     */
    int IsOnVehicle(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->IsBoarded());
#else
        Eluna::Push(L, unit->GetVehicle());
#endif
        return 1;
    }
#endif
    
    /**
     * Returns true if the [Unit] is in combat.
     *
     * @return bool inCombat
     */
    int IsInCombat(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isInCombat());
#else
        Eluna::Push(L, unit->IsInCombat());
#endif
        return 1;
    }
    
    /**
     * Returns true if the [Unit] is under water.
     *
     * @return bool underWater
     */
    int IsUnderWater(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsUnderWater());
        return 1;
    }
    
    /**
     * Returns true if the [Unit] is in water.
     *
     * @return bool inWater
     */
    int IsInWater(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsInWater());
        return 1;
    }
    
    /**
     * Returns true if the [Unit] is not moving.
     *
     * @return bool notMoving
     */
    int IsStopped(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsStopped());
        return 1;
    }
    
    /**
     * Returns true if the [Unit] is a quest giver.
     *
     * @return bool questGiver
     */
    int IsQuestGiver(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef CMANGOS
        Eluna::Push(L, unit->isQuestGiver());
#else
        Eluna::Push(L, unit->IsQuestGiver());
#endif
        return 1;
    }
    
    /**
     * Returns true if the [Unit]'s health is below the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isBelow
     */
    int HealthBelowPct(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->HealthBelowPct(Eluna::CHECKVAL<int32>(L, 2)));
        return 1;
    }
    
    /**
     * Returns true if the [Unit]'s health is above the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isAbove
     */
    int HealthAbovePct(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->HealthAbovePct(Eluna::CHECKVAL<int32>(L, 2)));
        return 1;
    }
    
    /**
     * Returns true if the [Unit] has an aura from the given spell entry.
     *
     * @param uint32 spell : entry of the aura spell
     * @return bool hasAura
     */
    int HasAura(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, unit->HasAura(spell));
        return 1;
    }

    /**
     * Returns true if the [Unit] is casting a spell
     *
     * @return bool isCasting
     */
    int IsCasting(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef TRINITY
        Eluna::Push(L, unit->HasUnitState(UNIT_STATE_CASTING));
#else
        Eluna::Push(L, unit->IsNonMeleeSpellCasted(false));
#endif
        return 1;
    }

    /**
     * Returns true if the [Unit] has the given unit state.
     *
     * @param [UnitState] state : an unit state
     * @return bool hasState
     */
    int HasUnitState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef TRINITY
        Eluna::Push(L, unit->hasUnitState(state));
#else
        Eluna::Push(L, unit->HasUnitState(state));
#endif
        return 1;
    }

    /*int IsVisible(Eluna* E, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsVisible());
        return 1;
    }*/

    /*int IsMoving(Eluna* E, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->isMoving());
        return 1;
    }*/

    /*int IsFlying(Eluna* E, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->IsFlying());
        return 1;
    }*/
    
    /**
     * Returns the [Unit]'s owner.
     *
     * @return [Unit] owner
     */
    int GetOwner(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetOwner());
        return 1;
    }
    
    /**
     * Returns the [Unit]'s owner's GUID.
     *
     * @return uint64 ownerGUID
     */
    int GetOwnerGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetOwnerGuid());
#else
        Eluna::Push(L, unit->GetOwnerGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the [Unit]'s mount's modelID.
     *
     * @return uint32 mountId : displayId of the mount
     */
    int GetMountId(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetMountID());
        return 1;
    }
    
    /**
     * Returns the [Unit]'s creator's GUID.
     *
     * @return uint64 creatorGUID
     */
    int GetCreatorGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCreatorGuid());
#else
        Eluna::Push(L, unit->GetCreatorGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the [Unit]'s charmer's GUID.
     *
     * @return uint64 charmerGUID
     */
    int GetCharmerGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCharmerGuid());
#else
        Eluna::Push(L, unit->GetCharmerGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the GUID of the [Unit]'s charmed entity.
     *
     * @return uint64 charmedGUID
     */
    int GetCharmGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCharmGuid());
#else
        Eluna::Push(L, unit->GetCharmGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the GUID of the [Unit]'s pet.
     *
     * @return uint64 petGUID
     */
    int GetPetGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetPetGuid());
#else
        Eluna::Push(L, unit->GetPetGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the GUID of the [Unit]'s charmer or owner.
     *
     * @return uint64 controllerGUID
     */
    int GetControllerGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCharmerOrOwnerGuid());
#else
        Eluna::Push(L, unit->GetCharmerOrOwnerGUID());
#endif
        return 1;
    }
    
    /**
     * Returns the GUID of the [Unit]'s charmer or owner or its own GUID.
     *
     * @return uint64 controllerGUID
     */
    int GetControllerGUIDS(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCharmerOrOwnerOrOwnGuid());
#else
        Eluna::Push(L, unit->GetCharmerOrOwnerOrOwnGUID());
#endif
        return 1;
    }

    /**
     * Returns [Unit]'s specified stat
     *
     * @param uint32 statType
     * @return float stat
     */
    int GetStat(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 stat = Eluna::CHECKVAL<uint32>(L, 2);

        if (stat >= MAX_STATS)
            return 1;

        Eluna::Push(L, unit->GetStat((Stats)stat));
        return 1;
    }

    /**
     * Returns the [Unit]'s base spell power
     *
     * @param uint32 spellSchool
     * @return uint32 spellPower
     */
    int GetBaseSpellPower(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spellschool = Eluna::CHECKVAL<uint32>(L, 2);

        if (spellschool >= MAX_SPELL_SCHOOL)
            return 1;

        Eluna::Push(L, unit->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + spellschool));
        return 1;
    }
    
    /**
     * Returns the [Unit]'s current victim target or nil.
     *
     * @return [Unit] victim
     */
    int GetVictim(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->getVictim());
#else
        Eluna::Push(L, unit->GetVictim());
#endif
        return 1;
    }

    /**
     * Returns the currently casted [Spell] of given type or nil.
     *
     * <pre>
     * enum CurrentSpellTypes
     * {
     *     CURRENT_MELEE_SPELL             = 0,
     *     CURRENT_GENERIC_SPELL           = 1,
     *     CURRENT_CHANNELED_SPELL         = 2,
     *     CURRENT_AUTOREPEAT_SPELL        = 3
     * };
     * </pre>
     *
     * @param [CurrentSpellTypes] spellType
     * @return [Spell] castedSpell
     */
    int GetCurrentSpell(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        if (type >= CURRENT_MAX_SPELL)
            return luaL_argerror(L, 2, "valid CurrentSpellTypes expected");

        Eluna::Push(L, unit->GetCurrentSpell(type));
        return 1;
    }
    
    /**
     * Returns the [Unit]'s current stand state.
     *
     * @return uint8 standState
     */
    int GetStandState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef TRINITY
        Eluna::Push(L, unit->GetStandState());
#else
        Eluna::Push(L, unit->getStandState());
#endif
        return 1;
    }
    
    /**
     * Returns the [Unit]'s current display ID.
     *
     * @return uint32 displayId
     */
    int GetDisplayId(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetDisplayId());
        return 1;
    }
    
    /**
     * Returns the [Unit]'s native/original display ID.
     *
     * @return uint32 displayId
     */
    int GetNativeDisplayId(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetNativeDisplayId());
        return 1;
    }
    
    /**
     * Returns the [Unit]'s level.
     *
     * @return uint8 level
     */
    int GetLevel(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->getLevel());
        return 1;
    }
    
    /**
     * Returns the [Unit]'s health amount.
     *
     * @return uint32 healthAmount
     */
    int GetHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetHealth());
        return 1;
    }

    Powers PowerSelectorHelper(Eluna* /*E*/, lua_State* L, Unit* unit, int powerType = -1)
    {
#ifdef TRINITY
        if (powerType == -1)
            return unit->getPowerType();
#else
        if (powerType == -1)
            return unit->GetPowerType();
#endif

        if (powerType < 0 || powerType >= int(MAX_POWERS))
            luaL_argerror(L, 2, "valid Powers expected");

        return (Powers)powerType;
    }

    /**
     * Returns the [Unit]'s power amount for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 powerAmount
     */
    int GetPower(Eluna* E, lua_State* L, Unit* unit)
    {
        int type = Eluna::CHECKVAL<int>(L, 2, -1);
        Powers power = PowerSelectorHelper(E, L, unit, type);

        Eluna::Push(L, unit->GetPower(power));
        return 1;
    }

    /**
     * Returns the [Unit]'s max power amount for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 maxPowerAmount
     */
    int GetMaxPower(Eluna* E, lua_State* L, Unit* unit)
    {
        int type = Eluna::CHECKVAL<int>(L, 2, -1);
        Powers power = PowerSelectorHelper(E, L, unit, type);

        Eluna::Push(L, unit->GetMaxPower(power));
        return 1;
    }

    /**
     * Returns the [Unit]'s power percent for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return float powerPct
     */
    int GetPowerPct(Eluna* E, lua_State* L, Unit* unit)
    {
        int type = Eluna::CHECKVAL<int>(L, 2, -1);
        Powers power = PowerSelectorHelper(E, L, unit, type);

#if (!defined(TRINITY) && defined(WOTLK))
        float percent = ((float)unit->GetPower(power) / (float)unit->GetMaxPower(power)) * 100.0f;
#else
        float percent = ((float)unit->GetPower(power) / (float)unit->GetMaxPower(power)) * 100.0f;
#endif
        Eluna::Push(L, percent);
        return 1;
    }

    /**
     * Returns the [Unit]'s current power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @return [Powers] powerType
     */
    int GetPowerType(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifdef TRINITY
        Eluna::Push(L, unit->getPowerType());
#else
        Eluna::Push(L, unit->GetPowerType());
#endif
        return 1;
    }

    /**
     * Returns the [Unit]'s max health.
     *
     * @return uint32 maxHealth
     */
    int GetMaxHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetMaxHealth());
        return 1;
    }

    /**
     * Returns the [Unit]'s health percent.
     *
     * @return float healthPct
     */
    int GetHealthPct(Eluna* /*E*/, lua_State* L, Unit* unit) 
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetHealthPercent());
#else
        Eluna::Push(L, unit->GetHealthPct());
#endif
        return 1;
    }

    /**
     * Returns the [Unit]'s gender.
     *
     * @return uint8 gender : 0 for male, 1 for female and 2 for none
     */
    int GetGender(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->getGender());
        return 1;
    }

    /**
     * Returns the [Unit]'s race ID.
     *
     * @return [Races] race
     */
    int GetRace(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->getRace());
        return 1;
    }

    /**
     * Returns the [Unit]'s class ID.
     *
     * @return [Classes] class
     */
    int GetClass(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->getClass());
        return 1;
    }

    /**
     * Returns the [Unit]'s creature type ID like wolf or humanoid.
     *
     * @return uint32 creatureType
     */
    int GetCreatureType(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetCreatureType());
        return 1;
    }

    /**
     * Returns the [Unit]'s class' name in given or default locale or nil.
     *
     * <pre>
     * enum LocaleConstant
     * {
     *     LOCALE_enUS = 0,
     *     LOCALE_koKR = 1,
     *     LOCALE_frFR = 2,
     *     LOCALE_deDE = 3,
     *     LOCALE_zhCN = 4,
     *     LOCALE_zhTW = 5,
     *     LOCALE_esES = 6,
     *     LOCALE_esMX = 7,
     *     LOCALE_ruRU = 8
     * };
     * </pre>
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE
     * @return string className : class name or nil
     */
    int GetClassAsString(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint8 locale = Eluna::CHECKVAL<uint8>(L, 2, DEFAULT_LOCALE);
        if (locale >= TOTAL_LOCALES)
            return luaL_argerror(L, 2, "valid LocaleConstant expected");

        const ChrClassesEntry* entry = sChrClassesStore.LookupEntry(unit->getClass());
        if (!entry)
            return 1;

        Eluna::Push(L, entry->name[locale]);
        return 1;
    }

    /**
     * Returns the [Unit]'s race's name in given or default locale or nil.
     *
     * <pre>
     * enum LocaleConstant
     * {
     *     LOCALE_enUS = 0,
     *     LOCALE_koKR = 1,
     *     LOCALE_frFR = 2,
     *     LOCALE_deDE = 3,
     *     LOCALE_zhCN = 4,
     *     LOCALE_zhTW = 5,
     *     LOCALE_esES = 6,
     *     LOCALE_esMX = 7,
     *     LOCALE_ruRU = 8
     * };
     * </pre>
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the race name in
     * @return string raceName : race name or nil
     */
    int GetRaceAsString(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint8 locale = Eluna::CHECKVAL<uint8>(L, 2, DEFAULT_LOCALE);
        if (locale >= TOTAL_LOCALES)
            return luaL_argerror(L, 2, "valid LocaleConstant expected");

        const ChrRacesEntry* entry = sChrRacesStore.LookupEntry(unit->getRace());
        if (!entry)
            return 1;

        Eluna::Push(L, entry->name[locale]);
        return 1;
    }

    /**
     * Returns the [Unit]'s faction ID.
     *
     * @return uint32 faction
     */
    int GetFaction(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->getFaction());
        return 1;
    }

    /**
     * Returns the [Aura] of the given spell entry on the [Unit] or nil.
     *
     * @param uint32 spellID : entry of the aura spell
     * @return [Aura] aura : aura object or nil
     */
    int GetAura(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spellID = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef TRINITY
        Eluna::Push(L, unit->GetAura(spellID, EFFECT_INDEX_0));
#else
        Eluna::Push(L, unit->GetAura(spellID));
#endif
        return 1;
    }

    /**
     * Returns the [Unit]'s combat timer
     *
     * @return uint32 combatTimer
     */
    int GetCombatTime(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetCombatTimer());
        return 1;
    }

    /**
     * Returns a table containing friendly [Unit]'s within given range of the [Unit].
     *
     * @param float range = 533.333 : search radius
     * @return table friendyUnits : table filled with friendly units
     */
    int GetFriendlyUnitsInRange(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float range = Eluna::CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);

        std::list<Unit*> list;
#ifndef TRINITY
        MaNGOS::AnyFriendlyUnitInObjectRangeCheck checker(unit, range);
        MaNGOS::UnitListSearcher<MaNGOS::AnyFriendlyUnitInObjectRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(unit, searcher, range);
#else
        Trinity::AnyFriendlyUnitInObjectRangeCheck checker(unit, unit, range);
        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
        unit->VisitNearbyObject(range, searcher);
#endif
        ElunaUtil::ObjectGUIDCheck guidCheck(unit->GET_GUID());
        list.remove_if(guidCheck);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Unit*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            Eluna::Push(L, ++i);
            Eluna::Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    /**
     * Returns a table containing unfriendly [Unit]'s within given range of the [Unit].
     *
     * @param float range = 533.333 : search radius
     * @return table unfriendyUnits : table filled with unfriendly units
     */
    int GetUnfriendlyUnitsInRange(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float range = Eluna::CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);

        std::list<Unit*> list;
#ifndef TRINITY
        MaNGOS::AnyUnfriendlyUnitInObjectRangeCheck checker(unit, range);
        MaNGOS::UnitListSearcher<MaNGOS::AnyUnfriendlyUnitInObjectRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(unit, searcher, range);
#else
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck checker(unit, unit, range);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
        unit->VisitNearbyObject(range, searcher);
#endif
        ElunaUtil::ObjectGUIDCheck guidCheck(unit->GET_GUID());
        list.remove_if(guidCheck);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Unit*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            Eluna::Push(L, ++i);
            Eluna::Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Returns [Unit]'s [Vehicle] methods
     *
     * @return [Vehicle] vehicle
     */
    int GetVehicleKit(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetVehicleInfo());
#else
        Eluna::Push(L, unit->GetVehicleKit());
#endif
        return 1;
    }

    /*
    int GetVehicle(Eluna* E, lua_State* L, Unit* unit)
    {
    Eluna::Push(L, unit->GetVehicle());
    return 1;
    }
    */

    /**
     * Returns the Critter Guid
     *
     * @return uint64 critterGuid
     */
    int GetCritterGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
#ifndef TRINITY
        Eluna::Push(L, unit->GetCritterGuid());
#else
        Eluna::Push(L, unit->GetCritterGUID());
#endif
        return 1;
    }
#endif

    /**
     * Returns the [Unit]'s speed of given [UnitMoveType].
     *
     * <pre>
     * enum UnitMoveType
     * {
     *     MOVE_WALK           = 0,
     *     MOVE_RUN            = 1,
     *     MOVE_RUN_BACK       = 2,
     *     MOVE_SWIM           = 3,
     *     MOVE_SWIM_BACK      = 4,
     *     MOVE_TURN_RATE      = 5,
     *     MOVE_FLIGHT         = 6,
     *     MOVE_FLIGHT_BACK    = 7,
     *     MOVE_PITCH_RATE     = 8
     * };
     * </pre>
     *
     * @param [UnitMoveType] type
     * @return float speed
     */
    int GetSpeed(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        if (type >= MAX_MOVE_TYPE)
            return luaL_argerror(L, 2, "valid UnitMoveType expected");

#ifndef TRINITY
        Eluna::Push(L, unit->GetSpeedRate((UnitMoveType)type));
#else
        Eluna::Push(L, unit->GetSpeed((UnitMoveType)type));
#endif
        return 1;
    }

    /**
     * Returns the current movement type for this [Unit].
     *
     * <pre>
     * enum MovementGeneratorType
     * {
     *     IDLE_MOTION_TYPE                = 0,
     *     RANDOM_MOTION_TYPE              = 1,
     *     WAYPOINT_MOTION_TYPE            = 2,
     *     MAX_DB_MOTION_TYPE              = 3,
     *     ANIMAL_RANDOM_MOTION_TYPE       = 3, // TC
     * 
     *     CONFUSED_MOTION_TYPE            = 4,
     *     CHASE_MOTION_TYPE               = 5,
     *     HOME_MOTION_TYPE                = 6,
     *     FLIGHT_MOTION_TYPE              = 7,
     *     POINT_MOTION_TYPE               = 8,
     *     FLEEING_MOTION_TYPE             = 9,
     *     DISTRACT_MOTION_TYPE            = 10,
     *     ASSISTANCE_MOTION_TYPE          = 11,
     *     ASSISTANCE_DISTRACT_MOTION_TYPE = 12,          
     *     TIMED_FLEEING_MOTION_TYPE       = 13,
     *     FOLLOW_MOTION_TYPE              = 14,
     *     EFFECT_MOTION_TYPE              = 15, // mangos
     *     ROTATE_MOTION_TYPE              = 15, // TC
     *     EFFECT_MOTION_TYPE              = 16, // TC
     *     NULL_MOTION_TYPE                = 17, // TC
     * };
     * </pre>
     *
     * @return [MovementGeneratorType] movementType
     */
    int GetMovementType(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->GetMotionMaster()->GetCurrentMovementGeneratorType());
        return 1;
    }

    /**
     * Sets the [Unit]'s owner GUID to given GUID.
     *
     * @param uint64 guid : new owner guid
     */
    int SetOwnerGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);

#ifndef TRINITY
        unit->SetOwnerGuid(ObjectGuid(guid));
#else
        unit->SetOwnerGUID(ObjectGuid(guid));
#endif
        return 0;
    }

    /**
     * Sets the [Unit]'s PvP on or off.
     *
     * @param bool apply = true : true if set on, false if off
     */
    int SetPvP(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

        unit->SetPvP(apply);
        return 0;
    }

    /**
     * Sets the [Unit]'s sheath state.
     *
     *     enum SheathState
     *     {
     *         SHEATH_STATE_UNARMED  = 0, // non prepared weapon
     *         SHEATH_STATE_MELEE    = 1, // prepared melee weapon
     *         SHEATH_STATE_RANGED   = 2  // prepared ranged weapon
     *     };
     *
     * @param [SheathState] sheathState : valid SheathState
     */
    int SetSheath(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 sheathed = Eluna::CHECKVAL<uint32>(L, 2);
        if (sheathed >= MAX_SHEATH_STATE)
            return luaL_argerror(L, 2, "valid SheathState expected");

        unit->SetSheath((SheathState)sheathed);
        return 0;
    }

    /**
     * Sets the [Unit]'s name internally.
     *
     * @param string name : new name
     */
    int SetName(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        const char* name = Eluna::CHECKVAL<const char*>(L, 2);
        if (std::string(name).length() > 0)
            unit->SetName(name);
        return 0;
    }

    /**
     * Sets the [Unit]'s speed of given [UnitMoveType] to given rate.
     * If forced, packets sent to clients forcing the visual change.
     *
     * <pre>
     * enum UnitMoveType
     * {
     *     MOVE_WALK           = 0,
     *     MOVE_RUN            = 1,
     *     MOVE_RUN_BACK       = 2,
     *     MOVE_SWIM           = 3,
     *     MOVE_SWIM_BACK      = 4,
     *     MOVE_TURN_RATE      = 5,
     *     MOVE_FLIGHT         = 6,
     *     MOVE_FLIGHT_BACK    = 7,
     *     MOVE_PITCH_RATE     = 8
     * };
     * </pre>
     *
     * @param [UnitMoveType] type
     * @param float rate
     * @param bool forced = false
     */
    int SetSpeed(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        float rate = Eluna::CHECKVAL<float>(L, 3);
        bool forced = Eluna::CHECKVAL<bool>(L, 4, false);
        if (type >= MAX_MOVE_TYPE)
            return luaL_argerror(L, 2, "valid UnitMoveType expected");
#ifndef TRINITY
        unit->SetSpeedRate((UnitMoveType)type, rate, forced);
#else
        unit->SetSpeedRate((UnitMoveType)type, rate);
#endif
        return 0;
    }

    /**
     * Sets the [Unit]'s faction.
     *
     * @param uint32 faction : new faction ID
     */
    int SetFaction(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 factionId = Eluna::CHECKVAL<uint32>(L, 2);
        unit->setFaction(factionId);
        return 0;
    }

    /**
     * Sets the [Unit]'s level.
     *
     * @param uint8 level : new level
     */
    int SetLevel(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint8 newlevel = Eluna::CHECKVAL<uint8>(L, 2);

        if (newlevel < 1)
            return 0;

        if (newlevel > STRONG_MAX_LEVEL)
            newlevel = STRONG_MAX_LEVEL;

        if (Player* player = unit->ToPlayer())
        {
            player->GiveLevel(newlevel);
            player->InitTalentForLevel();
            player->SetUInt32Value(PLAYER_XP, 0);
        }
        else
            unit->SetLevel(newlevel);

        return 0;
    }

    /**
     * Sets the [Unit]'s health.
     *
     * @param uint32 health : new health
     */
    int SetHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 2);
        unit->SetHealth(amt);
        return 0;
    }

    /**
     * Sets the [Unit]'s max health.
     *
     * @param uint32 maxHealth : new max health
     */
    int SetMaxHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 2);
        unit->SetMaxHealth(amt);
        return 0;
    }

    /**
     * Sets the [Unit]'s power amount for the given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @param uint32 power : new power amount
     */
    int SetPower(Eluna* E, lua_State* L, Unit* unit)
    {
        int type = Eluna::CHECKVAL<int>(L, 2, -1);
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 3);
        Powers power = PowerSelectorHelper(E, L, unit, type);

        unit->SetPower(power, amt);
        return 0;
    }

    /**
     * Sets the [Unit]'s max power amount for the given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @param uint32 maxPower : new max power amount
     */
    int SetMaxPower(Eluna* E, lua_State* L, Unit* unit)
    {
        int type = Eluna::CHECKVAL<int>(L, 2, -1);
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 3);
        Powers power = PowerSelectorHelper(E, L, unit, type);

        unit->SetMaxPower(power, amt);
        return 0;
    }

    /**
     * Sets the [Unit]'s power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *     };
     *
     * @param [Powers] type : a valid power type
     */
    int SetPowerType(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        if (type >= int(MAX_POWERS))
            return luaL_argerror(L, 2, "valid Powers expected");

#ifdef TRINITY
        unit->setPowerType((Powers)type);
#else
        unit->SetPowerType((Powers)type);
#endif
        return 0;
    }

    /**
     * Sets the [Unit]'s modelID.
     *
     * @param uint32 displayId
     */
    int SetDisplayId(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 model = Eluna::CHECKVAL<uint32>(L, 2);
        unit->SetDisplayId(model);
        return 0;
    }

    /**
     * Sets the [Unit]'s native/default modelID.
     *
     * @param uint32 displayId
     */
    int SetNativeDisplayId(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 model = Eluna::CHECKVAL<uint32>(L, 2);
        unit->SetNativeDisplayId(model);
        return 0;
    }

    /**
     * Sets the [Unit]'s facing/orientation.
     *
     * @param uint32 orientation
     */
    int SetFacing(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float o = Eluna::CHECKVAL<float>(L, 2);
        unit->SetFacingTo(o);
        return 0;
    }

    /**
     * Sets the [Unit] to face the given [WorldObject]'s direction.
     *
     * @param [WorldObject] target
     */
    int SetFacingToObject(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);
        unit->SetFacingToObject(obj);
        return 0;
    }

    /**
     * Sets creator GUID
     *
     * @param uint64 guid
     */
    int SetCreatorGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
#ifndef TRINITY
        unit->SetCreatorGuid(ObjectGuid(guid));
#else
        unit->SetCreatorGUID(ObjectGuid(guid));
#endif
        return 0;
    }

    /**
     * Sets charmer GUID
     *
     * @param uint64 guid
     */
    int SetCharmerGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
#ifndef TRINITY
        unit->SetCharmerGuid(ObjectGuid(guid));
#else
        unit->SetCharmerGUID(ObjectGuid(guid));
#endif
        return 0;
    }

    /**
     * Sets pet GUID
     *
     * @param uint64 guid
     */
    int SetPetGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
#ifndef TRINITY
        unit->SetPetGuid(ObjectGuid(guid));
#else
        unit->SetPetGUID(ObjectGuid(guid));
#endif
        return 0;
    }

    /**
     * Toggles (Sets) [Unit]'s water walking
     *
     * @param bool enable = true
     */
    int SetWaterWalk(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool enable = Eluna::CHECKVAL<bool>(L, 2, true);
#ifndef TRINITY
        unit->SetWaterWalk(enable);
#else
        unit->SetWaterWalking(enable);
#endif
        return 0;
    }

    /**
     * Sets the [Unit]'s stand state
     *
     * @param uint8 state : stand state
     */
    int SetStandState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint8 state = Eluna::CHECKVAL<uint8>(L, 2);
        unit->SetStandState(state);
        return 0;
    }

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Sets the [Unit]'s FFA flag on or off.
     *
     * @param bool apply = true
     */
    int SetFFA(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

#ifndef TRINITY
        unit->SetFFAPvP(apply);
#else
        if (apply)
        {
            unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
            for (Unit::ControlList::iterator itr = unit->m_Controlled.begin(); itr != unit->m_Controlled.end(); ++itr)
                (*itr)->SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        }
        else
        {
            unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
            for (Unit::ControlList::iterator itr = unit->m_Controlled.begin(); itr != unit->m_Controlled.end(); ++itr)
                (*itr)->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        }
#endif
        return 0;
    }

    /**
     * Sets the [Unit]'s sanctuary flag on or off.
     *
     * @param bool apply = true
     */
    int SetSanctuary(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

        if (apply)
        {
            unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
            unit->CombatStop();
            unit->CombatStopWithPets();
        }
        else
            unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);

        return 0;
    }

    /**
     * Sets the [Unit]'s phase mask.
     *
     * @param uint32 phaseMask
     * @param bool update = true : update visibility to nearby objects
     */
    int SetPhaseMask(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 phaseMask = Eluna::CHECKVAL<uint32>(L, 2);
        bool update = Eluna::CHECKVAL<bool>(L, 3, true);
        unit->SetPhaseMask(phaseMask, update);
        return 0;
    }

    int SetCritterGUID(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
#ifndef TRINITY
        unit->SetCritterGuid(ObjectGuid(guid));
#else
        unit->SetCritterGUID(ObjectGuid(guid));
#endif
        return 0;
    }
#endif

    /*int SetStunned(Eluna* E, lua_State* L, Unit* unit)
    {
    bool apply = Eluna::CHECKVAL<bool>(L, 2, true);
    unit->SetControlled(apply, UNIT_STATE_STUNNED);
    return 0;
    }*/

    /**
     * Roots the [Unit] to the ground, if 'false' specified, unroots the [Unit].
     *
     * @param bool apply = true
     */
    int SetRooted(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);
#ifndef TRINITY
        unit->SetRoot(apply);
#else
        unit->SetControlled(apply, UNIT_STATE_ROOT);
#endif
        return 0;
    }

    /**
     * Confuses the [Unit], if 'false' specified, the [Unit] is no longer confused.
     *
     * @param bool apply = true
     */
    int SetConfused(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);
#ifndef TRINITY
        unit->SetConfused(apply);
#else
        unit->SetControlled(apply, UNIT_STATE_CONFUSED);
#endif
        return 0;
    }

    /**
     * Fears the [Unit], if 'false' specified, the [Unit] is no longer feared.
     *
     * @param bool apply = true
     */
    int SetFeared(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);
#ifndef TRINITY
        unit->SetFeared(apply);
#else
        unit->SetControlled(apply, UNIT_STATE_FLEEING);
#endif
        return 0;
    }

    /*int SetCanFly(Eluna* E, lua_State* L, Unit* unit)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);
        unit->SetCanFly(apply);
        return 0;
    }*/

    /*int SetVisible(Eluna* E, lua_State* L, Unit* unit)
    {
        bool x = Eluna::CHECKVAL<bool>(L, 2, true);
        unit->SetVisible(x);
        return 0;
    }*/

    /**
     * Clears the [Unit]'s threat list.
     */
    int ClearThreatList(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
#ifdef MANGOS
        unit->GetThreatManager().clearReferences();
#else
        unit->getThreatManager().clearReferences();
#endif
        return 0;
    }
    
    /**
     * Mounts the [Unit] on the given displayID/modelID.
     *
     * @param uint32 displayId
     */
    int Mount(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 displayId = Eluna::CHECKVAL<uint32>(L, 2);

        unit->Mount(displayId);
        return 0;
    }
    
    /**
     * Dismounts the [Unit].
     */
    int Dismount(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        if (unit->IsMounted())
        {
#ifndef TRINITY
            unit->Unmount();
            unit->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
#else
            unit->Dismount();
            unit->RemoveAurasByType(SPELL_AURA_MOUNTED);
#endif
        }

        return 0;
    }
    
    /**
     * Makes the [Unit] perform the given emote.
     *
     * @param uint32 emoteId
     */
    int Emote(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        unit->HandleEmoteCommand(Eluna::CHECKVAL<uint32>(L, 2));
        return 0;
    }

    /**
     * Makes the [Unit] perform the given emote continuously.
     *
     * @param uint32 emoteId
     */
    int EmoteState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 emoteId = Eluna::CHECKVAL<uint32>(L, 2);

        unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, emoteId);
        return 0;
    }

    /**
     * Returns calculated percentage from Health
     *
     * @return int32 percentage
     */
    int CountPctFromCurHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->CountPctFromCurHealth(Eluna::CHECKVAL<int32>(L, 2)));
        return 1;
    }

    /**
     * Returns calculated percentage from Max Health
     *
     * @return int32 percentage
     */
    int CountPctFromMaxHealth(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Eluna::Push(L, unit->CountPctFromMaxHealth(Eluna::CHECKVAL<int32>(L, 2)));
        return 1;
    }

    /**
     * Sends chat message to [Player]
     *
     * @param uint8 type : chat, whisper, etc
     * @param uint32 lang : language to speak
     * @param string msg
     * @param [Player] target
     */
    int SendChatMessageToPlayer(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint8 type = Eluna::CHECKVAL<uint8>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
        std::string msg = Eluna::CHECKVAL<std::string>(L, 4);
        Player* target = Eluna::CHECKOBJ<Player>(L, 5);

        if (type >= MAX_CHAT_MSG_TYPE)
            return luaL_argerror(L, 2, "valid ChatMsg expected");
        if (lang >= LANGUAGES_COUNT)
            return luaL_argerror(L, 3, "valid Language expected");

        WorldPacket data;
#ifdef TRINITY
        ChatHandler::BuildChatPacket(data, ChatMsg(type), Language(lang), unit, target, msg);
#else
        ChatHandler::BuildChatPacket(data, ChatMsg(type), msg.c_str(), Language(lang), 0, unit->GET_GUID(), unit->GetName(), target->GET_GUID(), target->GetName());
#endif
        target->GetSession()->SendPacket(&data);
        return 0;
    }

    /*static void PrepareMove(Unit* unit)
    {
        unit->GetMotionMaster()->MovementExpired(); // Chase
        unit->StopMoving(); // Some
        unit->GetMotionMaster()->Clear(); // all
    }*/

    /**
     * Stops the [Unit]'s movement
     */
    int MoveStop(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->StopMoving();
        return 0;
    }

    /**
     * The [Unit]'s movement expires and clears movement
     *
     * @param bool reset = true : cleans movement
     */
    int MoveExpire(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool reset = Eluna::CHECKVAL<bool>(L, 2, true);
        unit->GetMotionMaster()->MovementExpired(reset);
        return 0;
    }

    /**
     * Clears the [Unit]'s movement
     *
     * @param bool reset = true : clean movement
     */
    int MoveClear(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        bool reset = Eluna::CHECKVAL<bool>(L, 2, true);
        unit->GetMotionMaster()->Clear(reset);
        return 0;
    }

    /**
     * The [Unit] will be idle
     */
    int MoveIdle(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->GetMotionMaster()->MoveIdle();
        return 0;
    }

    /**
     * The [Unit] will move at random
     *
     * @param float radius : limit on how far the [Unit] will move at random
     */
    int MoveRandom(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float radius = Eluna::CHECKVAL<float>(L, 2);
        float x, y, z;
        unit->GetPosition(x, y, z);
#ifndef TRINITY
        unit->GetMotionMaster()->MoveRandomAroundPoint(x, y, z, radius);
#else
        unit->GetMotionMaster()->MoveRandom(radius);
#endif
        return 0;
    }

    /**
     * The [Unit] will move to its set home location
     */
    int MoveHome(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->GetMotionMaster()->MoveTargetedHome();
        return 0;
    }

    /**
     * The [Unit] will follow the target
     *
     * @param [Unit] target : target to follow
     * @param float dist = 0 : distance to start following
     * @param float angle = 0
     */
    int MoveFollow(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        float dist = Eluna::CHECKVAL<float>(L, 3, 0.0f);
        float angle = Eluna::CHECKVAL<float>(L, 4, 0.0f);
        unit->GetMotionMaster()->MoveFollow(target, dist, angle);
        return 0;
    }

    /**
     * The [Unit] will chase the target
     *
     * @param [Unit] target : target to chase
     * @param float dist = 0 : distance start chasing
     * @param float angle = 0
     */
    int MoveChase(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        float dist = Eluna::CHECKVAL<float>(L, 3, 0.0f);
        float angle = Eluna::CHECKVAL<float>(L, 4, 0.0f);
        unit->GetMotionMaster()->MoveChase(target, dist, angle);
        return 0;
    }

    /**
     * The [Unit] will move confused
     */
    int MoveConfused(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->GetMotionMaster()->MoveConfused();
        return 0;
    }

    /**
     * The [Unit] will flee
     *
     * @param [Unit] target
     * @param uint32 time = 0 : flee delay
     */
    int MoveFleeing(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        uint32 time = Eluna::CHECKVAL<uint32>(L, 3, 0);
        unit->GetMotionMaster()->MoveFleeing(target, time);
        return 0;
    }

    /**
     * The [Unit] will move to the coordinates
     *
     * @param uint32 id : unique waypoint Id
     * @param float x
     * @param float y
     * @param float z
     * @param bool genPath = true : if true, generates path
     */
    int MoveTo(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        float x = Eluna::CHECKVAL<float>(L, 3);
        float y = Eluna::CHECKVAL<float>(L, 4);
        float z = Eluna::CHECKVAL<float>(L, 5);
        bool genPath = Eluna::CHECKVAL<bool>(L, 6, true);
        unit->GetMotionMaster()->MovePoint(id, x, y, z, genPath);
        return 0;
    }

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Makes the [Unit] jump to the coordinates
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float zSpeed : start velocity
     * @param float maxHeight : maximum height
     * @param uint32 id = 0 : unique movement Id
     */
    int MoveJump(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        float z = Eluna::CHECKVAL<float>(L, 4);
        float zSpeed = Eluna::CHECKVAL<float>(L, 5);
        float maxHeight = Eluna::CHECKVAL<float>(L, 6);
        uint32 id = Eluna::CHECKVAL<uint32>(L, 7, 0);

        Position pos(x, y, z);
        unit->GetMotionMaster()->MoveJump(pos, zSpeed, maxHeight, id);
        return 0;
    }
#endif

    /**
     * The [Unit] will whisper the message to a [Player]
     *
     * @param string msg : message for the [Unit] to emote
     * @param uint32 lang : language for the [Unit] to speak
     * @param [Player] receiver : specific [Unit] to receive the message
     * @param bool bossWhisper = false : is a boss whisper
     */
    int SendUnitWhisper(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        const char* msg = Eluna::CHECKVAL<const char*>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
        Player* receiver = Eluna::CHECKOBJ<Player>(L, 4);
        bool bossWhisper = Eluna::CHECKVAL<bool>(L, 5, false);
        if (std::string(msg).length() > 0)
#ifdef TRINITY
            unit->Whisper(msg, (Language)lang, receiver, bossWhisper);
#else
            unit->MonsterWhisper(msg, receiver, bossWhisper);
#endif
        return 0;
    }

    /**
     * The [Unit] will emote the message
     *
     * @param string msg : message for the [Unit] to emote
     * @param [Unit] receiver = nil : specific [Unit] to receive the message
     * @param bool bossEmote = false : is a boss emote
     */
    int SendUnitEmote(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        const char* msg = Eluna::CHECKVAL<const char*>(L, 2);
        Unit* receiver = Eluna::CHECKOBJ<Unit>(L, 3, false);
        bool bossEmote = Eluna::CHECKVAL<bool>(L, 4, false);
        if (std::string(msg).length() > 0)
#ifdef TRINITY
            unit->TextEmote(msg, receiver, bossEmote);
#else
            unit->MonsterTextEmote(msg, receiver, bossEmote);
#endif
        return 0;
    }

    /**
     * The [Unit] will say the message
     *
     * @param string msg : message for the [Unit] to say
     * @param uint32 language : language for the [Unit] to speak
     */
    int SendUnitSay(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        const char* msg = Eluna::CHECKVAL<const char*>(L, 2);
        uint32 language = Eluna::CHECKVAL<uint32>(L, 3);
        if (std::string(msg).length() > 0)
#ifdef TRINITY
            unit->Say(msg, (Language)language, unit);
#else
            unit->MonsterSay(msg, language, unit);
#endif
        return 0;
    }

    /**
     * The [Unit] will yell the message
     *
     * @param string msg : message for the [Unit] to yell
     * @param uint32 language : language for the [Unit] to speak
     */
    int SendUnitYell(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        const char* msg = Eluna::CHECKVAL<const char*>(L, 2);
        uint32 language = Eluna::CHECKVAL<uint32>(L, 3);
        if (std::string(msg).length() > 0)
#ifdef TRINITY
            unit->Yell(msg, (Language)language, unit);
#else
            unit->MonsterYell(msg, language, unit);
#endif
        return 0;
    }

    /**
     * Unmorphs the [Unit] setting it's display ID back to the native display ID.
     */
    int DeMorph(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->DeMorph();
        return 0;
    }

    /**
     * Makes the [Unit] cast the spell on the target.
     *
     * @param [Unit] target = nil : can be self or another unit
     * @param uint32 spell : entry of a spell
     * @param bool triggered = false : if true the spell is instant and has no cost
     */
    int CastSpell(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2, NULL);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 3);
        bool triggered = Eluna::CHECKVAL<bool>(L, 4, false);
        SpellEntry const* spellEntry = sSpellStore.LookupEntry(spell);
        if (!spellEntry)
            return 0;

        unit->CastSpell(target, spell, triggered);
        return 0;
    }

    /**
     * Casts the [Spell] at target [Unit] with custom basepoints or casters.
     * See also [Unit:CastSpell].
     *
     * @param [Unit] target = nil
     * @param uint32 spell
     * @param bool triggered = false
     * @param int32 bp0 = nil : custom basepoints for [Spell] effect 1. If nil, no change is made
     * @param int32 bp1 = nil : custom basepoints for [Spell] effect 2. If nil, no change is made
     * @param int32 bp2 = nil : custom basepoints for [Spell] effect 3. If nil, no change is made
     * @param [Item] castItem = nil
     * @param uint64 originalCaster = 0
     */
    int CastCustomSpell(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2, NULL);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 3);
        bool triggered = Eluna::CHECKVAL<bool>(L, 4, false);
        bool has_bp0 = !lua_isnoneornil(L, 5);
        int32 bp0 = Eluna::CHECKVAL<int32>(L, 5, 0);
        bool has_bp1 = !lua_isnoneornil(L, 6);
        int32 bp1 = Eluna::CHECKVAL<int32>(L, 6, 0);
        bool has_bp2 = !lua_isnoneornil(L, 7);
        int32 bp2 = Eluna::CHECKVAL<int32>(L, 7, 0);
        Item* castItem = Eluna::CHECKOBJ<Item>(L, 8, false);
        uint64 originalCaster = Eluna::CHECKVAL<uint64>(L, 9, 0);

        unit->CastCustomSpell(target, spell, has_bp0 ? &bp0 : NULL, has_bp1 ? &bp1 : NULL, has_bp2 ? &bp2 : NULL, triggered, castItem, NULL, ObjectGuid(originalCaster));
        return 0;
    }
    
    /**
     * Makes the [Unit] cast the spell to the given coordinates, used for area effect spells.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param uint32 spell : entry of a spell
     * @param bool triggered = false : if true the spell is instant and has no cost
     */
    int CastSpellAoF(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float _x = Eluna::CHECKVAL<float>(L, 2);
        float _y = Eluna::CHECKVAL<float>(L, 3);
        float _z = Eluna::CHECKVAL<float>(L, 4);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 5);
        bool triggered = Eluna::CHECKVAL<bool>(L, 6, true);
        unit->CastSpell(_x, _y, _z, spell, triggered);
        return 0;
    }

    /**
     * Clears the [Unit]'s combat
     */
    int ClearInCombat(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->ClearInCombat();
        return 0;
    }

    /**
     * Stops the [Unit]'s current spell cast
     *
     * @param uint32 spell = 0 : entry of a spell
     */
    int StopSpellCast(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2, 0);
        unit->CastStop(spellId);
        return 0;
    }

    /**
     * Interrupts [Unit]'s spell state, casting, etc.
     *
     * if spell is not interruptible, it will return
     *
     * @param int32 spellType : type of spell to interrupt
     * @param bool delayed = true : skips if the spell is delayed
     */
    int InterruptSpell(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        int spellType = Eluna::CHECKVAL<int>(L, 2);
        bool delayed = Eluna::CHECKVAL<bool>(L, 3, true);
        switch (spellType)
        {
            case 0:
                spellType = CURRENT_MELEE_SPELL;
                break;
            case 1:
                spellType = CURRENT_GENERIC_SPELL;
                break;
            case 2:
                spellType = CURRENT_CHANNELED_SPELL;
                break;
            case 3:
                spellType = CURRENT_AUTOREPEAT_SPELL;
                break;
            default:
                return luaL_argerror(L, 2, "valid CurrentSpellTypes expected");
        }

        unit->InterruptSpell((CurrentSpellTypes)spellType, delayed);
        return 0;
    }
    
    /**
     * Adds the [Aura] of the given spell entry on the given target from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     * @param [Unit] target : aura will be applied on the target
     * @return [Aura] aura
     */
    int AddAura(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 3);
        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
        if (!spellInfo)
            return 1;

#ifndef TRINITY
        if (!IsSpellAppliesAura(spellInfo) && !IsSpellHaveEffect(spellInfo, SPELL_EFFECT_PERSISTENT_AREA_AURA))
            return 1;

        SpellAuraHolder* holder = CreateSpellAuraHolder(spellInfo, target, unit);

        for (uint32 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            uint8 eff = spellInfo->Effect[i];
            if (eff >= TOTAL_SPELL_EFFECTS)
                continue;
            if (IsAreaAuraEffect(eff) ||
                eff == SPELL_EFFECT_APPLY_AURA ||
                eff == SPELL_EFFECT_PERSISTENT_AREA_AURA)
            {
                Aura* aur = CreateAura(spellInfo, SpellEffIndex(i), NULL, holder, target);
                holder->AddAura(aur, SpellEffIndex(i));
            }
        }
        Eluna::Push(L, target->AddSpellAuraHolder(holder));
#else
        Eluna::Push(L, unit->AddAura(spellId, target));
#endif
        return 1;
    }
    
    /**
     * Removes [Aura] of the given spell entry from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     */
    int RemoveAura(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
        unit->RemoveAurasDueToSpell(spellId);
        return 0;
    }
    
    /**
     * Removes all [Aura]'s from the [Unit].
     *
     *     Note: talents and racials are also auras, use with caution
     */
    int RemoveAllAuras(Eluna* /*E*/, lua_State* /*L*/, Unit* unit)
    {
        unit->RemoveAllAuras();
        return 0;
    }
    
    /**
     * Adds the given unit state for the [Unit].
     *
     * @param [UnitState] state
     */
    int AddUnitState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2);

#ifndef TRINITY
        unit->addUnitState(state);
#else
        unit->AddUnitState(state);
#endif
        return 0;
    }
    
    /**
     * Removes the given unit state from the [Unit].
     *
     * @param [UnitState] state
     */
    int ClearUnitState(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2);

#ifndef TRINITY
        unit->clearUnitState(state);
#else
        unit->ClearUnitState(state);
#endif
        return 0;
    }
    
    /**
     * Makes the [Unit] teleport to given coordinates within same map.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float o : orientation
     */
    int NearTeleport(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        float z = Eluna::CHECKVAL<float>(L, 4);
        float o = Eluna::CHECKVAL<float>(L, 5);

        unit->NearTeleportTo(x, y, z, o);
        return 0;
    }

    /**
     * Makes the [Unit] damage the target [Unit]
     *
     * <pre>
     * enum SpellSchools
     * {
     *     SPELL_SCHOOL_NORMAL  = 0,
     *     SPELL_SCHOOL_HOLY    = 1,
     *     SPELL_SCHOOL_FIRE    = 2,
     *     SPELL_SCHOOL_NATURE  = 3,
     *     SPELL_SCHOOL_FROST   = 4,
     *     SPELL_SCHOOL_SHADOW  = 5,
     *     SPELL_SCHOOL_ARCANE  = 6,
     *     MAX_SPELL_SCHOOL     = 7
     * };
     * </pre>
     *
     * @param [Unit] target : [Unit] to damage
     * @param uint32 damage : amount to damage
     * @param bool durabilityloss = true : if false, the damage does not do durability damage
     * @param [SpellSchools] school = MAX_SPELL_SCHOOL : school the damage is done in or MAX_SPELL_SCHOOL for direct damage
     * @param uint32 spell = 0 : spell that inflicts the damage
     */
    int DealDamage(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        uint32 damage = Eluna::CHECKVAL<uint32>(L, 3);
        bool durabilityloss = Eluna::CHECKVAL<bool>(L, 4, true);
        uint32 school = Eluna::CHECKVAL<uint32>(L, 5, MAX_SPELL_SCHOOL);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 6, 0);
        if (school > MAX_SPELL_SCHOOL)
            return luaL_argerror(L, 6, "valid SpellSchool expected");

        // flat melee damage without resistence/etc reduction
        if (school == MAX_SPELL_SCHOOL)
        {
            unit->DealDamage(target, damage, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, durabilityloss);
#ifdef TRINITY
            unit->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, target, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_HIT, 0);
#else
            unit->SendAttackStateUpdate(HITINFO_NORMALSWING2, target, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_NORMAL, 0);
#endif
            return 0;
        }

        SpellSchoolMask schoolmask = SpellSchoolMask(1 << school);

#ifdef TRINITY
        if (Unit::IsDamageReducedByArmor(schoolmask))
            damage = unit->CalcArmorReducedDamage(target, damage, NULL, BASE_ATTACK);
#else
        if (schoolmask & SPELL_SCHOOL_MASK_NORMAL)
            damage = unit->CalcArmorReducedDamage(target, damage);
#endif

        // melee damage by specific school
        if (!spell)
        {
            uint32 absorb = 0;
            uint32 resist = 0;
#ifdef TRINITY
            unit->CalcAbsorbResist(target, schoolmask, SPELL_DIRECT_DAMAGE, damage, &absorb, &resist);
#else
            target->CalculateDamageAbsorbAndResist(unit, schoolmask, SPELL_DIRECT_DAMAGE, damage, &absorb, &resist);
#endif

            if (damage <= absorb + resist)
                damage = 0;
            else
                damage -= absorb + resist;

            unit->DealDamageMods(target, damage, &absorb);
            unit->DealDamage(target, damage, NULL, DIRECT_DAMAGE, schoolmask, NULL, false);
#ifdef TRINITY
            unit->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, target, 1, schoolmask, damage, absorb, resist, VICTIMSTATE_HIT, 0);
#else
            unit->SendAttackStateUpdate(HITINFO_NORMALSWING2, target, schoolmask, damage, absorb, resist, VICTIMSTATE_NORMAL, 0);
#endif
            return 0;
        }

        // non-melee damage
        unit->SpellNonMeleeDamageLog(target, spell, damage);
        return 0;
    }

    /**
     * Makes the [Unit] heal the target [Unit] with given spell
     *
     * @param [Unit] target : [Unit] to heal
     * @param uint32 spell : spell that causes the healing
     * @param uint32 amount : amount to heal
     * @param bool critical = false : if true, heal is logged as critical
     */
    int DealHeal(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 3);
        uint32 amount = Eluna::CHECKVAL<uint32>(L, 4);
        bool critical = Eluna::CHECKVAL<bool>(L, 5, false);

#ifndef TRINITY
        if (const SpellInfo* info = sSpellStore.LookupEntry(spell))
            unit->DealHeal(target, amount, info, critical);
#else
        if (const SpellInfo* info = sSpellMgr->GetSpellInfo(spell))
            unit->HealBySpell(target, info, amount, critical);
#endif
        return 0;
    }

    /**
     * Makes the [Unit] kill the target [Unit]
     *
     * @param [Unit] target : [Unit] to kill
     * @param bool durLoss = true : when true, the target's items suffer durability loss
     */
    int Kill(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        bool durLoss = Eluna::CHECKVAL<bool>(L, 3, true);

#ifndef TRINITY
        unit->DealDamage(target, target->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, durLoss);
#else
        unit->Kill(target, durLoss);
#endif
        return 0;
    }

    /**
     * Adds threat to the [Unit] from the victim.
     *
     * <pre>
     * enum SpellSchoolMask
     * {
     *     SPELL_SCHOOL_MASK_NONE    = 0,
     *     SPELL_SCHOOL_MASK_NORMAL  = 1,
     *     SPELL_SCHOOL_MASK_HOLY    = 2,
     *     SPELL_SCHOOL_MASK_FIRE    = 4,
     *     SPELL_SCHOOL_MASK_NATURE  = 8,
     *     SPELL_SCHOOL_MASK_FROST   = 16,
     *     SPELL_SCHOOL_MASK_SHADOW  = 32,
     *     SPELL_SCHOOL_MASK_ARCANE  = 64,
     * }
     * </pre>
     *
     * @param [Unit] victim : [Unit] that caused the threat
     * @param float threat : threat amount
     * @param [SpellSchoolMask] schoolMask = 0 : [SpellSchoolMask] of the threat causer
     * @param uint32 spell = 0 : spell entry used for threat
     */
    int AddThreat(Eluna* /*E*/, lua_State* L, Unit* unit)
    {
        Unit* victim = Eluna::CHECKOBJ<Unit>(L, 2);
        float threat = Eluna::CHECKVAL<float>(L, 3, true);
        uint32 schoolMask = Eluna::CHECKVAL<uint32>(L, 4, 0);
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 5, 0);

        if (schoolMask > SPELL_SCHOOL_MASK_ALL)
        {
            return luaL_argerror(L, 4, "valid SpellSchoolMask expected");
        }

#ifdef TRINITY
        unit->AddThreat(victim, threat, (SpellSchoolMask)schoolMask, spell ? sSpellMgr->GetSpellInfo(spell) : NULL);
#else
        unit->AddThreat(victim, threat, false, (SpellSchoolMask)schoolMask, spell ? sSpellStore.LookupEntry(spell) : NULL);
#endif
        return 0;
    }

    /*int RestoreDisplayId(Eluna* E, lua_State* L, Unit* unit)
    {
        unit->RestoreDisplayId();
        return 0;
    }*/

    /*int RestoreFaction(Eluna* E, lua_State* L, Unit* unit)
    {
        unit->RestoreFaction();
        return 0;
    }*/

    /*int RemoveBindSightAuras(Eluna* E, lua_State* L, Unit* unit)
    {
        unit->RemoveBindSightAuras();
        return 0;
    }*/

    /*int RemoveCharmAuras(Eluna* E, lua_State* L, Unit* unit)
    {
        unit->RemoveCharmAuras();
        return 0;
    }*/

    /*int DisableMelee(Eluna* E, lua_State* L, Unit* unit)
    {
    bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

    if (apply)
    unit->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
    else
    unit->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
    return 0;
    }*/

    /*int SummonGuardian(Eluna* E, lua_State* L, Unit* unit)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
    float x = Eluna::CHECKVAL<float>(L, 3);
    float y = Eluna::CHECKVAL<float>(L, 4);
    float z = Eluna::CHECKVAL<float>(L, 5);
    float o = Eluna::CHECKVAL<float>(L, 6);
    uint32 desp = Eluna::CHECKVAL<uint32>(L, 7, 0);

    SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(61);
    if (!properties)
    return 1;
    Position pos;
    pos.Relocate(x,y,z,o);
    TempSummon* summon = unit->GetMap()->SummonCreature(entry, pos, properties, desp, unit);

    if (!summon)
    return 1;

    if (summon->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
    ((Guardian*)summon)->InitStatsForLevel(unit->getLevel());

    if (properties && properties->Category == SUMMON_CATEGORY_ALLY)
    summon->setFaction(unit->getFaction());
    if (summon->GetEntry() == 27893)
    {
    if (uint32 weapon = unit->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID))
    {
    summon->SetDisplayId(11686);
    summon->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, weapon);
    }
    else
    summon->SetDisplayId(1126);
    }
    summon->AI()->EnterEvadeMode();

    Eluna::Push(L, summon);
    return 1;
    }*/
};
#endif
