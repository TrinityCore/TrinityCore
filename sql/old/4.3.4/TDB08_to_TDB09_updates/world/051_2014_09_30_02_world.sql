DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4769,4770,4772,4774);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4769, 'SmartTrigger'),
(4774, 'SmartTrigger'),
(4770, 'SmartTrigger'),
(4772, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4769;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4769, 2, 0, 0, 46, 0, 100, 0, 4769, 0, 0, 0, 85, 43259, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 1''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4770;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4770, 2, 0, 0, 46, 0, 100, 0, 4770, 0, 0, 0, 85, 43261, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 3''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4772;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4772, 2, 0, 0, 46, 0, 100, 0, 4772, 0, 0, 0, 85, 43260, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 4''');

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid`=4774;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4774, 2, 0, 0, 46, 0, 100, 0, 4774, 0, 0, 0, 85, 43262, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast ''Brewfest  - Barker Bunny 2''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4769,4770,4772,4774);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4769, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4769, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4769, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4769, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4769, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4770, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4770, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4770, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4770, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4770, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4772, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4772, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4772, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4772, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4772, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken'),

(22, 1, 4774, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4774, 2, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Barleybrews!" taken'),
(22, 1, 4774, 2, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for the Thunderbrews!" taken'),
(22, 1, 4774, 2, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Barleybrews!" taken'),
(22, 1, 4774, 2, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for the Thunderbrews!" taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4801,4802,4803,4804);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4801, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4801, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4801, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4801, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4802, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4802, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4802, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4802, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4803, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4803, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4803, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4803, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),

(22, 1, 4804, 2, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only only if player does not have Aura "Rental Racing Ram"'),
(22, 1, 4804, 2, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(22, 1, 4804, 2, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for Drohn''s Distillery!" taken'),
(22, 1, 4804, 2, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken');
