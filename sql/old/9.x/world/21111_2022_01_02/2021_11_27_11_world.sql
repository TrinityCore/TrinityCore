DROP TABLE IF EXISTS `jump_charge_params`;
CREATE TABLE `jump_charge_params` (
  `id` int(11) NOT NULL,
  `speed` float NOT NULL DEFAULT 42,
  `treatSpeedAsMoveTimeSeconds` tinyint(1) NOT NULL DEFAULT 0,
  `jumpGravity` float NOT NULL DEFAULT 19.29110527038574,
  `spellVisualId` int(11) DEFAULT NULL,
  `progressCurveId` int(11) DEFAULT NULL,
  `parabolicCurveId` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `progressCurveId`) VALUES
(2, 0.65, 1, 0.018818924203515052, 1636), -- Infernal Strike
(9, 0.88, 1, 0.010237299837172031, 1717); -- Metamorphosis
