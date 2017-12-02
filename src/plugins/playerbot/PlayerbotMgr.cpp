#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "RandomPlayerbotMgr.h"
#include "CharacterCache.h"
#include "Log.h"
#include "ObjectAccessor.h"


class LoginQueryHolder;
class CharacterHandler;

PlayerbotHolder::PlayerbotHolder() : PlayerbotAIBase()
{
    for (uint32 spellId = 0; spellId < sSpellStore.GetNumRows(); spellId++)
        sSpellStore.LookupEntry(spellId);
}

PlayerbotHolder::~PlayerbotHolder()
{
    LogoutAllBots();
}


void PlayerbotHolder::UpdateAIInternal(uint32 elapsed)
{
}

void PlayerbotHolder::UpdateSessions(uint32 elapsed)
{
    for (PlayerBotMap::const_iterator itr = GetPlayerBotsBegin(); itr != GetPlayerBotsEnd(); ++itr)
    {
        Player* const bot = itr->second;
        if (bot->IsBeingTeleported())
        {
            bot->GetPlayerbotAI()->HandleTeleportAck();
        }
        else if (bot->IsInWorld())
        {
            bot->GetSession()->HandleBotPackets();
        }
    }
}

void PlayerbotHolder::LogoutAllBots()
{
    while (true)
    {
        PlayerBotMap::const_iterator itr = GetPlayerBotsBegin();
        if (itr == GetPlayerBotsEnd()) break;
        Player* bot= itr->second;
        LogoutPlayerBot(bot->GetGUID());
    }
}

void PlayerbotHolder::LogoutPlayerBot(uint64 guid)
{
    Player* bot = GetPlayerBot(guid);
    if (bot)
    {
        bot->GetPlayerbotAI()->TellMaster("Goodbye!");
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Bot %s logged out", bot->GetName());
        bot->SaveToDB();

        WorldSession * botWorldSessionPtr = bot->GetSession();
        playerBots.erase(guid);    // deletes bot player ptr inside this WorldSession PlayerBotMap
        botWorldSessionPtr->LogoutPlayer(true); // this will delete the bot Player object and PlayerbotAI object
        delete botWorldSessionPtr;  // finally delete the bot's WorldSession
    }
}

string PlayerbotHolder::LockPlayerBot(uint64 guid) //thesawolf - for gearlocking
{
    Player* bot = GetPlayerBot(guid);
    if (bot)
    {
        QueryResult gresults = CharacterDatabase.PQuery("SELECT * FROM ai_playerbot_locks WHERE name_id = '%u'", guid);
        if (gresults)
        {
            CharacterDatabase.PExecute("DELETE FROM ai_playerbot_locks WHERE name_id = '%u'", guid);    
            return "Gearlock: OFF";
        } 
        else 
        {
            CharacterDatabase.PExecute("INSERT INTO ai_playerbot_locks (name_id, gearlock) VALUES ('%u', 1)", guid);    
            return "Gearlock: ON";
        }
    }
    return "ERROR: bot does not exist";
}

Player* PlayerbotHolder::GetPlayerBot(uint64 playerGuid) const
{
    PlayerBotMap::const_iterator it = playerBots.find(playerGuid);
    return (it == playerBots.end()) ? 0 : it->second;
}

void PlayerbotHolder::OnBotLogin(Player * const bot)
{
    PlayerbotAI* ai = new PlayerbotAI(bot);
    bot->SetPlayerbotAI(ai);
    OnBotLoginInternal(bot);

    playerBots[bot->GetGUID()] = bot;

    Player* master = ai->GetMaster();
    if (master)
    {
        ObjectGuid masterGuid = master->GetGUID();
        if (master->GetGroup() &&
            ! master->GetGroup()->IsLeader(masterGuid))
            master->GetGroup()->ChangeLeader(masterGuid);
       //thesawolf - check for alt account playerbot
        uint32 botAccount = bot->GetSession()->GetAccountId();
        uint32 masterGacct = master->GetSession()->GetAccountId();
        if (masterGacct != botAccount)
        {        
            //thesawolf - faction change - still flags opposing for pvp.. but non-KOS
            bot->SetFaction(master->GetFaction());
        
            //thesawolf - autoset to master level
            uint32 level = master->getLevel();
            uint32 blevel = bot->getLevel();
            bool skipit = 1;
            uint32 ldiff = 0;

            //thesawolf - do a level check to see if init somethings can be skipped
            if (blevel >= level)
                ldiff = blevel - level;
            else
                ldiff = level - blevel;

            if (ldiff > 3)
                skipit = 0;        
            bot->SetLevel(level);

            //thesawolf - lets freshen things up a bit
            //sidenote: moved stuff from private to public to make these doable
            PlayerbotFactory factory(bot, master->getLevel());
            factory.Prepare();
            bot->ResetTalents(true);
            factory.CancelAuras();
            factory.InitAvailableSpells(); // spells step1
            factory.InitSkills(); // skills step1
            factory.InitTradeSkills();
            factory.InitTalents();
            factory.InitAvailableSpells(); // spells step2, needs to reinit
            factory.InitSpecialSpells();
            factory.InitMounts();
            factory.UpdateTradeSkills(); // skills step2, needs to update
            bot->SaveToDB();
    
            if (skipit == 0)
            {
                factory.InitEquipment(true);
                factory.InitBags();        
                factory.InitSecondEquipmentSet();        
            }

            factory.InitAmmo();
            factory.InitFood();
            factory.InitPotions();
            // factory.InitInventory();  // lets not lose gear stored by a packmule
            factory.InitGlyphs();
            factory.InitGuild(); 
            factory.InitPet();
        
            bot->SetMoney(urand(level * 10000, level * 5 * 10000));
        
            //thesawolf - refill hp/sp since level resets can leave a vacuum
            bot->SetHealth(bot->GetMaxHealth());
            bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA));

            bot->SaveToDB();
          }
    
          //thesawolf - autosummon to master
          bot->TeleportTo(master->GetMapId(), master->GetPositionX(), master->GetPositionY(), master->GetPositionZ(), master->GetOrientation());
          //with pizazz
          bot->CastSpell(bot, 52096, true);
          bot->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
    }

    Group *group = bot->GetGroup();
    if (group)
    {
        bool groupValid = false;
        Group::MemberSlotList const& slots = group->GetMemberSlots();
        for (Group::MemberSlotList::const_iterator i = slots.begin(); i != slots.end(); ++i)
        {
            ObjectGuid member = i->guid;
            uint32 account = sCharacterCache->GetCharacterAccountIdByGuid(member);
            if (!sPlayerbotAIConfig.IsInRandomAccountList(account))
            {
                groupValid = true;
                //thesawolf - personable test
                ai->TellMaster("Thanks for saving my spot!");
                break;
            }
        }

        if (!groupValid)
        {
            WorldPacket p;
            string member = bot->GetName();
            p << uint32(PARTY_OP_LEAVE) << member << uint32(0);
            bot->GetSession()->HandleGroupDisbandOpcode(p);
        }
    }

    ai->ResetStrategies();
    ai->TellMaster("Hello!");
}

string PlayerbotHolder::ProcessBotCommand(string cmd, ObjectGuid guid, bool admin, uint32 masterAccountId, uint32 masterGuildId)
{
    if (!sPlayerbotAIConfig.enabled || guid.IsEmpty())
        return "bot system is disabled";

    uint32 botAccount = sCharacterCache->GetCharacterAccountIdByGuid(guid);
    bool isRandomBot = sRandomPlayerbotMgr.IsRandomBot(guid);
    bool isRandomAccount = sPlayerbotAIConfig.IsInRandomAccountList(botAccount);
    bool isMasterAccount = (masterAccountId == botAccount);

    if (isRandomAccount && !isRandomBot && !admin)
    {
        Player* bot = ObjectAccessor::FindPlayer(guid);
        if (bot->GetGuildId() != masterGuildId)
            return "not in your guild";
    }

    if (!isRandomAccount && !isMasterAccount) // && !admin) thesawolf
        return "not in your account";

    if (cmd == "add" || cmd == "login")
    {
        if (ObjectAccessor::FindPlayer(guid))
            return "player already logged in";

        AddPlayerBot(guid.GetRawValue(), masterAccountId);
        return "ok";
    }
    else if (cmd == "remove" || cmd == "logout" || cmd == "rm")
    {
        if (!ObjectAccessor::FindPlayer(guid))
            return "player is offline";

        if (!GetPlayerBot(guid.GetRawValue()))
            return "not your bot";

        LogoutPlayerBot(guid.GetRawValue());
        return "ok";
    }
    else if (cmd == "lock") // thesawolf - gear lock so not replaced
    {
        if (!ObjectAccessor::FindPlayer(guid))
            return "player is offline";
        
        if (!GetPlayerBot(guid.GetRawValue()))
            return "not your bot";
        
        return(LockPlayerBot(guid.GetRawValue()));
    }

    if (admin || !admin) // thesawolf - giving all players access (for now)
    {
        Player* bot = GetPlayerBot(guid.GetRawValue());
        if (!bot)
            return "bot not found";

        Player* master = bot->GetPlayerbotAI()->GetMaster();

        //thesawolf - check for alt account playerbot
        uint32 botAcct = bot->GetSession()->GetAccountId();
        uint32 masterGacct = master->GetSession()->GetAccountId();

        if (master)
        {
            if (cmd == "init=white" || cmd == "init=common")
            {
                if (botAcct != masterGacct)
                {            
                    PlayerbotFactory factory(bot, master->getLevel(), ITEM_QUALITY_NORMAL);
                    factory.CleanRandomize();
                    return "ok";
                }
                else
                    return "ERROR: You cannot use INIT on an ALT!";
            }
            else if (cmd == "init=green" || cmd == "init=uncommon")
            {
                if (botAcct != masterGacct)
                {            
                    PlayerbotFactory factory(bot, master->getLevel(), ITEM_QUALITY_UNCOMMON);
                    factory.CleanRandomize();
                    return "ok";
                }
                else
                    return "ERROR: You cannot use INIT on an ALT!";
            }
            else if (cmd == "init=blue" || cmd == "init=rare")
            {
                if (botAcct != masterGacct)
                {            
                    PlayerbotFactory factory(bot, master->getLevel(), ITEM_QUALITY_RARE);
                    factory.CleanRandomize();
                    return "ok";
                }
                else
                    return "ERROR: You cannot use INIT on an ALT!";
            }
            else if (cmd == "init=epic" || cmd == "init=purple")
            {
                if (botAcct != masterGacct)
                {            
                    PlayerbotFactory factory(bot, master->getLevel(), ITEM_QUALITY_EPIC);
                    factory.CleanRandomize();
                    return "ok";
                }
                else
                    return "ERROR: You cannot use INIT on an ALT!";
            }
            else if (cmd == "init")
            {
                if (botAcct != masterGacct)
                {            
                    return "Specify quality level to init to.. ie. init=blue"; //thesawolf - give some instructions
                }
                else
                    return "ERROR: You cannot use INIT on an ALT!";
            }
        }

        if (cmd == "update")
        {
            if (botAcct != masterGacct)
            {    
                PlayerbotFactory factory(bot, bot->getLevel());
                factory.Refresh();
                return "ok";
            }
            else 
                return "ERROR: You cannot use UPDATE on an ALT!";
        }
        else if (cmd == "random")
        {
            if (botAcct != masterGacct)
            { 
                sRandomPlayerbotMgr.Randomize(bot);
                return "ok";
            }
            else
                return "ERROR: You cannot use RANDOM on an ALT!";
        }
    }

    return "unknown command";
}

bool PlayerbotMgr::HandlePlayerbotMgrCommand(ChatHandler* handler, char const* args)
{
    if (!sPlayerbotAIConfig.enabled)
    {
        handler->PSendSysMessage("|cffff0000Playerbot system is currently disabled!");
        handler->SetSentErrorMessage(true);
        return false;
    }

    WorldSession *m_session = handler->GetSession();

    if (!m_session)
    {
        handler->PSendSysMessage("You may only add bots from an active session");
        handler->SetSentErrorMessage(true);
        return false;
    }

    Player* player = m_session->GetPlayer();
    PlayerbotMgr* mgr = player->GetPlayerbotMgr();
    if (!mgr)
    {
        handler->PSendSysMessage("you cannot control bots yet");
        handler->SetSentErrorMessage(true);
        return false;
    }

    list<string> messages = mgr->HandlePlayerbotCommand(args, player);
    if (messages.empty())
        return true;

    for (list<string>::iterator i = messages.begin(); i != messages.end(); ++i)
    {
        handler->PSendSysMessage(i->c_str());
    }

    handler->SetSentErrorMessage(true);
    return false;
}

list<string> PlayerbotHolder::HandlePlayerbotCommand(char const* args, Player* master)
{
    list<string> messages;

    if (!*args)
    {
        messages.push_back("usage: list or add/init/remove PLAYERNAME");
        return messages;
    }

    char *cmd = strtok ((char*)args, " ");
    char *charname = strtok (NULL, " ");

    //thesawolf - display lookup legend
    if ((cmd) && (!charname))
    {
        std::string cmdStr = cmd;
        if (cmdStr == "lookup" || cmdStr == "LOOKUP")
        {
            messages.push_back("Classes Available:");
            messages.push_back("|TInterface\\icons\\INV_Sword_27.png:25:25:0:-1|t Warrior");
            messages.push_back("|TInterface\\icons\\INV_Hammer_01.png:25:25:0:-1|t Paladin");
            messages.push_back("|TInterface\\icons\\INV_Weapon_Bow_07.png:25:25:0:-1|t Hunter");
            messages.push_back("|TInterface\\icons\\INV_ThrowingKnife_04.png:25:25:0:-1|t Rogue");
            messages.push_back("|TInterface\\icons\\INV_Staff_30.png:25:25:0:-1|t Priest");
            messages.push_back("|TInterface\\icons\\inv_jewelry_talisman_04.png:25:25:0:-1|t Shaman");
            messages.push_back("|TInterface\\icons\\INV_staff_30.png:25:25:0:-1|t Mage");
            messages.push_back("|TInterface\\icons\\INV_staff_30.png:25:25:0:-1|t Warlock");
            messages.push_back("|TInterface\\icons\\Ability_Druid_Maul.png:25:25:0:-1|t Druid");
            messages.push_back("(Usage: .bot lookup CLASS)");
            return messages;
        }
    }
    else if (!cmd || !charname)
    {
        messages.push_back("Usage: .bot add / remove PLAYERNAME");
        messages.push_back("       .bot lookup [CLASS] (without to see list of classes)");
        messages.push_back("       .bot update / random / init=[QUALITY]");
        return messages;
    }

    if (!strcmp(cmd, "list"))
    {
        messages.push_back(ListBots(master));
        return messages;
    }

    //thesawolf - without this null check, tc was crashing because of the null to string conversion
    if (charname == NULL)
    {
        messages.push_back("ERROR: No bot was specified. Try again.");
        return messages;
    }
    if (!charname)
    {
        messages.push_back("usage: list or add/init/remove PLAYERNAME");
        return messages;
    }

    std::string cmdStr = cmd;
    std::string charnameStr = charname;

    //thesawolf - lookup routine.. you know ANY of those RANDOM names?
    if (cmdStr == "lookup" || cmdStr == "LOOKUP")
    {
        string bsearch1 = "Looking for bots of class: " + charnameStr + "...";
        messages.push_back(bsearch1);

        uint8 claz = 0;
        string icon = " ";
        if (charnameStr == "warrior" || charnameStr == "Warrior" || charnameStr == "WARRIOR")
        {
            claz = 1;
            icon = "|TInterface\\icons\\INV_Sword_27.png:25:25:0:-1|t ";
        }
        else if (charnameStr == "paladin" || charnameStr == "Paladin" || charnameStr == "PALADIN")
        {
            claz = 2;
            icon = "|TInterface\\icons\\INV_Hammer_01.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "hunter" || charnameStr == "Hunter" || charnameStr == "HUNTER")
        {
            claz = 3;
            icon = "|TInterface\\icons\\INV_Weapon_Bow_07.png:25:25:0:-1|t ";
        }
        else if (charnameStr == "rogue" || charnameStr == "Rogue" || charnameStr == "ROGUE" || charnameStr == "rouge" || charnameStr == "Rouge" || charnameStr == "ROUGE") // for my friends that cannot spell
        {
            claz = 4;
            icon = "|TInterface\\icons\\INV_ThrowingKnife_04.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "priest" || charnameStr == "Priest" || charnameStr == "PRIEST")
        {
            claz = 5;
            icon = "|TInterface\\icons\\INV_Staff_30.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "shaman" || charnameStr == "Shaman" || charnameStr == "SHAMAN")
        {
            claz = 7;
            icon = "|TInterface\\icons\\inv_jewelry_talisman_04.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "mage" || charnameStr == "Mage" || charnameStr == "MAGE")
        {
            claz = 8;
            icon = "|TInterface\\icons\\INV_staff_30.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "warlock" || charnameStr == "Warlock" || charnameStr == "WARLOCK")
        {
            claz = 9;
            icon = "|TInterface\\icons\\INV_staff_30.png:25:25:0:-1|t ";
        }                
        else if (charnameStr == "druid" || charnameStr == "Druid" || charnameStr == "DRUID")
        {
            claz = 11;
            icon = "|TInterface\\icons\\Ability_Druid_Maul.png:25:25:0:-1|t ";
        }
        else
        {
            messages.push_back("Error: Invalid Class. Try again.");
            return messages;
        }
        // thesawolf - lookup query search only for valid playerbots and alts on account
        //QueryResult lresults = CharacterDatabase.PQuery("SELECT * FROM characters WHERE class = '%u'",claz);
        QueryResult lresults = CharacterDatabase.PQuery("SELECT * FROM characters WHERE account = '%u' AND class = '%u' UNION ALL SELECT * FROM characters WHERE name IN (SELECT name FROM ai_playerbot_names) AND class = '%u' ORDER BY name ASC",master->GetSession()->GetAccountId(),claz,claz);
        if (lresults)
        {
            do
            {
                Field* fields = lresults->Fetch();
                uint32 acctId = fields[1].GetUInt32();
                string bName = fields[2].GetString();
                uint8 bRace = fields[3].GetUInt8();
                string cRace = " ";
                switch (bRace)
                {
                    case 1: cRace = "Human";	break;
                    case 2: cRace = "Orc";	break;
                    case 3: cRace = "Dwarf";	break;
                    case 4: cRace = "Nightelf";	break;
                    case 5: cRace = "Undead";	break;
                    case 6: cRace = "Tauren";	break;
                    case 7: cRace = "Gnome";	break;
                    case 8: cRace = "Troll";	break;
                    case 10: cRace = "Bloodelf";break;
                    case 11: cRace = "Draenei";	break;
                }
                bool bGender = fields[5].GetBool();
                string cGender = "";
                if (bGender == 0)
                    cGender = "Male";
                else
                    cGender = "Female";
                bool bOnline = fields[25].GetBool();
                string cOnline = "";
                //thesawolf - alt and bot differential
                if ((bOnline == 0) && (acctId == master->GetSession()->GetAccountId()))
                    cOnline = "|cff0ff000ALT Available|r";
                else if (bOnline == 0)
                    cOnline = "|cff00ff00Available|r";
                else
                    cOnline = "|cffff0000Not Available|r";
                string bList = icon + "|TInterface\\icons\\Achievement_Character_" + cRace + "_" + cGender + ".png:25:25:0:-1|t " + bName + " - " + cRace + " " + cGender + " [" + cOnline + "]";
                messages.push_back(bList);
                
            } while (lresults->NextRow());
        }
        else 
        {
            messages.push_back("Error: Listing class bots. Try again.");
            messages.push_back("Usage: .bot lookup (to see list of classes)");
            return messages;
        }
        messages.push_back("(Usage: .bot add PLAYERNAME)");
        return messages;
    }

    set<string> bots;
    if (charnameStr == "*" && master)
    {
        Group* group = master->GetGroup();
        if (!group)
        {
            messages.push_back("you must be in group");
            return messages;
        }

        Group::MemberSlotList slots = group->GetMemberSlots();
        for (Group::member_citerator i = slots.begin(); i != slots.end(); i++)
        {
            ObjectGuid member = i->guid;

            if (member == master->GetGUID())
                continue;

            string bot;
            if (sCharacterCache->GetCharacterNameByGuid(member, bot))
                bots.insert(bot);
        }
    }

    if (charnameStr == "!" && master && master->GetSession()->GetSecurity() > SEC_PLAYER) // SEC_GAMEMASTER) thesawolf
    {
        for (PlayerBotMap::const_iterator i = GetPlayerBotsBegin(); i != GetPlayerBotsEnd(); ++i)
        {
            Player* bot = i->second;
            if (bot && bot->IsInWorld())
                bots.insert(bot->GetName());
        }
    }

	std::vector<std::string> split(const std::string &s, char delim);

    vector<string> chars = split(charnameStr, ',');
    for (vector<string>::iterator i = chars.begin(); i != chars.end(); i++)
    {
        string s = *i;

        uint32 accountId = GetAccountId(s);
        if (!accountId)
        {
            bots.insert(s);
            continue;
        }

        QueryResult results = CharacterDatabase.PQuery(
            "SELECT name FROM characters WHERE account = '%u'",
            accountId);
        if (results)
        {
            do
            {
                Field* fields = results->Fetch();
                string charName = fields[0].GetString();
                bots.insert(charName);
            } while (results->NextRow());
        }
    }

    for (set<string>::iterator i = bots.begin(); i != bots.end(); ++i)
    {
        string bot = *i;
        ostringstream out;
        out << cmdStr << ": " << bot << " - ";

        ObjectGuid member = sCharacterCache->GetCharacterGuidByName(bot);
        if (!member)
        {
            out << "character not found";
        }
        else if (master && member != master->GetGUID())
        {
            out << ProcessBotCommand(cmdStr, member,
                    master->GetSession()->GetSecurity() >= SEC_PLAYER, //SEC_GAMEMASTER, thesawolf
                    master->GetSession()->GetAccountId(),
                    master->GetGuildId());
        }
        else if (!master)
        {
            out << ProcessBotCommand(cmdStr, member, true, -1, -1);
        }

        messages.push_back(out.str());
    }

    return messages;
}

uint32 PlayerbotHolder::GetAccountId(string name)
{
    uint32 accountId = 0;

    QueryResult results = LoginDatabase.PQuery("SELECT id FROM account WHERE username = '%s'", name.c_str());
    if(results)
    {
        Field* fields = results->Fetch();
        accountId = fields[0].GetUInt32();
    }

    return accountId;
}

string PlayerbotHolder::ListBots(Player* master)
{
    set<string> bots;
    map<uint8,string> classNames;
    classNames[CLASS_DRUID] = "Druid";
    classNames[CLASS_HUNTER] = "Hunter";
    classNames[CLASS_MAGE] = "Mage";
    classNames[CLASS_PALADIN] = "Paladin";
    classNames[CLASS_PRIEST] = "Priest";
    classNames[CLASS_ROGUE] = "Rogue";
    classNames[CLASS_SHAMAN] = "Shaman";
    classNames[CLASS_WARLOCK] = "Warlock";
    classNames[CLASS_WARRIOR] = "Warrior";
    ostringstream out;
    bool first = true;
    out << "Bot roster: ";
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        string name = bot->GetName();
        bots.insert(name);

        if (first) first = false; else out << ", ";
        out << "+" << name << " " << classNames[bot->getClass()];
    }

    if (master)
    {
        QueryResult results = CharacterDatabase.PQuery("SELECT class,name FROM characters where account = '%u'",
                master->GetSession()->GetAccountId());
        if (results != NULL)
        {
            do
            {
                Field* fields = results->Fetch();
                uint8 cls = fields[0].GetUInt8();
                string name = fields[1].GetString();
                if (bots.find(name) == bots.end() && name != master->GetSession()->GetPlayerName())
                {
                    if (first) first = false; else out << ", ";
                    out << "-" << name << " " << classNames[cls];
                }
            } while (results->NextRow());
        }
    }

    return out.str();
}


PlayerbotMgr::PlayerbotMgr(Player* const master) : PlayerbotHolder(),  master(master)
{
}

PlayerbotMgr::~PlayerbotMgr()
{
}

void PlayerbotMgr::UpdateAIInternal(uint32 elapsed)
{
    SetNextCheckDelay(sPlayerbotAIConfig.reactDelay);
}

void PlayerbotMgr::HandleCommand(uint32 type, const string& text)
{
    Player *master = GetMaster();
    if (!master)
        return;

    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        bot->GetPlayerbotAI()->HandleCommand(type, text, *master);
    }

    for (PlayerBotMap::const_iterator it = sRandomPlayerbotMgr.GetPlayerBotsBegin(); it != sRandomPlayerbotMgr.GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        if (bot->GetPlayerbotAI()->GetMaster() == master)
            bot->GetPlayerbotAI()->HandleCommand(type, text, *master);
    }
}

void PlayerbotMgr::HandleMasterIncomingPacket(const WorldPacket& packet)
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        bot->GetPlayerbotAI()->HandleMasterIncomingPacket(packet);
    }

    for (PlayerBotMap::const_iterator it = sRandomPlayerbotMgr.GetPlayerBotsBegin(); it != sRandomPlayerbotMgr.GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        if (bot->GetPlayerbotAI()->GetMaster() == GetMaster())
            bot->GetPlayerbotAI()->HandleMasterIncomingPacket(packet);
    }

    switch (packet.GetOpcode())
    {
        // if master is logging out, log out all bots
        case CMSG_LOGOUT_REQUEST:
        {
            LogoutAllBots();
            return;
        }
    }
}
void PlayerbotMgr::HandleMasterOutgoingPacket(const WorldPacket& packet)
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        bot->GetPlayerbotAI()->HandleMasterOutgoingPacket(packet);
    }

    for (PlayerBotMap::const_iterator it = sRandomPlayerbotMgr.GetPlayerBotsBegin(); it != sRandomPlayerbotMgr.GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        if (bot->GetPlayerbotAI()->GetMaster() == GetMaster())
            bot->GetPlayerbotAI()->HandleMasterOutgoingPacket(packet);
    }
}

void PlayerbotMgr::SaveToDB()
{
    for (PlayerBotMap::const_iterator it = GetPlayerBotsBegin(); it != GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        bot->SaveToDB();
    }
    for (PlayerBotMap::const_iterator it = sRandomPlayerbotMgr.GetPlayerBotsBegin(); it != sRandomPlayerbotMgr.GetPlayerBotsEnd(); ++it)
    {
        Player* const bot = it->second;
        if (bot->GetPlayerbotAI()->GetMaster() == GetMaster())
            bot->SaveToDB();
    }
}

void PlayerbotMgr::OnBotLoginInternal(Player * const bot)
{
    bot->GetPlayerbotAI()->SetMaster(master);
    bot->GetPlayerbotAI()->ResetStrategies();
}
