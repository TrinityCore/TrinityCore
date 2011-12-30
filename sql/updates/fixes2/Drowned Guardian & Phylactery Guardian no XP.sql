-- Drowned Guardian & Phylactery Guardian summoned NPC should not give XP fix by tobmaps
-- Closes #1860
UPDATE `creature_template` SET `flags_extra` = 64 WHERE `entry` IN (26225, 26224);
