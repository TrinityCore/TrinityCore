-- 
UPDATE `creature_template_addon` SET `auras`=""  WHERE `entry` IN (38451,35008,35602,28951,35642);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (35008,35602,28951);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35008,35602,28951,35642) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35008,0,0,0,23,0,100,0,12550,0,3000,3000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sawemba- On missing aura - Cast 'Frost Armor'"),
(35008,0,1,0,0,0,100,0,1000,2000,3000,4000,0,11,20692,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sawemba - IC - Cast Fireball"),
(35008,0,2,0,0,0,100,0,4000,6000,6000,8000,0,11,38534,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sawemba - IC - Cast Frostbolt"),
(35008,0,3,0,0,0,100,0,8000,12000,15000,20000,0,11,38896,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sawemba - IC - Cast Polymorph"),
(35602,0,0,0,23,0,100,0,12550,0,3000,3000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Savarin - On missing aura - Cast 'Frost Armor'"),
(35602,0,1,0,0,0,100,0,1000,2000,3000,4000,0,11,20692,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Savarin - IC - Cast Fireball"),
(35602,0,2,0,0,0,100,0,4000,6000,6000,8000,0,11,38534,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Savarin - IC - Cast Frostbolt"),
(35602,0,3,0,0,0,100,0,8000,12000,15000,20000,0,11,38896,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Savarin - IC - Cast Polymorph"),
(28951,0,0,0,10,0,100,0,1,5,30000,120000,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Breanni - Ooc los - Say text"),
(35642,0,0,0,54,0,100,0,0,0,0,0,0,11,68054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jeeves - On just summoned - Cast Pressing Engagement");

DELETE FROM `creature_text` WHERE `CreatureID` IN (28951);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(28951, 0, 0, "Welcome!", 12, 0, 100, 0, 0, 0, 'Breanni', 32807),
(28951, 0, 1, "Greetings, $c.", 12, 0, 100, 0, 0, 0, 'Breanni', 32808),
(28951, 0, 2, "Greetings! Please have a look around.", 12, 0, 100, 0, 0, 0, 'Breanni', 32809),
(28951, 0, 3, "Let me know if you need help finding anything, $c.", 12, 0, 100, 0, 0, 0, 'Breanni', 32810),
(28951, 0, 4, "Welcome. May I help you find something?", 12, 0, 100, 0, 0, 0, 'Breanni', 32811);

DELETE FROM `spell_scripts` WHERE `id` IN (68052);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(68052,0,0,0,0,0,35977,0,0,0,0),
(68052,0,0,18,4000,0,0,0,0,0,0);
