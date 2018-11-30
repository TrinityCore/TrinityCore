--
DELETE FROM `creature` WHERE `guid` IN (86805,86806,86807);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86805, 29854, 571, 1, 1, 0, 0, 6649.39, -546.08, 1116.03, 0.844789, 300, 0, 0, 0, 0, 0),
(86806, 29854, 571, 1, 1, 0, 0, 6663.04, -553.344, 1118.56, 2.12891, 300, 0, 0, 0, 0, 0),
(86807, 29854, 571, 1, 1, 0, 0, 6705.8, -572.515, 1138.59, 6.16508, 300, 0, 0, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry`=29854;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes1`,`mount`,`auras`) VALUES (29854,0,1,0, '');
DELETE FROM `creature_addon` WHERE `guid`=75094;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (75094,0,0,0, '');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56393;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56393,0,0,31,0,3,29854,0,0,0,'',''),
(13,1,56393,0,0,1,0,56393,0,0,1,0,'','');
