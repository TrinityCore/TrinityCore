ALTER TABLE `account` 
ADD COLUMN `vp` INT(10) NULL AFTER `recruiter`,
ADD COLUMN `dp` INT(10) NULL AFTER `vp`;
