-- Death's Head Adept
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4516 AND `source_type`=0 AND `id`=0;

-- Rotting Agam'ar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4512;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4512 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4512,0,0,1,0,0,100,2,9000,15000,30000,45000,11,8267,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Agam'ar - In Combat - Cast Cursed Blood"),
(4512,0,1,0,61,0,100,2,0,0,0,0,11,8268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Agam'ar - In Combat - Cast Cursed Blood");

-- Raging Agam'ar
DELETE FROM `smart_scripts` WHERE `entryorguid`=4514 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4514,0,1,0,2,0,100,3,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Agam'ar - Between 0-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=4514;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4514,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,38630,0,"Agathelos the Raging");

-- Agam'ar
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=4511 AND `source_type`=0 AND `id`=0;

-- Death's Head Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=4515 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4515,0,0,0,0,0,100,2,2000,3000,11000,15000,11,15785,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Acolyte - In Combat - Cast Mana Burn"),
(4515,0,1,0,14,0,100,2,1000,40,14000,19000,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,"Death's Head Acolyte - Friendly At 1000 Health - Cast Renew");

-- Razorfen Dustweaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=4522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4522,0,0,0,0,0,100,2,2000,3000,13000,16000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Razorfen Dustweaver - In Combat - Cast Enveloping Winds"),
(4522,0,1,0,11,0,100,2,0,0,0,0,11,8271,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Dustweaver - On Respawn - Cast Summon Wind Howler");

-- Razorfen Handler
DELETE FROM `smart_scripts` WHERE `entryorguid`=4530 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4530,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Handler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razorfen Beastmaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=4532 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4532,0,2,0,0,0,100,2,5000,8000,12000,18000,11,8275,0,0,0,0,0,5,0,0,0,0,0,0,0,"Razorfen Beastmaster - In Combat - Cast Poisoned Shot"),
(4532,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Beastmaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razorfen Groundshaker
UPDATE `smart_scripts` SET `target_type`=5 WHERE `entryorguid`=4525 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=4525 AND `source_type`=0 AND `id`=1;

-- Razorfen Warden
UPDATE `smart_scripts` SET `event_param3`=7000, `event_param4`=10000 WHERE `entryorguid`=4437 AND `source_type`=0 AND `id`=0;

-- Death's Head Priest
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4517 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4517 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4517,0,2,0,14,0,100,2,1000,40,14000,20000,11,6063,0,0,0,0,0,7,0,0,0,0,0,0,0,"Death's Head Priest - Friendly At 1000 Health - Cast Heal");

-- Razorfen Spearhide
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4438;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4438 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4438,0,0,0,0,0,100,2,4000,7000,7000,11000,11,8259,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Spearhide - In Combat - Cast Whirling Barrage"),
(4438,0,1,0,0,0,100,2,1000,3000,60000,70000,11,8148,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Spearhide - In Combat - Cast Thorns Aura");

-- Razorfen Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6035;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6035 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6035,0,0,0,25,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Stalker - On Reset - Cast Sneak"),
(6035,0,1,0,67,0,100,2,4000,7000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorfen Stalker - On Behind Target - Cast Backstab");

-- Greater Kraul Bat
DELETE FROM `smart_scripts` WHERE `entryorguid`=4539 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4539,0,0,0,0,0,100,2,4000,6000,8000,13000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Kraul Bat - In Combat - Cast Sonic Burst");

-- Roogug
DELETE FROM `smart_scripts` WHERE `entryorguid`=6168 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6168,0,0,0,0,0,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Roogug - In Combat CMC - Cast Lightning Bolt"),
(6168,0,1,0,11,0,100,3,0,0,0,0,11,8270,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roogug - On Respawn - Cast Summon Earth Rumbler");

-- Aggem Thorncurse
DELETE FROM `smart_scripts` WHERE `entryorguid`=4424 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4424,0,2,0,2,0,100,0,0,75,13000,18000,11,14900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Handler - Between 0-75% Health - Cast Chain Heal");

-- Death Speaker Jargba
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4428 AND `source_type`=0 AND `id`=0;

-- Overlord Ramtusk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4420 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4420,0,0,0,0,0,100,2,1000,3000,30000,45000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - In Combat - Cast Battle Shout"),
(4420,0,1,0,9,0,100,2,0,8,8000,14000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - Within 0-8 Range - Cast Thunderclap"),
(4420,0,2,3,4,0,100,2,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - On Aggro - Cast Battle Stance"),
(4420,0,3,4,61,0,100,2,0,0,0,0,39,15,1,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - On Aggro - Call For Help"),
(4420,0,4,0,61,0,100,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4420;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4420,0,0,"Victory! For Agamaggan!",14,0,100,0,0,5812,6178,0,"Overlord Ramtusk");

-- Charlga Razorflank
DELETE FROM `smart_scripts` WHERE `entryorguid`=4421 AND `source_type`=0 AND `id` IN (5,7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4421,0,5,0,0,0,100,2,9000,13000,9000,13000,11,8361,0,0,0,0,0,1,0,0,0,0,0,0,0,"Charlga Razorflank - In Combat - Cast Purity"),
(4421,0,7,0,0,0,100,2,0,0,3400,4800,11,8292,64,0,0,0,0,2,0,0,0,0,0,0,0,"Charlga Razorflank - In Combat - Cast Chain Bolt");

UPDATE `creature_text` SET `Sound`=5813 WHERE `BroadcastTextId`=6179;
UPDATE `creature_text` SET `Sound`=5814 WHERE `BroadcastTextId`=6180;
UPDATE `creature_text` SET `Sound`=5815 WHERE `BroadcastTextId`=6181;
UPDATE `creature_text` SET `Sound`=5816 WHERE `BroadcastTextId`=6182;
UPDATE `creature_text` SET `Sound`=5818 WHERE `BroadcastTextId`=6183;

-- Agathelos the Raging
DELETE FROM `smart_scripts` WHERE `entryorguid`=4422 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4422,0,0,1,4,0,100,3,0,0,0,0,11,8260,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - On Aggro - Cast Rushing Charge"),
(4422,0,1,0,61,0,100,3,0,0,0,0,39,15,1,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - On Aggro - Call For Help"),
(4422,0,2,0,2,0,100,3,0,40,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - Between 0-40% Health - Cast Frenzy (No Repeat)"),
(4422,0,3,0,2,0,100,3,0,40,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - Between 0-40% Health - Say Line 0 (No Repeat)"),
(4422,0,4,0,2,0,100,3,0,60,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - Between 0-60% Health - Cast Frenzy (No Repeat)"),
(4422,0,5,0,2,0,100,3,0,60,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - Between 0-60% Health - Say Line 0 (No Repeat)"),
(4422,0,6,0,9,0,100,2,0,5,21000,35000,11,8555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Agathelos the Raging - Within 0-5 Range - Cast Left for Dead"),
(4422,0,7,0,0,0,100,2,8000,14000,25000,31000,11,8285,0,0,0,0,0,1,0,0,0,0,0,0,0,"Agathelos the Raging - In Combat - Cast Rampage");

DELETE FROM `creature_text` WHERE `CreatureID`=4422;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4422,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,38630,0,"Agathelos the Raging");

-- Remove wrong spawns
DELETE FROM `creature` WHERE `guid` IN
(87339,87341,87366, -- Tamed Hyena (Already spawned as part of Razorfen Beastmaster's scripts)
87300,87309,87410, -- Stone Rumbler (Already spawned as part of Razorfen Geomancer's scripts)
87348, -- Stone Rumbler (Will be spawned as part of Roogug's scripts)
87361,87406,87409); -- Wind Howler (Will be spawned as part of Razorfen Dustweaver's scripts)
DELETE FROM `creature_addon` WHERE `guid` IN (87339,87341,87366,87300,87309,87410,87348,87361,87406,87409);