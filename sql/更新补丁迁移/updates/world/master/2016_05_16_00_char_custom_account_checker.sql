
SET FOREIGN_KEY_CHECKS=0;


DROP TABLE IF EXISTS `custom_account_checker`;
CREATE TABLE `custom_account_checker` (
  `type` int(11) NOT NULL DEFAULT '0',
  `count` int(11) NOT NULL DEFAULT '0',
  `account` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
