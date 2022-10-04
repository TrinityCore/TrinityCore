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
#include "Log.h"
#include "Map.h"
#include "wailing_caverns.h"

#define MAX_ENCOUNTER   9

class instance_wailing_caverns : public InstanceMapScript
{
public:
    instance_wailing_caverns() : InstanceMapScript(WCScriptName, 43) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_wailing_caverns_InstanceMapScript(map);
    }

    struct instance_wailing_caverns_InstanceMapScript : public InstanceScript
    {
        instance_wailing_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);

            yelled = false;
        }

        bool yelled;
        ObjectGuid NaralexGUID;

        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == DATA_NARALEX)
                NaralexGUID = creature->GetGUID();
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case TYPE_LORD_COBRAHN:         SetBossState(0, EncounterState(data));break;
                case TYPE_LORD_PYTHAS:          SetBossState(1, EncounterState(data));break;
                case TYPE_LADY_ANACONDRA:       SetBossState(2, EncounterState(data));break;
                case TYPE_LORD_SERPENTIS:       SetBossState(3, EncounterState(data));break;
                case TYPE_NARALEX_EVENT:        SetBossState(4, EncounterState(data));break;
                case TYPE_NARALEX_PART1:        SetBossState(5, EncounterState(data));break;
                case TYPE_NARALEX_PART2:        SetBossState(6, EncounterState(data));break;
                case TYPE_NARALEX_PART3:        SetBossState(7, EncounterState(data));break;
                case TYPE_MUTANUS_THE_DEVOURER: SetBossState(8, EncounterState(data));break;
                case TYPE_NARALEX_YELLED:       yelled = true;      break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case TYPE_LORD_COBRAHN:         return GetBossState(0);
                case TYPE_LORD_PYTHAS:          return GetBossState(1);
                case TYPE_LADY_ANACONDRA:       return GetBossState(2);
                case TYPE_LORD_SERPENTIS:       return GetBossState(3);
                case TYPE_NARALEX_EVENT:        return GetBossState(4);
                case TYPE_NARALEX_PART1:        return GetBossState(5);
                case TYPE_NARALEX_PART2:        return GetBossState(6);
                case TYPE_NARALEX_PART3:        return GetBossState(7);
                case TYPE_MUTANUS_THE_DEVOURER: return GetBossState(8);
                case TYPE_NARALEX_YELLED:       return yelled;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            if (data == DATA_NARALEX)return NaralexGUID;
            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_wailing_caverns()
{
    new instance_wailing_caverns();
}
