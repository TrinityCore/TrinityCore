SET @CGUID := 254061;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -842.4097, -659.1024, 831.901, 0, 249),
(@PATH, 1, -842.6354, -643.3143, 831.9013, 0, -768),
(@PATH, 2, -845.6443, -630.6788, 831.9009, 0, -933),
(@PATH, 3, -851.9236, -615.9549, 831.9012, 0, -1713),
(@PATH, 4, -858.941, -605.8246, 831.9009, 0, -1803),
(@PATH, 5, -868.1458, -594.6719, 831.9009, 0, -990),
(@PATH, 6, -878.0174, -585.4393, 831.9009, 0, -1492),
(@PATH, 7, -890.8246, -583.9236, 831.9009, 0, 1037),
(@PATH, 8, -878.0174, -585.4393, 831.9009, 0, -1378),
(@PATH, 9, -868.1458, -594.6719, 831.9009, 0, -1706),
(@PATH, 10, -858.941, -605.8246, 831.9009, 0, -929),
(@PATH, 11, -851.9236, -615.9549, 831.9012, 0, -1056),
(@PATH, 12, -845.6736, -630.5555, 831.9009, 0, -1826),
(@PATH, 13, -842.6354, -643.3143, 831.9013, 0, -749);

UPDATE `creature` SET `position_x`= -842.4097, `position_y`= -659.1024, `position_z`= 831.901, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

UPDATE `creature_template` SET `difficulty_entry_1`= 49814, `ScriptName`= 'npc_bot_evolved_drakonaar' WHERE `entry`= 49813;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `BaseAttackTime`= 1500, `mechanic_immune_mask`= 650854271, `unit_flags`= 32832 WHERE `entry` IN (49813, 49814);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_bot_twilight_rupture';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93377, 'spell_bot_twilight_rupture');
