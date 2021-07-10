UPDATE `creature_template` SET `unit_flags`=33555208 WHERE `entry`=42617;

DELETE FROM `creature_addon` WHERE `guid` IN (275083, 275049, 275051);
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `cyclicSplinePathId`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(275083, 0, 0, 0, 0, 0, 234, 0, 0, 0, 0, NULL),
(275049, 0, 0, 0, 0, 0, 234, 0, 0, 0, 0, NULL),
(275051, 0, 0, 0, 0, 0, 234, 0, 0, 0, 0, NULL);

UPDATE `creature_addon` SET `emote`=234 WHERE `guid`=27505;

DELETE FROM `page_text` WHERE `ID`=3633;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `VerifiedBuild`) VALUES
(3633, 'Minions, our leader has spoken. You are to sack Sentinel Hill and free the admiral. You may keep anything that you find in your rampage.\n\n-Helix', 0, 0);

 -- Marshal Gryan Stoutmantle
SET @ENTRY := 234;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI", ScriptName="" WHERE entry=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 5993, 1, 60000, 60000, 80, 23400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[5993] set to 1 (wait 60000 - 60000 ms before next event trigger) - Self: Start timed action list id #23400 (update out of combat)"),
(@ENTRY, 0, 1, 2, 20, 0, 100, 0, 26286, 0, 0, 0, 80, 23401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On player rewarded quest In Defense of Westfall (26286) - Self: Start timed action list id #23401 (update out of combat)"),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 64, 26286, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On player rewarded quest In Defense of Westfall (26286) - Self: storedTarget[26286] = Rewarded player"),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 8, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 10, 275323, 42635, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Look at Creature Ripsnarl (42635) with guid 275323"),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 8, 2, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.2915436, "On movement of type POINT_MOTION_TYPE inform, point 2 - Self: Set orientation to 1.2915436");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 234 AND SourceId = 0;

 -- Timed list 23401
SET @ENTRY := 23401;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 9;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "After 0 seconds - Self: Set walk"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10512.56, 1046.6771, 60.51798, 0, "After 0 seconds - Self: Move to position (-10512.56, 1046.6771, 60.51798, 0) (point id 1)"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 1, 0, 0, 0, 12, 26286, 0, 0, 0, 0, 0, 0, "After 5 seconds - Self: Talk 2 to 26286"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 8500, 8500, 0, 0, 100, 26286, 0, 0, 0, 0, 0, 10, 275323, 42635, 0, 0, 0, 0, 0, "After 8.5 seconds - Send stored target storedTarget[26286] to Creature Ripsnarl (42635) with guid 275323"),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 26286, 1, 0, 0, 0, 0, 10, 275323, 42635, 0, 0, 0, 0, 0, "After 0 seconds - Creature Ripsnarl (42635) with guid 275323: Set creature data #26286 to 1"),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 1, 0, 0, 0, 12, 26286, 0, 0, 0, 0, 0, 0, "After 7 seconds - Self: Talk 3 to 26286"),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 69, 2, 0, 0, 0, 0, 0, 8, 0, 0, 0, -10508.792, 1045.2327, 60.596703, 0, "After 6 seconds - Self: Move to position (-10508.792, 1045.2327, 60.596703, 0) (point id 2)");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 23401 AND SourceId = 9;

 -- Ripsnarl
SET @ENTRY := 42635;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI", ScriptName="" WHERE entry=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 5993, 1, 60000, 60000, 80, 4263500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[5993] set to 1 (wait 60000 - 60000 ms before next event trigger) - Self: Start timed action list id #4263500 (update out of combat)"),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 26286, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 12, 26286, 0, 0, 0, 0, 0, 0, "On data[26286] set to 1 - Self: Talk 1 to 26286");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 42635 AND SourceId = 0;

UPDATE `gameobject` SET `position_y`=1006.5087, `position_z`=31.759172, `rotation0`=0.009524973, `rotation1`=0.05605585, `rotation2`=0.99837375, `rotation3`=-0.0041101496 WHERE `guid`=208344;
UPDATE `gameobject` SET `position_x`=-9979.234, `position_y`=1007.1389, `position_z`=31.137272, `rotation0`=0.087147824, `rotation1`=0.0011408626, `rotation2`=0.013040186, `rotation3`=0.9961094 WHERE `guid`=208345;
UPDATE `gameobject` SET `position_x`=-9978.594, `position_y`=1007.7535, `position_z`=32.285603, `rotation0`=0.08098307, `rotation1`=-0.024925804, `rotation2`=-0.651451, `rotation3`=0.7539444 WHERE `guid`=208347;
UPDATE `gameobject` SET `position_x`=-9979.134, `position_y`=1007.3246, `position_z`=32.758778, `rotation0`=0.10068505, `rotation1`=-0.025143968, `rotation2`=0.052290976, `rotation3`=0.99322504 WHERE `guid`=208346;
UPDATE `gameobject` SET `position_x`=-10924.16, `position_y`=995.36804, `position_z`=34.95429, `rotation0`=0.004355991, `rotation1`=0.056691915, `rotation2`=0.9983822, `rotation3`=0.00024691413 WHERE `guid`=208205;
UPDATE `gameobject` SET `position_x`=10924.772, `position_y`=996.4549, `position_z`=35.676746, `rotation0`=0.03510426, `rotation1`=-0.026255073, `rotation2`=-0.6750812, `rotation3`=0.7364399 WHERE `guid`=208204;
UPDATE `gameobject` SET `position_x`=-10924.998, `position_y`=994.94965, `position_z`=36.355797, `rotation0`=-0.09091198, `rotation1`=-0.016616998, `rotation2`=0.040289015, `rotation3`=0.9949049 WHERE `guid`=208203;
UPDATE `gameobject` SET `position_x`=-10924.993, `position_y`=996.3403, `position_z`=34.506863, `rotation2`=-0.70710665, `rotation3`=0.7071069 WHERE `guid`=208202;

DELETE FROM `spell_proc` WHERE `SpellId` = 79522;
INSERT INTO `spell_proc` (`SpellId`, `Cooldown`) VALUES (79522, 1500);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (79522, 79523);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79522, 'spell_westfall_sniper_fire_proc'),
(79523, 'spell_westfall_sniper_fire');

DELETE FROM `creature` WHERE `guid` IN (396660, 396661);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(396660, 42654, 0, 40, 5289, 1, 169, 0, 0, 0, -11127.8330078125, 547.529541015625, 70.5027313232421875, 3.40339207649230957, 120, 0, 0, 1930, 0, 0, 0, 0, 0, 15595), -- Helix's Lumbering Oaf (Area: Mortwake's Tower - Difficulty: 0) (Auras: 79531 - Apply Quest Invis Zone Magic)
(396661, 42662, 0, 40, 5289, 1, 169, 0, 0, 0, -11131.814453125, 546.73956298828125, 70.4610595703125, 0.244346097111701965, 120, 0, 0, 6141, 0, 0, 0, 0, 0, 15595); -- Shadowy Figure (Area: Mortwake's Tower - Difficulty: 0) (Auras: 79192 - Shroud of Shadows, 79531 - Apply Quest Invis Zone Magic)

DELETE FROM `creature_addon` WHERE `guid` IN (396660, 396661);
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(396660, 0, 0, 65536, 1, 0, '79531'), -- Helix's Lumbering Oaf - 79531 - Apply Quest Invis Zone Magic
(396661, 0, 0, 65536, 1, 0, '79192 79531'); -- Shadowy Figure - 79192 - Shroud of Shadows, 79531 - Apply Quest Invis Zone Magic

UPDATE `creature_template_addon` SET `bytes1`=65536,`auras`=79531 WHERE `entry`=42655;

UPDATE `creature_template` SET `unit_flags`=33554432, `VehicleId`=911 WHERE `entry`=42654;
UPDATE `creature_template` SET `unit_flags`=33587968, `unit_flags2`=2099200 WHERE `entry`=42662;
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=42655;

DELETE FROM `vehicle_template_accessory` WHERE `entry`=42654 AND `seat_id`=0;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(42654, 42655, 0, 0, 'Helix Gearbreaker on Lumbering Oaf (Mortwake\'s Tower)', 6, 30000);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=42654 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42654, 46598, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (42655, 42662);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42655, 0, 0, 'The gnolls have failed, mistress. ', 12, 0, 100, 1, 0, 0, 42536, 'Helix Gearbreaker to Helix\'s Lumbering Oaf'),
(42655, 1, 0, 'But mistress, the admiral is sti...', 12, 0, 100, 1, 0, 0, 42538, 'Helix Gearbreaker to Shadowy Figure'),
(42655, 2, 0, 'Yes, mistress.', 12, 0, 100, 1, 0, 0, 42540, 'Helix Gearbreaker to Shadowy Figure'),
(42655, 3, 0, 'Moonbrook, mistress?', 12, 0, 100, 6, 0, 0, 42543, 'Helix Gearbreaker to Shadowy Figure'),
(42662, 0, 0, 'They provided the distraction I required. We continue as planned.', 12, 0, 100, 1, 0, 0, 42537, 'Shadowy Figure to Helix Gearbreaker'),
(42662, 1, 0, 'We will free the admiral during the dawning.', 12, 0, 100, 1, 0, 0, 42539, 'Shadowy Figure to Helix Gearbreaker'),
(42662, 2, 0, 'Judgment day is soon upon us, Helix.', 12, 0, 100, 1, 0, 0, 42541, 'Shadowy Figure to Helix Gearbreaker'),
(42662, 3, 0, 'Call for the people. I wish to speak to them one last time before the dawning.', 12, 0, 100, 1, 0, 0, 42542, 'Shadowy Figure to Helix Gearbreaker'),
(42662, 4, 0, 'Aye. Tonight.', 12, 0, 100, 273, 0, 0, 42544, 'Shadowy Figure to Helix Gearbreaker');

 -- Clientside area trigger 5994
SET @ENTRY := 5994;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 2;
DELETE FROM areatrigger_scripts WHERE entry = @ENTRY;
INSERT INTO areatrigger_scripts(entry, ScriptName) VALUES(@ENTRY, "SmartTrigger");
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 2, 0, 1, 46, 0, 100, 0, 0, 0, 0, 0, 64, 5994, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On trigger - Self: storedTarget[5994] = Triggering player"),
(@ENTRY, 2, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 100, 5994, 0, 0, 0, 0, 0, 10, 396661, 42662, 0, 0, 0, 0, 0, "On trigger - Send stored target storedTarget[5994] to Creature Shadowy Figure (42662) with guid 396661"),
(@ENTRY, 2, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 5994, 1, 0, 0, 0, 0, 10, 396661, 42662, 0, 0, 0, 0, 0, "On trigger - Creature Shadowy Figure (42662) with guid 396661: Set creature data #5994 to 1");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 5994 AND SourceId = 2;

INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, Comment) VALUES
(22, 1, 5994, 2, 0, 9, 0, 26290, 0, 0, 0, "Action invoker has quest Secrets of the Tower (26290) active"),
(22, 1, 5994, 2, 0, 28, 0, 26290, 0, 0, 1, "Action invoker hasn't completed quest Secrets of the Tower (26290) (or completed and rewarded)"),
(22, 1, 5994, 2, 0, 1, 0, 79528, 0, 0, 0, "Action invoker has aura of spell Potion of Shrouding (79528), effect EFFECT_0");

 -- Shadowy Figure
SET @ENTRY := 42662;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI", ScriptName="" WHERE entry=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 5994, 1, 0, 0, 80, 4266200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[5994] set to 1 - Self: Start timed action list id #4266200 (update out of combat)");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 42662 AND SourceId = 0;

 -- Timed list 4266200
SET @ENTRY := 4266200;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 9;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 5994, 0, 0, 0, 0, 0, 11, 42655, 5, 0, 0, 0, 0, 0, "After 0 seconds - Send stored target storedTarget[5994] to Creature Helix Gearbreaker (42655) in 5 yd"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5994, 1, 0, 0, 0, 0, 11, 42655, 5, 0, 0, 0, 0, 0, "After 0 seconds - Creature Helix Gearbreaker (42655) in 5 yd: Set creature data #5994 to 1"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6 seconds - Self: Talk 0 to Self"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 11 seconds - Self: Talk 1 to Self"),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 10 seconds - Self: Talk 2 to Self"),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6 seconds - Self: Talk 3 to Self"),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 4, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 15 seconds - Self: Talk 4 to Self"),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 11, 79534, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 3.5 seconds - Self: Cast spell Quest Credit: 26290 (79534) on Self");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 4266200 AND SourceId = 9;

 -- Helix Gearbreaker
SET @ENTRY := 42655;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI", ScriptName="" WHERE entry=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 5994, 1, 0, 0, 80, 4265500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[5994] set to 1 - Self: Start timed action list id #4265500 (update out of combat)");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 42655 AND SourceId = 0;

 -- Timed list 4265500
SET @ENTRY := 4265500;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 9;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 0 seconds - Self: Talk 0 to Self"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 13500, 13500, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 13.5 seconds - Self: Talk 1 to Self"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 9500, 9500, 0, 0, 1, 2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 9.5 seconds - Self: Talk 2 to Self"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 19500, 19500, 0, 0, 1, 3, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 19.5 seconds - Self: Talk 3 to Self");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 4265500 AND SourceId = 9;

DELETE FROM `creature_text` WHERE `CreatureID` = 7024;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(7024, 0, 0, 'I\'ve got your back, $n.', 15, 0, 100, 0, 0, 0, 42531, 'Agent Kearnen to Player'),
(7024, 0, 1, 'Headshot!', 15, 0, 100, 0, 0, 0, 42532, 'Agent Kearnen to Player'),
(7024, 0, 2, 'Not a chance.', 15, 0, 100, 0, 0, 0, 42533, 'Agent Kearnen to Player'),
(7024, 0, 3, 'Easy peasy.', 15, 0, 100, 0, 0, 0, 42534, 'Agent Kearnen to Player'),
(7024, 0, 4, 'Got him!', 15, 0, 100, 0, 0, 0, 42535, 'Agent Kearnen to Player');

DELETE FROM `spell_area` WHERE `area` = 40 AND `spell` = 79522;
INSERT INTO `spell_area` (`area`, `spell`, `quest_start`, `quest_start_status`, `quest_end`, `quest_end_status`, `flags`, `aura_spell`, `racemask`, `gender`) VALUES
(40, 79522, 26290, 10, 0, 11, 3, 0, 0, 2);
