-- NPC talk text insert from sniff
DELETE FROM `script_texts` WHERE `npc_entry`=28546;
DELETE FROM `creature_text` WHERE `entry`=28546;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28546,0,0, 'You wish to confront the master? You must first weather the storm!',14,0,100,0,0,14453, 'Ionar'),
(28546,1,0, 'The slightest spark shall be your undoing.',14,0,100,0,0,14454, 'Ionar'),
(28546,1,1, 'No one is safe!',14,0,100,0,0,14455, 'Ionar'),
(28546,2,0, 'Shocking ... I know!',14,0,100,0,0,14456, 'Ionar'),
(28546,2,1, 'You atempt the unpossible.',14,0,100,0,0,14457, 'Ionar'),
(28546,2,2, 'Your spark of light is ... extinguish.',14,0,100,0,0,14458, 'Ionar'),
(28546,3,0, 'Master... you have guests.',14,0,100,0,0,14459, 'Ionar');
