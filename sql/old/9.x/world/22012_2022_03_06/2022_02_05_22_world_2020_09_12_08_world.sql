-- https://www.youtube.com/watch?v=srN8vbnZgrw
-- Note: Spell 'Fel Gland Cleanup' (44988) probably is used after player turns in quest
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 22252;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22252 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2225200 AND 2225201 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22252,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Respawn - Set Event Phase 1"),
(22252,0,1,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Aggro - Say Line 0"),
(22252,0,2,0,0,0,100,0,5000,9000,10000,12000,0,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Peon - In Combat - Cast 'Sunder Armor'"),
(22252,0,3,0,13,0,100,0,12000,18000,0,0,0,11,34802,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragomaw Peon - Target Casting - Cast 'Kick'"),

(22252,0,4,0,8,1,100,0,40468,0,0,0,0,80,2225200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Spellhit 'Serving Poisoned Mutton' - Run Script (Phase 1)"),

(2225200,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Store Targetlist"),
(2225200,9,1,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Set Emote State 0"),
(2225200,9,2,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,11,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Set Emote State 0 (Dragonmaw Peon)"),
(2225200,9,3,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Set Event Phase 2"),
(2225200,9,4,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Set Data 1 1 (Dragonmaw Peon)"),
(2225200,9,5,0,0,0,100,0,0,0,0,0,0,69,1,0,0,3,0,0,20,185893,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Move to Closest Gameobject 'Delicious Mutton'"),

-- Spell hit target forms formation, called only when all formation members reaches final point
-- People says the quest is worst daily quest even because of high chance to bug
-- Also quest bugs if item was used when only one peon was nearby (cannot form formation, perhaps)
(22252,0,5,0,34,0,100,0,8,1,0,0,0,80,2225201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Reached Point 1 - Run Script"),

(2225201,9,0,0,0,0,100,0,0,0,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Play Emote 71"),
(2225201,9,1,0,0,0,100,0,0,0,0,0,0,5,71,0,0,0,0,0,11,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Play Emote 71 (Dragonmaw Peon)"),
-- Only one of them says text and it's not formation leader
(2225201,9,2,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Say Line 1 (Dragonmaw Peon)"),
(2225201,9,3,0,0,0,100,0,3000,3000,0,0,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Play Emote 92"),
(2225201,9,4,0,0,0,100,0,0,0,0,0,0,5,92,0,0,0,0,0,11,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Play Emote 92 (Dragonmaw Peon)"),
(2225201,9,5,0,0,0,100,0,0,0,0,0,0,71,0,0,2202,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Change Equipment"),
(2225201,9,6,0,0,0,100,0,0,0,0,0,0,71,0,0,2202,0,0,0,11,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Change Equipment (Dragonmaw Peon)"),
(2225201,9,7,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,185893,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Despawn Closest Gameobject 'Delicious Mutton'"),
-- Only one of them says text and it's not formation leader
(2225201,9,8,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,19,22252,20,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Say Line 2 (Dragonmaw Peon)"),
(2225201,9,9,0,0,0,100,0,2000,2000,0,0,0,33,23209,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Quest Credit 'A Slow Death'"),
(2225201,9,10,0,0,0,100,0,0,0,0,0,0,86,3617,2,11,22252,20,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Cross Cast 'NPC 32958 suicide spell' (Dragonmaw Peon)"),
(2225201,9,11,0,0,0,100,0,0,0,0,0,0,11,3617,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Script - Cast 'NPC 32958 suicide spell'"),

-- Has condition to execute only if alive, otherwise Set Data may target dead creatures
-- Ideally it must be done by new target param or event flag
-- When we will be able to form formation, we can also use new target to target all formation members
(22252,0,6,7,38,0,100,1,1,1,0,0,0,69,2,0,0,3,0,0,20,185893,0,0,0,0,0,0,0,"Dragonmaw Peon - Data Set 1 1 - Move to Closest Gameobject 'Delicious Mutton' (No Repeat)"),
(22252,0,7,0,61,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Peon - On Link - Set Event Phase 2");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22252 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,7,22252,0,0,36,1,0,0,0,0,0,0,"","Group 0: Execute SAI (Action 6) if creature is alive");

DELETE FROM `creature_text` WHERE `CreatureID` = 22252;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22252,0,0,"For the Dragonmaw!",12,1,100,0,0,0,1937,0,"Dragonmaw Peon"),
(22252,0,1,"Your bones will break under my boot, $r!",12,1,100,0,0,0,1938,0,"Dragonmaw Peon"),
(22252,0,2,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,1939,0,"Dragonmaw Peon"),
(22252,1,0,"Time for eating!?",12,0,100,0,0,0,21118,0,"Dragonmaw Peon"),
(22252,1,1,"Mmmm! FOOD!",12,0,100,0,0,0,21119,0,"Dragonmaw Peon"),
(22252,1,2,"Me so hungry! YUM!",12,0,100,0,0,0,21120,0,"Dragonmaw Peon"),
(22252,1,3,"It put the mutton in the stomach!",12,0,100,0,0,0,21121,0,"Dragonmaw Peon"),
(22252,2,0,"Hey... me not feel so good.",12,0,100,0,0,0,21122,0,"Dragonmaw Peon"),
(22252,2,1,"You is bad orc... baaad... or... argh!",12,0,100,0,0,0,21123,0,"Dragonmaw Peon");

-- Chance to drop of Fel Glands was increased to 100 in WotLK https://www.wowhead.com/quest=11020/a-slow-death#comments:id=573396
UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Item` = 32502 AND `Reference` = 0;
