CREATE TABLE `controlable_guardian_action_bar_info` (
  `guid` int(11) NOT NULL,
  `entry` mediumint(8) NOT NULL,
  `infoMask` mediumint(8) NOT NULL,
  PRIMARY KEY (`guid`,`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;