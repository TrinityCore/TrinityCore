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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "krasarang_wilds.h"
#include "SpellScript.h"

#define CHECK_STATUS(a) (player->GetQuestStatus(a) == QUEST_STATUS_INCOMPLETE)
#define GOSSIP_CHOICE_1 "Let's fight !"
#define GOSSIP_CHOICE "<Reach out to touch Chi-Ji.>"

void AddSC_krasarang_wilds()
{
  
}
