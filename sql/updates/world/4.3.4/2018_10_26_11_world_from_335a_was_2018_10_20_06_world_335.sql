/*
-- Foggy MacKreel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2696;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2696 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=269600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2696,0,0,0,1,0,100,0,1000,15000,120000,150000,80,269600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foggy MacKreel - Out of Combat - Run Script"),
(269600,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foggy MacKreel - On Script - Say Line 0"),
(269600,9,1,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foggy MacKreel - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2696;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2696,0,0,"Sure does seem like it's been a long time since anyone has relieved me from my post.",12,7,100,0,0,0,790,0,"Foggy MacKreel"),
(2696,1,0,"Well, that's what I get for oversleeping!",12,7,100,0,0,0,791,0,"Foggy MacKreel");
*/
