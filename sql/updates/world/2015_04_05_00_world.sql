DROP TABLE IF EXISTS `quest_poi`;
CREATE TABLE IF NOT EXISTS `quest_poi` (
  `QuestID` INT(11) NOT NULL DEFAULT '0',
  `BlobIndex` INT(11) NOT NULL DEFAULT '0',
  `Idx1` INT(11) NOT NULL DEFAULT '0',
  `ObjectiveIndex` INT(11) NOT NULL DEFAULT '0',
  `QuestObjectiveID` INT(11) NOT NULL DEFAULT '0',
  `QuestObjectID` INT(11) NOT NULL DEFAULT '0',
  `MapID` INT(11) NOT NULL DEFAULT '0',
  `WorldMapAreaId` INT(11) NOT NULL DEFAULT '0',
  `Floor` INT(11) NOT NULL DEFAULT '0',
  `Priority` INT(11) NOT NULL DEFAULT '0',
  `Flags` INT(11) NOT NULL DEFAULT '0',
  `WorldEffectID` INT(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` INT(11) NOT NULL DEFAULT '0',
  `WoDUnk1` INT(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `quest_poi_points`;
CREATE TABLE IF NOT EXISTS `quest_poi_points` (
  `QuestID` INT(11) NOT NULL DEFAULT '0',
  `BlobIndex` INT(11) NOT NULL DEFAULT '0',
  `Idx1` INT(11) NOT NULL DEFAULT '0',
  `Idx2` INT(11) NOT NULL DEFAULT '0',
  `X` INT(11) NOT NULL DEFAULT '0',
  `Y` INT(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `quest_poi`
 ADD PRIMARY KEY (`QuestID`,`BlobIndex`,`Idx1`), ADD KEY `idx` (`QuestID`,`BlobIndex`);
 
ALTER TABLE `quest_poi_points`
 ADD PRIMARY KEY (`QuestID`,`BlobIndex`,`Idx1`,`Idx2`), ADD KEY `questId_id` (`QuestID`,`BlobIndex`);
