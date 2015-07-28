ALTER TABLE `achievement_reward`   
  ADD COLUMN `mailTemplate` MEDIUMINT(8) UNSIGNED DEFAULT 0 NULL AFTER `text`;

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=11238;
INSERT INTO `disables` (`sourceType`, `entry`, `comment`) VALUES
(4,11238, 'Achievement: Jade Tiger');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (5597,5599,5600,6789,7408,7412,7415,7416,7418,7419,9058,9718,9719,9720,9721,10718,10878,10879,10881,10898,11238,11402,12562,12912,12999,13000,13001,13002,13003,13004,13005,13006,13007);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(5597,  23,  62, 0, ''), -- Merciless Gladiator Season 2
(5599,  23,  71, 0, ''), -- Vengeful Gladiator Season 3
(5600,  23,  80, 0, ''), -- Brutal Gladiator Season 4
(6789,  23,  53, 0, ''), -- Champion of the Naaru
(7408,  23,  45, 0, ''), -- Challenger
(7412,  23,  42, 0, ''), -- Gladiator
(7415,  23,  43, 0, ''), -- Duelist - Duelist
(7416,  23,  42, 0, ''), -- Duelist - Gladiator
(7418,  23,  44, 0, ''), -- Rival - Rival
(7419,  23,  43, 0, ''), -- Rival - Duelist
(9058,  22,   4, 0, ''), -- 4th Anniversary
(9718,  23,  42, 0, ''), -- Rival - Gladiator
(9719,  23,  44, 0, ''), -- Challenger - Rival
(9720,  23,  43, 0, ''), -- Challenger - Duelist
(9721,  23,  42, 0, ''), -- Challenger - Gladiator
(10718, 23, 157, 0, ''), -- Deadly Gladiator Season 5
(10878, 23, 157, 0, ''), -- Challenger - Deadly Gladiator
(10879, 23, 157, 0, ''), -- Rival - Deadly Gladiator
(10881, 23, 157, 0, ''), -- Gladiator - Deadly Gladiator
(10898, 23, 167, 0, ''), -- Furious Gladiator Season 6
-- (11238,  0, 0, 0, ''), -- Jade Tiger
(11402, 23, 169, 0, ''), -- Relentless Gladiator Season 7
(12562, 22,   5, 0, ''), -- 5th Anniversary
(12912, 23, 177, 0, ''), -- Wrathful Gladiator Season 8
(12999, 23, 167, 0, ''), -- Gladiator - Furious Gladiator
(13000, 23, 169, 0, ''), -- Gladiator - Relentless Gladiator
(13001, 23, 157, 0, ''), -- Duelist - Deadly Gladiator
(13002, 23, 167, 0, ''), -- Duelist - Furious Gladiator
(13003, 23, 169, 0, ''), -- Duelist - Relentless Gladiator
(13004, 23, 167, 0, ''), -- Rival - Furious Gladiator
(13005, 23, 169, 0, ''), -- Rival - Relentless Gladiator
(13006, 23, 167, 0, ''), -- Challenger - Furious Gladiator
(13007, 23, 169, 0, ''); -- Challenger - Relentless Gladiator

DELETE FROM `achievement_reward` WHERE `entry` IN (432,2090,2091,2092,2093);
INSERT INTO `achievement_reward` (`entry`, `title_A`, `title_H`) VALUES
( 432,53,53), -- Champion of the Naaru
(2090,45,45), -- Challenger
(2091,42,42), -- Gladiator
(2092,43,43), -- Duelist
(2093,44,44); -- Rival

DELETE FROM `achievement_reward` WHERE `entry` IN (419,420,3336,3436,3758,4599);
INSERT INTO `achievement_reward` (`entry`, `sender`, `mailTemplate`) VALUES
( 419,18897,211), -- Vengeful Gladiator
( 420,18897,262), -- Brutal Gladiator
(3336,18897,266), -- Deadly Gladiator
(3436,18897,267), -- Furious Gladiator
(3758,18897,286), -- Relentless Gladiator
(4599,18897,287); -- Wrathful Gladiator

DELETE FROM `mail_loot_template` WHERE `entry` IN (211,262,266,267,286,287);
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(211,37676,100,1,0,1,1), -- Vengeful Gladiator
(262,43516,100,1,0,1,1), -- Brutal Gladiator
(266,46708,100,1,0,1,1), -- Deadly Gladiator
(267,46171,100,1,0,1,1), -- Furious Gladiator
(286,47840,100,1,0,1,1), -- Relentless Gladiator
(287,50435,100,1,0,1,1); -- Wrathful Gladiator
