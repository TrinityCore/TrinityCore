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
SDName: Arathi Highlands
SD%Complete: 100
SDComment: Quest support: 665
SDCategory: Arathi Highlands
EndScriptData */

/* ContentData
npc_professor_phizzlethorpe
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_professor_phizzlethorpe
######*/

#define SAY_PROGRESS_1		"Ok, $N. Follow me to the cave where I'll attempt to harness the power of the rune stone into these goggles."
#define SAY_PROGRESS_2		"I discovered this cave on our first day here. I believe the energy in the stone can be used to our advantage."
#define SAY_PROGRESS_3		"I'll begin drawing energy from the stone. Your job, $N, is to defend me. This place is cursed... trust me."
#define EMOTE_PROGRESS_4	"begins tinkering with the goggles before the stone."
#define SAY_AGGRO			"Help!!! Get these things off me so I can get my work done!"
#define SAY_PROGRESS_5		"Almost done! Just a little longer!"
#define SAY_PROGRESS_6		"I've done it! I have harnessed the power of the stone into the goggles! Let's get out of here!"
#define SAY_PROGRESS_7		"Phew! Glad to be back from that creepy cave."
#define EMOTE_PROGRESS_8	"hands one glowing goggles over to Doctor Draxlegauge."
#define SAY_PROGRESS_9		"Doctor Draxlegauge will give you further instructions, $N. Many thanks for your help!"

#define QUEST_SUNKEN_TREASURE	665
#define MOB_VENGEFUL_SURGE	2776

struct TRINITY_DLL_DECL npc_professor_phizzlethorpeAI : public npc_escortAI
{
	npc_professor_phizzlethorpeAI(Creature *c) : npc_escortAI(c) {Reset();}

	void WaypointReached(uint32 i)
	{
		Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

		switch(i)
		{
		case 4:DoSay(SAY_PROGRESS_2, LANG_UNIVERSAL, player, true);break;
		case 5:DoSay(SAY_PROGRESS_3, LANG_UNIVERSAL, player, true);break;
		case 8:DoTextEmote(EMOTE_PROGRESS_4, NULL);break;
		case 9: 
			{
			m_creature->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96, -2142.49, 20.15, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
			m_creature->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96, -2142.49, 20.15, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
			break;
			}
		case 10:DoSay(SAY_PROGRESS_5, LANG_UNIVERSAL, player, true);break;
		case 11:DoSay(SAY_PROGRESS_6, LANG_UNIVERSAL, player, true);break;
		case 19:DoSay(SAY_PROGRESS_7, LANG_UNIVERSAL, player, true); break;
		case 20:
			DoTextEmote(EMOTE_PROGRESS_8, NULL);
			DoSay(SAY_PROGRESS_9, LANG_UNIVERSAL, player, true);
			if(player)
			((Player*)player)->GroupEventHappens(QUEST_SUNKEN_TREASURE, m_creature);
			break;
		}
	}

	void JustSummoned(Creature *summoned)
	{
		summoned->AI()->AttackStart(m_creature);
	}

	void Reset(){}

	void Aggro(Unit* who)
	{
		DoSay(SAY_AGGRO, LANG_UNIVERSAL, NULL);
	}

	void JustDied(Unit* killer)
	{
		if (PlayerGUID)
		{
			Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);
			if (player)
				((Player*)player)->FailQuest(QUEST_SUNKEN_TREASURE);
		}
	}

	void UpdateAI(const uint32 diff)
	{
		npc_escortAI::UpdateAI(diff);
	}
};

bool QuestAccept_npc_professor_phizzlethorpe(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_SUNKEN_TREASURE)
    {
		creature->Say(SAY_PROGRESS_1, LANG_UNIVERSAL, player->GetGUID());
        ((npc_escortAI*)(creature->AI()))->Start(false, false, false, player->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_professor_phizzlethorpeAI(Creature *_Creature)
{
	npc_professor_phizzlethorpeAI* professor_phizzlethorpeAI = new npc_professor_phizzlethorpeAI(_Creature);

	professor_phizzlethorpeAI->AddWaypoint(0, -2066.45, -2085.96, 9.08);
	professor_phizzlethorpeAI->AddWaypoint(1, -2077.99, -2105.33, 13.24);
	professor_phizzlethorpeAI->AddWaypoint(2, -2074.60, -2109.67, 14.24);
	professor_phizzlethorpeAI->AddWaypoint(3, -2076.60, -2117.46, 16.67);
	professor_phizzlethorpeAI->AddWaypoint(4, -2073.51, -2123.46, 18.42, 2000); 
	professor_phizzlethorpeAI->AddWaypoint(5, -2073.51, -2123.46, 18.42, 4000); 
	professor_phizzlethorpeAI->AddWaypoint(6, -2066.60, -2131.85, 21.56);
	professor_phizzlethorpeAI->AddWaypoint(7, -2053.85, -2143.19, 20.31);
	professor_phizzlethorpeAI->AddWaypoint(8, -2043.49, -2153.73, 20.20, 12000);
	professor_phizzlethorpeAI->AddWaypoint(9, -2043.49, -2153.73, 20.20, 14000); 
	professor_phizzlethorpeAI->AddWaypoint(10, -2043.49, -2153.73, 20.20, 10000);
	professor_phizzlethorpeAI->AddWaypoint(11, -2043.49, -2153.73, 20.20, 2000); 
	professor_phizzlethorpeAI->AddWaypoint(12, -2053.85, -2143.19, 20.31);
	professor_phizzlethorpeAI->AddWaypoint(13, -2066.60, -2131.85, 21.56);
	professor_phizzlethorpeAI->AddWaypoint(14, -2073.51, -2123.46, 18.42);
	professor_phizzlethorpeAI->AddWaypoint(15, -2076.60, -2117.46, 16.67);
	professor_phizzlethorpeAI->AddWaypoint(16, -2074.60, -2109.67, 14.24);
	professor_phizzlethorpeAI->AddWaypoint(17, -2077.99, -2105.33, 13.24);
	professor_phizzlethorpeAI->AddWaypoint(18, -2066.45, -2085.96, 9.08);
	professor_phizzlethorpeAI->AddWaypoint(19, -2066.41, -2086.21, 8.97, 6000); 
	professor_phizzlethorpeAI->AddWaypoint(20, -2066.41, -2086.21, 8.97, 2000);

	return (CreatureAI*)professor_phizzlethorpeAI;
}

void AddSC_arathi_highlands()
{
	Script * newscript;

	newscript = new Script;
	newscript->Name = "npc_professor_phizzlethorpe";
	newscript->GetAI = &GetAI_npc_professor_phizzlethorpeAI;
	newscript->pQuestAccept = &QuestAccept_npc_professor_phizzlethorpe;
	newscript->RegisterSelf();
}