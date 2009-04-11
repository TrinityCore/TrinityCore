#include "precompiled.h"
#include "def_keep.h"

struct TRINITY_DLL_DECL instance_keep : public ScriptedInstance
{
   instance_keep(Map *Map) : ScriptedInstance(Map) {Initialize();};
	
	uint64 Skarvald,
		   Skarvald_ghost,
		   Dalronn,
		   Dalronn_ghost,
		   Annhylde_thr_caller,
		   Ingvar,
		   Ingvar_undead;
   bool   IsBossDied[2];
		   
   void Initialize()
   {
		Skarvald = 0;
		Skarvald_ghost = 0;
		Dalronn =0;
		Dalronn_ghost =0;
		Annhylde_thr_caller =0;
		Ingvar =0;
		Ingvar_undead =0;
		IsBossDied[0] = false;
		IsBossDied[1] = false;
	}

	bool IsEncounterInProgress() const
   {
       //not active
       return false;
   }

   void OnCreatureCreate(Creature *creature, uint32 creature_entry)
   {
       switch(creature->GetEntry())
       { 
           case 24200:    Dalronn = creature->GetGUID();               break;
           case 27389:    Dalronn_ghost = creature->GetGUID();         break;
           case 24201:    Skarvald = creature->GetGUID();             break;
           case 27390:    Skarvald_ghost = creature->GetGUID();       break;
           case 24068:    Annhylde_thr_caller = creature->GetGUID();  break;
           case 23954:    Ingvar = creature->GetGUID();               break;
           case 23980:    Ingvar_undead = creature->GetGUID();        break;
       }
   }

   uint32 GetData(uint32 type)
   {
       switch(type)
       {
           case DATA_SKARVALDDEAD:
               if(IsBossDied[0])
                   return 1;
               break;
           case DATA_DALRONDEAD:
               if(IsBossDied[1])
                   return 1;
               break;
       }

       return 0;
   }

   uint64 GetData64 (uint32 identifier)
   {
       return 0;
   }

   void SetData(uint32 type, uint32 data)
   {
       switch(type)
       {
           case DATA_SKARVALD_DEATH:
               IsBossDied[0] = true;
               break;
           case DATA_DALRON_DEATH:
               IsBossDied[0] = true;
               break;
       }
   }
};

InstanceData* GetInstanceData_instance_keep(Map* map)
{
   return new instance_keep(map);
}

void AddSC_instance_keep()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_keep";
   newscript->GetInstanceData = GetInstanceData_instance_keep;
   newscript->RegisterSelf();
}
