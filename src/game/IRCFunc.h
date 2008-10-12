#ifndef _IRC_CLIENT_FUNC
#define _IRC_CLIENT_FUNC

std::string GetUser(std::string szU)
{
    int pos = szU.find("!");
    return szU.substr(0, pos);
}
// Delink will remove anything considered "non chat" from a string
// Linked items (items that players can click on to see a description)
// contain extra characters wich the client filter out, this function
// makes sure people on irc do not see those characters.
std::string Delink(std::string msg)
{
    std::size_t pos;
    while((pos = msg.find("|Hitem")) != std::string::npos)
    {
        std::size_t find1 = msg.find("|h", pos);
		std::size_t find2 = msg.find("|h", find1 + 2);
        msg.replace(pos, find1 - pos + 2, "\x2");
        msg.replace(msg.find("|h", pos), 2, "\x2");
    }
    while((pos = msg.find("|Henchant")) != std::string::npos)
    {
        std::size_t find1 = msg.find("|h", pos);
        std::size_t find2 = msg.find("|h", find1 + 2);
        msg.replace(pos, find1 - pos + 2, "\x2");
        msg.replace(msg.find("|h", pos), 2, "\x2");
		//msg.replace(find2, 2, "\x2");
    }
    return msg;
}

// This function converts the characters used by the client to identify colour to IRC format.
std::string WoWcol2IRC(std::string msg)
{
    std::size_t pos;
    char IRCCol[9][4] = { "\xF", "\xF", "\x3\x31\x34", "\x3\x30\x33", "\x3\x31\x32", "\x3\x30\x36", "\x3\x30\x37", "\x3\x30\x34", "\x3\x30\x37"};
    char WoWCol[9][12] = { "|r", "|cffffffff", "|cff9d9d9d", "|cff1eff00", "|cff0070dd", "|cffa335ee", "|cffff8000", "|cffe6cc80", "|cffffd000"};
    for (int i=0; i<=8; i++)
    {
        while ((pos = msg.find(WoWCol[i])) != std::string::npos)
        {
            if (i == 0)
                msg.replace(pos, 2, IRCCol[i]);
            else
                msg.replace(pos, 10, IRCCol[i]);
        }
    }
    return msg;
}

// This function converts the characters used by IRC to identify colour to a format the client can understand.
std::string IRCcol2WoW(std::string msg)
{
    std::size_t pos;
    char IRCCol[16][4] = { "\x3\x30", "\x3\x31", "\x3\x32", "\x3\x33", "\x3\x34", "\x3\x35", "\x3\x36", "\x3\x37", "\x3\x38", "\x3\x39", "\x3\x31\x30", "\x3\x31\x31", "\x3\x31\x32", "\x3\x31\x33", "\x3\x31\x34", "\x3\x31\x35"};
    char IRCCol2[10][4] = { "\x3\x30\x30", "\x3\x30\x31", "\x3\x30\x32", "\x3\x30\x33", "\x3\x30\x34", "\x3\x30\x35", "\x3\x30\x36", "\x3\x30\x37", "\x3\x30\x38", "\x3\x30\x39"};
    char WoWcol[16][12] = { "|cffffffff", "|cff000000", "|cff00007f", "|cff009300", "|cffff0000", "|cff7f0000", "|cff9c009c", "|cfffc9300", "|cffffff00", "|cff00fc00", "|cff009393", "|cff00ffff", "|cff0000fc", "|cffff00ff", "|cff7f7f7f", "|cffd2d2d2"};
    for (int i=15; i>=0; i--)
    {
        if (i<10)
        {
            while ((pos = msg.find(IRCCol2[i])) != std::string::npos)
            {
                msg.replace(pos, 3, WoWcol[i]);
            }
            while ((pos = msg.find(IRCCol[i])) != std::string::npos)
            {
                msg.replace(pos, 2, WoWcol[i]);
            }

        }
        else
        {
            while ((pos = msg.find(IRCCol[i])) != std::string::npos)
            {
                msg.replace(pos, 3, WoWcol[i]);
            }
        }

        // Remove Bold, Reverse, Underline from IRC
        char Checker[3][3] = {"\x2","\x16","\x1F"}; // This is the Hex part not Dec. In Decimal its (2,22,31)
        for(int I=0; I < 3; I++)
        {
            while ((pos = msg.find(Checker[I])) != std::string::npos)
            {	
                msg.replace(pos, 1, "");
            }
        }
        // Finished Removing !

    }

    while ((pos = msg.find("\x3")) != std::string::npos)
    {
        msg.replace(pos, 1, "|r");
    }
    while ((pos = msg.find("\xF")) != std::string::npos)
    {
        msg.replace(pos, 1, "|r");
    }

    return msg;
}

// This function compares 2 strings
int nocase_cmp(const string & s1, const string& s2)
{
    string::const_iterator it1=s1.begin();
    string::const_iterator it2=s2.begin();

    //stop when either string's end has been reached
    while ( (it1!=s1.end()) && (it2!=s2.end()) )
    {
        if(::toupper(*it1) != ::toupper(*it2))              //letters differ?
            // return -1 to indicate smaller than, 1 otherwise
            return (::toupper(*it1)  < ::toupper(*it2)) ? -1 : 1;
        //proceed to the next character in each string
        ++it1;
        ++it2;
    }
    size_t size1=s1.size(), size2=s2.size();                // cache lengths
    //return -1,0 or 1 according to strings' lengths
    if (size1==size2)
        return 0;
    return (size1<size2) ? -1 : 1;
}

std::string MakeMsgA(const char *sLine, ... )
{
    va_list ap;
    char tmpoutp[1024];
    va_start(ap, sLine);
    vsnprintf(tmpoutp, 1024, sLine, ap );
    va_end(ap);
    std::string outp = tmpoutp;
    return outp;
}

std::string MakeMsgP(int CLINE, std::string Msg, Player *plr)
{
    //	std::string ChatTag = "";
    //	switch (plr->GetTeam())
    //	{
    //		case 67:ChatTag.append("4");break; //horde
    //		case 469:ChatTag.append("12");break; //alliance
    //	}
    std::string sMsg = sIRC.MakeMsg(sIRC.GetChatLine(CLINE), "$Msg", Msg);
    //	sMsg = ChatTag + MakeMsg(sMsg, "$Name", plr->GetName());
    if (plr->GetTeam() == 67)
        sMsg = sIRC.MakeMsg(sMsg, "$Name", MakeMsgA("\0034%s\003", plr->GetName()));
    else if (plr->GetTeam() == 469)
        sMsg = sIRC.MakeMsg(sMsg, "$Name", MakeMsgA("\00312%s\003", plr->GetName()));
    if(plr->isAFK())
        sMsg = sIRC.MakeMsg(sMsg, "$Tag", "<AFK>");
    else if(plr->isDND())
        sMsg = sIRC.MakeMsg(sMsg, "$Tag", "<DND>");
    else
        sMsg = sIRC.MakeMsg(sMsg, "$Tag", "");
    sMsg = sIRC.MakeMsg(sMsg, "$Level", MakeMsgA("%d", plr->getLevel()));
    sMsg = Delink(sMsg);
    sMsg = WoWcol2IRC(sMsg);
    return sMsg;
}

/*
std::string MakeMsg(std::string msg, std::string var, int val)
{
    std::ostringstream ss;
    ss << val;

    std::string nval = ss.str();
    std::size_t start = msg.find(var);
    if (start != std::string::npos)
        msg.replace(start, var.length(), val);
    return msg;
}
*/
/*
std::string MakeMsg(const char *sLine, ... )
{
    va_list ap;
    char tmpoutp[1024];
    va_start(ap, sLine);
    vsnprintf(tmpoutp, 1024, sLine, ap );
    va_end(ap);
    std::string outp = tmpoutp;
    return outp;
}
*/

// This function checks if a channel exists in out configuration
// Mangchat supports as many channels as you like
// However the default has been set to 10
// if you wish to increase this you must edit the:
// MAX_CONF_CHANNELS variable in IRCClient.h
bool Channel_Valid(std::string Channel)
{
    for(int i=1;i < sIRC._chan_count + 1;i++)
    {
        if(nocase_cmp(sIRC._wow_chan[i], Channel)==0)
            return true;
    }
    return false;
}

std::string GetWoWChannel(std::string Channel)
{
    for(int i=1;i < sIRC._chan_count + 1;i++)
    {
        if("#" + sIRC._irc_chan[i] == Channel)
            return sIRC._wow_chan[i];
    }
    return "";
}

std::string GetIRCChannel(std::string Channel)
{
    for(int i=1;i < sIRC._chan_count + 1;i++)
    {
        if(sIRC._wow_chan[i] == Channel)
            return sIRC._irc_chan[i];
    }
    return "";
}

std::string* getArray(std::string PARAMS, int nCount, std::string )
{
    std::string *array = new std::string[nCount];
    if(PARAMS.size() > 0)
    {
        int pcnt = 0;
        size_t ps = 0;
        size_t pc = -1;
        for(int i = 0;i < nCount;i++)
        {
            pc = PARAMS.find(" ", pc + 1);
            if(i + 1 == nCount && nCount != 1)
            {
                if(ps > 0 && pc > 0)
                    array[i] = PARAMS.substr(ps, PARAMS.size() - ps);
            }
            else
                array[i] = PARAMS.substr(ps, pc - ps);
            ps = pc + 1;
        }
    }
    return array;
}
#endif
