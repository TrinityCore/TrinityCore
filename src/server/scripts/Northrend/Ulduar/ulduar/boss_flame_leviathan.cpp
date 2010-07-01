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
* Comment: there is missing code on triggers,
*          brann bronzebeard needs correct gossip info.
*          requires more work involving area triggers.
*          if reached brann speaks through his radio..
*/

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
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

    SPELL_OVERLOAD_CIRCUIT                      = 62399,
    SPELL_START_THE_ENGINE                      = 62472,
    SPELL_SEARING_FLAME                         = 62402,
    SPELL_BLAZE                                 = 62292,
    SPELL_SMOKE_TRAIL                           = 63575,
    SPELL_ELECTROSHOCK                          = 62522,
    //TOWER Additional SPELLS
    SPELL_THORIM_S_HAMMER                       = 62911, // Tower of Storms
    SPELL_MIMIRON_S_INFERNO                     = 62909, // Tower of Flames
    SPELL_HODIR_S_FURY                          = 62533, // Tower of Frost
    SPELL_FREYA_S_WARD                          = 62906, // Tower of Nature
    SPELL_FREYA_SUMMONS                         = 62947, // Tower of Nature
    //TOWER ap & health spells
    SPELL_BUFF_TOWER_OF_STORMS                  = 65076,
    SPELL_BUFF_TOWER_OF_FLAMES                  = 65075,
    SPELL_BUFF_TOWER_OF_FR0ST                   = 65077,
    SPELL_BUFF_TOWER_OF_LIFE                    = 64482,
    //Additional Spells
    SPELL_LASH                                  = 65062,
    SPELL_FREYA_S_WARD_EFFECT_1                 = 62947,
    SPELL_FREYA_S_WARD_EFFECT_2                 = 62907,
    SPELL_AUTO_REPAIR                           = 62705,
    AURA_DUMMY_BLUE                             = 63294,
    AURA_DUMMY_GREEN                            = 63295,
    AURA_DUMMY_YELLOW                           = 63292,
    SPELL_LIQUID_PYRITE                         = 62494,
};

enum Creatures
{
    MOB_MECHANOLIFT                             = 33214,
    MOB_LIQUID                                  = 33189,
    MOB_CONTAINER                               = 33218,
    MOB_THORIM_BEACON                           = 33365,
    MOB_MIMIRON_BEACON                          = 33370,
    MOB_HODIR_BEACON                            = 33212,
    MOB_FREYA_BEACON                            = 33367,
    NPC_THORIM_TARGET_BEACON                    = 33364,
    NPC_MIMIRON_TARGET_BEACON                   = 33369,
    NPC_HODIR_TARGET_BEACON                     = 33108,
    NPC_FREYA_TARGET_BEACON                     = 33366,
    NPC_LOREKEEPER                              = 33686, //Hard mode starter
    NPC_BRANZ_BRONZBEARD                        = 33579,
    NPC_DELORAH                                 = 33701,
};

enum Towers
{
    GO_TOWER_OF_STORMS = 194377,
    GO_TOWER_OF_FLAMES = 194371,
    GO_TOWER_OF_FROST = 194370,
    GO_TOWER_OF_LIFE = 194375,
};

enum Events
{
    EVENT_NONE,
    EVENT_PURSUE,
    EVENT_MISSILE,
    EVENT_VENT,
    EVENT_SPEED,
    EVENT_SUMMON,
    EVENT_SHUTDOWN,
    EVENT_THORIM_S_HAMMER, // Tower of Storms
    EVENT_MIMIRON_S_INFERNO, // Tower of Flames
    EVENT_HODIR_S_FURY,      // Tower of Frost
    EVENT_FREYA_S_WARD,     // Tower of Nature
};

enum Seats
{
    SEAT_PLAYER                                 = 0,
    SEAT_TURRET                                 = 1,
    SEAT_DEVICE                                 = 2,
};

enum Vehicles
{
    VEHICLE_SIEGE                             = 33060,
    VEHICLE_CHOPPER                           = 33062,
    VEHICLE_DEMOLISHER                        = 33109,
};

#define EMOTE_PURSUE          "Flame Leviathan pursues $N."
#define EMOTE_OVERLOAD        "Flame Leviathan's circuits overloaded."
#define EMOTE_REPAIR          "Automatic repair sequence initiated."

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
    //ACHIEV_CHAMPION_OF_ULDUAR                   = 2903,
    //ACHIEV_CONQUEROR_OF_ULDUAR                  = 2904,
    ACHIEV_10_NUKED_FROM_ORBIT                  = 2915,
    ACHIEV_25_NUKED_FROM_ORBIT                  = 2917,
    ACHIEV_10_ORBITAL_BOMBARDMENT               = 2913,
    ACHIEV_25_ORBITAL_BOMBARDMENT               = 2918,
    ACHIEV_10_ORBITAL_DEVASTATION               = 2914,
    ACHIEV_25_ORBITAL_DEVASTATION               = 2916,
    ACHIEV_10_ORBIT_UARY                        = 3056,
    ACHIEV_25_ORBIT_UARY                        = 3057,
    ACHIEV_10_SHUTOUT                           = 2911,
    ACHIEV_25_SHUTOUT                           = 2912,
    ACHIEV_10_SIEGE_OF_ULDUAR                   = 2886,
    ACHIEV_25_SIEGE_OF_ULDUAR                   = 2887,
    ACHIEV_10_THREE_CAR_GARAGE                  = 2907, //no core support for using a vehicle
    ACHIEV_25_THREE_CAR_GARAGE                  = 2908, //no core support for using a vehicle
    ACHIEV_10_UNBROKEN                          = 2905,
    ACHIEV_25_UNBROKEN                          = 2906,
};

static Position Center[]=
{
    {354.8771, -12.90240, 409.803650},
};

const Position PosSiege[5] =
{
    {-814.59,-64.54,429.92,5.969},
    {-784.37,-33.31,429.92,5.096},
    {-808.99,-52.10,429.92,5.668},
    {-798.59,-44.00,429.92,5.663},
    {-812.83,-77.71,429.92,0.046},
};

const Position PosChopper[5] =
{
    {-717.83,-106.56,430.02,0.122},
    {-717.83,-114.23,430.44,0.122},
    {-717.83,-109.70,430.22,0.122},
    {-718.45,-118.24,430.26,0.052},
    {-718.45,-123.58,430.41,0.085},
};

const Position PosDemolisher[5] =
{
    {-724.12,-176.64,430.03,2.543},
    {-766.70,-225.03,430.50,1.710},
    {-729.54,-186.26,430.12,1.902},
    {-756.01,-219.23,430.50,2.369},
    {-798.01,-227.24,429.84,1.446},
};

struct boss_flame_leviathanAI : public BossAI
{
    boss_flame_leviathanAI(Creature* pCreature) : BossAI(pCreature, TYPE_LEVIATHAN), vehicle(pCreature->GetVehicleKit())
    {
        assert(vehicle);
        pInstance = me->GetInstanceData();
        uiActiveTowers = 4;
        ActiveTowers = false;
        towerOfStorms = false;
        towerOfLife = false;
        towerOfFlames = false;
        towerOfFrost = false;
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); //deathgrip

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
        me->SetReactState(REACT_PASSIVE);
    }

    ScriptedInstance* pInstance;

    Vehicle* vehicle;
    uint8 uiActiveTowers;
    bool ActiveTowers;
    bool towerOfStorms;
    bool towerOfLife;
    bool towerOfFlames;
    bool towerOfFrost;

    void Reset()
    {
        _Reset();
        /*me->SetLootMode(LOOT_MODE_HARD_MODE_4);
        me->SetLootMode(LOOT_MODE_HARD_MODE_3);
        me->SetLootMode(LOOT_MODE_HARD_MODE_2);
        me->SetLootMode(LOOT_MODE_HARD_MODE_1);*/
        if (pInstance)
            pInstance->SetData(TYPE_LEVIATHAN, NOT_STARTED);
        assert(vehicle);
        me->GetVehicleKit();
        me->SetReactState(REACT_DEFENSIVE);
    }

    void EnterCombat(Unit* /*who*/)
    {
        _EnterCombat();
        pInstance->SetData(TYPE_LEVIATHAN, IN_PROGRESS); //_Reset doesnt do this correctly
        me->SetReactState(REACT_AGGRESSIVE);
        events.ScheduleEvent(EVENT_PURSUE, 0);
        events.ScheduleEvent(EVENT_MISSILE, 1500);
        events.ScheduleEvent(EVENT_VENT, 20000);
        events.ScheduleEvent(EVENT_SPEED, 15000);
        events.ScheduleEvent(EVENT_SUMMON, 0);
        if (ActiveTowers)
        {
            if (towerOfStorms)
            {
                me->AddAura(SPELL_BUFF_TOWER_OF_STORMS, me);
                events.ScheduleEvent(EVENT_THORIM_S_HAMMER, 35000);
            }

            if (towerOfFlames)
            {
                me->AddAura(SPELL_BUFF_TOWER_OF_FLAMES, me);
                events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO,70000);
            }

            if (towerOfFrost)
            {
                me->AddAura(SPELL_BUFF_TOWER_OF_FR0ST, me);
                events.ScheduleEvent(EVENT_HODIR_S_FURY, 105000);
            }

            if (towerOfLife)
            {
                me->AddAura(SPELL_BUFF_TOWER_OF_LIFE, me);
                events.ScheduleEvent(EVENT_FREYA_S_WARD, 140000);
            }

            if (!towerOfLife && !towerOfFrost && !towerOfFlames && !towerOfStorms)
                DoScriptText(SAY_TOWER_NONE, me);
            else
                DoScriptText(SAY_HARDMODE, me);
        }
        else
            DoScriptText(SAY_AGGRO, me);

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
        pInstance->SetData(TYPE_LEVIATHAN, DONE); //_Reset doesnt do this correctly
        DoScriptText(SAY_DEATH, me);

        if (ActiveTowers)
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

    void SpellHit(Unit* /*caster*/, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_START_THE_ENGINE)
            vehicle->InstallAllAccessories();
        else
            if (pSpell->Id == SPELL_ELECTROSHOCK)
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

        if (me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            return;
        }
        else
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }

        uint32 eventId = events.GetEvent();
        if (!me->getVictim())
            eventId = EVENT_PURSUE;

        switch(eventId)
        {
        case 0: break; // this is a must
        case EVENT_PURSUE:
            DoCastAOE(SPELL_PURSUED, true);
            DoScriptText(RAND(SAY_TARGET_1, SAY_TARGET_2, SAY_TARGET_3), me);
            events.RescheduleEvent(EVENT_PURSUE, 30000);
            UpdateVictim(); // begin to kill other things
            if (me->getVictim())
                me->MonsterTextEmote(EMOTE_PURSUE, me->getVictim()->GetGUID(), true);
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
        case EVENT_SHUTDOWN:
            DoScriptText(RAND(SAY_OVERLOAD_1, SAY_OVERLOAD_2, SAY_OVERLOAD_3), me);
            me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
            DoCast(SPELL_SYSTEMS_SHUTDOWN);
            me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
            me->MonsterTextEmote(EMOTE_REPAIR, 0, true);
            events.CancelEvent(EVENT_SHUTDOWN);
            return;
        case EVENT_THORIM_S_HAMMER: // Tower of Storms
            for (uint8 i = 0; i < 7; ++i)
            {
                if (Creature* pThorim = DoSummon(MOB_THORIM_BEACON, me, urand(20,60), 20000, TEMPSUMMON_TIMED_DESPAWN))
                    pThorim->GetMotionMaster()->MoveRandom(100);
            }
            DoScriptText(SAY_TOWER_STORM, me);
            events.CancelEvent(EVENT_THORIM_S_HAMMER);
            return;
        case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
            me->SummonCreature(MOB_MIMIRON_BEACON, 390.93, -13.91, 409.81);
            DoScriptText(SAY_TOWER_FLAME, me);
            events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
            return;
        case EVENT_HODIR_S_FURY:      // Tower of Frost
            for (uint8 i = 0; i < 7; ++i)
            {
                if (Creature* pHodir = DoSummon(MOB_HODIR_BEACON, me, 50, 0))
                    pHodir->GetMotionMaster()->MoveRandom(100);
            }
            DoScriptText(SAY_TOWER_FROST, me);
            events.CancelEvent(EVENT_HODIR_S_FURY);
            return;
        case EVENT_FREYA_S_WARD:    // Tower of Nature
            DoScriptText(SAY_TOWER_NATURE, me);
            StartFreyaEvent();
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                DoCast(pTarget, SPELL_FREYA_S_WARD);
            events.CancelEvent(EVENT_FREYA_S_WARD);
            return;
        default:
            events.PopEvent();
            break;
        }
        if (me->IsWithinMeleeRange(me->getVictim()))
            DoSpellAttackIfReady(SPELL_BATTERING_RAM);
    }

    void StartFreyaEvent()//summon these 4 on each corner wich wil spawn additional hostile mobs
    {
        me->SummonCreature(MOB_FREYA_BEACON, 377.02, -119.10, 409.81);
        me->SummonCreature(MOB_FREYA_BEACON, 377.02, 54.78, 409.81);
        me->SummonCreature(MOB_FREYA_BEACON, 185.62, 54.78, 409.81);
        me->SummonCreature(MOB_FREYA_BEACON, 185.62, -119.10, 409.81);
    }

    void DoAction(const int32 uiAction)
    {
        // Start encounter
        if (uiAction == 10)
        {
            me->SetHomePosition(354.8771, -12.90240, 409.803, 0);
            me->GetMotionMaster()->MoveCharge(354.8771, -12.90240, 409.803); //position center
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
            DoZoneInCombat();
            return;
        }

        if (uiAction && uiAction <= 4) // Tower destruction, debuff leviathan loot and reduce active tower
        {
            if (me->HasLootMode(31) && uiActiveTowers == 4)
            {
                me->RemoveLootMode(LOOT_MODE_HARD_MODE_4);
                --uiActiveTowers;
            }
            if (me->HasLootMode(15) && uiActiveTowers == 3)
            {
                me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
                --uiActiveTowers;
            }
            if (me->HasLootMode(7) && uiActiveTowers == 2)
            {
                me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                --uiActiveTowers;
            }
            if (me->HasLootMode(3) && uiActiveTowers == 1)
            {
                me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                --uiActiveTowers;
            }
        }

        switch (uiAction)
        {
        case 0:  // Activate hard-mode setting counter to 4 towers, enable all towers apply buffs on levithian
            ActiveTowers = true;
            towerOfStorms = true;
            towerOfLife = true;
            towerOfFlames = true;
            towerOfFrost = true;
            me->SetLootMode(31);
            break;
        case 1:  // Tower of Storms destroyed
            towerOfStorms = false;
            break;
        case 2: // Tower of Flames destroyed
            towerOfFlames = false;
            break;
        case 3: // Tower of Frost destroyed
            towerOfFrost = false;
            break;
        case 4: // Tower of Nature destroyed
            towerOfLife = false;
            break;
        case 9: // Schedule event
            events.ScheduleEvent(EVENT_SHUTDOWN, 0);
            break;
        }
    }
};

//#define BOSS_DEBUG

struct boss_flame_leviathan_seatAI : public PassiveAI
{
    boss_flame_leviathan_seatAI(Creature* pCreature) : PassiveAI(pCreature), vehicle(pCreature->GetVehicleKit())
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
        else
            if (seatId == SEAT_TURRET)
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
    boss_flame_leviathan_overload_deviceAI(Creature* pCreature) : PassiveAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void DoAction(const int32 param)
    {
        if (param == EVENT_SPELLCLICK)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            pInstance->instance->GetCreature(TYPE_LEVIATHAN)->AI()->DoAction(9);   //should be called if all 3 overload devices are active
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
    boss_flame_leviathan_safety_containerAI(Creature* pCreature) : PassiveAI(pCreature)
    {
    }

    void JustDied()
    {
        float x,y,z;
        me->GetPosition(x,y,z);
        z = me->GetMap()->GetHeight(x, y, z);
        me->GetMotionMaster()->MovePoint(0,x,y,z);
        me->GetMap()->CreatureRelocation(me, x,y,z,0);
    }

    void UpdateAI(const uint32 diff)
    {        
    }
};
struct npc_mechanoliftAI : public PassiveAI
{
    npc_mechanoliftAI(Creature* pCreature) : PassiveAI(pCreature), vehicle(pCreature->GetVehicleKit())
    {
        assert(vehicle);
    }

    Vehicle* vehicle;

    uint32 MoveTimer;

    void Reset ()
    {
        MoveTimer = 0;
        me->GetMotionMaster()->MoveRandom(50);
    }

    void JustDied(Unit* pKiller)
    {
        me->GetMotionMaster()->MoveTargetedHome();
        Creature* pLiquid = DoSummon(MOB_LIQUID, me, 0);
        if (pLiquid)
        {
            pLiquid->CastSpell(pLiquid, SPELL_LIQUID_PYRITE, true);
            pLiquid->GetMotionMaster()->MoveFall(pKiller->GetPositionZ());
        }

    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (id == 1)
        {
            Creature* pContainer = me->FindNearestCreature(MOB_CONTAINER, 5, true);
            if (pContainer)
                pContainer->EnterVehicle(me);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (MoveTimer <= diff)
        {
            if (me->GetVehicleKit()->HasEmptySeat(-1))
            {
                Creature* pContainer = me->FindNearestCreature(MOB_CONTAINER, 50, true);
                if (pContainer && !pContainer->GetVehicle())
                    me->GetMotionMaster()->MovePoint(1,pContainer->GetPositionX(),pContainer->GetPositionY(),pContainer->GetPositionZ());
            }
            MoveTimer = 30000; //check next 30 seconds
        }
        else
            MoveTimer-=diff;
    }
};


struct spell_pool_of_tarAI : public PassiveAI
{
    spell_pool_of_tarAI(Creature* pCreature) : PassiveAI(pCreature)
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void DamageTaken(Unit * /*who*/, uint32 &damage)
    {
        damage = 0;
    }

    void SpellHit(Unit* /*caster*/, const SpellEntry* pSpell)
    {
        if (pSpell->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
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
        DoMeleeAttackIfReady() ;
    }
};

struct npc_thorims_hammerAI : public ScriptedAI
{
    npc_thorims_hammerAI(Creature* pCreature) : ScriptedAI (pCreature)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->AddAura(AURA_DUMMY_BLUE, me);
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who,0,10,false))
        {
            if (Creature* pTrigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                pTrigger->CastSpell(who, SPELL_THORIM_S_HAMMER, true);
        }
    }

    void Reset ()
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!me->HasAura(AURA_DUMMY_BLUE))
            me->AddAura(AURA_DUMMY_BLUE, me);

        if (!UpdateVictim())
            return;
    }
};

struct npc_mimirons_infernoAI : public npc_escortAI
{
    npc_mimirons_infernoAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->AddAura(AURA_DUMMY_YELLOW, me);
        me->SetReactState(REACT_PASSIVE);
    }

    void WaypointReached(uint32 i)
    {
    }

    void Reset()
    {
        infernoTimer = 2000;
    }

    uint32 infernoTimer;

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            Start(false,true,0,NULL,false,true);
        }
        else
        {
            if(infernoTimer <= diff)
            {
                if (Creature* pTrigger = DoSummonFlyer(NPC_MIMIRON_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                {
                    pTrigger->CastSpell(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(), SPELL_MIMIRON_S_INFERNO, true);
                    infernoTimer = 2000;
                }
            }
            else
                infernoTimer -= diff;

            if (!me->HasAura(AURA_DUMMY_YELLOW))
                me->AddAura(AURA_DUMMY_YELLOW, me);
        }
    }
};


struct npc_hodirs_furyAI : public ScriptedAI
{
    npc_hodirs_furyAI(Creature* pCreature) : ScriptedAI (pCreature)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->AddAura(AURA_DUMMY_GREEN, me);
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who,0,5,false))
        {
            if (Creature* pTrigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                pTrigger->CastSpell(who, SPELL_HODIR_S_FURY, true);
        }
    }

    void Reset()
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!me->HasAura(AURA_DUMMY_GREEN))
            me->AddAura(AURA_DUMMY_GREEN, me);

        if (!UpdateVictim())
            return;
    }
};

struct npc_freyas_wardAI : public ScriptedAI
{
    npc_freyas_wardAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        me->AddAura(AURA_DUMMY_GREEN, me);
    }

    uint32 summonTimer ;

    void Reset()
    {
        summonTimer = 5000 ;
    }

    void UpdateAI(const uint32 diff)
    {
        if(summonTimer <= diff)
        {
            DoCast(SPELL_FREYA_S_WARD_EFFECT_1) ;
            DoCast(SPELL_FREYA_S_WARD_EFFECT_2) ;
            summonTimer = 20000 ;
        }
        else
            summonTimer -= diff ;

        if (!me->HasAura(AURA_DUMMY_GREEN))
            me->AddAura(AURA_DUMMY_GREEN, me);

        if (!UpdateVictim())
            return;
    }
};

struct npc_freya_ward_summonAI : public ScriptedAI
{
    npc_freya_ward_summonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pCreature->GetMotionMaster()->MoveRandom(100);
    }

    uint32 lashTimer ;

    void Reset()
    {
        lashTimer = 5000 ;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(lashTimer <= diff)
        {
            DoCast(SPELL_LASH);
            lashTimer = 20000;
        }
        else
            lashTimer -= diff;

        DoMeleeAttackIfReady();
    }
};
//npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems"
#define GOSSIP_ITEM_2  "Confirmed"
struct npc_lorekeeperAI : public ScriptedAI
{
    npc_lorekeeperAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    void DoAction(const int32 uiAction)
    {
        // Start encounter
        if (uiAction == 0)
        {
            for(uint32 i = 0; i < (RAID_MODE(2,5)); ++i)
                DoSummon(VEHICLE_SIEGE, PosSiege[i],3000,TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            for(uint32 i = 0; i < (RAID_MODE(2,5)); ++i)
                DoSummon(VEHICLE_CHOPPER, PosChopper[i],3000,TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            for(uint32 i = 0; i < (RAID_MODE(2,5)); ++i)
                DoSummon(VEHICLE_DEMOLISHER,PosDemolisher[i],3000,TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            return;
        }
    }
};

bool GossipHello_npc_lorekeeper(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance && pInstance->GetData(TYPE_LEVIATHAN) !=DONE && pPlayer)
    {
        pPlayer->PrepareGossipMenu(pCreature);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }
    return true;
}
//enable hardmode
bool GossipSelect_npc_lorekeeper(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    switch(uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF+1:
        if (pPlayer)
        {
            pPlayer->PrepareGossipMenu(pCreature);
            pInstance->instance->LoadGrid(364,-16); //make sure leviathan is loaded


            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        if (pPlayer)
            pPlayer->CLOSE_GOSSIP_MENU();

        if (Creature* pLeviathan = pInstance->instance->GetCreature(pInstance->GetData64(TYPE_LEVIATHAN)))
        {
            CAST_AI(boss_flame_leviathanAI, (pLeviathan->AI()))->DoAction(0); //enable hard mode activating the 4 additional events spawning additional vehicles
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->AI()->DoAction(0); // spawn the vehicles
            pCreature->SetVisibility(VISIBILITY_OFF);
            if (Creature* Delorah = pCreature->FindNearestCreature(NPC_DELORAH, 1000, true))
            {
                if (Creature* Branz = pCreature->FindNearestCreature(NPC_BRANZ_BRONZBEARD, 1000, true))
                {
                    Delorah->GetMotionMaster()->MovePoint(0, Branz->GetPositionX()-4, Branz->GetPositionY(), Branz->GetPositionZ());
                    //TODO DoScriptText(xxxx, Delorah, Branz); when reached at branz
                }
            }
        }
        break;
    }
    return true;
}
////npc_brann_bronzebeard this requires more work involving area triggers. if reached this guy speaks through his radio..
//#define GOSSIP_ITEM_1  "xxxxx"
//#define GOSSIP_ITEM_2  "xxxxx"
//
//bool GossipHello_npc_brann_bronzebeard(Player* pPlayer, Creature* pCreature)
//{
//    ScriptedInstance* pInstance = pCreature->GetInstanceData();
//    if (pInstance && pInstance->GetData(TYPE_LEVIATHAN) !=DONE)
//    {
//        pPlayer->PrepareGossipMenu(pCreature);
//
//        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
//        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
//    }
//    return true;
//}
//
//bool GossipSelect_npc_brann_bronzebeard(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
//{
//    switch(uiAction)
//    {
//        case GOSSIP_ACTION_INFO_DEF+1:
//            if (pPlayer)
//            {
//                pPlayer->PrepareGossipMenu(pCreature);
//
//                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
//                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
//            }
//            break;
//        case GOSSIP_ACTION_INFO_DEF+2:
//            if (pPlayer)
//                pPlayer->CLOSE_GOSSIP_MENU();
//            if (Creature* Lorekeeper = pCreature->FindNearestCreature(NPC_LOREKEEPER, 1000, true)) //lore keeper of lorgannon
//                Lorekeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
//            break;
//    }
//    return true;
//}

void GODestroyed_go_ulduar_tower(Player* pPlayer, GameObject* pGO, uint32 value)
{
    ScriptedInstance* pInstance = pGO->GetInstanceData();
    if (pGO->GetGOValue()->building.health == 0)
    {
        switch(pGO->GetEntry())
        {
        case GO_TOWER_OF_STORMS:
            pInstance->ProcessEvent(pGO, EVENT_TOWER_OF_STORM_DESTROYED);
            break;
        case GO_TOWER_OF_FLAMES:
            pInstance->ProcessEvent(pGO, EVENT_TOWER_OF_FLAMES_DESTROYED);
            break;
        case GO_TOWER_OF_FROST:
            pInstance->ProcessEvent(pGO, EVENT_TOWER_OF_FROST_DESTROYED);
            break;
        case GO_TOWER_OF_LIFE:
            pInstance->ProcessEvent(pGO, EVENT_TOWER_OF_LIFE_DESTROYED);
            break;
        }
    }
}

bool AreaTrigger_at_RX_214_repair_o_matic_station(Player* pPlayer, const AreaTriggerEntry* pAt)
{
    if(Creature* vehicle = pPlayer->GetVehicleCreatureBase())
    {
        if(!vehicle->HasAura(SPELL_AUTO_REPAIR))
        {
            pPlayer->MonsterTextEmote(EMOTE_REPAIR, pPlayer->GetGUID(), true);
            pPlayer->CastSpell(vehicle, SPELL_AUTO_REPAIR, true);
        }
    }
    return true;
}

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

CreatureAI* GetAI_boss_flame_leviathan_safety_container(Creature* pCreature)
{
    return new boss_flame_leviathan_safety_containerAI(pCreature);
}

CreatureAI* GetAI_npc_mechanolift(Creature* pCreature)
{
    return new npc_mechanoliftAI(pCreature);
}

CreatureAI* GetAI_spell_pool_of_tar(Creature* pCreature)
{
    return new spell_pool_of_tarAI (pCreature);
}

CreatureAI* GetAI_npc_colossus(Creature* pCreature)
{
    return new  npc_colossusAI(pCreature);
}

CreatureAI* GetAI_npc_thorims_hammer(Creature* pCreature)
{
    return new  npc_thorims_hammerAI(pCreature);
}

CreatureAI* GetAI_npc_mimirons_inferno(Creature* pCreature)
{
    return new  npc_mimirons_infernoAI(pCreature);
}

CreatureAI* GetAI_npc_hodirs_fury(Creature* pCreature)
{
    return new  npc_hodirs_furyAI(pCreature);
}

CreatureAI* GetAI_npc_freyas_ward(Creature* pCreature)
{
    return new  npc_freyas_wardAI(pCreature);
}

CreatureAI* GetAI_npc_freya_ward_summon(Creature* pCreature)
{
    return new npc_freya_ward_summonAI (pCreature);
}
CreatureAI* GetAI_npc_lorekeeper(Creature* pCreature)
{
    return new npc_lorekeeperAI (pCreature);
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
    newscript->GetAI = &GetAI_boss_flame_leviathan_safety_container;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mechanolift";
    newscript->GetAI = &GetAI_npc_mechanolift;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_pool_of_tar";
    newscript->GetAI = &GetAI_spell_pool_of_tar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_colossus";
    newscript->GetAI = &GetAI_npc_colossus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_thorims_hammer";
    newscript->GetAI = &GetAI_npc_thorims_hammer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mimirons_inferno";
    newscript->GetAI = &GetAI_npc_mimirons_inferno;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_hodirs_fury";
    newscript->GetAI = &GetAI_npc_hodirs_fury;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_freyas_ward";
    newscript->GetAI = &GetAI_npc_freyas_ward;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_freya_ward_summon";
    newscript->GetAI = &GetAI_npc_freya_ward_summon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lorekeeper";
    newscript->GetAI = &GetAI_npc_lorekeeper;
    newscript->pGossipHello = &GossipHello_npc_lorekeeper;
    newscript->pGossipSelect = &GossipSelect_npc_lorekeeper;
    newscript->RegisterSelf();

    /*newscript = new Script;
    newscript->Name = "npc_brann_bronzebeard";
    newscript->pGossipHello = &GossipHello_npc_brann_bronzebeard;
    newscript->pGossipSelect = &GossipSelect_npc_brann_bronzebeard;
    newscript->RegisterSelf();*/

    newscript = new Script;
    newscript->Name = "go_ulduar_tower";
    newscript->pGODestroyed = &GODestroyed_go_ulduar_tower;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_RX_214_repair_o_matic_station";
    newscript->pAreaTrigger = &AreaTrigger_at_RX_214_repair_o_matic_station;
    newscript->RegisterSelf();
}
