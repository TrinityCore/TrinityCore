/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "bastion_of_twilight.h"

class at_theralion_and_valiona_intro : public AreaTriggerScript
{
    public:
        at_theralion_and_valiona_intro() : AreaTriggerScript("at_theralion_and_valiona_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_THERALION_AND_VALIONA_INTRO, IN_PROGRESS);
            return true;
        }
};

void AddSC_bastion_of_twilight()
{
    new at_theralion_and_valiona_intro();
}