--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000, `ScriptName` = "" WHERE `entry` = 17025;
DELETE FROM `creature_template_addon` WHERE `entry` = 17025;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(17025,0,0,0,1,0,0,"29327");
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 17025;
