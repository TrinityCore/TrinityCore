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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "shadow_labyrinth.h"

DoorData const doorData[] =
{
    { GO_REFECTORY_DOOR,        DATA_BLACKHEART_THE_INCITER,    DOOR_TYPE_PASSAGE },
    { GO_SCREAMING_HALL_DOOR,   DATA_GRANDMASTER_VORPIL,        DOOR_TYPE_PASSAGE },
    { 0,                        0,                              DOOR_TYPE_ROOM } // END
};

class instance_shadow_labyrinth : public InstanceMapScript
{
    public:
        instance_shadow_labyrinth() : InstanceMapScript(SLScriptName, 555) { }

        struct instance_shadow_labyrinth_InstanceMapScript : public InstanceScript
        {
            instance_shadow_labyrinth_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                FelOverseerCount      = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_AMBASSADOR_HELLMAW:
                        AmbassadorHellmawGUID = creature->GetGUID();
                        break;
                    case NPC_BLACKHEART:
                        BlackheartGUID = creature->GetGUID();
                        break;
                    case NPC_BLACKHEART_DUMMY1:
                    case NPC_BLACKHEART_DUMMY2:
                    case NPC_BLACKHEART_DUMMY3:
                    case NPC_BLACKHEART_DUMMY4:
                    case NPC_BLACKHEART_DUMMY5:
                        BlackheartDummyGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_GRANDMASTER_VORPIL:
                        GrandmasterVorpilGUID = creature->GetGUID();
                        break;
                    case NPC_FEL_OVERSEER:
                        if (creature->IsAlive())
                        {
                            ++FelOverseerCount;
                            if (Creature* hellmaw = instance->GetCreature(AmbassadorHellmawGUID))
                                hellmaw->AI()->DoAction(ACTION_AMBASSADOR_HELLMAW_BANISH);
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_BLACKHEART_DUMMY1:
                    case NPC_BLACKHEART_DUMMY2:
                    case NPC_BLACKHEART_DUMMY3:
                    case NPC_BLACKHEART_DUMMY4:
                    case NPC_BLACKHEART_DUMMY5:
                        BlackheartDummyGUIDs.erase(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_REFECTORY_DOOR:
                    case GO_SCREAMING_HALL_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_REFECTORY_DOOR:
                    case GO_SCREAMING_HALL_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                if (creature->GetEntry() == NPC_FEL_OVERSEER)
                {
                    if (FelOverseerCount)
                        --FelOverseerCount;

                    if (!FelOverseerCount)
                        if (Creature* hellmaw = instance->GetCreature(AmbassadorHellmawGUID))
                            hellmaw->AI()->DoAction(ACTION_AMBASSADOR_HELLMAW_INTRO);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_FEL_OVERSEER:
                        return !FelOverseerCount ? 1 : 0;
                    default:
                        break;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BLACKHEART_THE_INCITER:
                        return BlackheartGUID;
                    case DATA_GRANDMASTER_VORPIL:
                        return GrandmasterVorpilGUID;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

            GuidUnorderedSet const& GetBlackheartDummies() const { return BlackheartDummyGUIDs; }

        protected:
            ObjectGuid AmbassadorHellmawGUID;
            ObjectGuid BlackheartGUID;
            GuidUnorderedSet BlackheartDummyGUIDs;
            ObjectGuid GrandmasterVorpilGUID;
            uint32 FelOverseerCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_shadow_labyrinth_InstanceMapScript(map);
        }
};

GuidUnorderedSet const* GetBlackheartDummies(InstanceScript const* s)
{
    if (auto* script = dynamic_cast<instance_shadow_labyrinth::instance_shadow_labyrinth_InstanceMapScript const*>(s))
        return &script->GetBlackheartDummies();
    return nullptr;

}

void AddSC_instance_shadow_labyrinth()
{
    new instance_shadow_labyrinth();
}
