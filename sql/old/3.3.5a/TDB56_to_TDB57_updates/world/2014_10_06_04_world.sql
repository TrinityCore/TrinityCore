DELETE FROM `waypoint_data` WHERE `id`=1131170;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=113117;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=113117;

DELETE FROM `waypoints` WHERE `entry`=23734;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(23734, 1, 629.388, -5021.37, 3.04091, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 2, 630.836, -5011.95, 3.8314, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 3, 630.836, -5011.95, 3.8314, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 4, 624.458, -5003.92, 3.59241, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 5, 614.28, -5005.49, 3.06355, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 6, 607.946, -5014.89, 3.10032, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 7, 612.983, -5025.49, 2.03711, 'Anchorite Yazmina <First Aid Trainer>'),
(23734, 8, 625.177, -5026.14, 2.32847, 'Anchorite Yazmina <First Aid Trainer>');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(23734,23728);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23734,23728) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2373400,2373401,2373402,2373403,237404,2372800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23734, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 23734, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - On Spawn - Start WP'),
(23734, 0, 1, 0, 40, 0, 5, 0, 0, 0, 0, 0, 87, 2373400,2373401,2373402,2373403,0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - On Reached WP - Run Random Script'),
(23728, 0, 0, 0, 10, 0, 100, 0, 1, 50, 120000, 300000, 80, 2372800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - OOC LOS - Run Script'),
(2372800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 0'),
(2372800, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 1'),
(2372800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 2'),
(2372800, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Captain Zorek - Script - Say Line 3'),
(2373400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 1 - Pause WP'),
(2373401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Pause WP'),
(2373401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Face Injured Defender'),
(2373401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Say Line 1'),
(2373401, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Bytes 1'),
(2373401, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Emote State 69'),
(2373401, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Set Emote State 0'),
(2373401, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Say Line 2'),
(2373401, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 2 - Remove Bytes 1'),
(2373402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Pause WP'),
(2373402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Face Injured Defender'),
(2373402, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Say Line 3'),
(2373402, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Bytes 1'),
(2373402, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Emote State 69'),
(2373402, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Set Emote State 0'),
(2373402, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Say Line 0'),
(2373402, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 3 - Remove Bytes 1'),
(2373403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Pause WP'),
(2373403, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 23783, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Face Injured Defender'),
(2373403, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Say Line 4'),
(2373403, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Bytes 1'),
(2373403, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Emote State 69'),
(2373403, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Set Emote State 0'),
(2373403, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Say Line 5'),
(2373403, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Yazmina <First Aid Trainer> - Script 4 - Remove Bytes 1');

DELETE FROM `creature_text` WHERE `entry` IN(23734,23728);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(23734, 0, 0, 'That should slow the infection down a little.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22251),
(23734, 1, 0, 'I can only hope the treatment will work.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22828),
(23734, 2, 0, 'I just don''t have the medical supplies I need to properly treat all of you.', 12, 7, 100, 1, 0, 5495, 'Anchorite Yazmina',22829),
(23734, 3, 0, 'Oh my, let me change those bandages!', 12, 7, 100, 5, 0, 0, 'Anchorite Yazmina',22250),
(23734, 4, 0, 'Don''t worry, soldier. Yazmina is going to take care of you.', 12, 7, 100, 1, 0, 0, 'Anchorite Yazmina',22830),
(23734, 5, 0, '%s shakes her head.', 16, 7, 100, 274, 0, 0, 'Anchorite Yazmina',22831),
(23728, 0, 0, '%s clears his throat.', 16, 7, 100, 0, 0, 0, 'Guard Captain Zorek',22737),
(23728, 1, 0, 'I look across this base and all I see is fear... Are you gonna be scared when the Lich King''s armies are sittin'' pretty in Stormwind? Ironforge? NO! You''re not. And do you know why? Because you''ll be dead, that''s why.', 12, 7, 100, 1, 0, 0, 'Guard Captain Zorek',22738),
(23728, 2, 0, 'So when you''re feeling that tinglin'' sensation at the base of your spine and you''re ''bout ready to wet your pants, embrace it. Let it enrage you. That fear is the only thing that''s gonna keep you breathin''.', 12, 7, 100, 25, 0, 0, 'Guard Captain Zorek',22739),
(23728, 3, 0, 'Am I clear? Do you understand what I''m sayin''? I don''t wanna have to send any more coffins or letters home.', 12, 7, 100, 6, 0, 0, 'Guard Captain Zorek',22740);
