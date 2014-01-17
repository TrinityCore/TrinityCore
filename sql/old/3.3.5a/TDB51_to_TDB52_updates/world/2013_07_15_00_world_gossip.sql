-- Add SAI for Sputtervalve <Independent Contractor> Quest 6981
UPDATE `creature_template` SET `gossip_menu_id`=21,`ScriptName`='' WHERE `entry`=3442;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3442 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(3442, 0, 1, 0, 62, 0, 100, 0, 21, 1, 0, 0, 15, 6981, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sputtervalve - Gossip Option 1 - Complete quest 6981');
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry`=21199;
DELETE FROM `gossip_menu` WHERE `entry` IN (21,22,21340);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
('21','518'), ('21','519'), ('22','520'), (21340,2013);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id`=21;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(21,0,0, 'How can I help?',1,1,22),
(21,1,0, 'Can you tell me about this shard?',1,1,21340);
-- Gossip Menu Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=21;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,21,518,0,0,27,0,10,3,0,0,'','Gossip text requires level 10 or higher'),
(15,21,519,0,0,27,0,10,2,0,0,'','Gossip text requires lower than level 10');
-- Gossip Options Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,21,0,0,0,27,0,10,3,0,0,'','Gossip Option requires level 10 or higher'),
(15,21,1,0,0,9,0,6981,0,0,0,'','Gossip Option requires quest not complete');
