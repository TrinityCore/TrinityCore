UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=81567 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=85091 AND `source_type`=0 AND `id`=1 AND `link`=0;

DELETE FROM `conversation_line_template` WHERE `Id`=5367;
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES 
(5367, 0, 625, 0, 0, 25901);

UPDATE `conditions` SET `ConditionValue2`='1' WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=2 AND `ConditionTarget`=0 AND `ConditionValue1`=36734 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `ConditionValue2`='1' WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=2 AND `ConditionTarget`=0 AND `ConditionValue1`=36734 AND `ConditionValue2`=0 AND `ConditionValue3`=0;

DELETE FROM `quest_objectives` WHERE  `ID`=257476;

