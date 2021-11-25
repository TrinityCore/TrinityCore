CREATE TABLE `battleground_sets` (
	`set` mediumint(8) unsigned NOT NULL,
	`battleground` mediumint(8) unsigned NOT NULL,
	`weight` float NOT NULL,
	PRIMARY KEY (`set`,`battleground`)
) ENGINE = MYISAM;

-- All default values from BattlemasterList.dbc (default weights)
INSERT INTO `battleground_sets` VALUES
	  (6,4,1)
	, (6,5,1)
	, (6,8,1)
	, (6,10,1)
	, (6,11,1)

	, (32,1,1)
	, (32,2,1)
	, (32,3,1)
	, (32,7,1)
	, (32,9,1)
	, (32,30,1)
	;