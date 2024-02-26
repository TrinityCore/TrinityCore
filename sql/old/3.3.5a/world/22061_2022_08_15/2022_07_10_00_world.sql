--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_magus_telestra_summon_clones',
'spell_magus_telestra_clone_dies');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47710,'spell_magus_telestra_summon_clones'),
(47711,'spell_magus_telestra_clone_dies'),
(47712,'spell_magus_telestra_clone_dies'),
(47713,'spell_magus_telestra_clone_dies');

DELETE FROM `spell_target_position` WHERE `ID` = 47754;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(47754,0,576,504.742,88.9122,-16.1245,0,11159);

UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72 WHERE `entry` = 26731;


-- Should be 15214 but it has 2 models.
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 2334, `DmgMultiplier1` = 1 WHERE `Id` = 41577;

UPDATE `creature_template` SET `BaseAttackTime` = 2000 WHERE `entry` IN (26928,26929,26930);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26928,26929,26930) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2692800,2692900,2693000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26928,0,0,0,37,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On AI Initialize - Set Invincibility HP 1"),
(26928,0,1,0,11,0,100,0,0,0,0,0,0,11,47705,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Spawn - Cast 'Grand Magus Telestra (Fire) Visual'"),
(26928,0,2,0,2,0,100,1,0,1,0,0,0,80,2692800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - Between 0-1% Health - Run Script (No Repeat)"),
(26928,0,3,0,0,0,100,2,0,0,1600,2400,0,11,47723,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat CMC - Cast 'Scorch'"),
(26928,0,4,0,0,0,100,4,0,0,1600,2400,0,11,56938,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat CMC - Cast 'Scorch'"),
(26928,0,5,0,0,0,100,2,6000,12000,6000,12000,0,11,47721,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Fire Blast'"),
(26928,0,6,0,0,0,100,4,6000,12000,6000,12000,0,11,56939,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Fire Blast'"),

(2692800,9,0,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,23,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Data 0 1 (Summoner)"),
(2692800,9,1,0,0,0,100,0,0,0,0,0,0,28,47705,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Remove Aura 'Grand Magus Telestra (Fire) Visual'"),
(2692800,9,2,0,0,0,100,0,0,0,0,0,0,11,41577,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Transform: Invisible Stalker'"),
(2692800,9,3,0,0,0,100,0,0,0,0,0,0,11,47711,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Telestra Clone Dies (Fire)'"),
(2692800,9,4,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Reactstate Passive"),
(2692800,9,5,0,0,0,100,0,0,0,0,0,0,146,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Uninteractible"),
-- Actually despawn after 3 sec, but aura can't be applied if caster is already destroyed
-- (if clone is just 20 yards away from boss, aura will not be applied, breaking whole encounter)

-- Great, now, as creature can continue cast COMBAT spells while being passive AND THAT IS ACTUALLY PROBABLY CORRECT,
-- but we increased despawn time to 30 sec, hackily silence it, what else we can do
(2692800,9,6,0,0,0,100,0,0,0,0,0,0,11,42201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Eternal Silence'"),
(2692800,9,7,0,0,0,100,0,30000,30000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Despawn"),


(26929,0,0,0,37,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On AI Initialize - Set Invincibility HP 1"),
(26929,0,1,0,11,0,100,0,0,0,0,0,0,11,47704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Spawn - Cast 'Grand Magus Telestra (Arcane) Visual'"),
(26929,0,2,0,2,0,100,1,0,1,0,0,0,80,2692900,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - Between 0-1% Health - Run Script (No Repeat)"),
(26929,0,3,0,0,0,100,0,6000,8000,12000,12000,0,11,47731,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Critter'"),
(26929,0,4,0,0,0,100,0,10000,15000,15000,15000,0,11,47736,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Time Stop'"),

(2692900,9,0,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,23,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Data 0 1 (Summoner)"),
(2692900,9,1,0,0,0,100,0,0,0,0,0,0,28,47704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Remove Aura 'Grand Magus Telestra (Arcane) Visual'"),
(2692900,9,2,0,0,0,100,0,0,0,0,0,0,11,41577,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Transform: Invisible Stalker'"),
(2692900,9,3,0,0,0,100,0,0,0,0,0,0,11,47713,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Telestra Clone Dies (Arcane)'"),
(2692900,9,4,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Reactstate Passive"),
(2692900,9,5,0,0,0,100,0,0,0,0,0,0,146,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Uninteractible"),
(2692900,9,6,0,0,0,100,0,0,0,0,0,0,11,42201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Eternal Silence'"),
(2692900,9,7,0,0,0,100,0,30000,30000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Despawn"),


(26930,0,0,0,37,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On AI Initialize - Set Invincibility HP 1"),
(26930,0,1,0,11,0,100,0,0,0,0,0,0,11,47706,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Spawn - Cast 'Grand Magus Telestra (Frost) Visual'"),
(26930,0,2,0,2,0,100,1,0,1,0,0,0,80,2693000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - Between 0-1% Health - Run Script (No Repeat)"),
(26930,0,3,0,0,0,100,2,0,0,1200,1200,0,11,47729,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat CMC - Cast 'Ice Barb'"),
(26930,0,4,0,0,0,100,4,0,0,1200,1200,0,11,56937,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat CMC - Cast 'Ice Barb'"),
(26930,0,5,0,0,0,100,2,8000,12000,10000,15000,0,11,47727,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Blizzard'"),
(26930,0,6,0,0,0,100,4,8000,12000,10000,15000,0,11,56936,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast 'Blizzard'"),

(2693000,9,0,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,23,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Data 0 1 (Summoner)"),
(2693000,9,1,0,0,0,100,0,0,0,0,0,0,28,47706,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Remove Aura 'Grand Magus Telestra (Frost) Visual'"),
(2693000,9,2,0,0,0,100,0,0,0,0,0,0,11,41577,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Transform: Invisible Stalker'"),
(2693000,9,3,0,0,0,100,0,0,0,0,0,0,11,47712,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Telestra Clone Dies (Frost)'"),
(2693000,9,4,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Reactstate Passive"),
(2693000,9,5,0,0,0,100,0,0,0,0,0,0,146,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Set Uninteractible"),
(2693000,9,6,0,0,0,100,0,0,0,0,0,0,11,42201,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Cast 'Eternal Silence'"),
(2693000,9,7,0,0,0,100,0,30000,30000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Magus Telestra - On Script - Despawn");
