-- Blackrock Caverns
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry` IN (39708, 39978, 39982, 39985, 39990, 40017, 40019, 40021, 40023, 39994, 39980);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (39665, 39698, 39700, 39705, 39987);

-- Throne of the Tides
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry` IN (41096, 41139, 39616, 40584, 44404, 44841, 40925, 40935);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (40586, 40765, 40788, 40633, 44648, 40936);
