-- Correct expansion level of High Prophet Barim HC version
UPDATE `creature_template` SET `exp`= 3 WHERE `entry`= 48951;

-- Add Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (43612, 48951, 43614, 49045, 44577, 48932, 44819, 51088);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
-- High Prophet Barim
(43612, 395, 3500),
(48951, 395, 7000),
-- Lockmaw and Augh
(43614, 395, 3500),
(49045, 395, 7000),
-- General Husam
(44577, 395, 3500),
(48932, 395, 7000),
-- Siamat
(44819, 395, 3500),
(51088, 395, 7000);
