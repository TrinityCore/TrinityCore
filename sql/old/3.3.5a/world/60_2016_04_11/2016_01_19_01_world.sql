--
DELETE FROM `gossip_menu` WHERE `entry` IN (7482, 7483);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7482, 9067),
(7483, 9068);

DELETE FROM `npc_text` WHERE `ID` IN (9068);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `Probability0`, `em0_0`, `BroadcastTextID0`) VALUES
(9068, 'How did you learn about the ore? Not even the Baron knew...$B$BTake the cursed things. They''ve brought me nothing but misfortune anyway. I hid them IN the stables just off the courtyard.$B$B<A low growl begins TO emanate FROM the back of Landen''s throat.>', '', 0, 1, 20, 14393);

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=7482);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(7482,0,0,'Listen to me, human. I care nothing for your plight, but you have something I require. Tell me where to find the bloodforged ingots.',14392,1,1,7483,0,0,0,'',0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7482;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7482,0,0,9,9692,0,0,0,'', 'gossip option on Landen Stilwell requires The Path of the Adept taken');

UPDATE `creature_template` SET `npcflag`=1,`gossip_menu_id` =7482, `AIName`='SmartAI', `flags_extra`=0 WHERE `entry` =17822;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17822;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=1782200;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17822,0,0,0,64,0,100,1,0,0,0,0,80,1782200,2,0,0,0,0,1,0,0,0,0,0,0,0,'Landen Stilwell - on gossip hello - Actionlist'),
(1782200,9,0,0,0,0,100,0,20000,20000,0,0,11,31310,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landen Stilwell - Action list  - cast Landen Stilwell Transform'),
(1782200,9,1,0,0,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landen Stilwell - Action list - set faction'),
(1782200,9,2,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,'Landen Stilwell - Action list - start attack'),
(17822,0,1,0,0,0,100,1,0,0,0,0,11,31310,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landen Stilwell - IC - cast Landen Stilwell Transform');
