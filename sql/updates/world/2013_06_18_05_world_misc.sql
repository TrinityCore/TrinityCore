-- Add texts for Captured Rageclaw
DELETE FROM `creature_text` WHERE `entry`=29686;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29686,0,0,'I poop on you, trollses!',0,0,100,0,0,0,'Captured Rageclaw'),
(29686,0,1,'ARRRROOOOGGGGAAAA!',0,0,100,0,0,0,'Captured Rageclaw'),
(29686,0,2,'No more mister nice wolvar!',0,0,100,0,0,0,'Captured Rageclaw');

-- Add option conditions for Crusade Recruit
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (9650);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9650,0,0,9,12509,0,0,0,0,'','Crusade Recruit - Show gossip option only if player has quest Troll Patrol: Intestinal Fortitude');

-- Add Any Missing Gossip Option for Gymer
DELETE FROM `gossip_menu_option` WHERE menu_id=9852;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(9852,0,0,"I'm ready, Gymer. Let's go!",1,1,0,0,0,0,'');

-- Add option conditions for Gymer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (9852);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9852,0,0,9,12919,0,0,0,0,'','Gymer - Show gossip option only if player has quest The Storm King''s Vengeance');

-- Gymer SAI Quest: The Storm King''s Vengeance
SET @ENTRY := 29647;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9852,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gymer - On Gossip Option Select - Close Gossip Window'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,85,55568,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gymer - On Gossip Option Select - Player cast Summon Gymer on self');
