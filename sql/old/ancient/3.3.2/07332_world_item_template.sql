-- Resize spellcharge fields in item_template to hold 3.3.0 wdb data
ALTER TABLE `item_template` MODIFY `spellcharges_1` SMALLINT(4); -- Resize make larger
ALTER TABLE `item_template` MODIFY `spellcharges_2` SMALLINT(4); -- Resize make larger
ALTER TABLE `item_template` MODIFY `spellcharges_3` SMALLINT(4); -- Resize make larger
ALTER TABLE `item_template` MODIFY `spellcharges_4` SMALLINT(4); -- Resize make larger
ALTER TABLE `item_template` MODIFY `spellcharges_5` SMALLINT(4); -- Resize make larger

ALTER TABLE `item_template` ADD `WDBVerified` SMALLINT(5) SIGNED DEFAULT 0 AFTER `maxMoneyLoot`;
