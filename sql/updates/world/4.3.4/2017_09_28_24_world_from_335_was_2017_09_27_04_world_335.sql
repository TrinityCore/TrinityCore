/*
-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (2956, 3244, 3246);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2956, 3244, 3246) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7726 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2956, 0, 0, 0, 2, 0, 100, 1, 0, 25, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Adult Plainstrider - Between 0-25% Health - Run In Fear (No Repeat)"),
(3244, 0, 0, 0, 2, 0, 100, 1, 0, 25, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Greater Plainstrider - Between 0-25% Health - Run In Fear (No Repeat)"),
(3246, 0, 0, 0, 2, 0, 100, 1, 0, 25, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fleeting Plainstrider - Between 0-25% Health - Run In Fear (No Repeat)"),
(7726, 0, 12, 0, 2, 0, 100, 1, 0, 25, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimtotem Naturalist - Between 0-25% Health - Run In Fear (No Repeat)");

UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid`=588 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid`=595 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `link`=2 WHERE `entryorguid`=16863 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=16863 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=588 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=595 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16863 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(588, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodscalp Scout - Between 0-30% Health - Say Line 0"),
(595, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodscalp Hunter - Between 0-30% Health - Say Line 0"),
(16863, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deranged Helboar - Between 0-30% Health - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (588, 595, 16863);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(588, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Bloodscalp Scout"),
(595, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Bloodscalp Hunter"),
(16863, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Deranged Helboar");
*/
