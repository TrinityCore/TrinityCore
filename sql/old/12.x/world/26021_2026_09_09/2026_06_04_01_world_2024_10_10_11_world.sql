-- Replace wrong 100 and 255 fixed orientation value with default NULL
UPDATE `waypoint_path_node` SET `Orientation`=NULL WHERE `Orientation`>7;
