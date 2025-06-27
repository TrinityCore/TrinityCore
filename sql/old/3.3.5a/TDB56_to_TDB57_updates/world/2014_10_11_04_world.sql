-- Schematic: Field Repair Bot 74A

Update npc_text set BroadcastTextID0=9486 where `ID`=6931;
Delete from gossip_menu where `entry`=5749 and `text_id`=6931;
insert into gossip_menu (`entry`, `text_id`) values (5749, 6931);

Update npc_text set BroadcastTextID0=9484 where `ID`=6930;
Delete from gossip_menu where `entry`=5749 and `text_id`=6930;
insert into gossip_menu (`entry`, `text_id`) values (5749, 6930);

Update npc_text set BroadcastTextID0=9483 where `ID`=6929;
Delete from gossip_menu where `entry`=5749 and `text_id`=6929;
insert into gossip_menu (`entry`, `text_id`) values (5749, 6929);

Update npc_text set BroadcastTextID0=9487 where `ID`=6932;
Delete from gossip_menu where `entry`=5749 and `text_id`=6932;
insert into gossip_menu (`entry`, `text_id`) values (5749, 6932);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 5749;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) 
VALUES (5749, 0, 0, '<Copy the schematic into your engineering notebook.>', 9485, 1, 3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =15 AND `SourceGroup`=5749;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,5749,0,0,7,202,300,0,0,0,'','Show gossip menu if player have 300 or more in Engineering'), 
(15,5749,0,0,25,22704,0,0,1,0,'','Show gossip menu if player doesn''t learned the spell');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5749 and `SourceEntry`= 6931;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,5749,6931,0,7,202,300,0,1,0,'','Show gossip menu if player is an Engineer but have less than 300'), 
(14,5749,6931,0,25,4036,0,0,0,0,'','Show gossip menu if player is an Engineer');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5749 and `SourceEntry`= 6930;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,5749,6930,0,7,202,300,0,0,'','Show gossip menu if player have 300 or more in Engineering'); 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5749 and `SourceEntry`= 6929;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,5749,6929,0,25,4036,0,0,1,0,'','Show gossip menu if player is not an Engineer');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5749 and `SourceEntry`= 6932;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,5749,6932,0,25,22704,0,0,0,'','Show gossip menu if player learned the spell');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', ScriptName='' WHERE `entry`=179552;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 179552  AND `source_type` = 1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(179552, 1, 0, 0, 62, 0, 100, 0, 5749, 0, 0, 0, 85, 22864, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '179552 - On Gossip Select - InvokerCast'),
(179552, 1, 1, 0, 62, 0, 100, 0, 5749, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '179552 - On Gossip Select - CloseGossip');
