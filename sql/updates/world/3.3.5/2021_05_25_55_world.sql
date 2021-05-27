-- Quest creature will be not summoned if cocoon is killed by a pet, it's close to correct behavior. I mean, in retail they summons nothing
-- if killed by pets. Perhaps our conditions work differently or we need to add another condition to check if killer is player. It's also possible that
-- final check is done in spell script
-- Chance to summon hostile unit may be just 75 and not 66, it's just not easy to find a balance between chance and respawn time to
-- reflect what I see in movies. In case of Rivenwood chance 80 looks fine
-- Quest creatures currently can be attacked by other creatures, they don't have immune flag. It may look like a bug but it's probably not

-- They're Alive! Maybe...
DELETE FROM `spell_script_names` WHERE `spell_id` = 30950 AND `ScriptName` = "spell_free_webbed";
DELETE FROM `spell_script_names` WHERE `spell_id` = 31009 AND `ScriptName` = "spell_free_webbed_on_quest";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(30950,"spell_free_webbed"),
(31009,"spell_free_webbed_on_quest");

-- Looks like 1 min
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 17680;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 17680;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17680 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17680,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Webbed Creature - On AI Initialize - Set Reactstate Passive"),
(17680,0,1,0,6,0,100,0,0,0,0,0,0,11,30950,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Webbed Creature - On Death - Cast 'Free Webbed Creature'"),
(17680,0,2,0,6,0,100,0,0,0,0,0,0,11,31009,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Webbed Creature - On Death - Cast 'Free Webbed Creature'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17680 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,17680,0,0,9,0,9670,0,0,1,0,0,"","Group 0: Execute SAI (Action 1) if quest 'They're Alive! Maybe...' is not taken by invoker"),
(22,3,17680,0,0,9,0,9670,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if quest 'They're Alive! Maybe...' is taken by invoker");

UPDATE `creature_template` SET `unit_flags` = 33024 WHERE `entry` = 17681;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17681 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1768100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17681,0,0,0,54,0,100,0,0,0,0,0,0,80,1768100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Expedition Researcher - On Just Summoned - Run Script"),
(17681,0,1,0,34,0,100,0,8,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Expedition Researcher - On Reached Point 1 - Despawn Instant"),

(1768100,9,0,0,0,0,100,0,1000,1000,0,0,0,33,17681,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Expedition Researcher - On Script - Quest Credit 'They're Alive! Maybe...'"),
(1768100,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Expedition Researcher - On Script - Set Orientation Owner"),
(1768100,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Expedition Researcher - On Script - Say Line 0"),
-- Completely guessed
(1768100,9,3,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-1596.5,-10847.2,57.352,0,"Expedition Researcher - On Script - Move To Position");
 
DELETE FROM `creature_text` WHERE `CreatureID` = 17681;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17681,0,0,"We're free! We're free!",12,7,100,0,0,0,14346,0,"Expedition Researcher"),
(17681,0,1,"Woot! Thanks!",12,7,100,0,0,0,14347,0,"Expedition Researcher"),
(17681,0,2,"By the forehead signet of Velen, I am saved!",12,7,100,0,0,0,14348,0,"Expedition Researcher"),
(17681,0,3,"I knew Cornelius wouldn't leave us behind!",12,7,100,0,0,0,14349,0,"Expedition Researcher");


-- Taken in the Night, sniffed
DELETE FROM `spell_script_names` WHERE `spell_id` = 38949 AND `ScriptName` = "spell_free_webbed_terokkar";
DELETE FROM `spell_script_names` WHERE `spell_id` = 38950 AND `ScriptName` = "spell_free_webbed_terokkar_on_quest";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38949,"spell_free_webbed_terokkar"),
(38950,"spell_free_webbed_terokkar_on_quest");

-- Looks like 1 min or even less, looks like unlike the other they're pooled so it's hard to be sure
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 22355;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22355 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2235500 AND 2235505 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22355,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherweb Victim - On AI Initialize - Set Reactstate Passive"),
(22355,0,1,0,6,0,100,0,0,0,0,0,0,11,38949,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherweb Victim - On Death - Cast 'Terrokar Free Webbed Creature'"),
(22355,0,2,0,6,0,100,0,0,0,0,0,0,11,38950,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Netherweb Victim - On Death - Cast 'Terokkar Free Webbed Creature ON QUEST'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22355 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,22355,0,0,9,0,10873,0,0,1,0,0,"","Group 0: Execute SAI (Action 1) if quest 'Taken in the Night' is not taken by invoker"),
(22,3,22355,0,0,9,0,10873,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if quest 'Taken in the Night' is taken by invoker");

UPDATE `creature_template` SET `unit_flags` = 33024 WHERE `entry` = 22459;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22459 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2245900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22459,0,0,0,54,0,100,0,0,0,0,0,0,80,2245900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Just Summoned - Run Script"),
(22459,0,1,0,34,0,100,0,8,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Reached Point 1 - Despawn Instant"),

(2245900,9,0,0,0,0,100,0,0,0,0,0,0,33,22459,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Script - Quest Credit 'Taken in the Night'"),
(2245900,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Script - Set Orientation Owner"),
(2245900,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Script - Say Line 0"),
(2245900,9,3,0,0,0,100,0,1000,1000,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-3801.06,4318.73,5.0761,0,"Freed Sha'tar Warrior - On Script - Move To Position");

UPDATE `creature_text` SET `GroupID` = 0, `Language` = 0, `Emote` = 0 WHERE `CreatureID` = 22459;


-- Cocooned!, sniffed
DELETE FROM `spell_script_names` WHERE `spell_id` = 51596 AND `ScriptName` = "spell_cocooned_not_on_quest";
DELETE FROM `spell_script_names` WHERE `spell_id` = 51598 AND `ScriptName` = "spell_cocooned_on_quest";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51596,"spell_cocooned_not_on_quest"),
(51598,"spell_cocooned_on_quest");

-- Looks like 1 min
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 28413;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28413 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2841300 AND 2841302 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28413,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nerubian Cocoon - On AI Initialize - Set Corpse Delay"),
(28413,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nerubian Cocoon - On AI Initialize - Set Reactstate Passive"),
(28413,0,2,0,6,0,100,0,0,0,0,0,0,11,51596,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Cast 'Cocooned: Player Not On Quest'"),
(28413,0,3,0,6,0,100,0,0,0,0,0,0,11,51598,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Cast 'Cocooned: Player On Quest'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 28413 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,28413,0,0,9,0,12606,0,0,1,0,0,"","Group 0: Execute SAI (Action 2) if quest 'Cocooned!' is not taken by invoker"),
(22,4,28413,0,0,9,0,12606,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if quest 'Cocooned!' is taken by invoker");

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 28415;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28415 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2841500 AND 2841501 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28415,0,0,0,54,0,100,0,0,0,0,0,0,88,2841500,2841501,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Footman - On Just Summoned - Run Random Script"),

(2841500,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Say Line 0"),
(2841500,9,1,0,0,0,100,0,0,0,0,0,0,33,28415,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Quest Credit 'Cocooned!'"),
(2841500,9,2,0,0,0,100,0,0,0,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Cast 'Suicide'"),
(2841500,9,3,0,0,0,100,0,0,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Delayed Despawn"),

(2841501,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Say Line 1"),
(2841501,9,1,0,0,0,100,0,0,0,0,0,0,33,28415,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Quest Credit 'Cocooned!'"),
(2841501,9,2,0,0,0,100,0,2000,2000,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Set Emote State 333"),
(2841501,9,3,0,0,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Footman - On Script - Delayed Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = 28415;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28415,0,0,"ugh...",12,0,100,0,0,0,27890,0,"Captive Footman"),
(28415,0,1,"Avenge me!",12,0,100,0,0,0,27891,0,"Captive Footman"),
(28415,0,2,"I am... finished.",12,0,100,0,0,0,27892,0,"Captive Footman"),
(28415,0,3,"It's too late for me.",12,0,100,0,0,0,27894,0,"Captive Footman"),
(28415,1,0,"I'm saved!",12,0,100,71,0,0,27896,0,"Captive Footman"),
(28415,1,1,"I thought I was done for!",12,0,100,71,0,0,27897,0,"Captive Footman"),
(28415,1,2,"Thank you!",12,0,100,71,0,0,27898,0,"Captive Footman"),
(28415,1,3,"I am in your debt, friend.",12,0,100,71,0,0,27899,0,"Captive Footman");

UPDATE `smart_scripts` SET `target_type` = 7, `target_param1` = 0, `comment` = "Drakkari Captive - On Just Summoned - Start Attack Invoker" WHERE `entryorguid` = 28414 AND `source_type` = 0 AND `id` = 0;


-- Rivenwood Captives, in general same as above
DELETE FROM `spell_script_names` WHERE `spell_id` = 43288 AND `ScriptName` = "spell_rivenwood_captives_not_on_quest";
DELETE FROM `spell_script_names` WHERE `spell_id` = 43287 AND `ScriptName` = "spell_rivenwood_captives_on_quest";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(43288,"spell_rivenwood_captives_not_on_quest"),
(43287,"spell_rivenwood_captives_on_quest");

-- They're probably pooled, no clue what is original respawn time but something like 2 minutes or 1 minute,
-- hard to say, let's make it 2 just to make quest less annoying
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` = 24210;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 24210;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24210 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24210,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Riven Widow Cocoon - On AI Initialize - Set Corpse Delay"),
(24210,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Riven Widow Cocoon - On AI Initialize - Set Reactstate Passive"),
(24210,0,2,0,6,0,100,0,0,0,0,0,0,11,43288,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Riven Widow Cocoon - On Death - Cast 'Rivenwood Captives: Player Not On Quest'"),
(24210,0,3,0,6,0,100,0,0,0,0,0,0,11,43287,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Riven Widow Cocoon - On Death - Cast 'Rivenwood Captives: Player On Quest'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 24210 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,24210,0,0,9,0,11296,0,0,1,0,0,"","Group 0: Execute SAI (Action 2) if quest 'Rivenwood Captives' is not taken by invoker"),
(22,4,24210,0,0,9,0,11296,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if quest 'Rivenwood Captives' is taken by invoker");

-- These are immune
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 24211;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24211 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2421100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24211,0,0,0,54,0,100,0,0,0,0,0,0,80,2421100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Just Summoned - Run Script"),

(2421100,9,0,0,0,0,100,0,1000,1000,0,0,0,33,24211,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Quest Credit 'Rivenwood Captives'"),
(2421100,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Set Orientation Owner"),
(2421100,9,2,0,0,0,100,0,1000,1000,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Start Follow Owner"),
-- Our usual hack
(2421100,9,3,0,0,0,100,0,6000,6000,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Stop Follow Owner"),
(2421100,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Say Line 0"),
(2421100,9,5,0,0,0,100,0,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - On Script - Delayed Despawn");

-- Reorder
DELETE FROM `creature_text` WHERE `CreatureID` = 24211;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24211,0,0,"Thank you, stranger.",12,1,100,1,0,0,22945,0,"Freed Winterhoof Longrunner"),
(24211,0,1,"I must return. Good hunting to you.",12,1,100,1,0,0,22946,0,"Freed Winterhoof Longrunner"),
(24211,0,2,"Blessings of the spirits of the land and air upon you.",12,1,100,1,0,0,22947,0,"Freed Winterhoof Longrunner"),
(24211,0,3,"You saved me from certain death. I owe you.",12,1,100,1,0,0,22948,0,"Freed Winterhoof Longrunner"),
(24211,0,4,"We should never have traveled through the Rivenwood. Everyone knows this!",12,1,100,1,0,0,22949,0,"Freed Winterhoof Longrunner"),
(24211,0,5,"Strange ghosts walk the land. Be careful!",12,1,100,1,0,0,22950,0,"Freed Winterhoof Longrunner"),
(24211,0,6,"They took us one by one. I'm sure there are other survivors.",12,1,100,1,0,0,22951,0,"Freed Winterhoof Longrunner"),
(24211,0,7,"I owe you a life debt, stranger.",12,1,100,1,0,0,22952,0,"Freed Winterhoof Longrunner");
