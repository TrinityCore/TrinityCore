-- They should change model if the 'Nights' event is active but I found only one video
-- and I'm not sure if models are randomized (there's only two, big and small) or not
-- so for now they will be not randomized

-- Also they don't flee in https://www.youtube.com/watch?v=4Mj5tH2goIc but were
-- able to flee in http://youtube.com/watch?v=1eREORqoCr4 (no longer available)
-- Changed in TBC with their elite status I guess
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Small
(2060,0,0,0,54,0,100,0,0,0,0,0,0,3,0,729,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Smithers - On Just Summoned - Morph To Model 729"),
(2060,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2060,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Smithers - On Just Summoned - Start Waypoint"),
(2060,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Smithers - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2060,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Smithers - On Evade - Despawn (0)"),
-- Big
(2061,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Thatcher - On Just Summoned - Morph To Model 574"),
(2061,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2061,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Thatcher - On Just Summoned - Start Waypoint"),
(2061,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Thatcher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2061,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Thatcher - On Evade - Despawn (0)"),
-- Small
(2062,0,0,0,54,0,100,0,0,0,0,0,0,3,0,729,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Hendricks - On Just Summoned - Morph To Model 729"),
(2062,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2062,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Hendricks - On Just Summoned - Start Waypoint"),
(2062,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Hendricks - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2062,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Hendricks - On Evade - Despawn (0)"),
-- Big
(2063,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Wilhelm - On Just Summoned - Morph To Model 574"),
(2063,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2063,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Wilhelm - On Just Summoned - Start Waypoint"),
(2063,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Wilhelm - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2063,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Wilhelm - On Evade - Despawn (0)"),
-- Big
(2064,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Hartin - On Just Summoned - Morph To Model 574"),
(2064,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2064,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Hartin - On Just Summoned - Start Waypoint"),
(2064,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Hartin - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2064,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Hartin - On Evade - Despawn (0)"),
-- Big
(2065,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Cooper - On Just Summoned - Morph To Model 574"),
(2065,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2065,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Cooper - On Just Summoned - Start Waypoint"),
(2065,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Cooper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2065,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Cooper - On Evade - Despawn (0)"),
-- Big
(2066,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Higarth - On Just Summoned - Morph To Model 574"),
(2066,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2066,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Higarth - On Just Summoned - Start Waypoint"),
(2066,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Higarth - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2066,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Higarth - On Evade - Despawn (0)"),
-- Big
(2067,0,0,0,54,0,100,0,0,0,0,0,0,3,0,574,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Brunswick - On Just Summoned - Morph To Model 574"),
(2067,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2067,0,0,0,2,1,0,0,0,0,0,0,0,0,"Councilman Brunswick - On Just Summoned - Start Waypoint"),
(2067,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Councilman Brunswick - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2067,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Councilman Brunswick - On Evade - Despawn (0)"),
-- Small
(2068,0,0,0,54,0,100,0,0,0,0,0,0,3,0,729,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Mayor Morrison - On Just Summoned - Morph To Model 729"),
(2068,0,1,0,54,0,100,0,0,0,0,0,0,53,0,2068,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lord Mayor Morrison - On Link - Start Waypoint"),
(2068,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lord Mayor Morrison - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2068,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Mayor Morrison - On Evade - Despawn (0)");

DELETE FROM `waypoints` WHERE `entry` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(2060,1,-397.731445,1502.890625,19.770845,"Councilman Smithers"),
(2060,2,-401.691681,1499.818726,19.770845,"Councilman Smithers"),
(2061,1,-396.266296,1502.207153,19.770849,"Councilman Thatcher"),
(2061,2,-400.981476,1498.297241,19.770849,"Councilman Thatcher"),
(2062,1,-397.731445,1502.890625,19.770845,"Councilman Hendricks"),
(2062,2,-401.691681,1499.818726,19.770845,"Councilman Hendricks"),
(2063,1,-397.731445,1502.890625,19.770845,"Councilman Wilhelm"),
(2063,2,-401.691681,1499.818726,19.770845,"Councilman Wilhelm"),
(2064,1,-397.009979,1502.273804,19.747398,"Councilman Hartin"),
(2064,2,-401.794128,1498.638428,19.747398,"Councilman Hartin"),
(2065,1,-397.731445,1502.890625,19.770845,"Councilman Cooper"),
(2065,2,-401.691681,1499.818726,19.770845,"Councilman Cooper"),
(2066,1,-396.266296,1502.207153,19.770849,"Councilman Higarth"),
(2066,2,-400.981476,1498.297241,19.770849,"Councilman Higarth"),
(2067,1,-396.266296,1502.207153,19.770849,"Councilman Brunswick"),
(2067,2,-400.981476,1498.297241,19.770849,"Councilman Brunswick"),
(2068,1,-397.009979,1502.273804,19.747398,"Councilman Morrison"),
(2068,2,-401.794128,1498.638428,19.747398,"Councilman Morrison");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068) AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,2060,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2061,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2062,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2063,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2064,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2065,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2066,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2067,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active"),
(22,1,2068,0,0,12,1,25,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Nights' is active");
