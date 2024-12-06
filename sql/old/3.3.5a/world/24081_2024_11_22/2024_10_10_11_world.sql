-- Replace wrong 100 and 255 fixed orientation value with default NULL
UPDATE `waypoint_data` SET `orientation`=NULL WHERE `orientation`>7;
