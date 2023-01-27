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
#include "Player.h"
#include "InstanceScript.h"
#include "siege_of_boralus.h"
#include "GameObject.h"

enum SOBSpells
{
	BLOOD_IN_THE_WATER_INSTAKILL = 276433,
	BLOOD_IN_THE_WATER_SCREEN_EFFECT = 279893,
};

struct instance_siege_of_boralus : public InstanceScript
{
	instance_siege_of_boralus(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

	void OnPlayerEnter(Player* player)
	{
	}
};

class blood_in_the_water : public PlayerScript
{
public:
	blood_in_the_water() : PlayerScript("blood_in_the_water") { }

	uint32 checkTimer = 3000;

	void OnUpdate(Player* player, uint32 diff) override
	{
        if (player->GetAreaId() != 9354)
        return;

		if (checkTimer <= diff && player->GetAreaId() == 9354)
		{
			if (player->IsInWater())
			{
				player->CastSpell(player, BLOOD_IN_THE_WATER_SCREEN_EFFECT);
				if (player->HasAura(BLOOD_IN_THE_WATER_SCREEN_EFFECT) && player->IsAlive() && player->IsInWater())
				{
					player->GetScheduler().Schedule(2s, [player](TaskContext context)
					{
						player->CastSpell(player, BLOOD_IN_THE_WATER_INSTAKILL);
					});
				}	
			}
			if (!player->IsInWater() && player->GetAreaId() == 9354)
			{
				if (player->HasAura(BLOOD_IN_THE_WATER_SCREEN_EFFECT))
				{
					player->RemoveAura(BLOOD_IN_THE_WATER_SCREEN_EFFECT);
				}
			}
			checkTimer = 3000;
		}
		else checkTimer -= diff;
	}
};

void AddSC_instance_siege_of_boralus()
{
    RegisterInstanceScript(instance_siege_of_boralus, 1822);
	RegisterPlayerScript(blood_in_the_water);
}
