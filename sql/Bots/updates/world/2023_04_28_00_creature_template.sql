--
UPDATE `creature_template` SET `flags_extra` = (`flags_extra` | 0x02000000) WHERE (`flags_extra` & 0x0A000000) = 0x08000000 AND `entry` > 70000;
UPDATE `creature_template` SET `flags_extra` = (`flags_extra` | 0x0A000000) WHERE (`flags_extra` & 0x0E000000) = 0x04000000 AND `entry` > 70000;
