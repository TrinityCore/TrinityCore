-- Add gossip menus
DELETE FROM `gossip_menu` WHERE (`MenuID`, `TextID`) IN ((13931, 1216),(14200, 16570),(13935, 4835),(13921, 4433),(13918, 539),(13924, 2175));
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
-- Warrior
(13931, 1216, 65299), -- 911
-- Hunter
(14200, 16570, 65299), -- 43278
-- Rogue
(13935, 4835, 65299), -- 915
-- Priest
(13921, 4433, 65299), -- 375
-- Mage
(13918, 539, 65299), -- 198
-- Warlock
(13924, 2175, 65299); -- 459

-- Update a field
UPDATE `gossip_menu_option` SET `GossipOptionID` = '32301' WHERE  `MenuID` = 13918 AND `OptionID` = 9;

-- Add smart scripts for mage trainer to train and unlearn spell Arcane Momentum
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE  `entry` = 198;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 198 AND `source_type` = 0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(198, 0, 0, 2, '', 62, 0, 100, 0, 20690, 0, 0, 0, '', 85, 232062, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, NULL, 0, 0, 0, 0, 'On gossip action 0 from menu 20690 selected - Gossip player: Cast spell Arcane Momentum (232062) on self'),
(198, 0, 1, 2, '', 62, 0, 100, 0, 20690, 1, 0, 0, '', 85, 232063, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, NULL, 0, 0, 0, 0, 'On gossip action 1 from menu 20690 selected - Gossip player: Cast unlearn spell Arcane Momentum (232062) on self'),
(198, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, NULL, 0, 0, 0, 0, 'On link close gossip');

-- Hunter npc text 
DELETE FROM `npc_text` WHERE `ID` = 16570;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES
(16570, 1, 0, 0, 0, 0, 0, 0, 0, 44495, 0, 0, 0, 0, 0, 0, 0, 65299);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`) IN ((14,13931,5721),(14,13931,1216),(14,14200,16569),(14,14200,16570),(14,13935,4837),(14,13935,4835),(14,13921,4434),(14,13921,4433),(14,13921,539),(14,13921,538),(15,20690,0),(15,20690,1),(15,13918,9),(14,13924,5722),(14,13924,2175),(14,12670,17816),(15,12670,0),(15,12670,1),(15,12670,2),(15,12670,3));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
-- Warrior
(14, 13931, 5721, 0, 0, 15, 0, 1, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Warrior'),
(14, 13931, 1216, 0, 0, 15, 0, 1, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Warrior'),
-- Hunter
(14, 14200, 16569, 0, 0, 15, 0, 4, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Hunter'),
(14, 14200, 16570, 0, 0, 15, 0, 4, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Hunter'),
-- Rogue
(14, 13935, 4837, 0, 0, 15, 0, 8, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Rogue'),
(14, 13935, 4835, 0, 0, 15, 0, 8, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Rogue'),
-- Priest
(14, 13921, 4434, 0, 0, 15, 0, 16, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Priest'),
(14, 13921, 4433, 0, 0, 15, 0, 16, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Priest'),
-- Mage
(14, 13921, 539, 0, 0, 15, 0, 128, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Mage'),
(14, 13921, 538, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Mage'),
-- Mage Options
(15, 20690, 0, 0, 0, 25, 0, 56384, 0, 0, '', 1, 0, 0, '', 'Show gossip menu if player does not have spell Arcane Momentum'),
(15, 20690, 1, 0, 0, 25, 0, 56384, 0, 0, '', 0, 0, 0, '', 'Show gossip menu if player has spell Arcane Momentum'),
(15, 13918, 9, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a Mage'),
-- Warlock
(14, 13924, 5722, 0, 0, 15, 0, 256, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Warlock'),
(14, 13924, 2175, 0, 0, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Warlock'),
-- Demon trainer 
(14, 12670, 17816, 0, 0, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Warlock'),
(15, 12670, 0, 0, 1, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a Warlock'),
(15, 12670, 0, 0, 1, 27, 0, 3, 3, 0, '', 0, 0, 0, '', 'Show gossip option if player is a level 3 Warlock'),
(15, 12670, 1, 0, 1, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a Warlock'),
(15, 12670, 1, 0, 1, 27, 0, 10, 3, 0, '', 0, 0, 0, '', 'Show gossip option if player is a level 10 Warlock'),
(15, 12670, 2, 0, 1, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a Warlock'),
(15, 12670, 2, 0, 1, 27, 0, 19, 3, 0, '', 0, 0, 0, '', 'Show gossip option if player is a level 19 Warlock'),
(15, 12670, 3, 0, 1, 15, 0, 256, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a Warlock'),
(15, 12670, 3, 0, 1, 27, 0, 23, 3, 0, '', 0, 0, 0, '', 'Show gossip option if player is a level 23 Warlock');