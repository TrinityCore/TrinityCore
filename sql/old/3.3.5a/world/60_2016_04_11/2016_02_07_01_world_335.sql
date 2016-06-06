-- DB/Item: "Deprecated BKP "Impact" Shot"
-- Restore correct values for bullet item "Deprecated BKP "Impact" Shot":
UPDATE `item_template` SET `name`= 'Deprecated BKP "Impact" Shot', `Quality`= 1,
 `Flags`= 16, `FlagsExtra`= 8192, `BuyCount`= 200, `BuyPrice`= 450, `SellPrice`= 0,
 `ItemLevel`= 35, `RequiredLevel`= 30, `stackable`= 1000, `StatsCount`= 0, 
 `stat_type1`= 0, `stat_value1`= 0, `stat_type2`= 0, `stat_value2`= 0, `dmg_min1`= 9,
 `dmg_max1`= 9, `armor`= 0, `delay`= 3000, `bonding`= 0, `MaxDurability`= 0, `BagFamily`= 2,
 `RequiredDisenchantSkill`= -1, `DisenchantID`= 0 WHERE `entry`= 3034;
