
ALTER TABLE `areatrigger_template` 
DROP PRIMARY KEY,
ADD COLUMN `IsServer` tinyint(1) NOT NULL AFTER `Id`,
ADD PRIMARY KEY (`Id`, `IsServer`);

ALTER TABLE `areatrigger_template_actions` 
DROP PRIMARY KEY,
ADD COLUMN `IsServer` tinyint(1) NOT NULL AFTER `AreaTriggerId`,
ADD PRIMARY KEY (`AreaTriggerId`, `IsServer`);

CREATE TABLE `areatrigger_positions` (
  `SpawnId` int(12) unsigned NOT NULL,	
  `Id` int(10) unsigned NOT NULL,
  `IsServer` tinyint(1) NOT NULL,
  `MapId` int(10) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `PhaseId` int(10) DEFAULT 0,
  `PhaseGroup` int(10) DEFAULT 0,
  `PhaseUseFlags` tinyint(3) DEFAULT 0,
  `Comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SpawnId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


DELETE FROM `areatrigger_positions` WHERE `SpawnId` IN (1, 2);
INSERT INTO `areatrigger_positions` (`SpawnId`, `Id`, `IsServer`, `MapId`, `PosX`, `PosY`, `PosZ`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `Comment`) VALUES
  (1, 1, 1, 0, -9015.774, 877.223, 148.61871, 0, 0, 0, 'Stormwind Mage Portal Entrance'),
  (2, 2, 1, 0, -8999.866, 864.13995, 65.88978, 0, 0, 0, 'Stormwind Mage Portal Exit');

DELETE FROM `areatrigger_template` WHERE `Id` in (1, 2) AND `IsServer` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServer`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
  (1, 1, 1, 0, 1.2597655, 1.2792665, 3.7021635, 0, 0, 0, '', 0),
  (2, 1, 1, 0, 1.2597655, 1.2792665, 3.7021635, 0, 0, 0, '', 0);


DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` IN (1, 2) AND `IsServer` = 1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServer`, `ActionType`, `ActionParam`, `TargetType`) VALUES
  (1, 1, 2, 3631, 5),
  (2, 1, 2, 3630, 5);


UPDATE `world_safe_locs` SET LocX=-9014.864258, LocY=874.324890, LocZ=148.618713 WHERE `id` = 3630;