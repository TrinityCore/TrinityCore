-- 7366 La misericordia del arzobispo
-- https://es.classic.wowhead.com/quest=7366
SET @ID := 7366;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Benedictus! No soy más que una mota a la sombra de su grandeza. ¡Alabado sea!', 0),
(@ID, 'esMX', 'Benedictus! No soy más que una mota a la sombra de su grandeza. ¡Alabado sea!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabado sea Benedictus! ¡Otra alma perdida, que pronto será salvada por las llamas candentes de la Luz!$B$B¡Vete, oh soldado de la Luz! ¡Hay que salvar más!', 0),
(@ID, 'esMX', '¡Alabado sea Benedictus! ¡Otra alma perdida, que pronto será salvada por las llamas candentes de la Luz!$B$B¡Vete, oh soldado de la Luz! ¡Hay que salvar más!', 0);
-- 7385 Un galón de sangre
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=7385
-- http://web.archive.org/web/20130402025145/http://es.wowhead.com/quest=7385
-- https://classic.wowhead.com/quest=7385
-- https://www.wowhead.com/quest=7385
SET @ID := 7385;
UPDATE `quest_request_items` SET `CompletionText` = 'You have the option of offering larger quantities of the blood taken from our enemies. I will be glad to accept gallon sized offerings, $n.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes la posibilidad de ofrecer cantidades mayores de sangre de nuestros enemigos. Será un placer aceptar ofrendas de mayor tamaño, $n.', 0),
(@ID, 'esMX', 'Tienes la posibilidad de ofrecer cantidades mayores de sangre de nuestros enemigos. Será un placer aceptar ofrendas de mayor tamaño, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se ha derramado sangre enemiga. Mezclaré esta sangre con el resto de elementos que hemos recolectado. Cuando la ofrenda esté completa, el Señor del Hielo enseñará a esos perros Pico Tormenta ¡toda la ira del clan Lobo Gélido!', 0),
(@ID, 'esMX', 'Se ha derramado sangre enemiga. Mezclaré esta sangre con el resto de elementos que hemos recolectado. Cuando la ofrenda esté completa, el Señor del Hielo enseñará a esos perros Pico Tormenta ¡toda la ira del clan Lobo Gélido!', 0);
-- 7386 Recogida de cristal
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=7386
-- http://web.archive.org/web/20140531002103/http://es.wowhead.com:80/quest=7386
-- https://classic.wowhead.com/quest=7386
-- https://www.wowhead.com/quest=7386
SET @ID := 7386;
UPDATE `quest_request_items` SET `CompletionText` = 'There are times which you may be entrenched in battle for days or weeks on end. During those longer periods of activity you may end up collecting large clusters of the Frostwolf\'s storm crystals.$B$BThe Circle accepts such offerings, $n.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A veces te puedes encontrar $gatrincherado:atrincherada; en la batalla durante varios días o incluso varias semanas. En esos períodos más largos de actividad, puedes acabar recogiendo grandes bloques de cristales de tormenta de los Lobo Gélido.$B$BEl Círculo acepta tales ofrendas, $n.', 0),
(@ID, 'esMX', 'A veces te puedes encontrar $gatrincherado:atrincherada; en la batalla durante varios días o incluso varias semanas. En esos períodos más largos de actividad, puedes acabar recogiendo grandes bloques de cristales de tormenta de los Lobo Gélido.$B$BEl Círculo acepta tales ofrendas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Usaré el poder de estos talismanes para aumentar la magia que ya se ha reunido. Cuando hayas acumulado suficiente poder, concentraré las energías reunidas e invocaré al Señor del Bosque para que nos ayude en nuestra causa.', 0),
(@ID, 'esMX', 'Muy bien, $n. Usaré el poder de estos talismanes para aumentar la magia que ya se ha reunido. Cuando hayas acumulado suficiente poder, concentraré las energías reunidas e invocaré al Señor del Bosque para que nos ayude en nuestra causa.', 0);
-- 7401 Se buscan: ¡ENANOS!
-- https://es.classic.wowhead.com/quest=7401
SET @ID := 7401;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Trato con la ironía al por mayor, soldado.', 0),
(@ID, 'esMX', 'Trato con la ironía al por mayor, soldado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora tienes licencia para diezmar a los enanos por docenas, $n!$B$B<Yazra mira a lo lejos por un momento.>$B$BNunca olvidas tu primer desespinado...', 0),
(@ID, 'esMX', '¡Ahora tienes licencia para diezmar a los enanos por docenas, $n!$B$B<Yazra mira a lo lejos por un momento.>$B$BNunca olvidas tu primer desespinado...', 0);
-- 7424 ¿Y la pezuña?
-- https://es.classic.wowhead.com/quest=7424
SET @ID := 7424;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '* Dirk arroja la pezuña en una pila detrás de él. *', 0),
(@ID, 'esMX', '* Dirk arroja la pezuña en una pila detrás de él. *', 0);
-- 7441 Pusillín y el ancestro Azj'Tordin
-- https://es.classic.wowhead.com/quest=7441
SET @ID := 7441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me arrepiento de nada, extranjero. La Reina desapareció hace mucho tiempo. Y los trabajos de Shen\'Dralar han sido mancillados por la locura del príncipe Tortheldrin. Yo solo busco la libertad... Quiero escapar...', 0),
(@ID, 'esMX', 'No me arrepiento de nada, extranjero. La Reina desapareció hace mucho tiempo. Y los trabajos de Shen\'Dralar han sido mancillados por la locura del príncipe Tortheldrin. Yo solo busco la libertad... Quiero escapar...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has encontrado! Maldito sea ese miserable diablillo. Aunque mis posesiones materiales no son muchas, puedes elegir la que quieras de entre ellas.', 0),
(@ID, 'esMX', '¡Lo has encontrado! Maldito sea ese miserable diablillo. Aunque mis posesiones materiales no son muchas, puedes elegir la que quieras de entre ellas.', 0);
-- 7461 Locura interior
-- https://es.classic.wowhead.com/quest=7461
SET @ID := 7461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado, $gaventurero:aventurera;. El Príncipe es... persuasivo.', 0),
(@ID, 'esMX', 'Ten cuidado, $gaventurero:aventurera;. El Príncipe es... persuasivo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te damos las gracias, $ghéroe:heroína;.', 0),
(@ID, 'esMX', 'Te damos las gracias, $ghéroe:heroína;.', 0);
-- El tesoro de los Shen'dralar
-- 7462, 7877
-- https://es.classic.wowhead.com/quest=7877
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7462, 7877) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7462, 'esES', 'Abres el cofre y en su interior encuentras...', 0),
(7877, 'esES', 'Abres el cofre y en su interior encuentras...', 0),
(7462, 'esMX', 'Abres el cofre y en su interior encuentras...', 0),
(7877, 'esMX', 'Abres el cofre y en su interior encuentras...', 0);
-- 7463 El refresco arcano
-- https://es.classic.wowhead.com/quest=7463
SET @ID := 7463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Nos conocemos?', 0),
(@ID, 'esMX', '¿Sí? ¿Nos conocemos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¿Quién decías que eras? Bah, no importa. ¿Qué era lo que te tenía que dar? Mm... bueno, como eres $c, puede que esto te resulte útil.', 0),
(@ID, 'esMX', '¡Estupendo! ¿Quién decías que eras? Bah, no importa. ¿Qué era lo que te tenía que dar? Mm... bueno, como eres $c, puede que esto te resulte útil.', 0);
-- Leyendas élficas
-- 7481, 7482
-- https://es.classic.wowhead.com/quest=7481
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7481, 7482) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7481, 'esES', 'Mi socio, el erudito elfo de la noche, Runethorn, está reclutando a sus aliados para esta tarea.', 0),
(7482, 'esES', 'Mi socio, el erudito elfo de la noche, Runethorn, está reclutando a sus aliados para esta tarea.', 0),
(7481, 'esMX', 'Mi socio, el erudito elfo de la noche, Runethorn, está reclutando a sus aliados para esta tarea.', 0),
(7482, 'esMX', 'Mi socio, el erudito elfo de la noche, Runethorn, está reclutando a sus aliados para esta tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7481, 7482) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7481, 'esES', 'Una pena... una tragedia. ¿Así que dices que los objetos se han perdido? No hay rastro de ellos, ¿eh?', 0),
(7482, 'esES', 'Una pena... una tragedia. ¿Así que dices que los objetos se han perdido? No hay rastro de ellos, ¿eh?', 0),
(7481, 'esMX', 'Una pena... una tragedia. ¿Así que dices que los objetos se han perdido? No hay rastro de ellos, ¿eh?', 0),
(7482, 'esMX', 'Una pena... una tragedia. ¿Así que dices que los objetos se han perdido? No hay rastro de ellos, ¿eh?', 0);
-- 7483 El tratado sobre rapidez
-- https://es.classic.wowhead.com/quest=7483
SET @ID := 7483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es? ¡Tengo mucho que catalogar!', 0),
(@ID, 'esMX', '¿Qué es? ¡Tengo mucho que catalogar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lydros bosteza.>$B$BComo prometí, el Arcanum de Rapidez. No lo gastes todo en un solo lugar.$B$B<Lydros se ríe.>', 0),
(@ID, 'esMX', '<Lydros bosteza.>$B$BComo prometí, el Arcanum de Rapidez. No lo gastes todo en un solo lugar.$B$B<Lydros se ríe.>', 0);
-- 7484 El tratado sobre enfoque
-- https://es.classic.wowhead.com/quest=7484
SET @ID := 7484;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tú otra vez? ¿Qué demonios quieres ahora?', 0),
(@ID, 'esMX', '¿Tú otra vez? ¿Qué demonios quieres ahora?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te hagas daño cuando apliques el encantamiento, $r.', 0),
(@ID, 'esMX', 'No te hagas daño cuando apliques el encantamiento, $r.', 0);
-- 7485 El tratado sobre protección
-- https://es.classic.wowhead.com/quest=7485
SET @ID := 7485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo mi paciencia se interpone entre tú y el sufrimiento.', 0),
(@ID, 'esMX', 'Solo mi paciencia se interpone entre tú y el sufrimiento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí... Tranquilízate. Aquí tienes tu arcano, como te prometí.', 0),
(@ID, 'esMX', 'Sí, sí... Tranquilízate. Aquí tienes tu arcano, como te prometí.', 0);
-- 7486 Una recompensa de héroe
-- https://es.classic.wowhead.com/quest=7486
SET @ID := 7486;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La voz de Hydraxis surge del agua...$B$B"Elige lo que más te plazca, $n. Que te proteja frente a los enemigos de los Señores del Agua."', 0),
(@ID, 'esMX', 'La voz de Hydraxis surge del agua...$B$B"Elige lo que más te plazca, $n. Que te proteja frente a los enemigos de los Señores del Agua."', 0);
-- Armonización con el Núcleo
-- 7487, 7848
-- https://es.classic.wowhead.com/quest=7487
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7487, 7848) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7487, 'esES', 'Debes sintonizar tu alma con el Núcleo de Magma antes de poder entrar.', 0),
(7848, 'esES', 'Debes sintonizar tu alma con el Núcleo de Magma antes de poder entrar.', 0),
(7487, 'esMX', 'Debes sintonizar tu alma con el Núcleo de Magma antes de poder entrar.', 0),
(7848, 'esMX', 'Debes sintonizar tu alma con el Núcleo de Magma antes de poder entrar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7487, 7848) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7487, 'esES', 'El Núcleo de Magma está justo pasada la entrada a mi derecha.', 0),
(7848, 'esES', 'El Núcleo de Magma está justo pasada la entrada a mi derecha.', 0),
(7487, 'esMX', 'El Núcleo de Magma está justo pasada la entrada a mi derecha.', 0),
(7848, 'esMX', 'El Núcleo de Magma está justo pasada la entrada a mi derecha.', 0);
-- 7488 La membrana de Lethtendris
-- https://es.classic.wowhead.com/quest=7488
SET @ID := 7488;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la red, $n? ¡Debemos disipar su energía mágica!', 0),
(@ID, 'esMX', '¿Tienes la red, $n? ¡Debemos disipar su energía mágica!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido la red! ¡Bien hecho, $n! Lethtendris, como muchos elfos de su ralea, no es consciente de los daños que el abuso de la magia puede ocasionar a nuestro mundo. Creen que son los dueños de la magia. No se dan cuenta de que en realidad son esclavos de una adicción. Su muerte me entristece, pero era necesaria.$B$BGracias, $n. Liberaré en un lugar seguro las energías que la red retiene y luego destruiré la red para impedir que vuelva a ser utilizada.', 0),
(@ID, 'esMX', '¡Has conseguido la red! ¡Bien hecho, $n! Lethtendris, como muchos elfos de su ralea, no es consciente de los daños que el abuso de la magia puede ocasionar a nuestro mundo. Creen que son los dueños de la magia. No se dan cuenta de que en realidad son esclavos de una adicción. Su muerte me entristece, pero era necesaria.$B$BGracias, $n. Liberaré en un lugar seguro las energías que la red retiene y luego destruiré la red para impedir que vuelva a ser utilizada.', 0);
-- 7489 La membrana de Lethtendris
-- https://es.classic.wowhead.com/quest=7489
SET @ID := 7489;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes la Membrana de Lethtendris?', 0),
(@ID, 'esMX', '$n, ¿tienes la Membrana de Lethtendris?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un buen trabajo, $n. Esta red contiene enormes cantidades de la magia de La Masacre. El daño que alguien tan irresponsable como Lethtendris podría haber causado si hubiera llegado a controlar sus energías... es inimaginable. Me apenó su muerte, pero sé que ella nunca se habría separado de la red mientras le quedara vida.$B$BGracias, $n. Enviaré la red a unos estudiantes de magia más responsables que Lethtendris. Serán los nuevos custodios de su poder.', 0),
(@ID, 'esMX', 'Has hecho un buen trabajo, $n. Esta red contiene enormes cantidades de la magia de La Masacre. El daño que alguien tan irresponsable como Lethtendris podría haber causado si hubiera llegado a controlar sus energías... es inimaginable. Me apenó su muerte, pero sé que ella nunca se habría separado de la red mientras le quedara vida.$B$BGracias, $n. Enviaré la red a unos estudiantes de magia más responsables que Lethtendris. Serán los nuevos custodios de su poder.', 0);
-- 7490 Victoria para la Horda
-- https://es.classic.wowhead.com/quest=7490
SET @ID := 7490;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El gesto impasible de Thrall cambia por un segundo al ver la enorme cabeza de Onyxia.>', 0),
(@ID, 'esMX', '<El gesto impasible de Thrall cambia por un segundo al ver la enorme cabeza de Onyxia.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué gran victoria para la Horda, $n. Has honrado muchas veces a tu Jefe de Guerra, ahora él debe honrarte a ti.', 0),
(@ID, 'esMX', 'Qué gran victoria para la Horda, $n. Has honrado muchas veces a tu Jefe de Guerra, ahora él debe honrarte a ti.', 0);
-- 7491 Para que todos lo vean
-- https://es.classic.wowhead.com/quest=7491
SET @ID := 7491;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elige tu recompensa y que empiece los festejos por tu gloriosa victoria.', 0),
(@ID, 'esMX', 'Elige tu recompensa y que empiece los festejos por tu gloriosa victoria.', 0);
-- 7492 Campamento Mojache
-- https://es.classic.wowhead.com/quest=7492
SET @ID := 7492;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, me alegra ver que $gun:una; $c acude a mi llamada. Necesito tus servicios, $n. Y temo que lo que te pida te guiará por un camino peligroso...$B$BEl camino a La Masacre.', 0),
(@ID, 'esMX', 'Ah, me alegra ver que $gun:una; $c acude a mi llamada. Necesito tus servicios, $n. Y temo que lo que te pida te guiará por un camino peligroso...$B$BEl camino a La Masacre.', 0);
-- 7495 Victoria para la Alianza
-- https://es.classic.wowhead.com/quest=7495
SET @ID := 7495;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por las barbas de Uther!', 0),
(@ID, 'esMX', '¡Por las barbas de Uther!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Durante muchos años su mirada cautivadora me privó de la libertad. ¡Al fin puedo ver que se hace justicia y se restaura el honor de Ventormenta! Hoy, celebramos esta gloriosa victoria.', 0),
(@ID, 'esMX', 'Durante muchos años su mirada cautivadora me privó de la libertad. ¡Al fin puedo ver que se hace justicia y se restaura el honor de Ventormenta! Hoy, celebramos esta gloriosa victoria.', 0);
-- 7496 Celebrar los buenos momentos
-- https://es.classic.wowhead.com/quest=7496
SET @ID := 7496;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pocos son recibidos con tanta ceremonia, $n. Por favor, elige tu recompensa para que podamos comenzar la celebración.', 0),
(@ID, 'esMX', 'Pocos son recibidos con tanta ceremonia, $n. Por favor, elige tu recompensa para que podamos comenzar la celebración.', 0);
-- Garona: Un Estudio sobre el Sigilo y la Traición
-- 7498, 7499, 7500, 7501, 7502, 7503, 7504, 7505, 7506
-- https://es.classic.wowhead.com/quest=7498
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7498, 7499, 7500, 7501, 7502, 7503, 7504, 7505, 7506) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7498, 'esES', '¡Has recuperado un tomo!', 0),
(7499, 'esES', '¡Has recuperado un tomo!', 0),
(7500, 'esES', '¡Has recuperado un tomo!', 0),
(7501, 'esES', '¡Has recuperado un tomo!', 0),
(7502, 'esES', '¡Has recuperado un tomo!', 0),
(7503, 'esES', '¡Has recuperado un tomo!', 0),
(7504, 'esES', '¡Has recuperado un tomo!', 0),
(7505, 'esES', '¡Has recuperado un tomo!', 0),
(7506, 'esES', '¡Has recuperado un tomo!', 0),
(7498, 'esMX', '¡Has recuperado un tomo!', 0),
(7499, 'esMX', '¡Has recuperado un tomo!', 0),
(7500, 'esMX', '¡Has recuperado un tomo!', 0),
(7501, 'esMX', '¡Has recuperado un tomo!', 0),
(7502, 'esMX', '¡Has recuperado un tomo!', 0),
(7503, 'esMX', '¡Has recuperado un tomo!', 0),
(7504, 'esMX', '¡Has recuperado un tomo!', 0),
(7505, 'esMX', '¡Has recuperado un tomo!', 0),
(7506, 'esMX', '¡Has recuperado un tomo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7498, 7499, 7500, 7501, 7502, 7503, 7504, 7505, 7506) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7498, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7499, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7500, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7501, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7502, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7503, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7504, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7505, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7506, 'esES', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7498, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7499, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7500, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7501, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7502, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7503, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7504, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7505, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0),
(7506, 'esMX', 'Excelente trabajo, $r. Si encuentra más tomos, no dudes en devolvérnoslos.$B$BA medida que pasa el tiempo, tendemos a cambiar e incluso agregar nuevas recompensas por la devolución de los tomos perdidos.', 0);
-- 7507 Compendio de Foror
-- https://es.classic.wowhead.com/quest=7507
SET @ID := 7507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, unu de nuestros mejores compendios. Este ha estado desaparecido durante años.', 0),
(@ID, 'esMX', 'Ah, unu de nuestros mejores compendios. Este ha estado desaparecido durante años.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Podrías haber obtenido bastante oro por este libro en el mercado negro, $n. Sobre todo porque el sello protector se ha roto, dejando los secretos de la matanza de dragones visibles para cualquiera que tenga el intelecto necesario para consumir el conocimiento contenido en las páginas sagradas.$B$BQuizás una gran recompensa sea lo correcto... Bueno, una recompensa que requerirá un enorme esfuerzo para obtenerla.$B$B<Lydros sonríe.>', 0),
(@ID, 'esMX', 'Podrías haber obtenido bastante oro por este libro en el mercado negro, $n. Sobre todo porque el sello protector se ha roto, dejando los secretos de la matanza de dragones visibles para cualquiera que tenga el intelecto necesario para consumir el conocimiento contenido en las páginas sagradas.$B$BQuizás una gran recompensa sea lo correcto... Bueno, una recompensa que requerirá un enorme esfuerzo para obtenerla.$B$B<Lydros sonríe.>', 0);
-- 7508 Forjar Quel'Serrar
-- https://es.classic.wowhead.com/quest=7508
SET @ID := 7508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, comencemos...', 0),
(@ID, 'esMX', 'Excelente, comencemos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si logras entrar en la guarida del dragón, calientas la hoja bajo su ardiente aliento y finalmente la templas en su sangre, ligaré la hoja para tu uso.', 0),
(@ID, 'esMX', 'Si logras entrar en la guarida del dragón, calientas la hoja bajo su ardiente aliento y finalmente la templas en su sangre, ligaré la hoja para tu uso.', 0);
-- 7509 Forjar Quel'Serrar
-- https://es.classic.wowhead.com/quest=7509
SET @ID := 7509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás algún día, otro empuñe la hoja prismática.', 0),
(@ID, 'esMX', 'Quizás algún día, otro empuñe la hoja prismática.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lydros murmura algo ininteligible.>$B$BComo prometí, $n, la espada de Quel\'Serrar.', 0),
(@ID, 'esMX', '<Lydros murmura algo ininteligible.>$B$BComo prometí, $n, la espada de Quel\'Serrar.', 0);
-- 7541 Un servicio para la Horda
-- https://es.classic.wowhead.com/quest=7541
SET @ID := 7541;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros estudiosos tardarán un tiempo en analizar el colgante que nos trajiste. Pero quiero ofrecerte una pequeña recompensa por el trabajo que has hecho para la Horda.$B$BGracias, $n. Tus actos te honran a ti, y también a nosotros.', 0),
(@ID, 'esMX', 'Nuestros estudiosos tardarán un tiempo en analizar el colgante que nos trajiste. Pero quiero ofrecerte una pequeña recompensa por el trabajo que has hecho para la Horda.$B$BGracias, $n. Tus actos te honran a ti, y también a nosotros.', 0);
-- 7562 Mor'zul Sangredoble
-- https://es.classic.wowhead.com/quest=7562
SET @ID := 7562;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n, y $gbienvenido:bienvenida;. ¿Estás aquí para estudiar cerca del Altar de las Tormentas como yo, quizás para aprovechar su energía para algún propósito oculto?$B$BO... ¿estás aquí para hablar conmigo? Sí, creo que es eso.$B$B¿Quieres dominar un corcel temible? No es una tarea fácil. Te costará grandes cantidades de sangre, sudor... y, por supuesto, oro. Pero un corcel temible de Xoroth es un premio que vale la pena ganar, así que si estás $ginteresado:interesada;, escucha...', 0),
(@ID, 'esMX', 'Saludos, $n, y $gbienvenido:bienvenida;. ¿Estás aquí para estudiar cerca del Altar de las Tormentas como yo, quizás para aprovechar su energía para algún propósito oculto?$B$BO... ¿estás aquí para hablar conmigo? Sí, creo que es eso.$B$B¿Quieres dominar un corcel temible? No es una tarea fácil. Te costará grandes cantidades de sangre, sudor... y, por supuesto, oro. Pero un corcel temible de Xoroth es un premio que vale la pena ganar, así que si estás $ginteresado:interesada;, escucha...', 0);
-- 7563 La ira de sangre
-- https://es.classic.wowhead.com/quest=7563
SET @ID := 7563;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto las fieras lechuzas, $n? La magia de esas criaturas es fuerte y se concentra en la sangre que fluye a través de sus formas torturadas.', 0),
(@ID, 'esMX', '¿Has visto las fieras lechuzas, $n? La magia de esas criaturas es fuerte y se concentra en la sangre que fluye a través de sus formas torturadas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Haré que destilen esta sangre en tinta y la utilicen para el pergamino que te prometí. Y quizás me guarde un poco para mí, ya que escuché que su sabor es bastante eufórico...', 0),
(@ID, 'esMX', 'Ah, muy bien. Haré que destilen esta sangre en tinta y la utilicen para el pergamino que te prometí. Y quizás me guarde un poco para mí, ya que escuché que su sabor es bastante eufórico...', 0);
-- 7564 Ojovago
-- https://es.classic.wowhead.com/quest=7564
SET @ID := 7564;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes algo para mi? No es una araña grande y jugosa, ¿verdad? ¿O quizás una cucaracha? Espero que todavía esté viva... Me encanta masticarlas cuando todavía están vivas...', 0),
(@ID, 'esMX', 'Tienes algo para mi? No es una araña grande y jugosa, ¿verdad? ¿O quizás una cucaracha? Espero que todavía esté viva... Me encanta masticarlas cuando todavía están vivas...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, es sangre. Entonces debe ser del maestro Mor\'zul. Está tan enamorado de las cosas y le encanta verlas derramadas. Yo, sin embargo, prefiero que corra por las venas de un pequeño roedor. Se mantiene caliente de esa manera... hasta que lo desee.$B$BEsta es sangre poderosa. ¡Mor\'zul debe estar haciendo otro pergamino para convocar a un corcel aterrador! ¡Que interesante!$B$BSi eso es cierto, y vas a realizar el ritual, entonces... vas a necesitar mucho más que sangre, $gamigo:amiga;.', 0),
(@ID, 'esMX', 'Oh, es sangre. Entonces debe ser del maestro Mor\'zul. Está tan enamorado de las cosas y le encanta verlas derramadas. Yo, sin embargo, prefiero que corra por las venas de un pequeño roedor. Se mantiene caliente de esa manera... hasta que lo desee.$B$BEsta es sangre poderosa. ¡Mor\'zul debe estar haciendo otro pergamino para convocar a un corcel aterrador! ¡Que interesante!$B$BSi eso es cierto, y vas a realizar el ritual, entonces... vas a necesitar mucho más que sangre, $gamigo:amiga;.', 0);
