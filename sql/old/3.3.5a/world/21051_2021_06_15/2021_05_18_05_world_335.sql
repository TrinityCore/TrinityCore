-- 9779 Interceptando el mensaje
-- https://es.wowhead.com/quest=9779
SET @ID := 9779;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto? ¿Has encontrado la carta?', 0),
(@ID, 'esMX', '¿Ya has vuelto? ¿Has encontrado la carta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El vindicador Boros observa el documento.>$B$BEsto está en thalassiano. Por suerte, conozco a alguien que puede traducirlo...', 0),
(@ID, 'esMX', '<El vindicador Boros observa el documento.>$B$BEsto está en thalassiano. Por suerte, conozco a alguien que puede traducirlo...', 0);
-- 9780 Filetes de anguila de Umbropantano
-- https://es.wowhead.com/quest=9780
SET @ID := 9780;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes pescado para nuestras tiendas?', 0),
(@ID, 'esMX', '¿Tienes pescado para nuestras tiendas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Tu generosidad no se olvidará.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Tu generosidad no se olvidará.', 0);
-- 9781 Demasiadas bocas que alimentar
-- https://es.wowhead.com/quest=9781
SET @ID := 9781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $gamigo:amiga;?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $gamigo:amiga;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. Eso debería suavizar la demanda de suministros alimenticios por aquí, al menos en un futuro inmediato, aunque vamos a necesitar encontrar nuevas fuentes de comida. Los champiñones y los peces son bastante, pero deberíamos empezar a pensar en variar.', 0),
(@ID, 'esMX', 'Bien hecho. Eso debería suavizar la demanda de suministros alimenticios por aquí, al menos en un futuro inmediato, aunque vamos a necesitar encontrar nuevas fuentes de comida. Los champiñones y los peces son bastante, pero deberíamos empezar a pensar en variar.', 0);
-- 9782 El Lodo Muerto
-- https://es.wowhead.com/quest=9782
SET @ID := 9782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la muestra de tierra de El Lodo Muerto?', 0),
(@ID, 'esMX', '¿Has conseguido la muestra de tierra de El Lodo Muerto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... Parece que la tierra está agotada, así que no puede ser la causa del problema como había pensado. ¿Cuál será el vínculo de unión? ¿Por qué está todo empezando a morir?', 0),
(@ID, 'esMX', 'Mmm... Parece que la tierra está agotada, así que no puede ser la causa del problema como había pensado. ¿Cuál será el vínculo de unión? ¿Por qué está todo empezando a morir?', 0);
-- 9783 Una sequía no natural
-- https://es.wowhead.com/quest=9783
SET @ID := 9783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me duele matar a las criaturas de El Lodo Muerto , pero no se pueden salvar. Lo mejor que podemos hacer es trabajar para restaurar el área y nutrir a una nueva generación.', 0),
(@ID, 'esMX', 'Me duele matar a las criaturas de El Lodo Muerto , pero no se pueden salvar. Lo mejor que podemos hacer es trabajar para restaurar el área y nutrir a una nueva generación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por ayudarme con esta difícil tarea, $n. Nuestro trabajo en El Lodo Muerto todavía no se ha terminado, pero nuestros esfuerzos se centrarán en hacer lo que podamos para restaurar el equilibrio de la zona.', 0),
(@ID, 'esMX', 'Gracias por ayudarme con esta difícil tarea, $n. Nuestro trabajo en El Lodo Muerto todavía no se ha terminado, pero nuestros esfuerzos se centrarán en hacer lo que podamos para restaurar el equilibrio de la zona.', 0);
-- 9784 Identificar partes de plantas
-- https://es.wowhead.com/quest=9784
SET @ID := 9784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito más partes de plantas. Ahora que los lagos están perdiendo el agua, sospecho que las especies invasoras están proliferando, pero necesito más muestras para defender esta teoría.', 0),
(@ID, 'esMX', 'Necesito más partes de plantas. Ahora que los lagos están perdiendo el agua, sospecho que las especies invasoras están proliferando, pero necesito más muestras para defender esta teoría.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Si encuentras más partes de plantas, no dejes de traérmelas.$B$B<Esta misión se puede repetir hasta el nivel de reputación honorable.>', 0),
(@ID, 'esMX', 'Excelente. Si encuentras más partes de plantas, no dejes de traérmelas.$B$B<Esta misión se puede repetir hasta el nivel de reputación honorable.>', 0);
-- 9785 Bendición de los ancestros
-- https://es.wowhead.com/quest=9785
SET @ID := 9785;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Marca de conocimiento', `ObjectiveText2` = 'Marca de guerra', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has hablado con los ancestros, $n?', 0),
(@ID, 'esMX', '¿Ya has hablado con los ancestros, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has regresado. ¿Has recibido ya la bendición de los ancestros?', 0),
(@ID, 'esMX', 'Veo que has regresado. ¿Has recibido ya la bendición de los ancestros?', 0);
-- 9786 Las Ruinas Boha'mu
-- https://es.wowhead.com/quest=9786
SET @ID := 9786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has examinado las ruinas de Boha\'mu? ¿Te imaginas cómo eran en todo su esplendor?', 0),
(@ID, 'esMX', '¿Has examinado las ruinas de Boha\'mu? ¿Te imaginas cómo eran en todo su esplendor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Los Perdidos de Feropantano han invadido las ruinas? Fascinante; deben de conservar recuerdos de su legado y el significado del lugar. Tenemos que saber más, $n. Este templo podría ser la clave para redimir a Los Perdidos y reunir las muchas ramas de draenei.', 0),
(@ID, 'esMX', '¿Así que Los Perdidos de Feropantano han invadido las ruinas? Fascinante; deben de conservar recuerdos de su legado y el significado del lugar. Tenemos que saber más, $n. Este templo podría ser la clave para redimir a Los Perdidos y reunir las muchas ramas de draenei.', 0);
-- 9787 Ídolos de Feropantano
-- https://es.wowhead.com/quest=9787
SET @ID := 9787;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los ídolos?', 0),
(@ID, 'esMX', '¿Traes los ídolos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con esto bastará, $n. Parecen tener una fijación con los pájaros, lo que resulta curioso porque no hay pájaros autóctonos en la Marisma de Zangar. ¿Qué significará esto?$B$B¿Es posible que se encontraran con los arakkoa? Un pueblo chamánico podría verlos como la encarnación de algún espíritu pájaro poderoso.', 0),
(@ID, 'esMX', 'Con esto bastará, $n. Parecen tener una fijación con los pájaros, lo que resulta curioso porque no hay pájaros autóctonos en la Marisma de Zangar. ¿Qué significará esto?$B$B¿Es posible que se encontraran con los arakkoa? Un pueblo chamánico podría verlos como la encarnación de algún espíritu pájaro poderoso.', 0);
-- 9788 Un lugar húmedo y sombrío
-- https://es.wowhead.com/quest=9788
SET @ID := 9788;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mis cosas, $n? La cueva no está lejos de Umbropantano, cerca de la frontera con Nagrand.', 0),
(@ID, 'esMX', '¿Has encontrado mis cosas, $n? La cueva no está lejos de Umbropantano, cerca de la frontera con Nagrand.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mis pertenencias! ¡Está todo aquí!$B$BTe lo agradezco, $n. Como te prometí, te dejo escoger uno de los objetos. No tengo mucho que ofrecer, pero mi gente siempre comparte lo poco que tiene.', 0),
(@ID, 'esMX', '¡Mis pertenencias! ¡Está todo aquí!$B$BTe lo agradezco, $n. Como te prometí, te dejo escoger uno de los objetos. No tengo mucho que ofrecer, pero mi gente siempre comparte lo poco que tiene.', 0);
-- 9789 Cacería de uñagrietas
-- https://es.wowhead.com/quest=9789
SET @ID := 9789;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las uñagrietas de Nagrand son un buen desafío. Me he anotado bastantes.$B$B¿Cómo te va con ellos?', 0),
(@ID, 'esMX', 'Las uñagrietas de Nagrand son un buen desafío. Me he anotado bastantes.$B$B¿Cómo te va con ellos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen comienzo pero, es solo eso, un comienzo.$B$BEl uñagrieta menor no prueba nada. Pasemos a un desafío mayor.', 0),
(@ID, 'esMX', 'Un buen comienzo pero, es solo eso, un comienzo.$B$BEl uñagrieta menor no prueba nada. Pasemos a un desafío mayor.', 0);
-- 9790 Alas diáfanas
-- https://es.wowhead.com/quest=9790
SET @ID := 9790;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido alas diáfanas?', 0),
(@ID, 'esMX', '¿Has conseguido alas diáfanas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$B<Haalrun sonríe con simpatía.>$B$BAl menos tú no tienes que limpiarlas. Esa es la peor parte, pero cuando están limpias, nunca sabrías que formaban parte de un insecto gigante.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$B<Haalrun sonríe con simpatía.>$B$BAl menos tú no tienes que limpiarlas. Esa es la peor parte, pero cuando están limpias, nunca sabrías que formaban parte de un insecto gigante.', 0);
-- 9791 La amenaza de los Colmillo de la Marisma
-- https://es.wowhead.com/quest=9791
SET @ID := 9791;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito en tu búsqueda de colmillos de la marisma?', 0),
(@ID, 'esMX', '¿Has tenido éxito en tu búsqueda de colmillos de la marisma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por ayudarnos a destruir algunos destripadores Colmillo de la Marisma, $n. Si fuesen inteligentes, quizás aprenderían que es mejor vivir y dejar vivir a los demás.$B$B<Noraani se encoge de hombros.>$B$BBichos gigantes con inteligencia. Me pregunto cómo sería eso...', 0),
(@ID, 'esMX', 'Gracias por ayudarnos a destruir algunos destripadores Colmillo de la Marisma, $n. Si fuesen inteligentes, quizás aprenderían que es mejor vivir y dejar vivir a los demás.$B$B<Noraani se encoge de hombros.>$B$BBichos gigantes con inteligencia. Me pregunto cómo sería eso...', 0);
-- 9792 Un mensaje para Telaar
-- https://es.wowhead.com/quest=9792
SET @ID := 9792;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ikuti es como un hermano para mí. Cualquier amigo suyo es amigo mío. Te doy la bienvenida, $n, y tienes nuestro agradecimiento por haber ayudado a nuestro pueblo.', 0),
(@ID, 'esMX', 'Ikuti es como un hermano para mí. Cualquier amigo suyo es amigo mío. Te doy la bienvenida, $n, y tienes nuestro agradecimiento por haber ayudado a nuestro pueblo.', 0);
-- 9793 El destino de Tuurem
-- https://es.wowhead.com/quest=9793
SET @ID := 9793;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... recuerdo haber oído a nuestros exploradores hablando sobre las ruinas de un asentamiento $r en el extremo norte del bosque. No sé mucho sobre las ruinas, pero puedes hablar con los exploradores.', 0),
(@ID, 'esMX', 'Mmm... recuerdo haber oído a nuestros exploradores hablando sobre las ruinas de un asentamiento $r en el extremo norte del bosque. No sé mucho sobre las ruinas, pero puedes hablar con los exploradores.', 0);
-- 9794 No hay tiempo para la curiosidad
-- https://es.wowhead.com/quest=9794
SET @ID := 9794;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kialon te mira con sospecha.>$B$BNo te conozco, $r. ¿Haces negocios conmigo?', 0),
(@ID, 'esMX', '<Kialon te mira con sospecha.>$B$BNo te conozco, $r. ¿Haces negocios conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que me traes la respuesta de Timothy?$B$B<Kialon se detiene un momento para leer la carta y luego se ríe.>$B$BDice que lo tiene todo bajo control. Dice que no necesita ayuda. ¡Me lo imaginaba!$B$BHay algunos que nunca cambian. Mira, incluso se tomó la libertad de corregir mi ortografía.$B$B<Kialon suspira.>$B$BNo debería haberle enviado la carta. Lo olvidé. El especialista siempre tiene la situación bajo control. Siempre.', 0),
(@ID, 'esMX', '¿Así que me traes la respuesta de Timothy?$B$B<Kialon se detiene un momento para leer la carta y luego se ríe.>$B$BDice que lo tiene todo bajo control. Dice que no necesita ayuda. ¡Me lo imaginaba!$B$BHay algunos que nunca cambian. Mira, incluso se tomó la libertad de corregir mi ortografía.$B$B<Kialon suspira.>$B$BNo debería haberle enviado la carta. Lo olvidé. El especialista siempre tiene la situación bajo control. Siempre.', 0);
-- 9795 La amenaza de los ogros
-- https://es.wowhead.com/quest=9795
SET @ID := 9795;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Denjai busca ayuda? Yo le enviaré refuerzos aunque no nos sobren precisamente. Tenemos nuestros propios problemas con los ogros de ahí arriba.$B$BEn cuanto pueda le informaré sobre las tribus ogras locales y sus tácticas. Si consigue sobrevivir los suficiente, podremos coordinar un ataque conjunto sobre las posiciones de esa escoria.', 0),
(@ID, 'esMX', '¿Denjai busca ayuda? Yo le enviaré refuerzos aunque no nos sobren precisamente. Tenemos nuestros propios problemas con los ogros de ahí arriba.$B$BEn cuanto pueda le informaré sobre las tribus ogras locales y sus tácticas. Si consigue sobrevivir los suficiente, podremos coordinar un ataque conjunto sobre las posiciones de esa escoria.', 0);
-- 9796 Noticias de la Marisma de Zangar
-- https://es.wowhead.com/quest=9796
SET @ID := 9796;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya es hora de que acabe esa avanzada. Ya hemos perdido demasiados corredores a manos de las escoltas de la Alianza.', 0),
(@ID, 'esMX', 'Ya es hora de que acabe esa avanzada. Ya hemos perdido demasiados corredores a manos de las escoltas de la Alianza.', 0);
-- 9797 Refuerzos para Garadar
-- https://es.wowhead.com/quest=9797
SET @ID := 9797;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Incluso aunque pretende ocultarlo, una mirada de alivio asoma a la cara de Kroghan.>$B$B¡Ya era hora de que llegaras! Está claro que no eres un ejército, pero cualquier $r capaz que pueda empuñar un arma o decir un encantamiento es bienvenido aquí. Las gentes de Garadar son hermanas de la Horda y nos enorgullece poder derramar nuestra sangre en su defensa.', 0),
(@ID, 'esMX', '<Incluso aunque pretende ocultarlo, una mirada de alivio asoma a la cara de Kroghan.>$B$B¡Ya era hora de que llegaras! Está claro que no eres un ejército, pero cualquier $r capaz que pueda empuñar un arma o decir un encantamiento es bienvenido aquí. Las gentes de Garadar son hermanas de la Horda y nos enorgullece poder derramar nuestra sangre en su defensa.', 0);
-- 9798 Planes de los elfos de sangre
-- https://es.wowhead.com/quest=9798
SET @ID := 9798;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A ver, déjame leer esos planes.$B$B¿Los elfos de sangre nos han seguido hasta aquí? Son terriblemente malvados, deberíamos acabar con todos ellos.$B$B<El vindicador hace una pausa para recuperar la compostura.>$B$BPerdona, eso no era necesario. Estamos en deuda contigo por la información que nos has proporcionado, $n.', 0),
(@ID, 'esMX', 'A ver, déjame leer esos planes.$B$B¿Los elfos de sangre nos han seguido hasta aquí? Son terriblemente malvados, deberíamos acabar con todos ellos.$B$B<El vindicador hace una pausa para recuperar la compostura.>$B$BPerdona, eso no era necesario. Estamos en deuda contigo por la información que nos has proporcionado, $n.', 0);
-- 9799 Trabajo de campo
-- https://es.wowhead.com/quest=9799
SET @ID := 9799;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Traes las flores?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Traes las flores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos especímenes tienen buen aspecto. Gracias por ocuparte del trabajo de campo. Cuando los haya analizado, podré determinar qué hay que hacer para restaurar los campos.', 0),
(@ID, 'esMX', 'Estos especímenes tienen buen aspecto. Gracias por ocuparte del trabajo de campo. Cuando los haya analizado, podré determinar qué hay que hacer para restaurar los campos.', 0);
-- 9800 Una extraña judía
-- https://es.wowhead.com/quest=9800
SET @ID := 9800;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El elementalista Lo\'ap cierra sus manos en puños y mueve la cabeza expresando su desaprobación.>$B$BDe tamaño de ogro...', 0),
(@ID, 'esMX', '<El elementalista Lo\'ap cierra sus manos en puños y mueve la cabeza expresando su desaprobación.>$B$BDe tamaño de ogro...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, no te laves en las aguas sagradas de El Trono.$B$B<El elementalista Lo\'ap levanta una píldora de anacardos preparada.>$B$BMétetela bajo la lengua y dale tiempo para que se disuelva. Cuando se haya disuelto, podrás respirar en el agua como si estuvieses en la superficie.', 0),
(@ID, 'esMX', 'Por favor, no te laves en las aguas sagradas de El Trono.$B$B<El elementalista Lo\'ap levanta una píldora de anacardos preparada.>$B$BMétetela bajo la lengua y dale tiempo para que se disuelva. Cuando se haya disuelto, podrás respirar en el agua como si estuvieses en la superficie.', 0);
-- 9801 Recogiendo componentes
-- https://es.wowhead.com/quest=9801
SET @ID := 9801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has reunido los componentes?', 0),
(@ID, 'esMX', '¿Has reunido los componentes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífico. Dame un momento para preparar la poción.', 0),
(@ID, 'esMX', 'Magnífico. Dame un momento para preparar la poción.', 0);
-- 9802 Plantas de Marisma de Zangar
-- https://es.wowhead.com/quest=9802
SET @ID := 9802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes partes de plantas, $n?', 0),
(@ID, 'esMX', '¿Traes partes de plantas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La degradación de las especies autóctonas es preocupante, desde luego. Las especies invasoras pueden estar relacionadas con la alteración reciente del ecosistema. Pero aún no dispongo de datos suficientes para alcanzar una conclusión.$B$B<Lauranna toma notas en un diario mientras clasifica las partes de plantas.>$B$BTen, $n, esto te puede ser útil.$B$BTráeme todas las partes de plantas que encuentres; las incluiré en mis estadísticas.', 0),
(@ID, 'esMX', 'La degradación de las especies autóctonas es preocupante, desde luego. Las especies invasoras pueden estar relacionadas con la alteración reciente del ecosistema. Pero aún no dispongo de datos suficientes para alcanzar una conclusión.$B$B<Lauranna toma notas en un diario mientras clasifica las partes de plantas.>$B$BTen, $n, esto te puede ser útil.$B$BTráeme todas las partes de plantas que encuentres; las incluiré en mis estadísticas.', 0);
-- 9803 Mensajero de los Feropantanos
-- https://es.wowhead.com/quest=9803
SET @ID := 9803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hablado ya con el anciano Feropantano?', 0),
(@ID, 'esMX', '¿Has hablado ya con el anciano Feropantano?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se han negado? Pueden elegir su propio camino, por supuesto, pero me sorprende su decisión. Pensaba que todos los Tábidos y Los Perdidos, recordarían que todos somos parte del mismo pueblo.$B$BSupongo que tiene razón pero, aun así, ¿no puede ver que nuestras intenciones son buenas?', 0),
(@ID, 'esMX', '¿Se han negado? Pueden elegir su propio camino, por supuesto, pero me sorprende su decisión. Pensaba que todos los Tábidos y Los Perdidos, recordarían que todos somos parte del mismo pueblo.$B$BSupongo que tiene razón pero, aun así, ¿no puede ver que nuestras intenciones son buenas?', 0);
-- 9804 Espíritus agitados de Sol Celeste
-- https://es.wowhead.com/quest=9804
SET @ID := 9804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Utiliza las cerezas de Nagrand antes de adentrarse demasiado en el lago.', 0),
(@ID, 'esMX', 'Utiliza las cerezas de Nagrand antes de adentrarse demasiado en el lago.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El elementalista Lo\'ap se arrodilla en el agua y reza una oración.>$B$BEl Anillo de la Tierra no se enorgullece de lo que ha hecho. Hacemos lo que debemos para curar la tierra.', 0),
(@ID, 'esMX', '<El elementalista Lo\'ap se arrodilla en el agua y reza una oración.>$B$BEl Anillo de la Tierra no se enorgullece de lo que ha hecho. Hacemos lo que debemos para curar la tierra.', 0);
-- 9805 Bendición de Incineratus
-- https://es.wowhead.com/quest=9805
SET @ID := 9805;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cabaña Grande destruida', `ObjectiveText2` = 'Cabaña del Oeste destruida', `ObjectiveText3` = 'Cabaña del Sur destruida', `ObjectiveText4` = 'Cabaña del Este destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con gran vergüenza te digo que son mis propios parientes los que buscan subir las aguas de Nagrand y crear un pantano.', 0),
(@ID, 'esMX', 'Con gran vergüenza te digo que son mis propios parientes los que buscan subir las aguas de Nagrand y crear un pantano.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus esfuerzos han sofocado la polución, pero han aparecido otros problemas.', 0),
(@ID, 'esMX', 'Tus esfuerzos han sofocado la polución, pero han aparecido otros problemas.', 0);
-- 9806 Esporas fértiles
-- https://es.wowhead.com/quest=9806
SET @ID := 9806;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Has conseguido las esporas fértiles?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Has conseguido las esporas fértiles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son unas esporas estupendas, $n. Los tallolargo son vitales para la reconstrucción de nuestro pueblo. Y, después de todos los ataques de señores de la marisma que hemos sufrido, estamos muy mal de suministros.', 0),
(@ID, 'esMX', 'Son unas esporas estupendas, $n. Los tallolargo son vitales para la reconstrucción de nuestro pueblo. Y, después de todos los ataques de señores de la marisma que hemos sufrido, estamos muy mal de suministros.', 0);
-- 9807 Más esporas
-- https://es.wowhead.com/quest=9807
SET @ID := 9807;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre podemos usar más esporas fértiles, $r. Los tallos son hongos increíblemente útiles. Poder cultivarlos nos permite hacer muchas cosas con ellos.', 0),
(@ID, 'esMX', 'Siempre podemos usar más esporas fértiles, $r. Los tallos son hongos increíblemente útiles. Poder cultivarlos nos permite hacer muchas cosas con ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se agradece tu ayuda, $n. Seguirás así, ¿no?', 0),
(@ID, 'esMX', 'Se agradece tu ayuda, $n. Seguirás así, ¿no?', 0);
-- 9808 Fluochampiñones
-- https://es.wowhead.com/quest=9808
SET @ID := 9808;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste fluochampiñones, $n? Están por todas partes en la marisma.$B$BSi te fijas, se ven brillar desde lejos.', 0),
(@ID, 'esMX', '¿Encontraste fluochampiñones, $n? Están por todas partes en la marisma.$B$BSi te fijas, se ven brillar desde lejos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con esto podremos negociar con otros esporinos para conseguir alimento y suministros. ¡Esporaggar te da las gracias, $n!', 0),
(@ID, 'esMX', 'Con esto podremos negociar con otros esporinos para conseguir alimento y suministros. ¡Esporaggar te da las gracias, $n!', 0);
-- 9809 Más fluochampiñones
-- https://es.wowhead.com/quest=9809
SET @ID := 9809;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tomaré más fluochampiñones si los tienes. Nuestro pueblo siempre puede usar más de ellos.', 0),
(@ID, 'esMX', 'Tomaré más fluochampiñones si los tienes. Nuestro pueblo siempre puede usar más de ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Como anciano de Esporaggar, debo asegurarme de que mi gente tenga los suministros adecuados. Haces mi tarea mucho más fácil.', 0),
(@ID, 'esMX', 'Gracias, $n. Como anciano de Esporaggar, debo asegurarme de que mi gente tenga los suministros adecuados. Haces mi tarea mucho más fácil.', 0);
-- 9810 El espíritu contaminado
-- https://es.wowhead.com/quest=9810
SET @ID := 9810;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Anillo de la Tierra te ayudará en todo lo posible.', 0),
(@ID, 'esMX', 'El Anillo de la Tierra te ayudará en todo lo posible.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los elementos celebraron tu victoria desde el momento en que la esencia contaminada fue destruida! El Anillo de la Tierra te da las gracias y quiere que elijas una recompensa.', 0),
(@ID, 'esMX', '¡Los elementos celebraron tu victoria desde el momento en que la esencia contaminada fue destruida! El Anillo de la Tierra te da las gracias y quiere que elijas una recompensa.', 0);
-- 9811 Amigos de los sin'dorei
-- https://es.wowhead.com/quest=9811
SET @ID := 9811;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Buscas audiencia conmigo? No recuerdo que tengamos una cita.', 0),
(@ID, 'esMX', '¿Buscas audiencia conmigo? No recuerdo que tengamos una cita.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que mataste a Dar\'Khan, $r? Impresionante. Tengo la sensación de que mi gente y la tuya pronto llegarán a ser muy buenos amigos.', 0),
(@ID, 'esMX', '¿Así que mataste a Dar\'Khan, $r? Impresionante. Tengo la sensación de que mi gente y la tuya pronto llegarán a ser muy buenos amigos.', 0);
-- 9812 Enviado de la Horda
-- https://es.wowhead.com/quest=9812
SET @ID := 9812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me dijeron que vendría un visitante de Quel\'Thalas. Esperaba un elfo de sangre, a decir verdad.$B$B¿Qué novedades traes?', 0),
(@ID, 'esMX', 'Me dijeron que vendría un visitante de Quel\'Thalas. Esperaba un elfo de sangre, a decir verdad.$B$B¿Qué novedades traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces está hecho. El vil traidor obtuvo lo que se merecía.$B$BHas prestado un gran servicio a los elfos de sangre y a la Horda. Dar\'khan fue la excusa de Thrall para negarles la entrada a nuestra alianza. Has despejado el camino para una nueva Horda, $c.$B$BTambién veo que Lor\'themar tiene noticias adicionales que mejorarán enormemente sus relaciones con Thrall. ¡Excelente!', 0),
(@ID, 'esMX', 'Entonces está hecho. El vil traidor obtuvo lo que se merecía.$B$BHas prestado un gran servicio a los elfos de sangre y a la Horda. Dar\'khan fue la excusa de Thrall para negarles la entrada a nuestra alianza. Has despejado el camino para una nueva Horda, $c.$B$BTambién veo que Lor\'themar tiene noticias adicionales que mejorarán enormemente sus relaciones con Thrall. ¡Excelente!', 0);
