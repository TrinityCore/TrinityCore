-- 
DELETE FROM `creature` WHERE `guid` IN (96886);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(96886, 17889, 530, 1, 1, 0, 0, -2143.43, -10692, 64.7658, 4.93928, 300, 0, 0, 42, 0, 0);

UPDATE `conditions` SET `ConditionValue2`=17889, `ConditionValue3`=63610 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31411;
UPDATE `conditions` SET `ConditionValue2`=17889, `ConditionValue3`=96886 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31412;
UPDATE `conditions` SET `ConditionValue2`=17889, `ConditionValue3`=63611 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31413;
UPDATE `conditions` SET `ConditionValue2`=17889, `ConditionValue3`=63609 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31414;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (17889,17886);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (184850,182026);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-63583,-63584,-63585,-63582) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (184850,182026) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-63583,0,0,0,11,0,100,0,0,0,0,0,11,31411,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sunhawk Portal Controller - On respawn - cast Stabilize Sun Gate I'),
(-63584,0,0,0,11,0,100,0,0,0,0,0,11,31412,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sunhawk Portal Controller - On respawn - cast Stabilize Sun Gate II'),
(-63585,0,0,0,11,0,100,0,0,0,0,0,11,31413,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sunhawk Portal Controller - On respawn - cast Stabilize Sun Gate III'),
(-63582,0,0,0,11,0,100,0,0,0,0,0,11,31414,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sunhawk Portal Controller - On respawn - cast Stabilize Sun Gate IV'),
(184850,1,0,0,70,0,100,0,2,0,0,0,51,0,0,0,0,0,0,19,17886,5,0,0,0,0,0,"Sunhawk Portal Controller - Gob activated - Kill target"),
(182026,1,0,0,60,0,100,0,2000,2000,2000,2000,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sun Gate - Update - add flag"),
(182026,1,1,0,60,0,100,0,2000,2000,2000,2000,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sun Gate - Update - remove flag");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(182026);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 182026, 1, 0, 30, 1, 184850, 60, 0, 0, 0, 0, '', 'Sun Gate - Only run SAI if gob in range'),
(22, 2, 182026, 1, 0, 30, 1, 184850, 60, 0, 1, 0, 0, '', 'Sun Gate - Only run SAI if no gob in range');

UPDATE `creature` SET `spawntimesecs`=30 WHERE `id`=17886; 
UPDATE `gameobject` SET `spawntimesecs`=30 WHERE `id`=184850; 

UPDATE `creature` SET `position_x`=-2147.350098, `position_y`=-10741.099609, `position_z`=73.903397 WHERE `guid`=63583; 
UPDATE `creature` SET `position_x`=-2128.939941, `position_y`=-10726.000000, `position_z`=66.335800 WHERE `guid`=63584; 
UPDATE `creature` SET `position_x`=-2107.070068, `position_y`=-10703.000000, `position_z`=65.189400 WHERE `guid`=63585; 
UPDATE `creature` SET `position_x`=-2098.620117, `position_y`=-10688.500000, `position_z`=65.218102 WHERE `guid`=63582;
