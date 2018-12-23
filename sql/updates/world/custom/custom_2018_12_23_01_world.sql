-- Throne of the Tides
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry`= 40634;
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 49092;
UPDATE `creature_template` SET `difficulty_entry_1`= 49067, `DamageModifier`= 4, `BaseVariance`= 0.5 WHERE `entry`= 40579;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `DamageModifier`= 8, `BaseVariance`= 0.5, `speed_walk`= 2, `speed_run`= 1.71429 WHERE `entry`= 49067;
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (39616, 49085, 41096, 49090, 40577, 49087, 40584, 49086, 41139, 49091, 40634, 49092);
UPDATE `creature_template_addon` SET `bytes1`= 0 WHERE `entry` IN (39616, 41096, 40584);
UPDATE `creature_template` SET `DamageModifier`= 4, `BaseVariance`= 0.5 WHERE `entry`= 39960;
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry`= 49066;
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 40936;
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 49074;
