/*
DELETE FROM  `smart_scripts` WHERE `entryorguid`=7665 AND `source_type`=0 AND `id`=2;
DELETE FROM  `smart_scripts` WHERE `entryorguid`=7666 AND `source_type`=0 AND `id`=6;
DELETE FROM  `smart_scripts` WHERE `entryorguid`=7667 AND `source_type`=0 AND `id`=5;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(7665, 0, 2, 0, 8, 0, 100, 0, 12938, 0, 0, 0, 0, 11, 12941, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grol the Destroyer - On Spellhit Fel Curse - Cast Fel Curse Effect'),
(7666, 0, 6, 0, 8, 0, 100, 0, 12938, 0, 0, 0, 0, 11, 12942, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archmage Allistarj - On Spellhit Fel Curse - Cast Fel Curse Effect'),
(7667, 0, 5, 0, 8, 0, 100, 0, 12938, 0, 0, 0, 0, 11, 12943, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sevine - On Spellhit Fel Curse - Cast Fel Curse Effect');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=12938;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 12938, 0, 0, 31, 0, 3, 7665, 0, 0, 0, 0, '', 'Fel Curse Targets Grol the Destroyer'),
(13, 1, 12938, 0, 1, 31, 0, 3, 7666, 0, 0, 0, 0, '', 'Fel Curse Targets Archmage Allistarj'),
(13, 1, 12938, 0, 2, 31, 0, 3, 7667, 0, 0, 0, 0, '', 'Fel Curse Targets Lady Sevine'),
(13, 1, 12938, 0, 3, 31, 0, 3, 7664, 0, 0, 0, 0, '', 'Fel Curse Targets Razelikh the Defiler'),
(13, 1, 12938, 0, 4, 31, 0, 3, 7668, 0, 0, 0, 0, '', 'Fel Curse Targets Servent of Razelikh');
*/
