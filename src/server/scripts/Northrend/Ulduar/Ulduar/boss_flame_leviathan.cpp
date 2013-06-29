/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "ulduar.h"
#include "Spell.h"

enum Spells
{
    SPELL_PURSUED                  = 62374,
    SPELL_GATHERING_SPEED          = 62375,
    SPELL_BATTERING_RAM            = 62376,
    SPELL_FLAME_VENTS              = 62396,
    SPELL_MISSILE_BARRAGE          = 62400,
    SPELL_SYSTEMS_SHUTDOWN         = 62475,
    SPELL_OVERLOAD_CIRCUIT         = 62399,
    SPELL_START_THE_ENGINE         = 62472,
    SPELL_SEARING_FLAME            = 62402,
    SPELL_BLAZE                    = 62292,
    SPELL_TAR_PASSIVE              = 62288,
    SPELL_SMOKE_TRAIL              = 63575,
    SPELL_ELECTROSHOCK             = 62522,
    SPELL_NAPALM                   = 63666,
    SPELL_INVIS_AND_STEALTH_DETECT = 18950, // Passive
    //TOWER Additional SPELLS
    SPELL_THORIM_S_HAMMER          = 62911, // Tower of Storms
    SPELL_MIMIRON_S_INFERNO        = 62909, // Tower of Flames
    SPELL_HODIR_S_FURY             = 62533, // Tower of Frost
    SPELL_FREYA_S_WARD             = 62906, // Tower of Nature
    SPELL_FREYA_SUMMONS            = 62947, // Tower of Nature
    //TOWER ap & health spells
    SPELL_BUFF_TOWER_OF_STORMS     = 65076,
    SPELL_BUFF_TOWER_OF_FLAMES     = 65075,
    SPELL_BUFF_TOWER_OF_FR0ST      = 65077,
    SPELL_BUFF_TOWER_OF_LIFE       = 64482,
    //Additional Spells
    SPELL_LASH                     = 65062,
    SPELL_FREYA_S_WARD_EFFECT_1    = 62947,
    SPELL_FREYA_S_WARD_EFFECT_2    = 62907,
    SPELL_AUTO_REPAIR              = 62705,
    AURA_DUMMY_BLUE                = 63294,
    AURA_DUMMY_GREEN               = 63295,
    AURA_DUMMY_YELLOW              = 63292,
    SPELL_LIQUID_PYRITE            = 62494,
    SPELL_DUSTY_EXPLOSION          = 63360,
    SPELL_DUST_CLOUD_IMPACT        = 54740,
    AURA_STEALTH_DETECTION         = 18950,
    SPELL_RIDE_VEHICLE             = 46598,
};

enum Creatures
{
    NPC_SEAT                       = 33114,
    NPC_MECHANOLIFT                = 33214,
    NPC_LIQUID                     = 33189,
    NPC_CONTAINER                  = 33218,
    NPC_THORIM_BEACON              = 33365,
    NPC_MIMIRON_BEACON             = 33370,
    NPC_HODIR_BEACON               = 33212,
    NPC_FREYA_BEACON               = 33367,
    NPC_THORIM_TARGET_BEACON       = 33364,
    NPC_MIMIRON_TARGET_BEACON      = 33369,
    NPC_HODIR_TARGET_BEACON        = 33108,
    NPC_FREYA_TARGET_BEACON        = 33366,
    NPC_LOREKEEPER                 = 33686, // Hard mode starter
    NPC_BRANZ_BRONZBEARD           = 33579,
    NPC_DELORAH                    = 33701,
    NPC_ULDUAR_GAUNTLET_GENERATOR  = 33571, // Trigger tied to towers
};

enum Towers
{
    GO_TOWER_OF_STORMS    = 194377,
    GO_TOWER_OF_FLAMES    = 194371,
    GO_TOWER_OF_FROST     = 194370,
    GO_TOWER_OF_LIFE      = 194375,
};

enum Events
{
    EVENT_PURSUE               = 1,
    EVENT_MISSILE              = 2,
    EVENT_VENT                 = 3,
    EVENT_SPEED                = 4,
    EVENT_SUMMON               = 5,
    EVENT_SHUTDOWN             = 6,
    EVENT_REPAIR               = 7,
    EVENT_THORIM_S_HAMMER      = 8,    // Tower of Storms
    EVENT_MIMIRON_S_INFERNO    = 9,    // Tower of Flames
    EVENT_HODIR_S_FURY         = 10,   // Tower of Frost
    EVENT_FREYA_S_WARD         = 11,   // Tower of Nature
};

enum Seats
{
    SEAT_PLAYER    = 0,
    SEAT_TURRET    = 1,
    SEAT_DEVICE    = 2,
    SEAT_CANNON    = 7,
};

enum Vehicles
{
    VEHICLE_SIEGE         = 33060,
    VEHICLE_CHOPPER       = 33062,
    VEHICLE_DEMOLISHER    = 33109,
};

#define DATA_SHUTOUT      29112912 // 2911, 2912 are achievement IDs
#define DATA_ORBIT_ACHIEVEMENTS    1
#define VEHICLE_SPAWNS             5
#define FREYA_SPAWNS               4

enum Yells
{
    SAY_AGGRO            = 0,
    SAY_SLAY             = 1,
    SAY_DEATH            = 2,
    SAY_TARGET           = 3,
    SAY_HARDMODE         = 4,
    SAY_TOWER_NONE       = 5,
    SAY_TOWER_FROST      = 6,
    SAY_TOWER_FLAME      = 7,
    SAY_TOWER_NATURE     = 8,
    SAY_TOWER_STORM      = 9,
    SAY_PLAYER_RIDING    = 10,
    SAY_OVERLOAD         = 11,
    EMOTE_PURSUE         = 12,
    EMOTE_OVERLOAD       = 13,
    EMOTE_REPAIR         = 14
};

enum MiscellanousData
{
    // Other Actions are in Ulduar.h
    ACTION_START_HARD_MODE    = 5,
    ACTION_SPAWN_VEHICLES     = 6,
    // Amount of seats depending on Raid mode
    TWO_SEATS                 = 2,
    FOUR_SEATS                = 4,
};

Position const Center = { 354.8771f, -12.90240f, 409.803650f, 0.0f };
Position const InfernoStart = { 390.93f, -13.91f, 409.81f, 0.0f };

Position const PosSiege[VEHICLE_SPAWNS] =
{
    {-814.59f, -64.54f, 429.92f, 5.969f},
    {-784.37f, -33.31f, 429.92f, 5.096f},
    {-808.99f, -52.10f, 429.92f, 5.668f},
    {-798.59f, -44.00f, 429.92f, 5.663f},
    {-812.83f, -77.71f, 429.92f, 0.046f},
};

Position const PosChopper[VEHICLE_SPAWNS] =
{
    {-717.83f, -106.56f, 430.02f, 0.122f},
    {-717.83f, -114.23f, 430.44f, 0.122f},
    {-717.83f, -109.70f, 430.22f, 0.122f},
    {-718.45f, -118.24f, 430.26f, 0.052f},
    {-718.45f, -123.58f, 430.41f, 0.085f},
};

Position const PosDemolisher[VEHICLE_SPAWNS] =
{
    {-724.12f, -176.64f, 430.03f, 2.543f},
    {-766.70f, -225.03f, 430.50f, 1.710f},
    {-729.54f, -186.26f, 430.12f, 1.902f},
    {-756.01f, -219.23f, 430.50f, 2.369f},
    {-798.01f, -227.24f, 429.84f, 1.446f},
};

Position const FreyaBeacons[FREYA_SPAWNS] =
{
    {377.02f, -119.10f, 409.81f, 0.0f},
    {185.62f, -119.10f, 409.81f, 0.0f},
    {377.02f, 54.78f, 409.81f, 0.0f},
    {185.62f, 54.78f, 409.81f, 0.0f},
};

class boss_flame_leviathan : public CreatureScript
{
    public:
        boss_flame_leviathan() : CreatureScript("boss_flame_leviathan") { }

        struct boss_flame_leviathanAI : public BossAI
        {
            boss_flame_leviathanAI(Creature* creature) : BossAI(creature, BOSS_LEVIATHAN), vehicle(creature->GetVehicleKit())
            {
            }

            void InitializeAI()
            {
                ASSERT(vehicle);
                if (!me->isDead())
                    Reset();

                ActiveTowersCount = 4;
                Shutdown = 0;
                ActiveTowers = false;
                towerOfStorms = false;
                towerOfLife = false;
                towerOfFlames = false;
                towerOfFrost = false;
                Shutout = true;
                Unbroken = true;

                DoCast(SPELL_INVIS_AND_STEALTH_DETECT);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                me->SetReactState(REACT_PASSIVE);
            }

            Vehicle* vehicle;
            uint8 ActiveTowersCount;
            uint8 Shutdown;
            bool ActiveTowers;
            bool towerOfStorms;
            bool towerOfLife;
            bool towerOfFlames;
            bool towerOfFrost;
            bool Shutout;
            bool Unbroken;

            void Reset()
            {
                _Reset();
                //resets shutdown counter to 0.  2 or 4 depending on raid mode
                Shutdown = 0;
                _pursueTarget = 0;

                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_PURSUE, 1);
                events.ScheduleEvent(EVENT_MISSILE, urand(1500, 4*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_VENT, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPEED, 15*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON, 1*IN_MILLISECONDS);
                ActiveTower(); //void ActiveTower
            }

            void ActiveTower()
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
                        events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO, 70*IN_MILLISECONDS);
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
                        Talk(SAY_TOWER_NONE);
                    else
                        Talk(SAY_HARDMODE);
                }
                else
                    Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                // Set Field Flags 67108928 = 64 | 67108864 = UNIT_FLAG_UNK_6 | UNIT_FLAG_SKINNABLE
                // Set DynFlags 12
                // Set NPCFlags 0
                Talk(SAY_DEATH);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_START_THE_ENGINE)
                    vehicle->InstallAllAccessories(false);

                if (spell->Id == SPELL_ELECTROSHOCK)
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                if (spell->Id == SPELL_OVERLOAD_CIRCUIT)
                    ++Shutdown;
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_SHUTOUT:
                        return Shutout ? 1 : 0;
                    case DATA_UNBROKEN:
                        return Unbroken ? 1 : 0;
                    case DATA_ORBIT_ACHIEVEMENTS:
                        if (ActiveTowers) // Only on HardMode
                            return ActiveTowersCount;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 data)
            {
                if (id == DATA_UNBROKEN)
                    Unbroken = data ? true : false;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (Shutdown == RAID_MODE(TWO_SEATS, FOUR_SEATS))
                {
                    Shutdown = 0;
                    events.ScheduleEvent(EVENT_SHUTDOWN, 4000);
                    me->RemoveAurasDueToSpell(SPELL_OVERLOAD_CIRCUIT);
                    me->InterruptNonMeleeSpells(true);
                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PURSUE:
                            Talk(SAY_TARGET);
                            DoCast(SPELL_PURSUED);  // Will select target in spellscript
                            events.ScheduleEvent(EVENT_PURSUE, 35*IN_MILLISECONDS);
                            break;
                        case EVENT_MISSILE:
                            DoCast(me, SPELL_MISSILE_BARRAGE, true);
                            events.ScheduleEvent(EVENT_MISSILE, 2*IN_MILLISECONDS);
                            break;
                        case EVENT_VENT:
                            DoCastAOE(SPELL_FLAME_VENTS);
                            events.ScheduleEvent(EVENT_VENT, 20*IN_MILLISECONDS);
                            break;
                        case EVENT_SPEED:
                            DoCastAOE(SPELL_GATHERING_SPEED);
                            events.ScheduleEvent(EVENT_SPEED, 15*IN_MILLISECONDS);
                            break;
                        case EVENT_SUMMON:
                            if (summons.size() < 15)
                                if (Creature* lift = DoSummonFlyer(NPC_MECHANOLIFT, me, 30.0f, 50.0f, 0))
                                    lift->GetMotionMaster()->MoveRandom(100);
                            events.ScheduleEvent(EVENT_SUMMON, 2*IN_MILLISECONDS);
                            break;
                        case EVENT_SHUTDOWN:
                            Talk(SAY_OVERLOAD);
                            Talk(EMOTE_OVERLOAD);
                            me->CastSpell(me, SPELL_SYSTEMS_SHUTDOWN, true);
                            if (Shutout)
                                Shutout = false;
                            events.ScheduleEvent(EVENT_REPAIR, 4000);
                            events.DelayEvents(20 * IN_MILLISECONDS, 0);
                            break;
                        case EVENT_REPAIR:
                            Talk(EMOTE_REPAIR);
                            me->ClearUnitState(UNIT_STATE_STUNNED | UNIT_STATE_ROOT);
                            events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                            events.CancelEvent(EVENT_REPAIR);
                            break;
                        case EVENT_THORIM_S_HAMMER: // Tower of Storms
                            for (uint8 i = 0; i < 7; ++i)
                            {
                                if (Creature* thorim = DoSummon(NPC_THORIM_BEACON, me, float(urand(20, 60)), 20000, TEMPSUMMON_TIMED_DESPAWN))
                                    thorim->GetMotionMaster()->MoveRandom(100);
                            }
                            Talk(SAY_TOWER_STORM);
                            events.CancelEvent(EVENT_THORIM_S_HAMMER);
                            break;
                        case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
                            me->SummonCreature(NPC_MIMIRON_BEACON, InfernoStart);
                            Talk(SAY_TOWER_FLAME);
                            events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
                            break;
                        case EVENT_HODIR_S_FURY:      // Tower of Frost
                            for (uint8 i = 0; i < 7; ++i)
                            {
                                if (Creature* hodir = DoSummon(NPC_HODIR_BEACON, me, 50, 0))
                                    hodir->GetMotionMaster()->MoveRandom(100);
                            }
                            Talk(SAY_TOWER_FROST);
                            events.CancelEvent(EVENT_HODIR_S_FURY);
                            break;
                        case EVENT_FREYA_S_WARD:    // Tower of Nature
                            Talk(SAY_TOWER_NATURE);
                            for (int32 i = 0; i < 4; ++i)
                                me->SummonCreature(NPC_FREYA_BEACON, FreyaBeacons[i]);

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_FREYA_S_WARD);
                            events.CancelEvent(EVENT_FREYA_S_WARD);
                            break;
                    }
                }

                DoBatteringRamIfReady();
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_PURSUED)
                    _pursueTarget = target->GetGUID();
            }

            void DoAction(int32 action)
            {
                if (action && action <= 4) // Tower destruction, debuff leviathan loot and reduce active tower count
                {
                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2 | LOOT_MODE_HARD_MODE_3 | LOOT_MODE_HARD_MODE_4) && ActiveTowersCount == 4)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_4);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2 | LOOT_MODE_HARD_MODE_3) && ActiveTowersCount == 3)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2) && ActiveTowersCount == 2)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1) && ActiveTowersCount == 1)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                        --ActiveTowersCount;
                    }
                }

                switch (action)
                {
                    case ACTION_TOWER_OF_STORM_DESTROYED:
                        towerOfStorms = false;
                        break;
                    case ACTION_TOWER_OF_FROST_DESTROYED:
                        towerOfFrost = false;
                        break;
                    case ACTION_TOWER_OF_FLAMES_DESTROYED:
                        towerOfFlames = false;
                        break;
                    case ACTION_TOWER_OF_LIFE_DESTROYED:
                        towerOfLife = false;
                        break;
                    case ACTION_START_HARD_MODE:  // Activate hard-mode enable all towers, apply buffs on leviathan
                        ActiveTowers = true;
                        towerOfStorms = true;
                        towerOfLife = true;
                        towerOfFlames = true;
                        towerOfFrost = true;
                        me->SetLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2 | LOOT_MODE_HARD_MODE_3 | LOOT_MODE_HARD_MODE_4);
                        break;
                    case ACTION_MOVE_TO_CENTER_POSITION: // Triggered by 2 Collossus near door
                        if (!me->isDead())
                        {
                            me->SetHomePosition(Center);
                            me->GetMotionMaster()->MoveCharge(Center.GetPositionX(), Center.GetPositionY(), Center.GetPositionZ()); // position center
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                            return;
                        }
                        break;
                    default:
                        break;
                }
            }

            private:
                //! Copypasta from DoSpellAttackIfReady, only difference is the target - it cannot be selected trough getVictim this way -
                //! I also removed the spellInfo check
                void DoBatteringRamIfReady()
                {
                    if (me->isAttackReady())
                    {
                        Unit* target = ObjectAccessor::GetUnit(*me, _pursueTarget);
                        if (me->IsWithinCombatRange(target, 30.0f))
                        {
                            DoCast(target, SPELL_BATTERING_RAM);
                            me->resetAttackTimer();
                        }
                    }
                }

                uint64 _pursueTarget;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_flame_leviathanAI>(creature);
        }
};

class boss_flame_leviathan_seat : public CreatureScript
{
    public:
        boss_flame_leviathan_seat() : CreatureScript("boss_flame_leviathan_seat") { }

        struct boss_flame_leviathan_seatAI : public ScriptedAI
        {
            boss_flame_leviathan_seatAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
            {
                ASSERT(vehicle);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            Vehicle* vehicle;

            void PassengerBoarded(Unit* who, int8 seatId, bool apply)
            {
                if (!me->GetVehicle())
                    return;

                if (seatId == SEAT_PLAYER)
                {
                    if (!apply)
                        return;
                    else if (Creature* leviathan = me->GetVehicleCreatureBase())
                        leviathan->AI()->Talk(SAY_PLAYER_RIDING);

                    if (Creature* turret = me->GetVehicleKit()->GetPassenger(SEAT_TURRET)->ToCreature())
                    {
                        turret->setFaction(me->GetVehicleBase()->getFaction());
                        turret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                        turret->AI()->AttackStart(who);
                    }
                    if (Creature* device = me->GetVehicleKit()->GetPassenger(SEAT_DEVICE)->ToCreature())
                    {
                        device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        device->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_seatAI(creature);
        }
};

class boss_flame_leviathan_defense_cannon : public CreatureScript
{
    public:
        boss_flame_leviathan_defense_cannon() : CreatureScript("boss_flame_leviathan_defense_cannon") { }

        struct boss_flame_leviathan_defense_cannonAI : public ScriptedAI
        {
            boss_flame_leviathan_defense_cannonAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            uint32 NapalmTimer;

            void Reset()
            {
                NapalmTimer = 5*IN_MILLISECONDS;
                DoCast(me, AURA_STEALTH_DETECTION);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (NapalmTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        if (CanAIAttack(target))
                            DoCast(target, SPELL_NAPALM, true);

                    NapalmTimer = 5000;
                }
                else
                    NapalmTimer -= diff;
            }

            bool CanAIAttack(Unit const* who) const
            {
                if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() == NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_defense_cannonAI(creature);
        }
};

class boss_flame_leviathan_defense_turret : public CreatureScript
{
    public:
        boss_flame_leviathan_defense_turret() : CreatureScript("boss_flame_leviathan_defense_turret") { }

        struct boss_flame_leviathan_defense_turretAI : public TurretAI
        {
            boss_flame_leviathan_defense_turretAI(Creature* creature) : TurretAI(creature) {}

            void DamageTaken(Unit* who, uint32 &damage)
            {
                if (!CanAIAttack(who))
                    damage = 0;
            }

            bool CanAIAttack(Unit const* who) const
            {
                if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_defense_turretAI(creature);
        }
};

class boss_flame_leviathan_overload_device : public CreatureScript
{
    public:
        boss_flame_leviathan_overload_device() : CreatureScript("boss_flame_leviathan_overload_device") { }

        struct boss_flame_leviathan_overload_deviceAI : public PassiveAI
        {
            boss_flame_leviathan_overload_deviceAI(Creature* creature) : PassiveAI(creature)
            {
            }

            void OnSpellClick(Unit* /*clicker*/, bool& result)
            {
                if (!result)
                    return;

                if (me->GetVehicle())
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    if (Unit* player = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                    {
                        me->GetVehicleBase()->CastSpell(player, SPELL_SMOKE_TRAIL, true);
                        player->GetMotionMaster()->MoveKnockbackFrom(me->GetVehicleBase()->GetPositionX(), me->GetVehicleBase()->GetPositionY(), 30, 30);
                        player->ExitVehicle();
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_overload_deviceAI(creature);
        }
};

class boss_flame_leviathan_safety_container : public CreatureScript
{
    public:
        boss_flame_leviathan_safety_container() : CreatureScript("boss_flame_leviathan_safety_container") { }

        struct boss_flame_leviathan_safety_containerAI : public PassiveAI
        {
            boss_flame_leviathan_safety_containerAI(Creature* creature) : PassiveAI(creature)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
                float x, y, z;
                me->GetPosition(x, y, z);
                z = me->GetMap()->GetHeight(me->GetPhaseMask(), x, y, z);
                me->GetMotionMaster()->MovePoint(0, x, y, z);
                me->SetPosition(x, y, z, 0);
            }

            void UpdateAI(uint32 /*diff*/)
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_safety_containerAI(creature);
        }
};

class npc_mechanolift : public CreatureScript
{
    public:
        npc_mechanolift() : CreatureScript("npc_mechanolift") { }

        struct npc_mechanoliftAI : public PassiveAI
        {
            npc_mechanoliftAI(Creature* creature) : PassiveAI(creature)
            {
                ASSERT(me->GetVehicleKit());
            }

            uint32 MoveTimer;

            void Reset()
            {
                MoveTimer = 0;
                me->GetMotionMaster()->MoveRandom(50);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->GetMotionMaster()->MoveTargetedHome();
                DoCast(SPELL_DUSTY_EXPLOSION);
                Creature* liquid = DoSummon(NPC_LIQUID, me, 0);
                if (liquid)
                {
                    liquid->CastSpell(liquid, SPELL_LIQUID_PYRITE, true);
                    liquid->CastSpell(liquid, SPELL_DUST_CLOUD_IMPACT, true);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == 1)
                    if (Creature* container = me->FindNearestCreature(NPC_CONTAINER, 5, true))
                        container->EnterVehicle(me);
            }

            void UpdateAI(uint32 diff)
            {
                if (MoveTimer <= diff)
                {
                    if (me->GetVehicleKit()->HasEmptySeat(-1))
                    {
                        Creature* container = me->FindNearestCreature(NPC_CONTAINER, 50, true);
                        if (container && !container->GetVehicle())
                            me->GetMotionMaster()->MovePoint(1, container->GetPositionX(), container->GetPositionY(), container->GetPositionZ());
                    }

                    MoveTimer = 30000; //check next 30 seconds
                }
                else
                    MoveTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_mechanoliftAI(creature);
        }
};

class npc_pool_of_tar : public CreatureScript
{
    public:
        npc_pool_of_tar() : CreatureScript("npc_pool_of_tar") { }

        struct npc_pool_of_tarAI : public ScriptedAI
        {
            npc_pool_of_tarAI(Creature* creature) : ScriptedAI(creature)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_TAR_PASSIVE, true);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                damage = 0;
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
                    me->CastSpell(me, SPELL_BLAZE, true);
            }

            void UpdateAI(uint32 /*diff*/) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_pool_of_tarAI(creature);
        }
};

class npc_colossus : public CreatureScript
{
    public:
        npc_colossus() : CreatureScript("npc_colossus") { }

        struct npc_colossusAI : public ScriptedAI
        {
            npc_colossusAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void JustDied(Unit* /*killer*/)
            {
                if (me->GetHomePosition().IsInDist(&Center, 50.f))
                    instance->SetData(DATA_COLOSSUS, instance->GetData(DATA_COLOSSUS)+1);
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_colossusAI(creature);
        }
};

class npc_thorims_hammer : public CreatureScript
{
    public:
        npc_thorims_hammer() : CreatureScript("npc_thorims_hammer") { }

        struct npc_thorims_hammerAI : public ScriptedAI
        {
            npc_thorims_hammerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, AURA_DUMMY_BLUE, true);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 10, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_THORIM_S_HAMMER, true);
                }
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_BLUE))
                    me->CastSpell(me, AURA_DUMMY_BLUE, true);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thorims_hammerAI(creature);
        }
};

class npc_mimirons_inferno : public CreatureScript
{
public:
    npc_mimirons_inferno() : CreatureScript("npc_mimirons_inferno") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mimirons_infernoAI(creature);
    }

    struct npc_mimirons_infernoAI : public npc_escortAI
    {
        npc_mimirons_infernoAI(Creature* creature) : npc_escortAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->CastSpell(me, AURA_DUMMY_YELLOW, true);
            me->SetReactState(REACT_PASSIVE);
        }

        void WaypointReached(uint32 /*waypointId*/)
        {

        }

        void Reset()
        {
            infernoTimer = 2000;
        }

        uint32 infernoTimer;

        void UpdateAI(uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                Start(false, true, 0, NULL, false, true);
            else
            {
                if (infernoTimer <= diff)
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_MIMIRON_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        trigger->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), SPELL_MIMIRON_S_INFERNO, true);
                        infernoTimer = 2000;
                    }
                }
                else
                    infernoTimer -= diff;

                if (!me->HasAura(AURA_DUMMY_YELLOW))
                    me->CastSpell(me, AURA_DUMMY_YELLOW, true);
            }
        }
    };

};

class npc_hodirs_fury : public CreatureScript
{
    public:
        npc_hodirs_fury() : CreatureScript("npc_hodirs_fury") { }

        struct npc_hodirs_furyAI : public ScriptedAI
        {
            npc_hodirs_furyAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, AURA_DUMMY_GREEN, true);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 5, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_HODIR_S_FURY, true);
                }
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->CastSpell(me, AURA_DUMMY_GREEN, true);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodirs_furyAI(creature);
        }
};

class npc_freyas_ward : public CreatureScript
{
    public:
        npc_freyas_ward() : CreatureScript("npc_freyas_ward") { }

        struct npc_freyas_wardAI : public ScriptedAI
        {
            npc_freyas_wardAI(Creature* creature) : ScriptedAI(creature)
            {
                me->CastSpell(me, AURA_DUMMY_GREEN, true);
            }

            uint32 summonTimer;

            void Reset()
            {
                summonTimer = 5000;
            }

            void UpdateAI(uint32 diff)
            {
                if (summonTimer <= diff)
                {
                    DoCast(SPELL_FREYA_S_WARD_EFFECT_1);
                    DoCast(SPELL_FREYA_S_WARD_EFFECT_2);
                    summonTimer = 20000;
                }
                else
                    summonTimer -= diff;

                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->CastSpell(me, AURA_DUMMY_GREEN, true);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_freyas_wardAI(creature);
        }
};

class npc_freya_ward_summon : public CreatureScript
{
    public:
        npc_freya_ward_summon() : CreatureScript("npc_freya_ward_summon") { }

        struct npc_freya_ward_summonAI : public ScriptedAI
        {
            npc_freya_ward_summonAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->GetMotionMaster()->MoveRandom(100);
            }

            uint32 lashTimer;

            void Reset()
            {
                lashTimer = 5000;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (lashTimer <= diff)
                {
                    DoCast(SPELL_LASH);
                    lashTimer = 20000;
                }
                else
                    lashTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_freya_ward_summonAI(creature);
        }
};

//npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems"
#define GOSSIP_ITEM_2  "Confirmed"

class npc_lorekeeper : public CreatureScript
{
    public:
        npc_lorekeeper() : CreatureScript("npc_lorekeeper") { }

        struct npc_lorekeeperAI : public ScriptedAI
        {
            npc_lorekeeperAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void DoAction(int32 action)
            {
                // Start encounter
                if (action == ACTION_SPAWN_VEHICLES)
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

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    if (player)
                    {
                        player->PrepareGossipMenu(creature);
                        instance->instance->LoadGrid(364, -16); //make sure leviathan is loaded

                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    if (player)
                        player->CLOSE_GOSSIP_MENU();

                    if (Creature* leviathan = instance->instance->GetCreature(instance->GetData64(BOSS_LEVIATHAN)))
                    {
                        leviathan->AI()->DoAction(ACTION_START_HARD_MODE);
                        creature->SetVisible(false);
                        creature->AI()->DoAction(ACTION_SPAWN_VEHICLES); // spawn the vehicles
                        if (Creature* Delorah = creature->FindNearestCreature(NPC_DELORAH, 1000, true))
                        {
                            if (Creature* Branz = creature->FindNearestCreature(NPC_BRANZ_BRONZBEARD, 1000, true))
                            {
                                Delorah->GetMotionMaster()->MovePoint(0, Branz->GetPositionX()-4, Branz->GetPositionY(), Branz->GetPositionZ());
                                /// @todo Delorah->AI()->Talk(xxxx, Branz->GetGUID()); when reached at branz
                            }
                        }
                    }
                    break;
            }

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (instance && instance->GetData(BOSS_LEVIATHAN) !=DONE && player)
            {
                player->PrepareGossipMenu(creature);

                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            }
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lorekeeperAI(creature);
        }
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

    //bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    //{
    //    player->PlayerTalkClass->ClearMenus();
    //    switch (action)
    //    {
    //        case GOSSIP_ACTION_INFO_DEF+1:
    //            if (player)
    //            {
    //                player->PrepareGossipMenu(creature);
    //
    //                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    //                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    //            }
    //            break;
    //        case GOSSIP_ACTION_INFO_DEF+2:
    //            if (player)
    //                player->CLOSE_GOSSIP_MENU();
    //            if (Creature* Lorekeeper = creature->FindNearestCreature(NPC_LOREKEEPER, 1000, true)) //lore keeper of lorgannon
    //                Lorekeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    //            break;
    //    }
    //    return true;
    //}
    //bool OnGossipHello(Player* player, Creature* creature)
    //{
    //    InstanceScript* instance = creature->GetInstanceScript();
    //    if (instance && instance->GetData(BOSS_LEVIATHAN) !=DONE)
    //    {
    //        player->PrepareGossipMenu(creature);
    //
    //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    //        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
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

        void OnDestroyed(GameObject* go, Player* /*player*/)
        {
            InstanceScript* instance = go->GetInstanceScript();
            if (!instance)
                return;

            switch (go->GetEntry())
            {
                case GO_TOWER_OF_STORMS:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_STORM_DESTROYED);
                    break;
                case GO_TOWER_OF_FLAMES:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_FLAMES_DESTROYED);
                    break;
                case GO_TOWER_OF_FROST:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_FROST_DESTROYED);
                    break;
                case GO_TOWER_OF_LIFE:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_LIFE_DESTROYED);
                    break;
            }

            Creature* trigger = go->FindNearestCreature(NPC_ULDUAR_GAUNTLET_GENERATOR, 15.0f, true);
            if (trigger)
                trigger->DisappearAndDie();
        }
};

class achievement_three_car_garage_demolisher : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_demolisher() : AchievementCriteriaScript("achievement_three_car_garage_demolisher") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_DEMOLISHER)
                    return true;
            }

            return false;
        }
};

class achievement_three_car_garage_chopper : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_chopper() : AchievementCriteriaScript("achievement_three_car_garage_chopper") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_CHOPPER)
                    return true;
            }

            return false;
        }
};

class achievement_three_car_garage_siege : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_siege() : AchievementCriteriaScript("achievement_three_car_garage_siege") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_SIEGE)
                    return true;
            }

            return false;
        }
};

class achievement_shutout : public AchievementCriteriaScript
{
    public:
        achievement_shutout() : AchievementCriteriaScript("achievement_shutout") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target)
                if (Creature* leviathan = target->ToCreature())
                    if (leviathan->AI()->GetData(DATA_SHUTOUT))
                        return true;

            return false;
        }
};

class achievement_unbroken : public AchievementCriteriaScript
{
    public:
        achievement_unbroken() : AchievementCriteriaScript("achievement_unbroken") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target)
                if (InstanceScript* instance = target->GetInstanceScript())
                    return instance->GetData(DATA_UNBROKEN);

            return false;
        }
};

class achievement_orbital_bombardment : public AchievementCriteriaScript
{
    public:
        achievement_orbital_bombardment() : AchievementCriteriaScript("achievement_orbital_bombardment") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Leviathan = target->ToCreature())
                if (Leviathan->AI()->GetData(DATA_ORBIT_ACHIEVEMENTS) >= 1)
                    return true;

            return false;
        }
};

class achievement_orbital_devastation : public AchievementCriteriaScript
{
    public:
        achievement_orbital_devastation() : AchievementCriteriaScript("achievement_orbital_devastation") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Leviathan = target->ToCreature())
                if (Leviathan->AI()->GetData(DATA_ORBIT_ACHIEVEMENTS) >= 2)
                    return true;

            return false;
        }
};

class achievement_nuked_from_orbit : public AchievementCriteriaScript
{
    public:
        achievement_nuked_from_orbit() : AchievementCriteriaScript("achievement_nuked_from_orbit") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Leviathan = target->ToCreature())
                if (Leviathan->AI()->GetData(DATA_ORBIT_ACHIEVEMENTS) >= 3)
                    return true;

            return false;
        }
};

class achievement_orbit_uary : public AchievementCriteriaScript
{
    public:
        achievement_orbit_uary() : AchievementCriteriaScript("achievement_orbit_uary") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Leviathan = target->ToCreature())
                if (Leviathan->AI()->GetData(DATA_ORBIT_ACHIEVEMENTS) == 4)
                    return true;

            return false;
        }
};

class spell_load_into_catapult : public SpellScriptLoader
{
    enum Spells
    {
        SPELL_PASSENGER_LOADED = 62340,
    };

    public:
        spell_load_into_catapult() : SpellScriptLoader("spell_load_into_catapult") { }

        class spell_load_into_catapult_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_load_into_catapult_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                owner->CastSpell(owner, SPELL_PASSENGER_LOADED, true);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                owner->RemoveAurasDueToSpell(SPELL_PASSENGER_LOADED);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_load_into_catapult_AuraScript::OnApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_load_into_catapult_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_load_into_catapult_AuraScript();
        }
};

class spell_auto_repair : public SpellScriptLoader
{
    enum Spells
    {
        SPELL_AUTO_REPAIR = 62705,
    };

    public:
        spell_auto_repair() : SpellScriptLoader("spell_auto_repair") {}

        class spell_auto_repair_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_auto_repair_SpellScript);

            void CheckCooldownForTarget()
            {
                if (GetHitUnit()->HasAuraEffect(SPELL_AUTO_REPAIR, EFFECT_2))   // Check presence of dummy aura indicating cooldown
                {
                    PreventHitEffect(EFFECT_0);
                    PreventHitDefaultEffect(EFFECT_1);
                    PreventHitDefaultEffect(EFFECT_2);
                    //! Currently this doesn't work: if we call PreventHitAura(), the existing aura will be removed
                    //! because of recent aura refreshing changes. Since removing the existing aura negates the idea
                    //! of a cooldown marker, we just let the dummy aura refresh itself without executing the other spelleffects.
                    //! The spelleffects can be executed by letting the dummy aura expire naturally.
                    //! This is a temporary solution only.
                    //PreventHitAura();
                }
            }

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Vehicle* vehicle = GetHitUnit()->GetVehicleKit();
                if (!vehicle)
                    return;

                Player* driver = vehicle->GetPassenger(0) ? vehicle->GetPassenger(0)->ToPlayer() : NULL;
                if (!driver)
                    return;

                driver->MonsterTextEmote(EMOTE_REPAIR, driver->GetGUID(), true);

                InstanceScript* instance = driver->GetInstanceScript();
                if (!instance)
                    return;

                // Actually should/could use basepoints (100) for this spell effect as percentage of health, but oh well.
                vehicle->GetBase()->SetFullHealth();

                // For achievement
                instance->SetData(DATA_UNBROKEN, 0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_auto_repair_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                BeforeHit += SpellHitFn(spell_auto_repair_SpellScript::CheckCooldownForTarget);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_auto_repair_SpellScript();
        }
};

class spell_systems_shutdown : public SpellScriptLoader
{
    public:
        spell_systems_shutdown() : SpellScriptLoader("spell_systems_shutdown") { }

        class spell_systems_shutdown_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_systems_shutdown_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Creature* owner = GetOwner()->ToCreature();
                if (!owner)
                    return;

                //! This could probably in the SPELL_EFFECT_SEND_EVENT handler too:
                owner->AddUnitState(UNIT_STATE_STUNNED | UNIT_STATE_ROOT);
                owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                owner->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Creature* owner = GetOwner()->ToCreature();
                if (!owner)
                    return;

                owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_systems_shutdown_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_systems_shutdown_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_systems_shutdown_AuraScript();
        }
};

class FlameLeviathanPursuedTargetSelector
{
    enum Area
    {
        AREA_FORMATION_GROUNDS = 4652,
    };

    public:
        explicit FlameLeviathanPursuedTargetSelector(Unit* unit) : _me(unit) {};

        bool operator()(WorldObject* target) const
        {
            //! No players, only vehicles (@todo check if blizzlike)
            Creature* creatureTarget = target->ToCreature();
            if (!creatureTarget)
                return true;

            //! NPC entries must match
            if (creatureTarget->GetEntry() != NPC_SALVAGED_DEMOLISHER && creatureTarget->GetEntry() != NPC_SALVAGED_SIEGE_ENGINE)
                return true;

            //! NPC must be a valid vehicle installation
            Vehicle* vehicle = creatureTarget->GetVehicleKit();
            if (!vehicle)
                return true;

            //! Entity needs to be in appropriate area
            if (target->GetAreaId() != AREA_FORMATION_GROUNDS)
                return true;

            //! Vehicle must be in use by player
            bool playerFound = false;
            for (SeatMap::const_iterator itr = vehicle->Seats.begin(); itr != vehicle->Seats.end() && !playerFound; ++itr)
                if (IS_PLAYER_GUID(itr->second.Passenger.Guid))
                    playerFound = true;

            return !playerFound;
        }

    private:
        Unit const* _me;
};

class spell_pursue : public SpellScriptLoader
{
    public:
        spell_pursue() : SpellScriptLoader("spell_pursue") {}

        class spell_pursue_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pursue_SpellScript);

            bool Load()
            {
                _target = NULL;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(FlameLeviathanPursuedTargetSelector(GetCaster()));
                if (targets.empty())
                {
                    if (Creature* caster = GetCaster()->ToCreature())
                        caster->AI()->EnterEvadeMode();
                }
                else
                {
                    //! In the end, only one target should be selected
                    _target = Trinity::Containers::SelectRandomContainerElement(targets);
                    FilterTargetsSubsequently(targets);
                }
            }

            void FilterTargetsSubsequently(std::list<WorldObject*>& targets)
            {
                targets.clear();
                if (_target)
                    targets.push_back(_target);
            }

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                if (!caster)
                    return;

                caster->AI()->AttackStart(GetHitUnit());    // Chase target

                for (SeatMap::const_iterator itr = caster->GetVehicleKit()->Seats.begin(); itr != caster->GetVehicleKit()->Seats.end(); ++itr)
                {
                    if (IS_PLAYER_GUID(itr->second.Passenger.Guid))
                    {
                        caster->AI()->Talk(EMOTE_PURSUE, itr->second.Passenger.Guid);
                        return;
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pursue_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pursue_SpellScript::FilterTargetsSubsequently, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_pursue_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }

            WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pursue_SpellScript();
        }
};

class spell_vehicle_throw_passenger : public SpellScriptLoader
{
    public:
        spell_vehicle_throw_passenger() : SpellScriptLoader("spell_vehicle_throw_passenger") {}

        class spell_vehicle_throw_passenger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_vehicle_throw_passenger_SpellScript);
            void HandleScript(SpellEffIndex effIndex)
            {
                Spell* baseSpell = GetSpell();
                SpellCastTargets targets = baseSpell->m_targets;
                int32 damage = GetEffectValue();
                if (targets.HasTraj())
                    if (Vehicle* vehicle = GetCaster()->GetVehicleKit())
                        if (Unit* passenger = vehicle->GetPassenger(damage - 1))
                        {
                            // use 99 because it is 3d search
                            std::list<WorldObject*> targetList;
                            Trinity::WorldObjectSpellAreaTargetCheck check(99, GetExplTargetDest(), GetCaster(), GetCaster(), GetSpellInfo(), TARGET_CHECK_DEFAULT, NULL);
                            Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(GetCaster(), targetList, check);
                            GetCaster()->GetMap()->VisitAll(GetCaster()->m_positionX, GetCaster()->m_positionY, 99, searcher);
                            float minDist = 99 * 99;
                            Unit* target = NULL;
                            for (std::list<WorldObject*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                            {
                                if (Unit* unit = (*itr)->ToUnit())
                                    if (unit->GetEntry() == NPC_SEAT)
                                        if (Vehicle* seat = unit->GetVehicleKit())
                                            if (!seat->GetPassenger(0))
                                                if (Unit* device = seat->GetPassenger(2))
                                                    if (!device->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                                                    {
                                                        float dist = unit->GetExactDistSq(targets.GetDstPos());
                                                        if (dist < minDist)
                                                        {
                                                            minDist = dist;
                                                            target = unit;
                                                        }
                                                    }
                            }
                            if (target && target->IsWithinDist2d(targets.GetDstPos(), GetSpellInfo()->Effects[effIndex].CalcRadius() * 2)) // now we use *2 because the location of the seat is not correct
                                passenger->EnterVehicle(target, 0);
                            else
                            {
                                passenger->ExitVehicle();
                                float x, y, z;
                                targets.GetDstPos()->GetPosition(x, y, z);
                                passenger->GetMotionMaster()->MoveJump(x, y, z, targets.GetSpeedXY(), targets.GetSpeedZ());
                            }
                        }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_vehicle_throw_passenger_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_vehicle_throw_passenger_SpellScript();
        }
};

void AddSC_boss_flame_leviathan()
{
    new boss_flame_leviathan();
    new boss_flame_leviathan_seat();
    new boss_flame_leviathan_defense_turret();
    new boss_flame_leviathan_defense_cannon();
    new boss_flame_leviathan_overload_device();
    new boss_flame_leviathan_safety_container();
    new npc_mechanolift();
    new npc_pool_of_tar();
    new npc_colossus();
    new npc_thorims_hammer();
    new npc_mimirons_inferno();
    new npc_hodirs_fury();
    new npc_freyas_ward();
    new npc_freya_ward_summon();
    new npc_lorekeeper();
    // new npc_brann_bronzebeard();
    new go_ulduar_tower();

    new achievement_three_car_garage_demolisher();
    new achievement_three_car_garage_chopper();
    new achievement_three_car_garage_siege();
    new achievement_shutout();
    new achievement_unbroken();
    new achievement_orbital_bombardment();
    new achievement_orbital_devastation();
    new achievement_nuked_from_orbit();
    new achievement_orbit_uary();

    new spell_load_into_catapult();
    new spell_auto_repair();
    new spell_systems_shutdown();
    new spell_pursue();
    new spell_vehicle_throw_passenger();
}
