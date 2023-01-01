-- 4962 Fragmento de can manáfago
-- https://es.classic.wowhead.com/quest=4962
SET @ID := 4962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué hay, $n? ¿Has elegido? ¿Infernal o can manáfago?$B$BCada elección es personal y debería reflejar tus puntos fuertes y tus flaquezas. No sería la primera vez que $gun:una; $c intenta aumentar su poder en lugar de mejorar las áreas que le fallan. A veces superar a un enemigo es una táctica tan eficaz como convertirse en un lanzador de hechizos más equilibrado.', 0),
(@ID, 'esMX', '¿Qué hay, $n? ¿Has elegido? ¿Infernal o can manáfago?$B$BCada elección es personal y debería reflejar tus puntos fuertes y tus flaquezas. No sería la primera vez que $gun:una; $c intenta aumentar su poder en lugar de mejorar las áreas que le fallan. A veces superar a un enemigo es una táctica tan eficaz como convertirse en un lanzador de hechizos más equilibrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, el espíritu de un can manáfago. Muy bien, $n.$B$BCuando tenga el espíritu y el orbe limpio, los combinaré para ti pero no hasta entonces.', 0),
(@ID, 'esMX', 'Ah, el espíritu de un can manáfago. Muy bien, $n.$B$BCuando tenga el espíritu y el orbe limpio, los combinaré para ti pero no hasta entonces.', 0);
-- 4963 Fragmento de infernal
-- https://es.classic.wowhead.com/quest=4963
SET @ID := 4963;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué hay, $n? ¿Has elegido? ¿Infernal o can manáfago?$B$BCada elección es personal y debería reflejar tus puntos fuertes y tus flaquezas. No sería la primera vez que $gun:una; $c intenta aumentar su poder en lugar de mejorar las áreas que le fallan. A veces superar a un enemigo es una táctica tan eficaz como convertirse en un lanzador de hechizos más equilibrado.', 0),
(@ID, 'esMX', '¿Qué hay, $n? ¿Has elegido? ¿Infernal o can manáfago?$B$BCada elección es personal y debería reflejar tus puntos fuertes y tus flaquezas. No sería la primera vez que $gun:una; $c intenta aumentar su poder en lugar de mejorar las áreas que le fallan. A veces superar a un enemigo es una táctica tan eficaz como convertirse en un lanzador de hechizos más equilibrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, el espíritu de un infernal. Muy bien, $n.$B$BCuando tenga el espíritu y el orbe limpio, los combinaré para ti pero no hasta entonces.', 0),
(@ID, 'esMX', 'Ah, el espíritu de un infernal. Muy bien, $n.$B$BCuando tenga el espíritu y el orbe limpio, los combinaré para ti pero no hasta entonces.', 0);
-- 4964 El orbe completo de Dar'Orahil
-- https://es.classic.wowhead.com/quest=4964
SET @ID := 4964;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está hecho, $n. Simplemente dime cuál prefieres: un bastón que requiera que uses ambas manos, o un orbe para que puedas usar una daga o espada como arma.$B$BHacer frente a un manáfago fue una gran hazaña de tu parte. Estoy seguro de que tu artículo te servirá bien en el futuro. Continúa trabajando duro en las artes, $n. Estaré esperando detalles de tus hazañas.', 0),
(@ID, 'esMX', 'Está hecho, $n. Simplemente dime cuál prefieres: un bastón que requiera que uses ambas manos, o un orbe para que puedas usar una daga o espada como arma.$B$BHacer frente a un manáfago fue una gran hazaña de tu parte. Estoy seguro de que tu artículo te servirá bien en el futuro. Continúa trabajando duro en las artes, $n. Estaré esperando detalles de tus hazañas.', 0);
-- 4964 El orbe completo de Dar'Orahil
-- https://es.classic.wowhead.com/quest=4964
SET @ID := 4964;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está hecho, $n. Simplemente dime cuál prefieres: un bastón que requiera que uses ambas manos, o un orbe para que puedas usar una daga o espada como arma.$B$BHacer frente a un manáfago fue una gran hazaña de tu parte. Estoy seguro de que tu artículo te servirá bien en el futuro. Continúa trabajando duro en las artes, $n. Estaré esperando detalles de tus hazañas.', 0),
(@ID, 'esMX', 'Está hecho, $n. Simplemente dime cuál prefieres: un bastón que requiera que uses ambas manos, o un orbe para que puedas usar una daga o espada como arma.$B$BHacer frente a un manáfago fue una gran hazaña de tu parte. Estoy seguro de que tu artículo te servirá bien en el futuro. Continúa trabajando duro en las artes, $n. Estaré esperando detalles de tus hazañas.', 0);
-- El conocimiento del orbe de Orahil
-- 4965, 4967, 4968, 4969
-- https://es.classic.wowhead.com/quest=4965
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4965, 4967, 4968, 4969) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4965, 'esES', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4967, 'esES', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4968, 'esES', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4969, 'esES', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4965, 'esMX', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4967, 'esMX', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4968, 'esMX', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0),
(4969, 'esMX', 'Ah, sí que buscas algo con más... sustancia. En eso te puedo ayudar si estás $gpreparado:preparada; de verdad.$B$BEs un cambio agradable ver que $guno:una; de nuestra clase busca más poder en formas distintas al conocimiento.$B$BAsí que ¿sientes que estás $gpreparado:preparada;, $n?', 0);
-- 4966 Defensa de Kanati Nube Gris
-- https://es.classic.wowhead.com/quest=4966
SET @ID := 4966;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Nunca habría podido derrotarlos sin ti.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Nunca habría podido derrotarlos sin ti.', 0);
-- 4970 Provisiones de sable de hielo
-- https://es.classic.wowhead.com/quest=4970
SET @ID := 4970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La disciplina y la determinación son tus metas. Puedo pedirte que hagas una tarea sencilla muchas veces; debes rendir lo mejor que puedas cada vez.', 0),
(@ID, 'esMX', 'La disciplina y la determinación son tus metas. Puedo pedirte que hagas una tarea sencilla muchas veces; debes rendir lo mejor que puedas cada vez.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por ayudarme, $n. Mi opinión sobre ti mejora a medida que pasa el tiempo.', 0),
(@ID, 'esMX', 'Gracias por ayudarme, $n. Mi opinión sobre ti mejora a medida que pasa el tiempo.', 0);
-- 4971 Una cuestión de tiempo
-- https://es.classic.wowhead.com/quest=4971
SET @ID := 4971;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los parásitos temporales son una enfermedad común allí donde el flujo del tiempo ha sido alterado. Siento que hay muchos... y es inquietante.$B$BErradica a todos los que puedas encontrar y me ayudarás a frenar el deterioro de la situación temporal de este lugar. Podré sentir cuándo lo has logrado.', 0),
(@ID, 'esMX', 'Los parásitos temporales son una enfermedad común allí donde el flujo del tiempo ha sido alterado. Siento que hay muchos... y es inquietante.$B$BErradica a todos los que puedas encontrar y me ayudarás a frenar el deterioro de la situación temporal de este lugar. Podré sentir cuándo lo has logrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora parece más fácil reparar el tiempo, gracias a ti, $n. Aunque quizás nunca llegues a comprender todas las consecuencias de la ruptura de la línea de tiempo, aprecio que comprendieras la urgencia de contrarrestar lo que cada vez se acerca más a una nueva maldad infligida por la Plaga.$B$BNo veo ningún mal en recompensarte por tu ayuda, mortal. Tus mayores hazañas aún están por llegar y esta chuchería no alterará tu futuro destino. Sin embargo, tu leal ayuda, será de lo que quizás nos valgamos yo y el Vuelo...', 0),
(@ID, 'esMX', 'Ahora parece más fácil reparar el tiempo, gracias a ti, $n. Aunque quizás nunca llegues a comprender todas las consecuencias de la ruptura de la línea de tiempo, aprecio que comprendieras la urgencia de contrarrestar lo que cada vez se acerca más a una nueva maldad infligida por la Plaga.$B$BNo veo ningún mal en recompensarte por tu ayuda, mortal. Tus mayores hazañas aún están por llegar y esta chuchería no alterará tu futuro destino. Sin embargo, tu leal ayuda, será de lo que quizás nos valgamos yo y el Vuelo...', 0);
-- 4972 Contar el tiempo
-- https://es.classic.wowhead.com/quest=4972
SET @ID := 4972;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los abalorios temporales que busco son instrumentos muy sencillos. Son sobre todo relojes que sus manillas se quedaron paradas cuando la Peste devastó Andorhal.$B$BEl tiempo es eterno y los relojes que me traes no sobrevivirán al paso del tiempo, serán desechados y devueltos a sus hogares... siempre que siga la alteración en este lugar.', 0),
(@ID, 'esMX', 'Los abalorios temporales que busco son instrumentos muy sencillos. Son sobre todo relojes que sus manillas se quedaron paradas cuando la Peste devastó Andorhal.$B$BEl tiempo es eterno y los relojes que me traes no sobrevivirán al paso del tiempo, serán desechados y devueltos a sus hogares... siempre que siga la alteración en este lugar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es exactamente lo que necesito, $n. Gracias.$B$BPermíteme recompensarte adecuadamente. Quizás no comprendas para qué podrías necesitar un instrumento así. Puede que ni siquiera sepas qué es. Ay... no puedo decirte cuándo te será de utilidad, pero tienes que saber que llegará un momento en el que lo encontrarás extremadamente útil. Decidas o no conservarlo hasta que llegue ese momento... esto, $gamigo mío:amiga mía;, es tuyo.', 0),
(@ID, 'esMX', 'Esto es exactamente lo que necesito, $n. Gracias.$B$BPermíteme recompensarte adecuadamente. Quizás no comprendas para qué podrías necesitar un instrumento así. Puede que ni siquiera sepas qué es. Ay... no puedo decirte cuándo te será de utilidad, pero tienes que saber que llegará un momento en el que lo encontrarás extremadamente útil. Decidas o no conservarlo hasta que llegue ese momento... esto, $gamigo mío:amiga mía;, es tuyo.', 0);
-- 4973 Contar el tiempo
-- https://es.classic.wowhead.com/quest=4973
SET @ID := 4973;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los relojes de Andorhal, como el gran reloj de las ruinas del ayuntamiento, están parados a las tres en punto. En esa hora los efectos de la peste comenzaron a propagarse por la ciudad, aniquilando toda forma de vida.$B$BTodo el dolor por lo que sucedió ese día ha modelado el flujo del tiempo tal y como ustedes, mortales, lo perciben. ¡El Vuelo Bronce debe seguir protegiendo la línea de tiempo!', 0),
(@ID, 'esMX', 'Los relojes de Andorhal, como el gran reloj de las ruinas del ayuntamiento, están parados a las tres en punto. En esa hora los efectos de la peste comenzaron a propagarse por la ciudad, aniquilando toda forma de vida.$B$BTodo el dolor por lo que sucedió ese día ha modelado el flujo del tiempo tal y como ustedes, mortales, lo perciben. ¡El Vuelo Bronce debe seguir protegiendo la línea de tiempo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te agradezco de nuevo tu ayuda. Por favor, acepta este regalo. Aunque tal vez no sepas cómo ni cuándo utilizar este objeto, puede que en el futuro la senda del tiempo te revele sus verdaderos propósitos. Podría decirse que he visto que va a ser así, $n.', 0),
(@ID, 'esMX', 'Te agradezco de nuevo tu ayuda. Por favor, acepta este regalo. Aunque tal vez no sepas cómo ni cuándo utilizar este objeto, puede que en el futuro la senda del tiempo te revele sus verdaderos propósitos. Podría decirse que he visto que va a ser así, $n.', 0);
-- 4974 ¡Por la Horda!
-- https://es.classic.wowhead.com/quest=4974
SET @ID := 4974;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thrall gruñe.>', 0),
(@ID, 'esMX', '<Thrall gruñe.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has asestado un golpe mortal a los Roca Negra, $n. Ahora que han perdido a su Jefe de Guerra, están perdidos.$B$B¡La gente de Kalimdor será recompensada por tu hazaña!', 0),
(@ID, 'esMX', 'Has asestado un golpe mortal a los Roca Negra, $n. Ahora que han perdido a su Jefe de Guerra, están perdidos.$B$B¡La gente de Kalimdor será recompensada por tu hazaña!', 0);
-- 4975 El orbe completo de Noh'Orahil
-- https://es.classic.wowhead.com/quest=4975
SET @ID := 4975;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya está, $n. Solo dime qué prefieres: un bastón, que requerirá el uso de ambas manos, o un orbe, de forma que puedas usar una daga o una espada como arma.$B$BDespachar al infernal ha sido una gran proeza por tu parte, proeza digna de esta recompensa. Te deseo éxitos similares en las artes, $n.', 0),
(@ID, 'esMX', 'Ya está, $n. Solo dime qué prefieres: un bastón, que requerirá el uso de ambas manos, o un orbe, de forma que puedas usar una daga o una espada como arma.$B$BDespachar al infernal ha sido una gran proeza por tu parte, proeza digna de esta recompensa. Te deseo éxitos similares en las artes, $n.', 0);
-- 4976 Devolver el orbe purificado
-- https://es.classic.wowhead.com/quest=4976
SET @ID := 4976;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de Tabetha y del orbe, $n?$B$BTabetha ha sido de más ayuda cuando se trata de asuntos arcanos. No me cabe la menor duda de que te ayudaría si logras encontrarla.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de Tabetha y del orbe, $n?$B$BTabetha ha sido de más ayuda cuando se trata de asuntos arcanos. No me cabe la menor duda de que te ayudaría si logras encontrarla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Esto me servirá.$B$BSolo te falta decidir qué demonio quieres que deje atrapado en el orbe limpio. Hazlo y tendrás un magnífico nuevo objeto que empuñar.', 0),
(@ID, 'esMX', 'Muy bien, $n. Esto me servirá.$B$BSolo te falta decidir qué demonio quieres que deje atrapado en el orbe limpio. Hazlo y tendrás un magnífico nuevo objeto que empuñar.', 0);
-- 4981 La espía Bijou
-- https://es.classic.wowhead.com/quest=4981
SET @ID := 4981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te mentiré, $r. ¡Necesitaba el dinero! Kibler paga muy pero que muy bien, mucho mejor de lo que lo haría nunca la F.E.K.$B$B¡Pero no pongas en duda mi lealtad! ¿Por qué crees que estoy aquí abajo? ¿Para conseguirle a algún goblin chalado unas patas de algún animal exótico o algo igualmente estúpido? No, solo alguien realmente tonto vendría a la Cumbre de Roca Negra para conseguir mascotas. Sí, y no creo que haya mucha gente así en este mundo.$B$B<Bijou suelta una carcajada.>$B$BLo último que necesitamos es esa clase de gente reproduciéndose.', 0),
(@ID, 'esMX', 'No te mentiré, $r. ¡Necesitaba el dinero! Kibler paga muy pero que muy bien, mucho mejor de lo que lo haría nunca la F.E.K.$B$B¡Pero no pongas en duda mi lealtad! ¿Por qué crees que estoy aquí abajo? ¿Para conseguirle a algún goblin chalado unas patas de algún animal exótico o algo igualmente estúpido? No, solo alguien realmente tonto vendría a la Cumbre de Roca Negra para conseguir mascotas. Sí, y no creo que haya mucha gente así en este mundo.$B$B<Bijou suelta una carcajada.>$B$BLo último que necesitamos es esa clase de gente reproduciéndose.', 0);
-- 4982 Las pertenencias de Bijou
-- https://es.classic.wowhead.com/quest=4982
SET @ID := 4982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte?', 0),
(@ID, 'esMX', '¿Ha habido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Cuando Lexlort tenga estos planos, se olvidará de todas esas cosas desagradables que quería hacerme.$B$B$n, ¡eres $gmi héroe:mi heroína;!', 0),
(@ID, 'esMX', '¡Lo has logrado! Cuando Lexlort tenga estos planos, se olvidará de todas esas cosas desagradables que quería hacerme.$B$B$n, ¡eres $gmi héroe:mi heroína;!', 0);
-- 4983 El informe de reconocimiento de Bijou
-- https://es.classic.wowhead.com/quest=4983
SET @ID := 4983;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿¿Dónde está el goblin???', 0),
(@ID, 'esMX', '¿¿¿Dónde está el goblin???', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo que reconocerlo, ¡ha logrado escabullirse de otra situación peliaguda! Estos informes serán valiosos cuando tratemos con los orcos Roca Negra.$B$BPor supuesto, se te recompensará por tu duro trabajo.', 0),
(@ID, 'esMX', 'Tengo que reconocerlo, ¡ha logrado escabullirse de otra situación peliaguda! Estos informes serán valiosos cuando tratemos con los orcos Roca Negra.$B$BPor supuesto, se te recompensará por tu duro trabajo.', 0);
-- 4984 La naturaleza también sufre
-- https://es.classic.wowhead.com/quest=4984
SET @ID := 4984;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los lobos infectados con la plaga deben ser sacrificados, $n. La enfermedad que portan no se puede curar. Lo intenté... lo intenté hasta que yo mismo sucumbí a la plaga.', 0),
(@ID, 'esMX', 'Los lobos infectados con la plaga deben ser sacrificados, $n. La enfermedad que portan no se puede curar. Lo intenté... lo intenté hasta que yo mismo sucumbí a la plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sii... siento que las almas de los lobos que mataste han encontrado por fin su descanso. Ellos, y yo, te agradecemos tu piadosa liberación.$B$BLos lobos no son los únicos que sufren en este detestable lugar, $n. Por favor, te necesito una vez más.', 0),
(@ID, 'esMX', 'Sii... siento que las almas de los lobos que mataste han encontrado por fin su descanso. Ellos, y yo, te agradecemos tu piadosa liberación.$B$BLos lobos no son los únicos que sufren en este detestable lugar, $n. Por favor, te necesito una vez más.', 0);
-- 4985 La naturaleza también sufre
-- https://es.classic.wowhead.com/quest=4985
SET @ID := 4985;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído tus pasos, $n. Mi visión se ha desvanecido, pero todavía puedo sentir las cosas que me rodean. ¿Has terminado con el sufrimiento de los pardos asolados por la enfermedad?', 0),
(@ID, 'esMX', 'He oído tus pasos, $n. Mi visión se ha desvanecido, pero todavía puedo sentir las cosas que me rodean. ¿Has terminado con el sufrimiento de los pardos asolados por la enfermedad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Sé que los pardos ahora están en paz, y su tormento ha terminado. Yo... tengo algo más para ti. Lo escribí en... en esta rama, porque presentía que mi tiempo en este reino estaba por terminar.$B$BAsí es... mi vida se acaba. Gracias de nuevo, $gamigo:amiga;... Las criaturas de esta tierra maldita pueden descansar... y ahora las acompañaré".$B$BCon esas últimas palabras, el druida emite una profunda exhalación hasta perder el aliento. Su cuerpo yace inmóvil en el piso de la cabaña.', 0),
(@ID, 'esMX', '"Sé que los pardos ahora están en paz, y su tormento ha terminado. Yo... tengo algo más para ti. Lo escribí en... en esta rama, porque presentía que mi tiempo en este reino estaba por terminar.$B$BAsí es... mi vida se acaba. Gracias de nuevo, $gamigo:amiga;... Las criaturas de esta tierra maldita pueden descansar... y ahora las acompañaré".$B$BCon esas últimas palabras, el druida emite una profunda exhalación hasta perder el aliento. Su cuerpo yace inmóvil en el piso de la cabaña.', 0);
-- 4986 Rama de roble con inscripciones
-- https://es.classic.wowhead.com/quest=4986
SET @ID := 4986;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En nombre del Círculo Cenarion te doy la bienvenida a este enclave, $c. ¿Qué te trae a nosotros?', 0),
(@ID, 'esMX', 'En nombre del Círculo Cenarion te doy la bienvenida a este enclave, $c. ¿Qué te trae a nosotros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto... esto es muy extraño. Este druida, un druida tauren nada menos, te ha confiado mucha y valiosa información sobre la extensión de la Peste de la Plaga. Me sorprende que un tauren diera a $gun:una; $r tal información y mucho más si todo lo que dices es cierto. Haremos un buen uso de esto, te lo prometo. Quizás el tauren no cayera tan lejos de Cenarius como Fandral podría pensar...$B$BErrr... de cualquier forma, por favor, acepta esto como muestra de gratitud del Círculo Cenarion.', 0),
(@ID, 'esMX', 'Esto... esto es muy extraño. Este druida, un druida tauren nada menos, te ha confiado mucha y valiosa información sobre la extensión de la Peste de la Plaga. Me sorprende que un tauren diera a $gun:una; $r tal información y mucho más si todo lo que dices es cierto. Haremos un buen uso de esto, te lo prometo. Quizás el tauren no cayera tan lejos de Cenarius como Fandral podría pensar...$B$BErrr... de cualquier forma, por favor, acepta esto como muestra de gratitud del Círculo Cenarion.', 0);
-- 4987 Rama de roble con inscripciones
-- https://es.classic.wowhead.com/quest=4987
SET @ID := 4987;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En nombre del Círculo Cenarion te doy la bienvenida a este enclave, $c. ¿Qué te trae a nosotros?', 0),
(@ID, 'esMX', 'En nombre del Círculo Cenarion te doy la bienvenida a este enclave, $c. ¿Qué te trae a nosotros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que esto es para Mulgris? Oímos que intentaba ayudar a las criaturas sufrientes de las Tierras de la Peste, pero no esperábamos esto... qué tragedia. Mulgris es... era un buen amigo. Lloraré su partida amargamente.$B$BPero sus esfuerzos no han sido en vano, gracias a tu diligencia. En esta rama hay mucha información sobre la peste que propaga la Plaga por el país. La estudiaremos con detalle. En cuanto a ti, por favor, acepta esto. Es lo menos que puedo hacer por tus nobles esfuerzos.', 0),
(@ID, 'esMX', '¿Dices que esto es para Mulgris? Oímos que intentaba ayudar a las criaturas sufrientes de las Tierras de la Peste, pero no esperábamos esto... qué tragedia. Mulgris es... era un buen amigo. Lloraré su partida amargamente.$B$BPero sus esfuerzos no han sido en vano, gracias a tu diligencia. En esta rama hay mucha información sobre la peste que propaga la Plaga por el país. La estudiaremos con detalle. En cuanto a ti, por favor, acepta esto. Es lo menos que puedo hacer por tus nobles esfuerzos.', 0);
-- 5001 Las pertenencias de Bijou
-- https://es.classic.wowhead.com/quest=5001
SET @ID := 5001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte?', 0),
(@ID, 'esMX', '¿Ha habido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, que me aspen! ¿¿Dónde estaban??', 0),
(@ID, 'esMX', '¡Vaya, que me aspen! ¿¿Dónde estaban??', 0);
-- 5002 Un mensaje para Maxwell
-- https://es.classic.wowhead.com/quest=5002
SET @ID := 5002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡cuánto tiempo!', 0),
(@ID, 'esMX', 'Ah, $n, ¡cuánto tiempo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto encaja con casi todo lo que ya sabíamos. Pero bueno, es interesante y una información más bien triste.$B$BLas marcas de este mapa serán valiosas para atajar la amenaza de los Roca Negra.', 0),
(@ID, 'esMX', 'Esto encaja con casi todo lo que ya sabíamos. Pero bueno, es interesante y una información más bien triste.$B$BLas marcas de este mapa serán valiosas para atajar la amenaza de los Roca Negra.', 0);
-- 5021 Más vale tarde que nunca
-- https://es.classic.wowhead.com/quest=5021
SET @ID := 5021;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el establo adviertes un paquete que de otra forma hubieras pasado por alto, pero que ahora destaca entre las ruinas y los escombros. Quizás es el paquete que pedía a gritos el fantasma de Janice Piedra Mácula...', 0),
(@ID, 'esMX', 'En el establo adviertes un paquete que de otra forma hubieras pasado por alto, pero que ahora destaca entre las ruinas y los escombros. Quizás es el paquete que pedía a gritos el fantasma de Janice Piedra Mácula...', 0);
-- 5022 Más vale tarde que nunca
-- https://es.classic.wowhead.com/quest=5022
SET @ID := 5022;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a la oficina del censo de Ventormenta. Si necesita información sobre nuestra población, puedo $gayudarlo:ayudarla;.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a la oficina del censo de Ventormenta. Si necesita información sobre nuestra población, puedo $gayudarlo:ayudarla;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un paquete para una Emma Piedra Mácula, dices? La última dirección conocida fue Ventormenta, ¿hace cuatro años? Bueno, déjame ver aquí...$B$BSegún lo que sabemos, hubo una Emma Piedra Mácula en la ciudad hace unos cuatro años. Bueno, debería decir posiblemente; este censo al que me refiero es de hace cinco años, y no tengo un informe de que ella haya abandonado la ciudad. Sin embargo, esto no significa que ella todavía esté aquí.$B$BEspera un segundo... este paquete no puede ser para la vieja Emma, ¿verdad?', 0),
(@ID, 'esMX', '¿Un paquete para una Emma Piedra Mácula, dices? La última dirección conocida fue Ventormenta, ¿hace cuatro años? Bueno, déjame ver aquí...$B$BSegún lo que sabemos, hubo una Emma Piedra Mácula en la ciudad hace unos cuatro años. Bueno, debería decir posiblemente; este censo al que me refiero es de hace cinco años, y no tengo un informe de que ella haya abandonado la ciudad. Sin embargo, esto no significa que ella todavía esté aquí.$B$BEspera un segundo... este paquete no puede ser para la vieja Emma, ¿verdad?', 0);
-- 5023 Más vale tarde que nunca
-- https://es.classic.wowhead.com/quest=5023
SET @ID := 5023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido buscando la ayuda del Censo de Entrañas o solo para preguntarme si ha muerto alguien que conocías? Me hacen esta pregunta muchas veces.', 0),
(@ID, 'esMX', '¿Has venido buscando la ayuda del Censo de Entrañas o solo para preguntarme si ha muerto alguien que conocías? Me hacen esta pregunta muchas veces.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un paquete para un tal Jeremiah Piedra Mácula cuya última dirección conocida es Lordaeron... debería poder ayudarte.$B$BJeremiah Piedra Mácula estaba en la ciudad antes de la peste. Bueno, más bien debería decir el antiguo Jeremiah Piedra Mácula. Algunos de los Renegados han cambiados sus apellidos para librarse de su antigua vida. Este caso no es ninguna excepción, el antiguo Jeremiah Piedra Mácula es ahora conocido como Jeremiah Payson.$B$BEspera un momento... ¿no es el vendedor de cucarachas?', 0),
(@ID, 'esMX', 'Un paquete para un tal Jeremiah Piedra Mácula cuya última dirección conocida es Lordaeron... debería poder ayudarte.$B$BJeremiah Piedra Mácula estaba en la ciudad antes de la peste. Bueno, más bien debería decir el antiguo Jeremiah Piedra Mácula. Algunos de los Renegados han cambiados sus apellidos para librarse de su antigua vida. Este caso no es ninguna excepción, el antiguo Jeremiah Piedra Mácula es ahora conocido como Jeremiah Payson.$B$BEspera un momento... ¿no es el vendedor de cucarachas?', 0);
-- 5041 Suministros para El Cruce
-- https://es.classic.wowhead.com/quest=5041
SET @ID := 5041;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de los suministros, $n? Confío en que los jabaespines caerán fácilmente bajo tu fuerza.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de los suministros, $n? Confío en que los jabaespines caerán fácilmente bajo tu fuerza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ea! ¡Gracias, $n! Esto será de gran ayuda. Eres un orgullo para El Cruce y la Horda. Si puedo hacer cualquier cosa por ti, solo tienes que pedirlo.', 0),
(@ID, 'esMX', '¡Ea! ¡Gracias, $n! Esto será de gran ayuda. Eres un orgullo para El Cruce y la Horda. Si puedo hacer cualquier cosa por ti, solo tienes que pedirlo.', 0);
-- 5042 La fuerza de Agamaggan
-- https://es.classic.wowhead.com/quest=5042
SET @ID := 5042;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré 4 esquirlas de sangre si quieres tener la fuerza de Agamaggan, $r.$B$BSi se te concediera esta bendición, tus enemigos se encogerán ante tu fuerza.$B$B¡Los más gloriosos guerreros Crines de Acero están imbuidos de tal poder!', 0),
(@ID, 'esMX', 'Necesitaré 4 esquirlas de sangre si quieres tener la fuerza de Agamaggan, $r.$B$BSi se te concediera esta bendición, tus enemigos se encogerán ante tu fuerza.$B$B¡Los más gloriosos guerreros Crines de Acero están imbuidos de tal poder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ojalá Quebrantadientes estuviera libre para ver cómo diezmas a los que lo traicionaron! <Gruñe>$B$BTe agradezco que destruyeras a más Erizapúas al reunir estos fragmentos. Te lo ruego, sigue haciéndolo, y yo volveré a ayudarte. <Gruñe>', 0),
(@ID, 'esMX', '¡Ojalá Quebrantadientes estuviera libre para ver cómo diezmas a los que lo traicionaron! <Gruñe>$B$BTe agradezco que destruyeras a más Erizapúas al reunir estos fragmentos. Te lo ruego, sigue haciéndolo, y yo volveré a ayudarte. <Gruñe>', 0);
-- 5043 La agilidad de Agamaggan
-- https://es.classic.wowhead.com/quest=5043
SET @ID := 5043;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se dice que la precisión de los mejores exploradores de mi tribu no tiene parangón y ningún granuja <gruñe> estaría a la altura de su rapidez en el combate.$B$BTráeme 4 esquirlas de sangre y haré que seas aún más ágil que cualquier jabaespín.', 0),
(@ID, 'esMX', 'Se dice que la precisión de los mejores exploradores de mi tribu no tiene parangón y ningún granuja <gruñe> estaría a la altura de su rapidez en el combate.$B$BTráeme 4 esquirlas de sangre y haré que seas aún más ágil que cualquier jabaespín.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que no falle tu disparo y la marca de tu arma sea verdadera, $r.$B$BEl espíritu de Agamaggan está contigo. Vuelve aquí si quieres. Quebrantadientes volverá a bendecirte si el gran dios jabalí te considera $gdigno:digna;.', 0),
(@ID, 'esMX', 'Que no falle tu disparo y la marca de tu arma sea verdadera, $r.$B$BEl espíritu de Agamaggan está contigo. Vuelve aquí si quieres. Quebrantadientes volverá a bendecirte si el gran dios jabalí te considera $gdigno:digna;.', 0);
-- 5044 La sabiduría de Agamaggan
-- https://es.classic.wowhead.com/quest=5044
SET @ID := 5044;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El chamán y los geománticos de las tribus jabaespín <gruñe> recurren a la fuerza de Agamaggan para que les ayude en la batalla y en sus rituales, $r.$B$BSi quieres el poder adicional de la bendición de Agamaggan con tus hechizos, tráeme 4 esquirlas de sangre y Quebrantadientes te ayudará.', 0),
(@ID, 'esMX', 'El chamán y los geománticos de las tribus jabaespín <gruñe> recurren a la fuerza de Agamaggan para que les ayude en la batalla y en sus rituales, $r.$B$BSi quieres el poder adicional de la bendición de Agamaggan con tus hechizos, tráeme 4 esquirlas de sangre y Quebrantadientes te ayudará.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus enemigos deberían temerte aún más, $r. $B$BCuéntale a Quebrantadientes los relatos de tu astucia en la batalla la próxima vez que nos veamos, ya sea en esta vida o en la otra.', 0),
(@ID, 'esMX', 'Tus enemigos deberían temerte aún más, $r. $B$BCuéntale a Quebrantadientes los relatos de tu astucia en la batalla la próxima vez que nos veamos, ya sea en esta vida o en la otra.', 0);
-- 5045 Fortaleza de espíritu
-- https://es.classic.wowhead.com/quest=5045
SET @ID := 5045;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todos los tipos de $c necesitan fortaleza de espíritu. Te empuja a mayores proezas cuando se ha perdido toda esperanza. Es algo a lo que están acostumbrados los Crines de Acero. Somos una tribu espiritual, estamos más orgullosos de nuestra conexión con Agamaggan que de nuestras proezas en la batalla.$B$BTráeme 4 esquirlas de sangre y bendeciré tu espíritu para el combate.', 0),
(@ID, 'esMX', 'Todos los tipos de $c necesitan fortaleza de espíritu. Te empuja a mayores proezas cuando se ha perdido toda esperanza. Es algo a lo que están acostumbrados los Crines de Acero. Somos una tribu espiritual, estamos más orgullosos de nuestra conexión con Agamaggan que de nuestras proezas en la batalla.$B$BTráeme 4 esquirlas de sangre y bendeciré tu espíritu para el combate.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros más gloriosos guerreros y <gruñe> chamanes envidiarían tu determinación, $r.$B$B¡Derrota a más Erizapúas sabiendo que no pueden detenerte!', 0),
(@ID, 'esMX', 'Nuestros más gloriosos guerreros y <gruñe> chamanes envidiarían tu determinación, $r.$B$B¡Derrota a más Erizapúas sabiendo que no pueden detenerte!', 0);
-- 5046 Ocultafilo
-- https://es.classic.wowhead.com/quest=5046
SET @ID := 5046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todos los que <gruñe> entran en combate necesitan protección. Sus huesos han de ser resistentes. Su piel, curtida <Gruñe> Mi tribu sabe esto muy bien y para reforzar la protección natural de nuestras púas y piel, <gruñe> con frecuencia recurrimos a Agamaggan para que nos proteja de los daños antes de entrar en combate.$B$BTráeme 4 fragmentos de sangre <gruñe> y te otorgaré la misma protección.', 0),
(@ID, 'esMX', 'Todos los que <gruñe> entran en combate necesitan protección. Sus huesos han de ser resistentes. Su piel, curtida <Gruñe> Mi tribu sabe esto muy bien y para reforzar la protección natural de nuestras púas y piel, <gruñe> con frecuencia recurrimos a Agamaggan para que nos proteja de los daños antes de entrar en combate.$B$BTráeme 4 fragmentos de sangre <gruñe> y te otorgaré la misma protección.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ve a la guerra, $r.', 0),
(@ID, 'esMX', 'Ve a la guerra, $r.', 0);
-- 5047 ¡Finkle Einhorn, a tu servicio!
-- https://es.classic.wowhead.com/quest=5047
SET @ID := 5047;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vivo? ¿El traje bien? ¿Y qué tenemos aquí?', 0),
(@ID, 'esMX', '¿Vivo? ¿El traje bien? ¿Y qué tenemos aquí?', 0);
-- 5048 El buen carácter de Emma
-- https://es.classic.wowhead.com/quest=5048
SET @ID := 5048;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le diría que salga de mi césped, pero como puede ver, no tengo césped.', 0),
(@ID, 'esMX', 'Le diría que salga de mi césped, pero como puede ver, no tengo césped.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, mi nombre es Emma Piedra Mácula, eres la primera persona en años que me llama así. ¿Quién... quién eres tú?$B$B¡¿Dices que sabías... mi hermana ?! ¿Sigue viva? A quién engaño, por supuesto que no. Cuando estalló la plaga en Lordaeron, esperaba lo peor. Muchos miembros de mi familia murieron... o algo peor. Aquí estoy ahora, loca Emma, completamente sola. ¿Qué eres, $gun ladrón:una ladrona; de tumbas o algo así? ¿Estás buscando tu próximo objetivo?$B$B¿Qué... tienes un paquete para mí de mi hermana?', 0),
(@ID, 'esMX', 'De hecho, mi nombre es Emma Piedra Mácula, eres la primera persona en años que me llama así. ¿Quién... quién eres tú?$B$B¡¿Dices que sabías... mi hermana ?! ¿Sigue viva? A quién engaño, por supuesto que no. Cuando estalló la plaga en Lordaeron, esperaba lo peor. Muchos miembros de mi familia murieron... o algo peor. Aquí estoy ahora, loca Emma, completamente sola. ¿Qué eres, $gun ladrón:una ladrona; de tumbas o algo así? ¿Estás buscando tu próximo objetivo?$B$B¿Qué... tienes un paquete para mí de mi hermana?', 0);
-- 5049 La depre de Jeremiah
-- https://es.classic.wowhead.com/quest=5049
SET @ID := 5049;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cada vez que alguien pisa una cucaracha, lloro. Por favor, no me hagas llorar.', 0),
(@ID, 'esMX', 'Cada vez que alguien pisa una cucaracha, lloro. Por favor, no me hagas llorar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace años que no uso ese nombre... pero sí, así me llamaba en mi anterior vida.$B$B¿Y dices que conoces a mi hermana? Bueno, que has hablado con ella hace poco...$B$B¿¡La misma hermana que lleva muerta cuatro años!?$B$BMira, si no tuviera los huesos tan frágiles, te patearía el trasero ahora mismo.$B$B¿Eh... cómo... me traes un paquete de su parte...?', 0),
(@ID, 'esMX', 'Hace años que no uso ese nombre... pero sí, así me llamaba en mi anterior vida.$B$B¿Y dices que conoces a mi hermana? Bueno, que has hablado con ella hace poco...$B$B¿¡La misma hermana que lleva muerta cuatro años!?$B$BMira, si no tuviera los huesos tan frágiles, te patearía el trasero ahora mismo.$B$B¿Eh... cómo... me traes un paquete de su parte...?', 0);
-- 5050 Talismán de buena suerte
-- https://es.classic.wowhead.com/quest=5050
SET @ID := 5050;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'John, querido... ¿eres tú? Tengo mucho frío...', 0),
(@ID, 'esMX', 'John, querido... ¿eres tú? Tengo mucho frío...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Devuelves la mitad del talismán a la aparecida. Lo mira y luego te mira a ti con expectación.$B$B"Cariño, ¿dónde dejaste la otra mitad? No podemos estar juntos si no tenemos las dos mitades. Cariño... ¿puedes verme?"', 0),
(@ID, 'esMX', 'Devuelves la mitad del talismán a la aparecida. Lo mira y luego te mira a ti con expectación.$B$B"Cariño, ¿dónde dejaste la otra mitad? No podemos estar juntos si no tenemos las dos mitades. Cariño... ¿puedes verme?"', 0);
