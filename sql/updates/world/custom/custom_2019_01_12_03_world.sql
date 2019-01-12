-- Strong trash
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 90, `BaseVariance`= 0.5 WHERE `entry` IN (42810, 42692);
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 120, `BaseVariance`= 0.5 WHERE `entry` IN (49647, 49661);

-- Regular trash
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (43537, 42696, 42808, 42691, 42696, 42789);
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (49662, 49667, 49663, 49665, 49667, 49664);

-- Weak trash
UPDATE `creature_template` SET `DamageModifier`= 3, `BaseVariance`= 0.5 WHERE `entry` IN (43662, 42845, 42695, 42428);
UPDATE `creature_template` SET `DamageModifier`= 6, `BaseVariance`= 0.5 WHERE `entry` IN (49669, 49655, 49666, 49648);

-- Offhand attack creatures
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 20, `BaseVariance`= 0.5, `flags_extra`= 2048 WHERE `entry` IN (43430);
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 50, `BaseVariance`= 0.5, `flags_extra`= 2048 WHERE `entry` IN (49660);
