-- Take to the Skies
DELETE FROM `gossip_menu` WHERE `entry`=11152 AND `text_id`=15524;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(11152,15524);

UPDATE `npc_text` SET `BroadcastTextID0`=39129 WHERE `ID`=15524;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=39130, `option_id`=1, `npc_option_npcflag`=8192 WHERE `menu_id`=11152 AND `ID`=1;

UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=37915;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 37915 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 37915*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37915, 0, 0, 0, 62, 0, 100, 0, 11152, 0, 0, 0, 80, 37915*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '37915 - On Gossip Select - Actionlist'),
(37915*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '37915 - Actionlist - Close gossip'),
(37915*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 73442, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '37915 - Actionlist - cast spell');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11152,1,0,9,25012,0,0,0,'','Take to the Skies');
