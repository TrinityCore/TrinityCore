/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "grim_batol.h"

class instance_grim_batol : public InstanceMapScript
{
    public:
        instance_grim_batol() : InstanceMapScript("instance_grim_batol", 670) { }

        struct instance_grim_batol_InstanceMapScript : public InstanceScript
        {
            instance_grim_batol_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 GeneralUmbrissGUID;
            uint64 ForgemasterThrongusGUID;
            uint64 DrahgaShadowburnerGUID;
            uint64 ErudaxGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                GeneralUmbrissGUID              = 0;
                ForgemasterThrongusGUID         = 0;
                DrahgaShadowburnerGUID          = 0;
                ErudaxGUID                      = 0;

                memset(Encounter, 0, sizeof(Encounter));
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (Encounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_GENERAL_UMBRISS:
                        GeneralUmbrissGUID = creature->GetGUID();
                        break;
                    case NPC_FORGEMASTER_THRONGUS:
                        ForgemasterThrongusGUID = creature->GetGUID();
                        break;
                    case NPC_DRAHGA_SHADOWBURNER:
                        DrahgaShadowburnerGUID = creature->GetGUID();
                        break;
                    case NPC_ERUDAX:
                        ErudaxGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_GENERAL_UMBRISS:
                        return GeneralUmbrissGUID;
                    case BOSS_FORGEMASTER_THRONGUS:
                        return ForgemasterThrongusGUID;
                    case BOSS_DRAHGA_SHADOWBURNER:
                        return DrahgaShadowburnerGUID;
                    case BOSS_ERUDAX:
                        return ErudaxGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_grim_batol_InstanceMapScript(map);
        }
};

void AddSC_instance_grim_batol()
{
    new instance_grim_batol();
}
