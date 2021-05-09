-- La guardia salvaje: arcanum de protección
-- 9208, 9209, 9210
-- https://es.classic.wowhead.com/quest=9208
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9208, 9209, 9210) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9208, 'esES', '¿Tienes el arcanum?', 0),
(9209, 'esES', '¿Tienes el arcanum?', 0),
(9210, 'esES', '¿Tienes el arcanum?', 0),
(9208, 'esMX', '¿Tienes el arcanum?', 0),
(9209, 'esMX', '¿Tienes el arcanum?', 0),
(9210, 'esMX', '¿Tienes el arcanum?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9208, 9209, 9210) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9208, 'esES', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0),
(9209, 'esES', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0),
(9210, 'esES', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0),
(9208, 'esMX', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0),
(9209, 'esMX', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0),
(9210, 'esMX', 'La magia sin valor en estos encantamientos alimenta mi ira. Mi ira me da fuerzas.$B$BTráeme más y recibirás otra Guardia Salvaje.', 0);
-- 9211 El guardahielo
-- https://es.classic.wowhead.com/quest=9211
SET @ID := 9211;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no fuera por estos guardias del Alba Argenta, serías una mancha en el suelo.', 0),
(@ID, 'esMX', 'Si no fuera por estos guardias del Alba Argenta, serías una mancha en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mataus guarda el oro.>$B$BDisfruta de los costos de reparación, $r. Naxxramas es "cruel" con $glos:las; no $giniciados:iniciadas;.', 0),
(@ID, 'esMX', '<Mataus guarda el oro.>$B$BDisfruta de los costos de reparación, $r. Naxxramas es "cruel" con $glos:las; no $giniciados:iniciadas;.', 0);
-- 9212 Huida de las catacumbas
-- https://es.wowhead.com/quest=9212
SET @ID := 9212;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes madera de <héroe/heroína, $c, para sacarla de allí con vida. Supongo que tendremos que lanzar un ataque para despejar esas catacumbas también. ¡Como si no tuviéramos ya bastante con los trols vivos!$B$BHoy has hecho una proeza, debo recompensarte. Elige aquí lo que quieras.', 0),
(@ID, 'esMX', 'Tienes madera de <héroe/heroína, $c, para sacarla de allí con vida. Supongo que tendremos que lanzar un ataque para despejar esas catacumbas también. ¡Como si no tuviéramos ya bastante con los trols vivos!$B$BHoy has hecho una proeza, debo recompensarte. Elige aquí lo que quieras.', 0);
-- 9213 El guardasombras
-- https://es.classic.wowhead.com/quest=9213
SET @ID := 9213;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mataus bosteza.>$B$BVete, insecto, a no ser que tengas algo para mí.', 0),
(@ID, 'esMX', '<Mataus bosteza.>$B$BVete, insecto, a no ser que tengas algo para mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mataus mete el oro en su túnica.>$B$B¿Por qué sigues $gparado:parada;, $r? Nuestro negocio está hecho.', 0),
(@ID, 'esMX', '<Mataus mete el oro en su túnica.>$B$B¿Por qué sigues $gparado:parada;, $r? Nuestro negocio está hecho.', 0);
-- 9220 Guerra a la Ciudad de la Muerte
-- https://es.wowhead.com/quest=9220
SET @ID := 9220;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto $gvictorioso:victoriosa; de la Ciudad de la Muerte, $n?', 0),
(@ID, 'esMX', '¿Has vuelto $gvictorioso:victoriosa; de la Ciudad de la Muerte, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Plaga ha sentido nuestra cólera, $n. Su maldita ciudadela no tardará en convertirse en ruinas.$B$BCon su número debilitado, es hora de lanzar un ataque contra objetivos más estratégicos.', 0),
(@ID, 'esMX', 'La Plaga ha sentido nuestra cólera, $n. Su maldita ciudadela no tardará en convertirse en ruinas.$B$BCon su número debilitado, es hora de lanzar un ataque contra objetivos más estratégicos.', 0);
-- 9229 El destino de Ramaladni
-- https://es.classic.wowhead.com/quest=9229
SET @ID := 9229;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna noticia de Ramaladni?', 0),
(@ID, 'esMX', '¿Alguna noticia de Ramaladni?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Es su anillo! Pero está destruido. ¿No se encontró ninguna otra evidencia de Ramaladni?$B$B<Korfax hace una mueca.>$B$BEsto no augura nada bueno para Ramaladni. Sin embargo, el anillo... podría ser recuperable.', 0),
(@ID, 'esMX', '¡Es su anillo! Pero está destruido. ¿No se encontró ninguna otra evidencia de Ramaladni?$B$B<Korfax hace una mueca.>$B$BEsto no augura nada bueno para Ramaladni. Sin embargo, el anillo... podría ser recuperable.', 0);
-- 9230 La garra helada de Ramaladni
-- https://es.classic.wowhead.com/quest=9230
SET @ID := 9230;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Probablemente se puedan encontrar runas congeladas dentro de Naxxramas.', 0),
(@ID, 'esMX', 'Probablemente se puedan encontrar runas congeladas dentro de Naxxramas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El mismo Ramaladni no podría haberlo hecho mejor! Aquí está el anillo, como prometí.', 0),
(@ID, 'esMX', '¡El mismo Ramaladni no podría haberlo hecho mejor! Aquí está el anillo, como prometí.', 0);
-- 9232 La única canción que conozco
-- https://es.classic.wowhead.com/quest=9232
SET @ID := 9232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te has encontrado con Omarion, ¿verdad?', 0),
(@ID, 'esMX', 'No te has encontrado con Omarion, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Wilhelm se seca el sudor de la frente>.$B$B¡Esto es un trabajo duro! Disfruta los pantalones, $n. Al menos ahora morirás con un par limpio.', 0),
(@ID, 'esMX', '<Wilhelm se seca el sudor de la frente>.$B$B¡Esto es un trabajo duro! Disfruta los pantalones, $n. Al menos ahora morirás con un par limpio.', 0);
-- 9233 Vademécum de Omarion
-- https://es.classic.wowhead.com/quest=9233
SET @ID := 9233;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eso es lo que creo que es?$B$B<Wilhelm está casi babeando.>', 0),
(@ID, 'esMX', '¿Eso es lo que creo que es?$B$B<Wilhelm está casi babeando.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Debía de estar totalmente ido cuando escribió esto! ¡Omarion y yo estábamos unidos como uña y mugre!$B$BPero mira, en cualquier caso, esto me abre nuevas posibilidades, $n. Ahora podré crear más objetos... a cambio de un pequeño honorario, claro está.', 0),
(@ID, 'esMX', '¡Debía de estar totalmente ido cuando escribió esto! ¡Omarion y yo estábamos unidos como uña y mugre!$B$BPero mira, en cualquier caso, esto me abre nuevas posibilidades, $n. Ahora podré crear más objetos... a cambio de un pequeño honorario, claro está.', 0);
-- 9234 Los guanteletes Deliriohelado
-- https://es.classic.wowhead.com/quest=9234
SET @ID := 9234;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído los materiales?', 0),
(@ID, 'esMX', '¿Has traído los materiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(@ID, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0);
-- Los guanteletes Deliriohelado
-- 9234, 9235, 9236, 9237, 9239, 9240, 9241, 9242, 9243, 9244, 9245, 9246
-- https://es.classic.wowhead.com/quest=9234
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9234, 9235, 9236, 9237, 9239, 9240, 9241, 9242, 9243, 9244, 9245, 9246) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9234, 'esES', '¿Has traído los materiales?', 0),
(9235, 'esES', '¿Has traído los materiales?', 0),
(9236, 'esES', '¿Has traído los materiales?', 0),
(9237, 'esES', '¿Has traído los materiales?', 0),
(9239, 'esES', '¿Has traído los materiales?', 0),
(9240, 'esES', '¿Has traído los materiales?', 0),
(9241, 'esES', '¿Has traído los materiales?', 0),
(9242, 'esES', '¿Has traído los materiales?', 0),
(9243, 'esES', '¿Has traído los materiales?', 0),
(9244, 'esES', '¿Has traído los materiales?', 0),
(9245, 'esES', '¿Has traído los materiales?', 0),
(9246, 'esES', '¿Has traído los materiales?', 0),
(9234, 'esMX', '¿Has traído los materiales?', 0),
(9235, 'esMX', '¿Has traído los materiales?', 0),
(9236, 'esMX', '¿Has traído los materiales?', 0),
(9237, 'esMX', '¿Has traído los materiales?', 0),
(9239, 'esMX', '¿Has traído los materiales?', 0),
(9240, 'esMX', '¿Has traído los materiales?', 0),
(9241, 'esMX', '¿Has traído los materiales?', 0),
(9242, 'esMX', '¿Has traído los materiales?', 0),
(9243, 'esMX', '¿Has traído los materiales?', 0),
(9244, 'esMX', '¿Has traído los materiales?', 0),
(9245, 'esMX', '¿Has traído los materiales?', 0),
(9246, 'esMX', '¿Has traído los materiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9234, 9235, 9236, 9237, 9239, 9240, 9241, 9242, 9243, 9244, 9245, 9246) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9234, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9235, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9236, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9237, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9239, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9240, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9241, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9242, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9243, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9244, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9245, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9246, 'esES', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9234, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9235, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9236, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9237, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9239, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9240, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9241, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9242, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9243, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9244, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9245, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0),
(9246, 'esMX', 'Aquí está tu pedido, $n. ¡Entregado según lo prometido!', 0);
-- 9238 Las muñequeras glaciales
-- https://es.classic.wowhead.com/quest=9238
SET @ID := 9238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa es una cara que no esperaba ver tan pronto.$B$BÉsta es una buena noticia. $n, en más formas de las que puedas imaginar.', 0),
(@ID, 'esMX', 'Esa es una cara que no esperaba ver tan pronto.$B$BÉsta es una buena noticia. $n, en más formas de las que puedas imaginar.', 0);
-- 9247 La llamada de los guardianes
-- https://es.classic.wowhead.com/quest=9247
SET @ID := 9247;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te debemos gratitud por el simple hecho de haber respondido, $n. Esperamos que tu ejemplo anime a otros a unirse a nuestra lucha contra la Peste.', 0),
(@ID, 'esMX', 'Te debemos gratitud por el simple hecho de haber respondido, $n. Esperamos que tu ejemplo anime a otros a unirse a nuestra lucha contra la Peste.', 0);
-- 9248 Una humilde ofrenda
-- https://es.classic.wowhead.com/quest=9248
SET @ID := 9248;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Fandu-dath-belore? Oh, perdóname, $n. No te reconocí. ¿Tienes el cetro?', 0),
(@ID, 'esMX', '¿Fandu-dath-belore? Oh, perdóname, $n. No te reconocí. ¿Tienes el cetro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ande\'thoras-ethil. en mi lengua materna significa; \'Que tus problemas disminuyan\'.$B$BUse la banda con orgullo y con buena salud, $n.', 0),
(@ID, 'esMX', 'Ande\'thoras-ethil. en mi lengua materna significa; \'Que tus problemas disminuyan\'.$B$BUse la banda con orgullo y con buena salud, $n.', 0);
-- 9249 40 vales: esquema (mando de tonque de vapor)
-- https://es.wowhead.com/quest=9249
SET @ID := 9249;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Da un paso adelante, un paso adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(@ID, 'esMX', '¡Da un paso adelante, un paso adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de un rey! ¡Felicidades, $gamigo mío:amiga mia;!$B$BSi tiene más vales que te gustaría cambiar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé todos tus vales.', 0),
(@ID, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de un rey! ¡Felicidades, $gamigo mío:amiga mia;!$B$BSi tiene más vales que te gustaría cambiar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé todos tus vales.', 0);
-- 9250 Cuerpo de Atiesh
-- https://es.classic.wowhead.com/quest=9250
SET @ID := 9250;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Era tu momento, mortal.', 0),
(@ID, 'esMX', 'Era tu momento, mortal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los archimagos han muerto.$B$BNo lamentes su muerte, $n. Todas esas cosas están predestinadas. Así como estaba destinado a sostener el bastón del Guardián...', 0),
(@ID, 'esMX', 'Los archimagos han muerto.$B$BNo lamentes su muerte, $n. Todas esas cosas están predestinadas. Así como estaba destinado a sostener el bastón del Guardián...', 0);
-- 9251 Atiesh, el gran báculo maligno
-- https://es.classic.wowhead.com/quest=9251
SET @ID := 9251;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su forma actual, el bastón es demasiado peligroso para estar en manos de un mortal.', 0),
(@ID, 'esMX', 'En su forma actual, el bastón es demasiado peligroso para estar en manos de un mortal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay un ser dentro... un ser que no es de este mundo.', 0),
(@ID, 'esMX', 'Hay un ser dentro... un ser que no es de este mundo.', 0);
-- Atiesh, el gran báculo del guardián
-- 9257, 9269, 9270, 9271
-- https://es.classic.wowhead.com/quest=9257
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has limpiado Atiesh', `VerifiedBuild` = 0 WHERE `id` IN(9257, 9269, 9270, 9271) AND `locale` IN('esES', 'esMX');
-- 9259 Un traidor de Velasangre
-- https://es.classic.wowhead.com/quest=9259
SET @ID := 9259;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ese perro sarnoso, Revilgaz, se ha ofrecido a perdonar a cualquier antiguo Velasangre que esté dispuesto a volverse contra su capitán! Ese tonto me pidió que me fuera y que me quitara de encima a mis viejos compañeros y que trajera sus pañuelos como prueba.$B$BNo tengo ganas de hacer eso, ni te lo pediré. Tráeme tela de seda y tinte rojo y haré réplicas adecuadas. Le diré al barón que te volviste $gun traidor:una traidora;, pero ten cuidado... ¡a los Velasangre no les va a gustar!', 0),
(@ID, 'esMX', '¡Ese perro sarnoso, Revilgaz, se ha ofrecido a perdonar a cualquier antiguo Velasangre que esté dispuesto a volverse contra su capitán! Ese tonto me pidió que me fuera y que me quitara de encima a mis viejos compañeros y que trajera sus pañuelos como prueba.$B$BNo tengo ganas de hacer eso, ni te lo pediré. Tráeme tela de seda y tinte rojo y haré réplicas adecuadas. Le diré al barón que te volviste $gun traidor:una traidora;, pero ten cuidado... ¡a los Velasangre no les va a gustar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Guardemos un minuto de silencio por nuestros compañeros caídos, $n.$B$B<El traidor Velasangre te sonríe y te guiña un ojo>.$B$BSer un traidor es una cosa, asesinar a tus propios compañeros... ¡eso sería absolutamente despreciable, sí!', 0),
(@ID, 'esMX', 'Guardemos un minuto de silencio por nuestros compañeros caídos, $n.$B$B<El traidor Velasangre te sonríe y te guiña un ojo>.$B$BSer un traidor es una cosa, asesinar a tus propios compañeros... ¡eso sería absolutamente despreciable, sí!', 0);
-- 9265 Investigar la Plaga en Entrañas
-- https://es.classic.wowhead.com/quest=9265
SET @ID := 9265;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm. Por lo que me has dicho, las voces dentro de los círculos... deben usarse para algún tipo de comunicación. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, pareces haber emergido completamente $gcuerdo:cuerda;. El Alba Argenta agradece tu servicio.', 0),
(@ID, 'esMX', 'Mmm. Por lo que me has dicho, las voces dentro de los círculos... deben usarse para algún tipo de comunicación. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, pareces haber emergido completamente $gcuerdo:cuerda;. El Alba Argenta agradece tu servicio.', 0);
-- 9266 Enmendar los errores
-- https://es.classic.wowhead.com/quest=9266
SET @ID := 9266;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes habernos hecho algo realmente malo a nosotros o a nuestros amigos, $n. En cualquier caso, estoy aquí para ofrecerte una forma de recuperar nuestro favor.$B$BComo sabes, en Cuna del Invierno hace bastante frío. Con tantos goblins que venimos de otras ciudades, nos vendría bien una mano para mantenernos calientes. Tráeme un poco de paño rúnica y carbón y te daré el perdón. Sin embargo, ten en cuenta que a nuestros enemigos no les agradará que nos ayudes.', 0),
(@ID, 'esMX', 'Debes habernos hecho algo realmente malo a nosotros o a nuestros amigos, $n. En cualquier caso, estoy aquí para ofrecerte una forma de recuperar nuestro favor.$B$BComo sabes, en Cuna del Invierno hace bastante frío. Con tantos goblins que venimos de otras ciudades, nos vendría bien una mano para mantenernos calientes. Tráeme un poco de paño rúnica y carbón y te daré el perdón. Sin embargo, ten en cuenta que a nuestros enemigos no les agradará que nos ayudes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estás en el buen camino para redimirte con nuestra ciudad.', 0),
(@ID, 'esMX', 'Gracias, $n. Estás en el buen camino para redimirte con nuestra ciudad.', 0);
-- 9267 Curar viejas heridas
-- https://es.classic.wowhead.com/quest=9267
SET @ID := 9267;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Será mejor que lo pienses dos veces antes de poner un pie en Trinquete, $n! Se ha corrido la voz de tus sucias acciones.$B$BSin embargo, estás de suerte, acaba de llegar un barco con muchos heridos de un encuentro con los Bucaneros Velasangre. Esta es tu oportunidad de demostrar que no eres $gun completo:una completa; sinvergüenza. Échanos una mano paño de lino para vendas y frascos vacíos para pociones.', 0),
(@ID, 'esMX', '¡Será mejor que lo pienses dos veces antes de poner un pie en Trinquete, $n! Se ha corrido la voz de tus sucias acciones.$B$BSin embargo, estás de suerte, acaba de llegar un barco con muchos heridos de un encuentro con los Bucaneros Velasangre. Esta es tu oportunidad de demostrar que no eres $gun completo:una completa; sinvergüenza. Échanos una mano paño de lino para vendas y frascos vacíos para pociones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que veas tu error, $n. Que sigan llegando los suministros; ¡No nos vamos a olvidar de ti tan fácilmente, $gseñor:señora;!', 0),
(@ID, 'esMX', 'Me alegra que veas tu error, $n. Que sigan llegando los suministros; ¡No nos vamos a olvidar de ti tan fácilmente, $gseñor:señora;!', 0);
-- 9268 Guerra en el mar
-- https://es.classic.wowhead.com/quest=9268
SET @ID := 9268;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Buscas hacerte $gamigo:amiga; de los goblins de Tanaris una vez más, $n? Necesitamos materiales para velas y cañones para luchar contra nuestros viejos enemigos, los Bucaneros Velasangre. Tráeme tejido mágico y flujo concentrado y estaremos en camino de perdonar tus ofensas.', 0),
(@ID, 'esMX', '¿Buscas hacerte $gamigo:amiga; de los goblins de Tanaris una vez más, $n? Necesitamos materiales para velas y cañones para luchar contra nuestros viejos enemigos, los Bucaneros Velasangre. Tráeme tejido mágico y flujo concentrado y estaremos en camino de perdonar tus ofensas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue así, $n. ¡Nosotros los goblins no olvidamos tan fácilmente!', 0),
(@ID, 'esMX', 'Sigue así, $n. ¡Nosotros los goblins no olvidamos tan fácilmente!', 0);
-- 9272 Vístete como tal
-- https://es.wowhead.com/quest=9272
SET @ID := 9272;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aaarr! Si te gusta la compañía de viejos lobos de mar como nosotros, será mejor que te vistas como uno. Toma, ponte algo más apropiado antes de que te pase por la quilla el pellejo.$B$BEsto te quedará mejor a ti que a ese viejo perro de Ben Ojosrojos. Lo perdimos en una maldita tormenta.$B$BLlévalo con orgullo, camarada.', 0),
(@ID, 'esMX', '¡Aaarr! Si te gusta la compañía de viejos lobos de mar como nosotros, será mejor que te vistas como uno. Toma, ponte algo más apropiado antes de que te pase por la quilla el pellejo.$B$BEsto te quedará mejor a ti que a ese viejo perro de Ben Ojosrojos. Lo perdimos en una maldita tormenta.$B$BLlévalo con orgullo, camarada.', 0);
-- 9279 ¡Has sobrevivido!
-- https://es.wowhead.com/quest=9279
SET @ID := 9279;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por mi alma, $n, cuánto me alegro de verte! No sé por qué se estrelló El Exodar. Solo sobrevivimos los que estábamos en esta parte de la nave.$B$B¡Tenemos que darnos prisa para salvar a todos los que podamos!', 0),
(@ID, 'esMX', '¡Por mi alma, $n, cuánto me alegro de verte! No sé por qué se estrelló El Exodar. Solo sobrevivimos los que estábamos en esta parte de la nave.$B$B¡Tenemos que darnos prisa para salvar a todos los que podamos!', 0);
-- 9280 Recargar los cristales de sanación
-- https://es.wowhead.com/quest=9280
SET @ID := 9280;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿traes la sangre de polilla del valle para los cristales de sanación? ¡Debemos apresurarnos, hay muchos supervivientes en el valle!', 0),
(@ID, 'esMX', '$n, ¿traes la sangre de polilla del valle para los cristales de sanación? ¡Debemos apresurarnos, hay muchos supervivientes en el valle!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es lamentable que esas criaturas tuvieran que morir para que nosotros vivamos; los draenei no matamos indiscriminadamente. Pero la sangre que traes recargará nuestros cristales de sanación. La muerte de esas criaturas no ha sido en vano.', 0),
(@ID, 'esMX', 'Es lamentable que esas criaturas tuvieran que morir para que nosotros vivamos; los draenei no matamos indiscriminadamente. Pero la sangre que traes recargará nuestros cristales de sanación. La muerte de esas criaturas no ha sido en vano.', 0);
-- 9281 Despejando el camino
-- https://es.wowhead.com/quest=9281
SET @ID := 9281;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ocupaste del negocio que discutimos, $n?', 0),
(@ID, 'esMX', '¿Te ocupaste del negocio que discutimos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por echarme una mano, $n. Me aterraba la sola idea de adentrarme en el bosque tan cerca de la Ciudad de la Muerte.', 0),
(@ID, 'esMX', 'Gracias por echarme una mano, $n. Me aterraba la sola idea de adentrarme en el bosque tan cerca de la Ciudad de la Muerte.', 0);
-- 9283 ¡Rescata a los supervivientes!
-- https://es.wowhead.com/quest=9283
SET @ID := 9283;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Supervivientes draenei salvados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sobreviviremos a esto con tu ayuda.', 0),
(@ID, 'esMX', 'Sobreviviremos a esto con tu ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabada sea la Luz! Has hecho lo que solo $gun héroe:una heroína; podría haber hecho, $n. Los draenei que has salvado te deben la vida.$B$BPor favor, acepta estos suministros. Parece que los necesitas más que yo.', 0),
(@ID, 'esMX', '¡Alabada sea la Luz! Has hecho lo que solo $gun héroe:una heroína; podría haber hecho, $n. Los draenei que has salvado te deben la vida.$B$BPor favor, acepta estos suministros. Parece que los necesitas más que yo.', 0);
-- Instrucción de paladín
-- 9287, 9676
-- https://es.wowhead.com/quest=9287
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9287, 9676) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9287, 'esES', 'Me alienta tu iniciativa de hablar conmigo. En el pasado, fui responsable del entrenamiento de los jóvenes paladines cuando ingresaban a nuestra orden. Este es un deber y un privilegio que asumo humildemente una vez más. Tu nombre ha sido mencionado como alguien que busca hacer el bien en nombre de la Luz. Sería un honor para mí guiarte en tus primeros pasos como $c.$B$B¿Deberíamos empezar?', 0),
(9676, 'esES', 'Me alienta tu iniciativa de hablar conmigo. En el pasado, fui responsable del entrenamiento de los jóvenes paladines cuando ingresaban a nuestra orden. Este es un deber y un privilegio que asumo humildemente una vez más. Tu nombre ha sido mencionado como alguien que busca hacer el bien en nombre de la Luz. Sería un honor para mí guiarte en tus primeros pasos como $c.$B$B¿Deberíamos empezar?', 0),
(9287, 'esMX', 'Me alienta tu iniciativa de hablar conmigo. En el pasado, fui responsable del entrenamiento de los jóvenes paladines cuando ingresaban a nuestra orden. Este es un deber y un privilegio que asumo humildemente una vez más. Tu nombre ha sido mencionado como alguien que busca hacer el bien en nombre de la Luz. Sería un honor para mí guiarte en tus primeros pasos como $c.$B$B¿Deberíamos empezar?', 0),
(9676, 'esMX', 'Me alienta tu iniciativa de hablar conmigo. En el pasado, fui responsable del entrenamiento de los jóvenes paladines cuando ingresaban a nuestra orden. Este es un deber y un privilegio que asumo humildemente una vez más. Tu nombre ha sido mencionado como alguien que busca hacer el bien en nombre de la Luz. Sería un honor para mí guiarte en tus primeros pasos como $c.$B$B¿Deberíamos empezar?', 0);
-- 9288 Instrucción de cazador
-- https://es.wowhead.com/quest=9288
SET @ID := 9288;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que hayas venido a mí. Desde hace bastante tiempo soy responsable de la formación de $gnuestros:nuestras; jóvenes $c, una responsabilidad que pretendo continuar en este nuevo mundo. Te he echado el ojo por un tiempo y sería un honor para mí ayudarte a entrenar en los caminos $gdel:de la; $c.$B¿Deberíamos empezar?', 0),
(@ID, 'esMX', 'Me alegro de que hayas venido a mí. Desde hace bastante tiempo soy responsable de la formación de $gnuestros:nuestras; jóvenes $c, una responsabilidad que pretendo continuar en este nuevo mundo. Te he echado el ojo por un tiempo y sería un honor para mí ayudarte a entrenar en los caminos $gdel:de la; $c.$B¿Deberíamos empezar?', 0);
-- 9289 Instrucción de guerrero
-- https://es.wowhead.com/quest=9289
SET @ID := 9289;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que busques mi guía. Durante siglos he enseñado a los jóvenes guerreros $r, así que puede que sepa un par de cosas sobre cómo debes empezar. Veo en ti los ingredientes de $gun:una; gran $n, pero solo si escuchas atentamente lo que tengo que enseñar.$B$B¿Estás $glisto:lista; para aprender, joven $n?', 0),
(@ID, 'esMX', 'Es bueno que busques mi guía. Durante siglos he enseñado a los jóvenes guerreros $r, así que puede que sepa un par de cosas sobre cómo debes empezar. Veo en ti los ingredientes de $gun:una; gran $n, pero solo si escuchas atentamente lo que tengo que enseñar.$B$B¿Estás $glisto:lista; para aprender, joven $n?', 0);
-- 9290 Instrucción de mago
-- https://es.wowhead.com/quest=9290
SET @ID := 9290;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas venido a buscar mis conocimientos. Tenemos mucho que hacer para perfeccionar tus habilidades mágicas. Durante más de cien años he enseñado la magia arcana, la de escarcha y la de fuego, y puedo sentirlas con la misma fuerza en este mundo. ¿Le gustaría que le diera algo de lo que sé?', 0),
(@ID, 'esMX', 'Me alegra que hayas venido a buscar mis conocimientos. Tenemos mucho que hacer para perfeccionar tus habilidades mágicas. Durante más de cien años he enseñado la magia arcana, la de escarcha y la de fuego, y puedo sentirlas con la misma fuerza en este mundo. ¿Le gustaría que le diera algo de lo que sé?', 0);
-- 9291 Instrucción de sacerdote
-- https://es.wowhead.com/quest=9291
SET @ID := 9291;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una gran esperanza para nuestro futuro que vengas en busca de mi sabiduría. Aunque tengo las manos ocupadas aquí con nuestros heridos, no estoy tan ocupado como para no poder dedicar un momento a ayudarte en tus primeros pasos como $n. Caminar en la Luz es el más alto de los llamamientos, y estoy seguro de que estás más que $glisto:lista; para empezar. Habla conmigo nuevamente cuando sientas que estás $glisto:lista; para comenzar tu entrenamiento.', 0),
(@ID, 'esMX', 'Es una gran esperanza para nuestro futuro que vengas en busca de mi sabiduría. Aunque tengo las manos ocupadas aquí con nuestros heridos, no estoy tan ocupado como para no poder dedicar un momento a ayudarte en tus primeros pasos como $n. Caminar en la Luz es el más alto de los llamamientos, y estoy seguro de que estás más que $glisto:lista; para empezar. Habla conmigo nuevamente cuando sientas que estás $glisto:lista; para comenzar tu entrenamiento.', 0);
