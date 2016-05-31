ALTER TABLE guild ADD `level` INT(10) unsigned DEFAULT '1' AFTER `BankMoney`;
ALTER TABLE guild ADD `experience` BIGINT(20) unsigned DEFAULT '0' AFTER `level`;
ALTER TABLE guild ADD `todayExperience` BIGINT(20) unsigned DEFAULT '0' AFTER `experience`;
