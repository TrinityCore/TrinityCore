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
SDName: Silverpine_Forest
SD%Complete: 100
SDComment: Quest support: 1886, 435
SDCategory: Silverpine Forest
EndScriptData */

/* ContentData
npc_astor_hadren
npc_deathstalker_erland
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_astor_hadren
######*/

struct TRINITY_DLL_DECL npc_astor_hadrenAI : public ScriptedAI
{
    npc_astor_hadrenAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
        m_creature->setFaction(68);
    }

    void Aggro(Unit* who)
    {
    }

    void JustDied(Unit *who)
    {
        m_creature->setFaction(68);
    }
};

CreatureAI* GetAI_npc_astor_hadren(Creature *_creature)
{
    return new npc_astor_hadrenAI(_creature);
}

bool GossipHello_npc_astor_hadren(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(1886) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "You're Astor Hadren, right?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    player->SEND_GOSSIP_MENU(623, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_astor_hadren(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->ADD_GOSSIP_ITEM( 0, "You've got something I need, Astor. And I'll be taking it now.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(624, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->CLOSE_GOSSIP_MENU();
            _Creature->setFaction(21);
            if(player)
                ((npc_astor_hadrenAI*)_Creature->AI())->AttackStart(player);
            break;
    }
    return true;
}

/*######
## npc_deathstalker_erland
######*/

#define SAY_QUESTACCEPT	"Let's get to the others, and keep an eye open for those wolves cutside..."
#define SAY_START		"Be careful, $N. Those wolves like to hide among the trees."
#define SAY_AGGRO_1		"A Mottled Worg attacks!"
#define SAY_AGGRO_2		"Beware! I am under attack!"
#define SAY_LAST		"We're almost there!"

#define SAY_THANKS		"We made it! Thanks, $N. I couldn't have gotten without you."
#define SAY_RANE		"It's good to see you again, Erland. What is your report?"
#define SAY_ANSWER		"Masses of wolves are to the east, and whoever lived at Malden's Orchard is gone."
#define SAY_MOVE_QUINN	"If I am excused, then I'd like to check on Quinn..."

#define SAY_GREETINGS	"Hello, Quinn. How are you faring?"
#define SAY_QUINN		"I've been better. Ivar the Foul got the better of me..."
#define SAY_ON_BYE		"Try to take better care of yourself, Quinn. You were lucky this time."

#define QUEST_ESCORTING	435
#define NPC_RANE		1950
#define NPC_QUINN		1951

struct TRINITY_DLL_DECL npc_deathstalker_erlandAI : public npc_escortAI
{
	npc_deathstalker_erlandAI(Creature *c) : npc_escortAI(c) {Reset();}

	void WaypointReached(uint32 i)
	{
		Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

		if (!player)
            return;

		switch(i)
		{
		case 1: DoSay(SAY_START, LANG_UNIVERSAL, player);break;
		case 13: 
			DoSay(SAY_LAST, LANG_UNIVERSAL, player);
			((Player*)player)->GroupEventHappens(QUEST_ESCORTING, m_creature);break;
		case 14: DoSay(SAY_THANKS, LANG_UNIVERSAL, player);break;
		case 15: {	
				Unit* Rane = FindCreature(NPC_RANE, 20);
				if(Rane)
					((Creature*)Rane)->Say(SAY_RANE, LANG_UNIVERSAL, NULL);				
				break;}
		case 16: DoSay(SAY_ANSWER, LANG_UNIVERSAL, NULL);break;
		case 17: DoSay(SAY_MOVE_QUINN, LANG_UNIVERSAL, NULL); break;
		case 24: DoSay(SAY_GREETINGS, LANG_UNIVERSAL, NULL);break;
		case 25: {
				Unit* Quinn = FindCreature(NPC_QUINN, 20);
				if(Quinn)
					((Creature*)Quinn)->Say(SAY_QUINN, LANG_GUTTERSPEAK, NULL);
				break;}
		case 26: DoSay(SAY_ON_BYE, LANG_UNIVERSAL, NULL);break;
			
		}
	}

	void Reset() {}

	void Aggro(Unit* who)
	{
		switch(rand()%2)
		{
		case 0: DoSay(SAY_AGGRO_1, LANG_UNIVERSAL, who);break;
		case 1: DoSay(SAY_AGGRO_2, LANG_UNIVERSAL, who);break;
		}
	}

	void UpdateAI(const uint32 diff)
	{
		npc_escortAI::UpdateAI(diff);
	}
};

bool QuestAccept_npc_deathstalker_erland(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_ESCORTING)
	{
		creature->Say(SAY_QUESTACCEPT, LANG_UNIVERSAL, player->GetGUID());
		((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
	}
    
    return true;
}

CreatureAI* GetAI_npc_deathstalker_erlandAI(Creature *_Creature)
{
    npc_deathstalker_erlandAI* deathstalker_erlandAI = new npc_deathstalker_erlandAI(_Creature);

	deathstalker_erlandAI->AddWaypoint(0, 1406.32, 1083.10, 52.55);
	deathstalker_erlandAI->AddWaypoint(1, 1400.49, 1080.42, 52.50); //first say
	deathstalker_erlandAI->AddWaypoint(2, 1388.48, 1083.10, 52.52);
	deathstalker_erlandAI->AddWaypoint(3, 1370.16, 1084.02, 52.30);
	deathstalker_erlandAI->AddWaypoint(4, 1359.02, 1080.85, 52.46);
	deathstalker_erlandAI->AddWaypoint(5, 1341.43, 1087.39, 52.69);
	deathstalker_erlandAI->AddWaypoint(6, 1321.93, 1090.51, 50.66);
	deathstalker_erlandAI->AddWaypoint(7, 1312.98, 1095.91, 47.49);
	deathstalker_erlandAI->AddWaypoint(8, 1301.09, 1102.94, 47.76);
	deathstalker_erlandAI->AddWaypoint(9, 1297.73, 1106.35, 50.18);
	deathstalker_erlandAI->AddWaypoint(10, 1295.49, 1124.32, 50.49);
	deathstalker_erlandAI->AddWaypoint(11, 1294.84, 1137.25, 51.75);
	deathstalker_erlandAI->AddWaypoint(12, 1292.89, 1158.99, 52.65);
	deathstalker_erlandAI->AddWaypoint(13, 1290.75, 1168.67, 52.56, 1000); //complete quest and say last
	deathstalker_erlandAI->AddWaypoint(14, 1287.12, 1203.49, 52.66, 5000); 
	deathstalker_erlandAI->AddWaypoint(15, 1287.12, 1203.49, 52.66, 4000); 
	deathstalker_erlandAI->AddWaypoint(16, 1287.12, 1203.49, 52.66, 5000); 
	deathstalker_erlandAI->AddWaypoint(17, 1287.12, 1203.49, 52.66, 4000); 
	deathstalker_erlandAI->AddWaypoint(18, 1290.72, 1207.44, 52.69);
	deathstalker_erlandAI->AddWaypoint(19, 1297.50, 1207.18, 53.74);
	deathstalker_erlandAI->AddWaypoint(20, 1301.32, 1220.90, 53.74);
	deathstalker_erlandAI->AddWaypoint(21, 1298.55, 1220.43, 53.74);
	deathstalker_erlandAI->AddWaypoint(22, 1297.59, 1211.23, 58.47);
	deathstalker_erlandAI->AddWaypoint(23, 1305.01, 1206.10, 58.51);
	deathstalker_erlandAI->AddWaypoint(24, 1310.51, 1207.36, 58.51, 5000);
	deathstalker_erlandAI->AddWaypoint(25, 1310.51, 1207.36, 58.51, 5000);
	deathstalker_erlandAI->AddWaypoint(26, 1310.51, 1207.36, 58.51, 2000);

	return (CreatureAI*)deathstalker_erlandAI;
}

/*######
## AddSC
######*/

void AddSC_silverpine_forest()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_astor_hadren";
    newscript->pGossipHello =  &GossipHello_npc_astor_hadren;
    newscript->pGossipSelect = &GossipSelect_npc_astor_hadren;
    newscript->GetAI = &GetAI_npc_astor_hadren;
    newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name="npc_deathstalker_erland";
	newscript->GetAI = &GetAI_npc_deathstalker_erlandAI;
	newscript->pQuestAccept = &QuestAccept_npc_deathstalker_erland;
	newscript->RegisterSelf();
}
