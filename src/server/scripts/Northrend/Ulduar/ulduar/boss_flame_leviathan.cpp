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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ScriptedEscortAI.h"
#include "ObjectMgr.h"
#include "ulduar.h"


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
    SPELL_DUSTY_EXPLOSION                       = 63360,
    SPELL_DUST_CLOUD_IMPACT                     = 54740,
    AURA_STEALTH_DETECTION                      = 18950,
    SPELL_RIDE_VEHICLE                          = 46598,
    SPELL_ANTI_AIR_ROCKET_DMG                   = 62363,
    SPELL_GROUND_SLAM                           = 62625
};

enum Creatures
{
    NPC_SEAT                                    = 33114,
    NPC_MECHANOLIFT                             = 33214,
    NPC_LIQUID                                  = 33189,
    NPC_CONTAINER                               = 33218,
    NPC_THORIM_BEACON                           = 33365,
    NPC_MIMIRON_BEACON                          = 33370,
    NPC_HODIR_BEACON                            = 33212,
    NPC_FREYA_BEACON                            = 33367,
    NPC_THORIM_TARGET_BEACON                    = 33364,
    NPC_MIMIRON_TARGET_BEACON                   = 33369,
    NPC_HODIR_TARGET_BEACON                     = 33108,
    NPC_FREYA_TARGET_BEACON                     = 33366,
    NPC_LOREKEEPER                              = 33686, // Hard mode starter
    NPC_BRANZ_BRONZBEARD                        = 33579,
    NPC_DELORAH                                 = 33701,
    NPC_ULDUAR_GAUNTLET_GENERATOR               = 33571, // Trigger tied to towers
};

enum Towers
{
    GO_TOWER_OF_STORMS  = 194377,
    GO_TOWER_OF_FLAMES  = 194371,
    GO_TOWER_OF_FROST   = 194370,
    GO_TOWER_OF_LIFE    = 194375,
};

enum Events
{
    EVENT_PURSUE            = 1,
    EVENT_MISSILE           = 2,
    EVENT_VENT              = 3,
    EVENT_SPEED             = 4,
    EVENT_SHUTDOWN          = 5,
    EVENT_REPAIR            = 6,
    EVENT_THORIM_S_HAMMER   = 7,    // Tower of Storms
    EVENT_MIMIRON_S_INFERNO = 8,    // Tower of Flames
    EVENT_HODIR_S_FURY      = 9,    // Tower of Frost
    EVENT_FREYA_S_WARD      = 10,   // Tower of Nature
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
#define DATA_SHUTOUT          29112912 // 2911, 2912 are achievement IDs
#define DATA_UNBROKEN         29052906 // 2905, 2906 are achievement IDs

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

enum actions
{
    ACTION_TOWER_OF_STORM_DESTROYED             = 1,
    ACTION_TOWER_OF_FROST_DESTROYED             = 2,
    ACTION_TOWER_OF_FLAMES_DESTROYED            = 3,
    ACTION_TOWER_OF_LIFE_DESTROYED              = 4,
};

Position const Center[]=
{
    {354.8771f, -12.90240f, 409.803650f, 0.0f},
};

Position const PosSiege[5] =
{
    {-814.59f, -64.54f, 429.92f, 5.969f},
    {-784.37f, -33.31f, 429.92f, 5.096f},
    {-808.99f, -52.10f, 429.92f, 5.668f},
    {-798.59f, -44.00f, 429.92f, 5.663f},
    {-812.83f, -77.71f, 429.92f, 0.046f},
};

Position const PosChopper[5] =
{
    {-717.83f, -106.56f, 430.02f, 0.122f},
    {-717.83f, -114.23f, 430.44f, 0.122f},
    {-717.83f, -109.70f, 430.22f, 0.122f},
    {-718.45f, -118.24f, 430.26f, 0.052f},
    {-718.45f, -123.58f, 430.41f, 0.085f},
};

Position const PosDemolisher[5] =
{
    {-724.12f, -176.64f, 430.03f, 2.543f},
    {-766.70f, -225.03f, 430.50f, 1.710f},
    {-729.54f, -186.26f, 430.12f, 1.902f},
    {-756.01f, -219.23f, 430.50f, 2.369f},
    {-798.01f, -227.24f, 429.84f, 1.446f},
};


#define DATA_ORBIT_ACHIEVEMENTS         1

class boss_flame_leviathan : public CreatureScript
{
    public:
        boss_flame_leviathan() : CreatureScript("boss_flame_leviathan") { }

        struct boss_flame_leviathanAI : public BossAI
        {
            boss_flame_leviathanAI(Creature* creature) : BossAI(creature, TYPE_LEVIATHAN), vehicle(creature->GetVehicleKit())
            {
                // temporary disable vehicle hp scaling effect, nyi
                //SpellEntry* tempSpell;
                //tempSpell = GET_SPELL(65266);
                //if (tempSpell)
                //    tempSpell->Effect[2] = 0;
            }

            void InitializeAI()
            {
                ASSERT(vehicle);
                if (!me->isDead())
                    Reset();
                ActiveTowersCount = 4;
                Shutdown = 0;
                ShutdownActive = false;
                ActiveTowers = false;
                towerOfStorms = false;
                towerOfLife = false;
                towerOfFlames = false;
                towerOfFrost = false;
                Shutout = true;
                Unbroken = true;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                me->SetReactState(REACT_PASSIVE);

                if (instance->GetData(TYPE_COLOSSUS) == 2)
                {
                    DoAction(10);
                    if (GameObject* Gate = me->FindNearestGameObject(GO_LEVIATHAN_GATE, 50.0f))
                        Gate->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                }
            }

            Vehicle* vehicle;
            uint8 ActiveTowersCount;
            uint8 Shutdown;
            bool ShutdownActive;
            bool ActiveTowers;
            bool towerOfStorms;
            bool towerOfLife;
            bool towerOfFlames;
            bool towerOfFrost;
            bool Shutout;
            bool Unbroken;
            bool Pursued;

            void Reset()
            {
                _Reset();
                Shutdown = 0;
                Pursued = false;
                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_PURSUE, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MISSILE, urand(1500, 4*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_VENT, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPEED, 15*IN_MILLISECONDS);
                ActiveTower();
                vehicle->InstallAllAccessories(false);
            }

            void EnterEvadeMode()
            {
                me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                _EnterEvadeMode();
                me->GetMotionMaster()->MoveTargetedHome();
                Reset();
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
                        DoScriptText(SAY_TOWER_NONE, me);
                    else
                        DoScriptText(SAY_HARDMODE, me);
                }
                else
                    DoScriptText(SAY_AGGRO, me);
            }

            void JustDied(Unit* /*victim*/)
            {
                _JustDied();
                DoScriptText(SAY_DEATH, me);

                // DEBUG
                bool isAllowed = me->IsDamageEnoughForLootingAndReward();
                char fText[128];
                sprintf(fText, "DEBUG >> %u LootRecipient: %s", isAllowed, me->GetLootRecipient() ? me->GetLootRecipient()->GetName() : "not found");
                me->MonsterYell(fText, LANG_UNIVERSAL, 0);
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_PURSUED)
                {
                    DoResetThreat();
                    me->AddThreat(target, 9999999.0f);
                    if (Player* player = target->GetCharmerOrOwnerPlayerOrPlayerItself())
                        me->MonsterTextEmote(EMOTE_PURSUE, player->GetGUID(), true);
                }
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_START_THE_ENGINE)
                    vehicle->InstallAllAccessories(false);

                if (spell->Id == SPELL_ELECTROSHOCK)
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                if (spell->Id == SPELL_OVERLOAD_CIRCUIT)
                    ++Shutdown;
            }

            uint32 GetData(uint32 type)
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

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);
                _DoAggroPulse(diff);

                if (Shutdown == RAID_MODE(2, 4))
                {
                    Shutdown = 0;
                    events.ScheduleEvent(EVENT_SHUTDOWN, 4000);
                    me->RemoveAurasDueToSpell(SPELL_OVERLOAD_CIRCUIT);
                    me->InterruptNonMeleeSpells(true);
                    return;
                }

                if (ShutdownActive)
                {
                    if (!me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
                    {
                        ShutdownActive = false;
                        me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                    }
                }

                if (me->HasUnitState(UNIT_STAT_CASTING) || me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
                    return;

                if (!Pursued && me->getVictim() && !me->getVictim()->HasAura(SPELL_PURSUED))
                {
                    Pursued = true;
                    events.RescheduleEvent(EVENT_PURSUE, 1000);
                }

                uint32 eventId = events.GetEvent();

                switch (eventId)
                {
                    case EVENT_PURSUE:
                        DoScriptText(RAND(SAY_TARGET_1, SAY_TARGET_2, SAY_TARGET_3), me);
                        DoCast(SPELL_PURSUED);
                        Pursued = false;
                        events.RepeatEvent(30*IN_MILLISECONDS);
                        break;
                    case EVENT_MISSILE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_MISSILE_BARRAGE);
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
                    case EVENT_SHUTDOWN:
                        DoScriptText(RAND(SAY_OVERLOAD_1, SAY_OVERLOAD_2, SAY_OVERLOAD_3), me);
                        me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                        me->AddAura(SPELL_SYSTEMS_SHUTDOWN, me);
                        me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);

                        ShutdownActive = true;
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();
                        me->AddUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        if (Shutout)
                            Shutout = false;

                        events.ScheduleEvent(EVENT_REPAIR, 4000);
                        events.CancelEvent(EVENT_SHUTDOWN);
                        break;
                    case EVENT_REPAIR:
                        me->MonsterTextEmote(EMOTE_REPAIR, 0, true);
                        events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                        events.CancelEvent(EVENT_REPAIR);
                        break;
                    case EVENT_THORIM_S_HAMMER: // Tower of Storms
                        for (uint8 i = 0; i < 7; ++i)
                        {
                            if (Creature* thorim = DoSummon(NPC_THORIM_BEACON, me, float(urand(20, 60)), 20000, TEMPSUMMON_TIMED_DESPAWN))
                                thorim->GetMotionMaster()->MoveRandom(100);
                        }
                        DoScriptText(SAY_TOWER_STORM, me);
                        events.CancelEvent(EVENT_THORIM_S_HAMMER);
                        break;
                    case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
                        me->SummonCreature(NPC_MIMIRON_BEACON, 390.93f, -13.91f, 409.81f);
                        DoScriptText(SAY_TOWER_FLAME, me);
                        events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
                        break;
                    case EVENT_HODIR_S_FURY:      // Tower of Frost
                        for (uint8 i = 0; i < 7; ++i)
                        {
                            if (Creature* hodir = DoSummon(NPC_HODIR_BEACON, me, 50, 0))
                                hodir->GetMotionMaster()->MoveRandom(100);
                        }
                        DoScriptText(SAY_TOWER_FROST, me);
                        events.CancelEvent(EVENT_HODIR_S_FURY);
                        break;
                    case EVENT_FREYA_S_WARD:    // Tower of Nature
                        DoScriptText(SAY_TOWER_NATURE, me);
                        StartFreyaEvent();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FREYA_S_WARD);
                        events.CancelEvent(EVENT_FREYA_S_WARD);
                        break;
                }

                if (me->IsWithinMeleeRange(me->getVictim())) // bugged spell casts on units that are boarded on leviathan
                    DoSpellAttackIfReady(SPELL_BATTERING_RAM);
                DoMeleeAttackIfReady();

                EnterEvadeIfOutOfCombatArea(diff);
            }

            void StartFreyaEvent() // summon these 4 on each corner wich wil spawn additional hostile mobs
            {
                me->SummonCreature(NPC_FREYA_BEACON, 377.02f, -119.10f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 377.02f, 54.78f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 185.62f, 54.78f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 185.62f, -119.10f, 409.81f);
            }

            void DoAction(int32 const action)
            {
                // Start encounter
                if (action == 10)
                {
                    if (!me->isDead())
                    {
                        me->SetHomePosition(Center->GetPositionX(), Center->GetPositionY(), Center->GetPositionZ(), 0);
                        me->GetMotionMaster()->MoveCharge(Center->GetPositionX(), Center->GetPositionY(), Center->GetPositionZ()); // position center
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                        return;
                    }
                }

                /*
                if (action && action <= 4) // Tower destruction, debuff leviathan loot and reduce active tower
                {
                    if (me->HasLootMode(31) && ActiveTowersCount == 4)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_4);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(15) && ActiveTowersCount == 3)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(7) && ActiveTowersCount == 2)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(3) && ActiveTowersCount == 1)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                        --ActiveTowersCount;
                    }
                }

                switch (action)
                {
                    case 0: // Activate hard-mode setting counter to 4 towers, enable all towers apply buffs on levithian
                        ActiveTowers = true;
                        towerOfStorms = true;
                        towerOfLife = true;
                        towerOfFlames = true;
                        towerOfFrost = true;
                        me->SetLootMode(31);
                        break;
                    case ACTION_TOWER_OF_STORM_DESTROYED:  // Tower of Storms destroyed
                        towerOfStorms = false;
                        break;
                    case ACTION_TOWER_OF_FROST_DESTROYED: // Tower of Frost destroyed
                        towerOfFrost = false;
                        break;
                    case ACTION_TOWER_OF_FLAMES_DESTROYED: // Tower of Flames destroyed
                        towerOfFlames = false;
                        break;
                    case ACTION_TOWER_OF_LIFE_DESTROYED: // Tower of Nature destroyed
                        towerOfLife = false;
                        break;
                    default:
                        break;
                }
                */
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathanAI(creature);
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
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
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
                    else
                        DoScriptText(SAY_PLAYER_RIDING, me);

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

            void Reset ()
            {
                NapalmTimer = 5000;
                DoCast(me, AURA_STEALTH_DETECTION);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (NapalmTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        if(CanAIAttack(target))
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

            void DoAction(const int32 param)
            {
                if (param == EVENT_SPELLCLICK)
                {
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
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_overload_deviceAI(creature);
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
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            }

            void DamageTaken(Unit* /*who*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    Creature* liquid = DoSummon(NPC_LIQUID, me, 0, 190000, TEMPSUMMON_TIMED_DESPAWN);
                    if (liquid)
                    {
                        float x, y, z;
                        me->GetPosition(x, y, z);
                        z = me->GetMap()->GetHeight(x, y, MAX_HEIGHT);
                        liquid->GetMotionMaster()->MovePoint(0, x, y, z);
                    }

                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_mechanoliftAI(creature);
        }
};

class npc_liquid_pyrite : public CreatureScript
{
    public:
        npc_liquid_pyrite() : CreatureScript("npc_liquid_pyrite") { }

        struct npc_liquid_pyriteAI : public PassiveAI
        {
            npc_liquid_pyriteAI(Creature* creature) : PassiveAI(creature) { }

            uint32 DespawnTimer;

            void Reset()
            {
                DoCast(me, SPELL_LIQUID_PYRITE, true);
                me->SetDisplayId(28476);
                DespawnTimer = 7000;
            }

            void MovementInform(uint32 type, uint32 /*id*/)
            {
                if (type == POINT_MOTION_TYPE)
                {
                    DoCast(me, SPELL_DUSTY_EXPLOSION, true);
                    DoCast(me, SPELL_DUST_CLOUD_IMPACT, true);
                    me->SetDisplayId(28783);
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                damage = 0;
            }

            void UpdateAI(const uint32 diff)
            {
                if (DespawnTimer <= diff)
                {
                    if (me->GetVehicle())
                        me->DisappearAndDie();
                    DespawnTimer = 7000;
                }
                else DespawnTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_liquid_pyriteAI(creature);
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
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_TAR_PASSIVE, me);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                damage = 0;
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if ((spell->Id == 65044 || spell->Id == 65045) && !me->HasAura(SPELL_BLAZE))
                    DoCast(me, SPELL_BLAZE, true);
            }

            void UpdateAI(uint32 const /*diff*/) {}
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

            void Reset()
            {
                GroundSlamTimer = urand(8000, 10000);
            }

            void JustDied(Unit* /*Who*/)
            {
                if (me->GetHomePosition().IsInDist(Center, 50.f))
                    instance->SetData(TYPE_COLOSSUS, instance->GetData(TYPE_COLOSSUS)+1);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (GroundSlamTimer <= diff)
                {
                    DoCastVictim(SPELL_GROUND_SLAM);
                    GroundSlamTimer = urand(20000, 25000);
                }
                else GroundSlamTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 GroundSlamTimer;
            InstanceScript* instance;
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
                me->AddAura(AURA_DUMMY_BLUE, me);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 10, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_THORIM_S_HAMMER, true);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_BLUE))
                    me->AddAura(AURA_DUMMY_BLUE, me);

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

        void UpdateAI(uint32 const diff)
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
                    me->AddAura(AURA_DUMMY_YELLOW, me);
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
                me->AddAura(AURA_DUMMY_GREEN, me);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 5, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_HODIR_S_FURY, true);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->AddAura(AURA_DUMMY_GREEN, me);

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
                me->AddAura(AURA_DUMMY_GREEN, me);
            }

            uint32 summonTimer;

            void Reset()
            {
                summonTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
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
                    me->AddAura(AURA_DUMMY_GREEN, me);

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

            void UpdateAI(uint32 const diff)
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

            void DoAction(int32 const action)
            {
                // Start encounter
                if (action == 0)
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

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action)
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

                    if (Creature* leviathan = instance->instance->GetCreature(instance->GetData64(TYPE_LEVIATHAN)))
                    {
                        CAST_AI(boss_flame_leviathan::boss_flame_leviathanAI, (leviathan->AI()))->DoAction(0); //enable hard mode activating the 4 additional events spawning additional vehicles
                        creature->SetVisible(false);
                        creature->AI()->DoAction(0); // spawn the vehicles
                        if (Creature* Delorah = creature->FindNearestCreature(NPC_DELORAH, 1000, true))
                        {
                            if (Creature* Branz = creature->FindNearestCreature(NPC_BRANZ_BRONZBEARD, 1000, true))
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

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE && player)
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

    //bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
    //{
    //    pPlayer->PlayerTalkClass->ClearMenus();
    //    switch(uiAction)
    //    {
    //        case GOSSIP_ACTION_INFO_DEF+1:
    //            if (pPlayer)
    //            {
    //                pPlayer->PrepareGossipMenu(creature);
    //
    //                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    //                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
    //            }
    //            break;
    //        case GOSSIP_ACTION_INFO_DEF+2:
    //            if (pPlayer)
    //                pPlayer->CLOSE_GOSSIP_MENU();
    //            if (Creature* Lorekeeper = creature->FindNearestCreature(NPC_LOREKEEPER, 1000, true)) //lore keeper of lorgannon
    //                Lorekeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    //            break;
    //    }
    //    return true;
    //}
    //bool OnGossipHello(Player* pPlayer, Creature* creature)
    //{
    //    InstanceScript* instance = creature->GetInstanceScript();
    //    if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE)
    //    {
    //        pPlayer->PrepareGossipMenu(creature);
    //
    //        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    //        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
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

        void OnDestroyed(GameObject* go, Player* /*pPlayer*/,  uint32 /*value*/)
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

class at_RX_214_repair_o_matic_station : public AreaTriggerScript
{
    public:
        at_RX_214_repair_o_matic_station() : AreaTriggerScript("at_RX_214_repair_o_matic_station") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (Creature* vehicle = player->GetVehicleCreatureBase())
            {
                if (!vehicle->HasAura(SPELL_AUTO_REPAIR))
                {
                    player->MonsterTextEmote(EMOTE_REPAIR, player->GetGUID(), true);
                    player->CastSpell(vehicle, SPELL_AUTO_REPAIR, true);
                    vehicle->SetFullHealth();
                    if (Creature* leviathan = ObjectAccessor::GetCreature(*player, instance ? instance->GetData64(TYPE_LEVIATHAN) : 0))
                        leviathan->AI()->SetData(DATA_UNBROKEN, 0); // set bool to false thats checked in leviathan getdata
                }
            }
            return true;
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
                if (Creature* leviathan = target->ToCreature())
                    if (leviathan->AI()->GetData(DATA_UNBROKEN))
                        return true;

            return false;
        }
};

// strange workaround until traj target selection works
class spell_anti_air_rocket : public SpellScriptLoader
{
    public:
        spell_anti_air_rocket() : SpellScriptLoader("spell_anti_air_rocket") { }

        class spell_anti_air_rocket_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anti_air_rocket_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ANTI_AIR_ROCKET_DMG))
                    return false;
                return true;
            }

            void HandleTriggerMissile(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                if (Position const* pos = GetTargetDest())
                {
                    if (Creature* temp = GetCaster()->SummonCreature(89, *pos, TEMPSUMMON_TIMED_DESPAWN, 500))
                    {
                        temp->SetReactState(REACT_PASSIVE);
                        temp->SetFlying(true);
                        temp->SetVisible(false);
                        std::list<Creature*> list;
                        GetCreatureListWithEntryInGrid(list, GetCaster(), NPC_MECHANOLIFT, 100.0f);

                        while (!list.empty())
                        {
                            std::list<Creature*>::iterator itr = list.begin();
                            std::advance(itr, urand(0, list.size()-1));

                            if ((*itr)->IsInBetween(GetCaster(), temp, 10.0f))
                            {
                                GetCaster()->CastSpell((*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), SPELL_ANTI_AIR_ROCKET_DMG, true);
                                return;
                            }
                            list.erase(itr);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_anti_air_rocket_SpellScript::HandleTriggerMissile, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_anti_air_rocket_SpellScript();
        }
};

class spell_pursued : public SpellScriptLoader
{
    public:
        spell_pursued() : SpellScriptLoader("spell_pursued") { }

        class spell_pursued_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pursued_SpellScript);

            bool Load()
            {
                _target = NULL;
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void SelectTarget(std::list<Unit*>& targetList)
            {
                if (targetList.empty())
                    return;

                std::list<Unit*> tempList;

                // try to find demolisher or siege engine first
                for (std::list<Unit*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                {
                    _target = *itr;

                    if (!_target->ToCreature())
                        continue;

                    if (_target->ToCreature()->GetEntry() == VEHICLE_SIEGE || _target->ToCreature()->GetEntry() == VEHICLE_DEMOLISHER)
                        tempList.push_back(_target);
                }

                if (tempList.empty())
                {
                    // no demolisher or siege engine, find a chopper
                    for (std::list<Unit*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                    {
                        _target = *itr;

                        if (!_target->ToCreature())
                            continue;

                        if (_target->ToCreature()->GetEntry() == VEHICLE_CHOPPER)
                            tempList.push_back(_target);
                    }
                }

                if (!tempList.empty())
                {
                    // found one or more vehicles, select a random one
                    std::list<Unit*>::iterator itr = tempList.begin();
                    std::advance(itr, urand(0, tempList.size() - 1));
                    _target = *itr;
                    targetList.clear();
                    targetList.push_back(_target);
                }
                else
                {
                    // found no vehicles, select a random player or pet
                    std::list<Unit*>::iterator itr = targetList.begin();
                    std::advance(itr, urand(0, targetList.size() - 1));
                    _target = *itr;
                    targetList.clear();
                    targetList.push_back(_target);
                }
            }

            void SetTarget(std::list<Unit*>& targetList)
            {
                targetList.clear();

                if (_target)
                    targetList.push_back(_target);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_pursued_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_pursued_SpellScript::SetTarget, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }

            Unit* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pursued_SpellScript();
        }
};

// find a more simple way
class spell_flame_leviathan_flames : public SpellScriptLoader
{
    public:
        spell_flame_leviathan_flames() : SpellScriptLoader("spell_flame_leviathan_flames") { }

        class spell_flame_leviathan_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_flame_leviathan_flames_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->HasAura(62297))
                    GetHitUnit()->RemoveAura(62297);
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(0);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_flame_leviathan_flames_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffect += SpellEffectFn(spell_flame_leviathan_flames_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_flame_leviathan_flames_SpellScript();
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

void AddSC_boss_flame_leviathan()
{
    new boss_flame_leviathan();
    new boss_flame_leviathan_seat();
    new boss_flame_leviathan_defense_turret();
    new boss_flame_leviathan_defense_cannon();
    new boss_flame_leviathan_overload_device();
    new npc_mechanolift();
    new npc_liquid_pyrite();
    new npc_colossus();
    new npc_thorims_hammer();
    new npc_mimirons_inferno();
    new npc_hodirs_fury();
    new npc_freyas_ward();
    new npc_freya_ward_summon();
    new npc_lorekeeper();
    new npc_pool_of_tar();
    // new npc_brann_bronzebeard();
    new go_ulduar_tower();
    new at_RX_214_repair_o_matic_station();
    new achievement_three_car_garage_demolisher();
    new achievement_three_car_garage_chopper();
    new achievement_three_car_garage_siege();
    new achievement_shutout();
    new achievement_unbroken();
    new achievement_orbital_bombardment();
    new achievement_orbital_devastation();
    new achievement_nuked_from_orbit();
    new achievement_orbit_uary();
    new spell_anti_air_rocket();
    new spell_pursued();
    new spell_flame_leviathan_flames();
}
