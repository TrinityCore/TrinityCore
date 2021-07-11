/* This file is part of the ScriptDev2 Project. See AUTHORS file for Copyright information
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_RFK_H
#define DEF_RFK_H

enum
{
    RFK_MAX_ENCOUNTER     = 1,

    TYPE_AGATHELOS    = 1,

    GO_AGATHELOS_WARD = 21099,

    NPC_WARD_KEEPER   = 4625,
    NPC_AGATHELOS     = 4422
};

class instance_razorfen_kraul : public ScriptedInstance
{
    public:
        instance_razorfen_kraul(Map* pMap);
        ~instance_razorfen_kraul() override {}

        void Initialize() override;

        void OnObjectCreate(GameObject* pGo) override;
        void OnCreatureCreate(Creature* pCreature) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        uint32 GetData(uint32 uiType) override;

        char const* Save() override { return m_strInstData.c_str(); }
        void Load(char const* chrIn) override;

    protected:
        uint32 m_auiEncounter[RFK_MAX_ENCOUNTER];
        std::string m_strInstData;

        uint8 m_uiWardKeepersRemaining;
        uint64 m_uiAgathelosWardGUID;
        uint64 m_uiAgathelosGUID;
};
#endif
