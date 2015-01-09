-- Quest "Solomon's Law" (91) was removed in 4.0.3a
-- Shadowhide Pendant (1075), related to the quest, is no longer needed in the loot templates
-- http://www.wowhead.com/quest=91
DELETE FROM `creature_loot_template` WHERE `item`=1075;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=91;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,91,0,0,0,'Disable quest Solomon''s Law (Removed in 4.0.3a)');
