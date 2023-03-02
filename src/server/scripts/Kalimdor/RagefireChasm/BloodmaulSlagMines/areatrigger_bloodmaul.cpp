/*
 * Copyright 2023 AzgathCore
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
    }
}

void AddSC_areatrigger_Bloodmaul()
{
    RegisterAreaTriggerAI(Instances::Bloodmaul::AreaTrigger_SuppresionField);
}
