-- 
-- DB/SAI: Update Felwood
-- Alshirr Banebreath SAI
SET @ENTRY := 14340;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,13000,19000,22000,11,11962,2,0,0,0,0,2,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast 'Immolate'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,16000,19000,11,13578,2,0,0,0,0,2,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast 'Jadefire'");
-- Angerclaw Bear SAI
SET @ENTRY := 8956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Bear - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Bear - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,22000,25000,11,84867,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Bear - Within 0-5 Range - Cast 'Sundering Swipe'");
-- NPC talk text insert
SET @ENTRY := 8956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Angerclaw Mauler SAI
SET @ENTRY := 8958;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Mauler - Within 0-5 Range - Cast 'Maul'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Mauler - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angerclaw Mauler - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 8958;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Arch Druid Navarax SAI
SET @ENTRY := 47842;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,22000,29000,11,36996,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - Within 0-10 Range - Cast 'Claw Swipe'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,89515,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - On Aggro - Cast 'Xaravan's Transformation' (No Repeat)");
-- Bloodvenom Slimeslave SAI
SET @ENTRY := 47675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,27000,32000,11,79607,0,0,0,0,0,2,32,0,0,0,0,0,0,"Bloodvenom Slimeslave - In Combat - Cast 'Venom Splash'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,19000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodvenom Slimeslave - Within 0-5 Range - Cast 'Corrosive Ooze'");
-- Chieftain Bloodmaw SAI
SET @ENTRY := 9462;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Bloodmaw - Between 0-30% Health - Cast 'Crazed' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Bloodmaw - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,30,15000,18000,11,15117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chieftain Bloodmaw - Within 0-30 Range - Cast 'Chain Lightning'");
-- NPC talk text insert
SET @ENTRY := 9462;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Deadwood Avenger SAI
SET @ENTRY := 7157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Avenger - In Combat - Cast 'Curse of the Deadwood'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Avenger - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Avenger - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7157;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Deadwood Den Watcher SAI
SET @ENTRY := 7156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Den Watcher - In Combat - Cast 'Curse of the Deadwood'");
-- Deadwood Gardener SAI
SET @ENTRY := 7154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Gardener - In Combat - Cast 'Curse of the Deadwood'"),
(@ENTRY,0,1,0,14,0,100,0,500,40,14000,17000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Deadwood Gardener - Friendly At 500 Health - Cast 'Rejuvenation'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,12000,15000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Gardener - Between 0-50% Health - Cast 'Healing Wave'");
-- Deadwood Pathfinder SAI
SET @ENTRY := 7155;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat - Cast 'Curse of the Deadwood'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,15000,19000,11,6685,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat - Cast 'Piercing Shot'");
-- Deadwood Shaman SAI
SET @ENTRY := 7158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 'Curse of the Deadwood'"),
(@ENTRY,0,2,0,0,0,100,0,5500,9500,6500,9500,11,12058,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,16,0,100,0,13585,1,15000,30000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");
-- Deadwood Warrior SAI
SET @ENTRY := 7153;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Warrior - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Warrior - In Combat - Cast 'Curse of the Deadwood'");
-- Death Howl SAI
SET @ENTRY := 14339;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Howl - Within 0-5 Range - Cast 'Tendon Rip'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,25000,29000,11,75355,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Howl - In Combat - Cast 'Horrifying Howl'"),
(@ENTRY,0,2,0,0,0,100,0,2000,3000,35000,37000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,"Death Howl - In Combat - Cast 'Infected Wound'");
-- Dessecus SAI
SET @ENTRY := 7104;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,6000,10000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dessecus - Within 0-30 Range - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,16000,21000,11,8293,0,0,0,0,0,4,0,0,0,0,0,0,0,"Dessecus - In Combat - Cast 'Lightning Cloud'");
-- Doomguard SAI
SET @ENTRY := 47795;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,18000,29000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomguard - Within 0-30 Range - Cast 'Cripple'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,17000,25000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard - In Combat - Cast 'War Stomp'");
-- Felhound SAI
SET @ENTRY := 47800;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,13321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felhound - In Combat - Cast 'Mana Burn'");
-- Felpaw Scavenger SAI
SET @ENTRY := 8960;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,14000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,"Felpaw Scavenger - Within 0-5 Range - Cast 'Infected Wound'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Scavenger - Within 0-5 Range - Cast 'Tendon Rip'");
-- Felpaw Wolf SAI
SET @ENTRY := 8959;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,14000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,"Felpaw Wolf - Within 0-5 Range - Cast 'Infected Wound'");
-- Felrot Courser SAI
SET @ENTRY := 48455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,22000,25000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felrot Courser - Within 0-5 Range - Cast 'Gore'");
-- Immolatus SAI
SET @ENTRY := 7137;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,10000,14000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Immolatus - Within 0-8 Range - Cast 'Knock Away'");
-- Grolvitar the Everburning SAI
SET @ENTRY := 48352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grolvitar the Everburning - On Aggro - Cast 'Rush of Flame' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,17000,18000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grolvitar the Everburning - In Combat - Cast 'Flame Shock'");
-- Ironbeak Hunter SAI
SET @ENTRY := 7099;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,21000,24000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbeak Hunter - Within 0-5 Range - Cast 'Rend'");
-- Ironbeak Owl SAI
SET @ENTRY := 7097;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,11000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbeak Owl - Within 0-5 Range - Cast 'Swoop'");
-- Irontree Chopper SAI
SET @ENTRY := 48453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,18000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irontree Chopper - Within 0-5 Range - Cast 'Chop'");
-- Irontree Shredder SAI
SET @ENTRY := 48259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irontree Shredder - On Aggro - Cast 'Saw Blade' (No Repeat)"),
(@ENTRY,0,1,0,1,0,60,0,500,1000,35000,45000,11,89829,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irontree Shredder - Out of Combat - Cast 'Oiled Up'");
-- Irontree Stomper SAI
SET @ENTRY := 7139;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,16000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irontree Stomper - Within 0-5 Range - Cast 'War Stomp'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,89399,3,0,0,0,0,1,0,0,0,0,0,0,0,"Irontree Stomper - On Just Died - Cast 'Release Wisp' (No Repeat)");
-- Ironwood Buzzer SAI
SET @ENTRY := 48038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,5416,0,0,0,0,0,2,32,0,0,0,0,0,0,"Ironwood Buzzer - In Combat - Cast 'Venom Sting'");
-- Jadefire Defender SAI
SET @ENTRY := 47601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Defender - In Combat - Cast 'Jadefire'");
-- Jadefire Felsworn SAI
SET @ENTRY := 7109;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,16000,19000,11,13578,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast 'Jadefire'"),
(@ENTRY,0,2,0,0,0,100,0,7000,11000,21000,24000,11,11443,2,0,0,0,0,4,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast 'Cripple'");
-- Jadefire Rogue SAI
SET @ENTRY := 7106;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Rogue - In Combat - Cast 'Jadefire'"),
(@ENTRY,0,1,0,67,0,100,0,6000,11000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Rogue - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,9000,12000,11,13579,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Rogue - In Combat - Cast 'Gouge'");
-- Jadefire Satyr SAI
SET @ENTRY := 7105;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Satyr - In Combat - Cast 'Jadefire'");
-- Jadefire Shadowstalker SAI
SET @ENTRY := 7110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Shadowstalker - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,22000,28000,11,11962,2,0,0,0,0,4,0,0,0,0,0,0,0,"Jadefire Shadowstalker - In Combat - Cast 'Immolate'");
-- Jadefire Shifter SAI
SET @ENTRY := 48154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Shifter - In Combat - Cast 'Shadow Shock'");
-- Jaedenar Adept SAI
SET @ENTRY := 7115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Adept - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,11000,15000,12000,16000,11,20832,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Adept - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,16000,21000,11,14514,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Adept - Within 0-5 Range - Cast 'Blink'");
-- Jaedenar Cultist SAI
SET @ENTRY := 7112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,22000,25000,11,11639,2,0,0,0,0,4,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,16000,19000,11,11980,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast 'Curse of Weakness'");
-- Jaedenar Darkweaver SAI
SET @ENTRY := 7118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Darkweaver - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,13000,21000,26000,11,11962,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Darkweaver - In Combat - Cast 'Immolate'");
-- Jaedenar Enforcer SAI
SET @ENTRY := 7114;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Enforcer - Within 0-5 Range - Cast 'Rend'");
-- Jaedenar Guardian SAI
SET @ENTRY := 7113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,13000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Guardian - Within 0-5 Range - Cast 'Shield Bash'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,13000,17000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Guardian - In Combat - Cast 'Improved Blocking'");
-- Jaedenar Hound SAI
SET @ENTRY := 7125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,15000,11,13321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Hound - Within 0-30 Range - Cast 'Mana Burn'");
-- Jaedenar Hunter SAI
SET @ENTRY := 7126;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,15000,19000,11,81082,0,0,0,0,0,2,32,0,0,0,0,0,0,"Jaedenar Hunter - Within 0-10 Range - Cast 'Noxious Breath'");
-- Jaedenar Legionnaire SAI
SET @ENTRY := 9862;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,17000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Legionnaire - Within 0-8 Range - Cast 'Uppercut'");
-- Jaedenar Warlock SAI
SET @ENTRY := 7120;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Warlock - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8699,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-30% Health - Cast 'Unholy Frenzy' (No Repeat)");
-- Lord Banehollow SAI
SET @ENTRY := 9516;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,21000,11,16247,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Banehollow - Within 0-5 Range - Cast 'Curse of Thorns'"),
(@ENTRY,0,1,0,9,0,100,0,0,15,8000,13000,11,17399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Banehollow - Within 0-15 Range - Cast 'Shadow Shock'"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,19000,27000,11,37624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Banehollow - In Combat - Cast 'Carrion Swarm'"),
(@ENTRY,0,3,0,0,0,100,0,2000,11000,12000,22000,11,92713,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Banehollow - In Combat - Cast 'Mind Blast'");
-- Mongress SAI
SET @ENTRY := 14344;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mongress - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mongress - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,12000,14500,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mongress - Within 0-5 Range - Cast 'Swipe'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,14000,21000,11,84868,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mongress - Between 0-40% Health - Cast 'Hibernate'");
-- NPC talk text insert
SET @ENTRY := 14344;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Moora SAI
SET @ENTRY := 9861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,12000,21000,26000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moora - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,14000,11,15968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moora - In Combat - Cast 'Lash of Pain'"),
(@ENTRY,0,2,0,9,0,100,0,0,30,34000,37000,11,38048,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moora - Within 0-30 Range - Cast 'Curse of Pain'");
-- Oily Sludge SAI
SET @ENTRY := 48315;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13600,14500,11,7279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oily Sludge - Within 0-5 Range - Cast 'Black Sludge'");
-- Panicking Worker SAI
SET @ENTRY := 48331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Panicking Worker - On Aggro - Cast 'Throw Hammer' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,17000,11,30615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Panicking Worker - Between 0-30% Health - Cast 'Fear'");
-- Phaseleashed Imp SAI
SET @ENTRY := 47441;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,3110,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phaseleashed Imp - In Combat - Cast 'Firebolt'");
-- Prince Xavalis SAI
SET @ENTRY := 9877;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,13000,19000,22000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Xavalis - In Combat - Cast 'Immolate'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Xavalis - In Combat - Cast 'Jadefire'");
-- Rabid Screecher SAI
SET @ENTRY := 48456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,12000,22000,11,54663,0,0,0,0,0,2,1,0,0,0,0,0,0,"Rabid Screecher - Between 0-40% Health - Cast 'Fatal Bite'");
-- Ragepaw SAI
SET @ENTRY := 14342;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragepaw - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragepaw - In Combat - Cast 'Curse of the Deadwood'");
-- Salia SAI
SET @ENTRY := 9860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,18000,24000,11,12888,0,0,0,0,0,4,1,0,0,0,0,0,0,"Salia - Within 0-20 Range - Cast 'Cause Insanity'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,14000,11,15968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Salia - In Combat - Cast 'Lash of Pain'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,24000,25000,11,11990,2,0,0,0,0,4,0,0,0,0,0,0,0,"Salia - In Combat - Cast 'Rain of Fire'");
-- Shadow Lord Fel'dan SAI
SET @ENTRY := 9517;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Lord Fel'dan - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,11000,15000,11,9081,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Lord Fel'dan - In Combat - Cast 'Shadow Bolt Volley'"),
(@ENTRY,0,2,0,0,0,100,0,12000,16000,10000,13000,11,16583,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Lord Fel'dan - In Combat - Cast 'Shadow Shock'"),
(@ENTRY,0,3,0,0,0,100,0,5000,9000,14000,27000,11,38401,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Lord Fel'dan - In Combat - Cast 'Incinerate'");
-- Shadowsworn Netherguard SAI
SET @ENTRY := 47439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Netherguard - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,35000,44000,11,32063,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Netherguard - In Combat - Cast 'Corruption'");
-- Tainted Ooze SAI
SET @ENTRY := 7092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,180000,180000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Ooze - Within 0-5 Range - Cast 'Dark Sludge'");
-- Talonbranch Guardian SAI
SET @ENTRY := 48556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talonbranch Guardian - In Combat - Cast 'Shoot'");
-- Talonbranch Prowler SAI
SET @ENTRY := 48311;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,89812,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talonbranch Prowler - On Respawn - Cast 'Extreme Prowling' (No Repeat)");
-- The Ongar SAI
SET @ENTRY := 14345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,180000,180000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Ongar - Within 0-5 Range - Cast 'Dark Sludge'");
-- Vile Ooze SAI
SET @ENTRY := 7093;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,21067,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Ooze - In Combat - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,11000,14000,11,22595,2,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Ooze - Within 0-5 Range - Cast 'Poison Shock'");
-- Xavathras SAI
SET @ENTRY := 9454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,21000,26000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavathras - Within 0-5 Range - Cast 'Rend'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavathras - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavathras - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 9454;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Vorlus SAI
SET @ENTRY := 47398;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13600,14500,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vorlus - Within 0-5 Range - Cast 'Shadowstrike'");
-- Warpwood Moss Flayer SAI
SET @ENTRY := 7100;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,21000,25000,11,11922,0,0,0,0,0,4,0,0,0,0,0,0,0,"Warpwood Moss Flayer - Within 0-30 Range - Cast 'Entangling Roots'");
-- Withered Protector SAI
SET @ENTRY := 7149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,13000,11,5337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Protector - Within 0-5 Range - Cast 'Wither Strike'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Protector - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Protector - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7149;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Winna Hazzard SAI
SET @ENTRY := 47679;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,81109,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winna Hazzard - In Combat - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,19000,11,40818,2,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - Within 0-8 Range - Cast 'Toxic Slime'"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 47679;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Kitty... KITTY! I''M SO SORRY, KITTY! COME BACK! DON''T LEAVE ME LIKE THIS!',14,0,100,0,0,0, 'on Aggro Text',48258);
-- Whisperwind Lasher SAI
SET @ENTRY := 47747;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,48195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Aggro - Cast 'Emerald Lasher Emerge' (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Aggro - Remove Flag Standstate Submerged (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,0,1,100,0,4000,7000,9000,13000,11,82803,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whisperwind Lasher - In Combat - Cast 'Lashing Flurry' (Phase 1)"),
(@ENTRY,0,4,0,7,1,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Evade - Set Event Phase 2 (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,7,2,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Evade - Remove Flag Standstate Submerged (Phase 2) (No Repeat)"),
(@ENTRY,0,6,0,21,2,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Lasher - On Reached Home - Set Flag Standstate Submerged (Phase 2) (No Repeat)");
