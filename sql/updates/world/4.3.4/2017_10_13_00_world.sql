ALTER TABLE `quest_template` MODIFY `RewardCurrencyCount1` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RewardCurrencyCount2` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RewardCurrencyCount3` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RewardCurrencyCount4` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `quest_template` MODIFY `RequiredCurrencyCount4` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RequiredCurrencyCount4` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RequiredCurrencyCount4` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` MODIFY `RequiredCurrencyCount4` INT(10) UNSIGNED NOT NULL DEFAULT '0';

UPDATE `quest_template` SET `RewardCurrencyCount1`= 15000, `RewardCurrencyId1`= 396 WHERE `id` IN (28905, 29185);
UPDATE `quest_template` SET `RewardCurrencyCount1`= 25000, `RewardCurrencyId1`= 396 WHERE `id` IN (30110, 30111);
UPDATE `quest_template` SET `RewardCurrencyCount1`= 15000, `RewardCurrencyId1`= 395 WHERE `id` IN (28906, 29183, 28907, 28908);
