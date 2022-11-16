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

#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "sepulcher_of_the_first_ones.h"

ObjectData const creatureData[] =
{
    { BOSS_ANDUIN_WRYNN,               DATA_ANDUIN_WRYNN         },

};

class instance_sepulcher_of_the_first_ones : public InstanceMapScript
{
public:
    instance_sepulcher_of_the_first_ones() : InstanceMapScript(SFOScriptName, 2481) { }

    struct instance_sepulcher_of_the_first_ones_InstanceMapScript : public InstanceScript
    {
        instance_sepulcher_of_the_first_ones_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
        }

        void OnPlayerEnter(Player* /*player*/) override
        {

        }




        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {

            default:
                break;
            }
        }

        void Update(uint32 diff) override
        {
            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {


                default:
                    break;
                }
            }
        }

    protected:
        EventMap Events;

    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sepulcher_of_the_first_ones_InstanceMapScript(map);
    }
};

void AddSC_instance_sepulcher_of_the_first_ones()
{
    new instance_sepulcher_of_the_first_ones();
}
