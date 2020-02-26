-- 
SET @ENTRY := 177491;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432, `AIName`='SmartAI' WHERE `entry`=12120; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12120 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,2,19,0,100,0,6390,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,1,2,19,0,100,0,6389,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,2,3,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,3,4,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,4,5,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,5,6,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,6,7,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,7,8,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,8,9,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,9,10,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,10,11,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,11,12,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,12,13,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,13,14,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,14,15,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,15,16,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,16,17,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,17,18,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,18,19,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,19,20,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,20,21,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,21,22,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,22,23,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,23,24,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,24,25,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,25,26,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,26,27,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,27,28,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,28,29,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,29,30,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(@ENTRY,1,30,0,61,0,100,0,0,0,0,0,12,12120,3,60000,0,0,0,1,0,0,0,0,0,0,0, "Termite Barrel - On quest accepted - summon creature"),
(12120, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,0,0,0, 'Plagueland Termite - On Spawn - Random movments');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =@ENTRY AND `SourceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@ENTRY,1,0,29,0,12120,40,0,1,0,'','Plagueland Termite only spawns if not present'),
(22,2,@ENTRY,1,0,29,0,12120,40,0,1,0,'','Plagueland Termite only spawns if not present');

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 12120;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Random`) VALUES
(12120, 1, 1, 0, 2);
