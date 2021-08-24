--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29434;

UPDATE `creature` SET `position_x` = 6630.177734375, `position_y` = -1250.8863525390625, `position_z` = 396.214141845703125, `orientation` = 6.038839340209960937, `VerifiedBuild` = 12340 WHERE `guid` = 202337 AND `id` = 29434;
DELETE FROM `creature` WHERE `guid` IN (83063,83064) AND `id` = 29434;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(83063,29434,571,0,0,1,1,0,1,6646.88818359375,-1110.958984375,427.337738037109375,3.228859186172485351,300,0,0,0,0,0,0,0,0,'',12340),
(83064,29434,571,0,0,1,1,0,1,6690.49365234375,-1167.4114990234375,398.814910888671875,3.769911050796508789,300,0,0,0,0,0,0,0,0,'',12340);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9859;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9859,13651,0,0,47,0,12832,10,0,0,0,0,"","Group 0: Show gossip text 13651 if quest 'Bitter Departure' is taken");

DELETE FROM `gossip_menu` WHERE `MenuID` = 9859 AND `TextID` = 13651;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(9859,13651,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29434 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2943400 AND 2943402 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29434,0,0,0,11,0,100,0,0,0,0,0,0,11,51329,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Respawn - Cast 'Feign Death'"),
(29434,0,1,0,19,0,100,0,12832,0,0,0,0,80,2943400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Quest 'Bitter Departure' Taken - Run Script"),
-- Everything below except action list 2943400 is not sniffed
(29434,0,2,0,62,0,100,0,9859,0,0,0,0,80,2943401,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Gossip Option 0 Selected - Run Script"),
(29434,0,3,0,40,0,100,0,27,2943400,0,0,0,80,2943402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Waypoint 27 Reached - Run Script"),
(29434,0,4,0,40,0,100,0,24,2943401,0,0,0,80,2943402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Waypoint 24 Reached - Run Script"),
(29434,0,5,0,40,0,100,0,18,2943402,0,0,0,80,2943402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Waypoint 18 Reached - Run Script"),
(29434,0,6,0,58,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Waypoint Finished - Despawn Instant"),
(29434,0,7,0,6,0,100,0,0,0,0,0,0,6,12832,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Injured Goblin Miner - On Death - Fail Quest 'Bitter Departure'"),

-- Somehow both player and creature are hit, probably that spell makes creature despawn if player
-- refused to continue or just handles actions below or both
(2943400,9,0,0,0,0,100,0,0,0,0,0,0,11,55612,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Cast 'Goblin Miner Quest Ready'"),
(2943400,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Say Line 0"),
(2943400,9,2,0,0,0,100,0,0,0,0,0,0,28,51329,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Remove Aura 'Feign Death'"),
-- Probably does what it says, it doesn't look like they have something like 'path assigned directly to guid or entry'
-- In other words they have to start somehow closest path by using that spell, probably
(2943401,9,0,0,0,0,100,0,0,0,0,0,0,11,55611,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Cast 'Goblin Miner Escort Start'"),
(2943401,9,1,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Store Targetlist"),
(2943401,9,2,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Set Faction 113"),
(2943401,9,3,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Remove NPC Flags Gossip & Questgiver"),
(2943401,9,4,0,0,0,100,0,2000,2000,0,0,0,113,2943400,2943401,2943402,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Start Closest Waypoint"),
(2943401,9,5,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Set Run On"),

(2943402,9,0,0,0,0,100,0,0,0,0,0,0,11,55616,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Cast 'Goblin Miner Quest Complete'"),
(2943402,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Goblin Miner - On Script - Say Line 1");

DELETE FROM `script_waypoint` WHERE `entry` = 29434;
DELETE FROM `waypoints` WHERE `entry` IN (2943400,2943401,2943402);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(2943400,1,6645.47,-1263.66,396.938,0,0,"Injured Goblin Miner"),
(2943400,2,6662.06,-1274.13,397.319,0,0,"Injured Goblin Miner"),
(2943400,3,6666.29,-1254.59,396.11,0,0,"Injured Goblin Miner"),
(2943400,4,6669.33,-1240.06,397.789,0,0,"Injured Goblin Miner"),
(2943400,5,6654.31,-1205.01,399.823,0,0,"Injured Goblin Miner"),
(2943400,6,6657.03,-1170.15,398.755,0,0,"Injured Goblin Miner"),
(2943400,7,6667.33,-1146.28,399.014,0,0,"Injured Goblin Miner"),
(2943400,8,6670.9,-1138.68,397.125,0,0,"Injured Goblin Miner"),
(2943400,9,6685.09,-1103.95,396.828,0,0,"Injured Goblin Miner"),
(2943400,10,6688.71,-1094.32,395.019,0,0,"Injured Goblin Miner"),
(2943400,11,6684.75,-1084.31,396.916,0,0,"Injured Goblin Miner"),
(2943400,12,6679.3,-1074.4,404.284,0,0,"Injured Goblin Miner"),
(2943400,13,6691.91,-1051.96,407.983,0,0,"Injured Goblin Miner"),
(2943400,14,6696.28,-1016.54,414.823,0,0,"Injured Goblin Miner"),
(2943400,15,6675.32,-1005.06,414.844,0,0,"Injured Goblin Miner"),
(2943400,16,6661.01,-1007.41,414.946,0,0,"Injured Goblin Miner"),
(2943400,17,6643.75,-1010.24,420.508,0,0,"Injured Goblin Miner"),
(2943400,18,6620.76,-1012.59,424.378,0,0,"Injured Goblin Miner"),
(2943400,19,6610.33,-996.992,428.116,0,0,"Injured Goblin Miner"),
(2943400,20,6581.3,-1005.9,434.257,0,0,"Injured Goblin Miner"),
(2943400,21,6570.74,-1013,434.076,0,0,"Injured Goblin Miner"),
(2943400,22,6551.68,-1012.38,433.218,0,0,"Injured Goblin Miner"),
(2943400,23,6530.83,-1024.99,433.04,0,0,"Injured Goblin Miner"),
(2943400,24,6510.05,-1031.23,435.824,0,0,"Injured Goblin Miner"),
(2943400,25,6491.5,-1032.46,434.226,0,0,"Injured Goblin Miner"),
(2943400,26,6475.58,-1023.13,434.759,0,0,"Injured Goblin Miner"),
(2943400,27,6451.81,-1025.43,431.502,6.2,5000,"Injured Goblin Miner"),
(2943400,28,6426.976074,-1032.857178,426.838379,0,0,"Injured Goblin Miner"),

(2943401,1,6639.489258,-1110.649536,427.121887,0,0,"Injured Goblin Miner"),
(2943401,2,6639.994141,-1103.572266,426.784698,0,0,"Injured Goblin Miner"),
(2943401,3,6652.661621,-1103.329590,424.513153,0,0,"Injured Goblin Miner"),
(2943401,4,6670.720703,-1114.010864,424.797729,0,0,"Injured Goblin Miner"),
(2943401,5,6670.794922,-1129.579956,423.808563,0,0,"Injured Goblin Miner"),
(2943401,6,6659.780762,-1133.140869,421.726227,0,0,"Injured Goblin Miner"),
(2943401,7,6643.547852,-1127.611450,416.798828,0,0,"Injured Goblin Miner"),
(2943401,8,6627.361816,-1126.778564,414.383362,0,0,"Injured Goblin Miner"),
(2943401,9,6616.920898,-1114.043335,411.758087,0,0,"Injured Goblin Miner"),
(2943401,10,6618.062012,-1093.986694,411.231140,0,0,"Injured Goblin Miner"),
(2943401,11,6617.839844,-1084.782471,414.162201,0,0,"Injured Goblin Miner"),
(2943401,12,6623.201660,-1070.807007,414.901611,0,0,"Injured Goblin Miner"),
(2943401,13,6629.339844,-1057.896851,415.200256,0,0,"Injured Goblin Miner"),
(2943401,14,6625.998535,-1043.035889,417.973541,0,0,"Injured Goblin Miner"),
(2943401,15,6623.543457,-1030.607666,423.388062,0,0,"Injured Goblin Miner"),
(2943401,16,6615.594238,-1019.000488,426.380249,0,0,"Injured Goblin Miner"),
(2943401,17,6596.823730,-1014.770752,429.281708,0,0,"Injured Goblin Miner"),
(2943401,18,6572.770508,-1022.431458,433.099487,0,0,"Injured Goblin Miner"),
(2943401,19,6552.164062,-1025.054932,433.381958,0,0,"Injured Goblin Miner"),
(2943401,20,6531.219238,-1024.119873,433.053436,0,0,"Injured Goblin Miner"),
(2943401,21,6522.533691,-1036.800171,432.977020,0,0,"Injured Goblin Miner"),
(2943401,22,6508.579590,-1038.284424,433.378571,0,0,"Injured Goblin Miner"),
(2943401,23,6486.433105,-1033.114502,433.741486,0,0,"Injured Goblin Miner"),
(2943401,24,6451.212891,-1034.432129,431.098267,0.2,5000,"Injured Goblin Miner"),
(2943401,25,6426.976074,-1032.857178,426.838379,0,0,"Injured Goblin Miner"),

(2943402,1,6674.806641,-1151.080200,398.016205,0,0,"Injured Goblin Miner"),
(2943402,2,6672.799805,-1134.866455,397.098877,0,0,"Injured Goblin Miner"),
(2943402,3,6682.981445,-1110.725708,397.012787,0,0,"Injured Goblin Miner"),
(2943402,4,6686.041016,-1098.317017,395.645538,0,0,"Injured Goblin Miner"),
(2943402,5,6678.679688,-1078.128906,402.279236,0,0,"Injured Goblin Miner"),
(2943402,6,6678.875488,-1052.984253,407.270905,0,0,"Injured Goblin Miner"),
(2943402,7,6673.411133,-1034.720459,412.358368,0,0,"Injured Goblin Miner"),
(2943402,8,6655.419922,-1017.152832,415.685638,0,0,"Injured Goblin Miner"),
(2943402,9,6637.676270,-1012.292664,422.505157,0,0,"Injured Goblin Miner"),
(2943402,10,6611.596191,-1015.275696,427.550171,0,0,"Injured Goblin Miner"),
(2943402,11,6587.860840,-1021.277771,430.110535,0,0,"Injured Goblin Miner"),
(2943402,12,6569.570312,-1023.147217,433.426422,0,0,"Injured Goblin Miner"),
(2943402,13,6549.567383,-1027.859253,433.062622,0,0,"Injured Goblin Miner"),
(2943402,14,6530.157227,-1028.086426,432.984924,0,0,"Injured Goblin Miner"),
(2943402,15,6508.740723,-1033.076538,435.571320,0,0,"Injured Goblin Miner"),
(2943402,16,6490.142090,-1030.373291,434.398651,0,0,"Injured Goblin Miner"),
(2943402,17,6466.509277,-1029.232056,433.822693,0,0,"Injured Goblin Miner"),
(2943402,18,6438.535156,-1029.557373,428.909821,0.8,5000,"Injured Goblin Miner"),
(2943402,19,6417.557617,-1028.709961,426.272186,0,0,"Injured Goblin Miner");
