-- 9758 Regresa junto al arcanista Vandril
-- https://es.wowhead.com/quest=9758
SET @ID := 9758;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah bien, ahí estás! Y justo a tiempo... ¡Hay mucho por hacer!', 0),
(@ID, 'esMX', '¡Ah bien, ahí estás! Y justo a tiempo... ¡Hay mucho por hacer!', 0);
-- 9192 Problemas en las Minas Sondaluz
-- https://es.wowhead.com/quest=9192
SET @ID := 9192;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gQuerido:Querida;, ¿son buenas noticias o malas?', 0),
(@ID, 'esMX', '$gQuerido:Querida;, ¿son buenas noticias o malas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen trabajo de carnicería, $c. Ahora mandaremos a los mineros volver al trabajo. Seguro que lamentarán que se les acabe el descanso pero hay que fabricar armaduras y armas y eso requiere mineral que se debe extraer.$B$BToma, acepta esto como pago por cumplir con tu deber. Ve a que te reparen la armadura y las armas y tómate algo, invito yo.', 0),
(@ID, 'esMX', 'Un buen trabajo de carnicería, $c. Ahora mandaremos a los mineros volver al trabajo. Seguro que lamentarán que se les acabe el descanso pero hay que fabricar armaduras y armas y eso requiere mineral que se debe extraer.$B$BToma, acepta esto como pago por cumplir con tu deber. Ve a que te reparen la armadura y las armas y tómate algo, invito yo.', 0);
-- 9155 Limpiar La Cicatriz Muerta
-- https://es.wowhead.com/quest=9155
SET @ID := 9155;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya terminaste con tu tarea?', 0),
(@ID, 'esMX', '¿Ya terminaste con tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está mal, $n. Sigue así; necesitamos a más gente como tú por aquí.', 0),
(@ID, 'esMX', 'No está mal, $n. Sigue así; necesitamos a más gente como tú por aquí.', 0);
-- 9149 La costa apestada
-- https://es.wowhead.com/quest=9149
SET @ID := 9149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado los especímenes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has encontrado los especímenes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¡Estas espinas dorsales no tienen precio para mi investigación! Cuando encuentre una cura para la peste y se haga famoso mi nombre, ¡me aseguraré de que recibas el debido crédito!$B$BMientras tanto, acepta esto como recompensa. Pueden hacerte falta si decides volver a la costa.', 0),
(@ID, 'esMX', '¡Estupendo! ¡Estas espinas dorsales no tienen precio para mi investigación! Cuando encuentre una cura para la peste y se haga famoso mi nombre, ¡me aseguraré de que recibas el debido crédito!$B$BMientras tanto, acepta esto como recompensa. Pueden hacerte falta si decides volver a la costa.', 0);
-- 9156 Se busca: Putrenudillos y Luzran
-- https://es.wowhead.com/quest=9156
SET @ID := 9156;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah... ¡Luzran y Putrenudillos! Ya no sois tan duros, ¿eh? Pero seguís igual de feos.$B$BElige una recompensa, $n. Te la has ganado.', 0),
(@ID, 'esMX', 'Ah... ¡Luzran y Putrenudillos! Ya no sois tan duros, ¿eh? Pero seguís igual de feos.$B$BElige una recompensa, $n. Te la has ganado.', 0);
-- 9171 Texturas crujientes
-- https://es.wowhead.com/quest=9171
SET @ID := 9171;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oigo rugir el estómago de la dama desde aquí! ¿Me traes las patas de araña?', 0),
(@ID, 'esMX', '¡Oigo rugir el estómago de la dama desde aquí! ¿Me traes las patas de araña?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, me apañaré con estas. No me describas a los bichos vivos, ¡no quiero saberlo! Les daré mi toque mágico a estas patas y saldrán muy buenas. Un poquito de especias, finas hierbas y por supuesto algunos ingredientes arcanos, y voilà, una comida digna de una reina. O de una dama en este caso.$B$BBuen trabajo, $c. Ten, una receta y unas muestras.', 0),
(@ID, 'esMX', 'Bien, me apañaré con estas. No me describas a los bichos vivos, ¡no quiero saberlo! Les daré mi toque mágico a estas patas y saldrán muy buenas. Un poquito de especias, finas hierbas y por supuesto algunos ingredientes arcanos, y voilà, una comida digna de una reina. O de una dama en este caso.$B$BBuen trabajo, $c. Ten, una receta y unas muestras.', 0);
-- 9130 Mercancía de Ciudad de Lunargenta
-- https://es.wowhead.com/quest=9130
SET @ID := 9130;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¿qué es esto?', 0),
(@ID, 'esMX', 'Sí, ¿qué es esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sathiel quiere que vayas a la Ciudad de Lunargenta y le lleves sus bienes, ¿vale? Desde luego que puedo llevarte allí rápidamente... por una módica cantidad, claro.', 0),
(@ID, 'esMX', 'Sathiel quiere que vayas a la Ciudad de Lunargenta y le lleves sus bienes, ¿vale? Desde luego que puedo llevarte allí rápidamente... por una módica cantidad, claro.', 0);
-- 9138 La Aldea Corona del Sol
-- https://es.wowhead.com/quest=9138
SET @ID := 9138;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tu ayuda conseguiremos contener el problema de la Plaga, $c. ¡Dar\'Khan será tratado!$B$B¿Ya has resuelto el problema nerubiano en la aldea Corona del Sol?', 0),
(@ID, 'esMX', 'Con tu ayuda conseguiremos contener el problema de la Plaga, $c. ¡Dar\'Khan será tratado!$B$B¿Ya has resuelto el problema nerubiano en la aldea Corona del Sol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso! ¡Pero aún queda mucho por hacer antes de que la amenaza de la Plaga se aleje de la poderosa Quel\'Thalas!$B$BAquí tienes, acepta esta moneda... no es gran cosa pero te la has ganado.', 0),
(@ID, 'esMX', '¡Asombroso! ¡Pero aún queda mucho por hacer antes de que la amenaza de la Plaga se aleje de la poderosa Quel\'Thalas!$B$BAquí tienes, acepta esta moneda... no es gran cosa pero te la has ganado.', 0);
-- 9133 Vuelo a la Ciudad de Lunargenta
-- https://es.wowhead.com/quest=9133
SET @ID := 9133;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es una señora lista, amigo. A ver, a ver...', 0),
(@ID, 'esMX', 'Eso es una señora lista, amigo. A ver, a ver...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡¿Qué Sathiel quiere todo esto!?$B$B¿Has traído a alguien para que te ayude a llevarlo?', 0),
(@ID, 'esMX', '¿Qué es esto? ¡¿Qué Sathiel quiere todo esto!?$B$B¿Has traído a alguien para que te ayude a llevarlo?', 0);
-- 9134 La maestra del cielo Anochecer
-- https://es.wowhead.com/quest=9134
SET @ID := 9134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esa caja parece muy pesada! ¿No querrás cargarla en una de mis hermosuras voladoras?', 0),
(@ID, 'esMX', '¡Esa caja parece muy pesada! ¿No querrás cargarla en una de mis hermosuras voladoras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te vuelves a la Aldea Brisa Pura en el Bosque Canción Eterna? ¡Déjame a mí, verás qué pronto llegas!', 0),
(@ID, 'esMX', '¿Te vuelves a la Aldea Brisa Pura en el Bosque Canción Eterna? ¡Déjame a mí, verás qué pronto llegas!', 0);
-- 9135 Regresa junto a Sathiel
-- https://es.wowhead.com/quest=9135
SET @ID := 9135;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tan pronto de vuelta, $c? No parece que tengas todo lo que te pedí...', 0),
(@ID, 'esMX', '¿Tan pronto de vuelta, $c? No parece que tengas todo lo que te pedí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, si dijo que el resto llegaría pronto por tierra, creeré en su palabra. Desde luego, nunca ha dejado tirado con un envío.$B$BGracias, $n. Toma esta moneda... no hace más que dar vueltas todo el día en mi bolsillo.', 0),
(@ID, 'esMX', 'Bueno, si dijo que el resto llegaría pronto por tierra, creeré en su palabra. Desde luego, nunca ha dejado tirado con un envío.$B$BGracias, $n. Toma esta moneda... no hace más que dar vueltas todo el día en mi bolsillo.', 0);
-- 1 Misión de Kanrethad
-- https://es.wowhead.com/quest=1
SET @ID := 1;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acuérdate de tus talentos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 17 Componentes de Uldaman
-- https://es.classic.wowhead.com/quest=17
SET @ID := 17;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes las setas moradas? ¡Si no, no te pago!', 0),
(@ID, 'esMX', '¿Me traes las setas moradas? ¡Si no, no te pago!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has hecho un buen trabajo otra vez, $n! Esto va a ser muy interesante.$B$BY como te prometí, aquí tienes uno de mis mejores elixires vigorizantes.$B$BSi te interesa la alquimia, puedo ofrecerte otros trabajos. En todo caso, te agradezco tu ayuda.', 0),
(@ID, 'esMX', '¡Has hecho un buen trabajo otra vez, $n! Esto va a ser muy interesante.$B$BY como te prometí, aquí tienes uno de mis mejores elixires vigorizantes.$B$BSi te interesa la alquimia, puedo ofrecerte otros trabajos. En todo caso, te agradezco tu ayuda.', 0);
-- 55 Morbent Vil
-- https://es.classic.wowhead.com/quest=55
SET @ID := 55;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Morbent Vil matado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 71 Informa a Thomas
-- https://es.classic.wowhead.com/quest=71
SET @ID := 71;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has averiguado qué suerte corrieron Rolf y Malakai?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has averiguado qué suerte corrieron Rolf y Malakai?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has confirmado mis temores, $n. Los murlocs son una amenaza que no podemos ignorar.', 0),
(@ID, 'esMX', 'Has confirmado mis temores, $n. Los murlocs son una amenaza que no podemos ignorar.', 0);
-- 189 Orejas de Sangrapellejo
-- https://es.classic.wowhead.com/quest=189
SET @ID := 189;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas tenido éxito... Hay trols por todas partes. Asquerosos demonios.$B$B¡Por cierto, eso me recuerda algo! Asegúrate de decírselo a tus amigos, ¿vale? ¡Necesitamos mucha ayuda!', 0),
(@ID, 'esMX', 'Espero que hayas tenido éxito... Hay trols por todas partes. Asquerosos demonios.$B$B¡Por cierto, eso me recuerda algo! Asegúrate de decírselo a tus amigos, ¿vale? ¡Necesitamos mucha ayuda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh excelente, excelente. Esto ayudará un poco, por ahora...$B$B<Su voz se hace casi imperceptible, masculla algo sobre margen de beneficio y costes...>$B$B¿Qué? ¿Todavía estáis aquí? ¿Recompensa? Oh, vale... claro, aquí tienes... debería ser más que suficiente.', 0),
(@ID, 'esMX', 'Oh excelente, excelente. Esto ayudará un poco, por ahora...$B$B<Su voz se hace casi imperceptible, masculla algo sobre margen de beneficio y costes...>$B$B¿Qué? ¿Todavía estáis aquí? ¿Recompensa? Oh, vale... claro, aquí tienes... debería ser más que suficiente.', 0);
-- 198 Suministros para el soldado Thorsen
-- https://es.classic.wowhead.com/quest=198
SET @ID := 198;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Qué quieres? Oh, suministros de los goblins. Es extraño ver a $gun:una; $r entregándolos, generalmente mandan a alguien de los suyos. No pasa nada... ¿no los habrás tocado, verdad? Bien, bien... No querríamos que nada pasase en nuestras minas. No, no, no.', 0),
(@ID, 'esMX', '¿Sí? ¿Qué quieres? Oh, suministros de los goblins. Es extraño ver a $gun:una; $r entregándolos, generalmente mandan a alguien de los suyos. No pasa nada... ¿no los habrás tocado, verdad? Bien, bien... No querríamos que nada pasase en nuestras minas. No, no, no.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas minas terrestres nos ayudan a defendernos de ese animal Kurzen y de sus hombres. Gracias por traerlas. Si buscas más trabajo, probablemente pueda encontrar algo para ti. Y no tendrás que tratar con esos goblins, ¿mm?', 0),
(@ID, 'esMX', 'Estas minas terrestres nos ayudan a defendernos de ese animal Kurzen y de sus hombres. Gracias por traerlas. Si buscas más trabajo, probablemente pueda encontrar algo para ti. Y no tendrás que tratar con esos goblins, ¿mm?', 0);
-- 201 Investiga el campamento
-- https://es.classic.wowhead.com/quest=201
SET @ID := 201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bien? ¿Tuviste suerte localizando el campamento?', 0),
(@ID, 'esMX', '¿Bien? ¿Tuviste suerte localizando el campamento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, así que mi información era correcta, como siempre. Bueno, no creo que representen amenaza alguna de interferencia con nuestra operación, pero quizás necesiten alguno de los extraordinarios productos que hemos producido. Mmm...', 0),
(@ID, 'esMX', 'Mmm, así que mi información era correcta, como siempre. Bueno, no creo que representen amenaza alguna de interferencia con nuestra operación, pero quizás necesiten alguno de los extraordinarios productos que hemos producido. Mmm...', 0);
-- 213 OPA hostil
-- https://es.classic.wowhead.com/quest=213
SET @ID := 213;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito esos cristales, $n. ¡Haz lo que sea para conseguirlo! Hazlo, no me des detalles.$B$BTodo se trata del resultado, $n, nada más y nada menos.', 0),
(@ID, 'esMX', 'Necesito esos cristales, $n. ¡Haz lo que sea para conseguirlo! Hazlo, no me des detalles.$B$BTodo se trata del resultado, $n, nada más y nada menos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fascinante. El que los cristales se hayan caído con este proceso solo puede indicar que piensan usarlos para algún tipo de combustible o catalizador. Eso es todo lo que sé. Habrá que enviar muestras al químico jefe Gigglefont.', 0),
(@ID, 'esMX', 'Fascinante. El que los cristales se hayan caído con este proceso solo puede indicar que piensan usarlos para algún tipo de combustible o catalizador. Eso es todo lo que sé. Habrá que enviar muestras al químico jefe Gigglefont.', 0);
-- 267 La amenaza trogg
-- https://es.classic.wowhead.com/quest=267
SET @ID := 267;
UPDATE `quest_template_locale` SET `Objectives` = 'Lleva 8 dientes de trogg de piedra al capitán Rugelfuss a la torre de vigilancia sur.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes los 8 petrodientes de trogg? Si no, no sé qué haces aquí, $n.', 0),
(@ID, 'esMX', '¿Me traes los 8 petrodientes de trogg? Si no, no sé qué haces aquí, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n. Los enanos quedan en deuda contigo. ¡El rey Magni Barbabronce estaría orgulloso!', 0),
(@ID, 'esMX', 'Impresionante, $n. Los enanos quedan en deuda contigo. ¡El rey Magni Barbabronce estaría orgulloso!', 0);
 -- 348 La fiebre de Tuercespina
-- https://es.classic.wowhead.com/quest=348
SET @ID := 348;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... ¿Madre?$B$B... tanto frío...$B$B... hacia El Vacío Abismal... a-abrázame, madre...', 0),
(@ID, 'esMX', '... ¿Madre?$B$B... tanto frío...$B$B... hacia El Vacío Abismal... a-abrázame, madre...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... Siento que... la fuerza... vuelve a mí...$B$B¿Dónde estoy? ¿Bahía del Botín? ¡Cielos! He tenido un sueño de lo más extraño...$B$B... todavía me sigo sintiendo débil...', 0),
(@ID, 'esMX', '... Siento que... la fuerza... vuelve a mí...$B$B¿Dónde estoy? ¿Bahía del Botín? ¡Cielos! He tenido un sueño de lo más extraño...$B$B... todavía me sigo sintiendo débil...', 0);
-- 349 La fiebre de Tuercespina
-- https://es.classic.wowhead.com/quest=349
SET @ID := 349;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El médico brujo Unbagwa sabe lo que gustar a Mokk el Salvaje. ¡Sí, sí!$B$BYo hablar con espíritus y hacer que venga, sí, sí.$B$BPero haber otro espíritu como de gorila hablando también. Tú proteger al médico brujo Unbagwa y yo hacer que él venir.$B$BEl médico brujo Unbagwa quiere algo primero. ¡Trae 10 colmillos de gorila y yo empezar a hablar con espíritus!', 0),
(@ID, 'esMX', 'El médico brujo Unbagwa sabe lo que gustar a Mokk el Salvaje. ¡Sí, sí!$B$BYo hablar con espíritus y hacer que venga, sí, sí.$B$BPero haber otro espíritu como de gorila hablando también. Tú proteger al médico brujo Unbagwa y yo hacer que él venir.$B$BEl médico brujo Unbagwa quiere algo primero. ¡Trae 10 colmillos de gorila y yo empezar a hablar con espíritus!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al médico brujo Unbagwa gustarle colmillos de gorila! Por ti yo hablar con espíritus. Haz que venga Mokk el Salvaje.$B$BPero tú proteger al médico brujo Unbagwa de otra bestia gorila, ¡o no hay Mokk!', 0),
(@ID, 'esMX', '¡Al médico brujo Unbagwa gustarle colmillos de gorila! Por ti yo hablar con espíritus. Haz que venga Mokk el Salvaje.$B$BPero tú proteger al médico brujo Unbagwa de otra bestia gorila, ¡o no hay Mokk!', 0);
