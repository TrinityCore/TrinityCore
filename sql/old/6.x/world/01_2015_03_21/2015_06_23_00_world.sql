--
-- Table structure for table `garrison_plot_finalize_info`
--

DROP TABLE IF EXISTS `garrison_plot_finalize_info`;
CREATE TABLE `garrison_plot_finalize_info` (
  `garrPlotInstanceId` int(10) unsigned NOT NULL,
  `hordeGameObjectId` int(10) unsigned NOT NULL DEFAULT '0',
  `hordeX` float NOT NULL DEFAULT '0',
  `hordeY` float NOT NULL DEFAULT '0',
  `hordeZ` float NOT NULL DEFAULT '0',
  `hordeO` float NOT NULL DEFAULT '0',
  `hordeAnimKitId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `allianceGameObjectId` int(10) unsigned NOT NULL DEFAULT '0',
  `allianceX` float NOT NULL DEFAULT '0',
  `allianceY` float NOT NULL DEFAULT '0',
  `allianceZ` float NOT NULL DEFAULT '0',
  `allianceO` float NOT NULL DEFAULT '0',
  `allianceAnimKitId` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`garrPlotInstanceId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `garrison_plot_finalize_info`
--

INSERT INTO `garrison_plot_finalize_info` (`garrPlotInstanceId`, `hordeGameObjectId`, `hordeX`, `hordeY`, `hordeZ`, `hordeO`, `hordeAnimKitId`, `allianceGameObjectId`, `allianceX`, `allianceY`, `allianceZ`, `allianceO`, `allianceAnimKitId`) VALUES
(18,233248,5642.37,4514.43,119.27,1.88088,1696,0,0,0,0,0,0),
(19,231964,5652.18,4539.69,119.27,3.74629,1696,0,0,0,0,0,0),
(20,236186,5623.58,4516.67,119.27,0.97567,1696,0,0,0,0,0,0),
(22,233249,5547.58,4522.44,131.393,0.0108777,1696,0,0,0,0,0,0),
(23,231217,5589.08,4480.11,130.349,1.05262,1696,0,0,0,0,0,0),
(24,236187,5643.26,4463.4,130.525,1.9379,1696,0,0,0,0,0,0),
(25,236188,5679.95,4486.13,131.107,2.4223,1696,0,0,0,0,0,0),
(59,236176,5475.8,4447.15,144.519,0.955649,1696,0,0,0,0,0,0),
(63,236177,5424.65,4567.79,137.431,0.112897,1696,0,0,0,0,0,0),
(67,236185,5476.71,4617.02,134.45,5.02338,1696,0,0,0,0,0,0),
(81,236175,5621.77,4652.88,142.448,4.39222,1696,0,0,0,0,0,0);
