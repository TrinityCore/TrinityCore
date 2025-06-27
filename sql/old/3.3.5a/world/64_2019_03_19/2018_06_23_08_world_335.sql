-- 
SET @OGUID  =1532;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`animprogress`,`state`, `rotation2`, `rotation3`) VALUES
(@OGUID,103813,0,1,1,2388.808, 338.269, 37.013, 2.242750, 10, 255,1, -0.891996, -0.452044);

UPDATE `gameobject_template` SET `ScriptName`="" WHERE `entry` IN (104593,176594);
UPDATE `gameobject_template_addon` SET `flags`=`flags`|16 WHERE `entry` IN (176594,103813);
UPDATE `gameobject_template` SET `ScriptName`="" WHERE `entry` IN (104593,176594);
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (104593);
UPDATE `creature_template` SET `AIName`="SmartAI", `type_flags`=`type_flags`|2048 WHERE `entry` IN (6390);
DELETE FROM `smart_scripts` WHERE `entryorguid`=104593 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6390 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (639000,10459300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(104593,1,0,0,70,0,100,0,2,0,0,0,0,80,10459300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mausoleum Trigger - Gob activated - action list"),
(10459300,9,0,0,0,0,100,0,0,0,0,0,0,12,6390,3,180000,0,0,0,8,0,0,0,2390.26, 336.47, 40.01, 2.26,"Mausoleum Trigger - action list - Summon Ulag"),
(10459300,9,1,0,0,0,100,0,0,0,0,0,0,9,0,0,0,0,0,0,20,103813,50,0,0,0,0,0,"Mausoleum Trigger - action list - Activate gob"),
(10459300,9,2,0,0,0,100,0,3000,3000,0,0,0,9,0,0,0,0,0,0,20,176594,50,0,0,0,0,0,"Mausoleum Trigger - action list - Activate gob"),
(10459300,9,3,0,0,0,100,0,6000,6000,0,0,0,9,0,0,0,0,0,0,20,103813,50,0,0,0,0,0,"Mausoleum Trigger - action list - Activate gob"),
(6390,0,0,0,63,0,100,0,0,0,0,0,0,80,639000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ulag - On just summoned - action list"),
(639000,9,0,0,0,0,100,0,0,0,0,0,0,43,0,10721,0,0,0,0,1,0,0,0,0,0,0,0,"Ulag - action list - mount"),
(639000,9,1,0,0,0,100,0,4000,4000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2371.5554, 358.37, 38.092,0,"Ulag - action list - move to pos"),
(639000,9,2,0,0,0,100,0,4000,4000,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulag - action list - desmount"),
(6390,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulag - On evadde - despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=104593;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,104593,1,0,29,1,6390,100,0,1,0,0,"","SAI triggers if Ulag is not summoned");
