--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00200000 WHERE `entry` IN (20869,21586);
