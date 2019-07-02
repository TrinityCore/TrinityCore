-- Sergra Darkthorn
DELETE FROM `creature_text` WHERE `CreatureID`=3338;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3338,0,0,"The spirit of Echeyakee flows through you, $n.",12,1,100,2,0,0,1295,0,"Sergra Darkthorn");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3338;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3338 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3338,0,0,1,20,0,100,0,881,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sergra Darkthorn - On Quest 'Echeyakee' Finished - Say Line 0"),
(3338,0,1,0,61,0,100,0,0,0,0,0,85,5320,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sergra Darkthorn - On Quest 'Echeyakee' Finished - Invoker Cast Echeyakee's Grace");
