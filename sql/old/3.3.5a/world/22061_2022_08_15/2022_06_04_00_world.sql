--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_fjord_the_way_to_his_heart_reverse_cast','spell_fjord_the_way_to_his_heart_quest_complete','spell_gen_pet_wait');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(44455,'spell_fjord_the_way_to_his_heart_reverse_cast'),
(44462,'spell_fjord_the_way_to_his_heart_quest_complete'),
(36553,'spell_gen_pet_wait');

-- Bull
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24786 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2478600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24786,0,0,0,8,0,100,0,44454,0,0,0,0,80,2478600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Bull - On Spellhit 'Tasty Reef Fish' - Run Script"),
(24786,0,1,0,1,0,100,0,30000,60000,30000,60000,0,4,3403,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Bull - Out of Combat - Play Sound 3403"),
-- Call for Help?
(24786,0,2,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Bull - On Aggro - Say Line 0"),

(2478600,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Bull - On Script - Set Orientation Invoker"),
(2478600,9,1,0,0,0,100,0,0,0,0,0,0,11,44455,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Bull - On Script - Cast 'Character Script Effect Reverse Cast'"),
(2478600,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Bull - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = 24786;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24786,0,0,"A Lion Seal has become alerted to your presence and begins bellowing a warning!",16,0,100,0,0,0,22437,0,"Reef Bull");

-- Attracted Bull
UPDATE `creature_template` SET `speed_run` = 1, `unit_flags` = 32768 WHERE `entry` = 24804;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24804;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24804 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2480400,2480401,2480402) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24804,0,0,0,11,0,100,0,0,0,0,0,0,80,2480400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Spawn - Run Script"),
(24804,0,1,0,8,0,100,0,44454,0,0,0,0,80,2480401,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Spellhit 'Tasty Reef Fish' - Run Script"),
-- Interrupting previous action list here is a good idea (see comment below) but it gives a weird side-effect
-- (creature despawns a bit longer than 12 sec (last action in this action list))
(24804,0,2,0,8,0,100,0,44453,0,0,0,0,80,2480402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Spellhit 'Reef Cow Aura' - Run Script"),

(2480400,9,0,0,0,0,100,0,0,0,0,0,0,4,3403,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Play Sound 3403"),
(2480400,9,1,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Follow Owner"),
-- It looks weird and unnecessary here since they can simply add timer to follow action, maybe it's not this simple
-- It wasn't used last time when he got attention from a cow, was interrupted by next action list
(2480400,9,2,0,0,0,100,0,3000,3000,0,0,0,11,36553,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Cast 'PetWait'"),

(2480401,9,0,0,0,0,100,0,0,0,0,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Play Emote 35"),
(2480401,9,1,0,0,0,100,0,0,0,0,0,0,4,3403,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Play Sound 3403"),
(2480401,9,2,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Follow Invoker"),
(2480401,9,3,0,0,0,100,0,3000,3000,0,0,0,11,36553,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Cast 'PetWait'"),

(2480402,9,0,0,0,0,100,0,0,0,0,0,0,11,44462,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Cast 'Cast Quest Complete on Master'"),
(2480402,9,1,0,0,0,100,0,0,0,0,0,0,11,44460,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Cast 'True Love'"),
(2480402,9,2,0,0,0,100,0,0,0,0,0,0,4,3403,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Play Sound 3403"),
(2480402,9,3,0,0,0,100,0,0,0,0,0,0,69,0,0,0,2,0,0,7,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Move To Invoker"),
(2480402,9,4,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,7,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Set Data 0 1 (Invoker)"),
(2480402,9,5,0,0,0,100,0,12000,12000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Attracted Reef Bull - On Script - Despawn");

-- Cow
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '44476' WHERE `entry` = 24797;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24797 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2479700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24797,0,0,0,1,0,100,0,30000,60000,30000,60000,0,4,3403,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - Out of Combat - Play Sound 3403"),
(24797,0,1,0,38,0,100,0,0,1,0,0,0,80,2479700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - On Data Set 0 1 - Run Script"),

(2479700,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Set Orientation Invoker"),
(2479700,9,1,0,0,0,100,0,0,0,0,0,0,11,44460,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Cast 'True Love'"),
(2479700,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Say Line 0"),
(2479700,9,3,0,0,0,100,0,0,0,0,0,0,144,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Set ImmunePC"),
(2479700,9,4,0,0,0,100,0,3000,3000,0,0,0,4,3405,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Play Sound 3405"),
(2479700,9,5,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Set Orientation Invoker"),
(2479700,9,6,0,0,0,100,0,9000,9000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reef Cow - On Script - Despawn");

-- 44476 (Reef Cow Periodic) is the aura always applied on cows (sniff)
-- 44453 (Reef Cow Aura) apparently is the spell which periodically triggers aura above
-- RangeIndex of 44453 (Self) and spell name makes it confusing a bit but we have similar spells, like 27999 + 28000
-- So we'll just copy existing combination
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 23, `EffectAmplitude1` = 2000, `EffectTriggerSpell1` = 44453 WHERE `Id` = 44476;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 3, `EffectImplicitTargetA1` = 22, `EffectImplicitTargetB1` = 7, `EffectRadiusIndex1` = 13 WHERE `Id` = 44453;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 44453;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,44453,0,0,31,0,3,24804,0,0,0,0,"","Group 0: Spell 'The Way to His Heart...: Reef Cow Aura' (Effect 0) targets creature 'Attracted Reef Bull'");
