
UPDATE `creature` SET `ScriptName`='npc_tushui_leading_trainee' WHERE `guid`=450123;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_instructor_zhi' WHERE `entry` = 61411;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_huojin_trainee' WHERE `entry` IN (54586, 65470); -- Huojin
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_tushui_huojin_trainee' WHERE `entry` IN (54587, 65471); -- Tushui
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (53565, 65469);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (45012300);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-450137, -450130, -450123, 54586);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(54586, 65470, 54587, 65471);
UPDATE `creature` SET `id` = 53565 WHERE `guid` = 450230;

DELETE FROM `creature_text` WHERE `CreatureID` =54611;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54611, 0, 0, 'A challenger approaches.', 12, 0, 100, 113, 0, 0, 0, 0, 'Jaomin Ro to Player'),
(54611, 1, 0, 'It seems I have more training to do. Thank you for the lesson.', 12, 0, 100, 2, 0, 0, 0, 0, 'Jaomin Ro'),
(54611, 2, 0, 'Well fought. Master Shang will be pleased.', 12, 0, 100, 2, 0, 0, 0, 0, 'Jaomin Ro'),
(54611, 3, 0, 'You\'ve been trained well.', 12, 0, 100, 2, 0, 0, 0, 0, 'Jaomin Ro');

UPDATE `creature_template` SET `speed_walk` = 0.345, `VerifiedBuild` = 42010 WHERE `entry` = 64440;

UPDATE `creature_equip_template` SET `VerifiedBuild`=41793 WHERE (`ID`=1 AND `CreatureID` IN (57620,57622));
UPDATE `gameobject_template_addon` SET `flags`=65573 WHERE `entry`=210986; -- Edict of Temperance

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29666 /*The Sting of Learning*/, 29677 /*The Sun Pearl*/, 29676 /*Finding an Old Friend*/, 29662 /*Stronger Than Reeds*/, 29663 /*The Lesson of the Balanced Rock*/, 29661 /*The Lesson of Dry Fur*/, 29521 /*The Singing Pools*/, 29423 /*The Passion of Shen-zin Su*/, 29422 /*Huo, the Spirit of Fire*/, 29421 /*Only the Worthy Shall Pass*/, 29664 /*The Challenger's Fires*/, 29420 /*The Spirit's Guardian*/, 29523 /*Fanning the Flames*/, 29418 /*Kindling the Fire*/, 29417 /*The Way of the Huojin*/, 29522 /*Ji of the Huojin*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29666, 1, 0, 0, 0, 0, 0, 0, 0, 'The water pincers are strange creatures. They seem to be drawn to still water.', 41793), -- The Sting of Learning
(29677, 1, 0, 0, 0, 0, 0, 0, 0, 'Shu\'s desires are not so different from our own. He does not want to be alone. Unwanted, unloved. He longs to be needed, and to share his life with others.$B$BKnowing that, earning his trust is not terribly difficult. He just wants company.', 41793), -- The Sun Pearl
(29676, 1, 0, 0, 0, 0, 0, 0, 0, 'Visitors are rare up here, but you are welcome. It is nice to meet you, young $c.', 41793), -- Finding an Old Friend
(29662, 0, 0, 0, 0, 0, 0, 0, 0, 'Good.$B$BNo number of reeds have ever withstood my might.$B$BStep back, and let me dispel your doubts.', 41793), -- Stronger Than Reeds
(29663, 1, 0, 0, 0, 0, 0, 0, 0, 'Even now, your skills increase. Your footing becomes more sure. Your blows strike with more force.$B$BDiscipline and practice are the keys to reaching our full potential.', 41793), -- The Lesson of the Balanced Rock
(29661, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. You\'re a quick study.', 41793), -- The Lesson of Dry Fur
(29521, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s good to see you again, $n.$B$BThis is the pool of the skunk, as I\'m sure you noticed.$B$BOver the many ages of Shen-zin Su, animals have died in some of these magical pools. Through their deaths, their spirits were infused into the waters, and anyone touching those waters will take their form.$B$BThere are several cursed pools here, some more dangerous than others.', 41793), -- The Singing Pools
(29423, 1, 0, 0, 0, 0, 0, 0, 0, '$n, you\'ve done very well. Huo, the spirit of fire, is here. The temple flames are reignited. You accomplished the challenge I put before you, and with seeming ease.$B$BThere is a greater purpose in bringing Huo to the temple. It is time that I tell you more of things to come.', 41793), -- The Passion of Shen-zin Su
(29422, 1, 0, 0, 0, 0, 0, 0, 0, '<Through the glare, it looks like Huo is smiling. He seems to have warmed up to you.>', 41793), -- Huo, the Spirit of Fire
(29421, 1, 0, 0, 0, 0, 0, 0, 0, 'Remember always, the superior warrior is modest in his speech, but exceeds in his actions.', 41793), -- Only the Worthy Shall Pass
(29664, 1, 0, 0, 0, 0, 0, 0, 0, 'These fires will give you the strength that you\'ve not yet obtained. They will illuminate your potential.', 41793), -- The Challenger's Fires
(29420, 1, 0, 0, 0, 0, 0, 0, 0, 'Life isn\'t about finding yourself. Life is about creating yourself. There is a path before you, but you choose the trials you will face, and the trials you will overcome.', 41793), -- The Spirit's Guardian
(29523, 1, 0, 0, 0, 0, 0, 0, 0, 'You know what it is to seize opportunity. I think you and I are kindred spirits, $n.', 41793), -- Fanning the Flames
(29418, 1, 0, 0, 0, 0, 0, 0, 0, '$n! You\'ve returned, roots in hand! You\'re a down-to-business kind of $G guy:gal;, aren\'t you? I like that!', 41793), -- Kindling the Fire
(29417, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'ve got some fight in you! I think I like you!', 41793), -- The Way of the Huojin
(29522, 1, 0, 0, 0, 0, 0, 0, 0, 'Hello! You look poised and confident... I like that!$B$BI\'ve heard some rather impressive whispers about you from the training grounds. If you\'re half as capable as they say, I think you and I are going to be good friends!', 41793); -- Ji of the Huojin

DELETE FROM `quest_request_items` WHERE `ID` IN (29418 /*Kindling the Fire*/, 29662 /*Stronger Than Reeds*/, 29523 /*Fanning the Flames*/, 29677 /*The Sun Pearl*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29418, 1, 0, 0, 0, 'I hope you\'re not shy about getting your hands dirty.', 42010), -- Kindling the Fire
(29662, 0, 0, 0, 0, 'Telling you of my strength means nothing. I must show you.', 42010), -- Stronger Than Reeds
(29523, 1, 0, 0, 0, 'When opportunity rises, it is our responsibility to reach out and grab it. Second guessing is as good as giving up.', 42010), -- Fanning the Flames
(29677, 1, 0, 0, 0, 'The decision to not return to the pools was a hard one. I don\'t think Shu ever truly understood. He does not know what it is to get older and weaker.', 42010); -- The Sun Pearl

UPDATE `creature_queststarter` SET `VerifiedBuild`=41793 WHERE (`id`=55020 AND `quest` IN (29678,29666,29677)) OR (`id`=54975 AND `quest` IN (29676,29663,29661)) OR (`id`=55021 AND `quest`=29662) OR (`id`=54786 AND `quest`=29521) OR (`id`=54787 AND `quest`=29423) OR (`id`=54135 AND `quest` IN (29422,29421,29664)) OR (`id`=54609 AND `quest`=29420) OR (`id`=54568 AND `quest` IN (29523,29418,29417)) OR (`id`=54608 AND `quest`=29522);
UPDATE `creature_queststarter` SET `VerifiedBuild`=42010 WHERE (`id`=54608 AND `quest`=29522) OR (`id`=53566 AND `quest` IN (30034,30033,30036,30038,30035));
UPDATE `creature_questender` SET `VerifiedBuild`=41793 WHERE (`id`=55020 AND `quest` IN (29666,29677,29676)) OR (`id`=55021 AND `quest`=29662) OR (`id`=54975 AND `quest` IN (29663,29661,29521)) OR (`id`=54786 AND `quest`=29423) OR (`id`=54787 AND `quest`=29422) OR (`id`=54135 AND `quest` IN (29421,29664,29420)) OR (`id`=54568 AND `quest` IN (29523,29418,29417,29522)) OR (`id`=54608 AND `quest`=29414);
UPDATE `creature_questender` SET `VerifiedBuild`=42010 WHERE (`id`=54608 AND `quest`=29414) OR (`id`=53566 AND `quest` IN (30034,30033,30036,30038,30035));

 -- Trainee Nim smart ai
SET @ENTRY := 60183;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (6018300);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 10, 0, 100, 1, 1, 10, 1, 2, 5, 113, 0, 0, 0, 0, 0, 17, 1, 20, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Players in 1 - 20 yards: Play emote 113'),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6018300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Start timed action list id #6018300 (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 100, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 - 1 seconds - Self: Talk 0 to invoker');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 60183 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(22, 1, 60183, 0, 0, 9, 0, 29409, 0, 0, 0, 'Action invoker has quest The Disciple\'s Challenge (29409) active');

UPDATE `creature` SET `id` = 60244, `map` = 860, `zoneId` = 5736, `areaId` = 5834, `position_x` = 1334.94, `position_y` = 3380.83, `position_z` = 128.679, `orientation` = 5.98421, `VerifiedBuild` = 41793 WHERE `guid` = 450099;

UPDATE `creature_text` SET `Sound` = 33646 WHERE `GroupID` = 0 AND `ID` = 0 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33646 WHERE `GroupID` = 0 AND `ID` = 3 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33644 WHERE `GroupID` = 0 AND `ID` = 4 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33645 WHERE `GroupID` = 0 AND `ID` = 5 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33646 WHERE `GroupID` = 0 AND `ID` = 6 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33646 WHERE `GroupID` = 0 AND `ID` = 7 AND `CreatureID` = 53565;
UPDATE `creature_text` SET `Sound` = 33645 WHERE `GroupID` = 0 AND `ID` = 0 AND `CreatureID` = 60183;

DELETE FROM `creature_text` WHERE `CreatureID` = 60244;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(60244, 0, 0, 'You\'re departing so soon?  I am envious of your prowess, $c. Good luck to you.', 12, 0, 100, 2, 0, 33645, 59711, 0, 'Trainee Guang to Player');

DELETE FROM `creature_text` WHERE `CreatureID` IN (54130, 54567, 54856, 54943, 56503, 59642, 59652, 65469); 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54130, 0, 0, 'Look out! Its friendses are coming!', 14, 0, 100, 2, 0, 0, 56473, 0, 'Amberleaf Scamp to Player'),
(54130, 1, 0, 'Run away!', 14, 0, 100, 2, 0, 0, 56474, 0, 'Amberleaf Scamp to Player'), -- BroadcastTextID: 26179 - 56474 - 61876 - 120283
(54567, 0, 0, 'And so our path lays before us. Speak to Master Shang Xi, he will tell you what comes next.', 12, 0, 100, 0, 0, 27399, 60046, 0, 'Aysa Cloudsinger to Player'),
(54856, 0, 0, 'Master Li Fei\'s voice echoes, \"It is good to see you again, Aysa. You\'ve come with respect, and so I shall give you the answers you seek.\"', 16, 0, 100, 1, 0, 0, 53845, 0, 'Master Li Fei to Player'),
(54856, 1, 0, 'Master Li Fei\'s voice echoes, \"Huo, the spirit of fire, is known for his hunger. He wants for tinder to eat. He needs the caress of the wind to rouse him.\"', 16, 0, 100, 1, 0, 0, 53841, 0, 'Master Li Fei to Player'),
(54856, 2, 0, 'Master Li Fei\'s voice echoes, \"If you find these things and bring them to his cave, on the far side of Wu-Song Village, you will face a challenge within.\"', 16, 0, 100, 1, 0, 0, 53842, 0, 'Master Li Fei to Player'),
(54856, 3, 0, 'Master Li Fei\'s voice echoes, \"Overcome that challenge, and you shall be graced by Huo\'s presence. Rekindle his flame, and if your spirit is pure, he shall follow you.\"', 16, 0, 100, 1, 0, 0, 53843, 0, 'Master Li Fei to Player'),
(54856, 4, 0, 'Master Li Fei\'s voice echoes, \"Go, children. We shall meet again very soon.\"', 16, 0, 100, 2, 0, 0, 53844, 0, 'Master Li Fei to Player'),
(54856, 5, 0, 'Master Li Fei fades away.', 16, 0, 100, 0, 0, 0, 53130, 0, 'Master Li Fei to Player'),
(54943, 0, 0, 'Shhhh! Come quietly. She\'s practicing.', 12, 0, 100, 396, 0, 0, 59712, 0, 'Merchant Lorvo to Player'),
(56503, 0, 0, 'Master Shang has trained you well. Thank you, friend!', 12, 0, 100, 2, 0, 0, 53265, 0, 'Min Dimwind to Player'),
(56503, 1, 0, 'I couldn\'t have fought them off alone. Now, if you\'ll excuse me, I should go find my cart.', 12, 0, 100, 1, 0, 0, 56452, 0, 'Min Dimwind to Player'),
(56503, 2, 0, 'Cart!', 14, 0, 100, 22, 0, 0, 56453, 0, 'Min Dimwind to Player'),
(56503, 3, 0, 'Hello, cart. Still upside-downed, I see.', 12, 0, 100, 1, 0, 0, 56454, 0, 'Min Dimwind to Player'),
(59642, 0, 0, 'Keep those creatures at bay while I meditate. We\'ll soon have the answers we seek.', 12, 0, 100, 0, 0, 27398, 59161, 0, 'Aysa Cloudsinger to Player'),
(59652, 0, 0, 'Meet me up in the cave if you would, friend.', 12, 0, 100, 396, 0, 27397, 59147, 0, 'Aysa Cloudsinger to Player');

 -- Trainee Guang smart ai
SET @ENTRY := 60244;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (6024400);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 10, 0, 100, 1, 1, 40, 1, 2, 5, 113, 0, 0, 0, 0, 0, 17, 1, 40, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Players in 1 - 40 yards: Play emote 113'),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6024400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Start timed action list id #6024400 (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 100, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 - 1 seconds - Self: Talk 0 to invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 60244 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(22, 1, 60244, 0, 0, 28, 0, 29410, 0, 0, 0, 'Action invoker has completed quest quest Aysa of the Tushui (29410) (but not yet rewarded)');

DELETE FROM `npc_vendor` WHERE (`entry`=54943 AND `item`=90660 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=90659 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54943 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54943, 17, 90660, 0, 0, 1, 0, 0, 42010), -- Black Tea
(54943, 16, 90659, 0, 0, 1, 0, 0, 42010), -- Jasmine Tea
(54943, 15, 159, 0, 0, 1, 0, 0, 42010), -- Refreshing Spring Water
(54943, 14, 3770, 0, 0, 1, 0, 0, 42010), -- Mutton Chop
(54943, 13, 2287, 0, 0, 1, 0, 0, 42010), -- Haunch of Meat
(54943, 12, 117, 0, 0, 1, 0, 0, 42010), -- Tough Jerky
(54943, 11, 4606, 0, 0, 1, 0, 0, 42010), -- Spongy Morel
(54943, 10, 4605, 0, 0, 1, 0, 0, 42010), -- Red-Speckled Mushroom
(54943, 9, 4604, 0, 0, 1, 0, 0, 42010), -- Forest Mushroom Cap
(54943, 8, 4593, 0, 0, 1, 0, 0, 42010), -- Bristle Whisker Catfish
(54943, 7, 4592, 0, 0, 1, 0, 0, 42010), -- Longjaw Mud Snapper
(54943, 6, 787, 0, 0, 1, 0, 0, 42010), -- Slitherskin Mackerel
(54943, 5, 4542, 0, 0, 1, 0, 0, 42010), -- Moist Cornbread
(54943, 4, 4541, 0, 0, 1, 0, 0, 42010), -- Freshly Baked Bread
(54943, 3, 4540, 0, 0, 1, 0, 0, 42010), -- Tough Hunk of Bread
(54943, 2, 4538, 0, 0, 1, 0, 0, 42010), -- Snapvine Watermelon
(54943, 1, 4536, 0, 0, 1, 0, 0, 42010); -- Shiny Red Apple

 -- Aspiring Trainee with guid 450215 smart ai
SET @ENTRY := -450215;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 108967, 0, 0, 0, 0, 0, 9, 57873, 0, 5, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Cast spell 108967 on Creature Training Target (57873) in 0 - 5 yards');

 -- Aspiring Trainee with guid 450228 smart ai
SET @ENTRY := -450228;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 108967, 0, 0, 0, 0, 0, 9, 57873, 0, 5, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Cast spell 108967 on Creature Training Target (57873) in 0 - 5 yards');

 -- Aspiring Trainee with guid 450197 smart ai
SET @ENTRY := -450197;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 108967, 0, 0, 0, 0, 0, 9, 57873, 0, 5, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Cast spell 108967 on Creature Training Target (57873) in 0 - 5 yards');

 -- Aspiring Trainee with guid 450207 smart ai
SET @ENTRY := -450207;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 108967, 0, 0, 0, 0, 0, 9, 57873, 0, 5, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Cast spell 108967 on Creature Training Target (57873) in 0 - 5 yards');

 -- Aspiring Trainee with guid 450213 smart ai
SET @ENTRY := -450213;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 108967, 0, 0, 0, 0, 0, 9, 57873, 0, 5, 0, 0, 0, 0, 'Every 6 - 7 seconds (1 - 5s initially) (OOC) - Self: Cast spell 108967 on Creature Training Target (57873) in 0 - 5 yards');

-- Instructor Qun smart ai
SET @ENTRY := 57748;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (5774800);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 19000, 19000, 19000, 20000, 80, 5774800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 - 20 seconds (19 - 19s initially) (OOC) - Self: Start timed action list id #5774800 (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 - 3 seconds - Self: Play emote 509'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 509'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 509, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 509'),
(@ENTRY * 100, 9, 3, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33645, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33645, 33646, 33646 of all'),
(@ENTRY * 100, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 543'),
(@ENTRY * 100, 9, 5, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 543'),
(@ENTRY * 100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 543'),
(@ENTRY * 100, 9, 7, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33643, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33643, 33646, 33646 of all'),
(@ENTRY * 100, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 511'),
(@ENTRY * 100, 9, 9, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 511'),
(@ENTRY * 100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 511'),
(@ENTRY * 100, 9, 11, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33645, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33645, 33646, 33646 of all'),
(@ENTRY * 100, 9, 12, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 507'),
(@ENTRY * 100, 9, 13, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 507'),
(@ENTRY * 100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 507'),
(@ENTRY * 100, 9, 15, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33646, 33643, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33646, 33643, 33646 of all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 57748 AND `SourceId` = 0;

-- Quiet Lam
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 57752;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57752 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57752, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quiet Lam - OOC - Play Random Emote (507, 509, 511, 543)'),
(57752, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Quiet Lam - Play Random Sound (33643, 33645, 33646)');

-- Ironfist Zhou
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 57753;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57753, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironfist Zhou - OOC - Play Random Emote (507, 509, 511, 543)'),
(57753, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironfist Zhou - Play Random Sound (33643, 33645, 33646)');

-- Aspiring Trainee with guid 450192 smart ai - the conversation doesn't go according to retail times - I put the times there according to myself "guessed"
SET @ENTRY := -450192;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (45019200);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 85000, 95000, 85000, 95000, 80, 45019200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 85 - 95 seconds (OOC) - Self: Start timed action list id #45019200 (update out of combat) // -inline'),
(45019200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 0 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk My money\'s on Lam. Did you see him take down Chu during trai... (1) to invoker'),
(45019200, 9, 1, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk His stamina is nothing against Lam\'s strength. (2) to invoker'),
(45019200, 9, 2, 0, 0, 0, 100, 0, 4000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 4 - 5 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk He has the legs of an ox! Have you ever been kicked by him i... (3) to invoker'),
(45019200, 9, 3, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 1, 4, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Self: Talk 4 to Closest alive creature Aspiring Trainee (53565) in 3 yards'),
(45019200, 9, 4, 0, 0, 0, 100, 0, 5000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 5 - 6 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk That\'s where you\'re mistaken, friend. Zhou is as sturdy as an oak. (5) to invoker'),
(45019200, 9, 5, 0, 0, 0, 100, 0, 7000, 8000, 0, 0, 1, 6, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 7 - 8 seconds - Self: Talk 6 to Closest alive creature Aspiring Trainee (53565) in 3 yards'),
(45019200, 9, 6, 0, 0, 0, 100, 0, 8000, 9000, 0, 0, 1, 7, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 8 - 9 seconds - Self: Talk 7 to Closest alive creature Aspiring Trainee (53565) in 3 yards');

DELETE FROM `creature_text` WHERE `CreatureID` IN(54586, 65470, 54587, 65471) AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54586, 0, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 1, 0, 33643, 56445, 0, 'Trainee'),
(54586, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 1, 0, 33645, 56441, 0, 'Trainee'),
(54586, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 0, 'Trainee'),
(54586, 0, 3, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 0, 'Trainee'),
(54586, 0, 4, 'You are an honorable opponent.', 12, 0, 100, 1, 0, 33643, 56438, 0, 'Trainee'),
(54586, 0, 5, 'You fight honorably, friend.', 12, 0, 100, 1, 0, 33645, 56440, 0, 'Trainee'),
(54586, 0, 6, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 0, 'Trainee'),
(54586, 0, 7, 'Your skills are too great. I yield.', 12, 0, 100, 1, 0, 33643, 56442, 0, 'Trainee'),
(54587, 0, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 1, 0, 33643, 56445, 0, 'Trainee'),
(54587, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 1, 0, 33645, 56441, 0, 'Trainee'),
(54587, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 0, 'Trainee'),
(54587, 0, 3, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 0, 'Trainee'),
(54587, 0, 4, 'You are an honorable opponent.', 12, 0, 100, 1, 0, 33643, 56438, 0, 'Trainee'),
(54587, 0, 5, 'You fight honorably, friend.', 12, 0, 100, 1, 0, 33645, 56440, 0, 'Trainee'),
(54587, 0, 6, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 0, 'Trainee'),
(54587, 0, 7, 'Your skills are too great. I yield.', 12, 0, 100, 1, 0, 33643, 56442, 0, 'Trainee'),
(65470, 0, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 1, 0, 33643, 56445, 0, 'Trainee'),
(65470, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 1, 0, 33645, 56441, 0, 'Trainee'),
(65470, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 0, 'Trainee'),
(65470, 0, 3, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 0, 'Trainee'),
(65470, 0, 4, 'You are an honorable opponent.', 12, 0, 100, 1, 0, 33643, 56438, 0, 'Trainee'),
(65470, 0, 5, 'You fight honorably, friend.', 12, 0, 100, 1, 0, 33645, 56440, 0, 'Trainee'),
(65470, 0, 6, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 0, 'Trainee'),
(65470, 0, 7, 'Your skills are too great. I yield.', 12, 0, 100, 1, 0, 33643, 56442, 0, 'Trainee'),
(65471, 0, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 1, 0, 33643, 56445, 0, 'Trainee'),
(65471, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 1, 0, 33645, 56441, 0, 'Trainee'),
(65471, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 0, 'Trainee'),
(65471, 0, 3, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 0, 'Trainee'),
(65471, 0, 4, 'You are an honorable opponent.', 12, 0, 100, 1, 0, 33643, 56438, 0, 'Trainee'),
(65471, 0, 5, 'You fight honorably, friend.', 12, 0, 100, 1, 0, 33645, 56440, 0, 'Trainee'),
(65471, 0, 6, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 0, 'Trainee'),
(65471, 0, 7, 'Your skills are too great. I yield.', 12, 0, 100, 1, 0, 33643, 56442, 0, 'Trainee');

UPDATE `creature` SET `spawntimesecs`=20 WHERE `id` IN(54586, 65470, 54587, 65471);
