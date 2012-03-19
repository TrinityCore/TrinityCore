DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10858,10860) AND `type`=18;

DELETE FROM `spell_dbc` WHERE `id`=65387;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `Effect1`, `EffectRadiusIndex1`, `EffectImplicitTargetA1`, `EffectImplicitTargetB1`, `comment`) VALUES
(65387,0x100,0x10000000,0x5,0x10000000,3,28,22,7, 'Achievement Dwarfageddon - Criteria Marker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=65387;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(13,65387,18,1);

DELETE FROM `smart_scripts` WHERE `entryorguid`=33236 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(33236,0,3,0,6,0,100,0,0,0,0,0,11,65387,0x2,0,0,0,0,1,0,0,0,0,0,0,0, 'Steelforged Defender - Achievement Criteria Spell');