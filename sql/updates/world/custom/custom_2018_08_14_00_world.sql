-- Template Updates
UPDATE `gameobject_template` SET `ScriptName`= 'go_tott_defense_system' WHERE `entry`= 203199;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_tott_camera',
'spell_tott_shock_defense_script',
'spell_tott_ulthok_intro_visual_impact');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77229, 'spell_tott_camera'),
(86630, 'spell_tott_shock_defense_script'),
(76018, 'spell_tott_ulthok_intro_visual_impact');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (94490, 96042, 86630) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 94490, 0, 0, 31, 0, 3, 40655, 0, 0, 0, '', 'Shock Defense - Target Ozumat'),
(13, 1, 96042, 0, 0, 31, 0, 3, 40655, 0, 0, 0, '', 'Shock Defense - Target Ozumat'),
(13, 1, 86630, 0, 0, 31, 0, 3, 40655, 0, 0, 0, '', 'Shock Defense - Target Ozumat');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry`= 40765;
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry`= 49079;

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 5873;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5873, 'at_tott_commander_ulthok_summon');
