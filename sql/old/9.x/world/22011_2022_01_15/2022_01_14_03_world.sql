--
ALTER TABLE `playercreateinfo_cast_spell` DROP PRIMARY KEY;
ALTER TABLE `playercreateinfo_cast_spell` ADD `createMode` tinyint(4) NOT NULL DEFAULT '0' AFTER `classMask`;
ALTER TABLE `playercreateinfo_cast_spell` ADD PRIMARY KEY(`raceMask`,`classMask`,`createMode`,`spell`);
