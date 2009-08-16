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

#define MAX_ENCOUNTER 6

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
    instance_sunwell_plateau(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];

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
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

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

        /*** Misc ***/
        SpectralRealmTimer = 5000;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
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

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 24850: Kalecgos_Dragon     = pCreature->GetGUID(); break;
            case 24891: Kalecgos_Human      = pCreature->GetGUID(); break;
            case 24892: Sathrovarr          = pCreature->GetGUID(); break;
            case 24882: Brutallus           = pCreature->GetGUID(); break;
            case 24895: Madrigosa           = pCreature->GetGUID(); break;
            case 25038: Felmyst             = pCreature->GetGUID(); break;
            case 25166: Alythess            = pCreature->GetGUID(); break;
            case 25165: Sacrolash           = pCreature->GetGUID(); break;
            case 25741: Muru                = pCreature->GetGUID(); break;
            case 25315: KilJaeden           = pCreature->GetGUID(); break;
            case 25608: KilJaedenController = pCreature->GetGUID(); break;
            case 26046: Anveena             = pCreature->GetGUID(); break;
            case 25319: KalecgosKJ          = pCreature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 188421: ForceField     = pGo->GetGUID(); break;
            case 188075:
                if (m_auiEncounter[2] == DONE)
                    HandleGameObject(NULL, true, pGo);
                FireBarrier = pGo->GetGUID();
                break;
            case 187990: MurusGate[0]   = pGo->GetGUID(); break;
            case 188118:
                if (m_auiEncounter[4] == DONE)
                    HandleGameObject(NULL, true, pGo);
                MurusGate[1]= pGo->GetGUID();
                break;
        }
    }

    uint32 GetData(uint32 id)
    {
        switch(id)
        {
            case DATA_KALECGOS_EVENT:     return m_auiEncounter[0];
            case DATA_BRUTALLUS_EVENT:    return m_auiEncounter[1];
            case DATA_FELMYST_EVENT:      return m_auiEncounter[2];
            case DATA_EREDAR_TWINS_EVENT: return m_auiEncounter[3];
            case DATA_MURU_EVENT:         return m_auiEncounter[4];
            case DATA_KILJAEDEN_EVENT:    return m_auiEncounter[5];
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
            case DATA_KALECGOS_EVENT:      m_auiEncounter[0] = data; break;
            case DATA_BRUTALLUS_EVENT:     m_auiEncounter[1] = data; break;
            case DATA_FELMYST_EVENT:
                if (data == DONE)
                    HandleGameObject(FireBarrier, true);
                m_auiEncounter[2] = data; break;
            case DATA_EREDAR_TWINS_EVENT:  m_auiEncounter[3] = data; break;
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
                m_auiEncounter[4] = data; break;
            case DATA_KILJAEDEN_EVENT:     m_auiEncounter[5] = data; break;
        }

        if (data == DONE)
            SaveToDB();
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream stream;
        stream << m_auiEncounter[0] << " "  << m_auiEncounter[1] << " "  << m_auiEncounter[2] << " "  << m_auiEncounter[3] << " "
            << m_auiEncounter[4] << " "  << m_auiEncounter[5];
        char* out = new char[stream.str().length() + 1];
        strcpy(out, stream.str().c_str());
        if (out)
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
        std::istringstream stream(in);
        stream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
            >> m_auiEncounter[4] >> m_auiEncounter[5];
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                m_auiEncounter[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_sunwell_plateau(Map* pMap)
{
    return new instance_sunwell_plateau(pMap);
}

void AddSC_instance_sunwell_plateau()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "instance_sunwell_plateau";
    newscript->GetInstanceData = &GetInstanceData_instance_sunwell_plateau;
    newscript->RegisterSelf();
}

