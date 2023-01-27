-- Jung Duk Equipment
SET @EQUIP := 60801;
DELETE FROM `creature_equip_template` WHERE `entry`=@EQUIP;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EQUIP,76289,76289,0);

-- Jung Duk SAI
SET @ENTRY := 60801;
UPDATE `creature_template` SET `AIName`="SmartAI", `equipment_id`=60801 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,23,0,0,0,0,0,0,0,"Jung Duk - On Just Summoned - Say Line 0"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Jung Duk - On Respawn - Start Attacking"),
(@ENTRY,0,2,0,52,0,100,0,0,60801,0,0,45,1,0,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - On Text 0 Over - Set Data 1 0"),
(@ENTRY,0,3,0,2,0,100,1,0,90,0,0,45,1,1,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - Between 0-90% Health - Set Data 1 1 (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,70,0,0,45,1,2,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - Between 0-70% Health - Set Data 1 2 (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,20,0,0,45,1,3,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - Between 0-20% Health - Set Data 1 3 (No Repeat)"),
(@ENTRY,0,6,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jung Duk - Between 0-50% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,7,0,6,0,100,1,0,0,0,0,45,1,4,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - On Just Died - Set Data 1 4 (No Repeat)"),
(@ENTRY,0,8,0,6,0,100,1,0,0,0,0,45,1,5,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - On Just Died - Set Data 1 5 (No Repeat)"),
(@ENTRY,0,9,0,7,0,100,1,0,0,0,0,45,1,5,0,0,0,0,19,60735,200,0,0,0,0,0,"Jung Duk - On Evade - Set Data 1 5 (No Repeat)"),
(@ENTRY,0,10,0,0,0,100,0,8000,8000,15000,17000,11,127476,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jung Duk - In Combat - Cast Whirling Blades of the Chieftan"),
(@ENTRY,0,11,0,2,0,100,1,0,50,0,0,11,128809,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jung Duk - Between 0-50% Health - Cast Wounded Pride (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,14000,14000,20000,22000,11,123849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jung Duk - In Combat - Cast Goring Charge");

-- Katak the Defeated SAI
SET @ENTRY := 60735;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 0 - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 1 - Say Line 1 (No Repeat)"),
(@ENTRY,0,2,0,38,0,100,1,1,2,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 2 - Say Line 2 (No Repeat)"),
(@ENTRY,0,3,0,38,0,100,1,1,3,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 3 - Say Line 3 (No Repeat)"),
(@ENTRY,0,4,0,38,0,100,1,1,4,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 4 - Say Line 4 (No Repeat)"),
(@ENTRY,0,5,0,38,0,100,1,1,5,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Katak the Defeated - On Data Set 1 5 - Reset All Scripts (No Repeat)");

DELETE FROM `creature_text` WHERE `entry` = 60801;
DELETE FROM `creature_text` WHERE `entry` = 60735;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) values
('60801','0','0','Who dares to challenge me?','14','0','100','0','0','30854','Jung Duk - YELL_AGGRO.'),
('60801','1','0','Shut up, Katak!','14','0','100','0','0','30855','Jung Duk - YELL_SHUTUP_KATAK'),
('60735','0','0','Not running this time, Jung Duk?','12','0','100','0','0','28126','Katak - Jung Duk After Aggro.'),
('60735','1','0','Where are your lackeys, great chief? They cannot help you this time!','12','0','100','0','0','28127','Katak - Jung Duk After Aggro.'),
('60735','2','0','Deceit is no match for true strength! This one is more powerful than you!','12','0','100','0','0','28128','Katak - Jung Duk After Aggro.'),
('60735','3','0','I feel... at peace.','12','0','100','0','0','28129','Katak - Jung Duk After Aggro.'),
('60735','4','0','Ahahahaha! More than filth like you deserved.','12','0','100','0','0','28130','Katak - Jung Duk After Aggro.');
