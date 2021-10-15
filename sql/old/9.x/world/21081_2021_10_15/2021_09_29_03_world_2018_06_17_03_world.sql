-- Cabal Interrogator
DELETE FROM `smart_scripts` WHERE `entryorguid`=22378 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22378,0,0,2,1,0,100,0,5000,15000,60000,80000,0,11,39043,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Interrogator - Out of Combat - Cast 'Kick Akuno'"),
(22378,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Interrogator - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=22378;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22378,0,0,"Speak, filthy refugee!  What was your caravan doing in the Bone Wastes?",12,0,100,0,0,0,20160,0,"Cabal Interrogator");

-- Akuno
DELETE FROM `creature_text` WHERE `CreatureID`=22377;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22377,0,0,"Let us leave this place.  I've had enough of these madmen!",12,0,100,0,0,0,20161,0,"Akuno"),
(22377,1,0,"Beware!  More cultists come!",12,0,100,0,0,0,20162,0,"Akuno"),
(22377,2,0,"I can find my way from here.  My friend Mekeda will reward you for your kind actions.",12,0,100,0,0,0,20163,0,"Akuno");

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=22377;

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=22377;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22377 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2237700,2237701,2237702,2237703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22377,0,0,0,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Respawn - Set Flag Standstate 'Kneel'"),
(22377,0,1,2,19,0,100,0,10887,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Akuno - On Quest 'Escaping the Tomb' Taken - Store Targetlist"),
(22377,0,2,3,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Quest 'Ancient Spirit' Taken - Remove Npc Flag Questgiver"),
(22377,0,3,0,61,0,100,0,0,0,0,0,0,80,2237700,2,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Quest 'Ancient Spirit' Taken - Run Script"),
(22377,0,4,0,19,0,100,0,10887,0,0,0,0,2,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Quest 'Escaping the Tomb' Taken - Set Faction 10"),
(22377,0,5,0,19,0,100,0,10887,0,0,0,0,2,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Quest 'Escaping the Tomb' Taken - Set Faction 33"),
(22377,0,6,0,6,0,100,0,0,0,0,0,0,6,10887,0,0,0,0,0,12,1,0,0,0,0,0,0,"Akuno - On Just Died - Fail Quest 'Escaping the Tomb'"),
(22377,0,7,0,40,0,100,0,7,22377,0,0,0,80,2237701,2,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Waypoint 7 Reached - Run Script"),
(22377,0,8,0,40,0,100,0,13,22377,0,0,0,80,2237702,2,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Waypoint 13 Reached - Run Script"),
(22377,0,9,0,40,0,100,0,14,22377,0,0,0,80,2237703,2,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Waypoint 14 Reached - Run Script"),
(2237700,9,0,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Say Line 0"),
(2237700,9,1,0,0,0,100,0,3000,3000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Remove Flag Standstate 'Kneel'"),
(2237700,9,2,0,0,0,100,0,0,0,0,0,0,53,0,22377,0,0,0,2,1,0,0,0,0,0,0,0,"Akuno - On Script - Start Waypoint"),
(2237701,9,0,0,0,0,100,0,0,0,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Pause Waypoint"),
(2237701,9,1,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Summon Group 1"),
(2237702,9,0,0,0,0,100,0,0,0,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Pause Waypoint"),
(2237702,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Say Line 1"),
(2237702,9,2,0,0,0,100,0,0,0,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Summon Group 2"),
(2237702,9,3,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Set Run On"),
(2237703,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Say Line 2"),
(2237703,9,1,0,0,0,100,0,0,0,0,0,0,15,10887,0,0,0,0,0,12,1,0,0,0,0,0,0,"Akuno - On Script - Complete Quest 'Escaping the Tomb'"),
(2237703,9,2,0,0,0,100,0,0,0,0,0,0,41,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akuno - On Script - Despawn");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=22377;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(22377,0,1,21661,-2872.73,5416.57,-28.261,6.28158,1,25000),
(22377,0,1,21661,-2872.57,5411.03,-28.261,0.06515,1,25000),
(22377,0,2,21661,-2897.29,5325.13,-11.854,1.29125,1,25000),
(22377,0,2,21661,-2890.51,5324.94,-11.222,1.63291,1,25000);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=22377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,6,22377,0,0,6,0,67,0,0,0,0,0,"","SAI triggers only if Player is Horde"),
(22,5,22377,0,0,6,0,469,0,0,0,0,0,"","SAI triggers only if Player is Alliance");

DELETE FROM `script_waypoint` WHERE `entry`=22377;
DELETE FROM `waypoints` WHERE `entry`=22377;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(22377,1,-2766.31,5429.65,-34.53,""),
(22377,2,-2769.35,5416.25,-34.53,""),
(22377,3,-2780.07,5416.06,-34.53,""),
(22377,4,-2812.56,5415.2,-34.53,""),
(22377,5,-2816.95,5415.02,-34.52,""),
(22377,6,-2827.86,5414.56,-28.29,""),
(22377,7,-2864.44,5414.17,-28.26,""),
(22377,8,-2878.32,5414.11,-28.26,""),
(22377,9,-2893.17,5413.15,-18.59,""),
(22377,10,-2896.36,5409.65,-18.59,""),
(22377,11,-2896.5,5396.76,-8.77,""),
(22377,12,-2896.67,5366.2,-9.59,""),
(22377,13,-2891.52,5342.16,-11.6663,""),
(22377,14,-2861.98,5242.75,-12.4858,"");

-- Cabal Skirmisher
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=21661 AND `source_type`=0 AND `id`=3;
