--
DROP TABLE IF EXISTS `quest_mail_sender`;
CREATE TABLE `quest_mail_sender`
(
  `QuestId` INT(5) UNSIGNED NOT NULL DEFAULT 0,
  `RewardMailSenderEntry` INT(5) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`QuestId`)
); 

INSERT INTO `quest_mail_sender` (`QuestId`, `RewardMailSenderEntry`) VALUES
(8729, 11811), -- Quest The Wrath of Neptulon sends mail from Narain Soothfancy
(10588, 18166), -- Quest The Cipher of Damnation sends mail from Archmage Khadgar
(12085, 5885), -- Quest A Letter for Home (Horde) sends mail from Deino
(12067, 2708), -- Quest A Letter for Home (Alliance) sends mail from Archmage Malin
(12422, 27102), -- Quest Tactical Clemency sends mail from Gorgonna
(12711, 28930), -- Quest Abandoned Mail sends mail from Dansel Adams
(22817, 10967), -- Quest Back to the Orphanage (Blood Elf) sends mail from Blood Elf Orphan
(22818, 10966), -- Quest Back to the Orphanage (Draenei) sends mail from Draenei Orphan
(28879, 33533), -- Quest Back To The Orphanage (Oracle) sends mail from Oracle Orphan
(28880, 33532); -- Quest Back To The Orphanage (Wolvar) sends mail from Wolvar Orphan
