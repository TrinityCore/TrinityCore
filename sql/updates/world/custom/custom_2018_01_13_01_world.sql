-- Creature Josiah Event Trigger 50415 SAI
SET @ENTRY := 50415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 44, 171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Set phase id to 171 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 2000 ms (and later repeats every 0 and 0 ms) - Owner/Summoner: Talk 0 // ");

DELETE FROM `creature_text` WHERE `CreatureID` IN (50415, 35911, 35552, 35551, 35753);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(50415, 0, 0, 'You''ve been bitten by a worgen.  It''s probably nothing, but it sure stings a little.$B$B|TInterface\\Icons\\INV_Misc_monsterfang_02.blp:32|t', 42, 0, 100, 0, 0, 0, 50192, 'Josiah Event Trigger to Player'),
(35911, 0, 0, 'If we can make it past the gates into Duskhaven we''ll be safe.  The eastern mountains are virtually impassable.', 12, 0, 100, 1, 0, 19696, 36107, 'King Genn Greymane to Player'),
(35911, 1, 0, 'We were fools to take up arms against each other, Darius.  The worgen would''ve never stood a chance.', 12, 0, 100, 1, 0, 19696, 36108, 'King Genn Greymane to Player'),

(35551, 0, 0, 'I''ll stay behind with the Royal Guard, father.  It is my duty to Gilneas.', 12, 0, 100, 1, 0, 19696, 36106, 'Prince Liam Greymane to Player'),
(35552, 0, 0, 'We need to keep the worgen''s attention in the city, Genn.  It''s the only shot we have for the survivors to make it to Duskhaven.', 12, 0, 100, 66, 0, 19696, 36103, 'Lord Darius Crowley to Player'),
(35552, 1, 0, 'Not a chance, boy.  Gilneas is going to need its king''s undivided attention.  Can''t have your father wondering whether his child is alive or not.', 12, 0, 100, 66, 0, 19696, 36104, 'Lord Darius Crowley to Player'),
(35552, 2, 0, 'My men and I will hole up inside the Light''s Dawn Cathedral.  I''ve already given the order and the cannons are on their way.  Lead our people well, Genn.', 12, 0, 100, 66, 0, 19696, 36105, 'Lord Darius Crowley to Player'),
(35753, 0, 0, 'Help!  Up here!', 14, 0, 100, 0, 0, 0, 46756, 'Krennan Aranas to Player');

UPDATE `creature_template` SET `scriptname`= 'npc_josiah_avery' WHERE `entry`= 35370;

DELETE FROM `conditions` WHERE `SourceEntry`= 67350 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 67350, 0, 0, 31, 0, 3, 35374, 0, 0, 0, '', 'Summon Josiah - Target Lab Trigger'),
(13, 4, 67350, 0, 0, 31, 0, 3, 35374, 0, 0, 0, '', 'Summon Josiah - Target Lab Trigger');

UPDATE `creature_template` SET `InhabitType`= 1 | 8 WHERE `entry` IN (35907, 35504, 35509, 50474);

DELETE FROM `creature_sparring_template` WHERE `AttackerEntry` IN (50471, 50474, 35505, 35504, 35509);
INSERT INTO `creature_sparring_template` (`AttackerEntry`, `VictimEntry`, `HealthLimitPct`) VALUES
(50471, 50474, 90.0),
(50474, 50471, 90.0),
(35505, 35504, 90.0),
(35509, 35505, 90.0),
(35505, 35509, 90.0);

UPDATE `creature_addon` SET `emote`= 214 WHERE `guid` IN (376746, 376788, 376779, 376756, 376694, 376702, 376737, 376698, 376726, 376704, 376713);
UPDATE `creature_addon` SET `emote`= 333 WHERE `guid` IN (376711, 376790, 376757, 376703, 376698, 376695, 376736, 376768, 376716, 376754);

UPDATE `creature` SET `SpawnDist`= 5 WHERE `id`= 35229;

-- Creature Gilneas City Guard 35504 SAI
SET @ENTRY := 35504;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, 11, 67595, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 2000 ms) - Self: Cast spell 67595 on Victim // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 2000, 2000, 49, 0, 0, 0, 0, 0, 0, 11, 35505, 20, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 2000 ms (and later repeats every 2000 and 2000 ms) - Self: Attack Creature Bloodfang Ripper (35505) in 20 yd // ");

-- Creature Gilneas City Guard 50474 SAI
SET @ENTRY := 50474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 2000, 49, 0, 0, 0, 0, 0, 0, 11, 50471, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 2000 ms) - Self: Attack Creature Afflicted Gilnean (50471) in 10 yd // ");

-- Creature Afflicted Gilnean 50474 SAI
SET @ENTRY := 50471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 2000, 49, 0, 0, 0, 0, 0, 0, 11, 50474, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 2000 ms) - Self: Attack Creature Gilneas City Guard (50474) in 10 yd // ");

-- Creature King Genn Greymane 35911 SAI
SET @ENTRY := 35911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14294, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 14294 - Self: Talk 0 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3555200, 0, 0, 0, 0, 0, 10, 377011, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3555200 // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3591100, 0, 0, 0, 0, 0, 10, 377012, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3591100 // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3555100, 0, 0, 0, 0, 0, 10, 377026, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3555100 // ");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (35552, 35551);
DELETE FROM `smart_scripts` WHERE `entryorguid`=3555200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3555200,9,0,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Darius Crowley - Talk 0"),
(3555200,9,1,0,0,0,100,0,14000,14000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Darius Crowley - Talk 1"),
(3555200,9,2,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Darius Crowley - Talk 2");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3591100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3591100,9,0,0,0,0,100,0,39000,39000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Genn Greymane - Talk 1");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3555100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3555100,9,0,0,0,0,100,0,16000,16000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Liam Greymane - Talk 0");
