DELETE FROM `spell_dbc` WHERE `id`=65037;
INSERT INTO `spell_dbc` (`Id`,`Effect1`,`EffectImplicitTargetA1`,`comment`)VALUES
(65037,3,1,'Nerf the Scrapbots Achievement Criteria Marker');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN(10401,10402) AND `type`=18;

DELETE FROM `conditions` WHERE `SourceEntry`=62834 AND `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`)VALUES
(13,62834,18,1,0,'Boombot Boom - Player target'),
(13,62834,18,1,33343,'Boombot Boom - Scrapbot target'),
(13,62834,18,1,33344,'Boombot Boom - Pummeler target'),
(13,62834,18,1,33346,'Boombot Boom - Boombot target'),
(13,62834,18,1,33329,'Boombot Boom - Heart of the Deconstructor target'),
(13,62834,18,1,33293,'Boombot Boom - XT-002 target');
