UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (721,883,890,1933,2098,2442,2620,4166,5951,10780,12296,12297,12298,12299,17467);
-- Remove unreferenced skinning_loot_template entries because of this update:
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (1933,12299,100000);
