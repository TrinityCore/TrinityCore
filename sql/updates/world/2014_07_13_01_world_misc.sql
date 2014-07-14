--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(13,17) AND `SourceEntry`=28268;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 48268, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target needs to be dead'),
(17, 0, 48268, 0, 0, 31, 1, 3, 27202, 0, 0, 0, 0, '', 'Target needs to be Onslaught Raven Priest'),
(17, 0, 48268, 0, 1, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target needs to be dead'),
(17, 0, 48268, 0, 1, 31, 1, 3, 27203, 0, 0, 0, 0, '', 'Target needs to be Onslaught Footman'),
(17, 0, 48268, 0, 2, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target needs to be dead'),
(17, 0, 48268, 0, 2, 31, 1, 3, 27206, 0, 0, 0, 0, '', 'Target needs to be Onslaught Knight'),
(17, 0, 48268, 0, 3, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target needs to be dead'),
(17, 0, 48268, 0, 3, 31, 1, 3, 27207, 0, 0, 0, 0, '', 'Target needs to be Onslaught Workman'),
(17, 0, 48268, 0, 4, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Target needs to be dead'),
(17, 0, 48268, 0, 4, 31, 1, 3, 27211, 0, 0, 0, 0, '', 'Target needs to be Onslaught Executioner'),
(13, 1, 48268, 0, 0, 31, 1, 3, 27202, 0, 0, 0, 0, '', 'Target needs to be Onslaught Raven Priest'),
(13, 1, 48268, 0, 1, 31, 1, 3, 27203, 0, 0, 0, 0, '', 'Target needs to be Onslaught Footman'),
(13, 1, 48268, 0, 2, 31, 1, 3, 27206, 0, 0, 0, 0, '', 'Target needs to be Onslaught Knight'),
(13, 1, 48268, 0, 3, 31, 1, 3, 27207, 0, 0, 0, 0, '', 'Target needs to be Onslaught Workman'),
(13, 1, 48268, 0, 4, 31, 1, 3, 27211, 0, 0, 0, 0, '', 'Target needs to be Onslaught Executioner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=27202 AND `source_type`=0 AND `id`=13;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES #
(27202, 0, 13, 0, 8, 0, 100, 0, 48268, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Spellhit Despawn');
-- Onslaught footman had ai set to smartai but there was no existing sai in db
DELETE FROM `smart_scripts` WHERE `entryorguid`=27203 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES #
(27203, 0, 0, 0, 8, 0, 100, 0, 48268, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - On Spellhit Despawn');
DELETE FROM `smart_scripts` WHERE `entryorguid`=27206 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES #
(27206, 0, 1, 0, 8, 0, 100, 0, 48268, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Knight - On Spellhit Despawn');
DELETE FROM `smart_scripts` WHERE `entryorguid`=27207 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES #
(27207, 0, 1, 0, 8, 0, 100, 0, 48268, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Workman - On Spellhit Despawn');
DELETE FROM `smart_scripts` WHERE `entryorguid`=27211 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES #
(27211, 0, 2, 0, 8, 0, 100, 0, 48268, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Executioner - On Spellhit Despawn');

-- Summon Rats
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48268;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(48268, 48272, 0, 'Let Them Not Rise!: Summon Rat');
