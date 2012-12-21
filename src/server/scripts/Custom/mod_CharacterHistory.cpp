#include "ScriptPCH.h"
#include "Config.h"

#define SQL_HISTORY "INSERT INTO `character_history` (`AccountId`, `RealmId`, `SessionIP`, `HistoryType`, `CharacterGuid`, `CharacterName`) VALUES ('%d', '%u', '%s', '%u', '%u', '%s')"

enum CharacterHistoryType
{
    CHARACTER_HISTORY_UNKNOWN = 0,
    CHARACTER_HISTORY_LOGIN   = 1,
    CHARACTER_HISTORY_LOGOUT  = 2,
    CHARACTER_HISTORY_DELETE  = 3,
    CHARACTER_HISTORY_CREATE  = 4
};

bool CharacterHistoryEnable   = false;
bool CharacterHistoryLogin    = false;
bool CharacterHistoryLogout   = false;
bool CharacterHistoryCreate   = false;
bool CharacterHistoryDelete   = false;

void WriteToHistory(Player* player, uint8 historyType)
{
    WorldSession* session = player->GetSession();
    LoginDatabase.PExecute(SQL_HISTORY, session->GetAccountId(), realmID, session->GetRemoteAddress().c_str(), historyType, player->GetGUIDLow(), player->GetName().c_str());
}

class mod_CharacterHistory_WorldScript : public WorldScript
{
    public:
        mod_CharacterHistory_WorldScript() : WorldScript("mod_CharacterHistory_WorldScript") { }

    // Called after the world configuration is (re)loaded.
    void OnConfigLoad(bool /*reload*/)
    {
        CharacterHistoryEnable    = ConfigMgr::GetBoolDefault("CharacterHistory.Enable", false);

        if (!CharacterHistoryEnable)
            return;

        CharacterHistoryLogin     = ConfigMgr::GetBoolDefault("CharacterHistory.Login", false);
        CharacterHistoryLogout    = ConfigMgr::GetBoolDefault("CharacterHistory.Logout", false);
        CharacterHistoryCreate    = ConfigMgr::GetBoolDefault("CharacterHistory.Create", false);
        CharacterHistoryDelete    = ConfigMgr::GetBoolDefault("CharacterHistory.Delete", false);
    }
};

class mod_CharacterHistory_PlayerScript : public PlayerScript
{
    public:
        mod_CharacterHistory_PlayerScript() : PlayerScript("mod_CharacterHistory_PlayerScript") { }

    // Called when a player is created.
    void OnCreate(Player* player)
    {
        if (!CharacterHistoryEnable || !CharacterHistoryCreate)
            return;

        WriteToHistory(player, CHARACTER_HISTORY_CREATE);
    }

    // Called when a player logs in.
    void OnLogin(Player* player)
    {
        if (!CharacterHistoryEnable || !CharacterHistoryLogin)
            return;

        WriteToHistory(player, CHARACTER_HISTORY_LOGIN);
    }

    // Called when a player logs out.
    void OnLogout(Player* player)
    {
        if (!CharacterHistoryEnable || !CharacterHistoryLogout)
            return;

        WriteToHistory(player, CHARACTER_HISTORY_LOGOUT);
    }

    // Called when a player is deleted.
    void OnDelete(uint64 guid, const char* name, WorldSession* session)
    {
        if (!CharacterHistoryEnable || !CharacterHistoryDelete)
            return;

        LoginDatabase.PExecute(SQL_HISTORY, session->GetAccountId(), realmID, session->GetRemoteAddress().c_str(), CHARACTER_HISTORY_DELETE, GUID_LOPART(guid), name);
    }
};

void AddSC_Mod_CharacterHistory()
{
    new mod_CharacterHistory_WorldScript();
    new mod_CharacterHistory_PlayerScript();
}
