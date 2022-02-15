-- 
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=31786;
DELETE FROM `creature_template_addon` WHERE `entry`=31786;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(31786, 0, 0, 0, 0, 0, "35357 46011");
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=31776;
