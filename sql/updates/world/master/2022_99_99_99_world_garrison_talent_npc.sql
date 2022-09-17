DROP TABLE IF EXISTS `garrison_talent_npc`;
CREATE TABLE IF NOT EXISTS `garrison_talent_npc` (
  `NpcEntry` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrTalentTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `FriendshipFactionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` INT NOT NULL DEFAULT 0,
  PRIMARY KEY (`NpcEntry`)
) ENGINE=INNODB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
