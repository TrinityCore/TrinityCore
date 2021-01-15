-- 10913 An Improper Burial

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id` IN(21859,21846,21869);

UPDATE creature_template SET AIName='SmartAI' WHERE entry IN(21859,21846,21869);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(21859,21846,21869) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21859,0,0,1,8,0,100,1,39189,0,0,0,11,59216,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slain Sha tar Vindicator - On Spellhit (Sha tari Torch) - Cast Burning Corpse'),
(21859,0,1,2,61,0,100,0,0,0,0,0,33,21859,0,0,0,0,0,7,0,0,0,0,0,0,0,'Slain Sha tar Vindicator - Linked with Previous Event - Give Kill Credit'),
(21859,0,2,3,61,0,100,0,0,0,0,0,11,37759,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Slain Sha tar Vindicator - Linked with Previous Event - Cast Bone Wastes - Summon Draenei Guardian Spirit'),
(21859,0,3,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slain Sha tar Vindicator - Linked with Previous Event - Despawn after 15 seconds'),
(21846,0,0,1,8,0,100,1,39189,0,0,0,11,59216,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slain Auchenai Warrior - On Spellhit (Sha tari Torch) - Cast Burning Corpse'),
(21846,0,1,2,61,0,100,0,0,0,0,0,33,21846,0,0,0,0,0,7,0,0,0,0,0,0,0,'Slain Auchenai Warrior - Linked with Previous Event - Give Kill Credit'),
(21846,0,2,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slain Auchenai Warrior - Linked with Previous Event - Despawn after 15 seconds'),
(21869,0,0,1,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Unliving Guardian - Link - Set Rendom Move'),
(21869,0,1,0,61,0,100,0,0,0,0,0,41,300000,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,'Unliving Guardian - On Spawn - Force Despawn 5 min');

DELETE FROM `creature_template_addon` WHERE  `entry`=21869;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(21869, 0, 0, 0, 4097, 0, '17327');
