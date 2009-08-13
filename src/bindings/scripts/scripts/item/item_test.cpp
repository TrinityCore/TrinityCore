/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Item_Test
SD%Complete: 100
SDComment: Used for Testing Item Scripts
SDCategory: Items
EndScriptData */

#include "precompiled.h"

extern void LoadDatabase();

bool ItemUse_item_test(Player* pPlayer, Item* _Item, SpellCastTargets const& targets)
{
    LoadDatabase();
    return true;
}

void AddSC_item_test()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="item_test";
    newscript->pItemUse = &ItemUse_item_test;
    newscript->RegisterSelf();
}

