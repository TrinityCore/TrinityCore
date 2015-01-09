-- 3 Quests given by "Marshal Marris" were removed in 4.0.3a
-- Blackrock Menace (20), Shadow Magic (115) and Tharil'zun (19)
-- Items related to those quests are no longer needed in loot template
-- Battleworn Axe (3014), Midnight Orb (1261) and Tharil'zun's Head (1260)
-- http://www.wowpedia.org/Marshal_Marris
DELETE FROM `creature_loot_template` WHERE `item` IN (3014,1261,1260);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (20,115,19);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,20,0,0,0,'Disable quest Blackrock Menace (Removed in 4.0.3a)'),
(1,115,0,0,0,'Disable quest Shadow Magic (Removed in 4.0.3a)'),
(1,19,0,0,0,'Disable quest Tharil''zun (Removed in 4.0.3a)');
