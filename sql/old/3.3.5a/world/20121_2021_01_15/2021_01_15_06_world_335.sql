-- 1957 Oleadas de maná
-- https://es.classic.wowhead.com/quest=1957
SET @ID := 1957;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No has eliminado la cantidad necesaria de oleadas de maná, $n.', 0),
(@ID, 'esMX', 'No has eliminado la cantidad necesaria de oleadas de maná, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! ¡Nunca dudé de ti ni por un segundo! Ok, tal vez solo por un segundo, o dos... pero básicamente no tenía muchas dudas.$B$BHonestamente.', 0),
(@ID, 'esMX', '¡Lo hiciste! ¡Nunca dudé de ti ni por un segundo! Ok, tal vez solo por un segundo, o dos... pero básicamente no tenía muchas dudas.$B$BHonestamente.', 0);
-- 1958 Poder celestial
-- https://es.classic.wowhead.com/quest=1958
SET @ID := 1958;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deberías estar $gorgulloso de ti mismo:orgullosa de ti misma;, $n. Muchos magos han caído ante las criaturas a las que te enfrentaste.$B$BEl Orbe Celestial está listo. O si lo deseas, puedo montarlo sobre un bastón. Tu decides. Preferiría el orbe, pero ¿quién soy yo para juzgar?', 0),
(@ID, 'esMX', 'Deberías estar $gorgulloso de ti mismo:orgullosa de ti misma;, $n. Muchos magos han caído ante las criaturas a las que te enfrentaste.$B$BEl Orbe Celestial está listo. O si lo deseas, puedo montarlo sobre un bastón. Tu decides. Preferiría el orbe, pero ¿quién soy yo para juzgar?', 0);
-- 1959 Preséntate ante Anastasia
-- https://es.classic.wowhead.com/quest=1959
SET @ID := 1959;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es cierto. Se ha detectado una alteración mágica en nuestra ciudad. Todavía no estamos seguros de su origen, si es maligna o benigna. Antes debemos reunir más información...$B$BY esto, $n, nos lleva a hablar de tu tarea.', 0),
(@ID, 'esMX', 'Es cierto. Se ha detectado una alteración mágica en nuestra ciudad. Todavía no estamos seguros de su origen, si es maligna o benigna. Antes debemos reunir más información...$B$BY esto, $n, nos lleva a hablar de tu tarea.', 0);
-- 1960 Investiga la tienda de alquimia
-- https://es.classic.wowhead.com/quest=1960
SET @ID := 1960;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has investigado la alteración, $n? ¿Has capturado a las criaturas?', 0),
(@ID, 'esMX', '¿Has investigado la alteración, $n? ¿Has capturado a las criaturas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Nuestras mentes más preclaras estudiarán las criaturas que hay en el interior de estas arcas de contención y determinarán los motivos de su presencia en Entrañas.$B$BSi su aparición es el resultado de una falla en el flujo natural de la magia debemos determinar si esa falla fue aleatoria. Si no lo fue, y fue producto del ataque de alguna fuerza mágica, nos prepararemos para alteraciones futuras y más serias.', 0),
(@ID, 'esMX', 'Muy bien, $n. Nuestras mentes más preclaras estudiarán las criaturas que hay en el interior de estas arcas de contención y determinarán los motivos de su presencia en Entrañas.$B$BSi su aparición es el resultado de una falla en el flujo natural de la magia debemos determinar si esa falla fue aleatoria. Si no lo fue, y fue producto del ataque de alguna fuerza mágica, nos prepararemos para alteraciones futuras y más serias.', 0);
-- 1961 Recolección de materiales
-- https://es.classic.wowhead.com/quest=1961
SET @ID := 1961;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Anastasia dijo que vendrías a verme, estoy listo para elaborar tu túnica. ¿Tienes las gemas y el lino?', 0),
(@ID, 'esMX', 'Anastasia dijo que vendrías a verme, estoy listo para elaborar tu túnica. ¿Tienes las gemas y el lino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un material excelente y aunque no tengo el talento necesario para valorar la calidad de estas gemas de maná, pronto sabremos si poseen el poder necesario para crear togas del fuegohechizo...', 0),
(@ID, 'esMX', 'Es un material excelente y aunque no tengo el talento necesario para valorar la calidad de estas gemas de maná, pronto sabremos si poseen el poder necesario para crear togas del fuegohechizo...', 0);
-- 1963 Mano Destrozada
-- https://es.classic.wowhead.com/quest=1963
SET @ID := 1963;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo un necio cree que hay más peligro en un ataque frontal con un hacha que en una daga en la oscuridad.', 0),
(@ID, 'esMX', 'Solo un necio cree que hay más peligro en un ataque frontal con un hacha que en una daga en la oscuridad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que Tazan haya muerto, pero una cartera cerrada no me sirve de nada.$B$BParece un buen desafío para quien aspira a ingresar en la Mano Destrozada.', 0),
(@ID, 'esMX', 'Me alegro de que Tazan haya muerto, pero una cartera cerrada no me sirve de nada.$B$BParece un buen desafío para quien aspira a ingresar en la Mano Destrozada.', 0);
-- 1978 Los mortacechadores
-- https://es.classic.wowhead.com/quest=1978
SET @ID := 1978;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, qué interesante... Los mortacechadores han hecho un buen trabajo al descubrir esto.$B$BPor lo que sé, a ti también te corresponde una mención honorífica. Espero que lo sigas haciendo igual de bien, $n, pues serás de gran ayuda para los mortacechadores.', 0),
(@ID, 'esMX', 'Mmm, qué interesante... Los mortacechadores han hecho un buen trabajo al descubrir esto.$B$BPor lo que sé, a ti también te corresponde una mención honorífica. Espero que lo sigas haciendo igual de bien, $n, pues serás de gran ayuda para los mortacechadores.', 0);
-- 1998 Fenwick Thatros
-- https://es.classic.wowhead.com/quest=1998
SET @ID := 1998;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He depositado la mayor fe en ti para realizar este servicio para Lord Varimathras.', 0),
(@ID, 'esMX', 'He depositado la mayor fe en ti para realizar este servicio para Lord Varimathras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Se me ocurre que has prestado muchos servicios a los Mortacechadores, demostrando tu valía, y que quizás es hora de que ampliemos tu formación en las artes de las sombras.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Se me ocurre que has prestado muchos servicios a los Mortacechadores, demostrando tu valía, y que quizás es hora de que ampliemos tu formación en las artes de las sombras.', 0);
-- 1999 Herramientas de comercio
-- https://es.classic.wowhead.com/quest=1999
SET @ID := 1999;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has localizado los documentos, $N?', 0),
(@ID, 'esMX', '¿Has localizado los documentos, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Has aprendido bien el fino arte de forzar cerraduras y más rápido de lo que yo esperaba.$B$BVeo que hice bien en depositar mi confianza en ti. Créeme, $gmuchacho:muchacha;, preveo que llegarás lejos en esta línea de trabajo.', 0),
(@ID, 'esMX', '¡Muy bien, $n! Has aprendido bien el fino arte de forzar cerraduras y más rápido de lo que yo esperaba.$B$BVeo que hice bien en depositar mi confianza en ti. Créeme, $gmuchacho:muchacha;, preveo que llegarás lejos en esta línea de trabajo.', 0);
-- 2041 Habla con Shoni
-- https://es.classic.wowhead.com/quest=2041
SET @ID := 2041;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes un mensaje?', 0),
(@ID, 'esMX', '¿Me traes un mensaje?', 0);
-- 2078 La venganza de Gyromast
-- https://es.classic.wowhead.com/quest=2078
SET @ID := 2078;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'El contramaestre de Gelkak', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde estará mi contgramaestre, $n? ¡Grilletes y tiburones para ti pronto si no te apresuras!', 0),
(@ID, 'esMX', '¿Dónde estará mi contgramaestre, $n? ¡Grilletes y tiburones para ti pronto si no te apresuras!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eeeeeh! Has demostrado ser casi un perro de mar, marinero de agua dulce.$B$BPuede que el capitán te ascienda a limpiador de la cubierta de popa si sigues así...', 0),
(@ID, 'esMX', '¡Eeeeeh! Has demostrado ser casi un perro de mar, marinero de agua dulce.$B$BPuede que el capitán te ascienda a limpiador de la cubierta de popa si sigues así...', 0);
-- 2098 La búsqueda de Gyromast
-- https://es.classic.wowhead.com/quest=2098
SET @ID := 2098;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mi llave, marinero de agua dulce?', 0),
(@ID, 'esMX', '¿Has encontrado mi llave, marinero de agua dulce?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, marinero de agua dulce! ¡Lo conseguiste! ¡Dentro de nada mi contramaestre volverá a estar en pie y esas bestias no sabrán ni de dónde les llegó el golpe!$B$BEste... ¿has visto a mi contramaestre?', 0),
(@ID, 'esMX', '¡Eh, marinero de agua dulce! ¡Lo conseguiste! ¡Dentro de nada mi contramaestre volverá a estar en pie y esas bestias no sabrán ni de dónde les llegó el golpe!$B$BEste... ¿has visto a mi contramaestre?', 0);
-- 2118 Tierras apestadas
-- https://es.classic.wowhead.com/quest=2118
SET @ID := 2118;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Oso Cardo rabioso capturado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 2161 Un cargamento de peón
-- https://es.classic.wowhead.com/quest=2161
SET @ID := 2161;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bienvenido a Cerrotajo!', 0),
(@ID, 'esMX', '¡Bienvenido a Cerrotajo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esta es la comida que Ukor llevó al Valle de los Retos. ¿No les hacía falta? Pues será que les gusta matar a los héroes de hambre mientras los entrenan. ¡Fortalece el espíritu, según dicen!$B$BGracias por traerme la comida. La pondré de nuevo en las estanterías... ¡Pero primero deja que te ofrezca un tentempié!$B$BY no olvides ir a descansar a la posada. Seguro que estás deseando comerte el mundo, pero si te falta energía, no podrás hacer gran cosa, ni por ti ni por la Horda.', 0),
(@ID, 'esMX', 'Ah, esta es la comida que Ukor llevó al Valle de los Retos. ¿No les hacía falta? Pues será que les gusta matar a los héroes de hambre mientras los entrenan. ¡Fortalece el espíritu, según dicen!$B$BGracias por traerme la comida. La pondré de nuevo en las estanterías... ¡Pero primero deja que te ofrezca un tentempié!$B$BY no olvides ir a descansar a la posada. Seguro que estás deseando comerte el mundo, pero si te falta energía, no podrás hacer gran cosa, ni por ti ni por la Horda.', 0);
-- 2199 Esa información tiene un precio
-- https://es.classic.wowhead.com/quest=2199
SET @ID := 2199;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los 5 lingotes de plata? Si no, no te contaré la historia del collar. ¡Ayuda a este gnomo!', 0),
(@ID, 'esMX', '¿Traes los 5 lingotes de plata? Si no, no te contaré la historia del collar. ¡Ayuda a este gnomo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No eres mala gente, pese a lo que dicen por ahí... ¡Es broma! En serio, gracias.$B$BEl collar es una de mis mejores obras, pero le faltan las 3 gemas con las que se imbuye de poder mágico. Lo diseñé para un paladín hace mucho; libraba una cruzada para limpiar la "corrupción" de Uldaman, en las Tierras Inhóspitas.$B$BMurió allí y entonces empezaron mis problemas.', 0),
(@ID, 'esMX', 'No eres mala gente, pese a lo que dicen por ahí... ¡Es broma! En serio, gracias.$B$BEl collar es una de mis mejores obras, pero le faltan las 3 gemas con las que se imbuye de poder mágico. Lo diseñé para un paladín hace mucho; libraba una cruzada para limpiar la "corrupción" de Uldaman, en las Tierras Inhóspitas.$B$BMurió allí y entonces empezaron mis problemas.', 0);
-- 2200 El regreso a Uldaman
-- https://es.classic.wowhead.com/quest=2200
SET @ID := 2200;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El diario revela que el paladín consiguió localizar las 3 gemas del collar:$B$Blos enanos Forjatiniebla tenían el rubí en zona segura durante su lucha contra los troggs.$B$BEstos, a su vez, guardaban el topacio en una urna situada cerca de enanos de la Alianza.$B$BY el ancestro trogg se quedó el zafiro para sí.', 0),
(@ID, 'esMX', 'El diario revela que el paladín consiguió localizar las 3 gemas del collar:$B$Blos enanos Forjatiniebla tenían el rubí en zona segura durante su lucha contra los troggs.$B$BEstos, a su vez, guardaban el topacio en una urna situada cerca de enanos de la Alianza.$B$BY el ancestro trogg se quedó el zafiro para sí.', 0);
-- 2201 Encuentra las gemas
-- https://es.classic.wowhead.com/quest=2201
SET @ID := 2201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La imagen de Talvash se dibuja en las aguas del cuenco de visión.$B$B"¡Vaya, todavía sigues con vida! ¿Encontraste mis gemas? ¿Eres quien va a salvar mi reputación, $gese:esa; a quien he estado esperando? Por favor, dime que no has desperdiciado una recarga de la ampolla solo para hablar de tonterías... Son muy caras y lo cierto es que no gozo precisamente de una buena situación económica."', 0),
(@ID, 'esMX', 'La imagen de Talvash se dibuja en las aguas del cuenco de visión.$B$B"¡Vaya, todavía sigues con vida! ¿Encontraste mis gemas? ¿Eres quien va a salvar mi reputación, $gese:esa; a quien he estado esperando? Por favor, dime que no has desperdiciado una recarga de la ampolla solo para hablar de tonterías... Son muy caras y lo cierto es que no gozo precisamente de una buena situación económica."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Efectivamente, esas son las tres gemas. ¡Buen trabajo! Por desgracia, tu trabajo no acaba aquí.$B$BNo, no estoy intentando jugarte una mala pasada. El objetivo es hacer joyas mágicas de calidad, ¡de la calidad que solo puede proporcionar Talvash del Kissel! Necesitarás una potente fuente de energía para darle vidilla a ese collar.', 0),
(@ID, 'esMX', 'Efectivamente, esas son las tres gemas. ¡Buen trabajo! Por desgracia, tu trabajo no acaba aquí.$B$BNo, no estoy intentando jugarte una mala pasada. El objetivo es hacer joyas mágicas de calidad, ¡de la calidad que solo puede proporcionar Talvash del Kissel! Necesitarás una potente fuente de energía para darle vidilla a ese collar.', 0);
-- 2202 Componentes de Uldaman
-- https://es.classic.wowhead.com/quest=2202
SET @ID := 2202;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las setas moradas que necesito para mis proyectos de alquimia? Si no hay setas, ¡no hay premio!', 0),
(@ID, 'esMX', '¿Has conseguido las setas moradas que necesito para mis proyectos de alquimia? Si no hay setas, ¡no hay premio!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n, ¡has vuelto a demostrar tu valía! Será interesante estudiar las setas, apuesto lo que sea.$B$BY ahora, lo prometido es deuda, disfruta de un trago de uno de mis brebajes de recuperación más eficaces de mi colección privada...$B$BSi eres un hábil alquimista, quizás podamos compartir algún negocio más. Sea como fuere, ¡agredecido quedo por tu ayuda!', 0),
(@ID, 'esMX', 'Muy bien, $n, ¡has vuelto a demostrar tu valía! Será interesante estudiar las setas, apuesto lo que sea.$B$BY ahora, lo prometido es deuda, disfruta de un trago de uno de mis brebajes de recuperación más eficaces de mi colección privada...$B$BSi eres un hábil alquimista, quizás podamos compartir algún negocio más. Sea como fuere, ¡agredecido quedo por tu ayuda!', 0);
-- 2203 Componentes de Tierras Inhóspitas II
-- https://es.classic.wowhead.com/quest=2203
SET @ID := 2203;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has usado los vasos para conseguirme la sangre de dragón guardián quemada que necesito? Sí, sé que es una tarea peligrosa... pero la receta de mi bebida reconstituyente aguarda su éxito. Riesgo y recompensa, $gamigo mío:amiga mía;... riesgo y recompensa...', 0),
(@ID, 'esMX', '¿Has usado los vasos para conseguirme la sangre de dragón guardián quemada que necesito? Sí, sé que es una tarea peligrosa... pero la receta de mi bebida reconstituyente aguarda su éxito. Riesgo y recompensa, $gamigo mío:amiga mía;... riesgo y recompensa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De un alquimista a otro, te saludo. Toma esta receta y apréndela. Que te traiga el éxito y las recompensas que me ha brindado a lo largo de los años.', 0),
(@ID, 'esMX', 'De un alquimista a otro, te saludo. Toma esta receta y apréndela. Que te traiga el éxito y las recompensas que me ha brindado a lo largo de los años.', 0);
-- 2204 Restaurar el collar
-- https://es.classic.wowhead.com/quest=2204
SET @ID := 2204;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera te detuviste a arreglarte después de dejar Uldaman, ¿verdad? Acabas de venir directamente aquí, al diablo con los persistentes olores de las mazmorras. Bueno, esperemos que esta visita sea meramente odiosa y no inútil para empezar.$B$B¿Tienes la fuente de energía para el collar?', 0),
(@ID, 'esMX', 'Ni siquiera te detuviste a arreglarte después de dejar Uldaman, ¿verdad? Acabas de venir directamente aquí, al diablo con los persistentes olores de las mazmorras. Bueno, esperemos que esta visita sea meramente odiosa y no inútil para empezar.$B$B¿Tienes la fuente de energía para el collar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno. Me alegra verte a ti y a esta fuente de energía en una sola pieza. Me tomará un momento fusionar mágicamente la fuente de energía con el collar ahora que las gemas ya se han unido a él. Sin embargo, una vez hecho esto, ¡el collar será tuyo!$B$BEstás $gemocionado:emocionada;, ¿no? ¿Todo hormigueo por la anticipación? Ahora, ¿dónde puse ese enfoque de hechizo en...', 0),
(@ID, 'esMX', 'Bueno. Me alegra verte a ti y a esta fuente de energía en una sola pieza. Me tomará un momento fusionar mágicamente la fuente de energía con el collar ahora que las gemas ya se han unido a él. Sin embargo, una vez hecho esto, ¡el collar será tuyo!$B$BEstás $gemocionado:emocionada;, ¿no? ¿Todo hormigueo por la anticipación? Ahora, ¿dónde puse ese enfoque de hechizo en...', 0);
-- 2218 El camino hacia la salvación
-- https://es.classic.wowhead.com/quest=2218
SET @ID := 2218;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que te consideras un bribón? ¿Destinado a convertirte en uno de los elegidos de Barbanegra... un oficial del Círculo Oculto?$B$BSolo un pillo redomado se lo tendría así de creído.$B$B¡Y eso es exactamente lo que buscamos! ¡$gBienvenido:Bienvenida; a bordo, $n!', 0),
(@ID, 'esMX', '¿Así que te consideras un bribón? ¿Destinado a convertirte en uno de los elegidos de Barbanegra... un oficial del Círculo Oculto?$B$BSolo un pillo redomado se lo tendría así de creído.$B$B¡Y eso es exactamente lo que buscamos! ¡$gBienvenido:Bienvenida; a bordo, $n!', 0);
-- 2238 Un simple subterfugio
-- https://es.classic.wowhead.com/quest=2238
SET @ID := 2238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Shhhh! Más bajo. Nos escucharán.', 0),
(@ID, 'esMX', '¡Shhhh! Más bajo. Nos escucharán.', 0);
-- 2239 El informe de Onin
-- https://es.classic.wowhead.com/quest=2239
SET @ID := 2239;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Disfrutasteis del hedor del gnomo leproso? Solo pregunto porque tienes una sonrisa loca en tu rostro.$B$B¿Qué noticias traéis de Onin?', 0),
(@ID, 'esMX', '¿Disfrutasteis del hedor del gnomo leproso? Solo pregunto porque tienes una sonrisa loca en tu rostro.$B$B¿Qué noticias traéis de Onin?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un largo camino? ¡En nombre de mi propia barba!$B$BHiciste bien, $n. Toma esta daga y vete. El Círculo te llamará de nuevo cuando el paso tres esté listo para ponerse en marcha.$B$B¿Cuál es el paso tres? Viene justo después del paso dos: yo poniendo la bota en tu trasero.$B$B¿$gInteresado:Interesada;?', 0),
(@ID, 'esMX', '¿Un largo camino? ¡En nombre de mi propia barba!$B$BHiciste bien, $n. Toma esta daga y vete. El Círculo te llamará de nuevo cuando el paso tres esté listo para ponerse en marcha.$B$B¿Cuál es el paso tres? Viene justo después del paso dos: yo poniendo la bota en tu trasero.$B$B¿$gInteresado:Interesada;?', 0);
-- 2241 Cuando cae la manzana
-- https://es.classic.wowhead.com/quest=2241
SET @ID := 2241;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¿no es maravilloso? Has traído flores para tu propio funeral.', 0),
(@ID, 'esMX', 'Oh, ¿no es maravilloso? Has traído flores para tu propio funeral.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si hubiera guardado todas las flores que ese idiota, Jannok, me ha enviado, habría tenido los medios para abrir una tienda. Por otro lado, parece que el último mensajero de Jannok puede resultar útil. ¿Estás $ginteresado:interesada; en algún trabajo, $c?', 0),
(@ID, 'esMX', 'Si hubiera guardado todas las flores que ese idiota, Jannok, me ha enviado, habría tenido los medios para abrir una tienda. Por otro lado, parece que el último mensajero de Jannok puede resultar útil. ¿Estás $ginteresado:interesada; en algún trabajo, $c?', 0);
-- 2242 La llamada del destino
-- https://es.classic.wowhead.com/quest=2242
SET @ID := 2242;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ha dicho algo Sethir el Ancestro, $n?', 0),
(@ID, 'esMX', '¿Te ha dicho algo Sethir el Ancestro, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son malas noticias, $n. Parece que la enfermedad que se ha apoderado de los bosques y los ríos de Costa Oscura ha empezado a extenderse por nuestro hogar.$B$BNos has servido con diligencia pero ya no hay nada más que puedas hacer aquí. Coge esta espada como recompensa por tu ayuda a Teldrassil.', 0),
(@ID, 'esMX', 'Son malas noticias, $n. Parece que la enfermedad que se ha apoderado de los bosques y los ríos de Costa Oscura ha empezado a extenderse por nuestro hogar.$B$BNos has servido con diligencia pero ya no hay nada más que puedas hacer aquí. Coge esta espada como recompensa por tu ayuda a Teldrassil.', 0);
-- 2258 Componentes de Tierras Inhóspitas
-- https://es.classic.wowhead.com/quest=2258
SET @ID := 2258;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las cosas que necesitaba? No te pagaré a menos que hayas traído esos componentes.', 0),
(@ID, 'esMX', '¿Tienes las cosas que necesitaba? No te pagaré a menos que hayas traído esos componentes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, muy bien! Me deberían durar una temporada, al menos. Aquí tienes el pago que te prometí.$B$BSi te interesa, no me vendrían mal otros componentes. Aunque estos solo se encuentran en lo más profundo de la excavación de Uldaman. No serán fáciles de conseguir pero haré que merezca la pena si te apetece volver a ayudarme.$B$BQuizás algo más que unas relucientes monedas, ¿qué te parece?', 0),
(@ID, 'esMX', '¡Ah, muy bien! Me deberían durar una temporada, al menos. Aquí tienes el pago que te prometí.$B$BSi te interesa, no me vendrían mal otros componentes. Aunque estos solo se encuentran en lo más profundo de la excavación de Uldaman. No serán fáciles de conseguir pero haré que merezca la pena si te apetece volver a ayudarme.$B$BQuizás algo más que unas relucientes monedas, ¿qué te parece?', 0);
-- 2259 Erion Sombrusurro
-- https://es.classic.wowhead.com/quest=2259
SET @ID := 2259;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es hora de diversificarse, $r, el mundo espera.', 0),
(@ID, 'esMX', 'Es hora de diversificarse, $r, el mundo espera.', 0);
-- 2260 La orden de Erion
-- https://es.classic.wowhead.com/quest=2260
SET @ID := 2260;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has respondido al llamado de IV:7, $n y viajaste desde costas distantes para unirte a nuestras filas, sin embargo, hay mucho que aprender.', 0),
(@ID, 'esMX', 'Has respondido al llamado de IV:7, $n y viajaste desde costas distantes para unirte a nuestras filas, sin embargo, hay mucho que aprender.', 0);
-- 2278 Los discos de platino
-- https://es.classic.wowhead.com/quest=2278
SET @ID := 2278;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La voz del vigía de piedra resuena en tu interior:$B$B"En primer lugar tendrás que asimilar la información contenida en los Discos de Norgannon. Una vez cumplido este requisito, podrás optar a una copia de los datos aquí guardados. Asegúrate de revisar toda la información que encontrarás aquí antes de proseguir."', 0),
(@ID, 'esMX', 'La voz del vigía de piedra resuena en tu interior:$B$B"En primer lugar tendrás que asimilar la información contenida en los Discos de Norgannon. Una vez cumplido este requisito, podrás optar a una copia de los datos aquí guardados. Asegúrate de revisar toda la información que encontrarás aquí antes de proseguir."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siguiendo las indicaciones del vigía de piedra, accedes de nuevo a los discos de Norgannon ahora que ya conoces la historia de los terráneos, los troggs y los enanos. Se oye un susurro que proviene del interior de los discos. Entonces, el vigía de piedra habla de nuevo:$B$B"Los discos han sido sintetizados. Accede de nuevo a los discos de Norgannon para recibir una copia personal."', 0),
(@ID, 'esMX', 'Siguiendo las indicaciones del vigía de piedra, accedes de nuevo a los discos de Norgannon ahora que ya conoces la historia de los terráneos, los troggs y los enanos. Se oye un susurro que proviene del interior de los discos. Entonces, el vigía de piedra habla de nuevo:$B$B"Los discos han sido sintetizados. Accede de nuevo a los discos de Norgannon para recibir una copia personal."', 0);
-- 2279 Los discos de platino
-- https://es.classic.wowhead.com/quest=2279
SET @ID := 2279;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte en algo? Te aseguro que tengo mucho que hacer. Sin embargo, si se trata de algo importante para la Liga de Expedicionarios... ¡entonces soy todo oídos!', 0),
(@ID, 'esMX', '¿Puedo ayudarte en algo? Te aseguro que tengo mucho que hacer. Sin embargo, si se trata de algo importante para la Liga de Expedicionarios... ¡entonces soy todo oídos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí? ¡Vaya! ¿Dónde encontraste esto?$B$B¿De verdad?$B$B¿Qué hablaste de qué con quién?$B$B¡NO PUEDE SER VERDAD!$B$BMi $gquerido:querida; $c, ¡este puede ser el descubrimiento arqueológico del año! ¿¡Qué digo del año!? ¡Del siglo! Si estos discos son lo que creo que son, ¡tenemos delante la última pieza del rompecabezas! Esto podría demostrar de una vez por todas la legitimidad de la creación encantada de los enanos.', 0),
(@ID, 'esMX', '¿Qué tienes ahí? ¡Vaya! ¿Dónde encontraste esto?$B$B¿De verdad?$B$B¿Qué hablaste de qué con quién?$B$B¡NO PUEDE SER VERDAD!$B$BMi $gquerido:querida; $c, ¡este puede ser el descubrimiento arqueológico del año! ¿¡Qué digo del año!? ¡Del siglo! Si estos discos son lo que creo que son, ¡tenemos delante la última pieza del rompecabezas! Esto podría demostrar de una vez por todas la legitimidad de la creación encantada de los enanos.', 0);
-- 2280 Los discos de platino
-- https://es.classic.wowhead.com/quest=2280
SET @ID := 2280;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí joven, veo que entras en mi tienda de campaña con paso firme... y con marcada determinación. ¿Vienes a pedir mi consejo acerca de algún tema de gran importancia para la Horda? ¿O quizás deseas que te revele un misterio del universo?', 0),
(@ID, 'esMX', 'Sí joven, veo que entras en mi tienda de campaña con paso firme... y con marcada determinación. ¿Vienes a pedir mi consejo acerca de algún tema de gran importancia para la Horda? ¿O quizás deseas que te revele un misterio del universo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto?$B$B¡Impresionante, joven! Estos discos encierran grandes secretos de la tierra que han permanecido ocultos durante años. Ha sido muy inteligente por tu parte habérmelos traído.', 0),
(@ID, 'esMX', '¿Qué es esto?$B$B¡Impresionante, joven! Estos discos encierran grandes secretos de la tierra que han permanecido ocultos durante años. Ha sido muy inteligente por tu parte habérmelos traído.', 0);
