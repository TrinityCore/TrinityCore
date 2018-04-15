DROP TABLE IF EXISTS ip2nation;
DROP TABLE IF EXISTS ip2nationCountries;

DELETE FROM `command` WHERE `name` in ('account lock', 'account lock ip', 'account lock country');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('account lock ip', 0, 'Syntax: .account lock ip [on|off]\nAllow login from account only from current used IP or remove this requirement.'),
('account lock country', 0, 'Syntax: .account lock country [on|off]\nAllow login from account only from current used Country or remove this requirement.');
