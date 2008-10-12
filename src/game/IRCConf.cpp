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
#include "IRCClient.h"
#include "IRCCmd.h"
#include "../shared/Config/Config.h"
#include "IRCConf.h"
Config MCConfig;
void IRCClient::SetCfg(char const* cfgfile)
{
    sIRC.CfgFile = cfgfile;
}
bool IRCClient::LoadConfig(char const* cfgfile)
{
    if (!MCConfig.SetSource(cfgfile))
        sLog.outString("*** MangChat: Unable to open configuration file, All default options are being used.");
	else sLog.outString("*** MangChat: Found the configuration file, %s", cfgfile);

	int ConfCnt = 0;
    sIRC._chan_count = 0;
    if(MCConfig.GetIntDefault("irc.active", 1) == 1)
        sIRC.Active = true;
    else
        sIRC.Active = false;
    sIRC._Host = MCConfig.GetStringDefault("irc.host", "irc.freenode.net");
    if(sIRC._Host.size() > 0)
        ConfCnt++;
    sIRC._Mver = MCConfig.GetStringDefault("irc.mver", "Version 1.6.5");
	sIRC._Port = MCConfig.GetIntDefault("irc.port", 6667);
    sIRC._User = MCConfig.GetStringDefault("irc.user", "MangChat");
    sIRC._Pass = MCConfig.GetStringDefault("irc.pass", "MyDumbPass");
    sIRC._Nick = MCConfig.GetStringDefault("irc.nick", "MangChat");
    sIRC._Auth = MCConfig.GetIntDefault("irc.auth", 0);
	sIRC._Auth_Nick = MCConfig.GetStringDefault("irc.auth.nick", "AuthNick");
    sIRC._ICC = MCConfig.GetStringDefault("irc.icc", "001");
    sIRC._defchan = MCConfig.GetStringDefault("irc.defchan", "lobby");
    sIRC._ldefc = MCConfig.GetIntDefault("irc.ldef", 0);
    sIRC._wct = MCConfig.GetIntDefault("irc.wct", 30000);
   	sIRC.ajoin = MCConfig.GetIntDefault("irc.ajoin", 1);
    sIRC.ajchan = MCConfig.GetStringDefault("irc.ajchan", "world");
    sIRC.onlrslt = MCConfig.GetIntDefault("irc.online.result", 10);
    sIRC.BOTMASK = MCConfig.GetIntDefault("Botmask", 0);
    sIRC.logfile = MCConfig.GetStringDefault("irc.logfile.prefix", "IRC_");
	for(int i = 1; i < MAX_CONF_CHANNELS;i++)
    {
        std::ostringstream ss;
        ss << i;
        std::string ci = "irc.chan_" + ss.str();
        std::string t_chan = MCConfig.GetStringDefault(ci.c_str(), "");
        if(t_chan.size() > 0)
        {
            sIRC._chan_count++;
            sIRC._irc_chan[sIRC._chan_count] = t_chan;
            ci = "wow.chan_" + ss.str();
            sIRC._wow_chan[sIRC._chan_count] = MCConfig.GetStringDefault(ci.c_str(), t_chan.c_str());
        }
    }
    sIRC.JoinMsg = MCConfig.GetStringDefault("irc.joinmsg", "Whhaaazzzzaaaa, MangChat $Ver Baby!!");
    sIRC.RstMsg  = MCConfig.GetStringDefault("irc.rstmsg", "MangChat Is Restarting, I Will Be Right Back!");
    sIRC.kikmsg = MCConfig.GetStringDefault("irc.kickmsg", "Do Not Kick Me Again, Severe Actions Will Be Taken!");
    // IRC LINES
    sIRC.ILINES[WOW_IRC] = MCConfig.GetStringDefault("chat.wow_irc", "\003<WoW>[\002$Name($Level)\002\003] $Msg");
    sIRC.ILINES[IRC_WOW] = MCConfig.GetStringDefault("chat.irc_wow", "\003<IRC>[$Name]: $Msg");
    sIRC.ILINES[JOIN_WOW] = MCConfig.GetStringDefault("chat.join_wow", "\00312>>\00304 $Name \003Joined The Channel!");
    sIRC.ILINES[JOIN_IRC] = MCConfig.GetStringDefault("chat.join_irc", "\003[$Name]: Has Joined IRC!");
    sIRC.ILINES[LEAVE_WOW] = MCConfig.GetStringDefault("chat.leave_wow", "\00312<<\00304 $Name \003Left The Channel!");
    sIRC.ILINES[LEAVE_IRC] = MCConfig.GetStringDefault("chat.leave_irc", "\003[$Name]: Has Left IRC!");
    sIRC.ILINES[CHANGE_NICK] = MCConfig.GetStringDefault("chat.change_nick", "\003<> $Name Is Now Known As $NewName!");
    // MangChat Options
    sIRC._MCA = MCConfig.GetIntDefault("irc.maxattempt", 10);
    sIRC._autojoinkick = MCConfig.GetIntDefault("irc.autojoin_kick", 1);
    sIRC._cmd_prefx = MCConfig.GetStringDefault("irc.command_prefix", ".");
	
	sIRC._op_gm = MCConfig.GetIntDefault("irc.op_gm_login", 0);
	sIRC._op_gm_lev = MCConfig.GetIntDefault("irc.op_gm_level", 3);

    // Misc Options
    sIRC.games = MCConfig.GetIntDefault("irc.fun.games", 0);
	sIRC.gmlog = MCConfig.GetIntDefault("irc.gmlog", 1);
	sIRC.BOTMASK = MCConfig.GetIntDefault("BotMask", 0);
    sIRC.Status = MCConfig.GetIntDefault("irc.StatusChannel", 1);
	sIRC.anchn = MCConfig.GetIntDefault("irc.AnnounceChannel", 1);
	sIRC.autoanc = MCConfig.GetIntDefault("irc.auto.announce", 30);
	sIRC.ojGM1 = MCConfig.GetStringDefault("irc.gm1", "[Moderator]");
    sIRC.ojGM2 = MCConfig.GetStringDefault("irc.gm2", "[Game Master]");
    sIRC.ojGM3 = MCConfig.GetStringDefault("irc.gm3", "[BugTracker]");
    sIRC.ojGM4 = MCConfig.GetStringDefault("irc.gm4", "[DevTeam Admin]");
    sIRC.ojGM5 = MCConfig.GetStringDefault("irc.gm5", "[Root Admin]");
    // REQUIRED GM LEVEL
    QueryResult *result = WorldDatabase.PQuery("SELECT `Command`, `gmlevel` FROM `IRC_Commands` ORDER BY `Command`");
    if(result)
    {
        Field *fields = result->Fetch();
        for (uint64 i=0; i < result->GetRowCount(); i++)
        {
            std::string command = fields[0].GetCppString();
            uint32 gmlvl = fields[1].GetUInt32();
            if(command == "acct") sIRC.CACCT = gmlvl;
			if(command == "ban") sIRC.CBAN = gmlvl;
			if(command == "char") sIRC.CCHAN = gmlvl;
			if(command == "char") sIRC.CCHAR = gmlvl;
            if(command == "fun") sIRC.CFUN = gmlvl;
			if(command == "help") sIRC.CHELP = gmlvl;
			if(command == "inchan") sIRC.CINCHAN = gmlvl;
			if(command == "info") sIRC.CINFO = gmlvl;
            if(command == "item") sIRC.CITEM = gmlvl;
            if(command == "jail") sIRC.CJAIL = gmlvl;
            if(command == "kick") sIRC.CKICK = gmlvl;
            if(command == "kill") sIRC._KILL = gmlvl;
            if(command == "level") sIRC.CLEVEL = gmlvl;
			if(command == "lookup") sIRC.CLOOKUP = gmlvl;
            if(command == "money") sIRC.CMONEY = gmlvl;
            if(command == "mute") sIRC.CMUTE = gmlvl;
			if(command == "online") sIRC.CONLINE = gmlvl;
            if(command == "pm") sIRC.CPM = gmlvl;
            if(command == "restart") sIRC.CRESTART = gmlvl;
            if(command == "revive") sIRC.CREVIVE = gmlvl;
            if(command == "saveall") sIRC.CSAVEALL = gmlvl;
            if(command == "shutdown") sIRC.CSHUTDOWN = gmlvl;
            if(command == "spell") sIRC.CSPELL = gmlvl;
            if(command == "sysmsg") sIRC.CSYSMSG = gmlvl;
            if(command == "tele") sIRC.CTELE = gmlvl;
			if(command == "top") sIRC.CTOP = gmlvl;
            if(command == "who") sIRC.CWHO = gmlvl;
            result->NextRow();
        }
        delete result;
    }
    else
    {
        sIRC.CACCT     = 3;
        sIRC.CBAN      = 3;
        sIRC.CCHAN     = 3;
        sIRC.CCHAR     = 3;
        sIRC.CFUN      = 3;
        sIRC.CHELP     = 3;
        sIRC.CINCHAN   = 3;
        sIRC.CINFO     = 3;
        sIRC.CITEM     = 3;
        sIRC.CJAIL     = 3;
        sIRC.CKICK     = 3;
        sIRC._KILL     = 3;
        sIRC.CLEVEL    = 3;
        sIRC.CLOOKUP   = 3;
        sIRC.CMONEY    = 3;
        sIRC.CMUTE     = 3;
        sIRC.CONLINE   = 3;
        sIRC.CPM       = 3;
        sIRC.CRESTART  = 3;
        sIRC.CREVIVE   = 3;
        sIRC.CSAVEALL  = 3;
        sIRC.CSHUTDOWN = 3;
        sIRC.CSPELL    = 3;
        sIRC.CSYSMSG   = 3;
        sIRC.CTELE     = 3;
        sIRC.CTOP      = 3;
        sIRC.CWHO      = 3;
    }
    return true;
}

std::string IRCClient::GetChatLine(int nItem)
{
    return sIRC.ILINES[nItem];
}
