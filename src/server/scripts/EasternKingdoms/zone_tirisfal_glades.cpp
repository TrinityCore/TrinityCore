/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Creature.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"

class npc_agatha : public CreatureScript
{
public:
    npc_agatha() : CreatureScript("npc_agatha") { }

    enum
    {
        QUEST_FRESH_OUT_OF_THE_GRAVE    = 24959,
        SPELL_RIGOR_MORTIS              = 73523
    };

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_FRESH_OUT_OF_THE_GRAVE)
            player->RemoveAurasDueToSpell(SPELL_RIGOR_MORTIS);

        return true;
    }
};

void AddSC_tirisfal_glades()
{
    new npc_agatha();
}
