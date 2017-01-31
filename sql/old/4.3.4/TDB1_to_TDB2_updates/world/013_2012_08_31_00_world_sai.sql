-- Defending Your Title (13423)
-- Taking on All Challengers (12971)

SET @NPC_CHALLENGER      := 30012; -- Victorious Challenger
SET @QUEST1              := 12971;
SET @QUEST2              := 13423;
SET @GOSSIP_MENUID       := 9865;
SET @SPELL_SUNDER        := 11971; -- Sunder Armor
SET @SPELL_REND          := 11977; -- Rend

UPDATE `creature_template` SET `faction_A`=2109,`faction_H`=2109,`unit_flags`=0x8000,`npcflag`=0x1,`gossip_menu_id`=@GOSSIP_MENUID,`AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@NPC_CHALLENGER;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_CHALLENGER;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_CHALLENGER,0,0x0,0x1,'');

DELETE FROM `creature_text` WHERE `entry`=@NPC_CHALLENGER;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_CHALLENGER,0,0,'You will not defeat me!',12,0,100,0,0,0,'Victorious Challenger'),
(@NPC_CHALLENGER,0,1,'You''re not worthy of Thorim!',12,0,100,0,0,0,'Victorious Challenger'),
(@NPC_CHALLENGER,0,2,'Good luck...  You''ll need it!',12,0,100,0,0,0,'Victorious Challenger'),
(@NPC_CHALLENGER,0,3,'May the best win!',12,0,100,0,0,0,'Victorious Challenger');

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP_MENUID;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP_MENUID,13660);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP_MENUID,0,0,'Let''s do this, sister.',1,1,0,0,0,0,'');

DELETE FROM `creature_equip_template` WHERE `entry`=@NPC_CHALLENGER;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NPC_CHALLENGER,40542,39288,0);

DELETE FROM `smart_scripts` WHERE (`source_type`=0 AND `entryorguid`=@NPC_CHALLENGER) OR (`source_type`=9 AND `entryorguid`=@NPC_CHALLENGER*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_CHALLENGER,0,0,0,25,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Victorious Challenger - On Reset - Set Default Faction'),
(@NPC_CHALLENGER,0,1,2,62,0,100,0,@GOSSIP_MENUID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Victorious Challenger - On Gossip - Close Gossip'),
(@NPC_CHALLENGER,0,2,0,61,0,100,0,0,0,0,0,80,@NPC_CHALLENGER*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Victorious Challenger - On Gossip - Run Timed Script'),
(@NPC_CHALLENGER,0,3,0,9,0,100,0,0,5,5000,10000,11,@SPELL_SUNDER,0,0,0,0,0,2,0,0,0,0,0,0,0,'Victorious Challenger - On Range - Cast Sunder Armor'),
(@NPC_CHALLENGER,0,4,0,0,0,100,0,10000,15000,15000,20000,11,@SPELL_REND,0,0,0,0,0,2,0,0,0,0,0,0,0,'Victorious Challenger - IC - Cast Rend'),
(@NPC_CHALLENGER*100,9,0,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Victorious Challenger - Timed - Talk'),
(@NPC_CHALLENGER*100,9,1,0,0,0,100,0,3000,3000,3000,3000,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Victorious Challenger - Timed - Set Faction Hostile'),
(@NPC_CHALLENGER*100,9,2,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Victorious Challenger - Timed - Attack Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP_MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP_MENUID,0,0,0,9,0,@QUEST1,0,0,0,0,'','Show gossip option 0 if player has quest Taking on All Challengers'),
(15,@GOSSIP_MENUID,0,0,1,9,0,@QUEST2,0,0,0,0,'','Show gossip option 0 if player has quest Defending Your Title');
