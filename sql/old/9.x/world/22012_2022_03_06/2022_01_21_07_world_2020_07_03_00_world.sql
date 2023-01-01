UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23038;
UPDATE `creature` SET `orientation`=0.049211 WHERE `id`=23038;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23038, 23042) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2303800, 2304200, 2304201, 2304202, 2304203) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23042, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Spawn - Set Event Phase 1"),
(23042, 0, 1, 0, 19, 1, 100, 0, 11004, 0, 0, 0, 0, 80, 2304200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Quest 'World of Shadows' Taken - Run Script (Event Phase 1)"),
(23042, 0, 2, 0, 20, 1, 100, 0, 11004, 0, 0, 0, 0, 80, 2304201, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Quest 'World of Shadows' Rewarded - Run Script (Event Phase 1)"),
(23042, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Data 1 1 Set - Say Line 1"),
(23042, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 2304200, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Data 1 1 Set - Start WP"),
(23042, 0, 5, 0, 40, 0, 100, 0, 1, 2304200, 0, 0, 0, 80, 2304202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On WP 1 Reached - Run Script"),
(23042, 0, 6, 0, 40, 0, 100, 0, 1, 2304201, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.555310, "Severin - On WP 1 Reached - Reset Orientation"),
(23042, 0, 7, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, 80, 2304203, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Data 2 2 Set - Run Script"),

(23038, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Spawn - Set Event Phase 1"),
(23038, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 1 1 Set - Remove StandState Sit"),
(23038, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 1 1 Set - Set StandState Kneel"),
(23038, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 1 1 Set - Say Line 1"),
(23038, 0, 4, 5, 38, 0, 100, 0, 2, 2, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.794490, "Sky Commander Adaris - On Data 2 2 Set - Set Orientation"),
(23038, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 2 2 Set - Say Line 2"),
(23038, 0, 6, 7, 38, 0, 100, 0, 3, 3, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 3 3 Set - Unsheathe Melee Weapon"),
(23038, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 2303800, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Data 3 3 Set - Start WP"),
(23038, 0, 8, 0, 40, 0, 100, 0, 1, 2303800, 0, 0, 0, 80, 2303800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On WP 1 Reached - Run Script"),
(23038, 0, 9, 10, 40, 0, 100, 0, 1, 2303801, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.049211, "Sky Commander Adaris - On WP 1 Reached - Reset Orientation"),
(23038, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On WP 1 Reached - Sheathe Melee Weapon"),
(23038, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On WP 1 Reached - Set StandState Kneel"),
(23038, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 23042, 10, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On WP 1 Reached - Set Data 2 2 (Severin)"),

(2303800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23042, 50, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Set Data 1 1 (Severin)"),
(2303800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.168708, "Sky Commander Adaris - On Script - Set Orientation"),
(2303800, 9, 2, 0, 0, 0, 100, 0, 400, 400, 0, 0, 0, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Play Emote ONESHOT_ATTACK1H"),
(2303800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 23207, 3, 18000, 0, 0, 0, 8, 0, 0, 0, 0, -3399.783447, 3614.886719, 276.369293, 2.089945, "Sky Commander Adaris - On Script - Summon Creature 'Skettis Assassin'"),
(2303800, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 6.268262, "Sky Commander Adaris - On Script - Set Orientation"),
(2303800, 9, 5, 0, 0, 0, 100, 0, 400, 400, 0, 0, 0, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Play Emote ONESHOT_ATTACK1H"),
(2303800, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 23207, 3, 18000, 0, 0, 0, 8, 0, 0, 0, 0, -3397.512207, 3617.134766, 276.865234, 3.028496, "Sky Commander Adaris - On Script - Summon Creature 'Skettis Assassin'"),
(2303800, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Say Line 3"),
(2303800, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 53, 0, 2303801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sky Commander Adaris - On Script - Start WP"),

(2304200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Event Phase 0"),
(2304200, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Say Line 0 (Sky Commander Adaris)"),
(2304200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set StandState Kneel"),
(2304200, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Say Line 0"),
(2304200, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Remove StandState Kneel"),
(2304200, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Event Phase 1"),

(2304201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Event Phase 0"),
(2304201, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Remove Gossip+Questgiver Npcflag (Sky Commander Adaris)"),
(2304201, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Data 1 1 (Sky Commander Adaris)"),
(2304201, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Remove StandState Kneel (Sky Commander Adaris)"),
(2304201, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Data 2 2 (Sky Commander Adaris)"),
(2304201, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Data 3 3 (Sky Commander Adaris)"),

(2304202, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.01555, "Severin - On Script - Set Orientation"),
(2304202, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 53, 0, 2304201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Start WP"),

(2304203, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Say Line 4 (Sky Commander Adaris)"),
(2304203, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Say Line 2"),
(2304203, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set StandState Kneel"),
(2304203, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Remove StandState Kneel (Sky Commander Adaris)"),
(2304203, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 90, 1, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set StandState Sit (Sky Commander Adaris)"),
(2304203, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 19, 23038, 10, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Gossip+Questgiver Npcflag (Sky Commander Adaris)"),
(2304203, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Remove StandState Kneel"),
(2304203, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Severin - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23042, 23038) AND `GroupID`!=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23038, 1, 0, "The elixir... give it to me, Severin!", 12, 0, 100, 0, 0, 0, 21083, 0, "Sky Commander Adaris"),
(23038, 2, 0, "I see them now... assassins from Skettis!", 12, 0, 100, 25, 0, 0, 21084, 0, "Sky Commander Adaris"),
(23038, 3, 0, "The arakkoa can send all the assassins they have... they will meet the same fate as these!", 12, 0, 100, 0, 0, 0, 21086, 0, "Sky Commander Adaris"),
(23038, 4, 0, "Is this... blood in my lungs?  If I don't die to an assassin's blade, it'll be my old injuries that get me.", 12, 0, 100, 0, 0, 0, 21094, 0, "Sky Commander Adaris"),
(23042, 1, 0, "Adaris!", 14, 0, 100, 0, 0, 0, 21132, 0, "Severin"),
(23042, 2, 0, "Rest now, friend.  You need your strength.", 12, 0, 100, 0, 0, 0, 21133, 0, "Severin");

DELETE FROM `waypoints` WHERE `entry` IN (2303800, 2303801, 2304200, 2304201);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2303800, 1, -3401.270020, 3617.288330, 276.939697, "Sky Commander Adaris"),
(2303801, 1, -3408.260010, 3622.709961, 278.075012, "Sky Commander Adaris"),
(2304200, 1, -3402.066650, 3619.804688, 277.965363, "Severin"),
(2304201, 1, -3407.590088, 3624.570068, 278.075012, "Severin");

DELETE FROM `creature_template_addon` WHERE `entry`=23207;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `auras`) VALUES
(23207, 0, "29266");
