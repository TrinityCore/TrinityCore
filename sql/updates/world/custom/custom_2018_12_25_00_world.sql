UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 50604;

DELETE FROM `vehicle_template_accessory` WHERE `entry`IN (46962, 49708);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(46962, 50604, 0, 1, 'Baron Ashbury - Wings', 5, 0),
(49708, 50604, 0, 1, 'Baron Ashbury - Wings', 5, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`IN (46962, 49708);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46962, 46598, 1, 1),
(49708, 46598, 1, 1);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 93766;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_sfk_asphyxiate',
'spell_ashbury_asphyxiate',
'spell_sfk_pain_and_suffering',
'spell_ashbury_pain_and_suffering',
'spell_ashbury_dark_archangel_form');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93423, 'spell_ashbury_asphyxiate'),
(93710, 'spell_ashbury_asphyxiate'),
(93581, 'spell_ashbury_pain_and_suffering'),
(93712, 'spell_ashbury_pain_and_suffering'),
(93757, 'spell_ashbury_dark_archangel_form');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 93766 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 93766, 0, 0, 31, 0, 3, 50604, 0, 0, 0, '', 'Dark Archangel Form - Target Wings');
