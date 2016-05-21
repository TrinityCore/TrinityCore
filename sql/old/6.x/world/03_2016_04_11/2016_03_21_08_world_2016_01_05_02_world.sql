-- Add gossip texts to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8719;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8719,0,0,'Absolutely!  Send me to the Skyguard Outpost.',21553,1,1,0,0,0,0,'',0);
-- This was already here but I think rather enumerate from 0 than 1 in gossip_menu_option

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 23415;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` = 8719;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,8719,10980,0,0,5,0,1031,224,0,1,0,'','Skyguard Handler Deesak - Show gossip menu text below Honored reputation with faction 1031'),
(14,8719,10979,0,0,5,0,1031,224,0,0,0,'','Skyguard Handler Deesak - Show gossip menu text above Honored reputation with faction 1031'),
(15,8719,0,0,0,5,0,1031,224,0,0,0,'','Skyguard Handler Deesak - Show gossip option 0 if player has reputation Honored or above with faction 1031');
-- Not sure if the missing condition is necessary, but it makes things a lot clearer when looking at the table.

-- Create SmartAI for Skyguard Handler Deesak
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23415);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23415,0,0,1,62,0,100,0,8719,0,0,0,11,41279,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skyguard Handler Deesak - On Gossip Option 0 Selected - Cast Spell 41279'),
(23415,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skyguard Handler Deesak - On Linked Actions - Close Gossip');
