-- Runed Giant SAI
SET @ENTRY := 26417;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,47329,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runed Giant - On Spawn - Cast Runic Compulsion"),
(@ENTRY,0,1,0,8,0,25,0,47604,0,10000,10000,80,2641700,2,2,0,0,0,1,0,0,0,0,0,0,0,"Runed Giant - On Spell Hit - Start Script for Free At Last");

-- Inquisitor Salrand SAI
SET @ENTRY := 25584;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Salrand - On Data 1 1 - Say 0"),
(@ENTRY,0,1,2,38,0,100,1,1,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Salrand - On Data 1 2 - Say 1"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,80,2558400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Salrand - On Data 1 2 - Run script"),
(@ENTRY,0,3,4,6,0,100,1,0,0,0,0,11,45809,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Salrand - On Death - Cast Summon Salrand's Lockbox"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Salrand - On Death - Say 2"),
(@ENTRY,0,5,0,11,0,100,0,0,0,0,0,11,45775,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runed Giant - On Spawn - Cast Cosmetic - Divine Shield Blue");

-- Image of Drakuru SAI
SET @ENTRY := 26543;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12042,0,0,0,11,47308,0,0,0,0,0,7,0,0,0,0,0,0,0,"Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 02"),
(@ENTRY,0,1,2,11,0,100,0,0,0,0,0,11,43167,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Spawn - Cast Spirit Particles (green)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,47119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Spawn - Cast Drakuru (Quest Invis)");

-- Image of Drakuru SAI
SET @ENTRY := 26787;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,12238,0,0,0,11,48417,0,0,0,0,0,7,0,0,0,0,0,0,0,"Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 04"),
(@ENTRY,0,1,2,11,0,100,0,0,0,0,0,11,43167,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Spawn - Cast Spirit Particles (green)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,47119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Spawn - Cast Drakuru (Quest Invis)");

-- Fix frenzy for Kvaldir Berserker
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=34947 AND `id`=2;

-- Scarlet Infantryman SAI
SET @ENTRY := 28609;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Infantryman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Infantryman - At 0 - 5 Range - Cast Heroic Strike"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,16000,19000,11,53399,1,1,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Infantryman - In Combat - Cast Sweeping Slam"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,11,48356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Infantryman - On Spawn - Cast See Wintergarde Invisibility");

-- Kvaldir Mist Binder SAI
SET @ENTRY := 34839;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,45658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Binder - On Spawn - Cast Call of the Mist "),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,12000,17000,11,49816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kvaldir Mist Binder - In Combat - Cast Mist of Strangulation");

-- Scarlet Commander SAI
SET @ENTRY := 28936;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,2404, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,0,2300,3900,11,52818,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Commander - In Combat CMC - Cast Shoot"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Commander - Between 0-5 Range - Cast Heroic Strike"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - On Evade - Set Sheath Melee"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,11,48356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - On Spawn - Cast See Wintergarde Invisibility");

-- Scarlet Peasant SAI
SET @ENTRY := 28557;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,1,234, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Peasant - At 0-20% hp - Say text"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,11,48356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Peasant - On Spawn - Cast See Wintergarde Invisibility");

-- Scarlet Captain SAI
SET @ENTRY := 28611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,2404, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,0,2300,3900,11,52818,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Captain - In Combat CMC - Cast Shoot"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Captain - Between 0-5 Range - Cast Heroic Strike"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Captain - On Evade - Set Sheath Melee"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,11,48356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Captain - On Spawn - Cast See Wintergarde Invisibility");

-- Firemane Flamecaller SAI
SET @ENTRY := 4334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3400,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat CMC - Cast Fireball"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,600000,600000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast Fire Shield"),
(@ENTRY,0,2,0,0,0,100,0,9000,16000,30000,45000,11,11990,1,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast Rain of Fire");

-- Plague Eruptor SAI
SET @ENTRY := 27611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,65536,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,28000,38000,11,49350,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plague Eruptor - In Combat - Cast Plague Cloud");

-- Fordragon High Priest SAI
SET @ENTRY := 27677;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon High Priest - In Combat CMC - Cast Holy Smite"),
(@ENTRY,0,1,0,0,0,100,0,18000,25000,40000,53000,11,32595,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,15000,23000,11,49306,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - In Combat - Cast Circle of Healing"),
(@ENTRY,0,3,0,14,0,100,0,3000,40,17000,21000,11,25058,1,0,0,0,0,7,0,0,0,0,0,0,0,"Fordragon High Priest - On Friendly Unit At 3000 Health Within 40 Range - Cast Renew"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,11,49348,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-15% Health - Cast Greater Heal");

-- Angrathar Aberration SAI
SET @ENTRY := 27631;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,65536,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,31540,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Aberration - HP@30% - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Aberration - HP@30% - Say 0");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'Angrathar Aberration on enrage');

-- Scarlet Medic SAI
SET @ENTRY := 28608;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,48356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - On Spawn - Cast See Wintergarde Invisibility"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Out Of Combat - Cast Power Word: Fortitude"),
(@ENTRY,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Say Line 0"),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4800,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Medic - In Combat CMC - Cast Holy Smite"),
(@ENTRY,0,4,0,2,0,100,1,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - Between 0-15% Health - Flee For Assist");

-- Bloodspore Firestarter SAI
SET @ENTRY := 25470;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,45985,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Out Of Combat - Cast Flaming Touch"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3800,6200,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodspore Firestarter - In Combat CMC - Cast Fireball");

-- Citizen of New Avalon SAI
SET @ENTRY := 28941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,52716,2,0,0,0,0,1,0,0,0,0,0,0,0,"Citizen of New Avalon - On Aggro - Cast fear");
