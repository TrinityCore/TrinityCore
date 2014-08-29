/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "blackwing_descent.h"
#include "Vehicle.h"
#include "Unit.h"
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
#include "Spell.h"

enum NefMagmawYells
{
    NEF_H_AGGRO                        = 9,
    NEF_H_MAG_DEATH                    = 10,
    NEF_H_MAG_DEATH_2                  = 11,
    NEF_H_LOW_HP                       = 12,
    NEF_H_STARTED_C                    = 13
};

enum Announce
{
// When Magmaw eats the tank, before rodeo phase, tank can dps his exposed head from inside it => ANN_CLOSE_HEAD.
    ANN_CLOSE_HEAD                      = 1, // You are close enough to reach Magmaw's head!
    ANN_EXPOSE_PINCERS                  = 2, // Magmaw slumps forward, exposing his pincers! - At Massive Crash cast.
    ANN_BREAK_FREE                      = 3, // Magmaw breaks free from the single chain binding him! -> Fail in casting both chains on the spike.
    ANN_IMPALED                         = 4  // Magmaw becomes impaled on the spike, exposing his head! -> Releases tank.
};

enum Pincers
{
    MAGMAW_PINCER1                      = 41620,
    MAGMAW_PINCER2                      = 41789,
};

enum Spells
{
    //Magmaw
    SPELL_MAGMA_SPIT_TANTRUM            = 78068,
    SPELL_MAGMA_SPIT_N                  = 78359,

    SPELL_LAVA_SPEW                     = 77839,
    SPELL_MOLTEN_TANTRUM                = 78403,
    SPELL_SWELTERING_ARMOR              = 78199,
    SPELL_PILLAR_OF_FLAME               = 77995,

    // Head phase
    SPELL_MANGLE                        = 89773,
    SPELL_MANGLED_LIFELESS              = 78362,

    SPELL_MASSIVE_CRASH                 = 88253,
    SPELL_MASSIVE_CRASH_DAMAGE          = 88287, // used only in spell script.

    // Ignition
    SPELL_IGNITION_AURA                 = 92131,
    SPELL_IGNITION_VISUAL_SMOKE         = 78608, // 5 sec duration then damage
    SPELL_IGNITION_VISUAL               = 92128, // 5 sec duration then damage
    SPELL_IGNITION_TRIGGER_SPAWN        = 92121,

    // Magmaw's Head
    SPELL_POINT_OF_VULNERABILITY        = 79010,
    SPELL_POINT_OF_VULNERABILITY2       = 79011,
    SPELL_RIDE_VEHICLE                  = 68503, // From DBC Sniffs

    SPELL_ENTER_MOUTH                   = 84275, // Player on Magmaw.

    SPELL_LAUNCH_HOOK_1                 = 77917,
    SPELL_LAUNCH_HOOK_2                 = 77941,

    SPELL_CUSTOM_STATE_04               = 45798,
    SPELL_CUSTOM_STATE_05               = 45799,
    SPELL_CUSTOM_IMPACT_06              = 45803,
    SPELL_CUSTOM_IMPACT_07              = 45804,
    SPELL_LAVA_ERRUPT_EMOTE             = 79461,

    SPELL_BLAZING_INFERNO               = 92154, // Summons blazing bone constructs every 40 secs, 3 and 6 mil hp
    SPELL_SHADOW_BREATH                 = 92173, // From 30%, each 10 secs
    SPELL_BERSERK                       = 26662,

   // Constructs
    SPELL_IGN                           = 92119, // missile he leaves behind
    SPELL_ARMAGEDDON                    = 92177, // at 20%
    SPELL_FIERY_SLASH                   = 92144
};

enum Events
{
    /*** Magmaw & Nefarian(Heroic) ***/

    EVENT_PILLAR_OF_FLAME = 1,
    EVENT_LAVA_SPEW,
    EVENT_MAGMA_SPIT,
    EVENT_MANGLE,
    EVENT_MASSIVE_CRASH,
    EVENT_EJECT_PINCERS,
    EVENT_LEAVE_GROUND_PHASE,
    EVENT_KILL_TANK,
    EVENT_BREAK_FREE,

    // Heroic
    EVENT_BLAZING_INFERNO,
    EVENT_SHADOW_BREATH,
    EVENT_IGNITION,

    EVENT_BERSERK,

    /*** Blazing Bone Construct ***/

    EVENT_IGNITE,
    EVENT_FIERY_SLASH,

    /*** Ignition Trigger ***/

    EVENT_IGNITION_VISUAL,
    EVENT_IGNITION_DAMAGE
};

enum Actions
{
    // Boss.
    ACTION_GET_IMPALED = 1,
    ACTION_BREAK_LOOSE,

    // Spike stalker.
    ACTION_SPIKE_RESET
};

Position const IgnitionPositions[2][21] =
{
    { // Left Side
        {-355.258f, -66.156f, 215.363f, 3.32963f},
        {-349.104f, -57.5792f, 214.837f, 3.35319f},
        {-355.983f, -79.9935f, 213.749f, 3.91082f},
        {-348.35f, -71.9141f, 213.26f, 3.96973f},
        {-341.228f, -63.2021f, 212.833f, 3.96973f},
        {-335.636f, -53.1296f, 212.332f, 5.80755f},
        {-344.959f, -47.9226f, 212.061f, 6.07851f},
        {-354.565f, -47.2949f, 213.04f, 3.04373f},
        {-350.721f, -88.5883f, 213.92f, 3.97443f},
        {-342.783f, -80.5202f, 213.868f, 3.93124f},
        {-335.879f, -72.941f, 212.87f, 4.06083f},
        {-330.037f, -64.3112f, 212.393f, 4.14329f},
        {-324.021f, -54.4161f, 211.863f, 4.19434f},
        {-317.603f, -44.6127f, 211.952f, 0.96793f},
        {-329.399f, -43.7365f, 211.748f, 6.02982f},
        {-341.139f, -38.8838f, 211.426f, 6.12014f},
        {-350.813f, -26.2997f, 211.345f, 2.15388f},
        {-352.253f, -37.0172f, 211.603f, 2.95734f},
        {-338.237f, -27.1878f, 211.154f, 3.06337f},
        {-327.528f, -32.3648f, 211.394f, 3.06337f},
        {-316.344f, -33.1654f, 211.428f, 3.17725f},
    },
    {  // Right Side
        {-313.627f, -72.6881f, 213.266f, 1.00637f},
        {-319.881f, -82.0775f, 213.552f, 4.27756f},
        {-306.833f, -83.4444f, 213.633f, 4.36788f},
        {-302.725f, -74.0836f, 213.345f, 4.69382f},
        {-304.055f, -63.3109f, 212.826f, 4.57601f},
        {-300.848f, -54.0836f, 212.39f, 4.18332f},
        {-308.972f, -52.744f, 212.326f, 5.62846f},
        {-315.607f, -58.0178f, 212.578f, 1.02995f},
        {-320.357f, -65.927f, 212.802f, 1.0378f},
        {-326.56f, -74.2884f, 213.145f, 0.841454f},
        {-333.371f, -83.2f, 213.706f, 0.566564f},
        {-343.042f, -91.8511f, 213.916f, 3.12304f},
        {-334.444f, -92.7097f, 213.903f, 3.06413f},
        {-324.424f, -93.0766f, 213.909f, 2.98166f},
        {-315.574f, -93.3725f, 213.924f, 3.12696f},
        {-304.845f, -93.5295f, 213.919f, 3.10733f},
        {-296.142f, -88.6009f, 214.03f, 4.72919f},
        {-292.752f, -78.8147f, 213.567f, 4.71348f},
        {-295.368f, -68.4218f, 213.065f, 4.71741f},
        {-293.046f, -56.9843f, 212.531f, 4.62709f},
        {-295.83f, -46.4565f, 212.04f, 1.27344f},
    }
};

Position const HeroicPositions[1] =
{
    {-330.978f, -62.313f, 212.289f, 5.976f} // Nefarians Position
};

class boss_magmaw : public CreatureScript
{
public:
    boss_magmaw() : CreatureScript("boss_magmaw") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_magmawAI (creature);
    }

    struct boss_magmawAI : public BossAI
    {
        boss_magmawAI(Creature* creature) : BossAI(creature, DATA_MAGMAW), vehicle(creature->GetVehicleKit()), summons(me)
        {
            ASSERT(vehicle);
            instance = creature->GetInstanceScript();
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }

        InstanceScript* instance;
        Vehicle* vehicle;
        Unit* sTarget;
        EventMap events;
        SummonList summons;
        bool isInManglePhase, pTar, sTar, say1, say2;
        float pTargetOldPosX, pTargetOldPosY, pTargetOldPosZ, sTargetPos;

        void Reset()
        {
            summons.DespawnAll();
            events.Reset();
            isInManglePhase = false;
            sTar = false; pTar = false;
            say1 = false; say2 = false;

            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (instance)
                instance->SetBossState(DATA_MAGMAW, NOT_STARTED);

            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
               nefarianHelperheroic->DespawnOrUnsummon(100);

            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            // Set head in combat.
            if (Unit* head = vehicle->GetPassenger(0))
            {
                head->ToCreature()->SetInCombatWithZone();
                head->SetMaxHealth(me->GetMaxHealth());
            }

            // Normal
            events.ScheduleEvent(EVENT_LAVA_SPEW, urand(17000,20000));
            events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, 25000);
            events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 11000));

            // Mangle phase
            events.ScheduleEvent(EVENT_MANGLE, 60000);

            // Berserk - 10 Min
            events.ScheduleEvent(EVENT_BERSERK, 600000);

            if (me->GetMap()->IsHeroic())
            {
                Creature* nefarian = me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC, HeroicPositions[0], TEMPSUMMON_MANUAL_DESPAWN);
                nefarian->AI()->DoZoneInCombat();
                nefarian->AI()->Talk(NEF_H_AGGRO);
                events.ScheduleEvent(EVENT_BLAZING_INFERNO, urand(15000, 18000));
            }

            if (instance)
            {
                instance->SetBossState(DATA_MAGMAW, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
            }

            _EnterCombat();
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_GET_IMPALED:
                    Talk(ANN_IMPALED);
                    me->RemoveAura(SPELL_CUSTOM_STATE_05);
                    DoCast(me, SPELL_CUSTOM_STATE_04); // Pinned

                    // Make head visible and attackable.
                    if (Unit* head = vehicle->GetPassenger(0))
                    {
                        head->SetHealth(me->GetHealth());
                        head->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        head->ClearUnitState(UNIT_STATE_ONVEHICLE);

                        me->CastSpell(head, SPELL_POINT_OF_VULNERABILITY, true);
                        head->CastSpell(head, SPELL_POINT_OF_VULNERABILITY2, true);
                    }

                    events.ScheduleEvent(EVENT_LEAVE_GROUND_PHASE, 33000);
                    events.ScheduleEvent(EVENT_EJECT_PINCERS, 1000);
                    events.CancelEvent(EVENT_KILL_TANK);
                    break;

                case ACTION_BREAK_LOOSE:
                    events.ScheduleEvent(EVENT_BREAK_FREE, 6000);
                    break;

				default:
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() && !isInManglePhase || me->HasUnitState(UNIT_STATE_CASTING))
                return; 

            if(me->GetMap()->IsHeroic())
            {
                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                {
                    if(me->GetHealthPct() < 95 && say1 == false)
                    {
                        nefarian->AI()->Talk(NEF_H_STARTED_C);
                        say1 = true;
                    }

                    if(me->GetHealthPct() < 31 && say2 == false)
                    {
                        nefarian->AI()->Talk(NEF_H_LOW_HP);
                        say2 = true;
                        events.CancelEvent(EVENT_BLAZING_INFERNO);
                        events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(6000, 9000));
                    }
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_IGNITION:
                        CastIgnition();
                        break;

                    case EVENT_SHADOW_BREATH:
                        if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                nefarian->CastSpell(target, SPELL_SHADOW_BREATH, false);
                        events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(9000, 13000));
                        break;

                    case EVENT_BLAZING_INFERNO:
                        if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                nefarian->CastSpell(target, SPELL_BLAZING_INFERNO, false);
                        events.ScheduleEvent(EVENT_BLAZING_INFERNO, urand(30000, 35000));
                        break;

                    case EVENT_MAGMA_SPIT:
                        me->AttackStop();
                        CastMagmaSpit();
                        me->Attack(me->getVictim(), true);
                        events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 11000));
                        break;

                    case EVENT_LAVA_SPEW:
                        DoCastAOE(SPELL_LAVA_SPEW);
                        events.ScheduleEvent(EVENT_LAVA_SPEW, urand(17000,20000));
                        break;

                    case EVENT_BREAK_FREE:
                        if (me->HasAura(SPELL_CUSTOM_STATE_05)) // Check if the second chain hit or not.
                        {
                            Talk(ANN_BREAK_FREE);
                            me->RemoveAura(SPELL_CUSTOM_STATE_05);
                            if (Creature* spikeStalker = me->FindNearestCreature(41767, 50.0f, true))
                                spikeStalker->AI()->DoAction(ACTION_SPIKE_RESET);
                        }
                        break;

                    case EVENT_PILLAR_OF_FLAME:
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 80.0f, true)) // Try to select farthest target.
                        {
                            if (me->GetDistance2d(target) >= 15.0f) // If target is over 15y away, it's ok.
                                DoCast(target, SPELL_PILLAR_OF_FLAME);
                            else
                                if (me->GetDistance2d(target) < 15.0f) // If target is less then 15y away, cast on nearest, as they are hacking the encounter by standing all melee.
                                    if (Unit* target2 = SelectTarget(SELECT_TARGET_NEAREST, 0, 80.0f, true))
                                        DoCast(target2, SPELL_PILLAR_OF_FLAME);
                        }
                        events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, urand(20000, 25000));
                        break;

                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK);
                        break;

                    case EVENT_MANGLE:
                        if (Unit* victim = me->getVictim())
                        {
                            if (victim->GetTypeId() == TYPEID_PLAYER)
                            {
                                sTarget = victim;
                                sTar = true;
                                isInManglePhase = true;
                                Talk(ANN_CLOSE_HEAD);
                                me->AddAura(SPELL_MANGLE, victim);
                                DoCast(me, SPELL_CUSTOM_IMPACT_06);
                                if (Unit* magmawHead = vehicle->GetPassenger(0))
                                    victim->CastSpell(magmawHead, SPELL_ENTER_MOUTH, true);
                                //sTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); 
                            }
                        }
                        events.ScheduleEvent(EVENT_MANGLE, 90000);
                        events.ScheduleEvent(EVENT_IGNITION, 5000);
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 10000);
                        events.ScheduleEvent(EVENT_KILL_TANK, 30000);
                        break;

                    case EVENT_MASSIVE_CRASH:
                        events.CancelEvent(EVENT_LAVA_SPEW);
                        events.CancelEvent(EVENT_PILLAR_OF_FLAME);
                        events.CancelEvent(EVENT_MAGMA_SPIT);

                        DoCast(me, SPELL_MASSIVE_CRASH);
                        Talk(ANN_EXPOSE_PINCERS);

                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                        // Enter Head Phase
                        if (Unit* head = vehicle->GetPassenger(0)) 
                        {
                            Unit* pincer1 = head->GetVehicleKit()->GetPassenger(0);
                            Unit* pincer2 = head->GetVehicleKit()->GetPassenger(1);

                            // Make pincers visible and right faction.
                            if (pincer1 && pincer2)
                            {
                                pincer1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                pincer2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                pincer1->setFaction(35);
                                pincer2->setFaction(35);
                                pincer1->ClearUnitState(UNIT_STATE_ONVEHICLE);
                                pincer2->ClearUnitState(UNIT_STATE_ONVEHICLE);
                            }
                        }
                        break;

                    case EVENT_EJECT_PINCERS:
                        if (Unit* head = vehicle->GetPassenger(0)) 
                        {
                            Unit* pincer1 = head->GetVehicleKit()->GetPassenger(0);
                            Unit* pincer2 = head->GetVehicleKit()->GetPassenger(1);

                            // Eject pincer passengers and set right faction.
                            if (pincer1 && pincer2)
                            {
                                pincer1->GetVehicleKit()->RemoveAllPassengers();
                                pincer2->GetVehicleKit()->RemoveAllPassengers();
                                pincer1->setFaction(14);
                                pincer2->setFaction(14);
                                pincer1->AddUnitState(UNIT_STATE_ONVEHICLE);
                                pincer2->AddUnitState(UNIT_STATE_ONVEHICLE);
                            }

                            if (sTar)
                            {
                                head->RemoveAura(SPELL_ENTER_MOUTH); // Remove from mouth seat.
                                sTarget->CastSpell(sTarget, SPELL_SWELTERING_ARMOR, true);
                                if (Unit* hTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    sTarget->JumpTo(hTarget, 10.0f);
                                isInManglePhase = false;
                                sTar = false;
                            }
                        }
                        break;

                    case EVENT_KILL_TANK:
                        if (Unit* head = vehicle->GetPassenger(0)) 
                        if (sTar)
                        {
                            head->RemoveAura(SPELL_ENTER_MOUTH); // Remove from mouth seat.
                            sTarget->CastSpell(sTarget, SPELL_MANGLED_LIFELESS, true);
                            me->Kill(sTarget);
                            isInManglePhase = false;
                            sTar = false;
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        }
                        break;

                    case EVENT_LEAVE_GROUND_PHASE:
                        // Leave Head Phase
                        if (Unit* head = vehicle->GetPassenger(0)) 
                        {
                            head->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            head->RemoveAllAuras();
                            head->AddUnitState(UNIT_STATE_ONVEHICLE);
                            me->RemoveAura(SPELL_POINT_OF_VULNERABILITY2);
                            head->RemoveAura(SPELL_POINT_OF_VULNERABILITY);
                            head->RemoveAura(SPELL_POINT_OF_VULNERABILITY2);
                        }

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAura(SPELL_CUSTOM_STATE_04);
                    
                        events.ScheduleEvent(EVENT_LAVA_SPEW, urand(17000,20000));
                        events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 11000));
                        events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, 25000);
                        break;
                }
            }

            if(!me->HasAura(SPELL_CUSTOM_STATE_04) && !me->HasAura(SPELL_CUSTOM_STATE_05) && !isInManglePhase)
                DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
            if (summon->GetEntry() == NPC_IGNITION_TRIGGER)
            {
                summon->setActive(true);
                summon->SetInCombatWithZone();
            }
            else
            {
                summon->setActive(true);
                summon->AI()->DoZoneInCombat(summon);
            }
        }

        void EnterEvadeMode()
        {
            Reset();
        
            me->GetMotionMaster()->MoveTargetedHome();

            if (Unit* head = vehicle->GetPassenger(0))
                head->ToCreature()->ClearInCombat();

            if (sTar)
            {
                //sTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (Unit* hTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    sTarget->JumpTo(hTarget,10);
            }

            if (instance)
            {
                instance->SetBossState(DATA_MAGMAW, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }
        
            _EnterEvadeMode();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                instance->SetBossState(DATA_MAGMAW, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            if (Unit* head = vehicle->GetPassenger(0)) 
                head->ToCreature()->DisappearAndDie();

            if (sTar)
            {
                //sTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (Unit* hTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    sTarget->JumpTo(hTarget,10);
            }

            if(me->GetMap()->IsHeroic())
            {
                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                {
                    nefarian->AI()->Talk(RAND(NEF_H_MAG_DEATH, NEF_H_MAG_DEATH_2));
                    nefarian->DespawnOrUnsummon(8000);
                }
            }

            summons.DespawnAll();
            _JustDied();
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if(me->HasReactState(REACT_PASSIVE) || me->HasReactState(REACT_DEFENSIVE))
                me->SetReactState(REACT_AGGRESSIVE);
            if (Unit* head = vehicle->GetPassenger(0))
            {                    
                head->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                head->SetHealth(me->GetHealth()-damage);
            }
        }

    private:
        inline void CastIgnition()
        {
            uint8 side = urand(1,2);

            for(uint8 i = 0; i < 21 ; i++)
                me->CastSpell(IgnitionPositions[side][i].GetPositionX(),IgnitionPositions[side][i].GetPositionY(),IgnitionPositions[side][i].GetPositionZ(),SPELL_IGNITION_TRIGGER_SPAWN,true);
        }

        void CastSpellOnPlayers(uint32 Spell)
        {
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();

            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    DoCast(i->getSource(), Spell);
                }
            }
        }

        void CastMagmaSpit()
        {
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();

            if (!PlayerList.isEmpty())
                for (uint8 i = 0; i <= (Is25ManRaid() ? 8 : 2); ++i)
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, i))
                    {
                        if (!me->IsWithinDistInMap(me->getVictim(), 15.0f)) // Check tank in range for enrage.
                            DoCast(target, SPELL_MAGMA_SPIT_TANTRUM);
                        else
                            DoCast(target, SPELL_MAGMA_SPIT_N);
                    }
        }
    };
};

class npc_exposed_magmaw_head : public CreatureScript
{
public:
    npc_exposed_magmaw_head() : CreatureScript("npc_exposed_magmaw_head") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_exposed_magmaw_headAI (creature);
    }

    struct npc_exposed_magmaw_headAI : public ScriptedAI
    {
        npc_exposed_magmaw_headAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
        {
            ASSERT(vehicle);
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        Vehicle* vehicle;

        void Reset()
        {
            if (Creature* magmaw = me->FindNearestCreature(41570, 50.0f, true))
            {
                me->EnterVehicle(magmaw, 0);
                me->setFaction(14);
                me->SetReactState(REACT_DEFENSIVE);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Unit* pincer1 = vehicle->GetPassenger(0)) 
                pincer1->ToCreature()->DisappearAndDie();

            if (Unit* pincer2 = vehicle->GetPassenger(1)) 
                pincer2->ToCreature()->DisappearAndDie();
        }
    };
};

class npc_magmaw_pincer : public CreatureScript
{
public:
    npc_magmaw_pincer() : CreatureScript("npc_magmaw_pincer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_magmaw_pincerAI (creature);
    }

    struct npc_magmaw_pincerAI : public ScriptedAI
    {
        npc_magmaw_pincerAI(Creature* creature) : ScriptedAI(creature)
        {
            ASSERT(creature->GetVehicleKit());
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            if (Creature* magmawHead = me->FindNearestCreature(42347, 50.0f, true))
            {
                me->EnterVehicle(magmawHead, me->GetEntry() == MAGMAW_PINCER1 ? 0 : 1);
                me->setFaction(14);
                me->SetReactState(REACT_PASSIVE);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }
    };
};

class npc_blazing_bone_construct : public CreatureScript
{
public:
    npc_blazing_bone_construct() : CreatureScript("npc_blazing_bone_construct") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blazing_bone_constructAI (creature);
    }

    struct npc_blazing_bone_constructAI : public ScriptedAI
    {
        npc_blazing_bone_constructAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            armageddon = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool armageddon;

        void EnterCombat(Unit* /*who*/)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                me->AI()->AttackStart(target);

            events.ScheduleEvent(EVENT_IGNITE, 500);
            events.ScheduleEvent(EVENT_FIERY_SLASH, 7000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(me->GetHealthPct() < 21 && !armageddon)
            {
                DoCast(me, SPELL_ARMAGEDDON);
                armageddon = true;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_IGNITE: // Spiral movement from impact point
                        DoCast(me, SPELL_LAVA_ERRUPT_EMOTE);
                        for (uint8 i = 0; i < 8; i++)
                            me->SummonCreature(NPC_IGNITION_TRIGGER, me->GetPositionX() + i, me->GetPositionY() + i, me->GetPositionZ(), 1.5f, TEMPSUMMON_TIMED_DESPAWN, 65100);
                        break;

                    case EVENT_FIERY_SLASH:
                        DoCast(me->getVictim(), SPELL_FIERY_SLASH);
                        events.ScheduleEvent(EVENT_FIERY_SLASH, urand(13000, 17000));
                        break;
                }
			}

            DoMeleeAttackIfReady();
        }
    };
};

class npc_ignition_trigger : public CreatureScript
{
public:
    npc_ignition_trigger() : CreatureScript("npc_ignition_trigger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ignition_triggerAI (creature);
    }

    struct npc_ignition_triggerAI : public ScriptedAI
    {
        npc_ignition_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_IGNITION_VISUAL, 100);
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_IGNITION_VISUAL: // Spiral movement from impact point
                        DoCast(me, SPELL_IGNITION_VISUAL_SMOKE);
                        DoCast(me, SPELL_IGNITION_VISUAL);
                        events.ScheduleEvent(EVENT_IGNITION_DAMAGE, 5000);
                        break;

                    case EVENT_IGNITION_DAMAGE:
                        me->RemoveAura(SPELL_IGNITION_VISUAL_SMOKE);
                        me->RemoveAura(SPELL_IGNITION_VISUAL);
                        DoCast(me, SPELL_IGNITION_AURA);
                        break;
                }
			}
        }
    };
};

class npc_magmaw_spike_stalker : public CreatureScript
{
public:
    npc_magmaw_spike_stalker() : CreatureScript("npc_magmaw_spike_stalker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_magmaw_spike_stalkerAI (creature);
    }

    struct npc_magmaw_spike_stalkerAI : public ScriptedAI
    {
        npc_magmaw_spike_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            firstChainHit = false;
            secondChainHit = false;
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        InstanceScript* instance;
        bool firstChainHit, secondChainHit;

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_SPIKE_RESET:
                   firstChainHit = false;
                   secondChainHit = false;
                   break;

                default:
                   break;
            }
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
        {
            if (Creature* magmaw = me->FindNearestCreature(41570, 50.0f, true))
            {
                // Either of the two spells can be cast first, so we need a double check on each.
                if (spell->Id == SPELL_LAUNCH_HOOK_1)
                {
                    firstChainHit = true;

                    if (secondChainHit == true)
                    {
                        magmaw->AI()->DoAction(ACTION_GET_IMPALED); // Here place action for phase 2.
                        DoAction(ACTION_SPIKE_RESET);
                    }
                    else
                    {
                        magmaw->CastSpell(magmaw, SPELL_CUSTOM_STATE_05, true);
                        magmaw->AI()->DoAction(ACTION_BREAK_LOOSE);
                    }
                }
                
                if (spell->Id == SPELL_LAUNCH_HOOK_2)
                {
                    secondChainHit = true;

                    if (firstChainHit == true)
                    {
                        magmaw->AI()->DoAction(ACTION_GET_IMPALED); // Here place action for phase 2.
                        DoAction(ACTION_SPIKE_RESET);
                    }
                    else
                    {
                        magmaw->CastSpell(magmaw, SPELL_CUSTOM_STATE_05, true);
                        magmaw->AI()->DoAction(ACTION_BREAK_LOOSE);
                    }
                }
            }
        }
    };
};

class spell_magmaw_massive_crash : public SpellScriptLoader // 88253.
{
public:
    spell_magmaw_massive_crash() : SpellScriptLoader("spell_magmaw_massive_crash") { }

    class spell_magmaw_massive_crashSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_magmaw_massive_crashSpellScript);

        bool Validate(SpellEntry const * spellEntry)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_MASSIVE_CRASH_DAMAGE, true);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_magmaw_massive_crashSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_magmaw_massive_crashSpellScript();
    }
};

void AddSC_boss_magmaw()
{
    new boss_magmaw();
    new npc_exposed_magmaw_head();
    new npc_magmaw_pincer();
    new npc_blazing_bone_construct();
    new npc_ignition_trigger();
    new npc_magmaw_spike_stalker();
    new spell_magmaw_massive_crash();
}