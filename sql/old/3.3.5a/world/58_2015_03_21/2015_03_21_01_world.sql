SET @CGUID := 69713; -- 4 free guid set by TC
SET @OGUID := 6144; -- 2 free guid set by TC

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 21318, 530, 1, 1, -3800.380, 2601.100, 90.14300, 5.481630, 180, 6986, 0, 0),
(@CGUID+1, 21310, 530, 1, 1, -3802.939, 2594.501, 92.709, 1.605702, 300, 6986, 0, 0),
(@CGUID+2, 21310, 530, 1, 1, -3794.054, 2588.724, 92.709, 1.905461, 300, 6986, 0, 0),
(@CGUID+3, 21310, 530, 1, 1, -3788.540, 2597.479, 92.709, 3.382006, 300, 6986, 0, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 184731, 530, 1, 1, -3802.939, 2594.501, 92.18282, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- 184731 (Area: -1)
(@OGUID+1, 184731, 530, 1, 1, -3794.054, 2588.724, 92.18282, 1.905461, 0, 0, 0, 1, 120, 255, 1); -- 184731 (Area: -1)

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (21310, 21309);
UPDATE `creature_template` SET `InhabitType`=4, `gossip_menu_id`=8287, `AIName`='SmartAI' WHERE `entry`=21292;
UPDATE `creature_template` SET `gossip_menu_id`=8288, `AIName`='SmartAI' WHERE `entry`=21318;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID+1, -@CGUID+2, -@CGUID+3, -74618, 21318, 21292, 21309);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-74618,0,0,0,1,0,100,1,0,0,0,0,11,36558,0,0,0,0,0,19,21292,30,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - OOC no repeat - Cast Ar''tor''s Prison'),
(-@CGUID+1,0,0,0,1,0,100,1,0,0,0,0,11,36558,0,0,0,0,0,19,21292,30,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - OOC no repeat - Cast Ar''tor''s Prison'),
(-@CGUID+2,0,0,0,1,0,100,1,0,0,0,0,11,36558,0,0,0,0,0,19,21292,30,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - OOC no repeat - Cast Ar''tor''s Prison'),
(-@CGUID+3,0,0,0,1,0,100,1,0,0,0,0,11,36558,0,0,0,0,0,19,21292,30,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - OOC no repeat - Cast Ar''tor''s Prison'),
(21292,0,0,0,20,0,100,0,10528,0,0,0,45,0,1,0,0,0,0,19,21318,20,0,0,0,0,0, 'Ar''tor, Son of Oronok - -On quest Rewarded - Set Data'),
(21318,0,0,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,21,30,0,0,0,0,0,0, 'Spirit of Ar''tor -On Data set - Talk'),
(21309,0,0,0,0,0,100,0,5000,7000,20000,25000,11,38048,0,0,0,0,0,2,0,0,0,0,0,0,0,"Painmistress Gabrissa - In Combat - Cast 'Curse of Pain'"),
(21309,0,1,0,0,0,100,0,6000,7000,17000,20000,11,38169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Painmistress Gabrissa - In Combat - Cast 'Curse of Pain'"),
(21309,0,2,0,25,0,100,0,0,0,0,0,11,32783,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmistress Gabrissa - On reset - Cast 'Arcane Channeling'");

DELETE FROM `creature_text` WHERE `entry`=21318;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(21318,0,0,'I... I have died... I was in so much pain... engulfed in darkness... Can you see me, $r?',12,0,100,0,0,0, 'Spirit of Ar''tor ', 18993);

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+1, @CGUID+2, @CGUID+3, 74618);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(@CGUID+1,0,4097,0,"60194"),
(@CGUID+2,0,4097,0,"60194"),
(@CGUID+3,0,4097,0,"60194"),
(74618,0,4097,0,"60194");

DELETE FROM `creature_template_addon` WHERE `entry` IN (21307, 21292);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(21292,0,4097,383,""),
(21307,0,4097,0,"31261");

DELETE FROM `gossip_menu` WHERE `entry`=8288 AND `text_id`=10327;
DELETE FROM `gossip_menu` WHERE `entry`=8287 AND `text_id`=10323;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8287, 10323),
(8288, 10327);

DELETE FROM `spell_area` WHERE `spell`=60197 AND `area`=3752;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(60197, 3752, 10528, 0, 0, 0, 2, 1, 64, 0);

DELETE FROM `spell_area` WHERE `spell`=60194 AND `area`=3752;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(60194, 3752, 0, 10528, 0, 0, 2, 1, 0, 11);
