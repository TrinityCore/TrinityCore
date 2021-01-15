DELETE FROM `gossip_menu_option` WHERE `menu_id`=8301 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8301, 1, 0, 'I need another disguise, Borak. I lost the last one.', 19182, 1, 1, 0, 0, 0, 0, '', 0);

UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=37064, `action_param2`=2, `comment`='Borak, Son of Oronok - On Gossip Option 0 Selected -Cast Create Bundle of Bloodthistle' WHERE  `entryorguid`=21293 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24806, `action_param2`=2, `comment`='Hive\'Ashi Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Ashi Rubbing DND' WHERE  `entryorguid`=180454 AND `source_type`=1 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24807, `action_param2`=2, `comment`='Hive\'Regal Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Regal Rubbing DND' WHERE  `entryorguid`=180453 AND `source_type`=1 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=24805, `action_param2`=2, `comment`='Hive\'Zora Glyphed Crystal - On Gossip Option 0 Selected - Cast Create Hive\'Zora Rubbing DND' WHERE  `entryorguid`=180455 AND `source_type`=1 AND `id`=1 AND `link`=0;

DELETE FROM  `smart_scripts` WHERE `entryorguid`=21293 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21293, 0, 5, 3, 62, 0, 100, 0, 8301, 1, 0, 0, 85, 37100, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Borak, Son of Oronok - On Gossip Option 1 Selected -Cast Create Blood Elf Disguise');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8301 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8301, 1, 0, 0, 9, 0, 10577, 0, 0, 0, 0, 0, '', 'Show gossip menu option if player has quest What Illidan Wants, Illidan Gets...'),
(15, 8301, 1, 0, 0, 2, 0, 30639, 1, 0, 1, 0, 0, '', 'Show gossip menu option if player does not have item Blood Elf Disguise');
