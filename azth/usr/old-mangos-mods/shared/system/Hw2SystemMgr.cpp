#include "Hw2SystemMgr.h"
#include "World.h"
#include "Chat.h"
#include "Player.h"
#include "Creature.h"
#include "Language.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "AccountMgr.h"
#include "Hw2ChatHandler.h"
#include "Opcodes.h"

// INIT STATIC MEMBERS
std::map<uint32, class T*> Hw2Class::scriptList;

Hw2Class::Hw2Class() //constructor
{
	ListFilled=false;
	lista=(struct act *)malloc(sizeof(struct act));
	ConfCount=0;
    timerCambiaOra = 0;
    newHr = 0;
    m_modGameTime = time(NULL);
}

Hw2Class::~Hw2Class()
{



}

Hw2Class* Hw2Class::GetHw2()
{
    return sHw2;
}

void Hw2Class::setScriptList(std::map<uint32, class T*> sList) {
    scriptList=sList;
}

ScriptObject* Hw2Class::getScript(const char* name) {
    for (ScriptMap::iterator it = scriptList.begin(); it != scriptList.end(); ++it)
    {
        if (strcmp(((ScriptObject*)it->second)->GetName().c_str(),name)==0)
        {
            return (ScriptObject*)it->second;
        }
    }
    
    return NULL;
}

void Hw2Class::Update(uint32 diff)
{

    if (newHr!=0)
        if (timerCambiaOra < diff)
        {

                tm localTm = *localtime(&sHw2->GetModGameTime());
                int increment = newHr > 0 ? 1 : -1;

                if (localTm.tm_min >=59)
                {
                    localTm.tm_min  = 0;
                    localTm.tm_hour += increment;
                    newHr -= increment;
                }
                else
                if ( localTm.tm_min <=0)
                {
                    localTm.tm_min  = 59;
                    localTm.tm_hour += increment;
                    newHr -= increment;
                }

                localTm.tm_min  += increment;

                time_t newtime = mktime(&localTm);
                WorldPacket data(SMSG_LOGIN_SETTIMESPEED, 4 + 4 + 4);
                data.AppendPackedTime(newtime);
                data << float(0.01666667f);                             // game speed
                data << uint32(0);                                      // added in 3.1.2
                sWorld->SendGlobalMessage(&data);

                timerCambiaOra = 50;
                sHw2->m_modGameTime = newtime;

        } else timerCambiaOra -= diff;


}

void Hw2Class::Hw2SendSysMessage(Player *target,const char* msg, ...) {
	if (msg) {
		std::string out = "[Hw2 Message] ";
		out += msg;
		va_list args;
		ChatHandler(target->GetSession()).PSendSysMessage(out.c_str(),args);
	}
};

void Hw2Class::Hw2SendSysMessage(Player *target, int32 msg, ...) {
	const char *format = ChatHandler(target->GetSession()).GetTrinityString(msg);
	va_list args;
	Hw2SendSysMessage(target,format,args);
};


bool Hw2Class::RpgFunzioneIniziale(Player *pl)
{
	if (!pl)
		return false;

    Hw2Player *hPl=pl->hw2Player;
    
	QueryResult result = Hw2Database.PQuery("SELECT * FROM `a_rpg_players` WHERE `guid`= %u",pl->GetGUIDLow());
	if(result)  
    {
		Field *fields		= result->Fetch();
		hPl->RpgCredito		= fields[1].GetInt32();  // 0 e' uguale al guid
		hPl->RpgTotalePt	    = fields[2].GetInt32();
		hPl->RpgIdentity		= fields[3].GetCString();
		hPl->RpgSupervisor   = fields[4].GetUInt32();
		hPl->RpgPlGenere		= fields[5].GetUInt8();
		hPl->RpgEpigoni		= RpgContaDownLine(pl->GetGUID(),sHw2->RpgTrovaRank(hPl->RpgTotalePt)); //funzione per contare i downline
	}

	if (pl->getGender()!=hPl->RpgPlGenere)
	{
		hPl->RpgPlGenere=pl->getGender();
		Hw2Database.PQuery("UPDATE `a_rpg_players` SET `gender`='%u' WHERE `guid`='%u'",hPl->RpgPlGenere,pl->GetGUIDLow());
	}

	std::string name;

        if (hPl->RpgSupervisor!=0)
			sObjectMgr->GetPlayerNameByGUID(hPl->RpgSupervisor,name);

	if(name.empty() && sHw2->RpgTrovaRank(hPl->RpgTotalePt)>0)
	{
		sHw2->Hw2SendSysMessage(pl,"DEVI SCEGLIERE UN PRECETTORE PER POTER CONTINUARE A GUADAGNARE PUNTI RUOLO");
		pl->GetSession()->SendAreaTriggerMessage("DEVI AVERE UN PRECETTORE PER POTER GUADAGNARE PUNTI RUOLO!");
	}

	pl->GetSession()->SendAreaTriggerMessage("%s", sWorld->GetMotd()); // messaggio di benvenuto


	return true;
}

bool Hw2Class::DmIsTourn(Player *pl)
{
	QueryResult result=NULL;
	Field *fields=NULL;
	uint8 tournament=0;

    result = LoginDatabase.PQuery("SELECT `tournament` FROM `account` WHERE `id`= %u",pl->GetSession()->GetAccountId());
	if(result)
	{
		fields = result->Fetch();
		tournament = fields[0].GetUInt8();
        if (tournament==1)
		{
			  return true;
		}
	}
  return false;
}

uint8 Hw2Class::CheckAcc(Player *player,uint8 type)
{
    uint8 AccLvl = 0;

    uint32 AccId=player->GetSession()->GetAccountId();
    
	if (AccId==0) return AccLvl;

	if (type<1 || type>2) return AccLvl;

	QueryResult result = Hw2Database.PQuery("SELECT AccID,Comandi_1,Comandi_2 FROM `a_permessi_comandi`");
		if(!result) return AccLvl; 
		//	if (player->GetSession()->GetSecurity() >=  SEC_ADMINISTRATOR) // abilita i comandi se sei administrator
		//		return true;  
		//    else 
		//		return false; 
		do
		{
				Field *fields = result->Fetch();
				uint32 Acc = fields[0].GetUInt32();
				
				if (Acc==AccId) // se trova l'id account...controlla il tipo di comando e il suo livello
				{
						AccLvl = fields[type].GetUInt8();  // numero field uguale al tipo
                        return AccLvl;
				}

		 } while( result->NextRow());
  
 return AccLvl;
}



uint64 Hw2Class::HandleFindPlayer(const char* stringa,Player* Pl,Player *SelPl)
{

		Player *chr=NULL;
	    uint64 guid=0;

		if (!stringa || strcmp(stringa," ")==0) 
		{
			chr=SelPl;
			
			if (!chr)
			{
				sHw2->Hw2SendSysMessage(Pl,LANG_PLAYER_NOT_FOUND);
				return 0;
			}

				guid=chr->GetGUID();

		}else
		{
			std::string name = stringa;

			if(!normalizePlayerName(name))
			{
				sHw2->Hw2SendSysMessage(Pl,LANG_PLAYER_NOT_FOUND);
				return 0;
			}
            
            guid=sObjectMgr->GetPlayerGUIDByName(name.c_str());
            
            if (guid)
                chr=ObjectAccessor::FindPlayer(guid);
		}

        if (!IS_PLAYER_GUID(guid)) {
            sHw2->Hw2SendSysMessage(Pl,LANG_PLAYER_NOT_FOUND);
            return 0;
        }
        
		return guid;
		
}



bool Hw2Class::AzDumpWrite(Player *pl,const char* args)
{

    char* dir  = strtok((char*)args, " ");

	if (!dir)
		 strcpy( dir, "" );

	QueryResult result=NULL;
	Field *fields=NULL;
	std::string name,username,argomento;
	uint32 AccId=0,AccId2=0,count=0,errors=0,success=0;

	// ordinati per account altrimenti il controllo 
    //if (AccId==AccId2) count++; else count=1; non funziona
	result =  CharacterDatabase.PQuery("SELECT `guid`,`name` FROM `characters` order by `account`");
	
	if(!result) return false;

      do
	  {

		fields = result->Fetch();

		AccId =  sObjectMgr->GetPlayerAccountIdByGUID(MAKE_NEW_GUID(fields[0].GetUInt32(),0,HIGHGUID_PLAYER));
	    name  =  fields[1].GetCString();

		if (!sAccountMgr->GetName(AccId,username))  { ++errors; continue; } 

		//username = fields2[0].GetCString();// prende l'username dal select

		if (AccId==AccId2) count++;
		else count=1;

		AccId2 = AccId;

		//"account1.sql nomepg" (destinazine sorgente)

		std::string userdest;
		remove_copy( username.begin() , username.end() , back_inserter( userdest ) , ' ');

		argomento = CreaStringaComposta("%s/%s_%u.sql %s",dir,userdest.c_str(),count,name.c_str()); //username + "_" + CreaStringaComposta("%u",count) + ".sql " + name;

		if (Hw2ChatHandler(pl->GetSession()).AzerothSelezionaHandler(1,(char*)argomento.c_str() ))
			success++;
		else
		{   
			sLog->outError(LOG_FILTER_GENERAL,"ERRORE DI DUMP WRITE PER %s",(char*)argomento.c_str());
			errors++;
		}
        
	  } while( result->NextRow());
	
      sHw2->Hw2SendSysMessage(pl,"Sono stati creati %u dumps e ne sono falliti %u",success,errors);
    sLog->outInfo(LOG_FILTER_GENERAL,"Sono stati creati %u dumps e ne sono falliti %u",success,errors);
    
	return true;
    
}

bool Hw2Class::AzDumpLoad(Player *pl,const char* args)
{
  
	char* Id = strtok((char*)args, " ");

	char* dir  = strtok(NULL, " ");

	if (!dir)
		strcpy(dir,"");

	if (!Id)
	{
		sLog->outError(LOG_FILTER_GENERAL,"Nessun id specificato");
		return false;
	}

	QueryResult result=NULL;
	Field *fields=NULL;
	std::string username,argomento;
	uint32 StartId=0,AccId=0,AccId2=0,count=0,errors=0,success=0;
	bool dumped=false;
    
    StartId=atoi(Id);
	
	result =  LoginDatabase.PQuery("SELECT `id`,`username` FROM `account` where id>=%u",StartId);
	
	if(!result) return false;

      do
	  {
	    fields = result->Fetch();

		AccId = fields[0].GetUInt32();
		if (!sAccountMgr->GetName(AccId,username))  
		  { ++errors; continue; }

		do {

				if (AccId==AccId2) count++;
				else count=1;

				AccId2 = AccId;

				std::string userdest;
				remove_copy( username.begin() , username.end() , back_inserter( userdest ) , ' ');


				//"account1.sql nomeaccount"  ( sorgente destinazione)
				//utilizzo userdest per il file poiche' e' senza spazi..username per l'account
				argomento=CreaStringaComposta("%s/%s_%u.sql %s",dir,userdest.c_str(),count,username.c_str()); 

				if (Hw2ChatHandler(pl->GetSession()).AzerothSelezionaHandler(2,(char*)argomento.c_str()) )
				{
					dumped=true;
					sLog->outDebug(LOG_FILTER_GENERAL,"DUMP EFFETTUATO per %s",argomento.c_str());
					++success;
				}
				else 
				{
					dumped=false;
					sLog->outDebug(LOG_FILTER_GENERAL,"NO DUMP LOAD per %s ( errore critico o normale prassi per procedere)",argomento.c_str());
					++errors;
				}   

		} while (dumped==true);

	  } while( result->NextRow());
	
    sHw2->Hw2SendSysMessage(pl,"Sono stati caricati %u characters",success);
    sLog->outInfo(LOG_FILTER_GENERAL,"Sono stati caricati %u characters",success);

    sHw2->Hw2SendSysMessage(pl,"ATTENZIONE: SI CONSIGLIA DI RIAVVIARE IL MANGOS TRA QUALCHE *MINUTO ALTRIMENTI NON VERRANNO IMPORTATI TUTTI I CHARACTERS!!");
    sHw2->Hw2SendSysMessage(pl,"*IL SOFTWARE IMPIEGA DEL TEMPO PER PROCESSARE TUTTI I DUMPS SUL DATABASE UNA VOLTA CARICATI IN MEMORIA,QUINDI");
    sHw2->Hw2SendSysMessage(pl,"BISOGNA ATTENDERE DEL TEMPO (CHE VARIA A SECONDA DELLA QUANTITA' DI CHARACTERS IMPORTATI) PRIMA DI RIAVVIARE/CHIUDERE L'APPLICAZIONE");
    sHw2->Hw2SendSysMessage(pl,"SI CONSIGLIA DI CONTROLLARE LA TABELLA CHARACTERS FINCHE' NON RAGGIUNGE LA QUANTITA' DI RIGHE ESATTA'");

	return true;
    
}       

std::string Hw2Class::CreaStringaComposta(const char *format, ...)
{
	    std::string stringa;
        va_list ap;
        char str [1024];
        va_start(ap, format);
        vsnprintf(str,1024,format, ap );
        va_end(ap);
		stringa = str;
		return stringa;
}


bool Hw2Class::DoubleLoot(LootStoreItem const & i, std::vector<LootItem> quest_items,std::vector<LootItem> items)
{
	
	//&& i.maxcount==1)  questo controllo non � essenziale ( specialmente per le piantine)
	if (sHw2->AzConf[1] && i.mincountOrRef>0 )  
			{
				bool found=false;
				std::vector<LootItem>::iterator j,k;
				
				if (!items.empty()){
					j = items.begin();
						do { if (j->itemid==i.itemid) found=true;  j++; } while (!found && j != items.end());
							if (found) return true; }

				if (!quest_items.empty()){
					k = quest_items.begin();
						do { if (k->itemid==i.itemid) found=true;  k++;} while (!found && k != quest_items.end());
							if (found) return true; }
		    } 
   return false;
}

uint16 Hw2Class::ProcessaRefCount(LootStoreItemList Entries,uint16 *tot,uint16 *count,float rate)
{
	  uint16 numero=0,tot_t=0,count_t=0;
	  srand((unsigned)time(NULL)); 

	  if (rate<0) 
		  return numero;

	  uint16 Max=LOOT_MAX*rate;

      if (sHw2->AzConf[0])  // blocca tutte le azioni successive
	  {
		  for (LootStoreItemList::const_iterator i = Entries.begin() ; i != Entries.end() ; i++ ) {
              LootStoreItem* item = *i;
              if (item->mincountOrRef < 0) { 
                  tot_t=tot_t+item->maxcount; 
                  ++count_t; 
              }
          }
		  
		  if (count_t>0 && tot_t<Max) {
              numero=(rand()%(Max-tot_t))/count_t; 
          } //if (tot <= LOOT_MIN) 

	      
		  *tot=tot_t;
		  *count=count_t;
	  }

	  return numero;
}

uint16 Hw2Class::ProcessaGruppi(Loot& loot,float rate)
{
	uint16 random=0,numero3=0;

	if (rate>0)
	{
		size_t Max=LOOT_MAX*rate;

		if (AzConf[0])
		{
			if (loot.items.size()<Max) // mai minore uguale!
					 random = rand()%( Max-loot.items.size() );	 
			 else
					 random = rand()%LOOT_MIN;  // anche quando � maggiore fa un random ( da rivedere )

				numero3=random; // ((random > Max) ? random: 0);

			//	sLog.outString("count %u rate %f itemsize %i",*count_t,rate,loot.items.size());
		}

	}

	if (numero3<=0) numero3=1; // loop singolo

	return numero3;
}

bool Hw2Class::Hw2Config(bool start,uint8 mode,uint8 tipo,bool scelta)
{
 // 1: esegue tournament conf , 2: esegue rpg conf
	QueryResult risultato = NULL;
	Field *campo;
	uint32 ConfCount;

 if ( start || mode == 1 )
 {
     risultato = Hw2Database.PQuery("SELECT COUNT(*) FROM `a_tournament_conf`");
     if(!risultato) return false;
	 campo = risultato->Fetch();
	 ConfCount = campo[0].GetUInt32();

	 if(!ConfCount)
     return false;

	if (start){

    	  // inizializzazioni delle flag per il conf del tournament
		for (uint8 I=0;I<ConfCount;I++) TrMod[I] = 0; // inizializzazione a null per evitare crash
		QueryResult result = Hw2Database.PQuery("SELECT * FROM `a_tournament_conf`");
		if(!result) return false;    
			do
			{
				Field *fields = result->Fetch();
				uint8 mod = fields[0].GetUInt8();
				TrMod[mod] = fields[1].GetBool();
			} while( result->NextRow());

      return true;
	} else {
			if (tipo >= ConfCount) return false;
			TrMod[tipo] = scelta;
			uint8 val;
			if (scelta) val=1; else val=0;
			Hw2Database.PQuery("UPDATE `a_tournament_conf` SET `attivo` = %u WHERE `mod` = %u",val,tipo);

			if (tipo==5){  
				Hw2World *world= new Hw2World(sWorld);
                world->AzerothExtra("vuoto",2);
            }

			return true;
	}

 }

 if ( start || mode == 2 )
 {
	risultato = Hw2Database.PQuery("SELECT COUNT(*) FROM `a_rpg_conf`");
	if(!risultato) return false;
    campo = risultato->Fetch();
	ConfCount=campo[0].GetUInt32();

    if(!ConfCount)
     return false;

	if (start){
	  // inizializzazioni delle flag per il conf del tournament
		for (uint8 I=0;I<ConfCount;I++) { 
			AzConf[I] = false; // inizializzazione a null per evitare crash
			ConfDef[I] = "Non Definito";
		}

		QueryResult result = Hw2Database.PQuery("SELECT * FROM `a_rpg_conf`");
		if(!result) return false;    
			do
			{
				Field *fields = result->Fetch();
				uint8 mod = fields[0].GetUInt8();
				AzConf[mod] = fields[1].GetBool();
				ConfDef[mod] = fields[2].GetCString();

			} while( result->NextRow());

      sLog->outInfo(LOG_FILTER_SERVER_LOADING,">> Caricate %u configurazioni",ConfCount);
      return true;

	} else {
			if (tipo>=ConfCount) return false;
			AzConf[tipo] = scelta;
			uint8 val;
			if (scelta) val=1; else val=0; // 1 true - 0 false
			Hw2Database.PQuery("UPDATE `a_rpg_conf` SET `MOD` = %u WHERE `ID` = %u",val,tipo);
			return true;
	}

 }

 return false;

}

void Hw2Class::RemoveCharFromDB(uint32 lowguid)
{
	Hw2Database.PExecute("DELETE FROM `a_tournament_punti` WHERE `guid`= '%u'",lowguid);
	Hw2Database.PExecute("DELETE FROM `a_rpg_players` WHERE `guid`= '%u'",lowguid);
	Hw2Database.PExecute("DELETE FROM `a_character_quests` WHERE `guid`= '%u'",lowguid);
}
