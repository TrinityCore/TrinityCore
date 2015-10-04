DELETE FROM `command` WHERE `name`='reset arenaworld';
DELETE FROM `command` WHERE `name`='reset honorworld';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reset honorworld', 900, 'Syntax: .reset honorworld [kills]\nReset all honor points at the default values. With [kills] all the kills will be resetted.'),
('reset arenaworld', 901, 'Syntax: .reset arenaworld [delete]\nReset all arena points/rating at the default values. With [delete] all teams will be deleted.');