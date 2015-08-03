-- Edwin VanCleef SAI
SET @ENTRY := 639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,3,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - In Combat - Cast 674 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2200,14200,8000,17500,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,34,66,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 34-66% Health - Say Line 1 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,26,50,0,0,11,5200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 26-50% Health - Cast 5200 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 26-50% Health - Say Line 2 (Normal Dungeon)"),
(@ENTRY,0,6,0,2,0,100,3,0,33,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 0-33% Health - Say Line 3 (Normal Dungeon)"),
(@ENTRY,0,7,8,2,0,100,3,0,25,0,0,11,5200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 0-25% Health - Cast 5200 (Normal Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,25,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - Between 0-25% Health - Say Line 2 (Normal Dungeon)"),
(@ENTRY,0,9,0,5,0,100,2,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - On Killed Unit - Say Line 4 (Normal Dungeon)"),
(@ENTRY,0,10,0,6,0,100,3,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edwin VanCleef - On Death - Say Line 5 (Normal Dungeon)");

-- Texts for Edwin VanCleef
SET @ENTRY := 639;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"None may challenge the Brotherhood!",14,0,100,0,0,5780,"Edwin VanCleef"),
(@ENTRY,1,0,"Lapdogs, all of you!",14,0,100,0,0,5782,"Edwin VanCleef"),
(@ENTRY,2,0,"%s calls more of his allies out of the shadows.",16,0,100,0,0,0,"Edwin VanCleef"),
(@ENTRY,3,0,"Fools! Our cause is righteous!",14,0,100,0,0,5783,"Edwin VanCleef"),
(@ENTRY,4,0,"And stay down!",14,0,100,0,0,5781,"Edwin VanCleef"),
(@ENTRY,5,0,"The Brotherhood will prevail!",14,0,100,0,0,5784,"Edwin VanCleef");

-- Fen Ray SAI
SET @ENTRY := 17731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3200,8900,16300,21500,11,34984,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fen Ray - In Combat - Cast 34984 (Dungeon Only)");

-- Underbog Lord SAI
SET @ENTRY := 17734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10500,10500,17000,20000,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,"Underbog Lord - In Combat - Cast 25778 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,7100,7100,12000,16000,11,32065,33,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Lord - In Combat - Cast 32065 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,7,0,50,0,0,11,40318,1,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lord - Between 0-50% Health - Cast 40318 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lord - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Lord - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Underbog Lord
SET @ENTRY := 17734;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Underbog Lord");

-- Wrathfin Warrior SAI
SET @ENTRY := 17735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4100,11500,9700,14900,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Warrior - In Combat - Cast 11976 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,4600,4600,34900,34900,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathfin Warrior - In Combat - Cast 11972 (Dungeon Only)"),
(@ENTRY,0,2,3,2,0,100,7,1,20,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathfin Warrior - Between 1-20% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathfin Warrior - Between 1-20% Health - Say Line 0 (Dungeon Only)");

-- Texts for Wrathfin Warrior
SET @ENTRY := 17735;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Wrathfin Warrior");

-- Coilfang Myrmidon SAI
SET @ENTRY := 17800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,6,3000,5000,5000,7500,11,15496,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Myrmidon - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,12,0,100,7,0,20,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Myrmidon - On Target Between 0-20% Health - Cast 7160 (Dungeon Only)");

-- Coilfang Warrior SAI
SET @ENTRY := 17802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Warrior - On Aggro - Cast 7164 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1000,5000,9000,15000,11,31403,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Warrior - In Combat - Cast 31403 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,12000,16000,11,35105,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Warrior - In Combat - Cast 35105 (Dungeon Only)");

-- Coilfang Oracle SAI
SET @ENTRY := 17803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,13000,16000,11,22582,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Oracle - In Combat - Cast 22582 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,13000,16000,11,37865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Oracle - In Combat - Cast 37865 (Heroic Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,13200,40,9000,14000,11,22883,1,0,0,0,0,7,0,0,0,0,0,0,0,"Coilfang Oracle - On Friendly Unit At 13200 Health Within 40 Range - Cast 22883 (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,4,13200,40,9000,14000,11,31730,1,0,0,0,0,7,0,0,0,0,0,0,0,"Coilfang Oracle - On Friendly Unit At 13200 Health Within 40 Range - Cast 31730 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,9000,12000,14000,18000,11,8281,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Oracle - In Combat - Cast 8281 (Dungeon Only)");

-- Coilfang Slavemaster SAI
SET @ENTRY := 17805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,11000,15000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Slavemaster - In Combat - Cast 6713 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,8000,12000,12000,15000,11,10987,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavemaster - In Combat - Cast 10987 (Dungeon Only)"),
(@ENTRY,0,2,3,2,0,100,7,0,20,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavemaster - Between 0-20% Health - Cast 8269 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavemaster - Between 0-20% Health - Say Line 0 (Dungeon Only)");

-- Texts for Coilfang Slavemaster
SET @ENTRY := 17805;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Coilfang Slavemaster");

-- Lordaeron Watchman SAI
SET @ENTRY := 17814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,9000,10000,17000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Watchman - In Combat - Cast 11976 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,7000,11000,11000,18000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Watchman - In Combat - Cast 12169 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lordaeron Watchman - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Bogstrok SAI
SET @ENTRY := 17816;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4100,12100,15700,20100,11,31551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bogstrok - In Combat - Cast 31551 (Dungeon Only)");

-- Greater Bogstrok SAI
SET @ENTRY := 17817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2400,18100,10800,16900,11,35760,32,0,0,0,0,5,0,0,0,0,0,0,0,"Greater Bogstrok - In Combat - Cast 35760 (Dungeon Only)");

-- Durnholde Sentry SAI
SET @ENTRY := 17819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,9000,8000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Sentry - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2000,3000,11000,15000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Sentry - In Combat - Cast 9080 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,11000,14000,9000,13000,11,14895,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Sentry - In Combat - Cast 14895 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Durnholde Sentry - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Durnholde Warden SAI
SET @ENTRY := 17833;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,19000,21000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Warden - In Combat - Cast 15654 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,19000,21000,11,34941,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Warden - In Combat - Cast 34941 (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,15000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Warden - Between 0-50% Health - Cast 15586 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,4,0,50,15000,20000,11,22883,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Warden - Between 0-50% Health - Cast 22883 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,16000,24000,20000,35000,11,22884,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Warden - In Combat - Cast 22884 (Dungeon Only)"),
(@ENTRY,0,5,0,0,0,100,6,7000,12000,10000,16000,11,17201,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Warden - In Combat - Cast 17201 (Dungeon Only)"),
(@ENTRY,0,6,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Durnholde Warden - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Durnholde Tracking Hound SAI
SET @ENTRY := 17840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,50,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Tracking Hound - Between 0-50% Health - Cast 8269 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Tracking Hound - Between 0-50% Health - Say Line 0 (Dungeon Only)");

-- Texts for Durnholde Tracking Hound
SET @ENTRY := 17840;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Durnholde Tracking Hound");

-- Durnholde Veteran SAI
SET @ENTRY := 17860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,6000,10000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Veteran - In Combat - Cast 15581 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2000,3000,5000,7000,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Veteran - In Combat - Cast 15582 (Dungeon Only)");

-- Underbog Shambler SAI
SET @ENTRY := 17871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2400,10400,12500,15000,11,32329,0,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Shambler - In Combat - Cast 32329 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2400,10400,12500,15000,11,37965,0,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Shambler - In Combat - Cast 37965 (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,75,25000,30000,11,34163,1,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Shambler - Between 0-75% Health - Cast 34163 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,4,0,75,25000,30000,11,37967,1,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Shambler - Between 0-75% Health - Cast 37967 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,7,1200,8100,0,0,11,31427,1,0,0,0,0,6,0,0,0,0,0,0,0,"Underbog Shambler - In Combat - Cast 31427 (Dungeon Only)");

-- Naturalist Bite SAI
SET @ENTRY := 17893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,7,1,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naturalist Bite - On LOS Out Of Combat - Say Line 0 (Dungeon Only)");

-- Texts for Naturalist Bite
SET @ENTRY := 17893;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hey!  Over here!  Yeah, over here... I'm in this cage!!!",14,0,100,0,0,0,"Naturalist Bite");

-- Coilfang Observer SAI
SET @ENTRY := 17938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9700,16900,7000,11000,11,17883,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Observer - In Combat - Cast 17883 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,9700,16900,7000,11000,11,37668,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Observer - In Combat - Cast 37668 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10900,15600,13000,15900,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Observer - In Combat - Cast 32191 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,10900,15600,13000,15900,11,37666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Observer - In Combat - Cast 37666 (Heroic Dungeon)");

-- Coilfang Technician SAI
SET @ENTRY := 17940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9400,13900,9000,14000,11,16005,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Technician - In Combat - Cast 16005 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,9400,13900,9000,14000,11,39376,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Technician - In Combat - Cast 39376 (Heroic Dungeon)");

-- Coilfang Champion SAI
SET @ENTRY := 17957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,14200,24100,29000,29000,11,19134,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Champion - In Combat - Cast 19134 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,4700,17900,11900,16200,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Champion - In Combat - Cast 15284 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,9500,12900,15100,23500,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Champion - In Combat - Cast 16145 (Dungeon Only)");

-- Coilfang Defender SAI
SET @ENTRY := 17958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Defender - On Respawn - Cast 18950"),
(@ENTRY,0,1,0,0,0,100,6,4900,11900,15500,16700,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Defender - In Combat - Cast 15655 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,10500,13300,13200,13200,11,31554,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Defender - In Combat - Cast 31554 (Dungeon Only)");

-- Coilfang Slavehandler SAI
SET @ENTRY := 17959;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,90,6,60000,120000,360000,420000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavehandler - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,90,6,180000,240000,540000,680000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavehandler - Out Of Combat - Say Line 1 (Dungeon Only)"),
(@ENTRY,0,2,0,4,0,20,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Slavehandler - On Aggro - Say Line 2 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,5800,6200,9000,9000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Slavehandler - In Combat - Cast 9080 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,11100,11100,20000,25000,11,16172,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Slavehandler - In Combat - Cast 16172 (Dungeon Only)");

-- Texts for Coilfang Slavehandler
SET @ENTRY := 17959;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Too soon! You are slacking off too soon!",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,0,1,"Wake up! Now get up and back to work!",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,0,2,"Hurry up with it already! The longer you take, the more of a hurtin' I'm putting on you!",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,1,0,"What is this?! Didn't mommy and daddy teach you anything?",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,1,1,"Get back to work you!",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,1,2,"This is terrible..... my arms grow tired from beating on you lazy peons!",14,0,100,0,0,0,"Coilfang Slavehandler"),
(@ENTRY,2,0,"Assist me slaves!",14,0,100,0,0,0,"Coilfang Slavehandler");

-- Coilfang Collaborator SAI
SET @ENTRY := 17962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9800,13400,16000,20000,11,33787,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Collaborator - In Combat - Cast 33787 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,20100,26200,20000,26000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Collaborator - In Combat - Cast 19130 (Dungeon Only)"),
(@ENTRY,0,2,3,2,0,100,6,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Collaborator - Between 0-30% Health - Cast 8269 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Collaborator - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Coilfang Collaborator
SET @ENTRY := 17962;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Coilfang Collaborator");

-- Wastewalker Worker SAI
SET @ENTRY := 17964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2300,7700,8000,11000,11,13738,32,0,0,0,0,5,0,0,0,0,0,0,0,"Wastewalker Worker - In Combat - Cast 13738 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2300,7700,8000,11000,11,37662,32,0,0,0,0,5,0,0,0,0,0,0,0,"Wastewalker Worker - In Combat - Cast 37662 (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wastewalker Worker - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Voidspawn SAI
SET @ENTRY := 17981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2500,9700,6000,18900,11,36447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Voidspawn - In Combat - Cast 36447"),
(@ENTRY,0,1,0,0,0,100,1,8000,16500,17300,17300,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,"Voidspawn - In Combat - Cast 32026");

-- Enraged Crusher SAI
SET @ENTRY := 18062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,65,0,30000,30000,8000,8000,11,32015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Crusher - In Combat - Cast 32015"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Crusher - Between 0-30% Health - Cast 3019"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Crusher - Between 0-30% Health - Say Line 0");

-- Texts for Enraged Crusher
SET @ENTRY := 18062;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Enraged Crusher");

-- Warmaul Shaman SAI
SET @ENTRY := 18064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,2000,2000,20000,20000,11,15038,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Shaman - In Combat - Cast 15038"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Shaman - Between 0-20% Health - Cast 11986"),
(@ENTRY,0,2,0,0,0,80,0,6000,6000,12000,16000,11,15038,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Shaman - In Combat - Cast 15038");

-- Mawg Grimshot SAI
SET @ENTRY := 18705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,15000,20000,15000,20000,11,33796,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mawg Grimshot - Out Of Combat - Cast 33796"),
(@ENTRY,0,1,0,1,0,100,0,120000,120000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mawg Grimshot - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,1,0,100,0,120000,120000,120000,120000,5,65,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mawg Grimshot - Out Of Combat - Emote Dead"),
(@ENTRY,0,3,0,1,0,100,0,140000,140000,120000,120000,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mawg Grimshot - Out Of Combat - Emote State Stand");

-- Texts for Mawg Grimshot
SET @ENTRY := 18705;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s faints.",16,0,100,0,0,0,"Mawg Grimshot");

-- Umbrafen Oracle SAI
SET @ENTRY := 18077;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - On Aggro - Cast 12550"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - Between 0-50% Health - Cast 11986"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - Between 0-15% Health - Cast 11986");

-- Umbrafen Seer SAI
SET @ENTRY := 18079;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,5000,5000,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umbrafen Seer - In Combat - Cast 9739"),
(@ENTRY,0,1,0,0,0,100,0,500,500,8000,8000,11,31287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umbrafen Seer - In Combat - Cast 31287");

-- Kataru SAI
SET @ENTRY := 18080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32734,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kataru - On Aggro - Cast 32734"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,6000,6000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kataru - In Combat - Cast 12058"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,15869,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kataru - Between 0-50% Health - Cast 15869");

-- Darkcrest Taskmaster SAI
SET @ENTRY := 18086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,4000,7000,11,34811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Taskmaster - In Combat - Cast 34811"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,8000,13000,11,34812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Taskmaster - In Combat - Cast 34812");

-- Bloodscale Slavedriver SAI
SET @ENTRY := 18089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Slavedriver - On Aggro - Cast 32064");

-- Tarren Mill Guardsman SAI
SET @ENTRY := 18092;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Guardsman - On Aggro - Cast 15749 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Guardsman - In Combat - Cast 16856 (Dungeon Only)");

-- Tarren Mill Protector SAI
SET @ENTRY := 18093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,9000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Protector - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,14000,20000,20000,26000,11,32588,1,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Protector - In Combat - Cast 32588 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,11000,20000,17000,22000,11,17234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Protector - In Combat - Cast 17234 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,6,0,50,45000,70000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Protector - Between 0-50% Health - Cast 31976 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,6,3000,9000,15000,20000,11,29380,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Protector - In Combat - Cast 29380 (Dungeon Only)"),
(@ENTRY,0,5,0,14,0,100,6,10000,40,18000,25000,11,17843,1,0,0,0,0,7,0,0,0,0,0,0,0,"Tarren Mill Protector - On Friendly Unit At 10000 Health Within 40 Range - Cast 17843 (Dungeon Only)"),
(@ENTRY,0,6,0,14,0,100,6,12000,40,18000,25000,11,17138,1,0,0,0,0,7,0,0,0,0,0,0,0,"Tarren Mill Protector - On Friendly Unit At 12000 Health Within 40 Range - Cast 17138 (Dungeon Only)");

-- Kialon Nightblade SAI
SET @ENTRY := 18098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,315000,315000,315000,315000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kialon Nightblade - Out Of Combat - Say Line 0");

-- Texts for Kialon Nightblade
SET @ENTRY := 18098;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s examines the information on the wanted poster.",16,0,100,0,0,0,"Kialon Nightblade");

-- Ghaz'an SAI
SET @ENTRY := 18105;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,8000,8300,11,34290,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghaz'an - In Combat - Cast 34290 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,2300,2300,4800,7000,11,34268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghaz'an - In Combat - Cast 34268 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,40,6,2000,4000,6000,8000,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghaz'an - In Combat - Cast 3417 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,2,5900,5900,11700,11700,11,34267,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ghaz'an - In Combat - Cast 34267 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,10000,12000,10000,12000,11,38737,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ghaz'an - In Combat - Cast 38737 (Heroic Dungeon)"),
(@ENTRY,0,5,6,2,0,100,7,0,20,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghaz'an - Between 0-20% Health - Cast 15716 (Dungeon Only)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghaz'an - Between 0-20% Health - Say Line 0 (Dungeon Only)");

-- Texts for Ghaz'an
SET @ENTRY := 18105;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ghaz\'an");

-- Daggerfen Muckdweller SAI
SET @ENTRY := 18115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,10000,10000,11,35201,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerfen Muckdweller - In Combat - Cast 35201");

-- Daggerfen Assassin SAI
SET @ENTRY := 18116;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,10000,10000,11,35204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerfen Assassin - In Combat - Cast 35204");

-- Ango'rosh Ogre SAI
SET @ENTRY := 18117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,4000,4000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Ogre - In Combat - Cast 11978"),
(@ENTRY,0,1,2,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Ogre - Between 0-25% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Ogre - Between 0-25% Health - Say Line 0");

-- Texts for Ango'rosh Ogre
SET @ENTRY := 18117;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ango\'rosh Ogre");

-- Ango'rosh Brute SAI
SET @ENTRY := 18119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,4000,4000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Brute - In Combat - Cast 11428"),
(@ENTRY,0,1,2,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Brute - Between 0-25% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Brute - Between 0-25% Health - Say Line 0");

-- Texts for Ango'rosh Brute
SET @ENTRY := 18119;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ango\'rosh Brute");

-- Ango'rosh Mauler SAI
SET @ENTRY := 18120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,14895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Mauler - Between 0-50% Health - Cast 14895");

-- Wrekt Slave SAI
SET @ENTRY := 18123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,100,100,4000,4000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrekt Slave - In Combat - Cast 11978"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,34789,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrekt Slave - On Aggro - Cast 34789");

-- Withered Giant SAI
SET @ENTRY := 18124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,35235,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Giant - In Combat - Cast 35235");

-- Starving Fungal Giant SAI
SET @ENTRY := 18125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,6000,6000,11,35244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Starving Fungal Giant - In Combat - Cast 35244");

-- Bog Lord SAI
SET @ENTRY := 18127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,6000,6000,11,32077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bog Lord - In Combat - Cast 32077");

-- Sporebat SAI
SET @ENTRY := 18128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,75,1,0,0,0,0,11,35336,7,0,0,0,0,2,0,0,0,0,0,0,0,"Sporebat - On Death - Cast 35336"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,15000,15000,11,35394,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sporebat - In Combat - Cast 35394");

-- Greater Sporebat SAI
SET @ENTRY := 18129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,75,1,0,0,0,0,11,35336,7,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Sporebat - On Death - Cast 35336"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,15000,15000,11,35394,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Sporebat - In Combat - Cast 35394");

-- Marshfang Ripper SAI
SET @ENTRY := 18130;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,3000,3000,9000,9000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshfang Ripper - In Combat - Cast 3604"),
(@ENTRY,0,1,0,0,0,75,0,1000,1000,10000,10000,11,17008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshfang Ripper - In Combat - Cast 17008");

-- Marshfang Slicer SAI
SET @ENTRY := 18131;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,3000,3000,9000,9000,11,35333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshfang Slicer - In Combat - Cast 35333"),
(@ENTRY,0,1,0,0,0,75,0,1000,1000,10000,10000,11,17008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshfang Slicer - In Combat - Cast 17008");

-- Umbraglow Stinger SAI
SET @ENTRY := 18132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,10000,10000,11,35325,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umbraglow Stinger - In Combat - Cast 35325");

-- Marshlight Bleeder SAI
SET @ENTRY := 18133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,15000,11,35329,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshlight Bleeder - In Combat - Cast 35329"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,15000,15000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshlight Bleeder - In Combat - Cast 13443");

-- Fen Strider SAI
SET @ENTRY := 18134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,12000,12000,11,33628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fen Strider - In Combat - Cast 33628");

-- Marsh Walker SAI
SET @ENTRY := 18135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,12000,12000,11,33628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Walker - In Combat - Cast 33628");

-- Marsh Lurker SAI
SET @ENTRY := 18136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,75,0,0,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Lurker - Between 0-75% Health - Cast 9616");

-- Marsh Dredger SAI
SET @ENTRY := 18137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,100,100,12000,12000,11,35234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Dredger - In Combat - Cast 35234");

-- Boss Grog'ak SAI
SET @ENTRY := 18159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,6000,6000,11,35473,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Grog'ak - In Combat - Cast 35473"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,10000,10000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Grog'ak - In Combat - Cast 13730");

-- Overlord Gorefist SAI
SET @ENTRY := 18160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,4000,4000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overlord Gorefist - In Combat - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,4000,4000,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Gorefist - In Combat - Cast 33962");

-- Infinite Slayer SAI
SET @ENTRY := 18170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,7000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Slayer - In Combat - Cast 16856 (Dungeon Only)");

-- Infinite Saboteur SAI
SET @ENTRY := 18172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,9000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Saboteur - In Combat - Cast 15496 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,11000,20000,17000,22000,11,17234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Saboteur - In Combat - Cast 17234 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,6,0,50,45000,70000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Saboteur - Between 0-50% Health - Cast 31976 (Dungeon Only)");

-- Tainted Earthgrab Totem SAI
SET @ENTRY := 18176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tainted Earthgrab Totem - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tainted Earthgrab Totem - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,1000,4000,16000,18000,11,20654,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tainted Earthgrab Totem - In Combat - Cast 20654 (Dungeon Only)");

-- Tainted Stoneskin Totem SAI
SET @ENTRY := 18177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tainted Stoneskin Totem - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tainted Stoneskin Totem - Out Of Combat - Disallow Combat Movement (Dungeon Only)");

-- Corrupted Nova Totem SAI
SET @ENTRY := 18179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Nova Totem - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Nova Totem - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,7,5000,5000,0,0,11,30687,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Nova Totem - In Combat - Cast 30687 (Dungeon Only)"),
(@ENTRY,0,3,0,8,0,100,6,0,127,0,0,11,30687,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Nova Totem - On Spellhit By School 127 - Cast 30687 (Dungeon Only)");

-- Gurok the Usurper SAI
SET @ENTRY := 18182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,12000,12000,11,23114,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gurok the Usurper - In Combat - Cast 23114"),
(@ENTRY,0,1,0,0,0,100,0,20000,20000,25000,25000,11,22127,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gurok the Usurper - In Combat - Cast 22127"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,18000,18000,11,32959,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gurok the Usurper - In Combat - Cast 32959");

-- Wastewalker Captive SAI
SET @ENTRY := 18206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,20,7,1,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Captive - On LOS Out Of Combat - Say Line 0 (Dungeon Only)");

-- Texts for Wastewalker Captive
SET @ENTRY := 18206;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Will the pain ever end?",12,0,100,0,0,0,"Wastewalker Captive"),
(@ENTRY,0,1,"Help me!  Please help me!",12,0,100,0,0,0,"Wastewalker Captive"),
(@ENTRY,0,2,"How can you just leave me here?",12,0,100,0,0,0,"Wastewalker Captive");

-- Tayemba SAI
SET @ENTRY := 18246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,15000,15000,15000,15000,11,32163,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tayemba - Out Of Combat - Cast 32163");

-- Farbosi SAI
SET @ENTRY := 18247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,20000,20000,20000,11,32164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farbosi - Out Of Combat - Cast 32164");

-- Bach'lor SAI
SET @ENTRY := 18258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12200,27000,11200,22900,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bach'lor - In Combat - Cast 32019"),
(@ENTRY,0,1,0,0,0,100,0,5000,17400,20200,28000,11,32020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bach'lor - In Combat - Cast 32020");

-- Banthar SAI
SET @ENTRY := 18259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,9000,9000,8000,8000,11,32021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Banthar - In Combat - Cast 32021"),
(@ENTRY,0,1,0,0,0,85,0,4000,4000,14000,14000,11,32023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Banthar - In Combat - Cast 32023");

-- Boulderfist Invader SAI
SET @ENTRY := 18260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,6000,9000,11,2676,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Invader - In Combat - Cast 2676");

-- Sporewing SAI
SET @ENTRY := 18280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,75,1,0,0,0,0,11,35336,7,0,0,0,0,2,0,0,0,0,0,0,0,"Sporewing - On Death - Cast 35336"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,15000,15000,11,35394,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sporewing - In Combat - Cast 35394");

-- Boglash SAI
SET @ENTRY := 18281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,10000,10000,11,35493,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boglash - In Combat - Cast 35493");

-- Lord Klaq SAI
SET @ENTRY := 18282;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35361,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Klaq - On Aggro - Cast 35361"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,9000,9000,11,8078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Klaq - In Combat - Cast 8078");

-- Blacksting SAI
SET @ENTRY := 18283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,1000,1000,15000,15000,11,35331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blacksting - In Combat - Cast 35331");

-- "Count" Ungula SAI
SET @ENTRY := 18285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,9000,9000,11,35333,0,0,0,0,0,2,0,0,0,0,0,0,0,"'Count' Ungula - In Combat - Cast 35333"),
(@ENTRY,0,1,0,0,0,75,0,1000,1000,10000,10000,11,17008,0,0,0,0,0,2,0,0,0,0,0,0,0,"'Count' Ungula - In Combat - Cast 17008");

-- Bleeding Hollow Refugee SAI
SET @ENTRY := 18292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,60000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Refugee - Out Of Combat - Say Line 0");

-- Sunspring Post Refugee SAI
SET @ENTRY := 18293;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,20000,60000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunspring Post Refugee - Out Of Combat - Say Line 0");

-- Sunspring Post Orphan SAI
SET @ENTRY := 18296;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,10,0,500000,500000,500000,700000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunspring Post Orphan - Out Of Combat - Say Line 0");

-- Texts for Bleeding Hollow Refugee
SET @ENTRY := 18292;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I wanna be just like the pitfighter!",12,0,100,5,0,0,"Bleeding Hollow Refugee"),
(@ENTRY,0,1,"Will he win? Can he win?",12,0,100,5,0,0,"Bleeding Hollow Refugee");

-- Texts for Sunspring Post Refugee
SET @ENTRY := 18293;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"He's so well disciplined!",12,0,100,21,0,0,"Sunspring Post Refugee");

-- Texts for Sunspring Post Orphan
SET @ENTRY := 18296;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"How does he do it?",12,0,100,0,0,0,"Sunspring Post Orphan"),
(@ENTRY,0,1,"I wanna be just like the pitfighter!",12,0,100,0,0,0,"Sunspring Post Orphan"),
(@ENTRY,0,2,"Wow! Look at his muscles!",12,0,100,0,0,0,"Sunspring Post Orphan");

-- Ethereal Crypt Raider SAI
SET @ENTRY := 18311;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,7,8,25,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Crypt Raider - Between 8-25 Range - Cast 22911 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,5800,13300,14000,18000,11,32315,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Crypt Raider - In Combat - Cast 32315 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,5800,8400,25000,40000,11,31403,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - In Combat - Cast 31403 (Dungeon Only)"),
(@ENTRY,0,3,4,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Ethereal Crypt Raider
SET @ENTRY := 18311;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ethereal Crypt Raider");

-- Ethereal Spellbinder SAI
SET @ENTRY := 18312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,15700,18100,0,0,11,32316,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 32316 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,5,15700,18100,0,0,11,32316,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 32316 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,5,15700,18100,0,0,11,32316,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 32316 (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,500,1500,2300,8500,11,17883,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 17883 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,500,1500,2300,8500,11,37668,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 37668 (Heroic Dungeon)"),
(@ENTRY,0,5,0,13,0,100,6,8300,13300,0,0,11,37470,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Spellbinder - On Target Casting - Cast 37470 (Dungeon Only)");

-- Ethereal Priest SAI
SET @ENTRY := 18317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,6400,8400,15400,11,17139,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 17139 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,1000,6400,8400,15400,11,35944,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 35944 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4800,7700,10800,20500,11,34944,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 34944 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4800,7700,10800,20500,11,37669,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 37669 (Heroic Dungeon)"),
(@ENTRY,0,4,0,14,0,100,2,5500,40,25000,30000,11,22883,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Priest - On Friendly Unit At 5500 Health Within 40 Range - Cast 22883 (Normal Dungeon)"),
(@ENTRY,0,5,0,14,0,100,4,9500,40,20000,30000,11,34945,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Priest - On Friendly Unit At 9500 Health Within 40 Range - Cast 34945 (Heroic Dungeon)");

-- Sethekk Ravenguard SAI
SET @ENTRY := 18322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,10000,18000,11,33964,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 33964 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2000,6000,10000,18000,11,40423,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 40423 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,10000,18000,11,32651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - In Combat - Cast 32651 (Dungeon Only)"),
(@ENTRY,0,3,4,14,0,100,3,18000,20,0,0,11,34970,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Friendly Unit At 18000 Health Within 20 Range - Cast 34970 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Friendly Unit At 18000 Health Within 20 Range - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,5,6,14,0,100,5,41000,20,0,0,11,34970,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Friendly Unit At 41000 Health Within 20 Range - Cast 34970 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethekk Ravenguard - On Friendly Unit At 41000 Health Within 20 Range - Say Line 0 (Heroic Dungeon)");

-- Texts for Sethekk Ravenguard
SET @ENTRY := 18322;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sethekk Ravenguard");

-- Rakoria SAI
SET @ENTRY := 18385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,310000,310000,310000,310000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rakoria - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,310200,310200,310200,310200,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rakoria - Out Of Combat - Say Line 1");

-- Texts for Rakoria
SET @ENTRY := 18385;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I never thought it would turn out to be mana oil! There's going to be plenty of demand for that, minus Grek of course!",12,0,100,0,0,0,"Rakoria"),
(@ENTRY,1,0,"Ship it!",12,0,100,5,0,0,"Rakoria");

-- Warp Stalker SAI
SET @ENTRY := 18464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Stalker - On Respawn - Cast 32942"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Stalker - On Aggro - Cast 32939"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,28,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Stalker - On Aggro - Remove Aura 32942"),
(@ENTRY,0,3,0,0,0,100,0,2000,2000,16000,21000,11,32920,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warp Stalker - In Combat - Cast 32920"),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,10000,20000,11,32922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warp Stalker - In Combat - Cast 32922"),
(@ENTRY,0,5,0,7,0,100,1,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Stalker - On Evade - Cast 32942");

-- Warp Hunter SAI
SET @ENTRY := 18465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Hunter - On Respawn - Cast 32942"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Hunter - On Aggro - Cast 32939"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,28,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Hunter - On Aggro - Remove Aura 32942"),
(@ENTRY,0,3,0,0,0,100,0,2000,2000,16000,21000,11,32920,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warp Hunter - In Combat - Cast 32920"),
(@ENTRY,0,4,0,9,0,100,1,0,5,0,0,11,39449,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warp Hunter - Between 0-5 Range - Cast 39449"),
(@ENTRY,0,5,0,7,0,100,1,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Hunter - On Evade - Cast 32942");

-- Unliving Cleric SAI
SET @ENTRY := 18500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,2000,20,7000,8000,11,33324,1,0,0,0,0,7,0,0,0,0,0,0,0,"Unliving Cleric - On Friendly Unit At 2000 Health Within 20 Range - Cast 33324 (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,4,6000,20,7000,8000,11,22883,1,0,0,0,0,7,0,0,0,0,0,0,0,"Unliving Cleric - On Friendly Unit At 6000 Health Within 20 Range - Cast 22883 (Heroic Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,1000,20,4000,6000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unliving Cleric - On Friendly Unit At 1000 Health Within 20 Range - Cast 25058 (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,4,2000,20,4000,6000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unliving Cleric - On Friendly Unit At 2000 Health Within 20 Range - Cast 38210 (Heroic Dungeon)"),
(@ENTRY,0,4,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Cleric - On Evade - Forced Despawn (Dungeon Only)");

-- Cabal Acolyte SAI
SET @ENTRY := 18633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,3600000,3600000,11,33482,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Acolyte - Out Of Combat - Cast 33482 (Dungeon Only)"),
(@ENTRY,0,1,0,14,0,100,2,9000,20,5000,9000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Acolyte - On Friendly Unit At 9000 Health Within 20 Range - Cast 12039 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,4,15000,20,5000,9000,11,38209,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Acolyte - On Friendly Unit At 15000 Health Within 20 Range - Cast 38209 (Heroic Dungeon)"),
(@ENTRY,0,3,0,14,0,100,2,4000,20,12000,15000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Acolyte - On Friendly Unit At 4000 Health Within 20 Range - Cast 25058 (Normal Dungeon)"),
(@ENTRY,0,4,0,14,0,100,4,7000,20,12000,15000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Acolyte - On Friendly Unit At 7000 Health Within 20 Range - Cast 38210 (Heroic Dungeon)");

-- Cabal Deathsworn SAI
SET @ENTRY := 18635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,10000,12000,15000,11,33480,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 33480 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,8000,10000,12000,15000,11,38226,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 38226 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,10000,12000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 11428 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Deathsworn - Between 0-30% Health - Cast 8599 (Dungeon Only)");

-- Cabal Shadow Priest SAI
SET @ENTRY := 18637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,11,16592,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Shadow Priest - Out Of Combat - Cast 16592 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,1000,2000,12000,15000,11,17165,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 17165 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,1000,2000,12000,15000,11,38243,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 38243 (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,5000,7000,10000,15000,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 14032 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,5000,7000,10000,15000,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 17146 (Heroic Dungeon)");

-- Fel Guardhound SAI
SET @ENTRY := 18642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4800,14500,12100,18100,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Guardhound - In Combat - Cast 30849 (Dungeon Only)");

-- Deathskitter SAI
SET @ENTRY := 18647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,11000,11,32902,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deathskitter - In Combat - Cast 32902");

-- Stonegazer SAI
SET @ENTRY := 18648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,45000,50000,11,32905,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonegazer - In Combat - Cast 32905");

-- Maiden of Discipline SAI
SET @ENTRY := 18663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4000,8000,10000,11,32202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maiden of Discipline - In Combat - Cast 32202 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,5000,8000,12000,18000,11,31865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maiden of Discipline - In Combat - Cast 31865 (Dungeon Only)");

-- Aged Dalaran Wizard SAI
SET @ENTRY := 18664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aged Dalaran Wizard - Out Of Combat - Cast 12544 (Dungeon Only)");

-- Ironjaw SAI
SET @ENTRY := 18670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,30000,35000,11,32918,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw - In Combat - Cast 32918"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,4000,6000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw - In Combat - Cast 32919"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,9000,11000,11,32962,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw - In Combat - Cast 32962");

-- Ever-Core the Punisher SAI
SET @ENTRY := 18698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ever-Core the Punisher - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,18000,22000,11,35892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ever-Core the Punisher - In Combat - Cast 35892"),
(@ENTRY,0,2,0,9,0,100,0,0,8,19000,23000,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ever-Core the Punisher - Between 0-8 Range - Cast 33860");

-- Texts for Ever-Core the Punisher
SET @ENTRY := 18698;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Intruder detected! Neutralizing threat immediately!",12,0,100,0,0,0,"Ever-Core the Punisher");

-- Reanimated Bones SAI
SET @ENTRY := 18700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,7000,8000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Bones - In Combat - Cast 13584 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1000,4000,9000,12000,11,13444,1,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Bones - In Combat - Cast 13444 (Dungeon Only)");

-- Auchenai Necromancer SAI
SET @ENTRY := 18702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,10000,12000,11,35839,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 35839 (Dungeon Only)"),
(@ENTRY,0,1,0,14,0,100,2,4000,15,6000,8000,11,33325,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Unit At 4000 Health Within 15 Range - Cast 33325 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,4,7000,15,6000,8000,11,37367,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Necromancer - On Friendly Unit At 7000 Health Within 15 Range - Cast 37367 (Heroic Dungeon)");

-- Shadowy Hunter SAI
SET @ENTRY := 18718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,4000,7000,11,32915,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowy Hunter - In Combat - Cast 32915"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,8000,13000,11,32908,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowy Hunter - In Combat - Cast 32908");

-- Shadowmaster Grieve SAI
SET @ENTRY := 18720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,6000,9000,11,32916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Grieve - In Combat - Cast 32916"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,9000,11000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Grieve - In Combat - Cast 32736");

-- Fel Overseer SAI
SET @ENTRY := 18796;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - On Aggro - Cast 27577 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,30000,30000,30000,30000,11,19134,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 19134 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,12000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 16856 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,9000,12000,9000,16000,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 30471 (Dungeon Only)");

-- Cabal Fanatic SAI
SET @ENTRY := 18830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,12000,18000,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Fanatic - In Combat - Cast 12021 (Dungeon Only)");

-- Malicious Instructor SAI
SET @ENTRY := 18848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,10000,10000,20000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 6713 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,7,8000,12000,0,0,11,33493,0,0,0,0,0,2,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 33493 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,12000,15000,11,33501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 33501 (Dungeon Only)");

-- Sunfury Guardsman SAI
SET @ENTRY := 18850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,13700,33400,183000,183000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Guardsman - In Combat - Cast 27577"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Guardsman - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Guardsman - Between 0-30% Health - Say Line 0");

-- Texts for Sunfury Guardsman
SET @ENTRY := 18850;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sunfury Guardsman");

-- Sunfury Warp-Engineer SAI
SET @ENTRY := 18852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,3100,5800,0,0,11,35919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Warp-Engineer - In Combat - Cast 35919");

-- Sunfury Bloodwarder SAI
SET @ENTRY := 18853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,13700,33400,183000,183000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Bloodwarder - In Combat - Cast 27577"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bloodwarder - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bloodwarder - Between 0-30% Health - Say Line 0");

-- Texts for Sunfury Bloodwarder
SET @ENTRY := 18853;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sunfury Bloodwarder");
