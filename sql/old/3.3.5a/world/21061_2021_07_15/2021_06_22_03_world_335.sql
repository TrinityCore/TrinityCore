-- 10302 Mutaciones volátiles
-- https://es.wowhead.com/quest=10302
SET @ID := 10302;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy trabajando en una solución que creo que puede ser eficaz con esas extrañas criaturas. Solo necesito más tiempo.', 0),
(@ID, 'esMX', 'Estoy trabajando en una solución que creo que puede ser eficaz con esas extrañas criaturas. Solo necesito más tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado? Es una buena noticia. Con un poco de suerte encontraremos una forma de evitar la matanza de estas bestias mutantes en el futuro.$B$BTengo un plan que quizás nos dé una solución alternativa para este problema pero voy a necesitar tu ayuda.', 0),
(@ID, 'esMX', '¿Has acabado? Es una buena noticia. Con un poco de suerte encontraremos una forma de evitar la matanza de estas bestias mutantes en el futuro.$B$BTengo un plan que quizás nos dé una solución alternativa para este problema pero voy a necesitar tu ayuda.', 0);
-- 10303 Los elfos de sangre
-- https://es.wowhead.com/quest=10303
SET @ID := 10303;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay demasiados... Debemos reducir su número, o de lo contrario, los supervivientes no tendrán ninguna posibilidad contra ellos.', 0),
(@ID, 'esMX', 'Hay demasiados... Debemos reducir su número, o de lo contrario, los supervivientes no tendrán ninguna posibilidad contra ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos elfos de sangre quieren matarnos a todos. ¿Qué podemos hacer para impedirlo?', 0),
(@ID, 'esMX', 'Esos elfos de sangre quieren matarnos a todos. ¿Qué podemos hacer para impedirlo?', 0);
-- 10304 El vindicador Aldar
-- https://es.wowhead.com/quest=10304
SET @ID := 10304;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿verdad? He escuchado cosas buenas sobre ti y el trabajo que has estado haciendo en el poco tiempo desde que volviste.$B$BDefinitivamente necesitaremos tu ayuda para que todo vuelva a la normalidad. A Zhanaa, que está allí, también le vendría bien tu ayuda, estoy seguro.', 0),
(@ID, 'esMX', '$n, ¿verdad? He escuchado cosas buenas sobre ti y el trabajo que has estado haciendo en el poco tiempo desde que volviste.$B$BDefinitivamente necesitaremos tu ayuda para que todo vuelva a la normalidad. A Zhanaa, que está allí, también le vendría bien tu ayuda, estoy seguro.', 0);
-- 10305 Abjuradora Belmara
-- https://es.wowhead.com/quest=10305
SET @ID := 10305;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Dar descanso al espíritu de Belmara', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Había oído que la Abjuradora Belmara tenía un viejo libro de cuentos, pero no sabía que se lo había llevado a Terrallende. Seguro que su espíritu podrá descansar ahora sabiendo que lo has encontrado y devuelto a su sitio.', 0),
(@ID, 'esMX', 'Ah, sí. Había oído que la Abjuradora Belmara tenía un viejo libro de cuentos, pero no sabía que se lo había llevado a Terrallende. Seguro que su espíritu podrá descansar ahora sabiendo que lo has encontrado y devuelto a su sitio.', 0);
-- 10306 Conjurador Luminrath
-- https://es.wowhead.com/quest=10306
SET @ID := 10306;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Dar descanso al espíritu de Luminrath', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre decíamos que Luminrath llevaba esa capa con todo. Para él, el rojo iba perfectamente con blanco, negro, púrpura, azul, amarillo, naranja y verde. Nunca llevaba la misma túnica dos días seguidos, pero esa capa...', 0),
(@ID, 'esMX', 'Siempre decíamos que Luminrath llevaba esa capa con todo. Para él, el rojo iba perfectamente con blanco, negro, púrpura, azul, amarillo, naranja y verde. Nunca llevaba la misma túnica dos días seguidos, pero esa capa...', 0);
-- 10307 Cohlien Tejescarcha
-- https://es.wowhead.com/quest=10307
SET @ID := 10307;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Dar descanso al espíritu de Cohlien', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El custodio sonríe ante la mención del nombre de Cohlien.>$B$BTienes mucha razón con lo del sombrero. Lo llevaba puesto todo el tiempo y nunca lo perdía de vista.$B$BUna vez, un mago de quien mejor no diremos el nombre, lo \'cogió prestado\' y lo escondió para gastarle una broma. No es necesario decir que la amenaza de uno de los rayos de hielo de Cohlien le hizo cambiar de idea rápidamente.$B$BVoy a echar de menos al pequeño Cohlien. Tenía un toque especial con las elfas.', 0),
(@ID, 'esMX', '<El custodio sonríe ante la mención del nombre de Cohlien.>$B$BTienes mucha razón con lo del sombrero. Lo llevaba puesto todo el tiempo y nunca lo perdía de vista.$B$BUna vez, un mago de quien mejor no diremos el nombre, lo \'cogió prestado\' y lo escondió para gastarle una broma. No es necesario decir que la amenaza de uno de los rayos de hielo de Cohlien le hizo cambiar de idea rápidamente.$B$BVoy a echar de menos al pequeño Cohlien. Tenía un toque especial con las elfas.', 0);
-- 10308 Otro montón de etéreos
-- https://es.wowhead.com/quest=10308
SET @ID := 10308;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Consorcio está muy interesado en acabar con todos los rebeldes Zaxxis en La Pila al sur.$B$B$n, si quieres congraciarte más con nosotros, vuelve allí y trae más de sus insignias de afiliación.', 0),
(@ID, 'esMX', 'El Consorcio está muy interesado en acabar con todos los rebeldes Zaxxis en La Pila al sur.$B$B$n, si quieres congraciarte más con nosotros, vuelve allí y trae más de sus insignias de afiliación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Traidores, todos!$B$B¡Buen trabajo, $n! Si encuentras el camino de regreso allí de nuevo, ¡siempre estoy ampliando mi colección de sus insignias!', 0),
(@ID, 'esMX', '¡Traidores, todos!$B$B¡Buen trabajo, $n! Si encuentras el camino de regreso allí de nuevo, ¡siempre estoy ampliando mi colección de sus insignias!', 0);
-- 10309 Es un atracador vil... pero con corazón
-- https://es.wowhead.com/quest=10309
SET @ID := 10309;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo de estar perdiendo la vista con toda la radiación que me rodea. ¿Tienes ya el corazón de atracador vil?', 0),
(@ID, 'esMX', 'Debo de estar perdiendo la vista con toda la radiación que me rodea. ¿Tienes ya el corazón de atracador vil?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, fíjate en esto... ¡un corazón de atracador vil que aún late! Bueno, no está "latiendo" de verdad, pero ya sabes a qué me refiero.$B$BMe muero por hacer algo de provecho con esto. O quizás venderlo. Conozco a un par de imb... eh, clientes que podrían estar interesados.$B$BToma, ¡te lo has ganado!', 0),
(@ID, 'esMX', 'Vaya, fíjate en esto... ¡un corazón de atracador vil que aún late! Bueno, no está "latiendo" de verdad, pero ya sabes a qué me refiero.$B$BMe muero por hacer algo de provecho con esto. O quizás venderlo. Conozco a un par de imb... eh, clientes que podrían estar interesados.$B$BToma, ¡te lo has ganado!', 0);
-- 10310 ¡Sabotead el portal de distorsión!
-- https://es.wowhead.com/quest=10310
SET @ID := 10310;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Como puedo ayudarte?', 0),
(@ID, 'esMX', '¿Como puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticia tan fantástica, $gamigo:amiga;!$B$BDrijya y tú nos han hecho un gran favor. Con el portal de distorsión fuera de juego, los demonios cercanos no recibirán más refuerzos.$B$BPermite que te recompense como es debido en el seno del Consorcio.', 0),
(@ID, 'esMX', '¡Qué noticia tan fantástica, $gamigo:amiga;!$B$BDrijya y tú nos han hecho un gran favor. Con el portal de distorsión fuera de juego, los demonios cercanos no recibirán más refuerzos.$B$BPermite que te recompense como es debido en el seno del Consorcio.', 0);
-- 10311 Drijya necesita tu ayuda
-- https://es.wowhead.com/quest=10311
SET @ID := 10311;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que Gahruj te haya enviado para ayudarme en mi misión.', 0),
(@ID, 'esMX', 'Espero que Gahruj te haya enviado para ayudarme en mi misión.', 0);
-- 10312 Las Crónicas de Kirin'Var
-- https://es.wowhead.com/quest=10312
SET @ID := 10312;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar el registro?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar el registro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Custodio Valemuerte acepta el registro y empieza a ojear las páginas.>$B$BMmm...$B$BPor lo visto, yo tenía razón. Hay una especie de patrón.$B$BLos fantasmas más agresivos y peligrosos coinciden con los miembros de mayor rango y más poderosos del Kirin Tor que residían en el poblado. Los habitantes locales y los comerciantes parecen menos amenazadores en comparación. ¿Qué podría significar esto?', 0),
(@ID, 'esMX', '<El Custodio Valemuerte acepta el registro y empieza a ojear las páginas.>$B$BMmm...$B$BPor lo visto, yo tenía razón. Hay una especie de patrón.$B$BLos fantasmas más agresivos y peligrosos coinciden con los miembros de mayor rango y más poderosos del Kirin Tor que residían en el poblado. Los habitantes locales y los comerciantes parecen menos amenazadores en comparación. ¿Qué podría significar esto?', 0);
-- 10313 Medir energías de distorsión
-- https://es.wowhead.com/quest=10313
SET @ID := 10313;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Medidas del conducto Norte tomadas', `ObjectiveText2` = 'Medidas del conducto Este tomadas', `ObjectiveText3` = 'Medidas del conducto Sur tomadas', `ObjectiveText4` = 'Medidas del conducto Oeste tomadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has realizado las medidas que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has realizado las medidas que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esas son muy malas noticias, $n. Las energías de distorsión que emanan de los conductos son peligrosamente altas.$B$BTenemos que encontrar el modo de cerrar esas forjas de maná o lo poco que queda de Terrallende volará en pedazos.', 0),
(@ID, 'esMX', 'Esas son muy malas noticias, $n. Las energías de distorsión que emanan de los conductos son peligrosamente altas.$B$BTenemos que encontrar el modo de cerrar esas forjas de maná o lo poco que queda de Terrallende volará en pedazos.', 0);
-- 10314 Una sospecha latente
-- https://es.wowhead.com/quest=10314
SET @ID := 10314;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto, $n?', 0),
(@ID, 'esMX', '¿Qué has descubierto, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Custodio Valemuerte examina los restos.>$B$BEl instrumento que has descrito suena a Foco nigromántico... Tenía que haber sabido que ningún aprendiz que se preciara se rebajaría a esto. Pensaba que su instrucción le impediría llegar tan lejos pero supongo que me ha demostrado lo contrario.', 0),
(@ID, 'esMX', '<El Custodio Valemuerte examina los restos.>$B$BEl instrumento que has descrito suena a Foco nigromántico... Tenía que haber sabido que ningún aprendiz que se preciara se rebajaría a esto. Pensaba que su instrucción le impediría llegar tan lejos pero supongo que me ha demostrado lo contrario.', 0);
-- 10315 Neutralizar a los abisálicos
-- https://es.wowhead.com/quest=10315
SET @ID := 10315;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuántos Abisálicos has logrado matar?', 0),
(@ID, 'esMX', '¿Cuántos Abisálicos has logrado matar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo lo que hagamos para que dejen de hacer lo que hacen en las forjas de maná será buena cosa.$B$BDesde luego, no parece que se pueda razonar con ellos. Y está claro que, sea lo que sea que planean sus jefes, han perdido el juicio.$B$BEspero que no te ofendas si te ofrezco pagarte con la moneda de tu reino en pago por tus servicios al Consorcio.', 0),
(@ID, 'esMX', 'Todo lo que hagamos para que dejen de hacer lo que hacen en las forjas de maná será buena cosa.$B$BDesde luego, no parece que se pueda razonar con ellos. Y está claro que, sea lo que sea que planean sus jefes, han perdido el juicio.$B$BEspero que no te ofendas si te ofrezco pagarte con la moneda de tu reino en pago por tus servicios al Consorcio.', 0);
-- 10316 En busca de pruebas
-- https://es.wowhead.com/quest=10316
SET @ID := 10316;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un orbe resplandeciente se encuentra en lo alto de un pedestal cuadrado. A primera vista, parece un repositorio de energía mágica pero ¿qué clase de energía y para qué?', 0),
(@ID, 'esMX', 'Un orbe resplandeciente se encuentra en lo alto de un pedestal cuadrado. A primera vista, parece un repositorio de energía mágica pero ¿qué clase de energía y para qué?', 0);
-- 10317 Tratar con el supervisor
-- https://es.wowhead.com/quest=10317
SET @ID := 10317;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El supervisor habla en voz baja.>$B$B¿Has venido a matarme? Vaya. Supongo que incluso los etéreos se equivocan a veces, ¿eh?$B$BCréeme, yo no soy el que buscas.', 0),
(@ID, 'esMX', '<El supervisor habla en voz baja.>$B$B¿Has venido a matarme? Vaya. Supongo que incluso los etéreos se equivocan a veces, ¿eh?$B$BCréeme, yo no soy el que buscas.', 0);
-- 10318 Conversaciones con el maestro Supremo
-- https://es.wowhead.com/quest=10318
SET @ID := 10318;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes de la Forja de Maná Ara? ¿Trataste con el Supervisor Ocaso?', 0),
(@ID, 'esMX', '¿Qué noticias traes de la Forja de Maná Ara? ¿Trataste con el Supervisor Ocaso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un maestro supremo guardia apocalíptico? ¡Qué raro! ¿Qué está haciendo aquí la Legión Ardiente?$B$BAsí que algunos elfos de sangre han desertado. Es un dato a tener en cuenta si decidimos tomar el lugar por la fuerza. Bueno, al menos eso es una buena noticia, ¿no?$B$BTen, $n, acepta esto en prueba de mi gratitud.', 0),
(@ID, 'esMX', '¿Un maestro supremo guardia apocalíptico? ¡Qué raro! ¿Qué está haciendo aquí la Legión Ardiente?$B$BAsí que algunos elfos de sangre han desertado. Es un dato a tener en cuenta si decidimos tomar el lugar por la fuerza. Bueno, al menos eso es una buena noticia, ¿no?$B$BTen, $n, acepta esto en prueba de mi gratitud.', 0);
-- 10319 Captura de la filacteria
-- https://es.wowhead.com/quest=10319
SET @ID := 10319;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes que conseguir la Filacteria de Naberius para que podamos atacarle. De no ser así, será invulnerable.', 0),
(@ID, 'esMX', 'Tienes que conseguir la Filacteria de Naberius para que podamos atacarle. De no ser así, será invulnerable.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. La filacteria será la llave de nuestra victoria. Cuando entres en combate con Naberius, la aplastaré haciendo que quede expuesto a tus ataques.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. La filacteria será la llave de nuestra victoria. Cuando entres en combate con Naberius, la aplastaré haciendo que quede expuesto a tus ataques.', 0);
-- 10320 ¡Destruir a Naberius!
-- https://es.wowhead.com/quest=10320
SET @ID := 10320;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has destruido ese miserable exánime de Naberius?', 0),
(@ID, 'esMX', '¿Has destruido ese miserable exánime de Naberius?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La derrota de Naberius es un gran logro, $n. No puedo evitar pensar que habríamos tenido una oportunidad contra las tropas de Kael\'thas si la lealtad del aprendiz hubiera sido como debía ser aquel día.', 0),
(@ID, 'esMX', 'La derrota de Naberius es un gran logro, $n. No puedo evitar pensar que habríamos tenido una oportunidad contra las tropas de Kael\'thas si la lealtad del aprendiz hubiera sido como debía ser aquel día.', 0);
-- 10321 El cierre de la Forja de Maná Coruu
-- https://es.wowhead.com/quest=10321
SET @ID := 10321;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Coruu cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado ya la tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado ya la tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excelente. Solo quedan dos forjas de maná activas.$B$BPronto, Kael\'thas perderá su principal fuente de energía.', 0),
(@ID, 'esMX', 'Un trabajo excelente. Solo quedan dos forjas de maná activas.$B$BPronto, Kael\'thas perderá su principal fuente de energía.', 0);
-- 10322 El cierre de la Forja de Maná Duro
-- https://es.wowhead.com/quest=10322
SET @ID := 10322;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Duro cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado ya la tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado ya la tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes la bendición de los naaru, $n. Tu dedicación a la causa no pasará desapercibida ni se quedará sin recompensa.', 0),
(@ID, 'esMX', 'Tienes la bendición de los naaru, $n. Tu dedicación a la causa no pasará desapercibida ni se quedará sin recompensa.', 0);
-- 10323 El cierre de la Forja de Maná Ara
-- https://es.wowhead.com/quest=10323
SET @ID := 10323;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Ara cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te encargué, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te encargué, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Legión Ardiente? ¿Se han aliado con Kael\'thas Caminante del Sol?$B$BMalas noticias. Aunque explica mucho sobre lo que hemos visto aquí y en Sombraluna.$B$BDebemos informar a la Ciudad de Shattrath inmediatamente.', 0),
(@ID, 'esMX', '¿La Legión Ardiente? ¿Se han aliado con Kael\'thas Caminante del Sol?$B$BMalas noticias. Aunque explica mucho sobre lo que hemos visto aquí y en Sombraluna.$B$BDebemos informar a la Ciudad de Shattrath inmediatamente.', 0);
-- 10324 La gran cacería lunar
-- https://es.wowhead.com/quest=10324
SET @ID := 10324;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las pieles de los ciervos son tupidas y resistentes, con lo que su carne es muy dura, prácticamente incomible. Pero nos vale para otros propósitos.', 0),
(@ID, 'esMX', 'Las pieles de los ciervos son tupidas y resistentes, con lo que su carne es muy dura, prácticamente incomible. Pero nos vale para otros propósitos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! Te estás convirtiendo en $gun:una; gran $gcazador:cazadora;, $n.$B$B¿Te gustaría parecerte más a mí? ¡Pues puedes hacerlo! Cuando estabas cazando, hice estos objetos con algunas pieles que tenía por aquí. ¡Elige uno!', 0),
(@ID, 'esMX', '¡Maravilloso! Te estás convirtiendo en $gun:una; gran $gcazador:cazadora;, $n.$B$B¿Te gustaría parecerte más a mí? ¡Pues puedes hacerlo! Cuando estabas cazando, hice estos objetos con algunas pieles que tenía por aquí. ¡Elige uno!', 0);
-- 10325 Marcas de Kil'jaeden
-- https://es.wowhead.com/quest=10325
SET @ID := 10325;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Llevas alguna de las insignias de nuestros enemigos, $n?', 0),
(@ID, 'esMX', '¿Llevas alguna de las insignias de nuestros enemigos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enfrentarse a los demonios de la Legión Ardiente y los cultistas locos que los adoran no es poca cosa, $n. Has demostrado una gran dedicación y coraje. Sigue así y tu fama entre los Aldor seguirá creciendo.', 0),
(@ID, 'esMX', 'Enfrentarse a los demonios de la Legión Ardiente y los cultistas locos que los adoran no es poca cosa, $n. Has demostrado una gran dedicación y coraje. Sigue así y tu fama entre los Aldor seguirá creciendo.', 0);
-- 10326 Más marcas de Kil'jaeden
-- https://es.wowhead.com/quest=10326
SET @ID := 10326;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes más insignias de nuestros enemigos, $n? La Legión Ardiente sigue siendo una amenaza y seguimos persiguiéndoles dondequiera que los encontremos.', 0),
(@ID, 'esMX', '¿Tienes más insignias de nuestros enemigos, $n? La Legión Ardiente sigue siendo una amenaza y seguimos persiguiéndoles dondequiera que los encontremos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Continúas demostrando tu valía, $n. Lucha contra los enemigos de la Luz dondequiera que los encuentres; tus acciones serán bien recompensadas.', 0),
(@ID, 'esMX', 'Continúas demostrando tu valía, $n. Lucha contra los enemigos de la Luz dondequiera que los encuentres; tus acciones serán bien recompensadas.', 0);
-- 10327 Marca de Kil'jaeden única
-- https://es.wowhead.com/quest=10327
SET @ID := 10327;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0),
(@ID, 'esMX', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigues demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(@ID, 'esMX', 'Sigues demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0);
-- 10328 Informes Furia del Sol
-- https://es.wowhead.com/quest=10328
SET @ID := 10328;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte con los informes de la Forja de Maná Duro?', 0),
(@ID, 'esMX', '¿Has tenido suerte con los informes de la Forja de Maná Duro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trabajo excelente, $n! Veamos lo que podemos descubrir en estos informes.', 0),
(@ID, 'esMX', '¡Un trabajo excelente, $n! Veamos lo que podemos descubrir en estos informes.', 0);
-- 10329 El cierre de la Forja de Maná B'naar
-- https://es.wowhead.com/quest=10329
SET @ID := 10329;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná B\'naar cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha funcionado el plan? No tenía muy claro que acabases bien...', 0),
(@ID, 'esMX', '¿Ha funcionado el plan? No tenía muy claro que acabases bien...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por supuesto que funcionó! Soy un maestro espía; mi información siempre es precisa.$B$BDe todas maneras, tengo un fantástico trabajillo para encargarte. ¿Quieres que te explique de qué se trata? Claro que sí.', 0),
(@ID, 'esMX', '¡Por supuesto que funcionó! Soy un maestro espía; mi información siempre es precisa.$B$BDe todas maneras, tengo un fantástico trabajillo para encargarte. ¿Quieres que te explique de qué se trata? Claro que sí.', 0);
-- 10330 El cierre de la Forja de Maná Coruu
-- https://es.wowhead.com/quest=10330
SET @ID := 10330;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Coruu cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado ya la tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado ya la tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oímos la gran conmoción y estábamos a punto de irnos. Nos alegramos de ver que no has salido demasiado mal $gparado:parada;.', 0),
(@ID, 'esMX', 'Oímos la gran conmoción y estábamos a punto de irnos. Nos alegramos de ver que no has salido demasiado mal $gparado:parada;.', 0);
-- 10331 Herramienta indispensable
-- https://es.wowhead.com/quest=10331
SET @ID := 10331;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes mi martillo?', 0),
(@ID, 'esMX', '¿Traes mi martillo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menos mal! Ya puedo seguir trabajando. Vas a pensar que estoy loco por trabajar fuera de la forja, y más en la pieza con la que voy a ganar el rango de oficial, pero no quiero que los demás aprendices copien mi diseño.', 0),
(@ID, 'esMX', '¡Menos mal! Ya puedo seguir trabajando. Vas a pensar que estoy loco por trabajar fuera de la forja, y más en la pieza con la que voy a ganar el rango de oficial, pero no quiero que los demás aprendices copien mi diseño.', 0);
-- 10332 El herrero maestro Rhonsus
-- https://es.wowhead.com/quest=10332
SET @ID := 10332;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Parece haber lágrimas en los ojos del aprendiz mientras habla.>$B$B¿Has... tratado con el maestro Rhonsus?', 0),
(@ID, 'esMX', '<Parece haber lágrimas en los ojos del aprendiz mientras habla.>$B$B¿Has... tratado con el maestro Rhonsus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El maestro Rhonsus me enseñó todo lo que sé sobre mi oficio. Honraré su memoria utilizando mi talento para servir a la gente de Kirin\'Var.', 0),
(@ID, 'esMX', 'El maestro Rhonsus me enseñó todo lo que sé sobre mi oficio. Honraré su memoria utilizando mi talento para servir a la gente de Kirin\'Var.', 0);
-- 10333 Ayuda a Mamá Ruedas
-- https://es.wowhead.com/quest=10333
SET @ID := 10333;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! ¿Me llamó su \'socia\'? ¡Soy su mujer!$B$B¡Y dijo que tenía una lengua mordaz! Ooh, cuando vuelva al Área 52, voy a darle un buen tirón a sus enormes y verdes orejas.$B$BPero me alegra que estés aquí. En algo tenía razón. Necesito ayuda.', 0),
(@ID, 'esMX', '¡¿Qué?! ¿Me llamó su \'socia\'? ¡Soy su mujer!$B$B¡Y dijo que tenía una lengua mordaz! Ooh, cuando vuelva al Área 52, voy a darle un buen tirón a sus enormes y verdes orejas.$B$BPero me alegra que estés aquí. En algo tenía razón. Necesito ayuda.', 0);
-- 10334 Necesita un cencerro
-- https://es.wowhead.com/quest=10334
SET @ID := 10334;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La vaca te mira con desconfianza, pero permanece en su posición.>', 0),
(@ID, 'esMX', '<La vaca te mira con desconfianza, pero permanece en su posición.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Sacas el cencerro de tu talega y lo haces sonar un par de veces. Se lo enseñas a Bessy, quien parece reconocerlo. La vaca permite que le ates el cordel del cencerro alrededor del cuello y te mira con expectación.>', 0),
(@ID, 'esMX', '<Sacas el cencerro de tu talega y lo haces sonar un par de veces. Se lo enseñas a Bessy, quien parece reconocerlo. La vaca permite que le ates el cordel del cencerro alrededor del cuello y te mira con expectación.>', 0);
-- 10335 Inspeccionar las ruinas
-- https://es.wowhead.com/quest=10335
SET @ID := 10335;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Marcador de reconocimiento uno colocado', `ObjectiveText2` = 'Marcador de reconocimiento dos colocado', `ObjectiveText3` = 'Marcador de reconocimiento tres colocado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué rápido. Debes de ser muy eficaz para haber colocado ya los tres marcadores.', 0),
(@ID, 'esMX', 'Qué rápido. Debes de ser muy eficaz para haber colocado ya los tres marcadores.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me lo dices en serio, verdad? ¡Excelentes noticias!$B$BAhora que has hecho el trabajo duro de reconocimiento, podré llevar a mi equipo a las ruinas y empezar a excavar.$B$BTe doy las gracias, $c.', 0),
(@ID, 'esMX', '¿Me lo dices en serio, verdad? ¡Excelentes noticias!$B$BAhora que has hecho el trabajo duro de reconocimiento, podré llevar a mi equipo a las ruinas y empezar a excavar.$B$BTe doy las gracias, $c.', 0);
