-- SAI for Lord Thorval speech to deciples
SET @ENTRY = 29196;
UPDATE `creature_template` SET AIName = 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,600000,600000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - OOC - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 0'),
(@ENTRY*100,9,1,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 1'),
(@ENTRY*100,9,2,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 2'),
(@ENTRY*100,9,3,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 3'),
(@ENTRY*100,9,4,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 4'),
(@ENTRY*100,9,5,0,0,0,100,0,8000,8000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 5'),
(@ENTRY*100,9,6,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 6'),
(@ENTRY*100,9,7,0,0,0,100,0,8000,8000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 7'),
(@ENTRY*100,9,8,0,0,0,100,0,7000,7000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Thorval - Script - Say 8');
-- Creature text for Lord Thorval
DELETE FROM creature_ai_texts WHERE entry BETWEEN -735 AND -727;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'As disciples of blood, you strive to master the very lifeforce of your enemies.',                                       12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 1 of Speech To Deciples)'),
(@ENTRY, 1, 0, 'Be it by blade or incantation, blood feeds our attacks and weakens our foes.',                                          12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 2 of Speech To Deciples)'),
(@ENTRY, 2, 0, 'True masters learn to make blood serve more than just their strength in battle.',                                       12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 3 of Speech To Deciples)'),
(@ENTRY, 3, 0, 'Stripping energy from our foes, both fighting and fallen, allows us to persevere where lesser beigns falls exhausted.', 12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 4 of Speech To Deciples)'),
(@ENTRY, 4, 0, 'And every foe that falls, energy sapped and stolen, only further fuels our assault.',                                   12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 5 of Speech To Deciples)'),
(@ENTRY, 5, 0, 'As masters of blood, we know battle without end...',                                                                    12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 6 of Speech To Deciples)'),
(@ENTRY, 6, 0, 'We know hunger never to be quenched...',                                                                                12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 7 of Speech To Deciples)'),
(@ENTRY, 7, 0, 'We know power never to be overcome...',                                                                                 12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 8 of Speech To Deciples)'),
(@ENTRY, 8, 0, 'As masters of blood, we are masters of life and death itself. Agains us, even hope falls drained and lifeless.',        12, 0, 100, 1, 0, 0, 'Lord Thorval - (Part 9 of Speech To Deciples)');

-- Remove some EAI already converted to cpp
DELETE FROM creature_ai_scripts WHERE creature_id IN (25040,26499,30663,30918,32273);
UPDATE creature_template SET AIName = '' WHERE entry IN (25040,26499,30663,30918,32273);
