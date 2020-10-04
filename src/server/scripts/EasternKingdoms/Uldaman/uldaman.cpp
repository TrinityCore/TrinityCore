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

/* ScriptData
SDName: Uldaman
SD%Complete: 100
SDCategory: Uldaman
EndScriptData */

/* ContentData
go_keystone_chamber
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "uldaman.h"

/*######
## go_keystone_chamber
######*/

class go_keystone_chamber : public GameObjectScript
{
    public:
        go_keystone_chamber() : GameObjectScript("go_keystone_chamber") { }

        struct go_keystone_chamberAI : public GameObjectAI
        {
            go_keystone_chamberAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* /*player*/) override
            {
                instance->SetData(DATA_IRONAYA_SEAL, IN_PROGRESS); //door animation and save state.
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetUldamanAI<go_keystone_chamberAI>(go);
        }
};

void AddSC_uldaman()
{
    new go_keystone_chamber();
}
