-- Flags 128+2: creature is trigger-NPC (invisible to players only) + creature does not aggro (ignore faction/reputation hostility)
UPDATE `creature_template` SET `flags_extra` = (`flags_extra`|2|128) WHERE `entry` IN (32195,32196,32197,32199);
