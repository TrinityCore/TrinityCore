CREATE TABLE `script_params`(
    `entryOrGuid` BIGINT(20) NOT NULL,
    `index` TINYINT(3) UNSIGNED NOT NULL AUTO_INCREMENT,
    `numericParam` DOUBLE NOT NULL,
    `stringParam` VARCHAR(255) NOT NULL,
    KEY(`index`),
    PRIMARY KEY (`entryOrGuid`, `index`) ); 
