-- The Aldor and Scryers flightmasters should remain unlocked in reputations higher than friendly
UPDATE `conditions` SET `ConditionValue2`=`ConditionValue2`|32|64|128 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8558,8560);
