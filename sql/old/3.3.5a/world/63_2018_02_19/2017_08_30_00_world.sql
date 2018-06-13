-- Verna Furlbrow
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=238;
DELETE FROM `smart_scripts` WHERE `entryorguid`=238;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(238,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Verna Furlbrow - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=238;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(238,0,0,"Don\t worry, Old Blanchy, we\ll get you something to eat soon...",12,7,100,0,0,0,54,0,"Verna Furlbrow"),
(238,0,1,"I never thought the day would come that I\d leave my homeland of Westfall....",12,7,100,0,0,0,55,0,"Verna Furlbrow");
