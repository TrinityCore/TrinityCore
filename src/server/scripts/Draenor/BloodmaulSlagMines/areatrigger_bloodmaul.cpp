/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiersImpl.h"
#include "instance_bloodmaul.h"
#include <forward_list>

namespace Instances
{
    namespace Bloodmaul
    {
        // AreaTriggers for spells: 151582
        class AreaTrigger_SuppresionField : public AreaTriggerAI
        {
            enum class Spells : uint32
            {
                SuppresionFieldEffect = 151638,
            };

            std::forward_list<ObjectGuid> m_Targets;

        public:
            AreaTrigger_SuppresionField(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger), m_Targets() { }

            void OnRemove() override
            {
                // If We are on the last tick.
                if (at->GetDuration() < 100)
                {
                    for (auto guid : m_Targets)
                    {
                        Unit* target = ObjectAccessor::GetUnit(*at, guid);
                        if (target)
                            target->RemoveAura(uint32(Spells::SuppresionFieldEffect));
                    }
                }
            }

            void OnUnitEnter(Unit* unit) override
            {
                if (at->GetCaster() || !at->GetCaster()->IsValidAttackTarget(unit))
                    return;

                at->GetCaster()->CastSpell(unit, uint32(Spells::SuppresionFieldEffect), true);
            }

            void OnUnitExit(Unit* unit) override
            {
                unit->RemoveAura(uint32(Spells::SuppresionFieldEffect));
            }
        };

        // 9686 - Start overseer event
        class AreaTrigger_at_bloodmaul_overseer_event : public AreaTriggerScript
        {
        public:

            AreaTrigger_at_bloodmaul_overseer_event() : AreaTriggerScript("at_bloodmaul_overseer_event") { }

            bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
            {
                if (Creature* overseer = GetClosestCreatureWithEntry(player, MobEntries::BloodmaulOverseer, 100.0f))
                    if (overseer->AI())
                        overseer->AI()->DoAction(0);

                return false;
            }
        };

        // 9783 - Start magmolatus begin area event
        class AreaTrigger_at_magmolatus_begin_area : public AreaTriggerScript
        {
        public:

            AreaTrigger_at_magmolatus_begin_area() : AreaTriggerScript("at_magmolatus_begin_area") { }

            bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
            {
                if (player->GetInstanceScript())
                    if (Creature* explosionStalker = player->GetMap()->GetCreature(player->GetInstanceScript()->GetGuidData(MobEntries::LavaExplosionStalker)))
                        if (explosionStalker->AI())
                            explosionStalker->AI()->DoAction(0);

                return false;
            }
        };

        // 9725
        class AreaTrigger_at_SpawnSlagna : public AreaTriggerScript
        {
        public:

            AreaTrigger_at_SpawnSlagna() : AreaTriggerScript("at_SpawnSlagna") { }

            bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
            {
                if (player->GetInstanceScript())
                {
                    player->GetInstanceScript()->SetData(uint32(Data::SpawnSlagna), 0);
                    return true;
                }

                return false;
            }
        };
    }
}

void AddSC_areatrigger_Bloodmaul()
{
    RegisterAreaTriggerAI(Instances::Bloodmaul::AreaTrigger_SuppresionField);
    new Instances::Bloodmaul::AreaTrigger_at_bloodmaul_overseer_event();
    new Instances::Bloodmaul::AreaTrigger_at_magmolatus_begin_area();
    new Instances::Bloodmaul::AreaTrigger_at_SpawnSlagna();
}
