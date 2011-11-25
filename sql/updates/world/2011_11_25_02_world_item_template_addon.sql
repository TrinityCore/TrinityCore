DROP TABLE IF EXISTS `item_template_addon`;
CREATE TABLE `item_template_addon` (
`Id` int(10) unsigned not null,
`BuyCount` tinyint(3) unsigned not null default 1,
`FoodType` tinyint(3) unsigned not null default 0,
`MinMoneyLoot` int(10) unsigned not null default 0,
`MaxMoneyLoot` int(10) unsigned not null default 0,
`SpellPPMChance` float unsigned not null default 0,
PRIMARY KEY(`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

INSERT INTO `item_template_addon`
SELECT
`item_template`.`entry` AS `Id`,
`item_template`.`BuyCount` AS `BuyCount`,
`item_template`.`FoodType` AS `FoodType`,
`item_template`.`minMoneyLoot` AS `MinMoneyLoot`,
`item_template`.`maxMoneyLoot` AS `MaxMoneyLoot`,
ABS(IF(`item_template`.`spelltrigger_1`=2, `item_template`.`spellppmRate_1`,
      IF (`item_template`.`spelltrigger_2`=2, `item_template`.`spellppmRate_2`,
        IF (`item_template`.`spelltrigger_3`=2, `item_template`.`spellppmRate_3`,
          IF (`item_template`.`spelltrigger_4`=2, `item_template`.`spellppmRate_4`,
            IF (`item_template`.`spelltrigger_5`=2, `item_template`.`spellppmRate_5`, 0))))))
  AS `SpellPPMChance`
FROM
`item_template`
HAVING -- need to use having due to `SpellPPMChance` usage which is not an actual field in table
`item_template`.`BuyCount`!=1 OR
`item_template`.`FoodType`!=0 OR
(`item_template`.`minMoneyLoot`!=0 AND
`item_template`.`maxMoneyLoot`!=0) OR
`SpellPPMChance`!=0;

ALTER TABLE `item_template`
  DROP `BuyCount`,
  DROP `FoodType`,
  DROP `minMoneyLoot`,
  DROP `maxMoneyLoot`;
