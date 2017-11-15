/*
-- Greater Plainstrider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3244;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3244 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3244,0,0,0,0,0,100,0,7000,9000,17000,21000,11,7272,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Plainstrider - In Combat - Cast Dust Cloud"),
(3244,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Plainstrider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Fleeting Plainstrider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3246;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3246 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3246,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fleeting Plainstrider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Sunscale Lashtail
DELETE FROM `smart_scripts` WHERE `entryorguid`=3254 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3254,0,0,0,0,0,100,0,5000,9000,12000,20000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunscale Lashtail - In Combat - Cast Lash");

-- Sunscale Screecher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3255;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3255 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3255,0,0,0,2,0,100,1,0,30,0,0,39,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunscale Screecher - Between 0-30% Health - Call For Help (No Repeat)"),
(3255,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunscale Screecher - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3255;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3255,0,0,"%s lets out a shriek, calling for help!",16,0,100,0,0,0,2081,0,"Sunscale Screecher");

-- Sunscale Scytheclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=3256 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3256,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunscale Scytheclaw - On Reset - Cast Thrash");

-- Razormane Water Seeker
DELETE FROM `smart_scripts` WHERE `entryorguid`=3267 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3267,0,0,0,0,0,100,0,7000,13000,30000,40000,11,6278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Water Seeker - In Combat - Cast Creeping Mold"),
(3267,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Water Seeker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Thornweaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=3268 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3268,0,0,0,0,0,100,0,4000,7000,15000,21000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Thornweaver - In Combat - Cast Faerie Fire"),
(3268,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Thornweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Defender
DELETE FROM `smart_scripts` WHERE `entryorguid`=3266 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3266,0,1,0,0,0,100,0,8000,10000,30000,35000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Defender - In Combat - Cast Demoralizing Shout"),
(3266,0,2,0,0,0,100,0,5000,7000,11000,13000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Defender - In Combat - Cast Heroic Strike"),
(3266,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Defender - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Geomancer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3269 AND `source_type`=0 AND `id`=1;

-- Razormane Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=3271 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3271,0,1,0,16,0,100,0,324,1,15000,30000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Mystic - On Friendly Unit Missing Buff 'Lightning Shield' - Cast Lightning Shield"),
(3271,0,2,0,2,0,100,0,0,40,12000,19000,11,547,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Mystic - Between 0-40% Health - Cast Healing Wave"),
(3271,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=3457 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3457,0,0,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Stalker - On Reset - Cast Sneak"),
(3457,0,1,0,0,0,100,0,5000,9000,4000,8000,11,1758,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Stalker - In Combat - Cast Sinister Strike"),
(3457,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Stalker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Seer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3458 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3458,0,0,0,2,0,100,0,0,50,25000,35000,11,6274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - Between 0-50% Health - Cast Healing Ward"),
(3458,0,1,0,0,0,100,0,5000,11000,16000,24000,11,6363,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - In Combat - Cast Searing Totem"),
(3458,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razormane Warfrenzy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3459;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3459 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3459,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Warfrenzy - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hagg Taurenbane
DELETE FROM `smart_scripts` WHERE `entryorguid`=5859 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5859,0,0,0,4,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hagg Taurenbane - On Aggro - Cast Battle Stance"),
(5859,0,1,0,9,0,100,0,0,5,9000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - Within 0-5 Range - Cast Cleave"),
(5859,0,2,0,9,0,100,0,0,8,25000,30000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hagg Taurenbane - Within 0-8 Range - Cast Demoralizing Shout"),
(5859,0,3,0,0,0,100,0,5000,7000,11000,18000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - In Combat - Cast Hamstring");

-- Lok Orcbane
DELETE FROM `smart_scripts` WHERE `entryorguid`=3435 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3435,0,0,0,0,0,100,0,5000,8000,11000,17000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lok Orcbane - In Combat - Cast Hamstring");

-- Nak
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3434 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param2`=50, `comment`="Nak - Between 0-50% Health - Cast Lesser Healing Wave" WHERE `entryorguid`=3434 AND `source_type`=0 AND `id`=1;

-- Southsea Brigand
DELETE FROM `smart_scripts` WHERE `entryorguid`=3381 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3381,0,0,0,0,0,100,0,7000,14000,10000,16000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Brigand - In Combat - Cast Backhand"),
(3381,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Brigand - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Southsea Cannoneer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3382;
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=3382;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3382 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3382,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Cannoneer - In Combat - Cast Shoot"),
(3382,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Cannoneer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Southsea Cutthroat
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3383;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3383 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3383,0,0,0,0,0,100,0,4000,9000,18000,25000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Cutthroat - In Combat - Cast Poison"),
(3383,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Cutthroat - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Southsea Privateer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3384;
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=3384;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3384 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3384,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Privateer - In Combat - Cast Shoot"),
(3384,0,1,0,0,0,100,0,4000,6000,9000,13000,11,3011,2,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Privateer - In Combat - Cast Fire Shot"),
(3384,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Privateer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Tazan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6494;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6494 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6494,0,0,0,0,0,100,0,7000,14000,10000,16000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Brigand - In Combat - Cast Backhand"),
(6494,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Brigand - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Baron Longshore
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3467;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3467 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3467,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Longshore - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Theramore Marine
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3385;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3385 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3385,0,0,0,4,0,100,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Marine - On Aggro - Cast Defensive Stance"),
(3385,0,1,0,0,0,100,0,7000,12000,14000,21000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theramore Marine - In Combat - Cast Disarm"),
(3385,0,2,0,13,0,100,0,15000,20000,0,0,11,72,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theramore Marine - Target Casting - Cast Shield Bash"),
(3385,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Marine - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Theramore Preserver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3386;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3386 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3386,0,0,0,0,0,100,0,0,0,3400,4800,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Theramore Preserver - In Combat - Cast Holy Smite"),
(3386,0,1,0,14,0,100,0,150,40,12000,18000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Theramore Preserver - Friendly At 150 Health - Cast Heal"),
(3386,0,2,0,14,0,100,0,250,40,15000,21000,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,"Theramore Preserver - Friendly At 250 Health - Cast Renew"),
(3386,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Preserver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Captain Fairmount
UPDATE `smart_scripts` SET `event_param1`=12000, `event_param2`=15000 WHERE `entryorguid`=3393 AND `source_type`=0 AND `id`=2;

-- Cannoneer Smythe
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3454;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3454 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3454,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cannoneer Smythe - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Cannoneer Whessan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3455;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3455 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3455,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cannoneer Whessan - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witchwing Harpy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3276;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3276 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3276,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Harpy - On Aggro - Say Line 0"),
(3276,0,1,0,0,0,100,0,4000,9000,18000,25000,11,7098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Harpy - In Combat - Cast Curse of Mending"),
(3276,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Harpy - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3276;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3276,0,1,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Witchwing Harpy"),
(3276,0,2,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Witchwing Harpy"),
(3276,0,0,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Witchwing Harpy");

-- Witchwing Roguefeather
UPDATE `smart_scripts` SET `event_chance`=20 WHERE `entryorguid`=3277 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3277 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3277,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Harpy - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3277 AND `ID` IN (1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3277,0,1,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Witchwing Roguefeather"),
(3277,0,2,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Witchwing Roguefeather");

-- Witchwing Slayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3278;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3278 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3278,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Slayer - On Aggro - Say Line 0"),
(3278,0,1,0,0,0,100,0,6000,8000,25000,28000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Slayer - In Combat - Cast Demoralizing Shout"),
(3278,0,2,0,12,0,100,1,0,20,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Slayer - Target Between 0-20% Health - Cast 'Execute' (No Repeat)"),
(3278,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Slayer - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3278;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3278,0,1,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Witchwing Slayer"),
(3278,0,2,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Witchwing Slayer"),
(3278,0,0,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Witchwing Slayer");

-- Witchwing Ambusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3279;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3279 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3279,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Ambusher - On Aggro - Say Line 0"),
(3279,0,1,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Ambusher - On Reset - Cast Stealth"),
(3279,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Ambusher - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3279;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3279,0,1,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Witchwing Ambusher"),
(3279,0,2,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Witchwing Ambusher"),
(3279,0,0,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Witchwing Ambusher");

-- Witchwing Windcaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3280;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3280 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3280,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witchwing Windcaller - On Aggro - Say Line 0"),
(3280,0,1,0,0,0,100,0,4000,7000,12000,15000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Witchwing Windcaller - In Combat - Cast Enveloping Winds"),
(3280,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witchwing Windcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3280;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3280,0,1,"A fine trophy your head will make, $r.",12,0,100,0,0,0,2229,0,"Witchwing Windcaller"),
(3280,0,2,"My talons will shred your puny body, $r.",12,0,100,0,0,0,2230,0,"Witchwing Windcaller"),
(3280,0,0,"You will be easy prey, $c.",12,0,100,0,0,0,2231,0,"Witchwing Windcaller");

-- Serena Bloodfeather
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=9000, `event_param3`=12000, `event_param4`=18000 WHERE `entryorguid`=3452 AND `source_type`=0 AND `id`=0;

-- Sister Rathtalon
DELETE FROM `smart_scripts` WHERE `entryorguid`=5830 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5830,0,0,0,0,0,100,0,2000,3000,14000,21000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sister Rathtalon - In Combat - Cast Enveloping Winds"),
(5830,0,1,0,9,0,100,0,0,5,9000,15000,11,6982,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister Rathtalon - Within 0-5 Range - Cast Gust of Wind"),
(5830,0,2,0,0,0,100,0,11000,16000,25000,35000,11,6535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sister Rathtalon - In Combat - Cast Lightning Cloud");

-- Savannah Matriarch
DELETE FROM `smart_scripts` WHERE `entryorguid`=3416 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3416,0,0,0,4,0,100,0,0,0,0,0,11,6598,2,0,0,0,0,1,0,0,0,0,0,0,0,"Savannah Matriarch - On Aggro - Cast Savannah Cub");

-- Stormsnout
DELETE FROM `smart_scripts` WHERE `entryorguid`=3240 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3240,0,0,0,0,0,100,0,1000,2000,2000,6000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormsnout - In Combat - Cast Lizard Bolt");

-- Thunderhead
DELETE FROM `smart_scripts` WHERE `entryorguid`=3239 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3239,0,0,0,0,0,100,0,1000,2000,2000,6000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead - In Combat - Cast Lizard Bolt");

-- Stormhide
DELETE FROM `smart_scripts` WHERE `entryorguid`=3238 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3238,0,0,0,0,0,100,0,1000,2000,2000,6000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormhide - In Combat - Cast Lizard Bolt");

-- Thunderhawk Hatchling
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3247 AND `source_type`=0 AND `id`=1;

-- Greater Thunderhawk
DELETE FROM `smart_scripts` WHERE `entryorguid`=3249 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3249,0,0,0,0,0,100,0,5000,11000,13000,19000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Thunderhawk - In Combat - Cast Thunderclap");

-- Thunderhawk Cloudscraper
DELETE FROM `smart_scripts` WHERE `entryorguid`=3424 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3424,0,0,0,0,0,100,0,5000,11000,13000,19000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Cloudscraper - In Combat - Cast Thunderclap");

-- Silithid Protector
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3503;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3503 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3503,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Protector - Just Summoned - Say Line 0"),
(3503,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Silithid Protector - Just Summoned - Start Attacking");

DELETE FROM `creature_text` WHERE `CreatureID`=3503;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3503,0,0,"%s digs its way out of the sand to protect its eggs.",16,0,100,0,0,0,1080,0,"Silithid Protector");

-- Silithid Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=3250 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3250,0,0,1,0,0,100,0,7000,15000,15000,23000,11,6587,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper - In Combat - Cast Silithid Creeper Egg"),
(3250,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper - In Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3250;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3250,0,0,"%s lays an egg!",16,0,100,0,0,0,1408,0,"Silithid Creeper");

-- Silithid Creeper Egg
DELETE FROM `smart_scripts` WHERE `entryorguid`=578100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(578100,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Say Line 0"),
(578100,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Say Line 1"),
(578100,9,2,0,0,0,100,0,0,0,0,0,11,6588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Cast 'Summon Silithid Grub'"),
(578100,9,3,0,0,0,100,0,0,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Cast 'Suicide'");

-- Silithid Grub
DELETE FROM `smart_scripts` WHERE `entryorguid`=3251 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3251,0,1,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Grub - Just Summoned - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3251;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3251,0,0,"%s hatches!",16,0,100,0,0,0,1413,0,"Silithid Grub");

-- Silithid Swarmer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3252 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3252,0,0,0,0,0,100,0,8000,12000,8000,12000,11,6589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Swarmer - In Combat - Cast Silithid Swarm"),
(3252,0,1,0,11,0,100,0,0,0,0,0,11,6589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Swarmer - On Respawn - Cast Silithid Swarm");

-- Silithid Swarm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4196;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4196 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4196,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,"Silithid Swarm - Just Summoned - Start Attacking");

-- Silithid Harvester
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3253;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3253 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3253,0,0,0,0,0,100,0,1000,3000,8000,12000,11,7278,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Harvester - In Combat - Cast Summon Harvester Swarm");

-- Harvester Swarm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5409;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5409 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5409,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Harvester Swarm - Just Summoned - Start Attacking");

-- Azzere the Skyblade
DELETE FROM `smart_scripts` WHERE `entryorguid`=5834 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5834,0,0,0,0,0,100,0,0,0,3400,4800,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast Fireball"),
(5834,0,1,0,0,0,100,0,4000,9000,18000,22000,11,6725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast Flame Spike");

-- Brontus
DELETE FROM `smart_scripts` WHERE `entryorguid`=5827 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5827,0,1,0,0,0,100,0,5000,9000,7000,15000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brontus - In Combat - Cast Pierce Armor");

-- Venture Co. Peon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3285;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3285 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3285,0,0,0,2,0,100,1,0,25,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Peon - Between 0-25% Health - Flee For Assist (No Repeat)");

-- Venture Co. Drudger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3284 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3284,0,0,0,2,0,100,1,0,25,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Drudger - Between 0-25% Health - Flee For Assist (No Repeat)");

-- Tinkerer Sniggles
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3471;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3471 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3471,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Sniggles - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Mercenary
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3282;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3282 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3282,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mercenary - In Combat - Cast Shoot"),
(3282,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mercenary - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Supervisor Lugwizzle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3445;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3445 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3445,0,0,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Supervisor Lugwizzle - Between 0-30% Health - Flee For Assist (No Repeat)");

-- Overseer Glibby
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6606;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6606 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6606,0,0,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Supervisor Glibby - Between 0-30% Health - Flee For Assist (No Repeat)");

-- Venture Co. Enforcer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3283;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3283 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3283,0,0,0,4,0,100,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Enforcer - On Aggro - Cast Battle Shout"),
(3283,0,1,0,0,0,100,0,5000,9000,15000,19000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Enforcer - In Combat - Cast Disarm"),
(3283,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Enforcer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Boss Copperplug
DELETE FROM `smart_scripts` WHERE `entryorguid`=9336 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9336,0,0,0,0,0,100,0,5000,9000,9000,16000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Copperplug - In Combat - Cast Net"),
(9336,0,1,0,0,0,100,0,0,0,2300,3900,11,9143,64,0,0,0,0,2,0,0,0,0,0,0,0,"Boss Copperplug - In Combat - Cast Bomb");

-- Foreman Grills
DELETE FROM `smart_scripts` WHERE `entryorguid`=5835 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5835,0,0,0,0,0,100,0,5000,7000,8000,11000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Grills - In Combat - Cast Hamstring"),
(5835,0,1,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Grills - Between 0-20% Health - Say Line 0 (No Repeat)"),
(5835,0,2,0,2,0,100,0,0,20,4000,6000,11,6531,32,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Grills - Between 0-20% Health - Cast Overseer's Poison");

DELETE FROM `creature_text` WHERE `CreatureID`=5835;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5835,0,0,"%s grabs for his poisoned dagger!",16,0,100,0,0,0,1385,0,"Foreman Grills");

-- Bristleback Thornweaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=3261 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3261,0,0,0,1,0,100,0,1000,1000,600000,600000,11,782,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Thornweaver - Out of Combat - Cast Thorns"),
(3261,0,1,0,0,0,100,0,5000,9000,10000,16000,11,12747,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bristleback Thornweaver - In Combat - Cast Entangling Roots"),
(3261,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Thornweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bristleback Geomancer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3263 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=3263 AND `source_type`=0 AND `id` IN (1,2);

-- Bristleback Water Seeker
DELETE FROM `smart_scripts` WHERE `entryorguid`=3260 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3260,0,0,0,0,0,100,0,5000,13000,10000,16000,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Water Seeker - In Combat - Cast Frost Nova"),
(3260,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Water Seeker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Barrens Kodo
DELETE FROM `smart_scripts` WHERE `entryorguid`=3236 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3236,0,0,0,0,0,100,0,6000,8000,10000,14000,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barrens Kodo - In Combat - Cast Kodo Stomp");

-- Bael'dun Excavator
DELETE FROM `smart_scripts` WHERE `entryorguid`=3374 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3374,0,1,0,0,0,100,0,5000,9000,13000,17000,11,7386,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Excavator - In Combat - Cast Sunder Armor"),
(3374,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Excavator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bael'dun Foreman
DELETE FROM `smart_scripts` WHERE `entryorguid`=3375 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3375,0,0,0,0,0,100,0,0,0,3400,4700,11,6257,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Foreman - In Combat - Cast Torch Toss"),
(3375,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Foreman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Digger Flameforge
DELETE FROM `smart_scripts` WHERE `entryorguid`=5849 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5849,0,0,0,0,0,100,0,0,0,2000,3500,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Digger Flameforge - In Combat - Cast Throw Dynamite"),
(5849,0,1,0,9,0,100,0,0,5,9000,14000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Digger Flameforge - Within 0-5 Range - Cast Backhand");

-- Prospector Khazgorm
DELETE FROM `smart_scripts` WHERE `entryorguid`=3392 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3392,0,0,0,0,0,100,0,7000,14000,10000,16000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prospector Khazgorm - In Combat - Cast Backhand");

-- Bael'dun Soldier
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3376;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3376 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3376,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Soldier - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bael'dun Rifleman
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=3377;

-- Bael'dun Officer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3378 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3378,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Officer - On Reset - Cast Thrash"),
(3378,0,1,0,0,0,100,0,3000,7000,15000,23000,11,6264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Officer - In Combat - Cast Nimble Reflexes"),
(3378,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Officer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Captain Gerogg Hammertoe
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5851;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5851 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5851,0,0,0,4,0,100,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Gerogg Hammertoe - On Aggro - Cast Defensive Stance"),
(5851,0,1,0,2,0,100,0,0,50,15000,25000,11,3419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Gerogg Hammertoe - Between 0-50% Helath - Cast Improved Blocking");

-- Burning Blade Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=3380 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3380,0,1,0,0,0,100,0,6000,11000,17000,22000,11,707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Acolyte - In Combat - Cast Immolate"),
(3380,0,2,0,0,0,100,0,2000,5000,26000,31000,11,980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Acolyte - In Combat - Cast Curse of Agony"),
(3380,0,3,0,2,0,100,0,0,50,13000,18000,11,689,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Acolyte - Between 0-50% Health - Cast Drain Life");

-- Rathorian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3470;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3470 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3470,0,0,0,0,0,100,0,5000,7000,11000,15000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rathorian - In Combat - Cast Mortal Strike");

-- Kolkar Bloodcharger
DELETE FROM `smart_scripts` WHERE `entryorguid`=3397 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3397,0,0,0,0,0,100,0,3000,5000,32000,35000,11,6742,32,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Bloodcharger - In Combat - Cast Bloodlust"),
(3397,0,1,0,0,0,100,0,6000,8000,15000,19000,11,172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Bloodcharger - In Combat - Cast Corruption"),
(3397,0,2,3,6,0,5,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Bloodcharger - On Just Died - Say Line 0"),
(3397,0,3,0,61,0,100,0,0,0,0,0,12,3395,6,20000,0,0,0,8,0,0,0,-1209.65,-2738.38,102.646,4.99352,"Kolkar Bloodcharger - On Just Died - Summon Creature 'Verog the Dervish'");

-- Kolkar Marauder
DELETE FROM `smart_scripts` WHERE `entryorguid`=3275 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3275,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Marauder - On Aggro - Cast Rushing Charge"),
(3275,0,1,0,0,0,100,0,5000,11000,7000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Marauder - In Combat - Cast Strike"),
(3275,0,2,0,0,0,100,0,7000,15000,9000,14000,11,8014,32,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Marauder - In Combat - Cast Tetanus"),
(3275,0,3,4,6,0,5,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Marauder - On Just Died - Say Line 0"),
(3275,0,4,0,61,0,100,0,0,0,0,0,12,3395,6,20000,0,0,0,8,0,0,0,-1209.65,-2738.38,102.646,4.99352,"Kolkar Marauder - On Just Died - Summon Creature 'Verog the Dervish'");

-- Kolkar Pack Runner
UPDATE `smart_scripts` SET `event_chance`=5 WHERE `entryorguid`=3274 AND `source_type`=0 AND `id`=1;

-- Kolkar Stormer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3273 AND `source_type`=0 AND `id`=1;

-- Rocklance
DELETE FROM `smart_scripts` WHERE `entryorguid`=5841 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5841,0,1,0,0,0,100,0,5000,7000,12000,16000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rocklance - In Combat - Cast Cleave"),
(5841,0,2,0,9,0,100,0,0,5,15000,19000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rocklance - Within 0-5 Range - Cast Sunder Armor");

-- Geopriest Gukk'rok
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=5863 AND `source_type`=0;

-- Snort the Heckler
DELETE FROM `smart_scripts` WHERE `entryorguid`=5829 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5829,0,0,0,0,0,100,0,3000,5000,7000,11000,11,7951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snort the Heckler - In Combat - Cast Toxic Spit"),
(5829,0,1,0,9,0,100,0,0,5,15000,21000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snort the Heckler - Within 0-5 Range - Cast Tendon Rip");

-- Swinegart Spearhide
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5864;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5864 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5864,0,0,0,4,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swinegart Spearhide - On Aggro - Cast Battle Stance"),
(5864,0,1,0,0,0,100,0,5000,7000,15000,17000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swinegart Spearhide - In Combat - Cast Pierce Armor");

-- Trigore the Lasher
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=32768 WHERE `entry`=3652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3652 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3652,0,0,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trigore the Lasher - On Reset - Cast Thrash");

-- Devouring Ectoplasm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3638;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3638 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3638,0,0,0,2,0,100,1,0,50,0,0,11,7952,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devouring Ectoplasm - Between 0-50% Health - Cast Clone (No Repeat)");

-- Deviate Stinglash
DELETE FROM `smart_scripts` WHERE `entryorguid`=3631 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3631,0,0,0,0,0,100,0,5000,7000,12000,18000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Stinglash - In Combat - Cast Lash");

-- Deviate Slayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3633 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633,0,0,0,12,0,100,0,0,20,9000,14000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Slayer - Target Between 0-20% Health - Cast Fatal Bite");

-- Deviate Creeper
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=3632 AND `source_type`=0;

-- Deviate Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3634;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3634 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3634,0,0,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Stalker - On Reset - Cast Stealth");

-- Gesharahan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3398;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3398 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3398,0,0,0,0,0,100,0,6000,9000,17000,23000,11,3583,2,0,0,0,0,5,0,0,0,0,0,0,0,"Gesharahan - In Combat - Cast Deadly Poison");

-- Death's Head Cultist
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=7872 AND `source_type`=0 AND `id`=0;

-- Death's Head Necromancer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=7337 AND `source_type`=0 AND `id`=2;

-- Razorfen Servitor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6132;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6132 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6132,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Servitor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Fix movement for some creatures
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (14096,14081,14166,14174,14256);
UPDATE `creature` SET `spawndist`=3, `MovementType`=1 WHERE `guid` IN (13605,13607);
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (13820,15066,14418,19791,13598,13594,13614,13611,13615,13627,13626,13600);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `guid` IN (51814,51810,14033);
UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid` IN (51813,14365);
UPDATE `creature` SET `spawndist`=25, `MovementType`=1 WHERE `guid` IN (51815,51816,15081);

-- Fix position for some creatures
UPDATE `creature` SET `position_x`=-912.213, `position_y`=-2217.01, `position_z`=93.6255, `spawndist`=10, `MovementType`=1 WHERE `guid`=20567;
UPDATE `creature` SET `position_x`=-107.326, `position_y`=-1851.97, `position_z`=92.4291, `spawndist`=8, `MovementType`=1 WHERE `guid`=19473;
UPDATE `creature` SET `position_x`=-53.9019, `position_y`=-1633.82, `position_z`=91.6667, `orientation`=4.1112 WHERE `guid`=20635;
UPDATE `creature` SET `position_x`=-4062.05, `position_y`=-2173.13, `position_z`=51.4807, `orientation`=0.690689 WHERE `guid`=13610;

-- Add emotes for some creatures
UPDATE `creature_addon` SET `emote`=173 WHERE `guid` IN (13610,13583,13617);
UPDATE `creature_addon` SET `bytes1`=3 WHERE `guid` IN (65607,14200,14253,14195,14215);

-- Pooling for Baron Longshore
SET @GUID := 84198;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,3467,1,0,0,1,1,0,1,-1751.48,-3720.43,14.0041,4.99665,300,5,0,356,0,1,0,0,0,"",0),
(@GUID+1,3467,1,0,0,1,1,0,1,-1723.34,-3811.04,11.8995,5.6289,300,5,0,356,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1110;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1110,1,"Baron Longshore");

DELETE FROM `pool_creature` WHERE `pool_entry`=1110;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1110,0,"Baron Longshore (3467) - Spawn 1"),
(@GUID+1,1110,0,"Baron Longshore (3467) - Spawn 2"),
(15066,1110,0,"Baron Longshore (3467) - Spawn 3");
*/
