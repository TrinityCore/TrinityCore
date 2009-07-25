/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

/* ScriptData
SDName: Instance_Sunwell_Plateau
SD%Complete: 25
SDComment: VERIFY SCRIPT
SDCategory: Sunwell_Plateau
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"

#define ENCOUNTERS 6

/* Sunwell Plateau:
0 - Kalecgos and Sathrovarr
1 - Brutallus
2 - Felmyst
3 - Eredar Twins (Alythess and Sacrolash)
4 - M'uru
5 - Kil'Jaeden
*/

struct TRINITY_DLL_DECL instance_sunwell_plateau : public ScriptedInstance
{
    instance_sunwell_plateau(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounters[ENCOUNTERS];

    /** Creatures **/
    uint64 Kalecgos_Dragon;
    uint64 Kalecgos_Human;
    uint64 Sathrovarr;
    uint64 Brutallus;
    uint64 Madrigosa;
    uint64 Felmyst;
    uint64 Alythess;
    uint64 Sacrolash;
    uint64 Muru;
    uint64 KilJaeden;
    uint64 KilJaedenController;
    uint64 Anveena;
    uint64 KalecgosKJ;

    /** GameObjects **/
    uint64 ForceField;                                      // Kalecgos Encounter
    uint64 FireBarrier;                                     // Felmysts Encounter
    uint64 MurusGate[2];                                    // Murus Encounter

    /*** Misc ***/
    uint32 SpectralRealmTimer;
    std::vector<uint64> SpectralRealmList;

    void Initialize()
    {
        /*** Creatures ***/
        Kalecgos_Dragon         = 0;
        Kalecgos_Human          = 0;
        Sathrovarr              = 0;
        Brutallus               = 0;
        Madrigosa               = 0;
        Felmyst                 = 0;
        Alythess                = 0;
        Sacrolash               = 0;
        Muru                    = 0;
        KilJaeden               = 0;
        KilJaedenController     = 0;
        Anveena                 = 0;
        KalecgosKJ              = 0;

        /*** GameObjects ***/
        ForceField  = 0;
        FireBarrier = 0;
        MurusGate[0] = 0;
        MurusGate[1] = 0;

        /*** Encounters ***/
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;

        /*** Misc ***/
        SpectralRealmTimer = 5000;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS)
                return true;

        return false;
    }

    Player* GetPlayerInMap()
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                Player* plr = itr->getSource();
                if (plr && !plr->HasAura(45839,0))
                        return plr;
            }
        }

        debug_log("TSCR: Instance Sunwell Plateau: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 24850: Kalecgos_Dragon     = creature->GetGUID(); break;
            case 24891: Kalecgos_Human      = creature->GetGUID(); break;
            case 24892: Sathrovarr          = creature->GetGUID(); break;
            case 24882: Brutallus           = creature->GetGUID(); break;
            case 24895: Madrigosa           = creature->GetGUID(); break;
            case 25038: Felmyst             = creature->GetGUID(); break;
            case 25166: Alythess            = creature->GetGUID(); break;
            case 25165: Sacrolash           = creature->GetGUID(); break;
            case 25741: Muru                = creature->GetGUID(); break;
            case 25315: KilJaeden           = creature->GetGUID(); break;
            case 25608: KilJaedenController = creature->GetGUID(); break;
            case 26046: Anveena             = creature->GetGUID(); break;
            case 25319: KalecgosKJ          = creature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
            case 188421: ForceField     = go->GetGUID(); break;
            case 188075:
                if(Encounters[2] == DONE)
                    HandleGameObject(NULL, true, go);
                FireBarrier = go->GetGUID();
                break;
            case 187990: MurusGate[0]   = go->GetGUID(); break;
            case 188118:
                if(Encounters[4] == DONE)
                    HandleGameObject(NULL, true, go);
                MurusGate[1]= go->GetGUID();
                break;
        }
    }

    uint32 GetData(uint32 id)
    {
        switch(id)
        {
            case DATA_KALECGOS_EVENT:     return Encounters[0];
            case DATA_BRUTALLUS_EVENT:    return Encounters[1];
            case DATA_FELMYST_EVENT:      return Encounters[2];
            case DATA_EREDAR_TWINS_EVENT: return Encounters[3];
            case DATA_MURU_EVENT:         return Encounters[4];
            case DATA_KILJAEDEN_EVENT:    return Encounters[5];
        }
        return 0;
    }

    uint64 GetData64(uint32 id)
    {
        switch(id)
        {
            case DATA_KALECGOS_DRAGON:      return Kalecgos_Dragon;
            case DATA_KALECGOS_HUMAN:       return Kalecgos_Human;
            case DATA_SATHROVARR:           return Sathrovarr;
            case DATA_GO_FORCEFIELD:        return ForceField;
            case DATA_BRUTALLUS:            return Brutallus;
            case DATA_MADRIGOSA:            return Madrigosa;
            case DATA_FELMYST:              return Felmyst;
            case DATA_ALYTHESS:             return Alythess;
            case DATA_SACROLASH:            return Sacrolash;
            case DATA_MURU:                 return Muru;
            case DATA_KILJAEDEN:            return KilJaeden;
            case DATA_KILJAEDEN_CONTROLLER: return KilJaedenController;
            case DATA_ANVEENA:              return Anveena;
            case DATA_KALECGOS_KJ:          return KalecgosKJ;
            case DATA_PLAYER_GUID:
                Player* Target = GetPlayerInMap();
                return Target->GetGUID();
        }
        return 0;
    }

    void SetData(uint32 id, uint32 data)
    {
        switch(id)
        {
            case DATA_KALECGOS_EVENT:      Encounters[0] = data; break;
            case DATA_BRUTALLUS_EVENT:     Encounters[1] = data; break;
            case DATA_FELMYST_EVENT:
                if(data == DONE)
                    HandleGameObject(FireBarrier, true);
                Encounters[2] = data; break;
            case DATA_EREDAR_TWINS_EVENT:  Encounters[3] = data; break;
            case DATA_MURU_EVENT:
                switch(data)
                {
                    case DONE:
                        HandleGameObject(MurusGate[0], true);
                        HandleGameObject(MurusGate[1], true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(MurusGate[0], false);
                        HandleGameObject(MurusGate[1], false);
                        break;
                    case NOT_STARTED:
                        HandleGameObject(MurusGate[0], true);
                        HandleGameObject(MurusGate[1], false);
                        break;
                }
                Encounters[4] = data; break;
            case DATA_KILJAEDEN_EVENT:     Encounters[5] = data; break;
        }

        if(data == DONE)
            SaveToDB();
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream stream;
        stream << Encounters[0] << " "  << Encounters[1] << " "  << Encounters[2] << " "  << Encounters[3] << " "
            << Encounters[4] << " "  << Encounters[5];
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
        if(!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);
        std::istringstream stream(in);
        stream >> Encounters[0] >> Encounters[1] >> Encounters[2] >> Encounters[3]
            >> Encounters[4] >> Encounters[5];
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                Encounters[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_sunwell_plateau(Map* map)
{
    return new instance_sunwell_plateau(map);
}

void AddSC_instance_sunwell_plateau()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "instance_sunwell_plateau";
    newscript->GetInstanceData = &GetInstanceData_instance_sunwell_plateau;
    newscript->RegisterSelf();
}

