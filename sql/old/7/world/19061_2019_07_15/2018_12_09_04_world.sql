DROP TABLE IF EXISTS `creature_template_model`;
CREATE TABLE `creature_template_model`(
  `CreatureID` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureDisplayID` int(10) unsigned NOT NULL,
  `DisplayScale` float NOT NULL DEFAULT '1',
  `Probability` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`CreatureID`,`CreatureDisplayID`)
) ENGINE=MYISAM CHARSET=utf8mb4;

INSERT IGNORE INTO `creature_template_model` (`CreatureID`,`Idx`,`CreatureDisplayID`,`DisplayScale`,`Probability`,`VerifiedBuild`) SELECT `entry`,0,`modelid1`,`scale`,1,`VerifiedBuild` FROM `creature_template` WHERE `modelid1`!=0;
INSERT IGNORE INTO `creature_template_model` (`CreatureID`,`Idx`,`CreatureDisplayID`,`DisplayScale`,`Probability`,`VerifiedBuild`) SELECT `entry`,1,`modelid2`,`scale`,1,`VerifiedBuild` FROM `creature_template` WHERE `modelid2`!=0;
INSERT IGNORE INTO `creature_template_model` (`CreatureID`,`Idx`,`CreatureDisplayID`,`DisplayScale`,`Probability`,`VerifiedBuild`) SELECT `entry`,2,`modelid3`,`scale`,1,`VerifiedBuild` FROM `creature_template` WHERE `modelid3`!=0;
INSERT IGNORE INTO `creature_template_model` (`CreatureID`,`Idx`,`CreatureDisplayID`,`DisplayScale`,`Probability`,`VerifiedBuild`) SELECT `entry`,3,`modelid4`,`scale`,1,`VerifiedBuild` FROM `creature_template` WHERE `modelid4`!=0;

UPDATE `creature_template` SET `scale`=1;

ALTER TABLE `creature_template`
  DROP `modelid1`,
  DROP `modelid2`,
  DROP `modelid3`,
  DROP `modelid4`;
