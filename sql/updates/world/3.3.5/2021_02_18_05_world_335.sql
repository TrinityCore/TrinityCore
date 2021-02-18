-- 5725 Poder destructivo
-- https://es.classic.wowhead.com/quest=5725
SET @ID := 5725;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchas cosas de las que ocuparme, $c. ¿Tienes los libros?', 0),
(@ID, 'esMX', 'Tengo muchas cosas de las que ocuparme, $c. ¿Tienes los libros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, $c. Has servido con eficacia a la Dama Oscura. Tu perseverancia y ambición serán de gran utilidad para ella. Ven a verme más adelante pues es posible que tenga otras tareas para ti con las que puedas ayudar a la Dama Oscura a derrotar al rey Exánime y liberar totalmente a la Plaga.', 0),
(@ID, 'esMX', 'Bien, $c. Has servido con eficacia a la Dama Oscura. Tu perseverancia y ambición serán de gran utilidad para ella. Ven a verme más adelante pues es posible que tenga otras tareas para ti con las que puedas ayudar a la Dama Oscura a derrotar al rey Exánime y liberar totalmente a la Plaga.', 0);
-- 5726 Enemigos ocultos
-- https://es.classic.wowhead.com/quest=5726
SET @ID := 5726;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la insignia, $n?$B$BLa necesitamos para infiltrarnos en lo que creo que es la mayor amenaza para la Horda y conseguir la paz.$B$BDescubrirás los extremos a los que orcos y humanos pueden llegar cuando los motiva el ansia de poder y la codicia. Te encontrarás en medio de una guerra cuya existencia no sospechabas.', 0),
(@ID, 'esMX', '¿Traes la insignia, $n?$B$BLa necesitamos para infiltrarnos en lo que creo que es la mayor amenaza para la Horda y conseguir la paz.$B$BDescubrirás los extremos a los que orcos y humanos pueden llegar cuando los motiva el ansia de poder y la codicia. Te encontrarás en medio de una guerra cuya existencia no sospechabas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que los espíritus te bendigan, $n, puede que seas tú quien vaya a librarme de mi mayor temor. Me recuerdas a mí mismo cuando tenía tu edad. Daré órdenes para que recibas la recompensa apropiada si sobrevivimos a lo que se avecina.$B$BPero ya tendremos tiempo para alabanzas; comparado con lo que te espera, aún no has hecho nada... Pero has empezado bien.', 0),
(@ID, 'esMX', 'Que los espíritus te bendigan, $n, puede que seas tú quien vaya a librarme de mi mayor temor. Me recuerdas a mí mismo cuando tenía tu edad. Daré órdenes para que recibas la recompensa apropiada si sobrevivimos a lo que se avecina.$B$BPero ya tendremos tiempo para alabanzas; comparado con lo que te espera, aún no has hecho nada... Pero has empezado bien.', 0);
-- 5727 Enemigos ocultos
-- https://es.classic.wowhead.com/quest=5727
SET @ID := 5727;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien, $c? ¿Te creyó o las cosas están peor de lo que yo pensaba?$B$BDemuestra tu valor ante Neeru y te será mucho más fácil infiltrarte en el Consejo de la Sombra. Te dará información que nos ayudará a destruir a nuestros enemigos.', 0),
(@ID, 'esMX', '¿Y bien, $c? ¿Te creyó o las cosas están peor de lo que yo pensaba?$B$BDemuestra tu valor ante Neeru y te será mucho más fácil infiltrarte en el Consejo de la Sombra. Te dará información que nos ayudará a destruir a nuestros enemigos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $c!$B$BLo que has conseguido hoy no es más que el primer paso de un largo camino que nos llevará a destruir el Consejo de la Sombra.$B$BCuéntame todo lo que dijo y no te dejes ni una coma; todo puede ser importante.', 0),
(@ID, 'esMX', '¡Excelente, $c!$B$BLo que has conseguido hoy no es más que el primer paso de un largo camino que nos llevará a destruir el Consejo de la Sombra.$B$BCuéntame todo lo que dijo y no te dejes ni una coma; todo puede ser importante.', 0);
-- 5728 Enemigos ocultos
-- https://es.classic.wowhead.com/quest=5728
SET @ID := 5728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya los has encontrado, $n? Los líderes de la Hoja Abrasadora.$B$BSabía que el Consejo de la Sombra buscaba arrebatarme Orgrimmar y a toda la Horda, pero no me había dado cuenta de lo rápido que pudieron infiltrarse en la ciudad. Tantos brazos tiene esta bestia... podemos cortarlos hasta que llegue el cansancio, pero no estaremos más allá de cuando empezamos. Tendré que hacer que mis espías redoblen sus esfuerzos.', 0),
(@ID, 'esMX', '¿Ya los has encontrado, $n? Los líderes de la Hoja Abrasadora.$B$BSabía que el Consejo de la Sombra buscaba arrebatarme Orgrimmar y a toda la Horda, pero no me había dado cuenta de lo rápido que pudieron infiltrarse en la ciudad. Tantos brazos tiene esta bestia... podemos cortarlos hasta que llegue el cansancio, pero no estaremos más allá de cuando empezamos. Tendré que hacer que mis espías redoblen sus esfuerzos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. Al parecer, ahora que los líderes han muerto reina el caos en las cavernas de Orgrimmar. He oído decir que Neeru estaba muy agitado; hemos hecho diana. Aunque la victoria sea pírrica, es una victoria.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. Al parecer, ahora que los líderes han muerto reina el caos en las cavernas de Orgrimmar. He oído decir que Neeru estaba muy agitado; hemos hecho diana. Aunque la victoria sea pírrica, es una victoria.', 0);
-- 5729 Enemigos ocultos
-- https://es.classic.wowhead.com/quest=5729
SET @ID := 5729;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres? Oh, $c, disculpa. Estoy furioso como un kodo con dolor de muelas, pero es culpa mía. Debí prever las consecuencias de enviar a gente a la Sima Ígnea. Parece que Bazzalan y Jergosh fueron asesinados por algún enviado de Thrall. Qué inoportuno, pero ya no se puede hacer nada.', 0),
(@ID, 'esMX', '¿Qué quieres? Oh, $c, disculpa. Estoy furioso como un kodo con dolor de muelas, pero es culpa mía. Debí prever las consecuencias de enviar a gente a la Sima Ígnea. Parece que Bazzalan y Jergosh fueron asesinados por algún enviado de Thrall. Qué inoportuno, pero ya no se puede hacer nada.', 0);
-- 5730 Enemigos ocultos
-- https://es.classic.wowhead.com/quest=5730
SET @ID := 5730;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sabía que Filo Ardiente estuviera en Vallefresno. Mis espías se encargarán. Buen trabajo, $n.$B$BAhora descansa y dedícate a otras tareas; te llamaré pronto.$B$B¡Lok-Tar Ogar!', 0),
(@ID, 'esMX', 'No sabía que Filo Ardiente estuviera en Vallefresno. Mis espías se encargarán. Buen trabajo, $n.$B$BAhora descansa y dedícate a otras tareas; te llamaré pronto.$B$B¡Lok-Tar Ogar!', 0);
-- 5742 Redención
-- https://es.classic.wowhead.com/quest=5742
SET @ID := 5742;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor $gamigo:amiga;; siéntate y escucha mi historia.', 0),
(@ID, 'esMX', 'Por favor $gamigo:amiga;; siéntate y escucha mi historia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La redención de Fordring será una tarea difícil. ¿Estás $gpreparado:preparada;?', 0),
(@ID, 'esMX', 'La redención de Fordring será una tarea difícil. ¿Estás $gpreparado:preparada;?', 0);
-- 5761 Matar a la bestia
-- https://es.classic.wowhead.com/quest=5761
SET @ID := 5761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has aniquilado ya a la bestia? Debía de ser el jefe de Filo Ardiente en la Sima Ígnea.', 0),
(@ID, 'esMX', '¿Has aniquilado ya a la bestia? Debía de ser el jefe de Filo Ardiente en la Sima Ígnea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico! Thrall estará encantado.$B$BVoy a poner el corazón a buen recaudo.$B$BDe momento, celebra tu victoria; yo voy a comunicársela a Thrall.$B$BGracias, $c.', 0),
(@ID, 'esMX', '¡Magnífico! Thrall estará encantado.$B$BVoy a poner el corazón a buen recaudo.$B$BDe momento, celebra tu victoria; yo voy a comunicársela a Thrall.$B$BGracias, $c.', 0);
-- 5763 La caza en Tuercespina
-- https://es.classic.wowhead.com/quest=5763
SET @ID := 5763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siéntate, $c. No tardarás en volver a la jungla.', 0),
(@ID, 'esMX', 'Siéntate, $c. No tardarás en volver a la jungla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, este cuerno es de un tauren, Roon Ferocrín. Pasamos buenos ratos dando caza a las bestias de Desolace. Así que Roon me invita a que vuelva, ¿no?$B$BEn este momento estamos hasta el cuello en esta jungla, pero gracias, $n. Quizás mi próxima expedición me lleve de vuelta a Desolace, la tierra de los centauros.', 0),
(@ID, 'esMX', 'Ah, este cuerno es de un tauren, Roon Ferocrín. Pasamos buenos ratos dando caza a las bestias de Desolace. Así que Roon me invita a que vuelva, ¿no?$B$BEn este momento estamos hasta el cuello en esta jungla, pero gracias, $n. Quizás mi próxima expedición me lleve de vuelta a Desolace, la tierra de los centauros.', 0);
-- 5781 De recuerdos olvidados
-- https://es.classic.wowhead.com/quest=5781
SET @ID := 5781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay que redimirle.', 0),
(@ID, 'esMX', 'Hay que redimirle.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tirion cierra los ojos para reprimir las lágrimas.>$B$BFue el destino que nos estaba reservado, $n. Tu bondad ha sido toda una bendición.', 0),
(@ID, 'esMX', '<Tirion cierra los ojos para reprimir las lágrimas.>$B$BFue el destino que nos estaba reservado, $n. Tu bondad ha sido toda una bendición.', 0);
-- La forja del Penacho en Llamas
-- 5801, 5802
-- https://es.classic.wowhead.com/quest=5801
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5801, 5802) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5801, 'esES', '¿Has acabado el mango de la llave esqueleto? Siento que hayas tenido que correr con los gastos del molde pero todos debemos poner algo de nuestra parte en nuestra lucha contra la Plaga. Cuando me traigas la llave incompleta, estarás <preparado(preparada> para recibir el elemento que necesitas para completar la llave.$B$BNo será fácil pero todo lo que has hecho para preparar el ataque a Andorhal comenzará ahora a dar sus frutos. Ya lo verás...', 0),
(5802, 'esES', '¿Has acabado el mango de la llave esqueleto? Siento que hayas tenido que correr con los gastos del molde pero todos debemos poner algo de nuestra parte en nuestra lucha contra la Plaga. Cuando me traigas la llave incompleta, estarás <preparado(preparada> para recibir el elemento que necesitas para completar la llave.$B$BNo será fácil pero todo lo que has hecho para preparar el ataque a Andorhal comenzará ahora a dar sus frutos. Ya lo verás...', 0),
(5801, 'esMX', '¿Has acabado el mango de la llave esqueleto? Siento que hayas tenido que correr con los gastos del molde pero todos debemos poner algo de nuestra parte en nuestra lucha contra la Plaga. Cuando me traigas la llave incompleta, estarás <preparado(preparada> para recibir el elemento que necesitas para completar la llave.$B$BNo será fácil pero todo lo que has hecho para preparar el ataque a Andorhal comenzará ahora a dar sus frutos. Ya lo verás...', 0),
(5802, 'esMX', '¿Has acabado el mango de la llave esqueleto? Siento que hayas tenido que correr con los gastos del molde pero todos debemos poner algo de nuestra parte en nuestra lucha contra la Plaga. Cuando me traigas la llave incompleta, estarás <preparado(preparada> para recibir el elemento que necesitas para completar la llave.$B$BNo será fácil pero todo lo que has hecho para preparar el ataque a Andorhal comenzará ahora a dar sus frutos. Ya lo verás...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5801, 5802) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5801, 'esES', 'Ya tenemos la costosa llave esqueleto, ¿verdad, $n? Aun así, está incompleta. Ha llegado el momento de que rematemos nuestra creación. Para ello, tendrás que enfrentarte al mayor enemigo que encontrarás en Andorhal... el abominable ser que domina las ruinas de las murallas de la ciudad.$B$BMe refiero a Araj el Invocador, un exánime y uno de los seres más poderosos de la Plaga.', 0),
(5802, 'esES', 'Ya tenemos la costosa llave esqueleto, ¿verdad, $n? Aun así, está incompleta. Ha llegado el momento de que rematemos nuestra creación. Para ello, tendrás que enfrentarte al mayor enemigo que encontrarás en Andorhal... el abominable ser que domina las ruinas de las murallas de la ciudad.$B$BMe refiero a Araj el Invocador, un exánime y uno de los seres más poderosos de la Plaga.', 0),
(5801, 'esMX', 'Ya tenemos la costosa llave esqueleto, ¿verdad, $n? Aun así, está incompleta. Ha llegado el momento de que rematemos nuestra creación. Para ello, tendrás que enfrentarte al mayor enemigo que encontrarás en Andorhal... el abominable ser que domina las ruinas de las murallas de la ciudad.$B$BMe refiero a Araj el Invocador, un exánime y uno de los seres más poderosos de la Plaga.', 0),
(5802, 'esMX', 'Ya tenemos la costosa llave esqueleto, ¿verdad, $n? Aun así, está incompleta. Ha llegado el momento de que rematemos nuestra creación. Para ello, tendrás que enfrentarte al mayor enemigo que encontrarás en Andorhal... el abominable ser que domina las ruinas de las murallas de la ciudad.$B$BMe refiero a Araj el Invocador, un exánime y uno de los seres más poderosos de la Plaga.', 0);
-- El escarabeo de Araj
-- 5803, 5804
-- https://es.classic.wowhead.com/quest=5803
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5803, 5804) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5803, 'esES', 'Has llegado muy lejos, $n... pero solo la destrucción de la forma física de Araj el Invocador nos dará los medios para terminar la llave. Consigue el Escarabeo de Araj por los medios que sean necesarios y tráemelo... lo utilizaré como cabeza de la llave.', 0),
(5804, 'esES', 'Has llegado muy lejos, $n... pero solo la destrucción de la forma física de Araj el Invocador nos dará los medios para terminar la llave. Consigue el Escarabeo de Araj por los medios que sean necesarios y tráemelo... lo utilizaré como cabeza de la llave.', 0),
(5803, 'esMX', 'Has llegado muy lejos, $n... pero solo la destrucción de la forma física de Araj el Invocador nos dará los medios para terminar la llave. Consigue el Escarabeo de Araj por los medios que sean necesarios y tráemelo... lo utilizaré como cabeza de la llave.', 0),
(5804, 'esMX', 'Has llegado muy lejos, $n... pero solo la destrucción de la forma física de Araj el Invocador nos dará los medios para terminar la llave. Consigue el Escarabeo de Araj por los medios que sean necesarios y tráemelo... lo utilizaré como cabeza de la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5803, 5804) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5803, 'esES', 'Sí, ¡eso es! Vuelvo a asombrarme ante tu enorme valentía. Es increíble lo que estás $gdispuesto:dispuesta; a hacer para lograr la victoria de las fuerzas oscuras.$B$BPermíteme formar aunque sea una pequeña parte de todo esto. He preparado un solvente especial que me permite conseguir un escarabajo como cabeza de la llave, dotándola del poder para abrir la puerta cerrada de Scholomance.$B$BAhí va...', 0),
(5804, 'esES', 'Sí, ¡eso es! Vuelvo a asombrarme ante tu enorme valentía. Es increíble lo que estás $gdispuesto:dispuesta; a hacer para lograr la victoria de las fuerzas oscuras.$B$BPermíteme formar aunque sea una pequeña parte de todo esto. He preparado un solvente especial que me permite conseguir un escarabajo como cabeza de la llave, dotándola del poder para abrir la puerta cerrada de Scholomance.$B$BAhí va...', 0),
(5803, 'esMX', 'Sí, ¡eso es! Vuelvo a asombrarme ante tu enorme valentía. Es increíble lo que estás $gdispuesto:dispuesta; a hacer para lograr la victoria de las fuerzas oscuras.$B$BPermíteme formar aunque sea una pequeña parte de todo esto. He preparado un solvente especial que me permite conseguir un escarabajo como cabeza de la llave, dotándola del poder para abrir la puerta cerrada de Scholomance.$B$BAhí va...', 0),
(5804, 'esMX', 'Sí, ¡eso es! Vuelvo a asombrarme ante tu enorme valentía. Es increíble lo que estás $gdispuesto:dispuesta; a hacer para lograr la victoria de las fuerzas oscuras.$B$BPermíteme formar aunque sea una pequeña parte de todo esto. He preparado un solvente especial que me permite conseguir un escarabajo como cabeza de la llave, dotándola del poder para abrir la puerta cerrada de Scholomance.$B$BAhí va...', 0);
-- ¡Te damos la bienvenida!
-- 5841, 5843
-- https://es.classic.wowhead.com/quest=5841
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5841, 5843) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5841, 'esES', '¡Hola! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5843, 'esES', '¡Hola! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5841, 'esMX', '¡Hola! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5843, 'esMX', '¡Hola! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5841, 5843) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5841, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5843, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5841, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5843, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0);
-- ¡Te damos la bienvenida!
-- 5805, 5842, 5844, 5847, 8547, 9278
-- https://es.wowhead.com/quest=5805
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5805, 5842, 5844, 5847, 8547, 9278) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5805, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5842, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5844, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5847, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(8547, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(9278, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5805, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5842, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5844, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(5847, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(8547, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(9278, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5805, 5842, 5844, 5847, 8547, 9278) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5805, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5842, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5844, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5847, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(8547, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(9278, 'esES', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5805, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5842, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5844, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(5847, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(8547, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(9278, 'esMX', 'De hecho, eres $gun héroe:una heroína; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0);
-- 5845 Del honor perdido
-- https://es.classic.wowhead.com/quest=5845
SET @ID := 5845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi fe te guiará, $n. La Luz no tiene límites.', 0),
(@ID, 'esMX', 'Mi fe te guiará, $n. La Luz no tiene límites.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está tan lleno de gloria (a pesar de su estado) como el día en el que mirándolo fijamente presté juramento de lealtad.$B$BSe acerca su redención y quizás también la mía...', 0),
(@ID, 'esMX', 'Está tan lleno de gloria (a pesar de su estado) como el día en el que mirándolo fijamente presté juramento de lealtad.$B$BSe acerca su redención y quizás también la mía...', 0);
-- 5846 Del amor y la familia
-- https://es.classic.wowhead.com/quest=5846
SET @ID := 5846;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo podría olvidar? Muchos de los espíritus de esta isla están condenados a revivir su último recuerdo feliz antes de encontrarse con su trágico fin.$B$BYo también estoy condenado, pero no como ellos... soy uno de los pocos que recuerda todo...$B$BQuizás esto que me pides es lo que me mantenía entre estas ruinas. Y tal vez lo que voy a decirte me libere.', 0),
(@ID, 'esMX', '¿Cómo podría olvidar? Muchos de los espíritus de esta isla están condenados a revivir su último recuerdo feliz antes de encontrarse con su trágico fin.$B$BYo también estoy condenado, pero no como ellos... soy uno de los pocos que recuerda todo...$B$BQuizás esto que me pides es lo que me mantenía entre estas ruinas. Y tal vez lo que voy a decirte me libere.', 0);
-- 5848 Del amor y la familia
-- https://es.classic.wowhead.com/quest=5848
SET @ID := 5848;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuadro, $n. ¿Tienes el cuadro?', 0),
(@ID, 'esMX', 'El cuadro, $n. ¿Tienes el cuadro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tirion casi se derrumba al ver la pintura.>$B$B<Comienza a sollozar casi con histeria.>', 0),
(@ID, 'esMX', '<Tirion casi se derrumba al ver la pintura.>$B$B<Comienza a sollozar casi con histeria.>', 0);
-- 5861 Encuentra a Myranda
-- https://es.classic.wowhead.com/quest=5861
SET @ID := 5861;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que llegaría este día.', 0),
(@ID, 'esMX', 'Sabía que llegaría este día.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yo era la consejera en la que más confiaba Tirion cuando era el Señor de Mardenholde. Me opuse abiertamente a la sentencia transmitida por la Orden de la Mano de Plata y fui desterrada por mi insolencia.$B$BHa tenido que pasar por mucho dolor y sufrimiento, $r. ¿Estás $gpreparado:preparada; para reparar todo el daño hecho a los Vadín?', 0),
(@ID, 'esMX', 'Yo era la consejera en la que más confiaba Tirion cuando era el Señor de Mardenholde. Me opuse abiertamente a la sentencia transmitida por la Orden de la Mano de Plata y fui desterrada por mi insolencia.$B$BHa tenido que pasar por mucho dolor y sufrimiento, $r. ¿Estás $gpreparado:preparada; para reparar todo el daño hecho a los Vadín?', 0);
-- 5862 El subterfugio Escarlata
-- https://es.classic.wowhead.com/quest=5862
SET @ID := 5862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tú eres los refuerzos de la Mano de Tyr?', 0),
(@ID, 'esMX', '¿Tú eres los refuerzos de la Mano de Tyr?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto, soldado?$B$B<Taelan abre la caja y comienza a examinar el contenido.>$B$BEsto... no puede ser verdad. Pero todo lo que me has enseñado...$B$B<Taelan cae de rodillas, se le acelera el pulso. La ira acumulada durante años está a punto de desatarse sobre la ciudad.>', 0),
(@ID, 'esMX', '¿Qué es esto, soldado?$B$B<Taelan abre la caja y comienza a examinar el contenido.>$B$BEsto... no puede ser verdad. Pero todo lo que me has enseñado...$B$B<Taelan cae de rodillas, se le acelera el pulso. La ira acumulada durante años está a punto de desatarse sobre la ciudad.>', 0);
-- 5881 La sustitución
-- https://es.classic.wowhead.com/quest=5881
SET @ID := 5881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes noticias de Maggran Vinculador Terrestre?', 0),
(@ID, 'esMX', '¿Tienes noticias de Maggran Vinculador Terrestre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son muy buenas noticias. Llevo demasiado tiempo aquí protegiendo esta madera. Ahora podré pasar algo de tiempo con mi familia... ¡Yupi!', 0),
(@ID, 'esMX', 'Son muy buenas noticias. Llevo demasiado tiempo aquí protegiendo esta madera. Ahora podré pasar algo de tiempo con mi familia... ¡Yupi!', 0);
-- 5892 Suministros de Ferrohondo
-- https://es.classic.wowhead.com/quest=5892
SET @ID := 5892;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los suministros, $n? ¡Nunca hay suficientes!', 0),
(@ID, 'esMX', '¿Tienes los suministros, $n? ¡Nunca hay suficientes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien! Haré que se aprovechen bien estos suministros. ¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Muy bien! Haré que se aprovechen bien estos suministros. ¡Gracias, $n!', 0);
-- 5893 Suministros de Dentefrío
-- https://es.classic.wowhead.com/quest=5893
SET @ID := 5893;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en la Mina Dentefrío, $n? ¿Tienes los suministros que te pedí?', 0),
(@ID, 'esMX', '¿Has estado en la Mina Dentefrío, $n? ¿Tienes los suministros que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, los tienes. ¡Buen trabajo, $n! Estos suministros están algo húmedos de estar guardados en esa oscura mina tanto tiempo pero les sacaremos partido igualmente.$B$BGracias, $n. Tus acciones son vitales para el mantenimiento de nuestras tropas.', 0),
(@ID, 'esMX', 'Ah, los tienes. ¡Buen trabajo, $n! Estos suministros están algo húmedos de estar guardados en esa oscura mina tanto tiempo pero les sacaremos partido igualmente.$B$BGracias, $n. Tus acciones son vitales para el mantenimiento de nuestras tropas.', 0);
-- 5901 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=5901
SET @ID := 5901;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya las termitas, $n? Seguro que $gun:una; $c tan inteligente como tú ya lo ha deducido.$B$BCuando tengamos suficientes termitas, ¡nos aseguraremos de que nadie pueda usar la Serrería nunca más!', 0),
(@ID, 'esMX', '¿Tienes ya las termitas, $n? Seguro que $gun:una; $c tan inteligente como tú ya lo ha deducido.$B$BCuando tengamos suficientes termitas, ¡nos aseguraremos de que nadie pueda usar la Serrería nunca más!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estas nos servirán.$B$BSi estás $glisto:lista;, podemos pasar a la fase siguiente.', 0),
(@ID, 'esMX', 'Gracias, $n. Estas nos servirán.$B$BSi estás $glisto:lista;, podemos pasar a la fase siguiente.', 0);
-- 5902 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=5902
SET @ID := 5902;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Notas que las termitas empiezan a inquietarse cuando colocas el barril sobre la caja.', 0),
(@ID, 'esMX', 'Notas que las termitas empiezan a inquietarse cuando colocas el barril sobre la caja.', 0);
-- 5903 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=5903
SET @ID := 5903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste los nidos de termitas, $n? He oído que hay muchos por todo el Bosque de la Peste.', 0),
(@ID, 'esMX', '¿Encontraste los nidos de termitas, $n? He oído que hay muchos por todo el Bosque de la Peste.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estas nos servirán. Míralas... todas apiñadas. Casi siento pena por la Cruzada, pero al fin y al cabo, no tenían que haberse apropiado de la serrería, ¿no te parece?', 0),
(@ID, 'esMX', 'Gracias, $n. Estas nos servirán. Míralas... todas apiñadas. Casi siento pena por la Cruzada, pero al fin y al cabo, no tenían que haberse apropiado de la serrería, ¿no te parece?', 0);
-- 5904 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=5904
SET @ID := 5904;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Notas que las termitas empiezan a inquietarse cuando colocas el barril sobre la caja.', 0),
(@ID, 'esMX', 'Notas que las termitas empiezan a inquietarse cuando colocas el barril sobre la caja.', 0);
-- 5921 Claro de la Luna
-- https://es.classic.wowhead.com/quest=5921
SET @ID := 5921;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Aquí empieza, Padre Cenario. Aquí empieza."$B$BDendrite hace un rápido e invisible gesto en el aire por encima de su cabeza, y una ligera aura de poder cae sobre él.$B$B"La primera perspectiva de la naturaleza a la que debes adaptarte es la del oso. Yo te orientaré para que entiendas este aspecto de la vida de los druidas, pero eres tú quien debe seguir el camino y propagarlo... ¡ahora y siempre!"', 0),
(@ID, 'esMX', '"Aquí empieza, Padre Cenario. Aquí empieza."$B$BDendrite hace un rápido e invisible gesto en el aire por encima de su cabeza, y una ligera aura de poder cae sobre él.$B$B"La primera perspectiva de la naturaleza a la que debes adaptarte es la del oso. Yo te orientaré para que entiendas este aspecto de la vida de los druidas, pero eres tú quien debe seguir el camino y propagarlo... ¡ahora y siempre!"', 0);
-- Escucha la llamada
-- 5923, 5924, 5925, 5927, 5928
-- https://es.classic.wowhead.com/quest=5923
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5923, 5924, 5925, 5927, 5928) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5923, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5924, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5925, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5927, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5928, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5923, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5924, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5925, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5927, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(5928, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0);
-- 5929 Espíritu del gran oso
-- https://es.classic.wowhead.com/quest=5929
SET @ID := 5929;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras te acercas, Dendrite hace otro gesto. Aparece otra aura de poder sobre él y te sonríe.$B$B"Hay en ti sabiduría nueva. Tu mirada refleja fuerza y decisión, pero debes aprender a dominarlas. Aprenderás a concentrarte y a adoptar las estrategias del oso."', 0),
(@ID, 'esMX', 'Mientras te acercas, Dendrite hace otro gesto. Aparece otra aura de poder sobre él y te sonríe.$B$B"Hay en ti sabiduría nueva. Tu mirada refleja fuerza y decisión, pero debes aprender a dominarlas. Aprenderás a concentrarte y a adoptar las estrategias del oso."', 0);
-- 5931 El regreso a Darnassus
-- https://es.classic.wowhead.com/quest=5931
SET @ID := 5931;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Veo que tu primer encuentro con el Espíritu del gran oso fue, como para todos los druidas, inquietante pero intenso; también lo fue para mí.$B$BEl Espíritu del gran oso ha residido en Azeroth desde el principio de los tiempos; confiamos en su sabiduría y su fuerza para ayudarnos en nuestro propósito. Escucha con atención...', 0),
(@ID, 'esMX', 'Saludos, $n. Veo que tu primer encuentro con el Espíritu del gran oso fue, como para todos los druidas, inquietante pero intenso; también lo fue para mí.$B$BEl Espíritu del gran oso ha residido en Azeroth desde el principio de los tiempos; confiamos en su sabiduría y su fuerza para ayudarnos en nuestro propósito. Escucha con atención...', 0);
-- 5941 Regresa junto a Cromi
-- https://es.classic.wowhead.com/quest=5941
SET @ID := 5941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado en contacto con tu amigo Carlin. Sufre por la desgracia de su aldea, pero habla muy bien de ti y sabe que tú puedes enderezar las cosas.$B$BPero me estoy alejando del tema que nos ocupa... $n, ¿tienes las reliquias que te pedí?', 0),
(@ID, 'esMX', 'He estado en contacto con tu amigo Carlin. Sufre por la desgracia de su aldea, pero habla muy bien de ti y sabe que tú puedes enderezar las cosas.$B$BPero me estoy alejando del tema que nos ocupa... $n, ¿tienes las reliquias que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, aquí están. Juntas conforman un poderoso hechizo, uno que alzará a los espíritus de Villa Darrow.$B$BCon ese hechizo y un poco de suerte, podremos salvar a Joseph Rutagrana.', 0),
(@ID, 'esMX', 'Ah, sí, aquí están. Juntas conforman un poderoso hechizo, uno que alzará a los espíritus de Villa Darrow.$B$BCon ese hechizo y un poco de suerte, podremos salvar a Joseph Rutagrana.', 0);
-- 5942 Tesoros ocultos
-- https://es.classic.wowhead.com/quest=5942
SET @ID := 5942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre es viejo y está cubierto de mugre.', 0),
(@ID, 'esMX', 'Este cofre es viejo y está cubierto de mugre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave entra en la cerradura y el cofre se abre...', 0),
(@ID, 'esMX', 'La llave entra en la cerradura y el cofre se abre...', 0);
-- 5944 En sueños
-- https://es.classic.wowhead.com/quest=5944
SET @ID := 5944;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tirion recupera la compostura.>', 0),
(@ID, 'esMX', '<Tirion recupera la compostura.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte de mi hijo a manos de esos monstruos no caerá en el olvido. Consuélate pensando en que la Orden ha renacido.$B$BAhora ocuparé mi puesto como Alto Señor de la nueva Orden de la Mano de Plata.$B$BEstas posesiones de mi pasado son todo lo que puedo ofrecerte por todo lo que has hecho por mí. Por favor, acéptalas como símbolo de mi gratitud, me fueron de gran ayuda durante años.$B$BTal vez nos volvamos a encontrar en tiempos mejores y recordaremos los días pasados... las duras batallas... los sueños redimidos.', 0),
(@ID, 'esMX', 'La muerte de mi hijo a manos de esos monstruos no caerá en el olvido. Consuélate pensando en que la Orden ha renacido.$B$BAhora ocuparé mi puesto como Alto Señor de la nueva Orden de la Mano de Plata.$B$BEstas posesiones de mi pasado son todo lo que puedo ofrecerte por todo lo que has hecho por mí. Por favor, acéptalas como símbolo de mi gratitud, me fueron de gran ayuda durante años.$B$BTal vez nos volvamos a encontrar en tiempos mejores y recordaremos los días pasados... las duras batallas... los sueños redimidos.', 0);
-- 5961 Campeón de la Reina alma en pena
-- https://es.classic.wowhead.com/quest=5961
SET @ID := 5961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda la Dama Oscura no te cree $gmerecedor:merecedora; de enfrentarte a su Campeón. ¿Has venido para convertirte en la merienda de mis canes? No puede haber otro motivo para esta interrupción.', 0),
(@ID, 'esMX', 'Sin duda la Dama Oscura no te cree $gmerecedor:merecedora; de enfrentarte a su Campeón. ¿Has venido para convertirte en la merienda de mis canes? No puede haber otro motivo para esta interrupción.', 0);
