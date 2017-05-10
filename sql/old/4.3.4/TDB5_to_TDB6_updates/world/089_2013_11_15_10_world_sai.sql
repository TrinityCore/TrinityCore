-- Rift Keeper SAI
SET @ENTRY := 21104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,30,1,1,2,0,0,0,1,0,0,0,0,0,0,0,"Rift Keeper - On Aggro - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,0,0,2,100,2,0,0,7300,16900,11,36279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36279 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,3,0,0,2,100,4,0,0,2400,3600,11,38534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 38534 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,4,0,0,2,100,2,12400,12400,13900,14500,11,36277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36277 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,0,2,100,4,18200,29300,14400,25200,11,38535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 38535 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,0,2,100,2,9800,9800,13400,13400,11,36278,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36278 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,0,2,100,4,11100,31400,15800,27700,11,38536,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 38536 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,0,2,100,4,13300,34500,27500,27500,11,13323,0,0,0,0,0,6,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 13323 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,0,0,100,2,7200,12200,11900,29600,11,36275,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36275 (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,4,7200,12000,11100,24200,11,38533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 38533 (Heroic Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,7300,19500,20300,45900,11,36276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36276 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,4,6200,21500,12000,21700,11,36276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 36276 (Heroic Dungeon)"),
(@ENTRY,0,13,0,0,0,100,6,2500,26300,16900,25300,11,12542,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 12542 (Dungeon Only)"),
(@ENTRY,0,14,0,2,0,100,7,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Keeper - Between 0-30% Health - Cast 8269 (Dungeon Only)");

-- Texts for Rift Keeper
SET @ENTRY := 21104;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Victory or death!",12,0,100,0,0,0,"Rift Keeper"),
(@ENTRY,0,1,"You are running out of time!",12,0,100,0,0,0,"Rift Keeper"),
(@ENTRY,0,2,"The rift must be protected!",12,0,100,0,0,0,"Rift Keeper");

-- Texts for Gralga
SET @ENTRY := 21193;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Learning to read is a thirsty business. A toast, eh?",12,0,100,0,0,0,"Gralga");

-- Texts for Warcaller Sardon Truslice
SET @ENTRY := 21771;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Wit a reward like dis, how could they refuse, mon?",12,0,100,0,0,0,"Warcaller Sardon Truslice");

-- Thane Yoregar SAI update
DELETE FROM `smart_scripts` WHERE `entryorguid`=21773 AND `id` IN (1);

-- Texts for Thane Yoregar
SET @ENTRY := 21773;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I don't get it! Are ya blind? Can ya not see the demons bangin' on our door? Who am I gonna send out to talk to your shaman friends? Point 'em out!",12,0,100,6,0,0,"Thane Yoregar");

-- Hand of Kargath SAI
SET @ENTRY := 22374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - On Aggro - Cast 33962"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,2600,2600,3800,6400,11,9080,32,0,0,0,0,2,0,0,0,0,0,0,0,"Hand of Kargath - In Combat - Cast 9080"),
(@ENTRY,0,3,0,0,0,100,0,5200,5200,30000,45000,11,33735,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - In Combat - Cast 33735"),
(@ENTRY,0,4,0,0,0,100,0,15400,15400,12000,16000,11,24193,1,0,0,0,0,5,0,0,0,0,0,0,0,"Hand of Kargath - In Combat - Cast 24193"),
(@ENTRY,0,5,0,2,0,100,1,0,90,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-90% Health - Cast 33962"),
(@ENTRY,0,6,0,2,0,100,1,0,80,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-80% Health - Cast 33962"),
(@ENTRY,0,7,0,2,0,100,1,0,70,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-70% Health - Cast 33962"),
(@ENTRY,0,8,0,2,0,100,1,0,60,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-60% Health - Cast 33962"),
(@ENTRY,0,9,0,2,0,100,1,0,50,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-50% Health - Cast 33962"),
(@ENTRY,0,10,0,2,0,100,1,0,40,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-40% Health - Cast 33962"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-30% Health - Cast 33962"),
(@ENTRY,0,12,0,2,0,100,1,0,20,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-20% Health - Cast 33962"),
(@ENTRY,0,13,0,2,0,100,1,0,10,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hand of Kargath - Between 0-10% Health - Cast 33962");

-- Texts for Hand of Kargath
SET @ENTRY := 22374;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Who dares slay one of my Kargath's commanders?  You will pay for this... in flesh!",14,0,100,0,0,0,"Hand of Kargath");

-- Guardian of the Hawk SAI
SET @ENTRY := 22992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Respawn - Stop Auto Attack"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Respawn - Set Not Attackable Flag"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,5,27,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Respawn - Emote State Ready Unarmed"),
(@ENTRY,0,4,0,0,0,100,1,0,0,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Say Line 0"),
(@ENTRY,0,5,0,0,0,100,1,0,0,7500,7500,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Say Line 1"),
(@ENTRY,0,6,0,0,0,100,1,0,0,12000,12000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Allow Combat Movement"),
(@ENTRY,0,7,0,0,0,100,1,0,0,12000,12000,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Start Auto Attack"),
(@ENTRY,0,8,0,0,0,100,1,0,0,12000,12000,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Remove Not Attackable Flag"),
(@ENTRY,0,9,0,0,0,100,1,0,0,12000,12000,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Emote 0"),
(@ENTRY,0,10,0,0,0,100,0,20000,20000,120000,120000,11,40412,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Cast 40412");

-- Texts for Guardian of the Hawk
SET @ENTRY := 22992;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Fool! The essence of the hawk will never be yours!",12,0,100,0,0,0,"Guardian of the Hawk"),
(@ENTRY,1,0,"The time of the Raven is night, but yours will end here!",12,0,100,0,0,0,"Guardian of the Hawk");

-- Guardian of the Eagle SAI
SET @ENTRY := 22993;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Respawn - Stop Auto Attack"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Respawn - Set Not Attackable Flag"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,5,27,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Respawn - Emote State Ready Unarmed"),
(@ENTRY,0,4,0,0,0,100,1,0,0,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Say Line 0"),
(@ENTRY,0,5,0,0,0,100,1,0,0,7500,7500,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Say Line 1"),
(@ENTRY,0,6,0,0,0,100,1,0,0,12000,12000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Allow Combat Movement"),
(@ENTRY,0,7,0,0,0,100,1,0,0,12000,12000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Allow Combat Movement"),
(@ENTRY,0,8,0,0,0,100,1,0,0,12000,12000,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Remove Not Attackable Flag"),
(@ENTRY,0,9,0,0,0,100,1,0,0,12000,12000,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Emote 0"),
(@ENTRY,0,10,0,0,0,100,0,15000,15000,7000,7000,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 9739"),
(@ENTRY,0,11,0,0,0,100,0,18000,18000,7000,7000,11,40339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 40339"),
(@ENTRY,0,12,0,0,0,100,0,24000,24000,30000,30000,11,40344,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 40344");

-- Texts for Guardian of the Eagle
SET @ENTRY := 22993;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You dare to disturb the loyal followers of the Raven?",12,0,100,0,0,0,"Guardian of the Eagle"),
(@ENTRY,1,0,"You will die for your hubris, druid!",12,0,100,0,0,0,"Guardian of the Eagle");

-- Guardian of the Falcon SAI
SET @ENTRY := 22994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Respawn - Stop Auto Attack"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Respawn - Set Not Attackable Flag"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,5,27,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Respawn - Emote State Ready Unarmed"),
(@ENTRY,0,4,0,0,0,100,1,0,0,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Say Line 0"),
(@ENTRY,0,5,0,0,0,100,1,0,0,7500,7500,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Say Line 1"),
(@ENTRY,0,6,0,0,0,100,1,0,0,12000,12000,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Allow Combat Movement"),
(@ENTRY,0,7,0,0,0,100,1,0,0,12000,12000,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Start Auto Attack"),
(@ENTRY,0,8,0,0,0,100,1,0,0,12000,12000,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Remove Not Attackable Flag"),
(@ENTRY,0,9,0,0,0,100,1,0,0,12000,12000,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Emote 0"),
(@ENTRY,0,10,0,0,0,100,0,25000,25000,30000,30000,11,40367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 40367"),
(@ENTRY,0,11,0,0,0,100,0,29000,29000,30000,30000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 9613");

-- Texts for Guardian of the Falcon
SET @ENTRY := 22994;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The falcon is vaniquished, doomed never to rise again! Your quest is futile!",12,0,100,0,0,0,"Guardian of the Falcon"),
(@ENTRY,1,0,"The raven will return to us as foretold in the prophecy and you are powerless to stop it!",12,0,100,0,0,0,"Guardian of the Falcon");

-- Shadowmoon Weapon Master SAI
SET @ENTRY := 23049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,1000,1000,0,0,11,41099,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Out Of Combat - Cast 41099 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,41106,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Out Of Combat - Cast 41106 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,70,0,0,11,41101,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-70% Health - Cast 41101 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,41105,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-70% Health - Cast 41105 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,40,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-40% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,11,41100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-40% Health - Cast 41100 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,11,41107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-40% Health - Cast 41107 (Normal Dungeon)"),
(@ENTRY,0,7,0,2,0,100,2,0,30,25000,30000,11,41097,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - Between 0-30% Health - Cast 41097 (Normal Dungeon)"),
(@ENTRY,0,8,0,0,0,100,2,3000,6000,8000,11000,11,41103,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - In Combat - Cast 41103 (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,100,2,6000,8000,12000,16000,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Weapon Master - In Combat - Cast 18813 (Normal Dungeon)");

-- Texts for Shadowmoon Weapon Master
SET @ENTRY := 23049;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Berserker stance! Attack them recklessly!",12,0,100,0,0,0,"Shadowmoon Weapon Master");

-- Texts for Harold Lane
SET @ENTRY := 25804;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You seek to deafen me? Pathetic... Wait... What's that sound?",12,0,100,0,0,0,"Harold Lane");

-- Loot Crazed Poacher SAI
SET @ENTRY := 25806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loot Crazed Poacher - Out Of Combat - Cast 34189"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,28,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loot Crazed Poacher - In Combat - Remove Aura 34189"),
(@ENTRY,0,2,4,0,1,25,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loot Crazed Poacher - In Combat - Say Line 0");

-- Texts for Loot Crazed Poacher
SET @ENTRY := 25806;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Now THIS is a sport!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,1,"KILL KILL KILL!!!!!!!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,2,"I'm sure ol' Hemet can do something with your bones!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,3,"Give it up, little beast!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,4,"Just fifty more hooves and I'll have the new gun!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,5,"No way! Rhino head helmet for the low, low price of thirty rhino heads? I'll take two at those prices!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,6,"I wonder what Nesingwary will give me for your hide!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,7,"It's gonna be veal tonight!",12,0,100,0,0,0,"Loot Crazed Poacher"),
(@ENTRY,0,8,"Nesingwary is going to go broke if he keeps this up! Lane probably has no idea what he's doing!",12,0,100,0,0,0,"Loot Crazed Poacher");

-- Whirligig Wafflefry SAI
SET @ENTRY := 25885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - On Respawn - Set Sheath Ranged"),
(@ENTRY,0,1,0,1,0,100,0,30000,30000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,1,0,100,0,82000,82000,300000,300000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - Out Of Combat - Say Line 1"),
(@ENTRY,0,3,0,1,0,100,0,90000,90000,300000,300000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - Out Of Combat - Say Line 2"),
(@ENTRY,0,4,0,1,0,100,0,98000,98000,300000,300000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - Out Of Combat - Say Line 3"),
(@ENTRY,0,5,0,1,0,100,0,106000,106000,300000,300000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirligig Wafflefry - Out Of Combat - Say Line 4");

-- Texts for Whirligig Wafflefry
SET @ENTRY := 25885;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hey, harbringer, how's that research coming along? There might be an Ultra-Kinetic Waffle Iron in it for you if you're prompt with the results!",12,0,100,1,0,0,"Whirligig Wafflefry"),
(@ENTRY,1,0,"Be the first on your block to own the incredible Electrostatic Maculation Blaster!",12,0,100,1,0,0,"Whirligig Wafflefry"),
(@ENTRY,2,0,"Derived from cutting edge Shattered Sun Offensive military technology, it blasts away stubborn stains with ease!",12,0,100,1,0,0,"Whirligig Wafflefry"),
(@ENTRY,3,0,"Wine stains, grass stains, even pet stains are no match for the Electrostatic Maculation Blaster!",12,0,100,1,0,0,"Whirligig Wafflefry"),
(@ENTRY,4,0,"Don't wait! Order now and receive my Ultra-Kinetic Waffle Iron at no additional charge!",12,0,100,1,0,0,"Whirligig Wafflefry");

-- Loot Crazed Hunter SAI
SET @ENTRY := 25979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,2,0,1,25,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loot Crazed Hunter - In Combat - Say Line 0");

-- Texts for Loot Crazed Hunter
SET @ENTRY := 25979;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Now THIS is a sport!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,1,"KILL KILL KILL!!!!!!!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,2,"I'm sure ol' Hemet can do something with your bones!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,3,"Give it up, little beast!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,4,"Just fifty more hooves and I'll have the new gun!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,5,"No way! Rhino head helmet for the low, low price of thirty rhino heads? I'll take two at those prices!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,6,"I wonder what Nesingwary will give me for your hide!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,7,"It's gonna be veal tonight!",12,0,100,0,0,0,"Loot Crazed Hunter"),
(@ENTRY,0,8,"Nesingwary is going to go broke if he keeps this up! Lane probably has no idea what he's doing!",12,0,100,0,0,0,"Loot Crazed Hunter");

-- Commander Stoutbeard SAI
SET @ENTRY := 26796;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - On Aggro - Remove Aura 47543 (Dungeon Only)"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - On Aggro - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,31403,1,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - On Aggro - Cast 31403 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,3000,4000,11000,15000,11,60067,7,0,0,0,0,6,0,0,0,0,0,0,0,"Commander Stoutbeard - In Combat - Cast 60067 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,6000,8000,19500,25000,11,38618,5,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - In Combat - Cast 38618 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,4,13000,15000,45000,55000,11,19134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - In Combat - Cast 19134 (Heroic Dungeon)"),
(@ENTRY,0,6,0,5,0,100,7,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - On Killed Unit - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,7,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Stoutbeard - On Death - Say Line 2 (Dungeon Only)");

-- Texts for Commander Stoutbeard
SET @ENTRY := 26796;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What? Where in a..? Don't just stand around lads KILL SOMEBODY!",14,0,100,0,0,13193,"Commander Stoutbeard"),
(@ENTRY,1,0,"Now we're gettin' somewhere!",14,0,100,0,0,13195,"Commander Stoutbeard"),
(@ENTRY,2,0,"Is that all you've... got?",14,0,100,0,0,13194,"Commander Stoutbeard");

-- Torturer LeCraft SAI
SET @ENTRY := 27209;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,168000,11,30478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torturer LeCraft - In Combat - Cast 30478"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,20000,26000,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torturer LeCraft - In Combat - Cast 30621"),
(@ENTRY,0,3,4,8,1,100,1,48603,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 1 (Phase 1)"),
(@ENTRY,0,4,0,61,1,100,1,48603,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Increment Event Phase (Phase 1)"),
(@ENTRY,0,5,6,8,2,100,1,48603,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 2 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,1,48603,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,8,8,4,100,1,48603,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 3 (Phase 4)"),
(@ENTRY,0,8,0,61,4,100,1,48603,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Increment Event Phase (Phase 4)"),
(@ENTRY,0,9,10,8,8,100,1,48603,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 4 (Phase 8)"),
(@ENTRY,0,10,0,61,8,100,1,48603,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Increment Event Phase (Phase 8)"),
(@ENTRY,0,11,13,8,16,100,1,48603,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 5 (Phase 16)"),
(@ENTRY,0,12,0,61,16,100,1,48603,0,0,0,33,27394,0,0,0,0,0,7,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Quest Credit (Phase 16)"),
(@ENTRY,0,13,0,61,16,100,1,48603,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Increment Event Phase (Phase 16)"),
(@ENTRY,0,14,0,8,0,100,1,48603,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Spellhit By 48603 - Say Line 5"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torturer LeCraft - On Evade - Set Sheath Melee");

-- Texts for Torturer LeCraft
SET @ENTRY := 27209;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Come to play?",12,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,1,0,"Ow! I'll tell you NOTHING, filthy $r!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,2,0,"Wait... WAIT! What is it that you want to know? I know you're the $c named $N.",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,3,0,"OW...NO! We know that you've been stealing our armor and weapons and horses!",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,4,0,"We know... that you don't... know why we're immune... to your so-called blight. Grand Admiral Westwind somehow gave the high abbot that prayer. I beg you... no more... please?",15,0,100,0,0,0,"Torturer LeCraft"),
(@ENTRY,5,0,"AHHHHHHHHH! Please... we know... that you... have a spy... disguised as... one of us! There... that's all that I know. Please... mercy... STOP!",15,0,100,0,0,0,"Torturer LeCraft");

-- Texts for Urgreth of the Thousand Tombs
SET @ENTRY := 28103;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s begins to emanate a power dark energy!",16,0,100,0,0,0,"Urgreth of the Thousand Tombs");

-- Scarlet Medic SAI
SET @ENTRY := 28608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Out Of Combat - Cast 13864"),
(@ENTRY,0,2,3,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Cast 15498"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,2,100,0,0,40,3400,4800,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-40 Range - Cast 15498 (Phase 2)"),
(@ENTRY,0,6,7,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-7% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-7% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,0,3,4,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 15-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-15% Health - Flee For Assist");

-- Texts for Scarlet Medic
SET @ENTRY := 28608;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The Crusade will be victorious!",12,0,100,0,0,0,"Scarlet Medic"),
(@ENTRY,0,1,"Let the purging begin!",12,0,100,0,0,0,"Scarlet Medic"),
(@ENTRY,0,2,"You're not welcome in these lands, monster!",12,0,100,0,0,0,"Scarlet Medic");
/*
DELETE FROM `creature_ai_texts` WHERE `entry` > -47;
DELETE FROM `creature_ai_texts` WHERE `entry` < -47;
*/
