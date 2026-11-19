--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 52839;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(52839,52775,1,"'Summon Escort Aura' - On Aura Apply - Target - Cast 'Summon Escort'"),
(52839,52842,1,"'Summon Escort Aura' - On Aura Apply - Target - Cast 'Scourge Disguise'"), -- Can't fade
(52839,-51966,1,"'Summon Escort Aura' - On Aura Apply - Target - Remove Aura 'Scourge Disguise'"); -- Can fade

UPDATE `creature_template` SET `minlevel` = 76, `maxlevel` = 76 WHERE `entry` = 28948;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28948 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2894800 AND 2894806 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28948,0,0,0,11,0,100,0,0,0,0,0,0,80,2894800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Spawn - Run Script"),
(28948,0,1,0,58,0,100,0,0,2894800,0,0,0,80,2894801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),
(28948,0,2,0,58,0,100,0,0,2894801,0,0,0,80,2894802,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),
(28948,0,3,0,58,0,100,0,0,2894802,0,0,0,80,2894803,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),
(28948,0,4,0,58,0,100,0,0,2894803,0,0,0,80,2894804,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),
(28948,0,5,0,58,0,100,0,0,2894804,0,0,0,80,2894805,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),
(28948,0,6,0,58,0,100,0,0,2894805,0,0,0,80,2894806,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Waypoint Finished - Run Script"),

(2894800,9,0,0,0,0,100,0,0,0,0,0,0,11,61707,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Cast 'Malmortis Heartbeat'"),
(2894800,9,1,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 0"),
(2894800,9,2,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 1"),
(2894800,9,3,0,0,0,100,0,3000,3000,0,0,0,53,0,2894800,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894801,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
-- https://www.wowhead.com/quest=12710/disclosure#comments:id=497397
-- Ever since his arrival from Drak'Tharon, the master has spoken of the time you would be joining him here.
-- (If you have completed the Cleansing Drak'tharon questline in Grizzly Hills)
(2894801,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 3"),
(2894801,9,2,0,0,0,100,0,5000,5000,0,0,0,53,0,2894801,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894802,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894802,9,1,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 4"),
(2894802,9,2,0,0,0,100,0,5000,5000,0,0,0,53,0,2894802,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894803,9,0,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 5"),
(2894803,9,1,0,0,0,100,0,8000,8000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894803,9,2,0,0,0,100,0,0,0,0,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 6"),
(2894803,9,3,0,0,0,100,0,3000,3000,0,0,0,11,52851,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Cast 'Escort Dummy 00'"),
(2894803,9,4,0,0,0,100,0,0,0,0,0,0,53,0,2894803,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894804,9,0,0,0,0,100,0,0,0,0,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 7"),
(2894804,9,1,0,0,0,100,0,8000,8000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894804,9,2,0,0,0,100,0,0,0,0,0,0,1,8,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 8"),
(2894804,9,3,0,0,0,100,0,5000,5000,0,0,0,53,0,2894804,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894805,9,0,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 9"),
(2894805,9,1,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894805,9,2,0,0,0,100,0,0,0,0,0,0,1,10,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 10"),
(2894805,9,3,0,0,0,100,0,8000,8000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.769911050796508789,"Malmortis - On Script - Set Orientation"),
(2894805,9,4,0,0,0,100,0,0,0,0,0,0,1,11,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 11"),
(2894805,9,5,0,0,0,100,0,9000,9000,0,0,0,1,12,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 12"),
(2894805,9,6,0,0,0,100,0,9000,9000,0,0,0,53,0,2894805,0,0,0,3,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Start Waypoint"),

(2894806,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894806,9,1,0,0,0,100,0,0,0,0,0,0,1,13,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 13"),
(2894806,9,2,0,0,0,100,0,5000,5000,0,0,0,1,14,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 14"),
(2894806,9,3,0,0,0,100,0,0,0,0,0,0,11,53100,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Cast 'Escort Dummy 01'"),
(2894806,9,4,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.611741304397583007,"Malmortis - On Script - Set Orientation"),
(2894806,9,5,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Set Orientation Owner"),
(2894806,9,6,0,0,0,100,0,0,0,0,0,0,1,15,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Say Line 15"),
(2894806,9,7,0,0,0,100,0,2000,2000,0,0,0,11,53101,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Malmortis - On Script - Cast 'Kill Credit'"),
(2894806,9,8,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Malmortis - On Script - Despawn");

DELETE FROM `waypoints` WHERE `entry` = 28948;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2894800 AND 2894805;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(2894800,1,6232.341,-1965.3967,484.78174,"Malmortis"),
(2894800,2,6218.6577,-1962.0309,484.88232,"Malmortis"),

(2894801,1,6205.6074,-1941.303,484.9172,"Malmortis"),
(2894801,2,6191.6187,-1930.0017,485.09485,"Malmortis"),
(2894801,3,6175.131,-1934.6721,484.86813,"Malmortis"),
(2894801,4,6156.749,-1953.0284,484.90216,"Malmortis"),

(2894802,1,6119.237,-1976.635,484.90793,"Malmortis"),
(2894802,2,6093.954,-1990.4447,484.91873,"Malmortis"),
(2894802,3,6089.3467,-2014.2975,484.8763,"Malmortis"),
(2894802,4,6113.093,-2041.1102,484.87854,"Malmortis"),
(2894802,5,6108.405,-2060.9314,484.78174,"Malmortis"),

(2894803,1,6136.7593,-2078.6272,484.88394,"Malmortis"),
(2894803,2,6157.708,-2107.487,485.1209,"Malmortis"),
(2894803,3,6156.6816,-2122.8428,485.22507,"Malmortis"),
(2894803,4,6140.6284,-2128.3413,485.36212,"Malmortis"),
(2894803,5,6118.48,-2123.0757,473.55508,"Malmortis"),
(2894803,6,6121.2275,-2108.0789,473.56277,"Malmortis"),
(2894803,7,6127.8154,-2108.126,473.33722,"Malmortis"),
(2894803,8,6146.062,-2111.0286,461.31088,"Malmortis"),
(2894803,9,6156.9985,-2110.6106,461.3106,"Malmortis"),
(2894803,10,6160.2593,-2087.5093,461.30475,"Malmortis"),
(2894803,11,6148.6777,-2072.7808,461.30435,"Malmortis"),

(2894804,1,6154.8696,-2058.052,461.29977,"Malmortis"),
(2894804,2,6144.377,-2044.998,460.95804,"Malmortis"),
(2894804,3,6139.7783,-2046.457,461.31024,"Malmortis"),

(2894805,1,6161.379,-2028.9777,458.9426,"Malmortis"),
(2894805,2,6172.3604,-2019.7084,455.12225,"Malmortis");

UPDATE `creature_text` SET `Emote` = 4 WHERE `CreatureID` = 28948 AND `GroupID` = 0;
UPDATE `creature_text` SET `Emote` = 396 WHERE `CreatureID` = 28948 AND `GroupID` = 1;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 3;
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 28948 AND `GroupID` = 4;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 5;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 6;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 7;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 8;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 9;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 10;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 11;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 12;
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 28948 AND `GroupID` = 13;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 28948 AND `GroupID` = 14;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 28932;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(28932,0,0,1,0,0,0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28932;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-80426,-80427,-96663,-96664,-96671,-96798,-96800,-96865) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-80426,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52681,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam RH'"),
(-80427,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam LH'"),
(-96663,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52681,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam RH'"),
(-96664,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam LH'"),
(-96671,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52681,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam RH'"),
-- This one falls to the ground
(-96798,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam LH'"),
(-96800,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52681,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam RH'"),
(-96865,0,0,0,1,0,100,0,0,0,17000,17000,0,11,52686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blight Effect Bunny - Out of Combat - Cast 'Voltarus Blight Beam LH'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (52681,52686);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52681,0,0,31,0,3,28931,0,0,0,0,"","Group 0: Spell 'Voltarus Blight Beam RH' (Effect 0) targets creature 'Blightblood Troll'"),
(13,1,52686,0,0,31,0,3,28931,0,0,0,0,"","Group 0: Spell 'Voltarus Blight Beam LH' (Effect 0) targets creature 'Blightblood Troll'");
