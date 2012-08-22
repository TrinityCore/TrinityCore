SET @Bag := 52676;
DELETE FROM `item_loot_template` WHERE `entry`=@Bag;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Bag,36933,0,1,1,1,3),-- Forest Emerald
(@Bag,36918,0,1,1,1,3),-- Scarlet Ruby
(@Bag,36921,0,1,1,1,3),-- Autumn's Glow
(@Bag,36930,0,1,1,1,3),-- Monarch Topaz
(@Bag,36924,0,1,1,1,3),-- Sky Sapphire
(@Bag,36927,0,1,1,1,3),-- Twilight Opal
(@Bag,43953,5,1,0,1,1); -- Reins of the Blue Drake
