--
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 4508;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4508 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 450800 AND 450808 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4508,0,0,0,19,0,100,0,1144,0,0,0,0,80,450800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Quest 'Willix the Importer' Taken - Run Script"),

(450800,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Store Targetlist"),
(450800,9,1,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Set Faction 250"),
(450800,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Remove NPC Flag Questgiver"),
(450800,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 0"),
(450800,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,3606401,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,1,0,58,0,100,0,0xFFFFFFFF,3606401,0,0,0,80,450801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450801,9,0,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 1"),
(450801,9,1,0,0,0,100,0,3000,3000,0,0,0,53,0,3606409,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,2,0,58,0,100,0,0xFFFFFFFF,3606409,0,0,0,80,450802,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450802,9,0,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 2"),
(450802,9,1,0,0,0,100,0,0,0,0,0,0,53,0,3606417,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,3,0,58,0,100,0,0xFFFFFFFF,3606417,0,0,0,80,450803,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450803,9,0,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 3"),
(450803,9,1,0,0,0,100,0,0,0,0,0,0,53,0,3606425,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,4,0,58,0,100,0,0xFFFFFFFF,3606425,0,0,0,80,450804,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450804,9,0,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 4"),
(450804,9,1,0,0,0,100,0,0,0,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Summon Group 0"),
(450804,9,2,0,0,0,100,0,0,0,0,0,0,53,0,3606433,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,5,0,58,0,100,0,0xFFFFFFFF,3606433,0,0,0,80,450805,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450805,9,0,0,0,0,100,0,1000,1000,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 5"),
(450805,9,1,0,0,0,100,0,0,0,0,0,0,53,0,3606441,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,6,0,58,0,100,0,0xFFFFFFFF,3606441,0,0,0,80,450806,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450806,9,0,0,0,0,100,0,1000,1000,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 6"),
(450806,9,1,0,0,0,100,0,0,0,0,0,0,53,0,3606449,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,7,0,58,0,100,0,0xFFFFFFFF,3606449,0,0,0,80,450807,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450807,9,0,0,0,0,100,0,1000,1000,0,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 7"),
(450807,9,1,0,0,0,100,0,0,0,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Summon Group 1"),
(450807,9,2,0,0,0,100,0,5000,5000,0,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 8"),
(450807,9,3,0,0,0,100,0,0,0,0,0,0,15,1144,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Quest Credit 'Willix the Importer'"),
(450807,9,4,0,0,0,100,0,0,0,0,0,0,2,69,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Set Faction 69"),
(450807,9,5,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Add Npc Flag Questgiver"),
-- Below guessed
(450807,9,6,0,0,0,100,0,180000,180000,0,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Script - Say Line 9"),
(450807,9,7,0,0,0,100,0,0,0,0,0,0,53,0,3606457,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Start Waypoint"),

(4508,0,8,0,58,0,100,0,0xFFFFFFFF,3606457,0,0,0,80,450808,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Waypoint Finished - Run Script"),

(450808,9,0,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Willix the Importer - On Script - Despawn Instant"),

(4508,0,9,0,4,0,15,0,0,0,0,0,0,1,10,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Willix the Importer - On Aggro - Say Line 10"),

(4508,0,10,0,6,0,100,0,0,0,0,0,0,6,1144,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Willix the Importer - On Death - Fail Quest 'Willix the Importer'");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 4508 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(4508,0,0,4514,2145.7168,1726.6263,51.936977,2.721183538436889648,4,60000,"Willix the Importer - Group 0 - Raging Agam'ar"),
(4508,0,0,4514,2148.4658,1732.5813,51.897450,3.228859186172485351,4,60000,"Willix the Importer - Group 0 - Raging Agam'ar"),
(4508,0,1,4514,1967.0083,1598.4280,81.058530,3.273414373397827148,4,60000,"Willix the Importer - Group 1 - Raging Agam'ar"),
(4508,0,1,4514,1969.7242,1601.2389,80.431830,3.298672199249267578,4,60000,"Willix the Importer - Group 1 - Raging Agam'ar");

DELETE FROM `waypoint_path` WHERE `PathId` = 36066;
DELETE FROM `waypoint_path_node` WHERE `PathId` = 36066;

DELETE FROM `waypoint_path` WHERE `PathId` IN (3606401,3606409,3606417,3606425,3606433,3606441,3606449,3606457);
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(3606401,0,0,NULL,'Migrated from refactor'),
(3606409,0,0,NULL,'Migrated from refactor'),
(3606417,0,0,NULL,'Migrated from refactor'),
(3606425,0,0,NULL,'Migrated from refactor'),
(3606433,0,0,NULL,'Migrated from refactor'),
(3606441,0,0,NULL,'Migrated from refactor'),
(3606449,0,0,NULL,'Migrated from refactor'),
(3606457,0,0,NULL,'Migrated from refactor');

DELETE FROM `waypoint_path_node` WHERE `PathId` IN (3606401,3606409,3606417,3606425,3606433,3606441,3606449,3606457);
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(3606401,1,2184.9822,1835.0039,59.86851,NULL,0),

(3606409,1,2166.6384,1854.7162,57.592236,NULL,0),
(3606409,2,2157.3577,1854.9065,55.602158,NULL,0),
(3606409,3,2153.4673,1852.6602,53.291454,NULL,0),
(3606409,4,2142.7424,1844.9857,48.762497,NULL,0),
(3606409,5,2137.1711,1840.3002,47.91533,NULL,0),
(3606409,6,2135.8704,1832.2656,46.650414,NULL,0),
(3606409,7,2135.7842,1822.5825,46.77384,NULL,0),
(3606409,8,2134.418,1814.5844,46.781307,NULL,0),
(3606409,9,2127.0889,1805.0176,46.83733,NULL,0),
(3606409,10,2120.1821,1798.7981,47.37992,NULL,0),
(3606409,11,2113.5994,1795.7913,47.761383,NULL,0),

(3606417,1,2097.2703,1789.3093,50.87806,NULL,0),
(3606417,2,2089.8,1786.4364,52.51884,NULL,0),
(3606417,3,2083.5083,1784.7682,53.985424,NULL,0),
(3606417,4,2077.7734,1783.3955,55.2612,NULL,0),
(3606417,5,2073.533,1779.6217,55.803577,NULL,0),
(3606417,6,2066.229,1772.921,57.292404,NULL,0),
(3606417,7,2059.8037,1771.465,58.410603,NULL,0),
(3606417,8,2052.2012,1770.2249,58.824398,NULL,0),
(3606417,9,2042.7672,1766.2555,60.009483,NULL,0),

(3606425,1,2035.2274,1753.339,60.447002,NULL,0),
(3606425,2,2033.9052,1745.2197,60.466377,NULL,0),
(3606425,3,2033.8594,1735.5001,60.753407,NULL,0),
(3606425,4,2034.8206,1726.9822,60.627968,NULL,0),
(3606425,5,2036.9271,1721.6207,60.200397,NULL,0),
(3606425,6,2039.4012,1716.8102,60.01561,NULL,0),
(3606425,7,2046.3212,1709.4685,59.614483,NULL,0),
(3606425,8,2051.8352,1704.3961,59.011375,NULL,0),
(3606425,9,2060.3647,1701.6138,58.468163,NULL,0),
(3606425,10,2071.5977,1701.4401,57.24946,NULL,0),
(3606425,11,2080.6086,1703.4143,56.65886,NULL,0),
(3606425,12,2090.0396,1706.752,56.50015,NULL,0),
(3606425,13,2100.1792,1715.869,54.63017,NULL,0),

(3606433,1,2111.7773,1727.5934,53.578506,NULL,0),
(3606433,2,2121.4128,1732.7437,52.923294,NULL,0),
(3606433,3,2129.9978,1734.7412,52.065136,NULL,0),
(3606433,4,2137.6743,1734.5045,51.93174,NULL,0),
(3606433,5,2147.1538,1730.2831,51.765865,NULL,0),
(3606433,6,2156.225,1723.2633,52.14113,NULL,0),
(3606433,7,2161.0212,1715.5737,53.069454,NULL,0),
(3606433,8,2163.305,1706.8594,54.337376,NULL,0),
(3606433,9,2163.6943,1696.58,55.472157,NULL,0),
(3606433,10,2160.4727,1690.9844,56.782005,NULL,0),
(3606433,11,2155.5955,1686.1584,57.875053,NULL,0),
(3606433,12,2149.8132,1680.13,58.0093,NULL,0),
(3606433,13,2143.8298,1676.6147,58.00794,NULL,0),
(3606433,14,2135.929,1673.4115,58.434864,NULL,0),
(3606433,15,2129.5115,1672.1378,58.938347,NULL,0),
(3606433,16,2120.024,1670.6798,59.023964,NULL,0),
(3606433,17,2112.1594,1670.3827,59.18009,NULL,0),
(3606433,18,2103.4446,1671.734,59.17758,NULL,0),
(3606433,19,2099.0474,1672.6481,59.88399,NULL,0),
(3606433,20,2088.258,1673.1373,61.252632,NULL,0),
(3606433,21,2081.069,1669.8579,61.24878,NULL,0),
(3606433,22,2074.7048,1664.9502,61.231228,NULL,0),
(3606433,23,2068.138,1658.0231,61.240517,NULL,0),
(3606433,24,2065.1865,1651.5103,61.203484,NULL,0),
(3606433,25,2063.264,1642.8959,62.12069,NULL,0),
(3606433,26,2063.9106,1637.3577,63.62475,NULL,0),
(3606433,27,2064.3074,1631.4198,64.49529,NULL,0),
(3606433,28,2064.2214,1609.5265,62.38478,NULL,0),

(3606441,1,2061.4136,1594.0212,62.913113,NULL,0),
(3606441,2,2060.8352,1587.7548,63.50159,NULL,0),
(3606441,3,2060.92,1581.7162,63.989983,NULL,0),
(3606441,4,2060.5627,1568.6227,66.582245,NULL,0),
(3606441,5,2059.0796,1562.1904,67.90953,NULL,0),
(3606441,6,2057.4543,1555.9479,69.81415,NULL,0),
(3606441,7,2054.8723,1551.19,71.85053,NULL,0),
(3606441,8,2046.2444,1544.615,75.84767,NULL,0),
(3606441,9,2040.5182,1543.5066,77.81182,NULL,0),
(3606441,10,2034.842,1543.4518,79.505844,NULL,0),
(3606441,11,2027.8698,1538.7988,80.94072,NULL,0),

(3606449,1,2020.8691,1539.2756,80.820175,NULL,0),
(3606449,2,2016.0541,1548.2653,81.073814,NULL,0),
(3606449,3,2012.8672,1553.107,80.72809,NULL,0),
(3606449,4,2006.2244,1559.5234,81.05614,NULL,0),
(3606449,5,2004.6276,1563.7064,81.24209,NULL,0),
(3606449,6,2003.7891,1572.111,81.85367,NULL,0),
(3606449,7,2001.1139,1582.8323,81.204994,NULL,0),
(3606449,8,1999.6489,1588.7372,80.62329,NULL,0),
(3606449,9,1993.3217,1598.7571,79.51372,NULL,0),
(3606449,10,1987.9791,1600.7035,79.683815,NULL,0),
(3606449,11,1978.8535,1600.8456,79.8718,NULL,0),
(3606449,12,1972.4584,1600.3914,80.34419,NULL,0),
(3606449,13,1965.8403,1599.5803,80.78863,NULL,0),
(3606449,14,1958.7689,1598.06,81.400314,NULL,0),
(3606449,15,1952.7817,1587.8278,81.90723,NULL,0),
(3606449,16,1951.8091,1583.4639,81.855774,NULL,0),
(3606449,17,1950.7427,1578.7097,81.07914,NULL,0),
-- Below guessed
(3606457,1,1939.151,1541.1406,82.5006,NULL,0);

DELETE FROM `creature_text` WHERE `CreatureID` = 4508;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4508,0,0,"Woo hoo! Finally getting out of here. It's going to be rough though. Keep your eyes peeled for trouble.",12,0,100,1,0,0,1482,0,"Willix the Importer"),
(4508,1,0,"Up there is where Charlga Razorflank resides. Blasted old crone.",12,0,100,25,0,0,1483,0,"Willix the Importer"),
(4508,2,0,"There's blueleaf tuber in this trench! It's like gold waiting to be mined I tell you!",12,0,100,1,0,0,1484,0,"Willix the Importer"),
(4508,3,0,"There could be danger around every corner here.",12,0,100,1,0,0,1485,0,"Willix the Importer"),
(4508,4,0,"I don't see how these foul animals live in this place... sheesh it smells!",12,0,100,1,0,0,1486,0,"Willix the Importer"),
(4508,5,0,"I think I see a way for us to get out of this big twisted mess of a bramble.",12,0,100,1,0,0,1487,0,"Willix the Importer"),
(4508,6,0,"Glad to be out of that wretched trench. Not much nicer up here though!",12,0,100,1,0,0,1488,0,"Willix the Importer"),
(4508,7,0,"Finally! I'll be glad to get out of this place.",12,0,100,1,0,0,1490,0,"Willix the Importer"),
(4508,8,0,"I think I'll rest a moment and catch my breath before heading back to Ratchet. Thanks for all the help!",12,0,100,1,0,0,1493,0,"Willix the Importer"),
(4508,9,0,"Well, I'm off to Ratchet now! Best of luck to you!",12,0,100,0,0,0,1494,0,"Willix the Importer"),

(4508,10,0,"Eek! $n coming right at us!",12,0,100,0,0,0,1544,0,"Willix the Importer"),
(4508,10,1,"Egads! $n on me!",12,0,100,0,0,0,1545,0,"Willix the Importer"),
(4508,10,2,"$n heading this way fast! To arms!",12,0,100,0,0,0,1546,0,"Willix the Importer"),
(4508,10,3,"Help! Get this $n off of me!",12,0,100,0,0,0,1547,0,"Willix the Importer");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4514 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4514,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Raging Agam'ar - On Just Summoned - Start Attack");
