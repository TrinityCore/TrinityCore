-- Added trigger flags to triggers
UPDATE `creature_template` SET `flags_extra` = flags_extra | 128 WHERE `entry` = 34862;
UPDATE `creature_template` SET `unit_flags` = unit_flags | 256 WHERE `entry` = 34862;
