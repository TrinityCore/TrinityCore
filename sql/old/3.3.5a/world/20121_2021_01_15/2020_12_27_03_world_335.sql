-- 778 Lo tienes crudo
-- https://es.classic.wowhead.com/quest=778
SET @ID := 778;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No es exactamente el final que esperaba. ¿Has logrado recuperar mis grilletes?', 0),
(@ID, 'esMX', 'No es exactamente el final que esperaba. ¿Has logrado recuperar mis grilletes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ha sido un suplicio, ¿verdad?$B$BNo estoy seguro de qué puede haber fallado. Menos mal que hemos contado con mi magia para enviar a la criatura de vuelta a su hogar.$B$B¿Quizás una muestra de aprecio por ser tan $gdenodado:denodada;...?', 0),
(@ID, 'esMX', 'Gracias, $n. Ha sido un suplicio, ¿verdad?$B$BNo estoy seguro de qué puede haber fallado. Menos mal que hemos contado con mi magia para enviar a la criatura de vuelta a su hogar.$B$B¿Quizás una muestra de aprecio por ser tan $gdenodado:denodada;...?', 0);
-- 779 El Sello de la Tierra
-- https://es.classic.wowhead.com/quest=779
SET @ID := 779;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Sello de la Tierra se encuentra aquí, con tres hornacinas en las que se alojan la piedra rúnica de Amatista, la de Ópalo y la de Diamante.', 0),
(@ID, 'esMX', 'El Sello de la Tierra se encuentra aquí, con tres hornacinas en las que se alojan la piedra rúnica de Amatista, la de Ópalo y la de Diamante.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al colocar las piedras rúnicas en las muescas correspondientes, un violento estruendo sacude la tierra y se rompe el Sello.', 0),
(@ID, 'esMX', 'Al colocar las piedras rúnicas en las muescas correspondientes, un violento estruendo sacude la tierra y se rompe el Sello.', 0);
-- 781 Ataque al Campamento Narache
-- https://es.classic.wowhead.com/quest=781
SET @ID := 781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que algo te preocupa, $n. ¿Qué noticias traes?', 0),
(@ID, 'esMX', 'Parece que algo te preocupa, $n. ¿Qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué inquietante! Pero podemos avisar a nuestros hermanos del Poblado Pezuña de Sangre para que nos ayuden. Has salvado la vida de muchos tauren, $n.', 0),
(@ID, 'esMX', '¡Qué inquietante! Pero podemos avisar a nuestros hermanos del Poblado Pezuña de Sangre para que nos ayuden. Has salvado la vida de muchos tauren, $n.', 0);
-- 782 Alianzas rotas
-- https://es.classic.wowhead.com/quest=782
SET @ID := 782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La traición de Tho\'grun... ¿puede extrañarse nadie de que los ogros ya no sean parte de la Horda? Me encantaría verlo muerto y que se recuperara el Signo de la Tierra.$B$BSi aún no lo has despachado, no pierdas el tiempo yendo al Asentamiento Boff. Está al sureste de Kargath.', 0),
(@ID, 'esMX', 'La traición de Tho\'grun... ¿puede extrañarse nadie de que los ogros ya no sean parte de la Horda? Me encantaría verlo muerto y que se recuperara el Signo de la Tierra.$B$BSi aún no lo has despachado, no pierdas el tiempo yendo al Asentamiento Boff. Está al sureste de Kargath.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con Tho\'grun muerto y su cadáver limpiado por el viento del desierto y las águilas ratoneras, reinará la confusión entre los ogros. Aunque solo es una pequeña victoria, llevará a otra mucho más importante.$B$BEl Signo de la Tierra está ahora en nuestras manos y podemos abrir la cárcel de los dragones negros en Lethlor. Los liberaremos de su eterno encarcelamiento, ¡aunque para su condena!', 0),
(@ID, 'esMX', 'Con Tho\'grun muerto y su cadáver limpiado por el viento del desierto y las águilas ratoneras, reinará la confusión entre los ogros. Aunque solo es una pequeña victoria, llevará a otra mucho más importante.$B$BEl Signo de la Tierra está ahora en nuestras manos y podemos abrir la cárcel de los dragones negros en Lethlor. Los liberaremos de su eterno encarcelamiento, ¡aunque para su condena!', 0);
-- 784 Vencer a los traidores
-- https://es.classic.wowhead.com/quest=784
SET @ID := 784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes tus órdenes, $n. La seguridad de Durotar está en duda. Completa la tarea que tienes ante ti o baja la cabeza avergonzado.$B$BMuestra tu honor y derrota a los humanos del Fuerte de Tiragarde.', 0),
(@ID, 'esMX', 'Tienes tus órdenes, $n. La seguridad de Durotar está en duda. Completa la tarea que tienes ante ti o baja la cabeza avergonzado.$B$BMuestra tu honor y derrota a los humanos del Fuerte de Tiragarde.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los relatos de tu valor viajan raudos, $c. Los de tu victoria en el Fuerte de Tiragarde serán anunciados en Orgrimmar.', 0),
(@ID, 'esMX', 'Los relatos de tu valor viajan raudos, $c. Los de tu victoria en el Fuerte de Tiragarde serán anunciados en Orgrimmar.', 0);
-- 786 Frustrar los planes kolkar
-- https://es.classic.wowhead.com/quest=786
SET @ID := 786;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Plan de ataque: Valle de los Retos destruido', `ObjectiveText2` = 'Plan de ataque: Poblado Sen\'jin destruido', `ObjectiveText3` = 'Plan de ataque: Orgrimmar destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los centauros han demostrado ser una molestia constante para la Horda. No se pueden tolerar sus intenciones de sitiar nuestra patria.', 0),
(@ID, 'esMX', 'Los centauros han demostrado ser una molestia constante para la Horda. No se pueden tolerar sus intenciones de sitiar nuestra patria.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los centauros Kolkar atacaran, a buen seguro, la Horda prevalecería. Pero impidiendo la eventualidad de un ataque, hemos evitado un inútil derramamiento de la sangre de nuestros poderosos guerreros.$B$BPero sabemos, como sabemos que hay arena en el Desierto de Tanaris, que antes de que estos atroces tiempos queden atrás, se derramará sangre.$B$BHas servido bien a tu gente, $c.', 0),
(@ID, 'esMX', 'Si los centauros Kolkar atacaran, a buen seguro, la Horda prevalecería. Pero impidiendo la eventualidad de un ataque, hemos evitado un inútil derramamiento de la sangre de nuestros poderosos guerreros.$B$BPero sabemos, como sabemos que hay arena en el Desierto de Tanaris, que antes de que estos atroces tiempos queden atrás, se derramará sangre.$B$BHas servido bien a tu gente, $c.', 0);
-- 787 La nueva Horda
-- https://es.classic.wowhead.com/quest=787
SET @ID := 787;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro de los reclutas de Eitrigg, ¿eh?$B$BNos encontramos en una situación lamentable si esto es lo mejor que puede producir la Horda. No importa. Cuando creamos que estás $glisto:lista; para dejar el Valle, serás $gun orgulloso guerrero:una orgullosa guerrera; de la Horda.', 0),
(@ID, 'esMX', 'Otro de los reclutas de Eitrigg, ¿eh?$B$BNos encontramos en una situación lamentable si esto es lo mejor que puede producir la Horda. No importa. Cuando creamos que estás $glisto:lista; para dejar el Valle, serás $gun orgulloso guerrero:una orgullosa guerrera; de la Horda.', 0);
-- 788 Dientes afilados
-- https://es.classic.wowhead.com/quest=788
SET @ID := 788;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no hayas regresado para intentar convencerme de que has completado tu tarea, $n? No, claro que no. Pensaría mejor en ti.', 0),
(@ID, 'esMX', 'Espero que no hayas regresado para intentar convencerme de que has completado tu tarea, $n? No, claro que no. Pensaría mejor en ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Umm... no está mal, $n. Pero que no se te suba a la cabeza... tendrás que luchar con cosas mucho más duras que un jabalí en tu carrera.$B$BSin embargo, has mostrado tu valía, y tu siguiente prueba será contra un adversario mucho más peligroso, necesitarás algo más de protección.', 0),
(@ID, 'esMX', 'Umm... no está mal, $n. Pero que no se te suba a la cabeza... tendrás que luchar con cosas mucho más duras que un jabalí en tu carrera.$B$BSin embargo, has mostrado tu valía, y tu siguiente prueba será contra un adversario mucho más peligroso, necesitarás algo más de protección.', 0);
-- 789 Aguijón de escórpido
-- https://es.classic.wowhead.com/quest=789
SET @ID := 789;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caparazón de un escórpido no es tan resistente como para disuadir la fuerza y determinación de un guerrero. Golpea fuerte y sin dudas, y los escórpidos serán una presa fácil.', 0),
(@ID, 'esMX', 'El caparazón de un escórpido no es tan resistente como para disuadir la fuerza y determinación de un guerrero. Golpea fuerte y sin dudas, y los escórpidos serán una presa fácil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De tus luchas con los escórpidos debes sacar una lección importante. Tanto el menor como el mayor de tus oponentes pueden enviarte directo al infierno. En el combate cualquier cosa y en cualquier número o tamaño puede llevarte a la perdición.$B$BNo tengo nada más que enseñarte, $n. Te has portado bien y seguiré con mucho interés tus progresos.', 0),
(@ID, 'esMX', 'De tus luchas con los escórpidos debes sacar una lección importante. Tanto el menor como el mayor de tus oponentes pueden enviarte directo al infierno. En el combate cualquier cosa y en cualquier número o tamaño puede llevarte a la perdición.$B$BNo tengo nada más que enseñarte, $n. Te has portado bien y seguiré con mucho interés tus progresos.', 0);
-- 790 Sarkoth
-- https://es.classic.wowhead.com/quest=790
SET @ID := 790;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahhh... mi padre siempre decía que nunca llegaría demasiado lejos y estando aquí, bajo un árbol viendo cómo mi vida se desvanece, parece que estaba en lo cierto.$B$BAl menos me gustaría morir sabiendo que mi último enemigo ha muerto.', 0),
(@ID, 'esMX', 'Ahhh... mi padre siempre decía que nunca llegaría demasiado lejos y estando aquí, bajo un árbol viendo cómo mi vida se desvanece, parece que estaba en lo cierto.$B$BAl menos me gustaría morir sabiendo que mi último enemigo ha muerto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis golpes no bastaron para matarle, pero cuando pienso en el daño que le hice siento algo de orgullo. Ese orgullo será todo lo que tenga si muero y, desde esa perspectiva, me enfurezco al pensar en las pocas cosas que he terminado en mi vida.', 0),
(@ID, 'esMX', 'Mis golpes no bastaron para matarle, pero cuando pienso en el daño que le hice siento algo de orgullo. Ese orgullo será todo lo que tenga si muero y, desde esa perspectiva, me enfurezco al pensar en las pocas cosas que he terminado en mi vida.', 0);
-- 791 Asume tu responsabilidad
-- https://es.classic.wowhead.com/quest=791
SET @ID := 791;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Combatí con orgullo al lado del Jefe de Guerra cuando llegamos por vez primera a estas tierras. Mi piel está surcada por las cicatrices del combate.$B$BMi hacha y mi grito de guerra defendieron el honor de la Horda en la derrota de Archimonde, cuando humanos y elfos sellaron, unidos por la necesidad, su impía alianza.$B$BAhora, sigo sintiéndome útil en mi cargo de vigilante y oficial de suministros.', 0),
(@ID, 'esMX', 'Combatí con orgullo al lado del Jefe de Guerra cuando llegamos por vez primera a estas tierras. Mi piel está surcada por las cicatrices del combate.$B$BMi hacha y mi grito de guerra defendieron el honor de la Horda en la derrota de Archimonde, cuando humanos y elfos sellaron, unidos por la necesidad, su impía alianza.$B$BAhora, sigo sintiéndome útil en mi cargo de vigilante y oficial de suministros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Esta bolsa resultará muy útil en el campo de batalla.$B$B¡Aplaudo tu vigor y tu disposición para morir en nombre de la Horda!', 0),
(@ID, 'esMX', 'Excelente, $n. Esta bolsa resultará muy útil en el campo de batalla.$B$B¡Aplaudo tu vigor y tu disposición para morir en nombre de la Horda!', 0);
-- 792 Familiares viles
-- https://es.classic.wowhead.com/quest=792
SET @ID := 792;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para demostrar tu valía contra el Filo Ardiente, primero debes derrotar a sus Familiares Viles. Regresa a mí cuando hayas hecho esto.', 0),
(@ID, 'esMX', 'Para demostrar tu valía contra el Filo Ardiente, primero debes derrotar a sus Familiares Viles. Regresa a mí cuando hayas hecho esto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien hecho, $n.$B$BAunque los familiares viles no son más que mascotas de los poderes oscuros del Filo Ardiente, tu victoria presagia grandes hazañas.', 0),
(@ID, 'esMX', 'Muy bien hecho, $n.$B$BAunque los familiares viles no son más que mascotas de los poderes oscuros del Filo Ardiente, tu victoria presagia grandes hazañas.', 0);
-- 793 Alianzas rotas
-- https://es.classic.wowhead.com/quest=793
SET @ID := 793;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay pocos enemigos más letales que un dragonante, y pocos dragones luchaban más ferozmente que Cinchoscura y Hematus.', 0),
(@ID, 'esMX', 'Hay pocos enemigos más letales que un dragonante, y pocos dragones luchaban más ferozmente que Cinchoscura y Hematus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Vuelo negro sigue buscando aliados entre los orcos renegados Roca Negra y hay que ponerlos a raya o eliminarlos. Con la muerte de Cinchoscura y Hematus, podemos centrar nuestra atención hacia el oeste, hacia la Cumbre de Roca Negra.', 0),
(@ID, 'esMX', 'El Vuelo negro sigue buscando aliados entre los orcos renegados Roca Negra y hay que ponerlos a raya o eliminarlos. Con la muerte de Cinchoscura y Hematus, podemos centrar nuestra atención hacia el oeste, hacia la Cumbre de Roca Negra.', 0);
-- 794 El medallón del Filo Ardiente
-- https://es.classic.wowhead.com/quest=794
SET @ID := 794;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado tu tarea, $n? ¿Tienes el Medallón del Filo Ardiente?', 0),
(@ID, 'esMX', '¿Has terminado tu tarea, $n? ¿Tienes el Medallón del Filo Ardiente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has recuperado! ¡Bien hecho!$B$BTus esfuerzos en el Aquelarre del Filo Ardiente son fundamentales para erradicar ese culto del Valle de los Retos. No obstante, temo que tienen más planes en esta tierra.$B$BAún no hemos visto su final.', 0),
(@ID, 'esMX', '¡Lo has recuperado! ¡Bien hecho!$B$BTus esfuerzos en el Aquelarre del Filo Ardiente son fundamentales para erradicar ese culto del Valle de los Retos. No obstante, temo que tienen más planes en esta tierra.$B$BAún no hemos visto su final.', 0);
-- 795 El Sello de la Tierra
-- https://es.classic.wowhead.com/quest=795
SET @ID := 795;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Sello de la Tierra se encuentra aquí, con tres hornacinas en las que se alojan la piedra rúnica de Amatista, la de Ópalo y la de Diamante.', 0),
(@ID, 'esMX', 'El Sello de la Tierra se encuentra aquí, con tres hornacinas en las que se alojan la piedra rúnica de Amatista, la de Ópalo y la de Diamante.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al colocar las piedras rúnicas en las muescas correspondientes, un violento estruendo sacude la tierra y se rompe el Sello.', 0),
(@ID, 'esMX', 'Al colocar las piedras rúnicas en las muescas correspondientes, un violento estruendo sacude la tierra y se rompe el Sello.', 0);
-- 804 Sarkoth
-- https://es.classic.wowhead.com/quest=804
SET @ID := 804;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según tu descripción de la bestia creo que estás hablando de Sarkoth. No me extraña que pudiera con Hana\'zua. Le prestaremos ayuda inmediatamente, ya no necesitas seguir preocupándote por su situación.$B$BPero hay una cosa que debo decir, me ha impresionado saber que acabaste con la vida de Sarkoth. Es una hazaña de la que estar $gorgulloso:orgullosa;, $n. Además, el haber luchado por el honor de un desconocido, dejando a un lado tus propias tareas, es, sin duda alguna, todo un signo de honor por tu parte.', 0),
(@ID, 'esMX', 'Según tu descripción de la bestia creo que estás hablando de Sarkoth. No me extraña que pudiera con Hana\'zua. Le prestaremos ayuda inmediatamente, ya no necesitas seguir preocupándote por su situación.$B$BPero hay una cosa que debo decir, me ha impresionado saber que acabaste con la vida de Sarkoth. Es una hazaña de la que estar $gorgulloso:orgullosa;, $n. Además, el haber luchado por el honor de un desconocido, dejando a un lado tus propias tareas, es, sin duda alguna, todo un signo de honor por tu parte.', 0);
-- 805 Preséntate en el Poblado Sen'jin
-- https://es.classic.wowhead.com/quest=805
SET @ID := 805;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ummm... tu informe llega en mal momento. El Filo Ardiente no ha sido visto por aquí, en Poblado Sen\'jin, pero su mal se ha arraigado en la costa, en las Islas del Eco.$B$BLos orcos son amigos de los trols Lanza Negra. Amigos honorables. Queremos ayudar a los orcos, pero... nosotros también necesitamos ayuda.', 0),
(@ID, 'esMX', 'Ummm... tu informe llega en mal momento. El Filo Ardiente no ha sido visto por aquí, en Poblado Sen\'jin, pero su mal se ha arraigado en la costa, en las Islas del Eco.$B$BLos orcos son amigos de los trols Lanza Negra. Amigos honorables. Queremos ayudar a los orcos, pero... nosotros también necesitamos ayuda.', 0);
-- 806 Oscuras tormentas
-- https://es.classic.wowhead.com/quest=806
SET @ID := 806;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a Fizzle, $n? ¡Él y el resto del Filo Ardiente deben ser expulsados de nuestras tierras!', 0),
(@ID, 'esMX', '¿Encontraste a Fizzle, $n? ¡Él y el resto del Filo Ardiente deben ser expulsados de nuestras tierras!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ajá! ¡Lo encontraste!$B$BTu clan se enorgullece de ti, $n. Y gracias a ti, Durotar se ha librado de un gran mal.', 0),
(@ID, 'esMX', '¡Ajá! ¡Lo encontraste!$B$BTu clan se enorgullece de ti, $n. Y gracias a ti, Durotar se ha librado de un gran mal.', 0);
-- 808 La calavera de Minshina
-- https://es.classic.wowhead.com/quest=808
SET @ID := 808;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la calavera de mi hermano, $n? ¿Está libre al fin?', 0),
(@ID, 'esMX', '¿Tienes la calavera de mi hermano, $n? ¿Está libre al fin?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Has salvado a Minshina. ¡Has salvado al espíritu de mi hermano de la esclavitud!', 0),
(@ID, 'esMX', 'Gracias, $n. Has salvado a Minshina. ¡Has salvado al espíritu de mi hermano de la esclavitud!', 0);
 -- 809 Ak'Zeloth
-- https://es.classic.wowhead.com/quest=809
SET @ID := 809;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Neeru quiere ver destruida la Semilla del Demonio, ¿no es así? Extraño...$B$BMuy bien. Si quiere que desaparezca, te diré qué hay que hacer.', 0),
(@ID, 'esMX', 'Neeru quiere ver destruida la Semilla del Demonio, ¿no es así? Extraño...$B$BMuy bien. Si quiere que desaparezca, te diré qué hay que hacer.', 0);
-- 812 Se necesita un remedio
-- https://es.classic.wowhead.com/quest=812
SET @ID := 812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Casi me alegro de no poder volver a Sen\'jin en este momento. Todos se reirían de mi debilidad y mi estupidez.', 0),
(@ID, 'esMX', 'Casi me alegro de no poder volver a Sen\'jin en este momento. Todos se reirían de mi debilidad y mi estupidez.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, me has salvado la vida. Gracias.$B$BPor favor, acepta esto. Espero que te ayude en tus viajes y, si no es así, quizás puedas sacar algún dinero vendiéndolo. Por lo que dices, yo no voy a volver a usarlo de momento. Kor\'ghan va a hacerme participar en muchos de sus rituales hasta que le demuestre mi valía. Tendré que matar jabalíes, recoger más colas de escórpido... lo de siempre, vaya...', 0),
(@ID, 'esMX', '$n, me has salvado la vida. Gracias.$B$BPor favor, acepta esto. Espero que te ayude en tus viajes y, si no es así, quizás puedas sacar algún dinero vendiéndolo. Por lo que dices, yo no voy a volver a usarlo de momento. Kor\'ghan va a hacerme participar en muchos de sus rituales hasta que le demuestre mi valía. Tendré que matar jabalíes, recoger más colas de escórpido... lo de siempre, vaya...', 0);
-- 813 En busca del antídoto
-- https://es.classic.wowhead.com/quest=813
SET @ID := 813;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda que, sea cual sea la criatura que desees cazar, debes estudiar y entender su comportamiento. Ese conocimiento podría salvarte la vida.', 0),
(@ID, 'esMX', 'Recuerda que, sea cual sea la criatura que desees cazar, debes estudiar y entender su comportamiento. Ese conocimiento podría salvarte la vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes el antídoto, $n. Llévaselo a Rhinag tan aprisa como puedas. Y sé prudente.', 0),
(@ID, 'esMX', 'Aquí tienes el antídoto, $n. Llévaselo a Rhinag tan aprisa como puedas. Y sé prudente.', 0);
-- 815 Romper huevos
-- https://es.classic.wowhead.com/quest=815
SET @ID := 815;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Desayuno, almuerzo, cena! ¿A quién le importa qué comida es? ¡Sea cual sea, alguien tiene que prepararla! Y ese alguien, soy yo.', 0),
(@ID, 'esMX', '¡Desayuno, almuerzo, cena! ¿A quién le importa qué comida es? ¡Sea cual sea, alguien tiene que prepararla! Y ese alguien, soy yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás seas débil, pero desde luego, no eres torpe, $n.$B$BTen, coge esto y quítate de mi vista. Tengo que cocinar.', 0),
(@ID, 'esMX', 'Quizás seas débil, pero desde luego, no eres torpe, $n.$B$BTen, coge esto y quítate de mi vista. Tengo que cocinar.', 0);
-- 816 Perdido, pero no olvidado
-- https://es.classic.wowhead.com/quest=816
SET @ID := 816;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Rezo para que Kron vuelva, aunque creo que ya sé cuál ha sido su suerte.', 0),
(@ID, 'esMX', 'Rezo para que Kron vuelva, aunque creo que ya sé cuál ha sido su suerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, mi hijo... mi querido hijo.$B$BMe he atormentado constantemente desde que se fue, pues no tenía noticias de su suerte. Ahora que sé lo que le ocurrió, quizás pueda empezar a llorarlo.$B$BGracias, $n. Y ten, acepta esto. Iba a dárselo a Kron como regalo, cuando volviera triunfante. Pero ahora que sé que está muerto, no puedo ni mirarlo.', 0),
(@ID, 'esMX', 'Oh, mi hijo... mi querido hijo.$B$BMe he atormentado constantemente desde que se fue, pues no tenía noticias de su suerte. Ahora que sé lo que le ocurrió, quizás pueda empezar a llorarlo.$B$BGracias, $n. Y ten, acepta esto. Iba a dárselo a Kron como regalo, cuando volviera triunfante. Pero ahora que sé que está muerto, no puedo ni mirarlo.', 0);
-- 817 Presa práctica
-- https://es.classic.wowhead.com/quest=817
SET @ID := 817;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún recuerdo la primera vez que cacé un tigre. Elegí cazar en la más grande de las Islas del Eco. Me senté entre el follaje y esperé y esperé... casi un día entero.$B$BTenía los músculos en tensión y preparados para atacar. Y por fin un tigre mordió el anzuelo... fue una de mis mayores victorias.', 0),
(@ID, 'esMX', 'Aún recuerdo la primera vez que cacé un tigre. Elegí cazar en la más grande de las Islas del Eco. Me senté entre el follaje y esperé y esperé... casi un día entero.$B$BTenía los músculos en tensión y preparados para atacar. Y por fin un tigre mordió el anzuelo... fue una de mis mayores victorias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy satisfecho, $n. Con tu ayuda, nuestra gente estará protegida y no pasará frío cuando cambie la estación.$B$BGracias.', 0),
(@ID, 'esMX', 'Estoy satisfecho, $n. Con tu ayuda, nuestra gente estará protegida y no pasará frío cuando cambie la estación.$B$BGracias.', 0);
-- 754 La purificación de Pezuña Invernal
-- https://es.classic.wowhead.com/quest=754
SET @ID := 754;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te retrases, $n. ¡Hay que purificar el Pozo Pezuña Invernal!', 0),
(@ID, 'esMX', 'No te retrases, $n. ¡Hay que purificar el Pozo Pezuña Invernal!', 0);
-- 6002 Cuerpo y corazón
-- https://es.classic.wowhead.com/quest=6002
SET @ID := 6002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas superado el desafío que te espera, tu comprensión de la fuerza del cuerpo y la fuerza del corazón se harán plenamente conscientes. Hasta ese momento, no puedo ayudarte más.', 0),
(@ID, 'esMX', 'Cuando hayas superado el desafío que te espera, tu comprensión de la fuerza del cuerpo y la fuerza del corazón se harán plenamente conscientes. Hasta ese momento, no puedo ayudarte más.', 0);
