-- 
ALTER TABLE `command` DROP COLUMN `permission`;
DELETE FROM `command` WHERE `name` IN ('reload command', 'gm', 'gm off', 'gm on');
INSERT INTO `command` (`name`,`help`) VALUES
('gm on', 'Syntax: .gm on

Enables in-game GM mode. This makes you exempt from most game mechanics.
Among other things, it makes creatures unable to attack you, and makes you untargetable by most spells. It also makes creatures in all phases, as well as invisible creatures, visible to you.'),
('gm off', 'Syntax: .gm off

Disables in-game GM mode.');
