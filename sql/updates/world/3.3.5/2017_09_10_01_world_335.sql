-- Trained Razorbeak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2657;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2657 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2657,0,0,0,9,0,100,0,0,5,15000,19000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Trained Razorbeak - In Combat - Cast Rend Flesh");

-- Mangy Silvermane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2923;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2923 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2923,0,0,0,0,0,100,0,4000,4500,22000,25000,11,8139,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mangy Silvermane - In Combat - Cast Fevered Fatigue");

-- Silvermane Howler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2925;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2925 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2925,0,0,0,0,0,100,0,2000,4500,12000,13000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Howler - In Combat - Cast Snarl"),
(2925,0,1,0,0,0,100,0,6000,9000,18000,22000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Howler - In Combat - Cast Furious Howl");

-- Silvermane Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2926;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2926 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2926,0,0,0,0,0,100,0,4000,5000,17000,19000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermane Stalker - In Combat - Cast Infected Bite"),
(2926,0,1,0,25,0,100,1,0,0,0,0,11,6408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Stalker - On Reset - Cast Faded (No Repeat)");

-- Old Cliff Jumper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8211;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8211 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8211,0,0,0,9,0,100,0,0,8,15000,18000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Cliff Jumper - Within 0-8 Range - Cast Blood Howl"),
(8211,0,1,0,9,0,100,0,0,5,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Cliff Jumper - Within 0-5 Range - Cast Tendon Rip");

-- Vicious Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2927;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2927 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2927,0,0,0,9,0,100,0,0,5,18000,24000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicious Owlbeast - Within 0-5 Range - Cast Fatal Bite");

-- Primitive Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2928;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2928 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2928,0,0,0,9,0,100,0,0,5,13000,16000,11,3252,0,0,0,0,0,2,0,0,0,0,0,0,0,"Primitive Owlbeast - Within 0-5 Range - Cast Shred");

-- Razortalon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8210;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8210 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8210,0,0,0,9,0,100,0,0,5,9000,12000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - Within 0-5 Range - Cast Strike"),
(8210,0,1,0,9,0,100,0,0,5,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - Within 0-5 Range - Cast Tendon Rip"),
(8210,0,2,0,0,0,100,0,6000,11000,18000,21000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razortalon - In Combat - Cast Rend");

-- Jade Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2656;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2656 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2656,0,0,0,0,0,100,0,4000,6000,16000,18000,11,6907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jade Ooze - In Combat - Cast Diseased Slime");

-- Green Sludge
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2655;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2655 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2655,0,0,0,0,0,100,0,4000,6000,12000,16000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Sludge - In Combat - Cast Corrosive Ooze");

-- The Reak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8212;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8212 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8212,0,0,0,0,0,100,0,6000,8000,18000,24000,11,7279,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Reak - In Combat - Cast Black Sludge"),
(8212,0,1,0,0,0,100,0,4000,6000,28000,32000,11,21062,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Reak - In Combat - Cast Putrid Breath");

-- Witherbark Scalper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2649;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2649 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2649,0,0,0,0,0,100,0,0,0,2100,4800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Scalper - In Combat CMC - Cast Throw"),
(2649,0,1,0,12,0,100,1,0,20,0,0,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Scalper - Target Between 0-20% Health - Cast Execute (No Repeat)"),
(2649,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Scalper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Zealot
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2650;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2650 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2650,0,0,0,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Zealot - Between 0-30% Health - Cast Enrage (No Repeat)");

-- Witherbark Hideskinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2651;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2651 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2651,0,0,0,9,0,100,0,0,5,5000,9000,11,8721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Hideskinner - In Combat - Cast Backstab"),
(2651,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Hideskinner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Venomblood
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2652 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2652,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Venomblood - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Sadist
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2653;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2653 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2653,0,0,0,1,0,100,1,1000,1000,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Sadist - Out of Combat - Cast Battle Stance (No Repeat)"),
(2653,0,1,0,9,0,100,0,0,5,6000,9000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Sadist - Within 0-5 Range - Cast Heroic Strike (No Repeat)"),
(2653,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Sadist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Caller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2654;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2654 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2654,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Caller - Combat CMC - Cast Shadow Bolt"),
(2654,0,1,0,4,0,100,0,0,0,0,0,11,11017,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Caller - On Aggro - Summon Witherbark Felhunter"),
(2654,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Caller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Felhunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7767;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7767 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7767,0,0,0,9,0,100,0,0,10,8000,14000,11,2691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Felhunter - Within 0-10 Range - Cast Mana Burn");

-- Witherbark Broodguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2686;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2686 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2686,0,0,0,6,0,100,0,0,0,0,0,11,11018,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witherbark Broodguard - On Death - Summon Witherbark Bloodlings");

-- Witherheart the Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8218;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8218 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8218,0,0,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherheart the Stalker - On Reset - Cast Sneak"),
(8218,0,1,0,67,0,100,0,5000,9000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherheart the Stalker - On Behind Target - Cast Backstab");

-- Zul'arek Hatefowler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8219;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8219 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8219,0,0,0,9,0,100,0,0,30,9000,14000,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zul\'arek Hatefowler - Within 0-30 Range - Cast Shadow Bolt Volley");

-- Witch Doctor Mai'jin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17235;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17235 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17235,0,0,0,0,0,100,0,15000,25000,30000,45000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Mai\'jin - In Combat - Cast Healing Ward (No Repeat)"),
(17235,0,1,0,0,0,100,0,6000,8000,25000,28000,11,8190,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Mai\'jin - In Combat - Cast Magma Totem (No Repeat)");

-- Tcha'kaz
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17236;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17236 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17236,0,0,0,6,0,100,0,0,0,0,0,11,11018,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tcha\'kaz - On Death - Summon Witherbark Bloodlings");

-- Highvale Outrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2691;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2691 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2691,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Outrunner - In Combat CMC - Cast Shoot"),
(2691,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Outrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Highvale Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2692;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2692 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2692,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Highvale Marksman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2693;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2693 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2693,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Marksman - In Combat CMC - Cast Shoot"),
(2693,0,1,0,9,0,100,0,5,30,9000,13000,11,14443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Marksman - Within 5-30 Range - Cast Multi-Shot"),
(2693,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Marksman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Highvale Ranger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2694;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2694 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2694,0,0,0,9,0,100,0,0,30,30000,35000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highvale Ranger - Within 0-30 Range - Cast Faerie Fire");

-- Vilebranch Soothsayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4467;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4467 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4467,0,0,0,0,0,100,0,0,0,3400,4700,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Soothsayer - In Combat - Cast Lightning Bolt"),
(4467,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Soothsayer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(4467,0,2,0,14,0,100,0,2500,40,20000,30000,11,10395,1,0,0,0,0,7,0,0,0,0,0,0,0,"Vilebranch Soothsayer - Friendly At 40% Health - Cast Healing Wave");

-- Vilebranch Scalper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4466;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4466 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4466,0,0,0,12,0,100,1,0,20,0,0,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Scalper - Target Between 0-20% Health - Cast Execute (No Repeat)"),
(4466,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Scalper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Qiaga the Keeperer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7996;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7996 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7996,0,0,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Qiaga the Keeper - In Combat CMC - Cast Shadow Bolt"),
(7996,0,1,0,0,0,100,0,4200,7700,7100,16200,11,11639,32,0,0,0,0,2,0,0,0,0,0,0,0,"Qiaga the Keeper - In Combat - Cast Shadow Word: Pain"),
(7996,0,2,0,14,0,100,0,1000,40,15000,19000,11,11640,1,0,0,0,0,7,0,0,0,0,0,0,0,"Qiaga the Keeper - Friendly At 40% Health - Cast Renew"),
(7996,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiaga the Keeperer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Morta'gya the Keeperer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8636;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8636 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8636,0,0,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morta\'gya the Keeper - In Combat CMC - Cast Shadow Bolt"),
(8636,0,1,0,0,0,100,0,4200,7700,7100,16200,11,11639,32,0,0,0,0,2,0,0,0,0,0,0,0,"Morta\'gya the Keeper - In Combat - Cast Shadow Word: Pain"),
(8636,0,2,0,14,0,100,0,1000,40,15000,19000,11,11640,1,0,0,0,0,7,0,0,0,0,0,0,0,"Morta\'gya the Keeper - Friendly At 40% Health - Cast Renew"),
(8636,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morta\'gya the Keeper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Retherokk the Berserker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8216;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8216 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8216,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Retherokk the Berserker - Between 0-30% Health - Cast Enrage (No Repeat)"),
(8216,0,1,0,0,0,100,0,2000,3000,8000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Retherokk the Berserker - In Combat - Cast Thrash");

-- Gammerita
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7977;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7977 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7977,0,0,0,9,0,100,0,0,5,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gammerita - Within 0-5 Range - Cast Pierce Armor");

-- Jade Sludge
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4468;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4468 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4468,0,0,0,9,0,100,0,0,10,15000,29000,11,6814,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jade Sludge - Within 0-10 Range - Cast Sludge Toxin");

-- Emerald Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4469;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4469 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4469,0,0,0,9,0,100,0,0,5,12000,19000,11,8245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Ooze - Within 0-5 Range - Cast Corrosive Acid");

-- Vilebranch Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4465;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4465 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4465,0,0,0,9,0,100,0,0,5,5000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Warrior - Within 0-5 Range - Cast Strike"),
(4465,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Witch Doctor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2640;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2640 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2640,0,0,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - In Combat CMC - Cast Shadow Bolt"),
(2640,0,1,0,14,0,100,0,1200,40,13000,17000,11,8005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - Friendly at 1200 Health - Cast Healing Wave"),
(2640,0,2,0,0,0,100,1,9000,13000,22000,28000,11,18503,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - In Combat CMC - Cast Hex"),
(2640,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Headhunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2641;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2641 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2641,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Headhunter - In Combat CMC - Cast Throw"),
(2641,0,1,0,9,0,100,0,0,5,15000,18000,11,7357,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Headhunter - Within 0-5 Range - Cast Poisonous Stab"),
(2641,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Shadowcaster
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2642;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2642 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2642,0,0,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat CMC - Cast Shadow Bolt"),
(2642,0,1,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - Out of Combat - Cast Summon Voidwalker"),
(2642,0,2,0,0,0,100,0,2500,10000,35000,40000,11,7289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - In Combat - Cast Shrink"),
(2642,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Hideskinnerr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2644;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2644 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2644,0,0,0,67,0,100,0,5000,9000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Hideskinner - On Behind Target - Cast Backstab"),
(2644,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Hideskinnerr - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Shadow Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2645;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2645 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2645,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - Combat CMC - Cast Shoot"),
(2645,0,1,0,9,0,100,0,0,30,21000,26000,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - Within 0-30 Range - Cast Shadow Word: Pain"),
(2645,0,2,0,0,0,100,0,4000,9000,15000,21000,11,9657,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - In Combat - Cast Shadow Shell"),
(2645,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Shadow Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mith'rethis the Enchanter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8217;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8217 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8217,0,0,0,0,0,100,0,5000,9000,12000,16000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith\'rethis the Enchanter - In Combat - Cast Slow"),
(8217,0,1,0,9,0,100,0,0,30,24000,29000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mith\'rethis the Enchanter - Within 0-30 Range - Cast Shadow Word: Pain"),
(8217,0,2,0,0,0,100,0,1000,5000,21000,27000,11,3443,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mith\'rethis the Enchanter - In Combat - Cast Enchanted Quickness");

-- Vilebranch Blood Drinker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2646;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2646 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2646,0,0,0,9,0,100,0,0,5,7000,15000,11,11015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Blood Drinker - Within 0-5 Range - Cast Blood Leech"),
(2646,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Blood Drinker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Soul Eater
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2647;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2647 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2647,0,0,0,9,0,100,0,0,5,8000,12000,11,11016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Soul Eater - Within 0-5 Range - Cast Soul Bite"),
(2647,0,1,0,14,0,100,0,600,10,12000,15000,11,7154,1,0,0,0,0,7,0,0,0,0,0,0,0,"Vilebranch Soul Eater - On Friendly at 600 Health - Cast Dark Offering"),
(2647,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Soul Eater - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Aman'zasi Guard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2648;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2648 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2648,0,0,0,0,0,100,0,4000,7000,8000,11000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Aman\'zasi Guard - In Combat - Cast Shield Slam"),
(2648,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Aman\'zasi Guard - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Raiding Wolf
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2681;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2681 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2681,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Raiding Wolf - In Combat - Cast Thrash");

-- Vile Priestess Hexx
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7995;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7995 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7995,0,0,0,9,0,100,0,0,30,9000,12000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Priestess Hexx - Within 0-30 Range - Cast Shadow Word: Pain"),
(7995,0,1,0,0,0,100,0,7000,12000,18000,25000,11,11641,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Priestess Hexx - In Combat - Cast Hex"),
(7995,0,2,0,14,0,100,0,1200,40,12000,15000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vile Priestess Hexx - Friendly At 1200 Health - Cast Heal"),
(7995,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Priestess Hexx - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hitah'ya the Keeper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10802 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10802,0,0,0,9,0,100,0,0,30,21000,25000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hitah\'ya the Keeper - Within 0-30 Range - Cast Shadow Word: Pain"),
(10802,0,1,0,0,0,100,0,0,0,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hitah\'ya the Keeper - In Combat - Cast Shadow Bolt"),
(10802,0,2,0,14,0,100,0,1400,40,12000,18000,11,11640,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hitah\'ya the Keeper - Friendly At 1400 Health - Cast Renew"),
(10802,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hitah\'ya the Keeper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vilebranch Kidnapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14748;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14748 AND `source_type`=0;;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14748,0,0,0,12,0,100,1,0,20,0,0,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Kidnapper - Target Between 0-20% Health - Cast Execute (No Repeat)"),
(14748,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Kidnapper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(14748,0,2,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Kidnapper - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=14748;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14748,0,0,"Another fool falls for the trap!",12,0,100,0,0,0,10003,0,"Vilebranch Kidnapper"),
(14748,0,1,"Dinner has arrived!",12,0,100,0,0,0,10004,0,"Vilebranch Kidnapper"),
(14748,0,2,"The High Priestess will feast on your bones!",12,0,100,0,0,0,10005,0,"Vilebranch Kidnapper");
