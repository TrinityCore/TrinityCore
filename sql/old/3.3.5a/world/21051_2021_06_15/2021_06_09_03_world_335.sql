-- 10120 Llegada a Terrallende
-- https://es.wowhead.com/quest=10120
SET @ID := 10120;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te vi hablando con Orion; debe de ser un asunto importante...', 0),
(@ID, 'esMX', 'Te vi hablando con Orion; debe de ser un asunto importante...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres $gel nuevo mensajero:la nueva mensajera; de Orion? Espero que te vaya mejor que al último, $c. Ahora que la Legión campa por la zona no podrías llegar a Thrallmar a pie. Solo tienes que decirlo y mi fiel dracoleón te llevará.', 0),
(@ID, 'esMX', '¿Eres $gel nuevo mensajero:la nueva mensajera; de Orion? Espero que te vaya mejor que al último, $c. Ahora que la Legión campa por la zona no podrías llegar a Thrallmar a pie. Solo tienes que decirlo y mi fiel dracoleón te llevará.', 0);
-- 10121 Erradicar a la Legión Ardiente
-- https://es.wowhead.com/quest=10121
SET @ID := 10121;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que has visto a los guerreros de la Legión durante tu vuelo desde El Portal Oscuro. Esos malditos demonios no dejan de acosarnos, pese a la derrota que les infligimos en la Batalla del Monte Hyjal hace 5 años. ¡Pues si lo que buscan es pelea, por la Horda que la tendrán!$B$BLos orcos tenemos más de una cuenta pendiente con la Legión. ¿Y tú, $n? ¿Quieres que te hable de nuestro enemigo?', 0),
(@ID, 'esMX', 'Supongo que has visto a los guerreros de la Legión durante tu vuelo desde El Portal Oscuro. Esos malditos demonios no dejan de acosarnos, pese a la derrota que les infligimos en la Batalla del Monte Hyjal hace 5 años. ¡Pues si lo que buscan es pelea, por la Horda que la tendrán!$B$BLos orcos tenemos más de una cuenta pendiente con la Legión. ¿Y tú, $n? ¿Quieres que te hable de nuestro enemigo?', 0);
-- 10123 El Barranco Llama Infernal
-- https://es.wowhead.com/quest=10123
SET @ID := 10123;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Thrallmar está a salvo mientras el arcanista y sus magos de sangre permanezcan al frente.', 0),
(@ID, 'esMX', 'Thrallmar está a salvo mientras el arcanista y sus magos de sangre permanezcan al frente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo extraordinario, soldado. Sin duda disminuirá la frecuencia de los ataques, al menos hasta que vuelvan a traer a más Señores del Terror.$B$BEn cuanto a la mala noticia, tengo tus nuevas órdenes...', 0),
(@ID, 'esMX', 'Un trabajo extraordinario, soldado. Sin duda disminuirá la frecuencia de los ataques, al menos hasta que vuelvan a traer a más Señores del Terror.$B$BEn cuanto a la mala noticia, tengo tus nuevas órdenes...', 0);
-- 10124 Base de la vanguardia: Caída del Atracador Vil
-- https://es.wowhead.com/quest=10124
SET @ID := 10124;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que vienes a despejar Llama Infernal? Me alegro de oírlo; necesitamos soldados como tú que vayan de cabeza a por los demonios.', 0),
(@ID, 'esMX', '¿Así que vienes a despejar Llama Infernal? Me alegro de oírlo; necesitamos soldados como tú que vayan de cabeza a por los demonios.', 0);
-- 10125 Misión: Interrumpir las comunicaciones
-- https://es.wowhead.com/quest=10125
SET @ID := 10125;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Antena Legión: Maldad destruida', `ObjectiveText2` = 'Antena Legión: Ira destruida', `ObjectiveText3` = 'Antena Legión: Odio destruida', `ObjectiveText4` = 'Antena Legión: Miedo destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 10129 Misión: Puerta Murketh y Puerta Shaadraz
-- https://es.wowhead.com/quest=10129
SET @ID := 10129;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Puerta Murketh destruida', `ObjectiveText2` = 'Puerta Shaadraz destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si se te escapó la primera vez, aquí tienes otro...', 0),
(@ID, 'esMX', 'Si se te escapó la primera vez, aquí tienes otro...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Con eso retrocederán unas semanas! Un trabajo estupendo, $n. La Legión nunca esperó tan firme resistencia.', 0),
(@ID, 'esMX', '¡Con eso retrocederán unas semanas! Un trabajo estupendo, $n. La Legión nunca esperó tan firme resistencia.', 0);
-- 10132 La amenaza colosal
-- https://es.wowhead.com/quest=10132
SET @ID := 10132;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has eliminado la amenaza colosal?', 0),
(@ID, 'esMX', '¿Has eliminado la amenaza colosal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo.$B$BA mi modo de ver, solo tenemos que matar a suficientes de estos colosos y ya no tendremos que preocuparnos por la cresta ni ese extraño cristal que contiene.$B$BAquí tienes, toma uno como regalo de la Expedición Cenarion.', 0),
(@ID, 'esMX', 'Buen trabajo.$B$BA mi modo de ver, solo tenemos que matar a suficientes de estos colosos y ya no tendremos que preocuparnos por la cresta ni ese extraño cristal que contiene.$B$BAquí tienes, toma uno como regalo de la Expedición Cenarion.', 0);
-- 10134 Pista para el cristal carmesí
-- https://es.wowhead.com/quest=10134
SET @ID := 10134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese cristal que traes es grande, ¡vaya! ¿Lo conseguiste mientras estabas allá en la cresta matando a colosos?$B$BPermíteme que le eche un vistazo.', 0),
(@ID, 'esMX', 'Ese cristal que traes es grande, ¡vaya! ¿Lo conseguiste mientras estabas allá en la cresta matando a colosos?$B$BPermíteme que le eche un vistazo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm. A mí solo me parece un pedazo de cristal en bruto.$B$BDebo admitir que siento que emana de él una asquerosa aura maligna pero no es exactamente mi especialidad. Solo estoy aquí para acabar con la amenaza de los gigantes monteses.', 0),
(@ID, 'esMX', 'Mmm. A mí solo me parece un pedazo de cristal en bruto.$B$BDebo admitir que siento que emana de él una asquerosa aura maligna pero no es exactamente mi especialidad. Solo estoy aquí para acabar con la amenaza de los gigantes monteses.', 0);
-- 10136 Crueles intenciones
-- https://es.wowhead.com/quest=10136
SET @ID := 10136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El destino llama, $n. Arazzius el Cruel ha eludido la justicia durante demasiado tiempo. Que su muerte sea un mensaje para todos aquellos que se opongan a la Horda.', 0),
(@ID, 'esMX', 'El destino llama, $n. Arazzius el Cruel ha eludido la justicia durante demasiado tiempo. Que su muerte sea un mensaje para todos aquellos que se opongan a la Horda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las nuevas generaciones cantarán canciones sobre este día, $n! Canciones alabando tu valor. Ojalá Thrall hubiera estado aquí para celebrar esta victoria con nosotros. La Legión está desarmada y, el Fuego Infernal, pertenece a la Horda de nuevo. Quizás todavía le quede alguna esperanza a este mundo condenado... y quizás todavía nuestro pueblo tenga alguna esperanza de sobrevivir.$B$B¡Lok\'tar ogar!', 0),
(@ID, 'esMX', '¡Las nuevas generaciones cantarán canciones sobre este día, $n! Canciones alabando tu valor. Ojalá Thrall hubiera estado aquí para celebrar esta victoria con nosotros. La Legión está desarmada y, el Fuego Infernal, pertenece a la Horda de nuevo. Quizás todavía le quede alguna esperanza a este mundo condenado... y quizás todavía nuestro pueblo tenga alguna esperanza de sobrevivir.$B$B¡Lok\'tar ogar!', 0);
-- 10137 Provocando al mandón de guerra
-- https://es.wowhead.com/quest=10137
SET @ID := 10137;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Rescata al soldado Imarion', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 10140 Viaje al Bastión del Honor
-- https://es.wowhead.com/quest=10140
SET @ID := 10140;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a la Luz que has conseguido llegar a salvo. El Bastión del Honor necesita de todos los guerreros veteranos que puedan estar disponibles.', 0),
(@ID, 'esMX', 'Gracias a la Luz que has conseguido llegar a salvo. El Bastión del Honor necesita de todos los guerreros veteranos que puedan estar disponibles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestra expedición a este mundo abandonado y en ruinas casi se ha detenido, $n. Hemos encontrado más resistencia de la esperada.$B$BComo si enfrentarse a la Legión Ardiente no fuera lo suficientemente malo – hay horrores en esta tierra como nada que hayamos visto antes.', 0),
(@ID, 'esMX', 'Nuestra expedición a este mundo abandonado y en ruinas casi se ha detenido, $n. Hemos encontrado más resistencia de la esperada.$B$BComo si enfrentarse a la Legión Ardiente no fuera lo suficientemente malo – hay horrores en esta tierra como nada que hayamos visto antes.', 0);
-- 10141 El renacer de la Legión
-- https://es.wowhead.com/quest=10141
SET @ID := 10141;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es posible que el comandante en jefe Danath haya malinterpretado mi solicitud de refuerzos. Pareces ser muy capaz, pero... ¡pedí un batallón!$B$BVerás, tenemos un pequeño problema demoníaco...', 0),
(@ID, 'esMX', 'Es posible que el comandante en jefe Danath haya malinterpretado mi solicitud de refuerzos. Pareces ser muy capaz, pero... ¡pedí un batallón!$B$BVerás, tenemos un pequeño problema demoníaco...', 0);
-- 10142 El Camino del Tormento
-- https://es.wowhead.com/quest=10142
SET @ID := 10142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Bastión del Honor está a salvo mientras los arqueros vigilen nuestros cielos.', 0),
(@ID, 'esMX', 'El Bastión del Honor está a salvo mientras los arqueros vigilen nuestros cielos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excepcional, soldado. Seguro que disminuye la frecuencia de los ataques, al menos hasta que traigan nuevos Señores del Terror.$B$BY ahora, las malas noticias... tengo nuevas órdenes para ti...', 0),
(@ID, 'esMX', 'Un trabajo excepcional, soldado. Seguro que disminuye la frecuencia de los ataques, al menos hasta que traigan nuevos Señores del Terror.$B$BY ahora, las malas noticias... tengo nuevas órdenes para ti...', 0);
-- 10143 Punta de Expedición
-- https://es.wowhead.com/quest=10143
SET @ID := 10143;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de conocerte, soldado.$B$BBasta de chácharas y escucha... tengo una misión vital para ti y quiero que tengas éxito... ¡Y que sobrevivas!', 0),
(@ID, 'esMX', 'Me alegro de conocerte, soldado.$B$BBasta de chácharas y escucha... tengo una misión vital para ti y quiero que tengas éxito... ¡Y que sobrevivas!', 0);
-- 10144 Perturbar sus refuerzos
-- https://es.wowhead.com/quest=10144
SET @ID := 10144;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Desactivar el Portal Grimh', `ObjectiveText2` = 'Desactivar el Portal Kaalez', `ObjectiveText3` = 'Antena de Legión: Olvido Destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ojalá pudiera estar ahí para ver la explosión. ¡Esos explosivos van a montar una buena!', 0),
(@ID, 'esMX', 'Ojalá pudiera estar ahí para ver la explosión. ¡Esos explosivos van a montar una buena!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Desactivar esos portales detendrá el flujo de refuerzos de la Legión durante mucho tiempo.$B$BPero todavía no podemos relajarnos...', 0),
(@ID, 'esMX', 'Bien hecho, $n. Desactivar esos portales detendrá el flujo de refuerzos de la Legión durante mucho tiempo.$B$BPero todavía no podemos relajarnos...', 0);
-- 10146 Misión: La Puerta Murketh y la Puerta Shaadraz
-- https://es.wowhead.com/quest=10146
SET @ID := 10146;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Puerta Murketh destruida', `ObjectiveText2` = 'Puerta Shaadraz destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta misión es vital, $n. Una que no le confiaría a cualquiera.', 0),
(@ID, 'esMX', 'Esta misión es vital, $n. Una que no le confiaría a cualquiera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso les ralentizará, ¡sin duda! Creo que me has puesto extrañamente de buen humor, $n.', 0),
(@ID, 'esMX', 'Eso les ralentizará, ¡sin duda! Creo que me has puesto extrañamente de buen humor, $n.', 0);
-- 10155 Provocando al mandón de guerra
-- https://es.wowhead.com/quest=10155
SET @ID := 10155;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Rescatar a la exploradora Makha', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 10159 Mantener despejada la Colina Colmillespinado
-- https://es.wowhead.com/quest=10159
SET @ID := 10159;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal tu intento de despejar Colina Colmillespinado?', 0),
(@ID, 'esMX', '¿Qué tal tu intento de despejar Colina Colmillespinado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con los devastadores muertos, los viajeros que van y vienen al Refugio Cenarion en la Marisma de Zangar, lo tendrán más fácil.$B$BLa Expedición Cenarion está en deuda contigo.', 0),
(@ID, 'esMX', 'Con los devastadores muertos, los viajeros que van y vienen al Refugio Cenarion en la Marisma de Zangar, lo tendrán más fácil.$B$BLa Expedición Cenarion está en deuda contigo.', 0);
-- 10160 Conoce a tu enemigo
-- https://es.wowhead.com/quest=10160
SET @ID := 10160;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La teniente Amadi asiente.>$B$BBien, necesitamos toda la ayuda posible. El aumento de orcos viles alrededor de la Muralla Sur me preocupa. Envié a un explorador a investigar, pero todavía no ha regresado.', 0),
(@ID, 'esMX', '<La teniente Amadi asiente.>$B$BBien, necesitamos toda la ayuda posible. El aumento de orcos viles alrededor de la Muralla Sur me preocupa. Envié a un explorador a investigar, pero todavía no ha regresado.', 0);
-- 10161 En caso de emergencia...
-- https://es.wowhead.com/quest=10161
SET @ID := 10161;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado las suficientes piezas? Si no es así, voy a tener que usar esa sartén que Legassi no hace más que agitar. Después tendré que cambiarle el nombre al zepelín por el de "Sartén Voladora."', 0),
(@ID, 'esMX', '¿Has encontrado las suficientes piezas? Si no es así, voy a tener que usar esa sartén que Legassi no hace más que agitar. Después tendré que cambiarle el nombre al zepelín por el de "Sartén Voladora."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algunas están en muy malas condiciones, pero debería poder trabajar con lo que tengo. Con algo de ingeniería creativa, ¡seguro que puedo hacerlo funcionar!', 0),
(@ID, 'esMX', 'Algunas están en muy malas condiciones, pero debería poder trabajar con lo que tengo. Con algo de ingeniería creativa, ¡seguro que puedo hacerlo funcionar!', 0);
-- 10162 Misión: La Plataforma Abisal
-- https://es.wowhead.com/quest=10162
SET @ID := 10162;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Cañón vil destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Demuéstrales que ni siquiera los cielos son seguros!', 0),
(@ID, 'esMX', '¡Demuéstrales que ni siquiera los cielos son seguros!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vuelas como si lo hubieras hecho toda la vida, $n. ¡Ha sido impresionante! ¡Ni un rasguño en los destructores dracoleón!', 0),
(@ID, 'esMX', 'Vuelas como si lo hubieras hecho toda la vida, $n. ¡Ha sido impresionante! ¡Ni un rasguño en los destructores dracoleón!', 0);
-- 10163 Misión: La Plataforma Abisal
-- https://es.wowhead.com/quest=10163
SET @ID := 10163;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Cañón vil destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Demuéstrales que ni siquiera los cielos son seguros!', 0),
(@ID, 'esMX', '¡Demuéstrales que ni siquiera los cielos son seguros!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vuelas como si llevaras toda la vida haciéndolo, $n. ¡Extraordinaria demostración! ¡Ni un rasguño en los destructores grifos!', 0),
(@ID, 'esMX', 'Vuelas como si llevaras toda la vida haciéndolo, $n. ¡Extraordinaria demostración! ¡Ni un rasguño en los destructores grifos!', 0);
-- 10164 Todo irá bien
-- https://es.wowhead.com/quest=10164
SET @ID := 10164;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Salva los espíritus, $n.', 0),
(@ID, 'esMX', 'Salva los espíritus, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido, $n! ¡Los espíritus son libres!$B$BAunque no tengo una manifestación material, todavía puedo recompensarte con artículos del mundo espiritual. Úsalos con precaución, ya que estos elementos a menudo son volátiles y pueden causar un gran daño a los que los usan.', 0),
(@ID, 'esMX', '¡Lo has conseguido, $n! ¡Los espíritus son libres!$B$BAunque no tengo una manifestación material, todavía puedo recompensarte con artículos del mundo espiritual. Úsalos con precaución, ya que estos elementos a menudo son volátiles y pueden causar un gran daño a los que los usan.', 0);
-- 10165 Eliminar a la competencia
-- https://es.wowhead.com/quest=10165
SET @ID := 10165;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me gusta "compartir".', 0),
(@ID, 'esMX', 'No me gusta "compartir".', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro competidor que se hunde... Haces un buen trabajo, como una bestia de carga, $r. Si alguna vez estás en Tormenta Abisal, búscame. Tengo mi hogar en La Flecha de la Tormenta.', 0),
(@ID, 'esMX', 'Otro competidor que se hunde... Haces un buen trabajo, como una bestia de carga, $r. Si alguna vez estás en Tormenta Abisal, búscame. Tengo mi hogar en La Flecha de la Tormenta.', 0);
-- 10166 La memoria de Cortezablanca
-- https://es.wowhead.com/quest=10166
SET @ID := 10166;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado, $n. ¿No has hecho ya bastante?', 0),
(@ID, 'esMX', 'Has regresado, $n. ¿No has hecho ya bastante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya no pertenezco a este mundo y tengo que admitir la derrota. La tierra ha cambiado para siempre; nada volverá a ser lo que fue.$B$BDéjame el colgante, $n. Puede que un día, mucho después de que los elfos se hayan ido, crezca un árbol aquí, en este bosque calcinado lleno de carcasas de antárboles muertos.', 0),
(@ID, 'esMX', 'Ya no pertenezco a este mundo y tengo que admitir la derrota. La tierra ha cambiado para siempre; nada volverá a ser lo que fue.$B$BDéjame el colgante, $n. Puede que un día, mucho después de que los elfos se hayan ido, crezca un árbol aquí, en este bosque calcinado lleno de carcasas de antárboles muertos.', 0);
-- 10167 Auchindoun...
-- https://es.wowhead.com/quest=10167
SET @ID := 10167;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El espíritu de D\'ore zumba.>$B$BSaludos, $n.', 0),
(@ID, 'esMX', '<El espíritu de D\'ore zumba.>$B$BSaludos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El recuerdo está fresco en mi memoria, $n. Perdí toda mi energía en el accidente. No era más que una chispa de energía del vacío cuando el profeta Velen y sus compatriotas draenei trajeron mis restos aquí. Después de mucha ceremonia, pusieron mis restos a descansar en este sarcófago. Hace cerca de mil años que me regenero. Ya casi se ha completado el ciclo...', 0),
(@ID, 'esMX', 'El recuerdo está fresco en mi memoria, $n. Perdí toda mi energía en el accidente. No era más que una chispa de energía del vacío cuando el profeta Velen y sus compatriotas draenei trajeron mis restos aquí. Después de mucha ceremonia, pusieron mis restos a descansar en este sarcófago. Hace cerca de mil años que me regenero. Ya casi se ha completado el ciclo...', 0);
-- 10168 Reflejos del alma
-- https://es.wowhead.com/quest=10168
SET @ID := 10168;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Madre Kashur está muy disgustada.>$B$BEstos naaru son más sabios que toda la vida de este mundo.', 0),
(@ID, 'esMX', '<Madre Kashur está muy disgustada.>$B$BEstos naaru son más sabios que toda la vida de este mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has completado un viaje largo y peligroso en el que has arriesgado tu vida para proporcionar seguridad a los Mag\'har y serenidad a nuestros antepasados. No tengo palabras para expresar mi agradecimiento.', 0),
(@ID, 'esMX', 'Has completado un viaje largo y peligroso en el que has arriesgado tu vida para proporcionar seguridad a los Mag\'har y serenidad a nuestros antepasados. No tengo palabras para expresar mi agradecimiento.', 0);
-- 10169 Saber perder
-- https://es.wowhead.com/quest=10169
SET @ID := 10169;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El olor a hierbas y especias llena el aire alrededor de la olla.', 0),
(@ID, 'esMX', 'El olor a hierbas y especias llena el aire alrededor de la olla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los tiradores de Aldor parecen distraídos, lo que te da tiempo suficiente para colocar el contenido del vial en el guiso.', 0),
(@ID, 'esMX', 'Los tiradores de Aldor parecen distraídos, lo que te da tiempo suficiente para colocar el contenido del vial en el guiso.', 0);
-- 10170 Regresa junto a la Abuela
-- https://es.wowhead.com/quest=10170
SET @ID := 10170;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero que lleves personalmente las noticias a Garrosh.', 0),
(@ID, 'esMX', 'Quiero que lleves personalmente las noticias a Garrosh.', 0);
-- 10171 El inconsolable jefe
-- https://es.wowhead.com/quest=10171
SET @ID := 10171;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo el mundo está orgulloso. Orgulloso porque nuestro pueblo conseguirá ver otro invierno. Pero, ¿qué pasará después?$B$BQuizás tú deberías liderar el clan, $n. Quizás entonces podré morir en paz cuando fallezca la Abuela. Quizás podré borrar finalmente la vergüenza que pesa sobre mi nombre. Anhelo tanto esa paz...', 0),
(@ID, 'esMX', 'Todo el mundo está orgulloso. Orgulloso porque nuestro pueblo conseguirá ver otro invierno. Pero, ¿qué pasará después?$B$BQuizás tú deberías liderar el clan, $n. Quizás entonces podré morir en paz cuando fallezca la Abuela. Quizás podré borrar finalmente la vergüenza que pesa sobre mi nombre. Anhelo tanto esa paz...', 0);
-- 10172 No hay esperanza
-- https://es.wowhead.com/quest=10172
SET @ID := 10172;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La abuela Geyah está acostada.>', 0),
(@ID, 'esMX', '<La abuela Geyah está acostada.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La cara de la Abuela Geyah está cubierta de lágrimas.>$B$BThrall vendrá. Sé que pronto estará aquí.', 0),
(@ID, 'esMX', '<La cara de la Abuela Geyah está cubierta de lágrimas.>$B$BThrall vendrá. Sé que pronto estará aquí.', 0);
-- 10173 El bastón del archimago
-- https://es.wowhead.com/quest=10173
SET @ID := 10173;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No descansaré hasta que el archimago Vargoth recupere su bastón. ¿Pudiste robárselo al demonio?', 0),
(@ID, 'esMX', 'No descansaré hasta que el archimago Vargoth recupere su bastón. ¿Pudiste robárselo al demonio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que has conseguido recuperar el bastón. Impresionante, $n. Quizás seas la persona que buscaba.$B$BAh, sí, tu recompensa...$B$B<Ravandwyr pone unas monedas en tu palma.>$B$BSin duda esperabas más pero eso también llegará en su momento. Por ahora, considera que la oportunidad es la verdadera recompensa.', 0),
(@ID, 'esMX', 'Ah, así que has conseguido recuperar el bastón. Impresionante, $n. Quizás seas la persona que buscaba.$B$BAh, sí, tu recompensa...$B$B<Ravandwyr pone unas monedas en tu palma.>$B$BSin duda esperabas más pero eso también llegará en su momento. Por ahora, considera que la oportunidad es la verdadera recompensa.', 0);
-- 10174 La maldición de la Torre Violeta
-- https://es.wowhead.com/quest=10174
SET @ID := 10174;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La imagen del archimago Vargoth te observa mientras le das el mensaje de Ravandwyr.>$B$BRavandwyr tiene todo lo que un maestro puede esperar de su aprendiz. Cuando le di el bastón y le dije que escapase, supuse que lo utilizaría para encontrar ayuda y liberarme cuando las fuerzas de Kael\'thas se hubieran ido de la torre. Desde entonces, he aprendido mucho sobre la naturaleza de la maldición.$B$BEs posible romperla, $n, pero necesitaría tu ayuda.', 0),
(@ID, 'esMX', '<La imagen del archimago Vargoth te observa mientras le das el mensaje de Ravandwyr.>$B$BRavandwyr tiene todo lo que un maestro puede esperar de su aprendiz. Cuando le di el bastón y le dije que escapase, supuse que lo utilizaría para encontrar ayuda y liberarme cuando las fuerzas de Kael\'thas se hubieran ido de la torre. Desde entonces, he aprendido mucho sobre la naturaleza de la maldición.$B$BEs posible romperla, $n, pero necesitaría tu ayuda.', 0);
-- 10175 Thrall, hijo de Durotan
-- https://es.wowhead.com/quest=10175
SET @ID := 10175;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La voz de Thrall adquiere la esencia hueca de una nube de tormenta.> Yo... ¿tengo una abuela? ¿Ella vive?', 0),
(@ID, 'esMX', '<La voz de Thrall adquiere la esencia hueca de una nube de tormenta.> Yo... ¿tengo una abuela? ¿Ella vive?', 0);
-- 10176 Ar'kelos el Guardián
-- https://es.wowhead.com/quest=10176
SET @ID := 10176;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin nos encontramos.', 0),
(@ID, 'esMX', 'Por fin nos encontramos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Destruir el campo hará que me resulte mucho más fácil preparar la magia que, por fin, acabará con la maldición de la torre.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Destruir el campo hará que me resulte mucho más fácil preparar la magia que, por fin, acabará con la maldición de la torre.', 0);
-- 10177 Problemas en Auchindoun
-- https://es.wowhead.com/quest=10177
SET @ID := 10177;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya es hora de que llegues.$B$BMehlisah dijo que enviaría ayuda hace días. ¡Y hemos estado luchando aquí más tiempo que eso!', 0),
(@ID, 'esMX', 'Ya es hora de que llegues.$B$BMehlisah dijo que enviaría ayuda hace días. ¡Y hemos estado luchando aquí más tiempo que eso!', 0);
-- 10178 Encontrar al espía To'gun
-- https://es.wowhead.com/quest=10178
SET @ID := 10178;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Grik\'tha te envió aquí a por mí?$B$B¡No sé si tocarla o llamarla tonta!$B$B¿Crees que podrías ayudarme a salir de esta jaula? Es un poco estrecha.', 0),
(@ID, 'esMX', '¿Qué? ¿Grik\'tha te envió aquí a por mí?$B$B¡No sé si tocarla o llamarla tonta!$B$B¿Crees que podrías ayudarme a salir de esta jaula? Es un poco estrecha.', 0);
-- 10180 No puedo estar lejos
-- https://es.wowhead.com/quest=10180
SET @ID := 10180;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debería haber sospechado que te enviaría a buscarme. Intentó convencerme para que no volviera a las Salas Sethekk, pero no soy capaz de seguir viviendo permitiendo que Lakka muera aquí dentro.', 0),
(@ID, 'esMX', 'Debería haber sospechado que te enviaría a buscarme. Intentó convencerme para que no volviera a las Salas Sethekk, pero no soy capaz de seguir viviendo permitiendo que Lakka muera aquí dentro.', 0);
-- 10182 Mago de batalla Dathric
-- https://es.wowhead.com/quest=10182
SET @ID := 10182;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Dar descanso al espíritu de Dathric', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Ya no percibo agitación en el espíritu de Dathric. Me encantaría poder volver a hablar con él, pero al menos sé que ahora descansa en paz.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Ya no percibo agitación en el espíritu de Dathric. Me encantaría poder volver a hablar con él, pero al menos sé que ahora descansa en paz.', 0);
