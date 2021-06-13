-- Beaten Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 10668;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 10668);

-- Night Elf Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 16804;

-- The Lich King
-- AoD Impact Bunny
-- Vegard Bunny
UPDATE `creature_template` SET `unit_flags2` = 2048, `dynamicflags` = 0 WHERE `entry` IN (37857,37878,37894);
