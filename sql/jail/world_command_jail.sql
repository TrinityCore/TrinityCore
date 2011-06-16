SET NAMES utf8;

DELETE FROM `command` WHERE `name` LIKE '%jail%';
INSERT INTO `command` (name, security, help) VALUES
('jail info',       0,  'Syntax: .jail info\nZeigt dir deinen Knast-Status an.'),
('jail pinfo',      10, 'Syntax: .jail pinfo [Charakter]\nZeigt Jail-Infos vom selektiertem, oder angegeben Charakter an.'),
('jail arrest',     20, 'Syntax: .jail arrest Charakter Stunden Grund\nBuchtet den ''Charakter'' für ''Stunden'' aus dem ''Grund'' ein.'),
('jail release',    20, 'Syntax: .jail release Charakter\nEntlässt den ''Charakter'' aus dem Knast.'),
('jail reset',      20, 'Syntax: .jail reset [Charakter]\nGibt dem selektiertem, oder angegebem Charakter, wieder eine weisse Weste.\nAls wäre nie etwas geschehen. ;-)'),
('jail reload',     40, 'Syntax: .jail reload\nLädt die Jail-Konfiguration neu aus der Datenbank.');
