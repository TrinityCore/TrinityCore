/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "darkheart_thicket.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

DoorData const doorData[] =
{
    { GO_DOOR_ROOM_GLAIDALIS_1,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_2,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_3,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_4,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_5,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_6,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_7,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_8,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_9,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_10,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_11,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_12,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_13,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_14,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_15,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_16,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_DRESARON_1,         DATA_DRESARON,              DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_DRESARON_2,         DATA_DRESARON,              DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_XAVIUS,             DATA_SHADE_OF_XAVIUS,       DOOR_TYPE_ROOM }
};

struct instance_darkheart_thicket : public InstanceScript
{
    instance_darkheart_thicket(InstanceMap* map) : InstanceScript(map), _introDone(false) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);
        SetChallengeDoorPos({ 3231.927979f, 1826.731812f, 233.376038f, 3.374087f });
    }

    void OnUnitDeath(Unit* unit) override
    {
        if (unit->IsCreature() && !_introDone)
        {
            DoCastSpellOnPlayers(SPELL_CONVERSATION_INTRO);
            _introDone = true;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        if (instance->IsHeroic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 2.f);
        if (instance->IsMythic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 1.33f);
    }

    bool SetBossState(uint32 type, EncounterState state) override
    {
        if (!InstanceScript::SetBossState(type, state))
            return false;

        switch (type)
        {
            case DATA_ARCHDRUID_GLAIDALIS:
            {
                if (state == DONE)
                    DoCastSpellOnPlayers(SPELL_CONVERSATION_AFTER_FIRST_BOSS);

                break;
            }
            case DATA_SHADE_OF_XAVIUS:
            {
                if (state == DONE)
                    if (Creature* malfurion = GetCreature(NPC_MALFURION_STORMRAGE))
                        malfurion->AI()->DoAction(ACTION_MALFURION_OUTRO);
                break;
            }
            default:
                break;
        }

        return true;
    }

    bool _introDone;
};

void AddSC_instance_darkheart_thicket()
{
    RegisterInstanceScript(instance_darkheart_thicket, 1466);
}
