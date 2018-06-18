-- Deathwhisperer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19299;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19299 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19299,0,0,0,25,0,100,0,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathwhisperer - On Reset - Cast 'Thrash'"),
(19299,0,1,0,25,0,100,0,0,0,0,0,0,11,15088,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathwhisperer - On Reset - Cast 'Flurry'"),
(19299,0,2,0,0,0,100,0,4000,6000,12000,16000,0,11,32417,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathwhisperer - In Combat - Cast 'Mind Flay'");

-- Dread Tactician
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16959;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16959 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16959,0,0,0,0,0,100,0,5000,8000,15000,20000,0,11,33678,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Tactician - In Combat - Cast 'Carrion Swarm'"),
(16959,0,1,0,0,0,100,0,8000,11000,24000,29000,0,11,12098,0,0,0,0,0,6,0,0,0,0,0,0,0,"Dread Tactician - In Combat - Cast 'Sleep'"),
(16959,0,2,0,2,0,100,1,0,30,0,0,0,11,33679,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dread Tactician - Between 0-30% Health - Cast 'Inferno' (No Repeat)");

-- Felguard Destroyer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18977;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18977 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18977,0,0,0,9,0,100,1,8,40,0,0,0,11,33971,2,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Destroyer - Within 8-40 Range - Cast 'Sweeping Charge' (No Reapeat)"),
(18977,0,1,0,0,0,100,0,7000,9000,11000,15000,0,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Destroyer - In Combat - Cast 'Mortal Strike'"),
(18977,0,2,0,0,0,100,0,3000,5000,7000,11000,0,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Destroyer - In Combat - Cast 'Cleave'");

-- Subjugator Yalqiz
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19335;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19335 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19335,0,0,0,0,0,100,0,6000,8000,12000,15000,0,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Subjugator Yalqiz - In Combat - Cast 'Mind Sear'"),
(19335,0,1,0,0,0,100,0,3000,5000,9000,11000,0,11,32026,2,0,0,0,0,2,0,0,0,0,0,0,0,"Subjugator Yalqiz - In Combat - Cast 'Pain Spike'");

-- Vorakem Doomspeaker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18679;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18679 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18679,0,0,0,0,0,100,0,5000,7000,11000,14000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vorakem Doomspeaker - In Combat - Cast 'Hamstring'"),
(18679,0,1,0,0,0,100,0,7000,9000,12000,15000,0,11,33804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vorakem Doomspeaker - In Combat - Cast 'Flame Wave'"),
(18679,0,2,0,2,0,100,1,0,20,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vorakem Doomspeaker - Between 0-20% Health - Cast Enrage (No Repeat)"),
(18679,0,3,0,2,0,100,1,0,20,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vorakem Doomspeaker - Between 0-20% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=18679;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18679,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Vorakem Doomspeaker");

-- Flame Wave
UPDATE `creature_template` SET `faction`=90, `AIName`="SmartAI" WHERE `entry`=19381;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19381 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19381,0,0,0,11,0,100,0,0,0,0,0,0,11,33800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flame Wave - On Respawn - Cast 'Flame Wave'");

-- Bonechewer Scavenger
DELETE FROM `creature_text` WHERE `CreatureID` IN (18952) AND `GroupID`=0 AND `ID` IN (1,2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18952,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bonechewer Scavenger"),
(18952,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bonechewer Scavenger"),
(18952,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bonechewer Scavenger");

-- Bonechewer Evoker
DELETE FROM `smart_scripts` WHERE `entryorguid`=19701 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19701,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - On Aggro - Say Line 0"),
(19701,0,1,0,0,0,100,0,0,0,3000,5000,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Evoker - In Combat - Cast 'Fireball'"),
(19701,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=19701;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19701,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bonechewer Evoker"),
(19701,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bonechewer Evoker"),
(19701,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bonechewer Evoker"),
(19701,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bonechewer Evoker");

-- Starving Helboar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16879;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16879 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16879,0,0,0,25,0,100,0,0,0,0,0,0,11,33908,0,0,0,0,0,1,0,0,0,0,0,0,0,"Starving Helboar - On Reset - Cast 'Burning Spikes'");

-- Infernal Warbringer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19261;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19261 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19261,0,0,0,25,0,100,0,0,0,0,0,0,11,19483,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infernal Warbringer - On Reset - Cast 'Immolation'");

-- Dreadcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=19434 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19434,0,0,0,0,0,100,0,0,0,2000,4000,0,11,32666,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - In Combat - Cast 'Shadow Bolt'"),
(19434,0,1,0,0,0,100,0,4000,9000,18000,24000,0,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - In Combat - Cast 'Cripple'");

-- Bleeding Hollow Peon
DELETE FROM `smart_scripts` WHERE `entryorguid`=16907 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16907,0,2,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Peon - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=16907;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16907,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bleeding Hollow Peon"),
(16907,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bleeding Hollow Peon"),
(16907,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bleeding Hollow Peon"),
(16907,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bleeding Hollow Peon");

-- Bleeding Hollow Grunt
DELETE FROM `smart_scripts` WHERE `entryorguid`=16871 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16871,0,3,0,4,0,20,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Grunt - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=16871 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16871,1,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bleeding Hollow Grunt"),
(16871,1,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bleeding Hollow Grunt"),
(16871,1,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bleeding Hollow Grunt"),
(16871,1,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bleeding Hollow Grunt");

-- Bleeding Hollow Necrolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=19422 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19422,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Aggro - Say Line 0"),
(19422,0,1,0,0,0,100,0,0,0,3000,5000,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - In Combat - Cast 'Fireball'"),
(19422,0,2,0,0,0,100,0,8000,12000,30000,45000,0,11,34073,32,0,0,0,0,5,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - In Combat - Cast 'Curse of the Bleeding Hollow'"),
(19422,0,3,0,5,0,100,0,0,0,0,0,0,11,34019,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Killed Unit - Cast 'Raise Dead'"),
(19422,0,4,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Health - Flee For Assist (No Repeat)"),
(19422,0,5,0,8,0,100,1,38530,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Spellhit - Start Attack");

DELETE FROM `creature_text` WHERE `CreatureID`=19422;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19422,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bleeding Hollow Necrolyte"),
(19422,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bleeding Hollow Necrolyte"),
(19422,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bleeding Hollow Necrolyte"),
(19422,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bleeding Hollow Necrolyte");

-- Bleeding Hollow Dark Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=16873 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16873,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Say Line 0"),
(16873,0,1,0,0,0,100,0,0,0,3000,5000,0,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - In Combat - Cast 'Shadow Bolt'"),
(16873,0,2,0,0,0,100,0,4000,8000,30000,45000,0,11,32062,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - In Combat - Cast 'Fire Nova Totem'"),
(16873,0,3,0,5,0,100,0,0,0,0,0,0,11,34013,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Killed Unit - Cast 'Raise Soul'"),
(16873,0,4,0,2,0,100,1,0,30,0,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)"),
(16873,0,5,0,23,0,100,0,12550,0,1000,1000,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Has No Aura 'Lightning Shield' - Cast 'Lightning Shield'"),
(16873,0,6,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(16873,0,7,0,8,0,100,1,38530,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Spellhit - Start Attack");

DELETE FROM `creature_text` WHERE `CreatureID`=16873;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16873,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bleeding Hollow Dark Shaman"),
(16873,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bleeding Hollow Dark Shaman"),
(16873,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bleeding Hollow Dark Shaman"),
(16873,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bleeding Hollow Dark Shaman");

-- Bleeding Hollow Tormentor
DELETE FROM `smart_scripts` WHERE `entryorguid`=19424 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19424,0,5,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Tormentor - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=19424;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19424,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bleeding Hollow Tormentor"),
(19424,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bleeding Hollow Tormentor"),
(19424,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bleeding Hollow Tormentor"),
(19424,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bleeding Hollow Tormentor");

-- Mekthorg the Wild
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18677;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18677 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18677,0,0,0,0,0,100,0,6000,8000,11000,13000,0,11,38875,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mekthorg the Wild - In Combat - Cast 'Pike Vault'"),
(18677,0,1,0,9,0,100,0,0,5,11000,14000,0,11,37704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mekthorg the Wild - Within 0-5 Range - Cast 'Whirlwind'"),
(18677,0,2,0,2,0,100,1,0,20,0,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mekthorg the Wild - Between 0-20% Health - Cast 'Enrage' (No Repeat)"),
(18677,0,3,0,2,0,100,1,0,20,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mekthorg the Wild - Between 0-20% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=18677;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18677,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Mekthorg the Wild");

-- Unyielding Knight
DELETE FROM `smart_scripts` WHERE `entryorguid`=16906 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16906,0,2,0,14,0,100,0,1600,40,20000,25000,0,11,33910,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unyielding Knight - Friendly At 1600 Health - Cast 'Heal Other'");

-- Arch Mage Xintor
DELETE FROM `smart_scripts` WHERE `entryorguid`=16977 AND `source_type`=0 AND `id`=15;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16977,0,15,0,25,0,100,1,0,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Mage Xintor - On Respawn - Cast 'Shroud of Death'");

-- Rogue Voidwalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=16974 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16974,0,1,0,6,0,100,0,0,0,0,0,0,11,34234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rogue Voidwalker - On Just Died - Cast 'Collapse'");

-- Uncontrolled Voidwalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=16975 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16975,0,1,0,2,0,100,1,0,50,0,0,0,11,33916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uncontrolled Voidwalker - Between 0-50% Health - Cast 'Void Drain'"),
(16975,0,2,0,6,0,100,0,0,0,0,0,0,11,34234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uncontrolled Voidwalker - On Just Died - Cast 'Collapse'");

-- Void Spawner L
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19681;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19681 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19681,0,0,0,1,0,100,0,1000,120000,120000,240000,0,11,34303,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Spawner L - Out of Combat - Cast 'Nether Charge'");

UPDATE `creature_addon` SET `auras`="" WHERE `auras`="34303";

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=34303;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,34303,0,0,32,0,144,0,0,1,0,0,"","Nether Charge cannot target players");

-- Warboss Nekrogg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19263;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19263 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19263,0,0,0,0,0,100,0,5000,7000,12000,16000,0,11,34113,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warboss Nekrogg - In Combat - Cast 'Bonechewer Bite'"),
(19263,0,1,0,0,0,100,0,10000,12000,25000,30000,0,11,30474,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warboss Nekrogg - In Combat - Cast 'Bloodthirst'");

-- Shattered Hand Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`=19414 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19414,0,1,0,0,0,100,0,6000,9000,13000,16000,0,11,33960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Guard - In Combat - Cast 'Counterstrike'");

-- Z'kral
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18974;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18974 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18974,0,0,0,0,0,100,0,5000,8000,9000,12000,0,11,32003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Z'kral - In Combat - Cast 'Power Burn'");

-- Explosive Charge
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=183410;
DELETE FROM `smart_scripts` WHERE `entryorguid`=183410 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(183410,1,0,0,1,0,100,1,10000,10000,0,0,9,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Explosive Charge - Out of Combat - Activate Gameobject");

-- Bonechewer Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=16925 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16925,0,1,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Raider - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=16925;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16925,0,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bonechewer Raider"),
(16925,0,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bonechewer Raider"),
(16925,0,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bonechewer Raider"),
(16925,0,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bonechewer Raider");

-- Bonechewer Mutant
DELETE FROM `smart_scripts` WHERE `entryorguid`=16876 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16876,0,5,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Mutant - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=16876 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16876,2,0,"Death to the interlopers!",12,0,100,0,0,0,12837,0,"Bonechewer Mutant"),
(16876,2,1,"For Spinebreaker!",12,0,100,0,0,0,12838,0,"Bonechewer Mutant"),
(16876,2,2,"Your bones will be devoured!",12,0,100,0,0,0,12839,0,"Bonechewer Mutant"),
(16876,2,3,"Protect the Warchief at all costs!",12,0,100,0,0,0,12836,0,"Bonechewer Mutant");

-- Shattered Hand Grunt
DELETE FROM `smart_scripts` WHERE `entryorguid`=16867 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16867,0,0,0,0,0,100,0,5000,7000,8000,9000,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grunt - In Combat - Cast 'Strike'"),
(16867,0,1,0,0,0,100,0,7000,9000,12000,14000,0,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grunt - In Combat - Cast 'Kick'");

-- Shattered Hand Captain
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=8000, `event_param3`=8000, `event_param4`=12000 WHERE `entryorguid`=16870 AND `source_type`=0 AND `id`=0;

-- Shattered Hand Warlock
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=19411 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=19411 AND `source_type`=0 AND `id`=2;

-- Mo'arg Forgefiend
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16946;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16946 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16946,0,0,0,0,0,100,0,0,0,2000,4000,0,11,32735,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'arg Forgefiend - In Combat - Cast 'Saw Blade'"),
(16946,0,1,0,9,0,100,0,0,5,15000,19000,0,11,36486,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'arg Forgefiend - Within 0-5 Range - Cast 'Slime Spray'");

-- Gan'arg Servant
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16947;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16947 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16947,0,0,0,0,0,100,0,5000,8000,12000,15000,0,11,32003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Servant - In Combat - Cast 'Power Burn'");

-- Incandescent Fel Spark
DELETE FROM `smart_scripts` WHERE `entryorguid`=22323 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22323,0,0,0,0,0,100,0,1000,2000,3000,5000,0,11,36247,64,0,0,0,0,2,0,0,0,0,0,0,0,"Incandescent Fel Spark - In Combat - Cast 'Fel Fireball'"),
(22323,0,2,0,0,0,100,0,8000,11000,18000,24000,0,11,39055,0,0,0,0,0,1,0,0,0,0,0,0,0,"Incandescent Fel Spark - In Combat - Cast 'Flames of Chaos'");

-- Fel Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18733;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18733 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18733,0,0,0,0,0,100,0,9000,12000,18000,25000,0,11,41534,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Reaver - In Combat - Cast 'War Stomp'"),
(18733,0,1,0,25,0,100,0,0,0,0,0,0,11,19818,0,0,0,0,0,1,0,0,0,0,0,0,0,"War Stomp - On Respawn - Cast 'Double Attack'"),
(18733,0,2,0,25,0,100,0,0,0,0,0,0,11,34623,0,0,0,0,0,1,0,0,0,0,0,0,0,"War Stomp - On Respawn - Cast 'Fel Reaver Warning Aura'"),
(18733,0,3,0,25,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"War Stomp - On Respawn - Set Active On");

-- Arazzius the Cruel
DELETE FROM `smart_scripts` WHERE `entryorguid`=19191 AND `source_type`=0 AND `id` IN (6,7,8);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19191,0,6,0,2,0,100,1,50,75,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arazzius the Cruel - Between 50-75% Health - Say Line 2 (No Repeat)"),
(19191,0,7,0,2,0,100,1,25,50,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arazzius the Cruel - Between 25-50% Health - Say Line 3 (No Repeat)"),
(19191,0,8,0,2,0,100,1,0,25,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arazzius the Cruel - Between 0-25% Health - Say Line 4 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=19191 AND `GroupID` IN (2,3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19191,2,0,"Fool! You are a child playing in a world beyond your comprehension. Speak no more!",14,0,100,0,0,0,16858,0,"Arazzius the Cruel"),
(19191,3,0,"Your weapons are nothing to me! Relent!",14,0,100,0,0,0,16859,0,"Arazzius the Cruel"),
(19191,4,0,"You have confidence in your skills? Think carefully as the answer may surprise you.",14,0,100,0,0,0,16860,0,"Arazzius the Cruel");

-- Thornfang Ravager
DELETE FROM `smart_scripts` WHERE `entryorguid`=19349 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19349,0,1,0,25,0,100,0,0,0,0,0,0,11,22696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thornfang Ravager - On Respawn - Cast 'Thorns'");

-- Thornfang Venomspitter
DELETE FROM `smart_scripts` WHERE `entryorguid`=19350 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19350,0,0,0,0,0,100,0,2000,4000,12000,14000,0,11,6917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornfang Venomspitter - In Combat - Cast 'Venom Spit'"),
(19350,0,1,0,0,0,100,0,6000,8000,15000,17000,0,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornfang Venomspitter - In Combat - Cast 'Ravage'"),
(19350,0,2,0,25,0,100,0,0,0,0,0,0,11,22696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thornfang Venomspitter - On Respawn - Cast 'Thorns'");

-- Dreghood Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=16938 AND `source_type`=0 AND `id`=15;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16938,0,15,0,38,0,100,0,1,1,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Dreghood Brute - On Data 1 1 Set - Start Attacking");

-- Dreghood Geomancer
DELETE FROM `smart_scripts` WHERE `entryorguid`=16937 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16937,0,1,0,0,0,100,0,0,0,3000,5000,0,11,34083,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreghood Geomancer - In Combat - Cast 'Fireball'");

-- Stonescythe Whelp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16927;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16927 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16927,0,0,0,2,0,100,1,0,15,0,0,0,11,33896,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Whelp - Between 0-15% Health - Cast 'Desperate Defense' (No Repeat)"),
(16927,0,1,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Whelp - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=16927;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16927,0,0,"%s defends himself in desperation.",16,0,100,0,0,0,16744,0,"Stonescythe Whelp");

-- Stonescythe Alpha
DELETE FROM `smart_scripts` WHERE `entryorguid`=16929 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16929,0,1,0,2,0,100,1,0,15,0,0,0,11,33896,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Alpha - Between 0-15% Health - Cast 'Desperate Defense' (No Repeat)"),
(16929,0,2,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Alpha - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=16929;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16929,0,0,"%s defends himself in desperation.",16,0,100,0,0,0,16744,0,"Stonescythe Alpha");

-- Stonescythe Ambusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16928;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16928 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16928,0,0,0,25,0,100,0,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Ambusher - On Respawn - Cast 'Sneak'"),
(16928,0,1,0,0,0,100,0,1000,3000,14000,18000,0,11,31843,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonescythe Ambusher - In Combat - Cast 'Cheap Shot'"),
(16928,0,2,0,2,0,100,1,0,15,0,0,0,11,33896,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Ambusher - Between 0-15% Health - Cast 'Desperate Defense' (No Repeat)"),
(16928,0,3,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonescythe Ambusher - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=16928;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16928,0,0,"%s defends himself in desperation.",16,0,100,0,0,0,16744,0,"Stonescythe Ambusher");

-- Haal'eshi Talonguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16967;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16967 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16967,0,0,0,4,0,100,0,0,0,0,0,0,11,32720,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haal'eshi Talonguard - On Aggro - Cast 'Sprint'"),
(16967,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haal'eshi Talonguard - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Haal'eshi Windwalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16966;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16966 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16966,0,0,0,0,0,100,0,0,0,3000,5000,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Haal'eshi Windwalker - In Combat - Cast 'Lightning Bolt'"),
(16966,0,1,0,0,0,100,0,8000,12000,20000,24000,0,11,32717,0,0,0,0,0,5,0,0,0,0,0,0,0,"Haal'eshi Windwalker - In Combat - Cast 'Hurricane'"),
(16966,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haal'eshi Windwalker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Quillfang Ravager
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=16934 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=9000 WHERE `entryorguid`=16934 AND `source_type`=0 AND `id`=0;

-- Fix movement for some creatures
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (58637,58216,58207,58208,58209);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=19681;

-- Fix spell "Desperate Defense"
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-33896;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-33896,-33897,0,"Desperate Defense");

-- Sister of Grief (16960)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=16960;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16960 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16960,0,0,0,0,0,100,0,3000,5000,5000,8000,0,11,21987,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sister of Grief - In Combat - Cast \'Lash of Pain\''),
(16960,0,1,0,0,0,100,0,10000,15000,60000,60000,0,11,34250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sister of Grief - In Combat - Cast \'Whipped Fury\'');

-- Urga'zz (18976)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=18976;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18976 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18976,0,0,0,0,0,100,0,3000,7000,7000,12000,0,11,32004,0,0,0,0,0,2,0,0,0,0,0,0,0,'Urga\'zz - In Combat - Cast \'Drill\''),
(18976,0,1,0,0,0,100,0,11000,17000,17000,30000,0,11,32003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Urga\'zz - In Combat - Cast \'Power Burn\'');

-- Warbringer Arix'Amal (19298)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=19298;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19298 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19298,0,0,0,0,0,100,0,3000,7000,7000,11000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warbringer Arix\'Amal - In Combat - Cast \'Cleave\''),
(19298,0,1,0,0,0,100,0,8000,12000,11000,17000,0,11,32009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warbringer Arix\'Amal - In Combat - Cast \'Cutdown\'');

-- Razorsaw (20798)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=20798;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20798 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20798,0,0,0,0,0,100,0,4000,9000,14000,19000,0,11,36486,0,0,0,0,0,2,0,0,0,0,0,0,0,'Razorsaw - In Combat - Cast \'Slime Spray\''),
(20798,0,1,0,0,0,100,0,0,1000,1500,1500,0,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,'Razorsaw - In Combat - Cast \'Saw Blade\'');
