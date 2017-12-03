CREATE TABLE IF NOT EXISTS `npc_trainer` (
	`ID` mediumint (8),
	`SpellID` mediumint (8),
	`MoneyCost` int (10),
	`ReqSkillLine` smallint (5),
	`ReqSkillRank` smallint (5),
	`ReqLevel` tinyint (3),
	`Index` tinyint (3)
); 
