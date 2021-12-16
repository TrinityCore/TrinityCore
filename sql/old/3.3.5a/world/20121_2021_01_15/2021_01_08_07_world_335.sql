-- 1478 Las invocaciones de Halgar
-- https://es.classic.wowhead.com/quest=1478
SET @ID := 1478;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, veo que Ageron logró encontrarte, $n. Mejor que no pierdas el tiempo con conversaciones triviales y cortesías y concéntrate en tu capacitación. Aún queda mucho por aprender.', 0),
(@ID, 'esMX', 'Bien, veo que Ageron logró encontrarte, $n. Mejor que no pierdas el tiempo con conversaciones triviales y cortesías y concéntrate en tu capacitación. Aún queda mucho por aprender.', 0);
-- 1479 La Rama de los Eternos
-- https://es.classic.wowhead.com/quest=1479
SET @ID := 1479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, era más genial de lo que imaginaba, ¡la Rama de los Eternos! No pensé que fuera tan grande, ¡pero lo es! ¿Viste el pájaro encima también? ¡Me pregunto cómo consiguieron que las ramas crecieran así!$B$BGracias por llevarme a Darnassus, $n. ¡Eres increíble!', 0),
(@ID, 'esMX', 'Vaya, era más genial de lo que imaginaba, ¡la Rama de los Eternos! No pensé que fuera tan grande, ¡pero lo es! ¿Viste el pájaro encima también? ¡Me pregunto cómo consiguieron que las ramas crecieran así!$B$BGracias por llevarme a Darnassus, $n. ¡Eres increíble!', 0);
-- 1480 El corruptor
-- https://es.classic.wowhead.com/quest=1480
SET @ID := 1480;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Filo Ardiente empieza a percatarse de cuán vulnerables son. Su magia es ridícula, carecen de fuerza.$B$BSu poder proviene de aquellos a quienes sirven, pero no lo comprenden en absoluto.', 0),
(@ID, 'esMX', 'Filo Ardiente empieza a percatarse de cuán vulnerables son. Su magia es ridícula, carecen de fuerza.$B$BSu poder proviene de aquellos a quienes sirven, pero no lo comprenden en absoluto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas runas son muy, muy antiguas, $n. Se parecen un poco a las del Eredun, pero con grandes diferencias. Esto parece un contrato... Sí, este símbolo es la firma del demonio: Lord Azrethoc.', 0),
(@ID, 'esMX', 'Estas runas son muy, muy antiguas, $n. Se parecen un poco a las del Eredun, pero con grandes diferencias. Esto parece un contrato... Sí, este símbolo es la firma del demonio: Lord Azrethoc.', 0);
-- 1481 El corruptor
-- https://es.classic.wowhead.com/quest=1481
SET @ID := 1481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tráeme la cabellera adecuada, $c. Podríamos morir si los ingredientes no son correctos. Es posible que el señor demoníaco tenga hechizos ocultos en la manga.$B$BYa he sufrido bastante en esta vida.', 0),
(@ID, 'esMX', 'Tráeme la cabellera adecuada, $c. Podríamos morir si los ingredientes no son correctos. Es posible que el señor demoníaco tenga hechizos ocultos en la manga.$B$BYa he sufrido bastante en esta vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los acechasombras no pudieron matarte, $c. Impresionante.$B$BEsta cabellera me vendrá de perlas para el hechizo. Mientras estabas fuera, conseguí recolectar algunos de los demás componentes necesarios para el hechizo.$B$BLo tengo casi todo listo. Solo necesito un punto de concentración, algo para proyectar una imagen del señor demoníaco y de su paradero.', 0),
(@ID, 'esMX', 'Los acechasombras no pudieron matarte, $c. Impresionante.$B$BEsta cabellera me vendrá de perlas para el hechizo. Mientras estabas fuera, conseguí recolectar algunos de los demás componentes necesarios para el hechizo.$B$BLo tengo casi todo listo. Solo necesito un punto de concentración, algo para proyectar una imagen del señor demoníaco y de su paradero.', 0);
-- 1482 El corruptor
-- https://es.classic.wowhead.com/quest=1482
SET @ID := 1482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame el cristal del oráculo, $c. Si acabamos con Lord Azrethoc nos ganaremos el favor del Jefe de Guerra; nos interesa colaborar.', 0),
(@ID, 'esMX', 'Dame el cristal del oráculo, $c. Si acabamos con Lord Azrethoc nos ganaremos el favor del Jefe de Guerra; nos interesa colaborar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un cristal del oráculo precioso, sin mácula... Qué belleza.$B$BEmpecemos: debemos encontrar y eliminar al señor demoníaco.$B$BApártate, $c; voy a concentrarme para descubrir su paradero.', 0),
(@ID, 'esMX', 'Un cristal del oráculo precioso, sin mácula... Qué belleza.$B$BEmpecemos: debemos encontrar y eliminar al señor demoníaco.$B$BApártate, $c; voy a concentrarme para descubrir su paradero.', 0);
-- 1484 El corruptor
-- https://es.classic.wowhead.com/quest=1484
SET @ID := 1484;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He visto lo ocurrido entre Maurin y el señor demoníaco. Parece tener más poder que mi brujo. Iría yo mismo, pero deshonraría a mi clan si abandonara mis deberes para ir a enfrentarme con un enemigo por mi propio honor.', 0),
(@ID, 'esMX', 'He visto lo ocurrido entre Maurin y el señor demoníaco. Parece tener más poder que mi brujo. Iría yo mismo, pero deshonraría a mi clan si abandonara mis deberes para ir a enfrentarme con un enemigo por mi propio honor.', 0);
-- 1485 Familiares viles
-- https://es.classic.wowhead.com/quest=1485
SET @ID := 1485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es importante que puedas controlar a los seres que convocas a través de tu magia. Hay pocos interesados en aprender los caminos $gdel:de la; $c pero me arriesgaría a matarte enseñándote algo antes de que estés $glisto:lista;.', 0),
(@ID, 'esMX', 'Es importante que puedas controlar a los seres que convocas a través de tu magia. Hay pocos interesados en aprender los caminos $gdel:de la; $c pero me arriesgaría a matarte enseñándote algo antes de que estés $glisto:lista;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A lo largo de tu entrenamiento como $c, aprenderás a invocar seres de muchos tipos. Puede que algunos no lo parezcan, pero todos son herramientas útiles.$B$BNo te dejes engañar por el pequeño tamaño del diablillo. Como sin duda habrás notado, es un adversario formidable.', 0),
(@ID, 'esMX', 'A lo largo de tu entrenamiento como $c, aprenderás a invocar seres de muchos tipos. Puede que algunos no lo parezcan, pero todos son herramientas útiles.$B$BNo te dejes engañar por el pequeño tamaño del diablillo. Como sin duda habrás notado, es un adversario formidable.', 0);
-- 1486 Pellejos descarriados
-- https://es.classic.wowhead.com/quest=1486
SET @ID := 1486;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo mucho interés en examinar los cueros de las criaturas descarriadas que infestaban las cuevas. ¿Has podido recoger alguno, $c?', 0),
(@ID, 'esMX', 'Tengo mucho interés en examinar los cueros de las criaturas descarriadas que infestaban las cuevas. ¿Has podido recoger alguno, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus esfuerzos reuniendo los cueros no serán olvidados, $n.$B$BGracias por tu entrega y dedicación.', 0),
(@ID, 'esMX', 'Tus esfuerzos reuniendo los cueros no serán olvidados, $n.$B$BGracias por tu entrega y dedicación.', 0);
-- 1487 Erradicación de descarriados
-- https://es.classic.wowhead.com/quest=1487
SET @ID := 1487;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, nosotros, los Discípulos de Naralex, necesitamos tu ayuda. Nuestro número está disminuyendo con nuestro maestro atrapado en su retorcida pesadilla. No tenemos las fuerzas necesarias para lidiar con las criaturas corruptas que ahora acechan estas cavernas.$B$B¡Te lo ruego, entra en las cuevas y libra la guerra contra las criaturas desviadas!', 0),
(@ID, 'esMX', '$n, nosotros, los Discípulos de Naralex, necesitamos tu ayuda. Nuestro número está disminuyendo con nuestro maestro atrapado en su retorcida pesadilla. No tenemos las fuerzas necesarias para lidiar con las criaturas corruptas que ahora acechan estas cavernas.$B$B¡Te lo ruego, entra en las cuevas y libra la guerra contra las criaturas desviadas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como discípulo de Naralex no puedo más que elogiar tu valor, $n.$B$BTu ayuda en el asalto de las cavernas es el primer paso en nuestra larga lucha por restaurar Los Baldíos.$B$BGracias y mucha prosperidad.', 0),
(@ID, 'esMX', 'Como discípulo de Naralex no puedo más que elogiar tu valor, $n.$B$BTu ayuda en el asalto de las cavernas es el primer paso en nuestra larga lucha por restaurar Los Baldíos.$B$BGracias y mucha prosperidad.', 0);
-- 1488 El corruptor
-- https://es.classic.wowhead.com/quest=1488
SET @ID := 1488;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gloria a la Horda y muerte a nuestros enemigos, $n!$B$BLos demonios en Desolace representan una amenaza mayor que nunca. Mi esperanza de volver con el Jefe de Guerra disminuye a medida que aparecen más y más criaturas inmundas.$B$BA veces desearía que solo tuviéramos que lidiar con los centauros.', 0),
(@ID, 'esMX', '¡Gloria a la Horda y muerte a nuestros enemigos, $n!$B$BLos demonios en Desolace representan una amenaza mayor que nunca. Mi esperanza de volver con el Jefe de Guerra disminuye a medida que aparecen más y más criaturas inmundas.$B$BA veces desearía que solo tuviéramos que lidiar con los centauros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Disfruta de tu gran victoria, $n. Gracias a ti, el futuro no parece tan amenazador como creía.$B$BEliminaremos a los demonios, Filo Ardiente caerá y nosotros volveremos a tener un hogar.', 0),
(@ID, 'esMX', 'Disfruta de tu gran victoria, $n. Gracias a ti, el futuro no parece tan amenazador como creía.$B$BEliminaremos a los demonios, Filo Ardiente caerá y nosotros volveremos a tener un hogar.', 0);
-- 1489 Hamuul Runatótem
-- https://es.classic.wowhead.com/quest=1489
SET @ID := 1489;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus amos son tontos al enviarte aquí, ¡nunca más seré un esclavo de la Plaga!', 0),
(@ID, 'esMX', 'Tus amos son tontos al enviarte aquí, ¡nunca más seré un esclavo de la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis más cordiales saludos, $n. Eres $gbienvenido:bienvenida; entre nosotros. Te convendría hacer acopio de todas tus fuerzas... la tarea que te espera... es extremadamente ardua.', 0),
(@ID, 'esMX', 'Mis más cordiales saludos, $n. Eres $gbienvenido:bienvenida; entre nosotros. Te convendría hacer acopio de todas tus fuerzas... la tarea que te espera... es extremadamente ardua.', 0);
-- 1490 Nara Ferocrín
-- https://es.classic.wowhead.com/quest=1490
SET @ID := 1490;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, es cierto. Ya conocía a los druidas de las Cuevas de los Lamentos y he visto sus rostros retorcidos y demacrados. Conozco sus crímenes y sus planes.$B$BDebes detenerlos, $n.', 0),
(@ID, 'esMX', 'Sí, es cierto. Ya conocía a los druidas de las Cuevas de los Lamentos y he visto sus rostros retorcidos y demacrados. Conozco sus crímenes y sus planes.$B$BDebes detenerlos, $n.', 0);
-- 1492 Maestro de muelles Vertipeluca
-- https://es.classic.wowhead.com/quest=1492
SET @ID := 1492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Buscas pasaje en el barco siguiente o quieres enviar algo a bordo?', 0),
(@ID, 'esMX', '¿Buscas pasaje en el barco siguiente o quieres enviar algo a bordo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una caja lo suficientemente pequeña. Sí, debería encontrar un hueco a bordo para esto. Zarpa con la próxima marea, suficientemente pronto, ¿verdad? Fantástico. Permite que lo registre en mi libro de contabilidad.$B$B¡Ya está todo! Que tengas un buen día, $c.', 0),
(@ID, 'esMX', 'Una caja lo suficientemente pequeña. Sí, debería encontrar un hueco a bordo para esto. Zarpa con la próxima marea, suficientemente pronto, ¿verdad? Fantástico. Permite que lo registre en mi libro de contabilidad.$B$B¡Ya está todo! Que tengas un buen día, $c.', 0);
-- 1498 Camino de defensa
-- https://es.classic.wowhead.com/quest=1498
SET @ID := 1498;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las escamas, $n? Si no puedes resistir los ataques de los truenagartos, mi instrucción no te servirá de nada.', 0),
(@ID, 'esMX', '¿Tienes las escamas, $n? Si no puedes resistir los ataques de los truenagartos, mi instrucción no te servirá de nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah. Veo que has derrotado a los truenagartos, una buena prueba de tu dureza. Ahora te enseñaré como pueden combinarse una piel resistente y unos movimientos diestros para dar forma a un muro de defensa impenetrable.$B$BAprende bien la lección, $n, y prepárate para tu futura instrucción.', 0),
(@ID, 'esMX', 'Ah. Veo que has derrotado a los truenagartos, una buena prueba de tu dureza. Ahora te enseñaré como pueden combinarse una piel resistente y unos movimientos diestros para dar forma a un muro de defensa impenetrable.$B$BAprende bien la lección, $n, y prepárate para tu futura instrucción.', 0);
-- 1499 Familiares viles
-- https://es.classic.wowhead.com/quest=1499
SET @ID := 1499;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n.$B$BAunque los familiares viles eran meras mascotas de los poderes más oscuros dentro del Filo Ardiente, tu éxito contra ellos predice grandes hazañas en el futuro.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n.$B$BAunque los familiares viles eran meras mascotas de los poderes más oscuros dentro del Filo Ardiente, tu éxito contra ellos predice grandes hazañas en el futuro.', 0);
-- 1501 Criatura Abisal
-- https://es.classic.wowhead.com/quest=1501
SET @ID := 1501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la tablilla de Vergua, $n? No te hablaré hasta que la traigas.', 0),
(@ID, 'esMX', '¿Traes la tablilla de Vergua, $n? No te hablaré hasta que la traigas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que causaras bajas en Filo Ardiente cuando fuiste a buscar esto.$B$BEstán molestando mucho al Jefe de Guerra y a los brujos en general.', 0),
(@ID, 'esMX', 'Espero que causaras bajas en Filo Ardiente cuando fuiste a buscar esto.$B$BEstán molestando mucho al Jefe de Guerra y a los brujos en general.', 0);
-- 1502 Thun'grim Vistafuego
-- https://es.classic.wowhead.com/quest=1502
SET @ID := 1502;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis ojos se secaron hace mucho tiempo por mirar fijamente la llama de la forja, pero hay cosas que aún puedo ver. Puedo ver que quieres algo.$B$BY si viniste hasta aquí creo saber qué deseas.', 0),
(@ID, 'esMX', 'Mis ojos se secaron hace mucho tiempo por mirar fijamente la llama de la forja, pero hay cosas que aún puedo ver. Puedo ver que quieres algo.$B$BY si viniste hasta aquí creo saber qué deseas.', 0);
-- 1503 Acero fundido
-- https://es.classic.wowhead.com/quest=1503
SET @ID := 1503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis lingotes de acero?', 0),
(@ID, 'esMX', '¿Tienes mis lingotes de acero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los encontraste! Están todos los lingotes, no me sorprende. No creo que los Crines de Acero supieran qué hacer con un acero como este.$B$BGracias, $n. Aquí tienes tu recompensa. Espero que te sea útil.', 0),
(@ID, 'esMX', '¡Los encontraste! Están todos los lingotes, no me sorprende. No creo que los Crines de Acero supieran qué hacer con un acero como este.$B$BGracias, $n. Aquí tienes tu recompensa. Espero que te sea útil.', 0);
-- 1504 El vínculo
-- https://es.classic.wowhead.com/quest=1504
SET @ID := 1504;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los abisarios tienen mucho poder. Recuerdo cuando empecé como tú ahora, $n. Con el tiempo mi abisario va luchando menos conmigo, pero creo que espera que baje la guardia.$B$BNo lo olvides.', 0),
(@ID, 'esMX', 'Los abisarios tienen mucho poder. Recuerdo cuando empecé como tú ahora, $n. Con el tiempo mi abisario va luchando menos conmigo, pero creo que espera que baje la guardia.$B$BNo lo olvides.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Voy a enseñarte a invocar un abisario parecido al que acabas de derrotar.$B$BHas de saber que tenemos grandes esperanzas puestas en ti y hasta ahora no nos has decepcionado.$B$BPero no te confíes; las tareas que te esperan harán que esto te parezca un paseo por el bosque.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Voy a enseñarte a invocar un abisario parecido al que acabas de derrotar.$B$BHas de saber que tenemos grandes esperanzas puestas en ti y hasta ahora no nos has decepcionado.$B$BPero no te confíes; las tareas que te esperan harán que esto te parezca un paseo por el bosque.', 0);
-- 1505 Uzzek, el veterano
-- https://es.classic.wowhead.com/quest=1505
SET @ID := 1505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, joven. Has venido en busca de instrucción, ¿verdad?', 0),
(@ID, 'esMX', 'Hola, joven. Has venido en busca de instrucción, ¿verdad?', 0);
-- 1506 Las invocaciones de Gan'rul
-- https://es.classic.wowhead.com/quest=1506
SET @ID := 1506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno. Tenía miedo de que Ophek no te alcanzara.$B$BEs hora de que mejores tu entrenamiento de brujo. Cualquier asunto que tengas actualmente tendrá que esperar.$B$B¿Confío en que no habrá ningún problema con esto?', 0),
(@ID, 'esMX', 'Bueno. Tenía miedo de que Ophek no te alcanzara.$B$BEs hora de que mejores tu entrenamiento de brujo. Cualquier asunto que tengas actualmente tendrá que esperar.$B$B¿Confío en que no habrá ningún problema con esto?', 0);
-- 1507 Devoradora de almas
-- https://es.classic.wowhead.com/quest=1507
SET @ID := 1507;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... $n. Todavía eres $gnuevo:nueva; en tu camino, pero siento la posibilidad de grandeza en ti.$B$BNaciste con dones, $n. Procura que no se desperdicien.', 0),
(@ID, 'esMX', 'Mmm... $n. Todavía eres $gnuevo:nueva; en tu camino, pero siento la posibilidad de grandeza en ti.$B$BNaciste con dones, $n. Procura que no se desperdicien.', 0);
-- 1508 Cazul, el ciego
-- https://es.classic.wowhead.com/quest=1508
SET @ID := 1508;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido con noticias de Dogran? Debía haber regresado hace días y no he sabido nada...', 0),
(@ID, 'esMX', '¿Has venido con noticias de Dogran? Debía haber regresado hace días y no he sabido nada...', 0);
-- 1509 Noticias de Dogran
-- https://es.classic.wowhead.com/quest=1509
SET @ID := 1509;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Zankaja? Ese es el compañero de Dogran, ¿verdad?$B$BSí, he escuchado de él, pero no es el tipo de noticias que debamos dejar que le lleguen...$B$BNo, no está muerto. Pero está herido y prisionero de los jabaespines.', 0),
(@ID, 'esMX', '¿Zankaja? Ese es el compañero de Dogran, ¿verdad?$B$BSí, he escuchado de él, pero no es el tipo de noticias que debamos dejar que le lleguen...$B$BNo, no está muerto. Pero está herido y prisionero de los jabaespines.', 0);
-- 1510 Noticias de Dogran
-- https://es.classic.wowhead.com/quest=1510
SET @ID := 1510;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gOtro:Otra; $r, ¿eh? Espero que no hayas venido por el otro. No lo logró. Esos goblins lo hicieron bien.$B$BDijo que necesitaba un trago curativo, pero no mucho más.', 0),
(@ID, 'esMX', '$gOtro:Otra; $r, ¿eh? Espero que no hayas venido por el otro. No lo logró. Esos goblins lo hicieron bien.$B$BDijo que necesitaba un trago curativo, pero no mucho más.', 0);
-- 1511 Jarabe de Ken'zigla
-- https://es.classic.wowhead.com/quest=1511
SET @ID := 1511;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Si, que es eso?', 0),
(@ID, 'esMX', '¿Si, que es eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¡ya era hora! Dogran ha estado muriendo ahí afuera, esperando esto.$B$BNecesitamos comunicárselo de inmediato, pero la mayoría de los brutos apostados aquí están en una misión de búsqueda de alimentos.', 0),
(@ID, 'esMX', 'Bueno, ¡ya era hora! Dogran ha estado muriendo ahí afuera, esperando esto.$B$BNecesitamos comunicárselo de inmediato, pero la mayoría de los brutos apostados aquí están en una misión de búsqueda de alimentos.', 0);
-- 1512 Un regalo de amor
-- https://es.classic.wowhead.com/quest=1512
SET @ID := 1512;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¿Te atreves a enfrentarte a una súcubo?', 0),
(@ID, 'esMX', 'Has vuelto. ¿Te atreves a enfrentarte a una súcubo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si dices que con esto basta, te creo, $n. Pero voy a limpiarlo un poco, así llamará más la atención a la súcubo.', 0),
(@ID, 'esMX', 'Si dices que con esto basta, te creo, $n. Pero voy a limpiarlo un poco, así llamará más la atención a la súcubo.', 0);
-- 1513 El vínculo
-- https://es.classic.wowhead.com/quest=1513
SET @ID := 1513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando miro a una súcubo, mi corazón comienza a latir ... Pero al mismo tiempo, casi puedo sentir el reflujo de mi alma, alejándose como las mareas.$B$BTen cuidado, amigo mío.', 0),
(@ID, 'esMX', 'Cuando miro a una súcubo, mi corazón comienza a latir ... Pero al mismo tiempo, casi puedo sentir el reflujo de mi alma, alejándose como las mareas.$B$BTen cuidado, amigo mío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Éxito! No esperaba menos de mi $galumno:alumna; estrella.$B$BHas demostrado tu valía y con mucho gusto te mostraré el método para convocar a tu súcubo sometida. Vete ahora, tienes mucho que aprender, y la próxima vez que te vea, espero que hayas encontrado un verdadero dominio sobre tu súcubo.$B$BDeje el dolor de Dogran y Zankaja a aquellos de nosotros que tenemos más años, pero recuérdelo y úsalo como protección contra las artimañas del poder oscuro que has aprendido a invocar hoy.', 0),
(@ID, 'esMX', '¡Éxito! No esperaba menos de mi $galumno:alumna; estrella.$B$BHas demostrado tu valía y con mucho gusto te mostraré el método para convocar a tu súcubo sometida. Vete ahora, tienes mucho que aprender, y la próxima vez que te vea, espero que hayas encontrado un verdadero dominio sobre tu súcubo.$B$BDeje el dolor de Dogran y Zankaja a aquellos de nosotros que tenemos más años, pero recuérdelo y úsalo como protección contra las artimañas del poder oscuro que has aprendido a invocar hoy.', 0);
-- 1514 Flor del viento corrupta
-- https://es.classic.wowhead.com/quest=1514
SET @ID := 1514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor de viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(@ID, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor de viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aplicas dos bálsamos de plantas Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(@ID, 'esMX', 'Aplicas dos bálsamos de plantas Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0);
-- 1515 El cautiverio de Dogran
-- https://es.classic.wowhead.com/quest=1515
SET @ID := 1515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Urrrghhhh...', 0),
(@ID, 'esMX', 'Urrrghhhh...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Brebaje de mal sabor...$B$BPuedo sentir la fuerza en mí ahora, lo suficiente como para alejarme cojeando... Pero mi pierna, la habré perdido por el resto de mi vida. Mi brazo también.', 0),
(@ID, 'esMX', 'Brebaje de mal sabor...$B$BPuedo sentir la fuerza en mí ahora, lo suficiente como para alejarme cojeando... Pero mi pierna, la habré perdido por el resto de mi vida. Mi brazo también.', 0);
-- 1516 La llamada de la tierra
-- https://es.classic.wowhead.com/quest=1516
SET @ID := 1516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La paciencia es la mayor virtud de la tierra. La tierra es testigo del ciclo de todas las cosas: las montañas que se convierten en desiertos, los ríos convirtiéndose en cañones. La tierra es el más testarudo y sabio de todos los elementos y no tolera la impaciencia.$B$BLa tierra te reclama porque se acerca un tiempo de conflictos. Cuando vuelvas a mí triunfante, estarás mucho más cerca de la realización.$B$BOtros envidiarán tu sabiduría y te odiarán por su ignorancia.', 0),
(@ID, 'esMX', 'La paciencia es la mayor virtud de la tierra. La tierra es testigo del ciclo de todas las cosas: las montañas que se convierten en desiertos, los ríos convirtiéndose en cañones. La tierra es el más testarudo y sabio de todos los elementos y no tolera la impaciencia.$B$BLa tierra te reclama porque se acerca un tiempo de conflictos. Cuando vuelvas a mí triunfante, estarás mucho más cerca de la realización.$B$BOtros envidiarán tu sabiduría y te odiarán por su ignorancia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Tu éxito demuestra que estás preparado.$B$BDe entre todos los elementos, la tierra representa el cimiento de todas las cosas. Es tu poder, tu fuerza y tu paciencia. Como el resto de elementos, la tierra puede ser inconstante. La tierra es el fundamento de la vida y si sigues sus leyes crecerá tu sabiduría. Nunca olvides los secretos que la tierra comparte contigo.$B$BTe haré una sapta y, al aceptarla, completarás tu senda.', 0),
(@ID, 'esMX', 'Excelente. Tu éxito demuestra que estás preparado.$B$BDe entre todos los elementos, la tierra representa el cimiento de todas las cosas. Es tu poder, tu fuerza y tu paciencia. Como el resto de elementos, la tierra puede ser inconstante. La tierra es el fundamento de la vida y si sigues sus leyes crecerá tu sabiduría. Nunca olvides los secretos que la tierra comparte contigo.$B$BTe haré una sapta y, al aceptarla, completarás tu senda.', 0);
-- 1517, 1520
-- https://es.classic.wowhead.com/quest=1517
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(1517, 1520) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1517, 'esES', 'Ah... $n... la tierra se complace de tenerte aquí.$B$B$gComprometido:Comprometida; en cuerpo y espíritu, avanzarás sabiendo que las montañas son tu fuerza, las llanuras tu paciencia y el mundo tu esencia.$B$BLa humildad ante la tierra es todo lo que necesitas para pasar este rito. Pero los otros no son tan pasivos. Pueden ser caóticos y violentos... tal es la naturaleza de los elementos, naturalezas duales en eterna oposición. Debes aprender estas cosas en toda su complejidad.', 0),
(1520, 'esES', 'Ah... $n... la tierra se complace de tenerte aquí.$B$B$gComprometido:Comprometida; en cuerpo y espíritu, avanzarás sabiendo que las montañas son tu fuerza, las llanuras tu paciencia y el mundo tu esencia.$B$BLa humildad ante la tierra es todo lo que necesitas para pasar este rito. Pero los otros no son tan pasivos. Pueden ser caóticos y violentos... tal es la naturaleza de los elementos, naturalezas duales en eterna oposición. Debes aprender estas cosas en toda su complejidad.', 0),
(1517, 'esMX', 'Ah... $n... la tierra se complace de tenerte aquí.$B$B$gComprometido:Comprometida; en cuerpo y espíritu, avanzarás sabiendo que las montañas son tu fuerza, las llanuras tu paciencia y el mundo tu esencia.$B$BLa humildad ante la tierra es todo lo que necesitas para pasar este rito. Pero los otros no son tan pasivos. Pueden ser caóticos y violentos... tal es la naturaleza de los elementos, naturalezas duales en eterna oposición. Debes aprender estas cosas en toda su complejidad.', 0),
(1520, 'esMX', 'Ah... $n... la tierra se complace de tenerte aquí.$B$B$gComprometido:Comprometida; en cuerpo y espíritu, avanzarás sabiendo que las montañas son tu fuerza, las llanuras tu paciencia y el mundo tu esencia.$B$BLa humildad ante la tierra es todo lo que necesitas para pasar este rito. Pero los otros no son tan pasivos. Pueden ser caóticos y violentos... tal es la naturaleza de los elementos, naturalezas duales en eterna oposición. Debes aprender estas cosas en toda su complejidad.', 0);
