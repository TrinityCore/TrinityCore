-- Fix quests: The Explorers' League Outpost (11448), We Can Rebuild It (11483)

SET @MCGOYVER := 24040;
SET @GOSSIP   := 8991;

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@MCGOYVER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MCGOYVER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MCGOYVER,0,0,3,62,0,100,0,@GOSSIP,0,0,0,11,51221,0,0,0,0,0,7,0,0,0,0,0,0,0, 'McGoyver - On gossip option select - Spellcast Taxi to Explorers'' League Outpost'),
(@MCGOYVER,0,1,3,62,0,100,0,9023,0,0,0,11,44280,0,0,0,0,0,7,0,0,0,0,0,0,0, 'McGoyver - On gossip option select - Spellcast Taxi to Explorers'' League Outpost'),
(@MCGOYVER,0,2,3,62,0,100,0,@GOSSIP,1,0,0,11,51221,0,0,0,0,0,7,0,0,0,0,0,0,0, 'McGoyver - On gossip option select - Spellcast Taxi to Explorers'' League Outpost'),
(@MCGOYVER,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'McGoyver - On gossip option select - Close gossip'),
(@MCGOYVER,0,4,0,62,0,100,0,@GOSSIP,2,0,0,11,44512,0,0,0,0,0,7,0,0,0,0,0,0,0, 'McGoyver - On gossip option select - Spellcast Create Dark Iron Ingots');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-51221;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-51221,44280,0,'On spellfade Taxi to Explorers'' League Outpost - Spellcast Taxi to Explorers'' League');

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=12144;
DELETE FROM `gossip_menu` WHERE `entry`=9023 AND `text_id`=12193;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP,12144),
(9023,12193);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id` IN (0,1,2);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9023 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,0,'Official Explorers'' League business, McGoyver. Take me to the Explorers'' League Outpost!',1,1,0,0,0,0,''),
(@GOSSIP,1,0,'Official Explorers'' League business, McGoyver. Take me to the Explorers'' League Outpost!',1,1,0,0,0,0,''),
(@GOSSIP,2,0,'Walt sent me to pick up some dark iron ingots.',1,1,9023,0,0,0,''),
(9023,0,0,'Yarp.',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@GOSSIP;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@MCGOYVER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,12191,0,0,8,11278,0,0,0,0,'','McGoyver show different gossip if player has rewarded quest Return to Valgarde'),
(15,@GOSSIP,0,0,0,28,11448,0,0,0,0,'','McGoyver show gossip option only if player has completed but not rewarded quest The Explorers'' League Outpost'),
(15,@GOSSIP,1,0,0,8,11448,0,0,0,0,'','McGoyver show gossip option only if player has rewarded quest The Explorers'' League Outpost'),
(15,@GOSSIP,2,0,0,9,11483,0,0,0,0,'','McGoyver show gossip option only if player has taken quest We Can Rebuild It'),
(22,5,@MCGOYVER,0,0,2,34135,1,1,1,0,'','SAI triggers only if player has no Dark Iron Ingots');
