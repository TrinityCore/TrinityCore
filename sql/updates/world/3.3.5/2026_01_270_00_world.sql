--
SET @SPAWN_GROUP_ID := 342; -- 4

-- Kael'thas
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry` = 19622;

-- Reorder texts & fix one text
DELETE FROM `creature_text` WHERE `CreatureID` = 19622;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19622,0,0,"Energy. Power. My people are addicted to it... a dependence made manifest after the Sunwell was destroyed. Welcome to the future. A pity you are too late to stop it. No one can stop me now! Selama ashal'anore!",14,0,100,0,0,11256,20195,0,"Kael'thas SAY_INTRO"),
(19622,1,0,"Capernian will see to it that your stay here is a short one.",14,0,100,0,0,11257,19004,0,"Kael'thas SAY_INTRO_CAPERNIAN"),
(19622,2,0,"Well done, you have proven worthy to test your skills against my master engineer, Telonicus.",14,0,100,0,0,11258,19005,0,"Kael'thas SAY_INTRO_TELONICUS"),
(19622,3,0,"Let us see how your nerves hold up against the Darkener, Thaladred! ",14,0,100,0,0,11259,19006,0,"Kael'thas SAY_INTRO_THALADRED"),
(19622,4,0,"You have persevered against some of my best advisors... but none can withstand the might of the Blood Hammer. Behold, Lord Sanguinar!",14,0,100,0,0,11260,19003,0,"Kael'thas SAY_INTRO_SANGUINAR"),
(19622,5,0,"As you see, I have many weapons in my arsenal....",14,0,100,0,0,11261,19053,0,"Kael'thas SAY_PHASE_2_WEAPONS"),
(19622,6,0,"Perhaps I underestimated you. It would be unfair to make you fight all four advisors at once, but... fair treatment was never shown to my people. I'm just returning the favor.",14,0,100,0,0,11262,19060,0,"Kael'thas SAY_PHASE_3_ADVANCE"),
(19622,7,0,"Alas, sometimes one must take matters into one's own hands. Balamore shanal!",14,0,100,0,0,11263,19195,0,"Kael'thas SAY_PHASE_4_INTRO_2"),
(19622,8,0,"Let us see how you fare when your world is turned upside down.",14,0,100,0,0,11264,20198,0,"Kael'thas SAY_GRAVITY_LAPSE_1"),
(19622,8,1,"Having trouble staying grounded?",14,0,100,0,0,11265,20199,0,"Kael'thas SAY_GRAVITY_LAPSE_2"),
(19622,9,0,"By the power of the sun!",14,0,100,0,0,11266,20200,0,"Kael'thas SAY_SUMMON_PHOENIX_1"),
(19622,9,1,"Anar'anel belore!",14,0,100,0,0,11267,20201,0,"Kael'thas SAY_SUMMON_PHOENIX_2"),
(19622,10,0,"Obey me!",14,0,100,0,0,11268,20202,0,"Kael'thas SAY_MIND_CONTROL_1"),
(19622,10,1,"Bow to my will!",14,0,100,0,0,11269,20203,0,"Kael'thas SAY_MIND_CONTROL_2"),
(19622,11,0,"You will not prevail!",14,0,100,0,0,11270,20204,0,"Kael'thas SAY_SLAY_1"),
(19622,11,1,"You gambled. And lost.",14,0,100,0,0,11271,20205,0,"Kael'thas SAY_SLAY_2"),
(19622,11,2,"This was child's play.",14,0,100,0,0,11272,20206,0,"Kael'thas SAY_SLAY_3"),
(19622,12,0,"I have not come this far to be stopped! The future I have planned will not be jeopardized! Now you will taste true power!!",14,0,100,0,0,11273,20208,0,"Kael'thas SAY_PHASE_5_NUTS"),
(19622,13,0,"For... Quel'...Thalas!",14,0,100,0,0,11274,20207,0,"Kael'thas SAY_DEATH"),
(19622,14,0,"%s begins to cast Pyroblast!",41,0,100,0,0,0,20775,0,"Kael'thas EMOTE_PYROBLAST");

-- Spawn groups
DELETE FROM `spawn_group` WHERE `spawnId` IN (12570,12569,12568,12567) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,12570),
(@SPAWN_GROUP_ID+1,0,12569),
(@SPAWN_GROUP_ID+2,0,12568),
(@SPAWN_GROUP_ID+3,0,12567);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Tempest Keep - Kael'thas - Lord Sanguinar",4),
(@SPAWN_GROUP_ID+1,"Tempest Keep - Kael'thas - Grand Astromancer Capernian",4),
(@SPAWN_GROUP_ID+2,"Tempest Keep - Kael'thas - Master Engineer Telonicus",4),
(@SPAWN_GROUP_ID+3,"Tempest Keep - Kael'thas - Thaladred the Darkener",4);

-- Controller
UPDATE `creature` SET `ScriptName` = 'npc_kaelthas_controller', `StringId` = 'KaelthasControllerTrigger' WHERE `guid` = 144154 AND `id` = 22515;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (36687,36688,36689,36709);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36687,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Kael Sanguinar' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36688,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Kael Capernian' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36689,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Kael Telonicus' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36709,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Kael Phase Two' (Effect 0) targets creature 'Kael'thas Sunstrider'");

-- Weapons
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 21268 AND 21274 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2126800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21268,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On AI Initialize - Run Script"),
(21269,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devastation - On AI Initialize - Run Script"),
(21270,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cosmic Infuser - On AI Initialize - Run Script"),
(21271,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinity Blades - On AI Initialize - Run Script"),
(21272,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warp Slicer - On AI Initialize - Run Script"),
(21273,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Phaseshift Bulwark - On AI Initialize - Run Script"),
(21274,0,0,0,37,0,100,0,0,0,0,0,0,80,2126800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Staff of Disintegration - On AI Initialize - Run Script"),

(2126800,9,0,0,0,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On Script - Set Corpse Delay"),
(2126800,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On Script - Set Reactstate Passive"),
(2126800,9,2,0,0,0,100,0,3000,3000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On Script - Set Reactstate Aggressive"),
(2126800,9,3,0,0,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On Script - Set In Combat With Zone");

UPDATE `spell_target_position` SET `PositionX` = 795, `PositionY` = 15, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36958;
UPDATE `spell_target_position` SET `PositionX` = 785, `PositionY` = 11, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36959;
UPDATE `spell_target_position` SET `PositionX` = 781, `PositionY` = 5, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36960;
UPDATE `spell_target_position` SET `PositionX` = 776, `PositionY` = -0.7, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36961;
UPDATE `spell_target_position` SET `PositionX` = 781, `PositionY` = -6, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36962;
UPDATE `spell_target_position` SET `PositionX` = 785, `PositionY` = -13, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36963;
UPDATE `spell_target_position` SET `PositionX` = 795, `PositionY` = -17, `PositionZ` = 50.06, `Orientation` = 3.141590118408203125, `VerifiedBuild` = 23420 WHERE `ID` = 36964;

-- Flame Strike Trigger (Kael)
UPDATE `creature_template` SET `ScriptName` = 'npc_flame_strike_trigger_kael' WHERE `entry` = 21369;

-- Phoenix Egg
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2, `ScriptName` = 'npc_phoenix_egg_the_eye' WHERE `entry` = 21364;

-- Phoenix
UPDATE `creature_template` SET `ScriptName` = 'npc_phoenix_the_eye' WHERE `entry` = 21362;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 40370;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,40370,0,0,31,0,3,21362,0,0,0,0,"","Group 0: Spell 'Banish' (Effect 0, 1, 2) targets creature 'Phoenix'");

-- Nether Vapor
UPDATE `creature_template` SET `ScriptName` = 'npc_nether_vapor' WHERE `entry` = 21002;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 21002;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(21002,1,0,1,0,0,0,NULL);

-- Spell scripts
UPDATE `spell_script_names` SET `ScriptName` = 'spell_kaelthas_gravity_lapse' WHERE `ScriptName` = 'spell_kael_gravity_lapse';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_kaelthas_remote_toy',
'spell_kaelthas_mind_control',
'spell_kaelthas_pyroblast',
'spell_kaelthas_gaining_power',
'spell_kaelthas_explodes',
'spell_kaelthas_pure_nether_beam',
'spell_kaelthas_pure_nether_beam_visual',
'spell_kaelthas_shock_barrier',
'spell_kaelthas_gravity_lapse_periodic',
'spell_kaelthas_summon_nether_vapor',
'spell_kaelthas_summon_nether_vapor_effect',
'spell_kaelthas_nether_vapor_lightning',
'spell_kaelthas_nether_beam');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37027, 'spell_kaelthas_remote_toy'),
(36797, 'spell_kaelthas_mind_control'),
(36819, 'spell_kaelthas_pyroblast'),
(36091, 'spell_kaelthas_gaining_power'),
(36092, 'spell_kaelthas_explodes'),
(36201, 'spell_kaelthas_pure_nether_beam'),
(36290, 'spell_kaelthas_pure_nether_beam'),
(36291, 'spell_kaelthas_pure_nether_beam'),
(36196, 'spell_kaelthas_pure_nether_beam_visual'),
(36197, 'spell_kaelthas_pure_nether_beam_visual'),
(36198, 'spell_kaelthas_pure_nether_beam_visual'),
(36815, 'spell_kaelthas_shock_barrier'),
(34480, 'spell_kaelthas_gravity_lapse_periodic'),
(35865, 'spell_kaelthas_summon_nether_vapor'),
(35861, 'spell_kaelthas_summon_nether_vapor_effect'),
(35862, 'spell_kaelthas_summon_nether_vapor_effect'),
(35863, 'spell_kaelthas_summon_nether_vapor_effect'),
(35864, 'spell_kaelthas_summon_nether_vapor_effect'),
(45960, 'spell_kaelthas_nether_vapor_lightning'),
(35869, 'spell_kaelthas_nether_beam');

-- Transition
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger1' WHERE `guid` = 144119 AND `id` = 22517; -- X: 799.8832 Y: -39.790634 Z: 86.04091
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger2' WHERE `guid` = 144121 AND `id` = 22517; -- X: 799.48193 Y: 38.38402 Z: 84.188545
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger3' WHERE `guid` = 144130 AND `id` = 22517; -- X: 847.9123 Y: -16.270517 Z: 64.80233
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger4' WHERE `guid` = 144123 AND `id` = 22517; -- X: 847.84033 Y: 14.672723 Z: 64.72507
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger5' WHERE `guid` = 144128 AND `id` = 22517; -- X: 844.8883 Y: -7.439569 Z: 66.139854
UPDATE `creature` SET `StringId` = 'KaelthasNetherbeamChannelTrigger6' WHERE `guid` = 144124 AND `id` = 22517; -- X: 844.85583 Y: 6.185529 Z: 65.86212

UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144112 AND `id` = 22517; -- X: 701.93585 Y: 66.05067 Z: 46.862164
UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144114 AND `id` = 22517; -- X: 699.306 Y: -67.62751 Z: 46.86217
UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144111 AND `id` = 22517; -- X: 665.1088 Y: -0.950598 Z: 46.86217
UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144113 AND `id` = 22517; -- X: 708.8086 Y: -0.769152 Z: 46.862156
UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144115 AND `id` = 22517; -- X: 732.94727 Y: -0.566178 Z: 46.86214
UPDATE `creature` SET `StringId` = 'KaelthasExplosionTrigger' WHERE `guid` = 144133 AND `id` = 22517; -- X: 766.7248 Y: -0.726238 Z: 50.133865

UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup1' WHERE `guid` = 144134; -- Spell: 36201 X: 778.8183 Y: 56.698456 Z: 126.98994
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup1' WHERE `guid` = 144116; -- Spell: 36201 X: 798.81226 Y: 61.566982 Z: 115.34415
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup1' WHERE `guid` = 144135; -- Spell: 36201 X: 786.0614 Y: 65.858246 Z: 100.424866

UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144129; -- Spell: 36290 X: 846.6299 Y: -37.764027 Z: 84.40607
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144132; -- Spell: 36290 X: 847.2033 Y: -31.359663 Z: 99.57969
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144127; -- Spell: 36290 X: 852.7165 Y: -17.161448 Z: 111.89911
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144125; -- Spell: 36290 X: 855.7502 Y: -1.335043 Z: 112.82647
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144122; -- Spell: 36290 X: 851.5966 Y: 17.912886 Z: 109.899216
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144131; -- Spell: 36290 X: 848.43695 Y: 30.284082 Z: 92.795105
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup2' WHERE `guid` = 144126; -- Spell: 36290 X: 849.4088 Y: 37.11266 Z: 77.683975

UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup3' WHERE `guid` = 144117; -- Spell: 36291 X: 785.42413 Y: -52.299824 Z: 134.9155
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup3' WHERE `guid` = 144118; -- Spell: 36291 X: 775.7325 Y: -61.36944 Z: 119.4992
UPDATE `creature` SET `StringId` = 'KaelthasPureNetherBeamTriggerGroup3' WHERE `guid` = 144120; -- Spell: 36291 X: 800.0196 Y: -62.71717 Z: 109.616516

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (36089,36090,36196,36197,36198);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36089,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Netherbeam' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36090,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Netherbeam' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36196,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36197,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'Kael'thas Sunstrider'"),
(13,1,36198,0,0,31,0,3,19622,0,0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'Kael'thas Sunstrider'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (36201,36290,36291);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36201,0,0,58,0,0,0,0,"KaelthasPureNetherBeamTriggerGroup1",0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'World Trigger (Large AOI)'"),
(13,1,36290,0,0,58,0,0,0,0,"KaelthasPureNetherBeamTriggerGroup2",0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'World Trigger (Large AOI)'"),
(13,1,36291,0,0,58,0,0,0,0,"KaelthasPureNetherBeamTriggerGroup3",0,0,0,"","Group 0: Spell 'Pure Nether Beam' (Effect 0) targets creature 'World Trigger (Large AOI)'");
