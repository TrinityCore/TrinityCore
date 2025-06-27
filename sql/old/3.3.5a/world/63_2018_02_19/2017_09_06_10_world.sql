-- First Mate Fitzsimmons
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1239;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1239 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1239,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"First Mate Fitzsimmons - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1239;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1239,0,0,"I'm cursed!  First my ship sinks, and now...I'm out of mead!",12,7,100,0,0,0,552,0,"First Mate Fitzsimmons"),
(1239,0,1,"Curse you, Halyndor!  You led us to our doom!",12,7,100,0,0,0,553,0,"First Mate Fitzsimmons"),
(1239,0,2,"Don't mind me, or my smell...because I sure don't!",12,7,100,0,0,0,554,0,"First Mate Fitzsimmons"),
(1239,0,3,"Ah, beautiful Menethil Harbor, with the best mead this side of Ironforge.",12,7,100,0,0,0,556,0,"First Mate Fitzsimmons"),
(1239,0,4,"Oh, my brothers!  May you find rest in your watery graves!",12,7,100,0,0,0,557,0,"First Mate Fitzsimmons");
