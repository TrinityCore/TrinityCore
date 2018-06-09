-- Deadwood Den Watcher
DELETE FROM `smart_scripts` WHERE `entryorguid`=7156 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7156,0,1,0,2,0,100,1,0,50,0,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Den Watcher - Between 0-50% Health - Call For Help (No Repeat)");

-- Overlord Ror
DELETE FROM `smart_scripts` WHERE `entryorguid`=9464 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9464,0,2,0,2,0,100,1,0,50,0,0,0,39,40,1,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ror - Between 0-50% Health - Call For Help (No Repeat)");

-- Duskwing
DELETE FROM `smart_scripts` WHERE `entryorguid`=11897 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11897,0,1,0,0,0,100,0,6000,9000,14000,17000,0,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duskwing - In Combat - Cast 'Sonic Burst'");

-- Unseen Servant
UPDATE `smart_scripts` SET `action_param1`=30991 WHERE `entryorguid`=8538 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8538 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8538,0,3,0,25,0,100,0,0,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unseen Servant - On Reset - Cast 'Stealth Detection'");

-- Rotting Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=1793 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1793,0,1,0,25,0,100,0,0,0,0,0,0,11,16800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Ghoul - On Reset - Cast 'Ghoul Rot'"),
(1793,0,2,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Ghoul - On Respawn - Cast 'Birth'");

-- Freezing Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=1796 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1796,0,1,0,23,0,100,0,12544,0,1000,3000,0,11,12544,2,0,0,0,0,1,0,0,0,0,0,0,0,"Freezing Ghoul - On Has No Aura 'Frost Armor' - Cast 'Frost Armor'"),
(1796,0,2,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freezing Ghoul - On Respawn - Cast 'Birth'");

-- Devouring Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=1808 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1808,0,1,0,0,0,100,0,5000,10000,15000,20000,0,11,12250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devouring Ooze - In Combat - Cast 'Summon Oozeling'");

-- Oozeling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8257;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8257 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8257,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Oozeling - Just Summoned - Start Attacking");

-- Fledgling Chillwind
DELETE FROM `smart_scripts` WHERE `entryorguid`=7447 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7447,0,0,0,0,0,100,0,1000,2000,2500,4500,0,11,16552,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fledgling Chillwind - In Combat - Cast 'Venom Spit'");

-- Cauldron Lord Bilemaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=11075 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11075,0,2,0,25,0,100,0,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cauldron Lord Bilemaw - On Reset - Cast 'Thrash'");

-- Slavering Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=1791 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1791,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slavering Ghoul - On Reset - Cast 'Thrash'"),
(1791,0,1,0,0,0,100,0,6000,9000,45000,60000,0,11,7125,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slavering Ghoul - In Combat - Cast 'Toxic Saliva'"),
(1791,0,2,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slavering Ghoul - On Respawn - Cast 'Birth'");

-- Scarlet Paladin
DELETE FROM `smart_scripts` WHERE `entryorguid`=1834 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1834,0,4,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Paladin - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1834;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1834,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Paladin"),
(1834,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Paladin"),
(1834,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Paladin"),
(1834,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Paladin");

-- Scarlet Priest
DELETE FROM `smart_scripts` WHERE `entryorguid`=10608 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10608,0,5,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Priest - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=10608;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10608,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Priest"),
(10608,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Priest"),
(10608,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Priest"),
(10608,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Priest");

-- Scarlet Sentinel
DELETE FROM `smart_scripts` WHERE `entryorguid`=1827 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1827,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sentinel - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1827;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1827,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Sentinel"),
(1827,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Sentinel"),
(1827,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Sentinel"),
(1827,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Sentinel");

-- Scarlet Spellbinder
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=4494 AND `source_type`=0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4494 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4494,0,4,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4494;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4494,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Spellbinder"),
(4494,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Spellbinder"),
(4494,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Spellbinder"),
(4494,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Spellbinder");

-- Scarlet Mage
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=1826 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1826 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1826,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1826;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1826,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Mage"),
(1826,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Mage"),
(1826,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Mage"),
(1826,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Mage");

-- Scarlet Avenger
DELETE FROM `smart_scripts` WHERE `entryorguid`=4493 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4493,0,0,0,25,0,100,0,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Avenger - On Reset - Cast 'Thrash'"),
(4493,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Avenger - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4493;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4493,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Avenger"),
(4493,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Avenger"),
(4493,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Avenger"),
(4493,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Avenger");

-- Scarlet Knight
DELETE FROM `smart_scripts` WHERE `entryorguid`=1833 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1833,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Knight - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1833;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1833,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Knight"),
(1833,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Knight"),
(1833,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Knight"),
(1833,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Knight");

-- Scarlet Medic
DELETE FROM `smart_scripts` WHERE `entryorguid`=10605 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10605,0,4,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=10605;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10605,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Medic"),
(10605,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Medic"),
(10605,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Medic"),
(10605,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Medic");

-- Scarlet Invoker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1835 AND `source_type`=0 AND `id` IN (0,1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1835,0,0,0,0,0,100,0,0,0,2000,4000,0,11,15736,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Invoker - In Combat - Cast 'Arcane Missiles'"),
(1835,0,1,0,9,0,100,0,0,8,12000,20000,0,11,11975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Invoker - Within 0-8 Range - Cast 'Arcane Explosion'"),
(1835,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Invoker - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1835;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1835,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Invoker"),
(1835,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Invoker"),
(1835,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Invoker"),
(1835,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Invoker");

-- Scarlet Hunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=1831 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1831,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1831;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1831,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Hunter"),
(1831,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Hunter"),
(1831,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Hunter"),
(1831,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Hunter");

-- Gibbering Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=8531 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8531,0,1,0,0,0,100,0,6000,12000,22000,28000,0,11,12889,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gibbering Ghoul - In Combat - Cast 'Curse of Tongues'");

-- Snarlflare
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14272;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14272 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14272,0,0,0,1,0,100,0,6000,10000,6000,10000,11,54293,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snarlflare - Out Of Combat - Cast 'Flame Breath'"),
(14272,0,1,0,0,0,100,0,4000,6000,8000,12000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snarlflare - Combat - Cast 'Flame Breath'");

-- Scarlet Smith
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1885;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1885 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1885,0,0,0,0,0,100,0,5000,7000,5000,7000,0,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Smith - In Combat - Cast 'Strike'"),
(1885,0,1,0,0,0,100,0,8000,11000,11000,14000,0,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Smith - In Combat - Cast 'Knockdown'"),
(1885,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Smith - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Spectral Attendant
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11873;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11873 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11873,0,0,0,0,0,100,0,0,0,3000,5000,0,11,13860,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Attendant - In Combat - Cast 'Mind Blast'"),
(11873,0,1,0,0,0,100,0,8000,11000,14000,17000,0,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Attendant - In Combat - Cast 'Mana Burn'"),
(11873,0,2,0,0,0,100,0,5000,7000,18000,21000,0,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Attendant - In Combat - Cast 'Cripple'");

-- The Husk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1851;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1851 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1851,0,0,0,0,0,100,0,9000,11000,20000,23000,0,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Husk - In Combat - Cast 'Tendon Rip'"),
(1851,0,1,0,0,0,100,0,5000,7000,12000,18000,0,11,17230,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Husk - In Combat - Cast 'Infected Wound'");

-- Dreadwhisper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1849;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1849 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1849,0,0,0,0,0,100,0,1000,2000,18000,21000,0,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadwhisper - In Combat - Cast 'Criple'"),
(1849,0,1,0,0,0,100,0,6000,7000,11000,13000,0,11,17228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadwhisper - In Combat - Cast 'Shadow Bolt Volley'"),
(1849,0,2,0,0,0,100,0,10000,12000,18000,21000,0,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadwhisper - In Combat - Cast 'Veil of Shadow'");

-- Putridius
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1850;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1850 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1850,0,0,0,0,0,100,0,11000,15000,18000,22000,0,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridius - In Combat - Cast 'Knock Away'"),
(1850,0,1,0,0,0,100,0,7000,10000,22000,28000,0,11,12946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putridius - In Combat - Cast 'Putrid Stench'"),
(1850,0,2,0,0,0,100,0,5000,7000,8000,12000,0,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridius - In Combat - Cast 'Uppercut'");

-- Venom Mist Lurker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1822;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1822 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1822,0,0,0,25,0,100,0,0,0,0,0,0,11,10022,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venom Mist Lurker - On Reset - Cast 'Deadly Poison'");

-- Skeletal Flayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=1783 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1783,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Flayer - On Reset - Cast 'Thrash'");

-- Soulless Ghoul
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=1794 AND `source_type`=0 AND `id`=2;

-- Searing Ghoul
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=1795 AND `source_type`=0 AND `id`=1;

-- Skeletal Acolyte
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=1789 AND `source_type`=0 AND `id`=0;

-- Diseased Black Bear
DELETE FROM `smart_scripts` WHERE `entryorguid`=1815 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1815,0,0,0,0,0,100,0,6000,9000,11000,14000,0,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Diseased Black Bear - In Combat - Cast 'Infected Wound'");

-- Diseased Grizzly
DELETE FROM `smart_scripts` WHERE `entryorguid`=1816 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1816,0,0,0,0,0,100,0,6000,9000,11000,14000,0,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Diseased Grizzly - In Combat - Cast 'Infected Wound'");

-- Skeletal Sorcerer
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=1784 AND `source_type`=0 AND `id`=0;

-- Dethryll Satyr
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `event_param3`=2000, `event_param4`=4000 WHERE `entryorguid`=2212 AND `source_type`=0 AND `id`=0;

-- Diseased Wolf
DELETE FROM `smart_scripts` WHERE `entryorguid`=1817 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1817,0,0,0,0,0,100,0,4000,9000,10000,15000,0,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Diseased Wolf - In Combat - Cast 'Infected Wound'");

-- Carrion Lurker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1821 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1821,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Carrion Lurker - On Reset - Cast 'Poison Proc'");

-- Large Vile Slime
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12387;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12387 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12387,0,0,0,0,0,100,0,0,0,3000,5000,0,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,"Large Vile Slime - In Combat - Cast 'Arcane Bolt'"),
(12387,0,1,0,0,0,100,0,8000,11000,9000,15000,0,11,16843,0,0,0,0,0,1,0,0,0,0,0,0,0,"Large Vile Slime - In Combat - Cast 'Crimson Fury'"),
(12387,0,2,0,9,0,100,0,0,8,13000,15000,0,11,11975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Large Vile Slime - Within 0-8 Range - Cast 'Arcane Explosion'");

-- Skeletal Sorcerer
UPDATE `smart_scripts` SET `event_chance`=100, `event_param1`=8000, `event_param3`=16000 WHERE `entryorguid`=1804 AND `source_type`=0 AND `id`=0;

-- Haunting Vision
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=4472 AND `source_type`=0 AND `id` IN (1,2);

-- Putrid Gargoyle
DELETE FROM `smart_scripts` WHERE `entryorguid`=8534 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8534,0,0,0,25,0,100,0,0,0,0,0,0,11,16574,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putrid Gargoyle - On Reset - Cast 'Putrid Bile'");

-- Diseased Flayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=8532 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8532,0,1,0,25,0,100,0,0,0,0,0,0,11,16800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Flayer - On Reset - Cast 'Ghoul Rot'"),
(8532,0,2,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Flayer - On Respawn - Cast 'Birth'");

-- Eyeless Watcher
UPDATE `smart_scripts` SET `action_param1`=30991 WHERE `entryorguid`=8539 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8539 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8539,0,3,0,25,0,100,0,0,0,0,0,0,11,8279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eyeless Watcher - On Reset - Cast 'Stealth Detection'");

-- Plague Ravager
DELETE FROM `smart_scripts` WHERE `entryorguid`=8520 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8520,0,1,0,25,0,100,0,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Ravager - On Reset - Cast 'Thrash'");

-- Scarlet Warder
DELETE FROM `smart_scripts` WHERE `entryorguid`=9447 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9447,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Warder - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9447;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9447,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Warder"),
(9447,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Warder"),
(9447,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Warder"),
(9447,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Warder");

-- Scarlet Cleric
DELETE FROM `smart_scripts` WHERE `entryorguid`=9449 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9449,0,1,0,14,0,100,0,3000,40,25000,35000,0,11,15586,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Cleric - On Friendly Between 0-40% Health - Cast 'Heal'"),
(9449,0,3,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9449;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9449,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Cleric"),
(9449,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Cleric"),
(9449,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Cleric"),
(9449,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Cleric");

-- Scarlet Enchanter
DELETE FROM `smart_scripts` WHERE `entryorguid`=9452 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9452,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9452;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9452,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Enchanter"),
(9452,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Enchanter"),
(9452,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Enchanter"),
(9452,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Enchanter");

-- Scarlet Praetorian
DELETE FROM `smart_scripts` WHERE `entryorguid`=9448 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9448,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Praetorian - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9448;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9448,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Praetorian"),
(9448,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Praetorian"),
(9448,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Praetorian"),
(9448,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Praetorian");

-- Scarlet Archmage
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=9451 AND `source_type`=0 AND `id` IN (0,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=9451 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9451,0,5,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9451;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9451,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Archmage"),
(9451,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Archmage"),
(9451,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Archmage"),
(9451,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Archmage");

-- Scarlet Curate
DELETE FROM `smart_scripts` WHERE `entryorguid`=9450 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9450,0,4,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=9450;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9450,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,7,100,0,0,0,2625,0,"Scarlet Curate"),
(9450,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge's taint.",12,7,100,0,0,0,2626,0,"Scarlet Curate"),
(9450,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,7,100,0,0,0,2627,0,"Scarlet Curate"),
(9450,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,7,100,0,0,0,2628,0,"Scarlet Curate");

-- Cursed Mage
UPDATE `smart_scripts` SET `event_param3`=2000, `event_param4`=4000 WHERE `entryorguid`=8524 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=8524 AND `source_type`=0 AND `id`=1;

-- Baron Bloodbane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10819;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10819 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10819,0,0,0,0,0,100,0,3000,6000,9000,12000,0,11,18663,0,0,0,0,0,5,0,0,0,0,0,0,0,"Baron Bloodbane - In Combat - Cast 'Shadow Shock'"),
(10819,0,1,0,13,0,100,0,12000,16000,0,0,0,11,12555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Baron Bloodbane - Target Casting - Cast 'Pummel'"),
(10819,0,2,0,1,0,100,0,1000,1000,1800000,1800000,0,11,11733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Bloodbane - Out of Combat - Cast 'Demon Armor'"),
(10819,0,3,0,0,0,100,0,3000,5000,6000,8000,0,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Bloodbane - In Combat - Cast 'Strike'");

-- Death Knight Soulbearer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10818;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10818 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10818,0,0,0,0,0,100,0,2000,4000,5000,9000,0,11,12471,2,0,0,0,0,5,0,0,0,0,0,0,0,"Death Knight Soulbearer - In Combat - Cast 'Shadow Bolt'"),
(10818,0,1,0,1,0,100,0,1000,1000,1800000,1800000,0,11,11733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Soulbearer - Out of Combat - Cast 'Demon Armor'"),
(10818,0,2,0,0,0,100,0,5000,7000,9000,11000,0,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Soulbearer - In Combat - Cast 'Mortal Strike'");

-- Forest Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=30 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forest Spider - On Reset - Cast 'Poison Proc'");

-- Mine Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=43 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(43,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mine Spider - On Reset - Cast 'Poison Proc'");

-- Mother Fang
DELETE FROM `smart_scripts` WHERE `entryorguid`=471 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(471,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mother Fang - On Reset - Cast 'Poison Proc'"),
(471,0,1,0,0,0,100,0,3000,6000,12000,15000,0,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mother Fang - In Combat - Cast 'Web'");

-- Ruklar the Trapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=60 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60,0,0,0,0,0,100,0,4000,6000,11000,15000,0,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast 'Net'"),
(60,0,1,0,0,0,100,0,6000,8000,22000,26000,0,11,6016,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast 'Pierce Armor'");

-- Kobold Miner
DELETE FROM `smart_scripts` WHERE `entryorguid`=40 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40,0,1,0,0,0,100,0,4000,14000,22000,28000,0,11,6016,2,0,0,0,0,2,0,0,0,0,0,0,0,"Kobold Miner - In Combat - Cast 'Pierce Armor'");

-- Riverpaw Outrunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=478 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(478,0,1,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Outrunner - On Reset - Cast 'Thrash'");

-- Kobold Geomancer
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=476 AND `source_type`=0 AND `id`=2;

-- Defias Rogue Wizard
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=474 AND `source_type`=0 AND `id`=2;

-- Defias Footpad
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=481 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=5000, `event_param3`=5000, `event_param4`=7000 WHERE `entryorguid`=481 AND `source_type`=0 AND `id`=1;

-- Young Goretusk
DELETE FROM `smart_scripts` WHERE `entryorguid`=454 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(454,0,0,0,9,0,50,1,5,40,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Goretusk - Within 5-40 Range - Cast 'Rushing Charge' (No Repeat)");

-- Goretusk
DELETE FROM `smart_scripts` WHERE `entryorguid`=157 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(157,0,0,0,9,0,50,1,5,40,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goretusk - Within 5-40 Range - Cast 'Rushing Charge' (No Repeat)");

-- Murloc Coastrunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=126 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(126,0,0,0,0,0,100,0,6000,9000,18000,24000,0,11,7357,2,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Coastrunner - In Combat - Cast 'Poisonous Stab'");

-- Slark
DELETE FROM `smart_scripts` WHERE `entryorguid`=519 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(519,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slark - On Reset - Cast 'Thrash'");

-- Brack
DELETE FROM `smart_scripts` WHERE `entryorguid`=520 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(520,0,0,0,0,0,100,0,6000,9000,12000,18000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Hamstring'"),
(520,0,1,0,0,0,100,0,9000,11000,22000,26000,0,11,6016,2,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Pierce Armor'"),
(520,0,2,0,0,0,100,0,5000,7000,11000,15000,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Strike'");

-- Murloc Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=517 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(517,0,0,0,0,0,100,0,0,0,3000,5000,0,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Oracle - In Combat - Cast 'Holy Smite'"),
(517,0,1,0,14,0,100,0,50,40,35000,45000,0,11,6074,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Oracle - Friendly At 50 Health - Cast 'Renew'");

-- Murloc Tidehunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=127 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(127,0,0,0,0,0,100,0,8000,11000,15000,19000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Tidehunter - In Combat - Cast 'Frost Nova'"),
(127,0,1,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Tidehunter - On Reset - Cast 'Poison Proc'");

-- Harvest Reaper
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=8000, `event_param3`=14000, `event_param4`=20000 WHERE `entryorguid`=115 AND `source_type`=0 AND `id`=0;

-- Fleshripper
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid` IN (1109,154) AND `source_type`=0 AND `id`=0;

-- Defias Trapper
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=504 AND `source_type`=0 AND `id`=0;

-- Dust Devil
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=11000, `event_param3`=15000, `event_param4`=19000 WHERE `entryorguid`=832 AND `source_type`=0 AND `id`=0;

-- Riverpaw Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=1065 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1065,0,2,0,14,0,100,0,120,40,35000,45000,0,11,913,1,0,0,0,0,7,0,0,0,0,0,0,0,"Riverpaw Shaman - Friendly At 120 Health - Cast 'Healing Wave'");

-- Defias Looter
DELETE FROM `smart_scripts` WHERE `entryorguid`=590 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(590,0,2,0,0,0,100,0,4000,9000,24000,29000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Looter - In Combat - Cast 'Disarm'");

-- Riverpaw Mongrel
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=15000 WHERE `entryorguid`=123 AND `source_type`=0 AND `id`=1;

-- Defias Knuckleduster
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=449 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=449 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(449,0,2,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Knuckleduster - On Reset - Cast 'Thrash'");

-- Riverpaw Bandit
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=452 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=452 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(452,0,2,0,0,0,100,0,5000,9000,15000,19000,0,11,7357,2,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Bandit - In Combat - Cast 'Poisonous Stab'");

-- Riverpaw Taskmaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=98 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(98,0,1,0,74,0,100,0,0,80,12000,16000,0,11,3229,0,0,0,0,0,9,0,0,10,0,0,0,0,"Riverpaw Taskmaster - On Friendly Between 0-80% Health - Cast 'Quick Bloodlust'");

-- Leprithus
DELETE FROM `smart_scripts` WHERE `entryorguid`=572 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(572,0,0,0,0,0,100,0,8000,11000,11000,17000,0,11,4974,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leprithus - In Combat - Cast 'Wither Touch'"),
(572,0,1,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprithus - On Reset - Cast 'Poison Proc'");

-- Fix bytes2 for some range-attacking creatures
UPDATE `creature_addon` SET `bytes2`=2 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (1831,8561,12322,2212,3745,3926,7155,7442,8564,11680,500));
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry` IN (1831,8561,12322,2212,3745,3926,7155,7442,8564,11680,500);

-- Brack and Slark shoud be running
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (902060,902070);
