-- 9142 Libranza del artesano
-- https://es.classic.wowhead.com/quest=9142
SET @ID := 9142;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo has ganado, don nadie. Ahora, no llores por tus órdenes. Llénalos o destrúyelos.', 0),
(@ID, 'esMX', 'Te lo has ganado, don nadie. Ahora, no llores por tus órdenes. Llénalos o destrúyelos.', 0);
-- 9151 El Sagrario del Sol
-- https://es.wowhead.com/quest=9151
SET @ID := 9151;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Darenis? Bueno, supongo que tu ayuda nos vendrá bien para luchar contra las huestes de Dar\'Khan.', 0),
(@ID, 'esMX', '¿Te envía Darenis? Bueno, supongo que tu ayuda nos vendrá bien para luchar contra las huestes de Dar\'Khan.', 0);
-- 9153 Bajo la Sombra
-- https://es.classic.wowhead.com/quest=9153
SET @ID := 9153;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eliminar esta amenaza llevará tiempo. ¿Estás $gdispuesto:dispuesta;, $n?', 0),
(@ID, 'esMX', 'Eliminar esta amenaza llevará tiempo. ¿Estás $gdispuesto:dispuesta;, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Pese a las derrotas, conseguiremos rechazar la amenaza de la Peste.$B$BDescansa ahora, pero después tendrás que volver al campo de batalla para defender el terreno ganado hoy.$B$BSi nos traes más runas necróticas, te las cambiaremos por objetos especiales que te ayudarán en tus batallas futuras.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Pese a las derrotas, conseguiremos rechazar la amenaza de la Peste.$B$BDescansa ahora, pero después tendrás que volver al campo de batalla para defender el terreno ganado hoy.$B$BSi nos traes más runas necróticas, te las cambiaremos por objetos especiales que te ayudarán en tus batallas futuras.', 0);
-- 9164 Cautivos en la Ciudad de la Muerte
-- https://es.wowhead.com/quest=9164
SET @ID := 9164;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Boticaria Enith rescatada', `ObjectiveText2` = 'Aprendiz Varnis rescatado', `ObjectiveText4` = 'Forestal Vedoran rescatado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué fue de los prisioneros en la Ciudad de la Muerte? ¿Ya te has aventurado allí?', 0),
(@ID, 'esMX', '¿Qué fue de los prisioneros en la Ciudad de la Muerte? ¿Ya te has aventurado allí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Sin ti esos prisioneros habrían perdido el juicio y el alma a manos de la Plaga.', 0),
(@ID, 'esMX', 'Gracias, $n. Sin ti esos prisioneros habrían perdido el juicio y el alma a manos de la Plaga.', 0);
-- 9165 La libranza de salvoconducto
-- https://es.classic.wowhead.com/quest=9165
SET @ID := 9165;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Salvoconducto firmado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nombre, rango y número de serie!', 0),
(@ID, 'esMX', '¡Nombre, rango y número de serie!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante de envios Metz toma la orden y la firma.>$B$BExcelente trabajo, $n. ¡Sobresaliente incluso! Toma esto como muestra de nuestro agradecimiento. Sin juego de palabras, don nadie.', 0),
(@ID, 'esMX', '<El comandante de envios Metz toma la orden y la firma.>$B$BExcelente trabajo, $n. ¡Sobresaliente incluso! Toma esto como muestra de nuestro agradecimiento. Sin juego de palabras, don nadie.', 0);
-- 9167 La muerte del traidor
-- https://es.wowhead.com/quest=9167
SET @ID := 9167;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho? ¿Has matado a Dar\'Khan?', 0),
(@ID, 'esMX', '¿Lo has hecho? ¿Has matado a Dar\'Khan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has asestado un golpe mortal al dominio de la Plaga en esta región.$B$BAhora que ha muerto el traidor, no tardaremos en recuperar nuestras tierras y nuestra grandeza.', 0),
(@ID, 'esMX', 'Has asestado un golpe mortal al dominio de la Plaga en esta región.$B$BAhora que ha muerto el traidor, no tardaremos en recuperar nuestras tierras y nuestra grandeza.', 0);
-- 9170 Los tenientes de Dar'Khan
-- https://es.wowhead.com/quest=9170
SET @ID := 9170;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado cortar la cadena de mando de la Plaga, $n? ¿Están muertos los lugartenientes de Dar\'Khan?', 0),
(@ID, 'esMX', '¿Has logrado cortar la cadena de mando de la Plaga, $n? ¿Están muertos los lugartenientes de Dar\'Khan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El ejército de Dar\'Khan se derrumba! La Plaga no tiene ninguna posibilidad de resistir ante el poder conjunto de los sin\'dorei y los Renegados.', 0),
(@ID, 'esMX', '¡El ejército de Dar\'Khan se derrumba! La Plaga no tiene ninguna posibilidad de resistir ante el poder conjunto de los sin\'dorei y los Renegados.', 0);
-- 9175 El collar de Sylvanas
-- https://es.wowhead.com/quest=9175
SET @ID := 9175;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dices que lo tenía uno de los miembros de la Plaga en la Aguja Brisaveloz y que hay una inscripción?! ¡A ver!$B$BAquí tienes, una moneda por un buen trabajo.', 0),
(@ID, 'esMX', '¡¿Dices que lo tenía uno de los miembros de la Plaga en la Aguja Brisaveloz y que hay una inscripción?! ¡A ver!$B$BAquí tienes, una moneda por un buen trabajo.', 0);
-- 9178 Libranza del artesano: contrapeso denso
-- https://es.classic.wowhead.com/quest=9178
SET @ID := 9178;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $n?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, estos serán útiles para las armas de ataque de la infantería.', 0),
(@ID, 'esMX', 'Sí, estos serán útiles para las armas de ataque de la infantería.', 0);
-- 9179 Libranza del artesano: peto de placas imperiales
-- https://es.classic.wowhead.com/quest=9179
SET @ID := 9179;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $n?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Más armaduras para las tropas! ¡Fantástico, $n!', 0),
(@ID, 'esMX', '¡Más armaduras para las tropas! ¡Fantástico, $n!', 0);
-- 9180 Viaje a Entrañas
-- https://es.wowhead.com/quest=9180
SET @ID := 9180;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y tú eres...?$B$B¿Qué traes ahí? Ese collar me suena. ¡Dámelo!', 0),
(@ID, 'esMX', '¿Y tú eres...?$B$B¿Qué traes ahí? Ese collar me suena. ¡Dámelo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Sylvanas te arranca el collar de las manos.>$B$B¡No puede ser! Después de tanto tiempo, lo creía perdido para siempre.$B$B<Al cabo de un momento parece volver en sí y recobra la compostura.>$B$B¿Creías que esto me haría gracia? ¿Pensabas acaso que añoro los tiempos anteriores a mi reinado sobre los Renegados? Como tú, esto no significa nada para mí, y Alleria Brisaveloz no es más que un lejano recuerdo!$B$B<Arroja el amuleto al suelo.>$B$BPuedes retirarte, $c.', 0),
(@ID, 'esMX', '<Sylvanas te arranca el collar de las manos.>$B$B¡No puede ser! Después de tanto tiempo, lo creía perdido para siempre.$B$B<Al cabo de un momento parece volver en sí y recobra la compostura.>$B$B¿Creías que esto me haría gracia? ¿Pensabas acaso que añoro los tiempos anteriores a mi reinado sobre los Renegados? Como tú, esto no significa nada para mí, y Alleria Brisaveloz no es más que un lejano recuerdo!$B$B<Arroja el amuleto al suelo.>$B$BPuedes retirarte, $c.', 0);
-- 9181 Libranza del artesano: martillo volcánico
-- https://es.classic.wowhead.com/quest=9181
SET @ID := 9181;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $n?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos deberían ir bien con las densas piedras de peso que estamos acumulando.', 0),
(@ID, 'esMX', 'Estos deberían ir bien con las densas piedras de peso que estamos acumulando.', 0);
-- 9182 Libranza del artesano: hacha de batalla de torio enorme
-- https://es.classic.wowhead.com/quest=9182
SET @ID := 9182;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $n?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No son tan grandes como esperaba. Pero, un trato es un trato.', 0),
(@ID, 'esMX', 'No son tan grandes como esperaba. Pero, un trato es un trato.', 0);
-- 9183 Libranza del artesano: aro radiante
-- https://es.classic.wowhead.com/quest=9183
SET @ID := 9183;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $n?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía no puedo creer que Metz espere que nuestras tropas usen esta basura de baja calidad para protegerse de los congelados ataques de la Plaga.', 0),
(@ID, 'esMX', 'Todavía no puedo creer que Metz espere que nuestras tropas usen esta basura de baja calidad para protegerse de los congelados ataques de la Plaga.', 0);
-- 9184 Libranza del artesano: cinta de cuero maligno
-- https://es.classic.wowhead.com/quest=9184
SET @ID := 9184;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son... malignos.', 0),
(@ID, 'esMX', 'Estos son... malignos.', 0);
-- 9185 Libranza del artesano: refuerzo para armadura basto
-- https://es.classic.wowhead.com/quest=9185
SET @ID := 9185;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los refuerzos de armadura tienen muchos usos, $n. No son SOLO para mejorar ciertas piezas de armadura para mayor protección. Como esta de aquí, la voy a usar como tetera acogedora.', 0),
(@ID, 'esMX', 'Los refuerzos de armadura tienen muchos usos, $n. No son SOLO para mejorar ciertas piezas de armadura para mayor protección. Como esta de aquí, la voy a usar como tetera acogedora.', 0);
-- 9186 Libranza del artesano: cinturón de cuero maligno
-- https://es.classic.wowhead.com/quest=9186
SET @ID := 9186;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos cinturones son en realidad más malignos que las cintas para la cabeza, si puedes creer que tal cosa es posible.', 0),
(@ID, 'esMX', 'Estos cinturones son en realidad más malignos que las cintas para la cabeza, si puedes creer que tal cosa es posible.', 0);
-- 9187 Libranza del artesano: pantalones de cuero rúnico
-- https://es.classic.wowhead.com/quest=9187
SET @ID := 9187;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los druidas definitivamente apreciarán la artesanía que se empleó en la fabricación de estos pantalones. Muchas gracias, $n.', 0),
(@ID, 'esMX', 'Los druidas definitivamente apreciarán la artesanía que se empleó en la fabricación de estos pantalones. Muchas gracias, $n.', 0);
-- 9188 Libranza del artesano: pantalones de paño brillante
-- https://es.classic.wowhead.com/quest=9188
SET @ID := 9188;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Casi puedo ver mi reflejo en estas cosas! Esto es una locura.', 0),
(@ID, 'esMX', '¡Casi puedo ver mi reflejo en estas cosas! Esto es una locura.', 0);
-- 9189 Entrega a El Sepulcro
-- https://es.wowhead.com/quest=9189
SET @ID := 9189;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $ghermano:hermana;. ¿Qué novedades traes?', 0),
(@ID, 'esMX', 'Saludos, $ghermano:hermana;. ¿Qué novedades traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo aquí que el Embajador Penasol tiene grandes esperanzas en tu continuo ascenso como un valor para los sin\'dorei. Sin embargo, desafortunado ese asunto con Lady Sylvanas. No le hagas caso, $n, hiciste lo correcto al devolverle el collar. Debería haber estado agradecida, pero así es la realeza.$B$BMientras estés aquí, si decides ayudar con las tareas de los Renegados, comportate lo mejor que puedas. No querrías dañar nuestro nuevo vínculo con la Horda, ¿verdad?', 0),
(@ID, 'esMX', 'Veo aquí que el Embajador Penasol tiene grandes esperanzas en tu continuo ascenso como un valor para los sin\'dorei. Sin embargo, desafortunado ese asunto con Lady Sylvanas. No le hagas caso, $n, hiciste lo correcto al devolverle el collar. Debería haber estado agradecida, pero así es la realeza.$B$BMientras estés aquí, si decides ayudar con las tareas de los Renegados, comportate lo mejor que puedas. No querrías dañar nuestro nuevo vínculo con la Horda, ¿verdad?', 0);
-- 9190 Libranza del artesano: botas de paño rúnico
-- https://es.classic.wowhead.com/quest=9190
SET @ID := 9190;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por la barba de Barbabronce! Me has traido botas de paño rúnico... Supongo que perdí esa apuesta.', 0),
(@ID, 'esMX', '¡Por la barba de Barbabronce! Me has traido botas de paño rúnico... Supongo que perdí esa apuesta.', 0);
-- 9191 Libranza del artesano: bolsa de paño rúnico
-- https://es.classic.wowhead.com/quest=9191
SET @ID := 9191;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gBendito:Bendita; seas! ¿Son esos lo que creo que son? Las tropas se han estado quejando sin parar por la falta de espacio de almacenamiento para todo lo que se requiere mientras están en el campo. Uno de ellos incluso me dibujó un diagrama...$B$BEstos definitivamente ayudarán a aliviar algunos de los lloriqueos.', 0),
(@ID, 'esMX', '¡$gBendito:Bendita; seas! ¿Son esos lo que creo que son? Las tropas se han estado quejando sin parar por la falta de espacio de almacenamiento para todo lo que se requiere mientras están en el campo. Uno de ellos incluso me dibujó un diagrama...$B$BEstos definitivamente ayudarán a aliviar algunos de los lloriqueos.', 0);
-- 9194 Libranza del artesano: toga de paño rúnico
-- https://es.classic.wowhead.com/quest=9194
SET @ID := 9194;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No deberías haberlo hecho! No, en serio, no deberías haberlo hecho. No sé qué está pensando Metz, pero nadie usará estas túnicas en Naxxramas.$B$B<El maestro de manada Mazadura suspira.>$B$BBah, tendré que transferir otro montón de basura al frente y otra reprimenda más del Mariscal de campo Cuevas.', 0),
(@ID, 'esMX', '¡No deberías haberlo hecho! No, en serio, no deberías haberlo hecho. No sé qué está pensando Metz, pero nadie usará estas túnicas en Naxxramas.$B$B<El maestro de manada Mazadura suspira.>$B$BBah, tendré que transferir otro montón de basura al frente y otra reprimenda más del Mariscal de campo Cuevas.', 0);
-- 9195 Libranza del artesano: carga de zapador goblin
-- https://es.classic.wowhead.com/quest=9195
SET @ID := 9195;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora estás hablando mi idioma, $n. Cosas que hacen BOOM!', 0),
(@ID, 'esMX', 'Ahora estás hablando mi idioma, $n. Cosas que hacen BOOM!', 0);
-- 9196 Libranza del artesano: granada de torio
-- https://es.classic.wowhead.com/quest=9196
SET @ID := 9196;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deben haber costado una bonita pieza de cobre. ¿Tengo razón o tengo razón, $n?', 0),
(@ID, 'esMX', 'Deben haber costado una bonita pieza de cobre. ¿Tengo razón o tengo razón, $n?', 0);
-- 9197 Libranza del artesano: gallo de batalla gnómico
-- https://es.classic.wowhead.com/quest=9197
SET @ID := 9197;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué sonríes? ¿Que es tan gracioso? Escucha, $gseñorito:señorita;, un pollo de batalla gnómico es una unidad muy importante y no debe tomarse a la ligera, NUNCA. Los enviamos a áreas que podrían estar muy plagadas o infestadas y limpian cualquier insecto plagado o gusanos carroñeros que aún puedan estar revoloteando. Todo el mundo sabe que los robots son inmunes a la plaga.$B$BApuesto a que no te sientes tan inteligente ahora, ¿verdad? Maniquí grande...', 0),
(@ID, 'esMX', '¿Por qué sonríes? ¿Que es tan gracioso? Escucha, $gseñorito:señorita;, un pollo de batalla gnómico es una unidad muy importante y no debe tomarse a la ligera, NUNCA. Los enviamos a áreas que podrían estar muy plagadas o infestadas y limpian cualquier insecto plagado o gusanos carroñeros que aún puedan estar revoloteando. Todo el mundo sabe que los robots son inmunes a la plaga.$B$BApuesto a que no te sientes tan inteligente ahora, ¿verdad? Maniquí grande...', 0);
-- 9198 Libranza del artesano: tubo de torio
-- https://es.classic.wowhead.com/quest=9198
SET @ID := 9198;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tubos de torio? Vaya, gracias.$B$B<El maestro de manada Mazadura arroja la pila de tubos de torio a una gran pila de chatarra variada.>', 0),
(@ID, 'esMX', 'Tubos de torio? Vaya, gracias.$B$B<El maestro de manada Mazadura arroja la pila de tubos de torio a una gran pila de chatarra variada.>', 0);
-- 9200 Libranza del artesano: poción de maná sublime
-- https://es.classic.wowhead.com/quest=9200
SET @ID := 9200;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La utilidad de esto debería ser evidente.', 0),
(@ID, 'esMX', 'La utilidad de esto debería ser evidente.', 0);
-- 9201 Libranza del artesano: poción de Protección contra lo Arcano superior
-- https://es.classic.wowhead.com/quest=9201
SET @ID := 9201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Maestro de manada Mazadura abre una de las pociones de protección arcana y bebe un trago.>$B$B¡WOOT! ¡Esto ta pega una patada en el pecho, bebé! ¡Una buena patada!', 0),
(@ID, 'esMX', '<El Maestro de manada Mazadura abre una de las pociones de protección arcana y bebe un trago.>$B$B¡WOOT! ¡Esto ta pega una patada en el pecho, bebé! ¡Una buena patada!', 0);
-- 9202 Libranza del artesano: poción de sanación sublime
-- https://es.classic.wowhead.com/quest=9202
SET @ID := 9202;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes cómo las llaman las tropas en el frente? Sacerdotes embotellados...$B$B<Canta el maestro de manada Mazadura.>$B$B"Soy tu sacerdote embotellado bebé... tienes que beberme de la manera correcta..."$B$B¿Qué pasa $ghijo:hija;? Es una canción muy popular en estos lugares.', 0),
(@ID, 'esMX', '¿Sabes cómo las llaman las tropas en el frente? Sacerdotes embotellados...$B$B<Canta el maestro de manada Mazadura.>$B$B"Soy tu sacerdote embotellado bebé... tienes que beberme de la manera correcta..."$B$B¿Qué pasa $ghijo:hija;? Es una canción muy popular en estos lugares.', 0);
-- 9203 Libranza del artesano: poción de petrificación
-- https://es.classic.wowhead.com/quest=9203
SET @ID := 9203;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin comentarios.$B$B<El maestro de manada Mazadura te fulmina con la mirada.>$B$B¡Dije sin comentarios! ¡Ahora sal de mi vista!', 0),
(@ID, 'esMX', 'Sin comentarios.$B$B<El maestro de manada Mazadura te fulmina con la mirada.>$B$B¡Dije sin comentarios! ¡Ahora sal de mi vista!', 0);
-- 9204 Libranza del artesano: anguila escama pétrea
-- https://es.classic.wowhead.com/quest=9204
SET @ID := 9204;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Podrías haber usado esto para otra cosa, pero no lo hiciste, ¿verdad? No sirve de nada llorar por eso ahora, $n.', 0),
(@ID, 'esMX', 'Podrías haber usado esto para otra cosa, pero no lo hiciste, ¿verdad? No sirve de nada llorar por eso ahora, $n.', 0);
-- 9205 Libranza del artesano: pez coraza de placas
-- https://es.classic.wowhead.com/quest=9205
SET @ID := 9205;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Realmente no sabes para qué son?$B$B<El maestro de manada Mazadura se ríe.>$B$B¡Como te diría...!', 0),
(@ID, 'esMX', '¿Realmente no sabes para qué son?$B$B<El maestro de manada Mazadura se ríe.>$B$B¡Como te diría...!', 0);
-- 9206 Libranza del artesano: anguila relámpago
-- https://es.classic.wowhead.com/quest=9206
SET @ID := 9206;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Completando una orden de trabajo, $c?', 0),
(@ID, 'esMX', '¿Completando una orden de trabajo, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos hacen los mejores rollos de anguila del mundo. Eso es así - DE TODO EL MUNDO.', 0),
(@ID, 'esMX', 'Estos hacen los mejores rollos de anguila del mundo. Eso es así - DE TODO EL MUNDO.', 0);
