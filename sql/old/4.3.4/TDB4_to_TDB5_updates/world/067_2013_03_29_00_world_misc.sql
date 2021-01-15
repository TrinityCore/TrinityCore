SET @GUID := 61994;

SET @NPC_ELM_BUNNY := 23837;
SET @NPC_ELM_BUNNY_LARGE := 24110;
SET @NPC_ELM_BUNNY_LARGE_001 := 26298;
SET @NPC_AKALI := 28952;
SET @NPC_AKALI_SUBDUER := 28988;
SET @NPC_AKALI_PROPHET := 28996;

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_AKALI,@NPC_AKALI_PROPHET);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_AKALI,0,0,'I''M FREE, LITTLE DRAKKARI. TIME TO PAY FOR YOUR MANY TRESSPASSES!',14,0,100,33,0,771,'Akali'),
(@NPC_AKALI_PROPHET,0,0,'ENOUGH!',14,0,100,15,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,1,0,'And now, Akali, my master will have your blood and I will take some of your power as well!',14,0,100,397,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,2,0,'It is done. Run back to your masters. Run back to Har''koa. Tell her that I am coming!',14,0,100,14,0,0,'Prophet of Akali');

UPDATE `creature_model_info` SET `bounding_radius`=1.041666, `combat_reach`=4.5 WHERE `modelid`=25839;

UPDATE `creature_template` SET `rank`=1, `unit_flags`=33536, `dmg_multiplier`=10 WHERE `entry`=@NPC_AKALI;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_ELM_BUNNY_LARGE,@NPC_AKALI,@NPC_AKALI_SUBDUER);
UPDATE `creature_template` SET `inhabitType`=4 WHERE `entry` IN (@NPC_ELM_BUNNY_LARGE,@NPC_ELM_BUNNY_LARGE_001);
UPDATE `creature_template` SET `faction_A`=2069, `faction_H`=2069, `unit_flags`=33536, `AIName`='SmartAI' WHERE `entry`=@NPC_AKALI_PROPHET;

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (100333,100334,100335,100336);
UPDATE `creature` SET `modelid`=21999 WHERE `id`=@NPC_ELM_BUNNY_LARGE_001;
DELETE FROM `creature` WHERE `guid` IN (@GUID+0,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@GUID+0,@NPC_ELM_BUNNY_LARGE_001,571,1,1,0,6863.839,-4503.26,443.1838,3.926991,300,0,0),
(@GUID+1,@NPC_ELM_BUNNY_LARGE_001,571,1,1,0,6862.341,-4549.724,443.0588,2.286381,300,0,0),
(@GUID+2,@NPC_ELM_BUNNY,571,1,1,11686,6829.338,-4525.157,442.068,3.420845,300,0,0);

DELETE FROM `creature_addon` WHERE `guid` IN (100333,100334,100335,100336);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(100333,0,0,0,1,0,'52855'),
(100334,0,0,0,1,0,'52855'),
(100335,0,0,0,1,0,'52855'),
(100336,0,0,0,1,0,'52855');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=@NPC_AKALI;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6810.893,-4592.669,440.6777,1.299272,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6806.189,-4595.943,440.6777,1.250024,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6822.087,-4599.02,440.6777,1.469111,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6797.534,-4594.82,440.685,1.137566,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6827.478,-4601.454,440.6777,1.543024,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6817.193,-4601.688,440.6777,1.409492,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6834.823,-4602.401,440.6777,1.638796,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6805.295,-4601.961,440.6777,1.263096,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6765.525,-4543.851,440.6777,0.2786701,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6764.082,-4549.868,440.6777,0.3558455,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6765.489,-4564.422,440.6777,0.5454721,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6763.994,-4537.706,440.6782,0.1836674,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6826.999,-4607.5,440.6777,1.539239,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6763.607,-4558.375,440.6785,0.4619856,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6796.735,-4602.545,441.0136,1.167641,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6832.644,-4607.751,440.6777,1.607957,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6810.649,-4609.51,440.6977,1.349023,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6821.64,-4610.604,440.6777,1.477666,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6759.292,-4545.87,440.828,0.2817687,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6758.293,-4555.154,440.7154,0.393915,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6758.89,-4536.409,441.8029,0.152804,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6759.161,-4564.057,440.7889,0.5006734,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6800.313,-4611.478,442.0841,1.242545,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6755.442,-4540.723,441.9008,0.2022173,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6756.493,-4531.063,443.5255,0.07566226,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6754.277,-4551.221,440.8657,0.3288565,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6815.617,-4616.651,440.7146,1.418685,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6753.755,-4559.585,441.2291,0.4221908,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6750.038,-4544.226,441.7151,0.2309312,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6748.174,-4550.871,441.9503,0.301857,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6901.166,-4516.716,440.6777,3.263991,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6904.161,-4525.245,440.6777,3.145305,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6843.423,-4464.692,440.6777,4.488739,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6894.436,-4500.116,440.6777,3.514982,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6908.481,-4530.965,440.6777,3.0727,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6851.518,-4464.19,440.6777,4.368972,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6903.379,-4508.444,440.6777,3.369018,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6862.596,-4466.07,440.6777,4.205543,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6907.354,-4513.603,440.6777,3.293668,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6847.208,-4459.859,440.6799,4.450202,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6901.388,-4500.221,440.6777,3.480376,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6910.758,-4518.518,440.6777,3.22766,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6877.528,-4472.05,440.6777,3.981474,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6906.053,-4501.915,440.6777,3.441033,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6855.152,-4457.84,440.2045,4.351227,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6903.093,-4495.178,440.6777,3.533091,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6871.4,-4463.921,440.6777,4.11605,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6911.422,-4507.554,440.6777,3.357718,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6916.012,-4518.927,440.6807,3.217745,3,100000),
(@NPC_AKALI,0,1,@NPC_AKALI_SUBDUER,6864.756,-4459.202,440.6777,4.224802,3,100000);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (52816,52833,52834,52837,52838,52844,52867,52884);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52816,0,0,31,0,3,@NPC_ELM_BUNNY_LARGE,0,0,0,'','Spell Akali Chain Anchor On Disturb targets ELM General Purpose Bunny Large'),
(13,1,52816,0,1,31,0,3,@NPC_ELM_BUNNY_LARGE_001,0,0,0,'','Spell Akali Chain Anchor On Disturb targets ELM General Purpose Bunny Large'),
(13,1,52833,0,0,31,0,3,@NPC_AKALI,0,0,0,'','Spell Akali''s Chains - Left Front Paw targets Akali'),
(13,1,52834,0,0,31,0,3,@NPC_AKALI,0,0,0,'','Spell Akali''s Chains - Right Front Paw targets Akali'),
(13,1,52837,0,0,31,0,3,@NPC_ELM_BUNNY_LARGE_001,0,0,0,'','Spell Akali''s Chains - Right Rear Paw targets ELM General Purpose Bunny Large'),
(13,1,52837,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Right Rear Paw target distance must be 5y or more'),
(13,1,52838,0,0,31,0,3,@NPC_ELM_BUNNY_LARGE_001,0,0,0,'','Spell Akali''s Chains - Left Rear Paw targets ELM General Purpose Bunny Large'),
(13,1,52838,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Left Rear Paw target distance must be 5y or more'),
(13,1,52844,0,0,31,0,3,@NPC_AKALI,0,0,0,'','Spell Akali''s Chains - Rear Paw Invisible Stun Channel targets Akali'),
(13,1,52867,0,0,31,0,3,@NPC_AKALI_SUBDUER,0,0,0,'','Spell Knockback targets Akali Subduer'),
(13,1,52884,0,0,31,0,3,@NPC_AKALI,0,0,0,'','Spell Drain Power targets Akali');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=52860;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(52860,45254,1,'On spellhit Rampage: Drain Power Effect - Spellcast Suicide');

DELETE FROM `spell_dbc` WHERE `Id`=52867;
INSERT INTO `spell_dbc` (`Id`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`AreaGroupId`,`SchoolMask`,`Comment`) VALUES
(52867,0,0,538968320,525448,67108868,64,2177,0,512,0,0,0,0,1,0,0,101,0,0,0,0,0,1,0,-1,0,0,98,0,0,1,0,0,0,0,0,199,0,0,0,0,0,22,0,0,7,0,0,10,0,0,0,0,0,0,0,0,0,0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,'Knockback');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28575;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-100333,-100334,-100335,-100336,-113548,-113549,-113550,-113551,-(@GUID+0),-(@GUID+1),-(@GUID+2),@NPC_AKALI,@NPC_AKALI_SUBDUER,@NPC_AKALI_PROPHET) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_AKALI*100+0,@NPC_AKALI*100+1,@NPC_AKALI_SUBDUER*100,@NPC_AKALI_PROPHET*100+0,@NPC_AKALI_PROPHET*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-100333,0,0,1,8,0,100,0,52816,0,0,0,45,0,1,0,0,0,0,10,@GUID+2,@NPC_ELM_BUNNY,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Set data 0 1 ELM General Purpose Bunny'),
(-100333,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-100334,0,0,1,8,0,100,0,52816,0,0,0,45,0,1,0,0,0,0,10,@GUID+2,@NPC_ELM_BUNNY,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Set data 0 1 ELM General Purpose Bunny'),
(-100334,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-100335,0,0,1,8,0,100,0,52816,0,0,0,45,0,1,0,0,0,0,10,@GUID+2,@NPC_ELM_BUNNY,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Set data 0 1 ELM General Purpose Bunny'),
(-100335,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-100336,0,0,1,8,0,100,0,52816,0,0,0,45,0,1,0,0,0,0,10,@GUID+2,@NPC_ELM_BUNNY,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Set data 0 1 ELM General Purpose Bunny'),
(-100336,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),

(-113548,0,0,0,38,0,100,0,0,1,0,0,11,52833,0,0,0,0,0,10,98159,@NPC_AKALI,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Akali''s Chains - Left Front Paw'),
(-113548,0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-113549,0,0,0,38,0,100,0,0,1,0,0,11,52834,0,0,0,0,0,10,98159,@NPC_AKALI,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Akali''s Chains - Right Front Paw'),
(-113549,0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-113550,0,0,0,38,0,100,0,0,1,0,0,11,52844,0,0,0,0,0,10,98159,@NPC_AKALI,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Rear Paw Invisible Stun Channel'),
(-113550,0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-113551,0,0,0,38,0,100,0,0,1,0,0,11,52844,0,0,0,0,0,10,98159,@NPC_AKALI,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Rear Paw Invisible Stun Channel'),
(-113551,0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-(@GUID+0),0,0,0,38,0,100,0,0,1,0,0,11,52837,0,0,0,0,0,10,113478,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Akali''s Chains - Right Rear Paw'),
(-(@GUID+0),0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),
(-(@GUID+1),0,0,0,38,0,100,0,0,1,0,0,11,52838,0,0,0,0,0,10,113479,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Akali''s Chains - Left Rear Paw'),
(-(@GUID+1),0,1,0,8,0,100,0,52816,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Chain Anchor On Disturb - Despawn'),

(-(@GUID+2),0,0,1,1,8,100,0,0,0,500,500,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC (phase 4) - Set event phase 0'),
(-(@GUID+2),0,1,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_AKALI,30,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC (phase 4) - Set data 0 1 Akali'),
(-(@GUID+2),0,2,0,38,0,100,0,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Increment event phase'),

(@NPC_AKALI,0,0,0,38,0,100,0,0,1,0,0,80,@NPC_AKALI*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali - On data 0 1 set - Run script 0'),
(@NPC_AKALI,0,1,2,8,0,100,0,52859,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali - On spellhit Submission - Stop regen health'),
(@NPC_AKALI,0,2,3,61,0,100,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali - On spellhit Submission - Set unit_flags IMMUNE_TO_NPC'),
(@NPC_AKALI,0,3,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,6829.587,-4525.521,442.068,0, 'Akali - On spellhit Submission - Move to position'),
(@NPC_AKALI,0,4,0,34,0,100,0,0,1,0,0,80,@NPC_AKALI*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali - On movement inform - Run script 1'),
(@NPC_AKALI,0,5,0,9,0,100,0,0,80,10000,10000,11,52856,0,0,0,0,0,6,0,0,0,0,0,0,0, 'Akali - On target range 10-80y - Spellcast Charge'),
(@NPC_AKALI,0,6,7,11,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali - On spawn - Set faction default'),
(@NPC_AKALI,0,7,8,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,113548,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,8,9,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,113549,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,9,10,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,113550,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,10,11,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,113551,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,11,12,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+0,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,12,13,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+1,@NPC_ELM_BUNNY_LARGE_001,0,0,0,0,0, 'Akali - On spawn - Set data 0 1 ELM General Purpose Bunny'),
(@NPC_AKALI,0,13,14,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101661,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,14,15,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101662,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,15,16,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101663,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,16,17,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101665,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,17,18,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101666,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,18,19,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101667,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,19,20,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101668,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,20,21,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,101669,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,21,22,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203572,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,22,23,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203573,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,23,24,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203574,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,24,25,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203575,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,25,26,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203576,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),
(@NPC_AKALI,0,26,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,203577,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script - On spawn - Set data 0 1 Akali Subduer'),

(@NPC_AKALI_SUBDUER,0,0,0,2,0,100,0,0,50,90000,90000,11,57843,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On health below 50% - Spellcast Mojo Empowered Fire Ward'),
(@NPC_AKALI_SUBDUER,0,1,0,9,0,100,0,25,35,4000,7000,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Akali Subduer - On target range 0-35y - Spellcast Fireball'),
(@NPC_AKALI_SUBDUER,0,2,0,9,0,100,0,0,25,3000,5000,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Akali Subduer - On target range 0-35y - Spellcast Firebolt'),
(@NPC_AKALI_SUBDUER,0,3,4,54,0,100,0,0,0,0,0,2,2102,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - Just summoned - Set faction'),
(@NPC_AKALI_SUBDUER,0,4,5,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - Just summoned - Set unit_flags IMMUNE_TO_PC'),
(@NPC_AKALI_SUBDUER,0,5,6,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - Just summoned - Set run'),
(@NPC_AKALI_SUBDUER,0,6,0,61,0,100,0,0,0,0,0,46,60,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - Just summoned - Move forward'),
(@NPC_AKALI_SUBDUER,0,7,8,31,0,100,0,52859,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On target spellhit Submission - Set homeposition'),
(@NPC_AKALI_SUBDUER,0,8,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On target spellhit Submission - Evade'),
(@NPC_AKALI_SUBDUER,0,9,10,38,0,100,0,0,3,0,0,92,0,0,1,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 3 set - Interrupt spellcast'),
(@NPC_AKALI_SUBDUER,0,10,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 3 set - Stop combat'),
(@NPC_AKALI_SUBDUER,0,11,0,38,0,100,0,0,1,0,0,11,45579,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 1 set - Spellcast Fire Channeling'),
(@NPC_AKALI_SUBDUER,0,12,13,38,0,100,0,0,2,0,0,2,2102,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 2 set - Set faction'),
(@NPC_AKALI_SUBDUER,0,13,0,61,0,100,0,0,0,0,0,92,0,45579,1,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 2 set - Interrupt spellcast'),
(@NPC_AKALI_SUBDUER,0,14,0,38,0,100,0,0,4,0,0,80,@NPC_AKALI_SUBDUER*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer - On data 0 4 set - Run script'),

(@NPC_AKALI_PROPHET,0,0,1,54,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Spellcast Ethereal Teleport'),
(@NPC_AKALI_PROPHET,0,1,0,61,0,100,0,0,0,0,0,1,0,2300,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Say line'),
(@NPC_AKALI_PROPHET,0,2,3,52,0,100,0,0,@NPC_AKALI_PROPHET,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On text over - Set run'),
(@NPC_AKALI_PROPHET,0,3,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,6869.146,-4558.086,443.3982,0, 'Prophet of Akali - On text over - Move to position'),
(@NPC_AKALI_PROPHET,0,4,5,34,0,100,0,0,1,0,0,97,30.7787,0,0,0,0,0,1,0,0,0,6856.265,-4543.67,441.9847,0, 'Prophet of Akali - On movement inform - Jump to position'),
(@NPC_AKALI_PROPHET,0,5,0,61,0,100,0,0,0,0,0,80,@NPC_AKALI_PROPHET*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On WP 1 reached - Run script 0'),
(@NPC_AKALI_PROPHET,0,6,0,38,0,100,0,0,1,0,0,80,@NPC_AKALI_PROPHET*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On data 0 1 set - Run script 1'),

(@NPC_AKALI*100,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali script 0 - Say line'),
(@NPC_AKALI*100,9,1,0,0,0,100,0,0,0,0,0,15,12721,0,0,0,0,0,18,50,0,0,0,0,0,0, 'Akali script 0 - Quest credit'),
(@NPC_AKALI*100,9,2,0,0,0,100,0,0,0,0,0,107,1,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Akali script 0 - Summon creature group'),
(@NPC_AKALI*100,9,3,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101661,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,4,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101662,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,5,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101663,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,6,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101665,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,7,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101666,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,8,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101667,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,9,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101668,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,10,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,101669,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,11,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203572,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,12,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203573,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,13,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203574,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,14,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203575,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,15,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203576,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,16,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,203577,@NPC_AKALI_SUBDUER,0,0,0,0,0, 'Akali script 0 - Set data 0 2 Akali Subduer'),
(@NPC_AKALI*100,9,17,0,0,0,100,0,4600,4600,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali script - Remove unit_flags IMMUNE_TO_NPC'),
(@NPC_AKALI*100,9,18,0,0,0,100,0,55000,55000,0,0,12,@NPC_AKALI_PROPHET,8,0,0,0,0,8,0,0,0,6882.029,-4571.001,442.3118,2.373648, 'Akali script - Summon Akali Prophet'),

(@NPC_AKALI*100+1,9,0,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali script 1 - Set faction'),
(@NPC_AKALI*100+1,9,1,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali script 1 - Evade'),
(@NPC_AKALI*100+1,9,2,0,0,0,100,0,200,200,0,0,66,0,0,0,0,0,0,19,@NPC_AKALI_PROPHET,100,0,0,0,0,0, 'Akali script 1 - Turn to'),
(@NPC_AKALI*100+1,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_AKALI_PROPHET,100,0,0,0,0,0, 'Akali script 1 - Set data 0 1 Prophet of Akali'),

(@NPC_AKALI_SUBDUER*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_AKALI_PROPHET,100,0,0,0,0,0, 'Akali Subduer script - Turn to'),
(@NPC_AKALI_SUBDUER*100,9,1,0,0,0,100,0,10000,10000,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,2,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,3,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,4,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,5,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,6,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,7,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,8,0,0,0,100,0,1000,1200,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Play emote'),
(@NPC_AKALI_SUBDUER*100,9,9,0,0,0,100,0,1000,1200,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akali Subduer script - Despawn'),

(@NPC_AKALI_PROPHET*100+0,9,0,0,0,0,100,0,0,0,0,0,45,0,3,0,0,0,0,9,@NPC_AKALI_SUBDUER,0,100,0,0,0,0, 'Prophet of Akali script - Set data 0 4 Akali Subduer'), 
(@NPC_AKALI_PROPHET*100+0,9,1,0,0,0,100,0,1000,1000,0,0,11,52859,0,0,0,0,0,19,@NPC_AKALI,100,0,0,0,0,0, 'Prophet of Akali script - Spellcast Submission'), 

(@NPC_AKALI_PROPHET*100+1,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script - Say line'),
(@NPC_AKALI_PROPHET*100+1,9,1,0,0,0,100,0,4700,4700,0,0,11,52884,0,0,0,0,0,19,@NPC_AKALI,50,0,0,0,0,0, 'Prophet of Akali script - Spellcast Drain Power'),
(@NPC_AKALI_PROPHET*100+1,9,2,0,0,0,100,0,0,0,0,0,45,0,4,0,0,0,0,9,@NPC_AKALI_SUBDUER,0,100,0,0,0,0, 'Prophet of Akali script - Set data 0 3 Akali Subduer'),
(@NPC_AKALI_PROPHET*100+1,9,3,0,0,0,100,0,11600,11600,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script - Say line'),
(@NPC_AKALI_PROPHET*100+1,9,4,0,0,0,100,0,3500,3500,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script - Spellcast Ethereal Teleport'),
(@NPC_AKALI_PROPHET*100+1,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script - Despawn');
