-- These items have a Buycount value but thats now in Item-Sparse.db2 (https://github.com/TrinityCore/TrinityCore/commit/ee06bef31b943fba45d8b018df151f3400e07242)
DELETE FROM `item_template_addon` WHERE `FlagsCu`=0 AND `FoodType`=0 AND `MinMoneyLoot`=0 AND `MaxMoneyLoot`=0 AND `SpellPPMChance`=0;
