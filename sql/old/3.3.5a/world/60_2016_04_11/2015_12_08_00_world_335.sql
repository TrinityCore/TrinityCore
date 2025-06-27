-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (2562) AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(2562,1,0,"Gubber, I don't know how to fish.",5529,1,1,0,0,0,0,'',0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2562;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,2562,1,0,9,1141,0,0,0,0,'','Show the gossip option if the quest 1141 is taken'),
(15,2562,1,0,25,7620,0,0,1,0,'','Show the gossip option if Fishing is not learned');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10216;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10216 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10216, 0, 0, 1, 62, 0, 100, 0, 2562, 1, 0, 0, 85, 7733, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gubber Blump- On Gossip Select - Cast Fishing'),
(10216, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gubber Blump- On Gossip Select - Close gossip');
