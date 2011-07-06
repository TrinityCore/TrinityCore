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

-- fix aggro for Rimefang and Spinestalker
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry` IN (37533, 37534);

-- Fix start Valithria encounter while enconter is DONE
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (38752, 16980);

-- Add lost data
DELETE FROM `creature` WHERE `guid` in (85584, 85585, 85586);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(85584, 29836, 604, 3, 1, 0, 0, 1851.12, 743.221, 135.951, 3.1629, 7200, 0, 0, 45516, 0, 0, 0, 0, 0),
(85585, 29836, 604, 3, 1, 0, 0, 1874.55, 757.72, 136.039, 3.56345, 7200, 0, 0, 45516, 0, 0, 0, 0, 0),
(85586, 29836, 604, 3, 1, 0, 0, 1875.77, 726.76, 135.946, 2.61705, 7200, 0, 0, 45516, 0, 0, 0, 0, 0);
