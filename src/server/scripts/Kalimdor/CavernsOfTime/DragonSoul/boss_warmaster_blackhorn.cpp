/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
*
* Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_warmaster_blackhorn
Author: Bennu
SD%Complete: 80%
SDComment: TODO: Heroic Mode , some cosmetic stuff
SDCategory: Boss Warmaster Blackhorn
EndScriptData
*/

#include "ScriptMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Vehicle.h"
#include "dragon_soul.h"

enum Events
{
    // Blackhorn
    EVENT_ENGAGE = 1,
    EVENT_DEVASTATE,
    EVENT_DISRUPTING_ROAR,
    EVENT_SHOCKWAVE,
    EVENT_BERSERK,

    // Commander
    EVENT_SUMMON_DRAKES,
    EVENT_SUMMON_INFILTRATOR,
    EVENT_BOSS,
    EVENT_DRAKE_CHECK,

    // Twilight Elite slayer and Dreadblades
    EVENT_BLADE_RUSH,
    EVENT_DEGENERATION,
    EVENT_BRUTAL_STRIKE,

    // Twilight Assault Drake
    EVENT_TWILIGHT_BARRAGE,
    EVENT_BREAK_HARPOON,

    // Goriona
    EVENT_PHASE_2,
    EVENT_TWILIGHT_ONSLAUGHT,
    EVENT_TWILIGHT_FLAMES,
    EVENT_DISMONT_BOSS,
    EVENT_GORIONA_LAND,
    EVENT_TWILIGHT_BREATH,
    EVENT_CONSUMING_SHROUD,
    EVENT_BROADSIDE,

    // Twilight Sapper
    EVENT_LAND,
    EVENT_APPEAR,

    // Harpoon and cannon
    EVENT_HARPOON,
    EVENT_RELOAD,
    EVENT_ARTILLERY_BARRAGE,

    // Heroic mode
    EVENT_SHIP_FIRE,
    EVENT_FIRE_DAMAGE,
    EVENT_SKYFIRE_BRIGADE,
    EVENT_MOVE,
    EVENT_WATER_JET,
};

enum Actions
{
    ACTION_START_FIGHT = 0,
    ACTION_SAPPER,
    ACTION_RELOAD,
    ACTION_HARPOON,
    ACTION_PHASE_2,
    ACTION_ENGAGE,
    ACTION_HARPOON_DEATH,
};

enum Spells
{
    // Warmaster Blackhorn
    SPELL_DEVASTATE                  = 108042,
    SPELL_DISRUPTING_ROAR            = 108044,
    SPELL_SHOCKWAVE                  = 108046,
    SPELL_SIPHON_VITALITY            = 110312,
    SPELL_SIPHON_VITALITY_DUMMY     = 110315,
    SPELL_SUNDER_ARMOR               = 108043,
    SPELL_VENGEANCE                  = 108045,
    SPELL_BERSERK                    = 26662,

    // Twilight Elite slayer and Dreadblades
    SPELL_BLADE_RUSH                 = 107594,
    SPELL_DEGENERATION               = 107558,
    SPELL_BRUTAL_STRIKE              = 107567,

    // Twilight Assault Drake
    SPELL_TWILIGHT_BARRAGE           = 107286,
    SPELL_TWILIGHT_BARRAGE_SKYFIRE   = 107501,

    // Twilight Sapper
    SPELL_EVADE                      = 107761,
    SPELL_DETONATE                   = 107518,

    // Goriona
    SPELL_TWILIGHT_ONSLAUGHT_AURA    = 107927,
    SPELL_TWILIGHT_ONSLAUGHT         = 107588,
    SPELL_TWILIGHT_ONSLAUGHT_SKYFIRE = 107589,
    SPELL_TWILIGHT_FLAMES            = 108050,
    SPELL_TWILIGHT_BREATH            = 110212,
    SPELL_CONSUMING_SHROUD           = 110214,
    SPELL_CONSUMING_SHROUD_DAMAGE    = 110215,
    SPELL_BROADSIDE                  = 110153,
    SPELL_BROADSIDE_DAMAGE           = 110157,

    // Harpoon and cannon
    SPELL_HARPOON                    = 108038,
    SPELL_RELOADING                  = 108039,
    SPELL_ARTILLERY_BARRAGE          = 108040,
    SPELL_HEAVY_SLUG                 = 108010,

    // Misc
    SPELL_ENGINE_DAMAGED             = 109470,
    SPELL_ENGINE_FIRE                = 107799,
    SPELL_MASSIVE_EXPLOSION          = 108132,
    SPELL_SHIP_FIRE                  = 109245,
    SPELL_FIRE_DAMAGE                = 110095,
    SPELL_WATER_JET                  = 110061,

};

enum ScriptedTexts
{
    SAY_SWAYZE_INTRO    = 0,
    SAY_SWAYZE_INTRO_1  = 1,
    SAY_AGGRO           = 0,
    SAY_DEATH           = 1,
    SAY_INTRO           = 2,
    SAY_SLAY            = 3,
    SAY_SHOCK           = 4,
};

#define GOSSIP_ITEM_SWAYZE_HORDE_0 "We are the Horde. We are always ready."
#define GOSSIP_ITEM_SWAYZE_ALLIANCE_0 "We are the Alliance. We are always ready."
#define GOSSIP_ITEM_SWAYZE_1 "Bring us in closer!"
#define GOSSIP_ITEM_SWAYZE_HORDE_2 "FOR THE HORDE!"
#define GOSSIP_ITEM_SWAYZE_ALLIANCE_2 "JUSTICE AND GLORY!"

Position const sapperPos = { 13474.66f, -12134.19f, 150.80f, 2.81f };

Position const gorionaPos[] =
{
    { 13403.83f, -12165.28f, 191.57f, 0.80f },
    { 13422.77f, -12092.32f, 167.40f, 4.46f },
};

Position const drakePos[] =
{
    { 13537.41f, -12171.54f, 172.12f, 2.98f },
    { 13534.15f, -12103.88f, 175.44f, 3.14f },
    { 13384.00f, -12130.89f, 174.32f, 6.22f },
};

Position const barragePos[] =
{
    { 13437.4f, -12126.9f, 150.786f },
    { 13422.4f, -12136.9f, 150.918f },
    { 13422.4f, -12126.9f, 150.883f },
    { 13447.4f, -12141.9f, 150.855f },
    { 13427.4f, -12141.9f, 150.870f },
    { 13452.4f, -12131.9f, 150.842f },
    { 13432.4f, -12136.9f, 150.917f },
    { 13442.4f, -12141.9f, 150.840f },
    { 13437.4f, -12121.9f, 150.773f },
    { 13437.4f, -12126.9f, 150.786f },
    { 13422.4f, -12136.9f, 150.918f },
    { 13422.4f, -12126.9f, 150.883f },
    { 13447.4f, -12141.9f, 150.855f },
    { 13427.4f, -12141.9f, 150.870f },
    { 13452.4f, -12131.9f, 150.842f },
    { 13432.4f, -12136.9f, 150.917f },
    { 13442.4f, -12141.9f, 150.840f },
    { 13437.4f, -12121.9f, 150.773f },
};

Position const firePos[] =
{
    { 13450.7f, -12126.8f, 150.838f },
    { 13450.1f, -12133.0f, 151.047f },
    { 13449.5f, -12140.4f, 150.835f },
    { 13449.0f, -12148.5f, 150.822f },
    { 13456.5f, -12149.4f, 151.189f },
    { 13457.1f, -12142.2f, 151.065f },
    { 13458.0f, -12127.6f, 150.970f },
    { 13457.7f, -12135.0f, 151.055f },
    { 13466.3f, -12120.0f, 151.183f },
    { 13458.6f, -12119.5f, 150.849f },
    { 13465.8f, -12128.4f, 151.176f },
    { 13465.6f, -12135.8f, 151.173f },
    { 13464.9f, -12145.8f, 151.180f },
    { 13436.4f, -12114.6f, 151.072f },
    { 13442.8f, -12130.9f, 150.836f },
    { 13442.2f, -12137.6f, 150.827f },
    { 13451.5f, -12120.1f, 150.831f },
    { 13444.0f, -12115.9f, 150.794f },
    { 13443.0f, -12123.8f, 150.817f },
    { 13435.2f, -12128.8f, 151.186f },
    { 13436.4f, -12122.1f, 150.976f },
    { 13429.8f, -12115.5f, 150.779f },
    { 13434.3f, -12143.5f, 151.186f },
    { 13434.2f, -12136.2f, 151.198f },
    { 13441.5f, -12145.1f, 150.801f },
    { 13435.6f, -12150.7f, 150.757f },
    { 13429.5f, -12122.3f, 150.838f },
    { 13429.0f, -12129.1f, 150.893f },
    { 13426.6f, -12136.1f, 150.891f },
    { 13426.4f, -12142.6f, 150.844f },
    { 13426.3f, -12150.4f, 150.857f },
    { 13418.0f, -12145.7f, 151.041f },
    { 13419.2f, -12138.3f, 151.170f },
    { 13419.6f, -12131.0f, 151.169f },
    { 13420.3f, -12124.5f, 151.159f },
    { 13421.1f, -12115.2f, 150.939f },
};

Position const brigadePos[] =
{
    { 13450.7f, -12126.8f, 160.838f },
    { 13450.1f, -12133.0f, 161.047f },
    { 13449.5f, -12140.4f, 160.835f },
    { 13449.0f, -12148.5f, 160.822f },
    { 13456.5f, -12149.4f, 161.189f },
    { 13457.1f, -12142.2f, 161.065f },
    { 13458.0f, -12127.6f, 160.970f },
    { 13457.7f, -12135.0f, 161.055f },
    { 13466.3f, -12120.0f, 161.183f },
    { 13458.6f, -12119.5f, 160.849f },
    { 13465.8f, -12128.4f, 161.176f },
    { 13465.6f, -12135.8f, 161.173f },
    { 13464.9f, -12145.8f, 161.180f },
    { 13436.4f, -12114.6f, 161.072f },
    { 13442.8f, -12130.9f, 160.836f },
    { 13442.2f, -12137.6f, 160.827f },
    { 13451.5f, -12120.1f, 160.831f },
    { 13444.0f, -12115.9f, 160.794f },
    { 13443.0f, -12123.8f, 160.817f },
    { 13435.2f, -12128.8f, 161.186f },
    { 13436.4f, -12122.1f, 160.976f },
    { 13429.8f, -12115.5f, 160.779f },
    { 13434.3f, -12143.5f, 161.186f },
    { 13434.2f, -12136.2f, 161.198f },
    { 13441.5f, -12145.1f, 160.801f },
    { 13435.6f, -12150.7f, 160.757f },
    { 13429.5f, -12122.3f, 160.838f },
    { 13429.0f, -12129.1f, 160.893f },
    { 13426.6f, -12136.1f, 160.891f },
    { 13426.4f, -12142.6f, 160.844f },
    { 13426.3f, -12150.4f, 160.857f },
    { 13418.0f, -12145.7f, 161.041f },
    { 13419.2f, -12138.3f, 161.170f },
    { 13419.6f, -12131.0f, 161.169f },
    { 13420.3f, -12124.5f, 161.159f },
    { 13421.1f, -12115.2f, 150.939f },
};

class boss_warmaster_blackhorn : public CreatureScript
{
public:
    boss_warmaster_blackhorn() : CreatureScript("boss_warmaster_blackhorn") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_warmaster_blackhornAI(creature);
    }

    struct boss_warmaster_blackhornAI: public BossAI
    {
        boss_warmaster_blackhornAI(Creature* creature) : BossAI(creature, DATA_BLACKHORN)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        float ori;
        Position pos;

        void Reset() override
        {
            _Reset();
            me->DespawnOrUnsummon();
        }

        void InitializeAI() override
        {
            Talk(SAY_INTRO);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoCast(me, SPELL_VENGEANCE);
            _EnterCombat();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_ENGAGE:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);

                events.ScheduleEvent(EVENT_ENGAGE, 3000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (IsHeroic())
                if (me->HealthAbovePct(20) && (me->GetMaxHealth() *0.2f) > (me->GetHealth() - damage))
                    if (Creature* goriona = me->FindNearestCreature(NPC_GORIONA, 500.0f, true))
                        DoCast(goriona, SPELL_SIPHON_VITALITY_DUMMY);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ENGAGE:

                    events.ScheduleEvent(EVENT_BERSERK, 240000);
                    events.ScheduleEvent(EVENT_DISRUPTING_ROAR, 18000);
                    events.ScheduleEvent(EVENT_SHOCKWAVE, 23000);
                    events.ScheduleEvent(EVENT_DEVASTATE, 15000);
                    break;

                case EVENT_DISRUPTING_ROAR:
                    DoCast(me, SPELL_DISRUPTING_ROAR);

                    events.ScheduleEvent(EVENT_DISRUPTING_ROAR, 18000);
                    break;

                case EVENT_SHOCKWAVE:
                    Talk(SAY_SHOCK);
                    if (Unit* rand = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        pos = rand->GetPosition();
                        if (Creature* target = me->SummonCreature(NPC_SHOCKWAVE_TARGET, pos, TEMPSUMMON_TIMED_DESPAWN, 10000))
                        {
                            me->SetFacingToObject(target);
                            DoCast(target, SPELL_SHOCKWAVE);
                        }
                    }

                    events.ScheduleEvent(EVENT_SHOCKWAVE, 23000);
                    break;

                case EVENT_DEVASTATE:
                    DoCastVictim(SPELL_DEVASTATE);

                    events.ScheduleEvent(EVENT_DEVASTATE, 15000);
                    break;

                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    break;
                }
            }
                DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            Talk(SAY_DEATH);
            instance->SetBossState(DATA_BLACKHORN, DONE);
            killer->SummonCreature(NPC_TRAVEL_TO_MAELSTORM, 13405.485f, -12131.544f, 150.971f, 6.213f, TEMPSUMMON_CORPSE_DESPAWN, 600000);
            _JustDied();
        }
    };
};

class npc_goriona : public CreatureScript
{
public:
    npc_goriona() : CreatureScript("npc_goriona") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gorionaAI(creature);
    }

    struct npc_gorionaAI : public ScriptedAI
    {
        npc_gorionaAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        Vehicle* vehicle;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            DoZoneInCombat(me);

            if (IsHeroic())
                events.ScheduleEvent(EVENT_BROADSIDE, 60000);

            events.ScheduleEvent(EVENT_TWILIGHT_ONSLAUGHT, 48000);
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (IsHeroic())
                if (me->HealthAbovePct(80) && (me->GetMaxHealth() *0.8f) > (me->GetHealth() - damage))
                    events.ScheduleEvent(EVENT_GORIONA_LAND, 1000);

                if (me->HealthAbovePct(25) && (me->GetMaxHealth() *0.25f) > (me->GetHealth() - damage))
                {
                    events.Reset();
                    me->GetMotionMaster()->MovePoint(0, gorionaPos[0]);
                    me->SetVisible(false);
                    me->DespawnOrUnsummon(300000);
                }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_PHASE_2:
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, NPC_FIRE_STALKER, 500.0f);
                GetCreatureListWithEntryInGrid(creatures, me, NPC_SKYFIRE_BRIGADE, 500.0f);

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->DespawnOrUnsummon();

                me->GetMotionMaster()->MovePoint(0, gorionaPos[1]);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                events.CancelEvent(EVENT_BROADSIDE);
                events.CancelEvent(EVENT_TWILIGHT_ONSLAUGHT);
                events.ScheduleEvent(EVENT_DISMONT_BOSS, 3000);
                events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 8000);
            }
                break;
            }
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TWILIGHT_ONSLAUGHT:
                {
                    std::list<Creature*> unitList;
                    me->GetCreatureListWithEntryInGrid(unitList, NPC_ONSLAUGHT_TARGET, 100.0f);
                    Trinity::Containers::RandomResize(unitList, 1);
                    if (Creature* target = Trinity::Containers::SelectRandomContainerElement(unitList))
                    {
                        pos = target->GetHomePosition();
                        me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_TWILIGHT_ONSLAUGHT, false);
                        target->CastSpell(target, SPELL_TWILIGHT_ONSLAUGHT_AURA);
                    }
                        events.ScheduleEvent(EVENT_TWILIGHT_ONSLAUGHT, 35000);
                }
                    break;

                case EVENT_DISMONT_BOSS:
                    if (Unit* pass = vehicle->GetPassenger(0))
                        pass->ExitVehicle();

                    if (Creature* blackhorn = me->FindNearestCreature(NPC_BLACKHORN, 100.0f, true))
                        blackhorn->AI()->DoAction(ACTION_ENGAGE);
                    break;

                case EVENT_TWILIGHT_FLAMES:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    {
                        me->SetFacingToObject(target);
                        DoCast(target, SPELL_TWILIGHT_FLAMES);
                    }

                    events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 8000);
                    break;

                case EVENT_BROADSIDE:
                    DoCast(me, SPELL_BROADSIDE);
                    DoCast(me, SPELL_BROADSIDE_DAMAGE);

                    events.ScheduleEvent(EVENT_BROADSIDE, 60000);
                    break;

                case EVENT_GORIONA_LAND:
                    events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 20000);
                    events.ScheduleEvent(EVENT_CONSUMING_SHROUD, 25000);
                    events.CancelEvent(EVENT_TWILIGHT_FLAMES);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;

                case EVENT_TWILIGHT_BREATH:
                    DoCast(me, SPELL_TWILIGHT_BREATH);

                    events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 20000);
                    break;

                case EVENT_CONSUMING_SHROUD:
                    DoCast(me, SPELL_CONSUMING_SHROUD);

                    events.ScheduleEvent(EVENT_CONSUMING_SHROUD, 25000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};


class npc_sky_captain_swayze : public CreatureScript
{
    public:
        npc_sky_captain_swayze() : CreatureScript("npc_sky_captain_swayze") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sky_captain_swayzeAI(creature);
        }

        struct npc_sky_captain_swayzeAI : public ScriptedAI
        {
            npc_sky_captain_swayzeAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
                waveCounter = 0;
            }

            InstanceScript* instance;
            EventMap events;
            SummonList summons;
            Position pos;
            int32 currentFire;
            uint8 waveCounter;

            void DoAction(int32 action) override
            {
                switch (action)
                {
                case ACTION_START_FIGHT:
                    currentFire = urand(0, 35);

                    events.ScheduleEvent(EVENT_SUMMON_DRAKES, 20000);
                    events.ScheduleEvent(EVENT_SUMMON_INFILTRATOR, 70000);
                    events.ScheduleEvent(EVENT_BOSS, 10000);

                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_SHIP_FIRE, 45000);
                        events.ScheduleEvent(EVENT_SKYFIRE_BRIGADE, 48000);
                    }
                    break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void UpdateAI(uint32 diff) override

            {
                std::list<Player*> targets;
                me->GetPlayerListInGrid(targets, 500.0f);

                if (targets.empty())
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    summons.DespawnAll();
                    events.Reset();
                    waveCounter = 0;

                    if (Creature* skyfire = me->FindNearestCreature(NPC_THE_SKYFIRE, 100.0f, true))
                    {
                        skyfire->setRegeneratingHealth(true);
                        skyfire->AI()->EnterEvadeMode();
                    }
                }

                if (instance->GetBossState(DATA_BLACKHORN) == DONE)
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_SUMMON_DRAKES:
                        waveCounter++;
                        me->SummonCreature(NPC_TWILIGHT_ASSAULT_DRAKE, drakePos[0], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_TWILIGHT_ASSAULT_DRAKE_2, drakePos[1], TEMPSUMMON_MANUAL_DESPAWN);

                        if (waveCounter <= 2)
                        {
                            events.ScheduleEvent(EVENT_SUMMON_DRAKES, 55000);
                        }
                        else if (waveCounter > 2)
                        {
                            events.ScheduleEvent(EVENT_DRAKE_CHECK, 1000);
                        }
                        break;

                    case EVENT_SUMMON_INFILTRATOR:
                        me->SummonCreature(NPC_TWILIGHT_INFILTRATOR, drakePos[2], TEMPSUMMON_MANUAL_DESPAWN);

                        events.ScheduleEvent(EVENT_SUMMON_INFILTRATOR, 40000);
                        break;

                    case EVENT_BOSS:
                    {
                        Talk(SAY_SWAYZE_INTRO_1);
                        me->SummonCreature(NPC_GORIONA, gorionaPos[0], TEMPSUMMON_MANUAL_DESPAWN);

                        std::list<Creature*> stalkers;
                        me->GetCreatureListWithEntryInGrid(stalkers, NPC_ENGINE_STALKER, 200.0f);
                        for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                        {
                            (*itr)->CastSpell(*itr, SPELL_ENGINE_DAMAGED);
                            (*itr)->CastSpell(*itr, SPELL_ENGINE_FIRE);
                        }
                    }
                        break;

                    case EVENT_DRAKE_CHECK:
                    {
                        if (Creature* drake = me->FindNearestCreature(NPC_TWILIGHT_ASSAULT_DRAKE, 500.0f, true))
                            events.ScheduleEvent(EVENT_DRAKE_CHECK, 1000);
                        else if (Creature* drake2 = me->FindNearestCreature(NPC_TWILIGHT_ASSAULT_DRAKE_2, 500.0f, true))
                            events.ScheduleEvent(EVENT_DRAKE_CHECK, 1000);
                        else if (Creature* goriona = me->FindNearestCreature(NPC_GORIONA, 500.0f, true))
                        {
                            goriona->AI()->DoAction(ACTION_PHASE_2);
                            events.CancelEvent(EVENT_SUMMON_INFILTRATOR);

                            if (IsHeroic())
                            {
                                events.CancelEvent(EVENT_SHIP_FIRE);
                                events.CancelEvent(EVENT_SKYFIRE_BRIGADE);
                            }
                        }
                    }
                        break;
                    case EVENT_SHIP_FIRE:
                    {
                        pos = firePos[currentFire];
                        currentFire++;
                        if (Creature* deckfire = me->FindNearestCreature(NPC_FIRE_STALKER, 200.0f, true))
                        {
                            std::list<Creature*> fire;


                            if (currentFire >= 36)
                                currentFire = 0;

                            me->GetCreatureListWithEntryInGrid(fire, NPC_FIRE_STALKER, 500.0f);
                            me->SummonCreature(NPC_FIRE_STALKER, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), me->GetOrientation());

                            for (std::list<Creature*>::iterator itr = fire.begin(); itr != fire.end(); ++itr)
                                (*itr)->CastSpell((*itr), SPELL_SHIP_FIRE);
                        }
                        else
                            me->SummonCreature(NPC_FIRE_STALKER, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        events.ScheduleEvent(EVENT_SHIP_FIRE, 3000);
                    }
                        break;

                    case EVENT_SKYFIRE_BRIGADE:
                        for (int32 x = 0; x <= 1; x++)
                            me->SummonCreature(NPC_SKYFIRE_BRIGADE, brigadePos[x], TEMPSUMMON_MANUAL_DESPAWN);
                        break;
                    default:
                        break;
                    }
                }
            }
        };

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->FindNearestGameObject(GO_ALLIANCE_SHIP_1, 300.0f))
            {
                if (player->GetTeam() == ALLIANCE)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SWAYZE_ALLIANCE_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                else
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SWAYZE_HORDE_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, 18870, creature->GetGUID());
            }
            else
            {
                if (InstanceScript* instance = creature->GetInstanceScript())
                    if (instance->GetBossState(DATA_BLACKHORN) == DONE)
                    {
                        if (player->GetTeam() == ALLIANCE)
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SWAYZE_ALLIANCE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2, "Do you want to start the encounter?", 0, false);
                        else
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SWAYZE_HORDE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2, "Do you want to start the encounter?", 0, false);
                        SendGossipMenuFor(player, 18872, creature->GetGUID());
                    }
                    else
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SWAYZE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1, "Do you want to start the encounter?", 0, false);
                        SendGossipMenuFor(player, 18871, creature->GetGUID());
                    }
            }

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();
            CloseGossipMenuFor(player);
            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF:
            {
                std::list<Player*> targets;
                creature->GetPlayerListInGrid(targets, 80.0f);
                for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    (*itr)->TeleportTo(967, 13444.9f, -12133.3f, 151.21f, 0.0f);
            }
                break;

            case GOSSIP_ACTION_INFO_DEF + 1:
            {
                creature->AI()->Talk(SAY_SWAYZE_INTRO);
                creature->AI()->DoAction(ACTION_START_FIGHT);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                std::list<Creature*> Harpoons;
                creature->GetCreatureListWithEntryInGrid(Harpoons, NPC_SKYFIRE_HARPOON_GUN, 200.0f);
                for (std::list<Creature*>::iterator itr = Harpoons.begin(); itr != Harpoons.end(); ++itr)
                {
                    (*itr)->AI()->DoAction(ACTION_HARPOON);
                }
            }
                break;

            case GOSSIP_ACTION_INFO_DEF + 2:
            {
                if (InstanceScript* instance = creature->GetInstanceScript())
                {

                    std::list<Player*> targets;
                    creature->GetPlayerListInGrid(targets, 80.0f);
                    for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        if (instance->GetBossState(DATA_SPINE) == DONE)
                        {
                            (*itr)->TeleportTo(967, -12081.390625f, 12160.050781f, 30.60f, 6.03f);
                            (*itr)->CastSpell(*itr, SPELL_PARACHUTE);
                        }
                        else
                        {
                            (*itr)->TeleportTo(967, -13852.5f, -13665.38f, 297.3786f, 1.53589f);
                            (*itr)->CastSpell(*itr, SPELL_PARACHUTE);
                            creature->CastSpell(creature, SPELL_PLAY_MOVIE_DEATHWING_2);
                        }
                    }
                }
            }
                break;
            }
            return true;
        }
};

class npc_twilight_assault_drake : public CreatureScript
{
    public:
        npc_twilight_assault_drake() : CreatureScript("npc_twilight_assault_drake") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_twilight_assault_drakeAI(creature);
        }

        struct npc_twilight_assault_drakeAI : public npc_escortAI
        {
            npc_twilight_assault_drakeAI(Creature* creature) : npc_escortAI(creature), vehicle(creature->GetVehicleKit())
            {
                npc_escortAI::SetDespawnAtEnd(false);
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            Vehicle* vehicle;
            Position pos;

            void InitializeAI() override
            {
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_FLIGHT, 2.2f);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoZoneInCombat(me);
                Start(true, true);
            }

            void SpellHit(Unit*, const SpellInfo* spell)
            {
                if (spell->Id == SPELL_HARPOON)
                {
                    if (Creature* harpoon = me->FindNearestCreature(NPC_SKYFIRE_HARPOON_GUN, 100.0f, true))
                        me->GetMotionMaster()->MoveFollow(harpoon, 10.0f, 0);

                    events.ScheduleEvent(EVENT_BREAK_HARPOON, urand(20000, 30000));
                }
            }

            void WaypointReached(uint32 waypointId)
            {
                switch (waypointId)
                {
                case 3:
                    if (Unit* pass = vehicle->GetPassenger(0))
                        pass->ExitVehicle();
                    break;

                case 4:
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetSpeed(MOVE_FLIGHT, 1.2f);

                    events.ScheduleEvent(EVENT_TWILIGHT_BARRAGE, urand(10000, 20000));
                    break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                npc_escortAI::UpdateAI(diff);

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_TWILIGHT_BARRAGE:
                    {
                        if (Creature* harpoon = me->FindNearestCreature(NPC_SKYFIRE_HARPOON_GUN, 50.0f, true))
                            me->SetFacingToObject(harpoon);

                        pos = barragePos[urand(0, 18)];
                        me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_TWILIGHT_BARRAGE, false);

                        events.ScheduleEvent(EVENT_TWILIGHT_BARRAGE, urand(10000, 20000));
                    }
                        break;

                    case EVENT_BREAK_HARPOON:
                        me->RemoveAurasDueToSpell(SPELL_HARPOON);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveTargetedHome();

                        if (Creature* harpoon = me->FindNearestCreature(NPC_SKYFIRE_HARPOON_GUN, 50.0f, true))
                            harpoon->AI()->DoAction(ACTION_RELOAD);
                        break;
                    default:
                        break;
                    }
                }
            }

            void JustDied(Unit* killer) override
            {
                if (Creature* harpoon = me->FindNearestCreature(NPC_SKYFIRE_HARPOON_GUN, 50.0f, true))
                    harpoon->AI()->DoAction(ACTION_HARPOON_DEATH);
            }
        };
};

class npc_deck_fire : public CreatureScript
{
public:
    npc_deck_fire() : CreatureScript("npc_deck_fire") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_deck_fireAI(creature);
    }

    struct npc_deck_fireAI : public ScriptedAI
    {
        npc_deck_fireAI(Creature* creature) : ScriptedAI(creature){}

        void IsSummonedBy(Unit* /*owner*/) override
        {
            events.ScheduleEvent(EVENT_FIRE_DAMAGE, 1000);
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIRE_DAMAGE:
                {
                    std::list<Player*> players;
                    me->GetPlayerListInGrid(players, 3.0f);

                    for (std::list<Player*>::iterator iter = players.begin(); iter != players.end(); ++iter)
                        me->CastSpell((*iter), SPELL_FIRE_DAMAGE);

                    events.ScheduleEvent(EVENT_FIRE_DAMAGE, 1000);
                }
                default:
                    break;
                }
            }
        }
    private:
        EventMap events;
    };
};

class npc_skyfire_brigade : public CreatureScript
{
public:
    npc_skyfire_brigade() : CreatureScript("npc_skyfire_brigade") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skyfire_brigadeAI(creature);
    }

    struct npc_skyfire_brigadeAI : public ScriptedAI
    {
        npc_skyfire_brigadeAI(Creature* creature) : ScriptedAI(creature){}

        void IsSummonedBy(Unit* /*owner*/) override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);

            events.ScheduleEvent(EVENT_MOVE, 1000);
        }


        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_WATER_JET)
                if (Creature* fire = me->FindNearestCreature(NPC_FIRE_STALKER, 100.0f, true))
                    fire->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE:
                {
                    std::list<Creature*> fire;
                    me->GetCreatureListWithEntryInGrid(fire, NPC_FIRE_STALKER, 500.0f);

                    if (Creature* target = Trinity::Containers::SelectRandomContainerElement(fire))
                        me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + 10);
                    else
                        me->DespawnOrUnsummon();

                    events.ScheduleEvent(EVENT_WATER_JET, 5000);
                }
                    break;

                case EVENT_WATER_JET:
                    DoCast(me, SPELL_WATER_JET);

                    events.ScheduleEvent(EVENT_MOVE, urand(4000, 6000));
                default:
                    break;
                }
            }
        }
    private:
        EventMap events;
    };
};

class npc_elite_slayer : public CreatureScript
{
public:
    npc_elite_slayer() : CreatureScript("npc_elite_slayer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_elite_slayerAI(creature);
    }

    struct npc_elite_slayerAI : public ScriptedAI
    {
        npc_elite_slayerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        float visualNumb;

        void Reset() override
        {
            me->DespawnOrUnsummon();
        }

        void InitializeAI() override
        {
            DoZoneInCombat(me);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_BRUTAL_STRIKE, urand(7000, 22000));
            events.ScheduleEvent(EVENT_BLADE_RUSH, 18000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLADE_RUSH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    {
                        pos = target->GetPosition();
                        visualNumb = me->GetDistance(target);
                        float ori = me->GetOrientation();

                        if (Creature* tar = me->SummonCreature(575808, pos, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            me->SetFacingToObject(target);
                            DoCast(tar, SPELL_BLADE_RUSH);
                        }

                        for (float x = 0; x <= visualNumb; x += 4)
                        {
                            if (Creature* rush = me->SummonCreature(NPC_BLADE_RUSH, me->GetPositionX() + x * cos(ori), me->GetPositionY() + x * sin(ori), me->GetPositionZ(), ori, TEMPSUMMON_TIMED_DESPAWN, 3000))
                                rush->SendPlaySpellVisualKit(23400, 0, 0);
                        }
                    }

                    events.ScheduleEvent(EVENT_BLADE_RUSH, urand(15000, 20000));
                    break;

                case EVENT_BRUTAL_STRIKE:
                    DoCastVictim(SPELL_BRUTAL_STRIKE);

                    events.ScheduleEvent(EVENT_BRUTAL_STRIKE, urand(7000, 22000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_elite_dreadblade : public CreatureScript
{
public:
    npc_elite_dreadblade() : CreatureScript("npc_elite_dreadblade") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_elite_dreadbladeAI(creature);
    }

    struct npc_elite_dreadbladeAI : public ScriptedAI
    {
        npc_elite_dreadbladeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        float visualNumb;

        void Reset() override
        {
            me->DespawnOrUnsummon();
        }

        void InitializeAI() override
        {
            DoZoneInCombat(me);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_DEGENERATION, urand(7000, 22000));
            events.ScheduleEvent(EVENT_BLADE_RUSH, 18000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLADE_RUSH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    {
                        pos = target->GetPosition();
                        visualNumb = me->GetDistance(target);
                        float ori = me->GetOrientation();

                        if (Creature* tar = me->SummonCreature(575808, pos, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            me->SetFacingToObject(target);
                            DoCast(tar, SPELL_BLADE_RUSH);
                        }

                        for (float x = 0; x <= visualNumb; x += 4)
                        {
                            if (Creature* rush = me->SummonCreature(NPC_BLADE_RUSH, me->GetPositionX() + x * cos(ori), me->GetPositionY() + x * sin(ori), me->GetPositionZ(), ori, TEMPSUMMON_TIMED_DESPAWN, 3000))
                                rush->SendPlaySpellVisualKit(23400, 0, 0);
                        }
                    }

                    events.ScheduleEvent(EVENT_BLADE_RUSH, urand(15000, 20000));
                    break;

                case EVENT_DEGENERATION:
                    DoCastVictim(SPELL_DEGENERATION);

                    events.ScheduleEvent(EVENT_DEGENERATION, urand(7000, 22000));
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_twilight_infiltrator : public CreatureScript
{
public:
    npc_twilight_infiltrator() : CreatureScript("npc_twilight_infiltrator") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_infiltratorAI(creature);
    }

    struct npc_twilight_infiltratorAI : public npc_escortAI
    {
        npc_twilight_infiltratorAI(Creature* creature) : npc_escortAI(creature), vehicle(creature->GetVehicleKit())
        {
            npc_escortAI::SetDespawnAtEnd(true);
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Vehicle* vehicle;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            me->SetSpeed(MOVE_RUN, 3.0f);
            Start(true, true);
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
            case 1:
                if (Unit* pass = vehicle->GetPassenger(0))
                    pass->ExitVehicle();

                if (Creature* sapper = me->FindNearestCreature(NPC_TWILIGHT_SAPPER, 200.0f, true))
                    sapper->AI()->DoAction(ACTION_SAPPER);
                break;
            }
        }
    };

};

class npc_twilight_sapper : public CreatureScript
{
public:
    npc_twilight_sapper() : CreatureScript("npc_twilight_sapper") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_sapperAI(creature);
    }

    struct npc_twilight_sapperAI : public ScriptedAI
    {
        npc_twilight_sapperAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetHomePosition(sapperPos);
            me->SetSpeed(MOVE_WALK, 1.5f);
            me->SetSpeed(MOVE_RUN, 1.5f);
            DoZoneInCombat(me);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_SAPPER:
                events.ScheduleEvent(EVENT_LAND, 2000);
                break;
            }
        }

        void JustReachedHome()
        {
            DoCast(me, SPELL_DETONATE);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LAND:
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class npc_skyfire_harpoon : public CreatureScript
{
public:
    npc_skyfire_harpoon() : CreatureScript("npc_skyfire_harpoon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skyfire_harpoonAI(creature);
    }

    struct npc_skyfire_harpoonAI : public ScriptedAI
    {
        npc_skyfire_harpoonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_HARPOON:
                events.ScheduleEvent(EVENT_HARPOON, 40000);
                break;

            case ACTION_RELOAD:
                events.ScheduleEvent(EVENT_RELOAD, 1000);
                break;

            case ACTION_HARPOON_DEATH:
                events.RescheduleEvent(EVENT_HARPOON, urand(48000, 55000));
                break;
            }
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_HARPOON)
            {
                events.CancelEvent(EVENT_HARPOON);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RELOAD:
                    DoCast(me, SPELL_RELOADING);

                    events.RescheduleEvent(EVENT_HARPOON, 500);
                    break;

                case EVENT_HARPOON:
                    if (Creature* gori = me->FindNearestCreature(NPC_GORIONA, 200.0f, true))
                    {
                        DoCast(me, SPELL_HARPOON);

                        events.ScheduleEvent(EVENT_HARPOON, urand(2000, 3000));
                    }
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class npc_skyfire_cannon : public CreatureScript
{
public:
    npc_skyfire_cannon() : CreatureScript("npc_skyfire_cannon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skyfire_cannonAI(creature);
    }

    struct npc_skyfire_cannonAI : public ScriptedAI
    {
        npc_skyfire_cannonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) <= 50.0f)
            {
                if (who->GetEntry() == NPC_TWILIGHT_ASSAULT_DRAKE || who->GetEntry() == NPC_TWILIGHT_ASSAULT_DRAKE_2)
                    DoCast(me, SPELL_HEAVY_SLUG);
            }
        }
    };
};

class npc_skyfire : public CreatureScript
{
public:
    npc_skyfire() : CreatureScript("npc_skyfire") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skyfireAI(creature);
    }

    struct npc_skyfireAI : public BossAI
    {
        npc_skyfireAI(Creature* creature) : BossAI(creature, DATA_ALLIANCE_SHIP)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetEntry() == NPC_BLACKHORN)
            {
                me->setRegeneratingHealth(false);
                EnterCombat(me);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Creature*> Explosion;
            me->GetCreatureListWithEntryInGrid(Explosion, NPC_MASSIVE_EXPLOSION, 200.0f);
            for (std::list<Creature*>::iterator itr = Explosion.begin(); itr != Explosion.end(); ++itr)
            {
                (*itr)->CastSpell(*itr, SPELL_MASSIVE_EXPLOSION);
            }

            me->Respawn(true);
        }
    };
};

class spell_twilight_barrage : public SpellScriptLoader
{
public:
    spell_twilight_barrage() : SpellScriptLoader("spell_twilight_barrage") { }

    class spell_twilight_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_twilight_barrage_SpellScript);

        int32 damageAmount;

        bool Load() override
        {
            damageAmount = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(caster, SPELL_TWILIGHT_BARRAGE_SKYFIRE, &damageAmount, 0, 0, true);
        }


        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_twilight_barrage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_twilight_barrage_SpellScript();
    }
};

class spell_twilight_onslaught : public SpellScriptLoader
{
public:
    spell_twilight_onslaught() : SpellScriptLoader("spell_twilight_onslaught") { }

    class spell_twilight_onslaught_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_twilight_onslaught_SpellScript);

        int32 damageAmount;
        int32 shipDamage;
        uint32 targetCount;

        bool Load() override
        {
            damageAmount = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            shipDamage = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void CountTargets(std::list<WorldObject*>& targetList)
        {
            targetCount = targetList.size() + 1;
            damageAmount /= targetCount;

            if (targetList.empty())
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(caster, SPELL_TWILIGHT_ONSLAUGHT_SKYFIRE, &shipDamage, 0, 0, true);
        }

        void CalcDamage(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                SetHitDamage(damageAmount);
                shipDamage = damageAmount;
                caster->CastCustomSpell(caster, SPELL_TWILIGHT_ONSLAUGHT_SKYFIRE, &shipDamage, 0, 0, true);
            }
        }


        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_twilight_onslaught_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_twilight_onslaught_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_twilight_onslaught_SpellScript();
    }
};

class spell_vengeance : public SpellScriptLoader
{
public:
    spell_vengeance() : SpellScriptLoader("spell_vengeance") { }

    class spell_vengeance_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vengeance_AuraScript);

        uint32 curHealth;
        int32 amount;

        void CalculateBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = true;

            if (Unit* owner = GetUnitOwner())
            {
                uint32 maxHealth = 100;
                amount = (maxHealth - curHealth);
            }
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* owner = GetUnitOwner())
            {
                curHealth = owner->GetHealthPct();
                owner->CastSpell(owner, SPELL_VENGEANCE);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_vengeance_AuraScript::CalculateBonus, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_vengeance_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vengeance_AuraScript();
    }
};

class NotVictimFilter
{
public:
    NotVictimFilter(Unit* caster) : _victim(caster->GetVictim()){}

    bool operator()(WorldObject* target)
    {
        return target == _victim;
    }

private:
    Unit* _victim;
};

class spell_consuming_shroud : public SpellScriptLoader
{

public:
    spell_consuming_shroud() : SpellScriptLoader("spell_consuming_shroud") { }

    class spell_consuming_shroud_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_consuming_shroud_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            targets.remove_if(NotVictimFilter(GetCaster()));

            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_consuming_shroud_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_consuming_shroud_SpellScript();
    }
};

class spell_siphon_vitality : public SpellScriptLoader
{
public:
    spell_siphon_vitality() : SpellScriptLoader("spell_siphon_vitality") { }

    class spell_siphon_vitality_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_siphon_vitality_SpellScript);

        uint32 amount;
        int32 bp0;

        void CalcAmount(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    amount = 0.2f * (target->GetHealth());
                    bp0 = amount;

                    caster->CastCustomSpell(caster, SPELL_SIPHON_VITALITY, &bp0, 0, 0, true);

                    std::list<Player*> targets;
                    caster->GetPlayerListInGrid(targets, 500.0f);

                    for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    {
                        if ((*iter)->ToPlayer())
                        {
                            caster->DealDamage((*iter), (amount / targets.size()));
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_siphon_vitality_SpellScript::CalcAmount, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_siphon_vitality_SpellScript();
    }
};

class spell_broadside : public SpellScriptLoader
{
public:
    spell_broadside() : SpellScriptLoader("spell_broadside") { }

    class spell_broadside_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_broadside_SpellScript);

        int32 damageAmount;

        void CalcDamage(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    SetHitDamage(0.2 * (target->GetHealth()));
        }


        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_broadside_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_broadside_SpellScript();
    }
};

void AddSC_boss_warmaster_blackhorn()
{
    new boss_warmaster_blackhorn();
    new npc_goriona();
    new npc_sky_captain_swayze();
    new npc_deck_fire();
    new npc_twilight_assault_drake();
    new npc_skyfire_brigade();
    new npc_elite_slayer();
    new npc_elite_dreadblade();
    new npc_twilight_infiltrator();
    new npc_twilight_sapper();
    new npc_skyfire_harpoon();
    new npc_skyfire_cannon();
    new npc_skyfire();
    new spell_twilight_barrage();
    new spell_twilight_onslaught();
    new spell_vengeance();
    new spell_consuming_shroud();
    new spell_siphon_vitality();
    new spell_broadside();
}
