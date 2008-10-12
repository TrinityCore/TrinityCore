/*
 * MangChat By |Death| And Cybrax
 *
 * This Program Is Free Software; You Can Redistribute It And/Or Modify It Under The Terms 
 * Of The GNU General Public License
 * Written and Developed by Cybrax. cybraxvd@gmail.com
 * |Death| <death@hell360.net>, Lice <lice@yeuxverts.net>, Dj_baby & Sanaell, Tase
 * With Help And Support From The MaNGOS Project Community.
 * PLEASE RETAIN THE COPYRIGHT OF THE AUTHORS.
 */
#include "IRCCmd.h"
#include "IRCClient.h"
#include "MCS_OnlinePlayers.h"
#include "WorldPacket.h"
#include "Database/DatabaseEnv.h"
#include "Chat.h"
#include "MapManager.h"
#include "World.h"
#include "Guild.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "SpellAuras.h"
#include "SystemConfig.h"
#include "Config/ConfigEnv.h"

#define Send_Player(p, m)           sIRC.Send_WoW_Player(p, m)
#define Send_IRCA(c, m, b, t)       sIRC.Send_IRC_Channel(c, m, b, t)

#ifdef WIN32
#define Delay(x) Sleep(x)
#else
#define Delay(x) sleep(x / 1000)
#endif

void IRCCmd::Handle_Login(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 2);
    std::string isbanned = AcctIsBanned(_PARAMS[0]);
    if(isbanned == "NOTBANNED")
    {
        if(!IsLoggedIn(CD->USER))
        {
            if(!AcctIsLoggedIn(_PARAMS[0].c_str()))
            {
                QueryResult *result = loginDatabase.PQuery("SELECT `gmlevel` FROM `account` WHERE `username`='%s' AND `sha_pass_hash`=SHA1(CONCAT(UPPER(`username`),':',UPPER('%s')));", _PARAMS[0].c_str(), _PARAMS[1].c_str());
                if (result)
                {
                    Field *fields = result->Fetch();
                    int GMLevel = fields[0].GetInt16();
                    if(GMLevel >= 0)
                    {
                        _client *NewClient = new _client();
                         NewClient->Name     = CD->USER;
                        NewClient->UName    = MakeUpper(_PARAMS[0]);
                        NewClient->GMLevel  = fields[0].GetInt16();
                        _CLIENTS.push_back(NewClient);
                        Send_IRCA(CD->USER, MakeMsg("You Are Now Logged In As %s, Welcome To MangChat Admin Mode.", _PARAMS[0].c_str()), true, CD->TYPE);

                        if(sIRC._op_gm == 1 && GMLevel >= sIRC._op_gm_lev)
                        {
                            for(int i=1;i < sIRC._chan_count + 1;i++)
                            sIRC.SendIRC("MODE #"+sIRC._irc_chan[i]+" +o "+CD->USER );
                        }
                    }
                }else
                    Send_IRCA(CD->USER, "\0034[ERROR] : Sorry, Your Username Or Password Is Incorrect. Please Try Again. ", true, "ERROR");
            }else
                Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : %s Is Already Logged In With This Username. ", GetNameFromAcct(MakeUpper(_PARAMS[0])).c_str()), true, "ERROR");
        }else
            Send_IRCA(CD->USER, "\0034[ERROR] : You Are Already Logged In As "+ _PARAMS[0] +"!", true, "ERROR");
    }else
         Send_IRCA(CD->USER, "\0034[ERROR] : Sorry You Are "+isbanned+". You Cannot Log In To MangChat "+CD->USER.c_str()+"!", true, "ERROR");
}

void IRCCmd::Handle_Logout(_CDATA *CD)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == CD->USER)
        {
            _CLIENTS.erase(i);
            delete (*i);
            Send_IRCA(CD->USER, "You Are Now Logged Out!", true, CD->TYPE);
            return;
        }
    }
    Send_IRCA(CD->USER, "\0034[ERROR] : You Are Not Logged In!", true, "ERROR");
}

void IRCCmd::Account_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    normalizePlayerName(_PARAMS[0]);
    uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[0]);
    uint32 account_id = 0;
    account_id = objmgr.GetPlayerAccountIdByGUID(guid);
    if(account_id)
    {
        if(account_id == GetAcctIDFromName(CD->USER) || GetLevel(CD->USER) >= sIRC._op_gm_lev)
        {
            Player* plr = objmgr.GetPlayer(guid);
            if(_PARAMS[1] == "lock")
            {
                loginDatabase.PExecute( "UPDATE `account` SET `locked` = '1' WHERE `id` = '%d'",account_id);
                if(plr) Send_Player(plr, MakeMsg("Your Account Has Been Locked To Your Current IP By: %s", CD->USER.c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+GetAcctNameFromID(account_id)+"] : Account Has Been Locked To Their Current IP Address.", true, CD->TYPE);
            }
            else if(_PARAMS[1] == "unlock")
            {
                loginDatabase.PExecute( "UPDATE `account` SET `locked` = '0' WHERE `id` = '%d'",account_id);
                if(plr) Send_Player(plr, MakeMsg("Your Account Has Been UnLocked From The Associated IP By: %s", CD->USER.c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+GetAcctNameFromID(account_id)+"] : Account Has Been UnLocked From The Associated IP Address.", true, CD->TYPE);
            }
            else if(_PARAMS[1] == "mail")
            {
                loginDatabase.PExecute( "UPDATE `account` SET `email` = '%s' WHERE `id` = '%d'",_PARAMS[2].c_str() ,account_id);
                if (plr) Send_Player(plr, MakeMsg("%s Has Changed Your EMail Adress To: %s", CD->USER.c_str(), _PARAMS[2].c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+GetAcctNameFromID(account_id)+"] : EMail Address Successfully Changed To: "+_PARAMS[2], true, CD->TYPE);
            }
            else if(_PARAMS[1] == "pass")
            {
                loginDatabase.PExecute( "UPDATE `account` SET `sha_pass_hash` = SHA1(CONCAT(UPPER(`username`),':',UPPER('%s'))) WHERE `id` = '%d'",_PARAMS[2].c_str() ,account_id);
                if (plr) Send_Player(plr, MakeMsg("%s Has Changed Your Password To: %s", CD->USER.c_str(), _PARAMS[2].c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+GetAcctNameFromID(account_id)+"] : Password Successfully Changed To: "+_PARAMS[2], true, CD->TYPE);
            }
            else if(_PARAMS[1] == "rename")
            {
                if(plr)
                {
                    plr->SetAtLoginFlag(AT_LOGIN_RENAME);
                    Send_Player(plr, MakeMsg("%s Has Requested You Change This Characters Name, Rename Will Be Forced On Next Login!", CD->USER.c_str()));
                }
                CharacterDatabase.PExecute("UPDATE `characters` SET `at_login` = `at_login` | '1' WHERE `guid` = '%u'", guid);
                Send_IRCA(ChanOrPM(CD), "\00313["+GetAcctNameFromID(account_id)+"] : Has Been Forced To Change Their Characters Name, Rename Will Be Forced On Next Login!", true, CD->TYPE);
            }
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : You Are Not A GM, You May Only Change Settings In Your Own Account.", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : No Such Player Exists, So Account Cannot Be Looked Up.", true, "ERROR");
}

void IRCCmd::Ban_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    if(_PARAMS[1] == "ip")
    {
        std::string ip = GetIPFromPlayer(_PARAMS[0]);
        if(_PARAMS[2] == "")
            _PARAMS[2] = "No Reason";
        if(ip != "")
        {
            loginDatabase.PExecute( "INSERT IGNORE INTO `ip_banned` VALUES ('%s', UNIX_TIMESTAMP(), UNIX_TIMESTAMP(), '%s', '%s')", ip.c_str(), CD->USER.c_str(), _PARAMS[2].c_str());
            if (Player* plr = GetPlayer(_PARAMS[0]))
                plr->GetSession()->KickPlayer();
            Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Had Their IP Address Banned. [%s] Reason: %s",_PARAMS[0].c_str() ,ip.c_str() , _PARAMS[2].c_str()), true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : I Cannot Locate An IP Address For The Character Name Given.", true, "ERROR");
    }
    if(_PARAMS[1] == "acct")
    {
        uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[0].c_str());
        uint32 acctid = objmgr.GetPlayerAccountIdByGUID(guid);
        if(_PARAMS[2] == "")
            _PARAMS[2] = "No Reason";
        if(acctid)
        {
            loginDatabase.PExecute( "INSERT INTO `account_banned` VALUES ('%u', UNIX_TIMESTAMP(), UNIX_TIMESTAMP(), '%s', '%s', 1)", acctid, CD->USER.c_str(), _PARAMS[2].c_str());
            if (Player* plr = GetPlayer(_PARAMS[0]))
                plr->GetSession()->KickPlayer();
            Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Had Their Account Banned. Reason: %s",_PARAMS[0].c_str(), _PARAMS[2].c_str()), true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : I Cannot Locate An Account For The Character Name Given.", true, "ERROR");
    }
    if(_PARAMS[1] == "unban")
    {
        std::string unbani = _PARAMS[0];
        if(atoi(unbani.c_str()) > 0)
        {
            loginDatabase.PExecute( "DELETE FROM ip_banned WHERE ip = '%s'", _PARAMS[0].c_str());
            Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Been Removed From The IP Ban List.", _PARAMS[0].c_str()), true, CD->TYPE);
        }
        else
        {
            QueryResult *result = loginDatabase.PQuery("SELECT id FROM `account` WHERE username = '%s'", _PARAMS[0].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string id = fields[0].GetCppString();

                loginDatabase.PExecute( "DELETE FROM account_banned WHERE id = %s", id.c_str());
                delete result;
                Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Been Removed From The Account Ban List.", _PARAMS[0].c_str()), true, CD->TYPE);

            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : I Cannot Locate An Account Or IP Address For The Paramaters Given.", true, "ERROR");
        }
    }
}

void IRCCmd::Chan_Control(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 2);
    if(CD->FROM == sIRC._Nick)
    {
        Send_IRCA(CD->USER, "\0034[ERROR] : You Cannot Use This Command Through A PM Yet.", true, "ERROR");
        return;
    }
    if(_PARAMS[0] == "op")
    {
        if(_PARAMS[1].length() > 1)
            sIRC.SendIRC("MODE "+CD->FROM+" +o "+_PARAMS[1] );
        else
            sIRC.SendIRC("MODE "+CD->FROM+" +o "+CD->USER );
    }
    if(_PARAMS[0] == "deop")
    {
        if(_PARAMS[1].length() > 1)
            sIRC.SendIRC("MODE "+CD->FROM+" -o "+_PARAMS[1] );
        else
            sIRC.SendIRC("MODE "+CD->FROM+" -o "+CD->USER );
    }
    if(_PARAMS[0] == "voice")
    {
        if(_PARAMS[1].length() > 1)
            sIRC.SendIRC("MODE "+CD->FROM+" +v "+_PARAMS[1] );
        else
            sIRC.SendIRC("MODE "+CD->FROM+" +v "+CD->USER );
    }
    if(_PARAMS[0] == "devoice")
    {
        if(_PARAMS[1].length() > 1)
            sIRC.SendIRC("MODE "+CD->FROM+" -v "+_PARAMS[1] );
        else
            sIRC.SendIRC("MODE "+CD->FROM+" -v "+CD->USER );
    }
}

void IRCCmd::Char_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 5);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    normalizePlayerName(_PARAMS[0]);
    uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[0]);
    Player* plr = objmgr.GetPlayer(guid);
    if(plr)
    {
        if(_PARAMS[1] == "mapcheat")
        {
            bool explore = false;
            if (_PARAMS[2] != "0")
                explore = true;
            for (uint8 i=0; i<64; i++)
            {
                if (_PARAMS[2] != "0")
                    plr->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
                else
                    plr->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0);
            }
            if(explore)
            {
                Send_Player(plr, MakeMsg("All Your Zones Have Been Set To Explored By: %s", CD->USER.c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Now Explored All Zones.", true, CD->TYPE);
            }
            else
            {
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Now Had All Zones Set To Un-Explored.", true, CD->TYPE);
                Send_Player(plr, MakeMsg("All Your Zones Have Been Set To Un-Explored By: %s", CD->USER.c_str()));
            }
        }
        if(_PARAMS[1] == "taxicheat")
        {
            if (_PARAMS[2] != "0")
            {
                plr->SetTaxiCheater(true);
                Send_Player(plr, MakeMsg("Taxi Node Cheat Has Been Enabled By: %s", CD->USER.c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Taxi Node Cheat Has Been Enabled.", true, CD->TYPE);
            }
            else
            {
                plr->SetTaxiCheater(false);
                Send_Player(plr, MakeMsg("Taxi Node Cheat Has Been Disabled By: %s", CD->USER.c_str()));
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Taxi Node Cheat Has Been Disabled.", true, CD->TYPE);
            }
        }
        if(_PARAMS[1] == "maxskill")
        {
            plr->UpdateSkillsToMaxSkillsForLevel();
            Send_Player(plr, MakeMsg("Your Skills Have Been Maxed Out By: %s", CD->USER.c_str()));
            Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Skills Have Been Maxed Out.", true, CD->TYPE);
        }
        if(_PARAMS[1] == "setskill")
        {
            std::string* _PARAMSA = getArray(_PARAMS[2], 4);
            uint32 skill = atoi(_PARAMS[2].c_str());
            uint32 level = atol(_PARAMS[3].c_str());
            int32 max   = _PARAMS[4].c_str() ? atol (_PARAMS[4].c_str()) : plr->GetPureMaxSkillValue(skill);
            SkillLineEntry const* skilllookup = sSkillLineStore.LookupEntry(skill);
            //if skillid entered is not a number and greater then 0 then the command is being used wrong
            if(skill >= 0)
            {
                //does the skill even exist
                if(skilllookup)
                {
                    //does player have the skill yet
                    if(plr->GetSkillValue(skill))
                    {
                        plr->SetSkill(skill,level,max);
                        Send_Player(plr, MakeMsg("Skill: %s Has Been Set To Level: %i Max: %i By: %s",skilllookup->name[0], level, max, CD->USER.c_str()));
                        Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Had Skill: %s Set To Level: %d Max: %d",_PARAMS[0].c_str() , skilllookup->name[0], level, max), true, CD->TYPE);
                    }
                    else
                        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Player Does Not Have The %s Skill Yet.", skilllookup->name[0]), true, "ERROR");
                }
                else
                    Send_IRCA(CD->USER, "\0034[ERROR] : That Skill ID Does Not Exist.", true, "ERROR");
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : The Skill ID Entered Is Invalid.", true, "ERROR");
        }
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : No Character With That Name Exists.", true, "ERROR");
}

void IRCCmd::Fun_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        if(_PARAMS[1] == "say")
        {
            plr->Say(_PARAMS[2], LANG_UNIVERSAL);
            Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Was Forced To Say: "+_PARAMS[2]+".", true, CD->TYPE);
        }
        if(_PARAMS[1] == "sound")
        {
            uint32 sndid = atoi(_PARAMS[2].c_str());
            plr->SendPlaySound(sndid ,true);
            Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Just Heard Sound ID: "+_PARAMS[2]+".", true, CD->TYPE);
        }
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Player Not Online!", true, "ERROR");
}

void IRCCmd::Help_IRC(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 1);
    QueryResult *result = WorldDatabase.PQuery("SELECT `Command`, `Description`, `gmlevel` FROM `IRC_Commands`");
    if(result)
    {
        if(IsLoggedIn(CD->USER))
        {
            if(_PARAMS[0] == "")
            {
                QueryResult *result = WorldDatabase.PQuery("SELECT * FROM `IRC_Commands` WHERE `gmlevel` <= %u ORDER BY `Command`", GetLevel(CD->USER));
                if(result)
                {
                    std::string output = "\002MangChat IRC Commands:\017 ";
                    for (uint64 i=0; i < result->GetRowCount(); i++)
                    {
                        Field *fields = result->Fetch();
                        output += fields[0].GetCppString() + ", ";
                        result->NextRow();
                    }
                    delete result;
                    Send_IRCA(CD->USER, output, true, CD->TYPE.c_str());
                }
            }
            else
            {
                QueryResult *result = WorldDatabase.PQuery("SELECT `Description`, `gmlevel` FROM `IRC_Commands` WHERE `Command` = '%s'", _PARAMS[0].c_str());
                if(result)
                {
                    Field *fields = result->Fetch();
                    if(fields[1].GetUInt32() > GetLevel(CD->USER))
                    {
                        Send_IRCA(CD->USER, "You Do Not Have Access To That Command, So No Help Is Available.", true, CD->TYPE.c_str());
                        return;
                    }
                    if(result)
                    {
                        std::string cmdhlp = fields[0].GetCppString();
                        delete result;
                        Send_IRCA(CD->USER, cmdhlp, true, CD->TYPE.c_str());
                    }
                }
                else
                    Send_IRCA(CD->USER, "\0034[ERROR] : No Such Command Exists, Please Check The Spelling And Try Again.", true, "ERROR");
            }
        }
        else if(!IsLoggedIn(CD->USER))
        {
            if(_PARAMS[0] == "")
            {
                QueryResult *result = WorldDatabase.PQuery("SELECT * FROM `IRC_Commands` WHERE `gmlevel` = 0 ORDER BY `Command`");
                if(result)
                {
                    std::string output = "\002MangChat IRC Commands:\017 ";
                    for (uint64 i=0; i < result->GetRowCount(); i++)
                    {
                        Field *fields = result->Fetch();
                        output += fields[0].GetCppString() + ", ";
                        result->NextRow();
                    }
                    delete result;
                    Send_IRCA(CD->USER, output, true, CD->TYPE.c_str());
                    Send_IRCA(CD->USER, "You Are Currently Not Logged In, Please Login To See A Complete List Of Commands Available To You.", true, CD->TYPE.c_str());
                }
            }
            else
            {
                QueryResult *result = WorldDatabase.PQuery("SELECT `Description`, `gmlevel` FROM `IRC_Commands` WHERE `Command` = '%s'", _PARAMS[0].c_str());
                if(result)
                {
                    Field *fields = result->Fetch();
                    if(fields[1].GetUInt32() > 0)
                    {
                        Send_IRCA(CD->USER, "You Do Not Have Access To That Command, So No Help Is Available.", true, CD->TYPE.c_str());
                        return;
                    }
                    std::string cmdhlp = fields[0].GetCppString();
                    delete result;
                    Send_IRCA(CD->USER, cmdhlp, true, CD->TYPE.c_str());
                }
                else
                    Send_IRCA(CD->USER, "\0034[ERROR] : No Such Command Exists, Please Check The Spelling And Try Again.", true, "ERROR");
            }
        }
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Database Error! Please Make Sure You Used IRC_Commands.sql, You Must Have A Table In Your World Database (IRC_Commands)!", true, "ERROR");
}

void IRCCmd::Inchan_Server(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 1);
    if(_PARAMS[0] == "")
    {
        Send_IRCA(CD->USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"inchan <ChannelName> )", true, "ERROR");
        return;
    }
    QueryResult *result = WorldDatabase.PQuery("SELECT * FROM `IRC_Inchan` WHERE `channel` = '%s' ORDER BY `name`", _PARAMS[0].c_str());
    if(result)
    {
        Field *fields = result->Fetch();
        std::string output = "\002Players In The [ "+fields[2].GetCppString()+" ] Channel:\017 ";
        for (uint64 i=0; i < result->GetRowCount(); i++)
        {
            output += fields[1].GetCppString() + ", ";
            result->NextRow();
        }
        delete result;
        Send_IRCA(ChanOrPM(CD), output, true, CD->TYPE);
    }
    else
        Send_IRCA(ChanOrPM(CD), "No Players Are Currently In [ "+_PARAMS[0]+" ] Channel!", true, CD->TYPE.c_str());
}

void IRCCmd::Info_Server(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 1);
    char clientsNum [50];
    sprintf(clientsNum, "%u", sWorld.GetActiveSessionCount());
    char maxClientsNum [50];
    sprintf(maxClientsNum, "%u", sWorld.GetMaxActiveSessionCount());
    std::string str = secsToTimeString(sWorld.GetUptime());
    std::string svnrev = _FULLVERSION;
    Send_IRCA(ChanOrPM(CD), "\x2 Number of players online:\x3\x31\x30 " + (std::string)clientsNum + "\xF |\x2 Max since last restart:\x3\x31\x30 "+(std::string)maxClientsNum+"\xF |\x2 Uptime:\x3\x31\x30 "+str, true, CD->TYPE);
    Send_IRCA(ChanOrPM(CD), "\x2 Trinity Core SVN revision:\x3\x31\x30 "+svnrev, true, CD->TYPE);
}

void IRCCmd::Item_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);

    normalizePlayerName(_PARAMS[0]);
    Player *chr = GetPlayer(_PARAMS[0].c_str());
    if(_PARAMS[1] == "add")
    {
        std::string s_param  = _PARAMS[2];

        char *args = (char*)s_param.c_str();
        uint32 itemId = 0;
        if(args[0]=='[')
        {
            char* citemName = citemName = strtok((char*)args, "]");
            if(citemName && citemName[0])
            {
                std::string itemName = citemName+1;
                WorldDatabase.escape_string(itemName);
                QueryResult *result = WorldDatabase.PQuery("SELECT entry FROM item_template WHERE name = '%s'", itemName.c_str());
                if (!result)
                {
                    Send_IRCA(CD->USER, "\0034[ERROR] : Item Not Found!", true, "ERROR");
                    return;
                }
                itemId = result->Fetch()->GetUInt16();
                delete result;
            }
            else
            {
                Send_IRCA(CD->USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"item <Player> <add> [Exact Item Name] <Amount> )", true, "ERROR");
                return;
            }
        }
        else
        {
            std::string itemName = s_param;
            WorldDatabase.escape_string(itemName);
            QueryResult *result = WorldDatabase.PQuery("SELECT entry FROM item_template WHERE name = '%s'", itemName.c_str());
            if (result)
            {
                itemId = result->Fetch()->GetUInt16();
            }
            delete result;

            char* cId = strtok(args, " ");
            if(!cId)
            {
                Send_IRCA(CD->USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"item <Player> <add> <ItemID> <Amount> )", true, "ERROR");
                return;
            }
            itemId = atol(cId);
        }
            char* ccount = strtok(NULL, " ");
            int32 count = 1;
            if (ccount) { count = atol(ccount); }
            Player* plTarget = chr;
        if(!plTarget)
        {
            Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Online!", true, "ERROR");
            return;
        }
        ItemPrototype const *pProto = objmgr.GetItemPrototype(itemId);
        //Subtract
        if (count < 0)
        {
            plTarget->DestroyItemCount(itemId, -count, true, false);
            char itemid2[255];
            sprintf(itemid2,"%d",itemId);
            std::string itake = " \00313["+ _PARAMS[0] +"] : Has Had Item " +itemid2+ " Taken From Them!";
            Send_IRCA(ChanOrPM(CD), itake, true, CD->TYPE);
            return;
        }
        //Adding items
        uint32 noSpaceForCount = 0;

        // check space and find places
        ItemPosCountVec dest;
        uint8 msg = plTarget->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount );
        if( msg == EQUIP_ERR_INVENTORY_FULL )                   // convert to possibel store amount
            count -= noSpaceForCount;
        else if( msg != EQUIP_ERR_OK )                          // other error, can't add
        {
            char s_countForStore[255];
            sprintf(s_countForStore,"%d",count);
            std::string ierror = " \00313["+ _PARAMS[0] +"] : Could Not Create All Items! " +s_countForStore+ " Item(s) Were Not Created!";
            Send_IRCA(ChanOrPM(CD), ierror, true, CD->TYPE);
            return;
        }
        Item* item = plTarget->StoreNewItem( dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
        if(count > 0 && item)
        {
                plTarget->SendNewItem(item,count,true,false);
                QueryResult *result = WorldDatabase.PQuery("SELECT name FROM item_template WHERE entry = %d", itemId);
                char* dbitemname = NULL;
                if (result)
                {
                    dbitemname = (char*)result->Fetch()->GetString();
                }
                std::string iinfo = " \00313[" + _PARAMS[0] + "] : Has Been Given Item "+dbitemname+". From: "+CD->USER.c_str()+".";
                Send_IRCA(ChanOrPM(CD), iinfo, true, CD->TYPE);
                delete result;
        }
        if(noSpaceForCount > 0)
        {
            char s_countForStore[255];
            sprintf(s_countForStore,"%d",noSpaceForCount);
            std::string ierror = " \00313["+ _PARAMS[0] +"] : Could Not Create All Items! " +s_countForStore+ " Item(s) Were Not Created!";
            Send_IRCA(ChanOrPM(CD), ierror, true, CD->TYPE);
            return;
        }
    }
    else
    {
        Send_IRCA(CD->USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"item <Player> <add> <ItemID> <Amount> )", true, "ERROR");
        return;
    }
}

void IRCCmd::Jail_Player(_CDATA *CD)
{
    if(ValidParams(CD->PARAMS, 1))
    {
        std::string* _PARAMS = getArray(CD->PARAMS, 2);
        if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
        {
            Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
            return;
        }
        if (Player *plr = GetPlayer(_PARAMS[0]))
        {
            std::string sReason = "";
            if(_PARAMS[1] == "release")
            {
                float rposx, rposy, rposz, rposo = 0;
                uint32 rmapid = 0;
                CharacterDatabase.escape_string(_PARAMS[0]);
                QueryResult *result = CharacterDatabase.PQuery( "SELECT `map`, `position_x`, `position_y`, `position_z` FROM `character_homebind` WHERE `guid` = '" I64FMTD "'", plr->GetGUID() );
                if(result)
                {
                    Field *fields = result->Fetch();
                    rmapid = fields[0].GetUInt16();
                    rposx = fields[1].GetFloat();
                    rposy = fields[2].GetFloat();
                    rposz = fields[3].GetFloat();
                    delete result;
                    plr->SetMovement(MOVE_UNROOT);
                    plr->TeleportTo(rmapid, rposx, rposy, rposz, rposo);
                    plr->RemoveAurasDueToSpell(42201);
                    plr->RemoveAurasDueToSpell(23775);
                    plr->RemoveAurasDueToSpell(9454);
                    Send_Player(plr, MakeMsg("You Have Been Released By: %s.", CD->USER.c_str()));
                    sReason = " \00313["+_PARAMS[0]+"] : Has Been Released By: "+CD->USER+".";
                    Send_IRCA(ChanOrPM(CD), sReason, true, CD->TYPE);
                }
            }
            else
            {
                if(_PARAMS[1] == "")
                    _PARAMS[1] = "No Reason Given.";
                plr->TeleportTo(13, 0, 0, 0, 0);
                plr->SetMovement(MOVE_ROOT);
                plr->CastSpell(plr, 42201, true);
                plr->CastSpell(plr, 23775, true);
                plr->CastSpell(plr, 9454, true);
                Send_Player(plr, MakeMsg("You Have Been Jailed By: %s. Reason: %s.", CD->USER.c_str(), _PARAMS[1].c_str()));
                sReason = " \00313["+_PARAMS[0]+"] : Has Been Jailed By: "+CD->USER+". Reason: "+_PARAMS[1]+".";
                Send_IRCA(ChanOrPM(CD), sReason, true, CD->TYPE);
            }
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Online!", true, "ERROR");
    }
}

void IRCCmd::Kick_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    if(_PARAMS[1] == "")
        _PARAMS[1] = "No Reason Given.";
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        plr->GetSession()->KickPlayer();
        Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Been Kicked By: "+CD->USER+". Reason: "+_PARAMS[1]+".", true, CD->TYPE);
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Online!", true, "ERROR");
}

void IRCCmd::Kill_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        if(plr->isAlive())
        {
            plr->DealDamage(plr, plr->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            plr->SaveToDB();
            if(_PARAMS[1] == "")
                _PARAMS[1] = "No Reason Given.";
            Send_IRCA(ChanOrPM(CD), MakeMsg("\00313[%s] : Has Been Killed By: %s.", _PARAMS[0].c_str(), CD->USER.c_str()) +  +  + " Reason: "+_PARAMS[1]+".", true, CD->TYPE);
            Send_Player(plr, MakeMsg("You Have Been Killed By: %s. Reason: %s.", CD->USER.c_str(), _PARAMS[1].c_str()));
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Already Dead!", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Online!", true, "ERROR");
}

void IRCCmd::Lookup_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
    if(_PARAMS[0] == "acct")
    {
        uint32 acctid = atoi(_PARAMS[1].c_str());
        if(objmgr.GetAccountByAccountName(_PARAMS[1]))
            acctid = objmgr.GetAccountByAccountName(_PARAMS[1]);
        if(acctid > 0)
        {       
            std::string DateTime = "%a, %b %d, %Y - %h:%i%p";
            QueryResult *result = loginDatabase.PQuery("SELECT id, username, gmlevel, last_ip, (SELECT banreason FROM account_banned WHERE id = %d LIMIT 1) as banned, (SELECT banreason FROM ip_banned WHERE ip = last_ip) as bannedip, DATE_FORMAT(last_login, '%s') FROM `account` WHERE id = %d", acctid, DateTime.c_str(), acctid, acctid);
            if(result)
            {
                Field *fields = result->Fetch();

                uint32 id = fields[0].GetUInt32();
                std::string usrname = fields[1].GetCppString();
                uint32 gm = fields[2].GetUInt32();
                std::string lastip = fields[3].GetCppString();
                std::string banreason = fields[4].GetCppString();
                std::string banreasonip = fields[5].GetCppString();
                std::string lastlogin = fields[6].GetCppString();
                delete result;

                QueryResult *chars = CharacterDatabase.PQuery("SELECT guid, name, (SELECT SUM(totaltime) FROM characters WHERE account = %d) AS tottime FROM characters WHERE account = %u", id, id);
                std::string characters = "None";
                std::string totaccttime = "Never Logged In";
                if(chars)
                {
                    characters = "";
                    Field *fields = chars->Fetch();
                    totaccttime = SecToDay(fields[2].GetCppString());
                    for (uint64 i=0; i < chars->GetRowCount(); i++)
                    {   
                        std::string guid = fields[0].GetCppString();
                        std::string charname = fields[1].GetCppString();
                        characters.append(charname+"("+guid+"), ");
                        chars->NextRow();
                    }
                    delete chars;
                }
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Username:\x3\x31\x30 %s \xF|\x2 AccountID:\x3\x31\x30 %d \xF|\x2 GM Level:\x3\x31\x30 %d \xF|\x2 Last IP:\x3\x31\x30 %s \xF|\x2 Last Login:\x3\x31\x30 %s", usrname.c_str(), id, gm, lastip.c_str(), lastlogin.c_str()), true, CD->TYPE);
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Total Play Time:\x3\x31\x30 %s \xF|\x2 Characters:\x3\x31\x30 %s ", totaccttime.c_str(), characters.c_str()), true, CD->TYPE);
                if(banreason.length() > 1)
                    Send_IRCA(ChanOrPM(CD), MakeMsg("\0034This User Has An Account Ban. Ban Reason: %s", banreason.c_str()), true, CD->TYPE);
                if(banreasonip.length() > 1)
                    Send_IRCA(ChanOrPM(CD), MakeMsg("\0034This User Has An IP Ban. Ban Reason: %s", banreasonip.c_str()), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Account ID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = loginDatabase.PQuery("SELECT id, username FROM `account` WHERE username LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string accts = "\002Account Search Results:\x3\x31\x30 ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string acctid = fields[0].GetCppString();
                    std::string acctname = fields[1].GetCppString();
                    accts.append(acctname+"("+acctid+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), accts, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Username. I Cant Find Any Users With Those Search Terms." ,true, "ERROR");
        }
    }   
    if(_PARAMS[0] == "char")
    {
        uint32 plguid = atoi(_PARAMS[1].c_str());
        if(objmgr.GetPlayerGUIDByName(_PARAMS[1].c_str()))
            plguid = objmgr.GetPlayerGUIDByName(_PARAMS[1].c_str());
        if(plguid > 0)
        {       
            QueryResult *result = CharacterDatabase.PQuery("SELECT guid, account, name, race, class, online, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 35), ' ' , -1) AS level, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 238), ' ' , -1) AS guildid, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 239), ' ' , -1) AS guildrank, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 927), ' ' , -1) AS xp, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 928), ' ' , -1) AS maxxp, SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ' , 1462), ' ' , -1) AS gold, SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ' , 1454), ' ' , -1) AS hk, SEC_TO_TIME(totaltime) AS tottime FROM characters WHERE guid =%i", plguid);
            uint32 latency = 0;
            Player *chr = objmgr.GetPlayer(plguid);
            if(chr) 
            {
                latency = chr->GetSession()->GetLatency();
            }
            char templatency [100];
            sprintf(templatency, "%ums", latency);
            if(result)
            {
                Field *fields = result->Fetch();
                std::string pguid = fields[0].GetCppString();
                std::string pacct = fields[1].GetCppString();
                std::string pname = fields[2].GetCppString();
                uint32 praceid = fields[3].GetUInt32();
                uint32 pclassid = fields[4].GetUInt32();
                std::string ponline = (fields[5].GetInt32() == 1 ? "\x3\x30\x33Online" : "\x3\x30\x34Offline\xF");
                std::string plevel = fields[6].GetCppString();
                uint32 pguildid = fields[7].GetUInt32();
                uint32 pguildrank = fields[8].GetUInt32();
                std::string pxp = fields[9].GetCppString();
                std::string pmaxxp = fields[10].GetCppString();
                unsigned int money = fields[11].GetInt32();
                std::string hk = fields[12].GetCppString();
                std::string totaltim = SecToDay(fields[13].GetCppString());
                delete result;
                std::string sqlquery = "SELECT `gmlevel` FROM `account` WHERE `id` = '" + pacct + "';";
                QueryResult *result = loginDatabase.Query(sqlquery.c_str());
                Field *fields2 = result->Fetch();
                std::string pgmlvl = fields2[0].GetCppString();
                delete result;
                std::string guildinfo = "";
                if (pguildid != 0)
                {
                    Guild* guild = objmgr.GetGuildById(pguildid);
                    if (guild)
                    {
                        guildinfo = " " + guild->GetRankName(pguildrank) + " Of " + guild->GetName();
                    }
                }
                else guildinfo = " None";
                ChrRacesEntry const* prace = sChrRacesStore.LookupEntry(praceid);
                ChrClassesEntry const* pclass = sChrClassesStore.LookupEntry(pclassid);

                if (atoi(plevel.c_str()) < sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL))
                    plevel += " (" + pxp + "/" + pmaxxp + ")";
                unsigned int gold = money / 10000;
                unsigned int silv = (money % 10000) / 100;
                unsigned int cop = (money % 10000) % 100;
                char tempgold [100];
                sprintf(tempgold, "\x2\x3\x30\x37%ug \x3\x31\x34%us \x3\x30\x35%uc\xF", gold, silv, cop);
                if (ponline == "\x3\x30\x33Online")
                {
                    Player * plr = ObjectAccessor::Instance().FindPlayerByName(pname.c_str());
                    if (plr)
                    {
                        AreaTableEntry const* area = GetAreaEntryByAreaID(plr->GetAreaId());
                        ponline += " in " + (std::string) area->area_name[sWorld.GetDefaultDbcLocale()];
                        if (area->zone != 0)
                        {
                            AreaTableEntry const* zone = GetAreaEntryByAreaID(area->zone);
                            ponline += " (" + (std::string)zone->area_name[sWorld.GetDefaultDbcLocale()] + ")";
                        }
                    }
                }
                std::string pinfo  = "\x2 About Player:\x3\x31\x30 " +pname+ "\xF |\x2 GM Level:\x3\x31\x30 " +pgmlvl+ "\xF |\x2 AcctID:\x3\x31\x30 " +pacct+ "\xF |\x2 CharID:\x3\x31\x30 " +pguid+ " \xF |\x2 Played Time:\x2\x3\x31\x30 " +totaltim+" \xF |\x2 Latency:\x2\x3\x31\x30 "+templatency;
                std::string pinfo2 = "\x2 Race:\x2\x3\x31\x30 " + (std::string)prace->name[sWorld.GetDefaultDbcLocale()] + "\xF |\x2 Class:\x2\x3\x31\x30 " + (std::string)pclass->name[sWorld.GetDefaultDbcLocale()] + "\xF |\x2 Level:\x2\x3\x31\x30 " + plevel + "\xF |\x2 Money:\x2 " + tempgold + "\xF |\x2 Guild Info:\x2\x3\x31\x30 "+guildinfo+"\xF |\x2 Status:\x2 " + ponline;
                //        pinfo3 = " :" + " \x2Honor Kills:\x2\x3\x31\x30 " + hk;
                Send_IRCA(ChanOrPM(CD),pinfo , true, CD->TYPE);
                Send_IRCA(ChanOrPM(CD),pinfo2 , true, CD->TYPE);
                //        Send_IRCA(ChanOrPM(CD),pinfo3 , true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Character ID. (GUID)" ,true, "ERROR");
        }
        else
        {
            QueryResult *result = CharacterDatabase.PQuery("SELECT guid, account, name FROM characters WHERE name LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string items = "\x2 Character Search Results:\x3\x31\x30 ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string guid = fields[0].GetCppString();
                    std::string account = fields[1].GetCppString();
                    std::string name = fields[2].GetCppString();
                    MakeUpper(name);
                    items.append(name+"(Account:"+account+" - GUID:"+guid+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), items, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Character. I Cant Find Any Characters With Those Search Terms." ,true, "ERROR");
        }
    }   
    if(_PARAMS[0] == "creature")
    {
        std::string creature = _PARAMS[1];
        if(atoi(creature.c_str()) > 0)
        {
            WorldDatabase.escape_string(_PARAMS[1]);
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, modelid_A, name, (minlevel*maxlevel/2) as level, faction_A, armor,  (SELECT count(*) FROM creature WHERE id = '%s') as spawns FROM creature_template WHERE entry = '%s';", _PARAMS[1].c_str(), _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();

                uint32 entry = fields[0].GetUInt32();
                uint32 modelid = fields[1].GetUInt32();
                std::string name = fields[2].GetCppString();
                uint32 level = fields[3].GetUInt32();
                uint32 faction = fields[4].GetUInt32();
                uint32 armor = fields[5].GetUInt32();
                uint32 spawns = fields[6].GetUInt32();
                delete result;

                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Name:\x3\x31\x30 %s \xF|\x2 CreatureID:\x3\x31\x30 %d \xF|\x2 DisplayID:\x3\x31\x30 %d \xF|\x2 Spawns:\x3\x31\x30 %d", name.c_str(), entry, modelid, spawns), true, CD->TYPE);
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Level:\x3\x31\x30 %d \xF|\x2 Faction:\x3\x31\x30 %d \xF|\x2 Armor:\x3\x31\x30 %d", level, faction, armor), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Creature ID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, name FROM creature_template WHERE name LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string items = "\002Creature Search Results:\x3\x31\x30 ";
                //Send_IRCA(ChanOrPM(CD), "", true, CD->TYPE);
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string CreatureID = fields[0].GetCppString();
                    std::string Name = fields[1].GetCppString();
                    items.append(Name+"("+CreatureID+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), items, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Creature. I Cant Find Any Creatures With Those Search Terms." ,true, "ERROR");
        }
    }
    if(_PARAMS[0] == "faction")
    {
        std::string faction = _PARAMS[1];
        if(atoi(faction.c_str()) > 0)
        {       
            FactionEntry const *factionEntry = sFactionStore.LookupEntry(atoi(faction.c_str()));
            if(factionEntry)
            {
                std::string name = factionEntry->name[sWorld.GetDefaultDbcLocale()];
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2 Faction:\x3\x31\x30 %s \xF|\x2 FactionID:\x3\x31\x30 %s",name.c_str(), faction.c_str()), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown FactionID." ,true, "ERROR");

        }
        else
        {
            uint32 counter = 0;
            std::string factions = "\002Faction Search Results:\x3\x31\x30 ";
            for (uint32 id = 0; id < sFactionStore.GetNumRows(); id++)
            {
                FactionEntry const *factionEntry = sFactionStore.LookupEntry(id);
                if(factionEntry)
                {
                    MakeLower( _PARAMS[1] );
                    std::string name = factionEntry->name[sWorld.GetDefaultDbcLocale()];
                    MakeLower( name );
                    if (name.find(_PARAMS[1]) != std::string::npos && counter < 10)
                    {
                        char factionid[100];
                        sprintf(factionid, "%d", id);
                        factions.append(name+"("+factionid+")\xF | \x3\x31\x30\x2");            
                        ++counter;                      
                    }
                }
            }
            if(counter == 0)
                factions.append("No Factions Found.");
            Send_IRCA(ChanOrPM(CD), factions, true, CD->TYPE);
        }
    }
    if(_PARAMS[0] == "go")
    {
        std::string gobject = _PARAMS[1];
        if(atoi(gobject.c_str()) > 0)
        {       
            WorldDatabase.escape_string(_PARAMS[1]);
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, type, displayId, name, faction, (SELECT count(*) FROM gameobject WHERE id = '%s') as spawns FROM gameobject_template WHERE entry = '%s';", _PARAMS[1].c_str(), _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();

                uint32 entry = fields[0].GetUInt32();
                uint32 type = fields[1].GetUInt32();
                uint32 modelid = fields[2].GetUInt32();
                std::string name = fields[3].GetCppString();
                uint32 faction = fields[4].GetUInt32();
                uint32 spawns = fields[5].GetUInt32();
                delete result;

                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2GO Name:\x3\x31\x30 %s \xF|\x2 GameobjectID:\x3\x31\x30 %d \xF|\x2 DisplayID:\x3\x31\x30 %d \xF|\x2 Spawns:\x3\x31\x30 %d", name.c_str(), entry, modelid, spawns), true, CD->TYPE);
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Type:\x3\x31\x30 %d \xF|\x2 Faction:\x3\x31\x30 %d", type, faction), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Creature ID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, name FROM gameobject_template WHERE name LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string gos = "\002Gameobject Search Results:\x3\x31\x30 ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string GOID = fields[0].GetCppString();
                    std::string GoName = fields[1].GetCppString();
                    gos.append(GoName+"("+GOID+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), gos, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Game Object. I Cant Find Any Game Object's With Those Search Terms." ,true, "ERROR");
        }
    }
    if(_PARAMS[0] == "item")
    {
        std::string item = _PARAMS[1];
        if(atoi(item.c_str()) > 0)
        {       
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, name, displayid, (SELECT count(*) FROM creature_loot_template WHERE item = '%s') as loot FROM `item_template` WHERE entry = %s", _PARAMS[1].c_str(), _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                QueryResult *result2 = CharacterDatabase.PQuery("SELECT count(*) FROM `character_inventory` WHERE item_template = %s", _PARAMS[1].c_str());
                Field *fields2 = result2->Fetch();
                uint32 charcnt = fields2[0].GetUInt32();
                delete result2;

                uint32 ItemID = fields[0].GetUInt32();
                std::string ItmName = fields[1].GetCppString();
                uint32 DisplayID = fields[2].GetUInt32();
                uint32 loots = 0;
                loots = fields[3].GetUInt32();
                delete result;
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Item:\x3\x31\x30 %s \xF|\x2 ItemID:\x3\x31\x30 %d \xF|\x2 DisplayID:\x3\x31\x30 %d \xF|\x2 Owned By:\x3\x31\x30 %d players \xF|\x2 Dropped By:\x3\x31\x30 %d creatures", ItmName.c_str(), ItemID, DisplayID, charcnt, loots), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown ItemID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, name FROM `item_template` WHERE name LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string items = "\002Item Search Results:\x3\x31\x30 ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string ItemID = fields[0].GetCppString();
                    std::string ItemName = fields[1].GetCppString();
                    items.append(ItemName+"("+ItemID+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), items, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Item. I Cant Find Any Items With Those Search Terms." ,true, "ERROR");
        }
    }
    if(_PARAMS[0] == "quest")
    {
        std::string quest = _PARAMS[1];
        if(atoi(quest.c_str()) > 0)
        {       
            WorldDatabase.escape_string(_PARAMS[1]);
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, Title FROM quest_template WHERE entry = '%s';", _PARAMS[1].c_str(), _PARAMS[1].c_str());
            if(result)
            {
                QueryResult *result2 = CharacterDatabase.PQuery("SELECT count(*) FROM character_queststatus WHERE quest = '%s' AND status = '1';", _PARAMS[1].c_str());
                Field *fields2 = result2->Fetch();
                uint32 status = fields2[0].GetUInt32();
                delete result2;

                Field *fields = result->Fetch();
                uint32 entry = fields[0].GetUInt32();
                std::string name = fields[1].GetCppString();
                delete result;
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Quest Name:\x3\x31\x30 %s \xF|\x2 QuestID:\x3\x31\x30 %d \xF|\x2 Completed:\x3\x31\x30 %d times", name.c_str(), entry, status), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Quest ID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT entry, Title FROM quest_template WHERE Title LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string quests = "\002Quest Search Results:\x3\x31\x30 ";
                //Send_IRCA(ChanOrPM(CD), "", true, CD->TYPE);
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {   
                    std::string QuestID = fields[0].GetCppString();
                    std::string QuestName = fields[1].GetCppString();
                    quests.append(QuestName+"("+QuestID+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                delete result;
                Send_IRCA(ChanOrPM(CD), quests, true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Quest. I Cant Find Any Quest's With Those Search Terms." ,true, "ERROR");
        }
    }
    if(_PARAMS[0] == "skill")
    {
        std::string skill = _PARAMS[1];
        if(atoi(skill.c_str()) > 0)
        {
            SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(atoi(skill.c_str()));
            if(skillInfo)
            {
                std::string name = skillInfo->name[sWorld.GetDefaultDbcLocale()];
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Skill:\x3\x31\x30 %s \xF|\x2 SkillID:\x3\x31\x30 %s",name.c_str(), skill.c_str()), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown SkillID." ,true, "ERROR");

        }
        else
        {
            uint32 counter = 0;
            std::string skills = "\002Skill Search Results:\x3\x31\x30 ";
            for (uint32 id = 0; id < sSkillLineStore.GetNumRows(); id++)
            {
                SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(id);
                if(skillInfo)
                {
                    MakeLower( _PARAMS[1] );
                    std::string name = skillInfo->name[sWorld.GetDefaultDbcLocale()];
                    MakeLower( name );
                    if (name.find(_PARAMS[1]) != std::string::npos && counter < 10)
                    {
                        char skillid[100];
                        sprintf(skillid, "%d", id);
                        skills.append(name+"("+skillid+")\xF | \x3\x31\x30\x2");
                        ++counter;
                    }
                }
            }
            if(counter == 0)
                skills.append("No Skills Found.");
            Send_IRCA(ChanOrPM(CD), skills, true, CD->TYPE);
        }
    }
    if(_PARAMS[0] == "spell")
    {
        std::string spell = _PARAMS[1];
        if(atoi(spell.c_str()) > 0)
        {
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(atoi(spell.c_str()));
            if(spellInfo)
            {
                std::string name = spellInfo->SpellName[sWorld.GetDefaultDbcLocale()];
                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Spell:\x3\x31\x30 %s \xF|\x2 SpellID:\x3\x31\x30 %s",name.c_str(), spell.c_str()), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown SpellID." ,true, "ERROR");

        }
        else
        {
            uint32 counter = 0;
            std::string spells = "\002Spell Search Results:\x3\x31\x30 ";
            for (uint32 id = 0; id < sSpellStore.GetNumRows(); id++)
            {
                SpellEntry const *spellInfo = sSpellStore.LookupEntry(id);
                if(spellInfo)
                {
                    MakeLower( _PARAMS[1] );
                    std::string name = spellInfo->SpellName[sWorld.GetDefaultDbcLocale()];
                    MakeLower( name );
                    if (name.find(_PARAMS[1]) != std::string::npos && counter < 10)
                    {
                        char itemid[100];
                        sprintf(itemid, "%d", id);
                        spells.append(name+"("+itemid+")\xF | \x3\x31\x30\x2");
                        ++counter;
                    }
                }
            }
            if(counter == 0)
                spells.append("No Spells Found.");
            Send_IRCA(ChanOrPM(CD), spells, true, CD->TYPE);
        }
    }
    if(_PARAMS[0] == "tele")
    {
        std::string tele = _PARAMS[1];
        if(atoi(tele.c_str()) > 0)
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT * FROM `game_tele` WHERE id = %s", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();

                uint32 teleid = fields[0].GetUInt32();
                uint32 pos_x = fields[1].GetUInt32();
                uint32 pos_y = fields[2].GetUInt32();
                uint32 pos_z = fields[3].GetUInt32();
                uint32 oriet = fields[4].GetUInt32();
                uint32 map = fields[5].GetUInt32();
                std::string telname = fields[6].GetCppString();
                delete result;

                Send_IRCA(ChanOrPM(CD), MakeMsg("\x2Tele Name:\x3\x31\x30 %s \xF|\x2 TeleID:\x3\x31\x30 %d \xF|\x2 Coordinates:\x3\x31\x30 [X: %d, Y: %d, Z: %d, MAP: %d, Orientation: %d]", telname.c_str(), teleid, pos_x, pos_y, pos_z, map, oriet), true, CD->TYPE);
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Teleport Location ID." ,true, "ERROR");
        }
        else
        {
            QueryResult *result = WorldDatabase.PQuery("SELECT id, name FROM `game_tele` WHERE name LIKE '%%%s%%' LIMIT 10", _PARAMS[1].c_str());
            if(result)
            {
                Field *fields = result->Fetch();
                std::string teles = "\002Tele Location Search Results:\x3\x31\x30 ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {
                    std::string TeleID = fields[0].GetCppString();
                    std::string TeleName = fields[1].GetCppString();
                    teles.append(TeleName+"("+TeleID+")\xF | \x3\x31\x30\x2");
                    result->NextRow();
                }
                Send_IRCA(ChanOrPM(CD), teles, true, CD->TYPE);
                delete result;
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Unknown Item. I Cant Find Any Items With Those Search Terms." ,true, "ERROR");
        }
    }
}

void IRCCmd::Level_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    std::string player  = _PARAMS[0];
    normalizePlayerName(player);
    uint64 guid = objmgr.GetPlayerGUIDByName(player.c_str());
    std::string s_newlevel  = _PARAMS[1];
    uint8 i_newlvl = atoi(s_newlevel.c_str());
    if(!guid)
    {
        Send_IRCA(CD->USER, "\0034[ERROR] : Player Not Found!", true, "ERROR");
        return;
    } else if ( i_newlvl < 1 || i_newlvl > sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL) )
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Level Must Be Between 1 And %i!",sConfig.GetIntDefault("MaxPlayerLevel", 70)), true, "ERROR");
        return;
    } else
    {
        Player *chr = objmgr.GetPlayer(guid);
        int32 i_oldlvl = chr ? chr->getLevel() : Player::GetUInt32ValueFromDB(UNIT_FIELD_LEVEL,guid);
        if(chr)
        {
            chr->GiveLevel(i_newlvl);
            chr->InitTalentForLevel();
            chr->SetUInt32Value(PLAYER_XP,0);
            WorldPacket data;
            ChatHandler CH(chr->GetSession());
            if(i_oldlvl == i_newlvl)
                CH.FillSystemMessageData(&data, "Your level progress has been reset.");
            else
            if(i_oldlvl < i_newlvl)
                CH.FillSystemMessageData(&data, fmtstring("You have been leveled up (%i)",i_newlvl-i_oldlvl));
            else
            if(i_oldlvl > i_newlvl)
                CH.FillSystemMessageData(&data, fmtstring("You have been leveled down (%i)",i_newlvl-i_oldlvl));
            chr->GetSession()->SendPacket( &data );
        }
        else
        {
            Tokens values;
            Player::LoadValuesArrayFromDB(values,guid);
            Player::SetUInt32ValueInArray(values,UNIT_FIELD_LEVEL,i_newlvl);
            Player::SetUInt32ValueInArray(values,PLAYER_XP,0);
            Player::SaveValuesArrayInDB(values,guid);
        }
    }
    Send_IRCA(ChanOrPM(CD), "\00313[" + _PARAMS[0]+ "] : Has Been Leveled To " + _PARAMS[1] + ". By: "+CD->USER+".", true, CD->TYPE);
}

void IRCCmd::Money_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 2);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    std::string player  = _PARAMS[0];
    normalizePlayerName(player);
    uint64 guid = objmgr.GetPlayerGUIDByName(player.c_str());
    Player *chr = objmgr.GetPlayer(guid);

    std::string s_money  = _PARAMS[1];
    int32 money = atoi(s_money.c_str());
    unsigned int gold = money / 10000;
    unsigned int silv = (money % 10000) / 100;
    unsigned int cop = (money % 10000) % 100;
    char tempgold [100];
    sprintf(tempgold, "\x2\x3\x30\x37%ug \x3\x31\x34%us \x3\x30\x35%uc\xF", gold, silv, cop);
    if(!guid)
    {
        Send_IRCA(CD->USER, "\0034[ERROR] : Player Not Found!", true, "ERROR");
        return;
    }
    else
    {
        Player *chr = objmgr.GetPlayer(guid);
        uint32 moneyuser = 0;
        if(chr)
            moneyuser = chr->GetMoney();
        else {
        CharacterDatabase.escape_string(player);
        std::string sqlquery = "SELECT SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ' , 1462), ' ' , -1) AS `gold` FROM `characters` WHERE `name` = '"+player+"';";
        QueryResult *result = CharacterDatabase.Query(sqlquery.c_str());
            Field *fields = result->Fetch();
            moneyuser = fields[0].GetInt32();
            delete result;
        }
            int32 addmoney = money;
            int32 newmoney = moneyuser + addmoney;
            char s_newmoney[255];
            sprintf(s_newmoney,"%d",newmoney);
            if(addmoney < 0)
            {
                sLog.outDetail("USER1: %i, ADD: %i, DIF: %i\\n", moneyuser, addmoney, newmoney);
                if(newmoney <= 0 )
                {
                    Send_IRCA(ChanOrPM(CD), "\00313["+player+"] : Has Had All Money Taken By: "+CD->USER.c_str()+".", true, CD->TYPE);
                    if(chr)
                    {
                        chr->SetMoney(0);
                        Send_Player(chr, MakeMsg("You Have Been Liquidated By: %s. Total Money Is Now 0.", CD->USER.c_str()));
                    }
                    else
                        CharacterDatabase.PExecute("UPDATE `characters` SET data=concat(substring_index(data,' ',1462-1),' ','%u',' ', right(data,length(data)-length(substring_index(data,' ',1462))-1) ) where guid='%u'",newmoney, guid );
                }
                else
                {
                    Send_IRCA(ChanOrPM(CD), "\00313["+player+"] : Has Had ("+s_money+"\00313) Taken From Them By: "+CD->USER.c_str()+".", true, CD->TYPE);
                    if(chr)
                    {
                        chr->SetMoney( newmoney );
                        Send_Player(chr, MakeMsg("You Have Had %s Copper Taken From You By: %s.", _PARAMS[1].c_str(), CD->USER.c_str()));
                    }
                    else
                        CharacterDatabase.PExecute("UPDATE `characters` SET data=concat(substring_index(data,' ',1462-1),' ','%u',' ', right(data,length(data)-length(substring_index(data,' ',1462))-1) ) where guid='%u'",newmoney, guid );
                }
            }
            else
            {
                Send_IRCA(ChanOrPM(CD), "\00313["+player+"] : Has Been Given ("+tempgold+"\00313) From: "+CD->USER.c_str()+".", true, CD->TYPE);
                if(chr)
                {
                    chr->ModifyMoney( addmoney );
                    Send_Player(chr, MakeMsg("You Have Been Given %s Copper. From: %s.", _PARAMS[1].c_str(), CD->USER.c_str()));
                }
                else
                    CharacterDatabase.PExecute("UPDATE `characters` SET data=concat(substring_index(data,' ',1462-1),' ','%u',' ', right(data,length(data)-length(substring_index(data,' ',1462))-1) ) where guid='%u'",newmoney, guid );
            }
    }
}

void IRCCmd::Mute_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    normalizePlayerName(_PARAMS[0]);
    uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[0]);
    if(guid)
    {
        if(_PARAMS[1] == "release")
        {
            Player* plr = objmgr.GetPlayer(guid);
            uint32 account_id = 0;
            account_id = objmgr.GetPlayerAccountIdByGUID(guid);
            loginDatabase.PExecute("UPDATE `account` SET `mutetime` = '0' WHERE `id` = '%u'", account_id );
            Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Been UnMuted By: "+CD->USER+"." , true, CD->TYPE);
            if(plr)
            {
                plr->GetSession()->m_muteTime = 0;
                Send_Player(plr, MakeMsg("You Have Been UnMuted By: %s.", CD->USER.c_str()));
            }
        }
        else
        {
            if(_PARAMS[2] == "")
                _PARAMS[2] = "No Reason Given";
            Player* plr = objmgr.GetPlayer(guid);
            time_t mutetime = time(NULL) + atoi(_PARAMS[1].c_str())*60;
            uint32 account_id = 0;
            account_id = objmgr.GetPlayerAccountIdByGUID(guid);
            if(plr) plr->GetSession()->m_muteTime = mutetime;
            loginDatabase.PExecute("UPDATE `account` SET `mutetime` = " I64FMTD " WHERE `id` = '%u'",uint64(mutetime), account_id );
            Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Been Muted By: "+CD->USER+". For: "+_PARAMS[1]+" Minutes. Reason: "+_PARAMS[2] , true, CD->TYPE);
            if(plr) Send_Player(plr, MakeMsg("You Have Been Muted By: %s. For: %s Minutes. Reason: %s", CD->USER.c_str(), _PARAMS[1].c_str(), _PARAMS[2].c_str()));
        }
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Player Does Not Exist!", true, "ERROR");
}

void IRCCmd::Online_Players(_CDATA *CD)
{
        sIRC.Script_Lock[MCS_Players_Online] = true;
        ZThread::Thread script(new mcs_OnlinePlayers(CD));
}

void IRCCmd::PM_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 2);
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        if(plr->isAcceptWhispers())
        {
            std::string sMsg = MakeMsg("|cffFE87FD[<IRC>%s] Whispers: %s|r", CD->USER.c_str(), _PARAMS[1].c_str());
            WorldPacket data(SMSG_MESSAGECHAT, 200);
            data << (uint8)CHAT_MSG_SYSTEM;
            data << (uint32)LANG_UNIVERSAL;
            data << (uint64)plr->GetGUID();
            data << (uint32)0;
            data << (uint64)plr->GetGUID();
            data << (uint32)(sMsg.length()+1);
            data << sMsg;
            data << (uint8)0;
            plr->GetSession()->SendPacket(&data);
            plr->SendPlaySound(3081, true);
            Send_IRCA(ChanOrPM(CD), "\00313To ["+_PARAMS[0]+"] : "+_PARAMS[1]+".", true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : Is Not Accepting Private Messages!", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Player not online!", true, "ERROR");
}

void IRCCmd::Revive_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        if(plr->isDead())
        {
            plr->ResurrectPlayer(0.5f);
            plr->SpawnCorpseBones();
            plr->SaveToDB();
            sIRC.Send_IRC_Channel(ChanOrPM(CD), " \00313["+_PARAMS[0]+"] : Has Been Revived By: " + CD->USER, true, CD->TYPE);
            Send_Player(plr, MakeMsg("You Have Been Revived By: %s.", CD->USER.c_str()));
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Dead!", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : "+_PARAMS[0]+" Is Not Online!", true, "ERROR");
}

void IRCCmd::Saveall_Player(_CDATA *CD)
{
    ObjectAccessor::Instance().SaveAllPlayers();
    Send_IRCA(ChanOrPM(CD), "\00313["+CD->USER+"] : Has Saved All Players!", true, CD->TYPE);
}

void IRCCmd::Shutdown_Mangos(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 1);
    if(_PARAMS[0] == "cancel")
    {
        sWorld.ShutdownCancel();
        Send_IRCA(ChanOrPM(CD), "\0034Server Shutdown Has Been Cancelled.", true, CD->TYPE);
    }

    int32 i_time = atoi(_PARAMS[0].c_str());
    if (i_time <= 0 && _PARAMS[0]!="0")
    {
        Send_IRCA(ChanOrPM(CD), "\00313["+CD->USER+"] : Please Enter A Number! And No Negative Numbers! "+_PARAMS[0]+" Seconds!?", true, CD->TYPE);
        return;
    }
    if (i_time > 1) Send_IRCA(ChanOrPM(CD), "\00313["+CD->USER+"] : Has Requested Server To Be Shut Down In "+_PARAMS[0]+" Seconds!", true, CD->TYPE);
    sWorld.ShutdownServ(i_time);
    Delay(i_time*1000);
    Send_IRCA(ChanOrPM(CD), "\0034Server Will Now Shut Down.. Good Bye!", true, CD->TYPE);
    sIRC.Active = false;
    sIRC.ResetIRC();
}

void IRCCmd::Spell_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 3);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    uint32 spell         = atoi(_PARAMS[2].c_str());
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell);
    if (Player* plr = GetPlayer(_PARAMS[0]))
    {
        if(spellInfo)
        {
            std::string name = spellInfo->SpellName[sWorld.GetDefaultDbcLocale()];
            if(_PARAMS[1] == "cast")
            {
                plr->CastSpell(plr, spell, true);
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Had Spell "+name+" Casted On Them.", true, CD->TYPE);
            }
            if(_PARAMS[1] == "learn")
            {
                plr->learnSpell(spell);
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Learned Spell "+name+".", true, CD->TYPE);
            }
            if(_PARAMS[1] == "unlearn")
            {
                plr->removeSpell(spell);
                Send_IRCA(ChanOrPM(CD), "\00313["+_PARAMS[0]+"] : Has Unlearned Spell "+name+".", true, CD->TYPE);
            }
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : Incorrect Spell ID!", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Player Not Online!", true, "ERROR");
}

void IRCCmd::Sysmsg_Server(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, CD->PCOUNT);
	std::string ircchan = "#";
	ircchan += sIRC._irc_chan[sIRC.anchn].c_str();
	if(_PARAMS[0] == "a")
    {
        //std::string str = "|cffff0000[System Message]:|r" + _PARAMS[1];
        std::string ancmsg = MakeMsg("\00304,08\037/!\\\037\017\00304 System Message \00304,08\037/!\\\037\017 %s",_PARAMS[1].c_str());
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, _PARAMS[1].c_str());
		sIRC.Send_IRC_Channel(ircchan, ancmsg, true);
    }
    else if (_PARAMS[0] == "e")
    {
        std::string str = "|cffff0000[Server Event]:|r " + _PARAMS[1];
        std::string notstr = "[Server Event]: " + _PARAMS[1];
        std::string notmsg = MakeMsg("\00304,08\037/!\\\037\017\00304 Server Event \00304,08\037/!\\\037\017 %s",_PARAMS[1].c_str());
        WorldPacket data(SMSG_NOTIFICATION, (notstr.size()+1));
        data << notstr;
        WorldPacket data2(SMSG_PLAY_SOUND,32);
        data2 << (uint32)1400;
        sWorld.SendGlobalMessage(&data2);
        sWorld.SendGlobalMessage(&data);
        sWorld.SendWorldText(LANG_EVENTMESSAGE, _PARAMS[1].c_str());
		sIRC.Send_IRC_Channel(ircchan, notmsg, true);
    }
    else if (_PARAMS[0] == "n")
    {
        std::string str = "Global notify: " + _PARAMS[1];
        std::string notmsg = MakeMsg("\00304,08\037/!\\\037\017\00304 Global Notify \00304,08\037/!\\\037\017 %s",_PARAMS[1].c_str());
        WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
        data << str;
        sWorld.SendGlobalMessage(&data);
		sIRC.Send_IRC_Channel(ircchan, notmsg, true);
    }
    else if (_PARAMS[0] == "add")
    {
        sIRC.Send_IRC_Channel(ircchan, "This command is currently borken.", true);
	// Commented for now -- timer broken
        //WorldDatabase.PExecute( "INSERT INTO IRC_AutoAnnounce (message, addedby) VALUES ('%s', '%s')", _PARAMS[1].c_str(), CD->USER.c_str());
        //std::string str = "|cffff0000[Automatic]:|r" + _PARAMS[1];
        //std::string ancmsg = MakeMsg("\00304,08\037/!\\\037\017\00304 Automatic System Message \00304,08\037/!\\\037\017 %s",_PARAMS[1].c_str());
        //sWorld.SendWorldText(LANG_AUTO_ANN, _PARAMS[1].c_str());
        //sIRC.Send_IRC_Channel(ircchan, ancmsg, true);
    }
    else if (_PARAMS[0] == "del")
    {
        WorldDatabase.PExecute( "DELETE FROM IRC_AutoAnnounce WHERE id = %s", _PARAMS[1].c_str());
        Send_IRCA(ChanOrPM(CD), MakeMsg("Deleted Automatic Announcement Message ID: %s", _PARAMS[1].c_str()), true, CD->TYPE);
    }
    else if (_PARAMS[0] == "list")
    {
        QueryResult *result = WorldDatabase.PQuery("SELECT * FROM IRC_AutoAnnounce LIMIT 5;", _PARAMS[1].c_str());
        if(result)
        {
            Field *fields = result->Fetch();
            for (uint64 i=0; i < result->GetRowCount(); i++)
            {
                std::string id = fields[0].GetCppString();
                std::string message = fields[1].GetCppString();
                std::string addedby = fields[2].GetCppString();
                Send_IRCA(ChanOrPM(CD), MakeMsg("ID: %s - Added By: %s - Message: %s", id.c_str(), addedby.c_str(), message.c_str()), true, CD->TYPE);
                result->NextRow();
            }
            delete result;
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : No Auto Announce Messages Are In The Database.", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Please Use (a-Announce)(n-Notify)(e-Event) As Second Parameter!", true, "ERROR");
}

void IRCCmd::Tele_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 4);
    if(AcctLevel(_PARAMS[0]) > GetLevel(CD->USER) && (sIRC.BOTMASK & 512)!= 0)
    {
        Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : Nice Try, This Player Has A Higher GM Level Than You! [ %i ]", AcctLevel(_PARAMS[0])), true, "ERROR");
        return;
    }
    bool DoTeleport = false;
    float pX, pY, pZ, pO = 0;
    uint32 mapid = 0;
    std::string rMsg = " \0034[ERROR] : Teleport Failed!";
    std::string wMsg = "Invalid Tele Location";
    Player* plr = GetPlayer(_PARAMS[0]);
    if(plr)
    {
        if(plr->isInFlight() || plr->isInCombat())
        {
            Send_IRCA(CD->USER, MakeMsg("\0034[ERROR] : %s Is Busy And Cannot Be Teleported! They Could Be In Combat, Or Flying.",_PARAMS[0].c_str()), true, "ERROR");
            return;
        }
    }
    if(_PARAMS[1] == "l" || _PARAMS[1].size() > 2)
    {
        if(_PARAMS[1].size() > 1)
            _PARAMS[2] = _PARAMS[1];
        WorldDatabase.escape_string(_PARAMS[2]);
        QueryResult *result = WorldDatabase.PQuery("SELECT position_x, position_y, position_z, orientation, map FROM game_tele WHERE name='%s';", _PARAMS[2].c_str());
        if (result)
        {
            Field *fields = result->Fetch();
            pX = fields[0].GetFloat();
            pY = fields[1].GetFloat();
            pZ = fields[2].GetFloat();
            pO = fields[3].GetFloat();
            mapid = fields[4].GetUInt16();
            delete result;
            rMsg = MakeMsg(" \00313[%s] : Teleported To %s! By: %s.",
                _PARAMS[0].c_str(),
                _PARAMS[2].c_str(),
                CD->USER.c_str());
            wMsg = MakeMsg("You Have Been Teleported To %s By: %s.",
                _PARAMS[2].c_str(),
                CD->USER.c_str());
            DoTeleport = true;
        }
        else
        {
            WorldDatabase.escape_string(_PARAMS[2]);
            QueryResult *result = WorldDatabase.PQuery("SELECT name FROM game_tele WHERE name LIKE '%%%s%%' LIMIT 7;", _PARAMS[2].c_str());
            if (result)
            {
                std::string telename = "<> ";
                for (uint64 i=0; i < result->GetRowCount(); i++)
                {
                    Field *fields = result->Fetch();
                    telename.append(fields[0].GetCppString());
                    result->NextRow();
                    telename.append(" <> ");
                }
                delete result;
                Send_IRCA(CD->USER, "I Cannot Find Location: "+_PARAMS[2]+" . Perhaps One Of These Will Work For You.", true, "ERROR");
                Send_IRCA(CD->USER, telename, true, "ERROR");
                return;
            }
            else
                Send_IRCA(CD->USER, "\0034[ERROR] : Location Not Found! Nothing Even Close Found!", true, "ERROR");
                return;
        }
    }
    else if(_PARAMS[1] == "c")
    {
        std::string* _PARAMSA = getArray(_PARAMS[2], 4);
        pX = atof(_PARAMSA[1].c_str());
        pY = atof(_PARAMSA[2].c_str());
        pZ = atof(_PARAMSA[3].c_str());
        mapid = atoi(_PARAMSA[0].c_str());
        rMsg = MakeMsg(" \00313[%s] : Teleported To Map: %s. Position: X(%s) Y(%s) Z(%s)! By: %s.",
            _PARAMS[0].c_str(),
            _PARAMSA[0].c_str(),
            _PARAMSA[1].c_str(),
            _PARAMSA[2].c_str(),
            _PARAMSA[3].c_str(),
            CD->USER.c_str());
        wMsg = MakeMsg("You Have Been Teleported To Map: %s. Position: X(%s) Y(%s) Z(%s)! By: %s.",
            _PARAMSA[0].c_str(),
            _PARAMSA[1].c_str(),
            _PARAMSA[2].c_str(),
            _PARAMSA[3].c_str(),
            CD->USER.c_str());
        DoTeleport = true;
    }
    else if(_PARAMS[1] == "r")
    {
        if(plr)
        {
            pX = plr->m_recallX;
            pY = plr->m_recallY;
            pZ = plr->m_recallZ;
            pO = plr->m_recallO;
            mapid = plr->m_recallMap;
            rMsg = MakeMsg(" \00313[%s] : Has Been Recalled To Their Previous Location.",
                _PARAMS[0].c_str());
            wMsg = MakeMsg("You Have Been Recalled To Your Previous Location. By: %s",
                CD->USER.c_str());
            DoTeleport = true;
        }
        else
        {
            Send_IRCA(CD->USER, MakeMsg("\00313[%s] : Cannot Be Recalled, They Are Not Online.", _PARAMS[0].c_str()), true, "ERROR");
            return;
        }

    }
    else if(_PARAMS[1] == "to")
    {
        Player* plr2 = GetPlayer(_PARAMS[2]);
        if(plr2)
        {
            plr2->GetContactPoint(plr, pX, pY, pZ);
            mapid = plr2->GetMapId();
        }
        else
        {
            if(uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[2].c_str()))
            {
                bool in_flight;
                Player::LoadPositionFromDB(mapid, pX, pY, pZ, pO, in_flight, guid);
            }
            else
            {
                Send_IRCA(CD->USER, "\0034[ERROR] : Second Player Not Found!", true, "ERROR");
                return;
            }
        }
        rMsg = MakeMsg(" \00313[%s] : Teleported To Player: [%s] By: %s.",
            _PARAMS[0].c_str(),
            _PARAMS[2].c_str(),
            CD->USER.c_str());
        wMsg = MakeMsg("You Are Being Teleported To: %s. By: %s.",
            _PARAMS[2].c_str(),
            CD->USER.c_str());
        DoTeleport = true;
    }
    if(DoTeleport)
    {
        if(MapManager::IsValidMapCoord(mapid, pX ,pY))
        {
            //if player is online teleport them in real time, if not set the DB to our coordinates.
            if(plr)
            {
                plr->SaveRecallPosition();
                plr->TeleportTo(mapid, pX, pY, pZ, pO);
                sIRC.Send_IRC_Channel(ChanOrPM(CD), rMsg, true, CD->TYPE);
                Send_Player(plr, wMsg);
            }
            else
            {
                uint64 guid = objmgr.GetPlayerGUIDByName(_PARAMS[0]);
                Player::SavePositionInDB(mapid,pX,pY,pZ,pO,MapManager::Instance().GetZoneId(mapid,pX,pY),guid);
                sIRC.Send_IRC_Channel(ChanOrPM(CD), rMsg + " \0034*Offline Tele.* ", true, CD->TYPE);
            }
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : Invalid Location!", true, "ERROR");
    }
    else
        Send_IRCA(CD->USER, "\0034[ERROR] : Invalid Paramaters, Please Try Again [ "+sIRC._cmd_prefx+"help tele ] For More Information. ", true, "ERROR");
}

void IRCCmd::Top_Player(_CDATA *CD)
{
    std::string* _PARAMS = getArray(CD->PARAMS, 2);
    uint32 limitr = 10;
    if(atoi(_PARAMS[1].c_str()) > 0 && GetLevel(CD->USER) >= sIRC._op_gm_lev)
        limitr = atoi(_PARAMS[1].c_str());
    if(_PARAMS[0] == "accttime")
    {
        QueryResult *result = CharacterDatabase.PQuery("SELECT account, name, (SUM(totaltime)) AS combinetime FROM characters GROUP BY account ORDER BY combinetime DESC LIMIT 0, %d ", limitr);
        if(result)
        {
            Field *fields = result->Fetch();
            std::string tptime = MakeMsg("\x2 Top%d Accounts By Played Time:\x3\x31\x30 ", limitr);
            for (uint64 i=0; i < result->GetRowCount(); i++)
            {
                uint32 account = fields[0].GetUInt32();
                std::string PlName = GetAcctNameFromID(account);
                std::string Time = SecToDay(fields[2].GetCppString());
                uint32 rank = i+1;
                tptime.append(MakeMsg("[%u]%s %s \xF| \x3\x31\x30\x2", rank, PlName.c_str(), Time.c_str()));
                result->NextRow();
            }
            delete result;
            Send_IRCA(ChanOrPM(CD), tptime, true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : No Accounts Returned." ,true, "ERROR");
    }
    if(_PARAMS[0] == "chartime")
    {
        QueryResult *result = CharacterDatabase.PQuery("SELECT name, totaltime FROM characters ORDER BY totaltime DESC LIMIT 0, %d ", limitr);
        if(result)
        {
            Field *fields = result->Fetch();
            std::string tptime = MakeMsg("\x2 Top%d Characters By Played Time:\x3\x31\x30 ", limitr);
            for (uint64 i=0; i < result->GetRowCount(); i++)
            {
                std::string Name = fields[0].GetCppString();
                std::string Time = SecToDay(fields[1].GetCppString());
                uint32 rank = i+1;
                tptime.append(MakeMsg("[%u]%s %s \xF| \x3\x31\x30\x2", rank, Name.c_str(), Time.c_str()));
                result->NextRow();
            }
            delete result;
            Send_IRCA(ChanOrPM(CD), tptime, true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : No Characters Returned." ,true, "ERROR");
    }
    if(_PARAMS[0] == "money")
    {
        QueryResult *result = CharacterDatabase.PQuery("SELECT name, CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 1462), ' ', -1) AS UNSIGNED) AS money FROM characters ORDER BY money DESC LIMIT 0, %d ", limitr);
        if(result)
        {
            Field *fields = result->Fetch();
            std::string tptime = MakeMsg("\x2 Top%d Characters By Money:\x3\x31\x30 ", limitr);
            for (uint64 i=0; i < result->GetRowCount(); i++)
            {
                std::string Name = fields[0].GetCppString();
                unsigned int money = fields[1].GetInt32();

                uint32 rank = i+1;

                unsigned int gold = money / 10000;
                unsigned int silv = (money % 10000) / 100;
                unsigned int cop = (money % 10000) % 100;
                char tempgold [100];
                sprintf(tempgold, "\x2\x3\x30\x37%ug \x3\x31\x34%us \x3\x30\x35%uc\xF", gold, silv, cop);

                tptime.append(MakeMsg("[%u]%s %s \xF| \x3\x31\x30\x2", rank, Name.c_str(), tempgold));
                result->NextRow();
            }
            delete result;
            Send_IRCA(ChanOrPM(CD), tptime, true, CD->TYPE);
        }
        else
            Send_IRCA(CD->USER, "\0034[ERROR] : No Characters Returned." ,true, "ERROR");
    }

}

void IRCCmd::Who_Logged(_CDATA *CD)
{
    std::string OPS = "";
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        OPS.append(MakeMsg(" \002[GM:%d IRC: %s - WoW: %s]\002 ", (*i)->GMLevel, (*i)->Name.c_str(), (*i)->UName.c_str()));
    }
    Send_IRCA(ChanOrPM(CD), OPS, true, CD->TYPE);
}
