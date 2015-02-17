--
SET @CGUID :=    49141;

SET @Loken  :=    30396;
SET @Thorim :=    30399;
SET @Veranus:=    30420;
SET @Servant:=    30429;

UPDATE `creature_template` SET `gossip_menu_id`=9928, `minlevel`=82, `maxlevel`=82, `npcflag`=1, `speed_walk`=4.8, `speed_run`=3.142857, `rank`=3, `unit_flags`=320, `unit_flags2`=2099200, `AIName`='SmartAI', `type_flags`=0 WHERE  `entry`=@Thorim; -- thorim
UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.6, `speed_run`=1.857143, `unit_flags`=320, `unit_flags2`=2099200, `AIName`='SmartAI' WHERE  `entry`=@Loken; -- loken
UPDATE `creature_template` SET `speed_walk`=3.2, `speed_run`=1.428571, `unit_flags`=33088, `unit_flags2`=2099200, `AIName`='SmartAI', `HoverHeight`=2.1, `InhabitType`=4 WHERE  `entry`=@Veranus;
UPDATE `creature_template` SET `faction`=2102, `unit_flags`=320,`AIName`='SmartAI' WHERE  `entry`=@Servant;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@Thorim*100,@Loken*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(@Thorim,@Loken,@Veranus,@Servant) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Loken,0,0,1,38,0,100,0,1,1,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - On Data Set 1 1 - Set Bytes 1"),
(@Loken,0,1,0,61,0,100,0,0,0,0,0,80,@Loken*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - On Data Set 1 1 - Run Script"),
(@Veranus,0,0,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,8609.171875, -636.665955, 967.317383, 2.124008,"Veranus - On Data Set 1 1 - move to pos"),
(@Veranus,0,1,2,38,0,100,0,2,2,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veranus - On Data Set 2 2 - Cast Ethereal Teleport"),
(@Veranus,0,2,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veranus - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Veranus,0,3,0,1,0,100,0,160000,160000,160000,160000,70,0,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Veranus - Ooc - respawn target"),
(@Servant,0,0,1,38,0,100,0,2,2,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Cast Ethereal Teleport"),
(@Servant,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Servant,0,2,3,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Servant,0,3,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runeforged Servant <Servant of Loken> - On Data Set 2 2 - Despawn After 1 Seconds"),
(@Thorim,0,0,1,62,0,100,0,9928,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Store Targetlist"),
(@Thorim,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Close Gossip"), 
(@Thorim,0,2,3,61,0,100,0,0,0,0,0,28,54503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - remove aura"),
(@Thorim,0,3,0,61,0,100,0,0,0,0,0,80,@Thorim*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Gossip Option select - Run Script"),
(@Thorim,0,4,0,40,0,100,0,2,@Thorim,0,0,1,1,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - On Reached WP2 - Say Line 2"),
(@Thorim,0,5,0,40,0,100,0,3,@Thorim,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Reached WP3 - Set Home Position"),
(@Thorim,0,6,0,8,0,100,0,56696,0,0,0,100,1,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - On Spellhit (Loken - Defeat Thorim) - Send Target List to Loken"),
(@Thorim,0,7,0,9,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Spawn - Set Invincibility hp"),
(@Thorim,0,8,0,25,0,100,0,1,1,0,0,75,54503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - On Reset - Add aura"),
(@Loken*100,9,0,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Set Run On"),
(@Loken*100,9,1,0,0,0,100,0,0,0,0,0,17,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - set stand none"),
(@Loken*100,9,2,0,0,0,100,0,2000,2000,0,0,11,56677,0,0,0,0,0,19,@Thorim,30,0,0,0,0,0,"Loken - Script - Cast Loken's Knockback"),
(@Loken*100,9,3,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,8591.518555, -610.456604, 925.558228, 5.241327,"Loken - Script - Say Line 1"),
(@Loken*100,9,5,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 1"),
(@Loken*100,9,6,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Play emote 25"),
(@Loken*100,9,7,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,8577.214844, -596.050659, 925.558289, 5.372476,"Loken - Script - Say Line 1"),
(@Loken*100,9,8,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 2"),
(@Loken*100,9,9,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 3"),
(@Loken*100,9,10,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 4"),
(@Loken*100,9,11,0,0,0,100,0,1000,1000,0,0,75,56696,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Cast Loken - Defeat Thorim"),
(@Loken*100,9,12,0,0,0,100,0,0,0,0,0,11,46846,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Cast Loken - Defeat Thorim"),
(@Loken*100,9,13,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,@CGUID+1,@Veranus,0,0,0,0,0,"Loken - Script - Set Data 1 1 to Veranus"), 
(@Loken*100,9,14,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 5"),
(@Loken*100,9,15,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Say Line 6"),
(@Loken*100,9,16,0,0,0,100,0,0,0,0,0,12,@Servant,1,60000,0,0,0,8,0,0,0,8622.837,-605.7887,926.2864,4.433136,"Loken - Script - Spawn Runeforged Servant <Servant of Loken>"),
(@Loken*100,9,17,0,0,0,100,0,0,0,0,0,12,@Servant,1,60000,0,0,0,8,0,0,0,8586.867,-564.764,925.6412,5.166174,"Loken - Script - Spawn Runeforged Servant <Servant of Loken>"),
(@Loken*100,9,18,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,21,50,0,0,0,0,0,0,"Loken - Script - Say Line 7"),
(@Loken*100,9,19,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,21,50,0,0,0,0,0,0,"Loken - Script - Say Line 8"),
(@Loken*100,9,20,0,0,0,100,0,0,0,0,0,28,46846,0,0,0,0,0,10,@CGUID,@Thorim,0,0,0,0,0,"Loken - Script - Say Line 1"),
(@Loken*100,9,21,0,0,0,100,0,5000,5000,0,0,11,56941,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loken - Script - Cast Witness the Reckoning"),
(@Loken*100,9,22,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,@CGUID+1,@Veranus,0,0,0,0,0,"Loken - Script - Set Data 2 2 to Veranus"),
(@Loken*100,9,23,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,30429,0,200,0,0,0,0,"Loken - Script - Set Data 2 2 to Runeforged Servant <Servant of Loken>"), 
(@Thorim*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set NPC Flags"),
(@Thorim*100,9,1,0,0,0,100,0,0,0,0,0,12,@Loken,1,180000,0,0,0,8,0,0,0,8564.411,-580.366,925.6412,5.5676,"Thorim - Script - Spawn Loken"),
(@Thorim*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - Script - Say Line 1"),
(@Thorim*100,9,3,0,0,0,100,0,3000,3000,0,0,53,0,@Thorim,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Start WP"),
(@Thorim*100,9,4,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 3"),
(@Thorim*100,9,5,0,0,0,100,0,2000,2000,0,0,5,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Play Emote 333"),
(@Thorim*100,9,6,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Set Data 1 1 to Loken"),
(@Thorim*100,9,7,0,0,0,100,0,6000,6000,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set Run On"),
(@Thorim*100,9,8,0,0,0,100,0,0,0,0,0,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Cast Move to Loken"),
(@Thorim*100,9,9,0,0,0,100,0,6000,6000,0,0,11,56688,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Knockback"),
(@Thorim*100,9,10,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 4"),
(@Thorim*100,9,11,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 5"),
(@Thorim*100,9,12,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 6"),
(@Thorim*100,9,13,0,0,0,100,0,1000,1000,0,0,11,56694,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Lightning Fury"),
(@Thorim*100,9,14,0,0,0,100,0,3000,3000,0,0,11,56695,0,0,0,0,0,19,@Loken,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Hammer");

DELETE FROM `spell_area` WHERE `spell`=54504 AND `area` IN(4543,4445);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(54504, 4543, 13047, 13047, 0, 0, 2, 1, 8, 11),
(54504, 4445, 13047, 13047, 0, 0, 2, 1, 8, 11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9928;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9928, 0, 0, 0, 9, 0, 13047, 0, 0, 0, 0, 0, '', 'Gossip option requires the reckoning taken');

DELETE from `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56677;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56677, 0, 31, 3, @Thorim, 0, 0, '', 'Loken''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56688;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56688, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56694;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 56694, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s Knockback');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56695;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56695, 0, 31, 3, @Loken, 0, 0, '', 'Thorim''s hammer');

DELETE FROM `creature_text` WHERE `entry` IN(@Thorim,@Loken);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(@Thorim, 0, 0, 'It is time I put an end to my brother''s madness.', 12, 0, 100, 0, 0, 0, 'Thorim', 31078),
(@Thorim, 1, 0, 'Loken!!', 14, 0, 100, 15, 0, 0, 'Thorim', 31079),
(@Thorim, 2, 0, 'Stand up and fight me, you worthless traitor!  ', 14, 0, 100, 53, 0, 0, 'Thorim', 31080),
(@Thorim, 3, 0, 'Do not dare...', 12, 0, 100, 0, 0, 0, 'Thorim', 31083),
(@Thorim, 4, 0, 'Speak...', 12, 0, 100, 0, 0, 0, 'Thorim', 31116),
(@Thorim, 5, 0, 'Her name!!', 12, 0, 100, 0, 0, 0, 'Thorim', 31117),
(@Loken, 0, 0, 'You seem eager to join your beloved Sif, brother.', 12, 0, 100, 0, 0, 0, 'Loken', 31082),
(@Loken, 1, 0, 'ENOUGH!', 14, 0, 100, 15, 0, 0, 'Loken', 31126),
(@Loken, 2, 0, 'Looks like you can still best me in a fair fight, little brother.', 12, 0, 100, 1, 0, 0, 'Loken', 31110),
(@Loken, 3, 0, 'Unfortunately for you.... this fight is anything but fair!', 12, 0, 100, 1, 0, 0, 'Loken', 31111),
(@Loken, 4, 0, 'Thanks to your little friend, you''ve left the Temple of Storms, where you were at your strongest.  Instead we fight closer to my master''s power.', 12, 0, 100, 0, 0, 0, 'Loken', 31112),
(@Loken, 5, 0, 'Minions!  Take my brother and his drake to their new dwellings.  Make sure the beast makes it alive.  I have special plans for the broodmother.', 12, 0, 100, 0, 0, 0, 'Loken', 31128),
(@Loken, 6, 0, 'As for your life, mortal.  I will be generous.  After all... why would I destroy my most useful servant?  I waited for you for weeks inside that Hyldnir mine.', 12, 0, 100, 0, 0, 0, 'Loken', 31127),
(@Loken, 7, 0, 'The shape wasn''t mine, of course.  And had you not been so reckless, you would''ve seen past my illusion.  But you came through for me, and for that... I must thank you!', 12, 0, 100, 0, 0, 0, 'Loken', 31133);

DELETE FROM `creature_template_addon` WHERE `entry` IN(@Thorim,@Loken,@Veranus);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@Thorim, 0, 0x10000, 0x1, '54503'), -- 30399 - 54503
(@Loken, 0, 0x1, 0x1, ''), -- 30396
(@Veranus, 0, 0x3010000, 0x1, '54503'); -- 30420 - 54503

DELETE FROM `creature` WHERE `id` IN(@Thorim,@Veranus);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @Thorim, 571, 1, 1,  8703.806, -714.0443, 934.9764, 2.321288, 120, 0, 0), -- 30399 (Area: 67)
(@CGUID+1, @Veranus, 571, 1, 1,  8711.395, -754.7941, 955.1224, 2.338741, 120, 0, 0); -- 30420 (Area: 67)

DELETE FROM `gossip_menu` WHERE `entry`=9928;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(9928, 13800); -- 30399

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9928;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9928, 0, 0, 'I''m with you, Thorim.', 0, 1, 1, 0, 0, 0, 0, '', 31225);

DELETE FROM `waypoints` WHERE `entry` IN(@Thorim);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Thorim, 1,8695.301, -703.0229, 933.7817, 'Thorim'),
(@Thorim, 2,8665.801, -675.7729, 927.5317, 'Thorim'),
(@Thorim, 3,8573.930664, -591.286133, 925.558167 , 'Thorim');

UPDATE creature_template SET InhabitType=4 WHERE entry IN (29747, 29790);
