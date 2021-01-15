--
SET @Guid := 14218;

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`IN(181045,181051);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`IN(181045,181051);

DELETE FROM `gameobject` WHERE `id` IN(181096,181048);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(@Guid,181096,429,1,1,263.38,-452.69,-119.96,0,0,0,0,0,180,0,1),
(@Guid+1,181096,229,1,1,-23.97,-451.98,-18.64,0,0,0,0,0,180,0,1),
(@Guid+2,181096,289,1,1,-3.82,141.88,83.9,0,0,0,0,0,180,0,1),
(@Guid+3,181096,229,1,1,25.92,-537.7,110.93,0,0,0,0,0,180,0,1),
(@Guid+4,181096,329,1,1,3423.47,-3055.73,136.499,6.00568,0,0,0.138306,-0.990389,300,0,1),
(@Guid+5, 181048, 329, 1, 1, 3423.47, -3055.73, 136.499, 6.00568, 0, 0, 0.138306, -0.990389, 300, 0, 1);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181045, 1, 0 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,45841,16044,0,0,0,0,0, 'Brazier of Beckoning - On Spawn - Set Data Mor Grayhoof Trigger'),
(181045, 1, 1 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,48937,16047,0,0,0,0,0, 'Brazier of Beckoning - On Spawn - Set Data Kormok Trigger'),
(181045, 1, 2 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,84386,16045,0,0,0,0,0, 'Brazier of Beckoning - On Spawn - Set Data Isalien Trigger'),
(181045, 1, 3 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,53937,16046,0,0,0,0,0, 'Brazier of Beckoning - On Spawn - Set Data Jarien and Sothos Trigger'),
(181045, 1, 4 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,137927,16048,0,0,0,0,0, 'Brazier of Beckoning - On Spawn - Set Data Lord Valthalak Trigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=181045;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 181045, 1, 0, 23, 1, 1583, 0, 0, 0, 0, 0, '', 'Brazier of Beckoning only run SAI in Blackrock Spire'),
(22, 2, 181045, 1, 0, 23, 1, 2057, 0, 0, 0, 0, 0, '', 'Brazier of Beckoning only run SAI in Scholomance'),
(22, 3, 181045, 1, 0, 23, 1, 2557, 0, 0, 0, 0, 0, '', 'Brazier of Beckoning only run SAI in Dire Maul'),
(22, 4, 181045, 1, 0, 23, 1, 2017, 0, 0, 0, 0, 0, '', 'Brazier of Beckoning only run SAI in Stratholme'),
(22, 5, 181045, 1, 0, 23, 1, 1583, 0, 0, 0, 0, 0, '', 'Brazier of Beckoning only run SAI in Blackrock Spire');

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181051, 1, 0 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,45841,16044,0,0,0,0,0, 'Brazier of Invocation - On Spawn - Set Data Mor Grayhoof Trigger'),
(181051, 1, 1 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,48937,16047,0,0,0,0,0, 'Brazier of Invocation - On Spawn - Set Data Kormok Trigger'),
(181051, 1, 2 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,84386,16045,0,0,0,0,0, 'Brazier of Invocation - On Spawn - Set Data Isalien Trigger'),
(181051, 1, 3 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,53937,16046,0,0,0,0,0, 'Brazier of Invocation - On Spawn - Set Data Jarien and Sothos Trigger'),
(181051, 1, 4 ,0, 11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,10,137927,16048,0,0,0,0,0, 'Brazier of Invocation - On Spawn - Set Data Lord Valthalak Trigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=181051;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 181051, 1, 0, 23, 1, 1583, 0, 0, 0, 0, 0, '', 'Brazier of Invocation only run SAI in Blackrock Spire'),
(22, 2, 181051, 1, 0, 23, 1, 2057, 0, 0, 0, 0, 0, '', 'Brazier of Invocation only run SAI in Scholomance'),
(22, 3, 181051, 1, 0, 23, 1, 2557, 0, 0, 0, 0, 0, '', 'Brazier of Invocation only run SAI in Dire Maul'),
(22, 4, 181051, 1, 0, 23, 1, 2017, 0, 0, 0, 0, 0, '', 'Brazier of Invocation only run SAI in Stratholme'),
(22, 5, 181051, 1, 0, 23, 1, 1583, 0, 0, 0, 0, 0, '', 'Brazier of Invocation only run SAI in Blackrock Spire');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=16044;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16044;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16044, 0, 0, 0, 38,  0, 100, 1, 1, 1, 0, 0, 12, 16080, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mor Grayhoof Trigger - On Data Set - Spawn Mor Grayhoof');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=16045;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16045;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16045, 0, 0, 0, 38,  0, 100, 1, 1, 1, 0, 0, 12, 16097, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Isalien Trigger - On Data Set - Spawn Isalien');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=16046;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16046;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16046, 0, 0, 1, 38,  0, 100, 1, 1, 1, 0, 0, 12, 16101, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jarien and Sothos Trigger - On Data Set - Spawn Jarien'),
(16046, 0, 1, 0, 61,  0, 100, 1, 1, 1, 0, 0, 12, 16102, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jarien and Sothos Trigger - Linked with Previous Event - Spawn Sothos');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=16047;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16047;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16047, 0, 0, 0, 38,  0, 100, 1, 1, 1, 0, 0, 12, 16118, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kormok Trigger - On Data Set - Spawn Kormok');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=16048;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16048;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16048, 0, 0, 0, 38,  0, 100, 1, 1, 1, 0, 0, 12, 16042, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lord Valthalak Trigger - On Data Set - Spawn Lord Valthalak');
