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
SDComment: Quest support: 4285,4287,4288(crystal pylons), 4296, 6481, 10990, 10991, 10992, Field_Repair_Bot->Teaches spell 22704. Barov_journal->Teaches spell 26089
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
go_southfury_moonstone
go_field_repair_bot_74A
go_orb_of_command
go_resonite_cask
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

bool GOHello_go_cat_figurine(Player* pPlayer, GameObject* pGo)
{
    pPlayer->CastSpell(pPlayer,SPELL_SUMMON_GHOST_SABER,true);
    return false;
}

/*######
## go_crystal_pylons (3x)
######*/

bool GOHello_go_northern_crystal_pylon(Player* pPlayer, GameObject* pGo)
{
    if (pGo->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        pPlayer->PrepareQuestMenu(pGo->GetGUID());
        pPlayer->SendPreparedQuest(pGo->GetGUID());
    }

    if (pPlayer->GetQuestStatus(4285) == QUEST_STATUS_INCOMPLETE)
        pPlayer->AreaExploredOrEventHappens(4285);

    return true;
}

bool GOHello_go_eastern_crystal_pylon(Player* pPlayer, GameObject* pGo)
{
    if (pGo->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        pPlayer->PrepareQuestMenu(pGo->GetGUID());
        pPlayer->SendPreparedQuest(pGo->GetGUID());
    }

    if (pPlayer->GetQuestStatus(4287) == QUEST_STATUS_INCOMPLETE)
        pPlayer->AreaExploredOrEventHappens(4287);

    return true;
}

bool GOHello_go_western_crystal_pylon(Player* pPlayer, GameObject* pGo)
{
    if (pGo->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        pPlayer->PrepareQuestMenu(pGo->GetGUID());
        pPlayer->SendPreparedQuest(pGo->GetGUID());
    }

    if (pPlayer->GetQuestStatus(4288) == QUEST_STATUS_INCOMPLETE)
        pPlayer->AreaExploredOrEventHappens(4288);

    return true;
}

/*######
## go_barov_journal
######*/

bool GOHello_go_barov_journal(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->HasSkill(SKILL_TAILORING) && pPlayer->GetBaseSkillValue(SKILL_TAILORING) >= 280 && !pPlayer->HasSpell(26086))
    {
        pPlayer->CastSpell(pPlayer,26095,false);
    }
    return true;
}

/*######
## go_field_repair_bot_74A
######*/

bool GOHello_go_field_repair_bot_74A(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->HasSkill(SKILL_ENGINERING) && pPlayer->GetBaseSkillValue(SKILL_ENGINERING) >= 300 && !pPlayer->HasSpell(22704))
    {
        pPlayer->CastSpell(pPlayer,22864,false);
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

bool GOHello_go_orb_of_command(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestRewardStatus(7761))
        pPlayer->CastSpell(pPlayer,23460,true);

    return true;
}

/*######
## go_tablet_of_madness
######*/

bool GOHello_go_tablet_of_madness(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->HasSkill(SKILL_ALCHEMY) && pPlayer->GetSkillValue(SKILL_ALCHEMY) >= 300 && !pPlayer->HasSpell(24266))
    {
        pPlayer->CastSpell(pPlayer,24267,false);
    }
    return true;
}

/*######
## go_tablet_of_the_seven
######*/

//TODO: use gossip option ("Transcript the Tablet") instead, if Trinity adds support.
bool GOHello_go_tablet_of_the_seven(Player* pPlayer, GameObject* pGo)
{
    if (pGo->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
        return true;

    if (pPlayer->GetQuestStatus(4296) == QUEST_STATUS_INCOMPLETE)
        pPlayer->CastSpell(pPlayer,15065,false);

    return true;
}

/*#####
## go_jump_a_tron
######*/

bool GOHello_go_jump_a_tron(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestStatus(10111) == QUEST_STATUS_INCOMPLETE)
     pPlayer->CastSpell(pPlayer,33382,true);

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

    if (Creature* pCreature = pPlayer->SummonCreature(NpcPrisonEntry[Random],
        pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), pGo->GetAngle(pPlayer),
        TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
    {
        if (!pCreature->IsHostileTo(pPlayer))
        {
            uint32 Spell = 0;

            if (FactionTemplateEntry const* pFaction = pCreature->getFactionTemplateEntry())
            {
                switch(pFaction->faction)
                {
                    case 1011: Spell = SPELL_REP_LC; break;
                    case 935: Spell = SPELL_REP_SHAT; break;
                    case 942: Spell = SPELL_REP_CE; break;
                    case 933: Spell = SPELL_REP_CON; break;
                    case 989: Spell = SPELL_REP_KT; break;
                    case 970: Spell = SPELL_REP_SPOR; break;
                }

                if (Spell)
                    pCreature->CastSpell(pPlayer, Spell, false);
                else
                    error_log("TSCR: go_ethereum_prison summoned Creature (entry %u) but faction (%u) are not expected by script.", pCreature->GetEntry(), pCreature->getFaction());
            }
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
## go_resonite_cask
######*/

enum
{
    NPC_GOGGEROC    = 11920
};

bool GOHello_go_resonite_cask(Player* pPlayer, GameObject* pGO)
{
    if (pGO->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        pGO->SummonCreature(NPC_GOGGEROC, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

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

    if (BirdEntry)
        pPlayer->SummonCreature(BirdEntry, fX, fY, fZ, pGo->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);

    return false;
}

/*######
## go_southfury_moonstone
######*/

enum
{
    NPC_RIZZLE                  = 23002,
    SPELL_BLACKJACK             = 39865, //stuns player
    SPELL_SUMMON_RIZZLE         = 39866

};

bool GOHello_go_southfury_moonstone(Player* pPlayer, GameObject* pGo)
{
    //implicitTarget=48 not implemented as of writing this code, and manual summon may be just ok for our purpose
    //pPlayer->CastSpell(pPlayer,SPELL_SUMMON_RIZZLE,false);

    if (Creature* pCreature = pPlayer->SummonCreature(NPC_RIZZLE, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
        pCreature->CastSpell(pPlayer,SPELL_BLACKJACK,false);

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

/*######
## go_fel_crystalforge
######*/

#define GOSSIP_FEL_CRYSTALFORGE_TEXT 31000
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN 31001
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_1 "Purchase 1 Unstable Flask of the Beast for the cost of 10 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_5 "Purchase 5 Unstable Flask of the Beast for the cost of 50 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN "Use the fel crystalforge to make another purchase."

enum
{
    SPELL_CREATE_1_FLASK_OF_BEAST   = 40964,
    SPELL_CREATE_5_FLASK_OF_BEAST   = 40965,
};

bool GOHello_go_fel_crystalforge(Player* pPlayer, GameObject* pGO)
{
    if ( pGO->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER ) /* != GAMEOBJECT_TYPE_QUESTGIVER) */
        pPlayer->PrepareQuestMenu(pGO->GetGUID()); /* return true*/

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, pGO->GetGUID());

    return true;
}

bool GOSelect_go_fel_crystalforge(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->CastSpell(pPlayer,SPELL_CREATE_1_FLASK_OF_BEAST,false);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, pGO->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->CastSpell(pPlayer,SPELL_CREATE_5_FLASK_OF_BEAST,false);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, pGO->GetGUID());
            break;
    case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, pGO->GetGUID());
            break;
    }
    return true;
}

/*######
## go_bashir_crystalforge
######*/

enum
{
    SPELL_CREATE_1_FLASK_OF_SORCERER   = 40968,
    SPELL_CREATE_5_FLASK_OF_SORCERER   = 40970,
};

bool GOHello_go_bashir_crystalforge(Player* pPlayer, GameObject* pGO)
{
    pPlayer->CastSpell(pPlayer,SPELL_CREATE_1_FLASK_OF_SORCERER,false);
    return false;
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
    newscript->Name = "go_southfury_moonstone";
    newscript->pGOHello =           &GOHello_go_southfury_moonstone;
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
    newscript->Name = "go_resonite_cask";
    newscript->pGOHello =           &GOHello_go_resonite_cask;
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

    newscript = new Script;
    newscript->Name = "go_fel_crystalforge";
    newscript->pGOHello =           &GOHello_go_fel_crystalforge;
    newscript->pGOSelect =          &GOSelect_go_fel_crystalforge;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_bashir_crystalforge";
    newscript->pGOHello =           &GOHello_go_bashir_crystalforge;
    newscript->RegisterSelf();
}

