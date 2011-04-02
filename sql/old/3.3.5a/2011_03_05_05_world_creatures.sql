-- Dalaran Violet Citadel/Purple Parlor - npc scripts
SET @CGuid = 151893; -- Set by TDB team

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32739; -- Baroness Zildjia
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32736; -- Scribe Whitman
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32741; -- Conjurer Weinhaus
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=32631; -- Alfred Copperworth
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32734; -- Arcanist Ginsberg
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32735; -- Alchemist Burroughs

DELETE FROM `creature` WHERE `id`=32741; -- Conjurer Weinhaus
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGuid+0,32741,571,1,1,0,0,5871.94,852.655,846.336,6.21344,300,0,0,1,0,0,0,0,0,0);
DELETE FROM `creature_template_addon` WHERE `entry` IN (31848,32287,32739,32736,32631,32737,32734,32735);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31848,0,0,1,0, NULL), -- Zidormi
(32287,0,0,257,0, NULL), -- Archmage Alvareaux
(32739,0,0,257,0, NULL), -- Baroness Zildjia
(32736,0,0,257,0, NULL), -- Scribe Whitman
(32631,0,0,1,0, NULL), -- Alfred Copperworth
(32737,0,0,257,0, NULL), -- Archmage John Nicholas
(32734,0,0,257,0, NULL), -- Arcanist Ginsberg
(32735,0,0,257,0, NULL); -- Alchemist Burroughs
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1,`gender`=1 WHERE `modelid`=27756; -- Zidormi
UPDATE `creature_model_info` SET `bounding_radius`=0.3672,`combat_reach`=1,`gender`=0 WHERE `modelid`=27886; -- Archmage Alvareaux
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1,`gender`=1 WHERE `modelid`=28176; -- Baroness Zildjia
UPDATE `creature_model_info` SET `bounding_radius`=0.3519,`combat_reach`=1,`gender`=0 WHERE `modelid`=28179; -- Scribe Whitman
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=28119; -- Alfred Copperworth
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1,`gender`=0 WHERE `modelid`=28174; -- Archmage John Nicholas
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=28173; -- Arcanist Ginsberg
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=28172; -- Alchemist Burroughs
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=19284; -- Archmage Vargoth

-- Add teleport to gossip option "Teleport me to Caverns of Time." - Zidormi
UPDATE `gossip_menu_option` SET `action_script_id`=10131 WHERE `menu_id`=10131 AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=10131;
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(10131,0,6,1,0,0,-8167.24,-4766.05,33.8599,1.74123);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10131 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10131,0,0,27,65,3,0,0, '', 'Zidormi - Teleport to CoT level restriction'); -- Zidormi

-- Talk events for Baroness Zildjia, Scribe Whitman and Conjurer Weinhaus
DELETE FROM `creature_text` WHERE `entry` IN (32739,32736,32741) AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(32739,0,0, 'The view up here is amazing!',0,0,0,5,0,0, 'Baroness Zildjia'), -- Baroness Zildjia
(32739,0,1, 'Too bad I left my light feathers at home... Slow Fall would work perfect here!',0,0,0,1,0,0, 'Baroness Zildjia'), -- Baroness Zildjia
(32736,0,0, 'The view up here is amazing!',0,0,0,5,0,0, 'Scribe Whitman'), -- Scribe Whitman
(32736,0,1, 'Too bad I left my light feathers at home... Slow Fall would work perfect here!',0,0,0,1,0,0, 'Scribe Whitman'), -- Scribe Whitman
(32741,0,0, 'The view up here is amazing!',0,0,0,5,0,0, 'Conjurer Weinhaus'), -- Conjurer Weinhaus
(32741,0,1, 'Too bad I left my light feathers at home... Slow Fall would work perfect here!',0,0,0,1,0,0, 'Conjurer Weinhaus'); -- Conjurer Weinhaus
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32739,32736,32741,32734,32735) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32739,0,0,0,1,0,100,0,0,0,420000,1000000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baroness Zildjia: Say rand text every 7-14 minutes'), -- Baroness Zildjia
(32736,0,0,0,1,0,100,0,0,0,300000,840000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scribe Whitman: Say rand text every 5-14 minutes'), -- Scribe Whitman
(32741,0,0,0,1,0,100,0,0,0,400000,520000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Conjurer Weinhaus: Say rand text every 5-7 minutes'), -- Conjurer Weinhaus
(32734,0,0,0,1,0,100,0,0,0,5000,30000,10,274,1,11,0,0,0,1,0,0,0,0,0,0,0, 'Arcanist Ginsberg: Random emote every 5-30 seconds'), -- Arcanist Ginsberg
(32735,0,0,0,1,0,100,0,0,0,5000,30000,10,274,1,11,0,0,0,1,0,0,0,0,0,0,0, 'Alchemist Burroughs: Random emote every 5-30 seconds'); -- Alchemist Burroughs
