--
UPDATE `conditions` SET `ConditionTypeOrReference`=32, `ConditionValue1`=0x90, `ScriptName`="condition_is_wintergrasp_horde" WHERE `ConditionTypeOrReference`=48 AND `NegativeCondition`=0;
UPDATE `conditions` SET `ConditionTypeOrReference`=32, `ConditionValue1`=0x90, `NegativeCondition`=0, `ScriptName`="condition_is_wintergrasp_alliance" WHERE `ConditionTypeOrReference`=48 AND `NegativeCondition`=1;
