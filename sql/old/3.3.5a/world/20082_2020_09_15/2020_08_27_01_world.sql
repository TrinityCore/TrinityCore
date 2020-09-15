-- Add gold, immune to roots and snare https://www.wowhead.com/npc=32255/converted-hero#comments:id=505383
UPDATE `creature_template` SET `mingold` = 1654, `maxgold` = 2760, `mechanic_immune_mask` = `mechanic_immune_mask`|64|1024 WHERE `entry` = 32255;
