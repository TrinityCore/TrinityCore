-- Yarlyn Amberstill
DELETE FROM `creature` WHERE `guid` IN (4151,4153);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(4151, 1352, 0, 0, 0, '0', 0, 0, 0, 0, 0, -5546.13, -1301.88, 399.909, 1.25519, 300, 0, 0, 8, 0, 2, 0, 0, 0, 0),
(4153, 1263, 0, 0, 0, '0', 0, 0, 0, 0, 0, -5547.62, -1306.45, 398.409, 4.45606, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`=4151;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(4151,41510,0,0,0,0,"");
DELETE FROM `waypoint_data` WHERE `id`=41510;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(41510,1,-5549,-1295.66,400.267,0,0,1,0,100,0),
(41510,2,-5555.14,-1286.75,400.705,0,0,1,0,100,0),
(41510,3,-5563.65,-1281.34,401.378,0,0,1,0,100,0),
(41510,4,-5571.76,-1283.92,401.595,0,0,1,0,100,0),
(41510,5,-5574.1,-1292.32,401.575,0,0,1,0,100,0),
(41510,6,-5550.61,-1316.42,398.663,0,0,1,0,100,0),
(41510,7,-5539.53,-1319.2,399.05,0,0,1,0,100,0),
(41510,8,-5527.46,-1315.68,401.761,0,0,1,0,100,0),
(41510,9,-5510.42,-1310.07,402.876,0,0,1,0,100,0),
(41510,10,-5496.35,-1307.78,404.306,0,0,1,0,100,0),
(41510,11,-5485.81,-1317.02,403.623,0,0,1,0,100,0),
(41510,12,-5482.9,-1328.74,403.128,0,0,1,0,100,0),
(41510,13,-5497.13,-1351.01,403.118,0,0,1,0,100,0),
(41510,14,-5506.29,-1361.86,401.173,0,0,1,0,100,0),
(41510,15,-5512.5,-1380.78,401.059,0,0,1,0,100,0),
(41510,16,-5523.74,-1388.3,400.524,0,0,1,0,100,0),
(41510,17,-5532.06,-1391.59,401.022,0,0,1,0,100,0),
(41510,18,-5536.64,-1400.22,402.253,0,0,1,0,100,0),
(41510,19,-5534.24,-1407.77,402.474,0,0,1,0,100,0),
(41510,20,-5526.26,-1409.96,402.421,0,0,1,0,100,0),
(41510,21,-5516.35,-1405.69,402.985,0,0,1,0,100,0),
(41510,22,-5512.02,-1380.34,401.147,0,0,1,0,100,0),
(41510,23,-5505.66,-1361.61,401.475,0,0,1,0,100,0),
(41510,24,-5496.98,-1350.89,403.125,0,0,1,0,100,0),
(41510,25,-5483.01,-1328.78,403.113,0,0,1,0,100,0),
(41510,26,-5485.76,-1316.7,403.664,0,0,1,0,100,0),
(41510,27,-5496.2,-1307.95,404.289,0,0,1,0,100,0),
(41510,28,-5510.93,-1310.19,402.859,0,0,1,0,100,0),
(41510,29,-5527.54,-1315.5,401.787,0,0,1,0,100,0),
(41510,30,-5537.08,-1315.39,399.541,0,0,1,0,100,0),
(41510,31,-5543.39,-1309.22,398.204,0,0,1,0,100,0);
DELETE FROM `creature_formations` WHERE `leaderGUID`=4151;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(4151,4151,0,0,512,0,0),
(4151,4153,4,0,512,0,0);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry`=1352;
UPDATE `creature_template` SET `speed_run`=0.85714, `AIName`="SmartAI" WHERE `entry`=1263;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1263 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1263,0,0,0,1,0,100,0,1000,15000,30000,45000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yarlyn Amberstill - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=1263;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1263,0,0,"Come back, Fluffy!",12,6,100,0,0,0,159,0,"Yarlyn Amberstill"),
(1263,0,1,"Why do you run from me, Fluffy?!",12,6,100,0,0,0,160,0,"Yarlyn Amberstill"),
(1263,0,2,"C\mon, Fluffy! I just want to give you a bath!",12,6,100,0,0,0,161,0,"Yarlyn Amberstill"),
(1263,0,3,"Fluffy! Fluffy, stop running!",12,6,100,0,0,0,162,0,"Yarlyn Amberstill"),
(1263,0,4,"Carrots every day for a year if you stop!",12,6,100,0,0,0,164,0,"Yarlyn Amberstill"),
(1263,0,5,"Don\t make me get my pappy to catch you! He likes to catch bunnies using his rifle!",12,6,100,0,0,0,165,0,"Yarlyn Amberstill");
