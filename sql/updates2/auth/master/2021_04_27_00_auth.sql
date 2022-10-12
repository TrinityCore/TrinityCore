DROP TABLE IF EXISTS `battlepay_purchases`;
CREATE TABLE `battlepay_purchases` (
	`battlenetAccountId` INT(11) NULL DEFAULT NULL,
	`realm` INT(11) NULL DEFAULT NULL,
	`characterGuid` INT(11) NULL DEFAULT NULL,
	`productID` INT(11) NULL DEFAULT NULL,
	`productName` VARCHAR(255) NULL DEFAULT NULL COLLATE 'latin1_swedish_ci',
	`CurrentPrice` INT(11) NULL DEFAULT NULL,
	`RemoteAddress` VARCHAR(50) NULL DEFAULT NULL COLLATE 'latin1_swedish_ci'
)
COLLATE='latin1_swedish_ci'
ENGINE=InnoDB
;

ALTER TABLE `battlenet_accounts`
	ADD COLUMN `battlePayCredits` INT(10) UNSIGNED NULL DEFAULT '0' AFTER `LoginTicketExpiry`;