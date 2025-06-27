-- 
DELETE FROM conditions WHERE SourceTypeOrReferenceId=13 AND SourceEntry=45872;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES
(13, 1, 45872, 0, 0, 31, 0, 3, 23837, 0, 0, 0, 0, '', 'Defibrillate');

SET @ENTRY := 25678;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Doctor Razorgin - On Aggro - Say Line 0 (random)'),
(@ENTRY,0,1,2,1,0,100,0,3000,3000,30000,30000,11,45872,0,0,0,0,0,1,0,0,0,0,0,0,0,'Doctor Razorgin - OOC - Cast Defibrillate'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Doctor Razorgin - Ooc - Say Line 1 (random)');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0,'Ah, good... more parts!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines',24872),
(@ENTRY,0,1,'Fresh meat!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines',24871),
(@ENTRY,0,2,'The doctor is in!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines',24870),
(@ENTRY,0,3,'I recommened evisceration!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines',24873),
(@ENTRY,1,0,'Clear!',14,0,100,0,0,0,'Part of the Doctor Razorgin ooc lines',24867),
(@ENTRY,1,1,'It''s no good... you need more work first.',14,0,100,0,0,0,'Part of the Doctor Razorgin ooc lines',24869),
(@ENTRY,1,2,'Live, damn you!',14,0,100,0,0,0,'Part of the Doctor Razorgin ooc lines',24868);

UPDATE `creature` SET `position_x`=4402.431152, `position_y`=4554.557129, `position_z`=88.743332, `orientation`=0.395920, `MovementType`=0, `spawndist`=0 WHERE `id`=@ENTRY;
