-- Harbiger of Darkness and Blaze of the Heaven
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (43927, 48953, 48906);
-- Frenzied Crocolisk
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry` IN (43658, 49311);
-- Augh (Pre-Boss)
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 45377;
-- Servant of Siamat
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (45259, 49256, 45268, 49257, 45269, 49258);
-- Oathsworn Captain
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (45122, 49334);
-- Small Trash Groups
UPDATE `creature_template` SET `DamageModifier`= 30, `RangeVariance`= 0.5 WHERE `entry` IN (44932, 49323, 44926, 49322);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (44922, 49319, 44924, 49321, 44976, 44982, 49328, 44980, 49326, 44896, 49317, 44897, 49318, 44898, 49320);
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry` IN (44981, 49327, 44977, 49325, 44261, 49315, 45062, 49330, 49331, 45063);
-- Sharptalon Eagle
UPDATE `creature_template` SET `difficulty_entry_1`= 49315 WHERE `entry`= 44261;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 90, `speed_run`= 0.857143, `movementId`= 121 WHERE `entry`= 49315;
-- Bonesnapper Scorpid
UPDATE `creature_template` SET `difficulty_entry_1`= 49331, `minlevel`= 84, `maxlevel`= 84 WHERE `entry`= 45063;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 90 WHERE `entry`= 49331;
-- Enslaved Bandit
UPDATE `creature_template` SET `DamageModifier`= 4, `BaseVariance`= 0.5 WHERE `entry`= 45007;
