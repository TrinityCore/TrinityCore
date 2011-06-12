-- fix Saurfang spawn time
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` = 37813;

-- fix spam in log
UPDATE `waypoint_scripts` SET `datalong2`='1' WHERE datalong IN (39950,76221,54324,50036,48310,46906,61615,45940,70153,46400,55838,35782,54324,46960,49119,46400,70602);

-- fix crash with use .gob near command and russian locale
UPDATE `trinity_string` SET `content_loc8` = '%d (Entry: %d) - |cffffffff|Hgameobject:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r' WHERE `entry` = '517';

-- Anub'arak, fix of incorrect YTDB flag
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry`= 34564;
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry`= 34566;
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry`= 35615;
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry`= 35616;

-- fix crash with NPC 38068 cast spel (recursion)
UPDATE `creature_template` SET `ScriptName`="", `spell1`="" WHERE `entry` = 38068;
