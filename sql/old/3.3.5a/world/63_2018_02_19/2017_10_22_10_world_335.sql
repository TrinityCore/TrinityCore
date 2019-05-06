-- Hissperak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14227;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14227 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14227,0,0,0,0,0,100,0,8000,12000,24000,28000,11,11020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hissperak - In Combat - Cast Petrify");

-- Crusty
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18241;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18241 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18241,0,0,0,0,0,100,0,8000,12000,16000,22000,11,5424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crusty - In Combat - Cast Claw Grasp"),
(18241,0,1,0,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusty - Between 0-20% Health - Cast Enrage (No Repeat)"),
(18241,0,2,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusty - Between 0-20% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=18241;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18241,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Crusty");

-- Giggler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14228;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14228 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14228,0,0,0,0,0,100,0,6000,8000,6000,8000,11,3150,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giggler - In Combat - Cast Rabies");

-- Kaskk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14226;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14226 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14226,0,0,0,9,0,100,0,0,8,28000,34000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kaskk - Within 0-8 Range - Cast Demoralizing Shout"),
(14226,0,1,0,0,0,100,0,6000,9000,10000,16000,11,22859,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaskk - In Combat - Cast Mortal Cleave");

-- Accursed Slitherblade
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=32768 WHERE `entry`=14229;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14229 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14229,0,0,0,0,0,100,0,5000,8000,10000,15000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Accursed Slitherblade - In Combat - Cast Localized Toxin");

-- Tyranis Malem
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5643;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5643 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5643,0,0,0,0,0,100,0,0,0,3400,4800,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tyranis Malem - In Combat - Cast Wrath"),
(5643,0,1,0,0,0,100,0,7000,11000,15000,19000,11,15798,2,0,0,0,0,2,0,0,0,0,0,0,0,"Tyranis Malem - In Combat - Cast Moonfire"),
(5643,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tyranis Malem - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Prince Kellen
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=2 WHERE `entry`=14225;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14225 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14225,0,0,0,0,0,100,0,0,0,3400,4800,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Kellen - In Combat - Cast Fel Fireball"),
(14225,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Kellen - Between 0-30% Health - Cast Enrage (No Repeat)"),
(14225,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Kellen - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=14225;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14225,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Prince Kellen");

-- Jugkar Grim'rod
UPDATE `creature_template` SET `AIName`="SmartAI",  `flags_extra`=0 WHERE `entry`=5771;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5771 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5771,0,0,0,0,0,100,0,0,0,3400,4800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jugkar Grim'rod - In Combat - Cast Shadow Bolt"),
(5771,0,1,0,0,0,100,0,7000,9000,120000,130000,11,12741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jugkar Grim'rod - In Combat - Cast Curse of Weakness"),
(5771,0,2,0,0,0,100,0,11000,14000,23000,28000,11,20787,0,0,0,0,0,5,0,0,0,0,0,0,0,"Jugkar Grim'rod - In Combat - Cast Immolate"),
(5771,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jugkar Grim'rod - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lord Azrethoc
DELETE FROM `smart_scripts` WHERE `entryorguid`=5760 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5760,0,1,0,0,0,100,0,12000,16000,18000,24000,11,7961,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Azrethoc - In Combat - Cast Azrethoc's Stomp");

-- Hatefury Rogue
DELETE FROM `smart_scripts` WHERE `entryorguid`=4670 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4670,0,0,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Rogue - On Reset - Cast Stealth");

-- Hatefury Trickster
DELETE FROM `smart_scripts` WHERE `entryorguid`=4671 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4671,0,0,0,0,0,100,0,4000,12000,8000,16000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Trickster - In Combat - Cast Poison");

-- Hatefury Betrayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4673 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4673,0,2,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Betrayer - In Combat - Cast Shoot");

-- Hatefury Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=4674 AND `source_type`=0 AND `id` IN (0,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4674,0,0,0,0,0,100,0,5000,8000,13000,17000,11,8629,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Shadowstalker - In Combat - Cast Gouge"),
(4674,0,3,0,9,0,100,0,0,5,10000,14000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Shadowstalker - Within 0-5 Range - Cast Exploit Weakness");

-- Hatefury Hellcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=4675 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4675,0,0,0,0,0,100,0,6000,12000,15000,19000,11,1094,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Cast Immolate"),
(4675,0,1,0,0,0,100,0,12000,15000,12000,15000,11,5740,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Cast Rain of Fire"),
(4675,0,2,3,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-30% Health - Cast Enrage (No Repeat)"),
(4675,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-30% Health - Say Line 0 (No Repeat)");

-- Gritjaw Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4728 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4728,0,0,0,0,0,100,0,8000,12000,25000,35000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gritjaw Basilisk - In Combat - Cast Crystalline Slumber");

-- Hulking Gritjaw Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4729 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4729,0,0,0,0,0,100,0,8000,12000,25000,35000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hulking Gritjaw Basilisk - In Combat - Cast Crystalline Slumber");

-- Burning Blade Summoner
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4668 AND `source_type`=0 AND `id`=1;

-- Burning Blade Adept
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4665 AND `source_type`=0 AND `id`=0;

-- Burning Blade Augur
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4663 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param3`=15000 WHERE `entryorguid`=4663 AND `source_type`=0 AND `id`=1;

-- Burning Blade Shadowmage
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4667 AND `source_type`=0 AND `id`=0;

-- Burning Blade Reaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=4664 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4664,0,0,0,0,0,100,0,5000,7000,8000,11000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Reaver - In Combat - Cast Arcing Smash");

-- Random movement for some creatures
UPDATE `creature` SET `MovementType`=1, `spawndist`=8 WHERE `guid` IN (51848, 51850);
UPDATE `creature` SET `MovementType`=1, `spawndist`=20 WHERE `guid` IN (51849, 51846, 51847, 27825);

-- Fix spawn position for some creatures
UPDATE `creature` SET `position_x`=-351.133, `position_y`=812.029, `position_z`=96.3967, `orientation`=0.220683 WHERE `guid`=27852;
UPDATE `creature` SET `position_z`=97.3841 WHERE `guid`=27854;

-- Add waypoint movement to Burning Blade Felsworn
UPDATE `creature` SET `MovementType`=2, `spawndist`=0 WHERE `guid`=27713;
UPDATE `creature_addon` SET `path_id`=277130 WHERE `guid`=27713;

DELETE FROM `waypoint_data` WHERE `id`=277130;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(277130,1,-404.629,1839.69,128.402,0,0,0,0,100,0),
(277130,2,-398.871,1849.86,128.408,0,0,0,0,100,0),
(277130,3,-399.184,1868.68,128.409,0,0,0,0,100,0),
(277130,4,-414.135,1876.57,128.409,0,0,0,0,100,0),
(277130,5,-426.609,1867.71,128.409,0,0,0,0,100,0),
(277130,6,-433.731,1854.44,128.407,0,0,0,0,100,0),
(277130,7,-426.651,1844.51,128.407,0,0,0,0,100,0),
(277130,8,-414.903,1839.9,128.408,0,0,0,0,100,0);
