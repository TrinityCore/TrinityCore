UPDATE `gameobject_template` SET `flags`=0 WHERE  `entry`=184383;
DELETE FROM `creature` WHERE  `guid`=72505;

DELETE FROM `gossip_menu` WHERE `entry`=8062;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8062, 9958); -- 184073

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8062;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8062, 0, 0, 'Attempt to contact Wind Trader Marid.', 17638, 1, 1, 0, 0, 0, 0, '', 0); -- 184073

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8062;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8062, 0, 0, 0,28, 0, 10270, 0, 0, 0, 0, 0, '', 'Ethereal Teleport Pad - Show Gossip option only if player has A Not-So-Modest Proposal complete in quest log'),
(15, 8062, 0, 0, 0,9, 0, 10271, 0, 0, 1, 0, 0, '', 'Ethereal Teleport Pad - Show Gossip option only if player does not have Getting Down to Business taken'),
(15, 8062, 0, 0, 0,8, 0, 10271, 0, 0, 1, 0, 0, '', 'Ethereal Teleport Pad - Show Gossip option only if player does not have Getting Down to Business rewarded'),
(15, 8062, 0, 0, 0,28, 0, 10271, 0, 0, 1, 0, 0, '', 'Ethereal Teleport Pad - Show Gossip option only if player does not have Getting Down to Business complete'),
(15, 8062, 0, 0, 0,29, 1, 20518, 200, 0, 1, 0, 0, '', 'Ethereal Teleport Pad - Show Gossip option only if Image of Wind Trader Marid is not already spawned');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE  `entry`IN(184073,184383);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(184073,184383) AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(184073, 1, 0, 1, 62, 0, 100, 0, 8062, 0, 0, 0, 12, 20518, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 4006.99, 1516.938, -114.63, 2.303835, 'Ethereal Teleport Pad - On Gossip Option 0 Selected - Summon Image of Wind Trader Marid'),
(184073, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ethereal Teleport Pad - On Gossip Option 0 Selected - Close Gossip'),
(184383, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 12, 20482, 1, 180000, 0, 0, 0, 8, 0, 0, 0, 4017.968, 2315.796, 114.9459, 0.4363323, 'Ethereum Transponder Zeta - On State Changed - Summon Image of Commander Ameer <The Protectorate>');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(20518,20482);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(20518,20482) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(20518, 0, 0, 0, 1, 0, 100, 1, 50, 50, 0, 0, 11, 12980, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Wind Trader Marid - On Just Summoned - Cast Simple Teleport'),
(20482, 0, 0, 1, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Commander Ameer - On Agro - Say Line'),
(20482, 0, 1, 2,61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 14, 25179, 184383, 0, 0, 0, 0, 0, 'Image of Commander Ameer - On Agro - Set Data 1 1 to Ethereum Transponder Zeta'),
(20482, 0, 2, 0,61, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Commander Ameer - On Agro - Despawn'),
(20482, 0, 3, 4,11, 0, 100, 1, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Commander Ameer - On Spawn - Disable Auto Attack'),
(20482, 0, 4, 0,61, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Commander Ameer - On Spawn - Disable combat movement');

DELETE FROM `creature_text` WHERE `entry`=20482;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(20482, 0, 0, 'Hostiles detected. Ending transmission.', 12, 0, 100, 15, 0, 0, 'Image of Commander Ameer',18190);
