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
(2878200,9,0,0,0,0,100,0,500,500,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Set Passive"),
(2878200,9,1,0,0,0,100,0,0,0,0,0,2,2082,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Set Faction"),
(2878200,9,2,0,0,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Remove Flag"),
(2878200,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Say Line 0"),
(2878200,9,4,0,0,0,100,0,20000,20000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Deathcharger - Action List - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (28782,28788);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28782,0,0,"%s rears up, beckoning you to ride it.",16,0,100,0,0,0,29069,0,"Acherus Deathcharger"),
(28788,0,0,"Impressive, death knight. Return to me in the world of the living for your reward.",12,0,100,2,0,0,28835,0,"Salanar the Horseman");

UPDATE `creature_template` SET `unit_flags`=32768,`AIName`='SmartAI', `Scriptname`='' WHERE `entry`=28788;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28788 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2878800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28788,0,0,0,54,0,100,0,0,0,0,0,80,2878800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salanar the Horseman - On Just Spawned - Action List"),
(2878800,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Set Orientation"),
(2878800,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Set Walk"),
(2878800,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Say Line 0"),
(2878800,9,3,0,0,0,100,0,5000,5000,0,0,11,52361,0,0,0,0,0,23,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Cast 'Death Race Complete'"),
(2878800,9,4,0,0,0,100,0,0,0,0,0,28,52693,0,0,0,0,0,23,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Remove Aura"),
(2878800,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salanar the Horseman - Action List - Despawn");

UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=28653;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28782;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(28782,46598,1,0),
(28782,52349,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=28782;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=52349;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,28782,46598,0,0,31,0,3,0,0,0,0,0,'','Allow spellclick for NPC'),
(18,28782,52349,0,0,9,0,12687,0,0,0,0,0,'','Requires quest \'Into the Realm of Shadows\' active for spellclick'),
(13,1,52349,0,0,31,0,3,28782,0,0,0,0,'','Target Acherus Deathcharger');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_death_race_complete';
INSERT INTO `spell_script_names` VALUES (52361,'spell_death_race_complete');
