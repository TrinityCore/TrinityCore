-- Void Zone
UPDATE `creature_template` SET `unit_flags` = `unit_flags` | 4 | 131072 WHERE `entry` = 34001;
-- Void Zone
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(34001, 0, 0, 0, 0, 0, "46262");
