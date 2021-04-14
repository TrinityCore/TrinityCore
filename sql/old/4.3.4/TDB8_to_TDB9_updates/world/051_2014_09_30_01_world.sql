UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23558,23627,23628,24364,24468);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23558;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23558, 0, 0, 0, 19, 0, 100, 0, 11318, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 1, 0, 19, 0, 100, 0, 11122, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''There and Back Again'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 2, 5, 62, 0, 100, 0, 8934, 3, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Bark for the Barleybrews!'' / ''Bark for the Thunderbrews!'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 3, 5, 62, 0, 100, 0, 8934, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 4, 5, 62, 0, 100, 0, 8934, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(23558, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neill Ramstein <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23627;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23627, 0, 0, 0, 19, 0, 100, 0, 11293, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Becan Barleybrew - On Quest ''Bark for the Barleybrews!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23628;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23628, 0, 0, 0, 19, 0, 100, 0, 11294, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Daran Thunderbrew - On Quest ''Bark for the Thunderbrews!'' Taken - Cast ''Rental Racing Ram''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24364;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24364, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43660, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bok Dropcertain - Within 0-25 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24468;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24468, 0, 1, 0, 8, 0, 100, 0, 43662, 0, 0, 0, 85, 44601, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Pol Amberstill <Ram Racing Apprentice> - On SpellHit - Cast ''Brewfest - Relay Race - Intro - Assign Kill Credit'''),
(24468, 0, 0, 0, 10, 0, 100, 0, 1, 25, 1000, 1000, 11, 43714, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Pol Amberstill <Ram Racing Apprentice> - Within 0-25 Range - Cast ''Brewfest - Throw Keg - DND''');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8934;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8934, 1, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8934, 2, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8934, 3, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8934;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8934, 1, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8934, 2, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8934, 3, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),

(15, 8934, 1, 0, 0, 9, 0, 11122, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "There and Back Again" taken'),
(15, 8934, 2, 0, 0, 9, 0, 11318, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Now This is Ram Racing... Almost." taken'),
(15, 8934, 3, 0, 0, 9, 0, 11293, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for the Barleybrews!" taken'),
(15, 8934, 3, 0, 1, 9, 0, 11294, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Bark for the Thunderbrews!" taken'),

(15, 8934, 1, 0, 0, 28, 0, 11122, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "There and Back Again" rewarded'),
(15, 8934, 2, 0, 0, 28, 0, 11318, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Now This is Ram Racing... Almost." rewarded'),
(15, 8934, 3, 0, 0, 28, 0, 11293, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for the Barleybrews!" rewarded'),
(15, 8934, 3, 0, 1, 28, 0, 11294, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Bark for the Thunderbrews!" rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24364;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24364, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does have Aura "Rental Racing Ram"'),
(22, 1, 24364, 0, 0, 2, 0, 33797, 1, 0, 1, 0, 0, '', 'SAI triggers only if player does not have Item "Portable Brewfest Keg"'),
(22, 1, 24364, 0, 0, 9, 0, 11122, 0, 0, 0, 0, 0, '', 'SAI triggers only if player not have "There and Back Again" taken'),
(22, 1, 24364, 0, 0, 28, 0, 11122, 0, 0, 1, 0, 0, '', 'SAI triggers only if player does not have "There and Back Again" taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24468;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24468, 0, 0, 1, 0, 43883, 0, 0, 0, 0, 0, '', 'SAI triggers only if player does have Aura "Rental Racing Ram"'),
(22, 1, 24468, 0, 0, 2, 0, 33797, 1, 0, 0, 0, 0, '', 'SAI triggers only if player does have Item "Portable Brewfest Keg"');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43662 AND `ConditionValue2`=24468;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43662, 0, 1, 31, 0, 3, 24468, 0, 0, 0, 0, '', 'Brewfest - Throw Keg - Player - DND targets Pol Amberstill <Ram Racing Apprentice>');
