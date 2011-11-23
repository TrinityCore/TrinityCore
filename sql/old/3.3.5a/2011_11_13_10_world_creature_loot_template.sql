-- Drakkari Offerings should also drop when NOT on a quest:
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=ABS(`ChanceOrQuestChance`) WHERE `item`=38551;
