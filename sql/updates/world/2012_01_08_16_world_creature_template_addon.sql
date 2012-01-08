-- Apply Image of Arthas Visual Effect
DELETE FROM `creature_template_addon` WHERE `entry` = 29280;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('29280', '0', '0', '0', '1', '0', '54134');
