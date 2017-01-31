DELETE FROM `spell_dbc` WHERE `id`=65074;
INSERT INTO `spell_dbc` (`Id`,`Effect1`,`EffectRadiusIndex1`,`EffectImplicitTargetA1`,`EffectImplicitTargetB1`,`comment`)
VALUES
(65074,3,28,22,30,'Knock on Wood Achievements - Criteria Marker');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10447,10448,10449,10459,10460,10461);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10447,11,0,0,'achievement_knock_on_wood'),
(10447,12,0,0,''),
(10448,11,0,0,'achievement_knock_knock_on_wood'),
(10448,12,0,0,''),
(10449,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10449,12,0,0,''),
(10459,11,0,0,'achievement_knock_on_wood'),
(10459,12,1,0,''),
(10460,11,0,0,'achievement_knock_knock_on_wood'),
(10460,12,1,0,''),
(10461,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10461,12,1,0,'');
