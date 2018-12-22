-- Halls of Origination
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 20000, `maxgold`= 25000 WHERE `entry` IN (39428, 39425, 39788, 39731, 39732, 39587, 39378);
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5, `mingold`= 20000, `maxgold`= 25000 WHERE `entry` IN (48714, 49262, 48902, 48715, 48776, 48710, 48815);
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (48141, 48139, 48140, 40715, 39373, 40033);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000 WHERE `entry` IN (49309, 49307, 49308, 49300, 49285, 49291);
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 32 | 65536, `flags_extra`= 0x40000000 WHERE `entry` IN (48143, 40170);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 32 | 65536, `flags_extra`= 0x40000000 WHERE `entry` IN (49310, 49293);
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 2048 WHERE `entry` IN (48140, 49308);
UPDATE `creature_template` SET `DamageModifier`= 5, `BaseVariance`= 0.5 WHERE `entry` IN (39804, 40252, 40251, 42556, 40458, 41374, 39444, 39370);
UPDATE `creature_template` SET `DamageModifier`= 10, `BaseVariance`= 0.5 WHERE `entry` IN (48900, 48899, 48897, 49306, 49297, 49305, 48891);
UPDATE `creature_template` SET `difficulty_entry_1`= 48900 WHERE `entry`= 39804;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16 WHERE `entry`= 48900;
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mingold`= 15000, `maxgold`= 20000, `mechanic_immune_mask`= 650854271, `flags_extra`= 0x40000000 WHERE `entry` IN (39800, 39801, 39802, 39803);
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mingold`= 15000, `maxgold`= 20000, `mechanic_immune_mask`= 650854271, `flags_extra`= 0x40000000 WHERE `entry` IN (48892, 48894, 48895, 48896);
UPDATE `creature_template` SET `difficulty_entry_1`= 48894 WHERE `entry`= 39800;
UPDATE `creature_template` SET `difficulty_entry_1`= 48895 WHERE `entry`= 39801;
UPDATE `creature_template` SET `difficulty_entry_1`= 48892 WHERE `entry`= 39802;
UPDATE `creature_template` SET `difficulty_entry_1`= 48896 WHERE `entry`= 39803;
UPDATE `creature_template` SET `difficulty_entry_1`= 49293 WHERE `entry`= 40170;
UPDATE `creature_template` SET `difficulty_entry_1`= 48891 WHERE `entry`= 39444;
UPDATE `creature_template` SET `difficulty_entry_1`= 49285 WHERE `entry`= 39373;
UPDATE `creature_template` SET `difficulty_entry_1`= 49283 WHERE `entry`= 39369;
UPDATE `creature_template` SET `difficulty_entry_1`= 49282 WHERE `entry`= 39366;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `unit_class`= 4, `unit_flags`= 64 WHERE `entry`= 49293;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 91, `unit_flags`= 64 WHERE `entry`= 49285;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 91 WHERE `entry` IN (49283, 49282);
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16 WHERE `entry`= 48891;
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry` IN (40310, 39440, 40787, 40311, 40808, 40450, 41371, 41364, 40668, 39366, 49283);
UPDATE `creature_template` SET `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry` IN (39369);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (49294, 49286, 49301, 49295, 49302, 49296, 49305, 49303, 40668, 49282);
UPDATE `creature_template` SET `mingold`= 10000, `maxgold`= 15000 WHERE `entry`= 39370;
UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 3500 WHERE `creature_id` IN (39731, 39587, 39732, 39378);
UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 7000 WHERE `creature_id` IN (48715, 48710, 48776, 48815);

-- Fix interrupt immunities of all implemented bosses
UPDATE `creature_template` SET `mechanic_immune_mask`= `mechanic_immune_mask` | 33554432 WHERE `entry` IN (39428, 39587, 39605, 39665, 39666, 39679, 39680, 39698, 39699, 39700, 39701, 39705, 39706, 39788, 42188, 43214, 43324, 43391, 43406, 43438, 43592, 43612, 43614, 43689, 43735, 43873, 43874, 43875, 43876, 43878, 43879, 44566, 44641, 44648, 44653, 44687, 44752, 44819, 44826, 44828, 44829, 45377, 45992, 45993, 46212, 46213, 46214, 46215, 46216, 46217, 46218, 46219, 46220, 46221, 46222, 46223, 46224, 46225, 46226, 46227, 46228, 46229, 47120, 48710, 48714, 48902, 48936, 48939, 48940, 48941, 48943, 48944, 48951, 49043, 49045, 49073, 49097, 49104, 49429, 49538, 49541, 49609, 49610, 49611, 49619, 49620, 49621, 49642, 49653, 49654, 49670, 49674, 49681, 49709, 49710, 49711, 49897, 49898, 49899, 49903, 49904, 49905, 50008, 50131, 50132, 50133, 50194, 50195, 50196, 50197, 50198, 50199, 51088, 51350, 51627, 52151, 52157, 52602);
UPDATE `creature_template` SET `mechanic_immune_mask`= 617299839 WHERE `entry` IN (39378, 39425, 39731, 40586, 42333, 43622, 43686, 43687, 43688, 44023, 44045, 44600, 46209, 46210, 46211, 48715, 48815, 49080, 49262, 49606, 49607, 49608, 49612, 49613, 49614, 49615, 49616, 49617, 49624, 49708, 49712, 50184, 50185, 50186, 50187, 50188, 50189, 50190, 50191, 50192, 50264, 52053, 52059, 52155);
