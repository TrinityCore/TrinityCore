-- Kalaran Windblade --> Fix condition
UPDATE `conditions` SET `NegativeCondition`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1323 AND `ConditionTypeOrReference`=2;
