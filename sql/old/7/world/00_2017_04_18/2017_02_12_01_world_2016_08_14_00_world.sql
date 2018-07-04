-- NPC ID/entry 23373 Mortog Steamhead
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 23373;

SET @menu_id := 8692;

DELETE FROM `gossip_menu_option` WHERE `menu_id`= @menu_id;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(@menu_id,0,1,"I'd like to browse your goods.",3370,3,128,0,0,0,0,'',0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= @menu_id AND `SourceEntry`= 0 AND `SourceId`= 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@menu_id,0,0,0,5,0,942,128,0,0,0,0,'', 'Show gossip menu_id 8692 option id 0 if player is Exalted with Cenarion Expedition.');
