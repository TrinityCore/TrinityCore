ALTER TABLE `conditions` DROP PRIMARY KEY;
ALTER TABLE `conditions` ADD `ConditionStringValue1` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '' AFTER `ConditionValue3`;
ALTER TABLE `conditions` ADD PRIMARY KEY (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`);
