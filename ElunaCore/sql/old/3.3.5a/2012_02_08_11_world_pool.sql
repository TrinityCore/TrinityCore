-- Toxic Tolerance questchain for a horde specific mount requires doing
-- daily quests. However currently all of those are acceptable daily, though
-- only one (random) should be.
-- Source: http://www.wowhead.com/quest=13917/gorishi-grub#comments:id=829822
SET @pool1_id := 350; -- Orcs, Bloodelves
SET @pool2_id := 351; -- Undead, Tauren, Troll

-- create new pools, each allowing only 1 out of 4 dailys per day
DELETE FROM `pool_template` WHERE `entry` IN (@pool1_id, @pool2_id);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool1_id, 1, 'Toxic Tolerance Daily-Quests'),
(@pool2_id, 1, 'Toxic Tolerance Daily-Quests');

-- fill pools with the daily quests, starting from Venomhide Hatchling (c34320)
DELETE FROM `pool_quest` WHERE `entry` IN (13889, 13915, 13903, 13904, 13905, 13917, 13916, 13914) AND `pool_entry` IN (@pool1_id, @pool2_id);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(13889, @pool1_id, 'Hungry, Hungry Hatchling'),
(13903, @pool1_id, 'Gorishi Grub'),
(13904, @pool1_id, 'Poached, Scrambled, Or Raw?'),
(13905, @pool1_id, 'Searing Roc Feathers'),
(13915, @pool2_id, 'Hungry, Hungry Hatchling'),
(13917, @pool2_id, 'Gorishi Grub'),
(13916, @pool2_id, 'Poached, Scrambled, Or Raw?'),
(13914, @pool2_id, 'Searing Roc Feathers');
