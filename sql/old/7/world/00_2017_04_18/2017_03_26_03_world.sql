-- Shao-Tien Fist SAI
SET @ENTRY := 65134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,14000,14000,14000,14000,11,126908,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shao-Tien Fist - In Combat - Cast 'Molten Fists'");

-- Molten Fists SAI
SET @ENTRY := 64913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,126909,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molten Fists - On Respawn - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,18,34079620,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molten Fists - On Respawn - Set Flags Disable Movement & Not Attackable & Immune To Players & Immune To NPC's & In Combat & Not Selectable");

-- Manifestation of Pride SAI
SET @ENTRY := 72280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,5000,5000,11,128099,64,0,0,0,0,2,0,0,0,0,0,0,0,"Manifestation of Pride - In Combat - Cast 'Sha Corruption'");

-- Vestige of Pride SAI
SET @ENTRY := 72279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,15000,15000,11,145053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vestige of Pride - In Combat - Cast 'Consuming Pride'");

-- Sahn Tidehunter SAI
SET @ENTRY := 50780;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,6000,11,124854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sahn Tidehunter - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,0,0,11,124860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sahn Tidehunter - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,2,0,0,0,100,0,18000,18000,18000,18000,11,124935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sahn Tidehunter - In Combat - Cast 'Torrent'");

-- Ancient Mogu Spirit SAI
SET @ENTRY := 58671;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,14000,14000,14000,14000,11,126350,0,0,0,0,0,9,58669,0,20,0,0,0,0,"Ancient Mogu Spirit - On Respawn - Cast 'Electrocute' On Echo of a Pandaren"),
(@ENTRY,0,1,0,0,0,100,0,13000,13000,13000,13000,11,126356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Mogu Spirit - In Combat - Cast 'Crushing Blow'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,15000,15000,11,126350,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Mogu Spirit - In Combat - Cast 'Electrocute'");

-- Echo of a Pandaren Monk SAI
SET @ENTRY := 58669;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,14000,14000,11,126460,0,0,0,0,0,9,56671,0,20,0,0,0,0,"Echo of a Pandaren Monk - On Respawn - Cast 'Pandaren Uprising'");

-- Aspiring Trainee SAI
SET @ENTRY := 67004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,6000,6000,5,509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Emote 509"),
(@ENTRY,0,1,0,1,0,100,0,3000,3000,6000,6000,5,507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Emote 507"),
(@ENTRY,0,2,0,1,0,100,0,0,0,0,0,17,510,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Set Emote State 510");

-- Aspiring Trainee SAI
SET @ENTRY := 58731;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,6000,6000,5,507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Emote 507"),
(@ENTRY,0,1,0,1,0,100,0,3000,3000,6000,6000,5,509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Emote 509"),
(@ENTRY,0,2,0,1,0,100,0,0,0,0,0,17,510,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Set Emote State 510");

-- Krik'thik Locust-Guard SAI
SET @ENTRY := 63974;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,12000,12000,11,126426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krik'thik Locust-Guard - In Combat - Cast 'Wind Slash'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,12000,12000,11,126437,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krik'thik Locust-Guard - In Combat - Cast 'Corrosive Gas'");

-- Kal'tik the Blight SAI
SET @ENTRY := 50749;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,18,524288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kal'tik the Blight - Out of Combat - Set Flag In Combat"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,20000,20000,11,125370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kal'tik the Blight - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,12000,12000,11,125373,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kal'tik the Blight - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,15000,15000,11,125398,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kal'tik the Blight - In Combat - Cast 'Tornado'");

-- Tornado SAI
SET @ENTRY := 64267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,0,0,18,33555328,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tornado - In Combat - Set Flags Not Attackable & Immune To Players & Immune To NPC's & Not Selectable"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3000,11,127987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tornado - In Combat - Cast 'Tornado");

-- Riverblade Bloodletter SAI
SET @ENTRY := 58987;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,6000,6000,11,126913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverblade Bloodletter - In Combat - Cast 'Thunder's Call'");

-- Shao-Tien Antiquator SAI
SET @ENTRY := 58928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,15000,11,127463,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shao-Tien Antiquator - In Combat - Cast 'Icy Destruction'"),
(@ENTRY,0,1,0,0,0,100,0,13000,13000,9000,9000,11,127466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shao-Tien Antiquator - In Combat - Cast 'Ancient Magic'");

-- Shao-Tien Sorcerer SAI
SET @ENTRY := 65133;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,4000,4000,11,127552,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shao-Tien Sorcerer - In Combat - Cast 'Lightning Crash'");

-- Shao-Tien Soul-Caller SAI
SET @ENTRY := 63611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,0,0,11,126209,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shao-Tien Soul-Caller - In Combat - Cast 'Shadow Strikes'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,5000,5000,11,126202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shao-Tien Soul-Caller - In Combat - Cast 'Rend Soul'");

-- Gaohun the Soul-Severer SAI
SET @ENTRY := 62881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1000,1000,11,126420,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gaohun the Soul-Severer - In Combat - Cast 'Spirits of the Damned'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,10000,10000,11,126390,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gaohun the Soul-Severer - In Combat - Cast 'Rend Soul'"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,10000,11,126466,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gaohun the Soul-Severer - In Combat - Cast 'Spirit Cage'");

-- Echo of a Pandaren Monk SAI
SET @ENTRY := 58669;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,14000,14000,11,126460,0,0,0,0,0,9,56671,0,20,0,0,0,0,"Echo of a Pandaren Monk - On Respawn - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,14000,14000,11,126367,0,0,0,0,0,9,0,0,0,0,0,0,0,"Echo of a Pandaren Monk - In Combat - Cast 'Thousand Blows'");

-- Spirit of Lao-Fe SAI
SET @ENTRY := 58817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,20000,20000,20000,20000,11,126471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Lao-Fe - In Combat - Cast 'Oppress the Weak'");

-- Cracklefang SAI
SET @ENTRY := 58768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,6000,6000,11,126032,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cracklefang - In Combat - Cast 'Devastating Arc'");


-- Moldo One-Eye SAI
SET @ENTRY := 50806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,10000,10000,11,125624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moldo One-Eye - In Combat - Cast 'Vicious Rend'"),
(@ENTRY,0,1,0,0,0,100,0,23000,23000,23000,23000,11,125623,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moldo One-Eye - In Combat - Cast 'Grappling Hook'"),
(@ENTRY,0,2,0,0,0,100,0,20000,20000,20000,20000,11,125632,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moldo One-Eye - In Combat - Cast 'Vanish'"),
(@ENTRY,0,3,0,0,0,100,0,20500,20500,20500,20500,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moldo One-Eye - In Combat - Start Random Movement");


-- Vicejaw SAI
SET @ENTRY := 58769;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1000,1000,11,126104,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicejaw - In Combat - Cast 'Chomp'"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,126126,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vicejaw - In Combat - Cast 'Upchuck'"),
(@ENTRY,0,2,0,2,0,100,0,20,0,5000,5000,11,126187,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vicejaw - Between 20-0% Health - Cast 'Vice Jaws'");


-- Shadowmaster Sydow SAI
SET @ENTRY := 63240;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,123559,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowmaster Sydow - On Respawn - Cast 'Spirit Harvest'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3000,11,126283,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Sydow - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,9000,9000,11,126347,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Sydow - In Combat - Cast 'Shadow Fissure'"),
(@ENTRY,0,3,0,1,0,100,0,0,0,0,0,11,123559,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmaster Sydow - Out of Combat - Cast 'Spirit Harvest'"),
(@ENTRY,0,4,0,0,0,100,0,15000,15000,30000,30000,11,126299,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Sydow - In Combat - Cast 'Unleash Souls'"),
(@ENTRY,0,5,0,0,0,100,0,3000,3000,3000,3000,11,126274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmaster Sydow - In Combat - Cast 'Crackling Shadows'");
