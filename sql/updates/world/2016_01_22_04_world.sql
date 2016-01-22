-- Tomb of the Lightbringer
-- This quest was marked obsolete by Blizzard and cannot be obtained or completed.
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=17238;
DELETE FROM `script_waypoint` WHERE `entry`=17238;
