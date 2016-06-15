-- remove script from core requires removing ScriptName from creature_template
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`IN (1749,2708);
