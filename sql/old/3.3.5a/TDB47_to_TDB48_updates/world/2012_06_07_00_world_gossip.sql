-- SAI for Charles Worth
SET @NPC    := 28699;
SET @GOSSIP := 10118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC,0,0,2,62,0,100,0,@GOSSIP,3,0,0,85,59817,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Charles Worth - On Gossip Select - Cast Spell Teach Wispcloak'),
(@NPC,0,1,2,62,0,100,0,@GOSSIP,5,0,0,85,59841,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Charles Worth - On Gossip Select - Cast Spell Teach Deathchill Cloak'),
(@NPC,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Charles Worth - On Gossip Select - Close Gossip');
-- Add missing Gossip for Charles Worth
DELETE FROM `gossip_menu` WHERE `entry` IN (10136,10138);
DELETE FROM `gossip_menu` WHERE `entry`=10118 AND `text_id`=14076;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10136,14072),(10138,14074),(10118,14076);
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id` IN (2,3,4,5);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP,2,0, 'Tell me about the Wispcloak Recipe.',1,1,10136,0,0,0, ''),
(@GOSSIP,3,0, 'I am ready to learn the Wispcloak Recipe.',1,1,0,0,0,0, ''),
(@GOSSIP,4,0, 'Tell me about the Deathchill Cloak Recipe.',1,1,10138,0,0,0, ''),
(@GOSSIP,5,0, 'I am ready to learn the Deathchill Cloak Recipe.',1,1,0,0,0,0, '');
-- Add conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,14076,0,7,197,420,0,0,0,'','Only show gossip text 14076 if player has Tailoring with skill level 420');
-- Add conditions for gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,2,0,7,197,420,0,0,0,'','Only show gossip option if player has Tailoring with skill level 420'),
(15,@GOSSIP,2,0,25,56016,0,0,1,0,'','Only show gossip option if player has not learned spell 56016'),
(15,@GOSSIP,3,0,7,197,420,0,0,0,'','Only show gossip option if player has Tailoring with skill level 420 Alliance'),
(15,@GOSSIP,3,0,17,41,0,0,0,0,'','Only show gossip option if player has achievement Loremaster of Northrend Alliance'),
(15,@GOSSIP,3,1,7,197,420,0,0,0,'','Only show gossip option if player has Tailoring with skill level 420 Horde'),
(15,@GOSSIP,3,1,17,1360,0,0,0,0,'','Only show gossip option if player has achievement Loremaster of Northrend Horde'),
(15,@GOSSIP,3,0,25,56016,0,0,1,0,'','Only show gossip option if player has not learned spell 56016'),
(15,@GOSSIP,4,0,7,197,420,0,0,0,'','Only show gossip option if player has Tailoring with skill level 420'),
(15,@GOSSIP,4,0,25,56017,0,0,1,0,'','Only show gossip option if player has not learned spell 56017'),
(15,@GOSSIP,5,0,7,197,420,0,0,0,'','Only show gossip option if player has Tailoring with skill level 420'),
(15,@GOSSIP,5,0,17,1288,0,0,0,0,'','Only show gossip option if player has achievement Northrend Dungeonmaster'),
(15,@GOSSIP,5,0,25,56017,0,0,1,0,'','Only show gossip option if player has not learned spell 56017');
