ALTER TABLE `account` CHANGE `sessionkey` `sessionkey` varchar(80) NOT NULL DEFAULT '' AFTER `sha_pass_hash`;
