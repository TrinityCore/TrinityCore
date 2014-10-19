-- Quest "Crocolisk Hunting" (385) was removed in 4.0.3a
-- Crocolisk Skin (2925), related to the quest, is no longer needed in loot templates
-- http://www.wowpedia.org/Quest:Crocolisk_Hunting
DELETE FROM `creature_loot_template` WHERE `item`=2925;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=385;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,385,0,0,0,'Disable quest Crocolisk Hunting (Removed in 4.0.3a)');
