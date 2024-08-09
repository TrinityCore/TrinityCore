SET @CGUID := 213818;
SET @OGUID := 167035; -- First free guid in master branch
SET @EVENT := 61;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=11375 WHERE `entry`=40352;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x200 WHERE `entry`=40416;

UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=40204; -- 40204 (Handler Marnlek)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=40253; -- 40253 (Champion Uru'zin)
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=40361; -- 40361 (Troll Dance Leader)

DELETE FROM `creature_template_addon` WHERE `entry` IN (40184, 40352);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(40184, 0, 0, 0, 0, 0, 1, 0, 0, ''), -- 40184 (Vanira)
(40352, 0, 0, 0, 0, 0, 1, 0, 0, ''); -- 40352 (Witch Doctor Hez'tok)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (40176, 40187, 40188, 40218, 40222, 40301, 40387);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(40176, 1, 0, 0, 0, 0, 2, NULL),
(40187, 0, 0, 1, 1, 0, 0, NULL),
(40188, 1, 0, 0, 0, 0, 2, NULL),
(40218, 0, 0, 1, 0, 0, 0, NULL),
(40222, 2, 0, 0, 0, 0, 0, NULL),
(40301, 0, 0, 1, 0, 0, 0, NULL),
(40387, 0, 0, 1, 0, 0, 0, NULL);

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=21257 AND `TextID`=15846);
DELETE FROM `gossip_menu` WHERE (`MenuID`=11375 AND `TextID`=15846);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11375, 15846, 53788); -- 40352 (Witch Doctor Hez'tok)

-- Misc
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=40176;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(40176, 74904, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (74903, 74977);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=74977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11345;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=40176;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 74903, 0, 0, 31, 0, 3, 40187, 0, 0, 0, 0, '', 'Spell "Attune" can only targets Vanira''s Sentry Totem'),
(13, 1, 74977, 0, 0, 31, 0, 3, 40218, 0, 0, 0, 0, '', 'Spell "Frogs Away!" can only targets Spy Frog Credit'),
(17, 0, 74977, 0, 0, 46, 0, 0, 0, 0, 0, 60, 0, '', 'Spell "Frogs Away!" can only be used on taxi'),
(15, 11345, 0, 0, 0, 47, 0, 25446, 10, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25446 taken or completed'),
(15, 11345, 1, 0, 0, 47, 0, 25461, 10, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25461 taken or completed'),
(15, 11345, 2, 0, 0, 47, 0, 25495, 2, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25495 completed'),
(18, 40176, 74904, 0, 0, 2, 0, 53510, 5, 1, 1, 0, 0, '', 'Spellclick "Pickup Sen''jin Frog" requires less than 5 Captured Frog');

DELETE FROM `spell_area` WHERE `spell`=75434 AND `area` IN (367, 393);
UPDATE `spell_area` SET `quest_start_status`=10, `quest_end_status`=10 WHERE `spell`=75434;
UPDATE `spell_area` SET `area`=14, `quest_start_status`=10, `quest_end_status`=10 WHERE `spell`=74982 AND `area`=368;

-- Quests
DELETE FROM `quest_poi` WHERE `QuestID`=25461;
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(25461, 0, -1, 1, 4, 0, 0, 1, 0),
(25461, 1, 0, 1, 4, 0, 1, 1, 0),
(25461, 2, 1, 1, 4, 0, 2, 1, 0);

DELETE FROM `quest_poi_points` WHERE `QuestID` IN (25444, 25446, 25461);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(25444, 0, 0, -747, -5004, 53007),
(25444, 1, 0, -736, -5100, 53007),
(25444, 1, 1, -673, -5062, 53007),
(25444, 1, 2, -644, -4999, 53007),
(25444, 1, 3, -673, -4932, 53007),
(25444, 1, 4, -740, -4873, 53007),
(25444, 1, 5, -808, -4831, 53007),
(25444, 1, 6, -892, -4776, 53007),
(25444, 1, 7, -984, -4785, 53007),
(25444, 1, 8, -1014, -4911, 53007),
(25444, 1, 9, -959, -4995, 53007),
(25444, 1, 10, -887, -5062, 53007),
(25444, 1, 11, -808, -5100, 53007),
(25444, 2, 0, -749, -5024, 53007),
(25446, 0, 0, -1062, -5631, 53007),
(25446, 0, 1, -1041, -5585, 53007),
(25446, 0, 2, -1066, -5375, 53007),
(25446, 0, 3, -1189, -5343, 53007),
(25446, 0, 4, -1269, -5386, 53007),
(25446, 0, 5, -1320, -5477, 53007),
(25446, 0, 6, -1322, -5527, 53007),
(25446, 0, 7, -1289, -5571, 53007),
(25446, 0, 8, -1195, -5618, 53007),
(25446, 1, 0, -1532, -5341, 53007),
(25446, 1, 1, -1502, -5263, 53007),
(25446, 1, 2, -1611, -5276, 53007),
(25446, 1, 3, -1589, -5340, 53007),
(25446, 2, 0, -955, -5186, 53007),
(25446, 2, 1, -1020, -5153, 53007),
(25446, 2, 2, -1128, -5131, 53007),
(25446, 2, 3, -1089, -5174, 53007),
(25446, 3, 0, -806, -5674, 53007),
(25446, 3, 1, -730, -5656, 53007),
(25446, 3, 2, -654, -5627, 53007),
(25446, 3, 3, -688, -5518, 53007),
(25446, 3, 4, -732, -5499, 53007),
(25446, 3, 5, -795, -5544, 53007),
(25446, 3, 6, -835, -5606, 53007),
(25446, 4, 0, -747, -5004, 53007),
(25461, 2, 0, -773, -5016, 53788),
(25461, 1, 10, 266, -4830, 53788),
(25461, 1, 9, 246, -4715, 53788),
(25461, 1, 8, 247, -4675, 53788),
(25461, 1, 7, 248, -4673, 53788),
(25461, 1, 6, 284, -4628, 53788),
(25461, 1, 5, 302, -4612, 53788),
(25461, 1, 4, 380, -4661, 53788),
(25461, 1, 3, 411, -4704, 53788),
(25461, 1, 2, 376, -4778, 53788),
(25461, 1, 1, 345, -4831, 53788),
(25461, 1, 0, 343, -4831, 53788),
(25461, 0, 0, -765, -5018, 53788);

DELETE FROM `quest_details` WHERE `ID` IN (25446 /*Frogs Away!*/, 25444 /*Da Perfect Spies*/, 25461 /*Trollin' For Volunteers*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25446, 1, 1, 0, 0, 0, 0, 0, 0, 53788), -- Frogs Away!
(25444, 1, 1, 1, 0, 0, 0, 0, 0, 53788), -- Da Perfect Spies
(25461, 1, 1, 0, 0, 0, 0, 0, 0, 53788); -- Trollin' For Volunteers

DELETE FROM `quest_request_items` WHERE `ID` IN (25446 /*Frogs Away!*/, 25444 /*Da Perfect Spies*/, 25461 /*Trollin' For Volunteers*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(25446, 0, 1, 'Did ya get those frogs onto de isles?', 53788), -- Frogs Away!
(25444, 0, 1, 'Ya helpin'' with da frogs or not?', 53788), -- Da Perfect Spies
(25461, 0, 1, 'We be needin'' as many volunteers as we can get.', 53788); -- Trollin' For Volunteers

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=53788 WHERE `ID`=25446; -- Frogs Away!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=53788 WHERE `ID`=25444; -- Da Perfect Spies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=53788 WHERE `ID`=25461; -- Trollin' For Volunteers

DELETE FROM `game_event_creature_quest` WHERE (`id`=40184 AND `quest` IN (25446,25444)) OR (`id`=40253 AND `quest`=25461);
DELETE FROM `creature_queststarter` WHERE (`id`=40184 AND `quest` IN (25446,25444));
DELETE FROM `creature_queststarter` WHERE (`id`=40253 AND `quest`=25461);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(40184, 25446), -- Frogs Away! offered by Vanira
(40184, 25444), -- Da Perfect Spies offered by Vanira
(40253, 25461); -- Trollin' For Volunteers offered by Champion Uru'zin

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (40218, 40253, 40356, 40392);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40176, 40188, 40204, 40218, 40253, 40356, 40392, 40416) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4021800, 4025300, 4039200, 4039201, 4039202, 4035600, 4035601, 4035602, 4041600, 4041601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40176,0,0,1,8,0,100,1,74904,0,5000,5000,0,127,0,5000,1,0,0,0,1,0,0,0,0,0,0,0,0,'Sen''jin Frog - On spellhit "Pickup Sen''jin Frog" - Pause movement'),
(40176,0,1,2,61,0,100,0,0,0,0,0,0,11,74905,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Sen''jin Frog - Event linked - Cast "Pickup Sen''jin Frog" on invoker'),
(40176,0,2,3,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Sen''jin Frog - Event linked - Face invoker'),
(40176,0,3,0,61,0,100,0,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sen''jin Frog - Event linked - Despawn'),

(40188,0,0,1,11,0,100,0,0,0,0,0,0,11,31517,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Attuned Frog - On spawn - Cast "Bind Visual Spawn In DND"'),
(40188,0,1,0,61,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Attuned Frog - Event linked - Start random movement'),

(40204,0,0,3,62,0,100,0,11345,0,0,0,0,11,74978,2,0,0,0,0,7,0,0,0,0,0,0,0,0,'Handler Marnlek - On gossip option 0 selected - Cast "Echo Isles: Unlearned Spy Frog Taxi"'),
(40204,0,1,3,62,0,100,0,11345,1,0,0,0,11,75421,2,0,0,0,0,7,0,0,0,0,0,0,0,0,'Handler Marnlek - On gossip option 1 selected - Cast "Echo Isles: Unlearned Troll Recruit Taxi"'),
(40204,0,2,3,62,0,100,0,11345,2,0,0,0,11,75422,2,0,0,0,0,7,0,0,0,0,0,0,0,0,'Handler Marnlek - On gossip option 2 selected - Cast "Echo Isles: Unlearned Troll Battle Taxi"'),
(40204,0,3,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Handler Marnlek - Event linked - Close gossip'),

(40218,0,0,1,8,0,100,1,74977,0,10000,10000,0,33,40218,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Spy Frog Credit - On spellhit "Frogs Away!" - Kill credit'),
(40218,0,1,0,61,0,100,0,0,0,0,0,0,80,4021800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Spy Frog Credit - Event linked - Call timed actionlist'),
(4021800,9,0,0,0,0,100,0,2000,2000,0,0,0,28,74971,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Spy Frog Credit - Remove aura "Red Flare State"'),
(4021800,9,1,0,0,0,100,0,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Spy Frog Credit - Despawn'),

(40253,0,0,0,1,0,100,0,0,0,300000,300000,0,80,4025300,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Champion Uru''zin - Out of combat (5 min) - Call timed actionlist'),
(4025300,9,0,0,0,0,100,0,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Set sheath state unarmed'),
(4025300,9,1,0,0,0,100,0,2500,2500,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Say line 1'),
(4025300,9,2,0,0,0,100,0,6500,6500,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Say line 2'),
(4025300,9,3,0,0,0,100,0,3250,3250,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Play emote'),
(4025300,9,4,0,0,0,100,0,1600,1600,0,0,0,45,1,1,0,0,0,0,11,40392,15,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Set data 1 1 on Darkspear Warrior'),
(4025300,9,5,0,0,0,100,0,1600,1600,0,0,0,1,2,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Say line 3'),
(4025300,9,6,0,0,0,100,0,6500,6500,0,0,0,1,3,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Say line 4'),
(4025300,9,7,0,0,0,100,0,6400,6400,0,0,0,1,4,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Say line 5'),
(4025300,9,8,0,0,0,100,0,3300,3300,0,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Play emote'),
(4025300,9,9,0,0,0,100,0,4800,4800,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Play emote'),
(4025300,9,10,0,0,0,100,0,3200,3200,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Champion Uru''zin - Set sheath state ranged'),

(40392,0,0,0,38,0,100,0,1,1,0,0,0,88,4039200,4039202,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Warrior - On data set 1 1 - Call random range actionlist'),
(4039200,9,0,0,0,0,100,0,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039200,9,1,0,0,0,100,0,13000,13000,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039200,9,2,0,0,0,100,0,3300,3300,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039200,9,3,0,0,0,100,0,4800,4800,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039200,9,4,0,0,0,100,0,3200,3200,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039201,9,0,0,0,0,100,0,800,800,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039201,9,1,0,0,0,100,0,13000,13000,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039201,9,2,0,0,0,100,0,3300,3300,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039201,9,3,0,0,0,100,0,4800,4800,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039201,9,4,0,0,0,100,0,3200,3200,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039202,9,0,0,0,0,100,0,1600,1600,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039202,9,1,0,0,0,100,0,13000,13000,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039202,9,2,0,0,0,100,0,3300,3300,0,0,0,5,71,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039202,9,3,0,0,0,100,0,4800,4800,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),
(4039202,9,4,0,0,0,100,0,3200,3200,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Warrior - Play emote'),

(40356,0,0,0,11,0,100,0,0,0,0,0,0,88,4035600,4035602,0,0,0,0,1,0,0,0,0,0,0,0,0,'Ritual Dancer - On spawn - Call random range actionlist'),
(4035600,9,0,0,0,0,100,0,0,0,0,0,0,11,75228,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Ritual Dancer - Cast "Tiki Mask Visual 01"'),
(4035601,9,0,0,0,0,100,0,0,0,0,0,0,11,75229,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Ritual Dancer - Cast "Tiki Mask Visual 02"'),
(4035602,9,0,0,0,0,100,0,0,0,0,0,0,11,75230,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Ritual Dancer - Cast "Tiki Mask Visual 03"'),

(40416,0,0,1,11,0,100,0,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Scout - On spawn - Disable gravity'),
(40416,0,1,0,61,0,100,0,0,0,0,0,0,53,1,4041600,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Scout - Event linked - Start waypoints 1'),
(40416,0,2,0,58,0,100,0,0,4041600,0,0,0,80,4041600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Scout - On waypoints 1 ended - Call timed actionlist 1'),
(40416,0,3,0,58,0,100,0,0,4041601,0,0,0,80,4041601,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Scout - On waypoints 2 ended - Call timed actionlist 2'),
(40416,0,4,0,58,0,100,0,0,4041602,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Darkspear Scout - On waypoints 3 ended - Despawn after 1s'),
(4041600,9,0,0,0,0,100,0,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Enable gravity'),
(4041600,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-838.1789,-4989.835,14.905015,0,'Actionlist - Darkspear Scout - Move to position'),
(4041600,9,2,0,0,0,100,0,1600,1600,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Dismount'),
(4041600,9,3,0,0,0,100,0,2000,2000,0,0,0,53,1,4041601,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Start waypoints 2'),
(4041601,9,0,0,0,0,100,0,200,200,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.820304751396179199,'Actionlist - Darkspear Scout - Set orientation'),
(4041601,9,1,0,0,0,100,0,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Set sheath state unarmed'),
(4041601,9,2,0,0,0,100,0,1200,1200,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Play emote'),
(4041601,9,3,0,0,0,100,0,3200,3200,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Say line 1'),
(4041601,9,4,0,0,0,100,0,6500,6500,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Say line 2'),
(4041601,9,5,0,0,0,100,0,10000,10000,0,0,0,1,0,0,0,0,0,0,19,40391,10,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Vol''jin says line 1'),
(4041601,9,6,0,0,0,100,0,3000,3000,0,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Play emote'),
(4041601,9,7,0,0,0,100,0,3200,3200,0,0,0,53,0,4041602,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Darkspear Scout - Start waypoints 3');

DELETE FROM `creature_text` WHERE `CreatureID` IN (40416, 40253, 40391);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(40416, 0, 0, 'Zalazane got most of his hexed trolls hidden under de canopy on de big island.', 12, 0, 100, 5, 0, 0, 40411, 0, 'Darkspear Scout'),
(40416, 1, 0, 'He got a big army, an'' he be plannin'' somethin'' down dere.', 12, 0, 100, 1, 0, 0, 40412, 0, 'Darkspear Scout'),
(40391, 0, 0, 'Thank ya, scout. Keep up da patrols. But for now, a rest is in order. Dismissed.', 12, 0, 100, 5, 0, 0, 40413, 0, 'Vol''jin'),
(40253, 0, 0, 'Warriors of de Darkspear Tribe, our leader, de great Vol''jin prepares to reclaim de Echo Isles.', 12, 0, 100, 1, 0, 0, 40404, 0, 'Champion Uru''zin'),
(40253, 1, 0, 'De battle ahead will be de true test of de warrior''s skill, de true test of loyalty.', 12, 0, 100, 1, 0, 0, 40405, 0, 'Champion Uru''zin'),
(40253, 2, 0, 'De spirits of our ancestors will be watchin'' us and aidin'' us in dis battle.', 12, 0, 100, 1, 0, 0, 40408, 0, 'Champion Uru''zin'),
(40253, 3, 0, 'Do dem proud! Show dem your bravery and your ferocity! Bring honor to their spirits!', 12, 0, 100, 25, 0, 0, 40409, 0, 'Champion Uru''zin'),
(40253, 4, 0, 'An'' most of all, we be showin'' Zalazane dat his time be at an end! Dat he will give back what be rightfully ours!', 12, 0, 100, 5, 0, 0, 40410, 0, 'Champion Uru''zin');

DELETE FROM `waypoints` WHERE `entry`=40416;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 4041600 AND 4041602;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(4041600, 1, -847.34894, -5067.6147, 44.53932, NULL, 0, 'Darkspear Scout - Waypoints 1'),
(4041600, 2, -845.3715, -5046.6772, 36.678055, NULL, 0, 'Darkspear Scout - Waypoints 1'),
(4041600, 3, -842.8768, -5023.0103, 28.066988, NULL, 0, 'Darkspear Scout - Waypoints 1'),
(4041600, 4, -839.65625, -4999.0415, 18.678074, NULL, 0, 'Darkspear Scout - Waypoints 1'),
(4041600, 5, -838.17883, -4989.835, 16.316948, NULL, 0, 'Darkspear Scout - Waypoints 1'),
(4041601, 1, -830.34033, -4997.711, 15.596991, NULL, 0, 'Darkspear Scout - Waypoints 2'), -- Spline
(4041601, 2, -808.0018, -5010.587, 15.288965, NULL, 0, 'Darkspear Scout - Waypoints 2'),
(4041601, 3, -796.17365, -5009.604, 15.994558, NULL, 0, 'Darkspear Scout - Waypoints 2'),
(4041601, 4, -782.4566, -5002.5176, 17.227955, NULL, 0, 'Darkspear Scout - Waypoints 2'),
(4041601, 5, -758.71356, -5001.0884, 19.623611, NULL, 0, 'Darkspear Scout - Waypoints 2'),
(4041602, 1, -763.01044, -4995.0537, 20.094784, NULL, 0, 'Darkspear Scout - Waypoints 3'),
(4041602, 2, -753.53644, -4974.764, 21.784557, NULL, 0, 'Darkspear Scout - Waypoints 3'),
(4041602, 3, -742.8715, -4961.8784, 22.5831, NULL, 0, 'Darkspear Scout - Waypoints 3');

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 208901 AND 209018;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 208901 AND 209018;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 208901 AND 209018;
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` BETWEEN 208901 AND 209018;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+154;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `VerifiedBuild`) VALUES
-- Sen'jin Village
(@CGUID+0, 40184, 1, 14, 367, 1, 1, 0, 1, -747.17535400390625, -5003.97412109375, 19.50520896911621093, 3.769911050796508789, 120, 0, 0, 12600, 3994, 0, 53788), -- Vanira (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+1, 40187, 1, 14, 367, 1, 1, 0, 0, -747.70489501953125, -5007.78125, 18.8993072509765625, 3.385938644409179687, 120, 0, 0, 53, 0, 0, 53788), -- Vanira's Sentry Totem (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+2, 40204, 1, 14, 367, 1, 1, 0, 1, -840.05206298828125, -4982.1630859375, 14.42926979064941406, 4.86946868896484375, 120, 0, 0, 11770, 3809, 0, 53788), -- Handler Marnlek (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+3, 40222, 1, 14, 367, 1, 1, 0, 0, -833.529541015625, -4980.720703125, 16.1929779052734375, 4.293509960174560546, 120, 0, 0, 12600, 0, 0, 53788), -- Scout Bat (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+4, 40253, 1, 14, 367, 1, 1, 0, 1, -765.43231201171875, -5018.3974609375, 17.14230537414550781, 3.735004663467407226, 120, 0, 0, 12600, 3994, 0, 53788), -- Champion Uru'zin (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75075 - [DND] Persuaded, 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 40352, 1, 14, 367, 1, 1, 0, 1, -805.01043701171875, -4975.75, 17.731353759765625, 4.625122547149658203, 120, 0, 0, 12600, 3994, 0, 53788), -- Witch Doctor Hez'tok (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+6, 40356, 1, 14, 367, 1, 1, 0, 0, -810.127685546875, -4981.27001953125, 17.4376068115234375, 5.148721218109130859, 120, 0, 0, 12600, 3994, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75228 - Tiki Mask Visual 01)
(@CGUID+7, 40356, 1, 14, 367, 1, 1, 0, 0, -816.66607666015625, -4987.6337890625, 16.71418952941894531, 5.846852779388427734, 120, 0, 0, 11379, 3725, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75229 - Tiki Mask Visual 02)
(@CGUID+8, 40356, 1, 14, 367, 1, 1, 0, 0, -794.63323974609375, -4987.93408203125, 17.71096420288085937, 3.490658521652221679, 120, 0, 0, 10282, 3466, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75228 - Tiki Mask Visual 01)
(@CGUID+9, 40356, 1, 14, 367, 1, 1, 0, 0, -800.999755859375, -4981.392578125, 17.73172950744628906, 4.276056766510009765, 120, 0, 0, 12175, 3893, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75228 - Tiki Mask Visual 01)
(@CGUID+10, 40356, 1, 14, 367, 1, 1, 0, 0, -801.29620361328125, -5003.42431640625, 16.53342056274414062, 2.216568231582641601, 120, 0, 0, 12600, 3994, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75229 - Tiki Mask Visual 02)
(@CGUID+11, 40356, 1, 14, 367, 1, 1, 0, 0, -794.7557373046875, -4997.056640625, 17.17598724365234375, 3.211405754089355468, 120, 0, 0, 11379, 3725, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75228 - Tiki Mask Visual 01)
(@CGUID+12, 40356, 1, 14, 367, 1, 1, 0, 0, -810.423095703125, -5003.30029296875, 16.23058891296386718, 0.994837641716003417, 120, 0, 0, 10282, 3466, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75229 - Tiki Mask Visual 02)
(@CGUID+13, 40356, 1, 14, 367, 1, 1, 0, 0, -816.789794921875, -4996.76123046875, 16.61115455627441406, 0.349065840244293212, 120, 0, 0, 11379, 3725, 0, 53788), -- Ritual Dancer (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 75228 - Tiki Mask Visual 01)
(@CGUID+14, 40361, 1, 14, 367, 1, 1, 0, 0, -805.7860107421875, -4992.45068359375, 17.33248138427734375, 4.363323211669921875, 120, 0, 0, 42, 0, 0, 53788), -- Troll Dance Leader (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+15, 40387, 1, 14, 367, 1, 1, 0, 0, -805.02081298828125, -4975.9375, 17.96628952026367187, 0, 120, 0, 0, 42, 0, 0, 53788), -- Omen Event Credit (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+16, 40391, 1, 14, 367, 1, 1, 0, 1, -755.1475830078125, -4998.0400390625, 20.33691215515136718, 4.031710624694824218, 120, 0, 0, 5578000, 68128, 0, 53788), -- Vol'jin (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+17, 40392, 1, 14, 367, 1, 1, 0, 1, -768.63543701171875, -5023.29541015625, 16.76416778564453125, 0.750491559505462646, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+18, 40392, 1, 14, 367, 1, 1, 0, 1, -771.30206298828125, -5021.15966796875, 16.70833396911621093, 0.750491559505462646, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+19, 40392, 1, 14, 367, 1, 1, 0, 1, -765.890625, -5025.62158203125, 16.8368072509765625, 0.715584993362426757, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+20, 40392, 1, 14, 367, 1, 1, 0, 1, -775.84552001953125, -5021.3505859375, 16.11614990234375, 0.558505356311798095, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+21, 40392, 1, 14, 367, 1, 1, 0, 1, -775.15802001953125, -5025.70849609375, 16.1457977294921875, 0.750491559505462646, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+22, 40392, 1, 14, 367, 1, 1, 0, 1, -749.078125, -5000.17041015625, 20.16327095031738281, 3.892084121704101562, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+23, 40392, 1, 14, 367, 1, 1, 0, 1, -773.82293701171875, -5019.0068359375, 16.52001953125, 0.610865235328674316, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+24, 40392, 1, 14, 367, 1, 1, 0, 1, -777.67706298828125, -5023.55908203125, 15.95835494995117187, 0.610865235328674316, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+25, 40392, 1, 14, 367, 1, 1, 0, 1, -767.90277099609375, -5027.93408203125, 16.31126785278320312, 0.767944872379302978, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+26, 40392, 1, 14, 367, 1, 1, 0, 1, -757.123291015625, -4992.1181640625, 21.01827430725097656, 3.96189737319946289, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+27, 40392, 1, 14, 367, 1, 1, 0, 1, -770.64581298828125, -5025.61474609375, 16.2830352783203125, 0.698131680488586425, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+28, 40392, 1, 14, 367, 1, 1, 0, 1, -773.326416015625, -5023.50341796875, 16.52063751220703125, 0.733038306236267089, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+29, 40392, 1, 14, 367, 1, 1, 0, 1, -763.30902099609375, -5027.79541015625, 16.87847328186035156, 0.733038306236267089, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+30, 40392, 1, 14, 367, 1, 1, 0, 1, -767.16839599609375, -5032.35791015625, 16.15991020202636718, 0.733038306236267089, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+31, 40392, 1, 14, 367, 1, 1, 0, 1, -765.3125, -5030.111328125, 16.3195953369140625, 0.715584993362426757, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+32, 40392, 1, 14, 367, 1, 1, 0, 1, -772.48785400390625, -5027.84375, 16.176177978515625, 0.593411922454833984, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+33, 40392, 1, 14, 367, 1, 1, 0, 1, -769.75, -5030.1630859375, 16.01453590393066406, 0.715584993362426757, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+34, 40392, 1, 14, 367, 1, 1, 0, 1, -738.1788330078125, -4955.24853515625, 22.87205696105957031, 4.276056766510009765, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+35, 40392, 1, 14, 367, 1, 1, 0, 1, -741.29168701171875, -4956.875, 22.8888702392578125, 5.8817596435546875, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+36, 40392, 1, 14, 367, 1, 1, 0, 1, -732.2413330078125, -5022.27587890625, 16.8452606201171875, 3.892084121704101562, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+37, 40392, 1, 14, 367, 1, 1, 0, 1, -735.36456298828125, -5027.3994140625, 16.46612167358398437, 2.007128715515136718, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+38, 40392, 1, 14, 367, 1, 1, 0, 1, -738.25, -4962.16650390625, 22.74147224426269531, 2.094395160675048828, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Warrior (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@CGUID+39, 40416, 1, 14, 393, 1, 1, 0, 1, -861.3819580078125, -5117.953125, 47.46448516845703125, 1.298925042152404785, 120, 0, 0, 12600, 0, 0, 53788), -- Darkspear Scout (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+40, 40176, 1, 14, 367, 1, 1, 0, 0, -761.4913330078125, -4979.48974609375, 21.27761077880859375, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+41, 40176, 1, 14, 367, 1, 1, 0, 0, -721.45489501953125, -5041.0693359375, 15.96520614624023437, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2))
(@CGUID+42, 40176, 1, 14, 367, 1, 1, 0, 0, -746.33856201171875, -4959.142578125, 22.60099029541015625, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+43, 40176, 1, 14, 393, 1, 1, 0, 0, -721.44964599609375, -5060.798828125, 14.67235469818115234, 5.276498317718505859, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+44, 40176, 1, 14, 367, 1, 1, 0, 0, -741.40802001953125, -5049.798828125, 14.89621448516845703, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+45, 40176, 1, 14, 0, 1, 1, 0, 0, -702.0242919921875, -4936.859375, 24.78557968139648437, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+46, 40176, 1, 14, 0, 1, 1, 0, 0, -760.2413330078125, -4883.55224609375, 20.76257896423339843, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+47, 40176, 1, 14, 367, 1, 1, 0, 0, -724.5625, -4818.8193359375, 26.28030014038085937, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+48, 40176, 1, 14, 0, 1, 1, 0, 0, -787.11456298828125, -4886.40087890625, 19.40635871887207031, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+49, 40176, 1, 14, 367, 1, 1, 0, 0, -729.86981201171875, -4891.54150390625, 20.80730819702148437, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+50, 40176, 1, 14, 367, 1, 1, 0, 0, -821.30206298828125, -4945.25341796875, 21.38181495666503906, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+51, 40176, 1, 14, 367, 1, 1, 0, 0, -825.763916015625, -4881.84912109375, 19.6065673828125, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+52, 40176, 1, 14, 367, 1, 1, 0, 0, -836.92706298828125, -4913.4462890625, 19.9190216064453125, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+53, 40176, 1, 14, 367, 1, 1, 0, 0, -748.83856201171875, -4906.57666015625, 21.7292327880859375, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+54, 40176, 1, 14, 367, 1, 1, 0, 0, -819.82293701171875, -4899.18212890625, 19.33116531372070312, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+55, 40176, 1, 14, 367, 1, 1, 0, 0, -755.16839599609375, -4936.03662109375, 21.85312652587890625, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+56, 40176, 1, 14, 367, 1, 1, 0, 0, -816.50518798828125, -5012.21728515625, 14.52201271057128906, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+57, 40176, 1, 14, 367, 1, 1, 0, 0, -899.05035400390625, -4994.486328125, 11.61573982238769531, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+58, 40176, 1, 14, 367, 1, 1, 0, 0, -802.01739501953125, -5037.51025390625, 10.57736015319824218, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+59, 40176, 1, 14, 367, 1, 1, 0, 0, -879.2586669921875, -4998.140625, 11.62432479858398437, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+60, 40176, 1, 14, 367, 1, 1, 0, 0, -858.81597900390625, -5039.14404296875, 3.009856224060058593, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+61, 40176, 1, 14, 367, 1, 1, 0, 0, -862.34027099609375, -4878.53466796875, 20.73167610168457031, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+62, 40176, 1, 14, 367, 1, 1, 0, 0, -977.39410400390625, -4935.78466796875, 2.094997167587280273, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+63, 40176, 1, 14, 367, 1, 1, 0, 0, -886.93927001953125, -4879.79345703125, 11.099761962890625, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+64, 40176, 1, 14, 367, 1, 1, 0, 0, -902.4132080078125, -4921.45654296875, 15.91738510131835937, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+65, 40176, 1, 14, 393, 1, 1, 0, 0, -1056.60595703125, -4785.24462890625, 16.12485313415527343, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+66, 40176, 1, 14, 393, 1, 1, 0, 0, -1095.2899169921875, -4817.8369140625, 4.299854278564453125, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+67, 40176, 1, 14, 393, 1, 1, 0, 0, -1043.8385009765625, -4853.01904296875, 10.14375591278076171, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+68, 40176, 1, 14, 393, 1, 1, 0, 0, -1046.329833984375, -4874.751953125, 3.680143356323242187, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+69, 40176, 1, 14, 393, 1, 1, 0, 0, -1019.286376953125, -4867.87158203125, 7.741229534149169921, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+70, 40176, 1, 14, 367, 1, 1, 0, 0, -943.03643798828125, -4990.80712890625, 5.739674568176269531, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+71, 40176, 1, 14, 393, 1, 1, 0, 0, -944.935791015625, -4976.017578125, 7.39838266372680664, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+72, 40176, 1, 14, 367, 1, 1, 0, 0, -980.50518798828125, -4858.24853515625, 12.1892242431640625, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+73, 40176, 1, 14, 393, 1, 1, 0, 0, -924.55035400390625, -4933.63916015625, 15.40508174896240234, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+74, 40176, 1, 14, 367, 1, 1, 0, 0, -975.32464599609375, -4958.41845703125, 2.663735151290893554, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2))
(@CGUID+75, 40176, 1, 14, 393, 1, 1, 0, 0, -924.904541015625, -4912.98974609375, 14.60846614837646484, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+76, 40176, 1, 14, 367, 1, 1, 0, 0, -928.42364501953125, -4984.96875, 9.577900886535644531, 3.3780059814453125, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+77, 40176, 1, 14, 393, 1, 1, 0, 0, -899.7882080078125, -5010.37158203125, 6.849414348602294921, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2 (Auras: 75433 - Spawn Invisibility Aura (QZS 2)) (possible waypoints or random movement)
(@CGUID+78, 40176, 1, 14, 367, 1, 1, 0, 0, -790.77081298828125, -5014.88916015625, 15.7722930908203125, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Sen'jin Village - Difficulty: 0) CreateObject2
(@CGUID+79, 40176, 1, 14, 393, 1, 1, 0, 0, -689.66143798828125, -5107.501953125, 4.891781330108642578, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+80, 40176, 1, 14, 393, 1, 1, 0, 0, -706.873291015625, -5089.25341796875, 10.18779563903808593, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+81, 40176, 1, 14, 0, 1, 1, 0, 0, -707.09552001953125, -4877.09033203125, 24.10580253601074218, 2.177077293395996093, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+82, 40176, 1, 14, 393, 1, 1, 0, 0, -1101.3055419921875, -4749.20654296875, 9.48058319091796875, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+83, 40176, 1, 14, 393, 1, 1, 0, 0, -1088.6597900390625, -4744.001953125, 14.55965614318847656, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
(@CGUID+84, 40176, 1, 14, 393, 1, 1, 0, 0, -1097.9583740234375, -4722.8662109375, 11.66373538970947265, 0, 120, 10, 0, 42, 0, 1, 53788), -- Sen'jin Frog (Area: Darkspear Strand - Difficulty: 0) CreateObject2
-- Echo Isles
(@CGUID+85, 40301, 1, 14, 368, 1, 1, 0, 0, -1122.29345703125, -5126.54345703125, 2.912185192108154296, 0.767944872379302978, 120, 0, 0, 42, 0, 0, 53788), -- Tiger Matriarch Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+86, 40218, 1, 14, 368, 1, 1, 0, 0, -954.8211669921875, -5186.23779296875, 1.090953350067138671, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+87, 40218, 1, 14, 368, 1, 1, 0, 0, -853.24481201171875, -5335.12841796875, 2.751948356628417968, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+88, 40218, 1, 14, 367, 1, 1, 0, 0, -794.69964599609375, -5350.50537109375, 2.743489265441894531, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Sen'jin Village - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+89, 40218, 1, 14, 368, 1, 1, 0, 0, -688.09552001953125, -5517.6875, 6.003633499145507812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+90, 40218, 1, 14, 368, 1, 1, 0, 0, -732.17706298828125, -5498.767578125, 5.773289680480957031, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+91, 40218, 1, 14, 368, 1, 1, 0, 0, -794.59552001953125, -5544.4619140625, 5.39234161376953125, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+92, 40218, 1, 14, 368, 1, 1, 0, 0, -654.15625, -5626.69970703125, 7.23921060562133789, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+93, 40218, 1, 14, 368, 1, 1, 0, 0, -729.59722900390625, -5655.970703125, 20.00365638732910156, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+94, 40218, 1, 14, 368, 1, 1, 0, 0, -805.80731201171875, -5674.3837890625, 6.655506610870361328, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+95, 40218, 1, 14, 368, 1, 1, 0, 0, -835.0711669921875, -5606.0380859375, 4.204616546630859375, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+96, 40218, 1, 14, 368, 1, 1, 0, 0, -1061.529541015625, -5631.46337890625, 4.56439065933227539, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+97, 40218, 1, 14, 368, 1, 1, 0, 0, -1040.7882080078125, -5585.18603515625, 3.462282180786132812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+98, 40218, 1, 14, 368, 1, 1, 0, 0, -1123.2882080078125, -5619.78125, 5.644940376281738281, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+99, 40218, 1, 14, 368, 1, 1, 0, 0, -1049.91845703125, -5542.5068359375, 7.805533409118652343, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+100, 40218, 1, 14, 368, 1, 1, 0, 0, -1194.8160400390625, -5617.876953125, 6.845169544219970703, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+101, 40218, 1, 14, 368, 1, 1, 0, 0, -1240.3785400390625, -5594.70849609375, 8.538580894470214843, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+102, 40218, 1, 14, 368, 1, 1, 0, 0, -1129.8316650390625, -5481.1494140625, 7.601991653442382812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+103, 40218, 1, 14, 368, 1, 1, 0, 0, -1288.6024169921875, -5571.11474609375, 7.435792446136474609, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+104, 40218, 1, 14, 368, 1, 1, 0, 0, -1321.611083984375, -5527.359375, 4.558995723724365234, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+105, 40218, 1, 14, 368, 1, 1, 0, 0, -1319.65625, -5477.3349609375, 5.189212322235107421, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+106, 40218, 1, 14, 368, 1, 1, 0, 0, -1269.0521240234375, -5386.2412109375, 4.37299966812133789, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+107, 40218, 1, 14, 368, 1, 1, 0, 0, -1532.3072509765625, -5340.73779296875, 7.001649379730224609, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+108, 40218, 1, 14, 368, 1, 1, 0, 0, -1589.217041015625, -5340.08154296875, 7.069466590881347656, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+109, 40218, 1, 14, 368, 1, 1, 0, 0, -1502.296875, -5262.67724609375, 4.592952728271484375, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+110, 40218, 1, 14, 368, 1, 1, 0, 0, -1611.142333984375, -5275.97900390625, 7.616913318634033203, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+111, 40218, 1, 14, 368, 1, 1, 0, 0, -1423.26220703125, -5171.40478515625, 3.539060354232788085, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+112, 40218, 1, 14, 368, 1, 1, 0, 0, -1304.359375, -5169.80029296875, 0.850009322166442871, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+113, 40218, 1, 14, 368, 1, 1, 0, 0, -1290.5260009765625, -5122.4306640625, 1.761084318161010742, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+114, 40218, 1, 14, 368, 1, 1, 0, 0, -1127.7691650390625, -5131.19970703125, 2.938694238662719726, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+115, 40218, 1, 14, 368, 1, 1, 0, 0, -1088.9635009765625, -5173.8837890625, 0.833697319030761718, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+116, 40218, 1, 14, 368, 1, 1, 0, 0, -1188.8177490234375, -5342.517578125, 4.285264492034912109, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+117, 40218, 1, 14, 368, 1, 1, 0, 0, -1020.20831298828125, -5152.767578125, 0.750920295715332031, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+118, 40218, 1, 14, 368, 1, 1, 0, 0, -1066.361083984375, -5374.91650390625, 6.872701644897460937, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+119, 40218, 1, 14, 368, 1, 1, 0, 0, -1201.6041259765625, -5379.16845703125, 8.589357376098632812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+120, 40218, 1, 14, 368, 1, 1, 0, 0, -1148.4254150390625, -5413.82275390625, 9.589723587036132812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+121, 40218, 1, 14, 368, 1, 1, 0, 0, -1102.048583984375, -5435.26416015625, 10.6309661865234375, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
(@CGUID+122, 40218, 1, 14, 368, 1, 1, 0, 0, -1060.920166015625, -5459.61962890625, 8.204561233520507812, 0, 30, 0, 0, 42, 0, 0, 53788), -- Spy Frog Credit (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 74980 - Spy Frog Invisibility, 74971 - Red Flare State)
-- Razor Hill
(@CGUID+123, 40256, 1, 14, 362, 1, 1, 0, 0, 271.295135498046875, -4739.45849609375, 9.899149894714355468, 5.79449319839477539, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+124, 40256, 1, 14, 362, 1, 1, 0, 0, 248.001739501953125, -4672.84033203125, 16.01275634765625, 5.410520553588867187, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+125, 40256, 1, 14, 362, 1, 1, 0, 0, 246.5208282470703125, -4717.0087890625, 15.29293155670166015, 1.535889744758605957, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+126, 40256, 1, 14, 362, 1, 1, 0, 0, 254.9496612548828125, -4698.4130859375, 14.71032047271728515, 2.722713708877563476, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+127, 40256, 1, 14, 362, 1, 1, 0, 0, 289.44964599609375, -4820.142578125, 10.60737133026123046, 0.959931075572967529, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+128, 40256, 1, 14, 362, 1, 1, 0, 0, 266.07464599609375, -4829.90283203125, 10.90517807006835937, 0.331612557172775268, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+129, 40256, 1, 14, 362, 1, 1, 0, 0, 310.90625, -4672.18603515625, 16.5634002685546875, 2.478367567062377929, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+130, 40256, 1, 14, 362, 1, 1, 0, 0, 347.310760498046875, -4723.87841796875, 10.32458209991455078, 4.939281940460205078, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+131, 40256, 1, 14, 362, 1, 1, 0, 0, 351.6788330078125, -4693.84033203125, 16.54110336303710937, 2.251474618911743164, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+132, 40256, 1, 14, 362, 1, 1, 0, 0, 343.736114501953125, -4791.71533203125, 11.36291027069091796, 0.959931075572967529, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+133, 40256, 1, 14, 362, 1, 1, 0, 0, 369.435760498046875, -4690.94970703125, 15.85660266876220703, 5.393067359924316406, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+134, 40256, 1, 14, 362, 1, 1, 0, 0, 375.814239501953125, -4775.57666015625, 12.50812625885009765, 5.759586334228515625, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+135, 40256, 1, 14, 362, 1, 1, 0, 0, 375.765625, -4777.9462890625, 12.52974224090576171, 0.767944872379302978, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+136, 40256, 1, 14, 362, 1, 1, 0, 0, 333.508697509765625, -4815.27099609375, 10.60719776153564453, 2.827433347702026367, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+137, 40256, 1, 14, 362, 1, 1, 0, 0, 343.204864501953125, -4831.05712890625, 10.19747829437255859, 0.244346097111701965, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73940 - Citizen Costume)
(@CGUID+138, 40256, 1, 14, 362, 1, 1, 0, 0, 345.03125, -4831.41162109375, 10.30186080932617187, 2.600540637969970703, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1
(@CGUID+139, 40257, 1, 14, 362, 1, 1, 0, 0, 273.432281494140625, -4738.96337890625, 9.832179069519042968, 3.735004663467407226, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject2
(@CGUID+140, 40257, 1, 14, 362, 1, 1, 0, 0, 321.611114501953125, -4640.15478515625, 16.68959426879882812, 3.490658521652221679, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+141, 40257, 1, 14, 362, 1, 1, 0, 0, 246.170135498046875, -4714.72900390625, 15.37176799774169921, 5.654866695404052734, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+142, 40257, 1, 14, 362, 1, 1, 0, 0, 247.421875, -4675.2724609375, 16.19962692260742187, 0.296705961227416992, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+143, 40257, 1, 14, 362, 1, 1, 0, 0, 349.482635498046875, -4724.8818359375, 10.32458209991455078, 3.124139308929443359, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+144, 40257, 1, 14, 362, 1, 1, 0, 0, 284.388885498046875, -4628.46728515625, 18.7369537353515625, 4.886921882629394531, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+145, 40257, 1, 14, 362, 1, 1, 0, 0, 338.173614501953125, -4669.6943359375, 16.54110336303710937, 4.712388992309570312, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+146, 40257, 1, 14, 362, 1, 1, 0, 0, 282.758697509765625, -4629.548828125, 18.29562568664550781, 0.226892799139022827, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+147, 40257, 1, 14, 362, 1, 1, 0, 0, 343.364593505859375, -4789.48779296875, 11.72961139678955078, 6.091198921203613281, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+148, 40257, 1, 14, 362, 1, 1, 0, 0, 301.664947509765625, -4612.20654296875, 28.02319908142089843, 0.959931075572967529, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+149, 40257, 1, 14, 362, 1, 1, 0, 0, 379.7257080078125, -4661.29345703125, 16.13381767272949218, 4.415682792663574218, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+150, 40257, 1, 14, 362, 1, 1, 0, 0, 411.10589599609375, -4704.45849609375, 9.560571670532226562, 3.822271108627319335, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+151, 40257, 1, 14, 362, 1, 1, 0, 0, 408.94964599609375, -4703.796875, 9.6985626220703125, 4.607669353485107421, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1
(@CGUID+152, 40257, 1, 14, 362, 1, 1, 0, 0, 293.423614501953125, -4798.140625, 10.08959388732910156, 2.251474618911743164, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject2 (Auras: 73939 - Citizen Costume)
(@CGUID+153, 40257, 1, 14, 362, 1, 1, 0, 0, 273.35589599609375, -4774.60400390625, 12.17043685913085937, 0.959931075572967529, 120, 0, 0, 42, 0, 0, 53788), -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)
(@CGUID+154, 40257, 1, 14, 362, 1, 1, 0, 0, 319.572906494140625, -4639.40087890625, 16.7221832275390625, 4.991641521453857421, 120, 0, 0, 42, 0, 0, 53788); -- Troll Citizen (Area: Razor Hill - Difficulty: 0) CreateObject1 (Auras: 73939 - Citizen Costume)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+154;
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+34, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Darkspear Warrior
(@CGUID+35, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Darkspear Warrior
(@CGUID+36, 0, 1, 0, 0, 1, 0, 0, 0, ''), -- Darkspear Warrior
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Darkspear Warrior
(@CGUID+38, 0, 1, 0, 0, 1, 0, 0, 0, ''), -- Darkspear Warrior
(@CGUID+126, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+127, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+128, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+129, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+131, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+133, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+136, 0, 1, 0, 0, 1, 0, 0, 0, '73940'), -- Troll Citizen
(@CGUID+145, 0, 1, 0, 0, 1, 0, 0, 0, '73939'), -- Troll Citizen
(@CGUID+148, 0, 1, 0, 0, 1, 0, 0, 0, '73939'), -- Troll Citizen
(@CGUID+149, 0, 1, 0, 0, 1, 0, 0, 0, '73939'), -- Troll Citizen
(@CGUID+152, 0, 1, 0, 0, 1, 0, 0, 0, '73939'), -- Troll Citizen
(@CGUID+153, 0, 1, 0, 0, 1, 0, 0, 0, '73939'); -- Troll Citizen

DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+154;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(2, 0, @CGUID+40),
(2, 0, @CGUID+41),
(2, 0, @CGUID+42),
(2, 0, @CGUID+43),
(2, 0, @CGUID+44),
(2, 0, @CGUID+45),
(2, 0, @CGUID+46),
(2, 0, @CGUID+47),
(2, 0, @CGUID+48),
(2, 0, @CGUID+49),
(2, 0, @CGUID+50),
(2, 0, @CGUID+51),
(2, 0, @CGUID+52),
(2, 0, @CGUID+53),
(2, 0, @CGUID+54),
(2, 0, @CGUID+55),
(2, 0, @CGUID+56),
(2, 0, @CGUID+57),
(2, 0, @CGUID+58),
(2, 0, @CGUID+59),
(2, 0, @CGUID+60),
(2, 0, @CGUID+61),
(2, 0, @CGUID+62),
(2, 0, @CGUID+63),
(2, 0, @CGUID+64),
(2, 0, @CGUID+65),
(2, 0, @CGUID+66),
(2, 0, @CGUID+67),
(2, 0, @CGUID+68),
(2, 0, @CGUID+69),
(2, 0, @CGUID+70),
(2, 0, @CGUID+71),
(2, 0, @CGUID+72),
(2, 0, @CGUID+73),
(2, 0, @CGUID+74),
(2, 0, @CGUID+75),
(2, 0, @CGUID+76),
(2, 0, @CGUID+77),
(2, 0, @CGUID+78),
(2, 0, @CGUID+79),
(2, 0, @CGUID+80),
(2, 0, @CGUID+81),
(2, 0, @CGUID+82),
(2, 0, @CGUID+83),
(2, 0, @CGUID+84),
(2, 0, @CGUID+86),
(2, 0, @CGUID+87),
(2, 0, @CGUID+88),
(2, 0, @CGUID+89),
(2, 0, @CGUID+90),
(2, 0, @CGUID+91),
(2, 0, @CGUID+92),
(2, 0, @CGUID+93),
(2, 0, @CGUID+94),
(2, 0, @CGUID+95),
(2, 0, @CGUID+96),
(2, 0, @CGUID+97),
(2, 0, @CGUID+98),
(2, 0, @CGUID+99),
(2, 0, @CGUID+100),
(2, 0, @CGUID+101),
(2, 0, @CGUID+102),
(2, 0, @CGUID+103),
(2, 0, @CGUID+104),
(2, 0, @CGUID+105),
(2, 0, @CGUID+106),
(2, 0, @CGUID+107),
(2, 0, @CGUID+108),
(2, 0, @CGUID+109),
(2, 0, @CGUID+110),
(2, 0, @CGUID+111),
(2, 0, @CGUID+112),
(2, 0, @CGUID+113),
(2, 0, @CGUID+114),
(2, 0, @CGUID+115),
(2, 0, @CGUID+116),
(2, 0, @CGUID+117),
(2, 0, @CGUID+118),
(2, 0, @CGUID+119),
(2, 0, @CGUID+120),
(2, 0, @CGUID+121),
(2, 0, @CGUID+122),
(2, 0, @CGUID+123),
(2, 0, @CGUID+124),
(2, 0, @CGUID+125),
(2, 0, @CGUID+126),
(2, 0, @CGUID+127),
(2, 0, @CGUID+128),
(2, 0, @CGUID+129),
(2, 0, @CGUID+130),
(2, 0, @CGUID+131),
(2, 0, @CGUID+132),
(2, 0, @CGUID+133),
(2, 0, @CGUID+134),
(2, 0, @CGUID+135),
(2, 0, @CGUID+136),
(2, 0, @CGUID+137),
(2, 0, @CGUID+138),
(2, 0, @CGUID+139),
(2, 0, @CGUID+140),
(2, 0, @CGUID+141),
(2, 0, @CGUID+142),
(2, 0, @CGUID+143),
(2, 0, @CGUID+144),
(2, 0, @CGUID+145),
(2, 0, @CGUID+146),
(2, 0, @CGUID+147),
(2, 0, @CGUID+148),
(2, 0, @CGUID+149),
(2, 0, @CGUID+150),
(2, 0, @CGUID+151),
(2, 0, @CGUID+152),
(2, 0, @CGUID+153),
(2, 0, @CGUID+154);

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 151829 AND 151887;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN 151829 AND 151887;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 151829 AND 151887;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Sen'jin Village
(@OGUID+0, 202833, 1, 14, 367, 1, 1, -839.14239501953125, -4978.3369140625, 14.5841064453125, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 53788), -- Sen'jin Bat Totem (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+1, 202834, 1, 14, 367, 1, 1, -833.62847900390625, -4980.71337890625, 14.82357597351074218, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 53788), -- Sen'jin Bat Roost Straw (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+2, 202835, 1, 14, 367, 1, 1, -827.06597900390625, -4983.640625, 15.51871395111083984, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+3, 202835, 1, 14, 367, 1, 1, -829.59552001953125, -4978.0087890625, 15.64376544952392578, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+4, 202839, 1, 14, 367, 1, 1, -831.79168701171875, -4975.609375, 15.85344982147216796, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence Post (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+5, 202879, 1, 14, 367, 1, 1, -797.4774169921875, -4972.70166015625, 17.80503463745117187, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 53788), -- Ritual Drum (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+6, 202880, 1, 14, 367, 1, 1, -789.609375, -4979.12841796875, 18.03583526611328125, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 53788), -- Ritual Gong (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+7, 202882, 1, 14, 367, 1, 1, -811.529541015625, -4988.205078125, 17.11979103088378906, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 53788), -- Small Ritual Drum (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+8, 202882, 1, 14, 367, 1, 1, -799.1007080078125, -4987.36474609375, 17.63783073425292968, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 53788), -- Small Ritual Drum (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+9, 202883, 1, 14, 367, 1, 1, -810.48785400390625, -4987.16650390625, 17.10089874267578125, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 53788), -- Small Ritual Drum 2 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+10, 202883, 1, 14, 367, 1, 1, -799.7882080078125, -4986.07275390625, 17.48750495910644531, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 53788), -- Small Ritual Drum 2 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+11, 202885, 1, 14, 367, 1, 1, -747.27081298828125, -4998.53466796875, 20.1927032470703125, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+12, 202885, 1, 14, 367, 1, 1, -755.015625, -4990.8818359375, 20.33255958557128906, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+13, 202885, 1, 14, 367, 1, 1, -763.57989501953125, -4919.81787109375, 20.17787742614746093, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+14, 202885, 1, 14, 367, 1, 1, -764.842041015625, -4936.15966796875, 21.09831428527832031, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+15, 202885, 1, 14, 367, 1, 1, -789.14410400390625, -4880.5849609375, 19.14895057678222656, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+16, 202885, 1, 14, 367, 1, 1, -863.6007080078125, -4916.2587890625, 19.7371978759765625, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+17, 202885, 1, 14, 367, 1, 1, -857.83160400390625, -4945.3056640625, 20.622039794921875, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+18, 202885, 1, 14, 367, 1, 1, -775.44268798828125, -4895.79541015625, 19.87759590148925781, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+19, 202885, 1, 14, 367, 1, 1, -834.109375, -4873.1474609375, 20.00675582885742187, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+20, 202886, 1, 14, 367, 1, 1, -736.05731201171875, -5025.12841796875, 16.79297828674316406, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 53788), -- Sen'jin Tent (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+21, 202886, 1, 14, 367, 1, 1, -738.671875, -4956.7275390625, 22.82360649108886718, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 53788), -- Sen'jin Tent (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+22, 202888, 1, 14, 367, 1, 1, -739.4375, -4957.40283203125, 22.81807136535644531, 0, 0, 0, 0, 1, 120, 255, 1, 53788), -- Sen'jin Table (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+23, 202888, 1, 14, 367, 1, 1, -736.44268798828125, -5024.7587890625, 16.54466056823730468, 0, 0, 0, 0, 1, 120, 255, 1, 53788), -- Sen'jin Table (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+24, 202889, 1, 14, 367, 1, 1, -737.08331298828125, -5024.984375, 17.58501243591308593, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 53788), -- Troll Book 1 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+25, 202889, 1, 14, 367, 1, 1, -739.15277099609375, -4958.62158203125, 23.87224769592285156, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 53788), -- Troll Book 1 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+26, 202889, 1, 14, 367, 1, 1, -735.80731201171875, -5024.63720703125, 17.64069366455078125, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 53788), -- Troll Book 1 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+27, 202890, 1, 14, 367, 1, 1, -736.21356201171875, -5025.76220703125, 17.5919647216796875, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 53788), -- Troll Book 2 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+28, 202890, 1, 14, 367, 1, 1, -739.1944580078125, -4957.1630859375, 23.85643577575683593, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 53788), -- Troll Book 2 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+29, 202890, 1, 14, 367, 1, 1, -740.05902099609375, -4958.033203125, 23.83476829528808593, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 53788), -- Troll Book 2 (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+30, 202891, 1, 14, 367, 1, 1, -742.06597900390625, -4997.02783203125, 20.31479644775390625, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+31, 202891, 1, 14, 367, 1, 1, -742.09893798828125, -4997.0712890625, 20.856292724609375, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+32, 202891, 1, 14, 367, 1, 1, -740.84552001953125, -5023.08154296875, 17.34810829162597656, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+33, 202891, 1, 14, 367, 1, 1, -743.295166015625, -4954.142578125, 22.78401565551757812, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+34, 202891, 1, 14, 367, 1, 1, -743.3125, -4954.19091796875, 23.34920692443847656, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+35, 202891, 1, 14, 367, 1, 1, -740.734375, -5022.94775390625, 16.8128814697265625, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+36, 202891, 1, 14, 367, 1, 1, -819.2586669921875, -4934.97216796875, 21.0808868408203125, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+37, 202891, 1, 14, 367, 1, 1, -806.21527099609375, -4925.30224609375, 19.99849510192871093, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+38, 202891, 1, 14, 367, 1, 1, -806.248291015625, -4925.19775390625, 19.40742683410644531, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+39, 202891, 1, 14, 367, 1, 1, -819.33160400390625, -4935, 20.47183799743652343, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 53788), -- Closed Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+40, 202892, 1, 14, 367, 1, 1, -742.08331298828125, -4997.0087890625, 21.42633628845214843, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 53788), -- Open Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+41, 202892, 1, 14, 367, 1, 1, -743.263916015625, -4954.2880859375, 23.98391151428222656, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 53788), -- Open Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+42, 202892, 1, 14, 367, 1, 1, -819.3819580078125, -4934.984375, 21.64498519897460937, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 53788), -- Open Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+43, 202892, 1, 14, 367, 1, 1, -740.93231201171875, -5023.298828125, 17.89151954650878906, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 53788), -- Open Weapon Crate (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+44, 202893, 1, 14, 367, 1, 1, -735.27777099609375, -5033.16162109375, 27.61154556274414062, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+45, 202893, 1, 14, 367, 1, 1, -744.3194580078125, -5021.3837890625, 27.21346473693847656, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+46, 202893, 1, 14, 367, 1, 1, -737.88543701171875, -4964.8037109375, 33.65756607055664062, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+47, 202893, 1, 14, 367, 1, 1, -784.77081298828125, -4942.91845703125, 55.81523895263671875, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+48, 202893, 1, 14, 367, 1, 1, -746.888916015625, -4953.02978515625, 33.657257080078125, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+49, 202893, 1, 14, 367, 1, 1, -736.49481201171875, -5024.7412109375, 32.87637710571289062, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+50, 202893, 1, 14, 367, 1, 1, -729.47393798828125, -5019.7431640625, 27.53687858581542968, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+51, 202893, 1, 14, 367, 1, 1, -739.0625, -4956.28662109375, 39.07462310791015625, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+52, 202893, 1, 14, 367, 1, 1, -732.10418701171875, -4951.34033203125, 33.59527969360351562, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+53, 202893, 1, 14, 367, 1, 1, -775.2899169921875, -4910.6943359375, 32.34464645385742187, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+54, 202893, 1, 14, 367, 1, 1, -842.765625, -4939.8994140625, 33.59177017211914062, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+55, 202893, 1, 14, 367, 1, 1, -802.77081298828125, -4915.736328125, 29.89216423034667968, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+56, 202893, 1, 14, 367, 1, 1, -835.0399169921875, -4898.42724609375, 30.94986343383789062, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
(@OGUID+57, 202893, 1, 14, 367, 1, 1, -802.79864501953125, -4896.53662109375, 30.40306663513183593, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 53788), -- Sen'jin Pennant (Area: Sen'jin Village - Difficulty: 0) CreateObject1
-- Echo Isles
(@OGUID+58, 180434, 1, 14, 368, 1, 1, -791.4913330078125, -5353.0537109375, 3.100693941116333007, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 53788), -- Bonfire (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+59, 186865, 1, 14, 368, 1, 1, -797.97393798828125, -5349.142578125, 2.206597089767456054, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 53788); -- Amani Drum (Area: Echo Isles - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+154;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17),
(@EVENT, @CGUID+18),
(@EVENT, @CGUID+19),
(@EVENT, @CGUID+20),
(@EVENT, @CGUID+21),
(@EVENT, @CGUID+22),
(@EVENT, @CGUID+23),
(@EVENT, @CGUID+24),
(@EVENT, @CGUID+25),
(@EVENT, @CGUID+26),
(@EVENT, @CGUID+27),
(@EVENT, @CGUID+28),
(@EVENT, @CGUID+29),
(@EVENT, @CGUID+30),
(@EVENT, @CGUID+31),
(@EVENT, @CGUID+32),
(@EVENT, @CGUID+33),
(@EVENT, @CGUID+34),
(@EVENT, @CGUID+35),
(@EVENT, @CGUID+36),
(@EVENT, @CGUID+37),
(@EVENT, @CGUID+38),
(@EVENT, @CGUID+39),
(@EVENT, @CGUID+40),
(@EVENT, @CGUID+41),
(@EVENT, @CGUID+42),
(@EVENT, @CGUID+43),
(@EVENT, @CGUID+44),
(@EVENT, @CGUID+45),
(@EVENT, @CGUID+46),
(@EVENT, @CGUID+47),
(@EVENT, @CGUID+48),
(@EVENT, @CGUID+49),
(@EVENT, @CGUID+50),
(@EVENT, @CGUID+51),
(@EVENT, @CGUID+52),
(@EVENT, @CGUID+53),
(@EVENT, @CGUID+54),
(@EVENT, @CGUID+55),
(@EVENT, @CGUID+56),
(@EVENT, @CGUID+57),
(@EVENT, @CGUID+58),
(@EVENT, @CGUID+59),
(@EVENT, @CGUID+60),
(@EVENT, @CGUID+61),
(@EVENT, @CGUID+62),
(@EVENT, @CGUID+63),
(@EVENT, @CGUID+64),
(@EVENT, @CGUID+65),
(@EVENT, @CGUID+66),
(@EVENT, @CGUID+67),
(@EVENT, @CGUID+68),
(@EVENT, @CGUID+69),
(@EVENT, @CGUID+70),
(@EVENT, @CGUID+71),
(@EVENT, @CGUID+72),
(@EVENT, @CGUID+73),
(@EVENT, @CGUID+74),
(@EVENT, @CGUID+75),
(@EVENT, @CGUID+76),
(@EVENT, @CGUID+77),
(@EVENT, @CGUID+78),
(@EVENT, @CGUID+79),
(@EVENT, @CGUID+80),
(@EVENT, @CGUID+81),
(@EVENT, @CGUID+82),
(@EVENT, @CGUID+83),
(@EVENT, @CGUID+84),
(@EVENT, @CGUID+85),
(@EVENT, @CGUID+86),
(@EVENT, @CGUID+87),
(@EVENT, @CGUID+88),
(@EVENT, @CGUID+89),
(@EVENT, @CGUID+90),
(@EVENT, @CGUID+91),
(@EVENT, @CGUID+92),
(@EVENT, @CGUID+93),
(@EVENT, @CGUID+94),
(@EVENT, @CGUID+95),
(@EVENT, @CGUID+96),
(@EVENT, @CGUID+97),
(@EVENT, @CGUID+98),
(@EVENT, @CGUID+99),
(@EVENT, @CGUID+100),
(@EVENT, @CGUID+101),
(@EVENT, @CGUID+102),
(@EVENT, @CGUID+103),
(@EVENT, @CGUID+104),
(@EVENT, @CGUID+105),
(@EVENT, @CGUID+106),
(@EVENT, @CGUID+107),
(@EVENT, @CGUID+108),
(@EVENT, @CGUID+109),
(@EVENT, @CGUID+110),
(@EVENT, @CGUID+111),
(@EVENT, @CGUID+112),
(@EVENT, @CGUID+113),
(@EVENT, @CGUID+114),
(@EVENT, @CGUID+115),
(@EVENT, @CGUID+116),
(@EVENT, @CGUID+117),
(@EVENT, @CGUID+118),
(@EVENT, @CGUID+119),
(@EVENT, @CGUID+120),
(@EVENT, @CGUID+121),
(@EVENT, @CGUID+122),
(@EVENT, @CGUID+123),
(@EVENT, @CGUID+124),
(@EVENT, @CGUID+125),
(@EVENT, @CGUID+126),
(@EVENT, @CGUID+127),
(@EVENT, @CGUID+128),
(@EVENT, @CGUID+129),
(@EVENT, @CGUID+130),
(@EVENT, @CGUID+131),
(@EVENT, @CGUID+132),
(@EVENT, @CGUID+133),
(@EVENT, @CGUID+134),
(@EVENT, @CGUID+135),
(@EVENT, @CGUID+136),
(@EVENT, @CGUID+137),
(@EVENT, @CGUID+138),
(@EVENT, @CGUID+139),
(@EVENT, @CGUID+140),
(@EVENT, @CGUID+141),
(@EVENT, @CGUID+142),
(@EVENT, @CGUID+143),
(@EVENT, @CGUID+144),
(@EVENT, @CGUID+145),
(@EVENT, @CGUID+146),
(@EVENT, @CGUID+147),
(@EVENT, @CGUID+148),
(@EVENT, @CGUID+149),
(@EVENT, @CGUID+150),
(@EVENT, @CGUID+151),
(@EVENT, @CGUID+152),
(@EVENT, @CGUID+153),
(@EVENT, @CGUID+154);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42),
(@EVENT, @OGUID+43),
(@EVENT, @OGUID+44),
(@EVENT, @OGUID+45),
(@EVENT, @OGUID+46),
(@EVENT, @OGUID+47),
(@EVENT, @OGUID+48),
(@EVENT, @OGUID+49),
(@EVENT, @OGUID+50),
(@EVENT, @OGUID+51),
(@EVENT, @OGUID+52),
(@EVENT, @OGUID+53),
(@EVENT, @OGUID+54),
(@EVENT, @OGUID+55),
(@EVENT, @OGUID+56),
(@EVENT, @OGUID+57),
(@EVENT, @OGUID+58),
(@EVENT, @OGUID+59);
