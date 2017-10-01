/*
-- Scarlet Convert
UPDATE `smart_scripts` SET `event_chance`=20 WHERE `entryorguid`=1506 AND `source_type`=0 AND `id`=0;

-- Scarlet Convert
DELETE FROM `smart_scripts` WHERE `entryorguid`=-44957 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-44957,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Convert - On Aggro - Say Line 0"),
(-44957,0,1,0,4,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,1667,0,0,0,0,0,0,"Scarlet Convert - On Aggro - Set Data");

-- Scarlet Initiate
DELETE FROM `smart_scripts` WHERE `entryorguid`=1507 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1507,0,0,0,0,0,100,0,0,0,3400,4800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Initiate - In Combat - Cast Fireball"),
(1507,0,1,0,23,0,100,0,12544,0,5000,10000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Initiate - On Has No Aura Frost Armor - Cast Frost Armor"),
(1507,0,2,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Initiate - On Aggro - Say Line 0");

-- Scarlet Initiate
DELETE FROM `smart_scripts` WHERE `entryorguid`=-44964 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-44964,0,0,0,0,0,100,0,0,0,3400,4800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Initiate - In Combat - Cast Fireball"),
(-44964,0,1,0,23,0,100,0,12544,0,5000,10000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Initiate - On Has No Aura Frost Armor - Cast Frost Armor"),
(-44964,0,2,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Initiate - On Aggro - Say Line 0"),
(-44964,0,3,0,4,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,1667,0,0,0,0,0,0,"Scarlet Initiate - On Aggro - Set Data");

-- Meven Korgal
DELETE FROM `smart_scripts` WHERE `entryorguid`=1667 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1667,0,0,0,25,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meven Korgal - On Reset - Say Line 1"),
(1667,0,1,0,4,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meven Korgal - On Aggro - Say Line 2"),
(1667,0,2,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meven Korgal - On Data Set - Say Line 0 (No Repeat)"),
(1667,0,3,0,1,0,100,0,25000,40000,90000,120000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meven Korgal - Out of Combat - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID`=1667;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1667,0,0,"These lands shall be cleansed!",12,0,100,0,0,0,314,0,"Meven Korgal"),
(1667,1,0,"These undead atrocities will be destroyed!",14,0,100,0,0,0,316,0,"Meven Korgal"),
(1667,2,0,"The Scarlet Crusade shall not fail in its mission!",12,0,100,0,0,0,317,0,"Meven Korgal"),
(1667,3,0,"We must be vigilant to eradicate this plague!",14,0,100,0,0,0,370,0,"Meven Korgal"),
(1667,3,1,"Keep up the good work.  This scourge will be cleansed!",14,0,100,0,0,0,371,0,"Meven Korgal"),
(1667,3,2,"The Scarlet Crusade will scour these lands!",14,0,100,0,0,0,372,0,"Meven Korgal"),
(1667,3,3,"Let none with the foul taint of plague live!",14,0,100,0,0,0,373,0,"Meven Korgal");

-- Shambling Horror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1528;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1528 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1528,0,0,0,0,0,100,0,3000,6000,9000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shambling Horror - In Combat - Cast Disease Touch");

-- Hungering Dead
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1527;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1527 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1527,0,0,0,0,0,100,0,3000,6000,9000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hungering Dead - In Combat - Cast Disease Touch");
*/
