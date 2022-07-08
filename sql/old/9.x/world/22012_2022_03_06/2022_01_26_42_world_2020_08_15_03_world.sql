-- Add CREATURE_FLAG_EXTRA_NO_COMBAT to Toxic Tunnel (Naxxramas)
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|0x00002000 WHERE `entry` = 16400;
