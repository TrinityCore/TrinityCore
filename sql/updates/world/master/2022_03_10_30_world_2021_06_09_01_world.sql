-- Apply mentioned earlier restrictions to previously updated quests
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (17680,22355,28413,24210) AND `SourceId` = 0 AND `ConditionTypeOrReference` = 32;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,17680,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if invoker is player"),
(22,3,17680,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is player"),
(22,2,22355,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if invoker is player"),
(22,3,22355,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is player"),
(22,3,28413,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is player"),
(22,4,28413,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if invoker is player"),
(22,3,24210,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is player"),
(22,4,24210,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if invoker is player");

DELETE FROM `spell_script_names` WHERE
(`spell_id` = 45516 AND `ScriptName` = "spell_nerubar_web_random_unit_not_on_quest") OR
(`spell_id` = 45515 AND `ScriptName` = "spell_nerubar_web_random_unit_not_on_quest_dummy") OR
(`spell_id` = 45535 AND `ScriptName` = "spell_nerubar_web_random_unit_on_quest_dummy") OR
(`spell_id` = 45522 AND `ScriptName` = "spell_dispel_freed_soldier_debuff");
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45516,"spell_nerubar_web_random_unit_not_on_quest"),
(45515,"spell_nerubar_web_random_unit_not_on_quest_dummy"),
(45535,"spell_nerubar_web_random_unit_on_quest_dummy"),
(45522,"spell_dispel_freed_soldier_debuff");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 25284;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25284 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25284,0,0,0,37,0,100,0,0,0,0,0,0,116,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nerub'ar Victim - On AI Initialize - Set Corpse Delay"),
(25284,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nerub'ar Victim - On AI Initialize - Set Reactstate Passive"),
(25284,0,2,0,6,0,100,0,0,0,0,0,0,11,45516,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Victim - On Death - Cast 'Nerub'ar Web Random Unit'"),
(25284,0,3,0,6,0,100,0,0,0,0,0,0,11,45534,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Victim - On Death - Cast 'Nerub'ar Web Random Unit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 25284 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,25284,0,0,9,0,11611,0,0,1,0,0,"","Group 0: Execute SAI (Action 2) if quest 'Taken by the Scourge' is not taken by invoker"),
(22,4,25284,0,0,9,0,11611,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if quest 'Taken by the Scourge' is taken by invoker"),
(22,3,25284,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is player"),
(22,4,25284,0,0,32,0,16,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if invoker is player");

-- Peon
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25270;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25270 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2527000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25270,0,0,0,54,0,100,0,0,0,0,0,0,80,2527000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Peon - On Just Summoned - Run Script"),

(2527000,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Peon - On Script - Set Orientation Owner"),
(2527000,9,1,0,0,0,100,0,0,0,0,0,0,33,25270,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Peon - On Script - Quest Credit 'Taken by the Scourge'"),
(2527000,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Peon - On Script - Say Line 0"),
(2527000,9,3,0,0,0,100,0,2000,2000,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Peon - On Script - Start Follow Owner"),
(2527000,9,4,0,0,0,100,0,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Peon - On Script - Delayed Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = 25270;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25270,0,0,"Huh? Where me at? Dis don't look good! Me run now!",12,1,100,5,0,0,24626,0,"Warsong Peon"),
(25270,0,1,"HOORAY! ME FREE!",12,1,100,5,0,0,24627,0,"Warsong Peon"),
(25270,0,2,"Tanks, buddy!",12,1,100,5,0,0,24628,0,"Warsong Peon"),
(25270,0,3,"Mister Mortuus gonna be so mad! Me go home now.",12,1,100,5,0,0,24629,0,"Warsong Peon"),
(25270,0,4,"Why it keep telling me to put da lotion in da basket? Me no like da lotion!",12,1,100,5,0,0,24630,0,"Warsong Peon");

-- Soldiers
UPDATE `creature_template` SET `unit_flags` = 32768, `AIName` = "SmartAI" WHERE `entry` IN (25414,25420,25421);
UPDATE `creature_template` SET `unit_class` = 2 WHERE `entry` IN (25420,25421);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25414,25420,25421) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25414,2541400,2541401,25420,2542000,25421,2542100) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Warrior
-- Currently all instant actions will be executed in any case, all timed actions will be executed only out of combat(say, start follow)
-- Not sure if it's correct or not(see comments about despawn events)
-- If by any chance after summon creature will be in combat for too long, despawn action list will be not started and it's probably incorrect
(25414,0,0,0,37,0,100,0,0,0,0,0,0,80,2541400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On AI Initialize - Run Script"),
(25414,0,1,0,4,0,100,0,0,0,0,0,0,11,45517,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Aggro - Cast 'Commanding Shout'"),
(25414,0,2,0,0,0,100,0,0,5000,5000,10000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - In Combat - Cast 'Cleave'"),
(25414,0,3,0,59,0,100,0,1,0,0,0,0,80,2541401,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Timed Event - Run Script"),
-- Guessed, just in case
(25414,0,4,0,6,0,100,0,0,0,0,0,0,11,45522,2,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Death - Cast 'Dispel Freed Soldier Debuff'"),

-- Used by all of them
(2541400,9,0,0,0,0,100,0,0,0,0,0,0,67,1,100000,100000,0,0,100,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Create Timed Event 1"),
-- Hackily stop follow movement
(2541400,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Move To Self"),
(2541400,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Set Orientation Owner"),
(2541400,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Say Line 0"),
(2541400,9,4,0,0,0,100,0,4000,4000,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Start Follow Owner"),

-- Despawn events are quite similar and according to sniffs can be called in combat. Passive react state is also confirmed by sniffs but
-- they don't become immune. That means they will be still attacked and it looks weird. Don't have enough info to figure out if it's correct
(2541401,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Set Reactstate Passive"),
-- Hackily stop follow movement
(2541401,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Move To Self"),
-- That spell probably has misleading name because if it really despawns them, it should be scripted in each script separately because they
-- all despawns at different time. Best guess: handles actions above(pre-despawn events)
-- That spell is also used in 'Ebon Blade Prisoners'
(2541401,9,2,0,0,0,100,0,0,0,0,0,0,11,43014,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Cast 'Despawn Self'"),
(2541401,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Say Line 1"),
-- Not really sure what they do here, looks like same random movement like in 'Ebon Blade Prisoners'
(2541401,9,4,0,0,0,100,0,3000,3000,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Start Random Movement"),
(2541401,9,5,0,0,0,100,0,7000,7000,0,0,0,11,45522,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Cast 'Dispel Freed Soldier Debuff'"),
(2541401,9,6,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Warrior - On Script - Despawn Instant"),

-- Mage
(25420,0,0,0,37,0,100,0,0,0,0,0,0,80,2541400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On AI Initialize - Run Script"),
-- No idea what it does but wasn't sent in case of Warsong Hold Warrior
(25420,0,1,0,37,0,100,0,0,0,0,0,0,11,45518,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On AI Initialize - Cast 'Quest Despawn Self'"),
-- Something may cancel this, probably combat
(25420,0,2,0,1,0,100,1,5000,5000,0,0,0,11,45525,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Mage - Out of Combat - Cast 'Arcane Intellect' (No Repeat)"),
(25420,0,3,0,0,0,100,0,0,0,7000,10000,0,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Warsong Hold Mage - In Combat - Cast 'Fireball'"),
(25420,0,4,0,59,0,100,0,1,0,0,0,0,80,2542000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Timed Event - Run Script"),
(25420,0,5,0,6,0,100,0,0,0,0,0,0,11,45522,2,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Death - Cast 'Dispel Freed Soldier Debuff'"),

(2542000,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Set Reactstate Passive"),
(2542000,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Move To Self"),
(2542000,9,2,0,0,0,100,0,0,0,0,0,0,11,43014,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Cast 'Despawn Self'"),
(2542000,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Say Line 1"),
(2542000,9,4,0,0,0,100,0,4000,4000,0,0,0,11,45522,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Cast 'Dispel Freed Soldier Debuff'"),
(2542000,9,5,0,0,0,100,0,0,0,0,0,0,11,41232,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Cast 'Teleport Visual Only'"),
(2542000,9,6,0,0,0,100,0,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Mage - On Script - Delayed Despawn"),

-- Shaman
(25421,0,0,0,37,0,100,0,0,0,0,0,0,80,2541400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On AI Initialize - Run Script"),
-- No idea what it does but wasn't sent in case of Warsong Hold Warrior
(25421,0,1,0,37,0,100,0,0,0,0,0,0,11,45518,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On AI Initialize - Cast 'Quest Despawn Self'"),
(25421,0,2,0,0,0,100,0,0,5000,10000,10000,0,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - In Combat - Cast 'Frost Shock'"),
(25421,0,3,0,59,0,100,0,1,0,0,0,0,80,2542100,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Timed Event - Run Script"),
(25421,0,4,0,6,0,100,0,0,0,0,0,0,11,45522,2,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Death - Cast 'Dispel Freed Soldier Debuff'"),

(2542100,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Set Reactstate Passive"),
(2542100,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Move To Self"),
(2542100,9,2,0,0,0,100,0,0,0,0,0,0,11,43014,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Cast 'Despawn Self'"),
(2542100,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Say Line 1"),
(2542100,9,4,0,0,0,100,0,3000,3000,0,0,0,11,45528,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Cast 'Ghost Wolf'"),
(2542100,9,5,0,0,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Start Random Movement"),
(2542100,9,6,0,0,0,100,0,4000,4000,0,0,0,11,45522,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Cast 'Dispel Freed Soldier Debuff'"),
(2542100,9,7,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Hold Shaman - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` IN (25414,25420,25421);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25414,0,0,"My axe is yours, hero! Together we will destroy these insects!",12,1,100,5,0,0,24614,0,"Warsong Hold Warrior"),
(25414,1,0,"I must return to Warsong Hold. Battle hard, hero!",12,1,100,0,0,0,24615,0,"Warsong Hold Warrior"),
(25414,1,1,"I must return to Warsong Hold, hero. May you swim in the blood of our enemies and feast upon their sorrow!",12,1,100,0,0,0,24616,0,"Warsong Hold Warrior"),

(25420,0,0,"By the fury of the Sunwell, I am released!",12,1,100,5,0,0,24624,0,"Warsong Hold Mage"),
(25420,0,1,"Vengeance shall be mine! For Quel'thalas! For the sin'dorei!",12,1,100,5,0,0,24625,0,"Warsong Hold Mage"),
(25420,1,0,"Farewell, friend. I must return to Warsong Hold.",12,1,100,0,0,0,24617,0,"Warsong Hold Mage"),
(25420,1,1,"Until we meet again, hero. Duty calls!",12,1,100,0,0,0,24618,0,"Warsong Hold Mage"),

(25421,0,0,"Rescued! You have my thanks and my aid, friend.",12,1,100,5,0,0,24622,0,"Warsong Hold Shaman"),
(25421,0,1,"We will battle together to rid this quarry of the Scourge!",12,1,100,5,0,0,24623,0,"Warsong Hold Shaman"),
(25421,1,0,"Spirits watch over you, friend. I must make my return to Warsong Hold.",12,1,100,0,0,0,24620,0,"Warsong Hold Shaman"),
(25421,1,1,"Ancestors be with you, hero. Farewell!",12,1,100,0,0,0,24621,0,"Warsong Hold Shaman");
