Populates the auction houses with items. It can make the game feel a bit more
like official on small servers. Items and prices are chosen randomly based on
the parameters you define. If an auction expires, auctions are deleted quietly.
AHBot will not buy it's own items, and will not receive mail from the AH
or get returned mail.

===============================================================================
~~HOW TO CONFIGURE~~
===============================================================================
Step 1.) Create a character that you are going to use as the auction house bot
         character. This character will be the auction's owner for all the
         items created by the bot.
Step 2.) Go into the realm database and note the account number for the
         character.
Step 3.) Go into the characters database and note the character's GUID.
Step 4.) Log in at least once with this character.
         (Do not change the configuration before this)
Step 5.) Tune the configuration options in the configuration file and the
         Database.

#These are the settings in the configuration file:
AuctionHouseBot.DEBUG = 0
AuctionHouseBot.EnableSeller = 0
AuctionHouseBot.EnableBuyer = 0
AuctionHouseBot.UseBuyPriceForSeller = 0
AuctionHouseBot.UseBuyPriceForBuyer = 0
AuctionHouseBot.Account = 0
AuctionHouseBot.GUID = 0
AuctionHouseBot.ItemsPerCycle = 200

AuctionHouseBot.DEBUG enables (1) or disables (0) Debug output
AuctionHouseBot.EnableSeller enables (1) or disables (0) the Seller
AuctionHouseBot.EnableBuyer enables (1) or disables (0) the Buyer
AuctionHouseBot.UseBuyPriceForSeller Use SellPrice (0) or BuyPrice (1) for determining prices
AuctionHouseBot.UseBuyPriceForBuyer Use SellPrice (0) or BuyPrice (1) for determining prices
AuctionHouseBot.Account is the account number (in realmd->account table) of the player you want to run as the auction bot. Note: a value of 0 will disable the bot.
AuctionHouseBot.GUID is the GUID (in characters->characters table) of the player you want to run as the auction bot. Note: a value of 0 will disable the bot.
AuctionHouseBot.ItemsPerCycle determines how many items are added each time AHBot is run (once per minute, by default)

#These are the Filters For filtering certain items/trade goods from the AH
AuctionHouseBot.VendorItems = 0
AuctionHouseBot.VendorTradeGoods = 0
AuctionHouseBot.LootItems = 1
AuctionHouseBot.LootTradeGoods = 1
AuctionHouseBot.OtherItems = 0
AuctionHouseBot.OtherTradeGoods = 0
AuctionHouseBot.No_Bind = 1
AuctionHouseBot.Bind_When_Picked_Up = 0
AuctionHouseBot.Bind_When_Equipped = 1
AuctionHouseBot.Bind_When_Use = 1
AuctionHouseBot.Bind_Quest_Item = 0
AuctionHouseBot.DisableBeta_PTR_Unused = 0
AuctionHouseBot.DisablePermEnchant = 0
AuctionHouseBot.DisableConjured = 0
AuctionHouseBot.DisableGems = 0
AuctionHouseBot.DisableMoney = 0
AuctionHouseBot.DisableMoneyLoot = 0
AuctionHouseBot.DisableLootable = 0
AuctionHouseBot.DisableKeys = 0
AuctionHouseBot.DisableDuration = 0
AuctionHouseBot.DisableBOP_Or_Quest_NoReqLevel = 0

AuctionHouseBot.VendorItems is a boolean value (0 or 1) that indicates whether to include Vendor only items
AuctionHouseBot.VendorTradeGoods is a boolean value (0 or 1) that indicates whether to include Vendor only Trade Goods
AuctionHouseBot.LootItems  is a boolean value (0 or 1) that indicates whether to include Loot/Fish/Skin/etc. only items
AuctionHouseBot.LootTradeGoods  is a boolean value (0 or 1) that indicates whether to include Loot/Fish/Skin/etc. only Trade Goods
AuctionHouseBot.OtherItems  is a boolean value (0 or 1) that indicates whether to include Other items not covered by the first 2
AuctionHouseBot.OtherTradeGoods  is a boolean value (0 or 1) that indicates whether to include Other Trade Goods not covered by the first 2
AuctionHouseBot.No_Bind is a boolean value (0 or 1) that indicates whether to include items with a bonding of 0
AuctionHouseBot.Bind_When_Picked_Up = is a boolean value (0 or 1) that indicates whether to include items with a bonding of 1
AuctionHouseBot.Bind_When_Equipped = is a boolean value (0 or 1) that indicates whether to include items with a bonding of 2
AuctionHouseBot.Bind_When_Use = is a boolean value (0 or 1) that indicates whether to include items with a bonding of 3
AuctionHouseBot.Bind_Quest_Item = is a boolean value (0 or 1) that indicates whether to include items with a bonding of 4
AuctionHouseBot.DisableBeta_PTR_Unused is a boolean value (0 or 1) that will Disable certain items that are usually unavailable to Players
AuctionHouseBot.DisablePermEnchant is a boolean value (0 or 1) that will Disable Items with a Permanent Enchantment
AuctionHouseBot.DisableConjured is a boolean value (0 or 1) that will Disable Conjured Items
AuctionHouseBot.DisableGems is a boolean value (0 or 1) that will Disable Gems
AuctionHouseBot.DisableMoney is a boolean value (0 or 1) that will Disable Items that are used as money
AuctionHouseBot.DisableMoneyLoot is a boolean value (0 or 1) that will Disable Items that have Money as a loot
AuctionHouseBot.DisableLootable is a boolean value (0 or 1) that will Disable Items that have other items as loot
AuctionHouseBot.DisableKeys is a boolean value (0 or 1) that will Disable Items that are keys
AuctionHouseBot.DisableDuration is a boolean value (0 or 1) that will Disable Items with a duration
AuctionHouseBot.DisableBOP_Or_Quest_NoReqLevel is a boolean value (0 or 1) that will Disable items that are BOP or Quest Item with a Required level that is less than the Item Level

#These Filters are boolean (0 or 1) and will disable items that are
#specifically meant for the Class named.
#(UnusedClass is Class 10, which was skipped for some reason)
AuctionHouseBot.DisableWarriorItems = 0
AuctionHouseBot.DisablePaladinItems = 0
AuctionHouseBot.DisableHunterItems = 0
AuctionHouseBot.DisableRogueItems = 0
AuctionHouseBot.DisablePriestItems = 0
AuctionHouseBot.DisableDKItems = 0
AuctionHouseBot.DisableShamanItems = 0
AuctionHouseBot.DisableMageItems = 0
AuctionHouseBot.DisableWarlockItems = 0
AuctionHouseBot.DisableUnusedClassItems = 0
AuctionHouseBot.DisableDruidItems = 0

#These are the Filters For filtering certain items/trade goods from the AH
AuctionHouseBot.DisableItemsBelowLevel = 0
AuctionHouseBot.DisableItemsAboveLevel = 0
AuctionHouseBot.DisableTGsBelowLevel = 0
AuctionHouseBot.DisableTGsAboveLevel = 0
AuctionHouseBot.DisableItemsBelowGUID = 0
AuctionHouseBot.DisableItemsAboveGUID = 0
AuctionHouseBot.DisableTGsBelowGUID = 0
AuctionHouseBot.DisableTGsAboveGUID = 0
AuctionHouseBot.DisableItemsBelowReqLevel = 0
AuctionHouseBot.DisableItemsAboveReqLevel = 0
AuctionHouseBot.DisableTGsBelowReqLevel = 0
AuctionHouseBot.DisableTGsAboveReqLevel = 0
AuctionHouseBot.DisableItemsBelowReqSkillRank = 0
AuctionHouseBot.DisableItemsAboveReqSkillRank = 0
AuctionHouseBot.DisableTGsBelowReqSkillRank = 0
AuctionHouseBot.DisableTGsAboveReqSkillRank = 0

#These are the settings in the Database:
#Each Auctionhouse has it's own set of these

MinItems = 0
#The Minimum number of items you want to keep in the auction houses.
#(default 0 - minimum will be the same as maximum).
#If it is higher than the value of the corresponding maxItems setting,
#it will be set down to match the maxItems setting.

MaxItems = 0
#The Maximum number of items you want to keep in the auction houses.

#These must add up to 100 each one is the percentage
#of the auction items that should be trade goods of
#that quality. A value of 0 will disable.

PercentGreyTradeGoods = 0
PercentWhiteTradeGoods = 27
PercentGreenTradeGoods = 12
PercentBlueTradeGoods = 10
PercentPurpleTradeGoods = 1
PercentOrangeTradeGoods = 0
PercentYellowTradeGoods = 0

PercentGreyItems = 0
PercentWhiteItems = 10
PercentGreenItems = 30
PercentBlueItems = 8
PercentPurpleItems = 2
PercentOrangeItems = 0
PercentYellowItems = 0

#MinPrice(Color)    is the minimum price adjustment for items. For example the default is 150, which means 150%. So if an item vendors for 1g it would go to auction for a minimum of 1.5g.
#MaxPrice(Color)    is the maximum price adjustment for items.
#MinBidPrice(Color) these two control the starting bid as a percent of the buyout price. For example, if MinBidPrice is 30 and MaxBidPrice is 80 the starting bid for the auction will randomly be between 30-80% of the randomly chosen buyout price.
#MaxBidPrice(Color) these two control the starting bid as a percent of the buyout price. For example, if MinBidPrice is 30 and MaxBidPrice is 80 the starting bid for the auction will randomly be between 30-80% of the randomly chosen buyout price.
#MaxStack(Color)    is maximum stack size to create for this quality type. A value of zero will disable the maximum stack size for this quality allowing the bot to create stacks (of random size) of items as big as the item type allows.

MinPriceGrey = 100
MaxPriceGrey = 150
MinBidPriceGrey = 70
MaxBidPriceGrey = 100
MaxStackGrey = 0
MinPriceWhite = 150
MaxPriceWhite = 250
MinBidPriceWhite = 70
MaxBidPriceWhite = 100
MaxStackWhite = 0
MinPriceGreen = 800
MaxPriceGreen = 1400
MinBidPriceGreen = 80
MaxBidPriceGreen = 100
MaxStackGreen = 0
MinPriceBlue = 1250
MaxPriceBlue = 1750
MinBidPriceBlue = 75
MaxBidPriceBlue = 100
MaxStackBlue = 0
MinPricePurple = 2250
MaxPricePurple = 4550
MinBidPricePurple = 80
MaxBidPricePurple = 100
MaxStackPurple = 0
MinPriceOrange = 4250
MaxPriceOrange = 5550
MinBidPriceOrange = 80
MaxBidPriceOrange = 100
MaxStackOrange = 0
MinPriceYellow = 5250
MaxPriceYellow = 6550
MinBidPriceYellow = 80
MaxBidPriceYellow = 100
MaxStackYellow = 0

#These are the multipliers that are applied to the vendor price for an item, that determines if AHBot will buy it or not.
#1 means AHBot will pay the same as (or less than) a vendor would pay, 2 means up to twice as much, etc.

BuyerPriceGrey = 1
BuyerPriceWhite = 3
BuyerPriceGreen = 5
BuyerPriceBlue = 12
BuyerPricePurple = 15
BuyerPriceOrange = 20
BuyerPriceYellow = 22

#BuyerBiddingInterval is the time (in minutes) between bids.
#BuyerBidsPerInterval is the number of bids the buyer will make in a cycle

BuyerBiddingInterval = 1
BuyerBidsPerInterval = 1



How to use ahcommands from the console (CLI) or in game with GM level 3 players:
ahbotoptions - will display usage instructions
ahbotoptions help - will display the list of commands

ahexpire - will expire all the auctions in the requested auction house that were created by AHBot.
minitems - will set the minimum number of items in the AH before it starts being filled again.
maxitems - will set the maximum number of items in the AH.
percentages - will set the percentage of each quality in the AH
minprice - will set the minimum price multiplier for auctions.
maxprice - will set the maximum price multiplier for auctions.
minbidprice - will set the minimum starting bid as a percent of the buyout price for auctions.
maxbidprice - will set the maximum starting bid as a percent of the buyout price for auctions.
maxstack - will set the maximum number of items in stacks for auctions. 0 will set the maximum to the maximum for that item type.
buyerprice - will set the bid price multiplier for auctions.
biddinginterval - will set the number of minutes between bids on auctions.
bidsperinterval - will set the number of bids to enter per cycle.

The auction house IDs are:
2 - Alliance
6 - Horde
7 - Neutral


AHBot Originally made by Chris K. Currently maintained by Paradox
Much thanks to Chris K, grether and Dolomit6!
AHBot Now includes AHBuyer created by Kerbe as a derivative of AHBot, and later modified by Paradox
