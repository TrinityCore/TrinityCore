-- Firewing Courier Aggro Text
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18548;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18548 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18548,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firewing Courier - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=18548;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18548,0,0,"This belongs to Firewing Point.  You'll not be putting your grubby hands on it!",12,0,100,0,0,0,15528,0,"Firewing Courier");
