CREATE TABLE `test_sessions` (
	`sessionName` VARCHAR(255) NOT NULL,
	`modName` VARCHAR(255) NOT NULL,
	`testName` VARCHAR(255) NOT NULL,
	`stepName` VARCHAR(255) NOT NULL,
	`filter` TEXT NOT NULL,
	`errorCount` INT(10) NOT NULL,
	`totalCount` INT(10) NOT NULL,
	`finished` TINYINT(3) DEFAULT "0",
	PRIMARY KEY (`sessionName`)
);

CREATE TABLE `test_errors` (
	`sessionName` VARCHAR(80) NOT NULL,
	`testType` VARCHAR(80) NOT NULL,
	`modName` VARCHAR(80) NOT NULL,
	`testName` VARCHAR(80) NOT NULL,
	`stepName` VARCHAR(255) NOT NULL,
	`errorMessage` TEXT NOT NULL,
	PRIMARY KEY (`sessionName`,`testType`,`modName`,`testName`)
);