SET @Triumph :=47241;
-- Cleanup some unneeded references
DELETE FROM `reference_loot_template` WHERE `entry` IN (34167,34168,34169);
UPDATE `creature_loot_template` SET `mincountOrRef`=-34349 WHERE `mincountOrRef` IN (-34167,-34168,-34169);
-- Fix this weird defined reference for ulduar
UPDATE `reference_loot_template` SET `ChanceOrQuestChance`=100,`groupid`=0 WHERE `entry`=34349;
-- Remove Emblem of Triumph from reference_loot
DELETE FROM `reference_loot_template` WHERE `item`=@Triumph AND `entry`IN (12025,35034,35040,35049);
-- Actual Emblem on creature as it should be
DELETE FROM `creature_loot_template` WHERE `entry` IN (30397,30398,31365,31367,31656,31679) AND `item`=@Triumph;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(30397,@Triumph,100,1,0,1,1), -- Commander Kolurg (1)
(30398,@Triumph,100,1,0,1,1), -- Commander Stoutbeard (1)
(31365,@Triumph,100,1,0,1,1), -- Drakkari Colossus (1)
(31367,@Triumph,100,1,0,1,1), -- Drakkari Elemental (1)
(31656,@Triumph,100,1,0,1,1), -- Dalronn the Controller (1)
(31679,@Triumph,100,1,0,1,1); -- Skarvald the Constructor (1)
-- Similar action for gameobjects
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (27416,27417) AND `item`=@Triumph;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27417,@Triumph,100,1,0,1,1), -- Confessor's Cache
(27416,@Triumph,100,1,0,1,1); -- Eadric's Cache
