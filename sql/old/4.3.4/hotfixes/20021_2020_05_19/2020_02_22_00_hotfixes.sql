ALTER TABLE `hotfix_data`   
  DROP COLUMN `Timestamp`, 
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`TableHash`, `RecordID`);

ALTER TABLE `item` ADD COLUMN `DisplayInfoID` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `Material`;
