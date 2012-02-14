ALTER TABLE `conditions` CHANGE `SourceId` `SourceId` INT(10) NOT NULL DEFAULT '0';
ALTER TABLE `conditions` DROP PRIMARY KEY,
    ADD PRIMARY KEY (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`);
