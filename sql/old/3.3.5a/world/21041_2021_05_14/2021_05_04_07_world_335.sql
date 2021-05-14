-- 9416 Preséntate ante el general Kirika
-- https://es.classic.wowhead.com/quest=9416
SET @ID := 9416;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que estés aquí, pero no hay tiempo que perder en charlas triviales. Necesitas instrucciones, y luego necesitas salir.$B$B$gAtento:Atenta;.', 0),
(@ID, 'esMX', 'Es bueno que estés aquí, pero no hay tiempo que perder en charlas triviales. Necesitas instrucciones, y luego necesitas salir.$B$B$gAtento:Atenta;.', 0);
-- 9417 La amenaza arakkoa
-- https://es.wowhead.com/quest=9417
SET @ID := 9417;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estás de vuelta! ¿Cómo lo hiciste?', 0),
(@ID, 'esMX', '¡Estás de vuelta! ¿Cómo lo hiciste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo, $n! Te declaro Barbalarga $ghonorario:honoraria;.$B$BQuédate por aquí y tómate algo con nosotros.', 0),
(@ID, 'esMX', '¡Excelente trabajo, $n! Te declaro Barbalarga $ghonorario:honoraria;.$B$BQuédate por aquí y tómate algo con nosotros.', 0);
-- 9418 El orbe de Avruu
-- https://es.wowhead.com/quest=9418
SET @ID := 9418;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin he conseguido la libertad que tanto he ansiado!', 0),
(@ID, 'esMX', '¡Al fin he conseguido la libertad que tanto he ansiado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con este orbe recupero mi libertad. Ten tu recompensa, mortal, y nuestra deuda quedará saldada.', 0),
(@ID, 'esMX', 'Con este orbe recupero mi libertad. Ten tu recompensa, mortal, y nuestra deuda quedará saldada.', 0);
-- 9419 Peinando el desierto
-- https://es.classic.wowhead.com/quest=9419
SET @ID := 9419;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Devuelve la silitista', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado, pero también se $grápido:rápida;. No tenemos tiempo que perder.', 0),
(@ID, 'esMX', 'Ten cuidado, pero también se $grápido:rápida;. No tenemos tiempo que perder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a la Luz, tuviste éxito.$B$BAhora bien, si solo hubiéramos podido comenzar esto antes, nuestra necesidad no sería tan desesperada. Debemos evitar que la generosidad del desierto caiga en manos de la Horda.', 0),
(@ID, 'esMX', 'Gracias a la Luz, tuviste éxito.$B$BAhora bien, si solo hubiéramos podido comenzar esto antes, nuestra necesidad no sería tan desesperada. Debemos evitar que la generosidad del desierto caiga en manos de la Horda.', 0);
-- 9420 Las plumas más finas
-- https://es.wowhead.com/quest=9420
SET @ID := 9420;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las plumas de kaliri, $c?', 0),
(@ID, 'esMX', '¿Traes las plumas de kaliri, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has cumplido tu parte y un trato es un trato.$B$BAquí tienes el sombrero. Cuídalo.', 0),
(@ID, 'esMX', 'Has cumplido tu parte y un trato es un trato.$B$BAquí tienes el sombrero. Cuídalo.', 0);
-- 9421 Entrenamiento de chamán
-- https://es.wowhead.com/quest=9421
SET @ID := 9421;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy Firmanvaar y es prudente que me busques. Mi llamado es brindar instrucción a los chamanes, especialmente a aquellos que están comenzando su aprendizaje.$B$BEl chamanismo se está volviendo a aprender entre los draenei, $n. Eres valiente para seguir su camino, ya que no es popular entre los de tu raza.$B$BEstaré aquí cuando sientas que estás $glisto:lista; para seguir formandote.', 0),
(@ID, 'esMX', 'Soy Firmanvaar y es prudente que me busques. Mi llamado es brindar instrucción a los chamanes, especialmente a aquellos que están comenzando su aprendizaje.$B$BEl chamanismo se está volviendo a aprender entre los draenei, $n. Eres valiente para seguir su camino, ya que no es popular entre los de tu raza.$B$BEstaré aquí cuando sientas que estás $glisto:lista; para seguir formandote.', 0);
-- 9422 Peinando el desierto
-- https://es.classic.wowhead.com/quest=9422
SET @ID := 9422;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Entrega la silitista', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado con los peligros del desierto, $n. Con la Alianza al acecho en las dunas, cualquier paso podría ser el último.', 0),
(@ID, 'esMX', 'Ten cuidado con los peligros del desierto, $n. Con la Alianza al acecho en las dunas, cualquier paso podría ser el último.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Estos recursos se agregarán a nuestras reservas, y cada migaja que sea para nuestro beneficio no lo es para nuestro enemigo.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Estos recursos se agregarán a nuestras reservas, y cada migaja que sea para nuestro beneficio no lo es para nuestro enemigo.', 0);
-- 9423 Regresa junto a Obadei
-- https://es.wowhead.com/quest=9423
SET @ID := 9423;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sedai, hermano mío...$B$B¡Malditos orcos cobardes! ¡Iba desarmado!$B$BAhora vete, $n. Agradezco tu ayuda, pero ahora quiero estar solo.', 0),
(@ID, 'esMX', 'Sedai, hermano mío...$B$B¡Malditos orcos cobardes! ¡Iba desarmado!$B$BAhora vete, $n. Agradezco tu ayuda, pero ahora quiero estar solo.', 0);
-- 9424 La venganza de Makuru
-- https://es.wowhead.com/quest=9424
SET @ID := 9424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vengaste a Sedai de parte de Makuru?', 0),
(@ID, 'esMX', '¿Vengaste a Sedai de parte de Makuru?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mmm, venganza! Muy bien.$B$BToma esto; era un regalo de Sedai. Makuru se pone triste solo de verlo.', 0),
(@ID, 'esMX', '¡Mmm, venganza! Muy bien.$B$BToma esto; era un regalo de Sedai. Makuru se pone triste solo de verlo.', 0);
-- 9425 Informando en Molino Tarren
-- https://es.wowhead.com/quest=9425
SET @ID := 9425;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gOtro:Otra; de mis $ghermanos:hermanas; llega para colaborar. ¡Bien! Hay mucho por hacer en apoyo de nuestros nuevos amigos Renegados, $n. Pregunta a tu alrededor para ver a quién puedes ayudar.$B$B¡Sé que los apoyarás a tu máxima capacidad!', 0),
(@ID, 'esMX', '$gOtro:Otra; de mis $ghermanos:hermanas; llega para colaborar. ¡Bien! Hay mucho por hacer en apoyo de nuestros nuevos amigos Renegados, $n. Pregunta a tu alrededor para ver a quién puedes ayudar.$B$B¡Sé que los apoyarás a tu máxima capacidad!', 0);
-- 9426 Las Pozas de Aggonar
-- https://es.wowhead.com/quest=9426
SET @ID := 9426;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, siento que la presencia en las pozas se está debilitando.$B$BBuen trabajo, $n.', 0),
(@ID, 'esMX', 'Sí, siento que la presencia en las pozas se está debilitando.$B$BBuen trabajo, $n.', 0);
-- 9427 Limpiando las aguas
-- https://es.wowhead.com/quest=9427
SET @ID := 9427;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Esencia de Aggonar eliminada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n, ¿has limpiado las aguas?', 0),
(@ID, 'esMX', 'Dime, $n, ¿has limpiado las aguas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La esencia de Aggonar siguió viviendo en su nauseabundo descendiente, Aggonis. Ahora que has derrotado al demonio, podemos empezar a purificar las pozas.$B$BTe damos las gracias, $n. Has hecho un gran bien a este mundo.', 0),
(@ID, 'esMX', 'La esencia de Aggonar siguió viviendo en su nauseabundo descendiente, Aggonis. Ahora que has derrotado al demonio, podemos empezar a purificar las pozas.$B$BTe damos las gracias, $n. Has hecho un gran bien a este mundo.', 0);
-- 9428 Misión en Puesto del Hachazo
-- https://es.wowhead.com/quest=9428
SET @ID := 9428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El embajador envió un mensaje por adelantado, así que te estaba esperando.$B$BEl embajador simplemente quiere que hagas todo lo que puedas para ayudar aquí. Dijo algo sobre asegurarnos de consolidar nuestra relación con el resto de la Horda.$B$BHay otros que necesitan ayuda más atrás en el Puesto. Y escuché que hay otro puesto de la Horda llamado Puesto avanzado Zoram\'gar en la costa hasta el oeste.', 0),
(@ID, 'esMX', 'El embajador envió un mensaje por adelantado, así que te estaba esperando.$B$BEl embajador simplemente quiere que hagas todo lo que puedas para ayudar aquí. Dijo algo sobre asegurarnos de consolidar nuestra relación con el resto de la Horda.$B$BHay otros que necesitan ayuda más atrás en el Puesto. Y escuché que hay otro puesto de la Horda llamado Puesto avanzado Zoram\'gar en la costa hasta el oeste.', 0);
-- 9429 Viaje a Villa Oscura
-- https://es.wowhead.com/quest=9429
SET @ID := 9429;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Confío en que tu viaje hasta aquí haya transcurrido sin incidentes.$B$BEstas pobres almas están acosadas por todos lados por las criaturas de la noche. Es nuestro deseo que les prestes toda la ayuda que puedas para hacer retroceder a la oscuridad.$B$BRecorre el pueblo y conoce a sus habitantes. Por favor, $n, ayúdalos en todo lo que puedas.', 0),
(@ID, 'esMX', 'Saludos, $n. Confío en que tu viaje hasta aquí haya transcurrido sin incidentes.$B$BEstas pobres almas están acosadas por todos lados por las criaturas de la noche. Es nuestro deseo que les prestes toda la ayuda que puedas para hacer retroceder a la oscuridad.$B$BRecorre el pueblo y conoce a sus habitantes. Por favor, $n, ayúdalos en todo lo que puedas.', 0);
-- 9430 Las reliquias de Sha'naar
-- https://es.wowhead.com/quest=9430
SET @ID := 9430;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado las reliquias de Sha\'naar, $n?', 0),
(@ID, 'esMX', '¿Has recuperado las reliquias de Sha\'naar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mucha suerte. Como esperaba, has encontrado una reliquia especial entre las demás.', 0),
(@ID, 'esMX', 'Tienes mucha suerte. Como esperaba, has encontrado una reliquia especial entre las demás.', 0);
-- 9431 Un enfoque diferente
-- https://es.wowhead.com/quest=9431
SET @ID := 9431;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La nota de Magistrix Elosai fue un poco críptica, pero creo que entiendo lo que quiere que haga. Si tienes la tierra de la que ella habló, puedo ponerla en el recipiente que necesitarás para el agua de la poza de la luna.', 0),
(@ID, 'esMX', 'La nota de Magistrix Elosai fue un poco críptica, pero creo que entiendo lo que quiere que haga. Si tienes la tierra de la que ella habló, puedo ponerla en el recipiente que necesitarás para el agua de la poza de la luna.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Ella no mencionó la fuente de la luna? Eso es lo que ella tenía en mente todo el tiempo. Admito que todo es un poco loco, pero ¿quién soy yo para rechazar a un cliente, especialmente cuando ella es la única que tengo?$B$BTal vez intentar colarse en un asentamiento de elfos de la noche y robar agua de su pozo de la luna no es lo más prudente que he ayudado a hacer a un cliente, ¡pero su oro es tan bueno como el de cualquier otra persona!', 0),
(@ID, 'esMX', '¿Qué? ¿Ella no mencionó la fuente de la luna? Eso es lo que ella tenía en mente todo el tiempo. Admito que todo es un poco loco, pero ¿quién soy yo para rechazar a un cliente, especialmente cuando ella es la única que tengo?$B$BTal vez intentar colarse en un asentamiento de elfos de la noche y robar agua de su pozo de la luna no es lo más prudente que he ayudado a hacer a un cliente, ¡pero su oro es tan bueno como el de cualquier otra persona!', 0);
-- 9432 Viaje a Astranaar
-- https://es.wowhead.com/quest=9432
SET @ID := 9432;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre es bueno ver una cara casi familiar. Debes ser $n. El emisario Valustraa me envió un mensaje para avisarme.$B$BLa gente de Vallefresno necesita nuestra ayuda, $n. Habla con los ciudadanos de Astranaar para ver cómo puedes ayudar.', 0),
(@ID, 'esMX', 'Siempre es bueno ver una cara casi familiar. Debes ser $n. El emisario Valustraa me envió un mensaje para avisarme.$B$BLa gente de Vallefresno necesita nuestra ayuda, $n. Habla con los ciudadanos de Astranaar para ver cómo puedes ayudar.', 0);
-- 9433 En la Poza de la Luna
-- https://es.wowhead.com/quest=9433
SET @ID := 9433;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho el trabajo?', 0),
(@ID, 'esMX', '¿Has hecho el trabajo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Funcionó mejor de lo que esperaba! ¡Otro punto para el buen ingenio de los goblins!$B$B¡El único problema es que está irremediablemente cubierto de polvo! Me va a llevar una eternidad limpiar esta cosa y volver a colocarla en su caja.$B$BPor supuesto, el tiempo es lo único que tengo en abundancia.', 0),
(@ID, 'esMX', '¡Funcionó mejor de lo que esperaba! ¡Otro punto para el buen ingenio de los goblins!$B$B¡El único problema es que está irremediablemente cubierto de polvo! Me va a llevar una eternidad limpiar esta cosa y volver a colocarla en su caja.$B$BPor supuesto, el tiempo es lo único que tengo en abundancia.', 0);
-- 9434 Probando el tónico
-- https://es.wowhead.com/quest=9434
SET @ID := 9434;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Habeis podido reunir los reactivos, Wizlo y tú?', 0),
(@ID, 'esMX', '¿Habeis podido reunir los reactivos, Wizlo y tú?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, parece que todo está aquí. Ahora, lo que tengo que hacer es mezclar todo y probarlo. Si este tónico hace lo que mi investigación indica que debería hacer, es posible que haya descubierto una manera de disminuir los efectos de la adicción a la magia de mi gente.$B$BEstás a punto de presenciar cómo se está gestando la historia, $n. Solo piensa que sin tu ayuda, esto no hubiera sido posible.', 0),
(@ID, 'esMX', 'Excelente, parece que todo está aquí. Ahora, lo que tengo que hacer es mezclar todo y probarlo. Si este tónico hace lo que mi investigación indica que debería hacer, es posible que haya descubierto una manera de disminuir los efectos de la adicción a la magia de mi gente.$B$BEstás a punto de presenciar cómo se está gestando la historia, $n. Solo piensa que sin tu ayuda, esto no hubiera sido posible.', 0);
-- 9436 Técnicas Sangrapellejo
-- https://es.wowhead.com/quest=9436
SET @ID := 9436;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me falles, $n. Si podemos doblegar esta magia Sangrapellejo a nuestra voluntad, mi gente aún puede eliminar la amenaza Amani.', 0),
(@ID, 'esMX', 'No me falles, $n. Si podemos doblegar esta magia Sangrapellejo a nuestra voluntad, mi gente aún puede eliminar la amenaza Amani.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. Ahora, esto es curioso...$B$BLa inscripción de este tótem está en un idioma que ningún trol podría esperar aprender, pero nosotros lo conocemos. Nombra al portador como un aliado de un elemental de agua llamado Naias y lo marca como alguien digno de canalizar su poder.$B$BEsto es inesperado, pero no del todo malo, $n. Con tu ayuda, me gustaría continuar con esto.', 0),
(@ID, 'esMX', 'Bien hecho. Ahora, esto es curioso...$B$BLa inscripción de este tótem está en un idioma que ningún trol podría esperar aprender, pero nosotros lo conocemos. Nombra al portador como un aliado de un elemental de agua llamado Naias y lo marca como alguien digno de canalizar su poder.$B$BEsto es inesperado, pero no del todo malo, $n. Con tu ayuda, me gustaría continuar con esto.', 0);
-- 9437 El surcador del ocaso
-- https://es.wowhead.com/quest=9437
SET @ID := 9437;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Rescata a Ithania de la Torre de la Punta Norte', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has liberado a Ithania y recuperado mi cargamento de esos corsarios exaltados?', 0),
(@ID, 'esMX', '¿Has liberado a Ithania y recuperado mi cargamento de esos corsarios exaltados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! En cuanto Ithania haya descansado y yo acabe con los preparativos, nos marcharemos de estas tierras empantanadas y volveremos a la civilización.', 0),
(@ID, 'esMX', '¡Muy bien, $n! En cuanto Ithania haya descansado y yo acabe con los preparativos, nos marcharemos de estas tierras empantanadas y volveremos a la civilización.', 0);
-- 9438 Mensaje para Thrall
-- https://es.wowhead.com/quest=9438
SET @ID := 9438;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes noticias de Terrallende, $n? ¡Habla ahora mismo!', 0),
(@ID, 'esMX', '¿Traes noticias de Terrallende, $n? ¡Habla ahora mismo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ves cómo se afloja la mandíbula de Thrall cuando comienza a leer el mensaje de Nazgrel.>$B$BMi gente... debemos llegar a ellos. ¡Debemos llegar a Nagrand lo antes posible!', 0),
(@ID, 'esMX', '<Ves cómo se afloja la mandíbula de Thrall cuando comienza a leer el mensaje de Nazgrel.>$B$BMi gente... debemos llegar a ellos. ¡Debemos llegar a Nagrand lo antes posible!', 0);
-- 9439 Equipaje perdido
-- https://es.wowhead.com/quest=9439
SET @ID := 9439;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por el amor del Caminante del Sol, no me mires! ¡Ya es bastante malo que me vea obligado a aguantar aquí con mi ropa sucia! Después de todo lo que he pasado, lo último que necesito es que se queden boquiabiertos. ¿Conseguiste recoger mis pertenencias de ese agujero en el suelo que los Hierro Negro llaman fortaleza?', 0),
(@ID, 'esMX', '¡Por el amor del Caminante del Sol, no me mires! ¡Ya es bastante malo que me vea obligado a aguantar aquí con mi ropa sucia! Después de todo lo que he pasado, lo último que necesito es que se queden boquiabiertos. ¿Conseguiste recoger mis pertenencias de ese agujero en el suelo que los Hierro Negro llaman fortaleza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres $gun hacedor:una hacedora; de milagros, $n! Te lo digo, nunca en mi vida había estado tan ansioso por cambiarme de ropa.$B$B¡Y mi espada! Me sentía desnudo sin mi espada.$B$BDebes ser $gfelicitado y recompensado:felicitada y recompensada; por tus esfuerzos. ¡Que nunca se diga que Sarophas no reconoció a las personas insignificantes que lo ayudaron en el camino!', 0),
(@ID, 'esMX', '¡Eres $gun hacedor:una hacedora; de milagros, $n! Te lo digo, nunca en mi vida había estado tan ansioso por cambiarme de ropa.$B$B¡Y mi espada! Me sentía desnudo sin mi espada.$B$BDebes ser $gfelicitado y recompensado:felicitada y recompensada; por tus esfuerzos. ¡Que nunca se diga que Sarophas no reconoció a las personas insignificantes que lo ayudaron en el camino!', 0);
-- 9440 Bocaditos peligrosos
-- https://es.wowhead.com/quest=9440
SET @ID := 9440;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Crocolisco capturado alimentado', `ObjectiveText2` = 'Jaguar capturado alimentado', `ObjectiveText3` = 'Tarántula capturada alimentada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alimentaste a los animales capturados? ¡Espera! No le diste nada a ese estúpido humano que tienen en la jaula, ¿verdad?$B$B¡Oh Dios! ¡Eso habría sido un desperdicio!', 0),
(@ID, 'esMX', '¿Alimentaste a los animales capturados? ¡Espera! No le diste nada a ese estúpido humano que tienen en la jaula, ¿verdad?$B$B¡Oh Dios! ¡Eso habría sido un desperdicio!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, excelente! ¡No puedo esperar a medir los efectos de este último lote!$B$BBueno, hiciste un trabajo admirable, cariño. Ojalá pudiera darte más que esto por el entretenimiento que me has brindado, pero ya sabes cómo es. No hay mucho dinero que ganar aquí en el pantano.$B$B¡Estoy segura de que valió la pena solo por la diversión!', 0),
(@ID, 'esMX', '¡Oh, excelente! ¡No puedo esperar a medir los efectos de este último lote!$B$BBueno, hiciste un trabajo admirable, cariño. Ojalá pudiera darte más que esto por el entretenimiento que me has brindado, pero ya sabes cómo es. No hay mucho dinero que ganar aquí en el pantano.$B$B¡Estoy segura de que valió la pena solo por la diversión!', 0);
-- 9441 Tributo a los Mag'har
-- https://es.wowhead.com/quest=9441
SET @ID := 9441;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Significa mucho para nosotros que vengas a ayudarnos en nuestro momento de necesidad. No te olvidaremos fácilmente ni a quien te envió.$B$BTienes nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Significa mucho para nosotros que vengas a ayudarnos en nuestro momento de necesidad. No te olvidaremos fácilmente ni a quien te envió.$B$BTienes nuestro agradecimiento.', 0);
-- 9442 Enfermedad debilitante
-- https://es.wowhead.com/quest=9442
SET @ID := 9442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Obtuviste el hongo que necesito, $n?', 0),
(@ID, 'esMX', '¿Obtuviste el hongo que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gorkan dijo cosas buenas de ti. Todas están resultando ser ciertas.$B$BGracias por tu ayuda.', 0),
(@ID, 'esMX', 'Gorkan dijo cosas buenas de ti. Todas están resultando ser ciertas.$B$BGracias por tu ayuda.', 0);
-- 9443 La supuesta marca del Iluminado
-- https://es.wowhead.com/quest=9443
SET @ID := 9443;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas logrado recuperar su \'marca\', la cambiaremos un poco; la haremos mejor.', 0),
(@ID, 'esMX', 'Cuando hayas logrado recuperar su \'marca\', la cambiaremos un poco; la haremos mejor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El primer paso está completo. Pásame la Marca del Iluminado y la transformaré en algo más adecuado.$B$B¡Entonces mi venganza comenzará en serio, $n!', 0),
(@ID, 'esMX', 'El primer paso está completo. Pásame la Marca del Iluminado y la transformaré en algo más adecuado.$B$B¡Entonces mi venganza comenzará en serio, $n!', 0);
-- 9444 Profanar la Tumba de Uther
-- https://es.wowhead.com/quest=9444
SET @ID := 9444;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Tumba de Uther profanada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho? ¿La tumba de Uther está profanada?', 0),
(@ID, 'esMX', '¿Está hecho? ¿La tumba de Uther está profanada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me perdona? ¡¡¿ME PERDONA? !!!$B$BNo me importa lo que ese viejo fantasma tenga que decir, ¡fue su culpa! ¡Todo lo que le sucedió a Quel\'Thalas fue el resultado de su incompetencia!$B$BEstá claro que la profanación no funcionó. ¡Vete, vete de mi vista! Debo pensar en esto.', 0),
(@ID, 'esMX', '¿Me perdona? ¡¡¿ME PERDONA? !!!$B$BNo me importa lo que ese viejo fantasma tenga que decir, ¡fue su culpa! ¡Todo lo que le sucedió a Quel\'Thalas fue el resultado de su incompetencia!$B$BEstá claro que la profanación no funcionó. ¡Vete, vete de mi vista! Debo pensar en esto.', 0);
-- 9446 La Tumba del Iluminado
-- https://es.wowhead.com/quest=9446
SET @ID := 9446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No se supone que debes estar caminando hacia la tumba de Uther con el Anacoreta Truuen?', 0),
(@ID, 'esMX', '¿No se supone que debes estar caminando hacia la tumba de Uther con el Anacoreta Truuen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Iluminado apareció ante ti? ¡Esto es increíble! Y lo hiciste todo posible gracias a tu desinteresada ayuda al anacoreta.$B$BSi hay que creer siquiera la mitad de las historias, Uther fue un gran hombre. Y, como él, ¡eres $gun verdadero héroe:una verdadera heroína; para toda la buena gente de Azeroth, $n!', 0),
(@ID, 'esMX', '¿El Iluminado apareció ante ti? ¡Esto es increíble! Y lo hiciste todo posible gracias a tu desinteresada ayuda al anacoreta.$B$BSi hay que creer siquiera la mitad de las historias, Uther fue un gran hombre. Y, como él, ¡eres $gun verdadero héroe:una verdadera heroína; para toda la buena gente de Azeroth, $n!', 0);
-- 9447 El bálsamo
-- https://es.wowhead.com/quest=9447
SET @ID := 9447;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Brutos debilitados sanados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Tu tarea está completa?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Tu tarea está completa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que los espíritus te bendigan, $n. Los Mag\'har están en deuda contigo.', 0),
(@ID, 'esMX', 'Que los espíritus te bendigan, $n. Los Mag\'har están en deuda contigo.', 0);
-- 9448 Piedad para los malditos
-- Notice: English text: Replace 'hunter' for '$c' in quest_request_items.CompletionText
-- https://es.wowhead.com/quest=9448
SET @ID := 9448;
UPDATE `quest_request_items` SET `CompletionText` = 'You are doing the right thing, $c. The Lost Ones have suffered so much already. They shouldn\'t have to suffer this further indignity.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás haciendo lo correcto, $c. Los Perdidos ya han sufrido mucho. No deberían tener que sufrir esta indignidad adicional.', 0),
(@ID, 'esMX', 'Estás haciendo lo correcto, $c. Los Perdidos ya han sufrido mucho. No deberían tener que sufrir esta indignidad adicional.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces está hecho. Te agradezco por mostrar tu compasión. Una vez corrompido por lo que sea que Cersei los estaba alimentando, no hay nada más que se pueda hacer.$B$BAhora están en paz y espero que mis estudios de los demás den sus frutos para que puedan rehabilitarse.', 0),
(@ID, 'esMX', 'Entonces está hecho. Te agradezco por mostrar tu compasión. Una vez corrompido por lo que sea que Cersei los estaba alimentando, no hay nada más que se pueda hacer.$B$BAhora están en paz y espero que mis estudios de los demás den sus frutos para que puedan rehabilitarse.', 0);
-- 9449 La llamada de la tierra
-- https://es.wowhead.com/quest=9449
SET @ID := 9449;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te atreves a buscar mi sabiduría después de lo que tu pueblo ha hecho con estas islas, forastero! Aún así, hay mucho que decir a favor de tu valentía, así que te impartiré algunos conocimientos.$B$BLa tierra debajo de tus pies forma la base de todas las cosas. El cielo, las aguas, incluso el gran fuego, todo descansa sobre sus hombros. Mientras que los otros a menudo forman tempestades caóticas, la tierra permanece. Otorga fuerza y fortaleza al núcleo de tu ser.$B$BAhora probarás tu valía, chamán.', 0),
(@ID, 'esMX', '¡Te atreves a buscar mi sabiduría después de lo que tu pueblo ha hecho con estas islas, forastero! Aún así, hay mucho que decir a favor de tu valentía, así que te impartiré algunos conocimientos.$B$BLa tierra debajo de tus pies forma la base de todas las cosas. El cielo, las aguas, incluso el gran fuego, todo descansa sobre sus hombros. Mientras que los otros a menudo forman tempestades caóticas, la tierra permanece. Otorga fuerza y fortaleza al núcleo de tu ser.$B$BAhora probarás tu valía, chamán.', 0);
-- 9450 La llamada de la tierra
-- https://es.wowhead.com/quest=9450
SET @ID := 9450;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los elementos todavía me parecen desequilibrados, $n.', 0),
(@ID, 'esMX', 'Los elementos todavía me parecen desequilibrados, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien. Disminuyendo los espíritus inquietos, has ayudado a sanar el desequilibrio entre los elementos, que tu gente causó inadvertidamente.$B$BA lo largo de tu viaje como chamán debes tener esto en cuenta cuando invoques nuestro poder. Debe preservarse el equilibrio.', 0),
(@ID, 'esMX', 'Lo has hecho bien. Disminuyendo los espíritus inquietos, has ayudado a sanar el desequilibrio entre los elementos, que tu gente causó inadvertidamente.$B$BA lo largo de tu viaje como chamán debes tener esto en cuenta cuando invoques nuestro poder. Debe preservarse el equilibrio.', 0);
-- 9451 La llamada de la tierra
-- https://es.wowhead.com/quest=9451
SET @ID := 9451;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Juntos, los Tábidos y los Draenei recuperarán una comprensión más profunda de los misterios que encierran los elementos.$B$B¿Has regresado con lo necesario para la creación de tu tótem terrestre?', 0),
(@ID, 'esMX', 'Juntos, los Tábidos y los Draenei recuperarán una comprensión más profunda de los misterios que encierran los elementos.$B$B¿Has regresado con lo necesario para la creación de tu tótem terrestre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Al ayudar a restablecer el equilibrio de los elementos en la arboleda, también has creado un equilibrio entre el elemento tierra de este mundo y los draenei. ¿Quizás esto ayude a traer entendimiento a aquellos entre nosotros que no aprueban nuestros caminos?$B$BCrearé para ti un tótem a través del cual podrás invocar el poder de la tierra para que cumpla tus órdenes. Y con el tiempo, se te revelarán más misterios de la tierra.$B$BAhora, toma tu tótem, chamán.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Al ayudar a restablecer el equilibrio de los elementos en la arboleda, también has creado un equilibrio entre el elemento tierra de este mundo y los draenei. ¿Quizás esto ayude a traer entendimiento a aquellos entre nosotros que no aprueban nuestros caminos?$B$BCrearé para ti un tótem a través del cual podrás invocar el poder de la tierra para que cumpla tus órdenes. Y con el tiempo, se te revelarán más misterios de la tierra.$B$BAhora, toma tu tótem, chamán.', 0);
-- 9452 Delicioso pargo rojo
-- https://es.wowhead.com/quest=9452
SET @ID := 9452;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con los múrlocs; son unas criaturas pequeñas, raras y muy, muy molestas.', 0),
(@ID, 'esMX', 'Cuidado con los múrlocs; son unas criaturas pequeñas, raras y muy, muy molestas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que los múrlocs no dieran mucho problema, $n. Estoy en deuda contigo por todo lo que has hecho.$B$B¿Quieres que te enseñe a pescar? Yo pongo la caña y un regalito.', 0),
(@ID, 'esMX', 'Espero que los múrlocs no dieran mucho problema, $n. Estoy en deuda contigo por todo lo que has hecho.$B$B¿Quieres que te enseñe a pescar? Yo pongo la caña y un regalito.', 0);
-- 9453 Busca a Acteon
-- https://es.wowhead.com/quest=9453
SET @ID := 9453;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te parece mi armadura? ¡La hice yo! Es un poco distinta de lo normal, pero muy cómoda.', 0),
(@ID, 'esMX', '¿Qué te parece mi armadura? ¡La hice yo! Es un poco distinta de lo normal, pero muy cómoda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pobre Diktynna, vaya susto se llevó con ese múrloc.$B$B<Acteon suspira.>$B$BEspero que se recupere pronto...$B$BSupongo que buscas trabajo. Bien, ¡en la Avanzada Azur no te va a faltar!', 0),
(@ID, 'esMX', 'Pobre Diktynna, vaya susto se llevó con ese múrloc.$B$B<Acteon suspira.>$B$BEspero que se recupere pronto...$B$BSupongo que buscas trabajo. Bien, ¡en la Avanzada Azur no te va a faltar!', 0);
