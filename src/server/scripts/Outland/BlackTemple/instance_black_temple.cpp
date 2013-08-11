/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Instance_Black_Temple
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Black Temple Scripts
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "black_temple.h"
#include "Player.h"

/* Black Temple encounters:
0 - High Warlord Naj'entus event
1 - Supremus Event
2 - Shade of Akama Event
3 - Teron Gorefiend Event
4 - Gurtogg Bloodboil Event
5 - Reliquary Of Souls Event
6 - Mother Shahraz Event
7 - Illidari Council Event
8 - Illidan Stormrage Event
*/

class instance_black_temple : public InstanceMapScript
{
public:
    instance_black_temple() : InstanceMapScript("instance_black_temple", 564) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_black_temple_InstanceMapScript(map);
    }

    struct instance_black_temple_InstanceMapScript : public InstanceScript
    {
        instance_black_temple_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[EncounterCount];
        std::string str_data;

        uint64 Najentus;
        uint64 Akama;                                           // This is the Akama that starts the Illidan encounter.
        uint64 Akama_Shade;                                     // This is the Akama that starts the Shade of Akama encounter.
        uint64 ShadeOfAkama;
        uint64 Supremus;
        uint64 LadyMalande;
        uint64 GathiosTheShatterer;
        uint64 HighNethermancerZerevor;
        uint64 VerasDarkshadow;
        uint64 IllidariCouncil;
        uint64 BloodElfCouncilVoice;
        uint64 IllidanStormrage;

        uint64 NajentusGate;
        uint64 MainTempleDoors;
        uint64 ShadeOfAkamaDoor;
        uint64 CommonDoor;//Teron
        uint64 TeronDoor;
        uint64 GuurtogDoor;
        uint64 MotherDoor;
        uint64 TempleDoor;//Befor mother
        uint64 CouncilDoor;
        uint64 SimpleDoor;//council
        uint64 IllidanGate;
        uint64 IllidanDoor[2];

        void Initialize() OVERRIDE
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            Najentus                = 0;
            Akama                   = 0;
            Akama_Shade             = 0;
            ShadeOfAkama            = 0;
            Supremus                = 0;
            LadyMalande             = 0;
            GathiosTheShatterer     = 0;
            HighNethermancerZerevor = 0;
            VerasDarkshadow         = 0;
            IllidariCouncil         = 0;
            BloodElfCouncilVoice    = 0;
            IllidanStormrage        = 0;

            NajentusGate            = 0;
            MainTempleDoors         = 0;
            ShadeOfAkamaDoor        = 0;
            CommonDoor              = 0; // teron
            TeronDoor               = 0;
            GuurtogDoor             = 0;
            MotherDoor              = 0;
            TempleDoor              = 0;
            SimpleDoor              = 0; // Bycouncil
            CouncilDoor             = 0;
            IllidanGate             = 0;
            IllidanDoor[0]          = 0;
            IllidanDoor[1]          = 0;
        }

        bool IsEncounterInProgress() const OVERRIDE
        {
            for (uint8 i = 0; i < EncounterCount; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        Player* GetPlayerInMap()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                        return player;
                }
            }

            TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Black Temple: GetPlayerInMap, but PlayerList is empty!");
            return NULL;
        }

        void OnCreatureCreate(Creature* creature) OVERRIDE
        {
            switch (creature->GetEntry())
            {
            case 22887:    Najentus = creature->GetGUID();                  break;
            case 23089:    Akama = creature->GetGUID();                     break;
            case 23191:    Akama_Shade = creature->GetGUID();               break;
            case 22841:    ShadeOfAkama = creature->GetGUID();              break;
            case 22898:    Supremus = creature->GetGUID();                  break;
            case 22917:    IllidanStormrage = creature->GetGUID();          break;
            case 22949:    GathiosTheShatterer = creature->GetGUID();       break;
            case 22950:    HighNethermancerZerevor = creature->GetGUID();   break;
            case 22951:    LadyMalande = creature->GetGUID();               break;
            case 22952:    VerasDarkshadow = creature->GetGUID();           break;
            case 23426:    IllidariCouncil = creature->GetGUID();           break;
            case 23499:    BloodElfCouncilVoice = creature->GetGUID();      break;
            }
        }

        void OnGameObjectCreate(GameObject* go) OVERRIDE
        {
            switch (go->GetEntry())
            {
            case 185483:
                NajentusGate = go->GetGUID(); // Gate past Naj'entus (at the entrance to Supermoose's courtyards)
                if (m_auiEncounter[0] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185882:
                MainTempleDoors = go->GetGUID(); // Main Temple Doors - right past Supermoose (Supremus)
                if (m_auiEncounter[1] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185478:
                ShadeOfAkamaDoor = go->GetGUID();
                break;

            case 185480:
                CommonDoor = go->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 186153:
                TeronDoor = go->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185892:
                GuurtogDoor = go->GetGUID();
                if (m_auiEncounter[4] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185479:
                TempleDoor = go->GetGUID();
                if (m_auiEncounter[5] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185482:
                MotherDoor = go->GetGUID();
                if (m_auiEncounter[6] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185481:
                CouncilDoor = go->GetGUID();
                if (m_auiEncounter[7] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 186152:
                SimpleDoor = go->GetGUID();
                if (m_auiEncounter[7] == DONE)
                    HandleGameObject(0, true, go);
                break;

            case 185905:
                IllidanGate = go->GetGUID(); // Gate leading to Temple Summit
                break;

            case 186261:
                IllidanDoor[0] = go->GetGUID(); // Right door at Temple Summit
                break;

            case 186262:
                IllidanDoor[1] = go->GetGUID(); // Left door at Temple Summit
                break;
            }
        }

        uint64 GetData64(uint32 identifier) const OVERRIDE
        {
            switch (identifier)
            {
            case DATA_HIGHWARLORDNAJENTUS:         return Najentus;
            case DATA_AKAMA:                       return Akama;
            case DATA_AKAMA_SHADE:                 return Akama_Shade;
            case DATA_SHADEOFAKAMA:                return ShadeOfAkama;
            case DATA_SUPREMUS:                    return Supremus;
            case DATA_ILLIDANSTORMRAGE:            return IllidanStormrage;
            case DATA_GATHIOSTHESHATTERER:         return GathiosTheShatterer;
            case DATA_HIGHNETHERMANCERZEREVOR:     return HighNethermancerZerevor;
            case DATA_LADYMALANDE:                 return LadyMalande;
            case DATA_VERASDARKSHADOW:             return VerasDarkshadow;
            case DATA_ILLIDARICOUNCIL:             return IllidariCouncil;
            case DATA_GAMEOBJECT_NAJENTUS_GATE:    return NajentusGate;
            case DATA_GAMEOBJECT_ILLIDAN_GATE:     return IllidanGate;
            case DATA_GAMEOBJECT_ILLIDAN_DOOR_R:   return IllidanDoor[0];
            case DATA_GAMEOBJECT_ILLIDAN_DOOR_L:   return IllidanDoor[1];
            case DATA_GAMEOBJECT_SUPREMUS_DOORS:   return MainTempleDoors;
            case DATA_BLOOD_ELF_COUNCIL_VOICE:     return BloodElfCouncilVoice;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data) OVERRIDE
        {
            switch (type)
            {
            case DATA_HIGHWARLORDNAJENTUSEVENT:
                if (data == DONE)
                    HandleGameObject(NajentusGate, true);
                m_auiEncounter[0] = data;
                break;
            case DATA_SUPREMUSEVENT:
                if (data == DONE)
                    HandleGameObject(NajentusGate, true);
                m_auiEncounter[1] = data;
                break;
            case DATA_SHADEOFAKAMAEVENT:
                if (data == IN_PROGRESS)
                    HandleGameObject(ShadeOfAkamaDoor, false);
                else
                    HandleGameObject(ShadeOfAkamaDoor, true);
                m_auiEncounter[2] = data;
                break;
            case DATA_TERONGOREFIENDEVENT:
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(TeronDoor, false);
                    HandleGameObject(CommonDoor, false);
                }
                else
                {
                    HandleGameObject(TeronDoor, true);
                    HandleGameObject(CommonDoor, true);
                }
                m_auiEncounter[3] = data;
                break;
            case DATA_GURTOGGBLOODBOILEVENT:
                if (data == DONE)
                    HandleGameObject(GuurtogDoor, true);
                m_auiEncounter[4] = data;
                break;
            case DATA_RELIQUARYOFSOULSEVENT:
                if (data == DONE)
                    HandleGameObject(TempleDoor, true);
                m_auiEncounter[5] = data;
                break;
            case DATA_MOTHERSHAHRAZEVENT:
                if (data == DONE)
                    HandleGameObject(MotherDoor, true);
                m_auiEncounter[6] = data;
                break;
            case DATA_ILLIDARICOUNCILEVENT:
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(CouncilDoor, false);
                    HandleGameObject(SimpleDoor, false);
                }
                else
                {
                    HandleGameObject(CouncilDoor, true);
                    HandleGameObject(SimpleDoor, true);
                }
                m_auiEncounter[7] = data;
                break;
            case DATA_ILLIDANSTORMRAGEEVENT:
                m_auiEncounter[8] = data;
                break;
            }

            if (data == DONE)
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
                    << m_auiEncounter[2] << ' ' << m_auiEncounter[3] << ' ' << m_auiEncounter[4]
                << ' ' << m_auiEncounter[5] << ' ' << m_auiEncounter[6] << ' ' << m_auiEncounter[7]
                << ' ' << m_auiEncounter[8];

                str_data = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
            }
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            switch (type)
            {
            case DATA_HIGHWARLORDNAJENTUSEVENT:         return m_auiEncounter[0];
            case DATA_SUPREMUSEVENT:                    return m_auiEncounter[1];
            case DATA_SHADEOFAKAMAEVENT:                return m_auiEncounter[2];
            case DATA_TERONGOREFIENDEVENT:              return m_auiEncounter[3];
            case DATA_GURTOGGBLOODBOILEVENT:            return m_auiEncounter[4];
            case DATA_RELIQUARYOFSOULSEVENT:            return m_auiEncounter[5];
            case DATA_MOTHERSHAHRAZEVENT:               return m_auiEncounter[6];
            case DATA_ILLIDARICOUNCILEVENT:             return m_auiEncounter[7];
            case DATA_ILLIDANSTORMRAGEEVENT:            return m_auiEncounter[8];
            }

            return 0;
        }

       std::string GetSaveData() OVERRIDE
        {
            return str_data;
        }

        void Load(const char* in) OVERRIDE
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            std::istringstream loadStream(in);
            loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2]
            >> m_auiEncounter[3] >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6]
            >> m_auiEncounter[7] >> m_auiEncounter[8];

            for (uint8 i = 0; i < EncounterCount; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_black_temple()
{
    new instance_black_temple();
}
