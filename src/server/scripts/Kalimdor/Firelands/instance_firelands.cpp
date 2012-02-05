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
#include "firelands.h"

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript("instance_firelands", 720) { } // phased map - phase2 map id: 721

        struct instance_firelands_InstanceMapScript : public InstanceScript
        {
            instance_firelands_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 ShannoxGUID;
            uint64 LordRhyolithGUID;
            uint64 BethtilacGUID;
            uint64 AlysrazorGUID;
            uint64 BalerocGUID;
            uint64 MajordomoStaghelmGUID;
            uint64 RagnarosGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                ShannoxGUID                     = 0;
                LordRhyolithGUID                = 0;
                BethtilacGUID                   = 0;
                AlysrazorGUID                   = 0;
                BalerocGUID                     = 0;
                MajordomoStaghelmGUID           = 0;
                RagnarosGUID                    = 0;

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
                    case NPC_SHANNOX:
                        ShannoxGUID = creature->GetGUID();
                        break;
                    case NPC_LORD_RHYOLITH:
                        LordRhyolithGUID = creature->GetGUID();
                        break;
                    case NPC_BETHTILAC:
                        BethtilacGUID = creature->GetGUID();
                        break;
                    case NPC_ALYSRAZOR:
                        AlysrazorGUID = creature->GetGUID();
                        break;
                    case NPC_BALEROC:
                        BalerocGUID = creature->GetGUID();
                        break;
                    case NPC_MAJORDOMO_STAGHELM:
                        MajordomoStaghelmGUID = creature->GetGUID();
                        break;
                    case NPC_RAGNAROS:
                        RagnarosGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_SHANNOX:
                        return ShannoxGUID;
                    case BOSS_LORD_RHYOLITH:
                        return LordRhyolithGUID;
                    case BOSS_BETHTILAC:
                        return BethtilacGUID;
                    case BOSS_ALYSRAZOR:
                        return AlysrazorGUID;
                    case BOSS_BALEROC:
                        return BalerocGUID;
                    case BOSS_MAJORDOMO_STAGHELM:
                        return MajordomoStaghelmGUID;
                    case BOSS_RAGNAROS:
                        return RagnarosGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_firelands_InstanceMapScript(map);
        }
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}
