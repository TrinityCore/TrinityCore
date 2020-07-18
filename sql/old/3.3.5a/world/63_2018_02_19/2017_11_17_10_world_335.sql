-- Besseleth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11921;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11921 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11921,0,0,0,9,0,100,0,0,30,9000,12000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Besseleth - Within 0-30 Range - Cast Web"),
(11921,0,1,0,0,0,100,0,6000,9000,12000,17000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Besseleth - In Combat - Cast Venom Sting");

-- Deepmoss Hatchling
DELETE FROM `smart_scripts` WHERE `entryorguid`=4263 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4263,0,0,1,2,0,30,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deepmoss Hatchling - Between 0-30% Health - Say Line 0 (No Repeat)"),
(4263,0,1,0,61,0,100,1,0,0,0,0,11,6536,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deepmoss Hatchling - Between 0-30% Health - Summon Deepmoss Matriarch (No Repeat)"),
(4263,0,2,0,54,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deepmoss Hatchling - Just Summoned - Say Line 1"),
(4263,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Deepmoss Hatchling - Just Summoned - Start Attacking");

DELETE FROM `creature_text` WHERE `CreatureID`=4263;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4263,0,0,"%s chitters for help...",16,0,100,0,0,0,1414,0,"Deepmoss Hatchling"),
(4263,1,0,"%s hatches!",16,0,100,0,0,0,1413,0,"Deepmoss Hatchling");

-- Deepmoss Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4264;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4264 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4264,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deepmoss Matriarch - Just Summoned - Say Line 0"),
(4264,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Deepmoss Matriarch - Just Summoned - Start Attacking");

DELETE FROM `creature_text` WHERE `CreatureID`=4264;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4264,0,0,"%s arrives!",16,0,100,0,0,0,1415,0,"Deepmoss Matriarch");

-- Blackened Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4044 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4044,0,0,0,0,0,100,0,7000,9000,22000,26000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackened Basilisk - In Combat - Cast Crystalline Slumber");

-- Scorched Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4041 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4041,0,0,0,0,0,100,0,7000,9000,22000,26000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scorched Basilisk - In Combat - Cast Crystalline Slumber");

-- Singed Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4042 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4042,0,0,0,0,0,100,0,7000,9000,22000,26000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Singed Basilisk - In Combat - Cast Crystalline Slumber");

-- Gerenzo Wrenchwhistle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4202 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4202,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gerenzo Wrenchwhistle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Goggeroc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11920;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11920 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11920,0,0,0,0,0,100,0,5000,7000,9000,13000,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goggeroc - In Combat - Cast Snap Kick"),
(11920,0,1,0,0,0,100,0,6000,9000,12000,16000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goggeroc - In Combat - Cast Uppercut"),
(11920,0,2,0,11,0,100,0,0,0,0,0,11,10387,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goggeroc - On Respawn - Cast Lightning Surge");

-- Furious Stone Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid`=4035 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4035,0,0,0,25,0,100,0,0,0,0,0,11,7095,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Stone Spirit - On Reset - Cast Knockdown Proc");

-- Bloodfury Harpy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4022;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4022 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4022,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Harpy - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Roguefeather
DELETE FROM `smart_scripts` WHERE `entryorguid`=4023 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4023,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Roguefeather - On Reset - Cast Thrash"),
(4023,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Roguefeather - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Slayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4024 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4024,0,1,0,0,0,100,0,7000,16000,120000,130000,11,16231,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Slayer - In Combat - Cast Curse of Recklessness"),
(4024,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Slayer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Ambusher
DELETE FROM `smart_scripts` WHERE `entryorguid`=4025 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4025,0,0,0,0,0,100,0,3000,5000,8000,12000,11,2608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Ambusher - In Combat - Cast Shock"),
(4025,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Ambusher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Windcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=4026 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4026,0,0,0,0,0,100,0,3000,5000,14000,20000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodfury Windcaller - In Combat - Cast Enveloping Winds"),
(4026,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Windcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Storm Witch
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4027 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4027 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4027,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Ripper
DELETE FROM `smart_scripts` WHERE `entryorguid`=12579 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12579,0,0,0,9,0,100,0,0,5,21000,25000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Ripper - Within 0-5 Range - Cast Rend");

-- Fix faction for Brother Ravenoak
UPDATE `creature_template` SET `faction`=124 WHERE `entry`=5915;
