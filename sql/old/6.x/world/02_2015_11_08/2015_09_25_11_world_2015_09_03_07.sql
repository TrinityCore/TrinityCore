-- 
UPDATE `creature_template` SET `spell1`=49297 WHERE `entry` IN (27664,40281);
DELETE FROM `creature_template_addon` WHERE `entry` IN (27664,40281);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(27664,0,0,0,0,0,'49384'),
(40281,0,0,0,0,0,'75110');
