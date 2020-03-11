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

#include "InstanceScript.h"
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

class at_ascendant_council_intro_1 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_1() : AreaTriggerScript("at_ascendant_council_intro_1") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_1, IN_PROGRESS);
            return true;
        }
};

class at_ascendant_council_intro_2 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_2() : AreaTriggerScript("at_ascendant_council_intro_2") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_2, IN_PROGRESS);
            return true;
        }
};

class at_ascendant_council_intro_3 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_3() : AreaTriggerScript("at_ascendant_council_intro_3") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_3, IN_PROGRESS);
            return true;
        }
};

class at_chogall_intro : public AreaTriggerScript
{
    public:
        at_chogall_intro() : AreaTriggerScript("at_chogall_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_CHOGALL_INTRO, IN_PROGRESS);
            return true;
        }
};

void AddSC_bastion_of_twilight()
{
    new at_theralion_and_valiona_intro();
    new at_ascendant_council_intro_1();
    new at_ascendant_council_intro_2();
    new at_ascendant_council_intro_3();
    new at_chogall_intro();
}