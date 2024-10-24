--
UPDATE `creature_template` SET `speed_walk` = 1.0, `speed_run` = 1.0 WHERE `entry` > 70000 AND (`flags_extra`&0x8E000000) = 0x8E000000 AND `speed_run` > 1.0;
