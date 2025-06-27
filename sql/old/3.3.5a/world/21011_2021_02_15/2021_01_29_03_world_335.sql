-- 3518 Entrega a Magatha
-- https://es.classic.wowhead.com/quest=3518
SET @ID := 3518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué hay, $n? ¿Necesitas algo? Tengo muchos asuntos de que ocuparme, así que te ruego premura.', 0),
(@ID, 'esMX', '¿Qué hay, $n? ¿Necesitas algo? Tengo muchos asuntos de que ocuparme, así que te ruego premura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, por fin, la tablilla de Beth\'Amara. Me estaba preguntando si mi asociación con Jediga había fracasado o si la pobre orco había encontrado la muerte en Azshara. Me alegra ver que tuvo éxito.$B$BBeth\'Amara era uno de los alquimistas con más influencia entre los altonatos. Se decía que el zahorí en solitario había conseguido dominar la trasmutación de metales entre otras cosas.', 0),
(@ID, 'esMX', 'Ah, por fin, la tablilla de Beth\'Amara. Me estaba preguntando si mi asociación con Jediga había fracasado o si la pobre orco había encontrado la muerte en Azshara. Me alegra ver que tuvo éxito.$B$BBeth\'Amara era uno de los alquimistas con más influencia entre los altonatos. Se decía que el zahorí en solitario había conseguido dominar la trasmutación de metales entre otras cosas.', 0);
-- 3520 Los espíritus de los estridadores
-- https://es.classic.wowhead.com/quest=3520
SET @ID := 3520;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Espíritus de los estridadores recogidos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 3523 La plaga de la Zahúrda
-- https://es.classic.wowhead.com/quest=3523
SET @ID := 3523;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me interesa la política, me da igual que estés con la Horda o con la Alianza. Lo que quiero es acabar con las amenazas a todas las razas, y aquí tenemos una importante.$B$BSi aceptas ayudarnos, dame la piedra de juramento como prueba de lealtad. Yo no soy de por aquí; las piedras de juramento son importantes para mi gente.', 0),
(@ID, 'esMX', 'No me interesa la política, me da igual que estés con la Horda o con la Alianza. Lo que quiero es acabar con las amenazas a todas las razas, y aquí tenemos una importante.$B$BSi aceptas ayudarnos, dame la piedra de juramento como prueba de lealtad. Yo no soy de por aquí; las piedras de juramento son importantes para mi gente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, lo sabía! Ya lo tenemos todo hecho. Si nos concentramos en lo que tenemos que hacer, todo irá bien.$B$BVoy a ponerte al día de los acontecimientos...', 0),
(@ID, 'esMX', '¡Estupendo, lo sabía! Ya lo tenemos todo hecho. Si nos concentramos en lo que tenemos que hacer, todo irá bien.$B$BVoy a ponerte al día de los acontecimientos...', 0);
-- 3525 Extinguir el ídolo
-- https://es.classic.wowhead.com/quest=3525
SET @ID := 3525;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Belnistrasz ha dejado atrás un blandón ardiente. Miras la llama y tu mente se llena con la imagen de un gran dragón rojo. Oyes la voz de Belnistrasz.$B$B"Los mortales sois los héroes que estaba esperando. Gracias por detener la matanza. Acepta esto como recompensa por tu heroicidad."', 0),
(@ID, 'esMX', 'Belnistrasz ha dejado atrás un blandón ardiente. Miras la llama y tu mente se llena con la imagen de un gran dragón rojo. Oyes la voz de Belnistrasz.$B$B"Los mortales sois los héroes que estaba esperando. Gracias por detener la matanza. Acepta esto como recompensa por tu heroicidad."', 0);
-- Ingeniería goblin
-- 3526, 3629, 3633, 4181
-- https://es.classic.wowhead.com/quest=3526
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3526, 3629, 3633, 4181) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3526, 'esES', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(3629, 'esES', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(3633, 'esES', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(4181, 'esES', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(3526, 'esMX', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(3629, 'esMX', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(3633, 'esMX', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0),
(4181, 'esMX', 'Puedo oler a los reclutas novatos a un kilómetro de distancia, como a la buena pólvora. ¿Has venido para aprender a provocar explosiones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3526, 3629, 3633, 4181) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3526, 'esES', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(3629, 'esES', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(3633, 'esES', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(4181, 'esES', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(3526, 'esMX', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(3629, 'esMX', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(3633, 'esMX', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0),
(4181, 'esMX', 'Bueno, $n, ¡has sido muy inteligente buscando mi enseñanza! Cualquier pringado puede convertirse en un experto de las bases de ingeniería, no hay más que ver a los gnomos y su irradiado hogar en Gnomeregan. Pero hace falta una mente fuerte y una mano FIRME para dominar la disciplina de la ingeniería goblin.$B$BEscucha con atención, $n, y puede que aprendas algo.', 0);
-- 3541 Entrega a Jes'rimon
-- https://es.classic.wowhead.com/quest=3541
SET @ID := 3541;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué va a ser, colega? Tengo muchas cosas qu\'hacer hoy y en principio no tengo hueco en la agenda pa\' ti. Dame la lata y eso cambiará.', 0),
(@ID, 'esMX', '¿Qué va a ser, colega? Tengo muchas cosas qu\'hacer hoy y en principio no tengo hueco en la agenda pa\' ti. Dame la lata y eso cambiará.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Jediga ha mandao su paquete desde Azshara. Bien. Qué ganas tenía de pillarlo.$B$BJediga, toda una mujer... mortal también. ¿Qué más se puede pedir?$B$BFíjate... la tablilla está en perfecto estado. Eres un mensajero daguten, $n.', 0),
(@ID, 'esMX', 'Ah, Jediga ha mandao su paquete desde Azshara. Bien. Qué ganas tenía de pillarlo.$B$BJediga, toda una mujer... mortal también. ¿Qué más se puede pedir?$B$BFíjate... la tablilla está en perfecto estado. Eres un mensajero daguten, $n.', 0);
-- 3542 Entrega a Andron Gant
-- https://es.classic.wowhead.com/quest=3542
SET @ID := 3542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... <hic>... ¡Qué sorpresa! ¡Un aventututurero... <hic>!$B$B¿Qué puedo hacer pa\' ti... <hic>?', 0),
(@ID, 'esMX', 'Vaya... <hic>... ¡Qué sorpresa! ¡Un aventututurero... <hic>!$B$B¿Qué puedo hacer pa\' ti... <hic>?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma, ahí van unas monedas... pa\' que... <hic>... te compres una nueva armadura y tal...$B$BEsto supondrá una pieza o dos de oro pa\' la gente... <hic> apropiada.', 0),
(@ID, 'esMX', 'Toma, ahí van unas monedas... pa\' que... <hic>... te compres una nueva armadura y tal...$B$BEsto supondrá una pieza o dos de oro pa\' la gente... <hic> apropiada.', 0);
-- 3561 Entrega al archimago Xylem
-- https://es.classic.wowhead.com/quest=3561
SET @ID := 3561;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué puedo hacer por ti, $n?', 0),
(@ID, 'esMX', '¿Qué puedo hacer por ti, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, la tablilla de Sael\'hai... ¡cuánto tiempo llevo esperando para estudiarla!$B$BGracias, $n. Puedes decirle a Jediga que ha hecho un buen trabajo. Esto sin duda vale el pago que pedía.', 0),
(@ID, 'esMX', 'Ah, la tablilla de Sael\'hai... ¡cuánto tiempo llevo esperando para estudiarla!$B$BGracias, $n. Puedes decirle a Jediga que ha hecho un buen trabajo. Esto sin duda vale el pago que pedía.', 0);
-- 3562 El pago de Magatha a Jediga
-- https://es.classic.wowhead.com/quest=3562
SET @ID := 3562;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué dijo Magatha? La vieja bruja... Apuesto que no fue precisamente educada.', 0),
(@ID, 'esMX', 'Bueno, ¿qué dijo Magatha? La vieja bruja... Apuesto que no fue precisamente educada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien. Fue mucho más razonable de lo que esperaba... al menos contigo. Casi esperaba que te castigara por mi insolencia al enviar a alguien en mi lugar. Debe de tener muchas ganas de hacerse con esa tablilla. Interesante.$B$BAlgo en lo que pensar en otro momento.', 0),
(@ID, 'esMX', 'Ah, bien. Fue mucho más razonable de lo que esperaba... al menos contigo. Casi esperaba que te castigara por mi insolencia al enviar a alguien en mi lugar. Debe de tener muchas ganas de hacerse con esa tablilla. Interesante.$B$BAlgo en lo que pensar en otro momento.', 0);
-- 3563 El pago de Jes'rimon a Jediga
-- https://es.classic.wowhead.com/quest=3563
SET @ID := 3563;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hablado ya con Jes\'rimon?$B$BEs un jabalí entre trols pero su información suele ser precisa y paga bien por sus trabajos.$B$BSi puedes soportar su actitud, entonces podrás ganarte un buen dinero con sus negocios.', 0),
(@ID, 'esMX', '¿Has hablado ya con Jes\'rimon?$B$BEs un jabalí entre trols pero su información suele ser precisa y paga bien por sus trabajos.$B$BSi puedes soportar su actitud, entonces podrás ganarte un buen dinero con sus negocios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que estaba más que contento por el aspecto de su nota... un pelín demasiado contento.$B$BQuizás algún día me tome el tiempo para asegurarme de que sepa cuánto aprecio también sus insinuaciones. Bueno, al menos hay una razón para desear pasar más tiempo en Azshara.$B$BAquí tienes tu parte del pago.', 0),
(@ID, 'esMX', 'Veo que estaba más que contento por el aspecto de su nota... un pelín demasiado contento.$B$BQuizás algún día me tome el tiempo para asegurarme de que sepa cuánto aprecio también sus insinuaciones. Bueno, al menos hay una razón para desear pasar más tiempo en Azshara.$B$BAquí tienes tu parte del pago.', 0);
-- 3564 El pago de Andron a Jediga
-- https://es.classic.wowhead.com/quest=3564
SET @ID := 3564;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto ya a Andron? Casi nunca sale de Entrañas, así que no debería costar mucho encontrarlo.', 0),
(@ID, 'esMX', '¿Has visto ya a Andron? Casi nunca sale de Entrañas, así que no debería costar mucho encontrarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto... espera un segundo.$B$B¡Ajá! ¿Qué le dijiste cuando le entregaste la tablilla, $n? ¡Se ha pasado tres pueblos con el pago! No es que me queje. ¿Le dijiste que el trato había cambiado? ¿O acaso estaba borracho para variar?$B$BDa igual... aquí tienes, parte extra para ti también.', 0),
(@ID, 'esMX', 'Perfecto... espera un segundo.$B$B¡Ajá! ¿Qué le dijiste cuando le entregaste la tablilla, $n? ¡Se ha pasado tres pueblos con el pago! No es que me queje. ¿Le dijiste que el trato había cambiado? ¿O acaso estaba borracho para variar?$B$BDa igual... aquí tienes, parte extra para ti también.', 0);
-- 3565 El pago de Xylem a Jediga
-- https://es.classic.wowhead.com/quest=3565
SET @ID := 3565;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué te dijo Xylem? No te hizo nada, ¿verdad? ¿No te habrá lanzado un hechizo? ¿O engatusado para que le hagas una faenita?', 0),
(@ID, 'esMX', 'Bueno, ¿qué te dijo Xylem? No te hizo nada, ¿verdad? ¿No te habrá lanzado un hechizo? ¿O engatusado para que le hagas una faenita?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ninguna complicación? ¿Para nada? Bueno, eso casi merece quedar en los anales... Esperaba que mostrara algo de reticencia o que al menos traicionara nuestro pacto. Mmm, a lo mejor hasta es de fiar después de todo.$B$BBueno, tampoco hay que pensar tanto en eso. Aquí tienes tu parte Gracias por tu ayuda.', 0),
(@ID, 'esMX', '¿Ninguna complicación? ¿Para nada? Bueno, eso casi merece quedar en los anales... Esperaba que mostrara algo de reticencia o que al menos traicionara nuestro pacto. Mmm, a lo mejor hasta es de fiar después de todo.$B$BBueno, tampoco hay que pensar tanto en eso. Aquí tienes tu parte Gracias por tu ayuda.', 0);
-- 3566 ¡Arriba, Obsidion!
-- https://es.classic.wowhead.com/quest=3566
SET @ID := 3566;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te creo! ¡Muéstrame una prueba!', 0),
(@ID, 'esMX', '¡No te creo! ¡Muéstrame una prueba!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La cara de Thorius se pone blanca.>$B$BEsto... esto no puede ser. ¿Mi propio hermano? ¿Él preparó todo esto?$B$B<El rostro de Thorius se contrae de ira.>$B$B¡Me traicionó, traicionó a Forjaz! Parece que la influencia de los Dioses Antiguos sigue siendo fuerte en estas tierras. Me temo que si mi hermano, un hombre que alguna vez fue noble y honorable, se doblegó tan fácilmente a la voluntad de Ragnaros, nadie estará a salvo.', 0),
(@ID, 'esMX', '<La cara de Thorius se pone blanca.>$B$BEsto... esto no puede ser. ¿Mi propio hermano? ¿Él preparó todo esto?$B$B<El rostro de Thorius se contrae de ira.>$B$B¡Me traicionó, traicionó a Forjaz! Parece que la influencia de los Dioses Antiguos sigue siendo fuerte en estas tierras. Me temo que si mi hermano, un hombre que alguna vez fue noble y honorable, se doblegó tan fácilmente a la voluntad de Ragnaros, nadie estará a salvo.', 0);
-- 3567 A la cima
-- https://es.classic.wowhead.com/quest=3567
SET @ID := 3567;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres ver la vista desde uno de los colosos gemelos? Porque puedo mandarte allí arriba, $r.$B$BPero tendrás que pensar tú en cómo harás para bajar. Yo te ofrezco solo el viaje de ida.', 0),
(@ID, 'esMX', '¿Quieres ver la vista desde uno de los colosos gemelos? Porque puedo mandarte allí arriba, $r.$B$BPero tendrás que pensar tú en cómo harás para bajar. Yo te ofrezco solo el viaje de ida.', 0);
-- 3568 La filtración de la corrupción
-- https://es.classic.wowhead.com/quest=3568
SET @ID := 3568;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes cómo acabará esto, ¿no es así, $n? No tiene ninguna posibilidad de sobrevivir... mírala. Lo mejor que puede hacer es ayudarnos a encontrar una cura para la peste. El agua que ella bebió podrá darnos alguna pista de cómo conseguirlo. De todos modos morirá, así que es mejor que antes haga algo noble por nuestro pueblo. ¿No crees?', 0),
(@ID, 'esMX', 'Sabes cómo acabará esto, ¿no es así, $n? No tiene ninguna posibilidad de sobrevivir... mírala. Lo mejor que puede hacer es ayudarnos a encontrar una cura para la peste. El agua que ella bebió podrá darnos alguna pista de cómo conseguirlo. De todos modos morirá, así que es mejor que antes haga algo noble por nuestro pueblo. ¿No crees?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendo. Has vuelto y ella aún sigue con vida. Muy bien.$B$BPongámonos manos a la obra.$B$BLlevo un tiempo observando sus síntomas y esto no tiene buena pinta. De hecho, me sorprende que siga en pie. Ha vomitado unas cuantas veces... ¡no veas qué olor!$B$BDame un segundo para prepararlo todo y podremos hacer una prueba con nuestra amiga.', 0),
(@ID, 'esMX', 'Estupendo. Has vuelto y ella aún sigue con vida. Muy bien.$B$BPongámonos manos a la obra.$B$BLlevo un tiempo observando sus síntomas y esto no tiene buena pinta. De hecho, me sorprende que siga en pie. Ha vomitado unas cuantas veces... ¡no veas qué olor!$B$BDame un segundo para prepararlo todo y podremos hacer una prueba con nuestra amiga.', 0);
-- 3569 La filtración de la corrupción
-- https://es.classic.wowhead.com/quest=3569
SET @ID := 3569;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He venido a Entrañas porque se dice que sus alquimistas llevan tiempo estudiando el modo de curar la enfermedad de la que son víctimas. Suponía que podrían ayudarme.$B$BAunque este lugar no me resulte acogedor, no tengo elección pues la enfermedad que padezco me está matando y necesito ayuda.', 0),
(@ID, 'esMX', 'He venido a Entrañas porque se dice que sus alquimistas llevan tiempo estudiando el modo de curar la enfermedad de la que son víctimas. Suponía que podrían ayudarme.$B$BAunque este lugar no me resulte acogedor, no tengo elección pues la enfermedad que padezco me está matando y necesito ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El químico Cuely está siendo muy amable conmigo... quizás en exceso. Si él dice que me ayudará, no tengo elección. No tengo tiempo para buscar una solución alternativa. Ya he hablado con sacerdotes y chamanes, y ninguno pudo ayudarme.$B$BEsperemos que la Madre Tierra vele por mi espíritu.', 0),
(@ID, 'esMX', 'El químico Cuely está siendo muy amable conmigo... quizás en exceso. Si él dice que me ayudará, no tengo elección. No tengo tiempo para buscar una solución alternativa. Ya he hablado con sacerdotes y chamanes, y ninguno pudo ayudarme.$B$BEsperemos que la Madre Tierra vele por mi espíritu.', 0);
-- 3570 La filtración de la corrupción
-- https://es.classic.wowhead.com/quest=3570
SET @ID := 3570;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes a dónde lleva esto, ¿no, $n? No hay forma de que pueda sobrevivir... mírala. Lo mejor para ella ahora es ayudarnos a encontrar una cura para la plaga. Esta agua que bebió podría tener una pista que nos ayude a descubrir cómo. Ella va a morir de todos modos; bien podría morir haciendo algo noble por nuestra gente. ¿No estas de acuerdo?', 0),
(@ID, 'esMX', 'Sabes a dónde lleva esto, ¿no, $n? No hay forma de que pueda sobrevivir... mírala. Lo mejor para ella ahora es ayudarnos a encontrar una cura para la plaga. Esta agua que bebió podría tener una pista que nos ayude a descubrir cómo. Ella va a morir de todos modos; bien podría morir haciendo algo noble por nuestra gente. ¿No estas de acuerdo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca hubiera imaginado que el elixir hiciera efecto tan rápido. Gracias, $n. Ahora me pondré manos a la obra con las demás muestras. Seguro que muy pronto les resultan de utilidad a Lady Sylvanas y a los Renegados.', 0),
(@ID, 'esMX', 'Nunca hubiera imaginado que el elixir hiciera efecto tan rápido. Gracias, $n. Ahora me pondré manos a la obra con las demás muestras. Seguro que muy pronto les resultan de utilidad a Lady Sylvanas y a los Renegados.', 0);
-- 3601 ¡Kim'jael, claro!
-- https://es.classic.wowhead.com/quest=3601
SET @ID := 3601;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Malditos elfos de sangre! Te lo digo, si fuera tan fuerte como tú, m\'iba pa\' allá ¡y les iba a dar pa’l pelo yo mismo! Pero me tengo que conformar con pagarte pa\' que t\'ocupes d\'ellos.', 0),
(@ID, 'esMX', '¡Malditos elfos de sangre! Te lo digo, si fuera tan fuerte como tú, m\'iba pa\' allá ¡y les iba a dar pa’l pelo yo mismo! Pero me tengo que conformar con pagarte pa\' que t\'ocupes d\'ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ea! ¡¿A que les has dado su merecido?!$B$B¡Estupendo! Eso enseñará a los elfos de sangre a no traicionar a sus socios... ¡y menos a alguien tan leal como un mercader goblin! ¡Bah, ¡elfos de sangre!$B$BBueno, lo mínimo que puedo hacer es pagarte por tu tiempo... como dije que haría.$B$BAquí tienes... deberían serte útiles.', 0),
(@ID, 'esMX', '¡Ea! ¡¿A que les has dado su merecido?!$B$B¡Estupendo! Eso enseñará a los elfos de sangre a no traicionar a sus socios... ¡y menos a alguien tan leal como un mercader goblin! ¡Bah, ¡elfos de sangre!$B$BBueno, lo mínimo que puedo hacer es pagarte por tu tiempo... como dije que haría.$B$BAquí tienes... deberían serte útiles.', 0);
-- 3602 Azsharita
-- https://es.classic.wowhead.com/quest=3602
SET @ID := 3602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El mal no duerme, $gtonto:tonta;. Tendrás tiempo para descansar cuando estés $gmuerto:muerta;. Ahora, tráeme esos cristales.', 0),
(@ID, 'esMX', 'El mal no duerme, $gtonto:tonta;. Tendrás tiempo para descansar cuando estés $gmuerto:muerta;. Ahora, tráeme esos cristales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus tareas en Azshara están completas, mortal. Ahora debo forjar los componentes necesarios para el siguiente paso en tu aventura.', 0),
(@ID, 'esMX', 'Tus tareas en Azshara están completas, mortal. Ahora debo forjar los componentes necesarios para el siguiente paso en tu aventura.', 0);
-- 3621 La formación de Aterravil
-- https://es.classic.wowhead.com/quest=3621
SET @ID := 3621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Loramus, ¿eh? Han pasado muchos años desde que escuché ese nombre.', 0),
(@ID, 'esMX', 'Loramus, ¿eh? Han pasado muchos años desde que escuché ese nombre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dios mío, solo puedo imaginar lo que pasaste para obtener estos materiales. Pocos se aventuran en Azshara y regresan con vida, ¡y mucho menos aquellos que se enfrentan a semidioses y gigantes!', 0),
(@ID, 'esMX', 'Dios mío, solo puedo imaginar lo que pasaste para obtener estos materiales. Pocos se aventuran en Azshara y regresan con vida, ¡y mucho menos aquellos que se enfrentan a semidioses y gigantes!', 0);
-- 3625 Armas Fel en Azsharita encantada
-- https://es.classic.wowhead.com/quest=3625
SET @ID := 3625;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interrumpir el proceso de forja podría resultar en un arma imperfecta. Ten paciencia, $n.', 0),
(@ID, 'esMX', 'Interrumpir el proceso de forja podría resultar en un arma imperfecta. Ten paciencia, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Galván se seca el sudor de la frente>.$B$BNunca ha existido un asesino de demonios mejor, $n.', 0),
(@ID, 'esMX', '<Galván se seca el sudor de la frente>.$B$BNunca ha existido un asesino de demonios mejor, $n.', 0);
-- 3626 Regresa a Las Tierras Devastadas
-- https://es.classic.wowhead.com/quest=3626
SET @ID := 3626;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te has curtido en la batalla, $n. ¿Estás $gpreparado:preparada; para enfrentarte a Razelikh y sus secuaces?', 0),
(@ID, 'esMX', 'Te has curtido en la batalla, $n. ¿Estás $gpreparado:preparada; para enfrentarte a Razelikh y sus secuaces?', 0);
-- 3627 Juntar pedazos del amuleto
-- https://es.classic.wowhead.com/quest=3627
SET @ID := 3627;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los tres formarán el uno, el uno iluminará el camino.', 0),
(@ID, 'esMX', 'Los tres formarán el uno, el uno iluminará el camino.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El amuleto de Razelikh el Rapiñador está una vez más completo, pero siente la interrupción en su cadena de mando. Sabe que vas a por él...', 0),
(@ID, 'esMX', 'El amuleto de Razelikh el Rapiñador está una vez más completo, pero siente la interrupción en su cadena de mando. Sabe que vas a por él...', 0);
-- 3628 Eres Rakh'likh, demonio
-- https://es.classic.wowhead.com/quest=3628
SET @ID := 3628;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No hay nada que temer.', 0),
(@ID, 'esMX', 'No hay nada que temer.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy es un día que será recordado por toda la eternidad. ¡El señor supremo demoníaco de las Tierras Devastadas finalmente ha caído!', 0),
(@ID, 'esMX', 'Hoy es un día que será recordado por toda la eternidad. ¡El señor supremo demoníaco de las Tierras Devastadas finalmente ha caído!', 0);
-- Ingeniería gnómica
-- 3630, 3632, 3634
-- https://es.classic.wowhead.com/quest=3630
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3630, 3632, 3634) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3630, 'esES', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0),
(3632, 'esES', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0),
(3634, 'esES', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0),
(3630, 'esMX', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0),
(3632, 'esMX', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0),
(3634, 'esMX', 'Sí, sí, ¿qué necesidades suyas podría abordar hoy? Claramente, tengo tiempo para hacerlo, ya que todo lo que hago es quedarme aquí mientras nuestra amada ciudad yace en una nube de muerte irradiada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3630, 3632, 3634) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3630, 'esES', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0),
(3632, 'esES', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0),
(3634, 'esES', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0),
(3630, 'esMX', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0),
(3632, 'esMX', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0),
(3634, 'esMX', '¡Ah, un joven ingeniero interesado en seguir la única y verdadera disciplina de la ingeniería! Bueno, perdona mi melodrama, amigo. Si bien nuestra situación sigue siendo grave, ¡siempre es un buen día para ver a otro ingeniero responder la llamada de la verdadera ingeniería!', 0);
-- Ingeniería gnómica
-- 3635, 3637
-- https://es.classic.wowhead.com/quest=3635
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3635, 3637) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3635, 'esES', '¡Hola a todos! Si te has encontrado con un robot buscador que puede haber atravesado una pared de tu domicilio, lo referiré a mi abogado con anticipación. De lo contrario, ¿qué puedo hacer hoy por ti?', 0),
(3637, 'esES', '¡Hola a todos! Si te has encontrado con un robot buscador que puede haber atravesado una pared de tu domicilio, lo referiré a mi abogado con anticipación. De lo contrario, ¿qué puedo hacer hoy por ti?', 0),
(3635, 'esMX', '¡Hola a todos! Si te has encontrado con un robot buscador que puede haber atravesado una pared de tu domicilio, lo referiré a mi abogado con anticipación. De lo contrario, ¿qué puedo hacer hoy por ti?', 0),
(3637, 'esMX', '¡Hola a todos! Si te has encontrado con un robot buscador que puede haber atravesado una pared de tu domicilio, lo referiré a mi abogado con anticipación. De lo contrario, ¿qué puedo hacer hoy por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3635, 3637) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3635, 'esES', 'Has venido a aprender sobre ingeniería gnómica, ¿eh? Bueno, has venido al gnomo correcto. Si bien la facción gobernante de Gnomeregan puede usar la política para condenar al ostracismo a quienes ven como una amenaza intelectual, saben que el conocimiento es algo que no pueden controlar.$B$BEllos y yo sabemos que cuando dejé Gnomeregan, perdieron a uno de sus mejores ingenieros gnomos con vida. Si eres un estudiante capaz, te enseñaré lo que sé.', 0),
(3637, 'esES', 'Has venido a aprender sobre ingeniería gnómica, ¿eh? Bueno, has venido al gnomo correcto. Si bien la facción gobernante de Gnomeregan puede usar la política para condenar al ostracismo a quienes ven como una amenaza intelectual, saben que el conocimiento es algo que no pueden controlar.$B$BEllos y yo sabemos que cuando dejé Gnomeregan, perdieron a uno de sus mejores ingenieros gnomos con vida. Si eres un estudiante capaz, te enseñaré lo que sé.', 0),
(3635, 'esMX', 'Has venido a aprender sobre ingeniería gnómica, ¿eh? Bueno, has venido al gnomo correcto. Si bien la facción gobernante de Gnomeregan puede usar la política para condenar al ostracismo a quienes ven como una amenaza intelectual, saben que el conocimiento es algo que no pueden controlar.$B$BEllos y yo sabemos que cuando dejé Gnomeregan, perdieron a uno de sus mejores ingenieros gnomos con vida. Si eres un estudiante capaz, te enseñaré lo que sé.', 0),
(3637, 'esMX', 'Has venido a aprender sobre ingeniería gnómica, ¿eh? Bueno, has venido al gnomo correcto. Si bien la facción gobernante de Gnomeregan puede usar la política para condenar al ostracismo a quienes ven como una amenaza intelectual, saben que el conocimiento es algo que no pueden controlar.$B$BEllos y yo sabemos que cuando dejé Gnomeregan, perdieron a uno de sus mejores ingenieros gnomos con vida. Si eres un estudiante capaz, te enseñaré lo que sé.', 0);
-- Invoca un corcel vil
-- 3631, 4487, 4488, 4489
-- https://es.classic.wowhead.com/quest=3631
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3631, 4487, 4488, 4489) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3631, 'esES', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4487, 'esES', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4488, 'esES', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4489, 'esES', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(3631, 'esMX', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4487, 'esMX', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4488, 'esMX', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0),
(4489, 'esMX', 'Entonces, has decidido honrar mi presencia nuevamente. Qué amable de tu parte.$B$BMis acólitos se preguntaron si alguna vez aparecerías. Les dije que no había ninguna duda. Cuando se trata de energía, te atrae como una polilla a la llama.', 0);
-- 4490 Invoca un corcel vil
-- https://es.classic.wowhead.com/quest=4490
SET @ID := 4490;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Suerte, $n. Espero que volvamos a vernos.', 0),
(@ID, 'esMX', 'Suerte, $n. Espero que volvamos a vernos.', 0);
-- 3638 La promesa del secreto
-- https://es.classic.wowhead.com/quest=3638
SET @ID := 3638;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si has firmado el documento y deseas entregármelo, no hay más que hablar. Ya sabes que no hay marcha atrás. ¡Si estás $gpreparado:preparada;, sube a bordo!', 0),
(@ID, 'esMX', 'Si has firmado el documento y deseas entregármelo, no hay más que hablar. Ya sabes que no hay marcha atrás. ¡Si estás $gpreparado:preparada;, sube a bordo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bienvenido a bordo, ingeniero goblin $n! Pronto tendrás acceso a los esquemas de ingeniería más poderosos en cualquier parte de Azeroth.$B$BAhora que te has comprometido a adquirir este conocimiento, veamos cómo se te da la ingeniería goblin. Después diseñaremos un currículo para desarrollar tus habilidades en ingeniería goblin.', 0),
(@ID, 'esMX', '¡Bienvenido a bordo, ingeniero goblin $n! Pronto tendrás acceso a los esquemas de ingeniería más poderosos en cualquier parte de Azeroth.$B$BAhora que te has comprometido a adquirir este conocimiento, veamos cómo se te da la ingeniería goblin. Después diseñaremos un currículo para desarrollar tus habilidades en ingeniería goblin.', 0);
