SET @ENTRY := 39946;
UPDATE `creature_template` SET `lootid`=@ENTRY WHERE `entry`=39746;
UPDATE `creature_template` SET `lootid`=@ENTRY+1 WHERE `entry`=39751;
UPDATE `creature_template` SET `lootid`=@ENTRY+2 WHERE `entry`=39747;
DELETE FROM `creature_loot_template` WHERE `entry` BETWEEN @ENTRY AND @ENTRY+2;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@ENTRY,49426,100,1,0,1,1),
(@ENTRY+1,49426,100,1,0,1,1),
(@ENTRY+2,49426,100,1,0,1,1);
