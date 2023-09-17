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

static constexpr DungeonEncounterData Encounters[] =
{
    { BOSS_LADY_ANACONDRA, {{ 585 } } },
    { BOSS_LORD_COBRAHN, {{ 586 } } },
    { BOSS_KRESH, {{ 587 } } },
    { BOSS_LORD_PYTHAS, {{ 588 } } },
    { BOSS_SKUM, {{ 589 } } },
    { BOSS_LORD_SERPENTIS, {{ 590 } } },
    { BOSS_VERDAN_THE_EVERLIVING, {{ 591 } } },
    { BOSS_MUTANUS_THE_DEVOURER, {{ 592 } } },
};

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
            LoadDungeonEncounterData(Encounters);

            yelled = false;
        }

        bool yelled;
        ObjectGuid NaralexGUID;

        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == DATA_NARALEX)
                NaralexGUID = creature->GetGUID();
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_KRESH:                 SetBossState(BOSS_KRESH, DONE); break;
                case NPC_SKUM:                  SetBossState(BOSS_SKUM, DONE); break;
                case NPC_VERDAN_THE_EVERLIVING: SetBossState(BOSS_VERDAN_THE_EVERLIVING, DONE); break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case TYPE_LORD_COBRAHN:         SetBossState(BOSS_LORD_COBRAHN, EncounterState(data));break;
                case TYPE_LORD_PYTHAS:          SetBossState(BOSS_LORD_PYTHAS, EncounterState(data));break;
                case TYPE_LADY_ANACONDRA:       SetBossState(BOSS_LADY_ANACONDRA, EncounterState(data));break;
                case TYPE_LORD_SERPENTIS:       SetBossState(BOSS_LORD_SERPENTIS, EncounterState(data));break;
                case TYPE_NARALEX_EVENT:        SetBossState(4, EncounterState(data));break;
                case TYPE_NARALEX_PART1:        SetBossState(5, EncounterState(data));break;
                case TYPE_NARALEX_PART2:        SetBossState(6, EncounterState(data));break;
                case TYPE_NARALEX_PART3:        SetBossState(7, EncounterState(data));break;
                case TYPE_MUTANUS_THE_DEVOURER: SetBossState(BOSS_MUTANUS_THE_DEVOURER, EncounterState(data));break;
                case TYPE_NARALEX_YELLED:       yelled = true;      break;
                default:                        break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case TYPE_LORD_COBRAHN:         return GetBossState(BOSS_LORD_COBRAHN);
                case TYPE_LORD_PYTHAS:          return GetBossState(BOSS_LORD_PYTHAS);
                case TYPE_LADY_ANACONDRA:       return GetBossState(BOSS_LADY_ANACONDRA);
                case TYPE_LORD_SERPENTIS:       return GetBossState(BOSS_LORD_SERPENTIS);
                case TYPE_NARALEX_EVENT:        return GetBossState(4);
                case TYPE_NARALEX_PART1:        return GetBossState(5);
                case TYPE_NARALEX_PART2:        return GetBossState(6);
                case TYPE_NARALEX_PART3:        return GetBossState(7);
                case TYPE_MUTANUS_THE_DEVOURER: return GetBossState(BOSS_MUTANUS_THE_DEVOURER);
                case TYPE_NARALEX_YELLED:       return yelled;
                default:                        break;
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
