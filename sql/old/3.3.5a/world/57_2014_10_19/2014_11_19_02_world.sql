UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=12933;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry`=12933;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 12933, 0, 0, 8, 0, 12932, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(20, 0, 12933, 0, 0, 8, 0, 12932, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(19, 0, 12933, 0, 1, 8, 0, 12954, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(20, 0, 12933, 0, 1, 8, 0, 12954, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!');
