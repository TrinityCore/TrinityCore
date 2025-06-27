-- 9890 ¡Éxito!
-- https://es.wowhead.com/quest=9890
SET @ID := 9890;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con calma, $n. Solo soy un pícaro. No tengo ni idea de qué hacer con esa información.', 0),
(@ID, 'esMX', 'Con calma, $n. Solo soy un pícaro. No tengo ni idea de qué hacer con esa información.', 0);
-- 9891 Porque Kilrath es un cobarde
-- https://es.wowhead.com/quest=9891
SET @ID := 9891;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que creen tener derecho a matar orcos a su antojo, ¿eh? Seguro que esto no tiene nada que ver con que nuestro líder sea un mocoso impotente... Si hubiese heredado una fracción de la pasión de su padre...', 0),
(@ID, 'esMX', 'Así que creen tener derecho a matar orcos a su antojo, ¿eh? Seguro que esto no tiene nada que ver con que nuestro líder sea un mocoso impotente... Si hubiese heredado una fracción de la pasión de su padre...', 0);
-- 9892 Más abalorios de guerra de obsidiana
-- https://es.wowhead.com/quest=9892
SET @ID := 9892;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido más abalorios de guerra? Encontrarás muchos ogros al norte, cerca de la frontera con la Marisma de Zangar.', 0),
(@ID, 'esMX', '¿Has conseguido más abalorios de guerra? Encontrarás muchos ogros al norte, cerca de la frontera con la Marisma de Zangar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sacaremos buenos beneficios con estos, $n. Seguro que a Khoraazi le llegarán las noticias sobre lo que has hecho.', 0),
(@ID, 'esMX', 'Sacaremos buenos beneficios con estos, $n. Seguro que a Khoraazi le llegarán las noticias sobre lo que has hecho.', 0);
-- 9893 Abalorios de guerra de obsidiana
-- https://es.wowhead.com/quest=9893
SET @ID := 9893;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te tratan esos ogros, $n? Son bastante duros de pelar, ¿eh?', 0),
(@ID, 'esMX', '¿Cómo te tratan esos ogros, $n? Son bastante duros de pelar, ¿eh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Esto nos mantendrá a flote mientras esperamos a que los Sha\'tar terminen con todas esas tareas domésticas que están haciendo dentro de Oshu\'gun.', 0),
(@ID, 'esMX', 'Excelente. Esto nos mantendrá a flote mientras esperamos a que los Sha\'tar terminen con todas esas tareas domésticas que están haciendo dentro de Oshu\'gun.', 0);
-- 9894 Vigilando a los vigías
-- https://es.wowhead.com/quest=9894
SET @ID := 9894;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has engargado de Lord Klaq?', 0),
(@ID, 'esMX', '¿Te has engargado de Lord Klaq?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi gratitud, $n, y la de los vigías. Les encantará saber que pueden continuar con su trabajo del sur sin temer un ataque.', 0),
(@ID, 'esMX', 'Tienes mi gratitud, $n, y la de los vigías. Les encantará saber que pueden continuar con su trabajo del sur sin temer un ataque.', 0);
-- 9895 Equilibrio en extinción
-- https://es.wowhead.com/quest=9895
SET @ID := 9895;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has encontrado con Látigo de ciénaga?', 0),
(@ID, 'esMX', '¿Te has encontrado con Látigo de ciénaga?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que has visto los síntomas del desequilibrio con tus propios ojos, fíjate bien en tus viajes.', 0),
(@ID, 'esMX', 'Ahora que has visto los síntomas del desequilibrio con tus propios ojos, fíjate bien en tus viajes.', 0);
-- 9896 La pesadilla de Aguijonegro
-- https://es.wowhead.com/quest=9896
SET @ID := 9896;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el aguijón? Recuerda, no me sirve de nada si está dañado.', 0),
(@ID, 'esMX', '¿Has conseguido el aguijón? Recuerda, no me sirve de nada si está dañado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te imaginas cuánto te lo agradezco, muchacho. Voy a disfrutar de esto...', 0),
(@ID, 'esMX', 'No te imaginas cuánto te lo agradezco, muchacho. Voy a disfrutar de esto...', 0);
-- 9897 ¡A salvo!
-- https://es.wowhead.com/quest=9897
SET @ID := 9897;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Kristen es una persona muy...<tose>... amable al compartir sus pieles, ¿no crees?', 0),
(@ID, 'esMX', 'Kristen es una persona muy...<tose>... amable al compartir sus pieles, ¿no crees?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En fin, no he podido ver si ayudaste a salvar a Kristen o no. Pero si te ha dado uno de sus fajos de pieles, será por algo.$B$BAquí tienes tu recompensa.', 0),
(@ID, 'esMX', 'En fin, no he podido ver si ayudaste a salvar a Kristen o no. Pero si te ha dado uno de sus fajos de pieles, será por algo.$B$BAquí tienes tu recompensa.', 0);
-- 9898 Nada dice Te quiero como un gran aguijón
-- https://es.wowhead.com/quest=9898
SET @ID := 9898;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi suerte está a punto de cambiar... puedo sentirlo.', 0),
(@ID, 'esMX', 'Mi suerte está a punto de cambiar... puedo sentirlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Nunca olvidaré cómo me ayudaste a ganar su corazón. De hecho, serás $gel invitado:lainvitada; de honor en nuestra boda.', 0),
(@ID, 'esMX', '¡Fantástico! Nunca olvidaré cómo me ayudaste a ganar su corazón. De hecho, serás $gel invitado:lainvitada; de honor en nuestra boda.', 0);
-- 9899 Un trabajo sin terminar
-- https://es.wowhead.com/quest=9899
SET @ID := 9899;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No voy acambiar de opinión, lo juro. Creo que tendré que pedirle al Cazador de las Sombras Denjai un traslado de regreso a Zabra\'jin.', 0),
(@ID, 'esMX', 'No voy acambiar de opinión, lo juro. Creo que tendré que pedirle al Cazador de las Sombras Denjai un traslado de regreso a Zabra\'jin.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al menos alguien está haciendo algo por aquí. Gracias por encargarte del problema, $n. Tengo que hablar con Zurai sobre Reavij. Ya hemos tenido bastante de sus ardides y tanto soñar despierto.', 0),
(@ID, 'esMX', 'Al menos alguien está haciendo algo por aquí. Gracias por encargarte del problema, $n. Tengo que hablar con Zurai sobre Reavij. Ya hemos tenido bastante de sus ardides y tanto soñar despierto.', 0);
-- 9900 Gava'xi
-- https://es.wowhead.com/quest=9900
SET @ID := 9900;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $r. ¿Gava\'xi está muerto?', 0),
(@ID, 'esMX', 'Has vuelto, $r. ¿Gava\'xi está muerto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya no tendremos que preocuparnos por Gava\'xi nunca más gracias a ti. Vamos a buscarte una buena recompensa.', 0),
(@ID, 'esMX', 'Ya no tendremos que preocuparnos por Gava\'xi nunca más gracias a ti. Vamos a buscarte una buena recompensa.', 0);
-- 9901 Negocios inconclusos
-- https://es.wowhead.com/quest=9901
SET @ID := 9901;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste localizar a Esporala?', 0),
(@ID, 'esMX', '¿Conseguiste localizar a Esporala?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Creo que tú y yo hemos conseguido superar a todo un equipo de prospectores. Cuando vuelva a Forjaz, seguro que puedo elegir mi próxima misión.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Creo que tú y yo hemos conseguido superar a todo un equipo de prospectores. Cuando vuelva a Forjaz, seguro que puedo elegir mi próxima misión.', 0);
-- 9902 El terror del Lago Luz Pantanosa
-- https://es.wowhead.com/quest=9902
SET @ID := 9902;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me avergüenza no poder hacer más para ayudar a mis hermanos esclavizados. pero al menos hemos evitado más muertes innecesarias.', 0),
(@ID, 'esMX', 'Me avergüenza no poder hacer más para ayudar a mis hermanos esclavizados. pero al menos hemos evitado más muertes innecesarias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Quizás con la ayuda de los $r, esta marisma estará algún día libre de los nagas. No puedo imaginarme lo que puede suponer ser su esclavo.$B$BNo habla mucho del tema, pero Maktu fue un esclavo hace tiempo.', 0),
(@ID, 'esMX', 'Gracias, $n. Quizás con la ayuda de los $r, esta marisma estará algún día libre de los nagas. No puedo imaginarme lo que puede suponer ser su esclavo.$B$BNo habla mucho del tema, pero Maktu fue un esclavo hace tiempo.', 0);
-- 9903 El más grande de todos
-- https://es.wowhead.com/quest=9903
SET @ID := 9903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has "retirado" al viejo Mragesh?', 0),
(@ID, 'esMX', '¿Has "retirado" al viejo Mragesh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguro que el viejo ha visto el fin de sus días. Con todas estas nuevas llegadas, el antiguo orden no podía continuar. Al final, es para bien que su espíritu esté descansando.', 0),
(@ID, 'esMX', 'Seguro que el viejo ha visto el fin de sus días. Con todas estas nuevas llegadas, el antiguo orden no podía continuar. Al final, es para bien que su espíritu esté descansando.', 0);
-- 9904 La persecución de Terrogarra
-- https://es.wowhead.com/quest=9904
SET @ID := 9904;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que Terrogarra ya no vive.', 0),
(@ID, 'esMX', 'Supongo que Terrogarra ya no vive.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! Dicen que todo gran pescador tiene una historia sobre "el pez que consiguió escapar," pero todavía no he conocido ninguna criatura que consiguiera escapar de mí... de una forma u otra.', 0),
(@ID, 'esMX', '¡Por fin! Dicen que todo gran pescador tiene una historia sobre "el pez que consiguió escapar," pero todavía no he conocido ninguna criatura que consiguiera escapar de mí... de una forma u otra.', 0);
-- 9905 La venganza de Maktu
-- https://es.wowhead.com/quest=9905
SET @ID := 9905;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace mucho tiempo, Maktu podría haber usado la piel de Mragesh para hacer una armadura fuerte. Mragesh ya es demasiado viejo para eso. Demasiado blando para una buena armadura.', 0),
(@ID, 'esMX', 'Hace mucho tiempo, Maktu podría haber usado la piel de Mragesh para hacer una armadura fuerte. Mragesh ya es demasiado viejo para eso. Demasiado blando para una buena armadura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maktu asiente en señal de aprobación.>$B$BMaktu te agradece tu ayuda. El orgullo de Maktu ha quedado satisfecho. No volverá a ser cogido con la guardia baja.', 0),
(@ID, 'esMX', '<Maktu asiente en señal de aprobación.>$B$BMaktu te agradece tu ayuda. El orgullo de Maktu ha quedado satisfecho. No volverá a ser cogido con la guardia baja.', 0);
-- 9906 Mensaje en una batalla
-- https://es.wowhead.com/quest=9906
SET @ID := 9906;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy enviando una pequeña partida de búsqueda organizada para el resto de los aldeanos.', 0),
(@ID, 'esMX', 'Estoy enviando una pequeña partida de búsqueda organizada para el resto de los aldeanos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía no hemos terminado. Hay que enseñar una lección a muchos más.', 0),
(@ID, 'esMX', 'Todavía no hemos terminado. Hay que enseñar una lección a muchos más.', 0);
-- 9907 Un audaz avance
-- https://es.wowhead.com/quest=9907
SET @ID := 9907;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay que recordarles que somos una fuerza a tener en cuenta en esta región.', 0),
(@ID, 'esMX', 'Hay que recordarles que somos una fuerza a tener en cuenta en esta región.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si esto no congela la sangre de tus venas, nada lo hará. Has conseguido justicia para los Mag\'har, $n. Y por la justicia, los Mag\'har recompensan generosamente.', 0),
(@ID, 'esMX', 'Si esto no congela la sangre de tus venas, nada lo hará. Has conseguido justicia para los Mag\'har, $n. Y por la justicia, los Mag\'har recompensan generosamente.', 0);
-- 9910 Confalones y prácticas
-- https://es.wowhead.com/quest=9910
SET @ID := 9910;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Primer confalón de batalla colocado', `ObjectiveText2` = 'Segundo confalón de batalla colocado', `ObjectiveText3` = 'Tercer confalón de batalla colocado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El respeto al miedo! Tan bueno como cualquier otro tipo de respeto.', 0),
(@ID, 'esMX', '¡El respeto al miedo! Tan bueno como cualquier otro tipo de respeto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quizás quieras encargarte de otra tarea? Algo más delicado, ¿eh?', 0),
(@ID, 'esMX', '¿Quizás quieras encargarte de otra tarea? Algo más delicado, ¿eh?', 0);
-- 9911 El conde de las marismas
-- https://es.wowhead.com/quest=9911
SET @ID := 9911;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La vigía parpadea varias veces con asombro.>$B$B¿Dónde has conseguido esa... cosa?', 0),
(@ID, 'esMX', '<La vigía parpadea varias veces con asombro.>$B$B¿Dónde has conseguido esa... cosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás $gseguro:segura; de que es real? Quiero decir que ya sabía que había mucha vida salvaje en la marisma, pero hay criaturas gigantes y después hay bichos GIGANTES.$B$BAhora que lo pienso, los esporines hablaban de una raya abisal que solía aterrorizarlos antes de la incursión del señor de la marisma.$B$B¿Qué pasaría si fuera cierto? Cielos, la expedición querrá estar informada de esto.', 0),
(@ID, 'esMX', '¿Estás $gseguro:segura; de que es real? Quiero decir que ya sabía que había mucha vida salvaje en la marisma, pero hay criaturas gigantes y después hay bichos GIGANTES.$B$BAhora que lo pienso, los esporines hablaban de una raya abisal que solía aterrorizarlos antes de la incursión del señor de la marisma.$B$B¿Qué pasaría si fuera cierto? Cielos, la expedición querrá estar informada de esto.', 0);
-- 9912 La Expedición Cenarion
-- https://es.wowhead.com/quest=9912
SET @ID := 9912;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida al Refugio Cenarion, $n. Espero que hayas venido a ayudarnos. Tenemos mucho trabajo que hacer.', 0),
(@ID, 'esMX', 'Te doy la bienvenida al Refugio Cenarion, $n. Espero que hayas venido a ayudarnos. Tenemos mucho trabajo que hacer.', 0);
-- 9913 ¡El Consorcio te necesita!
-- https://es.wowhead.com/quest=9913
SET @ID := 9913;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás $gpreparado:preparada; para ponerte a trabajar, $r? Creo que tengo la tarea perfecta para ti.', 0),
(@ID, 'esMX', '¿Estás $gpreparado:preparada; para ponerte a trabajar, $r? Creo que tengo la tarea perfecta para ti.', 0);
-- 9914 Una cabeza llena de marfil
-- https://es.wowhead.com/quest=9914
SET @ID := 9914;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es marfil lo que quiero, no excusas. Si quieres, podemos renegociar tu porcentaje de los beneficios. Dudo que te conformes con el resultado.', 0),
(@ID, 'esMX', 'Es marfil lo que quiero, no excusas. Si quieres, podemos renegociar tu porcentaje de los beneficios. Dudo que te conformes con el resultado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No he dudado de ti ni por un segundo, $gamigo:amiga;. La mayoría son buenos especímenes, aunque algo sucios y con arañazos... aun así, creo que valen lo que habíamos acordado.$B$BEspero que podamos seguir haciendo negocios en el futuro.', 0),
(@ID, 'esMX', 'No he dudado de ti ni por un segundo, $gamigo:amiga;. La mayoría son buenos especímenes, aunque algo sucios y con arañazos... aun así, creo que valen lo que habíamos acordado.$B$BEspero que podamos seguir haciendo negocios en el futuro.', 0);
-- 9915 Más cabezas llenas de marfil
-- https://es.wowhead.com/quest=9915
SET @ID := 9915;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía necesito más pares de colmillos de marfil de los elekk salvajes que deambulan por esta tierra. Desafortunadamente, mi presupuesto ya no cubrirá tu parte de las ganancias. Sin embargo, si continúas proporcionándome lo que necesito, te congraciarás con el Consorcio.', 0),
(@ID, 'esMX', 'Todavía necesito más pares de colmillos de marfil de los elekk salvajes que deambulan por esta tierra. Desafortunadamente, mi presupuesto ya no cubrirá tu parte de las ganancias. Sin embargo, si continúas proporcionándome lo que necesito, te congraciarás con el Consorcio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelentes especímenes de colmillos más finos, aunque algunos parecen un poco sucios. Tienes la gratitud del Consorcio, $n.', 0),
(@ID, 'esMX', 'Excelentes especímenes de colmillos más finos, aunque algunos parecen un poco sucios. Tienes la gratitud del Consorcio, $n.', 0);
-- 9916 Cajones de suministros Foso Sangrante
-- https://es.wowhead.com/quest=9916
SET @ID := 9916;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los niños podrán al fin pasar un día sin sentir punzadas de hambre.', 0),
(@ID, 'esMX', 'Los niños podrán al fin pasar un día sin sentir punzadas de hambre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La mayoría de nuestras posesiones fueron destruidas o robadas en los ataques. No puedo ofrecerte mucho, pero hay algunos objetos que quizás podrían resultarte útiles...', 0),
(@ID, 'esMX', 'La mayoría de nuestras posesiones fueron destruidas o robadas en los ataques. No puedo ofrecerte mucho, pero hay algunos objetos que quizás podrían resultarte útiles...', 0);
-- 9917 ¿Me engañan mis ojos?
-- https://es.wowhead.com/quest=9917
SET @ID := 9917;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto alguna información?', 0),
(@ID, 'esMX', '¿Has descubierto alguna información?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Bintook lee los planes.>$B$B¡POR LA LUZ! Su escritura es atroz. Por lo que puedo leer están planeando "comerse los pieles azules y capturar su aldea" o hacer una tarta de pieles azules en la aldea. Podría ser cualquier cosa. ¡Tenemos que llegar al fondo del asunto!', 0),
(@ID, 'esMX', '<Bintook lee los planes.>$B$B¡POR LA LUZ! Su escritura es atroz. Por lo que puedo leer están planeando "comerse los pieles azules y capturar su aldea" o hacer una tarta de pieles azules en la aldea. Podría ser cualquier cosa. ¡Tenemos que llegar al fondo del asunto!', 0);
-- 9918 ¡No durante mi guardia!
-- https://es.wowhead.com/quest=9918
SET @ID := 9918;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Zoquete ha sido interrogado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Probablemente estará dormido en una loma.', 0),
(@ID, 'esMX', 'Probablemente estará dormido en una loma.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pero bueno! ¿Es un grupo de cazadores y exploradores? ¡Debes decirle a Mo\'mor lo que has descubierto!', 0),
(@ID, 'esMX', '¡Pero bueno! ¿Es un grupo de cazadores y exploradores? ¡Debes decirle a Mo\'mor lo que has descubierto!', 0);
-- 9919 Esporaggar
-- https://es.wowhead.com/quest=9919
SET @ID := 9919;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que mostrarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que mostrarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has ayudado a proteger la próxima generación de esporinos, $r. Solo podemos pagártelo dándote la bienvenida a nuestros hogares. Quédate durante un tiempo y conoce a los otros esporinos. Te harán muchas preguntas, espero que no te importe.', 0),
(@ID, 'esMX', 'Has ayudado a proteger la próxima generación de esporinos, $r. Solo podemos pagártelo dándote la bienvenida a nuestros hogares. Quédate durante un tiempo y conoce a los otros esporinos. Te harán muchas preguntas, espero que no te importe.', 0);
-- 9920 Mo'Mor el Rompedor
-- https://es.wowhead.com/quest=9920
SET @ID := 9920;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mo\'mor parece perplejo.>$B$BAsí que una nueva tribu de ogros está empujando a los Puño de Roca cada vez más al sur. Eso es preocupante. Primero tenemos que solucionar lo que nos queda más cerca de casa...', 0),
(@ID, 'esMX', '<Mo\'mor parece perplejo.>$B$BAsí que una nueva tribu de ogros está empujando a los Puño de Roca cada vez más al sur. Eso es preocupante. Primero tenemos que solucionar lo que nos queda más cerca de casa...', 0);
-- 9921 Las Ruinas Filo Ardiente
-- https://es.wowhead.com/quest=9921
SET @ID := 9921;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recientemente hemos recuperado Telaar. ¡No la volveremos a perder!', 0),
(@ID, 'esMX', 'Recientemente hemos recuperado Telaar. ¡No la volveremos a perder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. ¿Localizaste a ese tal Lantresor del que hablaba la carta?$B$BEn todo caso, tenemos que seguir. ¡Hemos detectado más actividad de los ogros y hay que ocuparse del asunto de inmediato!', 0),
(@ID, 'esMX', 'Excelente. ¿Localizaste a ese tal Lantresor del que hablaba la carta?$B$BEn todo caso, tenemos que seguir. ¡Hemos detectado más actividad de los ogros y hay que ocuparse del asunto de inmediato!', 0);
-- 9922 Las fallas gemelas de Nagrand
-- https://es.wowhead.com/quest=9922
SET @ID := 9922;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con los elementales en la cuenca, $n.', 0),
(@ID, 'esMX', 'Cuidado con los elementales en la cuenca, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Estoy estudiando a la tribu Mazo de Guerra de la que habló el teniente Puño de Roca. Ahora hay que poner a prueba las tareas que has completado.', 0),
(@ID, 'esMX', '¡Excelente! Estoy estudiando a la tribu Mazo de Guerra de la que habló el teniente Puño de Roca. Ahora hay que poner a prueba las tareas que has completado.', 0);
-- 9923 ¡AYUDA!
-- https://es.wowhead.com/quest=9923
SET @ID := 9923;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Corki liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese chico...$B$B<Arechron niega con la cabeza con desaprobación.>$B$BÉl será mi muerte.', 0),
(@ID, 'esMX', 'Ese chico...$B$B<Arechron niega con la cabeza con desaprobación.>$B$BÉl será mi muerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo siento mucho, $r. Siempre se está metiendo en líos. Ojalá pudiera ponerle una correa...', 0),
(@ID, 'esMX', 'Lo siento mucho, $r. Siempre se está metiendo en líos. Ojalá pudiera ponerle una correa...', 0);
-- 9924 ¡Corki ha vuelto a desaparecer!
-- https://es.wowhead.com/quest=9924
SET @ID := 9924;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Corki liberado de nuevo', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo encontraste?', 0),
(@ID, 'esMX', '¿Lo encontraste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchísimas gracias, $n. A partir de ahora, su madre se encargará de él.', 0),
(@ID, 'esMX', 'Muchísimas gracias, $n. A partir de ahora, su madre se encargará de él.', 0);
-- 9925 Una cuestión de seguridad
-- https://es.wowhead.com/quest=9925
SET @ID := 9925;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te encargaste de los engendros del vacío, $n?', 0),
(@ID, 'esMX', '¿Te encargaste de los engendros del vacío, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Consigues que sonría, $n. O, mejor dicho, lo harías si aún tuviera rostro.$B$BSigue así y acabaremos siendo los mejores amigos.', 0),
(@ID, 'esMX', 'Consigues que sonría, $n. O, mejor dicho, lo harías si aún tuviera rostro.$B$BSigue así y acabaremos siendo los mejores amigos.', 0);
-- 9927 Astucia despiadada
-- https://es.wowhead.com/quest=9927
SET @ID := 9927;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Estandarte ogro de Mazo de Guerra colocado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lantresor abre los ojos perplejo.>$B$B¿Ya está?', 0),
(@ID, 'esMX', '<Lantresor abre los ojos perplejo.>$B$B¿Ya está?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedes imaginarte su sorpresa ante lo que está pasando, $r? Esto va a ser glorioso.', 0),
(@ID, 'esMX', '¿Puedes imaginarte su sorpresa ante lo que está pasando, $r? Esto va a ser glorioso.', 0);
