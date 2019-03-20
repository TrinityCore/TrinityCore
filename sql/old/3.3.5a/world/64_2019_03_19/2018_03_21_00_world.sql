UPDATE `creature_template` SET `flags_extra` = (`flags_extra` & ~0x1000);
UPDATE `creature_template` SET `flags_extra` = (`flags_extra` | 0x1000) WHERE `entry` = 27914;
