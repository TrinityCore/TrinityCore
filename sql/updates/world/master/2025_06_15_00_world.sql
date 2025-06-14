SET @CGUID := 4000758;

-- Areatrigger 7736
DELETE FROM `areatrigger_scripts` WHERE `entry`=7736;
INSERT INTO `areatrigger_scripts` VALUES
(7736, 'SmartTrigger');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=30 AND `SourceGroup`=0 AND `SourceEntry`=7736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30, 0, 7736, 0, 0, 47, 0, 29420, 2, 0, 0, 0, 0, '', 'Areatrigger 7736 only triggers when quest 29420 is taken'),
(30, 0, 7736, 0, 0, 1, 0, 92571, 0, 0, 1, 0, 0, '', 'Areatrigger 7736 only triggers when player has not aura 92571');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=59626;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32, 5, 59626, 0, 0, 47, 0, 29420, 2, 0, '', 0, 0, 0, '', 'Flame Spout gets visible if Quest: 29420 is completed');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=7736 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7736, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 92571, 2, 19, 60176, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast CSA Area Trigger Dummy Timer Aura');

DELETE FROM `smart_scripts` WHERE `entryorguid`=60176 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60176, 0, 0, 0, 31, 0, 100, 0, 92571, 0, 1000, 1000, 0, '', 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Huojin Monk - On Spellhit Target - Talk');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 59626 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5962600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(59626, 0, 0, 1, 1, 0, 100, 0, 3000, 10000, 30000, 50000, 0, 85, 114686, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - OOC - Cast Flame Spout'),
(59626, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 5962600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Update - Run Script'),
(5962600, 9, 0, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 0, 85, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Cast Flame Spout damage');

-- Phases
UPDATE `gameobject` SET `PhaseId`=504 WHERE `guid` IN (300154, 300152, 300149); -- Fire Wall
UPDATE `creature` SET `PhaseId`=504 WHERE `guid` = 450605; -- Master Li Fei

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id`=114684;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(114684, 'spell_flame_spout');

DELETE FROM `spell_area` WHERE `spell`=102399 AND `area`=5849;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(102399, 5849, 0, 29423, 0, 0, 2, 3, 0, 9);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=60176;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(60176, 0, 0, 'The fire spirit is upset. It\'s dangerous to enter the shrine now...', 12, 0, 100, 396, 0, 0, 59680, 0, 'Huojin Monk to Player');

-- Creature
UPDATE `creature_template` SET `unit_flags`=33555200, `AIName`='SmartAI' WHERE `entry`=59626; -- 59626 (Flame Spout) - Flame Spout
UPDATE `creature_template_addon` SET `auras`='96112' WHERE `entry`=59626; -- 59626 (Flame Spout) - Shrink
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=60176;
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55461 WHERE (`Entry`=59626 AND `DifficultyID`=0); -- 59626 (Flame Spout) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=60176 AND `DifficultyID`=0); -- 60176 (Huojin Monk) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=54135 AND `DifficultyID`=0); -- 54135 (Master Li Fei) - CanSwim

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 59626, 860, 5736, 5849, '0', 0, 0, 0, 0, 1393.7691650390625, 3900.11279296875, 101.0790328979492187, 1.522577166557312011, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461); -- Flame Spout (Area: Shrine of Inner-Light - Difficulty: 0) CreateObject1

-- Quest
UPDATE `quest_template_locale` SET `LogTitle`='Más fuerte que el junco', `LogDescription`='Reúne 8 juncos parteleños duros.', `QuestDescription`='Reúne juncos de las charcas cercanas.$B$BNo preguntes por qué. Hazlo y observa los resultados.', `VerifiedBuild`=55461 WHERE (`ID`=29662 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='El guardián del espíritu', `QuestDescription`='Por ahora te ha ido bien, $gdiscípulo:discípula;. Ya tienes el material necesario para avivar a Huo, el espíritu del fuego.$b$bTe espera en la cueva que hay al suroeste, pero está custodiado por el maestro Li Fei, el anciano pandaren al que conociste en la Cueva de Meditación. Lleva estas ofrendas al maestro Li Fei. Demuestra tu valía y luego reúnete con Huo.', `VerifiedBuild`=55461 WHERE (`ID`=29420 AND `locale`='esES');
UPDATE `quest_template_locale` SET `VerifiedBuild`=55461 WHERE (`locale`='esES' AND `ID` IN (46736,46735,46277));
UPDATE `quest_template_locale` SET `LogDescription`='Obtén una brisa batiente.', `QuestDescription`='El viento es algo curioso: resulta muy difícil aferrarlo con las manos.$b$bLa mejor forma de practicar es encontrar algún tipo de aire viviente. Si él puede atizarte, tú también podrás atizarle a él sin que se te escurra entre los dedos.$b$bDirígete al Santuario de la Brisa Estival e invoca a un aire viviente con esta piedra de viento. Véncelo, recoge una brisa batiente y vuelve para que decidamos qué hacer a continuación.', `VerifiedBuild`=55461 WHERE (`ID`=29523 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='Leña al fuego', `LogDescription`='Reúne 5 raíces de cornejo secas.', `QuestDescription`='Ahora que nos hemos encargado de eso, ¡vamos a lo que importa!$b$bHuo, el espíritu del fuego, desea raíces de cornejo secas. Se encuentran entre los árboles, al sur de la aldea. No te costará nada reunir unas cuantas.', `VerifiedBuild`=55461 WHERE (`ID`=29418 AND `locale`='esES');

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (29418,29523,29420));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(29418, 'esES', '¡$n! ¡Has vuelto con raíces y todo! Eres $gun tipo:una tipa; eficiente, ¿verdad? ¡Me gusta!', 55461),
(29523, 'esES', 'Tú sí que sabes aprovechar una oportunidad. Creo que somos almas gemelas, $n.', 55461),
(29420, 'esES', 'El objetivo de la vida no es encontrarse a uno mismo: es crearse a uno mismo. Un camino se extiende ante ti, pero eres tú quien debe elegir las pruebas a las que te enfrentarás... y las pruebas que superarás.', 55461);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esES' AND `ID` IN (29418,29523));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(29418, 'esES', 'Espero que no te importe ensuciarte las manos.', 55461),
(29523, 'esES', 'Cuando se presenta la oportunidad, es responsabilidad nuestra extender la mano y atraparla. Dudar equivale a rendirse.', 55461);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=59626;
