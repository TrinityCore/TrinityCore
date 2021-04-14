-- Quest chain involving the killing of Chieftain Nek'rosh was removed in 4.0.3a
-- Dragonmaw War Banner (3337), related to quest "War Banners", is no longer needed in loot template
-- Starting quest: http://www.wowpedia.org/Quest:Report_to_Captain_Stoutfist
DELETE FROM `creature_loot_template` WHERE `item`=3337;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (473,464,465,474);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,473,0,0,0,'Disable quest Report to Captain Stoutfist (Removed in 4.0.3a)'),
(1,464,0,0,0,'Disable quest War Banners (Removed in 4.0.3a)'),
(1,465,0,0,0,'Disable quest Nek''rosh''s Gambit (Removed in 4.0.3a)'),
(1,474,0,0,0,'Disable quest Defeat Nek''rosh (Removed in 4.0.3a)');
