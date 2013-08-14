SET @ThoriumGems := 12900;
SET @FelIronGems := 12901;
SET @RareGems := 12902;
SET @EpicGems := 12903
SET @AdamantiteGems := 12904;
SET @WotlkGreenGems := 12905;
SET @WotlkBlueGems := 12906;

DELETE FROM `reference_loot_template` WHERE `entry` IN (@ThoriumGems,@FelIronGems,@RareGems,@AdamantiteGems,@WotlkGreenGems,@WotlkBlueGems);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ThoriumGems
(@ThoriumGems,12363,40,1,1,1,1), -- Arcane Crystal
(@ThoriumGems, 7910,12,1,1,1,1), -- Star Ruby
(@ThoriumGems,12800,12,1,1,1,1), -- Azerothian Diamond
(@ThoriumGems,12361,12,1,1,1,1), -- Blue Sapphire
(@ThoriumGems,12364,12,1,1,1,1), -- Huge Emerald
(@ThoriumGems,12799,12,1,1,1,1), -- Large Opal
-- Fel Iron Gems
(@FelIronGems,23112,0,1,1,1,1), -- Golden Draenite
(@FelIronGems,23077,0,1,1,1,1), -- Blood Garnet
(@FelIronGems,21929,0,1,1,1,1), -- Flame Spessarite
(@FelIronGems,23079,0,1,1,1,1), -- Deep Peridot
(@FelIronGems,23107,0,1,1,1,1), -- Shadow Draenite
(@FelIronGems,23117,0,1,1,1,1), -- Azure Moonstone
-- Rare Gems
(@RareGems,23437,0,1,1,1,1), -- Talasite
(@RareGems,23439,0,1,1,1,1), -- Noble Topaz
(@RareGems,23440,0,1,1,1,1), -- Dawnstone
(@RareGems,23436,0,1,1,1,1), -- Living Ruby
(@RareGems,23441,0,1,1,1,1), -- Nightseye
(@RareGems,23438,0,1,1,1,1), -- Star of Elune
-- Epic Gems
(@EpicGems,32227,0,1,1,1,2), -- Crimson Spinel
(@EpicGems,32228,0,1,1,1,2), -- Empyrean Sapphire
(@EpicGems,32229,0,1,1,1,2), -- Lionseye
(@EpicGems,32230,0,1,1,1,2), -- Shadowsong Amethyst
(@EpicGems,32231,0,1,1,1,2), -- Pyrestone
(@EpicGems,32249,0,1,1,1,2), -- Seaspray Emerald
-- Adamantite Gems
(@AdamantiteGems,23112,0,1,1,1,2), -- Golden Draenite
(@AdamantiteGems,23077,0,1,1,1,2), -- Blood Garnet
(@AdamantiteGems,21929,0,1,1,1,2), -- Flame Spessarite
(@AdamantiteGems,23079,0,1,1,1,2), -- Deep Peridot
(@AdamantiteGems,23107,0,1,1,1,2), -- Shadow Draenite
(@AdamantiteGems,23117,0,1,1,1,2), -- Azure Moonstone
-- WOTLK Green Gems
(@WotlkGreenGems,36917,0,1,1,1,1), -- Bloodstone
(@WotlkGreenGems,36920,0,1,1,1,1), -- Sun Crystal
(@WotlkGreenGems,36923,0,1,1,1,1), -- Chalcedony
(@WotlkGreenGems,36926,0,1,1,1,1), -- Shadow Crystal
(@WotlkGreenGems,36929,0,1,1,1,1), -- Huge Citrine
(@WotlkGreenGems,36932,0,1,1,1,1), -- Dark Jade
-- WOTLK Blue Gems
(@WotlkBlueGems,36918,0,1,1,1,1), -- Scarlet Ruby
(@WotlkBlueGems,36921,0,1,1,1,1), -- Autumn's Glow
(@WotlkBlueGems,36924,0,1,1,1,1), -- Sky Sapphire
(@WotlkBlueGems,36927,0,1,1,1,1), -- Twilight Opal
(@WotlkBlueGems,36930,0,1,1,1,1), -- Monarch Topaz
(@WotlkBlueGems,36933,0,1,1,1,1); -- Forest Emerald
-- --------------------------------------------------------------------------------------------------------------------------------------------------------
-- --------------------------------------------------------------------------------------------------------------------------------------------------------
-- -------------------
-- -- CLASSIC ZONES --
-- -------------------
SET @Copper := 1502;
SET @Tin := 1503;
SET @Silver := 1504;
SET @Iron := 1505;
SET @Gold :=1506;
SET @Mithril :=1742;
SET @Truesilver := 5045;
SET @DarkIron := 11213;
SET @SmallThorium := 9597;
SET @RichThorium := 12883;
SET @Incendicite := 1409; -- (OR 29574??) 
SET @Indurium := 3266; 

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Copper,@Tin,@Silver,@Iron,@Gold,@Mithril,@Truesilver,@DarkIron,@SmallThorium,@RichThorium,17938,13960,17241,@Incendicite,@Indurium);
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
-- Silver Vein & Ooze Covered Silver Vein
(@Silver,2775,100,1,0,2,4), -- Silver Ore
(@Silver,1206,5,1,1,1,1), -- Moss Agate
(@Silver,1705,5,1,1,1,1), -- Lesser Moonstone
(@Silver,1210,5,1,1,1,1), -- Shadowgem
-- Iron Deposit
(@Iron,2772,100,1,0,2,4), -- Iron Ore
(@Iron,2838,100,1,0,1,5), -- Heavy Stone
(@Iron,1529,5,1,1,1,1), -- Jade
(@Iron,3864,5,1,1,1,1), -- Citrine
(@Iron,1705,5,1,1,1,1), -- Lesser Moonstone
(@Iron,7909,5,1,1,1,1), -- Aquamarine
-- Gold Vein & Ooze Covered Gold Vein
(@Gold,2776,100,1,0,2,4), -- Gold Ore
(@Gold,3864,5,1,1,1,1), -- Citrine
(@Gold,1705,5,1,1,1,1), -- Lesser Moonstone
(@Gold,7909,5,1,1,1,1), -- Aquamarine
-- Mithril Deposit & Ooze Covered
(@Mithril,3858,100,1,0,2,4), -- Mithril Ore
(@Mithril,7912,80,1,0,1,8), -- Solid Stone
(@Mithril,7909,5,1,1,1,1), -- Aquamarine
(@Mithril,3864,5,1,1,1,1), -- Citrine
(@Mithril,7910,5,1,1,1,1), -- Star Ruby
(@Mithril,9262,5,1,1,1,1), -- Black Vitriol
-- Truesilver Deposit & Ooze Covered
(@Truesilver,7911,100,1,0,2,4), -- Truesilver Ore
(@Truesilver,7909,5,1,1,1,1), -- Aquamarine
(@Truesilver,3864,5,1,1,1,1), -- Citrine
(@Truesilver,7910,5,1,1,1,1), -- Star Ruby
-- Dark Iron Deposit
(@DarkIron,11370,100,1,0,2,4), -- Dark Iron Ore
(@DarkIron, 9262,5,1,1,1,1), -- Black Vitriol
(@DarkIron,11382,5,1,1,1,1), -- Blood of the Mountain
(@DarkIron,11754,5,1,1,1,1), -- Black Diamond
-- Small Thorium Vein Covered
(@SmallThorium,10620,100,1,0,2,3), -- Thorium Ore
(@SmallThorium,12365,100,1,0,1,5), -- Dense Stone
(@SmallThorium,1,15,1,0,-@ThoriumGems,1), -- One From Gems
-- Rich Thorium Vein & Ooze Covered
(@RichThorium,10620,100,1,0,3,5), -- Thorium Ore
(@RichThorium,12365,100,1,0,4,7), -- Dense Stone
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
(17241,19774,40,1,0,5,10), -- Souldarite
-- Incendicite Mineral Vein
(@Incendicite,3340,-100,1,0,1,2), -- Incendicite Ore (for quest) 
-- Indurium Mineral Vein
(@Indurium,5833,-100,1,0,2,4); -- Indurium Ore (for quest)
-- -------------------------------
-- -- The Burning Crusade Zones -- 
-- -------------------------------
SET @FelIron :=18359;
SET @Nethercite := 22070;
SET @Adamantite := 18361;
SET @RichAdamantite := 26861;
SET @Khorium := 18363;
SET @GemVein := 26862;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@FelIron,@Nethercite,@Adamantite,@RichAdamantite,@Khorium,@GemVein);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Fel Iron Deposit
(@FelIron,23424,100,1,0,2,4), -- Fel Iron Ore
(@FelIron,22573,10,1,0,1,2), -- Mote of Earth
(@FelIron,22574,10,1,0,1,2), -- Mote of Fire
(@FelIron,23427,5,1,0,1,2), -- Eternium Ore
(@FelIron,1,5,1,0,-@FelIronGems,1), -- One From Green Gems
-- Nethercite Deposit
(@Nethercite,32464,100,1,0,1,2), -- Nethercite Ore
(@Nethercite,22573,10,1,0,1,4), -- Mote of Earth
(@Nethercite,22574,10,1,0,1,4), -- Mote of Fire
(@Nethercite,1,5,1,0,-@FelIronGems,1), -- One From Green Gems
(@Nethercite,2,1,1,0,-@RareGems,1), -- One From Blue Gems
-- Adamantite Deposit
(@Adamantite,23425,100,1,0,2,4), -- Adamantite Ore
(@Adamantite,22573,10,1,0,1,8), -- Mote of Earth
(@Adamantite,23427,10,1,0,1,2), -- Eternium Ore
(@Adamantite,1,5,1,0,-@AdamantiteGems,1), -- One From Green Gems
(@Adamantite,2,1,1,0,-@RareGems,1), -- One From Blue Gems
-- Rich Adamantite Deposit
(@RichAdamantite,23425,100,1,0,5,7), -- Adamantite Ore
(@RichAdamantite,22573,10,1,0,4,8), -- Mote of Earth
(@RichAdamantite,23427,10,1,0,2,3), -- Eternium Ore
(@RichAdamantite,1,5,1,0,-@AdamantiteGems,1), -- One From Green Gems
(@RichAdamantite,2,1,1,0,-@RareGems,1), -- One From Blue Gems
-- Khorium Vein
(@Khorium,23426,100,1,0,2,4), -- Khorim Ore
(@Khorium,22573,35,1,0,2,5), -- Mote of Earth
(@Khorium,22574,10,1,0,2,5), -- Mote of Fire
(@Khorium,23427,10,1,0,1,3), -- Eternium Ore
(@khorium,1,5,1,0,-@FelIronGems,1), -- One From Gems
(@khorium,2,1,1,0,-@RareGems,1), -- One From Gems
-- Ancient Gem Vein
(@GemVein,34907,70,1,1,1,9), -- Shattered Gem Fragments
(@GemVein,1,20,1,1,-@EpicGems,1), -- Epic Gems
(@GemVein,2,10,1,1,-@FelIronGems,1); -- One From Gems
-- ----------------------------------
-- -- Wrath of the Lich King Zones -- 
-- ----------------------------------
SET @Cobalt :=24153;
SET @RichCobalt := 24154;
SET @Saronite := 24155;
SET @RichSaronite := 24156;
SET @Titanium := 24157;
SET @PureSaronite := 27244;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Cobalt,@RichCobalt,@Saronite,@RichSaronite,@PureSaronite,@Titanium);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Cobalt Deposit
(@Cobalt,36909,100,1,0,2,4), -- Cobalt Ore
(@Cobalt,37701,30,1,0,1,2), -- Crystallized Earth
(@Cobalt,37705,30,1,0,1,2), -- Crystallized Water
(@Cobalt,1,5,1,0,-@WotlkGreenGems,1), -- One From Green Gems
-- Rich Cobalt Deposit
(@RichCobalt,36909,100,1,0,4,8), -- Cobalt Ore
(@RichCobalt,37701,30,1,0,1,2), -- Crystallized Earth
(@RichCobalt,37705,30,1,0,1,2), -- Crystallized Water
(@RichCobalt,1,5,1,0,-@WotlkGreenGems,1), -- One From Green Gems
(@RichCobalt,2,5,1,0,-@WotlkBlueGems,1), -- One From Blue Gems
-- Saronite Deposit
(@Saronite,36912,100,1,0,2,4), -- Saronite Ore
(@Saronite,37701,40,1,0,1,2), -- Crystallized Earth
(@Saronite,37703,40,1,0,1,2), -- Crystallized Shadow
(@Saronite,1,5,1,0,-@WotlkGreenGems,1), -- One From Green Gems
-- Rich Saronite Deposit
(@RichSaronite,36912,100,1,0,5,7), -- Saronite Ore
(@RichSaronite,37701,40,1,0,1,8), -- Crystallized Earth
(@RichSaronite,37703,40,1,0,1,8), -- Crystallized Shadow
(@RichSaronite,1,5,1,0,-@WotlkGreenGems,1), -- One From Green Gems
(@RichSaronite,2,5,1,0,-@WotlkBlueGems,1), -- One From Blue Gems
-- Titanium Vein
(@Titanium,36910,100,1,0,2,4), -- Titanium Ore
(@Titanium,37701,50,1,0,3,6), -- Crystallized Earth
(@Titanium,37705,50,1,0,3,6), -- Crystallized Water
(@Titanium,37702,50,1,0,3,6), -- Crystallized Fire
(@Titanium,37703,50,1,0,3,6), -- Crystallized Air
(@Titanium,1,25,1,0,-@WotlkGreenGems,1), -- One From Green Gems
(@Titanium,2,5,1,0,-@WotlkBlueGems,1), -- One From Blue Gems
-- Pure Saronite Deposit
(@PureSaronite,36912,100,1,0,22,38), -- Saronite Ore
(@PureSaronite,35627,60,1,0,2,4), -- Eternal Earth
(@PureSaronite,35624,60,1,0,2,4), -- Eternal Shadow
(@PureSaronite,1,35,1,0,-@WotlkGreenGems,1), -- One From Green Gems
(@PureSaronite,2,50,1,0,-@WotlkBlueGems,1); -- One From Blue Gems

DELETE FROM `reference_loot_template` WHERE `entry` IN (12909,12991,12992,12993,12994,12995,12996,12997,12998,12999);