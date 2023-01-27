/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "grim_batol.h"

#define ENCOUNTERS 4

/* Boss Encounters
General Umbriss
Forgemaster Throngus
Drahga Shadowburner
Erudax
*/

class instance_grim_batol : public InstanceMapScript
{
public:
    instance_grim_batol() : InstanceMapScript("instance_grim_batol", 670) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_grim_batol_InstanceMapScript(map);
    }

    struct instance_grim_batol_InstanceMapScript: public InstanceScript
    {
        instance_grim_batol_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        uint32 Encounter[ENCOUNTERS];

        ObjectGuid GeneralUmbriss;
        ObjectGuid ForgemasterThrongus;
        ObjectGuid DrahgaShadowburner;
        ObjectGuid Erudax;
        ObjectGuid TeamInInstance;

        void Initialize() override
        {
            for (uint8 i = 0 ; i<ENCOUNTERS; ++i)
                Encounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const override 
        {
            for (uint8 i = 0; i < ENCOUNTERS; ++i)
            {
                if (Encounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                 case BOSS_GENERAL_UMBRISS:
                     GeneralUmbriss = creature->GetGUID();
                     break;
                 case BOSS_FORGEMASTER_THRONGUS:
                     ForgemasterThrongus = creature->GetGUID();
                     break;
                 case BOSS_DRAHGA_SHADOWBURNER:
                     DrahgaShadowburner = creature->GetGUID();
                     break;
                 case BOSS_ERUDAX:
                     Erudax = creature->GetGUID();
                     break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_GENERAL_UMBRISS:
                    return GeneralUmbriss;
                case DATA_FORGEMASTER_THRONGUS:
                    return ForgemasterThrongus;
                case DATA_DRAHGA_SHADOWBURNER:
                    return DrahgaShadowburner;
                case DATA_ERUDAX:
                    return Erudax;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_GENERAL_UMBRISS_EVENT:
                    Encounter[0] = data;
                    break;
                case DATA_FORGEMASTER_THRONGUS_EVENT:
                    Encounter[1] = data;
                    break;
                case DATA_DRAHGA_SHADOWBURNER_EVENT:
                    Encounter[2] = data;
                    break;
                case DATA_ERUDAX_EVENT:
                    Encounter[3] = data;
                    break;
            }

           if (data == DONE)
               SaveToDB();
        }

        uint32 GetData(uint32 type) const override 
        {
            switch (type)
            {
                case DATA_GENERAL_UMBRISS_EVENT:
                    return Encounter[0];
                case DATA_FORGEMASTER_THRONGUS_EVENT:
                    return Encounter[1];
                case DATA_DRAHGA_SHADOWBURNER_EVENT:
                    return Encounter[2];
                case DATA_ERUDAX_EVENT:
                    return Encounter[3];
            }
            return 0;
        }
    };
};

void AddSC_instance_grim_batol()
{
    new instance_grim_batol();
}

