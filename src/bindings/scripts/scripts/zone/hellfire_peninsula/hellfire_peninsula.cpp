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
SDName: Hellfire_Peninsula
SD%Complete: 100
SDComment: Quest support: 9375, 10129, 10146, 10162, 10163, 10340, 10346, 10347, 10382 (Special flight paths)
SDCategory: Hellfire Peninsula
EndScriptData */

/* ContentData
npc_wing_commander_dabiree
npc_gryphoneer_windbellow
npc_wing_commander_brack
npc_wounded_blood_elf
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_wing_commander_dabiree
######*/

#define GOSSIP_ITEM1_DAB "Fly me to Murketh and Shaadraz Gateways"
#define GOSSIP_ITEM2_DAB "Fly me to Shatter Point"

bool GossipHello_npc_wing_commander_dabiree(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    //Mission: The Murketh and Shaadraz Gateways
    if (player->GetQuestStatus(10146) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM1_DAB, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    //Shatter Point
    if (!player->GetQuestRewardStatus(10340))
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM2_DAB, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_wing_commander_dabiree(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33768,true);               //TaxiPath 585 (Gateways Murket and Shaadraz)
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,35069,true);               //TaxiPath 612 (Taxi - Hellfire Peninsula - Expedition Point to Shatter Point)
    }
    return true;
}

/*######
## npc_gryphoneer_windbellow
######*/

#define GOSSIP_ITEM1_WIN "Fly me to The Abyssal Shelf"
#define GOSSIP_ITEM2_WIN "Fly me to Honor Point"

bool GossipHello_npc_gryphoneer_windbellow(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    //Mission: The Abyssal Shelf || Return to the Abyssal Shelf
    if (player->GetQuestStatus(10163) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10346) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM1_WIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    //Go to the Front
    if (player->GetQuestStatus(10382) != QUEST_STATUS_NONE && !player->GetQuestRewardStatus(10382))
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM2_WIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_gryphoneer_windbellow(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33899,true);               //TaxiPath 589 (Aerial Assault Flight (Alliance))
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,35065,true);               //TaxiPath 607 (Taxi - Hellfire Peninsula - Shatter Point to Beach Head)
    }
    return true;
}

/*######
## npc_wing_commander_brack
######*/

#define GOSSIP_ITEM1_BRA "Fly me to Murketh and Shaadraz Gateways"
#define GOSSIP_ITEM2_BRA "Fly me to The Abyssal Shelf"
#define GOSSIP_ITEM3_BRA "Fly me to Spinebreaker Post"

bool GossipHello_npc_wing_commander_brack(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    //Mission: The Murketh and Shaadraz Gateways
    if (player->GetQuestStatus(10129) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM1_BRA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    //Mission: The Abyssal Shelf || Return to the Abyssal Shelf
    if (player->GetQuestStatus(10162) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10347) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM2_BRA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    //Spinebreaker Post
    if (player->GetQuestStatus(10242) == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(10242))
        player->ADD_GOSSIP_ITEM(2, GOSSIP_ITEM3_BRA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_wing_commander_brack(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33659,true);               //TaxiPath 584 (Gateways Murket and Shaadraz)
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33825,true);               //TaxiPath 587 (Aerial Assault Flight (Horde))
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 3)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,34578,true);               //TaxiPath 604 (Taxi - Reaver's Fall to Spinebreaker Ridge)
    }
    return true;
}

/*######
## npc_wounded_blood_elf
######*/

#define QUEST_THE_ROAD_TO_FALCON_WATCH 9375
#define SAY1      "Thank you for agreeing to help. Now, let's get out of here $N."
#define SAY2      "Over there! They're following us!"
#define SAY3      "Allow me a moment to rest. The journey taxes what little strength I have."
#define SAY4      "Did you hear something?"
#define SAY5      "Falcon Watch, at last! Now, where's my... Oh no! My pack, it's missing! Where has -"
#define SAYAGGRO  "You won't keep me from getting to Falcon Watch!"

struct TRINITY_DLL_DECL npc_wounded_blood_elfAI : public npc_escortAI
{
    npc_wounded_blood_elfAI(Creature *c) : npc_escortAI(c) {Reset();}

    void WaypointReached(uint32 i)
    {
        Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

        if (!player)
            return;

        switch (i)
        {

        case 0:
            DoSay(SAY1, LANG_UNIVERSAL, player);
            // Change faction, so mobs can attack
            m_creature->setFaction(1610);
            break;

        case 9:
            DoSay(SAY2, LANG_UNIVERSAL, player);
            // Spawn two Haal'eshi Talonguard
            {
                Creature* temp1 = m_creature->SummonCreature(16967, m_creature->GetPositionX()-15, m_creature->GetPositionY()-15, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                if (temp1) temp1->AI()->AttackStart(m_creature);
                Creature* temp2 = m_creature->SummonCreature(16967, m_creature->GetPositionX()-17, m_creature->GetPositionY()-17, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                if (temp2) temp2->AI()->AttackStart(m_creature);
            }
            break;

        case 13:
            DoSay(SAY3, LANG_UNIVERSAL, player);
            // NPC "should" kneel
            m_creature->HandleEmoteCommand(EMOTE_STATE_KNEEL);
            break;

        case 14:
            DoSay(SAY4, LANG_UNIVERSAL, player);
            // Spawn two Haal'eshi Windwalker
            {
                Creature* temp3 = m_creature->SummonCreature(16966, m_creature->GetPositionX()-15, m_creature->GetPositionY()-15, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                if (temp3) temp3->AI()->AttackStart(m_creature);
                Creature* temp4 = m_creature->SummonCreature(16966, m_creature->GetPositionX()-17, m_creature->GetPositionY()-17, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                if (temp4) temp4->AI()->AttackStart(m_creature);
            }
            break;

        case 27:
            DoSay(SAY5, LANG_UNIVERSAL, player);
            // Set faction back to normal
            m_creature->setFaction(1604);
            // Award quest credit
            if( PlayerGUID )
            {
                Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);
                if( player && player->GetTypeId() == TYPEID_PLAYER )
                    ((Player*)player)->GroupEventHappens(9375,m_creature);
            }
            break;
        }
    }

    void Aggro(Unit* who)
    {
        DoSay(SAYAGGRO, LANG_UNIVERSAL, who);
    }

    void Reset() { }

    void JustDied(Unit* killer)
        // If NPC dies, Quest fail
    {
        if (PlayerGUID)
        {
            Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_THE_ROAD_TO_FALCON_WATCH);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_wounded_blood_elf(Player* player, Creature* creature, Quest const* quest)
// Begin the escort quest
{
    if (quest->GetQuestId() == QUEST_THE_ROAD_TO_FALCON_WATCH)
    {
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_wounded_blood_elf(Creature *_Creature)
{
    npc_wounded_blood_elfAI* thisAI = new npc_wounded_blood_elfAI(_Creature);

    thisAI->AddWaypoint(0, -1137.72, 4272.10, 14.04, 3000);
    thisAI->AddWaypoint(1, -1141.34, 4232.42, 14.63);
    thisAI->AddWaypoint(2, -1133.47, 4220.88, 11.78);
    thisAI->AddWaypoint(3, -1126.18, 4213.26, 13.51);
    thisAI->AddWaypoint(4, -1100.12, 4204.32, 16.41);
    thisAI->AddWaypoint(5, -1063.68, 4197.92, 15.51);
    thisAI->AddWaypoint(6, -1027.28, 4194.36, 15.52);
    thisAI->AddWaypoint(7, -995.68, 4189.59, 19.84);
    thisAI->AddWaypoint(8, -970.90, 4188.60, 24.61);
    thisAI->AddWaypoint(9, -961.93, 4193.34, 26.11, 80000); // Summon 1
    thisAI->AddWaypoint(10, -935.52, 4210.99, 31.98);
    thisAI->AddWaypoint(11, -913.42, 4218.27, 37.29);
    thisAI->AddWaypoint(12, -896.53, 4207.73, 43.23);
    thisAI->AddWaypoint(13, -868.49, 4194.77, 46.75, 17000); // Kneel and Rest Here
    thisAI->AddWaypoint(14, -852.83, 4198.29, 47.28, 80000); // Summon 2
    thisAI->AddWaypoint(15, -819.85, 4200.50, 46.37);
    thisAI->AddWaypoint(16, -791.92, 4201.96, 44.19);
    thisAI->AddWaypoint(17, -774.42, 4202.46, 47.41);
    thisAI->AddWaypoint(18, -762.90, 4202.17, 48.81);
    thisAI->AddWaypoint(19, -728.25, 4195.35, 50.68);
    thisAI->AddWaypoint(20, -713.58, 4192.07, 53.98);
    thisAI->AddWaypoint(21, -703.09, 4189.74, 56.96);
    thisAI->AddWaypoint(22, -693.70, 4185.43, 57.06);
    thisAI->AddWaypoint(23, -686.38, 4159.81, 60.26);
    thisAI->AddWaypoint(24, -679.88, 4147.04, 64.20);
    thisAI->AddWaypoint(25, -656.74, 4147.72, 64.11);
    thisAI->AddWaypoint(26, -652.22, 4137.50, 64.58);
    thisAI->AddWaypoint(27, -649.99, 4136.38, 64.63, 20000); // Award Quest Credit

    return (CreatureAI*)thisAI;
}

/*######
##
######*/

void AddSC_hellfire_peninsula()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_wing_commander_dabiree";
    newscript->pGossipHello =   &GossipHello_npc_wing_commander_dabiree;
    newscript->pGossipSelect =  &GossipSelect_npc_wing_commander_dabiree;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_gryphoneer_windbellow";
    newscript->pGossipHello =   &GossipHello_npc_gryphoneer_windbellow;
    newscript->pGossipSelect =  &GossipSelect_npc_gryphoneer_windbellow;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_wing_commander_brack";
    newscript->pGossipHello =   &GossipHello_npc_wing_commander_brack;
    newscript->pGossipSelect =  &GossipSelect_npc_wing_commander_brack;
    newscript->RegisterSelf();
	
    newscript = new Script;
    newscript->Name="npc_wounded_blood_elf";
    newscript->GetAI = &GetAI_npc_wounded_blood_elf;
    newscript->pQuestAccept = &QuestAccept_wounded_blood_elf;
    newscript->RegisterSelf();
}