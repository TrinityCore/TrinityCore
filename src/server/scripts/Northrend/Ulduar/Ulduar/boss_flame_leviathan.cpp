/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "CellImpl.h"
#include "CombatAI.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ulduar.h"
#include "Vehicle.h"

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

enum Misc
{
    DATA_SHUTOUT               = 29112912, // 2911, 2912 are achievement IDs
    DATA_ORBIT_ACHIEVEMENTS    = 1,
    VEHICLE_SPAWNS             = 5,
    FREYA_SPAWNS               = 4

};

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
            boss_flame_leviathanAI(Creature* creature) : BossAI(creature, DATA_FLAME_LEVIATHAN)
            {
                Initialize();
            }

            void Initialize()
            {
                ActiveTowersCount = 4;
                Shutdown = 0;
                ActiveTowers = false;
                towerOfStorms = false;
                towerOfLife = false;
                towerOfFlames = false;
                towerOfFrost = false;
                Shutout = true;
                Unbroken = true;
            }

            void InitializeAI() override
            {
                if (!me->isDead())
                    Reset();

                Initialize();

                DoCast(SPELL_INVIS_AND_STEALTH_DETECT);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_STUNNED);
                me->SetReactState(REACT_PASSIVE);
            }

            uint8 ActiveTowersCount;
            uint8 Shutdown;
            bool ActiveTowers;
            bool towerOfStorms;
            bool towerOfLife;
            bool towerOfFlames;
            bool towerOfFrost;
            bool Shutout;
            bool Unbroken;

            void Reset() override
            {
                _Reset();
                //resets shutdown counter to 0.  2 or 4 depending on raid mode
                Shutdown = 0;
                _pursueTarget.Clear();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_PURSUE, 1ms);
                events.ScheduleEvent(EVENT_MISSILE, 1500ms, 4s);
                events.ScheduleEvent(EVENT_VENT, 20s);
                events.ScheduleEvent(EVENT_SHUTDOWN, 150s);
                events.ScheduleEvent(EVENT_SPEED, 15s);
                events.ScheduleEvent(EVENT_SUMMON, 1s);
                ActiveTower(); //void ActiveTower
            }

            void ActiveTower()
            {
                if (ActiveTowers)
                {
                    if (towerOfStorms)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_STORMS, me);
                        events.ScheduleEvent(EVENT_THORIM_S_HAMMER, 35s);
                    }

                    if (towerOfFlames)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_FLAMES, me);
                        events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO, 70s);
                    }

                    if (towerOfFrost)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_FR0ST, me);
                        events.ScheduleEvent(EVENT_HODIR_S_FURY, 105s);
                    }

                    if (towerOfLife)
                    {
                        me->AddAura(SPELL_BUFF_TOWER_OF_LIFE, me);
                        events.ScheduleEvent(EVENT_FREYA_S_WARD, 140s);
                    }

                    if (!towerOfLife && !towerOfFrost && !towerOfFlames && !towerOfStorms)
                        Talk(SAY_TOWER_NONE);
                    else
                        Talk(SAY_HARDMODE);
                }
                else
                    Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_START_THE_ENGINE)
                    if (Vehicle* vehicleKit = me->GetVehicleKit())
                        vehicleKit->InstallAllAccessories(false);

                if (spellInfo->Id == SPELL_ELECTROSHOCK)
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                if (spellInfo->Id == SPELL_OVERLOAD_CIRCUIT)
                    ++Shutdown;
            }

            uint32 GetData(uint32 type) const override
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
                        break;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 data) override
            {
                if (id == DATA_UNBROKEN)
                    Unbroken = data ? true : false;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!me->IsEngaged())
                    return;

                if (!me->IsInCombat())
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }

                events.Update(diff);

                if (Shutdown == RAID_MODE(TWO_SEATS, FOUR_SEATS))
                {
                    Shutdown = 0;
                    events.ScheduleEvent(EVENT_SHUTDOWN, 4s);
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
                            events.ScheduleEvent(EVENT_PURSUE, 35s);
                            break;
                        case EVENT_MISSILE:
                            DoCast(me, SPELL_MISSILE_BARRAGE, true);
                            events.ScheduleEvent(EVENT_MISSILE, 2s);
                            break;
                        case EVENT_VENT:
                            DoCastAOE(SPELL_FLAME_VENTS);
                            events.ScheduleEvent(EVENT_VENT, 20s);
                            break;
                        case EVENT_SPEED:
                            DoCastAOE(SPELL_GATHERING_SPEED);
                            events.ScheduleEvent(EVENT_SPEED, 15s);
                            break;
                        case EVENT_SUMMON:
                            if (summons.size() < 15)
                                if (Creature* lift = DoSummonFlyer(NPC_MECHANOLIFT, me, 30.0f, 50.0f, 0s))
                                    lift->GetMotionMaster()->MoveRandom(100);
                            events.ScheduleEvent(EVENT_SUMMON, 2s);
                            break;
                        case EVENT_SHUTDOWN:
                            Talk(SAY_OVERLOAD);
                            Talk(EMOTE_OVERLOAD);
                            me->CastSpell(me, SPELL_SYSTEMS_SHUTDOWN, true);
                            if (Shutout)
                                Shutout = false;
                            events.ScheduleEvent(EVENT_REPAIR, 4s);
                            events.DelayEvents(20s, 0);
                            break;
                        case EVENT_REPAIR:
                            Talk(EMOTE_REPAIR);
                            me->ClearUnitState(UNIT_STATE_STUNNED | UNIT_STATE_ROOT);
                            events.ScheduleEvent(EVENT_SHUTDOWN, 150s);
                            events.CancelEvent(EVENT_REPAIR);
                            break;
                        case EVENT_THORIM_S_HAMMER: // Tower of Storms
                            for (uint8 i = 0; i < 7; ++i)
                            {
                                if (Creature* thorim = DoSummon(NPC_THORIM_BEACON, me, float(urand(20, 60)), 20s, TEMPSUMMON_TIMED_DESPAWN))
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
                                if (Creature* hodir = DoSummon(NPC_HODIR_BEACON, me, 50, 0s))
                                    hodir->GetMotionMaster()->MoveRandom(100);
                            }
                            Talk(SAY_TOWER_FROST);
                            events.CancelEvent(EVENT_HODIR_S_FURY);
                            break;
                        case EVENT_FREYA_S_WARD:    // Tower of Nature
                            Talk(SAY_TOWER_NATURE);
                            for (int32 i = 0; i < 4; ++i)
                                me->SummonCreature(NPC_FREYA_BEACON, FreyaBeacons[i]);

                            if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                                DoCast(target, SPELL_FREYA_S_WARD);
                            events.CancelEvent(EVENT_FREYA_S_WARD);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoBatteringRamIfReady();
            }

            void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
            {
                Unit* unitTarget = target->ToUnit();
                if (!unitTarget)
                    return;

                if (spellInfo->Id != SPELL_PURSUED)
                    return;

                _pursueTarget = unitTarget->GetGUID();
                AttackStart(unitTarget);

                for (SeatMap::const_iterator itr = unitTarget->GetVehicleKit()->Seats.begin(); itr != unitTarget->GetVehicleKit()->Seats.end(); ++itr)
                {
                    if (Player* passenger = ObjectAccessor::GetPlayer(*me, itr->second.Passenger.Guid))
                    {
                        Talk(EMOTE_PURSUE, passenger);
                        return;
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action && action <= 4) // Tower destruction, debuff leviathan loot and reduce active tower count
                {
                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2 | LOOT_MODE_HARD_MODE_3 | LOOT_MODE_HARD_MODE_4) && ActiveTowersCount == 4)
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_4);

                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2 | LOOT_MODE_HARD_MODE_3) && ActiveTowersCount == 3)
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);

                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1 | LOOT_MODE_HARD_MODE_2) && ActiveTowersCount == 2)
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);

                    if (me->HasLootMode(LOOT_MODE_DEFAULT | LOOT_MODE_HARD_MODE_1) && ActiveTowersCount == 1)
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                }

                switch (action)
                {
                    case ACTION_TOWER_OF_STORM_DESTROYED:
                        if (towerOfStorms)
                        {
                            towerOfStorms = false;
                            --ActiveTowersCount;
                        }
                        break;
                    case ACTION_TOWER_OF_FROST_DESTROYED:
                        if (towerOfFrost)
                        {
                            towerOfFrost = false;
                            --ActiveTowersCount;
                        }
                        break;
                    case ACTION_TOWER_OF_FLAMES_DESTROYED:
                        if (towerOfFlames)
                        {
                            towerOfFlames = false;
                            --ActiveTowersCount;
                        }
                        break;
                    case ACTION_TOWER_OF_LIFE_DESTROYED:
                        if (towerOfLife)
                        {
                            towerOfLife = false;
                            --ActiveTowersCount;
                        }
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
                        if (!me->isDead() && me->HasReactState(REACT_PASSIVE))
                        {
                            me->SetHomePosition(Center);
                            me->GetMotionMaster()->MoveCharge(Center.GetPositionX(), Center.GetPositionY(), Center.GetPositionZ(), 42.0f, ACTION_MOVE_TO_CENTER_POSITION); // position center
                        }
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id != ACTION_MOVE_TO_CENTER_POSITION)
                    return;
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_STUNNED);
            }

            private:
                //! Copypasta from DoSpellAttackIfReady, only difference is the target - it cannot be selected trough getVictim this way -
                //! I also removed the spellInfo check
                void DoBatteringRamIfReady()
                {
                    if (me->isAttackReady())
                    {
                        Unit* target = ObjectAccessor::GetUnit(*me, _pursueTarget);

                        if (!target)
                        {
                            events.RescheduleEvent(EVENT_PURSUE, 0s);
                            return;
                        }

                        if (me->IsWithinCombatRange(target, 30.0f))
                        {
                            DoCast(target, SPELL_BATTERING_RAM);
                            me->resetAttackTimer();
                        }
                    }
                }

                ObjectGuid _pursueTarget;
        };

        CreatureAI* GetAI(Creature* creature) const override
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
            boss_flame_leviathan_seatAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
            {
                if (!me->GetVehicle())
                    return;

                if (seatId == SEAT_PLAYER)
                {
                    if (!apply)
                        return;
                    else if (Creature* leviathan = me->GetVehicleCreatureBase())
                        leviathan->AI()->Talk(SAY_PLAYER_RIDING);

                    if (Unit* turretPassenger = me->GetVehicleKit()->GetPassenger(SEAT_TURRET))
                        if (Creature* turret = turretPassenger->ToCreature())
                        {
                            turret->SetFaction(me->GetVehicleBase()->GetFaction());
                            turret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // uninteractible
                            turret->AI()->AttackStart(who);
                        }
                    if (Unit* devicePassenger = me->GetVehicleKit()->GetPassenger(SEAT_DEVICE))
                        if (Creature* device = devicePassenger->ToCreature())
                        {
                            device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                            device->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                        }

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                }
                else if (seatId == SEAT_TURRET)
                {
                    if (apply)
                        return;

                    if (Unit* device = ASSERT_NOTNULL(me->GetVehicleKit())->GetPassenger(SEAT_DEVICE))
                    {
                        device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        device->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // uninteractible
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_flame_leviathan_seatAI>(creature);
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
                Initialize();
            }

            void Initialize()
            {
                NapalmTimer = 5 * IN_MILLISECONDS;
            }

            uint32 NapalmTimer;

            void Reset() override
            {
                Initialize();
                DoCast(me, AURA_STEALTH_DETECTION);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (NapalmTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        if (CanAIAttack(target))
                            DoCast(target, SPELL_NAPALM, true);

                    NapalmTimer = 5000;
                }
                else
                    NapalmTimer -= diff;
            }

            bool CanAIAttack(Unit const* who) const override
            {
                if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() == NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_flame_leviathan_defense_cannonAI>(creature);
        }
};

class boss_flame_leviathan_defense_turret : public CreatureScript
{
    public:
        boss_flame_leviathan_defense_turret() : CreatureScript("boss_flame_leviathan_defense_turret") { }

        struct boss_flame_leviathan_defense_turretAI : public TurretAI
        {
            boss_flame_leviathan_defense_turretAI(Creature* creature) : TurretAI(creature) { }

            void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (!CanAIAttack(who))
                    damage = 0;
            }

            bool CanAIAttack(Unit const* who) const override
            {
                if (!who || who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_flame_leviathan_defense_turretAI>(creature);
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

            void OnSpellClick(Unit* /*clicker*/, bool spellClickHandled) override
            {
                if (!spellClickHandled)
                    return;

                if (me->GetVehicle())
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);

                    if (Unit* player = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                    {
                        me->GetVehicleBase()->CastSpell(player, SPELL_SMOKE_TRAIL, true);
                        player->GetMotionMaster()->MoveKnockbackFrom(me->GetVehicleBase()->GetPositionX(), me->GetVehicleBase()->GetPositionY(), 30, 30);
                        player->ExitVehicle();
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_flame_leviathan_overload_deviceAI>(creature);
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

            void JustDied(Unit* /*killer*/) override
            {
                float x, y, z;
                me->GetPosition(x, y, z);
                z = me->GetMap()->GetHeight(me->GetPhaseMask(), x, y, z);
                me->GetMotionMaster()->MovePoint(0, x, y, z);
                me->UpdatePosition(x, y, z, 0);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_flame_leviathan_safety_containerAI>(creature);
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
                Initialize();
                ASSERT(me->GetVehicleKit());
            }

            void Initialize()
            {
                MoveTimer = 0;
            }

            uint32 MoveTimer;

            void Reset() override
            {
                Initialize();
                me->GetMotionMaster()->MoveRandom(50);
            }

            void JustDied(Unit* /*killer*/) override
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

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == 1)
                    if (Creature* container = me->FindNearestCreature(NPC_CONTAINER, 5, true))
                        container->EnterVehicle(me);
            }

            void UpdateAI(uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mechanoliftAI>(creature);
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
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_TAR_PASSIVE, true);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                damage = 0;
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
                    me->CastSpell(me, SPELL_BLAZE, true);
            }

            void UpdateAI(uint32 /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_pool_of_tarAI>(creature);
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

            void JustDied(Unit* /*killer*/) override
            {
                if (me->GetHomePosition().IsInDist(&Center, 50.f))
                    instance->SetData(DATA_COLOSSUS, instance->GetData(DATA_COLOSSUS)+1);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_colossusAI>(creature);
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
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                me->CastSpell(me, AURA_DUMMY_BLUE, true);
            }

            void MoveInLineOfSight(Unit* who) override

            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 10, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 20, 0, 1s, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_THORIM_S_HAMMER, true);
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!me->HasAura(AURA_DUMMY_BLUE))
                    me->CastSpell(me, AURA_DUMMY_BLUE, true);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_thorims_hammerAI>(creature);
        }
};

class npc_mimirons_inferno : public CreatureScript
{
public:
    npc_mimirons_inferno() : CreatureScript("npc_mimirons_inferno") { }

    struct npc_mimirons_infernoAI : public EscortAI
    {
        npc_mimirons_infernoAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
            me->CastSpell(me, AURA_DUMMY_YELLOW, true);
            me->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            infernoTimer = 2000;
        }

        void Reset() override
        {
            Initialize();
        }

        uint32 infernoTimer;

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                Start(false, true, ObjectGuid::Empty, nullptr, false, true);
            else
            {
                if (infernoTimer <= diff)
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_MIMIRON_TARGET_BEACON, me, 20, 0, 1s, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        trigger->CastSpell(me->GetPosition(), SPELL_MIMIRON_S_INFERNO, true);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUlduarAI<npc_mimirons_infernoAI>(creature);
    }
};

class npc_hodirs_fury : public CreatureScript
{
    public:
        npc_hodirs_fury() : CreatureScript("npc_hodirs_fury") { }

        struct npc_hodirs_furyAI : public ScriptedAI
        {
            npc_hodirs_furyAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                me->CastSpell(me, AURA_DUMMY_GREEN, true);
            }

            void MoveInLineOfSight(Unit* who) override

            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 5, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 20, 0, 1s, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_HODIR_S_FURY, true);
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->CastSpell(me, AURA_DUMMY_GREEN, true);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_hodirs_furyAI>(creature);
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
                Initialize();
                me->CastSpell(me, AURA_DUMMY_GREEN, true);
            }

            void Initialize()
            {
                summonTimer = 5000;
            }

            uint32 summonTimer;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_freyas_wardAI>(creature);
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
                Initialize();
                creature->GetMotionMaster()->MoveRandom(100);
            }

            void Initialize()
            {
                lashTimer = 5000;
            }

            uint32 lashTimer;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_freya_ward_summonAI>(creature);
        }
};

enum BrannBronzebeardGossips
{
    GOSSIP_MENU_BRANN_BRONZEBEARD   = 10355,
    GOSSIP_OPTION_BRANN_BRONZEBEARD = 0
};

class npc_brann_bronzebeard_ulduar_intro : public CreatureScript
{
    public:
        npc_brann_bronzebeard_ulduar_intro() : CreatureScript("npc_brann_bronzebeard_ulduar_intro") { }

        struct npc_brann_bronzebeard_ulduar_introAI : public ScriptedAI
        {
            npc_brann_bronzebeard_ulduar_introAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                if (menuId == GOSSIP_MENU_BRANN_BRONZEBEARD && gossipListId == GOSSIP_OPTION_BRANN_BRONZEBEARD)
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->PlayerTalkClass->SendCloseGossip();
                    if (Creature* loreKeeper = _instance->GetCreature(DATA_LORE_KEEPER_OF_NORGANNON))
                        loreKeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                }
                return false;
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_brann_bronzebeard_ulduar_introAI>(creature);
        }
};

enum LoreKeeperGossips
{
    GOSSIP_MENU_LORE_KEEPER   = 10477,
    GOSSIP_OPTION_LORE_KEEPER = 0
};

class npc_lorekeeper : public CreatureScript
{
    public:
        npc_lorekeeper() : CreatureScript("npc_lorekeeper") { }

        struct npc_lorekeeperAI : public ScriptedAI
        {
            npc_lorekeeperAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void DoAction(int32 action) override
            {
                // Start encounter
                if (action == ACTION_SPAWN_VEHICLES)
                {
                    for (uint8 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_SIEGE, PosSiege[i], 3s, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    for (uint8 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_CHOPPER, PosChopper[i], 3s, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    for (uint8 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_DEMOLISHER, PosDemolisher[i], 3s, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                }
            }

            bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                if (menuId == GOSSIP_MENU_LORE_KEEPER && gossipListId == GOSSIP_OPTION_LORE_KEEPER)
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->PlayerTalkClass->SendCloseGossip();
                    _instance->instance->LoadGrid(364, -16); // make sure leviathan is loaded

                    if (Creature* leviathan = _instance->GetCreature(DATA_FLAME_LEVIATHAN))
                    {
                        leviathan->AI()->DoAction(ACTION_START_HARD_MODE);
                        me->SetVisible(false);
                        DoAction(ACTION_SPAWN_VEHICLES); // spawn the vehicles
                        if (Creature* delorah = _instance->GetCreature(DATA_DELLORAH))
                        {
                            if (Creature* brann = _instance->GetCreature(DATA_BRANN_BRONZEBEARD_INTRO))
                            {
                                brann->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                delorah->GetMotionMaster()->MovePoint(0, brann->GetPositionX() - 4, brann->GetPositionY(), brann->GetPositionZ());
                                /// @todo delorah->AI()->Talk(xxxx, brann->GetGUID()); when reached at branz
                            }
                        }
                    }
                }
                return false;
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_lorekeeperAI>(creature);
        }
};

class go_ulduar_tower : public GameObjectScript
{
    public:
        go_ulduar_tower() : GameObjectScript("go_ulduar_tower") { }

        struct go_ulduar_towerAI : public GameObjectAI
        {
            go_ulduar_towerAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            void Destroyed(WorldObject* /*attacker*/, uint32 /*eventId*/) override
            {
                switch (me->GetEntry())
                {
                    case GO_TOWER_OF_STORMS:
                        instance->ProcessEvent(me, EVENT_TOWER_OF_STORM_DESTROYED);
                        break;
                    case GO_TOWER_OF_FLAMES:
                        instance->ProcessEvent(me, EVENT_TOWER_OF_FLAMES_DESTROYED);
                        break;
                    case GO_TOWER_OF_FROST:
                        instance->ProcessEvent(me, EVENT_TOWER_OF_FROST_DESTROYED);
                        break;
                    case GO_TOWER_OF_LIFE:
                        instance->ProcessEvent(me, EVENT_TOWER_OF_LIFE_DESTROYED);
                        break;
                }

                if (Creature* trigger = me->FindNearestCreature(NPC_ULDUAR_GAUNTLET_GENERATOR, 15.0f, true))
                    trigger->DisappearAndDie();
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetUlduarAI<go_ulduar_towerAI>(go);
        }
};

class achievement_three_car_garage_demolisher : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_demolisher() : AchievementCriteriaScript("achievement_three_car_garage_demolisher") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
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

        bool OnCheck(Player* source, Unit* /*target*/) override
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

        bool OnCheck(Player* source, Unit* /*target*/) override
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

        bool OnCheck(Player* /*source*/, Unit* target) override
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

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target)
                if (InstanceScript* instance = target->GetInstanceScript())
                    return instance->GetData(DATA_UNBROKEN) != 0;

            return false;
        }
};

class achievement_orbital_bombardment : public AchievementCriteriaScript
{
    public:
        achievement_orbital_bombardment() : AchievementCriteriaScript("achievement_orbital_bombardment") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
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

        bool OnCheck(Player* /*source*/, Unit* target) override
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

        bool OnCheck(Player* /*source*/, Unit* target) override
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

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Leviathan = target->ToCreature())
                if (Leviathan->AI()->GetData(DATA_ORBIT_ACHIEVEMENTS) == 4)
                    return true;

            return false;
        }
};

// 62399 - Overload Circuit
class spell_overload_circuit : public AuraScript
{
    PrepareAuraScript(spell_overload_circuit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYSTEMS_SHUTDOWN });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (!GetTarget()->GetMap()->IsDungeon() || int32(GetTarget()->GetAppliedAuras().count(GetId())) < (GetTarget()->GetMap()->Is25ManRaid() ? 4 : 2))
            return;

        GetTarget()->CastSpell(nullptr, SPELL_SYSTEMS_SHUTDOWN, true);
        if (Unit* veh = GetTarget()->GetVehicleBase())
            veh->CastSpell(nullptr, SPELL_SYSTEMS_SHUTDOWN, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_overload_circuit::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 62292 - Blaze
class spell_tar_blaze : public AuraScript
{
    PrepareAuraScript(spell_tar_blaze);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        // should we use custom damage?
        GetTarget()->CastSpell(nullptr, aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tar_blaze::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 64414 - Load into Catapult
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

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_load_into_catapult_AuraScript::OnApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_load_into_catapult_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_load_into_catapult_AuraScript();
        }
};

// 62705 - Auto-repair
class spell_auto_repair : public SpellScriptLoader
{
    enum Spells
    {
        SPELL_AUTO_REPAIR = 62705,
    };

    public:
        spell_auto_repair() : SpellScriptLoader("spell_auto_repair") { }

        class spell_auto_repair_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_auto_repair_SpellScript);

            void CheckCooldownForTarget(SpellMissInfo missInfo)
            {
                if (missInfo != SPELL_MISS_NONE)
                    return;

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

                Unit* driver = vehicle->GetPassenger(0);
                if (!driver)
                    return;

                driver->TextEmote(EMOTE_REPAIR, driver, true);

                InstanceScript* instance = driver->GetInstanceScript();
                if (!instance)
                    return;

                // Actually should/could use basepoints (100) for this spell effect as percentage of health, but oh well.
                vehicle->GetBase()->SetFullHealth();

                // For achievement
                instance->SetData(DATA_UNBROKEN, 0);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_auto_repair_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                BeforeHit += BeforeSpellHitFn(spell_auto_repair_SpellScript::CheckCooldownForTarget);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_auto_repair_SpellScript();
        }
};

// 62475 - Systems Shutdown
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

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_systems_shutdown_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_systems_shutdown_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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
        explicit FlameLeviathanPursuedTargetSelector() { };

        bool operator()(WorldObject* target) const
        {
            //! No players, only vehicles. Pursue is never cast on players.
            Creature* creatureTarget = target->ToCreature();
            if (!creatureTarget)
                return false;

            //! NPC entries must match
            if (creatureTarget->GetEntry() != NPC_SALVAGED_DEMOLISHER && creatureTarget->GetEntry() != NPC_SALVAGED_SIEGE_ENGINE)
                return false;

            //! NPC must be a valid vehicle installation
            Vehicle* vehicle = creatureTarget->GetVehicleKit();
            if (!vehicle)
                return false;

            //! Entity needs to be in appropriate area
            if (target->GetAreaId() != AREA_FORMATION_GROUNDS)
                return false;

            //! Vehicle must be in use by player
            for (SeatMap::const_iterator itr = vehicle->Seats.begin(); itr != vehicle->Seats.end(); ++itr)
                if (itr->second.Passenger.Guid.IsPlayer())
                    return true;

            return false;
        }
};

// 62374 - Pursued
class spell_pursue : public SpellScriptLoader
{
    public:
        spell_pursue() : SpellScriptLoader("spell_pursue") { }

        class spell_pursue_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pursue_SpellScript);

        private:
            // EFFECT #0 - select target
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, FlameLeviathanPursuedTargetSelector(), 1);
                if (targets.empty())
                {
                    if (Unit* caster = GetCaster())
                        if (Creature* cCaster = caster->ToCreature())
                            cCaster->AI()->EnterEvadeMode(CreatureAI::EVADE_REASON_NO_HOSTILES);
                }
                else
                    _target = targets.front();
            }

            // EFFECT #1 - copy target from effect #0
            void FilterTargetsSubsequently(std::list<WorldObject*>& targets)
            {
                targets.clear();
                if (_target)
                    targets.push_back(_target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pursue_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pursue_SpellScript::FilterTargetsSubsequently, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            WorldObject* _target = nullptr;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pursue_SpellScript();
        }
};

// 62324 - Throw Passenger
class spell_vehicle_throw_passenger : public SpellScriptLoader
{
    public:
        spell_vehicle_throw_passenger() : SpellScriptLoader("spell_vehicle_throw_passenger") { }

        class spell_vehicle_throw_passenger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_vehicle_throw_passenger_SpellScript);
            void HandleScript(SpellEffIndex /*effIndex*/)
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
                            Trinity::WorldObjectSpellAreaTargetCheck check(99, GetExplTargetDest(), GetCaster(), GetCaster(), GetSpellInfo(), TARGET_CHECK_DEFAULT, nullptr);
                            Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(GetCaster(), targetList, check);
                            Cell::VisitAllObjects(GetCaster(), searcher, 99.0f);
                            float minDist = 99 * 99;
                            Unit* target = nullptr;
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
                            if (target && target->IsWithinDist2d(targets.GetDstPos(), GetEffectInfo().CalcRadius() * 2)) // now we use *2 because the location of the seat is not correct
                                passenger->EnterVehicle(target, 0);
                            else
                            {
                                passenger->ExitVehicle();
                                passenger->GetMotionMaster()->MoveJump(*targets.GetDstPos(), targets.GetSpeedXY(), targets.GetSpeedZ());
                            }
                        }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_vehicle_throw_passenger_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
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
    new npc_brann_bronzebeard_ulduar_intro();
    new npc_lorekeeper();
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

    RegisterSpellScript(spell_overload_circuit);
    RegisterSpellScript(spell_tar_blaze);
    new spell_load_into_catapult();
    new spell_auto_repair();
    new spell_systems_shutdown();
    new spell_pursue();
    new spell_vehicle_throw_passenger();
}
