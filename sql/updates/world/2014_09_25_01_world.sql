DELETE FROM `creature_template_addon` WHERE `entry`=24497;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24497, 22631, 0x0, 0x1, '43880 44069 42146 43492'); -- Ram Master Ray - Ramstein's Swift Work Ram, See Supplier Mark, Brewfest Racing Ram Aura [DND], Brewfest - apple trap - Unfriendly DND

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8976;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8976, 1, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0),
(8976, 2, 0, 'May I have another racing ram?', 74294, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8976;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8976, 1, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 1, 0, 0, 9, 0, 11412, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "There and Back Again" taken'),
(15, 8976, 1, 0, 0, 28, 0, 11412, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "There and Back Again" rewarded'),
(15, 8976, 2, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player does not have Aura "Rental Racing Ram"'),
(15, 8976, 2, 0, 0, 9, 0, 11409, 0, 0, 0, 0, 0, '', 'Show Gossip option only if player does not have "Now This is Ram Racing... Almost." taken'),
(15, 8976, 2, 0, 0, 28, 0, 11409, 0, 0, 1, 0, 0, '', 'Show Gossip option only if player has not quest "Now This is Ram Racing... Almost." rewarded');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24497 AND `id` >= 4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24497, 0, 4, 6, 62, 0, 100, 0, 8976, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 5, 6, 62, 0, 100, 0, 8976, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Quest ''Now This is Ram Racing... Almost.'' Taken - Cast ''Rental Racing Ram'''),
(24497, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42149, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ram Master Ray <Ram Racing Master> - On Link - Cast ''Rental Racing Ram''');
