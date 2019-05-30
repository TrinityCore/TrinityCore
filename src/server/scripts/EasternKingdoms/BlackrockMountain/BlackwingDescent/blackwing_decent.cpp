/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "blackwing_descent.h"

struct go_bwd_ancient_bell : public GameObjectAI
{
    go_bwd_ancient_bell(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* /*player*/) override
    {
        if (_instance->GetData(DATA_ATRAMEDES_INTRO) == DONE)
            return true;

        if (GameObject* bell = me->ToGameObject())
        {
            _instance->SetData(DATA_ATRAMEDES_INTRO, DONE);
            me->SendCustomAnim(0);
            me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

            if (Creature* column = _instance->GetCreature(DATA_COLUMN_OF_LIGHT))
                column->DespawnOrUnsummon();

            me->DespawnOrUnsummon(7s + 400ms);
        }
        return true;
    }
private:
    InstanceScript* _instance;
};

void AddSC_blackwing_descent()
{
    RegisterGameObjectAI(go_bwd_ancient_bell);
}
