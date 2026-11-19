--
UPDATE `smart_scripts` SET `event_type` = 0, `event_param1` = 6000, `event_param2` = 6000, `comment` = "Ar'kelos - In Combat - Cast 'Arcane Explosion'" WHERE `entryorguid` = 19494 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_addon` SET `auras` = "34364" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 19494);
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 19494;
