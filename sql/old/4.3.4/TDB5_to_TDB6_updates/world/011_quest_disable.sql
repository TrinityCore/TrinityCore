-- Quest "Collecting Memories" (168) was removed in 4.0.3a
-- Miners' Union Card (1894), related to the quest, is no longer needed in loot template
-- http://www.wowpedia.org/Quest:Collecting_Memories
DELETE FROM `creature_loot_template` WHERE `item`=1894;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=168;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,168,0,0,0,'Disable quest Collecting Memories (Removed in 4.0.3a)');
