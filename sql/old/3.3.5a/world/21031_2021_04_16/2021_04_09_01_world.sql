--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00000040, `unit_flags` = 256 WHERE `entry` IN (18200,18180);
