/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_GNOMEREGAN_H
#define DEF_GNOMEREGAN_H

enum
{
    MAX_GNOME_FACES             = 6,
    MAX_EXPLOSIVES_PER_SIDE     = 2,

    TYPE_GRUBBIS                = 0,
    TYPE_THERMAPLUGG            = 1,
    TYPE_EXPLOSIVE_CHARGE       = 2,
    INSTANCE_GNOMEREGAN_MAX_ENCOUNTER = 2,                        // Only Grubbis and Thermaplugg need treatment

    DATA_EXPLOSIVE_CHARGE_1     = 1,
    DATA_EXPLOSIVE_CHARGE_2     = 2,
    DATA_EXPLOSIVE_CHARGE_3     = 3,
    DATA_EXPLOSIVE_CHARGE_4     = 4,
    DATA_EXPLOSIVE_CHARGE_USE   = 5,

    NPC_BLASTMASTER_SHORTFUSE   = 7998,
    NPC_ALARM_A_BOMB_2600       = 7897,

    GO_RED_ROCKET               = 103820,
    GO_CAVE_IN_NORTH            = 146085,
    GO_CAVE_IN_SOUTH            = 146086,
    GO_EXPLOSIVE_CHARGE         = 144065,
    GO_THE_FINAL_CHAMBER        = 142207,

    GO_GNOME_FACE_1             = 142211,
    GO_GNOME_FACE_2             = 142210,
    GO_GNOME_FACE_3             = 142209,
    GO_GNOME_FACE_4             = 142208,
    GO_GNOME_FACE_5             = 142213,
    GO_GNOME_FACE_6             = 142212,

    GO_BUTTON_1                 = 142214,
    GO_BUTTON_2                 = 142215,
    GO_BUTTON_3                 = 142216,
    GO_BUTTON_4                 = 142217,
    GO_BUTTON_5                 = 142218,
    GO_BUTTON_6                 = 142219
};

struct sBombFace
{
    uint64 m_uiGnomeFaceGUID;
    bool m_bActivated;
    uint32 m_uiBombTimer;
};

class instance_gnomeregan : public ScriptedInstance
{
    public:
        instance_gnomeregan(Map* pMap);
        ~instance_gnomeregan() override {}

        void Initialize() override;

        void OnCreatureCreate(Creature* pCreature) override;
        void OnObjectCreate(GameObject* pGo) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        uint32 GetData(uint32 uiType) override;
        uint64 GetData64(uint32 uiData) override;

        sBombFace* GetBombFaces();
        void DoActivateBombFace(uint8 uiIndex);
        void DoDeactivateBombFace(uint8 uiIndex);

        char const* Save() override { return strInstData.c_str(); }
        void Load(char const* chrIn) override;

    protected:
        uint32 m_auiEncounter[INSTANCE_GNOMEREGAN_MAX_ENCOUNTER];
        std::string strInstData;

        sBombFace m_asBombFaces[MAX_GNOME_FACES];
        uint64 m_auiExplosiveSortedGUIDs[2][MAX_EXPLOSIVES_PER_SIDE];

        uint64 m_uiBlastmasterShortfuseGUID;
        uint64 m_uiAlarmABomb2600GUID;
        uint64 m_uiCaveInNorthGUID;
        uint64 m_uiCaveInSouthGUID;
        uint64 m_uiDoorFinalChamberGUID;

        std::list<GameObject*> m_lExplosiveCharges;
        std::list<uint64> m_luiSpawnedExplosiveChargeGUIDs;
        std::list<uint64> m_lRedRocketGUIDs;
};

#endif
