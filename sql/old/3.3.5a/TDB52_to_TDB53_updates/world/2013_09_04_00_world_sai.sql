-- Putting Olakin Back Together Again (13220)
SET @QUEST               := 13220;
SET @NPC_OLAKIN          := 31235;  -- Crusader Olakin Sainrith
SET @GO_CLEAVER          := 193092; -- The Doctor's Cleaver
SET @GO_SPOOL            := 193091; -- Spool of Thread
SET @EVENT_SCRIPT        := 20269;  -- Event from 58856 Reanimate Crusader Olakin
SET @SPELL_FD            := 35356;  -- Feign Death
SET @SPELL_FAKE_BLOOD    := 37692;  -- Fake Blood Spurt
SET @SPELL_RESURRECTION  := 58854;  -- Resurrection

DELETE FROM `gameobject` WHERE `id` IN (@GO_CLEAVER,@GO_SPOOL);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(16974,@GO_SPOOL,571,1,1,6668.17,3268.54,669.539,2.54818,0,0,0.956304,0.292373,120,255, 1),
(16976,@GO_CLEAVER,571,1,1,6601.1,3147.78,666.916,-2.77507,0,0,-0.983254,0.182238,120,255,1);

DELETE FROM `event_scripts` WHERE `id`=@EVENT_SCRIPT;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT_SCRIPT,0,10,@NPC_OLAKIN,60000,0,6636.792,3211.102,668.6439,0.8901179);

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_OLAKIN;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_OLAKIN,0,0x0,0x1,'35356'); -- 31235 - 35356

DELETE FROM `creature_text` WHERE `entry`=@NPC_OLAKIN;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_OLAKIN,0,0,'Thank the Light for granting me another chance. And thank you, $N.',12,0,100,1,0,0,'Crusader Olakin Sainrith'),
(@NPC_OLAKIN,1,0,'Without your help, I would''ve been doomed to a life of undeath among the Lich King''s gruesome creations.', 12,0,100,1,0,0,'Crusader Olakin Sainrith'),
(@NPC_OLAKIN,2,0,'There will be time for a proper thanks later, but there is still a battle to be fought!', 12,0,100,25,0,0,'Crusader Olakin Sainrith');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_OLAKIN;
DELETE FROM `smart_scripts` WHERE (`source_type`=0 AND `entryorguid`=@NPC_OLAKIN) OR (`source_type`=9 AND `entryorguid`=@NPC_OLAKIN*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_OLAKIN,0,0,0,54,0,100,0,0,0,0,0,80,@NPC_OLAKIN*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Just summoned - Run Script'),
(@NPC_OLAKIN,0,1,0,40,0,100,0,3,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On WP Reached - Despawn'),
-- 17,26
(@NPC_OLAKIN*100,9,0,0,0,0,100,0,2000,2000,0,0,11,@SPELL_FAKE_BLOOD,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Cast Spell'),
(@NPC_OLAKIN*100,9,1,0,0,0,100,0,2000,2000,0,0,11,@SPELL_RESURRECTION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Cast Spell'),
(@NPC_OLAKIN*100,9,2,0,0,0,100,0,0,0,0,0,28,@SPELL_FD,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Remove Aura'),
(@NPC_OLAKIN*100,9,3,0,0,0,100,0,0,0,0,0,96,32,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Remove dynamic flag'),
(@NPC_OLAKIN*100,9,4,0,0,0,100,0,1000,1000,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Remove Unit Flag_2 1 {dead)'),
(@NPC_OLAKIN*100,9,5,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Say 0'),
(@NPC_OLAKIN*100,9,6,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Say 1'),
(@NPC_OLAKIN*100,9,7,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Say 2'),
(@NPC_OLAKIN*100,9,8,0,0,0,100,0,3000,3000,0,0,33,@NPC_OLAKIN,0,0,0,0,0,17,0,30,0,0,0,0,0,'Crusader Olakin Sainrith - On Script - Quest Credit'),
(@NPC_OLAKIN*100,9,9,0,0,0,100,0,0,0,0,0,53,1,@NPC_OLAKIN,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Script -Start WP movement');

DELETE FROM `waypoints` WHERE entry =@NPC_OLAKIN;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@NPC_OLAKIN, 1, 6632.227, 3223.6350, 666.7750,'Olakin'),
(@NPC_OLAKIN, 2, 6624.2558, 3230.2343, 666.857, 'Olakin'),
(@NPC_OLAKIN, 3, 6608.985, 3234.5588, 668.779, 'Olakin');

