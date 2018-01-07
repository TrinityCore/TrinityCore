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
#include "Player.h"
#include "InstanceScript.h"
#include "eye_of_azshara.h"

class instance_eye_of_azshara : public InstanceMapScript
{
    public:
        instance_eye_of_azshara() : InstanceMapScript(EoAScriptName, 1456) { }

        struct instance_eye_of_azshara_InstanceMapScript : public InstanceScript
        {
            instance_eye_of_azshara_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                _teamInInstance = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                if(!_teamInInstance)
                {
                    _teamInInstance = player->GetTeam();
                }
            }
            
            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SERPENTRIX:
                        SerpentrixGUID = creature->GetGUID();
                        break;
                    case NPC_WARLORD_PARJESH:
                        WarlordParjeshGUID = creature->GetGUID();
                        break;
                    case NPC_LADY_HATECOIL:
                        LadyHatecoilGUID = creature->GetGUID();
                        break;
                    case NPC_KING_DEEPBEARD:
                        KingDeepbeardGUID = creature->GetGUID();
                        break;
                    case NPC_WRATH_OF_AZSHARA:
                        WrathOfAzsharaGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SERPENTRIX:
                        return SerpentrixGUID;
                    case DATA_WARLORD_PARJESH:
                        return WarlordParjeshGUID;
                    case DATA_LADY_HATECOIL:
                        return LadyHatecoilGUID;
                    case DATA_KING_DEEPBEARD:
                        return KingDeepbeardGUID;
                    case DATA_WRATH_OF_AZSHARA:
                        return WrathOfAzsharaGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;
                return true;
            }

        private:
            uint32 _teamInInstance;

            ObjectGuid SerpentrixGUID;
            ObjectGuid WarlordParjeshGUID;
            ObjectGuid LadyHatecoilGUID;
            ObjectGuid KingDeepbeardGUID;
            ObjectGuid WrathOfAzsharaGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_eye_of_azshara_InstanceMapScript(map);
        }
};

void AddSC_instance_eye_of_azshara()
{
    new instance_eye_of_azshara();
}
