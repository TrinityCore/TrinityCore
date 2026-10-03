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

#ifndef TRINITYCORE_AI_GROUP_H
#define TRINITYCORE_AI_GROUP_H

#include "AIGroupScript.h"
#include "Define.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObjectAI.h"

class TC_GAME_API AIGroup : public CreatureAI
{
    public:
        ~AIGroup() { }
        explicit AIGroup(Creature* creature);

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

        AIGroupScript* GetScript()
        {
            return &_script;
        }

        AIGroupActiveActionSetList const& GetActiveActionSets() const
        {
            return _script.GetActiveActionSets();
        }

        // Custom hooks
        void InitializeAI() override;

        void OnActionTriggersChange(uint32 triggersId) override;

        void UpdateAI(uint32 diff) override;
        void MovementInform(uint32 type, uint32 id) override;

        // Original Action Triggers, ordered by id

        // Unit is hit by spell {Spell}.
        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override;

        // Unit dies.
        void JustDied(Unit* killer) override;

        // Unit spawns.
        void JustAppeared() override;

        // Unit receives emote {EmotesText}.
        void ReceiveEmote(Player* player, uint32 textEmote) override;

    private:
        AIGroupScript _script;
};

#endif
