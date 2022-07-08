-- 6503 Avanzada de Vallefresno
-- https://es.classic.wowhead.com/quest=6503
SET @ID := 6503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero informes de tus ejecuciones de mensajeros, $n.', 0),
(@ID, 'esMX', 'Espero informes de tus ejecuciones de mensajeros, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Tu habilidad para la caza es impresionante...$B$BLa pérdida de esos avanzados contribuye a cegar a la Alianza y con esta falta de información disminuyen las posibilidades de que ataquen.', 0),
(@ID, 'esMX', 'Muy bien, $n. Tu habilidad para la caza es impresionante...$B$BLa pérdida de esos avanzados contribuye a cegar a la Alianza y con esta falta de información disminuyen las posibilidades de que ataquen.', 0);
-- 6504 Las páginas perdidas
-- https://es.classic.wowhead.com/quest=6504
SET @ID := 6504;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que encuentres esas páginas pronto, $n? ¡Necesito volver a trabajar sin más demora!', 0),
(@ID, 'esMX', 'Espero que encuentres esas páginas pronto, $n? ¡Necesito volver a trabajar sin más demora!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No se me da muy bien leer... ¡pero ahora podré volver al trabajo! ¡Gracias, $n!', 0),
(@ID, 'esMX', 'No se me da muy bien leer... ¡pero ahora podré volver al trabajo! ¡Gracias, $n!', 0);
-- 6521 Una alianza impía
-- https://es.classic.wowhead.com/quest=6521
SET @ID := 6521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha muerto el embajador?$B$BNo podemos consentir que la Peste se afiance en Kalimdor; ya suponen amenaza suficiente.$B$BLo único esperanzador en todo lo que me has contado es que la bruja parece no estar corrupta. Debe de saber que la Peste podría darle mucho poder, pero Los Baldíos no serían realmente suyos si aceptara el trato.', 0),
(@ID, 'esMX', '¿Ha muerto el embajador?$B$BNo podemos consentir que la Peste se afiance en Kalimdor; ya suponen amenaza suficiente.$B$BLo único esperanzador en todo lo que me has contado es que la bruja parece no estar corrupta. Debe de saber que la Peste podría darle mucho poder, pero Los Baldíos no serían realmente suyos si aceptara el trato.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c.$B$BAhora que ha muerto Malcin se detendrá el avance de la Plaga. La Dama Oscura te agradece tu esfuerzo y te ofrece este regalo.$B$BAunque aún no sabemos hasta dónde llega la influencia de la Plaga en esta tierra, pronto lo averiguaremos.', 0),
(@ID, 'esMX', 'Buen trabajo, $c.$B$BAhora que ha muerto Malcin se detendrá el avance de la Plaga. La Dama Oscura te agradece tu esfuerzo y te ofrece este regalo.$B$BAunque aún no sabemos hasta dónde llega la influencia de la Plaga en esta tierra, pronto lo averiguaremos.', 0);
-- 6522 Una alianza impía
-- https://es.classic.wowhead.com/quest=6522
SET @ID := 6522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De qué quieres hablarme, $n? Si insistes tanto, tiene que ser importante.', 0),
(@ID, 'esMX', '¿De qué quieres hablarme, $n? Si insistes tanto, tiene que ser importante.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reconozco la insignia de este pergamino, $n. ¿Dices que lo tenía la bruja de la Zahúrda Rajacieno? Qué interesante.$B$BAl parecer, la Plaga no tiene bastante con un solo continente. Este embajador Malcin es un siervo infectado de la Plaga, un diplomático de Lordaeron antes de que todo cambiara.$B$BNo podemos permitir que se afiancen en Kalimdor.', 0),
(@ID, 'esMX', 'Reconozco la insignia de este pergamino, $n. ¿Dices que lo tenía la bruja de la Zahúrda Rajacieno? Qué interesante.$B$BAl parecer, la Plaga no tiene bastante con un solo continente. Este embajador Malcin es un siervo infectado de la Plaga, un diplomático de Lordaeron antes de que todo cambiara.$B$BNo podemos permitir que se afiancen en Kalimdor.', 0);
-- 6523 Protege a Kaya
-- https://es.classic.wowhead.com/quest=6523
SET @ID := 6523;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Kaya está viva! $n, tengo que agradecerte que la hayas rescatado.', 0),
(@ID, 'esMX', '¡Kaya está viva! $n, tengo que agradecerte que la hayas rescatado.', 0);
-- Preséntate ante Kadrak
-- 6541, 6542
-- https://es.classic.wowhead.com/quest=6541
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6541, 6542) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6541, 'esES', 'Vallefresno es una tierra dividida pero nuestros más recientes esfuerzos han dado sus frutos. No solo tenemos una avanzada en La Ensenada de Zoram, sino que también nos hemos hecho con otra justo al norte llamada Puesto del Hachazo.', 0),
(6542, 'esES', 'Vallefresno es una tierra dividida pero nuestros más recientes esfuerzos han dado sus frutos. No solo tenemos una avanzada en La Ensenada de Zoram, sino que también nos hemos hecho con otra justo al norte llamada Puesto del Hachazo.', 0),
(6541, 'esMX', 'Vallefresno es una tierra dividida pero nuestros más recientes esfuerzos han dado sus frutos. No solo tenemos una avanzada en La Ensenada de Zoram, sino que también nos hemos hecho con otra justo al norte llamada Puesto del Hachazo.', 0),
(6542, 'esMX', 'Vallefresno es una tierra dividida pero nuestros más recientes esfuerzos han dado sus frutos. No solo tenemos una avanzada en La Ensenada de Zoram, sino que también nos hemos hecho con otra justo al norte llamada Puesto del Hachazo.', 0);
-- 6543 Los informes Grito de Guerra
-- https://es.classic.wowhead.com/quest=6543
SET @ID := 6543;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $n. Tienen que recibir estos informes, es urgente.', 0),
(@ID, 'esMX', 'Date prisa, $n. Tienen que recibir estos informes, es urgente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que eres alguien con quien se puede contar. Estos informes son vitales para nuestros planes de incrementar nuestra presencia en Vallefresno. Ahora podemos planificar el movimiento siguiente.', 0),
(@ID, 'esMX', 'Veo que eres alguien con quien se puede contar. Estos informes son vitales para nuestros planes de incrementar nuestra presencia en Vallefresno. Ahora podemos planificar el movimiento siguiente.', 0);
-- 6544 El asalto de Torek
-- https://es.classic.wowhead.com/quest=6544
SET @ID := 6544;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Torek fue enviado a una misión contra la Avanzada Ala de Plata. ¿Tuvo éxito el ataque?', 0),
(@ID, 'esMX', 'Torek fue enviado a una misión contra la Avanzada Ala de Plata. ¿Tuvo éxito el ataque?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que el ataque de Torek salió bien! Muy bien, $n. Los elfos de la noche son enemigos respetables. Algo delgados ¡pero fuertes y feroces! Estoy seguro de que la batalla fue digna de ver...$B$B¡Y espero que te ganaras alguna que otra cicatriz!', 0),
(@ID, 'esMX', '¡Así que el ataque de Torek salió bien! Muy bien, $n. Los elfos de la noche son enemigos respetables. Algo delgados ¡pero fuertes y feroces! Estoy seguro de que la batalla fue digna de ver...$B$B¡Y espero que te ganaras alguna que otra cicatriz!', 0);
-- 6545 Novedades de corredor Grito de Guerra
-- https://es.classic.wowhead.com/quest=6545
SET @ID := 6545;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con mis órdenes? Siempre es bueno ver a nuevos reclutas con una naturaleza desbordante y resueltos.$B$BMás vale que aprendas rápido si esperas seguir a la altura aquí. Aumenta la amenaza de los nagas, $n. He estado observando y hemos reforzado las defensas frente a varios ataques sobre esta avanzada desde que llegué.$B$BPero si te apetece arrimar el hombro en esta guerra, habla con alguien de la avanzada.', 0),
(@ID, 'esMX', '¿Has vuelto con mis órdenes? Siempre es bueno ver a nuevos reclutas con una naturaleza desbordante y resueltos.$B$BMás vale que aprendas rápido si esperas seguir a la altura aquí. Aumenta la amenaza de los nagas, $n. He estado observando y hemos reforzado las defensas frente a varios ataques sobre esta avanzada desde que llegué.$B$BPero si te apetece arrimar el hombro en esta guerra, habla con alguien de la avanzada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, mi información hará que Kadrak lo entienda todo. Debes llevarle esto cuanto antes.', 0),
(@ID, 'esMX', 'Bueno, mi información hará que Kadrak lo entienda todo. Debes llevarle esto cuanto antes.', 0);
-- 6546 Novedades de escolta Grito de Guerra
-- https://es.classic.wowhead.com/quest=6546
SET @ID := 6546;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El camino está sembrado de peligros, $n. Tenlo bien presente cuando viajes por estas tierras. La amenaza de la Alianza está bastante cerca.$B$BEl enemigo nos rodea por todas partes. Los sátiros son la formidable fuerza predominante al este de Vallefresno. Asimismo, he descubierto que los nagas se han hecho con una vasta extensión de tierra en Azshara.$B$BEs bueno que seguimos incrementando nuestros efectivos, prepárate para lo que se avecina, $n.', 0),
(@ID, 'esMX', 'El camino está sembrado de peligros, $n. Tenlo bien presente cuando viajes por estas tierras. La amenaza de la Alianza está bastante cerca.$B$BEl enemigo nos rodea por todas partes. Los sátiros son la formidable fuerza predominante al este de Vallefresno. Asimismo, he descubierto que los nagas se han hecho con una vasta extensión de tierra en Azshara.$B$BEs bueno que seguimos incrementando nuestros efectivos, prepárate para lo que se avecina, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llévale mi informe a Kadrak. ¡Y apúrate, $n!', 0),
(@ID, 'esMX', 'Llévale mi informe a Kadrak. ¡Y apúrate, $n!', 0);
-- 6547 Novedades de explorador Grito de Guerra
-- https://es.classic.wowhead.com/quest=6547
SET @ID := 6547;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mantén los ojos bien abiertos, $r. Los elfos suelen ocultarse en las sombras...$B$BSiempre debemos estar vigilantes. Hemos trabajado mucho para conseguir esta tierra y los elfos buscan la más mínima oportunidad para arrebatárnosla.$B$BSupongo que tienes mis siguientes órdenes de Kadrak?', 0),
(@ID, 'esMX', 'Mantén los ojos bien abiertos, $r. Los elfos suelen ocultarse en las sombras...$B$BSiempre debemos estar vigilantes. Hemos trabajado mucho para conseguir esta tierra y los elfos buscan la más mínima oportunidad para arrebatárnosla.$B$BSupongo que tienes mis siguientes órdenes de Kadrak?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que Kadrak se entere del éxito que hemos tenido en mantener a raya a los elfos de la noche. Nuestro planes van muy bien.', 0),
(@ID, 'esMX', 'Que Kadrak se entere del éxito que hemos tenido en mantener a raya a los elfos de la noche. Nuestro planes van muy bien.', 0);
-- 6548 Venga mi aldea
-- https://es.classic.wowhead.com/quest=6548
SET @ID := 6548;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Los has matado ya?', 0),
(@ID, 'esMX', '¿Los has matado ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, te doy las gracias... pero nunca olvidaré lo que los Tótem Siniestro hicieron a mi aldea.', 0),
(@ID, 'esMX', '$n, te doy las gracias... pero nunca olvidaré lo que los Tótem Siniestro hicieron a mi aldea.', 0);
-- 6561 La vileza de Brazanegra
-- https://es.classic.wowhead.com/quest=6561
SET @ID := 6561;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la Madre Tierra esté contigo, $n.$B$BLa paz sea entre la tierra y todos sus pueblos, ese debería ser nuestro objetivo. Tiene grandes planes para la naturaleza y todos desempeñamos un papel.', 0),
(@ID, 'esMX', 'Que la Madre Tierra esté contigo, $n.$B$BLa paz sea entre la tierra y todos sus pueblos, ese debería ser nuestro objetivo. Tiene grandes planes para la naturaleza y todos desempeñamos un papel.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Kelris lleva bastante tiempo evitándome.$B$BDurante algún tiempo lo dieron por muerto o desaparecido.$B$BAl poner fin a su reinado has salvado las vidas de muchos inocentes, $n.$B$B¡Alabada sea la Madre Tierra! ¡Sacrificar a alguien a un servidor de un dios antiguo es repugnante!$B$BHoy has hecho algo grandioso. Kelris era una criatura del mal y buscaba devolver al mundo a una era de caos al adorar a criaturas como los dioses antiguos. Gracias, $n.', 0),
(@ID, 'esMX', 'Kelris lleva bastante tiempo evitándome.$B$BDurante algún tiempo lo dieron por muerto o desaparecido.$B$BAl poner fin a su reinado has salvado las vidas de muchos inocentes, $n.$B$B¡Alabada sea la Madre Tierra! ¡Sacrificar a alguien a un servidor de un dios antiguo es repugnante!$B$BHoy has hecho algo grandioso. Kelris era una criatura del mal y buscaba devolver al mundo a una era de caos al adorar a criaturas como los dioses antiguos. Gracias, $n.', 0);
-- 6562 Problemas en las profundidades
-- https://es.classic.wowhead.com/quest=6562
SET @ID := 6562;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Tsunaman? Fantástico. Entonces tenemos asuntos que tratar.', 0),
(@ID, 'esMX', '¿Te envía Tsunaman? Fantástico. Entonces tenemos asuntos que tratar.', 0);
-- 6563 La esencia de Aku'Mai
-- https://es.classic.wowhead.com/quest=6563
SET @ID := 6563;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de los cristales, $n? ¿Has visto a los nagas recolectándolos? Ruego a mis ancestros que averigüemos lo que les empuja a recoger tales cosas.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de los cristales, $n? ¿Has visto a los nagas recolectándolos? Ruego a mis ancestros que averigüemos lo que les empuja a recoger tales cosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Estos son los cristales de los que hablaba. Intrigante...$B$BPuedo sentir el poder de su interior. El Espíritu del Agua se aferra a ellos. Fuera lo que fuera lo que los nagas hicieran con ellos... bueno, podemos alegrarnos de que ya no estén en sus manos.', 0),
(@ID, 'esMX', 'Muy bien, $n. Estos son los cristales de los que hablaba. Intrigante...$B$BPuedo sentir el poder de su interior. El Espíritu del Agua se aferra a ellos. Fuera lo que fuera lo que los nagas hicieran con ellos... bueno, podemos alegrarnos de que ya no estén en sus manos.', 0);
-- 6564 Lealtad a los dioses antiguos
-- https://es.classic.wowhead.com/quest=6564
SET @ID := 6564;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué hay, $n? ¿Necesitas algo? Aún me queda mucho por aprender sobre los cristales que los nagas están recolectando.', 0),
(@ID, 'esMX', '¿Qué hay, $n? ¿Necesitas algo? Aún me queda mucho por aprender sobre los cristales que los nagas están recolectando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto sí que es interesante. Me alegra que me lo hayas hecho notar.$B$BAhora nuestros problemas tienen un nombre. Lorgus Jett.', 0),
(@ID, 'esMX', 'Esto sí que es interesante. Me alegra que me lo hayas hecho notar.$B$BAhora nuestros problemas tienen un nombre. Lorgus Jett.', 0);
-- 6565 Lealtad a los dioses antiguos
-- https://es.classic.wowhead.com/quest=6565
SET @ID := 6565;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has encontrado ya, $n? ¡Hay que detener a Lorgus!', 0),
(@ID, 'esMX', '¿Lo has encontrado ya, $n? ¡Hay que detener a Lorgus!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¡Estupendo!! Gracias, $n. Puede que no hayamos detenido completamente al Martillo Crepuscular pero al menos has echado abajo otra de sus artimañas para devolver a los dioses antiguos al poder.$B$BQuién sabe qué más andarán tramando pero por ahora podemos tomarnos un respiro.', 0),
(@ID, 'esMX', '¡¡Estupendo!! Gracias, $n. Puede que no hayamos detenido completamente al Martillo Crepuscular pero al menos has echado abajo otra de sus artimañas para devolver a los dioses antiguos al poder.$B$BQuién sabe qué más andarán tramando pero por ahora podemos tomarnos un respiro.', 0);
-- 6566 Lo que trae el viento
-- https://es.classic.wowhead.com/quest=6566
SET @ID := 6566;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Paciencia, $n. ¡Atiende!', 0),
(@ID, 'esMX', 'Paciencia, $n. ¡Atiende!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ves capaz de aceptar la misión?', 0),
(@ID, 'esMX', '¿Te ves capaz de aceptar la misión?', 0);
-- 6567 El Campeón de la Horda
-- https://es.classic.wowhead.com/quest=6567
SET @ID := 6567;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo hay una forma de entrar a la guarida de la dragona, $r.$B$BVerás, solo los más fuertes del Vuelo Negro pueden entrar a la guarida de la madre de linaje. Hay que superar muchas pruebas y obtener la llave encantada con la debida ceremonia por el mismísimo general Drakkisath.$B$BComo no perteneces a los dragonantes negros, puede que te sea difícil abrirte paso.$B$B<Rexxar sonríe.>', 0),
(@ID, 'esMX', 'Solo hay una forma de entrar a la guarida de la dragona, $r.$B$BVerás, solo los más fuertes del Vuelo Negro pueden entrar a la guarida de la madre de linaje. Hay que superar muchas pruebas y obtener la llave encantada con la debida ceremonia por el mismísimo general Drakkisath.$B$BComo no perteneces a los dragonantes negros, puede que te sea difícil abrirte paso.$B$B<Rexxar sonríe.>', 0);
-- 6568 Profesora del engaño
-- https://es.classic.wowhead.com/quest=6568
SET @ID := 6568;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, no se suelen ver muchos miembros de la Horda por esta parte de Lordaeron. ¿Qué tienes para Myranda?', 0),
(@ID, 'esMX', 'Vaya, no se suelen ver muchos miembros de la Horda por esta parte de Lordaeron. ¿Qué tienes para Myranda?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Myranda sujeta la nota, hace una pausa y sonríe.>$B$B¿Cómo está? Me refiero a Rexxar. Oh, vamos, no te hagas el confundido. La carta está en blanco intencionalmente. Contenía los pensamientos e intenciones de su creador. A juzgar por el contenido, no me extraña que Rexxar la dejara así. Imagina que te capturaran o asesinaran, ¡y descubrieran esta información!$B$BOh, ¡no importa! Myranda te ayudará, $r. Le debo un favor o dos al jefe de guerra.$B$B<Myranda sonríe.>', 0),
(@ID, 'esMX', '<Myranda sujeta la nota, hace una pausa y sonríe.>$B$B¿Cómo está? Me refiero a Rexxar. Oh, vamos, no te hagas el confundido. La carta está en blanco intencionalmente. Contenía los pensamientos e intenciones de su creador. A juzgar por el contenido, no me extraña que Rexxar la dejara así. Imagina que te capturaran o asesinaran, ¡y descubrieran esta información!$B$BOh, ¡no importa! Myranda te ayudará, $r. Le debo un favor o dos al jefe de guerra.$B$B<Myranda sonríe.>', 0);
-- 6569 Ilusiones oculares
-- https://es.classic.wowhead.com/quest=6569
SET @ID := 6569;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ingrediente más importante de cualquier ilusión, $n, son los ojos de aquello que queremos imitar.$B$B<Myranda señala una bolsa casi llena de globos oculares con la etiqueta \'Cruzada Escarlata\'>$B$B<Myranda se ríe.>', 0),
(@ID, 'esMX', 'El ingrediente más importante de cualquier ilusión, $n, son los ojos de aquello que queremos imitar.$B$B<Myranda señala una bolsa casi llena de globos oculares con la etiqueta \'Cruzada Escarlata\'>$B$B<Myranda se ríe.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deja que Myranda eche un vistazo, $r.$B$BOh, sí, son perfectos.$B$BCon estos componentes Myranda te hará un medallón capaz de crear una ilusión que engañará al guardián del Vuelo Negro.', 0),
(@ID, 'esMX', 'Deja que Myranda eche un vistazo, $r.$B$BOh, sí, son perfectos.$B$BCon estos componentes Myranda te hará un medallón capaz de crear una ilusión que engañará al guardián del Vuelo Negro.', 0);
-- 6570 Brasaliza
-- https://es.classic.wowhead.com/quest=6570
SET @ID := 6570;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tenemos tan pocos soldados aptos que Nefarian se dedica a enviarme crías? Nunca superarás mis pruebas, $gcachorrito:cachorrita;.', 0),
(@ID, 'esMX', '¿Tenemos tan pocos soldados aptos que Nefarian se dedica a enviarme crías? Nunca superarás mis pruebas, $gcachorrito:cachorrita;.', 0);
-- 6571 Suministros Grito de Guerra
-- https://es.classic.wowhead.com/quest=6571
SET @ID := 6571;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que consigas esos suministros! ¡Estaré en un lío si no los entrego pronto!', 0),
(@ID, 'esMX', '¡Espero que consigas esos suministros! ¡Estaré en un lío si no los entrego pronto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico, $n. ¡Me has ahorrado mucho trabajo!$B$B¡Pero es de bien nacido ser agradecido!', 0),
(@ID, 'esMX', 'Fantástico, $n. ¡Me has ahorrado mucho trabajo!$B$B¡Pero es de bien nacido ser agradecido!', 0);
-- 6581 Espadas dentadas Grito de Guerra
-- https://es.classic.wowhead.com/quest=6581
SET @ID := 6581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Directamente desde Trinquete, las hojas de sierra de los Grito de Guerra! Sí, las tengo aquí mismo.$B$B¿Pero cómo piensas pagarme? No te las puedes quedar y ya está, ¿sabes? ¡Mi tiempo no es barato!$B$BLo que de verdad necesito es un buen arma para llevar en mis viajes. Una chica tiene que protegerse, ¿sabes? Hay una escopeta que me gusta mucho y que estoy segura que un ingeniero podría hacer sin problema.$B$BAsí que si me traes un trabuco mortífero, te entregaré el cargamento de hojas de sierra. ¿Trato?', 0),
(@ID, 'esMX', '¡Directamente desde Trinquete, las hojas de sierra de los Grito de Guerra! Sí, las tengo aquí mismo.$B$B¿Pero cómo piensas pagarme? No te las puedes quedar y ya está, ¿sabes? ¡Mi tiempo no es barato!$B$BLo que de verdad necesito es un buen arma para llevar en mis viajes. Una chica tiene que protegerse, ¿sabes? Hay una escopeta que me gusta mucho y que estoy segura que un ingeniero podría hacer sin problema.$B$BAsí que si me traes un trabuco mortífero, te entregaré el cargamento de hojas de sierra. ¿Trato?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es perfecto, ¡como anillo al dedo! Bien, aquí tienes el envío.', 0),
(@ID, 'esMX', 'Esto es perfecto, ¡como anillo al dedo! Bien, aquí tienes el envío.', 0);
-- 6582 La prueba de los cráneos, Arúspice
-- https://es.classic.wowhead.com/quest=6582
SET @ID := 6582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Brasaliza silba.>', 0),
(@ID, 'esMX', '<Brasaliza silba.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Uno entre muchosss completado...', 0),
(@ID, 'esMX', 'Uno entre muchosss completado...', 0);
-- 6583 La prueba de los cráneos, Somnus
-- https://es.classic.wowhead.com/quest=6583
SET @ID := 6583;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No vuelvas aquí hasta que tengas las ropas empapadas con la sangre de nuestros enemigos y te hayas embriagado con su sufrimiento.', 0),
(@ID, 'esMX', 'No vuelvas aquí hasta que tengas las ropas empapadas con la sangre de nuestros enemigos y te hayas embriagado con su sufrimiento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro...', 0),
(@ID, 'esMX', 'Otro...', 0);
-- 6584 La prueba de los cráneos, Chronalis
-- https://es.classic.wowhead.com/quest=6584
SET @ID := 6584;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo irónico, criatura, es que el tiempo es fundamental.', 0),
(@ID, 'esMX', 'Lo irónico, criatura, es que el tiempo es fundamental.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Queda aún el másss odiado...', 0),
(@ID, 'esMX', 'Queda aún el másss odiado...', 0);
-- 6585 La prueba de los cráneos, Axtroz
-- https://es.classic.wowhead.com/quest=6585
SET @ID := 6585;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cambiosss... Losss siento en tu interior... Supera esta prueba y solo quedará la ceremonia.', 0),
(@ID, 'esMX', 'Cambiosss... Losss siento en tu interior... Supera esta prueba y solo quedará la ceremonia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dudaba de tu dedicación, $gmocoso:mocosa;. Has perseverado, dominando a nuestros enemigos, honorando a nuestro Vuelo.$B$BAhora debo preparar las calaveras para tu ascenso.', 0),
(@ID, 'esMX', 'Dudaba de tu dedicación, $gmocoso:mocosa;. Has perseverado, dominando a nuestros enemigos, honorando a nuestro Vuelo.$B$BAhora debo preparar las calaveras para tu ascenso.', 0);
-- 6601 El ascenso
-- https://es.classic.wowhead.com/quest=6601
SET @ID := 6601;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cálmate, $n!', 0),
(@ID, 'esMX', '¡Cálmate, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo esto es pura palabrería, $n. Mucho ruido y pocas nueces... pero nada de información real. De esa gente solo podemos esperar su habitual comportamiento pomposo y agresivo.', 0),
(@ID, 'esMX', 'Todo esto es pura palabrería, $n. Mucho ruido y pocas nueces... pero nada de información real. De esa gente solo podemos esperar su habitual comportamiento pomposo y agresivo.', 0);
-- 6602 La sangre de dragón Negro Campeón
-- https://es.classic.wowhead.com/quest=6602
SET @ID := 6602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No debes tomar a Drakkisath a la ligera, $n. Es responsable de la muerte de miles de personas.', 0),
(@ID, 'esMX', 'No debes tomar a Drakkisath a la ligera, $n. Es responsable de la muerte de miles de personas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La historia de tus actos heroicos se contará por generaciones, $n. El amuleto pirodraco es la llave para entrar a la guarida de Onyxia. ¡Reúne tus tropas y conquista en nombre de la Horda!', 0),
(@ID, 'esMX', 'La historia de tus actos heroicos se contará por generaciones, $n. El amuleto pirodraco es la llave para entrar a la guarida de Onyxia. ¡Reúne tus tropas y conquista en nombre de la Horda!', 0);
-- 6605 Algo extraño
-- https://es.classic.wowhead.com/quest=6605
SET @ID := 6605;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $c. Al parecer todavía hay esperanza. ¿Has venido para ayudarme?', 0),
(@ID, 'esMX', 'Ah, $c. Al parecer todavía hay esperanza. ¿Has venido para ayudarme?', 0);
-- 6606 Un poco de suerte
-- https://es.classic.wowhead.com/quest=6606
SET @ID := 6606;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿entonces Harlo te envía? Bueno, claro que te envía Harlo. Supongo que querrás mi ayuda.', 0),
(@ID, 'esMX', 'Ah, ¿entonces Harlo te envía? Bueno, claro que te envía Harlo. Supongo que querrás mi ayuda.', 0);
-- 6607 Nat Pagle, pescador extremo
-- https://es.classic.wowhead.com/quest=6607
SET @ID := 6607;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha picado algo?', 0),
(@ID, 'esMX', '¿Ha picado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esa es una buena captura!$B$BVen aquí, déjame mostrarte cómo establecer algunas pautas.', 0),
(@ID, 'esMX', '¡Esa es una buena captura!$B$BVen aquí, déjame mostrarte cómo establecer algunas pautas.', 0);
-- 6608 ¡Qué bueno eres!
-- https://es.classic.wowhead.com/quest=6608
SET @ID := 6608;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por supuesto, debes ser amigo de Lumak.$B$B¿Pescar? Puedo contarte todo sobre la pesca.', 0),
(@ID, 'esMX', 'Por supuesto, debes ser amigo de Lumak.$B$B¿Pescar? Puedo contarte todo sobre la pesca.', 0);
-- 6609 ¡Me has dejado seco!
-- https://es.classic.wowhead.com/quest=6609
SET @ID := 6609;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre hay espacio en mi isla para visitantes... creo...', 0),
(@ID, 'esMX', 'Siempre hay espacio en mi isla para visitantes... creo...', 0);
