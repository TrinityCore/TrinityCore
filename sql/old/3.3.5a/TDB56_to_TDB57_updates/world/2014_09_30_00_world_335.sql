
DELETE FROM `gossip_menu_option` WHERE `menu_id`=5483;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(5483, 0, 0, 'Barnil, I seem to have misplaced Chapter I.', 9018, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 1, 0, 'Barnil, I seem to have misplaced Chapter II.', 9019, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 2, 0, 'Barnil, I seem to have misplaced Chapter III.', 9020, 1, 1, 0, 0, 0, 0, '', 0),
(5483, 3, 0, 'Barnil, I seem to have misplaced Chapter IV.', 9021, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_text` WHERE `entry` IN(716);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(716, 0, 0, 'I see you misplaced that chapter you worked so hard to put together, $n. Well, you left it right here!', 12, 0, 100, 0, 0, 0, 'Barnil Stonepot', 9022);

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(716);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(716) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(716, 0, 0, 4, 62, 0, 100, 0, 5483, 0, 0, 0, 85, 22208, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 0 Selected - Invoker cast Create Chapter 1 DND '),
(716, 0, 1, 4, 62, 0, 100, 0, 5483, 1, 0, 0, 85, 22209, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 1 Selected - Invoker cast Create Chapter 2 DND '),
(716, 0, 2, 4, 62, 0, 100, 0, 5483, 2, 0, 0, 85, 22210, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 2 Selected - Invoker cast Create Chapter 3 DND '),
(716, 0, 3, 4, 62, 0, 100, 0, 5483, 3, 0, 0, 85, 22211, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - On Gossip Option 3 Selected - Invoker cast Create Chapter 4 DND '),
(716, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - Link - Say Line'),
(716, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Barnil Stonepot - Link - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5483;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 5483, 0, 0, 0, 2, 0, 2756, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter I'),
(15, 5483, 0, 0, 0, 8, 0, 339, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter I rewarded'),
(15, 5483, 0, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 1, 0, 0, 2, 0, 2757, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter II'),
(15, 5483, 1, 0, 0, 8, 0, 340, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter II rewarded'),
(15, 5483, 1, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 2, 0, 0, 2, 0, 2758, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter III'),
(15, 5483, 2, 0, 0, 8, 0, 341, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter III rewarded'),
(15, 5483, 2, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn'),
(15, 5483, 3, 0, 0, 2, 0, 2759, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Green Hills of Stranglethorn - Chapter IV'),
(15, 5483, 3, 0, 0, 8, 0, 342, 0, 0, 0, 0, 0, '', 'Gossip Option requires Chapter IV rewarded'),
(15, 5483, 3, 0, 0, 8, 0, 338, 0, 0, 1, 0, 0, '', 'Gossip Option requires Player is not rewarded for The Green Hills of Stranglethorn');
