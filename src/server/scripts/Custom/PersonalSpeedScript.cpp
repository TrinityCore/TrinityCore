#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "WorldSession.h"
#include "World.h"

namespace
{
    void ApplyPersonalSpeed(Player* player)
    {
        if (!player || !player->GetSession())
            return;

        float speedRate = sConfigMgr->GetFloatDefault("Player.MoveSpeed", 1.0f);
        if (speedRate <= 0.0f || speedRate == 1.0f)
            return;

        uint32 targetAccount = sConfigMgr->GetIntDefault("Player.MoveSpeed.AccountId", 0);
        if (targetAccount != 0 && player->GetSession()->GetAccountId() != targetAccount)
            return;

        player->SetSpeedRate(MOVE_WALK, speedRate);
        player->SetSpeedRate(MOVE_RUN, speedRate);
        player->SetSpeedRate(MOVE_RUN_BACK, speedRate);
        player->SetSpeedRate(MOVE_SWIM, speedRate);
        player->SetSpeedRate(MOVE_SWIM_BACK, speedRate);
        player->SetSpeedRate(MOVE_FLIGHT, speedRate);
        player->SetSpeedRate(MOVE_FLIGHT_BACK, speedRate);
    }
}

class PersonalSpeedPlayerScript : public PlayerScript
{
public:
    PersonalSpeedPlayerScript() : PlayerScript("PersonalSpeedPlayerScript") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        ApplyPersonalSpeed(player);
    }

    void OnMapChanged(Player* player) override
    {
        ApplyPersonalSpeed(player);
    }
};

class PersonalSpeedWorldScript : public WorldScript
{
public:
    PersonalSpeedWorldScript() : WorldScript("PersonalSpeedWorldScript") { }

    void OnUpdate(uint32 diff) override
    {
        _timer += diff;
        if (_timer < 1500)
            return;

        _timer = 0;
        for (auto const& itr : sWorld->GetAllSessions())
        {
            if (WorldSession* session = itr.second)
                if (Player* player = session->GetPlayer())
                    ApplyPersonalSpeed(player);
        }
    }

private:
    uint32 _timer = 0;
};

void AddSC_PersonalSpeedScript()
{
    new PersonalSpeedPlayerScript();
    new PersonalSpeedWorldScript();
}
