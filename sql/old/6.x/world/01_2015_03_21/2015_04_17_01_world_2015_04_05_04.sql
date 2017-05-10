UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(12256,12255,12254,12253,12252,12251,12249,12244);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(12256,12255,12254,12253,12252,12251,12249,12244) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(12256, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12255, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12254, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12253, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12252, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12251, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12249, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12244, 0, 0, 1, 8, 0, 100, 0, 19250, 0, 120000, 120000, 33, 12247, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Kill Credit'),
(12256, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12255, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12254, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12253, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12252, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12251, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12249, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation'),
(12244, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 177668, 0, 0, 0, 0, 0, 0, 'Mark of Detonation - On Spellhit - Despawn Mark of Detonation');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=19250;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 19250, 0, 0, 31, 0, 3, 12256, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 1, 31, 0, 3, 12255, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 2, 31, 0, 3, 12254, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 3, 31, 0, 3, 12253, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 4, 31, 0, 3, 12252, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 5, 31, 0, 3, 12251, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 6, 31, 0, 3, 12249, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 1, 19250, 0, 7, 31, 0, 3, 12244, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Mark of Detonation'),
(13, 4, 19250, 0, 0, 31, 0, 3, 12247, 0, 0, 0, 0, '', 'Place Smokeys Mixture targets Scourge Structure');
