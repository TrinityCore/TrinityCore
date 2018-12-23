-- Deadmines
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (48829, 48830);
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 48804;
UPDATE `creature_template` SET `mingold`= 20000, `maxgold`= 25000 WHERE `entry` IN (48940, 48943, 48944);
UPDATE `creature_template` SET `DamageModifier`= 10, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (48834, 48823, 48824, 48826, 48811);
UPDATE `creature_template` SET `DamageModifier`= 10, `BaseVariance`= 0.5 WHERE `entry`= 48447;
UPDATE `creature_template` SET `InhabitType`= 4  WHERE `entry` IN (48505, 48447);
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5,  `mingold`= 20000, `maxgold`= 25000 WHERE `entry` IN (48936, 48941);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (48819, 48821, 48814, 48812, 48914, 48787, 48792, 48791, 48777, 48778);
