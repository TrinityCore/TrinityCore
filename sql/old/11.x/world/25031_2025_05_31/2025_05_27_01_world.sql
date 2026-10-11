SET @OGUID := 6001354;
SET @CGUID := 6000670;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 93967, 1220, 7334, 7620, '0', 5049, 0, 0, 0, 274.848968505859375, 5872.89599609375, 15.98129177093505859, 3.646122217178344726, 120, 10, 0, 100, 0, NULL, NULL, NULL, NULL, 54604); -- Lyndras (Area: The Greenway - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 242633, 1220, 7502, 8415, '0', 5081, 0, -768.82989501953125, 4582.134765625, 728.8717041015625, 4.839252471923828125, 0.360172748565673828, 0.46509552001953125, -0.51393032073974609, 0.624369561672210693, 120, 255, 1, 54604), -- Tanithria's Silkweave (Area: Talismanic Textiles - Difficulty: 0) CreateObject1
(@OGUID+1, 242634, 1220, 7502, 8415, '0', 5085, 0, -773.86981201171875, 4579.12939453125, 728.70819091796875, 4.022988319396972656, 0, 0, -0.90445423126220703, 0.426570683717727661, 120, 255, 1, 54604); -- Tanithria's Thread (Area: Talismanic Textiles - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (242633, 242634);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(242633, 0, 2113536, 0, 0), -- Tanithria's Silkweave
(242634, 0, 2113536, 0, 0); -- Tanithria's Thread

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=54604 WHERE `entry`=242634; -- Tanithria's Thread
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=54604 WHERE `entry`=242633; -- Tanithria's Silkweave

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=331, `StaticFlags1`=268435456, `VerifiedBuild`=54604 WHERE (`Entry`=93967 AND `DifficultyID`=0); -- Lyndras

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (5081, 5085, 5049);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5081, 'Cosmetic - See Tanithria\'s Silkweave - Legion Tailoring'),
(5085, 'Cosmetic - See Tanithria\'s Thread - Legion Tailoring'),
(5049, 'Cosmetic - See Lyndras at Lyndras Exile');

DELETE FROM `phase_area` WHERE `PhaseId` IN (5081, 5085, 5049);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8415, 5081, 'Tanithria\'s Silkweave - Legion Tailoring'),
(8415, 5085, 'Tanithria\'s Thread - Legion Tailoring'),
(7620, 5049, 'Lyndras at Lyndras Exile'),
(8418, 5049, 'See Lyndras at Lyndras Exile');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (5081, 5085);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5081, 0, 0, 0, 47, 0, 38945, 2 | 8, 0, 0, 'Apply Phase 5081 if Quest 38945 is in progress | completed'),
(26, 5085, 0, 0, 0, 47, 0, 38945, 2 | 8, 0, 0, 'Apply Phase 5085 if Quest 38945 is in progress | completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5049;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5049, 0, 0, 0, 47, 0, 38946, 2 | 64, 0, 0, 'Apply Phase 5049 if Quest 38946 is completed | rewarded'),
(26, 5049, 0, 0, 1, 47, 0, 38950, 2 | 64, 1, 0, 'Apply Phase 5049 if Quest 37733 is not completed | rewarded');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`=93967;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93967, 0, 0, 'This simply will not do. I MUST find better accommodations.', 12, 0, 50, 0, 0, 0, 98225, 0, 'Lyndras'),
(93967, 0, 1, 'Maybe if I explain that I was just borrowing it, they\'ll have me back. No, no, no! Tytallo would never go for that.', 12, 0, 50, 0, 0, 0, 98227, 0, 'Lyndras'),
(93967, 1, 0, 'Let\'s see, did I remember the spritethorn needles...?', 12, 0, 50, 0, 0, 0, 98219, 0, 'Lyndras'),
(93967, 1, 1, 'One... two... three, four... yes. They\'re all here.', 12, 0, 50, 0, 0, 0, 98221, 0, 'Lyndras');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=93967 AND `MenuID`=18502);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(93967, 18502, 54604); -- Lyndras

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (38945 /*This Should Be Simple... Right?*/, 38944 /*Sew It Begins*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38945, 1, 0, 0, 0, 0, 0, 0, 0, 54604), -- This Should Be Simple... Right?
(38944, 1, 0, 0, 0, 0, 0, 0, 0, 54604); -- Sew It Begins

DELETE FROM `creature_queststarter` WHERE (`id`=93967 AND `quest` IN (38950,38949,38948,38947)) OR (`id`=93542 AND `quest` IN (38945,38944)) OR (`id`=114274 AND `quest`=44544);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(93967, 38950, 54604), -- The Wayward Tailor offered by Lyndras
(93967, 38949, 54604), -- So You Think You Can Sew offered by Lyndras
(93967, 38948, 54604), -- Hard Times offered by Lyndras
(93967, 38947, 54604), -- Runic Catgut offered by Lyndras
(93542, 38945, 54604), -- This Should Be Simple... Right? offered by Tanithria
(93542, 38944, 54604); -- Sew It Begins offered by Tanithria

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (38946, 38945,38944));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(38946, 'esES', '¡Vaya, vaya, mírate! $gUn:Una; joven $c tan $gatractivo:atractiva;, y $gtodo adornado:toda adornada; con sus armas y sus galas mágicas. ¿A qué debo el placer?$B$B¡Ajá! ¡Sastrería! Es tu día de suerte, esto...$B$BDisculpa, ¿cómo te llamabas? ¿$n?$B$B¡Es tu día de suerte, $n! Resulta que soy uno de los mejores sastres de Suramar...', 54604),
(38945, 'esES', 'Qué pena. Sin la posibilidad de coser, apenas podemos hacer nada con este tejido.$B$B<Tanithria hace un mohín.>$B$BAun así, EXISTEN patrones para los que sabemos que no hace falta coser. Las hombreras son fáciles, y los cinturones deberían de estar chupados.', 54604),
(38944, 'esES', 'Con esto... ¡Con esto sí que puedo trabajar!$B$BMe recuerda a una tela de un viejo festival de elfos de la noche.', 54604);

DELETE FROM `quest_request_items_locale` WHERE (`ID`=38944 AND `locale`='esES');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(38944, 'esES', 'No me importaría trabajar con un poco de cachemir...', 54604);

UPDATE `quest_template_locale` SET `LogTitle`='Esto no debería ser complicado... ¿no?', `LogDescription`='Fabrica una toga de filoseda hecha a mano en el banco de retoques de Tanithria. Puedes conseguir el patrón en tu lista de patrones de sastrería, y los materiales del patrón, en su tienda.', `QuestDescription`='Tengo muchos patrones de seda con los que podemos usar esta tela.$B$BAyúdame a preparar los materiales, $n. Le daremos un buen uso a esta tela y te haremos una toga nueva.', `VerifiedBuild`=54604 WHERE (`ID`=38945 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='Consulta a los lugareños', `QuestDescription`='El que tejió esto NO PUEDE haberlo hecho solamente para cinturones y hombreras. Debe de haber una forma de coser este material.$B$BBaja a Azsuna y busca un sastre. Necesitamos coser si queremos hacer algo de sastrería en serio.', `VerifiedBuild`=54604 WHERE (`ID`=38946 AND `locale`='esES');

-- Lyndras Ai
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 93967;
DELETE FROM `smart_scripts` WHERE `entryorguid`= -(@CGUID+0) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (9396700, 9396701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+0), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 0, '', 80, 9396700, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - on movement inform, point 1 - start Action List'),
(-(@CGUID+0), 0, 1, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 0, '', 80, 9396701, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - on movement inform, point 3 - start Action List'),
(9396700, 9, 0, 1, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Set Flag Standstate Kneel'),
(9396700, 9, 1, 2, '', 0, 0, 100, 0, 3000, 10000, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Talk'),
(9396700, 9, 2, 0, '', 0, 0, 100, 0, 115000, 115000, 0, 0, 0, '', 91, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Remove Flag Standstate Kneel'),
(9396701, 9, 0, 1, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 17, 569, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Set Emotestate 569'),
(9396701, 9, 1, 2, '', 0, 0, 100, 0, 3000, 10000, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Talk'),
(9396701, 9, 2, 0, '', 0, 0, 100, 0, 113000, 113000, 0, 0, 0, '', 17, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lyndras - On Script - Remove Emotestate');

-- Path for Lyndras
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 93967;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Lyndras - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 277.316, 5875.141, 15.98129, NULL, 0),
(@PATH, 1, 274.849, 5872.896, 15.98129, NULL, 121894),
(@PATH, 2, 287.7274, 5877.945, 15.98129, NULL, 0),
(@PATH, 3, 290.7188, 5877.89, 15.98129, NULL, 120626);

UPDATE `creature` SET `position_x`= 277.316, `position_y`= 5875.141, `position_z`= 15.98129, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
