-- Plagued Ghoul SAI
SET @ENTRY := 16447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,5000,12000,16000,11,29915,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Ghoul - In Combat - Cast 29915 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,4000,8000,15000,19000,11,13738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Ghoul - In Combat - Cast 13738 (Dungeon Only)"),
(@ENTRY,0,2,3,2,0,100,7,0,30,0,0,11,24318,1,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Ghoul - Between 0-30% Health - Cast 24318 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Ghoul - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Plagued Ghoul
SET @ENTRY := 16447;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Plagued Ghoul");

-- Night Mistress SAI
SET @ENTRY := 16460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,29488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Night Mistress - Between 0-50% Health - Cast 29488 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,29491,0,0,0,0,0,1,0,0,0,0,0,0,0,"Night Mistress - Between 0-50% Health - Cast 29491 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,80,2,7000,7000,15000,15000,11,29487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Night Mistress - In Combat - Cast 29487 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,85,2,15000,15000,25000,25000,11,30358,0,0,0,0,0,2,0,0,0,0,0,0,0,"Night Mistress - In Combat - Cast 30358 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,60,2,25000,25000,30000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Night Mistress - In Combat - Say Line 0 (Normal Dungeon)");

-- Texts for Night Mistress
SET @ENTRY := 16460;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"He asked if the imp could join in... can you believe it? Actually, it wasn't half bad...",12,0,100,1,0,0,"Night Mistress"),
(@ENTRY,0,1,"So I said, \"Yeah, but that'll cost you extra.\"",12,0,100,1,0,0,"Night Mistress"),
(@ENTRY,0,2,"Five seconds! I'm not kidding!",12,0,100,1,0,0,"Night Mistress");

-- Concubine SAI
SET @ENTRY := 16461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,29489,0,0,0,0,0,2,0,0,0,0,0,0,0,"Concubine - Between 0-50% Health - Cast 29489 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,29490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Concubine - Between 0-50% Health - Cast 29490 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,75,2,9000,9000,14000,18000,11,15969,0,0,0,0,0,2,0,0,0,0,0,0,0,"Concubine - In Combat - Cast 15969 (Normal Dungeon)"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Concubine - On Death - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,4,0,1,0,100,3,0,0,40000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Concubine - Out Of Combat - Say Line 1 (Normal Dungeon)");

-- Texts for Concubine
SET @ENTRY := 16461;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"We could have had so much fun!",12,0,100,0,0,0,"Concubine"),
(@ENTRY,1,0,"They fall asleep after. Me, I fall asleep during....",12,0,100,1,0,0,"Concubine");

-- Spectral Patron SAI
SET @ENTRY := 16468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,5000,5000,10000,10000,11,29555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Patron - In Combat - Cast 29555 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,8000,10000,11,29560,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Patron - In Combat - Cast 29560 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Patron - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Spectral Patron
SET @ENTRY := 16468;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Yes... I think I remember now...",12,0,100,0,0,0,"Spectral Patron"),
(@ENTRY,0,1,"I'll miss the show!",12,0,100,0,0,0,"Spectral Patron");

-- Ghostly Philanthropist SAI
SET @ENTRY := 16470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,2,12000,12000,30000,30000,11,29612,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostly Philanthropist - In Combat - Cast 29612 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,80,2,5000,5000,15000,15000,11,29609,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ghostly Philanthropist - In Combat - Cast 29609 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostly Philanthropist - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Ghostly Philanthropist
SET @ENTRY := 16470;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Is it really over?",12,0,100,0,0,0,"Ghostly Philanthropist"),
(@ENTRY,0,1,"It's all... coming back to me.",14,0,100,0,0,0,"Ghostly Philanthropist");

-- Ghastly Haunt SAI
SET @ENTRY := 16481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,14000,14000,19000,19000,11,29716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghastly Haunt - In Combat - Cast 29716 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,80,2,20000,20000,23000,23000,11,29712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghastly Haunt - In Combat - Cast 29712 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghastly Haunt - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Ghastly Haunt
SET @ENTRY := 16481;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Time to move on...",12,0,100,0,0,0,"Ghastly Haunt"),
(@ENTRY,0,1,"Free... at last.",12,0,100,0,0,0,"Ghastly Haunt");

-- Trapped Soul SAI
SET @ENTRY := 16482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,9000,9000,20000,20000,11,29717,0,0,0,0,0,2,0,0,0,0,0,0,0,"Trapped Soul - In Combat - Cast 29717 (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,29718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trapped Soul - On Aggro - Cast 29718 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trapped Soul - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Trapped Soul
SET @ENTRY := 16482;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Time to move on...",12,0,100,0,0,0,"Trapped Soul"),
(@ENTRY,0,1,"Free... at last.",12,0,100,0,0,0,"Trapped Soul");

-- Arcane Watchman SAI
SET @ENTRY := 16485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,12000,12000,12000,12000,11,29768,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Watchman - In Combat - Cast 29768 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,80,2,6000,6000,9000,15000,11,29765,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Watchman - In Combat - Cast 29765 (Normal Dungeon)"),
(@ENTRY,0,2,0,5,0,100,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Watchman - On Killed Unit - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Watchman - On Death - Say Line 1 (Normal Dungeon)");

-- Texts for Arcane Watchman
SET @ENTRY := 16485;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The same fate awaits all who would steal from the master.",12,0,100,0,0,0,"Arcane Watchman"),
(@ENTRY,0,1,"Death is far too merciful for your kind.",12,0,100,0,0,0,"Arcane Watchman"),
(@ENTRY,1,0,"This... changes nothing. Eternal damnation awaits you!",12,0,100,0,0,0,"Arcane Watchman"),
(@ENTRY,1,1,"Others will take my place!",12,0,100,0,0,0,"Arcane Watchman");

-- Shadowy Executioner SAI
SET @ENTRY := 16519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,0,0,20,30000,45000,11,7160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowy Executioner - On Target Between 0-20% Health - Cast 7160");

-- Blood Elf Scout SAI
SET @ENTRY := 16521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,30000,30000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Scout - In Combat - Cast 25602");

-- Texts for Blood Elf Scout
SET @ENTRY := 16521;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I hope you've made your peace.",12,0,100,0,0,0,"Blood Elf Scout"),
(@ENTRY,0,1,"We won't allow you to leave this valley!",12,0,100,0,0,0,"Blood Elf Scout"),
(@ENTRY,0,2,"What a pity you survived the crash just to die here.",12,0,100,0,0,0,"Blood Elf Scout");

-- Shattered Hand Savage SAI
SET @ENTRY := 16523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1500,1500,12000,14500,11,36023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Savage - In Combat - Cast 36023 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,1500,1500,12000,14500,11,36054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Savage - In Combat - Cast 36054 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,4000,4000,8000,14000,11,30470,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Savage - In Combat - Cast 30470 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,6,0,30,60,60,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Savage - Between 0-30% Health - Cast 30485 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Savage - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Shattered Hand Savage
SET @ENTRY := 16523;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Shattered Hand Savage");

-- Inoculated Nestlewood Owlkin SAI
SET @ENTRY := 16534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inoculated Nestlewood Owlkin - Out Of Combat - Say Line 0");

-- Texts for Inoculated Nestlewood Owlkin
SET @ENTRY := 16534;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The %s nods appreciatively.",16,0,100,2,0,0,"Inoculated Nestlewood Owlkin"),
(@ENTRY,0,1,"The %s looks confused.",16,0,100,6,0,0,"Inoculated Nestlewood Owlkin"),
(@ENTRY,0,2,"The %s didn't like what just happened.",16,0,100,18,0,0,"Inoculated Nestlewood Owlkin"),
(@ENTRY,0,3,"The %s seems overjoyed.",16,0,100,4,0,0,"Inoculated Nestlewood Owlkin"),
(@ENTRY,0,4,"The %s doen't look like it minds the crystal's effect.",16,0,100,22,0,0,"Inoculated Nestlewood Owlkin");

-- Ethereal Thief SAI
SET @ENTRY := 16544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,12000,12000,20000,20000,11,30014,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Cast 30014 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,75,2,30000,30000,45000,45000,11,29982,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Cast 29982 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,75,2,6000,6000,18000,22000,11,29982,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Cast 29982 (Normal Dungeon)"),
(@ENTRY,0,3,0,5,0,100,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Thief - On Killed Unit - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,4,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Thief - On Death - Say Line 1 (Normal Dungeon)");

-- Texts for Ethereal Thief
SET @ENTRY := 16544;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Turn your back while you can!",12,0,100,0,0,0,"Ethereal Thief"),
(@ENTRY,1,0,"You will succeed only in damning yourselves!",12,0,100,0,0,0,"Ethereal Thief");

-- Crazed Water Spirit SAI
SET @ENTRY := 16570;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,24000,30000,11,54400,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Water Spirit - In Combat - Cast 54400");

-- Watch Commander Krunk SAI
SET @ENTRY := 16584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,300000,300000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Watch Commander Krunk - Out Of Combat - Say Line 0");

-- Texts for Watch Commander Krunk
SET @ENTRY := 16584;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I've seen gnomes work harder than you, peon! Little girl gnomes - with pig tails! MOVE IT, MOVE IT, MOVE IT!",12,0,100,5,0,0,"Watch Commander Krunk");

-- Cookie One-Eye SAI
SET @ENTRY := 16585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,500000,500000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie One-Eye - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,125000,125000,505000,505000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie One-Eye - Out Of Combat - Say Line 1");

-- Texts for Cookie One-Eye
SET @ENTRY := 16585;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Yer slop is ready. Come n' get it...",12,0,100,0,0,0,"Cookie One-Eye"),
(@ENTRY,1,0,"And if I hear that you palookas complained to Nazgrel again, it'll be one of ya's that I serve up next time...",12,0,100,0,0,0,"Cookie One-Eye");

-- Injured Thrallmar Grunt SAI
SET @ENTRY := 16590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Thrallmar Grunt - On Respawn - Cast 18950"),
(@ENTRY,0,1,0,1,0,30,0,129000,129000,509000,509000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Thrallmar Grunt - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,1,0,30,0,454500,454500,454500,454500,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Thrallmar Grunt - Out Of Combat - Say Line 1"),
(@ENTRY,0,3,0,1,0,30,0,459000,459000,459000,459000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Thrallmar Grunt - Out Of Combat - Say Line 2"),
(@ENTRY,0,4,0,1,0,100,0,464000,464000,464000,464000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Thrallmar Grunt - Out Of Combat - Say Line 3");

-- Texts for Injured Thrallmar Grunt
SET @ENTRY := 16590;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"If my stomach wasn't threatening to dislodge itself from my body and leave me for the refuse that we give to the prisoners, I might be insulted by this... this food.",12,0,100,0,0,0,"Injured Thrallmar Grunt"),
(@ENTRY,0,1,"Do I detect a hint of cinnamon? Or is that nutmeg? Whatever it is, one thing is for sure - nobody cooks donkey like you, Cookie.",12,0,100,0,0,0,"Injured Thrallmar Grunt"),
(@ENTRY,1,0,"What kinda orcs, chief?",12,0,100,0,0,0,"Injured Thrallmar Grunt"),
(@ENTRY,2,0,"You mean...",12,0,100,0,0,0,"Injured Thrallmar Grunt"),
(@ENTRY,3,0,"But how, chief? I thought the curse was lifted...",12,0,100,0,0,0,"Injured Thrallmar Grunt");

-- Shattered Hand Reaver SAI
SET @ENTRY := 16699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1500,1500,5500,11500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Reaver - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1500,1500,5500,11500,13,100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Reaver - In Combat - Add -100% Threat (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,500,500,6500,6500,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Reaver - In Combat - Cast 30471 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,7,0,25,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Reaver - Between 0-25% Health - Cast 30485 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Reaver - Between 0-25% Health - Say Line 0 (Dungeon Only)");

-- Texts for Shattered Hand Reaver
SET @ENTRY := 16699;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Shattered Hand Reaver");

-- Bonechewer Devastator SAI
SET @ENTRY := 16772;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,6000,8000,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Devastator - In Combat - Cast 8646");

-- Broken Skeleton SAI
SET @ENTRY := 16805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32900,1,0,0,0,0,1,0,0,0,0,0,0,0,"Broken Skeleton - On Respawn - Cast 32900");

-- Mag'har Grunt SAI
SET @ENTRY := 16846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,20,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Grunt - Between 0-20% Health - Cast 3019"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Grunt - Between 0-20% Health - Say Line 0");

-- Texts for Mag'har Grunt
SET @ENTRY := 16846;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Mag\'har Grunt");

-- Shattered Hand Grunt SAI
SET @ENTRY := 16867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4200,6700,15600,20700,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grunt - In Combat - Cast 11976"),
(@ENTRY,0,1,0,0,0,40,0,8500,8500,10000,14000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grunt - In Combat - Cast 11978"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shattered Hand Grunt - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,3,0,6,0,10,1,0,0,0,0,11,38879,7,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grunt - On Death - Cast 38879");

-- Shattered Hand Captain SAI
SET @ENTRY := 16870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2200,8100,9400,16800,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Captain - In Combat - Cast 15496"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - On Aggro - Cast 33962"),
(@ENTRY,0,2,0,2,0,100,1,0,90,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-90% Health - Cast 33962"),
(@ENTRY,0,3,0,2,0,100,1,0,80,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-80% Health - Cast 33962"),
(@ENTRY,0,4,0,2,0,100,1,0,70,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-70% Health - Cast 33962"),
(@ENTRY,0,5,0,2,0,100,1,0,60,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-60% Health - Cast 33962"),
(@ENTRY,0,6,0,2,0,100,1,0,50,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-50% Health - Cast 33962"),
(@ENTRY,0,7,0,2,0,100,1,0,40,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-40% Health - Cast 33962"),
(@ENTRY,0,8,0,2,0,100,1,0,30,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-30% Health - Cast 33962"),
(@ENTRY,0,9,0,2,0,100,1,0,20,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-20% Health - Cast 33962"),
(@ENTRY,0,10,0,2,0,100,1,0,10,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Captain - Between 0-10% Health - Cast 33962"),
(@ENTRY,0,11,0,6,0,10,1,0,0,0,0,11,38879,7,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Captain - On Death - Cast 38879");

-- Bleeding Hollow Grunt SAI
SET @ENTRY := 16871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,6000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Grunt - In Combat - Cast 11976"),
(@ENTRY,0,1,2,2,0,100,1,0,25,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Grunt - Between 0-25% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Grunt - Between 0-25% Health - Say Line 0");

-- Texts for Bleeding Hollow Grunt
SET @ENTRY := 16871;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bleeding Hollow Grunt");

-- Bonechewer Mutant SAI
SET @ENTRY := 16876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,8000,11,34113,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Mutant - In Combat - Cast 34113"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Mutant - Between 0-50% Health - Cast 8599"),
(@ENTRY,0,2,3,2,0,100,1,0,20,0,0,11,34114,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Mutant - Between 0-20% Health - Cast 34114"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Mutant - Between 0-20% Health - Say Line 0");

-- Texts for Bonechewer Mutant
SET @ENTRY := 16876;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes unstable and begins to disintegrate!",16,0,100,0,0,0,"Bonechewer Mutant");

-- Blistering Rot SAI
SET @ENTRY := 16901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,8000,8000,11,32722,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blistering Rot - In Combat - Cast 32722");

-- Unyielding Footman SAI
SET @ENTRY := 16904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Footman - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,10000,10000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Footman - In Combat - Cast 11972"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,10000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Footman - In Combat - Cast 11976");

-- Unyielding Knight SAI
SET @ENTRY := 16906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Knight - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,4,0,75,1,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Knight - On Aggro - Cast 22911"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,33910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Knight - Between 0-50% Health - Cast 33910");

-- Bleeding Hollow Peon SAI
SET @ENTRY := 16907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Peon - Between 0-15% Health - Flee For Assist");

-- Mag'har Watcher SAI
SET @ENTRY := 16911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,80,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Watcher - Between 0-80% Health - Cast 12550"),
(@ENTRY,0,1,0,2,0,100,0,0,40,5000,5000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Watcher - Between 0-40% Health - Cast 11986");

-- Bonechewer Raider SAI
SET @ENTRY := 16925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32723,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Raider - On Aggro - Cast 32723");

-- Razorfang Hatchling SAI
SET @ENTRY := 16932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorfang Hatchling - In Combat - Cast 33781");

-- Razorfang Ravager SAI
SET @ENTRY := 16933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorfang Ravager - In Combat - Cast 33781");

-- Quillfang Ravager SAI
SET @ENTRY := 16934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,6000,6000,20000,20000,11,33968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quillfang Ravager - In Combat - Cast 33968"),
(@ENTRY,0,1,0,0,0,50,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quillfang Ravager - In Combat - Cast 33781");

-- Dreghood Geomancer SAI
SET @ENTRY := 16937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,32734,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreghood Geomancer - Between 0-50% Health - Cast 32734"),
(@ENTRY,0,1,0,0,0,75,0,500,500,5000,5000,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreghood Geomancer - In Combat - Cast 34083");

-- Dreghood Brute SAI
SET @ENTRY := 16938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,8000,8000,10000,10000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreghood Brute - In Combat - Cast 31553");

-- Cyber-Rage Forgelord SAI
SET @ENTRY := 16943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,19000,23000,11,36255,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyber-Rage Forgelord - Between 0-8 Range - Cast 36255"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyber-Rage Forgelord - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyber-Rage Forgelord - Between 0-30% Health - Say Line 0");

-- Texts for Cyber-Rage Forgelord
SET @ENTRY := 16943;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Cyber-Rage Forgelord");

-- Mo'arg Doomsmith SAI
SET @ENTRY := 16944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,16000,11,36200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'arg Doomsmith - Between 0-5 Range - Cast 36200");

-- Gan'arg Mekgineer SAI
SET @ENTRY := 16949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13000,18000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Mekgineer - Between 0-5 Range - Cast 36208"),
(@ENTRY,0,1,0,2,0,100,0,0,75,10000,14000,11,36825,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Mekgineer - Between 0-75% Health - Cast 36825");

-- Netherhound SAI
SET @ENTRY := 16950;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,5000,5000,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Netherhound - In Combat - Cast 11981");

-- Terrorfiend SAI
SET @ENTRY := 16951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,10000,10000,11,37488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terrorfiend - In Combat - Cast 37488"),
(@ENTRY,0,1,0,0,0,75,0,4000,4000,8000,8000,11,45,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terrorfiend - In Combat - Cast 45");

-- Warlord Morkh SAI
SET @ENTRY := 16964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,17000,17000,11,34080,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - In Combat - Cast 34080"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,8000,8000,11,11978,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Morkh - In Combat - Cast 11978"),
(@ENTRY,0,2,3,2,0,100,1,0,20,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - Between 0-20% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - Between 0-20% Health - Say Line 0");

-- Texts for Warlord Morkh
SET @ENTRY := 16964;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Warlord Morkh");

-- Bonestripper Buzzard SAI
SET @ENTRY := 16972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,37012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonestripper Buzzard - In Combat - Cast 37012");

-- Bonestripper Vulture SAI
SET @ENTRY := 16973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,32022,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonestripper Vulture - In Combat - Cast 32022");

-- Rogue Voidwalker SAI
SET @ENTRY := 16974;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rogue Voidwalker - In Combat - Cast 33914");

-- Uncontrolled Voidwalker SAI
SET @ENTRY := 16975;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Uncontrolled Voidwalker - In Combat - Cast 33914");

-- Collapsing Voidwalker SAI
SET @ENTRY := 17014;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,10,0,0,11,34233,1,0,0,0,0,1,0,0,0,0,0,0,0,"Collapsing Voidwalker - Between 0-10% Health - Cast 34233"),
(@ENTRY,0,1,2,6,0,100,1,0,0,0,0,11,34234,3,0,0,0,0,1,0,0,0,0,0,0,0,"Collapsing Voidwalker - On Death - Cast 34234"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,34842,7,0,0,0,0,1,0,0,0,0,0,0,0,"Collapsing Voidwalker - On Death - Cast 34842"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,10000,15000,11,34259,0,0,0,0,0,2,0,0,0,0,0,0,0,"Collapsing Voidwalker - In Combat - Cast 34259");

-- Female Kaliri Hatchling SAI
SET @ENTRY := 17034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Female Kaliri Hatchling - In Combat - Cast 5708");

-- Kaliri Matriarch SAI
SET @ENTRY := 17035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,32914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaliri Matriarch - In Combat - Cast 32914");

-- Male Kaliri Hatchling SAI
SET @ENTRY := 17039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Male Kaliri Hatchling - In Combat - Cast 5708");

-- Kaliri Swooper SAI
SET @ENTRY := 17053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaliri Swooper - In Combat - Cast 5708");

-- Blacktalon the Savage SAI
SET @ENTRY := 17057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,5000,5000,9000,9000,11,33911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blacktalon the Savage - In Combat - Cast 33911");

-- Illidari Taskmaster SAI
SET @ENTRY := 17058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,0,0,11,34186,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Taskmaster - Between 0-20% Health - Cast 34186"),
(@ENTRY,0,1,0,0,0,75,0,2000,2000,16000,16000,11,16244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Taskmaster - In Combat - Cast 16244");

-- Shadowy Summoner SAI
SET @ENTRY := 17088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,8722,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Summoner - Out Of Combat - Cast 8722"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,4000,6000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowy Summoner - In Combat - Cast 13878");

-- Wrekt Warrior SAI
SET @ENTRY := 17142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,7000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrekt Warrior - In Combat - Cast 11976"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,8000,12000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrekt Warrior - In Combat - Cast 17207");

-- Wrekt Seer SAI
SET @ENTRY := 17143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrekt Seer - Out Of Combat - Cast 12550"),
(@ENTRY,0,1,0,2,0,100,1,0,60,0,0,11,32931,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrekt Seer - Between 0-60% Health - Cast 32931"),
(@ENTRY,0,2,0,2,0,100,0,0,40,12000,20000,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrekt Seer - Between 0-40% Health - Cast 11642");

-- Kil'sorrow Cultist SAI
SET @ENTRY := 17147;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Cultist - On Aggro - Cast 16592"),
(@ENTRY,0,1,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 32000");

-- Kil'sorrow Deathsworn SAI
SET @ENTRY := 17148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,31996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Deathsworn - Between 0-50% Health - Cast 31996");

-- Vir'aani Raider SAI
SET @ENTRY := 17149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1900,5400,5800,14900,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Raider - In Combat - Cast 14873"),
(@ENTRY,0,1,0,0,0,100,0,7900,9200,11300,44700,11,15691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Raider - In Combat - Cast 15691"),
(@ENTRY,0,2,0,0,0,100,0,10400,17500,27300,34800,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Raider - In Combat - Cast 12540");

-- Tortured Earth Spirit SAI
SET @ENTRY := 17156;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Earth Spirit - Between 0-30% Health - Cast 3019"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Earth Spirit - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,0,0,75,0,25000,25000,12000,12000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tortured Earth Spirit - In Combat - Cast 13728");

-- Texts for Tortured Earth Spirit
SET @ENTRY := 17156;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Tortured Earth Spirit");

-- Raving Owlbeast SAI
SET @ENTRY := 17188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raving Owlbeast - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raving Owlbeast - Between 0-30% Health - Say Line 0");

-- Texts for Raving Owlbeast
SET @ENTRY := 17188;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Raving Owlbeast");

-- Bonechewer Hungerer SAI
SET @ENTRY := 17259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,7,100,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Hungerer - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1300,8500,10700,17700,11,16244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Hungerer - In Combat - Cast 16244 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,4800,15400,7200,22400,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Hungerer - In Combat - Cast 6713 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,3500,13700,5400,12500,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Hungerer - In Combat - Cast 14516 (Dungeon Only)"),
(@ENTRY,0,4,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bonechewer Hungerer - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Texts for Bonechewer Hungerer
SET @ENTRY := 17259;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"This world is OURS!",12,1,100,0,0,0,"Bonechewer Hungerer"),
(@ENTRY,0,1,"We are the true Horde!",12,1,100,0,0,0,"Bonechewer Hungerer"),
(@ENTRY,0,2,"The blood is our power!",12,1,100,0,0,0,"Bonechewer Hungerer");

-- Bonechewer Destroyer SAI
SET @ENTRY := 17271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Destroyer - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,3200,10900,6500,18600,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Destroyer - In Combat - Cast 16856 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,19300,31400,11100,27100,11,10101,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Destroyer - In Combat - Cast 10101 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,19300,31400,11100,27100,13,0,35,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Destroyer - In Combat - Remove 35% Threat (Dungeon Only)");

-- Texts for Bonechewer Destroyer
SET @ENTRY := 17271;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"For Kargath!  For Victory!",12,0,100,0,0,0,"Bonechewer Destroyer"),
(@ENTRY,0,1,"We are the true Horde!",12,1,100,0,0,0,"Bonechewer Destroyer"),
(@ENTRY,0,2,"The blood is our power!",12,1,100,0,0,0,"Bonechewer Destroyer");

-- Shattered Hand Warhound SAI
SET @ENTRY := 17280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warhound - On Respawn - Cast 18950"),
(@ENTRY,0,1,0,0,0,100,6,1000,2300,13100,17400,11,30636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warhound - In Combat - Cast 30636 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,2300,8600,4600,14300,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warhound - In Combat - Cast 30639 (Dungeon Only)");

-- Bonechewer Ripper SAI
SET @ENTRY := 17281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,6,700,1000,12000,19000,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Ripper - In Combat - Cast 18501 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Ripper - In Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,6,5000,9000,8000,12000,10,4,15,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Ripper - Out Of Combat - Random Emote (Dungeon Only)");

-- Texts for Bonechewer Ripper
SET @ENTRY := 17281;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bonechewer Ripper");

-- Gorgannon SAI
SET @ENTRY := 17300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,15700,32500,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorgannon - Between 0-40 Range - Cast 9613"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12100,24400,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorgannon - Between 0-5 Range - Cast 11428"),
(@ENTRY,0,2,3,2,0,100,1,0,50,0,0,39,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorgannon - Between 0-50% Health - Call For Help"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorgannon - Between 0-50% Health - Say Line 0");

-- Texts for Gorgannon
SET @ENTRY := 17300;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s calls for help!",16,0,100,0,0,0,"Gorgannon");

-- Laughing Skull Enforcer SAI
SET @ENTRY := 17370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Enforcer - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,4200,9500,9500,15300,11,15655,1,0,0,0,0,5,0,0,0,0,0,0,0,"Laughing Skull Enforcer - In Combat - Cast 15655 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,1900,8800,9300,14700,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Laughing Skull Enforcer - In Combat - Cast 14516 (Dungeon Only)");

-- Texts for Laughing Skull Enforcer
SET @ENTRY := 17370;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Lok Narash!",12,0,100,0,0,0,"Laughing Skull Enforcer");

-- Shadowmoon Technician SAI
SET @ENTRY := 17414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,2,2800,4700,1400,23400,11,30846,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Cast 30846 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,0,0,100,4,2800,4700,17700,23400,11,32784,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Cast 32784 (Heroic Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Say Line 0 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,4400,10600,3600,6200,11,40062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Cast 40062 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,4400,10600,3600,6200,11,40064,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Cast 40064 (Heroic Dungeon)"),
(@ENTRY,0,6,0,0,0,100,6,5400,11600,24300,24300,11,6726,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Technician - In Combat - Cast 6726 (Dungeon Only)");

-- Texts for Shadowmoon Technician
SET @ENTRY := 17414;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s begins to arm the Proximity Bomb!",16,0,100,0,0,0,"Shadowmoon Technician"),
(@ENTRY,1,0,"%s begins to arm the Proximity Bomb!",16,0,100,0,0,0,"Shadowmoon Technician");

-- Shattered Hand Heathen SAI
SET @ENTRY := 17420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,3500,7000,14000,11,30474,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Heathen - In Combat - Cast 30474 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,3500,3500,7000,14000,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Heathen - In Combat - Cast 35949 (Heroic Dungeon)"),
(@ENTRY,0,2,3,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Heathen - Between 0-30% Health - Cast 30485 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Heathen - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Shattered Hand Heathen
SET @ENTRY := 17420;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Shattered Hand Heathen");

-- Bonechewer Beastmaster SAI
SET @ENTRY := 17455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Beastmaster - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,4200,12400,30000,30000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Cast 9128 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,1200,7100,10800,12800,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Cast 10966 (Dungeon Only)"),
(@ENTRY,0,3,4,0,0,100,7,17000,17000,0,0,12,17280,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Summon Creature Shattered Hand Warhound (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,7,17020,17020,0,0,12,17280,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Summon Creature Shattered Hand Warhound (Dungeon Only)"),
(@ENTRY,0,6,0,0,0,50,7,17020,17020,0,0,12,17280,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Summon Creature Shattered Hand Warhound (Dungeon Only)"),
(@ENTRY,0,7,0,0,0,20,7,17030,17030,0,0,12,17280,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Beastmaster - In Combat - Summon Creature Shattered Hand Warhound (Dungeon Only)");

-- Texts for Bonechewer Beastmaster
SET @ENTRY := 17455;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hold them back while I release the warhounds!",14,0,100,0,0,10160,"Bonechewer Beastmaster"),
(@ENTRY,1,0,"My pets are hungry and they will dine on your flesh!",14,0,100,0,0,10161,"Bonechewer Beastmaster");

-- Blood Elf Bandit SAI
SET @ENTRY := 17591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,5916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Bandit - On Respawn - Cast 5916"),
(@ENTRY,0,1,0,4,0,75,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Bandit - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,9,0,100,0,0,5,5000,8000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - Between 0-5 Range - Cast 14873"),
(@ENTRY,0,3,0,9,0,100,0,0,5,9000,12000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - Between 0-5 Range - Cast 7159"),
(@ENTRY,0,4,0,0,0,100,0,9000,14000,16000,21000,11,25710,1,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - In Combat - Cast 25710");

-- Texts for Blood Elf Bandit
SET @ENTRY := 17591;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your money or your life! Actually, just your life will do...",12,0,100,0,0,0,"Blood Elf Bandit"),
(@ENTRY,0,1,"Your death will make a fitting tribute to the King!",12,0,100,0,0,0,"Blood Elf Bandit"),
(@ENTRY,0,2,"For Silvermoon! For Sunstrider!",12,0,100,0,0,0,"Blood Elf Bandit");

-- Heathen Guard SAI
SET @ENTRY := 17621;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,500,500,5000,10000,11,30474,0,0,0,0,0,2,0,0,0,0,0,0,0,"Heathen Guard - In Combat - Cast 30474 (Dungeon Only)"),
(@ENTRY,0,1,2,2,0,100,7,0,20,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heathen Guard - Between 0-20% Health - Cast 30485 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heathen Guard - Between 0-20% Health - Say Line 0 (Dungeon Only)");

-- Texts for Heathen Guard
SET @ENTRY := 17621;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Heathen Guard");

-- Reaver Guard SAI
SET @ENTRY := 17623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1500,1500,5500,11500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reaver Guard - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1500,1500,5500,11500,13,100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reaver Guard - In Combat - Add -100% Threat (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,500,500,6500,6500,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reaver Guard - In Combat - Cast 30471 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,7,0,25,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reaver Guard - Between 0-25% Health - Cast 30485 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reaver Guard - Between 0-25% Health - Say Line 0 (Dungeon Only)");

-- Texts for Reaver Guard
SET @ENTRY := 17623;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Reaver Guard");

-- Laughing Skull Legionnaire SAI
SET @ENTRY := 17626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5800,7200,11900,12400,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Laughing Skull Legionnaire - In Combat - Cast 10966 (Dungeon Only)"),
(@ENTRY,0,1,2,2,0,100,7,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Legionnaire - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Legionnaire - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Laughing Skull Legionnaire
SET @ENTRY := 17626;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Laughing Skull Legionnaire");

-- Coilfang Engineer SAI
SET @ENTRY := 17721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,9000,13000,11,40331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Engineer - In Combat - Cast 40331 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,6000,8000,9000,13000,11,40332,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Engineer - In Combat - Cast 40332 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,4000,6000,5000,7000,11,6533,1,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Engineer - In Combat - Cast 6533 (Dungeon Only)");

-- Bog Giant SAI
SET @ENTRY := 17723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4500,9600,18200,27100,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Giant - In Combat - Cast 15550 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,3200,7100,30300,30300,11,32065,32,0,0,0,0,5,0,0,0,0,0,0,0,"Bog Giant - In Combat - Cast 32065 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,7,0,50,0,0,11,40318,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Giant - Between 0-50% Health - Cast 40318 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,7,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Giant - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bog Giant - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Bog Giant
SET @ENTRY := 17723;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bog Giant");

-- Underbat SAI
SET @ENTRY := 17724;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2200,6600,4400,12900,11,34171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Underbat - In Combat - Cast 34171 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2200,6600,4400,12900,11,37956,0,0,0,0,0,2,0,0,0,0,0,0,0,"Underbat - In Combat - Cast 37956 (Heroic Dungeon)");

-- Underbog Lurker SAI
SET @ENTRY := 17725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,11,34161,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lurker - On Aggro - Cast 34161 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Underbog Lurker - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,3,0,0,100,7,5800,10800,0,0,28,34151,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lurker - In Combat - Remove Aura 34151 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lurker - In Combat - Say Line 1 (Dungeon Only)");

-- Texts for Underbog Lurker
SET @ENTRY := 17725;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s grows in size upon seeing $N!",16,0,100,0,0,0,"Underbog Lurker"),
(@ENTRY,1,0,"%s strength fades!",16,0,100,0,0,0,"Underbog Lurker");

-- Wrathfin Myrmidon SAI
SET @ENTRY := 17726;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2300,8100,10600,20400,11,31410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Myrmidon - In Combat - Cast 31410 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2300,8100,10600,20400,11,37973,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Myrmidon - In Combat - Cast 37973 (Heroic Dungeon)");

-- Wrathfin Sentry SAI
SET @ENTRY := 17727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,7,100,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathfin Sentry - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,7300,7300,8000,10500,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Sentry - In Combat - Cast 11976 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,12000,15000,17000,22000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Sentry - In Combat - Cast 11972 (Dungeon Only)");

-- Texts for Wrathfin Sentry
SET @ENTRY := 17727;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Illidan reigns!",12,0,100,0,0,0,"Wrathfin Sentry");

-- Murkblood Tribesman SAI
SET @ENTRY := 17728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2300,13300,8800,17400,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Tribesman - In Combat - Cast 12057 (Dungeon Only)"),
(@ENTRY,0,1,2,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Tribesman - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Tribesman - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Murkblood Tribesman
SET @ENTRY := 17728;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Murkblood Tribesman");
