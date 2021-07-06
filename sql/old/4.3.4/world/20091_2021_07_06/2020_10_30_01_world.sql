DELETE FROM `creature_text` WHERE `CreatureID`= 46935 AND `GroupID` > 8;
DELETE FROM `creature_text` WHERE `CreatureID` IN (46947, 47512);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Fourth Quest
(46935, 9, 0, 'Imagine my surprise when I was approached by the genius forsaken, Calder Gray, and propsitioned with a combatant made of all the best features of our previous champions... LITERALLY! Who could refuse a chance to challenge CALDER\'S CREATION?!', 14, 0, 100, 22, 0, 0, 46994, 'Gurgthock to Player'),
(46935, 10, 0, 'You know what they say... if you can\'t beat \'em, join \'em! And in this case, you won\'t have the choice! Cruicible of Carnage, I adore you so.', 14, 0, 100, 22, 0, 0, 46995, 'Gurgthock to Player'),
(46935, 11, 0, 'Bah, couldn\'t you have dragged it out a bit! People don\'t pay me when you make it look that easy! Add some theatrics to it, will ya?!', 14, 0, 100, 22, 0, 0, 48557, 'Gurgthock to Calder Gray'),
(46935, 12, 0, 'They went down like a sack of orc skulls!', 14, 0, 100, 22, 0, 0, 30675, 'Gurgthock to Player'),
-- Cadaver Collage
(46947, 0, 0, 'Calder said that if I kill you, I get to have your parts!', 14, 0, 100, 22, 0, 0, 46971, 'Cadaver Collage to Player'),
(46947, 1, 0, 'Eww! Get away from me, you nasty thing!', 14, 0, 100, 1, 0, 0, 47733, 'Cadaver Collage to Player'),
(46947, 2, 0, 'As you wish, Daddy!', 14, 0, 100, 1, 0, 0, 47734, 'Cadaver Collage to Calder Gray'),
(46947, 3, 0, 'Oh! Too full... oh no... ', 14, 0, 100, 1, 0, 0, 47735, 'Cadaver Collage to Calder Gray'),
-- Calder Gray
(47512, 0, 0, 'Go forth, my beautiful angel! Ah, it is so very sad when one\'s children leave the nest, isn\'t it?', 14, 0, 100, 1, 0, 0, 47729, 'Calder Gray to Player'),
(47512, 1, 0, 'It\'s time for your ultimate attack, my darling!', 14, 0, 100, 1, 0, 0, 47736, 'Calder Gray to Cadaver Collage'),
(47512, 2, 0, 'What... my creation! It didn\'t even blot out the sky! I\'d better recheck my notes...', 14, 0, 100, 1, 0, 0, 47731, 'Calder Gray to Calder Gray'),
(47512, 3, 0, 'Your bodies are all magnificent! If you\'d be willing to take a small whiff of this chloroform, I promise that you will all wake up 10 times stronger and 100 times more... unified in purpose.', 14, 0, 100, 1, 0, 0, 48591, 'Calder Gray to Calder Gray'),
(47512, 4, 0, 'No? Well... my offer stands. Just come by anytime and I\'ll be glad to give you the makeover you\'ve always dreamed of.', 14, 0, 100, 1, 0, 0, 48592, 'Calder Gray to Calder Gray');

-- Creature Cadaver Collage 46947 SAI
SET @ENTRY := 46947;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set event phase to 1 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Set Invulnerability Health level // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set walk // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4694701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4694701 // "),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 8, 1, 0, 0, 80, 4694700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Start timed action list id #4694700 // "),
(@ENTRY, 0, 5, 6, 0, 1, 100, 0, 7000, 7000, 11000, 11000, 11, 90447, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 7000 max ms (repeat 11000 min 11000 max ms) - Self: Cast spell 90447 on Self // "),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 11, 88605, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 88605 on Victim // "),
(@ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 1 // "),
(@ENTRY, 0, 8, 0, 0, 1, 100, 0, 13000, 14000, 20000, 20000, 11, 88607, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 13000 min and 14000 max ms (repeat 20000 min 20000 max ms) - Self: Cast spell 88607 on Self // "),
(@ENTRY, 0, 9, 0, 17, 1, 100, 0, 47512, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On summoned unit Calder Gray (47512)  - Self: Target_0 = Action invoker // "),
(@ENTRY, 0, 10, 11, 2, 0, 100, 1, 0, 5, 60000, 60000, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 5% (check every 60000 - 60000 ms) - Self: Evade disabled // "),
(@ENTRY, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set event phase to 2 // "),
(@ENTRY, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - storedTarget[0]: Set creature data #1 to 0 // "),
(@ENTRY, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4694702, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4694702 // "),
(@ENTRY, 0, 14, 15, 8, 0, 100, 0, 88615, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 88615 hit  - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 15, 16, 61, 0, 100, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Stop Attacking // "),
(@ENTRY, 0, 16, 17, 61, 0, 100, 0, 0, 0, 0, 0, 140, 1061, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: set AIAnimKit to: 1061 // "),
(@ENTRY, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Disable gravity // "),
(@ENTRY, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 141, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Can Hover // "),
(@ENTRY, 0, 19, 20, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 3 // "),
(@ENTRY, 0, 20, 21, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set walk // "),
(@ENTRY, 0, 21, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4694703, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4694703 // "),
(@ENTRY, 0, 22, 23, 8, 0, 100, 0, 87705, 0, 0, 0, 114, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 100, 0, "On spell 87705 hit  - Use target_x, target_y, target_z, With target_type=1 // "),
(@ENTRY, 0, 23, 24, 61, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC // "),
(@ENTRY, 0, 24, 25, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 1000 ms // "),
(@ENTRY, 0, 25, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - storedTarget[0]: Set creature data #2 to 0 // "),
(@ENTRY, 0, 26, 27, 7, 1, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, "On evade - storedTarget[0]: Despawn instantly // "),
(@ENTRY, 0, 27, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn instantly // ");

-- TimedActionList  4694700 SAI
SET @ENTRY := 4694700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.919862, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Look at (0, 0, 0, 1.919862) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 2400 min and 2400 max ms (repeat 0 min 0 max ms) - Self: Talk 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - Self: Remove UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_IMMUNE_TO_NPC // ");

-- TimedActionList  4694701 SAI
SET @ENTRY := 4694701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4182.64, -5148.09, -7.73615, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Move to position (-4182.64, -5148.09, -7.73615, 0) (point id 1) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 12, 47512, 8, 0, 0, 0, 0, 8, 0, 0, 0, -4164.86, -5126.77, 6.01649, 3.90954, "Update (In Combat) 1000 min and 1000 max ms (repeat 0 min 0 max ms) - Self: Summon creature Calder Gray (47512) at (-4164.86, -5126.77, 6.01649, 3.90954) // ");

-- TimedActionList  4694702 SAI
SET @ENTRY := 4694702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 4400, 4400, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4400 min and 4400 max ms (repeat 0 min 0 max ms) - Self: Talk 2 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 88615, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Cast spell 88615 on Self // ");

-- TimedActionList  4694703 SAI
SET @ENTRY := 4694703;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 114, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 15, 0, "Update (In Combat) 1000 min and 1000 max ms (repeat 0 min 0 max ms) - Use target_x, target_y, target_z, With target_type=1 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, 87705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - Self: Cast spell 87705 on Self // ");

-- Creature Calder Gray 47512 SAI
SET @ENTRY := 47512;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 0 - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 2, 0, 0, 0, 80, 4751200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 2 set to 0 - Start timed action list id #4751200 // ");

-- TimedActionList  4751200 SAI
SET @ENTRY := 4751200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Talk 2 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - Self: Talk 3 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 7000 max ms (repeat 0 min 0 max ms) - Self: Talk 4 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 8000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Despawn in 8000 ms // ");

UPDATE `creature_template` SET `unit_flags`= 33947648, `flags_extra`= 128 WHERE `entry`= 48591;
UPDATE `creature_template_addon` SET `auras`= '90449' WHERE `entry`= 48591;
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512, `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271 WHERE `entry`= 46947;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_th_brawler_explosion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(87705, 'spell_th_brawler_explosion');

DELETE FROM `quest_template_addon` WHERE `ID`= 27866;
INSERT INTO `quest_template_addon` (`ID`, `SpecialFlags`) VALUES
(27866, 2);
