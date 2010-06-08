/*
 * Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/*
 * Comment: Tower Event support is not finished, there is missing code on triggers and
 *          Lore Keeper and Brann Bronzebeard are not scripted yet. Lore Keeper's script
 *          should activate the hard mode so is not possible to play hard-mode yet. Add a call to
 *          Leviathan's DoAction(0) from Lore Keeper's script to activate hard-mode
 */

#include "ScriptPCH.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_PURSUED                               = 62374,
    SPELL_GATHERING_SPEED                       = 62375,
    SPELL_BATTERING_RAM                         = 62376,
    SPELL_FLAME_VENTS                           = 62396,
    SPELL_MISSILE_BARRAGE                       = 62400,
    SPELL_SYSTEMS_SHUTDOWN                      = 62475,

    SPELL_FLAME_CANNON                          = 62395,
//  SPELL_FLAME_CANNON                          = 64692, trigger the same spell

    SPELL_OVERLOAD_CIRCUIT                      = 62399,
    SPELL_SEARING_FLAME                         = 62402,
    SPELL_BLAZE                                 = 62292,
    SPELL_SMOKE_TRAIL                           = 63575,
    SPELL_ELECTROSHOCK                          = 62522,
    //TOWER BUFF SPELLS
    SPELL_THORIM_S_HAMMER                       = 62912, // Tower of Storms
    SPELL_MIMIRON_S_INFERNO                       = 62910, // Tower of Flames
    SPELL_HODIR_S_FURY                            = 62297, // Tower of Frost
    SPELL_FREYA_S_WARD                          = 62906  // Tower of Nature
};

enum Creatures
{
    MOB_MECHANOLIFT                             = 33214,
    MOB_LIQUID                                  = 33189,
    MOB_CONTAINER                               = 33218,
};

enum Events
{
    EVENT_NONE,
    EVENT_PURSUE,
    EVENT_MISSILE,
    EVENT_VENT,
    EVENT_SPEED,
    EVENT_SUMMON,
    EVENT_THORIM_S_HAMMER, // Tower of Storms
    EVENT_MIMIRON_S_INFERNO, // Tower of Flames
    EVENT_HODIR_S_FURY,      // Tower of Frost
    EVENT_FREYA_S_WARD     // Tower of Nature
};

enum Seats
{
    SEAT_PLAYER                                 = 0,
    SEAT_TURRET                                 = 1,
    SEAT_DEVICE                                 = 2,
};

enum Yells
{
    SAY_AGGRO                                   = -1603060,
    SAY_SLAY                                    = -1603061,
    SAY_DEATH                                   = -1603062,
    SAY_TARGET_1                                = -1603063,
    SAY_TARGET_2                                = -1603064,
    SAY_TARGET_3                                = -1603065,
    SAY_HARDMODE                                = -1603066,
    SAY_TOWER_NONE                              = -1603067,
    SAY_TOWER_FROST                             = -1603068,
    SAY_TOWER_FLAME                             = -1603069,
    SAY_TOWER_NATURE                            = -1603070,
    SAY_TOWER_STORM                             = -1603071,
    SAY_PLAYER_RIDING                           = -1603072,
    SAY_OVERLOAD_1                              = -1603073,
    SAY_OVERLOAD_2                              = -1603074,
    SAY_OVERLOAD_3                              = -1603075,
};

enum eAchievementData
{
    //ACHIEV_CHAMPION_OF_ULDUAR                   = 10042,
    //ACHIEV_CONQUEROR_OF_ULDUAR                  = 10352,
    ACHIEV_10_NUKED_FROM_ORBIT                  = 10058,
    ACHIEV_25_NUKED_FROM_ORBIT                  = 10060,
    ACHIEV_10_ORBITAL_BOMBARDMENT               = 10056,
    ACHIEV_25_ORBITAL_BOMBARDMENT               = 10061,
    ACHIEV_10_ORBITAL_DEVASTATION               = 10057,
    ACHIEV_25_ORBITAL_DEVASTATION               = 10059,
    ACHIEV_10_ORBIT_UARY                        = 10218,
    ACHIEV_25_ORBIT_UARY                        = 10219,
    ACHIEV_10_SHUTOUT                           = 10054,
    ACHIEV_25_SHUTOUT                           = 10055,
    ACHIEV_10_SIEGE_OF_ULDUAR                   = 9999,
    ACHIEV_25_SIEGE_OF_ULDUAR                   = 10003,
    //ACHIEV_10_THREE_CAR_GARAGE                  = 10046, 10047, 10048,
    //ACHIEV_25_THREE_CAR_GARAGE                  = 10049, 10050, 10051,
    ACHIEV_10_UNBROKEN                          = 10044,
    ACHIEV_25_UNBROKEN                          = 10045,
};

static Position Center[]=
{
    {354.8771, -12.90240, 409.803650},
};

struct boss_flame_leviathanAI : public BossAI
{
    boss_flame_leviathanAI(Creature* pCreature) : BossAI(pCreature, TYPE_LEVIATHAN), vehicle(pCreature->GetVehicleKit())
    {
        assert(vehicle);

        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    Vehicle* vehicle;
    uint8 uiActiveTowers;

    void Reset()
    {
        _Reset();
        assert(vehicle);
        uiActiveTowers = 0;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/)
    {
        _EnterCombat();
        DoScriptText(SAY_AGGRO, me);
        me->SetReactState(REACT_DEFENSIVE);
        events.ScheduleEvent(EVENT_PURSUE, 0);
        events.ScheduleEvent(EVENT_MISSILE, 1500);
        events.ScheduleEvent(EVENT_VENT, 20000);
        events.ScheduleEvent(EVENT_SPEED, 15000);
        events.ScheduleEvent(EVENT_SUMMON, 0);

        if (Creature *turret = CAST_CRE(vehicle->GetPassenger(SEAT_TURRET)))
            turret->AI()->DoZoneInCombat();
    }

    // TODO: effect 0 and effect 1 may be on different target
    void SpellHitTarget(Unit* pTarget, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_PURSUED)
            AttackStart(pTarget);
    }

    void JustDied(Unit* /*victim*/)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
        if (pInstance)
        {
            if (uiActiveTowers)
            {
                switch (uiActiveTowers)
                {
                case 4:
                    pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBIT_UARY, ACHIEV_25_ORBIT_UARY));
                    break;
                case 3:
                    pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_NUKED_FROM_ORBIT, ACHIEV_25_NUKED_FROM_ORBIT));
                    break;
                case 2:
                    pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_DEVASTATION, ACHIEV_25_ORBITAL_DEVASTATION));
                    break;
                case 1:
                    pInstance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_BOMBARDMENT, ACHIEV_25_ORBITAL_BOMBARDMENT));
                    break;
                }
            }
        }
    }

    void SpellHit(Unit* /*caster*/, const SpellEntry* pSpell)
    {
        if (pSpell->Id == 62472)
            vehicle->InstallAllAccessories();
        else if (pSpell->Id == SPELL_ELECTROSHOCK)
            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!me->isInCombat())
            return;

        if (me->getThreatManager().isThreatListEmpty())
        {
            EnterEvadeMode();
            return;
        }

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        uint32 eventId = events.GetEvent();
        if (!me->getVictim())
            eventId = EVENT_PURSUE;

        switch(eventId)
        {
            case 0: break; // this is a must
            case EVENT_PURSUE:
                DoCastAOE(SPELL_PURSUED, true);
                //events.RepeatEvent(35000); // this should not be used because eventId may be overriden
                events.RescheduleEvent(EVENT_PURSUE, 35000);
                if (!me->getVictim()) // all siege engines and demolishers are dead
                    UpdateVictim(); // begin to kill other things
                return;
            case EVENT_MISSILE:
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(pTarget, SPELL_MISSILE_BARRAGE);
                events.RepeatEvent(1500);
                return;
            case EVENT_VENT:
                DoCastAOE(SPELL_FLAME_VENTS);
                events.RepeatEvent(20000);
                return;
            case EVENT_SPEED:
                DoCastAOE(SPELL_GATHERING_SPEED);
                events.RepeatEvent(15000);
                return;
            case EVENT_SUMMON:
                if (summons.size() < 15) // 4seat+1turret+10lift
                    if (Creature* pLift = DoSummonFlyer(MOB_MECHANOLIFT, me, urand(20,40), 50, 0))
                        pLift->GetMotionMaster()->MoveRandom(100);
                events.RepeatEvent(2000);
                return;
            case EVENT_THORIM_S_HAMMER: // Tower of Storms
                DoCast(me, SPELL_THORIM_S_HAMMER);
                events.RepeatEvent(urand(60000, 120000));
                return;
            case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
                DoCast(me->getVictim(), SPELL_MIMIRON_S_INFERNO);
                events.RepeatEvent(urand(60000, 120000));
                return;
            case EVENT_HODIR_S_FURY:      // Tower of Frost
                DoCast(me->getVictim(), SPELL_HODIR_S_FURY);
                events.RepeatEvent(urand(60000, 120000));
                return;
            case EVENT_FREYA_S_WARD:    // Tower of Nature
                DoCast(me, SPELL_FREYA_S_WARD);
                events.RepeatEvent(urand(60000, 120000));
                return;
            default:
                events.PopEvent();
                break;
        }
        DoSpellAttackIfReady(SPELL_BATTERING_RAM);
    }

    void DoAction(const int32 uiAction)
    {
        // Start encounter
        if (uiAction == 10)
        {
            me->GetMotionMaster()->MovePoint(0, Center[0]);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            return;
        }
        /*
        Tower event triggers
            General TODO:
                Yells

            Actions:
                DoAction(0): Activate hard-mode. Buff up leviathan's AP & health, schedule all the tower spells.
                             Should be triggered on Lore Keeper's script
                DoAction(1-4): A tower have been destroyed, debuff leviathan's AP & health
                DoAction(1); Tower of Storms has been destroyed, deschedule spell Thorim's Hammer
                DoAction(2): Tower of Flames has been destroyed, deschedule spell Mimiron's Inferno
                DoAction(3): Tower of Frost has been destroyed, deschedule spell Hodir's Fury
                DoAction(4): Tower of Nature has been destroyed, deschedule spell Freya's Ward
        */

        if (uiAction) // Tower destruction, debuff leviathan AP & health
        {
            --uiActiveTowers;
        }

        switch (uiAction)
        {
        case 0:  // Activate hard-mode
            events.ScheduleEvent(EVENT_THORIM_S_HAMMER, urand(30000,60000));
            events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO, urand(30000,60000));
            events.ScheduleEvent(EVENT_HODIR_S_FURY, urand(30000,60000));
            events.ScheduleEvent(EVENT_FREYA_S_WARD, urand(30000,60000));
            uiActiveTowers=4;
            break;
        case 1:  // Tower of Storms destroyed
            events.CancelEvent(EVENT_THORIM_S_HAMMER);
            break;
        case 2: // Tower of Flames destroyed
            events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
            break;
        case 3: // Tower of Frost destroyed
            events.CancelEvent(EVENT_HODIR_S_FURY);
            break;
        case 4: // Tower of Nature destroyed
            events.CancelEvent(EVENT_FREYA_S_WARD);
            break;
        }
    }
};

//#define BOSS_DEBUG

struct boss_flame_leviathan_seatAI : public PassiveAI
{
    boss_flame_leviathan_seatAI(Creature *c) : PassiveAI(c), vehicle(c->GetVehicleKit())
    {
        assert(vehicle);
#ifdef BOSS_DEBUG
        me->SetReactState(REACT_AGGRESSIVE);
#endif
    }

    Vehicle* vehicle;

#ifdef BOSS_DEBUG
    void MoveInLineOfSight(Unit *who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER && CAST_PLR(who)->isGameMaster()
            && !who->GetVehicle() && vehicle->GetPassenger(SEAT_TURRET))
            who->EnterVehicle(vehicle, SEAT_PLAYER);
    }
#endif

    void PassengerBoarded(Unit* who, int8 seatId, bool apply)
    {
        if (!me->GetVehicle())
            return;

        if (seatId == SEAT_PLAYER)
        {
            if (!apply)
                return;

            if (Creature* turret = CAST_CRE(vehicle->GetPassenger(SEAT_TURRET)))
            {
                turret->setFaction(me->GetVehicleBase()->getFaction());
                turret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                turret->AI()->AttackStart(who);
            }
            if (Unit* device = vehicle->GetPassenger(SEAT_DEVICE))
            {
                device->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                device->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
        }
        else if (seatId == SEAT_TURRET)
        {
            if (apply)
                return;

            if (Unit* device = vehicle->GetPassenger(SEAT_DEVICE))
            {
                device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                device->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
            }
        }
    }
};

struct boss_flame_leviathan_defense_turretAI : public TurretAI
{
    boss_flame_leviathan_defense_turretAI(Creature *c) : TurretAI(c) {}

    void DamageTaken(Unit* who, uint32 &damage)
    {
        if (!CanAIAttack(who))
            damage = 0;
    }

    bool CanAIAttack(const Unit *who) const
    {
        if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != 33114)
            return false;
        return true;
    }
};

struct boss_flame_leviathan_overload_deviceAI : public PassiveAI
{
    boss_flame_leviathan_overload_deviceAI(Creature* pCreature) : PassiveAI(pCreature) {}

    void DoAction(const int32 param)
    {
        if (param == EVENT_SPELLCLICK)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            if (me->GetVehicle())
            {
                if (Unit* pPlayer = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                {
                    pPlayer->ExitVehicle();
                    me->GetVehicleBase()->CastSpell(pPlayer, SPELL_SMOKE_TRAIL, true);
                    if (Unit* leviathan = me->GetVehicleBase()->GetVehicleBase())
                        pPlayer->GetMotionMaster()->MoveKnockbackFrom(leviathan->GetPositionX(), leviathan->GetPositionY(), 30, 30);
                }
            }
        }
    }
};

struct boss_flame_leviathan_safety_containerAI : public PassiveAI
{
    boss_flame_leviathan_safety_containerAI(Creature *c) : PassiveAI(c) {}

    void MovementInform(uint32 /*type*/, uint32 id)
    {
        if (id == me->GetEntry())
        {
            if (Creature* pLiquid = DoSummon(MOB_LIQUID, me, 0))
                pLiquid->CastSpell(pLiquid, 62494, true);
            me->DisappearAndDie(); // this will relocate creature to sky
        }
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        if (!me->GetVehicle() && me->isSummon() && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
            me->GetMotionMaster()->MoveFall(409.8f, me->GetEntry());
    }
};

struct spell_pool_of_tarAI : public TriggerAI
{
    spell_pool_of_tarAI(Creature *c) : TriggerAI(c)
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void DamageTaken(Unit * /*who*/, uint32 &damage)
    {
        damage = 0;
    }

    void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
    {
        if (spell->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
            me->CastSpell(me, SPELL_BLAZE, true);
    }
};

struct npc_colossusAI : public ScriptedAI
{
    npc_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    Position pPos;

    void JustDied(Unit* /*Who*/)
    {
        if (me->GetHomePosition().IsInDist(Center,50.f))
        {
            if (pInstance)
                pInstance->SetData(TYPE_COLOSSUS,pInstance->GetData(TYPE_COLOSSUS)+1);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_boss_flame_leviathan(Creature* pCreature)
{
    return new boss_flame_leviathanAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_seat(Creature* pCreature)
{
    return new boss_flame_leviathan_seatAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_defense_turret(Creature* pCreature)
{
    return new boss_flame_leviathan_defense_turretAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_overload_device(Creature* pCreature)
{
    return new boss_flame_leviathan_overload_deviceAI (pCreature);
}

CreatureAI* GetAI_boss_flame_leviathan_safety_containerAI(Creature* pCreature)
{
    return new boss_flame_leviathan_safety_containerAI(pCreature);
}

CreatureAI* GetAI_spell_pool_of_tar(Creature* pCreature)
{
    return new spell_pool_of_tarAI (pCreature);
}

CreatureAI* GetAI_npc_colossus(Creature* pCreature)
{
    return new  npc_colossusAI(pCreature);
}

void AddSC_boss_flame_leviathan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_flame_leviathan";
    newscript->GetAI = &GetAI_boss_flame_leviathan;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_flame_leviathan_seat";
    newscript->GetAI = &GetAI_boss_flame_leviathan_seat;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_flame_leviathan_defense_turret";
    newscript->GetAI = &GetAI_boss_flame_leviathan_defense_turret;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_flame_leviathan_overload_device";
    newscript->GetAI = &GetAI_boss_flame_leviathan_overload_device;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_flame_leviathan_safety_container";
    newscript->GetAI = &GetAI_boss_flame_leviathan_safety_containerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_pool_of_tar";
    newscript->GetAI = &GetAI_spell_pool_of_tar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_colossus";
    newscript->GetAI = &GetAI_npc_colossus;
    newscript->RegisterSelf();
}
