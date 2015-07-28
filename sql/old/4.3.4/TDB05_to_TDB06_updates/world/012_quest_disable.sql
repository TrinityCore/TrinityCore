-- Quest "Oh Brother. . ." (167) was removed in 4.0.3a
-- Thistlenettle's Badge (1875), related to the quest, is no longer needed in loot template
-- http://www.wowpedia.org/Quest:Oh_Brother._._.
DELETE FROM `creature_loot_template` WHERE `item`=1875;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=167;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,167,0,0,0,'Disable quest Oh Brother. . . (Removed in 4.0.3a)');
