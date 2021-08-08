/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "MiscPackets.h"
#include "pursuing_the_black_harvest.h"

class instance_pursuing_the_black_harvest : public InstanceMapScript
{
public:
    instance_pursuing_the_black_harvest() : InstanceMapScript("instance_pursuing_the_black_harvest", 1112) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_pursuing_the_black_harvest_InstanceMapScript(map);
    }

    struct instance_pursuing_the_black_harvest_InstanceMapScript : public InstanceScript
    {
        instance_pursuing_the_black_harvest_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
            essenceData = 0;
            nodelData = 0;
            kanrethadData = 0;
            sceneEventData = 0;
            plunderData = 0;
            stage2Data = 0;
            allowedStage = STAGE_1;

            akamaGUID.Clear();
            jubekaGUID.Clear();
            doorGUID.Clear();
            secondDoorGUID.Clear();
            trashP2GUIDs.clear();
            trapGUIDs.clear();
            soulGUIDs.clear();
            treasuresGUIDs.clear();
        }

        void OnPlayerEnter(Player* player) override
        {
            std::vector<WorldPackets::Misc::PhaseShiftDataPhase> phaseIds;
            std::vector<uint16> terrainswaps;
            std::vector<uint16> WorldMapAreaIds;
            WorldMapAreaIds.emplace_back(992);
            WorldMapAreaIds.emplace_back(683);
            phaseIds.emplace_back(1982);
            player->GetSession()->SendSetPhaseShift(phaseIds, terrainswaps, WorldMapAreaIds, {}, 16);

            player->CastSpell(player, SPELL_ENTER_THE_BLACK_TEMPLE);
            player->CastSpell(player, SPELL_CSA_AT_DUMMY_TIMED_AURA);
            player->CastSpell(player, SPELL_WHAT_THE_DRAENEI_FOUND_INTRO);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ESSENCE_OF_ORDER:
                    creature->SetVisible(false);
                    break;
                case NPC_AKAMA:
                    creature->SetVisible(false);
                    akamaGUID = creature->GetGUID();
                    break;
                case NPC_JUBEKA_SHADOWBREAKER:
                    creature->SetVisible(false);
                    jubekaGUID = creature->GetGUID();
                    break;
                case NPC_UNBOUND_NIGHTLORD:
                case NPC_UNBOUND_CENTURION:
                case NPC_UNBOUND_BONEMENDER:
                case NPC_PORTALS_VISUAL:
                case NPC_FREED_IMP:
                case NPC_UNBOUND_SUCCUB:
                    creature->SetVisible(false);
                    creature->SetReactState(REACT_PASSIVE);
                    trashP2GUIDs.push_back(creature->GetGUID());
                    break;
                case NPC_SUFFERING_SOUL_FRAGMENT:
                    soulGUIDs.push_back(creature->GetGUID());
                    break;
                case NPC_ASHTONGUE_SHAMAN:
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_TEMPLATE_DOORS:
                    doorGUID = go->GetGUID();
                    break;
                case GO_SECOND_DOOR:
                    secondDoorGUID = go->GetGUID();
                    break;
                case GO_TRAP:
                    trapGUIDs.push_back(go->GetGUID());
                    break;
                case GO_TREASURE_CHEST:
                case GO_GOLDEN_HIGH_ELF_STATUETTE:
                case GO_GOLD_PLATTER:
                case GO_SHINY_YARN:
                case GO_GORGEOUS_GEM:
                case GO_GOLD_FRUIT_BOWL:
                case GO_DUSTY_PAINTING:
                case GO_FLUFFY_PILLOW:
                case GO_ANCIENT_ORCISH_SHIELD:
                case GO_RUSTED_SWORD:
                case GO_FRAGRANT_PERFUME:
                case GO_COLOGNE:
                case GO_EXPENSIVE_RUBY:
                case GO_SPARKLING_SAPPHIRE:
                case GO_JADE_KITTEN:
                case GO_RUBY_NECKLACE:
                case GO_SPELLSTONE_NECKLACE:
                case GO_DIAMOND_RING:
                case GO_RUBY_RING:
                case GO_GOLD_RING:
                case GO_SMALL_PILE_OF_COINS:
                case GO_LARGE_PILE_OF_COINS:
                case GO_GOLDEN_GOBLET:
                    go->SetVisible(false);
                    treasuresGUIDs.push_back(go->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_ALLOWED_STAGE:
                    allowedStage  = data;
                    break;
                case DATA_ESSENCE_OF_ORDER_EVENT:
                    essenceData = data;
                    if (data == DONE)
                    {
                        for (GuidVector::const_iterator itr = trashP2GUIDs.begin(); itr != trashP2GUIDs.end(); itr++)
                            if (Creature* trash = instance->GetCreature(*itr))
                            {
                                trash->SetVisible(true);
                                trash->SetReactState(REACT_AGGRESSIVE);
                            }

                        for (GuidVector::const_iterator itr = soulGUIDs.begin(); itr != soulGUIDs.end(); itr++)
                            if (Creature* soul = instance->GetCreature(*itr))
                                soul->RemoveFromWorld();

                        for (GuidVector::const_iterator itr = trapGUIDs.begin(); itr != trapGUIDs.end(); itr++)
                            if (GameObject* trap = instance->GetGameObject(*itr))
                                trap->RemoveFromWorld();
                    }
                    break;
                case DATA_AKAMA:
                    nodelData = data;
                    break;
                case DATA_KANRETHAD:
                    kanrethadData = data;
                    if (data == DONE)
                        if (Creature* jubeka = instance->GetCreature(jubekaGUID))
                            jubeka->AI()->DoAction(ACTION_1);
                    break;
                case DATA_SCENE_EVENT:
                    sceneEventData = data;
                    break;
                case DATA_NOBEL_EVENT:
                    nodelData = data;
                    break;
                case DATA_PLUNDER_EVENT:
                    plunderData = data;
                    if (data == DONE)
                        for (GuidVector::const_iterator itr = treasuresGUIDs.begin(); itr != treasuresGUIDs.end(); itr++)
                            if (GameObject* trap = instance->GetGameObject(*itr))
                                trap->SetVisible(true);
                    break;
                case DATA_STAGE_2:
                    stage2Data = data;
                    break;
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_AKAMA:
                    return akamaGUID;
                case DATA_MAIN_DOORS:
                    return doorGUID;
                case DATA_SECOND_DOOR:
                    return secondDoorGUID;
                default:
                    return ObjectGuid::Empty;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_ALLOWED_STAGE:
                    return allowedStage;
                case DATA_ESSENCE_OF_ORDER_EVENT:
                    return essenceData;
                case DATA_NOBEL_EVENT:
                    return nodelData;
                case DATA_SCENE_EVENT:
                    return sceneEventData;
                case DATA_PLUNDER_EVENT:
                    return plunderData;
                case DATA_STAGE_2:
                    return stage2Data;
                default:
                    return 0;
            }
        }

    private:
        uint32 essenceData;
        uint32 nodelData;
        uint32 kanrethadData;
        uint32 sceneEventData;
        uint32 plunderData;
        uint32 stage2Data;
        uint32 allowedStage;

        ObjectGuid akamaGUID;
        ObjectGuid jubekaGUID;
        ObjectGuid doorGUID;
        ObjectGuid secondDoorGUID;
        GuidVector trashP2GUIDs;
        GuidVector trapGUIDs;
        GuidVector soulGUIDs;
        GuidVector treasuresGUIDs;
    };
};

bool IsNextStageAllowed(InstanceScript* instance, uint8 stage)
{
    switch (stage)
    {
        case STAGE_2:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_1)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_2);
                instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_DOORS), true);
                return true;
            }
            return false;
        case STAGE_3:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_2)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_3);
                return true;
            }
            return false;
        case STAGE_4:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_3)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_4);
                return true;
            }
            return false;
        case STAGE_5:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_4)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_5);
                return true;
            }
            return false;
        case STAGE_6:
            if (instance->GetData(DATA_ESSENCE_OF_ORDER_EVENT) == DONE)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_6);
                return true;
            }
            return false;
        case STAGE_7:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_6)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_7);
                return true;
            }
            return false;
        case STAGE_8:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_7)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_8);
                return true;
            }
            return false;
        case STAGE_LAST:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_8)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_LAST);
                return true;
            }
            return false;
        default:
            return false;
    }
    return false;
}

void AddSC_instance_pursuing_the_black_harvest()
{
    new instance_pursuing_the_black_harvest();
}
