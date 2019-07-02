-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=1786;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(1786,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1786 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1786,2,0,0,46,0,100,1,0,0,0,0,45,1,1,0,0,0,0,10,91106,8891,0,0,0,0,0,"Areatrigger - On Trigger - Set Data to Anvilrage Guardsman"),
(1786,2,1,0,46,0,100,1,0,0,0,0,45,1,1,0,0,0,0,10,91107,8891,0,0,0,0,0,"Areatrigger - On Trigger - Set Data to Anvilrage Guardsman");

-- Anvilrage Guardsman
DELETE FROM `smart_scripts` WHERE `entryorguid`=-91106 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=889100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-91106,0,0,0,0,0,100,0,3000,6000,13000,16000,0,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Shield Block'"),
(-91106,0,1,0,0,0,100,0,7000,9000,12000,14000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Disarm'"),
(-91106,0,2,0,0,0,100,0,5000,7000,15000,17000,0,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Sunder Armor'"),
(-91106,0,3,0,11,0,100,0,0,0,0,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Respawn - Set Phasemask 2"),
(-91106,0,4,0,38,0,100,1,1,1,0,0,0,80,889100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Data Set - Run Script"),
(-91106,0,5,0,40,0,100,0,5,889100,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Anvilrage Guardsman - On Waypoint 5 Reached - Start Attacking"),
(889100,9,0,0,0,0,100,0,0,0,0,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Script - Set Phasemask 1"),
(889100,9,1,0,0,0,100,0,0,0,0,0,0,53,1,889100,0,0,0,2,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Script - Start Waypoint"),
(889100,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=8891;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8891,0,0,"You can't hide from us.  Prepare to burn!",14,0,100,0,0,0,5271,0,"Anvilrage Guardsman");

-- Anvilrage Guardsman
DELETE FROM `smart_scripts` WHERE `entryorguid`=-91107 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=889101 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-91107,0,0,0,0,0,100,0,3000,6000,13000,16000,0,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Shield Block'"),
(-91107,0,1,0,0,0,100,0,7000,9000,12000,14000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Disarm'"),
(-91107,0,2,0,0,0,100,0,5000,7000,15000,17000,0,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Guardsman - In Combat - Cast 'Sunder Armor'"),
(-91107,0,3,0,11,0,100,0,0,0,0,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Respawn - Set Phasemask 2"),
(-91107,0,4,0,38,0,100,1,1,1,0,0,0,80,889101,2,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Data Set - Run Script"),
(-91107,0,5,0,40,0,100,0,4,889101,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Anvilrage Guardsman - On Waypoint 5 Reached - Start Attacking"),
(889101,9,0,0,0,0,100,0,0,0,0,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Script - Set Phasemask 1"),
(889101,9,1,0,0,0,100,0,0,0,0,0,0,53,1,889101,0,0,0,2,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - On Script - Start Waypoint");

-- WP
DELETE FROM `waypoints` WHERE `entry` IN (889100,889101);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(889100,1,639.987,-276.824,-43.2361,""),
(889100,2,640.241,-280.344,-43.2384,""),
(889100,3,643.001,-284.951,-43.1872,""),
(889100,4,647.542,-284.671,-43.2179,""),
(889100,5,678.663,-280.524,-43.2024,""),
(889101,1,740.742,-279.867,-42.8317,""),
(889101,2,738.253,-276.193,-42.8331,""),
(889101,3,733.826,-276.382,-42.8014,""),
(889101,4,701.579,-279.202,-43.206,"");

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (-91106,-91107);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,5,-91106,0,0,26,1,2,0,0,0,0,0,"","SAI triggers only if Anvilrage Guardsman is in phasemask 2"),
(22,5,-91107,0,0,26,1,2,0,0,0,0,0,"","SAI triggers only if Anvilrage Guardsman is in phasemask 2");
