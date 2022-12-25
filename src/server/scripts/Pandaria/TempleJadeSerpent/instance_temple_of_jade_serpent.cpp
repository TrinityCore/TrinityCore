/*
 * Copyright 2023 AzgathCore
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

#include "ScriptPCH.h"

#define ENCOUNTERS 4

enum datas
{
    DATA_WISE = 0,
    DATA_LOREWALKER,
    DATA_LIU,
    DATA_SHA,
};

enum bosses
{
    BOSS_WISE = 56448,
    BOSS_LOREWALKER = 56843,
    BOSS_LIU = 56732,
    BOSS_SHA = 56439,
};

class instance_temple_of_jade_serpent : public InstanceMapScript
{
public:
    instance_temple_of_jade_serpent() : InstanceMapScript("instance_temple_of_jade_serpent", 960) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_temple_of_jade_serpent_InstanceMapScript(map);
    }

    struct instance_temple_of_jade_serpent_InstanceMapScript : public InstanceScript
    {
        instance_temple_of_jade_serpent_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        ObjectGuid bossGuids[ENCOUNTERS];

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case BOSS_WISE:
                bossGuids[DATA_WISE] = creature->GetGUID();
                break;
            case BOSS_LOREWALKER:
                bossGuids[DATA_LOREWALKER] = creature->GetGUID();
                break;
            case BOSS_LIU:
                bossGuids[DATA_LIU] = creature->GetGUID();
                break;
            case BOSS_SHA:
                bossGuids[DATA_SHA] = creature->GetGUID();
                break;
            }
        }

        ObjectGuid GetObjectGuid(uint32 identifier) const
        {
            if (identifier < ENCOUNTERS)
                return bossGuids[identifier];
        }
    };
};

void AddSC_instance_temple_of_jade_serpent()
{
    new instance_temple_of_jade_serpent();
};
