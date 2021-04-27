UPDATE `creature_template` SET `ScriptName`= 'npc_asaad_unstable_grounding_field' WHERE `entry`= 46492;
UPDATE `creature_template` SET `AIName`= 'NullCreatureAI', `RegenHealth`= 0 WHERE `entry`= 52019;
UPDATE `creature_template` SET `ManaModifierExtra`= 2 WHERE `entry` IN (43875, 43876);
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry` IN (47000, 46387);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_asaad_sots_trigger',
'spell_asaad_storm_rune_beam',
'spell_asaad_grounding_field_visual_beams',
'spell_asaad_supremacy_of_the_storm',
'spell_asaad_supremacy_of_the_storm_visual',
'spell_asaad_static_cling',
'spell_asaad_summon_skyfall_star',
'spell_asaad_sots_targeting',
'spell_asaad_sots_trigger',
'spell_asaad_storm_rune_beam',
'spell_asaad_grounding_field_visual_beams',
'spell_asaad_grounding_field',
'spell_asaad_supremacy_of_the_storm_damage');

UPDATE `creature_template_movement` SET `Ground`= 0, `Swim`= 0, `Flight`= 1 WHERE `CreatureId`= 47000;
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (52019, 52020);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(52019, 0, 1, 0, 1),
(52020, 0, 1, 0, 1);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86632, 'spell_asaad_sots_targeting'),
(86926, 'spell_asaad_sots_trigger'),
(86921, 'spell_asaad_storm_rune_beam'),
(86923, 'spell_asaad_storm_rune_beam'),
(86925, 'spell_asaad_storm_rune_beam'),
(87517, 'spell_asaad_grounding_field_visual_beams'),
(87474, 'spell_asaad_grounding_field'),
(87618, 'spell_asaad_static_cling'),
(86715, 'spell_asaad_supremacy_of_the_storm_visual'),
(87553, 'spell_asaad_supremacy_of_the_storm_damage'),
(93994, 'spell_asaad_supremacy_of_the_storm_damage');

DELETE FROM `conditions` WHERE `SourceEntry` IN (86981, 86923, 86925, 86921, 87517, 86715) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 86981, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Storm Rune Beam AA - Target Storm Target'),
(13, 1, 86921, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Storm Rune Beam A - Target Storm Target'),
(13, 1, 86923, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Storm Rune Beam B - Target Storm Target'),
(13, 1, 86925, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Storm Rune Beam C - Target Storm Target'),
(13, 7, 87517, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Grounding Field Visual Beams - Target Storm Target'),
(13, 1, 86715, 0, 0, 31, 0, 3, 46387, 0, 0, 0, '', 'Supremacy of the Storm - Target Storm Target');

UPDATE `creature_movement_info` SET `WalkSpeed`= 5.5, `RunSpeed`= 5.5 WHERE `MovementID`= 79;
