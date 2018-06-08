UPDATE `instance_template` SET `script`= 'instance_throne_of_the_four_winds' WHERE `map`= 754;

-- Areatrigger Scripts
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6290, 6280, 6281, 6274, 6275, 6276, 6277, 6278, 6279);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6290, 'at_totfw_jet_stream'),
(6280, 'at_totfw_jet_stream'),
(6274, 'at_totfw_jet_stream'),
(6275, 'at_totfw_jet_stream'),
(6276, 'at_totfw_jet_stream'),
(6277, 'at_totfw_jet_stream'),
(6278, 'at_totfw_jet_stream'),
(6279, 'at_totfw_jet_stream'),
(6281, 'at_totfw_catch_fall');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (84610, 85275) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 84610, 0, 0, 31, 0, 3, 21252, 340392, 0, 0, '', 'Jet Stream - Target World Trigger'),
(13, 1, 84610, 0, 1, 31, 0, 3, 47924, 0, 0, 0, '', 'Jet Stream - Target East Wind'),
(13, 1, 84610, 0, 2, 31, 0, 3, 47926, 0, 0, 0, '', 'Jet Stream - Target North Wind'),
(13, 1, 84610, 0, 3, 31, 0, 3, 47925, 0, 0, 0, '', 'Jet Stream - Target East Wind'),
(13, 1, 85275, 0, 0, 31, 0, 3, 21252, 340392, 0, 0, '', 'Catch Fall - Target World Trigger'),
(13, 1, 85275, 0, 1, 31, 0, 3, 47924, 0, 0, 0, '', 'Catch Fall - Target East Wind'),
(13, 1, 85275, 0, 2, 31, 0, 3, 47926, 0, 0, 0, '', 'Catch Fall - Target North Wind'),
(13, 1, 85275, 0, 3, 31, 0, 3, 47925, 0, 0, 0, '', 'Catch Fall - Target East Wind');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_totfw_jet_stream',
'spell_totfw_catch_fall_summon');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84576, 'spell_totfw_jet_stream'),
(85269, 'spell_totfw_catch_fall_summon');

-- Fall Catcher
UPDATE `creature_template` SET `InhabitType`= 4, `VehicleId`= 1134, `unit_flags`= 512, `flags_extra`= 128, `ScriptName`= 'npc_totfw_fall_catcher' WHERE `entry`= 45710;
