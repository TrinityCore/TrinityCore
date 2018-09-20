DELETE FROM `creature_equip_template` WHERE  `CreatureID`=794 AND `ID`=1;
INSERT INTO `creature_equip_template` (`CreatureID`, `ItemID1`) VALUES
(794, 1117);

-- Matt SAI
SET @ENTRY := 794;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,512,0,0,0,0,53,0,794,1,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,512,1,794,0,0,54,3597000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,512,1,794,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,512,26,794,0,0,54,900000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 26 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,512,26,794,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 26 Reached - Run Script"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,71,1,0,1117,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,-9387.45,-117.388,58.8643,2.61799,"Matt - On Script - Set Orientation 2,61799"),
(@ENTRY*100+00,9,2,0,0,0,100,0,3597000,3597000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Say Line 0"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,71,1,0,1117,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+01,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,-9429.23,148.94,56.5713,2.118,"Matt - On Script - Set Orientation 2,118"),
(@ENTRY*100+01,9,2,0,0,0,100,0,897000,897000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Say Line 1"),
(@ENTRY*100+01,9,3,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment");
