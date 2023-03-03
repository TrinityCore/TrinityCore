DROP TABLE IF EXISTS `achievement_dbc`;
CREATE TABLE `achievement_dbc` (
  `ID` int(10) unsigned NOT NULL,
  `requiredFaction` int(11) NOT NULL DEFAULT '-1',
  `mapID` int(11) NOT NULL DEFAULT '-1',
  `points` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '0',
  `refAchievement` int(10) unsigned NOT NULL DEFAULT '0',
  `criteriaTree` int(10) unsigned NOT NULL DEFAULT '0',
  `comment` text,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `criteria_dbc`;
CREATE TABLE `criteria_dbc` (
	`ID` INT NOT NULL DEFAULT '0',
	`type` INT NOT NULL DEFAULT '0',
	`field3` INT NOT NULL DEFAULT '0',
	`timedCriteriaStartType` INT NOT NULL DEFAULT '0',
	`timedCriteriaMiscId` INT NOT NULL DEFAULT '0',
	`timeLimit` INT NOT NULL DEFAULT '0',
	`timedCriteriaFailType` INT NOT NULL DEFAULT '0',
	`timedCriteriaMiscFailId` INT NOT NULL DEFAULT '0',
	`ModifyTree` INT NOT NULL DEFAULT '0',
	`operatorFlags` INT NOT NULL DEFAULT '0',
	`worldStateId` INT NOT NULL DEFAULT '0',
	`worldStateValue` INT NOT NULL DEFAULT '0',
	PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Export of Criteria.dbc';

DROP TABLE IF EXISTS `criteriatree_dbc`;
CREATE TABLE `criteriatree_dbc` (
	`ID` INT NOT NULL DEFAULT '0',
	`criteria` INT NOT NULL DEFAULT '0',
	`requirement_count` INT NOT NULL DEFAULT '0',
	`flags` INT NOT NULL DEFAULT '0',
	`parent` INT NOT NULL DEFAULT '0',
	`flags2` INT NOT NULL DEFAULT '0',
	PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Export of CriteriaTree.dbc';

INSERT INTO `achievement_dbc` VALUE (4788, -1, -1, 0, 2, 0, 0, 4788001, 'Превознесение у Алдоров'); -- 932
INSERT INTO `achievement_dbc` VALUE (4789, -1, -1, 0, 2, 0, 0, 4789001, 'Превознесение у Провидцев'); -- 934

-- "Превознесение у Алдоров"
INSERT INTO `criteriatree_dbc` VALUES (4788001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (4788002, 4762, 42000, 0, 4788001, 2);
-- "Превознесение у Провидцев"
INSERT INTO `criteriatree_dbc` VALUES (4789001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (4789002, 4763, 42000, 0, 4789001, 2);

-- Превознесение в Круговзоре
-- INSERT INTO `criteria_dbc` VALUES (24536, 8, 8905, 0, 0, 0, 0, 0, 0, 0, 0, 0);
-- Превознесение в Пиратской Бухте
-- INSERT INTO `criteria_dbc` VALUES (24535, 8, 8904, 0, 0, 0, 0, 0, 0, 0, 0, 0);
-- Превознесение в Прибамбасске
-- INSERT INTO `criteria_dbc` VALUES (24537, 8, 8907, 0, 0, 0, 0, 0, 0, 0, 0, 0);
-- Уважение среди Пиратов Кровавого Паруса
-- INSERT INTO `criteria_dbc` VALUES (24534, 8, 8908, 0, 0, 0, 0, 0, 0, 0, 0, 0);
-- Превознесение в Кабестане
-- INSERT INTO `criteria_dbc` VALUES (24538, 8, 8906, 0, 0, 0, 0, 0, 0, 0, 0, 0);


-- Insane in the Membrane
INSERT INTO `achievement_dbc` VALUE (8905, -1, -1, 0, 2, 0, 0, 8905001, 'Превознесение в Круговзоре'); -- 577
INSERT INTO `criteriatree_dbc` VALUES (8905001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (8905002, 8820, 42000, 0, 8905001, 2);

INSERT INTO `achievement_dbc` VALUE (8904, -1, -1, 0, 2, 0, 0, 8904001, 'Превознесение в Пиратской Бухте'); -- 21
INSERT INTO `criteriatree_dbc` VALUES (8904001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (8904002, 8819, 42000, 0, 8904001, 2);


INSERT INTO `achievement_dbc` VALUE (8907, -1, -1, 0, 2, 0, 0, 8907001, 'Превознесение в Прибамбасске'); -- 369
INSERT INTO `criteriatree_dbc` VALUES (8907001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (8907002, 8821, 42000, 0, 8907001, 2);


INSERT INTO `achievement_dbc` VALUE (8908, -1, -1, 0, 2, 0, 0, 8908001, 'Уважение среди Пиратов Кровавого Паруса'); -- 87
INSERT INTO `criteriatree_dbc` VALUES (8908001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (8908002, 8818, 9000, 0, 8908001, 2);

INSERT INTO `achievement_dbc` VALUE (8906, -1, -1, 0, 2, 0, 0, 8906001, 'Превознесение в Кабестане'); -- 470
INSERT INTO `criteriatree_dbc` VALUES (8906001, 0, 0, 4, 0, 0);
INSERT INTO `criteriatree_dbc` VALUES (8906002, 8822, 9000, 0, 8906001, 2);
