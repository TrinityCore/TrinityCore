UPDATE `creature_template` SET `flags_extra`= 0x00000100 WHERE `entry` IN (42897, 49121, 49122, 49123);
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 1 WHERE `entry` IN (42180, 49050, 49051, 49052);
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00200000 WHERE `entry` IN (42180, 49050, 49051, 49052, 42178, 49053, 49054, 49055, 42179, 49047, 49048, 49049, 42166, 49056, 49057, 49058);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (42180, 49050, 49051, 49052);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(42180, 396, 3500),
(49050, 396, 3500),
(49051, 396, 3500),
(49052, 396, 3500);
