-- Basically same concept as for Abandoned Fuel Tank
-- Spell 54541 is not shown in sniffs since it's not aura, may be shown in lower build
-- Effects of 54541 & 54542 simply copied from 37815 and 37814. EffectAmplitude1 may be different, who knows, hard to check
-- Looks like there are static spawns, well, they share same script as summoned by player
-- Not sure if we should change something in the way credit is awarded, current implementation looks a little bit weird
UPDATE `creature_template_addon` SET `auras` = '54542' WHERE `entry` = 29475;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29475 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29475,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Improved Land Mine - On AI Initialize - Set Reactstate Passive"),
(29475,0,1,2,31,0,100,1,54541,0,0,0,0,11,54537,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Improved Land Mine - On Target Spellhit 'Aggro (5 yd pbae)' - Cast 'Detonation' (No Repeat)"),
(29475,0,2,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Improved Land Mine - On Target Spellhit 'Aggro (5 yd pbae)' - Delayed Despawn"),
(29475,0,3,0,5,0,100,0,0,0,0,29618,0,11,54693,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Improved Land Mine - On Killed Unit - Cast 'Garm Attacker Kill Credit'"),
(29475,0,4,0,5,0,100,0,0,0,0,29619,0,11,54693,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Improved Land Mine - On Killed Unit - Cast 'Garm Attacker Kill Credit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 54541;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,54541,0,0,31,0,3,29618,0,0,0,0,"","Group 0: Spell 'Aggro (5 yd pbae)' (Effect 0) targets creature 'Snowblind Follower'"),
(13,1,54541,0,1,31,0,3,29619,0,0,0,0,"","Group 1: Spell 'Aggro (5 yd pbae)' (Effect 0) targets creature 'Garm Invader'");

UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 23, `EffectAmplitude1` = 500, `EffectTriggerSpell1` = 54541, `DmgMultiplier1` = 1 WHERE `ID` = 54542;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 3, `EffectImplicitTargetA1` = 22, `EffectImplicitTargetB1` = 15, `EffectRadiusIndex1` = 8, `DmgMultiplier1` = 1 WHERE `ID` = 54541;
