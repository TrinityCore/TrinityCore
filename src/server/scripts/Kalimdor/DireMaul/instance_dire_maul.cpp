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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "diremaul.h"

// Bosses (East)
// 0 - Pusillin
// 1 - Lethtendris
// 2 - Hydrospawn
// 3 - Zevrim Thornhoof
// 4 - Alzzin the Wildshaper

// West
// 5 - Tendris Warpwood
// 6 - Magister Kalendris
// 7 - Tsu'zee
// 8 - Illyanna Ravenoak
// 9 - Immol'thar
// 10 - Prince Tortheldrin
// 17 - CRYSTAL_01
// 18 - CRYSTAL_02
// 19 - CRYSTAL_03
// 20 - CRYSTAL_04
// 21 - CRYSTAL_05
// 22 - FORCEFIELD

// North
// 11 - Guard Mol'dar
// 12 - Stomper Kreeg
// 13 - Guard Fengus
// 14 - Guard Slip'kik
// 15 - Captain Kromcrush
// 16 - King Gordok

uint8 const EncounterCount = 23;

uint32 const CrystalMobs[2] = { NPC_ARCANE_ABERRATION, NPC_MANA_REMNANT };

enum Events
{
    EVENT_CRYSTAL_CREATURE_STORE                = 1,
    EVENT_CRYSTAL_CREATURE_CHECK                = 2
};

class instance_dire_maul : public InstanceMapScript
{
public:
    instance_dire_maul() : InstanceMapScript("instance_dire_maul", 429) { }

    struct instance_dire_maul_InstanceMapScript : public InstanceScript
    {
        instance_dire_maul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_IMMOLTHAR:
                    _immoGUID = creature->GetGUID();
                    // we make Immolthar non attackable, otherwise players with pets can pull him out of the forcefield
                    // TODO: this change isnt correct but since of today (13.09.2020) mmaps dont support doors
                    if (GetBossState(DATA_FORCEFIELD) != DONE)
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case GO_CRYSTAL_01:
                    _crystalGUIDs[0] = go->GetGUID();
                    break;
                case GO_CRYSTAL_02:
                    _crystalGUIDs[1] = go->GetGUID();
                    break;
                case GO_CRYSTAL_03:
                    _crystalGUIDs[2] = go->GetGUID();
                    break;
                case GO_CRYSTAL_04:
                    _crystalGUIDs[3] = go->GetGUID();
                    break;
                case GO_CRYSTAL_05:
                    _crystalGUIDs[4] = go->GetGUID();
                    break;
                case GO_FORCEFIELD:
                    _forcefieldGUID = go->GetGUID();
                    if (GetBossState(DATA_FORCEFIELD) != DONE)
                        _events.ScheduleEvent(EVENT_CRYSTAL_CREATURE_STORE, 1s);
                    break;
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case GO_CRYSTAL_01:
                    return _crystalGUIDs[0];
                case GO_CRYSTAL_02:
                    return _crystalGUIDs[1];
                case GO_CRYSTAL_03:
                    return _crystalGUIDs[2];
                case GO_CRYSTAL_04:
                    return _crystalGUIDs[3];
                case GO_CRYSTAL_05:
                    return _crystalGUIDs[4];
                case GO_FORCEFIELD:
                    return _forcefieldGUID;
                case NPC_IMMOLTHAR:
                    return _immoGUID;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

        void Update(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CRYSTAL_CREATURE_STORE:
                        CrystalCreatureStore();
                        _events.ScheduleEvent(EVENT_CRYSTAL_CREATURE_CHECK, 3s);
                        break;
                    case EVENT_CRYSTAL_CREATURE_CHECK:
                        CrystalCreatureCheck();
                        if ((GetBossState(DATA_FORCEFIELD) != DONE))
                            _events.ScheduleEvent(EVENT_CRYSTAL_CREATURE_CHECK, 1s);
                        break;
                    default:
                         break;
                }
            }
        }

        void CrystalCreatureStore()
        {
            for (uint8 i = 0; i < 5; ++i) // we store creatures in a list for all 5 crystals
            {
                uint8 creatureCount = 0;

                if (GameObject* crystal = instance->GetGameObject(_crystalGUIDs[i]))
                {
                    for (uint8 j = 0; j < 2; ++j)  // once per creature type from CrystalMobs
                    {
                        std::list<Creature*> creatureList;
                        GetCreatureListWithEntryInGrid(creatureList, crystal, CrystalMobs[j], 30.0f);
                        for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                        {
                            _crystalCreatureGUIDs[i][creatureCount] = (*itr)->GetGUID();
                            ++creatureCount;
                        }
                    }
                }
            }
        }

        void CrystalCreatureCheck()
        {
            for (uint8 i = 0; i < _crystalGUIDs.size(); ++i)
            {
                bool _mobAlive = false;
                GameObject* go = instance->GetGameObject(_crystalGUIDs[i]);
                if (!go)
                    continue;

                if (go->GetGoState() == GO_STATE_READY)
                {
                    for (uint8 j = 0; j < _crystalCreatureGUIDs[i].size(); ++j)
                    {
                        Creature* mob = instance->GetCreature(_crystalCreatureGUIDs[i][j]);
                        if (mob && mob->IsAlive())
                        {
                            _mobAlive = true;
                            break;
                        }
                    }
                }

                if (!_mobAlive && go->GetGoState() == GO_STATE_READY) // if all stored creatures are dead and go state is ready
                {
                    HandleGameObject(ObjectGuid::Empty, false, go);

                    switch (go->GetEntry())
                    {
                        case GO_CRYSTAL_01:
                            SetBossState(DATA_CRYSTAL_01, DONE);
                            go->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case GO_CRYSTAL_02:
                            SetBossState(DATA_CRYSTAL_02, DONE);
                            go->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case GO_CRYSTAL_03:
                            SetBossState(DATA_CRYSTAL_03, DONE);
                            go->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case GO_CRYSTAL_04:
                            SetBossState(DATA_CRYSTAL_04, DONE);
                            go->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case GO_CRYSTAL_05:
                            SetBossState(DATA_CRYSTAL_05, DONE);
                            go->SetGoState(GO_STATE_ACTIVE);
                            break;
                        default:
                            break;
                    }
                }
            }

            if (GetBossState(DATA_CRYSTAL_01) == DONE && GetBossState(DATA_CRYSTAL_02) == DONE && GetBossState(DATA_CRYSTAL_03) == DONE &&
                GetBossState(DATA_CRYSTAL_04) == DONE && GetBossState(DATA_CRYSTAL_05) == DONE)
            {
                // if all crystals are done, we set encounter forcefield to done
                SetBossState(DATA_FORCEFIELD, DONE);
                // activate forcefield to make it disappear
                if (GameObject* ffield = instance->GetGameObject(_forcefieldGUID))
                    ffield->SetGoState(GO_STATE_ACTIVE);
                // remove previously set non attackable flag
                if (Creature* immo = instance->GetCreature(_immoGUID))
                    immo->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }

protected:
        EventMap _events;
        std::array<ObjectGuid, 5> _crystalGUIDs;
        std::array<std::array<ObjectGuid, 4>, 5> _crystalCreatureGUIDs; // 5 different Crystals, maximum of 4 Creatures
        ObjectGuid _forcefieldGUID;
        ObjectGuid _immoGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dire_maul_InstanceMapScript(map);
    }
};

void AddSC_instance_dire_maul()
{
    new instance_dire_maul();
}
