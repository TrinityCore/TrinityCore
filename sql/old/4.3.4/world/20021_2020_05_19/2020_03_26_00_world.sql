DELETE FROM `gossip_menu_option_trainer` WHERE `MenuId` IN (11817, 4463, 4484, 4486, 11793, 4470, 14199, 7494, 4508);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(11817, 0, 40),
(4463, 0, 135),
(4484, 0, 135),
(4486, 0, 135),
(11793, 0, 16),
(14199, 0, 16),
(4470, 0, 164),
(7494, 0, 58),
(4508, 0, 39);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (11817, 4463, 11793, 14199);
INSERT INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`) VALUES
-- Stormwind Hunter Trainers
(11817, 0, 3, 'I seek training in the ways of the Hunter.', 7643, 5, 16),
(11817, 1, 0, 'I wish to unlearn my talents.', 62295, 16, 16),
(11817, 2, 0, 'I wish to know about Dual Talent Specialization.', 33762, 20, 1),
-- Stormwind Mage Trainer
(4463, 0, 3, 'I am interested in mage training.', 2522, 5, 16),
(4463, 1, 0, 'I wish to unlearn my talents.', 62295, 16, 16),
(4463, 2, 0, 'I wish to know about Dual Talent Specialization.', 33762, 20, 1),
-- Silvermoon Warrior Trainers
(11793, 0, 3, 'I require warrior training.', 3147, 5, 16),
(11793, 1, 0, 'I wish to unlearn my talents.', 62295, 16, 16),
(11793, 2, 0, 'I wish to know about Dual Talent Specialization.', 33762, 20, 1),
(14199, 0, 3, 'I require warrior training.', 3147, 5, 16),
(14199, 1, 0, 'I wish to unlearn my talents.', 62295, 16, 16),
(14199, 2, 0, 'I wish to know about Dual Talent Specialization.', 33762, 20, 1);

UPDATE `creature_template` SET `gossip_menu_id`= 14199, `npcflag`= `npcflag` | 1 WHERE `entry` IN (44128, 43009, 44129);
-- Silvermoon Blacksmith Trainer
UPDATE `creature_template` SET `gossip_menu_id`= 7494 WHERE `entry`= 16669;
