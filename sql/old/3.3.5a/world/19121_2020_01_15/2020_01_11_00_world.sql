ALTER TABLE `holiday_dates` ADD COLUMN `holiday_duration` INT(10) UNSIGNED NOT NULL AFTER `date_value`;
UPDATE `holiday_dates` SET `holiday_duration`= 360 WHERE `id`= 327;
