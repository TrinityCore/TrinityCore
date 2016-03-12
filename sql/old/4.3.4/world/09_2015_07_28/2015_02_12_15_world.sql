-- A Scarlet Letter 24979

SET @Lilian:=       38999;
SET @Gebler:=       39002;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Gebler  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Gebler*100  AND `source_type` = 9;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lilian;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Gebler;

DELETE FROM `waypoints` WHERE entry=@Gebler;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Gebler,1, 2451.679932, 1590.894897, 72.156181, 'Joseph'),
(@Gebler,2, 2447.750977, 1587.760864, 72.156181, 'Joseph'),
(@Gebler,3, 2441.820068, 1590.969360, 72.156181, 'Joseph'),
(@Gebler,4, 2441.470703, 1597.166748, 72.156853, 'Joseph');

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Lilian, 0, 0, 0, 62, 0, 100, 0, 11136, 0, 0, 0, 80, @Lilian*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Gossip Select - Actionlist'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Close gossip'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),  
(@Lilian*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.929932, 1600.719971, 72.155197, 3.880454, 'Lilian - action list - set orientation'),
(@Lilian*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Gebler, 8, 6666, 0, 0, 0, 8, 0, 0, 0, 2444.511719, 1599.778687, 66.572655, 5.399958, 'Lilian - action list - Spawn Gebler'),
(@Lilian*100, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Gebler, 30, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk'),
(@Lilian*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Gebler, 30, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk'),
(@Lilian*100, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 73304, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - cast spell'),
(@Lilian*100, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 73453, 1, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Lilian - Actionlist - cast spell'),
(@Lilian*100, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Lilian - Actionlist - kill'),
(@Lilian*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 73304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - remove aura'),
-- (@Lilian*100, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.929932, 1600.719971, 72.155197, 1.937310, 'Lilian - action list - Go to pos'),
(@Lilian*100, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian*100, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Lilian, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Credit quest'),
(@Lilian*100, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - despawn'),

(@Gebler, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80,@Gebler*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gebler - On spawn - Action list'),
(@Gebler*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set React Passive'),
(@Gebler*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0,1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set Immune To PC'),
(@Gebler*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @Gebler, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gebler - Action list - waypoint');

Delete from `creature_text` where `entry`= @Lilian;
Delete from `creature_text` where `entry`= @Gebler;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Lilian, 0, 0, 'Yes, my... wait, be quiet! I hear the lieutenant approaching.', 12, 0, 100, 0, 0, 0, 'Lilian', 39000),
(@Lilian, 1, 0, 'Gebler, you came! What did he say?', 12, 0, 100, 1, 0, 0, 'Lilian', 38994),
(@Lilian, 2, 0, 'What? NO! This can''t be! Gebler, you know me... we were friends once!', 12, 0, 100, 1, 0, 0, 'Lilian', 38996),
(@Lilian, 3, 0, 'Gebler, father, why would you...', 12, 0, 100, 1, 0, 0, 'Lilian', 39001),
(@Lilian, 4, 0, 'The world of the living may have turned its back on me, but I''m no damned Scourge. Just go.', 12, 0, 100, 1, 0, 0, 'Lilian', 38999),
(@Gebler, 0, 0, 'The time has come, my little captive... word has come back from your father.', 12, 0, 100, 0, 0, 0, 'Gebler', 38993),
(@Gebler, 1, 0, 'High Priest Voss denounces you as a daughter. He''s ordered that you be executed immediately.', 12, 0, 100, 1, 0, 0, 'Gebler', 38995),
(@Gebler, 2, 0, 'The High Priest sends his regrets. He had hoped that one day you would be a powerful weapon against our enemies.', 12, 0, 100, 1, 0, 0, 'Gebler', 38997),
(@Gebler, 3, 0, 'Unfortunately, you were too dangerous in life, and you''re far too dangerous in undeath. I will enjoy killing you, you Scourged witch...', 12, 0, 100, 1, 0, 0, 'Gebler', 38998);

UPDATE `creature_template` SET `gossip_menu_id`=11134, npcflag=1 WHERE (`entry`=@Lilian);
-- Lilian
update npc_text set BroadcastTextID0=38985 where `ID`=15487;
update npc_text set BroadcastTextID0=38987 where `ID`=15488;
update npc_text set BroadcastTextID0=38990 where `ID`=15489;

Delete from gossip_menu where `entry`=11134 and `text_id`=15487;
insert into gossip_menu (`entry`, `text_id`) values (11134, 15487);
Delete from gossip_menu where `entry`=11135 and `text_id`=15488;
insert into gossip_menu (`entry`, `text_id`) values (11135,15488);
Delete from gossip_menu where `entry`=11136 and `text_id`=15489;
insert into gossip_menu (`entry`, `text_id`) values (11136,15489);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11134;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) 
VALUES (11134, 0, 0, 'I''m here to rescue you.', 38986, 1, 1, 11135);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11135;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`)
VALUES (11135, 0, 0, 'Lilian, you''re one of the Forsaken, like me.  Which brings the question: why did the Scarlet Crusade put you in a cage?  They usually kill the undead on sight.', 38988, 1, 1, 11136);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11136;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) 
VALUES (11136, 0, 0, 'Your father?', 38991, 1, 1);
-- End Lilian
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11134;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11134,0,0,9,24979,0,0,0,'','Show gossip menu if player accept A Scarlet Letter');

DELETE FROM `creature_loot_template` WHERE `Entry`=1535 AND `Item`=52079;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1535, 52079, 0, 75, 0, 1, 0, 1, 1, NULL); -- Scarlet Warrior, High
