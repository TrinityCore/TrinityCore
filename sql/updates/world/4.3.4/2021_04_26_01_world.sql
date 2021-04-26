UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x40000000 WHERE `entry` IN (49813, 49814);

-- Bound Deluge
UPDATE `creature_template` SET `difficulty_entry_1`= 49829 WHERE `entry`= 49825;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `BaseVariance`= 0.7, `unit_class`= 2, `unit_flags`= 32832, `DamageModifier`= 120, `flags_extra`= `flags_extra` | 0x40000000, `mechanic_immune_mask`= 617299839, `ManaModifierExtra`= 2 WHERE `entry` IN (49825, 49829);

-- Bound Rumbler
UPDATE `creature_template` SET `difficulty_entry_1`= 49830 WHERE `entry`= 49826;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `BaseVariance`= 0.7, `unit_class`= 2, `unit_flags`= 32832, `DamageModifier`= 120, `flags_extra`= `flags_extra` | 0x40000000, `mechanic_immune_mask`= 650854271, `ManaModifierExtra`= 2 WHERE `entry` IN (49826, 49830);

-- Bound Zephyr
UPDATE `creature_template` SET `difficulty_entry_1`= 49828 WHERE `entry`= 49821;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `BaseVariance`= 0.7, `unit_class`= 2, `unit_flags`= 32832, `DamageModifier`= 120, `flags_extra`= `flags_extra` | 0x40000000, `mechanic_immune_mask`= 650854271, `ManaModifierExtra`= 2 WHERE `entry` IN (49821, 49828);

-- Bound Inferno
UPDATE `creature_template` SET `difficulty_entry_1`= 49827 WHERE `entry`= 49817;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `BaseVariance`= 0.7, `unit_class`= 2, `unit_flags`= 32832, `DamageModifier`= 120, `flags_extra`= `flags_extra` | 0x40000000, `mechanic_immune_mask`= 650854271, `ManaModifierExtra`= 2 WHERE `entry` IN (49817, 49827);

DELETE FROM `creature_template_addon` WHERE `entry` IN (49829, 49830, 49828, 49827);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `visibilityDistanceType`, `auras`) VALUES
(49829, 1, 3, '93335'),
(49830, 1, 3, ''),
(49828, 1, 3, '87906'),
(49827, 1, 3, '93336');
