-- 
-- Verdantine Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12478;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12478 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12478,0,0,0,14,0,100,0,20000,40,15000,20000,11,20664,0,0,0,0,0,7,0,0,0,0,0,0,0,"Verdantine Oracle - Friendly at 20000 HP - Cast 'Rejuvenation'"),
(12478,0,1,0,14,0,100,0,40000,40,20000,25000,11,20665,0,0,0,0,0,7,0,0,0,0,0,0,0,"Verdantine Oracle - Friendly at 40000 HP - Cast 'Regrowth'");

-- Verdantine Tree Warder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12479;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12479 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12479,0,0,0,0,0,100,0,2000,6000,19000,23000,11,20654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verdantine Tree Warder - In Combat - Cast 'Entangling Roots'"),
(12479,0,1,0,0,0,100,0,3000,6000,9000,12000,11,20656,32,0,0,0,0,5,0,0,0,0,0,0,0,"Verdantine Tree Warder - In Combat - Cast 'Faerie Fire'");

-- Verdantine Boughguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12477;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12477 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12477,0,0,0,0,0,100,0,3000,5000,11000,15000,11,20666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verdantine Boughguard - In Combat - Cast 'Cleave'"),
(12477,0,1,0,0,0,100,0,5000,7000,11000,15000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verdantine Boughguard - In Combat - Cast 'Mortal Strike'"),
(12477,0,2,0,0,0,100,0,12000,18000,18000,24000,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Verdantine Boughguard - In Combat - Cast 'Fixate'");

-- Dreamtracker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12496;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12496 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12496,0,0,0,0,0,100,0,5000,8000,5000,8000,11,20667,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dreamtracker - In Combat - Cast 'Corrosive Acid Breath'"),
(12496,0,1,0,0,0,100,0,8000,11000,10000,14000,11,6605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreamtracker - In Combat - Cast 'Terrifying Screech'");

-- Rothos
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5718 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5718,0,0,0,0,0,100,0,5000,8000,7000,11000,11,20667,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rothos - In Combat - Cast 'Corrosive Acid Breath'"),
(5718,0,1,0,0,0,100,0,12000,15000,13000,19000,11,20672,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rothos - In Combat - Cast 'Fade'");

-- Jademir Boughguard
UPDATE `smart_scripts` SET `action_type`=11, `comment`="Jademir Boughguard - In Combat - Cast 'Mortal Strike'" WHERE `entryorguid`=5320 AND `source_type`=0 AND `id`=1;

-- Jademir Tree Warder
DELETE FROM `smart_scripts` WHERE `entryorguid`=5319 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5319,0,0,0,0,0,100,0,5000,7000,19000,23000,11,20654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jademir Tree Warder - In Combat - Cast 'Entangling Roots'"),
(5319,0,1,0,0,0,100,0,2000,4000,9000,12000,11,20656,32,0,0,0,0,5,0,0,0,0,0,0,0,"Jademir Tree Warder - In Combat - Cast 'Faerie Fire'");

-- Jademir Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=5317 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5317,0,0,0,14,0,100,0,20000,40,15000,20000,11,20664,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jademir Oracle - Friendly at 20000 HP - Cast 'Rejuvenation'"),
(5317,0,1,0,14,0,100,0,40000,40,20000,25000,11,20665,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jademir Oracle - Friendly at 40000 HP - Cast 'Regrowth'");

-- Dreamroarer
DELETE FROM `smart_scripts` WHERE `entryorguid`=12497 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12497,0,0,0,0,0,100,0,5000,8000,7000,11000,11,20667,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dreamroarer - In Combat - Cast 'Corrosive Acid Breath'"),
(12497,0,1,0,0,0,100,0,9000,11000,12000,16000,11,20668,0,0,0,0,0,6,0,0,0,0,0,0,0,"Dreamroarer - In Combat - Cast 'Sleepwalk'");
