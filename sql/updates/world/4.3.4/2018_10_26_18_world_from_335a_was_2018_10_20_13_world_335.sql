/*
-- Cleansed Timberling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3570;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3570 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3570,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cleansed Timberling - Just Summoned - Say Line 0"),
(3570,0,1,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cleansed Timberling - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=3570;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3570,0,0,"%s happily follows $n as $ghis:her; new seedling.",16,0,100,0,0,0,1177,0,"Cleansed Timberling"),
(3570,1,0,"I will protect you!",12,2,100,0,0,0,1178,0,"Cleansed Timberling");
*/
