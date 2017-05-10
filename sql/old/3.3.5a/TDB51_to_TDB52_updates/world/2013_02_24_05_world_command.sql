DELETE FROM `command` WHERE `name` = 'reload creature_summon_groups';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload creature_summon_groups',3,'Syntax: .reload creature_summon_groups
Reload creature_summon_groups table.');
