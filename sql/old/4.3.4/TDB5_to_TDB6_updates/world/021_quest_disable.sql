-- Quest "The Scarlet Crusade" (381) was removed in 4.0.3a
-- Scarlet Armband (3266), related to the quest, is no longer needed in loot templates
-- http://www.wowpedia.org/Quest:The_Scarlet_Crusade
DELETE FROM `creature_loot_template` WHERE `item`=3266;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=381;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,381,0,0,0,'Disable quest The Scarlet Crusade (Removed in 4.0.3a)');
