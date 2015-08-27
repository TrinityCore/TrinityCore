DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 36450;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`,`ConditionValue2`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 36450, 0, 0, 31, 0, 3, 20060, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_0 hit only Lord Sanguinar'),
(13, 1, 36450, 0, 1, 31, 0, 3, 20062, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_0 hit only Grand Astromancer Capernian'),
(13, 1, 36450, 0, 2, 31, 0, 3, 20063, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_0 hit only Master Engineer Telonicus'),
(13, 1, 36450, 0, 3, 31, 0, 3, 20064, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_0 hit only Thaladred the Darkener'),
(13, 2, 36450, 0, 0, 31, 0, 3, 20060, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_1 hit only Lord Sanguinar'),
(13, 2, 36450, 0, 1, 31, 0, 3, 20062, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_1 hit only Grand Astromancer Capernian'),
(13, 2, 36450, 0, 2, 31, 0, 3, 20063, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_1 hit only Master Engineer Telonicus'),
(13, 2, 36450, 0, 3, 31, 0, 3, 20064, 0, 0, 0, '', 'Kael\'thas Ressurection EFFECT_1 hit only Thaladred the Darkener');
