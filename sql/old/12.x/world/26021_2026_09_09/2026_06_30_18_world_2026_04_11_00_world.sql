-- Morogrim
UPDATE `creature_template` SET `speed_run` = 2.14286, `BaseAttackTime` = 1600 WHERE `entry` = 21213;
UPDATE `creature_model_info` SET `BoundingRadius` = 6.315, `CombatReach` = 6 WHERE `DisplayID` = 20739;

UPDATE `creature_text` SET `Type` = 41 WHERE `CreatureID` = 21213 AND `GroupID` IN (5,7);

UPDATE `creature` SET `position_x` = 370.829, `position_y` = -723.939, `position_z` = -14.005, `orientation` = 2.93215 WHERE `id` = 21213;

-- Murlocs
DELETE FROM `spell_target_position` WHERE `ID` IN (37766,37923,37925,37926,37927,39813,39814,39815,39816,39817,37772,37928,37929,37931,37932,39818,39819,39820,39821,39822);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(37766,0,548,266,-707,-2.91667,5.34071,0),
(37925,0,548,260,-712,-2.91667,5.34071,0),
(37927,0,548,254,-719,-2.91667,5.34071,0),
(39814,0,548,260,-704,-2.91667,5.11381,0),
(39816,0,548,253,-707,-2.91667,5.2709,0),
(39817,0,548,250,-708,-2.91667,5.14872,0),

(37928,0,548,528,-699,-6.91667,3.9968,0),
(37931,0,548,534,-706,-6.91667,3.9968,0),
(39818,0,548,540,-700,-6.91667,4.32842,0),
(39820,0,548,535,-695,-6.91667,4.01426,0),
(39821,0,548,533,-691,-6.91667,4.31096,0),
(39822,0,548,529,-691,-6.91667,4.31096,0);

UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857 WHERE `entry` = 21920;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21920 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21920,0,0,0,37,0,100,0,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tidewalker Lurker - On AI Initialize - Set Corpse Delay"),
(21920,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,41932,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Tidewalker Lurker - In Combat - Cast 'Carnivorous Bite'");

-- Watery Grave (first is sniffed, other copied from Water Globule spells)
UPDATE `spell_target_position` SET `PositionX` = 334, `PositionY` = -728, `PositionZ` = -14, `Orientation` = 0, `VerifiedBuild` = 26365 WHERE `ID` = 37850;
UPDATE `spell_target_position` SET `PositionX` = 366, `PositionY` = -736, `PositionZ` = -14, `Orientation` = 2.513274 WHERE `ID` = 38023;
UPDATE `spell_target_position` SET `PositionX` = 366, `PositionY` = -709, `PositionZ` = -14, `Orientation` = 2.513274 WHERE `ID` = 38024;
UPDATE `spell_target_position` SET `PositionX` = 372, `PositionY` = -690, `PositionZ` = -14, `Orientation` = 4.258604 WHERE `ID` = 38025;

-- Water Globule
UPDATE `spell_target_position` SET `PositionX` = 334, `PositionY` = -728, `PositionZ` = -14, `Orientation` = 0, `VerifiedBuild` = 26365 WHERE `ID` = 37854;
UPDATE `spell_target_position` SET `PositionX` = 366, `PositionY` = -736, `PositionZ` = -14, `Orientation` = 2.513274, `VerifiedBuild` = 26365 WHERE `ID` = 37858;
UPDATE `spell_target_position` SET `PositionX` = 366, `PositionY` = -709, `PositionZ` = -14, `Orientation` = 2.513274, `VerifiedBuild` = 26365 WHERE `ID` = 37860;
UPDATE `spell_target_position` SET `PositionX` = 372, `PositionY` = -690, `PositionZ` = -14, `Orientation` = 4.258604, `VerifiedBuild` = 26365 WHERE `ID` = 37861;

UPDATE `creature_template` SET `speed_walk` = 0.4, `speed_run` = 0.285714 WHERE `entry` = 21913;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_morogrim_tidewalker_watery_grave',
'spell_morogrim_tidewalker_summon_water_globules');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38028, 'spell_morogrim_tidewalker_watery_grave'),
(37866, 'spell_morogrim_tidewalker_summon_water_globules');
