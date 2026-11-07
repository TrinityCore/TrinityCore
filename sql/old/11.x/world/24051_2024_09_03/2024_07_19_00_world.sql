ALTER TABLE `areatrigger_template`
  ADD `ActionSetId` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  ADD `ActionSetFlags` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `ActionSetId`;
  
UPDATE `areatrigger_template` SET `ActionSetFlags`=8 WHERE `Id`=48 AND `IsCustom`=1;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=48 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28,48,1,0,0,36,0,0,0,0,'',1,0,0,'','Only trigger areatrigger when player is dead');
