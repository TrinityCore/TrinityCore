-- Gold loot for implemented raid bosses
UPDATE `creature_template` SET `mingold`= 2500000, `maxgold`= 2500000 WHERE `entry` IN (44600, 46210, 43735, 49620, 43324, 50132, 41570, 51102, 42180, 49051, 41378, 49980, 41442, 49584, 43296, 47775, 47120, 52363, 55869, 45871, 50108);
UPDATE `creature_template` SET `mingold`= 6250000, `maxgold`= 6250000 WHERE `entry` IN (46209, 46211, 49619, 49621, 50131, 50133, 51101, 51103, 49050, 49052, 49974, 49986, 49583, 49585, 47774, 47776, 51350, 54229, 57270, 50098, 50118);

UPDATE `creature_template` SET `mingold`= 1250000, `maxgold`= 1250000 WHERE `entry` IN (45992, 49898, 45993, 49904);
UPDATE `creature_template` SET `mingold`= 3125000, `maxgold`= 3125000 WHERE `entry` IN (49897, 49899, 49903, 49905);
UPDATE `creature_template` SET `mingold`= 0, `maxgold`= 0 WHERE `entry` IN (42178, 49053, 49054, 49055, 42166, 49056, 49057, 49058, 42179, 49047, 49048, 49049, 45870, 50103, 50113, 50123, 45872, 50095, 50105, 50115);

UPDATE `gameobject_template_addon` SET `mingold`= 2500000, `maxgold`= 2500000 WHERE `entry` IN (207891, 207892);
UPDATE `gameobject_template_addon` SET `mingold`= 6250000, `maxgold`= 6250000 WHERE `entry` IN (207893, 207894);

-- Fix Omnotron Defense System encounter credit type
UPDATE `instance_encounters` SET `creditType`= 0 WHERE `entry`= 1027;

-- Gold loot for dungeon bosses
UPDATE `creature_template` SET `mingold`= 17000, `maxgold`= 23000 WHERE `entry` IN (39625, 40177, 40319, 40484, 44577, 43614, 43612, 44819, 39665, 39679, 39698, 39700, 39705, 39425, 39788, 39428, 39378, 39731, 39732, 39587, 43438, 43214, 42188, 42333, 40586, 40765, 40788, 43878, 43873, 43875, 52053);
UPDATE `creature_template` SET `mingold`= 17000, `maxgold`= 23000 WHERE `entry` IN (48337, 48702, 48784, 48822, 48932, 49045, 48951, 51088, 39666, 39680, 39699, 39701, 39706, 48936, 48940, 48941, 49541, 48943, 48944, 49262, 48902, 48714, 48815, 48715, 48776, 48710, 49708, 49709, 49711, 49710, 49711, 49642, 49538, 49654, 49624, 49080, 49064, 49082, 43879, 43874, 43876, 52155, 52151, 52148, 52059, 52053);

UPDATE `gameobject_template_addon` SET `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= 205216;
UPDATE `gameobject_template_addon` SET `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= 207973;

-- Currency drops for Chimaeron
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (43296, 47774, 47775, 47776);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(43296, 396, 3500),
(47774, 396, 4500),
(47775, 396, 3500),
(47776, 396, 4500);

-- Correct currency drops for raid bosses
UPDATE `creature_onkill_reward` SET `CurrencyCount1`= 3500 WHERE `creature_id` IN (44600, 46210, 45992, 49898, 43735, 49620, 47120, 43324, 50132, 45871, 50108, 46753, 50217);
UPDATE `creature_onkill_reward` SET `CurrencyCount1`= 4500 WHERE `creature_id` IN (46209, 46211, 49897, 49899, 49619, 49621, 51350, 50131, 50133, 50098, 50118, 50203, 50231);
