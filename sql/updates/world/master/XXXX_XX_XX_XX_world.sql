-- Quest items from deprecated quest Id: 116 Dry Times are buyable from vendors on retail
DELETE FROM `conditions` WHERE `ConditionTypeOrReference` = 9 AND `ConditionValue1` = 116;