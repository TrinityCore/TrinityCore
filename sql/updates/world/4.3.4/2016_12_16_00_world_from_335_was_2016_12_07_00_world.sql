--
SET @GUID:=87977;
DELETE FROM `creature` WHERE `id` IN(17256,17474) AND `map`=544;
DELETE FROM `linked_respawn` WHERE `guid` IN(90982,90981,90980,90979,90978); -- Delete Linked respawn from channelers
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(@GUID,17474,544,0,0,1,1,15435,0,11.2283,2.97198,-0.320875,1.14748,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+1,17474,544,0,0,1,1,15435,0,10.2283,1.97198,-0.320875,1.41097,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+2,17474,544,0,0,1,1,15435,0,-44.0663,21.973,-0.329128,5.15817,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+3,17474,544,0,0,1,1,15435,0,-44.3225,22.0454,-0.329129,5.87281,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+4,17474,544,0,0,1,1,15435,0,-13.1443,-26.8186,-0.412466,3.70357,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+5,17474,544,0,0,1,1,15435,0,-14.3701,-24.6551,-0.412466,1.99314,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+6,17474,544,0,0,1,1,15435,0,-45.6199,-16.1769,-0.329109,5.65524,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+7,17474,544,0,0,1,1,15435,0,-44.6199,-15.1769,-0.329109,1.5311,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+8,17474,544,0,0,1,1,15435,0,-17.5166,2.10518,-0.320812,5.98416,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+9,17474,544,0,0,1,1,15435,0,-16.5166,3.10518,-0.320812,0.0813029,7200,15,0,3965,0,1,0,0,0,0),
(@GUID+10,17474,544,0,0,1,1,15435,0,-12.4546,35.4987,-0.319343,2.09894,7200,5,0,3965,0,1,0,0,0,0),
(@GUID+11,17474,544,0,0,1,1,15435,0,-11.6249,31.6464,-0.412482,4.08569,7200,15,0,3965,0,1,0,0,0,0);

-- Target Trigger should walk in ground, not fly
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry`=17474;
-- Added Taunt Immunity in Magtheridon.
UPDATE `creature_template` SET `spell2`=0, `spell3`=0, `spell4`=0, `flags_extra` = `flags_extra` |256 WHERE `entry`=17257;

-- Delete addon aura from Magtheridon
DELETE FROM `creature_addon` WHERE `guid`=91254;

-- Added missing Fire Blast aura in Burning Abyssal creature
DELETE FROM `creature_template_addon` WHERE `entry`=17454;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(17454, 0, 0, 0, 1, 0, 30516);
-- Removed script from Burning Abyssal creature
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=17454;

-- Updated condition for Shadow Grasp hits Hellfire Raid Trigger
UPDATE `conditions` SET `ConditionValue2`=17376, `Comment`='Effect_0 hits Hellfire Raid Trigger' WHERE `SourceEntry`=30410 AND `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1;
-- Added condition for Blaze hit Target Trigger
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30541;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,30541,0,0,31,0,3,17474,0,0,0,0,'','Effect_0 hits Target Trigger');
-- Added condition for Quake hits Target Trigger
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30657;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,7,30657,0,0,31,0,3,17474,0,0,0,0,'','Effect_0, Effect_1, Effect_2 hits Target Trigger');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=30658;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(30658, 30571, 0, 'Quake Trigger Quake Knockback');

-- Making a summon group for Magtheridon.
DELETE FROM `creature_summon_groups` WHERE `summonerId`=17257; -- Magtheridon
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(17257,0,1,17256,-31.7645,-35.8374,0.714268,1.37881,6,6000), -- Hellfire Channelers
(17257,0,1,17256,10.3369,-19.7942,0.714241,2.53073,6,6000),
(17257,0,1,17256,10.4777,23.9914,0.714224,3.66519,6,6000),
(17257,0,1,17256,-31.9479,40.2201,0.714251,4.93928,6,6000),
(17257,0,1,17256,-55.6891,2.17024,0.71428,0.05236,6,6000);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_magtheridon_blaze_target','spell_magtheridon_shadow_grasp','spell_magtheridon_shadow_grasp_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30541,'spell_magtheridon_blaze_target'),
(30410,'spell_magtheridon_shadow_grasp'),
(30166,'spell_magtheridon_shadow_grasp_visual');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-30410 AND `spell_effect`=44032 AND `type`=0;

UPDATE `creature_template` SET `flags_extra`=128, `ScriptName`='npc_magtheridon_room' WHERE `entry`=17516;

UPDATE `spell_dbc` SET `AttributesEx3`=262400, `RangeIndex`=13 WHERE `Id`=30630;
UPDATE `spelleffect_dbc` SET `EffectImplicitTargetA`=53, `EffectImplicitTargetB`=0, `EffectRadiusIndex`=16 WHERE `EffectSpellId`=30630;

DELETE FROM `creature_text` WHERE `entry`=17257;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17257,0,0,'Wretched, meddling insects! Release me, and perhaps I will grant you a merciful death!',14,0,100,0,0,10247,17339,0,'Magtheridon - Taunt01'),
(17257,0,1,'Vermin! Leeches! Take my blood and choke on it!',14,0,100,0,0,10248,17340,0,'Magtheridon - Taunt02'),
(17257,0,2,'Illidan is an arrogant fool! I will crush him and reclaim Outland as my own!',14,0,100,0,0,10249,17341,0,'Magtheridon - Taunt03'),
(17257,0,3,'Away, you mindless parasites! My blood is my own!',14,0,100,0,0,10250,17342,0,'Magtheridon - Taunt04'),
(17257,0,4,'How long do you believe your pathetic sorcery can hold me?',14,0,100,0,0,10251,17343,0,'Magtheridon - Taunt05'),
(17257,0,5,'My blood will be the end of you!',14,0,100,0,0,10252,17344,0,'Magtheridon - Taunt06'),
(17257,1,0,'I... am... unleashed!',14,0,100,15,0,10253,17346,0,'Magtheridon - Free'),
(17257,2,0,'Did you think me weak? Soft? Who is the weak one now?',14,0,100,0,0,10255,17349,0,'Magtheridon - Slay'),
(17257,3,0,'Not again! Not again...',14,0,100,0,0,10256,17348,0,'Magtheridon - Banished'),
(17257,4,0,'I will not be taken so easily! Let the walls of this prison tremble... and fall!',14,0,100,0,0,10257,17336,0,'Magtheridon - Collapse'),
(17257,5,0,'The Legion will consume you all!',14,0,100,0,0,10258,17347,0,'Magtheridon - Death'),
(17257,6,0,'%s\'s bonds begin to weaken!',16,0,100,0,0,0,13689,0,'Magtheridon - Weaken'),
(17257,7,0,'%s is nearly free of his bonds!',16,0,100,0,0,0,13690,0,'Magtheridon - Nearly free'),
(17257,8,0,'%s breaks free!',16,0,100,0,0,0,13691,0,'Magtheridon - Breaks free'),
(17257,9,0,'%s begins to cast Blast Nova!',41,0,100,0,0,0,18739,0,'Magtheridon - Blast Nova');

UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=18829 AND `source_type`=0;

-- Channel Visual Group
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-90985,-90986,-90987) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-90986,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-90986,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-90986,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-90986,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-90986,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-90986,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-90986,0,6,0,1,0,100,1,1000,1000,0,0,11,33827,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Hellfire Warder Channel Visual'),
(-90987,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-90987,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-90987,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-90987,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-90987,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-90987,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-90987,0,6,0,1,0,100,1,1000,1000,0,0,11,33827,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Hellfire Warder Channel Visual'),
(-90985,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-90985,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-90985,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-90985,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-90985,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-90985,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-90985,0,6,0,1,0,100,1,1000,1000,0,0,11,33827,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Hellfire Warder Channel Visual');

-- Green Beam group
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-91247,-91248,-91249) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-91248,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-91248,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-91248,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-91248,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-91248,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-91248,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-91248,0,6,0,1,0,100,1,1000,1000,0,0,11,33346,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Green Beam'),
(-91247,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-91247,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-91247,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-91247,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-91247,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-91247,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-91247,0,6,0,1,0,100,1,1000,1000,0,0,11,33346,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Green Beam'),
(-91249,0,0,0,0,0,100,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Bolt Volley\''),
(-91249,0,1,0,0,0,100,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Death Coil\''),
(-91249,0,2,0,0,0,100,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Rain of Fire\''),
(-91249,0,3,0,0,0,100,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Burst\''),
(-91249,0,4,0,0,0,100,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Unstable Affliction\''),
(-91249,0,5,0,0,0,100,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Warder - In Combat - Cast \'Shadow Word: Pain\''),
(-91249,0,6,0,1,0,100,1,1000,1000,0,0,11,33346,0,0,0,0,0,19,15384,20,0,0,0,0,0,'Hellfire Warder - Ooc no repeat - Cast Green Beam');
