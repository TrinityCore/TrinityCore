--
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry`=188596;

DELETE FROM `smart_scripts` WHERE `entryorguid` =188596 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =18859600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188596, 1, 0, 1, 64, 0, 100, 0,0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lokens Pedestal - On Gossip Hello - Store Targetlist'),
(188596, 1, 1, 0, 61, 0, 100, 0,0, 0, 0, 0, 80, 18859600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lokens Pedestal - On Gossip Hello - Run Script'),
(18859600, 9, 0, 0, 0, 0, 100, 0,0, 0, 0, 0, 12, 27212, 3, 38500, 0, 0, 0, 8, 0, 0, 0, 3404.704297, -5394.74434, 270.198853, 1.127, 'Lokens Pedestal - Script - Spawn Image of Loken'),
(18859600, 9, 1, 0, 0, 0, 100, 0,1000, 1000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 27212, 0, 0, 0, 0, 0, 0, 'Lokens Pedestal - Script - Send Target List to Image of Loken');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=27212;

DELETE FROM `smart_scripts` WHERE `entryorguid` =27212 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27212, 0, 0, 0, 1 ,  0, 100, 1, 2000, 2000, 0, 0, 1, 0,6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken - On Spawn - Say Line 0'),
(27212, 0, 1, 0, 52,  0, 100, 0, 0, 27212, 0, 0, 1, 1, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken- On Text Over - Say'),
(27212, 0, 2, 0, 52,  0, 100, 0, 1, 27212, 0, 0, 1, 2, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken- On Text Over - Say'),
(27212, 0, 3, 0, 52,  0, 100, 0, 2, 27212, 0, 0, 1, 3, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken- On Text Over - Say'),
(27212, 0, 4, 0, 52,  0, 100, 0, 3, 27212, 0, 0, 1, 4, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken- On Text Over - Say'),
(27212, 0, 5, 0, 52,  0, 100, 0, 4, 27212, 0, 0,33, 27212, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Image of Loken- Linked with Previous Event - Quest Credit to stored target');

DELETE FROM `creature_text` WHERE `entry`=27212;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(27212, 0, 0, 'You''re late, overseer.', 12, 0, 100,0, 0, 0, 'Image of Loken'),
(27212, 1, 0, 'Destiny will not wait. Your craftsmen must increase their production of the war golems before the stone giant leader and his army reach Ulduar. ', 12,0, 100,0, 0, 0, 'Image of Loken'),
(27212, 2, 0, 'Tell your rune-smiths to continue converting what stone giants you can. Those that will not submit must be destroyed. ', 12, 0, 100,0, 0, 0, 'Image of Loken'),
(27212, 3, 0, 'If the stone giants interfere with our work at Ulduar, I will hold you and your thane responsible. Mortals must not be allowed to come to the aid of the giants.', 12, 0, 100,0, 0, 0, 'Image of Loken'),
(27212, 4, 0, 'Return to your duties, overseer. Be certain to impress upon your workers the urgency of their tasks.', 12, 0, 100,0, 0, 0, 'Image of Loken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceId`=1 AND `SourceEntry`=188596;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 188596, 1, 0, 29, 1, 27212, 200, 0, 1, 0, 0, '', 'Only run SAI if a image of loken is not already spawned'),
(22, 1, 188596, 1, 0, 9, 0, 12203, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has Lokens Orders taken but not complete'),
(22, 1, 188596, 1, 0, 1, 0, 48064, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has Overseer disguise aura'),
(22, 1, 188596, 1, 1, 29, 1, 27212, 200, 0, 1, 0, 0, '', 'Only run SAI if a image of loken is not already spawned'),
(22, 1, 188596, 1, 1, 9, 0, 12185, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has Put on your best face for loken taken but not complete'),
(22, 1, 188596, 1, 1, 1, 0, 48064, 0, 0, 0, 0, 0, '', 'Only run SAI if Player has Overseer disguise aura');
