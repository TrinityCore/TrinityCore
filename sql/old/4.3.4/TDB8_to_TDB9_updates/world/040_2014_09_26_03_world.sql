DELETE FROM `gossip_menu_option` WHERE `menu_id`=8976 AND `id`=3;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8976, 3, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8976 AND `SourceEntry`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8976, 3, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 3, 0, 0, 9, 0, 11407, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for Drohn''s Distillery!" taken'),
(15, 8976, 3, 0, 1, 9, 0, 11408, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for T''chali''s Voodoo Brewery!" taken'),
(15, 8976, 3, 0, 0, 28, 0, 11407, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for Drohn''s Distillery!" rewarded'),
(15, 8976, 3, 0, 1, 28, 0, 11408, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for T''chali''s Voodoo Brewery!" rewarded');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497 AND `id` >= 4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 4, 7, 62, 0, 100, 0, 8976, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 5, 7, 62, 0, 100, 0, 8976, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 6, 7, 62, 0, 100, 0, 8976, 3, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Bark for T''chali''s Voodoo Brewery!'' / ''Bark for Drohn''s Distillery!'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24498,24499);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24498;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24498, 0, 0, 0, 19, 0, 100, 0, 11407, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cort Gorestein - On Quest ''Bark for Drohn''s Distillery!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24499;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24499, 0, 0, 0, 19, 0, 100, 0, 11408, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ja''ron - On Quest ''Bark for T''chali''s Voodoo Brewery!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24527 AND `ConditionTypeOrReference` IN (9,28);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24527, 0, 0, 9, 0, 11412, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "There and Back Again" taken'),
(22, 1, 24527, 0, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "There and Back Again" taken');
