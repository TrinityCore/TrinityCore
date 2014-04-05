-- Deadwood Avenger SAI
SET @ENTRY := 7157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,5000,5000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Avenger - In Combat - Cast 13583"),
(@ENTRY,0,1,2,2,0,100,1,0,30,15000,15000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Avenger - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,15000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Avenger - Between 0-30% Health - Say Line 0");

-- Texts for Deadwood Avenger
SET @ENTRY := 7157;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Deadwood Avenger");

-- Polly SAI
SET @ENTRY := 7167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,73000,73000,60000,60000,11,8822,0,0,0,0,0,1,0,0,0,0,0,0,0,"Polly - Out Of Combat - Cast 8822"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,9998,0,0,0,0,0,1,0,0,0,0,0,0,0,"Polly - On Aggro - Cast 9998");

-- Stonevault Ambusher SAI
SET @ENTRY := 7175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,8721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Ambusher - In Combat - Cast 8721 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Ambusher - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Ambusher - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Ambusher - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Texts for Stonevault Ambusher
SET @ENTRY := 7175;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stonevault Ambusher");

-- Galgann Firehammer SAI
SET @ENTRY := 7291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galgann Firehammer - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,11000,20000,30000,11,8053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galgann Firehammer - In Combat - Cast 8053 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,13000,16000,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galgann Firehammer - In Combat - Cast 11969 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,2000,5000,13000,18000,11,3356,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galgann Firehammer - In Combat - Cast 3356 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,5000,6000,14000,19000,11,9482,32,0,0,0,0,5,0,0,0,0,0,0,0,"Galgann Firehammer - In Combat - Cast 9482 (Normal Dungeon)");

-- Texts for Galgann Firehammer
SET @ENTRY := 7291;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"By Thaurissan's beard! Slay them!",14,0,100,0,0,5852,"Galgann Firehammer");

-- Stonevault Mauler SAI
SET @ENTRY := 7320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,7000,10000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Mauler - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,2,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Mauler - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Mauler - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Stonevault Mauler
SET @ENTRY := 7320;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stonevault Mauler");

-- Withered Warrior SAI
SET @ENTRY := 7327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,50,2,0,30,120000,125000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Warrior - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Warrior - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,20000,8000,15000,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Warrior - In Combat - Cast 6268 (Normal Dungeon)");

-- Texts for Withered Warrior
SET @ENTRY := 7327;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Withered Warrior");

-- Withered Reaver SAI
SET @ENTRY := 7328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,2,0,30,120000,125000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Reaver - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Reaver - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,8000,3000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Reaver - In Combat - Cast 40504 (Normal Dungeon)");

-- Texts for Withered Reaver
SET @ENTRY := 7328;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Withered Reaver");

-- Texts for Withered Quilguard
SET @ENTRY := 7329;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Withered Quilguard");

-- Withered Quilguard SAI
SET @ENTRY := 7329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,2,0,30,120000,125000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Quilguard - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Quilguard - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Tuten'kash SAI
SET @ENTRY := 7355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,6000,8000,11,12252,32,0,0,0,0,5,0,0,0,0,0,0,0,"Tuten'kash - In Combat - Cast 12252 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,15000,25000,11,12255,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tuten'kash - In Combat - Cast 12255 (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,34,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tuten'kash - On Aggro - Set Instance Data Field To 0 To Data 1 (Normal Dungeon)"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,34,0,3,0,0,0,0,1,0,0,0,0,0,0,0,"Tuten'kash - On Death - Set Instance Data Field To 0 To Data 3 (Normal Dungeon)"),
(@ENTRY,0,4,0,7,0,100,3,0,0,0,0,34,0,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tuten'kash - On Evade - Set Instance Data Field To 0 To Data 2 (Normal Dungeon)");

-- Shardtooth Mauler SAI
SET @ENTRY := 7443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,8000,8000,12000,12000,11,15793,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shardtooth Mauler - In Combat - Cast 15793");

-- Shardtooth Bear SAI
SET @ENTRY := 7444;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,25000,25000,11,3604,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shardtooth Bear - In Combat - Cast 3604");

-- Elder Shardtooth SAI
SET @ENTRY := 7445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,8000,8000,12000,12000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shardtooth - In Combat - Cast 15971");

-- Rabid Shardtooth SAI
SET @ENTRY := 7446;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,1,0,0,8000,8000,11,3150,32,0,0,0,0,5,0,0,0,0,0,0,0,"Rabid Shardtooth - In Combat - Cast 3150"),
(@ENTRY,0,1,0,0,0,75,0,8000,8000,12000,12000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rabid Shardtooth - In Combat - Cast 3391");

-- Razorfen Battleguard SAI
SET @ENTRY := 7873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,9000,15000,11,11430,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorfen Battleguard - In Combat - Cast 11430");

-- Razorfen Thornweaver SAI
SET @ENTRY := 7874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7966,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Thornweaver - On Aggro - Cast 7966"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,11,11431,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Thornweaver - Between 0-25% Health - Cast 11431");

-- Dark Iron Land Mine SAI
SET @ENTRY := 8035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Land Mine - Out Of Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Land Mine - Out Of Combat - Say Line 1 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,3,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Land Mine - Out Of Combat - Say Line 2 (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,3,0,8,0,0,11,4043,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Land Mine - Between 0-8 Range - Cast 4043 (Normal Dungeon)"),
(@ENTRY,0,4,0,9,0,100,3,0,8,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Land Mine - Between 0-8 Range - Forced Despawn (Normal Dungeon)");

-- Omgorn the Lost SAI
SET @ENTRY := 8201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,10000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Omgorn the Lost - In Combat - Cast 16856"),
(@ENTRY,0,1,2,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Omgorn the Lost - Between 0-50% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Omgorn the Lost - Between 0-50% Health - Say Line 0");

-- Texts for Dark Iron Land Mine
SET @ENTRY := 8035;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s will be armed in 10 seconds!",16,0,100,0,0,0,"Dark Iron Land Mine"),
(@ENTRY,1,0,"%s will be armed in 5 seconds!",16,0,100,0,0,5871,"Dark Iron Land Mine"),
(@ENTRY,2,0,"%s is now armed!",16,0,100,0,0,0,"Dark Iron Land Mine");

-- Texts for Omgorn the Lost
SET @ENTRY := 8201;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Omgorn the Lost");

-- Bloodhound SAI
SET @ENTRY := 8921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,17000,20000,11,13692,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodhound - In Combat - Cast 13692 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,11000,11,13445,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodhound - Between 0-5 Range - Cast 13445 (Normal Dungeon)");

-- Dredge Worm SAI
SET @ENTRY := 8925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dredge Worm - On Aggro - Cast 14535 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,8000,8000,11,13298,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dredge Worm - In Combat - Cast 13298 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,70,2,4000,4000,3000,3000,11,6917,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dredge Worm - In Combat - Cast 6917 (Normal Dungeon)");

-- Deep Stinger SAI
SET @ENTRY := 8926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Stinger - On Aggro - Cast 14534 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,5000,5000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Stinger - In Combat - Cast 40504 (Normal Dungeon)");

-- Dark Screecher SAI
SET @ENTRY := 8927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14538,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Screecher - On Aggro - Cast 14538 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,18000,18000,11,8281,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Screecher - In Combat - Cast 8281 (Normal Dungeon)");

-- Burrowing Thundersnout SAI
SET @ENTRY := 8928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burrowing Thundersnout - On Aggro - Cast 14533 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,3000,3000,11,15611,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burrowing Thundersnout - In Combat - Cast 15611 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,70,2,4000,4000,8000,8000,11,15548,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burrowing Thundersnout - In Combat - Cast 15548 (Normal Dungeon)");

-- Borer Beetle SAI
SET @ENTRY := 8932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14539,0,0,0,0,0,2,0,0,0,0,0,0,0,"Borer Beetle - On Aggro - Cast 14539 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,45000,45000,11,6016,0,0,0,0,0,5,0,0,0,0,0,0,0,"Borer Beetle - In Combat - Cast 6016 (Normal Dungeon)");

-- Cave Creeper SAI
SET @ENTRY := 8933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cave Creeper - On Aggro - Cast 14532 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,8000,8000,11,745,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cave Creeper - In Combat - Cast 745 (Normal Dungeon)");

-- Angerclaw Bear SAI
SET @ENTRY := 8956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,120000,120000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Bear - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Bear - Between 0-30% Health - Say Line 0");

-- Texts for Angerclaw Bear
SET @ENTRY := 8956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Angerclaw Bear");

-- Angerclaw Grizzly SAI
SET @ENTRY := 8957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Grizzly - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Grizzly - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,0,0,75,0,8000,8000,16000,16000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Grizzly - In Combat - Cast 8716");

-- Texts for Angerclaw Grizzly
SET @ENTRY := 8957;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Angerclaw Grizzly");

-- Angerclaw Mauler SAI
SET @ENTRY := 8958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Mauler - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Mauler - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,0,0,60,0,12000,12000,21000,21000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Mauler - In Combat - Cast 15793");

-- Texts for Angerclaw Mauler
SET @ENTRY := 8958;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Angerclaw Mauler");

-- Ironhand Guardian SAI
SET @ENTRY := 8982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,16000,16000,11,15529,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironhand Guardian - In Combat - Cast 15529 (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,4000,4000,16000,16000,11,15529,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironhand Guardian - Out Of Combat - Cast 15529 (Normal Dungeon)");

-- Golem Lord Argelmach SAI
SET @ENTRY := 8983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Golem Lord Argelmach - On Aggro - Cast 15507 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,14000,14000,15000,15000,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Golem Lord Argelmach - In Combat - Cast 15305 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,6000,7000,7000,11,15605,0,0,0,0,0,2,0,0,0,0,0,0,0,"Golem Lord Argelmach - In Combat - Cast 15605 (Normal Dungeon)");

-- Bael'Gar SAI
SET @ENTRY := 9016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,10000,14000,11,13880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'Gar - In Combat - Cast 13880 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,82,0,0,11,13895,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bael'Gar - Between 0-82% Health - Cast 13895 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,62,0,0,11,13895,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bael'Gar - Between 0-62% Health - Cast 13895 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,42,0,0,11,13895,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bael'Gar - Between 0-42% Health - Cast 13895 (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,22,0,0,11,13895,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bael'Gar - Between 0-22% Health - Cast 13895 (Normal Dungeon)");

-- Lord Incendius SAI
SET @ENTRY := 9017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,16000,16000,22000,22000,11,26977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Incendius - In Combat - Cast 26977 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,9000,9000,13000,11,13900,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Incendius - In Combat - Cast 13900 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,6000,8000,8000,11,13899,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Incendius - In Combat - Cast 13899 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,12000,22000,22000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Incendius - In Combat - Cast 14099 (Normal Dungeon)");

-- Pyromancer Loregrain SAI
SET @ENTRY := 9024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,9000,8000,21000,11,15616,0,0,0,0,0,5,0,0,0,0,0,0,0,"Pyromancer Loregrain - In Combat - Cast 15616 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,8000,12000,11,15095,0,0,0,0,0,5,0,0,0,0,0,0,0,"Pyromancer Loregrain - In Combat - Cast 15095 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,25000,25000,11,15038,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyromancer Loregrain - In Combat - Cast 15038 (Normal Dungeon)");

-- Lord Roccor SAI
SET @ENTRY := 9025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,8000,18000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Roccor - In Combat - Cast 13729 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,7000,12000,12000,11,13728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lord Roccor - In Combat - Cast 13728 (Normal Dungeon)");

-- Anger'rel SAI
SET @ENTRY := 9035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anger'rel - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,6000,9000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anger'rel - In Combat - Cast 11971 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,10000,15000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anger'rel - In Combat - Cast 12169 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,1000,3000,20000,26000,11,15062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anger'rel - In Combat - Cast 15062 (Normal Dungeon)"),
(@ENTRY,0,4,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Anger'rel - On Just Reached Home - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Dope'rel SAI
SET @ENTRY := 9040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,5000,7000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dope'rel - In Combat - Cast 15581 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,14000,16000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dope'rel - In Combat - Cast 15583 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,10000,9000,15000,11,12540,0,0,0,0,0,6,0,0,0,0,0,0,0,"Dope'rel - In Combat - Cast 12540 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,1000,1000,25000,35000,11,15087,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dope'rel - In Combat - Cast 15087 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,3000,7000,5000,9000,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dope'rel - In Combat - Cast 15582 (Normal Dungeon)"),
(@ENTRY,0,5,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dope'rel - On Just Reached Home - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Verek SAI
SET @ENTRY := 9042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,6000,6000,11,15042,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verek - In Combat - Cast 15042 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Verek - Between 0-30% Health - Cast 8599 (Normal Dungeon)");

-- Scarshield Grunt SAI
SET @ENTRY := 9043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Grunt - Between 0-5 Range - Cast 11976 (Normal Dungeon)");

-- Young Diemetradon SAI
SET @ENTRY := 9162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,20000,20000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Young Diemetradon - In Combat - Cast 3604");

-- Diemetradon SAI
SET @ENTRY := 9163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,15000,11,13692,0,0,0,0,0,2,0,0,0,0,0,0,0,"Diemetradon - In Combat - Cast 13692");

-- Elder Diemetradon SAI
SET @ENTRY := 9164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Diemetradon - On Respawn - Cast 3417"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,7000,9000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Diemetradon - In Combat - Cast 12555");

-- Fledgling Pterrordax SAI
SET @ENTRY := 9165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,15000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fledgling Pterrordax - In Combat - Cast 5708");

-- Pterrordax SAI
SET @ENTRY := 9166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,10000,14000,11,6605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pterrordax - In Combat - Cast 6605");

-- Frenzied Pterrordax SAI
SET @ENTRY := 9167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Pterrordax - On Respawn - Cast 3417"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,10000,14000,11,7399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Pterrordax - In Combat - Cast 7399");

-- Spirestone Battle Mage SAI
SET @ENTRY := 9197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,10000,5000,15000,11,15305,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spirestone Battle Mage - In Combat - Cast 15305 (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,2,6000,40,20000,20000,11,16170,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirestone Battle Mage - On Friendly Unit At 6000 Health Within 40 Range - Cast 16170 (Normal Dungeon)");

-- Spirestone Enforcer SAI
SET @ENTRY := 9199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,3000,6000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Enforcer - In Combat - Cast 14516 (Normal Dungeon)");

-- Spirestone Reaver SAI
SET @ENTRY := 9200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,20000,20000,25000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Reaver - In Combat - Cast 11876 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,3000,10000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Reaver - In Combat - Cast 15284 (Normal Dungeon)");

-- Fineous Darkvire SAI
SET @ENTRY := 9056;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Aggro - Cast 8258 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,60,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - Between 0-60% Health - Cast 15493 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,40,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - Between 0-40% Health - Cast 15493 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,3000,3000,6000,8500,11,13953,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - In Combat - Cast 13953 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,12000,12000,7000,7000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fineous Darkvire - In Combat - Cast 11978 (Normal Dungeon)"),
(@ENTRY,0,5,0,2,0,100,3,0,20,0,0,11,15346,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - Between 0-20% Health - Cast 15346 (Normal Dungeon)");

-- Spirestone Mystic SAI
SET @ENTRY := 9198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,10000,5000,15000,11,15659,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spirestone Mystic - In Combat - Cast 15659 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,10000,20000,11,8435,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Mystic - In Combat - Cast 8435 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,3000,40,5000,10000,11,15981,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirestone Mystic - On Friendly Unit At 3000 Health Within 40 Range - Cast 15981 (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,2,4000,40,10000,15000,11,15982,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirestone Mystic - On Friendly Unit At 4000 Health Within 40 Range - Cast 15982 (Normal Dungeon)");

-- Spirestone Warlord SAI
SET @ENTRY := 9216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,20000,20000,20000,20000,11,16171,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Warlord - In Combat - Cast 16171 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,2,0,30,30000,30000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Warlord - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Warlord - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Spirestone Warlord
SET @ENTRY := 9216;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Spirestone Warlord");

-- Smolderthorn Mystic SAI
SET @ENTRY := 9239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,5000,10000,11,16006,0,0,0,0,0,5,0,0,0,0,0,0,0,"Smolderthorn Mystic - In Combat - Cast 16006 (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,2,2000,40,10000,15000,11,15799,0,0,0,0,0,7,0,0,0,0,0,0,0,"Smolderthorn Mystic - On Friendly Unit At 2000 Health Within 40 Range - Cast 15799 (Normal Dungeon)");

-- Smolderthorn Shadow Priest SAI
SET @ENTRY := 9240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,10000,10000,11,15090,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Shadow Priest - In Combat - Cast 15090 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,10000,20000,20000,11,11641,0,0,0,0,0,5,0,0,0,0,0,0,0,"Smolderthorn Shadow Priest - In Combat - Cast 11641 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,5000,10000,11,15800,0,0,0,0,0,5,0,0,0,0,0,0,0,"Smolderthorn Shadow Priest - In Combat - Cast 15800 (Normal Dungeon)");

-- Scarshield Raider SAI
SET @ENTRY := 9258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,4000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Raider - In Combat - Cast 11976 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,12000,18000,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Raider - Between 5-30 Range - Cast 14030 (Normal Dungeon)");

-- Firebrand Grunt SAI
SET @ENTRY := 9259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,2,0,30,30000,35000,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Grunt - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Grunt - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,6000,10000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Grunt - In Combat - Cast 13737 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,20000,20000,30000,30000,11,15128,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Grunt - In Combat - Cast 15128 (Normal Dungeon)");

-- Texts for Firebrand Grunt
SET @ENTRY := 9259;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Firebrand Grunt");

-- Firebrand Legionnaire SAI
SET @ENTRY := 9260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,5000,10000,15000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Legionnaire - In Combat - Cast 3248 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,6000,12000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Legionnaire - In Combat - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,30000,30000,11,15128,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Legionnaire - In Combat - Cast 15128 (Normal Dungeon)");

-- Firebrand Dreadweaver SAI
SET @ENTRY := 9263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,20000,20000,30000,30000,11,15128,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Dreadweaver - In Combat - Cast 15128 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,4000,12000,15000,11,16071,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Dreadweaver - In Combat - Cast 16071 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,10000,20000,11,15728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Dreadweaver - In Combat - Cast 15728 (Normal Dungeon)");

-- Firebrand Pyromancer SAI
SET @ENTRY := 9264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,20000,20000,30000,30000,11,15128,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Pyromancer - In Combat - Cast 15128 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,4000,5000,8000,11,15096,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Pyromancer - In Combat - Cast 15096 (Normal Dungeon)");

-- Smolderthorn Shadow Hunter SAI
SET @ENTRY := 9265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,12000,15000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Shadow Hunter - In Combat - Cast 12540 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,6000,12000,11,15614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Shadow Hunter - In Combat - Cast 15614 (Normal Dungeon)");

-- Smolderthorn Witch Doctor SAI
SET @ENTRY := 9266;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,20000,20000,20000,20000,11,15867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Witch Doctor - In Combat - Cast 15867 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,10000,15000,11,15869,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Witch Doctor - In Combat - Cast 15869 (Normal Dungeon)");

-- Smolderthorn Berserker SAI
SET @ENTRY := 9268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,2,0,30,30000,35000,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Berserker - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Berserker - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,4000,6000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Berserker - In Combat - Cast 13446 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,6000,10000,11,17547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Berserker - In Combat - Cast 17547 (Normal Dungeon)");

-- Texts for Smolderthorn Berserker
SET @ENTRY := 9268;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Smolderthorn Berserker");

-- Boss Copperplug SAI
SET @ENTRY := 9336;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,6000,6000,12000,16000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Copperplug - In Combat - Cast 6533"),
(@ENTRY,0,1,0,0,0,60,0,5000,5000,23000,23000,11,9143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Copperplug - In Combat - Cast 9143");

-- Dark Keeper Zimrel SAI
SET @ENTRY := 9441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,12000,17000,11,17139,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Zimrel - In Combat - Cast 17139 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,3000,3000,11,15238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Zimrel - In Combat - Cast 15238 (Normal Dungeon)");

-- Dark Guard SAI
SET @ENTRY := 9445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,8000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Guard - Between 0-5 Range - Cast 15580 (Normal Dungeon)");

-- Gorishi Egg SAI
SET @ENTRY := 9496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Egg - On Respawn - Stop Auto Attack"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Egg - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,2,0,0,0,100,1,0,0,8000,8000,11,14206,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Egg - In Combat - Cast 14206"),
(@ENTRY,0,3,0,0,0,100,1,0,0,9000,9000,11,7,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Egg - In Combat - Cast 7");

-- Bloodaxe Veteran SAI
SET @ENTRY := 9583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,12000,12000,15000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Veteran - In Combat - Cast 15618 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,90,2,5000,5000,9000,9000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Veteran - In Combat - Cast 15615 (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Veteran - On Aggro - Cast 674 (Normal Dungeon)");

-- U'cha SAI
SET @ENTRY := 9622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,8000,12000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"U'cha - In Combat - Cast 8374"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,10000,50000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"U'cha - In Combat - Cast 11428");

-- Lar'korwi Mate SAI
SET @ENTRY := 9683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,20000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lar'korwi Mate - In Combat - Cast 13443"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,20000,20000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lar'korwi Mate - In Combat - Cast 3604");

-- Lar'korwi SAI
SET @ENTRY := 9684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,20000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lar'korwi - In Combat - Cast 13443"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,20000,20000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lar'korwi - In Combat - Cast 3604");

-- Bloodaxe Raider SAI
SET @ENTRY := 9692;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,10000,10000,45000,45000,11,15572,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodaxe Raider - In Combat - Cast 15572 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,85,2,2000,2000,7000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Raider - In Combat - Cast 15284 (Normal Dungeon)");

-- Scarshield Portal SAI
SET @ENTRY := 9707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,5000,5000,12,9708,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Scarshield Portal - In Combat - Summon Creature Burning Imp (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,11000,11000,11000,11000,12,10261,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Scarshield Portal - In Combat - Summon Creature Burning Felhound (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,10,3,20000,20000,0,0,12,10263,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Scarshield Portal - In Combat - Summon Creature Burning Felguard (Normal Dungeon)"),
(@ENTRY,0,3,0,1,0,100,2,10000,10000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Portal - Out Of Combat - Forced Despawn (Normal Dungeon)");

-- Burning Imp SAI
SET @ENTRY := 9708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,10000,10000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Imp - Out Of Combat - Forced Despawn (Normal Dungeon)");

-- Bloodaxe Warmonger SAI
SET @ENTRY := 9716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,5000,9000,9000,13000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Warmonger - In Combat - Cast 10966 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Warmonger - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Warmonger - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Bloodaxe Warmonger
SET @ENTRY := 9716;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodaxe Warmonger");

-- Gorishi Hive Guard SAI
SET @ENTRY := 10040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,8000,12000,11,14120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Hive Guard - In Combat - Cast 14120");

-- Rage Talon Flamescale SAI
SET @ENTRY := 10083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3700,24100,6000,18300,11,15285,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Flamescale - In Combat - Cast 15285 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7400,15100,10800,22100,11,12470,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rage Talon Flamescale - In Combat - Cast 12470 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,14900,22800,32100,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rage Talon Flamescale - In Combat - Cast 16102 (Normal Dungeon)");

-- Azurous SAI
SET @ENTRY := 10202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azurous - On Respawn - Cast 34304"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,60000,63000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azurous - In Combat - Cast 16099");

-- Rookery Guardian SAI
SET @ENTRY := 10258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,12000,10000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rookery Guardian - In Combat - Cast 15572 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rookery Guardian - In Combat - Cast 15580 (Normal Dungeon)");

-- Burning Felhound SAI
SET @ENTRY := 10261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,5000,15000,11,15980,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burning Felhound - In Combat - Cast 15980 (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Felhound - Out Of Combat - Die (Normal Dungeon)");

-- Burning Felguard SAI
SET @ENTRY := 10263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Felguard - Out Of Combat - Die (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,10000,11,16046,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Felguard - In Combat - Cast 16046 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,15000,20000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Felguard - In Combat - Cast 15548 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Felguard - In Combat - Cast 15580 (Normal Dungeon)");

-- Blackhand Elite SAI
SET @ENTRY := 10317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13000,17300,9300,28700,11,15580,1,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Elite - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,15800,33000,25200,30500,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Elite - In Combat - Cast 16172 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5900,22800,11300,27800,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Elite - In Combat - Cast 6253 (Normal Dungeon)");

-- Blackhand Assassin SAI
SET @ENTRY := 10318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Assassin - Out Of Combat - Cast 22766 (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,28,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Assassin - On Aggro - Remove Aura 22766 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9800,17900,13200,22300,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Assassin - In Combat - Cast 12540 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9800,33100,60100,60100,11,6434,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Assassin - In Combat - Cast 6434 (Normal Dungeon)"),
(@ENTRY,0,4,0,9,0,100,2,0,5,2100,4700,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Assassin - Between 0-5 Range - Cast 15582 (Normal Dungeon)");

-- Blackhand Iron Guard SAI
SET @ENTRY := 10319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,22800,6600,18200,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Iron Guard - In Combat - Cast 15655 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,10,0,0,11,15062,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Iron Guard - Between 0-10% Health - Cast 15062 (Normal Dungeon)");

-- Rage Talon Dragon Guard SAI
SET @ENTRY := 10366;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7100,9800,10800,20500,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Dragon Guard - In Combat - Cast 15655 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8500,14300,9600,19500,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Dragon Guard - In Combat - Cast 16145 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,13700,19800,12500,25100,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Dragon Guard - In Combat - Cast 15284 (Normal Dungeon)");

-- Rage Talon Captain SAI
SET @ENTRY := 10371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4600,19900,4000,13700,11,16169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Captain - In Combat - Cast 16169 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,14100,32900,15800,21700,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Captain - In Combat - Cast 10101 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7300,11200,7300,31500,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Captain - In Combat - Cast 15708 (Normal Dungeon)");

-- Rage Talon Fire Tongue SAI
SET @ENTRY := 10372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9100,17900,13500,20700,11,16635,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rage Talon Fire Tongue - In Combat - Cast 16635 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3100,9700,3500,11800,11,16144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Fire Tongue - In Combat - Cast 16144 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,3700,5500,3600,14200,11,16168,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rage Talon Fire Tongue - In Combat - Cast 16168 (Normal Dungeon)");

-- Xabraxxis SAI
SET @ENTRY := 10373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,23000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xabraxxis - In Combat - Cast 11639"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,15000,20000,11,11980,33,0,0,0,0,2,0,0,0,0,0,0,0,"Xabraxxis - In Combat - Cast 11980"),
(@ENTRY,0,2,3,2,0,100,0,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xabraxxis - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xabraxxis - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,11,19127,3,0,0,0,0,1,0,0,0,0,0,0,0,"Xabraxxis - On Death - Cast 19127");

-- Texts for Xabraxxis
SET @ENTRY := 10373;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Xabraxxis");

-- Spire Spider SAI
SET @ENTRY := 10374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,20000,30000,30000,12,10375,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Spire Spider - In Combat - Summon Creature Spire Spiderling (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,20000,30000,30000,12,10375,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Spire Spider - In Combat - Summon Creature Spire Spiderling (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,20000,30000,30000,12,10375,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Spire Spider - In Combat - Summon Creature Spire Spiderling (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10000,20000,30000,30000,12,10375,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Spire Spider - In Combat - Summon Creature Spire Spiderling (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,15000,15000,15000,15000,11,16104,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spire Spider - In Combat - Cast 16104 (Normal Dungeon)");

-- Spire Spiderling SAI
SET @ENTRY := 10375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spire Spiderling - Out Of Combat - Die (Normal Dungeon)");

-- Crystal Fang SAI
SET @ENTRY := 10376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,5000,10000,12,10375,1,60000,0,0,0,5,0,0,0,0,0,0,0,"Crystal Fang - In Combat - Summon Creature Spire Spiderling (Normal Dungeon)");

-- Plague Ghoul SAI
SET @ENTRY := 10405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,40000,40000,11,16458,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Ghoul - In Combat - Cast 16458 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,7000,8000,8000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Ghoul - In Combat - Cast 40505 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Ghoul - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Ghoul - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Plague Ghoul
SET @ENTRY := 10405;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Plague Ghoul");

-- Eye of Naxxramas SAI
SET @ENTRY := 10411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,100,100,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Naxxramas - Out Of Combat - Cast 16380 (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Naxxramas - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,16381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Naxxramas - On Aggro - Cast 16381 (Normal Dungeon)");

-- Texts for Eye of Naxxramas
SET @ENTRY := 10411;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The living are here!",14,0,100,0,0,6596,"Eye of Naxxramas");

-- Chromatic Dragonspawn SAI
SET @ENTRY := 10447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1400,11700,9200,21700,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Dragonspawn - In Combat - Cast 15284 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7100,15600,6500,16700,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Dragonspawn - In Combat - Cast 15580 (Normal Dungeon)");

-- Risen Construct SAI
SET @ENTRY := 10488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5900,13800,11500,19600,11,16169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Construct - In Combat - Cast 16169 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,11000,15600,7300,9700,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Construct - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,2,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Construct - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Construct - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Risen Construct
SET @ENTRY := 10488;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Risen Construct");

-- Jed Runewatcher SAI
SET @ENTRY := 10509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,4000,6000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jed Runewatcher - In Combat - Cast 14516 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,10000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jed Runewatcher - In Combat - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,5000,15000,11,15749,0,0,0,0,0,5,0,0,0,0,0,0,0,"Jed Runewatcher - In Combat - Cast 15749 (Normal Dungeon)");

-- Urok Enforcer SAI
SET @ENTRY := 10601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,9000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Enforcer - Between 0-5 Range - Cast 14516 (Normal Dungeon)");

-- Spellmaw SAI
SET @ENTRY := 10662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellmaw - On Respawn - Cast 34304"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,60000,63000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellmaw - In Combat - Cast 16099"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,18000,21000,11,17012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellmaw - In Combat - Cast 17012");

-- Manaclaw SAI
SET @ENTRY := 10663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manaclaw - On Respawn - Cast 34304"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,60000,63000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Manaclaw - In Combat - Cast 16099");

-- Scryer SAI
SET @ENTRY := 10664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scryer - On Respawn - Cast 34304"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,60000,63000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scryer - In Combat - Cast 16099"),
(@ENTRY,0,2,0,0,0,100,0,6000,6000,15000,20000,11,12738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scryer - In Combat - Cast 12738");
