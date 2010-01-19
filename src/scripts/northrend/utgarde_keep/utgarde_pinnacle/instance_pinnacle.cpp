#include "ScriptedPch.h"
#include "utgarde_pinnacle.h"

#define MAX_ENCOUNTER     4

/* Utgarde Pinnacle encounters:
0 - Svala Sorrowgrave
1 - Gortok Palehoof
2 - Skadi the Ruthless
3 - King Ymiron
*/

#define ENTRY_SKADI_THE_RUTHLESS_DOOR      192173
#define ENTRY_KING_YMIRON_DOOR             192174
#define ENTRY_GORK_PALEHOOF_SPHERE         188593

struct TRINITY_DLL_DECL instance_pinnacle : public ScriptedInstance
{
    instance_pinnacle(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiSvalaSorrowgrave;
    uint64 uiGortokPalehoof;
    uint64 uiSkadiTheRuthless;
    uint64 uiKingYmiron;

    uint64 uiSkadiTheRuthlessDoor;
    uint64 uiKingYmironDoor;
    uint64 uiGortokPalehoofSphere;

    uint64 uiFrenziedWorgen;
    uint64 uiRavenousFurbolg;
    uint64 uiFerociousRhino;
    uint64 uiMassiveJormungar;
    uint64 uiPalehoofOrb;

    uint64 uiSvala;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    std::string str_data;

    void Initialize()
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
           m_auiEncounter[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 26668:    uiSvalaSorrowgrave = pCreature->GetGUID();               break;
            case 26687:    uiGortokPalehoof = pCreature->GetGUID();                 break;
            case 26693:    uiSkadiTheRuthless = pCreature->GetGUID();               break;
            case 26861:    uiKingYmiron = pCreature->GetGUID();                     break;
            case 26683:    uiFrenziedWorgen = pCreature->GetGUID();                 break;
            case 26684:    uiRavenousFurbolg = pCreature->GetGUID();                break;
            case 26685:    uiMassiveJormungar = pCreature->GetGUID();               break;
            case 26686:    uiFerociousRhino = pCreature->GetGUID();                 break;
            case 29281:    uiSvala = pCreature->GetGUID();                          break;
            case 26688:    uiPalehoofOrb = pCreature->GetGUID();                    break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case ENTRY_SKADI_THE_RUTHLESS_DOOR:
                uiSkadiTheRuthlessDoor = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE) HandleGameObject(NULL,true,pGo);
                break;
            case ENTRY_KING_YMIRON_DOOR:
                uiKingYmironDoor = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE) HandleGameObject(NULL,true,pGo);
                break;
            case ENTRY_GORK_PALEHOOF_SPHERE:
                uiGortokPalehoofSphere = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                {
                    HandleGameObject(NULL,true,pGo);
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_SVALA_SORROWGRAVE_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_GORTOK_PALEHOOF_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_SKADI_THE_RUTHLESS_EVENT:
                if (data == DONE)
                    HandleGameObject(uiSkadiTheRuthlessDoor,true);
                m_auiEncounter[2] = data;
                break;
            case DATA_KING_YMIRON_EVENT:
                if (data == DONE)
                    HandleGameObject(uiKingYmironDoor,true);
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_SVALA_SORROWGRAVE_EVENT:        return m_auiEncounter[0];
            case DATA_GORTOK_PALEHOOF_EVENT:          return m_auiEncounter[1];
            case DATA_SKADI_THE_RUTHLESS_EVENT:       return m_auiEncounter[2];
            case DATA_KING_YMIRON_EVENT:              return m_auiEncounter[3];
        }
        return 0;
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_SVALA_SORROWGRAVE:      return uiSvalaSorrowgrave;
            case DATA_GORTOK_PALEHOOF:        return uiGortokPalehoof;
            case DATA_SKADI_THE_RUTHLESS:     return uiSkadiTheRuthless;
            case DATA_KING_YMIRON:            return uiKingYmiron;
            case DATA_MOB_FRENZIED_WORGEN:    return uiFrenziedWorgen;
            case DATA_MOB_RAVENOUS_FURBOLG:   return uiRavenousFurbolg;
            case DATA_MOB_MASSIVE_JORMUNGAR:  return uiMassiveJormungar;
            case DATA_MOB_FEROCIOUS_RHINO:    return uiFerociousRhino;
            case DATA_MOB_ORB:                return uiPalehoofOrb;
            case DATA_SVALA:                  return uiSvala;
            case DATA_GORTOK_PALEHOOF_SPHERE: return uiGortokPalehoofSphere;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "U P " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3];

        str_data = saveStream.str();

        OUT_SAVE_INST_DATA_COMPLETE;
        return str_data;
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);

        char dataHead1, dataHead2;
        uint16 data0, data1, data2, data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'U' && dataHead2 == 'K')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_utgarde_pinnacle(Map* pMap)
{
    return new instance_pinnacle(pMap);
}

void AddSC_instance_utgarde_pinnacle()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_utgarde_pinnacle";
    newscript->GetInstanceData = &GetInstanceData_instance_utgarde_pinnacle;
    newscript->RegisterSelf();
}
