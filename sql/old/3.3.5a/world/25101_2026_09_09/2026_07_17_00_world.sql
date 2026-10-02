--
SET @CGUID := 147466; -- 24
SET @SPAWN_GROUP_ID := 377; -- 4

-- Medivh
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4288;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4288, 'at_black_morass_medivh');

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 15608;

DELETE FROM `creature_text` WHERE `CreatureID` = 15608;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15608,0,0,"The time has come! Gul'dan, order your warlocks to double their efforts! Moments from now the gateway will open and your Horde will be released upon this ripe, unsuspecting world!",14,0,100,0,0,10435,16787,0,"Medivh SAY_ENTER"),
(15608,1,0,"Champions! My shield grows weak!",14,0,100,0,0,10437,16792,0,"Medivh SAY_SHIELD_75"),
(15608,2,0,"My powers must be concentrated on the portal! I do not have time to hold the shield!",14,0,100,0,0,10438,16794,0,"Medivh SAY_SHIELD_50"),
(15608,3,0,"The shield is nearly gone! All that I have worked for is in danger!",14,0,100,0,0,10439,16795,0,"Medivh SAY_SHIELD_25"),
(15608,4,0,"I am grateful for your aid, champions. Now, Gul'dan's Horde will sweep across this world like a locust swarm, and all my designs, all my carefully-laid plans will at last fall into place.",14,0,100,0,0,10440,16796,0,"Medivh SAY_WIN"),
(15608,5,0,"No! Damn this feeble, mortal coil!",14,0,100,0,0,10441,16790,0,"Medivh SAY_DEATH"),
(15608,6,0,"Orcs of the Horde! This portal is the gateway to your new destiny! Azeroth lies before you, ripe for the taking!",14,0,100,5,0,0,19909,0,"Medivh SAY_ORCS");

-- Shadow Council Enforcer
UPDATE `creature_template` SET `unit_flags` = 33536, `flags_extra` = `flags_extra` &~ 2 WHERE `entry` = 17023;

DELETE FROM `creature_text` WHERE `CreatureID` = 17023;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17023,0,0,"Gul'dan speaks the truth! We should return at once to tell our brothers of the news! Retreat back through the portal!",14,0,100,5,0,0,19911,0,"Shadow Council Enforcer");

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+23;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+00,17023,269,0,0,3,1,0,1,-2086.84765625,7132.72216796875,34.67148208618164062,6.126105785369873046,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300001490A4
(@CGUID+01,17023,269,0,0,3,1,0,1,-2087.194580078125,7129.96923828125,34.671478271484375,6.143558979034423828,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300001490A5
(@CGUID+02,17023,269,0,0,3,1,0,1,-2087.479736328125,7127.2734375,34.67148208618164062,6.161012172698974609,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300009490A5
(@CGUID+03,17023,269,0,0,3,1,0,1,-2087.80126953125,7124.51025390625,34.67148208618164062,6.17846536636352539,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300011490A5
(@CGUID+04,17023,269,0,0,3,1,0,1,-2088.08203125,7121.8876953125,34.671478271484375,6.195918560028076171,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300019490A5
(@CGUID+05,17023,269,0,0,3,1,0,1,-2088.386474609375,7119.37890625,34.67148208618164062,6.213372230529785156,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300021490A5

(@CGUID+06,17023,269,0,0,3,1,0,1,-2086.572265625,7132.634765625,34.671478271484375,6.126105785369873046,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300001490A7
(@CGUID+07,17023,269,0,0,3,1,0,1,-2086.98486328125,7129.9677734375,34.671478271484375,6.143558979034423828,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300009490A7
(@CGUID+08,17023,269,0,0,3,1,0,1,-2087.408935546875,7127.20263671875,34.67148208618164062,6.161012172698974609,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300011490A7
(@CGUID+09,17023,269,0,0,3,1,0,1,-2087.88330078125,7124.3759765625,34.67148208618164062,6.17846536636352539,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300019490A7
(@CGUID+10,17023,269,0,0,3,1,0,1,-2088.224853515625,7121.990234375,34.67147445678710937,6.195918560028076171,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300021490A7
(@CGUID+11,17023,269,0,0,3,1,0,1,-2088.598876953125,7119.2431640625,34.671478271484375,6.213372230529785156,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300029490A7

(@CGUID+12,17023,269,0,0,3,1,0,1,-2086.509033203125,7132.677734375,34.671478271484375,6.126105785369873046,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300001490A9
(@CGUID+13,17023,269,0,0,3,1,0,1,-2086.95361328125,7129.98681640625,34.67148208618164062,6.143558979034423828,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300009490A9
(@CGUID+14,17023,269,0,0,3,1,0,1,-2087.310302734375,7127.18994140625,34.67148208618164062,6.161012172698974609,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300011490A9
(@CGUID+15,17023,269,0,0,3,1,0,1,-2087.646240234375,7124.35791015625,34.671478271484375,6.17846536636352539,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300019490A9
(@CGUID+16,17023,269,0,0,3,1,0,1,-2088.01318359375,7121.8740234375,34.671478271484375,6.195918560028076171,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300021490A9
(@CGUID+17,17023,269,0,0,3,1,0,1,-2088.5009765625,7119.22119140625,34.671478271484375,6.213372230529785156,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300029490A9

(@CGUID+18,17023,269,0,0,3,1,0,1,-2086.458740234375,7132.609375,34.67148208618164062,6.149602890014648437,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300001490AB
(@CGUID+19,17023,269,0,0,3,1,0,1,-2086.878173828125,7129.966796875,34.671478271484375,6.097349166870117187,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300009490AB
(@CGUID+20,17023,269,0,0,3,1,0,1,-2087.14892578125,7127.20458984375,34.671478271484375,6.089331626892089843,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300011490AB
(@CGUID+21,17023,269,0,0,3,1,0,1,-2087.487548828125,7124.41357421875,34.671478271484375,6.143567562103271484,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300019490AB
(@CGUID+22,17023,269,0,0,3,1,0,1,-2087.891845703125,7121.91796875,34.671478271484375,6.13900613784790039,300,0,0,0,0,0,0,0,0,'',NULL,24742), -- 0x203B0821A0109FC0001CE300021490AB
(@CGUID+23,17023,269,0,0,3,1,0,1,-2088.388427734375,7119.2041015625,34.671478271484375,6.178112030029296875,300,0,0,0,0,0,0,0,0,'',NULL,24742); -- 0x203B0821A0109FC0001CE300029490AB

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Black Morass - Shadow Council Enforcer Group 1",4),
(@SPAWN_GROUP_ID+1,"Black Morass - Shadow Council Enforcer Group 2",4),
(@SPAWN_GROUP_ID+2,"Black Morass - Shadow Council Enforcer Group 3",4),
(@SPAWN_GROUP_ID+3,"Black Morass - Shadow Council Enforcer Group 4",4);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+00 AND @CGUID+23 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+00),
(@SPAWN_GROUP_ID+0,0,@CGUID+01),
(@SPAWN_GROUP_ID+0,0,@CGUID+02),
(@SPAWN_GROUP_ID+0,0,@CGUID+03),
(@SPAWN_GROUP_ID+0,0,@CGUID+04),
(@SPAWN_GROUP_ID+0,0,@CGUID+05),

(@SPAWN_GROUP_ID+1,0,@CGUID+06),
(@SPAWN_GROUP_ID+1,0,@CGUID+07),
(@SPAWN_GROUP_ID+1,0,@CGUID+08),
(@SPAWN_GROUP_ID+1,0,@CGUID+09),
(@SPAWN_GROUP_ID+1,0,@CGUID+10),
(@SPAWN_GROUP_ID+1,0,@CGUID+11),

(@SPAWN_GROUP_ID+2,0,@CGUID+12),
(@SPAWN_GROUP_ID+2,0,@CGUID+13),
(@SPAWN_GROUP_ID+2,0,@CGUID+14),
(@SPAWN_GROUP_ID+2,0,@CGUID+15),
(@SPAWN_GROUP_ID+2,0,@CGUID+16),
(@SPAWN_GROUP_ID+2,0,@CGUID+17),

(@SPAWN_GROUP_ID+3,0,@CGUID+18),
(@SPAWN_GROUP_ID+3,0,@CGUID+19),
(@SPAWN_GROUP_ID+3,0,@CGUID+20),
(@SPAWN_GROUP_ID+3,0,@CGUID+21),
(@SPAWN_GROUP_ID+3,0,@CGUID+22),
(@SPAWN_GROUP_ID+3,0,@CGUID+23);

-- Chrono Lord Deja / Infinite Chrono-Lord
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857142857 WHERE `entry` = 17879;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72, `speed_walk` = 1, `speed_run` = 1.42857142857, `BaseAttackTime` = 2000 WHERE `entry` = 20738;

UPDATE `creature_template` SET `speed_run` = 1.42857142857, `AIName` = '', `ScriptName` = 'boss_chrono_lord_deja' WHERE `entry` = 21697;
UPDATE `creature_template` SET `speed_run` = 1.42857142857 WHERE `entry` = 21712;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21697 AND `source_type` = 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17879,21697);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17879,0,0,"Why do you aid the Magus? Just think of how many lives could be saved if the portal is never opened, if the resulting wars could be erased....",14,0,100,0,0,10412,16814,0,"Chrono Lord Deja SAY_ENTER"),
(17879,1,0,"You have outstayed your welcome, Keeper. Be gone!",14,0,100,0,0,10413,16817,0,"Chrono Lord Deja SAY_BANISH"),
(17879,2,0,"If you will not cease this foolish quest, then you will die!",14,0,100,0,0,10414,16815,0,"Chrono Lord Deja SAY_AGGRO"),
(17879,3,0,"I told you it was a fool's quest!",14,0,100,0,0,10415,16818,0,"Chrono Lord Deja SAY_SLAY_1"),
(17879,3,1,"Leaving so soon?",14,0,100,0,0,10416,16819,0,"Chrono Lord Deja SAY_SLAY_2"),
(17879,4,0,"Time... is on our side.",14,0,100,0,0,10417,16816,0,"Chrono Lord Deja SAY_DEATH"),

(21697,0,0,"Why do you aid the Magus? Just think of how many lives could be saved if the portal is never opened, if the resulting wars could be erased....",14,0,100,0,0,10412,16814,0,"Infinite Chrono-Lord SAY_ENTER"),
(21697,1,0,"You have outstayed your welcome, Keeper. Be gone!",14,0,100,0,0,10413,16817,0,"Infinite Chrono-Lord SAY_BANISH"),
(21697,2,0,"If you will not cease this foolish quest, then you will die!",14,0,100,0,0,10414,16815,0,"Infinite Chrono-Lord SAY_AGGRO"),
(21697,3,0,"I told you it was a fool's quest!",14,0,100,0,0,10415,16818,0,"Infinite Chrono-Lord SAY_SLAY_1"),
(21697,3,1,"Leaving so soon?",14,0,100,0,0,10416,16819,0,"Infinite Chrono-Lord SAY_SLAY_2"),
(21697,4,0,"Time... is on our side.",14,0,100,0,0,10417,16816,0,"Infinite Chrono-Lord SAY_DEATH");

-- Temporus / Infinite Timereaver
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72, `speed_walk` = 1, `speed_run` = 1.42857142857 WHERE `entry` = 17880;
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72, `speed_walk` = 1, `speed_run` = 1.42857142857, `BaseAttackTime` = 2000 WHERE `entry` = 20745;

UPDATE `creature_template` SET `speed_run` = 1.42857142857, `ScriptName` = 'boss_temporus' WHERE `entry` = 21698;
UPDATE `creature_template` SET `speed_run` = 1.42857142857 WHERE `entry` = 22167;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17880,21698);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17880,0,0,"Why do you persist? Surely you can see the futility of it all. It is not too late! You may still leave with your lives...",14,0,100,0,0,10442,16821,0,"Temporus SAY_ENTER"),
(17880,1,0,"Keeper! The sands of time have run out for you.",14,0,100,0,0,10443,16824,0,"Temporus SAY_BANISH"),
(17880,2,0,"So be it... you have been warned.",14,0,100,0,0,10444,16822,0,"Temporus SAY_AGGRO"),
(17880,3,0,"You should have left when you had the chance.",14,0,100,0,0,10445,16825,0,"Temporus SAY_SLAY_1"),
(17880,3,1,"Your days are done.",14,0,100,0,0,10446,16826,0,"Temporus SAY_SLAY_2"),
(17880,4,0,"My death means... little.",14,0,100,0,0,10447,16823,0,"Temporus SAY_DEATH"),

(21698,0,0,"Why do you persist? Surely you can see the futility of it all. It is not too late! You may still leave with your lives...",14,0,100,0,0,10442,16821,0,"Infinite Timereaver SAY_ENTER"),
(21698,1,0,"Keeper! The sands of time have run out for you.",14,0,100,0,0,10443,16824,0,"Infinite Timereaver SAY_BANISH"),
(21698,2,0,"So be it... you have been warned.",14,0,100,0,0,10444,16822,0,"Infinite Timereaver SAY_AGGRO"),
(21698,3,0,"You should have left when you had the chance.",14,0,100,0,0,10445,16825,0,"Infinite Timereaver SAY_SLAY_1"),
(21698,3,1,"Your days are done.",14,0,100,0,0,10446,16826,0,"Infinite Timereaver SAY_SLAY_2"),
(21698,4,0,"My death means... little.",14,0,100,0,0,10447,16823,0,"Infinite Timereaver SAY_DEATH");

-- Aeonus
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `BaseAttackTime` = 2000 WHERE `entry` = 20737;

DELETE FROM `creature_text` WHERE `CreatureID` = 17881;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17881,0,0,"The time has come to shatter this clockwork universe forever! Let us no longer be slaves of the hourglass! I warn you: those who do not embrace this greater path shall become victims of its passing!",14,0,100,0,0,10400,16827,0,"Aeonus SAY_ENTER"),
(17881,1,0,"Your time is up, slave of the past.",14,0,100,0,0,10401,16829,0,"Aeonus SAY_BANISH"),
(17881,2,0,"Let us see what fate has in store....",14,0,100,0,0,10402,16828,0,"Aeonus SAY_AGGRO"),
(17881,3,0,"One less obstacle in our way!",14,0,100,0,0,10403,16831,0,"Aeonus SAY_SLAY_1"),
(17881,3,1,"No one will stop us!",14,0,100,0,0,10404,16832,0,"Aeonus SAY_SLAY_2"),
(17881,4,0,"We will triumph. It is only a matter... of time.",14,0,100,0,0,10405,16830,0,"Aeonus SAY_DEATH"),
(17881,5,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Aeonus EMOTE_ENRAGE");

-- Time Keeper
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71428571429 WHERE `entry` IN (17918,20746);

DELETE FROM `creature_text` WHERE `CreatureID` = 17918;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17918,0,0,"There is no time to waste!",12,0,100,0,0,0,15190,0,"Time Keeper - On Spawn"),
(17918,0,1,"We must hurry!",12,0,100,0,0,0,15191,0,"Time Keeper - On Spawn"),
(17918,0,2,"We must use this time wisely!",12,0,100,0,0,0,15192,0,"Time Keeper - On Spawn"),
(17918,1,0,"One less threat to the timeways!",12,0,100,0,0,0,15193,0,"Time Keeper - On Kill"),
(17918,1,1,"Victory will be ours!",12,0,100,0,0,0,15194,0,"Time Keeper - On Kill"),
(17918,2,0,"Carry on! Victory at all costs!",14,0,100,0,0,0,15195,0,"Time Keeper - On Despawn"),
(17918,2,1,"Continue the fight! Do not falter!",14,0,100,0,0,0,15196,0,"Time Keeper - On Despawn");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17918 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17918,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Spawn - Say Line 0"),
(17918,0,1,0,11,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Spawn - Cast 'Simple Teleport'"),
(17918,0,2,0,0,0,100,0,0,5000,5000,10000,0,11,31478,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - In Combat - Cast 'Sand Breath'"),
(17918,0,3,0,5,0,100,0,20000,20000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Killed Unit - Say Line 1"),
(17918,0,4,0,8,0,100,0,31483,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Spellhit 'Dragon Helper Effect' - Say Line 2"),
(17918,0,5,0,8,0,100,0,31483,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Spellhit 'Dragon Helper Effect' - Despawn Instant");

-- Rift Lord
UPDATE `creature_template` SET `difficulty_entry_1` = 20744, `minlevel` = 71, `maxlevel` = 71 WHERE `entry` = 17839;
UPDATE `creature_template` SET `faction` = 1720, `speed_walk` = 1, `speed_run` = 1.42857 WHERE `entry` = 20744;
UPDATE `creature_template` SET `difficulty_entry_1` = 22172, `AIName` = 'SmartAI' WHERE `entry` = 21140;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857 WHERE `entry` = 22172;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17839,21140);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17839,0,0,"The sands of time shall be scattered to the winds!",14,0,100,0,0,0,15179,0,"Rift Lord - On Spawn"),
(17839,0,1,"History is about to be rewritten!",14,0,100,0,0,0,15180,0,"Rift Lord - On Spawn"),
(17839,0,2,"Let the siege begin!",14,0,100,0,0,0,15181,0,"Rift Lord - On Spawn"),
(17839,1,0,"The rift must be protected!",12,0,100,0,0,0,15182,0,"Rift Lord - On Aggro"),
(17839,1,1,"You are running out of time!",12,0,100,0,0,0,15183,0,"Rift Lord - On Aggro"),
(17839,1,2,"Victory or death!",12,0,100,0,0,0,15184,0,"Rift Lord - On Aggro"),
(17839,2,0,"You will never defeat us all!",14,0,100,0,0,0,15185,0,"Rift Lord - On Death"),
(17839,2,1,"You will accomplish nothing!",14,0,100,0,0,0,15186,0,"Rift Lord - On Death"),
(17839,2,2,"No! The rift...",14,0,100,0,0,0,15187,0,"Rift Lord - On Death"),
(17839,3,0,"The end is at hand!",12,0,100,0,0,0,15188,0,"Rift Lord - On Slay"),
(17839,3,1,"One step closer...",12,0,100,0,0,0,15189,0,"Rift Lord - On Slay"),

(21140,0,0,"The sands of time shall be scattered to the winds!",14,0,100,0,0,0,15179,0,"Rift Lord - On Spawn"),
(21140,0,1,"History is about to be rewritten!",14,0,100,0,0,0,15180,0,"Rift Lord - On Spawn"),
(21140,0,2,"Let the siege begin!",14,0,100,0,0,0,15181,0,"Rift Lord - On Spawn"),
(21140,1,0,"The rift must be protected!",12,0,100,0,0,0,15182,0,"Rift Lord - On Aggro"),
(21140,1,1,"You are running out of time!",12,0,100,0,0,0,15183,0,"Rift Lord - On Aggro"),
(21140,1,2,"Victory or death!",12,0,100,0,0,0,15184,0,"Rift Lord - On Aggro"),
(21140,2,0,"You will never defeat us all!",14,0,100,0,0,0,15185,0,"Rift Lord - On Death"),
(21140,2,1,"You will accomplish nothing!",14,0,100,0,0,0,15186,0,"Rift Lord - On Death"),
(21140,2,2,"No! The rift...",14,0,100,0,0,0,15187,0,"Rift Lord - On Death"),
(21140,3,0,"The end is at hand!",12,0,100,0,0,0,15188,0,"Rift Lord - On Slay"),
(21140,3,1,"One step closer...",12,0,100,0,0,0,15189,0,"Rift Lord - On Slay");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17839,21140) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17839,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Say Line 0"),
(17839,0,1,0,11,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Start Random Movement"),
(17839,0,2,0,11,0,100,0,0,0,0,0,0,11,31388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Cast 'Time Rift Channel Trigger'"),
(17839,0,3,0,4,0,20,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Rift Lord - On Aggro - Say Line 1"),
(17839,0,4,0,0,0,100,2,10000,20000,15000,20000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Hamstring' (Normal)"),
(17839,0,5,0,0,0,100,4,10000,20000,15000,20000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Hamstring' (Heroic)"),
(17839,0,6,0,0,0,100,2,10000,20000,15000,25000,0,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Knockdown' (Normal)"),
(17839,0,7,0,0,0,100,4,10000,20000,15000,25000,0,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Knockdown' (Heroic)"),
(17839,0,8,0,0,0,100,2,5000,15000,10000,20000,0,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Mortal Strike' (Normal)"),
(17839,0,9,0,0,0,100,4,5000,15000,10000,20000,0,11,35054,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Mortal Strike' (Heroic)"),
(17839,0,10,0,2,0,100,1,0,30,0,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(17839,0,11,0,5,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Killed Unit - Say Line 3"),
(17839,0,12,0,6,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Death - Say Line 2"),
(17839,0,13,0,6,0,100,0,0,0,0,0,0,11,31322,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Death - Cast 'Close Time Rift Trigger'"),

(21140,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Say Line 0"),
(21140,0,1,0,11,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Start Random Movement"),
(21140,0,2,0,11,0,100,0,0,0,0,0,0,11,31388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Spawn - Cast 'Time Rift Channel Trigger'"),
(21140,0,3,0,4,0,20,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Rift Lord - On Aggro - Say Line 1"),
(21140,0,4,0,0,0,100,2,6000,16000,6000,12000,0,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Sunder Armor' (Normal)"),
(21140,0,5,0,0,0,100,4,6000,16000,6000,12000,0,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Sunder Armor' (Heroic)"),
(21140,0,6,0,0,0,100,2,10000,20000,15000,25000,0,11,36214,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Thunderclap' (Normal)"),
(21140,0,7,0,0,0,100,4,10000,20000,15000,25000,0,11,38537,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 'Thunderclap' (Heroic)"),
(21140,0,8,0,2,0,100,1,0,30,0,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(21140,0,9,0,5,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Killed Unit - Say Line 3"),
(21140,0,10,0,6,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Death - Say Line 2"),
(21140,0,11,0,6,0,100,0,0,0,0,0,0,11,31322,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Lord - On Death - Cast 'Close Time Rift Trigger'");

-- Rift Keeper
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21148;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857 WHERE `entry` = 22170;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857 WHERE `entry` = 22171;

DELETE FROM `creature_text` WHERE `CreatureID` IN (21104,21148);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21104,0,0,"The sands of time shall be scattered to the winds!",14,0,100,0,0,0,15179,0,"Rift Keeper - On Spawn"),
(21104,0,1,"History is about to be rewritten!",14,0,100,0,0,0,15180,0,"Rift Keeper - On Spawn"),
(21104,0,2,"Let the siege begin!",14,0,100,0,0,0,15181,0,"Rift Keeper - On Spawn"),
(21104,1,0,"The rift must be protected!",12,0,100,0,0,0,15182,0,"Rift Keeper - On Aggro"),
(21104,1,1,"You are running out of time!",12,0,100,0,0,0,15183,0,"Rift Keeper - On Aggro"),
(21104,1,2,"Victory or death!",12,0,100,0,0,0,15184,0,"Rift Keeper - On Aggro"),
(21104,2,0,"You will never defeat us all!",14,0,100,0,0,0,15185,0,"Rift Keeper - On Death"),
(21104,2,1,"You will accomplish nothing!",14,0,100,0,0,0,15186,0,"Rift Keeper - On Death"),
(21104,2,2,"No! The rift...",14,0,100,0,0,0,15187,0,"Rift Keeper - On Death"),
(21104,3,0,"The end is at hand!",12,0,100,0,0,0,15188,0,"Rift Keeper - On Slay"),
(21104,3,1,"One step closer...",12,0,100,0,0,0,15189,0,"Rift Keeper - On Slay"),

(21148,0,0,"The sands of time shall be scattered to the winds!",14,0,100,0,0,0,15179,0,"Rift Keeper - On Spawn"),
(21148,0,1,"History is about to be rewritten!",14,0,100,0,0,0,15180,0,"Rift Keeper - On Spawn"),
(21148,0,2,"Let the siege begin!",14,0,100,0,0,0,15181,0,"Rift Keeper - On Spawn"),
(21148,1,0,"The rift must be protected!",12,0,100,0,0,0,15182,0,"Rift Keeper - On Aggro"),
(21148,1,1,"You are running out of time!",12,0,100,0,0,0,15183,0,"Rift Keeper - On Aggro"),
(21148,1,2,"Victory or death!",12,0,100,0,0,0,15184,0,"Rift Keeper - On Aggro"),
(21148,2,0,"You will never defeat us all!",14,0,100,0,0,0,15185,0,"Rift Keeper - On Death"),
(21148,2,1,"You will accomplish nothing!",14,0,100,0,0,0,15186,0,"Rift Keeper - On Death"),
(21148,2,2,"No! The rift...",14,0,100,0,0,0,15187,0,"Rift Keeper - On Death"),
(21148,3,0,"The end is at hand!",12,0,100,0,0,0,15188,0,"Rift Keeper - On Slay"),
(21148,3,1,"One step closer...",12,0,100,0,0,0,15189,0,"Rift Keeper - On Slay");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21104,21148) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21104,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Say Line 0"),
(21104,0,1,0,11,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Start Random Movement"),
(21104,0,2,0,11,0,100,0,0,0,0,0,0,11,31388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Cast 'Time Rift Channel Trigger'"),
(21104,0,3,0,4,0,20,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Rift Keeper - On Aggro - Say Line 1"),
(21104,0,4,0,0,0,100,2,5000,15000,10000,20000,0,11,36275,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Shadow Bolt Volley' (Normal)"),
(21104,0,5,0,0,0,100,4,5000,15000,10000,20000,0,11,38533,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Shadow Bolt Volley' (Heroic)"),
(21104,0,6,0,0,0,100,2,10000,20000,10000,20000,0,11,36276,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Curse of Vulnerability' (Normal)"),
(21104,0,7,0,0,0,100,4,10000,20000,10000,20000,0,11,36276,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Curse of Vulnerability' (Heroic)"),
(21104,0,8,0,0,0,100,0,15000,20000,15000,25000,0,11,12542,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Fear'"),
(21104,0,9,0,2,0,100,1,0,30,0,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(21104,0,10,0,5,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Killed Unit - Say Line 3"),
(21104,0,11,0,6,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Death - Say Line 2"),
(21104,0,12,0,6,0,100,0,0,0,0,0,0,11,31322,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Death - Cast 'Close Time Rift Trigger'"),

(21148,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Say Line 0"),
(21148,0,1,0,11,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Start Random Movement"),
(21148,0,2,0,11,0,100,0,0,0,0,0,0,11,31388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Spawn - Cast 'Time Rift Channel Trigger'"),
(21148,0,3,0,4,0,20,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Rift Keeper - On Aggro - Say Line 1"),
(21148,0,4,0,0,0,100,2,0,0,2400,3600,0,11,36279,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat CMC - Cast 'Frostbolt' (Normal)"),
(21148,0,5,0,0,0,100,4,0,0,2400,3600,0,11,38534,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat CMC - Cast 'Frostbolt' (Heroic)"),
(21148,0,6,0,0,0,100,2,5000,10000,15000,25000,0,11,36277,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Pyroblast' (Normal)"),
(21148,0,7,0,0,0,100,4,5000,10000,15000,25000,0,11,38535,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Pyroblast' (Heroic)"),
(21148,0,8,0,0,0,100,2,10000,20000,15000,25000,0,11,36278,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Blast Wave' (Normal)"),
(21148,0,9,0,0,0,100,4,10000,20000,15000,25000,0,11,38536,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Blast Wave' (Heroic)"),
(21148,0,10,0,0,0,100,0,15000,25000,20000,30000,0,11,13323,0,0,0,0,0,6,0,0,0,0,0,0,0,0,"Rift Keeper - In Combat - Cast 'Polymorph'"),
(21148,0,11,0,2,0,100,1,0,30,0,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(21148,0,12,0,5,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Killed Unit - Say Line 3"),
(21148,0,13,0,6,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Death - Say Line 2"),
(21148,0,14,0,6,0,100,0,0,0,0,0,0,11,31322,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rift Keeper - On Death - Cast 'Close Time Rift Trigger'");

-- Infinite Whelp
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 22169;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21818 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Actually not sure if all trash creatures are defensive
(21818,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Whelp - On AI Initialize - Set Reactstate Defensive"),
(21818,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Whelp - On AI Initialize - Set Corpse Delay"),
(21818,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Whelp - On Spawn - Move To Closest Creature 'Medivh'"),
(21818,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Whelp - On Aggro - Remove Aura 'Corrupt Medivh'"),
(21818,0,4,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Whelp - On Movement Inform - Cast 'Corrupt Medivh'");

-- Infinite Assassin
UPDATE `creature_template` SET `difficulty_entry_1` = 20740 WHERE `entry` = 17835;
UPDATE `creature_template` SET `faction` = 1720, `speed_walk` = 2, `speed_run` = 1.42857, `flags_extra` = `flags_extra`|64 WHERE `entry` = 20740;
UPDATE `creature_template` SET `difficulty_entry_1` = 22164, `AIName` = 'SmartAI' WHERE `entry` = 21137;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 22164;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17835,21137);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Not sure if these are grouped correctly
(17835,0,0,"Our time has come!",12,0,100,0,0,0,15163,0,"Infinite Assassin - On Aggro"),
(17835,0,1,"The wizard will fall!",12,0,100,0,0,0,15164,0,"Infinite Assassin - On Aggro"),
(17835,0,2,"Enforcers! Kill them all!",12,0,100,0,0,0,15165,0,"Infinite Assassin - On Aggro"),
(17835,0,3,"We will not be stopped!",12,0,100,0,0,0,15166,0,"Infinite Assassin - On Aggro"),
(17835,1,0,"More will take my place.",12,0,100,0,0,0,15167,0,"Infinite Assassin - On Death"),
(17835,1,1,"Your efforts... are in vain.",12,0,100,0,0,0,15168,0,"Infinite Assassin - On Death"),
(17835,1,2,"You will not save him!",12,0,100,0,0,0,15169,0,"Infinite Assassin - On Death"),
(17835,1,3,"We control the timeways now!",12,0,100,0,0,0,15170,0,"Infinite Assassin - On Death"),

(21137,0,0,"Our time has come!",12,0,100,0,0,0,15163,0,"Infinite Assassin - On Aggro"),
(21137,0,1,"The wizard will fall!",12,0,100,0,0,0,15164,0,"Infinite Assassin - On Aggro"),
(21137,0,2,"Enforcers! Kill them all!",12,0,100,0,0,0,15165,0,"Infinite Assassin - On Aggro"),
(21137,0,3,"We will not be stopped!",12,0,100,0,0,0,15166,0,"Infinite Assassin - On Aggro"),
(21137,1,0,"More will take my place.",12,0,100,0,0,0,15167,0,"Infinite Assassin - On Death"),
(21137,1,1,"Your efforts... are in vain.",12,0,100,0,0,0,15168,0,"Infinite Assassin - On Death"),
(21137,1,2,"You will not save him!",12,0,100,0,0,0,15169,0,"Infinite Assassin - On Death"),
(21137,1,3,"We control the timeways now!",12,0,100,0,0,0,15170,0,"Infinite Assassin - On Death");

DELETE FROM `creature_template_addon` WHERE `entry` IN (20740,22164);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(20740,0,0,0,0,0,0,1,0,0,0,'38519'),
(22164,0,0,0,0,0,0,1,0,0,0,'30982');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17835,21137) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17835,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On AI Initialize - Set Reactstate Defensive"),
(17835,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On AI Initialize - Set Corpse Delay"),
(17835,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Assassin - On Spawn - Move To Closest Creature 'Medivh'"),
(17835,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Remove Aura 'Corrupt Medivh'"),
(17835,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Say Line 0"),
(17835,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Movement Inform - Cast 'Corrupt Medivh'"),
(17835,0,6,0,0,0,100,2,5000,10000,5000,10000,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Backstab' (Normal)"),
(17835,0,7,0,0,0,100,4,5000,10000,5000,10000,0,11,15657,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Backstab' (Heroic)"),
(17835,0,8,0,0,0,100,0,5000,15000,20000,25000,0,11,30832,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Kidney Shot'"),
(17835,0,9,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Death - Say Line 1"),

(21137,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On AI Initialize - Set Reactstate Defensive"),
(21137,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On AI Initialize - Set Corpse Delay"),
(21137,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Assassin - On Spawn - Move To Closest Creature 'Medivh'"),
(21137,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Remove Aura 'Corrupt Medivh'"),
(21137,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Say Line 0"),
(21137,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Movement Inform - Cast 'Corrupt Medivh'"),
(21137,0,6,0,0,0,100,2,5000,10000,5000,15000,0,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Sinister Strike' (Normal)"),
(21137,0,7,0,0,0,100,4,5000,10000,5000,15000,0,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Sinister Strike' (Heroic)"),
(21137,0,8,0,0,0,100,2,5000,10000,10000,20000,0,11,14874,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Rupture' (Normal)"),
(21137,0,9,0,0,0,100,4,5000,10000,10000,20000,0,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 'Rupture' (Heroic)"),
(21137,0,10,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Death - Say Line 1");

-- Infinite Chronomancer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21136;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 20741;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 22165;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17892,21136);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Not sure if these are grouped correctly
(17892,0,0,"Death to the Last Guardian!",12,0,100,0,0,0,15171,0,"Infinite Chronomancer - On Aggro"),
(17892,0,1,"You will not stand in our way!",12,0,100,0,0,0,15172,0,"Infinite Chronomancer - On Aggro"),
(17892,0,2,"Magna Medivh dies today!",12,0,100,0,0,0,15173,0,"Infinite Chronomancer - On Aggro"),
(17892,1,0,"We are not finished!",12,0,100,0,0,0,15174,0,"Infinite Chronomancer - On Death"),
(17892,1,1,"A minor victory...",12,0,100,0,0,0,15175,0,"Infinite Chronomancer - On Death"),
(17892,1,2,"We will not fail!",12,0,100,0,0,0,15176,0,"Infinite Chronomancer - On Death"),
(17892,2,0,"The end is at hand!",12,0,100,0,0,0,15177,0,"Infinite Chronomancer - On Slay"),
(17892,2,1,"One step closer...",12,0,100,0,0,0,15178,0,"Infinite Chronomancer - On Slay"),

(21136,0,0,"Death to the Last Guardian!",12,0,100,0,0,0,15171,0,"Infinite Chronomancer - On Aggro"),
(21136,0,1,"You will not stand in our way!",12,0,100,0,0,0,15172,0,"Infinite Chronomancer - On Aggro"),
(21136,0,2,"Magna Medivh dies today!",12,0,100,0,0,0,15173,0,"Infinite Chronomancer - On Aggro"),
(21136,1,0,"We are not finished!",12,0,100,0,0,0,15174,0,"Infinite Chronomancer - On Death"),
(21136,1,1,"A minor victory...",12,0,100,0,0,0,15175,0,"Infinite Chronomancer - On Death"),
(21136,1,2,"We will not fail!",12,0,100,0,0,0,15176,0,"Infinite Chronomancer - On Death"),
(21136,2,0,"The end is at hand!",12,0,100,0,0,0,15177,0,"Infinite Chronomancer - On Slay"),
(21136,2,1,"One step closer...",12,0,100,0,0,0,15178,0,"Infinite Chronomancer - On Slay");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17892,21136) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17892,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On AI Initialize - Set Reactstate Defensive"),
(17892,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On AI Initialize - Set Corpse Delay"),
(17892,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Chronomancer - On Spawn - Move To Closest Creature 'Medivh'"),
(17892,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Remove Aura 'Corrupt Medivh'"),
(17892,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Say Line 0"),
(17892,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Movement Inform - Cast 'Corrupt Medivh'"),
(17892,0,6,0,0,0,100,2,0,0,1200,3600,0,11,15124,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat CMC - Cast 'Arcane Bolt' (Normal)"),
(17892,0,7,0,0,0,100,4,0,0,1200,3600,0,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat CMC - Cast 'Arcane Bolt' (Heroic)"),
(17892,0,8,0,0,0,100,2,5000,10000,10000,15000,0,11,33860,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Arcane Explosion' (Normal)"),
(17892,0,9,0,0,0,100,4,5000,10000,10000,15000,0,11,33623,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Arcane Explosion' (Heroic)"),
(17892,0,10,0,5,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Killed Unit - Say Line 2"),
(17892,0,11,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Death - Say Line 1"),

(21136,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On AI Initialize - Set Reactstate Defensive"),
(21136,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On AI Initialize - Set Corpse Delay"),
(21136,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Chronomancer - On Spawn - Move To Closest Creature 'Medivh'"),
(21136,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Remove Aura 'Corrupt Medivh'"),
(21136,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Say Line 0"),
(21136,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Movement Inform - Cast 'Corrupt Medivh'"),
(21136,0,6,0,0,0,100,2,0,0,3200,5400,0,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat CMC - Cast 'Frostbolt' (Normal)"),
(21136,0,7,0,0,0,100,4,0,0,3200,5400,0,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat CMC - Cast 'Frostbolt' (Heroic)"),
(21136,0,8,0,0,0,100,2,5000,10000,10000,20000,0,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Frost Nova' (Normal)"),
(21136,0,9,0,0,0,100,4,5000,10000,10000,20000,0,11,15531,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Frost Nova' (Heroic)"),
(21136,0,10,0,5,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Killed Unit - Say Line 2"),
(21136,0,11,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Death - Say Line 1");

-- Infinite Executioner
UPDATE `creature_template` SET `difficulty_entry_1` = 20742, `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 18994;
UPDATE `creature_template` SET `faction` = 1720, `speed_walk` = 2, `speed_run` = 1.42857, `flags_extra` = `flags_extra`|64 WHERE `entry` = 20742;
UPDATE `creature_template` SET `difficulty_entry_1` = 22166, `speed_walk` = 2, `speed_run` = 1.42857, `AIName` = 'SmartAI' WHERE `entry` = 21138;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857, `BaseAttackTime` = 2000 WHERE `entry` = 22166;

DELETE FROM `creature_text` WHERE `CreatureID` IN (18994,21138);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Not sure if these are grouped correctly
(18994,0,0,"Our time has come!",12,0,100,0,0,0,15163,0,"Infinite Executioner - On Aggro"),
(18994,0,1,"The wizard will fall!",12,0,100,0,0,0,15164,0,"Infinite Executioner - On Aggro"),
(18994,0,2,"Enforcers! Kill them all!",12,0,100,0,0,0,15165,0,"Infinite Executioner - On Aggro"),
(18994,0,3,"We will not be stopped!",12,0,100,0,0,0,15166,0,"Infinite Executioner - On Aggro"),
(18994,1,0,"More will take my place.",12,0,100,0,0,0,15167,0,"Infinite Executioner - On Death"),
(18994,1,1,"Your efforts... are in vain.",12,0,100,0,0,0,15168,0,"Infinite Executioner - On Death"),
(18994,1,2,"You will not save him!",12,0,100,0,0,0,15169,0,"Infinite Executioner - On Death"),
(18994,1,3,"We control the timeways now!",12,0,100,0,0,0,15170,0,"Infinite Executioner - On Death"),

(21138,0,0,"Our time has come!",12,0,100,0,0,0,15163,0,"Infinite Executioner - On Aggro"),
(21138,0,1,"The wizard will fall!",12,0,100,0,0,0,15164,0,"Infinite Executioner - On Aggro"),
(21138,0,2,"Enforcers! Kill them all!",12,0,100,0,0,0,15165,0,"Infinite Executioner - On Aggro"),
(21138,0,3,"We will not be stopped!",12,0,100,0,0,0,15166,0,"Infinite Executioner - On Aggro"),
(21138,1,0,"More will take my place.",12,0,100,0,0,0,15167,0,"Infinite Executioner - On Death"),
(21138,1,1,"Your efforts... are in vain.",12,0,100,0,0,0,15168,0,"Infinite Executioner - On Death"),
(21138,1,2,"You will not save him!",12,0,100,0,0,0,15169,0,"Infinite Executioner - On Death"),
(21138,1,3,"We control the timeways now!",12,0,100,0,0,0,15170,0,"Infinite Executioner - On Death");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18994,21138) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18994,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On AI Initialize - Set Reactstate Defensive"),
(18994,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On AI Initialize - Set Corpse Delay"),
(18994,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Executioner - On Spawn - Move To Closest Creature 'Medivh'"),
(18994,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Aggro - Remove Aura 'Corrupt Medivh'"),
(18994,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Executioner - On Aggro - Say Line 0"),
(18994,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Movement Inform - Cast 'Corrupt Medivh'"),
(18994,0,6,0,0,0,100,2,5000,10000,5000,10000,0,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Strike' (Normal)"),
(18994,0,7,0,0,0,100,4,5000,10000,5000,10000,0,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Strike' (Heroic)"),
(18994,0,8,0,0,0,100,2,5000,10000,5000,10000,0,11,17198,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Overpower' (Normal)"),
(18994,0,9,0,0,0,100,4,5000,10000,5000,10000,0,11,37321,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Overpower' (Heroic)"),
(18994,0,10,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Death - Say Line 1"),

(21138,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On AI Initialize - Set Reactstate Defensive"),
(21138,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On AI Initialize - Set Corpse Delay"),
(21138,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Executioner - On Spawn - Move To Closest Creature 'Medivh'"),
(21138,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Aggro - Remove Aura 'Corrupt Medivh'"),
(21138,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Executioner - On Aggro - Say Line 0"),
(21138,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Movement Inform - Cast 'Corrupt Medivh'"),
(21138,0,6,0,0,0,100,2,5000,10000,10000,15000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Hamstring' (Normal)"),
(21138,0,7,0,0,0,100,4,5000,10000,10000,15000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Hamstring' (Heroic)"),
(21138,0,8,0,0,0,100,2,5000,10000,10000,15000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Cleave' (Normal)"),
(21138,0,9,0,0,0,100,4,5000,10000,10000,15000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 'Cleave' (Heroic)"),
(21138,0,10,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Executioner - On Death - Say Line 1");

-- Infinite Vanquisher
UPDATE `creature_template` SET `difficulty_entry_1` = 20743, `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 18995;
UPDATE `creature_template` SET `faction` = 1720, `speed_walk` = 2, `speed_run` = 1.42857, `flags_extra` = `flags_extra`|64 WHERE `entry` = 20743;
UPDATE `creature_template` SET `difficulty_entry_1` = 22168, `speed_walk` = 2, `speed_run` = 1.42857, `AIName` = 'SmartAI' WHERE `entry` = 21139;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857, `BaseAttackTime` = 2000 WHERE `entry` = 22168;

DELETE FROM `creature_text` WHERE `CreatureID` IN (18995,21139);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Not sure if these are grouped correctly
(18995,0,0,"Death to the Last Guardian!",12,0,100,0,0,0,15171,0,"Infinite Vanquisher - On Aggro"),
(18995,0,1,"You will not stand in our way!",12,0,100,0,0,0,15172,0,"Infinite Vanquisher - On Aggro"),
(18995,0,2,"Magna Medivh dies today!",12,0,100,0,0,0,15173,0,"Infinite Vanquisher - On Aggro"),
(18995,1,0,"We are not finished!",12,0,100,0,0,0,15174,0,"Infinite Vanquisher - On Death"),
(18995,1,1,"A minor victory...",12,0,100,0,0,0,15175,0,"Infinite Vanquisher - On Death"),
(18995,1,2,"We will not fail!",12,0,100,0,0,0,15176,0,"Infinite Vanquisher - On Death"),
(18995,2,0,"The end is at hand!",12,0,100,0,0,0,15177,0,"Infinite Vanquisher - On Slay"),
(18995,2,1,"One step closer...",12,0,100,0,0,0,15178,0,"Infinite Vanquisher - On Slay"),

(21139,0,0,"Death to the Last Guardian!",12,0,100,0,0,0,15171,0,"Infinite Vanquisher - On Aggro"),
(21139,0,1,"You will not stand in our way!",12,0,100,0,0,0,15172,0,"Infinite Vanquisher - On Aggro"),
(21139,0,2,"Magna Medivh dies today!",12,0,100,0,0,0,15173,0,"Infinite Vanquisher - On Aggro"),
(21139,1,0,"We are not finished!",12,0,100,0,0,0,15174,0,"Infinite Vanquisher - On Death"),
(21139,1,1,"A minor victory...",12,0,100,0,0,0,15175,0,"Infinite Vanquisher - On Death"),
(21139,1,2,"We will not fail!",12,0,100,0,0,0,15176,0,"Infinite Vanquisher - On Death"),
(21139,2,0,"The end is at hand!",12,0,100,0,0,0,15177,0,"Infinite Vanquisher - On Slay"),
(21139,2,1,"One step closer...",12,0,100,0,0,0,15178,0,"Infinite Vanquisher - On Slay");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18995,21139) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18995,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On AI Initialize - Set Reactstate Defensive"),
(18995,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On AI Initialize - Set Corpse Delay"),
(18995,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Vanquisher - On Spawn - Move To Closest Creature 'Medivh'"),
(18995,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Remove Aura 'Corrupt Medivh'"),
(18995,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Say Line 0"),
(18995,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Movement Inform - Cast 'Corrupt Medivh'"),
(18995,0,6,0,0,0,100,2,5000,10000,5000,10000,0,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Fire Blast' (Normal)"),
(18995,0,7,0,0,0,100,4,5000,10000,5000,10000,0,11,38526,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Fire Blast' (Heroic)"),
(18995,0,8,0,0,0,100,2,1600,4800,1600,4800,0,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Scorch' (Normal)"),
(18995,0,9,0,0,0,100,4,1600,4800,1600,4800,0,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Scorch' (Heroic)"),
(18995,0,10,0,5,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Killed Unit - Say Line 2"),
(18995,0,11,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Death - Say Line 1"),

(21139,0,0,0,37,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On AI Initialize - Set Reactstate Defensive"),
(21139,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On AI Initialize - Set Corpse Delay"),
(21139,0,2,0,11,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,19,15608,200,0,0,0,0,0,0,"Infinite Vanquisher - On Spawn - Move To Closest Creature 'Medivh'"),
(21139,0,3,0,4,0,100,0,0,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Remove Aura 'Corrupt Medivh'"),
(21139,0,4,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Say Line 0"),
(21139,0,5,0,34,0,100,0,8,1,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Movement Inform - Cast 'Corrupt Medivh'"),
(21139,0,6,0,0,0,100,2,0,0,3200,4800,0,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat CMC - Cast 'Shadow Bolt' (Normal)"),
(21139,0,7,0,0,0,100,4,0,0,3200,4800,0,11,15472,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat CMC - Cast 'Shadow Bolt' (Heroic)"),
(21139,0,8,0,0,0,100,2,5000,10000,10000,15000,0,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Corruption' (Normal)"),
(21139,0,9,0,0,0,100,4,5000,10000,10000,15000,0,11,32197,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 'Corruption' (Heroic)"),
(21139,0,10,0,5,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Killed Unit - Say Line 2"),
(21139,0,11,0,6,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Death - Say Line 1");

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_black_morass_corrupt_medivh',
'spell_black_morass_corrupt_medivh_aeonus',
'spell_black_morass_time_rift_channel_trigger',
'spell_black_morass_banish_dragon_helper',
'spell_black_morass_close_time_rift_trigger',
'spell_black_morass_close_time_rift_effect',
'spell_black_morass_time_rift_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31326, 'spell_black_morass_corrupt_medivh'),
(37853, 'spell_black_morass_corrupt_medivh_aeonus'),
(31388, 'spell_black_morass_time_rift_channel_trigger'),
(31550, 'spell_black_morass_banish_dragon_helper'),
(31322, 'spell_black_morass_close_time_rift_trigger'),
(31323, 'spell_black_morass_close_time_rift_effect'),
(31320, 'spell_black_morass_time_rift_periodic');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 31550;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,31550,0,0,31,0,3,17918,0,0,0,0,"","Group 0: Spell 'Banish Dragon Helper' (Effect 0) targets creature 'Time Keeper'");
