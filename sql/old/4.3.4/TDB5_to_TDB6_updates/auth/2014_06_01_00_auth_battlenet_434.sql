ALTER TABLE `battlenet_accounts` ADD `sessionKey` VARCHAR(128) NOT NULL DEFAULT '' AFTER `s`;

DELETE FROM `battlenet_modules` WHERE `Name`='Resume';
INSERT INTO `battlenet_modules` VALUES
('bfe4ceb47700aa872e815e007e27df955d4cd4bc1fe731039ee6498ce209f368','Resume','auth','Win',NULL),
('00ffd88a437afbb88d7d4b74be2e3b43601605ee229151aa9f4bebb29ef66280','Resume','auth','Mac',NULL),
('898166926805f897804bdbbf40662c9d768590a51a0b26c40dbcdf332ba11974','Resume','auth','Wn64',NULL),
('304627d437c38500c0b5ca0c6220eeade91390e52a2b005ff3f7754afa1f93cd','Resume','auth','Mc64',NULL);
