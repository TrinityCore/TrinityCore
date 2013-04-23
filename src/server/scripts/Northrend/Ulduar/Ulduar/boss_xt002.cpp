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
    TODO:
        If the boss is to close to a scrap pile -> no summon  -- Needs retail confirmation
        make the life sparks visible...     /? Need test
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"
#include "Vehicle.h"
#include "Player.h"
#include "WorldPacket.h"
#include "Opcodes.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                      = 62776,
    SPELL_SEARING_LIGHT_10                      = 63018,
    SPELL_SEARING_LIGHT_25                      = 65121,

    SPELL_SUMMON_LIFE_SPARK                     = 64210,
    SPELL_SUMMON_VOID_ZONE                      = 64203,

    SPELL_GRAVITY_BOMB_10                       = 63024,
    SPELL_GRAVITY_BOMB_25                       = 64234,

    SPELL_HEARTBREAK_10                         = 65737,
    SPELL_HEARTBREAK_25                         = 64193,

    // Cast by 33337 at Heartbreak: (not used)
    SPELL_RECHARGE_PUMMELER                     = 62831,    // Summons 33344
    SPELL_RECHARGE_SCRAPBOT                     = 62828,    // Summons 33343
    SPELL_RECHARGE_BOOMBOT                      = 62835,    // Summons 33346

    SPELL_ENERGY_ORB                            = 62790,    // Cast by 33329 on 33337, used just for its visual

    SPELL_HEART_HEAL_TO_FULL                    = 17683,
    SPELL_HEART_OVERLOAD                        = 62789,
    SPELL_HEART_OVERLOAD_VISUAL                 = 62790,

    SPELL_HEART_LIGHTNING_TETHER                = 64799,    // Cast on self?
    SPELL_HEART_RIDE_VEHICLE                    = 63313,
    SPELL_ENRAGE                                = 26662,
    SPELL_STAND                                 = 37752,
    SPELL_SUBMERGE                              = 37751,

    //------------------VOID ZONE--------------------
    SPELL_VOID_ZONE_10                          = 64203,
    SPELL_VOID_ZONE_25                          = 64235,
    SPELL_CONSUMPTION_10                        = 64208,
    SPELL_CONSUMPTION_25                        = 64206,

    // Life Spark
    SPELL_STATIC_CHARGED_10                     = 64227,
    SPELL_STATIC_CHARGED_25                     = 64236,
    SPELL_SHOCK                                 = 64230,

    //----------------XT-002 HEART-------------------
    SPELL_EXPOSED_HEART                         = 63849,
    SPELL_HEART_RIDE_XT002                      = 63852,

    //---------------XM-024 PUMMELLER----------------
    SPELL_ARCING_SMASH                          = 8374,
    SPELL_TRAMPLE                               = 5568,
    SPELL_UPPERCUT                              = 10966,

    // Scrapbot:
    SPELL_SCRAPBOT_RIDE_VEHICLE                 = 47020,
    SPELL_SUICIDE                               = 7,

    //------------------BOOMBOT-----------------------
    SPELL_AURA_BOOMBOT                          = 65032,
    SPELL_BOOM                                  = 62834,

    //-----------------SCRAPBOT-----------------------
    SPELL_HEAL_XT002                            = 62832,
    // Achievement-related spells
    SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS     = 65037
};

#define SPELL_SEARING_LIGHT RAID_MODE(SPELL_SEARING_LIGHT_10, SPELL_SEARING_LIGHT_25)
#define SPELL_GRAVITY_BOMB RAID_MODE(SPELL_GRAVITY_BOMB_10, SPELL_GRAVITY_BOMB_25)
#define SPELL_HEARTBREAK RAID_MODE(SPELL_HEARTBREAK_10, SPELL_HEARTBREAK_25)
#define SPELL_CONSUMPTION RAID_MODE(SPELL_CONSUMPTION_10, SPELL_CONSUMPTION_25)
#define SPELL_STATIC_CHARGED RAID_MODE(SPELL_STATIC_CHARGED_10, SPELL_STATIC_CHARGED_25)

enum Creatures
{
    NPC_VOID_ZONE                               = 34001,
    NPC_LIFE_SPARK                              = 34004,
    NPC_XT002_HEART                             = 33329,
    NPC_XS013_SCRAPBOT                          = 33343,
    NPC_XM024_PUMMELLER                         = 33344,
    NPC_XE321_BOOMBOT                           = 33346
};

enum Actions
{
    ACTION_ENTER_HARD_MODE,
    ACTION_XT002_REACHED
};

enum XT002Data
{
    DATA_TRANSFERED_HEALTH,
    DATA_HARD_MODE,
    DATA_HEALTH_RECOVERED,
    DATA_GRAVITY_BOMB_CASUALTY
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_HEART_OPENED                            = 1,
    SAY_HEART_CLOSED                            = 2,
    SAY_TYMPANIC_TANTRUM                        = 3,
    SAY_SLAY                                    = 4,
    SAY_BERSERK                                 = 5,
    SAY_DEATH                                   = 6,
    SAY_SUMMON                                  = 7,
    EMOTE_TYMPANIC                              = 8,
    EMOTE_HEART                                 = 9,
    // Scrapbot emote
    EMOTE_REPAIR                                = 0
};

enum WaypointID
{
    WAYPOINT_XT     = 1360540
};

#define HEART_VEHICLE_SEAT 0

/************************************************
-----------------SPAWN LOCATIONS-----------------
************************************************/
const Position spawnLocations[] = 
{
    { 796.0f, -94.0f, 412.0f, 0.0 }, // Lower right
    { 796.0f,  57.0f, 412.0f, 0.0 }, // Lower left
    { 890.0f, -82.0f, 412.0f, 0.0 }, // Upper right
    { 894.0f,  62.0f, 412.0f, 0.0 }  // Upper left
};
/*-------------------------------------------------------
 *
 *        XT-002 DECONSTRUCTOR
 *
 *///----------------------------------------------------
class boss_xt002 : public CreatureScript
{
    private:
        // Internal definitions
        enum XT002Phase
        {
            PHASE_ACTIVE = 1,
            PHASE_PASSIVE
        };

        enum XT002HeartPhase
        {
            PHASE_AT_100_PERCT      = 100,
            PHASE_ABOVE_75_PERCT    = 75,
            PHASE_ABOVE_50_PERCT    = 50,
            PHASE_ABOVE_25_PERCT    = 25,
            PHASE_ABOVE_0_PERCT     = 0
        };

        enum XT002Events
        {
            EVENT_TYMPANIC_TANTRUM = 1,
            EVENT_SEARING_LIGHT,
            EVENT_GRAVITY_BOMB,
            EVENT_HEART_PHASE,
            EVENT_ENERGY_ORB,
            EVENT_DISPOSE_HEART,
            EVENT_ENRAGE,
            EVENT_ENTER_HARD_MODE,
            EVENT_SPAWN_ADDS,
            EVENT_OVERLOAD_VISUAL
        };

        enum AchievementCredits
        {
            ACHIEV_MUST_DECONSTRUCT_FASTER = 21027
        };

        enum Timers
        {
            TIMER_TYMPANIC_TANTRUM_MIN = 32*IN_MILLISECONDS,
            TIMER_TYMPANIC_TANTRUM_MAX = 36*IN_MILLISECONDS,
            TIMER_SEARING_LIGHT        = 20*IN_MILLISECONDS,
            TIMER_GRAVITY_BOMB         = 20*IN_MILLISECONDS,
            TIMER_HEART_PHASE          = 30*IN_MILLISECONDS,
            TIMER_ENERGY_ORB_MIN       = 9*IN_MILLISECONDS,
            TIMER_ENERGY_ORB_MAX       = 10*IN_MILLISECONDS,
            TIMER_ENRAGE               = 10*MINUTE*IN_MILLISECONDS,
            TIMER_VOID_ZONE            = 3*IN_MILLISECONDS
        };

    public:
        boss_xt002() : CreatureScript("boss_xt002") {}

        struct boss_xt002_AI : public BossAI
        {
            boss_xt002_AI(Creature* creature) : BossAI(creature, BOSS_XT002) {}

            void Reset()
            {
                _Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);  // Just for the case they are still present

                healthRecovered = false;
                gravityBombCasualty = false;
                hardMode = false;

                SetPhaseOne();
                me->GetMotionMaster()->MovePath(WAYPOINT_XT, true);
                transferHealth = 0;
                phase = PHASE_ACTIVE;
                heartPhase = PHASE_AT_100_PERCT;
                events.SetPhase(PHASE_ACTIVE);

                if (!instance)
                    return;

                if (me->GetVehicleKit())
                {
                    if (Unit* heart = me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT))
                        heart->ToCreature()->DespawnOrUnsummon();

                    if (Unit* heart = me->SummonCreature(NPC_XT002_HEART, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
                        heart->EnterVehicle(me, HEART_VEHICLE_SEAT);
                }

                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE, 0, PHASE_ACTIVE);
                events.ScheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB, 0, PHASE_ACTIVE);
                events.ScheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT, 0, PHASE_ACTIVE);
                // Due to Hordeguides, the first Tympanic Tantrum gets scheduled after ~1min.
                events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX)*2, 0, PHASE_ACTIVE);                               

                if (!instance)
                    return;

                heartPhase = PHASE_ABOVE_75_PERCT;
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ENTER_HARD_MODE:
                        events.ScheduleEvent(EVENT_ENTER_HARD_MODE, 1);
                        break;
                    case ACTION_XT002_REACHED:
                        healthRecovered = true;
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*victim*/)
            {
                Talk(SAY_DEATH);
                if (hardMode)
                    me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                _JustDied();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!hardMode && phase == PHASE_ACTIVE && HealthBelowPct(heartPhase))
                    ExposeHeart();
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_HARD_MODE:
                        return hardMode ? 1 : 0;
                    case DATA_HEALTH_RECOVERED:
                        return healthRecovered ? 1 : 0;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        return gravityBombCasualty ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case DATA_TRANSFERED_HEALTH:
                        transferHealth = data;
                        break;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        gravityBombCasualty = (data > 0) ? true : false;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SEARING_LIGHT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SEARING_LIGHT);
                            events.ScheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT, 0, PHASE_ACTIVE);
                            return;
                        case EVENT_GRAVITY_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_GRAVITY_BOMB);
                            events.ScheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB, 0, PHASE_ACTIVE);
                            return;
                        case EVENT_TYMPANIC_TANTRUM:
                            Talk(SAY_TYMPANIC_TANTRUM);
                            Talk(EMOTE_TYMPANIC);
                            DoCast(SPELL_TYMPANIC_TANTRUM);
                            events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX), 0, PHASE_ACTIVE);
                            return;
                        case EVENT_DISPOSE_HEART:
                            SetPhaseOne();
                            return;
                        case EVENT_ENRAGE:
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_ENRAGE);
                            return;
                        case EVENT_ENTER_HARD_MODE:
                            me->SetFullHealth();
                            DoCast(me, SPELL_HEARTBREAK, true);
                            me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                            hardMode = true;
                            SetPhaseOne();
                            return;
                        case EVENT_SPAWN_ADDS:
                        {
                            if (!urand(0,15))
                                Talk(SAY_SUMMON);

                            uint8 npc = rand() % 3;
                            switch (npc)
                            {
                                case 0:
                                    // Spawn Pummeller
                                    me->SummonCreature(NPC_XM024_PUMMELLER, spawnLocations[rand() % 4], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1*MINUTE*IN_MILLISECONDS);
                                    break;
                                case 1:
                                {
                                    uint8 pos = rand() % 4;
                                    // Spawn 5 Scrapbots
                                    for (uint8 n = 0; n < 5; n++)
                                    {
                                        me->SummonCreature(NPC_XS013_SCRAPBOT,
                                            frand(spawnLocations[pos].GetPositionX() - 3.0f, spawnLocations[pos].GetPositionX() + 3.0f),
                                            frand(spawnLocations[pos].GetPositionY() - 3.0f, spawnLocations[pos].GetPositionY() + 3.0f),
                                            spawnLocations[pos].GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1*MINUTE*IN_MILLISECONDS);
                                    }
                                    break;
                                }
                                case 2:
                                    // Spawn Boombot
                                    me->SummonCreature(NPC_XE321_BOOMBOT, spawnLocations[rand() % 4], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1*MINUTE*IN_MILLISECONDS);
                                    break;
                                default:
                                    break;
                            }
                            events.ScheduleEvent(EVENT_SPAWN_ADDS, 4*IN_MILLISECONDS, 0, PHASE_PASSIVE);
                            return;
                        }
                        case EVENT_OVERLOAD_VISUAL:
                            if (Unit* toyPile = ObjectAccessor::GetUnit(*me, instance->GetData64(DATA_TOY_PILE_0 + urand(0, 3))))
                                me->CastSpell(toyPile, SPELL_ENERGY_ORB, true);
                            events.ScheduleEvent(EVENT_OVERLOAD_VISUAL, urand(1*IN_MILLISECONDS, 3*IN_MILLISECONDS), 0, PHASE_PASSIVE);
                            return;
                        default:
                            return;
                    }
                }

                if (phase == PHASE_ACTIVE)
                    DoMeleeAttackIfReady();
            }

            void RecalcHeartPhase()
            {
                /*  Note: I'm not sure about this, since I did not find any source that covers the following scenario:
                    - XT on phase 2
                    - Players' damage too low
                    - Bots get him repaired above the last limit (say, if he got down to <75%, they heal him up to >75%)
                    - Does the XT schedule another step at the last limit (in the example mentioned above: at 75%) or will he fall through ?
                    The code below assumes the first option.
                    I know that this will be a rather rare scenario, but it need to be covered by our code ;)
                */
                float healthPct = me->GetHealthPct();
                if (healthPct > 75)
                    heartPhase = PHASE_ABOVE_75_PERCT;
                else if (healthPct > 50)
                    heartPhase = PHASE_ABOVE_50_PERCT;
                else if (healthPct > 25)
                    heartPhase = PHASE_ABOVE_25_PERCT;
                else
                    heartPhase = PHASE_ABOVE_0_PERCT;
            }

            void ExposeHeart()
            {
                Talk(SAY_HEART_OPENED);
                Talk(EMOTE_HEART);
                me->RemoveAurasDueToSpell(SPELL_TYMPANIC_TANTRUM);
                me->GetMotionMaster()->MoveIdle();

                DoCast(me, SPELL_SUBMERGE);  // Will make creature untargetable

                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                Talk(SAY_SUMMON);

                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT) : NULL;
                if (heart)
                {
                    heart->ClearUnitState(UNIT_STATE_ONVEHICLE);
                    heart->CastSpell(heart, SPELL_HEART_OVERLOAD, false);
                    heart->CastSpell(me, SPELL_HEART_LIGHTNING_TETHER, false);
                    heart->CastSpell(heart, SPELL_HEART_HEAL_TO_FULL, true);
                    heart->CastSpell(heart, SPELL_EXPOSED_HEART, false);    // Channeled
                    heart->SetVisible(true);
                    heart->ExitVehicle();
                    heart->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                }
                // If that does not work... uh-oh
                events.CancelEvent(EVENT_SEARING_LIGHT);
                events.CancelEvent(EVENT_GRAVITY_BOMB);
                events.CancelEvent(EVENT_TYMPANIC_TANTRUM);

                // Phase 2 has officially started
                phase = PHASE_PASSIVE;
                RecalcHeartPhase();
                // Start "end of phase 2 timer"
                events.SetPhase(PHASE_PASSIVE);
                events.ScheduleEvent(EVENT_DISPOSE_HEART, TIMER_HEART_PHASE, 0, PHASE_PASSIVE);
                events.ScheduleEvent(EVENT_OVERLOAD_VISUAL, urand(1*IN_MILLISECONDS, 3*IN_MILLISECONDS), 0, PHASE_PASSIVE);
                // Hordeguides: Add-spawn is running in phase 2
                events.ScheduleEvent(EVENT_SPAWN_ADDS, 2*IN_MILLISECONDS, 0, PHASE_PASSIVE);
            }

            void SetPhaseOne()
            {
                Talk(SAY_HEART_CLOSED);
                if (me->HasAura(SPELL_SUBMERGE))
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                DoCast(me, SPELL_STAND);
                // Just for the case this isn't done by the spell above.
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);

                phase = PHASE_ACTIVE;
                events.SetPhase(PHASE_ACTIVE);
                
                events.RescheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT / 2, 0, PHASE_ACTIVE);
                events.RescheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB, 0, PHASE_ACTIVE);
                events.RescheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX)*2, 0, PHASE_ACTIVE);

                /* Uncomment when XT works well as vehicle
                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT) : NULL;
                if (!heart)
                    return;*/

                Unit* heart = me->FindNearestCreature(NPC_XT002_HEART, 70.f, true);
                if (!heart)
                    return;

                heart->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                heart->RemoveAurasDueToSpell(SPELL_EXPOSED_HEART);
                heart->EnterVehicle(me, HEART_VEHICLE_SEAT);

                if (!hardMode)
                {
                    if (!transferHealth) // Not settled == heart did not die
                        if ( uint32 healthDiff = (heart->GetMaxHealth() - heart->GetHealth()) )
                        {
                            me->DealDamage(me, healthDiff);
                            me->LowerPlayerDamageReq(healthDiff);
                        }                    

                    // Note: if the heart did not go down enough or the players sucked too much (heal through bots), we may have jumped back in heart-phase
                    RecalcHeartPhase();
                }
            }

            private:
                // Achievement related
                bool healthRecovered;       // Did a scrapbot recover XT-002's health during the encounter?
                bool hardMode;              // Are we in hard mode? Or: was the heart killed during phase 2?
                bool gravityBombCasualty;   // Did someone die because of Gravity Bomb damage?

                XT002Phase phase;
                XT002HeartPhase heartPhase;
                uint32 transferHealth;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_xt002_AI>(creature);
        }
};

/*-------------------------------------------------------
 *
 *        XT-002 HEART
 *
 *///----------------------------------------------------
class mob_xt002_heart : public CreatureScript
{
    public:
        mob_xt002_heart() : CreatureScript("mob_xt002_heart") {}

        struct mob_xt002_heartAI : public ScriptedAI
        {
            mob_xt002_heartAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                SetCombatMovement(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);
            }

            void DamageTaken(Unit* /*pDone*/, uint32 &damage)
            {
                Creature* xt002 = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_XT002));
                if (!xt002 || !xt002->AI())
                    return;

                if (damage >= me->GetHealth())
                {
                    xt002->AI()->SetData(DATA_TRANSFERED_HEALTH, me->GetMaxHealth());
                    xt002->AI()->DoAction(ACTION_ENTER_HARD_MODE);
                    damage = 0;
                }
            }

            private:
                InstanceScript* instance;
                uint32 damageTaken;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_xt002_heartAI(creature);
        }
};

/*-------------------------------------------------------
 *
 *        XS-013 SCRAPBOT
 *
 *///----------------------------------------------------
class mob_scrapbot : public CreatureScript
{
    public:
        mob_scrapbot() : CreatureScript("mob_scrapbot") {}

        struct mob_scrapbotAI : public ScriptedAI
        {
            mob_scrapbotAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);

                rangeCheckTimer = 0.5*IN_MILLISECONDS;

                if (Creature* pXT002 = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_XT002)))
                    me->GetMotionMaster()->MoveFollow(pXT002, 0.0f, 0.0f);
            }

            void UpdateAI(uint32 diff)
            {
                if (instance->GetBossState(BOSS_XT002) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (rangeCheckTimer <= diff)
                {
                    if (Creature* xt002 = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_XT002)))
                    {
                        if (!casted && xt002->isAlive())
                            if (me->IsWithinMeleeRange(xt002))
                            {
                                casted = true;
                                Talk(EMOTE_REPAIR);
                                xt002->CastSpell(xt002, SPELL_HEAL_XT002, true);
                                xt002->AI()->DoAction(ACTION_XT002_REACHED);
                                /*
                                DoCast(xt002, SPELL_SCRAPBOT_RIDE_VEHICLE);
                                // Unapply vehicle aura again
                                xt002->RemoveAurasDueToSpell(SPELL_SCRAPBOT_RIDE_VEHICLE);
                                */
                                me->DespawnOrUnsummon();
                            }
                    }
                }
                else
                    rangeCheckTimer -= diff;
            }

            private:
                InstanceScript* instance;
                uint32 rangeCheckTimer;
                bool casted;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_scrapbotAI(creature);
        }
};

/*-------------------------------------------------------
 *
 *        XM-024 PUMMELLER
 *
 *///----------------------------------------------------
class mob_pummeller : public CreatureScript
{
    private:
        enum 
        { 
            EVENT_ARCING_SMASH = 1,
            EVENT_TRAMPLE,
            EVENT_UPPERCUT,
            TIMER_ARCING_SMASH = 7*IN_MILLISECONDS,
            TIMER_TRAMPLE      = 2*IN_MILLISECONDS,
            TIMER_UPPERCUT     = 7*IN_MILLISECONDS
        };

    public:
        mob_pummeller() : CreatureScript("mob_pummeller") {}

        struct mob_pummellerAI : public ScriptedAI
        {
            mob_pummellerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_ARCING_SMASH, TIMER_ARCING_SMASH);
                events.ScheduleEvent(EVENT_TRAMPLE, TIMER_TRAMPLE);
                events.ScheduleEvent(EVENT_UPPERCUT, TIMER_UPPERCUT);

                me->SetInCombatWithZone();
            }

            void UpdateAI(uint32 diff)
            {
                if (instance->GetBossState(BOSS_XT002) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    events.Update(diff);
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_ARCING_SMASH:
                                DoCast(me->getVictim(), SPELL_ARCING_SMASH);
                                events.ScheduleEvent(EVENT_ARCING_SMASH, TIMER_ARCING_SMASH);
                                return;
                            case EVENT_TRAMPLE:
                                DoCast(me->getVictim(), SPELL_TRAMPLE);
                                events.ScheduleEvent(EVENT_TRAMPLE, TIMER_TRAMPLE);
                                return;
                            case EVENT_UPPERCUT:
                                DoCast(me->getVictim(), SPELL_UPPERCUT);
                                events.ScheduleEvent(EVENT_UPPERCUT, TIMER_UPPERCUT);
                                return;
                            default:
                                return;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap events;
                InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_pummellerAI(creature);
        }
};

/*-------------------------------------------------------
 *
 *        XE-321 BOOMBOT
 *
 *///----------------------------------------------------
class BoomEvent : public BasicEvent
{
    public:
        BoomEvent(Creature* me) : _me(me) {}

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            // This hack is here because we suspect our implementation of spell effect execution on targets
            // is done in the wrong order. We suspect that EFFECT_0 needs to be applied on all targets,
            // then EFFECT_1, etc - instead of applying each effect on target1, then target2, etc.
            // The above situation causes the visual for this spell to be bugged, so we remove the instakill
            // effect and implement a script hack for that.

            _me->CastSpell(_me, SPELL_BOOM, false);
            return true;
        }

    private:
        Creature* _me;
};

class mob_boombot : public CreatureScript
{
    public:
        mob_boombot() : CreatureScript("mob_boombot") {}

        struct mob_boombotAI : public ScriptedAI
        {
            mob_boombotAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                boomed = false;
                DoCast(SPELL_AURA_BOOMBOT); // For achievement

                // HACK/workaround:
                // these values aren't confirmed - lack of data - and the values in DB are incorrect
                // these values are needed for correct damage of Boom spell
                me->SetFloatValue(UNIT_FIELD_MINDAMAGE, 15000.0f);
                me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, 18000.0f);
                me->SetDisplayId(19139);
                me->SetSpeed(MOVE_RUN, 0.5f, true);
                me->SetInCombatWithZone();
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (damage >= (me->GetHealth() - me->GetMaxHealth() * 0.5f) && !boomed)
                {
                    boomed = true; // Prevent recursive calls

                    WorldPacket data(SMSG_SPELLINSTAKILLLOG, 8+8+4);
                    data << uint64(me->GetGUID());
                    data << uint64(me->GetGUID());
                    data << uint32(SPELL_BOOM);
                    me->SendMessageToSet(&data, false);

                    me->DealDamage(me, me->GetHealth(), NULL, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                    damage = 0;

                    // Visual only seems to work if the instant kill event is delayed or the spell itself is delayed
                    // Casting done from player and caster source has the same targetinfo flags,
                    // so that can't be the issue
                    // See BoomEvent class
                    // Schedule 1s delayed
                    me->m_Events.AddEvent(new BoomEvent(me), me->m_Events.CalculateTime(1*IN_MILLISECONDS));
                }
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (instance->GetBossState(BOSS_XT002) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (!UpdateVictim())
                    return;

                // No melee attack
            }

           private:
                InstanceScript* instance;
                bool boomed;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_boombotAI(creature);
        }
};


/*-------------------------------------------------------
 *
 *        LIFE SPARK
 *
 *///----------------------------------------------------
class mob_life_spark : public CreatureScript
{
    private:
        enum
        {
            TIMER_SHOCK = 12*IN_MILLISECONDS
        };

    public:
        mob_life_spark() : CreatureScript("mob_life_spark") {}

        struct mob_life_sparkAI : public ScriptedAI
        {
            mob_life_sparkAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                DoCast(me, SPELL_STATIC_CHARGED);
                shockTimer = 0; // first one is immediate.
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (shockTimer <= diff)
                {
                    if (me->IsWithinMeleeRange(me->getVictim()))
                    {
                        DoCast(me->getVictim(), SPELL_SHOCK);
                        shockTimer = TIMER_SHOCK;
                    }
                }
                else shockTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 shockTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_life_sparkAI(creature);
        }
};

class mob_void_zone : public CreatureScript
{
    public:
        mob_void_zone() : CreatureScript("mob_void_zone") {}

        struct mob_void_zoneAI : public ScriptedAI
        {
            mob_void_zoneAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                consumptionTimer = 3*IN_MILLISECONDS;
            }

            void UpdateAI(uint32 diff)
            {
                if (consumptionTimer <= diff)
                {
                    int32 dmg = RAID_MODE<uint32>(5000, 7500);
                    me->CastCustomSpell(me, SPELL_CONSUMPTION, &dmg, 0, 0, false);
                    consumptionTimer = 3*IN_MILLISECONDS;
                }
                else
                    consumptionTimer -= diff;
            }

        private:
            uint32 consumptionTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_void_zoneAI(creature);
        }
};

class spell_xt002_searing_light_spawn_life_spark : public SpellScriptLoader
{
    public:
        spell_xt002_searing_light_spawn_life_spark() : SpellScriptLoader("spell_xt002_searing_light_spawn_life_spark") {}

        class spell_xt002_searing_light_spawn_life_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_searing_light_spawn_life_spark_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_LIFE_SPARK))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (Creature* xt002c = xt002->ToCreature())   // Heartbreak aura indicating hard mode
                            if (xt002c->IsAIEnabled)
                                if (xt002c->AI()->GetData(DATA_HARD_MODE))
                                    xt002->CastSpell(player, SPELL_SUMMON_LIFE_SPARK, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_searing_light_spawn_life_spark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_searing_light_spawn_life_spark_AuraScript();
        }
};

class spell_xt002_gravity_bomb_aura : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_aura() : SpellScriptLoader("spell_xt002_gravity_bomb_aura") {}

        class spell_xt002_gravity_bomb_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_gravity_bomb_aura_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_VOID_ZONE))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (Creature* xt002c = xt002->ToCreature())   // Heartbreak aura indicating hard mode
                            if (xt002c->IsAIEnabled)
                                if (xt002c->AI()->GetData(DATA_HARD_MODE))
                                    xt002c->CastSpell(player, SPELL_SUMMON_VOID_ZONE, true);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* xt002 = GetCaster();
                if (!xt002)
                    return;

                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                if (aurEff->GetAmount() >= int32(owner->GetHealth()))
                    if (xt002->GetAI())
                        xt002->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_xt002_gravity_bomb_aura_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_gravity_bomb_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };
        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_gravity_bomb_aura_AuraScript();
        }
};

class BombTargetSelector : public std::unary_function<Unit *, bool>
{
    public:
        BombTargetSelector(Creature* me, const WorldObject* victim) : _me(me), _victim(victim) {}

        bool operator() (WorldObject* target)
        {
            /*
                Decision rule:
                - If currently checked target is out current target, check if there are more targets in our threat-list.
                    - If there are, cut off the current target (in most cases, the tank).
                    - Otherwise - which would appear when only one player is in the list - we do not remove it from the list.
            */
            if (target == _victim && _me->getThreatManager().getThreatList().size() > 1)
                return true;

            return false;
        }

        Creature* _me;
        WorldObject const* _victim;
};

class spell_xt002_gravity_bomb_aura_target : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_aura_target() : SpellScriptLoader("spell_xt002_gravity_bomb_aura_target") {}

        class spell_xt002_gravity_bomb_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_gravity_bomb_targeting_SpellScript);

            bool Load()
            {
                _target = NULL;
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BombTargetSelector(GetCaster()->ToCreature(), GetCaster()->getVictim()));

                if (targets.empty())
                    return;

                _target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(_target);
            }

            void SetTarget(std::list<WorldObject*>& targets)
            {
                targets.clear();
                if (_target)
                    targets.push_back(_target);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_gravity_bomb_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_gravity_bomb_targeting_SpellScript::SetTarget, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
            }

            WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_gravity_bomb_targeting_SpellScript();
        }
};

class spell_xt002_gravity_bomb_damage : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_damage() : SpellScriptLoader("spell_xt002_gravity_bomb_damage") {}

        class spell_xt002_gravity_bomb_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_gravity_bomb_damage_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
                    if (caster->GetAI())
                        caster->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_gravity_bomb_damage_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_gravity_bomb_damage_SpellScript();
        }
};

class spell_xt002_tympanic_tantrum : public SpellScriptLoader
{
    public:
        spell_xt002_tympanic_tantrum() : SpellScriptLoader("spell_xt002_tympanic_tantrum") {}

        class spell_xt002_tympanic_tantrum_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_tympanic_tantrum_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if (PlayerOrPetCheck());
            }

            void HandleDamageCalc(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                {
                    uint8 healthPct = GetSpellInfo()->Effects[effIndex].CalcValue(target);
                    SetHitDamage(target->GetMaxHealth() / healthPct);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_xt002_tympanic_tantrum_SpellScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_tympanic_tantrum_SpellScript();
        }
};

class spell_xt002_submerged : public SpellScriptLoader
{
    public:
        spell_xt002_submerged() : SpellScriptLoader("spell_xt002_submerged") {}

        class spell_xt002_submerged_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_submerged_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Creature* target = GetHitCreature();
                if (!target)
                    return;

                target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                target->SetStandState(UNIT_STAND_STATE_SUBMERGED);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_submerged_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_submerged_SpellScript();
        }
};

class spell_xt002_stand : public SpellScriptLoader
{
    public:
        spell_xt002_stand() : SpellScriptLoader("spell_xt002_stand") {}

        class spell_xt002_stand_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_stand_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Creature* target = GetHitCreature();
                if (!target)
                    return;

                target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                target->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_stand_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_stand_SpellScript();
        }
};

class achievement_nerf_engineering : public AchievementCriteriaScript
{
    public:
        achievement_nerf_engineering() : AchievementCriteriaScript("achievement_nerf_engineering") {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_HEALTH_RECOVERED));
        }
};

class achievement_heartbreaker : public AchievementCriteriaScript
{
    public:
        achievement_heartbreaker() : AchievementCriteriaScript("achievement_heartbreaker") {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return target->GetAI()->GetData(DATA_HARD_MODE);
        }
};

class achievement_nerf_gravity_bombs : public AchievementCriteriaScript
{
    public:
        achievement_nerf_gravity_bombs() : AchievementCriteriaScript("achievement_nerf_gravity_bombs") {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_GRAVITY_BOMB_CASUALTY));
        }
};

void AddSC_boss_xt002()
{
    new mob_xt002_heart();
    new mob_scrapbot();
    new mob_pummeller();
    new mob_boombot();
    new mob_life_spark();
    new mob_void_zone();
    new boss_xt002();

    new spell_xt002_searing_light_spawn_life_spark();
    new spell_xt002_gravity_bomb_aura();
    new spell_xt002_gravity_bomb_aura_target();
    new spell_xt002_gravity_bomb_damage();
    new spell_xt002_tympanic_tantrum();
    new spell_xt002_submerged();
    new spell_xt002_stand();

    new achievement_nerf_engineering();
    new achievement_heartbreaker();
    new achievement_nerf_gravity_bombs();
}

#undef SPELL_SEARING_LIGHT
#undef SPELL_GRAVITY_BOMB
#undef SPELL_HEARTBREAK
#undef SPELL_CONSUMPTION
#undef SPELL_STATIC_CHARGED
