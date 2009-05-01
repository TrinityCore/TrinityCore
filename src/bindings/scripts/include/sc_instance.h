/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_INSTANCE_H
#define SC_INSTANCE_H

#include "InstanceData.h"
#include "Map.h"

#define OUT_SAVE_INST_DATA             debug_log("TSCR: Saving Instance Data for Instance %s (Map %d, Instance Id %d)", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_SAVE_INST_DATA_COMPLETE    debug_log("TSCR: Saving Instance Data for Instance %s (Map %d, Instance Id %d) completed.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA(a)          debug_log("TSCR: Loading Instance Data for Instance %s (Map %d, Instance Id %d). Input is '%s'", instance->GetMapName(), instance->GetId(), instance->GetInstanceId(), a)
#define OUT_LOAD_INST_DATA_COMPLETE    debug_log("TSCR: Instance Data Load for Instance %s (Map %d, Instance Id: %d) is complete.",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA_FAIL        error_log("TSCR: Unable to load Instance Data for Instance %s (Map %d, Instance Id: %d).",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())

class TRINITY_DLL_DECL ScriptedInstance : public InstanceData
{
    public:

        ScriptedInstance(Map *map) : InstanceData(map) {}
        ~ScriptedInstance() {}

        //All-purpose data storage 64 bit
        virtual uint64 GetData64(uint32 Data) { return 0; }
        virtual void SetData64(uint32 Data, uint64 Value) { }

        // Called every instance update
        virtual void Update(uint32) {}

        // Save and Load instance data to the database
        const char* Save() { return NULL; }
        void Load(const char* in) { }
};

#endif

