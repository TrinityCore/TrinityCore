--
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 181148;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 181148 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(181148,1,0,0,70,0,100,0,2,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mummified Troll Remains - On Gameobject State Changed - Delayed Despawn");

DELETE FROM `pool_template` WHERE `entry` = 576;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(576, 30, "Ghostlands - Mummified Troll Remains");

DELETE FROM `pool_members` WHERE `type` = 1 AND `spawnId` IN (27420,27424,27326,27327,27328,27329,27330,27331,27332,27333,27334,27341,27342,27346,27348,27352,27353,27354,27356,27357,27358,27360,27361,27362,27363,27364,27365,27416,27414,27412,27410,27408,27406,27404,27402,27400,27398,27396,27394,27392,27385,27384,27382,27379,27377,27368,27367,27322);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, 27326, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27327, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27328, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27329, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27330, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27331, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27332, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27333, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27334, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27341, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27342, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27346, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27348, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27352, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27353, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27354, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27356, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27357, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27358, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27360, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27361, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27362, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27363, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27364, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27365, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27322, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27367, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27368, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27377, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27379, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27382, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27384, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27385, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27392, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27394, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27396, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27398, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27400, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27402, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27404, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27406, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27408, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27410, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27412, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27414, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27416, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27420, 576, 0, "Ghostlands - Mummified Troll Remains"),
(1, 27424, 576, 0, "Ghostlands - Mummified Troll Remains");

DELETE FROM `gameobject` WHERE `guid` IN (27322,27367,27368,27377,27379,27382,27384,27385,27392,27394,27396,27398,27400,27402,27404,27406,27408,27410,27412,27414,27416,27420,27424) AND `id` = 181148;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(27322,181148,530,0,0,1,1,7640.25,-7217.89,156.293,1.93731,0,0,0.824125,0.566408,300,255,1,"",14545),
(27367,181148,530,0,0,1,1,7599.26,-7323.93,155.825,5.34071,0,0,-0.45399,0.891007,300,255,1,"",14545),
(27368,181148,530,0,0,1,1,7652.11,-7324.58,156.037,5.53269,0,0,-0.366501,0.930418,300,255,1,"",14545),
(27377,181148,530,0,0,1,1,7584.85,-7348.84,162.338,3.6652,0,0,-0.965925,0.258821,300,255,1,"",14545),
(27379,181148,530,0,0,1,1,7567.05,-7339.33,162.334,4.71239,0,0,-0.707107,0.707107,300,255,1,"",14545),
(27382,181148,530,0,0,1,1,7549.63,-7359.84,162.296,0,0,0,0,1,300,255,1,"",14545),
(27384,181148,530,0,0,1,1,7585.23,-7369.52,162.34,2.60054,0,0,0.96363,0.267241,300,255,1,"",14545),
(27385,181148,530,0,0,1,1,7549.85,-7349.91,162.339,5.77704,0,0,-0.25038,0.968148,300,255,1,"",14545),
(27392,181148,530,0,0,1,1,7591.1,-7366.98,163.807,3.26377,0,0,-0.998135,0.0610518,300,255,1,"",14545),
(27394,181148,530,0,0,1,1,7558.11,-7377.23,162.336,1.01229,0,0,0.484809,0.87462,300,255,1,"",14545),
(27396,181148,530,0,0,1,1,7568.3,-7379.6,162.333,1.58825,0,0,0.71325,0.70091,300,255,1,"",14545),
(27398,181148,530,0,0,1,1,7629.2,-7410.21,162.597,5.39307,0,0,-0.430511,0.902586,300,255,1,"",14545),
(27400,181148,530,0,0,1,1,7588.14,-7273.17,155.792,0.872664,0,0,0.422618,0.906308,300,255,1,"",14545),
(27402,181148,530,0,0,1,1,7644.89,-7458.43,163.781,5.81195,0,0,-0.233445,0.97237,300,255,1,"",23911),
(27404,181148,530,0,0,1,1,7645.1,-7442.22,163.416,2.09439,0,0,0.866025,0.500001,300,255,1,"",23911),
(27406,181148,530,0,0,1,1,7630.65,-7442.45,163.455,6.07375,0,0,-0.104528,0.994522,300,255,1,"",23911),
(27408,181148,530,0,0,1,1,7630.54,-7434.35,163.294,6.23083,0,0,-0.0261765,0.999657,300,255,1,"",23911),
(27410,181148,530,0,0,1,1,7644.39,-7393.5,162.388,3.94445,0,0,-0.920505,0.390732,300,255,1,"",23911),
(27412,181148,530,0,0,1,1,7644.71,-7385.25,162.096,3.54302,0,0,-0.979924,0.19937,300,255,1,"",23911),
(27414,181148,530,0,0,1,1,7623.35,-7322.99,155.784,2.16421,0,0,0.882947,0.469473,300,255,1,"",23911),
(27416,181148,530,0,0,1,1,7644.99,-7401.66,162.452,2.21656,0,0,0.894934,0.446199,300,255,1,"",23911),
(27420,181148,530,0,0,1,1,7663.17,-7304.76,156.041,5.58505,0,0,-0.34202,0.939693,300,255,1,"",23911),
(27424,181148,530,0,0,1,1,7587.23,-7264.9,155.842,3.3685,0,0,-0.993571,0.113208,300,255,1,"",23911);

UPDATE `gameobject` SET `spawntimesecs` = 300, `animprogress` = 255 WHERE `id` = 181148;
