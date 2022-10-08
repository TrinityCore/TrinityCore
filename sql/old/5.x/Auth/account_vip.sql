DROP TABLE IF EXISTS `account_vip`;
CREATE TABLE IF NOT EXISTS `account_vip` (
  `acc_id` int(10) NOT NULL,
  `viplevel` tinyint(4) NOT NULL DEFAULT '1',
  `active` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`acc_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;