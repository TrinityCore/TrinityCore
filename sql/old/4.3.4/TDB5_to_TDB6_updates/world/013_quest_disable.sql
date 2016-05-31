-- "The Defias Brotherhood" quest chain was removed in 4.0.3a
-- A Mysterious Message (1381), related to quest 142, is no longer needed in loot template
-- With the "deaht" of Edwin VanCleef (639) and his removal from the game, his loot template is no longer needed
-- http://www.wowpedia.org/Defias_Brotherhood_quest_chain
DELETE FROM `creature_loot_template` WHERE `item`=1381;
DELETE FROM `creature_loot_template` WHERE `entry`=639;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (65,132,135,141,142,155,166);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,65,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,132,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,135,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,141,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,142,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,155,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)'),
(1,166,0,0,0,'Disable quest The Defias Brotherhood (Removed in 4.0.3a)');
