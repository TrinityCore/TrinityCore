-- Boss Immunities
-- Default immunities except interrupt
UPDATE `creature_template` SET `mechanic_immune_mask`= 80297855 WHERE `entry` IN (46962, 49708, 46964, 49712, 39425, 49262, 39731, 48715, 49624, 42333);
-- Default boss immunities
UPDATE `creature_template` SET `mechanic_immune_mask`= 617299839 WHERE `entry` IN
(46963, 49711, 3887, 49709, 4278, 49710, 43612, 48951, 43614, 49043, 49045, 44819, 51088, 47162, 48936, 47296, 48940,
43778, 48941, 47626, 48943, 47739, 48944, 49429, 39665, 39666, 39679, 39680, 39698, 39699, 39700, 39701, 39705, 39706, 39428, 48714, 39788, 48902, 39587, 48710, 48939);

-- Boss damage
UPDATE `creature_template` SET `DamageModifier`= 121.2 WHERE `entry` IN (44577, 48932, 45378, 43614, 49043, 43612, 48951, 44819, 51088, 39425, 49262, 39428, 48714, 39788, 48902,
39731, 48715, 48710, 39587, 39378, 48815, 39665, 39666, 39679, 39680, 39698, 39699, 39700, 39701, 39705, 39706, 43878, 43879, 43873, 43874, 43875, 43876, 48936, 48940, 48941, 48943,
48944, 49429, 49708, 49709, 49710, 49711, 49712, 43438, 49642, 43214, 49538, 42188, 49654, 42333, 49624, 39732, 48776, 40320, 48801, 48939);

-- Specific updates
-- Temple Guardian Anhuur HC updates
UPDATE `creature_template` SET `difficulty_entry_1`= 48902 WHERE `entry`= 39425;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `unit_flags`= 2048, `movementId`= 151 WHERE `entry`= 49262;

-- Anraphet HC updates
UPDATE `creature_template` SET `difficulty_entry_1`= 48902 WHERE `entry`= 39788;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 1.6, `unit_flags`= 33555008, `movementId`= 167 WHERE `entry`= 48902;

-- Ammunae HC updates
UPDATE `creature_template` SET `difficulty_entry_1`= 48715 WHERE `entry`= 39731;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `unit_flags`= 32832, `VehicleId`= 758, `movementId`= 151 WHERE `entry`= 48715;

-- Isiset HC updates
UPDATE `creature_template` SET `difficulty_entry_1`= 48710 WHERE `entry`= 39587;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 2, `speed_run`= 1.42857, `unit_flags`= 32832, `movementId`= 151 WHERE `entry`= 48710;

-- Setesh HC updates
UPDATE `creature_template` SET `difficulty_entry_1`= 48776 WHERE `entry`= 39732;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 2.8, `speed_run`= 1.42857, `unit_flags`= 32832, `movementId`= 154 WHERE `entry`= 48776;

-- Currency loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39425, 39788, 39428, 39731, 39587, 39732, 39378, 43614, 44577, 43612, 44819);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- 35 Justice Points
(39425, 395, 3500),
(39788, 395, 3500),
(39428, 395, 3500),
(39731, 395, 3500),
(39587, 395, 3500),
(39732, 395, 3500),
(39378, 395, 3500),
(43614, 395, 3500),
(44577, 395, 3500),
(43612, 395, 3500),
(44819, 395, 3500);

-- Loot
-- Corborus
UPDATE `creature_template` SET `difficulty_entry_1`= 49642, `lootid`= 43438 WHERE `entry`= 43438;
DELETE FROM `creature_loot_template` WHERE entry IN (43438, 49642);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(43438, 55793, 0, 1, 1, 1, 1),
(43438, 55792, 0, 1, 1, 1, 1),
(43438, 55794, 0, 1, 1, 1, 1),
(43438, 55795, 0, 1, 1, 1, 1),
(43438, 55796, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 49642 WHERE `entry`= 49642;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49642, 56331, 0, 1, 1, 1, 1),
(49642, 56330, 0, 1, 1, 1, 1),
(49642, 56332, 0, 1, 1, 1, 1),
(49642, 56328, 0, 1, 1, 1, 1),
(49642, 56329, 0, 1, 1, 1, 1);

-- Slabhide
UPDATE `creature_template` SET `difficulty_entry_1`= 49538, `lootid`= 43214 WHERE `entry`= 43214;
DELETE FROM `creature_loot_template` WHERE `entry` IN (43214, 49538);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(43214, 63043, 0.1, 1, 2, 1, 1), -- Drake Mount Drop
(43214, 55798, 0, 1, 1, 1, 1),
(43214, 55797, 0, 1, 1, 1, 1),
(43214, 55799, 0, 1, 1, 1, 1),
(43214, 55800, 0, 1, 1, 1, 1),
(43214, 55801, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 49538 WHERE `entry`= 49538;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49538, 63043, 0.1, 1, 2, 1, 1), -- Drake Mount Drop
(49538, 56334, 0, 1, 1, 1, 1),
(49538, 56336, 0, 1, 1, 1, 1),
(49538, 56333, 0, 1, 1, 1, 1),
(49538, 56337, 0, 1, 1, 1, 1),
(49538, 56335, 0, 1, 1, 1, 1);

-- Ozruk
UPDATE `creature_template` SET `difficulty_entry_1`= 49654, `lootid`= 42188 WHERE `entry`= 42188;
DELETE FROM `creature_loot_template` WHERE `entry` IN (42188, 49654);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(42188, 55802, 0, 1, 1, 1, 1),
(42188, 55803, 0, 1, 1, 1, 1),
(42188, 55804, 0, 1, 1, 1, 1),
(42188, 55810, 0, 1, 1, 1, 1),
(42188, 55811, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 49654 WHERE `entry`= 49654;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49654, 56340, 0, 1, 1, 1, 1),
(49654, 56341, 0, 1, 1, 1, 1),
(49654, 56338, 0, 1, 1, 1, 1),
(49654, 56339, 0, 1, 1, 1, 1),
(49654, 56342, 0, 1, 1, 1, 1);

-- High Priestess Azil
UPDATE `creature_template` SET `difficulty_entry_1`= 49624, `lootid`= 42333 WHERE `entry`= 42333;
DELETE FROM `creature_loot_template` WHERE `entry` IN (42333, 49624);
DELETE FROM `reference_loot_template` WHERE `entry` IN (423330, 496240);

INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(42333, 423330, 100, 1, 0, 2, 2);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(423330, 55817, 0, 1, 1, 1, 1),
(423330, 55812, 0, 1, 1, 1, 1),
(423330, 55818, 0, 1, 1, 1, 1),
(423330, 55816, 0, 1, 1, 1, 1),
(423330, 55814, 0, 1, 1, 1, 1),
(423330, 55819, 0, 1, 1, 1, 1),
(423330, 55820, 0, 1, 1, 1, 1),
(423330, 55821, 0, 1, 1, 1, 1),
(423330, 55813, 0, 1, 1, 1, 1),
(423330, 55815, 0, 1, 1, 1, 1);

UPDATE creature_template SET `lootid`= 49624 WHERE `entry`= 49624;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49624, 496240, 100, 1, 0, 2, 2);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(496240, 56348, 0, 1, 1, 1, 1),
(496240, 56344, 0, 1, 1, 1, 1),
(496240, 56352, 0, 1, 1, 1, 1),
(496240, 56347, 0, 1, 1, 1, 1),
(496240, 56345, 0, 1, 1, 1, 1),
(496240, 56351, 0, 1, 1, 1, 1),
(496240, 56349, 0, 1, 1, 1, 1),
(496240, 56350, 0, 1, 1, 1, 1),
(496240, 56346, 0, 1, 1, 1, 1),
(496240, 56343, 0, 1, 1, 1, 1),
(496240, 52078, 100, 1, 2, 1, 1); -- Chaos Orb

-- The Stonecore 
UPDATE `creature_template` SET `mingold`= 14000, `maxgold`= 16000 WHERE `entry` IN (43438, 43214, 42188, 42333);
UPDATE `creature_template` SET `mingold`= 19000, `maxgold`= 20000 WHERE `entry` IN (49642, 49538, 49654, 49624);
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (49642, 49538, 49654, 49624);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- 70 Justice Points
(49642, 395, 7000),
(49538, 395, 7000),
(49654, 395, 7000),
(49624, 395, 7000);

-- The Vortex Pinnacle
UPDATE `creature_template` SET `mingold`= 14000, `maxgold`= 16000 WHERE `entry` IN (43878, 43873, 43875);
UPDATE `creature_template` SET `mingold`= 19000, `maxgold`= 20000 WHERE `entry` IN (43879, 43874, 43876);
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (43879, 43874, 43876);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- 70 Justice Points
(43879, 395, 7000),
(43874, 395, 7000),
(43876, 395, 7000);

-- Shadowfang Keep
UPDATE `creature_template` SET `mingold`= 7000, `maxgold`= 8000 WHERE `entry` IN (46962, 3887, 4278, 46963, 46964);
UPDATE `creature_template` SET `mingold`= 19000, `maxgold`= 20000 WHERE `entry` IN (49708, 49709, 49710, 49711, 49712);
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (49708, 49709, 49710, 49711, 49712);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- 70 Justice Points
(49708, 395, 7000),
(49709, 395, 7000),
(49710, 395, 7000),
(49711, 395, 7000),
(49712, 395, 7000);

-- Deadmines
UPDATE `creature_template` SET `mingold`= 7000, `maxgold`= 8000 WHERE `entry` IN (47162, 47296, 43778, 47626, 47739);
UPDATE `creature_template` SET `mingold`= 19000, `maxgold`= 20000 WHERE `entry` IN (48936, 48940, 48941, 48943, 48944);
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (48936, 48940, 48941, 48943, 48944, 49429);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- 70 Justice Points
(48936, 395, 7000),
(48940, 395, 7000),
(48941, 395, 7000),
(48943, 395, 7000),
(48944, 395, 7000),
(49429, 395, 7000);
