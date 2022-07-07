-- 2758 El origen de la herrería
-- https://es.classic.wowhead.com/quest=2758
SET @ID := 2758;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Podrías ser $gel próximo protegido:la próxima protegida; de Galván?', 0),
(@ID, 'esMX', '¿Podrías ser $gel próximo protegido:la próxima protegida; de Galván?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Escucha y aprende.$B$B¡La herrería nunca viene de aquí! <Hank señala su martillo.>$B$B¡La herrería nunca viene de aquí! <Hank señala el yunque.>$B$B¡La herrería solo viene de aquí! <Hank señala su corazón.>$B$BY ahora conoces el origen de la herrería.', 0),
(@ID, 'esMX', '¡Muy bien, $n! Escucha y aprende.$B$B¡La herrería nunca viene de aquí! <Hank señala su martillo.>$B$B¡La herrería nunca viene de aquí! <Hank señala el yunque.>$B$B¡La herrería solo viene de aquí! <Hank señala su corazón.>$B$BY ahora conoces el origen de la herrería.', 0);
-- 2759 Buscando a Galvan
-- https://es.classic.wowhead.com/quest=2759
SET @ID := 2759;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una raza rara tu especie, $gamigo:amiga;. Déjame ver esa insignia.', 0),
(@ID, 'esMX', 'Una raza rara tu especie, $gamigo:amiga;. Déjame ver esa insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por el pelo de la espalda de Pezuña Negra, ¡finalmente, $guno digno:una digna; de la Orden de Mithril!', 0),
(@ID, 'esMX', 'Por el pelo de la espalda de Pezuña Negra, ¡finalmente, $guno digno:una digna; de la Orden de Mithril!', 0);
-- 2760 La Orden del mitril
-- https://es.classic.wowhead.com/quest=2760
SET @ID := 2760;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Salve! Acércate; muéstrale a Galván lo que tienes.', 0),
(@ID, 'esMX', '¡Salve! Acércate; muéstrale a Galván lo que tienes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, han pasado muchos años desde el último digno de la iniciación de la orden del mithril. ¡Empezaremos ahora!', 0),
(@ID, 'esMX', 'Ah, han pasado muchos años desde el último digno de la iniciación de la orden del mithril. ¡Empezaremos ahora!', 0);
-- 2761 Funde o no funde
-- https://es.classic.wowhead.com/quest=2761
SET @ID := 2761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0),
(@ID, 'esMX', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tu ética de trabajo es impecable, $n! Estás comenzando a comprender la mineralogía de Galvan. ¡Toma esto y aprende todo lo que puedas!', 0),
(@ID, 'esMX', '¡Tu ética de trabajo es impecable, $n! Estás comenzando a comprender la mineralogía de Galvan. ¡Toma esto y aprende todo lo que puedas!', 0);
-- 2762 La veraplata no es verídica
-- https://es.classic.wowhead.com/quest=2762
SET @ID := 2762;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0),
(@ID, 'esMX', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una amante cruel, ¿no es así, $n? Estoy hablando de veraplata, naturalmente. Sí, Galván pasó más de una década en las montañas de Alterac aprendiendo esta lección. ¡Toma esto y aprende de él todo lo que puedas!', 0),
(@ID, 'esMX', 'Es una amante cruel, ¿no es así, $n? Estoy hablando de veraplata, naturalmente. Sí, Galván pasó más de una década en las montañas de Alterac aprendiendo esta lección. ¡Toma esto y aprende de él todo lo que puedas!', 0);
-- 2763 El arte de imbuir
-- https://es.classic.wowhead.com/quest=2763
SET @ID := 2763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0),
(@ID, 'esMX', 'Con tanta excavación, te han salido músculos y te duele el cuerpo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Uno apenas puede evitar que sus ojos abandonen su esplendor, $n. Sí, el citrino es una joya gloriosa.$B$B¡Presta atención y aprende lo que tal descubrimiento puede enseñarnos!', 0),
(@ID, 'esMX', 'Uno apenas puede evitar que sus ojos abandonen su esplendor, $n. Sí, el citrino es una joya gloriosa.$B$B¡Presta atención y aprende lo que tal descubrimiento puede enseñarnos!', 0);
-- 2764 El mejor alumno de Galvan
-- https://es.classic.wowhead.com/quest=2764
SET @ID := 2764;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Galván el Antiguo te envió?$B$B<Trenton se inclina.>$B$B¡Es un gran honor conocer a otro de los alumnos del maestro!', 0),
(@ID, 'esMX', '¿Galván el Antiguo te envió?$B$B<Trenton se inclina.>$B$B¡Es un gran honor conocer a otro de los alumnos del maestro!', 0);
-- 2765 ¡Experto herrero!
-- https://es.classic.wowhead.com/quest=2765
SET @ID := 2765;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo es justo que recibas un abalorio de mucho más poder que el que has sacrificado aquí. Utilízalo con buena salud, $n.', 0),
(@ID, 'esMX', 'Solo es justo que recibas un abalorio de mucho más poder que el que has sacrificado aquí. Utilízalo con buena salud, $n.', 0);
-- 2766 ¡Encuentra a OOX-22/FE!
-- https://es.classic.wowhead.com/quest=2766
SET @ID := 2766;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has descubierto la carcasa de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0),
(@ID, 'esMX', 'Parece que has descubierto la carcasa de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo... el localizador de emergencia... dentro del pollo... del robot mensajero.$B$BOyes murmullos y zumbidos dentro del robot mientras se esfuerza por levantarse. Cuando el robot vuelve a la vida, oyes la voz de Oglethorpe una vez más, pero ahora proviene del interior del robot:$B$B"¡OOX-22/FE está funcionando, pero necesita reparaciones! Pesa demasiado para que cargues con él, pero creo que tengo una idea. ¿Te apetece vigilarlo un poco más?"', 0),
(@ID, 'esMX', 'Colocas el huevo... el localizador de emergencia... dentro del pollo... del robot mensajero.$B$BOyes murmullos y zumbidos dentro del robot mientras se esfuerza por levantarse. Cuando el robot vuelve a la vida, oyes la voz de Oglethorpe una vez más, pero ahora proviene del interior del robot:$B$B"¡OOX-22/FE está funcionando, pero necesita reparaciones! Pesa demasiado para que cargues con él, pero creo que tengo una idea. ¿Te apetece vigilarlo un poco más?"', 0);
-- 2767 ¡Escolta a OOX-22/FE!
-- https://es.classic.wowhead.com/quest=2767
SET @ID := 2767;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí, soy Oglethorpe Obnoticus, maestro inventor a su servicio! Ahora, ¿hay algo en lo que pueda $gayudarlo:ayudarla;?', 0),
(@ID, 'esMX', '¡Sí, soy Oglethorpe Obnoticus, maestro inventor a su servicio! Ahora, ¿hay algo en lo que pueda $gayudarlo:ayudarla;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, eres el gran salvador de OOX-22/FE! ¡No sé ni cómo empezar a expresarte mi gratitud por tu ayuda! Aún necesito trabajar más en el desarrollo de mi serie de robots mensajeros, pero de momento, tu ayuda me ha ahorrado innumerables horas de reconstrucción, ¡y mucho dinero en costes de fabricación!$B$BPor favor, elige uno de estos objetos. Gracias de nuevo por tu valiosa ayuda, $n, ¡mis robots y yo estamos en deuda contigo!', 0),
(@ID, 'esMX', '¡Oh, eres el gran salvador de OOX-22/FE! ¡No sé ni cómo empezar a expresarte mi gratitud por tu ayuda! Aún necesito trabajar más en el desarrollo de mi serie de robots mensajeros, pero de momento, tu ayuda me ha ahorrado innumerables horas de reconstrucción, ¡y mucho dinero en costes de fabricación!$B$BPor favor, elige uno de estos objetos. Gracias de nuevo por tu valiosa ayuda, $n, ¡mis robots y yo estamos en deuda contigo!', 0);
-- 2771 La cabeza sobre los hombros
-- https://es.classic.wowhead.com/quest=2771
SET @ID := 2771;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado de confeccionar los objetos, $n?', 0),
(@ID, 'esMX', '¿Has acabado de confeccionar los objetos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Me parece un trato justo, modestia aparte. ¡Mira y aprende, $n!', 0),
(@ID, 'esMX', '¡Excelente! Me parece un trato justo, modestia aparte. ¡Mira y aprende, $n!', 0);
-- 2772 El mundo a tus pies
-- https://es.classic.wowhead.com/quest=2772
SET @ID := 2772;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado de confeccionar los objetos, $n?', 0),
(@ID, 'esMX', '¿Has acabado de confeccionar los objetos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El mundo estará a tus pies, $n! ¡Deja que todos lleguen a tus piernas, porque ahora eres imposible de barrer!', 0),
(@ID, 'esMX', '¡El mundo estará a tus pies, $n! ¡Deja que todos lleguen a tus piernas, porque ahora eres imposible de barrer!', 0);
-- 2773 El chico de mitril
-- https://es.classic.wowhead.com/quest=2773
SET @ID := 2773;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado de confeccionar los objetos, $n?', 0),
(@ID, 'esMX', '¿Has acabado de confeccionar los objetos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por todo lo que me has enseñado, $n. El dominio del conjunto de mithril adornado pronto será tuyo.$B$B¡Mira!', 0),
(@ID, 'esMX', 'Gracias por todo lo que me has enseñado, $n. El dominio del conjunto de mithril adornado pronto será tuyo.$B$B¡Mira!', 0);
-- 2782 El secreto de Rin'ji
-- https://es.classic.wowhead.com/quest=2782
SET @ID := 2782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, ¿qué es esto que me traes?', 0),
(@ID, 'esMX', 'Vaya, ¿qué es esto que me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué tablilla tan peculiar... ¿Dónde la encontraste, $n?', 0),
(@ID, 'esMX', 'Qué tablilla tan peculiar... ¿Dónde la encontraste, $n?', 0);
-- 2783 Peleas mezquinas
-- https://es.classic.wowhead.com/quest=2783
SET @ID := 2783;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Alianza desea ayudar?$B$BPensé que nunca volvería a ver este día. Un día en el que la Alianza lucha codo con codo con la Horda contra un enemigo común.$B$BSerá... nos uniremos.', 0),
(@ID, 'esMX', '¿La Alianza desea ayudar?$B$BPensé que nunca volvería a ver este día. Un día en el que la Alianza lucha codo con codo con la Horda contra un enemigo común.$B$BSerá... nos uniremos.', 0);
-- 2784 Pérdida de honor
-- https://es.classic.wowhead.com/quest=2784
SET @ID := 2784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escucha lo que tengo que decir.', 0),
(@ID, 'esMX', 'Escucha lo que tengo que decir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como espíritu, soy impotente, $n. Ayúdame. Permíteme que recupere mi honor.', 0),
(@ID, 'esMX', 'Como espíritu, soy impotente, $n. Ayúdame. Permíteme que recupere mi honor.', 0);
-- 2801 Una historia triste
-- https://es.classic.wowhead.com/quest=2801
SET @ID := 2801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escucha lo que tengo que decir, $n.', 0),
(@ID, 'esMX', 'Escucha lo que tengo que decir, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha llegado la hora de actuar, $n.', 0),
(@ID, 'esMX', 'Ha llegado la hora de actuar, $n.', 0);
-- 2821 La marca de la calidad
-- https://es.classic.wowhead.com/quest=2821
SET @ID := 2821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si me traes 10 pieles gruesas de yeti, te daré uno de mis artículos a elegir. Y como valoro la calidad, ¡puedo asegurarte de que será un buen artículo!$B$BSi no sabes dónde encontrar yetis, puedo indicarte un lugar en el que podrían estar. Busca tierra adentro desde La Costa Olvidada, por la Vega Cicatriz Feral.', 0),
(@ID, 'esMX', 'Si me traes 10 pieles gruesas de yeti, te daré uno de mis artículos a elegir. Y como valoro la calidad, ¡puedo asegurarte de que será un buen artículo!$B$BSi no sabes dónde encontrar yetis, puedo indicarte un lugar en el que podrían estar. Busca tierra adentro desde La Costa Olvidada, por la Vega Cicatriz Feral.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te paraste a examinar la textura de estos pellejos? Con el tratamiento adecuado, estos pellejos podrían ser más fuertes que el hierro. No mucha gente sabe de la existencia de estas pieles. Eso, combinado con los tratamientos que solo yo conozco, me permitirá crear objetos únicos, con un sello de calidad exclusivo y auténtico... ¡gracias a ti, claro!$B$BY ahora, por favor elige algo de lo que puedo ofrecerte por tus servicios.', 0),
(@ID, 'esMX', '¿Te paraste a examinar la textura de estos pellejos? Con el tratamiento adecuado, estos pellejos podrían ser más fuertes que el hierro. No mucha gente sabe de la existencia de estas pieles. Eso, combinado con los tratamientos que solo yo conozco, me permitirá crear objetos únicos, con un sello de calidad exclusivo y auténtico... ¡gracias a ti, claro!$B$BY ahora, por favor elige algo de lo que puedo ofrecerte por tus servicios.', 0);
-- 2822 La marca de la calidad
-- https://es.classic.wowhead.com/quest=2822
SET @ID := 2822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido reunir 10 pieles gruesas de yeti? Mis artículos de cuero son insuperables y, si tienes las pieles, compartiré contigo una muestra de mi trabajo.$B$BSi no sabes dónde encontrar yetis, puedo indicarte un lugar en el que podrían estar. Busca al oeste de aquí, tierra adentro desde La Costa Olvidada, por la Vega Cicatriz Feral.', 0),
(@ID, 'esMX', '¿Has conseguido reunir 10 pieles gruesas de yeti? Mis artículos de cuero son insuperables y, si tienes las pieles, compartiré contigo una muestra de mi trabajo.$B$BSi no sabes dónde encontrar yetis, puedo indicarte un lugar en el que podrían estar. Busca al oeste de aquí, tierra adentro desde La Costa Olvidada, por la Vega Cicatriz Feral.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, excelente! Cuando les dé mi tratamiento especial, estos pellejos serán tan resistentes como el hierro, ¡te lo digo yo! Tendré que hacer muchas pruebas para conseguir la mezcla correcta para curtirlas, pero sé que cuando lo consiga, mis productos tendrán una calidad superior y exclusiva.$B$BY, volviendo a ti, $n... tu ayuda ha sido valiosísima. Por favor, elige uno de estos objetos que he creado.', 0),
(@ID, 'esMX', '¡Excelente, excelente! Cuando les dé mi tratamiento especial, estos pellejos serán tan resistentes como el hierro, ¡te lo digo yo! Tendré que hacer muchas pruebas para conseguir la mezcla correcta para curtirlas, pero sé que cuando lo consiga, mis productos tendrán una calidad superior y exclusiva.$B$BY, volviendo a ti, $n... tu ayuda ha sido valiosísima. Por favor, elige uno de estos objetos que he creado.', 0);
-- 2841 Las guerras de la plataforma
-- https://es.classic.wowhead.com/quest=2841
SET @ID := 2841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los planos o has venido solo a irritarme?', 0),
(@ID, 'esMX', '¿Traes los planos o has venido solo a irritarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sabía que lo conseguirías! Sovik tenía sus dudas...$B$B<Nogg carraspea.>$B$BAhora que tenemos los planos, podremos estudiar las innovaciones gnómicas de la plataforma y adaptarlas al estilo goblin.', 0),
(@ID, 'esMX', '¡Sabía que lo conseguirías! Sovik tenía sus dudas...$B$B<Nogg carraspea.>$B$BAhora que tenemos los planos, podremos estudiar las innovaciones gnómicas de la plataforma y adaptarlas al estilo goblin.', 0);
-- 2842 Scooty, ingeniero jefe
-- https://es.classic.wowhead.com/quest=2842
SET @ID := 2842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífico, ¿verdad? Es lo mejor de la tecnología goblin, solo ha explotado una docena de veces.$B$BNo te preocupes, $n, ya está areglado y no explotará. Y si lo hace, al menos no te enterarás de nada.', 0),
(@ID, 'esMX', 'Magnífico, ¿verdad? Es lo mejor de la tecnología goblin, solo ha explotado una docena de veces.$B$BNo te preocupes, $n, ya está areglado y no explotará. Y si lo hace, al menos no te enterarás de nada.', 0);
-- 2843 ¡Gnomer-yaaaaa!
-- https://es.classic.wowhead.com/quest=2843
SET @ID := 2843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Está listo!', 0),
(@ID, 'esMX', '¡Está listo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Listo! ¡Cuando estés $gpreparado:preparada;, súbete a la plataforma!', 0),
(@ID, 'esMX', '¡Listo! ¡Cuando estés $gpreparado:preparada;, súbete a la plataforma!', 0);
-- 2844 El guardián gigante
-- https://es.classic.wowhead.com/quest=2844
SET @ID := 2844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, estoy tan contenta de que me hayas encontrado! Debo admitir que estoy un poco perdida... ¿Pero no es este un lugar hermoso?', 0),
(@ID, 'esMX', '¡Oh, estoy tan contenta de que me hayas encontrado! Debo admitir que estoy un poco perdida... ¿Pero no es este un lugar hermoso?', 0);
-- 2845 Las andanzas de Shay
-- https://es.classic.wowhead.com/quest=2845
SET @ID := 2845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me estaba \'preocupando\' por ti! Muchas gracias por traer a Shay a casa, $n.', 0),
(@ID, 'esMX', '¡Me estaba \'preocupando\' por ti! Muchas gracias por traer a Shay a casa, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Dices que la campana funcionará cuando Shay se escape? Bueno, ¿qué tal esto?$B$BYa que hiciste tanto por mí, aquí tienes, $n.', 0),
(@ID, 'esMX', '¿Qué? ¿Dices que la campana funcionará cuando Shay se escape? Bueno, ¿qué tal esto?$B$BYa que hiciste tanto por mí, aquí tienes, $n.', 0);
-- 2847 Armadura de cuero salvaje
-- https://es.classic.wowhead.com/quest=2847
SET @ID := 2847;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como dije, trabajarás para mí mientras aprendes sobre las armaduras de cuero salvaje. Debido a que las vides silvestres son potentes y caóticas, producen un beneficio aleatorio pero fuerte para la armadura que estarás haciendo. Este conocimiento, sin embargo, no fue fácil para mí.$B$BEl costo inicial para comenzar este proceso es de diez piezas de cuero grueso.$B$BUna vez hecho esto, nos ocuparemos del trabajo que necesitas hacer para obtener los patrones.', 0),
(@ID, 'esMX', 'Como dije, trabajarás para mí mientras aprendes sobre las armaduras de cuero salvaje. Debido a que las vides silvestres son potentes y caóticas, producen un beneficio aleatorio pero fuerte para la armadura que estarás haciendo. Este conocimiento, sin embargo, no fue fácil para mí.$B$BEl costo inicial para comenzar este proceso es de diez piezas de cuero grueso.$B$BUna vez hecho esto, nos ocuparemos del trabajo que necesitas hacer para obtener los patrones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, $n, me alegro de tenerte a bordo. Has tomado una decisión inteligente como $gpeletero:peletera;; los que usan armaduras de cuero te estarán clamando una vez que aprendas a hacer cualquiera de las piezas de armadura de cuero salvaje.$B$BPongámonos manos a la obra. ¿Por dónde quieres empezar?', 0),
(@ID, 'esMX', 'Bueno, $n, me alegro de tenerte a bordo. Has tomado una decisión inteligente como $gpeletero:peletera;; los que usan armaduras de cuero te estarán clamando una vez que aprendas a hacer cualquiera de las piezas de armadura de cuero salvaje.$B$BPongámonos manos a la obra. ¿Por dónde quieres empezar?', 0);
-- 2848 Sobrehombros de cuero salvaje
-- https://es.classic.wowhead.com/quest=2848
SET @ID := 2848;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los seis refuerzos de armadura gruesa y la atriplex salvaje que necesito?$B$BNo pienses en hacer kits de armadura como un trabajo monótono; el método de modelado constante que desarrollas a medida que ejerces tu oficio en estos kits, ayuda a desarrollar tus habilidades para el intrincado trabajo necesario para fabricar armaduras de cuero salvaje.$B$BMira, hay una razón real detrás de lo que estás haciendo para mí...', 0),
(@ID, 'esMX', '¿Tienes los seis refuerzos de armadura gruesa y la atriplex salvaje que necesito?$B$BNo pienses en hacer kits de armadura como un trabajo monótono; el método de modelado constante que desarrollas a medida que ejerces tu oficio en estos kits, ayuda a desarrollar tus habilidades para el intrincado trabajo necesario para fabricar armaduras de cuero salvaje.$B$BMira, hay una razón real detrás de lo que estás haciendo para mí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos kits de armadura son de calidad sólida, $n. Si hay algo que exijo no solo en mi trabajo, sino en el trabajo de los que están a mi servicio, es calidad.$B$BHas hecho bien en ganar este patrón; Espero que te traiga las recompensas que me ha traído.', 0),
(@ID, 'esMX', 'Estos kits de armadura son de calidad sólida, $n. Si hay algo que exijo no solo en mi trabajo, sino en el trabajo de los que están a mi servicio, es calidad.$B$BHas hecho bien en ganar este patrón; Espero que te traiga las recompensas que me ha traído.', 0);
-- 2849 El Jubón de cuero salvaje
-- https://es.classic.wowhead.com/quest=2849
SET @ID := 2849;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienen las dos corazas y guantes de caparazón de tortuga que te pedí? Además, ¡no te olvides de la atriplex!$B$BIncluso con los patrones más antiguos, aprendemos que los fundamentos de la forma se traducen bien en prendas más difíciles. Aunque son elementos diferentes, la forma de los petos de Tortuga te aporta lo necesario para hacer un chaleco de cuero salvaje.$B$BY los guantes... bueno, son solo para mi propio beneficio. Recuerda, ¡estás trabajando para mí!', 0),
(@ID, 'esMX', '¿Tienen las dos corazas y guantes de caparazón de tortuga que te pedí? Además, ¡no te olvides de la atriplex!$B$BIncluso con los patrones más antiguos, aprendemos que los fundamentos de la forma se traducen bien en prendas más difíciles. Aunque son elementos diferentes, la forma de los petos de Tortuga te aporta lo necesario para hacer un chaleco de cuero salvaje.$B$BY los guantes... bueno, son solo para mi propio beneficio. Recuerda, ¡estás trabajando para mí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son algunas piezas muy bonitas, $n. La artesanía y el cuidado puesto en su fabricación proporcionará varias monedas de plata más de lo normal.$B$BHas cumplido mi pedido y ahora viene tu recompensa. ¡El conocimiento de la fabricación de jubones de cuero salvaje ahora es suyo!', 0),
(@ID, 'esMX', 'Estas son algunas piezas muy bonitas, $n. La artesanía y el cuidado puesto en su fabricación proporcionará varias monedas de plata más de lo normal.$B$BHas cumplido mi pedido y ahora viene tu recompensa. ¡El conocimiento de la fabricación de jubones de cuero salvaje ahora es suyo!', 0);
-- 2850 Casco de cuero salvaje
-- https://es.classic.wowhead.com/quest=2850
SET @ID := 2850;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito que me hagas esas guerreras y cintas de pelo, y también necesito ese trozo de atriplex salvaje antes de poder compartir contigo el conocimiento de los cascos de cuero salvaje.$B$BLos accesorios para la cabeza son muy codiciados entre los aventureros, ya sea una diadema simple o un casco que lo cubra por completo. Los fundamentos de la creación de un valioso equipo para la cabeza permanecen constantes, sin importar la apariencia estética del equipo.', 0),
(@ID, 'esMX', 'Necesito que me hagas esas guerreras y cintas de pelo, y también necesito ese trozo de atriplex salvaje antes de poder compartir contigo el conocimiento de los cascos de cuero salvaje.$B$BLos accesorios para la cabeza son muy codiciados entre los aventureros, ya sea una diadema simple o un casco que lo cubra por completo. Los fundamentos de la creación de un valioso equipo para la cabeza permanecen constantes, sin importar la apariencia estética del equipo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este equipo Nochefugaz que has traido cumple perfectamente, $n. No espero menos de $gun peletero:una peletera; de tu calibre.$B$BDefinitivamente te has ganado este patrón. Te lo doy gratuitamente y espero que te beneficies de él en consecuencia.', 0),
(@ID, 'esMX', 'Este equipo Nochefugaz que has traido cumple perfectamente, $n. No espero menos de $gun peletero:una peletera; de tu calibre.$B$BDefinitivamente te has ganado este patrón. Te lo doy gratuitamente y espero que te beneficies de él en consecuencia.', 0);
-- 2851 Botas de cuero salvaje
-- https://es.classic.wowhead.com/quest=2851
SET @ID := 2851;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pedido de pantalones, botas y atriplex salvaje debe completarse antes de obtener el patrón, $n. ¿Terminaste?$B$BDesde el primer par de botas que aprendemos a fabricar, comenzamos a comprender que una bota de calidad necesita ir al filo de la navaja entre comodidad y funcionalidad. Con ambos, podemos crear artículos que permiten al usuario ignorar la fatiga que paralizaría a quienes usan artículos de menor calidad.', 0),
(@ID, 'esMX', 'El pedido de pantalones, botas y atriplex salvaje debe completarse antes de obtener el patrón, $n. ¿Terminaste?$B$BDesde el primer par de botas que aprendemos a fabricar, comenzamos a comprender que una bota de calidad necesita ir al filo de la navaja entre comodidad y funcionalidad. Con ambos, podemos crear artículos que permiten al usuario ignorar la fatiga que paralizaría a quienes usan artículos de menor calidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más, has completado un pedido complejo con la habilidad de un profesional experimentado. Te has ganado este patrón, así como mi agradecimiento.', 0),
(@ID, 'esMX', 'Una vez más, has completado un pedido complejo con la habilidad de un profesional experimentado. Te has ganado este patrón, así como mi agradecimiento.', 0);
-- 2852 Leotardos de cuero salvaje
-- https://es.classic.wowhead.com/quest=2852
SET @ID := 2852;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes listos los yelmos y los brazales de caparazón de tortuga ? ¡No olvides las dos atriplex salvajes que necesito!$B$BA estas alturas, estás empezando a darte cuenta del poder potencial que tiene la armadura de cuero salvaje. Una armadura que no tiene límites en la aplicación es de valor incalculable para un peletero. Los límites están solo en la cantidad de recursos para fabricar los artículos, ¡no en la calidad de los productos terminados!', 0),
(@ID, 'esMX', '¿Tienes listos los yelmos y los brazales de caparazón de tortuga ? ¡No olvides las dos atriplex salvajes que necesito!$B$BA estas alturas, estás empezando a darte cuenta del poder potencial que tiene la armadura de cuero salvaje. Una armadura que no tiene límites en la aplicación es de valor incalculable para un peletero. Los límites están solo en la cantidad de recursos para fabricar los artículos, ¡no en la calidad de los productos terminados!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuevamente, has completado un pedido sin problemas. Quizás algún día vendré a ti en busca de conocimiento, ¿eh $n?$B$BAquí está el patrón de los leotardos, junto con mi agradecimiento. ¡Aplica este conocimiento y deja que tus productos terminados aprovechen tus impresionantes habilidades!', 0),
(@ID, 'esMX', 'Nuevamente, has completado un pedido sin problemas. Quizás algún día vendré a ti en busca de conocimiento, ¿eh $n?$B$BAquí está el patrón de los leotardos, junto con mi agradecimiento. ¡Aplica este conocimiento y deja que tus productos terminados aprovechen tus impresionantes habilidades!', 0);
