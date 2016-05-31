DELETE FROM `script_waypoint` WHERE `entry` IN (SELECT `entry` FROM `creature_template` WHERE `ScriptName`='');
