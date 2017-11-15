/*
-- Stonard Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=861;
DELETE FROM `smart_scripts` WHERE `entryorguid`=861 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(861,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonard Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Stonard Explorer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=862;
DELETE FROM `smart_scripts` WHERE `entryorguid`=862 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(862,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonard Explorer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Adolescent Whelp
DELETE FROM `smart_scripts` WHERE `entryorguid`=740 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(740,0,0,0,0,0,100,0,0,0,3400,4800,11,20821,64,0,0,0,0,2,0,0,0,0,0,0,0,"Adolescent Whelp - In Combat - Cast Acid Spit");

-- Dreaming Whelp
DELETE FROM `smart_scripts` WHERE `entryorguid`=741 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(741,0,0,0,0,0,100,0,0,0,3400,4800,11,20821,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreaming Whelp - In Combat - Cast Acid Spit");

-- Dreamwatcher Forktongue
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5348 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5348,0,0,0,4,0,100,0,0,0,0,0,11,15114,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreamwatcher Forktongue - On Aggro - Cast Summon Illusionary Dreamwatchers");

-- Sorrow Spinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=858;
DELETE FROM `smart_scripts` WHERE `entryorguid`=858 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(858,0,0,0,9,0,100,0,0,30,8000,12000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorrow Spinner - Within 0-30 Range - Cast Web"),
(858,0,1,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sorrow Spinner - On Reset - Cast Poison Proc");

-- Deathstrike Tarantula
DELETE FROM `smart_scripts` WHERE `entryorguid`=769 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(769,0,0,0,12,0,100,0,0,20,16000,21000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathstrike Tarantula - Target Between 0-20% Health - Cast Fatal Bite"),
(769,0,1,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathstrike Tarantula - On Reset - Cast Poison Proc");

-- Sawtooth Snapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1087;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1087 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1087,0,0,0,0,0,100,0,5000,8000,11000,14000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sawtooth Snapper - In Combat - Cast Tendon Rip");

-- Swampwalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=764;
DELETE FROM `smart_scripts` WHERE `entryorguid`=764 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(764,0,0,0,2,0,100,1,0,50,20000,25000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swampwalker - Between 0-50% Health - Cast Wild Regeneration");

-- Swampwalker Elder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=765;
DELETE FROM `smart_scripts` WHERE `entryorguid`=765 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(765,0,0,0,2,0,100,1,0,50,20000,25000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swampwalker Elder - Between 0-50% Health - Cast Wild Regeneration");

-- Tangled Horror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=766;
DELETE FROM `smart_scripts` WHERE `entryorguid`=766 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(766,0,0,0,2,0,100,1,0,50,20000,25000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tangled Horror - Between 0-50% Health - Cast Wild Regeneration");

-- Draenei Protector
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17531 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17531,0,0,0,0,0,100,0,5000,7000,9000,13000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Draenei Protector - In Combat - Cast Heroic Strike"),
(17531,0,1,0,9,0,100,0,0,5,5000,9000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Draenei Protector - Within 0-5 Range - Cast Sunder Armor");

-- Molt Thorn
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14448;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14448 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14448,0,0,0,0,0,100,0,4000,6000,8000,11000,11,21748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molt Thorn - In Combat - Cast Thorn Volley");

-- Lost One Mudlurker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=755;
DELETE FROM `smart_scripts` WHERE `entryorguid`=755 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(755,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Mudlurker - Between 0-15% Health - Flee For Assist (No Repeat)"),
(755,0,1,0,67,0,100,0,5000,9000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost One Mudlurker - On Behind Target - Cast Backstab");

-- Lost One Fisherman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=757;
DELETE FROM `smart_scripts` WHERE `entryorguid`=757 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(757,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Fisherman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lost One Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=759;
DELETE FROM `smart_scripts` WHERE `entryorguid`=759 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(759,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(759,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lost One Hunter - In Combat - Cast Shoot"),
(759,0,2,0,0,0,100,0,3000,5000,8000,14000,11,8806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost One Hunter - In Combat - Cast Poisoned Shot");

-- Lost One Muckdweller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=760;
DELETE FROM `smart_scripts` WHERE `entryorguid`=760 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(760,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Muckdweller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(760,0,1,0,6,0,100,1,0,0,0,0,11,3256,3,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Muckdweller - On Just Died - Cast Plague Cloud");

-- Lost One Seer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=761;
DELETE FROM `smart_scripts` WHERE `entryorguid`=761 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(761,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Seer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(761,0,1,0,0,0,100,0,3000,6000,30000,40000,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Seer - In Combat - Cast Earthgrab Totem"),
(761,0,2,0,0,0,100,0,11000,15000,30000,40000,11,4971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Seer - In Combat - Cast Healing Ward");

-- Lost One Riftseeker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=762;
DELETE FROM `smart_scripts` WHERE `entryorguid`=762 AND `source_type`=0  AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(762,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Riftseeker - Between 0-15% Health - Flee For Assist (No Repeat)"),
(762,0,2,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lost One Riftseeker - In Combat - Cast Shadow Bolt"),
(762,0,3,0,9,0,100,0,0,30,65000,70000,11,9614,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lost One Riftseeker - Within 0-30 Range - Cast Rift Beacon");

-- Lost One Chieftain
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=763;
DELETE FROM `smart_scripts` WHERE `entryorguid`=763 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(763,0,0,0,2,0,100,1,0,30,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lost One Chieftain - Between 0-30% Health - Call for Help (No Repeat)");

-- Cursed Lost One
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17115 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17115,0,0,0,0,0,100,0,6000,8000,9000,13000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Lost One - In Combat - Cast Disarm"),
(17115,0,1,0,0,0,100,0,3000,5000,13000,20000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Lost One - In Combat - Cast Curse of Agony");

-- Lost One Cook
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1106;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1106 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1106,0,0,0,0,0,100,0,3000,5000,9000,14000,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lost One Cook - In Combat - Cast Immolate"),
(1106,0,1,0,9,0,100,0,0,5,8000,11000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost One Cook - Within 0-5 Range - Cast Knockdown");

-- Lord Captain Wyrmak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14445;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14445 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14445,0,0,0,0,0,100,0,9000,12000,9000,12000,11,12533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Captain Wyrmak - In Combat - Cast Acid Breath"),
(14445,0,1,0,9,0,100,0,0,5,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Captain Wyrmak - Within 0-5 Range - Cast Cleave");

-- Green Wyrmkin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=742;
DELETE FROM `smart_scripts` WHERE `entryorguid`=742 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(742,0,0,0,0,0,100,0,5000,12000,30000,40000,11,6306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Wyrmkin - In Combat - Cast Acid Splash");

-- Wyrmkin Dreamwalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=743;
DELETE FROM `smart_scripts` WHERE `entryorguid`=743 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(743,0,0,0,0,0,100,0,6000,11000,15000,18000,11,15970,0,0,0,0,0,6,0,0,0,0,0,0,0,"Wyrmkin Dreamwalker - In Combat - Cast Sleep"),
(743,0,1,0,0,0,100,0,1000,3000,62000,68000,11,7966,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmkin Dreamwalker - In Combat - Cast Thorns Aura"),
(743,0,2,0,14,0,100,0,1000,40,12000,15000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wyrmkin Dreamwalker - Friendly At 1000 Health - Cast Rejuvenation");

-- Green Scalebane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=744;
DELETE FROM `smart_scripts` WHERE `entryorguid`=744 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(744,0,0,0,0,0,100,0,5000,7000,6000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Scalebane - In Combat - Cast Cleave");

-- Elder Dragonkin
DELETE FROM `smart_scripts` WHERE `entryorguid`=746 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(746,0,0,0,0,0,100,0,5000,12000,30000,40000,11,6306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Dragonkin - In Combat - Cast Acid Splash");

-- Somnus
DELETE FROM `smart_scripts` WHERE `entryorguid`=12900 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12900,0,0,0,0,0,100,0,6000,8000,14000,17000,11,20989,0,0,0,0,0,6,0,0,0,0,0,0,0,"Somnus - In Combat - Cast Sleep"),
(12900,0,1,0,0,0,100,0,13000,16000,18000,21000,11,12882,0,0,0,0,0,1,0,0,0,0,0,0,0,"Somnus - In Combat - Cast Wing Flap"),
(12900,0,2,0,0,0,100,0,9000,12000,14000,20000,11,20667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Somnus - In Combat - Cast Corrosive Acid Breath"),
(12900,0,3,0,0,0,100,0,7000,9000,12000,16000,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,"Somnus - In Combat - Cast Strike");

-- Marsh Inkspewer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=750;
DELETE FROM `smart_scripts` WHERE `entryorguid`=750 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(750,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Inkspewer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(750,0,1,0,0,0,100,0,5000,7000,9000,12000,11,9612,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Inkspewer - In Combat - Cast Ink Spray");

-- Marsh Inkspewer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=751;
DELETE FROM `smart_scripts` WHERE `entryorguid`=751 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(751,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Flesheater - Between 0-15% Health - Flee For Assist (No Repeat)"),
(751,0,1,0,2,0,100,1,0,40,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Flesheater - Between 0-40% Health - Cast Enrage (No Repeat)"),
(751,0,2,0,2,0,100,1,0,40,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Flesheater - Between 0-40% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=751;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(751,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Marsh Flesheater");

-- Marsh Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=752;
DELETE FROM `smart_scripts` WHERE `entryorguid`=752 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(752,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(752,0,1,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Oracle - In Combat - Cast Lightning Bolt"),
(752,0,2,0,14,0,100,0,1200,40,12000,16000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Marsh Oracle - Friendly At 1200 Health - Cast Healing Wave"),
(752,0,3,0,23,0,100,0,12550,0,1000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Oracle - On Has No Aura Lightning Shield - Cast Lightning Shield");

-- Swamp Talker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=950;
DELETE FROM `smart_scripts` WHERE `entryorguid`=950 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(950,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swamp Talker - Between 0-15% Health - Flee For Assist (No Repeat)"),
(950,0,1,0,0,0,100,0,1000,3000,15000,20000,11,9636,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swamp Talker - In Combat - Cast Summon Swamp Spirit");

-- Jarquia
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9916;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9916 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9916,0,0,0,2,0,100,1,0,40,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jarquia - Between 0-40% Health - Cast Enrage (No Repeat)"),
(9916,0,1,0,2,0,100,1,0,40,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jarquia - Between 0-40% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=9916;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9916,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Jarquia");

-- Jade
DELETE FROM `smart_scripts` WHERE `entryorguid`=1063 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1063,0,1,0,0,0,100,0,3000,5000,8000,11000,11,12533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jade - In Combat - Cast Acid Breath");

-- Murk Slitherer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5224;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5224 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5224,0,0,0,0,0,100,0,5000,7000,8000,11000,11,13518,32,0,0,0,0,2,0,0,0,0,0,0,0,"Murk Slitherer - In Combat - Cast Poison");

-- Murk Spitter
DELETE FROM `smart_scripts` WHERE `entryorguid`=5225 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5225,0,0,0,0,0,100,0,0,0,3400,4800,11,6917,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murk Spitter - In Combat - Cast Venom Spit");

-- Kazkaz the Unholy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5401 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5401,0,0,0,0,0,100,0,3000,5000,7000,16000,11,11639,32,0,0,0,0,2,0,0,0,0,0,0,0,"Kazkaz the Unholy - In Combat - Cast Shadow Word: Pain"),
(5401,0,1,0,0,0,100,0,6000,9000,18000,24000,11,7645,0,0,0,0,0,6,0,0,0,0,0,0,0,"Kazkaz the Unholy - In Combat - Cast Dominate Mind"),
(5401,0,2,0,0,0,100,0,0,0,12000,15000,11,14887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kazkaz the Unholy - In Combat - Cast Shadow Bolt Volley");

-- Atal'ai Priest
DELETE FROM `smart_scripts` WHERE `entryorguid`=5269 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5269,0,0,0,0,0,100,0,6000,15000,17000,26000,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - In Combat - Cast Shadow Shield"),
(5269,0,1,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - In Combat - Cast Shadow Bolt");

-- Correct spawn position and add random movement for one creature
UPDATE `creature` SET `position_x`=-10157, `position_y`=-2822.25, `position_z`=21.7076, `MovementType`=1, `spawndist`=5 WHERE `guid`=38918;

-- Increase movement range for Sawfin Frenzy
UPDATE `creature` SET `spawndist`=20 WHERE `id`=14356;
*/
