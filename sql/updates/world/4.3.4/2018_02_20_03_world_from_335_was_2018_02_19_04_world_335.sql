/*
-- Un'Goro Thunderer
DELETE FROM `smart_scripts` WHERE `entryorguid`=-24081 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=651600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-24081,0,0,0,0,0,100,0,5000,5000,9000,15000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Un'Goro Thunderer - In Combat - Cast 'Shock'"),
(-24081,0,1,0,1,0,100,0,15000,30000,150000,180000,80,651600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Thunderer - Out of Combat - Run Script"),
(-24081,0,2,0,4,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Thunderer - On Aggro - Remove Flag Standstate Dead"),
(651600,9,0,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Thunderer - On Script - Set Flag Standstate Dead"),
(651600,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Thunderer - On Script - Say Line 0"),
(651600,9,2,0,0,0,100,0,60000,60000,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Goro Thunderer - On Script - Remove Flag Standstate Dead");

DELETE FROM `creature_text` WHERE `CreatureID`=6516;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6516,0,0,"%s looks tired. He then yawns and lies down next to A-Me 01.",16,0,100,0,0,0,5045,0,"Un'Goro Thunderer"),
(6516,0,1,"%s snores loudly and cuddles up next to A-Me 01.",16,0,100,0,0,0,5046,0,"Un'Goro Thunderer");
*/
