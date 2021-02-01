-- High Justice Grimstone
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 131072, `RangeAttackTime` = 2000 WHERE `entry` = 10096;

-- Grobbulus Cloud
UPDATE `creature_template` SET `speed_walk` = 0.004, `speed_run` = 0.00142857, `unit_flags` = `unit_flags` &~ 131072 WHERE `entry` IN (16363,29379);

-- Hellfire Training Dummy
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` &~ 131072 WHERE `entry` = 17578;
DELETE FROM `creature_template_addon` WHERE `entry` = 17578;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(17578,0,0,0,1,0,0,"7056");

-- The Lich King
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 131072 WHERE `entry` = 24248;

-- Defeated Argent Footman
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 28156;
UPDATE `creature_template` SET `unit_flags` = 33536, `dynamicflags` = 0 WHERE `entry` = 28156;
UPDATE `smart_scripts` SET `action_param2` = 2 WHERE `entryorguid` = 28156 AND `source_type` = 0 AND `id` IN (0,1);

-- Alexstrasza the Life-Binder
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 131072 WHERE `entry` = 31333;

-- Infernal Attacker
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 256+33554432 WHERE `entry` IN (21419,21786);
