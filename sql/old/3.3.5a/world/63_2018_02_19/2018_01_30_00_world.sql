-- Duplicates --
DELETE FROM creature WHERE guid IN (130015,129723,130021,129653,129643,129702,129724,130005,129709,129810,129750,129787,130343,130340,130341,130342,130338,130339,129696);
DELETE FROM creature_addon WHERE guid IN (130015,129723,130021,129653,129643,129702,129724,130005,129709,129810,129750,129787,130343,130340,130341,130342,130338,130339,129696);

-- missing creatures -- 
DELETE FROM creature WHERE guid IN (45218);
DELETE FROM creature_addon WHERE guid IN (45218);
INSERT INTO creature (guid, id, modelid, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, curhealth, curmana, MovementType) VALUES
-- Scarlet Marksman
(45218,28610,0,609,1,4,1491,-5933,132.781,5.5541,180,5,2614,2117,1);

-- UPDATES -- 
UPDATE creature_template SET inhabittype = 4 WHERE entry IN (28804,29038,28906);
UPDATE creature SET position_x = 2333.83, position_y = -5995.26, position_z = 56.932, spawndist = 10, MovementType = 1 WHERE guid = 130309;
UPDATE creature SET position_x = 1415.26, position_y = -5858.53, position_z = 131.53, spawndist = 10, MovementType = 1 WHERE guid = 130032;
UPDATE creature SET position_x = 1724.94, position_y = -5802.69, position_z = 117.32, spawndist = 5, MovementType = 1 WHERE guid = 129676;
UPDATE creature SET position_x = 1742.46, position_y = -5734.76, position_z = 112.5, spawndist = 10, MovementType = 1  WHERE guid = 130023;
UPDATE creature SET position_x = 1616.89, position_y = -5882.22, position_z = 115.91, spawndist = 10, MovementType = 1 WHERE guid = 129710;
UPDATE creature SET position_x = 1736.884888, position_y = -5929.806641, position_z = 117.481873, orientation = 0.825981, spawndist = 10, MovementType = 1 WHERE guid = 129670;
UPDATE creature SET position_x = 1665.335449, position_y = -5821.938477, position_z = 117.471611, orientation = 3.148665, spawndist = 15, MovementType = 1 WHERE guid = 129725;
UPDATE creature SET position_x = 1768.745728, position_y = -5783.970703, position_z = 116.123192, orientation = 4.962763, spawndist = 15, MovementType = 1 WHERE guid = 129679;
UPDATE creature SET position_x = 1783.516846, position_y = -5807.990723, position_z = 114.257050, orientation = 6.089830, spawndist = 0, MovementType = 0 WHERE guid = 129649;
UPDATE creature SET position_x = 1781.896362, position_y = -5801.923340, position_z = 115.135803, orientation = 5.912445, spawndist = 0, MovementType = 0 WHERE guid = 129648;
UPDATE creature SET position_x = 1812.887573, position_y = -5796.937500, position_z = 116.069069, orientation = 5.765442, spawndist = 0, MovementType = 0 WHERE guid = 130018;
UPDATE creature SET position_x = 1802.113770, position_y = -5800.691406, position_z = 115.556595, orientation = 5.613868, spawndist = 0, MovementType = 0 WHERE guid = 130019;
UPDATE creature SET position_x = 1792.531616, position_y = -5824.551758, position_z = 111.479637, orientation = 6.211735, spawndist = 0, MovementType = 0 WHERE guid = 130022;
UPDATE creature SET position_x = 1791.961548, position_y = -5811.046875, position_z = 111.580521, orientation = 0.091129, spawndist = 0, MovementType = 0 WHERE guid = 130027;
UPDATE creature SET position_x = 1789.263062, position_y = -5803.730957, position_z = 113.554192, orientation = 5.855959, spawndist = 0, MovementType = 0 WHERE guid = 130029;
UPDATE creature SET position_x = 1787.844360, position_y = -5832.341309, position_z = 115.062073, orientation = 0.281136, spawndist = 0, MovementType = 0 WHERE guid = 130033;
UPDATE creature SET position_x = 1579.620850, position_y = -5703.322266, position_z = 121.681549, orientation = 2.945991, spawndist = 0, MovementType = 0 WHERE guid = 129809;
UPDATE creature SET position_x = 1828.536743, position_y = -5918.959473, position_z = 109.820824, orientation = 0.376951, spawndist = 0, MovementType = 0 WHERE guid = 130031;
UPDATE creature SET position_x = 1833.080444, position_y = -5932.240723, position_z = 111.163170, orientation = 0.244101, spawndist = 0, MovementType = 0 WHERE guid = 130030;
UPDATE creature SET position_x = 1825.181641, position_y = -5907.274414, position_z = 115.891685, orientation = 6.098576, spawndist = 0, MovementType = 0 WHERE guid = 130012;
UPDATE creature SET position_x = 1821.618530, position_y = -5916.443848, position_z = 111.221413, orientation = 6.210087, spawndist = 0, MovementType = 0 WHERE guid = 130017;
UPDATE creature SET position_x = 1832.372803, position_y = -5937.548828, position_z = 112.914291, orientation = 0.873289, spawndist = 0, MovementType = 0 WHERE guid = 130016;
UPDATE creature SET position_x = 1825.616577, position_y = -5943.870605, position_z = 115.999161, orientation = 0.734298, spawndist = 0, MovementType = 0 WHERE guid = 129645;
UPDATE creature SET position_x = 1825.279663, position_y = -5936.830566, position_z = 113.658310, orientation = 0.573291, spawndist = 0, MovementType = 0 WHERE guid = 129641;
UPDATE creature SET position_x = 1813.636719, position_y = -5922.254883, position_z = 114.224655, orientation = 6.276883, spawndist = 0, MovementType = 0 WHERE guid = 129642;
UPDATE creature SET position_x = 1808.542114, position_y = -5915.114258, position_z = 115.840347, orientation = 6.127660, spawndist = 0, MovementType = 0 WHERE guid = 129650;
UPDATE creature SET spawndist = 10, MovementType = 1 WHERE guid = 129681;
UPDATE creature SET spawndist = 0, MovementType = 0 WHERE guid IN (129992,129813);
UPDATE creature SET spawndist = 0, MovementType = 0 WHERE id IN (29038);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (29030,29031);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29030,29031) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29030, 0, 0, 1, 1, 0, 100, 0, 2000, 5000, 5000, 9000, 11, 52953, 0, 0, 0, 0, 0, 19, 29038, 40, 0, 0, 0, 0, 0, "Death Knight - Ooc - Cast 'Torch'"),
(29030, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 1000, 1000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, "Death Knight - Ooc - create event1"),
(29030, 0, 2, 0, 59, 0, 100, 0, 1, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Death Knight - On event1 - play emote cheers"),
(29031, 0, 0, 1, 1, 0, 100, 0, 2000, 5000, 5000, 9000, 11, 52953, 0, 0, 0, 0, 0, 19, 29038, 40, 0, 0, 0, 0, 0, "Death Knight - Ooc - Cast 'Torch'"),
(29031, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 1000, 1000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, "Death Knight - Ooc - create event1"),
(29031, 0, 2, 0, 59, 0, 100, 0, 1, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Death Knight - On event1 - play emote cheers");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=52953;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,1,52953,0,0,31,0,3,29038,0,0,0,0,'',"'Death Knight' must cast spell on '[Chapter II] Torch Toss Dummy");
UPDATE smart_scripts SET `event_type`=1, `event_flags`=0, `event_param3`=13000, `event_param4`=15000 WHERE `entryorguid`=29038 AND `source_type`=0 AND `id`=0;

-- Scarlet Commander
UPDATE `creature_addon` SET `mount`=2404, `auras`="48356" WHERE `guid` IN (129639, 129654, 129657, 129640);
UPDATE `creature_template_addon` SET `auras`="48356" WHERE `entry` = 28936;

-- New Avalon Councilman
DELETE FROM `creature_addon` WHERE `guid` IN (129808,129809,129811,129812);

-- Scarlet Crusader
UPDATE `creature_addon` SET `auras` = '48356' WHERE `guid` IN (129688,129698,129700,129701,129703,129705,129706,129707,129708,129713,129716,129718,129720,129721);
UPDATE `creature_addon` SET `auras` = '48356 52103' WHERE `guid` IN (129722,129726,130014,130009);

-- Scarlet Marksman
UPDATE creature_addon SET auras = "" WHERE guid IN (130007,130010,130012,130018,130030);

-- Scarlet Captain -- phase 1
UPDATE `creature_addon` SET `mount`=2404, `auras`="48356", `bytes2`=1 WHERE guid IN (129292,129296,129297,129299,129300,129301,129302,129303);
UPDATE `creature_template_addon` SET `auras`="48356" WHERE `entry` = 28611;

-- Citizen of New Avalon -- 28941 28942
DELETE FROM creature_addon WHERE guid IN (129730, 129749, 129760, 129761, 129764, 129770, 129786, 129805, 129753, 129791);
INSERT INTO creature_addon (guid, mount, bytes1, bytes2, auras) VALUES 
(129753,0,0,1,'52742'), -- individual
(129791,0,0,1,'52742');  -- individual

-- Citizen of New Avalon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (28941,28942);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28941,28942) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2894100,2894101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28941, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 87, 2894100, 2894101, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - Random action list"),
(28942, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 87, 2894100, 2894101, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - Random action list"),
(2894100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52262, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - cast"),
(2894100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - say text0"),
(2894101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52716, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - cast"),
(2894101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - On aggro - say text1"),
(28941, 0, 1, 0, 1, 0, 10, 0, 5000, 20000, 15000, 20000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - Ooc - say text 2"),
(28942, 0, 1, 0, 1, 0, 10, 0, 5000, 20000, 15000, 20000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - Ooc - say text 2");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (28941,28942);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(22,2,28941,0,0,23,1,4346,0,0,0,0,0,'',"Citizen of New Avalon ooc sai only on area 4346"),
(22,2,28942,0,0,23,1,4346,0,0,0,0,0,'',"Citizen of New Avalon ooc sai only on area 4346");

DELETE FROM `creature_text` WHERE `CreatureID` IN (28941,28942);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28941,0,0,"Ask for anything and you shall have it! Just spare my life!",12,0,100,0,0,0,29088,0,"Citizen of New Avalon"),
(28941,0,1,"HELP! HELP!",12,0,100,0,0,0,29074,0,"Citizen of New Avalon"),
(28941,0,2,"I'll give you anything you want! Just let me live!",12,0,100,0,0,0,29087,0,"Citizen of New Avalon"),
(28941,0,3,"I'm too young to die!",12,0,100,0,0,0,29086,0,"Citizen of New Avalon"),
(28941,0,4,"RUN FOR YOUR LIVES!",12,0,100,0,0,0,29072,0,"Citizen of New Avalon"),
(28941,0,5,"SCOURGE!!! RUN!!!",12,0,100,0,0,0,29075,0,"Citizen of New Avalon"),
(28941,0,6,"Somebody save me!",12,0,100,0,0,0,29078,0,"Citizen of New Avalon"),
(28941,0,7,"Spare my life, $n! Please!",12,0,100,0,0,0,29076,0,"Citizen of New Avalon"),
(28941,0,8,"The Scourge has broken through! RUN AWAY! RUN AWAY!",12,0,100,0,0,0,29073,0,"Citizen of New Avalon"),
(28941,0,9,"The... They promised that we'd be safe...",12,0,100,0,0,0,29085,0,"Citizen of New Avalon"),
(28941,0,10,"Is nowhere safe from these monsters?",12,0,100,0,0,0,29077,0,"Citizen of New Avalon"),
(28941,0,11,"We're all gonna die!!!",12,0,100,0,0,0,29079,0,"Citizen of New Avalon"),
(28941,0,12,"Filthy coward! Get it over with...",12,0,100,0,0,0,29089,0,"Citizen of New Avalon"),
(28941,0,13,"Scourge scum... May the Light purge you from this world!",12,0,100,0,0,0,29090,0,"Citizen of New Avalon"),
(28941,1,0,"Come then, $c!",12,0,100,0,0,0,28790,0,"Citizen of New Avalon"),
(28941,1,1,"Die Scourge dog! DIE!",12,0,100,0,0,0,28789,0,"Citizen of New Avalon"),
(28941,1,2,"DIE!",12,0,100,0,0,0,28793,0,"Citizen of New Avalon"),
(28941,1,3,"I won't go down that easy!",12,0,100,0,0,0,28788,0,"Citizen of New Avalon"),
(28941,1,4,"Is this the best the Scourge can do?",12,0,100,0,0,0,28791,0,"Citizen of New Avalon"),
(28941,1,5,"You may take my life, but you won't take my freedom!",12,0,100,0,0,0,28792,0,"Citizen of New Avalon"),
(28941,1,6,"You're not taking me without a fight!",12,0,100,0,0,0,28787,0,"Citizen of New Avalon"),
(28941,2,0,"I assure you this much, Quimby, you won't be getting my vote next term!",12,0,100,0,0,0,29109,0,"Citizen of New Avalon"),
(28941,2,1,"I want on that last ship! Don't leave us!",12,0,100,0,0,0,29113,0,"Citizen of New Avalon"),
(28941,2,2,"If you don't come out, we'll tear this place apart!",12,0,100,0,0,0,29105,0,"Citizen of New Avalon"),
(28941,2,3,"My whole family's been killed! Where was the army when we needed them most?",12,0,100,0,0,0,29100,0,"Citizen of New Avalon"),
(28941,2,4,"Naxxramas is gone? Who cares! Acherus is here now and the death knights are killing everybody!",12,0,100,0,0,0,29108,0,"Citizen of New Avalon"),
(28941,2,5,"No more lies, Quimby! We want answers!",12,0,100,0,0,0,29102,0,"Citizen of New Avalon"),
(28941,2,6,"QUIMBY!!!!!!",12,0,100,0,0,0,29115,0,"Citizen of New Avalon"),
(28941,2,7,"So much for the Scarlet 'paradise!'",12,0,100,0,0,0,29114,0,"Citizen of New Avalon"),
(28941,2,8,"The Scourge are running freely through the streets!",12,0,100,0,0,0,29099,0,"Citizen of New Avalon"),
(28941,2,9,"This is a slap in the face! We demand answers!",12,0,100,0,0,0,29111,0,"Citizen of New Avalon"),
(28941,2,10,"We were promised safety! Security!",12,0,100,0,0,0,29098,0,"Citizen of New Avalon"),
(28941,2,11,"We're done for! Save us, Quimby!",12,0,100,0,0,0,29104,0,"Citizen of New Avalon"),
(28941,2,12,"What's 'Crimson Dawn!' We deserve to know the truth, Quimby!",12,0,100,0,0,0,29107,0,"Citizen of New Avalon"),
(28941,2,13,"Where are those ships going, Quimby! Tell us the truth!",12,0,100,0,0,0,29103,0,"Citizen of New Avalon"),
(28941,2,14,"You're useless, Quimby!",12,0,100,0,0,0,29110,0,"Citizen of New Avalon"),
(28941,2,15,"Everybody is dying! Help us!",12,0,100,0,0,0,29106,0,"Citizen of New Avalon"),
(28942,0,0,"Ask for anything and you shall have it! Just spare my life!",12,0,100,0,0,0,29088,0,"Citizen of New Avalon"),
(28942,0,1,"HELP! HELP!",12,0,100,0,0,0,29074,0,"Citizen of New Avalon"),
(28942,0,2,"I'll give you anything you want! Just let me live!",12,0,100,0,0,0,29087,0,"Citizen of New Avalon"),
(28942,0,3,"I'm too young to die!",12,0,100,0,0,0,29086,0,"Citizen of New Avalon"),
(28942,0,4,"RUN FOR YOUR LIVES!",12,0,100,0,0,0,29072,0,"Citizen of New Avalon"),
(28942,0,5,"SCOURGE!!! RUN!!!",12,0,100,0,0,0,29075,0,"Citizen of New Avalon"),
(28942,0,6,"Somebody save me!",12,0,100,0,0,0,29078,0,"Citizen of New Avalon"),
(28942,0,7,"Spare my life, $n! Please!",12,0,100,0,0,0,29076,0,"Citizen of New Avalon"),
(28942,0,8,"The Scourge has broken through! RUN AWAY! RUN AWAY!",12,0,100,0,0,0,29073,0,"Citizen of New Avalon"),
(28942,0,9,"The... They promised that we'd be safe...",12,0,100,0,0,0,29085,0,"Citizen of New Avalon"),
(28942,0,10,"Is nowhere safe from these monsters?",12,0,100,0,0,0,29077,0,"Citizen of New Avalon"),
(28942,0,11,"We're all gonna die!!!",12,0,100,0,0,0,29079,0,"Citizen of New Avalon"),
(28942,0,12,"Filthy coward! Get it over with...",12,0,100,0,0,0,29089,0,"Citizen of New Avalon"),
(28942,0,13,"Scourge scum... May the Light purge you from this world!",12,0,100,0,0,0,29090,0,"Citizen of New Avalon"),
(28942,1,0,"Come then, $c!",12,0,100,0,0,0,28790,0,"Citizen of New Avalon"),
(28942,1,1,"Die Scourge dog! DIE!",12,0,100,0,0,0,28789,0,"Citizen of New Avalon"),
(28942,1,2,"DIE!",12,0,100,0,0,0,28793,0,"Citizen of New Avalon"),
(28942,1,3,"I won't go down that easy!",12,0,100,0,0,0,28788,0,"Citizen of New Avalon"),
(28942,1,4,"Is this the best the Scourge can do?",12,0,100,0,0,0,28791,0,"Citizen of New Avalon"),
(28942,1,5,"You may take my life, but you won't take my freedom!",12,0,100,0,0,0,28792,0,"Citizen of New Avalon"),
(28942,1,6,"You're not taking me without a fight!",12,0,100,0,0,0,28787,0,"Citizen of New Avalon"),
(28942,2,0,"I assure you this much, Quimby, you won't be getting my vote next term!",12,0,100,0,0,0,29109,0,"Citizen of New Avalon"),
(28942,2,1,"I want on that last ship! Don't leave us!",12,0,100,0,0,0,29113,0,"Citizen of New Avalon"),
(28942,2,2,"If you don't come out, we'll tear this place apart!",12,0,100,0,0,0,29105,0,"Citizen of New Avalon"),
(28942,2,3,"My whole family's been killed! Where was the army when we needed them most?",12,0,100,0,0,0,29100,0,"Citizen of New Avalon"),
(28942,2,4,"Naxxramas is gone? Who cares! Acherus is here now and the death knights are killing everybody!",12,0,100,0,0,0,29108,0,"Citizen of New Avalon"),
(28942,2,5,"No more lies, Quimby! We want answers!",12,0,100,0,0,0,29102,0,"Citizen of New Avalon"),
(28942,2,6,"QUIMBY!!!!!!",12,0,100,0,0,0,29115,0,"Citizen of New Avalon"),
(28942,2,7,"So much for the Scarlet 'paradise!'",12,0,100,0,0,0,29114,0,"Citizen of New Avalon"),
(28942,2,8,"The Scourge are running freely through the streets!",12,0,100,0,0,0,29099,0,"Citizen of New Avalon"),
(28942,2,9,"This is a slap in the face! We demand answers!",12,0,100,0,0,0,29111,0,"Citizen of New Avalon"),
(28942,2,10,"We were promised safety! Security!",12,0,100,0,0,0,29098,0,"Citizen of New Avalon"),
(28942,2,11,"We're done for! Save us, Quimby!",12,0,100,0,0,0,29104,0,"Citizen of New Avalon"),
(28942,2,12,"What's 'Crimson Dawn!' We deserve to know the truth, Quimby!",12,0,100,0,0,0,29107,0,"Citizen of New Avalon"),
(28942,2,13,"Where are those ships going, Quimby! Tell us the truth!",12,0,100,0,0,0,29103,0,"Citizen of New Avalon"),
(28942,2,14,"You're useless, Quimby!",12,0,100,0,0,0,29110,0,"Citizen of New Avalon"),
(28942,2,15,"Everybody is dying! Help us!",12,0,100,0,0,0,29106,0,"Citizen of New Avalon");

-- Scarlet Miner
UPDATE creature SET spawntimesecs = 60 WHERE id = 28822;
