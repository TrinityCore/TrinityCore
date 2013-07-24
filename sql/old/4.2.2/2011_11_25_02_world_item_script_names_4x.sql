DROP TABLE IF EXISTS `item_script_names`;
CREATE TABLE `item_script_names` (
`Id` int(10) unsigned not null,
`ScriptName` varchar(64) not null,
PRIMARY KEY(`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

INSERT INTO `item_script_names`
SELECT
`item_template`.`entry` AS `Id`,
`item_template`.`ScriptName` AS `ScriptName`
FROM
`item_template`
WHERE
length(`item_template`.`ScriptName`)>0;

ALTER TABLE `item_template` DROP `ScriptName`;
