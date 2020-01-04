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

/* ScriptData
SDName: Instance_Wailing_Caverns
SD%Complete: 99
SDComment: Everything seems to work, still need some checking
SDCategory: Wailing Caverns
EndScriptData */

#include "ScriptMgr.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "wailing_caverns.h"

ObjectData const creatureData[] =
{
    { NPC_LADY_ANACONDRA, DATA_LADY_ANACONDRA },
    { NPC_LORD_COBRAHN,   DATA_LORD_COBRAHN   },
    { NPC_LORD_PYTHAS,    DATA_LORD_PYTHAS    },
    { NPC_LORD_SERPENTIS, DATA_LORD_SERPENTIS },
    { 0,                  0                   } // END

};

class instance_wailing_caverns : public InstanceMapScript
{
public:
    instance_wailing_caverns() : InstanceMapScript(WCScriptName, 43) { }

    struct instance_wailing_caverns_InstanceMapScript : public InstanceScript
    {
        instance_wailing_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);

            yelled = false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_LADY_ANACONDRA:
                case NPC_LORD_COBRAHN:
                case NPC_LORD_PYTHAS:
                case NPC_LORD_SERPENTIS:
                case NPC_MUTANUS_THE_DEVOURER:
                case NPC_KRESH:
                case NPC_SKUM:
                case NPC_VERDAN_THE_EVERLIVING:
                case NPC_NARALEX:
                    WailingCavernsGUIDs.emplace_back(creature->GetGUID());
                    break;
            }
        }

        void SetData(uint32 type, uint32 /*data*/) override
        {
            switch (type)
            {
                case DATA_NARALEX_YELLED:
                    yelled = true;
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_NARALEX_YELLED:
                    return yelled;
            }
            return 0;
        }

    private:
        bool yelled;
        GuidVector WailingCavernsGUIDs;

    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_wailing_caverns_InstanceMapScript(map);
    }

};

void AddSC_instance_wailing_caverns()
{
    new instance_wailing_caverns();
}
