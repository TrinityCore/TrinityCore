-- Defias Blackguard SAI
SET @ENTRY := 636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,11,6408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Blackguard - Out Of Combat - Cast 6408 (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,28,6408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Blackguard - On Aggro - Remove Aura 6408 (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Blackguard - On Aggro - Say Line 0 (Normal Dungeon)");

-- Texts for Defias Blackguard
SET @ENTRY := 636;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s jumps out of the shadows!",16,0,100,0,0,0,"Defias Blackguard");

-- Dark Iron Dwarf SAI
SET @ENTRY := 1051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Dwarf - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2000,8300,18000,34200,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Dwarf - In Combat - Cast 7891"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Dwarf - Between 0-15% Health - Flee For Assist");

-- Dark Iron Saboteur SAI
SET @ENTRY := 1052;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2100,7300,18000,26000,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Saboteur - In Combat - Cast 7891"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Saboteur - Between 0-15% Health - Say Line 0"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Saboteur - Between 0-15% Health - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,11,3204,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Saboteur - Between 0-15% Health - Cast 3204");

-- Dark Iron Tunneler SAI
SET @ENTRY := 1053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Tunneler - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,500,1000,1300,5000,11,7164,33,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 7164"),
(@ENTRY,0,2,0,0,0,100,0,2000,8500,18000,22000,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 7891"),
(@ENTRY,0,3,0,0,0,100,0,3100,12400,8900,15900,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 11971"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Tunneler - Between 0-15% Health - Flee For Assist");

-- Texts for Dark Iron Dwarf
SET @ENTRY := 1051;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never cross a Dark Iron, $c.",12,0,100,0,0,0,"Dark Iron Dwarf"),
(@ENTRY,0,1,"Time to die, $c!",12,0,100,0,0,0,"Dark Iron Dwarf"),
(@ENTRY,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,"Dark Iron Dwarf");

-- Texts for Dark Iron Saboteur
SET @ENTRY := 1052;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Wahehe! I'm taking you down with me!",12,0,100,0,0,0,"Dark Iron Saboteur"),
(@ENTRY,1,0,"%s's eyes glow red as he lights his dynamite and begins to cackle madly!",16,0,100,0,0,0,"Dark Iron Saboteur");

-- Texts for Dark Iron Tunneler
SET @ENTRY := 1053;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never cross a Dark Iron, $c.",12,0,100,0,0,0,"Dark Iron Tunneler"),
(@ENTRY,0,1,"Time to die, $c!",12,0,100,0,0,0,"Dark Iron Tunneler"),
(@ENTRY,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,"Dark Iron Tunneler");

-- Targorr the Dread SAI
SET @ENTRY := 1696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targorr the Dread - On Aggro - Cast 674 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3500,9100,9100,15500,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targorr the Dread - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targorr the Dread - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targorr the Dread - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Bazil Thredd SAI
SET @ENTRY := 1716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bazil Thredd - In Combat - Cast 674 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,20,3,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bazil Thredd - In Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,10700,15100,25900,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bazil Thredd - In Combat - Cast 7964 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,8500,10200,26300,30500,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bazil Thredd - In Combat - Cast 9128 (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bazil Thredd - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Texts for Targorr the Dread
SET @ENTRY := 1696;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Targorr the Dread");

-- Texts for Bazil Thredd
SET @ENTRY := 1716;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Why haven't the Stormwind guards come?",12,0,100,0,0,0,"Bazil Thredd");

-- Gilnid SAI
SET @ENTRY := 1763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,120000,120000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gilnid - Out Of Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,2100,4800,23300,44900,11,5213,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gilnid - In Combat - Cast 5213 (Normal Dungeon)");

-- Texts for Gilnid
SET @ENTRY := 1763;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Get those parts moving down to the ship!",12,0,100,0,0,0,"Gilnid"),
(@ENTRY,0,1,"Anyone want to take a break?  Well too bad!  Get to work you oafs!",12,0,100,0,0,0,"Gilnid");

-- Chieftain Nek'rosh SAI
SET @ENTRY := 2091;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Chieftain Nek'rosh - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2300,7900,12100,16400,11,6192,32,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Nek'rosh - In Combat - Cast 6192"),
(@ENTRY,0,2,0,0,0,100,0,3800,9400,6400,9400,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Nek'rosh - In Combat - Cast 13730"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Chieftain Nek'rosh - Between 0-15% Health - Flee For Assist");

-- Dragonmaw Grunt SAI
SET @ENTRY := 2102;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Grunt - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,5200,11100,7300,20900,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Grunt - In Combat - Cast 8242"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Grunt - Between 0-15% Health - Flee For Assist");

-- Texts for Chieftain Nek'rosh
SET @ENTRY := 2091;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,"Chieftain Nek''rosh"),
(@ENTRY,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,"Chieftain Nek''rosh"),
(@ENTRY,0,2,"For the Dragonmaw!",12,1,100,0,0,0,"Chieftain Nek''rosh");

-- Texts for Dragonmaw Grunt
SET @ENTRY := 2102;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,"Dragonmaw Grunt"),
(@ENTRY,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,"Dragonmaw Grunt"),
(@ENTRY,0,2,"For the Dragonmaw!",12,1,100,0,0,0,"Dragonmaw Grunt");

-- Garneg Charskull SAI
SET @ENTRY := 2108;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Garneg Charskull - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,6000,19600,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 15039"),
(@ENTRY,0,2,0,0,0,100,0,2300,6600,1200,7700,11,184,32,0,0,0,0,1,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 184"),
(@ENTRY,0,3,0,0,0,100,0,10200,17600,33800,61100,11,6725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 6725"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Garneg Charskull - Between 0-15% Health - Flee For Assist");

-- Texts for Garneg Charskull
SET @ENTRY := 2108;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,"Garneg Charskull"),
(@ENTRY,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,"Garneg Charskull"),
(@ENTRY,0,2,"For the Dragonmaw!",12,1,100,0,0,0,"Garneg Charskull");

-- Lord Falconcrest SAI
SET @ENTRY := 2597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,300000,300000,600000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Falconcrest - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2900,9200,1100,8800,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Falconcrest - In Combat - Cast 32064"),
(@ENTRY,0,2,0,0,0,100,0,4100,12100,11900,36200,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Falconcrest - In Combat - Cast 6713");

-- Otto SAI
SET @ENTRY := 2599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,308000,308000,608000,608000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Otto - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,9500,15000,8900,23900,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Otto - In Combat - Cast 6253"),
(@ENTRY,0,2,0,0,0,100,0,7200,10700,10200,21000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Otto - In Combat - Cast 12555"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Otto - Between 0-15% Health - Flee For Assist");

-- Texts for Lord Falconcrest
SET @ENTRY := 2597;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I presume you come with good news?",12,0,100,0,0,0,"Lord Falconcrest");

-- Texts for Otto
SET @ENTRY := 2599;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Things are going as planned, Lord Falconcrest. I assure you, it is only a matter of time.",12,0,100,0,0,0,"Otto");

-- Thistlefur Avenger SAI
SET @ENTRY := 3925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Respawn - Cast 6813"),
(@ENTRY,0,1,0,14,0,100,1,664,20,0,0,11,8602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Friendly Unit At 664 Health Within 20 Range - Cast 8602"),
(@ENTRY,0,2,0,14,0,100,1,664,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Friendly Unit At 664 Health Within 20 Range - Say Line 0"),
(@ENTRY,0,3,0,2,0,30,1,0,30,0,0,11,8602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - Between 0-30% Health - Cast 8602");

-- Texts for Thistlefur Avenger
SET @ENTRY := 3925;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a rage after seeing a friend fall in battle!",16,0,100,0,0,0,"Thistlefur Avenger");

-- Venomous Cloud Serpent SAI
SET @ENTRY := 4118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,10022,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venomous Cloud Serpent - On Respawn - Cast 10022");

-- Crag Stalker SAI
SET @ENTRY := 4126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crag Stalker - Out Of Combat - Cast 30831"),
(@ENTRY,0,1,0,0,0,100,1,1000,1000,0,0,11,8151,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crag Stalker - In Combat - Cast 8151");

-- Silithid Invader SAI
SET @ENTRY := 4131;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,22000,25000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Invader - In Combat - Cast 6016"),
(@ENTRY,0,1,0,0,0,100,1,10000,16000,0,0,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Invader - In Combat - Cast 8137");

-- Silithid Ravager SAI
SET @ENTRY := 4132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,9000,15000,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Ravager - In Combat - Cast 8255");

-- Scorpid Terror SAI
SET @ENTRY := 4139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,11000,17000,11,7399,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scorpid Terror - In Combat - Cast 7399");

-- Scorpid Reaver SAI
SET @ENTRY := 4140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,6500,9500,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Reaver - In Combat - Cast 40505");

-- Sparkleshell Tortoise SAI
SET @ENTRY := 4142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,1000,1000,11,7273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparkleshell Tortoise - Out Of Combat - Cast 7273");

-- Sparkleshell Snapper SAI
SET @ENTRY := 4143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,1000,1000,11,7273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparkleshell Snapper - Out Of Combat - Cast 7273"),
(@ENTRY,0,1,0,0,0,60,0,5000,5000,15000,15000,11,6730,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sparkleshell Snapper - In Combat - Cast 6730");

-- Sparkleshell Borer SAI
SET @ENTRY := 4144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,1000,1000,11,7273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparkleshell Borer - Out Of Combat - Cast 7273"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,26000,30000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sparkleshell Borer - In Combat - Cast 6016");

-- Saltstone Basilisk SAI
SET @ENTRY := 4147;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,8000,8000,30000,30000,11,3636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltstone Basilisk - In Combat - Cast 3636");

-- Saltstone Gazer SAI
SET @ENTRY := 4150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,12000,12000,15000,15000,11,3635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltstone Gazer - In Combat - Cast 3635");

-- Saltstone Crystalhide SAI
SET @ENTRY := 4151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,8000,8000,18000,18000,11,8129,0,0,0,0,0,5,0,0,0,0,0,0,0,"Saltstone Crystalhide - In Combat - Cast 8129");

-- Scarlet Abbot SAI
SET @ENTRY := 4303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Abbot - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Abbot - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,65,2,17500,17500,40000,42500,11,6064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Abbot - In Combat - Cast 6064 (Normal Dungeon)"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,11,1006,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Abbot - On Aggro - Cast 1006 (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,20,0,0,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Abbot - Between 0-20% Health - Cast 8362 (Normal Dungeon)");

-- Scarlet Torturer SAI
SET @ENTRY := 4306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Torturer - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,45000,45000,45000,45000,11,37668,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Torturer - In Combat - Cast 37668 (Normal Dungeon)");

-- Texts for Scarlet Abbot
SET @ENTRY := 4303;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Scarlet Abbot");

-- Texts for Scarlet Torturer
SET @ENTRY := 4306;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Confess and we shall set you free.",12,0,100,0,0,0,"Scarlet Torturer"),
(@ENTRY,0,1,"You will talk eventually. You might as well spill it now.",12,0,100,0,0,0,"Scarlet Torturer"),
(@ENTRY,0,2,"What? Oh no. I don't care what you have to say. I just enjoy inflicting pain.",14,0,100,0,0,0,"Scarlet Torturer");

-- Hatefury Rogue SAI
SET @ENTRY := 4670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,1000,1000,11,6920,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Rogue - Out Of Combat - Cast 6920"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Rogue - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Rogue - Between 0-30% Health - Say Line 0");

-- Hatefury Trickster SAI
SET @ENTRY := 4671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,20000,20000,11,744,33,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Trickster - In Combat - Cast 744"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Trickster - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Trickster - Between 0-30% Health - Say Line 0");

-- Hatefury Felsworn SAI
SET @ENTRY := 4672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Felsworn - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Felsworn - Between 0-30% Health - Say Line 0");

-- Hatefury Betrayer SAI
SET @ENTRY := 4673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Betrayer - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Betrayer - Between 0-30% Health - Say Line 0");

-- Hatefury Shadowstalker SAI
SET @ENTRY := 4674;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,15000,11,8629,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Shadowstalker - In Combat - Cast 8629"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Shadowstalker - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Shadowstalker - Between 0-30% Health - Say Line 0");

-- Texts for Hatefury Rogue
SET @ENTRY := 4670;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Rogue");

-- Texts for Hatefury Trickster
SET @ENTRY := 4671;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Trickster");

-- Texts for Hatefury Felsworn
SET @ENTRY := 4672;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Felsworn");

-- Texts for Hatefury Betrayer
SET @ENTRY := 4673;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Betrayer");

-- Texts for Hatefury Shadowstalker
SET @ENTRY := 4674;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Shadowstalker");

-- Fallenroot Shadowstalker SAI
SET @ENTRY := 4798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,20000,35000,11,6205,32,0,0,0,0,2,0,0,0,0,0,0,0,"Fallenroot Shadowstalker - In Combat - Cast 6205 (Normal Dungeon)");

-- Blackfathom Sea Witch SAI
SET @ENTRY := 4805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Sea Witch - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,10000,16000,20000,11,122,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Sea Witch - In Combat - Cast 122 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,3,3000,6000,0,0,11,6143,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Sea Witch - In Combat - Cast 6143 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackfathom Sea Witch - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Blackfathom Myrmidon SAI
SET @ENTRY := 4807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,16000,20000,11,8379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackfathom Myrmidon - In Combat - Cast 8379 (Normal Dungeon)");

-- Twilight Acolyte SAI
SET @ENTRY := 4809;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,750,40,18000,22000,11,2055,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Acolyte - On Friendly Unit At 750 Health Within 40 Range - Cast 2055 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,50,22000,25000,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Acolyte - Between 0-50% Health - Cast 8362 (Normal Dungeon)");

-- Twilight Reaver SAI
SET @ENTRY := 4810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,8000,12000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Reaver - In Combat - Cast 8374 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Twilight Reaver - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Twilight Loreseeker SAI
SET @ENTRY := 4812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,12000,20000,11,18972,32,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Loreseeker - In Combat - Cast 18972 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,30,10000,10000,11,8365,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Loreseeker - Between 0-30% Health - Cast 8365 (Not found in DBCs!) (Normal Dungeon)");

-- Murkshallow Snapclaw SAI
SET @ENTRY := 4815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,16000,20000,11,8379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkshallow Snapclaw - In Combat - Cast 8379 (Not found in DBCs!) (Normal Dungeon)");

-- Blindlight Murloc SAI
SET @ENTRY := 4818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Murloc - On Aggro - Cast 7164 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,75,2,3000,5000,8000,11000,11,7405,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blindlight Murloc - In Combat - Cast 7405 (Not found in DBCs!) (Normal Dungeon)");

-- Blindlight Muckdweller SAI
SET @ENTRY := 4819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,50000,60000,11,8382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blindlight Muckdweller - Between 0-50% Health - Cast 8382 (Not found in DBCs!) (Normal Dungeon)");

-- Twilight Elementalist SAI
SET @ENTRY := 4814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,13728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Elementalist - In Combat - Cast 13728 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,13000,17000,11,15039,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Elementalist - In Combat - Cast 15039 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,1000,2500,11000,15000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Elementalist - In Combat - Cast 12548 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,3000,6000,7000,12000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Elementalist - In Combat - Cast 11824 (Not found in DBCs!) (Normal Dungeon)");

-- Deep Pool Threshfin SAI
SET @ENTRY := 4827;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Pool Threshfin - In Combat - Cast 3604 (Not found in DBCs!) (Normal Dungeon)");

-- Stonevault Rockchewer SAI
SET @ENTRY := 4851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,2,0,50,120000,120000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Rockchewer - Between 0-50% Health - Cast 8599 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Rockchewer - Between 0-50% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Stonevault Rockchewer
SET @ENTRY := 4851;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stonevault Rockchewer");

-- Stonevault Brawler SAI
SET @ENTRY := 4855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,7000,10000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Brawler - In Combat - Cast 3391 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Brawler - Between 0-30% Health - Cast 8599 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Brawler - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Stonevault Brawler
SET @ENTRY := 4855;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stonevault Brawler");

-- Ghamoo-ra SAI
SET @ENTRY := 4887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,13000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghamoo-ra - In Combat - Cast 5568 (Not found in DBCs!) (Normal Dungeon)");

-- Slim's Friend SAI
SET @ENTRY := 4971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3700,6500,16000,22800,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Slim's Friend - In Combat - Cast 744 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8900,8400,15300,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Slim's Friend - In Combat - Cast 7992 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,70,0,500,500,2100,5600,11,2589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slim's Friend - In Combat - Cast 2589 (Not found in DBCs!)");

-- Unliving Atal'ai SAI
SET @ENTRY := 5267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7200,13300,14500,24200,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Atal'ai - In Combat - Cast 3391 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Atal'ai - Between 0-30% Health - Cast 8269 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Atal'ai - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Unliving Atal'ai
SET @ENTRY := 5267;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Unliving Atal\'ai");

-- Firewing Defender SAI
SET @ENTRY := 5355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firewing Defender - In Combat - Cast 11976 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,12000,18000,11,33483,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firewing Defender - In Combat - Cast 33483 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,1300,18000,11,33390,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firewing Defender - In Combat - Cast 33390 (Not found in DBCs!)");

-- Dreamscythe SAI
SET @ENTRY := 5721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,3,0,80,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreamscythe - On LOS Out Of Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreamscythe - On Aggro - Say Line 1 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2800,6100,8300,17900,11,12884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreamscythe - In Combat - Cast 12884 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,8700,13900,19300,34700,11,12882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreamscythe - In Combat - Cast 12882 (Not found in DBCs!) (Normal Dungeon)");

-- Texts for Dreamscythe
SET @ENTRY := 5721;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Turn back! Do not wake the dreamer!",14,0,100,0,0,5866,"Dreamscythe"),
(@ENTRY,1,0,"You know not what you do! We must destroy you for your own good.",14,0,100,0,0,0,"Dreamscythe");

-- Silithid Creeper Egg SAI
SET @ENTRY := 5781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7500,7500,3000,3000,11,6588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - In Combat - Cast 6588 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,1,0,0,30000,30000,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - In Combat - Cast 7 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,0,0,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - In Combat - Disallow Combat Movement");

-- Brontus SAI
SET @ENTRY := 5827;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brontus - On Aggro - Cast 6268 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,60,0,43500,43500,15000,15000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brontus - In Combat - Cast 6016 (Not found in DBCs!)");

-- Humar the Pridelord SAI
SET @ENTRY := 5828;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,14000,11,3247,32,0,0,0,0,5,0,0,0,0,0,0,0,"Humar the Pridelord - Between 0-5 Range - Cast 3247 (Not found in DBCs!)");

-- Snort the Heckler SAI
SET @ENTRY := 5829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,0,16500,16500,13000,13000,11,7951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snort the Heckler - In Combat - Cast 7951 (Not found in DBCs!)");

-- Sister Rathtalon SAI
SET @ENTRY := 5830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9500,12500,12000,12000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sister Rathtalon - In Combat - Cast 6728 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,80,0,1200,1200,14400,24800,11,6982,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister Rathtalon - In Combat - Cast 6982 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,80,0,3400,3400,44100,55600,11,6535,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Rathtalon - In Combat - Cast 6535 (Not found in DBCs!)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sister Rathtalon - Between 0-15% Health - Flee For Assist");

-- Swiftmane SAI
SET @ENTRY := 5831;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,7000,15000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swiftmane - In Combat - Cast 6016 (Not found in DBCs!)");

-- Thunderstomp SAI
SET @ENTRY := 5832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,9000,9000,16000,11,6254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderstomp - In Combat - Cast 6254 (Not found in DBCs!)");

-- Foreman Grills SAI
SET @ENTRY := 5835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,7000,7000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Grills - In Combat - Cast 9080 (Not found in DBCs!)");

-- Engineer Whirleygig SAI
SET @ENTRY := 5836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Whirleygig - On Aggro - Cast 7979 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6500,6500,10000,10000,11,8209,0,0,0,0,0,5,0,0,0,0,0,0,0,"Engineer Whirleygig - In Combat - Cast 8209 (Not found in DBCs!)");

-- Rocklance SAI
SET @ENTRY := 5841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocklance - On Aggro - Cast 7164 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,17000,17000,13000,17000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rocklance - In Combat - Cast 15496 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,60,0,43500,43500,15000,15000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rocklance - In Combat - Cast 11971 (Not found in DBCs!)");

-- Malgin Barleybrew SAI
SET @ENTRY := 5848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,5242,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malgin Barleybrew - On Aggro - Cast 5242 (Not found in DBCs!)");

-- Digger Flameforge SAI
SET @ENTRY := 5849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,12500,12500,10000,10000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Digger Flameforge - In Combat - Cast 6253 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,1,100,100,1000,1000,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Digger Flameforge - In Combat - Disallow Combat Movement"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,2000,2000,11,7978,0,0,0,0,0,5,0,0,0,0,0,0,0,"Digger Flameforge - In Combat - Cast 7978 (Not found in DBCs!)");

-- Hagg Taurenbane SAI
SET @ENTRY := 5859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,7000,7000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - In Combat - Cast 9080 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,35000,35000,10000,10000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - In Combat - Cast 13730 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,17000,17000,13000,17000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - In Combat - Cast 40505 (Not found in DBCs!)");

-- Geopriest Gukk'rok SAI
SET @ENTRY := 5863;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,70,0,0,60,12500,12500,11,600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geopriest Gukk'rok - Between 0-60% Health - Cast 600 (Not found in DBCs!)"),
(@ENTRY,0,1,0,2,0,70,0,0,45,7500,7500,11,6075,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geopriest Gukk'rok - Between 0-45% Health - Cast 6075 (Not found in DBCs!)"),
(@ENTRY,0,2,0,2,0,70,0,0,20,27500,27500,11,2054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geopriest Gukk'rok - Between 0-20% Health - Cast 2054 (Not found in DBCs!)");

-- Dishu SAI
SET @ENTRY := 5865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,8210,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dishu - On Aggro - Cast 8210 (Not found in DBCs!)");

-- Aqua Guardian SAI
SET @ENTRY := 6047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,14000,18000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aqua Guardian - In Combat - Cast 865 (Not found in DBCs!) (Normal Dungeon)");

-- Summoned Felhunter SAI
SET @ENTRY := 6268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,11000,17000,11,2691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Felhunter - In Combat - Cast 2691 (Not found in DBCs!)");

-- Devilsaur SAI
SET @ENTRY := 6498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,30000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Devilsaur - In Combat - Cast 14099 (Not found in DBCs!)");

-- Tyrant Devilsaur SAI
SET @ENTRY := 6500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,8000,8008,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tyrant Devilsaur - In Combat - Cast 14100 (Not found in DBCs!)");

-- Stegodon SAI
SET @ENTRY := 6501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,6,15,6000,6000,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stegodon - Between 6-15 Range - Cast 6268 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,8000,14000,11,15652,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stegodon - In Combat - Cast 15652 (Not found in DBCs!)");

-- Plated Stegodon SAI
SET @ENTRY := 6502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,8000,14000,11,15652,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plated Stegodon - In Combat - Cast 15652 (Not found in DBCs!)");

-- Spiked Stegodon SAI
SET @ENTRY := 6503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,8000,14000,11,15652,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiked Stegodon - In Combat - Cast 15652 (Not found in DBCs!)");

-- Thunderstomp Stegodon SAI
SET @ENTRY := 6504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,8000,14000,11,15652,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderstomp Stegodon - In Combat - Cast 15652 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,14000,14000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderstomp Stegodon - In Combat - Cast 15548 (Not found in DBCs!)");

-- Ravasaur SAI
SET @ENTRY := 6505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,20000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravasaur - In Combat - Cast 13443 (Not found in DBCs!)");

-- Ravasaur Hunter SAI
SET @ENTRY := 6507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,20000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravasaur Hunter - In Combat - Cast 13443 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,20000,20000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravasaur Hunter - In Combat - Cast 3604 (Not found in DBCs!)");

-- Venomhide Ravasaur SAI
SET @ENTRY := 6508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venomhide Ravasaur - On Respawn - Cast 14108 (Not found in DBCs!)");

-- Bloodpetal Lasher SAI
SET @ENTRY := 6509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14111,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpetal Lasher - On Respawn - Cast 14111 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,20000,20000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpetal Lasher - In Combat - Cast 6607 (Not found in DBCs!)");

-- Bloodpetal Flayer SAI
SET @ENTRY := 6510;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14111,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpetal Flayer - On Respawn - Cast 14111 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,6000,9000,11,14112,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpetal Flayer - In Combat - Cast 14112 (Not found in DBCs!)");

-- Bloodpetal Thresher SAI
SET @ENTRY := 6511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14111,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpetal Thresher - On Respawn - Cast 14111 (Not found in DBCs!)");

-- Bloodpetal Trapper SAI
SET @ENTRY := 6512;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14111,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpetal Trapper - On Respawn - Cast 14111 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,18000,23000,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpetal Trapper - In Combat - Cast 11922 (Not found in DBCs!)");

-- Un'Goro Stomper SAI
SET @ENTRY := 6513;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Stomper - Between 0-20% Health - Cast 8599 (Not found in DBCs!)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Stomper - Between 0-20% Health - Say Line 0");

-- Texts for Un'Goro Stomper
SET @ENTRY := 6513;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Un\'Goro Stomper");

-- Un'Goro Thunderer SAI
SET @ENTRY := 6516;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,9000,15000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Un'Goro Thunderer - In Combat - Cast 12553 (Not found in DBCs!)");

-- Tar Beast SAI
SET @ENTRY := 6517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tar Beast - On Respawn - Cast 14178 (Not found in DBCs!)");

-- Tar Lurker SAI
SET @ENTRY := 6518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14178,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Lurker - On Respawn - Cast 14178 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,23000,11,7279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Lurker - In Combat - Cast 7279 (Not found in DBCs!)");

-- Tar Lord SAI
SET @ENTRY := 6519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14178,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Lord - On Respawn - Cast 14178 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,17000,11,12747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tar Lord - In Combat - Cast 12747 (Not found in DBCs!)"),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Lord - Between 0-40% Health - Cast 11640 (Not found in DBCs!)");

-- Scorching Elemental SAI
SET @ENTRY := 6520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,3000,6000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorching Elemental - In Combat - Cast 13878 (Not found in DBCs!)");

-- Tar Creeper SAI
SET @ENTRY := 6527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,14178,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Creeper - On Respawn - Cast 14178 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,14000,19000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tar Creeper - In Combat - Cast 5568 (Not found in DBCs!)");

-- Gorishi Wasp SAI
SET @ENTRY := 6551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,24000,24000,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Wasp - In Combat - Cast 8137 (Not found in DBCs!)");

-- Gorishi Worker SAI
SET @ENTRY := 6552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,24000,24000,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Worker - In Combat - Cast 8137 (Not found in DBCs!)");

-- Gorishi Reaver SAI
SET @ENTRY := 6553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,8000,12000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Reaver - In Combat - Cast 40504 (Not found in DBCs!)");

-- Gorishi Stinger SAI
SET @ENTRY := 6554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,24000,24000,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Stinger - In Combat - Cast 8137 (Not found in DBCs!)");

-- Gorishi Tunneler SAI
SET @ENTRY := 6555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,8000,12000,11,14120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Tunneler - In Combat - Cast 14120 (Not found in DBCs!)");

-- Glutinous Ooze SAI
SET @ENTRY := 6559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,14147,7,0,0,0,0,1,0,0,0,0,0,0,0,"Glutinous Ooze - On Death - Cast 14147 (Not found in DBCs!)");

-- Ravasaur Matriarch SAI
SET @ENTRY := 6581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,20000,20000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravasaur Matriarch - In Combat - Cast 13445 (Not found in DBCs!)");

-- Clutchmother Zavas SAI
SET @ENTRY := 6582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,8000,18000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clutchmother Zavas - In Combat - Cast 40504 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,20000,24000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clutchmother Zavas - In Combat - Cast 12097 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,10000,15000,11,14205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Clutchmother Zavas - In Combat - Cast 14205 (Not found in DBCs!)");

-- Gruff SAI
SET @ENTRY := 6583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,12000,12000,11,15549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gruff - In Combat - Cast 15549 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,14000,14000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruff - In Combat - Cast 15548 (Not found in DBCs!)");

-- King Mosh SAI
SET @ENTRY := 6584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,12000,20000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Mosh - In Combat - Cast 14100 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,14000,19000,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Mosh - In Combat - Cast 15550 (Not found in DBCs!)"),
(@ENTRY,0,2,0,0,0,100,0,4000,4000,13000,13000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Mosh - In Combat - Cast 14331 (Not found in DBCs!)");

-- Uhk'loc SAI
SET @ENTRY := 6585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,5,0,100,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uhk'loc - On Killed Unit - Cast 9128 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,8000,12000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Uhk'loc - In Combat - Cast 10966 (Not found in DBCs!)");
