-- Quest The Color of Blood (388) was removed in 4.0.3a when Stockades were overhauled
-- Red Wool Bandana (2909), related to the quest, is no longer needed in loot template
-- http://www.wowhead.com/quest=388 / http://www.wowhead.com/item=2909
DELETE FROM `creature_loot_template` WHERE `item`=2909;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=388;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,388,0,0,0,'Disable quest The Color of Blood (Removed in 4.0.3a)');
