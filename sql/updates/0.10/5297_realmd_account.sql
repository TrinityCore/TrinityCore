ALTER TABLE `account` 
    CHANGE COLUMN `I` `sha_pass_hash`  VARCHAR(40) NOT NULL default '';