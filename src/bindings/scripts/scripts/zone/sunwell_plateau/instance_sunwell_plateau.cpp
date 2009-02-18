/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

/* ScriptData
SDName: Instance_Sunwell_Plateau
SD%Complete: 0
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

    /** GameObjects **/
    uint64 ForceField;                                      // Kalecgos Encounter
    uint64 FireBarrier;                                     // Brutallus Encounter
    uint64 Gate[5];                                         // Rename this to be more specific after door placement is verified.

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

        /*** GameObjects ***/
        ForceField  = 0;
        FireBarrier = 0;
        Gate[0]     = 0;                                    // TODO: Rename Gate[n] with gate_<boss name> for better specificity
        Gate[1]     = 0;
        Gate[2]     = 0;
        Gate[3]     = 0;
        Gate[4]     = 0;

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

    void OnCreatureCreate(Creature* creature, uint32 entry)
    {
        switch(entry)
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
        }
    }

    void OnObjectCreate(GameObject* gobj)
    {
        switch(gobj->GetEntry())
        {
            case 188421: ForceField     = gobj->GetGUID(); break;
            case 188075: FireBarrier    = gobj->GetGUID(); break;
            case 187979: Gate[0]        = gobj->GetGUID(); break;
            case 187770: Gate[1]        = gobj->GetGUID(); break;
            case 187896: Gate[2]        = gobj->GetGUID(); break;
            case 187990: Gate[3]        = gobj->GetGUID(); break;
            case 188118: Gate[4]        = gobj->GetGUID(); break;
        }
    }

    uint32 GetData(uint32 id)
    {
        switch(id)
        {
            case DATA_KALECGOS_EVENT:     return Encounters[0]; break;
            case DATA_BRUTALLUS_EVENT:    return Encounters[1]; break;
            case DATA_FELMYST_EVENT:      return Encounters[2]; break;
            case DATA_EREDAR_TWINS_EVENT: return Encounters[3]; break;
            case DATA_MURU_EVENT:         return Encounters[4]; break;
            case DATA_KILJAEDEN_EVENT:    return Encounters[5]; break;
        }

        return 0;
    }

    uint64 GetData64(uint32 id)
    {
        switch(id)
        {
            case DATA_KALECGOS_DRAGON:      return Kalecgos_Dragon;     break;
            case DATA_KALECGOS_HUMAN:       return Kalecgos_Human;      break;
            case DATA_SATHROVARR:           return Sathrovarr;          break;
            case DATA_BRUTALLUS:            return Brutallus;           break;
            case DATA_MADRIGOSA:            return Madrigosa;           break;
            case DATA_FELMYST:              return Felmyst;             break;
            case DATA_ALYTHESS:             return Alythess;            break;
            case DATA_SACROLASH:            return Sacrolash;           break;
            case DATA_MURU:                 return Muru;                break;
            case DATA_KILJAEDEN:            return KilJaeden;           break;
            case DATA_KILJAEDEN_CONTROLLER: return KilJaedenController; break;
            case DATA_ANVEENA:              return Anveena;             break;
        }

        return 0;
    }

    void SetData(uint32 id, uint32 data)
    {
        switch(id)
        {
            case DATA_KALECGOS_EVENT:      Encounters[0] = data; break;
            case DATA_BRUTALLUS_EVENT:     Encounters[1] = data; break;
            case DATA_FELMYST_EVENT:       Encounters[2] = data; break;
            case DATA_EREDAR_TWINS_EVENT:  Encounters[3] = data; break;
            case DATA_MURU_EVENT:          Encounters[4] = data; break;
            case DATA_KILJAEDEN_EVENT:     Encounters[5] = data; break;
        }
    }

    void SetData64(uint32 id, uint64 guid)
    {
    }

    void Update(uint32 diff)
    {
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

