
UPDATE `creature_template` SET `ScriptName`= 'npc_th_gurgthock' WHERE `entry`= 46935;
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 34816, `flags_extra`= 128 WHERE `entry`= 48549;

DELETE FROM `creature_text` WHERE `CreatureID` IN (46935, 46945, 46946);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Hurp Derp
(46935, 0, 0, 'The grand Crucible of Carnage awaits, $n. Remember, once a battle starts you have to stay in the arena. WIN OR DIE!', 12, 0, 100, 1, 0, 0, 46988, 'Gurgthock to Player'),
(46935, 1, 0, 'Here we are once again, ladies and gentlemen. The epic struggle between life and death in the Crucible of Carnage! For this round we have $n versus... a really fat ogre? Wait, seriously?! That\'s all we could come up with on short notice? What am I paying you for? ', 14, 0, 100, 22, 0, 0, 46989, 'Gurgthock to Player'),
(46935, 2, 0, 'Whatever, let the fight begin!', 14, 0, 100, 22, 0, 0, 46990, 'Gurgthock to Player'),
(46935, 3, 0, 'W-W-W-WINNER! We have a winner! Good job and stuff!', 14, 0, 100, 15, 0, 0, 46998, 'Gurgthock to Player'),
-- Second Quest (Alliance)
(46935, 4, 0, 'The battle is about to begin! $n vs. the vicious Dragonmaw, Torg Drakeflayer! I THINK he\'s vicious anyway - hard to tell. I just let him because they let us take over their old arena here. Here\'s hoping for some blood!', 14, 0, 100, 22, 0, 0, 46991, 'Gurgthock to Player'),
(46935, 5, 0, 'OOOOOOOH! Check that mess out! Amazing win! Way to stick it through him!', 14, 0, 100, 22, 0, 0, 48556, 'Gurgthock to Player'),
-- Second Quest (Horde)
(46935, 6, 0, 'I\'ve got a LITTLE somethin\' special for ya this time, folks! You aren\'t half the man of this half-man! $N vs. the vicious Wildhammer... SULLY KNEECAPPER!!!', 14, 0, 100, 22, 0, 0, 46992, 'Gurgthock to Player'),
(46935, 7, 0, 'This match is sure to be SHORT! Okay, okay, I\'m done. Let the bloodbath begin!', 12, 0, 100, 22, 0, 0, 46993, 'Gurgthock to Player'),
(46935, 8, 0, 'Bah, couldn\'t you have dragged it out a bit! People don\'t pay me when you make it look that easy! Add some theatrics to it, will ya?!', 14, 0, 100, 22, 0, 0, 48557, 'Gurgthock to Player'),
-- Torg Drakeflayer
(46945, 0, 0, 'All of the highlands belong to the Dragonmaw, even this pit!', 14, 0, 100, 22, 0, 0, 46969, 'Torg Drakeflayer'),
(46945, 1, 0, 'Pitiful meat bags! Feel the full force of the Dragonmaw!', 14, 0, 100, 0, 0, 0, 47651, 'Torg Drakeflayer'),
-- Sully Kneecapper
(46946, 0, 0, 'My little sister could best the lot of ya. This ain\'t no arena. This is a nursery!', 14, 0, 100, 22, 0, 0, 46970, 'Sully Kneecapper to Player'),
(46946, 1, 0, 'Perhaps ye filthy animals would like another taste o the dirt!', 14, 0, 100, 0, 0, 0, 47652, 'Sully Kneecapper');

UPDATE `quest_template_addon` SET `SpecialFlags`= 2 WHERE `ID` IN (27863, 27864, 27865);
UPDATE `quest_template_addon` SET `PrevQuestId`= 27863 WHERE `ID` IN (27864, 27865);

DELETE FROM `creature` WHERE `guid`= 383348;
DELETE FROM `creature_addon` WHERE `guid`= 383348;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_th_grab_targeting',
'spell_th_charge');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(94999, 'spell_th_grab_targeting'),
(88540, 'spell_th_charge');

-- Creature Hurp'derp 46944 SAI
SET @ENTRY := 46944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 11000, 12000, 11, 88482, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 10000 max ms (repeat 11000 min 12000 max ms) - Self: Cast spell 88482 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 30000, 30000, 11, 83016, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 15000 min and 15000 max ms (repeat 30000 min 30000 max ms) - Self: Cast spell 83016 on Self // "),
(@ENTRY, 0, 2, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On evade - Self: Despawn instantly // ");

UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271 WHERE `entry`= 46944;

-- Creature Torg Drakeflayer 46945 SAI
SET @ENTRY := 46945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 16, 1, 0, 0, 80, 4694500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1 - Start timed action list id #4694500 // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 21000, 22000, 11, 80182, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 7000 max ms (repeat 21000 min 22000 max ms) - Self: Cast spell 80182 on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 21000, 21000, 31000, 31000, 11, 94999, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 21000 min and 21000 max ms (repeat 31000 min 31000 max ms) - Self: Cast spell 94999 on Self // "),
(@ENTRY, 0, 3, 4, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On evade - storedTarget[0]: Despawn instantly // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn instantly // "),
(@ENTRY, 0, 5, 0, 17, 0, 100, 0, 47476, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On summoned unit Gloomwing (47476)  - Self: Target_0 = Action invoker // "),
(@ENTRY, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On aggro - storedTarget[0]: Set creature data #1 to 0 // "),
(@ENTRY, 0, 7, 0, 27, 0, 100, 0, 0, 0, 0, 0, 1, 1, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Self: Talk 1 // "),
(@ENTRY, 0, 8, 0, 52, 0, 100, 0, 1, 46945, 0, 0, 11, 88540, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When text 1 said by creature Torg Drakeflayer (46945) is over - Self: Cast spell 88540 on Self // "),
(@ENTRY, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On death - storedTarget[0]: Despawn instantly // "),
(@ENTRY, 0, 10, 0, 63, 0, 100, 0, 0, 0, 0, 0, 12, 47476, 8, 0, 0, 0, 0, 8, 0, 0, 0, -4180.601, -5147.3, 26.7149, 0, "When just created - Self: Summon creature Gloomwing (47476) at (-4180.601, -5147.3, 26.7149, 0) // ");

-- TimedActionList  4694500 SAI
SET @ENTRY := 4694500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 2000 min and 2000 max ms (repeat 0 min 0 max ms) - Self: Talk 0 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4182.37, -5148.59, -7.621854, 0, "Update (In Combat) 2500 min and 2500 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4182.37, -5148.59, -7.621854, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Remove UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_IMMUNE_TO_NPC // ");

UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `unit_flags`= 33600, `VehicleId`= 1269 WHERE `entry`= 46945;

-- Creature Gloomwing 47476 SAI
SET @ENTRY := 47476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 60, 1, 100, 0, 1000, 2000, 1000, 4000, 11, 88515, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Every 10000 and 4000 ms (for the first time, timer between 1000 and 2000 ms) - Self: Cast spell 88515 on Owner/Summoner // "),
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 1, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 0 - Self: Set event phase to 1 // ");

DELETE FROM `waypoint_data` WHERE `id`= 47476 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `velocity`) VALUES
(47476 * 10, 1, -4180.6006, -5147.3003, 26.714905, 0, 0),
(47476 * 10, 2, -4160.6006, -5147.3003, 26.714905, 0, 0),
(47476 * 10, 3, -4166.4585, -5161.4424, 26.714905, 0, 0),
(47476 * 10, 4, -4180.6006, -5167.3003, 26.714905, 0, 0),
(47476 * 10, 5, -4194.7427, -5161.4424, 26.714905, 0, 0),
(47476 * 10, 6, -4200.6006, -5147.3003, 26.714905, 0, 0),
(47476 * 10, 7, -4194.7427, -5133.158 , 26.714905, 0, 0),
(47476 * 10, 8, -4180.6006, -5127.3003, 26.714905, 0, 0),
(47476 * 10, 9, -4166.4585, -5133.158 , 26.714905, 0, 0);

UPDATE `creature_template` SET `MovementType`= 3 WHERE `entry`= 47476;
UPDATE `creature_template_addon` SET `cyclicSplinePathId` = 474760 WHERE `entry`= 47476;

-- Creature Sully Kneecapper 46946 SAI
SET @ENTRY := 46946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4694600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4694600 // "),
(@ENTRY, 0, 2, 3, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On evade - Self: Despawn instantly // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - storedTarget[0]: Despawn instantly // "),
(@ENTRY, 0, 4, 0, 17, 0, 100, 0, 47482, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On summoned unit Jora ""Nobbly"" Wildwing (47482)  - Self: Target_0 = Action invoker // "),
(@ENTRY, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On death - storedTarget[0]: Despawn instantly // "),
(@ENTRY, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 12, 47482, 8, 0, 0, 0, 0, 8, 0, 0, 0, -4181.449, -5146.95, 26.49864, 0.09909387, "On aggro - Self: Summon creature Jora ""Nobbly"" Wildwing (47482) at (-4181.449, -5146.95, 26.49864, 0.09909387) // "),
(@ENTRY, 0, 7, 0, 27, 0, 100, 0, 0, 0, 0, 0, 1, 1, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Self: Talk 1 // "),
(@ENTRY, 0, 8, 0, 52, 0, 100, 0, 1, 46946, 0, 0, 11, 88540, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When text 1 said by creature Sully Kneecapper (46946) is over - Self: Cast spell 88540 on Self // "),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 20000, 20000, 30000, 30000, 11, 88288, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 20000 min and 20000 max ms (repeat 30000 min 30000 max ms) - Self: Cast spell 88288 on Random hostile // "),
(@ENTRY, 0, 10, 0, 0, 0, 100, 0, 8000, 8000, 17000, 20000, 11, 80182, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 8000 max ms (repeat 17000 min 20000 max ms) - Self: Cast spell 80182 on Victim // ");

-- TimedActionList  4694600 SAI
SET @ENTRY := 4694600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4226.931, -5139.33, -7.67494, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4226.931, -5139.33, -7.67494, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4212.342, -5148.628, -7.67494, 0, "Update (In Combat) 2400 min and 2400 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4212.342, -5148.628, -7.67494, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 7300, 7300, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4196.002, -5154.196, -7.621854, 0, "Update (In Combat) 7300 min and 7300 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4196.002, -5154.196, -7.621854, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 7200, 7200, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4182.594, -5148.137, -7.621854, 0, "Update (In Combat) 7200 min and 7200 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4182.594, -5148.137, -7.621854, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 8500, 8500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8500 min and 8500 max ms (repeat 0 min 0 max ms) - Self: Talk 0 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2300, 2300, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 2300 min and 2300 max ms (repeat 0 min 0 max ms) - Self: Remove UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_IMMUNE_TO_NPC // ");

UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `unit_flags`= 33600, `VehicleId`= 1269 WHERE `entry`= 46946;

-- Creature Jora "Nobbly" Wildwing 47482 SAI
SET @ENTRY := 47482;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 0, 1000, 2000, 1000, 4000, 11, 88530, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Every 1000 and 4000 ms (for the first time, timer between 1000 and 2000 ms) - Self: Cast spell 88530 on Owner/Summoner // ");

DELETE FROM `waypoint_data` WHERE `id`= 47482 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `velocity`) VALUES
(47482 * 10, 1, -4185.9097, -5127.3003, 26.498642, 0, 0),
(47482 * 10, 2, -4171.7676, -5133.158, 26.498642, 0, 0),
(47482 * 10, 3, -4165.9097, -5147.3003, 26.498642, 0, 0),
(47482 * 10, 4, -4171.7676, -5161.4424, 26.498642, 0, 0),
(47482 * 10, 5, -4185.9097, -5167.3003, 26.498642, 0, 0),
(47482 * 10, 6, -4200.052, -5161.4424, 26.498642, 0, 0),
(47482 * 10, 7, -4205.9097, -5147.3003, 26.498642, 0, 0),
(47482 * 10, 8, -4200.052, -5133.158, 26.498642, 0, 0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 47482;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(47482, 1);

UPDATE `creature_template_addon` SET `cyclicSplinePathId`= 474820 WHERE `entry`= 47482;

UPDATE `creature_template` SET `VehicleId`= 613, `MovementType`= 3 WHERE `entry`= 47482;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 47482;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(47482, 46598, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 47482;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summonType`, `summonTimer`) VALUES
(47482, 37977, 0, 1, '', 6, 0);
