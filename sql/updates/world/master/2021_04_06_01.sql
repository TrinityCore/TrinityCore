-- DB update 2021_04_06_00 -> 2021_04_06_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_00 2021_04_06_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617676322351034500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617676322351034500');

-- 4512 Un largo camino para unas babosas
-- https://es.classic.wowhead.com/quest=4512
SET @ID := 4512;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algunos de los experimentos que he realizado son fascinantes. Creo que con un poco más de trabajo, podré descubrir la naturaleza de estas criaturas y cómo influyen en el desarrollo de la vida en Azeroth ... si es que tienen algo que ver con eso para empezar.$B$BUna de mis teorías más grandes que no gusta mucho es la idea de que los mocos y los lodos están vinculados a la creación de este planeta... casi como si fueran una secreción de él.$B$BPero no puedo probarlo ni refutarlo hasta que obtenga más muestras.', 0),
(@ID, 'esMX', 'Algunos de los experimentos que he realizado son fascinantes. Creo que con un poco más de trabajo, podré descubrir la naturaleza de estas criaturas y cómo influyen en el desarrollo de la vida en Azeroth ... si es que tienen algo que ver con eso para empezar.$B$BUna de mis teorías más grandes que no gusta mucho es la idea de que los mocos y los lodos están vinculados a la creación de este planeta... casi como si fueran una secreción de él.$B$BPero no puedo probarlo ni refutarlo hasta que obtenga más muestras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Resultados asombrosos, $n! ¡Te acercaste lo suficiente para tomar una muestra de los mocos corruptos y te las arreglaste para no lucir peor por el desgaste! Gracias. Oh, estas muestras serán perfectas. No puedo esperar para comenzar a probarlos.$B$BSi estoy en lo cierto, ¡podría ser uno de los más grandes científicos de la Liga de Exploradores!$B$BEso demostrará a todos los enanos que no fue un error permitirnos entrar a los gnomos en Forjaz después del incidente de Gnomeregan.', 0),
(@ID, 'esMX', '¡Resultados asombrosos, $n! ¡Te acercaste lo suficiente para tomar una muestra de los mocos corruptos y te las arreglaste para no lucir peor por el desgaste! Gracias. Oh, estas muestras serán perfectas. No puedo esperar para comenzar a probarlos.$B$BSi estoy en lo cierto, ¡podría ser uno de los más grandes científicos de la Liga de Exploradores!$B$BEso demostrará a todos los enanos que no fue un error permitirnos entrar a los gnomos en Forjaz después del incidente de Gnomeregan.', 0);
-- 4513 Un largo camino para unas babosas
-- https://es.classic.wowhead.com/quest=4513
SET @ID := 4513;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay tanto que tener en cuenta. Pero ¿qué significa? ¿Y cómo afecta a las gentes de Azeroth?', 0),
(@ID, 'esMX', 'Hay tanto que tener en cuenta. Pero ¿qué significa? ¿Y cómo afecta a las gentes de Azeroth?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes la muestra? $n, vales tu peso en oro. Tu dedicación y tu ayuda han sido magníficas.$B$BAcepta esto en prueba de mi imperecedera gratitud. Ahora tengo cosas que hacer, pero si vienes más adelante tendré más trabajo para ti.$B$BGracias de todo corazón.', 0),
(@ID, 'esMX', '¿Me traes la muestra? $n, vales tu peso en oro. Tu dedicación y tu ayuda han sido magníficas.$B$BAcepta esto en prueba de mi imperecedera gratitud. Ahora tengo cosas que hacer, pero si vienes más adelante tendré más trabajo para ti.$B$BGracias de todo corazón.', 0);
-- 725 Advertir de la amenaza
-- https://es.classic.wowhead.com/quest=725
SET @ID := 725;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hmm? Sí, $c.', 0),
(@ID, 'esMX', '¿Hmm? Sí, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una nota del historiador Karnik. Excelente.$B$BSiempre tengo tiempo para sus negocios.$B$B<El consejero Belgrum abre la nota y comienza a leer.>', 0),
(@ID, 'esMX', 'Ah, una nota del historiador Karnik. Excelente.$B$BSiempre tengo tiempo para sus negocios.$B$B<El consejero Belgrum abre la nota y comienza a leer.>', 0);
-- 726 Advertir de la amenaza
-- https://es.classic.wowhead.com/quest=726
SET @ID := 726;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás tratando este asunto con la urgencia que esperaría del propio rey, $N.$B$BDe acuerdo entonces. Sé lo que hará caer a los Forjatinieblas.$B$BSu presencia en Uldaman puede ralentizarse si los atacamos en su base de operaciones: la Fortaleza de Angor.', 0),
(@ID, 'esMX', 'Estás tratando este asunto con la urgencia que esperaría del propio rey, $N.$B$BDe acuerdo entonces. Sé lo que hará caer a los Forjatinieblas.$B$BSu presencia en Uldaman puede ralentizarse si los atacamos en su base de operaciones: la Fortaleza de Angor.', 0);
-- 762 Un embajador del mal
-- https://es.classic.wowhead.com/quest=762
SET @ID := 762;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es esencial, $n. Ragnaros no esperará a que nos preparemos.', 0),
(@ID, 'esMX', 'El tiempo es esencial, $n. Ragnaros no esperará a que nos preparemos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, tu dedicación a Forjaz y al pueblo enano no puede ser refutada. Te agradezco tu ayuda en este asunto.$B$BEnviaré un mensaje al historiador Karnik para informarle de que lo ha logrado y también haré que se envíe ayuda a las Tierras Inhóspitas lo antes posible para ayudar a recuperar el sitio de excavación. Gracias de nuevo.$B$BAntes de que te vayas, hay una cosa más que te pediría en nombre del Rey Barbabronce.', 0),
(@ID, 'esMX', '$n, tu dedicación a Forjaz y al pueblo enano no puede ser refutada. Te agradezco tu ayuda en este asunto.$B$BEnviaré un mensaje al historiador Karnik para informarle de que lo ha logrado y también haré que se envíe ayuda a las Tierras Inhóspitas lo antes posible para ayudar a recuperar el sitio de excavación. Gracias de nuevo.$B$BAntes de que te vayas, hay una cosa más que te pediría en nombre del Rey Barbabronce.', 0);
-- 1139 Las tablillas perdidas de Voluntad
-- https://es.classic.wowhead.com/quest=1139
SET @ID := 1139;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La búsqueda de Piemartillo debe continuar, $n. Le debo mucho.$B$BTu regreso a Uldaman es imperativo no solo para ese objetivo, sino también para la seguridad de todos los enanos. Con la tablilla en manos de los Forjatiniebla, quién sabe lo poderoso que se volvería su ejército de golems.', 0),
(@ID, 'esMX', 'La búsqueda de Piemartillo debe continuar, $n. Le debo mucho.$B$BTu regreso a Uldaman es imperativo no solo para ese objetivo, sino también para la seguridad de todos los enanos. Con la tablilla en manos de los Forjatiniebla, quién sabe lo poderoso que se volvería su ejército de golems.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El consejero Belgrum sacude la cabeza con incredulidad mientras le entregas el fragmento de piedra.>$B$B$n, esto es asombroso. Haré que se lo lleven a los magos del rey lo antes posible. Querrán estudiarlo para averiguar si las leyendas son ciertas. Pero esa es una discusión para otro momento: has ayudado a nuestra gente más de lo que hubiera esperado, gracias.', 0),
(@ID, 'esMX', '<El consejero Belgrum sacude la cabeza con incredulidad mientras le entregas el fragmento de piedra.>$B$B$n, esto es asombroso. Haré que se lo lleven a los magos del rey lo antes posible. Querrán estudiarlo para averiguar si las leyendas son ciertas. Pero esa es una discusión para otro momento: has ayudado a nuestra gente más de lo que hubiera esperado, gracias.', 0);
-- 1450 Maestro de grifos Garracha
-- https://es.classic.wowhead.com/quest=1450
SET @ID := 1450;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Por supuesto, recuerdo haber enviado a uno de mis jinetes de grifos para que le echara una mano a Brohann Barriliga.$B$BSiempre tuve una debilidad en mi corazón por la Liga de Exploradores. Mi padre ayudó con el equipo de excavación inicial que descubrió Uldaman.$B$BEnvié a quien pensé que era mi mejor jinete de grifos en ese momento con Brohann. Era un tipo llamado Rapsodio Machacacanillas.$B$B¡Y qué jinete de grifos era! Bueno hasta ...', 0),
(@ID, 'esMX', 'Ah, sí. Por supuesto, recuerdo haber enviado a uno de mis jinetes de grifos para que le echara una mano a Brohann Barriliga.$B$BSiempre tuve una debilidad en mi corazón por la Liga de Exploradores. Mi padre ayudó con el equipo de excavación inicial que descubrió Uldaman.$B$BEnvié a quien pensé que era mi mejor jinete de grifos en ese momento con Brohann. Era un tipo llamado Rapsodio Machacacanillas.$B$B¡Y qué jinete de grifos era! Bueno hasta ...', 0);
-- 1451 Rapsodio Machacacanillas
-- https://es.classic.wowhead.com/quest=1451
SET @ID := 1451;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip!$B$BTe estoy mirando y no paras de moverte. Tás mareándome. ¡Jo, jo!$B$B¡Hip!$B$B¡Guau! ¿Lo has sentido? La tierra se mueve, $gamigo:amiga;. Necesito una copa.$B$B¡Hip!', 0),
(@ID, 'esMX', '¡Hip!$B$BTe estoy mirando y no paras de moverte. Tás mareándome. ¡Jo, jo!$B$B¡Hip!$B$B¡Guau! ¿Lo has sentido? La tierra se mueve, $gamigo:amiga;. Necesito una copa.$B$B¡Hip!', 0);
-- 900 El churumbele
-- https://es.classic.wowhead.com/quest=900
SET @ID := 900;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilotos parpadeantes en la consola de control indican que aún no se han cerrado las principales válvulas de control.', 0),
(@ID, 'esMX', 'Los pilotos parpadeantes en la consola de control indican que aún no se han cerrado las principales válvulas de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las luces de las tres válvulas de control se apagan al cortarlas. Las luces verdes se vuelven poco a poco amarillas y el interruptor que controla el aparato puede ahora extraerse con las válvulas cerradas; se puede apagar.', 0),
(@ID, 'esMX', 'Las luces de las tres válvulas de control se apagan al cortarlas. Las luces verdes se vuelven poco a poco amarillas y el interruptor que controla el aparato puede ahora extraerse con las válvulas cerradas; se puede apagar.', 0);
-- 901 El churumbele
-- https://es.classic.wowhead.com/quest=901
SET @ID := 901;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilotos de la consola están atenuados y los diales están todos a cero, todo está parado.', 0),
(@ID, 'esMX', 'Los pilotos de la consola están atenuados y los diales están todos a cero, todo está parado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al girar la llave en la cerradura, la consola de control queda libre. Se apaga una luz roja en la parte superior de la consola y no queda corriente en el terminal.', 0),
(@ID, 'esMX', 'Al girar la llave en la cerradura, la consola de control queda libre. Se apaga una luz roja en la parte superior de la consola y no queda corriente en el terminal.', 0);
-- 902 El churumbele
-- https://es.classic.wowhead.com/quest=902
SET @ID := 902;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, has vuelto, $n! ¿Tienes el churumbele?', 0),
(@ID, 'esMX', '¡Eh, has vuelto, $n! ¿Tienes el churumbele?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es… interesante, vaya. Me ocuparé de que lo envíen al puesto de mando del Gremio de Manitas de Villabajo. Estoy seguro de que después de desarmar el aparato con cuidado y estudiarlo, conseguiré entender cómo funciona.', 0),
(@ID, 'esMX', 'Esto es… interesante, vaya. Me ocuparé de que lo envíen al puesto de mando del Gremio de Manitas de Villabajo. Estoy seguro de que después de desarmar el aparato con cuidado y estudiarlo, conseguiré entender cómo funciona.', 0);
-- 4502 Actividad volcánica
-- https://es.classic.wowhead.com/quest=4502
SET @ID := 4502;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es cierto que el volcán de Un\'Goro está activo? Creo que podría aprender mucho de las cenizas, $n.', 0),
(@ID, 'esMX', '¿Es cierto que el volcán de Un\'Goro está activo? Creo que podría aprender mucho de las cenizas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas muestras son perfectas! ¡Gracias, $n! Te informaré con detalle de todo lo que averigüe.', 0),
(@ID, 'esMX', '¡Estas muestras son perfectas! ¡Gracias, $n! Te informaré con detalle de todo lo que averigüe.', 0);
-- 1091 Noticias para Kaela
-- https://es.classic.wowhead.com/quest=1091
SET @ID := 1091;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy interesante.$B$BGaxim y tú lo habéis hecho muy bien, $n. Gracias.', 0),
(@ID, 'esMX', 'Esto es muy interesante.$B$BGaxim y tú lo habéis hecho muy bien, $n. Gracias.', 0);
-- 1084 Los antárboles corruptos
-- https://es.classic.wowhead.com/quest=1084
SET @ID := 1084;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo el presentimiento de que Gaxim sabrá cómo utilizar la metralla sin tener en cuenta cómo la ha usado Ventura y Cía. en el pasado.', 0),
(@ID, 'esMX', 'Tengo el presentimiento de que Gaxim sabrá cómo utilizar la metralla sin tener en cuenta cómo la ha usado Ventura y Cía. en el pasado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BEsto debería ser más que suficiente para que Gaxim descubra cómo fueron corrompidos los antárboles. Se lo daré ahora mismo.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BEsto debería ser más que suficiente para que Gaxim descubra cómo fueron corrompidos los antárboles. Se lo daré ahora mismo.', 0);
-- 1083 Los espíritus iracundos
-- https://es.classic.wowhead.com/quest=1083
SET @ID := 1083;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera vez que vi La Vega Carbonizada, casi lloro, $n.', 0),
(@ID, 'esMX', 'La primera vez que vi La Vega Carbonizada, casi lloro, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los restos de nuestro enemigo... tu fuerza nos hace un gran servicio, $n. Gracias.', 0),
(@ID, 'esMX', 'Los restos de nuestro enemigo... tu fuerza nos hace un gran servicio, $n. Gracias.', 0);
-- 1093 Súper Segadora 6000
-- https://es.classic.wowhead.com/quest=1093
SET @ID := 1093;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado esos planos? Quiero impresionar al nuevo jefe. Con suerte, cuando esté convencido de mi lealtad, bueno... todo lo que pueda estar convencido... El honor de los goblins y todo eso, ¿sabes? Pues eso, que cuando esté convencido, querrá utilizar mi impresionante genialidad.', 0),
(@ID, 'esMX', '¿Has encontrado esos planos? Quiero impresionar al nuevo jefe. Con suerte, cuando esté convencido de mi lealtad, bueno... todo lo que pueda estar convencido... El honor de los goblins y todo eso, ¿sabes? Pues eso, que cuando esté convencido, querrá utilizar mi impresionante genialidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, ¿es eso lo que creo que es? ¡Genial!$B$BVeamos. ¡Agh! ¿Cómo se supone que voy a entender esto...? No sé cómo piensan los gnomos. Te diré algo, me sorprende que consiguieran construir la rueda y mucho menos esas máquinas voladores que tanto les gustan.', 0),
(@ID, 'esMX', 'Eh, ¿es eso lo que creo que es? ¡Genial!$B$BVeamos. ¡Agh! ¿Cómo se supone que voy a entender esto...? No sé cómo piensan los gnomos. Te diré algo, me sorprende que consiguieran construir la rueda y mucho menos esas máquinas voladores que tanto les gustan.', 0);
-- 1094 Más instrucciones
-- https://es.classic.wowhead.com/quest=1094
SET @ID := 1094;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Cómo puedo ayudarte?', 0),
(@ID, 'esMX', '¡Hola! ¿Cómo puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fizziks, ¿eh? No es que confíe mucho en él, pero su información parece bastante fiable. ¿Qué no daría porque me quitaran de encima a Ventura y Cía.?$B$BAunque inventan buenas máquinas... No puedo negar que nos hemos beneficiado de algunos de los artefactos que han desarrollado.', 0),
(@ID, 'esMX', 'Fizziks, ¿eh? No es que confíe mucho en él, pero su información parece bastante fiable. ¿Qué no daría porque me quitaran de encima a Ventura y Cía.?$B$BAunque inventan buenas máquinas... No puedo negar que nos hemos beneficiado de algunos de los artefactos que han desarrollado.', 0);
-- 1095 Más instrucciones
-- https://es.classic.wowhead.com/quest=1095
SET @ID := 1095;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eliminar a Gerenzo? Vaya, esa es una idea a la que no me opondría.$B$BLos gnomos ya son bastante malos pero lo que sé sobre Gerenzo, no hace más que empeorar las cosas. Al parecer, era uno de los ingenieros jefe en Gnomeregan, donde trabajaba en un proyecto secreto; no logramos infiltrar a Dun Morogh para averiguar más detalles concretos. Fue un fracaso. Según nuestros informes, fuera lo que fuera, les explotó literalmente en la cara.', 0),
(@ID, 'esMX', '¿Eliminar a Gerenzo? Vaya, esa es una idea a la que no me opondría.$B$BLos gnomos ya son bastante malos pero lo que sé sobre Gerenzo, no hace más que empeorar las cosas. Al parecer, era uno de los ingenieros jefe en Gnomeregan, donde trabajaba en un proyecto secreto; no logramos infiltrar a Dun Morogh para averiguar más detalles concretos. Fue un fracaso. Según nuestros informes, fuera lo que fuera, les explotó literalmente en la cara.', 0);
-- 1096 Gerenzo Silbillave
-- https://es.classic.wowhead.com/quest=1096
SET @ID := 1096;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Petardol querrá alguna prueba de que Gerenzo está muerto. Creo que este brazo mecánico servirá.', 0),
(@ID, 'esMX', 'Petardol querrá alguna prueba de que Gerenzo está muerto. Creo que este brazo mecánico servirá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira eso... se necesita un gnomo para inventarse algo así. No puedo comprender por qué alguien querría cortarse un brazo y reemplazarlo con eso cuando puedes quedarte con ambos brazos y añadir un tercero.$B$B¡Gnomos!...$B$BAl menos Gerenzo ha pasado a la historia. Esperemos que eso sea suficiente para demostrarlo y que Petardol me asigne a uno de los talleres del Gremio de Manitas en Gadgetzan o quizás incluso en Villabajo.', 0),
(@ID, 'esMX', 'Mira eso... se necesita un gnomo para inventarse algo así. No puedo comprender por qué alguien querría cortarse un brazo y reemplazarlo con eso cuando puedes quedarte con ambos brazos y añadir un tercero.$B$B¡Gnomos!...$B$BAl menos Gerenzo ha pasado a la historia. Esperemos que eso sea suficiente para demostrarlo y que Petardol me asigne a uno de los talleres del Gremio de Manitas en Gadgetzan o quizás incluso en Villabajo.', 0);
-- 1082 Noticias para Centinela Thenysil
-- https://es.classic.wowhead.com/quest=1082
SET @ID := 1082;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Has hecho un gran servicio a las Centinelas.$B$BMe alegro mucho de ver que Kaela... e incluso Gaxim, están bien.$B$BTe has ganado nuestro aprecio.', 0),
(@ID, 'esMX', 'Gracias, $n. Has hecho un gran servicio a las Centinelas.$B$BMe alegro mucho de ver que Kaela... e incluso Gaxim, están bien.$B$BTe has ganado nuestro aprecio.', 0);
-- 1081 El recibimiento de Tyrande
-- https://es.classic.wowhead.com/quest=1081
SET @ID := 1081;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. He oído tu nombre y, aunque sigues siendo muy joven, me alegra ver el camino que has decidido seguir.$B$BMe harías un gran honor si quisieras aceptar esto como muestra de aprecio.', 0),
(@ID, 'esMX', 'Hola, $n. He oído tu nombre y, aunque sigues siendo muy joven, me alegra ver el camino que has decidido seguir.$B$BMe harías un gran honor si quisieras aceptar esto como muestra de aprecio.', 0);

-- 5821 Guardaespaldas de alquiler
-- https://es.classic.wowhead.com/quest=5821
SET @ID := 5821;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué sigo esperando esa maldita caravana?$B$B<Smeed parece iluminado.>$B$BOh, sí, ellos pagan las facturas. ¿Los has visto?', 0),
(@ID, 'esMX', '¿Por qué sigo esperando esa maldita caravana?$B$B<Smeed parece iluminado.>$B$BOh, sí, ellos pagan las facturas. ¿Los has visto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes, no parece rentable pagarle a gente como tú para proteger la caravana Gizelton. $c, si fuera un poco más alto, podría aceptar un segundo trabajo y sentarme con el arma más grande que mis manos pudieran llevar... y les mostraría a los malditos centauros quién es su papito.', 0),
(@ID, 'esMX', 'Sabes, no parece rentable pagarle a gente como tú para proteger la caravana Gizelton. $c, si fuera un poco más alto, podría aceptar un segundo trabajo y sentarme con el arma más grande que mis manos pudieran llevar... y les mostraría a los malditos centauros quién es su papito.', 0);
-- 5943 La caravana Gizelton
-- https://es.classic.wowhead.com/quest=5943
SET @ID := 5943;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes, si esa caravana desapareciera alguna vez, ¡estaría arruinado! No eres portador de malas noticias sobre la caravana, ¿verdad?$B$B<Smeed se seca el sudor de la frente.>$B$B¡Gracias a la diosa de la codicia!', 0),
(@ID, 'esMX', 'Sabes, si esa caravana desapareciera alguna vez, ¡estaría arruinado! No eres portador de malas noticias sobre la caravana, ¿verdad?$B$B<Smeed se seca el sudor de la frente.>$B$B¡Gracias a la diosa de la codicia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé yo si es una propuesta propicia pagar tanto dinero para proteger la caravana Gizelton. Cork y Rigger solo se sacan una moneda de oro a la semana, pero mientras me paguen los kodos, tampoco es que me importe un carajo cómo lleven su negocio.', 0),
(@ID, 'esMX', 'No sé yo si es una propuesta propicia pagar tanto dinero para proteger la caravana Gizelton. Cork y Rigger solo se sacan una moneda de oro a la semana, pero mientras me paguen los kodos, tampoco es que me importe un carajo cómo lleven su negocio.', 0);
-- 1114 Un envío para los gnomos
-- https://es.classic.wowhead.com/quest=1114
SET @ID := 1114;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí? ¡Genial! A ver, a ver...', 0),
(@ID, 'esMX', '¿Tienes algo para mí? ¡Genial! A ver, a ver...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí están los hidrotrinquetes y las ballestas! Son perfectos. ¡Gracias!', 0),
(@ID, 'esMX', '¡Aquí están los hidrotrinquetes y las ballestas! Son perfectos. ¡Gracias!', 0);
-- 1115 Rumores
-- https://es.classic.wowhead.com/quest=1115
SET @ID := 1115;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Preguntas por Nazz Vaporio? Es un piloto de carreras en El Desierto de Sal, ¿no?$B$BSí, puede que averigüe algo sobre él, pero no será fácil. Ni rápido...', 0),
(@ID, 'esMX', '¿Preguntas por Nazz Vaporio? Es un piloto de carreras en El Desierto de Sal, ¿no?$B$BSí, puede que averigüe algo sobre él, pero no será fácil. Ni rápido...', 0);
-- 1186 El piloto nº18
-- https://es.classic.wowhead.com/quest=1186
SET @ID := 1186;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú eres quien ha estado ayudando a Pozzik, ¿verdad? Yo antes era como tú; andaba vagando por los boxes y ayudando a los mecánicos en lo que podía.$B$B¡Y mírame ahora! ¡Soy el piloto del equipo de carreras de los goblins!', 0),
(@ID, 'esMX', 'Tú eres quien ha estado ayudando a Pozzik, ¿verdad? Yo antes era como tú; andaba vagando por los boxes y ayudando a los mecánicos en lo que podía.$B$B¡Y mírame ahora! ¡Soy el piloto del equipo de carreras de los goblins!', 0);
-- 1190 Mantener la velocidad
-- https://es.classic.wowhead.com/quest=1190
SET @ID := 1190;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un pergamino de notas y diseños que explican el proceso de refinado de un material, garabateados con mala letra.', 0),
(@ID, 'esMX', 'Un pergamino de notas y diseños que explican el proceso de refinado de un material, garabateados con mala letra.', 0);
-- 1187 Los ajustes de Razzeric
-- https://es.classic.wowhead.com/quest=1187
SET @ID := 1187;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo voy a participar en la carrera sin contar con un pequeño empujoncito? ¡Haría el ridículo!', 0),
(@ID, 'esMX', '¿Cómo voy a participar en la carrera sin contar con un pequeño empujoncito? ¡Haría el ridículo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mira esta belleza! ¡Siete kilos de potencia de seforio macizo! Cuando se lo ponga a mi coche, iré tan rápido por la pista... ¡que adelantaré a los gnomos dos veces!', 0),
(@ID, 'esMX', '¡Mira esta belleza! ¡Siete kilos de potencia de seforio macizo! Cuando se lo ponga a mi coche, iré tan rápido por la pista... ¡que adelantaré a los gnomos dos veces!', 0);
-- 1191 La distracción de Zamek
-- https://es.classic.wowhead.com/quest=1191
SET @ID := 1191;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vamos!', 0),
(@ID, 'esMX', '¡Vamos!', 0);
-- 1194 Los esquemas de Rizzle
-- https://es.classic.wowhead.com/quest=1194
SET @ID := 1194;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Indurio? Interesante... Si tiene una resistencia al calor tan alta como dices, eso podría explicar la mejora en los resultados experimentada por los gnomos.$B$BAdemás, esta muestra que me has traído tiene un valor incalculable. Podré hacer algunas pruebas con ella pero necesitaré más para poder sacarle partido.', 0),
(@ID, 'esMX', '¿Indurio? Interesante... Si tiene una resistencia al calor tan alta como dices, eso podría explicar la mejora en los resultados experimentada por los gnomos.$B$BAdemás, esta muestra que me has traído tiene un valor incalculable. Podré hacer algunas pruebas con ella pero necesitaré más para poder sacarle partido.', 0);
-- 1192 Mena de indurio
-- https://es.classic.wowhead.com/quest=1192
SET @ID := 1192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustaría usar indurio en diferentes partes de nuestros diseños, pero necesito grandes cantidades de mineral de indurio para crear estas partes.$B$BPuedes encontrar mineral de indurio en la excavación de Uldaman en Tierras Inhóspitas, al otro lado del mar en Khaz Modan.$B$BLos gnomos están obteniendo su propio suministro, por lo que es importante que tengamos el nuestro para seguirles el ritmo.', 0),
(@ID, 'esMX', 'Me gustaría usar indurio en diferentes partes de nuestros diseños, pero necesito grandes cantidades de mineral de indurio para crear estas partes.$B$BPuedes encontrar mineral de indurio en la excavación de Uldaman en Tierras Inhóspitas, al otro lado del mar en Khaz Modan.$B$BLos gnomos están obteniendo su propio suministro, por lo que es importante que tengamos el nuestro para seguirles el ritmo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Haré que el equipo trabaje de inmediato en las piezas que usaremos para la próxima carrera.', 0),
(@ID, 'esMX', '¡Excelente! Haré que el equipo trabaje de inmediato en las piezas que usaremos para la próxima carrera.', 0);
-- 1188 La seguridad primero
-- https://es.classic.wowhead.com/quest=1188
SET @ID := 1188;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Seguro que ya sabes que en la Cacharrería podrás encontrar todo lo que necesites! ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¡Seguro que ya sabes que en la Cacharrería podrás encontrar todo lo que necesites! ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Razzeric es el único que podría echar un vistazo a esto y decir que de algún modo le he puesto un seguro. ¡Este propulsor es seforio puro! Lo modifiqué para que suelte la mayor parte de la carga explosiva pero Razzeric siempre quiere más. ¡Quiere que vaya a tope!', 0),
(@ID, 'esMX', 'Razzeric es el único que podría echar un vistazo a esto y decir que de algún modo le he puesto un seguro. ¡Este propulsor es seforio puro! Lo modifiqué para que suelte la mayor parte de la carga explosiva pero Razzeric siempre quiere más. ¡Quiere que vaya a tope!', 0);
-- 1189 La seguridad primero
-- https://es.classic.wowhead.com/quest=1189
SET @ID := 1189;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedes creer que Pozzik puso un cubo de arena en el coche? ¿Cómo se supone que voy a llegar al máximo de velocidad con un cubo de arena bajo el asiento?', 0),
(@ID, 'esMX', '¿Puedes creer que Pozzik puso un cubo de arena en el coche? ¿Cómo se supone que voy a llegar al máximo de velocidad con un cubo de arena bajo el asiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto está mejor! Me gustaría ver la cara que pondrán los gnomos cuando me vean pasar a la velocidad del rayo con esta belleza.$B$B¡Pero estaré demasiado ocupado batiendo un nuevo récord!', 0),
(@ID, 'esMX', '¡Esto está mejor! Me gustaría ver la cara que pondrán los gnomos cuando me vean pasar a la velocidad del rayo con esta belleza.$B$B¡Pero estaré demasiado ocupado batiendo un nuevo récord!', 0);
-- 2865 Caparazones de escarabajo
-- https://es.classic.wowhead.com/quest=2865
SET @ID := 2865;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los caparazones? Mi primo de Bahía del Botín sigue esperando el cargamento, ¡y se está impacientando!', 0),
(@ID, 'esMX', '¿Tienes los caparazones? Mi primo de Bahía del Botín sigue esperando el cargamento, ¡y se está impacientando!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, genial! ¡Los conseguiste!$B$BGracias, $n. ¡Eres $gun:una; $gauténtico:auténtica; salvavidas!', 0),
(@ID, 'esMX', '¡Oh, genial! ¡Los conseguiste!$B$BGracias, $n. ¡Eres $gun:una; $gauténtico:auténtica; salvavidas!', 0);
-- 3362 El Valle Cardizal
-- https://es.classic.wowhead.com/quest=3362
SET @ID := 3362;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustaría echar un vistazo más de cerca a ese cactus en el valle... Así que deja alguno de una pieza, ¿quieres?', 0),
(@ID, 'esMX', 'Me gustaría echar un vistazo más de cerca a ese cactus en el valle... Así que deja alguno de una pieza, ¿quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sabía que eran tan grandes. Creo que tengo que perfeccionar mi plan...$B$BPero tú has cumplido con tu parte, así que aquí tienes lo que te prometí.', 0),
(@ID, 'esMX', 'No sabía que eran tan grandes. Creo que tengo que perfeccionar mi plan...$B$BPero tú has cumplido con tu parte, así que aquí tienes lo que te prometí.', 0);
-- 4504 Superpegajoso
-- https://es.classic.wowhead.com/quest=4504
SET @ID := 4504;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tran\'rek lo ha vuelto a conseguir. ¡Este pegamento superpegajoso hará furor!', 0),
(@ID, 'esMX', 'Tran\'rek lo ha vuelto a conseguir. ¡Este pegamento superpegajoso hará furor!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este alquitrán es genial...$B$B¡Eh, espera un segundo! Mis manos... están pegadas...$B$BQuizás no haya sido tan buena idea. ¡Ah, eso es! ¡Quita-alquitrán superpegajoso! ¡Ahí es donde está el dinero!', 0),
(@ID, 'esMX', 'Sí, este alquitrán es genial...$B$B¡Eh, espera un segundo! Mis manos... están pegadas...$B$BQuizás no haya sido tan buena idea. ¡Ah, eso es! ¡Quita-alquitrán superpegajoso! ¡Ahí es donde está el dinero!', 0);
-- 2781 SE BUSCA: Califa Escorpijón
-- https://es.classic.wowhead.com/quest=2781
SET @ID := 2781;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí $c, yo soy un oficial de la compañía de aguas de Gadgetzan. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Sí $c, yo soy un oficial de la compañía de aguas de Gadgetzan. ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin se ha hecho justicia! ¡Has asestado un duro golpe a esos infames nómadas! La muerte de Escorpijón será clave para expulsar finalmente a los que se están aprovechando de los pozos de agua de Gadgetzan.$B$BPor la autoridad que me confiere la compañía de aguas de Gadgetzan, te hago entrega de tu recompensa. Nos has prestado un gran servicio a todos nosotros.', 0),
(@ID, 'esMX', '¡Al fin se ha hecho justicia! ¡Has asestado un duro golpe a esos infames nómadas! La muerte de Escorpijón será clave para expulsar finalmente a los que se están aprovechando de los pozos de agua de Gadgetzan.$B$BPor la autoridad que me confiere la compañía de aguas de Gadgetzan, te hago entrega de tu recompensa. Nos has prestado un gran servicio a todos nosotros.', 0);
-- 2875 SE BUSCA: Andre Barbafuego
-- https://es.classic.wowhead.com/quest=2875
SET @ID := 2875;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces un tanto aturdido. ¿Has estado leyendo nuestros documentos legales?', 0),
(@ID, 'esMX', 'Pareces un tanto aturdido. ¿Has estado leyendo nuestros documentos legales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la cabeza de Andre! ¡Supongo que al final recibió su merecido!$B$BMuchas gracias, $n. Y ahora si me firmas aquí, te pagaré por los servicios prestados.$B$BNo te preocupes por la letra pequeña, no pone nada interesante y... de todos modos, no creo que exista una lupa lo suficientemente buena como para poder leerla.', 0),
(@ID, 'esMX', '¡Ah, la cabeza de Andre! ¡Supongo que al final recibió su merecido!$B$BMuchas gracias, $n. Y ahora si me firmas aquí, te pagaré por los servicios prestados.$B$BNo te preocupes por la letra pequeña, no pone nada interesante y... de todos modos, no creo que exista una lupa lo suficientemente buena como para poder leerla.', 0);
-- 1707 Cazador de faltriqueras de agua
-- https://es.classic.wowhead.com/quest=1707
SET @ID := 1707;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes las faltriqueras de agua de los Deambuladores que necesitamos? ¡Si es así, entonces recibirás el paquete modelo 103-XB de la compañía de aguas de Gadgetzan!', 0),
(@ID, 'esMX', '¿Ya tienes las faltriqueras de agua de los Deambuladores que necesitamos? ¡Si es así, entonces recibirás el paquete modelo 103-XB de la compañía de aguas de Gadgetzan!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0),
(@ID, 'esMX', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0);
-- 1690 Justicia para los Vagayermos
-- https://es.classic.wowhead.com/quest=1690
SET @ID := 1690;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? ¡Espero que hayas podido hacer justicia al estilo goblin a esos bandidos y ladrones Vagayermos como te pedí!', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? ¡Espero que hayas podido hacer justicia al estilo goblin a esos bandidos y ladrones Vagayermos como te pedí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A eso le llamo yo ser eficiente! Has acabado con tantos nómadas que ya se dibuja la posibilidad de recuperar nuestros pozos de agua.$B$BLa compañía de aguas de Gadgetzan te agradece tu inestimable ayuda, aunque todavía queda mucho trabajo que hacer con estos nómadas. Escucha atentamente, esto lo próximo que necesitamos que hagas...', 0),
(@ID, 'esMX', '¡A eso le llamo yo ser eficiente! Has acabado con tantos nómadas que ya se dibuja la posibilidad de recuperar nuestros pozos de agua.$B$BLa compañía de aguas de Gadgetzan te agradece tu inestimable ayuda, aunque todavía queda mucho trabajo que hacer con estos nómadas. Escucha atentamente, esto lo próximo que necesitamos que hagas...', 0);
-- 2768 Vara divinomática
-- https://es.classic.wowhead.com/quest=2768
SET @ID := 2768;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste al sargento Bly? ¿Tienes mi Vara Divinomática?', 0),
(@ID, 'esMX', '¿Encontraste al sargento Bly? ¿Tienes mi Vara Divinomática?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo encontraste! ¡Bien hecho, $n! ¿Tuviste que luchar con Bly para conseguirlo? Espero que le dieras bien fuerte a él y a toda su banda.', 0),
(@ID, 'esMX', '¡Lo encontraste! ¡Bien hecho, $n! ¿Tuviste que luchar con Bly para conseguirlo? Espero que le dieras bien fuerte a él y a toda su banda.', 0);
-- 2605 El goblin sediento
-- https://es.classic.wowhead.com/quest=2605
SET @ID := 2605;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, dime que has encontrado a los colectores de rocío.', 0),
(@ID, 'esMX', 'Por favor, dime que has encontrado a los colectores de rocío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, maravilloso! ¡Trae, me lo voy a beber!', 0),
(@ID, 'esMX', '¡Oh, maravilloso! ¡Trae, me lo voy a beber!', 0);

-- 3042 Temple trol
-- https://es.classic.wowhead.com/quest=3042
SET @ID := 3042;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído el temple, $n?', 0),
(@ID, 'esMX', '¿Has traído el temple, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, es un temple excelente! ¡Y hay mucho! ¡Podré trabajar muchos días antes de que se acabe!$B$BGracias, $n. Por favor, acepta esto como pago.', 0),
(@ID, 'esMX', '¡Ah, es un temple excelente! ¡Y hay mucho! ¡Podré trabajar muchos días antes de que se acabe!$B$BGracias, $n. Por favor, acepta esto como pago.', 0);
-- 992 Un estudio de agua de Gadgetzan
-- https://es.classic.wowhead.com/quest=992
SET @ID := 992;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gBienvenido:Bienvenida; de nuevo, $gperito:perita; adjunta $n! ¿Ya has terminado tu tarea?', 0),
(@ID, 'esMX', '¡$gBienvenido:Bienvenida; de nuevo, $gperito:perita; adjunta $n! ¿Ya has terminado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo? ¿Te han tendido una emboscada una especie de bichejos de mojo malo? Vaya, esto no augura nada bueno para la compañía de aguas de Gadgetzan...$B$BSupongo que tenía que haberte hablado de los peligrosos bichos que al parecer están consumiendo toda el agua del desierto. Al principio, le resté importancia pues ya tenemos bastantes problemas con los nómadas y creí que era una más de sus artimañas. Al menos ahora sabemos lo que está pasando.', 0),
(@ID, 'esMX', '¿Cómo? ¿Te han tendido una emboscada una especie de bichejos de mojo malo? Vaya, esto no augura nada bueno para la compañía de aguas de Gadgetzan...$B$BSupongo que tenía que haberte hablado de los peligrosos bichos que al parecer están consumiendo toda el agua del desierto. Al principio, le resté importancia pues ya tenemos bastantes problemas con los nómadas y creí que era una más de sus artimañas. Al menos ahora sabemos lo que está pasando.', 0);
-- 3022 Un envío frágil
-- https://es.classic.wowhead.com/quest=3022
SET @ID := 3022;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro envío de parte de Curgle, ¿verdad?', 0),
(@ID, 'esMX', 'Otro envío de parte de Curgle, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. La población de hiprogrifos no crecería de no ser por nosotros. Pero seguro que eso ya lo sabes pues has estado en Feralas y has visto con tus propios ojos la devastación causada por los Gordunni.$B$BBien, como puedes observar, tengo mucho trabajo así que será mejor que te vayas.$B$BGracias de nuevo, $n.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. La población de hiprogrifos no crecería de no ser por nosotros. Pero seguro que eso ya lo sabes pues has estado en Feralas y has visto con tus propios ojos la devastación causada por los Gordunni.$B$BBien, como puedes observar, tengo mucho trabajo así que será mejor que te vayas.$B$BGracias de nuevo, $n.', 0);
-- 2741 El Superhuevomático
-- https://es.classic.wowhead.com/quest=2741
SET @ID := 2741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0),
(@ID, 'esMX', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0),
(@ID, 'esMX', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0);
-- 5863 La Base Machacaduna
-- https://es.classic.wowhead.com/quest=5863
SET @ID := 5863;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estoy tan preocupada! ¡Por favor ten cuidado!', 0),
(@ID, 'esMX', '¡Estoy tan preocupada! ¡Por favor ten cuidado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me alegro de que hayas podido hacer esto por mí, $n! ¡Gracias por tu ayuda!', 0),
(@ID, 'esMX', '¡Me alegro de que hayas podido hacer esto por mí, $n! ¡Gracias por tu ayuda!', 0);
-- 1691 Más justicia para los Vagayermos
-- https://es.classic.wowhead.com/quest=1691
SET @ID := 1691;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿pudiste eliminar a esos nómadas como te pedí? ¡La Compañia de Aguas de Gadgetzan está desarrollando planes basados en tu éxito aquí! No nos defraudes, ahora...', 0),
(@ID, 'esMX', 'Bueno, ¿pudiste eliminar a esos nómadas como te pedí? ¡La Compañia de Aguas de Gadgetzan está desarrollando planes basados en tu éxito aquí! No nos defraudes, ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera, $n... ¡de primera! ¡Has reducido la población de los nómadas hasta tal punto que ya podemos hacerles frente!$B$BSi todavía no lo has hecho, ve a hablar con el grifoperador Luglunket que está aquí. Él te dará una recompensa por cada una de las bolsas de agua de los Vagayermos que hayas encontrado mientras impartías justicia a esos nómadas.', 0),
(@ID, 'esMX', 'Un trabajo de primera, $n... ¡de primera! ¡Has reducido la población de los nómadas hasta tal punto que ya podemos hacerles frente!$B$BSi todavía no lo has hecho, ve a hablar con el grifoperador Luglunket que está aquí. Él te dará una recompensa por cada una de las bolsas de agua de los Vagayermos que hayas encontrado mientras impartías justicia a esos nómadas.', 0);
-- 1878 Cazador de faltriqueras de agua
-- https://es.classic.wowhead.com/quest=1878
SET @ID := 1878;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto, $n? Si tienes cinco bolsas más de agua te puedo dar ya mismo tu recompensa.', 0),
(@ID, 'esMX', '¿Ya has vuelto, $n? Si tienes cinco bolsas más de agua te puedo dar ya mismo tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0),
(@ID, 'esMX', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0);
-- 82 Investigación en la Guarida Ponzoñosa
-- https://es.classic.wowhead.com/quest=82
SET @ID := 82;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gel:la; perito $gadjunto:adjunta;, ¿no es cierto? ¡Rápido, estamos en una situación muy delicada! ¡¿Tienes los trozos de insecto que Picoflojo dijo que tendrías?!', 0),
(@ID, 'esMX', 'Eres $gel:la; perito $gadjunto:adjunta;, ¿no es cierto? ¡Rápido, estamos en una situación muy delicada! ¡¿Tienes los trozos de insecto que Picoflojo dijo que tendrías?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, ¡empezaré ahora mismo con el análisis! A primera vista, puedo decirte que no se parecen a ningún tipo de insecto que haya visto antes. Parece que estos bichos están controlados por una fuerza externa o algo similar.$B$BDebes ir a hablar con Picoflojo inmediatamente. ¡Hay algo urgente para lo que necesita tu ayuda! No estoy seguro pero creo que tiene que ver con los bichos del Desierto de Tanaris.', 0),
(@ID, 'esMX', 'Buen trabajo, ¡empezaré ahora mismo con el análisis! A primera vista, puedo decirte que no se parecen a ningún tipo de insecto que haya visto antes. Parece que estos bichos están controlados por una fuerza externa o algo similar.$B$BDebes ir a hablar con Picoflojo inmediatamente. ¡Hay algo urgente para lo que necesita tu ayuda! No estoy seguro pero creo que tiene que ver con los bichos del Desierto de Tanaris.', 0);
-- 10 La redención de Patagolpe
-- https://es.classic.wowhead.com/quest=10
SET @ID := 10;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y bien, ¿qué novedades traes? Parece que te hayan dado una paliza... ¿Patagolpe está vivo?', 0),
(@ID, 'esMX', 'Y bien, ¿qué novedades traes? Parece que te hayan dado una paliza... ¿Patagolpe está vivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El joven Patagolpe era un buen goblin. Esperemos que, gracias a los datos registrados en su equipo de análisis, su muerte no haya sido en vano.$B$BParece que ahora el problema con estos bichos está en nuestras manos. Son demasiado astutos y las investigaciones realizadas hasta el momento señalan la posibilidad de que estén controlados por una tercera persona. Si eso es cierto, ¡no le espera nada bueno ni a Gadgetzan ni al desierto en general!', 0),
(@ID, 'esMX', 'El joven Patagolpe era un buen goblin. Esperemos que, gracias a los datos registrados en su equipo de análisis, su muerte no haya sido en vano.$B$BParece que ahora el problema con estos bichos está en nuestras manos. Son demasiado astutos y las investigaciones realizadas hasta el momento señalan la posibilidad de que estén controlados por una tercera persona. Si eso es cierto, ¡no le espera nada bueno ni a Gadgetzan ni al desierto en general!', 0);
-- 2606 Un buen sabor
-- https://es.classic.wowhead.com/quest=2606
SET @ID := 2606;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que Marin está otra vez en ello, ¿eh? ¿De qué está hecho este brebaje?', 0),
(@ID, 'esMX', 'Así que Marin está otra vez en ello, ¿eh? ¿De qué está hecho este brebaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Marin es un buen tipo pero un poco excéntrico, diría yo.$B$BEn cualquier caso, está claro que necesita mi ayuda una vez más.', 0),
(@ID, 'esMX', 'Marin es un buen tipo pero un poco excéntrico, diría yo.$B$BEn cualquier caso, está claro que necesita mi ayuda una vez más.', 0);
-- 2641 El ingrediente secreto de Roxio
-- https://es.classic.wowhead.com/quest=2641
SET @ID := 2641;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El único lugar en el que encontrarás tragano violeta es bajo las aguas de ese lago. ¡Espero que tengas buenos pulmones!', 0),
(@ID, 'esMX', 'El único lugar en el que encontrarás tragano violeta es bajo las aguas de ese lago. ¡Espero que tengas buenos pulmones!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es lo que quería, $n!$B$BTiene buena pinta, a ver... ¡Ajá! ¡Perfecto!', 0),
(@ID, 'esMX', '¡Eso es lo que quería, $n!$B$BTiene buena pinta, a ver... ¡Ajá! ¡Perfecto!', 0);
-- 11441 ¡Fiesta de la Cerveza!
-- https://es.classic.wowhead.com/quest=11441
SET @ID := 11441;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Jo jo! ¿Vienes por tu cerveza gratis?', 0),
(@ID, 'esMX', 'Jo jo! ¿Vienes por tu cerveza gratis?', 0);
-- 7261 El imperativo soberano
-- https://es.classic.wowhead.com/quest=7261
SET @ID := 7261;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A trabajar!', 0),
(@ID, 'esMX', '¡A trabajar!', 0);
-- 3702 Las humeantes Ruinas de Thaurissan
-- https://es.classic.wowhead.com/quest=3702
SET @ID := 3702;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme terminar de contarte la historia de Thaurissan.', 0),
(@ID, 'esMX', 'Permíteme terminar de contarte la historia de Thaurissan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Proseguimos?', 0),
(@ID, 'esMX', '¿Proseguimos?', 0);
-- 3701 Las humeantes Ruinas de Thaurissan
-- https://es.classic.wowhead.com/quest=3701
SET @ID := 3701;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes nueva información?', 0),
(@ID, 'esMX', '¿Traes nueva información?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explica mucho sobre Thaurissan.$B$B¡Qué interesante!', 0),
(@ID, 'esMX', 'Esto explica mucho sobre Thaurissan.$B$B¡Qué interesante!', 0);
-- 12022 ¡Traga y tira!
-- https://es.classic.wowhead.com/quest=12022
SET @ID := 12022;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lanza uno hacia atrás, luego lanza uno hacia adelante. G.U.A.O. puede soportarlo, es por eso que lo construí.', 0),
(@ID, 'esMX', 'Lanza uno hacia atrás, luego lanza uno hacia adelante. G.U.A.O. puede soportarlo, es por eso que lo construí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes qué fue eso? ¡Ingeniería gnómica en su máxima expresión! G.U.A.O. lo soportó como un campeón!$B$BCreo que ya estás $glisto:lista; para enfrentarte a los Hierro Negro si vuelven a aparecer.', 0),
(@ID, 'esMX', '¿Sabes qué fue eso? ¡Ingeniería gnómica en su máxima expresión! G.U.A.O. lo soportó como un campeón!$B$BCreo que ya estás $glisto:lista; para enfrentarte a los Hierro Negro si vuelven a aparecer.', 0);
-- 11118 Elekks rosas a la vista
-- https://es.classic.wowhead.com/quest=11118
SET @ID := 11118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya se han ido esos molestos elekks rosas?', 0),
(@ID, 'esMX', '¿Ya se han ido esos molestos elekks rosas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Elekks rosas... ¡qué idea más absurda!', 0),
(@ID, 'esMX', '¡Buen trabajo! Elekks rosas... ¡qué idea más absurda!', 0);
-- 11117 ¡Atrapa al wolpertinger salvaje!
-- https://es.classic.wowhead.com/quest=11117
SET @ID := 11117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estabas lo suficientemente $gborracho:borracha; como para ver a los pequeños cabroncetes?', 0),
(@ID, 'esMX', '¿Estabas lo suficientemente $gborracho:borracha; como para ver a los pequeños cabroncetes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¡mira ahí! ¡Tienes un montón de wolpertingers, sí!$B$B<Toma un buen trago de su jarra.>$B$BTe diré lo que voy a hacer. Ya que eres $gun:una; $c tan acertado, ¡dejaré que te quedes con uno de estos para ti!', 0),
(@ID, 'esMX', 'Bueno, ¡mira ahí! ¡Tienes un montón de wolpertingers, sí!$B$B<Toma un buen trago de su jarra.>$B$BTe diré lo que voy a hacer. Ya que eres $gun:una; $c tan acertado, ¡dejaré que te quedes con uno de estos para ti!', 0);
-- 11318 Carrera de carneros... o algo parecido
-- https://es.classic.wowhead.com/quest=11318
SET @ID := 11318;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste manejar la velocidad?', 0),
(@ID, 'esMX', '¿Pudiste manejar la velocidad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Se necesita tiempo para dominar el control de tu Carnero. Pero una vez que lo hagas, desearás que cada ariete sea un ariete de carreras.$B$B¿Que es eso? "¿Dónde está mi recompensa?" Ja, ja, ja... ¡tienes que montar el carnero más rápido! ¿Quieres más? Bueno, ¿qué tal esto...$B$BHa sido recompensado con la oportunidad de ayudar a otras personas en la Fiesta de la Cerveza. Hay mucho trabajo y recompensas para un corredor joven y entusiasta.', 0),
(@ID, 'esMX', '¡Buen trabajo! Se necesita tiempo para dominar el control de tu Carnero. Pero una vez que lo hagas, desearás que cada ariete sea un ariete de carreras.$B$B¿Que es eso? "¿Dónde está mi recompensa?" Ja, ja, ja... ¡tienes que montar el carnero más rápido! ¿Quieres más? Bueno, ¿qué tal esto...$B$BHa sido recompensado con la oportunidad de ayudar a otras personas en la Fiesta de la Cerveza. Hay mucho trabajo y recompensas para un corredor joven y entusiasta.', 0);
-- 11122 Historia de una ida y una vuelta
-- https://es.classic.wowhead.com/quest=11122
SET @ID := 11122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Necesito esos barriles! ¿¡qué estás esperando!?!', 0),
(@ID, 'esMX', '¡Necesito esos barriles! ¿¡qué estás esperando!?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muchas gracias por tu ayuda! Mientras dure la Fiesta de la Cerveza y los Enanos Hierro Negro estén atacando, necesitaré ayuda para enviar barriles. Si quieres trabajar para obtener más fichas, habla conmigo todos los días.$B$BPero basta de eso, voy pagarte por el trabajo que acabas de hacer. Aquí tienes tus fichas, ¡diviértete en la Fiesta de la Cerveza!', 0),
(@ID, 'esMX', '¡Muchas gracias por tu ayuda! Mientras dure la Fiesta de la Cerveza y los Enanos Hierro Negro estén atacando, necesitaré ayuda para enviar barriles. Si quieres trabajar para obtener más fichas, habla conmigo todos los días.$B$BPero basta de eso, voy pagarte por el trabajo que acabas de hacer. Aquí tienes tus fichas, ¡diviértete en la Fiesta de la Cerveza!', 0);

-- 583 Bienvenido a la jungla
-- https://es.classic.wowhead.com/quest=583
SET @ID := 583;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0),
(@ID, 'esMX', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0);
-- 194 Domina el raptor
-- https://es.classic.wowhead.com/quest=194
SET @ID := 194;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0),
(@ID, 'esMX', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', 'Un trabajo magistral, $gamigo:amiga;.', 0);
-- 185 Domina el tigre
-- https://es.classic.wowhead.com/quest=185
SET @ID := 185;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0),
(@ID, 'esMX', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Puedes seguir adelante.', 0),
(@ID, 'esMX', 'Muy bien, $n. Puedes seguir adelante.', 0);
-- 190 Domina la pantera
-- https://es.classic.wowhead.com/quest=190
SET @ID := 190;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0),
(@ID, 'esMX', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que tengas buena suerte, $n!', 0),
(@ID, 'esMX', '¡Que tengas buena suerte, $n!', 0);
-- 210 La cocina de Krazek
-- https://es.classic.wowhead.com/quest=210
SET @ID := 210;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Me has traído algo?', 0),
(@ID, 'esMX', '¡Hola! ¿Me has traído algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0),
(@ID, 'esMX', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0);
-- 338 Las verdes colinas de Tuercespina
-- https://es.classic.wowhead.com/quest=338
SET @ID := 338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya los capítulos, $n?', 0),
(@ID, 'esMX', '¿Tienes ya los capítulos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0),
(@ID, 'esMX', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0);
-- 195 Domina el raptor
-- https://es.classic.wowhead.com/quest=195
SET @ID := 195;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0),
(@ID, 'esMX', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0);
-- 196 Domina el raptor
-- https://es.classic.wowhead.com/quest=196
SET @ID := 196;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0),
(@ID, 'esMX', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0);
-- 597 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=597
SET @ID := 597;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0),
(@ID, 'esMX', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0);
-- 607 Regresa junto a MacKinley
-- https://es.classic.wowhead.com/quest=607
SET @ID := 607;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0),
(@ID, 'esMX', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0),
(@ID, 'esMX', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0);
-- 599 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=599
SET @ID := 599;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0),
(@ID, 'esMX', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0);
-- 576 ¡Ojo!
-- https://es.classic.wowhead.com/quest=576
SET @ID := 576;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0),
(@ID, 'esMX', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0),
(@ID, 'esMX', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0);

-- 583 Bienvenido a la jungla
-- https://es.classic.wowhead.com/quest=583
SET @ID := 583;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0),
(@ID, 'esMX', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0);
-- 194 Domina el raptor
-- https://es.classic.wowhead.com/quest=194
SET @ID := 194;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0),
(@ID, 'esMX', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', 'Un trabajo magistral, $gamigo:amiga;.', 0);
-- 185 Domina el tigre
-- https://es.classic.wowhead.com/quest=185
SET @ID := 185;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0),
(@ID, 'esMX', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Puedes seguir adelante.', 0),
(@ID, 'esMX', 'Muy bien, $n. Puedes seguir adelante.', 0);
-- 190 Domina la pantera
-- https://es.classic.wowhead.com/quest=190
SET @ID := 190;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0),
(@ID, 'esMX', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que tengas buena suerte, $n!', 0),
(@ID, 'esMX', '¡Que tengas buena suerte, $n!', 0);
-- 210 La cocina de Krazek
-- https://es.classic.wowhead.com/quest=210
SET @ID := 210;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Me has traído algo?', 0),
(@ID, 'esMX', '¡Hola! ¿Me has traído algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0),
(@ID, 'esMX', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0);
-- 338 Las verdes colinas de Tuercespina
-- https://es.classic.wowhead.com/quest=338
SET @ID := 338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya los capítulos, $n?', 0),
(@ID, 'esMX', '¿Tienes ya los capítulos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0),
(@ID, 'esMX', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0);
-- 195 Domina el raptor
-- https://es.classic.wowhead.com/quest=195
SET @ID := 195;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0),
(@ID, 'esMX', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0);
-- 196 Domina el raptor
-- https://es.classic.wowhead.com/quest=196
SET @ID := 196;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0),
(@ID, 'esMX', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0);
-- 597 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=597
SET @ID := 597;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0),
(@ID, 'esMX', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0);
-- 607 Regresa junto a MacKinley
-- https://es.classic.wowhead.com/quest=607
SET @ID := 607;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0),
(@ID, 'esMX', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0),
(@ID, 'esMX', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0);
-- 599 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=599
SET @ID := 599;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0),
(@ID, 'esMX', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0);
-- 576 ¡Ojo!
-- https://es.classic.wowhead.com/quest=576
SET @ID := 576;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0),
(@ID, 'esMX', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0),
(@ID, 'esMX', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0);
-- 577 Hay que ensamblar
-- https://es.classic.wowhead.com/quest=577
SET @ID := 577;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las botas de cuero estilo borceguí de Drizzlik, la mejor artesanía, cien por cien botas de piel de crocolisco aguasalada de la mejor calidad. ¡Insuperables!$B$B¿A que no se puede superar una descripción como esa, eh?$B$BA no ser... ¿tienes esas pieles que te pedí?', 0),
(@ID, 'esMX', 'Las botas de cuero estilo borceguí de Drizzlik, la mejor artesanía, cien por cien botas de piel de crocolisco aguasalada de la mejor calidad. ¡Insuperables!$B$B¿A que no se puede superar una descripción como esa, eh?$B$BA no ser... ¿tienes esas pieles que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis botas... son como salchichas, $n. Tienen una pinta estupenda y están buenísimas. Te digo que están hechas solo con las mejores carnes e ingredientes y, si las pruebas, te encantarán.$B$BEs más seguro, y más agradable, que simplemente confíes en mí y no preguntes lo que tienen dentro.', 0),
(@ID, 'esMX', 'Mis botas... son como salchichas, $n. Tienen una pinta estupenda y están buenísimas. Te digo que están hechas solo con las mejores carnes e ingredientes y, si las pruebas, te encantarán.$B$BEs más seguro, y más agradable, que simplemente confíes en mí y no preguntes lo que tienen dentro.', 0);
-- 627 Un favor a Krazek
-- https://es.classic.wowhead.com/quest=627
SET @ID := 627;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has conseguido la sangrita?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has conseguido la sangrita?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menuda maravilla! Me has hecho un gran favor.$B$BAquí tienes tu pago...', 0),
(@ID, 'esMX', '¡Menuda maravilla! Me has hecho un gran favor.$B$BAquí tienes tu pago...', 0);
-- 209 Colmillos Machacacráneos
-- https://es.classic.wowhead.com/quest=209
SET @ID := 209;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Unos bichos duros, ¿verdad? ¿Y bien? ¿Has tenido suerte? Perdona mi impaciencia, ¡pero esto ha sido una enorme espina clavada...! ¿¿Y bien??', 0),
(@ID, 'esMX', 'Unos bichos duros, ¿verdad? ¿Y bien? ¿Has tenido suerte? Perdona mi impaciencia, ¡pero esto ha sido una enorme espina clavada...! ¿¿Y bien??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡buen trabajo, buen trabajo! Ejem... aunque podrías haber hecho una labor de limpieza más minuciosa... en fin, no importa. Te lo agradezco, $n, gracias a ti, nuestra operación tendrá un resultado mejor y un aumento de productividad. Bien, bien, pasemos a otros asuntos...', 0),
(@ID, 'esMX', 'Ah, ¡buen trabajo, buen trabajo! Ejem... aunque podrías haber hecho una labor de limpieza más minuciosa... en fin, no importa. Te lo agradezco, $n, gracias a ti, nuestra operación tendrá un resultado mejor y un aumento de productividad. Bien, bien, pasemos a otros asuntos...', 0);
-- 601 Elementales de agua
-- https://es.classic.wowhead.com/quest=601
SET @ID := 601;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte, $n?', 0),
(@ID, 'esMX', '¿Has tenido suerte, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, no tengo capacidad para examinar los brazales y ver si alguno podría servirnos, pero seguro que, al menos uno, podrá ayudarnos. Llévalos a Dalaran y haz que un mago los vea.$B$BDespués de todo, yo no puedo irme tranquilamente de la Bahía del Botín para charlar con esos viejos magos cansados de la vida.$B$BNo me preocupa que alguien intente abrirse paso para convertirse en el nuevo barón. Nadie se interpone a Revilgaz y vive para contarlo.', 0),
(@ID, 'esMX', 'Mmm, no tengo capacidad para examinar los brazales y ver si alguno podría servirnos, pero seguro que, al menos uno, podrá ayudarnos. Llévalos a Dalaran y haz que un mago los vea.$B$BDespués de todo, yo no puedo irme tranquilamente de la Bahía del Botín para charlar con esos viejos magos cansados de la vida.$B$BNo me preocupa que alguien intente abrirse paso para convertirse en el nuevo barón. Nadie se interpone a Revilgaz y vive para contarlo.', 0);
-- 604 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=604
SET @ID := 604;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué noticias traes del campamento Velasangre del sur?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué noticias traes del campamento Velasangre del sur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n. Ahora que conocemos su plan, solo es cuestión de tiempo.$B$BY pensar que esos imbéciles han soltado el ancla justo fuera del cabo...', 0),
(@ID, 'esMX', 'Perfecto, $n. Ahora que conocemos su plan, solo es cuestión de tiempo.$B$BY pensar que esos imbéciles han soltado el ancla justo fuera del cabo...', 0);
-- 587 Tabaco rapé
-- https://es.classic.wowhead.com/quest=587
SET @ID := 587;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte, colega?', 0),
(@ID, 'esMX', '¿Has tenido suerte, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho, $n! ¡Y justo cuando yo también tengo que embarcar! No te lo puedo agradecer bastante, $gviejo:vieja; $gamigo:amiga;.', 0),
(@ID, 'esMX', '¡Muy bien hecho, $n! ¡Y justo cuando yo también tengo que embarcar! No te lo puedo agradecer bastante, $gviejo:vieja; $gamigo:amiga;.', 0);
-- 600 La minería de Ventura y Cía.
-- https://es.classic.wowhead.com/quest=600
SET @ID := 600;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos cristales? ¡¡Los necesito!!$B$BVamos a ver... necesito saber que la maldita Ventura y Cía. está perdiendo terreno en Tuercespina. Porque, ¿sabes?, los profesionales honestos tenemos que vivir de algo...', 0),
(@ID, 'esMX', '¿Tienes esos cristales? ¡¡Los necesito!!$B$BVamos a ver... necesito saber que la maldita Ventura y Cía. está perdiendo terreno en Tuercespina. Porque, ¿sabes?, los profesionales honestos tenemos que vivir de algo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Estupendo! ¡¡Puedo conseguir mucho por esto!!$B$BEsa Ventura y Cía. eligieron la selva equivocada donde excavar, ¿eh? A todos nos vendría estupendamente bien que se fueran de aquí.$B$BGracias, $n. Hoy has hecho una buena acción.', 0),
(@ID, 'esMX', '¡Genial! ¡Estupendo! ¡¡Puedo conseguir mucho por esto!!$B$BEsa Ventura y Cía. eligieron la selva equivocada donde excavar, ¿eh? A todos nos vendría estupendamente bien que se fueran de aquí.$B$BGracias, $n. Hoy has hecho una buena acción.', 0);
-- 617 Tallos de juncos akiris
-- https://es.classic.wowhead.com/quest=617
SET @ID := 617;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no tienes nada que me incumba, sigue tu camino, $n.', 0),
(@ID, 'esMX', 'Si no tienes nada que me incumba, sigue tu camino, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Después de todo, ¿no ha sido tan difícil conseguir 10 tallos de juncos akiris, eh? Sin ofender a los naga, ¡pero todo el mundo tiene derecho a ganarse la vida!', 0),
(@ID, 'esMX', 'Bien hecho, $n. Después de todo, ¿no ha sido tan difícil conseguir 10 tallos de juncos akiris, eh? Sin ofender a los naga, ¡pero todo el mundo tiene derecho a ganarse la vida!', 0);

-- 609 El vudú debido
-- https://es.classic.wowhead.com/quest=609
SET @ID := 609;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has encontrado a esos tres perros? ¿Tienes sus posesiones?', 0),
(@ID, 'esMX', '$n, ¿has encontrado a esos tres perros? ¿Tienes sus posesiones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡Podré conseguir un buen precio! Especialmente, por lo que hay en el pie de Maury. Muchas gracias, $n.$B$BEspero que esos tres hayan aprendido la lección: no apuestes algo que no puedes permitirte perder.$B$BY quizás sea demasiado tarde para ellos... deberían tener cuidado con quién apuestan.', 0),
(@ID, 'esMX', '¡Fantástico! ¡Podré conseguir un buen precio! Especialmente, por lo que hay en el pie de Maury. Muchas gracias, $n.$B$BEspero que esos tres hayan aprendido la lección: no apuestes algo que no puedes permitirte perder.$B$BY quizás sea demasiado tarde para ellos... deberían tener cuidado con quién apuestan.', 0);
-- 608 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=608
SET @ID := 608;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Cuál es el problema, $n? ¡Tenemos que atacar antes de que lo hagan los Bucaneros Velasangre!', 0),
(@ID, 'esMX', '¿¿Cuál es el problema, $n? ¡Tenemos que atacar antes de que lo hagan los Bucaneros Velasangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué día tan fantástico para los asaltantes Aguasnegras! ¡Tres hurras por ti, $n!', 0),
(@ID, 'esMX', '¡Ah, qué día tan fantástico para los asaltantes Aguasnegras! ¡Tres hurras por ti, $n!', 0);
-- 623 Tallos de juncos akiris
-- https://es.classic.wowhead.com/quest=623
SET @ID := 623;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! Tengo muchas cosas mejores que hacer que hablar con tipos como tú, $c. Haz que merezca la pena, o lárgate de aquí.$B$B¿De acuerdo? Bloads te ha enviado, ¿eh? A ver, ¿qué tienes pa mí?$B$B<El corsario Groy examina el paquete con atención>$B$BNo está mal, nada mal. Con otro de estos, mi cliente estaría mu contento.$B$BSupongo que tu próxima pregunta va a ser sobre el dinero, ¿eh, $c? ¡Pues claro que sí!$B$BToma, te voy a dar unas monedas y un consejo: largo de mi muelle.', 0),
(@ID, 'esMX', '¡¿Qué?! Tengo muchas cosas mejores que hacer que hablar con tipos como tú, $c. Haz que merezca la pena, o lárgate de aquí.$B$B¿De acuerdo? Bloads te ha enviado, ¿eh? A ver, ¿qué tienes pa mí?$B$B<El corsario Groy examina el paquete con atención>$B$BNo está mal, nada mal. Con otro de estos, mi cliente estaría mu contento.$B$BSupongo que tu próxima pregunta va a ser sobre el dinero, ¿eh, $c? ¡Pues claro que sí!$B$BToma, te voy a dar unas monedas y un consejo: largo de mi muelle.', 0);
-- 197 Domina el raptor
-- https://es.classic.wowhead.com/quest=197
SET @ID := 197;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza de $n? ¿Has conseguido seguirle la pista de vuelta al campamento, no?', 0),
(@ID, 'esMX', '¿Cómo va la caza de $n? ¿Has conseguido seguirle la pista de vuelta al campamento, no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maestro $n, ¡el Cazaraptores!$B$B¿A que suena bien?', 0),
(@ID, 'esMX', 'Maestro $n, ¡el Cazaraptores!$B$B¿A que suena bien?', 0);
-- 191 Domina la pantera
-- https://es.classic.wowhead.com/quest=191
SET @ID := 191;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ve a matar 10 panteras! ¡Muéstranos de que estas $ghecho:hecha;!', 0),
(@ID, 'esMX', '¡Ve a matar 10 panteras! ¡Muéstranos de que estas $ghecho:hecha;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una ejecución perfecta, $n!', 0),
(@ID, 'esMX', '¡Una ejecución perfecta, $n!', 0);
-- 192 Domina la pantera
-- https://es.classic.wowhead.com/quest=192
SET @ID := 192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué estás haciendo aquí, $n! Deberías estar arrastrándote por la maleza, tratando de matar a 10 Panteras Faucesombrías. Pensé que te imaginabas en el gran juego $c.', 0),
(@ID, 'esMX', '¡Qué estás haciendo aquí, $n! Deberías estar arrastrándote por la maleza, tratando de matar a 10 Panteras Faucesombrías. Pensé que te imaginabas en el gran juego $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado, $n!', 0),
(@ID, 'esMX', '¡Lo has logrado, $n!', 0);
-- 193 Domina la pantera
-- https://es.classic.wowhead.com/quest=193
SET @ID := 193;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bhag\'thera puede ser una bestia muy esquiva. ¿Cómo va la caza?', 0),
(@ID, 'esMX', 'Bhag\'thera puede ser una bestia muy esquiva. ¿Cómo va la caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que la gran Bhag\'thera está muerta! Enhorabuena, $n. ¡Eres $gun:una; $gpoderoso:poderosa; $c!', 0),
(@ID, 'esMX', '¡Así que la gran Bhag\'thera está muerta! Enhorabuena, $n. ¡Eres $gun:una; $gpoderoso:poderosa; $c!', 0);
-- 186 Persigue al tigre
-- https://es.classic.wowhead.com/quest=186
SET @ID := 186;
UPDATE `quest_template_locale` SET `Objectives` = 'Ajeck Rouack de la Expedición de Nesingwary, quiere que mates 10 tigres de Tuercespina.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si te esfuerzas por alcanzar mayores desafíos, antes debes demostrar su valía con esta tarea. Regresa a mí después de que hayas matado a 10 tigres de Tuercespina.', 0),
(@ID, 'esMX', 'Si te esfuerzas por alcanzar mayores desafíos, antes debes demostrar su valía con esta tarea. Regresa a mí después de que hayas matado a 10 tigres de Tuercespina.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me impresionas, $c. Estás progresando mucho.', 0),
(@ID, 'esMX', 'Me impresionas, $c. Estás progresando mucho.', 0);
-- 187 Domina el tigre
-- https://es.classic.wowhead.com/quest=187
SET @ID := 187;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes matar a 10 tigres de Tuercespina mayores antes de que te dé el desafío final que determinará si eres $gun:una; $gverdadero:verdadera; $gmaestro:maestra; de la caza de tigres.', 0),
(@ID, 'esMX', 'Debes matar a 10 tigres de Tuercespina mayores antes de que te dé el desafío final que determinará si eres $gun:una; $gverdadero:verdadera; $gmaestro:maestra; de la caza de tigres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante. Creo que casi estás $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Impresionante. Creo que casi estás $gpreparado:preparada;.', 0);
-- 188 Domina el tigre
-- https://es.classic.wowhead.com/quest=188
SET @ID := 188;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal va la caza de Sin\'Dall?', 0),
(@ID, 'esMX', '¿Qué tal va la caza de Sin\'Dall?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Absolutamente impresionante! ¡Eres $gun:una; $gauténtico:auténtica; $gmaestro:maestras; $gcazador:cazadora; de tigres, $n!', 0),
(@ID, 'esMX', '¡Absolutamente impresionante! ¡Eres $gun:una; $gauténtico:auténtica; $gmaestro:maestras; $gcazador:cazadora; de tigres, $n!', 0);
-- 339 Capítulo I
-- https://es.classic.wowhead.com/quest=339
SET @ID := 339;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Supongo que no has conseguido las páginas 1, 4, 6 y 8? Necesitamos esas cuatro para completar el capítulo I.', 0),
(@ID, 'esMX', '¿Supongo que no has conseguido las páginas 1, 4, 6 y 8? Necesitamos esas cuatro para completar el capítulo I.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin! El capítulo I está completo.', 0),
(@ID, 'esMX', '¡Al fin! El capítulo I está completo.', 0);
-- 340 Capítulo II
-- https://es.classic.wowhead.com/quest=340
SET @ID := 340;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguimos necesitando las páginas 10, 11, 14 y 16 para completar el capítulo II, $n.', 0),
(@ID, 'esMX', 'Seguimos necesitando las páginas 10, 11, 14 y 16 para completar el capítulo II, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El capítulo II está completo. ¡Bien hecho!', 0),
(@ID, 'esMX', 'El capítulo II está completo. ¡Bien hecho!', 0);
-- 341 Capítulo III
-- https://es.classic.wowhead.com/quest=341
SET @ID := 341;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte con las páginas 18, 20, 21 o 24? Son las únicas que faltan para completar el capítulo III.', 0),
(@ID, 'esMX', '¿Has tenido suerte con las páginas 18, 20, 21 o 24? Son las únicas que faltan para completar el capítulo III.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puff! Buen trabajo, $n. El capítulo III está completo.', 0),
(@ID, 'esMX', '¡Puff! Buen trabajo, $n. El capítulo III está completo.', 0);
-- 342 Capítulo IV
-- https://es.classic.wowhead.com/quest=342
SET @ID := 342;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo necesitamos tres páginas para acabar el capítulo IV, $n. ¿Tienes las páginas 25, 26 o 27?', 0),
(@ID, 'esMX', 'Solo necesitamos tres páginas para acabar el capítulo IV, $n. ¿Tienes las páginas 25, 26 o 27?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Ya tenemos el capítulo IV!', 0),
(@ID, 'esMX', '¡Excelente! ¡Ya tenemos el capítulo IV!', 0);
-- 208 Caza mayor
-- https://es.classic.wowhead.com/quest=208
SET @ID := 208;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has vuelto, $gviejo:vieja; $gamigo:amiga;. El rey Bangalash me ha obligado a volver arrastrándome al campamento demasiadas veces. Espera un momento.', 0),
(@ID, 'esMX', 'Veo que has vuelto, $gviejo:vieja; $gamigo:amiga;. El rey Bangalash me ha obligado a volver arrastrándome al campamento demasiadas veces. Espera un momento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pero qué maravilla! ¡Eso es! Enhorabuena, $n, por salir $gvictorioso:victoriosa; ahí donde otros fracasaron.$B$BEs un honor para mí contarte entre mis camaradas de caza mayor. ¡Nadie podrá poner en duda tu pericia en la caza y el rastreo!$B$B¡Levanto mi copa por ti, salud! ¡Salud!', 0),
(@ID, 'esMX', '¡Pero qué maravilla! ¡Eso es! Enhorabuena, $n, por salir $gvictorioso:victoriosa; ahí donde otros fracasaron.$B$BEs un honor para mí contarte entre mis camaradas de caza mayor. ¡Nadie podrá poner en duda tu pericia en la caza y el rastreo!$B$B¡Levanto mi copa por ti, salud! ¡Salud!', 0);
-- 204 Mala medicina
-- https://es.classic.wowhead.com/quest=204
SET @ID := 204;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy esperando los remedios y el extracto, $n.', 0),
(@ID, 'esMX', 'Estoy esperando los remedios y el extracto, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Estos remedios conseguirán mantener a más de nosotros con vida y en buena forma. Y los extractos nos ayudarán a crear nuestros propios remedios.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Estos remedios conseguirán mantener a más de nosotros con vida y en buena forma. Y los extractos nos ayudarán a crear nuestros propios remedios.', 0);
-- 203 La segunda rebelión
-- https://es.classic.wowhead.com/quest=203
SET @ID := 203;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas tenido éxito en tu caza, $n. No duraremos mucho sin tu ayuda.', 0),
(@ID, 'esMX', 'Espero que hayas tenido éxito en tu caza, $n. No duraremos mucho sin tu ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. La derrota de esos combatientes de la jungla aliviará algo la presión sobre nuestro campamento.$B$BPero ahora que has catado el tipo de fuerza al que nos enfrentamos, ¿aún deseas echar el resto con nosotros?', 0),
(@ID, 'esMX', 'Bien hecho. La derrota de esos combatientes de la jungla aliviará algo la presión sobre nuestro campamento.$B$BPero ahora que has catado el tipo de fuerza al que nos enfrentamos, ¿aún deseas echar el resto con nosotros?', 0);
-- 574 Fuerzas especiales
-- https://es.classic.wowhead.com/quest=574
SET @ID := 574;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La sargento Yohwa me dice que eres hábil y valiente, $c. ¿Tienes algo que informar?', 0),
(@ID, 'esMX', 'La sargento Yohwa me dice que eres hábil y valiente, $c. ¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. La sargento Yohwa confiaba en tus habilidades y yo confío en ella. La derrota de las tropas de Kurzen es casi demasiado buena para ser verdad. Temía que los rebeldes estábamos solos y que nadie se podría enfrentar al gran coronel.$B$BQuizás todavía nos quede alguna esperanza de sobrevivir.', 0),
(@ID, 'esMX', '$n. La sargento Yohwa confiaba en tus habilidades y yo confío en ella. La derrota de las tropas de Kurzen es casi demasiado buena para ser verdad. Temía que los rebeldes estábamos solos y que nadie se podría enfrentar al gran coronel.$B$BQuizás todavía nos quede alguna esperanza de sobrevivir.', 0);
-- 202 Coronel Kurzen
-- https://es.classic.wowhead.com/quest=202
SET @ID := 202;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me atrevo a creer que Kurzen y sus defensores están muertos, $n?', 0),
(@ID, 'esMX', '¿Me atrevo a creer que Kurzen y sus defensores están muertos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me atrevía a creer los informes pero nos traes la prueba… Has derrotado a Kurzen y a sus líderes. ¡Nos has salvado!$B$BEstos bosques están llenos de amenazas de todo tipo, pero ninguna tenía la perversa inteligencia de Kurzen. Todos estaremos más tranquilos ahora que ya no está.', 0),
(@ID, 'esMX', 'No me atrevía a creer los informes pero nos traes la prueba… Has derrotado a Kurzen y a sus líderes. ¡Nos has salvado!$B$BEstos bosques están llenos de amenazas de todo tipo, pero ninguna tenía la perversa inteligencia de Kurzen. Todos estaremos más tranquilos ahora que ya no está.', 0);

-- 207 El misterio de Kurzen
-- https://es.classic.wowhead.com/quest=207
SET @ID := 207;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Tienes las leyendas trols? ¡Tengo que saber sus secretos!', 0),
(@ID, 'esMX', '¡$n! ¿Tienes las leyendas trols? ¡Tengo que saber sus secretos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estudiaré estas leyendas para ver si hay algún tipo de unión entre los trols y el mal que ha poseído al coronel Kurzen.', 0),
(@ID, 'esMX', 'Gracias, $n. Estudiaré estas leyendas para ver si hay algún tipo de unión entre los trols y el mal que ha poseído al coronel Kurzen.', 0);
-- 602 Análisis mágico
-- https://es.classic.wowhead.com/quest=602
SET @ID := 602;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no te importa, tengo mucho que hacer ahora mismo.', 0),
(@ID, 'esMX', 'Si no te importa, tengo mucho que hacer ahora mismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Piedra de las Mareas? Muy interesante. Podría sorprenderte saber que yo escribí un libro... hace muchos años ya... sobre las leyendas del Imperio Gurubashi. Sé algo sobre la Piedra.$B$BAl menos uno de estos brazales parece tener un residuo mágico que creo poder analizar.$B$BVeamos...', 0),
(@ID, 'esMX', '¿La Piedra de las Mareas? Muy interesante. Podría sorprenderte saber que yo escribí un libro... hace muchos años ya... sobre las leyendas del Imperio Gurubashi. Sé algo sobre la Piedra.$B$BAl menos uno de estos brazales parece tener un residuo mágico que creo poder analizar.$B$BVeamos...', 0);
-- 628 Borceguí
-- https://es.classic.wowhead.com/quest=628
SET @ID := 628;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído por ahí que los crocoliscos aguasalada se están secando... malas noticias para el negocio, ¿eh?$B$BEn fin, espero que tengas esa piel de crocolisco aguasalada anciano para mí.', 0),
(@ID, 'esMX', 'He oído por ahí que los crocoliscos aguasalada se están secando... malas noticias para el negocio, ¿eh?$B$BEn fin, espero que tengas esa piel de crocolisco aguasalada anciano para mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Gracias a tu ayuda, tendré este pedido terminado y se lo enviaré al director Riddlevox en el próximo barco que salga para Villabajo. ¡Incluso antes de la hora prevista!$B$BHe hecho algunas de más, así que, por tus esfuerzos, puedes quedarte con un par. Regalo de Drizzlik.$B$BNo hay nada que supere el estilo borceguí de Drizzlik !', 0),
(@ID, 'esMX', '¡Genial! Gracias a tu ayuda, tendré este pedido terminado y se lo enviaré al director Riddlevox en el próximo barco que salga para Villabajo. ¡Incluso antes de la hora prevista!$B$BHe hecho algunas de más, así que, por tus esfuerzos, puedes quedarte con un par. Regalo de Drizzlik.$B$BNo hay nada que supere el estilo borceguí de Drizzlik !', 0);
-- 613 Abrir la pata de Maury
-- https://es.classic.wowhead.com/quest=613
SET @ID := 613;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buenas, $n! ¿Has encontrado la llave de Maury?', 0),
(@ID, 'esMX', '¡Buenas, $n! ¿Has encontrado la llave de Maury?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La has encontrado! Un millón de gracias, $n. ¡Has sido de gran ayuda!$B$BAquí tienes, ¡te lo has ganado!', 0),
(@ID, 'esMX', '¡La has encontrado! Un millón de gracias, $n. ¡Has sido de gran ayuda!$B$BAquí tienes, ¡te lo has ganado!', 0);
-- 205 Brujería trol
-- https://es.classic.wowhead.com/quest=205
SET @ID := 205;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos fetiches, $n? Quizás guarden el secreto de la degradación de Kurzen... ¡Debo saberlo!', 0),
(@ID, 'esMX', '¿Tienes esos fetiches, $n? Quizás guarden el secreto de la degradación de Kurzen... ¡Debo saberlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Estudiaré estos fetiches y veré si puedo descubrir el secreto de la corrupción de Kurzen.', 0),
(@ID, 'esMX', 'Gracias. Estudiaré estos fetiches y veré si puedo descubrir el secreto de la corrupción de Kurzen.', 0);
-- 206 Mai'Zoth
-- https://es.classic.wowhead.com/quest=206
SET @ID := 206;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy mi bendición. El mal aquí contenido es el único rival posible para la fuerza de Mai\'Zoth.', 0),
(@ID, 'esMX', 'Te doy mi bendición. El mal aquí contenido es el único rival posible para la fuerza de Mai\'Zoth.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ajá! ¡Lo has conseguido! Eres una gran fuerza para el bien, $n, ¡que las fuerzas nunca te fallen!$B$BEstudiaré este Ojo de la Mente y veré si puede usarse para buenos fines. Si no… habrá que destruirlo.', 0),
(@ID, 'esMX', '¡Ajá! ¡Lo has conseguido! Eres una gran fuerza para el bien, $n, ¡que las fuerzas nunca te fallen!$B$BEstudiaré este Ojo de la Mente y veré si puede usarse para buenos fines. Si no… habrá que destruirlo.', 0);
-- 1117 Rumores para Kravel
-- https://es.classic.wowhead.com/quest=1117
SET @ID := 1117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has averiguado algo de Nazz Vaporio? ¿Algún secreto que no quiere que se sepa, quizás?', 0),
(@ID, 'esMX', '¿Has averiguado algo de Nazz Vaporio? ¿Algún secreto que no quiere que se sepa, quizás?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, vaya! Esto es interesante... muy interesante. Eh, quizás la próxima vez que vea al piloto goblin debería hacerle una reverencia.$B$BLo que has averiguado vale oro, $n. Estoy seguro de que Nazz pagará una pequeña fortuna para mantener su secreto... en secreto.', 0),
(@ID, 'esMX', '¡Vaya, vaya! Esto es interesante... muy interesante. Eh, quizás la próxima vez que vea al piloto goblin debería hacerle una reverencia.$B$BLo que has averiguado vale oro, $n. Estoy seguro de que Nazz pagará una pequeña fortuna para mantener su secreto... en secreto.', 0);
-- 2873 El envío de Stoley
-- https://es.classic.wowhead.com/quest=2873
SET @ID := 2873;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mi cargamento de ron, $n?', 0),
(@ID, 'esMX', '¿Has encontrado mi cargamento de ron, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, gracias por el cargamento! Ahora MacKinley y yo podremos acabar con nuestra apuesta.', 0),
(@ID, 'esMX', '¡Genial, gracias por el cargamento! Ahora MacKinley y yo podremos acabar con nuestra apuesta.', 0);
-- 4324 Yuka Llavenrosca
-- https://es.classic.wowhead.com/quest=4324
SET @ID := 4324;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así es, busco a mi hermano. Debemos encontrarlo y recuperarlo, bendito sea su corazón.$B$BPero si no podemos traerlo entero... su cabeza bastará.', 0),
(@ID, 'esMX', 'Así es, busco a mi hermano. Debemos encontrarlo y recuperarlo, bendito sea su corazón.$B$BPero si no podemos traerlo entero... su cabeza bastará.', 0);
-- 8366 Mamporros en los Mares del Sur
-- https://es.classic.wowhead.com/quest=8366
SET @ID := 8366;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? Espero que les hayas enseñado a esos matones de los mares del Sur una lección que no olvidarán pronto.', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? Espero que les hayas enseñado a esos matones de los mares del Sur una lección que no olvidarán pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¡Tú sí que vales!$B$BEstoy seguro de que el cártel dejará de presionarme ahora que has acabado con esa escoria del Mar del Sur. Veamos, ¿qué puedo darte como recompensa? ¿Qué te parece si me das una pieza y te dejo elegir uno de estos por tus esfuerzos?', 0),
(@ID, 'esMX', '¡$n! ¡Tú sí que vales!$B$BEstoy seguro de que el cártel dejará de presionarme ahora que has acabado con esa escoria del Mar del Sur. Veamos, ¿qué puedo darte como recompensa? ¿Qué te parece si me das una pieza y te dejo elegir uno de estos por tus esfuerzos?', 0);
-- 8365 ¡Sombreros de pirata a babor!
-- https://es.classic.wowhead.com/quest=8365
SET @ID := 8365;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los 20 sombreros? No te creo, déjamelos ver. ¡Sería mejor que estuvieran en perfecto estado!', 0),
(@ID, 'esMX', '¿Tienes los 20 sombreros? No te creo, déjamelos ver. ¡Sería mejor que estuvieran en perfecto estado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, eres un cielo, aunque hayas tardado más de lo que esperaba. Cuando estos sombreros estén limpios y les haya dado mi toque personal, sacaré un buen pellizco por ellos. Y dado que siempre suelo recompensar un trabajo bien hecho, aquí tienes algo para ti. Te recomiendo que reserves algo para darte un buen baño, encanto.', 0),
(@ID, 'esMX', 'Oh, eres un cielo, aunque hayas tardado más de lo que esperaba. Cuando estos sombreros estén limpios y les haya dado mi toque personal, sacaré un buen pellizco por ellos. Y dado que siempre suelo recompensar un trabajo bien hecho, aquí tienes algo para ti. Te recomiendo que reserves algo para darte un buen baño, encanto.', 0);
-- 3520 Los espíritus de los estridadores
-- https://es.classic.wowhead.com/quest=3520
SET @ID := 3520;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has capturado la esencia de los espíritus de los estridadores, $n?', 0),
(@ID, 'esMX', '¿Has capturado la esencia de los espíritus de los estridadores, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Quizás ha llegado el momento de que cuente más cosas...$B$BUna antigua profecía de los trols cuenta que el dios muerto Hakkar, el Cazador de Almas, un día regresará a esta tierra. Algunos dicen que el regreso de Hakkar traerá dicha y gloria a los trols, mientras que otros creen que su resurrección significará el principio del fin.$B$BYo no creo en esta leyenda pero sé que la esencia de Hakkar ostenta gran poder, por lo que no debe caer en manos de aquellos que no harán buen uso de ella...', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Quizás ha llegado el momento de que cuente más cosas...$B$BUna antigua profecía de los trols cuenta que el dios muerto Hakkar, el Cazador de Almas, un día regresará a esta tierra. Algunos dicen que el regreso de Hakkar traerá dicha y gloria a los trols, mientras que otros creen que su resurrección significará el principio del fin.$B$BYo no creo en esta leyenda pero sé que la esencia de Hakkar ostenta gran poder, por lo que no debe caer en manos de aquellos que no harán buen uso de ella...', 0);
-- 2874 Un envío para MacKinley
-- https://es.classic.wowhead.com/quest=2874
SET @ID := 2874;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Aflojó Stoley la botella que me prometió?', 0),
(@ID, 'esMX', '¿Aflojó Stoley la botella que me prometió?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, a ver, déjame probar...$B$B¡No puedo creerlo! ¡Esto es... la bomba! ¡Genial!$B$BSupongo que Stoley puede quedarse el dinero que me debe. Tenía razón en cuanto al ron de la sentina Bonvapor... ¡Cómo rasca!', 0),
(@ID, 'esMX', 'Mm, a ver, déjame probar...$B$B¡No puedo creerlo! ¡Esto es... la bomba! ¡Genial!$B$BSupongo que Stoley puede quedarse el dinero que me debe. Tenía razón en cuanto al ron de la sentina Bonvapor... ¡Cómo rasca!', 0);
-- 110 Análisis de trozos de insecto
-- https://es.classic.wowhead.com/quest=110
SET @ID := 110;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, tengo los resultados aquí mismo. Son... inquietantes, por no decir otra cosa.$B$BCreemos que es cierta nuestra sospecha inicial de que los bichos están bajo el control de una fuerza externa. De ser así, nos enfrentamos a un poder desconocido y, lo que es más, maligno. ¡A estos bichos los han convertido en devastadores! Nunca había visto nada parecido.', 0),
(@ID, 'esMX', 'Sí, tengo los resultados aquí mismo. Son... inquietantes, por no decir otra cosa.$B$BCreemos que es cierta nuestra sospecha inicial de que los bichos están bajo el control de una fuerza externa. De ser así, nos enfrentamos a un poder desconocido y, lo que es más, maligno. ¡A estos bichos los han convertido en devastadores! Nunca había visto nada parecido.', 0);
-- 113 Análisis de trozos de insecto
-- https://es.classic.wowhead.com/quest=113
SET @ID := 113;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y bien, perito adjunto $n, ¿Morterozugg tiene el informe listo?', 0),
(@ID, 'esMX', 'Y bien, perito adjunto $n, ¿Morterozugg tiene el informe listo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por el informe, perito adjunto $n. Aquí tienes lo que te corresponde por el gran servicio prestado a la compañía de aguas de Gadgetzan.$B$BAunque no suelo entregar nuestra valiosa información de manera desinteresada a aquellos que con toda seguridad pagarían bien por ella, hace años que conozco a Morterozugg. Si él recomienda que todos han de conocer esta información, que así sea. Dame un momento y te haré una copia.', 0),
(@ID, 'esMX', 'Gracias por el informe, perito adjunto $n. Aquí tienes lo que te corresponde por el gran servicio prestado a la compañía de aguas de Gadgetzan.$B$BAunque no suelo entregar nuestra valiosa información de manera desinteresada a aquellos que con toda seguridad pagarían bien por ella, hace años que conozco a Morterozugg. Si él recomienda que todos han de conocer esta información, que así sea. Dame un momento y te haré una copia.', 0);
-- 162 La sublevación de los silítidos
-- https://es.classic.wowhead.com/quest=162
SET @ID := 162;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la paz y la tranquilidad sean contigo, forastero. ¿En qué necesitas hoy mi consejo?', 0),
(@ID, 'esMX', 'Que la paz y la tranquilidad sean contigo, forastero. ¿En qué necesitas hoy mi consejo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este informe... nosotros, los elfos de la noche, conocemos muy bien el terror del que en él se habla. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0),
(@ID, 'esMX', 'Este informe... nosotros, los elfos de la noche, conocemos muy bien el terror del que en él se habla. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0);
-- 1118 De vuelta a Bahía del Botín
-- https://es.classic.wowhead.com/quest=1118
SET @ID := 1118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola. ¿Qué trae a $gun:una; noble $r como tú a Bahía del Botín?', 0),
(@ID, 'esMX', 'Hola, hola. ¿Qué trae a $gun:una; noble $r como tú a Bahía del Botín?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo. Kravel ha ideado un nuevo plan. Este Kravel es un tanto siniestro, y eso me gusta.$B$BAsí que necesitas algo para confundir los sentidos, ¿no es cierto? Algo fuerte...$B$BMe pregunto si la mezcla que Zanzil les da a los zombis serviría...', 0),
(@ID, 'esMX', 'Entiendo. Kravel ha ideado un nuevo plan. Este Kravel es un tanto siniestro, y eso me gusta.$B$BAsí que necesitas algo para confundir los sentidos, ¿no es cierto? Algo fuerte...$B$BMe pregunto si la mezcla que Zanzil les da a los zombis serviría...', 0);
-- 3527 La profecía de Mosh'aru
-- https://es.classic.wowhead.com/quest=3527
SET @ID := 3527;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las tablillas de la profecía de Mosh\'aru, $n?$B$BCuando tenga las tablillas... ¡podré estudiarlas y descubrir cómo encerrar la esencia de Hakkar!', 0),
(@ID, 'esMX', '¿Tienes las tablillas de la profecía de Mosh\'aru, $n?$B$BCuando tenga las tablillas... ¡podré estudiarlas y descubrir cómo encerrar la esencia de Hakkar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué bien! Puedo fusionar estas dos tablillas y después estudiar los secretos que encierran.$B$BMi deuda contigo va en aumento, $n, y continuará haciéndolo.', 0),
(@ID, 'esMX', '¡Ah, qué bien! Puedo fusionar estas dos tablillas y después estudiar los secretos que encierran.$B$BMi deuda contigo va en aumento, $n, y continuará haciéndolo.', 0);
-- 4787 El huevo antiguo
-- https://es.classic.wowhead.com/quest=4787
SET @ID := 4787;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el huevo antiguo? Siento la agitación de poderosas fuerzas y temo que el tiempo se esté agotando.', 0),
(@ID, 'esMX', '¿Tienes el huevo antiguo? Siento la agitación de poderosas fuerzas y temo que el tiempo se esté agotando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, tienes el huevo! Me inclino ante ti, $n. Tu fuerza y valentía serán recordados durante mucho tiempo.', 0),
(@ID, 'esMX', '¡Ah, tienes el huevo! Me inclino ante ti, $n. Tu fuerza y valentía serán recordados durante mucho tiempo.', 0);
-- 5535 Agitación espiritual
-- https://es.classic.wowhead.com/quest=5535
SET @ID := 5535;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de los espíritus Altonato, $c?$B$BMuchos eventos han causado un gran sufrimiento a todas las razas de Azeroth, pero por alguna razón, estos espíritus parecen ser una plaga para todas las personas. Tal vez sea el deseo continuo de cualquier magia arcana; ese deseo es un presagio de la Legión Ardiente, y sabemos a qué puede conducir.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de los espíritus Altonato, $c?$B$BMuchos eventos han causado un gran sufrimiento a todas las razas de Azeroth, pero por alguna razón, estos espíritus parecen ser una plaga para todas las personas. Tal vez sea el deseo continuo de cualquier magia arcana; ese deseo es un presagio de la Legión Ardiente, y sabemos a qué puede conducir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c. Gracias por tu ayuda. Los espíritus descansan y las amenazas que su deseo de lo arcano trajeron han disminuido.$B$BEstoy seguro de que los dos lados del conflicto que causa estragos en Azeroth se darán cuenta de que estás por encima de estas cosas.', 0),
(@ID, 'esMX', 'Muy bien, $c. Gracias por tu ayuda. Los espíritus descansan y las amenazas que su deseo de lo arcano trajeron han disminuido.$B$BEstoy seguro de que los dos lados del conflicto que causa estragos en Azeroth se darán cuenta de que estás por encima de estas cosas.', 0);

-- 5536 Una tierra llena de odio
-- https://es.classic.wowhead.com/quest=5536
SET @ID := 5536;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu batalla contra los sátiros, $c?$B$B¿Son tan fuertes como pensabas? ¿Más fuerte? O tal vez no eran nada para tu propia fuerza.', 0),
(@ID, 'esMX', '¿Cómo va tu batalla contra los sátiros, $c?$B$B¿Son tan fuertes como pensabas? ¿Más fuerte? O tal vez no eran nada para tu propia fuerza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c. Veo que no solo eres $ghabilidoso:habilidosa; sino también $gastuto:astuta;. La derrota de tales criaturas es un testimonio de tu lealtad a los inquilinos de la Madre Tierra, aunque no la reconozcas como tu propia deidad. Está presente en todas las cosas de este planeta y más allá. Sus ojos, uno oscuro y otro claro, viajan por el cielo siempre pendientes de nosotros.$B$BAcepta este puñado de monedas como muestra de aprecio por lo que has hecho.', 0),
(@ID, 'esMX', 'Muy bien, $c. Veo que no solo eres $ghabilidoso:habilidosa; sino también $gastuto:astuta;. La derrota de tales criaturas es un testimonio de tu lealtad a los inquilinos de la Madre Tierra, aunque no la reconozcas como tu propia deidad. Está presente en todas las cosas de este planeta y más allá. Sus ojos, uno oscuro y otro claro, viajan por el cielo siempre pendientes de nosotros.$B$BAcepta este puñado de monedas como muestra de aprecio por lo que has hecho.', 0);
-- 3461 Regresa junto a Tymor
-- https://es.classic.wowhead.com/quest=3461
SET @ID := 3461;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estás de vuelta! Excelente. ¿También tienes mi kit de dibujo?', 0),
(@ID, 'esMX', '¡Estás de vuelta! Excelente. ¿También tienes mi kit de dibujo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! Me alegro mucho de escucharlo.$B$BEstoy muy ansioso por llegar a mi torre y repasar esos calcos. Tengo tanta envidia de que... vayas a un lugar como Azshara. Ese es el sueño de cualquier estudiante de lo arcano, supongo.$B$BBueno, nunca hablamos de ningún tipo de recompensa ya que solo trabajabas para la Liga de Exploradores, pero te mereces algo.', 0),
(@ID, 'esMX', '¡Maravilloso! Me alegro mucho de escucharlo.$B$BEstoy muy ansioso por llegar a mi torre y repasar esos calcos. Tengo tanta envidia de que... vayas a un lugar como Azshara. Ese es el sueño de cualquier estudiante de lo arcano, supongo.$B$BBueno, nunca hablamos de ningún tipo de recompensa ya que solo trabajabas para la Liga de Exploradores, pero te mereces algo.', 0);
-- 1119 La mezcla de Zanzil y la cerveza de tontos
-- https://es.classic.wowhead.com/quest=1119
SET @ID := 1119;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Pinchabujas nos ha echado una mano o no?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Pinchabujas nos ha echado una mano o no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¡Pinchabujas me ha echado una mano! Lo recordaré la próxima vez que lo vea.$B$BGracias, $n. Estás haciendo un buen trabajo y ambos vamos a ganar mucho con todo esto...', 0),
(@ID, 'esMX', '¡Estupendo! ¡Pinchabujas me ha echado una mano! Lo recordaré la próxima vez que lo vea.$B$BGracias, $n. Estás haciendo un buen trabajo y ambos vamos a ganar mucho con todo esto...', 0);
-- 1120 Emborrachar a los gnomos
-- https://es.classic.wowhead.com/quest=1120
SET @ID := 1120;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¡Hola! ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cerveza? ¡Qué detalle por tu parte! ¡Gracias!$B$BNo deberíamos beber antes de la carrera pero un poquito de nada no les hará daño a los chicos. Además, no será tan fuerte, ¿verdad?', 0),
(@ID, 'esMX', '¿Cerveza? ¡Qué detalle por tu parte! ¡Gracias!$B$BNo deberíamos beber antes de la carrera pero un poquito de nada no les hará daño a los chicos. Además, no será tan fuerte, ¿verdad?', 0);
-- 1121 Emborrachar a los goblins
-- https://es.classic.wowhead.com/quest=1121
SET @ID := 1121;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué estás mirando?', 0),
(@ID, 'esMX', '¿Qué estás mirando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tenemos aquí? Bebida, ¿eh?$B$BBueno, no importa si solo bebemos un poco...', 0),
(@ID, 'esMX', '¿Qué tenemos aquí? Bebida, ¿eh?$B$BBueno, no importa si solo bebemos un poco...', 0);
-- 1122 Volver a informar a Pinchabujas
-- https://es.classic.wowhead.com/quest=1122
SET @ID := 1122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Ha funcionado la cerveza o no? Es fuerte, ¿verdad?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Ha funcionado la cerveza o no? Es fuerte, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí dice que la cerveza de tontos ha sido todo un éxito. ¡Qué noticia tan buena!$B$BSi necesitas más, solo tienes que decírmelo y conseguir un poco de mezcla de Zanzil.', 0),
(@ID, 'esMX', 'Aquí dice que la cerveza de tontos ha sido todo un éxito. ¡Qué noticia tan buena!$B$BSi necesitas más, solo tienes que decírmelo y conseguir un poco de mezcla de Zanzil.', 0);
-- 8893 El Superhuevomático
-- https://es.classic.wowhead.com/quest=8893
SET @ID := 8893;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0),
(@ID, 'esMX', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0),
(@ID, 'esMX', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0);
-- 2748 Un huevo de primera
-- https://es.classic.wowhead.com/quest=2748
SET @ID := 2748;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen huevo es aquel que, en condiciones ideales, eclosionará libre de los efectos malignos de los encantamientos de los ogros Gordunni.', 0),
(@ID, 'esMX', 'Un buen huevo es aquel que, en condiciones ideales, eclosionará libre de los efectos malignos de los encantamientos de los ogros Gordunni.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. ¡Enviaré este huevo a Darnassus donde espero que pronto eclosione!$B$BAcepta esto como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Muy bien, $n. ¡Enviaré este huevo a Darnassus donde espero que pronto eclosione!$B$BAcepta esto como muestra de mi gratitud.', 0);
-- 2747 Un huevo muy especial
-- https://es.classic.wowhead.com/quest=2747
SET @ID := 2747;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He visto muy pocos huevos recuperados de Feralas en condiciones extraordinarias. Estos son huevos del tipo más raro...', 0),
(@ID, 'esMX', 'He visto muy pocos huevos recuperados de Feralas en condiciones extraordinarias. Estos son huevos del tipo más raro...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ahora tienes ¡algo increíble!$B$BEspero que recuerdes siempre el bien que has hecho hoy.', 0),
(@ID, 'esMX', 'Bueno, ahora tienes ¡algo increíble!$B$BEspero que recuerdes siempre el bien que has hecho hoy.', 0);
-- 2749 Un huevo normal
-- https://es.classic.wowhead.com/quest=2749
SET @ID := 2749;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los huevos de hipogrifo comunes eclosionan aproximadamente en la mitad del tiempo. Hacemos nuestro mejor esfuerzo para cuidarlos y, con un poco de suerte, eclosionarán.', 0),
(@ID, 'esMX', 'Los huevos de hipogrifo comunes eclosionan aproximadamente en la mitad del tiempo. Hacemos nuestro mejor esfuerzo para cuidarlos y, con un poco de suerte, eclosionarán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿has encontrado un huevo común, $n? Por favor dámelo... Y solo podemos esperar lo mejor.$B$BNo tengo mucho, pero acepta esta recompensa. Si alguna vez te encuentras en Feralas de nuevo, debes saber que siempre estoy aquí para que me traigas los huevos que encuentres allí.', 0),
(@ID, 'esMX', 'Entonces, ¿has encontrado un huevo común, $n? Por favor dámelo... Y solo podemos esperar lo mejor.$B$BNo tengo mucho, pero acepta esta recompensa. Si alguna vez te encuentras en Feralas de nuevo, debes saber que siempre estoy aquí para que me traigas los huevos que encuentres allí.', 0);
-- 2750 Un huevo pasado
-- https://es.classic.wowhead.com/quest=2750
SET @ID := 2750;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos huevos que no se pueden salvar, nunca eclosionarán.', 0),
(@ID, 'esMX', 'Estos huevos que no se pueden salvar, nunca eclosionarán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me temo que tengo malas noticias para ti, $n. Este huevo no sirve. Te lo cojo, pero únicamente para que sea desechado como es debido.$B$BPor favor, no permitas que esto te desanime; no podemos salvarlos a todos. Si vuelves alguna vez a Feralas, inténtalo de nuevo... ¡y trae otro huevo para el Superhuevomático!', 0),
(@ID, 'esMX', 'Me temo que tengo malas noticias para ti, $n. Este huevo no sirve. Te lo cojo, pero únicamente para que sea desechado como es debido.$B$BPor favor, no permitas que esto te desanime; no podemos salvarlos a todos. Si vuelves alguna vez a Feralas, inténtalo de nuevo... ¡y trae otro huevo para el Superhuevomático!', 0);
-- 2519 El templo de la Luna
-- https://es.classic.wowhead.com/quest=2519
SET @ID := 2519;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía la hermana Aquinne, ¿verdad?', 0),
(@ID, 'esMX', 'Así que te envía la hermana Aquinne, ¿verdad?', 0);
-- 2518 Las lágrimas de la Luna
-- https://es.classic.wowhead.com/quest=2518
SET @ID := 2518;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento haberte encomendado esta tarea pero entiende que queda poca esperanza para Lady Sathrah.$B$BLo único que nos queda es ofrecer el sacrificio de sus hilanderas a Elune. Con este sacrificio, Elune bendecirá a Sathrah de modo que podrá nacer de nuevo en paz.', 0),
(@ID, 'esMX', 'Siento haberte encomendado esta tarea pero entiende que queda poca esperanza para Lady Sathrah.$B$BLo único que nos queda es ofrecer el sacrificio de sus hilanderas a Elune. Con este sacrificio, Elune bendecirá a Sathrah de modo que podrá nacer de nuevo en paz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El bosque llora por Lady Sathrah pero era algo que había que hacer.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'El bosque llora por Lady Sathrah pero era algo que había que hacer.$B$BGracias, $n.', 0);
-- 4493 La marcha de los silítidos
-- https://es.classic.wowhead.com/quest=4493
SET @ID := 4493;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo entendido que te envió a mí Gracina. Tu experiencia combatiendo a esas bestias no tiene precio; no sé de nadie más que haya tratado con ellas. Y respecto a la idea de Gracina de que sacan su fuerza del Cráter de Un\'Goro... quizás sea así. Un\'Goro es una misteriosa y peligrosa jungla que hay al oeste de aquí. Quizás sea también el lugar en el que más podremos acercarnos a desvelar misterio de los silítidos.', 0),
(@ID, 'esMX', 'Tengo entendido que te envió a mí Gracina. Tu experiencia combatiendo a esas bestias no tiene precio; no sé de nadie más que haya tratado con ellas. Y respecto a la idea de Gracina de que sacan su fuerza del Cráter de Un\'Goro... quizás sea así. Un\'Goro es una misteriosa y peligrosa jungla que hay al oeste de aquí. Quizás sea también el lugar en el que más podremos acercarnos a desvelar misterio de los silítidos.', 0);
-- 730 ¿Problemas en Costa Oscura?
-- https://es.classic.wowhead.com/quest=730
SET @ID := 730;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cómo me alegro de que el arqueólogo jefe Mostachogris enviara a alguien a buscarnos...', 0),
(@ID, 'esMX', 'Cómo me alegro de que el arqueólogo jefe Mostachogris enviara a alguien a buscarnos...', 0);
-- 937 El claro encantado
-- https://es.classic.wowhead.com/quest=937
SET @ID := 937;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te resultará sencillo enfrentarte a sus potentes garras y a sus afilados picos con las facultades que posees, $n, pero confío en que no fallarás en esta misión.', 0),
(@ID, 'esMX', 'No te resultará sencillo enfrentarte a sus potentes garras y a sus afilados picos con las facultades que posees, $n, pero confío en que no fallarás en esta misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me impresiona realmente ver lo que has conseguido en un plazo tan corto de tiempo, $n, tanto que me gustaría pedirte que te quedaras para ayudarme... pero en el fondo de mi corazón sé que te esperan tareas más importantes.$B$BMe he dado cuenta de que el Árbol del Oráculo se ha despojado de una parte de su corteza. Seguro que hay algo en lo que puedas ayudarle, así que ve a hablar con él.', 0),
(@ID, 'esMX', 'Me impresiona realmente ver lo que has conseguido en un plazo tan corto de tiempo, $n, tanto que me gustaría pedirte que te quedaras para ayudarme... pero en el fondo de mi corazón sé que te esperan tareas más importantes.$B$BMe he dado cuenta de que el Árbol del Oráculo se ha despojado de una parte de su corteza. Seguro que hay algo en lo que puedas ayudarle, así que ve a hablar con él.', 0);
-- 931 Fronda fulgurante
-- https://es.classic.wowhead.com/quest=931
SET @ID := 931;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De dónde has sacado esto? No veía una planta como esta desde aquella vez que estuve en el Pantano de las Penas... ¡hace décadas! Es increíble que haya llegado hasta Teldrassil, ¡y que haya alcanzado este tamaño!$B$BGracias, $n. Perdona la brevedad de mis palabras pero me gustaría someter a esta hoja a una prueba...', 0),
(@ID, 'esMX', '¿De dónde has sacado esto? No veía una planta como esta desde aquella vez que estuve en el Pantano de las Penas... ¡hace décadas! Es increíble que haya llegado hasta Teldrassil, ¡y que haya alcanzado este tamaño!$B$BGracias, $n. Perdona la brevedad de mis palabras pero me gustaría someter a esta hoja a una prueba...', 0);
-- 940 Teldrassil
-- https://es.classic.wowhead.com/quest=940
SET @ID := 940;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... El espíritu del bosque habita en tu interior, $c. ¿Qué te trae ante el archidruida de los Kaldorei?', 0),
(@ID, 'esMX', 'Mmm... El espíritu del bosque habita en tu interior, $c. ¿Qué te trae ante el archidruida de los Kaldorei?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me preguntaba por qué el Árbol del Oráculo llevaba tanto tiempo sin ponerse en contacto conmigo. Parece que mientras unos problemas se solventan otros surgen para sembrar la inquietud.$B$BTemo que mi trabajo en Teldrassil nunca llegue a buen puerto y que nunca recuperemos nuestra inmortalidad.$B$BNo obstante, tú has cumplido el cometido asignado por el Árbol del Oráculo y deberías obtener una recompensa por tu diligencia.', 0),
(@ID, 'esMX', 'Me preguntaba por qué el Árbol del Oráculo llevaba tanto tiempo sin ponerse en contacto conmigo. Parece que mientras unos problemas se solventan otros surgen para sembrar la inquietud.$B$BTemo que mi trabajo en Teldrassil nunca llegue a buen puerto y que nunca recuperemos nuestra inmortalidad.$B$BNo obstante, tú has cumplido el cometido asignado por el Árbol del Oráculo y deberías obtener una recompensa por tu diligencia.', 0);
-- 2399 Flora en brote
-- https://es.classic.wowhead.com/quest=2399
SET @ID := 2399;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las hojas que Denalan plantó en su jardín han retoñado y crecido. Esperan con impaciencia a que alguien las coja...', 0),
(@ID, 'esMX', 'Las hojas que Denalan plantó en su jardín han retoñado y crecido. Esperan con impaciencia a que alguien las coja...', 0);
-- 4161 La receta de los kaldorei
-- https://es.classic.wowhead.com/quest=4161
SET @ID := 4161;
UPDATE `quest_template_locale` SET `Objectives` = 'Recoge 7 patas de araña pequeña para Zarrin, que está en Dolanaar.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda el equilibrio, $n. Quiero que comprendas y te compenetres con los bosques.', 0),
(@ID, 'esMX', 'Recuerda el equilibrio, $n. Quiero que comprendas y te compenetres con los bosques.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda siempre lo que te he enseñado hoy, $n. Tú formas parte del equilibrio que los elfos de la noche se esfuerzan por conservar, incluso en tiempos difíciles.', 0),
(@ID, 'esMX', 'Recuerda siempre lo que te he enseñado hoy, $n. Tú formas parte del equilibrio que los elfos de la noche se esfuerzan por conservar, incluso en tiempos difíciles.', 0);
-- 997 Las tierras de Denalan
-- https://es.classic.wowhead.com/quest=997
SET @ID := 997;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, aquí está! Llevo tiempo esperando este paquete con tierras especiales. Espero que todavía esté en buen estado...$B$BGracias por traérmela, $n. Eres $gun:una; $r $gcomprometido:comprometida; con su tiempo.', 0),
(@ID, 'esMX', '¡Ah, aquí está! Llevo tiempo esperando este paquete con tierras especiales. Espero que todavía esté en buen estado...$B$BGracias por traérmela, $n. Eres $gun:una; $r $gcomprometido:comprometida; con su tiempo.', 0);

-- 475 Una brisa problemática
-- https://es.classic.wowhead.com/quest=475
SET @ID := 475;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a los espíritus del bosque que estás aquí! Sabía que Athridas percibiría los problemas y enviaría ayuda.', 0),
(@ID, 'esMX', '¡Gracias a los espíritus del bosque que estás aquí! Sabía que Athridas percibiría los problemas y enviaría ayuda.', 0);
-- 932 Odio enraizado
-- https://es.classic.wowhead.com/quest=932
SET @ID := 932;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado ya a Lord Melenas? Es muy importante que alguien se ocupe de él rápido y con discreción, $n. Su existencia es una vergüenza para todos nosotros.', 0),
(@ID, 'esMX', '¿Has matado ya a Lord Melenas? Es muy importante que alguien se ocupe de él rápido y con discreción, $n. Su existencia es una vergüenza para todos nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con Lord Melenas criando malvas al fin puedo encargarme de otros asuntos. Gracias, $n.', 0),
(@ID, 'esMX', 'Con Lord Melenas criando malvas al fin puedo encargarme de otros asuntos. Gracias, $n.', 0);
-- 2438 El atrapasueños esmeralda
-- https://es.classic.wowhead.com/quest=2438
SET @ID := 2438;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, por favor. Solo espero que los furbolgs no hayan estropeado mi atrapasueños esmeralda.$B$B¿Lo has recuperado ya, $n?', 0),
(@ID, 'esMX', 'Date prisa, por favor. Solo espero que los furbolgs no hayan estropeado mi atrapasueños esmeralda.$B$B¿Lo has recuperado ya, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi atrapasueños esmeralda es muy importante para mí. Es un regalo reservado a unos pocos. Gracias por devolvérmelo, $n.', 0),
(@ID, 'esMX', 'Mi atrapasueños esmeralda es muy importante para mí. Es un regalo reservado a unos pocos. Gracias por devolvérmelo, $n.', 0);
-- 487 El camino a Darnassus
-- https://es.classic.wowhead.com/quest=487
SET @ID := 487;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El camino todavía no es seguro, $c. Avanza y mata a 6 emboscadores Tuercepinos y luego regresa a mí.', 0),
(@ID, 'esMX', 'El camino todavía no es seguro, $c. Avanza y mata a 6 emboscadores Tuercepinos y luego regresa a mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has servido con diligencia a las gentes de Dolanaar y Darnassus, valiente $c. Como miembro del Escuadrón de centinelas de Teldrassil, aplaudo tus esfuerzos.', 0),
(@ID, 'esMX', 'Has servido con diligencia a las gentes de Dolanaar y Darnassus, valiente $c. Como miembro del Escuadrón de centinelas de Teldrassil, aplaudo tus esfuerzos.', 0);
-- 488 Las apuestas de Zenn
-- https://es.classic.wowhead.com/quest=488
SET @ID := 488;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué has tardado tanto, $n? He estado esperando a que llegaras con todo lo que necesito.', 0),
(@ID, 'esMX', '¿Por qué has tardado tanto, $n? He estado esperando a que llegaras con todo lo que necesito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja, ja! ¡Lo has hecho!$B$B¿Quién habría imaginado que yo, Zenn Nauseapezuña, conseguiría que $gun:una; $r hiciera lo que se me antojara? ¡Yo no, la verdad! Pero así es... este maravilloso mundo está lleno de sorpresas.$B$B¡Tres hurras por $gnuestro:nuestra; inocente de hoy!', 0),
(@ID, 'esMX', '¡Ja, ja, ja! ¡Lo has hecho!$B$B¿Quién habría imaginado que yo, Zenn Nauseapezuña, conseguiría que $gun:una; $r hiciera lo que se me antojara? ¡Yo no, la verdad! Pero así es... este maravilloso mundo está lleno de sorpresas.$B$B¡Tres hurras por $gnuestro:nuestra; inocente de hoy!', 0);
-- 2159 Paquete de Dolanaar
-- https://es.classic.wowhead.com/quest=2159
SET @ID := 2159;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo puedo ayudarte, joven? ¿Vienes para alojarte en la posada? ¿Necesitas una piedra de hogar?', 0),
(@ID, 'esMX', '¿Cómo puedo ayudarte, joven? ¿Vienes para alojarte en la posada? ¿Necesitas una piedra de hogar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah sí, el paquete de hierbas de Cañada Umbría. Es una lástima que no lo haya podido traer el propio Porthannius pues él y yo tenemos mucho de qué hablar. No obstante, me alegro de hayas venido a traerme las hierbas.$B$BYa que estás aquí, aprovecha para descansar. $gLos héroes:Las heroínas; han de velar por su fuerza y ánimo, y buscar descanso y solaz cuando sea necesario. Si no se proporciona paz al cuerpo y a la mente, el fracaso es inevitable.$B$BAsí pues... descansa.', 0),
(@ID, 'esMX', 'Ah sí, el paquete de hierbas de Cañada Umbría. Es una lástima que no lo haya podido traer el propio Porthannius pues él y yo tenemos mucho de qué hablar. No obstante, me alegro de hayas venido a traerme las hierbas.$B$BYa que estás aquí, aprovecha para descansar. $gLos héroes:Las heroínas; han de velar por su fuerza y ánimo, y buscar descanso y solaz cuando sea necesario. Si no se proporciona paz al cuerpo y a la mente, el fracaso es inevitable.$B$BAsí pues... descansa.', 0);
-- 4495 Un buen amigo
-- https://es.classic.wowhead.com/quest=4495
SET @ID := 4495;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. ¿Cómo sabías que estaba aquí?', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. ¿Cómo sabías que estaba aquí?', 0);
-- 458 La protectora de los bosques
-- https://es.classic.wowhead.com/quest=458
SET @ID := 458;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida, $r. Melithar ha hecho bien en enviarte aquí.', 0),
(@ID, 'esMX', 'Te doy la bienvenida, $r. Melithar ha hecho bien en enviarte aquí.', 0);
-- 456 El equilibrio de la naturaleza
-- https://es.classic.wowhead.com/quest=456
SET @ID := 456;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún queda trabajo por hacer, $n. Regresa a mí una vez que hayas reducido las poblaciones de sable de la noche y jabalíes.', 0),
(@ID, 'esMX', 'Aún queda trabajo por hacer, $n. Regresa a mí una vez que hayas reducido las poblaciones de sable de la noche y jabalíes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n.', 0),
(@ID, 'esMX', 'Buen trabajo, $n.', 0);
-- 459 La protectora de los bosques
-- https://es.classic.wowhead.com/quest=459
SET @ID := 459;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Satisface mis sospechas, $n. Tráeme 8 muestras de Musgovil.', 0),
(@ID, 'esMX', 'Satisface mis sospechas, $n. Tráeme 8 muestras de Musgovil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu servicio hacia las criaturas de Cañada Umbría es digno de recompensa, $n.$B$BSin embargo, has confirmado mis temores. Si los grells han sido contaminados por el Musgovil, puedes imaginarte lo que le ha sucedido a la tribu Tuercepinos de fúrbolgs que una vez vivió aquí.$B$BDeberías encontrar tu verdadero talento en Dolanaar, diestr$go:a; $c, busca al sabio druida, Athridas Manto de Oso. Él comparte nuestra preocupación por el bienestar del bosque.', 0),
(@ID, 'esMX', 'Tu servicio hacia las criaturas de Cañada Umbría es digno de recompensa, $n.$B$BSin embargo, has confirmado mis temores. Si los grells han sido contaminados por el Musgovil, puedes imaginarte lo que le ha sucedido a la tribu Tuercepinos de fúrbolgs que una vez vivió aquí.$B$BDeberías encontrar tu verdadero talento en Dolanaar, diestr$go:a; $c, busca al sabio druida, Athridas Manto de Oso. Él comparte nuestra preocupación por el bienestar del bosque.', 0);
-- 457 El equilibrio de la naturaleza
-- https://es.classic.wowhead.com/quest=457
SET @ID := 457;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu tarea no ha concluido, $n. Regresa de nuevo una vez hayas matado a 5 sables de la noche sarnosos y 5 jabalíes cardo.', 0),
(@ID, 'esMX', 'Tu tarea no ha concluido, $n. Regresa de nuevo una vez hayas matado a 5 sables de la noche sarnosos y 5 jabalíes cardo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado una gran dedicación hacia el bién de la naturaleza, $n. A $glos:las; jóvenes como tu les espera un futuro muy prometedor.', 0),
(@ID, 'esMX', 'Has demostrado una gran dedicación hacia el bién de la naturaleza, $n. A $glos:las; jóvenes como tu les espera un futuro muy prometedor.', 0);
-- 3519 Un amigo en apuros
-- https://es.classic.wowhead.com/quest=3519
SET @ID := 3519;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, no! Me preguntaba por qué no había visto hoy a Iverron. Y eso que siempre le he dicho que tuviera cuidado con esas arañas...', 0),
(@ID, 'esMX', '¡Oh, no! Me preguntaba por qué no había visto hoy a Iverron. Y eso que siempre le he dicho que tuviera cuidado con esas arañas...', 0);
-- 3521 El antídoto de Iverron
-- https://es.classic.wowhead.com/quest=3521
SET @ID := 3521;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, reúne los ingredientes, $n. Iverron necesita nuestra ayuda.', 0),
(@ID, 'esMX', 'Por favor, reúne los ingredientes, $n. Iverron necesita nuestra ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a Elune que has conseguido los ingredientes con tanta rapidez!$B$BEn un momento, tendré el antídoto preparado.', 0),
(@ID, 'esMX', '¡Gracias a Elune que has conseguido los ingredientes con tanta rapidez!$B$BEn un momento, tendré el antídoto preparado.', 0);
-- 3522 El antídoto de Iverron
-- https://es.classic.wowhead.com/quest=3522
SET @ID := 3522;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... $n, me alegro de que hayas vuelto.', 0),
(@ID, 'esMX', 'Oh... $n, me alegro de que hayas vuelto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto, $n?$B$B¡Ah, sabía que Dirania podría ayudarme!$B$B<Iverron bebe el antídoto>$B$BSiempre me estoy metiendo en problemas y Dirania... bueno, ella siempre se las arregla para echarme una mano.$B$BYa me siento mucho mejor pero creo que me quedaré aquí sentado un rato hasta que esté totalmente recuperado. Mientras tanto, esperaba que pudieras despejar un camino de esas nocturácnidas sanguinarias...', 0),
(@ID, 'esMX', '¿Qué es esto, $n?$B$B¡Ah, sabía que Dirania podría ayudarme!$B$B<Iverron bebe el antídoto>$B$BSiempre me estoy metiendo en problemas y Dirania... bueno, ella siempre se las arregla para echarme una mano.$B$BYa me siento mucho mejor pero creo que me quedaré aquí sentado un rato hasta que esté totalmente recuperado. Mientras tanto, esperaba que pudieras despejar un camino de esas nocturácnidas sanguinarias...', 0);
-- 917 Huevo de Tejemadera
-- https://es.classic.wowhead.com/quest=917
SET @ID := 917;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Fuiste a la Gruta Narácnida? ¿Tienes el huevo de araña?', 0),
(@ID, 'esMX', '¿Fuiste a la Gruta Narácnida? ¿Tienes el huevo de araña?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendo. Voy a enviarlo a Darnassus, yo me voy a quedar investigando. No sabes cuánto te agradezco tu ayuda, $n.', 0),
(@ID, 'esMX', 'Estupendo. Voy a enviarlo a Darnassus, yo me voy a quedar investigando. No sabes cuánto te agradezco tu ayuda, $n.', 0);
-- 920 Las invocaciones de Tenaron
-- https://es.classic.wowhead.com/quest=920
SET @ID := 920;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, me alegro de verte. Tengo una importante misión para ti.', 0),
(@ID, 'esMX', 'Ah, $n, me alegro de verte. Tengo una importante misión para ti.', 0);
-- 476 Corrupción en Tuercepinos
-- https://es.classic.wowhead.com/quest=476
SET @ID := 476;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por todas las estrellas! ¡Qué noticia tan alarmante!', 0),
(@ID, 'esMX', '¡Por todas las estrellas! ¡Qué noticia tan alarmante!', 0);
-- 489 ¡Búsqueda de redención!
-- https://es.classic.wowhead.com/quest=489
SET @ID := 489;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes para mí, $n? Parece un rico aperitivo...', 0),
(@ID, 'esMX', '¿Qué tienes para mí, $n? Parece un rico aperitivo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué maravilla de $r! Sabía que me serías de ayuda.', 0),
(@ID, 'esMX', '¡Ah, qué maravilla de $r! Sabía que me serías de ayuda.', 0);
-- 483 Las Reliquias del Despertar
-- https://es.classic.wowhead.com/quest=483
SET @ID := 483;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, los druidas de la Garra secuestrados quedarán atrapados por toda la eternidad en el Sueño Esmeralda si no conseguimos las Reliquias del Despertar que se encuentran en el Túmulo de Ban\'ethil, al oeste de aquí.$B$BCada minuto que pasa, están más cerca de su condena eterna.', 0),
(@ID, 'esMX', '$n, los druidas de la Garra secuestrados quedarán atrapados por toda la eternidad en el Sueño Esmeralda si no conseguimos las Reliquias del Despertar que se encuentran en el Túmulo de Ban\'ethil, al oeste de aquí.$B$BCada minuto que pasa, están más cerca de su condena eterna.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido, joven $c! Bien hecho. ¡Y justo a tiempo!', 0),
(@ID, 'esMX', '¡Lo has conseguido, joven $c! Bien hecho. ¡Y justo a tiempo!', 0);
-- 2459 Ferocitas el Comesueños
-- https://es.classic.wowhead.com/quest=2459
SET @ID := 2459;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ferocitas y los místicos Tuercepinos me tienen que devolver lo que es mío. Por favor, recupera la esmeralda para que pueda reparar el atrapasueños esmeralda.', 0),
(@ID, 'esMX', 'Ferocitas y los místicos Tuercepinos me tienen que devolver lo que es mío. Por favor, recupera la esmeralda para que pueda reparar el atrapasueños esmeralda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora ya puedo completar mi atrapasueños. Gracias, $n.', 0),
(@ID, 'esMX', 'Ahora ya puedo completar mi atrapasueños. Gracias, $n.', 0);
-- 918 Semillas de Brezomadera
-- https://es.classic.wowhead.com/quest=918
SET @ID := 918;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las semillas? Estoy deseando plantarlas.', 0),
(@ID, 'esMX', '¿Tienes las semillas? Estoy deseando plantarlas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las has conseguido. ¡Estupendo!$B$BPlantaré estas semillas en una tierra muy especial que he preparado. Creo que las semillas germinarán dando lugar a Brezomadera mucho más dóciles. ¡Quizás más adelante puedas ver el resultado!', 0),
(@ID, 'esMX', 'Las has conseguido. ¡Estupendo!$B$BPlantaré estas semillas en una tierra muy especial que he preparado. Creo que las semillas germinarán dando lugar a Brezomadera mucho más dóciles. ¡Quizás más adelante puedas ver el resultado!', 0);
-- 919 Brotes de Brezomadera
-- https://es.classic.wowhead.com/quest=919
SET @ID := 919;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has encontrado algún brote cerca del agua?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has encontrado algún brote cerca del agua?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es demasiado! Me temo que su número está creciendo peligrosamente. Espero poder descubrir qué está provocando su corrupción.$B$BGracias por tu ayuda, $n. Esta tierra es un lugar más limpio gracias a tus esfuerzos.', 0),
(@ID, 'esMX', '¡Esto es demasiado! Me temo que su número está creciendo peligrosamente. Espero poder descubrir qué está provocando su corrupción.$B$BGracias por tu ayuda, $n. Esta tierra es un lugar más limpio gracias a tus esfuerzos.', 0);
-- 1047 La nueva frontera
-- https://es.classic.wowhead.com/quest=1047
SET @ID := 1047;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos mis insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Porque, POR SUPUESTO, el bienestar de Darnassus o, mejor dicho, el de tooodo Teldrassil, debe quedarse aparcado hasta que tú consigas ese adorno para tu colección.$B$BEsos tontos del Claro de la Luna me hacen perder el tiempo con su petición de ayuda ¿y ahora resulta que tengo que soportar también esto?', 0),
(@ID, 'esMX', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos mis insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Porque, POR SUPUESTO, el bienestar de Darnassus o, mejor dicho, el de tooodo Teldrassil, debe quedarse aparcado hasta que tú consigas ese adorno para tu colección.$B$BEsos tontos del Claro de la Luna me hacen perder el tiempo con su petición de ayuda ¿y ahora resulta que tengo que soportar también esto?', 0);
-- 5091 Un llamamiento a las armas: las Tierras de la Peste
-- https://es.classic.wowhead.com/quest=5091
SET @ID := 5091;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes:las heroínas; dispuestos y capaces en el borde de las Tierras de la Peste.', 0),
(@ID, 'esMX', 'Bienvenido a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes:las heroínas; dispuestos y capaces en el borde de las Tierras de la Peste.', 0);
-- 7494 Bastión Plumaluna
-- https://es.classic.wowhead.com/quest=7494
SET @ID := 7494;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Me alegra verte, aunque me pesa que nuestro encuentro no se dé en circunstancias más agradables.$B$BEscucha con atención, pues tengo una tarea vital que encomendarte...', 0),
(@ID, 'esMX', 'Saludos, $n. Me alegra verte, aunque me pesa que nuestro encuentro no se dé en circunstancias más agradables.$B$BEscucha con atención, pues tengo una tarea vital que encomendarte...', 0);
-- 6761 La nueva frontera
-- https://es.classic.wowhead.com/quest=6761
SET @ID := 6761;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, $c, gracias por venir. Siento el malentendido... el aire está saturado de la desconfianza entre el archidruida y el guardián Rémulos de Claro de la Luna. Cada uno acusa al otro de maquinar algo y el hecho de que las extrañas corrupciones de Teldrassil no remitan no contribuye precisamente a relajar este ambiente de desconfianza.$B$BEn cualquier caso, seguimos teniendo un deber para con el Círculo Cenarion, aunque aquellos que lo lideran no estén de acuerdo entre sí.', 0),
(@ID, 'esMX', 'Sí, $c, gracias por venir. Siento el malentendido... el aire está saturado de la desconfianza entre el archidruida y el guardián Rémulos de Claro de la Luna. Cada uno acusa al otro de maquinar algo y el hecho de que las extrañas corrupciones de Teldrassil no remitan no contribuye precisamente a relajar este ambiente de desconfianza.$B$BEn cualquier caso, seguimos teniendo un deber para con el Círculo Cenarion, aunque aquellos que lo lideran no estén de acuerdo entre sí.', 0);
-- 6762 Rabine Saturna
-- https://es.classic.wowhead.com/quest=6762
SET @ID := 6762;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy Rabine Saturna. Te doy la bienvenida de parte del guardián Rémulos y de los demás habitantes de este sagrado Claro.$B$BAprecio tu interés y tu deseo de asistir al Círculo Cenarion. Sé también que el archidruida de Darnassus te expresó su desprecio por prestarnos ayuda. Puedes estar seguro de que esto es por un bien mayor y de que estarás a salvo de cualquier represalia malvada de la que puedan hacerte objeto.$B$BAquí estás entre amigos, $n.', 0),
(@ID, 'esMX', 'Soy Rabine Saturna. Te doy la bienvenida de parte del guardián Rémulos y de los demás habitantes de este sagrado Claro.$B$BAprecio tu interés y tu deseo de asistir al Círculo Cenarion. Sé también que el archidruida de Darnassus te expresó su desprecio por prestarnos ayuda. Puedes estar seguro de que esto es por un bien mayor y de que estarás a salvo de cualquier represalia malvada de la que puedan hacerte objeto.$B$BAquí estás entre amigos, $n.', 0);

-- 922 Rellian Verdeguja
-- https://es.classic.wowhead.com/quest=922
SET @ID := 922;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola...$B$B¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Hola...$B$B¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, una semilla de Brezomadera! Quería cultivar una de estas semillas para ayudar a Denalan en sus investigaciones...$B$BHasta que descubrí que muchos de los Brezomadera están corruptos y, por lo tanto, también sus semillas. Yo no puedo hacer nada para curarlos.$B$BDenalan tiene mucha mano para las plantas y puede que encuentre una curación para los futuros Brezomadera. Puede que él sea su única esperanza.', 0),
(@ID, 'esMX', '¡Ah, una semilla de Brezomadera! Quería cultivar una de estas semillas para ayudar a Denalan en sus investigaciones...$B$BHasta que descubrí que muchos de los Brezomadera están corruptos y, por lo tanto, también sus semillas. Yo no puedo hacer nada para curarlos.$B$BDenalan tiene mucha mano para las plantas y puede que encuentre una curación para los futuros Brezomadera. Puede que él sea su única esperanza.', 0);
-- 2541 El druida durmiente
-- https://es.classic.wowhead.com/quest=2541
SET @ID := 2541;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si pudiera examinar el talismán, podría descubrir cómo romper el encantamiento. ¿Has encontrado alguno?', 0),
(@ID, 'esMX', 'Si pudiera examinar el talismán, podría descubrir cómo romper el encantamiento. ¿Has encontrado alguno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BQué objeto más extraño... Puedo sentir el aura de maldad que emana de él. Se trata de un potente encantamiento.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BQué objeto más extraño... Puedo sentir el aura de maldad que emana de él. Se trata de un potente encantamiento.', 0);
-- 2561 El druida de la Zarpa
-- https://es.classic.wowhead.com/quest=2561
SET @ID := 2561;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ten cuidado al acercarte a mi representación física; el encantamiento al que está sometida es muy poderoso.', 0),
(@ID, 'esMX', '$n, ten cuidado al acercarte a mi representación física; el encantamiento al que está sometida es muy poderoso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al fin estoy libre del control de los Tuercepinos. Gracias, $n.$B$BAhora mi espíritu podrá descansar en paz para siempre en el Sueño Esmeralda.$B$BQuizás nos volvamos a encontrar algún día, joven $c. De momento, acepta esta recompensa como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Al fin estoy libre del control de los Tuercepinos. Gracias, $n.$B$BAhora mi espíritu podrá descansar en paz para siempre en el Sueño Esmeralda.$B$BQuizás nos volvamos a encontrar algún día, joven $c. De momento, acepta esta recompensa como muestra de mi gratitud.', 0);
-- 930 El fruto resplandeciente
-- https://es.classic.wowhead.com/quest=930
SET @ID := 930;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, parece que tienes algo que contarme. ¿Sabes algo nuevo de los Brezomadera?', 0),
(@ID, 'esMX', '$n, parece que tienes algo que contarme. ¿Sabes algo nuevo de los Brezomadera?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y esto lo encontraste en Teldrassil? Fascinante... Se trata de un fruto exótico. Quizás sus semillas fueran traídas hasta aquí desde un lugar muy lejano. ¡Incluso tan lejano como Azeroth! Hay algo en este fruto... parece que ha reaccionado de modo extraño tras entrar en contacto con la tierra de Teldrassil.$B$BGracias, $n. Ahora, si me disculpas, voy a analizarlo en detalle...', 0),
(@ID, 'esMX', '¿Y esto lo encontraste en Teldrassil? Fascinante... Se trata de un fruto exótico. Quizás sus semillas fueran traídas hasta aquí desde un lugar muy lejano. ¡Incluso tan lejano como Azeroth! Hay algo en este fruto... parece que ha reaccionado de modo extraño tras entrar en contacto con la tierra de Teldrassil.$B$BGracias, $n. Ahora, si me disculpas, voy a analizarlo en detalle...', 0);
-- 486 Ursal el Violento
-- https://es.classic.wowhead.com/quest=486
SET @ID := 486;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros hermanos no pueden ser despertados hasta que Ursal el Violento haya sido asesinado, $n.', 0),
(@ID, 'esMX', 'Nuestros hermanos no pueden ser despertados hasta que Ursal el Violento haya sido asesinado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has demostrado ser $gun:una; $c de gran talento y valentía. $gUn:Una; $r que sigue el camino del honor del modo en que tú lo haces, sin duda alcanzará la gloria en este mundo.', 0),
(@ID, 'esMX', '$n, has demostrado ser $gun:una; $c de gran talento y valentía. $gUn:Una; $r que sigue el camino del honor del modo en que tú lo haces, sin duda alcanzará la gloria en este mundo.', 0);
-- 952 El Páramo de los Ancianos
-- https://es.classic.wowhead.com/quest=952
SET @ID := 952;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! $c, ¿en qué puede ayudarte Onus?', 0),
(@ID, 'esMX', '¡Ah! $c, ¿en qué puede ayudarte Onus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Gracias, $n, aunque es extraño pues parece que el Archidruida siempre es víctima de la presura. El bosque sabe que cada cosa ha de pasar a su debido tiempo y eso Shan\'do Tempestira lo respetaba.', 0),
(@ID, 'esMX', '¡Ah! Gracias, $n, aunque es extraño pues parece que el Archidruida siempre es víctima de la presura. El bosque sabe que cada cosa ha de pasar a su debido tiempo y eso Shan\'do Tempestira lo respetaba.', 0);
-- 3764 Tierra de Un'Goro
-- https://es.classic.wowhead.com/quest=3764
SET @ID := 3764;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, la tierra. El archidruida quiere 20 cargas por aventurero. Y 20 tendrá. ¡Que aquellos que conspiran contra nosotros se pierdan en el camino!', 0),
(@ID, 'esMX', 'Ah, sí, la tierra. El archidruida quiere 20 cargas por aventurero. Y 20 tendrá. ¡Que aquellos que conspiran contra nosotros se pierdan en el camino!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aligera aquí tu preciosa carga, noble $c. Ha debido de ser un gran peso... como el que llevo yo por ser un visionario. Aquí tienes un honorario por tu trabajo, tal y como dictó el propio archidruida.$B$BEl archidruida Corzocelada quiere hablar contigo de nuevo, $n. Pero para la siguiente tarea que te encomiende necesitarás tener los conocimientos de botánica de un oficial. Aunque, si no los tienes, también podrás ayudar al Círculo.', 0),
(@ID, 'esMX', 'Aligera aquí tu preciosa carga, noble $c. Ha debido de ser un gran peso... como el que llevo yo por ser un visionario. Aquí tienes un honorario por tu trabajo, tal y como dictó el propio archidruida.$B$BEl archidruida Corzocelada quiere hablar contigo de nuevo, $n. Pero para la siguiente tarea que te encomiende necesitarás tener los conocimientos de botánica de un oficial. Aunque, si no los tienes, también podrás ayudar al Círculo.', 0);
-- 2520 El Sacrificio de Sathrah
-- https://es.classic.wowhead.com/quest=2520
SET @ID := 2520;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has puesto el sacrificio en la fuente, $n?', 0),
(@ID, 'esMX', '¿Has puesto el sacrificio en la fuente, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pérdida de Lady Sathrah es angustiante pero puede que sea el único modo de que vuelva a nacer con un espíritu renovado.$B$BEsperemos que Elune acepte de buen grado el sacrificio que le has ofrecido.', 0),
(@ID, 'esMX', 'La pérdida de Lady Sathrah es angustiante pero puede que sea el único modo de que vuelva a nacer con un espíritu renovado.$B$BEsperemos que Elune acepte de buen grado el sacrificio que le has ofrecido.', 0);
-- 1199 Cascada Crepuscular
-- https://es.classic.wowhead.com/quest=1199
SET @ID := 1199;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las Caverna de Brazanegra fueron una vez un antiguo templo de los elfos de la noche. Una vez albergó la poza de la luna más poderosa. Quién sabe qué maldad se está gestando ahora a manos del Martillo Crepuscular.$B$B¿Ha hecho algún progreso para deshacerse de su presencia?', 0),
(@ID, 'esMX', 'Las Caverna de Brazanegra fueron una vez un antiguo templo de los elfos de la noche. Una vez albergó la poza de la luna más poderosa. Quién sabe qué maldad se está gestando ahora a manos del Martillo Crepuscular.$B$B¿Ha hecho algún progreso para deshacerse de su presencia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda eres de sangre noble y valiente, $n. El Alba Argenta te felicita por tus esfuerzos contra el mal.', 0),
(@ID, 'esMX', 'Sin duda eres de sangre noble y valiente, $n. El Alba Argenta te felicita por tus esfuerzos contra el mal.', 0);
-- 1198 Buscando a Thaelrid
-- https://es.classic.wowhead.com/quest=1198
SET @ID := 1198;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Shaedlass Guardalbas ha sido muy considerado al enviarte. Sin duda en este corrupto lugar se está tramando un oscuro complot.', 0),
(@ID, 'esMX', 'Shaedlass Guardalbas ha sido muy considerado al enviarte. Sin duda en este corrupto lugar se está tramando un oscuro complot.', 0);
-- 7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362 Un donativo de paño rúnico
-- https://es.classic.wowhead.com/quest=7795
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7795, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7800, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7805, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7811, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7818, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7823, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7824, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7836, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10357, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10362, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7795, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7800, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7805, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7811, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7818, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7823, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7824, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7836, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10357, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10362, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7795, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7800, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7805, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7811, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7818, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7823, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7824, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7836, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10357, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10362, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7795, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7800, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7805, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7811, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7818, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7823, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7824, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7836, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10357, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10362, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0);
-- 7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361 Un donativo de tejido mágico
-- https://es.classic.wowhead.com/quest=7794
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7794, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7799, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7804, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7809, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7817, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7822, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7831, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7835, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10356, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10361, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),

(7794, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7799, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7804, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7809, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7817, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7822, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7831, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7835, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10356, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10361, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7794, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7799, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7804, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7809, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7817, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7822, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7831, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7835, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10356, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10361, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7794, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7799, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7804, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7809, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7817, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7822, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7831, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7835, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10356, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10361, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0);
-- 7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363 Un donativo extra de paño rúnico
-- https://es.classic.wowhead.com/quest=7801
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7796, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7801, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7806, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7812, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7819, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7825, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7832, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7837, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10358, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10363, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7796, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7801, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7806, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7812, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7819, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7825, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7832, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7837, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10358, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10363, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7796, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7801, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7806, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7812, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7819, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7825, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7832, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7837, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10358, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10363, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7796, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7801, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7806, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7812, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7819, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7825, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7832, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7837, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10358, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10363, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0);

-- 2498 Regresa junto a Denalan
-- https://es.classic.wowhead.com/quest=2498
SET @ID := 2498;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, Rellian te ha enviado para que me ayudes! Me alegro de que hayas llegado tan pronto.$B$B¡He descubierto algo bastante alarmante!', 0),
(@ID, 'esMX', '¡Ah, Rellian te ha enviado para que me ayudes! Me alegro de que hayas llegado tan pronto.$B$B¡He descubierto algo bastante alarmante!', 0);
-- 2499 Roblegüello
-- https://es.classic.wowhead.com/quest=2499
SET @ID := 2499;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has localizado ya a Roblegüello, $r?', 0),
(@ID, 'esMX', '¿Has localizado ya a Roblegüello, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que serías capaz de acabar con esa bestia que aterrorizaba el lago.$B$BEstamos ante una penosa situación; Roblegüello fue en su día un gran líder entre los suyos... pero la corrupción no hace distinción entre el pueblo llano y los nobles.$B$BEl tamaño de este tumor es preocupante pero debo estudiarlo en profundidad para averiguar más datos sobre la enfermedad que está asolando a los Brezomadera.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Sabía que serías capaz de acabar con esa bestia que aterrorizaba el lago.$B$BEstamos ante una penosa situación; Roblegüello fue en su día un gran líder entre los suyos... pero la corrupción no hace distinción entre el pueblo llano y los nobles.$B$BEl tamaño de este tumor es preocupante pero debo estudiarlo en profundidad para averiguar más datos sobre la enfermedad que está asolando a los Brezomadera.$B$BGracias, $n.', 0);
-- 3661 ¿Creados por Elune?
-- https://es.classic.wowhead.com/quest=3661
SET @ID := 3661;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Intenta no acercarte a ellos; pueden sentirse amenazados y atacarte.', 0),
(@ID, 'esMX', 'Intenta no acercarte a ellos; pueden sentirse amenazados y atacarte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$B¿Aprendiste algo de esas criaturas?$B$BCon estas plumas sabremos más de su naturaleza.$B$BVoy a estudiarlas; tú dedícate a tus cosas y vuelve a hablar conmigo en otro momento.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$B¿Aprendiste algo de esas criaturas?$B$BCon estas plumas sabremos más de su naturaleza.$B$BVoy a estudiarlas; tú dedícate a tus cosas y vuelve a hablar conmigo en otro momento.', 0);
-- 5250 Estrella Fugaz
-- https://es.classic.wowhead.com/quest=5250
SET @ID := 5250;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿$gUn alumno:Una alumna; de Daryn Lightwind? Encantado de conocerte, $n.', 0),
(@ID, 'esMX', '¿$gUn alumno:Una alumna; de Daryn Lightwind? Encantado de conocerte, $n.', 0);
-- 3524 Varado
-- https://es.classic.wowhead.com/quest=3524
SET @ID := 3524;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace poco que esas criaturas han empezado a llegar a Costa Oscura en números tan alarmantes. No puedo evitar pensar que esto es algún tipo de augurio. Si consiguieras para Darnassus una muestra de los huesos de alguna de esas criaturas, nos ayudarías a entender la situación.', 0),
(@ID, 'esMX', 'Hace poco que esas criaturas han empezado a llegar a Costa Oscura en números tan alarmantes. No puedo evitar pensar que esto es algún tipo de augurio. Si consiguieras para Darnassus una muestra de los huesos de alguna de esas criaturas, nos ayudarías a entender la situación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que el múrloc no te pusiera difícil conseguirnos esto! Me aseguraré de mandar esto a Darnassus en el siguiente hipogrifo. El Templo de la Luna me ha concedido unos fondos para entregar a quien nos ayude. Te entrego una parte con nuestro agradecimiento.$B$BTu éxito me ha animado a ofrecerte la posibilidad de ayudar más al Templo de la Luna, si te interesa...', 0),
(@ID, 'esMX', '¡Espero que el múrloc no te pusiera difícil conseguirnos esto! Me aseguraré de mandar esto a Darnassus en el siguiente hipogrifo. El Templo de la Luna me ha concedido unos fondos para entregar a quien nos ayude. Te entrego una parte con nuestro agradecimiento.$B$BTu éxito me ha animado a ofrecerte la posibilidad de ayudar más al Templo de la Luna, si te interesa...', 0);
-- 1138 Rico marisco
-- https://es.classic.wowhead.com/quest=1138
SET @ID := 1138;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '...cangrejo al limón y cangrejo-sorpresa de Forjaz. Creo que no me dejo nada.$B$BOh, hola, $n. ¿Tienes esos trozos de cangrejo de gran calidad de los que te hablaba?', 0),
(@ID, 'esMX', '...cangrejo al limón y cangrejo-sorpresa de Forjaz. Creo que no me dejo nada.$B$BOh, hola, $n. ¿Tienes esos trozos de cangrejo de gran calidad de los que te hablaba?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, estos trozos de cangrejo de gran calidad son justo lo que necesito. ¡Gracias, $n! Encontré esto pescando hace un tiempo y no lo he usado. Quizás tú puedas darle uso. Desde luego, no podrás usarlo para preparar platos de cangrejo.$B$BYa te he hablado de los cangrejos, ¿verdad?', 0),
(@ID, 'esMX', 'Vaya, estos trozos de cangrejo de gran calidad son justo lo que necesito. ¡Gracias, $n! Encontré esto pescando hace un tiempo y no lo he usado. Quizás tú puedas darle uso. Desde luego, no podrás usarlo para preparar platos de cangrejo.$B$BYa te he hablado de los cangrejos, ¿verdad?', 0);
-- 1141 La familia y la caña de pescar
-- https://es.classic.wowhead.com/quest=1141
SET @ID := 1141;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con los meros de Costa Oscura se pueden preparar muchos platos muy buenos. Están muy ricos. Pero a mí me gusta más pescarlos.$B$B¿Tú has pescado alguno ya?', 0),
(@ID, 'esMX', 'Con los meros de Costa Oscura se pueden preparar muchos platos muy buenos. Están muy ricos. Pero a mí me gusta más pescarlos.$B$B¿Tú has pescado alguno ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estos meros son estupendos, $n! ¡Gracias por ayudarme!$B$BEres como mínimo, tan buen pescador como mi prima, Graun Blump. Ella también tiene barba y huele un poco raro, pero eso no le impide cazar como una diosa. Está claro que tienes lo que hace falta para utilizar una caña de pescar de la familia Blump.', 0),
(@ID, 'esMX', '¡Estos meros son estupendos, $n! ¡Gracias por ayudarme!$B$BEres como mínimo, tan buen pescador como mi prima, Graun Blump. Ella también tiene barba y huele un poco raro, pero eso no le impide cazar como una diosa. Está claro que tienes lo que hace falta para utilizar una caña de pescar de la familia Blump.', 0);
-- 963 Un amor eterno
-- https://es.classic.wowhead.com/quest=963
SET @ID := 963;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con una gran pena en el corazón, seguí a Shan\'do Tempestira en su hibernación y arrastré mi pena en mis sueños durante miles de años.', 0),
(@ID, 'esMX', 'Con una gran pena en el corazón, seguí a Shan\'do Tempestira en su hibernación y arrastré mi pena en mis sueños durante miles de años.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Quizás habría sido mejor... que lo hubiera hecho yo. Pero incluso después de tantos milenios, no podía soportar la idea de alzar mi mano contra mi amada.$B$BPor favor, déjame a solas con mi dolor...', 0),
(@ID, 'esMX', 'Gracias, $n. Quizás habría sido mejor... que lo hubiera hecho yo. Pero incluso después de tantos milenios, no podía soportar la idea de alzar mi mano contra mi amada.$B$BPor favor, déjame a solas con mi dolor...', 0);
-- 983 La caja mecánica 827
-- https://es.classic.wowhead.com/quest=983
SET @ID := 983;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica 827 guarda un inquietante silencio. Un destello luminoso indica que hay que colocar 6 patas de reptador en su soporte.', 0),
(@ID, 'esMX', 'La caja mecánica 827 guarda un inquietante silencio. Un destello luminoso indica que hay que colocar 6 patas de reptador en su soporte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando introduces las patas de reptador en la máquina, oyes chirriar sus engranajes. A juzgar por los sonidos que provienen de la caja mecánica, parece que las patas de reptador están colocándose en su sitio. La máquina empieza a zumbar y luego oyes una vocecita.$B$B"¿Hola? Eeh... ¡Hola! ¡La has arreglado! ¡Por cierto, esta es Zumbang! ¡Muchas gracias! Oye, ¿te apetecería reparar otra...?"', 0),
(@ID, 'esMX', 'Cuando introduces las patas de reptador en la máquina, oyes chirriar sus engranajes. A juzgar por los sonidos que provienen de la caja mecánica, parece que las patas de reptador están colocándose en su sitio. La máquina empieza a zumbar y luego oyes una vocecita.$B$B"¿Hola? Eeh... ¡Hola! ¡La has arreglado! ¡Por cierto, esta es Zumbang! ¡Muchas gracias! Oye, ¿te apetecería reparar otra...?"', 0);
-- 1579 Mecanismos eléctricos
-- https://es.classic.wowhead.com/quest=1579
SET @ID := 1579;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mis mecanismos eléctricos, $n? ¡Sin mis mecanismos eléctricos no puedo ajustarme las clavijas!', 0),
(@ID, 'esMX', '¿Has encontrado mis mecanismos eléctricos, $n? ¡Sin mis mecanismos eléctricos no puedo ajustarme las clavijas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo creer que los hayas encontrado! ¡Eres sin duda $gel:la; $r más $gafortunado:afortunada; de Kalimdor!', 0),
(@ID, 'esMX', '¡No puedo creer que los hayas encontrado! ¡Eres sin duda $gel:la; $r más $gafortunado:afortunada; de Kalimdor!', 0);
-- 4740 SE BUSCA: ¡Viscoso!
-- https://es.classic.wowhead.com/quest=4740
SET @ID := 4740;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos $c. ¿En qué pueden ayudarte los Centinelas hoy? ¿Quizás estás aquí para preguntar por la recompensa por Viscoso?', 0),
(@ID, 'esMX', 'Saludos $c. ¿En qué pueden ayudarte los Centinelas hoy? ¿Quizás estás aquí para preguntar por la recompensa por Viscoso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, diría que no has venido aquí solo a informarte! Los ciudadanos estarán encantados de saber que hoy podrán dormir un poco más tranquilos.$B$BHas traído un poco de paz y justicia a la gente de Auberdine, $n y por eso, quisiera ofrecerte esto como recompensa... Serás $gel héroe:la heroína; de las gentes de Auberdine.', 0),
(@ID, 'esMX', '¡Vaya, diría que no has venido aquí solo a informarte! Los ciudadanos estarán encantados de saber que hoy podrán dormir un poco más tranquilos.$B$BHas traído un poco de paz y justicia a la gente de Auberdine, $n y por eso, quisiera ofrecerte esto como recompensa... Serás $gel héroe:la heroína; de las gentes de Auberdine.', 0);
-- 947 La cueva de las setas
-- https://es.classic.wowhead.com/quest=947
SET @ID := 947;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis champiñones, $n? ¿Has estado en la cueva?', 0),
(@ID, 'esMX', '¿Tienes mis champiñones, $n? ¿Has estado en la cueva?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Estos champiñones son unos especímenes estupendos!$B$BOye, mientras estabas en el Salto de Fonroca, ¿encontraste algo que confirmara las preocupaciones de los Ancestros?$B$BLos Ancestros son sabios, pero esperaba que esta vez estuvieran equivocados.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Estos champiñones son unos especímenes estupendos!$B$BOye, mientras estabas en el Salto de Fonroca, ¿encontraste algo que confirmara las preocupaciones de los Ancestros?$B$BLos Ancestros son sabios, pero esperaba que esta vez estuvieran equivocados.', 0);
-- 4811 El cristal rojo
-- https://es.classic.wowhead.com/quest=4811
SET @ID := 4811;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes que informar sobre ese cristal rojo? ¿Existe realmente?', 0),
(@ID, 'esMX', '¿Qué tienes que informar sobre ese cristal rojo? ¿Existe realmente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que el cristal existe, $n. Fascinante... Bien, bien, ¡has hecho un buen trabajo!$B$B¿Y qué es exactamente ese cristal? Esta es solo una pregunta de las muchas que me vienen a la cabeza. Otra sería: ¿por qué los lechúcicos lunares se sienten atraídos por este objeto...? ¿El cristal es de naturaleza benigna o tiene un propósito más siniestro?$B$BY tengo más preguntas, pero será mejor examinar bien el cristal, a ver si las responde.', 0),
(@ID, 'esMX', 'Así que el cristal existe, $n. Fascinante... Bien, bien, ¡has hecho un buen trabajo!$B$B¿Y qué es exactamente ese cristal? Esta es solo una pregunta de las muchas que me vienen a la cabeza. Otra sería: ¿por qué los lechúcicos lunares se sienten atraídos por este objeto...? ¿El cristal es de naturaleza benigna o tiene un propósito más siniestro?$B$BY tengo más preguntas, pero será mejor examinar bien el cristal, a ver si las responde.', 0);
-- 729 El prospector despistado
-- https://es.classic.wowhead.com/quest=729
SET @ID := 729;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hollee, eres tú? Necesito ayuda con esta piedra. Pásame mi cepillo, creo que veo algo.$B$B¡Oye, tú no eres Hollee! ¿No habrás visto mi cepillo de piedra?$B$B¡Eso no importa ahora! Prometí a la Liga que enviaría el misterioso fósil que encontré. ¿Adónde se fue Hollee?$B$B¡Con todo lo que queda por hacer! En fin... ¿y dónde estará ese fósil misterioso? ¿Y mi cepillo...? ¿Y Hollee?$B$B¿Y tú quien eres? En realidad no importa, siempre que estés aquí para ayudar.$B$BAvísame cuando estés listo para empezar a buscar.', 0),
(@ID, 'esMX', '¿Hollee, eres tú? Necesito ayuda con esta piedra. Pásame mi cepillo, creo que veo algo.$B$B¡Oye, tú no eres Hollee! ¿No habrás visto mi cepillo de piedra?$B$B¡Eso no importa ahora! Prometí a la Liga que enviaría el misterioso fósil que encontré. ¿Adónde se fue Hollee?$B$B¡Con todo lo que queda por hacer! En fin... ¿y dónde estará ese fósil misterioso? ¿Y mi cepillo...? ¿Y Hollee?$B$B¿Y tú quien eres? En realidad no importa, siempre que estés aquí para ayudar.$B$BAvísame cuando estés listo para empezar a buscar.', 0);
-- 1001 La caja mecánica 411
-- https://es.classic.wowhead.com/quest=1001
SET @ID := 1001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cubierta de la máquina está abierta y parece estar esperando a que introduzcas 3 ojos de trillador.', 0),
(@ID, 'esMX', 'La cubierta de la máquina está abierta y parece estar esperando a que introduzcas 3 ojos de trillador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica cobra vida en cuanto introduces los ojos de trillador. Después de un lapso de tiempo, oyes una vocecilla familiar...$B$B"El vino de reptador es lo mejor..." *hip*$B$B"¿Eh? Oh, ¿ya la has arreglado? Vaya, sí que eres $grápido:rápida;. Dime, ¿quieres arreglar otra caja?"$B$BOyes lo que parece el sonido de un líquido vertiéndose en una copa y luego ruidos ansiosos de alguien tragando.', 0),
(@ID, 'esMX', 'La caja mecánica cobra vida en cuanto introduces los ojos de trillador. Después de un lapso de tiempo, oyes una vocecilla familiar...$B$B"El vino de reptador es lo mejor..." *hip*$B$B"¿Eh? Oh, ¿ya la has arreglado? Vaya, sí que eres $grápido:rápida;. Dime, ¿quieres arreglar otra caja?"$B$BOyes lo que parece el sonido de un líquido vertiéndose en una copa y luego ruidos ansiosos de alguien tragando.', 0);
-- 1580 Los electromuelles
-- https://es.classic.wowhead.com/quest=1580
SET @ID := 1580;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste algún electromuelle? Los necesito para continuar mis pruebas con el señuelo-pato...', 0),
(@ID, 'esMX', '¿Encontraste algún electromuelle? Los necesito para continuar mis pruebas con el señuelo-pato...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo creerlo! ¡Los has encontrado! ¡Eres el mejor pescador que he conocido en mi vida!$B$BGracias, $n. Y ten, acepta esto. Aunque eres tan bueno que probablemente no te hacen falta, te ayudarán.', 0),
(@ID, 'esMX', '¡No puedo creerlo! ¡Los has encontrado! ¡Eres el mejor pescador que he conocido en mi vida!$B$BGracias, $n. Y ten, acepta esto. Aunque eres tan bueno que probablemente no te hacen falta, te ayudarán.', 0);
-- 4681 Varado
-- https://es.classic.wowhead.com/quest=4681
SET @ID := 4681;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas examinado los restos de la criatura que hay en el agua, al oeste de aquí, debería poder redactar un informe para el Templo de la Luna de Darnassus. Quizás entonces estemos más cerca de descubrir la razón por la que estas desafortunadas criaturas eligen acabar sus vidas encalladas en Costa Oscura.', 0),
(@ID, 'esMX', 'Cuando hayas examinado los restos de la criatura que hay en el agua, al oeste de aquí, debería poder redactar un informe para el Templo de la Luna de Darnassus. Quizás entonces estemos más cerca de descubrir la razón por la que estas desafortunadas criaturas eligen acabar sus vidas encalladas en Costa Oscura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sido una ayuda tremenda hoy. Ahora tenemos una buena oportunidad de descubrir el misterio, de saber por qué estas criaturas eligen encallarse en Costa Oscura. La idea de que podrían estar huyendo de Teldrassil es inquietante. Si encontraras más en tus viajes, házmelo saber. Nuestra investigación aquí apenas ha comenzado.$B$BPor favor, acepta esto como muestra de agradecimiento del Templo de la Luna, $n. ¡Gracias!', 0),
(@ID, 'esMX', 'Has sido una ayuda tremenda hoy. Ahora tenemos una buena oportunidad de descubrir el misterio, de saber por qué estas criaturas eligen encallarse en Costa Oscura. La idea de que podrían estar huyendo de Teldrassil es inquietante. Si encontraras más en tus viajes, házmelo saber. Nuestra investigación aquí apenas ha comenzado.$B$BPor favor, acepta esto como muestra de agradecimiento del Templo de la Luna, $n. ¡Gracias!', 0);
-- 1275 Investigaciones acerca de la corrupción
-- https://es.classic.wowhead.com/quest=1275
SET @ID := 1275;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tenga suficientes muestras, podré empezar a trabajar de verdad. Con los bulbos raquídeos corruptos de los sátiros y los nagass de las Cavernas Anegadas podré encontrar la correlación entre las mutaciones.$B$BQuizás, una vez identificada, podré impedir que la deformidad y el mal arraiguen más en los elfos de sangre.', 0),
(@ID, 'esMX', 'Cuando tenga suficientes muestras, podré empezar a trabajar de verdad. Con los bulbos raquídeos corruptos de los sátiros y los nagass de las Cavernas Anegadas podré encontrar la correlación entre las mutaciones.$B$BQuizás, una vez identificada, podré impedir que la deformidad y el mal arraiguen más en los elfos de sangre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has viajado lejos y sin duda, habrás afrontado grandes peligros.$B$BTus acciones son desinteresadas; $n; me ayudas con mi trabajo por el bien de todo Azeroth. Y te doy las gracias por todo lo que has hecho.$B$BAhora, si me perdonas, tengo mucho que hacer...', 0),
(@ID, 'esMX', 'Has viajado lejos y sin duda, habrás afrontado grandes peligros.$B$BTus acciones son desinteresadas; $n; me ayudas con mi trabajo por el bien de todo Azeroth. Y te doy las gracias por todo lo que has hecho.$B$BAhora, si me perdonas, tengo mucho que hacer...', 0);
-- 2178 Guiso de zancudo
-- https://es.classic.wowhead.com/quest=2178
SET @ID := 2178;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta olla está vacía y mi estómago también! ¿Por qué estás tardando tanto?', 0),
(@ID, 'esMX', '¡Esta olla está vacía y mi estómago también! ¿Por qué estás tardando tanto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡Dime lo que piensas, $n!', 0),
(@ID, 'esMX', '¡Fantástico! ¡Dime lo que piensas, $n!', 0);
-- 4812 Agua en cascada
-- https://es.classic.wowhead.com/quest=4812
SET @ID := 4812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cristal contrasta extrañamente con el escenario leñoso de Costa Oscura. Te parece oír un suave murmullo de su interior.', 0),
(@ID, 'esMX', 'El cristal contrasta extrañamente con el escenario leñoso de Costa Oscura. Te parece oír un suave murmullo de su interior.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has conseguido llegar una vez más al misterioso cristal. Retiras el tapón del tubo de agua de poza de la luna y viertes su contenido sobre el cristal. A medida que el agua se desliza por su entramado, ves que la superficie empieza a volverse transparente...', 0),
(@ID, 'esMX', 'Has conseguido llegar una vez más al misterioso cristal. Retiras el tapón del tubo de agua de poza de la luna y viertes su contenido sobre el cristal. A medida que el agua se desliza por su entramado, ves que la superficie empieza a volverse transparente...', 0);
-- 954 Bashal'Aran
-- https://es.classic.wowhead.com/quest=954
SET @ID := 954;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aah... Me pregunto a qué debo este increíblemente especial honor de disfrutar de la compañía de alguien como tú. Pues he de reconocer que si se compara con mi compañía actual –sin ánimo de ofender a mis anfitriones, los nobles grells y sátiros– tu presencia aquí podría considerarse una increíble mejora.$B$BPor favor, no permitas que mi zafia lengua te aleje. Han pasado años, incluso décadas, desde la última vez que gocé de compañía civilizada.', 0),
(@ID, 'esMX', 'Aah... Me pregunto a qué debo este increíblemente especial honor de disfrutar de la compañía de alguien como tú. Pues he de reconocer que si se compara con mi compañía actual –sin ánimo de ofender a mis anfitriones, los nobles grells y sátiros– tu presencia aquí podría considerarse una increíble mejora.$B$BPor favor, no permitas que mi zafia lengua te aleje. Han pasado años, incluso décadas, desde la última vez que gocé de compañía civilizada.', 0);
-- 958 Las herramientas de los Altonato
-- https://es.classic.wowhead.com/quest=958
SET @ID := 958;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, si el cataclismo que destruyó nuestro mundo hubiera destruido también las herramientas de su destrucción... Pero no fue así. Y debemos asegurarnos de que los horrores de nuestro pasado no se repitan en el futuro.', 0),
(@ID, 'esMX', 'Ay, si el cataclismo que destruyó nuestro mundo hubiera destruido también las herramientas de su destrucción... Pero no fue así. Y debemos asegurarnos de que los horrores de nuestro pasado no se repitan en el futuro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque seguramente es producto de mi imaginación, casi me parece sentir la corrupción de la magia de los altonatos en estas reliquias. Haré que sean destruidas, para que el mal que duerme en ellas nunca vuelva a aflorar.', 0),
(@ID, 'esMX', 'Aunque seguramente es producto de mi imaginación, casi me parece sentir la corrupción de la magia de los altonatos en estas reliquias. Haré que sean destruidas, para que el mal que duerme en ellas nunca vuelva a aflorar.', 0);
-- 1442 La búsqueda de la gema Kor
-- https://es.classic.wowhead.com/quest=1442
SET @ID := 1442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Confiaría menos en alguien que no esté en un camino sagrado si vinieran a preguntar por una gema Kor. Pero confío en los de tu especie más que en algunos de los míos. No juzgo toda su orden basándome en las acciones de solo uno de los caídos.', 0),
(@ID, 'esMX', 'Confiaría menos en alguien que no esté en un camino sagrado si vinieran a preguntar por una gema Kor. Pero confío en los de tu especie más que en algunos de los míos. No juzgo toda su orden basándome en las acciones de solo uno de los caídos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ésta es, de hecho, la gema que Fontana desea, pero antes de que pueda entregársela, debe purificarse de la corrupción: las mujeres naga imbuyen las gemas con poder, eso es cierto, pero de su propia clase malvada.$B$BHazle saber a Fontana que su poder está intacto y que debería funcionar bien para cualquier ritual del que desee que forme parte.$B$BEspero que sepas lo que estás haciendo, $c, esta gema no es un simple objeto.', 0),
(@ID, 'esMX', 'Ésta es, de hecho, la gema que Fontana desea, pero antes de que pueda entregársela, debe purificarse de la corrupción: las mujeres naga imbuyen las gemas con poder, eso es cierto, pero de su propia clase malvada.$B$BHazle saber a Fontana que su poder está intacto y que debería funcionar bien para cualquier ritual del que desee que forme parte.$B$BEspero que sepas lo que estás haciendo, $c, esta gema no es un simple objeto.', 0);

-- 10752 A Vallefresno
-- https://es.classic.wowhead.com/quest=10752
SET @ID := 10752;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces Thundris Tejevientos todavía cree que necesito que me cuiden? Tendré que recordarle quién salvó a quién; parece olvidar que fui yo quien lo sacó del camino del peligro.$B$BBueno, ahora que estás aquí, $r, quizás pueda encontrar algo que puedas hacer.', 0),
(@ID, 'esMX', '¿Entonces Thundris Tejevientos todavía cree que necesito que me cuiden? Tendré que recordarle quién salvó a quién; parece olvidar que fui yo quien lo sacó del camino del peligro.$B$BBueno, ahora que estás aquí, $r, quizás pueda encontrar algo que puedas hacer.', 0);
-- 982 Profundo océano, mar inmenso
-- https://es.classic.wowhead.com/quest=982
SET @ID := 982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los capitanes de esas naves eran buenos elfos de la noche. Merecen un destino mejor del que tuvieron. Atender sus efectos personales sería la mejor forma de dar paz a sus espíritus.', 0),
(@ID, 'esMX', 'Los capitanes de esas naves eran buenos elfos de la noche. Merecen un destino mejor del que tuvieron. Atender sus efectos personales sería la mejor forma de dar paz a sus espíritus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un gran servicio a Auberdine, $gmuchacho:muchacha;. Cuidaremos bien de sus efectos.$B$BPor favor, acepta esto. Es lo mínimo que puedo hacer por alguien que ha tenido el valor suficiente para enmendar esta situación.', 0),
(@ID, 'esMX', 'Has hecho un gran servicio a Auberdine, $gmuchacho:muchacha;. Cuidaremos bien de sus efectos.$B$BPor favor, acepta esto. Es lo mínimo que puedo hacer por alguien que ha tenido el valor suficiente para enmendar esta situación.', 0);
-- 953 La caída de Ameth'Aran
-- https://es.classic.wowhead.com/quest=953
SET @ID := 953;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas estudiado las tablillas y te hayas enterado de la caída de Ameth\'Aran, llevaré el conocimiento a Auberdine e informaré al Círculo de Antiguos.', 0),
(@ID, 'esMX', 'Cuando hayas estudiado las tablillas y te hayas enterado de la caída de Ameth\'Aran, llevaré el conocimiento a Auberdine e informaré al Círculo de Antiguos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos poca información del tiempo de La guerra de los Ancestros y menos aún de la destrucción del Pozo de la Eternidad. Considerando la agitación y el caos que provocaron los acontecimientos que tenían lugar entonces, no es de sorprender.$B$BGracias, $n. Con tu ayuda, pronto acabaré mi trabajo y podré entregar un informe completo al Círculo.', 0),
(@ID, 'esMX', 'Tenemos poca información del tiempo de La guerra de los Ancestros y menos aún de la destrucción del Pozo de la Eternidad. Considerando la agitación y el caos que provocaron los acontecimientos que tenían lugar entonces, no es de sorprender.$B$BGracias, $n. Con tu ayuda, pronto acabaré mi trabajo y podré entregar un informe completo al Círculo.', 0);
-- 4813 Los trozos del interior
-- https://es.classic.wowhead.com/quest=4813
SET @ID := 4813;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, parece que aunque sabemos algo más sobre el cristal, ¡solo hemos conseguido acumular más preguntas sin respuesta!$B$BLlevaré la información que has reunido al Concejo de Auberdine. Quizás ellos sepan qué tenemos que hacer con este cristal. Eso, claro está, suponiendo que tengamos que hacer algo porque, por ahora, es una amenaza muy lejana y no creo que nos alcance.$B$BPor favor, acepta esto. Considéralo una recompensa por un trabajo bien hecho, $n.', 0),
(@ID, 'esMX', 'Vaya, parece que aunque sabemos algo más sobre el cristal, ¡solo hemos conseguido acumular más preguntas sin respuesta!$B$BLlevaré la información que has reunido al Concejo de Auberdine. Quizás ellos sepan qué tenemos que hacer con este cristal. Eso, claro está, suponiendo que tengamos que hacer algo porque, por ahora, es una amenaza muy lejana y no creo que nos alcance.$B$BPor favor, acepta esto. Considéralo una recompensa por un trabajo bien hecho, $n.', 0);
-- 955 Bashal'Aran
-- https://es.classic.wowhead.com/quest=955
SET @ID := 955;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tenga los pendientes, lanzaré el hechizo para localizar el sello que me ata. Llevo siglos soñando con la libertad que alcanzaría destruyendo el sello... Quizás todos esos siglos han dejado mella en mi mente... algo de lo que podría no recuperarme jamás...', 0),
(@ID, 'esMX', 'Cuando tenga los pendientes, lanzaré el hechizo para localizar el sello que me ata. Llevo siglos soñando con la libertad que alcanzaría destruyendo el sello... Quizás todos esos siglos han dejado mella en mi mente... algo de lo que podría no recuperarme jamás...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... los grells de Bashal\'Aran no poseen lo que estoy buscando... pero han entrado en contacto con ello recientemente, sin duda. Recientemente... en tu escala del tiempo, no en la mía. Porque los acontecimientos que para mí son recientes, para ti se pierden en la niebla del pasado, en una Era de la que ni siquiera has oído hablar...', 0),
(@ID, 'esMX', 'Vaya... los grells de Bashal\'Aran no poseen lo que estoy buscando... pero han entrado en contacto con ello recientemente, sin duda. Recientemente... en tu escala del tiempo, no en la mía. Porque los acontecimientos que para mí son recientes, para ti se pierden en la niebla del pasado, en una Era de la que ni siquiera has oído hablar...', 0);
-- 956 Bashal'Aran
-- https://es.classic.wowhead.com/quest=956
SET @ID := 956;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilares de este santuario son para mí como los barrotes de una prisión, $n. Las fuerzas que me queden no podrán quebrarlos, y tampoco me queda magia que podría lograrlo...$B$BMás de mil años he pasado observándolos, preguntándome si quedaría libre al final, si yo sobreviviera a la piedra... ¿O quedaría igualmente atrapado por unos barrotes invisibles?', 0),
(@ID, 'esMX', 'Los pilares de este santuario son para mí como los barrotes de una prisión, $n. Las fuerzas que me queden no podrán quebrarlos, y tampoco me queda magia que podría lograrlo...$B$BMás de mil años he pasado observándolos, preguntándome si quedaría libre al final, si yo sobreviviera a la piedra... ¿O quedaría igualmente atrapado por unos barrotes invisibles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es duro saber que esto que ahora contemplo me ha retenido tanto tiempo... Pero no nos entretengamos, $n. Cuando el sello haya sido destruido, podré volver a caminar por los bosques libremente.', 0),
(@ID, 'esMX', 'Es duro saber que esto que ahora contemplo me ha retenido tanto tiempo... Pero no nos entretengamos, $n. Cuando el sello haya sido destruido, podré volver a caminar por los bosques libremente.', 0);
-- 957 Bashal'Aran
-- https://es.classic.wowhead.com/quest=957
SET @ID := 957;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En verdad, $n, me temo... Tengo miedo de que tu venida, todo esto, sea meramente producto de una mente trastornada. ¿Puedes conocer la tortura que es esto? Yo... Por favor, debes ir rápido.', 0),
(@ID, 'esMX', 'En verdad, $n, me temo... Tengo miedo de que tu venida, todo esto, sea meramente producto de una mente trastornada. ¿Puedes conocer la tortura que es esto? Yo... Por favor, debes ir rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy libre, $n. Ahora puedo ver con mis propios ojos los cambios que ha sufrido nuestro mundo... Solo había percibido una pequeña parte de ellos. Y pensar que la última vez que caminaba libre, la poza aún existía y los altonatos se reunían en la corte de Azshara, nuestra amada reina.$B$BSiento que mi carcelero, mi antiguo maestro, Athrikus, aún vive... Mi desesperanza empieza a tornarse en deseos de venganza...', 0),
(@ID, 'esMX', 'Soy libre, $n. Ahora puedo ver con mis propios ojos los cambios que ha sufrido nuestro mundo... Solo había percibido una pequeña parte de ellos. Y pensar que la última vez que caminaba libre, la poza aún existía y los altonatos se reunían en la corte de Azshara, nuestra amada reina.$B$BSiento que mi carcelero, mi antiguo maestro, Athrikus, aún vive... Mi desesperanza empieza a tornarse en deseos de venganza...', 0);
-- 4723 Criatura marina varada
-- https://es.classic.wowhead.com/quest=4723
SET @ID := 4723;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás un día encontremos la forma de impedir que esas pobres criaturas acaben sus vidas en Costa Oscura de forma tan trágica e inútil. Hasta entonces, ¡debemos seguir investigando!$B$BSaludos, $n, ¿qué noticias traes?', 0),
(@ID, 'esMX', 'Quizás un día encontremos la forma de impedir que esas pobres criaturas acaben sus vidas en Costa Oscura de forma tan trágica e inútil. Hasta entonces, ¡debemos seguir investigando!$B$BSaludos, $n, ¿qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Otro descubrimiento! ¡Bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0),
(@ID, 'esMX', '¡Otro descubrimiento! ¡Bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0);
-- 1002 La caja mecánica 323
-- https://es.classic.wowhead.com/quest=1002
SET @ID := 1002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque aún no has colocado los 6 colmillos de Acechalunas, te parece oír unos sonidos estáticos y un farfulleo de gnomo saliendo de la máquina. ¿Alguien la habrá arreglado ya?', 0),
(@ID, 'esMX', 'Aunque aún no has colocado los 6 colmillos de Acechalunas, te parece oír unos sonidos estáticos y un farfulleo de gnomo saliendo de la máquina. ¿Alguien la habrá arreglado ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica se activa de repente y oyes sonidos de dientes que se pulverizan en su interior.$B$B"¡Ashí que lo hash conseguido! Esh una notishia excelente... Entonshesh... ¿Por qué no shiguesh con lo tuyo? ¡Oh! ¡A no sher que quierash otro encarguito!"', 0),
(@ID, 'esMX', 'La caja mecánica se activa de repente y oyes sonidos de dientes que se pulverizan en su interior.$B$B"¡Ashí que lo hash conseguido! Esh una notishia excelente... Entonshesh... ¿Por qué no shiguesh con lo tuyo? ¡Oh! ¡A no sher que quierash otro encarguito!"', 0);
-- 1003 La caja mecánica 525
-- https://es.classic.wowhead.com/quest=1003
SET @ID := 1003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que la caja mecánica 525 está cantando.$B$B"El vino de reptador esh dulce, la cerveza de trillador esh mejor y el licor de luna tiene un gran shabor. Pero nada hay másh reconfortante que la cerveza de Oso Cardo, ¡y pronto tendré una jarra en la mano!"$B$BLa cubierta está abierta y espera los 4 pellejos canosos mientras la caja mecánica repite su canción una y otra vez.', 0),
(@ID, 'esMX', 'Parece que la caja mecánica 525 está cantando.$B$B"El vino de reptador esh dulce, la cerveza de trillador esh mejor y el licor de luna tiene un gran shabor. Pero nada hay másh reconfortante que la cerveza de Oso Cardo, ¡y pronto tendré una jarra en la mano!"$B$BLa cubierta está abierta y espera los 4 pellejos canosos mientras la caja mecánica repite su canción una y otra vez.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"¿Ashí que metishte losh pellejosh? Esho esh eshtupendo... ¿Qué? Ah, eshte.. claro, te hash dado cuenta de puedo hablar contigo shin losh materialesh en la máquina, te mentí un poco. ¡Pero eshtaba diciendo la verdad cuando te dije que estaban rotash!$B$BEsh que, verásh, ademásh de sher herramientash de comunicación, lash cajash mecánicash deshtilan un licor eshtupendo. Shiento haberte engañado, pero esh que a losh elfosh de la noche no lesh gushta que mi licor pashe por shu ciudad. Pushe algo eshpecial en eshta caja para demoshtrarte mi gratitud por tush eshfuerzosh. ¡Que te gushte!"', 0),
(@ID, 'esMX', '"¿Ashí que metishte losh pellejosh? Esho esh eshtupendo... ¿Qué? Ah, eshte.. claro, te hash dado cuenta de puedo hablar contigo shin losh materialesh en la máquina, te mentí un poco. ¡Pero eshtaba diciendo la verdad cuando te dije que estaban rotash!$B$BEsh que, verásh, ademásh de sher herramientash de comunicación, lash cajash mecánicash deshtilan un licor eshtupendo. Shiento haberte engañado, pero esh que a losh elfosh de la noche no lesh gushta que mi licor pashe por shu ciudad. Pushe algo eshpecial en eshta caja para demoshtrarte mi gratitud por tush eshfuerzosh. ¡Que te gushte!"', 0);
-- 984 La extensión de la amenaza
-- https://es.classic.wowhead.com/quest=984
SET @ID := 984;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una noticia terrible, $n.$B$BCon los furbolgs tan cerca de Auberdine, tendremos que prepararnos para lo inevitable.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Es una noticia terrible, $n.$B$BCon los furbolgs tan cerca de Auberdine, tendremos que prepararnos para lo inevitable.$B$BGracias, $n.', 0);
-- 965 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=965
SET @ID := 965;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Elissa? Son buenas nuevas. Yo tengo noticias preocupantes que transmitirle y no he tenido forma de hacérselas llegar.', 0),
(@ID, 'esMX', '¿Te envía Elissa? Son buenas nuevas. Yo tengo noticias preocupantes que transmitirle y no he tenido forma de hacérselas llegar.', 0);
-- 2118 Tierras apestadas
-- https://es.classic.wowhead.com/quest=2118
SET @ID := 2118;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído el animal enfermo, $n?$B$BSi no logras lanzar la trampa, no te preocupes: la esperanza de Tharnariun es eterna. Si necesitas otra trampa, vuelve y pídela.', 0),
(@ID, 'esMX', '¿Me has traído el animal enfermo, $n?$B$BSi no logras lanzar la trampa, no te preocupes: la esperanza de Tharnariun es eterna. Si necesitas otra trampa, vuelve y pídela.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro trabajo apenas ha empezado, $n. ¿Estás preparado para tu siguiente tarea?', 0),
(@ID, 'esMX', 'Nuestro trabajo apenas ha empezado, $n. ¿Estás preparado para tu siguiente tarea?', 0);
-- 948 Onus
-- https://es.classic.wowhead.com/quest=948
SET @ID := 948;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Estás aquí.$B$BBien.$B$BTenemos asuntos que discutir tú y yo.', 0),
(@ID, 'esMX', '$n. Estás aquí.$B$BBien.$B$BTenemos asuntos que discutir tú y yo.', 0);
-- 2138 La limpieza de la infección
-- https://es.classic.wowhead.com/quest=2138
SET @ID := 2138;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu tarea está completa?', 0),
(@ID, 'esMX', '¿Tu tarea está completa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un gran servicio a Auberdine, $n, pero aún no has acabado tu cometido.$B$BDescansa un poco y vuelve.$B$BY..., $n, prepara tu mente y tu alma para más derramamientos de sangre.', 0),
(@ID, 'esMX', 'Has hecho un gran servicio a Auberdine, $n, pero aún no has acabado tu cometido.$B$BDescansa un poco y vuelve.$B$BY..., $n, prepara tu mente y tu alma para más derramamientos de sangre.', 0);
-- 985 La extensión de la amenaza
-- https://es.classic.wowhead.com/quest=985
SET @ID := 985;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No apartes tu mano de lo que se debe hacer, $gniño:niña;. Sé lo repulsiva que debe ser la idea de matar a las criaturas del bosque, pero en este caso es necesario. No se ha descubierto una cura para la corrupción desatada en el bosque, y debemos hacer lo que podamos para detener su progreso hasta que se encuentre una cura.', 0),
(@ID, 'esMX', 'No apartes tu mano de lo que se debe hacer, $gniño:niña;. Sé lo repulsiva que debe ser la idea de matar a las criaturas del bosque, pero en este caso es necesario. No se ha descubierto una cura para la corrupción desatada en el bosque, y debemos hacer lo que podamos para detener su progreso hasta que se encuentre una cura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Limpia la sangre de tu ropa, $n, y no sufras por lo que tuviste que hacer. Más bien tendrías que dar gracias. Has aliviado en parte los temores de las gentes de Auberdine, aunque Costa Oscura siga peligrando por los efectos del musgovil.', 0),
(@ID, 'esMX', 'Limpia la sangre de tu ropa, $n, y no sufras por lo que tuviste que hacer. Más bien tendrías que dar gracias. Has aliviado en parte los temores de las gentes de Auberdine, aunque Costa Oscura siga peligrando por los efectos del musgovil.', 0);
-- 4761 Thundris Tejevientos
-- https://es.classic.wowhead.com/quest=4761
SET @ID := 4761;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Tu exploración del campamento fúrbolg llega en un momento difícil para Auberdine. Durante un tiempo hemos lidiado no solo con los moradores del bosque, que ahora nos son abiertamente hostiles, sino también con la flagrante corrupción del propio bosque. Espero que puedas prestarnos tu ayuda en estos tiempos difíciles.', 0),
(@ID, 'esMX', 'Saludos, $c. Tu exploración del campamento fúrbolg llega en un momento difícil para Auberdine. Durante un tiempo hemos lidiado no solo con los moradores del bosque, que ahora nos son abiertamente hostiles, sino también con la flagrante corrupción del propio bosque. Espero que puedas prestarnos tu ayuda en estos tiempos difíciles.', 0);
-- 4762 El Río Fonroca
-- https://es.classic.wowhead.com/quest=4762
SET @ID := 4762;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción del Río Fonroca no es más que el principio de una alarmante situación en Costa Oscura. La muestra que nos has traído nos ayudará a idear un plan... y sospecho que tendrá que ser un plan de ataque.', 0),
(@ID, 'esMX', 'La corrupción del Río Fonroca no es más que el principio de una alarmante situación en Costa Oscura. La muestra que nos has traído nos ayudará a idear un plan... y sospecho que tendrá que ser un plan de ataque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me sorprende que el agua esté tan contaminada, ¡pero fíjate cómo se está pudriendo! Diría que tendremos que actuar pronto, ¿no te parece, $n?$B$BAl este se encuentra Frondavil. Es la fuente de esta corrupción, una que he visto en otros tiempos. Sé que esta muestra lo confirmará. Quizás podamos encontrar una cura aquí, pero para intentarlo siquiera, necesitaremos ayuda. Cuando llegue el momento, $n, espero que puedas proporcionárnosla.', 0),
(@ID, 'esMX', 'No me sorprende que el agua esté tan contaminada, ¡pero fíjate cómo se está pudriendo! Diría que tendremos que actuar pronto, ¿no te parece, $n?$B$BAl este se encuentra Frondavil. Es la fuente de esta corrupción, una que he visto en otros tiempos. Sé que esta muestra lo confirmará. Quizás podamos encontrar una cura aquí, pero para intentarlo siquiera, necesitaremos ayuda. Cuando llegue el momento, $n, espero que puedas proporcionárnosla.', 0);
-- 2139 La esperanza de Tharnariun
-- https://es.classic.wowhead.com/quest=2139
SET @ID := 2139;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la madre del cubil infectada asesinada, la población de osos cardos rabiosos que entran en nuestra tierra disminuye. No pierdas el tiempo, $n.', 0),
(@ID, 'esMX', 'Con la madre del cubil infectada asesinada, la población de osos cardos rabiosos que entran en nuestra tierra disminuye. No pierdas el tiempo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has combatido por Auberdine con valentía y honor, $n. En estas tierras desgarradas por la guerra, la muerte y la desesperación son habituales. Y son muchos los que no se atreven a aceptar el desafío de vivir en nuestro nuevo hogar y eligen esconderse en sus casas o huir a las tierras mejor defendidas de la Alianza.$B$BGracias, $n. Uno de estos días combatiremos como camaradas contra otro enemigo.', 0),
(@ID, 'esMX', 'Has combatido por Auberdine con valentía y honor, $n. En estas tierras desgarradas por la guerra, la muerte y la desesperación son habituales. Y son muchos los que no se atreven a aceptar el desafío de vivir en nuestro nuevo hogar y eligen esconderse en sus casas o huir a las tierras mejor defendidas de la Alianza.$B$BGracias, $n. Uno de estos días combatiremos como camaradas contra otro enemigo.', 0);
-- 986 El maestro perdido
-- https://es.classic.wowhead.com/quest=986
SET @ID := 986;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi conciencia no me permite enviarte a buscar a Volcor hasta que te haya hecho la capa.', 0),
(@ID, 'esMX', 'Mi conciencia no me permite enviarte a buscar a Volcor hasta que te haya hecho la capa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son estupendas, $n. Empezaré a trabajar en la capa de inmediato.$B$BDame un momento y luego vuelve.$B$BAh, otra cosa: cuando hayas usado el hechizo en la capa, tu capacidad de interactuar con otros estará limitada. Si puedes, limítate a hablar, solo eso. Si haces algo más, podrías destruir la ilusión.', 0),
(@ID, 'esMX', 'Estas pieles son estupendas, $n. Empezaré a trabajar en la capa de inmediato.$B$BDame un momento y luego vuelve.$B$BAh, otra cosa: cuando hayas usado el hechizo en la capa, tu capacidad de interactuar con otros estará limitada. Si puedes, limítate a hablar, solo eso. Si haces algo más, podrías destruir la ilusión.', 0);
-- 966 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=966
SET @ID := 966;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algún pergamino más? Si consigues encontrarlos, podría hacerme una idea más completa de lo que planean.', 0),
(@ID, 'esMX', '¿Has encontrado algún pergamino más? Si consigues encontrarlos, podría hacerme una idea más completa de lo que planean.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Esto debería arrojar algo de luz sobre esta reunión de brujos...$B$BMmm...el Culto de la Facción Oscura... Nunca había oído hablar de este culto. Es imposible saber qué planes tienen sin conocer su historia.$B$BNo hay tiempo que perder. Hay que enviar un aviso a Delgren de inmediato.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Esto debería arrojar algo de luz sobre esta reunión de brujos...$B$BMmm...el Culto de la Facción Oscura... Nunca había oído hablar de este culto. Es imposible saber qué planes tienen sin conocer su historia.$B$BNo hay tiempo que perder. Hay que enviar un aviso a Delgren de inmediato.', 0);
-- 967 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=967
SET @ID := 967;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres algo de mí, $c?', 0),
(@ID, 'esMX', '¿Quieres algo de mí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perdona que te lo diga, pero estás muy bien equipado para ser mensajero, ¿no? Supongo que Balthule quería asegurarse de que su carta llegaba a mis manos. Veamos qué dice...$B$BSon noticias desalentadoras. Cuando aparecen fuerzas de no-muertos y de demonios, ayudo a las Centinelas a destruirlas.$B$BTardé en acostumbrarme a los modos de los elfos de la noche, pero he llegado a respetarlos como aliados.', 0),
(@ID, 'esMX', 'Perdona que te lo diga, pero estás muy bien equipado para ser mensajero, ¿no? Supongo que Balthule quería asegurarse de que su carta llegaba a mis manos. Veamos qué dice...$B$BSon noticias desalentadoras. Cuando aparecen fuerzas de no-muertos y de demonios, ayudo a las Centinelas a destruirlas.$B$BTardé en acostumbrarme a los modos de los elfos de la noche, pero he llegado a respetarlos como aliados.', 0);
-- 4763 La corrupción de los Bosque Negro
-- https://es.classic.wowhead.com/quest=4763
SET @ID := 4763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El talismán de Corrupción es un siniestro instrumento que solo sirve para enturbiar el equilibrio de la naturaleza. Arrebata este objeto al sátiro que está atormentando a los furbolgs y tráemelo. Cuando yo lo haya destruido, ¡habremos ganado una importante batalla!', 0),
(@ID, 'esMX', 'El talismán de Corrupción es un siniestro instrumento que solo sirve para enturbiar el equilibrio de la naturaleza. Arrebata este objeto al sátiro que está atormentando a los furbolgs y tráemelo. Cuando yo lo haya destruido, ¡habremos ganado una importante batalla!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apenas hemos comenzado la guerra para arrebatar nuestro bosque a las fuerzas de la corrupción, ¡pero hoy hemos ganado una batalla! $n, las gentes de Auberdine tienen una deuda contigo que no podrá pagarse fácilmente. Por favor, acepta esto con nuestro agradecimiento. Lo que hemos aprendido hoy aquí, en un futuro podría liberar a nuestros amigos furbolgs de los grilletes del tormento eterno.', 0),
(@ID, 'esMX', 'Apenas hemos comenzado la guerra para arrebatar nuestro bosque a las fuerzas de la corrupción, ¡pero hoy hemos ganado una batalla! $n, las gentes de Auberdine tienen una deuda contigo que no podrá pagarse fácilmente. Por favor, acepta esto con nuestro agradecimiento. Lo que hemos aprendido hoy aquí, en un futuro podría liberar a nuestros amigos furbolgs de los grilletes del tormento eterno.', 0);

-- 944 La Espada del Maestro
-- https://es.classic.wowhead.com/quest=944
SET @ID := 944;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Espada del Maestro, $n$B$BVe allí y vuelve a hablar conmigo.', 0),
(@ID, 'esMX', 'La Espada del Maestro, $n$B$BVe allí y vuelve a hablar conmigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Martillo Crepuscular está en La Espada del Maestro?$B$BQué desventura.$B$BEl Señor de la Tierra que fue empalado en La Espada del Maestro lleva mucho tiempo muerto, pero eso no quiere decir que no queden aún trazas de su poder.$B$BEl Martillo Crepuscular debe de estar buscando ese poder.', 0),
(@ID, 'esMX', '¿El Martillo Crepuscular está en La Espada del Maestro?$B$BQué desventura.$B$BEl Señor de la Tierra que fue empalado en La Espada del Maestro lleva mucho tiempo muerto, pero eso no quiere decir que no queden aún trazas de su poder.$B$BEl Martillo Crepuscular debe de estar buscando ese poder.', 0);
-- 5321 El despertar
-- https://es.classic.wowhead.com/quest=5321
SET @ID := 5321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha llegado Kerlonian?', 0),
(@ID, 'esMX', '¿Ha llegado Kerlonian?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cómo me alegra que Kerlonian esté bien! Seguro que lo encontraré por aquí, durmiendo en cualquier esquina, ¿acierto?$B$BGracias por indicarle el camino, $n.', 0),
(@ID, 'esMX', '¡Cómo me alegra que Kerlonian esté bien! Seguro que lo encontraré por aquí, durmiendo en cualquier esquina, ¿acierto?$B$BGracias por indicarle el camino, $n.', 0);
-- 945 La fuga de Therylune
-- https://es.classic.wowhead.com/quest=945
SET @ID := 945;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Que mi hermana estaba dónde?? Sé que a Therylune no le importa ensuciarse, ¡pero ir a La Espada del Maestro! Incluso para ella es un largo camino... y La Espada es un lugar malsano...$B$BEn fin, gracias, $n. Ha sido un detalle por tu parte informarme de que está bien.', 0),
(@ID, 'esMX', '¿¿Que mi hermana estaba dónde?? Sé que a Therylune no le importa ensuciarse, ¡pero ir a La Espada del Maestro! Incluso para ella es un largo camino... y La Espada es un lugar malsano...$B$BEn fin, gracias, $n. Ha sido un detalle por tu parte informarme de que está bien.', 0);
-- 731 El prospector despistado
-- https://es.classic.wowhead.com/quest=731
SET @ID := 731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está vivo el prospector?', 0),
(@ID, 'esMX', '¿Está vivo el prospector?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a las estrellas el prospector Remtravel está bien! Te dije que era un poco despistado. No puedo creer que insistiera en quedarse allí con todas esas horribles criaturas al acecho.', 0),
(@ID, 'esMX', '¡Gracias a las estrellas el prospector Remtravel está bien! Te dije que era un poco despistado. No puedo creer que insistiera en quedarse allí con todas esas horribles criaturas al acecho.', 0);
-- 993 El maestro perdido
-- https://es.classic.wowhead.com/quest=993
SET @ID := 993;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! Terenthis ha encontrado a alguien que me ayude.$B$BY mira, una capa de Acechalunas...<tose> Ay... qué dolor. Gracias, $n.$B$BLos furbolgs me hirieron antes de que consiguiera escapar. Dame un momento para recuperarme. Luego podremos hablar.', 0),
(@ID, 'esMX', '¡Estupendo! Terenthis ha encontrado a alguien que me ayude.$B$BY mira, una capa de Acechalunas...<tose> Ay... qué dolor. Gracias, $n.$B$BLos furbolgs me hirieron antes de que consiguiera escapar. Dame un momento para recuperarme. Luego podremos hablar.', 0);
-- 995 Escaparse furtivamente
-- https://es.classic.wowhead.com/quest=995
SET @ID := 995;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Me alegra ver que has conseguido volver. Que ayudaras a Volcor me da esperanzas... creo que podremos superar los desafíos que nos esperan en Costa Oscura y más allá.', 0),
(@ID, 'esMX', '¡$n! Me alegra ver que has conseguido volver. Que ayudaras a Volcor me da esperanzas... creo que podremos superar los desafíos que nos esperan en Costa Oscura y más allá.', 0);
-- 994 Escaparse por la fuerza
-- https://es.classic.wowhead.com/quest=994
SET @ID := 994;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Me complace ver que has regresaso. Tu ayuda a Volcor me ha dado fe en que podemos superar los desafíos que enfrentamos aquí en Darkshore y más allá.', 0),
(@ID, 'esMX', '¡$n! Me complace ver que has regresaso. Tu ayuda a Volcor me ha dado fe en que podemos superar los desafíos que enfrentamos aquí en Darkshore y más allá.', 0);
-- 968 Los Poderes Subyacentes
-- https://es.classic.wowhead.com/quest=968
SET @ID := 968;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gseñor:señora;.$B¿Puedo interesarte en uno de mis libros?', 0),
(@ID, 'esMX', 'Hola, $gseñor:señora;.$B¿Puedo interesarte en uno de mis libros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una copia de Los Poderes Subyacentes. Un texto interesante. Y a algunos les puede resultar útil...$B$BPero este está en muy mal estado. ¡Y mira aquí! ¡Hay notas al margen de casi todas las páginas!$B$BHm... reconozco esta copia. Se lo vendí a Bolgar el año pasado. ¿Eres... su $gamigo:amiga;? Sí, eso pensé. ¡Tienes ese mismo fuego en de tu mirada!$B$BBueno, por definición, $gun amigo:una amiga; de Bolgar es $gamigo mío:amiga mia;. Y nosotros nos ocupamos de los nuestros, ¿no?', 0),
(@ID, 'esMX', 'Ah, una copia de Los Poderes Subyacentes. Un texto interesante. Y a algunos les puede resultar útil...$B$BPero este está en muy mal estado. ¡Y mira aquí! ¡Hay notas al margen de casi todas las páginas!$B$BHm... reconozco esta copia. Se lo vendí a Bolgar el año pasado. ¿Eres... su $gamigo:amiga;? Sí, eso pensé. ¡Tienes ese mismo fuego en de tu mirada!$B$BBueno, por definición, $gun amigo:una amiga; de Bolgar es $gamigo mío:amiga mia;. Y nosotros nos ocupamos de los nuestros, ¿no?', 0);
-- 949 El campamento del Martillo Crepuscular
-- https://es.classic.wowhead.com/quest=949
SET @ID := 949;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este libro fue manuscrito en un antiguo lenguaje e ilustrado por un artista.', 0),
(@ID, 'esMX', 'Este libro fue manuscrito en un antiguo lenguaje e ilustrado por un artista.', 0);
-- 950 Regresa junto a Onus
-- https://es.classic.wowhead.com/quest=950
SET @ID := 950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Vuelve.', 0),
(@ID, 'esMX', '$n. Vuelve.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este intrincado texto está envuelto en una primitiva y caótica magia. Percibo la mano de los mayores en él.$B$BEsperemos que nos revele el propósito del Martillo Crepuscular en Costa Oscura...', 0),
(@ID, 'esMX', 'Este intrincado texto está envuelto en una primitiva y caótica magia. Percibo la mano de los mayores en él.$B$BEsperemos que nos revele el propósito del Martillo Crepuscular en Costa Oscura...', 0);
-- 741 El prospector despistado
-- https://es.classic.wowhead.com/quest=741
SET @ID := 741;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué puedo hacer por ti, $r?', 0),
(@ID, 'esMX', '¿Qué puedo hacer por ti, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay, ay! ¡Deja que sea el prospector Remtravel quien descubra eso!', 0),
(@ID, 'esMX', '¡Ay, ay! ¡Deja que sea el prospector Remtravel quien descubra eso!', 0);
-- 942 El prospector despistado
-- https://es.classic.wowhead.com/quest=942
SET @ID := 942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya! ¿Dices que esto viene de las lejanas tierras de Kalimdor?$B$B¡Increíble! ¡Sencillamente increíble!', 0),
(@ID, 'esMX', '¡Vaya! ¿Dices que esto viene de las lejanas tierras de Kalimdor?$B$B¡Increíble! ¡Sencillamente increíble!', 0);
-- 1124 Páramo
-- https://es.classic.wowhead.com/quest=1124
SET @ID := 1124;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este no es lugar para pasearse, $c. ¿Qué te trae a Silithus?', 0),
(@ID, 'esMX', 'Este no es lugar para pasearse, $c. ¿Qué te trae a Silithus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, vienes de parte del rabino. Te doy la bienvenida a estas tierras inhóspitas.$B$BYo no fui testigo de las grandes guerras, pero la desolación se huele en el aire. Gracias a tu ayuda, puede que el Círculo Cenarion ponga fin a una amenaza que se creía eliminada hace generaciones.', 0),
(@ID, 'esMX', 'Ah, vienes de parte del rabino. Te doy la bienvenida a estas tierras inhóspitas.$B$BYo no fui testigo de las grandes guerras, pero la desolación se huele en el aire. Gracias a tu ayuda, puede que el Círculo Cenarion ponga fin a una amenaza que se creía eliminada hace generaciones.', 0);
-- 5527 Un relicario de Pureza
-- https://es.classic.wowhead.com/quest=5527
SET @ID := 5527;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los relicarios de pureza son instrumentos importantes. Se hicieron muy pocos y se creían perdidos.$B$BAdmito que sabía de la existencia del de Viento del Sur; pero me pareció más sensato mantener el secreto para evitar las sospechas del enemigo.$B$BPero ha llegado el momento de actuar, sobre todo tal como están las cosas en Eldre\'Thalas.', 0),
(@ID, 'esMX', 'Los relicarios de pureza son instrumentos importantes. Se hicieron muy pocos y se creían perdidos.$B$BAdmito que sabía de la existencia del de Viento del Sur; pero me pareció más sensato mantener el secreto para evitar las sospechas del enemigo.$B$BPero ha llegado el momento de actuar, sobre todo tal como están las cosas en Eldre\'Thalas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que se dice de ti es cierto; el Círculo Cenarion tiene suerte de poder contar contigo.$B$BAhora que tengo el relicario, me siento más tranquilo. Tienes mi gratitud eterna por lo que has hecho...', 0),
(@ID, 'esMX', 'Lo que se dice de ti es cierto; el Círculo Cenarion tiene suerte de poder contar contigo.$B$BAhora que tengo el relicario, me siento más tranquilo. Tienes mi gratitud eterna por lo que has hecho...', 0);
-- 1008 La Ensenada de Zoram
-- https://es.classic.wowhead.com/quest=1008
SET @ID := 1008;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir que los nagas invadan nuestras costas, $n. Es vital que vayas a La Ensenada de Zoram y completes tu misión.', 0),
(@ID, 'esMX', 'No podemos permitir que los nagas invadan nuestras costas, $n. Es vital que vayas a La Ensenada de Zoram y completes tu misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera, $n. Tus acciones en La Ensenada de Zoram contra los nagas son encomiables.$B$BSé que no fue fácil realizar semejante proeza ya que la fuerza y la astucia de los nagas es sobradamente conocida entre los elfos de la noche. Lo sabemos… porque compartimos una historia con ellos.$B$BUna historia que me guardo de repetir.', 0),
(@ID, 'esMX', 'Un trabajo de primera, $n. Tus acciones en La Ensenada de Zoram contra los nagas son encomiables.$B$BSé que no fue fácil realizar semejante proeza ya que la fuerza y la astucia de los nagas es sobradamente conocida entre los elfos de la noche. Lo sabemos… porque compartimos una historia con ellos.$B$BUna historia que me guardo de repetir.', 0);
-- 4581 Kayneth Ventoleve
-- https://es.classic.wowhead.com/quest=4581
SET @ID := 4581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, el informe de Shindrell! Muchas gracias, $n. Shindrell es una buena centinela, valiente y amable. Debo leer esto en busca de pistas de una perversidad que, me temo, se está extendiendo por Vallefresno.', 0),
(@ID, 'esMX', '¡Ah, el informe de Shindrell! Muchas gracias, $n. Shindrell es una buena centinela, valiente y amable. Debo leer esto en busca de pistas de una perversidad que, me temo, se está extendiendo por Vallefresno.', 0);
-- 9533 Una mano amiga
-- https://es.classic.wowhead.com/quest=9533
SET @ID := 9533;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno ver a otro recién llegado aquí en Canción del Bosque.$B$BLa vindicadora Palanaar está enviando toda la ayuda que puede reunir y se agradece cada par de manos.$B$BEcha un vistazo a tu alrededor, $c. Puede que no sea mucho ahora, pero con el tiempo y la ayuda de nuestros aliados elfos de la noche, construiremos un asentamiento digno de llamar hogar. Hay mucho por hacer aquí y cualquier ayuda que puedas brindar será bienvenida.', 0),
(@ID, 'esMX', 'Es bueno ver a otro recién llegado aquí en Canción del Bosque.$B$BLa vindicadora Palanaar está enviando toda la ayuda que puede reunir y se agradece cada par de manos.$B$BEcha un vistazo a tu alrededor, $c. Puede que no sea mucho ahora, pero con el tiempo y la ayuda de nuestros aliados elfos de la noche, construiremos un asentamiento digno de llamar hogar. Hay mucho por hacer aquí y cualquier ayuda que puedas brindar será bienvenida.', 0);
-- 991 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=991
SET @ID := 991;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuerpo de Teronis yace destrozado en la isla. Por alguna razón desconocida, los murlocs lo han dejado en paz.$B$BLos profundos cortes en su cadáver proceden sin duda de las armas y garras de los murlocs.', 0),
(@ID, 'esMX', 'El cuerpo de Teronis yace destrozado en la isla. Por alguna razón desconocida, los murlocs lo han dejado en paz.$B$BLos profundos cortes en su cadáver proceden sin duda de las armas y garras de los murlocs.', 0);
-- 1054 Matanza selectiva
-- https://es.classic.wowhead.com/quest=1054
SET @ID := 1054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción de los furbolgs ha asestado un duro golpe a la gloria de Vallefresno.', 0),
(@ID, 'esMX', 'La corrupción de los furbolgs ha asestado un duro golpe a la gloria de Vallefresno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n.$B$BLa amenaza de los furbolgs es constante. Esperemos que esto los mantenga a raya un poco más.', 0),
(@ID, 'esMX', 'Muy bien, $n.$B$BLa amenaza de los furbolgs es constante. Esperemos que esto los mantenga a raya un poco más.', 0);
-- 1023 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1023
SET @ID := 1023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, bienvenido de nuevo.', 0),
(@ID, 'esMX', 'Ah, $n, bienvenido de nuevo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es terrible, $n. ¡¿Teronis ha muerto?!$B$BYa llegará la hora del luto pero ahora tenemos que centrar nuestros esfuerzos. Enviaré a algunas centinelas para que recuperen el cuerpo de Teronis cuando antes.$B$BTienes el diario de Teronis y la gema que andaba buscando. ¿Te sientes capaz de completar su tarea? Descansaría mejor si supiera que no murió en vano.', 0),
(@ID, 'esMX', 'Es terrible, $n. ¡¿Teronis ha muerto?!$B$BYa llegará la hora del luto pero ahora tenemos que centrar nuestros esfuerzos. Enviaré a algunas centinelas para que recuperen el cuerpo de Teronis cuando antes.$B$BTienes el diario de Teronis y la gema que andaba buscando. ¿Te sientes capaz de completar su tarea? Descansaría mejor si supiera que no murió en vano.', 0);
-- 1007 Las antiguas estatuillas
-- https://es.classic.wowhead.com/quest=1007
SET @ID := 1007;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la estatuilla, $n?', 0),
(@ID, 'esMX', '¿Has encontrado la estatuilla, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La encontraste! ¡Gracias, $n!$B$BLa antigua ciudad de Zoram guarda muchos secretos y esta estatuilla podría ser la llave de gran parte de tales secretos.', 0),
(@ID, 'esMX', '¡La encontraste! ¡Gracias, $n!$B$BLa antigua ciudad de Zoram guarda muchos secretos y esta estatuilla podría ser la llave de gran parte de tales secretos.', 0);
-- 1009 Ruuzel
-- https://es.classic.wowhead.com/quest=1009
SET @ID := 1009;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se dice que el Anillo de Zoram es la clave de cualquier cerradura de la ciudad. ¿Lo tienes, $n?', 0),
(@ID, 'esMX', 'Se dice que el Anillo de Zoram es la clave de cualquier cerradura de la ciudad. ¿Lo tienes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Encontraste el anillo! Gracias, $n. Acepta esto a guisa de pago y que sepas que tus acciones de hoy permanecerán por siempre en mi memoria.', 0),
(@ID, 'esMX', '¡Encontraste el anillo! Gracias, $n. Acepta esto a guisa de pago y que sepas que tus acciones de hoy permanecerán por siempre en mi memoria.', 0);
-- 970 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=970
SET @ID := 970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la gema de alma?', 0),
(@ID, 'esMX', '¿Has conseguido la gema de alma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, esta piedra de alma está encantada con magia oscura. Será mejor que veamos que encierra.', 0),
(@ID, 'esMX', 'Mm, esta piedra de alma está encantada con magia oscura. Será mejor que veamos que encierra.', 0);
-- 1010 Cabello de Bathran
-- https://es.classic.wowhead.com/quest=1010
SET @ID := 1010;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el cabello de Bathran, $n? La salud de la niña se debilita por minutos...', 0),
(@ID, 'esMX', '¿Has conseguido el cabello de Bathran, $n? La salud de la niña se debilita por minutos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, tienes el cabello! Ahora haré un preparado para la niña y rezaré para que funcione.$B$BY... ¿dices que los Renegados están en las Ruinas de Bathran? Inquietante noticia. De lo más inquietante...', 0),
(@ID, 'esMX', '¡Ah, tienes el cabello! Ahora haré un preparado para la niña y rezaré para que funcione.$B$BY... ¿dices que los Renegados están en las Ruinas de Bathran? Inquietante noticia. De lo más inquietante...', 0);

-- 1020 Cura de Orendil
-- https://es.classic.wowhead.com/quest=1020
SET @ID := 1020;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis disculpas, no tengo tiempo para hablar. Mi hija, Relara, ¡está gravemente enferma!', 0),
(@ID, 'esMX', 'Mis disculpas, no tengo tiempo para hablar. Mi hija, Relara, ¡está gravemente enferma!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Esto es de Orendil?$B$BTiene un gran talento con hierbas y curaciones. Esta cura me da esperanza, antes de tomar un poco...', 0),
(@ID, 'esMX', '¿Esto es de Orendil?$B$BTiene un gran talento con hierbas y curaciones. Esta cura me da esperanza, antes de tomar un poco...', 0);
-- 973 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=973
SET @ID := 973;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces $ginquieto:inquieta;, $n. ¿Te encuentras bien?', 0),
(@ID, 'esMX', 'Pareces $ginquieto:inquieta;, $n. ¿Te encuentras bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy has hecho algo grande, $n. Puedes sentirte $gorgulloso:orgullosa; de haberte enfrentado a tan poderoso brujo.$B$BAhora, veamos qué podemos averiguar en los escritos de Ilkrud.', 0),
(@ID, 'esMX', 'Hoy has hecho algo grande, $n. Puedes sentirte $gorgulloso:orgullosa; de haberte enfrentado a tan poderoso brujo.$B$BAhora, veamos qué podemos averiguar en los escritos de Ilkrud.', 0);
-- 1134 Alaorgullo del Espolón
-- https://es.classic.wowhead.com/quest=1134
SET @ID := 1134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los sacos de veneno de alaorgullo, $n? No podemos permitir que los orcos utilicen el veneno de esas bestias contra nosotros.', 0),
(@ID, 'esMX', '¿Tienes los sacos de veneno de alaorgullo, $n? No podemos permitir que los orcos utilicen el veneno de esas bestias contra nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Me entristece ordenar matar a criaturas que no quieren ayudar voluntariamente a nuestro enemigo, pero es mi deber hacerlo.$B$BTu corazón puede llorar por los alaorgullo que has matado, pero también debería estar henchido de orgullo al saber que tus aliados están a salvo del veneno de alaorgullo.', 0),
(@ID, 'esMX', 'Gracias, $n. Me entristece ordenar matar a criaturas que no quieren ayudar voluntariamente a nuestro enemigo, pero es mi deber hacerlo.$B$BTu corazón puede llorar por los alaorgullo que has matado, pero también debería estar henchido de orgullo al saber que tus aliados están a salvo del veneno de alaorgullo.', 0);
-- 1024 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1024
SET @ID := 1024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Qué tal?', 0),
(@ID, 'esMX', 'Hola. ¿Qué tal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Raene? Entonces será grave. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿Te envía Raene? Entonces será grave. ¿En qué puedo ayudarte?', 0);
-- 1025 Una defensa agresiva
-- https://es.classic.wowhead.com/quest=1025
SET @ID := 1025;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los fúrbolg no siempre fueron nuestro enemigo, $n. Pero los tiempos cambian y ya no es un momento de paz aquí en estos bosques oscuros.', 0),
(@ID, 'esMX', 'Los fúrbolg no siempre fueron nuestro enemigo, $n. Pero los tiempos cambian y ya no es un momento de paz aquí en estos bosques oscuros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Gracias.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Gracias.', 0);
-- 1033 Lágrima de Elune
-- https://es.classic.wowhead.com/quest=1033
SET @ID := 1033;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has encontrado el Lago Iris? ¿Tienes la Lágrima?', 0),
(@ID, 'esMX', '$n, ¿has encontrado el Lago Iris? ¿Tienes la Lágrima?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, la encontraste! Colocaré la lágrima en un guiso y rezaré para que la cure.$B$B¡Gracias! ¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Vaya, la encontraste! Colocaré la lágrima en un guiso y rezaré para que la cure.$B$B¡Gracias! ¡Gracias, $n!', 0);
-- 1034 Las Ruinas del Polvo Estelar
-- https://es.classic.wowhead.com/quest=1034
SET @ID := 1034;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya el polvo estelar, $n?', 0),
(@ID, 'esMX', '¿Tienes ya el polvo estelar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido el polvo! Con él prepararé una cataplasma, eso debería bajar la fiebre de Relara.$B$BGracias otra vez, $n. Sin tu ayuda, mi hija habría perecido.', 0),
(@ID, 'esMX', '¡Has conseguido el polvo! Con él prepararé una cataplasma, eso debería bajar la fiebre de Relara.$B$BGracias otra vez, $n. Sin tu ayuda, mi hija habría perecido.', 0);
-- 1035 Lago Cielo Estrellado
-- https://es.classic.wowhead.com/quest=1035
SET @ID := 1035;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has enfrentado ya al Oráculo de Sombramatorral, $n? De ser así, te ruego me entregues la piedra lunar caída. ¡A Relara le quedan fuerzas para unos suspiros más!', 0),
(@ID, 'esMX', '¿Te has enfrentado ya al Oráculo de Sombramatorral, $n? De ser así, te ruego me entregues la piedra lunar caída. ¡A Relara le quedan fuerzas para unos suspiros más!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, $n, ¡has salvado a mi hija! ¡Sé que el poder de la piedra lunar le devolverá las fuerzas!$B$BNunca podré pagarte por lo que has hecho pero... te ruego aceptes esto. Aparte de Relara, es mi más preciada posesión.', 0),
(@ID, 'esMX', 'Oh, $n, ¡has salvado a mi hija! ¡Sé que el poder de la piedra lunar le devolverá las fuerzas!$B$BNunca podré pagarte por lo que has hecho pero... te ruego aceptes esto. Aparte de Relara, es mi más preciada posesión.', 0);
-- 1140 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1140
SET @ID := 1140;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez escuché susurrar que la historia de los sátiros está relacionada de alguna manera con la de los elfos de la noche, pero mis estimados anfitriones son reticentes a hablar del asunto.', 0),
(@ID, 'esMX', 'Una vez escuché susurrar que la historia de los sátiros está relacionada de alguna manera con la de los elfos de la noche, pero mis estimados anfitriones son reticentes a hablar del asunto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás a los sátiros se les ha permitido permanecer en el bosque durante demasiado tiempo. Hablaré con Elissa al respecto la próxima vez que viaje a Auberdine.$B$BNo obstante, con las gemas del alma destruidas, el poder de Athrikus disminuirá considerablemente. Debemos aprovechar esta oportunidad para eliminarlo a él y a su culto.', 0),
(@ID, 'esMX', 'Quizás a los sátiros se les ha permitido permanecer en el bosque durante demasiado tiempo. Hablaré con Elissa al respecto la próxima vez que viaje a Auberdine.$B$BNo obstante, con las gemas del alma destruidas, el poder de Athrikus disminuirá considerablemente. Debemos aprovechar esta oportunidad para eliminarlo a él y a su culto.', 0);
-- 976 Suministros a Auberdine
-- https://es.classic.wowhead.com/quest=976
SET @ID := 976;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las Centinelas tienen una gran necesidad de suministros para reforzarse en Costa Oscura.', 0),
(@ID, 'esMX', 'Las Centinelas tienen una gran necesidad de suministros para reforzarse en Costa Oscura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien hoy, $c. Los artículos que enviamos para ayudar a Auberdine serán de utilidad inmediata para hacer frente a las oscuras amenazas que infestan el bosque.$B$BToma esto con mi más sincero agradecimiento.', 0),
(@ID, 'esMX', 'Lo has hecho bien hoy, $c. Los artículos que enviamos para ayudar a Auberdine serán de utilidad inmediata para hacer frente a las oscuras amenazas que infestan el bosque.$B$BToma esto con mi más sincero agradecimiento.', 0);
-- 1026 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1026
SET @ID := 1026;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me indigna que los antárboles se hayan corrompido. Ojalá pudiera hacer más por ayudarlos.', 0),
(@ID, 'esMX', 'Me indigna que los antárboles se hayan corrompido. Ojalá pudiera hacer más por ayudarlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas vuelto, $n.', 0),
(@ID, 'esMX', 'Me alegra que hayas vuelto, $n.', 0);
-- 1167 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1167
SET @ID := 1167;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, es bueno verte de nuevo, $n! Las cosas más extrañas han estado sucediendo por aquí, ¡me alegro de que aparecieras!$B$BFue muy extraño, $n. Todo parecía normal, bueno, tan normal como se ponen las cosas por aquí, y de repente hubo un destello de luz cegadora desde la habitación superior de la torre. Luego vinieron los gritos. Los gritos partieron el aire y los relámpagos golpearon el suelo una y otra vez. ¿Que esta pasando?', 0),
(@ID, 'esMX', '¡Ah, es bueno verte de nuevo, $n! Las cosas más extrañas han estado sucediendo por aquí, ¡me alegro de que aparecieras!$B$BFue muy extraño, $n. Todo parecía normal, bueno, tan normal como se ponen las cosas por aquí, y de repente hubo un destello de luz cegadora desde la habitación superior de la torre. Luego vinieron los gritos. Los gritos partieron el aire y los relámpagos golpearon el suelo una y otra vez. ¿Que esta pasando?', 0);
-- 943 El prospector despistado
-- https://es.classic.wowhead.com/quest=943
SET @ID := 943;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la Piedra de Relu podré desvelar los secretos de mi fósil así como del fósil de Costa Oscura de Tripirrem, $n.', 0),
(@ID, 'esMX', 'Con la Piedra de Relu podré desvelar los secretos de mi fósil así como del fósil de Costa Oscura de Tripirrem, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n!$B$BAhora hay que ver si puedo utilizar la piedra para descubrir los poderes de los fósiles.', 0),
(@ID, 'esMX', '¡Excelente, $n!$B$BAhora hay que ver si puedo utilizar la piedra para descubrir los poderes de los fósiles.', 0);
-- 2988 Las jaulas de Secacorteza
-- https://es.classic.wowhead.com/quest=2988
SET @ID := 2988;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has registrado las jaulas, $n? ¡Debemos encontrar a Picoafilado!', 0),
(@ID, 'esMX', '¿Has registrado las jaulas, $n? ¡Debemos encontrar a Picoafilado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que no has encontrado a Picoafilado? Eso es una mala noticia; es el jefe de la futura generación de grifos. Sin él se perderá gran parte de su fuerza y empuje.', 0),
(@ID, 'esMX', '¿Que no has encontrado a Picoafilado? Eso es una mala noticia; es el jefe de la futura generación de grifos. Sin él se perderá gran parte de su fuerza y empuje.', 0);
-- 1452 El cubata de Kalimdor de Rapsodio
-- https://es.classic.wowhead.com/quest=1452
SET @ID := 1452;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna vez has probado una Malta Rapsódica? Una de mis mejores cervezas, si lo digo yo mismo. ¡Hip!$B$BPero si voy a revivir los horrores de ese fatídico vuelo sobre... ¡Hip!... el pantano, bueno, voy a necesitar algo un poquito más fuerte. ¡Hip!$B$B¿Crees que me encontrarás esas mollejas e hígados que necesito para agregar ese pelotazo extra a mi cubata de Kalimdor?$B$B¡Hip!', 0),
(@ID, 'esMX', '¿Alguna vez has probado una Malta Rapsódica? Una de mis mejores cervezas, si lo digo yo mismo. ¡Hip!$B$BPero si voy a revivir los horrores de ese fatídico vuelo sobre... ¡Hip!... el pantano, bueno, voy a necesitar algo un poquito más fuerte. ¡Hip!$B$B¿Crees que me encontrarás esas mollejas e hígados que necesito para agregar ese pelotazo extra a mi cubata de Kalimdor?$B$B¡Hip!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que no has tenido ningún problema en conseguirme lo que necesito! Te lo has tomado con calma allí en la lejana Kalimdor.$B$BNo me tomará más que un momento extraer lo que necesito de estas mollejas e hígados. ¡Hip!$B$BAhora puedo preparame un trago feroz y finalmente decirte lo que quieres saber.$B$B¡Hip!$B$BMe da escalofríos solo de pensar en ese viejo pantano.$B$B¡Hip!$B$BDéjame preparar un trago muy rápido.', 0),
(@ID, 'esMX', '¡Veo que no has tenido ningún problema en conseguirme lo que necesito! Te lo has tomado con calma allí en la lejana Kalimdor.$B$BNo me tomará más que un momento extraer lo que necesito de estas mollejas e hígados. ¡Hip!$B$BAhora puedo preparame un trago feroz y finalmente decirte lo que quieres saber.$B$B¡Hip!$B$BMe da escalofríos solo de pensar en ese viejo pantano.$B$B¡Hip!$B$BDéjame preparar un trago muy rápido.', 0);
-- 1469 El relato de Rapsodio
-- https://es.classic.wowhead.com/quest=1469
SET @ID := 1469;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has vuelto, $n. Ha pasado bastante tiempo desde la última vez que hablamos. Pensé que tal vez te habías olvidado de mi búsqueda.$B$B¿Localizaste a ese astuto jinete de grifos? ¿Tenía algo que informar?', 0),
(@ID, 'esMX', 'Por fin has vuelto, $n. Ha pasado bastante tiempo desde la última vez que hablamos. Pensé que tal vez te habías olvidado de mi búsqueda.$B$B¿Localizaste a ese astuto jinete de grifos? ¿Tenía algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rapsodio Machacacanillas! Así es... ¿cómo pude olvidar ese nombre?$B$B¿Entonces él sabía sobre el hundimiento del templo todo el tiempo? Bueno, eso ciertamente te habría ahorrado algo de trabajo.$B$B¡Pero este artefacto de Atal\'ai! ¡Es todo un descubrimiento!', 0),
(@ID, 'esMX', '¡Rapsodio Machacacanillas! Así es... ¿cómo pude olvidar ese nombre?$B$B¿Entonces él sabía sobre el hundimiento del templo todo el tiempo? Bueno, eso ciertamente te habría ahorrado algo de trabajo.$B$B¡Pero este artefacto de Atal\'ai! ¡Es todo un descubrimiento!', 0);
-- 8262 Botiquín avanzado de Arathor
-- https://es.classic.wowhead.com/quest=8262
SET @ID := 8262;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. Como recompensa, llévate este botiquín. En su interior encontrarás raciones y vendajes que solo se pueden utilizar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando tu valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(@ID, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. Como recompensa, llévate este botiquín. En su interior encontrarás raciones y vendajes que solo se pueden utilizar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando tu valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0);
-- 642 La princesa encerrada
-- https://es.classic.wowhead.com/quest=642
SET @ID := 642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este bloque de fragmentos se parece mucho a los fragmentos de Myzrael. Pero no late en ellos el mismo sentimiento de seguridad.', 0),
(@ID, 'esMX', 'Este bloque de fragmentos se parece mucho a los fragmentos de Myzrael. Pero no late en ellos el mismo sentimiento de seguridad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Has activado estos fragmentos. ¡Ya empiezo a sentirme como antes!$B$BAunque ¡qué lejos estoy aún de la liberación!', 0),
(@ID, 'esMX', '¡Ah! Has activado estos fragmentos. ¡Ya empiezo a sentirme como antes!$B$BAunque ¡qué lejos estoy aún de la liberación!', 0);
-- 651 Piedras de Vínculo
-- https://es.classic.wowhead.com/quest=651
SET @ID := 651;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es la Piedra de Vínculo Interior. Es la más fuerte de las piedras de vínculo y hay que desbloquearla para abrir las otras.', 0),
(@ID, 'esMX', 'Esta es la Piedra de Vínculo Interior. Es la más fuerte de las piedras de vínculo y hay que desbloquearla para abrir las otras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Myzrael habla a través de la piedra.>$B$B¡Lo has logrado! ¡Has abierto las Piedras de vínculo! Siento cómo los grilletes se sueltan y la libertad se acerca.$B$BComo $c, eres muy noble, $n. ¡Mi $gsalvador:salvadora;!', 0),
(@ID, 'esMX', '<Myzrael habla a través de la piedra.>$B$B¡Lo has logrado! ¡Has abierto las Piedras de vínculo! Siento cómo los grilletes se sueltan y la libertad se acerca.$B$BComo $c, eres muy noble, $n. ¡Mi $gsalvador:salvadora;!', 0);
-- 652 Desbloquear la piedra angular
-- https://es.classic.wowhead.com/quest=652
SET @ID := 652;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La piedra angular está cargada de energía geomántica.', 0),
(@ID, 'esMX', 'La piedra angular está cargada de energía geomántica.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas la vara en la piedra angular. Y sientes cómo el suelo tiembla bajo tus pies...', 0),
(@ID, 'esMX', 'Colocas la vara en la piedra angular. Y sientes cómo el suelo tiembla bajo tus pies...', 0);
-- 653 Aliados de Myzrael
-- https://es.classic.wowhead.com/quest=653
SET @ID := 653;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Señora me avisó de tu visita, $c. Te doy la bienvenida en mi morada ya que tú, al igual que yo, estás al servicio de una más alta causa.', 0),
(@ID, 'esMX', 'La Señora me avisó de tu visita, $c. Te doy la bienvenida en mi morada ya que tú, al igual que yo, estás al servicio de una más alta causa.', 0);

-- 687 Theldurin el Perdido
-- https://es.classic.wowhead.com/quest=687
SET @ID := 687;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Hola, hola, hola, hola, hola, ¡¡HOLA!!$B$BLo siento, ¡espera, no lo siento! ¡No seas grosero!$B$BOh no... no estoy diciendo más que locuras.$B$BPero... a veces la locura es mi único consuelo.', 0),
(@ID, 'esMX', 'Hola. Hola, hola, hola, hola, hola, ¡¡HOLA!!$B$BLo siento, ¡espera, no lo siento! ¡No seas grosero!$B$BOh no... no estoy diciendo más que locuras.$B$BPero... a veces la locura es mi único consuelo.', 0);
-- 692 Los trozos perdidos
-- https://es.classic.wowhead.com/quest=692
SET @ID := 692;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Has encontrado esos fragmentos?! Necesitarás el pergamino de Myzrael para cazarla de nuevo ¡antes de que sea demasiado tarde!', 0),
(@ID, 'esMX', '¡¿Has encontrado esos fragmentos?! Necesitarás el pergamino de Myzrael para cazarla de nuevo ¡antes de que sea demasiado tarde!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los has encontrado! ¡Buen trabajo, $n! ¡Puede que esta sea la única oportunidad contra la perversa Myzrael!$B$BDame un segundo para encontrar mi trinquete y ver si puedo recomponer estos fragmentos...', 0),
(@ID, 'esMX', '¡Ah, los has encontrado! ¡Buen trabajo, $n! ¡Puede que esta sea la única oportunidad contra la perversa Myzrael!$B$BDame un segundo para encontrar mi trinquete y ver si puedo recomponer estos fragmentos...', 0);
-- 656 Invocar a la princesa
-- https://es.classic.wowhead.com/quest=656
SET @ID := 656;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los fragmentos Myzrael están sospechosamente callados.', 0),
(@ID, 'esMX', 'Los fragmentos Myzrael están sospechosamente callados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al colocar los grilletes de Eldritch alrededor de los fragmentos, se oye un lejano gemido inhumano en el subsuelo. Tras este lamento se oye un rugido.$B$BLos fragmentos de Myzrael ya no invocan cálidos sentimientos de seguridad como otrora hicieran. Laten ahora con una amenaza abierta... como si lo que los sustenta encerrara una voluntad enferma para con la superficie.', 0),
(@ID, 'esMX', 'Al colocar los grilletes de Eldritch alrededor de los fragmentos, se oye un lejano gemido inhumano en el subsuelo. Tras este lamento se oye un rugido.$B$BLos fragmentos de Myzrael ya no invocan cálidos sentimientos de seguridad como otrora hicieran. Laten ahora con una amenaza abierta... como si lo que los sustenta encerrara una voluntad enferma para con la superficie.', 0);
-- 1143 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1143
SET @ID := 1143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Athrikus Narassin es un antiguo y poderoso brujo. Quizás deberíamos esperar la ayuda de Delgren, pero obviamente él tenía mucha fe en ti para enviarte $gsolo:sola;.', 0),
(@ID, 'esMX', 'Athrikus Narassin es un antiguo y poderoso brujo. Quizás deberíamos esperar la ayuda de Delgren, pero obviamente él tenía mucha fe en ti para enviarte $gsolo:sola;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la muerte de Athrikus, espero que las fuerzas demoníacas en esta área se reduzcan. No tengo ninguna duda de que se reagruparán y regresarán, pero entonces estaremos mejor preparados para enfrentarnos a su amenaza.', 0),
(@ID, 'esMX', 'Con la muerte de Athrikus, espero que las fuerzas demoníacas en esta área se reduzcan. No tengo ninguna duda de que se reagruparán y regresarán, pero entonces estaremos mejor preparados para enfrentarnos a su amenaza.', 0);
-- 981 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=981
SET @ID := 981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que estarías a la altura de la tarea, $N.$B$BPresiento grandes hazañas ante ti y que corregirás muchos de los males que asolan nuestras tierras. Lleva mis bendiciones, $n, así como este regalo.', 0),
(@ID, 'esMX', 'Sabía que estarías a la altura de la tarea, $N.$B$BPresiento grandes hazañas ante ti y que corregirás muchos de los males que asolan nuestras tierras. Lleva mis bendiciones, $n, así como este regalo.', 0);
-- Cubo de caramelos
-- 12286, 12331, 12332, 12333, 12334, 12335, 12336, 12337, 12338, 12339, 12340, 12341, 12342, 12343, 12344, 12345, 12346, 12347, 12348, 12349, 12350, 12351, 12352, 12353, 12354, 12355, 12356, 12357, 12358, 12359, 12360, 12361, 12362, 12363, 12364, 12365, 12366, 12367, 12368, 12369, 12370, 12371, 12373, 12374, 12375, 12376, 12377, 12378, 12379, 12380, 12381, 12382, 12383, 12384, 12385, 12386, 12387, 12388, 12389, 12390, 12391, 12392, 12393, 12394, 12395, 12396, 12397, 12398, 12399, 12400, 12401, 12402, 12403, 12404, 12405, 12406, 12407, 12408, 12409, 12410, 12940, 12941, 12944, 12945, 12946, 12947, 12950, 13433, 13434, 13435, 13436, 13437, 13438, 13439, 13448, 13452, 13456, 13459, 13460, 13461, 13462, 13463, 13464, 13465, 13466, 13467, 13468, 13469, 13470, 13471, 13472, 13473, 13474, 13501, 13548
-- https://es.classic.wowhead.com/quest=12286
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(12286, 12331, 12332, 12333, 12334, 12335, 12336, 12337, 12338, 12339, 12340, 12341, 12342, 12343, 12344, 12345, 12346, 12347, 12348, 12349, 12350, 12351, 12352, 12353, 12354, 12355, 12356, 12357, 12358, 12359, 12360, 12361, 12362, 12363, 12364, 12365, 12366, 12367, 12368, 12369, 12370, 12371, 12373, 12374, 12375, 12376, 12377, 12378, 12379, 12380, 12381, 12382, 12383, 12384, 12385, 12386, 12387, 12388, 12389, 12390, 12391, 12392, 12393, 12394, 12395, 12396, 12397, 12398, 12399, 12400, 12401, 12402, 12403, 12404, 12405, 12406, 12407, 12408, 12409, 12410, 12940, 12941, 12944, 12945, 12946, 12947, 12950, 13433, 13434, 13435, 13436, 13437, 13438, 13439, 13448, 13452, 13456, 13459, 13460, 13461, 13462, 13463, 13464, 13465, 13466, 13467, 13468, 13469, 13470, 13471, 13472, 13473, 13474, 13501, 13548) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(12286, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12331, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12332, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12333, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12334, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12335, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12336, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12337, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12338, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12339, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12340, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12341, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12342, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12343, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12344, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12345, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12346, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12347, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12348, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12349, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12350, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12351, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12352, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12353, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12354, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12355, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12356, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12357, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12358, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12359, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12360, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12361, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12362, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12363, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12364, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12365, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12366, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12367, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12368, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12369, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12370, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12371, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12373, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12374, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12375, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12376, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12377, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12378, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12379, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12380, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12381, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12382, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12383, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12384, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12385, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12386, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12387, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12388, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12389, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12390, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12391, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12392, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12393, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12394, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12395, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12396, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12397, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12398, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12399, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12400, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12401, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12402, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12403, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12404, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12405, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12406, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12407, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12408, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12409, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12410, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12940, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12941, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12944, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12945, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12946, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12947, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12950, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13433, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13434, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13435, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13436, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13437, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13438, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13439, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13448, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13452, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13456, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13459, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13460, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13461, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13462, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13463, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13464, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13465, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13466, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13467, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13468, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13469, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13470, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13471, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13472, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13473, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13474, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13501, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13548, 'esES', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12286, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12331, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12332, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12333, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12334, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12335, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12336, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12337, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12338, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12339, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12340, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12341, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12342, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12343, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12344, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12345, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12346, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12347, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12348, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12349, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12350, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12351, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12352, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12353, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12354, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12355, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12356, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12357, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12358, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12359, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12360, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12361, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12362, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12363, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12364, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12365, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12366, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12367, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12368, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12369, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12370, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12371, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12373, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12374, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12375, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12376, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12377, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12378, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12379, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12380, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12381, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12382, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12383, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12384, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12385, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12386, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12387, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12388, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12389, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12390, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12391, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12392, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12393, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12394, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12395, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12396, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12397, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12398, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12399, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12400, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12401, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12402, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12403, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12404, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12405, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12406, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12407, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12408, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12409, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12410, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12940, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12941, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12944, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12945, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12946, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12947, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(12950, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13433, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13434, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13435, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13436, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13437, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13438, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13439, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13448, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13452, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13456, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13459, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13460, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13461, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13462, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13463, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13464, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13465, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13466, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13467, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13468, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13469, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13470, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13471, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13472, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13473, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13474, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13501, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0),
(13548, 'esMX', 'Hay cubos de caramelos como este en tabernas por los reinos. No te cortes, ¡coge!', 0);

-- 1027 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1027
SET @ID := 1027;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la última pieza de la vara, $n?', 0),
(@ID, 'esMX', '¿Has encontrado la última pieza de la vara, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la última pieza? Fantástico para ti... y para Raene.$B$BBueno, habrá que ver si la arreglamos, ¿no?', 0),
(@ID, 'esMX', '¿Has encontrado la última pieza? Fantástico para ti... y para Raene.$B$BBueno, habrá que ver si la arreglamos, ¿no?', 0);
-- 1028 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1028
SET @ID := 1028;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque sutil, se siente una poderosa fuerza en el altar y los árboles circundantes.$B$BEmpieza por colocar la vara en el interior del altar y se oirá un repiqueteo suave alrededor del altar que empezará a irradiar luz...', 0),
(@ID, 'esMX', 'Aunque sutil, se siente una poderosa fuerza en el altar y los árboles circundantes.$B$BEmpieza por colocar la vara en el interior del altar y se oirá un repiqueteo suave alrededor del altar que empezará a irradiar luz...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando se apague el brillo, verás que la vara vuelve a estar encantada en la pila del altar.', 0),
(@ID, 'esMX', 'Cuando se apague el brillo, verás que la vara vuelve a estar encantada en la pila del altar.', 0);
-- 1055 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1055
SET @ID := 1055;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado, $n! ¡Muy bien!', 0),
(@ID, 'esMX', '¡Lo has logrado, $n! ¡Muy bien!', 0);
-- 1029 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1029
SET @ID := 1029;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recreado la vara que Teronis se había propuesto encontrar? ¡Qué alegría oírlo!$B$BTeronis estaría orgulloso de ver que su misión se completó incluso después de su trágico fin.', 0),
(@ID, 'esMX', '¿Has recreado la vara que Teronis se había propuesto encontrar? ¡Qué alegría oírlo!$B$BTeronis estaría orgulloso de ver que su misión se completó incluso después de su trágico fin.', 0);
-- 1030 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1030
SET @ID := 1030;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí... eres como yo, pero aún completo. Aún limpio.$B$BNo estoy seguro de cómo has conseguido librarte de las atrocidades que los elfos de la noche han infligido a nuestro pueblo pero me alegro de saber que ya no estoy solo.$B$BLa corrupción corre ahora por las venas de los nuestros, joven, corrupción que los orgullosos elfos de la noche nos trajeron. Son los que le han hecho esto a nuestro pueblo... A ellos culpo por haberme apartado de mi tribu.$B$BDe noche aún puedo ver las fogatas en la oscuridad.', 0),
(@ID, 'esMX', 'Sí, sí... eres como yo, pero aún completo. Aún limpio.$B$BNo estoy seguro de cómo has conseguido librarte de las atrocidades que los elfos de la noche han infligido a nuestro pueblo pero me alegro de saber que ya no estoy solo.$B$BLa corrupción corre ahora por las venas de los nuestros, joven, corrupción que los orgullosos elfos de la noche nos trajeron. Son los que le han hecho esto a nuestro pueblo... A ellos culpo por haberme apartado de mi tribu.$B$BDe noche aún puedo ver las fogatas en la oscuridad.', 0);
-- 1045 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1045
SET @ID := 1045;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Ran ya, amigo mío?$B$BIncluso los elfos de la noche no merecen realmente su ira. Su odio arde aún más brillante que el mío, pero su mente ya no es la suya. Es una amenaza para todas las criaturas de este bosque.', 0),
(@ID, 'esMX', '¿Has matado a Ran ya, amigo mío?$B$BIncluso los elfos de la noche no merecen realmente su ira. Su odio arde aún más brillante que el mío, pero su mente ya no es la suya. Es una amenaza para todas las criaturas de este bosque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, mi amigo.$B$BEl bosque aún está contaminado pero al menos hemos hecho algo para devolverle parte de su gloria pasada. Si quieres volver aquí, siempre disfruto de la compañía de uno de los míos.$B$BCuídate. Quizás nuestras tribus vuelvan a encontrarse en tiempos menos violentos.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, mi amigo.$B$BEl bosque aún está contaminado pero al menos hemos hecho algo para devolverle parte de su gloria pasada. Si quieres volver aquí, siempre disfruto de la compañía de uno de los míos.$B$BCuídate. Quizás nuestras tribus vuelvan a encontrarse en tiempos menos violentos.', 0);
-- 1046 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1046
SET @ID := 1046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las centinelas hacen lo que pueden aquí en Vallefresno pero es gracias a $r como tú que hemos recuperado el terreno.', 0),
(@ID, 'esMX', 'Las centinelas hacen lo que pueden aquí en Vallefresno pero es gracias a $r como tú que hemos recuperado el terreno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que esta es la calavera de la amenaza fúrbolg más feroz de Vallefresno?$B$BTus facultades son todo un portento, $n. Las centinelas no pueden agradecértelo lo suficiente. Espero que podamos volver a contar contigo en el futuro para ayudar a nuestro pueblo.$B$BPondré esta calavera y la vara de Dartol en un lugar de veneración para que los demás las vean.$B$BTeronis estaría orgulloso de ti. Gracias otra vez.', 0),
(@ID, 'esMX', '¿Así que esta es la calavera de la amenaza fúrbolg más feroz de Vallefresno?$B$BTus facultades son todo un portento, $n. Las centinelas no pueden agradecértelo lo suficiente. Espero que podamos volver a contar contigo en el futuro para ayudar a nuestro pueblo.$B$BPondré esta calavera y la vara de Dartol en un lugar de veneración para que los demás las vean.$B$BTeronis estaría orgulloso de ti. Gracias otra vez.', 0);
-- 1016 Brazales elementales
-- https://es.classic.wowhead.com/quest=1016
SET @ID := 1016;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puesto que debes destruir los brazales para matar los elementales, no será fácil encontrar los que contienen la información que el pergamino de adivinación requiere. Puedes intercambiar brazales con otros para conseguir los que necesitas o ¿acaso tienes ya el papel adivinado?', 0),
(@ID, 'esMX', 'Puesto que debes destruir los brazales para matar los elementales, no será fácil encontrar los que contienen la información que el pergamino de adivinación requiere. Puedes intercambiar brazales con otros para conseguir los que necesitas o ¿acaso tienes ya el papel adivinado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n, con esto deberíamos conseguir la información que necesitamos para descubrir al culpable. ¿Qué te parecería enfrentarte al mago que llena nuestras pozas de elementales corruptos? La corrupción de Vallefresno y más allá me revuelve el estómago, pero que un mago esté intentando llevar aún más lejos esta destrucción me pone enferma como nunca nada antes lo ha hecho. Haremos que pague por ello.', 0),
(@ID, 'esMX', 'Muy bien, $n, con esto deberíamos conseguir la información que necesitamos para descubrir al culpable. ¿Qué te parecería enfrentarte al mago que llena nuestras pozas de elementales corruptos? La corrupción de Vallefresno y más allá me revuelve el estómago, pero que un mago esté intentando llevar aún más lejos esta destrucción me pone enferma como nunca nada antes lo ha hecho. Haremos que pague por ello.', 0);
-- 1017 Mago invocador
-- https://es.classic.wowhead.com/quest=1017
SET @ID := 1017;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya está? ¿Ha muerto Sarilus Fuenteviciosa?', 0),
(@ID, 'esMX', '¿Ya está? ¿Ha muerto Sarilus Fuenteviciosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora veo su repugnante sonrisa borrada de su rostro para siempre. Lo has hecho muy bien, $n. Acepta este presente, la Luz de Elune, bébela cuando todo parezca perdido y la muerte se acerque. Podría salvarte, la Diosa mediante.', 0),
(@ID, 'esMX', 'Ahora veo su repugnante sonrisa borrada de su rostro para siempre. Lo has hecho muy bien, $n. Acepta este presente, la Luz de Elune, bébela cuando todo parezca perdido y la muerte se acerque. Podría salvarte, la Diosa mediante.', 0);
-- 622 Regresa junto al cabo Kaleb
-- https://es.classic.wowhead.com/quest=622
SET @ID := 622;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has logrado llegar a la Bahía del Botín? ¿El goblin Krazek me ha arreglado la olla?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has logrado llegar a la Bahía del Botín? ¿El goblin Krazek me ha arreglado la olla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Funciona! Esto es fantástico, ahora podré ponerme a preparar la cena. Muchísimas gracias, $n.$B$BEspero que no tuvieras problemas en la Bahía del Botín. Ese lugar puede ser bastante peliagudo y... he oído rumores que dicen que, algunas veces, los goblins se llevan a marineros borrachos a sus barcos de esclavos... quién sabe dónde... para hacer quién sabe qué...', 0),
(@ID, 'esMX', '¡Funciona! Esto es fantástico, ahora podré ponerme a preparar la cena. Muchísimas gracias, $n.$B$BEspero que no tuvieras problemas en la Bahía del Botín. Ese lugar puede ser bastante peliagudo y... he oído rumores que dicen que, algunas veces, los goblins se llevan a marineros borrachos a sus barcos de esclavos... quién sabe dónde... para hacer quién sabe qué...', 0);
-- 11522
-- https://es.wowhead.com/quest=11522
SET @ID := 11522;
DELETE FROM `quest_template_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_template_locale` (`id`, `locale`, `Details`, `VerifiedBuild`) VALUES
(@ID, 'esES', '[PH]Por alguna razón,(TBD),$BTienes que reunir 5 Raicez de Rajaespina.$B$BEstos solo se pueden encontrar en una ubicación remota al noreste de Shattrath, justo cuando subes a la cima de la Península del Fuego Infernal.', 0),
(@ID, 'esMX', '[PH]Por alguna razón,(TBD),$BTienes que reunir 5 Raicez de Rajaespina.$B$BEstos solo se pueden encontrar en una ubicación remota al noreste de Shattrath, justo cuando subes a la cima de la Península del Fuego Infernal.', 0);
-- 9755
-- https://es.wowhead.com/quest=9755
SET @ID := 9755;
DELETE FROM `quest_template_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_template_locale` (`id`, `locale`, `Details`, `Objectives`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los intentos de interrogatorio han fracasado estrepitosamente, $n. La tortura queda totalmente descartada, por supuesto. Lo que necesitamos es un infiltrado draenei.$B$BTe lanzaré un hechizo que te dará el aspecto y modo de hablar de un elfo de sangre; puede que los agentes capturados nos den la información que necesitamos.$B$BHabla con ellos y averigua todo lo que puedas.$B$BUna cosa, $n, no salgas de la Avanzada de Sangre o el hechizo se anulará.', 'Habla con un agente Halcón del Sol capturado en Avanzada de Sangre y consigue información. Luego ve a ver al exarca Admetius.', 0),
(@ID, 'esMX', 'Los intentos de interrogatorio han fracasado estrepitosamente, $n. La tortura queda totalmente descartada, por supuesto. Lo que necesitamos es un infiltrado draenei.$B$BTe lanzaré un hechizo que te dará el aspecto y modo de hablar de un elfo de sangre; puede que los agentes capturados nos den la información que necesitamos.$B$BHabla con ellos y averigua todo lo que puedas.$B$BUna cosa, $n, no salgas de la Avanzada de Sangre o el hechizo se anulará.', 'Habla con un agente Halcón del Sol capturado en Avanzada de Sangre y consigue información. Luego ve a ver al exarca Admetius.', 0);
-- 9748 Agua que no has de beber...
-- https://es.classic.wowhead.com/quest=9748
SET @ID := 9748;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No bebas ese agua, $n!', 0),
(@ID, 'esMX', '¡No bebas ese agua, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como sospechaba, el agua se ha teñido de rojo por la contaminación que se filtra del fluido del núcleo.$B$BEspero que no hayas nadado en esa agua contaminada.', 0),
(@ID, 'esMX', 'Como sospechaba, el agua se ha teñido de rojo por la contaminación que se filtra del fluido del núcleo.$B$BEspero que no hayas nadado en esa agua contaminada.', 0);
-- 2 La garfa de Garfafilada
-- https://es.classic.wowhead.com/quest=2
SET @ID := 2;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, $gpoderoso:poderosa; $c, he presentido tu llegada. Confío que tienes más noticias que darme sobre tu caza.', 0),
(@ID, 'esMX', 'Sí, $gpoderoso:poderosa; $c, he presentido tu llegada. Confío que tienes más noticias que darme sobre tu caza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De lo más impresionante, $n... ¡no puede haber sido un paseo conseguir la garra de Garrafilada! ¡La Caza de Vallefresno te está yendo bien!$B$BGarrafilada lleva muchos años aterrorizando a los peones de los aserraderos cuando se trasladan a Puesto del Hachazo y se cruzan en su ruta. No lo dudes, cuando se corra la voz de que doblegaste a ese monstruo, ¡se escucharán muchas canciones alabando tu valor en los campamentos y aserraderos de todo Vallefresno!', 0),
(@ID, 'esMX', 'De lo más impresionante, $n... ¡no puede haber sido un paseo conseguir la garra de Garrafilada! ¡La Caza de Vallefresno te está yendo bien!$B$BGarrafilada lleva muchos años aterrorizando a los peones de los aserraderos cuando se trasladan a Puesto del Hachazo y se cruzan en su ruta. No lo dudes, cuando se corra la voz de que doblegaste a ese monstruo, ¡se escucharán muchas canciones alabando tu valor en los campamentos y aserraderos de todo Vallefresno!', 0);
-- 1475 En El Templo de Atal'Hakkar
-- https://es.classic.wowhead.com/quest=1475
SET @ID := 1475;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras el crepúsculo desciende lentamente sobre mi carrera, me dirijo a ti, $n, para que me ayudes en mi búsqueda final de la Liga de Exploradores. Si mis viejos huesos pudieran reunir la fuerza para desafiar el Pantano de los Dolores y el templo hundido, estaría luchando junto a ti.$B$BEl orgullo me dificulta pedir tu ayuda para recolectar las tabletas Atal\'ai. Pero la vejez obliga a la necesidad.$B$BPor favor, ayúdame, $n. Quiero retirarme de la Liga de Exploradores habiendo completado su licitación final.', 0),
(@ID, 'esMX', 'Mientras el crepúsculo desciende lentamente sobre mi carrera, me dirijo a ti, $n, para que me ayudes en mi búsqueda final de la Liga de Exploradores. Si mis viejos huesos pudieran reunir la fuerza para desafiar el Pantano de los Dolores y el templo hundido, estaría luchando junto a ti.$B$BEl orgullo me dificulta pedir tu ayuda para recolectar las tabletas Atal\'ai. Pero la vejez obliga a la necesidad.$B$BPor favor, ayúdame, $n. Quiero retirarme de la Liga de Exploradores habiendo completado su licitación final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las tablillas Atal\'ai! ¡Gracias, $n!$B$BUna vez que las entregue a la Liga de Exploradores, nuestros nombres pasarán juntos a la historia. Has ayudado a un viejo enano a cumplir su última obligación en la vida. Por eso te estoy eternamente agradecido.', 0),
(@ID, 'esMX', '¡Las tablillas Atal\'ai! ¡Gracias, $n!$B$BUna vez que las entregue a la Liga de Exploradores, nuestros nombres pasarán juntos a la historia. Has ayudado a un viejo enano a cumplir su última obligación en la vida. Por eso te estoy eternamente agradecido.', 0);
-- 1474 El vínculo
-- https://es.classic.wowhead.com/quest=1474
SET @ID := 1474;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los poderes de más allá del vacío, el súcubo es uno de los más peligrosos, ya que los débiles se atrapan más fácilmente entre sus dedos.$B$BRecuerda eso ahora y en el futuro.', 0),
(@ID, 'esMX', 'De los poderes de más allá del vacío, el súcubo es uno de los más peligrosos, ya que los débiles se atrapan más fácilmente entre sus dedos.$B$BRecuerda eso ahora y en el futuro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más, lo has hecho bien, $n. Ha pasado bastante tiempo desde que vi a $gun:una; $c joven con tanto potencial como tú. Ten la seguridad de que seguiré observando tu progreso y me prepararé para ayudarte en tus pruebas futuras.$B$BPor ahora, déjame mostrarte el hechizo de invocación para tu súcubo recién dominado.', 0),
(@ID, 'esMX', 'Una vez más, lo has hecho bien, $n. Ha pasado bastante tiempo desde que vi a $gun:una; $c joven con tanto potencial como tú. Ten la seguridad de que seguiré observando tu progreso y me prepararé para ayudarte en tus pruebas futuras.$B$BPor ahora, déjame mostrarte el hechizo de invocación para tu súcubo recién dominado.', 0);
-- 978 Lechúcico Lunadón
-- https://es.classic.wowhead.com/quest=978
SET @ID := 978;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De dónde pueden haber surgido estos poderes? Creo que estamos siguiendo la pista correcta para encontrar la respuesta, $n.', 0),
(@ID, 'esMX', '¿De dónde pueden haber surgido estos poderes? Creo que estamos siguiendo la pista correcta para encontrar la respuesta, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya puedo comparar las plumas... Veamos...', 0),
(@ID, 'esMX', 'Ya puedo comparar las plumas... Veamos...', 0);
-- 3783 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=3783
SET @ID := 3783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0),
(@ID, 'esMX', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0),
(@ID, 'esMX', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0);
-- 6603 Problemas en Cuna del Invierno
-- https://es.classic.wowhead.com/quest=6603
SET @ID := 6603;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, hola! ¿Así que Meggi te habló de los problemas que he tenido aquí?', 0),
(@ID, 'esMX', '¡Eh, hola! ¿Así que Meggi te habló de los problemas que he tenido aquí?', 0);
-- 6604 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=6604
SET @ID := 6604;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¿qué puedo hacer por ti?', 0),
(@ID, 'esMX', 'Sí, ¿qué puedo hacer por ti?', 0);
-- 5601 Pamela, mi hermana
-- https://es.classic.wowhead.com/quest=5601
SET @ID := 5601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi hermana Jessica? Se fue hace mucho tiempo, cuando yo era muy pequeña. Lloró un montón cuando se fue. ¡No sé por qué lloraba! Igual se cayó y se hizo daño.$B$BCuando Jessica estaba aquí, jugábamos a cosas y bailábamos y recogíamos flores. Y a veces nos escondíamos cuando veíamos que venía papá a casa, ¡y luego salíamos y le dábamos un susto!$B$B¡Vuelve, Jessica! Si vuelves, igual vuelve también papá y podremos volver a jugar todos juntos...', 0),
(@ID, 'esMX', '¿Dónde está mi hermana Jessica? Se fue hace mucho tiempo, cuando yo era muy pequeña. Lloró un montón cuando se fue. ¡No sé por qué lloraba! Igual se cayó y se hizo daño.$B$BCuando Jessica estaba aquí, jugábamos a cosas y bailábamos y recogíamos flores. Y a veces nos escondíamos cuando veíamos que venía papá a casa, ¡y luego salíamos y le dábamos un susto!$B$B¡Vuelve, Jessica! Si vuelves, igual vuelve también papá y podremos volver a jugar todos juntos...', 0);
-- 6028 El informe Vista Eterna
-- https://es.classic.wowhead.com/quest=6028
SET @ID := 6028;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. En nombre del Alba Argenta, te ofrezco seguridad y refugio mientras estás aquí en el Campamento del Orvallo. También podría tener algo de trabajo para ti...', 0),
(@ID, 'esMX', 'Saludos, $n. En nombre del Alba Argenta, te ofrezco seguridad y refugio mientras estás aquí en el Campamento del Orvallo. También podría tener algo de trabajo para ti...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gregor es muy ingenioso. Ha estado lidiando con el Cártel Bonvapor desde hace algún tiempo y se ha convertido en un experto en el "arte" de las negociaciones con goblins. Aunque es cierto que la principal lealtad de los goblins reside en quienes tienen los monederos más grandes, también conocen y respetan el valor de la diplomacia. En todo caso, les proporciona clientes habituales...$B$BEn cualquier caso, el Alba Argenta te agradece tu esfuerzo. Por favor, toma esto junto con nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Gregor es muy ingenioso. Ha estado lidiando con el Cártel Bonvapor desde hace algún tiempo y se ha convertido en un experto en el "arte" de las negociaciones con goblins. Aunque es cierto que la principal lealtad de los goblins reside en quienes tienen los monederos más grandes, también conocen y respetan el valor de la diplomacia. En todo caso, les proporciona clientes habituales...$B$BEn cualquier caso, el Alba Argenta te agradece tu esfuerzo. Por favor, toma esto junto con nuestro agradecimiento.', 0);
-- 6030 El duque Nicolas Zverenhoff
-- https://es.classic.wowhead.com/quest=6030
SET @ID := 6030;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la Luz te guíe en estos tiempos confusos, $c. ¿Qué te trae a este faro de esperanza en medio de la oscuridad y la desesperación?', 0),
(@ID, 'esMX', 'Que la Luz te guíe en estos tiempos confusos, $c. ¿Qué te trae a este faro de esperanza en medio de la oscuridad y la desesperación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Me... me has traído un libro muy especial. Me gustaría decirte que, en este caso, "especial" significa "único y muy posiblemente iluminador", pero todavía hay que verlo.$B$B"¿Ooooo?" ¿A quién en su sano juicio se le ocurría esto?$B$BBien, he oído hablar de ese Umbranse del que te habló Gregor, será una ventaja. Haré todo lo que pueda por descifrarlo. En cuanto a ti... por favor, toma esto, cortesía del Alba Argenta. Mientras estés por aquí quizás puedas ayudarnos con alguna otra cosa.', 0),
(@ID, 'esMX', '"Me... me has traído un libro muy especial. Me gustaría decirte que, en este caso, "especial" significa "único y muy posiblemente iluminador", pero todavía hay que verlo.$B$B"¿Ooooo?" ¿A quién en su sano juicio se le ocurría esto?$B$BBien, he oído hablar de ese Umbranse del que te habló Gregor, será una ventaja. Haré todo lo que pueda por descifrarlo. En cuanto a ti... por favor, toma esto, cortesía del Alba Argenta. Mientras estés por aquí quizás puedas ayudarnos con alguna otra cosa.', 0);

-- 969 Que la suerte sea contigo
-- https://es.classic.wowhead.com/quest=969
SET @ID := 969;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Trae las esquirlas y te diré algo más!', 0),
(@ID, 'esMX', '¡Trae las esquirlas y te diré algo más!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahh, sí... te haré el talismán ahora mismo. ¡Espera un segundo!', 0),
(@ID, 'esMX', 'Ahh, sí... te haré el talismán ahora mismo. ¡Espera un segundo!', 0);
-- 5054 Ursius de los Dentoesquirla
-- https://es.classic.wowhead.com/quest=5054
SET @ID := 5054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vete ahora, $c. Busca a Ursius.', 0),
(@ID, 'esMX', 'Vete ahora, $c. Busca a Ursius.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No era una tarea fácil, pero has sido sobresaliente. Pero no vayas tan deprisa, no creas que me has impresionado, $n.', 0),
(@ID, 'esMX', 'No era una tarea fácil, pero has sido sobresaliente. Pero no vayas tan deprisa, no creas que me has impresionado, $n.', 0);
-- 5244 Las Ruinas de Kel'Theril
-- https://es.classic.wowhead.com/quest=5244
SET @ID := 5244;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, claro, puedo darte más información sobre Kel\'Theril. Sabes, no soy historiador, pero puedo contarte todo lo que vi...', 0),
(@ID, 'esMX', 'Sí, claro, puedo darte más información sobre Kel\'Theril. Sabes, no soy historiador, pero puedo contarte todo lo que vi...', 0);
-- 5245 Espíritus condenados de Kel'Theril
-- https://es.classic.wowhead.com/quest=5245
SET @ID := 5245;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué has venido?', 0),
(@ID, 'esMX', '¿Por qué has venido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quiero hablar sobre el pasado de los elfos nobles, $n. Por favor, me horroriza pensar en todo lo que ocurrió... Y no hay ninguna forma de corregir las cosas.', 0),
(@ID, 'esMX', 'No quiero hablar sobre el pasado de los elfos nobles, $n. Por favor, me horroriza pensar en todo lo que ocurrió... Y no hay ninguna forma de corregir las cosas.', 0);
-- 4861 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4861
SET @ID := 4861;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una caja muy dañada destaca entre el resto de las pertenencias destruidas en el campamento...', 0),
(@ID, 'esMX', 'Una caja muy dañada destaca entre el resto de las pertenencias destruidas en el campamento...', 0);
-- 3783 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=3783
SET @ID := 3783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0),
(@ID, 'esMX', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0),
(@ID, 'esMX', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0);
-- 977 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=977
SET @ID := 977;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acabo de terminar de poner las pieles, $n. Por favor, ¡date prisa con esos cuernos!', 0),
(@ID, 'esMX', 'Acabo de terminar de poner las pieles, $n. Por favor, ¡date prisa con esos cuernos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a enseñárselo a mis amigos! Espera, es solo un momento... voy a poner estas...$B$B¡Perfecto!', 0),
(@ID, 'esMX', '¡No puedo esperar a enseñárselo a mis amigos! Espera, es solo un momento... voy a poner estas...$B$B¡Perfecto!', 0);
-- 5055 Brumerán de los Orvallo
-- https://es.classic.wowhead.com/quest=5055
SET @ID := 5055;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Brumeran te llama, $n.', 0),
(@ID, 'esMX', 'Brumeran te llama, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí. Has regresado. Ahora creo que eres un auténtico $c por naturaleza. Te has enfrentado a las criaturas más fieras y has regresado, superando todas mis expectativas.$B$BYa estás preparado para mi última petición.', 0),
(@ID, 'esMX', 'Sí. Has regresado. Ahora creo que eres un auténtico $c por naturaleza. Te has enfrentado a las criaturas más fieras y has regresado, superando todas mis expectativas.$B$BYa estás preparado para mi última petición.', 0);
-- 5056 Shi-Rotam
-- https://es.classic.wowhead.com/quest=5056
SET @ID := 5056;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Shy-Rotam es audaz e implacable; defenderá a los suyos con ferviente entusiasmo.', 0),
(@ID, 'esMX', 'Shy-Rotam es audaz e implacable; defenderá a los suyos con ferviente entusiasmo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu fuerza y determinación. Te esperan muchos más desafíos, pero ya has probado ser tan capaz como yo mismo puedo serlo.', 0),
(@ID, 'esMX', 'Has demostrado tu fuerza y determinación. Te esperan muchos más desafíos, pero ya has probado ser tan capaz como yo mismo puedo serlo.', 0);
-- 4863 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4863
SET @ID := 4863;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al acercarte al carro, no parece que aquí haya mucho más para Jaron. Pero, mirando al suelo, notas algunas cajas que parecen intactas, a pesar de estar medio enterradas en la nieve.', 0),
(@ID, 'esMX', 'Al acercarte al carro, no parece que aquí haya mucho más para Jaron. Pero, mirando al suelo, notas algunas cajas que parecen intactas, a pesar de estar medio enterradas en la nieve.', 0);
-- 4864 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4864
SET @ID := 4864;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Cuéntame la noticia.', 0),
(@ID, 'esMX', 'Sí... Cuéntame la noticia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, esperaba escuchar lo mismo, $gmuchacho:muchacha;. Pensé que las bestias enloquecidas destruyeron todas mis pertenencias...$B$BPero encontraste mis herramientas y, lo más importante, ¡el amuleto! Me pregunto por qué los salvajes defendieron tan ferozmente este objeto... ¡En cualquier caso, lo pensaré dos veces antes de seguir su camino!', 0),
(@ID, 'esMX', 'Bueno, esperaba escuchar lo mismo, $gmuchacho:muchacha;. Pensé que las bestias enloquecidas destruyeron todas mis pertenencias...$B$BPero encontraste mis herramientas y, lo más importante, ¡el amuleto! Me pregunto por qué los salvajes defendieron tan ferozmente este objeto... ¡En cualquier caso, lo pensaré dos veces antes de seguir su camino!', 0);
-- 975 Alijo de Mau'ari
-- https://es.classic.wowhead.com/quest=975
SET @ID := 975;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí lo tieneh, $n. Recuerda, contigo lo llevah. ¿Por qué no volver a la naturaleza y veh qué encontrar?', 0),
(@ID, 'esMX', 'Aquí lo tieneh, $n. Recuerda, contigo lo llevah. ¿Por qué no volver a la naturaleza y veh qué encontrar?', 0);
-- 4807 E'ko de lechúcico salvaje
-- https://es.classic.wowhead.com/quest=4807
SET @ID := 4807;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con unah criaturah que parecen tener una habilidad mágica innata. Loh lechúcicoh pueden utilizar magia muy poderosa. Si quiereh aumentar tu intelecto tráeme el E\'ko que encontraráh en lah lechubehtiah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con unah criaturah que parecen tener una habilidad mágica innata. Loh lechúcicoh pueden utilizar magia muy poderosa. Si quiereh aumentar tu intelecto tráeme el E\'ko que encontraráh en lah lechubehtiah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4805 E'ko de los Cardo Nevado
-- https://es.classic.wowhead.com/quest=4805
SET @ID := 4805;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con enormeh criaturah llamadah Yeti Cardo Nevado. Son behtiah lentah pero pueden evadir muchoh golpeh por la protección que leh da su ehpeso pelaje. Si deseah obtener la habilidad de esquivar ataqueh, tráeme el E\'ko que encuentreh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con enormeh criaturah llamadah Yeti Cardo Nevado. Son behtiah lentah pero pueden evadir muchoh golpeh por la protección que leh da su ehpeso pelaje. Si deseah obtener la habilidad de esquivar ataqueh, tráeme el E\'ko que encuentreh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4803 E'ko Dentoesquirla
-- https://es.classic.wowhead.com/quest=4803
SET @ID := 4803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno encontraráh grandeh osoh con unah pieleh extremadamente durah y gruesah. Loh osoh dentoesquirla obtienen mucha protección de lo que pueden resihtir. Si quiereh resihtencia al Fuego, tráeme el E\'ko que encontraráh en loh dentoesquirla.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario para poder obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno encontraráh grandeh osoh con unah pieleh extremadamente durah y gruesah. Loh osoh dentoesquirla obtienen mucha protección de lo que pueden resihtir. Si quiereh resihtencia al Fuego, tráeme el E\'ko que encontraráh en loh dentoesquirla.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario para poder obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4806 E'ko de los Machacahielo
-- https://es.classic.wowhead.com/quest=4806
SET @ID := 4806;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno combatiráh con unoh enormeh giganteh de hielo llamadoh Machacahielo. Suyoh son el poder y la fuerza máh puroh. Si quiereh ganar la fuerza del Machacahielo tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno combatiráh con unoh enormeh giganteh de hielo llamadoh Machacahielo. Suyoh son el poder y la fuerza máh puroh. Si quiereh ganar la fuerza del Machacahielo tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4802 E'ko Nevada
-- https://es.classic.wowhead.com/quest=4802
SET @ID := 4802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno combatiráh con unah criaturah dehcarriadah conocidah como loh furbolgs Nevada. Siguiendo loh deseoh de su líder se han hecho increíblemente fuerteh. Si quiereh el poder de loh Nevada tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno combatiráh con unah criaturah dehcarriadah conocidah como loh furbolgs Nevada. Siguiendo loh deseoh de su líder se han hecho increíblemente fuerteh. Si quiereh el poder de loh Nevada tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4804 E'ko Orvallo
-- https://es.classic.wowhead.com/quest=4804
SET @ID := 4804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con unah grandeh criaturah voladorah llamadah Quimerah Venfrehco. Estah behtiah poseen el poder de usar la magia de hielo. Si deseah ganar resihtencia a lah heladah, tráeme el E\'ko que encuentreh en ellah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con unah grandeh criaturah voladorah llamadah Quimerah Venfrehco. Estah behtiah poseen el poder de usar la magia de hielo. Si deseah ganar resihtencia a lah heladah, tráeme el E\'ko que encuentreh en ellah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4801 E'ko de sable de hielo
-- https://es.classic.wowhead.com/quest=4801
SET @ID := 4801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, lucharáh contra grandeh felinoh llamadoh sableh de hielo. Estah behtiah poseen una increíble velocidad y ahtucia. Si quiereh ganar la velocidad de un sable de hielo, tráeme el E\'ko que encuentreh en elloh.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, lucharáh contra grandeh felinoh llamadoh sableh de hielo. Estah behtiah poseen una increíble velocidad y ahtucia. Si quiereh ganar la velocidad de un sable de hielo, tráeme el E\'ko que encuentreh en elloh.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 2661 Un envío para Marin
-- https://es.classic.wowhead.com/quest=2661
SET @ID := 2661;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, al fin has vuelto. ¿Qué traes?', 0),
(@ID, 'esMX', 'Ah, $n, al fin has vuelto. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Polvo violeta, eh? Déjame que lo pruebe... De todos modos, es imposible que empeore las cosas.', 0),
(@ID, 'esMX', '¿Polvo violeta, eh? Déjame que lo pruebe... De todos modos, es imposible que empeore las cosas.', 0);
-- 2662 El elixir de Tragonublo
-- https://es.classic.wowhead.com/quest=2662
SET @ID := 2662;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Dale un trago! ¡¡¡Es estupendo!!!$B$BSabía que lo conseguiría... Gracias otra vez por tu ayuda, $n. Eso sí, hazte a un lado. ¡Estás interrumpiendo mi trabajo! ¡Voy a hacerme rico con este fabuloso Elixir de Tragonublo! ¡Rico!$B$B¿Cómo? ¿Roxio dice que le debo una? ¡Hay que ver qué sentido del humor tiene Roxio!', 0),
(@ID, 'esMX', '¡Dale un trago! ¡¡¡Es estupendo!!!$B$BSabía que lo conseguiría... Gracias otra vez por tu ayuda, $n. Eso sí, hazte a un lado. ¡Estás interrumpiendo mi trabajo! ¡Voy a hacerme rico con este fabuloso Elixir de Tragonublo! ¡Rico!$B$B¿Cómo? ¿Roxio dice que le debo una? ¡Hay que ver qué sentido del humor tiene Roxio!', 0);
-- 4496 Que jungla tan chunga
-- https://es.classic.wowhead.com/quest=4496
SET @ID := 4496;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No es fácil conseguir una glándula secretora de olor que sirva; la glándula ha de estar en perfecto estado pero el proceso para obtenerla generalmente hace que eso sea imposible. Con la tierra supongo que no habrás tenido tantos problemas.$B$BEn cualquier caso, ¿tienes lo que necesito para fabricar el señuelo?', 0),
(@ID, 'esMX', 'No es fácil conseguir una glándula secretora de olor que sirva; la glándula ha de estar en perfecto estado pero el proceso para obtenerla generalmente hace que eso sea imposible. Con la tierra supongo que no habrás tenido tantos problemas.$B$BEn cualquier caso, ¿tienes lo que necesito para fabricar el señuelo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La glándula secretora de olor, ¡qué bien! ¡Estupendo! La membrana parece estar intacta. Y la tierra, sí, creo que servirá. Con esto y un pequeño toque personal, crearé el señuelo perfecto.$B$BDame un momento para prepararlo, $n. Cuando lo tenga, podremos dar el siguiente paso en nuestro intento de detener la expansión de los silítidos por Gadgetzan... y todo Kalimdor.', 0),
(@ID, 'esMX', 'La glándula secretora de olor, ¡qué bien! ¡Estupendo! La membrana parece estar intacta. Y la tierra, sí, creo que servirá. Con esto y un pequeño toque personal, crearé el señuelo perfecto.$B$BDame un momento para prepararlo, $n. Cuando lo tenga, podremos dar el siguiente paso en nuestro intento de detener la expansión de los silítidos por Gadgetzan... y todo Kalimdor.', 0);

-- 3528 El dios Hakkar
-- https://es.classic.wowhead.com/quest=3528
SET @ID := 3528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado al avatar de Hakkar, $n? ¿Has encerrado su esencia en el huevo que te di?', 0),
(@ID, 'esMX', '¿Has derrotado al avatar de Hakkar, $n? ¿Has encerrado su esencia en el huevo que te di?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La esencia de Hakkar está encerrada! ¡Aun así, el huevo rezuma vida! ¿Será cierto el mito sobre Hakkar?$B$BEspero que no pues quién sabe qué haría Hakkar si volviera a nacer. Guardaré el huevo en un lugar seguro para que no caiga en malas manos.$B$BTu trabajo conmigo ha concluido, $n. Ahora eres una auténtica leyenda y tus acciones algún día cambiarán nuestro mundo.', 0),
(@ID, 'esMX', '¡La esencia de Hakkar está encerrada! ¡Aun así, el huevo rezuma vida! ¿Será cierto el mito sobre Hakkar?$B$BEspero que no pues quién sabe qué haría Hakkar si volviera a nacer. Guardaré el huevo en un lugar seguro para que no caiga en malas manos.$B$BTu trabajo conmigo ha concluido, $n. Ahora eres una auténtica leyenda y tus acciones algún día cambiarán nuestro mundo.', 0);
-- 5065 Las tablillas perdidas Mosh'aru
-- https://es.classic.wowhead.com/quest=5065
SET @ID := 5065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las tablillas? Me temo que sus textos revelarán una gran amenaza para nuestro mundo.', 0),
(@ID, 'esMX', '¿Tienes las tablillas? Me temo que sus textos revelarán una gran amenaza para nuestro mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los encontraste! ¡Excelente!$B$BGracias, $n. Repasaré estos textos y descifraré su significado.$B$BTú, sin embargo, tienes otra tarea...', 0),
(@ID, 'esMX', '¡Los encontraste! ¡Excelente!$B$BGracias, $n. Repasaré estos textos y descifraré su significado.$B$BTú, sin embargo, tienes otra tarea...', 0);
-- 4289 Los simios de Un'Goro
-- https://es.classic.wowhead.com/quest=4289
SET @ID := 4289;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has dejado vencer por las criaturas, $n?$B$BNo te rindas tan fácilmente. Perseguir y derrotar a los simios de Un\'Goro no es tarea fácil, ni siquiera para $gun:una; gran $c.', 0),
(@ID, 'esMX', '¿Te has dejado vencer por las criaturas, $n?$B$BNo te rindas tan fácilmente. Perseguir y derrotar a los simios de Un\'Goro no es tarea fácil, ni siquiera para $gun:una; gran $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado poseer la fuerza necesaria para vencer a los grandes simios de Un\'Goro, lo cual está muy bien. Aunque no se pueda comparar con enfrentarse a Lar\'korwi, tu hazaña no deja de tener mérito.$B$BCon estas pieles mi tribu podrá confeccionar estupendos ropajes. Me has prestado una valiosa ayuda.$B$BAntes de que te marches, alabemos a la Madre Tierra y demos gracias a los espíritus de los simios que mataste, pues su muerte no ha sido en vano.', 0),
(@ID, 'esMX', 'Has demostrado poseer la fuerza necesaria para vencer a los grandes simios de Un\'Goro, lo cual está muy bien. Aunque no se pueda comparar con enfrentarse a Lar\'korwi, tu hazaña no deja de tener mérito.$B$BCon estas pieles mi tribu podrá confeccionar estupendos ropajes. Me has prestado una valiosa ayuda.$B$BAntes de que te marches, alabemos a la Madre Tierra y demos gracias a los espíritus de los simios que mataste, pues su muerte no ha sido en vano.', 0);
-- 4290 La comida de Lar'korwi
-- https://es.classic.wowhead.com/quest=4290
SET @ID := 4290;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tomes mis palabras a la ligera, $n. Si realmente quieres enfrentarte a esta criatura, debes actuar con prudencia y habilidad. Conseguir que Lar\'korwi venga a por ti y finalmente derrotarlo requerirá mucha fuerza y perspicacia por tu parte.', 0),
(@ID, 'esMX', 'No tomes mis palabras a la ligera, $n. Si realmente quieres enfrentarte a esta criatura, debes actuar con prudencia y habilidad. Conseguir que Lar\'korwi venga a por ti y finalmente derrotarlo requerirá mucha fuerza y perspicacia por tu parte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta carne servirá, $n. Parece que Lar\'korwi no pasa hambre, ¿eh? Me pregunto dónde habrá encontrado un trillanodonte... es extraño.$B$BDe cualquier modo, guardaré esto hasta que estés $gpreparado:preparada; pare enfrentarte a él. No te preocupes por mí, pues estoy seguro de que has enfadado tanto a Lar\'korwi que no me hará daño hasta que te haya echado el diente a ti.', 0),
(@ID, 'esMX', 'Esta carne servirá, $n. Parece que Lar\'korwi no pasa hambre, ¿eh? Me pregunto dónde habrá encontrado un trillanodonte... es extraño.$B$BDe cualquier modo, guardaré esto hasta que estés $gpreparado:preparada; pare enfrentarte a él. No te preocupes por mí, pues estoy seguro de que has enfadado tanto a Lar\'korwi que no me hará daño hasta que te haya echado el diente a ti.', 0);
-- 3884 Diario de Williden
-- https://es.classic.wowhead.com/quest=3884
SET @ID := 3884;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¡Mis compañeros y yo nos alegramos de ver formas de vida que no sean bestias salvajes hiperdesarrolladas! ¿Qué te trae al Cráter de Un\'Goro?', 0),
(@ID, 'esMX', '¡Hola! ¡Mis compañeros y yo nos alegramos de ver formas de vida que no sean bestias salvajes hiperdesarrolladas! ¿Qué te trae al Cráter de Un\'Goro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, mira eso! ¡Mi diario! Pensaba que estaba perdido, como casi todo lo que trajimos a Un\'Goro. ¡Muchísimas gracias por devolvérmelo!', 0),
(@ID, 'esMX', '¡Vaya, mira eso! ¡Mi diario! Pensaba que estaba perdido, como casi todo lo que trajimos a Un\'Goro. ¡Muchísimas gracias por devolvérmelo!', 0);
-- 3844 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3844
SET @ID := 3844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encuentras una talega empapada en el fondo del estanque.', 0),
(@ID, 'esMX', 'Encuentras una talega empapada en el fondo del estanque.', 0);
-- 3845 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3845
SET @ID := 3845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Ya te había visto antes... ¿no es cierto?', 0),
(@ID, 'esMX', 'Hola. Ya te había visto antes... ¿no es cierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... sí, esto me resulta familiar... en cierto modo...', 0),
(@ID, 'esMX', 'Oh... sí, esto me resulta familiar... en cierto modo...', 0);
-- 4291 Un aroma irresistible para Lar'korwi
-- https://es.classic.wowhead.com/quest=4291
SET @ID := 4291;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado, $n. Al acercarte a los nidos de huevos provocarás la ira de las madres... aunque ya tengas una de sus glándulas. Las madres pueden ser tan peligrosas como Lar\'korwi cuando se trata de defender a sus retoños. Sin embargo, si tienes éxito, será nuestra última oportunidad de conseguir que Lar\'korwi salga de su escondrijo.', 0),
(@ID, 'esMX', 'Ten cuidado, $n. Al acercarte a los nidos de huevos provocarás la ira de las madres... aunque ya tengas una de sus glándulas. Las madres pueden ser tan peligrosas como Lar\'korwi cuando se trata de defender a sus retoños. Sin embargo, si tienes éxito, será nuestra última oportunidad de conseguir que Lar\'korwi salga de su escondrijo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndidas glándulas, $n! Serán el cebo perfecto para atraer a Lar\'korwi. Estoy deseando ver cómo resulta tu enfrentamiento con ese monstruo. Es una mole con unas garras afiladas como cuchillos y en sus ojos se refleja la muerte.', 0),
(@ID, 'esMX', '¡Espléndidas glándulas, $n! Serán el cebo perfecto para atraer a Lar\'korwi. Estoy deseando ver cómo resulta tu enfrentamiento con ese monstruo. Es una mole con unas garras afiladas como cuchillos y en sus ojos se refleja la muerte.', 0);
-- 4292 El cebo para Lar'korwi
-- https://es.classic.wowhead.com/quest=4292
SET @ID := 4292;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejes que el miedo te bloquee, $n. El miedo es traicionero... ¡pero debes superarlo!$B$BCoge la carne, déjala en el pequeño valle y después úntala con la glándula. En ese momento, la muerte vendrá a por ti.', 0),
(@ID, 'esMX', 'No dejes que el miedo te bloquee, $n. El miedo es traicionero... ¡pero debes superarlo!$B$BCoge la carne, déjala en el pequeño valle y después úntala con la glándula. En ese momento, la muerte vendrá a por ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabada sea la Madre Tierra! ¡Lo has conseguido! No cabe duda de que eres $gun:una; gran $gcazador:cazadora;. Has demostrado poseer fortaleza de espíritu y una valentía inigualable, y además has incrementado tu fuerza. Mereces todo mi respeto.$B$BSolo el más poderoso de mis ancestros habría sido capaz de realizar una hazaña como la tuya. Enhorabuena.', 0),
(@ID, 'esMX', '¡Alabada sea la Madre Tierra! ¡Lo has conseguido! No cabe duda de que eres $gun:una; gran $gcazador:cazadora;. Has demostrado poseer fortaleza de espíritu y una valentía inigualable, y además has incrementado tu fuerza. Mereces todo mi respeto.$B$BSolo el más poderoso de mis ancestros habría sido capaz de realizar una hazaña como la tuya. Enhorabuena.', 0);
-- 4243 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4243
SET @ID := 4243;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observas a Memo 01 y ves que la maravillosa creación de ingeniería de Karna tiene dos enormes abolladuras, una en el hombro y otra en la cabeza.$B$BAdemás, te das cuenta de que no funciona.', 0),
(@ID, 'esMX', 'Observas a Memo 01 y ves que la maravillosa creación de ingeniería de Karna tiene dos enormes abolladuras, una en el hombro y otra en la cabeza.$B$BAdemás, te das cuenta de que no funciona.', 0);
-- 4503 El aparato volador de Shizzle
-- https://es.classic.wowhead.com/quest=4503
SET @ID := 4503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo gran vehículo necesita un nombre... Estaba pensando en llamarlo... ¡Pwned!', 0),
(@ID, 'esMX', 'Todo gran vehículo necesita un nombre... Estaba pensando en llamarlo... ¡Pwned!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, estas escamas son perfectas. ¡Ahora no debería tener ningún problema para hacer volar a este cacharro!$B$B¡Gracias!', 0),
(@ID, 'esMX', 'Sí, estas escamas son perfectas. ¡Ahora no debería tener ningún problema para hacer volar a este cacharro!$B$B¡Gracias!', 0);
-- 3908 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3908
SET @ID := 3908;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, vaya... Así que Linken por fin ha encontrado algo de tiempo para mandarme su espada.', 0),
(@ID, 'esMX', 'Vaya, vaya... Así que Linken por fin ha encontrado algo de tiempo para mandarme su espada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, claro que puedo templar la espada. Mientras trabajo puedes ir explicándome por qué le ha costado tanto tiempo a Linken traérmela. No suele olvidarse de nada...', 0),
(@ID, 'esMX', 'Sí, claro que puedo templar la espada. Mientras trabajo puedes ir explicándome por qué le ha costado tanto tiempo a Linken traérmela. No suele olvidarse de nada...', 0);
-- 4492 ¡Perdido!
-- https://es.classic.wowhead.com/quest=4492
SET @ID := 4492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eh.. qué?', 0),
(@ID, 'esMX', '¿Eh.. qué?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... qué alegría que me hayas encontrado...', 0),
(@ID, 'esMX', 'Oh... qué alegría que me hayas encontrado...', 0);
-- 4501 Cuidado con los pterrordáctilos
-- https://es.classic.wowhead.com/quest=4501
SET @ID := 4501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para decirte la verdad, realmente no estaba tan preocupado por las extrañas criaturas ... Hasta el día en que lo vi escrito en el costado de una gran piedra.$B$BCUIDADO CON LOS PTERRORDÁCTILOS$B$B¿Quién pudo haberlo escrito? No lo sé, ¡pero es demasiado espeluznante como para ignorarlo!', 0),
(@ID, 'esMX', 'Para decirte la verdad, realmente no estaba tan preocupado por las extrañas criaturas ... Hasta el día en que lo vi escrito en el costado de una gran piedra.$B$BCUIDADO CON LOS PTERRORDÁCTILOS$B$B¿Quién pudo haberlo escrito? No lo sé, ¡pero es demasiado espeluznante como para ignorarlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los Pterrordáctilos me dan un miedo horrible! Gracias por hacer que sean menos, $n. Ahora quizás me atreva a salir del Refugio de Marshal.', 0),
(@ID, 'esMX', '¡Los Pterrordáctilos me dan un miedo horrible! Gracias por hacer que sean menos, $n. Ahora quizás me atreva a salir del Refugio de Marshal.', 0);
-- 3882 Choca esos huesos
-- https://es.classic.wowhead.com/quest=3882
SET @ID := 3882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Piensa lo que quieras de mí, pero no se darán cuenta de que los huesos que investigan son de stegodones y diemetradones antiguos o de los que casi nos devoraron cuando intentábamos establecer nuestros campamentos. Yo solo estaré contento si salgo de aquí con vida...', 0),
(@ID, 'esMX', 'Piensa lo que quieras de mí, pero no se darán cuenta de que los huesos que investigan son de stegodones y diemetradones antiguos o de los que casi nos devoraron cuando intentábamos establecer nuestros campamentos. Yo solo estaré contento si salgo de aquí con vida...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, estos deberían servirnos. Y ahora, si me lo permites...$B$BGRACIAS POR DESENTERRAR TODOS ESTOS HUESOS PARA NOSOTROS Y NO HACER NI UN SOLO RASGUÑO A LAS BESTIAS NATIVAS.$B$BSi lo hiciste o no, no lo sé ni me importa. Dejémoslo tal y como está, ¿de acuerdo? Toma, quizás con esto mantengas la boca cerrada... ¡Estoy dispuesto a cualquier cosa con tal de salir de aquí con vida, ya te lo dije!', 0),
(@ID, 'esMX', 'Excelente, estos deberían servirnos. Y ahora, si me lo permites...$B$BGRACIAS POR DESENTERRAR TODOS ESTOS HUESOS PARA NOSOTROS Y NO HACER NI UN SOLO RASGUÑO A LAS BESTIAS NATIVAS.$B$BSi lo hiciste o no, no lo sé ni me importa. Dejémoslo tal y como está, ¿de acuerdo? Toma, quizás con esto mantengas la boca cerrada... ¡Estoy dispuesto a cualquier cosa con tal de salir de aquí con vida, ya te lo dije!', 0);
-- 5150 ¡Dadanga tiene hambre!
-- https://es.classic.wowhead.com/quest=5150
SET @ID := 5150;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dadanga te observa mientras te acercas a ella. Parece que espera algo...$B$B¡Probablemente esté hambrienta!$B$BSeguro que en el cráter hay algo que le puede servir de aperitivo a una gran herbívora como ella. Ten en cuenta que es una chica muy grande así que, traigas lo que traigas, ¡que sea en abundancia!', 0),
(@ID, 'esMX', 'Dadanga te observa mientras te acercas a ella. Parece que espera algo...$B$B¡Probablemente esté hambrienta!$B$BSeguro que en el cráter hay algo que le puede servir de aperitivo a una gran herbívora como ella. Ten en cuenta que es una chica muy grande así que, traigas lo que traigas, ¡que sea en abundancia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que a Dadanga le gustan los brotes que le has traído.$B$BA cambio, te entrega un pequeño paquete.', 0),
(@ID, 'esMX', 'Parece que a Dadanga le gustan los brotes que le has traído.$B$BA cambio, te entrega un pequeño paquete.', 0);
-- 3883 Ecología alienígena
-- https://es.classic.wowhead.com/quest=3883
SET @ID := 3883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la muestra de la colmena Gorishi para que la estudie, $n?', 0),
(@ID, 'esMX', '¿Tienes la muestra de la colmena Gorishi para que la estudie, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esto servirá. Has sido de gran ayuda... Ojalá pudiera darte algo más, pero estando aquí atrapada en medio de la nada no tengo muchas cosas que ofrecerte. Pero descansa tranquilo, ¡esta investigación no hubiera sido posible sin tu ayuda!', 0),
(@ID, 'esMX', 'Sí, esto servirá. Has sido de gran ayuda... Ojalá pudiera darte algo más, pero estando aquí atrapada en medio de la nada no tengo muchas cosas que ofrecerte. Pero descansa tranquilo, ¡esta investigación no hubiera sido posible sin tu ayuda!', 0);
-- 3881 Salvar a la expedición
-- https://es.classic.wowhead.com/quest=3881
SET @ID := 3881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si existe la más mínima posibilidad de salir de aquí con vida, necesitaremos nuestro cajón de comestibles. Además, recuperar algo de nuestro equipo de investigación sería un rayo de luz en un océano de desgracias.', 0),
(@ID, 'esMX', 'Si existe la más mínima posibilidad de salir de aquí con vida, necesitaremos nuestro cajón de comestibles. Además, recuperar algo de nuestro equipo de investigación sería un rayo de luz en un océano de desgracias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Conseguiste recuperar nuestros comestibles Y nuestro equipo de investigación! No solo has salvado la expedición, ¡has salvado nuestras vidas! Yo y el resto de mi equipo no podemos agradecértelo lo suficiente. Has hecho posible que podamos quedarnos aquí por un tiempo.$B$BAunque no tenemos mucho, no vamos a permitir que te vayas con las manos vacías después de toda la ayuda que nos has prestado. Gracias, $n, ¡ahora tienes un amigo en las Expediciones Marshal!', 0),
(@ID, 'esMX', '¡Conseguiste recuperar nuestros comestibles Y nuestro equipo de investigación! No solo has salvado la expedición, ¡has salvado nuestras vidas! Yo y el resto de mi equipo no podemos agradecértelo lo suficiente. Has hecho posible que podamos quedarnos aquí por un tiempo.$B$BAunque no tenemos mucho, no vamos a permitir que te vayas con las manos vacías después de toda la ayuda que nos has prestado. Gracias, $n, ¡ahora tienes un amigo en las Expediciones Marshal!', 0);
-- 4141 Muigin y Larion
-- https://es.classic.wowhead.com/quest=4141
SET @ID := 4141;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Larion no sabe lo que le espera!', 0),
(@ID, 'esMX', '¡Larion no sabe lo que le espera!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no te hayan causado demasiados problemas, $n. A ver si puedo dominarlas... ¡parecen salvajes!$B$BY si las piso... ¡Ah, me han atacado! ¡Las plantas no deberían comportarse de ese modo!', 0),
(@ID, 'esMX', 'Espero que no te hayan causado demasiados problemas, $n. A ver si puedo dominarlas... ¡parecen salvajes!$B$BY si las piso... ¡Ah, me han atacado! ¡Las plantas no deberían comportarse de ese modo!', 0);
-- 4142 Visita a Gregan
-- https://es.classic.wowhead.com/quest=4142
SET @ID := 4142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vivo en el bosque... en paz.$B$B¡O así pensaba que sería! ¡Recibo más visitas aquí que cuando vivía en Forjaz!', 0),
(@ID, 'esMX', 'Vivo en el bosque... en paz.$B$B¡O así pensaba que sería! ¡Recibo más visitas aquí que cuando vivía en Forjaz!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un pétalo de sangre, ¿eh? Mmm... Explícame qué quieres y entonces te diré si puedo ayudarte o no.', 0),
(@ID, 'esMX', 'Un pétalo de sangre, ¿eh? Mmm... Explícame qué quieres y entonces te diré si puedo ayudarte o no.', 0);
-- 4244 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4244
SET @ID := 4244;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El panel en el que va la envoltura de mitril está cerrado y Memo 01 permanece inerte.', 0),
(@ID, 'esMX', 'El panel en el que va la envoltura de mitril está cerrado y Memo 01 permanece inerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Abres el panel trasero de Memo 01, retiras la vieja envoltura de mitril que parece haberse quemado e introduces la nueva con cuidado. Si este era realmente el problema, lo único que queda por hacer es apagar y encender de nuevo a Memo.', 0),
(@ID, 'esMX', '"Abres el panel trasero de Memo 01, retiras la vieja envoltura de mitril que parece haberse quemado e introduces la nueva con cuidado. Si este era realmente el problema, lo único que queda por hacer es apagar y encender de nuevo a Memo.', 0);

-- 4491 Un poco de ayuda de mis amigos
-- https://es.classic.wowhead.com/quest=4491
SET @ID := 4491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado tan preocupada por Ringo...', 0),
(@ID, 'esMX', 'He estado tan preocupada por Ringo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ringo no está en plena forma, $n, ¡pero me alegra tenerlo de vuelta de una sola pieza!$B$BGracias por encontrarle.', 0),
(@ID, 'esMX', 'Ringo no está en plena forma, $n, ¡pero me alegra tenerlo de vuelta de una sola pieza!$B$BGracias por encontrarle.', 0);
-- 979 Encuentra a Ranshalla
-- https://es.classic.wowhead.com/quest=979
SET @ID := 979;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Vienes de parte de Erelas? Genial, estaba preparándome para ir a las cuevas, no me importaría tener algo de compañía.', 0),
(@ID, 'esMX', '¡Hola! ¿Vienes de parte de Erelas? Genial, estaba preparándome para ir a las cuevas, no me importaría tener algo de compañía.', 0);
-- 5163 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=5163
SET @ID := 5163;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a saber cuál es la reacción de mis amigos!$B$B¡Nunca se lo esperarían!', 0),
(@ID, 'esMX', '¡No puedo esperar a saber cuál es la reacción de mis amigos!$B$B¡Nunca se lo esperarían!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡Se lo pensarán dos veces antes de volver a reírse de mis ideas!$B$BGracias por tu ayuda, $n. ¡Sin tu ayuda no habría podido divertirme tanto!', 0),
(@ID, 'esMX', '¡Ja! ¡Se lo pensarán dos veces antes de volver a reírse de mis ideas!$B$BGracias por tu ayuda, $n. ¡Sin tu ayuda no habría podido divertirme tanto!', 0);
-- 4901 Guardianes del altar
-- https://es.classic.wowhead.com/quest=4901
SET @ID := 4901;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te reuniste con Ranshalla?', 0),
(@ID, 'esMX', '¿Te reuniste con Ranshalla?', 0);
-- 5082 La amenaza de los Nevada
-- https://es.classic.wowhead.com/quest=5082
SET @ID := 5082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aprecio tu ayuda!', 0),
(@ID, 'esMX', '¡Aprecio tu ayuda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡!Muchas gracias, $n! Ya puedo seguir trabajando aquí$B$B¿Encontraste algo interesante en el campamento Nevada?', 0),
(@ID, 'esMX', '¡!Muchas gracias, $n! Ya puedo seguir trabajando aquí$B$B¿Encontraste algo interesante en el campamento Nevada?', 0);
-- 3909 El Elixir de Videre
-- https://es.classic.wowhead.com/quest=3909
SET @ID := 3909;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás de vuelta?', 0),
(@ID, 'esMX', '¿Ya estás de vuelta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré un vial para asegurarme de que este es de verdad el Elixir... Sí... Esto es.', 0),
(@ID, 'esMX', 'Necesitaré un vial para asegurarme de que este es de verdad el Elixir... Sí... Esto es.', 0);
-- 5057 Esfuerzos del pasado
-- https://es.classic.wowhead.com/quest=5057
SET @ID := 5057;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprendemos de nuestras experiencias vitales, $n. Estoy seguro de que las tuyas solo conseguirán hacerte más fuerte y $gsabio:sabia;. Has crecido mucho desde la primera vez que hablamos.$B$BToma esto como recuerdo de todas las difíciles tareas que has superado como $r $c, y no olvides que siempre tendrás mi respeto y admiración.', 0),
(@ID, 'esMX', 'Aprendemos de nuestras experiencias vitales, $n. Estoy seguro de que las tuyas solo conseguirán hacerte más fuerte y $gsabio:sabia;. Has crecido mucho desde la primera vez que hablamos.$B$BToma esto como recuerdo de todas las difíciles tareas que has superado como $r $c, y no olvides que siempre tendrás mi respeto y admiración.', 0);
-- 4902 Lechúcico salvaje de Elune
-- https://es.classic.wowhead.com/quest=4902
SET @ID := 4902;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No lo dudes; dime por qué has venido.$B$B¿Oh si? Hmm. Bien.$B$BGracias por acudir directamente a mi; siempre es mejor ir directo a la cima... Pero... Sí. Los druidas del Círculo Cenarion conocen a los Lechúcicos desde hace algún tiempo. Saben que son mascotas de Elune y que fueron elegidas para proteger los lugares más sagrados.$B$BSi bien esto no es noticia, definitivamente te felicito por tu esfuerzo. Toma, toma esto: es algo que parece adecuado por ese esfuerzo.', 0),
(@ID, 'esMX', 'No lo dudes; dime por qué has venido.$B$B¿Oh si? Hmm. Bien.$B$BGracias por acudir directamente a mi; siempre es mejor ir directo a la cima... Pero... Sí. Los druidas del Círculo Cenarion conocen a los Lechúcicos desde hace algún tiempo. Saben que son mascotas de Elune y que fueron elegidas para proteger los lugares más sagrados.$B$BSi bien esto no es noticia, definitivamente te felicito por tu esfuerzo. Toma, toma esto: es algo que parece adecuado por ese esfuerzo.', 0);
-- 3781 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3781
SET @ID := 3781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la paz y la serenidad sean contigo. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0),
(@ID, 'esMX', 'Que la paz y la serenidad sean contigo. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este vale es para veinte paquetes de semillas. Si se te acaban, podremos proporcionarte más. Aunque, por desgracia, producir grandes números de semillas de Tharlendris resulta bastante costoso. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste.$B$BQuienes traigan mañagrana, encontrarán que la recompensa que ofrece el archidruida compensa con creces ese coste.', 0),
(@ID, 'esMX', 'Sí, este vale es para veinte paquetes de semillas. Si se te acaban, podremos proporcionarte más. Aunque, por desgracia, producir grandes números de semillas de Tharlendris resulta bastante costoso. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste.$B$BQuienes traigan mañagrana, encontrarán que la recompensa que ofrece el archidruida compensa con creces ese coste.', 0);
-- 3785 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3785
SET @ID := 3785;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0);
-- 4143 Bruma del mal
-- https://es.classic.wowhead.com/quest=4143
SET @ID := 4143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Larion todavía no me habla! Seguro que sabe cómo guardar rencor.', 0),
(@ID, 'esMX', '¡Larion todavía no me habla! Seguro que sabe cómo guardar rencor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo admito, ¡estoy un poco reacio a tocar esas cosas, $n! Pero si Gregan dice que funcionará, ¡entonces estoy dispuesto a intentarlo!', 0),
(@ID, 'esMX', 'Lo admito, ¡estoy un poco reacio a tocar esas cosas, $n! Pero si Gregan dice que funcionará, ¡entonces estoy dispuesto a intentarlo!', 0);
-- 4144 Brotes Sangrepétalo
-- https://es.classic.wowhead.com/quest=4144
SET @ID := 4144;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el plan, $n: sal y recolecta algunos brotes de pétalos de sangre, ya sabes, las plantas que aún no han brotado por completo, y tráelas aquí. Entonces veré qué puede hacer la neblina Atal\'ai.$B$BPuedes pensar que soy vengativo... ¡En realidad, tendrías razón en eso!$B$BLa verdad es que conozco la manera de salir de aquí, pero hasta que Larion admita que tengo razón, ¡me quedaré aquí!$B$B¡Así que vete, encuentra esos brotes de pétalos de sangre y divirtámonos!', 0),
(@ID, 'esMX', 'Este es el plan, $n: sal y recolecta algunos brotes de pétalos de sangre, ya sabes, las plantas que aún no han brotado por completo, y tráelas aquí. Entonces veré qué puede hacer la neblina Atal\'ai.$B$BPuedes pensar que soy vengativo... ¡En realidad, tendrías razón en eso!$B$BLa verdad es que conozco la manera de salir de aquí, pero hasta que Larion admita que tengo razón, ¡me quedaré aquí!$B$B¡Así que vete, encuentra esos brotes de pétalos de sangre y divirtámonos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No pasa nada, $n! ¡Esto llamará la atención de Larion!', 0),
(@ID, 'esMX', '¡No pasa nada, $n! ¡Esto llamará la atención de Larion!', 0);
-- 8 Un trato de pícaro
-- https://es.classic.wowhead.com/quest=8
SET @ID := 8;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Sí? ¿Qué hay?$B$BEsos Renegados sí que tienen estómagos grandes. Tú ponte cómodo... Da un respiro a tu agotado esqueleto. Me llamo Renee, por si quieres algo.', 0),
(@ID, 'esMX', '¿Sí? ¿Sí? ¿Qué hay?$B$BEsos Renegados sí que tienen estómagos grandes. Tú ponte cómodo... Da un respiro a tu agotado esqueleto. Me llamo Renee, por si quieres algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eh? ¿Una carta? ¡Qué bien! Estaba esperando noticias de mi querida madre, que está en Camposanto. Es una santa, eso es lo que es. Me pregunto qué tal estará.$B$B¿Qué? ¿Qué? ¿Sueno demasiado alegre? No te he engañado, ¿eh?$B$BPues me da igual. Y además, tampoco te importa de quién es la carta. ¡Hala! ¡Aire!$B$BVuelve cuando tengas dinero que gastar, holgazán.$B$BYa volverás, ya, cuando necesites descansar después de unos días de aventuras o de alguna estupidez parecida.', 0),
(@ID, 'esMX', '¿Eh? ¿Una carta? ¡Qué bien! Estaba esperando noticias de mi querida madre, que está en Camposanto. Es una santa, eso es lo que es. Me pregunto qué tal estará.$B$B¿Qué? ¿Qué? ¿Sueno demasiado alegre? No te he engañado, ¿eh?$B$BPues me da igual. Y además, tampoco te importa de quién es la carta. ¡Hala! ¡Aire!$B$BVuelve cuando tengas dinero que gastar, holgazán.$B$BYa volverás, ya, cuando necesites descansar después de unos días de aventuras o de alguna estupidez parecida.', 0);
-- 23 La pata de Ursangous
-- https://es.classic.wowhead.com/quest=23
SET @ID := 23;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡precisamente estaba pensando en ti! ¿Cómo te va la caza?', 0),
(@ID, 'esMX', 'Ah, $n, ¡precisamente estaba pensando en ti! ¿Cómo te va la caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la zarpa de Ursangous! Tu talento me impresiona, $c; muchos han perecido bajo su ira. La media luna de su zarpa no deja lugar a dudas, los elfos de la noche que merodean por Vallefresno lo amaestraron. Ursangous es... era el oso más poderoso que podías encontrarte por estos lares. Derrotar a semejante criatura es toda una muestra de tu empeño y determinación.$B$B¡Tus antepasados estarían orgullosos de ti!', 0),
(@ID, 'esMX', '¡Ah, la zarpa de Ursangous! Tu talento me impresiona, $c; muchos han perecido bajo su ira. La media luna de su zarpa no deja lugar a dudas, los elfos de la noche que merodean por Vallefresno lo amaestraron. Ursangous es... era el oso más poderoso que podías encontrarte por estos lares. Derrotar a semejante criatura es toda una muestra de tu empeño y determinación.$B$B¡Tus antepasados estarían orgullosos de ti!', 0);
-- 21 Escaramuza en la Mina del Eco
-- https://es.classic.wowhead.com/quest=21
SET @ID := 21;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto a ganarte mi respeto y la gratitud del ejército de Ventormenta. Enviaré a otro equipo para ver si quedan kobolds en la mina; para ti tengo otras misiones.', 0),
(@ID, 'esMX', 'Has vuelto a ganarte mi respeto y la gratitud del ejército de Ventormenta. Enviaré a otro equipo para ver si quedan kobolds en la mina; para ti tengo otras misiones.', 0);
-- 24 La cabeza de Shadumbra
-- https://es.classic.wowhead.com/quest=24
SET @ID := 24;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos de nuevo, $n! ¿Has venido a mostrarme la prueba de tu caza?', 0),
(@ID, 'esMX', '¡Saludos de nuevo, $n! ¿Has venido a mostrarme la prueba de tu caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una victoria para $n en la Caza de Vallefresno! Muy bien, la cabeza de Shadumbra es sin lugar a dudas un trofeo apropiado para atribuirse tan impresionante lucha.$B$BLa ferocidad de Shadumbra era de sobras conocida en toda la avanzada. Cualquier viaje hacia el oeste, especialmente a pie para salir de La Ensenada de Zoram, conllevaba mucho riesgo debido a este tigre. Gracias a ti, este peligro ya no existe.', 0),
(@ID, 'esMX', '¡Una victoria para $n en la Caza de Vallefresno! Muy bien, la cabeza de Shadumbra es sin lugar a dudas un trofeo apropiado para atribuirse tan impresionante lucha.$B$BLa ferocidad de Shadumbra era de sobras conocida en toda la avanzada. Cualquier viaje hacia el oeste, especialmente a pie para salir de La Ensenada de Zoram, conllevaba mucho riesgo debido a este tigre. Gracias a ti, este peligro ya no existe.', 0);
-- 25 Paso del Espolón bloqueado
-- https://es.classic.wowhead.com/quest=25
SET @ID := 25;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya regresaste? ¿Cuál es la situación ahí fuera? ¿Todo se ha solucionado gracias a ti?', 0),
(@ID, 'esMX', '¿Ya regresaste? ¿Cuál es la situación ahí fuera? ¿Todo se ha solucionado gracias a ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, he oído que alguien había abierto el lago como un demonio de polvo por Los Baldíos. Parece que podríamos establecer un punto de observación por allí para mantener un ojo sobre nuestros amigos de la Alianza. Bueno, eso si conseguimos mantenerlo al nivel mínimo...$B$BParece que has resultado ser bastante útil después de todo; ahora el transporte entre este lugar y Espolón deberían ser menos accidentados. Aquí tienes, te lo has ganado.', 0),
(@ID, 'esMX', 'Sí, he oído que alguien había abierto el lago como un demonio de polvo por Los Baldíos. Parece que podríamos establecer un punto de observación por allí para mantener un ojo sobre nuestros amigos de la Alianza. Bueno, eso si conseguimos mantenerlo al nivel mínimo...$B$BParece que has resultado ser bastante útil después de todo; ahora el transporte entre este lugar y Espolón deberían ser menos accidentados. Aquí tienes, te lo has ganado.', 0);
-- 26 Una lección que aprender
-- https://es.classic.wowhead.com/quest=26
SET @ID := 26;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, joven $c; ha llegado el momento de que conozcas nuestra forma acuática. Es aquella que te permite moverte libre e indefinidamente por el agua. Encontrarás este aspecto como una herramienta útil y una bendición ... pero es algo que debes ganar antes de dominarlo.$B$BTe enfrentarás a dos pruebas que superar. La primera pondrá a prueba tu capacidad para trabajar en el agua y bajo presión. La segunda pondrá a prueba tu determinación para comprender los aspectos de la forma en sí.$B$BEstá $gpreparado:preparada;, ya que ha llegado el momento de la prueba.', 0),
(@ID, 'esMX', 'Saludos, joven $c; ha llegado el momento de que conozcas nuestra forma acuática. Es aquella que te permite moverte libre e indefinidamente por el agua. Encontrarás este aspecto como una herramienta útil y una bendición ... pero es algo que debes ganar antes de dominarlo.$B$BTe enfrentarás a dos pruebas que superar. La primera pondrá a prueba tu capacidad para trabajar en el agua y bajo presión. La segunda pondrá a prueba tu determinación para comprender los aspectos de la forma en sí.$B$BEstá $gpreparado:preparada;, ya que ha llegado el momento de la prueba.', 0);
-- 1125 Los espíritus de Viento del Sur
-- https://es.classic.wowhead.com/quest=1125
SET @ID := 1125;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alianza u Horda, no importa, ningún ser merece estar atrapado en este mundo como un espíritu torturado. La liberación de estas almas arreglará las cosas, $n.', 0),
(@ID, 'esMX', 'Alianza u Horda, no importa, ningún ser merece estar atrapado en este mundo como un espíritu torturado. La liberación de estas almas arreglará las cosas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creía que quizás la enorme colmena que está cerca de las ruinas de la aldea había tenido algo que ver. Tu trabajo ha demostrado que esto es correcto. La proximidad de la colmena supone una amenaza para cualquier trabajo futuro que podamos hacer aquí.$B$BTe agradezco lo que has hecho para liberar las almas de los caídos; ese tipo de trabajo no es fácil, lo sé. Sin embargo, cuando estés preparado, necesito volver a pedirte ayuda...', 0),
(@ID, 'esMX', 'Creía que quizás la enorme colmena que está cerca de las ruinas de la aldea había tenido algo que ver. Tu trabajo ha demostrado que esto es correcto. La proximidad de la colmena supone una amenaza para cualquier trabajo futuro que podamos hacer aquí.$B$BTe agradezco lo que has hecho para liberar las almas de los caídos; ese tipo de trabajo no es fácil, lo sé. Sin embargo, cuando estés preparado, necesito volver a pedirte ayuda...', 0);
-- 1126 Una colmena en la torre
-- https://es.classic.wowhead.com/quest=1126
SET @ID := 1126;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y qué? ¿Ha funcionado? Sigues de una pieza, me alegro. ¿Has encontrado algo?', 0),
(@ID, 'esMX', '¿Y qué? ¿Ha funcionado? Sigues de una pieza, me alegro. ¿Has encontrado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pero... ¿pero qué...?$B$B¿Tiene forma de... caja, quizás? Está recubierto de algo muy sólido. Espera, aquí hay una parte a la vista... ¿Es eso un libro lo que hay debajo de toda esa porquería?$B$BCreo que has encontrado un gran descubrimiento, $n... bueno, al menos eso espero. Quizás sea un diario o un registro de tiempos pasados guardado en este contenedor.$B$BCreo que sé la forma de descubrir lo que es.', 0),
(@ID, 'esMX', 'Pero... ¿pero qué...?$B$B¿Tiene forma de... caja, quizás? Está recubierto de algo muy sólido. Espera, aquí hay una parte a la vista... ¿Es eso un libro lo que hay debajo de toda esa porquería?$B$BCreo que has encontrado un gran descubrimiento, $n... bueno, al menos eso espero. Quizás sea un diario o un registro de tiempos pasados guardado en este contenedor.$B$BCreo que sé la forma de descubrir lo que es.', 0);
-- 4301 El poderoso U'cha
-- https://es.classic.wowhead.com/quest=4301
SET @ID := 4301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'U\'cha... ¡qué espléndida! De gran tamaño y color rojo, con unos dientes tan grandes como puñales. Sus brazos parecían troncos de árboles y era tan veloz como un león de la montaña. Deberías considerarte afortunado por haber puesto a prueba tu valentía de este modo... Mi pueblo no verá una criatura semejante durante varias generaciones.', 0),
(@ID, 'esMX', 'U\'cha... ¡qué espléndida! De gran tamaño y color rojo, con unos dientes tan grandes como puñales. Sus brazos parecían troncos de árboles y era tan veloz como un león de la montaña. Deberías considerarte afortunado por haber puesto a prueba tu valentía de este modo... Mi pueblo no verá una criatura semejante durante varias generaciones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Hoy has hecho algo grandioso.$B$BU\'cha era el gorila más grande que jamás haya visto. Con tu victoria has demostrado poseer gran fuerza y valor.$B$BPor favor, acepta esto como muestra de mi respeto. Te lo has ganado.', 0),
(@ID, 'esMX', 'Muy bien, $n. Hoy has hecho algo grandioso.$B$BU\'cha era el gorila más grande que jamás haya visto. Con tu victoria has demostrado poseer gran fuerza y valor.$B$BPor favor, acepta esto como muestra de mi respeto. Te lo has ganado.', 0);
-- 4245 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4245
SET @ID := 4245;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido ayudar a Memo? Esa carcasa de mithril que mencionaste fue destruida era una buena suposición de lo que estaba mal. Estoy seguro de que si reemplaza eso, se reactivará y podrá volver a casa.', 0),
(@ID, 'esMX', '¿Has podido ayudar a Memo? Esa carcasa de mithril que mencionaste fue destruida era una buena suposición de lo que estaba mal. Estoy seguro de que si reemplaza eso, se reactivará y podrá volver a casa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! ¡Estupendo! Gracias, $n.$B$BMi pobre Memo 01... ¡mira qué abolladuras! Con unos pequeños retoques, la dejaré como nueva.$B$BGracias de nuevo por tu inestimable ayuda, $n.', 0),
(@ID, 'esMX', '¡Lo has logrado! ¡Estupendo! Gracias, $n.$B$BMi pobre Memo 01... ¡mira qué abolladuras! Con unos pequeños retoques, la dejaré como nueva.$B$BGracias de nuevo por tu inestimable ayuda, $n.', 0);
-- 4507 El señuelo atrapa a la reina
-- https://es.classic.wowhead.com/quest=4507
SET @ID := 4507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para poder proseguir con la investigación, es imprescindible el cerebro de la reina. Por los datos que tenemos, creemos que posiblemente los silítidos estén controlados por una inteligencia maléfica. No quiero ni pensar en qué podría controlar algo tan insidioso como son los silítidos, $n.', 0),
(@ID, 'esMX', 'Para poder proseguir con la investigación, es imprescindible el cerebro de la reina. Por los datos que tenemos, creemos que posiblemente los silítidos estén controlados por una inteligencia maléfica. No quiero ni pensar en qué podría controlar algo tan insidioso como son los silítidos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, $n! Hoy hemos dado un paso más hacia la victoria. Nos llevará un tiempo entender de qué se trata, pero no te preocupes, le sacaremos provecho.$B$BEn cuanto a los silítidos, sinceramente dudo que la cosa acabe aquí. Siento tener que decirlo, pero es demasiado bonito para ser cierto.', 0),
(@ID, 'esMX', '¡Fantástico, $n! Hoy hemos dado un paso más hacia la victoria. Nos llevará un tiempo entender de qué se trata, pero no te preocupes, le sacaremos provecho.$B$BEn cuanto a los silítidos, sinceramente dudo que la cosa acabe aquí. Siento tener que decirlo, pero es demasiado bonito para ser cierto.', 0);

-- 8080, 8154, 8155, 8156, 8297 Los recursos de la Cuenca de Arathi
-- https://es.classic.wowhead.com/quest=8080
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8080, 8154, 8155, 8156, 8297) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8080, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8154, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8155, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8156, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8297, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8080, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8154, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8155, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8156, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8297, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`IN(8080, 8154, 8155, 8156, 8297) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8080, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8154, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8155, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8156, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8297, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8080, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8154, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8155, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8156, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8297, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0);
-- 8105, 8166, 8167, 8168 La batalla por la Cuenca de Arathi
-- https://es.classic.wowhead.com/quest=8168
DELETE FROM `quest_offer_reward_locale` WHERE `id`  IN(8105, 8166, 8167, 8168) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8105, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8166, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8167, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8168, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8105, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8166, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8167, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8168, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0);
-- 4508 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4508
SET @ID := 4508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son tontos, $n! Ni siquiera pueden pensar en mirar a su alrededor en busca de una amenaza mayor; su odio irracional hacia la Horda será el fin de todos nosotros. ¡No sé cuántas pruebas más puedo darles de la amenaza de los silítidos a menos que los arroje a una de las colmenas para que puedan ver por sí mismos!$B$BLo siento, ¿traes noticias para mi atención?', 0),
(@ID, 'esMX', '¡Son tontos, $n! Ni siquiera pueden pensar en mirar a su alrededor en busca de una amenaza mayor; su odio irracional hacia la Horda será el fin de todos nosotros. ¡No sé cuántas pruebas más puedo darles de la amenaza de los silítidos a menos que los arroje a una de las colmenas para que puedan ver por sí mismos!$B$BLo siento, ¿traes noticias para mi atención?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si bien realmente aprecio esto, no estoy seguro de qué beneficio nos dará. La Alianza ignora las amenazas de cualquier otra fuente que no sea la Horda, e incluso nuestros propios líderes aquí en Darnassus no pueden ponerse de acuerdo sobre qué es exactamente esta amenaza. Los tontos como Fandral Corcocelada teorizan que los silítidos no se parecen en nada a la amenaza del pasado que yo digo que son. Su ignorancia solo es superada por su arrogancia.', 0),
(@ID, 'esMX', 'Si bien realmente aprecio esto, no estoy seguro de qué beneficio nos dará. La Alianza ignora las amenazas de cualquier otra fuente que no sea la Horda, e incluso nuestros propios líderes aquí en Darnassus no pueden ponerse de acuerdo sobre qué es exactamente esta amenaza. Los tontos como Fandral Corcocelada teorizan que los silítidos no se parecen en nada a la amenaza del pasado que yo digo que son. Su ignorancia solo es superada por su arrogancia.', 0);
-- 8308 La carta perdida de Brann Barbabronce
-- https://es.wowhead.com/quest=8308
SET @ID := 8308;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya.', 0),
(@ID, 'esMX', 'Vaya.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explica mucho. Si alguna vez entras en Ahn\'Qiraj, busca al pobre Brann. Seguro que echa de menos al monito.', 0),
(@ID, 'esMX', 'Esto explica mucho. Si alguna vez entras en Ahn\'Qiraj, busca al pobre Brann. Seguro que echa de menos al monito.', 0);
-- 3912 Encuentro en la tumba
-- https://es.classic.wowhead.com/quest=3912
SET @ID := 3912;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha pasado mucho tiempo desde que vinieron a hablar conmigo por última vez...', 0),
(@ID, 'esMX', 'Ha pasado mucho tiempo desde que vinieron a hablar conmigo por última vez...', 0);
-- 6844 Umber, el archivista
-- https://es.classic.wowhead.com/quest=6844
SET @ID := 6844;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, hola! Mmm...$B$BVoy a hablarte con sinceridad, $gamigo:amiga;... apestas un poco. Tienes olor a pies, o algo así. No es que te esté atacando ni nada de eso. Solo digo que... en el futuro, quizás quieras refrescarte un poco después de salir del campo de batalla. De esa forma, las primeras impresiones que causes no serán tan impresionantes.$B$BEn fin... ¿Qué puedo hacer por ti?', 0),
(@ID, 'esMX', '¡Eh, hola! Mmm...$B$BVoy a hablarte con sinceridad, $gamigo:amiga;... apestas un poco. Tienes olor a pies, o algo así. No es que te esté atacando ni nada de eso. Solo digo que... en el futuro, quizás quieras refrescarte un poco después de salir del campo de batalla. De esa forma, las primeras impresiones que causes no serán tan impresionantes.$B$BEn fin... ¿Qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por las barbas de los sapos! ¿Qué llevas ahí? Tiene forma de libro... Intentaré romper la estructura que lo cubre.$B$B¿Layo te ha enviado a buscarme desde Silithus? Tan solo he oído susurros silenciosos, bueno, no tan silenciosos si los he oído, claro, sobre los horrores que están ocurriendo allí. Une eso a mi aversión por los bichos y tendrás la razón perfecta para que me quede aquí con los libros.', 0),
(@ID, 'esMX', '¡Por las barbas de los sapos! ¿Qué llevas ahí? Tiene forma de libro... Intentaré romper la estructura que lo cubre.$B$B¿Layo te ha enviado a buscarme desde Silithus? Tan solo he oído susurros silenciosos, bueno, no tan silenciosos si los he oído, claro, sobre los horrores que están ocurriendo allí. Une eso a mi aversión por los bichos y tendrás la razón perfecta para que me quede aquí con los libros.', 0);
-- 6845 Desvelar los secretos del pasado
-- https://es.classic.wowhead.com/quest=6845
SET @ID := 6845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n.$B$BTe estaba esperando para comunicarte la gratitud del Círculo Cenarion por tu ayuda. Acepta esto como muestra de agradecimiento.$B$BMuchas gracias, $c.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n.$B$BTe estaba esperando para comunicarte la gratitud del Círculo Cenarion por tu ayuda. Acepta esto como muestra de agradecimiento.$B$BMuchas gracias, $c.', 0);
-- 5526 Fragmentos de gangrevid
-- https://es.classic.wowhead.com/quest=5526
SET @ID := 5526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que tenemos el relicario de pureza, podremos eliminar la amenaza corruptora y además estudiarla. Tal vez nos ayude a crear más defensas frente a la corrupción que amenaza permanentemente a Azeroth.$B$BEs lo que habría querido Milli...', 0),
(@ID, 'esMX', 'Ahora que tenemos el relicario de pureza, podremos eliminar la amenaza corruptora y además estudiarla. Tal vez nos ayude a crear más defensas frente a la corrupción que amenaza permanentemente a Azeroth.$B$BEs lo que habría querido Milli...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Círculo Cenarion está en deuda contigo, $c, por ayudarnos a ganar esta batalla contra nuestros enemigos.$B$BPor favor, acepta esto en muestra de agradecimiento y la admiración del Círculo, $n.', 0),
(@ID, 'esMX', 'El Círculo Cenarion está en deuda contigo, $c, por ayudarnos a ganar esta batalla contra nuestros enemigos.$B$BPor favor, acepta esto en muestra de agradecimiento y la admiración del Círculo, $n.', 0);
-- 4510 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4510
SET @ID := 4510;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elune\'adore, $c. ¿Qué puedo hacer hoy por ti?', 0),
(@ID, 'esMX', 'Elune\'adore, $c. ¿Qué puedo hacer hoy por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este comprobante bancario me autoriza a retirar un artículo de la cuenta de Gracina Poderespíritu y entregártelo. ¡Felicidades, todo parece estar en orden!', 0),
(@ID, 'esMX', 'Este comprobante bancario me autoriza a retirar un artículo de la cuenta de Gracina Poderespíritu y entregártelo. ¡Felicidades, todo parece estar en orden!', 0);
-- 3913 Una situación mortal
-- https://es.classic.wowhead.com/quest=3913
SET @ID := 3913;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta debe ser la lápida que mencionó Gaeriyan...', 0),
(@ID, 'esMX', 'Esta debe ser la lápida que mencionó Gaeriyan...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empujas la lápida con fuerza, y se desliza a un lado mostrando un pequeño hueco debajo de ella.$B$BCuando colocas la Espada de Linken en el hueco te das cuenta de que encaja a la perfección...', 0),
(@ID, 'esMX', 'Empujas la lápida con fuerza, y se desliza a un lado mostrando un pequeño hueco debajo de ella.$B$BCuando colocas la Espada de Linken en el hueco te das cuenta de que encaja a la perfección...', 0);
-- 3914 La Espada de Linken
-- https://es.classic.wowhead.com/quest=3914
SET @ID := 3914;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh! ¡Te recuerdo!... Eres... ¡No, no me lo digas!', 0),
(@ID, 'esMX', '¡Oh! ¡Te recuerdo!... Eres... ¡No, no me lo digas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi espada... ¡está terminada!$B$BSi tan solo pudiera recordar para qué la necesitaba...$B$BToma, deja que al menos te pague algo por tu trabajo.', 0),
(@ID, 'esMX', 'Mi espada... ¡está terminada!$B$BSi tan solo pudiera recordar para qué la necesitaba...$B$BToma, deja que al menos te pague algo por tu trabajo.', 0);
-- 3941 La ayuda de una gnoma
-- https://es.classic.wowhead.com/quest=3941
SET @ID := 3941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espera solo un momento... Estoy probando una nueva combinación de cristales...', 0),
(@ID, 'esMX', 'Espera solo un momento... Estoy probando una nueva combinación de cristales...', 0);
-- 3942 Recuerdos de Linken
-- https://es.classic.wowhead.com/quest=3942
SET @ID := 3942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Puedo ayudarte en algo?', 0);
-- 4284 Cristales de poder
-- https://es.classic.wowhead.com/quest=4284
SET @ID := 4284;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Solo sé que he dado con algo, $n!', 0),
(@ID, 'esMX', '¡Solo sé que he dado con algo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora seguiré con mis experimentos! Gracias, $n.', 0),
(@ID, 'esMX', '¡Ahora seguiré con mis experimentos! Gracias, $n.', 0);
-- 4285 La Torre de cristal del Norte
-- https://es.classic.wowhead.com/quest=4285
SET @ID := 4285;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que las historias que cuentan son ciertas, $n.', 0),
(@ID, 'esMX', 'Sé que las historias que cuentan son ciertas, $n.', 0);
-- 4287 La Torre de cristal del Este
-- https://es.classic.wowhead.com/quest=4287
SET @ID := 4287;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un\'Goro es un lugar muy extraño, $n. Cuando entras en el cráter es como si estuvieras en un mundo totalmente distinto...', 0),
(@ID, 'esMX', 'Un\'Goro es un lugar muy extraño, $n. Cuando entras en el cráter es como si estuvieras en un mundo totalmente distinto...', 0);
-- 4288 La Torre de cristal del Oeste
-- https://es.classic.wowhead.com/quest=4288
SET @ID := 4288;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay muchas zonas secretas a los lados del cráter. Si no se te ocurre ningún otro sitio donde buscar intenta explorar los caminos más intrincados, $n.', 0),
(@ID, 'esMX', 'Hay muchas zonas secretas a los lados del cráter. Si no se te ocurre ningún otro sitio donde buscar intenta explorar los caminos más intrincados, $n.', 0);
-- 974 Busca la fuente
-- https://es.classic.wowhead.com/quest=974
SET @ID := 974;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Iría allí yo mismo, pero... ¡me dan algo de miedo los elementales de fuego!', 0),
(@ID, 'esMX', 'Iría allí yo mismo, pero... ¡me dan algo de miedo los elementales de fuego!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, veo claramente la relación entre la temperatura del volcán y las fuentes termales. Tengo que volver a comprobar mis ecuaciones pero parece que la distancia y la tasa de transferencia del calor... Ummm...', 0),
(@ID, 'esMX', 'Sí, veo claramente la relación entre la temperatura del volcán y las fuentes termales. Tengo que volver a comprobar mis ecuaciones pero parece que la distancia y la tasa de transferencia del calor... Ummm...', 0);
-- 980 Nuevos manantiales
-- https://es.classic.wowhead.com/quest=980
SET @ID := 980;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. Sí, lo que te dijo Krakle es cierto...', 0),
(@ID, 'esMX', 'Hola, $n. Sí, lo que te dijo Krakle es cierto...', 0);
-- 4321 Entender el significado
-- https://es.classic.wowhead.com/quest=4321
SET @ID := 4321;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Es fascinante... ¡sólo espero que mis diagramas sean correctos! Recogí toda la información en este manual, tómalo.$B$BCreo que ya puedo responder a cualquier pregunta que tengas sobre los cristales, $n.', 0),
(@ID, 'esMX', 'Muy bien, $n. Es fascinante... ¡sólo espero que mis diagramas sean correctos! Recogí toda la información en este manual, tómalo.$B$BCreo que ya puedo responder a cualquier pregunta que tengas sobre los cristales, $n.', 0);

-- 4101 Limpiar Frondavil
-- https://es.classic.wowhead.com/quest=4101
SET @ID := 4101;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme: si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme la sangre ámbar de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0),
(@ID, 'esMX', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme: si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme la sangre ámbar de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta sangre ámbar se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0),
(@ID, 'esMX', 'Esta sangre ámbar se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0);
-- 8460 Aliado Fauces de Madera
-- https://es.classic.wowhead.com/quest=8460
SET @ID := 8460;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue así, $n. Si deseas ganarte nuestra confianza, deberás demostrarnos tu valía.', 0),
(@ID, 'esMX', 'Sigue así, $n. Si deseas ganarte nuestra confianza, deberás demostrarnos tu valía.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sufrimos mucho por acontecimientos del pasado. Gracias por lo que has hecho para ayudar a proteger a los Fauces de Madera. Acepta esta humilde ofrenda como símbolo de nuestra creciente amistad.', 0),
(@ID, 'esMX', 'Sufrimos mucho por acontecimientos del pasado. Gracias por lo que has hecho para ayudar a proteger a los Fauces de Madera. Acepta esta humilde ofrenda como símbolo de nuestra creciente amistad.', 0);
-- 8462 Habla con Nafien
-- https://es.classic.wowhead.com/quest=8462
SET @ID := 8462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah... El viento me ha hecho llegar noticias de quienes no pertenecen a nuestra tribu y quieren aliarse con los fúrbolgs Fauces de Madera. Te doy la bienvenida, pero debo advertirte que mi tribu no reacciona bien frente a los extraños.$B$BEstos son tiempos agobiantes, y solo podemos confiar en quienes deciden combatir la corrupción de la tierra junto a nosotros... y que nos hayan demostrado su valía. Los que no lo hagan no encontrarán más que hostilidad si entran al Bastión.', 0),
(@ID, 'esMX', 'Ah... El viento me ha hecho llegar noticias de quienes no pertenecen a nuestra tribu y quieren aliarse con los fúrbolgs Fauces de Madera. Te doy la bienvenida, pero debo advertirte que mi tribu no reacciona bien frente a los extraños.$B$BEstos son tiempos agobiantes, y solo podemos confiar en quienes deciden combatir la corrupción de la tierra junto a nosotros... y que nos hayan demostrado su valía. Los que no lo hagan no encontrarán más que hostilidad si entran al Bastión.', 0);
-- 8466 Plumas para Grazle
-- https://es.classic.wowhead.com/quest=8466
SET @ID := 8466;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los furbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los furbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0);
-- 4084 Corazón de plata
-- https://es.classic.wowhead.com/quest=4084
SET @ID := 4084;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo decirte más cosas para que logres derrotar a Correfuego, pero primero tienes que recolectar los objetos que te pedí.', 0),
(@ID, 'esMX', 'Puedo decirte más cosas para que logres derrotar a Correfuego, pero primero tienes que recolectar los objetos que te pedí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Parece que te tomas muy en serio el ayudar a tu amigo.', 0),
(@ID, 'esMX', 'Muy bien, $n. Parece que te tomas muy en serio el ayudar a tu amigo.', 0);
-- 4421 La corrupción de los Fuego de Jade
-- https://es.classic.wowhead.com/quest=4421
SET @ID := 4421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción aquí lleva a las criaturas a la locura...', 0),
(@ID, 'esMX', 'La corrupción aquí lleva a las criaturas a la locura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Liberar a Frondavil de Xavathras es el primer paso de un largo proceso. Reparar el daño que se ha hecho aquí requerirá mucho trabajo.$B$BPercibo que hay algo más grande actuando aquí... más poderoso que los sátiros. Pero solo el tiempo nos revelará la verdad...', 0),
(@ID, 'esMX', 'Liberar a Frondavil de Xavathras es el primer paso de un largo proceso. Reparar el daño que se ha hecho aquí requerirá mucho trabajo.$B$BPercibo que hay algo más grande actuando aquí... más poderoso que los sátiros. Pero solo el tiempo nos revelará la verdad...', 0);
-- 5156 Investigación acerca de la corrupción
-- https://es.classic.wowhead.com/quest=5156
SET @ID := 5156;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que tu búsqueda salga bien, $n. No he comenzado a dirigirme tan al norte, pero lo admito, la idea de cruzar el camino de un infernal en cualquier momento me asusta un poco. Las criaturas no tienen cerebro, pero siguen siendo bastante intimidantes.', 0),
(@ID, 'esMX', 'Espero que tu búsqueda salga bien, $n. No he comenzado a dirigirme tan al norte, pero lo admito, la idea de cruzar el camino de un infernal en cualquier momento me asusta un poco. Las criaturas no tienen cerebro, pero siguen siendo bastante intimidantes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que sigas con vida, $n. Pero me preocupa que esa agua aún exista. Esperaba encontrar al menos una fuente de agua pura en Frondavil. Pero parece que mi búsqueda ha sido un fracaso. El proceso de curación de la tierra habría sido mucho más sencillo de haber existido tal fuente.$B$BTendré que centrarme en salvar a las criaturas del bosque que aún puedan salvarse mientras destruyo a las que se han corrompido tanto que son un peligro para sí mismas y para los viajeros que atraviesen este bosque que antaño fuera tan poderoso.', 0),
(@ID, 'esMX', 'Me alegra que sigas con vida, $n. Pero me preocupa que esa agua aún exista. Esperaba encontrar al menos una fuente de agua pura en Frondavil. Pero parece que mi búsqueda ha sido un fracaso. El proceso de curación de la tierra habría sido mucho más sencillo de haber existido tal fuente.$B$BTendré que centrarme en salvar a las criaturas del bosque que aún puedan salvarse mientras destruyo a las que se han corrompido tanto que son un peligro para sí mismas y para los viajeros que atraviesen este bosque que antaño fuera tan poderoso.', 0);
-- 5155 Las fuerzas de Jaedenar
-- https://es.classic.wowhead.com/quest=5155
SET @ID := 5155;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu pelea, $n? Sé que el derramamiento de sangre como prueba de honor puede ser repugnante para algunos, pero debes entender que tiene dos objetivos: haces mi tarea más fácil al reducir su número, y nos ganamos un respeto mutuo que solo nos hará más fuertes para los tiempos venideros.$B$BEspero que lo entiendas.', 0),
(@ID, 'esMX', '¿Cómo va tu pelea, $n? Sé que el derramamiento de sangre como prueba de honor puede ser repugnante para algunos, pero debes entender que tiene dos objetivos: haces mi tarea más fácil al reducir su número, y nos ganamos un respeto mutuo que solo nos hará más fuertes para los tiempos venideros.$B$BEspero que lo entiendas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, $n! Ahora que su número se debilita, podemos presionarles más.$B$B¿Qué tal te supo esa primera cata de su poder? ¿Son tan fuertes como pensaste que serían? ¿Más fuertes? ¿O resultaron no ser un desafío a tu altura? Eso sería fantástico.$B$BPero ya discutiremos los detalles de tus hazañas más tarde. Ahora tenemos que concentrarnos en otras cosas.', 0),
(@ID, 'esMX', '¡Bien, $n! Ahora que su número se debilita, podemos presionarles más.$B$B¿Qué tal te supo esa primera cata de su poder? ¿Son tan fuertes como pensaste que serían? ¿Más fuertes? ¿O resultaron no ser un desafío a tu altura? Eso sería fantástico.$B$BPero ya discutiremos los detalles de tus hazañas más tarde. Ahora tenemos que concentrarnos en otras cosas.', 0);
-- Flor del viento corrupta
-- 996, 998, 4115, 4222, 4467
-- https://es.classic.wowhead.com/quest=996
DELETE FROM `quest_request_items_locale` WHERE `id` IN(996, 998, 4115, 4222, 4467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(996, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(998, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4115, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4222, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4467, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(996, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(998, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4115, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4222, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4467, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(996, 998, 4115, 4222, 4467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(996, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(998, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4115, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4222, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4467, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(996, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(998, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4115, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4222, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4467, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0);
-- 8461 Los Muertobosque del Norte
-- https://es.classic.wowhead.com/quest=8461
SET @ID := 8461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que ganes la confianza de los Fauces de madera, estoy seguro de que podremos hacer algo por ti. Los Fauces de madera no olvidan a sus aliados, especialmente en tiempos oscuros como estos.', 0),
(@ID, 'esMX', 'Una vez que ganes la confianza de los Fauces de madera, estoy seguro de que podremos hacer algo por ti. Los Fauces de madera no olvidan a sus aliados, especialmente en tiempos oscuros como estos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Percibo que has logrado una victoria. Victoria, con lo que has hecho... ¡qué de contradicción puede encerrar una palabra! En cualquier caso, has demostrado que mereces nuestra confianza.$B$BPodría pasar un tiempo antes de que los Fauces de Madera te reciban sin hostilidad en el Bastión. Aún así, tu perseverancia acabará con cualquier sospecha que alberguen mis hermanos. Mientras no nos traiciones y no alces tus armas contra nosotros, nos entenderemos bien.', 0),
(@ID, 'esMX', 'Percibo que has logrado una victoria. Victoria, con lo que has hecho... ¡qué de contradicción puede encerrar una palabra! En cualquier caso, has demostrado que mereces nuestra confianza.$B$BPodría pasar un tiempo antes de que los Fauces de Madera te reciban sin hostilidad en el Bastión. Aún así, tu perseverancia acabará con cualquier sospecha que alberguen mis hermanos. Mientras no nos traiciones y no alces tus armas contra nosotros, nos entenderemos bien.', 0);
-- 8467 Plumas para Nafien
-- https://es.classic.wowhead.com/quest=8467
SET @ID := 8467;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los fúrbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los fúrbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0);
-- 8465 Habla con Salfa
-- https://es.classic.wowhead.com/quest=8465
SET @ID := 8465;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Estoy aquí de guardia, pero también como portavoz de los Fauces de Madera en Cuna del Invierno y como defensor de la tribu.$B$BNuestros hermanos Nevada han sido víctimas de la misma corrupción que los fúrbolgs de Frondavil. Si has venido aquí a ofrecer ayuda a los Fauces de Madera, debo decirte que la aceptaremos.', 0),
(@ID, 'esMX', 'Saludos, $c. Estoy aquí de guardia, pero también como portavoz de los Fauces de Madera en Cuna del Invierno y como defensor de la tribu.$B$BNuestros hermanos Nevada han sido víctimas de la misma corrupción que los fúrbolgs de Frondavil. Si has venido aquí a ofrecer ayuda a los Fauces de Madera, debo decirte que la aceptaremos.', 0);
-- 5157 Una muestra de agua corrupta
-- https://es.classic.wowhead.com/quest=5157
SET @ID := 5157;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tengamos el agua de la Poza de la Luna, la purificaremos y la utilizaremos para extinguir los blandones de protección de la Guarida Sombría. Eso debería darme tiempo suficiente para mirar en las cámaras más profundas y discernir quién lidera este... culto.$B$BRezo para que la Madre Tierra esté con nosotros.', 0),
(@ID, 'esMX', 'Cuando tengamos el agua de la Poza de la Luna, la purificaremos y la utilizaremos para extinguir los blandones de protección de la Guarida Sombría. Eso debería darme tiempo suficiente para mirar en las cámaras más profundas y discernir quién lidera este... culto.$B$BRezo para que la Madre Tierra esté con nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta agua nos servirá, $n.$B$BAhora solo nos queda purificarla antes de utilizarla en los blandones. No debería ser difícil, pero requiere un viajecito.$B$BEspero que podamos hacerlo rápido.', 0),
(@ID, 'esMX', 'Esta agua nos servirá, $n.$B$BAhora solo nos queda purificarla antes de utilizarla en los blandones. No debería ser difícil, pero requiere un viajecito.$B$BEspero que podamos hacerlo rápido.', 0);
-- 4005 Aquamentas
-- https://es.classic.wowhead.com/quest=4005
SET @ID := 4005;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has vuelto, ¿eh? Ummm... Déjame echar un vistazo a eso, $n.', 0),
(@ID, 'esMX', 'Así que has vuelto, ¿eh? Ummm... Déjame echar un vistazo a eso, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Correfuego, dices...$B$BSí, ese poderoso elemental vive en el tórrido centro del cráter. Procuramos mantenernos alejados, nadie ha podido atravesar la potente aura que le rodea. Muchos han salido volando montaña abajo al intentar acercarse a él.', 0),
(@ID, 'esMX', 'Correfuego, dices...$B$BSí, ese poderoso elemental vive en el tórrido centro del cráter. Procuramos mantenernos alejados, nadie ha podido atravesar la potente aura que le rodea. Muchos han salido volando montaña abajo al intentar acercarse a él.', 0);
-- 4906 Más corrupción
-- https://es.classic.wowhead.com/quest=4906
SET @ID := 4906;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, pon fin al sufrimiento de las criaturas de Frondavil.', 0),
(@ID, 'esMX', 'Por favor, pon fin al sufrimiento de las criaturas de Frondavil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por todo lo que has hecho, $n. Que Elune te proteja y te guíe en tu camino.', 0),
(@ID, 'esMX', 'Gracias por todo lo que has hecho, $n. Que Elune te proteja y te guíe en tu camino.', 0);
-- Bálsamo por caza
-- 4103, 4108, 5882, 5887
-- https://es.classic.wowhead.com/quest=4103
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4103, 4108, 5882, 5887) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4103, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4108, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5882, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5887, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4103, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4108, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5882, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5887, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4103, 4108, 5882, 5887) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4103, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4108, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5882, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5887, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4103, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4108, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5882, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5887, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0);
-- Bálsamo por desencantamiento
-- 4107, 4112, 5886, 5891
-- https://es.classic.wowhead.com/quest=4107
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4107, 4112, 5886, 5891) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4107, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4112, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5886, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5891, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4107, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4112, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5886, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5891, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4107, 4112, 5886, 5891) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4107, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4112, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5886, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5891, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4107, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4112, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5886, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5891, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0);

-- Bálsamo por desuello
-- 4106, 4111, 5885, 5890
-- https://es.classic.wowhead.com/quest=4111
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4106, 4111, 5885, 5890) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4106, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4111, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5885, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5890, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4106, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4111, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5885, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5890, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4106, 4111, 5885, 5890) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4106, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4111, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5885, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5890, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4106, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4111, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5885, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5890, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0);
-- Bálsamo por minería
-- 4104, 4109, 5883, 5888
-- https://es.classic.wowhead.com/quest=4104
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4104, 4109, 5883, 5888) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4104, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4109, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5883, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5888, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4104, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4109, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5883, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5888, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4104, 4109, 5883, 5888) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4104, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4109, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5883, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5888, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4104, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4109, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5883, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5888, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0);
-- Bálsamo por recolección
-- 4105, 4110, 5884, 5889
-- https://es.classic.wowhead.com/quest=4105
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4105, 4110, 5884, 5889) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4105, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4110, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5884, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5889, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4105, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4110, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5884, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5889, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4105, 4110, 5884, 5889) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4105, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4110, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5884, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5889, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4105, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4110, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5884, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5889, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0);
-- Dragón nocturno corrupto
-- 4119, 4447, 4448, 4462
-- https://es.classic.wowhead.com/quest=4119
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4119, 4447, 4448, 4462) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4119, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4447, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4448, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4462, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4119, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4447, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4448, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4462, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4119, 4447, 4448, 4462) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4119, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4447, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4448, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4462, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4119, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4447, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4448, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4462, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0);
-- 5158 Buscando ayuda espiritual
-- https://es.classic.wowhead.com/quest=5158
SET @ID := 5158;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Percibo que no eres un viajero corriente buscando el camino a Trinquete. Ven, siéntate y descansa en nuestro campamento. Habla conmigo cuando estés listo.', 0),
(@ID, 'esMX', 'Percibo que no eres un viajero corriente buscando el camino a Trinquete. Ven, siéntate y descansa en nuestro campamento. Habla conmigo cuando estés listo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, necesitas limpiar el agua de esta Poza de la Luna. Detener esta fuente de maldad de Frondavil es una noble acción, pero yo no soy quién para decidir si el agua será purificada. Preguntaré a los espíritus del Agua. Ellos son quienes deciden si la causa es justa.$B$BDame un momento, les hablaré de tu ruego. Espero que simpaticen con tu causa como yo.', 0),
(@ID, 'esMX', 'Ah, necesitas limpiar el agua de esta Poza de la Luna. Detener esta fuente de maldad de Frondavil es una noble acción, pero yo no soy quién para decidir si el agua será purificada. Preguntaré a los espíritus del Agua. Ellos son quienes deciden si la causa es justa.$B$BDame un momento, les hablaré de tu ruego. Espero que simpaticen con tu causa como yo.', 0);
-- 4842 Fuentes extrañas
-- https://es.classic.wowhead.com/quest=4842
SET @ID := 4842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El agua de los manantiales parece tener algunas propiedades muy extrañas... Todavía no estoy segura de lo que significa...', 0),
(@ID, 'esMX', 'El agua de los manantiales parece tener algunas propiedades muy extrañas... Todavía no estoy segura de lo que significa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, los demonios de Garganta Negro Rumor... creo que su presencia es la que está afectando así a esta tierra. Voy a seguir observando las fuentes termales para ver si averiguo algo más.$B$BSi tienes planes de seguir adentrándote en la Garganta Negro Rumor te convendría esperar a ser un poco más fuerte.', 0),
(@ID, 'esMX', 'Sí, los demonios de Garganta Negro Rumor... creo que su presencia es la que está afectando así a esta tierra. Voy a seguir observando las fuentes termales para ver si averiguo algo más.$B$BSi tienes planes de seguir adentrándote en la Garganta Negro Rumor te convendría esperar a ser un poco más fuerte.', 0);
-- 8464 Actividad de los Nevada
-- https://es.classic.wowhead.com/quest=8464
SET @ID := 8464;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apreciamos mucho lo que has hecho por los Fauce de Madera, $n. Tus continuos esfuerzos seguramente ganarán la confianza y el respeto de mi tribu.', 0),
(@ID, 'esMX', 'Apreciamos mucho lo que has hecho por los Fauce de Madera, $n. Tus continuos esfuerzos seguramente ganarán la confianza y el respeto de mi tribu.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por todo lo que has hecho, aunque haya sido una misión ciertamente entristecedora. Acepta esto como muestra de gratitud.$B$BTe pediría que siguieras ayudándonos, $n. Tenemos pocos aliados a los que recurrir y sin tu ayuda no podremos afrontar todas las amenazas que se ciernen contra mi tribu.', 0),
(@ID, 'esMX', 'Gracias por todo lo que has hecho, aunque haya sido una misión ciertamente entristecedora. Acepta esto como muestra de gratitud.$B$BTe pediría que siguieras ayudándonos, $n. Tenemos pocos aliados a los que recurrir y sin tu ayuda no podremos afrontar todas las amenazas que se ciernen contra mi tribu.', 0);
-- 8469 Cuentas para Salfa
-- https://es.classic.wowhead.com/quest=8469
SET @ID := 8469;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sabido ganarte mi confianza, $n, pero aún tendrás que ganarte la confianza de mi tribu. Hay algo que puedes hacer para conseguirlo.$B$BSe sabe que los Nevada llevan consigo cuentas de espíritus para protegerse contra los espíritus infectos. Esas cuentas no han cumplido sus propósitos ya que los propios Nevada se han convertido en agentes de corrupción. Tráeme las cuentas de espíritu de los furbolgs Nevada caídos, por cada cinco que me traigas aumentará tu reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Has sabido ganarte mi confianza, $n, pero aún tendrás que ganarte la confianza de mi tribu. Hay algo que puedes hacer para conseguirlo.$B$BSe sabe que los Nevada llevan consigo cuentas de espíritus para protegerse contra los espíritus infectos. Esas cuentas no han cumplido sus propósitos ya que los propios Nevada se han convertido en agentes de corrupción. Tráeme las cuentas de espíritu de los furbolgs Nevada caídos, por cada cinco que me traigas aumentará tu reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos has probado una vez más tu honor! Me aseguraré de que los míos conozcan todas tus hazañas.$B$BRecuerda traerme todas las cuentas de los Nevada que encuentres. Por cada juego que me traigas hablaré de ti a la tribu.', 0),
(@ID, 'esMX', '¡Nos has probado una vez más tu honor! Me aseguraré de que los míos conozcan todas tus hazañas.$B$BRecuerda traerme todas las cuentas de los Nevada que encuentres. Por cada juego que me traigas hablaré de ti a la tribu.', 0);
-- 5159 El agua purificada vuelve a Frondavil
-- https://es.classic.wowhead.com/quest=5159
SET @ID := 5159;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que has vuelto, $n. Bien. ¿Encontraste a Islen en Los Baldíos? ¿O tenemos que encontrar otra manera de lograr nuestros objetivos?', 0),
(@ID, 'esMX', 'Ah, veo que has vuelto, $n. Bien. ¿Encontraste a Islen en Los Baldíos? ¿O tenemos que encontrar otra manera de lograr nuestros objetivos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta agua debería ser suficiente para nuestros propósitos.$B$BMe alegra que Islen pudiera ayudarnos. Su fuerza sobre los espíritus del agua ha sido siempre considerable. Y también es sabia. Raras son las veces que los espíritus no están de acuerdo con ella. El hecho de que ambos hayan bendecido nuestra causa me da esperanza: estamos en el buen camino.', 0),
(@ID, 'esMX', 'Esta agua debería ser suficiente para nuestros propósitos.$B$BMe alegra que Islen pudiera ayudarnos. Su fuerza sobre los espíritus del agua ha sido siempre considerable. Y también es sabia. Raras son las veces que los espíritus no están de acuerdo con ella. El hecho de que ambos hayan bendecido nuestra causa me da esperanza: estamos en el buen camino.', 0);
-- 3961 La aventura de Linken
-- https://es.classic.wowhead.com/quest=3961
SET @ID := 3961;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola de nuevo, $n!', 0),
(@ID, 'esMX', '¡Hola de nuevo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ayudó J.D. en algo?', 0),
(@ID, 'esMX', '¿Te ayudó J.D. en algo?', 0);
-- 3962 Ir solo es peligroso
-- https://es.classic.wowhead.com/quest=3962
SET @ID := 3962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La protección del aura que creó sirviéndose de la Llama Dorada hace a Correfuego prácticamente invencible. Solo tú tienes el poder para eliminarla gracias al Tótem plateado de Aquamentas.', 0),
(@ID, 'esMX', 'La protección del aura que creó sirviéndose de la Llama Dorada hace a Correfuego prácticamente invencible. Solo tú tienes el poder para eliminarla gracias al Tótem plateado de Aquamentas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BLa Llama Dorada volverá por fin a mi hogar, allí la protegerán y nunca volverá a caer en manos del mal.$B$B¡Sin tu ayuda todavía seguiría sin saber quién soy! Como has hecho tanto por mí, me gustaría darte algo muy especial...$B$B¡Elige lo que quieras!', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BLa Llama Dorada volverá por fin a mi hogar, allí la protegerán y nunca volverá a caer en manos del mal.$B$B¡Sin tu ayuda todavía seguiría sin saber quién soy! Como has hecho tanto por mí, me gustaría darte algo muy especial...$B$B¡Elige lo que quieras!', 0);
-- 5165 Sofocar las llamas de protección
-- https://es.classic.wowhead.com/quest=5165
SET @ID := 5165;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los blandones deben apagarse si queremos tener alguna esperanza de estar preparados para una batalla mucho mayor. Entrar en la guarida del dragón sin ningún conocimiento es una tarea tonta. Y esto es mucho peor que un dragón. El Consejo de la Sombra es el único responsable de una gran cantidad de crímenes y atrocidades. Tendremos que trabajar rápido si queremos detenerlos.', 0),
(@ID, 'esMX', 'Los blandones deben apagarse si queremos tener alguna esperanza de estar preparados para una batalla mucho mayor. Entrar en la guarida del dragón sin ningún conocimiento es una tarea tonta. Y esto es mucho peor que un dragón. El Consejo de la Sombra es el único responsable de una gran cantidad de crímenes y atrocidades. Tendremos que trabajar rápido si queremos detenerlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pude verte con mis hechizos en cuanto murieron las llamas del último blandón. Buen trabajo, $n.$B$BConseguí averiguar algunas cosas antes de que los brujos del Consejo de la Sombra reaccionaran. Espero que sea suficiente.$B$BAhora descansa un poco. Te diré lo que he averiguado en un momento.', 0),
(@ID, 'esMX', 'Pude verte con mis hechizos en cuanto murieron las llamas del último blandón. Buen trabajo, $n.$B$BConseguí averiguar algunas cosas antes de que los brujos del Consejo de la Sombra reaccionaran. Espero que sea suficiente.$B$BAhora descansa un poco. Te diré lo que he averiguado en un momento.', 0);
-- 5149 La muñeca de Pamela
-- https://es.classic.wowhead.com/quest=5149
SET @ID := 5149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mi muñeca?', 0),
(@ID, 'esMX', '¿Has encontrado mi muñeca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La has encontrado! ¡Has encontrado a mi muñeca! ¡Gracias!', 0),
(@ID, 'esMX', '¡La has encontrado! ¡Has encontrado a mi muñeca! ¡Gracias!', 0);
-- 5152 Tía Marlene
-- https://es.classic.wowhead.com/quest=5152
SET @ID := 5152;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Pamela? ¿Y cómo está? ¿¿Está viva?? ¡Oh, no! ¡Pobre Pamela! Era tan joven y tan alegre...$B$BNo sabe lo que le ocurrió a su padre, ¿verdad? ¿Mi hermano Joseph?$B$BNo... ella no podía entender lo que le ocurrió a Joseph. Y aunque pudiera, no tengo valor para contárselo...', 0),
(@ID, 'esMX', '¿Has visto a Pamela? ¿Y cómo está? ¿¿Está viva?? ¡Oh, no! ¡Pobre Pamela! Era tan joven y tan alegre...$B$BNo sabe lo que le ocurrió a su padre, ¿verdad? ¿Mi hermano Joseph?$B$BNo... ella no podía entender lo que le ocurrió a Joseph. Y aunque pudiera, no tengo valor para contárselo...', 0);
-- 5241 Tío Carlin
-- https://es.classic.wowhead.com/quest=5241
SET @ID := 5241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Pamela? ¿Está viva?$B$B¿Está muerta? ¡No! ¡Oh, Pamela! ¿Por qué debe sufrir tu espíritu en este mundo? ¿Por qué tú has perecido, mientras la fortuna me mantiene a mí con vida? ¡Ojalá pudiera cambiar mi lugar con el tuyo y vagar por Villa Darrow como un fantasma, cargando con tu soledad!$B$BPero esta noticia no puede cambiar el destino. Gracias, $n. Ahora mi voluntad de cumplir con mi deber, mi deber de vengarme, es más fuerte que nunca.', 0),
(@ID, 'esMX', '¿Has visto a Pamela? ¿Está viva?$B$B¿Está muerta? ¡No! ¡Oh, Pamela! ¿Por qué debe sufrir tu espíritu en este mundo? ¿Por qué tú has perecido, mientras la fortuna me mantiene a mí con vida? ¡Ojalá pudiera cambiar mi lugar con el tuyo y vagar por Villa Darrow como un fantasma, cargando con tu soledad!$B$BPero esta noticia no puede cambiar el destino. Gracias, $n. Ahora mi voluntad de cumplir con mi deber, mi deber de vengarme, es más fuerte que nunca.', 0);
-- 6021 Zaeldarr el Marginado
-- https://es.classic.wowhead.com/quest=6021
SET @ID := 6021;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el escondite, $n? ¿Te has encargado de Zaeldarr?', 0),
(@ID, 'esMX', '¿Encontraste el escondite, $n? ¿Te has encargado de Zaeldarr?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial, lo tienes! ¡Y espero que también le hayas dado una lección a su pandilla!', 0),
(@ID, 'esMX', 'Genial, lo tienes! ¡Y espero que también le hayas dado una lección a su pandilla!', 0);

-- 5281 Espíritus inquietos
-- https://es.classic.wowhead.com/quest=5281
SET @ID := 5281;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin Alen ha encontrado a alguien con el suficiente valor, ¿eh?', 0),
(@ID, 'esMX', 'Por fin Alen ha encontrado a alguien con el suficiente valor, ¿eh?', 0);
-- 5211 Los defensores de Villa Darrow
-- https://es.classic.wowhead.com/quest=5211
SET @ID := 5211;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pobres defensores de Villa Darrow me gritan en sueños, $n. ¡Debes liberarlos!', 0),
(@ID, 'esMX', 'Los pobres defensores de Villa Darrow me gritan en sueños, $n. ¡Debes liberarlos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra oír que encontraste las almas torturadas de mis hermanos y que las liberaste. Mi corazón sufrirá menos sabiendo que al menos algunos de los defensores de Villa Darrow se han liberado de la tiranía de la Plaga.', 0),
(@ID, 'esMX', 'Me alegra oír que encontraste las almas torturadas de mis hermanos y que las liberaste. Mi corazón sufrirá menos sabiendo que al menos algunos de los defensores de Villa Darrow se han liberado de la tiranía de la Plaga.', 0);
-- Piedras de la Plaga del corruptor
-- 5404, 5406, 5508
-- https://es.classic.wowhead.com/quest=5404
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5404, 5406, 5508) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5404, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5406, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5508, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5404, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5406, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5508, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5404, 5406, 5508) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5404, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5406, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5508, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5404, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5406, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5508, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0);
-- Piedras de la Plaga del invasor
-- 5403, 5407, 5509
-- https://es.classic.wowhead.com/quest=5403
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5403, 5407, 5509) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5403, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5407, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5509, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5403, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5407, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5509, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5403, 5407, 5509) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5403, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5407, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5509, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5403, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5407, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5509, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0);
-- Piedras de la Plaga del esbirro
-- 5402, 5408, 5510
-- https://es.classic.wowhead.com/quest=5402
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5402, 5408, 5510) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5402, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5408, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5510, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5402, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5408, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5510, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5402, 5408, 5510) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5402, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5408, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5510, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5402, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5408, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5510, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0);
-- 5251 El archivista
-- https://es.classic.wowhead.com/quest=5251
SET @ID := 5251;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0),
(@ID, 'esMX', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Impresionante, $n! Años y años de trabajo... ¡perdidos! La Cruzada Escarlata se resentirá de esto en las próximas semanas.', 0),
(@ID, 'esMX', '¡Impresionante, $n! Años y años de trabajo... ¡perdidos! La Cruzada Escarlata se resentirá de esto en las próximas semanas.', 0);
-- Armamento superior de batalla: amistoso con El Alba
-- 9221, 9223, 9226, 9227
-- https://es.classic.wowhead.com/quest=9221
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9221, 9223, 9226, 9227) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9221, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9223, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9226, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9227, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9221, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9223, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9226, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9227, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9221, 9223, 9226, 9227) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9221, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9223, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9226, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9227, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9221, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9223, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9226, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9227, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0);
-- Armamento épico de batalla: amistoso con El Alba
-- 9222, 9224, 9225, 9228
-- https://es.classic.wowhead.com/quest=9222
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9222, 9224, 9225, 9228) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9222, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9224, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9225, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9228, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9222, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9224, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9225, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9228, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9222, 9224, 9225, 9228) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9222, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9224, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9225, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9228, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9222, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9224, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9225, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9228, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0);
-- 5212 La carne no miente
-- https://es.classic.wowhead.com/quest=5212
SET @ID := 5212;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A quien me dice que me preocupo demasiado le digo que él no se preocupa lo suficiente.', 0),
(@ID, 'esMX', 'A quien me dice que me preocupo demasiado le digo que él no se preocupa lo suficiente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algo ha cambiado en la estructura química de los agentes activos de la peste. Necesitamos más datos.', 0),
(@ID, 'esMX', 'Algo ha cambiado en la estructura química de los agentes activos de la peste. Necesitamos más datos.', 0);
-- 5529 Crías de dragón apestadas
-- https://es.classic.wowhead.com/quest=5529
SET @ID := 5529;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ve a Scholomance, $n. ¡Elimina a esas crías apertadas antes de que crezcan!', 0),
(@ID, 'esMX', 'Ve a Scholomance, $n. ¡Elimina a esas crías apertadas antes de que crezcan!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Tardarán en poder volver a criar dragones.$B$B¡O al menos, eso espero!', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Tardarán en poder volver a criar dragones.$B$B¡O al menos, eso espero!', 0);
-- 9664 Nuevas avanzadas
-- https://es.classic.wowhead.com/quest=9664
SET @ID := 9664;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando las torres estén bajo nuestro control, podremos rodear a los Renegados. Después de eso, es solo cuestión de tiempo que podamos aplastarlos.', 0),
(@ID, 'esMX', 'Cuando las torres estén bajo nuestro control, podremos rodear a los Renegados. Después de eso, es solo cuestión de tiempo que podamos aplastarlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Será importante para nosotros mantener estas torres contra futuros ataques, y para eso es posible que necesitemos tu ayuda hasta que se puedan traer refuerzos para asegurar el área.', 0),
(@ID, 'esMX', 'Muy bien, $n. Será importante para nosotros mantener estas torres contra futuros ataques, y para eso es posible que necesitemos tu ayuda hasta que se puedan traer refuerzos para asegurar el área.', 0);
-- 9136 Flora salvaje
-- https://es.classic.wowhead.com/quest=9136
SET @ID := 9136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo un conocimiento profundo de la flora de nuestro mundo. ¿Necesitas orientación?', 0),
(@ID, 'esMX', 'Tengo un conocimiento profundo de la flora de nuestro mundo. ¿Necesitas orientación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy muy agradecida, $n.$B$B<Rayne hace una reverencia.>$B$BRecuerda que siempre estoy aceptando frondas.', 0),
(@ID, 'esMX', 'Estoy muy agradecida, $n.$B$B<Rayne hace una reverencia.>$B$BRecuerda que siempre estoy aceptando frondas.', 0);
-- 27 Una lección que aprender
-- https://es.classic.wowhead.com/quest=27
SET @ID := 27;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, joven $c, ha llegado el momento de que conozcas nuestra forma acuática. Se trata de una técnica que te permitirá moverte libre e indefinidamente por el agua. Encontrarás muy útil este aspecto y pronto te darás cuenta de que es una bendición. Pero debes ganártelo antes de dominarlo...$B$BDeberás superar dos pruebas. La primera probará tu capacidad para trabajar en el agua bajo presión. La segunda, tu resolución y tu comprensión de los aspectos de la forma acuática.$B$BPrepárate pues el momento de la prueba se acerca.', 0),
(@ID, 'esMX', 'Saludos, joven $c, ha llegado el momento de que conozcas nuestra forma acuática. Se trata de una técnica que te permitirá moverte libre e indefinidamente por el agua. Encontrarás muy útil este aspecto y pronto te darás cuenta de que es una bendición. Pero debes ganártelo antes de dominarlo...$B$BDeberás superar dos pruebas. La primera probará tu capacidad para trabajar en el agua bajo presión. La segunda, tu resolución y tu comprensión de los aspectos de la forma acuática.$B$BPrepárate pues el momento de la prueba se acerca.', 0);
-- La prueba del lago
-- 28, 29
-- https://es.classic.wowhead.com/quest=28
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(28, 29) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(28, 'esES', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(29, 'esES', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(28, 'esMX', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(29, 'esMX', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0);
-- 30 La prueba del león marino
-- https://es.classic.wowhead.com/quest=30
SET @ID := 30;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0),
(@ID, 'esMX', '¿Traes el colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua, y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0),
(@ID, 'esMX', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua, y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0);
-- 31 Forma acuática
-- https://es.classic.wowhead.com/quest=31
SET @ID := 31;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenía noticia de tu regreso a Cima del Trueno, pero debes demostrarme lo que has aprendido para que te enseñe tu forma acuática.$B$B¿Traes el colgante del león marino?', 0),
(@ID, 'esMX', 'Tenía noticia de tu regreso a Cima del Trueno, pero debes demostrarme lo que has aprendido para que te enseñe tu forma acuática.$B$B¿Traes el colgante del león marino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n; tus antepasados pueden estar orgullosos. Me llena de alegría poder enseñarte tu Forma acuática.$B$BAcepta esto como premio por tus logros en las dos pruebas; espero que te ayude en tu objetivo de proteger la naturaleza y su equilibrio.', 0),
(@ID, 'esMX', 'Impresionante, $n; tus antepasados pueden estar orgullosos. Me llena de alegría poder enseñarte tu Forma acuática.$B$BAcepta esto como premio por tus logros en las dos pruebas; espero que te ayude en tu objetivo de proteger la naturaleza y su equilibrio.', 0);
-- 32 La sublevación de los silítidos
-- https://es.classic.wowhead.com/quest=32
SET @ID := 32;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo siento, no te conozco... pero por lo que parece, tú sí has oído hablar de mí. ¿En qué puedo ayudarte? ¿Tienes algo para mí?', 0),
(@ID, 'esMX', 'Lo siento, no te conozco... pero por lo que parece, tú sí has oído hablar de mí. ¿En qué puedo ayudarte? ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este informe... Yo ya he visto antes a estas criaturas. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0),
(@ID, 'esMX', 'Este informe... Yo ya he visto antes a estas criaturas. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0);

-- 49 Dulce ámbar
-- https://es.classic.wowhead.com/quest=49
SET @ID := 49;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra? ¡Claro!$B$BÁmbar es el color del amor de mi vida$BComo las luces de un final del día$BRecupéralo y el amor volverá a mí$BUn saco de cebada, uno de centeno y otro de maíz.', 0),
(@ID, 'esMX', '¿Otra? ¡Claro!$B$BÁmbar es el color del amor de mi vida$BComo las luces de un final del día$BRecupéralo y el amor volverá a mí$BUn saco de cebada, uno de centeno y otro de maíz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 50 Dulce ámbar
-- https://es.classic.wowhead.com/quest=50
SET @ID := 50;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un bis? ¡Claro que sí!$B$BMezclaré y mezclaré y un puré será todo$BSerá, amigo, nuestro más querido tesoro$BHaré un alambique fuerte y resistente$BDame veraplata y no daré la lata.', 0),
(@ID, 'esMX', '¿Un bis? ¡Claro que sí!$B$BMezclaré y mezclaré y un puré será todo$BSerá, amigo, nuestro más querido tesoro$BHaré un alambique fuerte y resistente$BDame veraplata y no daré la lata.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 51 Dulce ámbar
-- https://es.classic.wowhead.com/quest=51
SET @ID := 51;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Repetimos? ¡Claro, lo que quieras!$B$BRecién destilada, aunque aún no esté filtrada$BComo tierra sin semilla esperando a ser arada$BAhora haré nuestra pila de carbón$BUna rama de sicomoro es tu próxima misión.', 0),
(@ID, 'esMX', '¿Repetimos? ¡Claro, lo que quieras!$B$BRecién destilada, aunque aún no esté filtrada$BComo tierra sin semilla esperando a ser arada$BAhora haré nuestra pila de carbón$BUna rama de sicomoro es tu próxima misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 53 Dulce ámbar
-- https://es.classic.wowhead.com/quest=53
SET @ID := 53;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Claro que te la canto otra vez, amigo!$B$BEs un líquido meloso que se vuelve delicioso$BDulce líquido ambarino que merece mi cariño$BPero algo necesito para darle mis cuidados$BUn magnífico tonel del mejor roble quemado.', 0),
(@ID, 'esMX', '¡Claro que te la canto otra vez, amigo!$B$BEs un líquido meloso que se vuelve delicioso$BDulce líquido ambarino que merece mi cariño$BPero algo necesito para darle mis cuidados$BUn magnífico tonel del mejor roble quemado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Envejecida en el barril y filtrada con carbón$BAcaricia tus labios y va directa al corazón.$BBrindemos por ti y verás que bueno$BAlzad vuestras jarras por Tragoamargo Cebatruenos', 0),
(@ID, 'esMX', 'Envejecida en el barril y filtrada con carbón$BAcaricia tus labios y va directa al corazón.$BBrindemos por ti y verás que bueno$BAlzad vuestras jarras por Tragoamargo Cebatruenos', 0);
-- 63 La llamada del agua
-- https://es.classic.wowhead.com/quest=63
SET @ID := 63;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El blandón aún refleja la luz ambiente del lugar y la llama tiembla levemente cuando te acercas.$B$BLa corrupción de las colinas parece haber mantenido las distancias y, además de los componentes perdidos, el blandón parece estar listo para el ritual de conjura de una forma de agua limpia.', 0),
(@ID, 'esMX', 'El blandón aún refleja la luz ambiente del lugar y la llama tiembla levemente cuando te acercas.$B$BLa corrupción de las colinas parece haber mantenido las distancias y, además de los componentes perdidos, el blandón parece estar listo para el ritual de conjura de una forma de agua limpia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los brazales sobre el blandón y entonces las gotas restantes de la poción de Brine en la llama. Las gotas harán chisporrotear la llama y empiezas el conjuro con las sencillas palabras que Islen te enseñó....', 0),
(@ID, 'esMX', 'Colocas los brazales sobre el blandón y entonces las gotas restantes de la poción de Brine en la llama. Las gotas harán chisporrotear la llama y empiezas el conjuro con las sencillas palabras que Islen te enseñó....', 0);
-- 77 Una situación peliaguda
-- https://es.classic.wowhead.com/quest=77
SET @ID := 77;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vienes a entregar el calimocho, ¿verdad?', 0),
(@ID, 'esMX', 'Vienes a entregar el calimocho, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Veo que has tratado el calimocho con cuidado; no hay nada peor que el calimocho agitado.$B$BBueno, pasemos al mágico proceso del embotellado para conservar este tesoro alcohólico. En realidad el proceso no tiene nada de mágico; lo único que tengo son unos contenedores de calimocho dulce de las Tierras del Interior vacíos. Nuestras triquiñuelas convertirán estas botellas en un tesoro alcohólico con solera.$B$B¡Salud!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Veo que has tratado el calimocho con cuidado; no hay nada peor que el calimocho agitado.$B$BBueno, pasemos al mágico proceso del embotellado para conservar este tesoro alcohólico. En realidad el proceso no tiene nada de mágico; lo único que tengo son unos contenedores de calimocho dulce de las Tierras del Interior vacíos. Nuestras triquiñuelas convertirán estas botellas en un tesoro alcohólico con solera.$B$B¡Salud!', 0);
-- 81 Entrega el calimocho
-- https://es.classic.wowhead.com/quest=81
SET @ID := 81;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no has venido a comprar o a entregar nada, me estás haciendo perder el tiempo. ¡Y eso no me gusta nada! ¡Más te vale traer el calimocho!', 0),
(@ID, 'esMX', 'Si no has venido a comprar o a entregar nada, me estás haciendo perder el tiempo. ¡Y eso no me gusta nada! ¡Más te vale traer el calimocho!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veamos el barril!$B$BSí, está todo. Ten tu pago y buen trabajo. ¡En la taberna me habría cansado mucho más, ja, ja!$B$BGuardaré estas botellas para una ocasión especial. Me gusta tomarlo con champán; lo llamo champimocho.', 0),
(@ID, 'esMX', '¡Veamos el barril!$B$BSí, está todo. Ten tu pago y buen trabajo. ¡En la taberna me habría cansado mucho más, ja, ja!$B$BGuardaré estas botellas para una ocasión especial. Me gusta tomarlo con champán; lo llamo champimocho.', 0);
-- 94 Un ojo vigilante
-- https://es.classic.wowhead.com/quest=94
SET @ID := 94;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta Estatua Leonida ha estado aquí décadas, vigilando la infame Torre de Ilgalar.$B$BHay una hendidura en la base de la estatua en la que parece que podría acoplarse una gema o un glifo...', 0),
(@ID, 'esMX', 'Esta Estatua Leonida ha estado aquí décadas, vigilando la infame Torre de Ilgalar.$B$BHay una hendidura en la base de la estatua en la que parece que podría acoplarse una gema o un glifo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el Glifo de Azora en la piedra. Se adhiere a ella y luego oyes la voz incorpórea de Theocritus:$B$BTienes toda mi gratitud, joven $n. Puedes hablar conmigo a través de este Glifo. Es posible que en un futuro tenga trabajos para ti... cuando haya sondeado los pensamientos de mi rival.', 0),
(@ID, 'esMX', 'Colocas el Glifo de Azora en la piedra. Se adhiere a ella y luego oyes la voz incorpórea de Theocritus:$B$BTienes toda mi gratitud, joven $n. Puedes hablar conmigo a través de este Glifo. Es posible que en un futuro tenga trabajos para ti... cuando haya sondeado los pensamientos de mi rival.', 0);
-- 96 La llamada del agua
-- https://es.classic.wowhead.com/quest=96
SET @ID := 96;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¡Fantástico!$B$B¿Qué tal fue tu viaje a Filargenta? ¿Te llevó mucho tiempo?$B$BMe cuesta discernir si te fue bien porque la corrupción alcanza gran parte de la tierra. Su hedor supera cualquier bien que puedas haber hecho. Pero en ocasiones los pequeños éxitos son tan importantes como los grandes. La purificación del agua fue decisiva para ti y para todos los chamanes.', 0),
(@ID, 'esMX', 'Has vuelto. ¡Fantástico!$B$B¿Qué tal fue tu viaje a Filargenta? ¿Te llevó mucho tiempo?$B$BMe cuesta discernir si te fue bien porque la corrupción alcanza gran parte de la tierra. Su hedor supera cualquier bien que puedas haber hecho. Pero en ocasiones los pequeños éxitos son tan importantes como los grandes. La purificación del agua fue decisiva para ti y para todos los chamanes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es la prueba que pedí. Lo has hecho muy bien, $n.$B$BMe complace ser el primero en felicitarte y te hago entrega de este… de tu tótem de agua.$B$BÚsalo bien y suerte.$B$BPasará cierto tiempo hasta tu próxima prueba, así que aprende bien las lecciones. El agua pura no solo devuelve la vida a los heridos, sino que puede tener muchos más efectos. Te sugiero que busques un instructor chamán cuando tengas tiempo. Podrías aprender más hechizos..', 0),
(@ID, 'esMX', 'Esta es la prueba que pedí. Lo has hecho muy bien, $n.$B$BMe complace ser el primero en felicitarte y te hago entrega de este… de tu tótem de agua.$B$BÚsalo bien y suerte.$B$BPasará cierto tiempo hasta tu próxima prueba, así que aprende bien las lecciones. El agua pura no solo devuelve la vida a los heridos, sino que puede tener muchos más efectos. Te sugiero que busques un instructor chamán cuando tengas tiempo. Podrías aprender más hechizos..', 0);
-- 99 La locura de Arugal
-- https://es.classic.wowhead.com/quest=99
SET @ID := 99;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has asegurado ya los grilletes piroleños, $n?', 0),
(@ID, 'esMX', '¿Has asegurado ya los grilletes piroleños, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu persistencia es encomiable. Con el conocimiento que me has ayudado a reunir, Arugal caerá y su magia temeraria se anulará. Brindo por ti, $n.', 0),
(@ID, 'esMX', 'Tu persistencia es encomiable. Con el conocimiento que me has ayudado a reunir, Arugal caerá y su magia temeraria se anulará. Brindo por ti, $n.', 0);
-- 100 La llamada del agua
-- https://es.classic.wowhead.com/quest=100
SET @ID := 100;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a ti. Gracias a los chamanes.$B$BLa corrupción retrocede pero la vida sigue disminuyendo. La protección de la vida depende de los chamanes', 0),
(@ID, 'esMX', 'Gracias a ti. Gracias a los chamanes.$B$BLa corrupción retrocede pero la vida sigue disminuyendo. La protección de la vida depende de los chamanes', 0);
-- Ah, Andorhal
-- 105, 211
-- https://es.classic.wowhead.com/quest=105
DELETE FROM `quest_request_items_locale` WHERE `id` IN(105, 211) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(105, 'esES', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(211, 'esES', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(105, 'esMX', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(211, 'esMX', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(105, 211) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(105, 'esES', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(211, 'esES', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(105, 'esMX', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(211, 'esMX', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0);
-- 111 Habla con la abuelita
-- https://es.classic.wowhead.com/quest=111
SET @ID := 111;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a ver cómo reaccionan mis amigos!$B$BEllos nunca lo esperarán', 0),
(@ID, 'esMX', '¡No puedo esperar a ver cómo reaccionan mis amigos!$B$BEllos nunca lo esperarán', 0);
-- 136 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=136
SET @ID := 136;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El baúl se abre lentamente. Solo parece estar lleno de agua y arena. ¡Pero espera! ¡Está saliendo un pequeño cangrejo con una pista del tesoro entre las pinzas!', 0),
(@ID, 'esMX', 'El baúl se abre lentamente. Solo parece estar lleno de agua y arena. ¡Pero espera! ¡Está saliendo un pequeño cangrejo con una pista del tesoro entre las pinzas!', 0);
-- 138 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=138
SET @ID := 138;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo cazatesoros!', 0),
(@ID, 'esMX', '¡Buen trabajo cazatesoros!', 0);
-- 139 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=139
SET @ID := 139;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te estás acercando al premio gordo, buscatesoros!', 0),
(@ID, 'esMX', '¡Te estás acercando al premio gordo, buscatesoros!', 0);
-- 140 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=140
SET @ID := 140;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las bisagras del viejo cofre están oxidadas, pero todavía funcionan. Fuerzas el cofre, lo abres y coges el botín.$B$B¡Felicidades!', 0),
(@ID, 'esMX', 'Las bisagras del viejo cofre están oxidadas, pero todavía funcionan. Fuerzas el cofre, lo abres y coges el botín.$B$B¡Felicidades!', 0);
-- 172 Semana de los Niños
-- https://es.classic.wowhead.com/quest=172
SET @ID := 172;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! Me llamo Grunth, ¿me vas a cuidar tú? Me alegro de conocerte. Mis papás también eran aventureros, me han dicho que murieron honrosamente en combate.$B$BEspero que juguemos mucho; la matrona me ha dicho que esta semana serás como mi hermano mayor, qué bien.', 0),
(@ID, 'esMX', '¡Hola! Me llamo Grunth, ¿me vas a cuidar tú? Me alegro de conocerte. Mis papás también eran aventureros, me han dicho que murieron honrosamente en combate.$B$BEspero que juguemos mucho; la matrona me ha dicho que esta semana serás como mi hermano mayor, qué bien.', 0);
-- 178 Theocritus recupera el colgante
-- https://es.classic.wowhead.com/quest=178
SET @ID := 178;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que te hablé mediante un colgante? Mmm, dámelo, quiero estudiarlo.', 0),
(@ID, 'esMX', '¿Que te hablé mediante un colgante? Mmm, dámelo, quiero estudiarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Hace semanas que envié el mensaje, creí que no se había transmitido. Pero parece que el hechizo llegó a algunos colgantes, aunque tarde.$B$BEspero aprender a enviar ataques para inmovilizar a los gnolls que los lleven puestos.$B$BPero me queda mucha investigación por delante para llegar a eso.', 0),
(@ID, 'esMX', 'Gracias, $n. Hace semanas que envié el mensaje, creí que no se había transmitido. Pero parece que el hechizo llegó a algunos colgantes, aunque tarde.$B$BEspero aprender a enviar ataques para inmovilizar a los gnolls que los lleven puestos.$B$BPero me queda mucha investigación por delante para llegar a eso.', 0);
-- 200 Corredor Herod
-- https://es.classic.wowhead.com/quest=200
SET @ID := 200;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son las notas y los registros del Corredor Herod.$B$BEntre los papeles hay: una lista de suministros del campamento, pedidos de material del coronel Kurzen, y varias cartas.', 0),
(@ID, 'esMX', 'Estas son las notas y los registros del Corredor Herod.$B$BEntre los papeles hay: una lista de suministros del campamento, pedidos de material del coronel Kurzen, y varias cartas.', 0);
-- 215 Los secretos de la jungla
-- https://es.classic.wowhead.com/quest=215
SET @ID := 215;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, lo que te contó Thorsen es cierto. Debes tener discreción con este asunto. Hubo un tiempo, cuando los rebeldes éramos absolutamente leales al coronel Kurzen. Pero debido al grado de corrupción de Kurzen, nuestra pasión se convirtió en ira. Si se supiera que el corsario Thorsen ha tenido algo que ver con los hombres de Kurzen, cualquier noche se encontraría con el pescuezo cortado.$B$BPor lo que yo sé, solo la sargento Yohwa, Thorsen y yo conocíamos la existencia de la misión de Thorsen. Pero debe de haber alguien más. Un traidor.', 0),
(@ID, 'esMX', 'Sí, lo que te contó Thorsen es cierto. Debes tener discreción con este asunto. Hubo un tiempo, cuando los rebeldes éramos absolutamente leales al coronel Kurzen. Pero debido al grado de corrupción de Kurzen, nuestra pasión se convirtió en ira. Si se supiera que el corsario Thorsen ha tenido algo que ver con los hombres de Kurzen, cualquier noche se encontraría con el pescuezo cortado.$B$BPor lo que yo sé, solo la sargento Yohwa, Thorsen y yo conocíamos la existencia de la misión de Thorsen. Pero debe de haber alguien más. Un traidor.', 0);
-- 216 Entre una roca y un Piel de Cardo
-- https://es.classic.wowhead.com/quest=216
SET @ID := 216;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has peleado con los Piel de Cardo? Con un camino despejado entre nuestras bases, nuestras posibilidades de reclamar todo Vallefresno aumentan drásticamente.', 0),
(@ID, 'esMX', '¿Has peleado con los Piel de Cardo? Con un camino despejado entre nuestras bases, nuestras posibilidades de reclamar todo Vallefresno aumentan drásticamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c, ¡pero que muy bien! Seguiré mandando tropas para diezmar a los furbolgs, pero al menos cuento con una ruta diferente que estará libre de enredos con la Alianza. ¡La conquista de Vallefresno por la Horda está bien encarrilada!$B$BTe has ganado el jornal, $ghéroe:heroína;. ¡Te saludo!', 0),
(@ID, 'esMX', 'Muy bien, $c, ¡pero que muy bien! Seguiré mandando tropas para diezmar a los furbolgs, pero al menos cuento con una ruta diferente que estará libre de enredos con la Alianza. ¡La conquista de Vallefresno por la Horda está bien encarrilada!$B$BTe has ganado el jornal, $ghéroe:heroína;. ¡Te saludo!', 0);

-- 219 Desaparecido en combate
-- https://es.classic.wowhead.com/quest=219
SET @ID := 219;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has prestado un gran servicio al Reino, $c. Gracias por ayudar al cabo Keeshan a huir de los Roca Negra. Recibirás una recompensa por tus heroicas acciones.', 0),
(@ID, 'esMX', 'Has prestado un gran servicio al Reino, $c. Gracias por ayudar al cabo Keeshan a huir de los Roca Negra. Recibirás una recompensa por tus heroicas acciones.', 0);
-- 220 La llamada del agua
-- https://es.classic.wowhead.com/quest=220
SET @ID := 220;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Tienes buen aspecto.$B$B¿Qué te trae por aquí tan pronto?', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Tienes buen aspecto.$B$B¿Qué te trae por aquí tan pronto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un vial de agua creado y bendecido por Brine y reunido por ti, nada menos.$B$BEl líquido de este vial será vital en la creación de sapta para ti pero también se usará en otra tarea.$B$BLa sapta que cree para ti también servirá para ver los espíritus del agua del altar que se encuentra en el Bosque de Argénteos, al sur de Entrañas. En cuanto a las gotas restantes, pues, te lo contaré si crees que estás $gpreparado:preparada;.$B$B¿Estás $gpreparado:preparada; para otro viaje, $n?', 0),
(@ID, 'esMX', 'Ah, un vial de agua creado y bendecido por Brine y reunido por ti, nada menos.$B$BEl líquido de este vial será vital en la creación de sapta para ti pero también se usará en otra tarea.$B$BLa sapta que cree para ti también servirá para ver los espíritus del agua del altar que se encuentra en el Bosque de Argénteos, al sur de Entrañas. En cuanto a las gotas restantes, pues, te lo contaré si crees que estás $gpreparado:preparada;.$B$B¿Estás $gpreparado:preparada; para otro viaje, $n?', 0);
-- 225 La lápida desgastada
-- https://es.classic.wowhead.com/quest=225
SET @ID := 225;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Morgan Ladimor?$B$BAh, sí, claro. La suya es una historia larga y llena de desgracias. Yo lo conocía bien, bueno, antes de que se fuera a al guerra, pero esa fue la última vez que lo vi. Era un buen hombre, un hombre noble, pero tuvo un trágico final.$B$BTen, tengo algo aquí que podría contarte su historia mejor que yo.', 0),
(@ID, 'esMX', '¿Morgan Ladimor?$B$BAh, sí, claro. La suya es una historia larga y llena de desgracias. Yo lo conocía bien, bueno, antes de que se fuera a al guerra, pero esa fue la última vez que lo vi. Era un buen hombre, un hombre noble, pero tuvo un trágico final.$B$BTen, tengo algo aquí que podría contarte su historia mejor que yo.', 0);
-- 227 Morgan Ladimor
-- https://es.classic.wowhead.com/quest=227
SET @ID := 227;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Morgan Ladimor? No sé quién es...$B$BAh, espera, ¡te refieres a Mor\'Ladim! Supongo que no has oído la historia.$B$BPues te contaré la versión resumida. Un no-muerto que se llama a sí mismo Mor\'Ladim ha estado deambulando por el Bosque del Ocaso. Por lo que sé, parece ser el cuerpo no-muerto de Morgan Ladimor, que es la persona que buscas. Nos ha causado todo tipo de problemas, ha estado atacando a los vigilantes que patrullaban la zona y ha matado a gente.$B$B<Te mira de arriba a abajo.>$B$BParece que tú podrías proporcionarle descanso.', 0),
(@ID, 'esMX', '¿Morgan Ladimor? No sé quién es...$B$BAh, espera, ¡te refieres a Mor\'Ladim! Supongo que no has oído la historia.$B$BPues te contaré la versión resumida. Un no-muerto que se llama a sí mismo Mor\'Ladim ha estado deambulando por el Bosque del Ocaso. Por lo que sé, parece ser el cuerpo no-muerto de Morgan Ladimor, que es la persona que buscas. Nos ha causado todo tipo de problemas, ha estado atacando a los vigilantes que patrullaban la zona y ha matado a gente.$B$B<Te mira de arriba a abajo.>$B$BParece que tú podrías proporcionarle descanso.', 0);
-- 228 Mor'Ladim
-- https://es.classic.wowhead.com/quest=228
SET @ID := 228;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me extraña que te esté dando problemas, $n. Algunos de nuestros guardias más fuertes han perdido la vida a manos de Mor\'Ladim.', 0),
(@ID, 'esMX', 'No me extraña que te esté dando problemas, $n. Algunos de nuestros guardias más fuertes han perdido la vida a manos de Mor\'Ladim.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo mataste? ¡Es toda una hazaña, $n! Te doy las gracias de parte de las gentes de Villa Oscura y de parte de La Guardia Nocturna.$B$BAh... pero hay una cosilla...', 0),
(@ID, 'esMX', '¿Lo mataste? ¡Es toda una hazaña, $n! Te doy las gracias de parte de las gentes de Villa Oscura y de parte de La Guardia Nocturna.$B$BAh... pero hay una cosilla...', 0);
-- 229 La hija superviviente
-- https://es.classic.wowhead.com/quest=229
SET @ID := 229;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Mi padre...$B$B<Baja la mirada, abatida..>$B$BOjalá hubiera podido hacer algo por él... Si hubiera hablado con él antes de...', 0),
(@ID, 'esMX', '¿Sí? Mi padre...$B$B<Baja la mirada, abatida..>$B$BOjalá hubiera podido hacer algo por él... Si hubiera hablado con él antes de...', 0);
-- 231 El amor de una hija
-- https://es.classic.wowhead.com/quest=231
SET @ID := 231;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame...', 0),
(@ID, 'esMX', 'Déjame...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El viento trae una voz fantasmal...>$B$B¿Esto es...? ¿Sarah? ¿Es posible que siga con vida? Qué peso me has quitado de encima...$B$B$n. Toma mi espada, Archeus. Mi alma descansará. Ya no volveré a necesitarla. Fue forjada para hacer el bien y, aunque yo he demostrado no ser merecedor de portarla, quizás tú consigas acercarla a la Luz.$B$BLys, mi amor...', 0),
(@ID, 'esMX', '<El viento trae una voz fantasmal...>$B$B¿Esto es...? ¿Sarah? ¿Es posible que siga con vida? Qué peso me has quitado de encima...$B$B$n. Toma mi espada, Archeus. Mi alma descansará. Ya no volveré a necesitarla. Fue forjada para hacer el bien y, aunque yo he demostrado no ser merecedor de portarla, quizás tú consigas acercarla a la Luz.$B$BLys, mi amor...', 0);
-- 232 Un recado para la boticaria Zinge
-- https://es.classic.wowhead.com/quest=232
SET @ID := 232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿en qué puedo ayudarte? ¿Tienes algo que tratar con la Sociedad Real de Boticarios o has venido simplemente a alegrarme el día?', 0),
(@ID, 'esMX', 'Dime, ¿en qué puedo ayudarte? ¿Tienes algo que tratar con la Sociedad Real de Boticarios o has venido simplemente a alegrarme el día?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque Zinge necesita un equipo? Me entristece que Zinge no me honre con su dulce presencia.$B$BBueno, te procuraremos un equipo.', 0),
(@ID, 'esMX', '¿Conque Zinge necesita un equipo? Me entristece que Zinge no me honre con su dulce presencia.$B$BBueno, te procuraremos un equipo.', 0);
-- 235 La Caza de Vallefresno
-- https://es.classic.wowhead.com/quest=235
SET @ID := 235;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, sobre todo para alguien como tú. Echa un vistazo y ve a La Ensenada de Zoram; allí hay otra avanzada de la Horda.$B$BTu presencia me dice que has venido a aprender sobre la caza. Escucha con atención y yo compartiré mis secretos contigo.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, sobre todo para alguien como tú. Echa un vistazo y ve a La Ensenada de Zoram; allí hay otra avanzada de la Horda.$B$BTu presencia me dice que has venido a aprender sobre la caza. Escucha con atención y yo compartiré mis secretos contigo.', 0);
-- 236 Combustible para los demoledores
-- https://es.classic.wowhead.com/quest=236
SET @ID := 236;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bien? ¿Conseguiste encontrar las ascuas? ¿o la Horda te adelantó y te dejó llorando?', 0),
(@ID, 'esMX', '¿Bien? ¿Conseguiste encontrar las ascuas? ¿o la Horda te adelantó y te dejó llorando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Esto ayudará a alimentar las llamas de la guerra en los próximos días.', 0),
(@ID, 'esMX', '¡Excelente! Esto ayudará a alimentar las llamas de la guerra en los próximos días.', 0);
-- 238 Un recado para la boticaria Zinge
-- https://es.classic.wowhead.com/quest=238
SET @ID := 238;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, al igual que tú creo que Luca es desconcertante. No importa, dame el equipo de prueba de campo. Tengo que hacerle algunos ajustes para poder recoger los materiales adecuados.$B$BTienes el equipo, ¿verdad?', 0),
(@ID, 'esMX', 'Sí, al igual que tú creo que Luca es desconcertante. No importa, dame el equipo de prueba de campo. Tengo que hacerle algunos ajustes para poder recoger los materiales adecuados.$B$BTienes el equipo, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que no me hagas perder el tiempo.$B$BCuando haya realizado los ajustes, podrás utilizar este equipo para recoger la información que precises.$B$BEspera un momento a que acabe y, entre tanto, ¿por qué no vas pensando en qué te gustaría llevar contigo al desierto?$B$BSí, sí, he dicho al desierto.', 0),
(@ID, 'esMX', 'Me alegra que no me hagas perder el tiempo.$B$BCuando haya realizado los ajustes, podrás utilizar este equipo para recoger la información que precises.$B$BEspera un momento a que acabe y, entre tanto, ¿por qué no vas pensando en qué te gustaría llevar contigo al desierto?$B$BSí, sí, he dicho al desierto.', 0);
-- 243 In situ
-- https://es.classic.wowhead.com/quest=243
SET @ID := 243;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, nuestras fuentes de alimentación, modelo 4711-FTZ! Solemos utilizarlas para el funcionamiento de los pozos de agua, pero GRACIAS A LOS VILES NÓMADAS, tenemos exceso de existencias ahora mismo.$B$BAsí que, seguro que puedo conseguirte una fuente de alimentación para el nefario experimento científico que tratas de ocultarme, sea el que sea. Aunque no será gratis, $r. Nada es gratis en Gadgetzan.', 0),
(@ID, 'esMX', '¡Ah, nuestras fuentes de alimentación, modelo 4711-FTZ! Solemos utilizarlas para el funcionamiento de los pozos de agua, pero GRACIAS A LOS VILES NÓMADAS, tenemos exceso de existencias ahora mismo.$B$BAsí que, seguro que puedo conseguirte una fuente de alimentación para el nefario experimento científico que tratas de ocultarme, sea el que sea. Aunque no será gratis, $r. Nada es gratis en Gadgetzan.', 0);
-- 247 El fin de la Caza
-- https://es.classic.wowhead.com/quest=247
SET @ID := 247;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has dado muerte a las tres bestias que comprenden la caza de Vallefresno. Me has traído prueba suficiente de su derrota; no cabe la menor duda acerca de tu fuerza y tenacidad. Por tus venas corre la sangre de $gun cazador:una cazadora; ¡y mereces los más elevados elogios!$B$BTe ruego aceptes este adorno como muestra de reconocimiento a tus descomunales esfuerzos realizados en Vallefresno para la Horda hoy. ¡Que tus ancestros estén contigo!', 0),
(@ID, 'esMX', '$n, has dado muerte a las tres bestias que comprenden la caza de Vallefresno. Me has traído prueba suficiente de su derrota; no cabe la menor duda acerca de tu fuerza y tenacidad. Por tus venas corre la sangre de $gun cazador:una cazadora; ¡y mereces los más elevados elogios!$B$BTe ruego aceptes este adorno como muestra de reconocimiento a tus descomunales esfuerzos realizados en Vallefresno para la Horda hoy. ¡Que tus ancestros estén contigo!', 0);
-- 248 Ver más allá
-- https://es.classic.wowhead.com/quest=248
SET @ID := 248;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este tarro contenía un licor pestilente, pero ahora está vacío, tirado entre dos barriles.', 0),
(@ID, 'esMX', 'Este tarro contenía un licor pestilente, pero ahora está vacío, tirado entre dos barriles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una vasija adecuada para el Glifo de Azora, que permite a Theocritus explorar las mentes que hay en el Fuerte de Petravista.', 0),
(@ID, 'esMX', 'Es una vasija adecuada para el Glifo de Azora, que permite a Theocritus explorar las mentes que hay en el Fuerte de Petravista.', 0);
-- 249 Morganth
-- https://es.classic.wowhead.com/quest=249
SET @ID := 249;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, tienes que evitar que Morganth extienda su poder!', 0),
(@ID, 'esMX', '¡$n, tienes que evitar que Morganth extienda su poder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Al derrotar a Morganth, has librado a Ventormenta de un grave peligro.$B$BAcepta esta recompensa. Te diría que fueras en paz, pero estos no son tiempos de paz.$B$BEn lugar de eso, te deseo suerte en tus pruebas y victoria en combates futuros.', 0),
(@ID, 'esMX', 'Muy bien, $n. Al derrotar a Morganth, has librado a Ventormenta de un grave peligro.$B$BAcepta esta recompensa. Te diría que fueras en paz, pero estos no son tiempos de paz.$B$BEn lugar de eso, te deseo suerte en tus pruebas y victoria en combates futuros.', 0);
-- 264 Hasta que la muerte nos separe
-- https://es.classic.wowhead.com/quest=264
SET @ID := 264;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La piedra está fría y su estado demuestra que se han ensañado con ella. La zona está llena de basura, el féretro presenta golpes y grietas y las malas hierbas empiezan a crecer a su alrededor.$B$BA nadie le importa quién está enterrado aquí, sobre todo a ninguna de las víctimas de la peste.', 0),
(@ID, 'esMX', 'La piedra está fría y su estado demuestra que se han ensañado con ella. La zona está llena de basura, el féretro presenta golpes y grietas y las malas hierbas empiezan a crecer a su alrededor.$B$BA nadie le importa quién está enterrado aquí, sobre todo a ninguna de las víctimas de la peste.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el colgante sobre la tumba y observas que la gema parece perder su brillo.$B$BCuando te incorporas para marcharte, miras de nuevo el collar, que yace inánime en las manos de la escultura que preside el féretro. Una ráfaga de viento frío recorre El Sepulcro, interrumpiendo así tus pensamientos. Por un momento, el silencio reina a tu alrededor.', 0),
(@ID, 'esMX', 'Colocas el colgante sobre la tumba y observas que la gema parece perder su brillo.$B$BCuando te incorporas para marcharte, miras de nuevo el collar, que yace inánime en las manos de la escultura que preside el féretro. Una ráfaga de viento frío recorre El Sepulcro, interrumpiendo así tus pensamientos. Por un momento, el silencio reina a tu alrededor.', 0);
-- 272 La prueba del león marino
-- https://es.classic.wowhead.com/quest=272
SET @ID := 272;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes tu colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0),
(@ID, 'esMX', '¿Traes tu colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua. y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0),
(@ID, 'esMX', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua. y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0);
-- 312 La reserva robada de Tundra MacGrann
-- https://es.classic.wowhead.com/quest=312
SET @ID := 312;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste entrar en mi almacén de carne, $n?', 0),
(@ID, 'esMX', '¿Conseguiste entrar en mi almacén de carne, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué amabilidad la tuya, $n! ¡Y qué valor! Gracias a ti no me moriré de hambre cuando llegue la estación fría.', 0),
(@ID, 'esMX', '¡Qué amabilidad la tuya, $n! ¡Y qué valor! Gracias a ti no me moriré de hambre cuando llegue la estación fría.', 0);
-- 328 La llave oculta
-- https://es.classic.wowhead.com/quest=328
SET @ID := 328;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja fuerte es de bronce. Muy sólida y pesada.', 0),
(@ID, 'esMX', 'La caja fuerte es de bronce. Muy sólida y pesada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Queda claro que, la caja fuerte, es donde Herod guarda sus monedas y objetos más valiosos.', 0),
(@ID, 'esMX', 'Queda claro que, la caja fuerte, es donde Herod guarda sus monedas y objetos más valiosos.', 0);
-- 329 ¡Espía descubierto!
-- https://es.classic.wowhead.com/quest=329
SET @ID := 329;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto quién sabía el secreto de Thorsen? ¿Hay un traidor entre nosotros?', 0),
(@ID, 'esMX', '¿Has descubierto quién sabía el secreto de Thorsen? ¿Hay un traidor entre nosotros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esta nota es la pista que necesitábamos para dar con el traidor.', 0),
(@ID, 'esMX', 'Gracias, $n. Esta nota es la pista que necesitábamos para dar con el traidor.', 0);
-- 330 Horarios de patrulla
-- https://es.classic.wowhead.com/quest=330
SET @ID := 330;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, claro que puedo comprobar eso. Veamos... la semana pasada era...$B$B...por qué..., el soldado Merle estaba de guardia con Thorsen. Tenían la misma hora de patrulla durante toda la semana pasada.', 0),
(@ID, 'esMX', 'Ah, sí, claro que puedo comprobar eso. Veamos... la semana pasada era...$B$B...por qué..., el soldado Merle estaba de guardia con Thorsen. Tenían la misma hora de patrulla durante toda la semana pasada.', 0);
-- 331 Informa a Doren
-- https://es.classic.wowhead.com/quest=331
SET @ID := 331;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me duele descubrir que fue Merle quien nos traicionó. Siempre ha sido un buen soldado y yo creí en su lealtad. Pero me alivia haberle descubierto... con un espía como él entre nosotros... no habríamos durado mucho contra el coronel Kurzen.', 0),
(@ID, 'esMX', 'Me duele descubrir que fue Merle quien nos traicionó. Siempre ha sido un buen soldado y yo creí en su lealtad. Pero me alivia haberle descubierto... con un espía como él entre nosotros... no habríamos durado mucho contra el coronel Kurzen.', 0);
-- 335 Una noble cerveza
-- https://es.classic.wowhead.com/quest=335
SET @ID := 335;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto, Wishock conseguirá suficientes refuerzos y suministros como para causarnos muchos problemas. ¿Has conseguido obtener la lágrima de Tilloa o la zibética ya?', 0),
(@ID, 'esMX', 'Pronto, Wishock conseguirá suficientes refuerzos y suministros como para causarnos muchos problemas. ¿Has conseguido obtener la lágrima de Tilloa o la zibética ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! ¡Por fin tengo lo que necesitaba!', 0),
(@ID, 'esMX', '¡Soberbio! ¡Por fin tengo lo que necesitaba!', 0);

-- 336 Una noble cerveza
-- https://es.classic.wowhead.com/quest=336
SET @ID := 336;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estoy con mucho lío? ¡Escucha mis palabras! ¡Soy muy importante para el futuro de este reino!$B$BOh... ¿Qué tienes ahí? Porque parece una bebida refrescante...', 0),
(@ID, 'esMX', '¿No ves que estoy con mucho lío? ¡Escucha mis palabras! ¡Soy muy importante para el futuro de este reino!$B$BOh... ¿Qué tienes ahí? Porque parece una bebida refrescante...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, gracias por traerme esta estupenda cerveza negra, sirviente. Aquí tienes una moneda de cobre. Y ahora, ¡lárgate y déjame disfrutar mi bebida!', 0),
(@ID, 'esMX', 'Ah, gracias por traerme esta estupenda cerveza negra, sirviente. Aquí tienes una moneda de cobre. Y ahora, ¡lárgate y déjame disfrutar mi bebida!', 0);
-- 337 Un libro viejo de Historia
-- https://es.classic.wowhead.com/quest=337
SET @ID := 337;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ooh! ¿Qué es ese libro viejo que tienes ahí? ¿Puedo verlo?', 0),
(@ID, 'esMX', '¡Ooh! ¿Qué es ese libro viejo que tienes ahí? ¿Puedo verlo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay, ay! Este libro no descansa en estos estantes desde antes de la reconstrucción de Ventormenta. Habrá que restaurarlo, claro, está en un estado lamentable, pero me honraría colocarlo entre los otros libros raros de nuestra colección.$B$BGracias, $gseñor:señora;. ¡Acepta esto como pago por la devolución del libro!', 0),
(@ID, 'esMX', '¡Ay, ay! Este libro no descansa en estos estantes desde antes de la reconstrucción de Ventormenta. Habrá que restaurarlo, claro, está en un estado lamentable, pero me honraría colocarlo entre los otros libros raros de nuestra colección.$B$BGracias, $gseñor:señora;. ¡Acepta esto como pago por la devolución del libro!', 0);
-- 350 Mira por un viejo amigo
-- https://es.classic.wowhead.com/quest=350
SET @ID := 350;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo dices en serio? ¿Shaw quiere mi ayuda otra vez? Menuda desfachatez...$B$B¿La Hermandad Defias, dices? Bueno, ciertamente traes muy buenas noticias, ¿eh? Lo próximo que me vas a decir es que Alamuerte sigue con vida y está atacando la ciudad.$B$BMuy bien, cuéntamelo todo, desde el principio. Y no te dejes nada que creas que no es importante. Necesito saberlo todo.', 0),
(@ID, 'esMX', '¿Lo dices en serio? ¿Shaw quiere mi ayuda otra vez? Menuda desfachatez...$B$B¿La Hermandad Defias, dices? Bueno, ciertamente traes muy buenas noticias, ¿eh? Lo próximo que me vas a decir es que Alamuerte sigue con vida y está atacando la ciudad.$B$BMuy bien, cuéntamelo todo, desde el principio. Y no te dejes nada que creas que no es importante. Necesito saberlo todo.', 0);
-- 351 ¡Encontrar a OOX-17/TN!
-- https://es.classic.wowhead.com/quest=351
SET @ID := 351;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0),
(@ID, 'esMX', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el localizador de emergencia con forma de... huevo en el interior del... pollo robótico.$B$BMientras el robot lucha por ponerse en pie, se escuchan una serie de zumbidos provenientes de su interior. Cuando el robot cobra vida, se escucha una vez más la voz de Oglethorpe, en esta ocasión desde el interior del robot:$B$B"OOX-17/TN funciona otra vez pero necesita ciertas reparaciones. Es demasiado pesado para que puedas traerlo... pero se me ocurre una idea. ¿Te apetece seguir cuidando de él?"', 0),
(@ID, 'esMX', 'Colocas el localizador de emergencia con forma de... huevo en el interior del... pollo robótico.$B$BMientras el robot lucha por ponerse en pie, se escuchan una serie de zumbidos provenientes de su interior. Cuando el robot cobra vida, se escucha una vez más la voz de Oglethorpe, en esta ocasión desde el interior del robot:$B$B"OOX-17/TN funciona otra vez pero necesita ciertas reparaciones. Es demasiado pesado para que puedas traerlo... pero se me ocurre una idea. ¿Te apetece seguir cuidando de él?"', 0);
-- 354 Muertes en la familia
-- https://es.classic.wowhead.com/quest=354
SET @ID := 354;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los restos de la familia Agamand? ¿Has acabado al fin con esas malditas bestias?', 0),
(@ID, 'esMX', '¿Tienes los restos de la familia Agamand? ¿Has acabado al fin con esas malditas bestias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La venganza es dulce, ¿no crees? Cuando acabaste con los Agamand, ¿eran conscientes de lo que estaba pasando? Eso espero. Espero que sintieran miedo antes de pasar a mejor vida.$B$BYa sé que es un deseo absurdo pero no puedo evitar pensar en ello.', 0),
(@ID, 'esMX', 'La venganza es dulce, ¿no crees? Cuando acabaste con los Agamand, ¿eran conscientes de lo que estaba pasando? Eso espero. Espero que sintieran miedo antes de pasar a mejor vida.$B$BYa sé que es un deseo absurdo pero no puedo evitar pensar en ello.', 0);
-- 355 Habla con Sevren
-- https://es.classic.wowhead.com/quest=355
SET @ID := 355;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coleman habla maravillas de ti, $n, sobre todo de tu exitosa incursión en los Molinos de Agamand.$B$BLos Renegados necesitan tu ayuda una vez más...', 0),
(@ID, 'esMX', 'Coleman habla maravillas de ti, $n, sobre todo de tu exitosa incursión en los Molinos de Agamand.$B$BLos Renegados necesitan tu ayuda una vez más...', 0);
-- 356 Patrulla de la retaguardia
-- https://es.classic.wowhead.com/quest=356
SET @ID := 356;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes un informe de tu patrulla?', 0),
(@ID, 'esMX', '¿Tienes un informe de tu patrulla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Con tus esfuerzos ayudas a mantener a raya a la Plaga. Enviaré una mención honorífica a mi superior, el ejecutor Zygand.', 0),
(@ID, 'esMX', 'Muy bien. Con tus esfuerzos ayudas a mantener a raya a la Plaga. Enviaré una mención honorífica a mi superior, el ejecutor Zygand.', 0);
-- 357 La identidad del exánime
-- https://es.classic.wowhead.com/quest=357
SET @ID := 357;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has conseguido el libro?', 0),
(@ID, 'esMX', '$n, ¿has conseguido el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Con este libro podré descubrir la identidad de ese exánime. Has servido con diligencia a la Reina.$B$B<Bethor abre el libro y mira fijamente sus brillantes páginas>$B$B¡No puedo creerlo! ¡El libro pertenece nada más y nada menos que a Gunther Arcanos!$B$BEn vida, Gunther era un gran Necromántico. Ambos éramos compañeros de armas antes de la llegada de la Peste. A juzgar por lo que veo aquí, parece que tras su muerte se hizo todavía más poderoso.$B$B¿Sabes? Sus facultades nos vendrían muy bien.', 0),
(@ID, 'esMX', 'Muy bien, $n. Con este libro podré descubrir la identidad de ese exánime. Has servido con diligencia a la Reina.$B$B<Bethor abre el libro y mira fijamente sus brillantes páginas>$B$B¡No puedo creerlo! ¡El libro pertenece nada más y nada menos que a Gunther Arcanos!$B$BEn vida, Gunther era un gran Necromántico. Ambos éramos compañeros de armas antes de la llegada de la Peste. A juzgar por lo que veo aquí, parece que tras su muerte se hizo todavía más poderoso.$B$B¿Sabes? Sus facultades nos vendrían muy bien.', 0);
-- 358 Profanadores
-- https://es.classic.wowhead.com/quest=358
SET @ID := 358;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has finalizado tu tarea? ¿Has destruido a esa especie de perros y obtenido su icor?', 0),
(@ID, 'esMX', '¿Has finalizado tu tarea? ¿Has destruido a esa especie de perros y obtenido su icor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien hecho, $n. La Plaga se equivoca si cree que podrá usar esos cuerpos en nuestra contra. Nuestros boticarios estudiarán el fluido que has recogido de los esclavos Putrepellejo pues es posible que albergue secretos que podamos utilizar contra ellos.$B$BComo ya he dicho, lo has hecho muy bien pero nuestra lucha continúa y con seguridad podrás seguir demostrando tu valía a los Renegados.', 0),
(@ID, 'esMX', 'Muy bien hecho, $n. La Plaga se equivoca si cree que podrá usar esos cuerpos en nuestra contra. Nuestros boticarios estudiarán el fluido que has recogido de los esclavos Putrepellejo pues es posible que albergue secretos que podamos utilizar contra ellos.$B$BComo ya he dicho, lo has hecho muy bien pero nuestra lucha continúa y con seguridad podrás seguir demostrando tu valía a los Renegados.', 0);
-- 359 Las obligaciones de los Renegados
-- https://es.classic.wowhead.com/quest=359
SET @ID := 359;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conque el magistrado Sevren quiere un informe, ¿eh? Muy bien: los defensores de El Baluarte están conteniendo a la mayor parte de los miembros de la Plaga aunque alguno siempre se las arregla para colarse.$B$BHemos detectado cierta actividad esporádica de la Plaga al este de aquí, especialmente importante en Hacienda Balnir.', 0),
(@ID, 'esMX', 'Conque el magistrado Sevren quiere un informe, ¿eh? Muy bien: los defensores de El Baluarte están conteniendo a la mayor parte de los miembros de la Plaga aunque alguno siempre se las arregla para colarse.$B$BHemos detectado cierta actividad esporádica de la Plaga al este de aquí, especialmente importante en Hacienda Balnir.', 0);
-- 360 Regresa junto al magistrado
-- https://es.classic.wowhead.com/quest=360
SET @ID := 360;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es preocupante saber que la Plaga consigue superar la seguridad de El Baluarte. El rey Exánime y sus esbirros no cesan en sus ataques.$B$BPero no nos rendiremos. ¡Nunca volverá a cogernos!', 0),
(@ID, 'esMX', 'Es preocupante saber que la Plaga consigue superar la seguridad de El Baluarte. El rey Exánime y sus esbirros no cesan en sus ataques.$B$BPero no nos rendiremos. ¡Nunca volverá a cogernos!', 0);
-- 361 Una carta sin entregar
-- https://es.classic.wowhead.com/quest=361
SET @ID := 361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh... mi pobre Thurman! Le supliqué que abandonara Molinos de Agamand conmigo y mi padre pero su lealtad a la familia era demasiado fuerte. ¡Lo sabía! ¡Sabía que Brand quería hacerle daño! ¡Maldita sea la Peste y maldita sea la Plaga!$B$B<Yvette se calma y se pone seria.>$B$BPero lamentarse es de débiles. Como Renegada tengo nuevas metas y el amor no está entre ellas. En otro tiempo, te hubiera dado las gracias por haberme entregado esta carta y brindarme la oportunidad de saber qué había sido de mi antiguo amor.$B$BPero esa vida se acabó para siempre.', 0),
(@ID, 'esMX', '¡Oh... mi pobre Thurman! Le supliqué que abandonara Molinos de Agamand conmigo y mi padre pero su lealtad a la familia era demasiado fuerte. ¡Lo sabía! ¡Sabía que Brand quería hacerle daño! ¡Maldita sea la Peste y maldita sea la Plaga!$B$B<Yvette se calma y se pone seria.>$B$BPero lamentarse es de débiles. Como Renegada tengo nuevas metas y el amor no está entre ellas. En otro tiempo, te hubiera dado las gracias por haberme entregado esta carta y brindarme la oportunidad de saber qué había sido de mi antiguo amor.$B$BPero esa vida se acabó para siempre.', 0);
-- 362 Los molinos fantasma
-- https://es.classic.wowhead.com/quest=362
SET @ID := 362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Devlin?', 0),
(@ID, 'esMX', '¿Has encontrado a Devlin?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Los huesos de Devlin quedarán de maravilla en mi manto.$B$BLo único que puede consolar a mi pobre corazón es ver el fin de los Agamand. Ellos nos fallaron a mi familia y a mí cuando llegó la Peste... ¡juro acabar con todos ellos!', 0),
(@ID, 'esMX', 'Gracias. Los huesos de Devlin quedarán de maravilla en mi manto.$B$BLo único que puede consolar a mi pobre corazón es ver el fin de los Agamand. Ellos nos fallaron a mi familia y a mí cuando llegó la Peste... ¡juro acabar con todos ellos!', 0);
-- 363 Desvelo brutal
-- https://es.classic.wowhead.com/quest=363
SET @ID := 363;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, otro muerto que camina... Ha debido de ser un shock... despertarse en la cripta con el frío y Mordo como única compañía...$B$BVeo en tu cara que estás muy confuso. Deja que te explique nuestra... situación.$B$BHemos sido liberados del control del Rey Exánime por nuestra nueva líder, Lady Sylvanas. La Dama Oscura nos guía en una guerra contra la odiada Plaga y contra los humanos que aún no aceptan la situación y nos acosan a cada paso.', 0),
(@ID, 'esMX', 'Mm, otro muerto que camina... Ha debido de ser un shock... despertarse en la cripta con el frío y Mordo como única compañía...$B$BVeo en tu cara que estás muy confuso. Deja que te explique nuestra... situación.$B$BHemos sido liberados del control del Rey Exánime por nuestra nueva líder, Lady Sylvanas. La Dama Oscura nos guía en una guerra contra la odiada Plaga y contra los humanos que aún no aceptan la situación y nos acosan a cada paso.', 0);
-- 364 Los autómatas
-- https://es.classic.wowhead.com/quest=364
SET @ID := 364;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No llegarás lejos en esta nueva vida si no puedes matar ni siquiera al más débil de los zombis, $n. No regrese para informar hasta que tengas éxito.', 0),
(@ID, 'esMX', 'No llegarás lejos en esta nueva vida si no puedes matar ni siquiera al más débil de los zombis, $n. No regrese para informar hasta que tengas éxito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una pena que no podamos hacer entrar en razón a los de la Plaga. Nos vendrían bien para futuras batallas, son muy numerosos.$B$BPero no se unirán a nosotros, así que no tenemos más opción que acabar con ellos', 0),
(@ID, 'esMX', 'Es una pena que no podamos hacer entrar en razón a los de la Plaga. Nos vendrían bien para futuras batallas, son muy numerosos.$B$BPero no se unirán a nosotros, así que no tenemos más opción que acabar con ellos', 0);
-- 365 Campos de pena
-- https://es.classic.wowhead.com/quest=365
SET @ID := 365;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El guardia de la muerte Simmer me dijo que me traerías los componentes que tanto anhelo. $n, ¿has podido reunir 10 calabazas?', 0),
(@ID, 'esMX', 'El guardia de la muerte Simmer me dijo que me traerías los componentes que tanto anhelo. $n, ¿has podido reunir 10 calabazas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has cumplido con tu cometido a la perfección, joven $c. Estás demostrando ser todo un hallazgo para el ejército de la Dama Oscura.', 0),
(@ID, 'esMX', 'Has cumplido con tu cometido a la perfección, joven $c. Estás demostrando ser todo un hallazgo para el ejército de la Dama Oscura.', 0);
-- 366 Devuelve el libro
-- https://es.classic.wowhead.com/quest=366
SET @ID := 366;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tus maestros están locos si piensan que volveré a ser un esclavo de la Plaga!', 0),
(@ID, 'esMX', '¡Tus maestros están locos si piensan que volveré a ser un esclavo de la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mi libro! ¡Así que tú me lo robaste!$B$BPero... este hechizo... ¿¡Bethor!? ¿Está en Lordaeron?$B$BEso significa que quizás también haya escapado del rey Exánime...', 0),
(@ID, 'esMX', '¡Mi libro! ¡Así que tú me lo robaste!$B$BPero... este hechizo... ¿¡Bethor!? ¿Está en Lordaeron?$B$BEso significa que quizás también haya escapado del rey Exánime...', 0);
-- 367 Una nueva Peste
-- https://es.classic.wowhead.com/quest=367
SET @ID := 367;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes ya 5 viales de sangre de can oscuro? ¡El tiempo se agota!', 0),
(@ID, 'esMX', '$n, ¿tienes ya 5 viales de sangre de can oscuro? ¡El tiempo se agota!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n y te agradezco tus esfuerzos.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n y te agradezco tus esfuerzos.', 0);
-- 368 Una nueva Peste
-- https://es.classic.wowhead.com/quest=368
SET @ID := 368;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has conseguido 5 escamas de Anca Vil de los murlocs?', 0),
(@ID, 'esMX', '$n, ¿has conseguido 5 escamas de Anca Vil de los murlocs?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las escamas son perfectas, $n. Son justo lo que necesitaba para el brebaje.', 0),
(@ID, 'esMX', 'Las escamas son perfectas, $n. Son justo lo que necesitaba para el brebaje.', 0);
-- 369 Una nueva Peste
-- https://es.classic.wowhead.com/quest=369
SET @ID := 369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes ya el veneno de araña nocturácnida? Es el último componente que necesito para completar mi experimento.', 0),
(@ID, 'esMX', '$n, ¿tienes ya el veneno de araña nocturácnida? Es el último componente que necesito para completar mi experimento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, este veneno será perfecto, $n. Ya he añadido y cocido los demás ingredientes de mi brebaje. ¡Al fin puedo probar este nuevo agente mortal!', 0),
(@ID, 'esMX', 'Ah, este veneno será perfecto, $n. Ya he añadido y cocido los demás ingredientes de mi brebaje. ¡Al fin puedo probar este nuevo agente mortal!', 0);
-- 370 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=370
SET @ID := 370;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Joven $c, no deberías estar perdiendo el tiempo aquí en Brill cuando tu gente te necesita luchando por su causa. Ahora, toma las armas y viaja hacia el suroeste, a la torre en ruinas, y mata al Capitán Perrine junto con 3 Zelotes Escarlata y 3 Misioneros Escarlata. Llevaremos a la Cruzada Escarlata como ganado hasta su desaparición.', 0),
(@ID, 'esMX', 'Joven $c, no deberías estar perdiendo el tiempo aquí en Brill cuando tu gente te necesita luchando por su causa. Ahora, toma las armas y viaja hacia el suroeste, a la torre en ruinas, y mata al Capitán Perrine junto con 3 Zelotes Escarlata y 3 Misioneros Escarlata. Llevaremos a la Cruzada Escarlata como ganado hasta su desaparición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte del capitán Perrine en verdad complacerá a la Dama Oscura. Has hecho un buen trabajo, $c.', 0),
(@ID, 'esMX', 'La muerte del capitán Perrine en verdad complacerá a la Dama Oscura. Has hecho un buen trabajo, $c.', 0);
-- 371 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=371
SET @ID := 371;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has regresado, pero tu tarea no está completa. ¿Quizás te sientas $gcómodo:cómoda; con los simples humanos que interfieren con el plan de La Dama Oscura? ¡O quizás puedas prestar atención al llamado del deber y matar al Capitán Vachon y su banda de Frailes Escarlatas!', 0),
(@ID, 'esMX', 'Veo que has regresado, pero tu tarea no está completa. ¿Quizás te sientas $gcómodo:cómoda; con los simples humanos que interfieren con el plan de La Dama Oscura? ¡O quizás puedas prestar atención al llamado del deber y matar al Capitán Vachon y su banda de Frailes Escarlatas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte del capitán Vachon frenará algo el avance de la Cruzada Escarlata en Tirisfal, pero se avecinan otras amenazas.', 0),
(@ID, 'esMX', 'La muerte del capitán Vachon frenará algo el avance de la Cruzada Escarlata en Tirisfal, pero se avecinan otras amenazas.', 0);

-- 372 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=372
SET @ID := 372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '', 0),
(@ID, 'esMX', '', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy, muy bien, $n. Con $gluchadores despiadados:luchadoras despiadadas; como tú actuando en nombre de los Renegados, nuestra raza está cada vez más cerca de derrotar a Arthas de una vez por todas. Tengo un buen presentimiento respecto a ti, camarada.', 0),
(@ID, 'esMX', 'Lo has hecho muy, muy bien, $n. Con $gluchadores despiadados:luchadoras despiadadas; como tú actuando en nombre de los Renegados, nuestra raza está cada vez más cerca de derrotar a Arthas de una vez por todas. Tengo un buen presentimiento respecto a ti, camarada.', 0);
-- 373 La carta sin enviar
-- https://es.classic.wowhead.com/quest=373
SET @ID := 373;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', '¿Sí? ¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Edwin VanCleef, dices? Sería como recibir una carta de mi abuela muerta... ¿Así que le has matado? Perdona que te lo diga, pero me sorprende bastante. En su juventud, fue un luchador incomparable. Veamos por qué decidió escribirme después de tantos años.$B$B<Baros lee detenidamente la carta.>$B$BEdwin... Veo que los años no te han cambiado, sigues siendo un idealista y un romántico. No le importa hacer daño, $n. La venganza le ha consumido. Aunque no estoy seguro de poder culparle por ello.', 0),
(@ID, 'esMX', '¿Edwin VanCleef, dices? Sería como recibir una carta de mi abuela muerta... ¿Así que le has matado? Perdona que te lo diga, pero me sorprende bastante. En su juventud, fue un luchador incomparable. Veamos por qué decidió escribirme después de tantos años.$B$B<Baros lee detenidamente la carta.>$B$BEdwin... Veo que los años no te han cambiado, sigues siendo un idealista y un romántico. No le importa hacer daño, $n. La venganza le ha consumido. Aunque no estoy seguro de poder culparle por ello.', 0);
-- 374 Prueba de defunción
-- https://es.classic.wowhead.com/quest=374
SET @ID := 374;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿has reunido ya 10 anillos con la insignia escarlata?', 0),
(@ID, 'esMX', '$c, ¿has reunido ya 10 anillos con la insignia escarlata?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Varimathras se sentiría orgulloso pues sirves con diligencia a tus líderes, $c.', 0),
(@ID, 'esMX', 'Varimathras se sentiría orgulloso pues sirves con diligencia a tus líderes, $c.', 0);
-- 375 El frío de la muerte
-- https://es.classic.wowhead.com/quest=375
SET @ID := 375;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes 5 pieles de murciumbrío y algunos hilos gruesos?', 0),
(@ID, 'esMX', '$n, ¿tienes 5 pieles de murciumbrío y algunos hilos gruesos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprecio tus esfuerzos, $n. Ojalá Sylvanas reconozca algún día tu valentía.', 0),
(@ID, 'esMX', 'Aprecio tus esfuerzos, $n. Ojalá Sylvanas reconozca algún día tu valentía.', 0);
-- 376 Los Malditos
-- https://es.classic.wowhead.com/quest=376
SET @ID := 376;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0),
(@ID, 'esMX', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esta armadura te servirá de ayuda.$B$BEspero que, al menos, te dé más suerte que a su último portador...', 0),
(@ID, 'esMX', 'Gracias, $n. Esta armadura te servirá de ayuda.$B$BEspero que, al menos, te dé más suerte que a su último portador...', 0);
-- 379 Aplacar esa sed
-- https://es.classic.wowhead.com/quest=379
SET @ID := 379;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿los nómadas "se ofrecieron como voluntarios" para ti?', 0),
(@ID, 'esMX', 'Bueno, ¿los nómadas "se ofrecieron como voluntarios" para ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, la fuente de energía es tuya. Ahora, no está completamente diseñado para su uso en un kit de ciencia como ese, por lo que solo tendrá una cantidad limitada de tiempo antes de que todos los datos que recopile se vuelvan locos.$B$BCuando reúnas todo lo que necesitas para lo que sea que estés haciendo, tréemela y la apagaré correctamente. Tendrás como máximo dos horas para hacer lo que necesitas.$B$BSi no lo haces a tiempo, siempre puedo venderle otra fuente de energía para volver a intentarlo. Me escuchaste bien... ¡vender!', 0),
(@ID, 'esMX', 'Excelente, la fuente de energía es tuya. Ahora, no está completamente diseñado para su uso en un kit de ciencia como ese, por lo que solo tendrá una cantidad limitada de tiempo antes de que todos los datos que recopile se vuelvan locos.$B$BCuando reúnas todo lo que necesitas para lo que sea que estés haciendo, tréemela y la apagaré correctamente. Tendrás como máximo dos horas para hacer lo que necesitas.$B$BSi no lo haces a tiempo, siempre puedo venderle otra fuente de energía para volver a intentarlo. Me escuchaste bien... ¡vender!', 0);
-- 380 Hoya Nocturácnidas
-- https://es.classic.wowhead.com/quest=380
SET @ID := 380;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado con el veneno de las arañas, $n. Si sientes un ardor agudo, es mejor que te revisen.', 0),
(@ID, 'esMX', 'Ten cuidado con el veneno de las arañas, $n. Si sientes un ardor agudo, es mejor que te revisen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo el mal. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n, seguro que encontraré algo más de trabajo para ti.', 0),
(@ID, 'esMX', 'Mmm, bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo el mal. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n, seguro que encontraré algo más de trabajo para ti.', 0);
-- 381 La Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=381
SET @ID := 381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos insensatos... Se cavan tan contentos sus propias tumbas.', 0),
(@ID, 'esMX', 'Esos insensatos... Se cavan tan contentos sus propias tumbas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, si se atuvieran a razones, ¿eh, $n? Quizás podríamos sentarnos alrededor de una mesa para dialogar... ¡Ja!$B$BEsos esperpentos cegados por la Luz...', 0),
(@ID, 'esMX', 'Ay, si se atuvieran a razones, ¿eh, $n? Quizás podríamos sentarnos alrededor de una mesa para dialogar... ¡Ja!$B$BEsos esperpentos cegados por la Luz...', 0);
-- 382 El mensajero rojo
-- https://es.classic.wowhead.com/quest=382
SET @ID := 382;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu misión, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu misión, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... Veamos lo que traes...$B$B<Empieza a rebuscar entre los documentos que le has entregado.>$B$BInformes de sus hazañas... contra nosotros... Esto no vale nada. Informes de rastreadores... Nuevas órdenes: "Seguir construyendo un campamento cerca de la ciudad en ruinas..." Nada que no supiéramos ya, la verdad... Espera, ¿qué es esto? ¡Un mapa con los destinos de algunos de sus comandantes de campo y agentes! Esto sí nos sirve.', 0),
(@ID, 'esMX', 'Mmm... Veamos lo que traes...$B$B<Empieza a rebuscar entre los documentos que le has entregado.>$B$BInformes de sus hazañas... contra nosotros... Esto no vale nada. Informes de rastreadores... Nuevas órdenes: "Seguir construyendo un campamento cerca de la ciudad en ruinas..." Nada que no supiéramos ya, la verdad... Espera, ¿qué es esto? ¡Un mapa con los destinos de algunos de sus comandantes de campo y agentes! Esto sí nos sirve.', 0);
-- 383 Información decisiva
-- https://es.classic.wowhead.com/quest=383
SET @ID := 383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Qué quieres?', 0),
(@ID, 'esMX', '¿Sí? ¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto está muy bien. Has hecho bien en conseguir esta información, $n. Mmm... los nombres de los oficiales de los Claros de Tirisfal...$B$BImagina el golpe que podríamos asestar a la moral de esos malditos fanáticos si consiguiéramos matar a todos sus jefazos de un golpe.', 0),
(@ID, 'esMX', 'Esto está muy bien. Has hecho bien en conseguir esta información, $n. Mmm... los nombres de los oficiales de los Claros de Tirisfal...$B$BImagina el golpe que podríamos asestar a la moral de esos malditos fanáticos si consiguiéramos matar a todos sus jefazos de un golpe.', 0);
-- 389 Bazil Thredd
-- https://es.classic.wowhead.com/quest=389
SET @ID := 389;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el nombre de la Luz, ¿qué quieres? ¿No ves que estamos en medio de una crisis?$B$B¡¿Bazil Thredd?! ¿Por qué quieres hablar con ese bastardo? ¿Cómo se supone que voy a saber que no eres uno de sus amigos que ha venido a ayudarle con este maldito motín? Si las malditas celdas no estuvieran abiertas, ¡te metería en una!', 0),
(@ID, 'esMX', 'En el nombre de la Luz, ¿qué quieres? ¿No ves que estamos en medio de una crisis?$B$B¡¿Bazil Thredd?! ¿Por qué quieres hablar con ese bastardo? ¿Cómo se supone que voy a saber que no eres uno de sus amigos que ha venido a ayudarle con este maldito motín? Si las malditas celdas no estuvieran abiertas, ¡te metería en una!', 0);
-- 391 El motín de Las Mazmorras
-- https://es.classic.wowhead.com/quest=391
SET @ID := 391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'O me traes la cabeza de Thredd, o me quedo con la tuya, ¿lo entiendes, $n?', 0),
(@ID, 'esMX', 'O me traes la cabeza de Thredd, o me quedo con la tuya, ¿lo entiendes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin Thredd para liderarlos, esperemos poder controlar los motines. Ya veremos.$B$BDebo decirte que no esperaba que duraras más de media hora, pero parece que te juzgué mal.$B$B¿Supongo que no conseguiste sacarle mucha información útil, no? Pero sé un par de cosas que podrían interesarte sobre las actividades de Thredd.', 0),
(@ID, 'esMX', 'Sin Thredd para liderarlos, esperemos poder controlar los motines. Ya veremos.$B$BDebo decirte que no esperaba que duraras más de media hora, pero parece que te juzgué mal.$B$B¿Supongo que no conseguiste sacarle mucha información útil, no? Pero sé un par de cosas que podrían interesarte sobre las actividades de Thredd.', 0);
-- 392 Extraño visitante
-- https://es.classic.wowhead.com/quest=392
SET @ID := 392;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Qué has encontrado?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Qué has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm. ¿Maelik? No, no me suena el nombre, ni tampoco la descripción. ¡Pero podría ser cualquiera! Un antiguo Albañil, un miembro de la Hermandad Defias... Aunque si está tan bien conectado como sugiere Thelagua, quizás alguien le pueda reconocer. Deja que lo piense...', 0),
(@ID, 'esMX', 'Mmm. ¿Maelik? No, no me suena el nombre, ni tampoco la descripción. ¡Pero podría ser cualquiera! Un antiguo Albañil, un miembro de la Hermandad Defias... Aunque si está tan bien conectado como sugiere Thelagua, quizás alguien le pueda reconocer. Deja que lo piense...', 0);
-- 393 Sombras del pasado
-- https://es.classic.wowhead.com/quest=393
SET @ID := 393;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿En qué puedo serte de ayuda, $c?', 0),
(@ID, 'esMX', 'Saludos. ¿En qué puedo serte de ayuda, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Qué es esto? Sí, creo que sé quién es, pero no se llama Maelik. Los asesinos usan muchos nombres y muchas máscaras, cambiando de personalidad cada vez que lo necesitan. Ese hombre también utilizaba otro alias, Marzon; aunque tampoco creo que ese sea su verdadero nombre.$B$BNo importa, es un asesino y sé mucho sobre él.$B$BAhora mismo, Marzon trabaja para Lord Gregor Lescovar, un lord bastante sombrío, incluso para la norma de corrupción de la nobleza de Ventormenta.', 0),
(@ID, 'esMX', '¿Qué? ¿Qué es esto? Sí, creo que sé quién es, pero no se llama Maelik. Los asesinos usan muchos nombres y muchas máscaras, cambiando de personalidad cada vez que lo necesitan. Ese hombre también utilizaba otro alias, Marzon; aunque tampoco creo que ese sea su verdadero nombre.$B$BNo importa, es un asesino y sé mucho sobre él.$B$BAhora mismo, Marzon trabaja para Lord Gregor Lescovar, un lord bastante sombrío, incluso para la norma de corrupción de la nobleza de Ventormenta.', 0);
-- 394 La cabeza de la bestia
-- https://es.classic.wowhead.com/quest=394
SET @ID := 394;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¡Está muerto!? Has administrado justicia rápidamente, $n. Rezo a la Luz para no convertirme nunca en tu enemigo.$B$B<Se ríe y te da una palmada en el hombro.>$B$BNo es por criticar, $n. ¿Cómo podría hacerlo siendo el maestro de todos los asesinos? Pero, a decir verdad, has hecho un gran servicio al pueblo de Ventormenta y, por eso, te doy las gracias.', 0),
(@ID, 'esMX', '¿¡Está muerto!? Has administrado justicia rápidamente, $n. Rezo a la Luz para no convertirme nunca en tu enemigo.$B$B<Se ríe y te da una palmada en el hombro.>$B$BNo es por criticar, $n. ¿Cómo podría hacerlo siendo el maestro de todos los asesinos? Pero, a decir verdad, has hecho un gran servicio al pueblo de Ventormenta y, por eso, te doy las gracias.', 0);
-- 395 El fin de la Hermandad
-- https://es.classic.wowhead.com/quest=395
SET @ID := 395;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. He oído que Lord Gregor Lescovar fue encontrado muerto no hace mucho tiempo.$B$BParece ser que has tenido éxito en tu misión. Tienes mi gratitud, nos has salvado a mí y a muchos más, de la venganza de VanCleef.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. He oído que Lord Gregor Lescovar fue encontrado muerto no hace mucho tiempo.$B$BParece ser que has tenido éxito en tu misión. Tienes mi gratitud, nos has salvado a mí y a muchos más, de la venganza de VanCleef.', 0);
-- 396 Una audiencia con el Rey
-- https://es.classic.wowhead.com/quest=396
SET @ID := 396;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿sí? Baros Alexston me informó de tu llegada. Debo decir que me interesa mucho lo que tienes que decir.', 0),
(@ID, 'esMX', '$n, ¿sí? Baros Alexston me informó de tu llegada. Debo decir que me interesa mucho lo que tienes que decir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te estamos muy agradecidos por el servicio que has hecho a Ventormenta, $n. Si VanCleef hubiese tenido éxito con sus maquinaciones, sin duda habría causado daño al reino... algo que, obviamente, queremos evitar a toda costa.$B$B$c, acepta esto como muestra del agradecimiento del rey. Siento que no te lo pueda dar él mismo, pero está fuera en una misión diplomática y no volverá en un tiempo.', 0),
(@ID, 'esMX', 'Te estamos muy agradecidos por el servicio que has hecho a Ventormenta, $n. Si VanCleef hubiese tenido éxito con sus maquinaciones, sin duda habría causado daño al reino... algo que, obviamente, queremos evitar a toda costa.$B$B$c, acepta esto como muestra del agradecimiento del rey. Siento que no te lo pueda dar él mismo, pero está fuera en una misión diplomática y no volverá en un tiempo.', 0);
-- 8325 Recuperar la Isla del Caminante del Sol
-- https://es.wowhead.com/quest=8325
SET @ID := 8325;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro trabajo en la reconstrucción de nuestra sociedad comienza aquí, $n. Una vez que podamos asegurar nuestro hogar, podemos mirar hacia afuera y hacia arriba.', 0),
(@ID, 'esMX', 'Nuestro trabajo en la reconstrucción de nuestra sociedad comienza aquí, $n. Una vez que podamos asegurar nuestro hogar, podemos mirar hacia afuera y hacia arriba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te felicito por haber completado tu primera tarea. Eso me da esperanzas de que vas a ser mejor que esos jóvenes elfos de sangre que se niegan a escuchar las lecciones de sus maestros. Tu trabajo y esfuerzos serán recompensados, no solo con el conocimiento, sino también de forma tangible.$B$BPero aún te queda mucho por hacer. Hay tanto por aprender...', 0),
(@ID, 'esMX', 'Te felicito por haber completado tu primera tarea. Eso me da esperanzas de que vas a ser mejor que esos jóvenes elfos de sangre que se niegan a escuchar las lecciones de sus maestros. Tu trabajo y esfuerzos serán recompensados, no solo con el conocimiento, sino también de forma tangible.$B$BPero aún te queda mucho por hacer. Hay tanto por aprender...', 0);
-- 8326 Medidas extremas
-- https://es.classic.wowhead.com/quest=8326
SET @ID := 8326;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me desagrada pedirte que aniquiles a estas bestias. En el pasado vivimos en relativa armonía con las criaturas de los bosques, pero las cosas han cambiado. La prioridad principal de los sin\'dorei es la supervivencia; no lo olvides.', 0),
(@ID, 'esMX', 'Me desagrada pedirte que aniquiles a estas bestias. En el pasado vivimos en relativa armonía con las criaturas de los bosques, pero las cosas han cambiado. La prioridad principal de los sin\'dorei es la supervivencia; no lo olvides.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La torre y alrededores son zona segura, al menos de momento. Nos has ayudado a conseguir seguridad temporal, pero tenemos que recuperar el control sobre toda la isla si queremos sobrevivir aquí. Eso implica ocuparse de amenazas bastante más graves que unos linces y vermis de maná errantes.$B$BToma esto, $n; seguro que te será útil en tus próximas misiones.', 0),
(@ID, 'esMX', 'La torre y alrededores son zona segura, al menos de momento. Nos has ayudado a conseguir seguridad temporal, pero tenemos que recuperar el control sobre toda la isla si queremos sobrevivir aquí. Eso implica ocuparse de amenazas bastante más graves que unos linces y vermis de maná errantes.$B$BToma esto, $n; seguro que te será útil en tus próximas misiones.', 0);
-- 8563 Entrenamiento de brujos
-- https://es.classic.wowhead.com/quest=8563
SET @ID := 8563;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n - tu nombre ha pasado por mis oídos como alguien que busca un maestro en los caminos del brujo. Pareces lo suficientemente capaz, pero busco algo más que miradas en mis alumnos. Debes estar $glisto:lista; para ahondar donde otros temen buscar para obtener tu poder. Te enseñaré, pero no toleraré el fracaso.$B$BHabrá costos monetarios asociados con tu capacitación, pero deberías preocuparte más por el costo que tu mente tendrá que soportar. Si estás $glisto:lista;, comenzaremos.', 0),
(@ID, 'esMX', '$n - tu nombre ha pasado por mis oídos como alguien que busca un maestro en los caminos del brujo. Pareces lo suficientemente capaz, pero busco algo más que miradas en mis alumnos. Debes estar $glisto:lista; para ahondar donde otros temen buscar para obtener tu poder. Te enseñaré, pero no toleraré el fracaso.$B$BHabrá costos monetarios asociados con tu capacitación, pero deberías preocuparte más por el costo que tu mente tendrá que soportar. Si estás $glisto:lista;, comenzaremos.', 0);
-- 8336 Por un puñado de esquirlas
-- https://es.classic.wowhead.com/quest=8336
SET @ID := 8336;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas de las criaturas aquí en la isla estuvieron en un momento atadas a la docilidad y la complacencia por nuestras habilidades mágicas. Cuando la Plaga destruyó la Fuente del Sol, nuestro control sobre estas criaturas se hizo añicos. Las astillas arcanas son los remanentes del control que alguna vez tuvimos y, como tales, podrían usarse para diseñar un nuevo dispositivo que nos ayude a recuperar su control.$B$BMejor aún, tal vez las astillas podrían usarse para ver el malestar que realmente sufre la isla...', 0),
(@ID, 'esMX', 'Muchas de las criaturas aquí en la isla estuvieron en un momento atadas a la docilidad y la complacencia por nuestras habilidades mágicas. Cuando la Plaga destruyó la Fuente del Sol, nuestro control sobre estas criaturas se hizo añicos. Las astillas arcanas son los remanentes del control que alguna vez tuvimos y, como tales, podrían usarse para diseñar un nuevo dispositivo que nos ayude a recuperar su control.$B$BMejor aún, tal vez las astillas podrían usarse para ver el malestar que realmente sufre la isla...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espléndido, estas funcionarán muy bien. He estado pensando un poco en el malestar actual que sufre la Isla del Caminante del Sol. Un posible curso de acción que había meditado era recoger estas astillas arcanas de las bestias de la isla. Al hacerlo, se podría experimentar con ellos; esto proporcionaría una fuente potencial de información.$B$BDe todos modos, me ocuparé de la investigación. Permíteme otorgarte este encantamiento. ¡Creo que harás un buen uso de él!', 0),
(@ID, 'esMX', 'Espléndido, estas funcionarán muy bien. He estado pensando un poco en el malestar actual que sufre la Isla del Caminante del Sol. Un posible curso de acción que había meditado era recoger estas astillas arcanas de las bestias de la isla. Al hacerlo, se podría experimentar con ellos; esto proporcionaría una fuente potencial de información.$B$BDe todos modos, me ocuparé de la investigación. Permíteme otorgarte este encantamiento. ¡Creo que harás un buen uso de él!', 0);
-- 8346 Sed insaciable
-- https://es.classic.wowhead.com/quest=8346
SET @ID := 8346;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah $n. ¿Has completado tu tarea?', 0),
(@ID, 'esMX', 'Ah $n. ¿Has completado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien hoy, $n. Tu disposición a aprender demuestra que es muy posible que superes los perjuicios inquebrantables que debes soportar como $R.$B$BNo descanses en tus laureles, joven, ahora busca dominar lo que ha aprendido. Solo mediante la diligencia sobreviviremos como raza.$B$BToma esto', 0),
(@ID, 'esMX', 'Lo has hecho bien hoy, $n. Tu disposición a aprender demuestra que es muy posible que superes los perjuicios inquebrantables que debes soportar como $R.$B$BNo descanses en tus laureles, joven, ahora busca dominar lo que ha aprendido. Solo mediante la diligencia sobreviviremos como raza.$B$BToma esto', 0);

-- 8327 Informar a Lanthan Perilon
-- https://es.classic.wowhead.com/quest=8327
SET @ID := 8327;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La magistrix Erona me dijo que llegarías pronto, $n. Ese edificio flotante con agujas ornamentadas, al oeste, es la Academia Falthrien. Tú dirigirás las operaciones para recuperarla de manos de uno de los desdichados, un $r que siempre ha sucumbido a sus más bajos instintos.$B$BEspero que vengas con ganas de trabajar. Esto no va a ser solo una lección sobre el peligro, sino sobre lo que pasa cuando olvidas quién eres.', 0),
(@ID, 'esMX', 'La magistrix Erona me dijo que llegarías pronto, $n. Ese edificio flotante con agujas ornamentadas, al oeste, es la Academia Falthrien. Tú dirigirás las operaciones para recuperarla de manos de uno de los desdichados, un $r que siempre ha sucumbido a sus más bajos instintos.$B$BEspero que vengas con ganas de trabajar. Esto no va a ser solo una lección sobre el peligro, sino sobre lo que pasa cuando olvidas quién eres.', 0);
-- 397 Nos has hecho un gran servicio
-- https://es.classic.wowhead.com/quest=397
SET @ID := 397;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maestro dice dar regalo a $n. Zggi querer quedarse con bonito regalo, pero Zggi no ser tan tonto para traicionar al maestro.', 0),
(@ID, 'esMX', 'Maestro dice dar regalo a $n. Zggi querer quedarse con bonito regalo, pero Zggi no ser tan tonto para traicionar al maestro.', 0);
-- 398 Se busca: Ojo de cresa
-- https://es.classic.wowhead.com/quest=398
SET @ID := 398;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin los ruines actos de Ojo de gusano han encontrado su venganza. Esperemos que este acto de valentía por tu parte sea un mensaje claro para aquellos que desean traer el sufrimiento a nuestro pueblo. En nombre de la ciudad de Rémol te doy las gracias, $n.', 0),
(@ID, 'esMX', 'Por fin los ruines actos de Ojo de gusano han encontrado su venganza. Esperemos que este acto de valentía por tu parte sea un mensaje claro para aquellos que desean traer el sufrimiento a nuestro pueblo. En nombre de la ciudad de Rémol te doy las gracias, $n.', 0);
-- 404 Una tarea pútrida
-- https://es.classic.wowhead.com/quest=404
SET @ID := 404;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado lo que te encomendé? ¿Ya tienes las garras pútridas?', 0),
(@ID, 'esMX', '¿Has acabado lo que te encomendé? ¿Ya tienes las garras pútridas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. ¡Cómo me hubiera gustado presenciar el fin de esos no-muertos!', 0),
(@ID, 'esMX', 'Bien hecho. ¡Cómo me hubiera gustado presenciar el fin de esos no-muertos!', 0);
-- 405 El exánime pródigo
-- https://es.classic.wowhead.com/quest=405
SET @ID := 405;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. O no sabes quién soy o tienes algo urgente que tratar conmigo.$B$BEn caso de que ninguno de estos dos supuestos te atañan, desearás no haberme molestado.', 0),
(@ID, 'esMX', 'Saludos. O no sabes quién soy o tienes algo urgente que tratar conmigo.$B$BEn caso de que ninguno de estos dos supuestos te atañan, desearás no haberme molestado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, si te envía el magistrado Sevren entonces tengo una tarea de suma importancia que confiarte.$B$BEspero que estés a la altura... aunque eso ya se verá.', 0),
(@ID, 'esMX', 'Ah, si te envía el magistrado Sevren entonces tengo una tarea de suma importancia que confiarte.$B$BEspero que estés a la altura... aunque eso ya se verá.', 0);
-- 407 Campos de pena
-- https://es.classic.wowhead.com/quest=407
SET @ID := 407;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te acerques a mí, inmunda e impura criatura! ¡Que la Luz me proteja! La Cruzada Escarlata te expulsará de Azeroth y... .$B$B... espera. ¿Me traes comida? Tengo tanta hambre…', 0),
(@ID, 'esMX', '¡No te acerques a mí, inmunda e impura criatura! ¡Que la Luz me proteja! La Cruzada Escarlata te expulsará de Azeroth y... .$B$B... espera. ¿Me traes comida? Tengo tanta hambre…', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por la Luz! ¡Al fin algo de comida! Dulce, dulce calabaza…', 0),
(@ID, 'esMX', '¡Por la Luz! ¡Al fin algo de comida! Dulce, dulce calabaza…', 0);
-- 408 La Cripta de la Familia
-- https://es.classic.wowhead.com/quest=408
SET @ID := 408;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo corre en nuestra contra, $n. Cada hora que pasa, la Plaga afianza su posición en los Claros de Tirisfal.', 0),
(@ID, 'esMX', 'El tiempo corre en nuestra contra, $n. Cada hora que pasa, la Plaga afianza su posición en los Claros de Tirisfal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tus acciones has asestado un duro golpe a la Plaga. Tu victoria no pasará inadvertida, ni para los Renegados ni para nuestros enemigos.$B$BSigue luchando como nosotros y quizás algún día consigamos expulsar al mismísimo rey Exánime de Azeroth.', 0),
(@ID, 'esMX', 'Con tus acciones has asestado un duro golpe a la Plaga. Tu victoria no pasará inadvertida, ni para los Renegados ni para nuestros enemigos.$B$BSigue luchando como nosotros y quizás algún día consigamos expulsar al mismísimo rey Exánime de Azeroth.', 0);
-- 409 Prueba de lealtad
-- https://es.classic.wowhead.com/quest=409
SET @ID := 409;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero una prueba de tu lealtad, $c.', 0),
(@ID, 'esMX', 'Espero una prueba de tu lealtad, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has derrotado a Lillith Nefara, lo que demuestra que eres $genemigo:enemiga; de la Plaga. Es increíble.$B$BHubiera jurado que era el único no-muerto con voluntad propia pero me has demostrado que también hay otros libres de la dominación del rey Exánime.', 0),
(@ID, 'esMX', 'Has derrotado a Lillith Nefara, lo que demuestra que eres $genemigo:enemiga; de la Plaga. Es increíble.$B$BHubiera jurado que era el único no-muerto con voluntad propia pero me has demostrado que también hay otros libres de la dominación del rey Exánime.', 0);
-- 410 Sombra durmiente
-- https://es.classic.wowhead.com/quest=410
SET @ID := 410;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta vieja mesa está hecha polvo.', 0),
(@ID, 'esMX', 'Esta vieja mesa está hecha polvo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas la vela de señalización sobre la mesa y la enciendes...', 0),
(@ID, 'esMX', 'Colocas la vela de señalización sobre la mesa y la enciendes...', 0);
-- 411 El regreso del exánime pródigo
-- https://es.classic.wowhead.com/quest=411
SET @ID := 411;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Le has devuelto a Gunther su libro? ¿Ha reaccionado?', 0),
(@ID, 'esMX', '¿Le has devuelto a Gunther su libro? ¿Ha reaccionado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido que se una a nuestra causa! Has hecho algo estupendo por los Renegados, $n. La Dama Oscura conocerá tu hazaña.', 0),
(@ID, 'esMX', '¡Has conseguido que se una a nuestra causa! Has hecho algo estupendo por los Renegados, $n. La Dama Oscura conocerá tu hazaña.', 0);
-- 415 La nueva bebida de Rejold
-- https://es.classic.wowhead.com/quest=415
SET @ID := 415;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Recuerdas la cerveza de cardaluz que me trajiste? Pues la utilicé en algunas recetas en las que estoy trabajando y una de ellas me salió mejor que genial.$B$BMira, prueba y dime qué opinas.', 0),
(@ID, 'esMX', '¡$n! ¿Recuerdas la cerveza de cardaluz que me trajiste? Pues la utilicé en algunas recetas en las que estoy trabajando y una de ellas me salió mejor que genial.$B$BMira, prueba y dime qué opinas.', 0);
-- 421 Demuestra tu valía
-- https://es.classic.wowhead.com/quest=421
SET @ID := 421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si quieres demostrar tu valía, debes matar a 5 Canosos Furia Lunar. Realiza esta tarea, y me aseguraré de que tu habilidad se use en tareas más valiosas.', 0),
(@ID, 'esMX', 'Si quieres demostrar tu valía, debes matar a 5 Canosos Furia Lunar. Realiza esta tarea, y me aseguraré de que tu habilidad se use en tareas más valiosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has servido bien, $c. Es obvio que serás de gran ayuda mientras me preparo para liberar el Bosque de Argénteos de la maldición de Arugal.', 0),
(@ID, 'esMX', 'Me has servido bien, $c. Es obvio que serás de gran ayuda mientras me preparo para liberar el Bosque de Argénteos de la maldición de Arugal.', 0);
-- 422 La locura de Arugal
-- https://es.classic.wowhead.com/quest=422
SET @ID := 422;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Antes de saber lo que tenemos entre manos, $c, tengo que estudiar el hechizo conocido como el Remedio de Arugal. Tráemelo ahora, o tendré que buscar a un sirviente digno de hacerlo.', 0),
(@ID, 'esMX', 'Antes de saber lo que tenemos entre manos, $c, tengo que estudiar el hechizo conocido como el Remedio de Arugal. Tráemelo ahora, o tendré que buscar a un sirviente digno de hacerlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Precisamente, este es el hechizo que estaba buscando, $c. Si tu dedicación a la causa de la Dama Oscura permanece infalible, tendrás un futuro entre los Renegados.', 0),
(@ID, 'esMX', 'Precisamente, este es el hechizo que estaba buscando, $c. Si tu dedicación a la causa de la Dama Oscura permanece infalible, tendrás un futuro entre los Renegados.', 0);
-- 423 La locura de Arugal
-- https://es.classic.wowhead.com/quest=423
SET @ID := 423;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré 6 grilletes de glotón y 3 grilletes de almanegra antes de poder evaluar la situación y encontrar una solución para Arugal. Ahora haz lo que tienes que hacer y mata glotones Furia Lunar y almanegras Furia Lunar hasta que tenga todo lo que necesito.', 0),
(@ID, 'esMX', 'Necesitaré 6 grilletes de glotón y 3 grilletes de almanegra antes de poder evaluar la situación y encontrar una solución para Arugal. Ahora haz lo que tienes que hacer y mata glotones Furia Lunar y almanegras Furia Lunar hasta que tenga todo lo que necesito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero poder adquirir suficiente energía de una muestra tan limitada. Quizás tenía que haberte pedido más grilletes.$B$BDe todas formas, has demostrado una gran habilidad para reunir estos, $c.', 0),
(@ID, 'esMX', 'Espero poder adquirir suficiente energía de una muestra tan limitada. Quizás tenía que haberte pedido más grilletes.$B$BDe todas formas, has demostrado una gran habilidad para reunir estos, $c.', 0);
-- 424 La locura de Arugal
-- https://es.classic.wowhead.com/quest=424
SET @ID := 424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Grimson el Pálido? Varimathras no estará contento si no hacemos lo que quiere.', 0),
(@ID, 'esMX', '¿Has matado a Grimson el Pálido? Varimathras no estará contento si no hacemos lo que quiere.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! La mina nos proporcionará excelentes recursos para nuestras tropas mientras avanzamos a través de Argénteos de camino a Azeroth.', 0),
(@ID, 'esMX', '¡Soberbio! La mina nos proporcionará excelentes recursos para nuestras tropas mientras avanzamos a través de Argénteos de camino a Azeroth.', 0);
-- 425 Ivar el Hediondo
-- https://es.classic.wowhead.com/quest=425
SET @ID := 425;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Ivar el Hediondo? Si no quieres hacerlo por mi hermano y por mí, al menos hazlo por los Renegados.', 0),
(@ID, 'esMX', '¿Has matado a Ivar el Hediondo? Si no quieres hacerlo por mi hermano y por mí, al menos hazlo por los Renegados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muchas gracias. Tienes mi gratitud, $n.$B$BY te incluiré en el informe que presento a mis superiores.', 0),
(@ID, 'esMX', 'Ah, muchas gracias. Tienes mi gratitud, $n.$B$BY te incluiré en el informe que presento a mis superiores.', 0);
-- 426 La invasión de los molinos
-- https://es.classic.wowhead.com/quest=426
SET @ID := 426;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestras batallas contra la Plaga están en marcha, $n. ¡Haz lo que te corresponde y envía a esos malditos no-muertos de vuelta a las Tierras de la Peste!', 0),
(@ID, 'esMX', 'Nuestras batallas contra la Plaga están en marcha, $n. ¡Haz lo que te corresponde y envía a esos malditos no-muertos de vuelta a las Tierras de la Peste!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos estás ayudando mucho en la guerra, $n. No te daré las gracias por hacer lo que es necesario, pero has de saber que los guardias de la muerte de Tirisfal no olvidaremos tu nombre.', 0),
(@ID, 'esMX', 'Nos estás ayudando mucho en la guerra, $n. No te daré las gracias por hacer lo que es necesario, pero has de saber que los guardias de la muerte de Tirisfal no olvidaremos tu nombre.', 0);
-- 427 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=427
SET @ID := 427;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si deseas demostrar tu valía a La Dama Oscura, mata a 10 Guerreros Escarlata, $c.', 0),
(@ID, 'esMX', 'Si deseas demostrar tu valía a La Dama Oscura, mata a 10 Guerreros Escarlata, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $c. Tu habilidad en el arte de la lucha es innegable.', 0),
(@ID, 'esMX', 'Impresionante, $c. Tu habilidad en el arte de la lucha es innegable.', 0);
-- 428 Los Mortacechadores desaparecidos
-- https://es.classic.wowhead.com/quest=428
SET @ID := 428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos has encontrado! Y justo a tiempo.', 0),
(@ID, 'esMX', '¡Nos has encontrado! Y justo a tiempo.', 0);
-- 429 Corazones salvajes
-- https://es.classic.wowhead.com/quest=429
SET @ID := 429;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me queda mucho tiempo, $c, la Dama Oscura me ha encargado una tarea de vital importancia.', 0),
(@ID, 'esMX', 'No me queda mucho tiempo, $c, la Dama Oscura me ha encargado una tarea de vital importancia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renferrel coge los corazones.>$B$BResulta de lo más perturbador saber que nuestros Mortacechadores han fallado su misión.$B$BEsperemos que no tengamos muchos fracasos más.$B$BTe daré la poción en un momento, pero aquí tienes la receta. Si esos Mortacechadores necesitan ayuda en el futuro, quizás podías dárselo tú mismo.', 0),
(@ID, 'esMX', '<Renferrel coge los corazones.>$B$BResulta de lo más perturbador saber que nuestros Mortacechadores han fallado su misión.$B$BEsperemos que no tengamos muchos fracasos más.$B$BTe daré la poción en un momento, pero aquí tienes la receta. Si esos Mortacechadores necesitan ayuda en el futuro, quizás podías dárselo tú mismo.', 0);
-- 430 Regresa junto a Quinn
-- https://es.classic.wowhead.com/quest=430
SET @ID := 430;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermana me dijo que estabas aquí para ayudarnos. ¿Es eso cierto?', 0),
(@ID, 'esMX', 'Mi hermana me dijo que estabas aquí para ayudarnos. ¿Es eso cierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Quinn coge la poción y la bebe.>$B$BSí, siento que funciona. Pronto podré viajar.$B$BMe has hecho un gran favor, $n.', 0),
(@ID, 'esMX', '<Quinn coge la poción y la bebe.>$B$BSí, siento que funciona. Pronto podré viajar.$B$BMe has hecho un gran favor, $n.', 0);
-- 431 Velas de señalización
-- https://es.classic.wowhead.com/quest=431
SET @ID := 431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges una de las velas y la colocas en tu talega.', 0),
(@ID, 'esMX', 'Coges una de las velas y la colocas en tu talega.', 0);

-- 432 ¡Malditos troggs!
-- https://es.classic.wowhead.com/quest=432
SET @ID := 432;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto me enoja mucho! Grrr...', 0),
(@ID, 'esMX', '¡Esto me enoja mucho! Grrr...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, ahora me siento un poco mejor...$B$B¡Pero no conseguiré paz hasta que estén todos muertos! ¡Todos ellos!', 0),
(@ID, 'esMX', 'Vaya, ahora me siento un poco mejor...$B$B¡Pero no conseguiré paz hasta que estén todos muertos! ¡Todos ellos!', 0);
-- 433 El servidor público
-- https://es.classic.wowhead.com/quest=433
SET @ID := 433;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si podemos sacar a los troggs de la Cantera de Gol\'Bolar, será el primer paso de muchos que tendremos que emprender para librarnos de esta amenaza.', 0),
(@ID, 'esMX', 'Si podemos sacar a los troggs de la Cantera de Gol\'Bolar, será el primer paso de muchos que tendremos que emprender para librarnos de esta amenaza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un comienzo. Con suerte podremos aprovechar el momento y llevar a algunos montaraces para asegurar el área. Luego podremos comenzar a reconstruir nuestra infraestructura para que los mineros vuelvan al trabajo.$B$BGracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Es un comienzo. Con suerte podremos aprovechar el momento y llevar a algunos montaraces para asegurar el área. Luego podremos comenzar a reconstruir nuestra infraestructura para que los mineros vuelvan al trabajo.$B$BGracias por tu ayuda, $n.', 0);
-- 434 El ataque
-- https://es.classic.wowhead.com/quest=434
SET @ID := 434;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $N? ¿Van las cosas bien con Tyrion? Me informó de la situación y lo ayudé a engañar a Marzon para que fuera al castillo.$B$BMarzon ha sido una espina clavada en el costado de muchas personas en Ventormenta; muchos de los cuales son amigos míos cercanos. Nadie se mete con mis amigos... no si saben lo que es saludable para ellos.$B$BEs una lástima que indirectamente esté haciendo un favor a Shaw y IV:7 mientras tanto. Bueno, no todos los planes son perfectos.', 0),
(@ID, 'esMX', '¿Sí, $N? ¿Van las cosas bien con Tyrion? Me informó de la situación y lo ayudé a engañar a Marzon para que fuera al castillo.$B$BMarzon ha sido una espina clavada en el costado de muchas personas en Ventormenta; muchos de los cuales son amigos míos cercanos. Nadie se mete con mis amigos... no si saben lo que es saludable para ellos.$B$BEs una lástima que indirectamente esté haciendo un favor a Shaw y IV:7 mientras tanto. Bueno, no todos los planes son perfectos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces ya está? Bien. Muchísimas gracias por tu discreción, $n. Has demostrado tu gran valía en más de una ocasión. Me aseguraré de seguir de cerca tu progreso en la Alianza.$B$BNo te metas en líos.', 0),
(@ID, 'esMX', '¿Entonces ya está? Bien. Muchísimas gracias por tu discreción, $n. Has demostrado tu gran valía en más de una ocasión. Me aseguraré de seguir de cerca tu progreso en la Alianza.$B$BNo te metas en líos.', 0);
-- 435 Escolta a Erland
-- https://es.classic.wowhead.com/quest=435
SET @ID := 435;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Temía que Erland hubiera perecido en Argénteos. Pero, gracias a ti, veo que sigue con vida.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Temía que Erland hubiera perecido en Argénteos. Pero, gracias a ti, veo que sigue con vida.', 0);
-- 437 El Campo Muerto
-- https://es.classic.wowhead.com/quest=437
SET @ID := 437;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Latipesadilla, $n? ¡Nuestro éxito contra los Putrepellejo depende de su aniquilación!', 0),
(@ID, 'esMX', '¿Has derrotado a Latipesadilla, $n? ¡Nuestro éxito contra los Putrepellejo depende de su aniquilación!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me he enterado de tu exitoso asalto contra los Putrepellejo, $n, y esta esencia demuestra la muerte de Latipesadilla.$B$BHoy, la Plaga ha perdido terreno. Tu valía aumenta para los Renegados.', 0),
(@ID, 'esMX', 'Me he enterado de tu exitoso asalto contra los Putrepellejo, $n, y esta esencia demuestra la muerte de Latipesadilla.$B$BHoy, la Plaga ha perdido terreno. Tu valía aumenta para los Renegados.', 0);
-- 438 El Viejo Embarcadero
-- https://es.classic.wowhead.com/quest=438
SET @ID := 438;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En este barco hay una pila de cadáveres envueltos. Y, mirando hacia el este a través del Lago Lordamere, se puede ver un puerto en la Isla de Fenris.$B$BEl destino de esos cadáveres debe de ser la Isla de Fenris.', 0),
(@ID, 'esMX', 'En este barco hay una pila de cadáveres envueltos. Y, mirando hacia el este a través del Lago Lordamere, se puede ver un puerto en la Isla de Fenris.$B$BEl destino de esos cadáveres debe de ser la Isla de Fenris.', 0);
-- 439 Pistas de Putrepellejos
-- https://es.classic.wowhead.com/quest=439
SET @ID := 439;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Has regresado, así que supongo que tus investigaciones han tenido éxito.', 0),
(@ID, 'esMX', '$n. Has regresado, así que supongo que tus investigaciones han tenido éxito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que este anillo lo llevaba una mujer asesinada recientemente?$B$BEl único sitio de donde se puede sacar un cadáver así es de las fosas comunes de Tirisfal. Los gnolls Putrepellejo deben de estar llevando esos cadáveres a la Isla de Fenris.', 0),
(@ID, 'esMX', '¿Dices que este anillo lo llevaba una mujer asesinada recientemente?$B$BEl único sitio de donde se puede sacar un cadáver así es de las fosas comunes de Tirisfal. Los gnolls Putrepellejo deben de estar llevando esos cadáveres a la Isla de Fenris.', 0);
-- 440 El anillo grabado
-- https://es.classic.wowhead.com/quest=440
SET @ID := 440;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué te trae de nuevo por Rémol?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué te trae de nuevo por Rémol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Había una Deliah que vivía en Rémol no hace mucho. La enterraron en la fosa común pero, si lo que dices es cierto, los gnolls Putrepellejo deben de haber robado su cadáver para llevárselo a Argénteos.$B$BTenemos que destruir a los Putrepellejo, al igual que a toda la Plaga. Confío en que te estés encargando de eso.', 0),
(@ID, 'esMX', 'Había una Deliah que vivía en Rémol no hace mucho. La enterraron en la fosa común pero, si lo que dices es cierto, los gnolls Putrepellejo deben de haber robado su cadáver para llevárselo a Argénteos.$B$BTenemos que destruir a los Putrepellejo, al igual que a toda la Plaga. Confío en que te estés encargando de eso.', 0);
-- 441 Raleigh y Entrañas
-- https://es.classic.wowhead.com/quest=441
SET @ID := 441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nos conocemos?', 0),
(@ID, 'esMX', '¿Nos conocemos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este anillo era de mi mujer. Compartió destino con todos los que cayeron en esta dura época. No siento nada por su muerte ni por la historia del secuestro de su cadáver.$B$BHace mucho tiempo que lo que sentía por ella se enfrió. Pero el deseo sigue quemando en mi corazón muerto, $n.$B$BDeseo de venganza.', 0),
(@ID, 'esMX', 'Sí, este anillo era de mi mujer. Compartió destino con todos los que cayeron en esta dura época. No siento nada por su muerte ni por la historia del secuestro de su cadáver.$B$BHace mucho tiempo que lo que sentía por ella se enfrió. Pero el deseo sigue quemando en mi corazón muerto, $n.$B$BDeseo de venganza.', 0);
-- 442 Asalto a la Isla de Fenris
-- https://es.classic.wowhead.com/quest=442
SET @ID := 442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir la presencia de la Plaga en Argénteos, $n. Vuelve a verme cuando tengas alguna prueba de la muerte de Thule.', 0),
(@ID, 'esMX', 'No podemos permitir la presencia de la Plaga en Argénteos, $n. Vuelve a verme cuando tengas alguna prueba de la muerte de Thule.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte de Thule Corvozarpa fue un gran golpe, $n. Renferrel me dice que las energías que se liberaron cuando destruiste a Thule, se sintieron incluso en El Sepulcro.$B$BTus acciones resuenan en las filas de los Renegados. Tu valía crece ente nosotros.', 0),
(@ID, 'esMX', 'La muerte de Thule Corvozarpa fue un gran golpe, $n. Renferrel me dice que las energías que se liberaron cuando destruiste a Thule, se sintieron incluso en El Sepulcro.$B$BTus acciones resuenan en las filas de los Renegados. Tu valía crece ente nosotros.', 0);
-- 443 Icor de Putrepellejo
-- https://es.classic.wowhead.com/quest=443
SET @ID := 443;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el icor de Putrepellejo, $n?', 0),
(@ID, 'esMX', '¿Tienes el icor de Putrepellejo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Este icor nos ayudará a entender la naturaleza de los Putrepellejo y quizás nos descubra sus debilidades...$B$B... si es que tienen alguna.', 0),
(@ID, 'esMX', 'Muy bien. Este icor nos ayudará a entender la naturaleza de los Putrepellejo y quizás nos descubra sus debilidades...$B$B... si es que tienen alguna.', 0);
-- 444 El origen de los Putrepellejos
-- https://es.classic.wowhead.com/quest=444
SET @ID := 444;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito una gran concentración para mis estudios. Espero que tu visita no sea frívola.', 0),
(@ID, 'esMX', 'Necesito una gran concentración para mis estudios. Espero que tu visita no sea frívola.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta sustancia está mezclada con poderosos hechizos, algunos de ellos no los había visto en mucho tiempo...$B$BUn momento, debo convocar un hechizo de adivinación...', 0),
(@ID, 'esMX', 'Esta sustancia está mezclada con poderosos hechizos, algunos de ellos no los había visto en mucho tiempo...$B$BUn momento, debo convocar un hechizo de adivinación...', 0);
-- 445 Entrega a Bosque de Argénteos
-- https://es.classic.wowhead.com/quest=445
SET @ID := 445;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae ante mí, $c?', 0),
(@ID, 'esMX', '¿Qué te trae ante mí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué bien que el boticario Johaan haya enviado los resultados de su investigación. Con tantas innovaciones aquí en el Bosque de Argénteos, casi me había olvidado de los hallazgos que llegan de Lordaeron y Claros de Tirisfal. ¡Ah! Esto me recuerda que tengo que hacer llegar estas muestras a Necrópolis lo antes posible.$B$BVaya, ya me he ido por las ramas, perdona... Prolonga tu estancia en el Bosque de Argénteos, $n. Sería muy útil tener a un $c en tan buena forma como tú por aquí.', 0),
(@ID, 'esMX', '¡Qué bien que el boticario Johaan haya enviado los resultados de su investigación. Con tantas innovaciones aquí en el Bosque de Argénteos, casi me había olvidado de los hallazgos que llegan de Lordaeron y Claros de Tirisfal. ¡Ah! Esto me recuerda que tengo que hacer llegar estas muestras a Necrópolis lo antes posible.$B$BVaya, ya me he ido por las ramas, perdona... Prolonga tu estancia en el Bosque de Argénteos, $n. Sería muy útil tener a un $c en tan buena forma como tú por aquí.', 0);
-- 446 Thule Corvozarpa
-- https://es.classic.wowhead.com/quest=446
SET @ID := 446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué te ha dicho Bethor?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué te ha dicho Bethor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pergamino está imbuido de poderosa magia. Nunca he usado fuerzas así en una poción... será una mezcla muy poderosa y debería servirte si atacas a Thule en su fortaleza de la Isla de Fenris.', 0),
(@ID, 'esMX', 'Este pergamino está imbuido de poderosa magia. Nunca he usado fuerzas así en una poción... será una mezcla muy poderosa y debería servirte si atacas a Thule en su fortaleza de la Isla de Fenris.', 0);
-- 447 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=447
SET @ID := 447;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Qué te trae a hablar con la Sociedad Real de Boticarios?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Qué te trae a hablar con la Sociedad Real de Boticarios?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué amable por parte del boticario Renferrel haberte enviado, $n. Estas muestras serán sin duda útiles para nuestra causa. Comenzaré a estudiar sus propiedades tóxicas y contaminantes ahora mismo.', 0),
(@ID, 'esMX', 'Qué amable por parte del boticario Renferrel haberte enviado, $n. Estas muestras serán sin duda útiles para nuestra causa. Comenzaré a estudiar sus propiedades tóxicas y contaminantes ahora mismo.', 0);
-- 448 Preséntate ante Hadrec
-- https://es.classic.wowhead.com/quest=448
SET @ID := 448;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si lo que Bethor dice es cierto, hay que encargarse rápidamente de Thule Corvozarpa.$B$BPara ayudarte, puedes coger algo de nuestro arsenal...', 0),
(@ID, 'esMX', 'Si lo que Bethor dice es cierto, hay que encargarse rápidamente de Thule Corvozarpa.$B$BPara ayudarte, puedes coger algo de nuestro arsenal...', 0);
-- 449 El informe de los Mortacechadores
-- https://es.classic.wowhead.com/quest=449
SET @ID := 449;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto lo que ha pasado con los Mortacechadores?', 0),
(@ID, 'esMX', '¿Has descubierto lo que ha pasado con los Mortacechadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No había contado con el nivel de presencia de la Plaga que vimos en el Bosque de Argénteos, ni con los problemas que nuestros Mortacechadores tuvieron en sus misiones de exploración.$B$BTu ayuda a nuestros Mortacechadores ha sido inapreciable, $n. Y te recomendaré.', 0),
(@ID, 'esMX', 'No había contado con el nivel de presencia de la Plaga que vimos en el Bosque de Argénteos, ni con los problemas que nuestros Mortacechadores tuvieron en sus misiones de exploración.$B$BTu ayuda a nuestros Mortacechadores ha sido inapreciable, $n. Y te recomendaré.', 0);
-- 450 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=450
SET @ID := 450;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has regresado, $n.', 0),
(@ID, 'esMX', 'Veo que has regresado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El Diario del boticario Berard! Eres muy valiente, $n. Ahora veamos lo que estaba haciendo Berard antes de volverse loco...', 0),
(@ID, 'esMX', '¡El Diario del boticario Berard! Eres muy valiente, $n. Ahora veamos lo que estaba haciendo Berard antes de volverse loco...', 0);
-- 451 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=451
SET @ID := 451;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae de nuevo a Entrañas, $n?', 0),
(@ID, 'esMX', '¿Qué te trae de nuevo a Entrañas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perder a Berard ha sido un duro golpe para la Sociedad Real de Boticarios. Pero gracias a lo que has hecho y a la diligente investigación del boticario Renferrel, los estudios de Berard serán de mucha utilidad para la Dama Oscura.$B$BEstamos a punto de conseguir algo grande, $n. Si no tuvieras tanto talento para el combate, intentaría reclutarte para la Sociedad.', 0),
(@ID, 'esMX', 'Perder a Berard ha sido un duro golpe para la Sociedad Real de Boticarios. Pero gracias a lo que has hecho y a la diligente investigación del boticario Renferrel, los estudios de Berard serán de mucha utilidad para la Dama Oscura.$B$BEstamos a punto de conseguir algo grande, $n. Si no tuvieras tanto talento para el combate, intentaría reclutarte para la Sociedad.', 0);
-- 452 La emboscada de Aldea Piroleña
-- https://es.classic.wowhead.com/quest=452
SET @ID := 452;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Luchas como un verdadero discípulo de la Dama Oscura, $n. Con la destrucción del Consejo, quizás podamos conseguir el control de esta ciudad de una vez por todas y expulsar a Arugal del Castillo de Colmillo Oscuro. ¡Te aplaudo!', 0),
(@ID, 'esMX', 'Luchas como un verdadero discípulo de la Dama Oscura, $n. Con la destrucción del Consejo, quizás podamos conseguir el control de esta ciudad de una vez por todas y expulsar a Arugal del Castillo de Colmillo Oscuro. ¡Te aplaudo!', 0);
-- 460 Descansar en piezas
-- https://es.classic.wowhead.com/quest=460
SET @ID := 460;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta tumba se ha cavado a toda prisa.', 0),
(@ID, 'esMX', 'Esta tumba se ha cavado a toda prisa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Temía que los gnolls hubieran destruido mi cuerpo. Me alegra saber que no es así.', 0),
(@ID, 'esMX', 'Gracias, $n. Temía que los gnolls hubieran destruido mi cuerpo. Me alegra saber que no es así.', 0);
-- 461 El nicho oculto
-- https://es.classic.wowhead.com/quest=461
SET @ID := 461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí es! Acércame más...', 0),
(@ID, 'esMX', '¡Aquí es! Acércame más...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí estamos, está abierto. Déjame aquí. Pasé los mejores días de mi vida aquí y el pensamiento de descansar entre sus muros me reconforta.$B$BAsegúrate de cerrar bien el nicho, no quiero que esos Putrepellejos me encuentren.$B$BOh, y acepta esto. Te lo has ganado.', 0),
(@ID, 'esMX', 'Aquí estamos, está abierto. Déjame aquí. Pasé los mejores días de mi vida aquí y el pensamiento de descansar entre sus muros me reconforta.$B$BAsegúrate de cerrar bien el nicho, no quiero que esos Putrepellejos me encuentren.$B$BOh, y acepta esto. Te lo has ganado.', 0);

-- 467 La búsqueda de los Roscapiedra
-- https://es.classic.wowhead.com/quest=467
SET @ID := 467;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, ¿vienes por el trabajito? ¡Me alegro de ver que aún hay gente que se emociona con la idea de una aventura!', 0),
(@ID, 'esMX', 'Hola, $n, ¿vienes por el trabajito? ¡Me alegro de ver que aún hay gente que se emociona con la idea de una aventura!', 0);
-- 477 Pasa la frontera
-- https://es.classic.wowhead.com/quest=477
SET @ID := 477;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Al destapar la caja, encuentras una selección de objetos cuidadosamente empaquetados. En la parte de arriba de la caja hay unos mapas amarillentos por el paso del tiempo, que parecen describir el Bosque de Argénteos y otras partes del oeste de Lordaeron.$B$BBajo los mapas hay un colgante de aspecto misterioso.>', 0),
(@ID, 'esMX', '<Al destapar la caja, encuentras una selección de objetos cuidadosamente empaquetados. En la parte de arriba de la caja hay unos mapas amarillentos por el paso del tiempo, que parecen describir el Bosque de Argénteos y otras partes del oeste de Lordaeron.$B$BBajo los mapas hay un colgante de aspecto misterioso.>', 0);
-- 478 Mapas y runas
-- https://es.classic.wowhead.com/quest=478
SET @ID := 478;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has aprendido algo útil, $n?', 0),
(@ID, 'esMX', '¿Has aprendido algo útil, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mapas y este... colgante, ¿mmm? Interesante.$B$BEs obvio que los zahoríes de Dalaran están interesados en Molino Ámbar por alguna razón, pero aun así, no llego a entender el motivo.$B$BQuizás Dalar sepa algo.', 0),
(@ID, 'esMX', 'Mapas y este... colgante, ¿mmm? Interesante.$B$BEs obvio que los zahoríes de Dalaran están interesados en Molino Ámbar por alguna razón, pero aun así, no llego a entender el motivo.$B$BQuizás Dalar sepa algo.', 0);
-- 479 Las investigaciones de Molino Ámbar
-- https://es.classic.wowhead.com/quest=479
SET @ID := 479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos darnos prisa, no podemos permitir que lleven a cabo su plan, o podríamos perder nuestra posición en el Bosque de Argénteos.', 0),
(@ID, 'esMX', 'Debemos darnos prisa, no podemos permitir que lleven a cabo su plan, o podríamos perder nuestra posición en el Bosque de Argénteos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dalar ha descubierto que han avanzado bastante a pesar del revés.$B$BTienen a un zahorí de gran poder guiando la energía mágica. Tenemos que detenerle rápidamente.', 0),
(@ID, 'esMX', 'Dalar ha descubierto que han avanzado bastante a pesar del revés.$B$BTienen a un zahorí de gran poder guiando la energía mágica. Tenemos que detenerle rápidamente.', 0);
-- 480 El Tejedor
-- https://es.classic.wowhead.com/quest=480
SET @ID := 480;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rápido, nos quedamos sin tiempo, $n!', 0),
(@ID, 'esMX', '¡Rápido, nos quedamos sin tiempo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La magia de los zahoríes se disipa y las energías Ley entran en letargo. Tus esfuerzos han dado fruto, $n, y hemos causado un duro golpe a nuestros enemigos y a los dominantes zahoríes de Dalaran.$B$BSin embargo, debemos ser vigilantes ya que sabemos que la fuente de la energía está tan cerca... Tenemos que hacer planes para el futuro.', 0),
(@ID, 'esMX', 'La magia de los zahoríes se disipa y las energías Ley entran en letargo. Tus esfuerzos han dado fruto, $n, y hemos causado un duro golpe a nuestros enemigos y a los dominantes zahoríes de Dalaran.$B$BSin embargo, debemos ser vigilantes ya que sabemos que la fuente de la energía está tan cerca... Tenemos que hacer planes para el futuro.', 0);
-- 481 El análisis de Dalar
-- https://es.classic.wowhead.com/quest=481
SET @ID := 481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $c? ¿Qué quieres?', 0),
(@ID, 'esMX', '¿Sí, $c? ¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante, parece que se trata de más maquinaciones del Kirin Tor. Se trata de un poderoso artefacto. Los poderosos zahoríes del Kirin Tor lo utilizaban frecuentemente para canalizar las energías mágicas.$B$BQue estén enviando tantos a Molino Ámbar indica que deben de estar preparando un proyecto de gran magnitud.$B$BA ver si consigo atravesar sus escudos y frustrar su intento...', 0),
(@ID, 'esMX', 'Interesante, parece que se trata de más maquinaciones del Kirin Tor. Se trata de un poderoso artefacto. Los poderosos zahoríes del Kirin Tor lo utilizaban frecuentemente para canalizar las energías mágicas.$B$BQue estén enviando tantos a Molino Ámbar indica que deben de estar preparando un proyecto de gran magnitud.$B$BA ver si consigo atravesar sus escudos y frustrar su intento...', 0);
-- 482 Las intenciones de los Dalaran
-- https://es.classic.wowhead.com/quest=482
SET @ID := 482;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Traes nefastas noticias, $n. Si Dalar tiene razón, y no me cabe duda de que así es, debemos movernos rápidamente.$B$BTengo que decidir con él nuestro plan de ataque. Pero, mientras tanto, tendremos que retrasar su avance.', 0),
(@ID, 'esMX', 'Traes nefastas noticias, $n. Si Dalar tiene razón, y no me cabe duda de que así es, debemos movernos rápidamente.$B$BTengo que decidir con él nuestro plan de ataque. Pero, mientras tanto, tendremos que retrasar su avance.', 0);
-- 485 ¡Encuentra a OOX-09/TI!
-- https://es.classic.wowhead.com/quest=485
SET @ID := 485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0),
(@ID, 'esMX', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo... localizador de emergencia... dentro del pollo... el robot mensajero.$B$BDentro se oyen zumbidos y chirridos. Cuando el robot es revivido, se vuelve a oír la voz de Oglethorpe una vez más, pero ahora, viene de dentro del robot:$B$B"OOX-09/TI funciona, pero necesita reparaciones. Es demasiado pesado para llevarlo, pero tengo una idea. ¿Puedes vigilarlo un rato más?"', 0),
(@ID, 'esMX', 'Colocas el huevo... localizador de emergencia... dentro del pollo... el robot mensajero.$B$BDentro se oyen zumbidos y chirridos. Cuando el robot es revivido, se vuelve a oír la voz de Oglethorpe una vez más, pero ahora, viene de dentro del robot:$B$B"OOX-09/TI funciona, pero necesita reparaciones. Es demasiado pesado para llevarlo, pero tengo una idea. ¿Puedes vigilarlo un rato más?"', 0);
-- 491 Una varita para Bethor
-- https://es.classic.wowhead.com/quest=491
SET @ID := 491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has derrotado a Thule Corvozarpa?', 0),
(@ID, 'esMX', '$n, ¿has derrotado a Thule Corvozarpa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Thule tenía nuestra varita tejida? Creí que la había perdido cuando nuestra amistad se destruyó y se alió con el rey Exánime.$B$BNo ha invocado su poder porque, si lo hubiera hecho, yo lo habría sentido. Y me alegro de que no la haya usado...$B$BEs un descubrimiento maravilloso. Tienes mi gratitud, $n, y recibirás una recompensa.', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Thule tenía nuestra varita tejida? Creí que la había perdido cuando nuestra amistad se destruyó y se alió con el rey Exánime.$B$BNo ha invocado su poder porque, si lo hubiera hecho, yo lo habría sentido. Y me alegro de que no la haya usado...$B$BEs un descubrimiento maravilloso. Tienes mi gratitud, $n, y recibirás una recompensa.', 0);
-- 492 Una nueva Peste
-- https://es.classic.wowhead.com/quest=492
SET @ID := 492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tuviera mi rifle acabaría contigo, $c. ¡Espera a que la Brigada de los tanques de vapor me saque de aquí!', 0),
(@ID, 'esMX', 'Si tuviera mi rifle acabaría contigo, $c. ¡Espera a que la Brigada de los tanques de vapor me saque de aquí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, por fin algo que beber! Estoy seguro de que no es malta rapsódica pero en este momento mojaría el gaznate con cualquier cosa.', 0),
(@ID, 'esMX', '¡Ah, por fin algo que beber! Estoy seguro de que no es malta rapsódica pero en este momento mojaría el gaznate con cualquier cosa.', 0);
-- 493 Viaja a Laderas de Trabalomas
-- https://es.classic.wowhead.com/quest=493
SET @ID := 493;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, excelente! El boticario Renferrel se merece todo mi respeto. Me muero por estudiar su obra.', 0),
(@ID, 'esMX', '¡Excelente, excelente! El boticario Renferrel se merece todo mi respeto. Me muero por estudiar su obra.', 0);
-- 494 El momento de atacar
-- https://es.classic.wowhead.com/quest=494
SET @ID := 494;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Desde el oeste nos llega el llanto del cuervo."$B$B¡Qué noticia tan excelente! Todo está a punto para arrasar Trabalomas. Esto complacerá a Varimathras.', 0),
(@ID, 'esMX', '"Desde el oeste nos llega el llanto del cuervo."$B$B¡Qué noticia tan excelente! Todo está a punto para arrasar Trabalomas. Esto complacerá a Varimathras.', 0);
-- 495 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=495
SET @ID := 495;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Shalindra? Muy bien, pues vayamos al grano.$B$BMug\'Thol es un estorbo así que debemos ocuparnos de él sin perder ni un segundo.', 0),
(@ID, 'esMX', '¿Te envía Shalindra? Muy bien, pues vayamos al grano.$B$BMug\'Thol es un estorbo así que debemos ocuparnos de él sin perder ni un segundo.', 0);
-- 496 Elixir de sufrimiento
-- https://es.classic.wowhead.com/quest=496
SET @ID := 496;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ya estás aquí. Espero que traigas los ingredientes; me deprimo si paso más de un día sin matar nada.', 0),
(@ID, 'esMX', 'Ah, ya estás aquí. Espero que traigas los ingredientes; me deprimo si paso más de un día sin matar nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, perfecto. Gracias por arrojar un tenue rayo de alegría a otro día sombrío.', 0),
(@ID, 'esMX', 'Muy bien, perfecto. Gracias por arrojar un tenue rayo de alegría a otro día sombrío.', 0);
-- 1000 La nueva frontera
-- https://es.classic.wowhead.com/quest=1000
SET @ID := 1000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0);
-- 990 El camino de Vallefresno
-- https://es.classic.wowhead.com/quest=990
SET @ID := 990;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $gun:una; $c de Costa Oscura. Selarin ha hecho bien en enviarte tan rápidamente, $n. Ojalá tu viaje aquí no se debiera a tan funesta urgencia. Quizás con tu ayuda logremos mejorar la situación.$B$BEmpezaría mi visita hablando con otros ciudadanos de Astranaar. Seguro que alguno te puede ayudar.', 0),
(@ID, 'esMX', 'Ah, $gun:una; $c de Costa Oscura. Selarin ha hecho bien en enviarte tan rápidamente, $n. Ojalá tu viaje aquí no se debiera a tan funesta urgencia. Quizás con tu ayuda logremos mejorar la situación.$B$BEmpezaría mi visita hablando con otros ciudadanos de Astranaar. Seguro que alguno te puede ayudar.', 0);
-- 1004 La nueva frontera
-- https://es.classic.wowhead.com/quest=1004
SET @ID := 1004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0);
-- 1011 Los males de los Renegados
-- https://es.classic.wowhead.com/quest=1011
SET @ID := 1011;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el campamento, $n? ¿Tienes una botella de enfermedad?', 0),
(@ID, 'esMX', '¿Encontraste el campamento, $n? ¿Tienes una botella de enfermedad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Ahora... probando el contenido de esta botella, ¡se revelarán los objetivos de los Renegados!', 0),
(@ID, 'esMX', 'Muy bien, $n. Ahora... probando el contenido de esta botella, ¡se revelarán los objetivos de los Renegados!', 0);
-- 1012 Druidas dementes
-- https://es.classic.wowhead.com/quest=1012
SET @ID := 1012;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La angustia de los druidas Dor\'danil todavía acecha mis sueños, $n. ¡Debes destruir a sus líderes!', 0),
(@ID, 'esMX', 'La angustia de los druidas Dor\'danil todavía acecha mis sueños, $n. ¡Debes destruir a sus líderes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sentí que la angustia del Túmulo de Dor\'danil disminuía y supe que habías completado tu tarea.$B$BHas hecho un macabro trabajo, $n, ya que los espíritus que has tenido que destruir eran meras víctimas de la perversión de los Renegados. Pero con su destrucción, esperemos que otros espíritus enloquecidos encuentren el descanso.', 0),
(@ID, 'esMX', 'Sentí que la angustia del Túmulo de Dor\'danil disminuía y supe que habías completado tu tarea.$B$BHas hecho un macabro trabajo, $n, ya que los espíritus que has tenido que destruir eran meras víctimas de la perversión de los Renegados. Pero con su destrucción, esperemos que otros espíritus enloquecidos encuentren el descanso.', 0);
-- 1013 El Libro de Ur
-- https://es.classic.wowhead.com/quest=1013
SET @ID := 1013;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el libro?', 0),
(@ID, 'esMX', '¿Encontraste el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto; esto completa mi colección de obras de Ur. Era sabio, pero su conciencia lo mantenía alejado del poder verdadero. Así, cuando la Plaga lo puso a prueba, falló.$B$BLos Renegados no podemos permitirnos tal debilidad.$B$BNo si queremos vencer.', 0),
(@ID, 'esMX', 'Perfecto; esto completa mi colección de obras de Ur. Era sabio, pero su conciencia lo mantenía alejado del poder verdadero. Así, cuando la Plaga lo puso a prueba, falló.$B$BLos Renegados no podemos permitirnos tal debilidad.$B$BNo si queremos vencer.', 0);
-- 1014 Arugal debe morir
-- https://es.classic.wowhead.com/quest=1014
SET @ID := 1014;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la muerte de Arugal, podemos aumentar el bastión de la Dama Oscura en Lordaeron.', 0),
(@ID, 'esMX', 'Con la muerte de Arugal, podemos aumentar el bastión de la Dama Oscura en Lordaeron.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin el Bosque de Argénteos está libre del vicio de ese malvado Arugal. Has hecho un gran servicio a la Dama Oscura, $n. Tu tenacidad será recompensada.', 0),
(@ID, 'esMX', 'Por fin el Bosque de Argénteos está libre del vicio de ese malvado Arugal. Has hecho un gran servicio a la Dama Oscura, $n. Tu tenacidad será recompensada.', 0);
-- 1015 La nueva frontera
-- https://es.classic.wowhead.com/quest=1015
SET @ID := 1015;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0),
(@ID, 'esMX', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0);
-- 1018 La nueva frontera
-- https://es.classic.wowhead.com/quest=1018
SET @ID := 1018;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas; te doy la bienvenida. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra conexión con el Círculo en Claro de la Luna trasciende las barreras raciales y políticas; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas; te doy la bienvenida. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra conexión con el Círculo en Claro de la Luna trasciende las barreras raciales y políticas; no lo olvides nunca.', 0);
-- 1019 La nueva frontera
-- https://es.classic.wowhead.com/quest=1019
SET @ID := 1019;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0),
(@ID, 'esMX', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0);

-- 1021 ¡Vil sátiro! ¡Dríades en peligro!
-- https://es.classic.wowhead.com/quest=1021
SET @ID := 1021;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A juzgar por la herida abierta en el costado, Anilia está al borde de la muerte.', 0),
(@ID, 'esMX', 'A juzgar por la herida abierta en el costado, Anilia está al borde de la muerte.', 0);
-- 1022 La Vega del Aullido
-- https://es.classic.wowhead.com/quest=1022
SET @ID := 1022;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tomo del santuario es un objeto misterioso. No es un libro en el sentido tradicional. Las hojas del tomo fueron bendecidas por la propia Mel\'Thandris, y registra eventos importantes en sus páginas.$B$BMe cuesta explicarlo. Si vas al santuario, lo entenderás.', 0),
(@ID, 'esMX', 'El tomo del santuario es un objeto misterioso. No es un libro en el sentido tradicional. Las hojas del tomo fueron bendecidas por la propia Mel\'Thandris, y registra eventos importantes en sus páginas.$B$BMe cuesta explicarlo. Si vas al santuario, lo entenderás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Libro de Mel\'Thandris funciona de extraña manera. Los acontecimientos que registra, los que muestra... Nadie entiende realmente por qué hace lo que hace.$B$BNo obstante, es evidente que lo que la sacerdotisa Cantoestelar recibió, esta Guadaña de Elune, merece algo más de investigación.', 0),
(@ID, 'esMX', 'El Libro de Mel\'Thandris funciona de extraña manera. Los acontecimientos que registra, los que muestra... Nadie entiende realmente por qué hace lo que hace.$B$BNo obstante, es evidente que lo que la sacerdotisa Cantoestelar recibió, esta Guadaña de Elune, merece algo más de investigación.', 0);
-- 1031 La Rama de Cenarius
-- https://es.classic.wowhead.com/quest=1031
SET @ID := 1031;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Los has encontrado? ¿Qué dijo Anilia? ¿Donde esta ella?', 0),
(@ID, 'esMX', '¿Los has encontrado? ¿Qué dijo Anilia? ¿Donde esta ella?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Anilia murió? No... ¡eso no puede ser! Fue ayer cuando estábamos corriendo y jugando juntos en el bosque.$B$BSupongo que esos días se acabaron...', 0),
(@ID, 'esMX', '¿Anilia murió? No... ¡eso no puede ser! Fue ayer cuando estábamos corriendo y jugando juntos en el bosque.$B$BSupongo que esos días se acabaron...', 0);
-- 1032 ¡Muerte a los sátiros!
-- https://es.classic.wowhead.com/quest=1032
SET @ID := 1032;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo ruego, ayúdame a vengar la muerte de Anilia.', 0),
(@ID, 'esMX', 'Te lo ruego, ayúdame a vengar la muerte de Anilia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, amable $r. El espíritu de mi hermana se llena de gozo con tus esfuerzos.', 0),
(@ID, 'esMX', 'Gracias, amable $r. El espíritu de mi hermana se llena de gozo con tus esfuerzos.', 0);
-- 1036 ¡Adelante, pillín!
-- https://es.classic.wowhead.com/quest=1036
SET @ID := 1036;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gQuieto:Quieta; ahí, canalla. He escuchado muchas cosas sobre ti. Bueno, si no eres $gamigo:amiga; de Bahía del Botín, podrías tener un lugar especial con los Bucaneros Velasangre.$B$BArrrrr...', 0),
(@ID, 'esMX', '$gQuieto:Quieta; ahí, canalla. He escuchado muchas cosas sobre ti. Bueno, si no eres $gamigo:amiga; de Bahía del Botín, podrías tener un lugar especial con los Bucaneros Velasangre.$B$BArrrrr...', 0);
-- 4621 ¡Adelante, almirante!
-- https://es.classic.wowhead.com/quest=4621
SET @ID := 4621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya volviste, maldito alquitrán! ¿Has hecho lo que te he ordenado? Si nos fallas, estarás caminando por la tabla.$B$BArrrrr...', 0),
(@ID, 'esMX', '¡Ya volviste, maldito alquitrán! ¿Has hecho lo que te he ordenado? Si nos fallas, estarás caminando por la tabla.$B$BArrrrr...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alto ahí, almirante $n! ¡Eres un pirata de piratas, $gmuchacho:muchacha;!$B$BMe alegra el corazón darte este sombrero. ¡Nunca encontrarás uno igual en ninguna parte, y todos los que te miran verán que eres un almirante de la Armada Velasangre!', 0),
(@ID, 'esMX', '¡Alto ahí, almirante $n! ¡Eres un pirata de piratas, $gmuchacho:muchacha;!$B$BMe alegra el corazón darte este sombrero. ¡Nunca encontrarás uno igual en ninguna parte, y todos los que te miran verán que eres un almirante de la Armada Velasangre!', 0);
-- 1037 Velinde Cantoestelar
-- https://es.classic.wowhead.com/quest=1037
SET @ID := 1037;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Velinde Cantoestelar? Que la sacerdotisa lleva algún tiempo desaparecida no es ningún secreto. Pero en cuanto a más detalles sobre los acontecimientos que rodearon su partida... haría falta una razón de peso para divulgar tal información.', 0),
(@ID, 'esMX', '¿Velinde Cantoestelar? Que la sacerdotisa lleva algún tiempo desaparecida no es ningún secreto. Pero en cuanto a más detalles sobre los acontecimientos que rodearon su partida... haría falta una razón de peso para divulgar tal información.', 0);
-- 1038 Las pertenencias de Velinde
-- https://es.classic.wowhead.com/quest=1038
SET @ID := 1038;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que la desaparición de Velinde es aún más preocupante de lo que parecía en un principio. Aún así, no quiero pensar que haya tenido un mal final. Quizás nos beneficiaría contactar con ella.$B$B$n, como has demostrado tu interés en este asunto, quisiera pedirte tu ayuda.', 0),
(@ID, 'esMX', 'Parece que la desaparición de Velinde es aún más preocupante de lo que parecía en un principio. Aún así, no quiero pensar que haya tenido un mal final. Quizás nos beneficiaría contactar con ella.$B$B$n, como has demostrado tu interés en este asunto, quisiera pedirte tu ayuda.', 0);
-- 1039 El puerto de Los Baldíos
-- https://es.classic.wowhead.com/quest=1039
SET @ID := 1039;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$r, ¿eh? He de admitir que no solemos tener a muchos de los tuyos por aquí. Estás buscando a alguien, ¿eh? Dame un momento, seguro que lo tengo escrito en alguno de mis libros.$B$BPero la gente que pasa por aquí es mucha, así que necesito un momento.', 0),
(@ID, 'esMX', '$r, ¿eh? He de admitir que no solemos tener a muchos de los tuyos por aquí. Estás buscando a alguien, ¿eh? Dame un momento, seguro que lo tengo escrito en alguno de mis libros.$B$BPero la gente que pasa por aquí es mucha, así que necesito un momento.', 0);
-- 1040 Pasaje a Bahía del Botín
-- https://es.classic.wowhead.com/quest=1040
SET @ID := 1040;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Vaya, no tienes pinta de traer mercancía para enviar, así que o buscas trabajo en mi caravana, y ahora no hay ninguno, o te has equivocado de goblin.$B$B¿De qué se trata?', 0),
(@ID, 'esMX', '¿Sí? Vaya, no tienes pinta de traer mercancía para enviar, así que o buscas trabajo en mi caravana, y ahora no hay ninguno, o te has equivocado de goblin.$B$B¿De qué se trata?', 0);
-- 8330 Las posesiones de Solanian
-- https://es.classic.wowhead.com/quest=8330
SET @ID := 8330;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido la oportunidad de encontrar mis pertenencias? Una vez que reafirmemos nuestro dominio sobre la Isla del Caminante, te necesitaré en mi trabajo. Por ahora, sin embargo, debo vigilar la Fuente del Sol... o lo que queda de ella.', 0),
(@ID, 'esMX', '¿Has tenido la oportunidad de encontrar mis pertenencias? Una vez que reafirmemos nuestro dominio sobre la Isla del Caminante, te necesitaré en mi trabajo. Por ahora, sin embargo, debo vigilar la Fuente del Sol... o lo que queda de ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, sabía que serías $gperfecto:perfecta; para la tarea. Una vez que sea seguro hacer uso de nuestras instalaciones al aire libre en la isla, haré un buen uso de estas cosas.$B$BComo mencioné, siéntete libre de quedarte con la cartera. Además, esta pieza de equipo puede resultarte útil. ¡Considérelo una amplia compensación por una simple tarea realizada con diligencia!', 0),
(@ID, 'esMX', 'Bien hecho, sabía que serías $gperfecto:perfecta; para la tarea. Una vez que sea seguro hacer uso de nuestras instalaciones al aire libre en la isla, haré un buen uso de estas cosas.$B$BComo mencioné, siéntete libre de quedarte con la cartera. Además, esta pieza de equipo puede resultarte útil. ¡Considérelo una amplia compensación por una simple tarea realizada con diligencia!', 0);
-- 8345 Santuario de Dath'Remar
-- https://es.classic.wowhead.com/quest=8345
SET @ID := 8345;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Placa del Santuario de Dath\'Remar leída', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has leído la placa del santuario, $c?', 0),
(@ID, 'esMX', '¿Has leído la placa del santuario, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, gracias por compartir su experiencia en el Santuario de Dath\'Remar. En primer lugar, debes ser $gfelicitado:felicitada; por tu sentido del deber y respeto; te será de gran utilidad no solo aquí, sino también en todo Azeroth.$B$BEn cuanto a la extraña sensación, sin duda es una parte que contribuye a la mancha que ha caído sobre la Isla del Caminante. Lo vigilaremos; ¡Gracias por avisarnos!', 0),
(@ID, 'esMX', 'Ah, $n, gracias por compartir su experiencia en el Santuario de Dath\'Remar. En primer lugar, debes ser $gfelicitado:felicitada; por tu sentido del deber y respeto; te será de gran utilidad no solo aquí, sino también en todo Azeroth.$B$BEn cuanto a la extraña sensación, sin duda es una parte que contribuye a la mancha que ha caído sobre la Isla del Caminante. Lo vigilaremos; ¡Gracias por avisarnos!', 0);
-- 8334 Agresividad
-- https://es.classic.wowhead.com/quest=8334
SET @ID := 8334;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es mejor que aprendas sobre la supervivencia, y los costos de la supervivencia, ahora que después. Tomar decisiones difíciles es algo a lo que tendrás que acostumbrarte como $r.$B$BNo había nadie allí para nosotros cuando la Plaga partió nuestras casas en dos. Fuimos nosotros y solo nosotros los que nos levantamos con esfuerzo.', 0),
(@ID, 'esMX', 'Es mejor que aprendas sobre la supervivencia, y los costos de la supervivencia, ahora que después. Tomar decisiones difíciles es algo a lo que tendrás que acostumbrarte como $r.$B$BNo había nadie allí para nosotros cuando la Plaga partió nuestras casas en dos. Fuimos nosotros y solo nosotros los que nos levantamos con esfuerzo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me alegro en absoluto de la muerte de los tiernos, pero demuestra que estás a punto para tu tarea más importante en la Isla del Caminante del Sol. Toma esto y úsalo bien; necesitarás objetos de calidad y tener la mente despierta para la misión que te espera. De ella depende que recuperemos el control de la isla.', 0),
(@ID, 'esMX', 'No me alegro en absoluto de la muerte de los tiernos, pero demuestra que estás a punto para tu tarea más importante en la Isla del Caminante del Sol. Toma esto y úsalo bien; necesitarás objetos de calidad y tener la mente despierta para la misión que te espera. De ella depende que recuperemos el control de la isla.', 0);
-- 8335 Felendren el Desterrado
-- https://es.wowhead.com/quest=8335
SET @ID := 8335;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Óyeme bien: Felendren el Desterrado no es sino el síntoma de un problema mucho mayor. Su muerte resolverá los problemas inmediatos, pero todos los elfos de sangre estamos expuestos a sufrir su mismo destino si nos dejamos dominar por nuestras adicciones.', 0),
(@ID, 'esMX', 'Óyeme bien: Felendren el Desterrado no es sino el síntoma de un problema mucho mayor. Su muerte resolverá los problemas inmediatos, pero todos los elfos de sangre estamos expuestos a sufrir su mismo destino si nos dejamos dominar por nuestras adicciones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cabeza de Felendren... Acabas de ganarte una mención honorífica, $n. Has tenido éxito donde otros, como el propio Felendren, han fallado miserablemente. Puede que haya llegado el momento de convertirte en miembro de la sociedad de los elfos de sangre.$B$BEsta cabeza significa que eres capaz de sobrevivir a los mayores peligros de Canción Eterna... Y créeme, son muchos.', 0),
(@ID, 'esMX', 'La cabeza de Felendren... Acabas de ganarte una mención honorífica, $n. Has tenido éxito donde otros, como el propio Felendren, han fallado miserablemente. Puede que haya llegado el momento de convertirte en miembro de la sociedad de los elfos de sangre.$B$BEsta cabeza significa que eres capaz de sobrevivir a los mayores peligros de Canción Eterna... Y créeme, son muchos.', 0);
-- 8338 Esquirla arcana mácula
-- https://es.classic.wowhead.com/quest=8338
SET @ID := 8338;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por tu actitud, diría que vienes por un asunto de cierta urgencia. ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Por tu actitud, diría que vienes por un asunto de cierta urgencia. ¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy interesante, y con eso quiero decir que es más inquietante que otra cosa.$B$BRecuperar el control de la isla tras la destrucción de La Fuente del Sol ha sido todo un desafío. Sospecho que lo que sea que está corrompiendo la isla se encuentra en el corazón de la misma; esta esquirla puede ayudarnos a descubrir qué está pasando.$B$BHas hecho muy bien en traérmela, $n. Acepta esto como pago de tu diligencia. Gracias.', 0),
(@ID, 'esMX', 'Esto es muy interesante, y con eso quiero decir que es más inquietante que otra cosa.$B$BRecuperar el control de la isla tras la destrucción de La Fuente del Sol ha sido todo un desafío. Sospecho que lo que sea que está corrompiendo la isla se encuentra en el corazón de la misma; esta esquirla puede ayudarnos a descubrir qué está pasando.$B$BHas hecho muy bien en traérmela, $n. Acepta esto como pago de tu diligencia. Gracias.', 0);
-- 8347 Ayudando a los avanzados
-- https://es.classic.wowhead.com/quest=8347
SET @ID := 8347;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos, $c! Había oído que $gun:una; joven $r que estuvo al servicio de la magistrix Erona iba a venir para echarnos una mano a los avanzados. Agradecemos la ayuda, sobre todo si es de alguien que ha demostrado ser tan competente como tú.$B$BTengo un par de cosas que encargarte.', 0),
(@ID, 'esMX', '¡Saludos, $c! Había oído que $gun:una; joven $r que estuvo al servicio de la magistrix Erona iba a venir para echarnos una mano a los avanzados. Agradecemos la ayuda, sobre todo si es de alguien que ha demostrado ser tan competente como tú.$B$BTengo un par de cosas que encargarte.', 0);
-- 9704 Ejecutados por los desdichados
-- https://es.wowhead.com/quest=9704
SET @ID := 9704;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Robaron todas las pertenencias de la avanzada salvo un paquete. Parece coincidir con la descripción que Alarion dio del paquete de Erona.', 0),
(@ID, 'esMX', 'Robaron todas las pertenencias de la avanzada salvo un paquete. Parece coincidir con la descripción que Alarion dio del paquete de Erona.', 0);
-- 9705 Recuperación de paquete
-- https://es.wowhead.com/quest=9705
SET @ID := 9705;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por La Fuente del Sol! Es el tercer avanzado que perdemos este mes.$B$BAgradezco tu valor al adentrarte en la Calle del Alba. Los guardias necesitan mantener una vigilancia estrecha sobre esos malditos desdichados.', 0),
(@ID, 'esMX', '¡Por La Fuente del Sol! Es el tercer avanzado que perdemos este mes.$B$BAgradezco tu valor al adentrarte en la Calle del Alba. Los guardias necesitan mantener una vigilancia estrecha sobre esos malditos desdichados.', 0);
-- 8350 El encargo
-- https://es.classic.wowhead.com/quest=8350
SET @ID := 8350;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido a mi posada, $c. ¿Vienes a traerme algo?', 0),
(@ID, 'esMX', 'Bienvenido a mi posada, $c. ¿Vienes a traerme algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por entregar esto tan rápidamente.$B$BPonte $gcómodo:cómoda; mientras estás aquí. Si no lo has hecho ya, coge una piedra de hogar y vincúlate a esta posada. La piedra te permite volver a una posada una vez cada media hora. Si pierdes la piedra, no tienes más que volver a una posada; el tabernero te dará otra piedra de hogar gustosamente.', 0),
(@ID, 'esMX', 'Gracias por entregar esto tan rápidamente.$B$BPonte $gcómodo:cómoda; mientras estás aquí. Si no lo has hecho ya, coge una piedra de hogar y vincúlate a esta posada. La piedra te permite volver a una posada una vez cada media hora. Si pierdes la piedra, no tienes más que volver a una posada; el tabernero te dará otra piedra de hogar gustosamente.', 0);
-- 8472 Avería grave
-- https://es.classic.wowhead.com/quest=8472
SET @ID := 8472;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido reunir los núcleos arcanos, $n?', 0),
(@ID, 'esMX', '¿Has conseguido reunir los núcleos arcanos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Ahora que nuestros sagrarios arcanos solo están activos parcialmente, estos núcleos de poder nos van a ser muy útiles.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Ahora que nuestros sagrarios arcanos solo están activos parcialmente, estos núcleos de poder nos van a ser muy útiles.', 0);
-- 8463 Cristales de maná inestables
-- https://es.classic.wowhead.com/quest=8463
SET @ID := 8463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los cristales robados?', 0),
(@ID, 'esMX', '¿Traes los cristales robados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n.', 0);
-- 8468 Se busca: Thaelis el Hambriento
-- https://es.classic.wowhead.com/quest=8468
SET @ID := 8468;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El canalla de Thaelis ha recibido su merecido por fin. Buen trabajo, $n. Esperemos que los desdichados estén tranquilitos una temporada.', 0),
(@ID, 'esMX', 'El canalla de Thaelis ha recibido su merecido por fin. Buen trabajo, $n. Esperemos que los desdichados estén tranquilitos una temporada.', 0);
-- 8895 Entrega para el Sagrario del Norte
-- https://es.classic.wowhead.com/quest=8895
SET @ID := 8895;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $c?', 0),
(@ID, 'esMX', '¿Sí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esperaba esta carta.', 0),
(@ID, 'esMX', 'Gracias, $n. Esperaba esta carta.', 0);

-- 9352 Intrusiones darnassianas
-- https://es.classic.wowhead.com/quest=9352
SET @ID := 9352;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Intruso derrotado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto algo? ¿Están los elfos de la noche detrás de esto?', 0),
(@ID, 'esMX', '¿Has descubierto algo? ¿Están los elfos de la noche detrás de esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Elfos de la noche? ¿Aquí? ¡Esas ratas!$B$B¿Crees que tienen algo que ver con la disfunción de mi sagrario? Si tienes cualquier información, ¡será mejor que se la lleves enseguida al capitán Marcasol!', 0),
(@ID, 'esMX', '¿Elfos de la noche? ¿Aquí? ¡Esas ratas!$B$B¿Crees que tienen algo que ver con la disfunción de mi sagrario? Si tienes cualquier información, ¡será mejor que se la lleves enseguida al capitán Marcasol!', 0);
-- 9119 Disfunción en el Sagrario del Oeste
-- https://es.classic.wowhead.com/quest=9119
SET @ID := 9119;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira a tu alrededor. Las cosas no están exactamente en orden.$B$BPor lo visto hay una grave disfunción en el Sagrario del Oeste. Hagamos todo lo posible para evitar que empeoren.', 0),
(@ID, 'esMX', 'Mira a tu alrededor. Las cosas no están exactamente en orden.$B$BPor lo visto hay una grave disfunción en el Sagrario del Oeste. Hagamos todo lo posible para evitar que empeoren.', 0);
-- 9035 Asaltantes de caminos
-- https://es.wowhead.com/quest=9035
SET @ID := 9035;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Han huido. ¡Casi los mato de miedo con una bola de Fuego bien colocada! Por desgracia, han tirado nuestra preciada carga al río.', 0),
(@ID, 'esMX', 'Han huido. ¡Casi los mato de miedo con una bola de Fuego bien colocada! Por desgracia, han tirado nuestra preciada carga al río.', 0);
-- 9062 Papel mojado
-- https://es.wowhead.com/quest=9062
-- https://es.classic.wowhead.com/quest=9062
SET @ID := 9062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué, ¿no ha habido suerte? Sigue buscando; ese libro es importantísimo, $c.', 0),
(@ID, 'esMX', 'Qué, ¿no ha habido suerte? Sigue buscando; ese libro es importantísimo, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El libro está completamente empapado. El instructor Antheol no va a estar nada contento.$B$BTen, toma estas monedas. Tengo una idea.', 0),
(@ID, 'esMX', 'El libro está completamente empapado. El instructor Antheol no va a estar nada contento.$B$BTen, toma estas monedas. Tengo una idea.', 0);
-- 9064 Asumiendo la responsabilidad
-- https://es.wowhead.com/quest=9064
SET @ID := 9064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te atreves a interrumpirme, $c?', 0),
(@ID, 'esMX', '¿Cómo te atreves a interrumpirme, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que esos dos incompetentes te sobornaron para que me mintieras? Has hecho bien en decírmelo, $n.', 0),
(@ID, 'esMX', '¿Que esos dos incompetentes te sobornaron para que me mintieras? Has hecho bien en decírmelo, $n.', 0);
-- 9066 La letra con sangre entra
-- https://es.wowhead.com/quest=9066
SET @ID := 9066;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Aprendiz Meledor castigado', `ObjectiveText2` = 'Aprendiz Ralen castigado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te he pedido, $n?', 0),
(@ID, 'esMX', '¿Has hecho lo que te he pedido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. No te preocupes, no se quedarán con esa forma. Sin embargo, no recuperarán su aprendizaje hasta que se lo ganen.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. No te preocupes, no se quedarán con esa forma. Sin embargo, no recuperarán su aprendizaje hasta que se lo ganen.', 0);
-- 8486 Inestabilidad arcana
-- https://es.wowhead.com/quest=8486
SET @ID := 8486;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te encargaste de los espectros de maná?', 0),
(@ID, 'esMX', '¿Te encargaste de los espectros de maná?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ahora que las apariciones están controladas podemos enviar a alguien a evaluar los daños. Espero que no sean permanentes.', 0),
(@ID, 'esMX', 'Gracias, $n. Ahora que las apariciones están controladas podemos enviar a alguien a evaluar los daños. Espero que no sean permanentes.', 0);
-- 8482 Documentos incriminadores
-- https://es.wowhead.com/quest=8482
SET @ID := 8482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué traes? Déjame ver.', 0),
(@ID, 'esMX', '¿Qué traes? Déjame ver.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que estos documentos los tenía un elfo de la noche? Están en enano...$B$BPor lo que entiendo de la carta, quien escribió esto no es responsable de la avería, sino que más bien vino a espiar para observar sus resultados. Dicen que nuestros esfuerzos son inconscientes y peligrosos... Pero ¿quién?$B$B¡Claro, el enviado de Forjaz! ¡Nunca debimos confiar en alguien de la Alianza!', 0),
(@ID, 'esMX', '¿Dices que estos documentos los tenía un elfo de la noche? Están en enano...$B$BPor lo que entiendo de la carta, quien escribió esto no es responsable de la avería, sino que más bien vino a espiar para observar sus resultados. Dicen que nuestros esfuerzos son inconscientes y peligrosos... Pero ¿quién?$B$B¡Claro, el enviado de Forjaz! ¡Nunca debimos confiar en alguien de la Alianza!', 0);
-- 8483 El espía enano
-- https://es.wowhead.com/quest=8483
SET @ID := 8483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ocupaste del intruso?', 0),
(@ID, 'esMX', '¿Te ocupaste del intruso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya veo. Has hecho un buen trabajo.$B$BHemos informado al General Forestal; créeme, esos enanos van a pagar cara su traición.$B$BHoy has rendido un gran servicio a los tuyos, $n.', 0),
(@ID, 'esMX', 'Ya veo. Has hecho un buen trabajo.$B$BHemos informado al General Forestal; créeme, esos enanos van a pagar cara su traición.$B$BHoy has rendido un gran servicio a los tuyos, $n.', 0);
-- 9256 La Aldea Brisa Pura
-- https://es.wowhead.com/quest=9256
SET @ID := 9256;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por venir, $n. Las cosas están peor de lo que habíamos previsto. Los desdichados se han adueñado del Fondeadero Vela del Sol.', 0),
(@ID, 'esMX', 'Gracias por venir, $n. Las cosas están peor de lo que habíamos previsto. Los desdichados se han adueñado del Fondeadero Vela del Sol.', 0);
-- 8475 La Cicatriz Muerta
-- https://es.wowhead.com/quest=8475
SET @ID := 8475;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Ya luchaste contra los muertos vivientes a lo largo de la Cicatriz?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Ya luchaste contra los muertos vivientes a lo largo de la Cicatriz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No creemos que la Plaga vaya a abandonar los ataques en un futuro próximo, pero agradecemos la ayuda para vigilar La Cicatriz.', 0),
(@ID, 'esMX', 'No creemos que la Plaga vaya a abandonar los ataques en un futuro próximo, pero agradecemos la ayuda para vigilar La Cicatriz.', 0);
-- 8491 Caza de pelambres
-- https://es.wowhead.com/quest=8491
SET @ID := 8491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¿Me traes las pelambres?', 0),
(@ID, 'esMX', 'Has vuelto. ¿Me traes las pelambres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n. Ten esta pieza de armadura como recompensa. Voy a poder hacer más gracias a estas pelambres.', 0),
(@ID, 'esMX', 'Perfecto, $n. Ten esta pieza de armadura como recompensa. Voy a poder hacer más gracias a estas pelambres.', 0);
-- 9254 El aprendiz de díscolo
-- https://es.wowhead.com/quest=9254
SET @ID := 9254;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es muy bonito que quien fuera mi mentora se preocupe por mí. Lástima que perdiera la fe en mi investigación hace mucho tiempo.$B$BNo pierdas el tiempo intentando que vuelva junto a ella; elige entre ayudarme en mi investigación o marcharte.', 0),
(@ID, 'esMX', 'Es muy bonito que quien fuera mi mentora se preocupe por mí. Lástima que perdiera la fe en mi investigación hace mucho tiempo.$B$BNo pierdas el tiempo intentando que vuelva junto a ella; elige entre ayudarme en mi investigación o marcharte.', 0);
-- 9395 El Refugio de Saltheril
-- https://es.wowhead.com/quest=9395
SET @ID := 9395;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Magistrix Caminalba se digna responder al fin a mis sencillas peticiones. Debería hablar de su actitud con el Señor regente de Lunargenta. ¡Es bastante maleducada!$B$BAunque nada por lo que debas preocuparte. Ya que estás aquí, ¿quizás podría al fin conseguir esos suministros que estaba esperando para la fiesta?', 0),
(@ID, 'esMX', 'Ah, Magistrix Caminalba se digna responder al fin a mis sencillas peticiones. Debería hablar de su actitud con el Señor regente de Lunargenta. ¡Es bastante maleducada!$B$BAunque nada por lo que debas preocuparte. Ya que estás aquí, ¿quizás podría al fin conseguir esos suministros que estaba esperando para la fiesta?', 0);
-- 9358 La forestal Sareyn
-- https://es.wowhead.com/quest=9358
SET @ID := 9358;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a ayudarnos? ¿Por qué no lo has dicho antes? ¡Siempre nos viene bien que nos echen una mano!', 0),
(@ID, 'esMX', '¿Has venido a ayudarnos? ¿Por qué no lo has dicho antes? ¡Siempre nos viene bien que nos echen una mano!', 0);
-- 9258 La Arboleda Agostada
-- https://es.wowhead.com/quest=9258
SET @ID := 9258;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, te envía mi hermano. Sí que tengo una tarea en la que podrías ayudar.', 0),
(@ID, 'esMX', 'Ah, te envía mi hermano. Sí que tengo una tarea en la que podrías ayudar.', 0);
-- 8892 Problemas en el Fondeadero Vela del Sol
-- https://es.wowhead.com/quest=8892
SET @ID := 8892;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Les enseñaste una lección a esos miserables?', 0),
(@ID, 'esMX', '¿Les enseñaste una lección a esos miserables?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así aprenderán que con nosotros no se juega. Buen trabajo, $n.', 0),
(@ID, 'esMX', 'Así aprenderán que con nosotros no se juega. Buen trabajo, $n.', 0);
-- 9067 Fiesta interminable
-- https://es.wowhead.com/quest=9067
SET @ID := 9067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No te acabo de mandar a buscar provisiones para la fiesta? ¿No eras tú? Bueno, no voy a acordarme de las caras de todo el mundo, ¿no? Conozco a tantos p... Personajes interesantes, quiero decir.$B$B¿Qué quieres?', 0),
(@ID, 'esMX', '¿No te acabo de mandar a buscar provisiones para la fiesta? ¿No eras tú? Bueno, no voy a acordarme de las caras de todo el mundo, ¿no? Conozco a tantos p... Personajes interesantes, quiero decir.$B$B¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres un $ghombre:mujer; bastante enérgico, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0),
(@ID, 'esMX', 'Eres un $ghombre:mujer; bastante enérgico, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0);
-- 8473 Una tarea dolorosa
-- https://es.wowhead.com/quest=8473
SET @ID := 8473;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me da miedo preguntar, $n... ¿está terminada la tarea?', 0),
(@ID, 'esMX', 'Me da miedo preguntar, $n... ¿está terminada la tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que ya está. Malditos sean estos tiempos que nos obligan a adoptar medidas desesperadas y maldito nuestro enemigo, la Plaga.$B$BRecuerda esto, $n: debemos proteger nuestra tierra al precio que sea. ¡Venceremos!', 0),
(@ID, 'esMX', 'Así que ya está. Malditos sean estos tiempos que nos obligan a adoptar medidas desesperadas y maldito nuestro enemigo, la Plaga.$B$BRecuerda esto, $n: debemos proteger nuestra tierra al precio que sea. ¡Venceremos!', 0);
-- 9359 El Retiro del Errante
-- https://es.wowhead.com/quest=9359
SET @ID := 9359;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a ayudar! ¡Excelente!$B$BLa batalla contra los trols Amani ha diezmado nuestros efectivos y siempre agradecemos el apoyo de luchadores capaces como tú.', 0),
(@ID, 'esMX', '¿Has venido a ayudar! ¡Excelente!$B$BLa batalla contra los trols Amani ha diezmado nuestros efectivos y siempre agradecemos el apoyo de luchadores capaces como tú.', 0);
-- 9252 Defender la Aldea Brisa Pura
-- https://es.wowhead.com/quest=9252
SET @ID := 9252;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Prevaleceremos, $n.', 0),
(@ID, 'esMX', 'Prevaleceremos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Nuestro trabajo es muy ingrato pero hoy tú lo has hecho un poco más fácil.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Nuestro trabajo es muy ingrato pero hoy tú lo has hecho un poco más fácil.', 0);
-- 9253 El celador de las runas Deryan
-- https://es.wowhead.com/quest=9253
SET @ID := 9253;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debe de enviarte alguien de la Aldea Brisa Pura. Sabía que era solo cuestión de tiempo hasta que llegara la ayuda.', 0),
(@ID, 'esMX', 'Debe de enviarte alguien de la Aldea Brisa Pura. Sabía que era solo cuestión de tiempo hasta que llegara la ayuda.', 0);
-- 8487 Tierra corrupta
-- https://es.wowhead.com/quest=8487
SET @ID := 8487;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las muestras que te pedí, $n?', 0),
(@ID, 'esMX', '¿Traes las muestras que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Voy a echar un encantamiento aumentador a las muestras para analizar la corrupción de la tierra.', 0),
(@ID, 'esMX', 'Excelente. Voy a echar un encantamiento aumentador a las muestras para analizar la corrupción de la tierra.', 0);
-- 8488 Resultados inesperados
-- https://es.wowhead.com/quest=8488
SET @ID := 8488;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No hay esperanza, $n. La naturaleza misma de la tierra ha sido alterada... La corrupción es irreversible. Gracias por tu ayuda; tengo una tarea más para ti.', 0),
(@ID, 'esMX', 'No hay esperanza, $n. La naturaleza misma de la tierra ha sido alterada... La corrupción es irreversible. Gracias por tu ayuda; tengo una tarea más para ti.', 0);

-- 9255 Notas de investigación
-- https://es.wowhead.com/quest=9255
SET @ID := 9255;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas anotaciones... son sorprendentes. Si son correctas, significa que el daño causado a la tierra de La Cicatriz Muerta es irreversible.$B$BNotificaré al gran magister ahora mismo. Más razón para que nuestra raza escape de este mundo y encuentre su verdadero destino en Terrallende.', 0),
(@ID, 'esMX', 'Estas anotaciones... son sorprendentes. Si son correctas, significa que el daño causado a la tierra de La Cicatriz Muerta es irreversible.$B$BNotificaré al gran magister ahora mismo. Más razón para que nuestra raza escape de este mundo y encuentre su verdadero destino en Terrallende.', 0);
-- 8490 Reforzando las defensas
-- https://es.wowhead.com/quest=8490
SET @ID := 8490;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Piedra rúnica cargada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido activar la piedra rúnica, $n?', 0),
(@ID, 'esMX', '¿Has conseguido activar la piedra rúnica, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Las defensas mantendrán a la Plaga a raya durante un tiempo más. Gracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Excelente. Las defensas mantendrán a la Plaga a raya durante un tiempo más. Gracias por tu ayuda, $n.', 0);
-- 8476 Asentamiento Amani
-- https://es.wowhead.com/quest=8476
SET @ID := 8476;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encontrarás los asentamientos Tor\'Watha y Zeb\'Watha al sureste de aquí. Vuelve cuando hayas matado a los trols.', 0),
(@ID, 'esMX', 'Encontrarás los asentamientos Tor\'Watha y Zeb\'Watha al sureste de aquí. Vuelve cuando hayas matado a los trols.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Con más gente como tú pronto devolveremos su antigua gloria a nuestra tierra.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Con más gente como tú pronto devolveremos su antigua gloria a nuestra tierra.', 0);
-- 8477 El martillo del maestro de lanzas
-- https://es.wowhead.com/quest=8477
SET @ID := 8477;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el martillo de Otembe, $n?', 0),
(@ID, 'esMX', '¿Traes el martillo de Otembe, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que cuentan es cierto, $n. Este martillo es ligero y resistente al mismo tiempo; ahora podré acabar varios encargos pendientes. Naturalmente, serás el primero en elegir una de mis creaciones.', 0),
(@ID, 'esMX', 'Lo que cuentan es cierto, $n. Este martillo es ligero y resistente al mismo tiempo; ahora podré acabar varios encargos pendientes. Naturalmente, serás el primero en elegir una de mis creaciones.', 0);
-- 8888 La aprendiza
-- https://es.wowhead.com/quest=8888
SET @ID := 8888;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El magister estaba preocupado por mí? Qué tierno; podría haberse interesado antes, cuando estábamos en la Aguja.$B$BNo importa. Escucha atentamente, $c: tengo que pedirte un favor.', 0),
(@ID, 'esMX', '¿El magister estaba preocupado por mí? Qué tierno; podría haberse interesado antes, cuando estábamos en la Aguja.$B$BNo importa. Escucha atentamente, $c: tengo que pedirte un favor.', 0);
-- 8479 Zul'Marosh
-- https://es.wowhead.com/quest=8479
SET @ID := 8479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la cabeza de Zul\'Marosh?', 0),
(@ID, 'esMX', '¿Traes la cabeza de Zul\'Marosh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. Se lo merecía por quemar el poblado de Ven\'jashi. Maté a muchos Amani antes de que me metieran en la jaula. Escondí algo en la arena; te lo regalo.$B$BAh... El veneno hace efecto. Voy a descansar...', 0),
(@ID, 'esMX', 'Bien. Se lo merecía por quemar el poblado de Ven\'jashi. Maté a muchos Amani antes de que me metieran en la jaula. Escondí algo en la arena; te lo regalo.$B$BAh... El veneno hace efecto. Voy a descansar...', 0);
-- 9360 La invasión Amani
-- https://es.wowhead.com/quest=9360
SET @ID := 9360;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué deseas enseñarme?', 0),
(@ID, 'esMX', '¿Qué deseas enseñarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los trols nos cercaron cuando planificábamos un ataque sobre la Aldea Brisa Pura. Fue de lo más inesperado.', 0),
(@ID, 'esMX', 'Los trols nos cercaron cuando planificábamos un ataque sobre la Aldea Brisa Pura. Fue de lo más inesperado.', 0);
-- 9363 Aviso a la Aldea Brisa Pura
-- https://es.wowhead.com/quest=9363
SET @ID := 9363;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La información que has traído es de vital importancia, $n. Ahora que sabemos qué planes tienen los trols, podemos prepararnos para un ataque.$B$BNo nos cogerán con la guardia bajada.', 0),
(@ID, 'esMX', 'La información que has traído es de vital importancia, $n. Ahora que sabemos qué planes tienen los trols, podemos prepararnos para un ataque.$B$BNo nos cogerán con la guardia bajada.', 0);
-- 8889 Desactivando la Aguja
-- https://es.wowhead.com/quest=8889
SET @ID := 8889;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Primera fuente de alimentación desactivada', `ObjectiveText2` = 'Segunda fuente de alimentación desactivada', `ObjectiveText3` = 'Tercera fuente de alimentación desactivada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No veo bien desde tan lejos... ¿Has desactivado las fuentes de poder de la Aguja Ocaso Marchito?', 0),
(@ID, 'esMX', 'No veo bien desde tan lejos... ¿Has desactivado las fuentes de poder de la Aguja Ocaso Marchito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te agradezco tu ayuda, pero me apena saber que algunos de mis aprendices han sucumbido a su adicción.$B$BAhora que las líneas de poder de la Aguja están cortadas, me quedaré un poco a esperar que las cosas se calmen para salir a buscar sus restos.', 0),
(@ID, 'esMX', 'Te agradezco tu ayuda, pero me apena saber que algunos de mis aprendices han sucumbido a su adicción.$B$BAhora que las líneas de poder de la Aguja están cortadas, me quedaré un poco a esperar que las cosas se calmen para salir a buscar sus restos.', 0);
-- 9394 ¿Dónde está Wyllithen?
-- https://es.wowhead.com/quest=9394
SET @ID := 9394;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién eres? No eres uno de los aprendices del magister, eso seguro.$B$BSin duda te han enviado para arreglar todo este desastre.', 0),
(@ID, 'esMX', '¿Quién eres? No eres uno de los aprendices del magister, eso seguro.$B$BSin duda te han enviado para arreglar todo este desastre.', 0);
-- 8891 Investigación abandonada
-- https://es.wowhead.com/quest=8891
SET @ID := 8891;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Me suena. Oh no, este diario... mi investigación... esta es la causa de todo esto desde el principio.', 0),
(@ID, 'esMX', '¿Qué es esto? Me suena. Oh no, este diario... mi investigación... esta es la causa de todo esto desde el principio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n, la prueba de mi delito. En este diario se recogen todos mis perversos estudios.$B$BHaciendo oídos sordos ante las advertencias, seguí con mi investigación hasta que fue casi demasiado tarde. Cuando me di cuenta de mi error, hice lo que pude. Pero para entonces, algunos de mis alumnos ya habían llegado demasiado lejos. Hice que evacuaran la Cumbre para alejarlos de la corrupción, pero en mi apresuramiento, olvidé cortar las fuentes de poder.$B$BQuemaré este libro para que nadie más caiga víctima de su contenido. Solo pretendía ayudar a los sin\'dorei.', 0),
(@ID, 'esMX', 'Aquí tienes, $n, la prueba de mi delito. En este diario se recogen todos mis perversos estudios.$B$BHaciendo oídos sordos ante las advertencias, seguí con mi investigación hasta que fue casi demasiado tarde. Cuando me di cuenta de mi error, hice lo que pude. Pero para entonces, algunos de mis alumnos ya habían llegado demasiado lejos. Hice que evacuaran la Cumbre para alejarlos de la corrupción, pero en mi apresuramiento, olvidé cortar las fuentes de poder.$B$BQuemaré este libro para que nadie más caiga víctima de su contenido. Solo pretendía ayudar a los sin\'dorei.', 0);
-- 8890 Un mensaje de la Aguja
-- https://es.wowhead.com/quest=8890
SET @ID := 8890;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No! Llegué demasiado tarde. Todo es culpa mía.$B$BMi investigación en fuentes mágicas purificadoras alternativas se me fue de las manos antes de que pudiera detenerlo. Si por lo menos hubiera yo... ¡o si me hubieran escuchado y tenido en cuenta mis advertencias!$B$BTengo sangre en las manos, $c. Te agradezco, sin embargo, que hayas aportado descanso a las torturadas almas de mis anteriores aprendices. Es un pequeño consuelo que ya no permanezcan en ese estado en el que a un elfo de sangre más le vale estar muerto.', 0),
(@ID, 'esMX', '¡No! Llegué demasiado tarde. Todo es culpa mía.$B$BMi investigación en fuentes mágicas purificadoras alternativas se me fue de las manos antes de que pudiera detenerlo. Si por lo menos hubiera yo... ¡o si me hubieran escuchado y tenido en cuenta mis advertencias!$B$BTengo sangre en las manos, $c. Te agradezco, sin embargo, que hayas aportado descanso a las torturadas almas de mis anteriores aprendices. Es un pequeño consuelo que ya no permanezcan en ese estado en el que a un elfo de sangre más le vale estar muerto.', 0);
-- 8894 Limpieza a fondo
-- https://es.wowhead.com/quest=8894
SET @ID := 8894;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has encargado entonces? ¿Terminaste con un buen número de esas anomalías mágicas? ¿Qué haría yo si el Magister reapareciera con todas estas cosas al acecho?', 0),
(@ID, 'esMX', '¿Te has encargado entonces? ¿Terminaste con un buen número de esas anomalías mágicas? ¿Qué haría yo si el Magister reapareciera con todas estas cosas al acecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, no podemos hacer más. Gracias por tu ayuda, $c. Espero tener tiempo de limpiar todo esto antes de que el magister vuelva a la Aguja Ocaso Marchito.$B$BTen estas monedas; no es mucho, pero ahora no dispongo de más. Y por supuesto, si te apetece liquidar a unas cuantas bestias más mientras sigues tu camino, no te prives.', 0),
(@ID, 'esMX', 'Muy bien, no podemos hacer más. Gracias por tu ayuda, $c. Espero tener tiempo de limpiar todo esto antes de que el magister vuelva a la Aguja Ocaso Marchito.$B$BTen estas monedas; no es mucho, pero ahora no dispongo de más. Y por supuesto, si te apetece liquidar a unas cuantas bestias más mientras sigues tu camino, no te prives.', 0);
-- 9529 La piedra
-- https://es.wowhead.com/quest=9529
SET @ID := 9529;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras miras la piedra, tu visión comienza a girar...', 0),
(@ID, 'esMX', 'Mientras miras la piedra, tu visión comienza a girar...', 0);
-- 109 Habla con Gryan Mantorrecio
-- https://es.classic.wowhead.com/quest=109
SET @ID := 109;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al... ¿Algo de Suerte?', 0),
(@ID, 'esMX', 'Al... ¿Algo de Suerte?', 0);
-- 9067 Fiesta interminable
-- https://es.wowhead.com/quest=9067
SET @ID := 9067;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gun hombre:una mujer; bastante $genérgico:enérgica;, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0),
(@ID, 'esMX', 'Eres $gun hombre:una mujer; bastante $genérgico:enérgica;, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0);
-- 9144 Desaparecido en las Tierras Fantasma
-- https://es.wowhead.com/quest=9144
SET @ID := 9144;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ayúdame. Tengo que llegar a Tranquillien... No puedo fallar.$B$B<El elfo de sangre pierde el conocimiento.>', 0),
(@ID, 'esMX', 'Ayúdame. Tengo que llegar a Tranquillien... No puedo fallar.$B$B<El elfo de sangre pierde el conocimiento.>', 0);
-- 9619 La runa de invocación
-- https://es.wowhead.com/quest=9619
SET @ID := 9619;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has seguido el camino revelado por la piedra del vacío?', 0),
(@ID, 'esMX', '¿Has seguido el camino revelado por la piedra del vacío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me impresiona que estés aquí, $n. Más de un aprendiz ha perecido ante el abisario, o incluso ante la propia piedra del vacío.$B$BEl abisario ahora es tuyo. Usa bien a tu nuevo sirviente.', 0),
(@ID, 'esMX', 'Me impresiona que estés aquí, $n. Más de un aprendiz ha perecido ante el abisario, o incluso ante la propia piedra del vacío.$B$BEl abisario ahora es tuyo. Usa bien a tu nuevo sirviente.', 0);
-- 9147 El mensajero caído
-- https://es.wowhead.com/quest=9147
SET @ID := 9147;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien? ¿Me has traído lo que necesito? ¡Apura, o adiós al lindo elfito de sangre!', 0),
(@ID, 'esMX', '¿Y bien? ¿Me has traído lo que necesito? ¡Apura, o adiós al lindo elfito de sangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo a tiempo, $n! Iba a empezar a cavar un hoyo para nuestro amigo.$B$BParece que mi poción funciona; ya viene.$B$BEh, creo que intenta que te fijes en él. ¿Por qué no hablas con él?', 0),
(@ID, 'esMX', '¡Justo a tiempo, $n! Iba a empezar a cavar un hoyo para nuestro amigo.$B$BParece que mi poción funciona; ya viene.$B$BEh, creo que intenta que te fijes en él. ¿Por qué no hablas con él?', 0);
-- 9148 Entrega en Tranquillien
-- https://es.wowhead.com/quest=9148
SET @ID := 9148;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la carta?', 0),
(@ID, 'esMX', '¿Tienes la carta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! ¡Llevamos semanas esperando una respuesta del Señor regente! A ver...$B$B<Vandril empieza a leer la carta.>$B$B¿Qué es esto? ¿Una presencia oscura? ¡¿Que siente una presencia oscura en las Tierras Fantasma?! Estará de broma; ¡yo podía haberle dicho eso!$B$B¿Para esto hemos estado esperando?', 0),
(@ID, 'esMX', '¡Por fin! ¡Llevamos semanas esperando una respuesta del Señor regente! A ver...$B$B<Vandril empieza a leer la carta.>$B$B¿Qué es esto? ¿Una presencia oscura? ¡¿Que siente una presencia oscura en las Tierras Fantasma?! Estará de broma; ¡yo podía haberle dicho eso!$B$B¿Para esto hemos estado esperando?', 0);
-- 9327 Los Renegados
-- https://es.wowhead.com/quest=9327
SET @ID := 9327;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que los Renegados parecen monstruosos ante tus ojos pero te aseguro que no queremos hacerle ningún daño a tu pueblo. Estamos aquí por un enemigo común: ¡Dar\'Khan, el traidor! Ha vuelto y ahora está al mando de la Plaga que está invadiendo esta tierra desde su inquebrantable Ciudad de la Muerte al sur.$B$BNuestra líder, Lady Sylvanas Brisaveloz, procede de estas tierras y, de hecho, antes era una elfa. Tiene cuentas pendientes con Dar\'Khan y quiere verlo muerto tanto como a su pueblo.$B$B¡Juntos lo derrotaremos, $c!', 0),
(@ID, 'esMX', 'Sé que los Renegados parecen monstruosos ante tus ojos pero te aseguro que no queremos hacerle ningún daño a tu pueblo. Estamos aquí por un enemigo común: ¡Dar\'Khan, el traidor! Ha vuelto y ahora está al mando de la Plaga que está invadiendo esta tierra desde su inquebrantable Ciudad de la Muerte al sur.$B$BNuestra líder, Lady Sylvanas Brisaveloz, procede de estas tierras y, de hecho, antes era una elfa. Tiene cuentas pendientes con Dar\'Khan y quiere verlo muerto tanto como a su pueblo.$B$B¡Juntos lo derrotaremos, $c!', 0);
-- 9152 Los suministros de Sepulturero
-- https://es.wowhead.com/quest=9152
SET @ID := 9152;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tan pronto como consiga el resto de mis suministros, podré abrir. Las tropas del lugar no llegarán muy lejos si no pueden comprar lo que necesitan para ejercer su oficio.$B$BLas zonas de conflicto bélico pueden generar mucho negocio, ¿no crees, $c? Bien, ¿has conseguido volver a mi carro a través de todos estos necrófagos?', 0),
(@ID, 'esMX', 'Tan pronto como consiga el resto de mis suministros, podré abrir. Las tropas del lugar no llegarán muy lejos si no pueden comprar lo que necesitan para ejercer su oficio.$B$BLas zonas de conflicto bélico pueden generar mucho negocio, ¿no crees, $c? Bien, ¿has conseguido volver a mi carro a través de todos estos necrófagos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con el resto de mis suministros al fin podré abrir el negocio. Seguro que el Sumo Ejecutor también se alegrará de oír que la guerra contra Dar\'Khan y la Plaga puede empezar.$B$BAh, y claro, está el asuntillo de tu recompensa. Muy bien, $c, aquí está la moneda de la que te hablé. No dejes de pasarte si necesitas cualquier producto.', 0),
(@ID, 'esMX', 'Con el resto de mis suministros al fin podré abrir el negocio. Seguro que el Sumo Ejecutor también se alegrará de oír que la guerra contra Dar\'Khan y la Plaga puede empezar.$B$BAh, y claro, está el asuntillo de tu recompensa. Muy bien, $c, aquí está la moneda de la que te hablé. No dejes de pasarte si necesitas cualquier producto.', 0);
-- 9150 Al rescate del pasado
-- https://es.wowhead.com/quest=9150
SET @ID := 9150;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste las esencias, $n?', 0),
(@ID, 'esMX', '¿Conseguiste las esencias, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es increíblemente potente, $n. Estoy muy satisfecho con tu trabajo.', 0),
(@ID, 'esMX', 'Eso es increíblemente potente, $n. Estoy muy satisfecho con tu trabajo.', 0);
-- 9145 ¡Ayuda a la forestal Valanna!
-- https://es.wowhead.com/quest=9145
SET @ID := 9145;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una alegría oír que Lethvalin consiguió ponerse a salvo y que fue lo suficientemente listo para pedirte ayuda en lugar de seguir esperando allí.$B$BEspero que la forestal Salissa también lograra refugiarse en el Enclave del Errante.', 0),
(@ID, 'esMX', 'Es una alegría oír que Lethvalin consiguió ponerse a salvo y que fue lo suficientemente listo para pedirte ayuda en lugar de seguir esperando allí.$B$BEspero que la forestal Salissa también lograra refugiarse en el Enclave del Errante.', 0);
-- 9160 Explorando An'daroth
-- https://es.wowhead.com/quest=9160
SET @ID := 9160;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c. ¿Qué noticias traes sobre An\'daroth y lo que estaban haciendo allí los elfos de la noche?', 0),
(@ID, 'esMX', '$c. ¿Qué noticias traes sobre An\'daroth y lo que estaban haciendo allí los elfos de la noche?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperaba que los planes de los elfos de la noche en An\'daroth fueran más evidentes. Pero lo que cuentas sobre esa especie de arbolitos mágicos con orbes de poder es muy interesante. Tendremos que ser más directos para conseguir información.$B$BTen esta moneda y estas pociones. Las necesitarás antes de terminar este asunto con los elfos de la noche.', 0),
(@ID, 'esMX', 'Esperaba que los planes de los elfos de la noche en An\'daroth fueran más evidentes. Pero lo que cuentas sobre esa especie de arbolitos mágicos con orbes de poder es muy interesante. Tendremos que ser más directos para conseguir información.$B$BTen esta moneda y estas pociones. Las necesitarás antes de terminar este asunto con los elfos de la noche.', 0);

-- 9758 Regresa junto al arcanista Vandril
-- https://es.wowhead.com/quest=9758
SET @ID := 9758;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah bien, ahí estás! Y justo a tiempo... ¡Hay mucho por hacer!', 0),
(@ID, 'esMX', '¡Ah bien, ahí estás! Y justo a tiempo... ¡Hay mucho por hacer!', 0);
-- 9192 Problemas en las Minas Sondaluz
-- https://es.wowhead.com/quest=9192
SET @ID := 9192;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gQuerido:Querida;, ¿son buenas noticias o malas?', 0),
(@ID, 'esMX', '$gQuerido:Querida;, ¿son buenas noticias o malas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen trabajo de carnicería, $c. Ahora mandaremos a los mineros volver al trabajo. Seguro que lamentarán que se les acabe el descanso pero hay que fabricar armaduras y armas y eso requiere mineral que se debe extraer.$B$BToma, acepta esto como pago por cumplir con tu deber. Ve a que te reparen la armadura y las armas y tómate algo, invito yo.', 0),
(@ID, 'esMX', 'Un buen trabajo de carnicería, $c. Ahora mandaremos a los mineros volver al trabajo. Seguro que lamentarán que se les acabe el descanso pero hay que fabricar armaduras y armas y eso requiere mineral que se debe extraer.$B$BToma, acepta esto como pago por cumplir con tu deber. Ve a que te reparen la armadura y las armas y tómate algo, invito yo.', 0);
-- 9155 Limpiar La Cicatriz Muerta
-- https://es.wowhead.com/quest=9155
SET @ID := 9155;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya terminaste con tu tarea?', 0),
(@ID, 'esMX', '¿Ya terminaste con tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está mal, $n. Sigue así; necesitamos a más gente como tú por aquí.', 0),
(@ID, 'esMX', 'No está mal, $n. Sigue así; necesitamos a más gente como tú por aquí.', 0);
-- 9149 La costa apestada
-- https://es.wowhead.com/quest=9149
SET @ID := 9149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado los especímenes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has encontrado los especímenes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¡Estas espinas dorsales no tienen precio para mi investigación! Cuando encuentre una cura para la peste y se haga famoso mi nombre, ¡me aseguraré de que recibas el debido crédito!$B$BMientras tanto, acepta esto como recompensa. Pueden hacerte falta si decides volver a la costa.', 0),
(@ID, 'esMX', '¡Estupendo! ¡Estas espinas dorsales no tienen precio para mi investigación! Cuando encuentre una cura para la peste y se haga famoso mi nombre, ¡me aseguraré de que recibas el debido crédito!$B$BMientras tanto, acepta esto como recompensa. Pueden hacerte falta si decides volver a la costa.', 0);
-- 9156 Se busca: Putrenudillos y Luzran
-- https://es.wowhead.com/quest=9156
SET @ID := 9156;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah... ¡Luzran y Putrenudillos! Ya no sois tan duros, ¿eh? Pero seguís igual de feos.$B$BElige una recompensa, $n. Te la has ganado.', 0),
(@ID, 'esMX', 'Ah... ¡Luzran y Putrenudillos! Ya no sois tan duros, ¿eh? Pero seguís igual de feos.$B$BElige una recompensa, $n. Te la has ganado.', 0);
-- 9171 Texturas crujientes
-- https://es.wowhead.com/quest=9171
SET @ID := 9171;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oigo rugir el estómago de la dama desde aquí! ¿Me traes las patas de araña?', 0),
(@ID, 'esMX', '¡Oigo rugir el estómago de la dama desde aquí! ¿Me traes las patas de araña?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, me apañaré con estas. No me describas a los bichos vivos, ¡no quiero saberlo! Les daré mi toque mágico a estas patas y saldrán muy buenas. Un poquito de especias, finas hierbas y por supuesto algunos ingredientes arcanos, y voilà, una comida digna de una reina. O de una dama en este caso.$B$BBuen trabajo, $c. Ten, una receta y unas muestras.', 0),
(@ID, 'esMX', 'Bien, me apañaré con estas. No me describas a los bichos vivos, ¡no quiero saberlo! Les daré mi toque mágico a estas patas y saldrán muy buenas. Un poquito de especias, finas hierbas y por supuesto algunos ingredientes arcanos, y voilà, una comida digna de una reina. O de una dama en este caso.$B$BBuen trabajo, $c. Ten, una receta y unas muestras.', 0);
-- 9130 Mercancía de Ciudad de Lunargenta
-- https://es.wowhead.com/quest=9130
SET @ID := 9130;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¿qué es esto?', 0),
(@ID, 'esMX', 'Sí, ¿qué es esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sathiel quiere que vayas a la Ciudad de Lunargenta y le lleves sus bienes, ¿vale? Desde luego que puedo llevarte allí rápidamente... por una módica cantidad, claro.', 0),
(@ID, 'esMX', 'Sathiel quiere que vayas a la Ciudad de Lunargenta y le lleves sus bienes, ¿vale? Desde luego que puedo llevarte allí rápidamente... por una módica cantidad, claro.', 0);
-- 9138 La Aldea Corona del Sol
-- https://es.wowhead.com/quest=9138
SET @ID := 9138;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tu ayuda conseguiremos contener el problema de la Plaga, $c. ¡Dar\'Khan será tratado!$B$B¿Ya has resuelto el problema nerubiano en la aldea Corona del Sol?', 0),
(@ID, 'esMX', 'Con tu ayuda conseguiremos contener el problema de la Plaga, $c. ¡Dar\'Khan será tratado!$B$B¿Ya has resuelto el problema nerubiano en la aldea Corona del Sol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso! ¡Pero aún queda mucho por hacer antes de que la amenaza de la Plaga se aleje de la poderosa Quel\'Thalas!$B$BAquí tienes, acepta esta moneda... no es gran cosa pero te la has ganado.', 0),
(@ID, 'esMX', '¡Asombroso! ¡Pero aún queda mucho por hacer antes de que la amenaza de la Plaga se aleje de la poderosa Quel\'Thalas!$B$BAquí tienes, acepta esta moneda... no es gran cosa pero te la has ganado.', 0);
-- 9133 Vuelo a la Ciudad de Lunargenta
-- https://es.wowhead.com/quest=9133
SET @ID := 9133;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es una señora lista, amigo. A ver, a ver...', 0),
(@ID, 'esMX', 'Eso es una señora lista, amigo. A ver, a ver...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡¿Qué Sathiel quiere todo esto!?$B$B¿Has traído a alguien para que te ayude a llevarlo?', 0),
(@ID, 'esMX', '¿Qué es esto? ¡¿Qué Sathiel quiere todo esto!?$B$B¿Has traído a alguien para que te ayude a llevarlo?', 0);
-- 9134 La maestra del cielo Anochecer
-- https://es.wowhead.com/quest=9134
SET @ID := 9134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esa caja parece muy pesada! ¿No querrás cargarla en una de mis hermosuras voladoras?', 0),
(@ID, 'esMX', '¡Esa caja parece muy pesada! ¿No querrás cargarla en una de mis hermosuras voladoras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te vuelves a la Aldea Brisa Pura en el Bosque Canción Eterna? ¡Déjame a mí, verás qué pronto llegas!', 0),
(@ID, 'esMX', '¿Te vuelves a la Aldea Brisa Pura en el Bosque Canción Eterna? ¡Déjame a mí, verás qué pronto llegas!', 0);
-- 9135 Regresa junto a Sathiel
-- https://es.wowhead.com/quest=9135
SET @ID := 9135;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tan pronto de vuelta, $c? No parece que tengas todo lo que te pedí...', 0),
(@ID, 'esMX', '¿Tan pronto de vuelta, $c? No parece que tengas todo lo que te pedí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, si dijo que el resto llegaría pronto por tierra, creeré en su palabra. Desde luego, nunca ha dejado tirado con un envío.$B$BGracias, $n. Toma esta moneda... no hace más que dar vueltas todo el día en mi bolsillo.', 0),
(@ID, 'esMX', 'Bueno, si dijo que el resto llegaría pronto por tierra, creeré en su palabra. Desde luego, nunca ha dejado tirado con un envío.$B$BGracias, $n. Toma esta moneda... no hace más que dar vueltas todo el día en mi bolsillo.', 0);
-- 1 Misión de Kanrethad
-- https://es.wowhead.com/quest=1
SET @ID := 1;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acuérdate de tus talentos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 17 Componentes de Uldaman
-- https://es.classic.wowhead.com/quest=17
SET @ID := 17;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes las setas moradas? ¡Si no, no te pago!', 0),
(@ID, 'esMX', '¿Me traes las setas moradas? ¡Si no, no te pago!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has hecho un buen trabajo otra vez, $n! Esto va a ser muy interesante.$B$BY como te prometí, aquí tienes uno de mis mejores elixires vigorizantes.$B$BSi te interesa la alquimia, puedo ofrecerte otros trabajos. En todo caso, te agradezco tu ayuda.', 0),
(@ID, 'esMX', '¡Has hecho un buen trabajo otra vez, $n! Esto va a ser muy interesante.$B$BY como te prometí, aquí tienes uno de mis mejores elixires vigorizantes.$B$BSi te interesa la alquimia, puedo ofrecerte otros trabajos. En todo caso, te agradezco tu ayuda.', 0);
-- 55 Morbent Vil
-- https://es.classic.wowhead.com/quest=55
SET @ID := 55;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Morbent Vil matado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 71 Informa a Thomas
-- https://es.classic.wowhead.com/quest=71
SET @ID := 71;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has averiguado qué suerte corrieron Rolf y Malakai?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has averiguado qué suerte corrieron Rolf y Malakai?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has confirmado mis temores, $n. Los murlocs son una amenaza que no podemos ignorar.', 0),
(@ID, 'esMX', 'Has confirmado mis temores, $n. Los murlocs son una amenaza que no podemos ignorar.', 0);
-- 189 Orejas de Sangrapellejo
-- https://es.classic.wowhead.com/quest=189
SET @ID := 189;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas tenido éxito... Hay trols por todas partes. Asquerosos demonios.$B$B¡Por cierto, eso me recuerda algo! Asegúrate de decírselo a tus amigos, ¿vale? ¡Necesitamos mucha ayuda!', 0),
(@ID, 'esMX', 'Espero que hayas tenido éxito... Hay trols por todas partes. Asquerosos demonios.$B$B¡Por cierto, eso me recuerda algo! Asegúrate de decírselo a tus amigos, ¿vale? ¡Necesitamos mucha ayuda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh excelente, excelente. Esto ayudará un poco, por ahora...$B$B<Su voz se hace casi imperceptible, masculla algo sobre margen de beneficio y costes...>$B$B¿Qué? ¿Todavía estáis aquí? ¿Recompensa? Oh, vale... claro, aquí tienes... debería ser más que suficiente.', 0),
(@ID, 'esMX', 'Oh excelente, excelente. Esto ayudará un poco, por ahora...$B$B<Su voz se hace casi imperceptible, masculla algo sobre margen de beneficio y costes...>$B$B¿Qué? ¿Todavía estáis aquí? ¿Recompensa? Oh, vale... claro, aquí tienes... debería ser más que suficiente.', 0);
-- 198 Suministros para el soldado Thorsen
-- https://es.classic.wowhead.com/quest=198
SET @ID := 198;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Qué quieres? Oh, suministros de los goblins. Es extraño ver a $gun:una; $r entregándolos, generalmente mandan a alguien de los suyos. No pasa nada... ¿no los habrás tocado, verdad? Bien, bien... No querríamos que nada pasase en nuestras minas. No, no, no.', 0),
(@ID, 'esMX', '¿Sí? ¿Qué quieres? Oh, suministros de los goblins. Es extraño ver a $gun:una; $r entregándolos, generalmente mandan a alguien de los suyos. No pasa nada... ¿no los habrás tocado, verdad? Bien, bien... No querríamos que nada pasase en nuestras minas. No, no, no.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas minas terrestres nos ayudan a defendernos de ese animal Kurzen y de sus hombres. Gracias por traerlas. Si buscas más trabajo, probablemente pueda encontrar algo para ti. Y no tendrás que tratar con esos goblins, ¿mm?', 0),
(@ID, 'esMX', 'Estas minas terrestres nos ayudan a defendernos de ese animal Kurzen y de sus hombres. Gracias por traerlas. Si buscas más trabajo, probablemente pueda encontrar algo para ti. Y no tendrás que tratar con esos goblins, ¿mm?', 0);
-- 201 Investiga el campamento
-- https://es.classic.wowhead.com/quest=201
SET @ID := 201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bien? ¿Tuviste suerte localizando el campamento?', 0),
(@ID, 'esMX', '¿Bien? ¿Tuviste suerte localizando el campamento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, así que mi información era correcta, como siempre. Bueno, no creo que representen amenaza alguna de interferencia con nuestra operación, pero quizás necesiten alguno de los extraordinarios productos que hemos producido. Mmm...', 0),
(@ID, 'esMX', 'Mmm, así que mi información era correcta, como siempre. Bueno, no creo que representen amenaza alguna de interferencia con nuestra operación, pero quizás necesiten alguno de los extraordinarios productos que hemos producido. Mmm...', 0);
-- 213 OPA hostil
-- https://es.classic.wowhead.com/quest=213
SET @ID := 213;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito esos cristales, $n. ¡Haz lo que sea para conseguirlo! Hazlo, no me des detalles.$B$BTodo se trata del resultado, $n, nada más y nada menos.', 0),
(@ID, 'esMX', 'Necesito esos cristales, $n. ¡Haz lo que sea para conseguirlo! Hazlo, no me des detalles.$B$BTodo se trata del resultado, $n, nada más y nada menos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fascinante. El que los cristales se hayan caído con este proceso solo puede indicar que piensan usarlos para algún tipo de combustible o catalizador. Eso es todo lo que sé. Habrá que enviar muestras al químico jefe Gigglefont.', 0),
(@ID, 'esMX', 'Fascinante. El que los cristales se hayan caído con este proceso solo puede indicar que piensan usarlos para algún tipo de combustible o catalizador. Eso es todo lo que sé. Habrá que enviar muestras al químico jefe Gigglefont.', 0);
-- 267 La amenaza trogg
-- https://es.classic.wowhead.com/quest=267
SET @ID := 267;
UPDATE `quest_template_locale` SET `Objectives` = 'Lleva 8 dientes de trogg de piedra al capitán Rugelfuss a la torre de vigilancia sur.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes los 8 petrodientes de trogg? Si no, no sé qué haces aquí, $n.', 0),
(@ID, 'esMX', '¿Me traes los 8 petrodientes de trogg? Si no, no sé qué haces aquí, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n. Los enanos quedan en deuda contigo. ¡El rey Magni Barbabronce estaría orgulloso!', 0),
(@ID, 'esMX', 'Impresionante, $n. Los enanos quedan en deuda contigo. ¡El rey Magni Barbabronce estaría orgulloso!', 0);
 -- 348 La fiebre de Tuercespina
-- https://es.classic.wowhead.com/quest=348
SET @ID := 348;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... ¿Madre?$B$B... tanto frío...$B$B... hacia El Vacío Abismal... a-abrázame, madre...', 0),
(@ID, 'esMX', '... ¿Madre?$B$B... tanto frío...$B$B... hacia El Vacío Abismal... a-abrázame, madre...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... Siento que... la fuerza... vuelve a mí...$B$B¿Dónde estoy? ¿Bahía del Botín? ¡Cielos! He tenido un sueño de lo más extraño...$B$B... todavía me sigo sintiendo débil...', 0),
(@ID, 'esMX', '... Siento que... la fuerza... vuelve a mí...$B$B¿Dónde estoy? ¿Bahía del Botín? ¡Cielos! He tenido un sueño de lo más extraño...$B$B... todavía me sigo sintiendo débil...', 0);
-- 349 La fiebre de Tuercespina
-- https://es.classic.wowhead.com/quest=349
SET @ID := 349;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El médico brujo Unbagwa sabe lo que gustar a Mokk el Salvaje. ¡Sí, sí!$B$BYo hablar con espíritus y hacer que venga, sí, sí.$B$BPero haber otro espíritu como de gorila hablando también. Tú proteger al médico brujo Unbagwa y yo hacer que él venir.$B$BEl médico brujo Unbagwa quiere algo primero. ¡Trae 10 colmillos de gorila y yo empezar a hablar con espíritus!', 0),
(@ID, 'esMX', 'El médico brujo Unbagwa sabe lo que gustar a Mokk el Salvaje. ¡Sí, sí!$B$BYo hablar con espíritus y hacer que venga, sí, sí.$B$BPero haber otro espíritu como de gorila hablando también. Tú proteger al médico brujo Unbagwa y yo hacer que él venir.$B$BEl médico brujo Unbagwa quiere algo primero. ¡Trae 10 colmillos de gorila y yo empezar a hablar con espíritus!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al médico brujo Unbagwa gustarle colmillos de gorila! Por ti yo hablar con espíritus. Haz que venga Mokk el Salvaje.$B$BPero tú proteger al médico brujo Unbagwa de otra bestia gorila, ¡o no hay Mokk!', 0),
(@ID, 'esMX', '¡Al médico brujo Unbagwa gustarle colmillos de gorila! Por ti yo hablar con espíritus. Haz que venga Mokk el Salvaje.$B$BPero tú proteger al médico brujo Unbagwa de otra bestia gorila, ¡o no hay Mokk!', 0);

-- 372 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=372
SET @ID := 372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún no has cumplido con tu deber, $c. No podemos esperar llevar a cabo el plan de La Dama Oscura con la Cruzada Escarlata molestando a nuestros soldados. ¡Haz que mueran y cumple tu deber con Sylvanas!', 0),
(@ID, 'esMX', 'Aún no has cumplido con tu deber, $c. No podemos esperar llevar a cabo el plan de La Dama Oscura con la Cruzada Escarlata molestando a nuestros soldados. ¡Haz que mueran y cumple tu deber con Sylvanas!', 0);
-- 498 El rescate
-- https://es.classic.wowhead.com/quest=498
SET @ID := 498;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Rescata a Drull', `ObjectiveText2` = 'Rescata a Tog\'thar', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes darte prisa, $c. Me estremezco al pensar en lo que los humanos podrían estar haciendo con Drull y Tog\'thar.', 0),
(@ID, 'esMX', 'Debes darte prisa, $c. Me estremezco al pensar en lo que los humanos podrían estar haciendo con Drull y Tog\'thar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que los humanos querían esclavizarnos, ¿eh? ¡Eso ya lo veremos!$B$BParece que han trasladado a Gol\'dir; debemos encontrarlo y rescatarlo.$B$BTe avisaré cuando tengamos alguna pista de su paradero.', 0),
(@ID, 'esMX', 'Así que los humanos querían esclavizarnos, ¿eh? ¡Eso ya lo veremos!$B$BParece que han trasladado a Gol\'dir; debemos encontrarlo y rescatarlo.$B$BTe avisaré cuando tengamos alguna pista de su paradero.', 0);
-- 499 Elixir de sufrimiento
-- https://es.classic.wowhead.com/quest=499
SET @ID := 499;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Croac!', 0),
(@ID, 'esMX', '¡Croac!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Croac!', 0),
(@ID, 'esMX', '¡Croac!', 0);
-- 501 Elixir de dolor
-- https://es.classic.wowhead.com/quest=501
SET @ID := 501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, $n; ibas a ayudarme con mi elixir. Necesito la sangre para extender el dolor y la muerte en Trabalomas.', 0),
(@ID, 'esMX', 'Ah, sí, $n; ibas a ayudarme con mi elixir. Necesito la sangre para extender el dolor y la muerte en Trabalomas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n.', 0);
-- 502 Elixir de dolor
-- https://es.classic.wowhead.com/quest=502
SET @ID := 502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Guau.', 0),
(@ID, 'esMX', 'Guau.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te pones un poco de elixir en el hueco de la mano y se lo das a Stanley.', 0),
(@ID, 'esMX', 'Te pones un poco de elixir en el hueco de la mano y se lo das a Stanley.', 0);
-- 503 Gol'dir
-- https://es.classic.wowhead.com/quest=503
SET @ID := 503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame la llave, $c, ya me ocupo yo.', 0),
(@ID, 'esMX', 'Dame la llave, $c, ya me ocupo yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Yo dirigía la expedición desde Durotar bajo las órdenes del Jefe de Guerra, pero como ves las cosas no han salido como esperábamos. Me han tenido cautivo en su ciudad realizando trabajos forzados.$B$BPero mi sufrimiento no es importante; tengo información que debes llevar de inmediato a quien sea que nos lidera ahora.', 0),
(@ID, 'esMX', 'Gracias, $n. Yo dirigía la expedición desde Durotar bajo las órdenes del Jefe de Guerra, pero como ves las cosas no han salido como esperábamos. Me han tenido cautivo en su ciudad realizando trabajos forzados.$B$BPero mi sufrimiento no es importante; tengo información que debes llevar de inmediato a quien sea que nos lidera ahora.', 0);
-- 506 El legado de Lodonegro
-- https://es.classic.wowhead.com/quest=506
SET @ID := 506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pero cómo se atreven esos humanos!$B$BAhora, además de recoger el abalorio para el Jefe de Guerra, nos ocuparemos de demostrarles que no nos someteremos nunca.', 0),
(@ID, 'esMX', '¡Pero cómo se atreven esos humanos!$B$BAhora, además de recoger el abalorio para el Jefe de Guerra, nos ocuparemos de demostrarles que no nos someteremos nunca.', 0);
-- 507 Lord Aliden Perenolde
-- https://es.classic.wowhead.com/quest=507
SET @ID := 507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Q-que quieres?', 0),
(@ID, 'esMX', '¿Q-que quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me hagas daño! ¡Yo no he hecho nada, me tenía retenida! ¡Piedad, te lo ruego!', 0),
(@ID, 'esMX', '¡No me hagas daño! ¡Yo no he hecho nada, me tenía retenida! ¡Piedad, te lo ruego!', 0);
-- 508 Un regalo de Taretha
-- https://es.classic.wowhead.com/quest=508
SET @ID := 508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Algún éxito que comunicar?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Algún éxito que comunicar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es extraño que el Jefe de Guerra se gaste tanto en una cosa tan pequeña. No puedo decir que lo entienda pero acataré sus órdenes, sean las que sean. Lo has hecho muy bien, $n, seguro que el Jefe de Guerra se alegrará de conocer tu éxito.', 0),
(@ID, 'esMX', 'Es extraño que el Jefe de Guerra se gaste tanto en una cosa tan pequeña. No puedo decir que lo entienda pero acataré sus órdenes, sean las que sean. Lo has hecho muy bien, $n, seguro que el Jefe de Guerra se alegrará de conocer tu éxito.', 0);
-- 509 Elixir de agonía
-- https://es.classic.wowhead.com/quest=509
SET @ID := 509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal en Granja Nethander?', 0),
(@ID, 'esMX', '¿Qué tal en Granja Nethander?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Detesto la peste de las flores de morrobarro. Al menos esos asquerosos gnolls sirven para algo.', 0),
(@ID, 'esMX', 'Detesto la peste de las flores de morrobarro. Al menos esos asquerosos gnolls sirven para algo.', 0);
-- 513 Elixir de agonía
-- https://es.classic.wowhead.com/quest=513
SET @ID := 513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estoy ocupado, $c? La Dama Oscura quiere que prepare una nueva plaga antes de que la Plaga nos invada desde Rasganorte. Los humanos amenazan desde el sur y a mí me falta el tiempo. ¡Espero que esto sea importante!', 0),
(@ID, 'esMX', '¿No ves que estoy ocupado, $c? La Dama Oscura quiere que prepare una nueva plaga antes de que la Plaga nos invada desde Rasganorte. Los humanos amenazan desde el sur y a mí me falta el tiempo. ¡Espero que esto sea importante!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que te envía el boticario Lydon? ¡Haberlo dicho!$B$BPese a su pesimismo innato, es uno de los mejores.$B$B¡Y me envía compuesto de Morrobarro! Me gusta su línea de pensamiento. La Dama Oscura estará muy complacida con los avances en la nueva peste.', 0),
(@ID, 'esMX', '¿Que te envía el boticario Lydon? ¡Haberlo dicho!$B$BPese a su pesimismo innato, es uno de los mejores.$B$B¡Y me envía compuesto de Morrobarro! Me gusta su línea de pensamiento. La Dama Oscura estará muy complacida con los avances en la nueva peste.', 0);
-- 515 Elixir de agonía
-- https://es.classic.wowhead.com/quest=515
SET @ID := 515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. Me estaba aburriendo mortalmente, sin nada que hacer salvo envenenar y reanimar a Umpi una y otra vez.$B$B¿Qué tal en Entrañas? ¿Pudiste eliminar a muchos humanos?', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. Me estaba aburriendo mortalmente, sin nada que hacer salvo envenenar y reanimar a Umpi una y otra vez.$B$B¿Qué tal en Entrañas? ¿Pudiste eliminar a muchos humanos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin, algo con lo que entretenerme! Gracias por tu ayuda, $n. ¡Vamos a extender la muerte y la enfermedad por el lugar!', 0),
(@ID, 'esMX', '¡Por fin, algo con lo que entretenerme! Gracias por tu ayuda, $n. ¡Vamos a extender la muerte y la enfermedad por el lugar!', 0);
 -- 516 El Desafío de Beren
-- https://es.classic.wowhead.com/quest=516
SET @ID := 516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has localizado su base, $n? ¡El tiempo es esencial!', 0),
(@ID, 'esMX', '¿Ya has localizado su base, $n? ¡El tiempo es esencial!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si nuestros exploradores y agentes continúan proporcionándonos información valiosa como esta, tendremos a la Plaga del rey Exánime fuera de nuestras tierras en un abrir y cerrar de ojos.', 0),
(@ID, 'esMX', 'Si nuestros exploradores y agentes continúan proporcionándonos información valiosa como esta, tendremos a la Plaga del rey Exánime fuera de nuestras tierras en un abrir y cerrar de ojos.', 0);
-- 517 Elixir de agonía
-- https://es.classic.wowhead.com/quest=517
SET @ID := 517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A veces me aburro tanto aquí en Molino Tarren que me da por probar cócteles de químicos. Pero Umpi se pone nerviosa.$B$BBueno, ¿traes el barril? Si no enveneno pronto a alguien con mi elixir mortal me va a dar un ataque.', 0),
(@ID, 'esMX', 'A veces me aburro tanto aquí en Molino Tarren que me da por probar cócteles de químicos. Pero Umpi se pone nerviosa.$B$BBueno, ¿traes el barril? Si no enveneno pronto a alguien con mi elixir mortal me va a dar un ataque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin podemos pasar a la acción!', 0),
(@ID, 'esMX', '¡Por fin podemos pasar a la acción!', 0);
 -- 518 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=518
SET @ID := 518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0),
(@ID, 'esMX', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La nieve está roja con la sangre de los ogros, pero no debemos cejar hasta que los Aplastacresta muerdan el polvo y sean aniquilados por completo.', 0),
(@ID, 'esMX', 'La nieve está roja con la sangre de los ogros, pero no debemos cejar hasta que los Aplastacresta muerdan el polvo y sean aniquilados por completo.', 0);
-- 519 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=519
SET @ID := 519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, quiero cabezas, no excusas.', 0),
(@ID, 'esMX', '$n, quiero cabezas, no excusas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y yo que creía que lo peor de los ogros era el olor.$B$BCuando me traigas la cabeza de Jarra\'thol, clavaré las 4 cabezas en picas; será un aviso para los que contrarían a la Dama Oscura.', 0),
(@ID, 'esMX', 'Y yo que creía que lo peor de los ogros era el olor.$B$BCuando me traigas la cabeza de Jarra\'thol, clavaré las 4 cabezas en picas; será un aviso para los que contrarían a la Dama Oscura.', 0);
-- 520 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=520
SET @ID := 520;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo 3 cabezas, me falta una. Si no es la de Jarra\'thol, será la tuya, $n; tenlo por seguro.', 0),
(@ID, 'esMX', 'Tengo 3 cabezas, me falta una. Si no es la de Jarra\'thol, será la tuya, $n; tenlo por seguro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. La cabeza de Jarra\'thol adornará la cumbre más alta de las Ruinas de Alterac y la Guardia de la Muerte acabará de exterminar a los Aplastacresta.', 0),
(@ID, 'esMX', 'Bien hecho, $n. La cabeza de Jarra\'thol adornará la cumbre más alta de las Ruinas de Alterac y la Guardia de la Muerte acabará de exterminar a los Aplastacresta.', 0);
-- 521 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=521
SET @ID := 521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Tienes alguna noticia?', 0),
(@ID, 'esMX', '¿Sí? ¿Tienes alguna noticia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que esto es lo que usó el ogro para enfrentarse a la Dama Oscura.$B$BCuesta creer que algo tan sencillo tenga tanto poder. Buen trabajo, $n. Entregaré la corona a Lady Sylvanas y le hablaré de tu proeza.', 0),
(@ID, 'esMX', 'Así que esto es lo que usó el ogro para enfrentarse a la Dama Oscura.$B$BCuesta creer que algo tan sencillo tenga tanto poder. Buen trabajo, $n. Entregaré la corona a Lady Sylvanas y le hablaré de tu proeza.', 0);
-- 524 Elixir de agonía
-- https://es.classic.wowhead.com/quest=524
SET @ID := 524;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La alfombra huele a moho.', 0),
(@ID, 'esMX', 'La alfombra huele a moho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dejas el barril contaminado en la alfombra polvorienta.', 0),
(@ID, 'esMX', 'Dejas el barril contaminado en la alfombra polvorienta.', 0);
-- 526 Lingotes Forjaluz
-- https://es.classic.wowhead.com/quest=526
SET @ID := 526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el hierro Forjaluz que necesitas?', 0),
(@ID, 'esMX', '¿Encontraste el hierro Forjaluz que necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los encontraste! Ahora hagamos que este hierro Forjaluz se convierta en algo útil, ¿eh?', 0),
(@ID, 'esMX', '¡Ah, los encontraste! Ahora hagamos que este hierro Forjaluz se convierta en algo útil, ¿eh?', 0);
-- 527 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=527
SET @ID := 527;
UPDATE `quest_template_locale` SET `Details` = 'Ponte firme cuando te dirijas a mí, $c.$B$BEstoy a las órdenes directas de Varimathras. Debemos sofocar la infestación humana hasta que nuestros boticarios desarrollen la nueva plaga.$B$BNuestros datos indican que Trabalomas es vulnerable. Tu primera misión es interrumpir el abastecimiento de alimentos y su infraestructura.$B$BVe hacia el oeste. Ataca las granjas más septentrionales de Campos de Trabalomas. Asegúrate de que los propietarios, el granjero Ray y el granjero Getz, son ejecutados.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como Alto Ejecutor de Molino Tarren, bajo el mando directo de Varimathras y la Dama Oscura, estás sujeto a seguir mis órdenes.$B$B¿Quizás te tomas a la ligera esta guerra con la Alianza? Si ese es el caso, debería decapitarte aquí y ahora. De lo contrario, viaja hacia el oeste hasta la ciudad de Trabalomas y libra una batalla contra los humanos, como te lo ordenaron.$B$BLárgate.', 0),
(@ID, 'esMX', 'Como Alto Ejecutor de Molino Tarren, bajo el mando directo de Varimathras y la Dama Oscura, estás sujeto a seguir mis órdenes.$B$B¿Quizás te tomas a la ligera esta guerra con la Alianza? Si ese es el caso, debería decapitarte aquí y ahora. De lo contrario, viaja hacia el oeste hasta la ciudad de Trabalomas y libra una batalla contra los humanos, como te lo ordenaron.$B$BLárgate.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Descansa, $c. Mis fuentes me indican que luchaste bien en el frente de Trabalomas.', 0),
(@ID, 'esMX', 'Descansa, $c. Mis fuentes me indican que luchaste bien en el frente de Trabalomas.', 0);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
