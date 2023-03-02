/*
**************************
*    BfaCore Reforged    *
**************************
*/

/* Update battleground_template table to avoid a crash */

DROP TABLE IF EXISTS `battleground_template`;
CREATE TABLE IF NOT EXISTS `battleground_template` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `MinPlayersPerTeam` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxPlayersPerTeam` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLvl` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLvl` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllianceStartLoc` mediumint(8) unsigned NOT NULL,
  `HordeStartLoc` mediumint(8) unsigned NOT NULL,
  `StartMaxDist` float NOT NULL DEFAULT '0',
  `Weight` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `ScriptName` char(64) NOT NULL DEFAULT '',
  `Comment` char(32) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


INSERT INTO `battleground_template` (`ID`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
	(1, 10, 40, 45, 120, 611, 610, 150, 1, '', 'Alterac Valley'),
	(2, 2, 10, 10, 120, 769, 770, 75, 1, '', 'Warsong Gulch'),
	(3, 2, 15, 10, 120, 890, 889, 75, 1, '', 'Arathi Basin'),
	(7, 2, 15, 35, 120, 1103, 1104, 75, 1, '', 'Eye of The Storm'),
	(4, 0, 5, 10, 120, 929, 936, 0, 1, '', 'Nagrand Arena'),
	(5, 0, 5, 10, 120, 939, 940, 0, 1, '', 'Blades\'s Edge Arena'),
	(6, 0, 5, 10, 120, 0, 0, 0, 1, '', 'All Arena'),
	(8, 0, 5, 10, 120, 1258, 1259, 0, 1, '', 'Ruins of Lordaeron'),
	(9, 15, 15, 111, 120, 1367, 1368, 0, 1, '', 'Strand of the Ancients'),
	(10, 0, 5, 10, 120, 1362, 1363, 0, 1, '', 'Dalaran Sewers'),
	(11, 0, 5, 10, 120, 1364, 1365, 0, 1, '', 'The Ring of Valor'),
	(30, 10, 40, 71, 120, 1299, 1245, 200, 1, '', 'Isle of Conquest'),
	(32, 2, 40, 45, 120, 0, 0, 0, 1, '', 'Random battleground'),
	(108, 2, 10, 85, 120, 1726, 1727, 0, 0, '', 'Twin Peaks'),
	(120, 2, 10, 85, 120, 1798, 1799, 0, 0, '', 'The Battle for Gilneas'),
	(757, 0, 5, 90, 120, 4534, 4535, 0, 1, '', 'The Tiger\'s Peak'),
	(719, 0, 5, 90, 120, 4136, 4137, 10, 1, '', 'Tol\'viron Arena'),
	(809, 2, 5, 90, 120, 5126, 5127, 0, 1, '', 'Nagrand Arena (Legion)'),
	(816, 0, 5, 90, 120, 5307, 5308, 0, 1, '', 'Arena Ashamanes Fall'),
	(844, 0, 5, 90, 120, 5816, 5817, 0, 1, '', 'Blades Edge Arena'),
	(808, 0, 5, 90, 120, 5121, 5122, 0, 1, '', 'Black Rook Hold Arena'),
	(903, 0, 5, 90, 120, 6616, 6617, 0, 1, '', 'Arena Bfa Mugambala'),
	(699, 2, 10, 40, 120, 4534, 4535, 50, 1, '', 'Kotmogu\'s Temple'),
	(708, 5, 10, 35, 120, 4062, 4061, 0, 1, '', 'Silvershard Mines'),
	(754, 8, 15, 45, 120, 4487, 4486, 0, 1, '', 'Deepwing Gorge'),
	(1025, 0, 5, 90, 120, 7208, 7209, 0, 1, '', 'The Robodrome'),
	(1020, 10, 40, 100, 120, 5276, 5275, 0, 1, '', 'Ashran - Epic Battleground'),
	(1021, 10, 40, 20, 120, 5276, 5275, 0, 1, '', 'Classic Ashran - Endless EB'),
	(894, 5, 10, 110, 120, 6163, 6164, 0, 1, '', 'Seething Shore - Resource Race	'),
	(890, 8, 15, 45, 120, 0, 0, 0, 1, '', 'Seething Strand - Domination'),
	(847, 8, 15, 0, 0, 5821, 5822, 0, 1, '', 'Arathi Basin Winter - Brawl'),
	(880, 6, 6, 110, 120, 0, 0, 0, 1, '', 'Arathi Basin - Brawl'),
	(1018, 8, 15, 10, 120, 7056, 7055, 0, 1, '', 'AB New'),
	(1019, 1, 15, 120, 120, 0, 0, 0, 1, '', 'Arathi Basin - Comp Stomp'),
	(1022, 8, 15, 120, 120, 0, 0, 0, 1, '', 'Arathi Basin - Brawl'),
	(897, 0, 5, 90, 120, 6276, 6277, 0, 1, '', 'Hook Point'),
	(1014, 5, 10, 10, 120, 7051, 7050, 0, 1, '', 'WSG New');
