-- Quest Underbelly Scales (122) was removed in 4.0.3a
-- Underbelly Whelp Scale (1221), related to the quest, is no longer needed in loot template
-- http://www.wowpedia.org/Quest:Underbelly_Scales / http://www.wowpedia.org/Underbelly_Whelp_Scale
DELETE FROM `creature_loot_template` WHERE `item`=1221;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=122;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,122,0,0,0,'Disable quest Underbelly Scales (Removed in 4.0.3a)');
