-- fix bad condition2/3 values on ItemEquip Conditions
UPDATE `conditions` SET `ConditionValue2`=0,`ConditionValue3`=0 WHERE `ConditionTypeOrReference`=3;
