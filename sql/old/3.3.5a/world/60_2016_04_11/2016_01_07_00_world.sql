-- Add sniffed gossip texts to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 7970;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(7970, 0, 0, 'I''m on a bombing mission for Forward Commander Kingston.  I need a gryphon destroyer!',18198,1,1,0,0,0,0,'',0),
(7970, 1, 0, 'Send me to Shatter Point!',17935,1,1,0,0,0,0,'',0);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '', `gossip_menu_id` = 7970 WHERE `entry` = 19409;

-- Condition: Gossip menu ID 0 needs either quest ID 10146 to be incomplete.
-- Condition: Gossip menu ID 1 needs quest ID 10340 to not be rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` = 7970 AND `SourceEntry`IN (0,1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7970,0,0,0,9,0,10146,0,0,0,0,'','Wing Commander Dabir''ee - Show gossip option 0 if player has taken quest ID 10146'),
(15,7970,1,0,0,8,0,10340,0,0,1,0,'','Wing Commander Dabir''ee - Show gossip option 1 if quest ID 10340 is not rewarded');

-- Create SmartAI for Wing Commander Dabir'ee
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19409);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19409,0,0,2,62,0,100,0,7970,0,0,0,11,33768,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wing Commander Dabir''ee - On Gossip Option 0 Selected - Cast Spell 33768'),
(19409,0,1,2,62,0,100,0,7970,1,0,0,11,35069,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wing Commander Dabir''ee - On Gossip Option 1 Selected - Cast Spell 35069'),
(19409,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wing Commander Dabir''ee - On Linked Actions - Close Gossip');

-- Misc creature fixes
UPDATE `creature` SET `MovementType` = 0 WHERE id = 22987 AND guid IN (79007, 79008, 79009);
