/*
-- Crag Coyote
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2727;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2727 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2727,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Crag Coyote - Out of Combat - Play Sound 1018"),
(2727,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crag Coyote - Out of Combat - Play Emote 393");

-- Feral Crag Coyote
DELETE FROM `smart_scripts` WHERE `entryorguid`=2728 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2728,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Feral Crag Coyote - Out of Combat - Play Sound 1018"),
(2728,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Crag Coyote - Out of Combat - Play Emote 393"),
(2728,0,2,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Crag Coyote - On Reset - Cast Thrash");

-- Elder Crag Coyote
DELETE FROM `smart_scripts` WHERE `entryorguid`=2729 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2729,0,2,0,0,0,100,0,4000,8000,6000,9000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Crag Coyote - In Combat - Cast Snarl");

-- Rabid Crag Coyote
DELETE FROM `smart_scripts` WHERE `entryorguid`=2730 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2730,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Rabid Crag Coyote - Out of Combat - Play Sound 1018"),
(2730,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rabid Crag Coyote - Out of Combat - Play Emote 393"),
(2730,0,2,0,0,0,100,0,4000,12000,16000,19000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Crag Coyote - In Combat - Cast Infected Wound"),
(2730,0,3,0,0,0,100,0,4000,12000,10000,18000,11,3150,34,0,0,0,0,5,0,0,0,0,0,0,0,"Rabid Crag Coyote - In Combat - Cast Rabies");

-- Ridge Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=2731 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2731,0,0,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Crag Coyote - On Reset - Cast Sneak");

-- Starving Buzzard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2829;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2829 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2829,0,0,0,0,0,100,0,5000,9000,16000,24000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Starving Buzzard - In Combat - Cast Infected Wound");

-- Buzzard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2830 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2830,0,0,0,0,0,100,0,5000,9000,16000,24000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Buzzard - In Combat - Cast Infected Wound");

-- Giant Buzzard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2831 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2831,0,0,0,0,0,100,0,5000,9000,16000,24000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Buzzard - In Combat - Cast Infected Wound");

-- Dustbelcher Ogres
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid` IN (2715,2906,2717,2701) AND `source_type`=0 AND `id`=0;

-- Dustbelcher Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2717 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2717,0,1,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mauler - On Reset - Cast Thrash");

-- Dustbelcher Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=2718 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2718,0,2,0,14,0,100,0,800,40,18000,24000,11,8005,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dustbelcher Shaman - On Friendly At 800 Health - Cast Healing Wave");

-- Dustbelcher Wyrmhunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=2716 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2716,0,2,0,0,0,100,0,6000,13000,18000,25000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - In Combat - Cast Net");

-- Dustbelcher Ogre Mage
DELETE FROM `smart_scripts` WHERE `entryorguid`=2720 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2720,0,2,0,0,0,100,0,4000,8000,31000,37000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - In Combat - Cast Bloodlust");

-- Dustbelcher Lord
DELETE FROM `smart_scripts` WHERE `entryorguid`=2719 AND `source_type`=0 AND `id` IN (0,1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2719,0,0,0,0,0,100,0,2000,5000,18000,21000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - In Combat - Cast Battle Shout"),
(2719,0,1,0,0,0,100,0,7000,11000,31000,35000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - In Combat - Cast Demoralizing Shout"),
(2719,0,3,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2719;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2719,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dustbelcher Lord"),
(2719,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dustbelcher Lord"),
(2719,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dustbelcher Lord");

-- Dustbelcher Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=2907 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2907,0,0,0,0,0,100,0,0,0,3000,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Mystic - In Combat - Cast Lightning Bolt"),
(2907,0,1,0,0,0,100,0,6000,12000,24000,30000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Mystic - In Combat - Cast Earth Shock"),
(2907,0,3,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2907;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2907,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dustbelcher Mystic"),
(2907,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dustbelcher Mystic"),
(2907,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dustbelcher Mystic");

-- Stonevault Bonesnapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=2893 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2893,0,0,0,0,0,100,0,5000,8000,11000,17000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Bonesnapper - In Combat - Cast Strike"),
(2893,0,1,0,0,0,100,0,9000,13000,17000,21000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Bonesnapper - In Combat - Cast Pummel");

-- Stonevault Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=2894 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2894,0,0,0,0,0,100,0,5000,7000,22000,25000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Shaman - In Combat - Cast Healing Ward"),
(2894,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Rumbler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2752 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2752,0,0,0,0,0,100,0,5000,9000,11000,16000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbler - In Combat - Cast Ground Tremor"),
(2752,0,1,0,0,0,100,0,7000,11000,14000,19000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbler - In Combat - Cast Trample");

-- War Golem
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2751;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2751 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2751,0,0,0,0,0,100,0,8000,11000,25000,28000,11,9576,0,0,0,0,0,1,0,0,0,0,0,0,0,"War Golem - In Combat - Cast Lock Down");

-- Shadowforge Darkweaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=2740 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2740,0,1,0,0,0,100,0,12000,14000,18000,22000,11,9482,32,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Darkweaver - In Combat - Cast Amplify Flames");

-- Shadowforge Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=2743 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2743,0,0,0,0,0,100,0,7000,10000,12000,15000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Warrior - In Combat - Cast Whirlwind");

-- Shadowforge Chanter
DELETE FROM `smart_scripts` WHERE `entryorguid`=2742 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2742,0,0,0,0,0,100,0,8000,12000,21000,25000,11,6066,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Chanter - In Combat - Cast Power Word: Shield"),
(2742,0,1,0,14,0,100,0,400,40,18000,22000,11,6077,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowforge Chanter - On Friendly At 400 Health - Cast Renew");

-- Shadowforge Surveyor
DELETE FROM `smart_scripts` WHERE `entryorguid`=4844 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4844,0,2,0,9,0,100,0,0,8,18000,22000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - Within 0-8 Range - Cast Frost Nova");

-- Fix spawn position for some creatures
UPDATE `creature` SET `position_x`=-7131.71, `position_y`=-3156.27, `position_z`=244.252, `spawndist`=10, `MovementType`=1 WHERE `guid`=6947;
UPDATE `creature` SET `position_x`=-6636.55, `position_y`=-3547.18, `position_z`=256.767, `spawndist`=5, `MovementType`=1 WHERE `guid`=6926;
UPDATE `creature` SET `position_x`=-6693.88, `position_y`=-3021.04, `position_z`=265.355, `spawndist`=10, `MovementType`=1 WHERE `guid`=6910;
UPDATE `creature` SET `position_x`=-6632.95, `position_y`=-3476.25, `position_z`=272.378, `spawndist`=5, `MovementType`=1 WHERE `guid`=6915;
UPDATE `creature` SET `position_x`=-7149.89, `position_y`=-3477.44, `position_z`=255.994, `spawndist`=10, `MovementType`=1 WHERE `guid`=6911;
*/
