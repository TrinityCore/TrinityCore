-- Ghostpaw Alpha
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3825;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3825 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3825,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - Between 0-30% Health - Cast Enrage (No Repeat)"),
(3825,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3825;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3825,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Ghostpaw Alpha");

-- Wildthorn Stalker
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=15000 WHERE `entryorguid`=3819 AND `source_type`=0 AND `id`=0;

-- Wildthorn Venomspitter
DELETE FROM `smart_scripts` WHERE `entryorguid`=3820 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3820,0,0,0,0,0,100,0,1000,2000,3500,5000,11,6917,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildthorn Venomspitter - In Combat - Cast Venom Spit");

-- Wrathtail Sorceress
DELETE FROM `smart_scripts` WHERE `entryorguid`=3717 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3717,0,1,0,9,0,100,0,0,8,12000,13000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Within 0-8 Range - Cast Frost Nova");

-- Wrathtail Priestess
DELETE FROM `smart_scripts` WHERE `entryorguid`=3944 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3944,0,1,0,14,0,100,0,250,40,25000,35000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Wrathtail Priestess - Friendly At 250 Health - Cast Heal");

-- Blackfathom Tide Priestess
UPDATE `smart_scripts` SET `event_param2`=40, `comment`="Blackfathom Tide Priestess - Between 0-40% Health - Cast Heal" WHERE `entryorguid`=4802 AND `source_type`=0 AND `id`=1;

-- Fallenroot Satyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4788;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4788 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4788,0,0,0,0,0,100,0,4000,10000,18000,24000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallenroot Satyr - In Combat - Cast Disarm");

-- Fallenroot Rogue
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4789;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4789 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4789,0,0,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Rogue - On Reset - Cast Stealth"),
(4789,0,1,0,0,0,100,0,6000,10000,8000,14000,11,6205,32,0,0,0,0,4,0,0,0,0,0,0,0,"Fallenroot Rogue - In Combat - Cast Curse of Weakness");

-- Blackfathom Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4803 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4803,0,0,0,0,0,100,0,3000,6000,25000,30000,11,8363,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackfathom Oracle - In Combat - Cast Parasite"),
(4803,0,1,0,2,0,100,0,0,40,18000,24000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Oracle - Between 0-40% Health - Cast Healing Wave"),
(4803,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Forsaken Seeker
DELETE FROM `smart_scripts` WHERE `entryorguid`=3732 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3732,0,1,0,14,0,100,1,200,40,0,0,11,2054,1,0,0,0,0,7,0,0,0,0,0,0,0,"Forsaken Seeker - Friendly At 200 Health - Cast Heal (No Repeat)");

-- Dark Strand Cultist
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3725 AND `source_type`=0 AND `id`=1;

-- Dark Strand Adept
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3728 AND `source_type`=0 AND `id`=1;

-- Saltspittle Puddlejumper
DELETE FROM `smart_scripts` WHERE `entryorguid`=3737 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3737,0,0,0,1,0,100,1,1000,1000,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Puddlejumper - Out of Combat - Cast Battle Stance (No Repeat)");

-- Saltspittle Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=3742 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3742,0,0,0,0,0,100,0,4000,6000,8000,12000,11,2608,2,0,0,0,0,2,0,0,0,0,0,0,0,"Saltspittle Oracle - In Combat - Cast Shock"),
(3742,0,1,0,14,0,100,0,250,40,20000,25000,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Saltspittle Oracle - Friendly At 250 Health - Cast Healing Wave");

-- Mugglefin
DELETE FROM `smart_scripts` WHERE `entryorguid`=10643 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10643,0,0,0,0,0,100,0,7000,11000,9000,15000,11,3584,32,0,0,0,0,4,0,0,0,0,0,0,0,"Mugglefin - In Combat - Cast Volatile Infection");

-- Felslayer
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=18000 WHERE `entryorguid`=3774 AND `source_type`=0 AND `id`=0;

-- Thistlefur Avenger
DELETE FROM `smart_scripts` WHERE `entryorguid`=3925 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3925,0,0,0,25,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Reset - Cast Coat of Thistlefur"),
(3925,0,1,0,38,0,100,1,1,1,0,0,11,8602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Data Set - Cast Vengeance (No Repeat)"),
(3925,0,2,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Data Set - Say Line 0 (No Repeat)"),
(3925,0,3,0,2,0,100,1,0,30,0,0,11,8602,32,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - Between 0-30% Health - Cast Vengeance (No Repeat)"),
(3925,0,4,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,3925,8,0,0,0,0,0,"Thistlefur Avenger - On Death - Set Data");

-- Thistlefur Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=3924 AND `source_type`=0 AND `id` IN (1,2,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3924,0,1,0,0,0,100,0,3000,8000,30000,35000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Shaman - In Combat - Cast Bloodlust"),
(3924,0,2,0,14,0,100,0,300,40,20000,25000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thistlefur Shaman - Friendly At 300 Health - Cast Healing Wave"),
(3924,0,4,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,3925,8,0,0,0,0,0,"Thistlefur Shaman - On Death - Set Data");

-- Thistlefur Pathfinder
DELETE FROM `smart_scripts` WHERE `entryorguid`=3926 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3926,0,3,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,3925,8,0,0,0,0,0,"Thistlefur Pathfinder - On Death - Set Data");

-- Dal Bloodclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=3987 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3987,0,0,0,25,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - On Reset - Cast Coat of Thistlefur"),
(3987,0,1,0,0,0,100,0,6000,8000,12000,16000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dal Bloodclaw - In Combat - Cast Disarm"),
(3987,0,2,0,2,0,100,1,0,50,0,0,39,40,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-50% Health - Call For Help (No Repeat)"),
(3987,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-30% Health - Cast Enrage (No Repeat)"),
(3987,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-30% Health - Say Line 0 (No Repeat)"),
(3987,0,5,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,3925,8,0,0,0,0,0,"Dal Bloodclaw - On Death - Set Data");

DELETE FROM `creature_text` WHERE `CreatureID`=3987;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3987,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Dal Bloodclaw");

-- Thistlefur Ursa
UPDATE `smart_scripts` SET `event_param3`=13000, `event_param4`=18000, `target_type`=2 WHERE `entryorguid`=3921 AND `source_type`=0 AND `id`=2;

-- Thistlefur Totemic
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=10000, `event_param3`=32000, `event_param4`=40000 WHERE `entryorguid`=3922 AND `source_type`=0 AND `id`=1;

-- Shadethicket Moss Eater
DELETE FROM `smart_scripts` WHERE `entryorguid`=3780 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3780,0,0,0,25,0,100,0,0,0,0,0,11,6867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadethicket Moss Eater - On Reset - Cast Moss Covered Hands Proc"),
(3780,0,1,0,25,0,100,0,0,0,0,0,11,6871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadethicket Moss Eater - On Reset - Cast Moss Covered Feet Proc");

-- Shadethicket Raincaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=3783 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3783,0,0,0,0,0,100,0,2000,4000,8000,12000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Raincaller - In Combat - Cast Lightning Bolt"),
(3783,0,1,0,0,0,100,0,8000,10000,24000,35000,11,6535,0,0,0,0,0,4,0,0,0,0,0,0,0,"Shadethicket Raincaller - In Combat - Cast Lightning Cloud");

-- Branch Snapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=10641 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10641,0,0,0,25,0,100,0,0,0,0,0,11,10022,0,0,0,0,0,1,0,0,0,0,0,0,0,"Branch Snapper - On Reset - Cast Deadly Poison");

-- Foulweald Den Watcher
DELETE FROM `smart_scripts` WHERE `entryorguid`=3746 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3746,0,1,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Den Watcher - On Reset - Cast Thrash");

-- Foulweald Totemic
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=10000, `event_param3`=40000, `event_param4`=45000 WHERE `entryorguid`=3750 AND `source_type`=0 AND `id`=1;

-- Befouled Water Elemental
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=3917;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3917 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3917,0,0,0,0,0,100,0,4000,8000,12000,16000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Raincaller - In Combat - Cast Frostbolt"),
(3917,0,1,0,9,0,100,0,0,5,14000,18000,11,6873,32,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Raincaller - Within 0-5 Range - Cast Foul Chill");

-- Tideress
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12759;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12759 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12759,0,0,0,0,0,100,0,4000,8000,12000,16000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tideress - In Combat - Cast Frostbolt"),
(12759,0,1,0,9,0,100,0,0,5,14000,18000,11,6873,32,0,0,0,0,2,0,0,0,0,0,0,0,"Tideress - Within 0-5 Range - Cast Foul Chill");

-- Eck'alom
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=10642;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10642 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10642,0,1,0,0,0,100,0,12000,16000,28000,34000,11,5276,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eck'alom - In Combat - Cast Freeze");

-- Cenarion Protector
DELETE FROM `smart_scripts` WHERE `entryorguid`=3797 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3797,0,0,0,1,0,100,0,1000,3000,1000,3000,11,7090,34,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Out of Combat - Cast Bear Form"),
(3797,0,1,0,0,0,100,0,1000,3000,1000,3000,11,7090,34,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - In Combat - Cast Bear Form"),
(3797,0,2,0,0,0,100,0,8000,18000,19000,24000,11,15727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - In Combat - Cast Demoralizing Roar"),
(3797,0,3,0,2,0,100,0,0,50,18000,21000,75,1430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-50% Health - Add Aura Rejuvenation"),
(3797,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Blink Dragon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3815;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3815 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3815,0,0,0,2,0,100,0,0,50,14000,21000,11,8611,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blink Dragon - Between 0-50% Health - Cast Phase Shift");

-- Cenarion Vindicator
UPDATE `smart_scripts` SET `event_param1`=9000, `event_param2`=13000, `event_param3`=15000, `event_param4`=25000 WHERE `entryorguid`=3833 AND `source_type`=0 AND `id`=0;

-- Keeper Ordanus
DELETE FROM `smart_scripts` WHERE `entryorguid`=4273 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4273,0,1,0,9,0,100,0,0,30,9000,11000,11,12747,2,0,0,0,0,5,0,0,0,0,0,0,0,"Keeper Ordanus - Within 0-30 Range - Cast Entangling Roots");

-- Oakpaw
UPDATE `smart_scripts` SET `event_param4`=18000 WHERE `entryorguid`=10640 AND `source_type`=0 AND `id`=0;

-- Bloodtooth Guard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3932;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3932 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3932,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtooth Guard - Between 0-30% Health - Cast Enrage (No Repeat)"),
(3932,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtooth Guard - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=3932;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3932,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Bloodtooth Guard");

-- Bleakheart Hellcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=3771 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (377100, 377101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3771,0,0,0,1,0,100,1,1000,1000,0,0,87,377100,377101,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Run Random Script"),
(3771,0,1,0,0,0,100,0,4000,6000,8000,12000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleakheart Hellcaller - In Combat - Cast Scorch"),
(3771,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(377100,9,0,0,0,0,100,0,0,0,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - On Script - Cast Summon Imp"),
(377101,9,0,0,0,0,100,0,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - On Script - Cast Summon Voidwalker");

-- Prince Raze
DELETE FROM `smart_scripts` WHERE `entryorguid`=10647 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10647,0,0,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - In Combat CMC - Cast Fireball"),
(10647,0,1,0,0,0,100,0,8000,9000,21000,25000,11,16570,0,0,0,0,0,5,0,0,0,0,0,0,0,"Prince Raze - In Combat - Cast Charged Arcane Bolt"),
(10647,0,2,0,9,0,100,0,0,8,12000,18000,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Within 0-8 Range - Cast Fire Nova"),
(10647,0,3,0,2,0,100,1,0,15,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-15% Health - Cast Gift of the Xavian (No Repeat)");

-- Xavian Rogue
DELETE FROM `smart_scripts` WHERE `entryorguid`=3752 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3752,0,0,0,9,0,100,0,0,5,10000,13000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Rogue - Within 0-5 Range - Cast Exploit Weakness"),
(3752,0,1,0,2,0,100,0,0,15,12000,19000,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Rogue - Between 0-15% Health - Cast Gift of the Xavian");

-- Xavian Betrayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=3754 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3754,0,0,0,0,0,100,0,7000,9000,23000,37000,11,5242,2,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Betrayer - In Combat - Cast Battle Shout"),
(3754,0,1,0,2,0,100,0,0,15,12000,19000,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Betrayer - Between 0-15% Health - Cast Gift of the Xavian");

-- Xavian Felsworn
DELETE FROM `smart_scripts` WHERE `entryorguid`=3755 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3755,0,0,0,0,0,100,0,2000,4000,3000,5000,11,6223,32,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Felsworn - In Combat - Cast Corruption"),
(3755,0,1,0,2,0,100,0,0,15,12000,19000,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Felsworn - Between 0-15% Health - Cast Gift of the Xavian");

-- Xavian Hellcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=3757 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3757,0,0,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Hellcaller - In Combat - Cast Fireball"),
(3757,0,1,0,2,0,100,0,0,15,12000,19000,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Cast Gift of the Xavian");

-- Geltharis
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=2 WHERE `entry`=4619;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4619 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4619,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Geltharis - In Combat - Cast Fel Fireball"),
(4619,0,1,0,9,0,100,0,0,30,17000,21000,11,37628,2,0,0,0,0,2,0,0,0,0,0,0,0,"Geltharis - Within 0-30 Range - Cast Fel Immolate"),
(4619,0,2,0,9,0,100,0,0,10,6000,8000,11,7098,34,0,0,0,0,5,0,0,0,0,0,0,0,"Geltharis - Within 0-10 Range - Cast Curse of Mending"),
(4619,0,3,0,2,0,100,0,0,20,15000,25000,11,6925,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geltharis - Between 0-20% Health - Cast Gift of the Xavian");

-- Ashenvale Outrunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=12856 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12856,0,3,0,25,0,100,0,0,0,0,0,11,20540,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - On Reset - Cast Ashenvale Outrunner Sneak");

-- Severed Keeper
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=19000 WHERE `entryorguid`=3803 AND `source_type`=0 AND `id`=0;

-- Taneel Darkwood
UPDATE `smart_scripts` SET `event_param3`=17000, `event_param4`=21000 WHERE `entryorguid`=3940 AND `source_type`=0 AND `id`=0;

-- Mannoroc Lasher
DELETE FROM `smart_scripts` WHERE `entryorguid`=11697 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11697,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mannoroc Lasher - In Combat - Cast Shadow Bolt"),
(11697,0,1,0,9,0,100,0,0,30,18000,24000,11,18543,2,0,0,0,0,2,0,0,0,0,0,0,0,"Mannoroc Lasher - Within 0-30 Range - Cast Flame Lash");

-- Diathorus the Seeker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6072;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6072 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6072,0,0,0,0,0,100,0,8000,12000,7000,13000,11,37624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Diathorus the Seeker - In Combat - Cast Carrion Swarm"),
(6072,0,1,0,2,0,100,0,0,75,18000,26000,11,17620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Diathorus the Seeker - Between 0-75% Health - Cast Drain Life");

-- Random movement for some creatures
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `guid` IN (32879, 34224, 32332, 33235, 33237);
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `guid` IN (51884, 33236);

-- Correct spawn position and add random movement for some creatures
UPDATE `creature` SET `position_x`=2724.74, `position_y`=693.129, `position_z`=110.271, `MovementType`=1, `spawndist`=5 WHERE `guid`=34982;
UPDATE `creature` SET `position_x`=344.121, `position_y`=-2341.81, `position_z`=214.561, `MovementType`=1, `spawndist`=5 WHERE `guid`=19550;

-- Remove wrong mount for Forsaken Thug
UPDATE `creature_addon` SET `mount`=0, `bytes2`=4097 WHERE `guid` IN (32905, 32906, 32907, 32908, 32909, 32910);
UPDATE `creature_template_addon` SET `mount`=0, `bytes2`=4097 WHERE `entry`=3734;

-- Correct equipment for Wrathtail Razortail
UPDATE `creature_equip_template` SET `ItemID1`=1899 WHERE `CreatureID`=3712;

-- Add equipment to Ruuzel
DELETE FROM `creature_equip_template` WHERE `CreatureID`=3943;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(3943,1,5747,0,0,0);

-- Add waypoint movement to Ruuzel
UPDATE `creature` SET `position_x`=4157.59, `position_y`=1272.73, `position_z`=3.22775, `MovementType`=2 WHERE `guid`=32617;
UPDATE `creature` SET `position_x`=4158.46, `position_y`=1274.85, `position_z`=3.35226 WHERE `guid`=32762;
UPDATE `creature` SET `position_x`=4159.55, `position_y`=1271.75, `position_z`=3.00348 WHERE `guid`=32728;
UPDATE `creature_addon` SET `path_id`=326170, `bytes2`=4097 WHERE `guid`=32617;

DELETE FROM `creature_formations` WHERE `leaderGUID`=32617;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(32617,32617,0,0,2,0,0),
(32617,32762,3,60,2,0,0),
(32617,32728,3,330,2,0,0);

DELETE FROM `waypoint_data` WHERE `id`=326170;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(326170,1,4157.59,1272.73,3.22775,0,0,0,0,100,0),
(326170,2,4118.6,1268.22,1.93513,0,0,0,0,100,0),
(326170,3,4100.35,1277.8,1.42555,0,0,0,0,100,0),
(326170,4,4090.54,1314.88,2.11756,0,0,0,0,100,0),
(326170,5,4098.61,1352.27,2.58844,0,0,0,0,100,0),
(326170,6,4116.9,1363.47,1.69482,0,0,0,0,100,0),
(326170,7,4133.67,1375.35,2.18856,0,0,0,0,100,0),
(326170,8,4176.57,1370.93,2.58461,0,0,0,0,100,0),
(326170,9,4221.99,1339.24,2.22232,0,0,0,0,100,0),
(326170,10,4225.52,1317.01,1.90514,0,0,0,0,100,0),
(326170,11,4206.5,1285.38,1.3025,0,0,0,0,100,0),
(326170,12,4185.92,1278.95,1.27956,0,0,0,0,100,0),
(326170,13,4168.32,1281.27,3.36765,0,0,0,0,100,0);
