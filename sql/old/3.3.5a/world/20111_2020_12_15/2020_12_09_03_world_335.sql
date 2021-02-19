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
