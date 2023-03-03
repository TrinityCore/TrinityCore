/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2016-2019 MagicStorm
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
 DELETE FROM `instance_template` WHERE `map` = 1648;
 INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES (1648, 0, "instance_trials_of_valor", 0);
 INSERT INTO game_tele (position_x, position_y, position_z, orientation, map, NAME) VALUES
 (3797.596924, 529.043213, 603.330627, 3.162955, 1648, "TrialOfValorEphemeralWay"), // Instance start
 (2520.351074, 528.9219636, 748.995056, 3.162937, 1648, "TrialOfValorOdyn"), // Chamber of Glory
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "trial_of_valor.h"

class instance_trial_of_valor : public InstanceMapScript
{
public:
    instance_trial_of_valor() : InstanceMapScript(TrialOfValorScriptName, 1456) { }

    struct instance_trial_of_valor_InstanceScript : public InstanceScript
    {
        instance_trial_of_valor_InstanceScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_VALARJAR_RUNE_GREEN:
                ValarjarRunesGUID[0] = go->GetGUID();
                break;
            case GO_VALARJAR_RUNE_BLUE:
                ValarjarRunesGUID[1] = go->GetGUID();
                break;
            case GO_VALARJAR_RUNE_YELLOW:
                ValarjarRunesGUID[2] = go->GetGUID();
                break;
            case GO_VALARJAR_RUNE_ORANGE:
                ValarjarRunesGUID[3] = go->GetGUID();
                break;
            case GO_VALARJAR_RUNE_PURPLE:
                ValarjarRunesGUID[4] = go->GetGUID();
                break;
            case GO_RITUAL_STONE:
                RitualStoneGUID = go->GetGUID();
                go->SetLootState(GO_READY);
                go->UseDoorOrButton(3000000, false);
                go->setActive(true);
                break;
            case GO_GUARM_DOOR_HALYA:
                GuarmDoorHalyaGUID = go->GetGUID();
                break;
            default:
                break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case BOSS_HYRJA:
                HyrjaGUID = creature->GetGUID();
                break;
            case BOSS_HYMDALL:
                HymdallGUID = creature->GetGUID();
                break;
            case BOSS_ODYN:
                OdynGUID = creature->GetGUID();
                break;
            case BOSS_GUARM:
                GuarmGUID = creature->GetGUID();
                break;
            case BOSS_HELYA:
                HelyaGUID = creature->GetGUID();
                break;
            default:
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_HYRJA:
                return HyrjaGUID;
            case DATA_HYMDALL:
                return HymdallGUID;
            case DATA_ODYN:
                return OdynGUID;
            case DATA_GUARM:
                return GuarmGUID;
            case DATA_HELYA:
                return HelyaGUID;
            default:
                break;
            }

            return ObjectGuid::Empty;
        }

    protected:
        EventMap events;
        ObjectGuid HyrjaGUID;
        ObjectGuid HymdallGUID;
        ObjectGuid OdynGUID;
        ObjectGuid GuarmGUID;
        ObjectGuid HelyaGUID;
        ObjectGuid ValarjarRunesGUID[5];
        ObjectGuid RitualStoneGUID;
        ObjectGuid GuarmDoorHalyaGUID;
        ObjectGuid DoorBridgeGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_trial_of_valor_InstanceScript(map);
    }
};

void AddSC_instance_trial_of_valor()
{
    new instance_trial_of_valor();
}
