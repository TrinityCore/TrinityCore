-- 8144 Dije Zandalar de maestría de las Sombras
-- https://es.classic.wowhead.com/quest=8144
SET @ID := 8144;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Anhela crecer, $n. El talismán se ha empapado de todo lo que has hecho. Los miles de cadáveres de trols que ensucian Zul\'Gurub han alimentado su poder. Dámelo y haré la mejora final.', 0),
(@ID, 'esMX', 'Anhela crecer, $n. El talismán se ha empapado de todo lo que has hecho. Los miles de cadáveres de trols que ensucian Zul\'Gurub han alimentado su poder. Dámelo y haré la mejora final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es la última vez que hablaremos bajo los auspicios de Shera Ali\'kh. Sabes todo lo que debes. Toma el talismán y continúa matando. No se debe permitir que Hakkar abandone Zul\'Gurub.', 0),
(@ID, 'esMX', 'Esta es la última vez que hablaremos bajo los auspicios de Shera Ali\'kh. Sabes todo lo que debes. Toma el talismán y continúa matando. No se debe permitir que Hakkar abandone Zul\'Gurub.', 0);
-- 8145 Zarcillo de La Vorágine
-- https://es.classic.wowhead.com/quest=8145
SET @ID := 8145;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entre los Zandalar, la profesión de $c es venerada. Nuestros mejores cazadores viajan al borde de la Vorágine para demostrar su resolución.$B$BDel corazón del mar extraen hebras de algas conocidas como Zarcillos de La Vorágine. Luego, las algas marinas se tejen en un talismán que está encantado para mejorar su precisión y poder.$B$BAhora te concedo un solo tejido del Zarcillo de La Vorágine. A medida que crezca tu vínculo con Zandalar, tejeré más poder en el talismán.', 0),
(@ID, 'esMX', 'Entre los Zandalar, la profesión de $c es venerada. Nuestros mejores cazadores viajan al borde de la Vorágine para demostrar su resolución.$B$BDel corazón del mar extraen hebras de algas conocidas como Zarcillos de La Vorágine. Luego, las algas marinas se tejen en un talismán que está encantado para mejorar su precisión y poder.$B$BAhora te concedo un solo tejido del Zarcillo de La Vorágine. A medida que crezca tu vínculo con Zandalar, tejeré más poder en el talismán.', 0);
-- 8146 Zarcillo de La Vorágine
-- https://es.classic.wowhead.com/quest=8146
SET @ID := 8146;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Incluso desde aquí puedo oír el sonido de tus descargas arrasando con nuestros enemigos. Sus gritos resuenan en agonía.$B$BTe has hecho un gran nombre entre los trols de Zandalar, $n. Agradecemos todo lo que has hecho.$B$BDame tu talismán para que pueda agregar otro tejido.', 0),
(@ID, 'esMX', 'Incluso desde aquí puedo oír el sonido de tus descargas arrasando con nuestros enemigos. Sus gritos resuenan en agonía.$B$BTe has hecho un gran nombre entre los trols de Zandalar, $n. Agradecemos todo lo que has hecho.$B$BDame tu talismán para que pueda agregar otro tejido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo hay un tejido más que podré agregar a tu talismán, $c', 0),
(@ID, 'esMX', 'Solo hay un tejido más que podré agregar a tu talismán, $c', 0);
-- 8147 Zarcillo de La Vorágine
-- https://es.classic.wowhead.com/quest=8147
SET @ID := 8147;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, es bueno volverte a oler.$B$B<Falthir sonríe.>$B$BTendrás que disculpar mi sentido del humor. A veces puede ser de lo más asqueroso.$B$BSiento que has causado una gran angustia a nuestros enemigos. Las fuerzas de Hakkar gritan tu nombre con ira. Esto es excelente.$B$BHas ganado otro tejido en tu talismán. Dámelo.', 0),
(@ID, 'esMX', 'Ah, $n, es bueno volverte a oler.$B$B<Falthir sonríe.>$B$BTendrás que disculpar mi sentido del humor. A veces puede ser de lo más asqueroso.$B$BSiento que has causado una gran angustia a nuestros enemigos. Las fuerzas de Hakkar gritan tu nombre con ira. Esto es excelente.$B$BHas ganado otro tejido en tu talismán. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que busquen expiación al final de tus municiones.', 0),
(@ID, 'esMX', 'Que busquen expiación al final de tus municiones.', 0);
-- 8148 Cólera de La Vorágine
-- https://es.classic.wowhead.com/quest=8148
SET @ID := 8148;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Molthor comunica la palabra del rey Rastakhan, $n. La corte real está muy impresionada con tu aniquilación de las fuerzas Hakkari. Voy a premiarte con el tejido final de tu talismán. Dámelo.', 0),
(@ID, 'esMX', 'Molthor comunica la palabra del rey Rastakhan, $n. La corte real está muy impresionada con tu aniquilación de las fuerzas Hakkari. Voy a premiarte con el tejido final de tu talismán. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu viaje apenas ha comenzado, joven $c. Quizás algún día visites la Vorágine y eches un vistazo al corazón del mundo.$B$B¡Te deseo poder y fortaleza!', 0),
(@ID, 'esMX', 'Tu viaje apenas ha comenzado, joven $c. Quizás algún día visites la Vorágine y eches un vistazo al corazón del mundo.$B$B¡Te deseo poder y fortaleza!', 0);
-- 8149 En honor a un héroe
-- https://es.classic.wowhead.com/quest=8149
SET @ID := 8149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho el viaje a la tumba de Uther y has colocado el tributo allí?$B$BPuede ser un viaje peligroso para los aventureros menos experimentados; una forma más segura de viajar allí, relativamente hablando, puede ser viajar hacia el norte desde el río que atraviesa Trabalomas hasta las Tierras de la Peste. Fluye de un lago junto a las Colinas de la Tristeza; viaja hacia el oeste a través de las colinas, evitando la tumba adyacente... una que está infestada con la Plaga.', 0),
(@ID, 'esMX', '¿Has hecho el viaje a la tumba de Uther y has colocado el tributo allí?$B$BPuede ser un viaje peligroso para los aventureros menos experimentados; una forma más segura de viajar allí, relativamente hablando, puede ser viajar hacia el norte desde el río que atraviesa Trabalomas hasta las Tierras de la Peste. Fluye de un lago junto a las Colinas de la Tristeza; viaja hacia el oeste a través de las colinas, evitando la tumba adyacente... una que está infestada con la Plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Era un héroe de héroes, el gran Uther. No puedo ni imaginar la angustia que sintió cuando Arthas, su mejor alumno y alguien a quien Uther amaba como a su propio hijo, traicionó a toda la humanidad. Aun así intentó detener a Arthas y por ello siempre será recordado como un auténtico paladín. Luchó hasta el final, pensando solo en aquellos a los que podría salvar.$B$BGracias, $n. Hoy has prestado tributo a un gran héroe, honrando su espíritu y el espíritu del Festival de la Cosecha.', 0),
(@ID, 'esMX', 'Era un héroe de héroes, el gran Uther. No puedo ni imaginar la angustia que sintió cuando Arthas, su mejor alumno y alguien a quien Uther amaba como a su propio hijo, traicionó a toda la humanidad. Aun así intentó detener a Arthas y por ello siempre será recordado como un auténtico paladín. Luchó hasta el final, pensando solo en aquellos a los que podría salvar.$B$BGracias, $n. Hoy has prestado tributo a un gran héroe, honrando su espíritu y el espíritu del Festival de la Cosecha.', 0);
-- 8150 En honor a un héroe
-- https://es.classic.wowhead.com/quest=8150
SET @ID := 8150;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha hecho el viaje al Monumento de Grom y depositado tu tributo allí?$B$BEl sitio donde está el monumento todavía está tocado por la mancha de la Legión Ardiente. Si tiene poca experiencia en aventuras de este tipo, permanece alerta cuando te acerques al monumento.', 0),
(@ID, 'esMX', '¿Ha hecho el viaje al Monumento de Grom y depositado tu tributo allí?$B$BEl sitio donde está el monumento todavía está tocado por la mancha de la Legión Ardiente. Si tiene poca experiencia en aventuras de este tipo, permanece alerta cuando te acerques al monumento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El nombre completo de Grom, Grommash, significa "El corazón de gigante"; necesitó eso y algo más para enfrentarse solo a Mannoroth. Creo que el Jefe de Guerra lo expresó mejor: la maldición de los orcos comenzó y terminó con Grom. Es apropiado que el sacrificio (y tal vez la redención) de Grom sea la fuente de la que fluye hoy la Horda.$B$BGracias, $n. Hoy has prestado tributo a un gran héroe, honrando su espíritu y el espíritu del Festival de la Cosecha.', 0),
(@ID, 'esMX', 'El nombre completo de Grom, Grommash, significa "El corazón de gigante"; necesitó eso y algo más para enfrentarse solo a Mannoroth. Creo que el Jefe de Guerra lo expresó mejor: la maldición de los orcos comenzó y terminó con Grom. Es apropiado que el sacrificio (y tal vez la redención) de Grom sea la fuente de la que fluye hoy la Horda.$B$BGracias, $n. Hoy has prestado tributo a un gran héroe, honrando su espíritu y el espíritu del Festival de la Cosecha.', 0);
-- 8151 El talismán del cazador
-- https://es.classic.wowhead.com/quest=8151
SET @ID := 8151;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya no es mi propósito cazar, sino enseñar $gal:a la; $n. Eso es lo que me ha entregado el destino.$B$BCrea conmigo un amuleto de $n: una colección de trofeos de presas caídas que te recordarán tus pruebas y triunfos pasados. Al final me quedaré con lo encantado, pero te recompensaré con algo más.', 0),
(@ID, 'esMX', 'Ya no es mi propósito cazar, sino enseñar $gal:a la; $n. Eso es lo que me ha entregado el destino.$B$BCrea conmigo un amuleto de $n: una colección de trofeos de presas caídas que te recordarán tus pruebas y triunfos pasados. Al final me quedaré con lo encantado, pero te recompensaré con algo más.', 0);
-- 8153 Cornamenta de trotador
-- https://es.classic.wowhead.com/quest=8153
SET @ID := 8153;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado las cornamentas?', 0),
(@ID, 'esMX', '¿Has encontrado las cornamentas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes poseer una vista aguda y una gran paciencia para haberlos obtenido. Bien hecho.', 0),
(@ID, 'esMX', 'Debes poseer una vista aguda y una gran paciencia para haberlos obtenido. Bien hecho.', 0);
-- 8181 La confrontación con Yeh'kinya
-- https://es.classic.wowhead.com/quest=8181
SET @ID := 8181;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, has estado hablando con ese viejo enano Ferrobota y has descubierto las Tablillas Mosh\'aru perdidas, ¿verdad? Ese buscador entrometido...$B$BNo importa. Es demasiado tarde para salvar este mundo. Hakkar ha renacido, e incluso ahora crece en poder... ¡en lo profundo del antiguo reino trol de Zul\'Gurub! ¡Él ha venido! ¡Y gobernará con sangre y terror!$B$BGracias, $n. ¡Tu ayuda ha acelerado el regreso del Cazador de Almas!', 0),
(@ID, 'esMX', 'Entonces, has estado hablando con ese viejo enano Ferrobota y has descubierto las Tablillas Mosh\'aru perdidas, ¿verdad? Ese buscador entrometido...$B$BNo importa. Es demasiado tarde para salvar este mundo. Hakkar ha renacido, e incluso ahora crece en poder... ¡en lo profundo del antiguo reino trol de Zul\'Gurub! ¡Él ha venido! ¡Y gobernará con sangre y terror!$B$BGracias, $n. ¡Tu ayuda ha acelerado el regreso del Cazador de Almas!', 0);
-- 8182 La mano de Rastakhan
-- https://es.classic.wowhead.com/quest=8182
SET @ID := 8182;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Fuiste enviado por el Prospector Ferrobota? Los de su clase son sabios, y más sabios aún para traerte a mí, porque yo y los trols Zandalari podemos conocer la forma de derrotar al Cazador de Almas.$B$BHabla con los trols de esta isla, presta atención a sus palabras y prepárate, $n, para la tarea que tienes ante ti $gempapado:empapada; en sangre.', 0),
(@ID, 'esMX', '¿Fuiste enviado por el Prospector Ferrobota? Los de su clase son sabios, y más sabios aún para traerte a mí, porque yo y los trols Zandalari podemos conocer la forma de derrotar al Cazador de Almas.$B$BHabla con los trols de esta isla, presta atención a sus palabras y prepárate, $n, para la tarea que tienes ante ti $gempapado:empapada; en sangre.', 0);
-- 8183 El corazón de Hakkar
-- https://es.classic.wowhead.com/quest=8183
SET @ID := 8183;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, el hedor de un alma maligna te rodea. ¿Has sido maldecido por el Cazador de Almas?', 0),
(@ID, 'esMX', '$n, el hedor de un alma maligna te rodea. ¿Has sido maldecido por el Cazador de Almas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, el corazón de Hakkar. ¡Así que el Cazador de Almas ha sido asesinado! ¡Nuestro mundo está salvado!$B$B$n, tu servicio para nosotros no puede ser exagerado. ¡Realmente eres $gun héroe:una heroína; de este reino!', 0),
(@ID, 'esMX', 'Ah, el corazón de Hakkar. ¡Así que el Cazador de Almas ha sido asesinado! ¡Nuestro mundo está salvado!$B$B$n, tu servicio para nosotros no puede ser exagerado. ¡Realmente eres $gun héroe:una heroína; de este reino!', 0);
-- Presencia de poderío
-- 8184, 8185, 8186, 8187, 8188, 8189, 8190, 8191, 8192
-- https://es.classic.wowhead.com/quest=8184
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8184, 8185, 8186, 8187, 8188, 8189, 8190, 8191, 8192) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8184, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8185, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8186, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8187, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8188, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8189, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8190, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8191, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8192, 'esES', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8184, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8185, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8186, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8187, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8188, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8189, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8190, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8191, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0),
(8192, 'esMX', '¡Tráeme estas cosas y te crearé un poderoso encantamiento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8184, 8185, 8186, 8187, 8188, 8189, 8190, 8191, 8192) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8184, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8185, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8186, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8187, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8188, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8189, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8190, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8191, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8192, 'esES', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8184, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8185, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8186, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8187, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8188, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8189, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8190, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8191, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0),
(8192, 'esMX', 'Úsalo bien, $n. ¡No muestres piedad al Hakkari!', 0);
-- 8193 Gran premio
-- https://es.classic.wowhead.com/quest=8193
SET @ID := 8193;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hoy entre las 2 p.m. y las 4 p.m. tenemos un concurso para determinar quién es el mejor pescador de todos! ¡Sé la PRIMERA PERSONA en traerme 40 Pezricos pescados de los bancos de Pezrico que se encuentran a lo largo de la costa de Tuercespina antes que nadie más y serás declarado $gel Maestro Pescador:la Maestra Pescadora;!$B$BSi no eres la primera persona en traerme 40 peces, mi aprendiz te recompensará con dinero por cada 5 Pezrico que le traigas.$B$BAh, y no te demores, ¡los Pezrico se echan a perder rápidamente!', 0),
(@ID, 'esMX', '¡Hoy entre las 2 p.m. y las 4 p.m. tenemos un concurso para determinar quién es el mejor pescador de todos! ¡Sé la PRIMERA PERSONA en traerme 40 Pezricos pescados de los bancos de Pezrico que se encuentran a lo largo de la costa de Tuercespina antes que nadie más y serás declarado $gel Maestro Pescador:la Maestra Pescadora;!$B$BSi no eres la primera persona en traerme 40 peces, mi aprendiz te recompensará con dinero por cada 5 Pezrico que le traigas.$B$BAh, y no te demores, ¡los Pezrico se echan a perder rápidamente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Date prisa y devuélvelos si quieres ser declarado $gMaestro Pescador:Maestra Pescadora;! ¡He estado parado aquí por HORAS sin nada para comer! ¡Entrégalos $gtonto:tonta;!', 0),
(@ID, 'esMX', '¡Date prisa y devuélvelos si quieres ser declarado $gMaestro Pescador:Maestra Pescadora;! ¡He estado parado aquí por HORAS sin nada para comer! ¡Entrégalos $gtonto:tonta;!', 0);
-- 8194 Aprendiz pescador
-- https://es.classic.wowhead.com/quest=8194
SET @ID := 8194;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque ya tenemos un ganador del concurso, aún quiero comprarte el pezrico a un precio razonable. ¿Qué dices?', 0),
(@ID, 'esMX', 'Aunque ya tenemos un ganador del concurso, aún quiero comprarte el pezrico a un precio razonable. ¿Qué dices?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A mí me viene bien, si a ti te viene bien!', 0),
(@ID, 'esMX', '¡A mí me viene bien, si a ti te viene bien!', 0);
-- 8195 Las monedas Zulian, Razzashi y Hakkari
-- https://es.classic.wowhead.com/quest=8195
SET @ID := 8195;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0),
(@ID, 'esMX', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0),
(@ID, 'esMX', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0);
-- 8196 Mangos de esencia
-- https://es.classic.wowhead.com/quest=8196
SET @ID := 8196;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La esencia extremadamente potente de mango crece en muchas de las islas de los mares del sur. Un solo mango refrescará a quien lo coma, tanto física como mentalmente. Si nunca has probado uno, ¡te haces un flaco favor!$B$BTenemos suficiente suministro aquí en la isla para ofrecerte un puñado a cambio de una ficha de honor de Zandalar. Habla con Vinchaxa si necesitas aprender a conseguir fichas; de lo contrario, ¡vayamos al asunto que nos ocupa!', 0),
(@ID, 'esMX', 'La esencia extremadamente potente de mango crece en muchas de las islas de los mares del sur. Un solo mango refrescará a quien lo coma, tanto física como mentalmente. Si nunca has probado uno, ¡te haces un flaco favor!$B$BTenemos suficiente suministro aquí en la isla para ofrecerte un puñado a cambio de una ficha de honor de Zandalar. Habla con Vinchaxa si necesitas aprender a conseguir fichas; de lo contrario, ¡vayamos al asunto que nos ocupa!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trato justo, $gamigo mío:amiga mía;, por favor disfruta de los deliciosos frutos de los mares del sur, con la bendición de la tribu.', 0),
(@ID, 'esMX', 'Un trato justo, $gamigo mío:amiga mía;, por favor disfruta de los deliciosos frutos de los mares del sur, con la bendición de la tribu.', 0);
-- 8201 Una colección de cabezas
-- https://es.classic.wowhead.com/quest=8201
SET @ID := 8201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la colección de cabezas, $n? ¡Debemos impedir que Hakkar aumente su poder!', 0),
(@ID, 'esMX', '¿Tienes la colección de cabezas, $n? ¡Debemos impedir que Hakkar aumente su poder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Conseguiste las cabezas! ¡Has puesto fin al expolio del poder de nuestros dioses y has debilitado a Hakkar!$B$BTus acciones son realmente heroicas, $n. Que las cabezas de estos esclavos trols te sigan suplicando clemencia mucho tiempo después de que se haya enfriado su sangre.', 0),
(@ID, 'esMX', '¡Conseguiste las cabezas! ¡Has puesto fin al expolio del poder de nuestros dioses y has debilitado a Hakkar!$B$BTus acciones son realmente heroicas, $n. Que las cabezas de estos esclavos trols te sigan suplicando clemencia mucho tiempo después de que se haya enfriado su sangre.', 0);
-- 8221 Pez raro: pez ángel de Keefer
-- https://es.classic.wowhead.com/quest=8221
SET @ID := 8221;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un pez ángel de Keefer, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0),
(@ID, 'esMX', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un pez ángel de Keefer, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn*$B$BIdentificación completa del pez ángel de Keefer.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0),
(@ID, 'esMX', '*ZZnnnn*$B$BIdentificación completa del pez ángel de Keefer.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0);
-- 8222 Sangre de escórpido resplandeciente
-- https://es.classic.wowhead.com/quest=8222
SET @ID := 8222;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En todo el tiempo que he trabajado en la Feria, he aprendido muchas cosas sobre los clientes. Aquí está una de esas pepitas de sabiduría: ¡a los clientes les encantan las cosas que brillan! No importa lo que sea, puedes tomar una pata de una silla rota y hacerla brillar, ¡y todos los niños vendrán de millas a la redonda para conseguir una!$B$BEntonces, $n, necesito sangre de escórpido brillante. Puedes encontrarlo en los escórpidos de Sillithus, o en las Tierras Devastadas, o en las Estepas Ardientes.', 0),
(@ID, 'esMX', 'En todo el tiempo que he trabajado en la Feria, he aprendido muchas cosas sobre los clientes. Aquí está una de esas pepitas de sabiduría: ¡a los clientes les encantan las cosas que brillan! No importa lo que sea, puedes tomar una pata de una silla rota y hacerla brillar, ¡y todos los niños vendrán de millas a la redonda para conseguir una!$B$BEntonces, $n, necesito sangre de escórpido brillante. Puedes encontrarlo en los escórpidos de Sillithus, o en las Tierras Devastadas, o en las Estepas Ardientes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! ¡Muchas gracias! ¡Voy a hacer pintura con esta sangre y convertiré todo tipo de basura barata en un tesoro resplandeciente!$B$B¡Aquí están sus vales y gracias de nuevo!', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! ¡Muchas gracias! ¡Voy a hacer pintura con esta sangre y convertiré todo tipo de basura barata en un tesoro resplandeciente!$B$B¡Aquí están sus vales y gracias de nuevo!', 0);
-- 8223 Más sangre de escórpido resplandeciente
-- https://es.classic.wowhead.com/quest=8223
SET @ID := 8223;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esa sangre de escórpido está funcionando muy bien, $n! Es sorprendente cómo un poco de brillo puede crear una chuchería preciada a partir de un pedazo de basura. A los clientes les encantan las cosas, y el amor es de lo que se trata, ¿no crees...?$B$BHas sido de gran ayuda para mí, $n, y aunque no tengo una gran necesidad de más sangre de escórpido brillante, si me traes más, te cambiaré algunos vales.', 0),
(@ID, 'esMX', '¡Esa sangre de escórpido está funcionando muy bien, $n! Es sorprendente cómo un poco de brillo puede crear una chuchería preciada a partir de un pedazo de basura. A los clientes les encantan las cosas, y el amor es de lo que se trata, ¿no crees...?$B$BHas sido de gran ayuda para mí, $n, y aunque no tengo una gran necesidad de más sangre de escórpido brillante, si me traes más, te cambiaré algunos vales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias de nuevo, $n. ¡Aquí tienes tus vales!', 0),
(@ID, 'esMX', 'Gracias de nuevo, $n. ¡Aquí tienes tus vales!', 0);
-- 8224 Pez raro: pez reina de Dezian
-- https://es.classic.wowhead.com/quest=8224
SET @ID := 8224;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un pez Reina de Dezian, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0),
(@ID, 'esMX', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un pez Reina de Dezian, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn*$B$BIdentificación completa del pez Reina de Dezian.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0),
(@ID, 'esMX', '*ZZnnnn*$B$BIdentificación completa del pez Reina de Dezian.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0);
-- 8225 Pez raro: corredor a rayas azules de Brownell
-- https://es.classic.wowhead.com/quest=8225
SET @ID := 8225;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un Corredor a rayas azules de Brownell, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0),
(@ID, 'esMX', '*ZZnnnn* *Click*$B$BBusco peces raros para catalogar para el Maestro Pescador Branquiazul. Si me traes un Corredor a rayas azules de Brownell, te daré esta excelente recompensa.$B$B*Zzzap* *ZZnnnn*', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*ZZnnnn*$B$BIdentificación completa del Corredor a rayas azules de Brownell.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0),
(@ID, 'esMX', '*ZZnnnn*$B$BIdentificación completa del Corredor a rayas azules de Brownell.$B$BTu recompensa ya está disponible.$B$B*click-click* *Bzzzz*', 0);
-- 8227 Cinta métrica de Nat
-- https://es.classic.wowhead.com/quest=8227
SET @ID := 8227;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gmuchachito:muchachita;. ¿Has venido a pescar algo?', 0),
(@ID, 'esMX', 'Hola, $gmuchachito:muchachita;. ¿Has venido a pescar algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, encontraste mi cinta métrica favorita! ¡Me encanta esta cinta! Con ella he medido los peces más grandes que he pescado...$B$BPero... perdí esta cinta en Zul\'Gurub... ¿has estado en Zul\'Gurub? ¿Has visto al legendario Gahz\'ranka?$B$B¿Quieres darle caza?', 0),
(@ID, 'esMX', '¡Vaya, encontraste mi cinta métrica favorita! ¡Me encanta esta cinta! Con ella he medido los peces más grandes que he pescado...$B$BPero... perdí esta cinta en Zul\'Gurub... ¿has estado en Zul\'Gurub? ¿Has visto al legendario Gahz\'ranka?$B$B¿Quieres darle caza?', 0);
-- ¿Puedo tener un folleto de pesca?
-- 8228, 8229
-- https://es.classic.wowhead.com/quest=8228
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8228, 8229) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8228, 'esES', '¡Este domingo hay un concurso de pesca en Bahía del Botín! ¡Aquí están las reglas, para ti!', 0),
(8229, 'esES', '¡Este domingo hay un concurso de pesca en Bahía del Botín! ¡Aquí están las reglas, para ti!', 0),
(8228, 'esMX', '¡Este domingo hay un concurso de pesca en Bahía del Botín! ¡Aquí están las reglas, para ti!', 0),
(8229, 'esMX', '¡Este domingo hay un concurso de pesca en Bahía del Botín! ¡Aquí están las reglas, para ti!', 0);
-- 8231 Los vándalos marinos
-- https://es.classic.wowhead.com/quest=8231
SET @ID := 8231;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito?', 0),
(@ID, 'esMX', '¿Has tenido éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los descarnadores marinos no son derrotados fácilmente, más aún en su entorno acuático.$B$BHas probado que estás $glisto:lista; para cazar presas aún más letales.', 0),
(@ID, 'esMX', 'Los descarnadores marinos no son derrotados fácilmente, más aún en su entorno acuático.$B$BHas probado que estás $glisto:lista; para cazar presas aún más letales.', 0);
-- 8232 El draco verde
-- https://es.classic.wowhead.com/quest=8232
SET @ID := 8232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo sabiduría en tus ojos, $n. ¿Ha terminado tu cacería?', 0),
(@ID, 'esMX', 'Veo sabiduría en tus ojos, $n. ¿Ha terminado tu cacería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has aprendido las viejas formas, $n, y por eso te ofrezco un regalo de mis días como $n.', 0),
(@ID, 'esMX', 'Has aprendido las viejas formas, $n, y por eso te ofrezco un regalo de mis días como $n.', 0);
-- 8233 Un pedido sencillo
-- https://es.classic.wowhead.com/quest=8233
SET @ID := 8233;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gBienvenido, bienvenido, bienvenido:Bienvenida, bienvenida, bienvenida;! Por favor, $n, siéntate y discute un asunto simple conmigo.$B$BVerás, $n, recientemente he perdido algo querido para mí y, para decirlo sin rodeos, lo quiero de vuelta a toda costa. Hay algo para ti, ¡no te preocupes por eso! Oh si, algo muy lindo.$B$BAhora, ¿qué dices $n... estás $gpreparado:preparada; para una aventura?', 0),
(@ID, 'esMX', '¡$gBienvenido, bienvenido, bienvenido:Bienvenida, bienvenida, bienvenida;! Por favor, $n, siéntate y discute un asunto simple conmigo.$B$BVerás, $n, recientemente he perdido algo querido para mí y, para decirlo sin rodeos, lo quiero de vuelta a toda costa. Hay algo para ti, ¡no te preocupes por eso! Oh si, algo muy lindo.$B$BAhora, ¿qué dices $n... estás $gpreparado:preparada; para una aventura?', 0);
-- 8234 Bolsa azur sellada
-- https://es.classic.wowhead.com/quest=8234
SET @ID := 8234;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te conozco?', 0),
(@ID, 'esMX', '¿Te conozco?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que tienes la bolsa de Lord Ravenholdt. ¿Por qué no lo dijiste, $gchico:chica;?', 0),
(@ID, 'esMX', 'Veo que tienes la bolsa de Lord Ravenholdt. ¿Por qué no lo dijiste, $gchico:chica;?', 0);
-- 8235 Los trozos codificados
-- https://es.classic.wowhead.com/quest=8235
SET @ID := 8235;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha encontrado suficientes fragmentos para continuar mi trabajo?', 0),
(@ID, 'esMX', '¿Ha encontrado suficientes fragmentos para continuar mi trabajo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has recogido algunos de los mejores fragmentos. Quizás no seas completamente inutil después de todo.', 0),
(@ID, 'esMX', 'Parece que has recogido algunos de los mejores fragmentos. Quizás no seas completamente inutil después de todo.', 0);
-- 8236 La llave azur
-- https://es.classic.wowhead.com/quest=8236
SET @ID := 8236;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La bolsa ya llegó del Archimago Xylem, ¿has encontrado la llave?', 0),
(@ID, 'esMX', 'La bolsa ya llegó del Archimago Xylem, ¿has encontrado la llave?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La llave! Pensé que se había perdido para siempre. Por favor, toma una prenda encantada de mi tienda; están reservadas para pícaros de habilidad y lealtad excepcionales. ¡Todos deben saber que no se debe jugar con $n!$B$B<Jorach abre la bolsa y es bañado por un resplandor dorado desde dentro. Sus ojos se abren y mira...>', 0),
(@ID, 'esMX', '¡La llave! Pensé que se había perdido para siempre. Por favor, toma una prenda encantada de mi tienda; están reservadas para pícaros de habilidad y lealtad excepcionales. ¡Todos deben saber que no se debe jugar con $n!$B$B<Jorach abre la bolsa y es bañado por un resplandor dorado desde dentro. Sus ojos se abren y mira...>', 0);
-- Las monedas Gurubashi, Vilrama y Secacorteza
-- 8238, 8239
-- https://es.classic.wowhead.com/quest=8238
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8238, 8239) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8238, 'esES', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0),
(8239, 'esES', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0),
(8238, 'esMX', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0),
(8239, 'esMX', 'Necesito los Dechados de Poder conocidos como Monedas de las Tribus. Son la moneda que utilizan los distintos habitantes de Zul\'Gurub y todas ellas están imbuidas con un sutil pero potente mojo.$B$BHay nueve tipos diferentes. Mis compatriotas buscan algunas de ellas para las distintas armaduras que ofrecen a los héroes Zandalar. Si tuvieras alguna de sobra te la cambiaré tres de ellas por una de nuestras marcas de honor. Puedes utilizar las marcas con Rin\'wosho el Mercader, a cambio te ofrecerá objetos especiales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8238, 8239) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8238, 'esES', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0),
(8239, 'esES', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0),
(8238, 'esMX', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0),
(8239, 'esMX', 'Excelente, este juego de monedas es una buena adquisición para nuestra colección... la que utilizaremos para defender a nuestra tribu contra el auge del Dios de la Sangre. Has ganado esta muestra de honor, $n, así como la gratitud de toda la tribu.', 0);
