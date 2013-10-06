/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: ah_bot_commandscript
%Complete: 100
Comment: All ah_bot related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "AuctionHouseBot.h"

class ah_bot_commandscript : public CommandScript
{
public:
    ah_bot_commandscript() : CommandScript("ah_bot_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand commandTable[] =
        {
            { "ahbotoptions",   SEC_GAMEMASTER,     true,   &HandleAHBotOptionsCommand,     "", NULL },
            { NULL,             0,                  false,  NULL,                           "", NULL }
        };
        return commandTable;
    }

    static bool HandleAHBotOptionsCommand(ChatHandler* handler, const char*args)
    {
        uint32 ahMapID = 0;
        char* opt = strtok((char*)args, " ");
        char* ahMapIdStr = strtok(NULL, " ");

        if (ahMapIdStr)
        {
            ahMapID = uint32(strtoul(ahMapIdStr, NULL, 0));
            switch (ahMapID)
            {
                case 2:
                case 6:
                case 7:
                    break;
                default:
                    opt = NULL;
                    break;
            }
        }

        if (!opt)
        {
            handler->PSendSysMessage("Syntax is: ahbotoptions $option $ahMapID (2, 6 or 7) $parameter");
            handler->PSendSysMessage("Try ahbotoptions help to see a list of options.");
            return false;
        }

        int l = strlen(opt);

        if (strncmp(opt, "help", l) == 0)
        {
            handler->PSendSysMessage("AHBot commands:");
            handler->PSendSysMessage("ahexpire");
            handler->PSendSysMessage("minitems");
            handler->PSendSysMessage("maxitems");
            //handler->PSendSysMessage("");
            //handler->PSendSysMessage("");
            handler->PSendSysMessage("percentages");
            handler->PSendSysMessage("minprice");
            handler->PSendSysMessage("maxprice");
            handler->PSendSysMessage("minbidprice");
            handler->PSendSysMessage("maxbidprice");
            handler->PSendSysMessage("maxstack");
            handler->PSendSysMessage("buyerprice");
            handler->PSendSysMessage("bidinterval");
            handler->PSendSysMessage("bidsperinterval");
            return true;
        }
        else if (strncmp(opt, "ahexpire", l) == 0)
        {
            if (!ahMapIdStr)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions ahexpire $ahMapID (2, 6 or 7)");
                return false;
            }

            auctionbot.Commands(0, ahMapID, NULL, NULL);
        }
        else if (strncmp(opt, "minitems", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            if (!ahMapIdStr || !param1)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions minitems $ahMapID (2, 6 or 7) $minItems");
                return false;
            }

            auctionbot.Commands(1, ahMapID, NULL, param1);
        }
        else if (strncmp(opt, "maxitems", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            if (!ahMapIdStr || !param1)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxitems $ahMapID (2, 6 or 7) $maxItems");
                return false;
            }

            auctionbot.Commands(2, ahMapID, NULL, param1);
        }
        else if (strncmp(opt, "mintime", l) == 0)
        {
            handler->PSendSysMessage("ahbotoptions mintime has been deprecated");
            return false;
            /*
            char* param1 = strtok(NULL, " ");
            if (!ahMapIdStr || !param1)
            {
                PSendSysMessage("Syntax is: ahbotoptions mintime $ahMapID (2, 6 or 7) $mintime");
                return false;
            }

            auctionbot.Commands(3, ahMapID, NULL, param1);
            */
        }
        else if (strncmp(opt, "maxtime", l) == 0)
        {
            handler->PSendSysMessage("ahbotoptions maxtime has been deprecated");
            return false;
            /*
            char* param1 = strtok(NULL, " ");
            if (!ahMapIdStr || !param1)
            {
                PSendSysMessage("Syntax is: ahbotoptions maxtime $ahMapID (2, 6 or 7) $maxtime");
                return false;
            }

            auctionbot.Commands(4, ahMapID, NULL, param1);
            */
        }
        else if (strncmp(opt, "percentages", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");
            char* param3 = strtok(NULL, " ");
            char* param4 = strtok(NULL, " ");
            char* param5 = strtok(NULL, " ");
            char* param6 = strtok(NULL, " ");
            char* param7 = strtok(NULL, " ");
            char* param8 = strtok(NULL, " ");
            char* param9 = strtok(NULL, " ");
            char* param10 = strtok(NULL, " ");
            char* param11 = strtok(NULL, " ");
            char* param12 = strtok(NULL, " ");
            char* param13 = strtok(NULL, " ");
            char* param14 = strtok(NULL, " ");

            if (!ahMapIdStr || !param14)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions percentages $ahMapID (2, 6 or 7) $1 $2 $3 $4 $5 $6 $7 $8 $9 $10 $11 $12 $13 $14");
                handler->PSendSysMessage("1 GreyTradeGoods 2 WhiteTradeGoods 3 GreenTradeGoods 4 BlueTradeGoods 5 PurpleTradeGoods");
                handler->PSendSysMessage("6 OrangeTradeGoods 7 YellowTradeGoods 8 GreyItems 9 WhiteItems 10 GreenItems 11 BlueItems");
                handler->PSendSysMessage("12 PurpleItems 13 OrangeItems 14 YellowItems");
                handler->PSendSysMessage("The total must add up to 100%");
                return false;
            }

            uint32 greytg = uint32(strtoul(param1, NULL, 0));
            uint32 whitetg = uint32(strtoul(param2, NULL, 0));
            uint32 greentg = uint32(strtoul(param3, NULL, 0));
            uint32 bluetg = uint32(strtoul(param3, NULL, 0));
            uint32 purpletg = uint32(strtoul(param5, NULL, 0));
            uint32 orangetg = uint32(strtoul(param6, NULL, 0));
            uint32 yellowtg = uint32(strtoul(param7, NULL, 0));
            uint32 greyi = uint32(strtoul(param8, NULL, 0));
            uint32 whitei = uint32(strtoul(param9, NULL, 0));
            uint32 greeni = uint32(strtoul(param10, NULL, 0));
            uint32 bluei = uint32(strtoul(param11, NULL, 0));
            uint32 purplei = uint32(strtoul(param12, NULL, 0));
            uint32 orangei = uint32(strtoul(param13, NULL, 0));
            uint32 yellowi = uint32(strtoul(param14, NULL, 0));
            uint32 totalPercent = greytg + whitetg + greentg + bluetg + purpletg + orangetg + yellowtg + greyi + whitei + greeni + bluei + purplei + orangei + yellowi;

            if (totalPercent == 0 || totalPercent != 100)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions percentages $ahMapID (2, 6 or 7) $1 $2 $3 $4 $5 $6 $7 $8 $9 $10 $11 $12 $13 $14");
                handler->PSendSysMessage("1 GreyTradeGoods 2 WhiteTradeGoods 3 GreenTradeGoods 4 BlueTradeGoods 5 PurpleTradeGoods");
                handler->PSendSysMessage("6 OrangeTradeGoods 7 YellowTradeGoods 8 GreyItems 9 WhiteItems 10 GreenItems 11 BlueItems");
                handler->PSendSysMessage("12 PurpleItems 13 OrangeItems 14 YellowItems");
                handler->PSendSysMessage("The total must add up to 100%");
                return false;
            }

            char param[100];
            param[0] = '\0';
            strcat(param, param1);
            strcat(param, " ");
            strcat(param, param2);
            strcat(param, " ");
            strcat(param, param3);
            strcat(param, " ");
            strcat(param, param4);
            strcat(param, " ");
            strcat(param, param5);
            strcat(param, " ");
            strcat(param, param6);
            strcat(param, " ");
            strcat(param, param7);
            strcat(param, " ");
            strcat(param, param8);
            strcat(param, " ");
            strcat(param, param9);
            strcat(param, " ");
            strcat(param, param10);
            strcat(param, " ");
            strcat(param, param11);
            strcat(param, " ");
            strcat(param, param12);
            strcat(param, " ");
            strcat(param, param13);
            strcat(param, " ");
            strcat(param, param14);
            auctionbot.Commands(5, ahMapID, NULL, param);
        }
        else if (strncmp(opt, "minprice", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions minprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }

            if (strncmp(param1, "grey", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, "orange", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(6, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions minprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }
        }
        else if (strncmp(opt, "maxprice", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");
            if (!ahMapIdStr || !param1 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }
            if (strncmp(param1, "grey", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, "orange",l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(7, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }
        }
        else if (strncmp(opt, "minbidprice", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");

            if (!ahMapIdStr || !param2 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions minbidprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }

            uint32 minBidPrice = uint32(strtoul(param2, NULL, 0));
            if (minBidPrice < 1 || minBidPrice > 100)
            {
                handler->PSendSysMessage("The min bid price multiplier must be between 1 and 100");
                return false;
            }

            if (strncmp(param1, "grey", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, "orange", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(8, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions minbidprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }
        }
        else if (strncmp(opt, "maxbidprice", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxbidprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }

            uint32 maxBidPrice = uint32(strtoul(param2, NULL, 0));
            if (maxBidPrice < 1 || maxBidPrice > 100)
            {
                handler->PSendSysMessage("The max bid price multiplier must be between 1 and 100");
                return false;
            }

            if (strncmp(param1, "grey", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, " orange", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(9, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions max bidprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $price");
                return false;
            }
        }
        else if (strncmp(opt, "maxstack",l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxstack $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $value");
                return false;
            }

            uint32 maxStack = uint32(strtoul(param2, NULL, 0));
            if (maxStack < 0)
            {
                 handler->PSendSysMessage("maxstack can't be a negative number.");
                return false;
            }

            if (strncmp(param1, "grey",l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, "orange", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(10, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions maxstack $ahMapID (2, 6 or 7) $color (grey, white, green, blue, purple, orange or yellow) $value");
                return false;
            }
        }
        else if (strncmp(opt, "buyerprice", l) == 0)
        {
            char* param1 = strtok(NULL, " ");
            char* param2 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1 || !param2)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions buyerprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue or purple) $price");
                return false;
            }

            if (strncmp(param1, "grey", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_GREY, param2);
            else if (strncmp(param1, "white", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_WHITE, param2);
            else if (strncmp(param1, "green", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_GREEN, param2);
            else if (strncmp(param1, "blue", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_BLUE, param2);
            else if (strncmp(param1, "purple", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_PURPLE, param2);
            else if (strncmp(param1, "orange", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_ORANGE, param2);
            else if (strncmp(param1, "yellow", l) == 0)
                auctionbot.Commands(11, ahMapID, AHB_YELLOW, param2);
            else
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions buyerprice $ahMapID (2, 6 or 7) $color (grey, white, green, blue or purple) $price");
                return false;
            }
        }
        else if (strncmp(opt, "bidinterval", l) == 0)
        {
            char* param1 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions bidinterval $ahMapID (2, 6 or 7) $interval(in minutes)");
                return false;
            }

            auctionbot.Commands(12, ahMapID, NULL, param1);
        }
        else if (strncmp(opt, "bidsperinterval", l) == 0)
        {
            char* param1 = strtok(NULL, " ");

            if (!ahMapIdStr || !param1)
            {
                handler->PSendSysMessage("Syntax is: ahbotoptions bidsperinterval $ahMapID (2, 6 or 7) $bids");
                return false;
            }

            auctionbot.Commands(13, ahMapID, NULL, param1);
        }
        else
        {
            handler->PSendSysMessage("Syntax is: ahbotoptions $option $ahMapID (2, 6 or 7) $parameter");
            handler->PSendSysMessage("Try ahbotoptions help to see a list of options.");
            return false;
        }

        return true;
    }
};

void AddSC_ah_bot_commandscript()
{
    new ah_bot_commandscript();
}
