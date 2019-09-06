#include "ScriptMgr.h"

class CharacterActionUpdatePhase : public PlayerScript
{
public:
    CharacterActionUpdatePhase() : PlayerScript("CharacterActionUpdatePhase") { }

    void OnCreate(Player* player) override
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_FACL_IP_LOGGING);

        stmt->setUInt32(0, playerGuid);
        stmt->setUInt32(1, characterGuid);
        stmt->setUInt8(2, aType);
        stmt->setUInt32(3, playerGuid);
        stmt->setString(4, systemNote);
        LoginDatabase.Execute(stmt);
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {

    }

    void OnLogout(Player* player) override
    {

    }
};
