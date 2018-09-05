-- Kologarn
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=34816 WHERE `entry` IN (32930,33909);
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=133120, `RegenHealth`=0 WHERE `entry` IN (32934,32933,33911,33910);
UPDATE `creature_template` SET `ScriptName`='npc_focused_eyebeam' WHERE `entry` IN (33632,33802);
UPDATE `creature_template_movement` SET `Ground`=1, `Flight`=0, `Rooted`=1 WHERE `CreatureId` IN (32930,33909);
DELETE FROM `creature` WHERE `id`=32930;
DELETE FROM `creature_addon` WHERE `guid`=136762;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=33661;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(33661,0,0,0,1);

DELETE FROM `creature_template_addon` WHERE `entry` IN(32930,33909,32934,32933);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32934,0,0,0,1,0,64651),
(32933,0,0,0,1,0,64651),
(32930,0,0,0,1,0,64651),
(33909,0,0,0,1,0,64651);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=33768;
DELETE FROM `smart_scripts` WHERE `entryorguid`=33768 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33768,0,0,0,0,0,100,2,4000,8000,7000,12000,0,11,63818,0,0,0,0,0,5,0,0,0,0,0,0,0,'Rumble - In Combat - Cast \'Rumble\' (10m)'),
(33768,0,1,0,0,0,100,4,4000,8000,7000,12000,0,11,63978,0,0,0,0,0,5,0,0,0,0,0,0,0,'Rumble - In Combat - Cast \'Stone Nova\' (25m)');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN(63356,63821);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(63356,63356,64003,0,0),
(63821,63821,64001,0,0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=32930;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(32930,32933,0,1,'Kologarn',6,3000),
(32930,32934,1,1,'Kologarn',6,3000);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_kologarn_summon_focused_eyebeam','spell_kologarn_focused_eyebeam_damage');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(63346,'spell_kologarn_focused_eyebeam_damage'),
(63976,'spell_kologarn_focused_eyebeam_damage');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN(5399,5390);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5399,'at_kologarn'),
(5390,'at_kologarn_pit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(63628,63983,63766);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,63628,0,0,31,0,3,32933,0,0,0,0,'','Spell Instakill Kologarn Arm targets Left Arm'),
(13,1,63628,0,1,31,0,3,32934,0,0,0,0,'','Spell Instakill Kologarn Arm targets Right Arm'),
(13,1,63766,0,0,31,0,3,33661,136520,0,0,0,'','Spell Arm Sweep(10m) - Effect 0 - Targets Armsweep Stalker Kologarn'),
(13,1,63983,0,0,31,0,3,33661,136520,0,0,0,'','Spell Arm Sweep(25m) - Effect 0 - Targets Armsweep Stalker Kologarn'),
(13,2,63766,0,0,31,0,3,33661,136519,0,0,0,'','Spell Arm Sweep(10m) - Effect 1 - Targets Armsweep Stalker Kologarn'),
(13,2,63983,0,0,31,0,3,33661,136519,0,0,0,'','Spell Arm Sweep(25m) - Effect 1 - Targets Armsweep Stalker Kologarn');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10286,10099,10290,10133,10285,10095);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10286,10099,10290,10133,10285,10095) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10286,11,0,0,'achievement_if_looks_could_kill'),
(10099,11,0,0,'achievement_if_looks_could_kill'),
(10290,11,0,0,'achievement_rubble_and_roll'),
(10133,11,0,0,'achievement_rubble_and_roll'),
(10285,11,0,0,'achievement_with_open_arms'),
(10095,11,0,0,'achievement_with_open_arms');
