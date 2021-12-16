-- 10412 Sellos Ala de Fuego
-- https://es.wowhead.com/quest=10412
SET @ID := 10412;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Adelante, $n. Habla.', 0),
(@ID, 'esMX', 'Adelante, $n. Habla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Puede que seas $gun aliado:una aliada; útil después de todo.', 0),
(@ID, 'esMX', 'Muy bien, $n. Puede que seas $gun aliado:una aliada; útil después de todo.', 0);
-- 10413 El horror de la contaminación
-- https://es.wowhead.com/quest=10413
SET @ID := 10413;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, parece que te has pringado un poco... ¿En qué te has metido?', 0),
(@ID, 'esMX', 'Mm, parece que te has pringado un poco... ¿En qué te has metido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿QUÉ?! ¿Te has enfrentado al horror de vacío? ¡¿Y has sobrevivido?! ¡Increíble!$B$BEsta muestra vale su peso en oro. Semejante hallazgo merece una recompensa.', 0),
(@ID, 'esMX', '¡¿QUÉ?! ¿Te has enfrentado al horror de vacío? ¡¿Y has sobrevivido?! ¡Increíble!$B$BEsta muestra vale su peso en oro. Semejante hallazgo merece una recompensa.', 0);
-- 10414 Sello Ala de Fuego único
-- https://es.wowhead.com/quest=10414
SET @ID := 10414;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Agradecemos hasta la más pequeña contribución a nuestra causa, $n. Nuestros enemigos son muy numerosos ¡pero venceremos!', 0),
(@ID, 'esMX', 'Agradecemos hasta la más pequeña contribución a nuestra causa, $n. Nuestros enemigos son muy numerosos ¡pero venceremos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Los efectivos de Kael\'s siguen menguando mientras que los nuestros aumentan.$B$B<Esta misión se puede repetir hasta conseguir el nivel de reputación de honorable.>', 0),
(@ID, 'esMX', 'Sí... Los efectivos de Kael\'s siguen menguando mientras que los nuestros aumentan.$B$B<Esta misión se puede repetir hasta conseguir el nivel de reputación de honorable.>', 0);
-- 10415 Más sellos Ala de Fuego
-- https://es.wowhead.com/quest=10415
SET @ID := 10415;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0),
(@ID, 'esMX', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Aplastaremos a cualquiera que se enfrente a nosotros!$B$B<Esta misión se puede repetir hasta conseguir el nivel de reputación de honorable.>', 0),
(@ID, 'esMX', '¡Excelente! ¡Aplastaremos a cualquiera que se enfrente a nosotros!$B$B<Esta misión se puede repetir hasta conseguir el nivel de reputación de honorable.>', 0);
-- 10416 Síntesis de poder
-- https://es.wowhead.com/quest=10416
SET @ID := 10416;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya un escrito Arcano, $n?', 0),
(@ID, 'esMX', '¿Tienes ya un escrito Arcano, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo prometido es deuda, $n. La totalidad del poder primario del libro condensado en una sola runa.', 0),
(@ID, 'esMX', 'Lo prometido es deuda, $n. La totalidad del poder primario del libro condensado en una sola runa.', 0);
-- 10417 ¡Realizar un diagnóstico!
-- https://es.wowhead.com/quest=10417
SET @ID := 10417;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los resultados de diagnóstico?', 0),
(@ID, 'esMX', '¿Has conseguido los resultados de diagnóstico?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mehrdad asiente con la cabeza y examina los resultados de diagnóstico.>$B$BEsto es preocupante. Los daños son mucho más graves de lo que pensaba. Puedo pedir que me traigan herramientas de La Flecha de la Tormenta para empezar las reparaciones pero será inútil si no aislamos antes lo que causa el daño en el equipamiento.', 0),
(@ID, 'esMX', '<Mehrdad asiente con la cabeza y examina los resultados de diagnóstico.>$B$BEsto es preocupante. Los daños son mucho más graves de lo que pensaba. Puedo pedir que me traigan herramientas de La Flecha de la Tormenta para empezar las reparaciones pero será inútil si no aislamos antes lo que causa el daño en el equipamiento.', 0);
-- 10418 Trato con los saboteadores
-- https://es.wowhead.com/quest=10418
SET @ID := 10418;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha sacado a las criaturas de su miseria? No me malinterpretes, realmente soy un amante de los animales, pero no cuando los animales muerden la mano que los alimenta y protege.', 0),
(@ID, 'esMX', '¿Ha sacado a las criaturas de su miseria? No me malinterpretes, realmente soy un amante de los animales, pero no cuando los animales muerden la mano que los alimenta y protege.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La zona ya parece más despejada. Los domos son bastante útiles pero tienen un efecto secundario y es que fomentan el crecimiento en algunos lugares, proliferan de forma inusual las especies locales a la vez que crecen más deprisa.', 0),
(@ID, 'esMX', 'La zona ya parece más despejada. Los domos son bastante útiles pero tienen un efecto secundario y es que fomentan el crecimiento en algunos lugares, proliferan de forma inusual las especies locales a la vez que crecen más deprisa.', 0);
-- 10419 Escritos Arcanos
-- https://es.wowhead.com/quest=10419
SET @ID := 10419;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido más tomos arcanos, $N?', 0),
(@ID, 'esMX', '¿Has obtenido más tomos arcanos, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El poder de este libro es tremendo. Y aun así, alguien con las ideas claras puede condensarlo fácilmente en una sola runa.', 0),
(@ID, 'esMX', 'El poder de este libro es tremendo. Y aun así, alguien con las ideas claras puede condensarlo fácilmente en una sola runa.', 0);
-- 10420 La Luz purificadora
-- https://es.wowhead.com/quest=10420
SET @ID := 10420;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido armamento vil, $n?', 0),
(@ID, 'esMX', '¿Has conseguido armamento vil, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira cómo se desintegran los asquerosos materiales. Mira cómo el metal se convierte en polvo.$B$BLa Luz lo limpia todo y solo queda el residuo más puro.', 0),
(@ID, 'esMX', 'Mira cómo se desintegran los asquerosos materiales. Mira cómo el metal se convierte en polvo.$B$BLa Luz lo limpia todo y solo queda el residuo más puro.', 0);
-- 10421 Armamento vil
-- https://es.wowhead.com/quest=10421
SET @ID := 10421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has cruzado con armamento vil últimamente? Que la Luz haga su trabajo, $n. No permitas que esos objetos contaminados permanezcan en este mundo.', 0),
(@ID, 'esMX', '¿Te has cruzado con armamento vil últimamente? Que la Luz haga su trabajo, $n. No permitas que esos objetos contaminados permanezcan en este mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los materiales viles se eliminan de este mundo. Solo permanece el residuo de la Luz.', 0),
(@ID, 'esMX', 'Los materiales viles se eliminan de este mundo. Solo permanece el residuo de la Luz.', 0);
-- 10422 El capitán Tyralius
-- https://es.wowhead.com/quest=10422
SET @ID := 10422;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Capitán Tyralius liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a Tyralius?', 0),
(@ID, 'esMX', '¿Encontraste a Tyralius?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Tyralius está gravemente herido, pero creo que va a sobrevivir.$B$BMencionó unos campamentos de prisiones parecidos al lugar donde estuvo prisionero. Prisiones llenas de criaturas de todo el universo.$B$BEstaremos en contacto por si surge la oportunidad de hacer algo. El Consorcio ya ha expresado su interés en enviar algunos equipos y está trabajando en la tecnología para abrir los candados de El Etereum.', 0),
(@ID, 'esMX', 'Gracias, $n. Tyralius está gravemente herido, pero creo que va a sobrevivir.$B$BMencionó unos campamentos de prisiones parecidos al lugar donde estuvo prisionero. Prisiones llenas de criaturas de todo el universo.$B$BEstaremos en contacto por si surge la oportunidad de hacer algo. El Consorcio ya ha expresado su interés en enviar algunos equipos y está trabajando en la tecnología para abrir los candados de El Etereum.', 0);
-- 10423 Hacia La Flecha de la Tormenta
-- https://es.wowhead.com/quest=10423
SET @ID := 10423;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Te presentas y le cuentas los resultados de los diagnósticos de Mehrdad en el Ecodomo de la Tierra Media.>$B$BMehrdad es tan solo un técnico, pero tiene un buen ojo para los detalles. Si sus observaciones son correctas necesitaremos los diagnósticos del resto de los generadores de los domos lo antes posible.', 0),
(@ID, 'esMX', '<Te presentas y le cuentas los resultados de los diagnósticos de Mehrdad en el Ecodomo de la Tierra Media.>$B$BMehrdad es tan solo un técnico, pero tiene un buen ojo para los detalles. Si sus observaciones son correctas necesitaremos los diagnósticos del resto de los generadores de los domos lo antes posible.', 0);
-- 10424 Diagnóstico: grave
-- https://es.wowhead.com/quest=10424
SET @ID := 10424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los diagnósticos?', 0),
(@ID, 'esMX', '¿Has conseguido los diagnósticos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos resultados coinciden exactamente con los de Mehrdad, ¿pero por qué? La única explicación posible que se me ocurre es que haya fallado alguna parte del equipamiento del generador del domo o que haya desaparecido. Eso podría provocar que los domos se debilitasen gravemente y perdiesen el equilibrio, como indican los diagnósticos.', 0),
(@ID, 'esMX', 'Estos resultados coinciden exactamente con los de Mehrdad, ¿pero por qué? La única explicación posible que se me ocurre es que haya fallado alguna parte del equipamiento del generador del domo o que haya desaparecido. Eso podría provocar que los domos se debilitasen gravemente y perdiesen el equilibrio, como indican los diagnósticos.', 0);
-- 10425 Huida del punto de escala
-- https://es.wowhead.com/quest=10425
SET @ID := 10425;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante Ameer parece satisfecho.>$B$B¡Bien hecho, ser de carne! Este soldado podría ser la clave para poner en jaque toda la operación de El Etereum.', 0),
(@ID, 'esMX', '<El comandante Ameer parece satisfecho.>$B$B¡Bien hecho, ser de carne! Este soldado podría ser la clave para poner en jaque toda la operación de El Etereum.', 0);
-- 10426 Flora de los Ecodomos
-- https://es.wowhead.com/quest=10426
SET @ID := 10426;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Probar modulador de campo de energía', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has intentado concentrar la energía del domo?', 0),
(@ID, 'esMX', '¿Has intentado concentrar la energía del domo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cielos! Parece que centrar la energía del domo sigue acelerando el crecimiento hasta el punto de la agresión extrema. Si conseguimos la habilidad de usar esta tecnología, tendremos que asegurarnos de calibrarla correctamente.', 0),
(@ID, 'esMX', '¡Cielos! Parece que centrar la energía del domo sigue acelerando el crecimiento hasta el punto de la agresión extrema. Si conseguimos la habilidad de usar esta tecnología, tendremos que asegurarnos de calibrarla correctamente.', 0);
-- 10427 Criaturas de los Ecodomos
-- https://es.wowhead.com/quest=10427
SET @ID := 10427;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Talbuk marcado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido marcar bastantes talbuks?', 0),
(@ID, 'esMX', '¿Has conseguido marcar bastantes talbuks?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo. Vigilaré bien los que has marcado a ver si maduran tan rápidamente como las otras formas de vida del domo.$B$BCon el control adecuado podríamos usar esta tecnología para revivir las zonas arruinadas de Terrallende y Azeroth.', 0),
(@ID, 'esMX', 'Excelente trabajo. Vigilaré bien los que has marcado a ver si maduran tan rápidamente como las otras formas de vida del domo.$B$BCon el control adecuado podríamos usar esta tecnología para revivir las zonas arruinadas de Terrallende y Azeroth.', 0);
-- 10428 El pescador desaparecido
-- https://es.wowhead.com/quest=10428
SET @ID := 10428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi familia... Qué he hecho... ¿Qué podría haber hecho?$B$B¿Por qué debo ser castigado de esta manera?', 0),
(@ID, 'esMX', 'Mi familia... Qué he hecho... ¿Qué podría haber hecho?$B$B¿Por qué debo ser castigado de esta manera?', 0);
-- 10429 Cuando la naturaleza va demasiado lejos
-- https://es.wowhead.com/quest=10429
SET @ID := 10429;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has conseguido la muestra de la monstruosa hidra?', 0),
(@ID, 'esMX', '¿Me has conseguido la muestra de la monstruosa hidra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Aurine toma el corazón.>$B$BIncluso para una criatura de ese tamaño, este corazón es demasiado grande. Le costaba mantener el ritmo del gigantesco cuerpo de la criatura. No me extrañaría que hubiese muerto antes de alcanzar la mitad de su vida normal.$B$BA pesar de tales riesgos, no dudaré en convencer al Consorcio para que compartan su tecnología. Esto es demasiado prometedor para abandonar ahora.', 0),
(@ID, 'esMX', '<Aurine toma el corazón.>$B$BIncluso para una criatura de ese tamaño, este corazón es demasiado grande. Le costaba mantener el ritmo del gigantesco cuerpo de la criatura. No me extrañaría que hubiese muerto antes de alcanzar la mitad de su vida normal.$B$BA pesar de tales riesgos, no dudaré en convencer al Consorcio para que compartan su tecnología. Esto es demasiado prometedor para abandonar ahora.', 0);
-- 10430 Probando el prototipo
-- https://es.wowhead.com/quest=10430
SET @ID := 10430;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece ser que tienes el prototipo. ¿Te ha enviado Ghabar?', 0),
(@ID, 'esMX', 'Parece ser que tienes el prototipo. ¿Te ha enviado Ghabar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto parece algo extraño. Definitivamente, Ghabar no tuvo en cuenta la Tormenta Abisal cuando lo diseñó.$B$BNo te sorprendas tanto, $n. La Tormenta Abisal no es nada comparada con algunos de los entornos en los que he trabajado. De cualquier forma, un domo a punto de derrumbarse, siempre es preocupante.', 0),
(@ID, 'esMX', 'Esto parece algo extraño. Definitivamente, Ghabar no tuvo en cuenta la Tormenta Abisal cuando lo diseñó.$B$BNo te sorprendas tanto, $n. La Tormenta Abisal no es nada comparada con algunos de los entornos en los que he trabajado. De cualquier forma, un domo a punto de derrumbarse, siempre es preocupante.', 0);
-- 10431 Ayuda externa
-- https://es.wowhead.com/quest=10431
SET @ID := 10431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tú eres toda la ayuda que envía Orelis? Debe tener un gran concepto de ti.', 0),
(@ID, 'esMX', '¿Tú eres toda la ayuda que envía Orelis? Debe tener un gran concepto de ti.', 0);
