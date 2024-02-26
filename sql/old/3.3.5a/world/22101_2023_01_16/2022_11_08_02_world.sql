-- Hand of Sacrifice can't be casted on targets with Divine Sacrifice
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=17 AND `SourceEntry`=6940; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `NegativeCondition`, `ErrorType`, `Comment`) VALUES
(17, 6940, 1, 1, 64205, 1, 173, 'Cant use Hand of Sacrifice while Divine Sacrifice is active');
