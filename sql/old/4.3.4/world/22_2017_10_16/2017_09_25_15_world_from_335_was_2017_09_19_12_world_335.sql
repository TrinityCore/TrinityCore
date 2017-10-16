/*
-- Living Decay
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8606;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8606 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8606,0,0,0,0,0,100,0,7000,12000,11000,18000,11,11442,32,0,0,0,0,2,0,0,0,0,0,0,0,"Living Decay - In Combat - Cast Withered Touch");

-- Mossflayer Zombie
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11290;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11290 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11290,0,0,0,9,0,100,0,0,5,9000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Zombie - Within 0-5 Range - Cast Disease Touch");

-- Scarlet Inquisitor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15162;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15162 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15162,0,0,0,25,0,100,0,0,0,0,0,11,9276,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Inquisitor - On Reset - Cast Immolate");

UPDATE `creature` SET `position_x`=1603.97, `position_y`=-5306.89, `position_z`=69.895, `orientation`=4.93402 WHERE `guid`=86149;
UPDATE `creature` SET `position_x`=1598.01, `position_y`=-5315.04, `position_z`=69.8807, `orientation`=3.27291 WHERE `guid`=84825;
UPDATE `creature` SET `position_x`=1594.68, `position_y`=-5313.46, `position_z`=69.8814, `orientation`=3.22185 WHERE `guid`=53036;

-- Remove wrong SAI and spawns for Skeletal Servant
DELETE FROM `creature` WHERE `guid` IN (92273, 92276, 92277, 92280, 52124, 52125, 52126, 52127, 52128, 52129, 52130, 52131, 52132, 52133, 52134, 52135, 52136, 52137, 52138, 52139, 52140);
DELETE FROM `creature_addon` WHERE `guid` IN (92273, 92276, 92277, 92280, 52124, 52125, 52126, 52127, 52128, 52129, 52130, 52131, 52132, 52133, 52134, 52135, 52136, 52137, 52138, 52139, 52140);

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=8477;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8477;
*/
