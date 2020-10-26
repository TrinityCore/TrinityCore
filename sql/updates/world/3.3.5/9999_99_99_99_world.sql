-- Into the Realm of Shadows
UPDATE `creature_template` SET `AIName`='SmartAI', `Scriptname`='' WHERE `entry`=28768;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28768 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28768,0,0,0,0,0,100,0,5000,8000,8000,11000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rider of Acherus - In Combat - Cast 'Blood Strike'"),
(28768,0,1,0,0,0,100,0,4000,7000,7000,10000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rider of Acherus - In Combat - Cast 'Plague Strike'"),
(28768,0,2,0,0,0,100,0,3000,6000,6000,9000,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rider of Acherus - In Combat - Cast 'Icy Touch'"),
(28768,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,28782,5,0,0,0,0,0,"Dark Rider of Acherus - On Death - Set Data 1 1");

UPDATE `creature_template` SET `AIName`='SmartAI', `Scriptname`='' WHERE `entry`=28782;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28782 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2878200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28782,0,0,1,25,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - On Reset - Set Aggressive"),
(28782,0,1,2,61,0,100,0,0,0,0,0,2,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - On Reset - Set Faction"),
(28782,0,2,0,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - On Reset - Add Flag"),
(28782,0,3,0,38,0,100,0,1,1,0,0,80,2878200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - On Data 1 1 Set - Action List"),
(2878200,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Set Passive"),
(2878200,9,1,0,0,0,100,0,0,0,0,0,2,2082,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Set Faction"),
(2878200,9,2,0,0,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Remove Flag"),
(2878200,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Say Line 0"),
(2878200,9,4,0,0,0,100,0,30000,30000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=28782;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28782,0,0,"%s rears up, beckoning you to ride it.",16,0,100,0,0,0,29069,0,"Acherus Deathcharger");

UPDATE `npc_spellclick_spells` SET `spell_id`=46598 WHERE `npc_entry`=28782;

