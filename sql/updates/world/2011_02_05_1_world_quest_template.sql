-- Fix nonexisting required races for Hungry Hungry Hatching
UPDATE `quest_template` SET `requiredraces`=514 WHERE `entry`=13889; -- Orc and Blood Elf (2+512)
UPDATE `quest_template` SET `requiredraces`=176 WHERE `entry`=13915; -- Undead, Tauren, Troll (16+32+128)
-- Fix nonexisting required races for Poached, Scrambled, Or Raw?
UPDATE `quest_template` SET `requiredraces`=514 WHERE `entry`=13904; -- Orc and Blood Elf (2+512)
UPDATE `quest_template` SET `requiredraces`=176 WHERE `entry`=13916; -- Undead, Tauren, Troll (16+32+128)
-- Fix nonexisting required races for Searing Roc Feathers
UPDATE `quest_template` SET `requiredraces`=514 WHERE `entry`=13905; -- Orc and Blood Elf (2+512)
UPDATE `quest_template` SET `requiredraces`=176 WHERE `entry`=13914; -- Undead, Tauren, Troll (16+32+128)
