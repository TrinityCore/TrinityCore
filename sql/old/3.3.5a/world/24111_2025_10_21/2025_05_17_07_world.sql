-- Fixes for outro to quest "How Big a Threat?" (985)

-- Grimclaw's waypoints
DELETE FROM `waypoints` WHERE `entry`=3695;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(3695,1,6409.01,381.597,13.7997,"Grimclaw"),
(3695,2,6422.38,398.542,11.1623,"Grimclaw"),
(3695,3,6425.87,399.465,10.927,"Grimclaw"),
(3695,4,6427.87,397.483,11.078,"Grimclaw"),
(3695,5,6429.45,392.999,12.467,"Grimclaw"),
(3695,6,6435.15,376.543,13.940,"Grimclaw"),
(3695,7,6437.69,369.887,13.940,"Grimclaw"),
(3695,8,6436.29,366.529,13.942,"Grimclaw"),
(3695,9,6436.94,373.378,13.940,"Grimclaw"),
(3695,10,6431.37,388.937,13.693,"Grimclaw"),
(3695,11,6426.25,398.279,11.016,"Grimclaw"),
(3695,12,6421.10,397.351,11.287,"Grimclaw"),
(3695,13,6406.53,381.324,14.168,"Grimclaw");

-- Updating Smart Scripts to work with new waypoints
UPDATE `smart_scripts` SET `event_param1`=8,`comment`='Grimclaw - On WP 8 Reached (Path 3695) - Run Actionlist' WHERE `entryorguid`=3695 AND `id`=2;
UPDATE `smart_scripts` SET `event_param1`=13,`comment`='Grimclaw - On WP 13 Reached (Path 3695) - Despawn' WHERE `entryorguid`=3695 AND `id`=3;
