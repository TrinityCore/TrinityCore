-- Nancy Vishas
DELETE FROM `creature_text` WHERE `CreatureID`=3984 AND `GroupID` IN (3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3984,3,0,"%s lets out a long, drawn out sigh.",16,0,100,0,0,0,1370,0,"Nancy Vishas"),
(3984,4,0,"Oh well....",12,7,100,0,0,0,1371,0,"Nancy Vishas");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3984 AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=398401 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3984,0,4,0,40,0,100,0,1,3984,0,0,80,398401,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nancy Vishas - On Waypoint 1 Reached - Run Script"),
(398401,9,0,0,0,0,100,0,23000,23000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nancy Vishas - On Script - Say Line 3"),
(398401,9,1,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nancy Vishas - On Script - Say Line 4");
