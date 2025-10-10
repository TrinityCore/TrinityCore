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

#include "CommonHelpers.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "ObjectAccessor.h"

Trinity::Helpers::Events::SetAggresiveStateEvent::SetAggresiveStateEvent(Creature* owner, bool startCombat/* = true*/, ObjectGuid summonerGUID/* = ObjectGuid::Empty*/) : _owner(owner), _startCombat(startCombat), _summonerGUID(summonerGUID)
{
}

bool Trinity::Helpers::Events::SetAggresiveStateEvent::Execute(uint64 /*time*/, uint32 /*diff*/)
{
    _owner->SetReactState(REACT_AGGRESSIVE);
    if (_startCombat)
    {
        if (Unit* currentVictim = _owner->SelectVictim())
        {
            if (_owner->IsAIEnabled())
                _owner->AI()->AttackStart(currentVictim);
        }
        else if (!_summonerGUID.IsEmpty())
            if (Creature* summoner = ObjectAccessor::GetCreature(*_owner, _summonerGUID))
                if (summoner->IsEngaged() && summoner->IsAIEnabled() && _owner->IsAIEnabled())
                    if (Unit* target = summoner->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        _owner->AI()->AttackStart(target);
    }
    return true;
}
