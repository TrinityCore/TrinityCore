/*
-- Improve Quest "The Blackwood Corrupted"
-- Blackwood Fruit Stores
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=175330;
DELETE FROM `smart_scripts` WHERE `entryorguid`=175330 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(175330,1,0,0,70,0,100,1,2,0,0,0,12,2168,3,180000,0,0,0,8,0,0,0,6870.6,-527.736,40.364,1.04751,"Blackwood Fruit Stores - On Gameobject State Changed - Summon Creature \'Blackwood Warrior\'"),
(175330,1,1,0,70,0,100,1,2,0,0,0,1,0,0,0,0,0,0,19,2168,0,0,0,0,0,0,"Blackwood Fruit Stores - On Gameobject State Changed - Say Line 0 (Blackwood Warrior)");

-- Blackwood Grain Stores
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=175331;
DELETE FROM `smart_scripts` WHERE `entryorguid`=175331 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(175331,1,0,0,70,0,100,1,2,0,0,0,12,2168,3,180000,0,0,0,8,0,0,0,6805.47,-367.96,40.3136,4.99806,"Blackwood Grain Stores - On Gameobject State Changed - Summon Creature \'Blackwood Warrior\'"),
(175331,1,1,0,70,0,100,1,2,0,0,0,1,1,0,0,0,0,0,19,2168,0,0,0,0,0,0,"Blackwood Grain Stores - On Gameobject State Changed - Say Line 1 (Blackwood Warrior)");

-- Blackwood Warrior
DELETE FROM `creature_text` WHERE `CreatureID`=2168;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2168,0,0,"%s spies you tampering with the camp\'s fruit stores and attacks you!",16,0,100,0,0,0,5684,0,"Blackwood Warrior"),
(2168,1,0,"%s emerges from the log hovel and catches you tampering with the grain stores!",16,0,100,0,0,0,5685,0,"Blackwood Warrior");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2168 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2168,0,2,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,15,0,0,0,0,0,0,"Blackwood Warrior - On Respawn - Start Attacking");

-- Xabraxxis
DELETE FROM `creature_text` WHERE `CreatureID`=10373;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10373,0,0,"What the... nobody cleanses a furbolg in MY camp!  Face the wrath of Xabraxxis!",14,0,100,0,0,0,5616,0,"Xabraxxis");

DELETE FROM `smart_scripts` WHERE `entryorguid`=10373 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10373,0,5,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xabraxxis - Just Summoned - Say Line 0");
*/
