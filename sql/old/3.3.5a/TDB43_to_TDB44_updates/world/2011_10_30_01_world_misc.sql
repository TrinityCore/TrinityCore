-- spell target position
DELETE FROM `spell_target_position` WHERE `id`=60905;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(60905, 571, 6435, 2366.9, 465.7, 0); -- Portal Effect: Naz'anak Exit

-- templates
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=193991; -- Altar of the Ebon Depths
UPDATE `gameobject_template` SET `flags`=0,`AIName`='SmartGameObjectAI' WHERE `entry`=193195; -- Pulsing Crystal
UPDATE `creature_template` SET `AIName`='SmartAI',`lootid`=`entry` WHERE `entry`=31691; -- Faceless Lurker
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=31237; -- Matthias Lehner

-- addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (31691,31237);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31691,0,0,1,0, NULL), -- Faceless Lurker
(31237,0,0,1,0, '10848'); -- Matthias Lehner (Shroud of Death)

-- model info
UPDATE `creature_model_info` SET `bounding_radius`=1.3,`combat_reach`=1.3,`gender`=0 WHERE `modelid`=27522; -- Matthias Lehner

-- scripts
DELETE FROM `smart_scripts` WHERE `entryorguid`=31691 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31237 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=193195 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31691,0,0,0,0,0,100,1,0,0,0,0,11,52342,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Faceless Lurker - On aggro cast Seething Evil'),
(193195,1,0,0,19,0,100,0,13390,0,0,0,45,1,1,0,0,0,0,10,203360,31237,0,0,0,0,0, 'Pulsing Crystal - On A Voice in the Dark (A) quest accept set data to Matthias Lehner'),
(193195,1,1,0,19,0,100,0,13271,0,0,0,45,1,1,0,0,0,0,10,203360,31237,0,0,0,0,0, 'Pulsing Crystal - On A Voice in the Dark (H) quest accept set data to Matthias Lehner'),
(31237,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,21,60,0,0,0,0,0,0, 'Matthias Lehner - On data set (quest accepted at Pulsing Crystal) say text 0');
DELETE FROM `creature_text` WHERE `entry`=31237;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(31237,0,0, 'You shouldn''t have done that!  He''s not going to like it.',15,0,100,0,0,0, 'Matthias Lehner - On quest accept');

-- loot
-- WTB ZxBiohazardZx to do lootz
DELETE FROM `creature_loot_template` WHERE `entry`=31691;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(31691,45912,0.1,1,0,1,1), -- Book of Glyph Mastery
(31691,44001,-60,1,0,1,1), -- Faceless One's Blood
(31691,35063,100,1,0,-35063,1), -- trash
(31691,26041,100,1,0,-26041,1); -- frostweave

-- Link some mobs on HoS with Krystallus (by Aokromes) (unrelated)
DELETE FROM `linked_respawn` WHERE `linkedGuid`=126792 AND `guid` IN (126710,126691,126702,126708,126743);
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`) VALUES
(126710,126792),
(126691,126792),
(126702,126792),
(126708,126792),
(126743,126792);

-- correct db errors recently found
UPDATE `smart_scripts` SET `target_param1`=40 WHERE `entryorguid`=1435404 AND `source_type`=9 AND `id`=10 AND `link`=0;
UPDATE `smart_scripts` SET `target_param1`=40 WHERE `entryorguid`=1905500 AND `source_type`=9 AND `id`=03 AND `link`=0;
