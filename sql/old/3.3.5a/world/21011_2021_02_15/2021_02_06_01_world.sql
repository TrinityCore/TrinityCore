-- Abandoned Fuel Tank
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 27064;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27064 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27064,0,0,0,63,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Abandoned Fuel Tank - On Just Created - Set Reactstate Passive"),
(27064,0,1,2,31,0,100,1,37814,0,0,0,0,11,47916,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Abandoned Fuel Tank - On Target Spellhit 'Aggro (2 yd pbae)' - Cast 'Fuel' (No Repeat)"),
(27064,0,2,3,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,25334,0,0,0,0,0,0,0,"Abandoned Fuel Tank - On Link - Say Line 0 (Horde Siege Tank)"),
-- No idea what is the original timer but with 1000 mana will be not restored
(27064,0,3,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Abandoned Fuel Tank - On Link - Delayed Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (37814,47916);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,37814,0,0,31,0,3,25334,0,0,0,0,"","Group 0: Spell 'Aggro (2 yd pbae)' (Effect 0) targets creature 'Horde Siege Tank'"),
(13,1,47916,0,0,31,0,3,25334,0,0,0,0,"","Group 0: Spell 'Fuel' (Effect 0) targets creature 'Horde Siege Tank'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 27064 AND `SourceId` = 0;

-- Dream Fog
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 15224;

-- Scourge Sky Darkener
-- Orithos the Sky Darkener
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 28642;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 28647;

-- Supremus Volcano
UPDATE `creature_template` SET `speed_run` = 1.28968279702, `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 23085;

-- Captured Arko'narin
-- Spirit of Trey Lightforge
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 11016;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 11141;
UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `entryorguid` = 11016 AND `source_type` = 0 AND `id` = 5;
UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `entryorguid` = 1101602 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param1` = `action_param1` &~ 2 WHERE `entryorguid` = 1114100 AND `source_type` = 9 AND `id` = 3;
