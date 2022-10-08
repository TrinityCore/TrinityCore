/*
 * Copyright (C) 2022 BfaCore Reforged
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
 
// Map: 1131
// Position: X: 1396.58 Y: 802.536 Z: 38.8645 O: 1.921415
// .go 1396.58 802.536 38.8645 1131

#include "Log.h"
#include "Scenario.h"
#include "GameObject.h"
#include "InstanceScenario.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "WorldSession.h"

enum DataTypes
{
    DATA_STAGE_1 = 1,
    DATA_STAGE_2,
    DATA_STAGE_3,
    DATA_STAGE_4,
    DATA_STAGE_5,
    DATA_MAX_ENCOUNTERS,

    SCENARIO_ID = 219,
};


enum RageFireCreaIds
{
    //gob squad
    NPC_PATCH = 70607,
    NPC_GRIT = 70605,
    NPC_NEWT = 70606,
    NPC_TICKER = 70609,
    NPC_VOLT = 70608,
    //stage 3
    NPC_MATID_BOMB = 71174,
    NPC_CANNON_BALLS = 71176,
    NPC_BATTERY = 71195,
    NPC_POOL_PONY = 71175,
    NPC_EGG_YOLK = 71197,

    //stage 4
    NPC_TRIGGER_1 = 98000,
    NPC_TRIGGER_2 = 98001,
    NPC_TRIGGER_3 = 98002,
    NPC_TRIGGER_4 = 98003,
    NPC_TRIGGER_5 = 98004,

    NPC_KORKRON_SHADOWBLADE = 71244,
    NPC_KOR_KRON_DIRE_SOLDIER = 70665,
    NPC_DARK_SHAMAN = 71245,
    NPC_FLAME_HOUND = 70702,
    NPC_EMBER_GUARD = 70798,
    NPC_OVERSEER_ELAGLO = 71030,
    NPC_IRON_BODY_PONSHU_RAGEFIRE = 98005,
};

enum RageFireGobIds
{
    GOBJ_INITIAL_TELEPORTER = 220065,
    GOBJ_EMERGENCY_TELEPORTER = 220066,
};

enum stage3SpellIds
{
    SPELL_CANNON_BALL = 141832,
    SPELL_THROW_CANNON_BALL = 141937,
    SPELL_ATTACH_CANNON_BALL1 = 141879,
    SPELL_ATTACH_CANNON_BALL2 = 141880,
    SPELL_ATTACH_CANNON_BALL3 = 141881,
    SPELL_ATTACH_BATTERY1 = 141887,
    SPELL_ATTACH_BATTERY2 = 141888,
    SPELL_BATTERY = 141904,
    SPELL_THROW_BATTERY = 141949,
    SPELL_POOL_PONY = 141898,
    SPELL_ATTACH_POOL_PONY = 141889,
    SPELL_THROW_POOL_PONY = 141951,
    SPELL_EGG_YOLK = 141914,
    SPELL_ATTACH_EGG_YOLK = 141891,
    SPELL_HUGE_EXPLOSION = 141954,//mantid bomb
    SPELL_MASSIVE_EXPLOSION = 142438,
    SPELL_GHOST_AURA = 137125,
};

enum CriteriaTrees
{
    CRITERIA_TREE_BREACH_THE_MAIN_CHAMBER_AND_STOP_THE_ABDUCTIONS = 32524,
    CRITERIA_TREE_INVESTIGATE_THE_MAIN_CHAMBER = 32588,
    CRITERIA_TREE_HELP_TICKER_BUILD_A_DEVICE_TO_OPEN_THE_NEXT_GATE = 32589,
    CRITERIA_TREE_DEFEND_THE_GOB_SQUAD_WHILE_PATCH_ESTABLISHES_AN_ESCAPE_ROUTE = 32590,
    CRITERIA_TREE_COMPLETE_ALL_BONUS_OBJECTIVES_TO_RECEIVE_BONUS_VALOR = 32799,
};

enum ScenarioEvents
{
    //stage 1
    SCENARIO_EVENT_DETONATION = 35961,
    SCENARIO_EVENT_ENEMY_FORCES = 36187,
    //stage 2
    SCENARIO_EVENT_PROTO_DRAKE = 36074,
    SCENARIO_EVENT_SUPPLY_CRATES = 36076,
    SCENARIO_EVENT_PANDARIA_ARTIFACTS = 36077,
    //stage 3
    SCENARIO_EVENT_MEET_UP = 36305,
    SCENARIO_EVENT_CANNON_BALLS = 36190,
    SCENARIO_EVENT_BATTERIES = 36193,
    SCENARIO_EVENT_POOL_PONY = 36191,
    SCENARIO_EVENT_EGG_YOLK = 36192,
    //stage 4
    SCENARIO_EVENT_GOB_SQUAD_DEFEATED = 36194, 
    //stage 5
    SCENARIO_EVENT_COMPLETE_ALL_BONUS_OBJECTIVES_TO_RECEIVE_BONUS_VALOR = 32799,//treeid
};

Position const finalBossPos = { 1452.521729f, 1046.348877f, 33.847805f, 4.314608f };
Position const spawnPosIron = { 1436.746338f, 1021.107483f, 34.471546f, 4.888280f };

struct scenario_the_secrets_of_ragefire : public InstanceScript
{
    scenario_the_secrets_of_ragefire(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        isLoadScenaro = false;

        squadGuids.clear();
        bombGuids.clear();
        darkShamanAddsGuids.clear();
        ragefirePeonGuids.clear();
        stage3DeliveryGuids.clear();
        stage4Entries.clear();
        stage4_1Guids.clear();
        stage4_2Guids.clear();
        stage4_3Guids.clear();
        stage4_4Guids.clear();

        stage4Entries.push_back(NPC_KOR_KRON_DIRE_SOLDIER);
        stage4Entries.push_back(NPC_DARK_SHAMAN);
        stage4Entries.push_back(NPC_FLAME_HOUND);
        stage4Entries.push_back(NPC_EMBER_GUARD);

        stageOneKills = 0;
        stageTwoKills = 0;
        stageThreeKills = 0;
        stageFourKills = 0;
        stageFourLevel = 0;
        onStageFour = false;
    }


    void OnPlayerAreaUpdate(Player* player, uint32 newAreaId, uint32 /*oldAreaId*/ ) override
    {
        if (!isLoadScenaro)
        {
            isLoadScenaro = true;
          //  GetScenarioByID(player, SCENARIO_ID);
        }
    }

    void OnCompletedCriteriaTree(CriteriaTree const* tree) override
    {
        switch (tree->ID)
        {
        case CRITERIA_TREE_BREACH_THE_MAIN_CHAMBER_AND_STOP_THE_ABDUCTIONS:   break;
        case CRITERIA_TREE_INVESTIGATE_THE_MAIN_CHAMBER:
            if (Creature* c = instance->GetCreature(matidBombGuid))
                c->SetVisible(true);
            for (ObjectGuid guid : squadGuids)
                if (Creature* creature = instance->GetCreature(guid))
                    creature->GetAI()->DoAction(13);
            for (ObjectGuid guid : stage3DeliveryGuids)
                if (Creature* c = instance->GetCreature(guid))
                    c->GetAI()->DoAction(1);
            break;
        case CRITERIA_TREE_HELP_TICKER_BUILD_A_DEVICE_TO_OPEN_THE_NEXT_GATE:
            for (ObjectGuid guid : stage3DeliveryGuids)
                if (Creature* c = instance->GetCreature(guid))
                    c->DespawnOrUnsummon();
            startStageFour();
            if (Creature* creature = instance->SummonCreature(NPC_OVERSEER_ELAGLO, finalBossPos))
            {
                creature->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                creature->SetReactState(REACT_AGGRESSIVE);
            }
            break;
        case CRITERIA_TREE_DEFEND_THE_GOB_SQUAD_WHILE_PATCH_ESTABLISHES_AN_ESCAPE_ROUTE:
            instance->SummonGameObject(220066, Position(1437.774f, 1010.219f, 34.19741f, 4.680285f), QuaternionData(0.f, 0.f, -0.7183657f, 0.6956657f), WEEK);
            instance->SummonCreature(71296, Position(1437.83f, 1010.01f, 34.2807f, 4.28767f));
            break;
        case CRITERIA_TREE_COMPLETE_ALL_BONUS_OBJECTIVES_TO_RECEIVE_BONUS_VALOR:
            if (Creature* creature = instance->SummonCreature(NPC_IRON_BODY_PONSHU_RAGEFIRE, spawnPosIron))
            {
                creature->CastSpell(creature, SPELL_GHOST_AURA);
                creature->GetAI()->DoAction(1);
            }
            break;

        }
    }

    void OnPlayerEnter(Player* player) override
    {
        SetCheckPointPos(Position(1396.58f, 802.536f, 38.8645f, 1.921415f));
        player->CastSpell(player, 140714, true);      //140714 142021 142022 142783 142784       
    }

    void checkStageFour()
    {
        ++stageFourKills;
        switch (stageFourLevel)
        {
        case 0:
            if (stageFourKills == 5)
            {
                stageFourKills = 0;
                stageFourLevel = 1;
                startStageFour();
            }
            break;
        case 1:
            if (stageFourKills == 4)
            {
                stageFourKills = 0;
                stageFourLevel = 2;
                startStageFour();
            }
            break;
        case 2:
            if (stageFourKills == 3)
            {
                stageFourKills = 0;
                stageFourLevel = 3;
                startStageFour();
            }
            break;
        case 3:
            if (stageFourKills == 4)
            {
                stageFourKills = 0;
                stageFourLevel = 4;
                startStageFour();
            }
            break;
        }
    }

    void startStageFour()
    {
        if (!onStageFour)
            onStageFour = true;
        switch (stageFourLevel)
        {
        case 0:
            for (ObjectGuid guid : stage4_1Guids)
                if (Creature* c = instance->GetCreature(guid))
                    c->GetAI()->DoAction(10);
            break;
        case 1:
            for (ObjectGuid guid : stage4_2Guids)
                if (Creature* c = instance->GetCreature(guid))
                    c->GetAI()->DoAction(10);
            break;
        case 2:
            for (ObjectGuid guid : stage4_3Guids)
                if (Creature* c = instance->GetCreature(guid))
                    c->GetAI()->DoAction(10);
            break;
        case 3:
            for (ObjectGuid guid : stage4_4Guids)
                if (Creature* c = instance->GetCreature(guid))
                    c->GetAI()->DoAction(10);
            break;
        case 4:
            instance->SummonCreature(NPC_OVERSEER_ELAGLO, finalBossPos);
            break;
        }
    }

    void insertGuidsInVectorFromCreatureEntryArray(WorldObject* o, std::vector<ObjectGuid> &guids, std::vector<uint32> entries, float range)
    {
        for (uint32 entry : entries)
        {
            std::list<Creature*> mobs;
            o->GetCreatureListWithEntryInGrid(mobs, entry, range);
            for (Creature* c : mobs)
                guids.push_back(c->GetGUID());
            mobs.clear();
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
        case NPC_PATCH:
        case NPC_GRIT:
        case NPC_NEWT:
        case NPC_TICKER:
        case NPC_VOLT:
            squadGuids.push_back(creature->GetGUID());
            break;
        case 70672://bomb
            bombGuids.push_back(creature->GetGUID());
            break;
        case 71244://shadowblade
        case 71245://dark shaman
            darkShamanAddsGuids.push_back(creature->GetGUID());
            break;
        case 70683:
            darkShamanXorenthGuid = creature->GetGUID();
            break;
        case 71097:
            ragefirePeonGuids.push_back(creature->GetGUID());
            break;
        case NPC_MATID_BOMB:
            matidBombGuid = creature->GetGUID();
            creature->SetVisible(false);
            break;
        case NPC_CANNON_BALLS:
        case NPC_BATTERY:
        case NPC_POOL_PONY:
        case NPC_EGG_YOLK:
            stage3DeliveryGuids.push_back(creature->GetGUID());
            break;
        case NPC_TRIGGER_1:
            insertGuidsInVectorFromCreatureEntryArray(creature, stage4_1Guids, stage4Entries, 10.0f);
            break;
        case NPC_TRIGGER_2:
            insertGuidsInVectorFromCreatureEntryArray(creature, stage4_2Guids, stage4Entries, 10.0f);
            break;
        case NPC_TRIGGER_4:
            insertGuidsInVectorFromCreatureEntryArray(creature, stage4_3Guids, stage4Entries, 10.0f);
            break;
        case NPC_TRIGGER_5:
            insertGuidsInVectorFromCreatureEntryArray(creature, stage4_4Guids, stage4Entries, 10.0f);
            break;
        }
    }


    void SetData(uint32 type, uint32 data) override
    {
        if (data == SPECIAL)
        {
            switch (type)
            {
            case NPC_KOR_KRON_DIRE_SOLDIER:
            case NPC_DARK_SHAMAN:
            case NPC_FLAME_HOUND:
            case NPC_EMBER_GUARD:
                checkStageFour();
                break;
            case 70672://bombs
                for (ObjectGuid guid : bombGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->GetAI()->DoAction(2);//rather than casting spell, which is wrong one in first place, setentry, then cast explosion. so after 5 secs cast spell, and entry set to will be 71098
                                                       //      creature->CastSpell(creature, 103546, true);

                break;
            case 70683:
                for (ObjectGuid guid : ragefirePeonGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->GetMotionMaster()->MovePoint(1, 1501.083374f, 1001.316284f, 38.346649f);
                break;
            case NPC_KORKRON_SHADOWBLADE:
                for (ObjectGuid guid : squadGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                    {
                        creature->SetReactState(REACT_AGGRESSIVE);
                        if (Creature* enemy = creature->FindNearestCreature(71244, 350.0f))
                        {
                            creature->SetInCombatWith(enemy);
                            creature->Attack(enemy, true);
                        }
                    }
                break;
            }
        }

        if (data == DONE)
        {
            switch (type)
            {
            case 70662://denotator
                DoSendScenarioEvent(SCENARIO_EVENT_DETONATION);//Breach the main chamber
                for (ObjectGuid guid : squadGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->GetAI()->DoAction(4);
                break;
            case 70683://dark shaman xorenth
                DoSendScenarioEvent(SCENARIO_EVENT_ENEMY_FORCES);//defeated enemy forces
                for (ObjectGuid guid : squadGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->GetAI()->DoAction(9);//activate step 2: reconnaissance
                break;
            case 71244:
            case 71245:
                stageOneKills++;
                if (stageOneKills == 4)
                    if (Creature* c = instance->GetCreature(darkShamanXorenthGuid))
                        c->GetAI()->DoAction(2);
                break;
            //case 71203:
            case 70901:
                stageTwoKills++;
                DoSendScenarioEvent(SCENARIO_EVENT_SUPPLY_CRATES);//stage 2
                break;
            //case 71208:
            case 71031:
                stageTwoKills++;
                DoSendScenarioEvent(SCENARIO_EVENT_PROTO_DRAKE);//stage 2
                break;
            //case 71209:
            case 71032:
                stageTwoKills++;
                DoSendScenarioEvent(SCENARIO_EVENT_PANDARIA_ARTIFACTS);//stage 2
                break;
            case NPC_PATCH:
                DoSendScenarioEvent(SCENARIO_EVENT_MEET_UP);//stage 3
                break;
            case NPC_CANNON_BALLS:
                DoSendScenarioEvent(SCENARIO_EVENT_CANNON_BALLS);//stage 3
                ++stageThreeKills;
                break;
            case NPC_BATTERY:
                DoSendScenarioEvent(SCENARIO_EVENT_BATTERIES);//stage 3
                ++stageThreeKills;
                break;
            case NPC_POOL_PONY:
                DoSendScenarioEvent(SCENARIO_EVENT_POOL_PONY);//stage 3
                ++stageThreeKills;
                break;
            case NPC_EGG_YOLK:
                DoSendScenarioEvent(SCENARIO_EVENT_EGG_YOLK);//stage 3
                ++stageThreeKills;
                break;
            case NPC_MATID_BOMB:
                startStageFour();
                break;
            case NPC_OVERSEER_ELAGLO:
                DoSendScenarioEvent(SCENARIO_EVENT_GOB_SQUAD_DEFEATED);
                break;
            }
        }

        if (data == IN_PROGRESS)
        {
            switch (type)
            {
            case 70683://dark shaman xorenth
            {
                for (ObjectGuid cGuid : darkShamanAddsGuids)
                {
                    if (Creature* c = instance->GetCreature(cGuid))
                    {
                        c->GetAI()->DoAction(1);//Set in combat.
                    }
                }
            }
            case NPC_PATCH:
                for (ObjectGuid guid : squadGuids)
                    if (Creature* creature = instance->GetCreature(guid))
                    {
                        creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());//if the player is noob and dies, just stay there..
                        creature->GetAI()->DoAction(6);
                    }
                break;
            }
        }


        //if (m_scenario.IsCompleted())
        //    CompleteScenario();
    }


    void OnUnitDeath(Unit* l_unit)
    {
       // if (l_unit->GetEntry() == 98011)
       //     if (GetData(DATA_STAGE_1) == NOT_STARTED)
       //         SetData(DATA_STAGE_1, DONE);
    }

private:
    EventMap events;
    bool isLoadScenaro = false;

    std::vector<ObjectGuid> squadGuids;
    std::vector<ObjectGuid> bombGuids;
    std::vector<ObjectGuid> darkShamanAddsGuids;
    std::vector<ObjectGuid> ragefirePeonGuids;
    std::vector<ObjectGuid> stage3DeliveryGuids;
    ///stage 4 Ids
    std::vector<uint32> stage4Entries;
    std::vector<ObjectGuid> stage4_1Guids;
    std::vector<ObjectGuid> stage4_2Guids;
    std::vector<ObjectGuid> stage4_3Guids;
    std::vector<ObjectGuid> stage4_4Guids;

    ObjectGuid darkShamanXorenthGuid;
    ObjectGuid matidBombGuid;
    uint32 stageOneKills;
    uint32 stageTwoKills;
    uint32 stageThreeKills;
    uint32 stageFourKills;
    uint32 stageFourLevel;
    bool onStageFour;
};
//70662
class ragefire_core_detonator : public CreatureScript
{
public:
    ragefire_core_detonator() : CreatureScript("ragefire_core_detonator") { }

    struct ragefire_core_detonatorAI : public ScriptedAI
    {
        ragefire_core_detonatorAI(Creature* creature) : ScriptedAI(creature), startTicking(false), msg("5")
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* clicker, bool& /*result*/) override
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            if (!startTicking)
            {
                startTicking = true;
                if (InstanceScript* instance = me->GetInstanceScript())
                    instance->SetData(70672, SPECIAL);
                events.ScheduleEvent(1, 5000);
                std::list<Creature*> bombList;
                me->GetCreatureListWithEntryInGrid(bombList, 70672, 50.0f);
                for (Creature* c : bombList)
                {
                    c->SetMaxHealth(999999);
                    c->SetFullHealth();
                    DoCast(c, 141624);//ignite the bombs spell
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!startTicking)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                  
                    if (GameObject* pDoor = me->FindNearestGameObject(220168, 40.0f))
                    {
                        pDoor->SetLootState(GO_READY);
                        pDoor->UseDoorOrButton(10000 * 999, false, me);
                        pDoor->CastSpell(me, 148964);
                    }
                    if (InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData(me->GetEntry(), DONE);
                    DoCastAOE(137548);
                    std::list<Creature*> bombList;
                    me->GetCreatureListWithEntryInGrid(bombList, 70672, 50.0f);
                    for (Creature* c : bombList)
                    {
                        c->CastSpell(c, 142474, true);
                        c->DespawnOrUnsummon();
                    }
                       
                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }

    private:
        std::string msg;
        bool startTicking;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_detonatorAI(creature);
    }
};
//71098
class ragefire_core_ticking_bomb : public CreatureScript
{
public:
    ragefire_core_ticking_bomb() : CreatureScript("ragefire_core_ticking_bomb") { }

    struct ragefire_core_ticking_bombAI : public ScriptedAI
    {
        ragefire_core_ticking_bombAI(Creature* creature) : ScriptedAI(creature), startTicking(false) { }

        void Reset()
        {
            //   me->SetVisible(false);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                me->SetVisible(true);
                break;
            case 2:
                startTicking = true;
                me->SetEntry(71098);
                DoCast(142072);
                events.ScheduleEvent(1, 5000);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!startTicking)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(149353);

                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }

    private:
        bool startTicking;
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_ticking_bombAI(creature);
    }
};
//70607
class ragefire_core_npc_patch : public CreatureScript
{
public:
    ragefire_core_npc_patch() : CreatureScript("ragefire_core_npc_patch") { }

    struct ragefire_core_npc_patchAI : public ScriptedAI
    {
        ragefire_core_npc_patchAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            events.ScheduleEvent(1, 3000);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }

        void Reset() override
        {

        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            switch (id)
            {
            case 1:
                Talk(0);//73081
                if (Creature* c = me->FindNearestCreature(NPC_NEWT,100.f))
                    c->GetAI()->DoAction(2);
                break;
            case 2:
                me->SetOrientation(1.768873f);
                me->GetMotionMaster()->MovePoint(3, 1424.620850f, 864.095642f, 38.610504f);
                break;
            case 4:
                Talk(8);//73100
                if (Creature* boss = me->FindNearestCreature(70683, 120.0f))
                    boss->GetAI()->DoAction(1);
                if (Creature* c = me->FindNearestCreature(NPC_TICKER, 100.f))
                    c->GetAI()->DoAction(5);
                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                events.ScheduleEvent(2, 2000);
                break;
            case 2:
                events.ScheduleEvent(3, 2000);
                break;
            case 3:
                events.ScheduleEvent(7, 1000);
                break;
            case 4:
                Talk(7);//73092
                events.ScheduleEvent(8, 1000);
                break;
            case 5:
                events.ScheduleEvent(9, 4000);
                break;
            case 6:
                if (Creature* enemy = me->FindNearestCreature(71244, 50.0f))
                {
                    me->SetInCombatWith(enemy);
                    me->Attack(enemy, true);
                    me->AddThreat(enemy, 500.0f);
                }
                break;
            case 7:
                events.ScheduleEvent(10, 3000);
                break;
            case 8:
                events.ScheduleEvent(12, 3000);
                break;
            case 9:
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(0, 1412.650635f, 1043.317871f, 34.165894f);
                events.ScheduleEvent(13, 2000);
                break;
            case 12:
                Talk(21);// me->Say("These supply crates came from Orgrimmar. What is Garrosh planning to do with so many war supplies?"); to do
                break;
            case 13:
                me->GetMotionMaster()->MovePoint(5, 1489.619629f, 1004.998657f, 38.381786f);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    Talk(0);// me->Say("Newt, get that door open.");
                    me->PlayOneShotAnimKitId(25); //point
                    if (Creature* c = me->FindNearestCreature(NPC_NEWT,100.f))
                        c->GetAI()->DoAction(1);
                    break;
                case 2:
                    Talk(1);//me->Say("Grit, Ticker and Volt, you three back her up.");
                    if (Creature* c = me->FindNearestCreature(NPC_TICKER,100.f))
                        c->GetAI()->DoAction(1);
                    break;
                case 3:
                    if (Player* p = me->SelectNearestPlayer(150.0f))//warning gms will trigger this
                        Talk(2, p);// me->MonsterSay("Recruit $n, you're with me", 0, p->GetGUID());
                    events.ScheduleEvent(4, 3000);
                    break;
                case 4:
                    Talk(3); //me->Say("We've tracked the recent disappearences in Durotar to this abandoned section of Ragefire.");
                    events.ScheduleEvent(5, 4000);
                    break;
                case 5:
                    Talk(4); //me->Say("It's our job to find out who's behind these abductions and put a stop to them.");
                    events.ScheduleEvent(6, 4000);
                    break;
                case 6:
                    Talk(5); //me->Say("Stay close.");
                    me->GetMotionMaster()->MovePoint(1, 1417.978516f, 870.028076f, 38.061775f);
                    break;
                case 7:
                    me->GetMotionMaster()->MovePoint(2, 1425.401001f, 862.816650f, 38.733353f);
                    break;
                case 8:
                    me->GetMotionMaster()->MovePoint(4, 1409.4255659f, 925.447998f, 36.675375f);
                    break;
                case 9:
                    Talk(9); //me->Yell("Gob Squad, defend yourselves!");
                    if (instance)
                        instance->SetData(me->GetEntry(), IN_PROGRESS);
                    break;
                case 10:
                    Talk(10); //me->Yell("We arn't your enemy, Xorenth!");
                    events.ScheduleEvent(11, 3000);
                    break;
                case 11:
                    if (Creature* c = me->FindNearestCreature(70683,100.f))
                        c->GetAI()->DoAction(3);
                    break;
                case 12:
                    Talk(11); //me->Yell("We'll show you who's lesser!");
                    break;
                case 13:
                    Talk(17); //me->Say("This is bad."); TO DO
                    events.ScheduleEvent(14, 2000);
                    break;
                case 14:
                    Talk(18); //me->Say("All of you fan out and search the chamber. If Garrosh is behind this we're going to need proof."); TO DO
                    break;
                }
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_patchAI(creature);
    }
};
//70606
class ragefire_core_npc_newt : public CreatureScript
{
public:
    ragefire_core_npc_newt() : CreatureScript("ragefire_core_npc_newt") { }

    struct ragefire_core_npc_newtAI : public ScriptedAI
    {
        ragefire_core_npc_newtAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {

        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            switch (id)
            {
            case 1:

                break;
            case 2:
                Talk(2);// me->Say("The charges are all set; hit the detonator as soon as you're ready!");
                if(Creature* c =me->SummonCreature(70662, 1420.861450f, 865.418701f, 38.158325f, TEMPSUMMON_MANUAL_DESPAWN))
                    c->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetOrientation(1.768873f);
                me->GetMotionMaster()->MovePoint(3, 1420.794434f, 864.493469f, 38.186062f);
                break;
            case 3:

                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                events.ScheduleEvent(1, 3000);
                break;
            case 2:
                events.ScheduleEvent(6, 2000);
                break;
            case 4:
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    me->GetMotionMaster()->MoveFollow(c, 5.0f, 3.0f);
                break;
            case 6:
                if (Creature* enemy = me->FindNearestCreature(71244, 50.0f))
                {
                    me->SetInCombatWith(enemy);
                    DoZoneInCombat(enemy);
                    me->Attack(enemy, true);
                }
                break;
            case 9:
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(0, 1453.287476f, 1059.285400f, 34.403152f);
                break;
            case 13:
                me->GetMotionMaster()->MovePoint(5, 1487.163818f, 1002.904053f, 37.929745f);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    Talk(0);// me->Say("Yes, Sir!");
                    if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                        c->GetAI()->DoAction(1);
                    events.ScheduleEvent(2, 2000);
                    break;
                case 2:
                    me->GetMotionMaster()->MovePoint(1, 1417.096069f, 885.688904f, 37.775940f);
                    break;
                case 3://SPELLID ticking timebomb: 141601
                case 4:
                case 5://planting bombs TODO
                    break;
                case 6:
                    Talk(1);//me->Say("I'm setting the last charge now, sir!");
                    me->GetMotionMaster()->MovePoint(2, 1420.563965f, 864.112671f, 38.187874f);
                    if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                        c->GetAI()->DoAction(3);
                    break;
                }
            }
            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_newtAI(creature);
    }
};
//70605
class ragefire_core_npc_grit : public CreatureScript
{
public:
    ragefire_core_npc_grit() : CreatureScript("ragefire_core_npc_grit") { }

    struct ragefire_core_npc_gritAI : public ScriptedAI
    {
        ragefire_core_npc_gritAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->LoadEquipment(int8(62249));
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            switch (id)
            {
            case 1:

                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                events.ScheduleEvent(1, 10);
                break;
            case 4:
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    me->GetMotionMaster()->MoveFollow(c, 5.0f, 4.0f);
                break;
            case 6:
                if (Creature* enemy = me->FindNearestCreature(71244, 50.0f))
                {
                    me->SetInCombatWith(enemy);
                    DoZoneInCombat(enemy);
                    me->Attack(enemy, true);
                }
                break;

            case 9:
                events.ScheduleEvent(2, 2000);
                break;

            case 13:
                me->GetMotionMaster()->MovePoint(5, 1489.619629f, 997.013855f, 39.032120f);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    me->GetMotionMaster()->MovePoint(1, 1401.851074f, 861.117004f, 38.370773f);
                    break;
                }
            }
            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_gritAI(creature);
    }
};
//70609
class ragefire_core_npc_ticker : public CreatureScript
{
public:
    ragefire_core_npc_ticker() : CreatureScript("ragefire_core_npc_ticker") { }

    struct ragefire_core_npc_tickerAI : public ScriptedAI
    {
        ragefire_core_npc_tickerAI(Creature* creature) : ScriptedAI(creature), _cannonBalls(0), meetUp(false), _batteries(0), _poolPony(false), _eggYolk(false), _count(0)
        {
            instance = me->GetInstanceScript();
        }

        void Reset() override
        {
            me->LoadEquipment(int8(62249));
        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            switch (id)
            {
            case 5:
                me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(6);// me->Say("Recruit, bring me that pool pony, three cannon balls, two batteries and some of that protodrake egg yolk.");
                events.ScheduleEvent(20, 10000);
                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                events.ScheduleEvent(1, 3000);
                break;
            case 4:
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    me->GetMotionMaster()->MoveFollow(c, 5.0f, 1.0f);
                break;
            case 5:
                events.ScheduleEvent(3, 1000);
                break;
            case 6:
                if (Creature* enemy = me->FindNearestCreature(71244, 50.0f))
                {
                    me->SetInCombatWith(enemy);
                    DoZoneInCombat(enemy);
                    me->Attack(enemy, true);
                }
                break;
            case 13:
                me->GetMotionMaster()->MovePoint(5, 1496.913818f, 1001.985840f, 38.286098f);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    Talk(0);// me->Say("On it.");
                    if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                        c->GetAI()->DoAction(2);
                    events.ScheduleEvent(2, 2000);
                    break;
                case 2:
                    if (Creature* c = me->FindNearestCreature(NPC_GRIT,100.f))
                        c->GetAI()->DoAction(1);
                    if (Creature* c = me->FindNearestCreature(NPC_VOLT,100.f))
                        c->GetAI()->DoAction(1);
                    me->GetMotionMaster()->MovePoint(1, 1411.282471f, 858.3328825f, 37.793259f);
                    break;
                case 3:
                    Talk(1);// me->Yell("Sir, these Kor'kron don't seem very friendly!");
                    if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                        c->GetAI()->DoAction(5);
                    break;

                case 20://move to ticker LOL
                    if (_count >= 7)
                    {
                        Talk(13);// me->Yell("My masterpiece is finished!");
                        events.ScheduleEvent(21, 2000);
                    }
                    else
                        events.ScheduleEvent(20, 3000);
                    break;
                case 21:
                    if (Creature* c = me->FindNearestCreature(NPC_VOLT, 100.f))
                        c->AI()->Talk(1);// Yell(c, "It's... it's beautiful!");
                    if (Creature* c = me->FindNearestCreature(NPC_NEWT,100.f))
                        c->AI()->Talk(4);//Say(c, "What the heck is the pool pony for?");
                    events.ScheduleEvent(22, 2000);
                    break;
                case 22:
                    Talk(14);// me->Say("Don't question my genius!");
                    events.ScheduleEvent(23, 2000);
                    break;
                case 23:
                    if (Creature* c = me->FindNearestCreature(NPC_PATCH, 100.f))
                        c->AI()->Talk(16);//Say(c, "I don't care what it's for, is it going to get this door open?");
                    events.ScheduleEvent(24, 4000);
                    break;
                case 24:
                    Talk(15);// me->Say("This thing could open Gallywix's personal safe!");
                    if (Creature* c = me->FindNearestCreature(NPC_MATID_BOMB, 100.f))
                        c->CastSpell(c, SPELL_MASSIVE_EXPLOSION);

                    events.ScheduleEvent(25, 2000);
                    break;
                case 25:
                    if (Creature* c = me->FindNearestCreature(NPC_MATID_BOMB, 100.f))
                        c->GetAI()->DoAction(1);
                    Talk(16);// me->Say("Once the detonator goes off in... err... NOW!");
                    break;
                }
            }
            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }

        void mantidBombCast(uint32 spellId)
        {
            if (Creature* c = me->FindNearestCreature(NPC_MATID_BOMB, 60.0f))
                c->CastSpell(c, spellId, false);
            _count++;
        }

        void sGossipHello(Player* player) override
        {
            if (player->IsGameMaster())
            {
                instance->SetData(NPC_CANNON_BALLS, DONE);
                instance->SetData(NPC_CANNON_BALLS, DONE);
                instance->SetData(NPC_CANNON_BALLS, DONE);
                instance->SetData(NPC_BATTERY, DONE);
                instance->SetData(NPC_POOL_PONY, DONE);
                instance->SetData(NPC_EGG_YOLK, DONE);
                instance->SetData(NPC_BATTERY, DONE);
                instance->SetData(NPC_BATTERY, DONE);
                _count = 7;
            }

            if (!meetUp)
            {
                meetUp = true;
                instance->SetData(NPC_PATCH, DONE);
            }

            if (player->HasAura(SPELL_CANNON_BALL))
            {
                player->RemoveAura(SPELL_CANNON_BALL);
                if (_cannonBalls < 3)
                {
                    instance->SetData(NPC_CANNON_BALLS, DONE);
                    mantidBombCast(SPELL_ATTACH_CANNON_BALL1 + _cannonBalls);
                    switch (_cannonBalls)
                    {
                    case 0:
                        Talk(9);// me->Say("That's exactly what we needed!");
                        break;
                    case 1:
                        Talk(11);//me->Say("Careful! This isn't a toy!");
                        break;
                    case 2:
                        Talk(12);//me->Say("This may be my greatest work yet!");
                        break;
                    }
                    ++_cannonBalls;
                }
            }

            if (player->HasAura(SPELL_BATTERY))
            {
                player->RemoveAura(SPELL_BATTERY);
                if (_batteries < 2)
                {
                    instance->SetData(NPC_BATTERY, DONE);
                    mantidBombCast(SPELL_ATTACH_BATTERY1 + _batteries);
                    switch (_batteries)
                    {
                    case 0:
                        Talk(2);// me->Say("Just a little more power...");
                        break;
                    case 1:
                        Talk(8);//me->Say("This should give us enough power to disable the stabilization matrix");
                        break;
                    }
                    _batteries++;
                }
            }

            if (player->HasAura(SPELL_POOL_PONY))
            {
                player->RemoveAura(SPELL_POOL_PONY);
                if (!_poolPony)
                {
                    Talk(7);// me->Say("The most important ingredient!");
                    mantidBombCast(SPELL_ATTACH_POOL_PONY);
                    _poolPony = true;
                    instance->SetData(NPC_POOL_PONY, DONE);
                }
            }

            if (player->HasAura(SPELL_EGG_YOLK))
            {
                player->RemoveAura(SPELL_EGG_YOLK);
                if (!_eggYolk)
                {
                    _eggYolk = true;
                    mantidBombCast(SPELL_ATTACH_EGG_YOLK);
                    Talk(10);//me->Say("You carried that with your hands?! Uh... you should probably see a medic when we get back...");
                    instance->SetData(NPC_EGG_YOLK, DONE);
                }
            }

            CloseGossipMenuFor(player);
        }
    private:
        uint32 _cannonBalls;
        uint32 _batteries;
        bool _poolPony;
        bool _eggYolk;
        bool meetUp;
        uint32 _count;
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_tickerAI(creature);
    }
};
//70608
class ragefire_core_npc_volt : public CreatureScript
{
public:
    ragefire_core_npc_volt() : CreatureScript("ragefire_core_npc_volt") { }

    struct ragefire_core_npc_voltAI : public ScriptedAI
    {
        ragefire_core_npc_voltAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->LoadEquipment(int8(62249));
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            switch (id)
            {
            case 1:

                break;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                events.ScheduleEvent(1, 10);
                break;

            case 4:
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    me->GetMotionMaster()->MoveFollow(c, 5.0f, 5.0f);
                break;
            case 6:
                if (Creature* enemy = me->FindNearestCreature(71244, 50.0f))
                {
                    me->SetInCombatWith(enemy);
                    DoZoneInCombat(enemy);
                    me->Attack(enemy, true);
                }
                break;
            case 9:
                if (Creature* c = me->FindNearestCreature(NPC_TICKER, 100.f))
                    c->AI()->Talk(1);// me->Say("Sir these are Garrosh's men.");
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(0, 1392.202026f, 999.338257f, 33.381569f);
                break;
            case 13:
                me->GetMotionMaster()->MovePoint(5, 1482.913818f, 998.0f, 38.286098f);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    me->GetMotionMaster()->MovePoint(1, 1421.058228f, 853.469604f, 38.675117f);
                    break;
                }
            }
            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_voltAI(creature);
    }
};

enum darkShamanXorenthSpells
{
    SPELL_GLACIAL_TOTEM = 142320,
    SPELL_RUINED_EARTH = 142306,
    SPELL_TWISTED_ELEMENTS = 142296,
};
//70683
class boss_ragefire_dark_shaman_xorenth : public CreatureScript
{
public:
    boss_ragefire_dark_shaman_xorenth() : CreatureScript("boss_ragefire_dark_shaman_xorenth") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ragefire_dark_shaman_xorenthAI(pCreature);
    }
    /*
    Introduction
    Dark Shaman Xorenth yells: Intruders! Stop them!
    Ticker yells: These Kor'kron don't seem very friendly!
    Patch yells: Gob Squad, defend yourselves!
    Aggro
    Dark Shaman Xorenth yells: Weaklings!
    Dark Shaman Xorenth yells: Seal the gate, and inform the overseer immediately.
    Patch yells: We aren't your enemy, Xorenth!
    Dark Shaman Xorenth yells: All lesser races are enemies of the true Horde!
    Patch yells: Lesser? We'll show you who's lesser!
    */
    struct boss_ragefire_dark_shaman_xorenthAI : public BossAI
    {
        boss_ragefire_dark_shaman_xorenthAI(Creature* pCreature) : BossAI(pCreature, 0), intro(false), _startCombat(false)
        {
            instance = me->GetInstanceScript();
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_DEFENSIVE);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                if (!intro)
                {
                    intro = true;
                    Talk(0);// me->Yell("Intruders! Stop them!");
                }
                if (instance)
                    instance->SetData(me->GetEntry(), IN_PROGRESS);
                break;
            case 2:
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetInCombatWithZone();
                EnterCombat(me);
                break;
            case 3:
                Talk(3);//me->Yell("All lesser races are enemies of the true horde!");
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    c->GetAI()->DoAction(8);
                break;
            }
        }

        void Reset()
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            if (intro)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            }

            _Reset();
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            if (!_startCombat)
            {
                _startCombat = true;
                Talk(2);// me->Yell("Seal the gate, and inform the overseer immediately.");
                instance->SetData(me->GetEntry(), SPECIAL);
                if (Creature* c = me->FindNearestCreature(NPC_PATCH,100.f))
                    c->GetAI()->DoAction(7);
            }
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.Reset();
            events.ScheduleEvent(1, urand(8000, 12000));
            events.ScheduleEvent(2, urand(14000, 27000));
            events.ScheduleEvent(3, urand(8000, 9000));
            events.ScheduleEvent(4, 10);//not correct at all but it should be fine for now, more of a visual
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(me->GetEntry(), DONE);
            }               
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1://Twisted Elements
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 15.0f, true))
                        DoCast(target, SPELL_TWISTED_ELEMENTS);
                    events.ScheduleEvent(1, urand(4000, 7000));
                    break;
                case 2://Glacial Freeze Totem
                    DoCast(SPELL_GLACIAL_TOTEM);
                    events.ScheduleEvent(2, urand(14000, 27000));
                    break;
                case 3://Ruined Earth
                    DoCast(SPELL_RUINED_EARTH);
                    events.ScheduleEvent(3, urand(8000, 9000));
                    break;
                case 4:
                    if (GameObject* pDoor = me->FindNearestGameObject(220169, 440.0f))
                    {
                        pDoor->SetLootState(GO_READY);
                        pDoor->UseDoorOrButton(10000 * 999, false, me);
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        bool intro;
        bool _startCombat;
        InstanceScript* instance;
    };
};
//71262
class npc_ruined_earth_71262 : public CreatureScript
{
public:
    npc_ruined_earth_71262() : CreatureScript("npc_ruined_earth_71262") { }

    struct npc_ruined_earth_71262AI : public ScriptedAI
    {
        npc_ruined_earth_71262AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void Reset() override
        {
            DoCast(142310);
            events.ScheduleEvent(1, 6000);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    me->RemoveAura(142310);
                    DoCast(142311);
                    break;
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ruined_earth_71262AI(creature);
    }
};
//71323
class npc_glacial_freeze_totem : public CreatureScript
{
public:
    npc_glacial_freeze_totem() : CreatureScript("npc_glacial_freeze_totem") { }

    struct npc_glacial_freeze_totemAI : public ScriptedAI
    {
        npc_glacial_freeze_totemAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.ScheduleEvent(1, 2000);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(142322);
                    events.ScheduleEvent(1, 2000);
                    break;
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_glacial_freeze_totemAI(creature);
    }
};
//71244
class ragefire_core_npc_korkron_shadowblade : public CreatureScript
{
public:
    ragefire_core_npc_korkron_shadowblade() : CreatureScript("ragefire_core_npc_korkron_shadowblade") { }

    struct ragefire_core_npc_korkron_shadowbladeAI : public ScriptedAI
    {
        ragefire_core_npc_korkron_shadowbladeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            events.Reset();
            _shadowStep = true;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 22)
            {
                me->SetInCombatWithZone();
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
                instance->SetData(me->GetEntry(), DONE);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.ScheduleEvent(1, urand(13000, 15000));
            instance->SetData(me->GetEntry(), SPECIAL);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                if (Creature* boss = me->FindNearestCreature(70683, 28.0f))
                {
                    me->SetInCombatWithZone();
                }
                break;
            case 10:
                events.ScheduleEvent(10, 1000);
                me->SetInCombatWithZone();
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (_shadowStep && me->GetDistance2d(me->GetVictim()) <= 40.0f)
            {
                _shadowStep = false;
                DoCastVictim(80576);//ShadowStep can be143262, wowhead says 80576
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    _shadowStep = true;
                    events.ScheduleEvent(1, urand(13000, 15000));
                    break;
                case 10:
                    if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_3, 30.0f))
                        me->GetMotionMaster()->MovePoint(22, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), false);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        bool _shadowStep;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_korkron_shadowbladeAI(creature);
    }
};

enum korkronDarkShamanSpells
{
    SPELL_ELECTRIFIED_GROUND = 145547,
    SPELL_LAVA_BURST = 142338,
    SPELL_POISON_BOLT_TOTEM = 145549,
};
//71245
class ragefire_core_npc_korkron_dark_shaman : public CreatureScript
{
public:
    ragefire_core_npc_korkron_dark_shaman() : CreatureScript("ragefire_core_npc_korkron_dark_shaman") { }

    struct ragefire_core_npc_korkron_dark_shamanAI : public ScriptedAI
    {
        ragefire_core_npc_korkron_dark_shamanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            events.Reset();
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 22)
            {
                me->SetInCombatWithZone();
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SetData(me->GetEntry(), DONE);
                instance->SetData(me->GetEntry(), SPECIAL);
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.ScheduleEvent(1, urand(10000, 12000));
            events.ScheduleEvent(2, urand(6000, 8000));//reset 8 sec
            events.ScheduleEvent(3, urand(20000, 30000)); //reset 20-30
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case 1:
                if (Creature* boss = me->FindNearestCreature(70683, 28.0f))
                {
                    me->SetInCombatWithZone();
                }
                break;
            case 10:
                me->SetInCombatWithZone();
                events.ScheduleEvent(10, 1000);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_ELECTRIFIED_GROUND);
                    events.ScheduleEvent(1, urand(20000, 30000));
                    break;
                case 2:
                    DoCastVictim(SPELL_LAVA_BURST);
                    events.ScheduleEvent(2, 8000);
                    break;
                case 3:
                    DoCast(SPELL_POISON_BOLT_TOTEM);
                    events.ScheduleEvent(3, urand(20000, 30000));
                    break;
                case 10:
                    if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_3, 30.0f))
                        me->GetMotionMaster()->MovePoint(22, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), false);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new ragefire_core_npc_korkron_dark_shamanAI(creature);
    }
};
//71097 - npc_ragefire_core_ragefire_peon
class npc_ragefire_core_ragefire_peon : public CreatureScript
{
public:
    npc_ragefire_core_ragefire_peon() : CreatureScript("npc_ragefire_core_ragefire_peon") { }

    struct npc_ragefire_core_ragefire_peonAI : public ScriptedAI
    {
        npc_ragefire_core_ragefire_peonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                me->GetMotionMaster()->MovePoint(2, 1535.967896f, 1028.711792f, 38.705750f);
            if (id == 2)
                me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_ragefire_peonAI(creature);
    }
};
//70901 71203 npc_ragefire_core_supply_crates
class npc_ragefire_core_supply_crates : public CreatureScript
{
public:
    npc_ragefire_core_supply_crates() : CreatureScript("npc_ragefire_core_supply_crates") { }

    struct npc_ragefire_core_supply_cratesAI : public ScriptedAI
    {
        npc_ragefire_core_supply_cratesAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            instance = me->GetInstanceScript();
            pGossip = false;
        }

        bool pGossip;
        InstanceScript* instance;

        void sGossipHello(Player* player)
        {
            if (!pGossip)
            {
                pGossip = true;
                if (instance)
                    instance->SetData(me->GetEntry(), DONE);
                if (Creature* c = me->FindNearestCreature(NPC_VOLT, 100.f))
                    c->AI()->Talk(0);// Say(c, "These supply crates came from Orgrimmar. What is Garrosh planning to do with so many war supplies?");
            }
            SendGossipMenuFor(player, player->GetEntry(), me->GetGUID());
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_supply_cratesAI(creature);
    }
};
//71031 71208 npc_ragefire_core_protodrake_eggs
class npc_ragefire_core_protodrake_eggs : public CreatureScript
{
public:
    npc_ragefire_core_protodrake_eggs() : CreatureScript("npc_ragefire_core_protodrake_eggs") { }

    struct npc_ragefire_core_protodrake_eggsAI : public ScriptedAI
    {
        npc_ragefire_core_protodrake_eggsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            instance = me->GetInstanceScript();
            pGossip = false;
        }

        bool pGossip;
        InstanceScript* instance;

        void sGossipHello(Player* player)
        {
            if (!pGossip)
            {
                pGossip = true;
                if (instance)
                    instance->SetData(me->GetEntry(), DONE);
                if (Creature* c = me->FindNearestCreature(NPC_GRIT, 100.f))
                    c->AI()->Talk(0, player);// MonsterSay("Protodrakes eggs... Is Garrosh working with the Dragonmaw? Orcs on protodrakes sounds bad to me, $n, very bad.", 0, player->GetGUID());
            }
            SendGossipMenuFor(player, player->GetEntry(), me->GetGUID());
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_protodrake_eggsAI(creature);
    }
};
//71032 71209 npc_ragefire_core_pandaria_artifacts
class npc_ragefire_core_pandaria_artifacts : public CreatureScript
{
public:
    npc_ragefire_core_pandaria_artifacts() : CreatureScript("npc_ragefire_core_pandaria_artifacts") { }

    struct npc_ragefire_core_pandaria_artifactsAI : public ScriptedAI
    {
        npc_ragefire_core_pandaria_artifactsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            instance = me->GetInstanceScript();
            pGossip = false;
        }

        bool pGossip;
        InstanceScript* instance;

        void sGossipHello(Player* player)
        {
            if (!pGossip)
            {
                pGossip = true;
                if (instance)
                    instance->SetData(me->GetEntry(), DONE);
                if (Creature* c = me->FindNearestCreature(NPC_VOLT, 100.f))
                    c->AI()->Talk(0);// Say(c, "These are from the dig site in the Vale of Eternal Blossoms. What is Garrosh trying to find there?");
            }
            SendGossipMenuFor(player, player->GetEntry(), me->GetGUID());
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_pandaria_artifactsAI(creature);
    }
};

class npc_ragefire_stage3 : public CreatureScript
{
public:
    npc_ragefire_stage3() : CreatureScript("npc_ragefire_stage3") { }

    struct npc_ragefire_stage3AI : public ScriptedAI
    {
        npc_ragefire_stage3AI(Creature* creature) : ScriptedAI(creature), startUpdate(false), spawned(false)
        {
            instance = me->GetInstanceScript();
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        InstanceScript* instance;

        void DoAction(const int32 action) override
        {
            if (action == 1)
            {
                startUpdate = true;
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }

        void OnSpellClick(Unit* clicker, bool& /*result*/) override
        {
            if (spawned)
                return;

            switch (me->GetEntry())
            {
            case NPC_BATTERY:
                //SendNotifiactionToMap(me->GetMap(), "|cffFFFF00Embercores wakes from the lava!");
                events.ScheduleEvent(1, 500);
                break;
            case NPC_EGG_YOLK:
                events.ScheduleEvent(2, 500);
                break;
            }
            spawned = true;
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startUpdate = false;
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!startUpdate)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1://embercore
                    if (Creature* emberCore = me->SummonCreature(70663, 1383.007935f, 985.9666553f, 31.678915f, 6.0f, TEMPSUMMON_MANUAL_DESPAWN))
                        emberCore->GetAI()->DoAction(1);
                    if (Creature* emberCore = me->SummonCreature(70663, 1386.297974f, 974.14063f, 33.518883f, 1.110001f, TEMPSUMMON_MANUAL_DESPAWN))
                        emberCore->GetAI()->DoAction(1);
                    if (Creature* emberCore = me->SummonCreature(70663, 1388.084229f, 1019.177124f, 31.682781f, 1.110001f, TEMPSUMMON_MANUAL_DESPAWN))
                        emberCore->GetAI()->DoAction(1);
                    break;
                case 2:

                    break;
                }
            }
        }

    private:
        bool startUpdate;
        bool spawned;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_stage3AI(creature);
    }
};
//70663
class npc_ragefire_embercore : public CreatureScript
{
public:
    npc_ragefire_embercore() : CreatureScript("npc_ragefire_embercore") { }

    struct npc_ragefire_core_embercoreAI : public ScriptedAI
    {
        npc_ragefire_core_embercoreAI(Creature* creature) : ScriptedAI(creature), startTicking(false)
        {
            instance = me->GetInstanceScript();
            DoCast(me, 141186);

            if (Player* player = me->SelectNearestPlayer(200.0f))
                me->SetLevel(player->getLevel());
        }

        InstanceScript* instance;

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startTicking = false;
        }

        void MovementInform(uint32 /*data*/, uint32 id) override
        {
            if (id == 1)
            {
                startTicking = true;
                chooseNewVictim();
                events.ScheduleEvent(1, urand(2000, 5000));
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == 1)
            {
                startTicking = true;
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 15.0f, false);
            }
        }

        void chooseNewVictim()
        {
            me->SetInCombatWithZone();
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!startTicking)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (UpdateVictim())
                        DoCastVictim(142298);//burning embers;
                    else
                        chooseNewVictim();
                    events.ScheduleEvent(1, 8000);
                    break;
                }
            }
        }

    private:
        bool startTicking;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_embercoreAI(creature);
    }
};
//71174
class npc_ragefire_core_mantid_bomb : public CreatureScript
{
public:
    npc_ragefire_core_mantid_bomb() : CreatureScript("npc_ragefire_core_mantid_bomb") { }

    struct npc_ragefire_core_mantid_bombAI : public ScriptedAI
    {
        npc_ragefire_core_mantid_bombAI(Creature* creature) : ScriptedAI(creature), startUpdate(false)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void DoAction(const int32 action) override
        {
            if (action == 1)
            {
                startUpdate = true;
                events.ScheduleEvent(1, 1000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startUpdate = false;
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!startUpdate)
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_HUGE_EXPLOSION);
                    me->DespawnOrUnsummon(500);
                    instance->SetData(me->GetEntry(), DONE);
                    break;
                }
            }
        }

    private:
        bool startUpdate;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_mantid_bombAI(creature);
    }
};
//70665
class npc_ragefire_core_kor_kron_dire_soldier : public CreatureScript
{
public:
    npc_ragefire_core_kor_kron_dire_soldier() : CreatureScript("npc_ragefire_core_kor_kron_dire_soldier") { }

    struct npc_ragefire_core_kor_kron_dire_soldierAI : public ScriptedAI
    {
        npc_ragefire_core_kor_kron_dire_soldierAI(Creature* creature) : ScriptedAI(creature), startUpdate(false)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 22)
            {
                me->SetInCombatWithZone();
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == 10)
            {
                me->SetInCombatWithZone();
                startUpdate = true;
                events.ScheduleEvent(1, 1000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startUpdate = false;
            instance->SetData(me->GetEntry(), SPECIAL);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_3, 30.0f))
                        me->GetMotionMaster()->MovePoint(22, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), false);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        bool startUpdate;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_kor_kron_dire_soldierAI(creature);
    }
};
//70702
class npc_ragefire_core_flame_hound : public CreatureScript
{
public:
    npc_ragefire_core_flame_hound() : CreatureScript("npc_ragefire_core_flame_hound") { }

    struct npc_ragefire_core_flame_houndAI : public ScriptedAI
    {
        npc_ragefire_core_flame_houndAI(Creature* creature) : ScriptedAI(creature), startUpdate(false)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 22)
            {
                me->SetInCombatWithZone();
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == 10)
            {
                me->SetInCombatWithZone();
                startUpdate = true;
                events.ScheduleEvent(1, 1000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startUpdate = false;
            instance->SetData(me->GetEntry(), SPECIAL);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_3, 30.0f))
                        me->GetMotionMaster()->MovePoint(22, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), false);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        bool startUpdate;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_flame_houndAI(creature);
    }
};
//70798
class npc_ragefire_core_kor_kron_emberguard : public CreatureScript
{
public:
    npc_ragefire_core_kor_kron_emberguard() : CreatureScript("npc_ragefire_core_kor_kron_emberguard") { }

    struct npc_ragefire_core_kor_kron_emberguardAI : public ScriptedAI
    {
        npc_ragefire_core_kor_kron_emberguardAI(Creature* creature) : ScriptedAI(creature), startUpdate(false)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 22)
            {
                me->SetInCombatWithZone();
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == 10)
            {
                me->SetInCombatWithZone();
                startUpdate = true;
                events.ScheduleEvent(1, 1000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            startUpdate = false;
            instance->SetData(me->GetEntry(), SPECIAL);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_3, 30.0f))
                        me->GetMotionMaster()->MovePoint(22, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), false);
                    me->SetInCombatWithZone();
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        bool startUpdate;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragefire_core_kor_kron_emberguardAI(creature);
    }
};

enum overseerSpells
{
    SPELL_SHATTERING_CHARGE = 142773,
    SPELL_DEMOLISH_ARMOR = 142764,
    SPELL_SHATTERING_STOMP = 142771,
};
//71030
class boss_ragefire_overseer_elaglo : public CreatureScript
{
public:
    boss_ragefire_overseer_elaglo() : CreatureScript("boss_ragefire_overseer_elaglo") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ragefire_overseer_elagloAI(pCreature);
    }

    struct boss_ragefire_overseer_elagloAI : public BossAI
    {
        boss_ragefire_overseer_elagloAI(Creature* pCreature) : BossAI(pCreature, 0)
        {
            instance = me->GetInstanceScript();
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_DEFENSIVE);
        }

        InstanceScript* instance;

        void DoAction(const int32 action) override
        {
        }

        void Reset()
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            _Reset();
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            _EnterCombat();
            DoCastVictim(SPELL_SHATTERING_CHARGE);
            events.ScheduleEvent(1, urand(3000, 20000));
            events.ScheduleEvent(2, urand(10000, 20000));
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(me->GetEntry(), DONE);
            }              
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCastVictim(SPELL_DEMOLISH_ARMOR);
                    events.ScheduleEvent(1, urand(10000, 20000));
                    break;
                case 2:
                    DoCast(SPELL_SHATTERING_STOMP);
                    events.ScheduleEvent(2, urand(10000, 20000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};
//stage 3 the sealed gate

//misc spells found in sniffs
/*
Holding Bomb - 141806
Unconscious - 141985
Self Set on Fire - 141964
*/
//misc npcs
//protodrake whelp - 71401
//Holding battery - 141904
//holding cannon ball - 141832
//egg yolk - 141914
//stage 4
//dire rage - 142760 Kor'kron dire soldier uses

//this is custom
class npc_eredar_felcaller_98005 : public CreatureScript //CID : 98005
{
public:
    npc_eredar_felcaller_98005() : CreatureScript("npc_eredar_felcaller_98005")
    {
    }

    struct npc_eredar_felcaller_98005AI : public ScriptedAI
    {
        InstanceScript* instance;

        void Reset()
        {
            instance = me->GetInstanceScript();

            if (!instance)
                me->DespawnOrUnsummon(1);

            me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        }

        void DoAction(const int32 action) override
        {
            if (action == 1) // called on spawn
                events.ScheduleEvent(1, 2000);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    //if (Player* player = me->SelectNearestPlayer(200.0f))
                    //    me->MonsterSay("Very nice young $c", 0, player->GetGUID());
                    me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_TALK);
                    events.ScheduleEvent(2, 4000);
                    break;

                case 2:
                    //me->Say("Now for my next task.");
                    break;
                }
            }
        }
    };
};

void AddSC_scenario_the_secrets_of_ragefire()
{
    RegisterInstanceScript(scenario_the_secrets_of_ragefire, 1131);
    new ragefire_core_ticking_bomb();
    new ragefire_core_detonator();
    new ragefire_core_npc_volt();
    new ragefire_core_npc_grit();
    new ragefire_core_npc_newt();
    new ragefire_core_npc_patch();
    new ragefire_core_npc_ticker();
    new boss_ragefire_dark_shaman_xorenth();
    new npc_ruined_earth_71262();
    new npc_glacial_freeze_totem();
    new ragefire_core_npc_korkron_shadowblade();
    new ragefire_core_npc_korkron_dark_shaman();
    new npc_ragefire_core_ragefire_peon();
    new npc_ragefire_core_supply_crates();
    new npc_ragefire_core_protodrake_eggs();
    new npc_ragefire_core_pandaria_artifacts();
    new npc_ragefire_stage3();
    new npc_ragefire_embercore();
    new npc_ragefire_core_mantid_bomb();
    new npc_ragefire_core_kor_kron_dire_soldier();
    new npc_ragefire_core_flame_hound();
    new npc_ragefire_core_kor_kron_emberguard();
    new boss_ragefire_overseer_elaglo();
}
