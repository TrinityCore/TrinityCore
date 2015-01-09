-- Definitions for Cataclysm veins
-- Taken from 26605282f3549c4c66a93e958d2ddef93bd72b83
SET @Obsidium       := 28490;
SET @RichObsidium   := 28495;
SET @Elementium     := 28492;
SET @RichElementium := 28493;
SET @Pyrite         := 28491;
SET @RichPyrite     := 28494;
-- Elementium Geode
SET @Geode          := 67282;
-- Definition for Cataclysm gems
SET @CataGreenGems  := 12907;
SET @CataBlueGems   := 12908;
-- Fix mistake implemented in 71c409312fde63c2fcee8f3d408725ac39878b9a
SET @WotLKGems      := 12906;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Obsidium,@RichObsidium,@Elementium,@RichElementium,@Pyrite,@RichPyrite) AND `mincountOrRef`=-@WotLKGems;
-- Insert Cataclysm gems into the Referenced Loot
DELETE FROM `reference_loot_template` WHERE `entry` IN (@CataGreenGems,@CataBlueGems);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Cataclysm Green Gems
(@CataGreenGems,52177,0,1,1,1,1), -- Carnelian
(@CataGreenGems,52178,0,1,1,1,1), -- Zephyrite
(@CataGreenGems,52179,0,1,1,1,1), -- Alicite
(@CataGreenGems,52180,0,1,1,1,1), -- Nightstone
(@CataGreenGems,52181,0,1,1,1,1), -- Hessonite
(@CataGreenGems,52182,0,1,1,1,1), -- Jasper
-- Cataclysm Blue Gems
(@CataBlueGems, 52190,0,1,1,1,1), -- Inferno Ruby
(@CataBlueGems, 52191,0,1,1,1,1), -- Ocean Sapphire
(@CataBlueGems, 52192,0,1,1,1,1), -- Dream Emerald
(@CataBlueGems, 52193,0,1,1,1,1), -- Ember Topaz
(@CataBlueGems, 52194,0,1,1,1,1), -- Demonseye
(@CataBlueGems, 52195,0,1,1,1,1); -- Amberjewel

-- Insert gems into Loot Templates of Cataclysm veins
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Obsidium,@RichObsidium,@Elementium,@RichElementium,@Pyrite,@RichPyrite) AND `mincountOrRef` IN (-@CataGreenGems,-@CataBlueGems);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Obsidium Deposit
(@Obsidium,      1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@Obsidium,      2,2,1,0,-@CataBlueGems, 1), -- One From Blue Gems
-- Rich Obsidium Deposit
(@RichObsidium,  1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@RichObsidium,  2,2,1,0,-@CataBlueGems, 1), -- One From Blue Gems
-- Elementium Vein
(@Elementium,@Geode,0.05,1,0,1,1),           -- Elementium Geode
(@Elementium,    1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@Elementium,    2,2,1,0,-@CataBlueGems, 1), -- One From Blue Gems
-- Rich Elementium Vein
(@RichElementium,@Geode,0.1,1,0,1,1),        -- Elementium Geode
(@RichElementium,1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@RichElementium,2,2,1,0,-@CataBlueGems, 1), -- One From Blue Gems
-- Pyrite Deposit
(@Pyrite,        1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@Pyrite,        2,2,1,0,-@CataBlueGems, 1), -- One From Blue Gems
-- Rich Pyrite Deposit
(@RichPyrite,    1,5,1,0,-@CataGreenGems,1), -- One From Green Gems
(@RichPyrite,    2,2,1,0,-@CataBlueGems, 1); -- One From Blue Gems
