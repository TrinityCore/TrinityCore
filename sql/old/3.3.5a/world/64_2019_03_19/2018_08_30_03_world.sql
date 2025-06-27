--
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1189 AND 1197;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1189, "No instances were found matching your input"),
(1190, "Multiple instances match your input - please be more specific:"),
(1191, "│ %03u - %s"),
(1192, "Specified map %u is not instanced"),
(1193, "Could not find entrance portal for map %u (%s)"),
(1194, "Could not find exit portal for map %u (%s)"),
(1195, "Teleported you to the entrance of mapid %u (%s)"),
(1196, "Teleported you to the starting location of mapid %u (%s)"),
(1197, "Failed to teleport you to mapid %u (%s) - missing attunement/expansion for parent map %u?");
