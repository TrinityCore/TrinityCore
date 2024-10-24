--
UPDATE `creature_template` SET `flags_extra`=(`flags_extra`|0x80000000) WHERE `entry` > 70000 AND (`flags_extra`&0x8E000000) IN (0xE000000, 0xA000000);
