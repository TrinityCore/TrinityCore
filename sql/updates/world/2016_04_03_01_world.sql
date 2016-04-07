DELETE FROM `smart_scripts` WHERE `entryorguid`=24713 AND `source_type`=0 AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24713, 0, 2, 3, 62, 0, 100, 0, 9335, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Crowleg" Dan - On Gossip Option Select - Close Gossip'),
(24713, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Crowleg" Dan - On Gossip Option Select - Start Attack');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9335;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9335, 0, 0, 'Ummm... the frog says you''re a traitor, "matey."', 25738, 1, 1, 0, 0, 0, 0, NULL, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9335;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9335, 0, 0, 0, 9, 0, 11479, 0, 0, 0, 0, 0, '', 'Crowleg" Dan - Only show Gossip if player is on quest');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', scriptname='' WHERE `entry` =186944;
DELETE FROM `smart_scripts` WHERE `entryorguid` =186944 AND `source_type`=1;


INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186944, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 105, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dirt Mound - On State Changed - Add Go Flag '),
(186944, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 12, 24790, 1, 120000, 1, 0, 0, 8, 0, 0, 0, 688.9122, -3377.737, 67.87585, 1.291544, 'Dirt Mound - On State Changed - Summon Black Conrads Ghost'),
(186944, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 12, 24796, 1, 120000, 1, 0, 0, 8, 0, 0, 0, 691.5706, -3375.863, 68.09953, 1.308997, 'Dirt Mound - On State Changed - Summon Spectral Sailor'),
(186944, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 24796, 1, 120000, 1, 0, 0, 8, 0, 0, 0, 687.27, -3374.881, 67.92136, 1.047198, 'Dirt Mound - On State Changed - Summon Spectral Sailor');

DELETE FROM `creature` WHERE  `guid`=116177;
UPDATE `gameobject` SET `spawntimesecs`=120 WHERE  `guid`=5842;

DELETE FROM `smart_scripts` WHERE  `entryorguid`=23777 AND `source_type`=0 AND `id`IN(6,7);

UPDATE `smart_scripts` SET `link`=6 WHERE  `entryorguid`=23777 AND `source_type`=0 AND `id`=1 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23777, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake Egg - On Reset - Set Passive'),
(23777, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 94, 24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake Egg - On Reset - Set Dynamic Flags');


UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=23777;
