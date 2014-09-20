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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"
#include "TW_trial_of_the_champion.h"
#include "Player.h"

enum Spells
{
    // Vehicle
    SPELL_SHIELD_BREAKER            = 62575,
    SPELL_SHIELD                    = 62544,
    SPELL_THRUST                    = 68505,
    SPELL_SHIELD_1                  = 66482,
    SPELL_CHARGE                    = 63010,
    SPELL_DEFEND                    = 62719,

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    SPELL_MORTAL_STRIKE             = 68783,
    SPELL_MORTAL_STRIKE_H           = 68784,
    SPELL_BLADESTORM                = 63784,
    SPELL_INTERCEPT                 = 67540,
    SPELL_ROLLING_THROW             = 47115, //not implemented in the AI yet...

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    SPELL_FIREBALL                  = 66042,
    SPELL_FIREBALL_H                = 68310,
    SPELL_BLAST_WAVE                = 66044,
    SPELL_BLAST_WAVE_H              = 68312,
    SPELL_HASTE                     = 66045,
    SPELL_POLYMORPH                 = 66043,
    SPELL_POLYMORPH_H               = 68311,

    // Colosos && Runok Wildmane || Shaman
    SPELL_CHAIN_LIGHTNING           = 67529,
    SPELL_CHAIN_LIGHTNING_H         = 68319,
    SPELL_EARTH_SHIELD              = 67530,
    SPELL_HEALING_WAVE              = 67528,
    SPELL_HEALING_WAVE_H            = 68318,
    SPELL_HEX_OF_MENDING            = 67534,

    // Jaelyne Evensong && Zul'tore || Hunter
    SPELL_DISENGAGE                 = 68340, //not implemented in the AI yet...
    SPELL_LIGHTNING_ARROWS          = 66083,
    SPELL_MULTI_SHOT                = 49047,
    SPELL_SHOOT                     = 65868,
    SPELL_SHOOT_H                   = 67988,

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                = 67709,
    SPELL_EVISCERATE_H              = 68317,
    SPELL_FAN_OF_KNIVES             = 67706,
    SPELL_POISON_BOTTLE             = 67701,

    // Achievement Credit
    SPELL_GRAND_CHAMPIONS_CREDIT    = 68572,
};

enum Talk
{
    SAY_CHAMPION_DEFEAT             = 0,
    WARNING_WEAPONS                 = 1,
};

enum Seat
{
    SEAT_ID_0                       = 0,
};

enum Events
{
    // Warrior
    EVENT_BLADESTORM                = 1,
    EVENT_MORTAL_STRIKE             = 2,

    // Mage
    EVENT_FIREBALL                  = 3,
    EVENT_BLASTWAVE                 = 4,
    EVENT_HASTE                     = 5,
    EVENT_POLYMORPH                 = 6,

    // Shaman
    EVENT_EARTH_SHIELD              = 7,
    EVENT_CHAIN_LIGHTNING           = 8,
    EVENT_HEALING_WAVE              = 9,
    EVENT_HEX                       = 10,

    // Hunter
    EVENT_SHOOT                     = 11,
    EVENT_MULTI_SHOOT               = 12,
    EVENT_DISENGAGE                 = 13,
    EVENT_LIGHTNING_ARROWS          = 14,

    // Rogue
    EVENT_EVISCERATE                = 15,
    EVENT_FAN_OF_KNIVES             = 16,
    EVENT_POISON_BOTTLE             = 17,

    // Vehicles
    EVENT_SHIELD_BREAKER            = 18,
    EVENT_CHARGE_VEHICLE            = 19,
    EVENT_THRUST                    = 20,
    EVENT_DEFEND                    = 21,

    EVENT_PHASE_SWITCH,
};

enum Phases
{
    PHASE_IDLE                      = 1,
    PHASE_COMBAT                    = 2
};

/*
struct Point
{
    float x,y,z;
};

const Point MovementPoint[] =
{
  {746.84f,623.15f,411.41f},
  {747.96f,620.29f,411.09f},
  {750.23f,618.35f,411.09f}
};
*/

void TW_AggroAllPlayers(Creature* pTemp)
{
    Map::PlayerList const &PlList = pTemp->GetMap()->GetPlayers();

    if (PlList.isEmpty())
        return;

    for(Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if (Player* player = i->GetSource())
        {
            if (player->IsGameMaster())
                continue;

            if (player->IsAlive())
            {
                pTemp->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                pTemp->SetReactState(REACT_AGGRESSIVE);
                pTemp->SetInCombatWith(player);
                player->SetInCombatWith(pTemp);
                pTemp->AddThreat(player, 0.0f);
            }
        }
    }
}

bool TW_GrandChampionsOutVehicle(Creature* me)
{
    InstanceScript* instance = me->GetInstanceScript();

    if (!instance)
        return false;

    Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1));
    Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2));
    Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3));

    if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
    {
        if (!pGrandChampion1->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion1->GetVehicle() &&
            !pGrandChampion2->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion2->GetVehicle() &&
            !pGrandChampion3->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion3->GetVehicle())
            return true;
    }

    return false;
}

/*
* Generic AI for vehicles used by npcs in ToC, it needs more improvements.  *
* Script Complete: 25%.                                                     *
*/

class TW_generic_vehicleAI_toc5 : public CreatureScript
{
    public:
        TW_generic_vehicleAI_toc5(): CreatureScript("TW_generic_vehicleAI_toc5") {}

    struct TW_generic_vehicleAI_toc5AI : public npc_escortAI
    {
        TW_generic_vehicleAI_toc5AI(Creature* creature) : npc_escortAI(creature)
        {
            hasBeenInCombat = false;
            SetDespawnAtEnd(false);
            uiWaypointPath = 0;
            uiCheckTimer=5000;
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            combatCheckTimer = 500;
        }

        void SetData(uint32 uiType, uint32 /*uiData8*/) override
        {
            switch(uiType)
            {
                case 1:
                    AddWaypoint(0, 746.45f, 647.03f, 411.57f);
                    AddWaypoint(1, 771.434f, 642.606f, 411.9f);
                    AddWaypoint(2, 779.807f, 617.535f, 411.716f);
                    AddWaypoint(3, 771.098f, 594.635f, 411.625f);
                    AddWaypoint(4, 746.887f, 583.425f, 411.668f);
                    AddWaypoint(5, 715.176f, 583.782f, 412.394f);
                    AddWaypoint(6, 720.719f, 591.141f, 411.737f);
                    uiWaypointPath = 1;
                    break;
                case 2:
                    AddWaypoint(0, 746.45f, 647.03f, 411.57f);
                    AddWaypoint(1, 771.434f, 642.606f, 411.9f);
                    AddWaypoint(2, 779.807f, 617.535f, 411.716f);
                    AddWaypoint(3, 771.098f, 594.635f, 411.625f);
                    AddWaypoint(4, 746.887f, 583.425f, 411.668f);
                    AddWaypoint(5, 746.16f, 571.678f, 412.389f);
                    AddWaypoint(6, 746.887f, 583.425f, 411.668f);
                    uiWaypointPath = 2;
                    break;
                case 3:
                    AddWaypoint(0, 746.45f, 647.03f, 411.57f);
                    AddWaypoint(1, 771.434f, 642.606f, 411.9f);
                    AddWaypoint(2, 779.807f, 617.535f, 411.716f);
                    AddWaypoint(3, 771.098f, 594.635f, 411.625f);
                    AddWaypoint(4, 777.759f, 584.577f, 412.393f);
                    AddWaypoint(5, 772.48f, 592.99f, 411.68f);
                    uiWaypointPath = 3;
                    break;
                 case 4:
                    combatEntered = true;
                    break;
            }

            if (uiType <= 3)
                Start(false, true);
        }

        void WaypointReached(uint32 i) override
        {
            switch(i)
            {
                case 2:
                    if (uiWaypointPath == 3 || uiWaypointPath == 2)
                        instance->SetData(DATA_MOVEMENT_DONE, instance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
                case 3:
                        instance->SetData(DATA_MOVEMENT_DONE, instance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            hasBeenInCombat = true;
            DoCastSpellDefend();

            events.ScheduleEvent(EVENT_SHIELD_BREAKER, 8000);
            events.ScheduleEvent(EVENT_DEFEND, urand(30000, 60000));
            events.ScheduleEvent(EVENT_CHARGE_VEHICLE, urand(10000, 30000));
            events.ScheduleEvent(EVENT_THRUST, urand(8000, 14000));
        }

        void DoCastSpellDefend()
        {
            for(uint8 i = 0; i < 3; ++i)
                DoCast(me, SPELL_DEFEND, true);
        }

        bool StayInCombatAndCleanup(bool combat, bool cleanup)
        {
            if (me->GetMap())
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                bool foundtarget = false;

                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && player->IsAlive())
                        {
                            // Handle combat variable
                            if (combat)
                            {
                                if (combatEntered)
                                {
                                    me->SetInCombatWith(player);
                                    player->SetInCombatWith(me);
                                    me->AddThreat(player, 0.0f);

                                    foundtarget = true;

                                    if (Vehicle* pVehicle = player->GetVehicle()) // If no mounted player is found, first encounter bugs. This might cause it, needs further tests
                                    {
                                        if (Unit* vehicleCreature = pVehicle->GetBase())
                                        {
                                            me->SetInCombatWith(vehicleCreature);
                                            vehicleCreature->SetInCombatWith(me);
                                            me->AddThreat(vehicleCreature, 0.0f);
                                        }
                                    }
                                }
                            }

                            // Handle cleanup variable
                            if (cleanup)
                                if (player->HasAura(SPELL_DEFEND))
                                    player->RemoveAurasDueToSpell(SPELL_DEFEND);
                        }
                    }
                }

                if (combatEntered && combat && !foundtarget)
                {
                    me->SetFullHealth();
                    return false;
                }
            }

            return true;
        }

        void EnterEvadeMode() override
        {
            // Try to stay in combat, otherwise reset
            if (!StayInCombatAndCleanup(true, false))
                ScriptedAI::EnterEvadeMode();
        }

        bool CheckPlayersAlive()
        {
            Map* pMap = me->GetMap();
            if (pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (itr->GetSource() && itr->GetSource()->IsAlive() && !itr->GetSource()->IsGameMaster())
                        return true;
                }
            }
            return false;
        }

        void DoCastSpellShield()
        {
            for(uint8 i = 0; i < 3; ++i)
                DoCast(me, SPELL_SHIELD, true);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            // Try to keep players clean of defend aura
            if (combatEntered)
            {
                if (combatCheckTimer <= uiDiff)
                {
                    StayInCombatAndCleanup(false, true);
                    combatCheckTimer = 1000;
                } else combatCheckTimer -= uiDiff;
            }

            if (!CheckPlayersAlive())
                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                   announcer->AI()->DoAction(ACTION_RESET_GRAND_CHAMPIONS);

            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHARGE_VEHICLE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            DoResetThreat();
                            me->AddThreat(target, 5.0f);
                            DoCastVictim(SPELL_CHARGE);
                        }
                        events.ScheduleEvent(EVENT_CHARGE_VEHICLE, urand(10000, 30000));
                        break;
                    case EVENT_SHIELD_BREAKER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            if (target->GetTypeId() == TYPEID_PLAYER && me->GetDistance(target) > 10.0f && me->GetDistance(target) < 30.0f)
                            {
                                if (target->GetVehicle())
                                {
                                    if (Unit* vehTarget = target->GetVehicle()->GetBase())
                                        DoCast(vehTarget, SPELL_SHIELD_BREAKER);
                                }
                            }
                            else if (target->GetTypeId() == TYPEID_UNIT && me->GetDistance(target) > 8.0f && me->GetDistance(target) < 25.0f)
                                DoCast(target, SPELL_SHIELD_BREAKER);
                        }
                        events.ScheduleEvent(EVENT_SHIELD_BREAKER, urand(15000, 20000));
                        break;
                    case EVENT_DEFEND:
                        DoCastSpellDefend();
                        events.ScheduleEvent(EVENT_DEFEND, urand(30000, 45000));
                        break;
                    case EVENT_THRUST:
                        DoCastVictim(SPELL_THRUST);
                        events.ScheduleEvent(EVENT_THRUST, urand(8000, 14000));
                        break;
                    default:
                        break;
                }
            }
        }
    private:
        EventMap events;
        InstanceScript* instance;
        bool hasBeenInCombat;
        bool combatEntered;
        uint32 combatCheckTimer;
        uint32 uiCheckTimer;
        uint32 uiWaypointPath;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_generic_vehicleAI_toc5AI>(creature);
    }
};

// Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
class TW_boss_warrior_toc5 : public CreatureScript
{
    public:
        TW_boss_warrior_toc5(): CreatureScript("TW_boss_warrior_toc5") {}

    struct TW_boss_warrior_toc5AI : public BossAI
    {
        TW_boss_warrior_toc5AI(Creature* creature) : BossAI(creature,BOSS_GRAND_CHAMPIONS)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;
            bCredit = false;
            hasBeenInCombat = false;
        }

        InstanceScript* instance;

        uint32 uiInterceptTimer;

        bool bDone;
        bool bHome;
        bool bCredit;
        bool hasBeenInCombat;

        void Reset() override
        {
            uiInterceptTimer  = 7000;                    
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            events.SetPhase(PHASE_IDLE);
        }

        void JustReachedHome() override
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            events.ScheduleEvent(EVENT_PHASE_SWITCH, 15000, 0, PHASE_IDLE);

            bHome = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            hasBeenInCombat = true;
            events.ScheduleEvent(EVENT_BLADESTORM, urand(15000, 25000), 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(8000,12000), 0, PHASE_COMBAT);
            events.SetPhase(PHASE_COMBAT);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->GetVehicle())
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (!bDone && TW_GrandChampionsOutVehicle(me))
            {
                bDone = true;
                Talk(WARNING_WEAPONS);
                me->RemoveAura(64723); // [DND] ReadyJoust Pose Effect	

                if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 413.395f, 4.49f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                         me->SetHomePosition(746.71f, 661.02f, 412.695f, 4.6f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                         me->SetHomePosition(754.34f, 660.70f, 413.395f, 4.79f);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                EnterEvadeMode();
                bHome = true;
            }

            if (uiInterceptTimer <= uiDiff && events.GetPhaseMask() == PHASE_COMBAT)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && me->IsInRange(player, 8.0f, 25.0f, false))
                        {
                            DoResetThreat();
                            me->AddThreat(player, 5.0f);
                            DoCast(player, SPELL_INTERCEPT);
                            break;
                        }
                    }
                }
                uiInterceptTimer = 7000;
            } else uiInterceptTimer -= uiDiff;

            while (uint32 eventID = events.ExecuteEvent())
            {
                switch (eventID)
                {
                    case EVENT_BLADESTORM:
                        DoCastVictim(SPELL_BLADESTORM);
                        events.ScheduleEvent(EVENT_BLADESTORM, urand(15000, 25000), 0, PHASE_COMBAT);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(8000,12000), 0, PHASE_COMBAT);
                        break;
                    case EVENT_PHASE_SWITCH:
                        if (events.GetPhaseMask() == PHASE_IDLE)
                        {
                            TW_AggroAllPlayers(me);
                            events.SetPhase(PHASE_COMBAT);
                        }
                        break;
                }
            }
            
            if (events.GetPhaseMask() == PHASE_COMBAT)
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                hasBeenInCombat = false;
                Talk(SAY_CHAMPION_DEFEAT);

                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

                // Instance encounter counting mechanics
                if (!bCredit)
                {
                    bCredit = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_GRAND_CHAMPIONS_CREDIT);
                }

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                HandleInstanceBind(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_warrior_toc5AI>(creature);
    }
};

// Ambrose Boltspark && Eressea Dawnsinger || Mage
class TW_boss_mage_toc5 : public CreatureScript
{
    public:
        TW_boss_mage_toc5(): CreatureScript("TW_boss_mage_toc5") {}

    struct TW_boss_mage_toc5AI : public BossAI
    {
        TW_boss_mage_toc5AI(Creature* creature) : BossAI(creature, BOSS_GRAND_CHAMPIONS)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;
            bCredit = false;

            hasBeenInCombat = false;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* instance;

        bool bDone;
        bool bHome;
        bool hasBeenInCombat;
        bool bCredit;

        void Reset() override
        {
            events.SetPhase(PHASE_IDLE);
        }

        void JustReachedHome() override
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            events.ScheduleEvent(EVENT_PHASE_SWITCH, 15000, 0, PHASE_IDLE);

            bHome = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            hasBeenInCombat = true;
            events.ScheduleEvent(EVENT_FIREBALL, 5000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_POLYMORPH, 8000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_BLASTWAVE, 12000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_HASTE, 22000, 0, PHASE_COMBAT);
            events.SetPhase(PHASE_COMBAT);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->GetVehicle())
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (!bDone && TW_GrandChampionsOutVehicle(me))
            {
                bDone = true;
                me->RemoveAura(64723); // [DND] ReadyJoust Pose Effect

                if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 413.395f, 4.49f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                         me->SetHomePosition(746.71f, 661.02f, 412.695f, 4.6f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                         me->SetHomePosition(754.34f, 660.70f, 413.395f, 4.79f);
                
                instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                EnterEvadeMode();
                bHome = true;
            }

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || me->GetVehicle())
                return;

            events.Update(uiDiff);

            while (uint32 eventID = events.ExecuteEvent())
            {
                switch (eventID)
                {
                    case EVENT_FIREBALL:
                        DoCastVictim(DUNGEON_MODE(SPELL_FIREBALL,SPELL_FIREBALL_H));
                        events.ScheduleEvent(EVENT_FIREBALL, 17000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_POLYMORPH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                            DoCast(target, DUNGEON_MODE(SPELL_POLYMORPH,SPELL_POLYMORPH_H));
                        events.ScheduleEvent(EVENT_POLYMORPH, 22000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_BLASTWAVE:
                        DoCastAOE(DUNGEON_MODE(SPELL_BLAST_WAVE,SPELL_BLAST_WAVE_H),false);
                        events.ScheduleEvent(EVENT_BLADESTORM, 30000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_HASTE:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me,SPELL_HASTE);
                        events.ScheduleEvent(EVENT_HASTE, 40000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_PHASE_SWITCH:
                        if (events.GetPhaseMask() == PHASE_IDLE)
                        {
                            TW_AggroAllPlayers(me);
                            events.SetPhase(PHASE_COMBAT);
                        }
                        break;
                }
            }
            if (events.GetPhaseMask() == PHASE_COMBAT)
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                hasBeenInCombat = false;
                Talk(SAY_CHAMPION_DEFEAT);

                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

                // Instance encounter counting mechanics
                if (!bCredit)
                {
                    bCredit = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_GRAND_CHAMPIONS_CREDIT);
                }
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                HandleInstanceBind(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_mage_toc5AI>(creature);
    };
};

// Colosos && Runok Wildmane || Shaman
class TW_boss_shaman_toc5 : public CreatureScript
{
    public:
        TW_boss_shaman_toc5(): CreatureScript("TW_boss_shaman_toc5") {}

    struct TW_boss_shaman_toc5AI : public BossAI
    {
        TW_boss_shaman_toc5AI(Creature* creature) : BossAI(creature,BOSS_GRAND_CHAMPIONS)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;
            bCredit = false;
            hasBeenInCombat = false;
            
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);        
        }

        InstanceScript* instance;

        bool bDone;
        bool bHome;
        bool hasBeenInCombat;
        bool bCredit;
        uint8 chance;

        void Reset() override
        {
            events.SetPhase(PHASE_IDLE);
        }

        void EnterCombat(Unit* who) override
        {
            _EnterCombat();
            hasBeenInCombat = true;
            if (!me->GetVehicle())
            {
                DoCast(me, SPELL_EARTH_SHIELD);
                DoCast(who, SPELL_HEX_OF_MENDING);
            }
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 16000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_HEALING_WAVE, 12000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_EARTH_SHIELD, urand(30000, 35000), 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_HEX, urand(20000, 25000), 0, PHASE_COMBAT);
            events.SetPhase(PHASE_COMBAT);
        };

        void JustReachedHome() override
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            events.ScheduleEvent(EVENT_PHASE_SWITCH, 15000, 0, PHASE_IDLE);

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->GetVehicle())
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (!bDone && TW_GrandChampionsOutVehicle(me))
            {
                bDone = true;

                me->RemoveAura(64723); // [DND] ReadyJoust Pose Effect

                if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,413.395f,4.49f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                         me->SetHomePosition(746.71f,661.02f,412.695f,4.6f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                         me->SetHomePosition(754.34f,660.70f,413.395f,4.79f);

                instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || me->GetVehicle())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EARTH_SHIELD:
                        DoCast(me, SPELL_EARTH_SHIELD);
                        events.ScheduleEvent(EVENT_EARTH_SHIELD, urand(40000,45000), 0, PHASE_COMBAT);
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                            DoCast(target, DUNGEON_MODE(SPELL_CHAIN_LIGHTNING, SPELL_CHAIN_LIGHTNING_H));
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 23000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_HEALING_WAVE:
                        chance = urand(0,1);
                        if (chance == 0)
                        {
                            if (Unit* pFriend = DoSelectLowestHpFriendly(40))
                                DoCast(pFriend,DUNGEON_MODE(SPELL_HEALING_WAVE, SPELL_HEALING_WAVE_H));
                        } else
                            DoCast(me,DUNGEON_MODE(SPELL_HEALING_WAVE, SPELL_HEALING_WAVE_H));
                        events.ScheduleEvent(EVENT_HEALING_WAVE, 19000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_HEX:
                        DoCastVictim(SPELL_HEX_OF_MENDING, true);
                        events.ScheduleEvent(EVENT_HEX, urand(30000,35000), 0, PHASE_COMBAT);
                        break;
                    case EVENT_PHASE_SWITCH:
                        if (events.GetPhaseMask() == PHASE_IDLE)
                        {
                            TW_AggroAllPlayers(me);
                            events.SetPhase(PHASE_COMBAT);
                        }
                        break;
                }
            }
            
            if (events.GetPhaseMask() == PHASE_COMBAT)
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                hasBeenInCombat = false;
                Talk(SAY_CHAMPION_DEFEAT);

                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

                // Instance encounter counting mechanics
                if (!bCredit)
                {
                    bCredit = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_GRAND_CHAMPIONS_CREDIT);
                }
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                HandleInstanceBind(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_shaman_toc5AI>(creature);
    }
};

// Jaelyne Evensong && Zul'tore || Hunter
class TW_boss_hunter_toc5 : public CreatureScript
{
    public:
        TW_boss_hunter_toc5(): CreatureScript("TW_boss_hunter_toc5") {}

    struct TW_boss_hunter_toc5AI : public BossAI
    {
        TW_boss_hunter_toc5AI(Creature* creature) : BossAI(creature, BOSS_GRAND_CHAMPIONS)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;
            hasBeenInCombat = false;
            bCredit = false;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* instance;

        ObjectGuid uiTargetGUID;

        bool bShoot;
        bool bDone;
        bool bHome;
        bool hasBeenInCombat;
        bool bCredit;

        void Reset() override
        {
            uiTargetGUID.Clear();

            bShoot = false;

            Map* pMap = me->GetMap();
            if (hasBeenInCombat && pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (itr->GetSource() && itr->GetSource()->IsAlive() && !itr->GetSource()->IsGameMaster())
                        return;
                }

                instance->SetData(BOSS_GRAND_CHAMPIONS, NOT_STARTED);

                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(), true);

                me->RemoveFromWorld();
                events.SetPhase(PHASE_IDLE);
            }
        }

        void JustReachedHome() override
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            events.ScheduleEvent(EVENT_PHASE_SWITCH, 15000, 0, PHASE_IDLE);

            bHome = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            hasBeenInCombat = true;
            events.ScheduleEvent(EVENT_SHOOT, 12000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_LIGHTNING_ARROWS, 7000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_DISENGAGE, 10000, 0, PHASE_COMBAT);
            events.SetPhase(PHASE_COMBAT);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->GetVehicle())
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (!bDone && TW_GrandChampionsOutVehicle(me))
            {
                bDone = true;

                me->RemoveAura(64723); // [DND] ReadyJoust Pose Effect

                if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,413.395f,4.49f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                         me->SetHomePosition(746.71f,661.02f,412.695f,4.6f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                         me->SetHomePosition(754.34f,660.70f,413.395f,4.79f);

                instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || me->GetVehicle())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHOOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 30.0f))
                        {
                            uiTargetGUID = target->GetGUID();
                            DoCast(target, DUNGEON_MODE(SPELL_SHOOT, SPELL_SHOOT_H));
                        }
                        bShoot = true;
                        events.ScheduleEvent(EVENT_SHOOT, 19000, 0, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_MULTI_SHOOT, 8000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_MULTI_SHOOT:
                        if (bShoot)
                        {
                            me->InterruptNonMeleeSpells(true);
                            Unit* target = ObjectAccessor::GetUnit(*me, uiTargetGUID);

                            if (target && me->IsInRange(target, 5.0f, 30.0f, false))
                                DoCast(target, SPELL_MULTI_SHOT);
                            else
                            {
                                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                                {
                                    for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                    {
                                        Player* player = itr->GetSource();
                                        if (player && me->IsInRange(player, 5.0f, 30.0f, false))
                                        {
                                            DoCast(target, SPELL_MULTI_SHOT);
                                            break;
                                        }
                                    }
                                }
                            }
                            bShoot = false;
                        }
                        break;
                    case EVENT_DISENGAGE: 
                        if (me->IsWithinDistInMap(me->GetVictim(), 5))
                        {
                            DoCast(me, SPELL_DISENGAGE);
                            events.ScheduleEvent(EVENT_DISENGAGE, 20000, 0, PHASE_COMBAT);
                        }
                        else
                            events.ScheduleEvent(EVENT_DISENGAGE, 10000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_LIGHTNING_ARROWS:
                        DoCastAOE(SPELL_LIGHTNING_ARROWS, false);
                        events.ScheduleEvent(EVENT_LIGHTNING_ARROWS, 15000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_PHASE_SWITCH:
                        if (events.GetPhaseMask() == PHASE_IDLE)
                        {
                            TW_AggroAllPlayers(me);
                            events.SetPhase(PHASE_COMBAT);
                        }
                        break;
                }
            }
            if (events.GetPhaseMask() == PHASE_COMBAT)
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                hasBeenInCombat = false;
                Talk(SAY_CHAMPION_DEFEAT);

                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

                // Instance encounter counting mechanics
                if (!bCredit)
                {
                    bCredit = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_GRAND_CHAMPIONS_CREDIT);
                }
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->GetMotionMaster()->MovePoint(0, 746.843f, 695.68f, 412.339f);
                HandleInstanceBind(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_hunter_toc5AI>(creature);
    }
};

// Lana Stouthammer Evensong && Deathstalker Visceri || Rogue
class TW_boss_rogue_toc5 : public CreatureScript
{
    public:
        TW_boss_rogue_toc5(): CreatureScript("TW_boss_rogue_toc5") {}

    struct TW_boss_rogue_toc5AI : public BossAI
    {
        TW_boss_rogue_toc5AI(Creature* creature) : BossAI(creature,BOSS_GRAND_CHAMPIONS)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;
            bCredit = false;

            hasBeenInCombat = false;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* instance;

        bool bDone;
        bool bHome;
        bool hasBeenInCombat;
        bool bCredit;

        void Reset() override
        {

            Map* pMap = me->GetMap();

            if (hasBeenInCombat && pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (itr->GetSource() && itr->GetSource()->IsAlive() && !itr->GetSource()->IsGameMaster())
                        return;
                }

                instance->SetData(BOSS_GRAND_CHAMPIONS, NOT_STARTED);

                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(gate->GetGUID(),true);

                events.SetPhase(PHASE_IDLE);
                me->RemoveFromWorld();
            }
        }

        void JustReachedHome() override
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            events.ScheduleEvent(EVENT_PHASE_SWITCH, 15000, 0, PHASE_IDLE);

            bHome = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            hasBeenInCombat = true;
            events.ScheduleEvent(EVENT_EVISCERATE, 8000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 14000, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_POISON_BOTTLE, 19000, 0, PHASE_COMBAT);
            events.SetPhase(PHASE_COMBAT);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->GetVehicle())
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (!bDone && TW_GrandChampionsOutVehicle(me))
            {
                bDone = true;

                me->RemoveAura(64723); // [DND] ReadyJoust Pose Effect

                if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,413.395f,4.49f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                         me->SetHomePosition(746.71f,661.02f,412.695f,4.6f);
                else if (me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                         me->SetHomePosition(754.34f,660.70f,413.395f,4.79f);

                instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                EnterEvadeMode();
                bHome = true;
            }

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || me->GetVehicle())
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EVISCERATE:
                        DoCast(me->GetVictim(),DUNGEON_MODE(SPELL_EVISCERATE, SPELL_EVISCERATE_H));
                        events.ScheduleEvent(EVENT_EVISCERATE, 12000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_FAN_OF_KNIVES:
                        DoCastAOE(SPELL_FAN_OF_KNIVES, false);
                        events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 20000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_POISON_BOTTLE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_POISON_BOTTLE);
                        events.ScheduleEvent(EVENT_POISON_BOTTLE, 19000, 0, PHASE_COMBAT);
                        break;
                    case EVENT_PHASE_SWITCH:
                        if (events.GetPhaseMask() == PHASE_IDLE)
                        {
                            TW_AggroAllPlayers(me);
                            events.SetPhase(PHASE_COMBAT);
                        }
                        break;
                }
            }
            if (events.GetPhaseMask() == PHASE_COMBAT)
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                hasBeenInCombat = false;
                Talk(SAY_CHAMPION_DEFEAT);

                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

                // Instance encounter counting mechanics
                if (!bCredit)
                {
                    bCredit = true;
                    HandleSpellOnPlayersInInstanceToC5(me, SPELL_GRAND_CHAMPIONS_CREDIT);
                }
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->GetMotionMaster()->MovePoint(0, 746.843f, 695.68f, 412.339f);
                HandleInstanceBind(me);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetTWTrialOfTheChampionAI<TW_boss_rogue_toc5AI>(creature);
    }
};

class TW_achievement_toc5_grand_champions : public AchievementCriteriaScript
{
    public:
        uint32 creature_entry;

        TW_achievement_toc5_grand_champions(const char* name, uint32 original_entry) : AchievementCriteriaScript(name) 
        {
            creature_entry = original_entry;
        }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* creature = target->ToCreature())
                if (creature->GetEntry() == creature_entry)
                    return true;

            return false;
        }
};

void HandleInstanceBind(Creature* source)
{
    Map::PlayerList const& players = source->GetMap()->GetPlayers();
    if (!players.isEmpty() && source->GetMap()->ToInstanceMap()->IsHeroic())
    {
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = itr->GetSource();
            if (player)
                source->GetMap()->ToInstanceMap()->PermBindAllPlayers(player);
        }
    }
}

void AddSC_TW_boss_grand_champions()
{
    new TW_generic_vehicleAI_toc5();
    new TW_boss_warrior_toc5();
    new TW_boss_mage_toc5();
    new TW_boss_shaman_toc5();
    new TW_boss_hunter_toc5();
    new TW_boss_rogue_toc5();
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_mokra", NPC_MOKRA);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_eressea", NPC_ERESSEA);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_runok", NPC_RUNOK);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_zultore", NPC_ZULTORE);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_visceri", NPC_VISCERI);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_alerius", NPC_JACOB);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_ambrose", NPC_AMBROSE);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_colosos", NPC_COLOSOS);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_jaelyne", NPC_JAELYNE);
    new TW_achievement_toc5_grand_champions("TW_achievement_toc5_champions_lana", NPC_LANA);
};