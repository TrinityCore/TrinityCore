--
DELETE FROM `command` WHERE `name` IN ('group repair','group level','group revive');
INSERT INTO `command` (`name`,`help`) VALUES
('group repair', 'Syntax: .group repair [$charactername] Repair the given character and his group. Repair only online group characters but original selected group member can be offline. If no character is selected and name not provided, it will repair yourself.'),
('group level', 'Syntax: .group level [$charactername] Set the level of the given character and his group to #numberoflevels (only positive values 1+). Modify only online group characters level but original selected group member can be offline. All stats and dependent values are not recalculated. At level decrease talents can be reset if need. Also at level decrease equipped items with greater level requirement can be lost. If no character is selected and name not provided, it will modify your level.'),
('group revive', 'Syntax: .group revive [$charactername] Revive the given character and his group. Revive only online group characters but original selected group member can be offline. If no character is selected and name not provided, it will revive yourself.');
