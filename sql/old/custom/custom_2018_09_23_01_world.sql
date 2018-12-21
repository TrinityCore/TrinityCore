
-- Adding Shadowy Corruption to Ascendant Lord Obsidius' heroic entry
DELETE FROM `creature_template_addon` WHERE `entry`= 39706;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(39706, 1, '75054');

-- Remove snare immunity from several encounter adds
UPDATE `creature_template` SET `mechanic_immune_mask`= `mechanic_immune_mask` & ~1024 WHERE `entry` IN (40357, 48785, 40600, 48828, 48844, 48845);

-- Adding Taunt Immunity to several adds
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 256 WHERE `entry` IN (40357, 48785, 40600, 48828, 48844, 48845, 43658, 49311, 49229);
