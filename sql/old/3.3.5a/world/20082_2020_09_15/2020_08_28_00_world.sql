-- Add CREATURE_FLAG_EXTRA_NO_COMBAT to Flame Breath Trigger (Skadi)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 28351;
