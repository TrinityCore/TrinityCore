-- Add CREATURE_FLAG_EXTRA_NO_COMBAT to Flash Freeze (Hodir)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (32926,33352);
