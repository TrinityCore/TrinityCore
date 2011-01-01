/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
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
    SPELL_TAR_PASSIVE                           = 62288,
    SPELL_SMOKE_TRAIL                           = 63575,
    SPELL_ELECTROSHOCK                          = 62522,
    SPELL_NAPALM                                = 63666,
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
    NPC_ULDUAR_GAUNTLET_GENERATOR               = 33571, // Trigger tied to towers
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
    EVENT_REPAIR,
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
    SEAT_CANNON                                 = 7,
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
    {354.8771f, -12.90240f, 409.803650f, 0.0f},
};

const Position PosSiege[5] =
{
    {-814.59f,-64.54f,429.92f,5.969f},
    {-784.37f,-33.31f,429.92f,5.096f},
    {-808.99f,-52.10f,429.92f,5.668f},
    {-798.59f,-44.00f,429.92f,5.663f},
    {-812.83f,-77.71f,429.92f,0.046f},
};

const Position PosChopper[5] =
{
    {-717.83f,-106.56f,430.02f,0.122f},
    {-717.83f,-114.23f,430.44f,0.122f},
    {-717.83f,-109.70f,430.22f,0.122f},
    {-718.45f,-118.24f,430.26f,0.052f},
    {-718.45f,-123.58f,430.41f,0.085f},
};

const Position PosDemolisher[5] =
{
    {-724.12f,-176.64f,430.03f,2.543f},
    {-766.70f,-225.03f,430.50f,1.710f},
    {-729.54f,-186.26f,430.12f,1.902f},
    {-756.01f,-219.23f,430.50f,2.369f},
    {-798.01f,-227.24f,429.84f,1.446f},
};

class boss_flame_leviathan : public CreatureScript
{
public:
    boss_flame_leviathan() : CreatureScript("boss_flame_leviathan") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathanAI (pCreature);
    }

    struct boss_flame_leviathanAI : public BossAI
    {
        boss_flame_leviathanAI(Creature* pCreature) : BossAI(pCreature, TYPE_LEVIATHAN), vehicle(pCreature->GetVehicleKit())
        {
            assert(vehicle);
            uiActiveTowers = 4;
            uiShutdown = 0;
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

        Vehicle* vehicle;
        uint8 uiActiveTowers;
        uint8 uiShutdown;
        bool ActiveTowers;
        bool towerOfStorms;
        bool towerOfLife;
        bool towerOfFlames;
        bool towerOfFrost;

        void Reset()
        {
            _Reset();
            me->SetReactState(REACT_DEFENSIVE);
            InstallAdds(true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_PURSUE, 30*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_MISSILE, 1500);
            events.ScheduleEvent(EVENT_VENT, 20*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SPEED, 15*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUMMON, 1*IN_MILLISECONDS);
            ActiveTower(false); //void ActiveTower
            InstallAdds(false);
        }

        void ActiveTower(bool bReset = false)
        {
            if (!bReset)
            {
                if (ActiveTowers)
                {
                    if (towerOfStorms)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_STORMS, me);
                        events.ScheduleEvent(EVENT_THORIM_S_HAMMER, 35*IN_MILLISECONDS);
                    }

                    if (towerOfFlames)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_FLAMES, me);
                        events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO,70*IN_MILLISECONDS);
                    }

                    if (towerOfFrost)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_FR0ST, me);
                        events.ScheduleEvent(EVENT_HODIR_S_FURY, 105*IN_MILLISECONDS);
                    }

                    if (towerOfLife)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_LIFE, me);
                        events.ScheduleEvent(EVENT_FREYA_S_WARD, 140*IN_MILLISECONDS);
                    }

                    if (!towerOfLife && !towerOfFrost && !towerOfFlames && !towerOfStorms)
                        DoScriptText(SAY_TOWER_NONE, me);
                    else
                        DoScriptText(SAY_HARDMODE, me);
                }
                else
                    DoScriptText(SAY_AGGRO, me);
            }
        }

        void InstallAdds(bool bReset = false)
        {
            if (!bReset)
            {
                std::list<Creature*> lSeats;
                me->GetCreatureListWithEntryInGrid(lSeats, 33114,17.0f);
                if (lSeats.empty())
                    return;
                for(std::list<Creature*>::const_iterator itr = lSeats.begin(); itr != lSeats.end(); itr++)
                {
                    Vehicle* pSeat = (*itr)->GetVehicleKit();
                    if (Creature* pTurret = (me->SummonCreature(33142, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN)))
                        pTurret->EnterVehicle(pSeat, SEAT_TURRET);

                    if (Creature* pDevice = (me->SummonCreature(33143, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN)))
                        pDevice->EnterVehicle(pSeat, SEAT_DEVICE);
                }
            }
            else
            {
                std::list<Creature*> lSeats;
                me->GetCreatureListWithEntryInGrid(lSeats, 33114,17.0f);
                if (lSeats.empty())
                    return;
                for(std::list<Creature*>::const_iterator itr = lSeats.begin(); itr != lSeats.end(); itr++)
                {
                    Vehicle* pSeat = (*itr)->GetVehicleKit();
                    if (Unit* pTurret = (pSeat->GetPassenger(SEAT_TURRET)))
                        pTurret->RemoveFromWorld();

                    if (Unit* pDevice = (pSeat->GetPassenger(SEAT_DEVICE)))
                        pDevice->RemoveFromWorld();

                }
            }
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

            if (ActiveTowers)
            {
                switch (uiActiveTowers)
                {
                case 4:
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBIT_UARY, ACHIEV_25_ORBIT_UARY));
                case 3:
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_NUKED_FROM_ORBIT, ACHIEV_25_NUKED_FROM_ORBIT));
                case 2:
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_DEVASTATION, ACHIEV_25_ORBITAL_DEVASTATION));
                case 1:
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_BOMBARDMENT, ACHIEV_25_ORBITAL_BOMBARDMENT));
                }
            }
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_START_THE_ENGINE)
                vehicle->InstallAllAccessories(me->GetEntry());

            if (pSpell->Id == SPELL_ELECTROSHOCK)
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);

            if (pSpell->Id == SPELL_OVERLOAD_CIRCUIT)
                uiShutdown++;
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

            if (uiShutdown == RAID_MODE(2,4))
            {
                uiShutdown = 0;
                events.ScheduleEvent(EVENT_SHUTDOWN, 0);
                events.ScheduleEvent(EVENT_REPAIR, 0);
                me->RemoveAurasDueToSpell(SPELL_OVERLOAD_CIRCUIT);
                me->InterruptNonMeleeSpells(true);
                return;
            }

            if (me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                return;
            }

            if (me->HasUnitState(UNIT_STAT_CASTING))
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

            events.Update(diff);

            uint32 eventId = events.GetEvent();
            if (!me->getVictim())
                UpdateVictim();

            switch(eventId)
            {
            case 0: break; // this is a must
            case EVENT_PURSUE:
                DoScriptText(RAND(SAY_TARGET_1, SAY_TARGET_2, SAY_TARGET_3), me);
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    if (pTarget->GetTypeId() == TYPEID_PLAYER || pTarget->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE))
                    {
                        me->AddAura(SPELL_PURSUED, pTarget);
                        me->MonsterTextEmote(EMOTE_PURSUE, pTarget->GetGUID(), true);
                    }
                }
                events.RepeatEvent(30*IN_MILLISECONDS);
                break;
            case EVENT_MISSILE:
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(pTarget, SPELL_MISSILE_BARRAGE);
                events.RepeatEvent(1500);
                break;
            case EVENT_VENT:
                DoCastAOE(SPELL_FLAME_VENTS);
                events.RepeatEvent(20*IN_MILLISECONDS);
                break;
            case EVENT_SPEED:
                DoCastAOE(SPELL_GATHERING_SPEED);
                events.RepeatEvent(15*IN_MILLISECONDS);
                break;
            case EVENT_SUMMON:
                if (summons.size() < 15) // 4seat+1turret+10lift
                    if (Creature* pLift = DoSummonFlyer(MOB_MECHANOLIFT, me, 30.0f, 50.0f, 0))
                        pLift->GetMotionMaster()->MoveRandom(100);
                events.RepeatEvent(2*IN_MILLISECONDS);
                break;
            case EVENT_SHUTDOWN:
                DoScriptText(RAND(SAY_OVERLOAD_1, SAY_OVERLOAD_2, SAY_OVERLOAD_3), me);
                InstallAdds(true);
                me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                me->AddAura(SPELL_SYSTEMS_SHUTDOWN, me);
                me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
                events.CancelEvent(EVENT_SHUTDOWN);
                break;
            case EVENT_REPAIR:
                me->MonsterTextEmote(EMOTE_REPAIR, 0, true);
                me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                InstallAdds(false);
                events.CancelEvent(EVENT_REPAIR);
                break;
            case EVENT_THORIM_S_HAMMER: // Tower of Storms
                for (uint8 i = 0; i < 7; ++i)
                {
                    if (Creature* pThorim = DoSummon(MOB_THORIM_BEACON, me, float(urand(20,60)), 20000, TEMPSUMMON_TIMED_DESPAWN))
                        pThorim->GetMotionMaster()->MoveRandom(100);
                }
                DoScriptText(SAY_TOWER_STORM, me);
                events.CancelEvent(EVENT_THORIM_S_HAMMER);
                break;
            case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
                me->SummonCreature(MOB_MIMIRON_BEACON, 390.93f, -13.91f, 409.81f);
                DoScriptText(SAY_TOWER_FLAME, me);
                events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
                break;
            case EVENT_HODIR_S_FURY:      // Tower of Frost
                for (uint8 i = 0; i < 7; ++i)
                {
                    if (Creature* pHodir = DoSummon(MOB_HODIR_BEACON, me, 50, 0))
                        pHodir->GetMotionMaster()->MoveRandom(100);
                }
                DoScriptText(SAY_TOWER_FROST, me);
                events.CancelEvent(EVENT_HODIR_S_FURY);
                break;
            case EVENT_FREYA_S_WARD:    // Tower of Nature
                DoScriptText(SAY_TOWER_NATURE, me);
                StartFreyaEvent();
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(pTarget, SPELL_FREYA_S_WARD);
                events.CancelEvent(EVENT_FREYA_S_WARD);
                break;
            default:
                events.PopEvent();
                break;
            }
            /*if (me->IsWithinMeleeRange(me->getVictim())) //bugged spell casts on units that are boarded on leviathan
            DoSpellAttackIfReady(SPELL_BATTERING_RAM);*/
            DoMeleeAttackIfReady();
        }

        void StartFreyaEvent()//summon these 4 on each corner wich wil spawn additional hostile mobs
        {
            me->SummonCreature(MOB_FREYA_BEACON, 377.02f, -119.10f, 409.81f);
            me->SummonCreature(MOB_FREYA_BEACON, 377.02f, 54.78f, 409.81f);
            me->SummonCreature(MOB_FREYA_BEACON, 185.62f, 54.78f, 409.81f);
            me->SummonCreature(MOB_FREYA_BEACON, 185.62f, -119.10f, 409.81f);
        }

        void DoAction(const int32 uiAction)
        {
            // Start encounter
            if (uiAction == 10)
            {
                me->SetHomePosition(354.8771f, -12.90240f, 409.803f, 0);
                me->GetMotionMaster()->MoveCharge(354.8771f, -12.90240f, 409.803f); //position center
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
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
            }
        }
    };

};

//#define BOSS_DEBUG

class boss_flame_leviathan_seat : public CreatureScript
{
public:
    boss_flame_leviathan_seat() : CreatureScript("boss_flame_leviathan_seat") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_seatAI (pCreature);
    }

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
                else
                    DoScriptText(SAY_PLAYER_RIDING,me);

                if (Creature* pTurret = CAST_CRE(vehicle->GetPassenger(SEAT_TURRET)))
                {
                    pTurret->setFaction(me->GetVehicleBase()->getFaction());
                    pTurret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                    pTurret->AI()->AttackStart(who);
                }
                if (Unit* pDevice = CAST_CRE(vehicle->GetPassenger(SEAT_DEVICE)))
                {
                    pDevice->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    pDevice->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }
            //else //throw passenger bugged, when fixed uncomment this part.
            //    if (seatId == SEAT_TURRET)
            //    {
            //        if (apply)
            //            return;
            //        if (Unit* device = vehicle->GetPassenger(SEAT_DEVICE))
            //        {
            //            device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            //            device->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
            //        }
            //    }
        }
    };

};

class boss_flame_leviathan_defense_cannon : public CreatureScript
{
public:
    boss_flame_leviathan_defense_cannon() : CreatureScript("boss_flame_leviathan_defense_cannon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_defense_cannonAI (pCreature);
    }

    struct boss_flame_leviathan_defense_cannonAI : public ScriptedAI
    {
        boss_flame_leviathan_defense_cannonAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        uint32 NapalmTimer;

        void Reset ()
        {
            NapalmTimer = 5000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (NapalmTimer <= diff)
            {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    {
                        if(CanAIAttack(pTarget))
                            DoCast(pTarget,SPELL_NAPALM,true);
                    }
                    NapalmTimer = 5000;
            }
            else
                NapalmTimer-=diff;
        }

        bool CanAIAttack(const Unit *who) const
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != 33114)
                return false;
            return true;
        }
    };
};

class boss_flame_leviathan_defense_turret : public CreatureScript
{
public:
    boss_flame_leviathan_defense_turret() : CreatureScript("boss_flame_leviathan_defense_turret") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_defense_turretAI (pCreature);
    }

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

};

class boss_flame_leviathan_overload_device : public CreatureScript
{
public:
    boss_flame_leviathan_overload_device() : CreatureScript("boss_flame_leviathan_overload_device") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_overload_deviceAI (pCreature);
    }

    struct boss_flame_leviathan_overload_deviceAI : public PassiveAI
    {
        boss_flame_leviathan_overload_deviceAI(Creature* pCreature) : PassiveAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript *instance;

        void DoAction(const int32 param)
        {
            if (param == EVENT_SPELLCLICK)
            {
                if (me->GetVehicle())
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    if (Unit* pPlayer = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                    {
                        me->GetVehicleBase()->CastSpell(pPlayer, SPELL_SMOKE_TRAIL, true);
                        pPlayer->GetMotionMaster()->MoveKnockbackFrom(me->GetVehicleBase()->GetPositionX(), me->GetVehicleBase()->GetPositionY(), 30, 30);
                        pPlayer->ExitVehicle();
                    }
                }
            }
        }
    };

};

class boss_flame_leviathan_safety_container : public CreatureScript
{
public:
    boss_flame_leviathan_safety_container() : CreatureScript("boss_flame_leviathan_safety_container") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_safety_containerAI(pCreature);
    }

    struct boss_flame_leviathan_safety_containerAI : public PassiveAI
    {
        boss_flame_leviathan_safety_containerAI(Creature* pCreature) : PassiveAI(pCreature)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            float x,y,z;
            me->GetPosition(x,y,z);
            z = me->GetMap()->GetHeight(x, y, z);
            me->GetMotionMaster()->MovePoint(0,x,y,z);
            me->GetMap()->CreatureRelocation(me, x,y,z,0);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
        }
    };
};

class npc_mechanolift : public CreatureScript
{
public:
    npc_mechanolift() : CreatureScript("npc_mechanolift") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_mechanoliftAI(pCreature);
    }

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

        void MovementInform(uint32 /*type*/, uint32 id)
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

};


class spell_pool_of_tar : public CreatureScript
{
public:
    spell_pool_of_tar() : CreatureScript("spell_pool_of_tar") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new spell_pool_of_tarAI (pCreature);
    }

    struct spell_pool_of_tarAI : public PassiveAI
    {
        spell_pool_of_tarAI(Creature* pCreature) : PassiveAI(pCreature)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AddAura(SPELL_TAR_PASSIVE, me);
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

};

class npc_colossus : public CreatureScript
{
public:
    npc_colossus() : CreatureScript("npc_colossus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_colossusAI(pCreature);
    }

    struct npc_colossusAI : public ScriptedAI
    {
        npc_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript *instance;

        void JustDied(Unit* /*Who*/)
        {
            if (me->GetHomePosition().IsInDist(Center,50.f))
                instance->SetData(TYPE_COLOSSUS,instance->GetData(TYPE_COLOSSUS)+1);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady() ;
        }
    };

};

class npc_thorims_hammer : public CreatureScript
{
public:
    npc_thorims_hammer() : CreatureScript("npc_thorims_hammer") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_thorims_hammerAI(pCreature);
    }

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

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!me->HasAura(AURA_DUMMY_BLUE))
                me->AddAura(AURA_DUMMY_BLUE, me);

            if (!UpdateVictim())
                return;
        }
    };

};

class npc_mimirons_inferno : public CreatureScript
{
public:
    npc_mimirons_inferno() : CreatureScript("npc_mimirons_inferno") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_mimirons_infernoAI(pCreature);
    }

    struct npc_mimirons_infernoAI : public npc_escortAI
    {
        npc_mimirons_infernoAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->AddAura(AURA_DUMMY_YELLOW, me);
            me->SetReactState(REACT_PASSIVE);
        }

        void WaypointReached(uint32 /*i*/)
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

};


class npc_hodirs_fury : public CreatureScript
{
public:
    npc_hodirs_fury() : CreatureScript("npc_hodirs_fury") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_hodirs_furyAI(pCreature);
    }

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

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!me->HasAura(AURA_DUMMY_GREEN))
                me->AddAura(AURA_DUMMY_GREEN, me);

            if (!UpdateVictim())
                return;
        }
    };

};

class npc_freyas_ward : public CreatureScript
{
public:
    npc_freyas_ward() : CreatureScript("npc_freyas_ward") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_freyas_wardAI(pCreature);
    }

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

};

class npc_freya_ward_summon : public CreatureScript
{
public:
    npc_freya_ward_summon() : CreatureScript("npc_freya_ward_summon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_freya_ward_summonAI (pCreature);
    }

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

};

//npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems"
#define GOSSIP_ITEM_2  "Confirmed"
class npc_lorekeeper : public CreatureScript
{
public:
    npc_lorekeeper() : CreatureScript("npc_lorekeeper") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        InstanceScript* instance = pCreature->GetInstanceScript();
        switch(uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            if (pPlayer)
            {
                pPlayer->PrepareGossipMenu(pCreature);
                instance->instance->LoadGrid(364,-16); //make sure leviathan is loaded


                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            }
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            if (pPlayer)
                pPlayer->CLOSE_GOSSIP_MENU();

            if (Creature* pLeviathan = instance->instance->GetCreature(instance->GetData64(TYPE_LEVIATHAN)))
            {
                CAST_AI(boss_flame_leviathan::boss_flame_leviathanAI, (pLeviathan->AI()))->DoAction(0); //enable hard mode activating the 4 additional events spawning additional vehicles
                pCreature->SetVisible(false);
                pCreature->AI()->DoAction(0); // spawn the vehicles
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

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();
        if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE && pPlayer)
        {
            pPlayer->PrepareGossipMenu(pCreature);

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lorekeeperAI (pCreature);
    }

    struct npc_lorekeeperAI : public ScriptedAI
    {
        npc_lorekeeperAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;

        void DoAction(const int32 uiAction)
        {
            // Start encounter
            if (uiAction == 0)
            {
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_SIEGE, PosSiege[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_CHOPPER, PosChopper[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_DEMOLISHER, PosDemolisher[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                return;
            }
        }
    };

};

//enable hardmode
////npc_brann_bronzebeard this requires more work involving area triggers. if reached this guy speaks through his radio..
//#define GOSSIP_ITEM_1  "xxxxx"
//#define GOSSIP_ITEM_2  "xxxxx"
//
/*
class npc_brann_bronzebeard : public CreatureScript
{
public:
    npc_brann_bronzebeard() : CreatureScript("npc_brann_bronzebeard") { }

    //bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    //{
    //    pPlayer->PlayerTalkClass->ClearMenus();
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
    //bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    //{
    //    InstanceScript* instance = pCreature->GetInstanceScript();
    //    if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE)
    //    {
    //        pPlayer->PrepareGossipMenu(pCreature);
    //
    //        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
    //        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    //    }
    //    return true;
    //}
    //
}
*/

class go_ulduar_tower : public GameObjectScript
{
public:
    go_ulduar_tower() : GameObjectScript("go_ulduar_tower") { }

    void OnDestroyed(Player* /*pPlayer*/, GameObject* pGO, uint32 /*value*/)
    {
        InstanceScript* instance = pGO->GetInstanceScript();
        switch(pGO->GetEntry())
        {
            case GO_TOWER_OF_STORMS:
                instance->ProcessEvent(pGO, EVENT_TOWER_OF_STORM_DESTROYED);
                break;
            case GO_TOWER_OF_FLAMES:
                instance->ProcessEvent(pGO, EVENT_TOWER_OF_FLAMES_DESTROYED);
                break;
            case GO_TOWER_OF_FROST:
                instance->ProcessEvent(pGO, EVENT_TOWER_OF_FROST_DESTROYED);
                break;
            case GO_TOWER_OF_LIFE:
                instance->ProcessEvent(pGO, EVENT_TOWER_OF_LIFE_DESTROYED);
                break;
        }

        Creature* trigger = pGO->FindNearestCreature(NPC_ULDUAR_GAUNTLET_GENERATOR, 15.0f, true);
        if (trigger)
            trigger->DisappearAndDie();
    }
};

class at_RX_214_repair_o_matic_station : public AreaTriggerScript
{
public:
    at_RX_214_repair_o_matic_station() : AreaTriggerScript("at_RX_214_repair_o_matic_station") { }

    bool OnTrigger(Player* pPlayer, const AreaTriggerEntry* /*pAt*/)
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

};

void AddSC_boss_flame_leviathan()
{
    new boss_flame_leviathan();
    new boss_flame_leviathan_seat();
    new boss_flame_leviathan_defense_turret();
    new boss_flame_leviathan_overload_device();
    new boss_flame_leviathan_safety_container();
    new npc_mechanolift();
    new spell_pool_of_tar();
    new npc_colossus();
    new npc_thorims_hammer();
    new npc_mimirons_inferno();
    new npc_hodirs_fury();
    new npc_freyas_ward();
    new npc_freya_ward_summon();
    new npc_lorekeeper();
    // new npc_brann_bronzebeard();
    new go_ulduar_tower();
    new at_RX_214_repair_o_matic_station();
}
