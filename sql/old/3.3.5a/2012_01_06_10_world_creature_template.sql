-- Drowned Guardian & Phylactery Guardian summoned NPC should not give XP
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry` IN (26225,26224);
