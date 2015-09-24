-- 
SET @DredgeWorm:=      8925;
SET @DeepStinger:=     8926;
SET @DarkScreecher:=   8927;
SET @Burrowing:=       8928;
SET @Creeper:=         8933;
SET @Beetle:=          8932;
SET @Gorosh:=          9027;
SET @Grizzle:=         9028;
SET @Eviscerator:=     9029;
SET @Okthor:=          9030;
SET @Anubshiah:=       9031;
SET @Hedrum:=          9032;

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry` IN (@DredgeWorm, @DeepStinger, @DarkScreecher, @Burrowing, @Creeper, @Beetle, @Gorosh, @Grizzle, @Eviscerator, @Okthor, @Anubshiah, @Hedrum);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@DredgeWorm, @DeepStinger, @DarkScreecher, @Burrowing, @Creeper, @Beetle, @Gorosh, @Grizzle, @Eviscerator, @Okthor, @Anubshiah, @Hedrum) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DredgeWorm,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@DeepStinger,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@DarkScreecher,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Burrowing,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Creeper,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Beetle,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Gorosh,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Grizzle,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Eviscerator,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Okthor,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Anubshiah,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@Hedrum,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"@DredgeWorm - Just summoned - Start Attack"),
(@DredgeWorm,0,1,0,0,0,100,0,3000,4000,10000,15000,11,14535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dredge Worm - In Combat - Cast Dredge Sickness"),
(@DredgeWorm,0,2,0,0,0,100,0,4000,4000,8000,8000,11,13298,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dredge Worm - In Combat - Cast Poison"),
(@DredgeWorm,0,3,0,0,0,100,0,5000,6000,3000,3000,11,6917,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dredge Worm - In Combat - Cast Venom Spit)"),
(@DeepStinger,0,1,0,0,0,100,0,2000,2000,6000,8000,11,14534,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deep Stinger - In Combat - Cast Barbed Sting"),
(@DeepStinger,0,2,0,0,0,100,0,4000,4000,4000,4000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Stinger - In Combat - Cast Cleave"),
(@DarkScreecher,0,1,0,0,0,100,0,2000,2000,6000,8000,11,14538,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Screecher - In Combat - Cast Aural Shock"),
(@DarkScreecher,0,2,0,0,0,100,0,4000,4000,9000,10000,11,8281,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Screecher - In Combat - Cast Sonic Burst"),
(@Burrowing,0,1,0,0,0,100,0,2000,2000,30000,30000,11,14533,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burrowing Thundersnout - In Combat - Cast Disjonction"),
(@Burrowing,0,2,0,0,0,100,0,3000,3000,3000,3000,11,15611,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burrowing Thundersnout - In Combat - Cast Lizard Bolt"),
(@Burrowing,0,3,0,0,0,100,0,5000,5000,8000,8000,11,15548,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burrowing Thundersnout - In Combat - Cast Thunderclap"),
(@Creeper,0,1,0,0,0,100,0,2000,2000,20000,20000,11,14532,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cave Creeper - In Combat - Cast Creeper Venom"),
(@Creeper,0,2,0,0,0,100,0,4000,4000,8000,8000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cave Creeper - In Combat - Cast Web"),
(@Creeper,0,3,0,0,0,100,0,5000,6000,4000,8000,11,15656,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cave Creeper - In Combat - Cast Poisonous Stab"),
(@Beetle,0,1,0,0,0,100,0,2000,2000,30000,30000,11,14539,0,0,0,0,0,2,0,0,0,0,0,0,0,"Borer Beetle - In Combat - Cast Putrid Enzyme"),
(@Beetle,0,2,0,0,0,100,0,4000,4000,15000,20000,11,6016,0,0,0,0,0,5,0,0,0,0,0,0,0,"Borer Beetle - In Combat - Cast Pierce Armor"),
(@Gorosh,0,1,0,0,0,100,0,2000,4000,6000,8000,11,13736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorosh the Dervish - In Combat - Cast Whirlwind"),
(@Gorosh,0,2,0,0,0,100,0,4000,6000,5000,6000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorosh the Dervish - In Combat - Cast Mortal Strike"),
(@Gorosh,0,3,0,0,0,100,1,10000,15000,10000,15000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorosh the Dervish - In Combat - Cast Bloodlust"),
(@Grizzle,0,1,0,0,0,100,0,2000,3000,4000,5000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle the Dervish - In Combat - Cast Cleave"),
(@Grizzle,0,2,0,0,0,100,0,4000,5000,8000,9000,11,6524,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle the Dervish - In Combat - Cast Ground Tremor"),
(@Grizzle,0,3,0,0,0,100,1,10000,15000,10000,15000,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzle the Dervish - In Combat - Cast Frenzy"),
(@Grizzle,0,4,0,0,0,100,0,6000,7000,6000,9000,11,24458,0,0,0,0,0,5,0,0,0,0,0,0,0,"Grizzle the Dervish - In Combat - Cast Shadow Shock"),
(@Eviscerator,0,1,0,0,0,100,0,2000,3000,14000,15000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eviscerator - In Combat - Cast Vicious Rend"),
(@Eviscerator,0,2,0,0,0,100,0,4000,5000,4000,5000,11,15245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eviscerator - In Combat - Cast Shadow Bolt Volley"),
(@Eviscerator,0,3,0,0,0,100,0,5000,6000,15000,16000,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eviscerator - In Combat - Cast Anti-Magic Shield"),
(@Okthor,0,1,0,0,0,100,0,2000,3000,4000,5000,11,15254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okthor - In Combat - Cast Arcane Bolt"),
(@Okthor,0,2,0,0,0,100,0,5000,6000,6000,7000,11,15453,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okthor - In Combat - Cast Arcane Explosion"),
(@Okthor,0,3,0,0,0,100,0,9000,11000,11000,12000,11,13323,0,0,0,0,0,5,0,0,0,0,0,0,0,"Okthor - In Combat - Cast Polymorph"),
(@Okthor,0,4,0,0,0,100,0,7000,8000,9000,10000,11,13747,0,0,0,0,0,5,0,0,0,0,0,0,0,"Okthor - In Combat - Cast Slow"),
(@Anubshiah,0,1,0,0,0,100,0,5000,7000,10000,11000,11,8994,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Banish"),
(@Anubshiah,0,2,0,0,0,100,0,2000,3000,8000,9000,11,15470,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Curse of Tongues"),
(@Anubshiah,0,3,0,0,0,100,0,4000,5000,13000,15000,11,12493,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Curse of Weakness"),
(@Anubshiah,0,4,0,0,0,100,0,1000,1000,300000,300000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Demon Armor"),
(@Anubshiah,0,5,0,0,0,100,0,7000,8000,10000,13000,11,15471,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Enveloping Web"),
(@Anubshiah,0,6,0,0,0,100,0,3000,4000,4000,5000,11,15472,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anubshiah - In Combat - Cast Shadow Bolt"),
(@Hedrum,0,1,0,0,0,100,0,2000,2000,15000,18000,11,15475,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hedrum - In Combat - Cast Baneful Poison"),
(@Hedrum,0,2,0,0,0,100,0,7000,9000,15000,18000,11,3609,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hedrum - In Combat - Cast Paralyzing Poison"),
(@Hedrum,0,3,0,0,0,100,1,10000,15000,20000,25000,11,15474,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hedrum - In Combat - Cast Web Explosion");

UPDATE `creature_template` SET `unit_flags`=131904 WHERE `entry`=10096;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@DeepStinger);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(@DeepStinger, 1, '8601');

UPDATE `creature_text` SET `groupid`=4, `id`=1 WHERE `BroadcastTextId`=5441 AND `entry`=10096;
UPDATE `creature_text` SET `groupid`=0, `id`=1 WHERE `BroadcastTextId`=5442 AND `entry`=10096;
UPDATE `creature_text` SET `groupid`=1, `id`=1 WHERE `BroadcastTextId`=5443 AND `entry`=10096;
UPDATE `creature_text` SET `groupid`=5, `id`=1 WHERE `BroadcastTextId`=5444 AND `entry`=10096;
UPDATE `creature_text` SET `groupid`=2, `id`=1 WHERE `BroadcastTextId`=5445 AND `entry`=10096;
UPDATE `creature_text` SET `groupid`=3, `id`=1 WHERE `BroadcastTextId`=5446 AND `entry`=10096;
UPDATE `creature_text` SET `id`=0 WHERE `entry`=10096;
