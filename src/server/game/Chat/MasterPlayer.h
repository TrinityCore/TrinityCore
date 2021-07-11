#ifndef MASTERPLAYER_H
#define MASTERPLAYER_H

#include "Common.h"
#include "SharedDefines.h"
#include "ObjectGuid.h"
#include "Chat/AbstractPlayer.h"

class PlayerSocial;
class WorldSession;
struct ActionButton;
class QueryResult;
class Player;
struct Mail;
class Item;
class Channel;

typedef std::map<uint8,ActionButton> ActionButtonList;
typedef std::deque<Mail*> PlayerMails;

class MasterPlayer
{
public:
    MasterPlayer(WorldSession* s);
    ~MasterPlayer();

    void Create(ObjectGuid playerGuid, uint8 raceId, uint32 classId);
    void LoadPlayer(Player* player);
    void SaveToDB();
    void Update();

    WorldSession* GetSession() const { return m_session; }
    void SetSession(WorldSession* wsess) { m_session = wsess; }

    uint32 GetGUIDLow() const { return guid.GetCounter(); }
    ObjectGuid const& GetObjectGuid() const { return guid; }
    std::string GetGuidStr() const { return GetObjectGuid().GetString(); }

    // CHAT SYSTEM
    void UpdateSpeakTime();
    void Whisper(std::string const& text, uint32 language, MasterPlayer* receiver);
    void ToggleDND();
    void ToggleAFK();
    void JoinedChannel(Channel *c);
    void LeftChannel(Channel *c);
    void CleanupChannels();

    // SOCIAL SYSTEM
    PlayerSocial* GetSocial() const { return m_social; }
    void SetSocial(PlayerSocial* s) { m_social = s; }
    void LoadSocial(QueryResult* result);

    // ACTIONS SYSTEM
    void LoadActions(QueryResult* result);
    void SaveActions();
    ActionButtonList& GetActionButtons() { return m_actionButtons; }
    void SendInitialActionButtons() const;
    ActionButton* addActionButton(uint8 button, uint32 action, uint8 type);
    void removeActionButton(uint8 button);

    // MAIL SYSTEM
    void LoadMailedItems(QueryResult* result);
    void LoadMails(QueryResult* result);
    void SaveMails();
    void UpdateNextMailTimeAndUnreads();
    void AddNewMailDeliverTime(time_t deliver_time);
    void RemoveMail(uint32 id);
    void AddMail(Mail* mail) { m_mail.push_front(mail);}// for call from WorldSession::SendMailTo
    uint32 GetMailSize() { return m_mail.size(); }
    Mail* GetMail(uint32 id);
    void MarkMailsUpdated() { m_mailsUpdated = true; }
    bool HasUnreadMail() const { return unReadMails > 0; }
    void DecreaseUnreadMailsCount() { unReadMails = unReadMails ? unReadMails-1 : 0; }

    PlayerMails::iterator GetMailBegin() { return m_mail.begin();}
    PlayerMails::iterator GetMailEnd() { return m_mail.end();}

    typedef std::unordered_map<uint32, Item*> ItemMap;

    Item* GetMItem(uint32 id)
    {
        ItemMap::const_iterator itr = mMitems.find(id);
        return itr != mMitems.end() ? itr->second : nullptr;
    }

    void AddMItem(Item* it);
    bool RemoveMItem(uint32 id) { return mMitems.erase(id) ? true : false; }


    // GUILD SYSTEMS
    uint32 GetGuildId() const { return guildId;  }
    uint32 GetRank() const { return guildRank; }

    // GM SYSTEMS
    bool IsAcceptTickets() const { return m_ExtraFlags & PLAYER_EXTRA_GM_ACCEPT_TICKETS; }
    void SetAcceptTicket(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_GM_ACCEPT_TICKETS; else m_ExtraFlags &= ~PLAYER_EXTRA_GM_ACCEPT_TICKETS; }

    bool IsAcceptWhispers() const { return m_ExtraFlags & PLAYER_EXTRA_ACCEPT_WHISPERS; }
    bool AcceptsWhispersFrom(ObjectGuid whisperer) const { return IsAcceptWhispers() || m_allowedWhispers.find(whisperer) != m_allowedWhispers.end(); }
    void AddAllowedWhisperer(ObjectGuid whisperer) { m_allowedWhispers.insert(whisperer); }
    void ClearAllowedWhisperers() { m_allowedWhispers.clear(); }
    void SetAcceptWhispers(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_ACCEPT_WHISPERS; else m_ExtraFlags &= ~PLAYER_EXTRA_ACCEPT_WHISPERS; }

    bool IsGameMaster() const { return m_ExtraFlags & PLAYER_EXTRA_GM_ON; }

    //
    bool IsVisibleGloballyFor(MasterPlayer* player) const;
    uint32 GetGMInvisibilityRank() const { return m_gmInvisibilityLevel; }
    Team GetTeam() const { return m_team; }
    char const* GetName() const { return name.c_str(); }
    uint32 GetZoneId() const { return zoneId; }
    uint32 GetAreaId() const { return areaId; }
    uint8 GetClass() const { return classId; }
    uint8 GetRace() const { return raceId; }
    uint32 GetLevel() const { return level; }
    bool IsAFK() const { return GetChatTag() == 1; }
    bool IsDND() const { return GetChatTag() == 2; }
    uint8 GetChatTag() const { return m_chatTag; }

    ObjectGuid guid;
    std::string name;
    uint32 zoneId;
    uint32 areaId;
    uint8 raceId;
    uint8 classId;
    uint32 level;
    Team m_team;
    // Guild system variables
    uint32 guildId;
    uint32 guildRank;
    // Chat system variables
    std::string afkMsg;
    std::string dndMsg;
    uint8 m_chatTag;
    time_t m_speakTime;
    uint32 m_speakCount;
    typedef std::list<Channel*> JoinedChannelsList;
    JoinedChannelsList m_channels;
    // GM system variables
    uint8 m_gmInvisibilityLevel;
    uint32 m_ExtraFlags;
    std::set<ObjectGuid> m_allowedWhispers;

    // TODO: Group ?

protected:

    PlayerSocial* m_social;
    ActionButtonList m_actionButtons;
    WorldSession* m_session;

    bool m_mailsUpdated;
    uint8 unReadMails;
    time_t m_nextMailDelivereTime;
    PlayerMails m_mail;
    ItemMap mMitems;
};

#endif // MASTERPLAYER_H
