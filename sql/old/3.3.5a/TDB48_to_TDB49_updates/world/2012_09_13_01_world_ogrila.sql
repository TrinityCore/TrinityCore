-- Quest support for http://www.wowhead.com/quest=11010 "Bombing Run", http://www.wowhead.com/quest=11102 "Bombing Run" /druid/ and http://www.wowhead.com/quest=11023 "Bomb Them Again!"
-- Achievement support for http://www.wowhead.com/achievement=1282 and http://www.wowhead.com/achievement=1276,
-- Based on Warpten Script
SET @SKYGUARD_BOMB       := 32456;
SET @Run_Dummy           := 23118;
SET @Explosion_Bunny     := 23119;
SET @Flak_Cannon         := 23076;
SET @Flak_Cannon2        := 23082;
SET @Fel_Cannon_Dummy    := 23077;
SET @RUN_MARK            := 40196;
SET @THROW_BOMB          := 40160;
SET @EXPLOSION_VISUAL    := 40162;
SET @See_Invisibility    := 40195;
SET @Invisibility        := 40194;
SET @CANNONBALL_STACK   := 185861;
-- Add class requirements for druid version of "Bombing Run"
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id`=11102;
-- Add SAI support for Bombing Run Target Dummy
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128 WHERE `entry`=@Run_Dummy;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Run_Dummy;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Run_Dummy;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Run_Dummy*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Run_Dummy,0,0,1,8,0,100,0,@THROW_BOMB,0,1000,1000,33,@Run_Dummy,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Run Target Dummy - On spell Throw Bomb hit - Give kill credit to invoker party'),
(@Run_Dummy,0,1,2,61,0,100,0,0,0,0,0,28,@RUN_MARK,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Run Target Dummy - Linked with previous event - Remove auras from hunter mark'),
(@Run_Dummy,0,2,3,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,@CANNONBALL_STACK,3,0,0,0,0,0, 'Run Target Dummy - Linked with previous event - Data set 0 1 on Cannonball Stack'),
(@Run_Dummy,0,3,4,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@Explosion_Bunny,3,0,0,0,0,0, 'Run Target Dummy - Linked with previous event - Data set 0 1 on Explosion Bunny'),
(@Run_Dummy,0,4,0,61,0,100,0,0,0,0,0,80,@Run_Dummy*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Run Target Dummy - Linked with previous event - Start script 0'),
(@Run_Dummy*100,9,0,0,0,0,100,0,29000,29000,0,0,11,@RUN_MARK,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Run Target Dummy - Action 0 - Cast run mark on self');
-- Add SAI for Cannonball Stack
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@CANNONBALL_STACK;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@CANNONBALL_STACK;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CANNONBALL_STACK,1,0,0,38,0,100,0,0,1,0,0,70,30,0,0,0,0,0,1,0,0,0,0,0,0,0,' Cannonball Stack - On data set 0 1 - Respawn object /make it reappear after 30 secs/');
-- Add SAI support for Bombing Run Fel Cannon Dummy
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=4,`flags_extra`=`flags_extra`|128 WHERE `entry`=@Fel_Cannon_Dummy;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Fel_Cannon_Dummy;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Fel_Cannon_Dummy,0,0,0,8,0,100,0,40110,0,4350,5000,11,40119,0,0,0,0,0,19,@Flak_Cannon,5,0,0,0,0,0, 'Fel Cannon Dummy - On spell hit by Cannon trigger - Cast Aggro Burst on Flak Cannon');
-- Add SAI support for Bombing Run Flak Cannon
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=`unit_flags`|4|256|131072,`flags_extra`=`flags_extra`|2 WHERE `entry`=@Flak_Cannon;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Flak_Cannon;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Flak_Cannon,0,0,0,25,0,100,0,0,0,0,0,11,40111,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Flak Cannon - On reset - Cast The Aggro Bunnies'),
(@Flak_Cannon,0,1,2,8,0,100,0,41598,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Flak Cannon - On hit by Bolt Pair - Set orientation to invoker'),
(@Flak_Cannon,0,2,0,61,0,100,0,0,0,0,0,11,40109,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Flak Cannon - Linked with previous event - Cast spell The Bolt');
-- Add SAI support for Bombing Run Flak Cannon 2 /target bunny/
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128,`InhabitType`=4 WHERE `entry`=@Flak_Cannon2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Flak_Cannon2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Flak_Cannon2,0,0,0,54,0,100,0,0,0,0,0,11,41598,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Flak Cannon 2 - On just summoned - Cast The Bolt Pair on invoker'),
(@Flak_Cannon2,0,1,2,8,0,100,0,40109,0,0,0,11,40075,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Flak Cannon 2 - On spell hit Cannon Bolt - Cast on self Fel Flak Fire'),
(@Flak_Cannon2,0,2,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Flak Cannon 2 - Linked with previous event - Despawn in 5 sec');
-- Add SAI support for Explosion Bunny
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128,`unit_flags`=0 WHERE `entry`=@Explosion_Bunny;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Explosion_Bunny;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Explosion_Bunny,0,0,0,38,0,100,0,0,1,0,0,11,@EXPLOSION_VISUAL,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Explosion Bunny - On data set 0 1 - Cast Explosion Visual on self');
-- Add conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@THROW_BOMB,40110,40112,40075);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (@THROW_BOMB,40200,41598,40111);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@Fel_Cannon_Dummy;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Comment`) VALUES
(17,0,@THROW_BOMB,0,29,0,@Run_Dummy,35,0,0,0,'Throw Bomb requires Run Target Dummy within 35y'),
(13,1,@THROW_BOMB,0,31,0,3,@Run_Dummy,0,0,0,'Throw Bomb implicit effect 0 can hit only Run Target Dummy'),
(13,1,@THROW_BOMB,0,1,0,@RUN_MARK,0,0,0,0,'Throw Bomb can hit only targets under the aura of 40196'),
(17,0,40200,0,9,0,11010,0,0,1,0,'To cast remove see invisibility player must not be on quest 11010'),
(17,0,40200,0,9,0,11102,0,0,1,0,'To cast remove see invisibility player must not be on quest 11102'),
(17,0,40200,0,9,0,11023,0,0,1,0,'To cast remove see invisibility player must not be on quest 11023'),
(13,1,40110,0,31,0,3,23077,0,0,0,'Cannon Trigger implicit targets can be only Fel Cannon Dummies'),
(13,1,40110,0,35,0,1,65,2,0,0,'Cannon Trigger implicit hit can happen only on targets under 65 yards range'),
(17,0,40111,0,29,0,@Fel_Cannon_Dummy,10,0,1,0,'The Aggro Bunnies caster should not be around Fel Cannon Dummies to cast'),
(13,1,40112,0,31,0,4,0,0,0,0,'Bombing Run Dummy aggro check can hit players'),
(13,3,40075,0,31,0,4,0,0,0,0,'Fel Flak Fire effect 2 can hit only players'),
(22,1,@Fel_Cannon_Dummy,0,1,1,40119,0,0,1,0,'Fel Cannon Dummy event 0 will happen only if target is missing aura from aggro burst');
-- Insert addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (@Run_Dummy,@Explosion_Bunny,@Fel_Cannon_Dummy);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Run_Dummy,0,0,0,0,'40196 40194 40195'), -- Mark, See Invisibility, Invisibility
(@Explosion_Bunny,0,0,0,0,'40194 40195'), -- See Invisibility, Invisibility
(@Fel_Cannon_Dummy,0,0,0,0,'40113'); -- The Aggro Check Aura
-- Remove achievement from disabled
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=3923;
-- Add missing spell from dbc
DELETE FROM `spell_dbc` WHERE `Id`=40200;
INSERT INTO `spell_dbc` (`Id`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`AreaGroupId`,`SchoolMask`,`Comment`) VALUES
(40200,0,0,256,0,0,0,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,26,1,0,-1,0,0,164,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40195,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,'Bombing Run: See Invisibility Aura Remover');
-- Spell area - Check to cast remove aura /against see invisibility aura/, if having it and not on quest
DELETE FROM `spell_area` WHERE `spell`=40200;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(40200,3522,0,0,0,@See_Invisibility,0,2,1);
-- Insert cannonballs spawns /based on sniffs/
SET @guid := 14811;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @guid+0 AND @guid+13;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@guid+0,@CANNONBALL_STACK,530,1,1,2825.11,7024.05,369.982,5.69617,0,0,0.289313,-0.957235,300,0,1),
(@guid+1,@CANNONBALL_STACK,530,1,1,2938.26,7094.72,369.413,2.78314,0,0,0.983982,0.178267,300,0,1),
(@guid+2,@CANNONBALL_STACK,530,1,1,2924.84,7031.46,367.857,4.26205,0,0,0.847134,-0.53138,300,0,1),
(@guid+3,@CANNONBALL_STACK,530,1,1,2938.02,7015.59,365.75,3.65778,0,0,0.966879,-0.255237,300,0,1),
(@guid+4,@CANNONBALL_STACK,530,1,1,2998.57,7043.55,368.539,5.91266,0,0,0.184206,-0.982888,300,0,1),
(@guid+5,@CANNONBALL_STACK,530,1,1,2982,7054.94,368.32,4.99766,0,0,0.599411,-0.800442,300,0,1),
(@guid+6,@CANNONBALL_STACK,530,1,1,2978.73,6889.19,369.701,0.689745,0,0,0.338077,0.941119,300,0,1),
(@guid+7,@CANNONBALL_STACK,530,1,1,2941.56,6827.17,367.3,4.08109,0,0,0.891683,-0.452661,300,0,1),
(@guid+8,@CANNONBALL_STACK,530,1,1,2953.55,6859.3,369.954,6.14433,0,0,0.0693712,-0.997591,300,0,1),
(@guid+9,@CANNONBALL_STACK,530,1,1,3023.13,6799.74,374.46,1.58666,0,0,0.712695,0.701474,300,0,1),
(@guid+10,@CANNONBALL_STACK,530,1,1,3028.3,6824.84,373.591,5.0275,0,0,0.587401,-0.809296,300,0,1),
(@guid+11,@CANNONBALL_STACK,530,1,1,3022.15,6859.05,369.546,3.44885,0,0,0.988222,-0.153025,300,0,1),
(@guid+12,@CANNONBALL_STACK,530,1,1,3016.28,6876.11,370.188,3.47791,0,0,0.985895,-0.167365,300,0,1),
(@guid+13,@CANNONBALL_STACK,530,1,1,2940.6,7106.65,370.123,0.88561,0,0,0.428475,0.903553,300,0,1);
-- Insert spawns for Fel Flak Cannons, Run Target Dummies and Explosion Bunnies /based on sniffs/
SET @guid := 85656;
DELETE FROM `creature` WHERE `guid` BETWEEN @guid+0 AND @guid+44;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@guid+0,23118,530,1,1,0,0,2764.71,7024.45,370.203,0,300,0,0,42,0,0,0,33554432,0),
(@guid+1,23119,530,1,1,0,0,2764.71,7024.45,370.203,0,300,0,0,6986,0,0,0,33554432,0),
(@guid+2,23118,530,1,1,0,0,2786.61,7036.28,370.686,0,300,0,0,42,0,0,0,33554432,0),
(@guid+3,23119,530,1,1,0,0,2786.61,7036.28,370.686,0,300,0,0,6986,0,0,0,33554432,0),
(@guid+4,23118,530,1,1,0,0,2824.71,7044.79,369.877,0,300,0,0,42,0,0,0,33554432,0),
(@guid+5,23119,530,1,1,0,0,2824.71,7044.79,369.877,0,300,0,0,6986,0,0,0,33554432,0),
(@guid+6,23076,530,1,1,0,0,2775.81,7030.75,370.337,1.85606,300,0,0,22140,0,0,0,0,0),
(@guid+7,23076,530,1,1,0,0,2933.28,7103.93,369.209,2.58129,300,0,0,21543,0,0,0,0,0),
(@guid+8,23119,530,1,1,0,0,2940.82,7107.17,370.115,4.65944,300,0,0,6986,0,0,0,33554432,0),
(@guid+9,23118,530,1,1,0,0,2940.82,7107.17,370.115,4.65944,300,0,0,42,0,0,0,33554432,0),
(@guid+10,23118,530,1,1,0,0,2825.11,7024.05,369.982,5.69617,300,0,0,42,0,0,0,33554432,0),
(@guid+11,23119,530,1,1,0,0,2825.11,7024.05,369.982,5.69617,300,0,0,6986,0,0,0,33554432,0),
(@guid+12,23076,530,1,1,0,0,2834.14,7018.43,368.459,5.42992,300,0,0,21543,0,0,0,0,0),
(@guid+13,23119,530,1,1,0,0,2938.84,7094.48,371.493,0.242375,300,0,0,6986,0,0,0,33554432,0),
(@guid+14,23118,530,1,1,0,0,2938.84,7094.48,371.493,0.242375,300,0,0,42,0,0,0,33554432,0),
(@guid+15,23076,530,1,1,0,0,2925.49,7021.72,367.007,3.59446,300,0,0,22140,0,0,0,0,0),
(@guid+16,23119,530,1,1,0,0,2924.84,7031.46,367.857,4.26205,300,0,0,6986,0,0,0,33554432,0),
(@guid+17,23118,530,1,1,0,0,2924.84,7031.46,367.857,4.26205,300,0,0,42,0,0,0,33554432,0),
(@guid+18,23119,530,1,1,0,0,2938.02,7015.59,366.54,3.65778,300,0,0,6986,0,0,0,33554432,0),
(@guid+19,23118,530,1,1,0,0,2938.02,7015.59,366.54,3.65778,300,0,0,42,0,0,0,33554432,0),
(@guid+20,23076,530,1,1,0,0,2994.48,7039.91,369.42,5.26077,300,0,0,22140,0,0,0,0,0),
(@guid+21,23119,530,1,1,0,0,2998.57,7043.55,368.539,5.91266,300,0,0,6986,0,0,0,33554432,0),
(@guid+22,23118,530,1,1,0,0,2998.57,7043.55,368.539,5.91266,300,0,0,42,0,0,0,33554432,0),
(@guid+23,23119,530,1,1,0,0,2982,7054.94,368.82,4.99766,300,0,0,6986,0,0,0,33554432,0),
(@guid+24,23118,530,1,1,0,0,2982,7054.94,368.82,4.99766,300,0,0,42,0,0,0,33554432,0),
(@guid+25,23076,530,1,1,0,0,2982.59,6886.5,370.082,0.831123,300,0,0,22140,0,0,0,0,0),
(@guid+26,23118,530,1,1,0,0,2978.74,6889.12,371.288,0.897875,300,0,0,42,0,0,0,33554432,0),
(@guid+27,23119,530,1,1,0,0,2978.74,6889.12,371.288,0.897875,300,0,0,6986,0,0,0,33554432,0),
(@guid+28,23118,530,1,1,0,0,2941.56,6827.17,367.3,4.54054,300,0,0,42,0,0,0,33554432,0),
(@guid+29,23119,530,1,1,0,0,2941.56,6827.17,367.3,4.54054,300,0,0,6986,0,0,0,33554432,0),
(@guid+30,23076,530,1,1,0,0,2938.19,6818.01,366.959,3.31926,300,0,0,21543,0,0,0,0,0),
(@guid+31,23076,530,1,1,0,0,2946.3,6875.71,370.04,3.2148,300,0,0,22140,0,0,0,0,0),
(@guid+32,23118,530,1,1,0,0,2953.55,6859.3,369.954,6.14433,300,0,0,42,0,0,0,33554432,0),
(@guid+33,23119,530,1,1,0,0,2953.55,6859.3,369.954,6.14433,300,0,0,6986,0,0,0,33554432,0),
(@guid+34,23119,530,1,1,0,0,3023.13,6799.74,374.46,1.58666,300,0,0,6986,0,0,0,33554432,0),
(@guid+35,23118,530,1,1,0,0,3023.13,6799.74,374.46,1.58666,300,0,0,42,0,0,0,33554432,0),
(@guid+36,23076,530,1,1,0,0,3028.22,6807.09,374.075,5.94641,300,0,0,22140,0,0,0,0,0),
(@guid+37,23118,530,1,1,0,0,3028.3,6824.84,373.591,5.0275,300,0,0,42,0,0,0,33554432,0),
(@guid+38,23119,530,1,1,0,0,3028.3,6824.84,373.591,5.0275,300,0,0,6986,0,0,0,33554432,0),
(@guid+39,23119,530,1,1,0,0,3022.15,6859.05,369.546,3.44885,300,0,0,6986,0,0,0,33554432,0),
(@guid+40,23118,530,1,1,0,0,3022.15,6859.05,369.546,3.44885,300,0,0,42,0,0,0,33554432,0),
(@guid+41,23076,530,1,1,0,0,3022.21,6864.61,369.93,0.100696,300,0,0,22140,0,0,0,0,0),
(@guid+42,23118,530,1,1,0,0,3016.28,6876.11,370.188,3.47791,300,0,0,42,0,0,0,33554432,0),
(@guid+43,23119,530,1,1,0,0,3016.28,6876.11,370.188,3.47791,300,0,0,6986,0,0,0,33554432,0),
(@guid+44,23076,530,1,1,0,0,2816.74,7057.61,369.779,1.4555,300,0,0,21543,0,0,0,0,0);
