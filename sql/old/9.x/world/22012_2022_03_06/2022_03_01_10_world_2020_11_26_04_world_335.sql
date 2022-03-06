-- 336 Una noble cerveza
-- https://es.classic.wowhead.com/quest=336
SET @ID := 336;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estoy con mucho lío? ¡Escucha mis palabras! ¡Soy muy importante para el futuro de este reino!$B$BOh... ¿Qué tienes ahí? Porque parece una bebida refrescante...', 0),
(@ID, 'esMX', '¿No ves que estoy con mucho lío? ¡Escucha mis palabras! ¡Soy muy importante para el futuro de este reino!$B$BOh... ¿Qué tienes ahí? Porque parece una bebida refrescante...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, gracias por traerme esta estupenda cerveza negra, sirviente. Aquí tienes una moneda de cobre. Y ahora, ¡lárgate y déjame disfrutar mi bebida!', 0),
(@ID, 'esMX', 'Ah, gracias por traerme esta estupenda cerveza negra, sirviente. Aquí tienes una moneda de cobre. Y ahora, ¡lárgate y déjame disfrutar mi bebida!', 0);
-- 337 Un libro viejo de Historia
-- https://es.classic.wowhead.com/quest=337
SET @ID := 337;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ooh! ¿Qué es ese libro viejo que tienes ahí? ¿Puedo verlo?', 0),
(@ID, 'esMX', '¡Ooh! ¿Qué es ese libro viejo que tienes ahí? ¿Puedo verlo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay, ay! Este libro no descansa en estos estantes desde antes de la reconstrucción de Ventormenta. Habrá que restaurarlo, claro, está en un estado lamentable, pero me honraría colocarlo entre los otros libros raros de nuestra colección.$B$BGracias, $gseñor:señora;. ¡Acepta esto como pago por la devolución del libro!', 0),
(@ID, 'esMX', '¡Ay, ay! Este libro no descansa en estos estantes desde antes de la reconstrucción de Ventormenta. Habrá que restaurarlo, claro, está en un estado lamentable, pero me honraría colocarlo entre los otros libros raros de nuestra colección.$B$BGracias, $gseñor:señora;. ¡Acepta esto como pago por la devolución del libro!', 0);
-- 350 Mira por un viejo amigo
-- https://es.classic.wowhead.com/quest=350
SET @ID := 350;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo dices en serio? ¿Shaw quiere mi ayuda otra vez? Menuda desfachatez...$B$B¿La Hermandad Defias, dices? Bueno, ciertamente traes muy buenas noticias, ¿eh? Lo próximo que me vas a decir es que Alamuerte sigue con vida y está atacando la ciudad.$B$BMuy bien, cuéntamelo todo, desde el principio. Y no te dejes nada que creas que no es importante. Necesito saberlo todo.', 0),
(@ID, 'esMX', '¿Lo dices en serio? ¿Shaw quiere mi ayuda otra vez? Menuda desfachatez...$B$B¿La Hermandad Defias, dices? Bueno, ciertamente traes muy buenas noticias, ¿eh? Lo próximo que me vas a decir es que Alamuerte sigue con vida y está atacando la ciudad.$B$BMuy bien, cuéntamelo todo, desde el principio. Y no te dejes nada que creas que no es importante. Necesito saberlo todo.', 0);
-- 351 ¡Encontrar a OOX-17/TN!
-- https://es.classic.wowhead.com/quest=351
SET @ID := 351;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0),
(@ID, 'esMX', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el localizador de emergencia con forma de... huevo en el interior del... pollo robótico.$B$BMientras el robot lucha por ponerse en pie, se escuchan una serie de zumbidos provenientes de su interior. Cuando el robot cobra vida, se escucha una vez más la voz de Oglethorpe, en esta ocasión desde el interior del robot:$B$B"OOX-17/TN funciona otra vez pero necesita ciertas reparaciones. Es demasiado pesado para que puedas traerlo... pero se me ocurre una idea. ¿Te apetece seguir cuidando de él?"', 0),
(@ID, 'esMX', 'Colocas el localizador de emergencia con forma de... huevo en el interior del... pollo robótico.$B$BMientras el robot lucha por ponerse en pie, se escuchan una serie de zumbidos provenientes de su interior. Cuando el robot cobra vida, se escucha una vez más la voz de Oglethorpe, en esta ocasión desde el interior del robot:$B$B"OOX-17/TN funciona otra vez pero necesita ciertas reparaciones. Es demasiado pesado para que puedas traerlo... pero se me ocurre una idea. ¿Te apetece seguir cuidando de él?"', 0);
-- 354 Muertes en la familia
-- https://es.classic.wowhead.com/quest=354
SET @ID := 354;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los restos de la familia Agamand? ¿Has acabado al fin con esas malditas bestias?', 0),
(@ID, 'esMX', '¿Tienes los restos de la familia Agamand? ¿Has acabado al fin con esas malditas bestias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La venganza es dulce, ¿no crees? Cuando acabaste con los Agamand, ¿eran conscientes de lo que estaba pasando? Eso espero. Espero que sintieran miedo antes de pasar a mejor vida.$B$BYa sé que es un deseo absurdo pero no puedo evitar pensar en ello.', 0),
(@ID, 'esMX', 'La venganza es dulce, ¿no crees? Cuando acabaste con los Agamand, ¿eran conscientes de lo que estaba pasando? Eso espero. Espero que sintieran miedo antes de pasar a mejor vida.$B$BYa sé que es un deseo absurdo pero no puedo evitar pensar en ello.', 0);
-- 355 Habla con Sevren
-- https://es.classic.wowhead.com/quest=355
SET @ID := 355;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coleman habla maravillas de ti, $n, sobre todo de tu exitosa incursión en los Molinos de Agamand.$B$BLos Renegados necesitan tu ayuda una vez más...', 0),
(@ID, 'esMX', 'Coleman habla maravillas de ti, $n, sobre todo de tu exitosa incursión en los Molinos de Agamand.$B$BLos Renegados necesitan tu ayuda una vez más...', 0);
-- 356 Patrulla de la retaguardia
-- https://es.classic.wowhead.com/quest=356
SET @ID := 356;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes un informe de tu patrulla?', 0),
(@ID, 'esMX', '¿Tienes un informe de tu patrulla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Con tus esfuerzos ayudas a mantener a raya a la Plaga. Enviaré una mención honorífica a mi superior, el ejecutor Zygand.', 0),
(@ID, 'esMX', 'Muy bien. Con tus esfuerzos ayudas a mantener a raya a la Plaga. Enviaré una mención honorífica a mi superior, el ejecutor Zygand.', 0);
-- 357 La identidad del exánime
-- https://es.classic.wowhead.com/quest=357
SET @ID := 357;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has conseguido el libro?', 0),
(@ID, 'esMX', '$n, ¿has conseguido el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Con este libro podré descubrir la identidad de ese exánime. Has servido con diligencia a la Reina.$B$B<Bethor abre el libro y mira fijamente sus brillantes páginas>$B$B¡No puedo creerlo! ¡El libro pertenece nada más y nada menos que a Gunther Arcanos!$B$BEn vida, Gunther era un gran Necromántico. Ambos éramos compañeros de armas antes de la llegada de la Peste. A juzgar por lo que veo aquí, parece que tras su muerte se hizo todavía más poderoso.$B$B¿Sabes? Sus facultades nos vendrían muy bien.', 0),
(@ID, 'esMX', 'Muy bien, $n. Con este libro podré descubrir la identidad de ese exánime. Has servido con diligencia a la Reina.$B$B<Bethor abre el libro y mira fijamente sus brillantes páginas>$B$B¡No puedo creerlo! ¡El libro pertenece nada más y nada menos que a Gunther Arcanos!$B$BEn vida, Gunther era un gran Necromántico. Ambos éramos compañeros de armas antes de la llegada de la Peste. A juzgar por lo que veo aquí, parece que tras su muerte se hizo todavía más poderoso.$B$B¿Sabes? Sus facultades nos vendrían muy bien.', 0);
-- 358 Profanadores
-- https://es.classic.wowhead.com/quest=358
SET @ID := 358;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has finalizado tu tarea? ¿Has destruido a esa especie de perros y obtenido su icor?', 0),
(@ID, 'esMX', '¿Has finalizado tu tarea? ¿Has destruido a esa especie de perros y obtenido su icor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien hecho, $n. La Plaga se equivoca si cree que podrá usar esos cuerpos en nuestra contra. Nuestros boticarios estudiarán el fluido que has recogido de los esclavos Putrepellejo pues es posible que albergue secretos que podamos utilizar contra ellos.$B$BComo ya he dicho, lo has hecho muy bien pero nuestra lucha continúa y con seguridad podrás seguir demostrando tu valía a los Renegados.', 0),
(@ID, 'esMX', 'Muy bien hecho, $n. La Plaga se equivoca si cree que podrá usar esos cuerpos en nuestra contra. Nuestros boticarios estudiarán el fluido que has recogido de los esclavos Putrepellejo pues es posible que albergue secretos que podamos utilizar contra ellos.$B$BComo ya he dicho, lo has hecho muy bien pero nuestra lucha continúa y con seguridad podrás seguir demostrando tu valía a los Renegados.', 0);
-- 359 Las obligaciones de los Renegados
-- https://es.classic.wowhead.com/quest=359
SET @ID := 359;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conque el magistrado Sevren quiere un informe, ¿eh? Muy bien: los defensores de El Baluarte están conteniendo a la mayor parte de los miembros de la Plaga aunque alguno siempre se las arregla para colarse.$B$BHemos detectado cierta actividad esporádica de la Plaga al este de aquí, especialmente importante en Hacienda Balnir.', 0),
(@ID, 'esMX', 'Conque el magistrado Sevren quiere un informe, ¿eh? Muy bien: los defensores de El Baluarte están conteniendo a la mayor parte de los miembros de la Plaga aunque alguno siempre se las arregla para colarse.$B$BHemos detectado cierta actividad esporádica de la Plaga al este de aquí, especialmente importante en Hacienda Balnir.', 0);
-- 360 Regresa junto al magistrado
-- https://es.classic.wowhead.com/quest=360
SET @ID := 360;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es preocupante saber que la Plaga consigue superar la seguridad de El Baluarte. El rey Exánime y sus esbirros no cesan en sus ataques.$B$BPero no nos rendiremos. ¡Nunca volverá a cogernos!', 0),
(@ID, 'esMX', 'Es preocupante saber que la Plaga consigue superar la seguridad de El Baluarte. El rey Exánime y sus esbirros no cesan en sus ataques.$B$BPero no nos rendiremos. ¡Nunca volverá a cogernos!', 0);
-- 361 Una carta sin entregar
-- https://es.classic.wowhead.com/quest=361
SET @ID := 361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh... mi pobre Thurman! Le supliqué que abandonara Molinos de Agamand conmigo y mi padre pero su lealtad a la familia era demasiado fuerte. ¡Lo sabía! ¡Sabía que Brand quería hacerle daño! ¡Maldita sea la Peste y maldita sea la Plaga!$B$B<Yvette se calma y se pone seria.>$B$BPero lamentarse es de débiles. Como Renegada tengo nuevas metas y el amor no está entre ellas. En otro tiempo, te hubiera dado las gracias por haberme entregado esta carta y brindarme la oportunidad de saber qué había sido de mi antiguo amor.$B$BPero esa vida se acabó para siempre.', 0),
(@ID, 'esMX', '¡Oh... mi pobre Thurman! Le supliqué que abandonara Molinos de Agamand conmigo y mi padre pero su lealtad a la familia era demasiado fuerte. ¡Lo sabía! ¡Sabía que Brand quería hacerle daño! ¡Maldita sea la Peste y maldita sea la Plaga!$B$B<Yvette se calma y se pone seria.>$B$BPero lamentarse es de débiles. Como Renegada tengo nuevas metas y el amor no está entre ellas. En otro tiempo, te hubiera dado las gracias por haberme entregado esta carta y brindarme la oportunidad de saber qué había sido de mi antiguo amor.$B$BPero esa vida se acabó para siempre.', 0);
-- 362 Los molinos fantasma
-- https://es.classic.wowhead.com/quest=362
SET @ID := 362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Devlin?', 0),
(@ID, 'esMX', '¿Has encontrado a Devlin?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Los huesos de Devlin quedarán de maravilla en mi manto.$B$BLo único que puede consolar a mi pobre corazón es ver el fin de los Agamand. Ellos nos fallaron a mi familia y a mí cuando llegó la Peste... ¡juro acabar con todos ellos!', 0),
(@ID, 'esMX', 'Gracias. Los huesos de Devlin quedarán de maravilla en mi manto.$B$BLo único que puede consolar a mi pobre corazón es ver el fin de los Agamand. Ellos nos fallaron a mi familia y a mí cuando llegó la Peste... ¡juro acabar con todos ellos!', 0);
-- 363 Desvelo brutal
-- https://es.classic.wowhead.com/quest=363
SET @ID := 363;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, otro muerto que camina... Ha debido de ser un shock... despertarse en la cripta con el frío y Mordo como única compañía...$B$BVeo en tu cara que estás muy confuso. Deja que te explique nuestra... situación.$B$BHemos sido liberados del control del Rey Exánime por nuestra nueva líder, Lady Sylvanas. La Dama Oscura nos guía en una guerra contra la odiada Plaga y contra los humanos que aún no aceptan la situación y nos acosan a cada paso.', 0),
(@ID, 'esMX', 'Mm, otro muerto que camina... Ha debido de ser un shock... despertarse en la cripta con el frío y Mordo como única compañía...$B$BVeo en tu cara que estás muy confuso. Deja que te explique nuestra... situación.$B$BHemos sido liberados del control del Rey Exánime por nuestra nueva líder, Lady Sylvanas. La Dama Oscura nos guía en una guerra contra la odiada Plaga y contra los humanos que aún no aceptan la situación y nos acosan a cada paso.', 0);
-- 364 Los autómatas
-- https://es.classic.wowhead.com/quest=364
SET @ID := 364;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No llegarás lejos en esta nueva vida si no puedes matar ni siquiera al más débil de los zombis, $n. No regrese para informar hasta que tengas éxito.', 0),
(@ID, 'esMX', 'No llegarás lejos en esta nueva vida si no puedes matar ni siquiera al más débil de los zombis, $n. No regrese para informar hasta que tengas éxito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una pena que no podamos hacer entrar en razón a los de la Plaga. Nos vendrían bien para futuras batallas, son muy numerosos.$B$BPero no se unirán a nosotros, así que no tenemos más opción que acabar con ellos', 0),
(@ID, 'esMX', 'Es una pena que no podamos hacer entrar en razón a los de la Plaga. Nos vendrían bien para futuras batallas, son muy numerosos.$B$BPero no se unirán a nosotros, así que no tenemos más opción que acabar con ellos', 0);
-- 365 Campos de pena
-- https://es.classic.wowhead.com/quest=365
SET @ID := 365;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El guardia de la muerte Simmer me dijo que me traerías los componentes que tanto anhelo. $n, ¿has podido reunir 10 calabazas?', 0),
(@ID, 'esMX', 'El guardia de la muerte Simmer me dijo que me traerías los componentes que tanto anhelo. $n, ¿has podido reunir 10 calabazas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has cumplido con tu cometido a la perfección, joven $c. Estás demostrando ser todo un hallazgo para el ejército de la Dama Oscura.', 0),
(@ID, 'esMX', 'Has cumplido con tu cometido a la perfección, joven $c. Estás demostrando ser todo un hallazgo para el ejército de la Dama Oscura.', 0);
-- 366 Devuelve el libro
-- https://es.classic.wowhead.com/quest=366
SET @ID := 366;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tus maestros están locos si piensan que volveré a ser un esclavo de la Plaga!', 0),
(@ID, 'esMX', '¡Tus maestros están locos si piensan que volveré a ser un esclavo de la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mi libro! ¡Así que tú me lo robaste!$B$BPero... este hechizo... ¿¡Bethor!? ¿Está en Lordaeron?$B$BEso significa que quizás también haya escapado del rey Exánime...', 0),
(@ID, 'esMX', '¡Mi libro! ¡Así que tú me lo robaste!$B$BPero... este hechizo... ¿¡Bethor!? ¿Está en Lordaeron?$B$BEso significa que quizás también haya escapado del rey Exánime...', 0);
-- 367 Una nueva Peste
-- https://es.classic.wowhead.com/quest=367
SET @ID := 367;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes ya 5 viales de sangre de can oscuro? ¡El tiempo se agota!', 0),
(@ID, 'esMX', '$n, ¿tienes ya 5 viales de sangre de can oscuro? ¡El tiempo se agota!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n y te agradezco tus esfuerzos.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n y te agradezco tus esfuerzos.', 0);
-- 368 Una nueva Peste
-- https://es.classic.wowhead.com/quest=368
SET @ID := 368;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has conseguido 5 escamas de Anca Vil de los murlocs?', 0),
(@ID, 'esMX', '$n, ¿has conseguido 5 escamas de Anca Vil de los murlocs?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las escamas son perfectas, $n. Son justo lo que necesitaba para el brebaje.', 0),
(@ID, 'esMX', 'Las escamas son perfectas, $n. Son justo lo que necesitaba para el brebaje.', 0);
-- 369 Una nueva Peste
-- https://es.classic.wowhead.com/quest=369
SET @ID := 369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes ya el veneno de araña nocturácnida? Es el último componente que necesito para completar mi experimento.', 0),
(@ID, 'esMX', '$n, ¿tienes ya el veneno de araña nocturácnida? Es el último componente que necesito para completar mi experimento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, este veneno será perfecto, $n. Ya he añadido y cocido los demás ingredientes de mi brebaje. ¡Al fin puedo probar este nuevo agente mortal!', 0),
(@ID, 'esMX', 'Ah, este veneno será perfecto, $n. Ya he añadido y cocido los demás ingredientes de mi brebaje. ¡Al fin puedo probar este nuevo agente mortal!', 0);
-- 370 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=370
SET @ID := 370;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Joven $c, no deberías estar perdiendo el tiempo aquí en Brill cuando tu gente te necesita luchando por su causa. Ahora, toma las armas y viaja hacia el suroeste, a la torre en ruinas, y mata al Capitán Perrine junto con 3 Zelotes Escarlata y 3 Misioneros Escarlata. Llevaremos a la Cruzada Escarlata como ganado hasta su desaparición.', 0),
(@ID, 'esMX', 'Joven $c, no deberías estar perdiendo el tiempo aquí en Brill cuando tu gente te necesita luchando por su causa. Ahora, toma las armas y viaja hacia el suroeste, a la torre en ruinas, y mata al Capitán Perrine junto con 3 Zelotes Escarlata y 3 Misioneros Escarlata. Llevaremos a la Cruzada Escarlata como ganado hasta su desaparición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte del capitán Perrine en verdad complacerá a la Dama Oscura. Has hecho un buen trabajo, $c.', 0),
(@ID, 'esMX', 'La muerte del capitán Perrine en verdad complacerá a la Dama Oscura. Has hecho un buen trabajo, $c.', 0);
-- 371 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=371
SET @ID := 371;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has regresado, pero tu tarea no está completa. ¿Quizás te sientas $gcómodo:cómoda; con los simples humanos que interfieren con el plan de La Dama Oscura? ¡O quizás puedas prestar atención al llamado del deber y matar al Capitán Vachon y su banda de Frailes Escarlatas!', 0),
(@ID, 'esMX', 'Veo que has regresado, pero tu tarea no está completa. ¿Quizás te sientas $gcómodo:cómoda; con los simples humanos que interfieren con el plan de La Dama Oscura? ¡O quizás puedas prestar atención al llamado del deber y matar al Capitán Vachon y su banda de Frailes Escarlatas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte del capitán Vachon frenará algo el avance de la Cruzada Escarlata en Tirisfal, pero se avecinan otras amenazas.', 0),
(@ID, 'esMX', 'La muerte del capitán Vachon frenará algo el avance de la Cruzada Escarlata en Tirisfal, pero se avecinan otras amenazas.', 0);
