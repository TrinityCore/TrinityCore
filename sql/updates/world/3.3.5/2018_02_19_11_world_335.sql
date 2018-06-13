-- Starving Snickerfang
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5984;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5984 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5984,0,0,0,0,0,100,0,5000,8000,21000,24000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Starving Snickerfang - In Combat - Cast 'Infected Bite'");

-- Snickerfang Hyena
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5985;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5985 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5985,0,0,0,0,0,100,0,5000,8000,21000,24000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snickerfang Hyena - In Combat - Cast 'Infected Bite'");

-- Ashmane Boar
DELETE FROM `smart_scripts` WHERE `entryorguid`=5992 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5992,0,0,0,25,0,100,0,0,0,0,0,11,12898,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - On Reset - Cast 'Smoke Aura Visual'"),
(5992,0,1,0,0,0,100,0,3000,3000,3000,3000,11,11351,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - In Combat - Cast 'Fire Shield'");

-- Redstone Basilisk
UPDATE `smart_scripts` SET `event_param1`=8000, `event_param2`=15000, `event_param3`=17000, `event_param4`=24000 WHERE `entryorguid`=5990 AND `source_type`=0 AND `id`=0;

-- Redstone Crystalhide
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=9000, `event_param3`=16000, `event_param4`=20000, `target_type`=5 WHERE `entryorguid`=5991 AND `source_type`=0 AND `id`=0;

-- Wretched Lost One
UPDATE `smart_scripts` SET `event_param1`=11000, `event_param2`=13000, `event_param3`=16000, `event_param4`=19000 WHERE `entryorguid`=5979 AND `source_type`=0 AND `id`=1;

-- Shadowsworn Thug
DELETE FROM `smart_scripts` WHERE `entryorguid`=6005 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6005,0,1,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Thug - On Reset - Cast 'Thrash'"),
(6005,0,2,0,0,0,100,0,8000,12000,14000,18000,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Thug - In Combat - Cast 'Snap Kick'");

-- Scorpok Stinger
DELETE FROM `smart_scripts` WHERE `entryorguid`=5988 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5988,0,0,0,0,0,100,0,7000,9000,14000,18000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpok Stinger - In Combat - Cast 'Venom Sting'");

-- Dreadmaul Ogre
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5974;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5974 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5974,0,0,0,0,0,100,0,5000,11000,28000,34000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre - In Combat - Cast 'Curse of the Dreadmaul'"),
(5974,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5974;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5974,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dreadmaul Ogre"),
(5974,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dreadmaul Ogre"),
(5974,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dreadmaul Ogre");

-- Dreadmaul Brute
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5976;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5976 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5976,0,0,0,0,0,100,0,5000,11000,28000,34000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Brute - In Combat - Cast 'Curse of the Dreadmaul'"),
(5976,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Brute - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5976;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5976,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dreadmaul Brute"),
(5976,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dreadmaul Brute"),
(5976,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dreadmaul Brute");

-- Dreadmaul Ogre Mage
DELETE FROM `smart_scripts` WHERE `entryorguid`=5975 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5975,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5975;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5975,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dreadmaul Ogre Mage"),
(5975,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dreadmaul Ogre Mage"),
(5975,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dreadmaul Ogre Mage");

-- Dreadmaul Warlock
UPDATE `smart_scripts` SET `action_param2`=32 WHERE `entryorguid`=5978 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5978 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5978,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5978;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5978,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dreadmaul Warlock"),
(5978,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dreadmaul Warlock"),
(5978,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dreadmaul Warlock");

-- Dreadmaul Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=5977 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5977,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - On Reset - Cast 'Thrash'"),
(5977,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5977;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5977,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Dreadmaul Mauler"),
(5977,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Dreadmaul Mauler"),
(5977,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Dreadmaul Mauler");

-- Felbeast
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=8000, `event_param3`=18000, `event_param4`=24000 WHERE `entryorguid`=8675 AND `source_type`=0 AND `id`=0;

-- Akubar the Seer
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=8298 AND `source_type`=0 AND `id` IN (1,2);

-- Shadowsworn Warlock
UPDATE `smart_scripts` SET `action_param2`=32 WHERE `entryorguid`=6008 AND `source_type`=0 AND `id`=2;

-- Shadowsworn Dreadweaver
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=6009 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=32 WHERE `entryorguid`=6009 AND `source_type`=0 AND `id`=2;
