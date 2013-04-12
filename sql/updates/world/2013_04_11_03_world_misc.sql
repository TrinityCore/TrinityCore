DELETE FROM `spell_target_position` WHERE `id`=52464;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(52464, 609, 2384.13, -5900.07, 107.998, 0);

UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry`=190767;

DELETE FROM `creature` WHERE `guid`=129164;
DELETE FROM `creature_addon` WHERE `guid`=129164;
