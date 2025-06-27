-- 3379 Las tejedoras de sombra
-- https://es.classic.wowhead.com/quest=3379
SET @ID := 3379;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué información tienes?', 0),
(@ID, 'esMX', '¿Qué información tienes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n.$B$BEstoy segura de que este es un trozo de tejido de sombra que nunca has visto.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n.$B$BEstoy segura de que este es un trozo de tejido de sombra que nunca has visto.', 0);
-- El Templo Sumergido
-- 3380, 3445
-- https://es.classic.wowhead.com/quest=3380
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3380, 3445) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3380, 'esES', 'Sí, el Templo Sumergido, puedo decir que lo he visto con mis propios ojos. ¿Quizás te gustaría oír más?$B$BParece que te gustan las aventuras... sé que estas cosas podrían interesarte...', 0),
(3445, 'esES', 'Sí, el Templo Sumergido, puedo decir que lo he visto con mis propios ojos. ¿Quizás te gustaría oír más?$B$BParece que te gustan las aventuras... sé que estas cosas podrían interesarte...', 0),
(3380, 'esMX', 'Sí, el Templo Sumergido, puedo decir que lo he visto con mis propios ojos. ¿Quizás te gustaría oír más?$B$BParece que te gustan las aventuras... sé que estas cosas podrían interesarte...', 0),
(3445, 'esMX', 'Sí, el Templo Sumergido, puedo decir que lo he visto con mis propios ojos. ¿Quizás te gustaría oír más?$B$BParece que te gustan las aventuras... sé que estas cosas podrían interesarte...', 0);
-- 3381 Un encuentro con el maestro
-- https://es.classic.wowhead.com/quest=3381
SET @ID := 3381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me quedo aquí por orden de mi maestro. Me han dado permiso para pedir el precio que desee por el transporte hasta su torre. Por ahora, solo pido las dos plumas de cada viajero para poder seguir haciendo mis flechas distintivas.$B$BSi no tienes cuidado, subiré el precio. ¿Cómo suena media docena de oro?$B$BSí, lo pensé mucho. Solo ten cuidado y mantendré el precio donde está.', 0),
(@ID, 'esMX', 'Me quedo aquí por orden de mi maestro. Me han dado permiso para pedir el precio que desee por el transporte hasta su torre. Por ahora, solo pido las dos plumas de cada viajero para poder seguir haciendo mis flechas distintivas.$B$BSi no tienes cuidado, subiré el precio. ¿Cómo suena media docena de oro?$B$BSí, lo pensé mucho. Solo ten cuidado y mantendré el precio donde está.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dos plumas, tal como te pedí. Y no son malas plumas.$B$B¿$gListo:Lista; entonces? Solo di la palabra y estarás en camino.$B$BAh, y una vez más, acuerdate... mi maestro no se lleva bien con los imbéciles, pero es muy generoso con los que le agradan.', 0),
(@ID, 'esMX', 'Dos plumas, tal como te pedí. Y no son malas plumas.$B$B¿$gListo:Lista; entonces? Solo di la palabra y estarás en camino.$B$BAh, y una vez más, acuerdate... mi maestro no se lleva bien con los imbéciles, pero es muy generoso con los que le agradan.', 0);
-- 3382 Un equipo bajo el fuego enemigo
-- https://es.classic.wowhead.com/quest=3382
SET @ID := 3382;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta va a ser una dura batalla...', 0),
(@ID, 'esMX', 'Esta va a ser una dura batalla...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho! ¡Gracias! Seguramente esta fue una de las batallas más brutales en las que he participado. No puedo agradecerte lo suficiente.$B$BOjalá más miembros de mi tripulación hubieran vivido esta prueba.$B$BTe pediría que hablara con los pasajeros supervivientes del Explorador del horizonte. Algunos de ellos tenían negocios en el área y es posible que tengan una petición o dos para ti si estás $gdispuesto:dispuesta;. De nuevo, gracias por toda tu ayuda.', 0),
(@ID, 'esMX', '¡Lo has hecho! ¡Gracias! Seguramente esta fue una de las batallas más brutales en las que he participado. No puedo agradecerte lo suficiente.$B$BOjalá más miembros de mi tripulación hubieran vivido esta prueba.$B$BTe pediría que hablara con los pasajeros supervivientes del Explorador del horizonte. Algunos de ellos tenían negocios en el área y es posible que tengan una petición o dos para ti si estás $gdispuesto:dispuesta;. De nuevo, gracias por toda tu ayuda.', 0);
-- 3385 El Mercado Negro
-- https://es.classic.wowhead.com/quest=3385
SET @ID := 3385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El maestro de comercio aún vive?', 0),
(@ID, 'esMX', '¿El maestro de comercio aún vive?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has asestado un golpe decisivo al Mercado Negro. Sus líderes se lo pensarán dos veces antes de enviar más compinches al desfiladero.$B$BAh, y tampoco encontré nada útil en la cartera del comerciante. Puedes guardar lo que encuentres dentro.', 0),
(@ID, 'esMX', 'Has asestado un golpe decisivo al Mercado Negro. Sus líderes se lo pensarán dos veces antes de enviar más compinches al desfiladero.$B$BAh, y tampoco encontré nada útil en la cartera del comerciante. Puedes guardar lo que encuentres dentro.', 0);
-- 3402 El Mercado Negro
-- https://es.classic.wowhead.com/quest=3402
SET @ID := 3402;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿¿Kovic asesinado??! ¡Este es un día glorioso, $n! Durante años, ese sinvergüenza ha estado llevando a cabo operaciones turbias en el Mercado Negro, socavando a los comerciantes honestos y trabajadores de todo el mundo.$B$B¡Te mereces una excelente recompensa por este logro! ¡Y tendrás una excelente recompensa!', 0),
(@ID, 'esMX', '¡¿¿Kovic asesinado??! ¡Este es un día glorioso, $n! Durante años, ese sinvergüenza ha estado llevando a cabo operaciones turbias en el Mercado Negro, socavando a los comerciantes honestos y trabajadores de todo el mundo.$B$B¡Te mereces una excelente recompensa por este logro! ¡Y tendrás una excelente recompensa!', 0);
-- 3421 El viaje de vuelta
-- https://es.classic.wowhead.com/quest=3421
SET @ID := 3421;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te haré volver al campamento de Sanath ahora.$B$BNo hagas caso de su mala educación, es así con todos a excepción del maestro. Quizás algún día le den una lección.', 0),
(@ID, 'esMX', 'Te haré volver al campamento de Sanath ahora.$B$BNo hagas caso de su mala educación, es así con todos a excepción del maestro. Quizás algún día le den una lección.', 0);
-- 3441 Castigo divino
-- https://es.classic.wowhead.com/quest=3441
SET @ID := 3441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme contarte más... $r.', 0),
(@ID, 'esMX', 'Permíteme contarte más... $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has escuchado lo suficiente como para decidir?', 0),
(@ID, 'esMX', '¿Has escuchado lo suficiente como para decidir?', 0);
-- 3442 La llama pura
-- https://es.classic.wowhead.com/quest=3442
SET @ID := 3442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes lo que te pedí?', 0),
(@ID, 'esMX', '¿Me traes lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Sigue, sigue.', 0),
(@ID, 'esMX', 'Muy bien, $n. Sigue, sigue.', 0);
-- 3443 Forjar el mango
-- https://es.classic.wowhead.com/quest=3443
SET @ID := 3443;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡necesito 8 dagas, 8!', 0),
(@ID, 'esMX', '$n, ¡necesito 8 dagas, 8!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres excepcional, $n. ¿Has pensado en cambiar de oficio? Podrías ser detective o cazatesoros... Ya sé, puedes hacer como esos gnomos locos que van por Azeroth con detectores de metal. Sí, ese trabajo te iría que ni pintado.', 0),
(@ID, 'esMX', 'Eres excepcional, $n. ¿Has pensado en cambiar de oficio? Podrías ser detective o cazatesoros... Ya sé, puedes hacer como esos gnomos locos que van por Azeroth con detectores de metal. Sí, ese trabajo te iría que ni pintado.', 0);
-- 3444 El círculo de piedra
-- https://es.classic.wowhead.com/quest=3444
SET @ID := 3444;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Trinquete no queda lejos de aquí, $n. No deberías tardar mucho.', 0),
(@ID, 'esMX', 'Trinquete no queda lejos de aquí, $n. No deberías tardar mucho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Esta es la piedra.$B$BAhora empiezo a recordarlo todo, $n...', 0),
(@ID, 'esMX', 'Sí... Esta es la piedra.$B$BAhora empiezo a recordarlo todo, $n...', 0);
-- 3446 En las profundidades
-- https://es.classic.wowhead.com/quest=3446
SET @ID := 3446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al examinar la estatua, ves un hueco en uno de los lados, del tamaño de la piedra que Marvon te dio...', 0),
(@ID, 'esMX', 'Al examinar la estatua, ves un hueco en uno de los lados, del tamaño de la piedra que Marvon te dio...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empujas el Círculo de Piedras y puedes oír cómo encaja en su sitio.$B$BAhora que la piedra está en su lugar, puedes continuar... ¿Pero qué debes hacer ahora?$B$BQuizás deberías examinar el altar con más detenimiento...', 0),
(@ID, 'esMX', 'Empujas el Círculo de Piedras y puedes oír cómo encaja en su sitio.$B$BAhora que la piedra está en su lugar, puedes continuar... ¿Pero qué debes hacer ahora?$B$BQuizás deberías examinar el altar con más detenimiento...', 0);
-- 3447 El secreto del círculo
-- https://es.classic.wowhead.com/quest=3447
SET @ID := 3447;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ojo del ídolo emite unos destellos brillantes, incluso en la semioscuridad del templo. Su transparencia revela algo detrás de él. Empujándolo a un lado, metes la mano y consigues coger lo que hay en el interior de la estatua.$B$BEl tesoro de los Atal\'ai ya es tuyo.', 0),
(@ID, 'esMX', 'El ojo del ídolo emite unos destellos brillantes, incluso en la semioscuridad del templo. Su transparencia revela algo detrás de él. Empujándolo a un lado, metes la mano y consigues coger lo que hay en el interior de la estatua.$B$BEl tesoro de los Atal\'ai ya es tuyo.', 0);
-- 3452 El soporte para la llama
-- https://es.classic.wowhead.com/quest=3452
SET @ID := 3452;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos completar la antorcha de reprensión sin una fuente de energía arcana.', 0),
(@ID, 'esMX', 'No podemos completar la antorcha de reprensión sin una fuente de energía arcana.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El símbolo irradia Magia demoníaca; justo lo que queríamos.', 0),
(@ID, 'esMX', 'El símbolo irradia Magia demoníaca; justo lo que queríamos.', 0);
-- 3453 La antorcha de reprensión
-- https://es.classic.wowhead.com/quest=3453
SET @ID := 3453;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No interrumpas el proceso de canalización.', 0),
(@ID, 'esMX', 'No interrumpas el proceso de canalización.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes completar una última tarea.', 0),
(@ID, 'esMX', 'Debes completar una última tarea.', 0);
-- 3454 La antorcha de reprensión
-- https://es.classic.wowhead.com/quest=3454
SET @ID := 3454;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges la antorcha y sientes una corriente de odio e ira correr por tus venas.', 0),
(@ID, 'esMX', 'Coges la antorcha y sientes una corriente de odio e ira correr por tus venas.', 0);
-- 3462 Escudero Maltrake
-- https://es.classic.wowhead.com/quest=3462
SET @ID := 3462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Preparado/Preparada?', 0),
(@ID, 'esMX', '¿Preparado/Preparada?', 0);
-- 3463 ¡Préndeles fuego!
-- https://es.classic.wowhead.com/quest=3463
SET @ID := 3463;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Torre Oeste en llamas', `ObjectiveText2` = 'Torre Sur en llamas', `ObjectiveText3` = 'Torre Este en llamas', `ObjectiveText4` = 'Torre Norte en llamas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has perdido, $n?', 0),
(@ID, 'esMX', '¿Te has perdido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué vista tan gloriosa!', 0),
(@ID, 'esMX', '¡Qué vista tan gloriosa!', 0);
-- 3481 Abalorios...
-- https://es.classic.wowhead.com/quest=3481
SET @ID := 3481;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cofre se abre cuando lo tocas. ¿Cuánto queso puede haber aquí? Solo hay un modo de averiguarlo.', 0),
(@ID, 'esMX', 'El cofre se abre cuando lo tocas. ¿Cuánto queso puede haber aquí? Solo hay un modo de averiguarlo.', 0);
-- 3501 Todo cuenta en grandes cantidades
-- https://es.classic.wowhead.com/quest=3501
SET @ID := 3501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte con la exploración?', 0),
(@ID, 'esMX', '¿Ha habido suerte con la exploración?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me produces asco, $r. ¿$gUn hombre hecho y derecho:Una mujer hecha y derecha; babeando sobre una pila de baratijas? ¡Qué pena das! Toma tu recompensa y desaparece de mi vista.', 0),
(@ID, 'esMX', 'Me produces asco, $r. ¿$gUn hombre hecho y derecho:Una mujer hecha y derecha; babeando sobre una pila de baratijas? ¡Qué pena das! Toma tu recompensa y desaparece de mi vista.', 0);
-- 3502 Un trasto de Draenei...
-- https://es.classic.wowhead.com/quest=3502
SET @ID := 3502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien? ¿Draenetista? ¿Te acuerdas?$B$B<Kum\'isha cierra el puño y te da en la cabeza.>$B$B¿Alguna neurona en casa?', 0),
(@ID, 'esMX', '¿Y bien? ¿Draenetista? ¿Te acuerdas?$B$B<Kum\'isha cierra el puño y te da en la cabeza.>$B$B¿Alguna neurona en casa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me produces asco, $r. ¿$gUn hombre hecho y derecha:Una mujer hecha y derecha; babeando sobre una pila de baratijas? ¡Qué pena das! Toma tu recompensa y desaparece de mi vista.$B$B¿Te suena? Debería, porque lo digo mil veces al día.$B$B¡Oh, cómo aborrezco este mundo!', 0),
(@ID, 'esMX', 'Me produces asco, $r. ¿$gUn hombre hecho y derecha:Una mujer hecha y derecha; babeando sobre una pila de baratijas? ¡Qué pena das! Toma tu recompensa y desaparece de mi vista.$B$B¿Te suena? Debería, porque lo digo mil veces al día.$B$B¡Oh, cómo aborrezco este mundo!', 0);
-- 3503 Encuentro con el maestro
-- https://es.classic.wowhead.com/quest=3503
SET @ID := 3503;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hubo un tiempo en que podía pedirles lo que fuera a los que buscaban a mi maestro. Pero ahora, solo tienes que pedirlo y te haré llegar hasta él.$B$BMe molesta pero no cuestiono sus órdenes. Solo puedo disfrutar de hacer bromas sobre tu ridículo atuendo o esa estúpida mirada que luces. Hasta eso me aburre...$B$B¡Hasta esta divagación me aburre! Bueno, ¿quieres ver a mi maestro o no?', 0),
(@ID, 'esMX', 'Hubo un tiempo en que podía pedirles lo que fuera a los que buscaban a mi maestro. Pero ahora, solo tienes que pedirlo y te haré llegar hasta él.$B$BMe molesta pero no cuestiono sus órdenes. Solo puedo disfrutar de hacer bromas sobre tu ridículo atuendo o esa estúpida mirada que luces. Hasta eso me aburre...$B$B¡Hasta esta divagación me aburre! Bueno, ¿quieres ver a mi maestro o no?', 0);
-- 3504 Traición
-- https://es.classic.wowhead.com/quest=3504
SET @ID := 3504;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, así que Belgrom se ha decidido a ayudarnos por fin, ¿eh?$B$BEn este campamento había varios guerreros, pero han muerto todos; esa Rimtori ha acabado con ellos. Ha jugado con Belgrom, apuesto a que lo sedujo. No es cosa mía, esa elfa es tentadora; ayudo a Belgrom porque yo habría hecho lo mismo en su lugar.', 0),
(@ID, 'esMX', 'Vaya, así que Belgrom se ha decidido a ayudarnos por fin, ¿eh?$B$BEn este campamento había varios guerreros, pero han muerto todos; esa Rimtori ha acabado con ellos. Ha jugado con Belgrom, apuesto a que lo sedujo. No es cosa mía, esa elfa es tentadora; ayudo a Belgrom porque yo habría hecho lo mismo en su lugar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Su ejército es fuerte; no ha regresado nadie de las tropas que enviamos. Supongo que muchos han muerto, pero otros habrán huído.$B$BPero ahora que tenemos refuerzos, quizás podamos darle el castigo que se merece por traicionar a Belgrom.$B$B¿Estás con nosotros?', 0),
(@ID, 'esMX', 'Su ejército es fuerte; no ha regresado nadie de las tropas que enviamos. Supongo que muchos han muerto, pero otros habrán huído.$B$BPero ahora que tenemos refuerzos, quizás podamos darle el castigo que se merece por traicionar a Belgrom.$B$B¿Estás con nosotros?', 0);
-- 3505 Traición
-- https://es.classic.wowhead.com/quest=3505
SET @ID := 3505;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El título del libro está estampado en la cubierta de cuero negro con pan de oro: Tomo de invocación de Kaldorei. Al abrir las páginas, puedes ver que el libro es muy antiguo, pero está en excelentes condiciones.$B$BAsumes que el texto es de algún idioma antiguo... ¿quizás Kaldorei?$B$BTus instintos te dicen que deberías volver aquí una vez que hayas terminado de castigar a los elfos de sangre por su traición.', 0),
(@ID, 'esMX', 'El título del libro está estampado en la cubierta de cuero negro con pan de oro: Tomo de invocación de Kaldorei. Al abrir las páginas, puedes ver que el libro es muy antiguo, pero está en excelentes condiciones.$B$BAsumes que el texto es de algún idioma antiguo... ¿quizás Kaldorei?$B$BTus instintos te dicen que deberías volver aquí una vez que hayas terminado de castigar a los elfos de sangre por su traición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo hojeas un poco y encuentras una página marcada por una cinta de seda negra.$B$BEn otra página ves un diagrama. Miras alrededor y ves que los cristales, el círculo e incluso algunos otros componentes del suelo están dispuestos de modo parecido al diagrama.', 0),
(@ID, 'esMX', 'Lo hojeas un poco y encuentras una página marcada por una cinta de seda negra.$B$BEn otra página ves un diagrama. Miras alrededor y ves que los cristales, el círculo e incluso algunos otros componentes del suelo están dispuestos de modo parecido al diagrama.', 0);
-- 3506 Traición
-- https://es.classic.wowhead.com/quest=3506
SET @ID := 3506;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la matanza de traidores elfos de sangre, $n?$B$B¡Tienes que hacer pagar a esa traidora! ¡Merece una muerte lenta y dolorosa por lo que ha hecho!', 0),
(@ID, 'esMX', '¿Cómo va la matanza de traidores elfos de sangre, $n?$B$B¡Tienes que hacer pagar a esa traidora! ¡Merece una muerte lenta y dolorosa por lo que ha hecho!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble!$B$B¡Lo has hecho! ¡Belgrom estará muy complacido! Al fin encontrarán la paz los espíritus de nuestros guerreros. Gracias, $n.', 0),
(@ID, 'esMX', '¡Increíble!$B$B¡Lo has hecho! ¡Belgrom estará muy complacido! Al fin encontrarán la paz los espíritus de nuestros guerreros. Gracias, $n.', 0);
-- 3507 Traición
-- https://es.classic.wowhead.com/quest=3507
SET @ID := 3507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te recuerdo, $c; te envié a Azshara para acabar con la traidora. Parece que han pasado muchas lunas... ¡No me digas que Ag\'tor y los demás también han muerto!', 0),
(@ID, 'esMX', 'Te recuerdo, $c; te envié a Azshara para acabar con la traidora. Parece que han pasado muchas lunas... ¡No me digas que Ag\'tor y los demás también han muerto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Chúpate esa, asquerosa!$B$BGracias de todo corazón, $n. ¡Qué alegría me has dado!$B$BTe daría todo un reino si pudiera, pero tendrás que conformarte con esto.$B$B<Belgrom mira la cabeza de la maga que lo había traicionado.> $B$BQué manera de acabar, con la cabeza en una bolsa... ¡Eso te pasa por traicionarme!', 0),
(@ID, 'esMX', '¡Chúpate esa, asquerosa!$B$BGracias de todo corazón, $n. ¡Qué alegría me has dado!$B$BTe daría todo un reino si pudiera, pero tendrás que conformarte con esto.$B$B<Belgrom mira la cabeza de la maga que lo había traicionado.> $B$BQué manera de acabar, con la cabeza en una bolsa... ¡Eso te pasa por traicionarme!', 0);
-- 3508 Romper el amuleto
-- https://es.classic.wowhead.com/quest=3508
SET @ID := 3508;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes encontrar el nombre de la bestia.', 0),
(@ID, 'esMX', 'Debes encontrar el nombre de la bestia.', 0);
-- 3509 El nombre de la bestia
-- https://es.classic.wowhead.com/quest=3509
SET @ID := 3509;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un señor demoníaco?$B$B<Lord Arkkoroc se ríe.>$B$BQuizás el uno pueda ayudarlo con esta información; pero primero, debes ayudar al uno.', 0),
(@ID, 'esMX', '¿Un señor demoníaco?$B$B<Lord Arkkoroc se ríe.>$B$BQuizás el uno pueda ayudarlo con esta información; pero primero, debes ayudar al uno.', 0);
-- 3510 El nombre de la bestia
-- https://es.classic.wowhead.com/quest=3510
SET @ID := 3510;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lord Arkkoroc se inclina para inspeccionarte.>$B$B¿Dónde están?', 0),
(@ID, 'esMX', '<Lord Arkkoroc se inclina para inspeccionarte.>$B$B¿Dónde están?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Finalmente, $guno digno:una digna; de la sabiduría de Arkkoroc!', 0),
(@ID, 'esMX', '¡Finalmente, $guno digno:una digna; de la sabiduría de Arkkoroc!', 0);
-- 3511 El nombre de la bestia
-- https://es.classic.wowhead.com/quest=3511
SET @ID := 3511;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto! Asombroso, $r. ¿Descubriste el verdadero nombre?', 0),
(@ID, 'esMX', '¡Has vuelto! Asombroso, $r. ¿Descubriste el verdadero nombre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El temple agregará el vitriolo necesario que requerimos para la forja de las armas. Solo queda un paso más en su creación.', 0),
(@ID, 'esMX', 'El temple agregará el vitriolo necesario que requerimos para la forja de las armas. Solo queda un paso más en su creación.', 0);
-- 3512 Como diría Eranikus...
-- https://es.classic.wowhead.com/quest=3512
SET @ID := 3512;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha sido una gran idea de Itharius el enviarte a verme. Dado que Eranikus no está muerto, al menos del modo en el que tú entiendes la muerte, pronto nos hablará él mismo y nos dará algunos consejos. De momento, no puedo ayudarte... al menos, por ahora.$B$BTe cederé mi habilidad para hablar con los muertos pero primero necesito la ayuda de alguien que, al contrario que yo, no sufra los achaques de la edad. Mi más potente dispositivo de augurios me fue arrebatado en contra de mi voluntad y, a menos que lo recupere, no podremos ayudar a Eranikus.', 0),
(@ID, 'esMX', 'Ha sido una gran idea de Itharius el enviarte a verme. Dado que Eranikus no está muerto, al menos del modo en el que tú entiendes la muerte, pronto nos hablará él mismo y nos dará algunos consejos. De momento, no puedo ayudarte... al menos, por ahora.$B$BTe cederé mi habilidad para hablar con los muertos pero primero necesito la ayuda de alguien que, al contrario que yo, no sufra los achaques de la edad. Mi más potente dispositivo de augurios me fue arrebatado en contra de mi voluntad y, a menos que lo recupere, no podremos ayudar a Eranikus.', 0);
-- 3513 El pergamino rúnico
-- https://es.classic.wowhead.com/quest=3513
SET @ID := 3513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes?', 0),
(@ID, 'esMX', '¿Qué tienes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ahora ... ¿Dónde encontraste esto?', 0),
(@ID, 'esMX', 'Bueno, ahora ... ¿Dónde encontraste esto?', 0);
-- 3514 La presencia de la Horda
-- https://es.classic.wowhead.com/quest=3514
SET @ID := 3514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir que la Alianza entre en nuestra tierra, $n. Hazlo saber.', 0),
(@ID, 'esMX', 'No podemos permitir que la Alianza entre en nuestra tierra, $n. Hazlo saber.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres $gduro:dura;! Librar la Guarida de Rynthariel es un paso importante, $n. Tardarán en reagruparse, por lo que podemos contar con menos corredores de la Alianza en Los Baldíos. Se lo pensarán de nuevo antes de enviar otro.$B$BGracias.', 0),
(@ID, 'esMX', '¡Eres $gduro:dura;! Librar la Guarida de Rynthariel es un paso importante, $n. Tardarán en reagruparse, por lo que podemos contar con menos corredores de la Alianza en Los Baldíos. Se lo pensarán de nuevo antes de enviar otro.$B$BGracias.', 0);
-- 3517 El robo de conocimientos
-- https://es.classic.wowhead.com/quest=3517
SET @ID := 3517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las tablillas que te he pedido que reúnas deberían aportar algo de cobre a las partes apropiadas. Te diré a quién hay que entregárselas cuando las encuentres. Pero no soy tonto... tendrás tu parte cuando tenga la prueba de que las has entregado.$B$BAsí que manos a la obra, no tenemos todo el día. Podría tener que encontrar a otro para que me ayude.', 0),
(@ID, 'esMX', 'Las tablillas que te he pedido que reúnas deberían aportar algo de cobre a las partes apropiadas. Te diré a quién hay que entregárselas cuando las encuentres. Pero no soy tonto... tendrás tu parte cuando tenga la prueba de que las has entregado.$B$BAsí que manos a la obra, no tenemos todo el día. Podría tener que encontrar a otro para que me ayude.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n, y además en buen estado. Deberíamos conseguir un buen precio de todas las partes interesadas.$B$BNo nos entretengamos aquí más de lo necesario. Hay un buen dinero que ganar.', 0),
(@ID, 'esMX', 'Perfecto, $n, y además en buen estado. Deberíamos conseguir un buen precio de todas las partes interesadas.$B$BNo nos entretengamos aquí más de lo necesario. Hay un buen dinero que ganar.', 0);
