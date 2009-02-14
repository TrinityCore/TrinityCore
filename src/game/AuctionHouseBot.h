#ifndef AUCTION_HOUSE_BOT_H
#define AUCTION_HOUSE_BOT_H
#include "Common.h"
#include "Log.h"
#include "Config/ConfigEnv.h"
#include "AuctionHouseMgr.h"
#define AHB_GREY        0
#define AHB_WHITE       1
#define AHB_GREEN       2
#define AHB_BLUE        3
#define AHB_PURPLE      4
#define AHB_GREY_TG     0
#define AHB_WHITE_TG    1
#define AHB_GREEN_TG    2
#define AHB_BLUE_TG     3
#define AHB_PURPLE_TG   4
#define AHB_GREY_I      5
#define AHB_WHITE_I     6
#define AHB_GREEN_I     7
#define AHB_BLUE_I      8
#define AHB_PURPLE_I    9
#define AHBplayerAccount sConfig.GetIntDefault("AuctionHouseBot.Account", 0)
#define AHBplayerGUID sConfig.GetIntDefault("AuctionHouseBot.GUID", 0)
#define ItemsPerCycle sConfig.GetIntDefault("AuctionHouseBot.ItemsPerCycle", 200)
#define SellMethod sConfig.GetIntDefault("AuctionHouseBot.UseBuyPriceForSeller", 1)
#define BuyMethod sConfig.GetIntDefault("AuctionHouseBot.UseBuyPriceForBuyer", 0)

class AHBConfig
{
   private:
     AuctionLocation AHID;
     uint32 minItems;
     uint32 maxItems;
     uint32 minTime;
     uint32 maxTime;
     uint32 percentWhiteTradeGoods;
     uint32 percentGreenTradeGoods;
     uint32 percentBlueTradeGoods;
     uint32 percentPurpleTradeGoods;
     uint32 percentWhiteItems;
     uint32 percentGreenItems;
     uint32 percentBlueItems;
     uint32 percentPurpleItems;
     uint32 minPriceWhite;
     uint32 maxPriceWhite;
     uint32 minBidPriceWhite;
     uint32 maxBidPriceWhite;
     uint32 maxStackWhite;
     uint32 minPriceGreen;
     uint32 maxPriceGreen;
     uint32 minBidPriceGreen;
     uint32 maxBidPriceGreen;
     uint32 maxStackGreen;
     uint32 minPriceBlue;
     uint32 maxPriceBlue;
     uint32 minBidPriceBlue;
     uint32 maxBidPriceBlue;
     uint32 maxStackBlue;
     uint32 minPricePurple;
     uint32 maxPricePurple;
     uint32 minBidPricePurple;
     uint32 maxBidPricePurple;
     uint32 maxStackPurple;

     uint32 buyerPriceGrey;
     uint32 buyerPriceWhite;
     uint32 buyerPriceGreen;
     uint32 buyerPriceBlue;
     uint32 buyerPricePurple;
     uint32 buyerBiddingInterval;
     uint32 buyerBidsPerInterval;

     uint32 wtgp;
     uint32 gtgp;
     uint32 btgp;
     uint32 ptgp;
     uint32 wip;
     uint32 gip;
     uint32 bip;
     uint32 pip;
    public:
     AHBConfig(AuctionLocation ahid)
     {
         AHID = ahid;
     }
     AHBConfig()
     {
     }
     AuctionLocation GetAHID()
     {
         return AHID;
     }
     void SetMinItems(uint32 value)
     {
             minItems = value;
     }
     uint32 GetMinItems()
     {
        if ((minItems  == 0) && (maxItems))
            return maxItems;
        else if ((maxItems) && (minItems > maxItems))
            return maxItems;
        else
            return minItems;
     }
     void SetMaxItems(uint32 value)
     {
             maxItems = value;
             CalculatePercents();
     }
     uint32 GetMaxItems()
     {
        return maxItems;
     }
     void SetMinTime(uint32 value)
     {
         minTime = value;
     }
     uint32 GetMinTime()
     {
        if (minTime < 1)
          return 1;
        else if ((maxTime) && (minTime > maxTime))
            return maxTime;
        else
            return minTime;
     }
     void SetMaxTime(uint32 value)
     {
         maxTime = value;
     }
     uint32 GetMaxTime()
     {
        return maxTime;
     }
     void SetPercentages(uint32 wtg, uint32 gtg, uint32 btg, uint32 ptg, uint32 wi, uint32 gi, uint32 bi, uint32 pi)
     {
        uint32 totalPercent = wtg + gtg + btg + ptg + wi + gi + bi + pi;

        if (totalPercent == 0)
        {
          maxItems = 0;
        }
        else if (totalPercent != 100)
        {
          double scale = (double) 100 / (double) totalPercent;

          wtg = (uint32) (scale * (double) pi);
          gtg = (uint32) (scale * (double) gtg);
          btg = (uint32) (scale * (double) btg);
          ptg = (uint32) (scale * (double) ptg);
          wi = (uint32) (scale * (double) wi);
          gi = (uint32) (scale * (double) gi);
          bi = (uint32) (scale * (double) bi);
          pi = 100 - wtg - gtg - btg - ptg - wi - gi - bi;

        }
        percentWhiteTradeGoods = wtg;
        percentGreenTradeGoods = gtg;
        percentBlueTradeGoods = btg;
        percentPurpleTradeGoods = ptg;
        percentWhiteItems = wi;
        percentGreenItems = gi;
        percentBlueItems = bi;
        percentPurpleItems = pi;
        CalculatePercents();
     }
     uint32 GetPercentages(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY_TG:
             return 0;
             break;
         case AHB_WHITE_TG:
            return percentWhiteTradeGoods;
             break;
         case AHB_GREEN_TG:
            return percentGreenTradeGoods;
             break;
         case AHB_BLUE_TG:
            return percentBlueTradeGoods;
             break;
         case AHB_PURPLE_TG:
            return percentPurpleTradeGoods;
             break;
         case AHB_GREY_I:
            return 0;
             break;
         case AHB_WHITE_I:
            return percentWhiteItems;
             break;
         case AHB_GREEN_I:
            return percentGreenItems;
             break;
         case AHB_BLUE_I:
            return percentBlueItems;
             break;
         case AHB_PURPLE_I:
            return percentPurpleItems;
             break;
         default:
            return 0;
             break;
         }
     }
     void SetMinPrice(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
             break;
         case AHB_WHITE:
            minPriceWhite = value;
             break;
         case AHB_GREEN:
            minPriceGreen = value;
             break;
         case AHB_BLUE:
            minPriceBlue = value;
             break;
         case AHB_PURPLE:
            minPricePurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetMinPrice(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            {
                return 0;
                break;
            }
         case AHB_WHITE:
            {
                if (minPriceWhite == 0)
                    return 150;
                else if (minPriceWhite > maxPriceWhite)
                    return maxPriceWhite;
                else
                    return minPriceWhite;
                break;
            }
         case AHB_GREEN:
            {
                if (minPriceGreen == 0)
                    return 200;
                else if (minPriceGreen > maxPriceGreen)
                    return maxPriceGreen;
                else
                    return minPriceGreen;
                break;
            }
         case AHB_BLUE:
            {
                if (minPriceBlue == 0)
                    return 250;
                else if (minPriceBlue > maxPriceBlue)
                    return maxPriceBlue;
                else
                    return minPriceBlue;
                break;
            }
         case AHB_PURPLE:
            {
                if (minPricePurple == 0)
                    return 300;
                else if (minPricePurple > maxPricePurple)
                    return maxPricePurple;
                else
                    return minPricePurple;
                break;
            }
         default:
             {
                 return 0;
                 break;
             }
        }
     }
     void SetMaxPrice(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
             break;
         case AHB_WHITE:
            maxPriceWhite = value;
             break;
         case AHB_GREEN:
            maxPriceGreen = value;
             break;
         case AHB_BLUE:
            maxPriceBlue = value;
             break;
         case AHB_PURPLE:
            maxPricePurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetMaxPrice(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            {
                return 0;
                break;
            }
         case AHB_WHITE:
            {
                if (maxPriceWhite == 0)
                    return 250;
                else
                    return maxPriceWhite;
                break;
            }
         case AHB_GREEN:
            {
                if (maxPriceGreen == 0)
                    return 300;
                else
                    return maxPriceGreen;
                break;
            }
         case AHB_BLUE:
            {
                if (maxPriceBlue == 0)
                    return 350;
                else
                    return maxPriceBlue;
                break;
            }
         case AHB_PURPLE:
            {
                if (maxPricePurple == 0)
                    return 450;
                else
                    return maxPricePurple;
                break;
            }
         default:
             {
                 return 0;
                 break;
             }
        }
     }
     void SetMinBidPrice(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
             break;
         case AHB_WHITE:
            minBidPriceWhite = value;
             break;
         case AHB_GREEN:
            minBidPriceGreen = value;
             break;
         case AHB_BLUE:
            minBidPriceBlue = value;
             break;
         case AHB_PURPLE:
            minBidPricePurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetMinBidPrice(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            {
                return 0;
                break;
            }
         case AHB_WHITE:
            {
                if (minBidPriceWhite > 100)
                    return 100;
                else
                    return minBidPriceWhite;
                break;
            }
         case AHB_GREEN:
            {
                if (minBidPriceGreen > 100)
                    return 100;
                else
                    return minBidPriceGreen;
                break;
            }
         case AHB_BLUE:
            {
                if (minBidPriceBlue > 100)
                    return 100;
                else
                    return minBidPriceBlue;
                break;
            }
         case AHB_PURPLE:
            {
                if (minBidPricePurple > 100)
                    return 100;
                else
                    return minBidPricePurple;
                break;
            }
         default:
             {
                 return 0;
                 break;
             }
         }
     }
     void SetMaxBidPrice(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
             break;
         case AHB_WHITE:
            maxBidPriceWhite = value;
             break;
         case AHB_GREEN:
            maxBidPriceGreen = value;
             break;
         case AHB_BLUE:
            maxBidPriceBlue = value;
             break;
         case AHB_PURPLE:
            maxBidPricePurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetMaxBidPrice(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            {
                return 0;
                break;
            }
         case AHB_WHITE:
            {
                if (maxBidPriceWhite > 100)
                    return 100;
                else
                    return maxBidPriceWhite;
                break;
            }
         case AHB_GREEN:
            {
                if (maxBidPriceGreen > 100)
                    return 100;
                else
                    return maxBidPriceGreen;
                break;
            }
         case AHB_BLUE:
            {
                if (maxBidPriceBlue > 100)
                    return 100;
                else
                    return maxBidPriceBlue;
                break;
            }
         case AHB_PURPLE:
            {
                if (maxBidPricePurple > 100)
                    return 100;
                else
                    return maxBidPricePurple;
                break;
            }
         default:
             {
                 return 0;
                 break;
             }
         }
     }
     void SetMaxStack(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
             break;
         case AHB_WHITE:
            maxStackWhite = value;
             break;
         case AHB_GREEN:
            maxStackGreen = value;
             break;
         case AHB_BLUE:
            maxStackBlue = value;
             break;
         case AHB_PURPLE:
            maxStackPurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetMaxStack(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            {
                return 0;
                break;
            }
         case AHB_WHITE:
            {
                return maxStackWhite;
                break;
            }
         case AHB_GREEN:
            {
                return maxStackGreen;
                break;
            }
         case AHB_BLUE:
            {
                return maxStackBlue;
                break;
            }
         case AHB_PURPLE:
            {
                return maxStackPurple;
                break;
            }
         default:
             {
                 return 0;
                 break;
             }
         }
     }
     void SetBuyerPrice(uint32 color, uint32 value)
     {
         switch(color)
         {
         case AHB_GREY:
            buyerPriceGrey = value;
             break;
         case AHB_WHITE:
            buyerPriceWhite = value;
             break;
         case AHB_GREEN:
            buyerPriceGreen = value;
             break;
         case AHB_BLUE:
            buyerPriceBlue = value;
             break;
         case AHB_PURPLE:
            buyerPricePurple = value;
             break;
         default:
             break;
         }
     }
     uint32 GetBuyerPrice(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY:
            return buyerPriceGrey;
             break;
         case AHB_WHITE:
            return buyerPriceWhite;
             break;
         case AHB_GREEN:
            return buyerPriceGreen;
             break;
         case AHB_BLUE:
            return buyerPriceBlue;
             break;
         case AHB_PURPLE:
            return buyerPricePurple;
             break;
         default:
             return 0;
             break;
         }
     }
     void SetBiddingInterval(uint32 value)
     {
         buyerBiddingInterval = value;
     }
     uint32 GetBiddingInterval()
     {
         return buyerBiddingInterval;
     }
     void CalculatePercents()
     {
        wtgp = (uint32) (((double)percentWhiteTradeGoods / 100.0) * maxItems);
        gtgp = (uint32) (((double)percentGreenTradeGoods / 100.0) * maxItems);
        btgp = (uint32) (((double)percentBlueTradeGoods / 100.0) * maxItems);
        ptgp = (uint32) (((double)percentPurpleTradeGoods / 100.0) * maxItems);
        wip = (uint32) (((double)percentWhiteItems / 100.0) * maxItems);
        gip = (uint32) (((double)percentGreenItems / 100.0) * maxItems);
        bip = (uint32) (((double)percentBlueItems / 100.0) * maxItems);
        pip = (uint32) (((double)percentPurpleItems / 100.0) * maxItems);
        uint32 total = wtgp + gtgp + btgp + ptgp + wip + gip + bip + pip;
        if (total != maxItems)
        {
          wtgp = (uint32) (maxItems * (double) wtgp);
          gtgp = (uint32) (maxItems * (double) gtgp);
          btgp = (uint32) (maxItems * (double) btgp);
          ptgp = (uint32) (maxItems * (double) ptgp);
          wip = (uint32) (maxItems * (double) wip);
          gip = (uint32) (maxItems * (double) gip);
          bip = (uint32) (maxItems * (double) bip);
          pip = (maxItems - (wtgp + gtgp + btgp + ptgp + wip + gip + bip));
          total = wtgp + gtgp + btgp + ptgp + wip + gip + bip + pip;
        }
        //sLog.outString("%u %u %u %u %u %u %u %u", wtgp, gtgp, btgp, ptgp, wip, gip, bip, pip);
     }
     uint32 GetPercents(uint32 color)
     {
         switch(color)
         {
         case AHB_GREY_TG:
             return 0;
             break;
         case AHB_WHITE_TG:
            return wtgp;
             break;
         case AHB_GREEN_TG:
            return gtgp;
             break;
         case AHB_BLUE_TG:
            return btgp;
             break;
         case AHB_PURPLE_TG:
            return ptgp;
             break;
         case AHB_GREY_I:
             return 0;
             break;
         case AHB_WHITE_I:
            return wip;
             break;
         case AHB_GREEN_I:
            return gip;
             break;
         case AHB_BLUE_I:
            return bip;
             break;
         case AHB_PURPLE_I:
            return pip;
             break;
         default:
             return 0;
             break;
         }
     }
     void SetBidsPerInterval(uint32 value)
     {
         buyerBidsPerInterval = value;
     }
     uint32 GetBidsPerInterval()
     {
         return buyerBidsPerInterval;
     }
   ~AHBConfig()
   {
   }
};
void AuctionHouseBot();
void AuctionHouseBotInit();
void AuctionHouseBotLoadValues(AHBConfig*);
void AuctionHouseBotCommands(uint32, AuctionLocation, uint32, char*);
#endif
