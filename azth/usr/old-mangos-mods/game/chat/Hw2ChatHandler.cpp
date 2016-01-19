#include "Hw2ChatHandler.h"
#include "Chat.h"
#include "ScriptLoader.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "TemporarySummon.h"

#include <sstream>
#include <string>

std::string concat(const char* str1, const char* str2) {
    std::stringstream ss;
    ss << str1 << str2;
    return ss.str();
}

bool Hw2ChatHandler::runCommand(const char* script,const char* cmd, const char* args) {
    CommandScript *scr=(CommandScript*) Hw2Class::getScript(script);
    std::string full=concat(cmd,args);
    return handler.ExecuteCommandInTable(scr->GetCommands(),full.c_str(),full.c_str());
}

bool Hw2ChatHandler::AzerothSelezionaHandler(uint16 scelta,const char* args)
{    
	switch(scelta)
	{
		case 1:
			return runCommand("character_commandscript","pdump write",args);
		break;
		// aggiungere case per altre funzioni
		case 2:
			return runCommand("character_commandscript","pdump load",args);
		break;
	}
           
	return false;
}


bool Hw2ChatHandler::AzerothQuest(Player *player)
{
	QueryResult result=NULL;
	QueryResult result2=NULL;
	Field *fields=NULL;
	Field *fields2=NULL;
	uint32 index=0,cEntry=0;
	char* quest=0,*addquest=0;
	TempSummon *cr = NULL;
	bool completato;
	float x,y,z;

	result = Hw2Database.PQuery("SELECT `index`,`quest_id`,`add_quest` FROM `a_character_quests` WHERE `guid`= %u",player->GetGUIDLow());
	
	if(result)
	{
      do
	  {
		fields = result->Fetch();
		quest = (char*)fields[1].GetString().c_str();
		index = fields[0].GetUInt32();
		addquest = (char*)fields[2].GetString().c_str();
		completato=true;

		player->SetSelection(player->GetGUID());

		// Aggiunge una quest (svolge prima l'aggiunta in modo che combinata con un completa quest 
		//il sistema aggiunge e completa direttamente
		if (addquest && strcmp(addquest,"0")!=0)
		{
			if (runCommand("quest_commandscript","quest add",addquest))
				sHw2->Hw2SendSysMessage(player,"QUEST %s AGGIUNTA",addquest);
			else
			{
				Hw2Database.PQuery("UPDATE `a_character_quests` SET `add_quest`= 'ERRORE' WHERE `index`= %u",index);
				completato=false;
			}
		}


		//completa la quest
		if (quest && index!=0 && strcmp(quest,"0")!=0)
			if (runCommand("quest_commandscript","quest complete",quest))
			{
			  result2 = WorldDatabase.PQuery("SELECT `id` FROM `creature_involvedrelation` WHERE `quest`= %s",quest);
			  if(result2)
			  {	
				fields2 = result2->Fetch();
				cEntry = fields2[0].GetUInt32();
				player->GetClosePoint(x,y,z,player->GetObjectSize());
			    cr = player->SummonCreature(cEntry,x,y,z+1,4.14f,TEMPSUMMON_TIMED_DESPAWN,200000);
				if (cr)
				{
					cr->SetUInt32Value(UNIT_NPC_FLAGS, 0);
					cr->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
					cr->setFaction(35);
					cr->SetDisplayId(1825); //spirit shade
				}
			  }
			  sHw2->Hw2SendSysMessage(player,"QUEST %s COMPLETATA",quest);
			} 
			else
			{
			   completato=false;
			   Hw2Database.PQuery("UPDATE `a_character_quests` SET `quest_id`= 'ERRORE' WHERE `index`= %u",index); 
			}

       if (completato)
		   Hw2Database.PQuery("DELETE FROM `a_character_quests` WHERE `index`= %u",index);


	  } while (result->NextRow());
      
	  sHw2->Hw2SendSysMessage(player,"PROCEDURA COMPLETAMENTO QUEST TERMINATA");
	  player->SaveToDB();

	  return true;
	}

	return false;
}
