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

//Missing scripts and bosses

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "stormstout_brewery.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "ScriptedCreature.h"
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "Weather.h"
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Weather.h"
#include <Instances/InstanceScript.h>
#include <Movement/MotionMaster.h>
#include "SpellInfo.h"
#include "Player.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "GameObject.h"
#include <Instances/InstanceScript.h>
#include "TemporarySummon.h"
#include "Position.h"
#include <Globals/ObjectAccessor.h>
#include <Maps/Map.cpp>
#include "MapInstanced.h"
#include <Instances/InstanceScript.h>
#include <DungeonFinding/LFGMgr.h>
#include "LFG.h"
#include "InstanceScript.h"
#include "EventMap.h"
#include <Instances/InstanceScript.h>

class instance_stormstout_brewery : public InstanceMapScript
{
public:
    instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_stormstout_brewery_InstanceMapScript(map);
    }

    struct instance_stormstout_brewery_InstanceMapScript : public InstanceScript
    {
        ObjectGuid ookookGUID;
        ObjectGuid hoptallusGUID;
        ObjectGuid yanzhuGUID;

        instance_stormstout_brewery_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            ookookGUID      = ObjectGuid::Empty;
            hoptallusGUID   = ObjectGuid::Empty;
            yanzhuGUID      = ObjectGuid::Empty;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_OOK_OOK:
                    ookookGUID = creature->GetGUID();
                    break;
                case NPC_HOPTALLUS:
                    hoptallusGUID = creature->GetGUID();
                    break;
                case NPC_YAN_ZHU:
                    yanzhuGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* /*go*/) override
        {}

        void SetData(uint32 /*type*/, uint32 /*data*/) override
        {}

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_OOK_OOK:
                    return ookookGUID;
                case NPC_HOPTALLUS:
                    return hoptallusGUID;
                case NPC_YAN_ZHU:
                    return yanzhuGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
