-- Change all Copper Ore Nodes in the Underlight Mines to be other id
UPDATE `gameobject` SET `id`=181248 WHERE `guid` IN (75024,75051,75090,75099,75105) AND `id`=1731;
-- Same for the Tin Nodes in the Underlight Mines
UPDATE `gameobject` SET `id`=181249 WHERE `guid` IN (75025,75052,75091,75100,75106) AND `id`=1732;

-- Change all Copper Ore Nodes in Beal Modan to match the other id
UPDATE `gameobject` SET `id`=103713 WHERE `guid` IN (5096,13067,120336) AND `id` IN (1731,3763);

-- fix wrongly increased counts (aka cata guildperk changed data)
-- Copper
UPDATE `gameobject_loot_template` SET `maxcount`=5 WHERE `entry`=1502 AND `item`=2770;
UPDATE `gameobject_loot_template` SET `maxcount`=6 WHERE `entry`=1502 AND `item`=2835;
-- Tin
UPDATE `gameobject_loot_template` SET `maxcount`=5 WHERE `entry`=1503 AND `item`=2771;
UPDATE `gameobject_loot_template` SET `maxcount`=7 WHERE `entry`=1503 AND `item`=2836;
-- Silver
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=1504 AND `item`=2775;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=1504 AND `item`=2775;
-- Iron
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=1505 AND `item`=2772;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=1505 AND `item`=2772;
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=1505 AND `item`=2838;
UPDATE `gameobject_loot_template` SET `maxcount`=5 WHERE `entry`=1505 AND `item`=2838;
-- Gold
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=1506 AND `item`=2776;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=1506 AND `item`=2776;
-- Mithril
UPDATE `gameobject_loot_template` SET `maxcount`=5 WHERE `entry`=1742 AND `item`=3858;
UPDATE `gameobject_loot_template` SET `maxcount`=7 WHERE `entry`=1742 AND `item`=7912;
-- Truesilver
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=5045 AND `item`=7911;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=5045 AND `item`=7911;
-- Small Thorium
UPDATE `gameobject_loot_template` SET `mincountOrRef`=1 WHERE `entry`=9597 AND `item`=10620;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=9597 AND `item`=10620;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE `entry`=9597 AND `item`=12365;
-- Rich Thorium
UPDATE `gameobject_loot_template` SET `mincountOrRef`=2 WHERE `entry`=12883 AND `item`=10620;
UPDATE `gameobject_loot_template` SET `maxcount`=5 WHERE `entry`=12883 AND `item`=10620;
UPDATE `gameobject_loot_template` SET `mincountOrRef`=2 WHERE `entry`=12883 AND `item`=12365;
UPDATE `gameobject_loot_template` SET `maxcount`=6 WHERE `entry`=12883 AND `item`=12365;

-- Remove Underlight Ore from all other copper ore nodes:
DELETE FROM `gameobject_loot_template` WHERE `item`=22634; -- Underlight Ore
DELETE FROM `gameobject_loot_template` WHERE `item`=2798; -- Rethban Ore
DELETE FROM `gameobject_loot_template` WHERE `item`=11513; -- Tainted Vitriol

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceGroup`=17939 AND `SourceEntry`=11513;

-- Set LootIDvariables for Special Nodes
SET @CopperUM := 18092;
SET @TinUM := 18093;
SET @CopperRR := 1735;
SET @TinRR := 1736;
SET @CopperB := 2626;
SET @TinB := 2627;
SET @GoldOoze := 17939;
SET @MithrilFW := 13961;
SET @TruesilverFW := 17938;
SET @ThoriumFW := 13960;
SET @ThoriumGems = 12900;

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@CopperUM,@CopperRR,@TinUM,@TinRR,@CopperB,@TinB,@GoldOoze,@MithrilFW,@TruesilverFW,@ThoriumFW);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Underlight Mine Special Nodes
(@CopperUM,2770,100,1,0,1,5), -- Copper Ore
(@CopperUM,2835, 25,1,0,1,6), -- Rough Stone
(@CopperUM,774 ,5,1,1,1,1), -- Malachite
(@CopperUM,1210,5,1,1,1,1), -- Shadowgem
(@CopperUM,818 ,5,1,1,1,1), -- Tigerseye
(@CopperUM,22634,-100,1,0,1,2), -- Underlight Ore (only if on quest)
-- Chanced Tin also have to drop it
(@TinUM,2771,100,1,0,1,5), -- Tin Ore
(@TinUM,2836,25,1,0,1,7), -- Coarse Stone
(@TinUM,1206,5,1,1,1,1), -- Moss Agate
(@TinUM,1705,5,1,1,1,1), -- Lesser Moonstone
(@TinUM,1210,5,1,1,1,1), -- Shadowgem
(@TinUM,1529,5,1,1,1,1), -- Jade
(@TinUM,22634,-100,1,0,1,2), -- Underlight Ore (only on quest)
-- Redridge Special Nodes
(@CopperRR,2770,100,1,0,1,5), -- Copper Ore
(@CopperRR,2835, 25,1,0,1,6), -- Rough Stone
(@CopperRR,774 ,5,1,1,1,1), -- Malachite
(@CopperRR,1210,5,1,1,1,1), -- Shadowgem
(@CopperRR,818 ,5,1,1,1,1), -- Tigerseye
(@CopperRR,2798,-100,1,0,1,4), -- Rethban Ore
-- Chanced Tin also have to drop it
(@TinRR,2771,100,1,0,1,5), -- Tin Ore
(@TinRR,2836,25,1,0,1,7), -- Coarse Stone
(@TinRR,1206,5,1,1,1,1), -- Moss Agate
(@TinRR,1705,5,1,1,1,1), -- Lesser Moonstone
(@TinRR,1210,5,1,1,1,1), -- Shadowgem
(@TinRR,1529,5,1,1,1,1), -- Jade
(@TinRR,2798,-100,1,0,1,2), -- Rethban Ore (only on quest)
-- The Barrens Copper Vein contain Blood Shards
(@CopperB,2770,100,1,0,1,5), -- Copper Ore
(@CopperB,2835, 25,1,0,1,6), -- Rough Stone
(@CopperB,774 ,5,1,1,1,1), -- Malachite
(@CopperB,1210,5,1,1,1,1), -- Shadowgem
(@CopperB,818 ,5,1,1,1,1), -- Tigerseye
(@CopperB,5075,5,1,1,1,3), -- Blood Shard (only in barrens)
-- Chanced Tin also have to drop it
(@TinB,2771,100,1,0,1,5), -- Tin Ore
(@TinB,2836,25,1,0,1,7), -- Coarse Stone
(@TinB,1206,5,1,1,1,1), -- Moss Agate
(@TinB,1705,5,1,1,1,1), -- Lesser Moonstone
(@TinB,1210,5,1,1,1,1), -- Shadowgem
(@TinB,1529,5,1,1,1,1), -- Jade
(@TinB,5075,5,1,1,1,4), -- Blood Shard (only in barrens ?)
-- Ooze Covered Gold Vein
(@GoldOoze,2776,100,1,0,2,4), -- Gold Ore
(@GoldOoze,3864,5,1,1,1,1), -- Citrine
(@GoldOoze,1705,5,1,1,1,1), -- Lesser Moonstone
(@GoldOoze,7909,5,1,1,1,1), -- Aquamarine
-- Felwood Mithril Vein
(@MithrilFW,3858,100,1,0,1,5), -- Mithril Ore
(@MithrilFW,7912,80,1,0,1,7), -- Solid Stone
(@MithrilFW,7909,5,1,1,1,1), -- Aquamarine
(@MithrilFW,3864,5,1,1,1,1), -- Citrine
(@MithrilFW,7910,5,1,1,1,1), -- Star Ruby
(@MithrilFW,9262,5,1,1,1,1), -- Black Vitriol
(@MithrilFW,11513,25,1,0,1,4), -- Tainted Vitriol
-- Chanced Truesilver also needs it
(@TruesilverFW,7911,100,1,0,1,4), -- Truesilver Ore
(@TruesilverFW,7909,5,1,1,1,1), -- Aquamarine
(@TruesilverFW,3864,5,1,1,1,1), -- Citrine
(@TruesilverFW,7910,5,1,1,1,1), -- Star Ruby
(@TruesilverFW,11513,25,1,0,1,4), -- Tainted Vitriol
-- Chance Thoriuym also needs it
-- Small Thorium Vein+Tainted Vitriol
(@ThoriumFW,10620,100,1,0,1,8), -- Thorium Ore
(@ThoriumFW,12365,100,1,0,1,10), -- Dense Stone
(@ThoriumFW,1,15,1,0,-@ThoriumGems,1), -- One From Gems
(@ThoriumFW,11513,50,1,0,1,1); -- Tainted Vitriol


