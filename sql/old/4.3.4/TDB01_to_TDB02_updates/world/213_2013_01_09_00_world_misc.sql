SET @GUID := 43491;
SET @OGUID := 16964;
SET @NPC_ELM_BUNNY := 23837;
SET @NPC_HARKOA := 28401;
SET @NPC_KHUFU := 28479;
SET @NPC_QUETZLUN_PROPHET := 28671;
SET @NPC_QUETZLUN_SPIRIT := 28785;
SET @NPC_DRAINED_PROPHET := 28795;

DELETE FROM `spell_dbc` WHERE `Id`=25900;
INSERT INTO `spell_dbc` (`Id`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`AreaGroupId`,`SchoolMask`,`Comment`) VALUES
(25900,0,0,256,268435456,0,0,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,21,1,0,-1,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Stun Self');

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid`=97576;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@GUID,@NPC_HARKOA,571,1,1,0,5746.506,-3608.833,387.1909,1.396263,300,0,0);

DELETE FROM `gameobject` WHERE `guid` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,190736,571,1,1,5335.713,-3770.941,371.7576,4.677484,0,0,-0.7193394,0.6946588,-30,255,0),
(@OGUID+1,190737,571,1,1,5329.674,-3770.804,371.3612,0.2617982,0,0,0.1305256,0.9914449,-30,255,0),
(@OGUID+2,190738,571,1,1,5332.682,-3770.142,371.5185,1.815142,0,0,0.7880106,0.6156617,-30,255,0),
(@OGUID+3,190738,571,1,1,5336.708,-3774.066,371.4286,4.415683,0,0,-0.8038568,0.5948228,-30,255,0),
(@OGUID+4,190737,571,1,1,5335.804,-3777.733,371.3452,2.565632,0,0,0.9588194,0.2840165,-30,255,0),
(@OGUID+5,190738,571,1,1,5711.15,-4361.727,385.8019,1.762782,0,0,0.7716246,0.6360782,-30,255,0),
(@OGUID+6,190737,571,1,1,5725.948,-4372.56,386.2328,0.122173,0,0,0.06104851,0.9981348,-30,255,0),
(@OGUID+7,190736,571,1,1,5707.201,-4371.69,385.8015,2.670348,0,0,0.9723692,0.2334484,-30,255,0),
(@OGUID+8,190737,571,1,1,5721.946,-4361.917,385.7987,1.151916,0,0,0.5446386,0.8386708,-30,255,0),
(@OGUID+9,190737,571,1,1,5717.053,-4378.755,385.8015,0.05235888,0,0,0.02617645,0.9996573,-30,255,0);

UPDATE `gameobject_template` SET `flags`=4 WHERE `entry` IN (188260,188262,188263,188345,188351,188461,188499,188518,188525,188530,188600,188601,188670,188691,190208,190223,190399,190534,190537,190540,190541,190542,190543,191780,191781,191782,191783);

UPDATE `creature_addon` SET `auras`='25900 51666 52485' WHERE `guid`=118591;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID,0,0,0,1,0,'25900 52483');

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_QUETZLUN_SPIRIT;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_QUETZLUN_SPIRIT,0,0,0,1,0,'51126 41408');

DELETE FROM `spell_area` WHERE `spell`=52351 AND `area`=4325;
DELETE FROM `spell_area` WHERE `spell`=52484 AND `area`=4323;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(52351,4325,12675,0,0,0,2,1),
(52484,4323,12685,0,0,0,2,1);

DELETE FROM `event_scripts` WHERE `id`=18858 AND `command` IN (9,10,15);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(18858,0,9,@OGUID+5,30,0,0,0,0,0),
(18858,0,9,@OGUID+6,30,0,0,0,0,0),
(18858,0,9,@OGUID+7,30,0,0,0,0,0),
(18858,0,9,@OGUID+8,30,0,0,0,0,0),
(18858,0,9,@OGUID+9,30,0,0,0,0,0),
(18858,0,10,@NPC_ELM_BUNNY,30000,0,5711.149,-4361.718,387.6694,5.253441),
(18858,0,10,@NPC_ELM_BUNNY,30000,0,5726.004,-4372.459,387.9738,2.775074),
(18858,0,10,@NPC_ELM_BUNNY,30000,0,5707.188,-4371.667,387.4335,3.228859),
(18858,0,10,@NPC_ELM_BUNNY,30000,0,5721.946,-4361.917,387.8101,4.29351),
(18858,0,10,@NPC_ELM_BUNNY,30000,0,5717.041,-4378.735,387.6418,1.570796);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_HARKOA,@NPC_QUETZLUN_PROPHET,@NPC_QUETZLUN_SPIRIT);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_HARKOA,0,0,'$N, please come to me.  I''m here in Zim''Torga now.',15,0,100,0,0,0,'Har''koa'),
(@NPC_QUETZLUN_PROPHET,0,0,'What is this you pathetic, little worm? Come to die?',14,0,100,0,0,0,'Prophet of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET,1,0,'I recognize your stench. You''re the one who stealthed by me on the back of that snow leopard runt!',14,0,100,0,0,0,'Prophet of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET,2,0,'What? How is this possible?',14,0,100,0,0,0,'Prophet of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET,3,0,'Wait... STOP! You can''t take back the power!!!',14,0,100,0,0,0,'Prophet of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET,4,0,'NOOOOooooooooooooooooo!',14,0,100,0,0,0,'Prophet of Quetz''lun'),
(@NPC_QUETZLUN_SPIRIT,0,0,'TIME TO DIE, FOOL!',14,0,100,0,0,0,'Spirit of Quetz''lun'),
(@NPC_QUETZLUN_SPIRIT,1,0,'I''ve returned to invite you to my housewarming in the underworld!',14,0,100,0,0,7056,'Spirit of Quetz''lun'),
(@NPC_QUETZLUN_SPIRIT,2,0,'I''d say come along quietly, but we both know that''s not going to happen. My little friend here is going to ease your way into the afterlife.',14,0,100,0,0,0,'Spirit of Quetz''lun'),
(@NPC_QUETZLUN_SPIRIT,3,0,'Well done. I''ll see to it that my prophet enjoys his eternal stay with me.',14,0,100,0,0,0,'Spirit of Quetz''lun');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (52340,52381,52388);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@NPC_ELM_BUNNY;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@NPC_HARKOA;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52340,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Har''koa''s Spirit targets ELM General Purpose Bunny'),
(13,1,52381,0,0,31,0,3,@NPC_QUETZLUN_PROPHET,0,0,0,'','Spell Reclaim Power targets Quetz''lun''s Prophet'),
(13,1,52388,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Ritual Bunny Channel targets ELM General Purpose Bunny'),
(22,1,@NPC_ELM_BUNNY,0,0,23,1,4325,0,0,0,0,'','SAI Elm General Purpose Bunny spellcast Ritual Bunny Channel if at Quetz''lun''s Altar'),
(22,14,@NPC_HARKOA,0,0,1,0,52485,0,0,0,0,'','SAI Har''koa custom gossip if player has aura See Har''koa at Zim''Torga');

UPDATE `creature_model_info` SET `bounding_radius`=2.38, `combat_reach`=10.5 WHERE `modelid`=25685;
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=27857;

UPDATE `creature_template` SET `gossip_menu_id`=9749, `unit_flags`=33536 WHERE `entry`=@NPC_HARKOA;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_KHUFU,@NPC_QUETZLUN_PROPHET,@NPC_DRAINED_PROPHET);
UPDATE `creature_template` SET `unit_flags`=33536, `AIName`='SmartAI' WHERE `entry`=@NPC_QUETZLUN_SPIRIT;

-- SmartAIs
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_ELM_BUNNY,@NPC_KHUFU,@NPC_QUETZLUN_PROPHET,@NPC_QUETZLUN_SPIRIT,@NPC_DRAINED_PROPHET) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_HARKOA AND `source_type`=0 AND `id` BETWEEN 2 AND 15;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_HARKOA*100,@NPC_QUETZLUN_PROPHET*100,@NPC_QUETZLUN_SPIRIT*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_ELM_BUNNY,0,0,1,54,0,100,0,0,0,0,0,11,52388,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - Just summoned - Spellcast Ritual Bunny Channel'),
(@NPC_ELM_BUNNY,0,1,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_QUETZLUN_PROPHET,30,0,0,0,0,0, 'ELM General Purpose Bunny - Just summoned - Set data 0 1 Prophet of Quetz''lun'),

(@NPC_KHUFU,0,0,1,20,0,100,0,12685,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Khufu - On quest rewarded - Store targetlist'),
(@NPC_KHUFU,0,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Khufu - On quest rewarded - Send targetlist to Har''koa'),
(@NPC_KHUFU,0,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Khufu - On quest rewarded - Set data 0 1 Har''koa'),

(@NPC_HARKOA,0,2,3,20,0,100,0,12684,0,0,0,70,30,0,0,0,0,0,14,@OGUID+0,190736,0,0,0,0,0, 'Har''koa - On quest rewarded - Spawn Underworld Fragment'),
(@NPC_HARKOA,0,3,4,61,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,@OGUID+1,190737,0,0,0,0,0, 'Har''koa - On quest rewarded - Spawn Underworld Fragment'),
(@NPC_HARKOA,0,4,5,61,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,@OGUID+2,190738,0,0,0,0,0, 'Har''koa - On quest rewarded - Spawn Underworld Fragment'),
(@NPC_HARKOA,0,5,6,61,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,@OGUID+3,190738,0,0,0,0,0, 'Har''koa - On quest rewarded - Spawn Underworld Fragment'),
(@NPC_HARKOA,0,6,7,61,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,@OGUID+4,190737,0,0,0,0,0, 'Har''koa - On quest rewarded - Spawn Underworld Fragment'),
(@NPC_HARKOA,0,7,8,61,0,100,0,0,0,0,0,12,@NPC_ELM_BUNNY,3,30000,0,0,0,8,0,0,0,5335.713,-3770.931,373.7013,3.926991, 'Har''koa - On quest rewarded - Spawn Elm General Purpose Bunny'),
(@NPC_HARKOA,0,8,9,61,0,100,0,0,0,0,0,12,@NPC_ELM_BUNNY,3,30000,0,0,0,8,0,0,0,5329.658,-3770.809,372.8022,4.433136, 'Har''koa - On quest rewarded - Spawn Elm General Purpose Bunny'),
(@NPC_HARKOA,0,9,10,61,0,100,0,0,0,0,0,12,@NPC_ELM_BUNNY,3,30000,0,0,0,8,0,0,0,5332.665,-3770.165,373.2305,4.08407, 'Har''koa - On quest rewarded - Spawn Elm General Purpose Bunny'),
(@NPC_HARKOA,0,10,11,61,0,100,0,0,0,0,0,12,@NPC_ELM_BUNNY,3,30000,0,0,0,8,0,0,0,5336.709,-3774.087,372.9049,0, 'Har''koa - On quest rewarded - Spawn Elm General Purpose Bunny'),
(@NPC_HARKOA,0,11,12,61,0,100,0,0,0,0,0,12,@NPC_ELM_BUNNY,3,30000,0,0,0,8,0,0,0,5335.774,-3777.741,373.3314,3.385939, 'Har''koa - On quest rewarded - Spawn Elm General Purpose Bunny'),
(@NPC_HARKOA,0,12,0,61,0,100,0,0,0,0,0,80,@NPC_HARKOA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On quest rewarded - Run script'),
(@NPC_HARKOA,0,13,0,64,0,100,0,0,0,0,0,98,9687,13139,0,0,0,0,7,0,0,0,0,0,0,0, 'Har''koa - On gossip hello - Send custom gossip'),
(@NPC_HARKOA,0,14,15,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Har''koa - On data 0 1 set - Say line'),
(@NPC_HARKOA,0,15,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On data 0 1 set - Reset data'),

(@NPC_QUETZLUN_PROPHET,0,0,1,38,0,100,1,0,1,0,0,11,52353,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Prophet - On data 0 1 set - Spellcast Script Effect - Creature Capture GUID to Dot Variable'),
(@NPC_QUETZLUN_PROPHET,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Prophet - On data 0 1 set - Store targetlist'),
(@NPC_QUETZLUN_PROPHET,0,2,0,61,0,100,0,0,0,0,0,80,@NPC_QUETZLUN_PROPHET*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Prophet - On data 0 1 set - Run script'),
(@NPC_QUETZLUN_PROPHET,0,3,4,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_QUETZLUN_SPIRIT,50,0,0,0,0,0, 'Quetz''lun''s Prophet - On death - Set data 0 1 Spirit of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET,0,4,0,61,0,100,0,0,0,0,0,18,256|64,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Prophet - On death - Set unit_flags IMMUNE_TO_PC and UNK_6'),

(@NPC_QUETZLUN_SPIRIT,0,0,1,54,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Spirit - Just summoned - Spellcast Ethereal Teleport'),
(@NPC_QUETZLUN_SPIRIT,0,1,0,61,0,100,0,0,0,0,0,80,@NPC_QUETZLUN_SPIRIT*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Spirit - Just summoned - Run script'),
(@NPC_QUETZLUN_SPIRIT,0,2,3,38,0,100,0,0,1,0,0,1,3,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Spirit - On data 0 1 set - Say line'),
(@NPC_QUETZLUN_SPIRIT,0,3,0,61,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Spirit - On data 0 1 set - Despawn after 10 seconds'),

(@NPC_DRAINED_PROPHET,0,0,0,2,0,100,0,0,70,30000,30000,11,54601,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Drained Prophet - On health below 70% - Spellcast Serpent Form'),

(@NPC_HARKOA*100,9,0,0,0,0,100,0,18000,18000,0,0,11,52340,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Har''koa script - Spellcast Har''koa''s Spirit'),

(@NPC_QUETZLUN_PROPHET*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Say line'),
(@NPC_QUETZLUN_PROPHET*100,9,1,0,0,0,100,0,5600,5600,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Say line'),
(@NPC_QUETZLUN_PROPHET*100,9,2,0,0,0,100,0,6200,6200,0,0,12,@NPC_QUETZLUN_SPIRIT,8,0,0,0,0,8,0,0,0,5716.019,-4371.387,385.8849,4.757225, 'Quetz''lun''s Prophet script 0 - Summon Quetz''lun''s Spirit'),
(@NPC_QUETZLUN_PROPHET*100,9,3,0,0,0,100,0,100,100,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Say line'),
(@NPC_QUETZLUN_PROPHET*100,9,4,0,0,0,100,0,15400,15400,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Say line'),
(@NPC_QUETZLUN_PROPHET*100,9,5,0,0,0,100,0,5000,5000,0,0,28,53143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Remove aura Cosmetic Arcane Force Shield'),
(@NPC_QUETZLUN_PROPHET*100,9,6,0,0,0,100,0,100,100,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 0 - Say line'),
(@NPC_QUETZLUN_PROPHET*100,9,7,0,0,0,100,0,200,200,0,0,36,28795,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 1 - Morph to Drained Prophet of Quetz''lun'),
(@NPC_QUETZLUN_PROPHET*100,9,8,0,0,0,100,0,0,0,0,0,19,256|64,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 1 - Remove unit_flags IMMUNE_TO_PC and UNK_6'),
(@NPC_QUETZLUN_PROPHET*100,9,9,0,0,0,100,0,0,0,0,0,11,52354,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 1 - Spellcast Script Effect - Creature Attack GUID from Dot Variable'),
(@NPC_QUETZLUN_PROPHET*100,9,10,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Quetz''lun''s Prophet script 1 - Attack'),

(@NPC_QUETZLUN_SPIRIT*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Spirit script - Say line'),
(@NPC_QUETZLUN_SPIRIT*100,9,1,0,0,0,100,0,4800,4800,0,0,1,1,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Spirit script - Say line'),
(@NPC_QUETZLUN_SPIRIT*100,9,2,0,0,0,100,0,8200,8200,0,0,11,52381,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Quetz''lun''s Spirit script - Spellcast Reclaim Power'),
(@NPC_QUETZLUN_SPIRIT*100,9,3,0,0,0,100,0,100,100,0,0,1,2,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Quetz''lun''s Spirit script - Say line');
