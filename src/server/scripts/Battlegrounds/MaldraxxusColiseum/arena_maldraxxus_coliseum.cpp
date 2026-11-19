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

#include "Battleground.h"
#include "BattlegroundScript.h"
#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"

namespace MaldraxxusColiseum
{
    namespace MapIds
    {
        static constexpr uint32 MaldraxxusColiseum = 2509;
    }

    namespace Creatures
    {
        static constexpr uint32 MaldraxxianGladiator = 185764;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door = 375890;
    }

    namespace Destinations
    {
        static constexpr Position Guard1 = { 2875.89f, 2285.57f, 3260.1755f };
        static constexpr Position Guard2 = { 2816.69f, 2300.51f, 3260.1885f };
        static constexpr Position Guard3 = { 2873.62f, 2219.39f, 3260.7085f };
        static constexpr Position Guard4 = { 2823.31f, 2204.30f, 3260.0960f };
    }

    namespace StringIds
    {
        static constexpr std::string_view Guard1 = "arena_maldraxxus_coliseum_1";
        static constexpr std::string_view Guard2 = "arena_maldraxxus_coliseum_2";
        static constexpr std::string_view Guard3 = "arena_maldraxxus_coliseum_3";
        static constexpr std::string_view Guard4 = "arena_maldraxxus_coliseum_4";
    }
}

struct arena_maldraxxus_coliseum : ArenaScript
{
    explicit arena_maldraxxus_coliseum(BattlegroundMap* map) : ArenaScript(map) { }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }

        for (ObjectGuid const& guid : _gladiatorGUIDs)
        {
            if (Creature* creature = battlegroundMap->GetCreature(guid))
            {
                if (creature->HasStringId(MaldraxxusColiseum::StringIds::Guard1))
                    creature->GetMotionMaster()->MovePoint(1, MaldraxxusColiseum::Destinations::Guard1);
                else if (creature->HasStringId(MaldraxxusColiseum::StringIds::Guard2))
                    creature->GetMotionMaster()->MovePoint(1, MaldraxxusColiseum::Destinations::Guard2);
                else if (creature->HasStringId(MaldraxxusColiseum::StringIds::Guard3))
                    creature->GetMotionMaster()->MovePoint(1, MaldraxxusColiseum::Destinations::Guard3);
                else if (creature->HasStringId(MaldraxxusColiseum::StringIds::Guard4))
                    creature->GetMotionMaster()->MovePoint(1, MaldraxxusColiseum::Destinations::Guard4);

                creature->DespawnOrUnsummon(2s);
            }
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case MaldraxxusColiseum::Creatures::MaldraxxianGladiator:
                _gladiatorGUIDs.emplace_back(creature->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case MaldraxxusColiseum::GameObjects::Door:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    GuidVector _doorGUIDs;
    GuidVector _gladiatorGUIDs;
};

void AddSC_arena_maldraxxus_coliseum()
{
    RegisterBattlegroundMapScript(arena_maldraxxus_coliseum, MaldraxxusColiseum::MapIds::MaldraxxusColiseum);
}
