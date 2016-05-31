-- 
-- DB/SAI: Elwynn Forest
-- Blackrock Spy SAI
SET @ENTRY := 49874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,11,0,50,1,0,0,0,0,11,80676,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spyglass' (No Repeat)"),
(@ENTRY,0,2,0,11,0,50,1,0,0,0,0,11,92857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spying' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 49874;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Orc KILL $r!',12,0,50,0,0,0, 'on Aggro Text',42876),
(@ENTRY,0,1, 'Blackrock take forest!',12,0,50,0,0,0, 'on Aggro Text',42879),
(@ENTRY,0,2, 'The grapes were VERY TASTY!',12,0,50,0,0,0, 'on Aggro Text',42880),
(@ENTRY,0,3, 'Eat you!',12,0,50,0,0,0, 'on Aggro Text',42878),
(@ENTRY,0,4, 'Beg for life!',12,0,50,0,0,0, 'on Aggro Text',42877);
-- Blackrock Spy SAI
SET @ENTRY := 49874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,11,0,50,1,0,0,0,0,11,80676,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spyglass' (No Repeat)"),
(@ENTRY,0,2,0,11,0,50,1,0,0,0,0,11,92857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spying' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 49874;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Orc KILL $r!',12,0,50,0,0,0, 'on Aggro Text',42876),
(@ENTRY,0,1, 'Blackrock take forest!',12,0,50,0,0,0, 'on Aggro Text',42879),
(@ENTRY,0,2, 'The grapes were VERY TASTY!',12,0,50,0,0,0, 'on Aggro Text',42880);
 -- Bodyguard SAI
SET @ENTRY := 6866;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bodyguard - Within 0-8 Range - Cast 'Sprint'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7800,16800,17900,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bodyguard - In Combat - Cast 'Expose Armor'");
-- Young Wolf SAI
SET @ENTRY := 299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,20,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Wolf - Out of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,20,0,30000,600000,120000,600000,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Wolf - Out of Combat - Play Emote 393"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,71764,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Wolf - On Respawn - Cast 'Diseased' (No Repeat)");
-- Crown Lackey SAI
SET @ENTRY := 37214;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Lackey - In Combat - Cast 'Spray Chemical'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crown Lackey - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Cutpurse SAI
SET @ENTRY := 94;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,3900,6900,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cutpurse - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,1,0,4,0,35,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cutpurse - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 94;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You''re in the wrong place at the wrong time, $g pal:missy;!',12,0,100,0,0,0, 'combat Say',42883);
-- Cylina Darkheart SAI
SET @ENTRY := 6374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,11939,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cylina Darkheart - On Respawn - Cast 'Summon Imp' (No Repeat)");
-- Elwynn Guard SAI
SET @ENTRY := 51519;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Elwynn Guard - In Combat - Cast 'Shoot'");
-- Dockworker SAI
SET @ENTRY := 6927;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8500,10500,37100,42100,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dockworker - In Combat - Cast 'Snap Kick'"),
(@ENTRY,0,1,0,4,0,35,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dockworker - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 6927;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You''re in the wrong place at the wrong time, $g pal:missy;!',12,0,100,0,0,0, 'combat Say',42883);
-- Bandit SAI
SET @ENTRY := 116;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8500,10500,37100,42100,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bandit - In Combat - Cast 'Snap Kick'"),
(@ENTRY,0,1,0,4,0,35,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bandit - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 116;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You''re in the wrong place at the wrong time, $g pal:missy;!',12,0,100,0,0,0, 'combat Say',42883);
-- Fedfennel SAI
SET @ENTRY := 472;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,12000,16000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fedfennel - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,3238,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fedfennel - Between 0-50% Health - Cast 'Nimble Reflexes' (No Repeat)");
-- Goblin Assassin SAI
SET @ENTRY := 50039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,60,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Assassin - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,93046,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Assassin - On Respawn - Cast 'Sneaking' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 50039;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Time to join your friends, kissin\' the dirt!',12,0,50,0,0,0, 'on Aggro Text',49838),
(@ENTRY,0,1, 'We\'re gonna burn this place to the ground!',12,0,50,0,0,0, 'on Aggro Text',49840);
-- Kobold Tunneler SAI
SET @ENTRY := 475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kobold Tunneler - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 475;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You no take candle!',12,0,50,0,0,0, 'combat Say',1868),
(@ENTRY,0,1, 'Yiieeeee! Me run!',12,0,50,0,0,0, 'combat Say',1864);
-- Kobold Laborer SAI
SET @ENTRY := 80;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kobold Laborer - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 80;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You no take candle!',12,0,50,0,0,0, 'combat Say',1868),
(@ENTRY,0,1, 'Yiieeeee! Me run!',12,0,50,0,0,0, 'combat Say',1864);
-- Longsnout SAI
SET @ENTRY := 119;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,1,0,0,0,0,0,0,"Longsnout - On Aggro - Cast 'Rushing Charge' (No Repeat)");
-- Mangy Wolf SAI
SET @ENTRY := 525;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,10,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mangy Wolf - Out of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,1,0,10,0,30000,600000,120000,600000,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mangy Wolf - Out of Combat - Play Emote 393");
-- Mother Fang SAI
SET @ENTRY := 471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,6700,22900,22900,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mother Fang - In Combat - Cast 'Web'");
-- Northshire Guard SAI
SET @ENTRY := 1642;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northshire Guard - In Combat - Cast 'Shoot'");
-- Rogue Wizard SAI
SET @ENTRY := 474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rogue Wizard - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rogue Wizard - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rogue Wizard - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,3,0,4,0,35,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rogue Wizard - On Aggro - Say Line 1 (No Repeat)");
-- Ruklar the Trapper SAI
SET @ENTRY := 60;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8200,8200,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,0,0,100,0,19600,19600,21000,31000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast 'Net'");
-- Stormwind Guard SAI
SET @ENTRY := 1423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Guard - In Combat - Cast 'Shoot'");
-- Stormwind Royal Guard SAI
SET @ENTRY := 42218;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Royal Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,11,78855,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - Out of Combat - Cast 'Stormwind Flag Carrier' (No Repeat)");
-- Surena Caledon SAI
SET @ENTRY := 881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Surena Caledon - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surena Caledon - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surena Caledon - Out of Combat - Cast 'Frost Armor'");
-- Tekton SAI
SET @ENTRY := 48873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,91121,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tekton - On Aggro - Cast 'Tektonic Boom' (No Repeat)");
