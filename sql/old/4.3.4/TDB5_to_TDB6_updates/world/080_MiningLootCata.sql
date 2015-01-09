SET @CataGreenGems := 12906;
-- ---------------------
-- -- Cataclysm Zones -- 
-- ---------------------
SET @Obsidium := 28490;
SET @RichObsidium := 28495;
SET @Elementium := 28492;
SET @RichElementium := 28493;
SET @Pyrite := 28491;
SET @RichPyrite := 28494;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Obsidium,@RichObsidium,@Elementium,@RichElementium,@Pyrite,@RichPyrite);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Obsidium Deposit
(@Obsidium,53038,100,1,0,2,4), -- Obsidium Ore
(@Obsidium,52327, 10,1,0,1,2), -- Volatile Earth
(@Obsidium,52328, 10,1,0,1,2), -- Volatile Air
(@Obsidium,    1,  5,1,0,-@CataGreenGems,1), -- One From Green Gems
-- Rich Obsidium Deposit
(@RichObsidium,53038,100,1,0,5,7), -- Obsidium Ore
(@RichObsidium,52327, 10,1,0,3,4), -- Volatile Earth
(@RichObsidium,52328, 10,1,0,3,4), -- Volatile Air
(@RichObsidium,    1,  5,1,0,-@CataGreenGems,1), -- One From Green Gems
-- Elementium Vein
(@Elementium,52185,100,1,0,2,4), -- Elementium Ore
(@Elementium,52325, 10,1,0,1,2), -- Volatile Fire
(@Elementium,52326, 10,1,0,1,2), -- Volatile Water
(@Elementium,52327, 10,1,0,1,2), -- Volatile Earth
(@Elementium,52328,  2,1,0,1,2), -- Volatile Air
(@Elementium,    1,  5,1,0,-@CataGreenGems,1), -- One From Green Gems
-- Rich Elementium Vein
(@RichElementium,52185,100,1,0,5,7), -- Elementium Ore
(@RichElementium,52325, 10,1,0,1,2), -- Volatile Fire
(@RichElementium,52326, 10,1,0,1,2), -- Volatile Water
(@RichElementium,52327, 10,1,0,1,2), -- Volatile Earth
(@RichElementium,52328,  2,1,0,1,2), -- Volatile Air
(@RichElementium,    1,  5,1,0,-@CataGreenGems,1), -- One From Green Gems
-- Pyrite Deposit
(@Pyrite,52183,100,1,0,2,4), -- Pyrite Ore
(@Pyrite,52325, 10,1,0,1,2), -- Volatile Fire
(@Pyrite,52328, 10,1,0,1,2), -- Volatile Air
(@Pyrite,    1,  5,1,0,-@CataGreenGems,1), -- One From Green Gems
-- Rich Pyrite Deposit
(@RichPyrite,52183,100,1,0,5,7), -- Pyrite Ore
(@RichPyrite,52325, 10,1,0,2,3), -- Volatile Fire
(@RichPyrite,52328, 10,1,0,2,3), -- Volatile Air
(@RichPyrite,    1,  5,1,0,-@CataGreenGems,1); -- One From Green Gems
