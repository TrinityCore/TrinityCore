-- Correct respawn time for dwarves in the Lyceum
UPDATE `creature` SET `spawntimesecs`=30 WHERE `id` IN (8901,9956);
