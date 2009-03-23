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
SDName: GO_Scripts
SD%Complete: 100
SDComment: Quest support: 4285,4287,4288(crystal pylons), 4296. Field_Repair_Bot->Teaches spell 22704. Barov_journal->Teaches spell 26089
SDCategory: Game Objects
EndScriptData */

/* ContentData
go_northern_crystal_pylon
go_eastern_crystal_pylon
go_western_crystal_pylon
go_barov_journal
go_field_repair_bot_74A
go_orb_of_command
go_tablet_of_madness
go_tablet_of_the_seven
go_teleporter
EndContentData */

#include "precompiled.h"

/*######
## go_crystal_pylons (3x)
######*/

bool GOHello_go_northern_crystal_pylon(Player *player, GameObject* _GO)
{
    if (_GO->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        player->PrepareQuestMenu(_GO->GetGUID());
        player->SendPreparedQuest(_GO->GetGUID());
    }

    if (player->GetQuestStatus(4285) == QUEST_STATUS_INCOMPLETE)
        player->AreaExploredOrEventHappens(4285);

    return true;
}

bool GOHello_go_eastern_crystal_pylon(Player *player, GameObject* _GO)
{
    if (_GO->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        player->PrepareQuestMenu(_GO->GetGUID());
        player->SendPreparedQuest(_GO->GetGUID());
    }

    if (player->GetQuestStatus(4287) == QUEST_STATUS_INCOMPLETE)
        player->AreaExploredOrEventHappens(4287);

    return true;
}

bool GOHello_go_western_crystal_pylon(Player *player, GameObject* _GO)
{
    if (_GO->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        player->PrepareQuestMenu(_GO->GetGUID());
        player->SendPreparedQuest(_GO->GetGUID());
    }

    if (player->GetQuestStatus(4288) == QUEST_STATUS_INCOMPLETE)
        player->AreaExploredOrEventHappens(4288);

    return true;
}

/*######
## go_barov_journal
######*/

bool GOHello_go_barov_journal(Player *player, GameObject* _GO)
{
    if(player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 280 && !player->HasSpell(26086))
    {
        player->CastSpell(player,26095,false);
    }
    return true;
}

/*######
## go_field_repair_bot_74A
######*/

bool GOHello_go_field_repair_bot_74A(Player *player, GameObject* _GO)
{
    if(player->HasSkill(SKILL_ENGINERING) && player->GetBaseSkillValue(SKILL_ENGINERING) >= 300 && !player->HasSpell(22704))
    {
        player->CastSpell(player,22864,false);
    }
    return true;
}

/*######
## go_orb_of_command
######*/

bool GOHello_go_orb_of_command(Player *player, GameObject* _GO)
{
    if( player->GetQuestRewardStatus(7761) )
        player->CastSpell(player,23460,true);

    return true;
}

/*######
## go_tablet_of_madness
######*/

bool GOHello_go_tablet_of_madness(Player *player, GameObject* _GO)
{
    if (player->HasSkill(SKILL_ALCHEMY) && player->GetSkillValue(SKILL_ALCHEMY) >= 300 && !player->HasSpell(24266))
    {
        player->CastSpell(player,24267,false);
    }
    return true;
}

/*######
## go_tablet_of_the_seven
######*/

//TODO: use gossip option ("Transcript the Tablet") instead, if Trinity adds support.
bool GOHello_go_tablet_of_the_seven(Player *player, GameObject* _GO)
{
    if (_GO->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
        return true;

    if (player->GetQuestStatus(4296) == QUEST_STATUS_INCOMPLETE)
        player->CastSpell(player,15065,false);

    return true;
}

/*######
## go_teleporter
######*/

bool GOHello_go_teleporter(Player *player, GameObject* _GO)
{
    player->TeleportTo(0, 1807.07f,336.105f,70.3975f,0.0f);
    return false;
}

/*#####
## go_jump_a_tron
######*/

bool GOHello_go_jump_a_tron(Player *player, GameObject* _GO)
{
    if (player->GetQuestStatus(10111) == QUEST_STATUS_INCOMPLETE)
 	player->CastSpell(player,33382,true);

    return true;
}

void AddSC_go_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="go_northern_crystal_pylon";
    newscript->pGOHello =           &GOHello_go_northern_crystal_pylon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_eastern_crystal_pylon";
    newscript->pGOHello =           &GOHello_go_eastern_crystal_pylon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_western_crystal_pylon";
    newscript->pGOHello =           &GOHello_go_western_crystal_pylon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_barov_journal";
    newscript->pGOHello =           &GOHello_go_barov_journal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_field_repair_bot_74A";
    newscript->pGOHello =           &GOHello_go_field_repair_bot_74A;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_orb_of_command";
    newscript->pGOHello =           &GOHello_go_orb_of_command;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_tablet_of_madness";
    newscript->pGOHello =           &GOHello_go_tablet_of_madness;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_tablet_of_the_seven";
    newscript->pGOHello =           &GOHello_go_tablet_of_the_seven;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_teleporter";
    newscript->pGOHello =           &GOHello_go_teleporter;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_jump_a_tron";
    newscript->pGOHello =           &GOHello_go_jump_a_tron;
    newscript->RegisterSelf();
}

