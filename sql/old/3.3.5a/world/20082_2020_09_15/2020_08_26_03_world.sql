-- Crushridge Warmonger casts Frenzy when nearby Crushridge ogre dies, handled by spell 9144
UPDATE `smart_scripts` SET `event_type` = 8, `event_param1` = 9144, `event_param2` = 0, `action_param2` = 0, `target_type` = 1, `comment` = "Crushridge Warmonger - On Spellhit 'Crushridge Death' - Cast 'Frenzy' (No Repeat)" WHERE `entryorguid` = 2287 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `event_flags` = 0, `comment` = "Crushridge Warmonger - On Link - Say Line 1" WHERE `entryorguid` = 2287 AND `source_type` = 0 AND `id` = 3;

UPDATE `creature_text` SET `BroadcastTextId` = 1151, `Text` = "%s goes into a rage after seeing a friend fall in battle!" WHERE `CreatureID` = 2287 AND `GroupID` = 1 AND `ID` = 0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 9144;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,9144,0,0,31,0,3,2287,0,0,0,0,"","Group 0: Spell 'Crushridge Death' (Effect 0) targets creature 'Crushridge Warmonger'");

-- Only Crushridge Enforcer are spawned in the same place
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2256 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2287 AND `source_type` = 0 AND `id` = 4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2256,0,2,0,6,0,100,0,0,0,0,0,0,11,9144,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crushridge Enforcer - On Death - Cast 'Crushridge Death'"),
(2287,0,4,0,6,0,100,0,0,0,0,0,0,11,9144,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crushridge Warmonger - On Death - Cast 'Crushridge Death'");

-- Stromgarde Vindicator casts Vengeance when nearby Stromgarde human dies, handled by spell 8894
UPDATE `smart_scripts` SET `link` = 1, `event_type` = 8, `event_flags` = 0, `event_param1` = 8894, `event_param2` = 0, `target_type` = 1, `comment` = "Stromgarde Vindicator - On Spellhit 'Stromgarde Death' - Cast 'Vengeance'" WHERE `entryorguid` = 2585 AND `source_type` = 0 AND `id` = 0;

-- Same emote https://youtu.be/hGqHgOS5igQ?t=321
DELETE FROM `creature_text` WHERE `CreatureID` = 2585;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(2585,0,0,"%s goes into a rage after seeing a friend fall in battle!",16,0,100,0,0,0,1151,0,"Stromgarde Vindicator");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 8894;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,8894,0,0,31,0,3,2585,0,0,0,0,"","Group 0: Spell 'Stromgarde Death' (Effect 0) targets creature 'Stromgarde Vindicator'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 2585 AND `source_type` = 0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2583 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2584 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2585,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stromgarde Vindicator - On Link - Say Line 0"),
(2585,0,2,0,6,0,100,0,0,0,0,0,0,11,8894,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stromgarde Vindicator - On Death - Cast 'Stromgarde Death'"),
(2583,0,2,0,6,0,100,0,0,0,0,0,0,11,8894,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stromgarde Troll Hunter - On Death - Cast 'Stromgarde Death'"),
(2584,0,2,0,6,0,100,0,0,0,0,0,0,11,8894,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stromgarde Defender - On Death - Cast 'Stromgarde Death'");

-- Twilight Avenger casts Vengeance when nearby Twilight human dies, found no spell
-- Source: https://youtu.be/97IAZW-rHQQ?t=72
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11880 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11881 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11882 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11883 AND `source_type` = 0 AND `id` = 4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11880,0,0,1,2,0,100,1,0,30,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Avenger - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(11880,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Avenger - On Link - Say Line 0"),
(11880,0,2,3,38,0,100,0,0,1,0,0,0,11,8602,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Avenger - On Data Set 0 1 - Cast 'Vengeance'"),
(11880,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Avenger - On Link - Say Line 1"),
(11880,0,4,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,11880,20,0,0,0,0,0,0,"Twilight Avenger - On Death - Set Data 0 1 (Twilight Avenger)"),
(11881,0,2,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,11880,20,0,0,0,0,0,0,"Twilight Geolord - On Death - Set Data 0 1 (Twilight Avenger)"),
(11882,0,4,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,11880,20,0,0,0,0,0,0,"Twilight Stonecaller - On Death - Set Data 0 1 (Twilight Avenger)"),
(11883,0,4,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,11880,20,0,0,0,0,0,0,"Twilight Master - On Death - Set Data 0 1 (Twilight Avenger)");

DELETE FROM `creature_text` WHERE `CreatureID` = 11880 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(11880,1,0,"%s goes into a rage after seeing a friend fall in battle!",16,0,100,0,0,0,1151,0,"Twilight Avenger");

-- Auchenai Necromancer - Shadow Mend
UPDATE `smart_scripts` SET `event_param5` = 15, `target_type` = 7, `target_param3` = 0 WHERE `entryorguid` = 18702 AND `source_type` = 0 AND `id` IN (4,5);

-- Shadowsword Commander - Battle Shout is used on timer (confirmed by sniffs)
UPDATE `smart_scripts` SET `event_type` = 0, `event_param1` = 1000, `event_param2` = 1000, `target_type` = 1, `comment` = "Shadowsword Commander - In Combat - Cast 'Battle Shout'" WHERE `entryorguid` = 25837 AND `source_type` = 0 AND `id` = 1;

-- Now after cleaning we can update all target types and add distance
UPDATE `smart_scripts` SET `event_param5` = 40, `target_type` = 7, `target_param2` = 0, `target_param3` = 0 WHERE `source_type` = 0 AND `event_type` = 74 AND `action_type` = 11 AND `action_param1` IN (547,913,1026,2054,3627,4961,6063,8362,10310,11431,11640,11986,12039,12160,12491,13952,15493,15586,15981,17138,17613,17843,20664,22883,25058,29170,29427,30643,31713,33324,33642,34945,37260,37479,37979,38209,38210,38899,44479,46029,48700,49204,52774,55597,56919,58980,59160,59252,61326);
UPDATE `smart_scripts` SET `event_param5` = 30, `target_type` = 7, `target_param2` = 0, `target_param3` = 0 WHERE `source_type` = 0 AND `event_type` = 74 AND `action_type` = 11 AND `action_param1` IN (3229,3477,17201,20656,49805,55598);
UPDATE `smart_scripts` SET `event_param5` = 20, `target_type` = 7, `target_param2` = 0, `target_param3` = 0 WHERE `source_type` = 0 AND `event_type` = 74 AND `action_type` = 11 AND `action_param1` IN (17233);
UPDATE `smart_scripts` SET `event_param5` = 10, `target_type` = 7, `target_param2` = 0, `target_param3` = 0 WHERE `source_type` = 0 AND `event_type` = 74 AND `action_type` = 11 AND `action_param1` IN (7106,7154);
