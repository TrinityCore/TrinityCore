-- Remove ScriptName and set unit_flags for Ahnhakar Swarm Eggs
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |2|256|33554432, `ScriptName` = "" WHERE `entry` IN (30172, 31446, 30173, 31445);
