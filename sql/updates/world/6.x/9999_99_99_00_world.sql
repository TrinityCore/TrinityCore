CREATE TABLE `areatrigger_template` (
  `id` int(11) unsigned NOT NULL,
  `flags` int(11) unsigned NOT NULL DEFAULT '0',
  `moveCurveId` int(11) unsigned NOT NULL DEFAULT '0',
  `scaleCurveId` int(11) unsigned NOT NULL DEFAULT '0',
  `morphCurveId` int(11) unsigned NOT NULL DEFAULT '0',
  `facingCurveId` int(11) unsigned NOT NULL DEFAULT '0',
  `data0` float NOT NULL DEFAULT '0',
  `data1` float NOT NULL DEFAULT '0',
  `data2` float NOT NULL DEFAULT '0',
  `data3` float NOT NULL DEFAULT '0',
  `data4` float NOT NULL DEFAULT '0',
  `data5` float NOT NULL DEFAULT '0',
  `scriptName` char(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `areatrigger_template_polygon_vertices` (
  `areatriggerId` int(11) unsigned NOT NULL,
  `index` int(11) unsigned NOT NULL,
  `verticeX` float NOT NULL DEFAULT '0',
  `verticeY` float NOT NULL DEFAULT '0',
  `verticeTargetX` float NOT NULL DEFAULT '0',
  `verticeTargetY` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`areatriggerId`,`index`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `areatrigger_template` WHERE `id` IN (2472, 4424);
INSERT INTO `areatrigger_template`(`id`,`flags`,`moveCurveId`,`scaleCurveId`,`morphCurveId`,`facingCurveId`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`scriptName`) VALUES
(2472,65536,0,0,0,0,0,0,0,0,0,0,''),
(4424,131072,0,0,0,0,3,3,4,4,1,1,'');

DELETE FROM `areatrigger_template_polygon_vertices` WHERE `areatriggerId` = 2472;
INSERT INTO `areatrigger_template_polygon_vertices`(`areatriggerId`,`index`,`verticeX`,`verticeY`,`verticeTargetX`,`verticeTargetY`) VALUEs
(2472,0,-1,0.75,0,0),
(2472,1,-1,-0.75,0,0),
(2472,2,4,-0.75,0,0),
(2472,3,4,0.75,0,0);

