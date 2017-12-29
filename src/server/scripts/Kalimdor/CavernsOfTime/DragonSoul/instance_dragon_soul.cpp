/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "ScriptMgr.h"
#include "dragon_soul.h"
#include "GameObject.h"

#define MAX_ENCOUNTER 8

class instance_dragon_soul : public InstanceMapScript
{
public:
    instance_dragon_soul() : InstanceMapScript("instance_dragon_soul", 967) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dragon_soul_InstanceMapScript(map);
    }

    struct instance_dragon_soul_InstanceMapScript : public InstanceScript
    {
        instance_dragon_soul_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);

            bHagaraEvent = 0;
        }

        void OnPlayerEnter(Player* pPlayer)
        {
            if (!uiTeamInInstance)
                uiTeamInInstance = pPlayer->GetTeam();
        }

        void OnCreatureCreate(Creature* pCreature) override
        {
            switch (pCreature->GetEntry())
            {
            case NPC_MORCHOK:
                uiMorchokGUID = pCreature->GetGUID();
                break;
            case NPC_KOHCROM:
                uiKohcromGUID = pCreature->GetGUID();
                break;
            case NPC_VALEERA:
                uiValeeraGUID = pCreature->GetGUID();
                break;
            case NPC_EIENDORMI:
                uiEiendormiGUID = pCreature->GetGUID();
                break;
            case NPC_ZONOZZ:
                uiZonozzGUID = pCreature->GetGUID();
                break;
            case NPC_YORSAHJ:
                uiYorsahjGUID = pCreature->GetGUID();
                break;
            case NPC_HAGARA:
                uiHagaraGUID = pCreature->GetGUID();
                break;
            case NPC_ULTRAXION:
                uiUltraxionGUID = pCreature->GetGUID();
                break;
            case NPC_THRALL_1:
                uiUltraxionThrallGUID = pCreature->GetGUID();
                break;
            case NPC_SKY_CAPTAIN_SWAYZE:
                if (pCreature->GetPositionZ() > 200.0f)
                {
                    uiSwayzeGUID = pCreature->GetGUID();
                    if (GetBossState(DATA_ULTRAXION) == DONE)
                        pCreature->SetVisible(true);
                    else
                        pCreature->SetVisible(false);
                }
                break;
            case NPC_KAANU_REEVS:
                if (pCreature->GetPositionZ() > 200.0f)
                {
                    uiReevsGUID = pCreature->GetGUID();
                    if (GetBossState(DATA_ULTRAXION) == DONE)
                        pCreature->SetVisible(true);
                    else
                        pCreature->SetVisible(false);
                }
                break;
            case NPC_BLACKHORN:
                uiBlackhornGUID = pCreature->GetGUID();
                break;
            case NPC_TRAVEL_TO_WYRMREST_TEMPLE:
            case NPC_TRAVEL_TO_EYE_OF_ETERNITY:
            case NPC_TRAVEL_TO_WYRMREST_BASE:
            case NPC_TRAVEL_TO_WYRMREST_SUMMIT:
                teleportGUIDs.push_back(pCreature->GetGUID());
                break;
            case NPC_TRAVEL_TO_DECK:
                if (GetBossState(DATA_BLACKHORN) == DONE)
                    pCreature->SetVisible(true);
                else
                    pCreature->SetVisible(false);
                uiDeckGUID = pCreature->GetGUID();
                teleportGUIDs.push_back(pCreature->GetGUID());
                break;
            case NPC_TRAVEL_TO_MAELSTORM:
                if (GetBossState(DATA_SPINE) == DONE)
                    pCreature->SetVisible(true);
                else
                    pCreature->SetVisible(false);
                uiMaelstormGUID = pCreature->GetGUID();
                teleportGUIDs.push_back(pCreature->GetGUID());
                break;
            case NPC_SPINE_OF_DEATHWING:
                uiSpineGUID = pCreature->GetGUID();
                break;
            case NPC_DEATHWING:
                DeathwingGUID = pCreature->GetGUID();
                break;
            case NPC_THRALL_2:
                Maelstrom_trall = pCreature->GetGUID();
                break;
            case NPC_KALECGOS_DRAGON:
                Maelstrom_kalecgos = pCreature->GetGUID();
                break;
            case NPC_YSERA_DRAGON:
                Maelstrom_ysera = pCreature->GetGUID();
                break;
            case NPC_NOZDORMU_DRAGON:
                Maelstrom_nozdormy = pCreature->GetGUID();
                break;
            case NPC_ALEXSTRASZA_DRAGON:
                Maelstrom_alexstrasza = pCreature->GetGUID();
                break;
            default:
                break;
            }
        }

        void OnCreatureRemove(Creature* pCreature)
        {
            if (pCreature->GetEntry() == NPC_ULTRAXION)
                uiUltraxionGUID = ObjectGuid::Empty;
            else if (pCreature->GetEntry() == NPC_BLACKHORN)
                uiBlackhornGUID = ObjectGuid::Empty;
        }

        void OnGameObjectCreate(GameObject* pGo) override
        {
            switch (pGo->GetEntry())
            {
            case GO_LESSER_CACHE_OF_THE_ASPECTS_10N:
                uiLesserCacheofTheAspects[0] = pGo->GetGUID();
                break;
            case GO_LESSER_CACHE_OF_THE_ASPECTS_25N:
                uiLesserCacheofTheAspects[1] = pGo->GetGUID();
                break;
            case GO_LESSER_CACHE_OF_THE_ASPECTS_10H:
                uiLesserCacheofTheAspects[2] = pGo->GetGUID();
                break;
            case GO_LESSER_CACHE_OF_THE_ASPECTS_25H:
                uiLesserCacheofTheAspects[3] = pGo->GetGUID();
                break;
            case GO_ALLIANCE_SHIP:
                uiAllianceShipGUID = pGo->GetGUID();
                if (GetBossState(DATA_ULTRAXION) == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                pGo->UpdateObjectVisibility();
                break;
            case GO_DEATHWING_BACK_PLATE_1:
                uiBackPlates[0] = pGo->GetGUID();
                break;
            case GO_DEATHWING_BACK_PLATE_2:
                uiBackPlates[1] = pGo->GetGUID();
                break;
            case GO_DEATHWING_BACK_PLATE_3:
                uiBackPlates[2] = pGo->GetGUID();
                break;
            case GO_GREATER_CACHE_OF_THE_ASPECTS_10N:
                uiGreaterCacheofTheAspects[0] = pGo->GetGUID();
                break;
            case GO_GREATER_CACHE_OF_THE_ASPECTS_25N:
                uiGreaterCacheofTheAspects[1] = pGo->GetGUID();
                break;
            case GO_GREATER_CACHE_OF_THE_ASPECTS_10H:
                uiGreaterCacheofTheAspects[2] = pGo->GetGUID();
                break;
            case GO_GREATER_CACHE_OF_THE_ASPECTS_25H:
                uiGreaterCacheofTheAspects[3] = pGo->GetGUID();
                break;
            default:
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_MORCHOK:              return uiMorchokGUID;
            case DATA_KOHCROM:              return uiKohcromGUID;
            case NPC_VALEERA:               return uiValeeraGUID;
            case NPC_EIENDORMI:             return uiEiendormiGUID;
            case DATA_ZONOZZ:               return uiZonozzGUID;
            case DATA_YORSAHJ:              return uiYorsahjGUID;
            case DATA_HAGARA:               return uiHagaraGUID;
            case DATA_ULTRAXION:            return uiUltraxionGUID;
            case DATA_TRALL_VS_ULTRAXION:   return uiUltraxionThrallGUID;
            case DATA_BLACKHORN:            return uiBlackhornGUID;
            case DATA_LESSER_CACHE_10N:     return uiLesserCacheofTheAspects[0];
            case DATA_LESSER_CACHE_25N:     return uiLesserCacheofTheAspects[1];
            case DATA_LESSER_CACHE_10H:     return uiLesserCacheofTheAspects[2];
            case DATA_LESSER_CACHE_25H:     return uiLesserCacheofTheAspects[3];
            case DATA_SWAYZE:               return uiSwayzeGUID;
            case DATA_REEVS:                return uiReevsGUID;
            case DATA_BACK_PLATE_1:         return uiBackPlates[0];
            case DATA_BACK_PLATE_2:         return uiBackPlates[1];
            case DATA_BACK_PLATE_3:         return uiBackPlates[2];
            case DATA_GREATER_CACHE_10N:    return uiGreaterCacheofTheAspects[0];
            case DATA_GREATER_CACHE_25N:    return uiGreaterCacheofTheAspects[1];
            case DATA_GREATER_CACHE_10H:    return uiGreaterCacheofTheAspects[2];
            case DATA_GREATER_CACHE_25H:    return uiGreaterCacheofTheAspects[3];
            case DATA_ALLIANCE_SHIP:        return uiAllianceShipGUID;
            case NPC_THRALL_2:              return Maelstrom_trall;
            case DATA_SPINE:                return uiSpineGUID;
            case DATA_DEATHWING:            return DeathwingGUID;
            default:
                break;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_HAGARA_EVENT)
            {
                bHagaraEvent = data;
                SaveToDB();
            }
        }

        uint32 GetData(uint32 type) const
        {
            if (type == DATA_HAGARA_EVENT)
                return bHagaraEvent;

            return 0;
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type == DATA_MORCHOK)
                if (Creature* pZonozz = instance->GetCreature(uiZonozzGUID))
                    pZonozz->SetVisible(state == DONE ? true : false);

            if (type == DATA_MORCHOK)
                if (Creature* pYorsahj = instance->GetCreature(uiYorsahjGUID))
                    pYorsahj->SetVisible(state == DONE ? true : false);

            if (type == DATA_BLACKHORN)
                if (Creature* pDeck = instance->GetCreature(uiDeckGUID))
                    pDeck->SetVisible(state == DONE ? true : false);

            if (type == DATA_SPINE)
                if (Creature* pMaelstorm = instance->GetCreature(uiMaelstormGUID))
                    pMaelstorm->SetVisible(state == DONE ? true : false);

            if (state == IN_PROGRESS)
            {
                if (!teleportGUIDs.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = teleportGUIDs.begin(); itr != teleportGUIDs.end(); ++itr)
                        if (Creature* pTeleport = instance->GetCreature((*itr)))
                            if (pTeleport->GetEntry() != NPC_TRAVEL_TO_EYE_OF_ETERNITY)
                            {
                                pTeleport->RemoveAura(SPELL_TELEPORT_VISUAL_ACTIVE);
                                pTeleport->CastSpell(pTeleport, SPELL_TELEPORT_VISUAL_DISABLED, true);
                            }
            }
            else
            {
                if (!teleportGUIDs.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = teleportGUIDs.begin(); itr != teleportGUIDs.end(); ++itr)
                        if (Creature* pTeleport = instance->GetCreature((*itr)))
                            if (pTeleport->GetEntry() != NPC_TRAVEL_TO_EYE_OF_ETERNITY)
                            {
                                pTeleport->CastSpell(pTeleport, SPELL_TELEPORT_VISUAL_ACTIVE, true);
                                pTeleport->CastSpell(pTeleport, SPELL_TELEPORT_VISUAL_DISABLED, true);
                            }
            }


            return true;
        }

    private:
        uint32 uiTeamInInstance;

        ObjectGuid uiMorchokGUID;
        ObjectGuid uiKohcromGUID;
        ObjectGuid uiZonozzGUID;
        ObjectGuid uiYorsahjGUID;
        ObjectGuid uiHagaraGUID;
        ObjectGuid uiValeeraGUID;
        ObjectGuid uiEiendormiGUID;
        ObjectGuid uiUltraxionGUID;
        ObjectGuid uiUltraxionThrallGUID;
        ObjectGuid uiAllianceShipGUID;
        ObjectGuid uiSwayzeGUID;
        ObjectGuid uiReevsGUID;
        ObjectGuid uiBlackhornGUID;
        ObjectGuid uiDeckGUID;
        ObjectGuid uiMaelstormGUID;

        ObjectGuid uiLesserCacheofTheAspects[4];
        ObjectGuid uiBackPlates[3];
        ObjectGuid uiGreaterCacheofTheAspects[4];
        ObjectGuid uiSpineGUID;

        ObjectGuid DeathwingGUID;
        ObjectGuid Maelstrom_trall;
        ObjectGuid Maelstrom_kalecgos;
        ObjectGuid Maelstrom_ysera;
        ObjectGuid Maelstrom_nozdormy;
        ObjectGuid Maelstrom_alexstrasza;

        std::vector<ObjectGuid> teleportGUIDs;

        uint32 bHagaraEvent;

    };
};

void WhisperToAllPlayerInZone(int32 TextId, Creature* sender)
{
    Map::PlayerList const &players = sender->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
        if (Player* player = i->GetSource())
        {
            // TODO: Implement this
            // Talk(TextId, sender, player);
        }
}

void AddSC_instance_dragon_soul()
{
    new instance_dragon_soul();
}
