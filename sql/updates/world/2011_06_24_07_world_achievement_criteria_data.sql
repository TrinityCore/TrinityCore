DELETE FROM `spell_dbc` WHERE `id`=59046;
INSERT INTO `spell_dbc` (`Id`,`Effect1`,`EffectRadiusIndex1`,`EffectImplicitTargetA1`,`EffectImplicitTargetB1`,`comment`)
VALUES
(59046,3,28,22,30,'Tribunal of Ages - Criteria Marker');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7590 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7590,11,0,0,'achievement_brann_sparklin_news');
