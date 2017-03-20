/*
-- Children's Week quest "Back to the Orphanage" and mail from the Orphans
DELETE FROM `quest_mail_sender` WHERE `QuestId` IN (22817,22818,28879,28880);
INSERT INTO `quest_mail_sender` (`QuestId`,`RewardMailSenderEntry`) VALUES
(10966, 22818), -- Back to the Orphanage (A) sends mail from Draenei Orphan
(10967, 22817), -- Back to the Orphanage (H) sends mail from Blood Elf Orphan
(13959, 33533), -- Back To The Orphanage (Oracle) sends mail from Oracle Orphan
(13960, 33532); -- Back To The Orphanage (Wolvar) sends mail from Wolvar Orphan
*/
