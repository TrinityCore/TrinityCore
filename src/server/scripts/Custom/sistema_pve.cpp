#include "ScriptPCH.h"
#include "Player.h"
#include "GroupMgr.h"

class sistema_pve : public PlayerScript
{
  public:
    sistema_pve() : PlayerScript("sistema_pve") { }

  void OnCreatureKill(Player * killer, Creature* killed)
  {
	Group* group = killer->GetGroup();

	if(!group) return;
	
	for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
	{
		Player* player = itr->GetSource();
		if (!player || !player->GetSession() || !player->IsInRange(killed,0,300))
            continue;
		std::ostringstream query;
		query << "SELECT currency_type,currency_amount FROM currency_system WHERE entry=" << killed->GetEntry() << std::endl;
		std::string query_str = query.str();
		QueryResult result = WorldDatabase.Query(query_str.c_str());
		if (!result) return;
		Field * fields = NULL;
		do{
		fields = result->Fetch();
		uint16 currency_type = fields[0].GetUInt16();
		uint16 currency_amount = fields[1].GetUInt16();
		player->ModifyCurrency(currency_type, currency_amount,true,true);
		}while(result->NextRow());
	}
  }
};




void AddSC_sistema_pve()
{
new sistema_pve();
}
