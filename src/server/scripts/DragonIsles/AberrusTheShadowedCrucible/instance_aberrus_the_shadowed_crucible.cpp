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

#include "Creature.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "aberrus_the_shadowed_crucible.h"

ObjectData const creatureData[] =
{
    { BOSS_KAZZARA_THE_HELLFORGED,              DATA_KAZZARA_THE_HELLFORGED         },
    { BOSS_SHADOWFLAME_AMALGAMATION,            DATA_THE_AMALGAMATION_CHAMBER       },
    { BOSS_RIONTHUS,                            DATA_THE_FORGOTTEN_EXPERIMENTS      },
    { BOSS_WARLORD_KAGNI,                       DATA_ASSAULT_OF_THE_ZAQALI          },
    { BOSS_RASHOK_THE_ELDER,                    DATA_RASHOK_THE_ELDER               },
    { BOSS_ZSKARN_THE_VIGILANT_STEWARD,         DATA_ZSKARN_THE_VIGILANT_STEWARD    },
    { BOSS_MAGMORAX,                            DATA_MAGMORAX                       },
    { BOSS_ECHO_OF_NELTHARION,                  DATA_ECHO_OF_NELTHARION             },
    { BOSS_SCALECOMMANDER_SARKARETH,            DATA_SCALECOMMANDER_SARKARETH       },
    { NPC_SCALECOMMANDER_SARKARETH_AT_KAZZARA,  DATA_SARKARETH_AT_KAZZARA           },
    { 0,                                        0                                   }  // END
};

DoorData const doorData[] =
{
    { GO_KAZZARA_DOOR, DATA_KAZZARA_THE_HELLFORGED,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,               0,                            EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

ObjectData const objectData[] =
{
    { GO_KAZZARA_GATE, DATA_KAZZARA_GATE },
    { 0,               0                 }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_KAZZARA_THE_HELLFORGED,      {{ 2688 }} },
    { DATA_THE_AMALGAMATION_CHAMBER,    {{ 2687 }} },
    { DATA_THE_FORGOTTEN_EXPERIMENTS,   {{ 2693 }} },
    { DATA_ASSAULT_OF_THE_ZAQALI,       {{ 2682 }} },
    { DATA_RASHOK_THE_ELDER,            {{ 2680 }} },
    { DATA_ZSKARN_THE_VIGILANT_STEWARD, {{ 2689 }} },
    { DATA_MAGMORAX,                    {{ 2683 }} },
    { DATA_ECHO_OF_NELTHARION,          {{ 2684 }} },
    { DATA_SCALECOMMANDER_SARKARETH,    {{ 2685 }} }
};

enum AberrusInstanceSpells
{
    SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_3 = 403409 // Winglord Dezran, Sarkareth and Zskarn (Kazzara Summon)
};

class instance_aberrus_the_shadowed_crucible : public InstanceMapScript
{
public:
    instance_aberrus_the_shadowed_crucible() : InstanceMapScript(ATSCScriptName, 2569) { }

    struct instance_aberrus_the_shadowed_crucible_InstanceMapScript: public InstanceScript
    {
        instance_aberrus_the_shadowed_crucible_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, objectData);
            LoadDoorData(doorData);
            LoadDungeonEncounterData(encounters);

            _kazzaraIntroState = NOT_STARTED;
            _kazzaraAliveIntroNPCs = 0;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_KAZZARA_INTRO_STATE:
                    return _kazzaraIntroState;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 value) override
        {
            switch (dataId)
            {
                case DATA_KAZZARA_INTRO_STATE:
                    _kazzaraIntroState = value;
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->HasStringId("kazzara_intro_trash"))
                _kazzaraAliveIntroNPCs++;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("kazzara_intro_trash"))
            {
                if (_kazzaraIntroState != NOT_STARTED)
                    return;

                _kazzaraAliveIntroNPCs--;
                if (_kazzaraAliveIntroNPCs > 0)
                    return;

                _kazzaraIntroState = IN_PROGRESS;

                Creature* sarkareth = GetCreature(DATA_SARKARETH_AT_KAZZARA);
                if (!sarkareth)
                    return;

                sarkareth->CastSpell(nullptr, SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_3);
            }
        }

    private:
        uint8 _kazzaraAliveIntroNPCs;
        uint8 _kazzaraIntroState;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_aberrus_the_shadowed_crucible_InstanceMapScript(map);
    }
};

void AddSC_instance_aberrus_the_shadowed_crucible()
{
    new instance_aberrus_the_shadowed_crucible();
}
