-- Add waypoints, formation and condition of Drak'aguul
SET @GUID := 99649;
SET @PATHID := @GUID * 10;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=52457;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `comment`) VALUES 
(13, 1, 52457, 0, 1, 31, 0, 3, 26797, 0, 0, 0, 0, "Spell 'Drak'aguul's Soldiers' only hits Drakkari Protector"),
(13, 1, 52457, 0, 2, 31, 0, 3, 26795, 0, 0, 0, 0, "Spell 'Drak'aguul's Soldiers' only hits Drakkari Oracle");

DELETE FROM `creature_formations` WHERE `leaderGUID`=@GUID;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(@GUID, @GUID, 4, 0, 515),
(@GUID, 112163, 4, 45, 515),
(@GUID, 112352, 4, 315, 515);

UPDATE `creature_addon` SET `path_id`=@PATHID WHERE `guid`=@GUID;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2 WHERE `guid` IN (@GUID);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (112163, 112352);

DELETE FROM `waypoint_data` WHERE `id`=@PATHID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATHID, 1, 4475.12, -4909.09, 15.846),
(@PATHID, 2, 4476.58, -4895.84, 23.675),
(@PATHID, 3, 4476.62, -4889.59, 25.291),
(@PATHID, 4, 4474.50, -4880.82, 25.309),
(@PATHID, 5, 4474.56, -4865.42, 25.309),
(@PATHID, 6, 4474.50, -4880.82, 25.309),
(@PATHID, 7, 4476.62, -4889.59, 25.291),
(@PATHID, 8, 4476.58, -4895.84, 23.675),
(@PATHID, 9, 4475.12, -4909.09, 15.846),
(@PATHID, 10, 4474.54, -4923.89, 14.257),
(@PATHID, 11, 4475.81, -4938.72, 14.205),
(@PATHID, 12, 4475.48, -4955.87, 14.043),
(@PATHID, 13, 4475.82, -4966.02, 10.969),
(@PATHID, 14, 4475.77, -4976.62, 11.276),
(@PATHID, 15, 4475.82, -4966.02, 10.969),
(@PATHID, 16, 4475.48, -4955.87, 14.043),
(@PATHID, 17, 4475.81, -4938.72, 14.205),
(@PATHID, 18, 4474.54, -4923.89, 14.257);

-- Remove old SAI and weapon of Drakkari Oracle 
SET @ENTRY := 26795;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Oracle - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,12000,16000,11,52431,32,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Oracle - In Combat  - Cast 'Warped Body'"),
(@ENTRY,0,2,0,0,0,100,0,8000,10000,12000,16000,11,52430,32,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Oracle - In Combat  - Cast 'Warped Mind'");

DELETE FROM `creature_equip_template` WHERE `CreatureID`=@ENTRY;
UPDATE `creature` SET `equipment_id`=0 WHERE `id`=@ENTRY;
