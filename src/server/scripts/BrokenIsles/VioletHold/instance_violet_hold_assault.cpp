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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "Group.h"
#include "violet_hold_assault.h"

enum Events
{
    EVENT_CHECK_CRITERIA        = 1,
    EVENT_ACTIVATE_PRISONER_1   = 2,
    EVENT_ACTIVATE_PRISONER_2   = 3,
    EVENT_ACTIVATE_FINAL_BOSS   = 4,
    EVENT_INIT_ROUND            = 5,
};

const uint32 BossesId [] =
{
    BOSS_SHIVERMAW        ,
    BOSS_FESTERFACE       ,
    BOSS_ANUBESSET        ,
    BOSS_BLOOD_PRINCESS   ,
    BOSS_MANASTORM        ,
    BOSS_MINDFLAYER_KAARHJ,
};

const uint32 PortalKeepers [] =
{
    NPC_PORTAL_DREADLORD,
    NPC_PORTAL_FELGUARD,
    NPC_PORTAL_JAILER,
    NPC_PORTAL_INQUISITOR,
};

uint32 EliteSquad[] =
{
    NPC_BLAZING_INFERNAL,
    NPC_EREDAR_SHADOW_MENDER,
    NPC_INFILTRATOR_ASSASIN,
    NPC_WRATHLORD_BULWARK,
};

const uint32 SaelornSquad[] =
{
    NPC_ACOLYTE_OF_SAELORN,
    NPC_VENOMHIDE_SHADOWSPINNER,
    NPC_BROOD_OF_SAELORN,
};

const uint32 BeltrugSquad[] =
{
    NPC_WRATHGUARD_DECIMATOR,
    NPC_SHADOWY_OVERFIEND,
};

enum CriteriasIds
{
    CRITERIA_NORMAL_STAGE_1 = 52867,
    CRITERIA_NORMAL_STAGE_2 = 52913,
    CRITERIA_NORMAL_STAGE_3 = 52929,

    CRITERIA_HEROIC_STAGE_1 = 52948,
    CRITERIA_HEROIC_STAGE_2 = 52963,
    CRITERIA_HEROIC_STAGE_3 = 52980,

    CRITERIA_MYTHIC_STAGE_1 = 56177,
    CRITERIA_MYTHIC_STAGE_2 = 56192,
    CRITERIA_MYTHIC_STAGE_3 = 56209,

    CRITERIA_BOSS_1_DONE    = 24858,
    CRITERIA_BOSS_2_DONE    = 24859,
    CRITERIA_FINAL_BOSS     = 29505,
};

using NpcInfo = std::pair<uint32, ObjectGuid>;

struct NpcInfoCmp
{
    explicit NpcInfoCmp(uint32 entry) : _entry(entry)
    {}

    bool operator() (const NpcInfo & npc_1)
    {
        return npc_1.first == _entry;
    }

    private:
        uint32 _entry;
};

class instance_violet_hold_assault : public InstanceMapScript
{
    public:
        instance_violet_hold_assault() : InstanceMapScript(VHAScriptName, 1544) { }

        struct instance_violet_hold_assault_InstanceScript : public InstanceScript
        {
            instance_violet_hold_assault_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                _firstBoss = BossesId[urand(0, 5)];
                _secondBoss = BossesId[urand(0, 5)];

                while (_secondBoss == _firstBoss)
                    _secondBoss = BossesId[urand(0,5)];

                if (Difficulty(instance->GetDifficultyID()) == DIFFICULTY_MYTHIC)
                    _criteriaToFind = CRITERIA_MYTHIC_STAGE_1;
                else if (Difficulty(instance->GetDifficultyID()) == DIFFICULTY_HEROIC)
                    _criteriaToFind = CRITERIA_HEROIC_STAGE_1;
                else
                    _criteriaToFind = CRITERIA_NORMAL_STAGE_1;

                _eliteDead = 0;
                _eventInitiated = false;
                _commanderEntry = ((urand(0,1)) ? BOSS_SAELORN : BOSS_BELTRUG);

            }

            void OnPlayerEnter(Player* player) override
            {
                if (!player)
                    return;

                if (!_eventInitiated)
                {
                    _eventInitiated = true;
                    _events.ScheduleEvent(EVENT_CHECK_CRITERIA, Seconds(15));
                    _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(15));
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (!unit)
                    return;
/*
                switch (unit->GetEntry())
                {
                    case NPC_PORTAL_JAILER:
                    case NPC_PORTAL_DREADLORD:
                    case NPC_PORTAL_FELGUARD:
                    case NPC_PORTAL_INQUISITOR:
                    {
                        CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(_criteriaToFind);
                        if (!instance->GetInstanceScenario()->CheckCompletedCriteriaTree(tree, nullptr))
                            _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(20));
                        break;
                    }

                    case NPC_BLAZING_INFERNAL:
                    case NPC_EREDAR_SHADOW_MENDER:
                    case NPC_INFILTRATOR_ASSASIN:
                    case NPC_WRATHLORD_BULWARK:
                    case NPC_ACOLYTE_OF_SAELORN:
                    case NPC_VENOMHIDE_SHADOWSPINNER:
                    case NPC_BROOD_OF_SAELORN:
                    case NPC_WRATHGUARD_DECIMATOR:
                    case NPC_SHADOWY_OVERFIEND:
                    {
                        _eliteDead++;
                        CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(_criteriaToFind);
                        if (!instance->ToInstanceMap()->GetInstanceScenario()->CheckCompletedCriteriaTree(tree, nullptr))
                        {
                            if (_firstBoss != 0 && _eliteDead >= 3)
                            {
                                _eliteDead = 0;
                                _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(20));
                            }
                            else if (_commanderEntry == BOSS_SAELORN && _eliteDead >= 3)
                            {
                                _eliteDead = 0;
                                _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(20));
                            }
                            else if (_commanderEntry == BOSS_BELTRUG && _eliteDead >= 2)
                            {
                                _eliteDead = 0;
                                _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(20));
                            }
                        }
                        break;
                    }

                    default : break;
                }*/
            }

            void TriggerCriteria(uint32 /*entry*/)
            {
                /*auto it = std::find_if(_guids.begin(), _guids.end(), NpcInfoCmp(entry));

                if (it != _guids.end())
                {
                    if (entry == BOSS_SAELORN || entry == BOSS_BELTRUG)
                        FREAKZ::Achievements::TriggerCriteriaToAllPlayersInMap(instance->GetCreature((*it).second), CRITERIA_FINAL_BOSS);
                    else if (_firstBoss == 0 && _secondBoss != 0)
                        FREAKZ::Achievements::TriggerCriteriaToAllPlayersInMap(instance->GetCreature((*it).second), CRITERIA_BOSS_1_DONE);
                    else if (_secondBoss == 0) // Second Prisoner
                        FREAKZ::Achievements::TriggerCriteriaToAllPlayersInMap(instance->GetCreature((*it).second), CRITERIA_BOSS_2_DONE);
                }*/
            }

            void UpdateCriteriaToCheck()
            {
                if (_firstBoss == 0 && _secondBoss != 0)
                {
                    if (instance->GetDifficultyID() == DIFFICULTY_MYTHIC)
                        _criteriaToFind = CRITERIA_MYTHIC_STAGE_2;
                    else if (instance->GetDifficultyID() == DIFFICULTY_HEROIC)
                        _criteriaToFind = CRITERIA_HEROIC_STAGE_2;
                    else
                        _criteriaToFind = CRITERIA_NORMAL_STAGE_2;
                }
                else if (_secondBoss == 0)
                {
                    if (instance->GetDifficultyID() == DIFFICULTY_MYTHIC)
                        _criteriaToFind = CRITERIA_MYTHIC_STAGE_3;
                    else if (instance->GetDifficultyID() == DIFFICULTY_HEROIC)
                        _criteriaToFind = CRITERIA_HEROIC_STAGE_3;
                    else
                        _criteriaToFind = CRITERIA_NORMAL_STAGE_3;
                }
            }

            void SpawnPortalMinions(Creature*& portal)
            {
                if (!portal)
                    return;

                if (roll_chance_f(50)) // Spawn a Normal Squadron
                {
                    Creature* keeper = portal->SummonCreature(PortalKeepers[urand(0,3)], portal->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 10000);
                    keeper->GetMotionMaster()->MovePoint(0, keeper->GetNearPosition(5,0));
                    portal->GetAI()->DoAction(1); // ACTION_SPAWN_MINION
                }
                else // Spawn a Elite Squadron
                {
                    _eliteDead = 0;
                    if (_firstBoss != 0) // Squadron before first prisoner escaped
                    {
                        Trinity::Containers::RandomShuffle(EliteSquad);
                        if (roll_chance_i(45))
                            for (auto & it : EliteSquad)
                                portal->SummonCreature(it, portal->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 10 * IN_MILLISECONDS);
                        else
                            for (uint8 i = 0; i < 3; ++i)
                                portal->SummonCreature(EliteSquad[i], portal->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 10 * IN_MILLISECONDS);
                    }
                    else // Squadron After First Prisoner Defeated
                    {
                        if (_commanderEntry == BOSS_SAELORN)
                            for (auto & it : SaelornSquad)
                                portal->SummonCreature(it, portal->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 10 * IN_MILLISECONDS);
                        else if (_commanderEntry == BOSS_BELTRUG)
                            for (auto & it : BeltrugSquad)
                                portal->SummonCreature(it, portal->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 10 * IN_MILLISECONDS);
                    }
                    portal->RemoveAllAuras();
                }
            }

            void UnlockDoor(Creature*& prisoner)
            {
                if (!prisoner)
                    return;

                uint32 door_entry = 0;
                switch (prisoner->GetEntry())
                {
                    case BOSS_ANUBESSET:
                        door_entry = GO_ANUBESSET_DOOR;
                        break;

                    case BOSS_BLOOD_PRINCESS:
                        door_entry = GO_THALENA_DOOR;
                        break;

                    case BOSS_SHIVERMAW:
                        door_entry = GO_SHIVERMAW_DOOR;
                        break;

                    case BOSS_MINDFLAYER_KAARHJ:
                        door_entry = GO_KAARHJ_DOOR;
                        break;

                    case BOSS_FESTERFACE:
                        door_entry = GO_FESTERFACE_DOOR;
                        break;

                    case BOSS_MANASTORM:
                        door_entry = GO_MANASTORM_DOOR;
                        break;

                    default : break;
                }

                if (door_entry == 0)
                    return;

                if (GameObject* go = prisoner->FindNearestGameObject(door_entry, 50.f))
                    go->SetGoState(GO_STATE_ACTIVE);
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                if (id != DATA_SAELORN && id != DATA_BELTRUG)
                {
                    if (state == DONE)
                    {
                        switch (id)
                        {
                            case DATA_ANUBESSET:
                                TriggerCriteria(BOSS_ANUBESSET);
                                break;

                            case DATA_MANASTORM:
                                TriggerCriteria(BOSS_MANASTORM);
                                break;

                            case DATA_SHIVERMAW:
                                TriggerCriteria(BOSS_SHIVERMAW);
                                break;
                            case DATA_BLOOD_PRINCESS:
                                TriggerCriteria(BOSS_BLOOD_PRINCESS);
                                break;

                            case DATA_MINDFLAYER_KAARHJ:
                                TriggerCriteria(BOSS_MINDFLAYER_KAARHJ);
                                break;
                            case DATA_FESTERFACE:
                                TriggerCriteria(BOSS_FESTERFACE);
                                break;
                        }

                        UpdateCriteriaToCheck();
                        _events.ScheduleEvent(EVENT_INIT_ROUND, Seconds(30));
                        _events.ScheduleEvent(EVENT_CHECK_CRITERIA, Seconds(10));
                    }
                }
                else if (id == DATA_SAELORN && state == DONE)
                    TriggerCriteria(BOSS_SAELORN);
                else if (id == DATA_BELTRUG && state == DONE)
                    TriggerCriteria(BOSS_BELTRUG);

                return true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!creature)
                    return;

                if (creature->GetEntry() == NPC_PORTAL_LEGION)
                    _portals.push_back(creature);

                switch (creature->GetEntry())
                {
                    case BOSS_SHIVERMAW:
                    case BOSS_MANASTORM:
                    case BOSS_ANUBESSET:
                    case BOSS_BLOOD_PRINCESS:
                    case BOSS_FESTERFACE:
                    case BOSS_MINDFLAYER_KAARHJ:
                        creature->SetFaction(35);
                        _guids.push_back(NpcInfo(creature->GetEntry(), creature->GetGUID()));
                        break;

                    case BOSS_BELTRUG:
                    case BOSS_SAELORN:
                        creature->SetFaction(35);
                        creature->SetVisible(false);
                        _guids.push_back(NpcInfo(creature->GetEntry(), creature->GetGUID()));
                        break;

                    default : break;
                }
            }

            /*void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_CRITERIA:
                        {
                            CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(_criteriaToFind);
                            if (instance->ToInstanceMap()->GetInstanceScenario()->CheckCompletedCriteriaTree(tree, nullptr))
                            {
                                _events.Reset();

                                if (_firstBoss != 0)
                                    _events.ScheduleEvent(EVENT_ACTIVATE_PRISONER_1, Seconds(15));
                                else if (_secondBoss != 0)
                                    _events.ScheduleEvent(EVENT_ACTIVATE_PRISONER_2, Seconds(15));
                                else
                                    _events.ScheduleEvent(EVENT_ACTIVATE_FINAL_BOSS, Seconds(15));
                            }
                            else
                                _events.ScheduleEvent(EVENT_CHECK_CRITERIA, Seconds(1));
                            break;
                        }

                        case EVENT_INIT_ROUND:
                        {
                            Creature* portal = Trinity::Containers::SelectRandomContainerElement(_portals);
                            if (portal)
                                portal->CastSpell(portal, 201901, true);
                            SpawnPortalMinions(portal);
                            break;
                        }

                        case EVENT_ACTIVATE_PRISONER_1:
                        {
                            auto it = std::find_if(_guids.begin(), _guids.end(), NpcInfoCmp(_firstBoss));

                            if (it != _guids.end())
                            {
                                Creature* boss = instance->GetCreature((*it).second);
                                if (boss)
                                {
                                    UnlockDoor(boss);
                                    boss->RemoveAllAuras();
                                    boss->SetFaction(16);
                                    boss->GetMotionMaster()->MovePoint(0, boss->GetNearPosition(10, 0));
                                }

                                _firstBoss = 0;
                            }
                            break;
                        }

                        case EVENT_ACTIVATE_PRISONER_2:
                        {
                            auto it = std::find_if(_guids.begin(), _guids.end(), NpcInfoCmp(_secondBoss));

                            if (it != _guids.end())
                            {
                                Creature* boss = instance->GetCreature((*it).second);
                                if (boss)
                                {
                                    UnlockDoor(boss);
                                    boss->RemoveAllAuras();
                                    boss->SetFaction(16);
                                    boss->GetMotionMaster()->MovePoint(0, boss->GetNearPosition(10, 0));
                                }

                                _secondBoss = 0;
                            }
                            break;
                        }

                        case EVENT_ACTIVATE_FINAL_BOSS:
                        {
                            auto it = std::find_if(_guids.begin(), _guids.end(), NpcInfoCmp(_commanderEntry));

                            if (it != _guids.end())
                            {
                                Creature* boss = instance->GetCreature((*it).second);

                                if (boss)
                                {
                                    boss->SetVisible(true);
                                    boss->NearTeleportTo(CenterRoom, true);
                                    boss->RemoveAllAuras();
                                    boss->SetFaction(16);
                                }
                            }

                            break;
                        }

                        default : break;
                    }
                }

            }*/

            private:
                uint8 _eliteDead;
                uint32 _criteriaToFind;
                uint32 _firstBoss, _secondBoss, _commanderEntry;
                bool _eventInitiated;
                EventMap _events;
                std::vector<Creature*> _portals;
                std::vector<NpcInfo> _guids;
        };



        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_violet_hold_assault_InstanceScript(map);
        }
};

void AddSC_instance_violet_hold_assault()
{
    new instance_violet_hold_assault();
}
