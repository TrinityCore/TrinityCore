-- 10183 Al Área 52
-- https://es.wowhead.com/quest=10183
SET @ID := 10183;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ocupado, ocupado. ¡No hay tiempo que perder! ¡Hay que construir un cohete!$B$B¿Qué quieres?', 0),
(@ID, 'esMX', 'Ocupado, ocupado. ¡No hay tiempo que perder! ¡Hay que construir un cohete!$B$B¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, Nicuproso finalmente decidió informar sobre sus hallazgos, ¿verdad? ¡Científicos perezosos!$B$B¿Qué es esto?$B$B<El jefe hojea las anotaciones varias veces, claramente con una mirada de incredulidad>.$B$BDice aquí que las violentas energías inferiores que fluyen a través de la Tormenta Abisal van a hacer trizas todo en solo unos meses.$B$BEso es un inconveniente, ¡ahora tendremos que avanzar en el cronograma para construir el cohete!', 0),
(@ID, 'esMX', 'Oh, Nicuproso finalmente decidió informar sobre sus hallazgos, ¿verdad? ¡Científicos perezosos!$B$B¿Qué es esto?$B$B<El jefe hojea las anotaciones varias veces, claramente con una mirada de incredulidad>.$B$BDice aquí que las violentas energías inferiores que fluyen a través de la Tormenta Abisal van a hacer trizas todo en solo unos meses.$B$BEso es un inconveniente, ¡ahora tendremos que avanzar en el cronograma para construir el cohete!', 0);
-- 10184 Restos malévolos
-- https://es.wowhead.com/quest=10184
SET @ID := 10184;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me duele saber que hay tan poco que hacer por nuestros camaradas.', 0),
(@ID, 'esMX', 'Me duele saber que hay tan poco que hacer por nuestros camaradas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Custodio Valemuerte mueve la cabeza.>$B$BNo es lo que se merecían, pero es lo mejor que podemos hacer.', 0),
(@ID, 'esMX', '<El Custodio Valemuerte mueve la cabeza.>$B$BNo es lo que se merecían, pero es lo mejor que podemos hacer.', 0);
-- 10185 Terrible destino
-- https://es.wowhead.com/quest=10185
SET @ID := 10185;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado eliminar algunas de las criaturas de maná de las ruinas de la aldea?', 0),
(@ID, 'esMX', '¿Has logrado eliminar algunas de las criaturas de maná de las ruinas de la aldea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El custodio parece consternado.>$B$BYa veo la siguiente ola en el horizonte. Lo que estamos haciendo funcionará de momento, pero tenemos que tomar medidas permanentes.', 0),
(@ID, 'esMX', '<El custodio parece consternado.>$B$BYa veo la siguiente ola en el horizonte. Lo que estamos haciendo funcionará de momento, pero tenemos que tomar medidas permanentes.', 0);
-- 10186 ¡Te contrato!
-- https://es.wowhead.com/quest=10186
SET @ID := 10186;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿A ti te parece que el cohete abisal X-52 está listo para despegar? ¿Acaso me ves surcando El Vacío Abisal sentado cómodamente en mi sillón de mando? ¿Explorando nuevos y apasionantes mundos? ¿Buscando nueva tecnología y oportunidades de negocio?$B$B¡No!$B$BAsí que, espero que tengas esos cristales que te pedí.', 0),
(@ID, 'esMX', '¿A ti te parece que el cohete abisal X-52 está listo para despegar? ¿Acaso me ves surcando El Vacío Abisal sentado cómodamente en mi sillón de mando? ¿Explorando nuevos y apasionantes mundos? ¿Buscando nueva tecnología y oportunidades de negocio?$B$B¡No!$B$BAsí que, espero que tengas esos cristales que te pedí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bah! No tienen muy buena pinta. ¿Quizás podamos usarlos en la sala terciaria del motor del colector?$B$BEn fin, no está mal para un técnico inferior de tercer grado. Llegarás al segundo grado en muy poco tiempo.', 0),
(@ID, 'esMX', '¡Bah! No tienen muy buena pinta. ¿Quizás podamos usarlos en la sala terciaria del motor del colector?$B$BEn fin, no está mal para un técnico inferior de tercer grado. Llegarás al segundo grado en muy poco tiempo.', 0);
-- 10188 El sigilo de Krasus
-- https://es.wowhead.com/quest=10188
SET @ID := 10188;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito el sigilo para librarme de la maldición de la torre.', 0),
(@ID, 'esMX', 'Necesito el sigilo para librarme de la maldición de la torre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, es tan magnífico como recordaba. ¿Sientes el poder que irradia?$B$BNaturalmente, queda mucho por hacer, pero te agradezco profundamente que me hayas traído el sigilo.', 0),
(@ID, 'esMX', 'Ah, es tan magnífico como recordaba. ¿Sientes el poder que irradia?$B$BNaturalmente, queda mucho por hacer, pero te agradezco profundamente que me hayas traído el sigilo.', 0);
-- 10189 Forja de Maná B'naar
-- https://es.wowhead.com/quest=10189
SET @ID := 10189;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los objetos que pedí, $n?', 0),
(@ID, 'esMX', '¿Traes los objetos que pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Con esto tendremos muchos más datos para atacar a los seguidores de Kael en las forjas de maná.$B$BEs una lástima; le estaba cogiendo el gusto a esto de matar a sus lacayos indiscriminadamente.', 0),
(@ID, 'esMX', '¡Excelente! Con esto tendremos muchos más datos para atacar a los seguidores de Kael en las forjas de maná.$B$BEs una lástima; le estaba cogiendo el gusto a esto de matar a sus lacayos indiscriminadamente.', 0);
-- 10190 Recargando las baterías
-- https://es.wowhead.com/quest=10190
SET @ID := 10190;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Nivel de carga de la batería', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recargado ya la batería?', 0),
(@ID, 'esMX', '¿Has recargado ya la batería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, cuidado, mira dónde apuntas con eso! ¡¡¡Tienes el control puesto en \'Matar\'!!!$B$BBueno, parece que has recargado la batería y hasta algo más. Eso ayudará a los chicos a seguir adelante.', 0),
(@ID, 'esMX', '¡Eh, cuidado, mira dónde apuntas con eso! ¡¡¡Tienes el control puesto en \'Matar\'!!!$B$BBueno, parece que has recargado la batería y hasta algo más. Eso ayudará a los chicos a seguir adelante.', 0);
-- 10191 ¡Mark V está vivo!
-- https://es.wowhead.com/quest=10191
SET @ID := 10191;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto?$B$B¿Está todo bien con el Maxx Y. Millón nº. V?', 0),
(@ID, 'esMX', '¿Regresaste tan pronto?$B$B¿Está todo bien con el Maxx Y. Millón nº. V?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Lo has conseguido! ¡Casi te daría un beso!$B$BOh, vaya... el Maxx Y. Millón nº. V se ha vuelto a quedar sin batería. Bah, ya ha hecho su trabajo ¡y eso es lo que cuenta!$B$B¡El jefe de cohetes Fuselaje estará encantado de tener estas máquinas draenei en el cohete abisal X-52! ¡Y eso significa un ascenso para mí! Estoy tan contenta, ¡tengo que darte una recompensa!$B$BToma, elige lo que quieras.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Lo has conseguido! ¡Casi te daría un beso!$B$BOh, vaya... el Maxx Y. Millón nº. V se ha vuelto a quedar sin batería. Bah, ya ha hecho su trabajo ¡y eso es lo que cuenta!$B$B¡El jefe de cohetes Fuselaje estará encantado de tener estas máquinas draenei en el cohete abisal X-52! ¡Y eso significa un ascenso para mí! Estoy tan contenta, ¡tengo que darte una recompensa!$B$BToma, elige lo que quieras.', 0);
-- 10192 El Compendio de Krasus
-- https://es.wowhead.com/quest=10192
SET @ID := 10192;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el libro?', 0),
(@ID, 'esMX', '¿Traes el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La imagen del archimago Vargoth parece inspeccionar el compendio.>$B$BEstá un poco estropeado, pero teniendo en cuenta por todo lo que ha pasado, es un milagro que haya sobrevivido. Guárdalo en lugar seguro, $n. Sin él no tenemos ninguna posibilidad de romper el resguardo de la torre.', 0),
(@ID, 'esMX', '<La imagen del archimago Vargoth parece inspeccionar el compendio.>$B$BEstá un poco estropeado, pero teniendo en cuenta por todo lo que ha pasado, es un milagro que haya sobrevivido. Guárdalo en lugar seguro, $n. Sin él no tenemos ninguna posibilidad de romper el resguardo de la torre.', 0);
-- 10193 Objetivos de gran valor
-- https://es.wowhead.com/quest=10193
SET @ID := 10193;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va, $n? ¿Tienes alguna noticia? ¿Qué has hecho por mí últimamente?', 0),
(@ID, 'esMX', '¿Cómo te va, $n? ¿Tienes alguna noticia? ¿Qué has hecho por mí últimamente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gdigno:digna; de confianza, $n. Si hay algo que me guste más que matar a siervos de Kael es que lo hagan por mí.$B$BAsí no me mancho la ropa.', 0),
(@ID, 'esMX', 'Eres $gdigno:digna; de confianza, $n. Si hay algo que me guste más que matar a siervos de Kael es que lo hagan por mí.$B$BAsí no me mancho la ropa.', 0);
-- 10194 Vuelo sigiloso
-- https://es.wowhead.com/quest=10194
SET @ID := 10194;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No fue barato preparar tu vuelo. Esperemos que tengas lo que hay que tener para hacer bien el trabajo.', 0),
(@ID, 'esMX', 'No fue barato preparar tu vuelo. Esperemos que tengas lo que hay que tener para hacer bien el trabajo.', 0);
-- 10197 Un disfraz convincente
-- https://es.wowhead.com/quest=10197
SET @ID := 10197;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las prendas que te pedí?', 0),
(@ID, 'esMX', '¿Has conseguido las prendas que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Cuando acabe contigo, podrás pasearte tranquilamente entre las filas de los Furia del Sol.', 0),
(@ID, 'esMX', '¡Excelente! Cuando acabe contigo, podrás pasearte tranquilamente entre las filas de los Furia del Sol.', 0);
-- 10198 Reuniendo pistas
-- https://es.wowhead.com/quest=10198
SET @ID := 10198;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal va eso, $n? Date prisa, me estoy empezando a poner nervioso.', 0),
(@ID, 'esMX', '¿Qué tal va eso, $n? Date prisa, me estoy empezando a poner nervioso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Forja de Maná Duro está en peligro? ¡Seguro que Thalodien se alegrará de oír tal noticia! Rematemos la faena aquí primero.', 0),
(@ID, 'esMX', '¿La Forja de Maná Duro está en peligro? ¡Seguro que Thalodien se alegrará de oír tal noticia! Rematemos la faena aquí primero.', 0);
-- 10199 Ese pequeño toque extra
-- https://es.wowhead.com/quest=10199
SET @ID := 10199;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si puedo conseguir el suficiente veneno de estos aguijones de raya abisal, creo que tendremos entre manos el combustible más explosivo jamás creado.', 0),
(@ID, 'esMX', 'Si puedo conseguir el suficiente veneno de estos aguijones de raya abisal, creo que tendremos entre manos el combustible más explosivo jamás creado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau! ¡Ahora sí!$B$BDeja que coja esas bellezas y les saque toda su maldad. Esto debería hacer una mezcla de combustible de cohete que dejará a todo el mundo boquiabierto.$B$BA ver, deja que mezcle el aceite de esquisto con el veneno del aguijón y veamos qué pasa...', 0),
(@ID, 'esMX', '¡Guau! ¡Ahora sí!$B$BDeja que coja esas bellezas y les saque toda su maldad. Esto debería hacer una mezcla de combustible de cohete que dejará a todo el mundo boquiabierto.$B$BA ver, deja que mezcle el aceite de esquisto con el veneno del aguijón y veamos qué pasa...', 0);
-- 10200 Regresa junto a Thalodien
-- https://es.wowhead.com/quest=10200
SET @ID := 10200;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejas de impresionarme, $n. Lo que has hecho en la Forja de Maná Coruu ha sido un gran despliegue de sigilo.', 0),
(@ID, 'esMX', 'No dejas de impresionarme, $n. Lo que has hecho en la Forja de Maná Coruu ha sido un gran despliegue de sigilo.', 0);
-- 10201 Y ahora, el momento de la verdad
-- https://es.wowhead.com/quest=10201
SET @ID := 10201;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Conseguir que Grek pruebe el aceite de olemba', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿tienes los resultados de la prueba?', 0),
(@ID, 'esMX', 'Bueno, ¿tienes los resultados de la prueba?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le dices a Rakoria los resultados de la prueba y empieza a reírse.>', 0),
(@ID, 'esMX', '<Le dices a Rakoria los resultados de la prueba y empieza a reírse.>', 0);
-- 10202 Un desertor
-- https://es.wowhead.com/quest=10202
SET @ID := 10202;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. Empezaba a preguntarme si los Arúspices estaban interesados.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. Empezaba a preguntarme si los Arúspices estaban interesados.', 0);
-- 10203 El ultra-desconsolidador es muy útil
-- https://es.wowhead.com/quest=10203
SET @ID := 10203;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Excavamática hiperrotacional recuperada', `ObjectiveText2` = 'Cangilón de arrastre servoneumático recuperado', `ObjectiveText3` = 'Analizador de terreno multiespectro recuperado', `ObjectiveText4` = 'Vagón grande lleno de explosivos recuperado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No es genial este lugar? ¡Y todos los días producen algo nuevo y exótico!$B$BQué golpe de suerte, y pensar que casi destruimos la ciudad excavando aquí.', 0),
(@ID, 'esMX', '¿No es genial este lugar? ¡Y todos los días producen algo nuevo y exótico!$B$BQué golpe de suerte, y pensar que casi destruimos la ciudad excavando aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tú debes de ser quien nos envió todo ese equipamiento desde las ruinas! ¡Hurra por ti!$B$BYa he reenviado el equipamiento a otras ubicaciones. Ahora podremos ampliar nuestras operaciones en la fisura a toda la isla, ¡por orden de magnitud! El cohete abisal estará terminado en un abrir y cerrar de ojos.$B$BMmmm, qué extraño. Espera, ¿dijiste que nos habías enviado cuatro cosas? Solo tengo tres...', 0),
(@ID, 'esMX', '¡Tú debes de ser quien nos envió todo ese equipamiento desde las ruinas! ¡Hurra por ti!$B$BYa he reenviado el equipamiento a otras ubicaciones. Ahora podremos ampliar nuestras operaciones en la fisura a toda la isla, ¡por orden de magnitud! El cohete abisal estará terminado en un abrir y cerrar de ojos.$B$BMmmm, qué extraño. Espera, ¿dijiste que nos habías enviado cuatro cosas? Solo tengo tres...', 0);
-- 10204 Cristales de gema de sangre
-- https://es.wowhead.com/quest=10204
SET @ID := 10204;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Investigaste las gemas de sangre utilizadas por los magister Furia del Sol, $n?', 0),
(@ID, 'esMX', '¿Investigaste las gemas de sangre utilizadas por los magister Furia del Sol, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmmm... Justo lo que sospechaba.$B$BLa exposición a este nivel de energía pura magnifica en gran medida nuestra innata adición a la magia.$B$BNo me sorprende que Kael se salga siempre con la suya; todos sus subordinados están controlados por esto.', 0),
(@ID, 'esMX', 'Mmmm... Justo lo que sospechaba.$B$BLa exposición a este nivel de energía pura magnifica en gran medida nuestra innata adición a la magia.$B$BNo me sorprende que Kael se salga siempre con la suya; todos sus subordinados están controlados por esto.', 0);
-- 10205 Asaltante de distorsión Nesaad
-- https://es.wowhead.com/quest=10205
SET @ID := 10205;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se acabó entonces? ¿Asaltante de distorsión Nesaad está muerto?', 0),
(@ID, 'esMX', '¿Se acabó entonces? ¿Asaltante de distorsión Nesaad está muerto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un alivio pensar que esa escoria ha recibido su merecido. Bien hecho, $n... No te importa que te llame por el nombre de pila, ¿verdad?$B$BSi quieres, tengo otra tarea para ti. Es muy importante y no le resultará difícil a alguien con tu talento.', 0),
(@ID, 'esMX', 'Es un alivio pensar que esa escoria ha recibido su merecido. Bien hecho, $n... No te importa que te llame por el nombre de pila, ¿verdad?$B$BSi quieres, tengo otra tarea para ti. Es muy importante y no le resultará difícil a alguien con tu talento.', 0);
-- 10206 Tú eliges
-- https://es.wowhead.com/quest=10206
SET @ID := 10206;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes los artilugios de tecnología? Por tu bien, espero que no me intentes engañar, $c.$B$BEl éxito del proyecto X-52 depende de que consigas esas cosas lo antes posible.', 0),
(@ID, 'esMX', '¿Ya tienes los artilugios de tecnología? Por tu bien, espero que no me intentes engañar, $c.$B$BEl éxito del proyecto X-52 depende de que consigas esas cosas lo antes posible.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Je, je, idiotas etéreos!$B$BGracias por las piezas, $c. Seguro que podemos enganchar estas cosas justo dentro del cohete. Me pregunto qué efecto tendrán. ¡Será divertido descubrirlo!$B$BMmm, veamos si tengo algo de calderilla para lanzártela.', 0),
(@ID, 'esMX', '¡Je, je, idiotas etéreos!$B$BGracias por las piezas, $c. Seguro que podemos enganchar estas cosas justo dentro del cohete. Me pregunto qué efecto tendrán. ¡Será divertido descubrirlo!$B$BMmm, veamos si tengo algo de calderilla para lanzártela.', 0);
-- 10208 Perturbar sus refuerzos
-- https://es.wowhead.com/quest=10208
SET @ID := 10208;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Perturbar el Portal Xilus', `ObjectiveText2` = 'Perturbar el Portal Kruul', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Legión no estará preparada para tu sorpresa, ¿eh, $n?', 0),
(@ID, 'esMX', 'La Legión no estará preparada para tu sorpresa, ¿eh, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho! Casi he podido sentir la explosión desde aquí.$B$BAhora tenemos otra misión explosiva para ti...', 0),
(@ID, 'esMX', '¡Bien hecho! Casi he podido sentir la explosión desde aquí.$B$BAhora tenemos otra misión explosiva para ti...', 0);
-- 10209 El premio del invocador Kanthin
-- https://es.wowhead.com/quest=10209
SET @ID := 10209;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la Piedra de Glacius?', 0),
(@ID, 'esMX', '¿Has conseguido la Piedra de Glacius?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<No tienes muy claro si es un espejismo o el archimago realmente está sonriendo.>$B$BAl recuperar la última de mis posesiones, tengo todo lo necesario para romper la magia de Kael\'thas. Comenzaré a trabajar inmediatamente.', 0),
(@ID, 'esMX', '<No tienes muy claro si es un espejismo o el archimago realmente está sonriendo.>$B$BAl recuperar la última de mis posesiones, tengo todo lo necesario para romper la magia de Kael\'thas. Comenzaré a trabajar inmediatamente.', 0);
-- 10210 A'dal
-- https://es.wowhead.com/quest=10210
SET @ID := 10210;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La luz que te envolvía al acercarte a A\'dal se intensifica cuando le hablas. Oyes una dulce melodía dentro de tu cabeza.>$B$B<Aquí estás a salvo.>', 0),
(@ID, 'esMX', '<La luz que te envolvía al acercarte a A\'dal se intensifica cuando le hablas. Oyes una dulce melodía dentro de tu cabeza.>$B$B<Aquí estás a salvo.>', 0);
-- 10211 La Ciudad de la Luz
-- https://es.wowhead.com/quest=10211
SET @ID := 10211;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las historias de los hombres son efímeras, $n. Las historias de las ciudades perduran durante muchos años.', 0),
(@ID, 'esMX', 'Las historias de los hombres son efímeras, $n. Las historias de las ciudades perduran durante muchos años.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas aprendido un par de cosas sobre Shattrath, $n. Puede que tardes un poco en asimilarlo.', 0),
(@ID, 'esMX', 'Espero que hayas aprendido un par de cosas sobre Shattrath, $n. Puede que tardes un poco en asimilarlo.', 0);
-- 10212 Héroe Mag'har
-- https://es.wowhead.com/quest=10212
SET @ID := 10212;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres verdaderamente $gel héroe:la heroína; de los Mag\'har, $n. Si no fuera por ti, seguramente los ogros y Tábidos nos hubieran invadido.$B$BSomos un pueblo pobre pero tenemos algunos artefactos de poder. Por favor, insisto en que cojas uno de nuestro cofre.', 0),
(@ID, 'esMX', 'Eres verdaderamente $gel héroe:la heroína; de los Mag\'har, $n. Si no fuera por ti, seguramente los ogros y Tábidos nos hubieran invadido.$B$BSomos un pueblo pobre pero tenemos algunos artefactos de poder. Por favor, insisto en que cojas uno de nuestro cofre.', 0);
-- 10213 Investigar el accidente
-- https://es.wowhead.com/quest=10213
SET @ID := 10213;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Legión Ardiente nos derribó, aunque sacamos una bandera de tregua. ¿Quién sabía que la Legión Ardiente era tan detestable?$B$BNo podemos ir a la Avanzada Rompeloma. Tenemos que reparar el zepelín y continuar con nuestro viaje.', 0),
(@ID, 'esMX', 'La Legión Ardiente nos derribó, aunque sacamos una bandera de tregua. ¿Quién sabía que la Legión Ardiente era tan detestable?$B$BNo podemos ir a la Avanzada Rompeloma. Tenemos que reparar el zepelín y continuar con nuestro viaje.', 0);
-- 10216 La seguridad es prioritaria
-- https://es.wowhead.com/quest=10216
SET @ID := 10216;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este dispositivo tiene más de una docena de botones, ninguno de los cuales te resulta familiar.', 0),
(@ID, 'esMX', 'Este dispositivo tiene más de una docena de botones, ninguno de los cuales te resulta familiar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Cierras los ojos y presionas un botón.>', 0),
(@ID, 'esMX', '<Cierras los ojos y presionas un botón.>', 0);
-- 10218 El trabajo duro de alguien más nos beneficia
-- https://es.wowhead.com/quest=10218
SET @ID := 10218;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, pequeña bestia de carne.', 0),
(@ID, 'esMX', 'Hola, pequeña bestia de carne.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Viendo que esto fue idea de Morphalius, decidí devolverle su antiguo trabajo. Bien hecho, pequeña bestia de carne. ¡Bien hecho!$B$BRecuerda, si alguna vez buscas trabajo y te encuentras en Tormenta Abisal, ven a buscarme a La Flecha de la Tormenta.', 0),
(@ID, 'esMX', 'Viendo que esto fue idea de Morphalius, decidí devolverle su antiguo trabajo. Bien hecho, pequeña bestia de carne. ¡Bien hecho!$B$BRecuerda, si alguna vez buscas trabajo y te encuentras en Tormenta Abisal, ven a buscarme a La Flecha de la Tormenta.', 0);
-- 10220 Oblígales a escuchar
-- https://es.wowhead.com/quest=10220
SET @ID := 10220;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Le has enseñado a los Implacables las consecuencias de desafiar a los Renegados?', 0),
(@ID, 'esMX', '¿Le has enseñado a los Implacables las consecuencias de desafiar a los Renegados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Implacables han podido sentir el poder de la Horda. Sin duda, pronto estarán de humor para escuchar lo que quiero proponerles.', 0),
(@ID, 'esMX', 'Los Implacables han podido sentir el poder de la Horda. Sin duda, pronto estarán de humor para escuchar lo que quiero proponerles.', 0);
-- 10221 ¡Dr. Bum!
-- https://es.wowhead.com/quest=10221
SET @ID := 10221;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nos has salvado ya del malvado Dr. Bum? Te prometo que esta vez no habrá carros explosivos, ¡aunque la última vez fue muy divertido!$B$BDeberíamos hacerlo más a menudo.', 0),
(@ID, 'esMX', '¿Nos has salvado ya del malvado Dr. Bum? Te prometo que esta vez no habrá carros explosivos, ¡aunque la última vez fue muy divertido!$B$BDeberíamos hacerlo más a menudo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Echaré de menos a Chispín. <Snif> ¡Pero todos dormiremos más tranquilos ahora que el Dr. Bum ya no puede aterrorizarnos!$B$BToma buena nota de esto: ¡no vengas aquí sin ponerte un casco abisal!$B$BDime, ¿cómo puedo pagarte?', 0),
(@ID, 'esMX', 'Echaré de menos a Chispín. <Snif> ¡Pero todos dormiremos más tranquilos ahora que el Dr. Bum ya no puede aterrorizarnos!$B$BToma buena nota de esto: ¡no vengas aquí sin ponerte un casco abisal!$B$BDime, ¿cómo puedo pagarte?', 0);
-- 10222 El cuartel Furia del Sol
-- https://es.wowhead.com/quest=10222
SET @ID := 10222;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho, $n? ¿Has vengado a los caídos del Poblado Kirin\'Var?', 0),
(@ID, 'esMX', '¿Está hecho, $n? ¿Has vengado a los caídos del Poblado Kirin\'Var?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que has hecho hoy nunca nos devolverá a los caídos pero quizás alivie sus espíritus. Aunque, la verdad sea dicha, no se derramará suficiente sangre para aplacar mi furia por los actos de Kael\'thas.', 0),
(@ID, 'esMX', 'Lo que has hecho hoy nunca nos devolverá a los caídos pero quizás alivie sus espíritus. Aunque, la verdad sea dicha, no se derramará suficiente sangre para aplacar mi furia por los actos de Kael\'thas.', 0);
-- 10223 Abajo con Daellis
-- https://es.wowhead.com/quest=10223
SET @ID := 10223;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado la tarea, $n?', 0),
(@ID, 'esMX', '¿Has terminado la tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<No lo tienes muy claro, pero parece que el custodio Valemuerte está a punto de llorar.>$B$BPor fin, se acabó. Si pudiera dejar de existir, lo haría, pero la verdad es que no sé cómo dejarme ir. Para los que están en el poblado, es difícil pero no hay vuelta de hoja. Supongo que es el precio que tenemos que pagar por sentirnos tan fuertemente atados a este lugar.', 0),
(@ID, 'esMX', '<No lo tienes muy claro, pero parece que el custodio Valemuerte está a punto de llorar.>$B$BPor fin, se acabó. Si pudiera dejar de existir, lo haría, pero la verdad es que no sé cómo dejarme ir. Para los que están en el poblado, es difícil pero no hay vuelta de hoja. Supongo que es el precio que tenemos que pagar por sentirnos tan fuertemente atados a este lugar.', 0);
-- 10224 Esencia para los motores
-- https://es.wowhead.com/quest=10224
SET @ID := 10224;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya todas las esencias?', 0),
(@ID, 'esMX', '¿Tienes ya todas las esencias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, ahí hay mucha esencia!$B$BBueno, veamos qué ocurre al mezclarla con los cristales de la matriz de eterlitio.', 0),
(@ID, 'esMX', '¡Vaya, ahí hay mucha esencia!$B$BBueno, veamos qué ocurre al mezclarla con los cristales de la matriz de eterlitio.', 0);
-- 10225 Informe para lngeniería
-- https://es.wowhead.com/quest=10225
SET @ID := 10225;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, hola. Estoy algo ocupado. ¿Qué tienes ahí?', 0),
(@ID, 'esMX', 'Mmm, hola. Estoy algo ocupado. ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aah, cristales de la matriz de eterlitio. Vaya, ¡eso suena a importante!$B$BVamos a dejarlos por aquí y ya me ocuparé de ellos luego.', 0),
(@ID, 'esMX', 'Aah, cristales de la matriz de eterlitio. Vaya, ¡eso suena a importante!$B$BVamos a dejarlos por aquí y ya me ocuparé de ellos luego.', 0);
