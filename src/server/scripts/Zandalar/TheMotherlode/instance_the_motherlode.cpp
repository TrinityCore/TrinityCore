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

 //Missing scripts

#include "GameObject.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "the_motherlode.h"

struct instance_the_motherlode : public InstanceScript
{
    instance_the_motherlode(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        switch (creature->GetEntry())
        {
        case NPC_COIN_OPERATED_CROWD_PUMMELER:
            CoinoperatedcrowdpummelerGUID = creature->GetGUID();
            break;
			
		case NPC_AZEROKK:
            AzerokkGUID = creature->GetGUID();
            break;
			
		case NPC_RIXXA_FLUXFLAME:
            RixxafluxflameGUID = creature->GetGUID();
            break;
			
		case NPC_MOGUL_RAZDUNK:
            MogulrazdunkGUID = creature->GetGUID();
            break;
			
        default:
            break;
        }
    };

    ObjectGuid GetGuidData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_COIN_OPERATED_CROWD_PUMMELER:
            return CoinoperatedcrowdpummelerGUID;
			
		case DATA_AZEROKK:
			return AzerokkGUID;
		
		case DATA_RIXXA_FLUXFLAME:
			return RixxafluxflameGUID;
		
		case DATA_MOGUL_RAZDUNK:
			return MogulrazdunkGUID;
			
        default:
            break;
        }
        return ObjectGuid::Empty;
    }

protected:
    ObjectGuid CoinoperatedcrowdpummelerGUID;
	ObjectGuid AzerokkGUID;
	ObjectGuid RixxafluxflameGUID;
	ObjectGuid MogulrazdunkGUID;
};
void AddSC_instance_the_motherlode();
{
    RegisterInstanceScript(instance_the_motherlode, 1594);
}
