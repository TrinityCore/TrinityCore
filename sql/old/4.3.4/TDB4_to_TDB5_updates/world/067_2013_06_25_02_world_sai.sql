SET @ENTRY  := 29732;
SET @GOSSIP := 9891;
SET @EAGLE  := 29736;
SET @DRAKE  := 29753;

UPDATE `creature_template` SET `VehicleId`=243,`InhabitType`=3,`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,1,0,0,11,56411,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fjorlin Frostbrow - On gossip option 1 select - Cast 56411 on player'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fjorlin Frostbrow - On gossip option 1 select - Close gossip');

UPDATE `creature_template` SET `npcflag` = `npcflag`|16777217, `VehicleId`=216, `spell1`=55958, `spell2`=55936 WHERE `entry`=@EAGLE;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@EAGLE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(@EAGLE,43671,1,0);

DELETE FROM `creature_template_addon` WHERE entry = @EAGLE;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@EAGLE,0,0,33554432,0,0,'55971');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,1,0,9,12869,0,0,0,'','Show gossip option 1 if player has quest 12869');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`IN (55958,55936);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,55958,0,0,31,1,3,@DRAKE,0,0,0,0,'','Stormbolt only hits Stormpeak Wyrm'),
(17,0,55936,0,0,31,1,3,@DRAKE,0,0,0,0,'','Swoop only hits Stormpeak Wyrm');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,1,0, 'I am ready to join the battle against the wyrms. Do you have an eagle ready for me, Fjorlin?',1,1,0,0,0,0, '');
