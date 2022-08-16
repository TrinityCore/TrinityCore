-- The Perfect Dissemblance (12260)
-- Priest
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dragonblight_cancel_banshees_magic_mirror';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48692,'spell_dragonblight_cancel_banshees_magic_mirror');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27202 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (/*2720200,*/2720201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27202,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Aggro - Say Line 1"),
(27202,0,1,0,8,0,100,1,48268,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Container of Rats' - Despawn (No Repeat)"),
(27202,0,2,0,8,0,100,1,48679,0,0,0,0,80,2720201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Run Script (No Repeat)"),
(27202,0,3,0,0,0,100,0,0,0,3400,4800,0,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - In Combat CMC - Cast 'Raven Flock'"),
(27202,0,4,0,2,0,100,0,0,30,14000,18000,0,11,50750,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-30% Health - Cast 'Raven Heal'"),

(2720201,9,0,0,0,0,100,0,0,0,0,0,0,11,48654,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Cast 'The Perfect Dissemblance: Summon Priest's Footman'"),
(2720201,9,1,0,0,0,100,0,0,0,0,0,0,11,48648,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Cast 'Banshee's Magic Mirror'"),
-- Hack, 48648 above should be enough, but force-cast of that spell doesn't work always for unknown reason
-- Sadly, yes, if it works, player summons two footmen instead of one
(2720201,9,2,0,0,0,100,0,0,0,0,0,0,85,48655,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Self Cast 'The Perfect Dissemblance: Summon Player's Footman & Credit Credit'"),
(2720201,9,3,0,0,0,100,0,0,0,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Say Line 2");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 27202 AND `SourceId` = 0;

DELETE FROM `creature_text` WHERE `CreatureID` = 27202;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27202,0,0,"I've heard whisperings of intruders.  Be wary.",12,0,100,0,0,0,26254,0,"Onslaught Raven Priest"),
(27202,0,1,"I sense the taint of this land in you, footman.  Report to the Bishop before the start of your next shift.",12,0,100,0,0,0,26256,0,"Onslaught Raven Priest"),
(27202,0,2,"You stink.  Take a shower.",12,0,100,0,0,0,26257,0,"Onslaught Raven Priest"),
(27202,0,3,"Your protection is strong, child.  Continue your work.",12,0,100,0,0,0,26390,0,"Onslaught Raven Priest"),
(27202,0,4,"You require the Bishop's blessing.  Go to him soon.",12,0,100,0,0,0,26391,0,"Onslaught Raven Priest"),
(27202,0,5,"Remain on the pure path.  The Light will protect you.",12,0,100,0,0,0,26392,0,"Onslaught Raven Priest"),
(27202,0,6,"The Grand Admiral himself has come to see to our dedication.  If I see you slacking on your post again, I will gut you myself.",12,0,100,0,0,0,26655,0,"Onslaught Raven Priest"),

(27202,1,0,"You are impure!",12,0,100,0,0,0,26393,0,"Onslaught Raven Priest"),
(27202,1,1,"Die, cur!",12,0,100,0,0,0,26394,0,"Onslaught Raven Priest"),
(27202,1,2,"Be washed from my sight!",12,0,100,0,0,0,26395,0,"Onslaught Raven Priest"),
(27202,1,3,"By the Light!",12,0,100,0,0,0,26396,0,"Onslaught Raven Priest"),
(27202,1,4,"Wretch!",12,0,100,0,0,0,26397,0,"Onslaught Raven Priest"),
(27202,1,5,"Defiler!",12,0,100,0,0,0,26398,0,"Onslaught Raven Priest"),
(27202,1,6,"Abbendis will see you purged!",12,0,100,0,0,0,26399,0,"Onslaught Raven Priest"),

(27202,2,0,"HELP! HELP! THIS $g MAN : WOMAN; HAS STOLEN MY IMAGE!",12,0,100,0,0,0,26543,0,"Onslaught Raven Priest"),

(27202,3,0,"Gah! What are you doing?",12,0,100,0,0,0,26637,0,"Onslaught Raven Priest"),
(27202,4,0,"A member of the priesthood whom I've never seen before.",12,0,100,0,0,0,26638,0,"Onslaught Raven Priest");

-- Footmen, yes, it's intended when one attacks player and another attacks priest, they even talk about that
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27405,27406) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2740500,2740600) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27405,0,0,0,11,0,100,0,0,0,0,0,0,80,2740500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Footman - On Spawn - Run Script"),
(27405,0,1,0,0,0,100,0,0,10000,30000,40000,0,11,50714,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Footman - In Combat - Cast 'Unrelenting Onslaught'"),

(27406,0,0,0,11,0,100,0,0,0,0,0,0,80,2740600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Footman - On Spawn - Run Script"),
(27406,0,1,0,0,0,100,0,0,10000,30000,40000,0,11,50714,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Footman - In Combat - Cast 'Unrelenting Onslaught'"),

(2740500,9,0,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Onslaught Footman - On Script - Start Attack Summoner"),
(2740500,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,0,"Onslaught Footman - On Script - Say Line 0"),

(2740600,9,0,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Onslaught Footman - On Script - Start Attack Summoner"),
(2740600,9,1,0,0,0,100,0,3000,3000,0,0,0,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,0,"Onslaught Footman - On Script - Say Line 0");


-- A Fall From Grace (12274)
-- Disguise stuff
-- Shouldn't be here, cancels disguise everytime, not a real solution but still
DELETE FROM `spell_area` WHERE `spell` = 48358 AND `area` = 4180;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dragonblight_scarlet_raven_priest_image_master','spell_dragonblight_cancel_scarlet_raven_priest_image');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48762,'spell_dragonblight_scarlet_raven_priest_image_master'),
(48769,'spell_dragonblight_cancel_scarlet_raven_priest_image');

UPDATE `quest_template_addon` SET `SourceSpellID` = 0 WHERE `ID` = 12274;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 27350 AND `SourceId` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27350 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27350,0,0,0,19,0,100,0,12274,0,0,0,0,11,48774,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agent Skully - On Quest 'A Fall From Grace' Taken - Cast 'A Fall from Grace: Quest Accept'"),
(27350,0,1,0,62,0,100,0,9501,0,0,0,0,11,48774,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agent Skully - On Gossip Option 0 Selected - Cast 'A Fall from Grace: Quest Accept'");

-- Bell stuff
DELETE FROM `smart_scripts` WHERE `entryorguid` = 188713 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(188713,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Store Targetlist"),
(188713,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,10,102082,27202,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Send Target 1 (Onslaught Raven Priest)"),
(188713,1,2,3,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,100277,24110,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Set Data 1 1 (ELM General Purpose Bunny Large)"),
(188713,1,3,4,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,102082,27202,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Set Data 1 1 (Onslaught Raven Priest)"),
(188713,1,4,5,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,105877,27245,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Set Data 1 1 (High Abbot Landgren)"),
(188713,1,5,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,106200,27247,0,0,0,0,0,0,"Abbey Bell Rope - On State Changed - Set Data 1 1 (Devout Bodyguard)");

DELETE FROM `smart_scripts` WHERE `entryorguid` = -100277 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2411000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-100277,0,0,0,38,0,100,0,1,1,0,0,0,80,2411000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - On Data Set 1 1 - Run Script"),

(2411000,9,0,0,0,0,100,0,0,0,0,0,0,4,7256,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - On Script - Play Sound 7256"),
(2411000,9,1,0,0,0,100,0,3000,3000,0,0,0,4,7256,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - On Script - Play Sound 7256"),
(2411000,9,2,0,0,0,100,0,3000,3000,0,0,0,4,7256,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - On Script - Play Sound 7256");

DELETE FROM `smart_scripts` WHERE `entryorguid` = -102082 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2720202,2720203) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-102082,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Aggro - Say Line 1"),
(-102082,0,1,0,8,0,100,1,48268,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Container of Rats' - Despawn (No Repeat)"),
(-102082,0,2,0,8,0,100,1,48679,0,0,0,0,80,2720201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Run Script (No Repeat)"),
(-102082,0,3,0,0,0,100,0,0,0,3400,4800,0,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - In Combat CMC - Cast 'Raven Flock'"),
(-102082,0,4,0,2,0,100,0,0,30,14000,18000,0,11,50750,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-30% Health - Cast 'Raven Heal'"),
(-102082,0,5,0,38,0,100,0,1,1,0,0,0,80,2720202,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Data Set 1 1 - Run Script"),
(-102082,0,6,0,38,0,100,0,1,2,0,0,0,80,2720203,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Data Set 1 2 - Run Script"),

(2720202,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Set Orientation Stored Target 1"),
(2720202,9,1,0,0,0,100,0,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Play Emote 5"),
(2720202,9,2,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Say Line 3"),
(2720202,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Remove Flag Standstate Kneel"),
(2720202,9,4,0,0,0,100,0,3000,3000,0,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Play Emote 6"),
(2720202,9,5,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.944444179534912109,"Onslaught Raven Priest - On Script - Set Orientation"),
(2720202,9,6,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Set Flag Standstate Kneel"),

(2720203,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Set Orientation Invoker"),
(2720203,9,1,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Remove Flag Standstate Kneel"),
(2720203,9,2,0,0,0,100,0,2000,2000,0,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Play Emote 6"),
(2720203,9,3,0,0,0,100,0,0,0,0,0,0,1,4,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Say Line 4"),
(2720203,9,4,0,0,0,100,0,11000,11000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.944444179534912109,"Onslaught Raven Priest - On Script - Set Orientation"),
(2720203,9,5,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Script - Set Flag Standstate Kneel");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27245 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27245,0,0,0,38,0,100,0,1,1,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Data Set 1 1 - Say Line 0"),
(27245,0,1,0,62,0,100,0,9536,0,0,0,0,11,48756,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Gossip Option 0 Selected - Cast 'A Fall from Grace: Ring Kissed Dummy Aura'");

DELETE FROM `creature_text` WHERE `CreatureID` = 27245;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27245,0,0,"Boys, go see who's doing that.",12,0,100,1,0,0,26608,0,"High Abbot Landgren");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-106200,-106201) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2724700,2724701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-106200,0,0,0,38,0,100,1,1,1,0,0,0,80,2724700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Data Set 1 1 - Run Script (No Repeat)"),
(-106200,0,1,0,58,0,100,0,0,0,0,0,0,80,2724701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Waypoint Finished - Run Script"),
(-106200,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - In Combat - Cast 'Piercing Howl'"),

(-106201,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - In Combat - Cast 'Piercing Howl'"),

(2724700,9,0,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Script - Say Line 0"),
(2724700,9,1,0,0,0,100,0,3000,3000,0,0,0,53,1,27247,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Script - Start Waypoint"),

(2724701,9,0,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Script - Say Line 1"),
(2724701,9,1,0,0,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,102082,27202,0,0,0,0,0,0,"Devout Bodyguard - On Script - Set Data 1 2 (Onslaught Raven Priest)"),
(2724701,9,2,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Script - Say Line 2"),
(2724701,9,3,0,0,0,100,0,20000,20000,0,0,0,41,0,0,0,0,0,0,10,106201,27247,0,0,0,0,0,0,"Devout Bodyguard - On Script - Despawn (Devout Bodyguard)"),
(2724701,9,4,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devout Bodyguard - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = 27247;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27247,0,0,"Yes, your eminence. Come on!",12,0,100,2,0,0,26609,0,"Devout Bodyguard"),
(27247,1,0,"Hey, who rang the bell?",12,0,100,6,0,0,26610,0,"Devout Bodyguard"),
(27247,2,0,"The bodyguard grunts.",16,0,100,0,0,0,26611,0,"Devout Bodyguard");

DELETE FROM `waypoints` WHERE `entry` IN (27247,2724700,2724701);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(27247,1,2800.5461,-479.0516,119.616455,"Devout Bodyguard"),
(27247,2,2807.7734,-471.9484,119.61645,"Devout Bodyguard"),
(27247,3,2814.5222,-465.90128,119.6147,"Devout Bodyguard"),
(27247,4,2821.4888,-471.29794,123.11067,"Devout Bodyguard"),
(27247,5,2827.7585,-472.69525,128.75671,"Devout Bodyguard"),
(27247,6,2833.6016,-470.6969,134.06349,"Devout Bodyguard"),
(27247,7,2839.7278,-464.88617,135.3624,"Devout Bodyguard"),
(27247,8,2837.8572,-452.8187,135.36316,"Devout Bodyguard"),
(27247,9,2827.6262,-447.17468,135.36287,"Devout Bodyguard"),
(27247,10,2816.3098,-452.6234,135.36247,"Devout Bodyguard"),
(27247,11,2814.4758,-463.5507,135.36266,"Devout Bodyguard"),
(27247,12,2819.273,-470.78683,136.68086,"Devout Bodyguard"),
(27247,13,2827.964,-473.3304,144.91586,"Devout Bodyguard"),
(27247,14,2834.3506,-470.6176,150.68944,"Devout Bodyguard"),
(27247,15,2837.8606,-466.93002,150.83655,"Devout Bodyguard"),
(27247,16,2833.3555,-463.5104,150.8349,"Devout Bodyguard");

DELETE FROM `creature_formations` WHERE `memberGUID` IN (106200,106201);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(106200,106200,0,0,515,0,0),
(106200,106201,2,0,515,0,0);

UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 27247;

-- AT
DELETE FROM `areatrigger_involvedrelation` WHERE `id` = 4987;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4987 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4987,2,0,1,46,0,100,0,4987,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (New Hearthglen) - On Trigger - Store Targetlist"),
(4987,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,10,98593,23837,0,0,0,0,0,0,"Areatrigger (New Hearthglen) - On Link - Send Target 1 (ELM General Purpose Bunny)"),
(4987,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,10,98593,23837,0,0,0,0,0,0,"Areatrigger (New Hearthglen) - On Link - Set Data 0 1 (ELM General Purpose Bunny)");

DELETE FROM `smart_scripts` WHERE `entryorguid` = -98593 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Hack, bunny here should cast 48759 on player but that works only if player does not move (if player teleports to creature)
-- It works with similar spells, for example 40917
(-98593,0,0,0,38,0,100,0,0,1,0,0,0,85,48757,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny - On Data Set 0 1 - Self Cast 'A Fall from Grace: Summon High Abbot Landgren'"),
-- That aura indeed is removed and that gives us possibility to prevent double-summoning no matter how we handle summon
(-98593,0,1,0,38,0,100,0,0,1,0,0,0,28,48756,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny - On Data Set 0 1 - Remove Aura 'A Fall from Grace: Ring Kissed Dummy Aura'");

-- Final part (no, he doesn't use vehicle for jump)
UPDATE `creature_template` SET `speed_walk` = 2 WHERE `entry` = 27439;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27439 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2743900,2743901) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27439,0,0,0,11,0,100,0,0,0,0,0,0,80,2743900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Spawn - Run Script"),
(27439,0,1,0,58,0,100,0,0,0,0,0,0,80,2743901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Waypoint Finished - Run Script"),

-- Hack, at this moment personal spawns can attack any creature, that completely breaks script
(2743900,9,0,0,0,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set ImmuneNPC"),
(2743900,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Orientation Summoner"),
(2743900,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 0"),
(2743900,9,3,0,0,0,100,0,5000,5000,0,0,0,53,0,27439,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Start Waypoint"),

(2743901,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Orientation Summoner"),
(2743901,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 1"),
(2743901,9,2,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Orientation Summoner"),
(2743901,9,3,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 2"),
(2743901,9,4,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Orientation Summoner"),
(2743901,9,5,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 3"),
(2743901,9,6,0,0,0,100,0,3000,3000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Play Emote 1"),
(2743901,9,7,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Orientation Summoner"),
(2743901,9,8,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 4"),
(2743901,9,9,0,0,0,100,0,3000,3000,0,0,0,11,48771,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Cast 'A Fall from Grace: Kill Credit'"),
-- No idea why it's still needed
(2743901,9,10,0,0,0,100,0,0,0,0,0,0,15,12274,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Quest Credit 'A Fall from Grace'"),
(2743901,9,11,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Say Line 5"),
(2743901,9,12,0,0,0,100,0,0,0,0,0,0,17,427,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Set Emote State 427"),
(2743901,9,13,0,0,0,100,0,0,0,0,0,0,97,25,32,0,0,0,0,1,0,0,0,0,2715.55,-560.343,10.6656,0,"High Abbot Landgren - On Script - Jump To Pos"),
(2743901,9,14,0,0,0,100,0,4000,4000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Abbot Landgren - On Script - Despawn");

DELETE FROM `waypoints` WHERE `entry` = 27439;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(27439,1,2827.0466,-412.4136,118.283745,"High Abbot Landgren"),
(27439,2,2810.891,-412.49506,118.283745,"High Abbot Landgren"),
(27439,3,2786.2637,-436.96738,118.26536,"High Abbot Landgren"),
(27439,4,2776.9878,-464.75424,116.191505,"High Abbot Landgren"),
(27439,5,2765.8164,-488.21484,114.05323,"High Abbot Landgren"),
(27439,6,2737.89,-524.4745,103.4476,"High Abbot Landgren");


-- Bombard the Ballistae (12232)
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dragonblight_bombard_the_ballistae_fx_master';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48347,'spell_dragonblight_bombard_the_ballistae_fx_master');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27331 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2733100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27331,0,0,0,8,0,100,0,48345,0,0,0,0,80,2733100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Spellhit 'Siegesmith Bombs' - Run Script"),

(2733100,9,0,0,0,0,100,0,0,0,0,0,0,33,27331,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Script - Quest Credit 'Bombard the Ballistae'"),
(2733100,9,1,0,0,0,100,0,0,0,0,0,0,11,48347,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Script - Cast 'Bombard the Ballistae: FX Master'"),
(2733100,9,2,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bombard the Ballistae Kill Credit Bunny - On Script - Despawn");


-- Without a Prayer (12254)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27246 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2724600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27246,0,0,0,38,0,100,0,0,1,60000,60000,0,80,2724600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bishop Street - On Data Set 0 1 - Run Script"),
(27246,0,1,0,4,0,100,0,0,0,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Bishop Street - On Aggro - Say Line 2"),
(27246,0,2,0,0,0,100,0,0,0,3400,4800,0,11,20820,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bishop Street - In Combat CMC - Cast 'Holy Smite'"),
(27246,0,3,0,0,0,100,0,12000,16000,45000,55000,0,11,11974,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bishop Street - In Combat - Cast 'Power Word: Shield'"),

(2724600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bishop Street - On Script - Say Line 0"),
(2724600,9,1,0,0,0,100,0,4000,4000,0,0,0,11,48183,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bishop Street - On Script - Cast 'Blessing of the Light'"),
(2724600,9,2,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bishop Street - On Script - Say Line 1");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4984 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4984,2,0,0,46,0,100,0,4984,0,0,0,0,45,0,1,0,0,0,0,19,27246,0,0,0,0,0,0,0,"Areatrigger (New Hearthglen) - On Trigger - Set Data 0 1 (Bishop Street)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4984;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4984,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4984 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4984,2,0,9,0,12254,0,0,0,0,0,"","Group 0: Execute Event 0 if player has taken quest 'Without a Prayer'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 48183;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,48183,0,0,31,0,3,27203,0,0,0,0,"","Group 0: Spell 'Blessing of the Light' (Effect 0) targets creature 'Onslaught Footman'");
