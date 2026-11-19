-- 4265 Liberado de la colmena
-- https://es.classic.wowhead.com/quest=4265
SET @ID := 4265;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que informar, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que informar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido a casa, $n. Raschal llegó hace no mucho y me contó lo que ocurrió.$B$BYo... no, todo el Bastión, te agradece enormemente lo que has hecho. Raschal habría muerto si no hubieras llegado tú, y tu ayuda nos ha llegado por apenas la tasa de un mercenario. Eres $gun auténtico héroe:una auténtica heroína;. Siempre contarás con la amistad de Ginro Mechogar.', 0),
(@ID, 'esMX', 'Bienvenido a casa, $n. Raschal llegó hace no mucho y me contó lo que ocurrió.$B$BYo... no, todo el Bastión, te agradece enormemente lo que has hecho. Raschal habría muerto si no hubieras llegado tú, y tu ayuda nos ha llegado por apenas la tasa de un mercenario. Eres $gun auténtico héroe:una auténtica heroína;. Siempre contarás con la amistad de Ginro Mechogar.', 0);
-- 4266 La bienvenida de un héroe
-- https://es.classic.wowhead.com/quest=4266
SET @ID := 4266;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, te agradezco de corazón la ayuda que nos has prestado. El valor que has demostrado en una situación tan desesperada debería ser recompensado con algo mil veces más grande. Pero espero que aceptes esto de parte de todo el Bastión.$B$BY ahora, si me lo permites, quisiera pedirte ayuda una vez más. A la luz del descubrimiento del nido de Zukk\'ash aquí en Feralas, creo que eres la mejor elección para esta misión.', 0),
(@ID, 'esMX', '$n, te agradezco de corazón la ayuda que nos has prestado. El valor que has demostrado en una situación tan desesperada debería ser recompensado con algo mil veces más grande. Pero espero que aceptes esto de parte de todo el Bastión.$B$BY ahora, si me lo permites, quisiera pedirte ayuda una vez más. A la luz del descubrimiento del nido de Zukk\'ash aquí en Feralas, creo que eres la mejor elección para esta misión.', 0);
-- 4267 La sublevación de los silítidos
-- https://es.classic.wowhead.com/quest=4267
SET @ID := 4267;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé bienvenido a este Templo sagrado, $gamigo:amiga;. Tu llegada desde el Bastión Plumaluna me había sido anunciada. ¿Tienes el informe que Shandris Plumaluna te pidió que trajeras?', 0),
(@ID, 'esMX', 'Sé bienvenido a este Templo sagrado, $gamigo:amiga;. Tu llegada desde el Bastión Plumaluna me había sido anunciada. ¿Tienes el informe que Shandris Plumaluna te pidió que trajeras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los elfos de la noche conocemos el terror que se recoge en este informe. Shandris ha hecho bien en enviármelo. Y en enviarte a ti.$B$BEstas criaturas consumirán Feralas rápidamente; son una de las mayores amenazas que afrontaremos jamás. Los insectos que encontrasteis tú y el mensajero, se llaman silítidos. Aunque no son más que herramientas de una de las mayores amenazas que jamás han afrontado la Horda y la Alianza.$B$BRezo para que consigamos derrotarlos antes de que nos destruyan.', 0),
(@ID, 'esMX', 'Los elfos de la noche conocemos el terror que se recoge en este informe. Shandris ha hecho bien en enviármelo. Y en enviarte a ti.$B$BEstas criaturas consumirán Feralas rápidamente; son una de las mayores amenazas que afrontaremos jamás. Los insectos que encontrasteis tú y el mensajero, se llaman silítidos. Aunque no son más que herramientas de una de las mayores amenazas que jamás han afrontado la Horda y la Alianza.$B$BRezo para que consigamos derrotarlos antes de que nos destruyan.', 0);
-- 4281 Una entrega en Thalanaar
-- https://es.classic.wowhead.com/quest=4281
SET @ID := 4281;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a Thalanaar, $c. ¿Necesitas ayuda de algún tipo?', 0),
(@ID, 'esMX', 'Te doy la bienvenida a Thalanaar, $c. ¿Necesitas ayuda de algún tipo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabada sea Elune! ¡Por fin llega el envío del Bastión Plumaluna!$B$BTu presencia aquí me indica que algo malo ha debido de ocurrirle a Raschal, nuestro mensajero habitual. Espero que todo acabe bien. Sé que últimamente los Zarpaleña han estado muy agitados. Algo que viene del sur los agita. Quizás Raschal cayó en sus manos. Yo tendría cuidado si fuera tú.$B$BEn cualquier caso, gracias. Ten, por la entrega del paquete.', 0),
(@ID, 'esMX', '¡Alabada sea Elune! ¡Por fin llega el envío del Bastión Plumaluna!$B$BTu presencia aquí me indica que algo malo ha debido de ocurrirle a Raschal, nuestro mensajero habitual. Espero que todo acabe bien. Sé que últimamente los Zarpaleña han estado muy agitados. Algo que viene del sur los agita. Quizás Raschal cayó en sus manos. Yo tendría cuidado si fuera tú.$B$BEn cualquier caso, gracias. Ten, por la entrega del paquete.', 0);
-- 4282 Una brizna de esperanza
-- https://es.classic.wowhead.com/quest=4282
SET @ID := 4282;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto habrá acabado este gran subterfugio.', 0),
(@ID, 'esMX', 'Pronto habrá acabado este gran subterfugio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El mariscal Windsor te arrebata las 2 tablillas de las manos.>$B$B¡Tenemos que salir de aquí!', 0),
(@ID, 'esMX', '<El mariscal Windsor te arrebata las 2 tablillas de las manos.>$B$B¡Tenemos que salir de aquí!', 0);
-- 4283 ¡CINCUENTA! ¡SÍ!
-- https://es.classic.wowhead.com/quest=4283
SET @ID := 4283;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Oralius le habla a una oreja cortada de ogro bastante grande.>$B$BEstepas Ardientes a control, adelante control.', 0),
(@ID, 'esMX', '<Oralius le habla a una oreja cortada de ogro bastante grande.>$B$BEstepas Ardientes a control, adelante control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Tu recompensa es: ¡FRÓTAME LA BARRIGA! ¡VENGA! ¡FRÓTALA!', 0),
(@ID, 'esMX', '¡Lo has logrado! Tu recompensa es: ¡FRÓTAME LA BARRIGA! ¡VENGA! ¡FRÓTALA!', 0);
-- 4286 Buena mercancía
-- https://es.classic.wowhead.com/quest=4286
SET @ID := 4286;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No se me puede molestar ahora, $n. Winky y yo tenemos una reunión a la que asistir.', 0),
(@ID, 'esMX', 'No se me puede molestar ahora, $n. Winky y yo tenemos una reunión a la que asistir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Oralius empieza a rebuscar en la enorme pila de riñoneras.>$B$B¡OH, QUÉ MARAVILLA!$B$B<Oralius mete su narizota en la pila y olisquea.>$B$B¡DELICIOSO! ¡Fíjate en todas estas maravillas!$B$BQuédate con una para ti, $n. Hay mucho para repartir.', 0),
(@ID, 'esMX', '<Oralius empieza a rebuscar en la enorme pila de riñoneras.>$B$B¡OH, QUÉ MARAVILLA!$B$B<Oralius mete su narizota en la pila y olisquea.>$B$B¡DELICIOSO! ¡Fíjate en todas estas maravillas!$B$BQuédate con una para ti, $n. Hay mucho para repartir.', 0);
-- 4293 Muestras de babosa...
-- https://es.classic.wowhead.com/quest=4293
SET @ID := 4293;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré al menos cinco muestras corruptas para nuestro grupo de control, $n. Continúa recolectando muestras de babosas de Frondavil hasta que puedas darme lo que necesitamos. Lady Sylvanas lo decreta...', 0),
(@ID, 'esMX', 'Necesitaré al menos cinco muestras corruptas para nuestro grupo de control, $n. Continúa recolectando muestras de babosas de Frondavil hasta que puedas darme lo que necesitamos. Lady Sylvanas lo decreta...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, excelente. Estas muestras funcionarán muy bien. Te agradezco tu ayuda.$B$BUna vez que hayamos reunido todas las muestras de babosas, podremos determinar más. Empiezo a sospechar que la corazonada de Lady Sylvanas no solo era correcta, sino más perspicaz de lo que ella podría haber predicho. Estas muestras son muy interesantes. Solo viendo cómo han reaccionado con mis compuestos... hmm, sí, definitivamente necesitaremos investigar más.', 0),
(@ID, 'esMX', 'Ah, excelente. Estas muestras funcionarán muy bien. Te agradezco tu ayuda.$B$BUna vez que hayamos reunido todas las muestras de babosas, podremos determinar más. Empiezo a sospechar que la corazonada de Lady Sylvanas no solo era correcta, sino más perspicaz de lo que ella podría haber predicho. Estas muestras son muy interesantes. Solo viendo cómo han reaccionado con mis compuestos... hmm, sí, definitivamente necesitaremos investigar más.', 0);
-- 4294 ... y unos mocos
-- https://es.classic.wowhead.com/quest=4294
SET @ID := 4294;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Cómo va tu búsqueda?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Cómo va tu búsqueda?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente asombroso, $n. El Cráter de Un\'Goro alberga más secretos de lo que esperaba. Me pregunto qué más descubriremos a medida que prosigamos las investigaciones.$B$BEs simplemente asombroso... estas muestras son realmente puras. ¿A qué podrá deberse? Parecen ser elementales pero... hay algo más. Me recuerdan a los dioses antiguos. Ya hemos encontrado rastros de ellos en Azeroth pero ahora me pregunto si estas criaturas tendrán algo que ver con ellos.$B$BNo cabe duda de que tendremos que seguir analizándolas.', 0),
(@ID, 'esMX', 'Realmente asombroso, $n. El Cráter de Un\'Goro alberga más secretos de lo que esperaba. Me pregunto qué más descubriremos a medida que prosigamos las investigaciones.$B$BEs simplemente asombroso... estas muestras son realmente puras. ¿A qué podrá deberse? Parecen ser elementales pero... hay algo más. Me recuerdan a los dioses antiguos. Ya hemos encontrado rastros de ellos en Azeroth pero ahora me pregunto si estas criaturas tendrán algo que ver con ellos.$B$BNo cabe duda de que tendremos que seguir analizándolas.', 0);
-- 4295 La cerveza de Sinroca
-- https://es.classic.wowhead.com/quest=4295
SET @ID := 4295;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, cerveza! ¡¡Mataría por algo de cerveza Hierro Negro!! ¡Rápido, que me estoy poniendo sobrio! Lo sé porque la sobriedad me nubla la vista... ¡y eso hace que te parezcas $gal:a la; $r que maté la semana pasada!', 0),
(@ID, 'esMX', '¡Oh, cerveza! ¡¡Mataría por algo de cerveza Hierro Negro!! ¡Rápido, que me estoy poniendo sobrio! Lo sé porque la sobriedad me nubla la vista... ¡y eso hace que te parezcas $gal:a la; $r que maté la semana pasada!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡Ah! ¡Es el aroma de la cerveza Hierro Negro! La bebida me nubla la vista pero puedo decirte algo, $gseñor:señora;, ¡tú sí que eres $gun amigo:una amiga;!', 0),
(@ID, 'esMX', '¿Qué es esto? ¡Ah! ¡Es el aroma de la cerveza Hierro Negro! La bebida me nubla la vista pero puedo decirte algo, $gseñor:señora;, ¡tú sí que eres $gun amigo:una amiga;!', 0);
-- 4296 La tablilla de los Siete
-- https://es.classic.wowhead.com/quest=4296
SET @ID := 4296;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los textos de los Siete, $n? ¿Has averiguado los secretos de su tablilla?', 0),
(@ID, 'esMX', '¿Tienes los textos de los Siete, $n? ¿Has averiguado los secretos de su tablilla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, has encontrado la tablilla! ¡Y tu transcripción es excelente! Seguro que eres $gun:una; $c y no $gun:una; escriba?$B$BAquí tienes, $n. Aquí tienes el pago que te prometí.', 0),
(@ID, 'esMX', '¡Ah, has encontrado la tablilla! ¡Y tu transcripción es excelente! Seguro que eres $gun:una; $c y no $gun:una; escriba?$B$BAquí tienes, $n. Aquí tienes el pago que te prometí.', 0);
-- 4297 Comida para el bebé
-- https://es.classic.wowhead.com/quest=4297
SET @ID := 4297;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya encontraste esa carne, $n? Tu pequeño huevo está a punto de nacer. Si no tiene una primera comida lo suficientemente buena, es posible que no supere la primera semana, y odiaría que eso sucediera.$B$BNo puedo mentirte, $n. Estoy celoso de que consigas este huevo. No hagas que me arrepienta de haberte ayudado así.', 0),
(@ID, 'esMX', '¿Ya encontraste esa carne, $n? Tu pequeño huevo está a punto de nacer. Si no tiene una primera comida lo suficientemente buena, es posible que no supere la primera semana, y odiaría que eso sucediera.$B$BNo puedo mentirte, $n. Estoy celoso de que consigas este huevo. No hagas que me arrepienta de haberte ayudado así.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos servirán muy bien, y si no me equivoco, tu pequeño huevo está a punto de eclosionar. ¿Cómo te sientes? ¿Sabes, estás a punto de ser $gpadre:madre;? Jaja, no pensaste que tendrías que lidiar con tal responsabilidad, ¿verdad?', 0),
(@ID, 'esMX', 'Estos servirán muy bien, y si no me equivoco, tu pequeño huevo está a punto de eclosionar. ¿Cómo te sientes? ¿Sabes, estás a punto de ser $gpadre:madre;? Jaja, no pensaste que tendrías que lidiar con tal responsabilidad, ¿verdad?', 0);
-- 4298 El amor parental
-- https://es.classic.wowhead.com/quest=4298
SET @ID := 4298;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma, toma el huevo... mejor lo tienes para que se adhiera a ti y te crea su $gpapá:mamá;.$B$BFelicitaciones, $n. Eres $gpadre:madre;... un poco.', 0),
(@ID, 'esMX', 'Toma, toma el huevo... mejor lo tienes para que se adhiera a ti y te crea su $gpapá:mamá;.$B$BFelicitaciones, $n. Eres $gpadre:madre;... un poco.', 0);
-- 4300 Armas con filo de hueso
-- https://es.classic.wowhead.com/quest=4300
SET @ID := 4300;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis clientes no tienen mucha paciencia, $n. ¿Me traes las garras?', 0),
(@ID, 'esMX', 'Mis clientes no tienen mucha paciencia, $n. ¿Me traes las garras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto. Gracias por volver tan rápido, $n.$B$B¿Qué te parece si te hago un arma con las garras?', 0),
(@ID, 'esMX', 'Perfecto. Gracias por volver tan rápido, $n.$B$B¿Qué te parece si te hago un arma con las garras?', 0);
-- 4322 La fuga de la prisión
-- https://es.classic.wowhead.com/quest=4322
SET @ID := 4322;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces $gexhausto:exhausta;, $n. Quizás debería sentarse junto al fuego y relajarse.', 0),
(@ID, 'esMX', 'Pareces $gexhausto:exhausta;, $n. Quizás debería sentarse junto al fuego y relajarse.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Asombroso, $n. Sencillamente asombroso. Windsor pasó cual exhalación por aquí hace menos de cinco minutos. Ha venido con grandes afirmaciones pero pretende que se apoyen en su testimonio. Ahora va camino de Ventormenta para confrontar a Bolvar y a... Lady Prestor.', 0),
(@ID, 'esMX', 'Asombroso, $n. Sencillamente asombroso. Windsor pasó cual exhalación por aquí hace menos de cinco minutos. Ha venido con grandes afirmaciones pero pretende que se apoyen en su testimonio. Ahora va camino de Ventormenta para confrontar a Bolvar y a... Lady Prestor.', 0);
-- 4341 Kharan Martillo Poderoso
-- https://es.classic.wowhead.com/quest=4341
SET @ID := 4341;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deja que te explique.', 0),
(@ID, 'esMX', 'Deja que te explique.', 0);
-- 4342 El relato de Kharan
-- https://es.classic.wowhead.com/quest=4342
SET @ID := 4342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permite que acabe de contar mi historia.', 0),
(@ID, 'esMX', 'Permite que acabe de contar mi historia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como puedes ver, no podía hacer nada.', 0),
(@ID, 'esMX', 'Como puedes ver, no podía hacer nada.', 0);
-- 4361 Portador de malas noticias
-- https://es.classic.wowhead.com/quest=4361
SET @ID := 4361;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Rey Magni da un puñetazo furioso.>', 0),
(@ID, 'esMX', '<El Rey Magni da un puñetazo furioso.>', 0);
-- 4362 El destino del reino
-- https://es.classic.wowhead.com/quest=4362
SET @ID := 4362;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La princesa Barbabronce llora la muerte del emperador Dagran Thaurissan.>$B$B¡¿Por qué?!', 0),
(@ID, 'esMX', '<La princesa Barbabronce llora la muerte del emperador Dagran Thaurissan.>$B$B¡¿Por qué?!', 0);
-- 4363 La sorpresa de la princesa
-- https://es.classic.wowhead.com/quest=4363
SET @ID := 4363;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Rey Magni Barbabronce está claramente enojado.>$B$BParece que hasta en la muerte, Thaurissan es victorioso.$B$BPuedes retirarte, $n. Antes de marcharte puedes elegir tu recompensa de la cámara real.$B$B<El rey Barbabronce se desploma en su trono para reflexionar sobre este extraño cambio de acontecimientos>.', 0),
(@ID, 'esMX', '<El Rey Magni Barbabronce está claramente enojado.>$B$BParece que hasta en la muerte, Thaurissan es victorioso.$B$BPuedes retirarte, $n. Antes de marcharte puedes elegir tu recompensa de la cámara real.$B$B<El rey Barbabronce se desploma en su trono para reflexionar sobre este extraño cambio de acontecimientos>.', 0);
-- 4381 El cristal de restauración
-- https://es.classic.wowhead.com/quest=4381
SET @ID := 4381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder verdes y amarillos.$B$BSegún el manual de J.D., esta combinación puede usarse para curarte a ti mismo o a tus aliados.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder verdes y amarillos.$B$BSegún el manual de J.D., esta combinación puede usarse para curarte a ti mismo o a tus aliados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0);
-- 4382 La fuerza de cristal
-- https://es.classic.wowhead.com/quest=4382
SET @ID := 4382;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder verdes y azules.$B$BSegún el manual de J.D., esta combinación puede usarse para aumentar tu espíritu.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder verdes y azules.$B$BSegún el manual de J.D., esta combinación puede usarse para aumentar tu espíritu.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0);
-- 4383 Resguardo de cristal
-- https://es.classic.wowhead.com/quest=4383
SET @ID := 4383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder verdes y rojos.$B$BSegún el manual de J.D., esta combinación se puede utilizar para mejorar la protección que contra el daño físico.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder verdes y rojos.$B$BSegún el manual de J.D., esta combinación se puede utilizar para mejorar la protección que contra el daño físico.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0);
-- 4384 Reducción de cristal
-- https://es.classic.wowhead.com/quest=4384
SET @ID := 4384;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder rojos y azules.$B$BSegún el manual de J.D., esta combinación se puede utilizar para debilitar las defensas de un enemigo.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder rojos y azules.$B$BSegún el manual de J.D., esta combinación se puede utilizar para debilitar las defensas de un enemigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales en la mesa y alineas cuidadosamente los colores. Mientras empujas el último en su lugar, un estallido de luz fusiona los cristales.$B$BLa combinación resultante ahora es tuya.', 0);
-- 4385 Carga de cristal
-- https://es.classic.wowhead.com/quest=4385
SET @ID := 4385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder rojos y amarillos.$B$BDe acuerdo con el manual de J.D. puedes utilizar esta combinación para crear una gran explosión que puede infligir daño a tus enemigos.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder rojos y amarillos.$B$BDe acuerdo con el manual de J.D. puedes utilizar esta combinación para crear una gran explosión que puede infligir daño a tus enemigos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales sobre la tabla y alineas con cuidado los colores. Cuando colocas el último un estallido de luz funde todos los cristales.$B$BLa combinación resultante es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales sobre la tabla y alineas con cuidado los colores. Cuando colocas el último un estallido de luz funde todos los cristales.$B$BLa combinación resultante es tuya.', 0);
-- 4386 Aguja de cristal
-- https://es.classic.wowhead.com/quest=4386
SET @ID := 4386;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tabla de la torre te permite combinar cristales de poder azules y amarillos.$B$BDe acuerdo con el manual de J.D. puedes utilizar esta combinación para crear un escudo que causará daño a tus enemigos.', 0),
(@ID, 'esMX', 'La tabla de la torre te permite combinar cristales de poder azules y amarillos.$B$BDe acuerdo con el manual de J.D. puedes utilizar esta combinación para crear un escudo que causará daño a tus enemigos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los cristales sobre la tabla y alineas con cuidado los colores. Cuando colocas el último un estallido de luz funde todos los cristales.$B$BLa combinación resultante es tuya.', 0),
(@ID, 'esMX', 'Colocas los cristales sobre la tabla y alineas con cuidado los colores. Cuando colocas el último un estallido de luz funde todos los cristales.$B$BLa combinación resultante es tuya.', 0);
-- 4402 Sorpresa de manzanas de cactus de Galgar
-- https://es.classic.wowhead.com/quest=4402
SET @ID := 4402;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado de recoger manzanas de cactus?', 0),
(@ID, 'esMX', '¿Has terminado de recoger manzanas de cactus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, $n! Como te prometí, toma una sorpresa de manzana de cactus... y algo más.', 0),
(@ID, 'esMX', '¡Fantástico, $n! Como te prometí, toma una sorpresa de manzana de cactus... y algo más.', 0);
-- 4441 Los Ancestros corrompidos
-- https://es.classic.wowhead.com/quest=4441
SET @ID := 4441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con suerte, el agua liberará el espíritu del Ancestro y este podrá encontrar la paz.', 0),
(@ID, 'esMX', 'Con suerte, el agua liberará el espíritu del Ancestro y este podrá encontrar la paz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ahora debemos rezar por que podamos reparar el daño que se ha hecho...', 0),
(@ID, 'esMX', 'Gracias, $n. Ahora debemos rezar por que podamos reparar el daño que se ha hecho...', 0);
-- 4442 ¡Purificada!
-- https://es.classic.wowhead.com/quest=4442
SET @ID := 4442;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con el agua bendita logré romper el vínculo entre la flauta y el espíritu. Pero creo que, si utilizaras esta flauta en un lugar sagrado, podrías invocar a los espíritus de los Ancestros.$B$BPodrías probar en las ruinas que hay en la zona sur del Bosque de Troncoferro. Hubo un tiempo en que esa zona estaba habitada por antárboles corruptos. Quizás aún residan allí, en forma de espíritu.', 0),
(@ID, 'esMX', 'Con el agua bendita logré romper el vínculo entre la flauta y el espíritu. Pero creo que, si utilizaras esta flauta en un lugar sagrado, podrías invocar a los espíritus de los Ancestros.$B$BPodrías probar en las ruinas que hay en la zona sur del Bosque de Troncoferro. Hubo un tiempo en que esa zona estaba habitada por antárboles corruptos. Quizás aún residan allí, en forma de espíritu.', 0);
-- 4449 Atrapado
-- https://es.classic.wowhead.com/quest=4449
SET @ID := 4449;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que no tengo todo el día! Tráeme la seda, digo mata a los geólogos. Que sientan el peso de mi ira. Bueno, de la tuya.', 0),
(@ID, 'esMX', '¡Que no tengo todo el día! Tráeme la seda, digo mata a los geólogos. Que sientan el peso de mi ira. Bueno, de la tuya.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué tacto tan suave!$B$B¿Qué? Ah, sí, los geólogos... ¿Has acabado con ellos? Gracias, $n. Ahora tendré tiempo de acabar.', 0),
(@ID, 'esMX', '¡Qué tacto tan suave!$B$B¿Qué? Ah, sí, los geólogos... ¿Has acabado con ellos? Gracias, $n. Ahora tendré tiempo de acabar.', 0);
-- 4450 El libro de contabilidad de Tanaris
-- https://es.classic.wowhead.com/quest=4450
SET @ID := 4450;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo, $r? Lo siento, pero tengo mucho trabajo, así que no te lo tomes a mal, pero ve al grano.', 0),
(@ID, 'esMX', '¿Querías algo, $r? Lo siento, pero tengo mucho trabajo, así que no te lo tomes a mal, pero ve al grano.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, así que te has dignado hacer algo de lo que pedí. Excelente; pensaba que ibas a pedirme algo.$B$BPerfecto; está todo aquí. Gracias, $c.$B$BVoy a darte una recompensa, algo práctico que vayas a usar.', 0),
(@ID, 'esMX', 'Vaya, así que te has dignado hacer algo de lo que pedí. Excelente; pensaba que ibas a pedirme algo.$B$BPerfecto; está todo aquí. Gracias, $c.$B$BVoy a darte una recompensa, algo práctico que vayas a usar.', 0);
-- 4451 La llave de la libertad
-- https://es.classic.wowhead.com/quest=4451
SET @ID := 4451;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tose>$B$B¿Quién es? ¿No ves que tengo trabajo?', 0),
(@ID, 'esMX', '<Tose>$B$B¿Quién es? ¿No ves que tengo trabajo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes la llave! ¡Sabía que la habían escondido, malditos Hierro Negro! Gracias, $n, ¡eres genial! Bueno, ¡gira la llave y déjame salir!', 0),
(@ID, 'esMX', '¡Tienes la llave! ¡Sabía que la habían escondido, malditos Hierro Negro! Gracias, $n, ¡eres genial! Bueno, ¡gira la llave y déjame salir!', 0);
-- 4463 Tratado sobre Reflexión
-- https://es.classic.wowhead.com/quest=4463
SET @ID := 4463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Presenta los componentes, mortal.$B$BTambién exigiré un pago en forma de treinta piezas de oro por esta creación.', 0),
(@ID, 'esMX', 'Presenta los componentes, mortal.$B$BTambién exigiré un pago en forma de treinta piezas de oro por esta creación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma tu abalorio, tonto. ¡Déjame con mis estudios!', 0),
(@ID, 'esMX', 'Toma tu abalorio, tonto. ¡Déjame con mis estudios!', 0);
-- 4481 Tratado sobre Constitución
-- https://es.classic.wowhead.com/quest=4481
SET @ID := 4481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay un precio que pagar por todas las cosas de este mundo. El precio del artículo específico que busca es de treinta piezas de oro.$B$BNaturalmente, conservaré la mayoría de los componentes que has reunido. Pero no te preocupes, tendrás tu abalorio.', 0),
(@ID, 'esMX', 'Hay un precio que pagar por todas las cosas de este mundo. El precio del artículo específico que busca es de treinta piezas de oro.$B$BNaturalmente, conservaré la mayoría de los componentes que has reunido. Pero no te preocupes, tendrás tu abalorio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una desgracia para su memoria... un mortal, como tú, terminando el trabajo de su vida.$B$B¡Toma tu amalgama y vete!', 0),
(@ID, 'esMX', 'Es una desgracia para su memoria... un mortal, como tú, terminando el trabajo de su vida.$B$B¡Toma tu amalgama y vete!', 0);
