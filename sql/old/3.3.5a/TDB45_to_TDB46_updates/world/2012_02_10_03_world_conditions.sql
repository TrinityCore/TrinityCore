-- CONDITION_SPELL with ConditionValue2 = 1 -> CONDITION_SPELL + NegativeCondition
UPDATE `conditions` SET `NegativeCondition` = 1, `ConditionValue2` = 0 WHERE `ConditionTypeOrReference` = 25 AND `ConditionValue2` = 1;
