ALTER TABLE `petition` 
DROP PRIMARY KEY, 
ADD PRIMARY KEY (`ownerguid`, `type`);

ALTER TABLE `petition_sign` ADD COLUMN `type` int(10) UNSIGNED NOT NULL DEFAULT 0;
