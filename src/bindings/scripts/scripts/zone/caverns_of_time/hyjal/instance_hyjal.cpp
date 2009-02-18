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
SDName: Instance_Mount_Hyjal
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Hyjal Scripts
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "def_hyjal.h"

#define ENCOUNTERS     5

/* Battle of Mount Hyjal encounters:
0 - Rage Winterchill event
1 - Anetheron event
2 - Kaz'rogal event
3 - Azgalor event
4 - Archimonde event
*/

struct TRINITY_DLL_DECL instance_mount_hyjal : public ScriptedInstance
{
    instance_mount_hyjal(Map *map) : ScriptedInstance(map) {Initialize();};

    uint64 RageWinterchill;
    uint64 Anetheron;
    uint64 Kazrogal;
    uint64 Azgalor;
    uint64 Archimonde;
    uint64 JainaProudmoore;
    uint64 Thrall;
    uint64 TyrandeWhisperwind;

    uint32 Trash;
    uint32 Encounters[ENCOUNTERS];

    void Initialize()
    {
        RageWinterchill = 0;
        Anetheron = 0;
        Kazrogal = 0;
        Azgalor = 0;
        Archimonde = 0;
        JainaProudmoore = 0;
        Thrall = 0;
        TyrandeWhisperwind = 0;

        Trash = 0;
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 17767: RageWinterchill = creature->GetGUID(); break;
            case 17808: Anetheron = creature->GetGUID(); break;
            case 17888: Kazrogal = creature->GetGUID();  break;
            case 17842: Azgalor = creature->GetGUID(); break;
            case 17968: Archimonde = creature->GetGUID(); break;
            case 17772: JainaProudmoore = creature->GetGUID(); break;
            case 17852: Thrall = creature->GetGUID(); break;
            case 17948: TyrandeWhisperwind = creature->GetGUID(); break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_RAGEWINTERCHILL: return RageWinterchill;
            case DATA_ANETHERON: return Anetheron;
            case DATA_KAZROGAL: return Kazrogal;
            case DATA_AZGALOR: return Azgalor;
            case DATA_ARCHIMONDE: return Archimonde;
            case DATA_JAINAPROUDMOORE: return JainaProudmoore;
            case DATA_THRALL: return Thrall;
            case DATA_TYRANDEWHISPERWIND: return TyrandeWhisperwind;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_RAGEWINTERCHILLEVENT: Encounters[0] = data; break;
            case DATA_ANETHERONEVENT:       Encounters[1] = data; break;
            case DATA_KAZROGALEVENT:        Encounters[2] = data; break;
            case DATA_AZGALOREVENT:         Encounters[3] = data; break;
            case DATA_ARCHIMONDEEVENT:      Encounters[4] = data; break;
            case DATA_RESET_TRASH_COUNT:    Trash = 0;            break;

            case DATA_TRASH:
                if(data) Trash = data;
                else     Trash--;
                UpdateWorldState(WORLD_STATE_ENEMYCOUNT, Trash);
                break;
        }

         debug_log("SD2: Instance Hyjal: Instance data updated for event %u (Data=%u)",type,data);

        if(data == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_RAGEWINTERCHILLEVENT: return Encounters[0];
            case DATA_ANETHERONEVENT:      return Encounters[1];
            case DATA_KAZROGALEVENT:       return Encounters[2];
            case DATA_AZGALOREVENT:        return Encounters[3];
            case DATA_ARCHIMONDEEVENT:     return Encounters[4];
            case DATA_TRASH:               return Trash;
        }
        return 0;
    }

    void UpdateWorldState(uint32 id, uint32 state)
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
                for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->getSource())
                        player->SendUpdateWorldState(id,state);
                }
        }else debug_log("TSCR: Instance Hyjal: UpdateWorldState, but PlayerList is empty!");
    }

    const char* Save()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream stream;
        stream << Encounters[0] << " " << Encounters[1] << " " << Encounters[2] << " "
            << Encounters[3] << " " << Encounters[4];
        char* out = new char[stream.str().length() + 1];
        strcpy(out, stream.str().c_str());
        if(out)
        {
            OUT_SAVE_INST_DATA_COMPLETE;
            return out;
        }

        return NULL;
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);
        std::istringstream loadStream;
        loadStream.str(in);
        loadStream >> Encounters[0] >> Encounters[1] >> Encounters[2] >> Encounters[3] >> Encounters[4];
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS)                // Do not load an encounter as IN_PROGRESS - reset it instead.
                Encounters[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_mount_hyjal(Map* map)
{
    return new instance_mount_hyjal(map);
}

void AddSC_instance_mount_hyjal()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_hyjal";
    newscript->GetInstanceData = &GetInstanceData_instance_mount_hyjal;
    newscript->RegisterSelf();
}

