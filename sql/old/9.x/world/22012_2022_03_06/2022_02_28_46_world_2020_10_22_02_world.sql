--
DELETE FROM `creature` WHERE `id` = 10237;
DELETE FROM `skinning_loot_template` WHERE `Entry` = 10237;
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` = 10237;
