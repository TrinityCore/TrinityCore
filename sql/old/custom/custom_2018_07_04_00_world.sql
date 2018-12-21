-- Boss damage
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (44577, 48932, 45378, 43614, 49043, 43612, 48951, 44819, 51088, 39425, 49262, 39428, 48714, 39788, 48902,
39731, 48715, 48710, 39587, 39378, 48815, 39665, 39666, 39679, 39680, 39698, 39699, 39700, 39701, 39705, 39706, 43878, 43879, 43873, 43874, 43875, 43876, 48941, 48944, 49429, 49708, 49709, 49710,
49711, 49712, 43438, 49642, 43214, 49538, 42188, 49654, 42333, 49624, 39732, 48776, 40320, 48801, 48939, 44600, 46209, 46210, 46211, 45992, 49897, 49898, 49899, 45993, 49903, 49904, 49905);

-- Boss damage (special cases)
-- Vanessa VanCleef, Glubtok
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (49541, 48936);
-- Admiral Ripsnarl
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry`= 48943;
-- Augh
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 49045;
