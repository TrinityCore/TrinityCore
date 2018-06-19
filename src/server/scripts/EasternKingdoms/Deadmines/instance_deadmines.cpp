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

        uint32 TeamInInstance;
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
