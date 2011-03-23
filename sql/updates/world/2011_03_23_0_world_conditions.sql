DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=33581;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`,`ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES 
(18,33581,24,1,24238, 'Only use Insult on Bjorn Halgurdsson');
