-- 11146 Captor de raptores
-- https://es.wowhead.com/quest=11146
SET @ID := 11146;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Capturaste esas raptores?', 0),
(@ID, 'esMX', '¿Capturaste esas raptores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces un poco arañado, pero nada importante. Ciertamente estás en mejor forma que los Tótem Siniestro cuando nuestros nuevos amigos raptores terminen con ellos.', 0),
(@ID, 'esMX', 'Pareces un poco arañado, pero nada importante. Ciertamente estás en mejor forma que los Tótem Siniestro cuando nuestros nuevos amigos raptores terminen con ellos.', 0);
-- 1324 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1324
SET @ID := 1324;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Espero que no te importe la ayuda, pero no podemos permitir que Hendel se escape o, peor aún, acabe muerto.', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Espero que no te importe la ayuda, pero no podemos permitir que Hendel se escape o, peor aún, acabe muerto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo aseguro, todos estamos bastante disgustados por los sucesos recientes, pero permite que le llevemos a Theramore para interrogarle a ver si conseguimos información sobre el rey.$B$BSeguro que Lady Valiente querría agradecerte tu ayuda. Habla con ella cuando tengas un momento.', 0),
(@ID, 'esMX', 'Te lo aseguro, todos estamos bastante disgustados por los sucesos recientes, pero permite que le llevemos a Theramore para interrogarle a ver si conseguimos información sobre el rey.$B$BSeguro que Lady Valiente querría agradecerte tu ayuda. Habla con ella cuando tengas un momento.', 0);
-- 11145 Prisioneros de los Tótem Siniestro
-- https://es.wowhead.com/quest=11145
SET @ID := 11145;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste liberar a los cautivos en el Poblado Pezuñanegra?', 0),
(@ID, 'esMX', '¿Conseguiste liberar a los cautivos en el Poblado Pezuñanegra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los cautivos liberados ya han comenzado a regresar del Poblado Pezuñanegra. La información que el capitán está recibiendo de los prisioneros nos dará una ventaja en nuestra próxima batalla contra los Tótem Siniestro.$B$BTienes mi agradecimiento y el de los hombres.', 0),
(@ID, 'esMX', 'Los cautivos liberados ya han comenzado a regresar del Poblado Pezuñanegra. La información que el capitán está recibiendo de los prisioneros nos dará una ventaja en nuestra próxima batalla contra los Tótem Siniestro.$B$BTienes mi agradecimiento y el de los hombres.', 0);
-- 1220 Capitán Vimes
-- https://es.classic.wowhead.com/quest=1220
SET @ID := 1220;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un informe de un espía orco! ¿Cómo lo encontraste? No importa. Veamos lo que dice...', 0),
(@ID, 'esMX', '¡Un informe de un espía orco! ¿Cómo lo encontraste? No importa. Veamos lo que dice...', 0);
-- 1267 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1267
SET @ID := 1267;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Primero, quiero darte las gracias por todo lo que has hecho, $n. Has sido una increíble bendición para todos los míos y para todo el pueblo de Ventormenta. Siento no haber podido conocerte en mejores circunstancias.$B$BEspero que comprendas que no puedo darte las gracias abiertamente, pero te aseguro, que lo aprecio mucho.$B$BCuando vengas a Theramore en el futuro, búscame e intentaré compensarte.$B$BGracias de nuevo, $n.', 0),
(@ID, 'esMX', 'Primero, quiero darte las gracias por todo lo que has hecho, $n. Has sido una increíble bendición para todos los míos y para todo el pueblo de Ventormenta. Siento no haber podido conocerte en mejores circunstancias.$B$BEspero que comprendas que no puedo darte las gracias abiertamente, pero te aseguro, que lo aprecio mucho.$B$BCuando vengas a Theramore en el futuro, búscame e intentaré compensarte.$B$BGracias de nuevo, $n.', 0);
-- 11139 Equipo de buceo de segunda mano
-- https://es.wowhead.com/quest=11139
SET @ID := 11139;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veamos qué has conseguido "pedir prestado" a los Defias.', 0),
(@ID, 'esMX', 'Veamos qué has conseguido "pedir prestado" a los Defias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, esto está en peor estado de lo que pensaba, y estas herramientas ...$B$BBueno, dije que volvería a poner esto en funcionamiento, así que será mejor que me ponga a trabajar.', 0),
(@ID, 'esMX', 'Vaya, esto está en peor estado de lo que pensaba, y estas herramientas ...$B$BBueno, dije que volvería a poner esto en funcionamiento, así que será mejor que me ponga a trabajar.', 0);
-- 11140 ¡Recupera la mercancía!
-- https://es.wowhead.com/quest=11140
SET @ID := 11140;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La búsqueda de restos reveló algo sobre la carga de los Defias?', 0),
(@ID, 'esMX', '¿La búsqueda de restos reveló algo sobre la carga de los Defias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renn revisa el contenido de las cajas fuertes que recuperaste.>$B$BBuen trabajo. Ahora, veamos si nuestro "precioso cargamento" está aquí...', 0),
(@ID, 'esMX', '<Renn revisa el contenido de las cajas fuertes que recuperaste.>$B$BBuen trabajo. Ahora, veamos si nuestro "precioso cargamento" está aquí...', 0);
-- 11141 Jaina debe saberlo
-- https://es.wowhead.com/quest=11141
SET @ID := 11141;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Renn y tú habéis hecho un trabajo excelente para sacar a la luz esta información y comunicarla de inmediato. Ahora, debemos confirmar los hallazgos. Las implicaciones son demasiado grandes si nos equivocamos.', 0),
(@ID, 'esMX', 'Renn y tú habéis hecho un trabajo excelente para sacar a la luz esta información y comunicarla de inmediato. Ahora, debemos confirmar los hallazgos. Las implicaciones son demasiado grandes si nos equivocamos.', 0);
-- 11142 Inspecciona la Isla de Alcaz
-- https://es.wowhead.com/quest=11142
SET @ID := 11142;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lady Jaina escucha atentamente mientras informas los resultados de tu reconocimiento aéreo.>$B$B¿Un círculo de runas, dragonkin? ¿Los Defia se han aliado con ELLA? ¿El traidor?$B$B<Lady Jaina se recompone y se prepara para explicar.>', 0),
(@ID, 'esMX', '<Lady Jaina escucha atentamente mientras informas los resultados de tu reconocimiento aéreo.>$B$B¿Un círculo de runas, dragonkin? ¿Los Defia se han aliado con ELLA? ¿El traidor?$B$B<Lady Jaina se recompone y se prepara para explicar.>', 0);
-- 1222 La fuga de Apestoso
-- https://es.classic.wowhead.com/quest=1222
SET @ID := 1222;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha visto al Sr. Ignatz? ¡Lo envié al pantano hace algún tiempo y no ha regresado!', 0),
(@ID, 'esMX', '¿Ha visto al Sr. Ignatz? ¡Lo envié al pantano hace algún tiempo y no ha regresado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El señor Ignatz ha estado aquí con las hojas de cienagrana y me dijo que le habías ayudado a salir de un auténtico atolladero.$B$BTe lo agradezco, $n. Pediré a mi tío que te invite a un festín la próxima vez que vayas a El Ermitaño Azul de Ventormenta.', 0),
(@ID, 'esMX', 'El señor Ignatz ha estado aquí con las hojas de cienagrana y me dijo que le habías ayudado a salir de un auténtico atolladero.$B$BTe lo agradezco, $n. Pediré a mi tío que te invite a un festín la próxima vez que vayas a El Ermitaño Azul de Ventormenta.', 0);
-- 1252 Teniente Paval Reethe
-- https://es.classic.wowhead.com/quest=1252
SET @ID := 1252;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algo de interés en la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Has encontrado algo de interés en la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando me traen la insignia de un guardia, nunca viene acompañada de buenas noticias.$B$BA veces, me la traen porque un hombre o una mujer ha muerto en combate. Y yo tengo que comunicar la noticia a su familia. Otras veces no se sabe ni qué fue de quien portaba la insignia. Y en ocasiones... es peor que todo lo anterior.', 0),
(@ID, 'esMX', 'Cuando me traen la insignia de un guardia, nunca viene acompañada de buenas noticias.$B$BA veces, me la traen porque un hombre o una mujer ha muerto en combate. Y yo tengo que comunicar la noticia a su familia. Otras veces no se sabe ni qué fue de quien portaba la insignia. Y en ocasiones... es peor que todo lo anterior.', 0);
-- 1253 El escudo negro
-- https://es.classic.wowhead.com/quest=1253
SET @ID := 1253;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algo en la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Has encontrado algo en la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, no soy un experto en la creación de armas y armaduras. En su uso, sí, pero no en su fabricación.$B$BEste escudo parece tan normal como cualquiera, exceptuando el daño que le causó el fuego de la posada.', 0),
(@ID, 'esMX', 'Mm, no soy un experto en la creación de armas y armaduras. En su uso, sí, pero no en su fabricación.$B$BEste escudo parece tan normal como cualquiera, exceptuando el daño que le causó el fuego de la posada.', 0);
-- 1284 Huellas de pezuñas sospechosas
-- https://es.classic.wowhead.com/quest=1284
SET @ID := 1284;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Huellas de pezuñas, ¿eh? Es verdad que los centauros están desplegando una actividad extraordinaria en las tierras cercanas al Marjal Revolcafango. En cortas excursiones a Los Baldíos, encontramos sus campamentos y sus propiedades, estaban por toda la zona.$B$BEnviaré a Falgran Hastil, uno de nuestros rastreadores, a ver si puede averiguar a dónde conducen las huellas.', 0),
(@ID, 'esMX', 'Huellas de pezuñas, ¿eh? Es verdad que los centauros están desplegando una actividad extraordinaria en las tierras cercanas al Marjal Revolcafango. En cortas excursiones a Los Baldíos, encontramos sus campamentos y sus propiedades, estaban por toda la zona.$B$BEnviaré a Falgran Hastil, uno de nuestros rastreadores, a ver si puede averiguar a dónde conducen las huellas.', 0);
-- https://es.wowhead.com/quest=11156
SET @ID := 11156;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho algún progreso para detener los ataques de Tótem Siniestro?', 0),
(@ID, 'esMX', '¿Has hecho algún progreso para detener los ataques de Tótem Siniestro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz Morlann asiente.>$B$BBueno. No puedo decir que extrañaré la compañía, si puedes llamarlo así. Pensarías que al menos en medio del pantano obtendrías algo de privacidad, ¿sabes?', 0),
(@ID, 'esMX', '<El aprendiz Morlann asiente.>$B$BBueno. No puedo decir que extrañaré la compañía, si puedes llamarlo así. Pensarías que al menos en medio del pantano obtendrías algo de privacidad, ¿sabes?', 0);
-- 11172 El accidente del zepelín
-- https://es.wowhead.com/quest=11172
SET @ID := 11172;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces te enviaron esos magos ermitaños? ¿Cómo puedo estar seguro de que puedo confiar en ti?$B$BSupongo que puedo usar la ayuda. De todos modos, no hay mucho que le interese a un mago.', 0),
(@ID, 'esMX', '¿Entonces te enviaron esos magos ermitaños? ¿Cómo puedo estar seguro de que puedo confiar en ti?$B$BSupongo que puedo usar la ayuda. De todos modos, no hay mucho que le interese a un mago.', 0);
-- 2846 Tiara de las profundidades
-- https://es.classic.wowhead.com/quest=2846
SET @ID := 2846;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la tiara, $n? ¿Ha aprendido ya Velratha cuál es el precio de contrariarme?', 0),
(@ID, 'esMX', '¿Tienes la tiara, $n? ¿Ha aprendido ya Velratha cuál es el precio de contrariarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! ¡La encontraste! Y lo que es más importante... ¡Velratha ya no la tiene! Gracias, $n. ¡Te estaré siempre en deuda!$B$BY si antes te pareció que tenía algo de mal humor... no hagas caso. Verás que soy mucho más agradable con aquellos que no me han robado nada.', 0),
(@ID, 'esMX', '¡Maravilloso! ¡La encontraste! Y lo que es más importante... ¡Velratha ya no la tiene! Gracias, $n. ¡Te estaré siempre en deuda!$B$BY si antes te pareció que tenía algo de mal humor... no hagas caso. Verás que soy mucho más agradable con aquellos que no me han robado nada.', 0);
-- 11169 El arma Tótem Siniestro
-- https://es.wowhead.com/quest=11169
SET @ID := 11169;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte probando el tótem?', 0),
(@ID, 'esMX', '¿Has tenido suerte probando el tótem?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz escucha mientras describe su experimento.>$B$B¿Una bruma y un rayo? ¿Eso es? ¡Tiene que haber más en el tótem que solo eso! No es probable que los Tótem Siniestro traigan algo como esto al campo de batalla a menos que tenga algún tipo de utilidad.', 0),
(@ID, 'esMX', '<El aprendiz escucha mientras describe su experimento.>$B$B¿Una bruma y un rayo? ¿Eso es? ¡Tiene que haber más en el tótem que solo eso! No es probable que los Tótem Siniestro traigan algo como esto al campo de batalla a menos que tenga algún tipo de utilidad.', 0);
-- 11173 El ladrón de componentes
-- https://es.wowhead.com/quest=11173
SET @ID := 11173;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste ese veneno? Morlann va a descubrir que no está en cualquier momento ...', 0),
(@ID, 'esMX', '¿Conseguiste ese veneno? Morlann va a descubrir que no está en cualquier momento ...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz Garion inspecciona el veneno.>$B$B¡Esto es absolutamente perfecto! Él nunca notará la diferencia.', 0),
(@ID, 'esMX', '<El aprendiz Garion inspecciona el veneno.>$B$B¡Esto es absolutamente perfecto! Él nunca notará la diferencia.', 0);
-- 11174 Prevención contra la corrosión
-- https://es.wowhead.com/quest=11174
SET @ID := 11174;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hiciste algún progreso contra esos mocos?', 0),
(@ID, 'esMX', '¿Hiciste algún progreso contra esos mocos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, parece un poco más limpio ahí fuera ...$B$BSupongo que es hora de poner manos a la obra de rescatar estos restos.', 0),
(@ID, 'esMX', 'Bueno, parece un poco más limpio ahí fuera ...$B$BSupongo que es hora de poner manos a la obra de rescatar estos restos.', 0);
-- 11207 ¡Asegura el cargamento!
-- https://es.wowhead.com/quest=11207
SET @ID := 11207;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Moxie parece frenética de preocupación.>$B$B¿Sobrevivió la carga? ¿Encontraste algo de eso?', 0),
(@ID, 'esMX', '<Moxie parece frenética de preocupación.>$B$B¿Sobrevivió la carga? ¿Encontraste algo de eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guauu! Ciertamente, has encontrado mucho más de lo que esperaba. No estoy segura de cuánto pensó Drazzit que íbamos a recuperar aquí, pero tendrá que estar contento con esto por ahora.', 0),
(@ID, 'esMX', '¡Guauu! Ciertamente, has encontrado mucho más de lo que esperaba. No estoy segura de cuánto pensó Drazzit que íbamos a recuperar aquí, pero tendrá que estar contento con esto por ahora.', 0);
-- 11208 Envío para Drazzit
-- https://es.wowhead.com/quest=11208
-- https://wow-es.gamepedia.com/Misión:Envío para Drazzit
SET @ID := 11208;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Si?', 0),
(@ID, 'esMX', '¿Si?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Drazzit coge el cargamento.>$B$B¡Estoy tan hambriento que podría comerme un dragón! Menos mal que Moxie trajo parte del cargamento. ¡Nos hemos visto obligados a apostar a los dados contra el ogro para conseguir lo que hubiera matado en sus cacerías!', 0),
(@ID, 'esMX', '<Drazzit coge el cargamento.>$B$B¡Estoy tan hambriento que podría comerme un dragón! Menos mal que Moxie trajo parte del cargamento. ¡Nos hemos visto obligados a apostar a los dados contra el ogro para conseguir lo que hubiera matado en sus cacerías!', 0);
