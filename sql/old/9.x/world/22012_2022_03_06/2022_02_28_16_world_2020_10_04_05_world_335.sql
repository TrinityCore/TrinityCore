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
