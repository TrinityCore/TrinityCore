/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "Creature.h"
#include "GameObject.h"
#include "World.h"
#include "WorldSession.h"
#include "karazhan_legion.h"


ObjectData const creatureData[] =
{
    { BOSS_VIZADUUM,            DATA_VIZADUUM           },
    { BOSS_MANA_DEVOURER,       DATA_MANA_DEVOURER      },
    { BOSS_SHADE_OF_MEDIVH,     DATA_SHADE_OF_MEDIVH    },
    { BOSS_CURATOR,             DATA_CURATOR            },
    { BOSS_ATTUMEN,             DATA_ATTUMEN            },
    { BOSS_MOROES,              DATA_MOROES             },
    { BOSS_MAIDEN_OF_VIRTUE,    DATA_MAIDEN_OF_VIRTUE   },
    { BOSS_COGGLESTON,          DATA_OPERA              },
    { BOSS_TOE_KNEE,            DATA_OPERA              },
    { BOSS_ELFYRA,              DATA_OPERA              },
    { BOSS_NIGHTBANE,           DATA_NIGHTBANE          },
    { NPC_FEL_CANNON,           DATA_FEL_CANNON         },
    { NPC_IMAGE_OF_MEDIVH,      DATA_IMAGE_OF_MEDIVH    },
    { 0,                        0                       }
};

DoorData const doorData[] =
{
    { GO_OPERA_RIGHT_DOOR,  DATA_OPERA,             DOOR_TYPE_ROOM    },
    { GO_MEDIVH_BOOK_DOOR,  DATA_SHADE_OF_MEDIVH,   DOOR_TYPE_PASSAGE },
    { GO_MEDIVH_DOOR,       DATA_SHADE_OF_MEDIVH,   DOOR_TYPE_ROOM    },
    { GO_STRANGE_WALL,      DATA_CURATOR,           DOOR_TYPE_PASSAGE },
    { GO_DOOR_BIBLIOTEK,    DATA_CURATOR,           DOOR_TYPE_PASSAGE },
    { 0, 0, DOOR_TYPE_ROOM},
};

constexpr uint32 TIMER_NIGHTBANE_OPERA      = 480000;
constexpr uint32 SPELL_MEDIVH_ECHO          = 229074;

class instance_new_karazhan : public InstanceMapScript
{
    public:
        instance_new_karazhan() : InstanceMapScript(NKARAScriptName, 1651)
        {}

        struct instance_new_karazhan_InstanceScript : public InstanceScript
        {
            explicit instance_new_karazhan_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                _operaEvent = urand(OPERA_EVENT_WIKKET, OPERA_EVENT_WESTFALL_STORY);
                _nightBaneTime = 0;
                _checked  = true;
                _result = false;
                _nightbaneEvent = NOT_STARTED;
            }

            uint32 GetData(uint32 data) const override
            {
                if (data == DATA_OPERA_EVENT)
                    return _operaEvent;
                else if (data == DATA_NIGHTBANE_TIMER)
                    return _result ? 2 : 1;
                else if (data == DATA_NIGHTBANE_EVENT)
                    return _nightbaneEvent;

                return 0;
            }

            void SetData(uint32 id, uint32 data) override
            {
                if (id == DATA_NIGHTBANE_EVENT)
                {
                    _nightbaneEvent = data;
                    if (data == IN_PROGRESS)
                    {
                        if (Creature* nightBane = GetCreature(DATA_NIGHTBANE))
                        {
                            for (auto & itr : instance->GetPlayers())
                            {
                                if (!itr.GetSource())
                                    return;

                                nightBane->Talk("The strange chill of a dark presence winds through the air", CHAT_MSG_RAID_BOSS_EMOTE,
                                LANG_UNIVERSAL, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), itr.GetSource());
                            }
                        }
                        _nightBaneTime = 0;
                        _checked = false;
                    }
                }

                if (data == DONE)
                    SaveToDB();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->GetEntry() == NPC_COMMAND_SHIP)
                {
                    if (creature->GetPositionZ() < 900)
                        _firstShip = creature->GetGUID();
                    else
                        _secondShip = creature->GetGUID();
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                case GO_DOOR_BIBLIOTEK:
                    AddDoor(go, true);
                    break;
                default:
                    break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                if (type == DATA_FIRST_SHIP)
                    return _firstShip;
                else if (type == DATA_SECOND_SHIP)
                    return _secondShip;

                return ObjectGuid::Empty;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _operaEvent << ' ' << _result << ' ' << _nightbaneEvent;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _operaEvent;
                data >> _result;
                data >> _nightbaneEvent;
            }

            void Update(uint32 diff) override
            {
                if (_checked)
                    return;

                _nightBaneTime += diff;

                if (_nightBaneTime >= TIMER_NIGHTBANE_OPERA)
                {
                    _checked = true;
                    auto & players = instance->GetPlayers();
                    _result = std::all_of(players.begin(), players.end(), [] (auto & it)
                    {
                        return it.GetSource() && it.GetSource()->HasAura(SPELL_MEDIVH_ECHO);
                    });
                }
            }

            private:
                bool _result, _checked;
                ObjectGuid _firstShip, _secondShip;
                uint32 _operaEvent, _nightbaneEvent;
                uint32 _nightBaneTime;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_new_karazhan_InstanceScript(map);
        }
};

void AddSC_instance_karazhan_legion()
{
    new instance_new_karazhan();
}
