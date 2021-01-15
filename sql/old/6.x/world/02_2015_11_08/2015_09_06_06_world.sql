-- Actionlist SAI
SET @ACTIONLIST := 5458700;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@ACTIONLIST,@ACTIONLIST+1,@ACTIONLIST+2,@ACTIONLIST+3) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ACTIONLIST+0,9,0,0,0,0,100,1,1000,1000,0,0,5,509,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 509 (No Repeat)"),
(@ACTIONLIST+1,9,0,0,0,0,100,1,1000,1000,0,0,5,543,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 543 (No Repeat)"),
(@ACTIONLIST+2,9,0,0,0,0,100,1,1000,1000,0,0,5,511,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 511 (No Repeat)"),
(@ACTIONLIST+3,9,0,0,0,0,100,1,1000,1000,0,0,5,507,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 507 (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 5458704;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,0,0,0,0,18,33554688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Script - Set Flags Immune To Players & Not Selectable (No Repeat)"),
(@ENTRY,9,1,0,0,0,100,1,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Script - Combat Stop (No Repeat)"),
(@ENTRY,9,2,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tushui Trainee - On Script - Say Line 0 (No Repeat)"),
(@ENTRY,9,3,0,0,0,100,1,0,0,0,0,41,4000,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Script - Despawn Instant (No Repeat)");

UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry` IN (65471,65470,54587,54586);
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=53714;

-- Tushui Trainee SAI
SET @ENTRY := 54587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,38,1,100,0,1,1,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 1 - Run Script"),
(@ENTRY,0,2,0,38,1,100,0,1,2,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 2 - Run Script"),
(@ENTRY,0,3,0,38,1,100,0,1,3,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 3 - Run Script"),
(@ENTRY,0,4,0,38,1,100,0,1,4,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 4 - Run Script"),
(@ENTRY,0,5,0,0,0,100,0,2000,2000,2000,2000,11,109080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tushui Trainee - In Combat - Cast 'Blackout Kick'"),
(@ENTRY,0,6,7,2,0,100,1,0,10,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Run Script (No Repeat)"),
(@ENTRY,0,7,8,61,0,100,0,0,10,0,0,33,54586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Quest Credit '54586' (No Repeat)"),
(@ENTRY,0,8,0,61,0,100,0,0,10,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Set Event Phase 2 (No Repeat)"),
(@ENTRY,0,9,0,25,0,100,0,0,0,0,0,42,0,10,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Set Invincibility Hp 10%"),
(@ENTRY,0,10,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Set Event Phase 1"),
(@ENTRY,0,11,0,25,0,100,0,0,0,0,0,19,33554688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Remove Flags Immune To Players & Not Selectable");

-- Tushui Trainee SAI
SET @ENTRY := 65471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,38,1,100,0,1,1,0,0,80,54587*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 1 - Run Script"),
(@ENTRY,0,2,0,38,1,100,0,1,2,0,0,80,54587*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 2 - Run Script"),
(@ENTRY,0,3,0,38,1,100,0,1,3,0,0,80,54587*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 3 - Run Script"),
(@ENTRY,0,4,0,38,1,100,0,1,4,0,0,80,54587*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Data Set 1 4 - Run Script"),
(@ENTRY,0,5,0,0,0,100,0,2000,2000,2000,2000,11,109080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tushui Trainee - In Combat - Cast 'Blackout Kick'"),
(@ENTRY,0,6,7,2,0,100,1,0,10,0,0,80,54587*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Run Script (No Repeat)"),
(@ENTRY,0,7,8,61,0,100,0,0,10,0,0,33,54586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Quest Credit '54586' (No Repeat)"),
(@ENTRY,0,8,0,61,0,100,0,0,10,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - Between 0-10% Health - Set Event Phase 2 (No Repeat)"),
(@ENTRY,0,9,0,25,0,100,0,0,0,0,0,42,0,10,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Set Invincibility Hp 10%"),
(@ENTRY,0,10,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Set Event Phase 1"),
(@ENTRY,0,11,0,25,0,100,0,0,0,0,0,19,33554688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tushui Trainee - On Reset - Remove Flags Immune To Players & Not Selectable");

-- Instructor Zhi SAI
SET @ENTRY := 61411;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,4000,4000,19000,19000,5,509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Zhi - Out of Combat - Play Emote 509"),
(@ENTRY,0,1,2,61,0,100,0,4000,4000,19000,19000,45,1,1,0,0,0,0,9,54587,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 1"),
(@ENTRY,0,2,0,61,0,100,0,4000,4000,19000,19000,45,1,1,0,0,0,0,9,65471,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 1"),
(@ENTRY,0,3,4,1,0,100,0,9000,9000,19000,19000,5,543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Zhi - Out of Combat - Play Emote 543"),
(@ENTRY,0,4,5,61,0,100,0,9000,9000,19000,19000,45,1,2,0,0,0,0,9,54587,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 2"),
(@ENTRY,0,5,0,61,0,100,0,9000,9000,19000,19000,45,1,2,0,0,0,0,9,65471,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 2"),
(@ENTRY,0,6,7,1,0,100,0,14000,14000,19000,19000,5,511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Zhi - Out of Combat - Play Emote 511"),
(@ENTRY,0,7,8,61,0,100,0,14000,14000,19000,19000,45,1,3,0,0,0,0,9,54587,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 3"),
(@ENTRY,0,8,0,61,0,100,0,14000,14000,19000,19000,45,1,3,0,0,0,0,9,65471,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 3"),
(@ENTRY,0,9,10,1,0,100,0,19000,19000,19000,19000,5,507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Zhi - Out of Combat - Play Emote 507"),
(@ENTRY,0,10,11,61,0,100,0,19000,19000,19000,19000,45,1,4,0,0,0,0,9,54587,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 4"),
(@ENTRY,0,11,0,61,0,100,0,19000,19000,19000,19000,45,1,4,0,0,0,0,9,65471,0,15,0,0,0,0,"Instructor Zhi - Out of Combat - Set Data 1 4");

DELETE FROM `gameobject_questitem` WHERE `GameObjectEntry` IN(210015,210016,210017,210018,210019,210020);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`,`Idx`,`ItemId`) VALUES
(210015, 0, 76392),
(210015, 1, 76390),
(210016, 0, 73211),
(210017, 0, 73207),
(210017, 1, 76393),
(210018, 0, 73208),
(210018, 1, 73212),
(210019, 0, 76391),
(210019, 1, 73213),
(210020, 0, 73210);

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN(40856,40859,40860,40861,40862,40863,40864);
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Chance`,`QuestRequired`) VALUES
(40856,73209,100,1),
(40859,76392,100,1),
(40859,76390,100,1),
(40860,73211,100,1),
(40861,73207,100,1),
(40861,76393,100,1),
(40862,73208,100,1),
(40862,73212,100,1),
(40863,76391,100,1),
(40863,73213,100,1),
(40864,73210,100,1);

DELETE FROM `creature_template_addon` WHERE `entry` IN(65470,54586,54587,65471,61411,54611,57753,53714,53565,57752,65469,57748);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(65470, 0, 0x0, 0x1, 510, ''),
(54586, 0, 0x0, 0x1, 510, ''),
(54587, 0, 0x0, 0x1, 510, ''),
(65471, 0, 0x0, 0x1, 510, ''),
(61411, 0, 0x0, 0x1, 510, ''),
(54611, 0, 0x1, 0x1, 0, ''),
(57753, 0, 0x0, 0x1, 510, ''),
(53714, 0, 0x0, 0x1, 0, ''),
(53565, 0, 0x0, 0x1, 510, ''),
(57752, 0, 0x0, 0x1, 510, ''),
(57748, 0, 0x0, 0x1, 510, ''),
(65469, 0, 0x0, 0x1, 510, '');

DELETE FROM `creature_addon` WHERE `guid` IN(138281,138284);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(138281, 0, 0x0, 0x1, ''),
(138284, 0, 0x0, 0x1, '');
