-- fix Saurfang spawn time
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` = 37813;

-- fix spam in log
UPDATE `waypoint_scripts` SET `datalong2`='1' WHERE datalong IN (39950,76221,54324,50036,48310,46906,61615,45940,70153,46400,55838,35782,54324,46960,49119,46400,70602);

-- fix crash with use .gob near command and russian locale
UPDATE `trinity_string` SET `content_loc8` = '%d (Entry: %d) - |cffffffff|Hgameobject:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r' WHERE `entry` = '517';