-- High Executor Anselm
UPDATE `creature_addon` SET `mount`=10721 WHERE `guid`=117743;
-- Forsaken Croaabowman
UPDATE `creature_addon` SET `bytes2`=2 WHERE `guid` IN (102612,102618,102620);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-102612,-102618,-102620) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-102612,0,0,0,1,0,100,0,1000,2000,2000,4000,0,11,42611,0,0,0,0,0,19,5202,0,0,0,0,0,0,0,"Forsaken Crossbowman - Out of Combat - Cast 'Shoot'"),
(-102618,0,0,0,1,0,100,0,1000,2000,2000,4000,0,11,42611,0,0,0,0,0,19,5202,0,0,0,0,0,0,0,"Forsaken Crossbowman - Out of Combat - Cast 'Shoot'"),
(-102620,0,0,0,1,0,100,0,1000,2000,2000,4000,0,11,42611,0,0,0,0,0,19,5202,0,0,0,0,0,0,0,"Forsaken Crossbowman - Out of Combat - Cast 'Shoot'");
-- Vengeance Landing Deathguard
DELETE FROM `creature_addon` WHERE `guid` IN (117673,117674);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `path_id`) VALUES 
(117673,10718,0,1,1176730), -- master
(117674,10718,0,1,0);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (117673);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(117673,117673,0,0,515,0,0),
(117673,117674,4,90,515,0,0);
-- Waypoints
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` = 117673;
UPDATE `creature` SET `position_x` = 2013.908936, `position_y` = -6164.616699, `position_z` = 15.733516, `orientation` = 1.57369, `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` = 117674;
DELETE FROM `waypoint_data` WHERE `id` IN (1176730);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(1176730,1,2016.24,-6157.87,13.1977,0,0,1.52477,100,0),
(1176730,2,2015.83,-6145.55,7.88017,0,0,1.67348,100,0),
(1176730,3,2014.28,-6133.29,6.46747,0,0,1.66955,100,0),
(1176730,4,2012.94,-6120.86,6.03301,0,0,1.6774,100,0),
(1176730,5,2011.75,-6107.13,6.63284,0,0,1.69704,100,0),
(1176730,6,2009.53,-6095.89,7.08266,0,0,1.88946,100,0),
(1176730,7,2007.67,-6090.07,7.64141,0,0,2.00334,100,0),
(1176730,8,2004.53,-6084.76,8.83384,0,0,2.26095,100,0),
(1176730,9,1998.68,-6080.14,10.576,0,0,2.64344,100,0),
(1176730,10,1989.88,-6077.4,12.7546,0,0,2.94582,100,0),
(1176730,11,1973.77,-6074.59,16.3861,0,0,3.21678,100,0),
(1176730,12,1965.13,-6075.81,17.5653,0,0,3.60556,100,0),
(1176730,13,1958.82,-6080.25,18.4291,0,0,3.73772,100,0),
(1176730,14,1951.8,-6085.63,20.1726,0,0,3.82412,100,0),
(1176730,15,1941.9,-6094.04,20.6644,0,0,3.93407,100,0),
(1176730,16,1939.54,-6099.86,20.5402,0,0,4.53882,100,0),
(1176730,17,1939.1,-6105.71,21.2091,0,0,4.75088,100,0),
(1176730,18,1939.12,-6110.8,22.4324,0,0,4.47285,100,0),
(1176730,19,1936.42,-6121.51,23.2113,0,0,4.498,100,0),
(1176730,20,1933.25,-6130.15,23.1697,0,0,4.71729,100,0),
(1176730,21,1934.82,-6135.03,23.2975,0,0,5.10213,100,0),
(1176730,22,1938.9,-6145.15,23.7109,0,0,5.01966,100,0),
(1176730,23,1939.97,-6152.59,23.7182,0,0,4.76205,100,0),
(1176730,24,1943.13,-6159.74,23.7036,0,0,5.38599,100,0),
(1176730,25,1950.22,-6169.12,24.1232,0,0,5.46453,100,0),
(1176730,26,1956.32,-6174.43,24.2589,0,0,5.84389,100,0),
(1176730,27,1964.69,-6178.04,24.0037,0,0,5.89102,100,0),
(1176730,28,1972.11,-6180.07,23.7833,0,0,6.1227,100,0),
(1176730,29,1978.29,-6180.39,23.7011,0,0,6.26015,100,0),
(1176730,30,1987.2,-6179.4,23.1245,0,0,0.03194,100,0),
(1176730,31,1995.8,-6178.26,19.8625,0,0,0.11048,100,0),
(1176730,32,2006.32,-6176.85,15.3594,0,0,0.14975,100,0),
(1176730,33,2013.16,-6175.09,15.3707,0,0,0.668113,100,0),
(1176730,34,2015.35,-6170.03,15.5007,0,0,1.28465,100,0),
(1176730,35,2015.85,-6164.67,15.7319,0,0,1.5831,100,0);

-- Apothecary Celestine
DELETE FROM `creature_template_addon` WHERE `entry` IN (23781);
INSERT INTO `creature_template_addon` (`entry`, `emote`) VALUES 
(23781,69);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42442;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42442,0,1,31,0,3,24921,0,0,0,'','Vengeance Landing Cannonfire'),
(13,1,42442,0,0,31,0,3,23803,0,0,0,'','Vengeance Landing Cannonfire');
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (23805);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(23805, 0, 0, 1, 0);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23805,23968); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23805,23968) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23805,0,0,0,1,0,100,0,1000,2000,4000,7000,0,11,42442,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vengeance Landing Cannon Controller - Out of Combat - Cast 'Vengeance Landing Cannonfire'"),
(23968,0,0,0,1,0,100,0,1000,30000,30000,45000,0,11,42686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hanes Fire Trigger - Out of Combat - Cast 'Serverside - Summon Fire'");

-- Forsaken Recruit
UPDATE `creature` SET `position_x` = 1972.96, `position_y` = -6254.06, `position_z` = 1.25329, `orientation` = 0.390811, `spawndist` = 0, `MovementType` = 2 WHERE `guid` = 118404;
UPDATE `creature` SET `position_x` = 1973.1,  `position_y` = -6254.7,  `position_z` = 1.25329, `orientation` = 0.390811, `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 118403;
UPDATE `creature` SET `position_x` = 1972.64, `position_y` = -6253.59, `position_z` = 1.25329, `orientation` = 0.390811, `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 118401;
UPDATE `creature` SET `position_x` = 1972.43, `position_y` = -6254.23, `position_z` = 1.25329, `orientation` = 0.34326,  `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 118402;
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (118404);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(118404,118404,0,0,515,0,0),
(118404,118403,2,90,515,0,0),
(118404,118401,2,270,515,0,0),
(118404,118402,2,360,515,0,0);
DELETE FROM creature_addon WHERE guid IN (118404);
INSERT INTO creature_addon (guid, mount, bytes1, bytes2, path_id) VALUES 
(118404,0,0,1,1184040);
DELETE FROM `waypoint_data` WHERE `id` IN (1184040);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(1184040,1,1977.54,-6251.92,1.25325,2000,0,0.482814,100,0),
(1184040,2,1989.75,-6244.71,1.25325,0,0,0.561354,100,0),
(1184040,3,1999.49,-6238.68,1.26237,0,0,0.384639,100,0),
(1184040,4,2007.32,-6235.63,5.29081,0,0,0.376785,100,0),
(1184040,5,2010.27,-6236.29,5.32908,0,0,5.38134,100,0),
(1184040,6,2009.43,-6239.24,5.32908,0,0,3.69667,100,0),
(1184040,7,2003.54,-6241.83,8.41202,0,0,3.49247,100,0),
(1184040,8,1997.87,-6242.26,8.58237,0,0,2.60889,100,0),
(1184040,9,1990.17,-6237.41,8.58352,0,0,2.45574,100,0),
(1184040,10,1987.09,-6234.06,8.62203,0,0,2.03241,100,0),
(1184040,11,1985.3,-6226.95,7.73933,10000,0,3.11693,100,0),
(1184040,12,1985.91,-6221.04,7.73933,0,0,0.821211,100,0),
(1184040,13,1997.99,-6214.67,7.73933,0,0,0.420497,100,0),
(1184040,14,2007.97,-6210.96,7.7388,0,0,0.65219,100,0),
(1184040,15,2011.58,-6204.69,7.89962,0,0,1.31585,100,0),
(1184040,16,2015.14,-6195.65,11.6578,0,0,1.43994,100,0),
(1184040,17,2015.56,-6185.98,15.7973,0,0,1.5105,100,0),
(1184040,18,2015.46,-6176.38,15.3872,0,0,1.61039,100,0),
(1184040,19,2014.71,-6164.41,15.7934,0,0,1.64181,100,0),
(1184040,20,2015.76,-6156.04,12.4072,0,0,1.57505,100,0),
(1184040,21,2015.16,-6145.36,7.86001,0,0,1.64181,100,0),
(1184040,22,2014.01,-6131.76,6.38754,0,0,1.66537,100,0),
(1184040,23,2012.71,-6120.14,5.99595,0,0,1.71249,100,0),
(1184040,24,2011.76,-6108.17,6.56669,0,0,1.64966,100,0),
(1184040,25,2009.49,-6095.97,7.07232,0,0,1.88921,100,0),
(1184040,26,2006.13,-6088.4,8.03768,0,0,2.13268,100,0),
(1184040,27,2001.07,-6082.28,9.85732,0,0,2.54894,100,0),
(1184040,28,1994.55,-6078.78,11.6305,0,0,2.76493,100,0),
(1184040,29,1986.24,-6075.43,13.6475,0,0,2.94164,100,0),
(1184040,30,1975.85,-6074.51,15.9894,0,0,3.13406,100,0),
(1184040,31,1967.14,-6075.05,17.3374,0,0,3.20082,100,0),
(1184040,32,1961.05,-6075.53,17.7725,0,0,2.82148,100,0),
(1184040,33,1956.93,-6073.34,17.4238,0,0,2.31725,100,0),
(1184040,34,1953.77,-6067.5,16.3958,0,0,1.99524,100,0),
(1184040,35,1952.29,-6060.38,15.2479,0,0,1.5829,100,0),
(1184040,36,1952.62,-6052.13,14.5453,0,0,1.29231,100,0),
(1184040,37,1956.05,-6045.36,13.7723,0,0,0.971828,100,0),
(1184040,38,1963.5,-6040.85,13.5027,0,0,0.418122,100,0),
(1184040,39,1972.26,-6036.53,12.5244,5000,0,0.484881,100,0);

-- Dark Ranger
DELETE FROM creature WHERE guid IN (89157,89212);
INSERT INTO creature (guid, id, map, spawnmask, phasemask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType) values
(89157,23776,571,1,1,0,1,1966.86,-6262.24,13.636,0.416786,300,0,0,14415,0,2),
(89212,23776,571,1,1,0,1,1966.45,-6261.53,13.636,0.334319,300,0,0,14415,0,0);
DELETE FROM creature_addon WHERE guid IN (89157,89212);
INSERT INTO creature_addon (guid, mount, bytes1, bytes2, path_id) VALUES 
(89157,10718,0,1,891570), -- master
(89212,10718,0,1,0);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (89157);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(89157,89157,0,0,515,0,0),
(89157,89212,4,0,515,0,0);
DELETE FROM `waypoint_data` WHERE `id` IN (891570);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(891570,1,1968.06,-6261.8,13.637,120000,5,0.380826,100, 0),
(891570,2,1972.76,-6259.87,14.6937,0,0,0.608592,100,0),
(891570,3,1976.97,-6255.25,14.4775,0,0,1.00129,100,0),
(891570,4,1986.89,-6242.99,13.8749,0,0,0.639729,100,0),
(891570,5,1991.34,-6240.14,8.58528,0,0,1.39371,100,0),
(891570,6,1991.53,-6237.17,8.58528,0,0,2.21524,100,0),
(891570,7,1987.39,-6234.63,8.48948,0,0,1.90815,100,0),
(891570,8,1985.53,-6224.06,7.73862,0,0,1.7118,100,0),
(891570,9,1992.64,-6219.13,7.73862,0,0,0.588678,100,0),
(891570,10,2001.36,-6212.46,7.73862,0,0,0.631875,100,0),
(891570,11,2012.76,-6204.6,7.89861,0,0,0.623161,100,0),
(891570,12,2015,-6202.05,8.90979,0,0,1.23577,100,0),
(891570,13,2014.37,-6186.23,15.6992,0,0,1.64038,100,0),
(891570,14,2012.21,-6179.49,15.394,0,0,2.14696,100,0),
(891570,15,2006.72,-6176.76,15.3592,0,0,2.89152,100,0),
(891570,16,1997.09,-6177.13,19.2825,0,0,3.17583,100,0),
(891570,17,1987.3,-6177.98,23.3879,0,0,3.26615,100,0),
(891570,18,1976.95,-6178.97,23.7202,0,0,3.08316,100,0),
(891570,19,1967.51,-6178.25,23.9363,0,0,3.03603,100,0),
(891570,20,1958.1,-6175.62,24.2028,0,0,2.76507,100,0),
(891570,21,1949.09,-6169.15,24.0711,0,0,2.50981,100,0),
(891570,22,1941.59,-6166,23.6998,0,0,3.07923,100,0),
(891570,23,1924.51,-6166.94,23.7876,0,0,3.1774,100,0),
(891570,24,1912.73,-6165.86,23.0089,0,0,2.80041,100,0),
(891570,25,1905.4,-6159.84,21.6651,0,0,2.25063,100,0),
(891570,26,1900.11,-6149.83,18.502,0,0,2.05036,100,0),
(891570,27,1895.57,-6141.51,18.0577,0,0,2.0857,100,0),
(891570,28,1893.9,-6137.66,18.0577,0,0,1.57519,100,0),
(891570,29,1894.31,-6126.74,18.1256,0,0,1.45765,100,0),
(891570,30,1895.81,-6118.22,18.3296,0,0,1.97602,100,0),
(891570,31,1887.19,-6109.54,18.1207,0,0,2.60434,100,0),
(891570,32,1878.36,-6103.71,18.0258,0,0,2.69858,100,0),
(891570,33,1868.98,-6100.17,17.2504,0,0,2.93333,100,0),
(891570,34,1857.29,-6100.18,15.4363,0,0,3.16109,100,0),
(891570,35,1842.48,-6102.49,13.5645,0,0,3.56165,100,0),
(891570,36,1833.03,-6107.17,12.5284,0,0,3.91491,100,0),
(891570,37,1825.68,-6115.29,10.637,0,0,4.04843,100,0),
(891570,38,1814.87,-6129.22,10.0362,0,0,4.07984,100,0),
(891570,39,1809.67,-6138.8,9.84111,0,0,4.38222,100,0),
(891570,40,1806.8,-6155.59,8.07283,0,0,4.57071,100,0),
(891570,41,1804.64,-6170.94,5.94955,0,0,4.57464,100,0),
(891570,42,1803.19,-6183.59,5.57056,5000,0,4.62569,100,0);
-- Morris Family
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (118144);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(118144,118144,0,0,515,0,0),
(118144,115143,1,270,515,0,0),
(118144,118200,2,270,515,0,0),
(118144,118249,3,0,515,0,0),
(118144,115231,3,15,515,0,0),
(118144,118045,3,30,515,0,0);
DELETE FROM creature_addon WHERE guid IN (118144);
INSERT INTO creature_addon (guid, mount, bytes1, bytes2, path_id) VALUES 
(118144,0,0,1,1181440);
UPDATE creature SET spawndist = 0, MovementType = 2 WHERE guid = 118144; -- master
DELETE FROM `waypoint_data` WHERE `id` IN (1181440);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(1181440,1,1979.35,-6255.47,8.58476,40000,0,0.376571,100,0),
(1181440,2,1984.87,-6253.24,8.58476,0,0,0.32552,100,0),
(1181440,3,1990.82,-6250.85,8.58476,0,0,0.451184,100,0),
(1181440,4,1995.73,-6248.42,8.58476,0,0,1.16982,100,0),
(1181440,5,1995.47,-6241.94,8.58302,0,0,1.80207,100,0),
(1181440,6,1990.43,-6237.06,8.58344,0,0,2.46573,100,0),
(1181440,7,1987.03,-6234.24,8.5071,0,0,1.69054,100,0),
(1181440,8,1985.58,-6226.35,7.73876,20000,0,3.31475,100,0),
(1181440,9,1986.77,-6221.69,7.73876,0,0,0.65618,100,0),
(1181440,10,1994.25,-6216.97,7.73876,0,0,0.515594,100,0),
(1181440,11,2003.94,-6211.56,7.73876,0,0,0.515594,100,0),
(1181440,12,2013.67,-6204.89,7.89386,0,0,1.65049,100,0),
(1181440,13,2014.42,-6195.4,11.7727,0,0,1.48949,100,0),
(1181440,14,2014.66,-6186,15.7962,0,0,1.57195,100,0),
(1181440,15,2014.63,-6176.89,15.3869,0,0,1.59039,100,0),
(1181440,16,2014.64,-6164.27,15.8498,0,0,1.55897,100,0),
(1181440,17,2016.01,-6155.96,12.3781,0,0,1.53934,100,0),
(1181440,18,2015.22,-6145.53,7.87425,0,0,1.60217,100,0),
(1181440,19,2013.88,-6129.59,6.28219,0,0,1.72391,100,0),
(1181440,20,2012.7,-6117.38,6.04007,0,0,1.64144,100,0),
(1181440,21,2011.24,-6105.77,6.73958,0,0,1.73569,100,0),
(1181440,22,2009.26,-6096.05,7.03634,0,0,1.86921,100,0),
(1181440,23,2005.91,-6088.15,8.11917,0,0,2.16373,100,0),
(1181440,24,2000.91,-6081.72,9.93104,0,0,2.76063,100,0),
(1181440,25,1994.18,-6078.81,11.7192,5000,0,2.90975,100,0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (29302,29419,29422);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- 
(29302,0,0,"Looks like you brought the whole family! What's your business here, then?",12,0,100,0,0,0,29933,0,"Deathguard Hemil"),
(29419,0,0,"We're here for civilian work, sir.",12,0,100,0,0,0,30118,0,"Julian Morris"),
(29302,1,0,"Work?  You are aware this is a warzone, citizen?  What is your profession?",12,0,100,0,0,0,29934,0,"Deathguard Hemil"),
(29419,1,0,"Well... we\'re undertakers, sir.",12,0,100,0,0,0,30119,0,"Julian Morris"),
(29302,2,0,"Right.  Go ahead.",12,0,100,0,0,0,29935,0,"Deathguard Hemil"),
-- 
(29302,3,0,"Her Majesty sends Dark Rangers! Stand aside, boys!",12,0,100,0,0,0,29936,0,"Deathguard Hemil"),
-- 
(29302,4,0,"You must be the sorriest bunch of recruits I've seen today!  Fall in formations and report to High Executor Anselm!",12,0,100,0,0,0,29938,0,"Deathguard Hemil"),
(29302,4,1,"Aren't you a sorry sight!  I suppose you're a little better than yesterday's bunch.  Formations, now!  Report for duty!",12,0,100,0,0,0,29939,0,"Deathguard Hemil"),
(29302,4,2,"Wipe that worthless grin off your faces, recruits!  If the High Executor sees you like that he will kill you all himself!,",12,0,100,0,0,0,29940,0,"Deathguard Hemil"),
(29422,0,0,"Yes, sir!",12,0,100,66,0,0,30120,0,"Forsaken Recruit");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29419,23776,29422);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29419,23776,29422) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2941900,2942200) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29419,0,0,0,34,0,100,0,2,7,0,0,80,2941900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Julian Morris - In movement informer - action list"),
(2941900,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,29302,0,0,0,0,0,0,"Julian Morris - Action list - Say text"),
(2941900,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Julian Morris - Action list - Say text"),
(2941900,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,29302,0,0,0,0,0,0,"Julian Morris - Action list - Say text"),
(2941900,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Julian Morris - Action list - Say text"),
(2941900,9,5,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,29302,0,0,0,0,0,0,"Julian Morris - Action list - Say text"),
(29419,0,1,0,34,0,100,0,2,24,0,0,41,0,0,0,0,0,0,19,29420,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29419,0,2,0,34,0,100,0,2,24,0,0,41,0,0,0,0,0,0,19,30157,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29419,0,3,0,34,0,100,0,2,24,0,0,41,0,0,0,0,0,0,19,29421,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29419,0,4,0,34,0,100,0,2,24,0,0,41,0,0,0,0,0,0,19,30158,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29419,0,5,0,34,0,100,0,2,24,0,0,41,0,0,0,0,0,0,19,29418,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29419,0,6,0,34,0,100,0,2,24,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Julian Morris - In movement informer - Despawn"),
(29422,0,0,0,34,0,100,0,2,10,0,0,80,2942200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Recruit - In movement informer - Action list"),
(2942200,9,0,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,29302,0,0,0,0,0,0,"Forsaken Recruit - Action list - Say text"),
(2942200,9,1,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,11,29422,30,0,0,0,0,0,"Forsaken Recruit - Action list - Set data"),
(2942200,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Recruit - Action list - Say text"),
(29422,0,1,0,34,0,100,0,2,38,0,0,41,0,0,0,0,0,0,11,29422,30,0,0,0,0,0,"Forsaken Recruit - In movement informer - Despawn"),
(29422,0,2,0,34,0,100,0,2,38,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Recruit - In movement informer - Despawn"),
(29422,0,3,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Recruit - On data set - Say text"),
(23776,0,0,0,34,0,100,0,2,7,0,0,1,3,0,0,0,0,0,19,29302,0,0,0,0,0,0,"Dark Ranger - In movement informer - Say text"),
(23776,0,1,0,34,0,100,0,2,41,0,0,41,0,0,0,0,0,0,19,23776,0,0,0,0,0,0,"Dark Ranger - In movement informer - Despawn"),
(23776,0,2,0,34,0,100,0,2,41,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger - In movement informer - Despawn");
