SET @OGUID := 4000000;

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 210015, 860, 5736, 5834, '0', 593, 0, 1420.93994140625, 3457.3701171875, 171.18499755859375, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 53441); -- Weapon Rack (Area: Shang Xi Training Grounds - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (57873,53714)); -- Training Target
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (54587,65471)); -- Tushui Trainee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (65469,53565)); -- Aspiring Trainee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (54586,65470)); -- Huojin Trainee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=53584 WHERE (`Entry`=53566 AND `DifficultyID`=0); -- Master Shang Xi

-- Creatures
UPDATE `creature` SET `spawntimesecs` = 5, `curhealth` = 623 WHERE `id` = 57873;
UPDATE `creature` SET `spawntimesecs` = 20, `curhealth` = 623 WHERE `id` = 53714;

UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` IN (57873, 53714);

DELETE FROM `creature_template_sparring` WHERE `Entry`=57873 AND `NoNPCDamageBelowHealthPct` = 85;
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(57873, 85);

DELETE FROM `creature_text` WHERE `CreatureID` IN (65469, 53565) AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(65469, 0, 0, 'One day you will have to teach me your secrets.', 12, 0, 100, 507, 0, 33646, 56432, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 1, 'You are bound for a great things, trainee.', 12, 0, 100, 507, 0, 33643, 56435, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 2, 'That target didn\'t stand a chance.', 12, 0, 100, 509, 0, 33643, 56433, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 3, 'I hope the instructors saw that!', 12, 0, 100, 0, 0, 33646, 56434, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 4, 'Such skill for a new trainee.', 12, 0, 100, 509, 0, 33643, 56431, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 5, 'I must train harder so I can be like you.', 12, 0, 100, 509, 0, 33645, 56437, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 6, 'Your form is impeccable.', 12, 0, 100, 511, 0, 33643, 56430, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 0, 'One day you will have to teach me your secrets.', 12, 0, 100, 507, 0, 33646, 56432, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 1, 'You are bound for a great things, trainee.', 12, 0, 100, 507, 0, 33643, 56435, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 2, 'That target didn\'t stand a chance.', 12, 0, 100, 509, 0, 33643, 56433, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 3, 'I hope the instructors saw that!', 12, 0, 100, 0, 0, 33646, 56434, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 4, 'Such skill for a new trainee.', 12, 0, 100, 509, 0, 33643, 56431, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 5, 'I must train harder so I can be like you.', 12, 0, 100, 509, 0, 33645, 56437, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 6, 'Your form is impeccable.', 12, 0, 100, 511, 0, 33643, 56430, 0, 'Aspiring Trainee to Training Target');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=108967 AND `ConditionValue1`=3 AND `ConditionValue2`=53714;

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (53714, 5774800, 45019200, -450228, -450215, -450213, -450207, -450197);

DELETE FROM `smart_scripts` WHERE `entryorguid`=57873 AND `source_type`=0 AND `id` IN (0, 1, 2, 3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57873, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Training Target - On Reset - Set Reactstate Passive'),
(57873, 0, 1, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '',  45, 1, 1, 0, 0, 0, 0, 0, 11, 53565, 4, 0, 0, 0, 0, 0, 0, 'Training Target - On Just Died - Set Data 1 1'),
(57873, 0, 2, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '',  45, 1, 1, 0, 0, 0, 0, 0, 11, 65469, 4, 0, 0, 0, 0, 0, 0, 'Training Target - On Just Died - Set Data 1 1'),
(57873, 0, 3, 0, '', 60, 0, 100, 0, 0, 0, 1000, 6000, 0, '', 45, 1, 2, 0, 0, 0, 0, 0, 11, 53565, 4, 0, 0, 0, 0, 0, 0, 'Training Target - On Update - Set Data 1 2'),
(57873, 0, 4, 0, '', 60, 0, 100, 0, 0, 0, 1000, 6000, 0, '', 45, 1, 2, 0, 0, 0, 0, 0, 11, 65469, 4, 0, 0, 0, 0, 0, 0, 'Training Target - On Update - Set Data 1 2');

DELETE FROM `smart_scripts` WHERE `entryorguid`=53565 AND `source_type`=0 AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(53565, 0, 0, 0, '', 38, 0, 100, 0, 1, 1, 0, 0, 0, '', 80, 5356500, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Aspiring Trainee - On Data Set 1 1 - Run Script'),
(53565, 0, 1, 0, '', 38, 0, 100, 0, 1, 2, 0, 0, 0, '', 80, 5356501, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Aspiring Trainee - On Data Set 1 2 - Run Script');

DELETE FROM `smart_scripts` WHERE `entryorguid`=65469 AND `source_type`=0 AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(65469, 0, 0, 0, '', 38, 0, 100, 0, 1, 1, 0, 0, 0, '', 80, 5356500, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Aspiring Trainee - On Data Set 1 1 - Run Script'),
(65469, 0, 1, 0, '', 38, 0, 100, 0, 1, 2, 0, 0, 0, '', 80, 5356501, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Aspiring Trainee - On Data Set 1 2 - Run Script');

DELETE FROM `smart_scripts` WHERE `entryorguid`=5356500 AND `source_type`=9 AND `id` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5356500, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, 19, 57873, 5, 0, 0, 0, 0, 0, 0, 'On Script - Say random creature Text - to Training Target');

DELETE FROM `smart_scripts` WHERE `entryorguid`=5356501 AND `source_type`=9 AND `id` IN (0, 1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5356501, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 10, 509, 543, 511, 507, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Actionlist - Self: Play random emote: 509, 543, 511, 507'),
(5356501, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 115, 33646, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Actionlist - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all'),
(5356501, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 108967, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Actionlist - Self: Cast spell 108967');

-- Quests
UPDATE `quest_template_locale` SET `LogTitle`='El reto de los discípulos', `QuestDescription`='Veo una gran fuerza y un gran valor en ti, $n, además de una pureza de alma incomparable.$b$bAún es pronto, pero creo que estás $glisto:lista; para enfrentarte a un desafío mayor.$b$bBaja por las escaleras y cruza el puente. Allí te encontrarás con Jaomin Ro, uno de nuestros pupilos más veteranos. Desafíalo y derrótalo en un combate honorable y la primera fase de tu adiestramiento habrá concluido.', `VerifiedBuild`=53441 WHERE (`ID`=29409 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='La lección del pergamino ardiente', `LogDescription`='Quítale la llama de la mano al maestro Shang Xi y luego prende fuego al edicto de templanza.', `QuestDescription`='Toda sabiduría tiene un momento y un lugar. Soplan vientos de cambio para los habitantes de Shen-zin Su. Para esta lección te pediré dos cosas.$b$bPrimero: sostengo una llama en la mano. Prepárate y, cuando creas estar $glisto:lista;, intenta quitármela.$b$bSi lo consigues, quiero que subas a lo alto de este templo y quemes el edicto de templanza que encontrarás allí.', `VerifiedBuild`=53441 WHERE (`ID`=29408 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='La lección del orgullo herido', `QuestDescription`='Enfrentarse a un oponente vivo es muy distinto a los objetivos estáticos del patio. Los oponentes vivos devuelven los golpes. El miedo al fracaso, e incluso a la muerte, es muy real.$b$bDebes tener el valor de superar ese miedo.$b$bReta a los demás alumnos que hay en el templo o en las escaleras, y derrótalos.', `VerifiedBuild`=53441 WHERE (`ID`=29524 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='La lección del puño de arena', `QuestDescription`='Me gustaría verte utilizar tu nueva arma, joven $gdiscípulo:discípula;. Me ayudará a decidir qué grado de entrenamiento será el más adecuado para tu talento.$B$BEn los campos de entrenamiento hay gran cantidad de objetivos de entrenamiento. Practica tus ataques con ellos y ven a verme cuando te sientas $gcómodo:cómoda; con tu nueva arma.', `VerifiedBuild`=53441 WHERE (`ID`=29406 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='La lección de la rama de acero', `QuestDescription`='Antes de nada, te harán falta armas adecuadas para tu talento. Coge una hoja de hechizo y un abanico de mano de uno de los expositores que hay abajo, tráemelo y demuéstrame que sabes sostenerlo como es debido.', `VerifiedBuild`=53441 WHERE (`ID`=30033 AND `locale`='esES');

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=53441 WHERE (`locale`='esES' AND `ID` IN (252375,252345,254896,252339,269435,253307,437689));
UPDATE `quest_objectives_locale` SET `Description`='Quítale la llama al maestro', `VerifiedBuild`=53441 WHERE (`ID`=252344 AND `locale`='esES');

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (29408,29524,29406,30033));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(29408, 'esES', 'Es una proeza que hayas conseguido quitarme la llama con tanta facilidad.$B$BEl edicto de templanza es un pergamino de sabiduría que mis antepasados heredaron generación tras generación. Es una sabiduría proveniente de una época más pacífica.$B$BCada lección pertenece a un momento y a un lugar; con la oscuridad en el horizonte, el tiempo de esta sabiduría toca a su fin.$B$BQuemar el pergamino es aceptar lo que está por llegar y comprometerse a pasar a la acción. Tu mano porta la llama, y creo que la seguirá portando en el futuro.', 53441),
(29524, 'esES', 'Interesante, mi joven $gdiscípulo:discípula;.$b$bLa mayoría de los alumnos llevan bastante tiempo con nosotros, pero tú has conseguido igualarlos en tu primera hora.$b$bEso dice mucho en tu favor, pero hay más lecciones que quiero que aprendas.', 53441),
(29406, 'esES', 'No está mal, $n. Es posible que hayas elegido bien tu destino.$b$b¡Muy bien! Prosigamos.', 53441),
(30033, 'esES', 'Un arma magnífica. Se adecuará a tus necesidades.$b$bVamos a darle uso.', 53441);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esES' AND `ID` IN (29408,29524,29406,30033, 29409));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(29408, 'esES', 'Llegará un día en el que tendrás que confiar en tu instinto y actuar sin dilación.', 53441),
(29524, 'esES', 'Hay un tiempo para la meditación y la reflexión y un tiempo para la acción. Encontrar el equilibrio entre los dos es la mayor sabiduría a la que aspiramos.', 53441),
(29406, 'esES', 'Los objetivos de entrenamiento están a los pies de la colina. Ven a verme cuando hayas terminado.', 53441),
(30033, 'esES', 'Empuñar tu primera arma es un gesto simbólico. Cada $c que sale de estos campos de entrenamiento debe estar $gpreparado:preparada; para tomar las armas en defensa de todos los pandaren.', 53441),
(29409, 'esES', 'Nuestra mayor gloria no radica en no caernos nunca, sino en levantarnos cada vez que nos caemos. Jaomin Ro lo sabe. Cada derrota le da fuerzas.$b$bTodavía puedes aprender esa lección.', 53441);

DELETE FROM `quest_request_items` WHERE `ID`=30033;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(30033, 0, 1, 0, 0, 'Picking up your first weapon is also a symbolic gesture. Every $c that leaves these training grounds must be ready to take up arms in defense of their fellow pandaren.', 20886); -- The Lesson of the Iron Bough
