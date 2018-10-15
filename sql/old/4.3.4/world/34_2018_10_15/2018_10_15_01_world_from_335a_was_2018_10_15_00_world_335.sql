/*
-- Loramus Thalipedes
DELETE FROM `creature_text` WHERE `CreatureID`=7783;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7783,0,0,"You will need to open the Felhound Tracker Kit and read the instruction manual. Summon the beast when you are near the peninsula of cliff giants, south of here.",12,0,100,0,0,0,4576,0,"Loramus Thalipedes");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7783 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7783,0,4,0,19,0,100,0,3602,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Loramus Thalipedes - On Quest 'Azsharite' Taken - Say Line 0");

-- Felhound Tracker
DELETE FROM `creature_text` WHERE `CreatureID`=8668;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8668,0,0,"%s searches for a source of arcane energy.",16,0,100,0,0,0,4570,0,"Felhound Tracker"),
(8668,1,0,"%s growls.",16,0,100,35,0,0,4571,0,"Felhound Tracker");

UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=`unit_flags`|768 WHERE `entry`=8668;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8668 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (866800,866801,866802) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8668,0,0,0,22,0,100,0,75,5000,5000,0,0,80,866800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Received Emote 'Roar' - Run Script"),
(8668,0,1,0,22,0,100,0,75,5000,5000,0,0,80,866801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Received Emote 'Roar' - Run Script"),
(8668,0,2,0,38,0,100,0,1,1,0,0,0,29,0,90,0,0,0,0,23,0,0,0,0,0,0,0,"Felhound Tracker - On Data Set - Follow owner"),
(866800,9,0,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Say Line 1"),
(866801,9,0,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Say Line 0"),
(866801,9,1,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Set Event phase1"),
(866801,9,2,0,0,2,100,0,0,0,0,0,0,69,1,0,0,2,0,0,20,152620,90,0,0,0,0,0,"Felhound Tracker - On Script - Move to Closest Gameobject 'Azsharite Formation'"),
(866801,9,3,0,0,2,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Set Event phase1"),
(866801,9,4,0,0,2,100,0,0,0,0,0,0,69,1,0,0,2,0,0,20,152621,90,0,0,0,0,0,"Felhound Tracker - On Script - Move to Closest Gameobject 'Azsharite Formation'"),
(866801,9,5,0,0,2,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Set Event phase1"),
(866801,9,6,0,0,2,100,0,0,0,0,0,0,69,1,0,0,2,0,0,20,152622,90,0,0,0,0,0,"Felhound Tracker - On Script - Move to Closest Gameobject 'Azsharite Formation'"),
(866801,9,7,0,0,2,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Set Event phase1"),
(866801,9,8,0,0,2,100,0,0,0,0,0,0,69,1,0,0,2,0,0,20,152631,90,0,0,0,0,0,"Felhound Tracker - On Script - Move to Closest Gameobject 'Azsharite Formation'"),
(866801,9,9,0,0,2,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On Script - Set Event phase1"),
(8668,0,3,0,34,0,100,0,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felhound Tracker - On movement informer - Set phase event 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=8668;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=866801;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,8668,0,0,30,1,152620,90,0,1,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is not in range"),
(22,1,8668,0,0,30,1,152621,90,0,1,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is not in range"),
(22,1,8668,0,0,30,1,152622,90,0,1,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is not in range"),
(22,1,8668,0,0,30,1,152631,90,0,1,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is not in range"),
(22,2,8668,0,0,30,1,152620,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,2,8668,0,1,30,1,152621,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,2,8668,0,2,30,1,152622,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,2,8668,0,3,30,1,152631,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,3,866801,9,0,30,1,152620,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,4,866801,9,0,30,1,152620,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,5,866801,9,0,30,1,152621,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,6,866801,9,0,30,1,152621,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,7,866801,9,0,30,1,152622,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,8,866801,9,0,30,1,152622,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,9,866801,9,0,30,1,152631,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range"),
(22,10,866801,9,0,30,1,152631,90,0,0,0,0,"","SAI triggers only if gameobject 'Azsharite Formation' is in range");

-- Azsharite Formation
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (152620,152621,152622,152631);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (152620,152621,152622,152631) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(152620,1,0,0,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,8668,0,0,0,0,0,0,"Azsharite Formation - On Gameobject State Changed - Set Data 2 to Felhound Tracker"),
(152621,1,0,0,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,8668,0,0,0,0,0,0,"Azsharite Formation - On Gameobject State Changed - Set Data 2 to Felhound Tracker"),
(152622,1,0,0,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,8668,0,0,0,0,0,0,"Azsharite Formation - On Gameobject State Changed - Set Data 2 to Felhound Tracker"),
(152631,1,0,0,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,8668,0,0,0,0,0,0,"Azsharite Formation - On Gameobject State Changed - Set Data 2 to Felhound Tracker");

DELETE FROM `item_loot_template` WHERE  `entry`=10834 AND `Item`=10714;
UPDATE `item_loot_template` SET `Chance`=100 WHERE  `entry`=10834;
*/
