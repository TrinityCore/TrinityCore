-- 6610 Sorpresa de almejate
-- https://es.classic.wowhead.com/quest=6610
SET @ID := 6610;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya no aguanto más! Date prisa, $n, antes de que eche mano de mis propias provisiones.', 0),
(@ID, 'esMX', '¡Ya no aguanto más! Date prisa, $n, antes de que eche mano de mis propias provisiones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Verás qué festín, $n! ¡Mira y aprende!$B$B<Dirge comienza a preparar la sorpresa de almeja.>', 0),
(@ID, 'esMX', '¡Verás qué festín, $n! ¡Mira y aprende!$B$B<Dirge comienza a preparar la sorpresa de almeja.>', 0);
-- 6611 Ve a Gadgetzan
-- 6612 Conozco a un tío...
-- https://es.classic.wowhead.com/quest=6611
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6611, 6612) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6611, 'esES', '<Dirge escupe trozos de cuero.>$B$BPuaj.$B$B<Tose violentamente.>$B$B¿Qué pasa? Que sepas que el cuero tiene muchas proteínas y es bajo en carbohidratos.', 0),
(6612, 'esES', '<Dirge escupe trozos de cuero.>$B$BPuaj.$B$B<Tose violentamente.>$B$B¿Qué pasa? Que sepas que el cuero tiene muchas proteínas y es bajo en carbohidratos.', 0),
(6611, 'esMX', '<Dirge escupe trozos de cuero.>$B$BPuaj.$B$B<Tose violentamente.>$B$B¿Qué pasa? Que sepas que el cuero tiene muchas proteínas y es bajo en carbohidratos.', 0),
(6612, 'esMX', '<Dirge escupe trozos de cuero.>$B$BPuaj.$B$B<Tose violentamente.>$B$B¿Qué pasa? Que sepas que el cuero tiene muchas proteínas y es bajo en carbohidratos.', 0);
-- 6621 El rey de los Maderiza
-- https://es.classic.wowhead.com/quest=6621
SET @ID := 6621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado al jefe Murgut, $n? ¿Has recuperado el tótem Corrupto?', 0),
(@ID, 'esMX', '¿Has derrotado al jefe Murgut, $n? ¿Has recuperado el tótem Corrupto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Has desafiado a los Corruptos y al derrotar a su líder les has enviado un mensaje contundente.$B$BNo se puede molestar a la Horda.$B$BNo creo que esa tribu vuelva a darnos problemas en mucho tiempo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Has desafiado a los Corruptos y al derrotar a su líder les has enviado un mensaje contundente.$B$BNo se puede molestar a la Horda.$B$BNo creo que esa tribu vuelva a darnos problemas en mucho tiempo.', 0);
-- 6622 La selección
-- https://es.classic.wowhead.com/quest=6622
SET @ID := 6622;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Obra milagrosa, doctor. Simplemente milagroso.', 0),
(@ID, 'esMX', 'Obra milagrosa, doctor. Simplemente milagroso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Doctor $n, bienvenido al Dispensario de la Horda.', 0),
(@ID, 'esMX', 'Doctor $n, bienvenido al Dispensario de la Horda.', 0);
-- 6623 Dispensario de la Horda
-- https://es.classic.wowhead.com/quest=6623
SET @ID := 6623;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maravilloso. ¡Ponte la bata, vamos a empezar de inmediato!', 0),
(@ID, 'esMX', 'Maravilloso. ¡Ponte la bata, vamos a empezar de inmediato!', 0);
-- 6624 Orden de gravedad
-- https://es.classic.wowhead.com/quest=6624
SET @ID := 6624;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Obra milagrosa, doctor. Simplemente milagroso.', 0),
(@ID, 'esMX', 'Obra milagrosa, doctor. Simplemente milagroso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Doctor $n, bienvenido al Dispensario de la Alianza.', 0),
(@ID, 'esMX', 'Doctor $n, bienvenido al Dispensario de la Alianza.', 0);
-- 6625 El Dispensario de la Alianza
-- https://es.classic.wowhead.com/quest=6625
SET @ID := 6625;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, ¡ponte la bata y empecemos!', 0),
(@ID, 'esMX', 'Bien, ¡ponte la bata y empecemos!', 0);
-- 6626 Un anfitrión del mal
-- https://es.classic.wowhead.com/quest=6626
SET @ID := 6626;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $n? Ver solo esta pequeña muestra del poder del diplomático elimina cualquier duda que tenía de que la Plaga es una de las mayores amenazas que este mundo haya visto.', 0),
(@ID, 'esMX', '¿Cómo va la caza, $n? Ver solo esta pequeña muestra del poder del diplomático elimina cualquier duda que tenía de que la Plaga es una de las mayores amenazas que este mundo haya visto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Nos has prestado un gran servicio.$B$BVoy a seguir investigando al diplomático; si quieres más aventuras, coge a unos amigos y ve a la caverna con forma de hocico de jabalí. Allí encontrarás toda la aventura que quieras.', 0),
(@ID, 'esMX', '¡Gracias, $n! Nos has prestado un gran servicio.$B$BVoy a seguir investigando al diplomático; si quieres más aventuras, coge a unos amigos y ve a la caverna con forma de hocico de jabalí. Allí encontrarás toda la aventura que quieras.', 0);
-- 6627 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=6627
SET @ID := 6627;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La vida está llena de preguntas, $n. Nunca podrás contestarlas todas, pero con algo de tiempo y estudio, tal vez adquieras más conocimientos.', 0),
(@ID, 'esMX', 'La vida está llena de preguntas, $n. Nunca podrás contestarlas todas, pero con algo de tiempo y estudio, tal vez adquieras más conocimientos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c. Has estudiado el libro tal como te pedí y has superado con éxito una prueba más.', 0),
(@ID, 'esMX', 'Muy bien, $c. Has estudiado el libro tal como te pedí y has superado con éxito una prueba más.', 0);
-- 6628 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=6628
SET @ID := 6628;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo hay una regla que creo que debes saber si deseas sobrevivir en este mundo: cuanto más sepas, más verás.$B$BSi estudias, si observas, empezarás a ver cosas en el mundo que $gningún otro:ninguna otra; $r verá.', 0),
(@ID, 'esMX', 'Solo hay una regla que creo que debes saber si deseas sobrevivir en este mundo: cuanto más sepas, más verás.$B$BSi estudias, si observas, empezarás a ver cosas en el mundo que $gningún otro:ninguna otra; $r verá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. No confiaba en que hubieras estudiado el libro pero has contestado correctamente.', 0),
(@ID, 'esMX', 'Muy bien, $n. No confiaba en que hubieras estudiado el libro pero has contestado correctamente.', 0);
-- 6629 Mata a Grundig Nube Negra
-- https://es.classic.wowhead.com/quest=6629
SET @ID := 6629;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Grundig Nube Negra y su banda personal de Toscos?', 0),
(@ID, 'esMX', '¿Has matado a Grundig Nube Negra y su banda personal de Toscos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Grundig Nube Negra está muerto! $n, te agradeceré eternamente lo que has hecho aquí hoy.', 0),
(@ID, 'esMX', '¡Grundig Nube Negra está muerto! $n, te agradeceré eternamente lo que has hecho aquí hoy.', 0);
-- 6641 Vorsha la Azotadora
-- https://es.classic.wowhead.com/quest=6641
SET @ID := 6641;
UPDATE `quest_template_locale` SET `Objectives` = 'Mantén a salvo a Muglash en su viaje hacia el blandón. Ayúdalo a apagar el blandón y entonces protégelo frente a los nagas.$B$BSi sales $gairoso:airosa;, vuelve a la Avanzada de Zoram\'gar e informa al corredor Grito de Guerra sobre la muerte de Vorsha la Azotadora.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He presenciado muchos ataques de los nagas desde que llegué a este lugar. Saber que Vorsha ya no anda suelto sin duda es un alivio.$B$BEstamos en deuda contigo, $n.', 0),
(@ID, 'esMX', 'He presenciado muchos ataques de los nagas desde que llegué a este lugar. Saber que Vorsha ya no anda suelto sin duda es un alivio.$B$BEstamos en deuda contigo, $n.', 0);
-- 6642 El favor de la Hermandad, mena de hierro negro
-- https://es.classic.wowhead.com/quest=6642
SET @ID := 6642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Hierro Negro, aunque abunda en las Profundidades, sigue siendo un bien valioso para la Hermandad. Los sagrados brazos y armas de Ragnaros favorecen a la Hermandad.$B$BPor cada 10 piezas de Mena de Hierro Negro que ofrezcas, ganarás el favor de la Hermandad.', 0),
(@ID, 'esMX', 'El Hierro Negro, aunque abunda en las Profundidades, sigue siendo un bien valioso para la Hermandad. Los sagrados brazos y armas de Ragnaros favorecen a la Hermandad.$B$BPor cada 10 piezas de Mena de Hierro Negro que ofrezcas, ganarás el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0),
(@ID, 'esMX', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0);
-- 6643 El favor de la Hermandad, núcleos ígneos
-- https://es.classic.wowhead.com/quest=6643
SET @ID := 6643;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay de aquellos que tientan al destino dentro del Núcleo Fundido! La muerte llega rápidamente: el castigo se inflige sin piedad.$B$BMuchos miembros de la Hermandad se han perdido en su búsqueda de Núcleos ígneos.$B$BOfrece 1 núcleo ígneo y recibirás el favor de la Hermandad.', 0),
(@ID, 'esMX', '¡Ay de aquellos que tientan al destino dentro del Núcleo Fundido! La muerte llega rápidamente: el castigo se inflige sin piedad.$B$BMuchos miembros de la Hermandad se han perdido en su búsqueda de Núcleos ígneos.$B$BOfrece 1 núcleo ígneo y recibirás el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0),
(@ID, 'esMX', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0);
-- 6644 El favor de la Hermandad, núcleo de lava
-- https://es.classic.wowhead.com/quest=6644
SET @ID := 6644;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Hermandad del torio comprende tu difícil situación, $r. Por eso se ha autorizado a Lokthos a negociar.$B$BOfréceme 1 núcleo de lava y se te concederá el favor de la Hermandad.', 0),
(@ID, 'esMX', 'La Hermandad del torio comprende tu difícil situación, $r. Por eso se ha autorizado a Lokthos a negociar.$B$BOfréceme 1 núcleo de lava y se te concederá el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0),
(@ID, 'esMX', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0);
-- 6645 El favor de la Hermandad, cuero del núcleo
-- https://es.classic.wowhead.com/quest=6645
SET @ID := 6645;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas de las recetas sagradas requieren la piel de las mascotas elegidas por Ragnaros.$B$BOfrece 2 Cueros del núcleo, desollado de los cadáveres humeantes de los Canes del Núcleo del Núcleo fundido y obtendrás el favor de la Hermandad.', 0),
(@ID, 'esMX', 'Muchas de las recetas sagradas requieren la piel de las mascotas elegidas por Ragnaros.$B$BOfrece 2 Cueros del núcleo, desollado de los cadáveres humeantes de los Canes del Núcleo del Núcleo fundido y obtendrás el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0),
(@ID, 'esMX', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0);
-- 6646 El favor de la Hermandad, gota de sangre de la montaña
-- https://es.classic.wowhead.com/quest=6646
SET @ID := 6646;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las lágrimas del Señor del Fuego son un hallazgo raro.$B$BOfrece 1 sangre de la montaña y recibirás el favor de la Hermandad.', 0),
(@ID, 'esMX', 'Las lágrimas del Señor del Fuego son un hallazgo raro.$B$BOfrece 1 sangre de la montaña y recibirás el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0),
(@ID, 'esMX', 'Tu ofrenda ha sido aceptada. El favor has obtenido. Sigue así y se te permitirá el acceso a los negocios ancestrales.', 0);
-- 6661 A por las ratas del tranvía subterráneo
-- https://es.classic.wowhead.com/quest=6661
SET @ID := 6661;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ratas capturadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Esto va bien, $gamigo:amiga;. Mi hermano las necesita vivitas y coleando, de lo contrario se ponen amargas... No querrás probar ninguna brocheta de rata agria.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 6681 Mansión Ravenholdt
-- https://es.classic.wowhead.com/quest=6681
SET @ID := 6681;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Rito de la Astucia', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conocido a Milton?$B$B<Se ríe.>', 0),
(@ID, 'esMX', '¿Has conocido a Milton?$B$B<Se ríe.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente.$B$BHa sido duro, pero pareces estar bien.$B$BTe espera un viaje largo y gratificante. ¿Te atreves a aceptar tu destino entre los señores de Ravenholdt?$B$BHabla con los guardias, te explicarán qué debes hacer.', 0),
(@ID, 'esMX', 'Excelente.$B$BHa sido duro, pero pareces estar bien.$B$BTe espera un viaje largo y gratificante. ¿Te atreves a aceptar tu destino entre los señores de Ravenholdt?$B$BHabla con los guardias, te explicarán qué debes hacer.', 0);
-- 6701 Emblemas de la Hermandad
-- https://es.classic.wowhead.com/quest=6701
SET @ID := 6701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace años que luchamos contra la Hermandad. Lo que les falta en habilidad lo compensan con cantidad; ¡no llegamos a matar los suficientes para reducir su población!$B$BHemos descubierto que el mejor método es robar sus emblemas. Cuando algún miembro pierde el suyo, digamos que el propio sistema lo elimina.$B$BRóbales los emblemas y dámelos a mí o a uno de los guardias.$B$BEmpieza por Durnholde, al sur de aquí.', 0),
(@ID, 'esMX', 'Hace años que luchamos contra la Hermandad. Lo que les falta en habilidad lo compensan con cantidad; ¡no llegamos a matar los suficientes para reducir su población!$B$BHemos descubierto que el mejor método es robar sus emblemas. Cuando algún miembro pierde el suyo, digamos que el propio sistema lo elimina.$B$BRóbales los emblemas y dámelos a mí o a uno de los guardias.$B$BEmpieza por Durnholde, al sur de aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Sigue así y a lo mejor los demás hasta te respetan un poco.', 0),
(@ID, 'esMX', '¡Buen trabajo! Sigue así y a lo mejor los demás hasta te respetan un poco.', 0);
-- 6721 El camino del cazador
-- https://es.classic.wowhead.com/quest=6721
SET @ID := 6721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, es el momento, $n.', 0),
(@ID, 'esMX', 'Sí, es el momento, $n.', 0);
-- 6741 ¡Más botines!
-- https://es.classic.wowhead.com/quest=6741
SET @ID := 6741;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Necesito más restos de armadura, $n! ¿Tienes alguno?', 0),
(@ID, 'esMX', '¡Necesito más restos de armadura, $n! ¿Tienes alguno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias otra vez, $n. Eres motivo de orgullo para la Horda.', 0),
(@ID, 'esMX', 'Gracias otra vez, $n. Eres motivo de orgullo para la Horda.', 0);
-- 6781 Más restos de armadura
-- https://es.classic.wowhead.com/quest=6781
SET @ID := 6781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡necesitamos más restos de armadura para los suministros de nuestros soldados!', 0),
(@ID, 'esMX', '$n, ¡necesitamos más restos de armadura para los suministros de nuestros soldados!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas piezas son muy buenas, $n. Puedo usarlas para confeccionar nuevos equipos para nuestros soldados.$B$BSi mi nivel de suministro llega a ser suficientemente alto, ¡a lo mejor nuestras avezadas unidades de combate irán al campo de batalla!', 0),
(@ID, 'esMX', 'Estas piezas son muy buenas, $n. Puedo usarlas para confeccionar nuevos equipos para nuestros soldados.$B$BSi mi nivel de suministro llega a ser suficientemente alto, ¡a lo mejor nuestras avezadas unidades de combate irán al campo de batalla!', 0);
-- 6801 Lokholar, el Señor del Hielo
-- https://es.classic.wowhead.com/quest=6801
SET @ID := 6801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vengo de Cima del Trueno, $r. El propio Cairne ha decidido que ayude al clan Lobo Gélido en estos amargos tiempos.$B$BPero no perdamos más el tiempo. Debes atacar a nuestros enemigos y traerme su sangre. Cuando tenga suficiente sangre, podrá empezar el ritual del conjuro.$B$BLa victoria estará garantizada cuando el Señor Elemental quede liberado sobre el ejército de los Pico Tormenta.', 0),
(@ID, 'esMX', 'Vengo de Cima del Trueno, $r. El propio Cairne ha decidido que ayude al clan Lobo Gélido en estos amargos tiempos.$B$BPero no perdamos más el tiempo. Debes atacar a nuestros enemigos y traerme su sangre. Cuando tenga suficiente sangre, podrá empezar el ritual del conjuro.$B$BLa victoria estará garantizada cuando el Señor Elemental quede liberado sobre el ejército de los Pico Tormenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se ha derramado sangre enemiga. Mezclaré esta sangre con el resto de elementos que hemos recolectado. Cuando la ofrenda esté completa, el Señor del Hielo enseñará a esos perros Pico Tormenta ¡toda la ira del clan Lobo Gélido!', 0),
(@ID, 'esMX', 'Se ha derramado sangre enemiga. Mezclaré esta sangre con el resto de elementos que hemos recolectado. Cuando la ofrenda esté completa, el Señor del Hielo enseñará a esos perros Pico Tormenta ¡toda la ira del clan Lobo Gélido!', 0);
-- 6804 Agua envenenada
-- https://es.classic.wowhead.com/quest=6804
SET @ID := 6804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los brazales?', 0),
(@ID, 'esMX', '¿Tienes los brazales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c. Esos elementales eran una ofensa a todos los seres del agua. Nuestra fuerza reside en la pureza y la necesitamos para ganar esta guerra.', 0),
(@ID, 'esMX', 'Buen trabajo, $c. Esos elementales eran una ofensa a todos los seres del agua. Nuestra fuerza reside en la pureza y la necesitamos para ganar esta guerra.', 0);
-- 6805 Sirocosos y reptarenas
-- https://es.classic.wowhead.com/quest=6805
SET @ID := 6805;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cobardía no es algo que valoremos, $c. Ve a Silithus y demuestra tu valentía.', 0),
(@ID, 'esMX', 'La cobardía no es algo que valoremos, $c. Ve a Silithus y demuestra tu valentía.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu valía. Puede que tenga más tareas para ti, dignas de un aliado de los Señores del Agua.', 0),
(@ID, 'esMX', 'Has demostrado tu valía. Puede que tenga más tareas para ti, dignas de un aliado de los Señores del Agua.', 0);
-- 6821 Ojo del Brasadivino
-- https://es.classic.wowhead.com/quest=6821
SET @ID := 6821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el ojo? ¿Osaste entrar en Cumbre de Roca Negra?', 0),
(@ID, 'esMX', '¿Traes el ojo? ¿Osaste entrar en Cumbre de Roca Negra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado que tienes fuerza y astucia.$B$BCreo que ganarás muchos honores en nuestras filas...', 0),
(@ID, 'esMX', 'Has demostrado que tienes fuerza y astucia.$B$BCreo que ganarás muchos honores en nuestras filas...', 0);
-- 6822 El Núcleo de Magma
-- https://es.classic.wowhead.com/quest=6822
SET @ID := 6822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu éxito en el Núcleo de Magma te espera, $n.', 0),
(@ID, 'esMX', 'Tu éxito en el Núcleo de Magma te espera, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo imposible: ¡enfrentarte a los seres del Núcleo de Magma y vivir para contarlo!$B$BTienes muchos recursos pese a tu pequeño tamaño.$B$BEspero que algún día se forme una alianza entre tu raza y los Señores del Agua.', 0),
(@ID, 'esMX', 'Has hecho lo imposible: ¡enfrentarte a los seres del Núcleo de Magma y vivir para contarlo!$B$BTienes muchos recursos pese a tu pequeño tamaño.$B$BEspero que algún día se forme una alianza entre tu raza y los Señores del Agua.', 0);
-- 6823 Agente de Hydraxis
-- https://es.classic.wowhead.com/quest=6823
SET @ID := 6823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se habla de tus hazañas en todos los salones de los Señores del Agua, $n. Había quien pensaba que tu raza es demasiado pequeña y frágil, pero has conseguido lo imposible: te has ganado nuestro respeto.', 0),
(@ID, 'esMX', 'Se habla de tus hazañas en todos los salones de los Señores del Agua, $n. Había quien pensaba que tu raza es demasiado pequeña y frágil, pero has conseguido lo imposible: te has ganado nuestro respeto.', 0);
-- 6824 Las manos de los enemigos
-- https://es.classic.wowhead.com/quest=6824
SET @ID := 6824;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Lucifron y los otros, $n? ¿Me traes las manos del enemigo?', 0),
(@ID, 'esMX', '¿Has derrotado a Lucifron y los otros, $n? ¿Me traes las manos del enemigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has eliminado a los capitanes! Si no fuera porque sé de lo que eres capaz, no me lo creería.$B$B$n, has demostrado antes tu valor, pero esta hazaña será cantada en los salones de los Señores del Agua. Te vas a convertir en una leyenda.$B$BVuelve a hablar conmigo; puede que tenga otra misión.', 0),
(@ID, 'esMX', '¡Has eliminado a los capitanes! Si no fuera porque sé de lo que eres capaz, no me lo creería.$B$B$n, has demostrado antes tu valor, pero esta hazaña será cantada en los salones de los Señores del Agua. Te vas a convertir en una leyenda.$B$BVuelve a hablar conmigo; puede que tenga otra misión.', 0);
-- 6825 La llamada del aire: flota de Guse
-- https://es.classic.wowhead.com/quest=6825
SET @ID := 6825;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos que preparar la nueva flota de alas de guerra, $r! Mis jinetes están listos para un ataque sobre el campo de batalla central pero primero hay que despertar su apetito... prepararlos para el asalto.$B$BNecesito carne de soldados Pico Tormenta, ¡como para alimentar a una flota! ¡Cientos de kilos! Seguro que puedes encargarte de eso, ¿verdad? ¡Andando!', 0),
(@ID, 'esMX', 'Tenemos que preparar la nueva flota de alas de guerra, $r! Mis jinetes están listos para un ataque sobre el campo de batalla central pero primero hay que despertar su apetito... prepararlos para el asalto.$B$BNecesito carne de soldados Pico Tormenta, ¡como para alimentar a una flota! ¡Cientos de kilos! Seguro que puedes encargarte de eso, ¿verdad? ¡Andando!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La flota se alimenta de su carne. Consume al enemigo.$B$B¡El vuelo es inminente!', 0),
(@ID, 'esMX', 'La flota se alimenta de su carne. Consume al enemigo.$B$B¡El vuelo es inminente!', 0);
-- 6826 La llamada del aire: flota de Jeztor
-- https://es.classic.wowhead.com/quest=6826
SET @ID := 6826;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has trabajado duro, $n, ¡pero es solo el principio!$B$BMis alas de guerra deben probar la misma carne de sus objetivos. ¡Esto garantizará un ataque preciso sobre nuestros enemigos!$B$BMi flota es la segunda más potente de nuestro mando aéreo. Por consiguiente, atacarán a los más poderosos de nuestros adversarios. Para ello, necesitan la carne de los tenientes Pico Tormenta.$B$B¡Apúrate, soldado!', 0),
(@ID, 'esMX', 'Has trabajado duro, $n, ¡pero es solo el principio!$B$BMis alas de guerra deben probar la misma carne de sus objetivos. ¡Esto garantizará un ataque preciso sobre nuestros enemigos!$B$BMi flota es la segunda más potente de nuestro mando aéreo. Por consiguiente, atacarán a los más poderosos de nuestros adversarios. Para ello, necesitan la carne de los tenientes Pico Tormenta.$B$B¡Apúrate, soldado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Más! ¡Más! ¡Tráeme más, que pronto estarán listos!', 0),
(@ID, 'esMX', '¡Más! ¡Más! ¡Tráeme más, que pronto estarán listos!', 0);
-- 6827 La llamada del aire: flota de Mulverick
-- https://es.classic.wowhead.com/quest=6827
SET @ID := 6827;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He pasado días encerrado en un horrible antro de enanos. ¡Vaya si quiero venganza!$B$BDebemos planificarlo minuciosamente.$B$BPrimero mis alas de guerra necesitan objetivos a los que apuntar, objetivos de alta prioridad. Tendré que alimentarlos con carne de los Comandantes Pico Tormenta. Por desgracia, ¡esos malnacidos están atrincherados muy lejos detrás de las líneas enemigas! Ahí tienes un trabajo a tu medida.', 0),
(@ID, 'esMX', 'He pasado días encerrado en un horrible antro de enanos. ¡Vaya si quiero venganza!$B$BDebemos planificarlo minuciosamente.$B$BPrimero mis alas de guerra necesitan objetivos a los que apuntar, objetivos de alta prioridad. Tendré que alimentarlos con carne de los Comandantes Pico Tormenta. Por desgracia, ¡esos malnacidos están atrincherados muy lejos detrás de las líneas enemigas! Ahí tienes un trabajo a tu medida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No hay suficiente! Esperaría este nivel de trabajo de un Iniciado ¡¿pero de ti, $n?! ¡Vamos, soldado! ¡DATE PRISA! ¡Hace falta más carne!', 0),
(@ID, 'esMX', '¡No hay suficiente! Esperaría este nivel de trabajo de un Iniciado ¡¿pero de ti, $n?! ¡Vamos, soldado! ¡DATE PRISA! ¡Hace falta más carne!', 0);
-- 6846 ¡Al ataque!
-- https://es.classic.wowhead.com/quest=6846
SET @ID := 6846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis tropas están abastecidas y listas para atacar. ¡Solo necesitamos órdenes de Noreg Pico Tormenta y los enviaré a la refriega!', 0),
(@ID, 'esMX', 'Mis tropas están abastecidas y listas para atacar. ¡Solo necesitamos órdenes de Noreg Pico Tormenta y los enviaré a la refriega!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, las órdenes! Dicen que debo atacar a voluntad, y mi voluntad dice... ¡ahora!', 0),
(@ID, 'esMX', '¡Ah, las órdenes! Dicen que debo atacar a voluntad, y mi voluntad dice... ¡ahora!', 0);
-- 6881 Ivus, el Señor del Bosque
-- https://es.classic.wowhead.com/quest=6881
SET @ID := 6881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El clan Lobo Gélido está protegido por una contaminación de energía elemental. Su chamán anda metido con poderes que seguramente nos aniquilarían si no nos ocupamos de ellos.$B$B¡El daño se ha extendido demasiado para que el Círculo lo controle! Tenemos que invocar a Ivus para que nos ayude.$B$BLos soldados Lobo Gélido llevan talismanes de elemental llamados cristales de tormenta. Podemos usar estos talismanes para conjurar a Ivus. ¡Adéntrate hasta ese lugar y recupera esos cristales, $n!', 0),
(@ID, 'esMX', 'El clan Lobo Gélido está protegido por una contaminación de energía elemental. Su chamán anda metido con poderes que seguramente nos aniquilarían si no nos ocupamos de ellos.$B$B¡El daño se ha extendido demasiado para que el Círculo lo controle! Tenemos que invocar a Ivus para que nos ayude.$B$BLos soldados Lobo Gélido llevan talismanes de elemental llamados cristales de tormenta. Podemos usar estos talismanes para conjurar a Ivus. ¡Adéntrate hasta ese lugar y recupera esos cristales, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Usaré el poder de este talismán para aumentar la magia que ya se ha reunido. Cuando hayas acumulado suficiente poder, concentraré las energías reunidas e invocaré al Señor del Bosque para que nos ayude en nuestra causa.', 0),
(@ID, 'esMX', 'Muy bien, $n. Usaré el poder de este talismán para aumentar la magia que ya se ha reunido. Cuando hayas acumulado suficiente poder, concentraré las energías reunidas e invocaré al Señor del Bosque para que nos ayude en nuestra causa.', 0);
