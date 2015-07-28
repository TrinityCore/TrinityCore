UPDATE `creature_template` SET `AIname`='SmartAI' WHERE `entry`=28389;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28389 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28389,0,0,0,8,0,100,0,51592,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Primordial Hatchling - On Spel Hit(Pickup Primordial Hatchling) - Despawn');
-- Creature_AI to Smart_AI Conversion for Primordial Drake Egg (ID 28408) and loot fix for Primordial Hatchling (ID 28389)
UPDATE `creature_template` SET `AIName`= 'SmartAI',`flags_extra`=`flags_extra`|2 WHERE `entry`  =28408;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` =28408;
-- Smart AI conversion for Primordial Egg creature ai scripts, also prevents these eggs from moving/auto attacking
DELETE FROM `smart_scripts` WHERE `entryorguid`  =28408;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28408,0,0,1,25,0,100,0,0,0, 0, 0, 21 ,0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Primordial Drake Egg - On Spawn - Prevent Combat Movement"),
(28408,0,1,0,61,0,100,0,0,0, 0, 0, 20 ,0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Primordial Drake Egg - Linked with Previous Event - Disable Combat"),
(28408,0,2,0,6 ,0,100,0,0,0, 0, 0, 11 ,51595, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Primordial Drake Egg - On Death - Cast Summon Primordial Hatchling");
-- Remove Borean Leather, Icy Dragonscale and Book of Glyph Mastery from Primordial Hatchling as these are not meant to drop from these
DELETE FROM `creature_loot_template` WHERE `entry`=28389 AND `item` IN (33568,38557,45912);
