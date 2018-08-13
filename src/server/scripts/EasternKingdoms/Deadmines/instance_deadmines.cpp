/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "deadmines.h"
#include "GameObject.h"

#define NOTE_TEXT "A note falls to the floor!"

Position const NoteSpawn = {-74.36111f, -820.0139f, 40.67145f, 4.014257f};

class instance_deadmines : public InstanceMapScript
{
public:
    instance_deadmines() : InstanceMapScript("instance_deadmines", 36) { }

    struct instance_deadmines_InstanceMapScript : public InstanceScript
    {
        instance_deadmines_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_BOSSES);
            IsVisionOfThePastRunning = false;
        };

        void OnCreatureCreate(Creature* creature) override
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->GetSource())
                    TeamInInstance = player->GetTeam();
            }
            switch (creature->GetEntry())
            {
                case 46889: // Kagtha
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(42308); // Lieutenant Horatio Laine
                    break;
                case 46902: // Miss Mayhem
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(491); // Quartermaster Lewis <Quartermaster>
                    break;
                case 46903: // Mayhem Reaper Prototype
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(1); // GM WAYPOINT
                    break;
                case 46906: // Slinky Sharpshiv
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(46612); // Lieutenant Horatio Laine
                    break;
                case 46613: // Crime Scene Alarm-O-Bot
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(1); // GM WAYPOINT
                    break;
                case 50595: // Stormwind Defender
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(46890); // Shattered Hand Assassin
                    break;
                case 46614: // Stormwind Investigator
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(1); // GM WAYPOINT
                    break;
                case NPC_VANESSA_VANCLEEF:
                    uiVanessa = creature->GetGUID();
                    break;
                case NPC_VANESSA_BOSS:
                    uiVanessaBoss = creature->GetGUID();
                    break;
                case NPC_VANESSA_NOTE:
                    uiVanessaNote = creature->GetGUID();
                    break;
                case NPC_GLUBTOK:
                    GlubtokGUID = creature->GetGUID();
                    break;
                case NPC_EDWIN_VANCLEEF:
                    EdwinVanCleefGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_VANESSA_VANCLEEF_2:
                    VanessaVanCleefGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_ALLIANCE_WARRIOR:
                    AllianceWarriorGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_ALLIANCE_HUNTER:
                    AllianceHunterGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_ALLIANCE_MAGE:
                    AllianceMageGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_ALLIANCE_PRIEST:
                    AlliancePriestGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;
                case NPC_ALLIANCE_ROGUE:
                    AllianceRogueGUID = creature->GetGUID();
                    if (creature->isDead())
                        creature->Respawn(true);
                    break;

            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_FACTORY_DOOR: // Door after first boss
                    FactoryDoorGUID = go->GetGUID();
                    break;
                case GO_FOUNDRY_DOOR: // Door before ship
                    FoundaryDoorGUID = go->GetGUID();
                    break;
                case GO_HEAVY_DOOR_HELIX:
                    HeavyDoorGUID = go->GetGUID();
                    break;
                case GO_IRONCLAD_DOOR:
                    IroncladDoorGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case DATA_NIGHTMARE_HELIX:
                    if (value == DONE)
                        if (GameObject* go = instance->GetGameObject(FoundaryDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DATA_NIGHTMARE_MECHANICAL:
                    if (value == DONE)
                        if (GameObject* go = instance->GetGameObject(IroncladDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DATA_GLUBTOK:
                    if (value == DONE)
                        if (GameObject* go = instance->GetGameObject(FactoryDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case EVENT_VISION_OF_THE_PAST:
                    if (value == IN_PROGRESS)
                        StartVisionOfThePastEvent();
                    else if (value == SPECIAL)
                        ResetVisionOfThePastEvent();
                    else if (value == DONE)
                        IsVisionOfThePastRunning = false;
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case EVENT_VISION_OF_THE_PAST:
                return IsVisionOfThePastRunning ? IN_PROGRESS : NOT_STARTED;
            }

            return 0;
        }

        void ResetVisionOfThePastEvent()
        {
            if (Creature* actor = instance->GetCreature(AllianceWarriorGUID))
                actor->Respawn(true);
            if (Creature* actor = instance->GetCreature(AlliancePriestGUID))
                actor->Respawn(true);
            if (Creature* actor = instance->GetCreature(AllianceRogueGUID))
                actor->Respawn(true);
            if (Creature* actor = instance->GetCreature(AllianceMageGUID))
                actor->Respawn(true);
            if (Creature* actor = instance->GetCreature(AllianceHunterGUID))
                actor->Respawn(true);
            if (Creature* actor = instance->GetCreature(EdwinVanCleefGUID))
                actor->Respawn(true);
        }

        void StartVisionOfThePastEvent()
        {
            if (!IsVisionOfThePastRunning)
            {
                if (Creature* actor = instance->GetCreature(AllianceWarriorGUID))
                    actor->AI()->DoAction(1);

                if (Creature* actor = instance->GetCreature(AllianceRogueGUID))
                    actor->AI()->DoAction(1);

                if (Creature* actor = instance->GetCreature(AlliancePriestGUID))
                    actor->AI()->DoAction(1);

                if (Creature* actor = instance->GetCreature(AllianceHunterGUID))
                    actor->AI()->DoAction(1);

                if (Creature* actor = instance->GetCreature(AllianceMageGUID))
                    actor->AI()->DoAction(1);

                if (Creature* actor = instance->GetCreature(EdwinVanCleefGUID))
                    actor->AI()->DoAction(1);

                IsVisionOfThePastRunning = true;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_GLUBTOK:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(FactoryDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DATA_HELIX:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(HeavyDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DATA_FOEREAPER:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(FoundaryDoorGUID))
                            go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case DATA_RIPSNARL:
                    //if (state == DONE)
                    //    break;
                    break;
                case DATA_COOKIE:
                    if (state == DONE)
                    {
                        if (instance->IsHeroic())
                        {
                            if (Creature* Note = instance->SummonCreature(NPC_VANESSA_NOTE, NoteSpawn))
                            {
                                Note->TextEmote(NOTE_TEXT, 0, true);

                                if (GameObject* go = instance->GetGameObject(IroncladDoorGUID))
                                    go->SetGoState(GO_STATE_READY);

                                if (GameObject* go = instance->GetGameObject(HeavyDoorGUID))
                                    go->SetGoState(GO_STATE_READY);

                                if (GameObject* go = instance->GetGameObject(FoundaryDoorGUID))
                                    go->SetGoState(GO_STATE_READY);

                            }
                        }
                    }
                    break;
                case DATA_VANNESSA_NIGHTMARE:
                    if (state == FAIL)
                    {
                        if (instance->SummonCreature(NPC_VANESSA_NOTE, NoteSpawn))
                        {
                            if (GameObject* go = instance->GetGameObject(IroncladDoorGUID))
                                go->SetGoState(GO_STATE_ACTIVE);

                            if (GameObject* go = instance->GetGameObject(HeavyDoorGUID))
                                go->SetGoState(GO_STATE_ACTIVE);

                            if (GameObject* go = instance->GetGameObject(FoundaryDoorGUID))
                                go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                case DATA_VANESSA:
                    break;
            }

            return true;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case NPC_VANESSA_VANCLEEF:
                    return uiVanessa;
                    break;
                case NPC_VANESSA_BOSS:
                    return uiVanessaBoss;
                    break;
                case NPC_VANESSA_NOTE:
                    return uiVanessaNote;
                    break;
                case DATA_GLUBTOK:
                    return GlubtokGUID;
                    break;
                case DATA_ALLIANCE_HUNTER:
                    return AllianceHunterGUID;
                    break;
                case DATA_ALLIANCE_MAGE:
                    return AllianceMageGUID;
                    break;
                case DATA_ALLIANCE_PRIEST:
                    return AlliancePriestGUID;
                    break;
                case DATA_ALLIANCE_WARRIOR:
                    return AllianceWarriorGUID;
                    break;
                case DATA_ALLIANCE_ROGUE:
                    return AllianceRogueGUID;
                    break;
                case DATA_VANESSA_VANCLEEF:
                    return VanessaVanCleefGUID;
                    break;
                case DATA_EDWIN_VANCLEEF:
                    return EdwinVanCleefGUID;
                    break;
            }

            return ObjectGuid::Empty;
        }

    private:
        ObjectGuid FactoryDoorGUID;
        ObjectGuid FoundaryDoorGUID;
        ObjectGuid HeavyDoorGUID;
        ObjectGuid IroncladDoorGUID;
        ObjectGuid uiVanessa;
        ObjectGuid uiVanessaNote;
        ObjectGuid uiVanessaBoss;
        ObjectGuid GlubtokGUID;

        ObjectGuid AllianceWarriorGUID;
        ObjectGuid AlliancePriestGUID;
        ObjectGuid AllianceRogueGUID;
        ObjectGuid AllianceHunterGUID;
        ObjectGuid AllianceMageGUID;
        ObjectGuid EdwinVanCleefGUID;
        ObjectGuid VanessaVanCleefGUID;

        uint32 TeamInInstance;
        bool IsVisionOfThePastRunning;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_deadmines_InstanceMapScript(map);
    }
};

void AddSC_instance_deadmines()
{
    new instance_deadmines();
}
