-- Random comment ™
SET @SHREDDER		:= 27061; -- Xink's Shredder
SET @XINK			:= 26660; -- Xink
SET @SPELL			:= 52872; -- Forceitem Xink's Shredder

UPDATE `creature_template` SET `npcflag`=16777216,`unit_flags`=32768,`spell1`=47938,`spell2`=47921,`spell3`=49857,`spell4`=47966, `spell6`=47939 ,`VehicleId`=42 WHERE `entry`=@SHREDDER;
-- Creature Gossip_menu_option ppdate from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9422) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9422,0,0, 'I seem to have misplaced your Shredder Control Device... might you have another?',1,1,0,0,0,0, '');
-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9422,0,1,9,12050,0,0,0,'','Show gossip only if Lumber Hack quest is taken'),
(15,9422,0,1,26,36734,0,0,0,'','Show gossip only if player does not have item Xink''s Shredder Control Device'),
(15,9422,0,2,26,36734,0,0,0,'','Show gossip option if player does not have item Xink''s Shredder Control Device'),
(15,9422,0,2,9,12052,0,0,0,'','Show gossip option if player has quest marked as taken');

DELETE FROM `conditions` WHERE `SourceEntry`=@SHREDDER;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)VALUES
(16,0,@SHREDDER,0,23,4230,0,0,0,'',"Dismount player when not in intended zone - Coldwind Heights");

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (26660,27061) AND `groupid` IN (0,1);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@XINK,0,0, 'About time!  Get that lumber and get moving.  The horde won''t be up there fighting forever, there''s money to be made!',12,0,100,25,1000,0, 'Xink'),
(@SHREDDER,0,0, 'Xink''s Shredder ready and available for woodland destruction.',16,0,100,0,0,0, 'Xink''s Shredder'),
(@SHREDDER,1,0, 'Xink''s Shredder security features activated.  Returning to base.',16,0,100,0,0,0, 'Xink''s Shredder');

-- SAI for Xink
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@XINK;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@XINK AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@XINK,0,0,0,19,0,100,0,12050,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Xink - On Quest Accept - say 0'),
(@XINK,0,1,2,62,0,100,0,9422,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xink - On Gossip option select - Cast Forceitem Xink''s Shredder'),
(@XINK,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xink - On Gossip option select - Close Gossip');

DELETE FROM `conditions` WHERE `SourceEntry`=47939;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 47939, 0, 0, 35, 0, 1, 5, 3, 0, 0, 0, '', 'Gather Lumber - limit GO targets to Coldwind Tree');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27061;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(27061, 47920, 1, 0);
