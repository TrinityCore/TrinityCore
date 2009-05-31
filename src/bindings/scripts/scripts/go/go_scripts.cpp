/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDComment: Quest support: 4285,4287,4288(crystal pylons), 4296, 10990, 10991, 10992, Field_Repair_Bot->Teaches spell 22704. Barov_journal->Teaches spell 26089
SDCategory: Game Objects
EndScriptData */

/* ContentData
go_cat_figurine (the "trap" version of GO, two different exist)
go_northern_crystal_pylon
go_eastern_crystal_pylon
go_western_crystal_pylon
go_barov_journal
go_ethereum_prison
go_ethereum_stasis
go_sacred_fire_of_life
go_shrine_of_the_birds
go_field_repair_bot_74A
go_orb_of_command
go_tablet_of_madness
go_tablet_of_the_seven
go_tele_to_dalaran_crystal
go_tele_to_violet_stand
EndContentData */

#include "precompiled.h"

/*######
## go_cat_figurine
######*/

enum
{
    SPELL_SUMMON_GHOST_SABER    = 5968,
};

bool GOHello_go_cat_figurine(Player *player, GameObject* _GO)
{
    player->CastSpell(player,SPELL_SUMMON_GHOST_SABER,true);
    return false;
}

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
## go_gilded_brazier
######*/

enum
{
    NPC_STILLBLADE  = 17716,
};

bool GOHello_go_gilded_brazier(Player* pPlayer, GameObject* pGO)
{
    if (pGO->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
    {
        if (Creature* pCreature = pPlayer->SummonCreature(NPC_STILLBLADE, 8087.632, -7542.740, 151.568, 0.122, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
            pCreature->AI()->AttackStart(pPlayer);
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

/*#####
## go_jump_a_tron
######*/

bool GOHello_go_jump_a_tron(Player *player, GameObject* _GO)
{
    if (player->GetQuestStatus(10111) == QUEST_STATUS_INCOMPLETE)
     player->CastSpell(player,33382,true);

    return true;
}

/*######
## go_ethereum_prison
######*/

enum
{
    SPELL_REP_LC        = 39456,
    SPELL_REP_SHAT      = 39457,
    SPELL_REP_CE        = 39460,
    SPELL_REP_CON       = 39474,
    SPELL_REP_KT        = 39475,
    SPELL_REP_SPOR      = 39476
};

const uint32 NpcPrisonEntry[] =
{
    22810, 22811, 22812, 22813, 22814, 22815,               //good guys
    20783, 20784, 20785, 20786, 20788, 20789, 20790         //bad guys
};

bool GOHello_go_ethereum_prison(Player* pPlayer, GameObject* pGo)
{
    int Random = rand() % (sizeof(NpcPrisonEntry) / sizeof(uint32));

    if(Creature* pCreature = pPlayer->SummonCreature(NpcPrisonEntry[Random],
        pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), pGo->GetAngle(pPlayer),
        TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
    {
        if(!pCreature->IsHostileTo(pPlayer))
        {
            uint32 Spell = 0;
            FactionTemplateEntry const* pFaction = pCreature->getFactionTemplateEntry();

            switch(pFaction->faction)
            {
                case 1011: Spell = SPELL_REP_LC; break;
                case 935: Spell = SPELL_REP_SHAT; break;
                case 942: Spell = SPELL_REP_CE; break;
                case 933: Spell = SPELL_REP_CON; break;
                case 989: Spell = SPELL_REP_KT; break;
                case 970: Spell = SPELL_REP_SPOR; break;
            }

            if(Spell)
                pCreature->CastSpell(pPlayer, Spell, false);
            else
                error_log("TSCR: go_ethereum_prison summoned creature (entry %u) but faction (%u) are not expected by script.", pCreature->GetEntry(), pCreature->getFaction());
        }
    }

    return false;
}

/*######
## go_ethereum_stasis
######*/

const uint32 NpcStasisEntry[] =
{
    22825, 20888, 22827, 22826, 22828
};

bool GOHello_go_ethereum_stasis(Player* pPlayer, GameObject* pGo)
{
    int Random = rand() % (sizeof(NpcStasisEntry) / sizeof(uint32));

    pPlayer->SummonCreature(NpcStasisEntry[Random],
        pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), pGo->GetAngle(pPlayer),
        TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

    return false;
}

/*######
## go_sacred_fire_of_life
######*/

#define NPC_ARIKARA  10882

bool GOHello_go_sacred_fire_of_life(Player* pPlayer, GameObject* pGO)
{
    if (pGO->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        pPlayer->SummonCreature(NPC_ARIKARA, -5008.338, -2118.894, 83.657, 0.874, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

    return true;
}

/*######
## go_shrine_of_the_birds
######*/

enum
{
    NPC_HAWK_GUARD      = 22992,
    NPC_EAGLE_GUARD     = 22993,
    NPC_FALCON_GUARD    = 22994,
    GO_SHRINE_HAWK      = 185551,
    GO_SHRINE_EAGLE     = 185547,
    GO_SHRINE_FALCON    = 185553
};

bool GOHello_go_shrine_of_the_birds(Player* pPlayer, GameObject* pGo)
{
    uint32 BirdEntry = 0;

    float fX, fY, fZ;
    pGo->GetClosePoint(fX, fY, fZ, pGo->GetObjectSize(), INTERACTION_DISTANCE);

    switch(pGo->GetEntry())
    {
        case GO_SHRINE_HAWK:
            BirdEntry = NPC_HAWK_GUARD;
            break;
        case GO_SHRINE_EAGLE:
            BirdEntry = NPC_EAGLE_GUARD;
            break;
        case GO_SHRINE_FALCON:
            BirdEntry = NPC_FALCON_GUARD;
            break;
    }

    if(BirdEntry)
        pPlayer->SummonCreature(BirdEntry, fX, fY, fZ, pGo->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);

    return false;
}

/*######
## go_tele_to_dalaran_crystal
######*/

enum
{
    QUEST_LEARN_LEAVE_RETURN    = 12790,
    QUEST_TELE_CRYSTAL_FLAG     = 12845
};

bool GOHello_go_tele_to_dalaran_crystal(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestRewardStatus(QUEST_TELE_CRYSTAL_FLAG))
        return false;

    //TODO: must send error message (what kind of message? On-screen?)
    return true;
}

/*######
## go_tele_to_violet_stand
######*/

bool GOHello_go_tele_to_violet_stand(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestRewardStatus(QUEST_LEARN_LEAVE_RETURN) || pPlayer->GetQuestStatus(QUEST_LEARN_LEAVE_RETURN) == QUEST_STATUS_INCOMPLETE)
        return false;

    return true;
}

void AddSC_go_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "go_cat_figurine";
    newscript->pGOHello =           &GOHello_go_cat_figurine;
    newscript->RegisterSelf();

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
    newscript->Name = "go_gilded_brazier";
    newscript->pGOHello =           &GOHello_go_gilded_brazier;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_orb_of_command";
    newscript->pGOHello =           &GOHello_go_orb_of_command;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_shrine_of_the_birds";
    newscript->pGOHello =           &GOHello_go_shrine_of_the_birds;
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
    newscript->Name="go_jump_a_tron";
    newscript->pGOHello =           &GOHello_go_jump_a_tron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_ethereum_prison";
    newscript->pGOHello =           &GOHello_go_ethereum_prison;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_ethereum_stasis";
    newscript->pGOHello =           &GOHello_go_ethereum_stasis;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_sacred_fire_of_life";
    newscript->pGOHello =           &GOHello_go_sacred_fire_of_life;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_tele_to_dalaran_crystal";
    newscript->pGOHello =           &GOHello_go_tele_to_dalaran_crystal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_tele_to_violet_stand";
    newscript->pGOHello =           &GOHello_go_tele_to_violet_stand;
    newscript->RegisterSelf();
}

