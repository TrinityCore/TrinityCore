DELETE FROM `world_custom_config` WHERE `Type` = 'int' AND `IDInTypeGroup` = 1;
INSERT INTO `world_custom_config`(`OptionName`, `Type`, `IDInTypeGroup`, `DefaultValue`, `CustomValue`, `Description`) VALUES 
('Antispam.Mail.Controller', 'int', 1, '100', NULL, 'How many mails player can hold in mailbox, include mail in future (from auctionhouse and calendar).');