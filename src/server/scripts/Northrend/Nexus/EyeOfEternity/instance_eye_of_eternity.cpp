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
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "eye_of_eternity.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"

BossBoundaryData const boundaries =
{
    { DATA_MALYGOS_EVENT, new CircleBoundary(Position(754.362f, 1301.609985f), 280.0) } // sanity check boundary
};

class instance_eye_of_eternity : public InstanceMapScript
{
public:
    instance_eye_of_eternity() : InstanceMapScript(EoEScriptName, 616) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_eye_of_eternity_InstanceMapScript(map);
    }

    struct instance_eye_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_eye_of_eternity_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            LoadBossBoundaries(boundaries);
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetBossState(DATA_MALYGOS_EVENT) == DONE)
                player->CastSpell(player, SPELL_SUMMOM_RED_DRAGON_BUDDY, true);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type == DATA_MALYGOS_EVENT)
            {
                if (state == FAIL)
                {
                    for (ObjectGuid const& portalTriggerGuid : portalTriggers)
                    {
                        if (Creature* trigger = instance->GetCreature(portalTriggerGuid))
                        {
                            // just in case
                            trigger->RemoveAllAuras();
                            trigger->AI()->Reset();
                        }
                    }

                    SpawnGameObject(GO_EXIT_PORTAL, exitPortalPosition);

                    if (GameObject* platform = instance->GetGameObject(platformGUID))
                        platform->RemoveFlag(GO_FLAG_DESTROYED);
                }
                else if (state == DONE)
                    SpawnGameObject(GO_EXIT_PORTAL, exitPortalPosition);
            }
            return true;
        }

        /// @todo this should be handled in map, maybe add a summon function in map
        // There is no other way afaik...
        void SpawnGameObject(uint32 entry, Position const& pos)
        {
            if (GameObject* go = GameObject::CreateGameObject(entry, instance, pos, QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.0f, 0.0f), 255, GO_STATE_READY))
                instance->AddToMap(go);
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_NEXUS_RAID_PLATFORM:
                    platformGUID = go->GetGUID();
                    break;
                case GO_FOCUSING_IRIS_10:
                case GO_FOCUSING_IRIS_25:
                    irisGUID = go->GetGUID();
                    focusingIrisPosition = go->GetPosition();
                    break;
                case GO_EXIT_PORTAL:
                    exitPortalGUID = go->GetGUID();
                    exitPortalPosition = go->GetPosition();
                    break;
                case GO_HEART_OF_MAGIC_10:
                case GO_HEART_OF_MAGIC_25:
                    heartOfMagicGUID = go->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_VORTEX_TRIGGER:
                    vortexTriggers.push_back(creature->GetGUID());
                    break;
                case NPC_MALYGOS:
                    malygosGUID = creature->GetGUID();
                    break;
                case NPC_PORTAL_TRIGGER:
                    portalTriggers.push_back(creature->GetGUID());
                    break;
                case NPC_ALEXSTRASZA_BUNNY:
                    alexstraszaBunnyGUID = creature->GetGUID();
                    break;
                case NPC_ALEXSTRASZAS_GIFT:
                    giftBoxBunnyGUID = creature->GetGUID();
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            // Player continues to be moving after death no matter if spline will be cleared along with all movements,
            // so on next world tick was all about delay if box will pop or not (when new movement will be registered)
            // since in EoE you never stop falling. However root at this precise* moment works,
            // it will get cleared on release. If by any chance some lag happen "Reload()" and "RepopMe()" works,
            // last test I made now gave me 50/0 of this bug so I can't do more about it.
            unit->SetControlled(true, UNIT_STATE_ROOT);
        }

        void ProcessEvent(WorldObject* /*obj*/, uint32 eventId, WorldObject* /*invoker*/) override
        {
            if (eventId == EVENT_FOCUSING_IRIS)
            {
                if (Creature* alexstraszaBunny = instance->GetCreature(alexstraszaBunnyGUID))
                    alexstraszaBunny->CastSpell(alexstraszaBunny, SPELL_IRIS_OPENED);

                if (GameObject* iris = instance->GetGameObject(irisGUID))
                    iris->AddFlag(GO_FLAG_IN_USE);

                if (Creature* malygos = instance->GetCreature(malygosGUID))
                    malygos->AI()->DoAction(0); // ACTION_LAND_ENCOUNTER_START

                if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                    exitPortal->Delete();
            }
        }

        void VortexHandling()
        {
            if (Creature* malygos = instance->GetCreature(malygosGUID))
            {
                for (GuidList::const_iterator itr_vortex = vortexTriggers.begin(); itr_vortex != vortexTriggers.end(); ++itr_vortex)
                {
                    uint8 counter = 0;
                    if (Creature* trigger = instance->GetCreature(*itr_vortex))
                    {
                        // each trigger have to cast the spell to 5 players.
                        for (auto* ref : malygos->GetThreatManager().GetUnsortedThreatList())
                        {
                            if (counter >= 5)
                                break;

                            if (Player* player = ref->GetVictim()->ToPlayer())
                            {
                                if (player->IsGameMaster() || player->HasAura(SPELL_VORTEX_4))
                                    continue;

                                player->CastSpell(trigger, SPELL_VORTEX_4, true);
                                counter++;
                            }
                        }
                    }
                }
            }
        }

        void PowerSparksHandling()
        {
            bool next = (lastPortalGUID == portalTriggers.back() || !lastPortalGUID ? true : false);

            for (GuidList::const_iterator itr_trigger = portalTriggers.begin(); itr_trigger != portalTriggers.end(); ++itr_trigger)
            {
                if (next)
                {
                    if (Creature* trigger = instance->GetCreature(*itr_trigger))
                    {
                        lastPortalGUID = trigger->GetGUID();
                        trigger->CastSpell(trigger, SPELL_PORTAL_OPENED, true);
                        return;
                    }
                }

                if (*itr_trigger == lastPortalGUID)
                    next = true;
            }
        }

        void SetData(uint32 data, uint32 /*value*/) override
        {
            switch (data)
            {
                case DATA_VORTEX_HANDLING:
                    VortexHandling();
                    break;
                case DATA_POWER_SPARKS_HANDLING:
                    PowerSparksHandling();
                    break;
                case DATA_RESPAWN_IRIS:
                    SpawnGameObject(instance->GetDifficultyID() == DIFFICULTY_10_N ? GO_FOCUSING_IRIS_10 : GO_FOCUSING_IRIS_25, focusingIrisPosition);
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case DATA_TRIGGER:
                    return vortexTriggers.front();
                case DATA_MALYGOS:
                    return malygosGUID;
                case DATA_PLATFORM:
                    return platformGUID;
                case DATA_ALEXSTRASZA_BUNNY_GUID:
                    return alexstraszaBunnyGUID;
                case DATA_HEART_OF_MAGIC_GUID:
                    return heartOfMagicGUID;
                case DATA_FOCUSING_IRIS_GUID:
                    return irisGUID;
                case DATA_GIFT_BOX_BUNNY_GUID:
                    return giftBoxBunnyGUID;
            }

            return ObjectGuid::Empty;
        }

    private:
        GuidList vortexTriggers;
        GuidList portalTriggers;
        ObjectGuid malygosGUID;
        ObjectGuid irisGUID;
        ObjectGuid lastPortalGUID;
        ObjectGuid platformGUID;
        ObjectGuid exitPortalGUID;
        ObjectGuid heartOfMagicGUID;
        ObjectGuid alexstraszaBunnyGUID;
        ObjectGuid giftBoxBunnyGUID;
        Position focusingIrisPosition;
        Position exitPortalPosition;
    };
};

void AddSC_instance_eye_of_eternity()
{
    new instance_eye_of_eternity();
}
