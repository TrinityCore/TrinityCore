-- 1265 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1265
SET @ID := 1265;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El hombre al que buscas, Hendel, no está aquí. Ha llegado información a través de otras fuentes a Lady Valiente, que creo que ya sabes. Me ha pedido que te busque y te ayude en tu misión. Si me lo permites, te diré dónde encontrar al soldado Hendel para que puedas llevarle ante la justicia.', 0),
(@ID, 'esMX', 'El hombre al que buscas, Hendel, no está aquí. Ha llegado información a través de otras fuentes a Lady Valiente, que creo que ya sabes. Me ha pedido que te busque y te ayude en tu misión. Si me lo permites, te diré dónde encontrar al soldado Hendel para que puedas llevarle ante la justicia.', 0);
-- 7070 Trozos Oscuros
-- https://es.classic.wowhead.com/quest=7070
SET @ID := 7070;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya hiciste el viaje? Sé que sería bastante peligroso, pero si tuvieras éxito, valdría mucho la pena.', 0),
(@ID, 'esMX', '¿Ya hiciste el viaje? Sé que sería bastante peligroso, pero si tuvieras éxito, valdría mucho la pena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son perfectos, $n. De hecho, otros aventureros también regresaron de allí y de ellos pude diseñar estos... por favor, siéntetee libre de tomar uno por su arduo trabajo. Y gracias nuevamente por traer más muestras para estudiar.', 0),
(@ID, 'esMX', 'Estos son perfectos, $n. De hecho, otros aventureros también regresaron de allí y de ellos pude diseñar estos... por favor, siéntetee libre de tomar uno por su arduo trabajo. Y gracias nuevamente por traer más muestras para estudiar.', 0);
-- 11134 El fin de los desertores
-- https://es.wowhead.com/quest=11134
SET @ID := 11134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu asalto a la base de los desertores?', 0),
(@ID, 'esMX', '¿Has completado tu asalto a la base de los desertores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las peticiones de Gavis no es tan extravagantes como podría parecer. Con el manejo adecuado, Lady Jaina puede devolver a los desertores al redil, pero esa es su decisión, por supuesto.$B$BHa sido un placer trabajar contigo, $n. Sin tu ayuda, dudo que la operación hubiera salido tan bien. Cuando haga mi informe en Ventormenta, te nombrará como $gel:la; $c que puso fin a la amenaza del desertor.', 0),
(@ID, 'esMX', 'Las peticiones de Gavis no es tan extravagantes como podría parecer. Con el manejo adecuado, Lady Jaina puede devolver a los desertores al redil, pero esa es su decisión, por supuesto.$B$BHa sido un placer trabajar contigo, $n. Sin tu ayuda, dudo que la operación hubiera salido tan bien. Cuando haga mi informe en Ventormenta, te nombrará como $gel:la; $c que puso fin a la amenaza del desertor.', 0);
-- 11192 Aceite de trillador
-- https://es.wowhead.com/quest=11192
SET @ID := 11192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste conseguir algo de ese aceite de trillador?', 0),
(@ID, 'esMX', '¿Pudiste conseguir algo de ese aceite de trillador?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, tengo mis dudas, pero esta es la única solución disponible en este momento. Una vez que lo tengamos en funcionamiento, estoy seguro de que habrá tiempo para buscar otras formas de alimentar la lámpara.', 0),
(@ID, 'esMX', 'Bueno, tengo mis dudas, pero esta es la única solución disponible en este momento. Una vez que lo tengamos en funcionamiento, estoy seguro de que habrá tiempo para buscar otras formas de alimentar la lámpara.', 0);
-- 11193 Ruines Moradores de las Profundidades
-- https://es.wowhead.com/quest=11193
SET @ID := 11193;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué será hoy? El róbalo es bastante bueno.', 0),
(@ID, 'esMX', '¿Qué será hoy? El róbalo es bastante bueno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, eso fue muy amable por parte de Babs al enviar el libro. No sé si lo habrá hojeado o no, pero hay mucha verdad en los cuentos de ese libro. Los marineros no se lo inventan todo, ya sabes.', 0),
(@ID, 'esMX', 'Bueno, eso fue muy amable por parte de Babs al enviar el libro. No sé si lo habrá hojeado o no, pero hay mucha verdad en los cuentos de ese libro. Los marineros no se lo inventan todo, ya sabes.', 0);
-- 11194 ¿Es real?
-- https://es.wowhead.com/quest=11194
SET @ID := 11194;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿quieres saber más sobre los monstruos marinos? Hmm... bueno, te propongo un trato, pero implicará mucho alcohol y algo de vergüenza por tu parte.', 0),
(@ID, 'esMX', 'Entonces, ¿quieres saber más sobre los monstruos marinos? Hmm... bueno, te propongo un trato, pero implicará mucho alcohol y algo de vergüenza por tu parte.', 0);
-- 11136 Un progreso preocupante
-- https://es.wowhead.com/quest=11136
SET @ID := 11136;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán no hace ningún esfuerzo por ocultar que está evaluando tus habilidades.>$B$B¿Has oído hablar del reciente naufragio frente a la costa? Me vendría bien un poco de ayuda para confirmar mis sospechas sobre los supervivientes. ', 0),
(@ID, 'esMX', '<El capitán no hace ningún esfuerzo por ocultar que está evaluando tus habilidades.>$B$B¿Has oído hablar del reciente naufragio frente a la costa? Me vendría bien un poco de ayuda para confirmar mis sospechas sobre los supervivientes. ', 0);
-- 11137 ¿Defias en Revolcafango?
-- https://es.wowhead.com/quest=11137
SET @ID := 11137;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste localizar a su líder?', 0),
(@ID, 'esMX', '¿Pudiste localizar a su líder?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán Wymor acepta las órdenes y las lee.>$B$B¿A qué diablos se podría referir "carga preciosa"? Los Defia han hecho pequeño contrabando en tierras de Ventormenta, pero esto parece fuera de su alcance. El lenguaje de estas órdenes sugiere un mecenas rico o noble.', 0),
(@ID, 'esMX', '<El capitán Wymor acepta las órdenes y las lee.>$B$B¿A qué diablos se podría referir "carga preciosa"? Los Defia han hecho pequeño contrabando en tierras de Ventormenta, pero esto parece fuera de su alcance. El lenguaje de estas órdenes sugiere un mecenas rico o noble.', 0);
-- 11138 Renn McBranquia
-- https://es.wowhead.com/quest=11138
SET @ID := 11138;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Qué te trae por aquí?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Qué te trae por aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renn revisa las órdenes.>$B$B¡Así que había una valiosa carga a bordo! Tenemos que localizarlo antes de que los Defias lo recuperen. Estos tipos no son buzos, pero vamos a necesitar algo de su equipo si me ayudas a encontrar la carga.', 0),
(@ID, 'esMX', '<Renn revisa las órdenes.>$B$B¡Así que había una valiosa carga a bordo! Tenemos que localizarlo antes de que los Defias lo recuperen. Estos tipos no son buzos, pero vamos a necesitar algo de su equipo si me ayudas a encontrar la carga.', 0);
-- 11209 El trato de Nat
-- https://es.wowhead.com/quest=11209
SET @ID := 11209;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerde el trato,... "no regreses hasta que algo te muerda".', 0),
(@ID, 'esMX', 'Recuerde el trato,... "no regreses hasta que algo te muerda".', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está nada mal, pero sabes, si fuera tú, creo que me daría un baño lo antes posible.$B$BAhora, sobre tu monstruo marino...$B$BMientras tanto, sírvete algo.', 0),
(@ID, 'esMX', 'No está nada mal, pero sabes, si fuera tú, creo que me daría un baño lo antes posible.$B$BAhora, sobre tu monstruo marino...$B$BMientras tanto, sírvete algo.', 0);
-- 11177 El ermitaño de la Mansión Cienaluz
-- https://es.wowhead.com/quest=11177
SET @ID := 11177;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sal de mi césped ... a menos que, es decir, quieras ayudar al viejo "Ojolodo" un poco en la cocina. ¿Qué dices?', 0),
(@ID, 'esMX', 'Sal de mi césped ... a menos que, es decir, quieras ayudar al viejo "Ojolodo" un poco en la cocina. ¿Qué dices?', 0);
-- 11210 Oh, es real
-- https://es.wowhead.com/quest=11210
SET @ID := 11210;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Cuentas tus experiencias con Nat Pagle, omitiendo cuidadosamente la parte sobre la \'prueba del cebo\'>$B$BBueno, parece que tenemos mucho trabajo por delante. Haré los preparativos.', 0),
(@ID, 'esMX', '<Cuentas tus experiencias con Nat Pagle, omitiendo cuidadosamente la parte sobre la \'prueba del cebo\'>$B$BBueno, parece que tenemos mucho trabajo por delante. Haré los preparativos.', 0);
-- 11198 ¡Elimina a Tethyr!
-- https://es.wowhead.com/quest=11198
SET @ID := 11198;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz tu informe.', 0),
(@ID, 'esMX', 'Haz tu informe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Lo admito, cuando vi por primera vez a esa bestia, tenía dudas sobre nuestra capacidad para defender los muelles, ¡pero mantuviste unidos a los defensores de manera brillante!', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Lo admito, cuando vi por primera vez a esa bestia, tenía dudas sobre nuestra capacidad para defender los muelles, ¡pero mantuviste unidos a los defensores de manera brillante!', 0);
-- 1266 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1266
SET @ID := 1266;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gciudadano:ciudadana;. Este es un lugar peligroso para las visitas. Yo no me quedaría mucho por aquí si valoras tu vida.$B$BSi tus preguntas son cortas, intentaré ayudarte. Mantén los ojos abiertos y ten cuidado con esos sucios ogros. Según los rumores, hay una base de la Horda cerca del pantano. Los infiltrados hacen todo lo que pueden para encontrarla, pero el proceso va lento y no hemos conseguido avanzar mucho.', 0),
(@ID, 'esMX', 'Hola, $gciudadano:ciudadana;. Este es un lugar peligroso para las visitas. Yo no me quedaría mucho por aquí si valoras tu vida.$B$BSi tus preguntas son cortas, intentaré ayudarte. Mantén los ojos abiertos y ten cuidado con esos sucios ogros. Según los rumores, hay una base de la Horda cerca del pantano. Los infiltrados hacen todo lo que pueden para encontrarla, pero el proceso va lento y no hemos conseguido avanzar mucho.', 0);
-- 1218 Ancas de rana de marisma
-- https://es.classic.wowhead.com/quest=1218
SET @ID := 1218;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Especias. A todos nos vendrían bien. Dan sabor a la vida. ¿No te parece?', 0),
(@ID, 'esMX', 'Especias. A todos nos vendrían bien. Dan sabor a la vida. ¿No te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto sí que son especias! Aquí tienes un poco de buen guiso del pantano.', 0),
(@ID, 'esMX', '¡Esto sí que son especias! Aquí tienes un poco de buen guiso del pantano.', 0);
-- 11180 ¿Quién atormenta la Colina de las Brujas?
-- https://es.wowhead.com/quest=11180
SET @ID := 11180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has aprendido de los espíritus que acechan este lugar?', 0),
(@ID, 'esMX', '¿Qué has aprendido de los espíritus que acechan este lugar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mordant saca una pequeña hoja de papel y un lápiz, y comienza a escribir notas sobre tus hallazgos.>$B$BSegún tus hallazgos, los espíritus en este lugar deben ser todos los que alguna vez vivieron en esta tierra, no solo los ocupantes anteriores.$B$BAlgo los ha estado corrompiendo y matando. Los que siguen no aprenden la verdad hasta que es demasiado tarde. ¡Tenemos que acabar con esto, $n!', 0),
(@ID, 'esMX', '<Mordant saca una pequeña hoja de papel y un lápiz, y comienza a escribir notas sobre tus hallazgos.>$B$BSegún tus hallazgos, los espíritus en este lugar deben ser todos los que alguna vez vivieron en esta tierra, no solo los ocupantes anteriores.$B$BAlgo los ha estado corrompiendo y matando. Los que siguen no aprenden la verdad hasta que es demasiado tarde. ¡Tenemos que acabar con esto, $n!', 0);
-- 1219 El informe orco
-- https://es.classic.wowhead.com/quest=1219
SET @ID := 1219;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que informar?', 0),
(@ID, 'esMX', '¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... No entiendo muy bien el lenguaje orco pero, esto parece una especie de informe... ¡escrito por un espía orco!', 0),
(@ID, 'esMX', 'Mm... No entiendo muy bien el lenguaje orco pero, esto parece una especie de informe... ¡escrito por un espía orco!', 0);
-- 1206 Jarl necesita ojos
-- https://es.classic.wowhead.com/quest=1206
SET @ID := 1206;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde están esos ojos?', 0),
(@ID, 'esMX', '¿Dónde están esos ojos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes los ojos! ¡Tienes los ojos! ¡Ricos, ricos ojos de araña!$B$BAlgunos ojos... parece que te miran cuando los miras. Esos son los últimos que hay que comerse. Así te hacen compañía... en el pantano la compañía escasea.$B$BHola, ojitos de araña. ¡Hola! Sabéis a pollo. ¡Rico pollito asado!$B$BMmm.', 0),
(@ID, 'esMX', '¡Tienes los ojos! ¡Tienes los ojos! ¡Ricos, ricos ojos de araña!$B$BAlgunos ojos... parece que te miran cuando los miras. Esos son los últimos que hay que comerse. Así te hacen compañía... en el pantano la compañía escasea.$B$BHola, ojitos de araña. ¡Hola! Sabéis a pollo. ¡Rico pollito asado!$B$BMmm.', 0);
-- 1203 Jarl necesita una hoja
-- https://es.classic.wowhead.com/quest=1203
SET @ID := 1203;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi espada?', 0),
(@ID, 'esMX', '¿Tienes mi espada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa es una buena espada. Tiene buen equilibrio. Es una buena hoja equilibrada. Gracias. ¡¡¡Gracias, gracias, gracias!!! Ahora quiero probarlo ...$B$BLuego. Lo intentaré más tarde. Pero como estaba diciendo ... gracias.', 0),
(@ID, 'esMX', 'Esa es una buena espada. Tiene buen equilibrio. Es una buena hoja equilibrada. Gracias. ¡¡¡Gracias, gracias, gracias!!! Ahora quiero probarlo ...$B$BLuego. Lo intentaré más tarde. Pero como estaba diciendo ... gracias.', 0);
-- 11181 La ruina de las brujas
-- https://es.wowhead.com/quest=11181
SET @ID := 11181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recolectar algo de la hierba? Debemos trabajar rápidamente, antes de que cualquier mal que esté detrás de esta plaga consolide su control en el área.', 0),
(@ID, 'esMX', '¿Pudiste recolectar algo de la hierba? Debemos trabajar rápidamente, antes de que cualquier mal que esté detrás de esta plaga consolide su control en el área.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mordant acepta tu manojo de hierbas.>$B$B¡Estos coinciden exactamente con la descripción! Preparé la antorcha mientras estabas fuera. Todo lo que queda es sujetar las hierbas en el final.', 0),
(@ID, 'esMX', '<Mordant acepta tu manojo de hierbas.>$B$B¡Estos coinciden exactamente con la descripción! Preparé la antorcha mientras estabas fuera. Todo lo que queda es sujetar las hierbas en el final.', 0);
-- 11183 Limpiar la Colina de las Brujas
-- https://es.wowhead.com/quest=11183
SET @ID := 11183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se terminó?', 0),
(@ID, 'esMX', '¿Se terminó?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Funcionó?$B$B<Mordant se aclara la garganta.>$B$BQuiero decir ... ¡funcionó! Jarl y yo estamos en deuda contigo, $n. Ahora el único problema que queda es el gusto de mi amigo por los muebles, y me temo que no se resolverá tan fácilmente.', 0),
(@ID, 'esMX', '¿Funcionó?$B$B<Mordant se aclara la garganta.>$B$BQuiero decir ... ¡funcionó! Jarl y yo estamos en deuda contigo, $n. Ahora el único problema que queda es el gusto de mi amigo por los muebles, y me temo que no se resolverá tan fácilmente.', 0);
