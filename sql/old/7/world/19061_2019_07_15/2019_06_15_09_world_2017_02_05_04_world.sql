UPDATE `creature` SET `position_x`=-11187.9, `position_y`=-1883.373, `position_z`=156.0449, `orientation`=5.375582, `spawndist`=0 WHERE `guid`=135489;
UPDATE `creature_template` SET `unit_flags`=33554432, `flags_extra`=256, `ScriptName`='npc_curator_astral_flare' WHERE `entry` IN (17096,19781,19782,19783);

DELETE FROM `creature_template_addon` WHERE `entry` IN (17096,19781,19782,19783);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(19781,0,0,0,1,0,30234),
(19782,0,0,0,1,0,30234),
(19783,0,0,0,1,0,30234),
(17096,0,0,0,1,0,30234);

DELETE FROM `waypoint_data` WHERE `id`=1354890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1354890, 1, -11172.98, -1902.532, 165.7656, 0, 0, 0, 0, 100, 0),
(1354890, 2, -11160.56, -1901.736, 165.7654, 0, 0, 0, 0, 100, 0),
(1354890, 3, -11104.56, -1856.968, 165.7654, 0, 0, 0, 0, 100, 0),
(1354890, 4, -11114.04, -1864.641, 165.7654, 0, 0, 0, 0, 100, 0),
(1354890, 5, -11166.35, -1906.356, 165.7654, 0, 0, 0, 0, 100, 0),
(1354890, 6, -11170.42, -1906.521, 165.7654, 0, 0, 0, 0, 100, 0),
(1354890, 7, -11180.58, -1892.599, 160.9129, 0, 0, 0, 0, 100, 0),
(1354890, 8, -11194.23, -1875.336, 153.5438, 0, 0, 0, 0, 100, 0);
