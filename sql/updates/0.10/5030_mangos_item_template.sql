ALTER TABLE `item_template` CHANGE `AllowableClass` `AllowableClass` mediumint(9) not null default '-1';
ALTER TABLE `item_template` CHANGE `AllowableRace`  `AllowableRace` mediumint(9) not null default '-1';

UPDATE `item_template` SET `AllowableClass` = -1 WHERE `AllowableClass` = 0;
UPDATE `item_template` SET `AllowableRace`  = -1 WHERE `AllowableRace`  = 0;
