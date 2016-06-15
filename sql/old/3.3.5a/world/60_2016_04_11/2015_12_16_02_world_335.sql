  DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` in(19,20) AND `SourceEntry`=254;

  INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
  (19, 0, 254, 0, 0, 29, 0, 314, 200, 0, 1, 0, 0, '', 'Show quest \'Digging Through the Dirt\' only if no Eliza nearby'),
  (20, 0, 254, 0, 0, 29, 0, 314, 200, 0, 1, 0, 0, '', 'Show quest \'Digging Through the Dirt\' only if no Eliza nearby'),
  (19, 0, 254, 0, 0, 8, 0, 253, 0, 0, 1, 0, 0, '', 'Show quest \'Digging Through the Dirt\' only if quest \'Bride of the Embalmer\' is not rewarded'),
  (19, 0, 254, 0, 0, 28, 0, 253, 0, 0, 1, 0, 0, '', 'Show quest \'Digging Through the Dirt\' only if quest \'Bride of the Embalmer\' is not completed');
