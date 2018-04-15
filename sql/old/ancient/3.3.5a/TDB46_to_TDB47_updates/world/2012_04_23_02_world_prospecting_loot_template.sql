SET @TinRef := 13000;
SET @TBC1 := @TinRef+1;
SET @TBC2 := @TinRef+2;
SET @WOTLK1 := @TinRef+3;
SET @WOTLK2 := @TinRef+4;
SET @WOTLK3 := @TinRef+5;

SET @Copper := 2770;
SET @Tin := 2771;
SET @Iron := 2772;
SET @Mithril := 3858;
SET @Thorium := 10620;
SET @FelIron := 23424;
SET @Adamantite := 23425;
SET @Cobalt := 36909;
SET @Saronite := 36912;
SET @Titanium := 36910;

-- Reference Loot Templates
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @TinRef AND @TinRef+5;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Stupid Tin
(@TinRef,1529,0,1,1,1,1),  -- Jade
(@TinRef,3864,0,1,1,1,1),  -- Citrine
(@TinRef,7909,0,1,1,1,1),  -- Aquamarine
-- TBC Greens
(@TBC1,21929,0,1,1,1,2), -- Flame Spessarite
(@TBC1,23077,0,1,1,1,2), -- Blood Garnet
(@TBC1,23079,0,1,1,1,2), -- Deep Peridot
(@TBC1,23107,0,1,1,1,2), -- Shadow Draenite
(@TBC1,23112,0,1,1,1,2), -- Golden Draenite
(@TBC1,23117,0,1,1,1,2), -- Azure Moonstone
-- TBC Blues
(@TBC2,23436,0,1,1,1,1), -- Living Ruby
(@TBC2,23437,0,1,1,1,1), -- Talasite
(@TBC2,23438,0,1,1,1,1), -- Star of Elune
(@TBC2,23439,0,1,1,1,1), -- Noble Topaz
(@TBC2,23440,0,1,1,1,1), -- Dawnstone
(@TBC2,23441,0,1,1,1,1), -- Nightseye
-- WOTLK Greens
(@WOTLK1,36917,0,1,1,1,2), -- Bloodstone
(@WOTLK1,36920,0,1,1,1,2), -- Sun Crystal
(@WOTLK1,36923,0,1,1,1,2), -- Chalcedony
(@WOTLK1,36926,0,1,1,1,2), -- Shadow Crystal
(@WOTLK1,36929,0,1,1,1,2), -- Huge Citrine
(@WOTLK1,36932,0,1,1,1,2), -- Dark Jade
-- WOTLK Blues
(@WOTLK2,36918,0,1,1,1,2), -- Scarlet Ruby
(@WOTLK2,36921,0,1,1,1,2), -- Autumn's Glow
(@WOTLK2,36924,0,1,1,1,2), -- Sky Sapphire
(@WOTLK2,36927,0,1,1,1,2), -- Twilight Opal
(@WOTLK2,36930,0,1,1,1,2), -- Monarch Topaz
(@WOTLK2,36933,0,1,1,1,2), -- Forest Emerald
-- WOTLK Epics
(@WOTLK3,36919,0,1,1,1,1), -- Cardinal Ruby
(@WOTLK3,36922,0,1,1,1,1), -- King's Amber
(@WOTLK3,36925,0,1,1,1,1), -- Majestic Zircon
(@WOTLK3,36928,0,1,1,1,1), -- Dreadstone
(@WOTLK3,36931,0,1,1,1,1), -- Ametrine
(@WOTLK3,36934,0,1,1,1,1); -- Eye of Zul
-- --------------------------------------------------------
-- Prospecting Loot Templates
DELETE FROM `prospecting_loot_template` WHERE `entry` IN (@Copper,@Tin,@Iron,@Mithril,@Thorium,@FelIron,@Adamantite,@Cobalt,@Saronite,@Titanium);
INSERT INTO `prospecting_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Copper Ore
(@Copper,774,0,1,1,1,1), -- Malachite
(@Copper,818,0,1,1,1,1), -- Tigerseye
(@Copper,1210,10,1,0,1,1), -- Shadowgem
-- Tin Ore
(@Tin,1210,0,1,1,1,2),  -- Shadowgem
(@Tin,1705,0,1,1,1,2),  -- Lesser Moonstone
(@Tin,1206,0,1,1,1,2), -- Moss Agate
(@Tin,1,10,1,0,-@TinRef,1), -- One Rare gem chance
-- Iron Ore
(@Iron,1529,30,1,1,1,2), -- Jade
(@Iron,1705,30,1,1,1,2), -- Lesser Moonstone
(@Iron,3864,30,1,1,1,2), -- Citrine
(@Iron,7909,5,1,1,1,1), -- Aquamarine
(@Iron,7910,5,1,1,1,1), -- Star Ruby
-- Mithril Ore
(@Mithril,3864,30,1,1,1,2), -- Citrine
(@Mithril,7909,30,1,1,1,2), -- Aquamarine
(@Mithril,7910,30,1,1,1,2), -- Star Ruby
(@Mithril,12361,2.5,1,1,1,1), -- Blue Sapphire
(@Mithril,12364,2.5,1,1,1,1), -- Huge Emerald
(@Mithril,12799,2.5,1,1,1,1), -- Large Opal
(@Mithril,12800,2.5,1,1,1,1), -- Azerothian Diamond
-- Thorium Ore
(@Thorium,7910,30,1,1,1,2), -- Star Ruby
(@Thorium,12361,15,1,1,1,2), -- Blue Sapphire
(@Thorium,12364,15,1,1,1,2), -- Huge Emerald
(@Thorium,12799,15,1,1,1,2), -- Large Opal
(@Thorium,12800,15,1,1,1,2), -- Azerothian Diamond
(@Thorium,1,10,1,1,-@TBC1,1), -- one from TBC Greens
-- Fel Iron Ore
(@FelIron,1,95,1,1,-@TBC1,1), -- One from TBC Greens
(@FelIron,2,05,1,1,-@TBC2,1), -- One from TBC Blues
-- Adamantite Ore
(@Adamantite,24243,100,1,0,1,1), -- Adamantite Powder
(@Adamantite,1,100,1,1,-@TBC1,1), -- One from TBC Greens
(@Adamantite,2, 10,1,1,-@TBC2,1), -- One from TBC Blues
-- Cobalt Ore
(@Cobalt,1,95,1,1,-@WOTLK1,1), -- One from WOTLK Greens
(@Cobalt,2,05,1,1,-@WOTLK2,1), -- One from WOTLK Blues
-- Saronite Ore
(@Saronite,1,85,1,1,-@WOTLK1,2), -- One from WOTLK Greens
(@Saronite,2,15,1,1,-@WOTLK2,1), -- One from WOTLK Blues
-- Titanium Ore
(@Titanium,46849,75,1,0,1,1), -- Titanium Powder
(@Titanium,1,75,1,1,-@WOTLK1,2), -- Two from WOTLK Greens
(@Titanium,2,25,1,1,-@WOTLK2,1), -- One from WOTLK Blues
(@Titanium,3,20,1,0,-@WOTLK3,1); -- One from WOTLK Epics
