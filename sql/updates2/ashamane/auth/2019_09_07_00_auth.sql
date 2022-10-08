ALTER TABLE `account` 
ADD COLUMN `recruiter_rewarded` TINYINT UNSIGNED NOT NULL DEFAULT 0 AFTER `recruiter`;
