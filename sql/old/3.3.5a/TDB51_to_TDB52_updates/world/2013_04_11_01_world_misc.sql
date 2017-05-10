SET @NPC_LARRY := 19720;
SET @NPC_MALONE := 19725;
SET @NPC_JACK := 19726;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8033;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(8033, 0, 0, 'Ezekiel said that you might have a certain book...', 1, 1, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (@NPC_LARRY,@NPC_MALONE,@NPC_JACK);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_LARRY,@NPC_MALONE,@NPC_JACK) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_LARRY,0,0,1,25,0,100,0,0,0,0,0,2,1194,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Dirty" Larry - On reset - Set faction'),
(@NPC_LARRY,0,1,2,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Dirty" Larry - On reset - Set unit_flags IMMUNE_TO_PC'),
(@NPC_LARRY,0,2,3,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Dirty" Larry - On reset - Set npcflag gossip, questgiver'),
(@NPC_LARRY,0,3,4,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,10,70376,@NPC_MALONE,0,0,0,0,0,'Dirty" Larry - On reset - Set data 1 2 "Epic" Malone'),
(@NPC_LARRY,0,4,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,10,70377,@NPC_JACK,0,0,0,0,0,'Dirty" Larry - On reset - Set data 1 2 "Creepjack"'),
(@NPC_LARRY,0,5,6,62,0,100,0,8033,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dirty" Larry - On gossip select - Store targetlist'),
(@NPC_LARRY,0,6,7,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dirty" Larry - On gossip select - Close Gossip'),
(@NPC_LARRY,0,7,8,61,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On gossip select - Say line'),
(@NPC_LARRY,0,8,9,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On gossip select - Set npcflag none'),
(@NPC_LARRY,0,9,10,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,10,70376,@NPC_MALONE,0,0,0,0,0,'Dirty" Larry - On gossip select - Respawn "Epic" Malone '),
(@NPC_LARRY,0,10,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,10,70377,@NPC_JACK,0,0,0,0,0,'Dirty" Larry - On gossip select - Respawn "Creepjack" '),
(@NPC_LARRY,0,11,0,52,0,100,0,0,@NPC_LARRY,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Say line'),
(@NPC_LARRY,0,12,0,52,0,100,0,1,@NPC_LARRY,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Say line'),
(@NPC_LARRY,0,13,0,52,0,100,0,2,@NPC_LARRY,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Say line'),
(@NPC_LARRY,0,14,0,52,0,100,0,3,@NPC_LARRY,0,0,1,4,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Say line'),
(@NPC_LARRY,0,15,16,52,0,100,0,4,@NPC_LARRY,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Set faction'),
(@NPC_LARRY,0,16,17,61,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On text over - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_LARRY,0,17,18,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Dirty" Larry - On text over - Attack'),
(@NPC_LARRY,0,18,19,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,70376,@NPC_MALONE,0,0,0,0,0,'Dirty" Larry - On text over - Send targetlist to "Epic" Malone'),
(@NPC_LARRY,0,19,20,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,70376,@NPC_MALONE,0,0,0,0,0,'Dirty" Larry - On text over - Set data 1 1 "Epic" Malone'),
(@NPC_LARRY,0,20,21,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,70377,@NPC_JACK,0,0,0,0,0,'Dirty" Larry - On text over - Send targetlist to "Creepjack"'),
(@NPC_LARRY,0,21,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,70377,@NPC_JACK,0,0,0,0,0,'Dirty" Larry - On text over - Set data 1 1 "Creepjack"'),
(@NPC_LARRY,0,22,23,2,0,100,0,0,20,0,0,15,10231,0,0,0,0,0,16,0,0,0,0,0,0,0,'Dirty" Larry - On health below 20% - Quest credit'),
(@NPC_LARRY,0,23,24,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On health below 20% - Say line'),
(@NPC_LARRY,0,24,3,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On health below 20% - Evade'),
(@NPC_LARRY,0,25,0,11,0,100,0,0,0,0,0,42,0,15,0,0,0,0,1,0,0,0,0,0,0,0,'Dirty" Larry - On spawn - Set invincibility HP level'),

(@NPC_MALONE,0,0,1,25,0,100,0,0,0,0,0,2,1194,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Epic" Malone - On reset - Set faction'),
(@NPC_MALONE,0,1,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Epic" Malone - On reset - Set unit_flags IMMUNE_TO_PC'),
(@NPC_MALONE,0,2,3,38,0,100,0,1,1,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Epic" Malone - On data 1 1 set - Set faction'),
(@NPC_MALONE,0,3,4,61,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Epic" Malone - On data 1 1 set - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_MALONE,0,4,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Epic" Malone - On data 1 1 set - Attack'),
(@NPC_MALONE,0,5,0,38,0,100,0,1,2,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Epic" Malone - On data 1 2 set - Evade'),

(@NPC_JACK,0,0,1,25,0,100,0,0,0,0,0,2,1194,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Creepjack" - On reset - Set faction'),
(@NPC_JACK,0,1,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Creepjack" - On reset - Set unit_flags IMMUNE_TO_PC'),
(@NPC_JACK,0,2,3,38,0,100,0,1,1,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Creepjack" - On data 1 1 set - Set faction'),
(@NPC_JACK,0,3,4,61,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Creepjack" - On data 1 1 set - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_JACK,0,4,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Creepjack" - On data 1 1 set - Attack'),
(@NPC_JACK,0,5,0,38,0,100,0,1,2,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Creepjack" - On data 1 2 set - Evade');

DELETE FROM `creature_text` WHERE `entry`=@NPC_LARRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@NPC_LARRY, 0, 0, 'Time to teach you a lesson in manners, little boy! ', 12, 0, 100, 0, 0, 0, '"Dirty" Larry'),
(@NPC_LARRY, 1, 0, 'I''m now going to give you to the count of "3" to get out of here before I sick the dogs on you.', 12, 0, 100, 0, 0, 0, '"Dirty" Larry'),
(@NPC_LARRY, 2, 0, '1...', 12, 0, 100, 0, 0, 0, '"Dirty" Larry'),
(@NPC_LARRY, 3, 0, '2...', 12, 0, 100, 0, 0, 0, '"Dirty" Larry'),
(@NPC_LARRY, 4, 0, 'Time to meet your maker!', 12, 0, 100, 0, 0, 0, '"Dirty" Larry'),
(@NPC_LARRY, 5, 0, 'Alright, we give up! Don''t hurt us!', 12, 0, 100, 0, 0, 0, '"Dirty" Larry');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8033;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8033,0,0,9,10231,0,0,0,'','"Dirty" Larry only show gossip if player is on and has not completed What Book? I Dont See Any Book');
