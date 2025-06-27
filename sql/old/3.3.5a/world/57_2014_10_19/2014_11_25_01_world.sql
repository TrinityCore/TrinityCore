-- Nerub'Ar Victim by DDuarte closes #13621
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|4, `flags_extra`=`flags_extra`|64 WHERE `entry`=25284;
-- Search for Incendicite by Exodius closes #13309
UPDATE `gameobject_loot_template` SET `QuestRequired`=0 WHERE `Entry`=1409 AND `Item`=3340;
-- Feeding Arngrim closes #12826
UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=30423;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30422;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30422;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30422, 0, 0, 1, 8,  0, 100, 0, 56727, 0, 0, 0, 12, 30423, 1, 240000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roaming Jormungar - On Spellhit - Spawn Disembodied Jormungar'),
(30422, 0, 1, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roaming Jormungar - Linked with Previous Event - Despawn');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30423;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30423;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30423, 0, 0, 0, 2,  0, 100, 1, 0, 30, 0, 0, 11, 56732, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - On 30% HP - Summon Arngrim'),
(30423, 0, 1, 2,38,  0, 100, 0, 1, 1, 0, 0, 11, 56731, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - On Spellhit - Cast Kill Credit'),
(30423, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - Linked with Previous Event - Despawn');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30425;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30425;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30425, 0, 0, 0,11,  0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 30423, 200, 0, 0, 0, 0, 0, 'Arngrim - On Spawn - Move to closest disembodied jormungar'),
(30425, 0, 1, 2, 1,  0, 100, 0, 10000, 10000, 30000, 30000, 45, 1, 1, 0, 0, 0, 0, 19, 30423, 20, 0, 0, 0, 0, 0, 'Arngrim - OOC - Cast Ping Jormungar'),
(30425, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arngrim - OOC - Linked with Previous Event - Despawn After 5 seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(13,17) AND `SourceEntry`=56727;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,56727,0,0,31,1,3,30422,0,0,0, '', 'Arngrims Tooth only hits Roaming Jormungar'),
(13,0,56727,0,0,31,1,3,30422,0,0,0, '', 'Arngrims Tooth only hits Roaming Jormungar');

-- Some CPP to SAI conversions closes #12645
-- and yes of keys and cages again realised now the previous commit was not most recent version
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=24035;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE`entry`IN(186491,186492,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24035,2403500,186491,186492,18649100,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490,18649000,24035);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186491, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186492, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186493, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186494, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186495, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186496, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186497, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186498, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186499, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186500, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186501, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186502, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186503, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186504, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186505, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186507, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186508, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186509, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186510, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186511, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186512, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186513, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186514, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186515, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186516, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186517, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186518, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186798, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186883, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186895, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186907, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186908, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186909, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186910, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186911, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186923, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186924, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186929, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186930, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186490, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649000,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - On State Changed - Run Script'),
(18649100, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,24035,0,10,0, 0, 0, 0, 'Gjalerbron Cage - Script - Set Data'),
(18649000, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,24035,0,20,0, 0, 0, 0, 'Large Gjalerbron Cage - Set Data'),
(18649100, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Store Targetlist'),
(18649000, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - Store Targetlist'),
(18649100, 9, 2 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,9,24035,0,10,0, 0, 0, 0, 'Gjalerbron Cage - Script - Send Targetlist'),
(18649000, 9, 2 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,9,24035,0,20,0, 0, 0, 0, 'Large Gjalerbron Cage - Send Targetlist'),
(18649100, 9, 3 ,0, 0, 0, 100, 0, 300000, 300000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Reset Go'),
(18649000, 9, 3 ,0, 0, 0, 100, 0, 300000, 300000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - Script - Reset Go'),
(24035, 0, 0, 1, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - On Data Set - Kill Credit'),
(2403500, 9, 0, 0, 0, 0, 100, 1, 3000, 3000, 0, 0, 33, 24035, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - On Data Set - Kill Credit'),
(2403500, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Say'),
(2403500, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Move Forward'),
(2403500, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Despawn');
-- Whats Haunting With Hill?
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=23555;

DELETE FROM `smart_scripts` WHERE `entryorguid` =23555;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23555, 0, 0, 0, 2,  0, 100, 0, 0, 50, 6000, 11000, 11, 37933, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - On Less than 50% HP - Cast Consume Flesh'),
(23555, 0, 1, 2, 6,  0, 100, 0, 0, 0, 0, 0, 11, 42511, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - On Death - Cast Summon Restless Apparotation'),
(23555, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 11, 42512, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - Linked with Previous Event - Cast Witch Hill Information Credit');

-- Risen Spirit 23554

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=23554;

DELETE FROM `smart_scripts` WHERE `entryorguid` =23554;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23554, 0, 0, 0, 0,  0, 100, 0, 0, 0, 6000, 11000, 11, 43127, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - IC - Intangible Presence'),
(23554, 0, 1, 2, 6,  0, 100, 0, 0, 0, 0, 0, 11, 42511, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - On Death - Cast Summon Restless Apparotation'),
(23554, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 11, 42512, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - Linked with Previous Event - Cast Witch Hill Information Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND  `SourceEntry`IN(23554,23555) AND `SourceId`=0;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,23554,0,0,9,0,11180,0,0,0,0,'','AI Only executes if player is on Whats haunting witch Hill'),
(22,2,23555,0,0,9,0,11180,0,0,0,0,'','AI Only executes if player is on Whats haunting witch Hill');
