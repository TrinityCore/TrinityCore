-- Quest "The Everstill Bridge" (89) was removed from the game in 4.0.3a
-- Iron Rivet (1013) and Iron Pike (2856), related to the quest, are no longer needed in the loot templates
-- http://www.wowpedia.org/Iron_Pike / http://www.wowpedia.org/Iron_Rivet
DELETE FROM `creature_loot_template` WHERE `item` IN (1013,2856);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=89;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,89,0,0,0,'Disable quest The Everstill Bridge (Removed in 4.0.3a)');
