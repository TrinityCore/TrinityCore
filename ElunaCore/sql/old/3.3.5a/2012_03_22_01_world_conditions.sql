-- Manual: Heavy Frostweave Bandage should be lootable if you have at least 390 skills in First Aid
UPDATE `conditions` SET `ConditionValue2`=390 WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=39152 AND `ConditionTypeOrReference`=7 AND `ConditionValue1`=129;
