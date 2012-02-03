SET @ThoriumGems = 12900;
DELETE FROM `reference_loot_template` WHERE `entry` IN (@ThoriumGems,12901,12902,12903,12904,12905,12906,12907,12908);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ThoriumGems
(@ThoriumGems,12363,40,1,1,1,1), -- Arcane Crystal
(@ThoriumGems, 7910,12,1,1,1,1), -- Star Ruby
(@ThoriumGems,12800,12,1,1,1,1), -- Azerothian Diamond
(@ThoriumGems,12361,12,1,1,1,1), -- Blue Sapphire
(@ThoriumGems,12364,12,1,1,1,1), -- Huge Emerald
(@ThoriumGems,12799,12,1,1,1,1); -- Large Opal

SET @Copper := 1502;
SET @Tin := 1503;
SET @Silver := 1504;
SET @Iron := 1505;
SET @Gold :=1506;
SET @Mithril :=1742;
SET @Truesilver := 5045;
SET @SmallThorium := 9597;
SET @RichThorium := 12883;

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Copper,@Tin,@Silver,@Iron,@Gold,@Mithril,@Truesilver,@SmallThorium,@RichThorium,17938,13960,17241);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Copper Vein
(@Copper,2770,100,1,0,1,9), -- Copper Ore
(@Copper,2835, 25,1,0,1,11), -- Rough Stone
(@Copper,774 ,5,1,1,1,1), -- Malachite
(@Copper,1210,5,1,1,1,1), -- Shadowgem
(@Copper,818 ,5,1,1,1,1), -- Tigerseye
(@Copper,22634,-100,1,0,1,2), -- Underlight Ore (only on quest)
-- Tin Vein
(@Tin,2771,100,1,0,1,9), -- Tin Ore
(@Tin,2836,25,1,0,1,13), -- Coarse Stone
(@Tin,1206,5,1,1,1,1), -- Moss Agate
(@Tin,1705,5,1,1,1,1), -- Lesser Moonstone
(@Tin,1210,5,1,1,1,1), -- Shadowgem
(@Tin,1529,5,1,1,1,1), -- Jade
(@Tin,2798,-100,1,0,1,2), -- Rethban Ore (only on quest)
(@Tin,22634,-100,1,0,1,2), -- Underlight Ore (only on quest)
-- Silver Vein
(@Silver,2775,100,1,0,2,8), -- Silver Ore
(@Silver,1206,5,1,1,1,1), -- Moss Agate
(@Silver,1705,5,1,1,1,1), -- Lesser Moonstone
(@Silver,1210,5,1,1,1,1), -- Shadowgem
-- Iron Deposit
(@Iron,2772,100,1,0,2,9), -- Iron Ore
(@Iron,2838,100,1,0,2,10), -- Heavy Stone
(@Iron,1529,5,1,1,1,1), -- Jade
(@Iron,3864,5,1,1,1,1), -- Citrine
(@Iron,1705,5,1,1,1,1), -- Lesser Moonstone
(@Iron,7909,5,1,1,1,1), -- Aquamarine
-- Gold Vein
(@Gold,2776,100,1,0,2,8), -- Gold Ore
(@Gold,3864,5,1,1,1,1), -- Citrine
(@Gold,1705,5,1,1,1,1), -- Lesser Moonstone
(@Gold,7909,5,1,1,1,1), -- Aquamarine
-- Mithril Deposit
(@Mithril,3858,100,1,0,1,9), -- Mithril Ore
(@Mithril,7912,80,1,0,1,13), -- Solid Stone
(@Mithril,7909,5,1,1,1,1), -- Aquamarine
(@Mithril,3864,5,1,1,1,1), -- Citrine
(@Mithril,7910,5,1,1,1,1), -- Star Ruby
(@Mithril,9262,5,1,1,1,1), -- Black Vitriol
-- Truesilver Deposit
(@Truesilver,7911,100,1,0,2,8), -- Truesilver Ore
(@Truesilver,7909,5,1,1,1,1), -- Aquamarine
(@Truesilver,3864,5,1,1,1,1), -- Citrine
(@Truesilver,7910,5,1,1,1,1), -- Star Ruby
-- Small Thorium Vein
(@SmallThorium,10620,100,1,0,1,8), -- Thorium Ore
(@SmallThorium,12365,100,1,0,1,10), -- Dense Stone
(@SmallThorium,1,15,1,0,-@ThoriumGems,1), -- One From Gems
-- Rich Thorium Vein
(@RichThorium,10620,100,1,0,3,10), -- Thorium Ore
(@RichThorium,12365,100,1,0,4,12), -- Dense Stone
(@RichThorium,1,25,1,0,-@ThoriumGems,1), -- One From Gems
-- Special Cases:
-- Truesilver Vein+Tainted Vitriol
(17938,7911,100,1,0,2,8), -- Truesilver Ore
(17938,7909,5,1,1,1,1), -- Aquamarine
(17938,3864,5,1,1,1,1), -- Citrine
(17938,7910,5,1,1,1,1), -- Star Ruby
(17938,11513,50,1,0,1,1), -- Tainted Vitriol
-- Small Thorium Vein+Tainted Vitriol
(13960,10620,100,1,0,1,8), -- Thorium Ore
(13960,12365,100,1,0,1,10), -- Dense Stone
(13960,1,15,1,0,-@ThoriumGems,1), -- One From Gems
(13960,11513,50,1,0,1,1), -- Tainted Vitriol
-- Hakkari Thorium Vein
(17241,10620,100,1,0,1,8), -- Thorium Ore
(17241,12365,100,1,0,1,10), -- Dense Stone
(17241,1,15,1,0,-@ThoriumGems,1), -- One From Gems
(17241,19774,40,1,0,5,10); -- Souldarite

