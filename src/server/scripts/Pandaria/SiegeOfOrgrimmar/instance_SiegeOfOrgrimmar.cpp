/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

/* # Script : SiegeOfOrgrimmar Dungeon # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "SiegeOfOrgrimmar.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_SiegeOfOrgrimmar : public InstanceMapScript
{
    public:
        instance_SiegeOfOrgrimmar() : InstanceMapScript("instance_SiegeOfOrgrimmar", 1136) { }

        struct instance_SiegeOfOrgrimmar_InstanceMapScript : public InstanceScript
        {
            instance_SiegeOfOrgrimmar_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_Immerseus:
                    case BOSS_TheFallenProtectors:
                    case BOSS_Norushen:
                    case BOSS_ShaOfPride:
                    case BOSS_Galakras:
                    case BOSS_IronJuggernaut:
                    case BOSS_KorKron:
                    case BOSS_GeneralNazgrim:
                    case BOSS_Malkorok:
                    case BOSS_SpoilsOfPandaria:
                    case BOSS_Thok:
                    case BOSS_SiegecrafterBlackfuse:
                    case BOSS_ParagonsOfTheKlaxxi:
                    case BOSS_GarroshHellscream:
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state != DONE)
                   return true;

                switch (type)
                {
                    case DATA_Immerseus:
                    case DATA_TheFallenProtectors:
                    case DATA_Norushen:
                    case DATA_ShaOfPride:
                    case DATA_Galakras:
                    case DATA_IronJuggernaut:
                    case DATA_KorKron:
                    case DATA_GeneralNazgrim:
                    case DATA_Malkorok:
                    case DATA_SpoilsOfPandaria:
                    case DATA_Thok:
                    case DATA_SiegecrafterBlackfuse:
                    case DATA_ParagonsOfTheKlaxxi:
                    case DATA_GarroshHellscream:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_SiegeOfOrgrimmar_InstanceMapScript(map);
        }
};

void AddSC_instance_SiegeOfOrgrimmar()
{
    new instance_SiegeOfOrgrimmar();
}
