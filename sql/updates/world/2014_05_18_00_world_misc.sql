--
UPDATE `creature_template` SET `npcflag`=3, `AIName`='SmartAI' WHERE `entry`=37120;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10910 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES 
(10910, 1, 'I must ask that you reforge Shadow''s Edge for me, Highlord Mograine.', 37855, 1, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`=37120;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37120, 0, 0, 0, 62, 0, 100, 0, 10910, 1, 0, 0, 11, 72995, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Gossip Option 1 Selected - Cast Shadow''s Edge'),
(37120, 0, 1, 0, 62, 0, 100, 0, 10910, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Gossip Option 1 Selected - Close Gossip');

DELETE FROM `conditions` WHERE `SourceGroup`=10910;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10910, 1, 0, 0, 8, 0, 24912, 0, 0, 1, 0, 0, '', 'Highlord Darion Mograine: Hide Gossip option if player has quest 24912 rewarded'),
(15, 10910, 1, 0, 0, 8, 0, 24743, 0, 0, 0, 0, 0, '', 'Highlord Darion Mograine: Show Gossip option if player has quest 24743 rewarded'),
(15, 10910, 1, 0, 0, 2, 0, 49888, 1, 0, 1, 0, 0, '', 'Highlord Darion Mograine: Show Gossip option if player does not have Shadow''s Edge');
