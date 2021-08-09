ALTER TABLE `world_quest`
    CHANGE `variable` `variable` INT(10) NOT NULL,
    CHANGE `value` `value` INT(10) NOT NULL,
    ADD COLUMN `VerifiedBuild` SMALLINT(5) DEFAULT 0 NULL AFTER `value`; 
