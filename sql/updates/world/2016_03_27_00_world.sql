DELETE FROM `creature_addon` WHERE `guid` IN(138281,138284,450189,450192);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(450189, 0, 0x0, 0x1, ''),
(450192, 0, 0x0, 0x1, '');

DELETE FROM `gameobject_addon` WHERE `guid` IN(45878,45947,300083,300014);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES
(300014, 7, 1),
(300083, 9, 100);

-- Aspiring Trainee SAI
SET @GUID := -138320;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450197;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450228;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138305;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138289;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450207;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138299;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450213;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
SET @GUID := -450189;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,120000,150000,300000,350000,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Say Line 1");
