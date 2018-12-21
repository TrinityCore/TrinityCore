-- Harbiger of Darkness
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 43927;
-- Frenzied Crocolisk
UPDATE `creature_template` SET `DamageModifier`= 4, `BaseVariance`= 0.5 WHERE `entry`= 43658;
-- Servant of Siamat
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry` IN (45259, 45268, 45269);
-- Oathsworn Captain
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 45122;
-- Small Trash Groups
UPDATE `creature_template` SET `DamageModifier`= 15, `RangeVariance`= 0.5 WHERE `entry` IN (44932, 44926);
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry` IN (44922, 44924, 44976, 44982, 44980, 44896, 44897, 44898);
UPDATE `creature_template` SET `DamageModifier`= 10, `BaseVariance`= 0.5 WHERE `entry` IN (44981, 44977, 44261, 45062);
-- Lost City Bosses
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (44577, 43614, 43612, 44819);
