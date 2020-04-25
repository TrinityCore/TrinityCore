#include "ScriptMgr.h"
#include "DatabaseEnv.h"
#include "Player.h"

class CharacterActionUpdatePhase : public PlayerScript
{
public:
    CharacterActionUpdatePhase() : PlayerScript("CharacterActionUpdatePhase") { }

    void OnCreate(Player* player) override
    {
        ObjectGuid::LowType lowGuid = player->GetGUID().GetCounter();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_PHASE);
        stmt->setUInt32(0, lowGuid);
        stmt->setUInt32(1, player->GetPhaseMask());
        CharacterDatabase.Execute(stmt);
    }

    void OnDelete(ObjectGuid guid, uint32 /*accountId*/) override
    {
        ObjectGuid::LowType lowGuid = guid.GetCounter();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PHASE);
        stmt->setUInt32(0, lowGuid);
        CharacterDatabase.Execute(stmt);
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        ObjectGuid::LowType lowGuid = player->GetGUID().GetCounter();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PHASE);
        stmt->setUInt32(0, lowGuid);

        PreparedQueryResult result = CharacterDatabase.Query(stmt);
        if (result)
        {
            Field* fieldsDB = result->Fetch();
            ObjectGuid guid = ObjectGuid(HighGuid::Player, fieldsDB[0].GetUInt32());
            uint32 phaseMask = fieldsDB[1].GetUInt32();

            player->SetPhaseMask(phaseMask, true);
        }
    }

    void OnLogout(Player* player) override
    {
        ObjectGuid::LowType lowGuid = player->GetGUID().GetCounter();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PHASE);
        stmt->setUInt32(0, player->GetPhaseMask());
        stmt->setUInt32(1, lowGuid);
        CharacterDatabase.Execute(stmt);
    }
};

void AddSC_action_update_phase()
{
    new CharacterActionUpdatePhase();
}
