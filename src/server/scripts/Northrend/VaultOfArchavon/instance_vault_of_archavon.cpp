/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "vault_of_archavon.h"

/* Vault of Archavon encounters:
1 - Archavon the Stone Watcher event
2 - Emalon the Storm Watcher event
3 - Koralon the Flame Watcher event
4 - Toravon the Ice Watcher event
*/

class instance_vault_of_archavon : public InstanceMapScript
{
    public:
        instance_vault_of_archavon() : InstanceMapScript(VoAScriptName, 624) { }

        struct instance_vault_of_archavon_InstanceMapScript : public InstanceScript
        {
            instance_vault_of_archavon_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

                ArchavonDeath   = 0;
                EmalonDeath     = 0;
                KoralonDeath    = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_EMALON:
                        EmalonGUID = creature->GetGUID();
                        break;
                    case NPC_TORAVON:
                        ToravonGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch (identifier)
                {
                    case DATA_EMALON:
                        return EmalonGUID;
                    case DATA_TORAVON:
                        return ToravonGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state != DONE)
                   return true;

                switch (type)
                {
                    case DATA_ARCHAVON:
                        ArchavonDeath = time(nullptr);
                        break;
                    case DATA_EMALON:
                        EmalonDeath = time(nullptr);
                        break;
                    case DATA_KORALON:
                        KoralonDeath = time(nullptr);
                        break;
                    default:
                        return true;
                }

                // on every death of Archavon, Emalon and Koralon check our achievement
                DoCastSpellOnPlayers(SPELL_EARTH_WIND_FIRE_ACHIEVEMENT_CHECK);

                return true;
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/) override
            {
                switch (criteria_id)
                {
                    case CRITERIA_EARTH_WIND_FIRE_10:
                    case CRITERIA_EARTH_WIND_FIRE_25:
                        if (ArchavonDeath && EmalonDeath && KoralonDeath)
                        {
                            // instance difficulty check is already done in db (achievement_criteria_data)
                            // int() for Visual Studio, compile errors with abs(time_t)
                            return (abs(int(ArchavonDeath-EmalonDeath)) < MINUTE && \
                                abs(int(EmalonDeath-KoralonDeath)) < MINUTE && \
                                abs(int(KoralonDeath-ArchavonDeath)) < MINUTE);
                        }
                        break;
                    default:
                        break;
                }

                return false;
            }

        private:
            ObjectGuid EmalonGUID;
            ObjectGuid ToravonGUID;
            time_t ArchavonDeath;
            time_t EmalonDeath;
            time_t KoralonDeath;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_vault_of_archavon_InstanceMapScript(map);
        }
};

void AddSC_instance_vault_of_archavon()
{
    new instance_vault_of_archavon();
}
