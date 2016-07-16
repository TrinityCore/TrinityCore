--
ALTER TABLE `quest_template_addon` ADD COLUMN `RewardMailSenderEntry` INT(5) UNSIGNED DEFAULT 0 NOT NULL AFTER `ProvidedItemCount`;

UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=11811 WHERE `Id`=8729;  -- Quest The Wrath of Neptulon sends mail from Narain Soothfancy
UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=18166 WHERE `Id`=10588; -- Quest The Cipher of Damnation sends mail from Archmage Khadgar
UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=5885 WHERE `Id`=12085; -- Quest A Letter for Home (horde) sends mail from Deino
UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=2708 WHERE `Id`=12067; -- Quest A Letter for Home (ally) sends mail from Archmage Malin
UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=27102 WHERE `Id`=12422; -- Quest Tactical Clemency sends mail from Gorgonna
UPDATE `quest_template_addon` SET `RewardMailSenderEntry`=28930 WHERE `Id`=12711; -- Quest Abandoned Mail sends mail from Dansel Adams

DELETE FROM `quest_template_addon` WHERE `Id` IN (22817, 22818, 28879, 28880);
INSERT INTO `quest_template_addon` (`Id`, `RewardMailSenderEntry`) VALUES
(22817, 10967), -- Quest Back to the Orphanage (Blood Elf) sends mail from Blood Elf Orphan
(22818, 10966), -- Quest Back to the Orphanage (Draenei) sends mail from Draenei Orphan
(28879, 33533), -- Quest Back To The Orphanage (Oracle) sends mail from Oracle Orphan
(28880, 33532); -- Quest Back To The Orphanage (Wolvar) sends mail from Wolvar Orphan
