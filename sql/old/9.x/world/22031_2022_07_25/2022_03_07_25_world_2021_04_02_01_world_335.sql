-- 8420 Caliente y picante
-- https://es.classic.wowhead.com/quest=8420
SET @ID := 8420;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi tela vil?', 0),
(@ID, 'esMX', '¿Tienes mi tela vil?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau! Eres demasiado $gbueno:buena;. ¡Especialmente para $gun:una; $n! $B$B<Impsy se lleva la tela vil a la cara.>$B$BOh, cómo me encanta sentirlo, la forma en que quema tu piel y teje pensamientos malvados en la mente...', 0),
(@ID, 'esMX', '¡Guau! Eres demasiado $gbueno:buena;. ¡Especialmente para $gun:una; $n! $B$B<Impsy se lleva la tela vil a la cara.>$B$BOh, cómo me encanta sentirlo, la forma en que quema tu piel y teje pensamientos malvados en la mente...', 0);
-- 8421 La mercancía equivocada
-- https://es.classic.wowhead.com/quest=8421
SET @ID := 8421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los bienes?', 0),
(@ID, 'esMX', '¿Tienes los bienes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto funcionará muy bien.', 0),
(@ID, 'esMX', 'Esto funcionará muy bien.', 0);
-- 8422 Plumas de trol
-- https://es.classic.wowhead.com/quest=8422
SET @ID := 8422;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trajiste las plumas? ¡Esta muñeca necesita ser rellenada!', 0),
(@ID, 'esMX', '¿Trajiste las plumas? ¡Esta muñeca necesita ser rellenada!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso, ahora mi mascota está completa!$B$B<Impsy rápidamente mete la muñeca y le da un abrazo demoníaco.>$B$BOh, qué efecto secundario tan extraño tienen estas plumas de vudú...', 0),
(@ID, 'esMX', '¡Maravilloso, ahora mi mascota está completa!$B$B<Impsy rápidamente mete la muñeca y le da un abrazo demoníaco.>$B$BOh, qué efecto secundario tan extraño tienen estas plumas de vudú...', 0);
-- 8423 Parentesco guerrero
-- https://es.classic.wowhead.com/quest=8423
SET @ID := 8423;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las espinas ardientes del jabinferno dejan horribles cicatrices. No temas el dolor y la desfiguración, $gguerrero:guerrera;, no son nada comparados con la prisión a la que estoy encadenado.', 0),
(@ID, 'esMX', 'Las espinas ardientes del jabinferno dejan horribles cicatrices. No temas el dolor y la desfiguración, $gguerrero:guerrera;, no son nada comparados con la prisión a la que estoy encadenado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No necesito pruebas para saber lo que ha hecho, $n. Puedo ver la determinación grabada en tu expresión.', 0),
(@ID, 'esMX', 'No necesito pruebas para saber lo que ha hecho, $n. Puedo ver la determinación grabada en tu expresión.', 0);
-- 8424 La guerra contra los Sombra Jurada
-- https://es.classic.wowhead.com/quest=8424
SET @ID := 8424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Sombra Jurada no son derrotados fácilmente, ¿verdad? Pero eres $gun guerrero:una guerrera; y triunfarás o perecerás en el intento.', 0),
(@ID, 'esMX', 'Los Sombra Jurada no son derrotados fácilmente, ¿verdad? Pero eres $gun guerrero:una guerrera; y triunfarás o perecerás en el intento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya has mitigado mi dolor y me has honrado. Gracias, $n.', 0),
(@ID, 'esMX', 'Ya has mitigado mi dolor y me has honrado. Gracias, $n.', 0);
-- 8425 Plumas Vudú
-- https://es.classic.wowhead.com/quest=8425
SET @ID := 8425;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás de regreso tan pronto? El tiempo ya no es el mismo para mí, quizás haya sido un largo viaje para ti...', 0),
(@ID, 'esMX', '¿Estás de regreso tan pronto? El tiempo ya no es el mismo para mí, quizás haya sido un largo viaje para ti...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin puedo volver a sentir el frío toque del acero, aunque sea sólo por un momento.', 0),
(@ID, 'esMX', 'Por fin puedo volver a sentir el frío toque del acero, aunque sea sólo por un momento.', 0);
-- 8446 Inundación de Pesadilla
-- https://es.classic.wowhead.com/quest=8446
SET @ID := 8446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $r?', 0),
(@ID, 'esMX', '¿Sí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo eliminar la mancha de este objeto. Esto puede arrojar algo de luz sobre mis recientes fracasos para profundizar en el Sueño. Dámelo.', 0),
(@ID, 'esMX', 'Debo eliminar la mancha de este objeto. Esto puede arrojar algo de luz sobre mis recientes fracasos para profundizar en el Sueño. Dámelo.', 0);
-- 8447 Leyendas veraces
-- https://es.classic.wowhead.com/quest=8447
SET @ID := 8447;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma el anillo, $n. Ha cumplido su propósito para Malfurion. Ahora te servirá para un nuevo propósito...', 0),
(@ID, 'esMX', 'Toma el anillo, $n. Ha cumplido su propósito para Malfurion. Ahora te servirá para un nuevo propósito...', 0);
-- 8470 El tótem de ritual Muertobosque
-- https://es.classic.wowhead.com/quest=8470
SET @ID := 8470;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $c, ¿en qué puedo ayudarte? Caminas entre nosotros pacíficamente, pero no cabe duda de que ocurre algo. Percibo algo... algo perturbador...', 0),
(@ID, 'esMX', 'Dime, $c, ¿en qué puedo ayudarte? Caminas entre nosotros pacíficamente, pero no cabe duda de que ocurre algo. Percibo algo... algo perturbador...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este tótem... Lo reconozco... es de los Muertobosque, pero está tan degradado... Cualquier fiebre que haya vuelto a nuestros hermanos en nuestra contra, está sin duda impregnada también en este objeto.$B$BHas hecho bien en traérnoslo, $n. Quizás con algunos rituales y mucho estudio, consigamos descubrir qué contamina las mentes de nuestros hermanos. Gracias. Acepta estas ofrendas a cambio de tu hallazgo.', 0),
(@ID, 'esMX', 'Este tótem... Lo reconozco... es de los Muertobosque, pero está tan degradado... Cualquier fiebre que haya vuelto a nuestros hermanos en nuestra contra, está sin duda impregnada también en este objeto.$B$BHas hecho bien en traérnoslo, $n. Quizás con algunos rituales y mucho estudio, consigamos descubrir qué contamina las mentes de nuestros hermanos. Gracias. Acepta estas ofrendas a cambio de tu hallazgo.', 0);
-- 8471 Tótem de ritual Nevada
-- https://es.classic.wowhead.com/quest=8471
SET @ID := 8471;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, vienes a nosotros de forma pacífica pero tengo la sensación de que te atañen asuntos graves y muy importantes tanto para un fúrbolg como para $gun:una; $r. ¿Qué has venido a decirnos?', 0),
(@ID, 'esMX', '$c, vienes a nosotros de forma pacífica pero tengo la sensación de que te atañen asuntos graves y muy importantes tanto para un fúrbolg como para $gun:una; $r. ¿Qué has venido a decirnos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto... tiene la forma de un tótem ritual Nevada, pero está deformado por fuerzas que no puedo ni empezar a comprender. Sea cual sea el mal y la corrupción que ha puesto a los Nevada contra nosotros, está presente en este objeto, no hay duda.$B$BEl saber divino es el que os ha traído a ti y a este objeto a nosotros, $n. Lo estudiaremos detenidamente, quizás un día los Nevada dejen de dirigir su ira contra nosotros.$B$BGracias, $gamigo:amiga;, por favor, acepta estos regalos a cambio de toda tu bondad.', 0),
(@ID, 'esMX', 'Esto... tiene la forma de un tótem ritual Nevada, pero está deformado por fuerzas que no puedo ni empezar a comprender. Sea cual sea el mal y la corrupción que ha puesto a los Nevada contra nosotros, está presente en este objeto, no hay duda.$B$BEl saber divino es el que os ha traído a ti y a este objeto a nosotros, $n. Lo estudiaremos detenidamente, quizás un día los Nevada dejen de dirigir su ira contra nosotros.$B$BGracias, $gamigo:amiga;, por favor, acepta estos regalos a cambio de toda tu bondad.', 0);
-- 8474 El colgante del viejo Cortezablanca
-- https://es.wowhead.com/quest=8474
SET @ID := 8474;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este colgante... Se lo regalé al viejo Cortezablanca cuando su gente nos ayudó a reconstruir el poblado.$B$BSupongo que esto significa que está...$B$B<La elfa de sangre carraspea y recupera la compostura.>$B$BGracias por traerme esto, $n. Quiero pedirte algo.', 0),
(@ID, 'esMX', 'Este colgante... Se lo regalé al viejo Cortezablanca cuando su gente nos ayudó a reconstruir el poblado.$B$BSupongo que esto significa que está...$B$B<La elfa de sangre carraspea y recupera la compostura.>$B$BGracias por traerme esto, $n. Quiero pedirte algo.', 0);
-- 8480 El armamento perdido
-- https://es.wowhead.com/quest=8480
SET @ID := 8480;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las armas?', 0),
(@ID, 'esMX', '¿Traes las armas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. ¡Les vamos a enseñar a los desdichados de qué estamos hechos!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. ¡Les vamos a enseñar a los desdichados de qué estamos hechos!', 0);
-- 8481 La raíz de todos los males
-- https://es.wowhead.com/quest=8481
SET @ID := 8481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n... ¿Eso quiere decir que has matado al demonio?', 0),
(@ID, 'esMX', 'Has vuelto, $n... ¿Eso quiere decir que has matado al demonio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú... ¡nos has salvado! Al haber derrotado al demonio Xandivious has garantizado la seguridad del Bastión Fauces de Madera durante los próximos años. Eres $gun auténtico héroe:una auténtica heroína; para nosotros.$B$BPor favor, acepta esto con nuestra bendición. Aunque el proceso de curación de los fúrbolgs será lento, y a pesar de que el conflicto todavía persista, les has dado a los Nevada algo que hasta ahora no tenían.$B$BLes has dado la oportunidad de sobrevivir.', 0),
(@ID, 'esMX', 'Tú... ¡nos has salvado! Al haber derrotado al demonio Xandivious has garantizado la seguridad del Bastión Fauces de Madera durante los próximos años. Eres $gun auténtico héroe:una auténtica heroína; para nosotros.$B$BPor favor, acepta esto con nuestra bendición. Aunque el proceso de curación de los fúrbolgs será lento, y a pesar de que el conflicto todavía persista, les has dado a los Nevada algo que hasta ahora no tenían.$B$BLes has dado la oportunidad de sobrevivir.', 0);
-- 8484 Negociar la paz
-- https://es.classic.wowhead.com/quest=8484
SET @ID := 8484;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, eres $gbienvenido:bienvenida; en mis dominios. Forjaz siempre debe considerarse el hogar de $gun héroe:una heroína; como tú. Ahora, ¿qué negocios tienes conmigo?', 0),
(@ID, 'esMX', '$n, eres $gbienvenido:bienvenida; en mis dominios. Forjaz siempre debe considerarse el hogar de $gun héroe:una heroína; como tú. Ahora, ¿qué negocios tienes conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, este es un giro de los acontecimientos sumamente fortuito. Si se lograra una paz duradera con estas criaturas, esto sin duda nos daría una ventaja en los asuntos de Kalimdor... una que los Elfos Nocturnos no pueden mantener por sí mismos. ¡Notificaré esto a los otros líderes de la Alianza de inmediato y se enviarán más diplomáticos!$B$BEn cuanto a ti, $n... has demostrado valentía tanto en la diplomacia como en la acción. Te doy las gracias, al igual que toda la Alianza.', 0),
(@ID, 'esMX', 'De hecho, este es un giro de los acontecimientos sumamente fortuito. Si se lograra una paz duradera con estas criaturas, esto sin duda nos daría una ventaja en los asuntos de Kalimdor... una que los Elfos Nocturnos no pueden mantener por sí mismos. ¡Notificaré esto a los otros líderes de la Alianza de inmediato y se enviarán más diplomáticos!$B$BEn cuanto a ti, $n... has demostrado valentía tanto en la diplomacia como en la acción. Te doy las gracias, al igual que toda la Alianza.', 0);
-- 8485 Negociar la paz
-- https://es.classic.wowhead.com/quest=8485
SET @ID := 8485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los saludos del Jefe de Guerra te son otorgados, $n. Tus acciones hacen que la Horda se fortalezca en estos tiempos difíciles. Ahora, ¿qué negocios tienes conmigo?', 0),
(@ID, 'esMX', 'Los saludos del Jefe de Guerra te son otorgados, $n. Tus acciones hacen que la Horda se fortalezca en estos tiempos difíciles. Ahora, ¿qué negocios tienes conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, este es un giro de los acontecimientos sumamente fortuito. Si se lograra una paz duradera con estas criaturas, esto ciertamente nos daría una ventaja para proteger a Kalimdor de amenazas externas. Notificaré esto a los otros líderes de la Horda de inmediato y se enviarán más diplomáticos.$B$BEn cuanto a ti, $n... has demostrado valentía tanto en la diplomacia como en la acción. Te doy las gracias, al igual que toda la Horda.', 0),
(@ID, 'esMX', 'De hecho, este es un giro de los acontecimientos sumamente fortuito. Si se lograra una paz duradera con estas criaturas, esto ciertamente nos daría una ventaja para proteger a Kalimdor de amenazas externas. Notificaré esto a los otros líderes de la Horda de inmediato y se enviarán más diplomáticos.$B$BEn cuanto a ti, $n... has demostrado valentía tanto en la diplomacia como en la acción. Te doy las gracias, al igual que toda la Horda.', 0);
-- 8492 ¡La Alianza necesita lingotes de cobre!
-- https://es.classic.wowhead.com/quest=8492
SET @ID := 8492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has reunido ya esos 20 lingotes de cobre, soldado?', 0),
(@ID, 'esMX', '¿Has reunido ya esos 20 lingotes de cobre, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo lograste, $gchico:chica;! Pondremos esos lingotes de cobre en la pila y le sacaremos provecho para el material de guerra ahora mismo. Es la entrega de gente como tú lo que me hace sentirme orgulloso de servir a la Alianza. ¡Buen trabajo, soldado!$B$BY si por casualidad te encontraras con más lingotes de cobre, asegúrate de que llegan hasta mí.', 0),
(@ID, 'esMX', '¡Lo lograste, $gchico:chica;! Pondremos esos lingotes de cobre en la pila y le sacaremos provecho para el material de guerra ahora mismo. Es la entrega de gente como tú lo que me hace sentirme orgulloso de servir a la Alianza. ¡Buen trabajo, soldado!$B$BY si por casualidad te encontraras con más lingotes de cobre, asegúrate de que llegan hasta mí.', 0);
-- 8493 ¡La Alianza necesita más lingotes de cobre!
-- https://es.classic.wowhead.com/quest=8493
SET @ID := 8493;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra vez aquí, $c? ¡Fantástico! Los lingotes que nos has conseguido hasta ahora serán muy útiles para confeccionar todo tipo de cosas para la guerra. Sé que, entre otras cosas, el cobre se usará en piezas para los tanques de vapor en construcción, además de para una reducida flota de girocópteros que queremos desplegar si el tiempo lo permite.$B$BPero que estas pilas no te engañen, necesitamos aún más pilas de lingotes de cobre si puedes conseguirlas para preparar la guerra de Ahn\'Qiraj. ¿Nos ayudarás?', 0),
(@ID, 'esMX', '¿Otra vez aquí, $c? ¡Fantástico! Los lingotes que nos has conseguido hasta ahora serán muy útiles para confeccionar todo tipo de cosas para la guerra. Sé que, entre otras cosas, el cobre se usará en piezas para los tanques de vapor en construcción, además de para una reducida flota de girocópteros que queremos desplegar si el tiempo lo permite.$B$BPero que estas pilas no te engañen, necesitamos aún más pilas de lingotes de cobre si puedes conseguirlas para preparar la guerra de Ahn\'Qiraj. ¿Nos ayudarás?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo! Cavar en busca de ese cobre y fundirlo debe de haber sido toda una aventura. A menos que lo compraras en la casa de subastas. De cualquier modo, a mí me va bien. Recibirás toda clase de elogios por tu contribución a los preparativos para la guerra, $c. Y no dudes en traerme más lingotes de cobre si los tienes.', 0),
(@ID, 'esMX', '¡Excelente trabajo! Cavar en busca de ese cobre y fundirlo debe de haber sido toda una aventura. A menos que lo compraras en la casa de subastas. De cualquier modo, a mí me va bien. Recibirás toda clase de elogios por tu contribución a los preparativos para la guerra, $c. Y no dudes en traerme más lingotes de cobre si los tienes.', 0);
-- 8494 ¡La Alianza necesita barras de hierro!
-- https://es.classic.wowhead.com/quest=8494
SET @ID := 8494;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tienes esas veinte barras de hierro, ¡no quiero saber dónde las tienes escondidas!', 0),
(@ID, 'esMX', 'Si tienes esas veinte barras de hierro, ¡no quiero saber dónde las tienes escondidas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, bueno, si es $n. Y saliste adelante. Supongo que ahora tendré que estar pendiente de ti. Me duele decir esto, pero gracias por tus esfuerzos. La Alianza no lo olvidará, y yo tampoco. Ahora sal y empápate de cualquier otra cosa que necesites recolectar.', 0),
(@ID, 'esMX', 'Bueno, bueno, si es $n. Y saliste adelante. Supongo que ahora tendré que estar pendiente de ti. Me duele decir esto, pero gracias por tus esfuerzos. La Alianza no lo olvidará, y yo tampoco. Ahora sal y empápate de cualquier otra cosa que necesites recolectar.', 0);
-- 8495 ¡La Alianza necesita más barras de hierro!
-- https://es.classic.wowhead.com/quest=8495
SET @ID := 8495;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto? ¿Así pretendes conseguir que mejore la opinión que tengo de ti, $c? ¡Es que se me saltan las lágrimas! Así que, como verás, aún no tenemos suficientes barras de hierro para todas las armas, armaduras, tanques de vapor y demás chismes que hay que construir para la caza de bichos. ¿Crees que podrás hacer un hueco para traer otra pila de 20 barras de hierro entre un garbeo y otro a Zul\'Gurub, o adondequiera que vayan los jóvenes de hoy en día?', 0),
(@ID, 'esMX', '¿Ya has vuelto? ¿Así pretendes conseguir que mejore la opinión que tengo de ti, $c? ¡Es que se me saltan las lágrimas! Así que, como verás, aún no tenemos suficientes barras de hierro para todas las armas, armaduras, tanques de vapor y demás chismes que hay que construir para la caza de bichos. ¿Crees que podrás hacer un hueco para traer otra pila de 20 barras de hierro entre un garbeo y otro a Zul\'Gurub, o adondequiera que vayan los jóvenes de hoy en día?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debe ser un día frío en las Estepas Ardientes. Mira, es $n y me ha traído un regalo. ¡Veinte barras de hierro! Justo lo que siempre quise.$B$BSin embargo, con toda seriedad, gracias, $n. Te acreditas a ti y a toda la Alianza. ¡Ahora regresa y trae más cosas para el esfuerzo de guerra!', 0),
(@ID, 'esMX', 'Debe ser un día frío en las Estepas Ardientes. Mira, es $n y me ha traído un regalo. ¡Veinte barras de hierro! Justo lo que siempre quise.$B$BSin embargo, con toda seriedad, gracias, $n. Te acreditas a ti y a toda la Alianza. ¡Ahora regresa y trae más cosas para el esfuerzo de guerra!', 0);
-- Vendas para el campo de batalla
-- 8496, 8810
-- https://es.classic.wowhead.com/quest=8496
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8496, 8810) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8496, 'esES', '¿Tienes algo para mí, $n?', 0),
(8810, 'esES', '¿Tienes algo para mí, $n?', 0),
(8496, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8810, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8496, 8810) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8496, 'esES', 'Justo a tiempo. Estos suministros salvarán vidas, $n. Se agradece tu trabajo. Aquí está tu próxima tarea.', 0),
(8810, 'esES', 'Justo a tiempo. Estos suministros salvarán vidas, $n. Se agradece tu trabajo. Aquí está tu próxima tarea.', 0),
(8496, 'esMX', 'Justo a tiempo. Estos suministros salvarán vidas, $n. Se agradece tu trabajo. Aquí está tu próxima tarea.', 0),
(8810, 'esMX', 'Justo a tiempo. Estos suministros salvarán vidas, $n. Se agradece tu trabajo. Aquí está tu próxima tarea.', 0);
-- 8497 Material de supervivencia en el desierto
-- https://es.classic.wowhead.com/quest=8497
SET @ID := 8497;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Los necesitábamos, $n. Gracias.', 0),
(@ID, 'esMX', '¡Excelente! Los necesitábamos, $n. Gracias.', 0);
-- 8498 Órdenes de batalla Crepusculares
-- https://es.classic.wowhead.com/quest=8498
SET @ID := 8498;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído algo?', 0),
(@ID, 'esMX', '¿Me has traído algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Es importante adelantarse al próximo movimiento del enemigo. Esta información nos permitirá anticiparnos a los ataques del Martillo Crepuscular.', 0),
(@ID, 'esMX', 'Excelente. Es importante adelantarse al próximo movimiento del enemigo. Esta información nos permitirá anticiparnos a los ataques del Martillo Crepuscular.', 0);
-- 8499 ¡La Alianza necesita barras de torio!
-- https://es.classic.wowhead.com/quest=8499
SET @ID := 8499;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¿un envío de mi hermano? ¡Espléndido! ¡La fortuna realmente brilla sobre mí hoy!', 0),
(@ID, 'esMX', 'Oh, ¿un envío de mi hermano? ¡Espléndido! ¡La fortuna realmente brilla sobre mí hoy!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces Gnoarn no confía en mis habilidades de reconocimiento? Me pregunto porque...', 0),
(@ID, 'esMX', '¿Entonces Gnoarn no confía en mis habilidades de reconocimiento? Me pregunto porque...', 0);
-- 8500 ¡La Alianza necesita más barras de torio!
-- https://es.classic.wowhead.com/quest=8500
SET @ID := 8500;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es tan bueno verte de nuevo, $n. Espero que te haya ido bien. Es cierto que todavía necesitamos barras de torio. Si tienes de sobra, las estoy recolectando para el esfuerzo bélico de Ahn\'Qiraj.', 0),
(@ID, 'esMX', 'Es tan bueno verte de nuevo, $n. Espero que te haya ido bien. Es cierto que todavía necesitamos barras de torio. Si tienes de sobra, las estoy recolectando para el esfuerzo bélico de Ahn\'Qiraj.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Un trabajo bien hecho. Me ocuparé de que esas barras caigan sobre el palé y lleguen a las manos de los herreros e ingenieros que están trabajando arduamente en la construcción de suministros para nuestro ejército. Gracias de nuevo, y si te encuentras con más barras de torio, no dudes en volver.', 0),
(@ID, 'esMX', '¡Excelente, $n! Un trabajo bien hecho. Me ocuparé de que esas barras caigan sobre el palé y lleguen a las manos de los herreros e ingenieros que están trabajando arduamente en la construcción de suministros para nuestro ejército. Gracias de nuevo, y si te encuentras con más barras de torio, no dudes en volver.', 0);
-- 8501 Objetivo: los aguijoneros Colmen'Ashi
-- https://es.classic.wowhead.com/quest=8501
SET @ID := 8501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres decirme algo, $n?', 0),
(@ID, 'esMX', '¿Quieres decirme algo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Ashi.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Ashi.', 0);
-- 8502 Objetivo: los trabajadores Colmen'Ashi
-- https://es.classic.wowhead.com/quest=8502
SET @ID := 8502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Sin sus trabajadores, los silítidos tendrán dificultades para reparar cualquier daño infligido a la estructura de su colmena.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Sin sus trabajadores, los silítidos tendrán dificultades para reparar cualquier daño infligido a la estructura de su colmena.', 0);
-- 8503 ¡La Alianza necesita algas estranguladoras!
-- https://es.classic.wowhead.com/quest=8503
SET @ID := 8503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No es verdad! Nunca quitaría ninguna alga estranguladora de la parte superior de las pilas aquí. Uno podría tener la tentación de considerar que es prácticamente una panacea de utilidad. *tos* ¿No tienes ese alga estranguladora que discutimos antes?', 0),
(@ID, 'esMX', '¡No es verdad! Nunca quitaría ninguna alga estranguladora de la parte superior de las pilas aquí. Uno podría tener la tentación de considerar que es prácticamente una panacea de utilidad. *tos* ¿No tienes ese alga estranguladora que discutimos antes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hurra! Veinte menos. Eres $gel mejor:la mejor;. Supongo que debería empacarlos todos antes de que se marchiten. ¡Tantas algas estranguladoras, tan poco tiempo!$B$B¡Gracias de nuevo, $n!', 0),
(@ID, 'esMX', '¡Hurra! Veinte menos. Eres $gel mejor:la mejor;. Supongo que debería empacarlos todos antes de que se marchiten. ¡Tantas algas estranguladoras, tan poco tiempo!$B$B¡Gracias de nuevo, $n!', 0);
-- 8505 ¡La Alianza necesita lotos cárdenos!
-- https://es.classic.wowhead.com/quest=8505
SET @ID := 8505;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tiene los lotos cárdenos que solicité?', 0),
(@ID, 'esMX', '¿Tiene los lotos cárdenos que solicité?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu contribución es muy apreciada, $c. Sólo mediante los esfuerzos combinados de todos seremos capaces de repeler el implacable avance de los silítidos y cualquier fuerza que los impulse. Incluso la Horda está acumulando su propia reserva de loto cárdeno. Si encuentras más, por favor regrese a mí.', 0),
(@ID, 'esMX', 'Tu contribución es muy apreciada, $c. Sólo mediante los esfuerzos combinados de todos seremos capaces de repeler el implacable avance de los silítidos y cualquier fuerza que los impulse. Incluso la Horda está acumulando su propia reserva de loto cárdeno. Si encuentras más, por favor regrese a mí.', 0);
-- 8507 Servicio de campo
-- https://es.classic.wowhead.com/quest=8507
SET @ID := 8507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encontrarás las fuerzas del Capitán Yunquenegro estacionadas fuera de Colmen\'Zora. Si no puedes encontrarlo, habla con su teniente, Janela Martillotenaz.', 0),
(@ID, 'esMX', 'Encontrarás las fuerzas del Capitán Yunquenegro estacionadas fuera de Colmen\'Zora. Si no puedes encontrarlo, habla con su teniente, Janela Martillotenaz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n He preparado un conjunto de tareas que deberían hacer un uso óptimo de tus habilidades.$B$B¡Con los tus continuos esfuerzos y los de otros como tú, nuestro enemigo pronto será derrotado de una vez por todas!$B$BSi necesitas un nuevo informe de misión, regresa con el Capitán Yunquenegro.', 0),
(@ID, 'esMX', 'Muy bien, $n He preparado un conjunto de tareas que deberían hacer un uso óptimo de tus habilidades.$B$B¡Con los tus continuos esfuerzos y los de otros como tú, nuestro enemigo pronto será derrotado de una vez por todas!$B$BSi necesitas un nuevo informe de misión, regresa con el Capitán Yunquenegro.', 0);
-- 8508 Documentación de instrucción de campo
-- https://es.classic.wowhead.com/quest=8508
SET @ID := 8508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que quiere esos papeles firmados, <muchacho:muchacha>', 0),
(@ID, 'esMX', 'Supongo que quiere esos papeles firmados, <muchacho:muchacha>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, supongo que esa pequeña escaramuza pasará a ser un deber de campo hoy en día. Llévalos de regreso a Fuerte Cenarion, estoy seguro de que tendrán un trabajo a tu medida.$B$B¡Márchate!', 0),
(@ID, 'esMX', 'Sí, supongo que esa pequeña escaramuza pasará a ser un deber de campo hoy en día. Llévalos de regreso a Fuerte Cenarion, estoy seguro de que tendrán un trabajo a tu medida.$B$B¡Márchate!', 0);
-- 8509 ¡La Alianza necesita lágrimas de Arthas!
-- https://es.classic.wowhead.com/quest=8509
SET @ID := 8509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso? ¡Habla, $n! ¿Tienes ese envío de lágrimas de Arthas que pedí?', 0),
(@ID, 'esMX', '¿Qué es eso? ¡Habla, $n! ¿Tienes ese envío de lágrimas de Arthas que pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Debo decir que estoy gratamente sorprendida. No creerías la cantidad de personas que han venido, ofreciéndose a ayudar, pero nunca regresan. Permíteme meterlas en una caja y contarlas con tu nombre, y luego podemos hablar de nuevo sobre si necesito más de esas plantas.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Debo decir que estoy gratamente sorprendida. No creerías la cantidad de personas que han venido, ofreciéndose a ayudar, pero nunca regresan. Permíteme meterlas en una caja y contarlas con tu nombre, y luego podemos hablar de nuevo sobre si necesito más de esas plantas.', 0);
-- 8511 ¡La Alianza necesita cuero semipesado!
-- https://es.classic.wowhead.com/quest=8511
SET @ID := 8511;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, espero que sea el cuero ligero que prometiste.', 0),
(@ID, 'esMX', '$n, espero que sea el cuero ligero que prometiste.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me atrevo a decir que la Alianza estará muy contenta con estas pieles, $n. Me aseguraré de que no se desperdicie nada. Gracias, y asegúrate de volver a consultarme una vez que los haya contado para ver si necesitamos más.', 0),
(@ID, 'esMX', 'Me atrevo a decir que la Alianza estará muy contenta con estas pieles, $n. Me aseguraré de que no se desperdicie nada. Gracias, y asegúrate de volver a consultarme una vez que los haya contado para ver si necesitamos más.', 0);
-- 8512 ¡La Alianza necesita más cuero semipesado!
-- https://es.classic.wowhead.com/quest=8512
SET @ID := 8512;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno verte de nuevo, $n. Parece que necesitamos más cuero ligero para los distintos materiales de guerra. Si me traes una pila de diez, sería perfecto.', 0),
(@ID, 'esMX', 'Es bueno verte de nuevo, $n. Parece que necesitamos más cuero ligero para los distintos materiales de guerra. Si me traes una pila de diez, sería perfecto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu generosa donación, $n. Voy a ponerlos en la pila ahora mismo, y estoy segura de que en poco tiempo se transformarán en un buen conjunto de armadura, algunos parches de cuero o se usarán para otra cosa en nuestros preparativos. Parece que siempre necesitamos más cuero ligero. Vuelve pronto y visítame.', 0),
(@ID, 'esMX', 'Gracias por tu generosa donación, $n. Voy a ponerlos en la pila ahora mismo, y estoy segura de que en poco tiempo se transformarán en un buen conjunto de armadura, algunos parches de cuero o se usarán para otra cosa en nuestros preparativos. Parece que siempre necesitamos más cuero ligero. Vuelve pronto y visítame.', 0);
