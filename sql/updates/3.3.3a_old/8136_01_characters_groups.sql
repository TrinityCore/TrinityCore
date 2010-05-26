-- Create guid column and make it new pk
ALTER TABLE `groups` ADD `guid` INT(11) NOT NULL FIRST;
SET @a := 0;
UPDATE `groups` SET `guid` = @a := @a+1;
ALTER TABLE `groups` DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`);
