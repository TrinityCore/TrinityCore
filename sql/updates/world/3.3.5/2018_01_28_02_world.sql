DELETE FROM `creature_text` WHERE `CreatureID`=12818;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12818, 0, 0, "Thank you for freeing me.  Speak with my sister in Splintertree.  I... I must find a place to rest...", 12, 0, 100, 0, 10000, 0, 8265, 0, "Ruul Snowhoof");

DELETE FROM `script_waypoint` WHERE `entry`=12818 AND `pointid`>20;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(12818, 21, 3484.2211, -489.7181, 182.391, 0, ""),
(12818, 22, 3454.7424, -476.7681, 170.161, 0, ""),
(12818, 23, 3381.2749, -428.4134, 149.411, 0, ""),
(12818, 24, 3323.4501, -446.5041, 150.590, 0, ""),
(12818, 25, 3302.2722, -485.8791, 153.285, 0, ""),
(12818, 26, 3287.0722, -519.1887, 154.622, 0, ""),
(12818, 27, 3249.5512, -531.9198, 151.633, 5000, "The end"),
(12818, 28, 3249.5512, -531.9198, 151.633, 0, "The end");
