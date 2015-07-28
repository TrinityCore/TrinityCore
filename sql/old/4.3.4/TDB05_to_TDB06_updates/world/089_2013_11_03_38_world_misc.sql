--
UPDATE `creature_template` SET `gossip_menu_id`=10036 WHERE  `entry`=31273;

DELETE FROM `gossip_menu` WHERE `entry`IN(10036,10037);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10036, 13930),
(10037, 13931);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10036;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10036, 0, 0, 'Hold on friend. Tell me what happened here.', 1, 1, 10037, 0, 0, 0, NULL);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31273;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31273;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31273, 0, 0, 0, 62, 0, 100, 0, 10036, 0, 0, 0, 33, 31272, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dying Berserker - On Gossip Select - Give Kill Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10036;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10036,0,0,0,9,0,13228,0,0,0,0,'','Dying Berserker show gossip only if player on quest The Broken Front');
