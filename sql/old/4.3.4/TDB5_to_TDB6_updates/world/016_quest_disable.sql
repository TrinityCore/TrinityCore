-- Quest "Noble Deaths" was removed in 4.0.3a
-- Alterac Signet Ring (3505), related to the quest, is no longer needed in loot template
-- http://www.wowpedia.org/Quest:Noble_Deaths
DELETE FROM `creature_loot_template` WHERE `item`=3505;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=512;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,512,0,0,0,'Disable quest Noble Deaths (Removed in 4.0.3a)');
