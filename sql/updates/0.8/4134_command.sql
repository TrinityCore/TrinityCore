DELETE FROM `command` WHERE `name` = 'reload all_area';
DELETE FROM `command` WHERE `name` = 'reload all_loot';
DELETE FROM `command` WHERE `name` = 'reload all_quest';
INSERT INTO `command` VALUES('reload all_area',3,'Syntax: .reload all_area\r\n\r\nReload all `areatrigger_*` tables if reload support added for this table and this table can be _safe_ reloaded.');
INSERT INTO `command` VALUES('reload all_loot',3,'Syntax: .reload all_loot\r\n\r\nReload all `*_loot_template` tables. This can be slow operation with lags for server run.');
INSERT INTO `command` VALUES('reload all_quest',3,'Syntax: .reload all_quest\r\n\r\nReload all quest related tables if reload support added for this table and this table can be _safe_ reloaded.');
