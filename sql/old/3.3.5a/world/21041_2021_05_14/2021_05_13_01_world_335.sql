-- 9588 Aciagas nuevas
-- https://es.wowhead.com/quest=9588
SET @ID := 9588;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué carta tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué carta tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está firmado por Illidan, dices? Déjame ver eso.$B$B<Nazgrel lee la carta y luego otra vez, pensando un momento antes de continuar.>$B$BEsta noticia que traes es realmente preocupante. Sabiendo esto, debemos acelerar nuestros planes contra la Ciudadela del Fuego Infernal y El Horno de Sangre. Debido a que has demostrado que puedes hacer el trabajo, ¡quiero que dirijas esos planes!$B$BEl centurión Caza\'rez te dará tu próxima misión, aunque sospecho que será mucho más letal que la primera.$B$B¡Lok\'tar ogar, $n!', 0),
(@ID, 'esMX', '¿Está firmado por Illidan, dices? Déjame ver eso.$B$B<Nazgrel lee la carta y luego otra vez, pensando un momento antes de continuar.>$B$BEsta noticia que traes es realmente preocupante. Sabiendo esto, debemos acelerar nuestros planes contra la Ciudadela del Fuego Infernal y El Horno de Sangre. Debido a que has demostrado que puedes hacer el trabajo, ¡quiero que dirijas esos planes!$B$BEl centurión Caza\'rez te dará tu próxima misión, aunque sospecho que será mucho más letal que la primera.$B$B¡Lok\'tar ogar, $n!', 0);
-- 9589 La sangre es vida
-- https://es.wowhead.com/quest=9589
SET @ID := 9589;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esa sangre, cariño? Podría ser algo importante si te pedimos que lo obtengas, ¿sabes?', 0),
(@ID, 'esMX', '¿Tienes esa sangre, cariño? Podría ser algo importante si te pedimos que lo obtengas, ¿sabes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fuera de pie! A partir de ahora $T Civil : Civil; $n, ¡eres mi persona favorita en los lamentables restos de este lamentable planeta!$B$BEstoy seguro de que las cabezas de huevo se van a mojar cuando les entregue esa sangre para que la estudien. Quién sabe, tal vez encontremos un nuevo arma en la lucha contra esos malditos orcos viles.', 0),
(@ID, 'esMX', '¡Fuera de pie! A partir de ahora $T Civil : Civil; $n, ¡eres mi persona favorita en los lamentables restos de este lamentable planeta!$B$BEstoy seguro de que las cabezas de huevo se van a mojar cuando les entregue esa sangre para que la estudien. Quién sabe, tal vez encontremos un nuevo arma en la lucha contra esos malditos orcos viles.', 0);
-- 9590 La sangre es vida
-- https://es.wowhead.com/quest=9590
SET @ID := 9590;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Seguro que has recogido toda la sangre tan rápido?', 0),
(@ID, 'esMX', '¿Seguro que has recogido toda la sangre tan rápido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy impresionado con tus habilidades, $n. No una, sino dos veces te has infiltrado en Ciudadela del Fuego Infernal por nosotros y has logrado lo que se te pidió.$B$BMe encargaré de que esta sangre se entregue a aquellos que puedan desentrañar sus misterios. Quién sabe, tal vez podamos encontrar una manera de revertir el proceso.', 0),
(@ID, 'esMX', 'Estoy impresionado con tus habilidades, $n. No una, sino dos veces te has infiltrado en Ciudadela del Fuego Infernal por nosotros y has logrado lo que se te pidió.$B$BMe encargaré de que esta sangre se entregue a aquellos que puedan desentrañar sus misterios. Quién sabe, tal vez podamos encontrar una manera de revertir el proceso.', 0);
-- 9594 Signos de la Legión
-- https://es.wowhead.com/quest=9594
SET @ID := 9594;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho bien en traerme esto, $n. Este es, sin duda, un fragmento de armadura de un guardia vil.$B$BEntonces, es como temí. El sátiro Nazzivus está renovando sus contactos con la Legión Ardiente. Si no los detenemos, los sátiros y sus aliados demoníacos nos invadirán. Notificaré al Presagista Mikolaas de inmediato.', 0),
(@ID, 'esMX', 'Has hecho bien en traerme esto, $n. Este es, sin duda, un fragmento de armadura de un guardia vil.$B$BEntonces, es como temí. El sátiro Nazzivus está renovando sus contactos con la Legión Ardiente. Si no los detenemos, los sátiros y sus aliados demoníacos nos invadirán. Notificaré al Presagista Mikolaas de inmediato.', 0);
-- 9595 Control
-- https://es.wowhead.com/quest=9595
SET @ID := 9595;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has enfrentado a tus pesadillas?', 0),
(@ID, 'esMX', '¿Te has enfrentado a tus pesadillas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con cada hechizo debes armarte de valor contra su atractivo seductor, utilizándolo solo cuando sea necesario para el bien. Con suerte, el espectro te permitió ver en qué podrías convertirte si te volvieras $gdescuidado: un descerebrado esclavo:descuidada: una descerebrada esclava; de la magia.', 0),
(@ID, 'esMX', 'Con cada hechizo debes armarte de valor contra su atractivo seductor, utilizándolo solo cuando sea necesario para el bien. Con suerte, el espectro te permitió ver en qué podrías convertirte si te volvieras $gdescuidado: un descerebrado esclavo:descuidada: una descerebrada esclava; de la magia.', 0);
-- 9598 Redención
-- https://es.wowhead.com/quest=9598
SET @ID := 9598;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has pasado tiempo leyendo el libro, espero.$B$BEntonces debes estar $gpreparado:preparada; para hacer la prueba. Siempre hay tareas que hacer tras la caída del Exodar en estas nuevas tierras: actos de compasión y comprensión... personas que necesitan ayuda... criaturas que matar...$B$BAl demostrar que tiene la paciencia para ayudar a los demás, especialmente a los menos afortunados, demuestras que eres $gun:una; sirviente de la Luz y de su sano juicio.', 0),
(@ID, 'esMX', 'Has pasado tiempo leyendo el libro, espero.$B$BEntonces debes estar $gpreparado:preparada; para hacer la prueba. Siempre hay tareas que hacer tras la caída del Exodar en estas nuevas tierras: actos de compasión y comprensión... personas que necesitan ayuda... criaturas que matar...$B$BAl demostrar que tiene la paciencia para ayudar a los demás, especialmente a los menos afortunados, demuestras que eres $gun:una; sirviente de la Luz y de su sano juicio.', 0);
-- 9599 Reflejar la luz
-- https://es.wowhead.com/quest=9599
SET @ID := 9599;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias $n! Me alegro de que el joven chamán Furbolg esté bien.$B$B¡Realmente estás $gbendecido:bendecida; con la Luz! ¡Por lo tanto, lo usarás para devolver la luz a todos!', 0),
(@ID, 'esMX', '¡Gracias $n! Me alegro de que el joven chamán Furbolg esté bien.$B$B¡Realmente estás $gbendecido:bendecida; con la Luz! ¡Por lo tanto, lo usarás para devolver la luz a todos!', 0);
-- 9600 Redención
-- https://es.wowhead.com/quest=9600
SET @ID := 9600;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Chamán fúrbolg joven resucitado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toda vida vale la pena salvarla, si no se nos opone. Solo nuestros enemigos deben descansar permanentemente.', 0),
(@ID, 'esMX', 'Toda vida vale la pena salvarla, si no se nos opone. Solo nuestros enemigos deben descansar permanentemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te aflijas por el desconcierto mostrado por aquellos a quienes has ayudado. Es común que aquellos que han regresado recientemente al mundo de los vivos experimenten desorientación, pero imagínate el impacto de encontrarte con un ser extraño al mismo tiempo.$B$BEl joven chamán tiene la suerte de haber sobrevivido a una lección tan dura gracias a ti, y es apropiado que te permitan invocar este poder como mejor te parezca.', 0),
(@ID, 'esMX', 'No te aflijas por el desconcierto mostrado por aquellos a quienes has ayudado. Es común que aquellos que han regresado recientemente al mundo de los vivos experimenten desorientación, pero imagínate el impacto de encontrarte con un ser extraño al mismo tiempo.$B$BEl joven chamán tiene la suerte de haber sobrevivido a una lección tan dura gracias a ti, y es apropiado que te permitan invocar este poder como mejor te parezca.', 0);
-- 9601 Hacia El Baluarte
-- https://es.wowhead.com/quest=9601
SET @ID := 9601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahh... parece que es el momento.$B$B<Mehlar asiente con complicidad.>', 0),
(@ID, 'esMX', 'Ahh... parece que es el momento.$B$B<Mehlar asiente con complicidad.>', 0);
-- 9602 Líbralos del mal...
-- https://es.wowhead.com/quest=9602
SET @ID := 9602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto!', 0),
(@ID, 'esMX', '¡Has vuelto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El exarca Menelaous toma la carta que le das y empieza a leerla.>$B$BMalditos sean... Malditos sean todos en El Vacío Abisal. ¡Han tenido un espía vigilando todo lo que hacíamos! ¿Y desde cuándo?$B$B¡Se lo comunicaré a Velen inmediatamente!$B$BNos has prestado un gran servicio, $n. No bajes la guardia, te contactaré cuando el profeta me haya dado las instrucciones sobre lo que debemos hacer.', 0),
(@ID, 'esMX', '<El exarca Menelaous toma la carta que le das y empieza a leerla.>$B$BMalditos sean... Malditos sean todos en El Vacío Abisal. ¡Han tenido un espía vigilando todo lo que hacíamos! ¿Y desde cuándo?$B$B¡Se lo comunicaré a Velen inmediatamente!$B$BNos has prestado un gran servicio, $n. No bajes la guardia, te contactaré cuando el profeta me haya dado las instrucciones sobre lo que debemos hacer.', 0);
-- 9603 Camas, vendas y algo más
-- https://es.wowhead.com/quest=9603
SET @ID := 9603;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buenos días, $n. ¿Te interesaría alquilar un hipogrifo?', 0),
(@ID, 'esMX', 'Buenos días, $n. ¿Te interesaría alquilar un hipogrifo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque necesitas ir a El Exodar?$B$BEso será un viaje largo pero no te preocupes, tengo lo necesario para que llegues allí rápidamente.', 0),
(@ID, 'esMX', '¿Conque necesitas ir a El Exodar?$B$BEso será un viaje largo pero no te preocupes, tengo lo necesario para que llegues allí rápidamente.', 0);
-- 9604 En alas de un hipogrifo
-- https://es.wowhead.com/quest=9604
SET @ID := 9604;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $gamigo:amiga;. Tienes aspecto de haber hecho un largo viaje. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Saludos, $gamigo:amiga;. Tienes aspecto de haber hecho un largo viaje. ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que traes la lista de Chellan. ¡Excelente! Esperaba recibirla hoy. A ver qué necesita.$B$B<Nurguni lee la lista y empieza a colocar varios artículos en una caja.>$B$BEsto es casi todo lo que pedía. Las piezas para las camas son demasiado grandes para entregarlas por hipogrifo pero organizaré su envío por carro.', 0),
(@ID, 'esMX', 'Así que traes la lista de Chellan. ¡Excelente! Esperaba recibirla hoy. A ver qué necesita.$B$B<Nurguni lee la lista y empieza a colocar varios artículos en una caja.>$B$BEsto es casi todo lo que pedía. Las piezas para las camas son demasiado grandes para entregarlas por hipogrifo pero organizaré su envío por carro.', 0);
-- 9605 El maestro de hipogrifos Stephanos
-- https://es.wowhead.com/quest=9605
SET @ID := 9605;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Adónde te diriges, $c?', 0),
(@ID, 'esMX', '¿Adónde te diriges, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que te han enviado otra vez a la Avanzada Azur con este paquete? Ningún problema, $c. Solo tienes que volver a hablar conmigo y estarás de camino con esos suministros.', 0),
(@ID, 'esMX', '¿Así que te han enviado otra vez a la Avanzada Azur con este paquete? Ningún problema, $c. Solo tienes que volver a hablar conmigo y estarás de camino con esos suministros.', 0);
-- 9606 Regresa junto a la cuidadora Chellan
-- https://es.wowhead.com/quest=9606
SET @ID := 9606;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Consiguió Nurguni reunir todo lo que había en la lista?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Consiguió Nurguni reunir todo lo que había en la lista?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Al entregar la caja, le dices a la cuidadora que Nurguni se está ocupando de enviar los artículos más voluminosos por carro.>$B$B¡Fantástico! Bien, al fin podré montar unas camas y un puesto de primeros auxilios para poder atender mejor a los heridos y a cualquier superviviente que encontremos.$B$BNo puedo agradecértelo lo suficiente, $n. Tienes toda mi gratitud y la de los vindicadores de la Avanzada Azur.', 0),
(@ID, 'esMX', '<Al entregar la caja, le dices a la cuidadora que Nurguni se está ocupando de enviar los artículos más voluminosos por carro.>$B$B¡Fantástico! Bien, al fin podré montar unas camas y un puesto de primeros auxilios para poder atender mejor a los heridos y a cualquier superviviente que encontremos.$B$BNo puedo agradecértelo lo suficiente, $n. Tienes toda mi gratitud y la de los vindicadores de la Avanzada Azur.', 0);
-- 9607 Corazón de ira
-- https://es.wowhead.com/quest=9607
SET @ID := 9607;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soldado, informe! ¿Ya has explorado todo el Horno de sangre?', 0),
(@ID, 'esMX', '¡Soldado, informe! ¿Ya has explorado todo el Horno de sangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<El comandante de la fuerza mira a su alrededor a las miradas de los demás y luego baja la voz a un susurro.>$B$BEso lo sella. Deben estar usando la sangre de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la Legión Ardiente. Y si pueden hacer esto con los orcos marrones, también pueden hacerlo con los verdes. Con todos los nuevos orcos de la Horda entrando a través del Portal Oscuro, ¡eso no es bueno!$B$BDebemos atacar el corazón de su poderío militar, ¡y pronto!', 0),
(@ID, 'esMX', '¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<El comandante de la fuerza mira a su alrededor a las miradas de los demás y luego baja la voz a un susurro.>$B$BEso lo sella. Deben estar usando la sangre de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la Legión Ardiente. Y si pueden hacer esto con los orcos marrones, también pueden hacerlo con los verdes. Con todos los nuevos orcos de la Horda entrando a través del Portal Oscuro, ¡eso no es bueno!$B$BDebemos atacar el corazón de su poderío militar, ¡y pronto!', 0);
-- 9608 Corazón de ira
-- https://es.wowhead.com/quest=9608
SET @ID := 9608;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has explorado todo el Horno de sangre? ¿Qué tienes que decirme?', 0),
(@ID, 'esMX', '¿Ya has explorado todo el Horno de sangre? ¿Qué tienes que decirme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<Nazgrel se da cuenta de las miradas de los demás reunidos y baja la voz a un susurro.>$B$BEso lo sella. Deben estar usando la sangre de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la Legión Ardiente. Y si pueden hacer esto con los orcos marrones Mag\'har, ¡pueden hacerlo con nosotros!$B$BTendremos que atacar el corazón de su poderío militar, ¡y pronto!', 0),
(@ID, 'esMX', '¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<Nazgrel se da cuenta de las miradas de los demás reunidos y baja la voz a un susurro.>$B$BEso lo sella. Deben estar usando la sangre de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la Legión Ardiente. Y si pueden hacer esto con los orcos marrones Mag\'har, ¡pueden hacerlo con nosotros!$B$BTendremos que atacar el corazón de su poderío militar, ¡y pronto!', 0);
-- 9609 Ayuda al vigía Biggs
-- https://es.wowhead.com/quest=9609
SET @ID := 9609;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Un draenei te envió aquí desde El Puerto? Que extraño.$B$BBueno, no soy de los que rechazan la ayuda. ¡Gracias por venir, $n!', 0),
(@ID, 'esMX', '¿Qué? ¿Un draenei te envió aquí desde El Puerto? Que extraño.$B$BBueno, no soy de los que rechazan la ayuda. ¡Gracias por venir, $n!', 0);
-- 9610 Charca de Lágrimas
-- https://es.wowhead.com/quest=9610
SET @ID := 9610;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que reúnas suficientes artefactos Atal\'ai para poder comenzar a estudiarlos. Estoy ansioso por descubrir qué pasó con su otrora gran civilización.', 0),
(@ID, 'esMX', 'Espero que reúnas suficientes artefactos Atal\'ai para poder comenzar a estudiarlos. Estoy ansioso por descubrir qué pasó con su otrora gran civilización.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. El estudio de estos artefactos debería mantenerme ocupado durante algún tiempo. ¿De qué otra manera podríamos tábido y draenei encajar, si no llegamos a comprender la historia de tu mundo?', 0),
(@ID, 'esMX', 'Gracias, $n. El estudio de estos artefactos debería mantenerme ocupado durante algún tiempo. ¿De qué otra manera podríamos tábido y draenei encajar, si no llegamos a comprender la historia de tu mundo?', 0);
-- 9612 ¡Gracias de corazón!
-- https://es.wowhead.com/quest=9612
SET @ID := 9612;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. ¡Bien hecho! Estás resultando ser un $r especial, un poco por encima de los demás de tu edad. ¡Toma esto como recompensa!', 0),
(@ID, 'esMX', 'Bien hecho, $n. ¡Bien hecho! Estás resultando ser un $r especial, un poco por encima de los demás de tu edad. ¡Toma esto como recompensa!', 0);
-- 9616 ¡Bandidos!
-- https://es.wowhead.com/quest=9616
SET @ID := 9616;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Estoy muy ocupado, $n.', 0),
(@ID, 'esMX', '¿Sí? Estoy muy ocupado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por la cabeza geométrica y sin barba de O\'ros! Es bueno que me hayas traído esto, $n. Estos elfos de sangre buscan... bueno, sangre. ¡Velen será informado de inmediato! Toma esto como recompensa.', 0),
(@ID, 'esMX', '¡Por la cabeza geométrica y sin barba de O\'ros! Es bueno que me hayas traído esto, $n. Estos elfos de sangre buscan... bueno, sangre. ¡Velen será informado de inmediato! Toma esto como recompensa.', 0);
-- 9617 Busca a los errantes
-- https://es.wowhead.com/quest=9617
SET @ID := 9617;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0),
(@ID, 'esMX', '$n, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0);
-- 9618 Devuelve los informes
-- https://es.wowhead.com/quest=9618
SET @ID := 9618;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste localizar a Keltus?', 0),
(@ID, 'esMX', '¿Pudiste localizar a Keltus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Todos estos informes son de Keltus? Ha estado bastante ocupado, eso es seguro.$B$BKeltus es un pícaro entre los pícaros: rara vez sigue las órdenes al pie de la letra y, a menudo, toma el asunto en sus propias manos. Sin embargo, no te lo tomes a mal, ya que es uno de mis espías de mayor confianza y estaríamos perdidos sin él.$B$BHoy ha hecho un trabajo ejemplar. Acepta esta hoja y guíala hacia la espalda de nuestro enemigo.', 0),
(@ID, 'esMX', '¿Todos estos informes son de Keltus? Ha estado bastante ocupado, eso es seguro.$B$BKeltus es un pícaro entre los pícaros: rara vez sigue las órdenes al pie de la letra y, a menudo, toma el asunto en sus propias manos. Sin embargo, no te lo tomes a mal, ya que es uno de mis espías de mayor confianza y estaríamos perdidos sin él.$B$BHoy ha hecho un trabajo ejemplar. Acepta esta hoja y guíala hacia la espalda de nuestro enemigo.', 0);
-- 9620 El equipo de investigación desaparecido
-- https://es.wowhead.com/quest=9620
SET @ID := 9620;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los cuerpos del equipo de investigación draenei están esparcidos... atravesados por las armas nagas. La zona está cubierta de restos de sus suministros y equipamiento de investigación pero ni rastro de los cristales de datos.', 0),
(@ID, 'esMX', 'Los cuerpos del equipo de investigación draenei están esparcidos... atravesados por las armas nagas. La zona está cubierta de restos de sus suministros y equipamiento de investigación pero ni rastro de los cristales de datos.', 0);
-- 9621 Enviado de la Horda
-- https://es.wowhead.com/quest=9621
SET @ID := 9621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, una visita de Quel\'Thalas! ¿Qué noticias traes?', 0),
(@ID, 'esMX', '¡Ah, una visita de Quel\'Thalas! ¿Qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya está hecho, pues. Ese sucio traidor tiene su merecido.$B$B¿Lo has hecho tú? Una hazaña impresionante que demuestra que tu raza sigue siendo digna, $n.$B$BEsta noticia será otro motivo más para que Lor\'themar mejore sus relaciones con los trols y su Jefe de Guerra.', 0),
(@ID, 'esMX', 'Ya está hecho, pues. Ese sucio traidor tiene su merecido.$B$B¿Lo has hecho tú? Una hazaña impresionante que demuestra que tu raza sigue siendo digna, $n.$B$BEsta noticia será otro motivo más para que Lor\'themar mejore sus relaciones con los trols y su Jefe de Guerra.', 0);
-- 9622 Avisar a tu pueblo
-- https://es.wowhead.com/quest=9622
SET @ID := 9622;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has dicho visiones? Interesante... ¿Y esta profecía ha ocurrido?$B$B¿Pero dices que vieron el núcleo de poder de El Exodar? ¿Y O\'ros estaba en la visión? ¿Qué significará...?', 0),
(@ID, 'esMX', '¿Has dicho visiones? Interesante... ¿Y esta profecía ha ocurrido?$B$B¿Pero dices que vieron el núcleo de poder de El Exodar? ¿Y O\'ros estaba en la visión? ¿Qué significará...?', 0);
-- 9623 Madurez
-- https://es.wowhead.com/quest=9623
SET @ID := 9623;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Torallius se ajusta el parche para mirarte.>$B$B¿Esto es lo mejor que podemos ofrecerle a la Mano de Argus?', 0),
(@ID, 'esMX', '<Torallius se ajusta el parche para mirarte.>$B$B¿Esto es lo mejor que podemos ofrecerle a la Mano de Argus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Torallius suspira.>$B$BBueno, dame esas órdenes que les eche un vistazo.', 0),
(@ID, 'esMX', '<Torallius suspira.>$B$BBueno, dame esas órdenes que les eche un vistazo.', 0);
-- 9624 Un caprichito goloso
-- https://es.wowhead.com/quest=9624
SET @ID := 9624;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cada vez cuesta más encontrar las peras de arena y, claro, eso significa menos tartas y menos comidita para los elekks. ¿Pudiste recolectar toda la fruta que necesito?', 0),
(@ID, 'esMX', 'Cada vez cuesta más encontrar las peras de arena y, claro, eso significa menos tartas y menos comidita para los elekks. ¿Pudiste recolectar toda la fruta que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ha costado encontrar suficientes? En cada viaje me llevaba más tiempo.$B$BPronto tendré que dejarlo completamente ya que no dispondré de ese tiempo. Gracias por recolectar las peras para mí, $n. Así podré hacer una última tarta o dos antes de que acabe la temporada.', 0),
(@ID, 'esMX', '¿Te ha costado encontrar suficientes? En cada viaje me llevaba más tiempo.$B$BPronto tendré que dejarlo completamente ya que no dispondré de ese tiempo. Gracias por recolectar las peras para mí, $n. Así podré hacer una última tarta o dos antes de que acabe la temporada.', 0);
-- 9625 Con los elekks no se bromea
-- https://es.wowhead.com/quest=9625
SET @ID := 9625;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, has llegado hasta aquí! A trabajar antes de que te pongas $gperdido:perdida; de sangre.', 0),
(@ID, 'esMX', '¡Bien, has llegado hasta aquí! A trabajar antes de que te pongas $gperdido:perdida; de sangre.', 0);
-- 9626 Encuentro con el Jefe de Guerra
-- https://es.wowhead.com/quest=9626
SET @ID := 9626;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a verme, $r? Habla y sé $grápido:rápida;. No tengo tiempo para las formalidades de tu raza.', 0),
(@ID, 'esMX', '¿Has venido a verme, $r? Habla y sé $grápido:rápida;. No tengo tiempo para las formalidades de tu raza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thrall comienza a leer la carta.>$B$BQué persistente es Sylvanas... Hasta ha mandado a $gun campeón:una campeona; de Lunargenta. ¿Acaso cree que eso cambia algo las cosas?', 0),
(@ID, 'esMX', '<Thrall comienza a leer la carta.>$B$BQué persistente es Sylvanas... Hasta ha mandado a $gun campeón:una campeona; de Lunargenta. ¿Acaso cree que eso cambia algo las cosas?', 0);
-- 9627 Fidelidad a la Horda
-- https://es.wowhead.com/quest=9627
SET @ID := 9627;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu trabajo ha contribuido a que la causa de nuestra raza progrese tremendamente. Thrall no solo cree que somos capaces de manejarnos a nosotros mismos frente al enemigo, sino que también cree que puede usar nuestro vínculo con Terrallende como un medio para llegar a su gente.$B$BNo es exactamente la verdad, pero tampoco una mentira.$B$BPrepárate para grandes cambios, $n. Ahora somos oficialmente parte de la Horda.', 0),
(@ID, 'esMX', 'Tu trabajo ha contribuido a que la causa de nuestra raza progrese tremendamente. Thrall no solo cree que somos capaces de manejarnos a nosotros mismos frente al enemigo, sino que también cree que puede usar nuestro vínculo con Terrallende como un medio para llegar a su gente.$B$BNo es exactamente la verdad, pero tampoco una mentira.$B$BPrepárate para grandes cambios, $n. Ahora somos oficialmente parte de la Horda.', 0);
-- 9628 Recuperar los datos
-- https://es.wowhead.com/quest=9628
SET @ID := 9628;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has sido capaz de averiguar lo que impedía al equipo de investigación volver?', 0),
(@ID, 'esMX', '¿Has sido capaz de averiguar lo que impedía al equipo de investigación volver?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le cuentas al presagista Mikolaas el destino del equipo de investigación. Toma el cristal que le has traído pero permanece en silencio un buen rato.>$B$BEran unos hombres buenos, $n, y sabían que su misión sería peligrosa. Te agradezco tu ayuda para encontrarlos y recuperar el cristal.', 0),
(@ID, 'esMX', '<Le cuentas al presagista Mikolaas el destino del equipo de investigación. Toma el cristal que le has traído pero permanece en silencio un buen rato.>$B$BEran unos hombres buenos, $n, y sabían que su misión sería peligrosa. Te agradezco tu ayuda para encontrarlos y recuperar el cristal.', 0);
-- 9629 Aquí te pillo, aquí te marco
-- https://es.wowhead.com/quest=9629
SET @ID := 9629;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Exploradores Cienonegro marcados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha funcionado el dispositivo? ¿Has marcado a los múrlocs para mi investigación?', 0),
(@ID, 'esMX', '¿Ha funcionado el dispositivo? ¿Has marcado a los múrlocs para mi investigación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Me preocupaba que la herramienta de marcar no funcionara bien, pero parece que todo ha ido según el plan.', 0),
(@ID, 'esMX', 'Muy bien, $n. Me preocupaba que la herramienta de marcar no funcionara bien, pero parece que todo ha ido según el plan.', 0);
-- 9630 El diario de Medivh
-- https://es.wowhead.com/quest=9630
SET @ID := 9630;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una ingente cantidad de información... ¡Podría pasarme años aquí! Seguro que Dalaran lo entenderá...', 0),
(@ID, 'esMX', 'Una ingente cantidad de información... ¡Podría pasarme años aquí! Seguro que Dalaran lo entenderá...', 0);
-- 9631 La ayuda de una compañera
-- https://es.wowhead.com/quest=9631
SET @ID := 9631;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alturus te envió. Las estrellas hablaron de tu llegada.', 0),
(@ID, 'esMX', 'Alturus te envió. Las estrellas hablaron de tu llegada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alturus quiere revivir a todo un dragón de entre los muertos? Lo pongas como lo pongas, no va a ser fácil.$B$BHablemos a ver cómo podemos ayudarnos mutuamente, $n.', 0),
(@ID, 'esMX', '¿Alturus quiere revivir a todo un dragón de entre los muertos? Lo pongas como lo pongas, no va a ser fácil.$B$BHablemos a ver cómo podemos ayudarnos mutuamente, $n.', 0);
-- 9632 Aliados inesperados
-- https://es.wowhead.com/quest=9632
SET @ID := 9632;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Qué tienes ahí?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo ayudarte a llegar a Auberdine. ¡Por suerte, solo es un viaje cortito en barco!', 0),
(@ID, 'esMX', 'Puedo ayudarte a llegar a Auberdine. ¡Por suerte, solo es un viaje cortito en barco!', 0);
-- 9633 Camino de Auberdine
-- https://es.wowhead.com/quest=9633
SET @ID := 9633;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a Auberdine, $gamigo:amiga;. ¿Qué te trae a Costa Oscura?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a Auberdine, $gamigo:amiga;. ¿Qué te trae a Costa Oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thundris acepta tu carta y la lee rápidamente, asintiendo con la cabeza.>$B$BLas islas que $r llaman Bruma Azur y Bruma de Sangre fueron habitadas hace mucho tiempo por mi gente. Algunas de las amenazas a las que se enfrenta el Anacoreta Paetheus y sus hermanos son antiguos enemigos de los elfos de la noche.$B$BEstoy seguro de que la gente de Auberdine está dispuesta a brindar toda la ayuda que podamos a nuestros nuevos aliados. Tan pronto como haya hablado con la gente del pueblo y los centinelas, enviaré un mensaje a Paetheus.', 0),
(@ID, 'esMX', '<Thundris acepta tu carta y la lee rápidamente, asintiendo con la cabeza.>$B$BLas islas que $r llaman Bruma Azur y Bruma de Sangre fueron habitadas hace mucho tiempo por mi gente. Algunas de las amenazas a las que se enfrenta el Anacoreta Paetheus y sus hermanos son antiguos enemigos de los elfos de la noche.$B$BEstoy seguro de que la gente de Auberdine está dispuesta a brindar toda la ayuda que podamos a nuestros nuevos aliados. Tan pronto como haya hablado con la gente del pueblo y los centinelas, enviaré un mensaje a Paetheus.', 0);
-- 9634 Depredadores alienígenas
-- https://es.wowhead.com/quest=9634
SET @ID := 9634;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos actuar antes de que el devastadores desplacen a los depredadores nativos de la Isla Bruma de Sangre. ¿Has comenzado a sacrificar la población de devastadores?', 0),
(@ID, 'esMX', 'Debemos actuar antes de que el devastadores desplacen a los depredadores nativos de la Isla Bruma de Sangre. ¿Has comenzado a sacrificar la población de devastadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. La población de devastadores se conformará con mirar en una temporada pero es un buen comienzo.', 0),
(@ID, 'esMX', 'Muy bien, $n. La población de devastadores se conformará con mirar en una temporada pero es un buen comienzo.', 0);
