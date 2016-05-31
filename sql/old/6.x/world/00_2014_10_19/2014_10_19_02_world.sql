DROP TABLE IF EXISTS class_expansion_requirement;
CREATE TABLE class_expansion_requirement
(
  `classID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `expansion` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`classID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO class_expansion_requirement (classID, expansion) VALUES
(1,0),
(2,0),
(3,0),
(4,0),
(5,0),
(6,2),
(7,0),
(8,0),
(9,0),
(10,4),
(11,0);

DROP TABLE IF EXISTS race_expansion_requirement;
CREATE TABLE race_expansion_requirement
(
  `raceID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `expansion` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`raceID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO race_expansion_requirement (raceID, expansion) VALUES
(1,0),
(2,0),
(3,0),
(4,0),
(5,0),
(6,0),
(7,0),
(8,0),
(9,1),
(10,1),
(11,1),
(22,1),
(24,1),
(25,1),
(26,1);
