-- Prophet of Sseratus SAI
SET @ENTRY := 28068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet of Sseratus - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet of Sseratus - On Death - Say Line 1"),
(@ENTRY,0,2,0,0,0,100,0,6000,10000,10000,15000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet of Sseratus - In Combat - Cast 48287"),
(@ENTRY,0,3,0,0,0,100,0,1000,4000,10000,10000,11,54483,32,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet of Sseratus - In Combat - Cast 54483"),
(@ENTRY,0,4,0,8,0,100,1,50706,0,0,0,36,28151,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet of Sseratus - On Spellhit By 50706 - Update Template To Muddled Prophet of Sseratus"),
(@ENTRY,0,5,0,1,0,100,0,65000,95000,65000,95000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet of Sseratus - Out Of Combat - Say Line 2");

-- Texts for Prophet of Sseratus
SET @ENTRY := 28068;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Mmm, more mojo.",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,1,0,"NOOOOOOOOooooooo.........!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,0,"They dare attack us? The fools! Do they not know we are now all-powerful?!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,1,"With the power of the wild gods burning in our veins, none, not even the Lich King, can stand in our way!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,2,"I see you, insect! Come closer",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,3,"Kill these invaders who dare to defile our altar!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,4,"I will destroy the Argent Crusade! I will crush the Scourge!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,5,"Finish them and then we will move south to kill their brethren!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,6,"The mojo of Sseratus is ours. Now all will be crushed under the might of the Drakkari!!",14,0,100,0,0,0,"Prophet of Sseratus"),
(@ENTRY,2,7,"Drink deep my brothers!",14,0,100,0,0,0,"Prophet of Sseratus");

-- Sapph SAI
SET @ENTRY := 31161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,9,0,100,0,10,40,9000,13000,11,61077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sapph - Between 10-40 Range - Cast 61077"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,25000,11,61058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sapph - Between 0-8 Range - Cast 61058"),
(@ENTRY,0,3,0,0,0,100,0,60000,120000,120000,240000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - In Combat - Say Line 1"),
(@ENTRY,0,4,0,5,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Killed Unit - Say Line 2"),
(@ENTRY,0,5,0,6,0,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Death - Say Line 3");

-- Texts for Sapph
SET @ENTRY := 31161;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I knew that you would come.",14,0,100,0,0,0,"Sapph"),
(@ENTRY,1,0,"You have some fight in you. I'm impressed.",14,0,100,0,0,0,"Sapph"),
(@ENTRY,2,0,"Welcome to the world of the unliving!",14,0,100,0,0,0,"Sapph"),
(@ENTRY,3,0,"Well fought...",14,0,100,0,0,0,"Sapph");

-- Sapph SAI
SET @ENTRY := 30956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,9,0,100,0,10,40,9000,13000,11,61077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sapph - Between 10-40 Range - Cast 61077"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,25000,11,61058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sapph - Between 0-8 Range - Cast 61058"),
(@ENTRY,0,3,0,0,0,100,0,60000,120000,120000,240000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - In Combat - Say Line 1"),
(@ENTRY,0,4,0,5,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Killed Unit - Say Line 2"),
(@ENTRY,0,5,6,6,0,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapph - On Death - Say Line 3"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,33,31161,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sapph - On Death - Quest Credit");

-- Texts for Sapph
SET @ENTRY := 30956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I knew that you would come.",14,0,100,0,0,0,"Sapph"),
(@ENTRY,1,0,"You have some fight in you. I'm impressed.",14,0,100,0,0,0,"Sapph"),
(@ENTRY,2,0,"Welcome to the world of the unliving!",14,0,100,0,0,0,"Sapph"),
(@ENTRY,3,0,"Well fought...",14,0,100,0,0,0,"Sapph");

-- Guardian Serpent SAI
SET @ENTRY := 26806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,34811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian Serpent - Between 0-5 Range - Cast 34811");

-- Magister Keldonus SAI
SET @ENTRY := 26828;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,15000,11,51830,0,0,0,0,0,5,0,0,0,0,0,0,0,"Magister Keldonus - In Combat - Cast 51830"),
(@ENTRY,0,1,0,9,0,100,0,0,10,24000,28000,11,51806,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Keldonus - Between 0-10 Range - Cast 51806"),
(@ENTRY,0,2,0,0,0,100,0,7000,12000,14000,22000,11,51804,32,0,0,0,0,5,0,0,0,0,0,0,0,"Magister Keldonus - In Combat - Cast 51804"),
(@ENTRY,0,3,0,0,0,100,0,9000,12000,20000,25000,11,51808,1,0,0,0,0,6,0,0,0,0,0,0,0,"Magister Keldonus - In Combat - Cast 51808"),
(@ENTRY,0,4,0,2,0,100,0,0,30,120000,130000,11,51800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Keldonus - Between 0-30% Health - Cast 51800");

-- Risen Drakkari Death Knight SAI
SET @ENTRY := 26830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - On Aggro - Call For Help (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,0,3000,6000,9000,11,49723,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - In Combat - Cast 49723 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,0,3000,6000,9000,11,59011,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - In Combat - Cast 59011 (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,75,2,9000,12000,7000,13500,11,49721,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - In Combat - Cast 49721 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,75,4,9000,12000,7000,13500,11,59010,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - In Combat - Cast 59010 (Heroic Dungeon)"),
(@ENTRY,0,5,0,0,0,100,6,4000,8000,8000,12000,11,51240,0,0,0,0,0,6,0,0,0,0,0,0,0,"Risen Drakkari Death Knight - In Combat - Cast 51240 (Dungeon Only)");

-- Commander Kolurg SAI
SET @ENTRY := 26798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - On Aggro - Remove Aura 47543 (Dungeon Only)"),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,31403,1,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - On Aggro - Cast 31403 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,3000,4000,11000,15000,11,60067,7,0,0,0,0,6,0,0,0,0,0,0,0,"Commander Kolurg - In Combat - Cast 60067 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,6000,8000,19500,25000,11,38618,5,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - In Combat - Cast 38618 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,4,13000,15000,45000,55000,11,19134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - In Combat - Cast 19134 (Heroic Dungeon)"),
(@ENTRY,0,6,0,5,0,100,7,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - On Killed Unit - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,7,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Kolurg - On Death - Say Line 2 (Dungeon Only)");

-- Texts for Commander Kolurg
SET @ENTRY := 26798;
-- DELETE FROM creature_ai_texts WHERE entry BETWEEN -633 AND -631;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What is this? Mag thorin Kar! Kill them!",14,0,100,0,0,13458,"Commander Kolurg"),
(@ENTRY,1,0,"Our task is not yet done!",14,0,100,0,0,13459,"Commander Kolurg"),
(@ENTRY,2,0,"GOOO!",14,0,100,0,0,13460,"Commander Kolurg");

-- Drakkari Protector SAI
SET @ENTRY := 26797;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,7000,11000,11,52425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Protector - In Combat - Cast 52425");

-- Iron Rune Avenger SAI
SET @ENTRY := 26786;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,9000,14000,11,52628,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Avenger - In Combat - Cast 52628");

-- Sinok the Shadowrager SAI
SET @ENTRY := 26771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,11000,16000,11,49961,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sinok the Shadowrager - Between 8-40 Range - Cast 49961"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,18000,21000,11,51622,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sinok the Shadowrager - In Combat - Cast 51622");

-- Infected Grizzly Bear SAI
SET @ENTRY := 26706;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,7000,10000,11,49861,32,0,0,0,0,2,0,0,0,0,0,0,0,"Infected Grizzly Bear - In Combat - Cast 49861");

-- Silverbrook Villager SAI
SET @ENTRY := 26708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,9000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Villager - In Combat - Cast 43410"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,49561,1,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Villager - Between 0-50% Health - Cast 49561");

-- Injured Mammoth SAI
SET @ENTRY := 26711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Mammoth - Between 0-5 Range - Cast 51944");

-- Drakkari Defender SAI
SET @ENTRY := 26704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Defender - In Combat - Cast 15496");

-- Ursus Mauler SAI
SET @ENTRY := 26644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,7000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursus Mauler - Between 0-5 Range - Cast 12161");

-- Saronite Horror SAI
SET @ENTRY := 26646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,130000,140000,11,52342,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saronite Horror - In Combat - Cast 52342");

-- Roanauk Icemist SAI
SET @ENTRY := 26654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,47378,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roanauk Icemist - Out Of Combat - Cast 47378"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roanauk Icemist - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,16,0,100,0,47379,25,9000,12000,11,47379,1,0,0,0,0,7,0,0,0,0,0,0,0,"Roanauk Icemist - On Friendly Unit Missing Buff _spellNameFirstParam_ - Cast 47379");

-- Texts for Roanauk Icemist
SET @ENTRY := 26654;
-- DELETE FROM creature_ai_texts WHERE entry IN (-771);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Rise, and fight once more!",14,0,100,0,0,0,"Roanauk Icemist");

-- Coldwind Witch SAI
SET @ENTRY := 26577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,7000,10000,11,51877,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldwind Witch - Between 0-30 Range - Cast 51877");

-- Mistress of the Coldwind SAI
SET @ENTRY := 26578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,9000,12000,18000,11,52814,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress of the Coldwind - In Combat - Cast 52814"),
(@ENTRY,0,1,0,2,0,100,0,0,20,20000,25000,11,38210,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress of the Coldwind - Between 0-20% Health - Cast 38210");

-- Graymist Hunter SAI
SET @ENTRY := 26592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,17000,21000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Graymist Hunter - In Combat - Cast 32019");

-- Anub'ar Underlord SAI
SET @ENTRY := 26605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,13000,11,51681,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Underlord - Between 0-5 Range - Cast 51681");

-- Wind Trader Mu'fah SAI
SET @ENTRY := 26496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,11000,15000,11,51817,0,0,0,0,0,5,0,0,0,0,0,0,0,"Wind Trader Mu'fah - Between 0-20 Range - Cast 51817");

-- Kili'ua SAI
SET @ENTRY := 26521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,17000,11,53442,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kili'ua - In Combat - Cast 53442");

-- Coldwind Waste Huntress SAI
SET @ENTRY := 26575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,14000,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldwind Waste Huntress - In Combat - Cast 49865");

-- Dead Mage Hunter SAI
SET @ENTRY := 26477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,61832,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Mage Hunter - On Spellhit By 61832 - Forced Despawn");

-- Dragonbone Condor SAI
SET @ENTRY := 26483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,7000,10000,11,51946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonbone Condor - Between 0-30% Health - Cast 51946");

-- Wastes Digger SAI
SET @ENTRY := 26492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Digger - Out Of Combat - Cast 26047"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,6000,9000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Digger - In Combat - Cast 30639");

-- Highland Mustang SAI
SET @ENTRY := 26472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,49319,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit By 49319 - Flee For Assist"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,49323,0,0,0,0,0,7,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit By 49319 - Cast 49323"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit By 49319 - Forced Despawn In 5000 Ms");

-- Diseased Drakkari SAI
SET @ENTRY := 26457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,5000,8000,11,34363,32,0,0,0,0,2,0,0,0,0,0,0,0,"Diseased Drakkari - In Combat - Cast 34363");

-- North Building SAI
SET @ENTRY := 26468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,2000,2000,33,26468,0,0,0,0,0,7,0,0,0,0,0,0,0,"North Building - On LOS Out Of Combat - Quest Credit");

-- South Building SAI
SET @ENTRY := 26469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,2000,2000,33,26469,0,0,0,0,0,7,0,0,0,0,0,0,0,"South Building - On LOS Out Of Combat - Quest Credit");

-- East Building SAI
SET @ENTRY := 26470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,2000,2000,33,26470,0,0,0,0,0,7,0,0,0,0,0,0,0,"East Building - On LOS Out Of Combat - Quest Credit");

-- Moonrest Highborne SAI
SET @ENTRY := 26455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,12000,14000,19000,11,51818,0,0,0,0,0,5,0,0,0,0,0,0,0,"Moonrest Highborne - In Combat - Cast 51818");

-- Winter's Sister SAI
SET @ENTRY := 26456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,9000,12000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Winter's Sister - Between 0-20 Range - Cast 12548");

-- Redfang Elder SAI
SET @ENTRY := 26436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,12000,17000,11,32717,0,0,0,0,0,5,0,0,0,0,0,0,0,"Redfang Elder - In Combat - Cast 32717"),
(@ENTRY,0,1,0,14,0,100,0,2000,40,15000,18000,11,14900,1,0,0,0,0,7,0,0,0,0,0,0,0,"Redfang Elder - On Friendly Unit At 2000 Health Within 40 Range - Cast 14900"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,47034,39,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Elder - On Death - Cast 47034");

-- Ice Serpent SAI
SET @ENTRY := 26446;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,7000,11,51878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Serpent - Between 0-5 Range - Cast 51878");

-- Longhoof Grazer SAI
SET @ENTRY := 26418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,14000,11,42320,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longhoof Grazer - In Combat - Cast 42320");

-- Drakkari Warrior SAI
SET @ENTRY := 26425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,60000,70000,11,52309,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Warrior - Between 0-30% Health - Cast 52309");

-- Arctic Ram SAI
SET @ENTRY := 26426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,13000,17000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arctic Ram - In Combat - Cast 32019");

-- Rune-Smith Durar SAI
SET @ENTRY := 26409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,33000,36000,11,52710,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rune-Smith Durar - In Combat - Cast 52710");

-- Deranged Indu'le Villager SAI
SET @ENTRY := 26411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,12000,15000,11,51781,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deranged Indu'le Villager - In Combat - Cast 51781");

-- Anub'ar Ambusher SAI
SET @ENTRY := 26402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50347,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Ambusher - On Aggro - Cast 50347"),
(@ENTRY,0,1,0,9,0,100,0,9000,14000,9000,12000,11,50347,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Ambusher - Between 9000-14000 Range - Cast 50347");

-- Ice Heart Jormungar Spawn SAI
SET @ENTRY := 26359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,15000,11,43358,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Heart Jormungar Spawn - Between 0-5 Range - Cast 43358");

-- Rattlebore SAI
SET @ENTRY := 26360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,19000,23000,11,47447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rattlebore - In Combat - Cast 47447"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,17000,20000,11,13737,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rattlebore - In Combat - Cast 13737"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7000,11000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rattlebore - Between 0-5 Range - Cast 48287");

-- Entropic Ooze SAI
SET @ENTRY := 26366;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,11000,11000,14000,11,52334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Entropic Ooze - In Combat - Cast 52334");

-- Imperial Eagle SAI
SET @ENTRY := 26369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,5000,9000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Imperial Eagle - In Combat - Cast 55079");

-- Frostpaw Warrior SAI
SET @ENTRY := 26357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,7000,11000,11,12054,32,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Warrior - In Combat - Cast 12054"),
(@ENTRY,0,1,0,13,0,100,0,17000,24000,0,0,11,12555,1,0,0,0,0,7,0,0,0,0,0,0,0,"Frostpaw Warrior - On Target Casting - Cast 12555"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,9000,12000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Warrior - In Combat - Cast 13730"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,11,47033,39,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Warrior - On Death - Cast 47033");

-- Indu'le Warrior SAI
SET @ENTRY := 26344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,8000,11,51786,0,0,0,0,0,2,0,0,0,0,0,0,0,"Indu'le Warrior - Between 0-5 Range - Cast 51786");

-- Iron Thane Argrum SAI
SET @ENTRY := 26348;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,45000,55000,11,52651,1,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Thane Argrum - In Combat - Cast 52651"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,9000,12000,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Thane Argrum - In Combat - Cast 32018");

-- Arcane Wyrm SAI
SET @ENTRY := 26322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,15,14000,18000,11,51732,0,0,0,0,0,5,0,0,0,0,0,0,0,"Arcane Wyrm - Between 0-15 Range - Cast 51732");

-- Corrupted Lothalor Ancient SAI
SET @ENTRY := 26333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,9000,13000,11,51725,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Lothalor Ancient - In Combat - Cast 51725"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,51727,7,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Lothalor Ancient - On Death - Cast 51727");

-- Forgemaster Damrath SAI
SET @ENTRY := 26334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forgemaster Damrath - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,11000,16000,11,52640,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forgemaster Damrath - In Combat - Cast 52640");

-- Texts for Forgemaster Damrath
SET @ENTRY := 26334;
-- DELETE FROM creature_ai_texts WHERE entry BETWEEN -774 AND -772;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Constructs, defend the capital at all costs!",14,0,100,0,0,0,"Forgemaster Damrath"),
(@ENTRY,0,1,"To battle, my children! Show the enemy no mercy!",14,0,100,0,0,0,"Forgemaster Damrath"),
(@ENTRY,0,2,"Crush the children of stone, my iron brethren!",14,0,100,0,0,0,"Forgemaster Damrath"),
(@ENTRY,0,3,"For the thane! For Loken!",14,0,100,0,0,0,"Forgemaster Damrath");

-- Crystalline Ice Elemental SAI
SET @ENTRY := 26316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,51878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Ice Elemental - Between 0-5 Range - Cast 51878");

-- Crystalline Ice Giant SAI
SET @ENTRY := 26291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,35,9000,12000,11,50588,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Ice Giant - Between 5-35 Range - Cast 50588"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,50597,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Ice Giant - Between 0-5 Range - Cast 50597");

-- Moonrest Stalker SAI
SET @ENTRY := 26281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,9000,15000,11,2691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonrest Stalker - Between 0-10 Range - Cast 2691");

-- Ice Revenant SAI
SET @ENTRY := 26283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,11000,15000,11,51584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Revenant - In Combat - Cast 51584");

-- Runic Battle Golem SAI
SET @ENTRY := 26284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,10000,14000,11,52630,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Battle Golem - In Combat - Cast 52630");

-- Dragonblight Mage Hunter SAI
SET @ENTRY := 26280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,0,4,12000,15000,11,51758,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By School 4 - Cast 51758"),
(@ENTRY,0,1,0,8,0,100,0,0,16,12000,15000,11,51763,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By School 16 - Cast 51763"),
(@ENTRY,0,2,0,8,0,100,0,0,32,12000,15000,11,51764,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By School 32 - Cast 51764"),
(@ENTRY,0,3,0,8,0,100,0,0,64,12000,15000,11,51766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By School 64 - Cast 51766");

-- Bronze Shrine Warden SAI
SET @ENTRY := 26277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,9000,13000,11,20716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bronze Shrine Warden - In Combat - Cast 20716"),
(@ENTRY,0,1,0,0,0,100,0,10000,13000,60000,70000,11,60077,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bronze Shrine Warden - In Combat - Cast 60077");

-- Captain Jacobs SAI
SET @ENTRY := 26252;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,17700,17700,11,33735,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Jacobs - In Combat - Cast 33735"),
(@ENTRY,0,1,0,0,0,100,0,4500,4500,4000,9000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Jacobs - In Combat - Cast 32736");

-- Rune Reaver SAI
SET @ENTRY := 26268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,10000,18000,11,52628,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rune Reaver - In Combat - Cast 52628"),
(@ENTRY,0,1,0,8,0,100,1,47005,0,0,0,33,26264,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rune Reaver - On Spellhit By 47005 - Quest Credit"),
(@ENTRY,0,2,0,8,0,100,1,47005,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rune Reaver - On Spellhit By 47005 - Forced Despawn");

-- Emaciated Mammoth Bull SAI
SET @ENTRY := 26271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,7000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emaciated Mammoth Bull - Between 0-5 Range - Cast 51944");

-- Emaciated Mammoth SAI
SET @ENTRY := 26272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,7000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emaciated Mammoth - Between 0-5 Range - Cast 51944");

-- Snowfall Glade Den Mother SAI
SET @ENTRY := 26199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,15000,20000,11,48193,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Den Mother - Between 0-30% Health - Cast 48193"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Den Mother - Between 0-30% Health - Say Line 0");

-- Texts for Snowfall Glade Den Mother
SET @ENTRY := 26199;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Snowfall Glade Den Mother");

-- Loguhn SAI
SET @ENTRY := 26196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Loguhn - Between 0-5 Range - Cast 50370"),
(@ENTRY,0,1,2,2,0,100,0,0,30,120000,130000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Loguhn - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loguhn - Between 0-30% Health - Say Line 0");

-- Texts for Loguhn
SET @ENTRY := 26196;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Loguhn");

-- Damned Taunka Spirit SAI
SET @ENTRY := 26165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Damned Taunka Spirit - On Aggro - Say Line 0");

-- Texts for Damned Taunka Spirit
SET @ENTRY := 26165;
-- DELETE FROM creature_ai_texts WHERE entry IN (-493);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Death will be only the beginning of your torture.",12,0,100,0,0,0,"Damned Taunka Spirit");

-- Bone Warrior SAI
SET @ENTRY := 26126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,700,3300,4400,15000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bone Warrior - In Combat - Cast 50370");

-- Taunka'le Brave SAI
SET @ENTRY := 26157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,15000,11,52058,0,0,0,0,0,1,0,0,0,0,0,0,0,"Taunka'le Brave - In Combat - Cast 52058");

-- Farshire Grain Credit SAI
SET @ENTRY := 26161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,46574,0,0,0,33,26161,0,0,0,0,0,7,0,0,0,0,0,0,0,"Farshire Grain Credit - On Spellhit By 46574 - Quest Credit");

-- Loot Crazed Diver SAI
SET @ENTRY := 25836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loot Crazed Diver - Between 0-30% Health - Cast 5915");

-- Northsea Mercenary SAI
SET @ENTRY := 25839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northsea Mercenary - Between 0-30% Health - Cast 5915");

-- Northsea Thug SAI
SET @ENTRY := 25843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northsea Thug - Between 0-30% Health - Cast 5915");

-- Minion of Kaw SAI
SET @ENTRY := 25880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,6700,10700,15100,11,51430,0,0,0,0,0,2,0,0,0,0,0,0,0,"Minion of Kaw - In Combat - Cast 51430");

-- Coldarra Wyrmkin SAI
SET @ENTRY := 25728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5700,10800,22300,25700,11,50416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Wyrmkin - In Combat - Cast 50416");

-- 55-D Collect-a-tron SAI
SET @ENTRY := 25793;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,15000,11,50269,0,0,0,0,0,2,0,0,0,0,0,0,0,"55-D Collect-a-tron - Between 0-5 Range - Cast 50269");

-- Kaw the Mammoth Destroyer SAI
SET @ENTRY := 25802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,46310,7,0,0,0,0,1,0,0,0,0,0,0,0,"Kaw the Mammoth Destroyer - On Death - Cast 46310");

-- Harold Lane SAI
SET @ENTRY := 25804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,46368,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harold Lane - On Spellhit By 46368 - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1100,10100,16400,28300,11,53432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harold Lane - In Combat - Cast 53432"),
(@ENTRY,0,2,0,9,0,100,0,8,40,9200,12400,11,53425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harold Lane - Between 8-40 Range - Cast 53425");

-- Arcane Serpent SAI
SET @ENTRY := 25721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3700,16100,12400,23700,11,50504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Serpent - In Combat - Cast 50504");

-- Magic-bound Ancient SAI
SET @ENTRY := 25707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3700,16200,19200,28000,11,50506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magic-bound Ancient - In Combat - Cast 50506");

-- Warbringer Goredrak SAI
SET @ENTRY := 25712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,200,16900,21200,11,50534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 50534"),
(@ENTRY,0,1,0,0,0,100,0,5900,6700,16800,21200,11,50545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 50545");

-- Blue Drakonid Supplicant SAI
SET @ENTRY := 25713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5500,21000,30600,11,50534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blue Drakonid Supplicant - In Combat - Cast 50534");

-- Frozen Elemental SAI
SET @ENTRY := 25715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,15000,11,50094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frozen Elemental - Between 0-30 Range - Cast 50094");

-- General Cerulean SAI
SET @ENTRY := 25716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10200,13600,10000,12000,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Cerulean - In Combat - Cast 15499");

-- Gorloc Hunter SAI
SET @ENTRY := 25700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1200,2500,10300,21800,11,50523,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gorloc Hunter - In Combat - Cast 50523");

-- Beryl Mage Hunter SAI
SET @ENTRY := 25585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,200,2500,1500,6400,11,50655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Beryl Mage Hunter - In Combat - Cast 50655");

-- Prince Valanar SAI
SET @ENTRY := 25601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1100,10100,17500,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Valanar - In Combat - Cast 15537"),
(@ENTRY,0,1,0,0,0,100,0,7600,14000,6400,19700,11,50992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Valanar - In Combat - Cast 50992"),
(@ENTRY,0,2,0,0,0,100,0,7200,24100,14500,26600,11,51009,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Valanar - In Combat - Cast 51009");

-- Warsong Aberration SAI
SET @ENTRY := 25611;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,900,9900,11,50306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Aberration - Between 0-5 Range - Cast 50306");

-- Plagued Scavenger SAI
SET @ENTRY := 25650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2900,4700,15900,16500,11,49861,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Scavenger - In Combat - Cast 49861");

-- Lich-Lord Chillwinter SAI
SET @ENTRY := 25682;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich-Lord Chillwinter - On Aggro - Say Line 0");

-- Texts for Lich-Lord Chillwinter
SET @ENTRY := 25682;
-- DELETE FROM creature_ai_texts WHERE entry IN (-768);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You cannot stop us!",12,0,100,0,0,0,"Lich-Lord Chillwinter");

-- Curator Insivius SAI
SET @ENTRY := 25448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,10600,10600,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Curator Insivius - In Combat - Cast 22120"),
(@ENTRY,0,1,0,0,0,100,0,9100,9100,19300,19300,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Curator Insivius - In Combat - Cast 11831"),
(@ENTRY,0,2,0,0,0,100,0,11700,11700,11700,12800,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Curator Insivius - In Combat - Cast 39171");

-- Scourged Mammoth SAI
SET @ENTRY := 25452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2400,8500,8500,16600,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourged Mammoth - In Combat - Cast 15550");

-- The End of the Line Ley Line Focus Kill Credit Bunny SAI
SET @ENTRY := 26887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,47634,0,0,0,11,47635,22,0,0,0,0,7,0,0,0,0,0,0,0,"The End of the Line Ley Line Focus Kill Credit Bunny - On Spellhit By 47634 - Cast 47635");
