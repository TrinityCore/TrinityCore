DELETE FROM `creature_ai_scripts` WHERE  `creature_id` IN (27355,27450);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(27355,27449,27450) AND `source_type`=0;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry IN(27355,27449,27450);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27450,0,0,1,8,0,100,0,48790,0,0,0,33,27450,0,0,0,0,0,7,0,0,0,0,0,0,0,'Neltharions Flame Control Bunny - On Spellhit (Neltharions Flame) - Give Kill Credit'),
(27450,0,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,27449,0,200,0,0,0,0, 'Neltharions Flame Control Bunny - Linked with Previous Event - Set Data 1 1 on Neltharions Flame Fire Bunny'),
(27450,0,2,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,27355,0,200,0,0,0,0, 'Neltharions Flame Control Bunny - Linked with Previous Event - Set Data 1 1 on Rothin the Decaying'),
(27449,0,0,1,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Neltharions Flame Fire Bunny - On Data set 1 1 - Set Data 1 0 on self'),
(27449,0,1,0,61,0,100,0,0,0,0,0,11,48786,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Neltharions Flame Fire Bunny - Linked with Previous Event - Cast Neltharions Flame Fire Bunny: Periodic Fire Aura'),
(27355,0,0,1,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Reset - Disable Combat Movement'),
(27355,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Set Phase 0'),
(27355,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Agro - Cast Shadowbolt'),
(27355,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Set Phase 1'),
(27355,0,4,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - On Range (Phase 1) - Cast Shadow Bolt'),
(27355,0,5,6,3,1,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Less than 7% Mana - Allow Combat Movement'),
(27355,0,6,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Set Phase 2'),
(27355,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Target More than 35 Yards away - Allow Combat Movement'),
(27355,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Target less than 15 Yards away - Disable Combat Movement'),
(27355,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Target less than 5 Yards away - Allow Combat Movement'),
(27355,0,10,0,3,3,100,0,15,100,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On More than 15% Mana - Set Phase 1'),
(27355,0,11,0,0,0,100,0,12000,17000,15000,20000,11,51337,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - IC - On Range (Phase 1) - Cast Shadow Flame'),
(27355,0,12,0,2,0,100,1,0,30,9500,11000,11,51512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Less than 30% HP - Cast Aegis of Neltharion'),
(27355,0,13,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Evade - Set Phase 0'),
(27355,0,14,0,25,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Reset/Spawn - Disable Combat'),
(27355,0,15,16,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Data set 1 1 - Set Data 1 0 on self'),
(27355,0,16,17,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Enable Combat'),
(27355,0,17,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Say'),
(27355,0,18,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Agro - Say'),
(27355,0,19,0,6,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying <Cult of the Damned> - On Death - Say');

DELETE FROM `creature_text` WHERE `entry`=27355;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27355,0,0,'No... NO! What have you done?! So many ancient wyrms wasted... what magic could do this?',14,0,100,1,0,0,'Rothin the Decaying <Cult of the Damned>'),
(27355,1,0,'Foolish errand $g boy:girl; ... you will die for interrupting my work!',14,0,100,1,0,0,'Rothin the Decaying <Cult of the Damned>'),
(27355,2,0,'This is not the end... death only... strengthens...',14,0,100,1,0,0,'Rothin the Decaying <Cult of the Damned>');
